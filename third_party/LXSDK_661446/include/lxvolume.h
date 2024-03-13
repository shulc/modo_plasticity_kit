/*
 * LX volume module
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
#ifndef LX_volume_H
#define LX_volume_H

typedef struct vt_ILxRaymarch ** ILxRaymarchID;
typedef struct vt_ILxVoxel ** ILxVoxelID;

#include <lxtableau.h>


/*
 * Volume rendering splits a volume into pieces.  Each piece is called a volume
 * sample. It has a color corresponding to the light scattering at that point, an
 * opacity corresponding to the light attenuation, a distance which is the
 * position of the sample on the ray (measured from the origin of the ray), and a
 * stride which is the size of the sample (still measured on the ray).
 */
typedef struct st_LXtVolumeSample {
        double		dist;
        double		color[3];
        double		opacity[3];
        double		stride;
} LXtVolumeSample;

/*
 * See Also: LXtVolumeSample
 * Solid rendering returns a LXtSurfFragment structure which holds the information
 * resulting from the intersection between the given ray and the solid and the
 * subsequent surface shading.  This includes the distance to the origin of the
 * ray, the surface normal, the color and opacity resulting from shading, and the
 * object and surface IDs.  Note:  Additionnal information that the client would
 * like to set (for special render buffers) can bet set manually by checking the
 * result of the addSolid() method which returns true if the LXtSurfFragment can
 * contribute to the buffers.
 */
typedef struct st_LXtSurfFragment {
        double		dist;
        double		color[3];
        double		transparency[3];
} LXtSurfFragment;


/*
 * The raymarching interface allows volume elements to contribute to raytracing by
 * adding volume samples to the ray. Once all the volume elements have been evaluated
 * the ray is 'flattened' and the resulting opacity and scattering values are passed
 * to the raytracer.
 * - AddVolume adds a volume sample to the ray. The volume sample has scattering and opacity values
 * as well as a size (along the ray) called 'stride'.
 * - AddSurface adds a surface sample to the ray. The surface sample is a sample with 0 stride and
 * is handled differently when computing the transmittance function.
 * - GetOpacity at any point during raymarching it is possible to evaluate the opacity for a given distance
 * along the ray.
 * - ShaderEvaluate samples can be shaded using the default shader using this function. The resulting values
 * will be in the ShadeOutput packet.
 * 
 * - Jitter1D to avoid aliasing patterns it is better to jitter the sample positions. This function can be used
 * to produce a good jitter value which will be different for every pixel and for every successive call.
 * 
 * 
 */
typedef struct vt_ILxRaymarch {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddVolume) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        LXtVolumeSample		*vs);

        LXxMETHOD(  LxResult,
AddSurface) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        LXtSurfFragment		*ss);

        LXxMETHOD(  LxResult,
GetOpacity) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        double			 dist,
        double			*opa);

        LXxMETHOD(  LxResult,
ShaderEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        LXtObjectID		 shader);

        LXxMETHOD(  LxResult,
Jitter1D) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        float			*offset);
} ILxRaymarch;

/*
 * - FeatureCount, FeatureByIndex: returns the number and name of features in the voxel grid.
 * - BBox: Specifies the region in world space where the data is located.
 * - NextPos: During raymarching we need to march through the data efficiently. The NextPos method returns the next position in the voxel data that needs to be sampled, it will skip void regions to go directly to the next grid cells along the ray.
 * - Sample: The grid data can be sampled by position. This will return the data for the given position and feature index, the nature of the data depends on the feature type.
 * - VDBData: We directly expose a vdbData object pointer that can be passed around. If the volume data comes from an OpenVdb file this pointer can be passed to other items for operations such as filtering , meshing, etc.
 * - RayIntersect: This allows raycasting to be performed on the voxel data.
 * - RayRelease: This will be called to release any data allocated by the RayIntersect method.
 */
typedef struct vt_ILxVoxel {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
FeatureCount) (
        LXtObjectID		 self,
        unsigned		*num);

        LXxMETHOD(  LxResult,
FeatureByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        const char		**name);

        LXxMETHOD(  LxResult,
BBox) (
        LXtObjectID		 self,
        LXtTableauBox		 bbox);

        LXxMETHOD(  LxResult,
NextPos) (
        LXtObjectID		 self,
        float			 currentPos,
        unsigned		 currentSegment,
        float			 stride,
        float			*segmentList,
        unsigned		*nextSegment,
        float			*nextPos);

        LXxMETHOD(  LxResult,
Sample) (
        LXtObjectID		 self,
        const LXtFVector	 pos,
        unsigned		 index,
        float			*val);

        LXxMETHOD(  LxResult,
VDBData) (
        LXtObjectID		 self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
RayIntersect) (
        LXtObjectID		 self,
        const LXtVector		 origin,
        const LXtFVector	 direction,
        unsigned		*numberOfSegments,
        float			**Segmentlist);

        LXxMETHOD(  LxResult,
RayRelease) (
        LXtObjectID		 self,
        unsigned		 numberOfSegments,
        float			**Segmentlist);
} ILxVoxel;

/*
 * Volumetric evaluation flags specify the context in which volumetric rays are
 * evaluated. More info about the context can be gathered from the raytrace flags.
 */

#define	LXfVOLUME_RAY_COLOR		(1<<0)	// color ray
#define	LXfVOLUME_RAY_OPACITY		(1<<1)	// shadow ray


        #define LXu_RAYMARCH		"1E84C5A8-C002-4120-BAB0-9EEB1722688B"
        #define LXa_RAYMARCH		"raymarch"
        #define LXsP_RAYMARCH		"raymarch"
        //[local]  ILxRaymarch
        //[export] ILxRaymarch rmrch

/*
 * Volumetric items can use and\or present a voxel interface to access volumetric data or export their own volumetric data to other items.
 * This is done with the voxel graph:
 */

#define	LXsGRAPH_VOXEL	"volumeVoxel"


#define LXsPKG_VOXEL_CHANNEL	"volumeVoxel.channel"


#define LXu_VOXEL		"A2B024D6-4D03-4FA0-B3CA-A7949D7F7B7A"
#define LXa_VOXEL		"voxel"
#define LXiVOXELSAMPLE_DTF	((unsigned)-1)
//[local]  ILxVoxel
//[export] ILxVoxel voxel

#endif
