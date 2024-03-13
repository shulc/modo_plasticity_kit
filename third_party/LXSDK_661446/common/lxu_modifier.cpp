/*
 * Plug-in SDK Source: Modifier Wrappers
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
 * Implements modifier wrapper classes.
 */
#include <lxu_modifier.hpp>

using namespace lx_err;


/*
 * -----------------------------------------------------------
 * Utilities
 */
class CChannelInfo
{
    public:
        CLxUser_Item		 item;
        unsigned		 index, type;

                bool
        operator== (
                const CChannelInfo	&rhs) const
        {
                return (item == rhs.item && index == rhs.index && type == rhs.type);
        }
};

class CChannelList :
                public std::vector<CChannelInfo>
{
    public:
                void
        add (
                CLxUser_Item		 item,
                unsigned		 index,
                unsigned		 type)
        {
                CChannelInfo		 proto;

                proto.item  = item;
                proto.index = index;
                proto.type  = type;
                push_back (proto);
        }
};


/*
 * -----------------------------------------------------------
 * Common Modifier
 *
 * The core class implements the private data that stores the settings
 * that the client has set on their implmentation, plus settings determined
 * from the meta tree.
 */
class pv_EvalModifier;
static CLxPolymorph<pv_EvalModifier> * alloc_ModSpawn (CLxMetaInterfaces *);

class pv_Meta_EvalModifier
{
    public:
        CLxAttributeDesc	*attr_desc;
        CLxMetaServer		*self_srv;
        CLxMeta			*alt_eval;
        CLxPolymorph<pv_EvalModifier>
                                *mod_spawn;

        std::string		 item_type;
        std::set<std::string>	 dep_types, dep_graphs;
        bool			 has_type, all_types, has_custom;

        pv_Meta_EvalModifier ()
        {
                attr_desc  = 0;
                self_srv   = 0;
                alt_eval   = 0;
                mod_spawn  = 0;
                has_type   = false;
                has_custom = false;
                all_types  = false;
        }

                void
        add_list_string (
                std::set<std::string>	&list,
                const char		*name)
        {
                std::string val (name);
                list.insert (val);
        }

                void
        set_type (
                const char		*name)
        {
                item_type = name;
                has_type  = true;

                add_list_string (dep_types, name);
        }

        /*
         * From the meta object we look for a package server and assume that's
         * our item type (if none already set). We also get the attrdesc data,
         * and the meta object for any alternate evaluation.
         */
                void
        set_meta (
                CLxMetaServer		*meta)
        {
                if (self_srv)
                        return;

                self_srv = meta;

                if (!has_type)
                {
                        CLxMeta *pkg = meta->find_any (LXsMETA_SERVER, &lx::guid_Package);
                        if (pkg)
                                set_type (pkg->m_name.c_str());
                }

                CLxMeta *attr = meta->find_any (LXsMETA_ATTRDESC);
                if (attr)
                        attr_desc = reinterpret_cast<CLxAttributeDesc*> (attr->alloc ());

                alt_eval = meta->find_sub (LXsMETA_EVALUATOR);

                mod_spawn = alloc_ModSpawn (meta->get_ifcs (&lx::guid_Modifier));
        }
};

CLxMeta_EvalModifier_Core::CLxMeta_EvalModifier_Core (
        const char		*srvName)
                :
        CLxMetaServer (srvName)
{
        pv = new pv_Meta_EvalModifier;
}

CLxMeta_EvalModifier_Core::~CLxMeta_EvalModifier_Core ()
{
        delete pv;
}

/*
 * The client can give us hints about the modifier, and request that it
 * traverse all items not just items of our type.
 */
        void
CLxMeta_EvalModifier_Core::set_itemtype (
        const char		*typeName)
{
        pv->set_type (typeName);
}

        void
CLxMeta_EvalModifier_Core::add_dependent_type (
        const char		*typeName)
{
        pv->add_list_string (pv->dep_types, typeName);
        pv->has_custom = true;
}

        void
CLxMeta_EvalModifier_Core::add_dependent_graph (
        const char		*graph)
{
        pv->add_list_string (pv->dep_graphs, graph);
        pv->has_custom = true;
}

        void
CLxMeta_EvalModifier_Core::get_all_items ()
{
        pv->all_types = true;
}

        void
CLxMeta_EvalModifier_Core::invalidate (
        CLxUser_Scene		&scene,
        bool			 reset)
{
        if (reset)
                scene.EvalModReset (pv->self_srv->m_name.c_str());
        else
                scene.EvalModInvalidate (pv->self_srv->m_name.c_str());
}

        void
CLxMeta_EvalModifier_Core::invalidate (
        CLxUser_Item		&item,
        bool			 reset)
{
        CLxUser_Scene		 us;

        us.from (item);
        invalidate (us, reset);
}

        void
CLxMeta_EvalModifier_Core::invalidate (
        ILxUnknownID		 scene,
        bool			 reset)
{
        CLxUser_Scene		 us (scene);

        invalidate (us, reset);
}


/*
 * The modifier node for the common modifier implements the test and
 * evaluation methods.
 */
class pv_EvalModifier :
                public CLxImpl_Modifier
{
    public:
        CLxMeta_EvalModifier_Core	*m_core;
        pv_Meta_EvalModifier		*m_cpv;
        CLxEvalModifier			*m_com;

        CLxUser_Item			 m_item;
        CLxUser_Evaluation		 m_eval;
        CLxUser_Attributes		 m_attr;
        unsigned			 m_index;

        CLxEvalModifier_Evaluator	*alt_eval;
        CChannelList			 cust_chan;
        unsigned			 obj_index, base_desc, base_cust;
        LxResult			 res_value;

        pv_EvalModifier ()
        {
                m_core = 0;
                m_cpv = 0;
                m_com = 0;
                alt_eval = 0;
        }

                void
        init (
                CLxMeta_EvalModifier_Core *core,
                ILxUnknownID		 item,
                unsigned		 index)
        {
                m_core = core;
                m_cpv  = core->pv;
                m_com  = core->new_inst ();
                m_com->pmod = this;

                check (m_item.set (item));
                m_index = index;
        }

                void
        set_eval (
                ILxUnknownID		 eval)
        {
                check (m_eval.set (eval));
                check (m_attr.set (eval));
        }

                void
        bind_chans (
                bool			 isReal)
        {
                if (isReal && m_cpv->alt_eval)
                {
                        alt_eval = reinterpret_cast<CLxEvalModifier_Evaluator *> (m_cpv->alt_eval->alloc ());
                        alt_eval->bind (*m_com);
                }

                m_com->bind (m_item, m_index);
        }

                void
        link_chans ()
        {
                CChannelInfo		*ci;
                unsigned		 index;
                int			 i, n;

                if (m_cpv->attr_desc)
                        base_desc = m_cpv->attr_desc->eval_attach (m_eval, m_item);

                n = cust_chan.size ();
                for (i = 0; i < n; i++)
                {
                        ci = &cust_chan[i];
                        check (m_eval.AddChannel (ci->item, ci->index, ci->type, &index));
                        if (i == 0)
                                base_cust = index;
                }
        }

                void
        bind_and_link (
                ILxUnknownID		 eval)
        {
                set_eval (eval);
                bind_chans (true);
                link_chans ();
        }

        LXxO_Modifier_Evaluate
        {
                res_value = LXe_OK;
                if (alt_eval)
                        alt_eval->eval (*m_com);
                else
                        m_com->eval ();

                return res_value;
        }

        LXxO_Modifier_Test
        {
                if (!m_com->change_test ())
                        return LXe_FALSE;

                if (!m_cpv->has_custom)
                        return LXe_TRUE;

                pv_EvalModifier	 tpv;

                tpv.init (m_core, m_item, m_index);
                tpv.bind_chans (false);

                bool ok = (cust_chan == tpv.cust_chan);
                return (ok ? LXe_TRUE : LXe_FALSE);
        }

        LXxO_Modifier_Validate
        {
                return LXe_NOTIMPL;
        }

        LXxO_Modifier_Free
        {
                delete reinterpret_cast<CLxObject *> (cache);
        }
};


class polymorph_Modifier :
                public CLxExtendedPolymorph<pv_EvalModifier>
{
    public:
        polymorph_Modifier (
                CLxMetaInterfaces	*ifcs)
                        :
                CLxExtendedPolymorph<pv_EvalModifier> (ifcs)
        {
                AddInterface (new CLxIfc_Modifier<pv_EvalModifier>);
        }

                void *
        RefObj (
                void			*obj)		LXx_OVERRIDE
        {
                pv_EvalModifier		*inst = (pv_EvalModifier *) obj;

                return (void *) inst->m_com;
        }
};

        static CLxPolymorph<pv_EvalModifier> *
alloc_ModSpawn (
        CLxMetaInterfaces		*ifcs)
{
        return new polymorph_Modifier (ifcs);
}


/*
 * Internal class -- nothing to see here.
 */
class metaServer_EvalModifier :
                public CLxImpl_EvalModifier,
                public CLxImpl_TagDescription,
                public CLxObject
{
    public:
         metaServer_EvalModifier ();
        ~metaServer_EvalModifier ();

        LXxO_EvalModifier_Reset;
        LXxO_EvalModifier_Next;
        LXxO_EvalModifier_Alloc;

        LXxO_TagDescription_Count;
        LXxO_TagDescription_Describe;

        void		init (CLxMeta_EvalModifier_Core *);

        class pv_EvalModifier_Server *pv;
};


class metaPolymorph_EvalModifier :
                public CLxPolymorph<metaServer_EvalModifier>
{
    public:
        CLxMeta_EvalModifier_Core *core;

        metaPolymorph_EvalModifier ()
        {
                this->AddInterface (new CLxIfc_EvalModifier  <metaServer_EvalModifier>);
                this->AddInterface (new CLxIfc_TagDescription<metaServer_EvalModifier>);
        }

                void *
        NewObj ()
                                                 LXx_OVERRIDE
        {
                metaServer_EvalModifier	 *mod;

                mod = new metaServer_EvalModifier;
                mod->init (core);
                return reinterpret_cast<void *> (mod);
        }
};

        void *
CLxMeta_EvalModifier_Core::alloc ()
{
        metaPolymorph_EvalModifier	*srv;

        srv = new metaPolymorph_EvalModifier ();
        srv->core = this;
        return reinterpret_cast<void *> (srv);
}


/*
 * The server for the common modifier handles tags and item iteration.
 */
class pv_EvalModifier_Server
{
    public:
        CLxMeta_EvalModifier_Core	*core;
        CLxEvalModifier			*com;
        CLxTagList			*tag_list;

        pv_EvalModifier_Server (
                CLxMeta_EvalModifier_Core	*cp)
        {
                core  = cp;
                com   = cp->new_inst ();
                com->psrv = this;

                tag_list = 0;

                core->pv->set_meta (cp);
        }

        /*
         * The server tags are created dynamically the first time they're
         * needed. This allows us to respond to user flags.
         */
                static void
        get_list (
                std::set<std::string>	&list,
                std::string		&str)
        {
                for (std::set<std::string>::iterator it = list.begin(); it != list.end(); ++it)
                {
                        if (str.length ())
                                str += " ";

                        str += *it;
                }
        }

                void
        init_tags ()
        {
                if (tag_list)
                        return;

                tag_list = &core->pv->self_srv->tag_list;

                std::string		 str;

                get_list (core->pv->dep_types, str);
                if (str.length ())
                        tag_list->add (LXsMOD_TYPELIST, str.c_str());

                str = "";
                get_list (core->pv->dep_graphs, str);
                if (str.length ())
                        tag_list->add (LXsMOD_GRAPHLIST, str.c_str());

                if (core->pv->has_type && !core->pv->all_types)
                        tag_list->add (LXsMOD_REQUIREDTYPE, core->pv->item_type.c_str());
        }

        CLxUser_SceneService	 scene_S;
        CLxUser_Scene		 iter_scene;
        unsigned		 iter_type;
        unsigned		 iter_num, iter_cur;

                bool
        include_by_type ()
        {
                return !core->pv->all_types;
        }

        /*
         * The reset/next methods for item-type based enumeration. We
         * include exactly one node for each item of this type.
         */
                void
        reset_item ()
        {
                iter_type = scene_S.ItemType  (core->pv->item_type.c_str());
                check (iter_scene.ItemCount (iter_type, &iter_num));
                iter_cur = 0;
        }

                LXtObjectID
        next_item (
                unsigned		*index)
        {
                if (iter_cur >= iter_num)
                        return 0;

                CLxUser_Item		 item;
                check (iter_scene.ItemByIndex (iter_type, iter_cur++, item));
                index[0] = 0;
                return item.m_loc;
        }

        CChannelList		 pending_nodes;
        CLxUser_Item		 cur_item;

        /*
         * The reset/next methods for channel-based enumeration.
         */
                void
        reset_chan ()
        {
                check (iter_scene.ItemCount (-1, &iter_num));
                iter_cur = 0;
                pending_nodes.clear ();
        }

                LXtObjectID
        next_chan (
                unsigned		*index)
        {
                while (1)
                {
                        if (pending_nodes.size ())
                        {
                                CChannelInfo &info = pending_nodes.back ();
                                ILxUnknownID item = info.item;
                                index[0] = info.index;
                                pending_nodes.pop_back ();
                                return item;
                        }

                        if (iter_cur >= iter_num)
                                return 0;

                        check (iter_scene.ItemByIndex (-1, iter_cur++, cur_item));
                        com->include_item (cur_item);
                }

                return 0;
        }
};


metaServer_EvalModifier::metaServer_EvalModifier ()
{
        pv = 0;
}

        void
metaServer_EvalModifier::init (
        CLxMeta_EvalModifier_Core	*core)
{
        pv = new pv_EvalModifier_Server (core);
}

metaServer_EvalModifier::~metaServer_EvalModifier ()
{
        if (pv)
                delete pv;
}

        LxResult
metaServer_EvalModifier::eval_Reset (
        ILxUnknownID		 scene)
{
        pv->iter_scene.set (scene);

        if (pv->include_by_type ())
                pv->reset_item ();
        else
                pv->reset_chan ();

        return LXe_OK;
}

        LXtObjectID
metaServer_EvalModifier::eval_Next (
        unsigned		*index)
{
        if (pv->include_by_type ())
                return pv->next_item (index);
        else
                return pv->next_chan (index);
}

        LxResult
metaServer_EvalModifier::eval_Alloc (
        ILxUnknownID		 item,
        unsigned		 index,
        ILxUnknownID		 eval,
        void		       **ppvObj)
{
        pv_EvalModifier		*mod;

        mod = pv->core->pv->mod_spawn->Alloc (ppvObj);
        mod->init (pv->core, item, index);
        mod->bind_and_link (eval);
        return LXe_OK;
}

        unsigned
metaServer_EvalModifier::tag_Count ()
{
        pv->init_tags ();
        return pv->tag_list->count ();
}

        LxResult
metaServer_EvalModifier::tag_Describe (
        unsigned		 index,
        LXtTagInfoDesc		*desc)
{
        pv->init_tags ();
        return pv->tag_list->describe (index, desc);
}


/*
 * Methods on the CLxEvalModifier are used by the client to communicate
 * feedback to the implementation.
 */
CLxEvalModifier::CLxEvalModifier ()
{
        psrv = 0;
        pmod = 0;
}

        void
CLxEvalModifier::mod_add_node (
        unsigned		 index)
{
        CChannelInfo		 info;

        info.item  = psrv->cur_item;
        info.index = index;
        psrv->pending_nodes.push_back (info);
}

        void
CLxEvalModifier::mod_read_attr (
        void			*ptr)
{
        pmod->m_cpv->attr_desc->eval_read (pmod->m_attr, pmod->base_desc, ptr);
}

        void
CLxEvalModifier::mod_add_chan (
        CLxUser_Item		&item,
        const char		*channel,
        unsigned		 type)
{
        unsigned		 index;

        check (item.ChannelLookup (channel, &index));
        mod_add_chan (item, index, type);
}

        void
CLxEvalModifier::mod_add_chan (
        CLxUser_Item		&item,
        unsigned		 channel,
        unsigned		 type)
{
        pmod->cust_chan.add (item, channel, type);
        pmod->m_cpv->has_custom = true;
}

        CLxUser_Item *
CLxEvalModifier::mod_item ()
{
        return &pmod->m_item;
}

        unsigned
CLxEvalModifier::mod_index ()
{
        return pmod->m_index;
}

        CLxUser_Evaluation *
CLxEvalModifier::mod_eval ()
{
        return &pmod->m_eval;
}

        CLxUser_Attributes *
CLxEvalModifier::mod_attr ()
{
        return &pmod->m_attr;
}

        void
CLxEvalModifier::mod_result (
        LxResult		 rc)
{
        pmod->res_value = rc;
}

        unsigned
CLxEvalModifier::mod_cust_index (
        unsigned		 offset)
{
        return pmod->base_cust + offset;
}

        void
CLxEvalModifier::mod_cust_val (
        unsigned		 offset,
        int			*result)
{
        check (pmod->m_attr.GetInt (mod_cust_index (offset), result));
}

        void
CLxEvalModifier::mod_cust_val (
        unsigned		 offset,
        bool			*result)
{
        int			 k;

        check (pmod->m_attr.GetInt (mod_cust_index (offset), &k));
        result[0] = !!k;
}

        void
CLxEvalModifier::mod_cust_val (
        unsigned		 offset,
        double			*result)
{
        check (pmod->m_attr.GetFlt (mod_cust_index (offset), result));
}

        void
CLxEvalModifier::mod_cust_val (
        unsigned		 offset,
        LXtMatrix4		&m4)
{
        CLxUser_Matrix		 mat;

        check (pmod->m_attr.Value (mod_cust_index (offset), mat, 0));
        check (mat.Get4 (m4));
}

        void
CLxEvalModifier::mod_cust_write (
        unsigned		 offset,
        bool			 value)
{
        check (pmod->m_attr.SetInt (mod_cust_index (offset), !!value));
}

        void
CLxEvalModifier::mod_cust_write (
        unsigned		 offset,
        int			 value)
{
        check (pmod->m_attr.SetInt (mod_cust_index (offset), value));
}

        void
CLxEvalModifier::mod_cust_write (
        unsigned		 offset,
        double			 value)
{
        check (pmod->m_attr.SetFlt (mod_cust_index (offset), value));
}

        void
CLxEvalModifier::mod_cust_write (
        unsigned		 offset,
        const LXtMatrix4	&m4)
{
        CLxUser_Matrix		 mat;

        check (pmod->m_attr.Value (mod_cust_index (offset), mat, 1));
        check (mat.Set4 (m4));
}


/*
 * Simulation sub-object. This is somewhat odd because it's an optional
 * interface on the same simulation object.
 */
class impl_Simulation :
                public CLxImpl_SimulationModifier
{
    public:
        CLxSimulation		*sim;

        LXxO_SimulationModifier_Enabled // (ILxUnknownID chanRead)
        {
                CLxUser_ChannelRead	 rd (chanRead);

                return (sim->enabled (rd) ? LXe_TRUE : LXe_FALSE);
        }

        LXxO_SimulationModifier_Initialize // (double time, double sample)
        {
                sim->init_sim (time, sample);
                return LXe_OK;
        }

        LXxO_SimulationModifier_Cleanup // (void)
        {
                sim->cleanup_sim ();
        }

        LXxO_SimulationModifier_StepSize // (double *stepSize)
        {
                double		 siz = sim->step_size ();

                if (siz <= 0.0)
                        return LXe_NOTIMPL;

                stepSize[0] = siz;
                return LXe_OK;
        }

        LXxO_SimulationModifier_Step // (double dt)
        {
                sim->step (dt);
                return LXe_OK;
        }
};

class polymorph_Simulation :
                public CLxPolymorph<impl_Simulation>
{
    public:
        polymorph_Simulation ()
        {
                AddInterface (new CLxIfc_SimulationModifier<impl_Simulation>);
        }

                void
        InitObj (
                void			*sim,
                void			*mod)
                                                        LXx_OVERRIDE
        {
                CLxEvalModifier		*evmod;

                evmod = reinterpret_cast<CLxEvalModifier *> (mod);
                ((impl_Simulation *) sim) -> sim = dynamic_cast<CLxSimulation *> (evmod);
        }
};

class meta_Simulation :
                public CLxMeta
{
    public:
        meta_Simulation ()
        {
                m_type = LXsMETA_INTERFACE;
                cls_guid = &lx::guid_Modifier;
        }

                void *
        alloc ()
        {
                return new polymorph_Simulation;
        }
};

        void
CLxMeta_EvalModifier_Core::set_simulation ()
{
        add (new meta_Simulation);
}


/*
 * -----------------------------------------------------------
 * Other modifier classes
 */

/*
 * Allocating the item modifier conjures the spawner for the modifier nodes out
 * of spawner space.
 */
CLxItemModifierServer::CLxItemModifierServer ()
{
        CLxSpawnerCreate<CLxItemModifierNode> sp ("CLxItemModifierServer");

        spawn = sp.spawn;
        if (sp.created)
                sp.AddInterface (new CLxIfc_Modifier<CLxItemModifierNode>);

        i_type = LXiTYPE_NONE;
}


/*
 * The typelist is either given explicitly or it copied from the main item
 * type. If there's a main type we make that the required type, and the
 * graph list is just sent directly if present. Tags are stored in a list
 * since the number is variable.
 */
        unsigned
CLxItemModifierServer::tag_Count ()
{
        if (!l_tags.size ())
        {
                l_tags.push_back (LXsMOD_TYPELIST);
                if (ItemTypeList ())
                        l_vals.push_back (ItemTypeList ());
                else
                        l_vals.push_back (ItemType ());

                if (ItemType ())
                {
                        l_tags.push_back (LXsMOD_REQUIREDTYPE);
                        l_vals.push_back (ItemType ());
                }

                if (GraphNames ())
                {
                        l_tags.push_back (LXsMOD_GRAPHLIST);
                        l_vals.push_back (GraphNames ());
                }
        }

        return (unsigned)l_tags.size ();
}

        LxResult
CLxItemModifierServer::tag_Describe (
        unsigned		 index,
        LXtTagInfoDesc		*desc)
{
        lx_err::check (index < l_tags.size (), LXe_OUTOFBOUNDS);

        desc->type = l_tags[index].c_str ();
        desc->info = l_vals[index].c_str ();
        return LXe_OK;
}


/*
 * These methods control traversal of the candidate items for the modifier.
 * Reset() builds the list (by default all items of the main type), and Next()
 * iterates through them. Subclasses can override UpdateList() to get a
 * different list of items.
 */
        LxResult
CLxItemModifierServer::eval_Reset (
        ILxUnknownID		 scene)
{
        CLxUser_Scene		 sc (scene);

        l_item.clear ();
        l_indx.clear ();
        UpdateList (sc);

        i_scan = 0;
        return LXe_OK;
}

        void
CLxItemModifierServer::UpdateList (
        CLxUser_Scene		&scene)
{
        CLxUser_Item		 item;
        unsigned		 i, n;

        if (i_type == LXiTYPE_NONE)
        {
                CLxUser_SceneService	 srv;

                i_type = srv.ItemType (ItemType ());
        }

        lx_err::check (scene.ItemCount (i_type, &n));
        for (i = 0; i < n; i++)
        {
                lx_err::check (scene.GetItem (i_type, i, item));
                
                if (Include (item))
                        add_entry (item, 0);
        }
}

        void
CLxItemModifierServer::add_entry (
        CLxUser_Item		&item,
        unsigned		 index)
{
        l_item.push_back (item);
        l_indx.push_back (index);
}

        LXtObjectID
CLxItemModifierServer::eval_Next (
        unsigned		*index)
{
        LXtObjectID		 obj;

        if (i_scan >= l_item.size ())
                return 0;

        index[0] = l_indx[i_scan];
        obj = l_item[i_scan].m_loc;
        i_scan ++;
        return obj;
}


/*
 * For each item this method is used to allocate the modifier node. We spawn the
 * object and store the eval context, but the rest is done by the client.
 *
 * Clients that want to link to related items would need a test() method and a way
 * to specify other item types and graphs. That could be added relatively easily.
 */
        LxResult
CLxItemModifierServer::eval_Alloc (
        ILxUnknownID		 item,
        unsigned		 index,
        ILxUnknownID		 eval,
        void		       **ppvObj)
{
        CLxItemModifierNode	*node = spawn->Alloc (ppvObj);

        node->m_eval.set (eval);
        node->m_attr.set (eval);
        node->has_cache = true;

        mod_index = index;
        node->p_elt = Alloc (node->m_eval, item);
        return LXe_OK;
}


/*
 * Free the allocated element.
 */
CLxItemModifierNode::~CLxItemModifierNode ()
{
        delete p_elt;
}


/*
 * Test if this modifier node matches what we would create with Alloc().
 */
        LxResult
CLxItemModifierNode::mod_Test (
        ILxUnknownID		 item,
        unsigned		 index)
{
        return (p_elt->Test (item) ? LXe_TRUE : LXe_FALSE);
}


/*
 * With the setup done, the evaluation defers completely to the client
 * implementation for reading and setting channels.
 */
        LxResult
CLxItemModifierNode::mod_Evaluate ()
{
        CLxObject		*cache = NULL;
        bool			 prev_eval;

        if (has_cache) {
                cache = (CLxObject *) m_eval.GetCache ();
                prev_eval = (cache != 0);
                if (!prev_eval) {
                        cache = p_elt->Cache ();
                        if (!cache)
                                has_cache = false;
                        else
                                m_eval.SetCache (cache);
                }
        }

        if (has_cache)
                return p_elt->EvalCache (m_eval, m_attr, cache, prev_eval);

        p_elt->Eval (m_eval, m_attr);
        return LXe_OK;
}

/*
 * Cache data installed in evalaution is freed here.
 */
        void
CLxItemModifierNode::mod_Free (
        void			*cacheRaw)
{
        CLxObject		*cache = (CLxObject *) cacheRaw;

        delete cache;
}


/*
 * Validate is called for input channels that change on a modifier with
 * cache state. If Validate() not implemented we return NOTIMPL to disable
 * validation on this modifier type forever.
 */
        LxResult
CLxItemModifierNode::mod_Validate (
        ILxUnknownID		 item,
        unsigned		 channel,
        LxResult		 rc)
{
        CLxObject		*cache = (CLxObject *) m_eval.GetCache ();
        CLxUser_Item		 itm (item);

        if (p_elt->Validate (cache, itm, channel, rc))
                return LXe_OK;
        else
                return LXe_NOTIMPL;
}


/*
 * This implements the only non-template method for the CLxObjectRefModifier
 * system. Evaluate index 0 for the value reference; allocate the real object;
 * insert it into the reference. Done.
 */
        void
CLxObjectRefModifierCore::Eval (
        CLxUser_Evaluation	&eval,
        CLxUser_Attributes	&attr)
{
        CLxUser_ValueReference	 ref;
        ILxUnknownID		 obj;

        attr.ObjectRW (0, ref);
        Alloc (eval, attr, 1, obj);
        ref.SetObject (obj);
        lx::UnkRelease (obj);
}


/*
 * -----------------------------------------------------------
 * These implement the RenderCamera utility class.
 */
        void
CLxRenderCamera::Camera (
        CLxUser_Evaluation	&eval, 
        CLxUser_Item		&camera)
{
        CLxUser_Scene		 scene (sceneObj);
        int			 index;

        index = scene.GetRenderCameraIndex (eval);
        scene.GetRenderCameraByIndex (index, camera);
}

        void
CLxRenderCamera::BuildList (void)
{
        ILxUnknownID		 camObj;
        CLxUser_Scene		 scene (sceneObj);
        CLxUser_Item		 camera;
        int			 count;
        
        cameraList.clear ();

        count = scene.NRenderCameras ();
        if (count == 0) {
                if (scene.GetRenderCameraByIndex (-1, camera)) {
                        camera.get ((void **) &camObj);
                        cameraList.push_back (camObj);
                }
        }
        else {
                for (int i = 0; i < count; i++) {
                        scene.GetRenderCameraByIndex (i, camera);
                        camera.get ((void **) &camObj);
                        cameraList.push_back (camObj);
                }
        }
}

        bool
CLxRenderCamera::ListIsValid (void)
{
        ILxUnknownID		 camObj;
        CLxUser_Scene		 scene (sceneObj);
        CLxUser_Item		 camera;
        int			 count;

        count = scene.NRenderCameras ();
        if (count == 0) {
                if (cameraList.size() != 1)
                        return false;

                scene.GetRenderCameraByIndex (-1, camera);
                camera.get ((void **) &camObj);
                if (camObj != cameraList[0])
                        return false;
        }
        else if (count != cameraList.size ()) {
                return false;
        }
        else {
                for (int i = 0; i < count; i++) {
                        scene.GetRenderCameraByIndex (i, camera);
                        camera.get ((void **) &camObj);
                        if (camObj != cameraList[i])
                                return false;
                }
        }

        return true;
}

        unsigned
CLxRenderCamera::AttachIndexChan (
        CLxUser_Evaluation	&eval)
{
        CLxUser_Scene		 scene (sceneObj);
        CLxUser_Item		 render_item;
        unsigned		 chanIdx;

        scene.GetItem (LXi_CIT_RENDER, 0, render_item);

        render_item.ChannelLookup ("cameraIndex", &chanIdx);

        this->chanIndex = eval.AddChan (render_item, chanIdx);

        return this->chanIndex;
}

        int
CLxRenderCamera::Camera (CLxUser_Attributes &attr)
{
        return attr.Int (this->chanIndex);
}

        size_t
CLxRenderCamera::size (void)
{
        return cameraList.size();
}

        ILxUnknownID &
CLxRenderCamera::operator[] (
        const int		 index)
{
        return cameraList[index];
}


