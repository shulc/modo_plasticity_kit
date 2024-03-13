/*
 * LX rendercache module
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
#ifndef LX_rendercache_H
#define LX_rendercache_H

typedef struct vt_ILxRenderCacheService ** ILxRenderCacheServiceID;
typedef struct vt_ILxRenderCache ** ILxRenderCacheID;
typedef struct vt_ILxRenderCacheListener1 ** ILxRenderCacheListener1ID;
typedef struct vt_ILxRenderCacheListener ** ILxRenderCacheListenerID;
typedef struct vt_ILxGeoCacheSegment ** ILxGeoCacheSegmentID;
typedef struct vt_ILxGeoCacheSurface ** ILxGeoCacheSurfaceID;

#include <lxitem.h>
#include <lxshade.h>
#include <lxvertex.h>


/*
 * Surface visibility flags
 */
typedef struct st_LXtGeoCacheSrfVisibility {
        unsigned	camera		: 1;
        unsigned	indirect	: 1;
        unsigned	reflection	: 1;
        unsigned	refraction	: 1;
        unsigned	subscatter	: 1;
        unsigned	occlusion	: 1;
} LXtGeoCacheSrfVisibility;


/*
 * Create render cache. Caller can pass LXiRENDERCACHE_XXX flags to guide the cache initialization.
 */
typedef struct vt_ILxRenderCacheService {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
CreateRenderCache) (
        LXtObjectID	  self,
        void		**ppvObj,
        unsigned int	  createFlags);
} ILxRenderCacheService;

/*
 * Return current render cache time and time offsets (for motion blur).
 * Argument timeOffsets is an array of 2 double values.
 * Update render cache to given time. 
 * If render cache is created without LXfRENDERCACHE_TURN_OFF_AUTO_UPDATES flag, the method will return LXe_FAILED.
 * If time is the same as internal time no update will happen.
 * In that case specify the force to force the full render cache update.
 * 
 * Clear the render cache.
 * 
 * Return number of geo cache surfaces.
 * 
 * Get geo cache surface at given index.
 */
typedef struct vt_ILxRenderCache {
        ILxUnknown	 iunk;
        LXxMETHOD ( void,
Time) (
        LXtObjectID	 self,
        double		*time,
        double		*timeOffsets);
        LXxMETHOD ( LxResult,
Update) (
        LXtObjectID	 self,
        double		 time,
        int		 force);
        LXxMETHOD ( void,
Clear) (
        LXtObjectID	 self);
        LXxMETHOD ( LxResult,
GeoSurfaceCount) (
        LXtObjectID	 self,
        int		*count);
        LXxMETHOD ( LxResult,
GeoSurfaceAt) (
        LXtObjectID	  self,
        int		  index,
        void		**srf);
} ILxRenderCache;

typedef struct vt_ILxRenderCacheListener1 {
        ILxUnknown	 iunk;
        LXxMETHOD (void,
RenderCacheDestroy) (
        LXtObjectID		self);

        LXxMETHOD (void,
UpdateBegin) (
        LXtObjectID		self);

        LXxMETHOD (void,
UpdateEnd) (
        LXtObjectID		self);

        LXxMETHOD (void,
GeoCacheSurfaceAdd )(
        LXtObjectID		self,
        LXtObjectID		geoSrf);

        LXxMETHOD (void,
GeoCacheSurfaceRemove )(
        LXtObjectID		self,
        LXtObjectID		geoSrf);

        LXxMETHOD (void,
GeoCacheSurfaceGeoUpdate )(
        LXtObjectID		self,
        LXtObjectID		geoSrf);

        LXxMETHOD (void,
GeoCacheSurfaceXformUpdate )(
        LXtObjectID		self,
        LXtObjectID		geoSrf);

        LXxMETHOD (void,
GeoCacheSurfaceShaderUpdate )(
        LXtObjectID		self,
        LXtObjectID		geoSrf);
} ILxRenderCacheListener1;

/*
 * Called when render cache is being destroyed. 
 * This happens when user changes the current scene (if LXfRENDERCACHE_TRACK_CURRENT_SCENE was specified).  
 * Called after the geo surface has been added to cache.
 * 
 * Called before the geo surface has been removed from cache.
 * 
 * Called when the geo surface data has been changed (this method is called only for non-instanced surfaces).
 * 
 * Called when the xform data has been changed.
 * 
 * Called when the shading data has been changed.
 * 
 * Called when render cache is cleared.
 */
typedef struct vt_ILxRenderCacheListener {
        ILxUnknown	 iunk;
        LXxMETHOD (void,
RenderCacheDestroy) (
        LXtObjectID		self);

        LXxMETHOD (void,
UpdateBegin) (
        LXtObjectID		self);

        LXxMETHOD (void,
UpdateEnd) (
        LXtObjectID		self);
        LXxMETHOD (void,
GeoCacheSurfaceAdd )(
        LXtObjectID		self,
        LXtObjectID		geoSrf);
        LXxMETHOD (void,
GeoCacheSurfaceRemove )(
        LXtObjectID		self,
        LXtObjectID		geoSrf);
        LXxMETHOD (void,
GeoCacheSurfaceGeoUpdate )(
        LXtObjectID		self,
        LXtObjectID		geoSrf);
        LXxMETHOD (void,
GeoCacheSurfaceXformUpdate )(
        LXtObjectID		self,
        LXtObjectID		geoSrf);
        LXxMETHOD (void,
GeoCacheSurfaceShaderUpdate )(
        LXtObjectID		self,
        LXtObjectID		geoSrf);
        LXxMETHOD (void,
RenderCacheClear) (
        LXtObjectID		self);
} ILxRenderCacheListener;

/*
 * Return the segment's bounding box in the world-space.
 * 
 * 
 * 
 * All polygons in the segments have same number of vertices in the polygon.
 * It can be 3 for triangles, 2 for curves and (hair & fur) and 1 for particles.
 * 
 * Return if the vertex feature is stored in the segment.
 * OPOS and ONRM are always stored.
 * The count for WVEL, RAD and FUR will be either 0 or 1.
 * For UV, DPDU and DPDV the count will return how many UV vmaps are stored in the segment.
 * 
 * Segment vertex feature is copied per-polygon-per-vertex into client's memory (like a triangle soup).
 * Caller can specify the start offset into the segment's data.
 * The start and count are in number of elements which are from 0 to VertsPerPoly * PolygonCount (not in byte size).
 * 
 * Segment vertex feature is copied per-vertex into client's memory.
 * Caller can specify the start offset into the segment's data.
 * The start and count are in number of elements which are from 0 to VertexCount (not in byte size).
 * 
 * Copy polygon vertex indices into client's memory.
 * Caller can specify the start offset into the segment's data.
 * The start and count are in number of elements which are from 0 to VertsPerPoly * PolygonVertexCount (not in byte size).
 */
typedef struct vt_ILxGeoCacheSegment {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
GetBBox ) (
        LXtObjectID		 self,
        LXtBBox			*bbox);
        LXxMETHOD ( void,
PolygonCount) (
        LXtObjectID		 self,
        int			*count);
        LXxMETHOD ( void,
VertexCount) (
        LXtObjectID		 self,
        int			*count);
        LXxMETHOD ( void,
VertsPerPoly) (
        LXtObjectID		 self,
        int			*count);
        LXxMETHOD ( void,
VertexFeatureCount) (
        LXtObjectID		 self,
        int			 feature,
        int			*count);
        LXxMETHOD ( LxResult,
GetPolygonVertexFeature) (
        LXtObjectID		 self,
        int			 feature,
        void			*featureData,
        int			 count,
        int			 start);
        LXxMETHOD ( LxResult,
GetVertexFeature) (
        LXtObjectID		 self,
        int			 feature,
        void			*featureData,
        int			 count,
        int			 start);
        LXxMETHOD (LxResult,
GetPolygonVertexInds) (
        LXtObjectID		 self,
        int			*polyVertexInds,
        int			 count,
        int			 start);
} ILxGeoCacheSegment;

/*
 * Obtain geo surface shader mask name (for example Surf(ShaderMaskName)).
 * Returns one of LXi_SURF_XXX flags.
 * 
 * Every surface has a source item. For replicated and instanced surfaces this method
 * will return the source mesh.
 * 
 * Returns 1 if surface is instanced.
 * 
 * Returns surface instance index, if surface is not instanced the returned value is -1.
 * 
 * If geo surface is instanced then it doesn't contain any geometry segments.
 * This mehtod returns the source geo cache surface which contains the segment data.
 * 
 * 
 * Obtain surface's bounding box.
 * 
 * Return surface's xform information at given time endpoint (T0 or T1).
 * T0 (=0) is time for shutter open, T1 (=1) is time for shutter close.
 * 
 * Return how many segments are in this surface.
 * 
 * Return how many polygons are in this surface.
 * 
 * Return how many vertices are in this surface.
 * 
 * Get segment by index
 * 
 * Return surface visibility flags (visible in camera, etc.)
 * 
 * Return surface unique id.
 * 
 * Return if surface is valid, i.e. not deleted.
 * 
 * Populate geometry segments with vertices and polygons.
 * If surface is already populated this method will do nothing.
 * Use this method when you want to populate geometry cache on-demand.
 * 
 * 
 * Return ILxTableauVertexID which can be used to query vertex information.
 * 
 * 
 * 
 * 
 * Return the number of shader tree layers applicable to this surface.
 * 
 * Extract the shader tree layer item at the specified index.
 */
typedef struct vt_ILxGeoCacheSurface {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
ShaderMaskName) (
        LXtObjectID		  self,
        const char		**name);
        LXxMETHOD ( int,
ShaderMaskType) (
        LXtObjectID		 self);
        LXxMETHOD ( LxResult,
SourceItem) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD ( int,
IsInstanced) (
        LXtObjectID		  self);
        LXxMETHOD ( int,
InstanceIndex) (
        LXtObjectID		  self);
        LXxMETHOD ( LxResult,
SourceSurface) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD ( LxResult,
GetBBox) (
        LXtObjectID		 self,
        LXtBBox			*bbox);
        LXxMETHOD ( LxResult,
GetXfrm) (
        LXtObjectID		  self,
        LXtVector		  pos,
        LXtMatrix		  rot,
        LXtVector		  scl,
        int				  endpoint);
        LXxMETHOD ( void,
SegmentCount) (
        LXtObjectID		 self,
        int			*count);
        LXxMETHOD ( void,
PolygonCount) (
        LXtObjectID		 self,
        int			*count);
        LXxMETHOD ( void,
VertexCount) (
        LXtObjectID		 self,
        int			*count);
        LXxMETHOD ( LxResult,
SegmentAt) (
        LXtObjectID		  self,
        int			  index,
        void			**segment);
        LXxMETHOD ( LxResult,
VisibilityFlags) (
        LXtObjectID			 self,
        LXtGeoCacheSrfVisibility	*flags);
        LXxMETHOD ( int,
ID) (
        LXtObjectID		  self);
        LXxMETHOD ( int,
IsValid) (
        LXtObjectID		  self);
        LXxMETHOD ( LxResult,
LoadSegments) (
        LXtObjectID		  self);
        LXxMETHOD ( LxResult,
UnloadSegments) (
        LXtObjectID		  self);
        LXxMETHOD ( ILxTableauVertexID,
GetVertexDesc )(
        LXtObjectID		  self);
        LXxMETHOD (const char*,
MaterialPTag ) (
        LXtObjectID		  self);
        LXxMETHOD (const char*,
PartPTag ) (
        LXtObjectID		  self);
        LXxMETHOD (const char*,
PickPTag ) (
        LXtObjectID		  self);
        LXxMETHOD ( LxResult,
ShaderLayerCount) (
        LXtObjectID	 self,
        unsigned int		*count);
        LXxMETHOD ( LxResult,
ShaderLayerAt) (
        LXtObjectID		self,
        unsigned int	index,
        void			**shaderLayer);
} ILxGeoCacheSurface;


        #define LXu_RENDERCACHESERVICE	"138FF638-1E34-4CC6-BAFC-4F734969F47E"
        #define LXa_RENDERCACHESERVICE	"rendercacheservice"

        // [python] ILxRenderCacheService:CreateRenderCache		obj RenderCache


        #define LXfRENDERCACHE_GEOCACHE_DISPLACE				0x1
        #define LXfRENDERCACHE_GEOCACHE_GENFUR					0x2
        #define LXfRENDERCACHE_FULL						LXfRENDERCACHE_GEOCACHE_DISPLACE | LXfRENDERCACHE_GEOCACHE_GENFUR
        #define LXfRENDERCACHE_TRACK_CURRENT_SCENE				0x100
        #define LXfRENDERCACHE_TURN_OFF_AUTO_UPDATES				0x200
        #define LXfRENDERCACHE_FORCE_FULL_UPDATE				0x400


        #define LXu_RENDERCACHE	"1ED14AD3-B202-46FF-A720-A1DCFC0B893A"
        #define LXa_RENDERCACHE	"rendercache"

        // [local] ILxRenderCache


        #define LXu_RENDERCACHELISTENER1	"E1EBCD71-B28A-42FB-9AF7-FADA18FEBFC6"


        #define LXu_RENDERCACHELISTENER	"BBF6E7B5-C59D-45D2-97E6-F49592A7EA6A"

        // [export] ILxRenderCacheListener rli


        #define LXu_GEOCACHESEGMENT	"CDA6EDAD-8E71-4EA9-A05A-326CEAD7DE9B"
        #define LXa_GEOCACHESEGMENT	"rendercachegeosegment"

        // [local] ILxGeoCacheSegment


        #define LXiRENDERCACHE_GEOVERT_OPOS		0		// Object-space position (LXtFVector)
        #define LXiRENDERCACHE_GEOVERT_ONRM		1		// Object-space normal (LXtFVector)
        #define LXiRENDERCACHE_GEOVERT_OVEL		2		// Object-space velocity (LXtFVector)
        #define LXiRENDERCACHE_GEOVERT_RAD		3		// Vertex radius (float)
        #define LXiRENDERCACHE_GEOVERT_FUR		4		// Fur params (LXtFVector [U, V(=lenParm), id])

        #define LXiRENDERCACHE_GEOVERT_UV		0x100		// Vertex UV coords. (LXtFVector2)
        #define LXiRENDERCACHE_GEOVERT_DPDU		0x200		// Vertex UV derivatives (LXtFVector3)
        #define LXiRENDERCACHE_GEOVERT_DPDV		0x300		// Vertex UV derivatives (LXtFVector3)


        #define LXu_GEOCACHESURFACE	"770BD566-315B-4EEC-A2A5-266D122D8DDF"
        #define LXa_GEOCACHESURFACE	"rendercachegeosurface"

        // [local] ILxGeoCacheSurface
        // [python] ILxGeoCacheSurface:SegmentAt	obj	GeoCacheSegment

#endif
