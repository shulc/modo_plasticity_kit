/*
 * LX draw module
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
#ifndef LX_draw_H
#define LX_draw_H

typedef struct vt_ILxView ** ILxViewID;
typedef struct vt_ILxStrokeDraw ** ILxStrokeDrawID;
typedef struct vt_ILxGLMaterial ** ILxGLMaterialID;
typedef struct vt_ILxGLImage ** ILxGLImageID;

#include <lxcom.h>
#include <lxvmath.h>



/*
 * - Type
 * This method returns the type of the view.
 * - Center
 * This method returns the center vector of the view.
 * - Scale
 * This method returns the scale of the view.
 * - PixelScale
 * The view can also be queried for the approximate mapping to the screen.
 * This returns the distance in model space that corresponds to one pixel of
 * screen space.
 * - Aspect
 * Aspect affects only the absolute SCREEN view type and it returns the width
 * of the mapped port relative to the height.
 * 
 * - Matrix
 * - InvMatrix
 * The matrix is used to rotate perspective and camera views, and it reads
 * the matrix.  The inverse matrix can also be read.
 * 
 * - Ortho
 * Orthogonal views are defined by a view direction and spin, which is 0 to 3
 * 90-degree turns around the center point to orient the view on screen.  This
 * method reads the current index and spin.
 * 
 * - Axis
 * The orthogonal views all have an axis perpendicular to the screen which can
 * be derived from the view indices defined above. For convenience, this function
 * returns that axis (0==X, 1==Y, 2==Z) if possible, or returns -1 for
 * non-orthogonal views.
 * 
 * - Zoom
 * Camera views have a zoom factor which is separate from the view scale.  It
 * is equivalent to the focal length divided by half the aperture width.  In
 * non-oriented perspective views the zoom is used to control the perspective
 * distortion.
 * 
 * - Focal
 * This function returns the focal length and focal distance for camera views.
 * 
 * - ToScreen
 * This method takes a 3D model coordinate as input and returns the X and
 * Y screen position relative to the pane.  The first top-left pixel on the
 * GL pane is (0, 0).  It returns false if the point is not visible in the
 * viewport.
 * 
 * - ToScreen3
 * Another form can compute 3D screen coordinates, where Z is the view-depth
 * which increases as the point moves behind other points.
 * 
 * - ToModel
 * This method does the reverse, taking a screen position and returning
 * the 3D model coordinate under it.  Since the model vector is
 * underdetermined, the vector returned is the one model-space position
 * at that point on the screen that is closest to the initial value of the
 * vector.  If 'snap' is true, then the return value will be snapped to the
 * nearest nice location given by the grid snap for the view.
 * 
 * - ScreenNormals
 * This returns the three axes normal to the given model position in screen space.
 * The axes are unit vectors that point right, up, and out, respectively.  The
 * function raises an assertion if the transformation is singular for any
 * reason.
 * 
 * - EyeVector
 * This returns a unit eye vector for the given point.  This is the direction
 * of gaze in model coordinates from the virtual eye point to the given model
 * position.  For perspective views this will focus at a specific point in
 * space, but for orthogonal view it'll be a uniform direction for all target
 * points.  The function return value is the magnitude of the eye vector (before
 * normalization, naturally).
 * 
 * - WorkPlane
 * Returns the axis of the workplane and sets the center.
 * 
 * - GridSize
 * Returns the size of the grid in meters for this view.
 * 
 * - GridSnap
 * Returns the size of the grid snap for this view, or 0.0 for NONE.
 * 
 * 
 */
typedef struct vt_ILxView {
        ILxUnknown	 iunk;
        LXxMETHOD( int,
Type) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Center) (
        LXtObjectID		 self,
        LXtVector		 center);

        LXxMETHOD( double,
Scale) (
        LXtObjectID		 self);

        LXxMETHOD( double,
PixelScale) (
        LXtObjectID		 self);

        LXxMETHOD( double,
Aspect) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Matrix) (
        LXtObjectID		 self,
        LXtMatrix		 xfrm);

        LXxMETHOD( void,
InvMatrix) (
        LXtObjectID		 self,
        LXtMatrix		 xfrm);

        LXxMETHOD( void,
Ortho) (
        LXtObjectID		 self,
        int			*index,
        int			*spin);

        LXxMETHOD( int,
Axis) (
        LXtObjectID		 self);

        LXxMETHOD( double,
Zoom) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Focal) (
        LXtObjectID		 self,
        double			*flen,
        double			*fdist);

        LXxMETHOD( int,
ToScreen) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        double			*x,
        double			*y);

        LXxMETHOD( int,
ToScreen3) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        LXtVector		 vp);

        LXxMETHOD( void,
ToModel) (
        LXtObjectID		 self,
        int			 x,
        int			 y,
        LXtVector		 pos,
        int			 snap);

        LXxMETHOD( void,
ScreenNormals) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        LXtVector		 ax,
        LXtVector		 ay,
        LXtVector		 az);

        LXxMETHOD( double,
EyeVector) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        LXtVector		 eye);

        LXxMETHOD( void,
Dimensions) (
        LXtObjectID		 self,
        int			*w,
        int			*h);

        LXxMETHOD( int,
WorkPlane) (
        LXtObjectID		 self,
        LXtVector		 center);

        LXxMETHOD( double,
GridSize) (
        LXtObjectID		 self);

        LXxMETHOD( double,
GridSnap) (
        LXtObjectID		 self);
} ILxView;

typedef struct vt_ILxStrokeDraw {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Begin) (
        LXtObjectID		 self,
        int			 type,
        const LXtVector		 color,
        double			 alpha);

        LXxMETHOD( void,
BeginW) (
        LXtObjectID		 self,
        int			 type,
        const LXtVector		 color,
        double			 alpha,
        double			 width);

        LXxMETHOD( void,
BeginWD) (
        LXtObjectID		 self,
        int			 type,
        const LXtVector		 color,
        double			 alpha,
        double			 width,
        int			 dashPattern);

        LXxMETHOD( void,
Vertex) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        int			 flags);

        LXxMETHOD( void,
Vertex3) (
        LXtObjectID		 self,
        double			 x,
        double			 y,
        double			 z,
        int			 flags);

        LXxMETHOD( void,
TextureUV) (
        LXtObjectID		 self,
        double			 u,
        double			 v);

        LXxMETHOD( void,
Text) (
        LXtObjectID		 self,
        const char		*text,
        int			 just);

        LXxMETHOD( void,
PushTransform) (
        LXtObjectID		 self,
        const LXtVector		 v,
        const LXtMatrix		 m);

        LXxMETHOD( void,
PopTransform) (
        LXtObjectID		 self);

        LXxMETHOD( void,
SetPart) (
        LXtObjectID		 self,
        int			 part);

        LXxMETHOD( void,
BeginPoints) (
        LXtObjectID		 self,
        double			 size,
        const LXtVector		 color,
        double			 alpha);

        LXxMETHOD( void,
Image) (
        LXtObjectID		 self,
        int			 texID,
        int			 just);

        LXxMETHOD( void,
BeginPolygons) (
        LXtObjectID		 self,
        int			 type,
        const LXtVector		 color,
        double			 alpha,
        double			 stip,
        double			 offsetX,
        double			 offsetY,
        int			 fill,
        int			 cull);
        
        LXxMETHOD( void,
BeginI) (
        LXtObjectID		 self,
        LXtObjectID		 texture,
        int			 type,
        const LXtVector		 color,
        double			 alpha);
} ILxStrokeDraw;

typedef struct vt_ILxGLMaterial {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Color) (
        LXtObjectID		 self,
        LXtFVector		 color);

        LXxMETHOD(  LxResult,
Alpha) (
        LXtObjectID		 self,
        float			*alpha);

        LXxMETHOD(  LxResult,
DiffuseAmount) (
        LXtObjectID		 self,
        float			*amount);

        LXxMETHOD(  LxResult,
DiffuseColor) (
        LXtObjectID		 self,
        LXtFVector		 color);

        LXxMETHOD(  LxResult,
SpecularAmount) (
        LXtObjectID		 self,
        float			*amount);

        LXxMETHOD(  LxResult,
SpecularColor) (
        LXtObjectID		 self,
        LXtFVector		 color);

        LXxMETHOD(  LxResult,
LuminosityColor) (
        LXtObjectID		 self,
        LXtFVector		 color);

        LXxMETHOD(  LxResult,
Glossiness) (
        LXtObjectID		 self,
        float			*amount);

        LXxMETHOD(  LxResult,
ReflectionColor) (
        LXtObjectID		 self,
        LXtFVector		 color);

        LXxMETHOD(  LxResult,
TwoSide) (
        LXtObjectID		 self,
        int			*value);
} ILxGLMaterial;

/*
 * Once a GL Image object has been created, the image can be updated by providing
 * it with a new ILxImage object.
 * The dimensions of a GL Image can be queried.
 */
typedef struct vt_ILxGLImage {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetImage) (
        LXtObjectID		 self,
        LXtObjectID		 image);
        LXxMETHOD( LxResult,
Size) (
        LXtObjectID		 self,
        double			*w,
        double			*h);
} ILxGLImage;

/*
 * The view type is the basic kind of projection to be used, and
 * determines which attributes are available.
 * - PIXEL
 * simply maps 2D model coordinates as if they were pixels in the pane.
 * The upper-left is the origin and values increase downward and to the
 * right, just like in windows.
 * - SCREEN
 * maps 2D coordinates to the screen using a simple -1 to 1
 * mapping in X and Y.  If the ABSOLUTE flag is set, then the mapping goes
 * from -1 to 1 in whichever axis is smaller, and distances in X and Y are
 * undistorted.  The mapping can be altered by changing the center or the
 * scale.
 * 
 * - ORTHOGONAL
 * maps 3D coordinates by projecting along one of the cardinal axes.  The
 * center and scale affect the transform, and model space distances are
 * always undistorted.  If the ABSOLUTE flag is set, then the scale will
 * be an absolute conversion factor from model space to screen space (e.g.
 * meters per pixel) rather than being relative to the viewport size.
 * 
 * - PERSPECTIVE
 * maps 3D coordinates using a perspective transformation.  The projection
 * gets its rotation from the view matrix, but other than that this is
 * identical to the ORTHOGONAL view type.
 * 
 * - CAMERA
 * maps 3D coordinates as if they were viewed using a camera.  The center
 * and matrix set the camera's location and view direction, and the scale
 * sets the zoom factor.  The ABSOLUTE flag has no effect.
 * 
 * - GRAPH
 * maps 2D coordinates to an ordinate and abscissa.  This is the only view
 * which is non-uniform and has types and scaling that can be different for
 * the two axes.
 * 
 * - MASTER
 * is a special type that is just a collection of view parameters.  Other
 * real views can be slaved to a master view to force multiple views to
 * alter their state synchronously.  Masters can be created without an
 * associated pane.  The ABSOLUTE flag has no effect.
 * 
 */

        #define LXiVIEWv_PIXEL		 0x000
        #define LXiVIEWv_SCREEN		 0x001
        #define LXiVIEWv_ORTHOGONAL	 0x002
        #define LXiVIEWv_PERSPECTIVE	 0x003
        #define LXiVIEWv_CAMERA		 0x004
        #define LXiVIEWv_GRAPH		 0x005
        #define LXiVIEWv_MASTER		 0x006
        #define LXiVIEWf_ABSOLUTE	 0x100

/*
 * The index of the view orientation is one of the six values defined here.
 */

        #define LXiORTHOv_TOP		 0
        #define LXiORTHOv_BOTTOM	 1
        #define LXiORTHOv_BACK		 2
        #define LXiORTHOv_FRONT		 3
        #define LXiORTHOv_RIGHT		 4
        #define LXiORTHOv_LEFT		 5

/*
 * The attributes of the view affect the transform.  Attributes can be read or
 * set in variety of ways, and altering view attributes will cause the pane to
 * redraw.
 */

        #define LXu_VIEW		"7D171FD2-20D5-438C-8664-AECC2F828B76"
        // [local]  ILxView


        #define LXu_STROKEDRAW	"DA71480A-95AA-11D9-936D-000A956C2E10"
        //[local] ILxStrokeDraw

/*
 * The stroke modes are similar to OpenGL's own geometric primitives, with a
 * few differences.  They basically determine what kind of shape is drawn from
 * a series of "vertex" calls.
 * - NONE
 * This mode allows putting down vertices without drawing anything.  Useful for
 * setting anchor points for relative moves.
 * - POINTS
 * Same as OpenGL's GL_POINTS primitive.  Each vertex drops a spot on the
 * screen.
 * 
 * - LINES
 * Same as OpenGL's GL_LINES primitive.  Each pair of vertices makes a separate
 * line segment.
 * 
 * - LINE_STRIP
 * Same as OpenGL's GL_LINE_STRIP primitive.  Each vertex draws a line from
 * the previous one.
 * 
 * - LINE_LOOP
 * Same as OpenGL's GL_LINE_LOOP primitive.  Acts the same as LINE_STRIP except
 * that the first and last vertices are joined when the mode is changed.
 * 
 * - TRIANGLES
 * Same as OpenGL's GL_TRIANGLES primitive.  Draws a series of filled,
 * disconnected triangles from triples of vertices.
 * 
 * - QUADS
 * Same as OpenGL's GL_QUADS primitive.  Draws a series of filled, disconnected
 * quadrilaterals from groups of four vertices.
 * 
 * - BEZIERS
 * Draws cubic Bezier spline curves.  The first vertex is the start of the curve,
 * and the next three are treated as the control points and the end point, and
 * the end point becomes the start for the next the vertices.
 * 
 * - ARCS
 * Draws a series of disconnected arcs from triples of vertices.  The first
 * vertex is the center of the circle, and the next two vertices define the start
 * and end of the curve.  This will actually draw ellipses if necessary to make
 * the endpoints right.
 * 
 * - CIRCLES
 * Draws a series of disconnected circles from pairs of vertices.  The first
 * vertex is the center of the circle, and the second vertex defines the normal
 * axis for the circle, with its length being the radius.
 * 
 * - BOXES
 * Draws a series of disconnected boxes from pairs of vertices which are its
 * two far corners.  The box is a hollow wireframe.
 * 
 * - FRONT_BOXES
 * Like BOXES except that only the front faces of the box are drawn.  This makes
 * for a nicer way to draw a box with an obvious orientation.
 * 
 * - TEXT
 * Draws the current text string at each vertex location.  The text string and
 * justification are set with a special function.
 * 
 * - FRONT_LINE_LOOP
 * Same as OpenGL's GL_POLYGON primitive, but with the polygon mode set to
 * GL_LINE, front face vertex order set to GL_CW, and GL_CULL_FACE enabled.
 * Draws a wireframe polygon if its vertices appear in clockwise order in the
 * viewport.
 * 
 */

        #define LXiSTROKE_NONE			0
        #define LXiSTROKE_POINTS		1
        #define LXiSTROKE_LINES			2
        #define LXiSTROKE_LINE_STRIP		3
        #define LXiSTROKE_LINE_LOOP		4
        #define LXiSTROKE_TRIANGLES		5
        #define LXiSTROKE_QUADS			6
        #define LXiSTROKE_BEZIERS		7
        #define LXiSTROKE_ARCS			8
        #define LXiSTROKE_CIRCLES		9
        #define LXiSTROKE_BOXES			10
        #define LXiSTROKE_FRONT_BOXES		11
        #define LXiSTROKE_TEXT			12
        #define LXiSTROKE_FRONT_LINE_LOOP	13

        #define LXiSTROKE_ABSOLUTE		0
        #define LXiSTROKE_RELATIVE		1
        #define LXiSTROKE_SCREEN		2
        #define LXiSTROKE_REL_SCREEN		(LXiSTROKE_RELATIVE | LXiSTROKE_SCREEN)

        #define LXiHITPART_INVIS		-2000000000

        #define LXiTEXT_LEFT			 0
        #define LXiTEXT_CENTER			 1
        #define LXiTEXT_RIGHT			 2

        #define LXiLPAT_DOTS			 0xAAAA
        #define LXiLPAT_DOTSLONG		 0x2222
        #define LXiLPAT_DASH			 0x3333
        #define LXiLPAT_DASHLONG		 0xF0F0
        #define LXiLPAT_DASHXLONG		 0xE007
        #define LXiLPAT_DOTDASH			 0xE083


        #define LXiTEXTURE_CAMERA 0
        #define LXiTEXTURE_NONE -1

/*
 * This function wraps an AGL surface object as a ILxAGLMaterial interface.
 */

        #define LXu_GLMATERIAL		"2AA53B64-9EEF-4504-BE1B-6471A834853D"
        #define LXa_GLMATERIAL		"AGLMaterial"
        // [local] ILxGLMaterial

/*
 * The GL Image interface provides a way to pass images to OpenGL for drawing.
 */

        #define LXu_GLIMAGE	"DA71480A-95AA-11D9-936D-000A956C2E10"
        #define LXa_GLIMAGE	"GLImage"
        //[local] ILxGLImage

#endif
