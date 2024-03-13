/*
 * Plug-in SDK Source: Package Utilities
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
 * Provides package utility classes.
 */
#include <lxu_package.hpp>
#include <lxu_getstring.hpp>
#include <lx_vmodel.hpp>


/*
 * ------------------------------------------------------
 * Default package just uses the common spawner to alloc objects and test
 * interface guids.
 */
        LxResult
CLxDefaultPackage::pkg_Attach (
        void		       **ppvObj)
{
        Spawner			 sp;

        sp.Alloc (ppvObj);
        return LXe_OK;
}

        LxResult
CLxDefaultPackage::pkg_TestInterface (
        const LXtGUID		*guid)
{
        Spawner			 sp;

        return sp.TestInterfaceRC (guid);
}


/*
 * ------------------------------------------------------
 * Meta Package Instance. This just implements the PackageInstance interface
 * with a reference to a CLxPackage.
 */
class meta_PackageInstance :
                public CLxImpl_PackageInstance
{
    public:
        CLxPackage		*m_pkg;

        LXxO_PackageInstance_Initialize
        {
                m_pkg->m_item.set (item);
                m_pkg->initialize(super);
                return LXe_OK;
        }

        LXxO_PackageInstance_SynthName
        {
                std::string		 name = "";

                m_pkg->synth_name (name);
                if (name == "")
                        return LXe_NOTIMPL;

                return lx::StringOut (name, buf, len);
        }

        LXxO_PackageInstance_TestParent
        {
                CLxUser_Item		 parent (item);

                return (m_pkg->parent_ok (parent) ? LXe_TRUE : LXe_FALSE);
        }

        LXxO_PackageInstance_Newborn
        {
                CLxUser_Item		 orig (original);

                m_pkg->newborn (orig, flags);
                return LXe_OK;
        }

        LXxO_PackageInstance_Loading
        {
                m_pkg->loading ();
                return LXe_OK;
        }

        LXxO_PackageInstance_AfterLoad
        {
                m_pkg->after_load ();
                return LXe_OK;
        }

        LXxO_PackageInstance_Add
        {
                m_pkg->add ();
                return LXe_OK;
        }

        LXxO_PackageInstance_Remove
        {
                m_pkg->remove ();
                return LXe_OK;
        }

        LXxO_PackageInstance_Doomed
        {
                m_pkg->doomed ();
        }
};

/*
 * pv_Meta_Package is the common data allocate for the metaclass and shared by
 * all the other polymorphs and objects.
 */
class pv_Meta_Package
{
    public:
        CLxTagList		*tag_list;
        CLxAttributeDesc	*attr_desc;
        CLxMeta_Package_Core	*m_core;
        CLxMetaInterfaces	*pkg_sub;
        CLxGenericPolymorph	*inst_spawn;
        CLxMetaInterfaces	*inst_sub;

        pv_Meta_Package ()
        {
                tag_list   = 0;
                attr_desc  = 0;
                m_core     = 0;
                pkg_sub    = 0;
                inst_spawn = 0;
                inst_sub   = 0;
        }
};

/*
 * This polymorph is the spawner for the PackageInstance, with a couple of
 * overrides:
 *
 *	- IsA() & TestInterface() allow us to allocate sub-objects associated
 *	  with the package instance.
 *
 *	- NewObj() allocates a CLxPackage for each PackageInstance.
 */
class meta_PackageInstancePolymorph :
                public CLxPolymorph<meta_PackageInstance>
{
    public:
        class pv_Meta_Package	*pv;

        meta_PackageInstancePolymorph (
                class pv_Meta_Package	*ptr)
        {
                this->AddInterface (new CLxIfc_PackageInstance<meta_PackageInstance>);
                pv = ptr;
        }

                void *
        NewObj ()					 LXx_OVERRIDE
        {
                meta_PackageInstance	*inst;

                inst = new meta_PackageInstance;
                inst->m_pkg = pv->m_core->new_inst ();
                return reinterpret_cast<void *> (inst);
        }

                bool
        TestInterface (
                const LXtGUID		*iid)		LXx_OVERRIDE
        {
                if (pv->inst_sub->test (iid))
                        return true;

                return CLxGenericPolymorph::TestInterface (iid);
        }

                ILxUnknownID
        IsA (
                ILxUnknownID		 src,
                const LXtGUID		*iid)		LXx_OVERRIDE
        {
                CLxGenericPolymorph	*gp;

                gp = pv->inst_sub->find (iid);
                if (!gp)
                        return 0;

                return gp->Spawn ();
        }

                void *
        RefObj (
                void			*obj)		LXx_OVERRIDE
        {
                meta_PackageInstance	*inst = (meta_PackageInstance *) obj;

                return (void *) inst->m_pkg;
        }
};

/*
 * The Package server obejcts just implements the Package and Tags interfaces.
 */
class meta_PackageServer :
                public CLxImpl_Package,
                public CLxImpl_TagDescription
{
    public:
        class pv_Meta_Package	*pv;

        LXxO_Package_SetupChannels
        {
                if (pv->attr_desc)
                        return pv->attr_desc->setup_channels (addChan);
                else
                        return LXe_OK;
        }

        LXxO_Package_Attach
        {
                ppvObj[0] = pv->inst_spawn->Spawn ();
                return LXe_OK;
        }

        LXxO_Package_TestInterface
        {
                return (pv->inst_spawn->TestInterface (guid) ? LXe_TRUE : LXe_FALSE);
        }

        LXxO_TagDescription_Count
        {
                return pv->tag_list->count ();
        }

        LXxO_TagDescription_Describe
        {
                return pv->tag_list->describe (index, desc);
        }
};

/*
 * The package polymorph allows sub-objects and passes the PV data to the
 * new package instances.
 */
class meta_PackagePolymorph :
                public CLxPolymorph<meta_PackageServer>
{
    public:
        class pv_Meta_Package	*pv;

        meta_PackagePolymorph (
                class pv_Meta_Package	*ptr)
        {
                this->AddInterface (new CLxIfc_Package       <meta_PackageServer>);
                this->AddInterface (new CLxIfc_TagDescription<meta_PackageServer>);
                pv = ptr;
        }

                bool
        TestInterface (
                const LXtGUID		*iid)		LXx_OVERRIDE
        {
                if (pv->pkg_sub->test (iid))
                        return true;

                return CLxGenericPolymorph::TestInterface (iid);
        }

                ILxUnknownID
        IsA (
                ILxUnknownID		 src,
                const LXtGUID		*iid)		LXx_OVERRIDE
        {
                CLxGenericPolymorph	*gp;

                gp = pv->pkg_sub->find (iid);
                if (!gp)
                        return 0;

                return gp->Spawn ();
        }

                void *
        NewObj ()			 LXx_OVERRIDE
        {
                meta_PackageServer *pkg;

                pkg = new meta_PackageServer;
                pkg->pv = pv;
                return reinterpret_cast<void *> (pkg);
        }
};


/*
 * Package metaclass is the owner of the common private data. It defines itself
 * as a server of the Package type. PV data is set at create and again during
 * alloc when the whole meta tree is available.
 */
CLxMeta_Package_Core::CLxMeta_Package_Core (
        const char		*srvName)
                :
        CLxMetaServer (srvName)
{
        pv = new pv_Meta_Package;
        pv->m_core     = this;
        pv->tag_list   = &tag_list;
        pv->inst_spawn = new meta_PackageInstancePolymorph (pv);

        cls_guid = &lx::guid_Package;
        has_channel_ui = false;
}

CLxMeta_Package_Core::~CLxMeta_Package_Core ()
{
        delete pv;
}

        bool
CLxMeta_Package_Core::pre_init ()
{
        CLxMeta			*m;

        m = find_any (LXsMETA_ATTRDESC);
        if (m)
        {
                pv->attr_desc = reinterpret_cast<CLxAttributeDesc *> (m->alloc ());
                if (!has_channel_ui && pv->attr_desc->need_chan_ui ())
                        add_channel_ui<CLxChannelUI> ();
        }

        return false;
}

        void *
CLxMeta_Package_Core::alloc ()
{
        pv->pkg_sub  = get_ifcs (&lx::guid_Package);
        pv->inst_sub = get_ifcs (&lx::guid_PackageInstance);

        return reinterpret_cast<void *> (new meta_PackagePolymorph (pv));
}

        void
CLxMeta_Package_Core::set_supertype (
        const char		*typeName)
{
        add_tag (LXsPKG_SUPERTYPE, typeName);
}


/*
 * ------------------------------------------------------
 * Channel UI
 *
 * UI for channels, implementing the ChannelUI interface on a metaclass.
 */
class pv_Meta_ChannelUI
{
    public:
        CLxMeta_ChannelUI_Core	*m_core;
        CLxAttributeDesc	*attr_desc;
        std::string		 type_name;
};

/*
 * Channel UI interface
 */
class meta_ChannelUI :
                public CLxImpl_ChannelUI
{
    public:
        pv_Meta_ChannelUI	*pv;
        CLxChannelUI		*ui;

        LXxO_ChannelUI_ItemEnabled
        {
                CLxUser_Item	 uitem (item);
                CLxUser_Message	 mess (msg);

                if (ui->item_enabled (uitem, mess))
                        return LXe_OK;

                mess.SetCode (LXe_CMD_DISABLED);
                return LXe_CMD_DISABLED;
        }

        LXxO_ChannelUI_ItemIcon
        {
                CLxUser_Item	 uitem (item);
                const char	*name = ui->item_icon (uitem);

                if (!name)
                        return LXe_NOTFOUND;

                icon[0] = name;
                return LXe_OK;
        }

        LXxO_ChannelUI_Enabled
        {
                return pv->attr_desc->chan_enabled (channelName, item, chanRead, msg);
        }

        LXxO_ChannelUI_DependencyCount
        {
                count[0] = pv->attr_desc->chan_dep_count (channelName);
                return LXe_OK;
        }

        LXxO_ChannelUI_DependencyByIndexName
        {
                if (index >= pv->attr_desc->chan_dep_count (channelName))
                        return LXe_OUTOFBOUNDS;

                pv->attr_desc->chan_dep_byindex (channelName, index, depChannelName, depItemTypeName);
                if (!depItemTypeName[0])
                        depItemTypeName[0] = pv->type_name.c_str();

                return LXe_OK;
        }

        LXxO_ChannelUI_UIHints
        {
                return pv->attr_desc->chan_uihints (channelName, hints);
        }

        LXxO_ChannelUI_UIValueHints
        {
                return pv->attr_desc->chan_uivalue (channelName, ppvObj);
        }
};

/*
 * Polymorph -- just passes the private data along.
 */
class meta_ChannelUIPolymorph :
                public CLxPolymorph<meta_ChannelUI>
{
    public:
        pv_Meta_ChannelUI	*pv;

        meta_ChannelUIPolymorph (
                pv_Meta_ChannelUI	*init)
        {
                this->AddInterface (new CLxIfc_ChannelUI<meta_ChannelUI>);
                pv = init;
        }

                void *
        NewObj ()			 LXx_OVERRIDE
        {
                meta_ChannelUI		*obj;

                obj = new meta_ChannelUI;
                obj->pv = pv;
                obj->ui = pv->m_core->new_inst ();
                return reinterpret_cast<void *> (obj);
        }
};

/*
 * Meta_core class
 */
CLxMeta_ChannelUI_Core::CLxMeta_ChannelUI_Core ()
{
        m_type = LXsMETA_INTERFACE;
        cls_guid = &lx::guid_Package;

        pv = new pv_Meta_ChannelUI;
        pv->m_core = this;
}

CLxMeta_ChannelUI_Core::~CLxMeta_ChannelUI_Core ()
{
        delete pv;
}

        void *
CLxMeta_ChannelUI_Core::alloc ()
{
        CLxMeta			*m;

        m = find_any (LXsMETA_ATTRDESC);
        if (m)
                pv->attr_desc = reinterpret_cast<CLxAttributeDesc *> (m->alloc ());

        m = find_any (LXsMETA_SERVER, &lx::guid_Package);
        if (m)
                pv->type_name = m->m_name;

        return new meta_ChannelUIPolymorph (pv);
}


/*
 * ------------------------------------------------------
 * View Item 3D
 *
 * The client's CLxViewItem3D object is stateless, so we just share the same
 * one for all instances.
 */
class pv_Meta_ViewItem3D
{
    public:
        CLxMeta_ViewItem3D_Core *core;
        bool			 b_world, b_bg, b_test;

        pv_Meta_ViewItem3D (
                CLxMeta_ViewItem3D_Core	*init)
        {
                core    = init;
                b_world = false;
                b_bg    = false;
                b_test  = false;
        }
};

class meta_ViewItem3D :
                public CLxImpl_ViewItem3D
{
    public:
        pv_Meta_ViewItem3D	*pv;
        CLxViewItem3D		*v3d;
        CLxUser_Item		 m_item;

        LXxO_ViewItem3D_WorldSpace
        {
                return (pv->b_world ? LXe_TRUE : LXe_FALSE);
        }

        LXxO_ViewItem3D_Draw
        {
                CLxUser_ChannelRead	 chan (chanRead);
                CLxUser_StrokeDraw	 stroke (strokeDraw);

                v3d->draw (m_item, chan, stroke, selectionFlags, CLxVector (itemColor));
                return LXe_OK;
        }

        LXxO_ViewItem3D_Test
        {
                if (!pv->b_test)
                        return LXe_NOTIMPL;

                CLxUser_ChannelRead	 chan (chanRead);
                CLxUser_StrokeDraw	 stroke (strokeDraw);

                v3d->drawtest (m_item, chan, stroke, selectionFlags);
                return LXe_OK;
        }

        LXxO_ViewItem3D_DrawBackground
        {
                if (!pv->b_bg)
                        return LXe_NOTIMPL;

                CLxUser_ChannelRead	 chan (chanRead);
                CLxUser_StrokeDraw	 stroke (strokeDraw);

                v3d->drawbg (m_item, chan, stroke);
                return LXe_OK;
        }
};

class meta_ViewItem3DPolymorph :
                public CLxMetaPackagePolymorph<meta_ViewItem3D>
{
    public:
        pv_Meta_ViewItem3D	*pv;

        meta_ViewItem3DPolymorph (
                pv_Meta_ViewItem3D	*init)
        {
                this->AddInterface (new CLxIfc_ViewItem3D<meta_ViewItem3D>);
                pv = init;
        }

                void
        inherit (
                meta_ViewItem3D		*that,
                CLxPackage		*pkg)		LXx_OVERRIDE
        {
                that->m_item.set (pkg->m_item);
                that->pv  = pv;
                that->v3d = pv->core->new_inst ();
        }
};

CLxMeta_ViewItem3D_Core::CLxMeta_ViewItem3D_Core ()
{
        m_type = LXsMETA_INTERFACE;
        cls_guid = &lx::guid_PackageInstance;

        pv = new pv_Meta_ViewItem3D (this);
}

        void
CLxMeta_ViewItem3D_Core::set_world_space (
        bool			 world)
{
        pv->b_world = world;
}

        void
CLxMeta_ViewItem3D_Core::enable_background ()
{
        pv->b_bg = true;
}

        void
CLxMeta_ViewItem3D_Core::enable_test ()
{
        pv->b_test = true;
}

        void *
CLxMeta_ViewItem3D_Core::alloc ()
{
        return new meta_ViewItem3DPolymorph (pv);
}


/*
 * ------------------------------------------------------
 * Instance Assets
 *
 * The client's CLxInstanceAssets object enumerates the assets in an item,
 * and the local data stores the results in a list.
 */
class pv_InstanceAssets
{
    public:
        class assetEntry
        {
            public:
                std::string	 ident, fileType, category;
                bool		 isSeq;
        };

        std::vector<assetEntry>	 ass_list;
};

CLxInstanceAssets::CLxInstanceAssets ()
{
        pv = new pv_InstanceAssets;
}

CLxInstanceAssets::~CLxInstanceAssets ()
{
        delete pv;
}

        void
CLxInstanceAssets::add_asset (
        const char		*ident,
        const char		*fileType,
        const char		*category,
        bool			 isSeq)
{
        pv_InstanceAssets::assetEntry dum;

        dum.ident    = ident;
        dum.fileType = fileType;
        dum.isSeq    = isSeq;
        if (category)
                dum.category = category;

        pv->ass_list.push_back (dum);
}

/*
 * Just a place to put the core backpointer, so we can create instances.
 */
class pv_Meta_InstanceAssets
{
    public:
        CLxMeta_InstanceAssets_Core *core;

        pv_Meta_InstanceAssets (
                CLxMeta_InstanceAssets_Core	*init)
        {
                core = init;
        }
};

/*
 * Implementation for the actual object.
 */
class meta_InstanceAssets :
                public CLxImpl_InstanceAssets
{
    public:
        pv_Meta_InstanceAssets	*mpv;
        CLxInstanceAssets	*i_ass;
        CLxUser_Item		 m_item;

        LXxO_InstanceAssets_Count
        {
                i_ass->pv->ass_list.clear ();
                i_ass->get_assets (m_item);
                *count = i_ass->pv->ass_list.size ();
                return LXe_OK;
        }

        LXxO_InstanceAssets_IdentByIndex
        {
                if (index >= i_ass->pv->ass_list.size ())
                        return LXe_OUTOFBOUNDS;

                pv_InstanceAssets::assetEntry &ass = i_ass->pv->ass_list[index];
                *isSeq = (ass.isSeq ? 1 : 0);
                *fileType = ass.fileType.c_str();
                return lx::StringOut (ass.ident, buf, len);
        }

        LXxO_InstanceAssets_Category
        {
                if (index >= i_ass->pv->ass_list.size ())
                        return LXe_OUTOFBOUNDS;

                pv_InstanceAssets::assetEntry &ass = i_ass->pv->ass_list[index];
                if (ass.category.size() == 0)
                        return LXe_NOTFOUND;

                return lx::StringOut (ass.category, buf, len);
        }

        LXxO_InstanceAssets_GetPath
        {
                std::string path = i_ass->get_path (m_item, ident);
                return lx::StringOut (path, buf, len);
        }

        LXxO_InstanceAssets_SetPath
        {
                i_ass->set_path (m_item, ident, newPath);
                return LXe_OK;
        }
};

class meta_InstanceAssetsPolymorph :
                public CLxMetaPackagePolymorph<meta_InstanceAssets>
{
    public:
        pv_Meta_InstanceAssets	*mpv;

        meta_InstanceAssetsPolymorph (
                pv_Meta_InstanceAssets	*init)
        {
                this->AddInterface (new CLxIfc_InstanceAssets<meta_InstanceAssets>);
                mpv = init;
        }

                void
        inherit (
                meta_InstanceAssets	*that,
                CLxPackage		*pkg)		LXx_OVERRIDE
        {
                that->m_item.set (pkg->m_item);
                that->mpv   = mpv;
                that->i_ass = mpv->core->new_inst ();
        }
};

CLxMeta_InstanceAssets_Core::CLxMeta_InstanceAssets_Core ()
{
        m_type = LXsMETA_INTERFACE;
        cls_guid = &lx::guid_PackageInstance;

        mpv = new pv_Meta_InstanceAssets (this);
}

        void *
CLxMeta_InstanceAssets_Core::alloc ()
{
        return new meta_InstanceAssetsPolymorph (mpv);
}


