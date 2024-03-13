/*
 * LX vmodel module
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
#ifndef LX_vmodel_H
#define LX_vmodel_H

typedef struct vt_ILxViewItem3D ** ILxViewItem3DID;
typedef struct vt_ILxViewItem3D1 ** ILxViewItem3D1ID;
typedef struct vt_ILxVirtualModel ** ILxVirtualModelID;
typedef struct vt_ILxToolModel ** ILxToolModelID;
typedef struct vt_ILxToolModel4 ** ILxToolModel4ID;
typedef struct vt_ILxToolModel3 ** ILxToolModel3ID;
typedef struct vt_ILxToolModel2 ** ILxToolModel2ID;
typedef struct vt_ILxToolModel1 ** ILxToolModel1ID;
typedef struct vt_ILxAdjustTool ** ILxAdjustToolID;
typedef struct vt_ILxNavigationListener ** ILxNavigationListenerID;

#include <lxvalue.h>
#include <lxvector.h>
#include <lxtool.h>
#include <lxhandles.h>
#include <lxdraw.h>
#include <lxvalue.h>


/*
 * Tool can also have a tracking function associated with them. The
 * function will be called during mouse movement over a viewport with one
 * of the event types below.
 */

        #define LXfTRACK_ENTER		0x00
        #define LXfTRACK_MOVE		0x01
        #define LXfTRACK_EXIT		0x02

/*
 * Tool can specify how to select elements for selection rollover. LAZY allows
 * the tool lazy selection regardress the current lazy selection mode. VERX,
 * EDGE and POLY are components to be pre highlighting. If nothing is specified,
 * the default selection settings will be used. LOOP1 and LOOP2 works with EDGE
 * mask to draw edge loop. RAYCAST always uses the hit testing regardress the
 * view shading mode.
 */

        #define LXfTRACK_LAZY		0x000040
        #define LXfTRACK_VERX		0x000100
        #define LXfTRACK_EDGE		0x000200
        #define LXfTRACK_POLY		0x000400
        #define LXfTRACK_LOOP1		0x000800
        #define LXfTRACK_LOOP2		0x001000
        #define LXfTRACK_RAYCAST	0x002000
        #define LXfTRACK_BK_RAYCAST	0x004000
        #define LXfTRACK_ACTIVE		0x008000
        #define LXfTRACK_INACTIVE	0x010000



/*
 * "Test" is called to hit test the item.  If "Test" is not implemented, "Draw"
 * method is called for hit testing.
 * 
 */
typedef struct vt_ILxViewItem3D {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Draw) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtObjectID		 strokeDraw,
        int			 selectionFlags,
        const LXtVector		 itemColor);

        LXxMETHOD(  LxResult,
DrawBackground) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtObjectID		 strokeDraw,
        const LXtVector		 itemColor);

        LXxMETHOD(  LxResult,
WorldSpace) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
HandleCount) (
        LXtObjectID		 self,
        int			*count);

        LXxMETHOD(  LxResult,
HandleMotion) (
        LXtObjectID		 self,
        int			 handleIndex,
        int			*handleFlags,
        double			*min,
        double			*max,
        LXtVector		 plane,
        LXtVector		 offset);

        LXxMETHOD(  LxResult,
HandleChannel) (
        LXtObjectID		 self,
        int			 handleIndex,
        int			*chanIndex);

        LXxMETHOD(  LxResult,
HandleValueToPosition) (
        LXtObjectID		 self,
        int			 handleIndex,
        const double		*chanValue,
        LXtVector		 position);

        LXxMETHOD(  LxResult,
HandlePositionToValue) (
        LXtObjectID		 self,
        int			 handleIndex,
        const LXtVector		 position,
        double			*chanValue);
        LXxMETHOD(  LxResult,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtObjectID		 strokeDraw,
        int			 selectionFlags,
        const LXtVector		 itemColor);
} ILxViewItem3D;

typedef struct vt_ILxViewItem3D1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Draw) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtObjectID		 strokeDraw,
        int			 selectionFlags,
        LXtVector		 itemColor);

        LXxMETHOD(  LxResult,
DrawBackground) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtObjectID		 strokeDraw,
        LXtVector		 itemColor);

        LXxMETHOD(  LxResult,
WorldSpace) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
HandleCount) (
        LXtObjectID		 self,
        int			*count);

        LXxMETHOD(  LxResult,
HandleMotion) (
        LXtObjectID		 self,
        int			 handleIndex,
        int			*handleFlags,
        double			*min,
        double			*max,
        LXtVector		 plane,
        LXtVector		 offset);

        LXxMETHOD(  LxResult,
HandleChannel) (
        LXtObjectID		 self,
        int			 handleIndex,
        int			*chanIndex);

        LXxMETHOD(  LxResult,
HandleValueToPosition) (
        LXtObjectID		 self,
        int			 handleIndex,
        double			*chanValue,
        LXtVector		 position);

        LXxMETHOD(  LxResult,
HandlePositionToValue) (
        LXtObjectID		 self,
        int			 handleIndex,
        LXtVector		 position,
        double			*chanValue);
} ILxViewItem3D1;

/*
 * The flags method determines various interactive behaviors for the virtual model.
 * These values should be a combination of LXfTMOD flags. This value should not
 * change.
 * Virtual Models can draw into graphic viewports with the Draw and Test methods.
 * Draw is called to update the stroked model in the view, and Test is called when
 * performing mouse rollover to define regions for hit testing.
 * 
 * This function allows clients to get the part number the mouse is over. If the
 * mouse is not over a part, the part number is -1.
 * 
 * Virtual Models can handle mouse input using the Down, Move and Up methods.
 * - Down
 * This function is called on an initial mouse down.
 * 
 * - Move
 * This function is called repeatedly with updated position information that tracks
 * the mouse movement during raw input event processing.
 * 
 * - Up
 * This function is called at the end of a user interaction, signified by a release
 * of the mouse button.
 * 
 * 
 * This function allows clients to return a tooltip for the given part number.
 */
typedef struct vt_ILxVirtualModel {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD( void,
Draw) (
        LXtObjectID		 self,
        LXtObjectID		 stroke);

        LXxMETHOD( void,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 stroke);
        LXxMETHOD( void,
Track) (
        LXtObjectID		 self,
        int			 part);
        LXxMETHOD( void,
Down) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( void,
Move) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( void,
Up) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
        LXxMETHOD( const char *,
Tooltip) (
        LXtObjectID		 self,
        int			 part);
} ILxVirtualModel;

/*
 * A tool's flags encode various interactive behaviors of the tool.  This value
 * should not change.
 * Tools can draw themselves in graphic viewports with the Draw() and Test()
 * methods.  Draw() is called to update the appearance of the tool (as a stroked
 * model in the view).  Test() is called when performing hit testing on the
 * tool, and can be substantially the same as the draw method as long as part
 * ID's are set for the tool's handles.
 * 
 * The Initialize() method is called to set up tool attributes when they
 * need to integrate into an active pipeline, typically when the tool activates
 * due to a mouse-down event.  The tool needs to compute default state based on
 * the flags.  DIRECT means that the tool itself is the focus of user action,
 * and EVENT means that this is the result of a viewport event.  AGAIN is set
 * only if the tool sets the INITAGAIN bit in its flags, in which case it means
 * that the tool has user-set values but is being initialized again. BRUSH means
 * that the tool is used in conjunction with a brush tool, which maybe change
 * the way the tool is intialized. PROCEDURAL bit is set when the Initialize()
 * method is called for the procedural tool operator.
 * 
 * The ILxToolModel directly tracks mouse movement via Down, Move, and Up event
 * callbacks, as well as tracking the part number and hit location of mouse
 * events on handles.  The parts are prioritized based on the part number (available
 * in the tool vector), with the highest part taking the hit.
 * 
 * Some attributes can have automatic hauling behavior.  Tools may expose up to
 * 2 attributes for automatic hauling: the first attribute (index = 0) is displayed
 * with horizontal graduations, the seconde one (index = 1) is displayed vertically.
 * The 'haul' method returns the attribute name given its index.
 * 
 * Similarly, users may select attributes on the tool to be automatically hauled.  
 * Before input is taken over, however, tools will have their AllowOverride function 
 * called (if implemented) for each selected attribute with the attribute name, mouse 
 * button and chosen hauling axis. Tool clients can opt out of the override and ignore
 * the attribute selection by returning LXe_FALSE for at least one of the selected 
 * attributes. Tools which do not implement this method or return LXe_TRUE for all 
 * selected attributes will not recieve down, move, or up calls while attributes are 
 * selected. 
 * 
 * Help or tips messages can be displayed during tool interaction using the 'Help'
 * method.  This function gets the tool vector and returns a pointer to a string.
 * 
 * Tell whether tool can be set. This method retuns LXe_DISABLED if the tool is not
 * ready to run and it also set the reason to the message. Otherwise it returns
 * LXe_OK.
 * 
 * Called when the tool is dropped.
 * 
 * 
 * 
 * 
 * Test if the tool can be operated on the given viewport type. This meshod
 * should return LXe_FALSE if the tool does not work on the viewport type.
 * Otherwise it returns LXe_TRUE.
 * 
 * This function allows clients to return a tooltip for the given tool part number.
 */
typedef struct vt_ILxToolModel {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD( void,
Draw) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 stroke,
        int 			 flags);

        LXxMETHOD( void,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 stroke,
        int 			 flags);

        LXxMETHOD( void,
Filter) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);
        LXxMETHOD( void,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust,
        unsigned int		 flags);
        LXxMETHOD( LxResult,
Down) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Move) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Up) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);
        LXxMETHOD( const char *,
Haul) (
        LXtObjectID		 self,
        unsigned int		 index);
        LXxMETHOD( LxResult,
AllowOverride) (
        LXtObjectID		 self,
        const char		*attrName,
        unsigned int		 mouseInput,
        unsigned int		 haulAxis);
        LXxMETHOD( const char *,
Help) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
        LXxMETHOD( LxResult,
Enable) (
        LXtObjectID		 self,
        LXtObjectID		 msg);
        LXxMETHOD( LxResult,
Drop) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Track) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        unsigned int		 eventType);
        LXxMETHOD( LxResult,
TrackFlags) (
        LXtObjectID		 self,
        unsigned int		*flags);
        LXxMETHOD( LxResult,
Post) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
        LXxMETHOD( LxResult,
TestType) (
        LXtObjectID		 self,
        LXtID4			 type);
        LXxMETHOD( const char *,
Tooltip) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        int			 part);
} ILxToolModel;

typedef struct vt_ILxToolModel4 {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Draw) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 stroke,
        int 			 flags);

        LXxMETHOD( void,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 stroke,
        int 			 flags);

        LXxMETHOD( void,
Filter) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust,
        unsigned int		 flags);

        LXxMETHOD( LxResult,
Down) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Move) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Up) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( const char *,
Haul) (
        LXtObjectID		 self,
        unsigned int		 index);

        LXxMETHOD( const char *,
Help) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( LxResult,
Enable) (
        LXtObjectID		 self,
        LXtObjectID		 msg);

        LXxMETHOD( LxResult,
Drop) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Track) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        unsigned int		 eventType);

        LXxMETHOD( LxResult,
TrackFlags) (
        LXtObjectID		 self,
        unsigned int		*flags);

        LXxMETHOD( LxResult,
Post) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
        
        LXxMETHOD( LxResult,
TestType) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD( const char *,
Tooltip) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        int			 part);
} ILxToolModel4;

typedef struct vt_ILxToolModel3 {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Draw) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 stroke,
        int 			 flags);

        LXxMETHOD( void,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 stroke,
        int 			 flags);

        LXxMETHOD( void,
Filter) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( void,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust,
        unsigned int		 flags);

        LXxMETHOD( LxResult,
Down) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Move) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Up) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( const char *,
Haul) (
        LXtObjectID		 self,
        unsigned int		 index);

        LXxMETHOD( const char *,
Help) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( LxResult,
Enable) (
        LXtObjectID		 self,
        LXtObjectID		 msg);

        LXxMETHOD( LxResult,
Drop) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Track) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        unsigned int		 eventType);

        LXxMETHOD( LxResult,
TrackFlags) (
        LXtObjectID		 self,
        unsigned int		*flags);

        LXxMETHOD( LxResult,
Post) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
        
        LXxMETHOD( LxResult,
TestType) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD( const char *,
Tooltip) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        int			 part);
} ILxToolModel3;

typedef struct vt_ILxToolModel2 {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Draw) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 stroke,
        int 			 flags);

        LXxMETHOD( void,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 stroke,
        int 			 flags);

        LXxMETHOD( void,
Filter) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( void,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust,
        unsigned int		 flags);

        LXxMETHOD( LxResult,
Down) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Move) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Up) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( const char *,
Haul) (
        LXtObjectID		 self,
        unsigned int		 index);

        LXxMETHOD( const char *,
Help) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( LxResult,
Enable) (
        LXtObjectID		 self,
        LXtObjectID		 msg);

        LXxMETHOD( LxResult,
Drop) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Track) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        unsigned int		 eventType);

        LXxMETHOD( LxResult,
TrackFlags) (
        LXtObjectID		 self,
        unsigned int		*flags);

        LXxMETHOD( LxResult,
Post) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
        
        LXxMETHOD( LxResult,
TestType) (
        LXtObjectID		 self,
        LXtID4			 type);
} ILxToolModel2;

typedef struct vt_ILxToolModel1 {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Draw) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 stroke,
        int 			 flags);

        LXxMETHOD( void,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 stroke,
        int 			 flags);

        LXxMETHOD( void,
Filter) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( void,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust,
        unsigned int		 flags);

        LXxMETHOD( LxResult,
Down) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Move) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( void,
Up) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 adjust);

        LXxMETHOD( const char *,
Haul) (
        LXtObjectID		 self,
        unsigned int		 index);

        LXxMETHOD( const char *,
Help) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( LxResult,
Enable) (
        LXtObjectID		 self,
        LXtObjectID		 msg);

        LXxMETHOD( LxResult,
Drop) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Track) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        unsigned int		 eventType);

        LXxMETHOD( LxResult,
TrackFlags) (
        LXtObjectID		 self,
        unsigned int		*flags);

        LXxMETHOD( LxResult,
Post) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
} ILxToolModel1;

/*
 * During event processing, the tool should not modify its own attributes
 * directly.  Instead it should adjust its own values through the adjust tool
 * interface which allows the atribute changes to be scripted and undoable.
 * The functions are similar to those found in the ILxAttributes interface,
 * but they are for write only.  The Value() method is passed a value object
 * for the attribute which will probably be copied and converted into text.
 * 
 * Additional methods allow the tool to signal other changes during interaction.
 * Invalidate() causes the tools model to redraw, and Lock() indicates that the
 * next attribute change will have side effects and cannot be merged with
 * previous changes.
 */
typedef struct vt_ILxAdjustTool {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Value) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtObjectID		 val);

        LXxMETHOD( void,
SetInt) (
        LXtObjectID		 self,
        unsigned int		 index,
        int			 val);

        LXxMETHOD( void,
SetFlt) (
        LXtObjectID		 self,
        unsigned int		 index,
        double			 val);

        LXxMETHOD( void,
SetString) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char		*val);
        LXxMETHOD( void,
Lock) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Invalidate) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Update) (
        LXtObjectID		 self);
} ILxAdjustTool;

/*
 * Navigation listener is a global port to be informed of camera navigation event.
 * 'Down' is called when mouse is down. 'view' is ILxView3D object of navigation viewport.
 * 'item' is ILxItem1 object when navigation viewport is camera or light or preview.
 * 
 * 
 * 'Move' is called when mouse is move. 'pos', 'rot' and 'zoom' are current view tranform
 * in hot mode in camera or preview navigation. The navigating transform type is set by
 * 'hot' mask as LXfNAV_HOT.
 * 
 * 'Up' is called when mouse is up.
 * 
 * 'Delta' is called at the end of navigation by a navigation wiget.
 * 
 * 'Wheel' is called at the end of mouse wheel event.
 * 
 * 'HotSyncPre' is called when the current hot mode is on and the new 
 * mode is off before calling the navigation action in 'Move' or 'Delta' 
 * event.
 * 
 * 'HotSyncPost' is called when the current hot mode is on and the new 
 * mode is off after the navigation action in 'Move' or 'Delta' event.
 */
typedef struct vt_ILxNavigationListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Down) (
        LXtObjectID		 self,
        LXtObjectID		 view,
        LXtObjectID		 item);
        LXxMETHOD( void,
Move) (
        LXtObjectID		 self,
        LXtObjectID		 view,
        LXtObjectID		 item,
        unsigned		 hot,
        const LXtVector		 pos,
        const LXtMatrix		 rot,
        double			 zoom);
        LXxMETHOD( void,
Up) (
        LXtObjectID		 self,
        LXtObjectID		 view,
        LXtObjectID		 item);
        LXxMETHOD( void,
Delta) (
        LXtObjectID		 self,
        LXtObjectID		 view,
        LXtObjectID		 item,
        unsigned		 hot,
        const LXtVector		 pos,
        const LXtMatrix		 rot,
        double			 zoom);
        LXxMETHOD( void,
Wheel) (
        LXtObjectID		 self,
        LXtObjectID		 view,
        LXtObjectID		 item);
        LXxMETHOD( void,
HotSyncPre) (
        LXtObjectID		 self,
        LXtObjectID		 view,
        LXtObjectID		 item);
        LXxMETHOD( void,
HotSyncPost) (
        LXtObjectID		 self,
        LXtObjectID		 view,
        LXtObjectID		 item);
} ILxNavigationListener;

/*
 * A 3D view item plug-in defines the appearance of an entity in abstract 3D space.
 */

        #define LXu_VIEWITEM3D		"5E0E5E09-9D9F-447C-AEDA-2F6F266DB464"
        #define LXa_VIEWITEM3D		"viewitem3dv2"
        //[local]  ILxViewItem3D
        //[export] ILxViewItem3D vitm
        //[python] ILxViewItem3D:WorldSpace bool


        #define LXiSELECTION_UNSELECTED		0
        #define LXiSELECTION_SELECTED		1
        #define LXiSELECTION_ROLLOVER		2

        #define LXiMOTION_1D			1 // obsolete
        #define LXiMOTION_ANGULAR		2 // obsolete
        #define LXiMOTION_RADIAL		3 // obsolete

        #define LXiVHANDLE_BASE_PART		400

        #define LXmVHANDLE_CONSTRAINT		7 // mask off bottom 3 bits for 8 constraint types
        #define LXfVHANDLE_CON_LINEAR		1
        #define LXfVHANDLE_CON_PLANAR		2

        #define LXmVHANDLE_DRAW_SHAPE		(15<<3) // mask off next 4 bits for 16 draw shapes
        #define LXfVHANDLE_DRAW_BOX		(0)
        #define LXfVHANDLE_DRAW_LINE		(1<<3)
        #define LXfVHANDLE_DRAW_POINT		(2<<3)
        #define LXfVHANDLE_DRAW_PLUS		(3<<3)
        #define LXfVHANDLE_DRAW_X		(4<<3)
        #define LXxVHANDLE_DRAW_SHAPE(f)	((f)&LXmVHANDLE_DRAW_SHAPE)

        #define LXmVHANDLE_DRAW_AXIS		(3<<16) // mask off bottom 2 bits of next word for 4 axis values
        #define LXxVHANDLE_DRAW_AXIS(f)		(((f)>>16)&3)

        #define LXfVHANDLE_VAL_VECTOR		(1<<8)
        #define LXfVHANDLE_VAL_2D		(2<<8)
        #define LXfVHANDLE_RESERVED		(1<<31) // PRIVATE! HANDS OFF


/*
 * This interface was retired in modo 701, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXu_VIEWITEM3D1		"9BCE73B5-3264-48BB-B129-15FF53FD1661"
        #define LXa_VIEWITEM3D1		"viewitem3d"
        //[local]  ILxViewItem3D1
        //[export] ILxViewItem3D1 vitm


        #define LXu_VIRTUALMODEL	"28F7A244-E5B0-406C-AA54-55D33D52EB4A"
        
        // [export] ILxVirtualModel	 vmodel
        // [local]  ILxVirtualModel
        // [default] ILxVirtualModel:Flags = LXfTMOD_DRAW_3D
        // [default] ILxVirtualModel:Tooltip = NULL

/*
 * When tools are selected, they can affect the way that input happens in the
 * 3D views.  Tool object present an ILxToolModel interface which allows them
 * to participate in mouse input and direct manipulation.  Internal tools
 * implemented as ToolObj's can also have model interfaces attached.
 */

        #define LXu_TOOLMODEL	"7C98503C-B697-43D2-BC04-50CE8E4839B2"
        // [local]   ILxToolModel
        // [export]  ILxToolModel tmod
        // [default] ILxToolModel:Flags = LXfTMOD_DRAW_3D
        // [default] ILxToolModel:Help  = 0
        // [default] ILxToolModel:Haul  = 0
        // [default] ILxToolModel:Tooltip = 0

/*
 * The flags contain masks for drawing and testing in different view coordinates.
 * 3D space is the normal model or world coordinate system, and PIXEL is the pixel space
 * for the GL viewport.  Tools with both flags set will be drawn twice in each
 * viewport.
 * The MODELSPACE bit indicates that the tool will expect the draw and test functions to
 * operate in raw Model space, rather than the View space, which is the apparent space
 * in which the user is working. View space is just Model space transformed by the
 * 'Construction Plane'.  Since users will expect tools to respect the altered coordinate
 * system they have chosen, it is rare that a tool would want to forgo this transformation.
 * For tools that will work directly with mesh coordinates, however, this flag can be useful.
 * The Model Space to View Space transform is available in the Xfrm packet of the tool vector.
 */

        #define LXfTMOD_MODELSPACE	 0x00000004
        #define LXfTMOD_DRAW_3D		 0x00000010
        #define LXfTMOD_DRAW_PIXEL	 0x00000020

/*
 * The flags also contain masks for the different input behaviors.  I0 is the primary input
 * and I1 is the secondary input (mapped to left and right buttons), the tool can ask for input
 * on either of these or indicate that it wants automatic attribute hauling.  The other two flags
 * can be used to trigger certain input changes, for brush-type and curve-type tools.
 */

        #define LXfTMOD_I0_INPUT	 0x00000040
        #define LXfTMOD_I0_ATTRHAUL	 0x00000080
        #define LXfTMOD_I1_INPUT	 0x00000100
        #define LXfTMOD_I1_ATTRHAUL	 0x00000200
        #define LXfTMOD_I_CURVE		 0x00000400
        #define LXfTMOD_I_BRUSH		 0x00000800
        #define LXfTMOD_I_GENERAL	 0x00001000

/*
 * Finally, the flags contain masks to identify the tool type which is then mapped to an
 * input pattern. For the input pattern, we can derive the falloff information from the
 * vector type, so we just need to know the reset and brush behaviors.
 * - BRUSHRESET
 * This is used for tools that want to autoreset for each brush stroke (like the push tool
 * - NEEDHAUL
 * Tools without handles or that require hauling input should say so with the NEEDSHAUL
 * flag. This will prevent hauling from being disabled by a tool preset flag.
 * 
 * - ROLLOVERS 
 * Set if the handles should draw highlighted when the mouse moves over them.
 * 
 * - AUTORESET
 * Apaprently distinguishes between transform and general tools...
 * 
 * - HANDLERESET
 * This flag causes the tool to be restarted each time a handle is clicked.
 * 
 * - DRAW_INACTIVE
 * When set, the draw function is called even if the tool is not active. Similarly, clicking
 * on the drawn handle of such an inactive tool will activate the tool and start dragging
 * the handle.
 * 
 * - I0_NOSELECT
 * - I1_NOSELECT
 * Don't select when an INPUT or ATTRHAUL event is received, effectively blocking "select through"
 * (I think).
 * 
 * - AUTOACTIVATE
 * - SELECTTRHOUGH
 * These set the initial tool modes, which can then be overridden from tool presets.
 * 
 * - NOCLONE
 * This should be set when clone is reset.
 * 
 * - NODELTA
 * When set, the mouse pointer remains visible and the tool does not operate in delta
 * mode, meaning that it is constrainted to the bounds of the screen.  Useful for 2D
 * operations that should track the true mouse position, as opposed to 3D operations
 * where edge of the screen would be in the way.
 * 
 * - INDIRECT
 * The tool is always activated indirectly as a result of downstream tool activation.
 * 
 * - NEEDSFIRSTINPUT
 * Ensures that the first click and drag in the 3D view always goes to the tool, and isn't
 * overridden by selectable tool hauling assignments.  This ensures that the user can drag
 * out an initial primitive shape, for example, before tweaking it with STH.
 * 
 */

        #define LXfTMOD_BRUSHRESET	 0x00002000
        #define LXfTMOD_INITAGAIN	 0x00004000
        #define LXfTMOD_NEEDSHAUL	 0x00008000
        #define LXfTMOD_ROLLOVERS	 0x00010000
        #define LXfTMOD_AUTORESET	 0x00020000
        #define LXfTMOD_HANDLERESET	 0x00040000
        #define LXfTMOD_DRAW_INACTIVE	 0x00080000

        #define LXfTMOD_I0_NOSELECT	 0x00100000
        #define LXfTMOD_I1_NOSELECT	 0x00200000

        #define LXfTMOD_AUTOACTIVATE	 0x00400000
        #define LXfTMOD_SELECTTHROUGH	 0x00800000

        #define LXfTMOD_NOCLONE		 0x01000000
        #define LXfTMOD_NODELTA		 0x02000000
        #define LXfTMOD_INDIRECT	 0x04000000

        #define LXfTMOD_NEEDFIRSTINPUT	 0x08000000


        #define LXfINITIALIZE_DIRECT	 0x01
        #define LXfINITIALIZE_EVENT	 0x02
        #define LXfINITIALIZE_AGAIN	 0x04
        #define LXfINITIALIZE_BRUSH	 0x08
        #define LXfINITIALIZE_PROCEDURAL 0x10

/*
 * This interface was retired in modo 14.2, and was replaced with an updated one
 * that adds the "AllowOverride" method.
 */

        #define LXu_TOOLMODEL4	"6E3DCFCE-F8BF-43EB-9D2E-617070574736"
        // [local]   ILxToolModel4
        // [export]  ILxToolModel4 tmod
        // [default] ILxToolModel4:Flags = LXfTMOD_DRAW_3D
        // [default] ILxToolModel4:Help  = 0
        // [default] ILxToolModel4:Haul  = 0
        // [default] ILxToolModel4:Tooltip = 0

/*
 * This interface was retired in modo 904, and was replaced with an updated one
 * that adds "adjust" argument to Filter method.
 */

        #define LXu_TOOLMODEL3	"27DB58F5-5C0C-4CF7-B064-6B07188E9813"
        // [local]   ILxToolModel3
        // [export]  ILxToolModel3 tmod
        // [default] ILxToolModel3:Flags = LXfTMOD_DRAW_3D
        // [default] ILxToolModel3:Help  = 0
        // [default] ILxToolModel3:Haul  = 0

/*
 * This interface was retired in modo 901, and was replaced with an updated one
 * that adds a method for tooltips.
 */

        #define LXu_TOOLMODEL2	"B70B1F15-137A-4716-A893-1AC416C547E9"
        // [local]   ILxToolModel2
        // [export]  ILxToolModel2 tmod
        // [default] ILxToolModel2:Flags = LXfTMOD_DRAW_3D
        // [default] ILxToolModel2:Help  = 0
        // [default] ILxToolModel2:Haul  = 0

/*
 * This interface was retired in modo 701, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXu_TOOLMODEL1	"EECE6570-AD5F-4190-AFA7-15067500454F"
        // [local]   ILxToolModel1
        // [export]  ILxToolModel1 tmod
        // [default] ILxToolModel1:Flags = LXfTMOD_DRAW_3D
        // [default] ILxToolModel1:Help  = 0
        // [default] ILxToolModel1:Haul  = 0

/*
 * This interface has an ID, but it's never used by the client since it's
 * not polymorphic with anything.
 */

        #define LXu_ADJUSTTOOL	"26E85301-8165-4FF3-AF26-392A03C9E1E7"
        // [local]  ILxAdjustTool


        #define	LXfNAV_HOT_POS			0x01
        #define	LXfNAV_HOT_ROT			0x02
        #define	LXfNAV_HOT_ZOOM			0x04


        #define LXu_NAVIGATIONLISTENER	"61724B7C-59DE-40F7-B260-8C71D8FE9710"
        // [export] ILxNavigationListener nav
        // [local]  ILxNavigationListener

#endif
