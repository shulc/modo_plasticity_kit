/*
 * LX stddialog module
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
#ifndef LX_stddialog_H
#define LX_stddialog_H

typedef struct vt_ILxAsyncMonitorInfo ** ILxAsyncMonitorInfoID;
typedef struct vt_ILxAsyncMonitorInfo1 ** ILxAsyncMonitorInfo1ID;
typedef struct vt_ILxAsyncMonitorSystem ** ILxAsyncMonitorSystemID;
typedef struct vt_ILxColorDialog ** ILxColorDialogID;
typedef struct vt_ILxStdDialogService ** ILxStdDialogServiceID;
typedef struct vt_ILxFileDialogClient ** ILxFileDialogClientID;

#include <lxserver.h>
#include <lxvalue.h>



/*
 * Get the system and title of the monitor.
 * Get the current progress of this single monitor, ignoring child monitors.
 * 
 * This is similar, but takes into account sub-monitors to provide an overall
 * progress value.
 * 
 * Get the parent and child of the monitor.  This fails with NOTAVAILABLE if
 * there is no parent or child.  These objects must be released when no longer
 * needed.
 * 
 * This returns a unique identifier string for the monitor, mostly to make
 * it easier to address from things like the Activity View commands.
 * 
 * Returns LXe_TRUE if the monitor can be aborted.  This is purely a UI
 * construct, and determiens if a root-level monitor should draw the abort
 * widget.  It is always false on sub-monitors, and Abort() can still be
 * called, in which case IsAborted() will return true.
 * 
 * Tell the monitor to abort.  This simply sets the abort flag, which is
 * returned by IsAborted() and ILxMonitor::Step().
 * 
 * This returns LXe_TRUE if aborted, and LXe_FALSE if it is still running.
 */
typedef struct vt_ILxAsyncMonitorInfo {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
System) (
        LXtObjectID		  self,
        const char		**system);

        LXxMETHOD(  LxResult,
Title) (
        LXtObjectID		  self,
        const char		**title);
        LXxMETHOD(  LxResult,
Progress) (
        LXtObjectID		  self,
        double			 *progress);
        LXxMETHOD(  LxResult,
OverallProgress) (
        LXtObjectID		  self,
        double			 *progress);
        LXxMETHOD(  LxResult,
Parent) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
Child) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Identifier) (
        LXtObjectID		  self,
        const char		**ident);
        LXxMETHOD(  LxResult,
CanAbort) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
Abort) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
IsAborted) (
        LXtObjectID		  self);
} ILxAsyncMonitorInfo;

typedef struct vt_ILxAsyncMonitorInfo1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
System) (
        LXtObjectID		  self,
        const char		**system);

        LXxMETHOD(  LxResult,
Title) (
        LXtObjectID		  self,
        const char		**title);

        LXxMETHOD(  LxResult,
Progress) (
        LXtObjectID		  self,
        double			 *progress);

        LXxMETHOD(  LxResult,
OverallProgress) (
        LXtObjectID		  self,
        double			 *progress);

        LXxMETHOD(  LxResult,
Parent) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
Child) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
Identifier) (
        LXtObjectID		  self,
        const char		**ident);

        LXxMETHOD(  LxResult,
Abort) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
IsAborted) (
        LXtObjectID		  self);
} ILxAsyncMonitorInfo1;

/*
 * Get the name of the system.
 * Walk the list of monitors in the system.
 */
typedef struct vt_ILxAsyncMonitorSystem {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        const char		**name);
        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);
} ILxAsyncMonitorSystem;

/*
 * DoDialog is responsible for opening a color dialog.  All dialog handling is up
 * to the server.  This includes whatever methods it chooses to create and display
 * the dialog, handling windowing and event loops, etc.
 * The rgb[] argument is initialized to the original color, and is also used to
 * return any color the user may have chosen.  This color may be HDR (i.e., outside
 * the range of 0-1).  The title string is a pre-translated string to be displayed
 * in the dialog's title bar.  The method should return an LXe_OK() code if the
 * user choose a color, an LXe_FAIL() code on an error, or LXe_ABORT if the user
 * canceled the dialog.
 * The current stops are also provided for displaying HDR colors, and are applied
 * by multiplying or dividing by two to the power of the stops (i.e., pow(2,stops))
 * to convert between HDR and LDR.  Stops should always be applied before gamma.
 * 
 * The gamma value is used to gamma correct the colors shown in the color dialog
 * to match those in modo.  This may be 1.0 if no correction should be applied.
 * Gamma can be applied by raising a color's RGB values to the gamma value (i.e.,
 * pow(rgb[x],gamma)).  Gamma should always be applied after stops.
 * 
 * The returned RGB value should not be gamma corrected, but can be HDR.
 * 
 */
typedef struct vt_ILxColorDialog {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
DoDialog) (
        LXtObjectID		  self,
        const char		 *title,
        double			  stops,
        double			  gamma,
        double			 *rgb);
} ILxColorDialog;

/*
 * 
 * Clients can request an ILxMonitor, which can be used to create/open
 * progress bar dialogs.
 * Prior to 701, only the first client to request a monitor will succeed,
 * with the rest getting back LXe_NOTAVAILABLE.  However, the system maintains
 * a count of allocate/release calls, meaning that it is pivital that
 * MonitorRelease() is called to release the monitor, rather than the client
 * calling the monitor object's Release() method directly.
 * 
 * 801 introduces support for sub-monitors.  This means that allocating
 * a monitor while another monitor is already running will now return a
 * new monitor.  Functionally, the two monitors are independent, but the
 * sub-monitor can be considered to fill the current step in the parent
 * monitor, although the sub-monitor will not affect the parent monitor
 * in any way (meaning, you should still step the parent monitor even if
 * the sub-monitor appears to fill that step in the UI).  Note that it
 * is still critical that the monitors be released with MonitorRelease()
 * instead of calling the monitor object's Release() method directly.
 * 
 * 
 * Clients can request an ILxMessage.  This can be used to open dialogs
 * for user input, or pased to other clients that require them.  These
 * objects should be released as normal, via their Release() methods.
 * 
 * 
 * Calling the MonitorAllocate() from a thread will implicitly create an async monitor
 * with an empty system string for that thread.  Such monitors should be released with
 * MonitorRelease() as normal, although they are considered to be async monitors.
 * 
 * These can be used to walk the list of async monitor systems or look them
 * up by name.  Objects returned by these methods sport an ILxAsyncMonitorSystem
 * interface, and must be released as normal when no longer needed.  These methods
 * should only be called from the main thread.
 * Lookup a system by its name.
 * 
 * 
 * This can be used to look up an async monitor by its unique identifier string.
 * As always, the returned object must be released when no longer needed.
 * 
 * This service method will display any of several types of file dialogs to allow
 * the user to browse to a location, file or list of files. The configuration of
 * the dilaog is defined by the client's dialog object.
 * 
 * In some cases async monitors are not abortable, and should not draw an abort widget
 * in the activity view.  This is purely cosmetic, and does not affect the operation
 * of the moonitor, and thus is only available for root-level monitors, which are the
 * ones that determine how the montior is displayed.
 * 
 * Clients are supposed to call AllocateMonitor() / MonitorRelease() in nested 
 * pairs to bracket regions of code being monitored. In cases where that's not
 * always possible (such as with the Python Monitor object implementation) this
 * version takes the actual object being released and removes it from the stack
 * or is harmless if it's already been removed indirectly.
 */
typedef struct vt_ILxStdDialogService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
MonitorAllocate) (
        LXtObjectID		  self,
        const char		 *title,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
MonitorRelease) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
MessageAllocate) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
MessageOpen) (
        LXtObjectID		  self,
        LXtObjectID		  message,
        const char		 *title,
        const char		 *helpURL,
        const char		 *cookie);
        LXxMETHOD(  LxResult,
AsyncMonitorAllocate) (
        LXtObjectID		  self,
        const char		 *system,
        const char		 *title,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
AsyncMonitorSubAllocate) (
        LXtObjectID		  self,
        LXtObjectID		  parent,
        const char		 *title,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
AsyncMonitorRelease) (
        LXtObjectID		  self,
        LXtObjectID		  monitor);
        LXxMETHOD(  LxResult,
AsyncMonitorSystemCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
AsyncMonitorSystemByIndex) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
AsyncMonitorSystemLookup) (
        LXtObjectID		  self,
        const char		 *name,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
AsyncMonitorLookup) (
        LXtObjectID		  self,
        const char		 *ident,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
FileDialog) (
        LXtObjectID		 self,
        LXtObjectID		 dlgObj);
        LXxMETHOD(  LxResult,
AsyncMonitorAllocateWithoutAbort) (
        LXtObjectID		  self,
        const char		 *system,
        const char		 *title,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
MonitorReleaseObj) (
        LXtObjectID		 self,
        LXtObjectID		 monitor);
} ILxStdDialogService;

/*
 * The Flags() method returns flag bits to determine the behavior of the dialog.
 * - LOAD
 * By default the dialog will be for loading exising files.
 * 
 * - SAVE
 * This flag changes the dialog to allow it to create new files. This makes the
 * format important.
 * 
 * - DIRECTORY
 * This flag changes the dialog to browse for a directory. It's mutually exclusive
 * with the SAVE flag.
 * 
 * - MULTIPLE
 * For load dialogs this allows the user to pick more than one file.
 * 
 * - OVERWRITE
 * Allow overwrite for save dialogs.
 * 
 * - NOFORMATS
 * Suppress the format choice.
 * 
 * 
 * The client provides the title of the dialog through a message object.
 * 
 * The class is the type of file object that you want to load or save, and is
 * required for all file dialogs. Common choices are LXa_SCENE and LXa_IMAGE. If
 * you have defined a custom type through the config you can also give that here.
 * 
 * The context string is an optional string which just provides a way for the
 * system to remember the path for this dialog. By providing a unique context
 * string the same dialog opened again will go back to the last place the user
 * was looking. This is useful for common types like images because you don't
 * want to override all stored image paths, but not so important for custom types.
 * 
 * This method returns the initial format for the dialog. The format must match
 * the object class, so it has to be an image format for images or a scene
 * format for scenes, etc. If missing the format will default to the first one
 * for this class, and is only needed if there is more than one.
 * 
 * This returns the initial path for the dialog. A full path can be returned for
 * load and directory dialogs, or just a base name for loading and saving. If
 * missing the file name field will be empty.
 * 
 * Results are returned by calling methods on the client object. This is called
 * for each file or path chosen by the user.
 * 
 * For save dialogs this method is called to indicate the format that was chosen.
 * For object classes with multiple formats this should be stored and passed back
 * as the starting format if the dialog is opened again.
 */
typedef struct vt_ILxFileDialogClient {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Title) (
        LXtObjectID		 self,
        LXtObjectID		 message);
        LXxMETHOD(  const char *,
FileClass) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
ContextString) (
        LXtObjectID		 self,
        const char	       **context);
        LXxMETHOD(  LxResult,
FileFormat) (
        LXtObjectID		 self,
        const char	       **format);
        LXxMETHOD(  LxResult,
StartPath) (
        LXtObjectID		 self,
        const char	       **filepath);
        LXxMETHOD(  LxResult,
ResultPath) (
        LXtObjectID		 self,
        const char		*filepath);
        LXxMETHOD(  LxResult,
ResultFormat) (
        LXtObjectID		 self,
        const char		*format);
} ILxFileDialogClient;

/*
 * Asynchronous monitors provide can provide information about their current
 * state.  In fact, you can tell the difference between a standard monitor and
 * an async monitor based on either it exposes this interface.  This is primarily
 * used to implement the Activity View.
 */

        #define LXu_ASYNCMONITORINFO		"79f3c06f-f36d-477d-b946-f6f78a838230"
        #define LXa_ASYNCMONITORINFO		"asyncmonitorinfo"
        // [local] ILxAsyncMonitorInfo
        // [export] ILxAsyncMonitorInfo amoninfo

/*
 * This interface was retired in modo 11.1, and was replaced with an updated one
 * that adds the CanAbort() method.
 */

        #define LXu_ASYNCMONITORINFO1	"adf5bb35-7180-4d6e-9348-49206ae7e6ca"
        // [local]  ILxAsyncMonitorInfo1
        // [export] ILxAsyncMonitorInfo1

/*
 * Async monitors are organized by the system they belong to.  An object
 * representing this list provides this simple interface.
 * Note that the methods in this interface should only be used from the main
 * thread.
 */

        #define LXu_ASYNCMONITORSYSTEM		"c573842a-d4fd-48eb-8fb0-078a721e5e0f"
        #define LXa_ASYNCMONITORSYSTEM		"asyncmonitorsystem"
        // [local] ILxAsyncMonitorSystem
        // [export] ILxAsyncMonitorInfo amonsys
        // [python]  ILxAsyncMonitorInfo:ByIndex	obj AsyncMonitor (io)
        // [python]  ILxAsyncMonitorInfo:Lookup		obj AsyncMonitor (io)

/*
 * The color dialog can be replaced with an arbitrary one defined by a plug-in.
 * ILxColorDialog is very simple, and includes a single method, DoDialog().
 */

        #define LXu_COLORDIALOG			"2AB01AAE-110B-11DF-BFD0-0AC756D89593"
        #define LXa_COLORDIALOG			"colordialog"
        // [local] ILxColorDialog
        // [export] ILxColorDialog colordlg

/*
 * The standard dialog service provides access to a standardize dialogs
 * useful to plug-ins.
 */

        #define LXa_STDDIALOGSERVICE	"stddialogservice"
        #define LXu_STDDIALOGSERVICE	"A78FA063-6C8D-471f-8981-6BAEFF62BEE3"
        // [python]  ILxStdDialogService:MonitorAllocate		obj Monitor (io)
        // [python]  ILxStdDialogService:MessageAllocate		obj Message (value)
        // [python]  ILxStdDialogService:AsyncMonitorAllocate		obj AsyncMonitor (io)
        // [python]  ILxStdDialogService:AsyncMonitorSubAllocate	obj AsyncMonitor (io)
        // [python]  ILxStdDialogService:AsyncMonitorSystemByIndex	obj AsyncMonitorSystem (io)
        // [python]  ILxStdDialogService:AsyncMonitorSystemLookup	obj AsyncMonitorSystem (io)
        // [python]  ILxStdDialogService:AsyncMonitorLookup		obj Monitor (io)
        // [python]  ILxStdDialogService:MessageOpen			global

/*
 * An ILxMessage object can be displayed in a standard dialog.  This dialog also
 * features a help button if a help URL is provided.  Lastly, a popup is available
 * to the user that lets them decide how to handle the message in the future.
 * Currently, the options are DIALOG and HIDDEN.  If HIDDEN, the dialog will
 * not be displayed at all.
 * A title string is optional; it can contain a valid message string in the form
 * "@table@message@", where message is either a dictionary lookup string or an
 * integer ID code, or it can just be a simple string.  The simple string method
 * is not recommended unless it has already been translated.  If the title is NULL,
 * one will be generated based on the ILxMessageID's code.
 * The service can also be used to present the user with choice dialogs, such
 * as OK/Cancel or Yes/No/Yes All/No All/Cancel.  This kind of dialog is opened simply by
 * using one of the following as the LxResult message code in place of a real info/warning/error
 * code.  Any other message code will result in a dialog with "OK" as the only button.
 * - OKCANCEL
 * This is a typical binary dialog with OK and Cancel.
 * - YESNO
 * This is a slight variant of the binary dialog for answering questions:
 * Yes, and No.
 * 
 * - YESNOCAN
 * This is a standard trinary dialog, which is like a binary dialog but
 * with an extra "none of the above" option.  The dismissal buttons are:
 * Yes, No, and Cancel.
 * 
 * - SAVEOK
 * This trinary variant is intended for asking the user if they want to save an
 * object which has been changed.  It has three states: Save, Don't Save,
 * and Cancel.
 * 
 * - YESNOALL
 * This dialog type has five states which are really just a two-by-two matrix
 * of choices plus cancel.  Intended for asking a question for a series of like
 * questions, the buttons are: Yes, Yes to All, No, No to All, and Cancel.
 * 
 * - YESNOTOALL
 * This dialog type is similar to YESNOALL, but is missing the "Yes To All" option.
 * The buttons are: Yes, No, No to All, and Cancel.
 * 
 * - YESTOALLCANCEL
 * Again similar to YESNOALL, but missing the No and No To All options.
 * The buttons are: Yes, Yes to All, and Cancel.
 * 
 * 
 */

        #define LXeMSGDIALOG_AS_OKCANCEL	LXxGOODCODE( LXeSYS_COMP, 50 )
        #define LXeMSGDIALOG_AS_YESNO		LXxGOODCODE( LXeSYS_COMP, 51 )
        #define LXeMSGDIALOG_AS_YESNOCANCEL	LXxGOODCODE( LXeSYS_COMP, 52 )
        #define LXeMSGDIALOG_AS_SAVEOK		LXxGOODCODE( LXeSYS_COMP, 53 )
        #define LXeMSGDIALOG_AS_YESNOALL	LXxGOODCODE( LXeSYS_COMP, 54 )
        #define LXeMSGDIALOG_AS_YESNOTOALL	LXxGOODCODE( LXeSYS_COMP, 55 )
        #define LXeMSGDIALOG_AS_YESTOALLCANCEL	LXxGOODCODE( LXeSYS_COMP, 56 )

/*
 * LXiMSGDIALOG_EMPTY is retruned if a string is present, but it contains only
 * white space.  LXiMSGDIALOG_INVALID is returned if there is a problem with the
 * message object (e.g., it's NULL).
 */

        #define LXeMSGDIALOG_EMPTY		LXxFAILCODE( LXeSYS_COMP, 60 )
        #define LXeMSGDIALOG_INVALID		LXxFAILCODE( LXeSYS_COMP, 61 )

/*
 * If opened successfully as a question dialog, one of the following will be returned.
 * If opened as an OK Only dialog (as in, not one of the LXeMSGDIALOG_AS codes), OK
 * is always returned.  No and Cancel are fail codes, while Yes, OK and Yes To All are
 * good codes, which allows for some quick generalized checking with LXx_FAIL() and
 * LXx_OK().
 */

        #define LXeMSGDIALOG_OK			 LXe_OK
        #define LXeMSGDIALOG_YES		 LXe_OK					// Also for "Save" in the SAVEOK dialog
        #define LXeMSGDIALOG_YESTOALL		 LXxGOODCODE( LXeSYS_COMP, 70 )
        #define LXeMSGDIALOG_NO			 LXxFAILCODE( LXeSYS_COMP, 71 )		// Also for "Don't Save" in the SAVEOK dialog
        #define LXeMSGDIALOG_NOTOALL		 LXxFAILCODE( LXeSYS_COMP, 72 )
        #define LXeMSGDIALOG_CANCEL		 LXxFAILCODE( LXeSYS_COMP, 73 )

/*
 * This returns LXeMSGDIALOG_OK or CANCEL for normal operation, or some special
 * error code for other problems.
 */

        #define LXeFILEDIALOG_BADCLASS		LXxFAILCODE( LXeSYS_COMP, 80 )
        #define LXeFILEDIALOG_BADFORMAT		LXxFAILCODE( LXeSYS_COMP, 81 )


        #define LXfFILEDIALOG_LOAD		 0x00
        #define LXfFILEDIALOG_SAVE		 0x01
        #define LXfFILEDIALOG_DIRECTORY		 0x02
        #define LXfFILEDIALOG_MULTIPLE		 0x04
        #define LXfFILEDIALOG_OVERWRITE		 0x08
        #define LXfFILEDIALOG_NOFORMATS		 0x10


        #define LXu_FILEDIALOGCLIENT		"77F97D4C-8AF9-4E3A-AA58-E8418990FCA8"
        // [export]  ILxFileDialogClient fileDlg
        // [default] ILxFileDialogClient:Flags     = LXfFILEDIALOG_LOAD
        // [default] ILxFileDialogClient:FileClass = 0

#endif
