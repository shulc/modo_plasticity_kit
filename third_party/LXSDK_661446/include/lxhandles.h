/*
 * LX handles module
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
#ifndef LX_handles_H
#define LX_handles_H

typedef struct vt_ILxShapeDraw ** ILxShapeDrawID;
typedef struct vt_ILxHandleDraw ** ILxHandleDrawID;
typedef struct vt_ILxHandleDraw1 ** ILxHandleDraw1ID;
typedef struct vt_ILxEventTranslatePacket ** ILxEventTranslatePacketID;
typedef struct vt_ILxEventTranslatePacket1 ** ILxEventTranslatePacket1ID;
typedef struct vt_ILxEventGuide ** ILxEventGuideID;
typedef struct vt_ILxGeoConstraintPacket ** ILxGeoConstraintPacketID;

#include <lxcom.h>
#include <lxresult.h>
#include <lxvalue.h>
#include <lxvector.h>
#include <lxidef.h>
#include <lximage.h>



/*
 * - Circle
 * This method draws a circle defined by the 'rad' argument, centered at 'pos'.
 * - Ellipse
 * This method is just a circle with a radius vector whose element along the axis is ignored.
 * - Pill
 * This method is a rectangle with rounded corners defined by the 'rad' argument, centered at 'pos'. If the radius of the corners is too large compared with the height or width of the rectangle then it will be adjusted.
 * - Bone
 * The bone is a double pyramid.
 * - Arc
 * This method draws a section of a circle between angles given by start and end.
 * 
 * - Plane
 * This method draws a wireframe plane defined by the size vector and the axis at centered 'pos'.
 * 
 * - Ellipsoid
 * This method draws a wireframe ellipsoid defined by the radius vector at centered 'pos'.
 * 
 * - Cube
 * This method draws a wireframe cube defined by by the size vector and the axis at centered 'pos'.
 * 
 * - CubeFill
 * This method draws a cube with filled faces.
 * 
 * - BoxShape
 * This method draws a wireframe box by by the size vector with filled faces.
 * 
 * - Pyramid
 * This method draws a wireframe pyramid defined by by the size vector and the axis at centered 'pos'.
 * 
 * - PyramidShape
 * This method draws a wireframe pyramid with filled faces.
 * 
 * - Rhombus
 * This method draws a wireframe rhombus defined by by the size vector and the axis at centered 'pos'.
 * 
 * - RhombusShape
 * This method draws a wireframe rhombus with filled faces.
 * 
 * - Cone
 * This method draws a wireframe cone defined by by the radius, the height and the axis at centered 'pos'.
 * 
 * - ConeShape
 * This method draws a wireframe cone with filled faces.
 * 
 * - Cylinder
 * This method draws a wireframe cylinder defined by by the radius, the height and the axis at centered 'pos'.
 * 
 * - CylinderShape
 * This method draws a wireframe cylinder with filled faces.
 * 
 * - SphereShape
 * This method draws a wireframe sphere by the radius and the axis at centered 'pos' with filled faces.
 * 
 * - CircleShape
 * This method draws a wireframe circle by the radius and the axis at centered 'pos' with filled faces.
 * 
 * - PlaneShape
 * This method draws a wireframe plane with filled faces.
 * 
 * - RadialMap
 * - RadialRays
 * These methods renders a greyscale image map of radius values vs theta and phi spherical coordinates.
 * 
 * - Link
 * This method draws a line from 'posS' to 'posE' with point at the ends. If 'solid' is false, a dashed line is drawn.
 * 
 * - BBox
 * This method draws a wireframe lines of bounding box at each corners defined by 'size' at the origin.
 * 
 * - Arrow
 * This method draws a arrow defined along the axis, centered at 'pos'.
 * 
 * - Axis
 * This method draws a set of three arrows along the principal axes.
 * 
 * - Star
 * This method draws a star shape defined in the radius, centered at 'pos'.
 * 
 * - Cross
 * This method draws a cross defined by the radius, centered at 'pos'.
 * 
 * - Line
 * This method draws a line in the virtual model space from 'v0' to 'v1'.
 * 
 * - CSeg
 * This method draws a line in the virtual model space centered at cen and extending in both directions along offset. If in screen space, draw relative.
 * 
 * - PlaneIndicator
 * This method draws a plane indicator defined by the radius and the axis, centered at 'pos'.
 * 
 * - CrossHair
 * This method draws a screen-space crosshairs style reticle. The size is approximately in grid units.
 * 
 * - PreciseHandle
 * This method draws cross lines defined by 'the size vectors, centered at 'pos' along axes.
 * 
 * 
 * 
 */
typedef struct vt_ILxShapeDraw {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Circle) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double 		         alpha,
        const LXtVector		 pos,
        double			 rad,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Ellipse) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double		         alpha,
        const LXtVector		 pos,
        const LXtVector		 rad,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Pill) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double			 alpha,
        const LXtVector		 pos,
        double			 width,
        double			 height,
        double			 rad,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Bone) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double			 rlen,
        int			 active);

        LXxMETHOD( void,
Arc) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double			 alpha,
        const LXtVector		 pos,
        double			 rad,
        double			 start,
        double			 end,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Plane) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Ellipsoid) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double			 alpha,
        const LXtVector		 pos,
        const LXtVector		 rad,
        int			 flags);

        LXxMETHOD( void,
Cube) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 flags);

        LXxMETHOD( void,
CubeFill) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double			 alpha,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 flags);

        LXxMETHOD( void,
BoxShape) (
        LXtObjectID		 self,
        const LXtVector		 colW,
        const LXtVector		 colF,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 flags);

        LXxMETHOD( void,
Pyramid) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
PyramidShape) (
        LXtObjectID		 self,
        const LXtVector		 colW,
        const LXtVector		 colF,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Rhombus) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
RhombusShape) (
        LXtObjectID		 self,
        const LXtVector		 colW,
        const LXtVector		 colF,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Cone) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        double			 rad,
        double			 height,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
ConeShape) (
        LXtObjectID		 self,
        const LXtVector		 colW,
        const LXtVector		 colF,
        const LXtVector		 pos,
        double			 radius,
        double			 height,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Cylinder) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        double			 rad,
        double			 height,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
CylinderShape) (
        LXtObjectID		 self,
        const LXtVector		 colW,
        const LXtVector		 colF,
        const LXtVector		 pos,
        double			 radius,
        double			 height,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
SphereShape) (
        LXtObjectID		 self,
        const LXtVector		 colW,
        const LXtVector		 colF,
        const LXtVector		 pos,
        double			 radius,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
CircleShape) (
        LXtObjectID		 self,
        const LXtVector		 colW,
        const LXtVector		 colF,
        const LXtVector		 pos,
        double			 radius,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
PlaneShape) (
        LXtObjectID		 self,
        const LXtVector		 colW,
        const LXtVector		 colF,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
RadialMap) (
        LXtObjectID		 self,
        LXtObjectID		 image,
        const LXtVector		 col,
        const LXtVector		 cen,
        double			 size,
        int			 sel,
        int			 flags);

        LXxMETHOD( void,
RadialRays) (
        LXtObjectID		 self,
        LXtObjectID		 image,
        const LXtVector		 col,
        const LXtVector		 cen,
        double			 size,
        int			 sel,
        int			 flags);

        LXxMETHOD( void,
Link) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 posS,
        const LXtVector		 posE,
        int			 solid,
        int			 flags);

        LXxMETHOD( void,
BBox) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double			 size,
        int			 flags);

        LXxMETHOD( void,
Arrow) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        double			 size,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Axis) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 flags);

        LXxMETHOD( void,
Star) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        const LXtVector		 rad,
        int			 flags);

        LXxMETHOD( void,
Cross) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        const LXtVector		 rad,
        int			 flags);

        LXxMETHOD( void,
Line) (
        LXtObjectID		 self,
        const LXtVector		 v0,
        const LXtVector		 v1,
        const LXtVector		 col,
        double		         alpha,
        int			 flags);

        LXxMETHOD( void,
CSeg) (
        LXtObjectID		 self,
        const LXtVector		 cen,
        const LXtVector		 offset,
        double			 screen,
        const LXtVector		 col,
        int			 flags);

        LXxMETHOD( void,
PlaneIndicator) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double			 alpha,
        const LXtVector		 pos,
        double			 rad,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
CrossHair) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double			 alpha,
        const LXtVector		 pos,
        int			 flags);

        LXxMETHOD( void,
PreciseHandle) (
        LXtObjectID		 self,
        const LXtVector		 col,
        double			 alpha,
        const LXtVector		 pos,
        const LXtVector		 size,
        int			 flags);

        LXxMETHOD( void,
Ruler) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        const LXtMatrix		 xfrm,
        double			 len,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Distance) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        double			 dist,
        int			 axis,
        int			 flags);

        LXxMETHOD( void,
Dimension) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 A,
        const LXtVector		 B,
        const char		*format,
        int 			 top,
        int			 flags);

        LXxMETHOD( void,
Grid) (
        LXtObjectID		 self,
        const LXtVector		 col,
        const LXtVector		 pos,
        const LXtVector		 siz,
        int			 divX,
        int			 divY,
        int			 divZ,
        int			 axis,
        int			 flags);
} ILxShapeDraw;

/*
 * All the 3D handles take a 'mat' argument, if a local space transformation is known for an item or selection then the matrix can be passed to these functions. The directions to draw the handle will then be taken directly from the matrix. If this argument is NULL then the handles will be drawn in world/model space.
 * - Handle
 * This method draws the most basic type of tool handle, a filled box. It will be drawn in the color specified by the user for handles. If the matrix is NULL, it will be ignored.
 * - AxisHandle
 * This method is similar to the generic box handle above but has a line of length 'len' drawn from 'pos' in the direction of the specified axis. The box handle itself is drawn at the end of the line and will be color coded to the axis it represents.
 * - MoveHandle
 * This method draws axis arrows to indicate the direction of the handle constraint. The length of the arrow is determined by user settings for handle size and the color by the axis it represents.
 * - RotateHandle
 * - RotateMouseHandle
 * Rotation handles are rings drawn on the plane specified by the 'pos' and 'axis' arguments. To help to make their orientation clearer the rings can be drawn with 'back face' removal by setting the 'facing' argument. The rings are color coded to the axis. The two angle arguments, if set, will draw a semi-transparent pie segment to indicate an angle on the plane, to disable this set both angle arguments to the same value.
 * 
 * - ScaleHandle
 * Scale handles are similar to the axis handles but have a solid axis line and an optional 'offset' argument. This provides the ability to draw a semi-transparent box along the axis to indicate the delta move of the handle, set the offset to zero to disable this. Turn off 'line' if you do not need the axis line.
 * 
 * - CrossHandle
 * For handles requiring precise placement the following function will draw a set of cross-hairs at the specified position. They will be drawn in the color set by the user for handles.
 * 
 * - PointHandle
 * The point handle is a single point rendered as a flat square. It is recommended for handles which directly control vertices and will be drawn in the color specified by the user for handles.
 * 
 * - XHandle
 * This alternative cross-hairs design is used to target things (curve points) for destruction.
 * 
 * - PlaneHandle
 * This method draws the planar handles used for the move and scale tools.
 * 
 * - LineHandleHilight
 * This method draws a line in the given direction to indicate that the handle 
 * is being used with a linear constraint.
 * 
 * - PlaneHandleHilight
 * For handles being used with planar constraints the following function will
 * draw a disc style indicator on the plane specified by the 'norm' argument.
 * 
 * 
 */
typedef struct vt_ILxHandleDraw {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Handle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
AxisHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        double			 len,
        int			 flags);

        LXxMETHOD( void,
MoveHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
RotateHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        double			 sAngle,
        double			 eAngle,
        int			 facing,
        int			 flags);

        LXxMETHOD( void,
RotateMouseHandle) (
        LXtObjectID		 self,
        const LXtVector		 center,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
ScaleHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        double			 offset,
        int			 line,
        int			 flags);

        LXxMETHOD( void,
CrossHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
PointHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
XHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
PlaneHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
LineHandleHilight) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtVector		 dir,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
PlaneHandleHilight) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtVector		 norm,
        int			 part,
        int			 flags);
} ILxHandleDraw;

typedef struct vt_ILxHandleDraw1 {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Handle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
AxisHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        double			 len,
        int			 flags);

        LXxMETHOD( void,
MoveHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
RotateHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        double			 sAngle,
        double			 eAngle,
        int			 facing,
        int			 flags);

        LXxMETHOD( void,
RotateMouseHandle) (
        LXtObjectID		 self,
        const LXtVector		 center,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
ScaleHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        double			 offset,
        int			 line,
        int			 flags);

        LXxMETHOD( void,
CrossHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
PointHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
XHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
PlaneHandle) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtMatrix		 mat,
        int			 axis,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
LineHandleHilight) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtVector		 dir,
        int			 part,
        int			 flags);

        LXxMETHOD( void,
PlaneHandleHilight) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtVector		 norm,
        int			 part,
        int			 flags);
} ILxHandleDraw1;

/*
 * The event translation interface performs the translation of 'raw' 2D input events to 'cooked'
 * 3D events. Because this translation will vary depending on the type of tool, and its current
 * attributes, it must be handled by an object packet whose methods are called by tools as needed.
 * Constraint modifier tools can participate in tool input by replacing this object with one of
 * their own (possibly calling the original object methods and modifying their results).
 * - ToModel
 * This function will convert the raw event data in the tool vectors LXpToolEvent packet into
 * a model-space 3D position in the 'pos' argument. It returns the index of the primary axis chosen
 * for the event, and fills 'axis'.  While the axis vector may not be on a principal plane, the index
 * returned must be in 0-2, representing the nearest principal direction to the axis vector.
 * Some Snapping-type modifiers may return this value snapped to some position, and generate zero deltas
 * on moves.
 * - ToModelLine
 * This method does the 2D-to-3D conversion with the added constraint that the result position must
 * lie on the model-space line passing through 'center' in the (normalized) direction 'dir'.
 * - ToModelPlane
 * This method does the 2D-to-3D conversion with the constraint that the result position
 * will lie in the model-space plane containing the point 'center' and perpendicular to 'normal'.
 * 
 * 
 * Converting mouse moves to 3D delta vectors requires some information beyond that
 * used for simple position conversion. Specifically, the deltas will be based on an
 * existing handle position which may be independent of the constraining line or plane.
 * - ModelDelta
 * This function calculates the 3D position offset from the mouse-down position. If 'handle'
 * is not NULL, the implicit constraint plane will be centered at  the level of handle. Otherwise
 * the quantized view center is used. To compute a full handle position it is important to use the sum
 * of this delta and the original ToModel position, since some snapping-type modifiers will generate
 * zero deltas for locked moves.
 * 
 * - ModelLineDelta
 * This function calculates a 3D delta constrained to the line given, from the 2D mouse input.
 * 
 * - ModelPlaneDelta
 * This function calculates a 3D delta constrained to the line given, from the 2D mouse input.
 * 
 * 
 * Many input events are organized by the client to maintain the handle state and position
 * through the down-move-up mouse input cycle.  These methods will also take this approach,
 * hopefully sparing tool makers some duplicated effort.
 * - HitHandle
 * The client establishes the handle that will be manipulated with this function, usually during
 * the mouse down event.
 * 
 * - GetNewPosition
 * This function lets the client find the handle position on mouse move events.
 * 
 * 
 * 
 * - ScreenToRay
 * This method converts any given screen coordinates into ray vectors (pos and dir).
 * 
 * Handling snapping and constraining within event translation allows tools to offer
 * layered, context-aware 'guides' to the user. Event translation coordinates
 * multiple snapping/constraining options added by multiple tools in the tool pipe.
 * 
 * - AddGuide
 * This method allows event translation clients to add dynamic constraints to the ET system.
 * The guide is an ILxEventGuide object.
 * 
 * - RemoveGuide
 * This method removes the guide previously added by a client. It returns 0 if the guide was not present.
 * 
 * - SetLinearSnapConstraint
 * This is same as SetLinearConstraint except linear snapping. Linear snapping is available along the
 * given vector.
 * 
 * 
 * - SetPlaneSnapConstraint
 * This is same as SetPlaneConstraint except linear snapping. Linear snapping is available along the
 * given vector.
 * 
 * 
 * 
 */
typedef struct vt_ILxEventTranslatePacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
ToModel) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        LXtVector		 pos,
        LXtVector		 axis);

        LXxMETHOD(  void,
ToModelLine) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 dir,
        LXtVector		 pos);

        LXxMETHOD(  void,
ToModelPlane) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 normal,
        LXtVector		 pos);

        LXxMETHOD(  void,
ModelDelta) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 handle,
        LXtVector		 delta);

        LXxMETHOD(  void,
ModelLineDelta) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 dir,
        const LXtVector		 handle,
        LXtVector		 delta);

        LXxMETHOD(  void,
ModelPlaneDelta) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 normal,
        const LXtVector		 handle,
        LXtVector		 delta);

        LXxMETHOD(  void,
HitHandle) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 handle);

        LXxMETHOD(  void,
GetNewPosition) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        LXtVector		 pos);
        LXxMETHOD(  void,
SetLinearConstraint) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 dir);

        LXxMETHOD(  void,
SetPlanarConstraint) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 normal);

        LXxMETHOD(  int,
GetConstraint) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        LXtVector		 center,
        LXtVector		 vector);

        LXxMETHOD(  void,
SetSnapRange) (
        LXtObjectID		 self,
        double			 inner,
        double			 outer);
        LXxMETHOD(  void,
ScreenToRay) (
        LXtObjectID 		 self,
        LXtObjectID		 toolVector,
        float       		 x,
        float       		 y,
        LXtVector   		 pos,
        LXtVector   		 dir);
    LXxMETHOD(  void,
AddGuide) (
        LXtObjectID 		 self,
        LXtObjectID		 guide,
        void       		*client);

    LXxMETHOD(  int,
RemoveGuide) (
        LXtObjectID 		 self,
        LXtObjectID		 guide,
        void       		*client);
        LXxMETHOD(  void,
SetLinearSnapConstraint) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 dir);
        LXxMETHOD(  int,
SnapPosition) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 pos,
        LXtVector		 snapPos);
        LXxMETHOD(  void,
SetPlanarSnapConstraint) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 dir);
} ILxEventTranslatePacket;

typedef struct vt_ILxEventTranslatePacket1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
ToModel) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        LXtVector		 pos,
        LXtVector		 axis);

        LXxMETHOD(  void,
ToModelLine) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        LXtVector		 center,
        LXtVector		 dir,
        LXtVector		 pos);

        LXxMETHOD(  void,
ToModelPlane) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        LXtVector		 center,
        LXtVector		 normal,
        LXtVector		 pos);

        LXxMETHOD(  void,
ModelDelta) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 handle,
        LXtVector		 delta);

        LXxMETHOD(  void,
ModelLineDelta) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 dir,
        const LXtVector		 handle,
        LXtVector		 delta);

        LXxMETHOD(  void,
ModelPlaneDelta) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 normal,
        const LXtVector		 handle,
        LXtVector		 delta);

        LXxMETHOD(  void,
HitHandle) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        LXtVector		 handle);

        LXxMETHOD(  void,
GetNewPosition) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        LXtVector		 pos);

        LXxMETHOD(  void,
SetLinearConstraint) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 dir);

        LXxMETHOD(  void,
SetPlanarConstraint) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 normal);

        LXxMETHOD(  int,
GetConstraint) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        LXtVector		 center,
        LXtVector		 vector);

        LXxMETHOD(  void,
SetSnapRange) (
        LXtObjectID		 self,
        double			 inner,
        double			 outer);

        LXxMETHOD(  void,
ScreenToRay) (
        LXtObjectID 		 self,
        LXtObjectID		 toolVector,
        float       		 x,
        float       		 y,
        LXtVector   		 pos,
        LXtVector   		 dir);

    LXxMETHOD(  void,
AddGuide) (
        LXtObjectID 		 self,
        LXtObjectID		 guide,
        void       		*client);

    LXxMETHOD(  int,
RemoveGuide) (
        LXtObjectID 		 self,
        LXtObjectID		 guide,
        void       		*client);
} ILxEventTranslatePacket1;

typedef struct vt_ILxEventGuide {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
Limits) (
        LXtObjectID 		 self,
        double			 inner,
        double			 outer);

        LXxMETHOD(  int,
Proximity) (
        LXtObjectID 		 self,
        LXtObjectID		 toolVector,
        LXtVector	 	 pos,
        double			*dist,
        int       		*priority,
        void			*element);

        LXxMETHOD(  int,
SetDrawState) (
        LXtObjectID		 self,
        int			 flags);

        LXxMETHOD(  void,
SetFlags) (
        LXtObjectID		 self,
        int			 flags);

        LXxMETHOD(  int,
Flags) (
        LXtObjectID		 self);
} ILxEventGuide;

/*
 * - PointConstrain
 * This method moves this given position to a constrained position.
 * - VectorConstrain
 * This method This would add delta to pos unless it hit a constraint along that vector which
 * would clamp the magnitude of delta.
 * - Flags
 * This returns the current flags. Now GEOCONS_POINT or GEOCONS_VECTOR is available.
 * - ModeMaskSet
 * The effector tool would specify the mode which it uses as a mask.
 * 
 * 
 * 
 * 
 */
typedef struct vt_ILxGeoConstraintPacket {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
PointConstrain) (
        LXtObjectID		 self,
        LXtVector		 pos,
        const LXtVector		 delta);
        LXxMETHOD( LxResult,
VectorConstrain) (
        LXtObjectID		 self,
        LXtVector		 pos,
        const LXtVector		 delta);
        LXxMETHOD( int,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD( void,
ModeMaskSet) (
        LXtObjectID		 self,
        int			 mask);
} ILxGeoConstraintPacket;


        #define LXfVDRAW_MASK		 (0xFF<<24)
        #define LXfVDRAW_FILL		 (1<<31)
        #define LXfVDRAW_DASH		 (1<<30)
        #define LXfVDRAW_CUSTOM0	 (1<<24)
        #define LXfVDRAW_CUSTOM1	 (1<<25)
        #define LXfVDRAW_CUSTOM2	 (1<<26)
        #define LXfVDRAW_CUSTOM3	 (1<<23)


        #define LXfVDRAW_AXARROW	 LXfVDRAW_CUSTOM0


        #define LXu_SHAPEDRAW		"DC46A7E2-2849-46CE-9075-2394E04EB3AE"
        // [local]  ILxShapeDraw


        #define LXi_THANDf_SMALL	(1<<16)
        #define LXi_THANDf_HOT		(1<<17)
        #define LXi_THANDf_HIT		(1<<18)
        #define LXi_THANDf_CONST	(1<<19)
        #define LXi_THANDf_GHOST	(1<<20)
        #define LXi_THANDf_FLIP		(1<<21)
        #define LXi_THANDf_DISABLE	(1<<22)

        #define LXi_THANDf_AXES		(3<<24)
        #define LXi_THANDf_AXIS_X	(1<<24)
        #define LXi_THANDf_AXIS_Y	(2<<24)
        #define LXi_THANDf_AXIS_Z	(3<<24)
        #define LXi_THANDv_AXIS(f)	((((f) & LXi_THANDf_AXES) >> 24) - 1)

        #define LXi_THANDv_MASK		(0xFFFF)

/*
 * The following methods provide methods to draw the standard tool handles.
 */

        #define LXu_HANDLEDRAW		"502ACBC8-ADFB-4493-828C-3D2EC423051B"
        // [local] ILxHandleDraw

/*
 * This interface was retired in Modo 11.1 for bug 55147.
 */

        #define LXu_HANDLEDRAW1		"EEC6665A-BB44-48A4-8F8C-B4BCDF2ED880"
        // [local] ILxHandleDraw1

/*
 * The active handle can be constrained to move along client-defined lines or
 * planes.  Removing all constraints requires reinitializing the handle with
 * HitHandle().
 * - SetLinearConstraint
 * Constrain handle to the line passing through 'center' and along direction 'dir'.
 * - SetPlanarConstraint
 * Constrain handle to the plane passing through 'center' and perpendicular to 'normal'.
 * 
 * - GetConstraint
 * This function returns the current constraint by filling 'center' and 'vector' with the
 * center and the normal(/direction) of the planar(/linear) constraint. It returns one of the
 * following types:
 * 
 */

        #define LXi_EVTRAN_CONSTRAIN_NONE		0
        #define LXi_EVTRAN_CONSTRAIN_LINE		1
        #define LXi_EVTRAN_CONSTRAIN_PLANE		2
        #define LXm_EVTRAN_CONSTRAIN_AXIS		0x0f
        #define LXm_EVTRAN_CONSTRAIN_SNAP		0x10
        #define LXf_EVTRAN_CONSTRAIN_SNAP_LINE		(LXm_EVTRAN_CONSTRAIN_SNAP|LXi_EVTRAN_CONSTRAIN_LINE)
        #define LXf_EVTRAN_CONSTRAIN_SNAP_PLANE		(LXm_EVTRAN_CONSTRAIN_SNAP|LXi_EVTRAN_CONSTRAIN_PLANE)

/*
 * - SetSnapRange
 * This function sets the inner and outer ranges (in pixels) for snapping.
 * -- NOT IMPLEMENTED --
 * - SetSnap
 * This function allows the client to specify the degree/type of snapping for the 'current'
 * handle by setting flag bits to mask off different types of snapping and constraint.
 * These flags will serve as hints to upstream event processors. The NOSNAP flag prevents snapping
 * to elements, NOQUANT prevents snapping to a spatial quantization, like a grid, and
 * NOCONST stops 'snapping' along continuous constraints.   At the moment it is not clear what
 * value these distinctions have.
 */

        #define LXf_EVTRAN_SNAPS		0
        #define LXf_EVTRAN_NOSNAP		1
        #define LXf_EVTRAN_NOQUANT		2
        #define LXf_EVTRAN_NOCONST		4
        #define LXf_EVTRAN_UNSNAPPED		(LXf_EVTRAN_NOSNAP|LXf_EVTRAN_NOQUANT|LXf_EVTRAN_NOCONST)

/*
 * This interface was retired in modo 701, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXu_EVENTTRANSLATEPACKET1	"81B7CACE-DB90-4AD7-AE93-42C23E62130D"
        // [local] ILxEventTranslatePacket1

/*
 * - Limits
 * This function sets inner and outer limits for the constraint range. These limits are
 * a property of the environment, either set in the toolpipe, or taken from a user preference.
 * The flags returned specify the type of constraint. Constraining to both a point
 * and a line is assumed to be a constraint to a point, a.k.a. a snap.
 */

        #define LXf_GUIDE_LINE		1
        #define LXf_GUIDE_PLANE		2
        #define LXf_GUIDE_POINT		(LXf_GUIDE_PLANE | LXf_GUIDE_LINE)
        #define LXf_GUIDE_SNAP		LXf_GUIDE_POINT

/*
 * - Proximity
 * This function evaluates the constraint for the current event and tells whether the guide is
 * active, returning zero for inactive / out-of-range guides. Non-zero returns are composed of
 * bit flags declaring which axis or axes of motion are constrained. It also returns the distance
 * of the event to the constraint as a metric for choosing among competing guides. It also returns
 * the priority for the constraint, and the position to use should the constraint be selected. If
 * a mesh element is used by the guide, it will be returned in 'element'. The 'pos' argument must be
 * initialized with the raw 3d event position.
 */

        #define LXf_GUIDE_SNAP_NONE	0
        #define LXf_GUIDE_SNAP_AXIS_X	1 //  (1<<0)
        #define LXf_GUIDE_SNAP_AXIS_Y	2 //  (1<<1)
        #define LXf_GUIDE_SNAP_AXIS_Z	4 //  (1<<2)
        #define LXf_GUIDE_SNAP_ALLAXES	7 //  (LXf_GUIDE_AXIS_X | LXf_GUIDE_AXIS_Y | LXf_GUIDE_AXIS_Z)

/*
 * - SetDrawState
 * Since drawing the guide in the interface must be done within the tool draw cycle, it is the responsibility
 * of guides creator to draw it based on the drawing state set by ET. There are two drawing states,
 * specified by the flags argument. The 'suggest' mode draws the guide before the user has selected a guide,
 * the 'chosen' mode draws the guide as it should appear when that constraint is being used by the tool.
 * 
 */

        #define LXi_GUIDE_OFF		0
        #define LXi_GUIDE_SUGGEST	1
        #define LXi_GUIDE_CHOSEN	2

/*
 * - SetFlags, Flags
 * This function sets and returns the current flags of the guide.
 * 'ALWAYS' is to enable the guide even if the global snap state is off.
 */

        #define LXi_GUIDE_FLAGS_NONE	0x00
        #define LXi_GUIDE_FLAGS_ALWAYS	0x01


        #define LXu_EVENTTRANSLATEPACKET	"4D50C150-8681-4F4A-91E9-E730C4D1173A"
        #define LXu_EVENTGUIDE			"B2A11425-25DE-4628-839C-995020BD8DF1"
        #define LXsP_TOOL_EVENTTRANS		"toolEventTranslate"
        // [local] ILxEventTranslatePacket
        // [local] ILxEventGuide


        #define LXf_GEOCONS_POINT		0x01
        #define LXf_GEOCONS_VECTOR		0x02


        #define LXu_GEOCONSTRAINTPACKET		"0589BA62-5A11-453d-B84A-1C7CF30A0D35"



        // Area light shapes
        #define	LXi_AREALIGHT_SHAPE_RECTANGLE	0
        #define	LXi_AREALIGHT_SHAPE_ELLIPSE		1

#endif
