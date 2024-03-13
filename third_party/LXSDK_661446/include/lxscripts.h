/*
 * LX scripts module
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
#ifndef LX_scripts_H
#define LX_scripts_H

typedef struct vt_ILxScriptSysService ** ILxScriptSysServiceID;
typedef struct vt_ILxUserValue ** ILxUserValueID;
typedef struct vt_ILxKit ** ILxKitID;
typedef struct vt_ILxSessionListener ** ILxSessionListenerID;
typedef struct vt_ILxUserValueListener ** ILxUserValueListenerID;
typedef struct vt_ILxScriptManager ** ILxScriptManagerID;
typedef struct vt_ILxTextScriptInterpreter ** ILxTextScriptInterpreterID;
typedef struct vt_ILxScript ** ILxScriptID;
typedef struct vt_ILxPlatformService ** ILxPlatformServiceID;
typedef struct vt_ILxAppActiveListener ** ILxAppActiveListenerID;
typedef struct vt_ILxLineInterpreter ** ILxLineInterpreterID;
typedef struct vt_ILxLineExecution ** ILxLineExecutionID;
typedef struct vt_ILxScriptLineEvent ** ILxScriptLineEventID;

#include <lxserver.h>
#include <lxvalue.h>



/*
 * 
 * 
 * 
 * Managers can also be looked up by name.
 * 
 * Some user interface information about a manager can be read with these functions.
 * User strings are looked up in the message table matching the manager's name with
 * "{scriptservice} " prefixed.
 * 
 * 
 * The list of user values can be walked directly, or a specific user value
 * can be looked up by name.  The object returned has an ILxUIserValueDef
 * interface.  This includes all config, temporary and momentary user values.
 * These methods are implemented as of nexus 801.
 * User values can only be created with user.defNew, edited with user.def,
 * the value set with user.value.  None of these functions or those commands
 * are thread-safe, and care should be taken to not call these from a thread.
 * 
 * 
 * To simplify the use of scripts in kits, we support script aliases.  This allows
 * a script hash (aka the path to a script on disk) to be aliased to an arbitrary
 * string.
 * Script aliases are defined solely from within configs, usually by the script's
 * developer.  The alias may include path aliases, and may included any ASCII
 * characters, although it is important to note that it is not a translatable
 * string.
 * 
 * When used in kits, the simple form can be used when the script is in the kit's
 * directory:
 * 
 * 	<hash type="ScriptAlias" key="aliasedScriptName">myScript.pl</p>
 * 
 * When defined outside of a kit, the full path to the script must be used.
 * 
 * 	<hash type="ScriptAlias" key="aliasedScriptName">pathAlias:dir/myScript.pl</p>
 * 	<hash type="ScriptAlias" key="aliasedScriptName">c:\dir\myScript.pl</p>
 * 
 * Once defined, the script alias can be used in place of the script's path at any
 * time to lookup and/or execute the script, including in commands like script.run,
 * script.implicit, and the @ syntax.
 * 
 * This utility can be used by clients to resolve a script alias to its full path.
 * The path returned will always be a valid string, returning a the resolved path
 * if possible, and returning the alias otherwise.  This allows you to just pass
 * in any script path or a known alias and get back a usable path, even though
 * the function will fail if the alias cannot be resolved.
 * 
 * This returns LXe_NOTFOUND if the alias does not exist, in which case the alias
 * passed in is returned.  This returns LXe_FAILED if the alias exists, but could
 * not be resolved into an absolute path.  In this case, the aliased path will
 * be returned instead of the alias name or the resolved path.
 * 
 * Just to clarify:
 * - LXe_FAILED returns the alias: aliasedScriptName
 * - LXe_NOTFOUND returns the alias path: pathAlias:dir/myScript.pl
 * - LXE_OK returns the resolved absolute path: <path that 'pathAlias:' points to>/dir/myScript.pl
 * 
 * 
 * This provides a high-level way to look up a scriopt by path.  It loops though
 * all of the script servers and returns the ILxScriptManager that found the script,
 * and an ILxScript representing the script itself.  The write and tryAsUsername
 * arguments work identically to those on the ILxScriptManager::Lookup() method.
 * This also provides a caching mechanism based on the script's path, making it
 * efficient to look up a script without having to hit the disk each time for
 * disk-based scripts.
 * 
 * 
 * Kits extend Nexus functionality by adding a collection of self contained scripts,
 * plugins and configs. Clients can enumerate over kits using the following functions.
 * Returns the numer of kits. If 'visible' is not 0, then the list of kits will be
 * limited to kits that are visible in the user interface.
 * 
 * 
 * Allocates an ILxKit object representing the kit specified by index. If 'visible'
 * is not 0, then the list of kits will be limited to kits that are visible in the
 * user interface.
 * 
 * Allocates an ILxKit object representing the kit specified by name.
 */
typedef struct vt_ILxScriptSysService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
NameByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **name);
        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		 self,
        const char		*name,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		 self,
        LXtObjectID		 manager,
        const char	       **name);
        LXxMETHOD(  LxResult,
Desc) (
        LXtObjectID		 self,
        LXtObjectID		 manager,
        const char	       **name);
        LXxMETHOD(  LxResult,
UserValueCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
UserValueByIndex) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
UserValueLookup) (
        LXtObjectID		  self,
        const char		 *name,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ResolveAlias) (
        LXtObjectID		  self,
        const char	         *alias,
        const char		**path);
        LXxMETHOD(  LxResult,
LookupScript) (
        LXtObjectID		  self,
        const char		 *hash,
        int			  write,
        int			  tryAsUsername,
        void			**service,
        void			**script);
        LXxMETHOD(  LxResult,
KitCount) (
        LXtObjectID		  self,
        int			  visible,
        int			 *count);
        LXxMETHOD(  LxResult,
KitByIndex) (
        LXtObjectID		  self,
        int			  index,
        int			  visible,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
KitLookup) (
        LXtObjectID		  self,
        const char		 *name,
        void			**ppvObj);
} ILxScriptSysService;

/*
 * These methods get the value's name and username.  If the username is not set,
 * this just returns the name.
 * The Name() method will always succeed as long as the underlying user value
 * exists.  This can be used as a way to test if the object is still valid,
 * or if the user value itself has been deleted out from under the object.
 * 
 * These return the type (as an LXi_TYPE_ define) and type name of the user value.
 * 
 * For config user values, this returns LXe_TRUE if a user value is transient,
 * and LXe_FAILS if not.  Transient values have a default that is loaded from
 * the config, but the new value is never written to the config -- it is only
 * stored in memory.
 * 
 * These return the value of the user value.  GetString() will work on anything, and will
 * return the "raw" string version of the value.
 * 
 * 
 * Get the min/max values.  There are separate functions for float and int
 * types, as well as flags indiciating if min/max is set.
 * 
 * Get the list and their names as string, similar to the one passed to user.def.
 * The ArgumentType used to get usernames from the config is also available.
 * These methods fail with NOTAVAILABLE for non-integer types, and fail with
 * NOTFOUND if they are not set.
 * 
 * Get the action (command string) executed when the user value changes.  Returns
 * NOTFOUND if no action is set.
 * 
 * 
 * This returns LXe_TRUE if an action is to be deferred after refiring has completed,
 * and LXe_FALSE if not.  It returns NOTFOUND if no action is set.
 * 
 * Get the dialog username string for the user value.  Returns NOTFOUND if none
 * is set.
 * 
 * Get the value preset cookie string for the user value.  Returns NOTFOUND if no action
 * is set.
 * 
 * Get the command whose enable state is also applied to this user value.  Returns NOTFOUND if
 * none is set.
 * 
 * Get the notifier that causes the user value's control to be updated in the interface.
 * Returns NOTFOUND if none is set.
 * 
 * Get the default value as an ILxValue.  This fails with NOTFOUND if none is set.
 * 
 * Get if changing the user value via user.value be treated as an undoable UI command
 * instead of an undoable model command.  UI commands exist in the undo stack only until
 * a model command is executed, while model commands persist in the stack.  UI mode is
 * useful when creating preferences, while model mode is useful when the user value is
 * used to directly affect the scene itself, usually by performing an assocated action
 * when the value changes.  This returns LXe_TRUE for UI style behavior, and LXe_FALSE
 * for model style behaviors.
 * 
 * Get if the enable command test is inverted or not.  Normally, when the enable
 * command is disabled, or it is enabled but queries to false, then the user value
 * is also disabled.  This simply flips the test.
 * 
 */
typedef struct vt_ILxUserValue {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        const char		**name);

        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		  self,
        const char		**username);
        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		  self,
        int			 *type);

        LXxMETHOD(  LxResult,
TypeName) (
        LXtObjectID		  self,
        const char		**tname);
        LXxMETHOD(  LxResult,
IsTransient) (
        LXtObjectID		  self,
        int			 *isTransient);
        LXxMETHOD(  LxResult,
GetInt) (
        LXtObjectID		  self,
        int			 *val);

        LXxMETHOD(  LxResult,
GetFlt) (
        LXtObjectID		  self,
        double			 *val);

        LXxMETHOD(  LxResult,
GetString) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
Lifespan) (
        LXtObjectID		  self,
        int			 *life);
        LXxMETHOD(  LxResult,
FloatRange) (
        LXtObjectID		  self,
        int			 *hasMin,
        double			 *min,
        int			 *hasMax,
        double			 *max);
        LXxMETHOD(  LxResult,
IntRange) (
        LXtObjectID		  self,
        int			 *hasMin,
        int			 *min,
        int			 *hasMax,
        int			 *max);
        LXxMETHOD(  LxResult,
List) (
        LXtObjectID		  self,
        const char		**list);

        LXxMETHOD(  LxResult,
ListNames) (
        LXtObjectID		  self,
        const char		**listNames);

        LXxMETHOD(  LxResult,
ArgType) (
        LXtObjectID		  self,
        const char		**argType);
        LXxMETHOD(  LxResult,
Action) (
        LXtObjectID		  self,
        const char		**action);
        LXxMETHOD(  LxResult,
DeferAction) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
DialogUserName) (
        LXtObjectID		  self,
        const char		**username);
        LXxMETHOD(  LxResult,
ValuePresetCookie) (
        LXtObjectID		  self,
        const char		**cookie);
        LXxMETHOD(  LxResult,
EnableCommand) (
        LXtObjectID		  self,
        const char		**command);
        LXxMETHOD(  LxResult,
Notifier) (
        LXtObjectID		  self,
        const char		**notifier);
        LXxMETHOD(  LxResult,
DefaultValue) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
AsUI) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
InvertEnableCommandTest) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
UIMode) (
        LXtObjectID		  self,
        int			 *uiMode);
} ILxUserValue;

/*
 * Returns the name of the kit.
 * 
 * Returns the version string for the kit.
 * 
 * Returns LXe_TRUE or LXe_FALSE if the kit is enabled.
 * 
 * Enabled or Disable the kit. Note that the program will need to be restarted
 * before the change takes effect.
 * 
 * Returns LXe_TRUE or LXe_FALSE if the specified kit is visible, or marked as
 * internal.
 */
typedef struct vt_ILxKit {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        const char		**name);
        LXxMETHOD(  LxResult,
Version) (
        LXtObjectID		  self,
        const char		**version);
        LXxMETHOD(  LxResult,
IsEnabled) (
        LXtObjectID		  self);
        LXxMETHOD(  void,
SetEnabled) (
        LXtObjectID		  self,
        int			  enabled);
        LXxMETHOD(  LxResult,
IsVisible) (
        LXtObjectID		  self);
} ILxKit;

/*
 * This is called just before the first window (usually the main window) is
 * opened, which generally means that the app is nearing final readiness.
 * This is not sent in headless mode for obvious reasons.
 * 
 * This is called just before the startup commands are executed.  This can be
 * used to execute other startup commands from code, for example, or to query
 * commands.
 * 
 * This is called after any startup comamnds have executed, and just before
 * the application main loop starts, and indicates that the application is
 * fully initialized and ready.
 * 
 * This is called when the app's UI is told to quit, usually because the user tried
 * to close the main window or chose Quit from the system menu.  Most importantly,
 * the main window is still open at this time, and the listener can open dialogs and
 * is able to abort the quit by returning LXe_FALSE.
 * Remember that you may not be the only session listener, that all listeners will
 * get this event, and that the abort state won't be read until all listeners have
 * returned (this is jsut how listeners work).  Before opening a dialog or doing any
 * other quit tests, you should check the value of quitWasAborted; if ture, you may
 * simply want to exit early because another listeener has decided that we're not
 * going to quit after all.
 * 
 * As the name implies, this method is only sent from the UI, and never from headless.
 * If you need to save critical state, yous hould do so from ShuttingDown().
 * 
 * 
 * If no listeners have aborted the quit, this method is called to indicate that we
 * really are going to exit the app.  At this point the main window is still open,
 * so if you want to save something with a progress bar or the possibility of opening
 * an error dialog, you can.  However, you will not be able to keep the app from
 * quitting.
 * Once again, this is not sent from headless mode.
 * 
 * 
 * This is called just after the last window (usually the main window) has
 * closed, indicating that the application is about to shut down. This is
 * not sent in headless mode for obvious reasons.
 * 
 * After all windows have been closed (or in headless, if we're about to quit),
 * this is called to indicate that we're going to start shutting down the remaining
 * systems and exit the app.  This is a good time to store any other state you may
 * want to persist between sessions.
 */
typedef struct vt_ILxSessionListener {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
FirstWindowOpening) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
BeforeStartupCommands) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
SystemReady) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
CheckQuitUI) (
        LXtObjectID		  self,
        int			  quitWasAborted);
        LXxMETHOD(  LxResult,
QuittingUI) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
LastWindowClosed) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
ShuttingDown) (
        LXtObjectID		  self);
} ILxSessionListener;

/*
 * This is called after a new user value is added.  The object provided has
 * an ILxUserValue interface.  Since the value was just added, the obejct is
 * only immediately useful for getting its name, as everything else will be
 * defaults.
 * 
 * This is called just after an existing user value is deleted.  Since the
 * object was just deleted, only the name is provided.
 * 
 * This is called when the definition (one of the properties) of a user value
 * has changed.  The object provided has an ILxUserValue interface.
 * 
 * This is called when the user value's value changes.  It is also called for
 * all user values on startup, thus ensuring that clients that only listen for
 * this event can get useful default values.  The object provided has an
 * ILxUserValue interface.
 */
typedef struct vt_ILxUserValueListener {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Added) (
        LXtObjectID		  self,
        LXtObjectID		  userValue);
        LXxMETHOD(  LxResult,
Deleted) (
        LXtObjectID		  self,
        const char		 *name);
        LXxMETHOD(  LxResult,
DefChanged) (
        LXtObjectID		  self,
        LXtObjectID		  userValue);
        LXxMETHOD(  LxResult,
ValueChanged) (
        LXtObjectID		  self,
        LXtObjectID		  userValue);
} ILxUserValueListener;

/*
 * This returns the name of the script manager, which should be the name of the plug-in
 * itself, or else the system will get very confused.  Script manager names should have
 * the format "name.scriptservice", as the .scriptservice part is automatically skipped
 * during lookup for convenience.
 * 
 * - CREATE
 * - REMOVE
 * These should be set if the Script Editor can create or delete scripts.
 * - LINE_ACTION
 * This is set if an operation is defined for single lines in a script.  For example,
 * double-clicking on a macro line to execute that command.
 * 
 * 
 * These functions allow the list of available scripts to be walked.  When getting a script
 * from the manager, the write flag determines if the script is read-only or read/write.
 * This is just a hint; if the script cannot be modified and the write flag is set, the
 * function should fail with LXe_SCRIPT_READONLY.
 * 
 * 
 * This looks up a script by its hash.  Note the lookup may succeed even if it is
 * not in the script list, as the manager may try to load the script off disk, for
 * example.  If tryAsUserName is true, the hash will be looked up as a username if
 * it cannot be found as a hash.
 * It is important to note that the hash may not be what you expect.  For example,
 * if you normally expect a path to a file, you should be able to handle arbitrary
 * cases like config hashes (say, "872345659345:macro") and not try to pass them
 * to file system functions that might hit the network and create long delays.
 * 
 * Similarly, if you recognize the hash as your own but cannot find the contents,
 * you should return LXe_SCRIPT_RECOGNIZED_INVALID.  This keeps other servers
 * from having to scan servers that only you recognize.
 * 
 * 
 * Scripts can be read-only (for example, if the perl script is read-only on disk,
 * or the config the macro is in is imported).  This function tells if the script
 * can be instanced as read/write or just read-only.
 * Since the intention is to see if the script can be instanced as read/write before
 * you have a script ID, this takes a hash or index as its args; the index is checked
 * if the hash is NULL.
 * 
 * 
 * A new script for this manager can be created and filled in by the client.
 * 
 * 
 * An existing script can be removed from the system.  This only removes the
 * script; it does not necessarily delete it from disk.
 * 
 * Scripts can be validated to ensure that they are supported by the interpreter and to
 * check that they are free of errors before execution.  The interpreter should return
 * SCRIPT_UNKNOWN if the script is not supported by the interpreter, and SCRIPT_ERROR if
 * there is a problem parsing the script.  SCRIPT_WARNING can be returned if there are
 * only warnings, but since this is an OK code, the script can still be considered mostly
 * valid and thus executable.
 * 
 * A script can be executed with this function.  The command services global can be
 * used to query and execute commands as needed.  Commend execution flags are also provided,
 * which can be used to decide how to interact with the user for warnings, etc.  A list of
 * optional arguments can also be provided as a string, or be NULL.
 */
typedef struct vt_ILxScriptManager {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        const char	       **name);
        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		 self,
        int			*flags);
        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj,
        int			 write);
        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		 self,
        const char		*hash,
        void		       **ppvObj,
        int			 write,
        int			 tryAsUserName);
        LXxMETHOD(  LxResult,
ReadWrite) (
        LXtObjectID		 self,
        const char		*hash,
        int			 index);
        LXxMETHOD(  LxResult,
New) (
        LXtObjectID		 self,
        const char		*name,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Remove) (
        LXtObjectID		 self,
        LXtObjectID		 script);
        LXxMETHOD (LxResult,
Validate) (
        LXtObjectID		 self,
        LXtObjectID		 script,
        LXtObjectID		 msg);
        LXxMETHOD (LxResult,
Run) (
        LXtObjectID		 self,
        LXtObjectID		 script,
        int			 execFlags,
        const char		*args,
        LXtObjectID		 msg);
} ILxScriptManager;

/*
 * An initial validation of the file is performed to figure out what interpreters support
 * which files.  The interpreter is provided with an ILxScriptID and the first line of the
 * script, which allows for a common first-line check or a more complete check of the script's
 * contents via GetBuffer().  The hash of the script is the path of the file on disk, and
 * can be used to check the extension if desired.  The interpreter should return LXe_OK if
 * it can deal with this script, and LXe_SCRIPT_UNKNOWN if it cannot.
 * This method should be quick, since it may be called often.  Simply check the file type
 * here; don't test the script for errors or anything like that.
 * 
 * 
 * Before execution of a script, this function is called to ensure that the script is
 * properly formatted for execution by this interpreter.  SCRIPT_ERROR can be returned
 * on failer, and SCRIPT_WARNING if the script can be executed, but there may be
 * problems with it.  The ILxMessageID can be used to report specific errors.
 * 
 * A script can be executed with this function.  The command services global can be
 * used to query and execute commands as needed.  Commend execution flags are also provided,
 * which can be used to decide how to interact with the user for warnings, etc.  A list of
 * optional arguments can also be provided as a string, or be NULL.  The ILxMessageID can
 * be used to report specific errors.
 */
typedef struct vt_ILxTextScriptInterpreter {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ValidateFileType) (
        LXtObjectID		 self,
        LXtObjectID		 script,
        const char		*firstLine);
        LXxMETHOD(  LxResult,
Validate) (
        LXtObjectID		 self,
        LXtObjectID		 script,
        LXtObjectID		 msg);
        LXxMETHOD (LxResult,
Run) (
        LXtObjectID		 self,
        LXtObjectID		 script,
        int			 execFlags,
        const char		*args,
        LXtObjectID		 msg);
} ILxTextScriptInterpreter;

/*
 * Scripts have a hash used for lookup.  For macros, it's just the hash in the config;
 * for scripts in files, it might be the filename.
 * 
 * Scripts may have a username and description.
 * 
 * 
 * 
 * 
 * This returns a semicolon-delimited list of icon resources.  If not implemented,
 * the hash of the script is used.
 * 
 * The script manager can also return a help key, which will be looked up in the
 * HelpURLs config entries.  An argument string can also be provided for more
 * specific lookups.
 * 
 * The script's type is obtained by asking for its manager.
 * 
 * This gets the full text of the script as one large buffer, read-only NUL-terminated
 * text buffer. The length of the buffer is also returned.
 * 
 * This replaces the existing script's contents with a new one.  The buffer should be
 * NUL-terminated, and the buffer length should include the NUL.
 */
typedef struct vt_ILxScript {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Hash) (
        LXtObjectID		 self,
        const char	       **hash);
        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		 self,
        const char	       **userName);
        LXxMETHOD(  LxResult,
SetUserName) (
        LXtObjectID		 self,
        const char		*userName);
        LXxMETHOD(  LxResult,
Desc) (
        LXtObjectID		 self,
        const char	       **desc);
        LXxMETHOD(  LxResult,
SetDesc) (
        LXtObjectID		 self,
        const char		*desc);
        LXxMETHOD(  LxResult,
Icon) (
        LXtObjectID		 self,
        const char	       **icon);
        LXxMETHOD(  LxResult,
HelpKey) (
        LXtObjectID		 self,
        const char		*args,
        const char	       **key);
        LXxMETHOD (LxResult,
Manager) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD (LxResult,
GetBuffer) (
        LXtObjectID		 self,
        const char	       **buffer,
        unsigned int		*bufferLength);
        LXxMETHOD (LxResult,
SetBuffer) (
        LXtObjectID		 self,
        const char	        *buffer,
        unsigned int		 bufferLength);
} ILxScript;

/*
 * Get the user the app is licensed to.  If not licensed, this fails.
 * 
 * Get the number of days left until the key expires, or -1 if the key is
 * permanent.
 * 
 * Get the serial number of this key.
 * 
 * Get the number of licenses this key works with.
 * 
 * Get the application name.
 * 
 * Get the version and build numbers of the application.
 * 
 * This returns LXe_TRUE if the app is running in headless mode, and
 * LXe_FALSE if not.
 * 
 * 
 * 
 * 
 * Walk the list of paths.
 * 
 * This returns the internal name of the path, or NULL if the path
 * doesn't have one.
 * 
 * Walk the list of imported resource paths.
 * 
 * This returns true if the application (but not necessarily the platform) is 64 bit,
 * and false if it's 32 bit.
 * 
 * This arms a user idle action, preferably only once until it has been fired, after
 * which you can arm it again if necessary.
 * 
 * This can be used to remove a pending user idle action.  It will do nothing if the
 * idle action isn't armed.  Note that flags and the vistor pointer must be exactly
 * the same as the one passed to DoWhenUserIsIdle(), or else it will not be found and
 * the action will remain armed.
 * Note that when doing this from Python, you must pass the exact same visitor COM object
 * (not Python object).  This is also necessary when removing listeners and canceling
 * timers, as discussed here: http://modo.sdk.thefoundry.co.uk/wiki/FAQ#Q:_How_do_I_remove_a_listener_object_in_Python.3F
 * 
 * 
 * This simply returns if the user is currently idle.  It can be useful at times,
 * but generally you always want to perform your idle actions from DoWhenUserIsIdle().
 * 
 * Another useful feature is to be able to know when the app has become active or
 * inactive.  This returns LXe_TRUE if the app is currently active.
 * 
 * The current session stage can be read with this method, indicating the status of the
 * application.
 * 
 * - NOT_READY
 * The system is in the very early startup phase, and is not yet ready to be accessed.
 * - STARTUP_COMMANDS
 * Startup commands are or have just executed, and the system is almost completely up
 * and running.
 * 
 * - SYSTEM_READY
 * The main event loop is running, and the application is fully started.
 * 
 * - SHUTTING_DOWN
 * The main event loop has stopped, and the applicatin is shutting down.
 * 
 * You can register an ILxSessionListener to be notified when the stage changes.
 * 
 * 
 * The application username may be different from the internal name returned by AppName().
 * Usually this is farily minor, such as the case of the name.
 * 
 * 
 * Timers execute after a pre-determiend number of milliseconds.  A timer executes only
 * once, but you can re-arm it when it expires if you want.  The most common use of timers
 * is to check files for changes or trigger periodic refreshes of part of the UI.
 * Note that timers can trigger at arbitrary and unsafe times, such as in the middle of
 * rendering or while saving a file.  You should never execute a command from a timer,
 * for exmaple, but rather arm a user idle action (and even then executing commands is
 * a bit iffy, since now you're adding something to the command history or undo list
 * that the user didn't do directly, but sometimes it is necessary).  
 * 
 * If idleFlags are LXiUSERIDLE_ALWAYS, then the timer's visitor is called as soon as
 * the timer expires.  Otherwise, the action is deferred until user idle state matches
 * the flags.
 * 
 * 
 * A currently-running timer can be canceled with this function.  The visitor and flags
 * must match what the timer was armed with.
 * Note that when doing this from Python, you must pass the exact same visitor COM object
 * (not Python object).  This is also necessary when removing listeners and canceling
 * user idle actions, as discussed here: http://modo.sdk.thefoundry.co.uk/wiki/FAQ#Q:_How_do_I_remove_a_listener_object_in_Python.3F
 * 
 * 
 * This will return true if the app was started in safe mode.
 * 
 * Get the minor and service back version numbers.
 */
typedef struct vt_ILxPlatformService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
LicensedTo) (
        LXtObjectID		  self,
        const char		**licensee);
        LXxMETHOD(  LxResult,
ExpiresIn) (
        LXtObjectID		 self,
        int			*daysLeft);
        LXxMETHOD(  LxResult,
SerialNumber) (
        LXtObjectID		  self,
        const char		**serial);
        LXxMETHOD(  LxResult,
NumLicenses) (
        LXtObjectID		  self,
        int			 *licenses);
        LXxMETHOD(  LxResult,
AppName) (
        LXtObjectID		  self,
        const char		**name);
        LXxMETHOD(  LxResult,
AppVersion) (
        LXtObjectID		 self,
        int			*version);

        LXxMETHOD(  LxResult,
AppBuild) (
        LXtObjectID		 self,
        int			*build);
        LXxMETHOD(  LxResult,
IsHeadless) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
OSType) (
        LXtObjectID		 self,
        int			*type);
        LXxMETHOD(  LxResult,
OSName) (
        LXtObjectID		  self,
        const char		**name);
        LXxMETHOD(  LxResult,
OSVersion) (
        LXtObjectID		  self,
        const char		**version);
        LXxMETHOD(  LxResult,
PathCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
PathByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**path);
        LXxMETHOD(  LxResult,
PathNameByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**name);
        LXxMETHOD(  LxResult,
ImportPathCount) (
        LXtObjectID		  self,
        int			 *index);

        LXxMETHOD(  LxResult,
ImportPathByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**path);
        LXxMETHOD(  LxResult,
IsApp64Bit) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
DoWhenUserIsIdle) (
        LXtObjectID		  self,
        LXtObjectID		  visitor,
        int			  flags);
        LXxMETHOD(  LxResult,
CancelDoWhenUserIsIdle) (
        LXtObjectID		  self,
        LXtObjectID		  visitor,
        int			  flags);
        LXxMETHOD(  LxResult,
IsUserIdle) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
IsAppActive) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
SessionStage) (
        LXtObjectID		  self,
        int			 *stage);
        LXxMETHOD(  LxResult,
AppUsername) (
        LXtObjectID		  self,
        const char		**name);
        LXxMETHOD(  LxResult,
TimerStart) (
        LXtObjectID		  self,
        LXtObjectID		  visitor,
        int			  milliseconds,
        int			  idleFlags);
        LXxMETHOD(  LxResult,
TimerCancel) (
        LXtObjectID		  self,
        LXtObjectID		  visitor,
        int			  idleFlags);
        LXxMETHOD(  LxResult,
IsSafeMode) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
AppVersionMinor) (
        LXtObjectID		 self,
        int			*version);
        
        LXxMETHOD(  LxResult,
AppVersionSP) (
        LXtObjectID		 self,
        int			*version);

        LXxMETHOD(  LxResult,
AppVersionMajor) (
        LXtObjectID		 self,
        int			*version);
        
} ILxPlatformService;

/*
 * This is called with true when the app becomes active, and false when it becomes
 * inactive.  User idle actions can be armed from this method to execute commands as
 * needed.
 */
typedef struct vt_ILxAppActiveListener {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
IsNowActive) (
        LXtObjectID		  self,
        int			  isActive);
} ILxAppActiveListener;

/*
 * 
 * - NOPROMPT
 * The user-provided or default prompt is used, and the server does not define
 * its own.
 * - NORESULT
 * Determines if the "ok" text is output in headless mode after successfully
 * executing a line.
 * 
 * - NOCOOKING
 * Dunno.
 * 
 * - NOUNDOS
 * The server does not create undos, and will not appear in the Command Histroy's
 * unod list or history.  This used for the special-case of the built-in command
 * line interpreter, since commands implicitly have undos and are directly handled
 * by the undo systme.  It is extremely dangerous to perform undos (intentionally
 * or not) with this flag set.
 * 
 * 
 * Get the prompt string. CURRENT returns the active prompt based on the state
 * of the interpreter. ALTERNATE gives the other possible prompt, if any.
 * 
 * 
 * Execute a line. The flags are used for executing commands, and the execution
 * object receives the results. Errors can be returned as the return value or
 * through the message object, although return values take precedence. The special
 * value LINEISCOMMENT can also be returned.
 */
typedef struct vt_ILxLineInterpreter {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Prompt) (
        LXtObjectID		 self,
        const char	       **prompt,
        unsigned		 type);
        LXxMETHOD(  LxResult,
Execute) (
        LXtObjectID		 self,
        const char		*line,
        int			 execFlags,
        LXtObjectID		 execution);
} ILxLineInterpreter;

/*
 * All of these methods are optional and hold the results of ececuting the
 * interpreted line.
 * - CookedLine
 * the line string echoed back after processing. For the command interpreter
 * this includes normalizing arguments.
 * - Message
 * a Message object holding the result code and success/failure statement.
 * 
 * - Results
 * a ValueArray object holding a list of query results.
 * 
 * - ResultHints
 * hints for decoding integer results into strings.
 * 
 * - Info
 * text lines to report status back to the user. This may be called multiple
 * times.
 * 
 */
typedef struct vt_ILxLineExecution {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
CookedLine) (
        LXtObjectID		 self,
        const char		*text);

        LXxMETHOD(  LxResult,
Message) (
        LXtObjectID		 self,
        LXtObjectID		 message);

        LXxMETHOD(  LxResult,
Results) (
        LXtObjectID		 self,
        LXtObjectID		 valArray);

        LXxMETHOD(  LxResult,
ResultHints) (
        LXtObjectID		 self,
        const LXtTextValueHint	*hints);

        LXxMETHOD(  LxResult,
Info) (
        LXtObjectID		 self,
        const char		*text);
} ILxLineExecution;

typedef struct vt_ILxScriptLineEvent {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Index) (
        LXtObjectID		 self,
        unsigned int		*index);

        LXxMETHOD(  LxResult,
Script) (
        LXtObjectID		 self,
        void		       **ppvObj);
} ILxScriptLineEvent;


        #define LXe_SCRIPT_UNKNOWN		LXxFAILCODE( LXeSYS_SCRIPT,   1)
        #define LXe_SCRIPT_ERROR		LXxFAILCODE( LXeSYS_SCRIPT,   2)
        #define LXe_SCRIPT_OPAQUE		LXxFAILCODE( LXeSYS_SCRIPT,   3)
        #define LXe_SCRIPT_READONLY		LXxFAILCODE( LXeSYS_SCRIPT,   4)
        #define LXe_SCRIPT_ALREADY_EXISTS	LXxFAILCODE( LXeSYS_SCRIPT,   5)
        #define LXe_SCRIPT_NOT_ENOUGH_ARGS	LXxFAILCODE( LXeSYS_SCRIPT,   6)
        #define LXe_SCRIPT_TOO_MANY_ARGS	LXxFAILCODE( LXeSYS_SCRIPT,   7)
        #define LXe_SCRIPT_RECOGNIZED_INVALID	LXxFAILCODE( LXeSYS_SCRIPT,   8)

        #define LXe_SCRIPT_LINEISCOMMENT	LXxGOODCODE( LXeSYS_SCRIPT,   1)
        #define LXe_SCRIPT_WARNING		LXxGOODCODE( LXeSYS_SCRIPT,   8)

/*
 * We also define a script subsystem that script clients can use for their messages
 */

        #define LXsLOG_SCRIPTSYS	 "scripts"

/*
 * The script system service provides a list of available script managers, rather than
 * having clients browse the plug-in database themselves.  Managers are sorted by
 * their internal name (i.e., the name of the plug-in itself), which can also be obtained.
 * Managers must be released when no longer needed.  The objects returned by ByIndex(),
 * NameByIndex() and Lookup() must be released by the caller.
 */

        #define LXu_SCRIPTSYSSERVICE	"5046C663-7990-44d5-84CB-A859101B1C59"
        #define LXa_SCRIPTSYSSERVICE	"scriptsysservice"
        // [python] ILxScriptSysService:ByIndex			obj ScriptManager
        // [python] ILxScriptSysService:Lookup			obj ScriptManager
        // [python] ILxScriptSysService:UserValueByIndex	obj UserValue
        // [python] ILxScriptSysService:UserValueLookup		obj UserValue
        // [python] ILxScriptSysService:KitByIndex		obj Kit
        // [python] ILxScriptSysService:KitLookup		obj Kit

/*
 * This interface provides read-only information about a user value.  The type,
 * type name and value are available from the ILxScriptSysService::UserValues().
 * If the user value has been deleted, all of these methods will fail.
 */

        #define LXu_USERVALUE		"d7fb1eb0-47fe-4dc2-a64f-c8a35a86c51e"
        // [local] ILxUserValue
        // [python] ILxUserValue:IsTransient			bool
        // [python] ILxUserValue:DeferAction			bool
        // [python] ILxUserValue:AsUI				bool
        // [python] ILxUserValue:InvertEnableCommandTest	bool

/*
 * This returns the lifespan of the user value.
 */

        #define LXiUSERVALUELIFE_CONFIG		0
        #define LXiUSERVALUELIFE_TEMPORARY	1
        #define LXiUSERVALUELIFE_MOMENTARY	2

        #define LXiUSERVALUELIFE_COUNT		3	// Not an option

/*
 * 12.2 adds support for pure UI commands that are not undoable.  AsUI() will only
 * return true if the user values is undoable UI, and false if it's undoable model.
 * With this new functionality, it will also return true for pure UI user values.
 * This method returns which of the three states the user values is defined.
 */

        #define LXiUSERVALUE_UIMODE_UNDO_MODEL		0
        #define LXiUSERVALUE_UIMODE_UNDO_UI		1
        #define LXiUSERVALUE_UIMODE_PURE_UI		2

/*
 * This interface provides access to basic properties about a kit.
 */

        #define LXu_KIT		"6A961CA0-6174-4E65-BB13-AC199DD10471"
        #define LXa_KIT		"kit"
        // [local] ILxKit
        // [python] ILxKit:IsEnabled	bool
        // [python] ILxKit:IsVisible	bool

/*
 * The session listener provides information about application startup and shutdown.
 * A "session" is defined as the time the app is running, from when it starts to
 * when it exits.
 */

        #define LXu_SESSIONLISTENER	"b5cb3afe-3f0c-4498-b530-1726811b1401"
        #define LXa_SESSIONLISTENER	"sessionlistener"
        // [local]  ILxSessionListener
        // [export] ILxSessionListener			sesl
        // [python] ILxSessionListener:CheckQuitUI	bool

/*
 * The user value listener alerts clients when a user value has changed.  It also
 * has methods that are called at various points in the startup sequence so that
 * user values can be cached after startup or actions can be taken during the
 * startup process.
 */

        #define LXu_USERVALUELISTENER	"13a85a48-06aa-4a75-9e73-066ee3cb761f"
        // [local]  ILxUserValueListener
        // [export] ILxUserValueListener	uvl

/*
 * The script manager is provided as a global.  It is used to obtain information about
 * a particular scripting subsystem.  Each type of script has a matching script manager,
 * although one manager can handle multiple script types. As well as providing a list of
 * available scripts known to the manager, they also include the interpreter used to
 * execute said scripts.
 */

        #define LXu_SCRIPTMANAGER	"3699E7C5-44B8-4e07-B8CA-E26899CD7B3B"
        #define LXa_SCRIPTMANAGER	"scriptservice"
        //[local]  ILxScriptManager
        //[export] ILxScriptManager scman

/*
 * Script managers can return a number of flags describing how the manager operates.
 */

        #define LXfSCRIPTSRV_CREATE		0x0001
        #define LXfSCRIPTSRV_REMOVE		0x0002
        #define LXfSCRIPTSRV_LINE_ACTION	0x0003

/*
 * Many scripts simply involve parsing text files and interpreting the lines in turn.
 * Rather than forcing the creating of a completely new manager each time, a simple
 * text script interpreter can be created.
 * The script system automatically handles loading of text files from disc, and provides
 * search paths for scripts and so on.  All the interpreter needs to do is confirm that
 * it actually can deal with this kind of script and execute it.
 */

        #define LXu_TEXTSCRIPTINTERPRETER	"D612FFCE-4B94-4823-A0A7-CC7CA2DDC3D6"
        #define LXa_TEXTSCRIPTINTERPRETER	"textscriptinterpreter"
        // [export]  ILxTextScriptInterpreter tsi
        // [local]   ILxTextScriptInterpreter
        // [python]  ILxTextScriptInterpreter:Validate	bool
        // [default] ILxTextScriptInterpreter:Validate = LXe_OK
        // [python]  ILxTextScriptInterpreter:ValidateFileType	bool

/*
 * Scripts provide an ILxScript interface.  This allows clients to browse the contents
 * of a script for display to the user, for example.  For example, the attribute editor
 * displays script contents
 */

        #define LXu_SCRIPT		"33C03F3F-A692-4bf4-8AB4-C5A95CA7930C"
        #define LXa_SCRIPT		"script"
        // [export] ILxScript
        // [local]  ILxScript
        // [python] ILxScript:Manager	obj Unknown

/*
 * The platform service provides information about the application and OS.
 */

        #define LXu_PLATFORMSERVICE	"B9596D64-8CB3-4943-8415-7EDF527AE513"
        #define LXa_PLATFORMSERVICE	"platformservice"
        // [python]  ILxPlatformService:IsApp64Bit	bool
        // [python]  ILxPlatformService:IsAppActive	bool
        // [python]  ILxPlatformService:IsHeadless	bool
        // [python]  ILxPlatformService:IsUserIdle	bool
        // [python]  ILxPlatformService:IsSafeMode	bool

/*
 * Get the OS type, OS name and OS version string.
 */

    #define LXiOSTYPE_UNKNOWN   0
        #define	LXiOSTYPE_WIN32		1
        #define	LXiOSTYPE_MACOSX	2
    #define	LXiOSTYPE_LINUX		3

/*
 * There are cases where plug-ins have out-of-band actions they need to execute from
 * the main thread when it is safe to do so.  An example might be modo's own telnet
 * service, which can receive commands at any time but can only execute them when it
 * is safe to do so, a time that we refer to as "user idle".
 * This method can be used to perform an action a visitor when the user is idle.  It
 * is always performed from the main thread.
 * There are a number of criteria that can be used to define "idle".  You can set
 * whatever combination of flags you want, except for ALWAYS, which is a special case
 * that is executed immediately.
 * 
 * Generally speaking, you'll want to use ALL_IDLE, combined with APP_MUST_BE_ACTIVE when
 * applicable and just leave it at that.  It should be rare to need to remove specific flags.
 * 
 * - ALWAYS
 * A special-case value; if passed, the user idle action is executed as soon as possible.
 * This is rarely used, as it does not make sure it is safe to perform such an action --
 * the user may be in the middle of a file dialog or rendering or something like that.
 * Extreme care should be taken when using his functionality.
 * 
 * - APP_MUST_BE_ACTIVE
 * The application must be active, meaning that it currently has the focus in the OS.
 * 
 * - KEYS_UP
 * No keys on the keyboard can be pressed.
 * 
 * - MODIFIER_KEYS_UP
 * No keys defined as modifiers can be pressed.
 * 
 * - NO_DIALOGS_OPEN
 * All dialogs (system dialogs, modal dialogs, etc) must be closed.
 * 
 * - CMD_STACK_EMPTY
 * No commands can be currently be executing.
 * 
 * - NO_SUB_INPUT_LOOP
 * Somewhat escoteric, this ensures that we're in the main application input loop.
 * In some cases there are secondary input loops used for special things, like modal
 * dialogs.
 * 
 * - EDIT_FIELDS_UNFOCUSED
 * No edit fields have focus.
 * 
 * - ALL_IDLE
 * This mask is what is usually set, and contains all of the above flags except for
 * APP_MUST_BE_ACTIVE.
 * 
 * NOTE:  These defines MUST match the USERIDLEf_ defines in awin.
 * 
 */

        #define			 LXiUSERIDLE_ALWAYS			0x0000

        #define			 LXfUSERIDLE_APP_MUST_BE_ACTIVE		0x1000

        #define			 LXfUSERIDLE_MOUSE_BUTTONS_UP		0x0001	// All mouse buttons must be up
        #define			 LXfUSERIDLE_KEYS_UP			0x0002	// All non-modifier keys must be up
        #define			 LXfUSERIDLE_MODIFIER_KEYS_UP		0x0004	// All modifier keys must be up
        #define			 LXfUSERIDLE_NO_DIALOGS_OPEN		0x0008	// No modal windows may be open, including system dialogs
        #define			 LXfUSERIDLE_NO_POPS_OPEN		0x0010	// No popups/popovers may be open (except for tooltips)
        #define			 LXfUSERIDLE_CMD_STACK_EMPTY		0x0020	// The command stack must be empty
        #define			 LXfUSERIDLE_NO_SUB_INPUT_LOOP		0x0040	// Cannot be in a secondary input loop; meaning, we must be in the root-level input loop or no input loop at all
        #define			 LXfUSERIDLE_EDIT_FIELDS_UNFOCUSED	0x0080	// Edit field cannot have focus
        #define			 LXfUSERIDLE_SCENE_STABLE		0x0100	// Scene must not be in flux (i.e. safe to perform evaluations)

        #define			 USERIDLEf_ALL_IDLE			0x0FFF	// Everything except APP_MUST_BE_ACTIVE

/*
 * The stage can be one of the following:
 */

        #define LXfSESSIONSTAGE_STARTUP			0x10000000
        #define LXfSESSIONSTAGE_READY			0x20000000
        #define LXfSESSIONSTAGE_SHUTDOWN		0x30000000

        #define LXiSESSIONSTAGE_NOT_READY		0
        #define LXiSESSIONSTAGE_STARTUP_COMMANDS	(LXfSESSIONSTAGE_STARTUP  | 0)
        #define LXiSESSIONSTAGE_SYSTEM_READY		(LXfSESSIONSTAGE_READY    | 0)
        #define LXiSESSIONSTAGE_SHUTTING_DOWN		(LXfSESSIONSTAGE_SHUTDOWN | 0)

/*
 * Clients can be notified when the application gets or loses focus by listening to
 * the ILxAppActiveListener port.  A common use of this is to check to see if any files
 * have changed since the user last left the app, or to pause some networking or other
 * interprocess communication until the app gains/loses focus again.
 */

        #define LXu_APPACTIVELISTENER	"7c35c2c0-8116-43f7-8277-dd521d1bd6a8"
        #define LXa_APPACTIVELISTENER	"appactivelistener"
        // [local]  ILxAppActiveListener
        // [export] ILxAppActiveListener activeEvent

/*
 * A line interpreter is a persistent server that interprets lines of text
 * as interactive commands. The simplest (built-in) interpreter is one that
 * treats each line of input as a command or query and generates output.
 * More complex interpreters could process input using a scripting language.
 */

        #define LXu_LINEINTERPRETER	"8F7DF2BE-69A2-4E1C-A4E9-CB3BC3D534D5"
        #define LXa_LINEINTERPRETER	"lineinterpreter"
        // [export] ILxLineInterpreter
        // [local]  ILxLineInterpreter


        #define LXfLINT_NOPROMPT		0x01
        #define LXfLINT_NORESULT		0x02
        #define LXfLINT_NOCOOKING		0x04
        #define LXfLINT_NOUNDOS			0x08


        #define LXiLINT_CURRENT		 0
        #define LXiLINT_ALTERNATE	 1

/*
 * The execution object is just a way for the interpreter to pass results
 * back to the caller.
 */

        #define LXu_LINEEXECUTION	"16947735-3797-444C-A907-DADD8165F4FB"
        // [export] ILxLineExecution
        // [local]  ILxLineExecution

/*
 * This interface provides the line number edited and the script it was edited in.
 */

        #define LXu_SCRIPTLINEEVENT	"DABF6619-A4B5-4919-8389-8C54B39422E4"
        #define LXa_SCRIPTLINEEVENT	"scriptlineevent"
        // [export] ILxScriptLineEvent slev
        // [local]  ILxScriptLineEvent
        // [python] ILxScriptLineEvent:Script	obj Script

#endif
