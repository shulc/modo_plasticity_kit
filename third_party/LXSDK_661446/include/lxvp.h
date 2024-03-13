/*
 * LX vp module
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
#ifndef LX_vp_H
#define LX_vp_H

typedef struct vt_ILxView3D ** ILxView3DID;
typedef struct vt_ILxGLViewport ** ILxGLViewportID;
typedef struct vt_ILxGLViewportClient ** ILxGLViewportClientID;
typedef struct vt_ILxView3DportService ** ILxView3DportServiceID;
typedef struct vt_ILxSimulationListener ** ILxSimulationListenerID;

#include <lxvalue.h>
#include <lxvector.h>
#include <lxtool.h>
#include <lxvp.h>
#include <lxhandles.h>



/*
 * -	LxResult Bounds (self, x, y, w, h)
 * 	Returns the upper left corner coordinates for the view, and its width and height
 * 	in pixels.
 * 
 * 
 * 
 * Background images in viewports a whole kettle of worms, enjoy.
 * -	LxResult Backdrop(self, item)
 * 	Returns the ILxItem for the image used by the specified view. Naturally,
 * 	this object must be released by the client when it is no longer needed.
 * 	If there is no image, LXe_NOTFOUND will be returned.
 * 
 * -	const char *BackdropName(self)
 * 	Returns the name of the image used by the specified view.
 * 	If there is no image it will be null.
 * 
 * -	LxResult BackdropPlace(self, x, y, w, h)
 * 	Returns the center position and dimensions of the backdrop image.
 * 	If there is no image, LXe_NOTFOUND will be returned.
 * 
 * -	int BackdropAspect(self, asp)
 * 	Returns the aspect ratio of the backdrop image, and whether the aspect is locked.
 * 	If there is no image, LXe_NOTFOUND will be returned.
 * 
 * -	int BackdropOrient(self, ang)
 * 	Returns the rotation and horizontal-flip state of the backdrop image.
 * 	If there is no image, LXe_NOTFOUND will be returned.
 * 
 * -	int BackdropLook(self, brit, cont, trans)
 * 	Returns the invert state and fills brightness, contrast, and transparency of the backdrop image.
 * 	If there is no image, LXe_NOTFOUND will be returned.
 * 
 * -	int BackdropRender(self, res, blend)
 * 	Returns the overlay state and fills resolution and pixel-blending of the backdrop image.
 * 	If there is no image, LXe_NOTFOUND will be returned.
 * 
 * 
 * 
 * -	double GridSize (self)
 * 	Returns the current grid size of the view.
 * -	int FrameRate(self)
 * 	Returns the frame rate of the view, meanng how quickly GL is drawing.  This is identical
 * 	to the results displayed in the viewport from the "glmeter" command.
 * 
 * 
 * These functions are to get item specific properties on the viewport. When "Enable Independent Drawing"
 * is enabled on the viewport, they returns the properties from "Draw Options" on the item.
 * -	LxResult ItemShade (self, item, shade)
 * 	Return the shading style (VPOPT_SHADE_XXX) of the given item.
 * 
 * -	LxResult ItemColor (self, item, color)
 * 	Returns the basic wireframe color and alpha of the item.
 * 
 * -	LxResult ItemSelColor (self, item, color)
 * 	Returns the wireframe color of the selected item. If the item is not
 * 	selected, it returs basic wireframe color.
 * 
 * -	LxResult ItemWireOverlay (self, item, color, wireframe)
 * 	Returns the wireframe overlay mode and the overlay color of the selected item.
 * 
 * 
 * -	LxResult Deformers (self)
 * 	Returns LXe_TRUE if "Deformers" stat of the view is ON, otherwise 
 * 	it returns LXe_FALSE.
 * 
 * -	LxResult ItemIsVisible (self, item)
 * 	Returns LXe_TRUE if the item is visible, otherwise it returns LXe_FALSE.
 * 
 * -	LxResult ToUVHit(self, x, y, u, v)
 * 	Sets the U and V for the ray hit for screen coordinate x,y.
 * 	Return LXe_OK if there is a hit, LXe_NOTFOUND if there is no hit.
 * 
 * 
 * -	LxResult InvalidateSurface(self, item)
 * 	Invalidate GL Draw Cache for an item. 
 */
typedef struct vt_ILxView3D {
        ILxUnknown	 iunk;
        LXxMETHOD(  LXtID4,
Space) (
        LXtObjectID		 self);


        LXxMETHOD(  int,
Axis) (
        LXtObjectID		 self,
        int 			*cam,
        LXtVector		 axis);

        LXxMETHOD(  LxResult,
Bounds) (
        LXtObjectID		 self,
        int			*x,
        int			*y,
        int			*w,
        int			*h);
        LXxMETHOD(  int,
Style) (
        LXtObjectID		 self,
        int			 option);
        LXxMETHOD(  double,
PixelSize) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
Center) (
        LXtObjectID		 self,
        LXtVector		 center);

        LXxMETHOD(  double,
EyeVector) (
        LXtObjectID		 self,
        LXtVector		 pos,
        LXtVector 		 dir);

        LXxMETHOD(  LxResult,
Matrix) (
        LXtObjectID		 self,
        LXtMatrix		 mat,
        int			 inverse);

        LXxMETHOD(  LxResult,
Angles) (
        LXtObjectID		 self,
        LXtVector		 hpb);

        LXxMETHOD(  int,
WorkPlane) (
        LXtObjectID		 self,
        LXtVector		 center);

        LXxMETHOD(  LxResult,
To3D) (
        LXtObjectID		 self,
        float			 x,
        float			 y,
        LXtVector		 pos,
        int			 flags);

        LXxMETHOD(  LxResult,
To3DHit) (
        LXtObjectID		 self,
        float			 x,
        float			 y,
        LXtVector		 pos,
        LXtVector		 nrm);
        LXxMETHOD(  LxResult,
Backdrop) (
        LXtObjectID		 self,
        void		       **item);

        LXxMETHOD(  const char*,
BackdropName) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
BackdropPlace) (
        LXtObjectID		 self,
        double			*cx,
        double			*cy,
        double			*w,
        double			*h);

        LXxMETHOD(  int,
BackdropAspect) (
        LXtObjectID		 self,
        double			*asp);

        LXxMETHOD(  int,
BackdropOrient) (
        LXtObjectID		 self,
        double			*ang);

        LXxMETHOD(  int,
BackdropLook) (
        LXtObjectID		 self,
        double			*brit,
        double			*cont,
        double			*trns);

        LXxMETHOD(  int,
BackdropRender) (
        LXtObjectID		 self,
        int			*resolution,
        int			*blend);
        LXxMETHOD(  int,
HitElement) (
        LXtObjectID		 self,
        LXtID4			 type,
        float			 x,
        float			 y,
        void		       **list);
        LXxMETHOD(  double,
GridSize) (
        LXtObjectID		 self);

        LXxMETHOD(  double,
FrameRate) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetMatrix) (
        LXtObjectID		self,
        const LXtMatrix		mat);

        LXxMETHOD(  LxResult,
SetCenter) (
        LXtObjectID		self,
        const LXtVector		vec);

        LXxMETHOD(  LxResult,
SetScale) (
        LXtObjectID		self,
        double			scl);
        LXxMETHOD(  LxResult,
ItemShade) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*shade);

        LXxMETHOD(  LxResult,
ItemColor) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        LXtFVector4		 color);

        LXxMETHOD(  LxResult,
ItemSelColor) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        LXtFVector4		 color);

        LXxMETHOD(  LxResult,
ItemWireOverlay) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        LXtFVector4		 color,
        unsigned		*wireframe);
        LXxMETHOD(  LxResult,
Deformers) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
ItemIsVisible) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD(  LxResult,
ToUVHit) (
        LXtObjectID		 self,
        const char		*name,
        float			 x,
        float			 y,
        unsigned		 layer,
        float			 *u,
        float			 *v);
        LXxMETHOD(LxResult,
InvalidateSurface) (
        LXtObjectID		 self,
        LXtObjectID		 item);
} ILxView3D;

/*
 * Initialize the new viewport object with the client interface.
 * 
 * Set the size of the GL area.
 * 
 * Call this to draw the viewport. The GL context must be set correctly.
 * 
 * Call this to process a mouse event.
 * 
 * Select the viewport, allowing the various view3d.??? commands to target it.
 * 
 * When performing drag and drop, clients can get the drop destination for
 * elements under the mouse. This will be a PreDest object that can be
 * queried for information about the drop destination.
 */
typedef struct vt_ILxGLViewport {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 client);
        LXxMETHOD(  LxResult,
SetSize) (
        LXtObjectID		 self,
        unsigned		 w,
        unsigned		 h);
        LXxMETHOD(  LxResult,
Draw) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
MouseEvent) (
        LXtObjectID		 self,
        unsigned		 event);
        LXxMETHOD(  LxResult,
SelectViewport) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
DropDestination) (
        LXtObjectID		  self,
        int			  x,
        int			  y,
        void			**ppvObj);
} ILxGLViewport;

/*
 * This is called by the GL viewport when it needs to redraw.
 * 
 * Return the current mouse position.
 * 
 * Return the current mouse button depressed.
 * 
 * Return the current pressure for stylus devices.
 * 
 * Return the current tilt for stylus devices.
 * 
 * Return the count associated with the last input event.  If it was a mouse button,
 * this is used to resolve double click (2) from single click (1).  For the scroll
 * wheel, this is the number of steps the wheel has turned since the last wheel event,
 * with positive numbers for one direction and negative for the other.
 */
typedef struct vt_ILxGLViewportClient {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Invalidate) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
MousePosition) (
        LXtObjectID		 self,
        int			*x,
        int			*y);
        LXxMETHOD(  LxResult,
MouseButton) (
        LXtObjectID		 self,
        unsigned		*button);
        LXxMETHOD(  LxResult,
TabletPressure) (
        LXtObjectID		 self,
        double			*press);
        LXxMETHOD(  LxResult,
TabletTilt) (
        LXtObjectID		 self,
        double			*tilt);
        LXxMETHOD(  LxResult,
MouseCount) (
        LXtObjectID		 self,
        int			*count);
} ILxGLViewportClient;

/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.
 * - ScriptQuery(self, sq)
 * 
 * The viewport service will provide access to a list of 3d and UV viewports
 * referenced by index.
 * - 	int Count(self)
 * 	Returns the number of viewports
 * 
 * - 	int Current(self)
 * 	Returns the most recently selected viewport's index
 * 
 * -	LxResult View(self, index, view)
 * 	Returns an ILxView3D for viewport at index. Naturally the client is responsible for
 * 	releasing the returned object.
 * 
 * - 	int Mouse(self, x, y)
 * 	Returns the index of the viewport currently under the mouse, or -1 if
 * 	the mouse is not over a 3D view. The position relative to that view is
 * 	fillde into x and y, if they are not NULL.
 * 
 * -	LxResult SetHitUVMap(self, name)
 * 	Sets the UV vertex map used for hit testing by tools. If the name is NULL,
 * 	then the hit vmap is cleared.
 * 
 * 
 * 
 * This function allocates a GL material object (ILxGLMaterial) with given bin, 
 * item and view objects.
 * 
 * Converts a ILxTriangleGroup into an ILxViewObject.
 * 
 * Converts an ILxImage object into a ILxGLImage object for drawing.
 * 
 * Allocate a GLViewport.
 * 
 * Adds an ILxVirtualModel for drawing into GL viewports.
 * 
 * Removes an ILxVirtualModel from GL viewports so it stops being drawn. If the
 * provided vmodel isn't currently being drawn, the function will do nothing.
 * 
 * Updates drawing for the provided virtual model.
 * 
 * Converts a ILxSurfaceID into an ILxViewObject.
 */
typedef struct vt_ILxView3DportService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  int,
Count) (
        LXtObjectID		 self);

        LXxMETHOD(  int,
Current) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
View) (
        LXtObjectID		 self,
        int			 index,
        void		       **ppvObj);

        LXxMETHOD(  int,
Mouse) (
        LXtObjectID		 self,
        int			*x,
        int			*y);

        LXxMETHOD(  LxResult,
SetHitUVMap) (
        LXtObjectID		 self,
        const char		*name);

        LXxMETHOD(  int,
InvalidateOverrider) (
        LXtObjectID		 self,
        LXtObjectID		 scene,
        const char		*pkgName);
        LXxMETHOD(  LxResult,
GLMaterial) (
        LXtObjectID		 self,
        LXtObjectID		 bin,
        LXtObjectID		 item,
        LXtObjectID		 view,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
TriGroupToViewObject) (
        LXtObjectID		  self,
        unsigned int		  type,
        LXtObjectID		  triGroup,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ImageToGLImage) (
        LXtObjectID		  self,
        LXtObjectID		  image,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
AllocGLViewport) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
AddVirtualModel) (
        LXtObjectID		  self,
        LXtObjectID		  vmodel);
        LXxMETHOD(  void,
RemoveVirtualModel) (
        LXtObjectID		  self,
        LXtObjectID		  vmodel);
        LXxMETHOD(  void,
UpdateVirtualModel) (
        LXtObjectID		  self,
        LXtObjectID		  vmodel);
        LXxMETHOD(  LxResult,
SurfaceToViewObject) (
        LXtObjectID		  self,
        unsigned int		  type,
        LXtObjectID		  item,
        void			**ppvObj);
} ILxView3DportService;

/*
 * These methods are called when the simulation mode starts and ends. The
 * start event is passed a ChannelRead object for reading the outputs of the
 * simulation.
 * Current time for the simulation is set here.
 * 
 * Any time the simulation has new results the listener clients are invalidated.
 */
typedef struct vt_ILxSimulationListener {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Start) (
        LXtObjectID		 self,
        LXtObjectID		 channels);

        LXxMETHOD(  LxResult,
End) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Time) (
        LXtObjectID		 self,
        double			 time);
        LXxMETHOD(  LxResult,
Invalidate) (
        LXtObjectID		 self);
} ILxSimulationListener;

/*
 * The application 3D and UV viewports are exposed as a list of ILxView3D objects. Clients
 * will generally find a view in the list, then use the ILxView3D interface to get its
 * specific properties.
 */

        #define LXu_VIEW3D		"02DBFE75-C1AB-4E23-A4C9-90508C7CD7C3"
        #define LXa_VIEW3D		"viewport3d"
        // [local] ILxView3D

/*
 * -	LXtID4 Space (self)
 * 	Returns the viewspace type of the view. It will be one
 * 	of the following for valid indices:
 */

        #define LXi_VPSPACE_MODEL		LXxID4('M','O','3','D')
        #define LXi_VPSPACE_TEXTURE		LXxID4('U','V','2','D')
        #define LXi_VPSPACE_WORLD		LXxID4('W','O','3','D')
        #define LXi_VPSPACE_PREVIEW		LXxID4('P','R','E','V')
        #define LXi_VPSPACE_MODEL2D		LXxID4('M','O','2','D')
        #define LXi_VPSPACE_GRAPH		LXxID4('V','P','G','E')
        #define LXi_VPSPACE_SCHEMATIC		LXxID4('S','C','H','M')

/*
 * -	int Axis (self, cam, axis)
 * 	Returns the view axis. Note that perspective views return -1, and that UV
 * 	views always return a Z axis. For convenience, the view's camera mode is also
 * 	provided. If it or the 'axis' vector pointers are NULL they will not be filled.
 */

        #define LXi_VP_AXIS_X		 0
        #define LXi_VP_AXIS_Y		 1
        #define LXi_VP_AXIS_Z		 2
        #define LXi_VP_AXIS_PERSP	-1
        #define LXi_VP_AXIS_UV		 LXi_VP_AXIS_Z

        #define LXi_VP_CAM_LEFT		0
        #define LXi_VP_CAM_RIGHT	1
        #define LXi_VP_CAM_TOP		2
        #define LXi_VP_CAM_BOTTOM	3
        #define LXi_VP_CAM_FRONT	4
        #define LXi_VP_CAM_BACK		5
        #define LXi_VP_CAM_PERSP	6

/*
 * The grab-bag of view styles is exposed with a deceptively simple
 * function that, in turn, depends on a vast and ragged matrix of options
 * and their potential values.
 * -	int Style (self, option)
 * 	Returns the state of the specified option for the specified view.
 * 	The option must be one of the LXi_VPSTYLE_* values, and the return state
 * 	will be the appropriate LXI_VPOPT_* value. For simple2-state options,
 * 	LXi_VPOPT_OFF and LXi_VPOPT_ON will be returned.
 * 
 */

enum {
        LXi_VPSTYLE_SHADE,
        LXi_VPSTYLE_WIRE,
        LXi_VPSTYLE_VCOLOR,
        LXi_VPSTYLE_SMOOTH,
        LXi_VPSTYLE_BACK,
        LXi_VPSTYLE_VERTS,
        LXi_VPSTYLE_CAGES,
        LXi_VPSTYLE_GUIDES,
        LXi_VPSTYLE_GRID,
        LXi_VPSTYLE_WPLANE,
        LXi_VPSTYLE_IMAGE,
        LXi_VPSTYLE_SELECT,
        LXi_VPSTYLE_SELNORM,
        LXi_VPSTYLE_SELFILL,
        LXi_VPSTYLE_SELBORD,
        LXi_VPSTYLE_SELROLL,
        LXi_VPSTYLE_OVERLAY,
        LXi_VPSTYLE_NULL,
};

        #define LXi_VPOPT_OFF			0
        #define LXi_VPOPT_ON 			1

        #define LXi_VPOPT_SHADE_WIRE		0
        #define LXi_VPOPT_SHADE_SKCH		1
        #define LXi_VPOPT_SHADE_VCLR		2
        #define LXi_VPOPT_SHADE_SHAD		3
        #define LXi_VPOPT_SHADE_TEXT		4
        #define LXi_VPOPT_SHADE_REFL		5
        #define LXi_VPOPT_SHADE_PRG1		6
        #define LXi_VPOPT_SHADE_PRG2		7

        #define LXi_VPOPT_WIRE_NONE	 	0
        #define LXi_VPOPT_WIRE_COLR	 	1
        #define LXi_VPOPT_WIRE_UNIF      	2

        #define LXi_VPOPT_VCLR_SEL		0
        #define LXi_VPOPT_VCLR_WGT		1
        #define LXi_VPOPT_VCLR_RGB		2

        #define LXi_VPOPT_BACK_WIRE		0
        #define LXi_VPOPT_BACK_FLAT		1
        #define LXi_VPOPT_BACK_ACTV     	2

/*
 * -	double PixelSize(self)
 * 	Returns the approximate size of a single pixel in model space units.
 * -	LxResult Center(self, center)
 * 	Returns the position vector for the center of the view.
 * -	double EyeVector(self, pos, dir)
 * 	Computes the gaze direction and distance for a point at 'pos' in the view.
 * 	The 'dir' vector is normalized, and the distance from eye to pos is returned by the function.
 * -	LxResult Matrix(self, matrix, inverse)
 * 	Returns the view transform matrix or its inverse.
 * -	LxResult Angles(self, hpb)
 * 	Returns the view transformation of the specified view as heading, pitch and bank angles.
 * 
 * -	int WorkPlane(self, center)
 * 	Returns the workplane center and axis
 * 
 * -	LxResult To3D(self, x, y, pos, axis, flags)
 * 	Returns position and nearest axis for the screen coordinates x,y.
 * 	The flag velues determine whether the position is snapped to the user
 * 	grid, and whether the workplane is used or not.
 * 
 * -	LxResult To3DHit(self, x, y, pos, nrm)
 * 	Sets the position and normal for the ray hit for screen coordinate x,y.
 * 	Return LXe_OK if there is a hit, LXe_NOTFOUND if there is no hit.
 * 
 * 
 */

        #define LXi_VPTO3D_SNAP		1
        #define LXi_VPTO3D_WORK     	2

/*
 * Raycasting to hit scene elements is facilitated at the viewport level and generalized
 * to use any 2D position on the view. Often the view and the position will be taken from the
 * mouse position.
 * -	int HitElement(self, type, x, y, list)
 * 	Returns the number of elements of the requested type along the eye
 * 	vector going through (x,y). The elements themselves are in the read-only
 * 	array of pointers returned in list. Type should be one of the following
 */

        #define LXi_VPHIT_VERT		LXxID4('V','E','R','T')
        #define LXi_VPHIT_EDGE		LXxID4('E','D','G','E')
        #define LXi_VPHIT_POLY		LXxID4('P','O','L','Y')
        #define LXi_VPHIT_ITEM		LXxID4('I','T','E','M')

/*
 * An item type can define a tag for a deferred update channel. This is an
 * integer channel that will be tested to see if deferred updates should be
 * done. Any non-zero int value enables deferred updates.
 */

        #define LXsPKG_DEFERRED_UPDATE		"pkg.deferredUpdate"

/*
 * The GLViewport object allows clients to get a fully domesticated GL viewport
 * of their own. The object is not associated with any on-screen viewport and
 * can be used with no nexus-native windows at all. Instead it represents GL
 * state that can draw and react to input.
 */

        #define LXu_GLVIEWPORT		"9F4D9937-FF49-45E4-9781-8085A9463661"
        // [local] ILxGLViewport


        #define LXiGLMOUSE_EVENT_TERMINATE	-1		// Terminate any current mouse input, reseting the state at the nexus level
        #define LXiGLMOUSE_EVENT_NONE		 0		// No-op, basically
        #define LXiGLMOUSE_EVENT_ENTER		 1		// Mouse entered the view
        #define LXiGLMOUSE_EVENT_LEAVE		 2		// Mouse left the view
        #define LXiGLMOUSE_EVENT_DOWN		 3		// Mouse button went down
        #define LXiGLMOUSE_EVENT_MOVE		 4		// Mouse moved, irrespective of if a button is down
        #define LXiGLMOUSE_EVENT_UP		 5		// Mouse button went up
        #define LXiGLMOUSE_EVENT_WHEEL		 6		// Mouse wheel rolled up or down
        #define LXiGLMOUSE_EVENT_MOD_KEY	 7		// Modifier key was pressed

/*
 * The client object allows the owner of the viewport to provide essential
 * information to the GL viewport, and to handle invalidation.
 */

        #define LXu_GLVIEWPORTCLIENT	"2975C75E-1F2C-4448-98BB-D3FA8ADF8595"
        // [export] ILxGLViewportClient glClient
        // [local]  ILxGLViewportClient


        #define LXiGLMOUSE_BUTTON_NONE		0
        #define LXiGLMOUSE_BUTTON_LEFT		1
        #define LXiGLMOUSE_BUTTON_RIGHT		2
        #define LXiGLMOUSE_BUTTON_MIDDLE	3


        #define LXu_VIEW3DPORTSERVICE	"D84FF812-E4E9-41DC-B82F-B550ACF2E40A"
        #define LXa_VIEW3DPORTSERVICE	"view3dservice"

/*
 * This global listener can be used to track the state changes related to
 * interactive simulation.
 */

        #define LXu_SIMULATIONLISTENER	"628A3377-C56B-4801-878C-8BF87A097D29"
        #define LXa_SIMULATIONLISTENER	"simulationlistener"
        // [local]  ILxSimulationListener

#endif
