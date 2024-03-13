/*
 * Plug-in SDK Header: C++ Services
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
 * Wrapper for building scenes from scratch.
 */
#ifndef LX_SCENE_HPP
#define LX_SCENE_HPP

#include <lxvector.h>	// for FX channel values
#include <lx_item.hpp>
#include <lx_mesh.hpp>
#include <lx_locator.hpp>
#include <lx_trisurf.hpp>
#include <lx_envelope.hpp>
#include <lx_package.hpp>
#include <lx_io.hpp>
#include <lx_value.hpp>
#include <lxu_parser.hpp>
#include <lxu_format.hpp>
#include <lxidef.h>

#include <string>

/*
 * ----------------------------------------------------------------------------
 * Various file utilities.
 */

namespace lx
{

/*
 * This adds the base filename onto a path with a path separator. If the
 * basename is absolute the function fails.
 */

        bool
ComposeFilePath (
        const std::string	&fileName,
        const std::string	&filePath,
        std::string		&composedPath);

}	// End namespace lx

/*
 * ----------------------------------------------------------------
 * Scene builder class is a service that allows building a scene using
 * simple methods. New elements are given an index which can be used to
 * select them and reference them.
 */
class CLxSceneBuilder
{
    public:
         CLxSceneBuilder ();
        ~CLxSceneBuilder ();

        static const int	 CURMASK = 0;
        static const int	 SCENE   = 1;
        static const int	 RENDER  = 2;
        static const int	 ENVIRON = 3;

        bool			 IsGood     ();
        LxResult		 ErrorCode  ();
        void			 Initialize (ILxUnknownID);
        LxResult		 Finalize   ();
        void			 Cleanup    ();
        bool			 IsValid    ();

        unsigned		 SceneItem   ();
        ILxUnknownID		 SceneObject ();
        unsigned		 Singleton   (int what);

        unsigned		 AddItem   (const char *);
        unsigned		 PushItem  (ILxUnknownID);
        void			 SetItem   (unsigned);
        unsigned		 InstItem  (unsigned);
        unsigned		 CurItem   ();
        ILxUnknownID		 GetItem   ();
        bool			 GetItem   (CLxLocalizedObject &);
        bool			 GetMesh   (CLxLocalizedObject &);
        void			 SetName   (const char *);
        void			 SetTag    (LXtID4, const char *);
        void			 SetParent (unsigned int index, unsigned int childPos = -1);
        void			 SetLink   (const char *, unsigned int);
        void			 SetLink   (const char *, unsigned int, int, int);
        void			 SetLink   (const char *channelFrom, unsigned int itemTo, const char *channelTo);
        
        unsigned		 AddRenderOutput (const char *path, const char *format, const char *effect);

        bool			 GoodMesh ();

        void			 SetChannel  (const char *, bool);
        void			 SetChannel  (const char *, int);
        void			 SetChannel  (const char *, double);
        void			 SetChannelColor  (const char *, const LXtVector&);
        void			 SetChannel  (const char *, const char *);
        void			 SetChannelEncoded (const char *, const char *);
        void			 SetChannel  (unsigned int, bool);
        void			 SetChannel  (unsigned int, int);
        void			 SetChannel  (unsigned int, double);
        void			 SetChannel  (unsigned int, const char *);
        void			 SetChannelEncoded (unsigned int, const char *);
        void			 SetEditTime (double frameTime);
        void			 AddEnvelope (const char *, CLxUser_Envelope &);
        void			 AddEnvelope (unsigned int, CLxUser_Envelope &);
        void			 AddValue    (const char *, CLxUser_Value &);
        void			 AddValue    (unsigned int, CLxUser_Value &);

        void			 SetXform     (LXtTransformType, double[3]);
        void			 SetXform     (LXtTransformType, double, double, double);
        void			 SetXform     (LXtTransformType, double);
        unsigned		 AddXform     (LXtTransformType, unsigned * = 0);

        unsigned		 AddPreXform  (LXtTransformType, double[3], unsigned * = 0);
        unsigned		 AddPreXform  (LXtTransformType, double, double, double, unsigned * = 0);
        unsigned		 AddPreXform  (LXtTransformType, double, unsigned * = 0);

        unsigned		 AddPostXform (LXtTransformType, double[3], unsigned * = 0);
        unsigned		 AddPostXform (LXtTransformType, double, double, double, unsigned * = 0);
        unsigned		 AddPostXform (LXtTransformType, double, unsigned * = 0);

        unsigned		 PrependXform (LXtTransformType, double[3], unsigned * = 0);
        unsigned		 PrependXform (LXtTransformType, double, double, double, unsigned * = 0);
        unsigned		 PrependXform (LXtTransformType, double, unsigned * = 0);

        unsigned		 AppendXform  (LXtTransformType, double[3], unsigned * = 0);
        unsigned		 AppendXform  (LXtTransformType, double, double, double, unsigned * = 0);
        unsigned		 AppendXform  (LXtTransformType, double, unsigned * = 0);

        void			 AddPackage (const char *);

        unsigned		 RenderItem ();
        unsigned		 AddMaterial  (const char *matName, int where = RENDER, const char *matType = LXsITYPE_ADVANCEDMATERIAL);
        void			 SpecExponent (double);
        unsigned		 AddTexture   (const char *, int where = CURMASK);
        unsigned		 AddImage     (const char *filename);
        unsigned		 AddImageFolder (const char *folderName);
        unsigned		 AddImageMap  (const char *, const char * = 0, const char * = "Texture", int where = CURMASK);
        unsigned		 TxtrLocator  ();

        unsigned		 AddMesh (bool asStatic = false);
        unsigned		 ConvertMesh ();

        unsigned		 AddPoint (LXtFVector);
        unsigned		 AddPoint (LXtVector);
        unsigned		 AddPoint (double, double, double);

        void			 StartPoly  (LXtID4);
        void			 AddVertex  (unsigned);
        unsigned		 AddPolygon (bool rev = false);
        void			 SetPolyTag (unsigned, LXtID4, const char *);

        unsigned		 AddMap       (LXtID4, const char *);
        bool			 SetMap       (LXtID4, const char *name = 0);
        void			 SetPointMap  (unsigned, float *, unsigned);
        void			 SetVertexMap (unsigned, float *, unsigned, unsigned);
        void			 SetCoVertMap (unsigned, float *, unsigned, unsigned);
        void			 SetEdgeMap   (const float *, unsigned, unsigned);
        
        unsigned		 AddMeshOp (const char *);
        unsigned		 AddSelOp (const char *);

        class pv_SceneBuilder	*pv;
};


// ------------ following declaractions are deprecated
//@skip

/*
 * ----------------------------------------------------------------
 * Scene loader framework class.
 *
 * The scene loader handles all the basic mechanics of loading a scene.
 * The subclass provides a suitable parser, plus methods for recognizing
 * and reading an open file. The Parse() method is called until it returns
 * false or some other error occurs.
 */
class CLxSceneLoader : public CLxImpl_Loader
{
    public:
                                 CLxSceneLoader ();
        virtual			~CLxSceneLoader ();

        LxResult		 load_Recognize  (const char *, ILxUnknownID)	 LXx_OVERRIDE;
        LxResult		 load_LoadObject (ILxUnknownID, ILxUnknownID, ILxUnknownID)
                                                                                 LXx_OVERRIDE;
        void			 load_Cleanup    ()				 LXx_OVERRIDE;
        LxResult		 load_SpawnOptions (void **)			 LXx_OVERRIDE;

        virtual CLxFileParser	*sl_Parser     ()		= 0;

        virtual bool		 sl_Recognize  ()		= 0;
        virtual bool		 sl_HasOptions ()		 { return false; }
        virtual void		 sl_SpawnOpt   (void **)	 { }

        virtual bool		 sl_ParseInit  ()		 { return true; };
        virtual bool		 sl_ParseDone  ()		 { return true; }
        virtual bool		 sl_Parse      (LxResult *)	= 0;

        bool			 IsFileAbsolute (const char *fileName) const;
        bool			 IsFileAbsolute (const std::string &fileName) const;
        bool			 MakeFileAbsolute (
                                        char *absFileName,
                                        const char *fileName);
        bool			 MakeFileAbsolute (std::string &fileName);

        CLxUser_SceneLoaderTarget
                                 ld_target;
        CLxSceneBuilder		 scene_build;
        const char		*cp_filename;
};


/*
 * ----------------------------------------------------------------
 * Scene saver framework class.
 *
 * The scene saver handles all the basic mechanics of saving a scene.
 */
class CLxSceneSaver : public CLxImpl_Saver
{
    public:
                                 CLxSceneSaver ();
        virtual			~CLxSceneSaver ();

        LxResult		 sav_Verify   (ILxUnknownID, ILxUnknownID)		 LXx_OVERRIDE;
        LxResult		 sav_Save     (ILxUnknownID, const char *, ILxUnknownID) LXx_OVERRIDE;

        virtual CLxFileFormat	*ss_Format    ()	= 0;
        virtual bool		 ss_DoSubset  ()	 { return false; }

        virtual void		 ss_Verify    ()	 {}
        virtual LxResult	 ss_Save      ()	= 0;

        virtual void		 ss_Point     ()	 {}
        virtual void		 ss_Edge      ()         {}
        virtual void		 ss_Polygon   ()	 {}

        void			 Message      (const char *, unsigned);
        void			 Message      (const char *, const char *);
        void			 MessageArg   (unsigned, int);
        void			 MessageArg   (unsigned, double);
        void			 MessageArg   (unsigned, const char *);

        ILxUnknownID		 SceneObject  ();
        bool			 ReallySaving ();
        bool			 TestItem     (ILxUnknownID item);

        bool			 IsSceneSaved ();
        const char *		 ScenePath    ();
        const char *		 SceneName    (unsigned);

        void			 StartScan    (const char * = 0);
        bool			 NextItem     ();
        bool			 NextMesh     ();
        bool			 NextSelectedMesh ();
        bool			 GetMesh      (CLxUser_Mesh &);
        bool			 ScanMask     (const char *, const char * = 0);
        bool			 NextLayer    ();

        bool			 GetItem      (CLxUser_Item &) const;
        bool			 SetItem      (ILxUnknownID);
        bool			 SetMeshTime  (double);

        bool			 ItemVisible  () const;
        const char *		 ItemName     () const;
        std::string		 ItemIdentity () const;
        const char *		 ItemType     () const;
        LXtItemType		 GetItemType  () const;
        LXtItemType		 ItemType     (const char *typeName) const;
        bool			 ItemIsA      (const char *typeName) const;
        const char *		 ItemTag      (LXtID4 tag);
        unsigned		 ItemTagCount ();
        const char *		 ItemTagByIndex (unsigned index, LXtID4 *tag);

        bool			 WorldXform   (LXtMatrix, LXtVector);
        bool			 HasXformItem (LXtTransformType) const;
        bool			 XformItem    (LXtTransformType);

        const char *		 LayerEffect  ();
        double			 SpecExponent ();
        bool			 TxtrImage    ();
        bool			 TxtrLocator  ();

        unsigned		 ChanIndex    (const char *channel) const;
        bool			 ChanBool     (unsigned index) const;
        bool			 ChanBool     (const char *channel) const;
        int			 ChanInt      (unsigned index) const;
        int			 ChanInt      (const char *channel) const;
        double			 ChanFloat    (unsigned index) const;
        double			 ChanFloat    (const char *channel) const;
        void			 ChanColor    (const char *channel, LXtVector vec) const;
        void			 ChanXform    (const char *channel, LXtVector vec) const;
        const char *		 ChanString   (unsigned index) const;
        const char *		 ChanString   (const char *channel) const;
        void			 ChanIntEncoded (unsigned channelIndex, char *buf, int bufLen) const;
        void			 ChanIntEncoded (const char *channel, char *buf, int bufLen) const;
        bool			 ChanObject   (unsigned index,  CLxLocalizedObject &loc) const;
        bool			 ChanObject   (const char *channel, CLxLocalizedObject &loc) const;
        bool			 ChanEnvelope (unsigned index, CLxUser_Envelope &env) const;
        bool			 ChanEnvelope (const char *channel, CLxUser_Envelope &env) const;
        bool			 ChanIsAnimated (unsigned index) const;
        bool			 ChanIsAnimated (const char *channel) const;

        bool			 IsFileAbsolute (const char *fileName) const;
        bool			 IsFileAbsolute (const std::string &fileName) const;
        bool			 MakeFileRelative (
                                        char *relName,
                                        const char *fileName);
        bool			 MakeFileRelative (std::string &relName);
        bool			 MakeFileAbsolute (
                                        char *absFileName,
                                        const char *fileName);
        bool			 MakeFileAbsolute (std::string &fileName);

        void			 MeshBounds   (LXtBBox &);
        bool			 SetMap       (LXtID4, const char *name = 0);
        bool			 SetSelMap    (LXtID4);

        unsigned		 PointCount   ();
        void			 WritePoints  ();
        void			 PntSet       (LXtPointID);
        LXtPointID		 PntID        ();
        void			 PntPosition  (LXtFVector);
        void			 PntPosition  (LXtVector);
        bool			 PntNormal    (LXtVector, LXtPolygonID = 0);
        bool			 PntMapValue  (float *);

        unsigned		 EdgeCount    ();
        void			 WriteEdges   ();
        LXtEdgeID		 EdgeID       ();
        bool			 EdgeEndPoints (LXtPointID *, LXtPointID *);
        bool			 EdgeMapValue (float *);

        unsigned		 PolygonCount ();
        void			 WritePolys   (
                                        LXtID4	type = 0,
                                        bool	unifyByPolyMatTags = false);
        void			 PolySet      (LXtPolygonID);
        LXtPolygonID		 PolyID       ();
        LXtID4			 PolyType     ();
        unsigned		 PolyNumVerts ();
        LXtPointID		 PolyVertex   (unsigned);
        const char *		 PolyTag      (LXtID4);
        bool			 PolyNormal   (LXtVector, LXtPointID = 0);
        bool			 PolyMapValue (float *, LXtPointID);
        bool			 GetPolygon   (CLxUser_Polygon &);

        LxResult		 LastErr      () const;

        // Export monitor controls
        void			 Step (unsigned n = 1);
        void			 Tally (unsigned n);

        class pv_SceneSaver	*pv;
};


#endif	/* LX_SCENE_HPP */

