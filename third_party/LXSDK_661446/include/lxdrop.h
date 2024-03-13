/*
 * LX drop module
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
#ifndef LX_drop_H
#define LX_drop_H

typedef struct vt_ILxDrop ** ILxDropID;
typedef struct vt_ILxDrop1 ** ILxDrop1ID;
typedef struct vt_ILxAddDropAction ** ILxAddDropActionID;
typedef struct vt_ILxDropPreviewDefault ** ILxDropPreviewDefaultID;
typedef struct vt_ILxDropService ** ILxDropServiceID;

#include <lxcom.h>
#include <lxserver.h>



/*
 * The Recognize() method is called soon after the server is instanced.
 * It is only called once per drag and drop cycle, and is used to
 * perform any possibly expensive setup and verification of the source,
 * such as scanning file headers.  This information can be cached in
 * your server for use in ActionList(), Preview() and Drop(), rather
 * than recomputing state in those functions.
 * If the source was recognized, this should return LXe_OK.  Any failure
 * code will be treated as though the source was not recognized, and the
 * server will not be called any more for this drag and drop cycle.
 * 
 * 
 * ActionList() is where you add your actions to the dropover.  This
 * method is called frequently (ie: when dragging the mouse around the
 * screen), and should be fast.  It is provided with thtrr COM objects:
 * the source data being dragged, the destination, and an ILxAddDropAction
 * object with which you can add your actions to the dropover.
 * The destination may contain arbitrary interfaces depending on what
 * is under the mouse, included interfaces that your server doesn't
 * support.  It is best to check the destination interfaces first
 * before doing anything else so that you can exit quickly if you
 * can't support drops here.
 * 
 * The source will be of the type the server indicated in its tags, but it
 * may contain additional interfaces, and should be queried as appropriate
 * before trying to use it.
 * 
 * If the server can find interfaces that it supports on both the source and
 * destination objects, it should call ILxAddDropAction::AddAction() on the
 * provided object for each drop action it would like to register.  An
 * arbitrary number of actions can be registered, but the action codes must
 * match those defined by the server's ACTIONNAMES server tag.
 * 
 * 
 * 901 introduces the Preview() method.  Some targets provide objects that
 * can be used by the server to drop the mark point.  This can be as simple
 * changing the location fo a drop marker drawn by the target (say, changing
 * whre the drop marker is drawn in a tree view), to complete custom drawing
 * by the server in a GL view (say, to draw a bounding box representation of
 * a mesh preset in the 3D view).
 * If an action in your server is the best match for the current mouse/modifier
 * combo and the target provides a destination interface (as determiend by
 * which modifier keys are down and the Drop Mappings set up in the prefernces),
 * your Preview() method will be called.
 * 
 * If you return LXe_NOTIMPL, the target will do its own default drawing.
 * Otherwise, you are expected to do your own drawing with the draw object
 * provided.  The exact interfaces available are determined by the target,
 * so you will have to query for the ones you want to see if they are
 * available.
 * 
 * The draw object is expected to have the ILxDropPreviewDefault interface,
 * which may allow you to force the default drawing in addition to your own
 * drawing, athough in some case default drawing and custom drawing are
 * mutually exclusive (such as in tree panes).
 * 
 * 
 * The Drop() method is called to actually perform the drop itself.  The
 * server is expected to take apply the source object using information
 * obtained through the destination's interfaces.  The specific action
 * to apply is provided through the action argument, and is one of those
 * that was added by the Recognize() method's
 */
typedef struct vt_ILxDrop {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Recognize) (
        LXtObjectID		  self,
        LXtObjectID		  source);
        LXxMETHOD( LxResult,
ActionList) (
        LXtObjectID		  self,
        LXtObjectID		  source,
        LXtObjectID		  dest,
        LXtObjectID		  addDropAction);
        LXxMETHOD( LxResult,
Preview) (
        LXtObjectID		  self,
        LXtObjectID		  source,
        LXtObjectID		  dest,
        int			  action,
        LXtObjectID		  draw);
        LXxMETHOD( LxResult,
Drop) (
        LXtObjectID		  self,
        LXtObjectID		  source,
        LXtObjectID		  dest,
        int			  action);
} ILxDrop;

typedef struct vt_ILxDrop1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Recognize) (
        LXtObjectID		  self,
        LXtObjectID		  source);

        LXxMETHOD( LxResult,
ActionList) (
        LXtObjectID		  self,
        LXtObjectID		  source,
        LXtObjectID		  dest,
        LXtObjectID		  addDropAction);

        LXxMETHOD( LxResult,
Drop) (
        LXtObjectID		  self,
        LXtObjectID		  source,
        LXtObjectID		  dest,
        int			  action);
} ILxDrop1;

/*
 * This method is called during by ILxDrop servers during their ActionList()
 * method to add new behaviors to drop hover popover.  The ILxDrop server
 * should call this once for each action it wishes to add.
 * Actions are identified by a server-specific action code (which can be
 * anything the server desires, but is expected to match those in the
 * ACTIONNAMES tag), as well as a label in the form of a "@table@message"
 * message string for display in the hover popover.  This label can also
 * be a dynamically generated string, thus allowing for things like
 * "Move 3 Files" that provide more useful information to the user about
 * what the drop will do.
 * 
 * 
 * This method can be used to obtain a "peek" at the destination object to
 * more accurately determine which actions to add to the list.  This only
 * works when inside the ILxDrop server's ActionList() method, and is
 * somewhat redundant since that method is passed the destination anyway.
 * Although this is a peek, the caller is still responsible for freeing
 * the returned object.
 */
typedef struct vt_ILxAddDropAction {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddAction) (
        LXtObjectID		 self,
        int			 action,
        const char		*message);
        LXxMETHOD(  LxResult,
Peek) (
        LXtObjectID		  self,
        void			**ppvObj);
} ILxAddDropAction;

/*
 * Calling this method tells the target to draw its default drop marker.
 * You can call this instead of or in addition to your own drawing.  Rreturning
 * LXe_NOTIMPL from your ILxDrop::Preview() will also trigger default drawing.
 */
typedef struct vt_ILxDropPreviewDefault {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Draw) (
        LXtObjectID		 self);
} ILxDropPreviewDefault;

/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.  However, it is not implemented for ILxDropService.
 * 
 * This returns the current destination object, failing if there is none.  The
 * object must be released when no longer needed.
 * 
 * This returns the current source type and source object.  While a source can
 * expose multiple source types and objects, this is the specific source type
 * (as an LXsDROPSOURCE_ define) and object representing the drop in progress.
 * The object must be released when no longer needed.
 * 
 * During a drop, this returns the name of the drop server and the action
 * code of the server.  Scripts associated with the drop server can use
 * knowledge of that server's action codes to perform specific drop actions
 * (add vs. replace, say).
 */
typedef struct vt_ILxDropService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Destination) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Source) (
        LXtObjectID		  self,
        const char		**sourceType,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Action) (
        LXtObjectID		  self,
        const char		**serverName,
        int			 *actionCode);
} ILxDropService;

/*
 * Alternate input -- most notably tablet support -- can be obtained at any time
 * by checking WManInputAttr().  A common use is to wait for a mouse move or click
 * event, then check WManInputAttr() for pressure, tilt, etc.
 * Currently, only tablet input is defined, but we might wind up defining other
 * types in the future.
 */

        #define LXmINATTR_CLASS			0xF000

        #define LXfINATTR_TABLET		0x1000
        #define LXfINATTR_SPACEBALL		0x2000

        // Tablet
        #define LXiINATTR_TABLET_INUSE		(LXfINATTR_TABLET | 1)

        #define LXiINATTR_TABLET_PRESSURE	(LXfINATTR_TABLET | 2)
        #define LXiINATTR_TABLET_TANGENT	(LXfINATTR_TABLET | 3)
        #define LXiINATTR_TABLET_TILT_HEADING	(LXfINATTR_TABLET | 4)
        #define LXiINATTR_TABLET_TILT_PITCH	(LXfINATTR_TABLET | 5)
        #define LXiINATTR_TABLET_TWIST		(LXfINATTR_TABLET | 6)

        // Spaceball
        #define LXiINATTR_SPACEBALL_POS_X	(LXfINATTR_SPACEBALL | 1)
        #define LXiINATTR_SPACEBALL_POS_Y	(LXfINATTR_SPACEBALL | 2)
        #define LXiINATTR_SPACEBALL_POS_Z	(LXfINATTR_SPACEBALL | 3)
        #define LXiINATTR_SPACEBALL_ROT_X	(LXfINATTR_SPACEBALL | 4)
        #define LXiINATTR_SPACEBALL_ROT_Y	(LXfINATTR_SPACEBALL | 5)
        #define LXiINATTR_SPACEBALL_ROT_Z	(LXfINATTR_SPACEBALL | 6)

/*
 * ILxDrop allows servers to provide arbtirary behaviors when a drag
 * and drop operation matches a specific combination of source and
 * destination COM interfaces.  If the user has chosen one of these
 * behaviors (often from a popover that appears when the user hovers
 * the mouse during a drag and drop operation), ILxDrop is asked to
 * perform it.
 */

        #define LXu_DROP		"ca3c0d04-5ebe-40a7-bb1a-d38488c7967d"
        #define LXa_DROP		"drop"
        //[export] ILxDrop drop
        //[local]  ILxDrop

/*
 * An ILxDrop server can recognize only one kind of source, although
 * the details of that source may be varied.  For example, a
 * LXsDROPSOURCE_FILES may represent the path to one or more presets,
 * images, scenes or any other kind of file.
 * The specific source type supported by a server is indicated through
 * server tags.
 */

        #define LXsDROP_SOURCETYPE		"drop.sourceType"

/*
 * Here are some common source types.  The ones ending in "S" are
 * plurals, and thus are usually an ILxValueArray containing one or
 * more entries.  The ones without an "S" suffix are usually represented
 * as single objects, not arrays of objects.
 * - FILES
 * An ILxValueArray object with the FILEPATH ExoType, which contains
 * strings representing the paths for each file being dropped (even
 * if it's only one file).  These always represent real files or
 * directories as absolute paths in local format.
 * - FILES_SYNTH
 * An ILxValueArray object with the FILEPATH ExoType, which contains
 * strings representing the paths for each file being dropped (even
 * if it's only one file).  Unlike FILES, which only ever includes
 * real files on disk, FILES_SYNTH can include real files, synthetic
 * files (those starting with the path volume "[servername]:"
 * as described in the dir cache docs), and merged files (starting
 * with "#basePathIdent(setName):", again as described in the dir
 * cache docs).  Paths are always absoluete and in local format for
 * file system paths, and neutral format for synthetic and merged
 * paths.
 * 
 * - COLOR
 * An ILxColor object, which contains the RGB color, the alternate
 * color model (if any) and the color in that model's space as a
 * string (if any).
 * 
 * - ITEMS
 * An ILxValueArray object with the ITEM ExoType.
 * 
 * - CHANNELS
 * An ILxValueArray object with the CHANNEL ExoType.
 * 
 * - COMMANDS
 * An ILxValueArray of strings representing commands.
 * 
 * - FORMCONTROLS
 * An ILxValueArray of strings representing form controls and sheets.
 * 
 * A note about FILES and FILES_SYNTH:  Since drop servers can support
 * only a single drop source, you only need to support FILES or
 * FILES_SYNTH.  If the actual drag source is FILES_SYNTH and you only
 * support FILES, the array you get will contain only non-synthetic
 * and non-merged paths.  This makes it easy to add synthetic support,
 * while also avoiding issues with legacy servers that predate FILES_SYNTH.
 * 
 */

        #define LXsDROPSOURCE_FILES		"files"
        #define LXsDROPSOURCE_FILES_SYNTH	"filesAndSynthetics"
        #define LXsDROPSOURCE_COLOR		"color"
        #define LXsDROPSOURCE_ITEMS		"items"
        #define LXsDROPSOURCE_CHANNELS		"channels"
        #define LXsDROPSOURCE_COMMANDS		"commands"
        #define LXsDROPSOURCE_FORMCONTROLS	"formcontrols"

/*
 * The user can prioritize which drop actions are associated with which
 * modifier key combinations through the Drop Mapping viewport. The list
 * of available actions for this view is read from the LXsDROP_ACTIONS
 * server tag.  All actions that may appear in the dropover should be
 * included in this tag, as only actions exposed in this way can be
 * associated with modifier keys.  Although actions not in the tag may
 * still appear in the dropover, they will never have modifier keys
 * associated with them and can never be the deafult drop action, so
 * you really should always include them so that the user can make that
 * decision themselves.
 */

        #define LXsDROP_ACTIONNAMES	"drop.actions"

/*
 * This interface was retired in modo 901, and was replaced with an updated one
 * that adds new methods.
 */

        #define LXu_DROP1		"abea8de3-d821-4437-88b3-05f20276ffeb"
        // [export] ILxDrop1 drop1
        // [local]  ILxDrop1

/*
 * An object with this interface is used by ILxDrop to add new behaviors to
 * the action list.
 */

        #define LXu_ADDDROPACTION	"05C3FF8F-5C3C-4463-AF6E-439C52621DCA"
        #define LXa_ADDDROPACTION	"adddropaction"
        // [local]  ILxAddDropAction
        // [python] ILxAddDropAction:Peek	obj Unknown

/*
 * An object with this interface (and others) is passed to ILxDrop::Preview()
 * so that clients can ask the view to draw a default drop marker.
 */

        #define LXu_DROPPREVIEWDEFAULT	"f3823495-d23f-448f-a5dd-16a1761445a0"
        #define LXa_DROPPREVIEWDEFAULT	"droppreviewdefault"
        // [local]  ILxDropPreviewDefault

/*
 * The global ILxDropService provides a way for clients that don't have direct
 * access to the ILxDrop server to access the destination and source objects.
 * This is primarily for scripts associated with drop servers.  For example,
 * a script embedded in a preset can be launched by the ILxDrop server, and
 * the script can determine what to do based on the destination object.
 * Note that all of these are only gauranteed to be implemented for an actual
 * drop, and not necessarily during a drag.
 */

        #define LXu_DROPSERVICE	"44345a07-014c-4deb-aba8-8a3147bba212"
        #define LXa_DROPSERVICE	"dropservice"
        // [python] ILxDropService:Destination	obj Unknown
        // [python] ILxDropService:Source	obj Unknown

#endif
