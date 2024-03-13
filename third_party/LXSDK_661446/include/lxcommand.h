/*
 * LX command module
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
 */
#ifndef LX_command_H
#define LX_command_H

typedef struct vt_ILxCommand ** ILxCommandID;
typedef struct vt_ILxCommandDBHelp ** ILxCommandDBHelpID;
typedef struct vt_ILxUIHints ** ILxUIHintsID;
typedef struct vt_ILxUIHintsRead ** ILxUIHintsReadID;
typedef struct vt_ILxUIValueHints ** ILxUIValueHintsID;
typedef struct vt_ILxUIValueHints3 ** ILxUIValueHints3ID;
typedef struct vt_ILxUIValueHints2 ** ILxUIValueHints2ID;
typedef struct vt_ILxUIValueHints1 ** ILxUIValueHints1ID;
typedef struct vt_ILxAttributesUI ** ILxAttributesUIID;
typedef struct vt_ILxCommandEvent ** ILxCommandEventID;
typedef struct vt_ILxCommand1 ** ILxCommand1ID;
typedef struct vt_ILxCommand2 ** ILxCommand2ID;
typedef struct vt_ILxCommand3 ** ILxCommand3ID;
typedef struct vt_ILxCommandBlock ** ILxCommandBlockID;
typedef struct vt_ILxCommandService ** ILxCommandServiceID;
typedef struct vt_ILxCommandPostEnd ** ILxCommandPostEndID;
typedef struct vt_ILxCmdSysListener ** ILxCmdSysListenerID;

#include <lxserver.h>
#include <lxvalue.h>

/*
 * This returns a command's tag.  This function is implemented by the command
 * system and does not need to be provided by the command itself.
 */

        typedef unsigned short	LXtCommandTag;
        #define LXiCTAG_NULL	((LXtCommandTag) 0)
    // See Also:  LXtCommandTag LXiCTAG



/*
 * These functions return the name, username, button name, description,
 * tooltip and example associated with an entry in the config.  Name always
 * returns the internal name of the command.  The other functions will
 * return either a string from the message table, or possibly a dynamic string
 * provided by the command based on its current arguments and environment,
 * falling back to the message table and possibly other reasonable defaults if
 * the method fails or is NULL.
 * 
 * The help method returns a key, which in turn is resolved into a URL from the
 * HelpURL part of the config.
 * 
 * Commands can also return an example string.
 * 
 * The icon name can also be obtained, which may be read directly from
 * cmdhelp.cfg or dynamically specified by the command's current arguments.
 * Note that this is the raw icon name without any size information attached.
 * Multiple icons can be specified in the icon name string, but this is not
 * required.  A simple icon string can just be "icon".  For multiple icons,
 * the form is "besticon;fallbackicon;defaulticon".  There can be any number of
 * icons; the first in the list will be tried, followed by the nexxt, and so on
 * until one matches at the size requested.  If the icon name contains a
 * semicolon, two semicolons can be used instead.
 * 
 * 
 * It is possible to for the command to use the value of its arguments during
 * the flags method. However, it is important to handle cases where the
 * arguments have no value, even if they are required arguments.  This can
 * happen when the prototype command is created, in which case no arguments
 * have yet been set.  In these cases, the client should just return default
 * flags without relying on the command's arguments.
 * 
 * Also available are "post-execution" flags.  The original flags assigned
 * to a command may change after a pending command has fired.  For example,
 * an undoable command firing non-undoable commands would itself become
 * non-undoable.  Post-fire flags are only available after a command has
 * been fired; if this hasn't yet occured, LXe_CMD_NOT_AVAILABLE is returned.
 * This function is provided by the command system and does not need to be
 * specified by commands themselves.
 * 
 * 
 * The exuection flags are also available.  These are the flags that were
 * passed to the Execute() method, and include the LXfCMD_EXEC_ and
 * LXfCMD_ALERT_ flags.  These are only valid after the command has been
 * executed.
 * 
 * 
 * Certain commands can only be executed within specific sandboxes.  If this method
 * returns LXe_CMD_SANDBOX_GLOBAL, then the command operates in the global sandbox.
 * LXeCMD_OK means that only a sandbox containing an object with the specific GUID
 * returned is supported.  Sandboxed commands can NOT be undoable.
 * 
 * Each command contains an ILxMessage object.  This can be obtained through the
 * following method.  This object is used for by the Execute() method and others
 * to report error states.  The client must release the message returned by this
 * method.
 * 
 * A command may be disabled based on the current environment.  This function can
 * be called to see if a command is enabled.  LXe_CMD_DISABLED will be returned
 * if the command is disabled and the message string will be set to a user-readable
 * string describing the condition.  This simply checks to see if the command itself
 * could be fired; it does not check to see if the arguments are set and valid.
 * There is an alternate disabled state, LXe_CMD_NOT_AVAILABLE.  This should be set
 * if there is no context at all for the command's arguments, not even enough to
 * display a control of the correct type in an attribute sheet (as the dynamic
 * datatypes arguments cannot be resolved).  An example is the item.channel command,
 * which requires an item selection so it can infer the type of channel; without that
 * selection, it cannot guess what kind of control to display.  LXe_CMD_DISABLED
 * should be used when the argument parsing and dynamic datatypes can still be set,
 * but there is no context for the command to execute in.
 * 
 * In general, the return code should match the code set in the ILxMessage object.
 * 
 * 
 * Commands in containers should provide a contained enable function.  This is called
 * by the container to see if the command can be executed.  The ID_NULL-terminated
 * types array should tested be with SelTopmostType() to ensure that they are
 * the topmost type in the container.
 * 
 * Just before the command executes, the Interact() method is called.  This can
 * be used to open file and confirmation dialogs so the user can confirm that
 * they want to perform the operation.  This is particularly useful for MODEL
 * commands, since as soon as the Execute() method is called the undo stack
 * is discarded; by opening dialogs from Interact(), the undo stack is preserved
 * if the user chooses to abort.
 * The Interact() method does not return an error code.  Instead, the ILxMessageID
 * of the command is used just like it is in the Execute() method.  If the code is
 * anything besides LXe_OK(), the execute method is not called.
 * 
 * This method is not called if LXxCMD_IS_USER_INTERACTION_OK() would fail.  This
 * allows the user to suppress any dialogs that might have been opened, including
 * confirmation and file dialogs.  Commands should perform default behaviors if
 * this occurs.
 * 
 * 
 * We have one final test before Execute() is called.  The PreExecute() method
 * can be used to verify that the command state is set in such a way that it
 * can still execute.  This is most useful if the command requires a filename,
 * but the Interact() method was suppressed by the user, and the filename
 * argument was not set.  Rather than have a MODEL command fail and clear the
 * undo stack, it instead can do a final test to ensure the appropriate
 * arguments are set.  Again, no LxResult code is returned; instead, the
 * ILxMessageID that is part of the command itself is used to provide errors.
 * 
 * The user should only be presented with dialogs or questions if
 * LXxCMD_IS_USER_INTERACTION_OK() is true; otherwise, the command should handle
 * the case quietly.
 * Note that these flags are used by the command system itself, but are passed
 * on to the command for its own benefit.  Direct action should not be taken
 * by the command based on these flags, and they can be safely ignored.
 * 
 * 
 * Toggle commands have a single argument that can have one of many possible
 * but mutually exclusive states (for example, only one tool can be activate
 * at a time).  When inserted into an attribute sheet, a toggle button is created
 * that switches between an "off" state and the "on" state assigned to that arg
 * in the sheet definition.  When one of these buttons is activated, other
 * buttons using the same command but different "on" states are automatically
 * turned off.  tool.set is an example of a command that does this, creating
 * toggle buttons in attribute sheets that determined the currently active tool.
 * Note that when attrs sets up the UI for a toggle arg command, if the toggle
 * arg is optional and has no value, the command will be created as a simple
 * button, not a toggle command.
 * 
 * The command stores the "off" state in its definition, as well as the index
 * of the toggle argument and its ExoType as either (or both) an ID and name.
 * This method can retrieve any or all of these states.  The index, value, typeID
 * or typeName can be NULL if desired, in which case only the non-NULL arguments
 * will be set.  Note that the ppvObj value argument should be considered read-only, as
 * it is owned by the command.  However, the ILxValueID returned must be released
 * through XObjectRelease() by the client.
 * 
 * If no arguments are set for toggling in this manner, LXe_CMD_NOT_AVAILABLE is
 * returned.
 * 
 * 
 * Although most of the argument data is read from the command's ILxAttributes
 * interface, there is some extra information not encapsulated there.  This
 * method allows the flags of a particular argument to be read.
 * 
 * The INIT_ONLY flags are only set during initialization, and include the following:
 * - OPTIONAL
 * If present, the argument is optional for the command to work.  By default all
 * arguments are required.
 * 
 * - QUERY
 * If present, the query function can be used to get the value for a control.
 * Only arguments with this flag can be used in an Attribute Sheet.
 * 
 * - READONLY
 * If present, the argument is not editable by the user, and is there purely to
 * provide statistical information, such as point/polygon counts or image bit
 * depth.  Read only arguments display as special labels in forms, not as
 * interactive controls.  Read-only implies queriable.
 * 
 * - VARIABLE
 * If present, the datatype for the argument is variable.  The datatype must be
 * set with the datatype callback using the REQFORVARIABLE arguments as keys, and
 * thus this flag is not compatible with REQFORVARIABLE.
 * 
 * - DYNAMICHINTS
 * If present, the text hints array member is overridden by the callback provided
 * to CmdDefineTextHintFunc().  See that function for more information.  The hints
 * array can still be provided and used as defaults if the callback returns NULL.
 * REQFORVARIABLE arguments will be set before this function is called, and thus
 * REQFORVARIABLE and DYNAMICHINTS are not compatible.
 * 
 * - REQFORVARIABLE
 * If present, the argument is used as to determine the datatype of a variable
 * argument.  These arguments will be set before any others, allowing them to
 * be read from the datatype and dynamic hints callbacks for setting those
 * argument's datatypes and hints.  They will not show up in the command
 * dialogs, since changing them could change the type of control presented in
 * the dialog.  Note that it is technically legal to have an argument that is
 * both OPTIONAL and REQFORVARIABLE; in this case, the argument is required only
 * if it is set, and it is up to the command to make sure it is set before trying
 * to use it, and it must handle the case of the argument not being set.
 * 
 * - HIDDEN
 * If present, the argument can be entered from a command line, but is not shown
 * in the command dialog.  This is useful for arguments that are only really
 * uesful internally or from scripts but not in the command dialog.
 * 
 * - DYNAMIC_DEFAULTS
 * If set, the default values for the argument will always be used when displaying
 * in a dialog.  Normally, the dialog caches non-query arguments so the same value
 * will show up the next time the dialog is opened, but behavior isn't desirable for
 * dynamically-computed values.
 * 
 * - LXfCMDARG_DIALOG_ALWAYS_SETS
 * Normally, when a command dialog is opened for the user, only the arguments the
 * user has actually changed will be passed to the client.  If this flag is set,
 * an optional argument will always get a value if the dialog was opened, even if
 * the user did not change the value.  This is useful when the previous dialog values
 * are used as defaults for another argument's value, such as in poly.setMaterial.
 * 
 * - LXfCMDARG_CAN_QUERY_WHEN_DISABLED
 * Normally, if the command is disabled, none of its arguments can be queried.
 * This simplifies the command's Query() method by removing the need to repeat
 * the enable test there where the query relies on the current system state.
 * However, there are times when a command is disabled even though a query state
 * is available, and thus can still display a useful state in the UI.  A common
 * case is tool and item properties, where the user has turned off a feature
 * via a checkmark, which in turn causes this command's control to appear disabled
 * in the interface.
 * 
 * - LXfCMDARG_DIALOG_DIVIDER_AFTER_ARG
 * If set, an divider will be inserted between the controls representing this
 * argument and the next argument in the command's dialog.  This allows for some
 * extra organization within the dialog.
 * 
 * The STATE_ONLY flags are used for testing the current state of arguments:
 * 
 * As of modo 701, this flag has been superceded by the more powerful
 * DialogFormatting() method.
 * 
 * - VALUE_SET
 * If present, the value of an argument has been set by the user (but does not
 * necessarily represent an internal default) and can be retrieved from the
 * ILxAttributes interface.  If not present, the value has not been set by the
 * user; however, a static default value may still be present.  Furthermore,
 * both default and queried values (which can be based on the system state)
 * may be different from the set value.  Arguments without this flag set will
 * not be displayed in the command history.
 * 
 * You should only set the VALUE_SET flag for your argument if your command's
 * ILxAttributes interface's SetFlt(), SetInt() or SetString() have been called,
 * or if Value() was called with writeOK set to true.  Until then, the argument
 * should be considered unset, but calls to GetFlt(), GetInt(), GetString() and
 * Value() should still succeed by returning a default initial value for the
 * argument.
 * 
 * - CHANGED
 * If present, the value of an argument has been changed through the DialogArgChange()
 * method.  This lets the command system know that it should use this value, even if
 * VALUE_SET is false or the value can be queried.  This is only used for command
 * dialogs.
 * 
 * - REQFORVAR_SET
 * If present, then ILxCommand::ArgSetDatatypes() has been called and the variable
 * datatype arguments have had their datatypes set.  This means that the values of
 * variable datatype arguments can now be set, and required-for-variable arguments
 * are now "locked".  Note that this flag is the same for all arguments, and is
 * really a property of the command and not a single argument.  This flag is not
 * relevant if the command does not have any variable datatype arguments.
 * 
 * 
 * These macros are provided for quick tests on specific arguments.
 * 
 * - ISREQFORVARIABLE()
 * This returns true if the argument is required to set a variable argument's
 * datatype.
 * 
 * - ISVARIABLE()
 * This returns true if the argument has a variable datatype.
 * 
 * - ISREQUIRED()
 * A pure required argument is one that has none of these flags set, or only
 * the REQFORVARIABLE flag.  Required-for-variable-datatype arguments must be
 * set before the command can be run (although optional ones need not be set
 * at all).  This returns true if this is the case.
 * 
 * - ISNEEDED()
 * Arguments that are not OPTIONAL or READONLY arguments must have a value
 * before the command can be run.  This can be used to test an argument to see
 * if it is needed.
 * 
 * - ISQUERY()
 * This returns true if the value of an argument can be obtained directly from the
 * command.  LXfCMDARG_QUERY and LXfCMDARG_READONLY arguments can do this.
 * 
 * - ISSET()
 * This returns true if the value of an argument is set, and false if not.
 * 
 * 
 * This clears the value for an argument, resetting its VALUE_SET flag.
 * 
 * 
 * This clears the values of all arguments in the command.
 * 
 * Commands that have arguments with dynamic datatypes can use this function to
 * set those datatypes.  This will be called by the command system itself when
 * all required for variable arguments have been set, and then whenever a required
 * for variable argument's value changes.
 * When changing an argument's datatype, it is assumed that the argument's value
 * has also been cleared.  If the arguments new datatype is the same as the old
 * datatype (so, the datatype didn't actually change), the argument's value should
 * not be cleared.
 * 
 * 
 * Arguments also have user-readable names provided through these methods.  Note
 * that the wrapper will always return a valid string if the argument index is
 * valid, and return LXe_CMD_NOT_AVAILABLE otherwise.
 * 
 * 
 * Some arguments use text hints to display a list of choices.  Text hints
 * are represented as internal strings that are not very human-readable.  UI-
 * friendly strings can be obtained via an "ArgumentType" atom on the argument's
 * cmdhelp.  This in turn references an "ArgumentType" hash at the root of the
 * "CommandHelp" block, and contains usernames and descriptions for each text
 * hint, and for the ArgumentType itself.  Because the ArgumentType is stored
 * at the root of the CommandHelp block, the same ArgumentType can be used to
 * provide user strings for multiple commands that use the same text hints.
 * Information about the ArgumentType can be accessed with these functions.
 * ArgType() returns the internal argument type name, which may be fail if no
 * type is set in cmdhelp; the other functions return human-readable strings
 * if available.
 * 
 * 
 * The individual options in the argument type (such as popup entries) can also
 * be listed.  The username method will always return a valid string, falling
 * back to the internal name if no username can be found.  index is the index
 * of the argument, while optIndex is the index of the choice in the
 * LXtTextValueHint array.  Note that optIndex is not the index into the array,
 * but specifically the index of the element that is identified as a choice
 * the user can select, thus omitting entries like "&min" and other special
 * hints.
 * 
 * 
 * If all required arguments of a command aren't set by the user when it is executed, a
 * dialog is opened to ask for those values.  This method is called to allow the dialog
 * to set the values of any of its arguments after the last used dialog values and
 * any queried values have been plugged in.  Note that some or none of arguments may
 * have values when this method is called.
 * 
 * 
 * This method is called by command dialogs and similar entities to let the command
 * know that one of its arguments has been changed by the user.  It allows the
 * command to change the value of any of its arguments to provide more useful default
 * values based on system state or the set values of other arguments.  For example,
 * the poly.subdivide command has a different default "Max Smoothing Angles "depending
 * on what the mode argument is set to.
 * Note that the flag LXfCMDARG_CHANGED should be set on arguments whos values have
 * been modified by the change function, and the LXfCMDARG_VALUE_SET flag should be
 * unset (since the changed value is presumably a default of some sort).  The CHANGED
 * flag lets the command system know that it should use the current argument value,
 * while unsetting VALUE_SET tells the command system to not include that value in
 * the output string in the command history.
 * 
 * 
 * Dialogs will often call this method to see if a control within should be enabled
 * or disabled.  An example is that the Max Smoothing Angle control in the poly.subdivide
 * command should be disabled when in Faceted mode.  Return LXe_OK if enabled or
 * LXe_CMD_DISABLED if disabled.
 * 
 * Normally, the command system automatically parses arguments for each command.
 * However, commands are also given an opportunity to manually parse the arguments
 * themselves.  This method is called for each argument just before its value is
 * parsed out of the command line.  If the method handles all argument parsing, it
 * should return LXe_OK and set its own value.  If it wants the command system to
 * parse the argument, this should return LXe_NOTIMPL.
 * It is important to note that this function is called only when the arguments
 * are parsed as a string; directly setting the argument values via the
 * ILxAttributes interface will not call this function as the arguments are already
 * in in their intrinsic forms and never presented as strings.
 * 
 * 
 * This function copies the dynamic contents of one command into another.  This
 * should include everything possible, such as the argument values and error
 * states.
 * Note that this will only work on commands that have the same tag; dissimilar
 * commands can not be copied to each other.  For this reason, it can be assumed
 * that the two instances have the same internal data and thus can be manipulated
 * directly without the need to go through the interface when creating an
 * implementation.
 * 
 * To create a new duplicate of a command, use the command system global's
 * SpawnFromCommand() method.
 * 
 * 
 * Querying is done through this function.  An ILxValueArray interface is provided to
 * the command, which is filled in with as many values as the current argument may
 * represent in the current environment.  This is the main way that clients can
 * ask commands about their VALUE argument's default states.  The values in the
 * ILxQuery will have the same datatype as the argument being queried.
 * 
 * Commands need to communicate with clients, such as the attribute system, when
 * their data needs to be refreshed in the user interface.  The client calls this
 * method to let the command know that it wants to be notified when it needs to
 * be updated.
 * Normally, a client asks specifically for the notifier associated with a single
 * argument of a command (say, because it's displaying a UI for the queried value
 * of that argument), so the client needs to specify which argument they would like
 * additional notifiers from.  If the argument index is -1, then only the notifers
 * defined by the entire command will be added.
 * 
 * Clients rarely have to implement this method themselves, but can if they want to.
 * If not implemented, adding and removing clients is handled automatically by
 * calling the command's ILxUIValueHInts::NotifierCount() and NOtifierByIndex()
 * methods.
 * 
 * 
 * When a client no longer needs to listen for notifications, it calls this method.
 * Clients should be automatically removed from the queue when the command object
 * is released as well.
 * 
 * Any argument not included in the string will be omitted from the dialog.  This can be
 * used as an alternative to the HIDDEN argument flag.  The command dialog will not open
 * if all arguments are hidden, and the command will simply fail.
 * 
 * This alternative to the Icon() method allows a command to return a dynamically-defined
 * image.  This is rarely used, as the config-based Icon() method is preferable in most
 * cases.  The image returned must be of the w and h provided; if not, the image will
 * simply be discarded and ignored.  In general, this method is called before calling
 * Icon(), with Icon() being used if IconImage() is not implemented.
 * Note that as of 801, this is only supported on simple buttons in Form Views, and
 * is not used for popups, ToolChoices, pie menus, or any other kind of control.
 * 
 * The individual options in the argument type (such as popup entries) support icons
 * as well, if available.  The icon name should not have any size suffix, and _13, _20
 * or _32 will be added as needed by the caller.
 * 
 */
typedef struct vt_ILxCommand {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Tag) (
        LXtObjectID		 self,
        LXtCommandTag		*tag);
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		 self,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ButtonName) (
        LXtObjectID		 self,
        const char	       **buttonName);

        LXxMETHOD(  LxResult,
Desc) (
        LXtObjectID		 self,
        const char	       **desc);

        LXxMETHOD(  LxResult,
Tooltip) (
        LXtObjectID		 self,
        const char	       **tooltip);
        LXxMETHOD(  LxResult,
Help) (
        LXtObjectID		 self,
        const char	       **help);
        LXxMETHOD(  LxResult,
Example) (
        LXtObjectID		 self,
        const char	       **example);
        LXxMETHOD(  LxResult,
Icon) (
        LXtObjectID		 self,
        const char	       **iconNames);
        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		 self,
        unsigned int	        *flags);
        LXxMETHOD(  LxResult,
PostExecFlags) (
        LXtObjectID		 self,
        unsigned int	        *flags);
        LXxMETHOD(  LxResult,
PostExecBehaviorFlags) (
        LXtObjectID		 self,
        unsigned int	        *flags);
        LXxMETHOD(  LxResult,
PostExecHints) (
        LXtObjectID		 self,
        unsigned int		*hints);
        LXxMETHOD(  LxResult,
SandboxGUID) (
        LXtObjectID		  self,
        const LXtGUID		**guid);
        LXxMETHOD(  LxResult,
Message) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Enable) (
        LXtObjectID		  self,
        LXtObjectID		  msg);
        LXxMETHOD(  LxResult,
ContainedEnable) (
        LXtObjectID		  self,
        LXtID4			 *types);
        LXxMETHOD( void,
Interact) (
        LXtObjectID		  self);
        LXxMETHOD( void,
PreExecute) (
        LXtObjectID		  self);
        LXxMETHOD(  void,
Execute) (
        LXtObjectID		 self,
        unsigned int		 flags);
        LXxMETHOD(  LxResult,
ToggleArg) (
        LXtObjectID		  self,
        unsigned int		 *index,
        void			**ppvObj,
        unsigned int		 *typeID,
        const char		**typeName);
        LXxMETHOD(  LxResult,
ArgFlags) (
        LXtObjectID		  self,
        unsigned int		  index,
        unsigned int		 *flags);
        LXxMETHOD(  LxResult,
ArgClear) (
        LXtObjectID		  self,
        unsigned int		  index );
        LXxMETHOD(  LxResult,
ArgResetAll) (
        LXtObjectID		  self );
        LXxMETHOD(  LxResult,
ArgSetDatatypes) (
        LXtObjectID		  self );
        LXxMETHOD(  LxResult,
ArgUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **desc);

        LXxMETHOD(  LxResult,
ArgExample) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **example);
        LXxMETHOD(  LxResult,
ArgType) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **type);

        LXxMETHOD(  LxResult,
ArgTypeUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgTypeDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **desc);
        LXxMETHOD(  LxResult,
ArgOptionUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		 optIndex,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgOptionDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		 optIndex,
        const char	       **desc);
        LXxMETHOD(  LxResult,
DialogInit) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
DialogArgChange) (
        LXtObjectID		  self,
        unsigned int		  arg);
        LXxMETHOD(  LxResult,
ArgEnable) (
        LXtObjectID		  self,
        unsigned int		  arg);
        LXxMETHOD(  LxResult,
ArgParseString) (
        LXtObjectID		  self,
        unsigned int		  argIndex,
        const char		 *argString);
        LXxMETHOD(  LxResult,
Copy) (
        LXtObjectID		  self,
        LXtObjectID		  sourceCommand );
        LXxMETHOD(  LxResult,
Query) (
        LXtObjectID		  self,
        unsigned int		  index,
        LXtObjectID		  vaQuery );
        LXxMETHOD(  LxResult,
NotifyAddClient) (
        LXtObjectID		  self,
        int			  argument,
        LXtObjectID		  object);
        LXxMETHOD(  LxResult,
NotifyRemoveClient) (
        LXtObjectID		  self,
        LXtObjectID		  object);
        LXxMETHOD(  LxResult,
DialogFormatting) (
        LXtObjectID		  self,
        const char		**formatting);
        LXxMETHOD(  LxResult,
IconImage) (
        LXtObjectID		  self,
        int			  w,
        int			  h,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ArgOptionIconName) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		 optIndex,
        const char	       **iconName);
} ILxCommand;

/*
 * Same idea, but for tooltips.
 */
typedef struct vt_ILxCommandDBHelp {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
DBHelp) (
        LXtObjectID		 self,
        const char	       **dbhelp);
        LXxMETHOD(  LxResult,
DBTooltip) (
        LXtObjectID		 self,
        const char	       **dbtooltip);
} ILxCommandDBHelp;

/*
 * Class changes the class of an attribute.  The class change should be consistent
 * with the argument type.  Classes match those used by the old XPanels system
 * ("iBoolean", "integer", "iPopChoice", etc).
 * The argument's user-readable label can be set with this method.  The string
 * should be translated into the user's language.
 * 
 * These can be used to set the minimum and maximum for integer and float-based
 * controls.
 * 
 * This controls the step size of a minislider.
 * 
 * If tracking is turned on, drags on the minislider will cause instant updates.
 * 
 * Choice/Popup controls can take a simple string list if desired.
 * 
 * String controls can have multiple lines, as set by this hint.
 * 
 * String controls can also be told to use a fixed width font.
 * 
 * Sometimes it is useful for string controls to obscure their text,
 * such as when entering a password, which can be set with this method.
 * 
 * Control types like numeric edit fields support "value presets".  This creates
 * a popup containing a user-extensible list of common values for the argument.
 * For example, rather than forcing the user to lookup or remember what the index
 * of refraction is for glass, they can simply click on the popup and select
 * glass from the list.
 * Value presets are handled completely automatically by the attributes/forms system.
 * All the client needs to do is provide a cookie, which is used to load and save
 * the list of values from the config.  The cookie can be shared by multiple controls
 * if desired, and need not be unique.
 * 
 * 
 * Force update is a special flag; if set, this will force the UI to refresh even if
 * the UI object hasn't otherwise changed since the last time the UI object was
 * requested.  This is most useful if your popup functions changed their list of
 * properties since the last time they we called, thus forcing a refresh.
 * 
 * 
 * - OUTPUT_ONLY
 * If this is set on a channel, it is consider read-only, and cannot have an input.
 * If set, in schematic, the connection dot is displayed ONLY on the right side of the
 * node to indicate that it is an output only.
 * - INPUT_ONLY
 * If this is set on a channel, it is consider write-only, and cannot have an output.
 * If set, in schematic, the connection dot is displayed ONLY on the left side of the
 * node to indicate that it is an input only.
 * 
 * The INPUT_ONLY & OUTPUT_ONLY flags are mutually exclusive.
 * 
 * - SUGGESTED
 * If this is set on a channel, this channel should be added by default in schematic.
 * 
 * - HIDDEN
 * If marked as hidden, this channel will not be visible in the channel list.
 * 
 * 
 * Most buttons perform actions or are toggles.  Buttons that open dialogs usually have
 * ellipsis in the label (like "Save..."), and ToolChoices have a small triangle in the
 * lower-right corner.  It is also useful to mark buttons that open popovers differently
 * from the others.  This flag can be set to indicate executing the command opens a
 * popopover instead of performing an action, and will result in special decoration
 * being added to the button's face.
 * 
 * For ClipChoices (&clip datatype) the brower normally shows only clip items which
 * can be evalauted for an actual image. Flags can be set with this method to allow
 * other types of items as well.
 * - FOLDERS
 * Image folders, which are also clip item but have no composite image.
 * 
 * - GROUPS
 * Group items that contain images.
 * 
 * 
 * The type of vertex map. Default is UV map.
 * 
 * Specifies when a value of (none) is allowed in the list. Default is TRUE.
 * 
 * Specifies that the list is only generated from the selected item. Default is FALSE.
 * 
 * Info text controls (usually queried read-only command arguments) can be set to draw
 * with a small font instead of the default font.
 * 
 */
typedef struct vt_ILxUIHints {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Class) (
        LXtObjectID		  self,
        const char		 *c);
        LXxMETHOD(  LxResult,
Label) (
        LXtObjectID		  self,
        const char		 *label);
        LXxMETHOD(  LxResult,
MinInt) (
        LXtObjectID		  self,
        int			  min);

        LXxMETHOD(  LxResult,
MaxInt) (
        LXtObjectID		  self,
        int			  max);

        LXxMETHOD(  LxResult,
MinFloat) (
        LXtObjectID		  self,
        double			  min);

        LXxMETHOD(  LxResult,
MaxFloat) (
        LXtObjectID		  self,
        double			  max);
        LXxMETHOD(  LxResult,
StepInt) (
        LXtObjectID		  self,
        int			  step);

        LXxMETHOD(  LxResult,
StepFloat) (
        LXtObjectID		  self,
        double			  step);
        LXxMETHOD(  LxResult,
Track) (
        LXtObjectID		  self,
        unsigned int		  state);
        LXxMETHOD(  LxResult,
StringList) (
        LXtObjectID		  self,
        const char		**strings);
        LXxMETHOD(  LxResult,
TextLines) (
        LXtObjectID		  self,
        unsigned int		  lines);
        LXxMETHOD(  LxResult,
TextFixedWidthFont) (
        LXtObjectID		  self,
        unsigned int		  state);
        LXxMETHOD(  LxResult,
TextPasswordMode) (
        LXtObjectID		  self,
        unsigned int		  state);
        LXxMETHOD(  LxResult,
ValuePresetCookie) (
        LXtObjectID		  self,
        const char		 *cookie);
        LXxMETHOD(  LxResult,
ForceUpdate) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
BooleanStyle) (
        LXtObjectID		  self,
        unsigned int		  style);
        LXxMETHOD(  LxResult,
ChannelFlags) (
        LXtObjectID		  self,
        unsigned int		  flags);
        LXxMETHOD(  LxResult,
ButtonHasPopoverDecoration) (
        LXtObjectID		  self,
        int			  state);
        LXxMETHOD(  LxResult,
ClipChoiceSupportsGroups) (
        LXtObjectID		  self,
        unsigned		  flags);
        LXxMETHOD(LxResult,
VertmapType) (
        LXtObjectID		  self,
        LXtID4			  type);
        LXxMETHOD(LxResult,
VertmapAllowNone) (
        LXtObjectID		  self,
        int			  state);
        LXxMETHOD(LxResult,
VertmapItemMode) (
        LXtObjectID		  self,
        int			  state);
        LXxMETHOD(LxResult,
InfoTextUseSmallFont) (
        LXtObjectID		  self,
        int			  state);
        LXxMETHOD(LxResult,
FormFilterPriority) (
        LXtObjectID		  self,
        int			  priority);
} ILxUIHints;

/*
 * The remainder of the methods match those in ILxUIHInts; see the ILxUIHInts docs
 * for more information about how they are used and what values they return.  The
 * only method that is missing is StringList(), which is replaced with the enumeration
 * methods StringListCount() and StringListByIndex().
 * If a properly wasn't set in the ILxUIHInts, the associated method will return
 * LXe_NOTAVAILABLE.  Be sure to check the return code before using the returned
 * value.
 */
typedef struct vt_ILxUIHintsRead {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Class) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
Label) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
MinInt) (
        LXtObjectID		  self,
        int			  *min);

        LXxMETHOD(  LxResult,
MaxInt) (
        LXtObjectID		  self,
        int			  *max);

        LXxMETHOD(  LxResult,
MinFloat) (
        LXtObjectID		  self,
        double			  *min);

        LXxMETHOD(  LxResult,
MaxFloat) (
        LXtObjectID		  self,
        double			  *max);

        LXxMETHOD(  LxResult,
StepInt) (
        LXtObjectID		  self,
        int			 *step);

        LXxMETHOD(  LxResult,
StepFloat) (
        LXtObjectID		  self,
        double			 *step);

        LXxMETHOD(  LxResult,
Track) (
        LXtObjectID		  self,
        unsigned int		 *state);

        LXxMETHOD(  LxResult,
StringListCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
StringListByIndex) (
        LXtObjectID		  self,
        int			  index,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
TextLines) (
        LXtObjectID		  self,
        unsigned int		 *lines);

        LXxMETHOD(  LxResult,
TextFixedWidthFont) (
        LXtObjectID		  self,
        unsigned int		 *state);

        LXxMETHOD(  LxResult,
TextPasswordMode) (
        LXtObjectID		  self,
        unsigned int		 *state);

        LXxMETHOD(  LxResult,
ValuePresetCookie) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
ForceUpdate) (
        LXtObjectID		  self,
        int			 *state);

        LXxMETHOD(  LxResult,
BooleanStyle) (
        LXtObjectID		  self,
        unsigned int		 *style);

        LXxMETHOD(  LxResult,
ChannelFlags) (
        LXtObjectID		  self,
        unsigned int		 *flags);

        LXxMETHOD(  LxResult,
ButtonHasPopoverDecoration) (
        LXtObjectID		  self,
        int			 *state);

        LXxMETHOD(  LxResult,
ClipChoiceSupportsGroups) (
        LXtObjectID		  self,
        unsigned		 *flags);

        LXxMETHOD(LxResult,
VertmapType) (
        LXtObjectID		  self,
        LXtID4			 *type);

        LXxMETHOD(LxResult,
VertmapAllowNone) (
        LXtObjectID		  self,
        int			 *state);

        LXxMETHOD(LxResult,
VertmapItemMode) (
        LXtObjectID		  self,
        int			 *state);

        LXxMETHOD(LxResult,
InfoTextUseSmallFont) (
        LXtObjectID		  self,
        int			 *state);

        LXxMETHOD(LxResult,
FormFilterPriority) (
        LXtObjectID		  self,
        int			 *priority);
} ILxUIHintsRead;

/*
 * 
 * Popups are flat lists, and can be represented by integer or, preferably, string
 * stirng-based arguments.  Strings are prefereed because they are more scriptable
 * and the order can be changed more easily without affecting legacy use.
 * PopCount() returns the number of items in a popup.  PopUserName() returns a
 * human-readable string for display in the popup.  PopInternalName() returns an
 * untranslated, internal string that uniquely identifies theis item.  It is only
 * required when PopCategory() is used or when using a string-based argument.
 * 
 * 
 * Tooltips strings can be returned by individual entries in the popup.
 * 
 * Each entry in a poup can have an icon or image associated with it, which will appear
 * to the left of the entry's name.  This method returns the amount of space reserved
 * for the icons.  If not implemented, no space is reserved.
 * 
 * These return an icon for a specific entry.  If both fail, no icon will be drawn for
 * that entry.  The icon can be the name of an icon resource from a config file, or
 * a custom ILxImageID, which will be released by the popup system.
 * 
 * 
 * This returns the name of a category.  Combined with the popup functions defined above,
 * this can be used to create a hierarchical popup based on categorization defined through
 * the config.  Each entry is assigned to a part of the hierarchy by adding named entries
 * to the appropriate portion of the config file, and are easily extensible by third
 * parties by simply adding new config entries.  An example of category use is Add Layer
 * popup in the Shader Tree.
 * There is no flag matching this method; it will always be called for string-style
 * controls, but you can return LXe_NOTIMPL if you do not want to use categories in
 * your popup.
 * 
 * 
 * The ItemTest() method is used to decide if a particular item should appear in an
 * ItemChoice popup or not.  This allows you to limit an ItemChoice to only the specific
 * items that are releveant to you, rather than all items or all items of a given item
 * type.  Returning LXe_TRUE means that you want the item in the list, and LXe_FALSE
 * means that it should not be in the list.
 * 
 * Commands with arguments using the "color" datatype are available for use in the color
 * picker.  This happens automatically when the user clicks on a color control in a form,
 * which calls select.color to add the queried command to the color selection.  Any command
 * with a queriable "color"-datatype argument can be selected for the color picker through
 * select.color.
 * The limitation of the color controls adding the command that created them is that it
 * can only add a single command representing the RGB component of the color.  Sometimes
 * there is a related command that implements the alpha component.  Other times there is
 * an alternate color, such as the FG and BG colors used by the paint tools.
 * 
 * This method allows a command to override what commands are placed in the color picker
 * selection when a control created from this command's queried "color" argument is clicked
 * on by the user
 * 
 * A command can implement this method to return one or more command queries that should be
 * used in place of the command itself.  Note that the alpha commands are separate from the
 * RGB commands.  The useAlt command is used to decide if the main or alternate RGB and alpha
 * are displayed in the color picker, and is used to swap them.
 * 
 * RGB commands should have "color"-datatype arguments being queried.  For example,
 * "item.channel diffCol ?".  The queried argument is used both to get the current value
 * and to change the value when the user picks a new color.
 * 
 * Similarly, alpha commands should have a "percent"-datatype argument queried, and the
 * useAlt command should have a "boolean" argument queried.
 * 
 * All of these command are optional, and can be set to empty strings (first char '\0') to
 * skip them.  If the method is not implemented, the current color selection will be used.
 * If the RGB command string is empty, then the command itself will be used for that.  If the
 * alpha command is empty, then the alpha control in the color picker will be disabled.  If
 * rgbAlt is not empty, then the alternate color swatch and the swap icon will appear in the
 * color picker.  If the useAlt command is empty, "color.useAlt ?" will automatically be used
 * instead.
 * 
 * It is important to note that some clients may not want all the strings, in which case some
 * of the pointers may be NULL.
 * 
 * 
 * ILxUIValueHints is also used by tools attributes, item channels and other clients to
 * allow them to specify notifiers so that their representations in the user interface can
 * refresh when their values change.  This first method returns the number of notifiers
 * supported.
 * 
 * This second method returns the name of the notifier and its arguments as strings given
 * a notifier index.
 * 
 * The Form Command List (FCL) is a special feature used by very few commands.  It is
 * a powerful mechanism that allows a command to effectively dynamically insert controls
 * in a form by providing them as a list of command strings.  In this context, the
 * "owning" command itself will not be execute, but rather those in the Form Command
 * List may.
 * Here's how it works: when a command is in a form and an argument is queried, the
 * attrs/forms system will first check for the LXfVALHINT_FORM_COMMAND_LIST flag.
 * If not found, the command appears as normal.
 * 
 * If the flag is found, however, the command itself will not appear in the form.
 * Instead, each command represented by the strings returned by the Form Command
 * List will be displayed in instead.
 * 
 * If the command string starts with a dash and a space ("- "), then a divider will
 * be inserted into the form using whatever follows the space as the label (and which
 * is hopefully a translated, user-readable string).  Dividers can also include a
 * hash by placing one in curly braces between the prefix and the name (ie:
 * "- {MyHashHere} My Label Here").  This has is primarily used by form presets, and
 * enables form presets for that divider.  An empty hash (via "{}") is considered to
 * be no hash.
 * 
 * Ganging is also supported through its own special syntax.  Ganging is started by
 * prefixing a command string with an open curly brace and a space ("{ ").  All
 * controls after that will be ganged until a command prefixed with a closing curly
 * brace and a space ("} ") is found.  Note that even though the brace is closed before
 * the command string, the command is still considered part of the gang.
 * 
 * Viewports can be embedded in forms as well.  This can be done through presets and
 * viewport types.
 * 
 * Viewport presets can be embedded with "+vpPreset presetHash", where "presetHash" is
 * the hash of the preset as stored in the config.
 * 
 * A viewport type is added with "+vpType viewportType".  Arguments can then be set on
 * the instanced viewport by immediately following the "+vpType" line with one or more
 * "> argName argDataType argValue" lines, where "argName" is the internal name of the
 * viewport's argument, "argDataType" the internal name of the dargument's datatype, and
 * and everything after that space is the argument's value.  Any number of arguments
 * can be added this way.
 * 
 * Viewport types also have a special entry, "> =hash:".  This allows viewport types to
 * save their state to the config with a custom hash, which immediately follows the colon.
 * This is not supported for viewport presets, only for types.
 * 
 * Since UI hints are defined per argument, the argument must be marked as queriable,
 * even if the query method fails.
 * 
 * When commands exist solely for the purposes of creating an FCL
 * (item.channelsAsFormControls, for example), the LXfCMD_NO_EXEC command flag should
 * be set to indicate that it is not executable, after which the Execute() method does
 * not need to be implemented.  It also also suggested to providing the NoExecReason
 * cmdhelp atom to tell the user why the command does not support execution.
 * 
 * 
 * For strings, this is shown when the field contains no value and is otherwise completely
 * empty.  It is drawn dimmed, and disappears as soon as the user clicks in the field.
 * Cue text is also used as the default value for read-only string controls when the
 * string is empty so that we don't leave a hole in the interface.
 * 
 * For strings, this function will be called to validate the text value. It allows
 * the client to modify the string, performing operations such as removing invalid
 * characters, changing case, or clipping the length of the string.
 */
typedef struct vt_ILxUIValueHints {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD(  unsigned,
PopCount) (
        LXtObjectID		 self);

        LXxMETHOD(  const char *,
PopUserName) (
        LXtObjectID		 self,
        unsigned		 index);

        LXxMETHOD(  const char *,
PopInternalName) (
        LXtObjectID		 self,
        unsigned		 index);
        LXxMETHOD(  const char *,
PopToolTip) (
        LXtObjectID		 self,
        unsigned		 index);
        LXxMETHOD(  unsigned,
PopIconSize) (
        LXtObjectID		 self,
        int			*w,
        int			*h);
        LXxMETHOD(  LxResult,
PopIconImage) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
PopIconResource) (
        LXtObjectID		  self,
        int			  index,
        const char		**iconResource);
        LXxMETHOD(  LxResult,
PopFlags) (
        LXtObjectID		 self,
        unsigned		 index,
        int			*flags);
        LXxMETHOD(  LxResult,
PopCategory) (
        LXtObjectID		  self,
        const char		**category);
        LXxMETHOD(  LxResult,
ItemTest) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD(  LxResult,
ColorPickerCommands) (
        LXtObjectID		  self,
        char			 *rgb,
        char			 *alpha,
        char			 *rgbAlt,
        char			 *alphaAlt,
        char			 *useAlt,
        unsigned		  bufLens);
        LXxMETHOD(  LxResult,
NotifierCount) (
        LXtObjectID		  self,
        int			 *count);
        LXxMETHOD(  LxResult,
NotifierByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**name,
        const char		**args);
        LXxMETHOD(  LxResult,
FormCommandListCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
FormCommandListByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**command);
        LXxMETHOD(  LxResult,
CueText) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
TextValidate) (
        LXtObjectID		 self,
        const char		*value,
        char			*buf,
        unsigned		 len);
} ILxUIValueHints;

typedef struct vt_ILxUIValueHints3 {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD(  unsigned,
PopCount) (
        LXtObjectID		 self);

        LXxMETHOD(  const char *,
PopUserName) (
        LXtObjectID		 self,
        unsigned		 index);

        LXxMETHOD(  const char *,
PopInternalName) (
        LXtObjectID		 self,
        unsigned		 index);

        LXxMETHOD(  const char *,
PopToolTip) (
        LXtObjectID		 self,
        unsigned		 index);

        LXxMETHOD(  unsigned,
PopIconSize) (
        LXtObjectID		 self,
        int			*w,
        int			*h);

        LXxMETHOD(  LxResult,
PopIconImage) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
PopIconResource) (
        LXtObjectID		  self,
        int			  index,
        const char		**iconResource);

        LXxMETHOD(  LxResult,
PopFlags) (
        LXtObjectID		 self,
        unsigned		 index,
        int			*flags);

        LXxMETHOD(  LxResult,
PopCategory) (
        LXtObjectID		  self,
        const char		**category);

        LXxMETHOD(  LxResult,
ItemTest) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD(  LxResult,
ColorPickerCommands) (
        LXtObjectID		  self,
        char			 *rgb,
        char			 *alpha,
        char			 *rgbAlt,
        char			 *alphaAlt,
        char			 *useAlt,
        unsigned		  bufLens);

        LXxMETHOD(  LxResult,
NotifierCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
NotifierByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**name,
        const char		**args);

        LXxMETHOD(  LxResult,
FormCommandListCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
FormCommandListByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**command);
        
        LXxMETHOD(  LxResult,
CueText) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);
} ILxUIValueHints3;

typedef struct vt_ILxUIValueHints2 {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD(  unsigned,
PopCount) (
        LXtObjectID		 self);

        LXxMETHOD(  const char *,
PopUserName) (
        LXtObjectID		 self,
        unsigned		 index);

        LXxMETHOD(  const char *,
PopInternalName) (
        LXtObjectID		 self,
        unsigned		 index);

        LXxMETHOD(  unsigned,
PopIconSize) (
        LXtObjectID		 self,
        int			*w,
        int			*h);

        LXxMETHOD(  LxResult,
PopIconImage) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
PopIconResource) (
        LXtObjectID		  self,
        int			  index,
        const char		**iconResource);

        LXxMETHOD(  LxResult,
PopFlags) (
        LXtObjectID		 self,
        unsigned		 index,
        int			*flags);

        LXxMETHOD(  LxResult,
PopCategory) (
        LXtObjectID		  self,
        const char		**category);

        LXxMETHOD(  LxResult,
ItemTest) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD(  LxResult,
ColorPickerCommands) (
        LXtObjectID		  self,
        char			 *rgb,
        char			 *alpha,
        char			 *rgbAlt,
        char			 *alphaAlt,
        char			 *useAlt,
        unsigned		  bufLens);

        LXxMETHOD(  LxResult,
NotifierCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
NotifierByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**name,
        const char		**args);

        LXxMETHOD(  LxResult,
FormCommandListCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
FormCommandListByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**command);
} ILxUIValueHints2;

typedef struct vt_ILxUIValueHints1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD(  unsigned,
PopCount) (
        LXtObjectID		 self);

        LXxMETHOD(  const char *,
PopUserName) (
        LXtObjectID		 self,
        unsigned		 index);

        LXxMETHOD(  const char *,
PopInternalName) (
        LXtObjectID		 self,
        unsigned		 index);

        LXxMETHOD(  LxResult,
PopFlags) (
        LXtObjectID		 self,
        unsigned		 index,
        int			*flags);

        LXxMETHOD(  LxResult,
PopCategory) (
        LXtObjectID		  self,
        const char		**category);

        LXxMETHOD(  LxResult,
ItemTest) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD(  LxResult,
ColorPickerCommands) (
        LXtObjectID		  self,
        char			 *rgb,
        char			 *alpha,
        char			 *rgbAlt,
        char			 *alphaAlt,
        char			 *useAlt,
        unsigned		  bufLens);

        LXxMETHOD(  LxResult,
NotifierCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
NotifierByIndex) (
        LXtObjectID		  self,
        const char		**name,
        const char		**args);

        LXxMETHOD(  LxResult,
FormCommandListCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
FormCommandListByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**command);
} ILxUIValueHints1;

/*
 * This will allocate a value hints object for the given attribute, provided it
 * has any hints that need to be queried.  If index is LXiATTRUI_ANY, then
 * the object should represent hints for the entire command, tool, etc.  This
 * is most commonly used to obtain notifiers for a command when used as a button
 * in a form.
 * 
 * This returns an attribute-specific disabled message if the argument is disabled
 * by filling in an ILxMessageID.  If the attribute is enabled, the code is set to
 * LXe_OK; disabled attributes use the code LXe_DISABLED and may set a disabled
 * string as well. The value returned from the method itself should match the code
 * set in the ILxMessageID.
 * For example, a boolean attribute may control an overall setting,
 * while its sub-attributes are only valid if the boolean is true.  If the
 * boolean is false, then this function could return a message saying that the
 * boolean needs to be set true for all the sub-attributes.
 * 
 */
typedef struct vt_ILxAttributesUI {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
UIHints) (
        LXtObjectID		  self,
        unsigned int		  index,
        LXtObjectID		  hints);
        LXxMETHOD(  LxResult,
UIValueHints) (
        LXtObjectID		  self,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
DisableMsg) (
        LXtObjectID		  self,
        unsigned int		  index,
        LXtObjectID		  message);
} ILxAttributesUI;

typedef struct vt_ILxCommandEvent {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Event) (
        LXtObjectID		 self,
        unsigned int		 flags);
} ILxCommandEvent;

typedef struct vt_ILxCommand1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Tag) (
        LXtObjectID		 self,
        LXtCommandTag		*tag);

        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		 self,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ButtonName) (
        LXtObjectID		 self,
        const char	       **buttonName);

        LXxMETHOD(  LxResult,
Desc) (
        LXtObjectID		 self,
        const char	       **desc);

        LXxMETHOD(  LxResult,
Tooltip) (
        LXtObjectID		 self,
        const char	       **tooltip);

        LXxMETHOD(  LxResult,
Help) (
        LXtObjectID		 self,
        const char	       **help);

        LXxMETHOD(  LxResult,
Example) (
        LXtObjectID		 self,
        const char	       **example);

        LXxMETHOD(  LxResult,
Icon) (
        LXtObjectID		 self,
        const char	       **iconNames);

        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		 self,
        unsigned int	        *flags);

        LXxMETHOD(  LxResult,
PostExecFlags) (
        LXtObjectID		 self,
        unsigned int	        *flags);

        LXxMETHOD(  LxResult,
PostExecBehaviorFlags) (
        LXtObjectID		 self,
        unsigned int	        *flags);

        LXxMETHOD(  LxResult,
PostExecHints) (
        LXtObjectID		 self,
        unsigned int		*hints);

        LXxMETHOD(  LxResult,
SandboxGUID) (
        LXtObjectID		  self,
        const LXtGUID		**guid);

        LXxMETHOD(  LxResult,
Message) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
Enable) (
        LXtObjectID		  self,
        LXtObjectID		  msg);

        LXxMETHOD(  LxResult,
ContainedEnable) (
        LXtObjectID		  self,
        LXtID4			 *types);

        LXxMETHOD( void,
Interact) (
        LXtObjectID		  self);

        LXxMETHOD( void,
PreExecute) (
        LXtObjectID		  self);

        LXxMETHOD(  void,
Execute) (
        LXtObjectID		 self,
        unsigned int		 flags);

        LXxMETHOD(  LxResult,
ToggleArg) (
        LXtObjectID		  self,
        unsigned int		 *index,
        void			**ppvObj,
        unsigned int		 *typeID,
        const char		**typeName);

        LXxMETHOD(  LxResult,
ArgFlags) (
        LXtObjectID		  self,
        unsigned int		  index,
        unsigned int		 *flags);

        LXxMETHOD(  LxResult,
ArgClear) (
        LXtObjectID		  self,
        unsigned int		  index );

        LXxMETHOD(  LxResult,
ArgResetAll) (
        LXtObjectID		  self );

        LXxMETHOD(  LxResult,
ArgSetDatatypes) (
        LXtObjectID		  self );

        LXxMETHOD(  LxResult,
ArgUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **desc);

        LXxMETHOD(  LxResult,
ArgExample) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **example);

        LXxMETHOD(  LxResult,
ArgType) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **type);

        LXxMETHOD(  LxResult,
ArgTypeUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgTypeDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **desc);

        LXxMETHOD(  LxResult,
ArgOptionUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		 optIndex,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgOptionDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		 optIndex,
        const char	       **desc);

        LXxMETHOD(  LxResult,
DialogInit) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
DialogArgChange) (
        LXtObjectID		  self,
        unsigned int		  arg);

        LXxMETHOD(  LxResult,
ArgEnable) (
        LXtObjectID		  self,
        unsigned int		  arg);

        LXxMETHOD(  LxResult,
ArgParseString) (
        LXtObjectID		  self,
        unsigned int		  argIndex,
        const char		 *argString);

        LXxMETHOD(  LxResult,
Copy) (
        LXtObjectID		  self,
        LXtObjectID		  sourceCommand );

        LXxMETHOD(  LxResult,
Query) (
        LXtObjectID		  self,
        unsigned int		  index,
        LXtObjectID		  vaQuery );

        LXxMETHOD(  LxResult,
NotifyAddClient) (
        LXtObjectID		  self,
        int			  argument,
        LXtObjectID		  object);

        LXxMETHOD(  LxResult,
NotifyRemoveClient) (
        LXtObjectID		  self,
        LXtObjectID		  object);
} ILxCommand1;

typedef struct vt_ILxCommand2 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Tag) (
        LXtObjectID		 self,
        LXtCommandTag		*tag);

        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		 self,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ButtonName) (
        LXtObjectID		 self,
        const char	       **buttonName);

        LXxMETHOD(  LxResult,
Desc) (
        LXtObjectID		 self,
        const char	       **desc);

        LXxMETHOD(  LxResult,
Tooltip) (
        LXtObjectID		 self,
        const char	       **tooltip);

        LXxMETHOD(  LxResult,
Help) (
        LXtObjectID		 self,
        const char	       **help);

        LXxMETHOD(  LxResult,
Example) (
        LXtObjectID		 self,
        const char	       **example);

        LXxMETHOD(  LxResult,
Icon) (
        LXtObjectID		 self,
        const char	       **iconNames);

        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		 self,
        unsigned int	        *flags);

        LXxMETHOD(  LxResult,
PostExecFlags) (
        LXtObjectID		 self,
        unsigned int	        *flags);

        LXxMETHOD(  LxResult,
PostExecBehaviorFlags) (
        LXtObjectID		 self,
        unsigned int	        *flags);

        LXxMETHOD(  LxResult,
PostExecHints) (
        LXtObjectID		 self,
        unsigned int		*hints);

        LXxMETHOD(  LxResult,
SandboxGUID) (
        LXtObjectID		  self,
        const LXtGUID		**guid);

        LXxMETHOD(  LxResult,
Message) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
Enable) (
        LXtObjectID		  self,
        LXtObjectID		  msg);

        LXxMETHOD(  LxResult,
ContainedEnable) (
        LXtObjectID		  self,
        LXtID4			 *types);

        LXxMETHOD( void,
Interact) (
        LXtObjectID		  self);

        LXxMETHOD( void,
PreExecute) (
        LXtObjectID		  self);

        LXxMETHOD(  void,
Execute) (
        LXtObjectID		 self,
        unsigned int		 flags);

        LXxMETHOD(  LxResult,
ToggleArg) (
        LXtObjectID		  self,
        unsigned int		 *index,
        void			**ppvObj,
        unsigned int		 *typeID,
        const char		**typeName);

        LXxMETHOD(  LxResult,
ArgFlags) (
        LXtObjectID		  self,
        unsigned int		  index,
        unsigned int		 *flags);

        LXxMETHOD(  LxResult,
ArgClear) (
        LXtObjectID		  self,
        unsigned int		  index );

        LXxMETHOD(  LxResult,
ArgResetAll) (
        LXtObjectID		  self );

        LXxMETHOD(  LxResult,
ArgSetDatatypes) (
        LXtObjectID		  self );

        LXxMETHOD(  LxResult,
ArgUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **desc);

        LXxMETHOD(  LxResult,
ArgExample) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **example);

        LXxMETHOD(  LxResult,
ArgType) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **type);

        LXxMETHOD(  LxResult,
ArgTypeUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgTypeDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **desc);

        LXxMETHOD(  LxResult,
ArgOptionUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		 optIndex,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgOptionDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		 optIndex,
        const char	       **desc);

        LXxMETHOD(  LxResult,
DialogInit) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
DialogArgChange) (
        LXtObjectID		  self,
        unsigned int		  arg);

        LXxMETHOD(  LxResult,
ArgEnable) (
        LXtObjectID		  self,
        unsigned int		  arg);

        LXxMETHOD(  LxResult,
ArgParseString) (
        LXtObjectID		  self,
        unsigned int		  argIndex,
        const char		 *argString);

        LXxMETHOD(  LxResult,
Copy) (
        LXtObjectID		  self,
        LXtObjectID		  sourceCommand );

        LXxMETHOD(  LxResult,
Query) (
        LXtObjectID		  self,
        unsigned int		  index,
        LXtObjectID		  vaQuery );

        LXxMETHOD(  LxResult,
NotifyAddClient) (
        LXtObjectID		  self,
        int			  argument,
        LXtObjectID		  object);

        LXxMETHOD(  LxResult,
NotifyRemoveClient) (
        LXtObjectID		  self,
        LXtObjectID		  object);

        LXxMETHOD(  LxResult,
DialogFormatting) (
        LXtObjectID		  self,
        const char		**formatting);
} ILxCommand2;

typedef struct vt_ILxCommand3 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Tag) (
        LXtObjectID		 self,
        LXtCommandTag		*tag);

        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		 self,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ButtonName) (
        LXtObjectID		 self,
        const char	       **buttonName);

        LXxMETHOD(  LxResult,
Desc) (
        LXtObjectID		 self,
        const char	       **desc);

        LXxMETHOD(  LxResult,
Tooltip) (
        LXtObjectID		 self,
        const char	       **tooltip);

        LXxMETHOD(  LxResult,
Help) (
        LXtObjectID		 self,
        const char	       **help);

        LXxMETHOD(  LxResult,
Example) (
        LXtObjectID		 self,
        const char	       **example);

        LXxMETHOD(  LxResult,
Icon) (
        LXtObjectID		 self,
        const char	       **iconNames);

        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		 self,
        unsigned int	        *flags);

        LXxMETHOD(  LxResult,
PostExecFlags) (
        LXtObjectID		 self,
        unsigned int	        *flags);

        LXxMETHOD(  LxResult,
PostExecBehaviorFlags) (
        LXtObjectID		 self,
        unsigned int	        *flags);

        LXxMETHOD(  LxResult,
PostExecHints) (
        LXtObjectID		 self,
        unsigned int		*hints);

        LXxMETHOD(  LxResult,
SandboxGUID) (
        LXtObjectID		  self,
        const LXtGUID		**guid);

        LXxMETHOD(  LxResult,
Message) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
Enable) (
        LXtObjectID		  self,
        LXtObjectID		  msg);

        LXxMETHOD(  LxResult,
ContainedEnable) (
        LXtObjectID		  self,
        LXtID4			 *types);

        LXxMETHOD( void,
Interact) (
        LXtObjectID		  self);

        LXxMETHOD( void,
PreExecute) (
        LXtObjectID		  self);

        LXxMETHOD(  void,
Execute) (
        LXtObjectID		 self,
        unsigned int		 flags);

        LXxMETHOD(  LxResult,
ToggleArg) (
        LXtObjectID		  self,
        unsigned int		 *index,
        void			**ppvObj,
        unsigned int		 *typeID,
        const char		**typeName);

        LXxMETHOD(  LxResult,
ArgFlags) (
        LXtObjectID		  self,
        unsigned int		  index,
        unsigned int		 *flags);

        LXxMETHOD(  LxResult,
ArgClear) (
        LXtObjectID		  self,
        unsigned int		  index );

        LXxMETHOD(  LxResult,
ArgResetAll) (
        LXtObjectID		  self );

        LXxMETHOD(  LxResult,
ArgSetDatatypes) (
        LXtObjectID		  self );

        LXxMETHOD(  LxResult,
ArgUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **desc);

        LXxMETHOD(  LxResult,
ArgExample) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **example);

        LXxMETHOD(  LxResult,
ArgType) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **type);

        LXxMETHOD(  LxResult,
ArgTypeUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgTypeDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **desc);

        LXxMETHOD(  LxResult,
ArgOptionUserName) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		 optIndex,
        const char	       **userName);

        LXxMETHOD(  LxResult,
ArgOptionDesc) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		 optIndex,
        const char	       **desc);

        LXxMETHOD(  LxResult,
DialogInit) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
DialogArgChange) (
        LXtObjectID		  self,
        unsigned int		  arg);

        LXxMETHOD(  LxResult,
ArgEnable) (
        LXtObjectID		  self,
        unsigned int		  arg);

        LXxMETHOD(  LxResult,
ArgParseString) (
        LXtObjectID		  self,
        unsigned int		  argIndex,
        const char		 *argString);

        LXxMETHOD(  LxResult,
Copy) (
        LXtObjectID		  self,
        LXtObjectID		  sourceCommand );

        LXxMETHOD(  LxResult,
Query) (
        LXtObjectID		  self,
        unsigned int		  index,
        LXtObjectID		  vaQuery );

        LXxMETHOD(  LxResult,
NotifyAddClient) (
        LXtObjectID		  self,
        int			  argument,
        LXtObjectID		  object);

        LXxMETHOD(  LxResult,
NotifyRemoveClient) (
        LXtObjectID		  self,
        LXtObjectID		  object);

        LXxMETHOD(  LxResult,
DialogFormatting) (
        LXtObjectID		  self,
        const char		**formatting);

        LXxMETHOD(  LxResult,
IconImage) (
        LXtObjectID		  self,
        int			  w,
        int			  h,
        void			**ppvObj);
} ILxCommand3;

/*
 * This returns the block's name.
 * 
 * This returns the flags it was created with.
 * 
 * This number of commands executed within the block can be read with this function.  This
 * is mainly used by CHist to discard empty blocks.
 * 
 * After commands in the block have been executed, the flags of the block itself may have
 * changed.  Normally, blocks are undoable, but firing non-undoable blocks can change that.
 * Note that these flags are the same as the execution flags used by the commands, not the
 * flags used to create a command block.
 */
typedef struct vt_ILxCommandBlock {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        const char	       **name);
        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		 self,
        unsigned int		*flags);
        LXxMETHOD(  LxResult,
SubExecs) (
        LXtObjectID		 self,
        unsigned int		*execs);
        LXxMETHOD(  LxResult,
PostExecFlags) (
        LXtObjectID		 self,
        unsigned int		*flags);
} ILxCommandBlock;

/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.
 * 
 * 
 * This returns the ILxCommand interface of the prototype command, thus allowing basic
 * non-editable data to be read out, such as the command's name, tag and attributes.
 * The object must be released when no longer needed.  Note that it is legal to pass
 * in a full command argument string with name, and only the part up to the first space
 * will be treated as a name (the arguments are ignored).
 * 
 * This returns the prototype of a command from an alreadly instanced one.
 * 
 * Should you want to, this returns a command's tag, which can be used to create an
 * instance of a command instead of using its name.
 * 
 * This spawns a new command object given its name or tag, which means it creates
 * a fully functional command object whose args can be set for firing and querying.
 * The object needs to be released with XObjectRelease() when no longer needed.
 * 
 * This spawns a new command object given another command object.  Note that the spawned
 * command will include any aliasing that was applied, even if the original command was
 * create with SpawnUnaliased().
 * 
 * This super-wrapper spawns a command from an argument string and sets all the arguments
 * found.  It will also return the index of the query argument, if one was set in the
 * argument string; the query argument will be -1 if no query argument is set.
 * 
 * Also, execution flags passed in will be modified based on the leading characters of the
 * command string (!, +, ?, etc).  Note that the execFlags should be iniitalized to some
 * useful execution flags, such as LXfCMD_EXEC_DEFAULT, as this will also be used to present
 * parsing errors.
 * 
 * Once the command has been spawned in this way, it is ready for execution or querying.
 * 
 * 
 * This is a high-level function that parses arguments and fires the command all in
 * one go.  If the tag is CTAG_NULL, it is assumed that the command name begins the
 * argument string.
 * If the tag is CTAG_NULL, then there are some special characters that can be used
 * to modify the execution state.  These flags are insereted at the very beginning of
 * the arugment string, before the command name.
 * 
 * A single exclamation point "!" can be used to turn off the SHOWERR and GETARGS
 * flags for this command only.  An opposite effect can be achieved by using a
 * single leading plus "+".  This adds SHOWERR and GETARGS to the command.
 * 
 * Note that the above only affect this specific command.  All sub-commands can be
 * affected be using double exclamation points "!!" or double pluses "++" where
 * appropriate.  These will add SHOWERR_FORCESUB_OFF and GETARGS_FORCESUB_OFF or
 * SHOWERR_FORCESUB and GETARGS_FORCESUB to the execFlags.
 * 
 * This function also handles special UI-level behaviors.  For example, if a
 * required argument is missing, the command dialog will open.  Similarly, if
 * a query operator is specified for an argument, it will be applied.  This
 * includes using a question mark by itself on an argument that can be
 * represented by a popup, thereby forcing it to open a menu at the current
 * mouse position, or in the case of a boolean argument, causing it toggle it
 * on or off.
 * 
 * 
 * Similar, but also allows a toggle arg to be flipped.  -1 can be used to invert
 * the current state.
 * 
 * This processes a command string (name and args) and returns LXe_TRUE if it is
 * a toggle arg command, and LXe_FALSE if not.  If true, this means the command
 * can be executed with ExecuteToggleArgString() to toggle argument.
 * 
 * Commands with queried boolean arguments can also be somewhat tedious to test,
 * toggle and execute, especially considering the multiple ways that a boolean
 * argument can be specified.  This function takes a command string, and if
 * the boolean argument contains any query operators (including a question mark
 * alone), this returns true.
 * 
 * This allows the boolean argument's value to be easily changed to an alternate
 * state.  As above, the boolean argument is expected to be marked with a query
 * operator, and the argument's value will be toggled based on the argument's
 * currently queried value before being executed..
 * 
 * This executes a command object, but also takes a special argument index.  If the
 * index is not -1, then special behaviors specific to that argument may be taken
 * (i.e., opening a popup), or the command may be executed normal or a command dialog
 * may appear as normal. This same behavior is taken automatically when executing
 * a command from a string using ExecuteArgString().
 * 
 * Finally, we support using an ILxAttributes interface to provide the arguments to
 * the command.  The Name(), Count(), Value(), GetString(), GetInt() and GetFloat()
 * arguments are used, but the Type() argument is not used.
 * It works like this: First the Count() and Name() methods are called to see which
 * argument this is.  Then one of Value(), GetInt(), GetFloat() or GetString() is
 * called depending on the datatype of the argument (note that the Type() method is
 * not usd).  If the method fails, the GetString() method is used as an encoded
 * string.  If that fails, then the execution fails.
 * 
 * 
 * This function can be used to parse the special prefix characters mentioned above
 * out the string, and combine them with other execution flags.  This is useful when
 * you are directly creating an ILxCommand object from a user-entered string.
 * The function takes the original execution and/or alert flags and the source string.
 * It returns new flags and a pointer to the first character after the flags characters
 * in the source string.  Either newFlags or afterFlags may be NULL if desired.
 * 
 * 
 * This inverse function takes the exec flags and converts them back into a prefix
 * string.
 * 
 * These functions makes it easy to flip the toggle of a Toggle Argument command,
 * and to tell if the state is on or off.  1 is on, 0 is off, and -1 inverts the
 * current state.
 * 
 * When getting the value, both a simple on/off state and the current value of the
 * arg can be provided, or either can be NULL.
 * 
 * Scripts can be more easily executed using this function.  Before looking up any
 * commands, this should be called to see if it starts with the script marker (the @
 * symbol).  Note that the definition string should include entire command like, not
 * just the @ and script name; if If it does, the next function will create the
 * implicit script command and and set the script name and arg string arguments
 * automatically.  Scripts cannot be queried, so the command returned is only useful
 * for execution.  The command can otherwise be treated a a normal command object
 * after it is created.
 * See if the command is an implicit script execution.
 * 
 * 
 * Spawn a command to launch the script.  This "definition" string should include any
 * arguments to pass to the script.
 * 
 * Execute an implicit script directly.
 * 
 * Some commands are fired many times over and over again as the user changes a
 * value.  An example of this is the the Move Tool; each time the users drags
 * the mouse, the Move Tool fires a new AddPosition (or whatever) command.  This
 * clutters up the command histroy quite a bit.  Instead, the Move Tool should
 * fire the AddPosition command effectively once with the final value, thus
 * resulting in a single entry in the command history.
 * This process has been dubbed "Refiring".  On mouse down, a tool calls
 * CmdRefireBegin(), and on mouse up calls CmdRefireEnd().  In between it
 * fires commands using CmdEntryFireArgs() or CmdEntryFireTag() to fire
 * a command.  When a command is refired, the previous execution is undone
 * just before the command is re-executed.
 * 
 * Each successive time CmdEntryFire...() is called within a refire block,
 * the previously fired command is undone.
 * 
 * 	IT IS REQUIRED THAT THE COMMAND BEING FIRED IS UNDOABLE!
 * 
 * Large annoying requesters will pop up if you try to use any non-undoable
 * commands.
 * 
 * Only a single command can be executed inside a refire block, although that
 * command may execute others.  Attempting to execute more than one will cause
 * those later commands to fail.  If you need to fire multiple commands, you
 * can wrap them in a command block via BlockBegin()/BlockEnd(), in which case
 * the name of the block is used to identify it.  RefireBegin() does not nest,
 * and cannot be called while any commands are executing.  It will return false
 * if a previous RefireBegin() hasn't been ended yet via RefireEnd() or if it
 * is called while any command is being executed.
 * 
 * Beginning refiring can take a tag, name or an ILxCommandID if you have one
 * handy.
 * 
 * 
 * 
 * 
 * These can be used to get the prototype of the command or the name of
 * the block being refired.
 * NOTE: this is returned without being add-refed! That needs to be fixed.
 * 
 * 
 * 
 * The being and end functions.  In begin, any of cmd, tag or args can be provided.
 * If all are NULL, it is assumed that the command name prefixes the arguments.\
 * Otherwise, the argument list is optional.
 * 
 * 
 * This fetches the current post-mode state (i.e., on or off).
 * 
 * This resets all undoable states since the PostModeBegin() call.  An example
 * usage is ToolRefluxRestart() in tools.qq.
 * 
 * This returns the current command execution depth.  -1 means no commands are
 * currently executing.  This information is useful in rare situations.  Note
 * that this count includes both commands and command blocks.
 * 
 * It is sometimes desirable to have multiple commands executed as a single
 * undoable event.  This can be done by creating command blocks.  Blocks can
 * be nested as needed.  Each block can be given a name that will be sent in
 * the block create event and undo data and be displayed in the command history.
 * Block names should be localized, and can take the form of "@table@message@"
 * 
 * - PRESERVE_SELECTION
 * The PRESERVE_SELECTION flag will keep a copy of the entire selection list.
 * This copy will be restored after the block is closed.  This allows the command
 * to change the selection in any way it wishes without damaging it later.
 * - UI
 * If present, the block can be triggered during refiring events without
 * disrupting them.  This should only be used with commands supporting
 * LXfCMD_UI or with side effect commands.
 * 
 * - UNDO_UI
 * If present, the block is expected to contain undoable UI blocks.
 * 
 * - UNDO_AFTER_EXEC
 * If applied to an UNDO (default) or UNDO_UI block, the undo actions are 
 * undone on completion.
 * 
 * - SANDBOXED
 * Should be set if the block is in a sandbox.
 * 
 * - POSTMODE
 * Command block is being used as part of a post command execution.
 * 
 * - STEPUNDO
 * Taz, any idea what this is for?
 * 
 * - TOP_OF_CYCLE_SAFE
 * This is a special behavior used only in rare circumstances.  Normally,
 * a command block is not allwoed to remain open at the top of the input
 * cycle.  This flag allows that condition to be ignored.  This is used by
 * tree panes to allow the user to click and drag down a column to change
 * a series of checkmarks without releasing the mouse, while having all of
 * the commands contained within a single command block.
 * 
 * Each block must be closed with this function.  Bad things will happen if you
 * miss one so don't forget.
 * 
 * 
 * The current block can be obtained with this function, if one is on the
 * execution stack.  This mainly allows the flags and name of the block to
 * be read.  Note that this is a "peek", and the object should not be released
 * by the caller.
 * NOTE: should be returned as the main return value.
 * 
 * 
 * 
 * This method adds an object to a sandbox.  The object is AddRef()'ed when added, and
 * released when the sandbox is destroyed.
 * 
 * A list of objects can be read with these functions.
 * 
 * An object can be looked up by the interfaces it supports.  The first object with the
 * GUID will be returned, or the method fails.  Since this method caches interface queries,
 * it is recommended instead of walking the object list directly.
 * 
 * More commonly, this method would be used to get the object associated with the command's
 * SandboxGUID() method.
 * 
 * Command sandboxes can be started through this method.  Flags are any combination of
 * LXfCMDSANDBOX_ flags, and cannot be changed once the sandbox is created.
 * 
 * This method returns LXe_CMD_SANDBOX_GLOBAL if there are no sandboxes on the stack, and
 * LXe_CMD_SANDBOXED if there is at least one.  Any other return code is a failure.
 * 
 * When the sandbox is no longer needed, it must be popped off the stack with this method.
 * 
 * This is similar to CmdEntryFireTag(), and takes a string representing the
 * arguments.
 * 
 * This function uses an ILxAttributesID to fill in the arguments.  See
 * ExecuteAttribObj() for more information about how this works.
 * 
 * This function composes and returns a string describing the arguments of the
 * command in a user-readable format.  This string is dynamically generated from
 * the command's own argument list, and includes the command name.
 * 
 * This function returns the argument list as a string which would result in
 * the same arguments for the command if parsed.  This is mainly used for
 * recording the command in an executable history.  If includeCmd is true, the
 * internal command name will prefix the argument portion.
 * 
 * This queries a command for its values, providing a new ILxValueArray that
 * must be released by the client.
 * 
 * This is similar, but takes an argument string instead of an index.  One argument
 * may be marked with a ?, and that one will be queried.  The index of that argument
 * can be obtained through the queryIndex argument, or NULL can be passed NULL if you
 * don't want it back.  Similarly, the ILxValueArrayID argument can be NULL if only the
 * queryIndex itself is desired but not the actual queried values.
 * If includesCmdName is true, the first part of the argument string is assumed to
 * be the command name and will be skipped.  The alertFlags (LXfCMD_ALERT_ defines)
 * are used to decide how to present errors to the user during parsing; passing 0 will
 * suppress any error dialogs.
 * 
 * If successful parsed, the command object provided will be populated with the arguments
 * present in the args string.
 * 
 * 
 * This creates a new ILxValueArray interface given an ExoType name.
 * 
 * Commands can be aliased.  This allows one command to replace another, and to create
 * shortcut commands that have arguments preset.  Aliases themselves cannot be aliased.
 * When creating or deleting aliases, any one of cmd, tag or name may be set.  The
 * argument string used during creation will be used to provide default values for the
 * command.  The arguments set in the cmd (if provided) are ignored.
 * 
 * Note that using aliased arguments is only completely supported for commands that
 * do not use dynamic datatypes.  The issue is that if the user changes the the
 * REQFORVARIABLE argument, the other arguments will need to be reset, thus overriding
 * the aliased defaults.  This shouldn't pose any issues in most situations.
 * 
 * 
 * There are currently three types of commands:  normal commands, containers and aliases.
 * This functions can be used to tell if the command is a container.
 * 
 * This succeeds if the command is aliased.  Note that a command can be both a container
 * and aliased.
 * 
 * The command list can be walked with these functions, returning the prototype.
 * Commands are sorted by internal name.  Note that commands will be loaded from
 * plug-ins if necessary as the list is walked.
 * 
 * 
 * The username can be obtained for both commands and blocks.
 * 
 * 
 * For commands, an argument string suitable for executing it can be read with
 * this function.
 * 
 * This returns LXe_TRUE if a command is executing and the interaction flags are
 * set.  This means that if this returns LXe_FALSE, the client should not open any
 * dialogs and instead should perform its default behavior.  The interaction flags
 * are often unset when running from a script or when in headless mode, during which
 * time modo's own dialogs (such as ILxMessage-based dialogs) will be automatically
 * suppressed, acting as though the user had hit cancel/abort/no.  By testing
 * IsGlobalInteractionOK(), clients can skip the message and perform a reasonable
 * default action instead of failing.
 * This method is only intended to be used by non-command clients.  Commands
 * themselves should check their exec flags (as passed to the Execute() methods)
 * via LXxCMD_IS_USER_INTERACTION_OK() instead.
 * 
 * 
 * This is identical to ArgsAsString, but is a safer function that takes a buffer
 * length to reduce the chance of a buffer overflow.
 * ArgAsString() was updated a long time ago to include a len argument, making it
 * identical to this function.  Before nexus 12, there was a bug in ArgAsString()
 * that kept it from working properly, but as of 12 both are identical.
 * 
 * Since the "len" argument was added to ArgAsString(), the two functions are now
 * completley identical, and are only both maintained to avoid breaking old plug-ins.
 * 
 * 
 * Commands can be aliased such that they replace an existing command.  This is useful
 * when you want an alias to be able to completely replace built-in functionality.
 * This method can be used to spawn an instance of the original, unaliased command,
 * thus allowing the alias to call the original command's methods.
 * 
 * It is sometimes useful to be able to lock out interaction on a global level.
 * A common case is Slave mode, where we don't want any dialogs opening as these
 * machines are usually unattended.  This state can only be set from within a
 * command, and is automatically cleared when the stack is emptied.  It cannot
 * be manually cleared if it was not set by the client.
 * 
 * These functions are identical to their non-'2' counterparts, but will indirectly
 * return a COM object representing the command object.  This allows you to read
 * post-execution flags and messages from the executed command, without having to
 * manually spawn the command, set the argumetns, and do everything else you have
 * to do to set up and execute a command manually.
 * It's important to note that this object may be NULL if the command could not be
 * spawned.  If the object returned is non-NULL, it must be released by the caller
 * when no longer needed.
 * 
 * 
 * This allocates an ILxUIHints object, has the provided command populate it, and returns it.
 * The obejct can be cast to an ILxUIHintsRead interface to read the values of the hints.
 * Since a new object is allocated, the returned hints object can also be modified by the
 * caller and returned by their own commands if so desired.
 * The argument index can be a specific arguments for hints for that argument, or LXiATTRUI_ANY
 * for command-level hints, as is common for the form filter priority.
 * 
 * 
 * Sometimes a large undoable operation occurs that causes a lot of events to come in,
 * and you want to do one undoable operation once everything else is done.  You could
 * use ScriptService::DoWhenUserIsIdle(), which is general useful for deferred and lazy
 * operations, but if you want to perform an undoable operation you'll have have to fire
 * a command, and that means the user will have to do an extra undo to go back, which
 * isn't ideal and makes the undos feel broken.
 * This method can only be called while an undoable command is being fired, and will
 * fail otherwise.  It registers a visitor that will be called after the root-level
 * undoable command or block is about to return, but the undo block is still open.
 * Calling this method twice with the same object pointer does nothing; the object
 * is only registered once.
 * 
 * The cancel method can be used to remove the registration, but the object passed
 * in must be exactly the same as the one passed for registration, as this does a
 * pointer compare.  When doing this from Python, this means that you must pass the
 * exact same visitor COM object (not Python object).  This is also necessary when
 * removing listeners and canceling timers, as discussed here: http://modo.sdk.thefoundry.co.uk/wiki/FAQ#Q:_How_do_I_remove_a_listener_object_in_Python.3F
 * 
 * Note that unlike user idle, these functions are not thread-safe.  This is because
 * they are usually called in response to listeners from an actively-firing command,
 * both of which happen from the main thread.
 * 
 * If the command is aborted or fails, these actions are not executed, since the
 * effects of the operation were all undo and it's as though the operation never
 * happened.  This also does nothing if the root command's eventual state wasn't
 * either model or model-undoable (UI undos are not supported).
 * 
 * 
 * 
 * In addition to monitoring the execution stack with functions like CurrentExecDepth(),
 * this function can be used to test if the currently executing command on the stack is
 * at the root or if it is in a sub-command or block.  If ignoreBlocks is true, this
 * returns LXe_TRUE if its only parents are blocks.  This fails if the stack is empty.
 * 
 */
typedef struct vt_ILxCommandService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
MasterStatus) (
        LXtObjectID		 self,
        unsigned int		*status);
        LXxMETHOD(  LxResult,
GetNameSep) (
        LXtObjectID		 self,
        unsigned int		*sep);

        LXxMETHOD(  LxResult,
SetNameSep) (
        LXtObjectID		 self,
        unsigned int		 sep);
        LXxMETHOD(  LxResult,
Proto) (
        LXtObjectID		  self,
        LXtCommandTag		  tag,
        const char		 *name,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ProtoFromCommand) (
        LXtObjectID		  self,
        LXtObjectID		  cmd,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		 self,
        const char		*name,
        LXtCommandTag		*tag);
        LXxMETHOD(  LxResult,
Spawn) (
        LXtObjectID		  self,
        LXtCommandTag		  tag,
        const char		 *name,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
SpawnFromCommand) (
        LXtObjectID		  self,
        LXtObjectID		  cmd,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
SpawnFromString) (
        LXtObjectID		  self,
        const char		 *args,
        unsigned int		 *execFlags,
        int			 *queryArgIndex,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ExecuteArgString) (
        LXtObjectID		 self,
        unsigned int		 execFlags,
        LXtCommandTag		 tag,
        const char		*args);
        LXxMETHOD(  LxResult,
ExecuteToggleArgString) (
        LXtObjectID		 self,
        unsigned int		 execFlags,
        LXtCommandTag		 tag,
        const char		*args,
        int			 newState);
        LXxMETHOD(  LxResult,
IsToggleArgString) (
        LXtObjectID		 self,
        const char		*string);
        LXxMETHOD(  LxResult,
IsBooleanArgString) (
        LXtObjectID		 self,
        const char		*string);
        LXxMETHOD(  LxResult,
ExecuteBooleanArgString) (
        LXtObjectID		 self,
        unsigned int		 execFlags,
        LXtCommandTag		 tag,
        const char		*args);
        LXxMETHOD(  LxResult,
ExecuteSpecial) (
        LXtObjectID		 self,
        unsigned int		 execFlags,
        LXtObjectID		 cmd,
        int			 specialArgIndex);
        LXxMETHOD(  LxResult,
ExecuteAttribObject) (
        LXtObjectID		 self,
        unsigned int		 execFlags,
        LXtCommandTag		 tag,
        const char		*cmdName,
        LXtObjectID		 attribArgs);
        LXxMETHOD(  LxResult,
ProcessStringFlags) (
        LXtObjectID		  self,
        unsigned int		  flags,
        const char		 *string,
        unsigned int		 *newFlags,
        const char		**afterFlags);
        LXxMETHOD(  LxResult,
ExecFlagsAsPrefixString) (
        LXtObjectID		  self,
        unsigned int		  flags,
        char			 *buf,
        unsigned int		  len);
        LXxMETHOD(  LxResult,
SetToggleArgState) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        int			 state);
        LXxMETHOD(  LxResult,
GetToggleArgState) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        int			*state,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
IsImplicitScript) (
        LXtObjectID		 self,
        const char		*definition );
        LXxMETHOD(  LxResult,
SpawnImplicitScript) (
        LXtObjectID		  self,
        const char		 *definition,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ExecuteImplicitScript) (
        LXtObjectID		 self,
        const char		*definition,
        unsigned int		 execFlags);
        LXxMETHOD(  LxResult,
RefireBegin) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
RefireEnd) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
RefireState) (
        LXtObjectID		 self,
        unsigned int		*state);
        LXxMETHOD(  LxResult,
RefireCmd) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
RefireBlock) (
        LXtObjectID		 self,
        const char	       **name);
        LXxMETHOD(  LxResult,
PostModeBegin) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        LXtCommandTag		 tag,
        const char		*name,
        const char		*args,
        LXtObjectID		 postEndObj);
        LXxMETHOD(  LxResult,
PostModeEnd ) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
PostModeState ) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
PostModeRestart ) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
CurrentExecDepth ) (
        LXtObjectID		 self,
        int			*depth);
        LXxMETHOD(  LxResult,
BlockBegin) (
        LXtObjectID		 self,
        const char		*name,
        unsigned int		 flags);
        LXxMETHOD(  LxResult,
BlockEnd) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
BlockCurrent) (
        LXtObjectID		  self,
        void			**block);
        LXxMETHOD(  LxResult,
SandboxFlags) (
        LXtObjectID		 self,
        unsigned int		*flags);
        LXxMETHOD(  LxResult,
SandboxAddObject) (
        LXtObjectID		 self,
        LXtObjectID		 object);
        LXxMETHOD(  LxResult,
SandboxObjectCount) (
        LXtObjectID		  self,
        unsigned int		 *count);

        LXxMETHOD(  LxResult,
SandboxObjectByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
SandboxObjectLookup) (
        LXtObjectID		  self,
        const LXtGUID		 *guid,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
SandboxObjectByCommand) (
        LXtObjectID		  self,
        LXtObjectID		  cmd,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
SandboxBegin) (
        LXtObjectID		 self,
        unsigned int		 flags);
        LXxMETHOD(  LxResult,
SandboxState) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
SandboxEnd) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
ParseArgString) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        int			 alertFlags,
        const char		*args);
        LXxMETHOD(  LxResult,
ParseAttribObject) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        unsigned int		 alertFlags,
        LXtObjectID		 attribArgs);
        LXxMETHOD(  LxResult,
Usage) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        const char	       **buffer);
        LXxMETHOD(  LxResult,
ArgsAsString) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        char			*buf,
        unsigned int		 len,
        unsigned int		 includeCmd);
        LXxMETHOD(  LxResult,
Query) (
        LXtObjectID		  self,
        LXtObjectID		  cmd,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
QueryArgString) (
        LXtObjectID		  self,
        LXtObjectID		  cmd,
        unsigned int		  alertFlags,
        const char		 *args,
        void			**ppvObj,
        unsigned int		 *queryIndex,
        unsigned int		  includesCmdName);
        LXxMETHOD(  LxResult,
CreateQueryObject) (
        LXtObjectID		  self,
        const char		 *typeName,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
AliasCreate) (
        LXtObjectID		 self,
        const char		*name,
        LXtObjectID		 targetCmd,
        LXtCommandTag		 targetTag,
        const char		*targetName,
        const char		*args);

        LXxMETHOD(  LxResult,
AliasDelete) (
        LXtObjectID		 self,
        LXtObjectID		 alias,
        LXtCommandTag		 tag,
        const char		*name);
        LXxMETHOD(  LxResult,
IsContainer) (
        LXtObjectID		 self,
        LXtObjectID		 cmd);
        LXxMETHOD(  LxResult,
IsAliased) (
        LXtObjectID		 self,
        LXtObjectID		 cmd);
        LXxMETHOD(  LxResult,
CommandCount) (
        LXtObjectID		  self,
        unsigned int		 *count);

        LXxMETHOD(  LxResult,
CommandByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ExecEntryType ) (
        LXtObjectID		 self,
        int			 index,
        int			*type);
        LXxMETHOD(  LxResult,
ExecEntryUserName ) (
        LXtObjectID		  self,
        int			  index,
        const char		**userName);
        LXxMETHOD(  LxResult,
ExecEntryName ) (
        LXtObjectID		  self,
        int			  index,
        const char		**name);
        LXxMETHOD(  LxResult,
ExecEntryAsArgString ) (
        LXtObjectID		 self,
        int			 index,
        char			*buf,
        int			 len);
        LXxMETHOD(  LxResult,
IsGlobalInteractionOK) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
ArgsAsStringLen) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        char			*buf,
        unsigned int		 len,
        unsigned int		 includeCmd);
        LXxMETHOD(  LxResult,
SpawnUnaliased) (
        LXtObjectID		  self,
        LXtCommandTag		  tag,
        const char		 *name,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
SetIsGlobalInteractionOK) (
        LXtObjectID		 self,
        int			 isOK);
        LXxMETHOD(  LxResult,
ExecuteArgString2) (
        LXtObjectID		 self,
        unsigned int		 execFlags,
        LXtCommandTag		 tag,
        const char		*args,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
ExecuteToggleArgString2) (
        LXtObjectID		  self,
        unsigned int		  execFlags,
        LXtCommandTag		  tag,
        const char		 *args,
        int			  newState,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
ExecuteBooleanArgString2) (
        LXtObjectID		  self,
        unsigned int		  execFlags,
        LXtCommandTag		  tag,
        const char		 *args,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
ExecuteAttribObject2) (
        LXtObjectID		 self,
        unsigned int		 execFlags,
        LXtCommandTag		 tag,
        const char		*cmdName,
        LXtObjectID		 attribArgs,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
ExecuteImplicitScript2) (
        LXtObjectID		 self,
        const char		*definition,
        unsigned int		 execFlags,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
AllocateUIHintsFromCommand) (
        LXtObjectID		  self,
        LXtObjectID		  cmd,
        int			 argIndex,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
DoAtEndOfRootLevelUndoableCommand) (
        LXtObjectID		  self,
        LXtObjectID		  visitor);

        LXxMETHOD(  LxResult,
CancelDoAtEndOfRootLevelUndoableCommand) (
        LXtObjectID		  self,
        LXtObjectID		  visitor);
        LXxMETHOD(  LxResult,
ArgsAsStringWithOptions) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        char			*buf,
        unsigned int		 len,
        int			 options);
        LXxMETHOD(  LxResult,
CurrentExecIsRoot) (
        LXtObjectID		 self,
        int			 ignoreBlocks);
} ILxCommandService;

typedef struct vt_ILxCommandPostEnd {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
End) (
        LXtObjectID		 self);
} ILxCommandPostEnd;

/*
 * This is called once the system has entered master enable, meaning that everything
 * has been started and commands can be executed when safe.
 * This indicates that the undo lockout state has changed.  When locked out, no
 * MODEL or MODEL|UNDO commands can be executed, and an error will be reported
 * if attempted.
 * 
 * This is called when a new command has been added to the system.
 * 
 * These are called when an alias is added or removed.  If isOverride is set,
 * the alias replaces an existing alias.  Note that isOverride is not set if
 * it a command with that name already exists (unless it is already aliased);
 * in that case, the command is replaced with the alias.
 * 
 * Similarly, the isOverride flag is set if the alias is being removed because
 * a new alias is replacing it.
 * 
 * 
 * 
 * 
 * This indicates that a command block was opened.  The event data is an ILxCommandBlockID
 * representing the block.
 * 
 * This is called when a command block is closed.  If wasDiscarded is true, the block
 * didn't contain any commands and is a no-op,, and does not appear in the history.
 * 
 * This is sent if the last closed block ended post mode.
 * 
 * These let the client know when refiring has started or stopped.  RefireNext()
 * indicates that the next command executed matches the refiring criteria and will
 * trigger refiring, undoing the previously-executed command.
 * 
 * 
 * 
 * These indicate when the post mode state has changed.
 * 
 * 
 * 
 * 
 * These indicate that the user performed an undo or redo.
 * 
 */
typedef struct vt_ILxCmdSysListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
SystemReady) (
        LXtObjectID		 self);
        LXxMETHOD( void,
UndoLockout) (
        LXtObjectID		 self,
        int			 isLockedOut);
        LXxMETHOD( void,
CommandAdded) (
        LXtObjectID		 self,
        const char		*name);
        LXxMETHOD( void,
AliasAdded) (
        LXtObjectID		 self,
        const char		*name,
        int			 isOverride);
        LXxMETHOD( void,
AliasRemoved) (
        LXtObjectID		 self,
        const char		*name,
        int			 isOverride);
        LXxMETHOD( void,
ExecutePre) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        int			 type,
        int			 isSandboxed,
        int			 isPostCmd);
        LXxMETHOD( void,
ExecuteResult) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        int			 type,
        int			 isSandboxed,
        int			 isPostCmd,
        int			 wasSuccessful);
        LXxMETHOD( void,
ExecutePost) (
        LXtObjectID		 self,
        LXtObjectID		 cmd,
        int			 isSandboxed,
        int			 isPostCmd);
        LXxMETHOD( void,
BlockBegin) (
        LXtObjectID		 self,
        LXtObjectID		 block,
        int			 isSandboxed);
        LXxMETHOD( void,
BlockEnd) (
        LXtObjectID		 self,
        LXtObjectID		 block,
        int			 isSandboxed,
        int			 wasDiscarded);
        LXxMETHOD( void,
BlockEndedPostMode) (
        LXtObjectID		 self,
        const char		*name,
        int			 isSandboxed);
        LXxMETHOD( void,
RefireBegin) (
        LXtObjectID		 self);
        LXxMETHOD( void,
RefireEnd) (
        LXtObjectID		 self);
        LXxMETHOD( void,
RefiringNext) (
        LXtObjectID		 self);
        LXxMETHOD( void,
PostModeBegin) (
        LXtObjectID		 self);
        LXxMETHOD( void,
PostModeEnd) (
        LXtObjectID		 self);
        LXxMETHOD( void,
PostModeRestart) (
        LXtObjectID		 self);
        LXxMETHOD( void,
PostModeUndoNext) (
        LXtObjectID		 self);
        LXxMETHOD( void,
UserUndo) (
        LXtObjectID		 self);
        LXxMETHOD( void,
UserRedo) (
        LXtObjectID		 self);
} ILxCmdSysListener;

/*
 * The command object is mainly defined by the ILxCommand interface.
 */

        #define LXu_COMMAND		"1db2d294-3b52-4442-a634-f3d4c6ce8dc4"
        #define LXa_COMMAND		"command"
        // [export] ILxCommand cmd
        // [local]  ILxCommand
        // [python] ILxCommand:Message		obj Message
        // [python] ILxCommand:ToggleArg	obj Value
        // [python] ILxCommand:IconImage	obj Image
        // [python] ILxCommand:ExecuteArg	global
        // [python] ILxCommand:ExecuteArgString	global

        #define LXe_CMD_ALREADY_EXISTS			LXxFAILCODE( LXeSYS_CMDS,   1)
        #define LXe_CMD_MISSING_ARGS			LXxFAILCODE( LXeSYS_CMDS,   2)
        #define LXe_CMD_NOT_AVAILABLE			LXxFAILCODE( LXeSYS_CMDS,   3)
        #define LXe_CMD_DISABLED			LXxFAILCODE( LXeSYS_CMDS,   4)
        #define LXe_CMD_UNKNOWN_COMMAND			LXxFAILCODE( LXeSYS_CMDS,   5)
        #define LXe_CMD_INVALID_ON_PROTO		LXxFAILCODE( LXeSYS_CMDS,   6)
        #define LXe_CMD_DIFFERENT_TYPES			LXxFAILCODE( LXeSYS_CMDS,   7)
        #define LXe_CMD_UNBALANCED_BRACES		LXxFAILCODE( LXeSYS_CMDS,   8)
        #define LXe_CMD_BAD_DEFINITION			LXxFAILCODE( LXeSYS_CMDS,   9)
        #define LXe_CMD_UNKNOWN_ARGUMENT		LXxFAILCODE( LXeSYS_CMDS,  10)
        #define LXe_CMD_TOO_MANY_ARGUMENTS		LXxFAILCODE( LXeSYS_CMDS,  11)
        #define LXe_CMD_ARGUMENT_ALREADY_SET		LXxFAILCODE( LXeSYS_CMDS,  12)
        #define LXe_CMD_ARGUMENT_NOT_QUERYABLE		LXxFAILCODE( LXeSYS_CMDS,  13)
        #define LXe_CMD_NO_QUERY_MARKED			LXxFAILCODE( LXeSYS_CMDS,  14)
        #define LXe_CMD_TOO_MANY_QUERIES_MARKED		LXxFAILCODE( LXeSYS_CMDS,  15)
        #define LXe_CMD_ILLEGAL_REFIRE_BEGIN		LXxFAILCODE( LXeSYS_CMDS,  16)
        #define LXe_CMD_ILLEGAL_REFIRE_END		LXxFAILCODE( LXeSYS_CMDS,  17)
        #define LXe_CMD_ALREADY_REFIRING		LXxFAILCODE( LXeSYS_CMDS,  18)
        #define LXe_CMD_NOT_ALIASED			LXxFAILCODE( LXeSYS_CMDS,  19)
        #define LXe_CMD_ERROR_SETTING_DATATYPE		LXxFAILCODE( LXeSYS_CMDS,  20)
        #define LXe_CMD_ERROR_ARG_MISSING_VALUE		LXxFAILCODE( LXeSYS_CMDS,  21)
        #define LXe_CMD_SANDBOX_NOT_COMPATIBLE		LXxFAILCODE( LXeSYS_CMDS,  22)
        #define LXe_CMD_SANDBOX_ONLY			LXxFAILCODE( LXeSYS_CMDS,  23)
        #define LXe_CMD_EXPECTED_OPENING_BRACE		LXxFAILCODE( LXeSYS_CMDS,  24)
        #define LXe_CMD_VARIABLE_DATATYPES_SET		LXxFAILCODE( LXeSYS_CMDS,  25)
        #define LXe_CMD_VARIABLE_DATATYPES_PENDING	LXxFAILCODE( LXeSYS_CMDS,  26)
        #define LXe_CMD_REQUIRES_USER_INTERACTION	LXxFAILCODE( LXeSYS_CMDS,  27)
        #define LXe_CMD_HAS_NO_ARGUMENTS		LXxFAILCODE( LXeSYS_CMDS,  28)
        #define LXe_CMD_QUERY_MISMATCHED_DATATYPES	LXxFAILCODE( LXeSYS_CMDS,  29)
        #define LXe_CMD_ALL_ARGUMENTS_HIDDEN		LXxFAILCODE( LXeSYS_CMDS,  30)
        #define LXe_CMD_BAD_DIALOG_FORMAT		LXxFAILCODE( LXeSYS_CMDS,  32)
        #define LXe_CMD_UNDOS_LOCKED_OUT		LXxFAILCODE( LXeSYS_CMDS,  33)
        #define LXe_CMD_DATATYPE_UNAVAILABLE		LXxFAILCODE( LXeSYS_CMDS,  34)
        #define LXe_CMD_ILLEGAL_DURING_INITIALIZATION	LXxFAILCODE( LXeSYS_CMDS,  35)
        #define LXe_CMD_NOT_EXECUTABLE			LXxFAILCODE( LXeSYS_CMDS,  36)

        #define LXe_CMD_SANDBOX_GLOBAL			LXxGOODCODE( LXeSYS_CMDS,   1)	// Good, not Fail
        #define LXe_CMD_SANDBOXED			LXxGOODCODE( LXeSYS_CMDS,   2)	// Good, not Fail

        #define LXe_CMD_ACTION_COMPLETED		LXxGOODCODE( LXeSYS_CMDS,   3)	// Good, not Fail

/*
 * The current command flags are available through this function.  A
 * command may return different flags based on its required arguments.
 * The following flags can be set only during setup:
 * -   SELECT
 * If present this flag marks the command as a selection command.
 * 
 * -	QUIET
 * These are a special type of command that allows lower-level operations to
 * be wrapped.  They do not have an undo context, thus allowing them to issue
 * undos themselves.  The primary use of QUIET commands is specific UI behaviors
 * that in turn call lower level commands to perform the actual operation.
 * Since they do not show up in the history and do not have an undo context, a
 * command block is often used to encapsulate a QUIET commands' multiple
 * sub-command firings.  Otherwies, each sub-command will show up as a separate
 * entry in the history.
 * 
 * If set, the command will not be recorded in the history or undo system when
 * activated.  This can be useful either for commands that make no sense in
 * scripts, or for commands that are mearly front-ends for real commands.  If
 * a quiet command fires a real command, the real command will be recorded.
 * QUIET commands do not directly affect the undo stack, but may fire commands
 * that do.  Note that each command fired by a QUIET command will show up as
 * a separate events, so more complex uses should include a command block to
 * wrap multiple undoable commands.  The QUIET flag overrides all others.
 * 
 * Note that a QUIET command does not get an undo context, and in itself is
 * not undoable, although the commands it fires can be undoable.  If multiple
 * commands need to be fired, a command block can be used, creating a single
 * undoable event.  Note that creating a command block within a QUIET command
 * is not enough to begin executing undoable code.
 * 
 * - POSTCMD
 * This command supports the post command mechanism.
 * 
 * - MUSTSETARG
 * If set, at least one argument of a command that contains all optional
 * arguments must be set for the command to execute.  If no arugments have
 * a value, a dialog is opened as though a required argument were missing.
 * If any value is set, the command is executed.
 * 
 * - EXTRA1
 * If set, app.undo does an extra undo after this command is undone. This flag
 * is reset when this command is not fired in post command mode.
 * 
 * - EXTRA2
 * If set, app.undo does an extra undo when next command block includes this
 * flag.
 * 
 * 
 * These flags may be set both during setup and through the flags callback.
 * 
 * - REPEAT
 * The command supports key repeat and will be fired continuously while the
 * shortcut key is held down.
 * 
 * - UI
 * The command affects the user interface.  This affects how the command is
 * shown in the Command History viewport.  UI commands should not affect the
 * model and are not undoable.  UI commands can be executed from sandboxes if
 * the UI flag is set for the sandbox.
 * 
 * - MODEL
 * The command affects the internal state of the program, such as modifying
 * geometry, changing motions, or performing some other model-level change.
 * Model commands are not undable by default, and cause any pending undos or
 * redos to be purged.  Model commands can NOT be used in a sandbox.
 * 
 * - NO_EXEC
 * The command is not executable, and its Interact(), PreExecute(), Execute(),
 * and other related methods will never be called.  Such commands are often
 * used for special behaviors like form command lists (FCLs), command filters
 * in forms, and so on.  The string defined by the command's NoExecReason atom
 * in its cmdhelp will be used to tell the user whey it is never executed.
 * 
 * - UNDO
 * This defines an undoable MODEL command, which can be undone and redone.
 * The command is responsible for correctly registering its undos with the
 * undo system, or calling other functions that do this themselves.  Undoable
 * commands can NOT be used in a sandbox.
 * 
 * - UNDO_UI
 * This defines an undoable UI command.  These are similar to undoable MODEL
 * commands, but undo UI constructs.  They are also fairly transient; when
 * a MODEL or undoable MODEL command is executed, any undoable UI command
 * undos or redos are flushed.  They are mostly intended to allow the user
 * to correct immediate or very recent mistakes made to UI constructs themselves,
 * rather than allowing them to step all the way back to the beginning of UI
 * changes as can be done with undoable MODEL commands.  Note that UNDO_UI
 * commands can only be executed as a root command, or a child of another
 * UNDO_UI command or UNDO_UI command block and retain their undos; executing
 * as a child of any other command or block type will cause the undos to be
 * lost.
 * 
 * - UNDOSPECIAL
 * This is used by the commands that actually modify the undo state directly
 * through the undo system, such as app.undo, app.redo and app.undoClear.
 * It should rarely ever be used.  UNDOSPECIAL commands are very much like
 * QUIET commands, and cannot be called from sub-commands or inside scripts,
 * and are not recorded by the command history that they are likely changing.
 * 
 * - UNDO_AFTER_EXEC
 * This flag is used in conjunction with UNDO or UNDO_UI.  The command can
 * execute undoable actions as normal, but after the command finishes executing
 * the undo blocks within are discarded, effectively undoing the command, even
 * if it executes successfully.  This is useful when performing temporary
 * operations where you need to modify the scene but don't want those changes
 * to be permanent.  The command will appear in the history as a side effect
 * command.
 * 
 * - Side Effect
 * This isn't a flag, but rather an absence of the UI, MODEL, UNDO or UNDOSPECIAL
 * flags.  If none of these are set, this is a Side Effect command.  They are
 * basically the same as UI commands, but don't shuffle through the command history
 * during undos. Side Effect commands can be executed from sandboxes if the UI flag
 * is set for the sandbox.
 * 
 * - SANDBOXED
 * Sandboxed commands are not undoable, and are not recorded in the command history.
 * They can only be executed in a sandbox containing an object with the interface
 * GUID returned by the command's Sandbox() method.  The Sandbox() method is not used
 * elsewhere.  Sandboxed commands are special commands used for scripting in specific
 * contexts.
 * 
 * - SELECTIONLESS
 * Marks a command that does not rely on the selection for the purposes of region
 * assignments, and may derrive the selection itself or simply not use any kind of
 * selection.  If this command is executed as part of a region assignment, it will
 * not cause the Pick function to be triggered first.
 * 
 * - STICKYLESS
 * Normally, executing a command with a boolean argument marked for query will that is
 * mapped to a key in the Input Editor will automatically act as a sticky if the key
 * is held down for a brief period of time instead of being tapped.  This can be
 * undesirable for certain commands, especially those like restoring layouts in palettes
 * that for some reason seems to delay the key up event.  Making those commands
 * sticky-less will keep them for being considered for sticky key behaivor -- tapping
 * and holding the key will only execute the command on down, not again on up.
 * 
 * - INTERNAL
 * If set, the command is hidden from the command list in the Command History.  It will
 * still show up in the undo list when executed.
 * 
 * - MOUSEDOWNOK
 * The command can be executed while a mouse button is down.  This should only be used
 * by UI commands, as performing undos or other actions could create very undesirable
 * performance issues.
 * 
 * - DEFER_INTERACTIVITY
 * Commands that use arguments that can be represented as numeric edit fields or sliders
 * can result in the command being called many times in quick succession.  If the
 * command requires a lot of processing (such as a script), it can significantly hamper
 * interactivity.  Although all efforts should be made to improve the performance of the
 * command, this is sometimes unavoidable.  DEFER_INTERACTIVITY tells the UI (such as
 * attrs/forms) to not call the command until the user has stopped interacting with its
 * controls (say, they released the mouse button).  This can dramatically improve the
 * apparent responsiveness of the application, although at the expense of real-time
 * updates.
 * 
 */

        #define LXfCMD_SELECT			 0x00000080
        #define LXfCMD_QUIET			 0x00000400
        #define LXfCMD_POSTCMD			 0x00000800
        #define LXfCMD_MUSTSETARG		 0x00001000
        #define LXfCMD_EXTRA1			 0x00002000
        #define LXfCMD_EXTRA2			 0x00004000
        #define LXfCMD_SELECTIONLESS		 0x00008000
        #define LXfCMD_STICKYLESS		 0x00040000
        #define LXfCMD_INTERNAL			 0x00020000
        #define LXfCMD_MOUSEDOWNOK		 0x00080000

        #define LXfCMD_INIT_ONLY		 0x000FFFF0	// Init only flags

        #define LXfCMD_REPEAT			 0x00100000
        #define LXfCMD_DEFER_INTERACTIVITY	 0x00200000

        #define LXfCMD_UI			 0x01000000
        #define LXfCMD_MODEL			 0x02000000
        #define LXfCMD_UNDO			(LXfCMD_UNDO_INTERNAL | LXfCMD_MODEL)
        #define LXfCMD_UNDO_UI			(LXfCMD_UNDO_INTERNAL | LXfCMD_UI)
        #define LXfCMD_UNDOSPECIAL		 0x08000000
        #define LXfCMD_SANDBOXED		 0x10000000
        #define LXfCMD_UNDO_AFTER_EXEC		 0x20000000
        #define LXfCMD_NO_EXEC			 0x40000000

        #define LXfCMD_TYPES			 0xFF000000	// Type flags

        #define LXxCMD_IS_SIDEEFFECT(flags)	((flags & LXfCMD_TYPES) == 0)

        #define LXfCMD_UNDO_INTERNAL		 0x04000000	// Used for testing for undoable commands only; do NOT set command flags with this.  Use LXfCMD_UNDO/LXfCMD_UNDO_UI to make an undoable command

/*
 * Commands can also provide hints on how the command system should act after
 * the command has executed.  The most common use is to suppress the command's
 * own error dialogs if any sub-commands have already opened one of that type.
 * This only affects dialogs that would be implicitly opened by the message
 * object set by the command during its execution.  Note that the
 * "command disabled" dialog is considered an error code.
 */

        #define LXfCMDHINT_SUPPRESS_INFOS	0x00000001
        #define LXfCMDHINT_SUPPRESS_WARNINGS	0x00000002
        #define LXfCMDHINT_SUPPRESS_ERRORS	0x00000004

        #define LXmCMDHINT_SUPPRESS_DIALOGS	(LXfCMDHINT_SUPPRESS_INFOS | LXfCMDHINT_SUPPRESS_WARNINGS | LXfCMDHINT_SUPPRESS_ERRORS)

/*
 * The execute function is used to fire a command using its current arguments.
 * A client calls this to actually fire the command, while the command itself
 * looks at its arguments and performs whatever operation it is going to do.
 * Note that unlike most methods, the execute function does not return an
 * LxResult.  Instead, errors should be set and read with the ILxMessage
 * interface of the command object.
 * 
 * The execution flags can be any combination of the following, including 0.
 * 
 * The ALERT flags are used to let the command system know how the user should
 * be notified about errors, if at all.
 * 
 * SHOWERR causes errors during execution to be displayed in a modal dialog.
 * 
 * SHOWERR_FORCESUB will force sub-commands to use the SHOWERR flag, even if
 * they do not specify it themselves.  This implies the SHOERR flag on this
 * command as well as its descendants.
 * 
 * SHOWERR_FORCESUB_OFF will force sub-commands to not use the SHOWERR flag,
 * even if SHOWERR is specified.  This disables SHOWERR on the parent as well.
 * 
 * SYNTAXERR causes syntax errors during argument parsing to be displayed in
 * a dialog; if unset, they are silently ignored.
 * 
 */

        #define LXfCMD_ALERT_NONE			 0x0000

        #define LXfCMD_ALERT_SHOWERR			 0x0001
        #define LXfCMD_ALERT_SHOWERR_FORCESUB		 0x0002
        #define LXfCMD_ALERT_SHOWERR_FORCESUB_OFF	 0x0004

        #define LXfCMD_ALERT_SYNTAXERR			 0x0008

        #define LXfCMD_ALERT_MASK			 0x00FF

/*
 * The EXEC flags are used purely during execution.
 * When executing a command from another command's Execute() method, the sub-command
 * should be passed the same flags that were passed from the parent command.  This
 * ensures that dialog suppression and similar features are properly respected by
 * child commands.
 * So that's what you should do.  However, this can be inconvenient if the sub-command
 * is executed from a helper function.  Rather than forcing you to pass the execution
 * flags through your helpers, you can use this method to obtain the flags from the
 * currently executing command.  If no commands are being executed, this returns the
 * default execution flags, so youc an use this at any time.
 * 
 * As you can see, this is defined as -1.  You can use -1 directly if you don't want to
 * type LXiCMD_EXEC_WITH_PARENTS_FLAGS all the time.  This is gauranteed to not change
 * in the future.
 * 
 */

        #define LXiCMD_EXEC_WITH_PARENTS_FLAGS		 (-1)

        #define LXxCMD_EXEC_WITH_PARENTS_FLAGS( flags )	 ((flags) == LXiCMD_EXEC_WITH_PARENTS_FLAGS)

/*
 * Here is an explination of the specific flags, which can be tested from your Execute()
 * method or passed when executing sub-commands.  In general, though, you hsould use
 * LXmCMD_EXEC_WITH_PARENTS_FLAGS
 * GETARGS will force the command system to open a dialog and ask for any
 * missing required arguments; missing optional arguments will not trigger
 * this behavior.
 * GETARGS_FORCESUB will force sub-commands to use the GETARGS flag, even if
 * they do not specify it themselves.  This implies the GETARGS flag on this
 * command as well as its descendants.
 * 
 * GETARGS_FORCESUB_OFF will force sub-commands to not use the GETARGS flag,
 * even if GETARGS is specified.  This disables GETARGS on the parent as well.
 * 
 * ALWAYSGETARGS will cause the command dialog to open even if all required
 * arguments are set.
 * 
 * TOGGLED is used to indicate that the command is being executed as the result
 * of a sticky key being released.  This flag is not set when the command is
 * fired on key.  Sticky keys are defined as the user holding down a key mapped
 * to a queried boolean or ToggleArg command (which in turn fires the command),
 * clicking/dragging with the mouse, and then releasing the key (which fires the
 * command again with the TOGGLED flag set).  Commands can read this flag in
 * there Execute() method to perform special behaviors when their sticky key is
 * released.
 * 
 * NO_ABORT makes it so that progress monitors will not have abort buttons.  This
 * is useful for specialized tasks where you need to execute a series of commands
 * and never want the user to be able to abort.  It should only be used rarely,
 * and only in scenarios where an abort is impossible.
 * 
 * When LOG_WHEN_FAILED_OFF, a command execution failure for any reason will not
 * show up in the Event Log.  This is generally set when failure is acceptable
 * and is handled by the caller, so logging is not necessary.
 * 
 * Note that both GETARGS and ALWAYSGETARGS may result in the set arguments of
 * a command changing, even if there is an error or the user aborts the dialog.
 * 
 */

        #define LXfCMD_EXEC_NONE			 0x0000

        #define LXfCMD_EXEC_GETARGS			 0x0100
        #define LXfCMD_EXEC_GETARGS_FORCESUB		 0x0200
        #define LXfCMD_EXEC_GETARGS_FORCESUB_OFF	 0x0400

        #define LXfCMD_EXEC_ALWAYSGETARGS		 0x0800

        #define LXfCMD_EXEC_TOGGLED			 0x1000

        #define LXfCMD_EXEC_NO_ABORT			 0x2000

        #define LXfCMD_EXEC_LOG_WHEN_FAILED_OFF		 0x8000

        #define LXfCMD_EXEC_MASK			 0xFF00

        #define LXxCMD_EXEC_MASK( flags )		 ((flags) & LXfCMD_EXEC_MASK)

/*
 * Various commands need to open dialogs or other user interface elements.
 * However, this is not always desirable in all contexts, such as when the
 * command is running from a script.  Before trying to open any dialogs or
 * otherwise interacting with the user the command should use the following
 * macro with its execution flags to see if such interaction is allowed.
 */

        #define LXxCMD_IS_USER_INTERACTION_OK( flags )	 ((flags & LXfCMD_EXEC_GETARGS) || (flags & LXfCMD_EXEC_ALWAYSGETARGS))

/*
 * DEFAULT is the default set of flags that should be used in most circumstances
 * for execution, argument parsing, etc.
 * The high bit is reserved for internal use.  It is used to esnure that sub-command
 * executions are passed their parent's command flags.  However, in rare cases it may
 * be intentional to pass execution flags to a sub-command.  In this case, the internal
 * marker flag can be directly specified to suppress the errors that will otherwise
 * be reported.
 */

        #define LXfCMD_EXEC_PARENT_FLAGS_PASSED_MARKER	 0x8000

        #define LXxCMD_EXEC_WERE_PARENT_FLAGS_PASSED(flags) ((flags) & LXfCMD_EXEC_PARENT_FLAGS_PASSED_MARKER)

/*
 * These are the default execution and alert flags.
 */

        #define LXfCMD_ALERT_DEFAULT			 (LXfCMD_ALERT_SHOWERR | LXfCMD_ALERT_SYNTAXERR)
        #define LXfCMD_EXEC_DEFAULT			 (LXfCMD_ALERT_SHOWERR | LXfCMD_ALERT_SYNTAXERR | LXfCMD_EXEC_GETARGS)

/*
 * We also hve one other special flag.  If any of the GETARGS or SHOWERR flags were
 * set by parsing the command string for leading +, ++, ! or !! flags, then
 * PARSED_FLAGS will also be set.
 */

        #define LXfCMD_PARSED_FLAGS			 0x10000000

/*
 * Flags can be any combination of the following.  If none of these are set,
 * the argument is required, and must be set by the client/user when the
 * command is fired.  The bulk of these flags are set during initialization.
 */

        #define		LXfCMDARG_INIT_ONLY			 0x0FFFF
        #define		LXfCMDARG_OPTIONAL			 0x00001
        #define		LXfCMDARG_QUERY				 0x00002
        #define		LXfCMDARG_READONLY			 0x00004
        #define		LXfCMDARG_VARIABLE			 0x00008
        #define		LXfCMDARG_DYNAMICHINTS			 0x00010
        #define		LXfCMDARG_REQFORVARIABLE		 0x00020
        #define		LXfCMDARG_HIDDEN			 0x00040
        #define		LXfCMDARG_DYNAMIC_DEFAULTS		 0x00080
        #define		LXfCMDARG_DIALOG_ALWAYS_SETS		 0x00100
        #define		LXfCMDARG_CAN_QUERY_WHEN_DISABLED	 0x00200
        #define		LXfCMDARG_DIALOG_DIVIDER_AFTER_ARG	 0x00400		// Obsolete; use DialogFormatting() instead

        #define		LXfCMDARG_STATE_ONLY			 0xF0000
        #define		LXfCMDARG_VALUE_SET			 0x10000
        #define		LXfCMDARG_CHANGED			 0x20000
        #define		LXfCMDARG_REQFORVAR_SET			 0x40000

        #define		LXxCMDARG_ISREQFORVARIABLE(f)	   ((f) & LXfCMDARG_REQFORVARIABLE)
        #define		LXxCMDARG_ISVARIABLE(f)		   ((f) & LXfCMDARG_VARIABLE)
        #define		LXxCMDARG_ISREQUIRED(f)		( (((f) & LXfCMDARG_INIT_ONLY) == 0) || (((f) & LXfCMDARG_INIT_ONLY) == LXfCMDARG_REQFORVARIABLE) )
        #define		LXxCMDARG_ISNEEDED(f)		( !((f) & LXfCMDARG_OPTIONAL) && !((f) & LXfCMDARG_READONLY) )
        #define		LXxCMDARG_ISQUERY(f)		(  ((f) & LXfCMDARG_QUERY)    ||  ((f) & LXfCMDARG_READONLY) )

        #define		LXxCMDARG_ISSET(f)		((f) & LXfCMDARG_VALUE_SET)

/*
 * This optional interface is used to aid in setting up the documention.  It is
 * only implemented by commands that do their own custom help key lookup, such
 * as item.channel.  Most commands can skip it.  Each line of the string returned
 * commonly starts with "\n  " so that it's nicely formatted.
 */

        #define LXu_COMMANDDBHELP	"7c8a58e0-0052-4d8e-addb-7387fba9d5bf"
        #define LXa_COMMANDDBHELP	"commanddbhelp"
        // [local]  ILxCommandDBHelp

/*
 * Hints for the user interface can be provided through an ILxUIHints object passed
 * to the ILxAttributes::UIHints() method.  Different systems may implement different
 * ILxUIHints for their own purposes, which may result in slightly different behavior
 * depending who is calling the UIHints() method.  See ILxAttributes in valet/umath.qq
 * for more information on UIHints().  Note that systems generally expect an ILxMessage
 * interface on the UI Hints object that is used to descide if the argument is enabled
 * and to get a disable message.
 */

        #define LXu_UIHINTS		"944D9CFD-DB04-4bba-B8B1-ADE424695EDC"
        #define LXa_UIHINTS		"uihints"
        // [local]  ILxUIHints

/*
 * Boolean controls are normally represented as checkmarks in forms.  The user can
 * override this behavior from the From Editor to create a toggle-style button instead.
 * This hint can be used by the client to state its preference for checkmarks vs.
 * toggle-style buttons.
 */

        #define LXiBOOLEANSTYLE_DEFAULT		0
        #define LXiBOOLEANSTYLE_CHECKMARK	1
        #define LXiBOOLEANSTYLE_BUTTON		2

/*
 * There are also a few channel-specific flags.  These are usually used in specific
 * contexts, and are described in detail below:
 */

        #define LXfUIHINTCHAN_OUTPUT_ONLY	0x00000001
        #define LXfUIHINTCHAN_INPUT_ONLY	0x00000002
        #define LXfUIHINTCHAN_SUGGESTED		0x00000004
        #define LXfUIHINTCHAN_HIDDEN		0x00000008


        #define LXfCLIPCHOICE_FOLDERS	 0x01
        #define LXfCLIPCHOICE_GROUPS	 0x02

/*
 * Commands are often assigned to forms to decide if the form is visible or not.  These
 * command filters normallly just need to be enabled or have their queried state return
 * true, and that's that.  However, certain forms like Item Properties show a series of
 * vertical tabs, and forms attempts to intelligently determine which tab to automatically
 * select if a previously selected tab is no longer visible due to filtering.  Usuually
 * the most recently selected item's tab should be the one that is selected.  Other forms
 * may have other crieteria for deciding which tab is first based on their command filters.
 * Usually all vtab forms in a form view use the same command filter, or at least commands
 * that use the same criteria.
 * The form filter priority is used to decide which tab best matches the current selection.
 * The closer the priority is to 0, the more likely it is to have its tab chosen.  Often
 * this is just the index of the item in the selection that matches the filter's criteria.
 * If multiple filters returns the same priority, the first form in the list is chosen.
 * Filters with priorities below LXiCMD_FORMFILTERPRIORITY_DEFAULT will always be chosen
 * before legacy filters and unfiltered forms.
 * If the priority is implemented, the command only needs to implement its UIHints method
 * for the LXiATTRUI_ANY "argument", to be a filter, and no other methods -- the enable
 * state and query value will be ignored.  A priority of LXiCMD_FORMFILTERPRIORITY_NO_MATCH
 * indicates that the filter doesn't match and the form should be hidden.  The command flags
 * should be set to LXfCMD_NO_EXEC as well.
 * 
 * Note that if a priority is set (including NO_MATCH), the enable function and queried
 * argument values will not be tested -- only the priority will be used to decide if the
 * form is filtered or not.
 * 
 */

        #define LXiCMD_FORMFILTERPRIORITY_NO_MATCH	(-1)		// Filter doesn't match
        #define LXiCMD_FORMFILTERPRIORITY_LAST		(999999)	// Lowest priority (for all practical purposes), commonly used for tabs that are always visible when any element is selected (User Channels and Item Tags in the Item Properties, for example)
        #define LXiCMD_FORMFILTERPRIORITY_DEFAULT	(888888)	// The default priority if the command doesn't set one itself

/*
 * This sibling interface provides a way to read the values from an ILxUIHints object,
 * if it implements the interface.  The method names are the same, but they return
 * values instead of setting them.
 */

        #define LXu_UIHINTSREAD		"8f22a96d-94e5-49c8-b3d4-a4080fbee91b"
        #define LXa_UIHINTSREAD		"uihintsread"
        // [local]  ILxUIHintsRead

/*
 * An ILxUIValueHints object can be allocated for an argument, and can be queried for
 * more complex state.
 */

        #define LXu_UIVALUEHINTS	"57E8F131-CE2D-42C6-8241-A395253B37D6"
        #define LXa_UIVALUEHINTS	"uivaluehints"
        // [local]  ILxUIValueHints
        // [export] ILxUIValueHints
        // [python] ILxUIValueHints:PopIconImage	obj Image
        // [python] ILxUIValueHints:ItemTest		bool

/*
 * The flags method determines which properties of the ILxUIValueHints object are valid.
 * The appropriate flags must be set if you want the associated methods to be called.
 * - POPUPS
 * The attribute has a popup to select possible settings. The Pop...() functions will
 * only be called if this is set.
 * - POPUP_DIRECT
 * This is a hint about how to construct the popup. If this is a string attribute then
 * the user will be able to type in a string directly into an edit field, as well as
 * selecting from a list of existing choices in the popup.
 * 
 * - POPUP_ALPHA_SORT
 * This causes the popup's contents to be sorted alphabetically.
 * 
 * - ITEMS
 * The attribute is an item type ("&item" exoType), and the hint object provides a
 * filter.
 * 
 * - ITEMS_NONE
 * The item popup can support a "(none)" option.
 * 
 * - FORMS_COMMAND_LIST
 * The forms command list functions are implemented.  See below for more information.
 * 
 * - POPUPS_NO_FILTER
 * Disables the string filter on long lists.
 * 
 */

        #define LXfVALHINT_POPUPS		0x001
        #define LXfVALHINT_POPUP_DIRECT		0x002
        #define LXfVALHINT_POPUP_ALPHA_SORT	0x004
        #define LXfVALHINT_ITEMS		0x008
        #define LXfVALHINT_ITEMS_NONE		0x010
        #define LXfVALHINT_FORM_COMMAND_LIST	0x020
        #define LXfVALHINT_POPUPS_NO_FILTER	0x040

/*
 * This method allows flags to be returned on a per-entry basis.  It need not be implemented,
 * in which case the default behavior occurs.  The low bits are used to defined a "group mask",
 * casuing a divider to be inserted if two elements do not share the same group.  Checkmarks can
 * be added  with the SELECTED flag, while a mixed state can be shown by using both SELECTED and
 * UNSELECTED (UNSELECTED doesn't need to be used by itself, as it is implied).  Entries can
 * be drawn ghosted with the DISABLED flag.
 * Note that implement PopFlags() means that you are responsible for marking your currently
 * selected item, if applicable.
 */

        #define LXmPOPFLAGS_GROUP_MASK		0x00F

        #define LXfPOPFLAGS_SELECTED		0x010
        #define LXfPOPFLAGS_UNSELECTED		0x020
        #define LXfPOPFLAGS_MIXED		0x030
        #define LXfPOPFLAGS_DISABLED		0x080

/*
 * This interface was retired in modo 13, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXu_UIVALUEHINTS3	"ded71bdb-080c-4ce8-bf06-69e372ea8bea"
        // [local]  ILxUIValueHints3
        // [export] ILxUIValueHints3

/*
 * This interface was retired in modo 10.2, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXu_UIVALUEHINTS2	"f37bb385-7214-42d5-9bed-552ff4738908"
        // [local]  ILxUIValueHints2
        // [export] ILxUIValueHints2

/*
 * This interface was retired in modo 601, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXu_UIVALUEHINTS1	"7BB10C3F-1FFB-4104-8FBE-CB1C334EE3C1"
        // [local]  ILxUIValueHints1
        // [export] ILxUIValueHints1

/*
 * It is not uncommon for clients sporting an ILxAttributes interface to need to
 * present some kind of UI.  Thus we have this sibling interface, ILxAttributesUI,
 * which provides UI-specific additions.  The ILxAttributes::Count() method is used
 * to get the number of attributes as normal, with those indices being passed to the
 * ILxAttributesUI methods to get information about a specific attribute.
 */

        #define LXu_ATTRIBUTESUI	"44D9C65E-AE2E-4012-AB57-E2839734F7FF"
        #define LXa_ATTRIBUTESUI	"attributesui"
        // [local]  ILxAttributesUI
        // [export] ILxAttributesUI atrui
        // [python] ILxAttributesUI:UIValueHints	obj UIValueHints

/*
 * The UIHints() method is called to fill in an ILxUIHints object given an
 * attribute index, thus providing it with a graphical user interface.
 * Note that an index of LXiATTRUI_ANY may be passed in cases where
 * information is being requested for the entire command (usually when
 * the command is represented as a button in form, for example, or when
 * used as a form command filter), instead of for a specific argument.
 */

        #define LXiATTRUI_ANY			-1

/*
 * When the notifier wants to send an event to its clients, it uses this function.
 * The notifier simply has to provide that kind of refresh that's required (value,
 * label, disable or datatype), and this function will take care of notifying all
 * the clients.
 */

        #define	LXfCMDNOTIFY_VALUE	0x01
        #define	LXfCMDNOTIFY_LABEL	0x02
        #define	LXfCMDNOTIFY_DISABLE	0x04
        #define	LXfCMDNOTIFY_DATATYPE	0x08

        #define	LXfCMDNOTIFY_CHANGE_ALL	0x0F

/*
 * This is used to send the event (meaning, the changed flags) to a client as a
 * result of CmdNotify() being called.
 */

        #define LXu_COMMANDEVENT	"F7CD29B5-6858-445b-BE6D-8347603B47E9"
        #define LXa_COMMANDEVENT	"commandevent"
        // [export] ILxCommandEvent cevt
        // [local]  ILxCommandEvent

/*
 * This interface was retired in modo 701, and was replaced with an updated one
 * that adds new methods.
 */

        #define LXu_COMMAND1		"4F540BF1-F97E-4D46-8A5F-6B2750A6CEB9"
        // [export] ILxCommand1 cmd1
        // [local]  ILxCommand1

/*
 * This interface was retired in modo 801, and was replaced with an updated one
 * that adds new methods.
 */

        #define LXu_COMMAND2		"5e981e16-94b7-4364-92f0-d7679236f3d1"
        // [export] ILxCommand2 cmd2
        // [local]  ILxCommand2

/*
 * This interface was retired in modo 801, and was replaced with an updated one
 * that adds new methods.
 */

        #define LXu_COMMAND3		"db970a3b-dce1-4679-a4bf-b5f1dff4db0d"
        // [export] ILxCommand2 cmd2
        // [local]  ILxCommand2

/*
 * The command block interface is used to provide some basic information about
 * the current command block.
 */

        #define LXu_COMMANDBLOCK	"65AEBD9F-D518-47b2-8CC6-E453F8C43CB6"
        #define LXa_COMMANDBLOCK	"commandblock"

/*
 * The global service provides high-level access to the command system itself.
 * This includes operations such as walking the list of available commands and
 * instancing commands for querying and firing.
 */

        #define LXu_COMMANDSERVICE	"9DB8BA65-8C36-45A7-B403-DF7BA59BA6C2"
        #define LXa_COMMANDSERVICE	"commandservice"
        // [python] ILxCommandService:CommandByIndex		obj Command
        // [python] ILxCommandService:Proto			obj Command
        // [python] ILxCommandService:ProtoFromCommand		obj Command
        // [python] ILxCommandService:Spawn			obj Command
        // [python] ILxCommandService:SpawnFromCommand		obj Command
        // [python] ILxCommandService:SpawnFromString		obj Command
        // [python] ILxCommandService:SpawnUnaliased		obj Command
        // [python] ILxCommandService:RefireCmd			obj Command
        // [python] ILxCommandService:SpawnImplicitScript	obj Command

        // [python] ILxCommandService:ExecuteArgString2		obj Command
        // [python] ILxCommandService:ExecuteAttribObject2	obj Command
        // [python] ILxCommandService:ExecuteBooleanArgString2	obj Command
        // [python] ILxCommandService:ExecuteImplicitScript2	obj Command
        // [python] ILxCommandService:ExecuteToggleArgString2	obj Command

        // [python] ILxCommandService:GetToggleArgState		obj Value
        // [python] ILxCommandService:Query			obj ValueArray
        // [python] ILxCommandService:CreateQueryObject		obj ValueArray
        // [python] ILxCommandService:QueryArgString		obj ValueArray

        // [python] ILxCommandService:SandboxObjectByCommand	obj Unknown
        // [python] ILxCommandService:SandboxObjectByIndex	obj Unknown
        // [python] ILxCommandService:SandboxObjectLookup	obj Unknown

        // [python] ILxCommandService:IsAliased			bool
        // [python] ILxCommandService:IsBooleanArgString	bool
        // [python] ILxCommandService:IsContainer		bool
        // [python] ILxCommandService:IsGlobalInteractionOK	bool
        // [python] ILxCommandService:IsImplicitScript		bool
        // [python] ILxCommandService:IsToggleArgString		bool
        // [python] ILxCommandService:ExecuteArgString		global

        // [python] ILxCommandService:AllocateUIHintsFromCommand	obj UIHints

/*
 * This method allows clients to check the current status of the command system.
 * - INITIALIZING
 * When initially started, the command system is effectively disabled while it
 * initialized.  This is when many internal commands are set up and added to
 * containers and initial aliases are set up.  Commands cannot be executed
 * during initialization.
 * - NORMAL
 * The system is active and running as normal.  Commands can now be executed.
 * 
 * - EXECUTING_STARTUP_COMMANDS
 * This is a temporary state set when startup commands are being executed.
 * This is most commonly used by commands that cannot run at startup, thus
 * allowing them to return a meaningful error from their enable method
 * instead of doing something bad like crashing.  Once startup commands
 * have finished, the state resets to LXiCMDSTATUS_NORMAL.
 * 
 */

        #define LXiCMDSTATUS_INITIALIZING			0
        #define LXiCMDSTATUS_NORMAL				1
        #define LXiCMDSTATUS_EXECUTING_STARTUP_COMMANDS		2

/*
 * These set and get the command separator, which determines how command names returned
 * by ILxCommand::Name() are returned.  The set function returns false if the separator ID
 * entered isn't one of the following.
 */

        #define	LXiCMD_SEP_DOT		0
        #define	LXiCMD_SEP_BACKSLASH	1
        #define	LXiCMD_SEP_SLASH	2
        #define	LXiCMD_SEP_COLON	3

/*
 * The current refiring state can be tested with this function, which will
 * return if this the system is idle, if a command is being refired, or if
 * a block is being refired.  PENDING means that refiring has just begun,
 * but no commands or blocks have yet been fired.
 */

        #define	LXiCMDREFIRE_NONE		0
        #define	LXiCMDREFIRE_PENDING		1
        #define	LXiCMDREFIRE_COMMAND		2
        #define	LXiCMDREFIRE_BLOCK		3

/*
 * This is a mode to use "non-persistent refiring".  The post command mode is started
 * by calling CmdPostModeBegin.  In this mode, CmdPostModeEnd() must be called when
 * "post command" mode is complete.  Alternatively, the block can be implicitly closed
 * throught he use of an endObj.
 * The endObj is an ILxCommandPostEnd interface containing only one function, which
 * is called when the block is implicitly closed.
 */

        #define LXu_COMMANDPOSTEND	"AEB6B7BF-34B9-4991-904C-298B8DB1AE12"
        #define LXa_COMMANDPOSTEND	"commandpostmodeend"

/*
 * Command containers allow multiple similar commands that operate on different
 * contexts to be logically grouped together.  A prime example is a Delete
 * container, which can be mapped to a single key/button and be used to delete
 * whatever the current selection is, as long as the container has a matching
 * command for it.
 * Containers are used just like normal commands, but are implicitly created by
 * server tags attached to the command.  Containers have no arguments and no
 * significant user interface.
 * This server tags specify which container a command belongs, what arguments.
 * it should have set when executed from the container, and the selection types
 * it acts on.  A command can belong to multiple containers by space-delimiting
 * the container names, although the same execution arguments and selection types
 * will apply equally to both containers.  The selection type is set of four-
 * character strings that define types in the selection system.  Multiple types
 * can be provided by separating them with spaces.
 * 
 */

        #define LXsCMD_CONTAINER_NAME	"command.container.name"
        #define LXsCMD_CONTAINER_ARGS	"command.container.args"
        #define LXsCMD_CONTAINER_TYPES	"command.container.types"

/*
 * Flags can be any of the following.  When used in a sandbox, the flags should be
 * set to LXfCMDBLOCK_SANDBOX.  If UI or UNDO_UI are not specified, the block is
 * assumed to be UNOD (aka an undoable model command).
 */

        #define	LXfCMDBLOCK_PRESERVE_SELECTION	0x000100

        #define	LXfCMDBLOCK_UI			0x010000
        #define	LXfCMDBLOCK_UNDO_UI		0x020000

        #define	LXfCMDBLOCK_SANDBOXED		0x040000

        #define	LXfCMDBLOCK_UNDO_AFTER_EXEC	0x080000

        #define	LXfCMDBLOCK_POSTMODE		0x100000
        #define	LXfCMDBLOCK_STEPUNDO		0x200000

        #define	LXfCMDBLOCK_TOP_OF_CYCLE_SAFE	0x400000

/*
 * Some commands can only be executed in certain contexts.  These contexts are known
 * as "sandboxes".  There is a special global sandbox through with general, high-level
 * commands are executed, such as loading and saving, toggling tools, etc.
 * Other commands can be executed only within supported sandboxes.  The way this works
 * is simple enough:  A sandbox is created and filled with objects that the commands
 * operate on.  Once the sandbox is activated, only commands that can operate on the
 * objects within the sandbox can be executed.  These are commands with the LXfCMD_SANDBOXED
 * flag set and a sandbox GUID that matches one of the objects in the sandbox (see UI
 * command exceptions below).  Attempting to execute any other command will fail with
 * LXe_CMD_SANDBOX_NOT_COMPATIBLE.
 * Although only commands compatible with the sandbox can be executed, global commands
 * can be queried.  A flag can also be set to allow global UI and Side Effect commands
 * to be executed from within a sandbox.
 * 
 * 
 * The following flags are supported by the sandboxes.
 * 
 * - ALLOW_UI
 * If set, UI and Side Effect commands can be executed from within the sandbox.
 * 
 */

        #define	LXfCMDSANDBOX_ALLOW_UI	1

/*
 * Together with CurrentExecDepth(), these methods allow indirect access to the
 * commands that are currently being executed.
 * The username, internal name and argument string representing the commands on
 * the stack can be obtained with these functions, as well as the name of a
 * command block, and if the entry is a block or command.  Index must be between
 * 0 and the value returned by CurrentExecDepth() inclusive.
 * The type of the entry on the stack will be either a command or a command block.
 * 
 */

        #define LXiCMDENTRYTYPE_INVALID		0
        #define LXiCMDENTRYTYPE_COMMAND		1
        #define LXiCMDENTRYTYPE_BLOCK		2

/*
 * This variant of the ArgsAsStringLen function takes flags to alter the output of
 * the generated string.  
 * - INCLUDE_CMD
 * This replaces the includeCmd flag on the other ArgAsString functions, determining
 * if the final string starts with the command name.
 * 
 * - ITEM_AS_NAME
 * If set, any arguments with the &item datatype will be added with their item name
 * instead of their item identifier.  You usually want this flag to be unset when
 * reprsenting the results of a command execution, but set when using it in a form,
 * script or similar where it may be executed in a different context where the
 * item identifier may be different than it was when the command was last run.
 * 
 */

        #define	LXfCMDSYSARGSASSTRING_INCLUDE_CMD		0x00000001
        #define	LXfCMDSYSARGSASSTRING_ITEM_AS_NAME		0x00000002

/*
 * The command system listener can be used to listen for various events.
 */

        #define LXu_CMDSYSLISTENER	"d89ccb72-43b9-4bf2-bb7d-7e816bb4d9d8"
        // [local]  ILxCmdSysListener
        // [export] ILxCmdSysListener cmdsysEvent

/*
 * These are called for the different stages of command execution.  The
 * ExecutePre() event is called before the command is actually executed,
 * and ExecuteResult() is called with a true/false indicating if the
 * execution was successful.  ExecutePost() is called just before a
 * command is cleaned up and removed from the execution stack.
 * In all cases the ILxCommandID should be considered read-only, and messing
 * with it will probably do bad things to the system.  The isSandboxed flag
 * is set if the command is executed in a sandbox, but since sandboxes are
 * currently used this will always be 0.
 * The type flag (included for all but ExecutePost()) indicates the how the
 * command was executed relative to other commands.  QUIET means the command
 * does not show up in the command history. ROOT means this was a root-level
 * command from the point of view of the history, and will be set all
 * root-level commands and children of QUIET commands.  SUB means that this
 * command was executed as a child of another non-QUIET command.
 * 
 * ExecutePre(), ExecuteResult() and ExecutePost() are all always called for
 * any given command execution, and always in this order.  However, more
 * Pre()/Result()/Post() calls may occur between other Pre() and Result()
 * calls as sub-commands are executed.
 * 
 */

        #define	LXiCMDSYSEVENT_TYPE_QUIET	1
        #define	LXiCMDSYSEVENT_TYPE_ROOT	2
        #define	LXiCMDSYSEVENT_TYPE_SUB		3

#endif
