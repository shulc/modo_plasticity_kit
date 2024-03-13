/*
 * LX locator module
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
#ifndef LX_locator_H
#define LX_locator_H

typedef struct vt_ILxLocator ** ILxLocatorID;

#include <lxvalue.h>
#include <lxitem.h>

/*
 * Transforms applied to locators have a fixed set of types.
 */

        typedef unsigned	LXtTransformType;

        #define LXiXFRM_SCALE		0
        #define LXiXFRM_ROTATION	1
        #define LXiXFRM_POSITION	2
        #define LXiXFRM_PIVOT		3
        #define LXiXFRM_PIVOT_C		4
        #define LXiXFRM_SHEAR		5
        #define LXiXFRM_PIVOT_ROT	6
        #define LXiXFRM_PIVOT_ROT_C	7



/*
 * Locator-type item visibility is controlled both locally and by parent items.
 * If an item evaluates as visible, the return value is LXe_TRUE, otherwise the
 * return value is LXe_FALSE.
 * 
 * Locator-type items have support methods for getting and setting their transforms.
 * This gets the evaluated world transform (position offset and 3x3 matrix) for a
 * given item at a given time.
 * 
 * This method returns the transform item of the given type for the locator item.
 * If no item exists this method returns LXe_NOTFOUND. Otherwise the item is
 * returned.
 * 
 * This method adds a given transform or returns the existing one.  It can
 * optionally return the index of the first value channel of the xfrm as well.
 * 
 * This method sets the value of one of the transforms for the given locator
 * item.  The chanWrite object can be an object presenting an ILxChannelWrite
 * interface for one of the scene's actions.  If this is null the vector is
 * written as constant channel values in some appropriate action.
 * 
 * This method creates a new transform of the requested type and inserts into the
 * transform chain before the standard transform. It returns the new object, optionally
 * the first value channel of the xfrm as well. If 'value' is not NULL, it sets the value of one of
 * the transforms.  The chanWrite object can be an object presenting an ILxChannelWrite
 * interface for one of the scene's actions.  If this is null the vector is
 * written as constant channel values in some appropriate action.
 * 
 * This is like the above, but it inserts the transform AFTER the standard transforms.
 * 
 * 
 * Inserts the transform BEFORE the very first transform.
 * 
 * Inserts the transform AFTER the very last transform.
 * 
 * 
 * 
 * 
 * Items may have several position transforms (zeroed, pivot etc) making it difficult to
 * set a local position directly. This function takes the desired local position values for
 * an item and updates them to the values that need to be set on the standard position transform
 * item to give the desired position after taking all other transforms into account.
 * 
 * As above above but for the local rotation matrix.
 * 
 * 
 * This is similar to WorldTransform, except the evaluated world transform is
 * returned in a full 4x4 matrix.
 * 
 * This gets the invert transformation matrix and offset
 * 
 * This gets the evaluated local transform (position offset and 3x3 matrix - relative to its parent)
 * for a given item at a given time.
 * 
 * This is similar to LocalTransform, except the evaluated local transform is
 * returned in a full 4x4 matrix.
 */
typedef struct vt_ILxLocator {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Visible) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead);
        LXxMETHOD(  LxResult,
WorldTransform) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtMatrix		 xfrm,
        LXtVector		 pos);
        LXxMETHOD(  LxResult,
GetTransformItem) (
        LXtObjectID		 self,
        LXtTransformType	 type,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
AddTransformItem) (
        LXtObjectID		 self,
        LXtTransformType	 type,
        void		       **ppvObj,
        unsigned		*index);
        LXxMETHOD(  LxResult,
SetTransformVector) (
        LXtObjectID		 self,
        LXtObjectID		 chanWrite,
        LXtTransformType	 type,
        const LXtVector		 value);
        LXxMETHOD(  LxResult,
AddPreTransformItem) (
        LXtObjectID		 self,
        LXtObjectID		 chanWrite,
        LXtTransformType	 type,
        const LXtVector		 value,
        void		       **ppvObj,
        unsigned		*index);
        LXxMETHOD(  LxResult,
AddPostTransformItem) (
        LXtObjectID		 self,
        LXtObjectID		 chanWrite,
        LXtTransformType	 type,
        const LXtVector		 value,
        void		       **ppvObj,
        unsigned		*index);
        LXxMETHOD(  LxResult,
SetTarget) (
        LXtObjectID		 self,
        LXtObjectID		 target,
        void	     		**ppvObj);
        LXxMETHOD(  LxResult,
PrependTransformItem) (
        LXtObjectID		 self,
        LXtObjectID		 chanWrite,
        LXtTransformType	 type,
        const LXtVector		 value,
        void		       **ppvObj,
        unsigned		*index);
        LXxMETHOD(  LxResult,
AppendTransformItem) (
        LXtObjectID		 self,
        LXtObjectID		 chanWrite,
        LXtTransformType	 type,
        const LXtVector		 value,
        void		       **ppvObj,
        unsigned		*index);
        LXxMETHOD(  LxResult,
SetPosition) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtObjectID		 chanWrite,
        const LXtVector		 pos,
        unsigned		 type,
        unsigned		 comp);
        LXxMETHOD(  LxResult,
SetRotation) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtObjectID		 chanWrite,
        const LXtMatrix		 m3,
        unsigned		 type,
        unsigned		 comp);
        LXxMETHOD(  LxResult,
SetScale) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtObjectID		 chanWrite,
        const LXtMatrix4	 m4,
        unsigned		 type,
        unsigned		 comp);
        LXxMETHOD(  LxResult,
ExtractLocalPosition) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtVector		 pos);
        LXxMETHOD(  LxResult,
ExtractLocalRotation) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtMatrix		 m3);
        LXxMETHOD(  LxResult,
ZeroTransform) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtObjectID		 chanWrite,
        LXtTransformType	 type);
        LXxMETHOD(  LxResult,
WorldTransform4) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtMatrix4		 xfrm4);
        LXxMETHOD(  LxResult,
WorldInvertTransform) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtMatrix		 xfrm,
        LXtVector		 pos);
        LXxMETHOD(  LxResult,
LocalTransform) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtMatrix		 xfrm,
        LXtVector		 pos);
        LXxMETHOD(  LxResult,
LocalTransform4) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtMatrix4		 xfrm4);
} ILxLocator;

/*
 * - IROTATEc_X  [angle]
 * Rotation angle around the X axis.
 * - IROTATEc_Y  [angle]
 * Rotation angle around the Y axis.
 * - IROTATEc_Z  [angle]
 * Rotation angle around the Z axis.
 * - IROTATEc_ORDER  [integer]
 * The rotation order defines the order in which the rotation channels are combined to create the final
 * rotation matrix.
 * 	{0,1,2} is Maya, XSI, Max default; {X,Y,Z}
 * 
 * 	{2,0,1} is LightWave; {Z,X,Y}, or {B,P,H}.
 * 
 * 
 * 
 */

enum {
LXi_ROTORD_XYZ = 0	,
LXi_ROTORD_XZY	,
LXi_ROTORD_YXZ	,
LXi_ROTORD_YZX	,
LXi_ROTORD_ZXY	,
LXi_ROTORD_ZYX
};

/*
 * Startup initializes all the packages and then promotes some of them to item
 * status.  This basically just means creating the package, assigning the local
 * data and callbacks, and setting up the channels.  This module depends on
 * cinemas and meshes.
 */

        // Locator Item Type and Channels
        #define	LXsITYPE_LOCATOR			"locator"
        #define	LXsICHAN_LOCATOR_VISIBLE		"visible"
        #define	LXsICHAN_LOCATOR_RENDER			"render"
        #define	LXsICHAN_LOCATOR_SELECT			"select"
        #define	LXsICHAN_LOCATOR_LOCK			"lock"
        #define	LXsICHAN_LOCATOR_SIZE			"size"
        #define	LXsICHAN_LOCATOR_DRAWSHAPE		"drawShape"
        #define	LXsICHAN_LOCATOR_CENTER			"center"
        #define	LXsICHAN_LOCATOR_PIVOT			"pivot"
        #define	LXsICHAN_LOCATOR_LINK			"link"
        #define	LXsICHAN_LOCATOR_GLSTATE		"glState"
        #define	LXsICHAN_LOCATOR_HVISIBLE		"hVisible"
        #define LXsICHAN_LOCATOR_GLSURF			"glsurf"
        #define LXsICHAN_LOCATOR_SILHOUETTE		"silhouette"

        // Locator "drawShape" Channel Hints
        #define	LXsICVAL_LOCATOR_DRAWSHAPE_DEFAULT	"default"
        #define	LXsICVAL_LOCATOR_DRAWSHAPE_CUSTOM	"custom"

        // Locator "link" Channel Hints
        #define	LXsICVAL_LOCATOR_LINK_DEFAULT		"default"
        #define	LXsICVAL_LOCATOR_LINK_CUSTOM		"line"
//	#define	LXsICVAL_LOCATOR_LINK_CUSTOM		"custom"

        // Various Locator Channel "state" Hints
        #define	LXsICVAL_LOCATOR_STATE_DEFAULT		"default"
        #define	LXsICVAL_LOCATOR_STATE_ON		"on"
        #define	LXsICVAL_LOCATOR_STATE_OFF		"off"

        // Light Item Type and Channels
        #define	LXsITYPE_LIGHT				"light"
        #define	LXsICHAN_LIGHT_RADIANCE			"radiance"
        #define	LXsICHAN_LIGHT_FALLTYPE			"fallType"
        #define	LXsICHAN_LIGHT_RANGE			"range"
        #define	LXsICHAN_LIGHT_SHADTYPE			"shadType"
        #define	LXsICHAN_LIGHT_SHADRES			"shadRes"
        #define	LXsICHAN_LIGHT_SHADSPOT			"shadSpot"
        #define	LXsICHAN_LIGHT_SAMPLES			"samples"
        #define	LXsICHAN_LIGHT_IMPORTANCE		"importance"
        #define	LXsICHAN_LIGHT_VISCAM			"visCam"
        #define	LXsICHAN_LIGHT_VISREFL			"visRefl"
        #define	LXsICHAN_LIGHT_VISREFR			"visRefr"
        #define	LXsICHAN_LIGHT_STACK			"stack"
        #define	LXsICHAN_LIGHT_TARGET			"target"

        #define LXsICHAN_SUNLIGHT_GAMMA				"gamma"
        #define LXsICHAN_SUNLIGHT_DISTANCE			"distance"
        #define LXsICHAN_SUNLIGHT_THINNING			"thinning"
        #define LXsICHAN_SUNLIGHT_SUMMERTIME		"summerTime"
        #define LXsICHAN_SUNLIGHT_USEWORLDXFORM		"useWorldXfrm"

        // Light "fallType" Channel Text Hints
        #define	LXsICVAL_LIGHT_FALLTYPE_NONE		"none"
        #define	LXsICVAL_LIGHT_FALLTYPE_INVDIST		"invdist"
        #define	LXsICVAL_LIGHT_FALLTYPE_INVDIST2	"invdist2"

        // Light "shadType" Channel Text Hints
        #define	LXsICVAL_LIGHT_SHADTYPE_NONE		"none"
        #define	LXsICVAL_LIGHT_SHADTYPE_RAYTRACE	"raytrace"
        #define	LXsICVAL_LIGHT_SHADTYPE_SHADOWMAP	"shadowmap"

        // Camera Item Type and Channels
        #define	LXsITYPE_CAMERA				"camera"
        #define	LXsICHAN_CAMERA_FOCALLEN		"focalLen"
        #define	LXsICHAN_CAMERA_APERTUREX		"apertureX"
        #define	LXsICHAN_CAMERA_APERTUREY		"apertureY"
        #define	LXsICHAN_CAMERA_OFFSETX			"offsetX"
        #define	LXsICHAN_CAMERA_OFFSETY			"offsetY"
        #define	LXsICHAN_CAMERA_SQUEEZE			"squeeze"
        #define	LXsICHAN_CAMERA_FILMROLL		"filmRoll"
        #define	LXsICHAN_CAMERA_FILMFIT			"filmFit"
        #define	LXsICHAN_CAMERA_DOF			"dof"
        #define	LXsICHAN_CAMERA_FOCUSDIST		"focusDist"
        #define	LXsICHAN_CAMERA_FSTOP			"fStop"
        #define	LXsICHAN_CAMERA_IRISBLADES		"irisBlades"
        #define	LXsICHAN_CAMERA_IRISROT			"irisRot"
        #define	LXsICHAN_CAMERA_IRISBIAS		"irisBias"
        #define	LXsICHAN_CAMERA_DISTORT			"distort"
        #define	LXsICHAN_CAMERA_MOTIONBLUR		"motionBlur"
        #define	LXsICHAN_CAMERA_BLURLEN			"blurLen"
        #define	LXsICHAN_CAMERA_BLUROFF			"blurOff"
        #define	LXsICHAN_CAMERA_STEREO			"stereo"
        #define	LXsICHAN_CAMERA_STEREOEYE		"stereoEye"
        #define	LXsICHAN_CAMERA_STEREOCOMP		"stereoComp"
        #define	LXsICHAN_CAMERA_IODIST			"ioDist"
        #define	LXsICHAN_CAMERA_CONVDIST		"convDist"
        #define	LXsICHAN_CAMERA_PROJTYPE		"projType"
        #define	LXsICHAN_CAMERA_TARGET			"target"
        #define	LXsICHAN_CAMERA_CLIPDIST		"clipDist"
        #define	LXsICHAN_CAMERA_CLIPPING		"clipping"
        #define	LXsICHAN_CAMERA_RESOVERRIDE		"resOverride"
        #define	LXsICHAN_CAMERA_RESX			"resX"
        #define	LXsICHAN_CAMERA_RESY			"resY"
        #define	LXsICHAN_CAMERA_OVERSCAN		"overscan"
        #define	LXsICHAN_CAMERA_USEMASK			"useMask"
        #define	LXsICHAN_CAMERA_USEIMAGES		"useImages"
        #define	LXsICHAN_CAMERA_USEBGIMAGE		"useBGImage"
        #define	LXsICHAN_CAMERA_USEFGIMAGE		"useFGImage"

        // Camera "filmFit" Channel Text Hints
        #define	LXsICVAL_CAMERA_FILMFIT_FILL		"fill"
        #define	LXsICVAL_CAMERA_FILMFIT_HORIZONTAL	"horizontal"
        #define	LXsICVAL_CAMERA_FILMFIT_VERTICAL	"vertical"
        #define	LXsICVAL_CAMERA_FILMFIT_OVERSCAN	"overscan"

        // Camera "projType" Channel Text Hints
        #define	LXsICVAL_CAMERA_PROJTYPE_PERSP		"persp"
        #define	LXsICVAL_CAMERA_PROJTYPE_ORTHO		"ortho"
        #define LXsICVAL_CAMERA_PROJTYPE_CYLINDRICAL    "cylindrical"
        #define LXsICVAL_CAMERA_PROJTYPE_CYLINDRICAL_VR "cylindricalvr"
        #define LXsICVAL_CAMERA_PROJTYPE_SPHERICAL      "spherical"
        #define LXsICVAL_CAMERA_PROJTYPE_SPHERICAL_VR   "sphericalvr"

        // Camera "stereoEye" Channel Text Hints
        #define	LXsICVAL_CAMERA_STEREOEYE_LEFT		"left"
        #define	LXsICVAL_CAMERA_STEREOEYE_RIGHT		"right"
        #define	LXsICVAL_CAMERA_STEREOEYE_BOTH		"both"

        // Camera "stereoComp" Channel Text Hints
        #define	LXsICVAL_CAMERA_STEREOCOMP_NONE				"stereoNone"
        #define	LXsICVAL_CAMERA_STEREOCOMP_ANAGLYPH_RED_CYAN		"anaRedCyan"
        #define	LXsICVAL_CAMERA_STEREOCOMP_ANAGLYPH_GRAYSCALE		"anaGrayscale"
        #define	LXsICVAL_CAMERA_STEREOCOMP_ANAGLYPH_RED_CYAN_HALF	"anaRedCyanHalf"
        #define	LXsICVAL_CAMERA_STEREOCOMP_ANAGLYPH_RED_CYAN_OPT	"anaRedCyanOpt"
        #define	LXsICVAL_CAMERA_STEREOCOMP_ANAGLYPH_RED_BLUE_LS		"anaRedBlueLS"
        #define	LXsICVAL_CAMERA_STEREOCOMP_SIDE_BY_SIDE			"sideBySide"
        #define	LXsICVAL_CAMERA_STEREOCOMP_SIDE_BY_SIDE_FULL		"sideBySideFull"
        #define	LXsICVAL_CAMERA_STEREOCOMP_SIDE_BY_SIDE_CROSS		"sideBySideCross"
        #define	LXsICVAL_CAMERA_STEREOCOMP_SIDE_BY_SIDE_CROSSFULL	"sideBySideCrossFull"

        // Group Locator Item Type and Channels
        #define	LXsITYPE_GROUPLOCATOR			"groupLocator"

/*
 * A locator is a basic item type that has a transform.
 */

        #define LXu_LOCATOR	"50DCCB9D-9856-4A33-9BDA-DAF3A71BBD2D"
        #define LXa_LOCATOR	"locator"
        // [local]  ILxLocator
        // [const]  ILxLocator:Visible
        // [const]  ILxLocator:WorldTransform
        // [const]  ILxLocator:WorldTransform4
        // [const]  ILxLocator:LocalTransform
        // [const]  ILxLocator:LocalTransform4
        // [const]  ILxLocator:GetTransformItem
        // [const]  ILxLocator:GetXfrmItem
        // [python] ILxLocator:AddPostTransformItem	obj Item
        // [python] ILxLocator:AddPreTransformItem	obj Item
        // [python] ILxLocator:AddTransformItem		obj Item
        // [python] ILxLocator:AppendTransformItem	obj Item
        // [python] ILxLocator:GetTransformItem		obj Item
        // [python] ILxLocator:PrependTransformItem	obj Item
        // [python] ILxLocator:SetTarget		obj Item
        // [python] ILxLocator:Visible			bool

/*
 * These declarations are used to test light shadow types.
 */

        #define LXiICVAL_LIGHT_SHADTYPE_NONE		0
        #define LXiICVAL_LIGHT_SHADTYPE_RAYTRACE	1
        #define LXiICVAL_LIGHT_SHADTYPE_SHADOWMAP	2
        #define LXiICVAL_LIGHT_SHADTYPE_PORTAL		3


        #define LXiLOCATOR_LOCAL	0
        #define LXiLOCATOR_WORLD	1

#endif
