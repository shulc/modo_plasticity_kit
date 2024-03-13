/*
 * LX surface module
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
#ifndef LX_surface_H
#define LX_surface_H

typedef struct vt_ILxGLShadingListener ** ILxGLShadingListenerID;
typedef struct vt_ILxSurfaceItem ** ILxSurfaceItemID;
typedef struct vt_ILxSurface ** ILxSurfaceID;
typedef struct vt_ILxSurfaceBin ** ILxSurfaceBinID;
typedef struct vt_ILxCurveGroup ** ILxCurveGroupID;
typedef struct vt_ILxCurve ** ILxCurveID;
typedef struct vt_ILxCurve1 ** ILxCurve1ID;
typedef struct vt_ILxCurve2 ** ILxCurve2ID;
typedef struct vt_ILxCurve3 ** ILxCurve3ID;

#include <lxshade.h>
#include <lxmesh.h>


/*
 * Surface objects have a number of properties that can be queried with the ILxBinnedSurface interface.
 * - GetBBox
 * returns the surface bounding box.
 * - FrontBBox
 * sets the front bounding box for that bin. The 'front' bounding box is formed by the geometry facing the viewer given
 * by its position and direction vectors.
 * 
 * - RayCast
 * casts a ray on the surface.
 * 
 * The input is the rayInfo structure which holds the position & direction of the ray plus some
 * optional settings. 'cull' must be true to cull hidden geometry, 'half' only raycasts the geoemtry in front of the viewer and 'vmapName' must be set
 * to calculate the UVs (or other vmap values) at the hit point.
 * 
 */
typedef struct st_LXtRayInfo {
        LXtVector		 pos;
        LXtVector		 dir;
        unsigned		 cull;
        unsigned		 half;
        const char		*vmapName;
        LXtID4			 vmapType;
} LXtRayInfo;

/*
 * The output is the rayHIt stucture. pos & nrm are the position and normal vectors at the hit point. 'dist' is the distance along the ray, 'uvw' are the vmap values
 * if 'vmap' is set in the input and 'bin' is the hit bin.
 */
typedef struct st_LXtRayHit {
        LXtVector		 pos;  // object position
        LXtVector		 nrm;  // object normal
        LXtVector		 uvw;
        double			 dist;
        void			*bin;
        LXtPolygonID		 polygon;
} LXtRayHit;


/*
 * When any change occurs which alters the shading of an item in GL, a shading update
 * event is sent.  This could be a reorganization of the shader tree, a change to a
 * material's channel, or anything else which might impact the gl shading of the item.
 * 
 * If a change alters the displacement of a surface, a displacement update
 * event is sent.  This change will also trigger a shading update.
 * 
 * 
 * If a change alters the fur on a surface, a fur update
 * event is sent.  This change will also trigger a shading update.
 * 
 */
typedef struct vt_ILxGLShadingListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
ShadingUpdate) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD( void,
DisplacementUpdate) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD( void,
FurUpdate) (
        LXtObjectID		 self,
        LXtObjectID		 item);
} ILxGLShadingListener;

/*
 * All item types that produce a surface can be queried for their ILxSurfaceItem interface.
 * - GetSurface
 * returns the ILxSurface object, 'morph' should be set if the client is intertested in the morphed surface.
 * 
 * - Prepare
 * adds the channels for the surface modifier and
 * 
 * - Evaluate
 * evaluates the surface.
 * 
 */
typedef struct vt_ILxSurfaceItem {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetSurface) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        unsigned		 morph,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Prepare) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        unsigned		*index);

        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned		 index,
        void		       **ppvObj);
} ILxSurfaceItem;

/*
 * - BinCount
 * returns the number of bins on a surface.
 * - BinByIndex
 * returns the ILxSurfaceBin object by its index in the surface.
 * - TagCount
 * returns the number of string tags per tag type
 * 
 * - TagByIndex
 * returns the string tag interface given by its type and index in the list.
 * 
 * - GLCount
 * returns the number of GL polygons displayed by the surface.
 * 
 */
typedef struct vt_ILxSurface {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetBBox) (
        LXtObjectID		 self,
        LXtBBox		        *bbox);

        LXxMETHOD(  LxResult,
FrontBBox) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtVector		 dir,
        LXtBBox		        *bbox);

        LXxMETHOD(  LxResult,
RayCast) (
        LXtObjectID		 self,
        const LXtRayInfo	*ray,
        LXtRayHit		*hit);

        LXxMETHOD(  LxResult,
BinCount) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD( LxResult,
BinByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
TagCount) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		*count);

        LXxMETHOD( LxResult,
TagByIndex) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 index,
        const char		**stag);

        LXxMETHOD( LxResult,
GLCount) (
        LXtObjectID		 self,
        unsigned int		*count);
} ILxSurface;

/*
 * Finally we have surface bins which represents a segment of the surface with the same
 * tags and thus the same shader.
 * - GetBBox
 * sets the bounding box for that bin
 * - FrontBBox
 * sets the front bounding box for that bin. The 'front' bounding box is formed by the geometry facing the viewer given
 * by its position and direction vectors.
 * 
 * The surface bin object should also present an ILxStringTags interface to get the
 * polygon tags on the bin for shader tree masking, and an ILxTableauSurface interface
 * to allow the surface to be sampled into a triangle soup.
 * 
 */
typedef struct vt_ILxSurfaceBin {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetBBox) (
        LXtObjectID		 self,
        LXtBBox		        *bbox);

        LXxMETHOD(  LxResult,
FrontBBox) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtVector		 dir,
        LXtBBox		        *bbox);
} ILxSurfaceBin;

/*
 * Any item can present itself as a group of curves. The bounding box and count
 * of curves can be read from the root object, and curve accessors can be allocated
 * for each one by index.
 */
typedef struct vt_ILxCurveGroup {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetBBox) (
        LXtObjectID		 self,
        LXtBBox		        *bbox);

        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        unsigned		*count);

        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);
} ILxCurveGroup;

/*
 * The curve accessor allows the client to read the attributes and shape of the
 * curve. It also has StringTag interface for bin tags. The bounding box and
 * length are gross features.
 * 
 * If the curve is piecewise cubic, the spline segments can be read as Bezier
 * control points. If the curve is not a spline then Count() returns NOTFOUND.
 * 
 * Curves can also be parameteric. In that case they aren't made of splines, but
 * we want to know aproximately how many bends they have in case we need to
 * sample it and capture the shape. A bend is a flex in the curve, and we're
 * counting how many of them there are relative to the parameterization. For
 * piecewise cubic curves this is twice the number of splines.
 * 
 * Points along the curve are read by setting the parameter for the curve to a
 * value between 0 and 1. The parameter can also be set by the fraction of the
 * curve's total length.
 * 
 * The position, tangent, and curvature can then be read. The position is in world coordinates,
 * the tangent is the rate of change relative to the parameter, and the curvature is the 
 * tangent's rate of change relative to the parameter.
 * 
 * The normal of the curve can also be computed. This should always be a vector
 * at 90 degrees to the tangent. 
 * 
 * Normals can also be computed using the closest polygon normal from a given 
 * mesh, or the direction to the closest point on another curve.  
 * 
 * This finds the closest point on the curve at the probe position. Results are
 * returned as the parameter value, the position on the curve, and the normal to
 * the curve in the direction of the probe.
 * 
 * This returns LXe_TRUE or LXe_FALSE, depending on whether the curve is closed
 * or not.
 * 
 * Sometimes, it can be useful to walk a curve from a start point to an end
 * point, based on an angle. Samples will be placed along the curve where the
 * angle deviation from the last sample is greater than the threshold angle.
 */
typedef struct vt_ILxCurve {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetBBox) (
        LXtObjectID		 self,
        LXtBBox		        *bbox);

        LXxMETHOD(  double,
Length) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
SplineCount) (
        LXtObjectID		 self,
        unsigned		*count);

        LXxMETHOD(  LxResult,
SplineByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtVector		 b0,
        LXtVector		 b1,
        LXtVector		 b2,
        LXtVector		 b3);

        LXxMETHOD(  LxResult,
SplineLengthByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        double			*length);
        LXxMETHOD(  unsigned,
BendCount) (
        LXtObjectID		 self);
        LXxMETHOD(  double,
Param) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetParam) (
        LXtObjectID		 self,
        double			 param);

        LXxMETHOD(  double,
LenFraction) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetLenFraction) (
        LXtObjectID		 self,
        double			 frac);
        LXxMETHOD(  LxResult,
Position) (
        LXtObjectID		 self,
        LXtVector		 pos);

        LXxMETHOD(  LxResult,
Tangent) (
        LXtObjectID		 self,
        LXtVector		 tan);

        LXxMETHOD(  LxResult,
Curvature) (
        LXtObjectID		 self,
        double			*curv);

        LXxMETHOD(  LxResult,
Normal) (
        LXtObjectID		 self,
        LXtVector		 normal);
        LXxMETHOD(  LxResult,
MeshNormal) (
        LXtObjectID		 self,
        LXtObjectID		 meshObj,
        LXtMatrix4               xfrm,
        LXtVector		 normal);

        LXxMETHOD(  LxResult,
GuideCurveNormal) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        LXtVector		 normal);
        LXxMETHOD(  LxResult,
Closest) (
        LXtObjectID		 self,
        const LXtVector		 probe,
        double			*param,
        LXtVector		 pos,
        LXtVector		 norm);
        LXxMETHOD(  LxResult,
IsClosed) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
WalkByAngle) (
        LXtObjectID		 self,
        double			 start,
        double			 end,
        double			 angle,
        LXtObjectID		 visitor);
} ILxCurve;

/*
 * This interface was retired in modo 901, and was replaced with an updated one
 * that added a few more methods.
 */
typedef struct vt_ILxCurve1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetBBox) (
        LXtObjectID		 self,
        LXtBBox		        *bbox);

        LXxMETHOD(  double,
Length) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SplineCount) (
        LXtObjectID		 self,
        unsigned		*count);

        LXxMETHOD(  LxResult,
SplineByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtVector		 b0,
        LXtVector		 b1,
        LXtVector		 b2,
        LXtVector		 b3);

        LXxMETHOD(  unsigned,
BendCount) (
        LXtObjectID		 self);

        LXxMETHOD(  double,
Param) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetParam) (
        LXtObjectID		 self,
        double			 param);

        LXxMETHOD(  LxResult,
SetLenFraction) (
        LXtObjectID		 self,
        double			 frac);

        LXxMETHOD(  LxResult,
Position) (
        LXtObjectID		 self,
        LXtVector		 pos);

        LXxMETHOD(  LxResult,
Tangent) (
        LXtObjectID		 self,
        LXtVector		 tan);

        LXxMETHOD(  LxResult,
Closest) (
        LXtObjectID		 self,
        const LXtVector		 probe,
        double			*param,
        LXtVector		 pos,
        LXtVector		 norm);
} ILxCurve1;

/*
 * This interface was retired in modo 10, and was replaced with an updated one
 * that added a few more methods.
 */
typedef struct vt_ILxCurve2 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetBBox) (
        LXtObjectID		 self,
        LXtBBox		        *bbox);

        LXxMETHOD(  double,
Length) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SplineCount) (
        LXtObjectID		 self,
        unsigned		*count);

        LXxMETHOD(  LxResult,
SplineByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtVector		 b0,
        LXtVector		 b1,
        LXtVector		 b2,
        LXtVector		 b3);

        LXxMETHOD(  unsigned,
BendCount) (
        LXtObjectID		 self);

        LXxMETHOD(  double,
Param) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetParam) (
        LXtObjectID		 self,
        double			 param);

        LXxMETHOD(  double,
LenFraction) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetLenFraction) (
        LXtObjectID		 self,
        double			 frac);

        LXxMETHOD(  LxResult,
Position) (
        LXtObjectID		 self,
        LXtVector		 pos);

        LXxMETHOD(  LxResult,
Tangent) (
        LXtObjectID		 self,
        LXtVector		 tan);

        LXxMETHOD(  LxResult,
Closest) (
        LXtObjectID		 self,
        const LXtVector		 probe,
        double			*param,
        LXtVector		 pos,
        LXtVector		 norm);

        LXxMETHOD(  LxResult,
IsClosed) (
        LXtObjectID		 self);
} ILxCurve2;

/*
 * This interface was retired in modo 13, and was replaced with an updated one
 * that added a few more methods.
 */
typedef struct vt_ILxCurve3 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetBBox) (
        LXtObjectID		 self,
        LXtBBox		        *bbox);

        LXxMETHOD(  double,
Length) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SplineCount) (
        LXtObjectID		 self,
        unsigned		*count);

        LXxMETHOD(  LxResult,
SplineByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtVector		 b0,
        LXtVector		 b1,
        LXtVector		 b2,
        LXtVector		 b3);

        LXxMETHOD(  unsigned,
BendCount) (
        LXtObjectID		 self);

        LXxMETHOD(  double,
Param) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetParam) (
        LXtObjectID		 self,
        double			 param);

        LXxMETHOD(  double,
LenFraction) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetLenFraction) (
        LXtObjectID		 self,
        double			 frac);

        LXxMETHOD(  LxResult,
Position) (
        LXtObjectID		 self,
        LXtVector		 pos);

        LXxMETHOD(  LxResult,
Tangent) (
        LXtObjectID		 self,
        LXtVector		 tan);

        LXxMETHOD(  LxResult,
Closest) (
        LXtObjectID		 self,
        const LXtVector		 probe,
        double			*param,
        LXtVector		 pos,
        LXtVector		 norm);

        LXxMETHOD(  LxResult,
IsClosed) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
WalkByAngle) (
        LXtObjectID		 self,
        double			 start,
        double			 end,
        double			 angle,
        LXtObjectID		 visitor);
} ILxCurve3;

/*
 * There are many different changes users can make which invalidate an item's shading in GL and
 * attempting to track them all might not be practical. Instead, sdk clients can listen for 
 * invalidation events using the GL Shading Listener.
 */

        #define LXu_GLSHADINGLISTENER		"893C9E49-CBFE-496D-BE18-DD45BBE4E67D" 
        // [export] ILxGLShadingListener gls
        // [local]  ILxGLShadingListener


        #define LXa_SURFACEITEM	"surfaceItem"
        #define LXu_SURFACEITEM	"65EC0E0E-FFD7-48a3-9E20-62EA82EF4728"
        // [export] ILxSurfaceItem isurf
        // [local]  ILxSurfaceItem
        // [python] ILxSurfaceItem:Evaluate	obj Surface
        // [python] ILxSurfaceItem:GetSurface	obj Surface


        #define LXa_SURFACE	"surface"
        #define LXu_SURFACE	"75006BDB-93F7-4a41-8B8C-E710D80D3F1A"
        // [export] ILxSurface surf
        // [local]  ILxSurface
        // [python] ILxSurface:BinByIndex	obj SurfaceBin


        #define LXa_SURFACEBIN	"surfaceBin"
        #define LXu_SURFACEBIN	"48B534C1-7B7C-4147-ADBC-154850898E7F"
        // [export] ILxSurfaceBin surfBin
        // [local]  ILxSurfaceBin

/*
 * Items declare that they can provide curves with a package tag giving the
 * name of the curve channel. Read in an evaluated context, this will be an
 * ValueReference object channel holding the curve group object.
 */

        #define LXu_CURVEGROUP		"20F1B298-84E2-4DA2-BA66-8883B4B0D7FF"
        // [export] ILxCurveGroup cgrp
        // [local]  ILxCurveGroup
        // [python] ILxCurveGroup:ByIndex	obj Curve

        #define LXsPKG_CURVES_CHANNEL	"curveGroup.channel"

        #define LXu_CURVE		"2FE806FE-0E47-41B4-9F2A-C0BB2CAF364F"
        #define LXa_CURVE		"curve3"
        // [export] ILxCurve curve
        // [local]  ILxCurve
        // [python] ILxCurve:IsClosed	bool


        #define LXu_CURVE1		"9DDF4A43-691F-4F30-8986-B52FD1D96E34"
        #define LXa_CURVE1		"curve"


        #define LXu_CURVE2		"E3EF1C95-F295-4FAD-9DF8-9E822EF3202F"
        #define LXa_CURVE2		"curve1"


        #define LXu_CURVE3		"1A832950-B71E-4BCB-8D56-46ECE4F5BC3F"
        #define LXa_CURVE3		"curve2"

#endif
