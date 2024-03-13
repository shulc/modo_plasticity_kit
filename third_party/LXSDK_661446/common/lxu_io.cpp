/*
 * Plug-in SDK Source: Metaclasses
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
 * Implements I/O metaclasses.
 */
#include <lxu_io.hpp>
#include <lxw_command.hpp>
#include <lx_com.hpp>
#include <string>
#include <vector>

using namespace lx_err;


/*
 * ------------------------------------------------------
 * Meta Loader
 */

/*
 * The options COM object just implements the StreamIO interface. It's basically
 * just a place to put a pointer to the client's subclass.
 */
class impl_Options_Object :
                public CLxImpl_StreamIO
{
    public:
        CLxLoaderOptions		*lopt;

        LXxO_StreamIO_Write // (ILxUnknownID stream)
        {
                CLxUser_BlockWrite	 w (stream);

                lopt->save (w);
                return LXe_OK;
        }

        LXxO_StreamIO_Read // (ILxUnknownID stream)
        {
                CLxUser_BlockRead	 r (stream);

                lopt->load (r);
                return LXe_OK;
        }

                static CLxPolymorph<impl_Options_Object> *
        factory ()
        {
                CLxSpawnerCreate<impl_Options_Object> sp ("lxu_io.options");

                if (sp.created)
                        sp.AddInterface (new CLxIfc_StreamIO<impl_Options_Object>);

                return sp.spawn;
        }
};

class impl_Loader_Server;

/*
 * This private state is global to each loader metaclass.
 */
class pv_Meta_Loader
{
    public:
        CLxTagList		*tag_list;
        CLxMeta_Loader_Core	*m_core;
        std::string		 cmd_name;
        std::vector<const char *>
                                 cls_list;

        pv_Meta_Loader ()
        {
                tag_list   = 0;
                m_core     = 0;
        }

                void
        add_interfaces (
                CLxGenericPolymorph	*gp)
        {
                gp->AddInterface (new CLxIfc_Loader        <impl_Loader_Server>);
                gp->AddInterface (new CLxIfc_TagDescription<impl_Loader_Server>);
        }

                std::string
        class_list ()
        {
                std::string		 res;
                int			 i, n;

                n = cls_list.size();
                for (i = 0; i < n; i++)
                {
                        if (i)
                                res += " ";

                        res += cls_list[i];
                }

                return res;
        }

                CLxLoaderOptions *
        alloc_options (
                void		       **ppvObj)
        {
                CLxPolymorph<impl_Options_Object> *fac = impl_Options_Object::factory ();
                impl_Options_Object	*iopt = fac->Alloc (ppvObj);

                iopt->lopt = m_core->new_options ();
                return iopt->lopt;
        }
};

/*
 * This private state is local to each loader subclass.
 */
class pv_Loader
{
    public:
        pv_Meta_Loader		*mpv;
        CLxUser_LoaderInfo	 info;
        CLxUser_Monitor		 mon;
        bool			 opaque;

        pv_Loader ()
        {
                mpv    = 0;
                opaque = false;
        }
};


/*
 * The Loader server object implements the Loader and Tags interfaces.
 */
class impl_Loader_Server :
                public CLxImpl_Loader,
                public CLxImpl_TagDescription
{
    public:
        class pv_Meta_Loader	*mpv;
        CLxLoader		*load;

        impl_Loader_Server (
                pv_Meta_Loader		*init = 0)
        {
                mpv = init;
                load = 0;
        }

        /*
         * We allocate a new loader for each new recognize so that the state
         * is always pristene. If the recog succeeds we set the flags based
         * on the settings of the loader.
         */
        LXxO_Loader_Recognize // (const char *filename, ILxUnknownID loadInfo)
        {
                if (load)
                        delete load;

                load = mpv->m_core->new_inst ();
                check (load->pv->info.set (loadInfo));

                load->pv->opaque = false;
                if (!load->recognize (filename))
                        return LXe_NOTFOUND;

                unsigned flags = 0;
                if (load->pv->opaque)
                        flags |= LXfLOAD_OPAQUE;

                if (mpv->m_core->has_options ())
                        flags |= LXfLOAD_OPTIONS;

                check (load->pv->info.SetFlags (flags));
                return LXe_OK;
        }

        /*
         * Opaque load allocates an object. The monitor is optional.
         */
        LXxO_Loader_LoadInstance // (ILxUnknownID loadInfo, ILxUnknownID monitor, void **ppvObj)
        {
                check (load->pv->info.set (loadInfo));
                load->pv->mon.set (monitor);

                ppvObj[0] = load->load_opaque ();
                if (ppvObj[0])
                        return LXe_OK;
                else
                        return LXe_FAILED;
        }

        /*
         * Non-opaque load fill in destination object. The monitor is optional.
         */
        LXxO_Loader_LoadObject // (ILxUnknownID loadInfo, ILxUnknownID monitor, ILxUnknownID dest)
        {
                check (load->pv->info.set (loadInfo));
                load->pv->mon.set (monitor);

                load->load_into (dest);
                return LXe_OK;
        }

        /*
         * Cleanup is called at the end of the cycle, and we free the loader.
         */
        LXxO_Loader_Cleanup // (void)
        {
                if (load)
                        delete load;

                load = 0;
        }

        LXxO_Loader_SpawnOptions // (void **ppvObj)
        {
                mpv->alloc_options (ppvObj);
                return LXe_OK;
        }

        /*
         * Server tags from metaclass core.
         */
        LXxO_TagDescription_Count
        {
                return mpv->tag_list->count ();
        }

        LXxO_TagDescription_Describe
        {
                return mpv->tag_list->describe (index, desc);
        }
};


/*
 * Methods on the public root class just store settings for the actual
 * implementation methods.
 */
CLxLoader::CLxLoader ()
{
        pv = new pv_Loader;
}

CLxLoader::~CLxLoader ()
{
        delete pv;
}

/*
 * If there's only one class this just returns that. If there are more then
 * we find the one the loader wants more and use that one, setting it at
 * the same time.
 */
        const char *
CLxLoader::get_class ()
{
        int			 n;

        n = pv->mpv->cls_list.size();
        if (n == 1)
                return pv->mpv->cls_list[0];

        CLxUser_GUIDService	 guid_S;
        const LXtGUID		*guid, *gres;
        unsigned		 pri, best;
        int			 i, ires;

        best = ~0;
        for (i = 0; i < n; i++)
        {
                guid = guid_S.Translate (pv->mpv->cls_list[i]);
                if (pv->info.TestClass (guid, &pri) == LXe_TRUE && pri < best)
                {
                        gres = guid;
                        ires = i;
                        best = pri;
                }
        }

        check (pv->info.SetClass (gres));
        return pv->mpv->cls_list[ires];
}

        void
CLxLoader::set_opaque (
        bool			 opaque)
{
        pv->opaque = opaque;
}

        void
CLxLoader::set_format (
        const char		*fmtName)
{
        check (pv->info.SetFormat (fmtName));
}

        CLxUser_LoaderInfo &
CLxLoader::loader_info ()
{
        return pv->info;
}

        CLxUser_Monitor &
CLxLoader::monitor ()
{
        return pv->mon;
}


/*
 * The metaclass holds the global settings.
 */
CLxMeta_Loader_Core::CLxMeta_Loader_Core (
        const char		*srvName)
                :
        CLxMetaServer (srvName)
{
        pv = new pv_Meta_Loader;
        pv->m_core   =  this;
        pv->tag_list = &tag_list;

        cls_guid = &lx::guid_Loader;
}

CLxMeta_Loader_Core::~CLxMeta_Loader_Core ()
{
        delete pv;
}

        bool
CLxMeta_Loader_Core::pre_init ()
{
        CLxMeta			*cmd;

        cmd = find_sub (LXsMETA_SERVER, &lx::guid_Command);
        if (cmd)
        {
                pv->cmd_name  = "loaderOptions.";
                pv->cmd_name +=  m_name;

                cmd->m_name = pv->cmd_name.c_str();
        }

        return false;
}

        void *
CLxMeta_Loader_Core::alloc ()
{
        add_tag (LXsLOD_CLASSLIST, pv->class_list().c_str());

        return reinterpret_cast<void *>
           ( new CLxMetagenPolymorph<impl_Loader_Server, pv_Meta_Loader> (pv) );
}

        CLxLoaderOptions *
CLxMeta_Loader_Core::access_opt (
        bool			 create)
{
        CLxUser_IOService	 io_S;

        if (create)
        {
                ILxUnknownID		 obj;
                CLxLoaderOptions	*opt;

                opt = pv->alloc_options ((void **) &obj);
                io_S.SetOptions (obj);
                lx::ObjRelease (obj);
                return opt;
        } else
        {
                CLxPolymorph<impl_Options_Object> *fac = impl_Options_Object::factory ();
                ILxUnknownID		 obj;
                impl_Options_Object	*iopt;

                obj = io_S.PeekOptions ();
                if (!obj)
                        return 0;

                iopt = fac->Cast (obj);
                return iopt->lopt;
        }
}

        void
CLxMeta_Loader_Core::set_file_pattern (
        const char		*pattern)
{
        add_tag (LXsLOD_DOSPATTERN, pattern);
}

        void
CLxMeta_Loader_Core::set_threadsafe ()
{
        add_tag (LXsLOD_THREADSAFE, "Yes");
}

        void
CLxMeta_Loader_Core::set_class (
        const char		*clsName)
{
        pv->cls_list.push_back (clsName);
}



/*
 * ------------------------------------------------------
 * Meta Saver
 */
class impl_Saver_Server;

/*
 * This private state is global to each saver metaclass.
 */
class pv_Meta_Saver
{
    public:
        CLxTagList		*tag_list;
        CLxMeta_Saver_Core	*m_core;

        pv_Meta_Saver ()
        {
                tag_list   = 0;
                m_core     = 0;
        }

                void
        add_interfaces (
                CLxGenericPolymorph	*gp)
        {
                gp->AddInterface (new CLxIfc_Saver         <impl_Saver_Server>);
                gp->AddInterface (new CLxIfc_TagDescription<impl_Saver_Server>);
        }
};


/*
 * The Saver server object implements the Saver and Tags interfaces.
 */
class impl_Saver_Server :
                public CLxImpl_Saver,
                public CLxImpl_TagDescription
{
    public:
        /*
         * The temp saver class just allocates a saver and disposes of it no
         * matter how this object goes out of scope.
         */
        class cTempSaver {
            public:
                CLxSaver	*ts;

                 cTempSaver (pv_Meta_Saver *mpv)
                {
                        ts = mpv->m_core->new_inst ();
                }

                ~cTempSaver ()
                {
                        delete ts;
                }
        };

        pv_Meta_Saver		*mpv;

        impl_Saver_Server (
                pv_Meta_Saver		*init = 0)
        {
                mpv = init;
        }

        LXxO_Saver_Verify // (ILxUnknownID source, ILxUnknownID message)
        {
                CLxUser_Message		 msg (message);
                cTempSaver		 save (mpv);

                save.ts->obj_verify (source, msg);
                return LXe_OK;
        }

        LXxO_Saver_Save // (ILxUnknownID source, const char *filename, ILxUnknownID monitor)
        {
                CLxUser_Monitor		 mon (monitor);
                cTempSaver		 save (mpv);

                save.ts->obj_save (source, filename, mon);
                return LXe_OK;
        }

        /*
         * Server tags from metaclass core.
         */
        LXxO_TagDescription_Count
        {
                return mpv->tag_list->count ();
        }

        LXxO_TagDescription_Describe
        {
                return mpv->tag_list->describe (index, desc);
        }
};


/*
 * The metaclass holds the global settings.
 */
CLxMeta_Saver_Core::CLxMeta_Saver_Core (
        const char		*srvName)
                :
        CLxMetaServer (srvName)
{
        pv = new pv_Meta_Saver;
        pv->m_core   =  this;
        pv->tag_list = &tag_list;

        cls_guid = &lx::guid_Saver;
}

CLxMeta_Saver_Core::~CLxMeta_Saver_Core ()
{
        delete pv;
}

        void *
CLxMeta_Saver_Core::alloc ()
{
        return reinterpret_cast<void *>
           ( new CLxMetagenPolymorph<impl_Saver_Server, pv_Meta_Saver> (pv) );
}

        void
CLxMeta_Saver_Core::set_class (
        const char		*clsName)
{
        add_tag (LXsSAV_OUTCLASS, clsName);
}

        void
CLxMeta_Saver_Core::set_file_extension (
        const char		*pattern)
{
        add_tag (LXsSAV_DOSTYPE, pattern);
}

        void
CLxMeta_Saver_Core::set_overwrite ()
{
        add_tag (LXsSAV_OVERWRITE, "1");
}

        void
CLxMeta_Saver_Core::set_save_as ()
{
        add_tag (LXsSAV_SAVEAS, "1");
}


