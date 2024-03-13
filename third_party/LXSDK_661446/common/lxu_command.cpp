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
 * Command Wrapper
 */

/*
 * Disable deprecated function warning.
 */
#pragma warning(disable: 4996)

#include <lxu_command.hpp>
#include <lx_log.hpp>
#include <lx_wrap.hpp>
#include <vector>
#include <map>
#include <set>

using namespace std;
using namespace lx_err;

/*
 * ----------------------------------------------------------------
 * Command Metaclass
 */
class impl_Command_Server;

/*
 * Private data for the metaclass itself. Everything here is global state for
 * the command.
 */
class pv_Meta_Command
{
    public:
        CLxTagList		*tag_list;
        CLxMeta_Command_Core	*m_core;
        CLxAttributeDesc	 attr_desc;
        const char		*cmd_name;
        unsigned		 cmd_flags;
        std::vector<std::string> note_names;
        bool			 desc_init;

        pv_Meta_Command ()
        {
                tag_list  = 0;
                m_core    = 0;
                cmd_flags = 0;
                desc_init = true;
        }

                void
        add_interfaces (
                CLxGenericPolymorph	*gp)
        {
                gp->AddInterface (new CLxIfc_Command       <impl_Command_Server>);
                gp->AddInterface (new CLxIfc_Attributes    <impl_Command_Server>);
                gp->AddInterface (new CLxIfc_AttributesUI  <impl_Command_Server>);
                gp->AddInterface (new CLxIfc_TagDescription<impl_Command_Server>);
        }
};

/*
 * Private data for the CLxCommand implementation. This is unique to each
 * command instance.
 */
class pv_Command
{
    public:
        pv_Meta_Command		*mpv;
        CLxDynamicArguments	*m_dyna;
        CLxUser_Message		 m_msg, tmp_msg;
        CLxUser_ValueArray	 va_query;
        CLxNotifierHost		 n_host;
        unsigned		 e_flags;
        int			 notifier_state;

        pv_Command ()
        {
                mpv = 0;
                m_dyna = 0;
                notifier_state = -2;
        }

                void
        init_msg ()
        {
                if (!m_msg.test ())
                {
                        CLxUser_MessageService ms;

                        if (!ms.NewMessage (m_msg))
                                throw (LXe_FAILED);
                }
        }

                void
        clear_msg ()
        {
                init_msg ();
                m_msg.SetCode (LXe_OK);
        }
};


/*
 * Base CLxCommand implementation manages the private data and implements the
 * helper methods for communication between server object and client instance.
 */
CLxCommand::CLxCommand ()
{
        pv = new pv_Command;
}

CLxCommand::~CLxCommand ()
{
        delete pv;
}

        unsigned
CLxCommand::cmd_exec_flags ()
{
        return pv->e_flags;
}

        bool
CLxCommand::cmd_interaction_ok (
        bool			 err)
{
        bool			 ok = !!LXxCMD_IS_USER_INTERACTION_OK (pv->e_flags);

        if (err && !ok)
                cmd_error (LXe_CMD_REQUIRES_USER_INTERACTION);

        return ok;
}

        void
CLxCommand::cmd_read_args (
        void			*ptr)
{
        pv->mpv->attr_desc.read_args (pv->m_dyna[0], ptr);
}

        void
CLxCommand::cmd_read_args_isset (
        void			*ptr)
{
        pv->mpv->attr_desc.read_args_isset (pv->m_dyna[0], ptr);
}

        bool
CLxCommand::cmd_read_arg (
        const char		*arg,
        int			&val,
        int			 def)
{
        unsigned		 idx = pv->mpv->attr_desc.by_name (arg);

        val = pv->m_dyna->dyna_Int (idx, def);
        return pv->m_dyna->dyna_IsSet (idx);
}

        bool
CLxCommand::cmd_read_arg (
        const char		*arg,
        double			&val,
        double			 def)
{
        unsigned		 idx = pv->mpv->attr_desc.by_name (arg);

        val = pv->m_dyna->dyna_Float (idx, def);
        return pv->m_dyna->dyna_IsSet (idx);
}

        bool
CLxCommand::cmd_read_arg (
        const char		*arg,
        std::string		&val,
        const char		*def)
{
        return pv->m_dyna->dyna_String (pv->mpv->attr_desc.by_name (arg), val, def);
}

        bool
CLxCommand::cmd_read_arg (
        const char		*arg,
        CLxLocalizedObject	&val)
{
        return pv->m_dyna->dyna_Object (pv->mpv->attr_desc.by_name (arg), val);
}

        void
CLxCommand::cmd_set_arg (
        const char		*arg,
        int			 val)
{
        check (pv->m_dyna->attr_SetInt (pv->mpv->attr_desc.by_name (arg), val));
}

        void
CLxCommand::cmd_set_arg (
        const char		*arg,
        double			 val)
{
        check (pv->m_dyna->attr_SetFlt (pv->mpv->attr_desc.by_name (arg), val));
}

        void
CLxCommand::cmd_set_arg (
        const char		*arg,
        const char		*val)
{
        check (pv->m_dyna->attr_SetString (pv->mpv->attr_desc.by_name (arg), val));
}

        void
CLxCommand::cmd_set_arg (
        const char		*arg,
        std::string		 val)
{
        cmd_set_arg (arg, val.c_str());
}

        void
CLxCommand::cmd_add_query (
        int			 val)
{
        pv->va_query.AddInt (val);
}

        void
CLxCommand::cmd_add_query (
        double			 val)
{
        pv->va_query.AddFloat (val);
}

        void
CLxCommand::cmd_add_query (
        const char		*val)
{
        pv->va_query.AddString (val);
}

        void
CLxCommand::cmd_add_query (
        std::string		 val)
{
        cmd_add_query (val.c_str ());
}

        void
CLxCommand::cmd_add_query (
        ILxUnknownID		 val)
{
        pv->va_query.AddValue (val);
}

        void
CLxCommand::cmd_add_query (
        CLxLocalizedObject	&val)
{
        pv->va_query.AddEmptyValue (val);
}

        CLxDynamicArguments *
CLxCommand::cmd_args ()
{
        return pv->m_dyna;
}

        CLxUser_Message &
CLxCommand::cmd_message (
        const char		*key)
{
        pv->init_msg ();

        CLxUser_Message		&m = (pv->tmp_msg.test() ? pv->tmp_msg : pv->m_msg);

        if (key)
                m.SetMsg (pv->mpv->cmd_name, key);

        return m;
}

        void
CLxCommand::cmd_error (
        LxResult		 rc,
        const char		*key)
{
        cmd_message (key);
        throw (rc);
}

        void
CLxCommand::cmd_add_notifier (
        const char		*name,
        const char		*args)
{
        check (pv->notifier_state == -1);
        pv->n_host.add (name, args);
}

        void
CLxCommand::cmd_add_notifier (
        std::string		 name,
        std::string		 args)
{
        cmd_add_notifier (name.c_str(), args.c_str());
}


/*
 * Helper class to support temporary object localizations. The temp thing will
 * be releaed no matter what.
 */
class cTempLocal
{
    public:
        CLxLocalizedObject &	 m_loc;

        cTempLocal (CLxLocalizedObject &loc, ILxUnknownID unk) : m_loc(loc)
        {
                m_loc.set (unk);
        }

        ~cTempLocal ()
        {
                m_loc.clear ();
        }
};


/*
 * Server implementation class
 */
class impl_Command_Server :
                public CLxImpl_Command,
                public CLxDynamicArguments,
                public CLxImpl_TagDescription
{
    public:
        pv_Meta_Command		*mpv;
        pv_Command		*ipv;
        CLxCommand		*inst;

        /*
         * Inialization sets up the arguments from the desc.
         */
        impl_Command_Server (
                pv_Meta_Command		*init = 0)
        {
                mpv = init;
                if (lx::IsTempSpawn ())
                {
                        ipv  = 0;
                        inst = 0;
                        return;
                }

                inst = mpv->m_core->new_inst ();
                ipv = inst->pv;
                ipv->mpv = mpv;
                ipv->m_dyna = this;

                if (mpv->desc_init)
                {
                        inst->setup_args (mpv->attr_desc);
                        mpv->desc_init = false;
                }

                mpv->attr_desc.setup_args (*this);
        }

        /*
         * Global properties.
         */
        LXxO_Command_Flags // (unsigned int *flags)
        {
                flags[0] = mpv->cmd_flags;
                return LXe_OK;
        }

        LXxO_Command_Message // (void **ppvObj)
        {
                inst->cmd_message();
                ipv->m_msg.get (ppvObj);
                return LXe_OK;
        }

        LXxO_Command_ButtonName // (const char **buttonName)
        {
                buttonName[0] = inst->button_name ();
                return (buttonName[0] ? LXe_OK : LXe_NOTIMPL);
        }

        LXxO_Command_Icon // (const char **iconNames)
        {
                iconNames[0] = inst->icon_name ();
                return (iconNames[0] ? LXe_OK : LXe_NOTIMPL);
        }

        /*
         * Argument methods.
         */
        LXxO_Command_ArgFlags // (unsigned int index, unsigned int *flags)
        {
                flags[0] = dyna_GetFlags (index);
                return LXe_OK;
        }

        LXxO_Command_ArgClear // (unsigned int index)
        {
                dyna_Clear (index);
                return LXe_OK;
        }

        LXxO_Command_ArgResetAll // (void)
        {
                dyna_ClearAll ();
                return LXe_OK;
        }

        LXxO_Command_ArgSetDatatypes // (void)
        {
                dyna_SetVariable ();
                return LXe_OK;
        }

                const char *
        dyna_GetType (
                unsigned		 index)			LXx_OVERRIDE
        {
                return mpv->attr_desc.arg_get_type (index, *inst);
        }

                void
        atrui_UIHints2 (
                unsigned		 index,
                CLxUser_UIHints		&hints)			LXx_OVERRIDE
        {
                mpv->attr_desc.arg_uihints (index, hints, *inst);
        }

                CLxDynamicUIValue *
        atrui_UIValue (
                unsigned		 index)			LXx_OVERRIDE
        {
                return mpv->attr_desc.arg_uivalue (index, *inst);
        }

                LxResult
        enable_result (
                bool			 enab)
        {
                if (enab)
                        return LXe_OK;

                inst->cmd_message().SetCode(LXe_CMD_DISABLED);
                return LXe_CMD_DISABLED;
        }

        LXxO_Command_ArgEnable // (unsigned int arg)
        {
                return enable_result (mpv->attr_desc.arg_enabled (arg, *inst));
        }

        /*
         * Execution cycle.
         */
        LXxO_Command_Enable // (ILxUnknownID msg)
        {
                cTempLocal		 tmp (ipv->tmp_msg, msg);
                bool			 enab;

                ipv->clear_msg ();
                try
                {
                        enab = inst->enabled ();

                } catch (LxResult rc)
                {
                        return rc;
                }

                return enable_result (enab);
        }

        LXxO_Command_DialogInit // (void)
        {
                return mpv->attr_desc.dialog_init (*this);
        }

        LXxO_Command_Interact // (void)
        {
                ipv->clear_msg ();
                try
                {
                        inst->interact ();

                } catch (LxResult rc)
                {
                        inst->cmd_message().SetCode (rc);
                }
        }

        LXxO_Command_PreExecute // (void)
        {
                ipv->clear_msg ();
                try
                {
                        inst->preflight ();

                } catch (LxResult rc)
                {
                        inst->cmd_message().SetCode (rc);
                }
        }

        LXxO_Command_Execute // (unsigned int flags)
        {
                ipv->clear_msg ();
                try
                {
                        ipv->e_flags = flags;
                        inst->execute ();

                } catch (LxResult rc)
                {
                        inst->cmd_message().SetCode (rc);
                }
        }

        LXxO_Command_Query // (unsigned int index, ILxUnknownID vaQuery)
        {
                cTempLocal		 tmp (ipv->va_query, vaQuery);

                mpv->attr_desc.arg_query (index, *inst);
                return LXe_OK;
        }

        /*
         * Notifiers. State of -2 means nothing set, get them all go to
         * state -1. If an argument is given go to state 'arg'. Can't go
         * backwards once set.
         */
        LXxO_Command_NotifyAddClient // (int argument, ILxUnknownID object)
        {
                if (ipv->notifier_state == -2)
                {
                        int	 i, n;

                        n = mpv->note_names.size ();
                        for (i = 0; i < n; i += 2)
                                ipv->n_host.add (mpv->note_names[i], mpv->note_names[i + 1]);

                        ipv->notifier_state = -1;
                        inst->notifiers ();
                }

                if (argument != -1)
                {
                        check (ipv->notifier_state == -1);
                        ipv->notifier_state = argument;

                        ipv->n_host.set_arg (*this, argument);
                }

                ipv->n_host.add_client (object);
                return LXe_OK;
        }

        LXxO_Command_NotifyRemoveClient // (ILxUnknownID object)
        {
                ipv->n_host.rem_client (object);
                return LXe_OK;
        }

 #if 0
        LXxO_Command_UserName // (const char **userName)
        LXxO_Command_Desc // (const char **desc)
        LXxO_Command_Tooltip // (const char **tooltip)
        LXxO_Command_Help // (const char **help)
        LXxO_Command_Example // (const char **example)
        LXxO_Command_PostExecFlags // (unsigned int *flags)
        LXxO_Command_PostExecBehaviorFlags // (unsigned int *flags)
        LXxO_Command_PostExecHints // (unsigned int *hints)
        LXxO_Command_SandboxGUID // (const LXtGUID **guid)
        LXxO_Command_ContainedEnable // (LXtID4 *types)
        LXxO_Command_ToggleArg // (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
        LXxO_Command_ArgType // (unsigned int index, const char **type)
        LXxO_Command_ArgUserName // (unsigned int index, const char **userName)
        LXxO_Command_ArgDesc // (unsigned int index, const char **desc)
        LXxO_Command_ArgExample // (unsigned int index, const char **example)
        LXxO_Command_ArgTypeUserName // (unsigned int index, const char **userName)
        LXxO_Command_ArgTypeDesc // (unsigned int index, const char **desc)
        LXxO_Command_ArgOptionUserName // (unsigned int index, unsigned int optIndex, const char **userName)
        LXxO_Command_ArgOptionDesc // (unsigned int index, unsigned int optIndex, const char **desc)
        LXxO_Command_DialogArgChange // (unsigned int arg)
        LXxO_Command_ArgParseString // (unsigned int argIndex, const char *argString)
        LXxO_Command_Copy // (ILxUnknownID sourceCommand)
        LXxO_Command_DialogFormatting // (const char **formatting)
        LXxO_Command_IconImage // (int w, int h, void **ppvObj)
 #endif

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
CLxMeta_Command_Core::CLxMeta_Command_Core (
        const char		*cmdName)
                :
        CLxMetaServer (cmdName)
{
        cls_guid = &lx::guid_Command;

        pv = new pv_Meta_Command;
        pv->tag_list = &tag_list;
        pv->m_core   = this;
        pv->cmd_name = cmdName;
}

CLxMeta_Command_Core::~CLxMeta_Command_Core ()
{
        delete pv;
}

        void *
CLxMeta_Command_Core::alloc ()
{
        return reinterpret_cast<void *>
           ( new CLxMetagenPolymorph<impl_Command_Server, pv_Meta_Command> (pv) );
}

        void
CLxMeta_Command_Core::set_type_flags (
        unsigned		 flags)
{
        pv->cmd_flags |= flags;
}

        void
CLxMeta_Command_Core::set_type_model ()
{
        set_type_flags (LXfCMD_MODEL | LXfCMD_UNDO);
}

        void
CLxMeta_Command_Core::set_type_UI ()
{
        set_type_flags (LXfCMD_UI);
}

        void
CLxMeta_Command_Core::add_notifier (
        const char		*name,
        const char		*args)
{
        std::string		 tmp;

        tmp = name;
        pv->note_names.push_back (tmp);

        tmp = args;
        pv->note_names.push_back (tmp);
}


/*
 * ----------------------------------------------------------------
 * Notifier metaclass
 */

/*
 * Global data for a notifier server. We have to keep a list of all instances
 * with different args.
 */
class impl_Notifier_Server;

class pv_Meta_Notifier
{
    public:
        CLxTagList		*tag_list;
        CLxMeta_Notifier_Core	*m_core;
        const char		*srv_name;
        set<CLxNotifier_Core *>	 n_table;

        pv_Meta_Notifier ()
        {
                tag_list  = 0;
                m_core    = 0;
                srv_name  = 0;
        }

                CLxNotifier_Core *
        get_inst ()
        {
                CLxNotifier_Core	*noti;

                noti = m_core->new_inst();
                n_table.insert (noti);
                return noti;
        }

                void
        free_inst (
                CLxNotifier_Core	*noti)
        {
                n_table.erase (noti);
                delete noti;
        }

                void
        add_interfaces (
                CLxGenericPolymorph	*gp)
        {
                gp->AddInterface (new CLxIfc_Notifier      <impl_Notifier_Server>);
                gp->AddInterface (new CLxIfc_TagDescription<impl_Notifier_Server>);
        }
};

/*
 * Private data for a specific notifier holds a list of the clients.
 */
class pv_Notifier
{
    public:
        pv_Meta_Notifier	*mpv;
        map<ILxUnknownID,CLxUser_CommandEvent>
                                 clients;

        pv_Notifier ()
        {
                mpv = 0;
        }
};


CLxNotifier_Core::CLxNotifier_Core ()
{
        pv = new pv_Notifier;
}

CLxNotifier_Core::~CLxNotifier_Core ()
{
        delete pv;
}

        void
CLxNotifier_Core::notify_cmd (
        unsigned			 cmdFlags)
{
        map<ILxUnknownID,CLxUser_CommandEvent>::iterator
                                         mit;

        for (mit = pv->clients.begin() ; mit != pv->clients.end(); mit++)
                mit->second.Event (cmdFlags);
}


/*
 * Server implementation class
 */
class impl_Notifier_Server :
                public CLxImpl_Notifier,
                public CLxImpl_TagDescription
{
    public:
        pv_Meta_Notifier	*mpv;
        CLxNotifier_Core	*p_inst;
        std::string		 arg_str;

        /*
         * Inialization sets up the arguments from the desc.
         */
        impl_Notifier_Server (
                pv_Meta_Notifier	*init = 0)
        {
                mpv = init;
                p_inst = mpv->get_inst();
        }

        ~impl_Notifier_Server ()
        {
                mpv->free_inst (p_inst);
        }

        LXxO_Notifier_Name // (const char **name)
        {
                name[0] = mpv->srv_name;
                return LXe_OK;
        }

        LXxO_Notifier_SetArgs // (const char *args)
        {
                arg_str = args;
                p_inst->parse_args (args);
                return LXe_OK;
        }

        LXxO_Notifier_Args // (const char **args)
        {
                args[0] = arg_str.c_str();
                return LXe_OK;
        }

        LXxO_Notifier_AddClient // (ILxUnknownID object)
        {
                CLxUser_CommandEvent	 ce (object);

                if (!ce.test ())
                        return LXe_NOINTERFACE;

                if (p_inst->pv->clients.find (object) != p_inst->pv->clients.end())
                        return LXe_OK;

                p_inst->pv->clients[object] = ce;
                return LXe_OK;
        }

        LXxO_Notifier_RemoveClient // (ILxUnknownID object)
        {
                p_inst->pv->clients.erase (object);
                return LXe_OK;
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
CLxMeta_Notifier_Core::CLxMeta_Notifier_Core (
        const char		*srvName)
                :
        CLxMetaServer (srvName)
{
        cls_guid = &lx::guid_Notifier;

        pv = new pv_Meta_Notifier;
        pv->tag_list = &tag_list;
        pv->srv_name = srvName;
        pv->m_core   = this;
}

CLxMeta_Notifier_Core::~CLxMeta_Notifier_Core ()
{
        delete pv;
}

        void *
CLxMeta_Notifier_Core::alloc ()
{
        return reinterpret_cast<void *>
           ( new CLxMetagenPolymorph<impl_Notifier_Server, pv_Meta_Notifier> (pv) );
}

        void
CLxMeta_Notifier_Core::enumerate_raw ()
{
        set<CLxNotifier_Core *>::iterator sit;

        for (sit = pv->n_table.begin(); sit != pv->n_table.end(); sit++)
                visit_raw (*sit);
}


/*
 * ----------------------------------------------------------------
 * The basic command manages a certain amount of local state.
 */
class pv_BasicCommand {
    public:
        CLxUser_Message		 msg;
        vector<CLxUser_Notifier> notifiers;
        vector<ILxUnknownID>	 noteClients;
        string			 bname, icon;
        LxResult		 code;
        bool			 initNotifiers;

//	CLxUser_LogService	 slog;
//	char			 buf[1024];
};


CLxBasicCommand::CLxBasicCommand ()
{
        pv = new pv_BasicCommand;

        CLxUser_MessageService ms;
        if (!ms.NewMessage (pv->msg))
                throw (LXe_FAILED);

        pv->initNotifiers = true;

//	sprintf (pv->buf, "cmd%p - create\n", this);
//	pv->slog.DebugLogOutput (LXi_DBLOG_NORMAL, pv->buf);
}

CLxBasicCommand::~CLxBasicCommand ()
{
//	sprintf (pv->buf, "cmd%p - destroy\n", this);
//	pv->slog.DebugLogOutput (LXi_DBLOG_NORMAL, pv->buf);

        for (unsigned i = 0; i < pv->notifiers.size (); i++)
                for (unsigned j = 0; j < pv->noteClients.size (); j++)
                        pv->notifiers[i].RemoveClient (pv->noteClients[j]);

        delete pv;
}


/*
 * The flags are passed directly to DynamicArguments
 */
        void
CLxBasicCommand::basic_SetFlags (
        unsigned int		 index,
        unsigned int		 flags)
{
        dyna_SetFlags (index, flags);
}


/*
 * --------------------------------------------------------------------
 * Implementations of ILxCommand argument methods.
 */

/*
 * Enable calls the nice internal form, and hides the weirdness of result codes.
 */
        LxResult
CLxBasicCommand::cmd_Enable (
        ILxUnknownID		 msg)
{
        CLxUser_Message		 userMsg(msg);
        LxResult		 result;

        result = basic_Enable (userMsg) ? LXe_OK : LXe_CMD_DISABLED;
        userMsg.SetCode (result);
        return result;
}


/*
 * Global flags come straight from the client.
 */
        LxResult
CLxBasicCommand::cmd_Flags (
        unsigned int		*flags)
{
        flags[0] = basic_CmdFlags ();
        return LXe_OK;
}


/*
 * Arg clearing resets the value in the attributes. If this is a req-for-var
 * argument then we clear all the variable args as well.
 */
        LxResult
CLxBasicCommand::cmd_ArgClear (
        unsigned int		 index)
{
        dyna_Clear (index);
        return LXe_OK;
}

        LxResult
CLxBasicCommand::cmd_ArgResetAll ()
{
        dyna_ClearAll ();
        return LXe_OK;
}


/*
 * Arg flags are stored except for the "set" bit which we get from attributes.
 */
        LxResult
CLxBasicCommand::cmd_ArgFlags (
        unsigned int		 index,
        unsigned int		*flags)
{
        flags[0] = dyna_GetFlags (index);
        return LXe_OK;
}

        LxResult
CLxBasicCommand::cmd_ArgSetDatatypes ()
{
        dyna_SetVariable ();
        return LXe_OK;
}

        LxResult
CLxBasicCommand::cmd_ArgEnable (
        unsigned int		 arg)
{
        return atrui_Enabled (arg, pv->msg) ? LXe_OK : LXe_CMD_DISABLED;
}


/*
 * Return the button name and icon, if the client has an override.
 */
        LxResult
CLxBasicCommand::cmd_ButtonName (
        const char	       **name)
{
        if (basic_ButtonName (pv->bname)) {
                name[0] = pv->bname.c_str ();
                return LXe_OK;
        } else
                return LXe_NOTIMPL;
}

        LxResult
CLxBasicCommand::cmd_Icon (
        const char	       **name)
{
        if (basic_IconName (pv->icon)) {
                name[0] = pv->icon.c_str ();
                return LXe_OK;
        } else
                return LXe_NOTIMPL;
}


/*
 * We have a message object but no message interface. It's returned directly
 * through these methods.
 */
        CLxUser_Message &
CLxBasicCommand::basic_Message ()
{
        return pv->msg;
}

        LxResult
CLxBasicCommand::cmd_Message (
        void		       **ppvObj)
{
        return pv->msg.get (ppvObj);
}


/*
 * Older commands implement their own cmd_Execute(). Newer ones should use
 * this one and implement basic_Execute() instead. The difference is that
 * basic_Execute() can raise LxResult exceptions and those will be properly
 * caught and passed on.
 */
        void
CLxBasicCommand::cmd_Execute (
        unsigned		 flags)
{
        try
        {
                basic_Execute (flags);

        } catch (LxResult rc)
        {
                pv->msg.SetCode (rc);
        }
}

/*
 * Exactly the same thing happens with the cmd_Interact() method.
 */
        void
CLxBasicCommand::cmd_Interact ()
{
        try
        {
                basic_Interact ();

        } catch (LxResult rc)
        {
                pv->msg.SetCode (rc);
        }
}


/*
 * Notifiers are kept in a list which is initialized only when needed. Once we
 * have the list, adding and removing clients can be done by iterating. It's
 * not totally clear how to deal with errors.
 */
        LxResult
CLxBasicCommand::cmd_NotifyAddClient (
        int			 argument,
        ILxUnknownID		 object)
{
        if (pv->initNotifiers) {
                string			 name, args;
                unsigned		 i;

                /*
                 * Notifiers that are global to the command. We get these either by
                 * traversing them by index or by getting a list of name/arg pairs.
                 */
                i = 0;
                while (basic_Notifier (i++, name, args))
                        basic_AddNotify (name, args);

                basic_Notifiers ();

                // NOTE: don't think this is right. It only gets the notifiers for the
                // argument specified the first time this is called. During init we
                // should scan all the args and get their lists of notifiers.
                //
                if( argument != -1 ) {
                        /* Argument-specific notifiers */
                        LXtObjectID	 uiValueHintsObj;
                        if( LXx_OK( atrui_UIValueHints( argument, &uiValueHintsObj ) ) ) {
                                CLxLoc_UIValueHints	 uiValueHints;
                                int			 n;

                                if( uiValueHints.take( uiValueHintsObj ) ) {
                                        if( LXx_OK( uiValueHints.NotifierCount( &n ) ) ) {
                                                for( int index=0; index < n; index++ ) {
                                                        const char	*np = NULL, *ap = NULL;
                                                        if( LXx_OK( uiValueHints.NotifierByIndex( index, &np, &ap ) ) && (np != NULL) ) {
                                                                name = np;
                                                                args = ap;
                                                                basic_AddNotify (name, args);
                                                        }
                                                }
                                        }
                                }
                        }
                }

                pv->initNotifiers = false;
        }

        for (unsigned i = 0; i < pv->notifiers.size (); i++)
                pv->notifiers[i].AddClient (object);

        pv->noteClients.push_back (object);
        return LXe_OK;
}

/*
 * This should only be called from the client's basic_Notifiers() method. We could
 * add protection for that, but it shouldn't be necessary.
 */
        void
CLxBasicCommand::basic_AddNotify (
        const char		*name,
        const char		*args)
{
        CLxUser_NotifySysService srv;
        CLxUser_Notifier	 note;
        LXtObjectID		 obj;
        LxResult		 rc;

        rc = srv.Spawn (name, args, &obj);
        if (LXx_FAIL (rc))
                throw (rc);

        note.take (obj);
        pv->notifiers.push_back (note);
}

        void
CLxBasicCommand::basic_AddNotify (
        const std::string	&name,
        const std::string	&args)
{
        basic_AddNotify (name.c_str(), args.c_str());
}


        LxResult
CLxBasicCommand::cmd_NotifyRemoveClient (
        ILxUnknownID		 object)
{
        vector<ILxUnknownID>::iterator it;

        it = pv->noteClients.begin ();
        while (1) {
                if (it >= pv->noteClients.end())
                        return LXe_NOTFOUND;

                if (*it == object) {
                        pv->noteClients.erase (it);
                        break;
                }

                it++;
        }

        for (unsigned i = 0; i < pv->notifiers.size (); i++)
                pv->notifiers[i].RemoveClient (object);

        return LXe_OK;
}


/*
 * ----------------------------------------------------------------
 * Popup Choice
 *
 * Base class for a command with a single argument that presents a popup
 * of name choices. Constructor adds the query arg, and the class manages
 * its query value and popup list.
 */
CLxPopupChoiceCommand::CLxPopupChoiceCommand (
        const char		*name,
        const char		*type)
{
        dyna_Add (name, type);
        basic_SetFlags (0, LXfCMDARG_QUERY);
}

        LxResult
CLxPopupChoiceCommand::cmd_Query (
        unsigned int		 index,
        ILxUnknownID		 vaQuery)
{
        CLxUser_ValueArray	 va (vaQuery);

        if (index == 0)
                popcmd_GetCurrent (va);

        return LXe_OK;
}

        void
CLxPopupChoiceCommand::popcmd_GetChoices2 (
        std::vector<std::string> &user,
        std::vector<std::string> &internal,
        std::vector<std::string> &tooltip)
{
        popcmd_GetChoices (user, internal);
}

class CPCC_Popup :
                public CLxUIListPopup
{
    public:
        CLxPopupChoiceCommand	*pcc;

        CPCC_Popup (CLxPopupChoiceCommand *p) : pcc (p) {}

                void
        UpdateLists ()
        {
                pcc->popcmd_GetChoices2 (user_list, internal_list, tooltip_list);
        }
};

       CLxDynamicUIValue *
CLxPopupChoiceCommand::atrui_UIValue (
        unsigned int		 index)
{
        return new CPCC_Popup (this);
}


/*
 * ----------------------------------------------------------------
 * Item-type Operator
 *
 * This is an operation (the core of a command) that's interested in
 * items of a given type.
 */
class pv_ItemTypeOperator {
    public:
        set<pair<string, string> >	 choices;
        bool				 has_internal;
};

CLxItemTypeOperator::CLxItemTypeOperator (
        const char		*type)
                :
                item_sel (type)
{
        pv = new pv_ItemTypeOperator;
}

CLxItemTypeOperator::~CLxItemTypeOperator ()
{
        delete pv;
}

        bool
CLxItemTypeOperator::op_Notifier (
        unsigned		 index,
        std::string		&name,
        std::string		&args)
{
        if (index == 0)
        {
                name = LXsNOTIFIER_SELECT;
                args = "item +vd ";
                return true;
        } else
                return false;
}

        bool
CLxItemTypeOperator::op_Enable ()
{
        CLxUser_Item		 item;

        return item_sel.GetFirst (item);
}

        void
CLxItemTypeOperator::op_GetCurrent (
        CLxUser_ValueArray	&va)
{
        CLxItemSelection::ItemList	list;
        CLxItemSelection::ItemList_Itr	lit;

        item_sel.GetList (list);
        for (lit = list.begin (); lit != list.end (); lit++)
                op_item_current (*lit, va);
}

        void
CLxItemTypeOperator::op_GetChoices (
        vector<string>		&user,
        vector<string>		&internal)
{
        CLxItemSelection::ItemList	list;
        CLxItemSelection::ItemList_Itr	lit;

        pv->choices.clear ();
        pv->has_internal = true;

        item_sel.GetList (list);
        for (lit = list.begin (); lit != list.end (); lit++)
                op_item_choices (*lit);

        set<pair<string, string> >::iterator sit;
        for (sit = pv->choices.begin (); sit != pv->choices.end (); sit ++)
        {
                user.push_back (sit->first);
                if (pv->has_internal)
                        internal.push_back (sit->second);
        }
}

        void
CLxItemTypeOperator::op_add_choice (
        const char		*user,
        const char		*intr)
{
        pair<string, string>	 proto;

        proto.first = user;
        if (intr)
                proto.second = intr;
        else
                pv->has_internal = false;

        pv->choices.insert (proto);
}

        void
CLxItemTypeOperator::op_Execute ()
{
        CLxItemSelection::ItemList	list;
        CLxItemSelection::ItemList_Itr	lit;

        item_sel.GetList (list);
        for (lit = list.begin (); lit != list.end (); lit++)
                op_item_exec (*lit);
}


/*
 * ----------------------------------------------------------------
 * The command notifier manages the table of clients and arguments. The name is
 * set in the constructor.
 */
class pv_CommandNotifier {
    public:
        map<ILxUnknownID,CLxUser_CommandEvent>
                                 l_client;
        string			 s_name, s_args;
};

/*
 * The global notifier table maps the notifier name to the set of all notifiers.
 * The notifier system should be responsible for merging notifiers with the same
 * arg strings, so these should all be unique.
 */
typedef set<CLxCommandNotifier *> CommandNotifierSet;

static map<string, CommandNotifierSet> cn_MasterTable;


CLxCommandNotifier::CLxCommandNotifier (
        const char		*name)
{
        pv = new pv_CommandNotifier;
        pv->s_name = name;
}

CLxCommandNotifier::~CLxCommandNotifier ()
{
        map<ILxUnknownID,CLxUser_CommandEvent>::iterator it;

        while (!pv->l_client.empty ()) {
                it = pv->l_client.begin ();
                noti_RemoveClient (it->first);
        }

        delete pv;
}

        LxResult
CLxCommandNotifier::noti_Name (
        const char	       **name)
{
        name[0] = pv->s_name.c_str ();
        return LXe_OK;
}

        LxResult
CLxCommandNotifier::noti_SetArgs (
        const char		*args)
{
        try {
                pv->s_args = args;
                cn_Parse (pv->s_args);

        } catch (LxResult rc) {
                return rc;
        }
        return LXe_OK;
}

        LxResult
CLxCommandNotifier::noti_Args (
        const char	       **args)
{
        args[0] = pv->s_args.c_str ();
        return LXe_OK;
}

        LxResult
CLxCommandNotifier::noti_AddClient (
        ILxUnknownID		 object)
{
        CLxUser_CommandEvent	 ce;

        ce.set (object);
        if (!ce.test ())
                return LXe_NOTFOUND;

        if (pv->l_client.empty ())
                cn_MasterTable[pv->s_name].insert (this);

        pv->l_client[object] = ce;
        return LXe_OK;
}

        LxResult
CLxCommandNotifier::noti_RemoveClient (
        ILxUnknownID		 object)
{
        pv->l_client.erase (object);
        if (!pv->l_client.empty ())
                return LXe_OK;

        cn_MasterTable[pv->s_name].erase (this);
        return LXe_OK;
}

        void
CLxCommandNotifier::Notify (
        const char		*name,
        int			 code)
{
        CommandNotifierSet::iterator	 sit;
        string				 sn  = name;
        CommandNotifierSet		&set = cn_MasterTable[sn];

        for (sit = set.begin() ; sit != set.end(); sit++) {
                CLxCommandNotifier	*note = *sit;
                unsigned int		 flags;

                flags = note->cn_Flags (code);
                if (!flags)
                        continue;

                map<ILxUnknownID,CLxUser_CommandEvent>::iterator
                                         mit;

                for (mit = note->pv->l_client.begin() ; mit != note->pv->l_client.end(); mit++)
                        mit->second.Event (flags);
        }
}


/*
 * ----------------------------------------------------------------
 * The notifier host manages a list of notifiers and their client
 * objects. For now notifiers can only be added as long are there
 * are no clients.
 */
class pv_NotifierHost
{
    public:
        vector<CLxUser_Notifier> notifiers;
        set<ILxUnknownID>	 clients;
        bool			 has_arg;
};

CLxNotifierHost::CLxNotifierHost ()
{
        pv = new pv_NotifierHost;
        pv->has_arg = false;
}

CLxNotifierHost::~CLxNotifierHost ()
{
        std::set<ILxUnknownID>::iterator sit;

        for (sit = pv->clients.begin(); sit != pv->clients.end(); sit++)
                for (int i = 0; i < pv->notifiers.size (); i++)
                        pv->notifiers[i].RemoveClient (*sit);

        delete pv;
}

        void
CLxNotifierHost::add (
        std::string		 name,
        std::string		 args)
{
        add (name.c_str(), args.c_str());
}

        void
CLxNotifierHost::add (
        const char		*name,
        const char		*args)
{
        CLxUser_NotifySysService srv;
        CLxUser_Notifier	 note;
        LXtObjectID		 obj;
        LxResult		 rc;

        if (pv->clients.size () > 0)
                throw (LXe_NOACCESS);

        rc = srv.Spawn (name, args, &obj);
        if (LXx_FAIL (rc))
                throw (rc);

        note.take (obj);
        pv->notifiers.push_back (note);
}

        void
CLxNotifierHost::set_arg (
        CLxDynamicArguments	&dyna,
        unsigned		 index)
{
        LXtObjectID		 uiObj;
        CLxLoc_UIValueHints	 ui;
        int			 n;

        if (pv->has_arg)
                throw (LXe_NOACCESS);

        pv->has_arg = true;

        if (LXx_FAIL (dyna.atrui_UIValueHints (index, &uiObj)))
                return;

        check (ui.take (uiObj));
        check (ui.NotifierCount (&n));
        for (int i = 0; i < n; i++)
        {
                const char	*name = NULL, *args = NULL;

                check (ui.NotifierByIndex (i, &name, &args));
                if (name)
                        add (name, args);
        }
}

        void
CLxNotifierHost::add_client (
        ILxUnknownID		 client)
{
        if (pv->clients.find (client) != pv->clients.end())
                return;

        pv->clients.insert (client);
        for (int i = 0; i < pv->notifiers.size (); i++)
                pv->notifiers[i].AddClient (client);
}

        void
CLxNotifierHost::rem_client (
        ILxUnknownID		 client)
{
        if (pv->clients.find (client) == pv->clients.end())
                return;

        pv->clients.erase (client);
        for (int i = 0; i < pv->notifiers.size (); i++)
                pv->notifiers[i].RemoveClient (client);
}


/*
 * Open a command block as long as we're in scope.
 */
CLxOpenCommandBlock::CLxOpenCommandBlock (
        const char		*name,
        unsigned		 flags)
{
        check (cmd_S.BlockBegin (name, flags));
}

CLxOpenCommandBlock::~CLxOpenCommandBlock ()
{
        check (cmd_S.BlockEnd ());
}

/*
 * ----------------------------------------------------------------
 * Static Analysis Test
 *
 * This is a wrapper around BasicCommand to run a Test against a set of items
 * in a scene.
 *
 */

CLxStaticAnalysisTest::CLxStaticAnalysisTest()
{
    // item to Test / Fix
        dyna_Add("item", "&item");
        idxItem = 0;
        dyna_SetFlags(idxItem, LXfCMDARG_OPTIONAL | LXfCMDARG_HIDDEN);

    // Test name - return sa_Name()
        dyna_Add("name", LXsTYPE_STRING);
        idxName = 1;
        dyna_SetFlags(idxName, LXfCMDARG_OPTIONAL | LXfCMDARG_QUERY | LXfCMDARG_HIDDEN);

    // category
        dyna_Add("category", LXsTYPE_STRING);
        idxCategory = 2;
        dyna_SetFlags(idxCategory, LXfCMDARG_OPTIONAL | LXfCMDARG_QUERY | LXfCMDARG_HIDDEN);

    // Fix the item
        dyna_Add("runFix", LXsTYPE_BOOLEAN);
        idxRunFix = 3;
        dyna_SetFlags(idxRunFix, LXfCMDARG_OPTIONAL | LXfCMDARG_QUERY | LXfCMDARG_HIDDEN);

    // Run this test and report results
        dyna_Add("runTests", LXsTYPE_STRING);
        idxRunTests = 4;
        dyna_SetFlags(idxRunTests, LXfCMDARG_OPTIONAL | LXfCMDARG_QUERY | LXfCMDARG_HIDDEN);

    // key to mark as the "ignore key" for this test. Each item has a tag, which is compared to this key. If present, it is not tested.
        dyna_Add("ignoreKey", LXsTYPE_STRING);
        idxIgnoreKey = 5;
        dyna_SetFlags(idxIgnoreKey, LXfCMDARG_OPTIONAL | LXfCMDARG_QUERY | LXfCMDARG_HIDDEN);

        // flag to basically bypass the ignore step. We use this so that we can show ignored tests in the tree.
        dyna_Add("showIgnored", LXsTYPE_BOOLEAN);
        idxShowIgnored = 6;
        dyna_SetFlags(idxShowIgnored, LXfCMDARG_OPTIONAL | LXfCMDARG_QUERY | LXfCMDARG_HIDDEN);

        // Run the select function of the test
        dyna_Add("doSelect", LXsTYPE_BOOLEAN);
    idxDoSelect = 7;
        dyna_SetFlags(idxDoSelect, LXfCMDARG_OPTIONAL | LXfCMDARG_HIDDEN);

        // Select mode (add, replace etc)
        dyna_Add("selectMode", LXsTYPE_STRING);
        idxSelectMode = 8;
        dyna_SetFlags(idxSelectMode, LXfCMDARG_OPTIONAL | LXfCMDARG_HIDDEN);

        dyna_Add("tooltip", LXsTYPE_STRING);
        idxTooltip = 9;
        dyna_SetFlags(idxTooltip, LXfCMDARG_OPTIONAL | LXfCMDARG_QUERY | LXfCMDARG_HIDDEN);

        DefaultArgumentsCount = 9;

}

LxResult CLxStaticAnalysisTest::cmd_Query(unsigned int index, ILxUnknownID vaQuery)
{
        CLxUser_Item myItem = GetTestItem();
        CLxUser_ValueArray va(vaQuery);

        const char* message = "";

        switch (index)
        {
        case 0:
                break;
        case 1:
                GetMessageTableEntry(sa_Name(), &message);
                va.AddString(message);
                break;
        case 2:
                SplitCategories(va);
                break;
        case 3:
                va.AddString(sa_Test(myItem).c_str());
                break;
        case 4:
                RunTests(va);
        break;
    case 6:
        va.AddInt(IsIgnored(myItem));
        break;
        case 9:
                GetMessageTableEntry(sa_ToolTip(), &message);
                va.AddString(message);
                break;
        default:
                break;
        }

        return LXe_OK;

}

int CLxStaticAnalysisTest::basic_CmdFlags()
{
        return LXfCMD_UNDO;
}

void CLxStaticAnalysisTest::basic_Execute(unsigned flags)
{
    // Execute the fix command
        CLxUser_Item testItem = GetTestItem();
        std::string runtests;
        dyna_String(idxRunTests, runtests, "");
        bool runFix = dyna_Bool(idxRunFix, false);
        if (runFix)
        {
                sa_Fix(testItem);
        }

        bool doSelect = dyna_Bool(idxDoSelect, false);
        if (doSelect && runtests.empty())
        {
        std::string mode;
        dyna_String(idxSelectMode, mode, "");
        sa_Select(testItem, mode);
        }
        if (!runtests.empty())
        {
                RunTests(NULL);
        }
}

// Get the ident of the passed in item name
CLxUser_Item CLxStaticAnalysisTest::GetTestItem()
{
        std::string itemName;
        dyna_String(idxItem, itemName, "");

        if (!itemName.empty())
        {
                CLxSceneSelection sel_scene;
                CLxUser_Scene scene;
                sel_scene.Get(scene);

                CLxUser_Item MyItem;
                scene.ItemLookupIdent(itemName.c_str(), MyItem);

                return MyItem;
        }

        return NULL;
}

// split the categories string based on ";", so get an array of categories
void CLxStaticAnalysisTest::SplitCategories(CLxUser_ValueArray va)
{
        std::string myCat = sa_Category();
        const char* outMsg;
        GetMessageTableEntry(myCat.c_str(), &outMsg);
        myCat = outMsg;
        std::size_t found = myCat.rfind(";");
        std::set<std::string> allCategories;
        while (found != std::string::npos)
        {
                std::string strippedname = myCat.substr(found + 1, myCat.size());
                myCat = myCat.substr(0, found);
                allCategories.insert(strippedname);
                found = myCat.rfind(";");
        }
        allCategories.insert(myCat);

        std::set<std::string>::iterator catIter;

        for (catIter = allCategories.begin(); catIter != allCategories.end(); ++catIter)
        {
                std::string currentCat = *catIter;
                va.AddString(currentCat.c_str());
        }
}

bool CLxStaticAnalysisTest::GetMessageTableEntry(const char* inString, const char** outMsg)
{
        CLxUser_MessageService srvMsg;
        srvMsg.RawText(NULL, inString, outMsg);
        return false;
}

// Go over the selected item type and test each item.
// If item type is none, do everything.
void CLxStaticAnalysisTest::RunTests(CLxUser_ValueArray vaArray)
{
        CLxUser_SceneService srvScn;

        CLxSceneSelection sel_scene;
        CLxUser_Scene scene;
        sel_scene.Get(scene);

    int useSelected = 0;
    CLxUser_CommandService srvCmd;
        CLxUser_Command spawnedCmd;
        std::string myCmd = "StaticAnalysis.TestType";
        srvCmd.Spawn(LXiCTAG_NULL, myCmd.c_str(), spawnedCmd);
    
        CLxUser_ValueArray va;
    srvCmd.QueryArgString(spawnedCmd, 0, "?", va, 0, false);
    if (va.test())
    {
        for (unsigned int j = 0; j < va.Count(); j++)
        {
            va.GetInt(0, &useSelected);
        }
    }
        
    std::vector<LXtItemType> allItemsVector;
    // per itemtype test
        LXtItemType itype;
        const char* itemType = sa_ItemType();
        std::string allTypes = itemType;
        std::size_t found = allTypes.rfind(";");
        std::set<std::string> allUserTypes;
        while (found != std::string::npos)
        {
                std::string strippedname = allTypes.substr(found + 1, allTypes.size());
                allTypes = allTypes.substr(0, found);
                allUserTypes.insert(strippedname);
                found = allTypes.rfind(";");
        }
        allUserTypes.insert(allTypes);

    if (!allUserTypes.empty())
    {
        std::set<std::string>::iterator userTypeIter;
        for (userTypeIter = allUserTypes.begin(); userTypeIter != allUserTypes.end(); ++userTypeIter)
        {
            std::string currentCat = *userTypeIter;
            srvScn.ItemTypeLookup(currentCat.c_str(), &itype);
            allItemsVector.push_back(itype);
        }
    }
    else
    {
        for (unsigned int i = 0; i < srvScn.ItemTypeCount(); i++)
        {
            LXtItemType currentType;
            srvScn.ItemTypeByIndex(i, &currentType);
            allItemsVector.push_back(currentType);
        }
    }
   
        allItemsVector.push_back(0);
        LXtItemType* allTypesArray = &allItemsVector[0];

        if (useSelected < 2)
        {
                unsigned int allItemCount = 0;
                scene.ItemCountByTypes(allTypesArray, &allItemCount);
                std::set<CLxUser_Item> testedItems;
                for (unsigned int itemiter = 0; itemiter < allItemCount; itemiter++)
                {
                        bool bDoTest = true;
                        CLxUser_SelectionService srvSel;
                        CLxUser_Item testItem;

                        scene.ItemByIndexByTypes(allTypesArray, itemiter, testItem);
                        if (useSelected == 1)
                        {
                                LXtID4 itemType = srvSel.LookupType(LXsSELTYP_ITEM);
                                CLxUser_ItemPacketTranslation ipt;
                                ipt.autoInit();
                                void* pkt;
                                CLxUser_Item pktItem;
                                srvSel.Allocate(LXsSELTYP_ITEM, ipt);
                                pkt = ipt.Packet(testItem);
                                if ((srvSel.Test(itemType, pkt)) == LXe_TRUE)
                                {
                                        bDoTest = true;
                                }
                                else
                                {
                                        bDoTest = false;
                                }

                        }


                        if (bDoTest && testedItems.insert(testItem).second)
                        {
                                DoTest(vaArray, testItem);
                        }
                }
        }
        else
        {
                // GROUPS
                unsigned grpCount = 0;
                srvScn.ItemTypeLookup("group", &itype);
                scene.ItemCount(itype, &grpCount);
                for (int grpIter = 0; grpIter < grpCount; grpIter++)
                {
                        CLxUser_Item myGroup;
                        scene.ItemByIndex(itype, grpIter, myGroup);
                        CLxUser_SelectionService srvSel;
                        LXtID4 itemType = srvSel.LookupType(LXsSELTYP_ITEM);
                        CLxUser_ItemPacketTranslation ipt;
                        ipt.autoInit();
                        void* pkt;
                        CLxUser_Item pktItem;
                        srvSel.Allocate(LXsSELTYP_ITEM, ipt);
                        pkt = ipt.Packet(myGroup);
                        if ((srvSel.Test(itemType, pkt)) == LXe_TRUE)
                        {
                                // get items
                                CLxUser_ItemGraph ig;
                                scene.GetGraph("itemGroups", ig); // ITEMGROUPS graph
                                unsigned int itemCount;
                                ig.FwdCount(myGroup, &itemCount);
                                for (int linkedItemIter = 0; linkedItemIter < itemCount; linkedItemIter++)
                                {
                                        CLxUser_Item groupItem;
                                        ig.FwdByIndex(myGroup, linkedItemIter, groupItem);
                                        if (LXx_OK(groupItem.TestTypes(allTypesArray)))
                                        {
                                                DoTest(vaArray, groupItem);
                                        }
                                }

                        }
                }
        }
}

// Function to actually do the test
void CLxStaticAnalysisTest::DoTest(CLxUser_ValueArray vaArray, CLxUser_Item testItem)
{
        if (IsIgnored(testItem) == false)
        {
        std::string result = sa_Test(testItem);
                if (!result.empty())
                {
                        if (vaArray.test())
                        {
                                std::string itemUserName;
                                testItem.GetUniqueName(itemUserName);
                                const char* userName = itemUserName.c_str();
                                vaArray.AddString(userName);
                                vaArray.AddString(result.c_str());
                        }
                        else
                        {
                                bool bDoSelect = dyna_Bool(idxDoSelect, false);
                                if (bDoSelect)
                                {
                                        sa_Select(testItem, "add");
                                }
                                else
                                {
                                        sa_Fix(testItem);
                                }
                        }
                }
        }
}

// Read the items tag and see if the test should be ignored on it.
bool CLxStaticAnalysisTest::IsIgnored(CLxUser_Item testItem)
{
        bool showIgnored = dyna_Bool(idxShowIgnored, false);
        if (showIgnored)
        {
                return false;
        }


        CLxUser_StringTag testTag(testItem);
        if (!testTag.test())
        {
                return false;
        }
        LXtID4 myID = LXxID4('S', 'A', 'I', 'T');

        std::string tagVal;
        const char* tagChar = NULL;
        testTag.Get(myID, &tagChar);
        if (tagChar == NULL)
        {
                return false;
        }
        tagVal = tagChar;

        std::size_t found = tagVal.rfind(";");
        std::set<std::string> allIgnores;

        while (found != std::string::npos)
        {
                std::string strippedname = tagVal.substr(found + 1, tagVal.size());
                tagVal = tagVal.substr(0, found);
                allIgnores.insert(strippedname);
                found = tagVal.rfind(";");
        }
        allIgnores.insert(tagVal);

        std::string ignoreKey;
        dyna_String(idxIgnoreKey, ignoreKey);
        found = ignoreKey.rfind(";");
        std::vector<std::string> allKeys;
        bool bFoundIgnore = false;

        while (found != std::string::npos)
        {
                std::string strippedname = ignoreKey.substr(found + 1, ignoreKey.size());
                if (allIgnores.count(strippedname) > 0)
                {
                        bFoundIgnore = true;
                        break;
                }
                ignoreKey = ignoreKey.substr(0, found);
                found = ignoreKey.rfind(";");
        }
        // do it again for the last chunk
        if (allIgnores.count(ignoreKey) > 0)
        {
                bFoundIgnore = true;
        }
        return bFoundIgnore;
}

// override: name
const char* CLxStaticAnalysisTest::sa_Name()
{
        return "";
}

// override: category
const char* CLxStaticAnalysisTest::sa_Category()
{
        return "";
}

// override: itemtype
const char* CLxStaticAnalysisTest::sa_ItemType()
{
        return "";
}

// override: tooltip
const char* CLxStaticAnalysisTest::sa_ToolTip()
{
        return "";
}



// override: test
std::string CLxStaticAnalysisTest::sa_Test(CLxUser_Item item)
{
        return "";
}

// override: fix
bool CLxStaticAnalysisTest::sa_Fix(CLxUser_Item item)
{
        return true;
}

void CLxStaticAnalysisTest::sa_Select(CLxUser_Item item, std::string mode/*=""*/)
{
    CLxUser_CommandService srvCmd;
    const char* ident = "";
    item.Ident(&ident);
    std::string cmd;
    cmd = "select.item ";
    cmd.append(ident);
    cmd = cmd + " " + mode;
   
    srvCmd.ExecuteArgString(-1, LXiCTAG_NULL, cmd.c_str());
}

// tags to define this is a static analysis test
LXtTagInfoDesc CLxStaticAnalysisTest::descInfo[] = {
        { "StaticAnalysisTest",	"" },
        { 0 }
};



