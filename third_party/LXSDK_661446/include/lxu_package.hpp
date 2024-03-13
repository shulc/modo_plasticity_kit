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
 * Helper classes for implementing package servers.
 */
#ifndef LXU_PACKAGE_HPP
#define LXU_PACKAGE_HPP

#include <lx_item.hpp>
#include <lxu_package.hpp>
#include <lxu_attrdesc.hpp>
#include <lxu_vector.hpp>
#include <lx_channelui.hpp>
#include <lx_vmodel.hpp>
#include <lx_draw.hpp>


/*
 * -------------------------------------
 * - Default Package
 *
 * The default package just provides methods to allocate a default package
 * instance that does nothing. This is useful if the functionality of your
 * item is not located in the instance.
 */
class CLxDefaultPackage :
                public CLxImpl_Package
{
    public:
        class Spawner :
                public CLxSpawnerCreate<CLxImpl_PackageInstance>
        {
            public:
                Spawner () : CLxSpawnerCreate<CLxImpl_PackageInstance> ("default_pkg_inst")
                {
                        if (created)
                                AddInterface (new CLxIfc_PackageInstance<CLxImpl_PackageInstance>);
                }
        };

        LXxO_Package_Attach;
        LXxO_Package_TestInterface;
};


/*
 * -------------------------------------
 * - Channel UI Interface
 *
 * This class allows clients to define Channel UI interface for attachment
 * to other servers.
 */
class CLxChannelUI
{
    public:
        /*
         * Implement to set an entire item as disabled in the UI.
         */
        virtual bool		 item_enabled (CLxUser_Item &, CLxUser_Message &) { return true; }

        /*
         * Implement to return a computed icon for the item.
         */
        virtual const char *	 item_icon (CLxUser_Item &) { return 0; }
};

class CLxMeta_ChannelUI_Core :
                public CLxMeta
{
    public:
    //internal:
         CLxMeta_ChannelUI_Core ();
        ~CLxMeta_ChannelUI_Core ();

        virtual CLxChannelUI *	 new_inst () = 0;
        void *			 alloc () LXx_OVERRIDE;

        class pv_Meta_ChannelUI *pv;
};

template <class T>
class CLxMeta_ChannelUI :
                public CLxMeta_ChannelUI_Core
{
    public:
    //internal:
                CLxChannelUI *
        new_inst ()
        {
                return new T;
        }
};


/*
 * -------------------------------------
 * - Meta Package
 *
 * The Package class supports basic behaviors and some customization for
 * item instances.
 */
class CLxPackage
{
    public:
        CLxUser_Item	m_item;

        /*
         * Implement to initialize the instance. The package instance from
         * the item's supertype is also provided.
         */
        virtual void	initialize (ILxUnknownID super) {}

        /*
         * Implement to handle a new item being created. If 'original' is set
         * then this was a type conversion.
         */
        virtual void	newborn (CLxUser_Item &original, int flags) {}

        /*
         * Implement to handle loading this item/package.
         */
        virtual void	loading () {}

        /*
         * Implement to update the item/package after loading.
         */
        virtual void	after_load () {}

        /*
         * Implement to handle when the item/package is to be destroyed.
         */
        virtual void	doomed () {}

        /*
         * Implement to handle when the item/package is added to a scene.
         */
        virtual void	add () {}

        /*
         * Implement to handle when the item/package is removed from a scene.
         */
        virtual void	remove () {}

        /*
         * Implement to compute a synthetic name for the item.
         */
        virtual void	synth_name (std::string &name) {}

        /*
         * Implement to test if this item can be parented to another item.
         */
        virtual bool	parent_ok  (CLxUser_Item &parent) { return true; }
};

/*
 * Core metaclass can have a supertype and other server tags.
 */
class CLxMeta_Package_Core :
                public CLxMetaServer
{
    public:
        /*
         * Set the package name on declaration.
         */
        CLxMeta_Package_Core (const char *srvName);

        /*
         * Set the supertype for this package. If unset the package will be
         * standalone rather than an item type. Leaving off the argument makes
         * this a root item type.
         */
        void		 set_supertype (const char * = ".");

        /*
         * Add a ChannelUI package using the CLxChannelUI class or a
         * custom subclass.
         */
                template <class T>
                void
        add_channel_ui ()
        {
                add (new CLxMeta_ChannelUI<T>);
                has_channel_ui = true;
        }

  //internal:
        ~CLxMeta_Package_Core ();

        virtual CLxPackage *	 new_inst () = 0;
        void *			 alloc () LXx_OVERRIDE;
        bool			 pre_init () LXx_OVERRIDE;

        class pv_Meta_Package	*pv;
        bool			 has_channel_ui;
};

/*
 * Template for client metaclass.
 */
template <class T>
class CLxMeta_Package :
                public CLxMeta_Package_Core
{
    public:
        CLxMeta_Package (const char *srvName) : CLxMeta_Package_Core (srvName) {}

                CLxPackage *
        new_inst ()
        {
                return new T;
        }
};


//@skip
/*
 * -------------------------------------
 * Meta Package Interfaces
 *
 * This is an internal class used to declare polymorphs for interface
 * extentions to the package instance.
 */
template <class T, class P = CLxPackage>
class CLxMetaPackagePolymorph :
                public CLxPolymorph<T>
{
    public:
        virtual void	 inherit (T *, P *) = 0;

                void
        InitObj (
                void			*obj1,
                void			*obj2)
                                                        LXx_OVERRIDE
        {
                CLxPackage		*pkg;

                pkg = reinterpret_cast<CLxPackage *> (obj2);
                inherit ((T *) obj1, dynamic_cast<P *> (pkg));
        }
};


//@read
/*
 * Any subclass of ViewItem3D can be made into a metaclass as
 * an interface on the normal package.
 */
class CLxViewItem3D
{
    public:
        /*
         * Implement to draw this item in the 3D viewport. Channel values are given
         * by the channel-read object, and the stroke-draw object is used to render.
         */
        virtual void	draw     (CLxUser_Item &, CLxUser_ChannelRead &, CLxUser_StrokeDraw &, int selFlags, const CLxVector &color) {}

        /*
         * Implement to hit-test this item. The stroke-draw is used to render
         * the shape, but they are used for testing.
         */
        virtual void	drawtest (CLxUser_Item &, CLxUser_ChannelRead &, CLxUser_StrokeDraw &, int selFlags) {}

        /*
         * Implement to draw this item in the background.
         */
        virtual void	drawbg   (CLxUser_Item &, CLxUser_ChannelRead &, CLxUser_StrokeDraw &) {}
};

class CLxMeta_ViewItem3D_Core :
                public CLxMeta
{
    public:
        /*
         * Set drawing to world space.
         */
        void	set_world_space (bool world = true);

        /*
         * Enable background drawing.
         */
        void	enable_background ();

        /*
         * Enable alternate testing.
         */
        void	enable_test ();

    //internal:
        CLxMeta_ViewItem3D_Core ();

        class pv_Meta_ViewItem3D	*pv;

        virtual CLxViewItem3D *	 new_inst () = 0;
        void *			 alloc () LXx_OVERRIDE;
};

template <class T>
class CLxMeta_ViewItem3D :
                public CLxMeta_ViewItem3D_Core
{
    public:
    //internal:
                CLxViewItem3D *
        new_inst ()
        {
                return new T;
        }
};


/*
 * The Instance Assets interface allows items to present external file
 * references.
 */
class CLxInstanceAssets
{
    public:
        /*
         * Implement to enumerate the assets for an item. Calls add-asset() for
         * each asset on the item.
         */
        virtual void	get_assets (CLxUser_Item &) = 0;

        /*
         * Call to add an asset during enumeration. Each has a unique ident, and
         * the filetype is also required. Assets are assumed to be file paths
         * unless isSeq is set, in which case they are patterns.
         */
        void		add_asset (const char *ident, const char *fileType, const char *category = 0, bool isSeq = false);

        /*
         * Implement to return the current asset path given item and ident.
         */
        virtual std::string
                        get_path (CLxUser_Item &, const char *ident) = 0;

        /*
         * Implement to change the current asset path given item and ident. This
         * should change the asset path by doing direct edits, not through commands.
         */
        virtual void	set_path (CLxUser_Item &, const char *ident, const char *path) = 0;

    //internal:
         CLxInstanceAssets ();
        ~CLxInstanceAssets ();

        class pv_InstanceAssets	*pv;
};

class CLxMeta_InstanceAssets_Core :
                public CLxMeta
{
    public:
    //internal:
        CLxMeta_InstanceAssets_Core ();

        class pv_Meta_InstanceAssets	*mpv;

        virtual CLxInstanceAssets *	 new_inst () = 0;
        void *			 alloc () LXx_OVERRIDE;
};

template <class T>
class CLxMeta_InstanceAssets :
                public CLxMeta_InstanceAssets_Core
{
    public:
    //internal:
                CLxInstanceAssets *
        new_inst ()
        {
                return new T;
        }
};

#endif // LXU_PACKAGE_HPP

