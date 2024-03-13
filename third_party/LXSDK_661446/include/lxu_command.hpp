/*
 * Plug-in SDK Header: C++ Wrapper Classes
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
//@title Commands

#ifndef LXU_COMMAND_HPP
#define LXU_COMMAND_HPP

#include <lxu_attrdesc.hpp>
#include <lxu_attributes.hpp>
#include <lxu_select.hpp>
#include <lxu_meta.hpp>
#include <lx_command.hpp>
#include <lx_notify.hpp>
#include <string>


/*
 * ----------------------------------------------------------------
 * -- Command Metaclass
 *
 * The CLxCommand class implements the customized part of a Command server.
 */
class CLxCommand :
                public CLxObject
{
    public:
        /*
         * Implement to define command arguments.
         */
        virtual void		setup_args (CLxAttributeDesc &) {}

        /*
         * Implement to test if your command is enabled.
         */
        virtual bool		enabled () { return true; }

        /*
         * Implement to do user interaction.
         */
        virtual void		interact () {}

        /*
         * Implement to test your command for execution before starting.
         */
        virtual void		preflight () {}

        /*
         * Implement to execute your command.
         */
        virtual void		execute () {}

        /*
         * Implement to add notifiers to your command.
         */
        virtual void		notifiers () {}

        /*
         * Implement to return a custom button names.
         */
        virtual const char *	button_name () { return 0; }

        /*
         * Implement to return a custom icon.
         */
        virtual const char *	icon_name () { return 0; }

        /*
         * Call to get execution flags.
         */
        unsigned		cmd_exec_flags ();

        /*
         * Test if interaction is OK. If error is true the command fails.
         */
        bool			cmd_interaction_ok (bool error = false);

        /*
         * Call to read argument values into your structure. You can get all
         * arguments, only those required for variable type, or non-query args.
         */
        void			cmd_read_args (void *);

        /*
         * Call to read the 'isset' state for arguments.
         */
        void			cmd_read_args_isset (void *);

        /*
         * Call to read the value of a single argument. Returns true if the
         * arg is set, and sets the result to the default value if not.
         */
        bool			cmd_read_arg (const char *, int &, int def = 0);
        bool			cmd_read_arg (const char *, double &, double def = 0.0);
        bool			cmd_read_arg (const char *, std::string &, const char * def = "");
        bool			cmd_read_arg (const char *, CLxLocalizedObject &);

        /*
         * Call to set the value of an argument.
         */
        void			cmd_set_arg (const char *, int);
        void			cmd_set_arg (const char *, double);
        void			cmd_set_arg (const char *, const char *);
        void			cmd_set_arg (const char *, std::string);

        /*
         * Call to access arguments directly.
         */
        CLxDynamicArguments *	cmd_args ();

        /*
         * Call to add a query result.
         */
        void			cmd_add_query (int);
        void			cmd_add_query (double);
        void			cmd_add_query (const char *);
        void			cmd_add_query (std::string);
        void			cmd_add_query (ILxUnknownID);
        void			cmd_add_query (CLxLocalizedObject &);

        /*
         * Call to get the message for the command, or -- if the string
         * is non-zero -- set the message key.
         */
        CLxUser_Message &	cmd_message (const char * = 0);

        /*
         * Call to raise an error with optional message key. This function
         * never returns.
         */
        void			cmd_error (LxResult = LXe_FAILED, const char * = 0);

        /*
         * Call to add a notifier for this command.
         */
        void			cmd_add_notifier (const char *name, const char *args);

        /*
         * Call to add a notifier for this command.
         */
        void			cmd_add_notifier (std::string name, std::string args);

   //internal:
         CLxCommand ();
        ~CLxCommand ();

        class pv_Command *pv;
};

/*
 * Core metaclass provides some methods for global customization.
 */
class CLxMeta_Command_Core :
                public CLxMetaServer
{
    public:
        /*
         * The type of command you are implementing is set here. Typically
         * commands are either model or UI, but any flags can be set.
         */
        void		 set_type_model ();
        void		 set_type_UI ();
        void		 set_type_flags (unsigned);

        /*
         * Notifiers that don't vary with arguments can be added here.
         */
        void		 add_notifier (const char *, const char *);

    //internal:
         CLxMeta_Command_Core (const char *cmdName);
        ~CLxMeta_Command_Core ();

        virtual CLxCommand *	 new_inst () = 0;

        void *		 alloc () LXx_OVERRIDE;

        class pv_Meta_Command *pv;
};

/*
 * Metaclass template for your specialization.
 */
template <class T>
class CLxMeta_Command :
                public CLxMeta_Command_Core
{
    public:
        /*
         * Set the command server name in the constructor.
         */
        CLxMeta_Command (const char *cmdName) : CLxMeta_Command_Core (cmdName) { }

    //internal:
                CLxCommand *
        new_inst ()
        {
                return new T;
        }
};


/*
 * ----------------------------------------------------------------
 * -- Notifier Metaclass
 *
 * The required methods for a notifier are actually divided between a core 
 * and template class.
 * The template is customized by event data passed to each notifier to compute 
 * the command flags for the combination of event & args.
 */
class CLxNotifier_Core :
                public CLxObject
{
    public:
        /*
         * Implement to parse notifier argument string.
         */
        virtual void		parse_args (const char *) {}

   //internal:
        void			notify_cmd (unsigned);

         CLxNotifier_Core ();
        ~CLxNotifier_Core ();

        class pv_Notifier *pv;
};


/*
 * The CLxNotifier class implements the customized part of a Notifier server.
 * This is a template to allow for client-defined event data.
 */
template <class E>
class CLxNotifier :
                public CLxNotifier_Core
{
    public:
        /*
         * Implement to return the change flags based on the event data.
         */
        virtual unsigned	change_flags (E event) { return LXfCMDNOTIFY_VALUE; }
};


/*
 * Core metaclass has only internal methods.
 */
class CLxMeta_Notifier_Core :
                public CLxMetaServer
{
    public:
    //internal:
         CLxMeta_Notifier_Core (const char *srvName);
        ~CLxMeta_Notifier_Core ();

        virtual CLxNotifier_Core *	 new_inst () = 0;
        virtual void			 visit_raw (CLxNotifier_Core *) = 0;

        void *		 alloc () LXx_OVERRIDE;
        void		 enumerate_raw ();

        class pv_Meta_Notifier *pv;
};

/*
 * Metaclass template for specialization by notifier and event classes.
 */
template <class T, class E>
class CLxMeta_Notifier :
                public CLxMeta_Notifier_Core
{
    public:
        /*
         * Set the notifier server name in the constructor.
         */
        CLxMeta_Notifier (const char *srvName) : CLxMeta_Notifier_Core (srvName) { }

        /*
         * Call to send an event to all notifiers.
         */
                void
        notify (
                E			 event)
        {
                cur_event = event;
                enumerate_raw ();
        }

    //internal:
        E		 cur_event;

                void
        visit_raw (
                CLxNotifier_Core	*noti)			LXx_OVERRIDE
        {
                T			*t = dynamic_cast<T *> (noti);
                unsigned		 f;

                f = t->change_flags (cur_event);
                if (f)
                        noti->notify_cmd (f);
        }

                CLxNotifier_Core *
        new_inst ()
        {
                return new T;
        }
};


/*
 * ----------------------------------------------------------------
 * -- Utilities
 */

/*
 * This class is useful for keeping a command block open as long as it's
 * in scope. As soon as the object goes out of scope, the block is closed.
 */
class CLxOpenCommandBlock
{
    public:
         CLxOpenCommandBlock (const char *name, unsigned flags = 0);
        ~CLxOpenCommandBlock ();

        CLxUser_CommandService cmd_S;
};


/*
 * The CLxNotifierHost class is used to hold onto a list of notifiers and
 * add and remove clients.
 */
class CLxNotifierHost :
                public CLxObject
{
    public:
         CLxNotifierHost ();
        ~CLxNotifierHost ();

        void		 add (const char *name, const char *args);
        void		 add (std::string name, std::string args);
        void		 add_client (ILxUnknownID);
        void		 rem_client (ILxUnknownID);
        void		 set_arg (CLxDynamicArguments &, unsigned);

        class pv_NotifierHost	*pv;
};



// ------------ following declaractions are deprecated
//@skip


/*
 * ----------------------------------------------------------------
 * The CLxBasicCommand class provides a framework for implementing simple
 * commands. Derived classes provide the command flags, arguments and argument
 * flags, and the basic command manages storing the arguments and the command
 * result message.
 */
class CLxBasicCommand :
                public CLxImpl_Command,
                public CLxDynamicArguments
{
    public:
                         CLxBasicCommand ();
        virtual		~CLxBasicCommand ();

        virtual	int	basic_CmdFlags	() = 0;
        virtual bool	basic_Notifier	(int index, std::string &name, std::string &args)
                                { return false; }
        virtual void	basic_Notifiers	()
                                {}
        virtual bool	basic_Enable (CLxUser_Message &msg)
                                { return true; }
        virtual const char *
                        basic_ArgType (unsigned int index)
                                { return 0; }
        virtual bool	basic_ButtonName (std::string &)
                                { return false; }
        virtual bool	basic_IconName (std::string &)
                                { return false; }

        virtual void	basic_Interact ()
                                { }
        virtual void	basic_Execute (unsigned flags)
                                { }

        const char *	dyna_GetType (unsigned index) LXx_OVERRIDE
                                { return basic_ArgType (index); }

        void		basic_SetFlags	(unsigned int index, unsigned int flags);
        CLxUser_Message&basic_Message	();
        void		basic_AddNotify	(const std::string &name, const std::string &args);
        void		basic_AddNotify	(const char *name, const char *args);

        LxResult	cmd_Enable	(ILxUnknownID msg)				LXx_OVERRIDE;
        LxResult	cmd_Flags	(unsigned int *flags)				LXx_OVERRIDE;
        LxResult	cmd_ArgFlags	(unsigned int index, unsigned int *flags)	LXx_OVERRIDE;
        LxResult	cmd_ArgClear	(unsigned int index)				LXx_OVERRIDE;
        LxResult	cmd_ArgResetAll	()						LXx_OVERRIDE;
        LxResult	cmd_ArgSetDatatypes ()						LXx_OVERRIDE;
        LxResult	cmd_ArgEnable	(unsigned int arg)				LXx_OVERRIDE;
        LxResult	cmd_Message	(void **ppvObj)					LXx_OVERRIDE;
        LxResult	cmd_ButtonName	(const char **name)				LXx_OVERRIDE;
        LxResult	cmd_Icon	(const char **name)				LXx_OVERRIDE;
        void		cmd_Interact	()						LXx_OVERRIDE;
        void		cmd_Execute	(unsigned flags)				LXx_OVERRIDE;

        LxResult	cmd_NotifyAddClient	(int argument, ILxUnknownID object)	LXx_OVERRIDE;
        LxResult	cmd_NotifyRemoveClient	(ILxUnknownID object)			LXx_OVERRIDE;

    private:
        class pv_BasicCommand	*pv;
};


/*
 * ----------------------------------------------------------------
 * Popup Choice Command
 *
 * The CLxPopupChoiceCommand is a variation of the basic command that can
 * be used to create popup choice controls. Argument zero will be given the
 * name and datatype specified in the constuctor. The subclass client fills
 * in two methods:
 *
 *	GetCurrent(va)	generates the list of current values for the popup.
 *			Typically this involves walking the selection and
 *			calling va.Add() for each selected value.
 *
 *	GetChoices2(user, internal, tooltip)
 *			fills in the list of choices to be displayed in the
 *			popup. The meaning of the lists is the same as when
 *			used in the CLxUIListPopup class.
 *
 *	GetChoices(user, internal)
 *			same as above, but only for user and internal lists.
 *			This is called if GetChoices2() is not overridden.
 */
class CLxPopupChoiceCommand :
                public CLxBasicCommand
{
    public:
        CLxPopupChoiceCommand (const char *name, const char *type);

        virtual void	popcmd_GetCurrent (CLxUser_ValueArray &va) = 0;
        virtual void	popcmd_GetChoices2 (std::vector<std::string> &user, std::vector<std::string> &internal, std::vector<std::string> &tooltip);
        virtual void	popcmd_GetChoices (std::vector<std::string> &user, std::vector<std::string> &internal) {}

        CLxDynamicUIValue *
                        atrui_UIValue	(unsigned int index)			   LXx_OVERRIDE;
        LxResult	cmd_Query	(unsigned int index, ILxUnknownID vaQuery) LXx_OVERRIDE;
};


/*
 * ----------------------------------------------------------------
 * Construtors on template classes can kind of work like functions with
 * parameterized types. Declaring and installing a command server derived from
 * CLxBasicCommand can be done by instantiating this object with the client's
 * subclass and the server name.
 *
 *	initialize ()
 *	{
 *		CLxExport_BasicCommand<CMyCommand> ("myCommandName");
 *	}
 */
template <class T>
class CLxExport_BasicCommand
{
    public:
        CLxExport_BasicCommand (
                const char		*name)
        {
                CLxGenericPolymorph	*srv;

                srv = new CLxPolymorph<T>;
                srv->AddInterface (new CLxIfc_Command     <T>);
                srv->AddInterface (new CLxIfc_Attributes  <T>);
                srv->AddInterface (new CLxIfc_AttributesUI<T>);
                lx::AddServer (name, srv);
        }
};


/*
 * ----------------------------------------------------------------
 * The CLxCommandNotifier class is used to create new notifier servers.
 */
class CLxCommandNotifier :
                public CLxImpl_Notifier
{
    public:
                                 CLxCommandNotifier (const char *);
        virtual			~CLxCommandNotifier ();

        virtual void		cn_Parse (std::string &args) {}
        virtual unsigned int	cn_Flags (int code) { return LXfCMDNOTIFY_VALUE; }

        LxResult		noti_Name         (const char **name)   LXx_OVERRIDE;
        LxResult		noti_SetArgs      (const char  *args)   LXx_OVERRIDE;
        LxResult		noti_Args         (const char **args)   LXx_OVERRIDE;
        LxResult		noti_AddClient    (ILxUnknownID object) LXx_OVERRIDE;
        LxResult		noti_RemoveClient (ILxUnknownID object) LXx_OVERRIDE;

        static void		Notify (const char *, int code);

    private:
        class pv_CommandNotifier	*pv;
};


/*
 * ----------------------------------------------------------------
 * The CLxItemTypeOperator class can be used as a help to create commands
 * that operate on a specific type of selected item. The item_sel member
 * will be initialized to the desired item type, and the various command-like
 * method can be called to implement basic command methods:
 *
 *	op_Notifier	-> basic_Notifier
 *	op_Enable	-> basic_Enable
 *	op_Execute	-> cmd_Execute
 *	op_GetCurrent	-> popcmd_GetCurrent
 *	op_GetChoices	-> popcmd_GetChoices
 *
 * The client implements the virtual methods that operate on only one item
 * at a time.
 *
 *	op_item_exec(item)
 *			execute command on the item
 *
 *	op_item_current(item, va)
 *			add the current value for the item to the array
 *
 *	op_item_choices(item)
 *			add choices for this item by calling op_add_choice()
 */
class CLxItemTypeOperator
{
    public:
        CLxItemSelectionType	 item_sel;

                 CLxItemTypeOperator (const char *type);
        virtual	~CLxItemTypeOperator ();

        bool		op_Notifier (unsigned index, std::string &name, std::string &args);
        bool		op_Enable ();
        void		op_Execute ();
        void		op_GetCurrent (CLxUser_ValueArray &va);
        void		op_GetChoices (std::vector<std::string> &user, std::vector<std::string> &internal);
        void		op_add_choice (const char *user, const char *internal = 0);

        virtual void	op_item_exec (CLxUser_Item &item) {}
        virtual void	op_item_current (CLxUser_Item &item, CLxUser_ValueArray &va) {}
        virtual void	op_item_choices (CLxUser_Item &item) {}

    private:
        class pv_ItemTypeOperator	*pv;
};

/* Static Analysis Commands
* This is a wrapper around Basic Command used for writing simple "Static Analysis" tests for modo scenes.
* The subclass of this should just need to implement the sa_ functions, and the wrapper will handle running tthe test and passing in the correct items.
*/

class CLxStaticAnalysisTest : public CLxBasicCommand
{

public:
        CLxStaticAnalysisTest();

        // Standard "BasicCommand" functions.
        LxResult cmd_Query(unsigned int index, ILxUnknownID vaQuery) override;
        int basic_CmdFlags() override;
        void basic_Execute(unsigned flags) override;

        // A name for the test - this appears in the tree view
        virtual const char* sa_Name();
        // A string defining a semi-colon split set of categories for filtering (eg. Test1;Test2)
        virtual const char* sa_Category();
        // The text representation of the Item type to test agasint (eg. "mesh")
        virtual const char* sa_ItemType();
        // more indepth tooltip for errors / information.
        virtual const char* sa_ToolTip();
    // Return whether the passed in item passes or fails the test (a non-empty string is a fail, and forms the error message)
        virtual std::string sa_Test(CLxUser_Item item);
        // Function to attempt to fix the item for the test
        virtual bool sa_Fix(CLxUser_Item item);
        // Select the test item
    virtual void sa_Select(CLxUser_Item item, std::string mode="");
    // Tags is required to register as a static analysis command
        static LXtTagInfoDesc	 descInfo[];
protected:
        // Num of attributes defined by the test
        int DefaultArgumentsCount;
private:
        // Reads the tags on the item to see if the passed in ingoreKey is present. This is usually the command name
        bool IsIgnored(CLxUser_Item testItem);

        // runs the tests across all items of specified type
        void RunTests(CLxUser_ValueArray vaArray);

        // Tests one item, appends results.
        void DoTest(CLxUser_ValueArray vaArray, CLxUser_Item testItem);

        // Gets the item that we are testing against
        CLxUser_Item GetTestItem();

        // splits the category string into the value array
        void SplitCategories(CLxUser_ValueArray va);

        bool GetMessageTableEntry(const char* inString, const char** outMsg);
        
        int idxItem;
        int idxRunFix;
        int idxCategory;
        int idxName;
        int idxRunTests;
        int idxIgnoreKey;
        int idxShowIgnored;
    int idxDoSelect;
    int idxSelectMode;
        int idxTooltip;
};

/* Template for registering Static Analysis tests
*  eg CLxRegisterStaticAnalysisTest<CTestStaticTest>("TestStaticAnalysisTest");
* This is different from Export_BasicCommand in that we also need the StaticDesc.
*/

template <class T>
class CLxRegisterStaticAnalysisTest
{
public:
        CLxRegisterStaticAnalysisTest(
                const char* name)
        {
                CLxGenericPolymorph* srv;

                srv = new CLxPolymorph<T>;
                srv->AddInterface(new CLxIfc_Command     <T>);
                srv->AddInterface(new CLxIfc_Attributes  <T>);
                srv->AddInterface(new CLxIfc_AttributesUI<T>);
                srv->AddInterface(new CLxIfc_StaticDesc		<T>);
                lx::AddServer(name, srv);
        }
};

#endif /* LX_COMMAND_HPP */

