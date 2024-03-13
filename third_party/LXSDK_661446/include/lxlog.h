/*
 * LX log module
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
#ifndef LX_log_H
#define LX_log_H

typedef struct vt_ILxLogService ** ILxLogServiceID;
typedef struct vt_ILxLogInfoBlock ** ILxLogInfoBlockID;
typedef struct vt_ILxLog ** ILxLogID;
typedef struct vt_ILxLogEntry ** ILxLogEntryID;
typedef struct vt_ILxLogListener ** ILxLogListenerID;

#include <lxcom.h>
#include <lxvmath.h>
        #ifdef long
         
          #include <stdio.h>
          #include <stdarg.h>
          #include <time.h>
         
        #else
          #include <stdio.h>
          #include <stdarg.h>
          #include <time.h>
        #endif

        // Suppress warnings for deprecated functions.

        #ifdef _MSC_VER
                #define _CRT_SECURE_NO_WARNINGS 1
                #define _CRT_SECURE_NO_DEPRECATE 1
                #pragma warning(disable: 4996)
        #endif



/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.
 * 
 * The list of subsystems can be walked with these functions.  As of 901, an
 * entry can only belong to one subsystem, or zero if it hasn't been added to
 * any yet.
 * 
 * 
 * This looks up a subsystem by name or, if NULL, by ID.
 * 
 * 
 * Like subsystems, the list of info blocks can be walked and looked up by name.
 * 
 * 
 * This looks up a subsystem by name.
 * 
 * These helpers check to see if two field names are in the same group (i.e., have
 * the same name up to the first period), and return the names of the group and
 * sub.
 * The group test returns LXe_TRUE if the two field names are in the same group
 * and LXe_FALSE if not.  Any other code is an error.
 * 
 * 
 * This returns the group and/or sub parts of the field name.  Either can be NULL
 * if you only want the one.  Note that *sub may be NULL if there is no sub.  Also
 * note that this function is NOT thread safe, and that the strings returned are
 * only good until the next call to this function.
 * 
 * Debug messages are used only for internal purposes, and follow the same visibility rules
 * as DBprintf(), as well as being output to the console through DBprintf() when added.
 * 
 * Info blocks can be used to provide formatted messages.  The first step is to get
 * a new ILxLogEntryID with this method.  The block arguments are the name of a
 * previously registered info block.  Once created, the ILxLogEntryID can be filled
 * in with the the appropriate methods.
 * 
 * A second way to add complex formatted messages is through name/value pairs.  The
 * returned ILxLogEntryID will need to be populated with the appropriate methods.
 * 
 * There are times when high-level operations trigger low-level operations
 * that may take a while. In that case we should have a monitor, but there is
 * no way to pass the monitor down from the UI command to the actual code that
 * needs it. The log service allows us to prepare a monitor and deliver it to
 * a lower-level function.
 * This method sets the global monitor. If called with null the monitor is
 * cleared.
 * 
 * 
 * This method can be used by any low-level client to acquire the global
 * monitor for use. The acquire method returns a "peek" of the global monitor,
 * so it is not add-refed, and the method may return null if there is none or
 * it has already been acquired previously.
 * 
 * Logging can be enabled and disabled on a per-subsystem basis.  When disabled,
 * logged events will still go to that subsystem, but they will not show up in the
 * master log or the console output.  This does not affect rolling log entries.
 * 
 * This returns LXe_TRUE if loggin is enabled for a system, and LXe_FALSE if it
 * is disabled.
 * 
 * This allows yout create a new entry from an ILxMessageID.  The message itself
 * and the type code are read from the ILxMessageID
 * 
 * This function lets plug-ins dump data to the normal debug log. The level indicates
 * the severity of the information, allowing debug trace output to be hidden during
 * normal usage.
 * 
 * 
 * The exception message is a single, global message object that holds a description
 * of the cause of an unexpected failure. This can be set at the site of an initial
 * error with a description of the cause of the error, and it will be displayed to the
 * user by the controlling code higher up the stack.
 * ExceptionMessage() grabs the exception message for this caller and returns it to
 * allow it to be changed. Flags control the action to perform. Even if this exception
 * isn't the primary one it still gets captured for informational purposes. Since an
 * exception mechanism that itself generates errors would be weird, this function will
 * return null on errors which the client should check and do nothing.
 * 
 * 
 * Exception messages are handled by a client system high enough to be able to display
 * an error message, but general enough that any type of exception might be possible.
 * The start method assures that past exceptions have been handled and clears the state.
 * The collect method reads out any exception message. This generally only needs to be
 * called when an error has happened, and if there is no error it will return NOTFOUND.
 * 
 * 
 * This low-level utility provides a way to change the string and type code associated
 * with a message-class log entry.  This is rarely used, but can be useful when you need
 * to add some summary information to a parent entry.  This only works on log entries
 * created with CreateEntryMessage().
 */
typedef struct vt_ILxLogService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
SubSystemCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
SubSystemByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
SubSystemLookup) (
        LXtObjectID		 self,
        const char		*name,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
MasterSubSystem) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
InfoBlockCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
InfoBlockByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
InfoBlockLookup) (
        LXtObjectID		 self,
        const char		*name,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
InfoBlockFieldsAreSameGroup) (
        LXtObjectID		 self,
        const char		*name1,
        const char		*name2);
        LXxMETHOD(  LxResult,
InfoBlockFieldGetParts) (
        LXtObjectID		  self,
        const char		 *name,
        const char		**group,
        const char		**sub);
        LXxMETHOD(  LxResult,
CreateEntryMessage) (
        LXtObjectID		 self,
        LxResult		 type,
        const char		*message,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
CreateEntryInfoBlock) (
        LXtObjectID		 self,
        LxResult		 type,
        const char		*blockName,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
CreateEntryPaired) (
        LXtObjectID		 self,
        LxResult		 type,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
SetMonitor) (
        LXtObjectID		 self,
        LXtObjectID		 monitor);
        LXxMETHOD(  LXtObjectID,
AcquireMonitor) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
EnableLogging) (
        LXtObjectID		 self,
        const char		*systemName,
        unsigned int		 state);
        LXxMETHOD(  LxResult,
IsLoggingEnabled) (
        LXtObjectID		 self,
        const char		*systemName);
        LXxMETHOD(  LxResult,
CreateEntryMessageFromMsgObj) (
        LXtObjectID		 self,
        LXtObjectID		 msgObj,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
DebugLogOutput) (
        LXtObjectID		 self,
        unsigned int		 level,
        const char		*line);
        LXxMETHOD(  LxResult,
DebugLogOutputSys) (
        LXtObjectID		 self,
        unsigned int		 level,
        const char		*logSystem,
        const char		*line);
        LXxMETHOD(  LXtObjectID,
ExceptionMessage) (
        LXtObjectID		 self,
        LxResult		 error,
        unsigned		 flags);
        LXxMETHOD(  LxResult,
ExceptionBlockStart) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
ExceptionBlockCollect) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ReplaceEntryMessage) (
        LXtObjectID		 self,
        LXtObjectID		 logEntry,
        LxResult		 type,
        const char		*msg);
} ILxLogService;

/*
 * These return the name of the block.
 * 
 * This walks the list of fields, returning the total count and the
 * name and datatype of each field.  Note that FieldName() is NOT
 * thread safe, and the returned string is only valid until the next
 * call to this method.
 */
typedef struct vt_ILxLogInfoBlock {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        const char 		**name);
        LXxMETHOD(  LxResult,
FieldCount) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD(  LxResult,
FieldName) (
        LXtObjectID		  self,
        unsigned int		  index,
        const char 		**name);

        LXxMETHOD(  LxResult,
FieldType) (
        LXtObjectID		  self,
        unsigned int		  index,
        const char 		**type);
} ILxLogInfoBlock;

/*
 * This adds an entry to a subsystem.  Old entries will be dropped if needed.  This
 * does an AddRef() on the object, meaning you'll still need to do your own release
 * on it after it has been added.
 * It is also possible to create rolling messages.  For example, it is not
 * useful to log all of the Box Tool Info messages as described above; you
 * really only want to see the current state of the Box Info Tool at any
 * given time.  A rolling message can be used to accomplish this.  Another
 * example is a context-sensitive status bar that provides specific
 * information based on what the mouse is hovering over.
 * This changes the rolling message.  A separate rolling message is stored
 * for each subsystem, with the one most recently changed being used as the
 * master message.
 * 
 * 
 * The rolling message can also be cleared when it is no longer needed.
 * 
 * Logged events specific to a particular subsystem can be scanned with
 * these methods.
 * 
 * 
 * If you don't want to or can't release an entry, you can "peek" at
 * the entry with this method.  These entries should be considered
 * volatile and should not be held onto for very long unless you
 * AddRef them yourself.
 * 
 * The most recently added entry can be fetched with this function.  This
 * may be NULL if there is no recent entry.
 * 
 * The maximum number of entries that a particular subsystem can store can
 * be set and read with these functions.
 * 
 * 
 * The current rolling message can also be read.  This returns LXe_NOTFOUND if
 * there is currently no rolling entry.
 * 
 * This clears all entries from the subsystem.  If called on the master subsystem,
 * all subsystems are cleared.
 * 
 * The name of a subsystem can be returned at any time.
 */
typedef struct vt_ILxLog {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddEntry) (
        LXtObjectID		 self,
        LXtObjectID		 entry);
        LXxMETHOD(  LxResult,
RollEntry) (
        LXtObjectID		 self,
        LXtObjectID		 entry);
        LXxMETHOD(  LxResult,
RollClear) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
EntryCount) (
        LXtObjectID		 self,
        unsigned int		*count );
        LXxMETHOD(  LxResult,
EntryByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj );
        LXxMETHOD(  LXtObjectID,
PeekEntryByIndex) (
        LXtObjectID		 self,
        unsigned int		 index );
        LXxMETHOD(  LxResult,
GetCurrentEntry) (
        LXtObjectID		 self,
        void		       **ppvObj );
        LXxMETHOD(  LxResult,
SetMaxEntries) (
        LXtObjectID		 self,
        unsigned int		 max );
        LXxMETHOD(  LxResult,
GetMaxEntries) (
        LXtObjectID		 self,
        unsigned int		*max );
        LXxMETHOD(  LxResult,
GetRolling) (
        LXtObjectID		 self,
        void		       **ppvObj );
        LXxMETHOD(  LxResult,
ClearAll) (
        LXtObjectID		 self );
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        const char		**name );
} ILxLog;

/*
 * Log entries can have child entries.  A common child event is simply another message
 * that provides more detail for the first, such as why an event failed.  Normally the
 * root event is a warning or error, with one or more child messages describing exactly
 * why this occured.  Info messages may also have children, providing more details on
 * what might be an otherwise simple statement.
 * Note that this only applies to simple messages, and not to complex data such as
 * info blocks and name/value pairs.
 * This does an AddRef() on the object, meaning you'll still need to do your own release
 * on it after it has been added.
 * A log entry can have multiple parents, and will thus appear as a child of each parent.
 * Care should be taken to avoid loops.
 * 
 * 
 * This sets a title that can appear at the top of the block, which in this case is
 * "Box (Squared)".
 * 
 * This sets a description, which here is the three lines of text at the bottom of
 * the block.
 * 
 * This sets the value of one of the fields in the info block.  The specific field
 * can be specified by either it's name or it's index, if the name is NULL.  A
 * matching ILxValueID must be provided for the field.
 * 
 * SetDesc() can again be used to add a description after the pairs.
 * This function can be used to add a pair of strings to the message.
 * 
 * 
 * 
 * The type can be returned as an LxResult code.
 * 
 * The time at which the entry was logged can be read either as a C-style
 * time_t or as a string via asctime().
 * 
 * 
 * The list of child entries for MESSAGE class entries can be enumerated with
 * these methods.
 * 
 * 
 * A peek method is also available.
 * 
 * Each root-level entry knows what subsystems it has been added to.
 * 
 * 
 * The message stored in a MESSAGE-type log entry can be read out with
 * this function.  This fails if used on a non-MESSAGE type.
 * 
 * The title and description stored in a block-type log entry can
 * be read out with these functions.  These fail if used on a
 * MESSAGE entry.  Desc() can also be used on pairs, but not on
 * MESSAGEs.
 * 
 * 
 * This returns the info block definition.
 * 
 * The ILxValueID for a particular field in the block can be extracted with this
 * method.  The value should be freed by the client when no longer needed.  The
 * field can be referenced by index or by name.
 * 
 * These mehtods return the number of pairs, and the name and value strings by index.
 * 
 * 
 */
typedef struct vt_ILxLogEntry {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddEntry) (
        LXtObjectID		 self,
        LXtObjectID		 entry);
        LXxMETHOD(  LxResult,
SetTitle) (
        LXtObjectID		 self,
        const char		*title );
        LXxMETHOD(  LxResult,
SetDesc) (
        LXtObjectID		 self,
        const char		*desc );
        LXxMETHOD(  LxResult,
SetValue) (
        LXtObjectID		 self,
        const char		*name,
        unsigned int		 index,
        LXtObjectID		 value );
        LXxMETHOD(  LxResult,
AddPair) (
        LXtObjectID		 self,
        const char		*name,
        const char		*value );
        LXxMETHOD(  LxResult,
Class) (
        LXtObjectID		 self,
        unsigned int		*classType );
        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		 self,
        LxResult		*type );
        LXxMETHOD(  LxResult,
Time) (
        LXtObjectID		 self,
        time_t			*time );
        LXxMETHOD(  LxResult,
TimeString) (
        LXtObjectID		  self,
        const char		**string );
        LXxMETHOD(  LxResult,
ChildCount) (
        LXtObjectID		 self,
        unsigned int		*count );
        LXxMETHOD(  LxResult,
ChildByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj );
        LXxMETHOD(  LXtObjectID,
PeekChildByIndex) (
        LXtObjectID		 self,
        unsigned int		 index );
        LXxMETHOD(  LxResult,
SubSystemCount) (
        LXtObjectID		 self,
        unsigned int		*count );
        LXxMETHOD(  LxResult,
SubSystemByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj );
        LXxMETHOD(  LxResult,
Message) (
        LXtObjectID		  self,
        const char		**message );
        LXxMETHOD(  LxResult,
Title) (
        LXtObjectID		  self,
        const char		**title );
        LXxMETHOD(  LxResult,
Desc) (
        LXtObjectID		  self,
        const char		**desc );
        LXxMETHOD(  LxResult,
InfoBlock) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
InfoBlockValue) (
        LXtObjectID		 self,
        const char		*name,
        unsigned int		 index,
        void		       **ppvObj );
        LXxMETHOD(  LxResult,
PairCount) (
        LXtObjectID		  self,
        unsigned int		 *count );
        LXxMETHOD(  LxResult,
PairName) (
        LXtObjectID		  self,
        unsigned int		  index,
        const char		**name );
        LXxMETHOD(  LxResult,
PairValue) (
        LXtObjectID		  self,
        unsigned int		  index,
        const char		**value );
} ILxLogEntry;

/*
 * This is called when a new log subsystem (ILxLogID) has been added to the application.
 * 
 * Called when a new log entry is added to a subsystem.  Note that a single log
 * entry many belong to multiple subsystems.
 * 
 * Called when a new entry was added as a child of anohter log entry.  This is
 * only sent for root entries.
 * 
 * Called when an entry has been dropped from the log, usually because the number of
 * entries exceeds te maximum number allowed, and thus the oldest entry is removed.
 * 
 * Rolling log entries are much the same as normal logged entries.  Since rolling
 * logs only contain a single entry, RollingEntryAdded() implies RollingEntryDrop().
 * RollingEntryDrop() will still be called when the rolling log is cleared.
 */
typedef struct vt_ILxLogListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
SystemAdded) (
        LXtObjectID		 self,
        LXtObjectID		 system);
        LXxMETHOD( void,
EntryAdded) (
        LXtObjectID		 self,
        LXtObjectID		 system,
        LXtObjectID		 entry);
        LXxMETHOD( void,
ChildEntryAdded) (
        LXtObjectID		 self,
        LXtObjectID		 entry,
        LXtObjectID		 parentEntry);
        LXxMETHOD( void,
EntryDropped) (
        LXtObjectID		 self,
        LXtObjectID		 system,
        LXtObjectID		 entry);
        LXxMETHOD( void,
RollingEntryAdded) (
        LXtObjectID		 self,
        LXtObjectID		 system,
        LXtObjectID		 entry);

        LXxMETHOD( void,
RollingChildEntryAdded) (
        LXtObjectID		 self,
        LXtObjectID		 entry,
        LXtObjectID		 parentEntry);

        LXxMETHOD( void,
RollingEntryDropped) (
        LXtObjectID		 self,
        LXtObjectID		 system,
        LXtObjectID		 entry);
} ILxLogListener;

/*
 * The log service allows subsystems to be registered and walked.
 */

        #define LXu_LOGSERVICE	"0BC355C2-5E6B-49EF-B368-600D9F26F543"
        #define LXa_LOGSERVICE	"logservice"

        // [python] ILxLogService:CreateEntryInfoBlock	obj LogEntry
        // [python] ILxLogService:CreateEntryMessage	obj LogEntry
        // [python] ILxLogService:CreateEntryMessageFromMsgObj	obj LogEntry
        // [python] ILxLogService:CreateEntryPaired	obj LogEntry
        // [python] ILxLogService:InfoBlockByIndex	obj LogInfoBlock
        // [python] ILxLogService:InfoBlockLookup	obj LogInfoBlock
        // [python] ILxLogService:MasterSubSystem	obj Log
        // [python] ILxLogService:SubSystemByIndex	obj Log
        // [python] ILxLogService:SubSystemLookup	obj Log
        // [python] ILxLogService:ExceptionBlockCollect	obj Message
        // [python] ILxLogService:InfoBlockFieldsAreSameGroup	bool
        // [python] ILxLogService:IsLoggingEnabled	bool

/*
 * Any client can choose to log events with the log manager.  Each client should
 * register one subsystem name for each set of logged entry types it wants to have.
 * You can register as many subsystems as you like, using each for different
 * types of logging events.  Any client can use any defined subsystem.  Each
 * registration is defined as an ILxLogID.
 * The log system itself registers its own subsystem.
 */

        #define LXsLOG_LOGSYS	 "logsys"

/*
 * Subsystems are registered automatically simply by adding a tag to any server.
 */

        #define LXsSRV_LOGSUBSYSTEM	"server.logsubsystem"

/*
 * There is also a special master subsystem.  This is a combination of all logged entries,
 * plus the most recently logged rolling entry.  Entries cannot be directly added to this,
 * but the ones that are there can be read in the normal manner.
 */

        #define LXsLOG_MASTERSYS	 "master"

/*
 * Once registered, messages can be added to the log using simple strings. Each
 * message will be added to both the master log and to the subsystem's own internal
 * log.  These logs are stored as lists, with each new messages being added to the
 * end of the list, and with old entries purged as needed.  The type can be any
 * LxResult code.
 * LXe_INFO messages are relatively generic system states, such as a tooltip or confirmation
 * that an operation has completed.  LXe_WARNING and any LXx_FAIL() code designate non-fatal
 * and fatal messages respectively.  LXe_ABORT should be sent when an operation is aborted
 * through a user action.
 */

        #define LXe_LOG_DEBUG	LXxGOODCODE(LXeSYS_LOG,1)


        #define LXi_DBLOG_ERROR		 1
        #define LXi_DBLOG_NORMAL	 2
        #define LXi_DBLOG_TRACE		 3
        #define LXi_DBLOG_VERBOSE	 4

/*
 * - LOWLEVEL
 * Marks this as a low-level description that should be overridden by any later
 * (presumably more useful) description.
 * - OVERRIDE
 * Explicitly overriding any previous message.
 */

        #define LXfEXMSG_LOWLEVEL	 0x01
        #define LXfEXMSG_OVERRIDE	 0x02

/*
 * Registering an info block requires an ILxLogInfoBlock object.
 */

        #define LXu_LOGINFOBLOCK	"B9AEE11A-3501-4dc2-90A6-41F2435856C6"
        #define LXa_LOGINFOBLOCK	"loginfoblock"
        // [local]  ILxLogInfoBlock
        // [export] ILxLogInfoBlock lb

/*
 * A log subsystem manages it's individual entries.  These objects are owned by the
 * log system and should not be released by clients.
 */

        #define LXu_LOG		"1890538F-D64C-478c-8472-228B7C9AB1DF"
        #define LXa_LOG		"logsubsystem"
        // [local]  ILxLog

        // [python] ILxLog:EntryByIndex		obj LogEntry
        // [python] ILxLog:GetCurrentEntry	obj LogEntry
        // [python] ILxLog:GetRolling		obj LogEntry

/*
 * A log entry contains a timestamp, an LxResult code and a message string.  Log
 * entries are owned by the subsystem and should not be released by the client.
 */

        #define LXu_LOGENTRY	"E83679B2-DB4D-4D90-B81B-5F786D212FB3"
        #define LXa_LOGENTRY	"logentry"
        // [local]  ILxLogEntry

        // [python] ILxLogEntry:ChildByIndex		obj LogEntry
        // [python] ILxLogEntry:InfoBlock		obj LogInfoBlock
        // [python] ILxLogEntry:InfoBlockValue		obj Unknown
        // [python] ILxLogEntry:SubSystemByIndex	obj Unknown

/*
 * The various properties of an entry can be read with these functions.
 * The class of the entry wuill be one of the following, depending on how the
 * entry was created:
 */

        #define LXiLOGCLASS_MESSAGE	0
        #define LXiLOGCLASS_BLOCK	1
        #define LXiLOGCLASS_PAIRS	2

/*
 * The log listener can be used to listen for newly added log entries.
 */

        #define LXu_LOGLISTENER		"c5fd260b-cab7-4283-b876-2314144ae83a"
        // [local]  ILxLogListener
        // [export] ILxLogListener logEvent

#endif
