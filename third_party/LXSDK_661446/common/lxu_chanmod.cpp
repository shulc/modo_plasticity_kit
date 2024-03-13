/*
 * Plug-in SDK Source: Channel Modifier Utilities
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
 * Provides channel modifier utility classes.
 */
#include <lxu_chanmod.hpp>


/*
 * ------------------------------------------------------------
 * Channel Modifier Manager (& implicit Operator)
 *
 * Operator is self-contained, with its own instance of the manager.
 */
class meta_Operator :
                public CLxImpl_ChannelModOperator
{
    public:
        CLxChannelModManager	*man;

        LXxD_ChannelModOperator_Evaluate
        {
                man->eval ();
                return LXe_OK;
        }
};

/*
 * Common data for everything other than the operator includes the channel
 * description and the operator spawner.
 */
class pv_Meta_ChannelModManager
{
    public:
        CLxAttributeDesc		*attr_desc;
        CLxMeta_ChannelModManager_Core	*m_core;
        CLxPolymorph<meta_Operator>	 op_spawn;

        pv_Meta_ChannelModManager ()
        {
                op_spawn.AddInterface (new CLxIfc_ChannelModOperator<meta_Operator>);
        }
};

/*
 * The actual manager (sub-interface of Package) defines the channels and
 * allocates the operators. Each operator also gets its own manager instance.
 * Casting types changes pointers, so we get the raw pointer directly.
 */
class meta_ChannelModManager :
                public CLxImpl_ChannelModManager
{
    public:
        pv_Meta_ChannelModManager	*pv;

        LXxO_ChannelModManager_Define
        {
                return pv->attr_desc->chanmod_define (cmod);
        }

        LXxO_ChannelModManager_Allocate
        {
                CLxUser_ChannelModSetup	 setup (cmod);
                meta_Operator		*op;
                void			*ptr;

                op = pv->op_spawn.Alloc (ppvObj);
                op->man = pv->m_core->new_inst (&ptr);
                op->man->m_eval.set (setup.GetEvaluation ());

                pv->attr_desc->chanmod_bind (cmod, ptr);
                op->man->post_alloc ();
                return LXe_OK;
        }
};


/*
 * Manager polymorph.
 *
 * Just passes the core object pointer up to the manager instance.
 */
class meta_ChannelModManagerPolymorph :
                public CLxPolymorph<meta_ChannelModManager>
{
    public:
        pv_Meta_ChannelModManager	*pv;

        meta_ChannelModManagerPolymorph (
                pv_Meta_ChannelModManager	*init)
        {
                this->AddInterface (new CLxIfc_ChannelModManager<meta_ChannelModManager>);
                pv = init;
        }

                void *
        NewObj ()			 LXx_OVERRIDE
        {
                meta_ChannelModManager *man;

                man = new meta_ChannelModManager;
                man->pv = pv;
                return reinterpret_cast<void *> (man);
        }
};


/*
 * Core Methods.
 *
 * Declare self as interface for package. We allocate the spawner for
 * operators and find the channel attributes on alloc.
 */
CLxMeta_ChannelModManager_Core::CLxMeta_ChannelModManager_Core ()
{
        m_type = LXsMETA_INTERFACE;
        cls_guid = &lx::guid_Package;

        pv = new pv_Meta_ChannelModManager;
        pv->m_core = this;
}

CLxMeta_ChannelModManager_Core::~CLxMeta_ChannelModManager_Core ()
{
        delete pv;
}

        void *
CLxMeta_ChannelModManager_Core::alloc ()
{
        CLxMeta			*m;

        m = find_any (LXsMETA_ATTRDESC);
        if (m)
                pv->attr_desc = reinterpret_cast<CLxAttributeDesc *> (m->alloc ());

        return new meta_ChannelModManagerPolymorph (pv);
}


