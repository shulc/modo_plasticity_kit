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
#include <lxu_shade.hpp>
#include <lx_tableau.hpp>
#include <lx_vector.hpp>
#include <string>


/*
 * ------------------------------------------------------
 * Meta ValueTexture
 *
 * pv_Meta_Package is the common data allocate for the metaclass and shared by
 * all the other polymorphs and objects.
 */
class pv_Meta_ValueTexture
{
    public:
        CLxTagList		*tag_list;
        CLxAttributeDesc	*attr_desc;
        CLxMeta_ValueTexture_Core
                                *m_core;
        CLxMetaInterfaces	*srv_sub;
        std::string		 type_name;

        pv_Meta_ValueTexture ()
        {
                tag_list   = 0;
                attr_desc  = 0;
                m_core     = 0;
                srv_sub    = 0;
        }
};


/*
 * The ValueTexture server object implements the ValueTexture and Tags interfaces.
 */
class meta_ValueTextureServer :
                public CLxImpl_ValueTexture,
                public CLxImpl_TagDescription
{
    public:
        class pv_Meta_ValueTexture	*pv;
        CLxUser_PacketService		 pkt_S;
        CLxUser_NodalService		 nodal_S;
        unsigned			 idx_attach;
        unsigned			 tin_offset;

        class cData
        {
            public:
                CLxValueTexture		*base;
                CLxValueTexture		*sample;

                ~cData ()
                {
                        delete base;
                        delete sample;
                }
        };

        LXxO_ValueTexture_SetupChannels
        {
                return pv->attr_desc->setup_channels (addChan);
        }

        LXxO_ValueTexture_LinkChannels
        {
                tin_offset = pkt_S.GetOffset (LXsCATEGORY_SAMPLE, LXsP_TEXTURE_INPUT);
                idx_attach = pv->attr_desc->eval_attach (eval, item);
                return LXe_OK;
        }

        LXxO_ValueTexture_LinkSampleChannels
        {
                return pv->attr_desc->nodal_link (nodalEtor, item, idx);
        }

        LXxO_ValueTexture_IsSampleDriven
        {
                return pv->attr_desc->nodal_driven (idx);
        }

        LXxO_ValueTexture_ReadChannels
        {
                cData			*cx = new cData;

                cx->base   = pv->m_core->new_inst ();
                cx->sample = pv->m_core->new_inst ();

                pv->attr_desc->eval_read (attr, idx_attach, cx->base->struct_ptr ());
                ppvData[0] = cx;
                return LXe_OK;
        }

        LXxO_ValueTexture_Cleanup
        {
                cData			*cx = reinterpret_cast<cData *> (data);

                delete cx;
        }

        LXxO_ValueTexture_Customize
        {
                cData			*cx = reinterpret_cast<cData *> (ppvData[0]);
                CLxUser_ValueTextureCustom cust (custom);

                cx->base->customize (cust);
                return LXe_OK;
        }

        LXxO_ValueTexture_Setup
        {
                cData			*cx = reinterpret_cast<cData *> (data);

                cx->base->setup ();
                cx->sample->setup ();
                return LXe_OK;
        }

        LXxO_ValueTexture_Evaluate
        {
                cData			*cx = reinterpret_cast<cData *> (data);
                CLxPkt_TextureOutput	 pOut (tOut);
                CLxPkt_TextureInput	 pIn;
                LXpTextureInput		*tIn;

                pv->attr_desc->nodal_read (etor, idx, cx->sample->struct_ptr(), cx->base->struct_ptr());
                tIn = (LXpTextureInput *) pkt_S.FastPacket (vector, tin_offset);
                pIn.set (tIn);

                cx->sample->eval (vector, pIn, pOut);
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
class meta_ValueTexturePolymorph :
                public CLxPolymorph<meta_ValueTextureServer>
{
    public:
        class pv_Meta_ValueTexture	*pv;

        meta_ValueTexturePolymorph (
                class pv_Meta_ValueTexture	*ptr)
        {
                this->AddInterface (new CLxIfc_ValueTexture  <meta_ValueTextureServer>);
                this->AddInterface (new CLxIfc_TagDescription<meta_ValueTextureServer>);
                pv = ptr;
        }

                bool
        TestInterface (
                const LXtGUID		*iid)		LXx_OVERRIDE
        {
                if (pv->srv_sub->test (iid))
                        return true;

                return CLxGenericPolymorph::TestInterface (iid);
        }

                ILxUnknownID
        IsA (
                ILxUnknownID		 src,
                const LXtGUID		*iid)		LXx_OVERRIDE
        {
                CLxGenericPolymorph	*gp;

                gp = pv->srv_sub->find (iid);
                if (!gp)
                        return 0;

                return gp->Spawn ();
        }

                void *
        NewObj ()			 LXx_OVERRIDE
        {
                meta_ValueTextureServer *obj;

                obj = new meta_ValueTextureServer;
                obj->pv = pv;
                return reinterpret_cast<void *> (obj);
        }
};


/*
 * Package metaclass is the owner of the common private data. It defines itself
 * as a server of the Package type. PV data is set at create and again during
 * alloc when the whole meta tree is available.
 */
CLxMeta_ValueTexture_Core::CLxMeta_ValueTexture_Core (
        const char		*srvName)
                :
        CLxMetaServer (srvName)
{
        pv = new pv_Meta_ValueTexture;
        pv->m_core    = this;
        pv->tag_list  = &tag_list;
        pv->type_name = "val.";
        pv->type_name += srvName;

        cls_guid = &lx::guid_ValueTexture;
        has_channel_ui = false;
}

CLxMeta_ValueTexture_Core::~CLxMeta_ValueTexture_Core ()
{
        delete pv;
}

        bool
CLxMeta_ValueTexture_Core::pre_init ()
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
CLxMeta_ValueTexture_Core::alloc ()
{
        pv->srv_sub = get_ifcs (&lx::guid_ValueTexture);

        return reinterpret_cast<void *> (new meta_ValueTexturePolymorph (pv));
}

        const char *
CLxMeta_ValueTexture_Core::item_type ()
{
        return pv->type_name.c_str();
}


/*
 * ------------------------------------------------------
 * Meta VectorPacket (& PacketEffect)
 *
 * This consists of the public VectorPacket metaclass and the private
 * PackEffect metaclass. They're all related so let's pre-declare some pointers.
 */
class meta_PacketEffect_Server;
class meta_VectorPacket_Server;
class pv_Meta_VectorPacket;

/*
 * The private objects are related to the like-named server metaclasses.
 */
class pv_PacketEffect
{
    public:
        CLxTagList		*tag_list;
        pv_Meta_VectorPacket	*vp_pv;

        pv_PacketEffect ()
        {
                tag_list = 0;
                vp_pv    = 0;
        }

                void
        add_interfaces (
                CLxGenericPolymorph	*gp)
        {
                gp->AddInterface (new CLxIfc_PacketEffect  <meta_PacketEffect_Server>);
                gp->AddInterface (new CLxIfc_TagDescription<meta_PacketEffect_Server>);
        }
};

class pfxEffect
{
    public:
        std::string		 name, type;
        unsigned		 flags;
        size_t			 offset;
};

class pv_Meta_VectorPacket
{
    public:
        CLxTagList		*tag_list;
        CLxMeta_VectorPacket_Core
                                *m_core;
        CLxVectorPacket_Void	*v_type;
        const char		*srv_name;
        const char		*pfx_cat;
        std::vector<pfxEffect>	 pfx_list;
        pv_PacketEffect		 pe_pv;

        pv_Meta_VectorPacket ()
        {
                tag_list = 0;
                m_core   = 0;
                v_type   = 0;
                srv_name = 0;
                pfx_cat  = LXsSHADE_SURFACE;

                pe_pv.vp_pv = this;
        }

                void
        add_interfaces (
                CLxGenericPolymorph	*gp)
        {
                gp->AddInterface (new CLxIfc_VectorPacket  <meta_VectorPacket_Server>);
                gp->AddInterface (new CLxIfc_TagDescription<meta_VectorPacket_Server>);
        }
};

/*
 * The PacketEffect is a private server metaclass, so we declare the server and
 * the metaclass here.
 */
class meta_PacketEffect_Server :
                public CLxImpl_PacketEffect,
                public CLxImpl_TagDescription
{
    public:
        pv_PacketEffect	*pv;

        meta_PacketEffect_Server (
                pv_PacketEffect	*init = 0)
        {
                pv = init;
        }

        LXxO_PacketEffect_Packet
        {
                packet[0] = pv->vp_pv->srv_name;
                return LXe_OK;
        }

        LXxO_PacketEffect_Count
        {
                return pv->vp_pv->pfx_list.size ();
        }

        LXxO_PacketEffect_ByIndex
        {
                if (index < 0 || index >= pv->vp_pv->pfx_list.size ())
                        return LXe_OUTOFBOUNDS;

                pfxEffect &pfx = pv->vp_pv->pfx_list[index];
                name[0]     = pfx.name.c_str();
                typeName[0] = pfx.type.c_str();
                type[0]     = pfx.flags;
                return LXe_OK;
        }

                template <class T>
                T *
        struct_element (
                pfxEffect		&pfx,
                void			*packet)
        {
                char			*b;

                b = reinterpret_cast<char *> (packet);
                return reinterpret_cast<T *> (b + pfx.offset);
        }

        LXxO_PacketEffect_Get
        {
                if (index < 0 || index >= pv->vp_pv->pfx_list.size ())
                        return LXe_OUTOFBOUNDS;

                pfxEffect &pfx = pv->vp_pv->pfx_list[index];
                val[0] = struct_element<float> (pfx, packet) [0];
                return LXe_OK;
        }

        LXxO_PacketEffect_Set
        {
                if (index < 0 || index >= pv->vp_pv->pfx_list.size ())
                        return LXe_OUTOFBOUNDS;

                pfxEffect &pfx = pv->vp_pv->pfx_list[index];
                struct_element<float> (pfx, packet) [0] = val[0];
                return LXe_OK;
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

class meta_PacketEffect :
                public CLxMetaServer
{
    public:
        pv_PacketEffect		*pv;

        meta_PacketEffect (
                const char		*srvName,
                pv_Meta_VectorPacket	*vp)
                        :
                CLxMetaServer (srvName)
        {
                pv = &vp->pe_pv;
                pv->tag_list = &tag_list;

                cls_guid = &lx::guid_PacketEffect;
        }

                void *
        alloc ()
        {
                return reinterpret_cast<void *>
                        (  new CLxMetagenPolymorph<
                                meta_PacketEffect_Server,
                                pv_PacketEffect>
                           (pv)
                        );
        }
};

/*
 * The server object for the VectorPacket and Tags interfaces.
 */
class meta_VectorPacket_Server :
                public CLxImpl_VectorPacket,
                public CLxImpl_TagDescription
{
    public:
        pv_Meta_VectorPacket	*pv;

        meta_VectorPacket_Server (
                pv_Meta_VectorPacket	*init = 0)
        {
                pv = init;
        }

        LXxO_VectorPacket_Size
        {
                return pv->v_type->p_size ();
        }

        LXxO_VectorPacket_Interface
        {
                return 0;
        }

        LXxO_VectorPacket_Initialize
        {
                pv->v_type->v_init (packet);
                return LXe_OK;
        }

        LXxO_VectorPacket_Reset
        {
                pv->v_type->v_reset (packet);
        }

        LXxO_VectorPacket_Copy
        {
                pv->v_type->v_copy (packet, from);
                return LXe_OK;
        }

        LXxO_VectorPacket_Cleanup
        {
                pv->v_type->v_cleanup (packet);
        }

        LXxO_VectorPacket_Blend
        {
                pv->v_type->v_blend (packet, p0, p1, t, mode);
                return LXe_OK;
        }

        LXxO_VectorPacket_Invert
        {
                pv->v_type->v_invert (packet);
                return LXe_OK;
        }

        LXxO_VectorPacket_NodeCount
        {
                return 0;
        }

        LXxO_VectorPacket_NodeName
        {
                return LXe_NOTIMPL;
        }

        LXxO_VectorPacket_NodeType
        {
                return LXe_NOTIMPL;
        }

        LXxO_VectorPacket_NodeGet
        {
                return LXe_NOTIMPL;
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
 * Methods on the client's subclass populate the effect list.
 */
        void
CLxVectorPacket_Void::add_effect (
        const char		*name,
        const char		*type,
        int			 flags)
{
        pfxEffect		 pfx;

        pfx.name   = name;
        pfx.type   = type;
        pfx.flags  = flags;
        pfx.offset = 0;

        pv->pfx_list.push_back (pfx);
}

        void
CLxVectorPacket_Void::struct_offset (
        float			*offset)
{
        pv->pfx_list.back().offset = (size_t) offset;
}

/*
 * The metaclass is the owner of the common private data and the place where
 * the server factory is spawned.
 */
CLxMeta_VectorPacket_Core::CLxMeta_VectorPacket_Core (
        const char		*srvName)
                :
        CLxMetaServer (srvName)
{
        pv = new pv_Meta_VectorPacket;
        pv->tag_list = &tag_list;
        pv->m_core   = this;
        pv->srv_name = srvName;

        cls_guid = &lx::guid_VectorPacket;
}

CLxMeta_VectorPacket_Core::~CLxMeta_VectorPacket_Core ()
{
        if (pv->v_type)
                delete pv->v_type;

        delete pv;
}

        void
CLxMeta_VectorPacket_Core::self_init ()
{
        if (pv->v_type)
                return;

        pv->v_type = new_inst ();
        pv->v_type->pv = pv;
        add_tag (LXsVPK_CATEGORY, LXsCATEGORY_SAMPLE);
}

        void
CLxMeta_VectorPacket_Core::packet_category (
        const char		*cat)
{
        self_init ();
        add_tag (LXsVPK_CATEGORY, cat);
}

        void
CLxMeta_VectorPacket_Core::effect_category (
        const char		*cat)
{
        self_init ();
        pv->pfx_cat = cat;
}

        bool
CLxMeta_VectorPacket_Core::pre_init ()
{
        self_init ();

        pv->v_type->define_effects ();
        if (pv->pfx_list.size () > 0)
        {
                meta_PacketEffect *pfx_meta = new meta_PacketEffect (m_name.c_str(), pv);

                pfx_meta->add_tag (LXsTFX_CATEGORY, pv->pfx_cat);
                add (pfx_meta);
        }
        return false;
}

        void *
CLxMeta_VectorPacket_Core::alloc ()
{
        self_init ();

        return reinterpret_cast<void *>
                (  new CLxMetagenPolymorph<
                        meta_VectorPacket_Server,
                        pv_Meta_VectorPacket>
                   (pv)
                );
}



