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
 * Helper classes for implementing texture servers.
 */
#ifndef LXU_SHADE_HPP
#define LXU_SHADE_HPP

#include <lx_shade.hpp>
#include <lxu_package.hpp>


/*
 * -------------------------------------
 * Packet Wrappers
 *
 * Wrappers for a couple of the most common shading packets.
 */
template <class P>
class CLxPacketWrapper
{
    public:
        P		*m_pkt;

        CLxPacketWrapper ()		{ m_pkt = 0; }
        CLxPacketWrapper (P *p)		{ m_pkt = p; }

        void	set (P *p)		{ m_pkt = p; }

              P* operator-> ()		{ return m_pkt; }
        const P* operator-> () const	{ return m_pkt; }
};

class CLxPkt_TextureInput :
                public CLxPacketWrapper<LXpTextureInput>
{
    public:
        CLxPkt_TextureInput () {}
        CLxPkt_TextureInput (LXpTextureInput *p) : CLxPacketWrapper<LXpTextureInput> (p) {}
};

class CLxPkt_TextureOutput :
                public CLxPacketWrapper<LXpTextureOutput>
{
    public:
        CLxPkt_TextureOutput () {}
        CLxPkt_TextureOutput (LXpTextureOutput *p) : CLxPacketWrapper<LXpTextureOutput> (p) {}

                void
        Set (
                double		 value,
                double		 alpha = 1.0)
        {
                m_pkt->direct = 1;
                m_pkt->value[0] = value;
                LXx_VSET (m_pkt->color[0], value);
                m_pkt->alpha[0] = alpha;
        }

                template <class F>
                void
        Set (
                const F		*color,
                double		 alpha = 1.0)
        {
                m_pkt->direct = 1;
                m_pkt->value[0] = LXx_VLEN (color);
                LXx_VCPY (m_pkt->color[0], color);
                m_pkt->alpha[0] = alpha;
        }

                void
        Blend (
                double		 blend,
                double		 value0,
                double		 value1,
                double		 alpha0 = 1.0,
                double		 alpha1 = 1.0)
        {
                m_pkt->direct = 0;
                m_pkt->value[0] = value0;
                m_pkt->value[1] = value1;
                LXx_VSET (m_pkt->color[0], value0);
                LXx_VSET (m_pkt->color[1], value1);
                m_pkt->alpha[0] = alpha0;
                m_pkt->alpha[1] = alpha1;
        }

                template <class F>
                void
        Blend (
                double		 blend,
                const F		*color0,
                const F		*color1,
                double		 alpha0 = 1.0,
                double		 alpha1 = 1.0)
        {
                m_pkt->direct = 0;
                m_pkt->value[0] = LXx_VLEN (color0);
                m_pkt->value[1] = LXx_VLEN (color1);
                LXx_VCPY (m_pkt->color[0], color0);
                LXx_VCPY (m_pkt->color[1], color1);
                m_pkt->alpha[0] = alpha0;
                m_pkt->alpha[1] = alpha1;
        }
};

class CLxPkt_ShadeComponents :
                public CLxPacketWrapper<LXpShadeComponents>
{
    public:
        CLxPkt_ShadeComponents () {}
        CLxPkt_ShadeComponents (LXpShadeComponents *p) : CLxPacketWrapper<LXpShadeComponents> (p) {}
};

class CLxPkt_ShadeOutput :
                public CLxPacketWrapper<LXpShadeOutput>
{
    public:
        CLxPkt_ShadeOutput () {}
        CLxPkt_ShadeOutput (LXpShadeOutput *p) : CLxPacketWrapper<LXpShadeOutput> (p) {}
};

class CLxPkt_ShadeFlags :
                public CLxPacketWrapper<LXpShadeFlags>
{
    public:
        CLxPkt_ShadeFlags () {}
        CLxPkt_ShadeFlags (LXpShadeFlags *p) : CLxPacketWrapper<LXpShadeFlags> (p) {}
};


/*
 * -------------------------------------
 * Meta Value Texture
 *
 * The meta texture supports basic behaviors and some customization.
 */
class CLxValueTexture :
                public CLxObject
{
    public:
        virtual void	setup () {}
        virtual void	customize (CLxUser_ValueTextureCustom &) {}
        virtual void *	struct_ptr () = 0;
        virtual void	eval (ILxUnknownID vector, CLxPkt_TextureInput &tIn, CLxPkt_TextureOutput &tOut) = 0;
};

/*
 * Core metaclass is declared with a server name, and can have server tags.
 */
class CLxMeta_ValueTexture_Core :
                public CLxMetaServer
{
    public:
        CLxMeta_ValueTexture_Core (const char *srvName);

        /*
         * Get the item type name for the texture layer.
         */
        const char *	 item_type ();

        /*
         * Add a ChannelUI interface using the given CLxChannelUI subclass.
         */
                template <class T>
                void
        add_channel_ui ()
        {
                CLxMeta	*m = new CLxMeta_ChannelUI<T>;
                m->cls_guid = &lx::guid_ValueTexture;
                add (m);
                has_channel_ui = true;
        }

        /*
         * Internal methods.
         */
        ~CLxMeta_ValueTexture_Core ();

        virtual CLxValueTexture *	 new_inst () = 0;

        void *		 alloc () LXx_OVERRIDE;
        bool		 pre_init () LXx_OVERRIDE;

        class pv_Meta_ValueTexture *pv;
        bool			has_channel_ui;
};

/*
 * Template for client metaclass. All methods are internal.
 */
template <class T>
class CLxMeta_ValueTexture :
                public CLxMeta_ValueTexture_Core
{
    public:
        CLxMeta_ValueTexture (const char *srvName) : CLxMeta_ValueTexture_Core (srvName) { }

                CLxValueTexture *
        new_inst ()
        {
                return new T;
        }
};


/*
 * -------------------------------------
 * Meta Vector Packet & Effect
 *
 * Vector Packets must be defined as structs. They are not objects, and will
 * be allocated as blocks of memory by the sample vector system. As such the
 * design of the metaclass is a bit unusual. The client's class derives from
 * The CLxVectorPacket template, which is parameterized by the packet struct.
 *
 * Any vector packet will generally have an effect as well, so these two
 * server types are implemented by the same metaclass.
 */
class CLxVectorPacket_Void :
                public CLxObject
{
    public:
        /*
         * Define the effects for the packet. These are added one by one with
         * add_effect(). struct_offset() is called to set the data member
         * offset relative to a null pointer.
         */
        virtual void	define_effects () {}

        void		add_effect (const char *, const char *, int flags = LXi_TFX_SCALAR | LXf_TFX_READ | LXf_TFX_WRITE);
        void		struct_offset (float *);

    //internal:
        virtual size_t	p_size () = 0;
        virtual void	v_init (void *) = 0;
        virtual void	v_cleanup (void *) = 0;
        virtual void	v_reset (void *) = 0;
        virtual void	v_copy (void *, void *) = 0;
        virtual void	v_blend (void *, void *, void *, float, int) = 0;
        virtual void	v_invert (void *) = 0;

        class pv_Meta_VectorPacket *pv;
};

template <class P>
class CLxVectorPacket :
                public CLxVectorPacket_Void
{
    public:
        virtual	void	init (P *) = 0;

        virtual	void	cleanup (P *p) {}

        virtual	void	reset (P *p)
        {
                init (p);
        }

        virtual void	copy (P *p, const P *f)
        {
                memcpy (p, f, p_size ());
        }

        virtual void	blend (P *p, const P *p0, const P *p1, float t, int mode) {}

        virtual void	invert (P *) {}

    //internal:
        size_t	p_size () LXx_OVERRIDE
        {
                return sizeof (P);
        }

        void	v_init (void *p) LXx_OVERRIDE
        {
                init ((P *) p);
        }

        void	v_cleanup (void *p) LXx_OVERRIDE
        {
                cleanup ((P *) p);
        }

        void	v_reset (void *p) LXx_OVERRIDE
        {
                reset ((P *) p);
        }

        void	v_copy (void *p, void *f) LXx_OVERRIDE
        {
                copy ((P *) p, (const P *) f);
        }

        void	v_blend (void *p, void *p0, void *p1, float t, int mode) LXx_OVERRIDE
        {
                blend ((P *) p, (const P *) p0, (const P *) p1, t, mode);
        }

        void	v_invert (void *p) LXx_OVERRIDE
        {
                invert ((P *) p);
        }
};

/*
 * Core metaclass is declared with a server name, and can have additional
 * server tags.
 */
class CLxMeta_VectorPacket_Core :
                public CLxMetaServer
{
    public:
        CLxMeta_VectorPacket_Core (const char *srvName);

        /*
         * Set the cateory for the packet. The default is "sample".
         */
        void		 packet_category (const char *);

        /*
         * Set the cateory for the effects. The default is "surface".
         */
        void		 effect_category (const char *);

    //internal:
        ~CLxMeta_VectorPacket_Core ();

        virtual CLxVectorPacket_Void *	 new_inst () = 0;

        void *		 alloc () LXx_OVERRIDE;
        bool		 pre_init () LXx_OVERRIDE;
        void		 self_init ();

        class pv_Meta_VectorPacket *pv;
};

/*
 * Template for client metaclass. All methods are internal.
 */
template <class T>
class CLxMeta_VectorPacket :
                public CLxMeta_VectorPacket_Core
{
    public:
    //internal:
        CLxMeta_VectorPacket (const char *srvName) : CLxMeta_VectorPacket_Core (srvName) { }

                CLxVectorPacket_Void *
        new_inst ()		LXx_OVERRIDE
        {
                return new T;
        }
};


#endif // LXU_SHADE_HPP

