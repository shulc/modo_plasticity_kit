/*
 * Plug-in SDK Source: Common Utility
 *
 * Copyright (c) 2008-2022 The Foundry Group LLC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.   Except as contained
 * in this notice, the name(s) of the above copyright holders shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Scene building.
 */
#include <lxu_scene.hpp>
#include <lx_layer.hpp>
#include <lx_locator.hpp>
#include <lx_action.hpp>
#include <lx_select.hpp>
#include <lx_seltypes.hpp>
#include <lx_shade.hpp>
#include <lx_value.hpp>
#include <lxfile.h>
#include <math.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <exception>

#pragma warning(disable: 4786)

/*
 * Suppress warnings for deprecated functions.
 */
#ifdef _MSC_VER
        #define _CRT_SECURE_NO_WARNINGS 1
        #define _CRT_SECURE_NO_DEPRECATE 1
        #pragma warning(disable: 4996)
#endif

/*
 * Setting the map with a null name uses a visitor to find the first map
 * of a given type. By returning an error the visitor halts the enumeration.
 */
class CFirstMapVisitor : public CLxImpl_AbstractVisitor {
        LxResult		 Evaluate ()
        {
                return LXe_FAILED;
        }
};

/*
 * ---------------------------------------------------------------------------
 * Path name utilities.
 *
 * [TODO] All of these functions should eventually be provided as host-side services.
 */

#define IS_SLASH(c)	((c) == '\\' || (c) == '/')

/*
 * The system-generic filename utilities operate on neutral-format paths.
 * Local forms are converted to neutral forms, manipulated and converted
 * back.  The major test on paths of this type determines if a character
 * is a directory separator.
 */
#define IS_DIRSEP(c)	 ((c) == '/' || (c) == ':')

/*
 * Return true if the given file name is absolute.
 */
        static bool
FileIsAbsolute (const char *fileName)
{
#if defined(_WIN32) || defined(_WIN64)
        /*
         * Windows (x86 and x64):
         *
         * Test for absolute local file name.  Look for the "X:\ " prefix pattern
         * or the "\\ " form for a network path.
         */
        return (fileName[0] && fileName[1] == ':' && IS_SLASH (fileName[2])) ||
               (fileName[2] && IS_SLASH (fileName[0]) && IS_SLASH (fileName[1]));
#else
        /*
         * Everyone else:
         *
         * Test for absolute local filename.
         * This is simply a matter of looking for "/" at the beginning of the path.
         */
        return (fileName[0] && fileName[0] == '/');
#endif
}

/*
 * "const" version of Latin_Search.
 */
        static const char *
Latin_Search (
        const char		*string,
        int			 code,
        bool			 reverse)
{
        if (reverse) {
                return strrchr (string, code);
        }
        else {
                return strchr (string, code);
        }
}

        static const char *
Latin_PullChar (
        const char		*string,
        int			*code,
        int			*len)
{
        *code = ((const unsigned char *) string) [0];
        if (len) {
                *len = 1;
        }

        return (*code ? string + 1 : NULL);
}

/*
 * ---------------------------------------------------------------------------
 * Local <-> Neutral file format conversion.
 *
 * Local file and path names can be converted to and from neutral format with
 * NFileFromLocal and NFileToLocal.  The value returned is the result of the
 * conversion. These conversions are raw, performing a simple conversion
 * without validity checks.  Aliases are not used.
 */
        static void
NFileFromLocal (
        std::string		&neutral,
        const std::string	&local)
{
#if defined(_WIN32) || defined(_WIN64)
        /*
         * Windows (x86 and x64):
         *
         * To convert from local to neutral, extract the drive letter or network
         * name, if any, as the "volume" name and then just copy the remaining path 
         * changing backslash into front slash.
         */
        const char		*p = local.c_str ();
        int			 code, len;
        size_t			 ind = 0, lSize = local.size();

        neutral.clear ();

        if (local[0] && local[1] == ':' && IS_SLASH (local[2])) {
                neutral.append (local, ind, 2);
                ind += 3;

        } else if (IS_SLASH (local[0]) && IS_SLASH (local[1])) {
                code = 0;
                for (ind = 2; ind < lSize && p; ind++) {
                        p = Latin_PullChar (&local[ind], &code, &len);
                        if (IS_SLASH (code))
                                break;

                        neutral.append (local, ind, len);
                }

                neutral.append(":");
                if (IS_SLASH (code))
                        ind++;
        }

        for (; ind < lSize && p; ind++) {
                p = Latin_PullChar (&local[ind], &code, &len);
                if (IS_SLASH (code))
                        neutral.append("/");
                else {
                        neutral.append (local, ind, len);
                }
        }
        return;
#else
        /*
         * Everyone else:
         *
         * We treat posix paths as if the first entry after the root 
         * slash is the volume name and go from there.  Shouldn't matter too much since the 
         * user should rarely, if ever, see these.
         */
        const char		*p;
        int			 volSet = 0, code, len;
        size_t			 ind = 0;

        neutral.clear ();

        if (!FileIsAbsolute (local.c_str()))
                neutral.append(local);
        else {
                p = Latin_PullChar (&local[ind], &code, &len);
                while (p) {
                        ind++;
                        p = Latin_PullChar (&local[ind], &code, &len);
                        if (code == '/' && !volSet) {
                                volSet = 1;
                                neutral.append(":");
                        }
                        else {
                                neutral.append(local, ind, len);
                        }
                }
        }
        return;
#endif
}

        static void
NFileToLocal (
        std::string			&local,
        const std::string		&neutral)
{
#if defined(_WIN32) || defined(_WIN64)
        /*
         * Windows (x86 and x64):
         *
         * Conversion to the local format requires checking for an alias that
         * matches the absolute part of the name (if any).  If there is no alias,
         * then we treat the absolute location as a drive letter if it's one
         * character, and as a network path if it's longer.  The remainder of
         * the path is just copied, with the slashes reversed.
         */
        const char		*p;
        size_t			 ind = 0, nSize = neutral.size ();
        int			 code, len;

        local.clear ();

        p = Latin_Search (neutral.c_str(), ':', 0);
        if (p) {
                ind = p - neutral.c_str ();

                /*
                 * Look for alias
                 */
                if (ind == 1) {
                        local.append (neutral, 0, ind);
                        local.append(":");
                } else {
                        local.append ("\\");
                        local.append ("\\");
                        local.append (neutral, 2, ind);
                }

                ind++;
                if (!IS_SLASH (neutral[ind]))
                        local.append ("\\");
        }

        for (; ind < nSize; ind++)
        {
                Latin_PullChar (&neutral[ind], &code, &len);
                if (code == '/') {
                        local.append ("\\");
                }
                else {
                        local.append (neutral, ind, len);
                }
        }

        return;
#else
        /*
         * Everyone else:
         *
         * Conversion to the local format requires checking for an alias that
         * matches the absolute part of the name (if any).  If there is no
         * alias, simply copy  the path replacing the single ':' with a '/'
         * and everything else as is.
         */
        const char		*p = neutral.c_str ();
        int			 code, len;
        size_t			 ind = 0, nSize = neutral.size ();

        local.clear ();

        /* Look for alias */
        if (Latin_Search (p, ':', 1))
                local.append ("/");

        for (; ind < nSize && p; ind++) {
                p = Latin_PullChar (&neutral[ind], &code, &len);
                if (code == ':')
                        local.append ("/");
                else {
                        if (len == 1)
                                local.append (neutral, ind, len);
                }
        }
#endif
}

        static char *
NFileToLocal (
        char			*local,
        const char		*neutral)
{
        std::string neu (neutral), loc;
        NFileToLocal (loc, neu);

        strcpy (local, loc.c_str());

        return local;
}

/*
 * To prepend a path, we first check that the original filename is relative.
 * If not, we're done.  Otherwise we make a neutral copy of the path and
 * attempt to append the base.  The basename is converted to neutral format
 * (using the filename buffer) and since it is a relative path no aliases
 * will be used.  We append a file separator if there is none and append the
 * basename.  We convert back to local format and we're done.
 */
        static bool
FilePathCompose (
        std::string		&fileName,
        const std::string	&basename,
        const std::string	&path)
{
        bool			 composed;

        if (FileIsAbsolute (basename.c_str())) {
                fileName = basename;
                composed = false;
        }
        else {
                if (!basename[0]) {
                        fileName = path;
                        composed = false;
                }
                else {
                        std::string	 temp;
                        NFileFromLocal (temp, path);
                        NFileFromLocal (fileName, basename);
                        size_t n = temp.size();
                        if (n && !IS_DIRSEP (temp[n - 1])) {
                                temp.append("/");
                        }

                        temp.append(fileName);
                        NFileToLocal (fileName, temp);

                        composed = true;
                }
        }

        return composed;
}

        static bool
FilePathCompose (
        char			*fileName,
        const char		*basename,
        const char		*path)
{
        bool			 composed;

        std::string fileN, baseN(basename), p(path);
        composed = FilePathCompose (fileN, baseN, p);

        strcpy (fileName, fileN.c_str ());

        return composed;
}

/*
 * File name substring comparison is done with the system-specific
 * path string compare.
 */
        static int
FileNameCompare (
        const char              *nameA,
        const char              *nameB,
        int                      len)
{
#if defined(_WIN32) || defined (_WIN64)
        /*
         * Windows (x86 and x64):
         */
        return strnicmp (nameA, nameB, len);
#else
        /*
         * Everyone else:
         *
         * The file n-compare function for MacOS X is a case-insensitive string compare.  
         * In this case, we use strncasecmp, defined in the BSD stdClib.
         */
        return strncasecmp (nameA, nameB, len);
#endif
}

        static std::string
FilePath (const std::string &baseFileName)
{
        std::string	baseFilePath(baseFileName);

        /*
         * Find the position of the last slash with reverse find.
         */
        char forwardSeparator = '/';
        size_t slashPos = baseFilePath.rfind (
                forwardSeparator, baseFilePath.length ());
        if (slashPos == std::string::npos) {
                char backSeparator = '\\';
                slashPos = baseFilePath.rfind (
                        backSeparator, baseFilePath.length ());
        }

        /*
         * If there was at least one forward slash, truncate to the left side.
         */
        if ((slashPos != std::string::npos) && (slashPos <= baseFilePath.length ()))
        {
                baseFilePath = baseFilePath.substr (0, slashPos + 1);
        }

        return baseFilePath;
}

/*
 * Extract the base name and path from a filename.  Either destination
 * pointer can be null and will not be written to in that case. The
 * path will be a bare filename without trailing slash or backslash.
 */

        static void
FileParseName (
        const std::string	&filename,
        std::string		*basename,
        std::string		*path)
{
        std::string		 buf;

        NFileFromLocal (buf, filename);
        const char *p_path = buf.c_str();

        const char *p_base = Latin_Search (p_path, '/', 1);
        int p_base_ind = buf.rfind ('/');
        const char *p2     = Latin_Search (p_path, ':', 1);
        int p2_ind = buf.rfind (':');
        if (!p_base || !p2 || p_base > p2) {
                int			 kill;

                kill = 0;
                if (!p_base && !p2) {
                        p_base = p_path;
                        p_path = (char*)"";
                } else if (!p_base) {
                        p_base = p2 + 1;
                        kill   = 1;
                } else
                        buf[p_base_ind++] = 0;

                if (basename)
                        NFileToLocal (*basename, p_base);

                if (path) {
                        if (kill)
                                buf[p2_ind + 1] = 0;

                        if (!p_path[0])
                                (*path)[0] = 0;
                        else
                                NFileToLocal (*path, p_path);
                }
        }
}

        static void
FileParseName (
        const char		*filename,
        char			*basename,
        char			*path)
{
        std::string fileN (filename), baseN (basename), p (path);
        std::string *baseNPtr = NULL, *pPtr = NULL;

        if (basename)
                baseNPtr = &baseN;

        if (path)
                pPtr = &p;

        FileParseName (fileN, baseNPtr, pPtr);

        strcpy (basename, baseN.c_str ());
        strcpy (path, p.c_str ());
}

        static bool
FileMakeAbsolute (
        std::string		&absFileName,
        const std::string	&fileName,
        const std::string	&baseFileName)
{
        bool	madeAbsolute;
        if (FileIsAbsolute (fileName.c_str()))
        {
                absFileName.append(fileName);
                madeAbsolute = true;
        }
        else
        {
                std::string	baseFilePath (FilePath (baseFileName));
                std::string	rel;
                if (fileName[0] == '.' &&
                        (fileName[1] == '/') || (fileName[1] == '\\'))
                {
                        rel = fileName.substr (
                                2, fileName.length () - 2);
                }
                else
                        rel = fileName;

                madeAbsolute = FilePathCompose (
                        absFileName,
                        rel,
                        baseFilePath);
        }

        return madeAbsolute;
}

        static bool
FileMakeAbsolute (
        char		*absFileName,
        const char	*fileName,
        const char	*baseFileName)
{
        bool	madeAbsolute;
        
        std::string absFileN, fileN (fileName), basefileN (baseFileName);
        madeAbsolute = FileMakeAbsolute (absFileN, fileN, basefileN);

        strcpy (absFileName, absFileN.c_str ());

        return madeAbsolute;
}

/*
 * Remove the path portion of the filename if it matches the path in baseFileName.
 * The result in relname will be relative to baseFileName, or it will be the same
 * as it started with.  This is useful for making absolute file names relative
 * to a known path.  Returns true if the path was made relative.
 */

        static bool
FileMakeRelative (
        std::string		&relname,
        const std::string	&filename,
        const std::string	&baseFileName)
{
        const char		*p;
        std::string		 temp;
        int			 len;
        std::string		 baseFilePath(FilePath (baseFileName));
        bool			 isRel = true;

        if (FileIsAbsolute (filename.c_str())) {
                NFileFromLocal (temp, filename);
                NFileFromLocal (relname, baseFilePath);

                isRel = false;
                len   = static_cast<int>(strlen (relname.c_str()));
                p = temp.c_str ();

                if (len && FileNameCompare (relname.c_str(), p, len) == 0) {
                        p += len;
                        if (*p == '/') {
                                isRel = 1;
                                while (*p == '/') {
                                        p++;
                                }
                        }
                        else if (IS_DIRSEP (p[-1]) || !*p) {
                                isRel = true;
                        }

                }

                if (isRel)
                        NFileToLocal (relname, p);
                else
                        relname = filename;
        }
        else {
                relname = filename;
        }

        return isRel;
}

        static bool
FileMakeRelative (
        char			*relname,
        const char		*filename,
        const char		*baseFileName)
{
        bool	isRel;
        
        std::string relN, fileN (filename), basefileN (baseFileName);
        isRel = FileMakeRelative (relN, fileN, basefileN);

        strcpy (relname, relN.c_str ());

        return isRel;
}

/*
 * ----------------------------------------------------------------
 * Public file utilities.
 *	
 */

namespace lx
{

        bool
ComposeFilePath (
        const std::string	&fileName,
        const std::string	&filePath,
        std::string		&composedPath)
{
        char			*buffer = new char[(fileName.size () + filePath.size ()) + 10];
        bool			 rc = false;

        composedPath = "";

        rc = FilePathCompose (buffer, fileName.c_str (), filePath.c_str ());
        if (rc)
                composedPath = buffer;

        delete[] buffer;

        return rc;
}

};	// End namespace lx.

/*
 * ----------------------------------------------------------------
 * Scene Builder Implementation
 *
 */
class pv_SceneBuilder {
    public:
        class cSingleton {
            public:
                bool		 exists;
                unsigned	 index;

                cSingleton () : exists (false) {}

                        void
                set (unsigned i)
                {
                        exists = true;
                        index = i;
                }

                        unsigned
                get ()
                {
                        if (!exists)
                                throw (LXe_NOTFOUND);

                        return index;
                }
        };

         pv_SceneBuilder (ILxUnknownID);
        ~pv_SceneBuilder ();

        unsigned			 PushItem (ILxUnknownID);
        unsigned			 AddItem  (LXtItemType);
        void				 SetItem  (unsigned);
        bool				 FindItem (ILxUnknownID, unsigned &);
        ILxUnknownID			 Item     (unsigned);
        LXtPointID			 Point    (unsigned);
        LXtPolygonID			 Polygon  (unsigned);
        LXtMeshMapID			 Map      (unsigned);
        bool				 GoodMesh ();
        bool				 GoodItem ();
        void				 Err      (LxResult);
        void				 Err      (CLxResult);
        void				 Err      (bool);
        ILxUnknownID			 ByCue    (LXtItemType, const char *);
        unsigned			 Single   (int);
        bool				 IsA	  (const char *);
        bool				 IsA	  (LXtItemType);

        LxResult			 error;

        CLxUser_MeshService		 mesh_S;
        CLxUser_SceneService		 scene_S;
        CLxUser_ValueService		 value_S;
        CLxUser_Scene			 scene;
        CLxUser_ChannelWrite		 chan, anim;
        LXtItemType			 cit_scene;
        LXtItemType			 cit_render;
        LXtItemType			 cit_polyRender;
        LXtItemType			 cit_defaultShader;
        LXtItemType			 cit_mask;
        LXtItemType			 cit_sfolder;
        LXtItemType			 cit_environ;
        LXtItemType			 cit_txtr;
        LXtItemType			 cit_txtrloc;
        LXtItemType			 cit_mesh;

        CLxUser_Item			 item;
        CLxUser_StringTag		 itemTag;
        unsigned			 curIndex;

        std::vector<ILxUnknownID>	 itemList;

        CLxUser_Mesh			 mesh;
        CLxUser_Point			 point;
        std::vector<LXtPointID>		 pntList;

        CLxUser_Edge			 edge;

        CLxUser_Polygon			 poly;
        CLxUser_StringTag		 polyTag;
        std::vector<LXtPolygonID>	 polList;
        std::vector<LXtPointID>		 pverts;
        LXtID4			 	 ptype;

        CLxUser_MeshMap			 mmap;
        std::vector<LXtMeshMapID>	 mapList;

        cSingleton			 sScene, sRender;

        // Default shader position in the shader tree
        // as a child of render object
        unsigned			 defaultShaderPosition;

        cSingleton			 sCurMask, sEnvFold;
};

/*
 * Optional macro for debug output. Prints the name and arguments of every call.
 */
#if 0
 #define SB_DBG(x)		 printf x
#else
 #define SB_DBG(x)
#endif

/*
 * The scene builder should raise only LxResult exceptions.  This macro catches
 * anything else and converts.
 */
#define CATCH_ALL_F(x)		catch (std::bad_alloc &) { x (LXe_OUTOFMEMORY); }
#define CATCH_ALL		CATCH_ALL_F(pv->Err)


/*
 * Init booleans, item types, and get the state from the starting scene.
 * If there any any items in the scene we pick out the singletons by adding
 * them to our local list.
 */
pv_SceneBuilder::pv_SceneBuilder (
        ILxUnknownID		 obj)
{
        error = LXe_OK;

        cit_scene			= scene_S.ItemType (LXsITYPE_SCENE);
        cit_render			= scene_S.ItemType (LXsITYPE_RENDER);
        cit_polyRender		= scene_S.ItemType (LXsITYPE_POLYRENDER);
        cit_defaultShader	= scene_S.ItemType (LXsITYPE_DEFAULTSHADER);
        cit_mask			= scene_S.ItemType (LXsITYPE_MASK);
        cit_sfolder			= scene_S.ItemType (LXsITYPE_SHADERFOLDER);
        cit_environ			= scene_S.ItemType (LXsITYPE_ENVIRONMENT);
        cit_txtr			= scene_S.ItemType (LXsITYPE_TEXTURELAYER);
        cit_txtrloc			= scene_S.ItemType (LXsITYPE_TEXTURELOC);
        cit_mesh			= scene_S.ItemType (LXsITYPE_MESH);

        if (!scene.set (obj) ||
            !scene.SetChannels (chan, LXs_ACTIONLAYER_SETUP) ||
            !scene.SetChannels (anim, LXs_ACTIONLAYER_EDIT) )
        {
                error = LXe_INVALIDARG;
                return;
        }

        // Find the default render in the scene graph or create a new one
        Single (CLxSceneBuilder::RENDER);

        // Find out if there is a default shader for future materials to be placed under
        unsigned				subCount, shaderSubNum;
        CLxUser_Item			render(item), subItem;

        defaultShaderPosition = 0;

        // Find the default shader index in the list of render item children
        render.SubCount (&subCount);

        for (shaderSubNum = 0; shaderSubNum < subCount; ++shaderSubNum)
        {
                render.SubByIndex (shaderSubNum, subItem);

                if (LXe_TRUE == subItem.TestType (cit_defaultShader))
                {
                        defaultShaderPosition = shaderSubNum;
                        break;
                }
        }
}

pv_SceneBuilder::~pv_SceneBuilder ()
{
}

/*
 * Check for error, clear ourselves and throw.
 */
        void
pv_SceneBuilder::Err (
        LxResult		 rc)
{
        if (LXx_FAIL (rc)) {
                error = rc;
                scene.clear ();
                item.clear ();
                chan.clear ();
                anim.clear ();
                mesh.clear ();
                throw (rc);
        }
}

        void
pv_SceneBuilder::Err (
        CLxResult		 rc)
{
        Err (rc.resultCode());
}

        void
pv_SceneBuilder::Err (
        bool			 ok)
{
        if (!ok)
                Err (LXe_FAILED);
}

/*
 * Get each of the singletons by type. In most cases if we don't have it
 * search for the existing item or create it. We always create a new render
 * item because that's how import expects it to work. (#56408)
 */
        unsigned
pv_SceneBuilder::Single (
        int			 what)
{
        bool			 hasPrev = item.test();
        unsigned		 prev = curIndex;

        if (what == CLxSceneBuilder::CURMASK)
                return sCurMask.get();

        if (what == CLxSceneBuilder::RENDER)
        {
                if (!sRender.exists)
                {
                        if (scene.GetItem (cit_render, item) && scene.GetItem (cit_polyRender, item))
                                sRender.set (PushItem (item));
                        else
                                AddItem (cit_polyRender);

                        if (hasPrev)
                                SetItem (prev);
                }

                return sRender.get();
        }

        if (what == CLxSceneBuilder::SCENE)
        {
                if (!sScene.exists)
                {
                        CLxUser_Item	 item;

                        if (scene.GetItem (cit_scene, item))
                                sScene.set (PushItem (item));
                        else
                                AddItem (cit_scene);

                        if (hasPrev)
                                SetItem (prev);
                }

                return sScene.get();
        }

        if (what == CLxSceneBuilder::ENVIRON)
        {
                if (!sEnvFold.exists)
                {
                        ILxUnknownID	 fold;

                        fold = ByCue (cit_sfolder, "envShaders");
                        if (fold)
                                sEnvFold.set (PushItem (fold));
                        else
                        {
                                sEnvFold.set (AddItem (cit_sfolder));
                                itemTag.Set (LXiTAG_CUE, "envShaders");
                        }

                        if (hasPrev)
                                SetItem (prev);
                }

                return sEnvFold.get();
        }

        return ~0;
}

/*
 * Tests if the current item is of the provided type.
 */

        bool
pv_SceneBuilder::IsA (
        const char		*type)
{
        return IsA (scene_S.ItemType (type));
}
        
        bool
pv_SceneBuilder::IsA (
        LXtItemType		 type)
{	
        if (item.test () && type != LXiTYPE_NONE)
                return item.IsA (type);

        return false;
}

/*
 * The item list keeps raw item object pointers without add-refing them, since
 * they may go away if a read is aborted. We'll assume for the purposes of
 * building a scene that the items will persist after we add them.
 *
 * NOTE: I think with zombie objects this is now no longer an issue.
 */
        unsigned
pv_SceneBuilder::PushItem (
        ILxUnknownID		 obj)
{
        unsigned		 index;

        try {
                itemList.push_back (obj);
        } CATCH_ALL_F (Err)

        index = static_cast<unsigned>(itemList.size () - 1);
        SetItem (index);
        return index;
}

        ILxUnknownID
pv_SceneBuilder::Item (
        unsigned		 index)
{
        if (index >= itemList.size ())
                Err (LXe_OUTOFBOUNDS);

        return itemList[index];
}

/*
 * Setting the current item inits the various wrappers for it. We also check
 * if this is a shading mask and set that state as well.
 */
        void
pv_SceneBuilder::SetItem (
        unsigned		 index)
{
        ILxUnknownID		 obj;

        if (index >= itemList.size ())
                Err (LXe_OUTOFBOUNDS);

        obj = itemList[index];
        item.set (obj);
        itemTag.set (obj);
        curIndex = index;

        if (item.IsA (cit_render))
                sRender.set (index);
        else if (item.IsA (cit_scene))
                sScene.set (index);

        if (item.IsA (cit_mask) || item.IsA (cit_environ))
                sCurMask.set (index);

        if (item.IsA (cit_mesh)) {
                unsigned int		 idx;
                idx = item.ChannelIndex (LXsICHAN_MESH_MESH);

                Err (  chan.ValueObj (item, idx, (void **) &obj) );
                mesh.take (obj);
                mesh.GetPoints   (point);
                mesh.GetPolygons (poly);
                mesh.GetMaps     (mmap);
                polyTag.set      (poly);
        }
}

        bool
pv_SceneBuilder::FindItem (
        ILxUnknownID		 obj,
        unsigned		&index)
{
        for (unsigned int i = 0; i < itemList.size (); i++)
        {
                if (obj == itemList[i])
                {
                        index = i;
                        return true;
                }
        }

        return false;
}

        unsigned
pv_SceneBuilder::AddItem (
        LXtItemType		 type)
{
        Err ( scene.ItemAdd (type, item) );
        return PushItem (item);
}

/*
 * Find existing item matching cue string.
 */
        ILxUnknownID
pv_SceneBuilder::ByCue (
        LXtItemType		 type,
        const char		*str)
{
        CLxUser_Item		 item;
        CLxUser_StringTag	 tags;
        unsigned		 i, n;

        n = scene.NItems (type);
        for (i = 0; i < n; i++)
        {
                scene.GetItem (type, i, item);
                tags.set (item);
                if (tags.Match (LXiTAG_CUE, str))
                        return item;
        }

        return 0;
}

/*
 * Get points, polygons and maps out of their respective lists.
 */
        LXtPointID
pv_SceneBuilder::Point (
        unsigned		 index)
{
        if (index >= pntList.size ())
                Err (LXe_OUTOFBOUNDS);

        return pntList[index];
}

        LXtPolygonID
pv_SceneBuilder::Polygon (
        unsigned		 index)
{
        if (index >= polList.size ())
                Err (LXe_OUTOFBOUNDS);

        return polList[index];
}

        LXtMeshMapID
pv_SceneBuilder::Map (
        unsigned		 index)
{
        if (index >= mapList.size ())
                Err (LXe_OUTOFBOUNDS);

        return mapList[index];
}

/*
 * Return true if we have a mesh.
 */
        bool
pv_SceneBuilder::GoodMesh ()
{
        return (mesh.test () ? true : false);
}

/*
 * Utterly fail if we don't have an item.
 */
        bool
pv_SceneBuilder::GoodItem ()
{
        if (!item.test ())
                Err (LXe_NOTFOUND);

        return true;
}


/*
 * The scene builder starts with a null private pointer which is allocated
 * and cleared for each scene. In theory this means the builder can be used
 * to create multiple scenes, but who would.
 */
CLxSceneBuilder::CLxSceneBuilder ()
{
        pv = 0;
}

CLxSceneBuilder::~CLxSceneBuilder ()
{
        Cleanup ();
}

        bool
CLxSceneBuilder::IsGood ()
{
        return pv && LXx_OK (pv->error);
}

        LxResult
CLxSceneBuilder::ErrorCode ()
{
        return pv ? pv->error : LXe_NOACCESS;
}

        void
CLxSceneBuilder::Initialize (
        ILxUnknownID		 scene)
{
        try {
                pv = new pv_SceneBuilder (scene);
        } CATCH_ALL_F (throw)

        pv->Err (pv->error);
}

        LxResult
CLxSceneBuilder::Finalize ()
{
        LxResult		 rc;

        SB_DBG (("SceneBuilder::Finalize\n"));

        if (IsGood ()) {
                // real stuff
                rc = LXe_OK;
        } else
                rc = pv->error;

        delete pv;
        pv = 0;
        return rc;
}

        void
CLxSceneBuilder::Cleanup ()
{
        if (pv) {
                delete pv;
                pv = 0;
        }
}

        bool
CLxSceneBuilder::IsValid ()
{
        return (pv != NULL && pv->scene.test ());
}

        unsigned
CLxSceneBuilder::Singleton (
        int			 what)
{
        return pv->Single (what);
}

        unsigned
CLxSceneBuilder::SceneItem  ()
{
        return pv->Single (SCENE);
}

        ILxUnknownID
CLxSceneBuilder::SceneObject ()
{
        return pv->scene;
}


/*
 * Adding items also sets them, so they become the current item.
 */
        unsigned
CLxSceneBuilder::AddItem (
        const char		*itemType)
{
        LXtItemType		 type;
        
        if (!IsGood ())
                return 0;
        
        SB_DBG (("SceneBuilder::AddItem %s\n", itemType));
        
        pv->Err (  pv->scene_S.ItemTypeLookup (itemType, &type)	);

        return pv->AddItem (type);
}

                unsigned
CLxSceneBuilder::PushItem (
        ILxUnknownID	 item)
{
        if (!IsGood ())
                return 0;
        
        SB_DBG (("SceneBuilder::PushItem \n"));

        return pv->PushItem (item);
}


        unsigned
CLxSceneBuilder::InstItem (
        unsigned		 index)
{
        if (!IsGood ())
                return 0;
        
        SB_DBG (("SceneBuilder::InstItem %d\n", index));
        
        pv->Err (  pv->scene.ItemInstance (pv->Item (index), pv->item) ? LXe_OK : LXe_FAILED);

        return pv->PushItem (pv->item);
}

        void
CLxSceneBuilder::SetItem (
        unsigned		 index)
{
        if (!IsGood ())
                return;

        SB_DBG (("SceneBuilder::SetItem %d\n", index));

        pv->SetItem (index);
}

        unsigned
CLxSceneBuilder::CurItem ()
{
        return pv->curIndex;
}


        ILxUnknownID
CLxSceneBuilder::GetItem ()
{
        return pv->item;
}

        bool
CLxSceneBuilder::GetItem (
        CLxLocalizedObject	&item)
{
        return item.set (pv->item);
}

        bool
CLxSceneBuilder::GetMesh (
        CLxLocalizedObject	&mesh)
{
        return mesh.set (pv->mesh);
}

        void
CLxSceneBuilder::SetName (
        const char		*name)
{
        if (!IsGood () || !pv->GoodItem ())
                return;

        pv->Err (  pv->item.SetName (name)	);
}

        void
CLxSceneBuilder::SetTag (
        LXtID4			 type,
        const char		*value)
{
        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetTag %d %s\n", type, value));

        pv->Err (pv->itemTag.Set (type, value));
}

        void
CLxSceneBuilder::SetParent (
        unsigned int		 index,
        unsigned int		 childPos)
{
        ILxUnknownID		 item;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetParent %d\n", index));

        item = pv->Item (index);
        if (childPos == -1)
                pv->Err (  pv->item.SetParent (item)	);
        else
                pv->Err (  pv->item.SetParentAndPosition (item, childPos)	);
}

        void
CLxSceneBuilder::SetLink (
        const char		*type,
        unsigned int		 to)
{
        CLxUser_SceneGraph	 sgr;
        CLxUser_ItemGraph	 igr;
        ILxUnknownID		 iTo;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetLink %s %d\n", type, index));

        pv->Err (  pv->scene.GetGraph (type, sgr) ? LXe_OK : LXe_FAILED);
        if (!igr.set (sgr))
                pv->Err (LXe_NOINTERFACE);

        iTo = pv->Item (to);

        pv->Err (  igr.AddLink (pv->item, iTo)	);
}

        void
CLxSceneBuilder::SetLink(
        const char		*type,
        unsigned int		 to,
        int			 fromIndex,
        int			 toIndex)
{
        CLxUser_SceneGraph	 sgr;
        CLxUser_ItemGraph	 igr;
        ILxUnknownID		 iTo;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetLink %s %d\n", type, index));

        pv->Err (  pv->scene.GetGraph (type, sgr) ? LXe_OK : LXe_FAILED);
        if (!igr.set (sgr))
                pv->Err (LXe_NOINTERFACE);

        iTo = pv->Item (to);

        pv->Err (  igr.SetLink (pv->item, fromIndex, iTo, toIndex)	);
}

        void
CLxSceneBuilder::SetLink (
        const char		*channelFrom,
        unsigned int		 itemTo,
        const char		*channelTo)
{
        CLxUser_SceneGraph	 sgr;
        CLxUser_ChannelGraph	 cgr;
        CLxUser_Item		 iTo;
        unsigned		 chanIndexTo = 0;
        unsigned		 chanIndexFrom = 0;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetLink %d %s %d %s\n", index, channelFrom, itemTo, channelTo));

        pv->Err (  pv->scene.GetGraph (LXsGRAPH_CHANLINKS, sgr) ? LXe_OK : LXe_FAILED);
        if (!cgr.set (sgr))
                pv->Err (LXe_NOINTERFACE);

        if (!iTo.set (pv->Item (itemTo)))
                pv->Err (LXe_NOINTERFACE);

        pv->Err (  iTo.ChannelLookup (channelTo, &chanIndexTo) );
        pv->Err (  pv->item.ChannelLookup (channelFrom, &chanIndexFrom) );
        pv->Err (  cgr.AddLink (pv->item, chanIndexFrom, iTo, chanIndexTo) );
}

        unsigned
CLxSceneBuilder::AddRenderOutput (
        const char		*path,
        const char		*format,
        const char		*effect)
{
        if (!IsGood ())
                return 0;

        SB_DBG (("SceneBuilder::AddRenderOutput\n"));

        AddTexture (LXsITYPE_RENDEROUTPUT, CLxSceneBuilder::RENDER);

        if (path && strlen (path) > 0)
        {
                SetChannel (LXsICHAN_RENDEROUTPUT_FILENAME, path);
                SetChannel (LXsICHAN_RENDEROUTPUT_FORMAT, (format && strlen (format) > 0) ? format : "$Targa");
        }

        SetChannel (LXsICHAN_TEXTURELAYER_EFFECT, effect ? effect : "shade.color");

        return pv->curIndex;;
}

        bool
CLxSceneBuilder::GoodMesh ()
{
        return pv->GoodMesh ();
}

        void
CLxSceneBuilder::SetChannel (
        const char		*channel,
        bool			 value)
{
        unsigned		 idx;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %s = %d\n", channel, value));

        pv->Err (  pv->item.ChannelLookup (channel, &idx)	);
        pv->Err (  pv->chan.Set (pv->item, idx, value ? 1 : 0) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetChannel (
        const char		*channel,
        int			 value)
{
        unsigned		 idx;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %s = %d\n", channel, value));

        pv->Err (  pv->item.ChannelLookup (channel, &idx)	);
        pv->Err (  pv->chan.Set (pv->item, idx, value) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetChannel (
        const char		*channel,
        double			 value)
{
        unsigned		 idx;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %s = %f\n", channel, value));

        pv->Err (  pv->item.ChannelLookup (channel, &idx)	);
        pv->Err (  pv->chan.Set (pv->item, idx, value) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetChannelColor (
        const char		*channel,
        const LXtVector		&color)
{
        unsigned		 idxRed, idxGreen, idxBlue;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %s = %f\n", channel, value));

        using namespace std;
        string channelRed = string(channel) + string(".R");
        string channelGreen = string(channel) + string(".G");
        string channelBlue = string(channel) + string(".B");

        pv->Err (  pv->item.ChannelLookup (channelRed.c_str (), &idxRed)	);
        pv->Err (  pv->item.ChannelLookup (channelGreen.c_str (), &idxGreen)	);
        pv->Err (  pv->item.ChannelLookup (channelBlue.c_str (), &idxBlue)	);

        pv->Err (  pv->chan.Set (pv->item, idxRed, color[0]) ? LXe_OK : LXe_FAILED);
        pv->Err (  pv->chan.Set (pv->item, idxGreen, color[1]) ? LXe_OK : LXe_FAILED);
        pv->Err (  pv->chan.Set (pv->item, idxBlue, color[2]) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetChannel (
        const char		*channel,
        const char		*value)
{
        unsigned		 idx;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %s = %s\n", channel, value));

        pv->Err (  pv->item.ChannelLookup (channel, &idx)	);
        pv->Err (  pv->chan.Set (pv->item, idx, value) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetChannelEncoded (
        const char		*channel,
        const char		*encodedValue)
{
        unsigned		 channelIndex;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %s = %s\n", channel, value));

        pv->Err (pv->item.ChannelLookup (channel, &channelIndex));

        /*
         * Ask the value service to convert the encoded channel value
         * into an integer value.
         */
        const LXtTextValueHint *hints = NULL;
        pv->item.ChannelIntHint (channelIndex, &hints);
        int	value;
        pv->Err (pv->value_S.TextHintDecode (
                encodedValue, hints, &value));

        pv->Err (  pv->chan.Set (pv->item, channelIndex, value) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetChannel (
        unsigned int		 channel,
        bool			 value)
{
        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %d = %d\n", channel, value));

        pv->Err (  pv->chan.Set (pv->item, channel, value ? 1 : 0) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetChannel (
        unsigned int		 channel,
        int			 value)
{
        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %d = %d\n", channel, value));

        pv->Err (  pv->chan.Set (pv->item, channel, value) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetChannel (
        unsigned int		 channel,
        double			 value)
{
        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %d = %f\n", channel, value));

        pv->Err (  pv->chan.Set (pv->item, channel, value) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetChannel (
        unsigned int		 channel,
        const char		*value)
{
        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %d = %s\n", channel, value));

        pv->Err (  pv->chan.Set (pv->item, channel, value) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetChannelEncoded (
        unsigned int		 channel,
        const char		*encodedValue)
{
        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetChannel %d = %s\n", channel, encodedValue));

        /*
         * Ask the value service to convert the encoded channel value
         * into an integer value.
         */
        const LXtTextValueHint *hints = NULL;
        pv->item.ChannelIntHint (channel, &hints);
        int	value;
        pv->Err (pv->value_S.TextHintDecode (
                encodedValue, hints, &value));

        pv->Err (  pv->chan.Set (pv->item, channel, value) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::SetEditTime (
        double			 frameTime)
{
        pv->Err ( pv->scene.SetChannels (pv->anim, LXs_ACTIONLAYER_EDIT, frameTime) ? LXe_OK : LXe_FAILED );
}

        void
CLxSceneBuilder::AddEnvelope (
        const char		*channel,
        CLxUser_Envelope	&env)
{
        unsigned		 idx;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::AddEnvelope %s\n", channel));

        pv->Err (  pv->item.ChannelLookup (channel, &idx)	);
        pv->Err (  pv->anim.AddEnv (pv->item, idx, env) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::AddEnvelope (
        unsigned int		 channel,
        CLxUser_Envelope	&env)
{
        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::AddEnvelope %d\n", channel));

        pv->Err (  pv->anim.AddEnv (pv->item, channel, env) ? LXe_OK : LXe_FAILED);
}

        void
CLxSceneBuilder::AddValue (
        const char		*channel,
        CLxUser_Value		&value)
{
        LXtObjectID		 obj = NULL;
        unsigned int		 idx;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::AddValue %s\n", channel));

        pv->Err (  pv->item.ChannelLookup (channel, &idx)	);
        pv->Err (  pv->chan.ValueObj (pv->item, idx, (void **) &obj)	);

        if (!obj || !value.take (obj))
                pv->Err (LXe_FAILED);
}

        void
CLxSceneBuilder::AddValue (
        unsigned int		 channel,
        CLxUser_Value		&value)
{
        LXtObjectID		 obj = NULL;

        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::AddEnvelope %d\n", channel));

        pv->Err (  pv->chan.ValueObj (pv->item, channel, (void **) &obj)	);

        if (!obj || !value.take (obj))
                pv->Err (LXe_FAILED);
}

        void
CLxSceneBuilder::SetXform (
        LXtTransformType	 type,
        double			 vec[3])
{
        if (!IsGood () || !pv->GoodItem ())
                return;

        SB_DBG (("SceneBuilder::SetXform %d (%f %f %f)\n", type, vec[0], vec[1], vec[2]));

        CLxUser_Locator locator;
        if (locator.set (pv->item)) {
                pv->Err (locator.SetTransformVector (pv->chan, type, vec));
        }
        else {
                pv->Err (LXe_NOINTERFACE);
        }
}

        void
CLxSceneBuilder::SetXform (
        LXtTransformType	 type,
        double			 x,
        double			 y,
        double			 z)
{
        double			 vec[3] = { x, y, z };

        SetXform (type, vec);
}

        void
CLxSceneBuilder::SetXform (
        LXtTransformType	 type,
        double			 val)
{
        double			 vec[3] = { val, val, val };

        SetXform (type, vec);
}

        unsigned
CLxSceneBuilder::AddXform (
        LXtTransformType	 type,
        unsigned		*index)
{
        LXtObjectID		 obj;

        if (!IsGood () || !pv->GoodItem ())
                return 0;

        SB_DBG (("SceneBuilder::AddXform %d\n", type));

        CLxUser_Locator locator;
        if (locator.set (pv->item)) {
                pv->Err (locator.AddTransformItem (type, &obj, index));
                if (!pv->item.take (obj))
                        pv->Err (LXe_NOINTERFACE);

                pv->PushItem (pv->item);
        }
        else {
                pv->Err (LXe_NOINTERFACE);
        }

        return pv->curIndex;
}

        unsigned
CLxSceneBuilder::AddPreXform (LXtTransformType type, double vec[3], unsigned *index)
{
        if (!IsGood () || !pv->GoodItem ())
                return 0;

        SB_DBG (("SceneBuilder::AddPostXform %d\n", type));

        LXtObjectID		 obj;

        CLxUser_Locator locator;
        if (locator.set (pv->item)) {
                pv->Err (locator.AddPreTransformItem (pv->chan, type, vec, &obj, index));
                if (!pv->item.take (obj))
                        pv->Err (LXe_NOINTERFACE);

                pv->PushItem (pv->item);
        }
        else {
                pv->Err (LXe_NOINTERFACE);
        }

        return pv->curIndex;
}

        unsigned
CLxSceneBuilder::AddPreXform (LXtTransformType type, double x, double y, double z, unsigned *index)
{
        double			 vec[3] = { x, y, z };

        return AddPreXform (type, vec, index);
}

        unsigned
CLxSceneBuilder::AddPreXform (LXtTransformType type, double val, unsigned *index)
{
        double			 vec[3] = { val, val, val };

        return AddPreXform (type, vec, index);
}

        unsigned
CLxSceneBuilder::AddPostXform (LXtTransformType type, double vec[3], unsigned *index)
{
        if (!IsGood () || !pv->GoodItem ())
                return 0;

        SB_DBG (("SceneBuilder::AddPostXform %d\n", type));

        LXtObjectID		 obj;

        CLxUser_Locator locator;
        if (locator.set (pv->item)) {
                pv->Err (locator.AddPostTransformItem (pv->chan, type, vec, &obj, index));
                if (!pv->item.take (obj)) {
                        pv->Err (LXe_NOINTERFACE);
                }

                pv->PushItem (pv->item);
        }
        else {
                pv->Err (LXe_NOINTERFACE);
        }

        return pv->curIndex;
}

        unsigned
CLxSceneBuilder::AddPostXform (LXtTransformType type, double x, double y, double z, unsigned *index)
{
        double			 vec[3] = { x, y, z };

        return AddPostXform (type, vec, index);
}

        unsigned
CLxSceneBuilder::AddPostXform (LXtTransformType type, double val, unsigned *index)
{
        double			 vec[3] = { val, val, val };

        return AddPostXform (type, vec, index);
}

        unsigned
CLxSceneBuilder::PrependXform (LXtTransformType type, double vec[3], unsigned *index)
{
        if (!IsGood () || !pv->GoodItem ())
                return 0;

        SB_DBG (("SceneBuilder::PrependXform %d\n", type));

        LXtObjectID		 obj;

        CLxUser_Locator locator;
        if (locator.set (pv->item)) {
                pv->Err (locator.PrependTransformItem (pv->chan, type, vec, &obj, index));
                if (!pv->item.take (obj)) {
                        pv->Err (LXe_NOINTERFACE);
                }

                pv->PushItem (pv->item);
        }
        else {
                pv->Err (LXe_NOINTERFACE);
        }

        return pv->curIndex;
}

        unsigned
CLxSceneBuilder::PrependXform (LXtTransformType type, double x, double y, double z, unsigned *index)
{
        double			 vec[3] = { x, y, z };

        return PrependXform (type, vec, index);
}

        unsigned
CLxSceneBuilder::PrependXform (LXtTransformType type, double val, unsigned *index)
{
        double			 vec[3] = { val, val, val };

        return PrependXform (type, vec, index);
}

        unsigned
CLxSceneBuilder::AppendXform (LXtTransformType type, double vec[3], unsigned *index)
{
        if (!IsGood () || !pv->GoodItem ())
                return 0;

        SB_DBG (("SceneBuilder::AppendXform %d\n", type));

        LXtObjectID		 obj;

        CLxUser_Locator locator;
        if (locator.set (pv->item)) {
                pv->Err (locator.AppendTransformItem (pv->chan, type, vec, &obj, index));
                if (!pv->item.take (obj))
                        pv->Err (LXe_NOINTERFACE);

                pv->PushItem (pv->item);
        }
        else {
                pv->Err (LXe_NOINTERFACE);
        }

        return pv->curIndex;
}

        unsigned
CLxSceneBuilder::AppendXform (LXtTransformType type, double x, double y, double z, unsigned *index)
{
        double			 vec[3] = { x, y, z };

        return AppendXform (type, vec, index);
}

        unsigned
CLxSceneBuilder::AppendXform (LXtTransformType type, double val, unsigned *index)
{
        double			 vec[3] = { val, val, val };

        return AppendXform (type, vec, index);
}

        void
CLxSceneBuilder::AddPackage (const char *name)
{
        pv->Err (pv->item.PackageAdd (name));
}

        unsigned
CLxSceneBuilder::RenderItem ()
{
        return pv->Single (RENDER);
}


/*
 * Adding a texture layer can be done in a subset of locations.
 */
        unsigned
CLxSceneBuilder::AddTexture (
        const char		*type,
        int			 where)
{
        int			 whereIdx = 0;

        if (!IsGood ())
                return 0;

        if (where == RENDER || where == ENVIRON)
                pv->sCurMask.set (pv->Single (where));

        whereIdx = pv->sCurMask.get();

        AddItem (type);
        if (where == RENDER)
                SetParent (whereIdx, pv->defaultShaderPosition);
        else
                SetParent (whereIdx);
        return pv->curIndex;
}

        unsigned
CLxSceneBuilder::AddMaterial (
        const char		*matName,
        int				 where,
        const char		*matType)
{
        unsigned		 msk;

        msk = AddTexture (LXsITYPE_MASK, where);
        SetChannel (LXsICHAN_MASK_PTAG, matName);

        AddItem (matType);
        SetParent (msk);
        return msk;
}

        unsigned
CLxSceneBuilder::AddImageFolder (
        const char		*folderName)
{
        return AddItem (LXsITYPE_IMAGEFOLDER);
}

        void
CLxSceneBuilder::SpecExponent (
        double			 exp)
{
        if (exp > 0.0)
                SetChannel (LXsICHAN_ADVANCEDMATERIAL_ROUGH, 1.0 - ((log (exp) / log (2.0) - 2.0) / 10.0));
        else
                SetChannel (LXsICHAN_ADVANCEDMATERIAL_ROUGH, 1.0); // use a default value when exp is invalid
}

        unsigned
CLxSceneBuilder::AddImage (
        const char		*filename)
{
        ILxUnknownID		 clip;
        LxResult		 rc;

        if (!IsGood ())
                return 0;

        SB_DBG (("SceneBuilder::AddImage\n"));

        rc = pv->scene_S.LoadImage (pv->scene, filename, NULL, (void**) &clip);
        if (rc == LXe_NOTFOUND)
                return 0;

        if (rc == LXe_SKIP)
                return 0;

        pv->Err (rc);

        pv->item.take (clip);
        return pv->PushItem (clip);
}

        unsigned
CLxSceneBuilder::AddImageMap (
        const char		*filename,
        const char		*effect,
        const char		*uvmap,
        int			 where)
{
        CLxUser_Texture		 txtr;
        unsigned		 mapidx;

        if (!IsGood ())
                return 0;

        SB_DBG (("SceneBuilder::AddImageMap\n"));

        mapidx = AddTexture (LXsITYPE_IMAGEMAP, where);
        GetItem (txtr);
        txtr.SetEffect (effect);

        if (AddImage (filename))
                txtr.SetImage (GetItem ());

        if (uvmap)
        {
                SetItem (mapidx);
                SetItem (TxtrLocator ());
                SetChannel (LXsICHAN_TEXTURELOC_UVMAP,    uvmap);
                SetChannel (LXsICHAN_TEXTURELOC_PROJTYPE, LXi_TEXTURE_PROJ_MODE_UVMAP);
        }

        // restore imageMap item to current
        SetItem (mapidx);
        return mapidx;
}

        unsigned int
CLxSceneBuilder::TxtrLocator ()
{
        if (!pv->item.test () || !pv->item.IsA (pv->cit_txtr))
                return ~0;

        CLxUser_Item		 txtr (pv->item), tloc;
        CLxUser_ItemGraph	 graph;
        unsigned		 index = 0;
        unsigned		 n;

        if (pv->scene.GetGraph (LXsGRAPH_SHADELOC, graph))
        {
                n = graph.Forward (txtr);
                for (unsigned int i = 0; i < n; i++)
                {
                        graph.Forward (txtr, i, tloc);
                        if (tloc.IsA (pv->cit_txtrloc))
                        {
                                if (!pv->FindItem (tloc, index))
                                        index = pv->PushItem (tloc);

                                return index;
                        }
                }
        }

        index = AddItem (LXsITYPE_TEXTURELOC);
        pv->Err ( graph.AddLink (txtr, pv->item) );

        return index;
}

        unsigned
CLxSceneBuilder::AddMesh (
        bool			 asStatic)
{
        LXtObjectID		 mesh;
        unsigned int		 ret, idx;

        if (!IsGood ())
                return 0;

        SB_DBG (("SceneBuilder::AddMesh\n"));

        pv->mesh.clear ();
        pv->pntList.clear ();
        pv->polList.clear ();
        pv->mapList.clear ();

        if (asStatic) {
                /* To make a static mesh from a regular mesh we create the
                 * static mesh item (triSurf) that will eventually hold the
                 * converted data, and create a *temporary* mesh for the app
                 * to populate. Calling ConvertMesh() will complete the item.
                 */
                ret = AddItem (LXsITYPE_TRISURF);

                pv->Err (  pv->mesh_S.CreateMesh (&mesh) );

        } else {
                ret = AddItem (LXsITYPE_MESH);

                // setup mesh channel
                idx = pv->item.ChannelIndex (LXsICHAN_MESH_MESH);

                pv->Err (  pv->chan.ValueObj (pv->item, idx, (void **) &mesh)	);
        }

        if (!pv->mesh.take (mesh)             ||
            !pv->mesh.GetPoints   (pv->point) ||
            !pv->mesh.GetPolygons (pv->poly)  ||
            !pv->mesh.GetMaps     (pv->mmap)  ||
            !pv->polyTag.set      (pv->poly)    )
                pv->Err (LXe_FAILED);

        return ret;
}

        unsigned
CLxSceneBuilder::ConvertMesh ()
{
        if (!IsGood () || !GoodMesh())
                return 0;

        SB_DBG (("SceneBuilder::ConvertMesh\n"));

        int			    idx = pv->item.ChannelIndex (LXsICHAN_TRISURF_SURF);
        CLxUser_TriangleGroup	    triGroup;

        pv->Err (  pv->chan.Object (pv->item, idx, triGroup) ? LXe_OK : LXe_FAILED );
        pv->Err (  pv->mesh_S.ConvertMesh (triGroup, pv->mesh) );

        pv->mesh.clear ();
        pv->pntList.clear ();
        pv->polList.clear ();
        pv->mapList.clear ();

        return 1;
}

        unsigned int
CLxSceneBuilder::AddPoint (
        LXtVector		 pos)
{
        LXtPointID		 pnt;

        if (!pv->GoodMesh ())
                return 0;

        SB_DBG (("SceneBuilder::AddPoint %f %f %f\n", pos[0], pos[1], pos[2]));

        pv->Err (  pv->point.New (pos, &pnt)	);

        try {
                pv->pntList.push_back (pnt);
        } CATCH_ALL

        return static_cast<unsigned int>(pv->pntList.size () - 1);
}

        unsigned int
CLxSceneBuilder::AddPoint (
        LXtFVector		 pos)
{
        LXtVector		 fv;

        fv[0] = pos[0];
        fv[1] = pos[1];
        fv[2] = pos[2];
        return AddPoint (fv);
}

        unsigned int
CLxSceneBuilder::AddPoint (
        double			 x,
        double			 y,
        double			 z)
{
        LXtVector		 fv;

        fv[0] = x;
        fv[1] = y;
        fv[2] = z;
        return AddPoint (fv);
}

        void
CLxSceneBuilder::StartPoly (
        LXtID4			 type)
{
        if (!pv->GoodMesh ())
                return;

        SB_DBG (("SceneBuilder::StartPoly %d\n", type));

        pv->pverts.clear();
        pv->ptype = type;
}

        void
CLxSceneBuilder::AddVertex (
        unsigned		 index)
{
        LXtPointID		 pnt;

        if (!pv->GoodMesh ())
                return;

        SB_DBG (("SceneBuilder::AddVertex %d\n", index));

        pnt = pv->Point (index);

        pv->Err (  pv->point.Select (pnt)	);
        try {
                pv->pverts.push_back (pv->point.ID ());
        } CATCH_ALL
}

        unsigned int
CLxSceneBuilder::AddPolygon (
        bool			 rev)
{
        LXtPolygonID 		 poly;
        int 			 i, n;
        LXtPointID		*vrts;
        LxResult		 rc;
        LXtID4			 type = pv->ptype;

        if (!pv->GoodMesh ())
                return 0;

        SB_DBG (("SceneBuilder::AddPolygon %d\n", rev));

        n = static_cast<int>(pv->pverts.size ());
        if (!n)
                pv->Err (LXe_INVALIDARG);

        try {
                vrts = new LXtPointID[n];
                for (i = 0; i < n; i++)
                        vrts[i] = pv->pverts[i];

                if(type == LXiPTYP_FACE)
                {
                        if(n == 1)
                        {
                                SB_DBG ("SceneBuilder::Attempting to create incompatible 1 point face polygon. Forcing to OnePoint type.\n");
                                type = LXiPTYP_OPNT;
                        }
                        else if(n == 2)
                        {
                                SB_DBG ("SceneBuilder::Attempting to create incompatible 2 point face polygon. Forcing to Line type.\n");
                                type = LXiPTYP_LINE;
                        }
                }

                rc = pv->poly.New (pv->ptype, vrts, n, rev, &poly);
                delete[] vrts;
                pv->Err (rc);

                pv->polList.push_back (poly);
        } CATCH_ALL

        return static_cast<unsigned int>(pv->polList.size () - 1);
}

        void
CLxSceneBuilder::SetPolyTag (
        unsigned		 index,
        LXtID4			 type,
        const char		*value)
{
        LXtPolygonID		 pol;

        if (!pv->GoodMesh ())
                return;

        SB_DBG (("SceneBuilder::SetPolyTag %d %d %s\n", index, type, value));

        if (!(pol = pv->Polygon (index)))
                return;

        pv->Err (  pv->poly.Select (pol)		);
        pv->Err (  pv->polyTag.Set (type, value)	);
}

        unsigned int
CLxSceneBuilder::AddMap (
        LXtID4			 type,
        const char		*name)
{
        LXtMeshMapID		 mmap;

        if (!pv->GoodMesh ())
                return 0;

        SB_DBG (("SceneBuilder::AddMap %d %s\n", type, name));

        pv->Err (  pv->mmap.New (type, name, &mmap)	);

        try {
                pv->mapList.push_back (mmap);
        } CATCH_ALL

        return static_cast<unsigned int>(pv->mapList.size () - 1);
}

        bool
CLxSceneBuilder::SetMap (
        LXtID4			 type,
        const char		*name)
{
        if (name)
                return LXx_OK (pv->mmap.SelectByName (type, name));

        CFirstMapVisitor	 vis;

        pv->mmap.FilterByType (type);
        pv->mmap.Enum (&vis);
        return pv->mmap.ID () != 0;
}

        void
CLxSceneBuilder::SetPointMap (
        unsigned		 mapIndex,
        float			*vec,
        unsigned		 pntIndex)
{
        LXtMeshMapID		 mmap;
        LXtPointID		 pnt;

        if (!pv->GoodMesh ())
                return;

        SB_DBG (("SceneBuilder::SetPointMap %d %d\n", mapIndex, pntIndex));

        mmap = pv->Map   (mapIndex);
        pnt  = pv->Point (pntIndex);

        pv->Err (  pv->point.Select (pnt)		);
        pv->Err (  pv->point.SetMapValue (mmap, vec)	);
}

        void
CLxSceneBuilder::SetVertexMap (
        unsigned		 mapIndex,
        float			*vec,
        unsigned		 pntIndex,
        unsigned		 polIndex)
{
        LXtMeshMapID		 mmap;
        LXtPointID		 pnt;
        LXtPolygonID		 pol;

        if (!pv->GoodMesh ())
                return;

        SB_DBG (("SceneBuilder::SetVertexMap %d %d %d\n", mapIndex, pntIndex, polIndex));

        mmap = pv->Map     (mapIndex);
        pnt  = pv->Point   (pntIndex);
        pol  = pv->Polygon (polIndex);

        pv->Err (  pv->poly.Select (pol)		);
        pv->Err (  pv->poly.SetMapValue (pnt, mmap, vec));
}

        void
CLxSceneBuilder::SetCoVertMap (
        unsigned		 mapIndex,
        float			*vec,
        unsigned		 pntIndex,
        unsigned		 polIndex)
{
        LXtMeshMapID		 mmap;
        LXtPointID		 pnt;
        LXtPolygonID		 pol;
        float			 test[10];
        LxResult		 rc;
        unsigned		 dim, i;

        if (!pv->GoodMesh ())
                return;

        SB_DBG (("SceneBuilder::SetCoVertMap %d %d %d\n", mapIndex, pntIndex, polIndex));

        mmap = pv->Map     (mapIndex);
        pnt  = pv->Point   (pntIndex);
        pol  = pv->Polygon (polIndex);

        pv->Err (  pv->point.Select (pnt)		);

        rc = pv->point.MapValue (mmap, test);
        if (rc == LXe_FALSE) {
                pv->Err (  pv->point.SetMapValue (mmap, vec)	);
                return;
        }

        pv->Err (rc);
        pv->Err (  pv->mmap.Select (mmap)		);
        pv->Err (  pv->mmap.Dimension (&dim)		);

        for (i = 0; i < dim; i++)
                if (test[i] != vec[i]) {
                        pv->Err (  pv->poly.Select (pol)			);
                        pv->Err (  pv->poly.SetMapValue (pnt, mmap, vec)	);
                        return;
                }
}

        void
CLxSceneBuilder::SetEdgeMap (
        const float		*vec,
        unsigned		 p1Index,
        unsigned		 p2Index)
{
        if (!pv->GoodMesh ())
                return;

        SB_DBG (("SceneBuilder::SetEdgeMap %d %d %d\n", mapIndex, p1Index, p2Index));

        LXtPointID	 pnt1;
        LXtPointID	 pnt2;

        pnt1 = pv->Point (p1Index);
        pnt2 = pv->Point (p2Index);

        if (pv->mesh.GetEdges (pv->edge)) {
                pv->edge.SelectEndpoints (pnt1, pnt2);
                pv->edge.SetMapValue (pv->mmap.ID (), vec);
        }
}

        unsigned
CLxSceneBuilder::AddMeshOp (
        const char		*type)
{
        unsigned int		 sceneIndex = pv->Single (SCENE);
        unsigned int		 index = ~0;
        unsigned int		 targetIndex = ~0;

        if (pv->IsA (LXsITYPE_MESH))
                targetIndex = CurItem ();

        index = AddItem (type);
        if (index != ~0)
        {
                SetLink ("deformTree", sceneIndex, 0, 0);
                if (targetIndex != ~0)
                        SetLink ("deformers", targetIndex);
        }

        return index;
}

        unsigned
CLxSceneBuilder::AddSelOp (
        const char		*type)
{
        unsigned int		 index = ~0;
        unsigned int		 targetIndex = ~0;

        if (pv->IsA (LXsITYPE_MESHOP))
                targetIndex = CurItem ();

        index = AddItem (type);
        if (index != ~0 && targetIndex != ~0)
                SetLink ("selops", targetIndex);

        return index;
}


/*
 * ----------------------------------------------------------------
 * Scene Loader Implementation
 */
#if 0
 #define SL_DBG(x)		 printf x
#else
 #define SL_DBG(x)
#endif

CLxSceneLoader::CLxSceneLoader ()
{
}

CLxSceneLoader::~CLxSceneLoader ()
{
}

        LxResult
CLxSceneLoader::load_Recognize (
        const char		*filename,
        ILxUnknownID		 ldInfo)
{
        CLxFileParser		*par = sl_Parser ();
        CLxUser_SceneService	 svc;

        SL_DBG (("CLxSceneLoader::load_Recognize %s\n", load->filename));

        cp_filename = filename;
        try {
                if (!par->fp_Open (filename))
                        return LXe_FAILED;

                if (par->fp_HasError ())
                        return par->fp_ErrorCode ();

                if (!sl_Recognize ())
                        return LXe_FAILED;

                if (par->fp_HasError ())
                        return par->fp_ErrorCode ();
        }
        catch (LxResult rc) {
                return rc;
        }
        catch (std::bad_alloc &) {
                return LXe_OUTOFMEMORY;
        }

        CLxUser_LoaderInfo		 info (ldInfo);

        ld_target.set (ldInfo);

        info.SetClass (&lx::guid_Scene);
        if (sl_HasOptions ())
                info.SetFlags (LXfLOAD_OPTIONS);

        ld_target.SetRootType (LXsITYPE_MESH);

        SL_DBG (("  Recognized!\n"));
        par->fp_Cleanup ();
        return LXe_OK;
}

        LxResult
CLxSceneLoader::load_LoadObject (
        ILxUnknownID		 ldInfo,
        ILxUnknownID		 monitor,
        ILxUnknownID		 dest)
{
        CLxFileParser		*par = sl_Parser ();
        LxResult		 error, res = LXe_OK;

        try {
                if (!par->fp_Open (cp_filename))
                        throw (LXe_FAILED);

                if (monitor)
                        par->fp_SetMonitor (monitor);

                if (par->fp_HasError ())
                        throw (par->fp_ErrorCode ());

                scene_build.Initialize (dest);

                if (!sl_ParseInit ())
                        throw (LXe_FAILED);

                error = LXe_OK;
                while (sl_Parse (&error) && LXx_OK (error))
                        if (!scene_build.IsGood ())
                                throw (scene_build.ErrorCode ());

                if (LXx_FAIL (error))
                        throw (error);

                if (par->fp_HasError ())
                        throw (par->fp_ErrorCode ());

                if (!sl_ParseDone ())
                        throw (LXe_FAILED);

                error = scene_build.Finalize ();
                if (LXx_FAIL (error))
                        throw (error);
        }
        catch (LxResult rc) {
                res = rc;
        }
        catch (std::bad_alloc &) {
                res = LXe_OUTOFMEMORY;
        }

        scene_build.Cleanup ();
        return res;
}

        void
CLxSceneLoader::load_Cleanup ()
{
        ld_target.clear ();
        scene_build.Cleanup ();
        sl_Parser () -> fp_Cleanup ();
}

        LxResult
CLxSceneLoader::load_SpawnOptions (
        void		       **ppvObj)
{
        sl_SpawnOpt (ppvObj);
        return LXe_OK;
}

        bool
CLxSceneLoader::IsFileAbsolute (const char *fileName) const
{
        return FileIsAbsolute (fileName);
}

        bool
CLxSceneLoader::IsFileAbsolute (const std::string &fileName) const
{
        return IsFileAbsolute (fileName.c_str ());
}

        bool
CLxSceneLoader::MakeFileAbsolute (
        char *absFileName,
        const char *fileName)
{
        /*
         * file_name is the base file name to the scene, whereas fileName
         * is the file name for the referenced asset, such as an image.
         */
        return FileMakeAbsolute (
                absFileName, fileName, sl_Parser ()->file_name);
}

        bool
CLxSceneLoader::MakeFileAbsolute (
        std::string &fileName)
{
        std::string	absFileNameChars;

        /*
         * file_name is the base file name to the scene, whereas fileName
         * is the file name for the referenced asset, such as an image.
         */
        bool result = FileMakeAbsolute (
                absFileNameChars,
                fileName,
                std::string(sl_Parser ()->file_name));

        fileName = absFileNameChars;

        return result;
}

/*
 * ----------------------------------------------------------------
 * Scene Saver Implementation
 */
typedef enum en_ScanMode {
        SM_NONE,
        SM_MESH,
        SM_ITEM,
        SM_LAYER
} ScanMode;

class pv_SceneSaver {
    public:
         pv_SceneSaver (ILxUnknownID, bool);
        ~pv_SceneSaver ();

        bool				 Err      (LxResult) const;
        LxResult			 LastErr  () const;
        void				 Step     (unsigned n = 1);
        bool				 Tally    (unsigned);

        bool				 Test     (ILxUnknownID item);

        bool				 CollectLayers (
                                                CLxUser_Item &,
                                                const char *,
                                                const char * = 0);

        bool				 UpdateMeshAccessors ();

        CLxUser_SceneService		 svc;
        CLxUser_Scene			 scene;
        CLxUser_ChannelRead		 chan;
        CLxUser_ChannelRead		 chanXForm;
        CLxUser_ItemCollection		 icoll;
        CLxUser_Message			 msg;
        CLxUser_Monitor			 mon;
        CLxUser_ItemGraph		 sGraph;
        LXtItemType			 meshType, meshInstType, triSurfType,
                                         rendType, maskType,
                                         tlayType, stilType, tlocType;

        bool				 real;
        unsigned			 steps;
        mutable LxResult		 error;

        unsigned			 curItem, numItems;
        LXtItemType			 curType;
        ScanMode			 scanMode;
        CLxUser_Item			 item;
        std::vector<ILxUnknownID>	 layer;

        /*
         * TriSurf (static mesh) iteration.
         */
        unsigned			 posVectorIndex;
        unsigned			 normVectorIndex;
        unsigned			 texcoordVectorIndex;
        CLxUser_TriangleGroup		 triangleGroup;
        CLxUser_TriangleSurface		 triangleSurface;
        unsigned			 trianglePointIndex;

        CLxUser_StringTag		 itemTag;
        CLxUser_Mesh			 mesh;
        CLxUser_MeshFilter		 meshFilter;
        CLxUser_Point			 point;
        CLxUser_Edge			 edge;
        CLxUser_Polygon			 poly;
        CLxUser_StringTag		 polyTag;
        CLxUser_MeshMap			 map;
};

/*
 * ------	Scene Saver Private
 *
 * The private data for the scene saver is given the scene object. We look up
 * some commonly useful item types and init all the user objects to the scene.
 */
pv_SceneSaver::pv_SceneSaver (
        ILxUnknownID		 obj,
        bool			 subsets)
                :
                real(false)
{
        CLxUser_SceneSubset	 ssub;
        CLxUser_SceneGraph	 gr;

        meshType     = svc.ItemType (LXsITYPE_MESH);
        meshInstType = svc.ItemType (LXsITYPE_MESHINST);
        triSurfType  = svc.ItemType (LXsITYPE_TRISURF);
        rendType     = svc.ItemType (LXsITYPE_POLYRENDER);
        maskType     = svc.ItemType (LXsITYPE_MASK);
        tlayType     = svc.ItemType (LXsITYPE_TEXTURELAYER);
        stilType     = svc.ItemType (LXsITYPE_VIDEOSTILL);
        tlocType     = svc.ItemType (LXsITYPE_TEXTURELOC);

        if (subsets && ssub.set (obj))
        {
                ssub.GetScene (scene);
                ssub.GetCollection (icoll);
        } else
                scene.set (obj);

        if (scene.test () &&
            scene.GetChannels (chan, LXs_ACTIONLAYER_EDIT) &&
            scene.GetChannels (chanXForm, 0.0) &&
            scene.GetGraph (LXsGRAPH_SHADELOC, gr) && sGraph.set (gr) )
        {
                error = LXe_OK;
        } else
                error = LXe_NOACCESS;
}

pv_SceneSaver::~pv_SceneSaver ()
{
}

/*
 * This returns true and sets the internal error state for a genuine error.
 */
        bool
pv_SceneSaver::Err (
        LxResult		 rc) const
{
        if (LXx_OK (rc))
                return false;

        error = rc;
        return true;
}

/*
 * Return the last error result code.
 */
        LxResult
pv_SceneSaver::LastErr  () const
{
        return error;
}

/*
 * The monitor steps are computed in two passes. The first non-real pass just
 * counts the steps, while in the second real pass we step the monitor and
 * check for abort.
 */
        void
pv_SceneSaver::Step (unsigned n)
{
        if (!real)
                steps += n;

        else if (mon.Step (n))
                error = LXe_ABORT;
}

/*
 * Tally() is called for longer iterations that we want to bypass on the first
 * pass. If not real the count is simply added to the tally and we return true,
 * meaning to skip the real iteration. On the real pass we just return false.
 */
        bool
pv_SceneSaver::Tally (
        unsigned		 n)
{
        if (real)
                return false;

        steps += n;
        return true;
}

/*
 * Test() is called to determine if the item is part of the subset. If there
 * is no subset this always returns true.
 */
        bool
pv_SceneSaver::Test (
        ILxUnknownID		 item)
{
        if (icoll.test())
                return (icoll.Test (item) == LXe_TRUE);

        return true;
}

/*
 * This function fills the "layer" array by recursively scanning the shader
 * tree. Mask items that don't match the tag names are skipped.
 *
 * NOTE: this should also deal with other tag types.
 */
        bool
pv_SceneSaver::CollectLayers (
        CLxUser_Item		&root,
        const char		*polyMask,
        const char		*itemMask)
{
        CLxUser_Item		 sub;
        const char		*ptag;
        unsigned		 idx, i, n;

        if (Err (root.SubCount (&n)))
                return false;

        /*
         * Grab the shader tree graph to look up item masks.
         */
        CLxUser_SceneGraph	 sceneGraph;
        scene.GetGraph (LXsGRAPH_SHADELOC, sceneGraph);
        CLxUser_ItemGraph	 itemGraph;
        itemGraph.set (sceneGraph);

        for (i = 0; i < n; i++) {
                if (!root.GetSubItem (i, sub))
                        return false;

                if (!sub.IsA (maskType)) {
                        if (Test (sub))
                                layer.push_back (sub);

                        continue;
                }

                idx = sub.ChannelIndex (LXsICHAN_MASK_PTAG);
                if (Err (chan.String (sub, idx, &ptag)))
                        return false;

                const char *subName;
                if (LXx_OK (sub.UniqueName (&subName))) {
                        std::string subItemName(subName);
                }

                /*
                 * If the shader tree item's polygon tag is empty, that
                 * indicates that we should match all polygon tags,
                 * including empty ones.
                 *
                 * If the shader tree item's polygon tag is not empty,
                 * then we must match the tags by comparison.
                 */
                if (*ptag && (!polyMask || strcmp (ptag, polyMask))) {
                        continue;
                }

                /*
                 * Check if the layer has a matching mask name.
                 */
                bool itemTagMatch(itemMask == NULL);
                unsigned itemCount = itemGraph.Forward (sub);
                CLxUser_Item layerMask;
                const char	*layerName = NULL;
                if (itemCount && itemGraph.Forward (sub, 0, layerMask)) {
                        if (LXx_OK (layerMask.UniqueName (&layerName))) {
                                if (itemMask) {
                                        itemTagMatch = layerName &&
                                                !strcmp (layerName, itemMask);
                                }
                                else {
                                        /*
                                         * Test for an empty layer name,
                                         * or for the empty (all) polytag
                                         * with a NULL (all) item mask).
                                         */
                                        itemTagMatch = (layerName == NULL) ||
                                                ((!strlen (ptag)) && !itemMask);
                                }
                        }
                }
                if (!itemTagMatch) {
                        continue;
                }

                if (!CollectLayers (sub, polyMask, itemMask))
                        return false;
        }
        return true;
}

        bool
pv_SceneSaver::UpdateMeshAccessors ()
{
        return	mesh.GetPoints (point) &&
                mesh.GetEdges (edge) &&
                mesh.GetPolygons (poly) &&
                mesh.GetMaps (map) &&
                polyTag.set (poly);
}

/*
 * ------	Scene Saver
 */
CLxSceneSaver::CLxSceneSaver ()
{
        pv = 0;
}

CLxSceneSaver::~CLxSceneSaver ()
{
        if (pv) {
                delete pv;
                pv = 0;
        }
}

/*
 * Verification -- we call the client's ss_Verify() method. If there's a problem
 * they set the message object to reflect the situation.
 */
        LxResult
CLxSceneSaver::sav_Verify (
        ILxUnknownID		 source,
        ILxUnknownID		 msg)
{
        pv = new pv_SceneSaver (source, ss_DoSubset());

        if (!pv->msg.set (msg))
                return LXe_INVALIDARG;

        ss_Verify ();

        delete pv;
        pv = 0;
        return LXe_OK;
}

        void
CLxSceneSaver::Message (
        const char		*table,
        unsigned		 id)
{
        pv->msg.SetCode    (LXe_INFO);
        pv->msg.SetMessage (table, 0, id);
}

        void
CLxSceneSaver::Message (
        const char		*table,
        const char		*key)
{
        pv->msg.SetCode    (LXe_INFO);
        pv->msg.SetMessage (table, key, 0);
}

        void
CLxSceneSaver::MessageArg (
        unsigned		 arg,
        int			 value)
{
        pv->msg.SetArg (arg, value);
}

        void
CLxSceneSaver::MessageArg (
        unsigned		 arg,
        double			 value)
{
        pv->msg.SetArg (arg, value);
}

        void
CLxSceneSaver::MessageArg (
        unsigned		 arg,
        const char		*value)
{
        pv->msg.SetArg (arg, value);
}

/*
 * Saving -- requires two passes. The first call to ss_Save() just counts
 * steps without doing anything. The second call performs the real save,
 * hopefully using the same number of steps.
 */
        LxResult
CLxSceneSaver::sav_Save (
        ILxUnknownID		 source,
        const char		*filename,
        ILxUnknownID		 mon)
{
        CLxFileFormat		*ff = ss_Format ();
        LxResult		 rc;

        pv = new pv_SceneSaver (source, ss_DoSubset());
        if (!pv)
                return LXe_FAILED;

        while (1) {
                if (!ff->ff_Open (filename)) {
                        rc = LXe_FAILED;
                        break;
                }

                if (ff->ff_HasError ()) {
                        rc = LXe_FAILED;
                        break;
                }

                pv->steps = 0;
                if (mon) {
                        ff->ff_Enable (0);
                        pv->real = false;
                        rc = ss_Save ();
                        if (LXx_FAIL (rc))
                                break;

                        pv->mon.set (mon);
                        pv->mon.Init (pv->steps);
                }

                ff->ff_Enable (1);
                pv->real = true;
                rc = ss_Save ();
                if (LXx_FAIL (rc))
                        break;

                if (LXx_FAIL (pv->error)) {
                        rc = pv->error;
                        break;
                }

                if (ff->ff_HasError ())
                        rc = LXe_FAILED;

                break;
        }

        ff->ff_Cleanup ();
        delete pv;
        pv = 0;
        return rc;
}

/*
 * ------	Scene Attributes
 * These methods get at basic scene and saver attributes.
 */
        ILxUnknownID
CLxSceneSaver::SceneObject ()
{
        return pv->scene;
}

        bool
CLxSceneSaver::ReallySaving ()
{
        return pv->real;
}

        bool
CLxSceneSaver::TestItem (
        ILxUnknownID		 item)
{
        return pv->Test (item);
}

        bool
CLxSceneSaver::IsSceneSaved ()
{
        const char		*value;
        LxResult		 rc;

        rc = pv->scene.Filename (&value);
        if (rc == LXe_FALSE)
                return 0;

        return 1;
}

        const char *
CLxSceneSaver::ScenePath ()
{
        const char		*value;
        LxResult		 rc;

        rc = pv->scene.Filename (&value);
        if (rc == LXe_FALSE)
                return 0;

        return value;
}

        const char *
CLxSceneSaver::SceneName (
        unsigned		 flags)
{
        const char		*value = 0;

        pv->scene.FriendlyFilename (flags, &value);
        return value;
}

/*
 * ------	Item Iteration
 *
 * Items are walked by using the scene saver as an iterator. This method
 * resets the iteration and sets an optional item type.
 */
        void
CLxSceneSaver::StartScan (
        const char		*typeName)
{
        pv->scanMode = SM_NONE;
        if (typeName)
                pv->curType = pv->svc.ItemType (typeName);
        else
                pv->curType = LXiTYPE_ANY;
}

/*
 * NextItem() sets the current item to the next item of the desired type.
 * On the first call we get the total number of items.
 */
        bool
CLxSceneSaver::NextItem ()
{
        CLxUser_Item		 item;

        //pv->Step ();

        if (pv->scanMode == SM_ITEM)
                pv->curItem++;
        else {
                pv->scanMode = SM_ITEM;
                pv->numItems = pv->scene.NItems (pv->curType);
                pv->curItem  = 0;
        }

        while (1)
        {
                if (pv->curItem >= pv->numItems)
                        return false;

                if (pv->Err (pv->scene.ItemByIndex (pv->curType, pv->curItem, item)))
                        return false;

                if (pv->Test (item))
                        break;

                pv->curItem++;
        }

        // Fixes #467058 [PUBLIC] FBX exporter doesn't work correctly with this scene file.
        // Being unable to set an item doesn't mean we can't use it to get the hirearchy
        SetItem (item);
        return true;
}

/*
 * NextMesh() walks through mesh items only.
 */
        bool
CLxSceneSaver::NextMesh ()
{
        CLxUser_Item		 item;

        //pv->Step ();

        if (pv->scanMode == SM_MESH)
                pv->curItem++;
        else {
                pv->scanMode = SM_MESH;
                pv->numItems = pv->scene.NItems (pv->meshType);
                pv->curItem  = 0;
        }

        while (1)
        {
                if (pv->curItem >= pv->numItems)
                        return false;

                if (pv->Err (pv->scene.ItemByIndex (pv->meshType, pv->curItem, item)))
                        return false;

                if (pv->Test (item))
                        break;

                pv->curItem++;
        }

        // Fixes #467058 [PUBLIC] FBX exporter doesn't work correctly with this scene file.
        // Being unable to set an item doesn't mean we can't use it to get the hirearchy
        SetItem (item);
        return true;
}

/*
 * NextSelectedMesh() walks through selected mesh items only.
 */
        bool
CLxSceneSaver::NextSelectedMesh ()
{
        bool			 ok = false;

        //pv->Step ();

        CLxUser_SelectionService	 selSvc;
        LXtID4				 selItemType;

        selItemType = selSvc.LookupType (LXsSELTYP_ITEM);

        if (pv->scanMode == SM_MESH)
                pv->curItem++;
        else {
                pv->scanMode = SM_MESH;
                pv->numItems = selSvc.Count (selItemType);
                pv->curItem  = 0;
        }

        if (pv->curItem >= pv->numItems)
                return false;

        void *itemPacket = selSvc.ByIndex (selItemType, pv->curItem);
        if (!itemPacket)
                return false;

        CLxUser_ItemPacketTranslation	 itemPktTrans;
        CLxUser_Item			 itemObj;

        itemPktTrans.autoInit ();

        if (itemPktTrans.GetItem (itemPacket, itemObj) && SetItem (itemObj))
                ok = pv->item.IsA (pv->meshType);
        else
                pv->Err (LXe_FAILED);

        return ok;
}

        bool
CLxSceneSaver::GetMesh(
        CLxUser_Mesh		&mesh)
{
        return mesh.set (pv->mesh);
}

        bool
CLxSceneSaver::GetPolygon(
        CLxUser_Polygon		&poly)
{
        return poly.set (pv->poly);
}

/*
 * Layers in the shader tree are selected by mask strings. The initialization
 * method scans the tree recursively and finds all layers that match the masks.
 * The Nextlayer() method steps through that list.
 */
        bool
CLxSceneSaver::ScanMask (
        const char		*polyMask,
        const char		*itemMask)
{
        CLxUser_Item		 rend;

        pv->layer.clear ();
        pv->scanMode = SM_NONE;

        if (!pv->scene.GetItem (pv->rendType, rend))
                return false;

        if (!pv->CollectLayers (rend, polyMask, itemMask))
                return false;

        pv->scanMode = SM_LAYER;
        pv->curItem  = 0;
        return true;
}

        bool
CLxSceneSaver::NextLayer ()
{
        LXtObjectID		 obj;

//	pv->Step ();

        if (pv->scanMode != SM_LAYER && !ScanMask (0))
                return false;

        if (pv->curItem >= pv->layer.size ())
                return false;

        obj = pv->layer[pv->curItem++];
        return pv->item.set (obj);
}

/*
 * The user can remember and reset the current item. Setting the current item
 * to a mesh sets up the query state for the mesh channel.
 */
        bool
CLxSceneSaver::SetItem (
        ILxUnknownID		 obj)
{
        bool	isItemSet(false);
        bool	haveMesh(false);

        if (pv->item.set (obj)) {
                pv->itemTag.set (pv->item);

                /*
                 * Check for a trisurf.
                 */
                if (pv->item.IsA (pv->triSurfType)) {
                        unsigned surfChanIndex = ChanIndex (LXsICHAN_TRISURF_SURF);
                        isItemSet = ChanObject (surfChanIndex, pv->triangleGroup);
                }

                /*
                 * Check for a mesh instance.
                 */
                else if (pv->item.IsA (pv->meshInstType)) {
                        /*
                         * Find the mesh that is referenced by the instance.
                         */
                        CLxUser_SceneService	 service;
                        CLxUser_Item		 srcMeshItem;
                        ILxItem1ID		 iMesh;
                        if (LXx_OK (service.GetMeshInstSourceItem (
                                (ILxUnknownID)pv->item, (void**)&iMesh))) {
                                srcMeshItem.take (iMesh);
                                unsigned index;

                                if (LXe_TRUE == iMesh[0]->TestType (iMesh, LXsITYPE_TRISURF))
                                        isItemSet = true;
                                else if (LXx_OK (iMesh[0]->ChannelIndex (
                                        iMesh, LXsICHAN_MESH_MESH, &index))) {
                                        LXtObjectID	meshObj;
                                        if (LXx_OK (
                                                pv->chan.m_loc[0]->ValueObj (
                                                        pv->chan, iMesh, index,
                                                        (void**)&meshObj))) {
                                                isItemSet = haveMesh =
                                                        pv->mesh.take (meshObj);
                                        }
                                }
                        }
                }
                else if (!pv->item.IsA (pv->meshType))
                        isItemSet = true;
                else if (ChanObject (LXsICHAN_MESH_MESH, pv->mesh)) {
                        isItemSet = true;
                        haveMesh = true;
                }

                if (isItemSet && haveMesh) {
                        isItemSet = pv->UpdateMeshAccessors ();
                }
        }

        return isItemSet;
}

/*
 * For the current item, switch to using the deformed mesh at a specified time.
 */
        bool
CLxSceneSaver::SetMeshTime (
        double			 frameTime)
{
        if (! pv->item.test ())			// current item must be set
                return false;

        if (pv->item.IsA (pv->triSurfType))	// does not apply to static meshes
                return false;

        int			 index;
        CLxUser_ChannelRead	 fChan;

        pv->scene.GetChannels (fChan, frameTime);

        /*
         * Check for a mesh instance.
         */
        if (pv->item.IsA (pv->meshInstType)) {
                /*
                 * Find the mesh that is referenced by the instance.
                 */
                CLxUser_SceneService	 service;
                CLxUser_Item		 srcMeshItem;
                ILxItem1ID		 iMesh;
                unsigned		 uindex;

                if (LXx_FAIL (service.GetMeshInstSourceItem (pv->item, (void**)&iMesh)) ||
                        false == srcMeshItem.take (iMesh))
                        return false;

                // Handle instances with allowed deformation on
                if (ChanBool (LXsICHAN_MESHINST_ALLOWDEFORM))
                {
                        if (0 > (index = pv->item.ChannelIndex (LXsICHAN_MESH_MESH)) ||
                                false == fChan.Object (pv->item, index, pv->meshFilter))
                                return false;
                }
                else
                {
                        if (LXe_TRUE == iMesh[0]->TestType (iMesh, LXsITYPE_TRISURF) ||
                                LXx_FAIL (iMesh[0]->ChannelIndex (iMesh, LXsICHAN_MESH_MESH, &uindex)) ||
                                false == fChan.Object (srcMeshItem, uindex, pv->meshFilter))
                                return false;
                }
        }

        else if (!pv->item.IsA (pv->meshType))	// current item must be a mesh
                return false;

        else if (0 > (index = pv->item.ChannelIndex (LXsICHAN_MESH_MESH)) ||
                 false == fChan.Object (pv->item, index, pv->meshFilter))
                        return false;

        return	pv->meshFilter.GetMesh (pv->mesh) && 
                pv->UpdateMeshAccessors ();
}

        bool
CLxSceneSaver::GetItem (
        CLxUser_Item		&item) const
{
        item.clear ();
        if (pv->item.test ())
                item.set (pv->item);

        return item.test ();
}


/*
 * ------	Item Attributes
 *
 * These methods read out attributes of the current item.
 */
        const char *
CLxSceneSaver::ItemName () const
{
        const char		*name;

        if (pv->Err (pv->item.UniqueName (&name)))
                return 0;

        return name;
}

        std::string
CLxSceneSaver::ItemIdentity () const
{
        return pv->item.GetIdentity ();
}

        const char *
CLxSceneSaver::ItemType () const
{
        const char		*name;

        if (pv->Err (pv->svc.ItemTypeName (pv->item.Type (), &name)))
                return 0;

        return name;
}

        LXtItemType
CLxSceneSaver::GetItemType () const
{
        return pv->item.Type ();
}

        LXtItemType
CLxSceneSaver::ItemType (
        const char		*typeName) const
{
        LXtItemType		 type(LXiTYPE_NONE);

        pv->Err (pv->svc.ItemTypeLookup (typeName, &type));

        return type;
}

        bool
CLxSceneSaver::ItemIsA (
        const char		*typeName) const
{
        LXtItemType		 type;

        if (pv->Err (pv->svc.ItemTypeLookup (typeName, &type)))
                return false;

        return pv->item.IsA (type);
}

        const char *
CLxSceneSaver::ItemTag (
        LXtID4			 tag)
{
        const char		*value;

        if (LXx_OK (pv->itemTag.Get (tag, &value)))
                return value;

        return 0;
}

        unsigned
CLxSceneSaver::ItemTagCount ()
{
        unsigned		 count;

        pv->Err (pv->itemTag.Count (&count));

        return count;
}

        const char *
CLxSceneSaver::ItemTagByIndex (unsigned index, LXtID4 *tag)
{
        const char		*value;

        if (LXx_OK (pv->itemTag.ByIndex (index, tag, &value)))
                return value;

        return 0;
}

        bool
CLxSceneSaver::ItemVisible () const
{
        bool	visible = true;

        CLxUser_Locator locator;
        if (locator.set (pv->item)) {
                visible = (locator.Visible (pv->chanXForm) == LXe_TRUE);
        }

        return visible;
}

/*
 * ------	Locator Attributes
 *
 * For locator items we can get the computed world transform or the transform
 * items.
 */
        bool
CLxSceneSaver::WorldXform (
        LXtMatrix		 xfrm,
        LXtVector		 offset)
{
        bool	result = false;
        CLxUser_Locator locator;
        if (locator.set (pv->item)) {
                if (!pv->Err (locator.WorldTransform (pv->chanXForm, xfrm, offset))) {
                        result = true;
                }
        }
        else {
                pv->Err (LXe_NOINTERFACE);
        }

        return result;
}

        bool
CLxSceneSaver::HasXformItem (LXtTransformType type) const
{
        LXtObjectID		 obj;
        bool			 hasXform = false;

        CLxUser_Locator locator;
        if (locator.set (pv->item)) {
                LxResult result = locator.GetTransformItem (type, &obj);
                hasXform = LXx_OK (result);
                if (hasXform) {
                        lx::ObjRelease (obj);
                }
        }

        return hasXform;
        
}

        bool
CLxSceneSaver::XformItem (
        LXtTransformType	 type)
{
        LXtObjectID		 obj;
        bool			 hasXform = false;

        CLxUser_Locator locator;
        if (locator.set (pv->item)) {
                LxResult result = locator.GetTransformItem (type, &obj);
                hasXform = LXx_OK (result);
                if (hasXform) {
                        hasXform = pv->item.take (obj);
                }
        }

        return hasXform;
}


/*
 * ------	Texture Attributes
 *
 * For texture layer items these methods provide easier access to some of
 * their attributes.
 */
        const char *
CLxSceneSaver::LayerEffect ()
{
        return ChanString (LXsICHAN_TEXTURELAYER_EFFECT);
}

        double
CLxSceneSaver::SpecExponent ()
{
        double			 rough;

        rough = ChanFloat (LXsICHAN_ADVANCEDMATERIAL_ROUGH);
        return pow (2.0, (1.0 - rough) * 10.0 + 2.0);
}

/*
 * These two methods set the current item to the image map or locator for a
 * texture layer, if any.
 */
        bool
CLxSceneSaver::TxtrImage ()
{
        CLxUser_Item		 sub;
        int			 i, n;

        if (!pv->item.IsA (pv->tlayType))
                return false;

        n = pv->sGraph.Forward (pv->item);
        for (i = 0; i < n; i++) {
                pv->sGraph.Forward (pv->item, i, sub);
                if (sub.IsA (pv->stilType)) {
                        pv->item.set (sub);
                        return true;
                }
        }

        return false;
}

        bool
CLxSceneSaver::TxtrLocator ()
{
        CLxUser_Item		 sub;
        int			 i, n;

        if (!pv->item.IsA (pv->tlayType))
                return false;

        n = pv->sGraph.Forward (pv->item);
        for (i = 0; i < n; i++) {
                pv->sGraph.Forward (pv->item, i, sub);
                if (sub.IsA (pv->tlocType)) {
                        pv->item.set (sub);
                        return true;
                }
        }

        return false;
}


/*
 * ------	Channel Accessors
 *
 * These methods get values for channels by index or by name.
 */
        bool
CLxSceneSaver::ChanBool (
        unsigned		 index) const
{
        int			 value = 0;

        pv->Err (pv->chan.Integer (pv->item, index, &value));
        return value ? true : false;
}

        int
CLxSceneSaver::ChanInt (
        unsigned		 index) const
{
        int			 value = 0;

        pv->Err (pv->chan.Integer (pv->item, index, &value));
        return value;
}

        double
CLxSceneSaver::ChanFloat (
        unsigned		 index) const
{
        double			 value = 0.0;

        pv->Err (pv->chan.Double (pv->item, index, &value));
        return value;
}

        const char *
CLxSceneSaver::ChanString (
        unsigned		 index) const
{
        const char		*value = 0;

        pv->Err (pv->chan.String (pv->item, index, &value));
        return value;
}

        bool
CLxSceneSaver::ChanObject (
        unsigned		 index,
        CLxLocalizedObject	&loc) const
{
        return pv->chan.Object (pv->item, index, loc);
}

        bool
CLxSceneSaver::ChanEnvelope (
        unsigned		 index,
        CLxUser_Envelope	&env) const
{
        return pv->chan.GetEnv (pv->item, index, env);
}

        bool
CLxSceneSaver::ChanIsAnimated (
        unsigned		 index) const
{
        // we need to use the time-based channel reader
        return 0 != pv->chanXForm.IsAnimated (pv->item, index);
}

        unsigned
CLxSceneSaver::ChanIndex (
        const char		*channel) const
{
        unsigned		 index;

        if (pv->Err (pv->item.ChannelLookup (channel, &index)))
                return ~0;

        return index;
}

        bool
CLxSceneSaver::ChanBool (
        const char		*channel) const
{
        unsigned		 index;

        if (pv->Err (pv->item.ChannelLookup (channel, &index)))
                return 0;

        return ChanBool (index);
}

        int
CLxSceneSaver::ChanInt (
        const char		*channel) const
{
        unsigned		 index;

        if (pv->Err (pv->item.ChannelLookup (channel, &index)))
                return 0;

        return ChanInt (index);
}

        double
CLxSceneSaver::ChanFloat (
        const char		*channel) const
{
        unsigned		 index;

        if (pv->Err (pv->item.ChannelLookup (channel, &index)))
                return 0.0;

        return ChanFloat (index);
}

        void
CLxSceneSaver::ChanColor (
        const char		*channel,
        LXtVector		 vec) const
{
        using namespace std;

        LxResult		 resultR, resultG, resultB;
        unsigned		 indexR, indexG, indexB;

        const char* CHANNEL_R = ".R";
        const char* CHANNEL_G = ".G";
        const char* CHANNEL_B = ".B";

        resultR = pv->item.ChannelLookup (
                string(string(channel) + string(CHANNEL_R)).c_str (), &indexR);
        resultG = pv->item.ChannelLookup (
                string(string(channel) + string(CHANNEL_G)).c_str (), &indexG);
        resultB = pv->item.ChannelLookup (
                string(string(channel) + string(CHANNEL_B)).c_str (), &indexB);

        if (pv->Err (resultR) || pv->Err (resultG) || pv->Err (resultB)) {
                vec[0] = 0.0; vec[1] = 0.0; vec[2] = 0.0;
        }
        else {
                vec[0] = ChanFloat (indexR);
                vec[1] = ChanFloat (indexG);
                vec[2] = ChanFloat (indexB);
        }
}

        void
CLxSceneSaver::ChanXform (
        const char		*channel,
        LXtVector		 vec) const
{
        using namespace std;

        LxResult		 resultX, resultY, resultZ;
        unsigned		 indexX, indexY, indexZ;

        const char* CHANNEL_X = ".X";
        const char* CHANNEL_Y = ".Y";
        const char* CHANNEL_Z = ".Z";

        resultX = pv->item.ChannelLookup (
                string(string(channel) + string(CHANNEL_X)).c_str (), &indexX);
        resultY = pv->item.ChannelLookup (
                string(string(channel) + string(CHANNEL_Y)).c_str (), &indexY);
        resultZ = pv->item.ChannelLookup (
                string(string(channel) + string(CHANNEL_Z)).c_str (), &indexZ);

        if (pv->Err (resultX) || pv->Err (resultY) || pv->Err (resultZ)) {
                vec[0] = 0.0; vec[1] = 0.0; vec[2] = 0.0;
        }
        else {
                vec[0] = ChanFloat (indexX);
                vec[1] = ChanFloat (indexY);
                vec[2] = ChanFloat (indexZ);
        }
}

        const char *
CLxSceneSaver::ChanString (
        const char		*channel) const
{
        unsigned		 index;

        if (pv->Err (pv->item.ChannelLookup (channel, &index)))
                return 0;

        return ChanString (index);
}

        void
CLxSceneSaver::ChanIntEncoded (unsigned channelIndex, char *buf, int bufLen) const
{
        /*
         * Get the raw channel value as an integer.
         */
        int channelValue = ChanInt (channelIndex);

        /*
         * Ask the value service to convert the raw channel value
         * into a symbolic text string.
         */
        CLxUser_ValueService	valueSvc;
        const LXtTextValueHint *hints = NULL;
        pv->item.ChannelIntHint (channelIndex, &hints);
        buf[0] = 0;
        pv->Err (valueSvc.TextHintEncode (
                channelValue, hints, buf, bufLen));
}

        void
CLxSceneSaver::ChanIntEncoded (const char *channel, char *buf, int bufLen) const
{
        unsigned		 index;

        if (pv->Err (pv->item.ChannelLookup (channel, &index)))
                return;

        ChanIntEncoded (index, buf, bufLen);
}

        bool
CLxSceneSaver::ChanObject (
        const char		*channel,
        CLxLocalizedObject	&loc) const
{
        unsigned		 index;

        if (pv->Err (pv->item.ChannelLookup (channel, &index)))
                return 0;

        return ChanObject (index, loc);
}

        bool
CLxSceneSaver::ChanEnvelope (
        const char		*channel,
        CLxUser_Envelope	&env) const
{
        unsigned		 index;

        if (pv->Err (pv->item.ChannelLookup (channel, &index)))
                return 0;

        return ChanEnvelope (index, env);
}

        bool
CLxSceneSaver::ChanIsAnimated (
        const char		*channel) const
{
        unsigned		 index;

        if (pv->Err (pv->item.ChannelLookup (channel, &index)))
                return 0;

        return ChanIsAnimated (index);
}

        bool
CLxSceneSaver::IsFileAbsolute (const char *fileName) const
{
        return FileIsAbsolute (fileName);
}

        bool
CLxSceneSaver::IsFileAbsolute (const std::string &fileName) const
{
        return IsFileAbsolute (fileName.c_str ());
}

        bool
CLxSceneSaver::MakeFileRelative (
        char		*relName,
        const char	*fileName)
{
        bool	madeRelative(false);

        const char *sceneFileName = ss_Format ()->file_name;
        strcpy (relName, fileName);

        char			*abs, *con, *rel;
        char			*out;
        size_t			 len, len1;

        len1 = strlen (sceneFileName);
        len  = strlen (fileName);
        len  = (len > len1 ? len : len1) + 20;

        abs = new char [len * 3];
        con = abs + len;
        rel = con + len;

        /*
         * Make absolute.
         */
        if (!FileIsAbsolute (relName)) {
                FileMakeAbsolute (abs, relName, sceneFileName);
        }
        else {
                strcpy (abs, relName);
        }
        out = abs;

        /*
         * Quasi-loop which breaks out at any point with a valid local filename.
         */
        // Try to see if the scene is in the same directory as the image first
        strcpy (con, sceneFileName);

        while (true) {
                /*
                 * Relative filename.  Try getting a path relative to the scene
                 * directory, and if that fails the parent of the scene directory.
                 */
                if (FileMakeRelative (rel, relName, con)) {
                        out = rel;
                        madeRelative = true;
                        break;
                }

                FileParseName (con, NULL, rel);
                strcpy (con, rel);
                if (FileMakeRelative (rel, relName, con)) {
                        out = rel;
                        madeRelative = true;
                        break;
                }

                FileParseName (con, NULL, rel);

                break;
        }

        NFileToLocal (relName, out);

        delete [] abs;

        return madeRelative;
}

        bool
CLxSceneSaver::MakeFileRelative (
        std::string &fileName)
{
        bool	madeRelative (false);

        std::string sceneFileName(ss_Format ()->file_name);
        std::string abs, out, con, rel;

        /*
        * Make absolute.
        */
        if (!FileIsAbsolute (fileName.c_str()))
        {
                FileMakeAbsolute (abs, fileName, sceneFileName);
        }
        else
        {
                abs.append (fileName);
        }
        out = abs;

        /*
        * Relative filename.  Try getting a path relative to the scene
        * directory.
        */
        if (FileMakeRelative (rel, fileName, sceneFileName))
        {
                out = rel;
                madeRelative = true;
        }

        NFileToLocal (fileName, out);

        return madeRelative;
}

        bool
CLxSceneSaver::MakeFileAbsolute (
        char *absFileName,
        const char *fileName)
{
        /*
         * file_name is the base file name to the scene, whereas fileName
         * is the file name for the referenced asset, such as an image.
         */
        return FileMakeAbsolute (absFileName, fileName, ss_Format ()->file_name);
}

        bool
CLxSceneSaver::MakeFileAbsolute (
        std::string &fileName)
{
        char	absFileNameChars[1024];

        /*
         * file_name is the base file name to the scene, whereas fileName
         * is the file name for the referenced asset, such as an image.
         */
        bool result = FileMakeAbsolute (
                absFileNameChars,
                fileName.c_str (),
                ss_Format ()->file_name);

        fileName = std::string(absFileNameChars);

        return result;
}

/*
 * ------	Mesh Attributes
 *
 * These methods read out parameters of the current mesh.
 */
        void
CLxSceneSaver::MeshBounds (
        LXtBBox			&box)
{
        pv->Err (pv->mesh.BoundingBox (LXiMARK_ANY, &box));
}

        bool
CLxSceneSaver::SetMap (
        LXtID4			 type,
        const char		*name)
{
        if (name)
                return LXx_OK (pv->map.SelectByName (type, name));

        CFirstMapVisitor	 vis;

        pv->map.FilterByType (type);
        pv->map.Enum (&vis);
        return pv->map.ID () != 0;
}

        bool
CLxSceneSaver::SetSelMap (
        LXtID4			 type)
{
        CLxUser_SelectionService svc;
        CLxUser_VMapPacketTranslation trans;
        LXtID4			 selType, mapType;
        const char		*name;
        void			*pkt;

        selType = svc.LookupType (LXsSELTYP_VERTEXMAP);
        trans.autoInit ();

        int mapCount = svc.Count (selType);
        for (int mapIndex = mapCount - 1; mapIndex >= 0; mapIndex--) {
                pkt = svc.ByIndex (selType, mapIndex);
                if (!pkt)
                        continue;

                trans.Type (pkt, &mapType);
                if (mapType == type) {
                        trans.Name (pkt, &name);
                        return SetMap (mapType, name);
                }
        }

        return false;
}

/*
 * Point Enumeration
 *
 * Element enumerators just tally the count of elements on the fake pass
 * to get the monitor set right without doing any work.  The visitor class
 * for each case just acts as an encapsulation of data and callback.  The
 * client's ss_Point() method is called to read the state of the current
 * point.  The client can also remember specific points and set the query
 * state back to any point.
 */
        unsigned
CLxSceneSaver::PointCount ()
{
        unsigned count = 0;

        if (pv->item.IsA (pv->meshType) || pv->item.IsA (pv->meshInstType)) {
                count = pv->mesh.NPoints ();
        }
        else if (pv->item.IsA (pv->triSurfType)) {
                unsigned	triSurfIndex(0);
                bool		nextTriSurf = true;
                do {
                        unsigned vrtCount;
                        unsigned triCount;
                        nextTriSurf = pv->triangleGroup.GetSurf (
                                triSurfIndex++, pv->triangleSurface);
                        if (nextTriSurf) {
                                pv->triangleSurface.GetSize (
                                        &vrtCount, &triCount);
                                count += vrtCount;
                        }
                        else {
                                break;
                        }
                } while (nextTriSurf);
        }

        return count;
}

class CPointVisitor : public CLxImpl_AbstractVisitor {
    public:
        CLxSceneSaver		*ss;
        LxResult		 Evaluate ()
        {
                ss->pv->Step ();
                ss->ss_Point ();
                return LXe_OK;
        }
};

        static LxResult
TriangleSurfaceVectorIndex (
        CLxUser_TriangleSurface &triangleSurface,
        LXtID4			 vectorType,
        unsigned		&vectorIndex)
{
        LxResult	 result(LXe_OUTOFBOUNDS);
        const char	*vectorName;
        unsigned	 stride;
        LXtID4		 testVectorType;

        vectorIndex = 0;
        while (LXx_OK (triangleSurface.VectorInfo (
                vectorIndex, &testVectorType,
                &vectorName, &stride))) {
                if (testVectorType == vectorType) {
                        result = LXe_OK;
                        break;
                }
                else {
                        ++vectorIndex;
                }
        }
        return result;
}

        void
CLxSceneSaver::WritePoints ()
{
        CPointVisitor		 vis;

        if (pv->Tally (PointCount ()))
                return;

        vis.ss = this;
        if (pv->item.IsA (pv->meshType) || pv->item.IsA (pv->meshInstType)) {
                pv->point.Enum (&vis);
        }
        else if (pv->item.IsA (pv->triSurfType)) {
                unsigned	triSurfIndex(0);
                bool		nextTriSurf = true;
                do {
                        unsigned vrtCount;
                        unsigned triCount;
                        nextTriSurf = pv->triangleGroup.GetSurf (
                                triSurfIndex++, pv->triangleSurface);
                        if (nextTriSurf) {
                                pv->triangleSurface.GetSize (
                                        &vrtCount, &triCount);
                                if (LXx_OK (TriangleSurfaceVectorIndex (
                                        pv->triangleSurface,
                                        LXi_VMAP_OBJECTPOS,
                                        pv->posVectorIndex))) {
                                //	float *points = pv->triangleSurface.Vector (
                                //		pv->posVectorIndex);
                                        for (pv->trianglePointIndex = 0;
                                             pv->trianglePointIndex < vrtCount;
                                             ++pv->trianglePointIndex) {
                                                     vis.Evaluate ();
                                        }
                                }
                        }
                        else {
                                break;
                        }
                } while (nextTriSurf);
        }
}

        void
CLxSceneSaver::PntSet (
        LXtPointID		 pnt)
{
        pv->Err (pv->point.Select (pnt));
}

        LXtPointID
CLxSceneSaver::PntID ()
{
        return pv->point.ID ();
}

        void
CLxSceneSaver::PntPosition (
        LXtFVector		 vec)
{
        if (pv->item.IsA (pv->meshType) || pv->item.IsA (pv->meshInstType)) {
                pv->point.Pos (vec);
        }
        else if (pv->item.IsA (pv->triSurfType)) {
                unsigned vrtCount;
                unsigned triCount;
                pv->triangleSurface.GetSize (&vrtCount, &triCount);
                float *points = pv->triangleSurface.Vector (pv->posVectorIndex);
                if (pv->trianglePointIndex < vrtCount) {
                        unsigned pointIndex = pv->trianglePointIndex * 3;
                        vec[0] = points[pointIndex];
                        vec[1] = points[pointIndex + 1];
                        vec[2] = points[pointIndex + 2];
                }
        }
}

        void
CLxSceneSaver::PntPosition (
        LXtVector		 vec)
{
        if (pv->item.IsA (pv->meshType) || pv->item.IsA (pv->meshInstType)) {
                LXtFVector	 fv;
                pv->point.Pos (fv);
                vec[0] = fv[0];
                vec[1] = fv[1];
                vec[2] = fv[2];
        }
        else if (pv->item.IsA (pv->triSurfType)) {
                unsigned vrtCount;
                unsigned triCount;
                pv->triangleSurface.GetSize (&vrtCount, &triCount);
                float *points = pv->triangleSurface.Vector (pv->posVectorIndex);
                if (pv->trianglePointIndex < vrtCount) {
                        unsigned pointIndex = pv->trianglePointIndex * 3;
                        vec[0] = points[pointIndex];
                        vec[1] = points[pointIndex + 1];
                        vec[2] = points[pointIndex + 2];
                }
        }
}

        bool
CLxSceneSaver::PntNormal (
        LXtVector		 norm,
        LXtPolygonID		 pol)
{
        return LXx_OK (pv->point.Normal (pol, norm));
}

        bool
CLxSceneSaver::PntMapValue (
        float			*vec)
{
        LxResult result = pv->point.MapEvaluate (pv->map.ID (), vec);
        return (LXx_OK (result) && (result != LXe_FALSE));
}

/*
 * Edge Enumeration
 *
 * Element enumerators just tally the count of elements on the fake pass
 * to get the monitor set right without doing any work.  The visitor class
 * for each case just acts as an encapsulation of data and callback.  The
 * client's ss_Edge() method is called to read the state of the current
 * edge.  The client can also remember specific edges and set the query
 * state back to any edge.
 */
        unsigned
CLxSceneSaver::EdgeCount ()
{
        unsigned count = 0;

        if (pv->item.IsA (pv->meshType) || pv->item.IsA (pv->meshInstType)) {
                count = pv->mesh.NEdges ();
        }

        return count;
}

class CEdgeVisitor : public CLxImpl_AbstractVisitor {
    public:
        CLxSceneSaver		*ss;
        LxResult		 Evaluate ()
        {
                ss->pv->Step ();
                ss->ss_Edge ();
                return LXe_OK;
        }
};

        void
CLxSceneSaver::WriteEdges ()
{
        CEdgeVisitor		 vis;

        if (pv->Tally (EdgeCount ()))
                return;

        vis.ss = this;
        if (pv->item.IsA (pv->meshType) || pv->item.IsA (pv->meshInstType)) {
                pv->edge.Enum (&vis);
        }
}

        LXtEdgeID
CLxSceneSaver::EdgeID ()
{
        return pv->edge.ID ();
}

        bool
CLxSceneSaver::EdgeEndPoints (LXtPointID *point1, LXtPointID *point2)
{
        LxResult result = pv->edge.Endpoints (point1, point2);
        return (LXx_OK (result) && (result != LXe_FALSE));
}

        bool
CLxSceneSaver::EdgeMapValue (float *vec)
{
        LxResult result = pv->edge.MapEvaluate (pv->map.ID (), vec);
        return (LXx_OK (result) && (result != LXe_FALSE));
}

/*
 * Polygon Enumeration
 */
        unsigned
CLxSceneSaver::PolygonCount ()
{
        unsigned count = 0;

        if (pv->item.IsA(pv->meshType) || pv->item.IsA(pv->meshInstType)) {
                count = pv->mesh.NPolygons();
        }

        return count;
}

/*
 * Optional multi-map to visit all of the polygons for a given material in a
 * single run. (All of the polygons associated with a material are not
 * necessarily contiguous when polygons are visited.
 */
typedef const char *PolyMaterialTag;
typedef std::multimap<PolyMaterialTag, LXtPolygonID> MeshMaterialMap;

class CPolyVisitor : public CLxImpl_AbstractVisitor {
    public:
        CLxSceneSaver		*ss;
        LXtID4			 type;

        CPolyVisitor ()
                :
                unifyByPolyMatTags(false),
                meshMaterialMap(nullMap)
        {
        }

        CPolyVisitor (MeshMaterialMap &map)
                :
                unifyByPolyMatTags(true),
                meshMaterialMap(map)
        {
        }
                                         
        LxResult		 Evaluate ()
        {
                if (unifyByPolyMatTags) {
                        const PolyMaterialTag polyMatTag(
                                ss->PolyTag (LXi_PTAG_MATR));
                        LXtPolygonID polyID(ss->PolyID ());
                        meshMaterialMap.insert (
                                std::make_pair (polyMatTag, polyID));
                }
                else {
                ss->pv->Step ();
                if (!type || ss->PolyType () == type)
                        ss->ss_Polygon ();
                }

                return LXe_OK;
        }

    private:
        MeshMaterialMap		 nullMap;

        bool			 unifyByPolyMatTags;
        MeshMaterialMap		&meshMaterialMap;
};

        void
CLxSceneSaver::WritePolys (
        LXtID4			 type,
        bool			 unifyByPolyMatTags)
{
        if (pv->Tally (pv->mesh.NPolygons ()))
                return;

        if (unifyByPolyMatTags) {
                /*
                 * Build the mesh material map (poly mat tag , poly ID).
                 */
                MeshMaterialMap		 meshMaterialMap;
                CPolyVisitor		 matVis(meshMaterialMap);
                matVis.ss = this;
                matVis.type = type;
                pv->poly.Enum (&matVis);

                /*
                 * Iterate using the mesh material map instead of
                 * calling the modo polygon enumerator.
                 */
                for (MeshMaterialMap::const_iterator iter = meshMaterialMap.begin ();
                     iter != meshMaterialMap.end (); ++iter) {
                        PolySet (iter->second);
                        ss_Polygon ();
                }
        }
        else {
                CPolyVisitor		 vis;
        vis.ss   = this;
        vis.type = type;
        pv->poly.Enum (&vis);
        }
}

        void
CLxSceneSaver::PolySet (
        LXtPolygonID		 pol)
{
        pv->Err (pv->poly.Select (pol));
}

        LXtPolygonID
CLxSceneSaver::PolyID ()
{
        return pv->poly.ID ();
}

        LXtID4
CLxSceneSaver::PolyType ()
{
        LXtID4			 t;

        if (LXx_OK (pv->poly.Type (&t)))
                return t;
        else
                return 0;
}

        unsigned
CLxSceneSaver::PolyNumVerts ()
{
        unsigned		 n = 0;

        pv->poly.VertexCount (&n);
        return n;
}

        LXtPointID
CLxSceneSaver::PolyVertex (
        unsigned		 index)
{
        LXtPointID		 pnt;

        if (LXx_FAIL (pv->poly.VertexByIndex (index, &pnt)))
                return 0;

        return pnt;
}

        const char *
CLxSceneSaver::PolyTag (
        LXtID4			 tag)
{
        const char		*value;

        if (LXx_OK (pv->polyTag.Get (tag, &value)))
                return value;

        return 0;
}

        bool
CLxSceneSaver::PolyNormal (
        LXtVector		 norm,
        LXtPointID		 vrt)
{
        if (!vrt)
                return LXx_OK (pv->poly.Normal (norm));

        pv->point.Select (vrt);
        return LXx_OK (pv->point.Normal (pv->poly.ID (), norm));
}

        bool
CLxSceneSaver::PolyMapValue (
        float			*vec,
        LXtPointID		 vrt)
{
        LxResult		 rc;

        if (!pv->map.ID ())
                return false;

        rc = pv->poly.MapEvaluate (pv->map.ID (), vrt, vec);

        /*
         * We specifically test for LXe_OK (instead of testing with
         * LXx_OK), because MapEvaluate can return LXe_FALSE, which
         * passes the LXx_OK test, leaving the vec array un-initialized.
         */
        return (rc == LXe_OK);
}

        LxResult
CLxSceneSaver::LastErr  () const
{
        return pv->LastErr ();
}

        void
CLxSceneSaver::Step (unsigned n)
{
        pv->Step (n);
}

        void
CLxSceneSaver::Tally (unsigned n)
{
        pv->Tally (n);
}

