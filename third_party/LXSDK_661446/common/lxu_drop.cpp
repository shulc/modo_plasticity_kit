/*
 * Plug-in SDK Header: Common Utility
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
 * Drop Server Wrapper
 */

/*
 * Disable deprecated function warning.
 */
#pragma warning(disable: 4996)

#include <lxu_drop.hpp>
#include <lx_wrap.hpp>
#include <stdio.h>
#include <vector>
#include <string>

using namespace lx_err;


/*
 * ----------------------------------------------------------------
 * Drop Metaclass
 */
class impl_Drop_Server;

class drop_Action
{
    public:
        CLxDropAction		*act;
        std::string		 name;
        unsigned		 index;
        bool			 custom;
        int			 cust_base, cust_num;
};

typedef std::vector<drop_Action> ActionList;

/*
 * Private data for the metaclass itself. Everything here is global state for
 * the Drop.
 */
class pv_Meta_Drop
{
    public:
        CLxTagList		*tag_list;
        CLxMeta_Drop_Core	*m_core;
        CLxDrop			*m_inst;
        const char		*srv_name;
        ActionList		 act_list;
        bool			 array_src;
        unsigned		 i_max;

        pv_Meta_Drop ()
        {
                tag_list  = 0;
                m_core    = 0;
                m_inst    = 0;
                srv_name  = 0;
                array_src = false;
        }

        ~pv_Meta_Drop ()
        {
                for (ActionList::iterator it = act_list.begin(); it != act_list.end(); ++it)
                        delete it->act;

                if (m_inst)
                        delete m_inst;
        }

                void
        add_interfaces (
                CLxGenericPolymorph	*gp)
        {
                gp->AddInterface (new CLxIfc_Drop          <impl_Drop_Server>);
                gp->AddInterface (new CLxIfc_TagDescription<impl_Drop_Server>);
        }

                std::string
        action_names ()
        {
                std::string		 str;
                char			 buf[32];

                i_max = 0;

                for (ActionList::iterator it = act_list.begin(); it != act_list.end(); ++it)
                {
                        if (it->custom)
                                it->index = ~0;
                        else
                        {
                                it->index = i_max++;
                                if (str.length())
                                        str += " ";

                                sprintf (buf, "%d", it->index);
                                str += buf;
                                str += "@";
                                str += it->name;
                        }
                }

                return str;
        }

                void
        init_drop (
                CLxDrop			*drop)
        {
                for (ActionList::iterator it = act_list.begin(); it != act_list.end(); ++it)
                        it->act->init_drop (drop);
        }
};

/*
 * Private data for the CLxDrop implementation. This is unique to each
 * Drop instance.
 */
class pv_Drop
{
    public:
        pv_Meta_Drop		*mpv;
        CLxUser_AddDropAction	 add;
        drop_Action		*cur;
        int			 icur;

        pv_Drop ()
        {
                mpv = 0;
                cur = 0;
        }
};


CLxDrop::CLxDrop ()
{
        pv = new pv_Drop;
}

CLxDrop::~CLxDrop ()
{
        delete pv;
}

/*
 * Custom actions are added more or less directly. We assign them a global
 * index and return a local index.
 */
        unsigned
CLxDrop::add_custom (
        const char		*name)
{
        pv->add.AddAction (pv->icur++, name);
        return pv->cur->cust_num++;
}


/*
 * Server implementation class
 */
class impl_Drop_Server :
                public CLxImpl_Drop,
                public CLxImpl_TagDescription
{
    public:
        pv_Meta_Drop		*mpv;
        CLxDrop			*inst;
        CLxUser_MessageService	 msg_S;

        /*
         * Inialization sets up the arguments from the desc.
         */
        impl_Drop_Server (
                pv_Meta_Drop		*init = 0)
        {
                mpv = init;

                if (!mpv->m_inst)
                {
                        mpv->m_inst = mpv->m_core->new_inst ();
                        mpv->init_drop (mpv->m_inst);
                }

                inst = mpv->m_inst;
        }

        LXxO_Drop_Recognize // (ILxUnknownID source)
        {
                if (inst->recognize_any (source))
                        return LXe_OK;

                if (mpv->array_src)
                {
                        CLxUser_ValueArray va (source);
                        check (va.test ());

                        if (inst->recognize_array (va))
                                return LXe_OK;
                }

                return LXe_NOTFOUND;
        }

        LXxO_Drop_ActionList // (ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction)
        {
                std::string		 name;
                bool			 enab;

                if (!inst->enabled (dest))
                        return LXe_OK;

                inst->pv->add.set (addDropAction);
                inst->pv->icur = mpv->i_max;

                for (ActionList::iterator it = mpv->act_list.begin(); it != mpv->act_list.end(); ++it)
                {
                        inst->pv->cur = &(*it);
                        it->cust_base = inst->pv->icur;
                        it->cust_num  = 0;

                        enab = it->act->enabled (dest);
                        if (it->custom || !enab)
                                continue;

                        name.clear();
                        it->act->name_str (name);

                        if (name.empty())
                        {
                                CLxUser_Message	 msg;

                                if (msg_S.NewMessage (msg))
                                {
                                        it->act->name_msg (msg);
                                        msg_S.MessageText (msg, name);
                                }
                        }

                        if (name.empty())
                        {
                                name  = "@";
                                name += mpv->srv_name;
                                name += "@";
                                name += it->name;
                                name += "@";
                        }

                        inst->pv->add.AddAction (it->index, name.c_str());
                }

                inst->pv->add.clear ();
                inst->pv->cur = 0;
                return LXe_OK;
        }

//	LXxO_Drop_Preview // (ILxUnknownID source, ILxUnknownID dest, int action, ILxUnknownID draw)
//	{
//		return LXe_NOTIMPL;
//	}

        LXxO_Drop_Drop // (ILxUnknownID source, ILxUnknownID dest, int action)
        {
                for (ActionList::iterator it = mpv->act_list.begin(); it != mpv->act_list.end(); ++it)
                {
                        if (it->custom)
                        {
                                if (action >= it->cust_base && action < it->cust_base + it->cust_num)
                                {
                                        it->act->exec_custom (action - it->cust_base);
                                        return LXe_OK;
                                }

                        } else if (action == it->index)
                        {
                                it->act->exec ();
                                return LXe_OK;
                        }
                }

                return LXe_NOTFOUND;
        }

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
 * Metaclass implementation.
 */
CLxMeta_Drop_Core::CLxMeta_Drop_Core (
        const char		*srvName)
                :
        CLxMetaServer (srvName)
{
        cls_guid = &lx::guid_Drop;

        pv = new pv_Meta_Drop;
        pv->tag_list = &tag_list;
        pv->srv_name = srvName;
        pv->m_core   = this;
}

CLxMeta_Drop_Core::~CLxMeta_Drop_Core ()
{
        delete pv;
}

        void *
CLxMeta_Drop_Core::alloc ()
{
        add_tag (LXsDROP_ACTIONNAMES, pv->action_names().c_str());

        return reinterpret_cast<void *>
           ( new CLxMetagenPolymorph<impl_Drop_Server, pv_Meta_Drop> (pv) );
}

        void
CLxMeta_Drop_Core::set_source_type (
        const char		*type)
{
        add_tag (LXsDROP_SOURCETYPE, type);

        std::string t (type);
        pv->array_src = 
                   !t.compare (LXsDROPSOURCE_FILES)
                || !t.compare (LXsDROPSOURCE_FILES_SYNTH)
                || !t.compare (LXsDROPSOURCE_ITEMS)
                || !t.compare (LXsDROPSOURCE_CHANNELS)
                || !t.compare (LXsDROPSOURCE_COMMANDS)
                || !t.compare (LXsDROPSOURCE_FORMCONTROLS);
}

        void
CLxMeta_Drop_Core::add_action (
        const char		*name,
        CLxDropAction		*action,
        bool			 custom)
{
        drop_Action		 proto;

        proto.name   = name;
        proto.act    = action;
        proto.custom = custom;

        pv->act_list.push_back (proto);
}


