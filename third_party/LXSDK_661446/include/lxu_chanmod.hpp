/*
 * Plug-in SDK Header: Channel Modifier Utilities
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
 * Provides utility classes for creating channel modifier servers.
 */
//@title Channel Modifiers

#ifndef LXU_CHANMOD_HPP
#define LXU_CHANMOD_HPP

#include <lx_chanmod.hpp>
#include <lxu_package.hpp>
#include <lxu_attrdesc.hpp>
#include <lxidef.h>

/*
 * ---------------------
 * -- Channel Modifier
 *
 * This defines a ChannelModManager on a package.
 */
class CLxChannelModManager
{
    public:
        CLxUser_Evaluation	m_eval;

        /*
         * Implement to read inputs and write outputs from your values.
         */
        virtual void		eval () = 0;

        /*
         * Implement to optionally set up more values after initial binding.
         */
        virtual void		post_alloc () {}
};

/*
 * -- Internal core class -- no user methods.
 */
class CLxMeta_ChannelModManager_Core :
                public CLxMeta
{
    public:
    //internal:
         CLxMeta_ChannelModManager_Core ();
        ~CLxMeta_ChannelModManager_Core ();

        virtual CLxChannelModManager *	 new_inst (void **) = 0;
        void *				 alloc ()	LXx_OVERRIDE;

        class pv_Meta_ChannelModManager *pv;
};

/*
 * Metaclass template for exposing a CLxChannelModManager class as a
 * ChannelModManager interface on a package.
 */
template <class T>
class CLxMeta_ChannelModManager :
                public CLxMeta_ChannelModManager_Core
{
    public:
    //internal:
                CLxChannelModManager *
        new_inst (
                void		       **ptr)		LXx_OVERRIDE
        {
                T *t = new T;

                ptr[0] = reinterpret_cast<void *> (t);
                return t;
        }
};


/*
 * Composite class combining channels, manager and package can be created by
 * deriving from CLxChannelModManager and adding a method for initializing the
 * channel description.
 */
class CLxChannelModifier :
                public CLxChannelModManager
{
    public:
        /*
         * Define the channels for this modifier node.
         */
        virtual void	 init_chan (CLxAttributeDesc &) = 0;
};

/*
 * The metaclass takes two template arguments. The first is a CLxChannelModifier,
 * and the second is an optional class to customize the package.
 */
template <class M, class P = CLxPackage>
class CLxMeta_ChannelModifier :
                public CLxMeta
{
    public:
    //internal:
        class cChannels : public CLxChannels
        {
            public:
                void init_chan (CLxAttributeDesc &desc) LXx_OVERRIDE
                {
                        M tmp;
                        tmp.init_chan (desc);
                }
        };

        CLxMeta_Channels<cChannels>	 channels;
        CLxMeta_ChannelModManager<M>	 manager;
        CLxMeta_Package<P>		 package;

        /*
         * Set the channel modifier server name in the constructor.
         */
        CLxMeta_ChannelModifier (const char *srvName) :
                        package (srvName)
        {
                add (&channels);
                add (&package);

                package.set_supertype (LXsITYPE_CHANMODIFY);
                package.add (&manager);
        }
};

/*
 * This is the same as [[CLxMeta_ChannelModifier (class)]] but it's implemented
 * as a root object. This means it can be declared standalone.
 */
template <class M, class P = CLxPackage>
class CLxMetaRoot_ChannelModifier :
                public CLxMetaRoot
{
    public:
        CLxMeta_ChannelModifier<M,P>	 chan_mod;

        /*
         * Set the channel modifier server name in the constructor.
         */
        CLxMetaRoot_ChannelModifier (const char *srvName) :
                        chan_mod (srvName)
        {
                add (&chan_mod);
        }
};


#endif // LXU_CHANMOD_HPP

