/*
 * LX mesh module
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
#ifndef LX_mesh_H
#define LX_mesh_H

typedef struct vt_ILxMeshService ** ILxMeshServiceID;
typedef struct vt_ILxMesh ** ILxMeshID;
typedef struct vt_ILxMesh1 ** ILxMesh1ID;
typedef struct vt_ILxMesh2 ** ILxMesh2ID;
typedef struct vt_ILxPoint ** ILxPointID;
typedef struct vt_ILxPolygon ** ILxPolygonID;
typedef struct vt_ILxPolygon1 ** ILxPolygon1ID;
typedef struct vt_ILxEdge ** ILxEdgeID;
typedef struct vt_ILxMeshMap ** ILxMeshMapID;
typedef struct vt_ILxMeshListener ** ILxMeshListenerID;
typedef struct vt_ILxMeshListener1 ** ILxMeshListener1ID;
typedef struct vt_ILxMeshTracker ** ILxMeshTrackerID;
typedef struct vt_ILxMeshOperation ** ILxMeshOperationID;
typedef struct vt_ILxMeshOperation2 ** ILxMeshOperation2ID;
typedef struct vt_ILxMeshOperation1 ** ILxMeshOperation1ID;
typedef struct vt_ILxMeshFilter ** ILxMeshFilterID;
typedef struct vt_ILxMeshFilter1 ** ILxMeshFilter1ID;
typedef struct vt_ILxMeshFilterBBox ** ILxMeshFilterBBoxID;
typedef struct vt_ILxMeshFilterIdent ** ILxMeshFilterIdentID;
typedef struct vt_ILxMeshFilterBlend ** ILxMeshFilterBlendID;
typedef struct vt_ILxMeshBlend ** ILxMeshBlendID;
typedef struct vt_ILxMeshMetaData ** ILxMeshMetaDataID;
typedef struct vt_ILxMeshXtraData ** ILxMeshXtraDataID;

#include <lxserver.h>
#include <lxvmath.h>

/*
 * Mark modes are collections of bits of two types: the ones required to be set
 * and ones required to be clear.  To be specific, this is not simply turning a
 * bit on or off; a bit can be required to be set or can be required to be clear
 * based on the mark mode.  The mesh service allows mark mode masks to be created
 * and read via strings.  The mode which matches anything (and changes nothing)
 * is always just zero.
 */

        typedef unsigned int	LXtMarkMode;
        #define LXiMARK_ANY	((LXtMarkMode) 0)

        #define LXsMARK_HIDE	"hide"
        #define LXsMARK_HALO	"halo"
        #define LXsMARK_LOCK	"lock"
        #define LXsMARK_SELECT	"select"
        #define LXsMARK_DELTA	"delta"
        #define LXsMARK_USER_0	"user0"
        #define LXsMARK_USER_1	"user1"
        #define LXsMARK_USER_2	"user2"
        #define LXsMARK_USER_3	"user3"
        #define LXsMARK_USER_4	"user4"
        #define LXsMARK_USER_5	"user5"
        #define LXsMARK_USER_6	"user6"
        #define LXsMARK_USER_7	"user7"

/*
 * Defined here and in lxmeshOLD, protected because of gcc whining.
 */

        #ifndef   LX_DEF_LXTMESHID
          #define LX_DEF_LXTMESHID
          typedef struct st_Mesh * 	LXtMeshID;
        #endif


        #define LXf_TESS_TRIPLE		 0x01
        #define LXf_TESS_COPYFACE	 0x10

/*
 * Points, polygons, edges and maps are referenced by these types.
 * These are not COM objects, but are simply identifiers for specific elements
 * which are then accessed through the accessors.
 */

        typedef struct st_MeshVertex *	  LXtPointID;
        typedef struct st_MeshPolygon *	  LXtPolygonID;
        typedef struct st_MeshEdge *	  LXtEdgeID;
        typedef struct st_MeshVertexMap * LXtMeshMapID;

        // [python] type LXtPointID	id
        // [python] type LXtPolygonID	id
        // [python] type LXtEdgeID	id
        // [python] type LXtMeshMapID	id


/*
 * - type
 * The type is 3 or 4, where 3 indicates that this is a triangle mesh and
 * 4 indicates that it is a quad mesh.  A type of zero indicates no mesh.
 * - nvrt, vrts, norm
 * The vertices of the polygon mesh are given by an array of floats organized into
 * 'nvrt' triples.  The normals for each vertex, if requested, are accessed in the
 * same manner as the vertex coordinates, unless the normals vmap is available.
 * - npol, pols
 * The polygons in the mesh are specified by indices into the vertex array.  There
 * are 'npol' polygons and the indices are grouped into triples or quads based on
 * the mesh type.
 * 
 * - ntex, itex, wtex
 * Texture information is organized into a set of tuples.  Each point in the mesh
 * is associated with an n-tuple of polygon vertices and weights, with the tuple
 * size specified by 'ntex.'  The 'itex' array holds the indices of the polygon
 * vertices, with 'wtex' giving the weight for each.
 * 
 */
typedef struct st_LXtPolyMeshInfo {
        unsigned int		 flag;
        unsigned int		 type;
        unsigned int		 nvrt;
        unsigned int		 npol;
        unsigned int		 ntex;
        const unsigned int	*pols;
        const float		*vrts;
        const float		*norm;
        const unsigned int	*itex;
        const float		*wtex;
} LXtPolyMeshInfo;


/*
 * 
 * This method allows multiple mode bits to be marked as "must be set" or
 * "must be cleared".  The two arguments take a space-delimited list of modes
 * to set or clear, failing with LXe_NOTFOUND if the mode is unknown.  Either
 * argument can be NULL.
 * 
 * Vertex map types have names and codes which can be translated with these functions.
 * 
 * It can also be useful to find the features of a vertex map type without requiring
 * an actual instance. These functions are equivalent to the same-named functions in
 * the mesh map interface.
 * 
 * Clients can create their own private mesh objects, not affiliated with any
 * item.
 * 
 * This converts a private mesh to a static mesh.
 * 
 * Some of the tool packets still use the obsolete LXtMeshID type. These functions
 * allow you to convert between mesh IDs and mesh objects. These functions should
 * be used carefully since they're not very safe. That's why the LXtMeshID was
 * retired in the first place.
 * 
 * This converts any surface to a static mesh.
 * 
 * This converts a static mesh to an editable mesh.
 * 
 * Static meshes can be rigidly transformed.
 * 
 * Creates a ILxPolygonSlice object which slices polygons.
 * 
 * Creates a ILxSolidDrill object which slices polygons.
 * 
 * This returns LXe_TRUE if the specified mesh item is procedural and LXe_FALSE
 * if it isn't.
 * 
 * Returns an Item object that a mesh belongs to. For private meshes, the function
 * fails.
 * 
 * Returns a curve group for the provided mesh, allowing the polygonal curves to
 * be enumerated and evaluated.
 * 
 * Returns a mesh from a surface interface.
 * 
 * Returns a surface from a mesh. In the majority of cases, the mesh item can be
 * evaluated directly for a surface. However if you have a private mesh, this
 * function can be used.
 * 
 * Validates and returns the named mesh meta for the provided mesh.
 * 
 * Returns a tessellated mesh from source mesh. 'xfrm' transform new vertex position as
 * option. if COPYFACE is set then it copies raw face polygons without subdivision, otherwise
 * FACE polygons are tessellated to triangles. Subdivision surface polygons are tessellated
 * to quadrangles. if TRIPLE is set, subdivision surface are tesselated to triangles instead
 * of quadrangles.
 */
typedef struct vt_ILxMeshService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ModeCompose) (
        LXtObjectID		 self,
        const char		*set,
        const char		*clear,
        LXtMarkMode		*mode);
        LXxMETHOD(  LxResult,
VMapLookupType) (
        LXtObjectID		 self,
        const char		*name,
        LXtID4			*type);

        LXxMETHOD(  LxResult,
VMapLookupName) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char	       **name);
        LXxMETHOD(  LxResult,
VMapDimension) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		*dimension);

        LXxMETHOD(  LxResult,
VMapIsEdgeMap) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LxResult,
VMapIsContinuous) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LxResult,
VMapZeroDefault) (
        LXtObjectID		 self,
        LXtID4			 type);
        LXxMETHOD(  LxResult,
CreateMesh) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ConvertMesh) (
        LXtObjectID		 self,
        LXtObjectID		 triGroupObj,
        LXtObjectID		 meshObj);
        LXxMETHOD(  LxResult,
MeshFromMeshID) (
        LXtObjectID		 self,
        LXtMeshID		 meshID,
        void		       **ppvObj);

        LXxMETHOD(  LXtMeshID,
MeshToMeshID) (
        LXtObjectID		 self,
        LXtObjectID		 mesh);
        LXxMETHOD(  LxResult,
SurfaceToTriGroup) (
        LXtObjectID		 self,
        LXtObjectID		 triGroupObj,
        LXtObjectID		 surfObj);
        LXxMETHOD(  LxResult,
MeshFromTriGroup) (
        LXtObjectID		 self,
        LXtObjectID		 meshObj,
        LXtObjectID		 triGroupObj);
        LXxMETHOD(  LxResult,
TriGroupTransform) (
        LXtObjectID		 self,
        LXtObjectID		 triGroupObj,
        LXtMatrix4		 xfrm);
        LXxMETHOD(  LxResult,
CreateSlice) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
CreateSolidDrill) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
IsMeshProcedural) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD(  LxResult,
ItemFromMesh) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
CurveGroupFromMesh) (
        LXtObjectID		  self,
        LXtObjectID		  mesh,
        const LXtMatrix4	  xfrm,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
MeshFromSurface) (
        LXtObjectID		 self,
        LXtObjectID		 meshObj,
        LXtObjectID		 surfItem,
        LXtObjectID		 surfObj);
        LXxMETHOD(  LxResult,
SurfaceFromMesh) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtObjectID		 meshItem,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ValidateMetaData) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        const char		*name,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Tessellate) (
        LXtObjectID		 self,
        LXtObjectID		 meshTess,
        LXtObjectID		 meshSource,
        const LXtMatrix4	 xfrm,
        unsigned int		 flags);
} ILxMeshService;

/*
 * These methods return the number of elements of their type in the mesh.
 * 
 * This method returns the bounding box of the mesh.
 * 
 * This method returns the maximum number of polygons shared by any point in
 * the mesh.
 * 
 * This method returns the maximum size of any polygon marked in the mesh.
 * 
 * Sets the the value of the specified tag that will be applied
 * to any newly created polys.
 * 
 * Most data about a mesh is obtained through the accessors.  These
 * methods return new accessors, which must be released by the client when
 * no longer needed.  Multiple accessors can exist at the same time for the
 * same mesh without conflicting.  Accessors can be used to walk the list
 * of elements in a mesh or to obtain specific information about a particular
 * element.
 * These methods create and return the various accessors.  Each one is unique
 * to the caller can so can be used in parallel with others obtained from
 * these methods.
 * 
 * 
 * If a mesh is accessed for write, any edits made have to be signalled back to the
 * mesh.
 * 
 * Polygon types can have overall settings that affect all the polygons of that
 * type in the mesh.
 * Set and get SUBD subdivision level for the mesh.
 * 
 * 
 * 
 * Set and get SUBD UV interpolation flag.
 * 
 * 
 * 
 * 
 * Give a mesh interface and another mesh object, this returns true if they
 * refer to the same actual mesh.
 * 
 * These methods separate contents of a PICK ptag into component selection sets,
 * presenting a list of the distinct selection sets, rather than the large and
 * redundant list of all distinct PICK poly tag values.
 * 
 * 
 * Set and get PSUB subdivision level for the mesh.
 * 
 * 
 * Set and get PSUB subdivision level for the mesh.
 * 
 * 
 * 
 * 
 * Multi-Resolution layers are new displacement data for 901. Displpacement vectors
 * in layers are composited based on the opacity ratio.
 * This method returns number of multi-resolution layer.
 * 
 * 
 * This method returns name of multi-resolution layer for given layer index.
 * 
 * This method look up multi-resolution layer by layer name and set the index
 * and retruns OK if it is found.
 * 
 * This method returns the current selected multi-resolution layer.
 * index.
 * 
 * This method returns the enable state of multi-resolution layer for given
 * layer index.
 * 
 * This method returns the opacity of multi-resolution layer for given layer 
 * index.
 * 
 * This method set the opacity of multi-resolution layer for given layer index.
 * This is not undoable action.
 * 
 * If multiple operations need to be batched together, this function will start and end
 * a mesh edit batch on the specified mesh.
 * 
 * 
 * This removes all data in the current mesh.
 * 
 * Often, it can be useful to track multiple changes to a mesh within a particular
 * time period. The TrackChanges function returns an ILxMeshTracker interface. The
 * MeshTracker will collect a series of changes to a base mesh, along with a list
 * of modified points and polygons. Multiple trackers can be created per mesh, each
 * with their own lifetime, independent of the mesh.
 * 
 * This merges the provided mesh with the current mesh, copying all the data from
 * other. The flags argument controls which elements are copied from the source mesh
 * to the target mesh. A matrix can also be provided to apply as transform to all
 * merged elements.
 */
typedef struct vt_ILxMesh {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
PointCount) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD(  LxResult,
PolygonCount) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD(  LxResult,
EdgeCount) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD(  LxResult,
MapCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
BoundingBox) (
        LXtObjectID		 self,
        LXtMarkMode		 pick,
        LXtBBox			*bbox);
        LXxMETHOD(  LxResult,
MaxPointPolygons) (
        LXtObjectID		 self,
        LXtMarkMode		 pick,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
MaxPolygonSize) (
        LXtObjectID		 self,
        LXtMarkMode		 pick,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
PolyTagSetDefault) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*tag);
        LXxMETHOD(  LxResult,
PointAccessor) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
PolygonAccessor) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
EdgeAccessor) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
MeshMapAccessor) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
SetMeshEdits) (
        LXtObjectID		 self,
        unsigned int		 edits);
        LXxMETHOD(  LxResult,
SUBDGetLevel) (
        LXtObjectID		 self,
        int			*n);
        LXxMETHOD(  LxResult,
SUBDSetLevel) (
        LXtObjectID		 self,
        int			 n);
        LXxMETHOD(  LxResult,
SUBDGetLinearUV) (
        LXtObjectID		 self,
        int			*isLinear);
        LXxMETHOD(  LxResult,
SUBDSetLinearUV) (
        LXtObjectID		 self,
        int			 isLinear);
        LXxMETHOD(  LxResult,
PSUBGetBoundRule) (
        LXtObjectID		 self,
        int			*bound);
        LXxMETHOD(  LxResult,
PSUBSetBoundRule) (
        LXtObjectID		 self,
        int			 bound);
        LXxMETHOD(  LxResult,
TestSameMesh) (
        LXtObjectID		 self,
        LXtObjectID		 other);
        LXxMETHOD(  unsigned,
PTagCount) (
        LXtObjectID		 self,
        LXtID4			 type);
        LXxMETHOD(  LxResult,
PTagByIndex) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned		 index,
        const char		**tag);
        LXxMETHOD(  LxResult,
PSUBGetLevel) (
        LXtObjectID		 self,
        int			*n);
        LXxMETHOD(  LxResult,
PSUBSetLevel) (
        LXtObjectID		 self,
        int			 n);
        LXxMETHOD(  LxResult,
PSUBGetCurrentLevel) (
        LXtObjectID		 self,
        int			*n);
        LXxMETHOD(  LxResult,
PSUBSetCurrentLevel) (
        LXtObjectID		 self,
        int			 n);
        LXxMETHOD(  LxResult,
PSUBSetSubdivObj) (
        LXtObjectID		 self,
        LXtObjectID		 subObj);
        LXxMETHOD(  LxResult,
ChangeEvent) (
        LXtObjectID		 self,
        unsigned		 event);
        LXxMETHOD(  LxResult,
PSUBDispNumLayer) (
        LXtObjectID		 self,
        int			*num);
        LXxMETHOD(  const char *,
PSUBDispLayerName) (
        LXtObjectID		 self,
        int			 index);
        LXxMETHOD(  LxResult,
PSUBDispLayerLookupByName) (
        LXtObjectID		 self,
        const char		*name,
        int			*index);
        LXxMETHOD(  LxResult,
PSUBDispLayerCurrent) (
        LXtObjectID		 self,
        int			*index);
        LXxMETHOD(  LxResult,
PSUBDispLayerEnable) (
        LXtObjectID		 self,
        int			 index,
        int			*enable);
        LXxMETHOD(  LxResult,
PSUBDispLayerOpacity) (
        LXtObjectID		 self,
        int			 index,
        double			*opacity);
        LXxMETHOD(  LxResult,
PSUBDispLayerSetOpacity) (
        LXtObjectID		 self,
        int			 index,
        double			 opacity);
        LXxMETHOD( LxResult,
BeginEditBatch) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
EndEditBatch) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Merge) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        unsigned int		 flags);
        LXxMETHOD(  LxResult,
Clear) (
        LXtObjectID		 self);
        LXxMETHOD (  LxResult,
TrackChanges) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
MergeWithTransform) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        const LXtMatrix4	 xfrm,
        unsigned int		 flags);
} ILxMesh;

typedef struct vt_ILxMesh1 {
        ILxUnknown	 iunk;
                LXxMETHOD(  LxResult,
        PointCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        PolygonCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        EdgeCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        MapCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        BoundingBox) (
                LXtObjectID              self,
                LXtMarkMode              pick,
                LXtBBox                 *bbox);

                LXxMETHOD(  LxResult,
        MaxPointPolygons) (
                LXtObjectID              self,
                LXtMarkMode              pick,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        MaxPolygonSize) (
                LXtObjectID              self,
                LXtMarkMode              pick,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        PolyTagSetDefault) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *tag);

                LXxMETHOD(  LxResult,
        PointAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        PolygonAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        EdgeAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        MeshMapAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        SetMeshEdits) (
                LXtObjectID              self,
                unsigned int             edits);

                LXxMETHOD(  LxResult,
        SUBDGetLevel) (
                LXtObjectID              self,
                int                     *n);

                LXxMETHOD(  LxResult,
        SUBDSetLevel) (
                LXtObjectID              self,
                int                      n);

                LXxMETHOD(  LxResult,
        SUBDGetLinearUV) (
                LXtObjectID              self,
                int                     *isLinear);

                LXxMETHOD(  LxResult,
        SUBDSetLinearUV) (
                LXtObjectID              self,
                int                      isLinear);

                LXxMETHOD(  LxResult,
        PSUBGetBoundRule) (
                LXtObjectID              self,
                int                     *bound);

                LXxMETHOD(  LxResult,
        PSUBSetBoundRule) (
                LXtObjectID              self,
                int                      bound);

                LXxMETHOD(  LxResult,
        TestSameMesh) (
                LXtObjectID              self,
                LXtObjectID              other);

                LXxMETHOD(  unsigned,
        PTagCount) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LxResult,
        PTagByIndex) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned                 index,
                const char              **tag);

                LXxMETHOD(  LxResult,
        PSUBGetLevel) (
                LXtObjectID              self,
                int                     *n);

                LXxMETHOD(  LxResult,
        PSUBSetLevel) (
                LXtObjectID              self,
                int                      n);

                LXxMETHOD(  LxResult,
        PSUBGetCurrentLevel) (
                LXtObjectID              self,
                int                     *n);

                LXxMETHOD(  LxResult,
        PSUBSetCurrentLevel) (
                LXtObjectID              self,
                int                      n);

                LXxMETHOD(  LxResult,
        PSUBSetSubdivObj) (
                LXtObjectID		 self,
                LXtObjectID		 subObj);

                LXxMETHOD(  LxResult,
        ChangeEvent) (
                LXtObjectID		 self,
                unsigned		 event);

                LXxMETHOD(  LxResult,
        PSUBDispNumLayer) (
                LXtObjectID		 self,
                int			*num);

                LXxMETHOD(  const char *,
        PSUBDispLayerName) (
                LXtObjectID		 self,
                int			 index);

                LXxMETHOD(  LxResult,
        PSUBDispLayerLookupByName) (
                LXtObjectID		 self,
                const char		*name,
                int			*index);

                LXxMETHOD(  LxResult,
        PSUBDispLayerCurrent) (
                LXtObjectID		 self,
                int			*index);

                LXxMETHOD(  LxResult,
        PSUBDispLayerEnable) (
                LXtObjectID		 self,
                int			 index,
                int			*enable);

                LXxMETHOD(  LxResult,
        PSUBDispLayerOpacity) (
                LXtObjectID		 self,
                int			 index,
                double			*opacity);

                LXxMETHOD(  LxResult,
        PSUBDispLayerSetOpacity) (
                LXtObjectID		 self,
                int			 index,
                double			 opacity);

                LXxMETHOD( LxResult,
        BeginEditBatch) (
                LXtObjectID		 self);

                LXxMETHOD( LxResult,
        EndEditBatch) (
                LXtObjectID		 self);

                LXxMETHOD(  LxResult,
        Merge) (
                LXtObjectID		 self,
                LXtObjectID		 other);

                LXxMETHOD(  LxResult,
        Clear) (
                LXtObjectID		 self);
} ILxMesh1;

typedef struct vt_ILxMesh2 {
        ILxUnknown	 iunk;
                LXxMETHOD(  LxResult,
        PointCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        PolygonCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        EdgeCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        MapCount) (
                LXtObjectID              self,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        BoundingBox) (
                LXtObjectID              self,
                LXtMarkMode              pick,
                LXtBBox                 *bbox);
                LXxMETHOD(  LxResult,
        MaxPointPolygons) (
                LXtObjectID              self,
                LXtMarkMode              pick,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        MaxPolygonSize) (
                LXtObjectID              self,
                LXtMarkMode              pick,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        PolyTagSetDefault) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *tag);
                LXxMETHOD(  LxResult,
        PointAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        PolygonAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        EdgeAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        MeshMapAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        SetMeshEdits) (
                LXtObjectID              self,
                unsigned int             edits);
                LXxMETHOD(  LxResult,
        SUBDGetLevel) (
                LXtObjectID              self,
                int                     *n);
                LXxMETHOD(  LxResult,
        SUBDSetLevel) (
                LXtObjectID              self,
                int                      n);
                LXxMETHOD(  LxResult,
        SUBDGetLinearUV) (
                LXtObjectID              self,
                int                     *isLinear);
                LXxMETHOD(  LxResult,
        SUBDSetLinearUV) (
                LXtObjectID              self,
                int                      isLinear);
                LXxMETHOD(  LxResult,
        PSUBGetBoundRule) (
                LXtObjectID              self,
                int                     *bound);
                LXxMETHOD(  LxResult,
        PSUBSetBoundRule) (
                LXtObjectID              self,
                int                      bound);
                LXxMETHOD(  LxResult,
        TestSameMesh) (
                LXtObjectID              self,
                LXtObjectID              other);
                LXxMETHOD(  unsigned,
        PTagCount) (
                LXtObjectID              self,
                LXtID4                   type);
                LXxMETHOD(  LxResult,
        PTagByIndex) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned                 index,
                const char              **tag);
                LXxMETHOD(  LxResult,
        PSUBGetLevel) (
                LXtObjectID              self,
                int                     *n);
                LXxMETHOD(  LxResult,
        PSUBSetLevel) (
                LXtObjectID              self,
                int                      n);
                LXxMETHOD(  LxResult,
        PSUBGetCurrentLevel) (
                LXtObjectID              self,
                int                     *n);
                LXxMETHOD(  LxResult,
        PSUBSetCurrentLevel) (
                LXtObjectID              self,
                int                      n);
                LXxMETHOD( LxResult,
        BeginEditBatch) (
                LXtObjectID		 self);
                LXxMETHOD( LxResult,
        EndEditBatch) (
                LXtObjectID		 self);
} ILxMesh2;

/*
 * As mentioned previously, all accessors share common interface methods for
 * walking their respective lists.
 * This method sets the accessor to the given point.  Only points that
 * are known to be in the mesh should be passed to this method.
 * 
 * A point can be selected by its index in the mesh.
 * 
 * A point can also be selected by its index within a polygon.
 * 
 * This methods returns the ID of the curent point or null if none.
 * 
 * This methods returns the index of the curent point.
 * 
 * This returns the position of the point.
 * 
 * This method returns the geometric normal of this point for the given polygon.
 * This is the average of the connected polyon normals if the polygon is null.
 * 
 * This returns the value of the current point in the given map.  This
 * returns LXe_FALSE for points with no value set in the map.
 * 
 * This method is the same as MapValue(), except that if the point is not in the
 * map it will return zero for maps that allow that.
 * 
 * These methods return the number of polygons sharing this point as a vertex,
 * and get the polygon ID for a specific index.
 * 
 * This creates a new point in the mesh.  It sets the current point to the new
 * point.
 * 
 * This creates a new point in the mesh duplicating the current point.
 * If this point has already been copied this function returns the same pointer.
 * 
 * This removes a point from the mesh.  Any polygons that use this point should
 * already have been altered to remove the point from their vertex list.  Maps
 * are automatically updated to reflect the removed point.
 * 
 * This sets a point's position.
 * 
 * This sets the value for the point in the given map.
 * 
 * This removes any value for the point in the given map.
 * 
 * The corner control point for a vertex can also be accessed.  This is the
 * location of the actual intersection of the patch mesh.
 * 
 * These methods return the number of points connecting this point as a point,
 * and get the point ID for a specific index.
 * 
 * 
 * These methods return the number of edges connecting this point as a point,
 * and get the edge ID for a specific index.
 * 
 * 
 * This sets the symmetric point corresponding to the current point when
 * the symmetry mode is enabled. This returns LXe_OK when the symmetric point
 * is found, otherwise it returns LXe_FAILED. When the current point is on
 * the symmetry center plane, it returns LXe_FAILED.
 * 
 * This returns LXe_TRUE if the symmetry state is enabled and the current point
 * is on the symmetry center plane, otherwise it returns LXe_FALSE.
 * 
 * This function returns the ILxMesh object associated with the point accessor.
 * 
 * This function returns the part number for the current point. All connected
 * points share the same part number.
 * 
 * Add a point to an edge made up for Verts A and B.
 */
typedef struct vt_ILxPoint {
        ILxUnknown	 iunk;
        // QWEB_MACRO_BEGIN - Common Accessor Methods
        LXxMETHOD(  LxResult,
Spawn) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Enumerate) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        LXtObjectID		 monitor);
        // QWEB_MACRO_END - Common Accessor Methods
        // QWEB_MACRO_BEGIN - Common Geometry Accessor Methods
        LXxMETHOD(  LxResult,
TestMarks) (
        LXtObjectID		 self,
        LXtMarkMode		 mode);
        LXxMETHOD(  LxResult,
SetMarks) (
        LXtObjectID		 self,
        LXtMarkMode		 set);
        // QWEB_MACRO_END - Common Geometry Accessor Methods
        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID		 self,
        LXtPointID		 point);
        LXxMETHOD(  LxResult,
SelectByIndex) (
        LXtObjectID		 self,
        unsigned int		 index);
        LXxMETHOD(  LxResult,
SelectPolygonVertex) (
        LXtObjectID		 self,
        LXtPolygonID		 polygon,
        unsigned int		 index);
        LXxMETHOD( LXtPointID,
ID) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Index) (
        LXtObjectID		 self,
        unsigned int		*index);
        LXxMETHOD(  LxResult,
Pos) (
        LXtObjectID		 self,
        LXtFVector		 pos);
        LXxMETHOD(  LxResult,
Normal) (
        LXtObjectID		 self,
        LXtPolygonID		 pol,
        LXtVector		 normal);
        LXxMETHOD(  LxResult,
MapValue) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        float			*value);
        LXxMETHOD(  LxResult,
MapEvaluate) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        float			*value);
        LXxMETHOD(  LxResult,
PolygonCount) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD(  LxResult,
PolygonByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtPolygonID		*polygonID);
        LXxMETHOD(  LxResult,
New) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        LXtPointID		*pointID);
        LXxMETHOD(  LxResult,
Copy) (
        LXtObjectID		 self,
        LXtPointID		*pointID);
        LXxMETHOD(  LxResult,
Remove) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
SetPos) (
        LXtObjectID		 self,
        const LXtVector		 pos);
        LXxMETHOD(  LxResult,
SetMapValue) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        const float		*value);
        LXxMETHOD(  LxResult,
ClearMapValue) (
        LXtObjectID		 self,
        LXtMeshMapID		 map);
        LXxMETHOD(  LxResult,
Corner) (
        LXtObjectID		 self,
        LXtFVector		 pos);
        LXxMETHOD(  LxResult,
PointCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
PointByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtPointID		*pointID);
        LXxMETHOD(  LxResult,
EdgeCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
EdgeByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtEdgeID		*edgeID);
        LXxMETHOD(  LxResult,
Symmetry) (
        LXtObjectID		 self,
        LXtPointID		*pointID);
        LXxMETHOD(  LxResult,
OnSymmetryCenter) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Mesh) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Part) (
        LXtObjectID		 self,
        unsigned int		*part);
        LXxMETHOD(  LxResult,
NewOnEdge) (
        LXtObjectID		 self,
        LXtPointID A,
        LXtPointID B,
        float percent,
        LXtPointID *newPoint);
} ILxPoint;

/*
 * As mentioned previously, all accessors share common interface methods for
 * walking their respective lists.
 * 
 * This method sets the accessor to the given polygon.
 * 
 * 
 * This method returns the ID of the current polygon.
 * 
 * This methods returns the index of the curent polygon.
 * 
 * This returns the type of the polygon.
 * 
 * These return the number of vertices in the polygon, and get the point ID's by
 * index.
 * 
 * There are two special polygon flags, which are used by curves.  The first
 * method returns LXe_TRUE if the first point on is an extended control point,
 * while the second returns true if the last point is a control point.  If
 * the polygon is not a curve, this method fails.
 * 
 * This method returns the geometric normal of this polygon.  This fails if there
 * is no normal or the polygon has only one or two points.  The normal is the same
 * as the normal for the triangle containing the first point.
 * 
 * This method gets the map value of a specific point in this polygon
 * given a map.  It returns LXe_FALSE if the specific is unmapped.
 * 
 * Evaluating the map first tries to find a discontinuous value specific to this
 * polygon.  If there is none it falls back on the continuous value for the point
 * itself.  Failing that it may return zero for a map that allows that.
 * 
 * This function returns the approximate surface area of the current polygon.
 * 
 * This method creates a new polygon of the given type from a prepared list
 * of point IDs.  If 'rev' is true, the point list will be used in reverse.
 * 
 * This method is the same as New(), but it copies the tags from the current
 * polygon which is used as a prototype.  Type can also be zero to copy the
 * polygon type from the prototype.
 * 
 * This removes a polygon from the mesh.
 * 
 * These set if the first or last endpoints of a curve are control points,
 * failing if this is not a curve-type polygon.
 * 
 * This method allows the vertex list of a polygon to be changed.
 * 
 * This sets the value in the given point map for a point/polygon pair.
 * The number of elements in the 'value' array should match the dimension
 * of the map.
 * 
 * This removes any value for the point/polygon pair in the given map.
 * 
 * Polygons can also be created from a contour. A contour defines a path that
 * can consist of multiple closed loops with reversed loops inside that act
 * as holes. this call starts a contour.
 * 
 * This call adds an edge to the contour. Edges must form a set of closed
 * loops.
 * 
 * When all the contour edges are added, this adds a set of polygons describing
 * the same surface as the closed contour. Since multiple polygons may be added
 * this only returns the new polygon ID if there was only one. Multiple polygons
 * must be inferred some other way.
 * 
 * This is the same but uses the current polygon as prototype for all the new
 * polygons to be created from the contour.
 * 
 * This method traces a ray with a given start position and direction (normalized).
 * If the ray intersects a polygon it sets the current polygon, sets the distance to
 * the hit point and the surface normal, and returns LXe_TRUE. It returns LXe_FALSE
 * if there are no polygons in the path of the ray.
 * 
 * This method finds the closest polygon from the given position. If it finds a polygon,
 * it sets the current polygon, the hit position, the distance to the hit position and
 * the surface normal, and returns LXe_TRUE. It returns LXe_FALSE if there are no polygons.
 * If 'maxDist' is set, the method finds polygons in the radius given by 'maxDist' from
 * the given position.
 * 
 * This returns the index of the point on the polygon.  It return -1 if the given point is
 * not belong to the polygon.
 * 
 * This returns the index of the edge on the polygon.  It return -1 if the given edge is
 * not belong to the polygon.
 * 
 * Returns the edge that is shared by both edges.
 * 
 * This returns LXe_TRUE if the polygon is on border or the polygon type is not surface.
 * 
 * Find a representative position for a polygon.  This returns a position that
 * is on the interior or the polygon but not on an edge.
 * 
 * Find a representative position for point list.  This returns an index that
 * is on the interior or the point list but not on an edge.
 * 
 * These functions provide a way to triagulate surface type polygons.
 * 'GenerateTriangles' generates triangle lists and it returns the number of triangle
 * to 'count'. If the current polygon is not a surface type, it returns FAILED.
 * 
 * 
 * This function returns three points consist of the triangle given by the index.
 * 'GenerateTriangles' must be called to generate triangle list before calling this
 * function.
 * 
 * This clears the internal triangle list.
 * 
 * Enumerate polygons using test conditions. The mode selects which subset of elements
 * to traverse. The visitor will be called with the accessor set to each successive
 * element.
 * This function enumerates the polygons conatined in the given bounding box.
 * 
 * 
 * This function enumerates the polygons along the ray given by its origin and
 * direction vectors.
 * 
 * This function enumerates the polygons along the line given by its origin and
 * direction vectors.
 * 
 * Create curve fill polygon from continuous linear type polygons.
 * 
 * This sets the symmetric point corresponding to the current polygon when
 * the symmetry mode is enabled. This returns LXe_OK when the symmetric polygon
 * is found, otherwise it returns LXe_FAILED.
 * 
 * This returns surface point, normal, DPDU and DPDV for a given UV position on the polygon.
 * The normal and the DPDU/DPDV can be null, if not interested in those values.
 * 
 * This function enumerates the polygons that contain the given texture coordinate position.
 * 
 * This function enumerates all the polygons with a given surface bin.
 * 
 * This function returns the ILxMesh object associated with the polygon accessor.
 * 
 * Clients can also enumerate over all polygons that have the same tags. The type
 * of tag must be specified, along with the value to match.
 * 
 * This function returns the part number for the current polygon. All connected
 * polygons share the same part number.
 * 
 * This function returns the uv part number for the current polygon. All 
 * polygons connected on the given UV map share the same part number.
 * 
 * Polygons are converted to a surface mesh using the 'Tessellate' function.
 * The 'Tessellate' function returns its data in a struct with the following fields.
 */
typedef struct vt_ILxPolygon {
        ILxUnknown	 iunk;
        // QWEB_MACRO_BEGIN - Common Accessor Methods
        LXxMETHOD(  LxResult,
Spawn) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Enumerate) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        LXtObjectID		 monitor);
        // QWEB_MACRO_END - Common Accessor Methods
        // QWEB_MACRO_BEGIN - Common Geometry Accessor Methods
        LXxMETHOD(  LxResult,
TestMarks) (
        LXtObjectID		 self,
        LXtMarkMode		 mode);
        LXxMETHOD(  LxResult,
SetMarks) (
        LXtObjectID		 self,
        LXtMarkMode		 set);
        // QWEB_MACRO_END - Common Geometry Accessor Methods
        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID		 self,
        LXtPolygonID		 polygon);
        LXxMETHOD(  LxResult,
SelectByIndex) (
        LXtObjectID		 self,
        unsigned int		 index);
        LXxMETHOD( LXtPolygonID,
ID) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Index) (
        LXtObjectID		 self,
        int			*index);
        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		 self,
        LXtID4			*type);
        LXxMETHOD(  LxResult,
VertexCount) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD(  LxResult,
VertexByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtPointID		*point);
        LXxMETHOD(  LxResult,
FirstIsControlEndpoint) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
LastIsControlEndpoint) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Normal) (
        LXtObjectID		 self,
        LXtVector		 normal);
        LXxMETHOD(  LxResult,
MapValue) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        LXtPointID		 point,
        float			*value);
        LXxMETHOD(  LxResult,
MapEvaluate) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        LXtPointID		 point,
        float			*value);
        LXxMETHOD(  LxResult,
Area) (
        LXtObjectID		 self,
        double			*area);
        LXxMETHOD(  LxResult,
New) (
        LXtObjectID		 self,
        LXtID4			 type,
        const LXtPointID	*vertices,
        unsigned int		 numVert,
        unsigned int		 rev,
        LXtPolygonID		*polygonID);
        LXxMETHOD(  LxResult,
NewProto) (
        LXtObjectID		 self,
        LXtID4			 type,
        const LXtPointID	*vertices,
        unsigned int		 numVert,
        unsigned int		 rev,
        LXtPolygonID		*polygonID);
        LXxMETHOD(  LxResult,
Remove) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
SetFirstIsControlEndpoint) (
        LXtObjectID		 self,
        int			 state);

        LXxMETHOD(  LxResult,
SetLastIsControlEndpoint) (
        LXtObjectID		 self,
        int			 state);
        LXxMETHOD(  LxResult,
SetVertexList) (
        LXtObjectID		 self,
        const LXtPointID	*vertices,
        unsigned int		 numVert,
        unsigned int		 rev);
        LXxMETHOD(  LxResult,
SetMapValue) (
        LXtObjectID		 self,
        LXtPointID		 point,
        LXtMeshMapID		 map,
        const float		*value);
        LXxMETHOD(  LxResult,
ClearMapValue) (
        LXtObjectID		 self,
        LXtPointID		 point,
        LXtMeshMapID		 map);
        LXxMETHOD(  LxResult,
StartContour) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
AddContourEdge) (
        LXtObjectID		 self,
        LXtPointID		 startPt,
        LXtPointID		 endPt);
        LXxMETHOD(  LxResult,
GenerateContour) (
        LXtObjectID		 self,
        LXtID4			 type,
        LXtPolygonID		*polygonID);
        LXxMETHOD(  LxResult,
GenerateContourProto) (
        LXtObjectID		 self,
        LXtPolygonID		*polygonID);
        LXxMETHOD(  LxResult,
IntersectRay) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtVector		 dir,
        LXtVector		 hitNorm,
        double			*hitDist);
        LXxMETHOD(  LxResult,
Closest) (
        LXtObjectID		 self,
        double			 maxDist,
        const LXtVector		 pos,
        LXtVector		 hitPos,
        LXtVector		 hitNorm,
        double			*hitDist);
        LXxMETHOD( LxResult,
PointIndex) (
        LXtObjectID		 self,
        LXtPointID		 pointID,
        unsigned int		*index);
        LXxMETHOD( LxResult,
EdgeIndex) (
        LXtObjectID		 self,
        LXtEdgeID		 edgeID,
        unsigned int		*index);
        LXxMETHOD( LxResult,
SharedEdge) (
        LXtObjectID		 self,
        LXtPolygonID		 polygonID,
        LXtEdgeID		*edgeID);
        LXxMETHOD( LxResult,
IsBorder) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
RepresentativePosition) (
        LXtObjectID		 self,
        LXtVector		 pos);
        LXxMETHOD( LxResult,
GoodPoint) (
        LXtObjectID		 self,
        const LXtPointID	*points,
        unsigned int		 nPoints,
        unsigned int		*index);
        LXxMETHOD( LxResult,
GenerateTriangles) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD( LxResult,
TriangleByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtPointID		*point0,
        LXtPointID		*point1,
        LXtPointID		*point2);
        LXxMETHOD( LxResult,
ClearTriangles) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
EnumerateBBox) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        const LXtVector		 min,
        const LXtVector		 max);
        LXxMETHOD(  LxResult,
EnumerateRay) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        const LXtVector		 org,
        const LXtVector		 ray);
        LXxMETHOD(  LxResult,
EnumerateLine) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        const LXtVector		 org,
        const LXtVector		 dir);
        LXxMETHOD(  LxResult,
NewCurveFill) (
        LXtObjectID		 self,
        const LXtPolygonID	*polygons,
        unsigned int		 numPols,
        LXtPolygonID		*polygonID);
        LXxMETHOD(  LxResult,
Symmetry) (
        LXtObjectID		 self,
        LXtPolygonID		*polygonID);
        LXxMETHOD( LxResult,
UVLookup) (
        LXtObjectID		 self,
        const char		*vMapName,
        const LXtVector2	 uv,
        LXtVector		 surfacePosition,
        LXtVector		 surfaceNormal,
        LXtVector		 surfaceDPDU,
        LXtVector		 surfaceDPDV);
        LXxMETHOD(  LxResult,
EnumerateByUV) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        const char		*vMapName,
        int			 quality,
        const LXtVector2	 uv,
        LXtObjectID		 visitor);
        LXxMETHOD(  LxResult,
EnumerateBin) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        LXtObjectID		 bin);
        LXxMETHOD(  LxResult,
Mesh) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
EnumerateByPTag) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtID4			 type,
        const char		*tag,
        LXtObjectID		 visitor);
        LXxMETHOD(  LxResult,
Part) (
        LXtObjectID		 self,
        unsigned int		*part);
        LXxMETHOD(  LxResult,
UVPart) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        unsigned int		*part);
        LXxMETHOD(  LxResult,
Tessellate) (
        LXtObjectID		 self,
        unsigned int		 flags,
        LXtPolyMeshInfo		*info);
} ILxPolygon;

typedef struct vt_ILxPolygon1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Spawn) (
        LXtObjectID              self,
        void                   **ppvObj);

        LXxMETHOD(  LxResult,
Enumerate) (
        LXtObjectID              self,
        LXtMarkMode              mode,
        LXtObjectID              visitor,
        LXtObjectID              monitor);

        LXxMETHOD(  LxResult,
TestMarks) (
        LXtObjectID              self,
        LXtMarkMode              mode);

        LXxMETHOD(  LxResult,
SetMarks) (
        LXtObjectID              self,
        LXtMarkMode              set);

        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID		 self,
        LXtPolygonID		 polygon);

        LXxMETHOD(  LxResult,
SelectByIndex) (
        LXtObjectID		 self,
        unsigned int		 index);

        LXxMETHOD( LXtPolygonID,
ID) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Index) (
        LXtObjectID		 self,
        int			*index);

        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		 self,
        LXtID4			*type);

        LXxMETHOD(  LxResult,
VertexCount) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD(  LxResult,
VertexByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtPointID		*point);

        LXxMETHOD(  LxResult,
FirstIsControlEndpoint) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
LastIsControlEndpoint) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
Normal) (
        LXtObjectID		 self,
        LXtVector		 normal);

        LXxMETHOD(  LxResult,
MapValue) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        LXtPointID		 point,
        float			*value);

        LXxMETHOD(  LxResult,
MapEvaluate) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        LXtPointID		 point,
        float			*value);

        LXxMETHOD(  LxResult,
New) (
        LXtObjectID		 self,
        LXtID4			 type,
        const LXtPointID	*vertices,
        unsigned int		 numVert,
        unsigned int		 rev,
        LXtPolygonID		*polygonID);

        LXxMETHOD(  LxResult,
NewProto) (
        LXtObjectID		 self,
        LXtID4			 type,
        const LXtPointID	*vertices,
        unsigned int		 numVert,
        unsigned int		 rev,
        LXtPolygonID		*polygonID);

        LXxMETHOD(  LxResult,
Remove) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetFirstIsControlEndpoint) (
        LXtObjectID		 self,
        int			 state);

        LXxMETHOD(  LxResult,
SetLastIsControlEndpoint) (
        LXtObjectID		 self,
        int			 state);

        LXxMETHOD(  LxResult,
SetVertexList) (
        LXtObjectID		 self,
        const LXtPointID	*vertices,
        unsigned int		 numVert,
        unsigned int		 rev);

        LXxMETHOD(  LxResult,
SetMapValue) (
        LXtObjectID		 self,
        LXtPointID		 point,
        LXtMeshMapID		 map,
        const float		*value);

        LXxMETHOD(  LxResult,
ClearMapValue) (
        LXtObjectID		 self,
        LXtPointID		 point,
        LXtMeshMapID		 map);

        LXxMETHOD(  LxResult,
StartContour) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
AddContourEdge) (
        LXtObjectID		 self,
        LXtPointID		 startPt,
        LXtPointID		 endPt);

        LXxMETHOD(  LxResult,
GenerateContour) (
        LXtObjectID		 self,
        LXtID4			 type,
        LXtPolygonID		*polygonID);

        LXxMETHOD(  LxResult,
GenerateContourProto) (
        LXtObjectID		 self,
        LXtPolygonID		*polygonID);

        LXxMETHOD(  LxResult,
IntersectRay) (
        LXtObjectID		 self,
        const LXtVector		 pos,
        const LXtVector		 dir,
        LXtVector		 hitNorm,
        double			*hitDist);

        LXxMETHOD(  LxResult,
Closest) (
        LXtObjectID		 self,
        double			 maxDist,
        const LXtVector		 pos,
        LXtVector		 hitPos,
        LXtVector		 hitNorm,
        double			*hitDist);

        LXxMETHOD( LxResult,
PointIndex) (
        LXtObjectID		 self,
        LXtPointID		 pointID,
        unsigned int		*index);

        LXxMETHOD( LxResult,
EdgeIndex) (
        LXtObjectID		 self,
        LXtEdgeID		 edgeID,
        unsigned int		*index);

        LXxMETHOD( LxResult,
SharedEdge) (
        LXtObjectID		 self,
        LXtPolygonID		 polygonID,
        LXtEdgeID		*edgeID);

        LXxMETHOD( LxResult,
IsBorder) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
RepresentativePosition) (
        LXtObjectID		 self,
        LXtVector		 pos);

        LXxMETHOD( LxResult,
GoodPoint) (
        LXtObjectID		 self,
        const LXtPointID	*points,
        unsigned int		 nPoints,
        unsigned int		*index);

        LXxMETHOD( LxResult,
GenerateTriangles) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD( LxResult,
TriangleByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtPointID		*point0,
        LXtPointID		*point1,
        LXtPointID		*point2);

        LXxMETHOD( LxResult,
ClearTriangles) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
EnumerateBBox) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        const LXtVector		 min,
        const LXtVector		 max);

        LXxMETHOD(  LxResult,
EnumerateRay) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        const LXtVector		 org,
        const LXtVector		 ray);

        LXxMETHOD(  LxResult,
EnumerateLine) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        const LXtVector		 org,
        const LXtVector		 dir);
} ILxPolygon1;

/*
 * As mentioned previously, all accessors share common interface methods for
 * walking their respective lists.
 * This method sets the accessor to the given edge. Edge IDs are somewhat
 * dynamic based on the points and polygons in the mesh, so an old edge ID
 * should not be assumed valid if the mesh has been edited.
 * 
 * This selects the edge by its endpoints.
 * 
 * These methods returns the current edge ID.
 * 
 * This method returns the points that make up the edge. Either argument
 * can be NULL if you only want one or the other.
 * 
 * This method returns the value of the edge in the map provided, returning
 * LXe_FALSE if the edge is unmapped.
 * 
 * 
 * This sets the edge's value in the given point map.
 * 
 * This removes any value for the edge pair in the given map.
 * 
 * These methods return the number of polygons sharing this edge.
 * 
 * This returns the polygon given by its index.
 * 
 * This returns a polygon that is visible and surface. It also return the index of the
 * polygon in the polygon list of the edge.
 * 
 * This returns a shared polygon between two edges.
 * 
 * This returns LXe_TRUE if the edge is on border and it is belong to one polygon.
 * 
 * This sets the symmetric point corresponding to the current edge when
 * the symmetry mode is enabled. This returns LXe_OK when the symmetric edge
 * is found, otherwise it returns LXe_FAILED. When the current edge is on
 * the symmetry center plane, it returns LXe_FAILED.
 * 
 * This returns LXe_TRUE if the symmetry state is enabled and the current edge
 * is on the symmetry center plane, otherwise it returns LXe_FALSE.
 * 
 * This methods returns the index of the curent edge.
 * 
 * An edge can be selected by it's index. As edges don't have a deterministic index,
 * this is calculated by iterating through the mesh polygon's edges and returning
 * the index of the first occurance.
 * 
 * This function returns the ILxMesh object associated with the edge accessor.
 * 
 * These methods returns the next edge ID.
 */
typedef struct vt_ILxEdge {
        ILxUnknown	 iunk;
        // QWEB_MACRO_BEGIN - Common Accessor Methods
        LXxMETHOD(  LxResult,
Spawn) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Enumerate) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        LXtObjectID		 monitor);
        // QWEB_MACRO_END - Common Accessor Methods
        // QWEB_MACRO_BEGIN - Common Geometry Accessor Methods
        LXxMETHOD(  LxResult,
TestMarks) (
        LXtObjectID		 self,
        LXtMarkMode		 mode);
        LXxMETHOD(  LxResult,
SetMarks) (
        LXtObjectID		 self,
        LXtMarkMode		 set);
        // QWEB_MACRO_END - Common Geometry Accessor Methods
        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID		 self,
        LXtEdgeID		 edge);
        LXxMETHOD(  LxResult,
SelectEndpoints) (
        LXtObjectID		 self,
        LXtPointID		 v0,
        LXtPointID		 v1);
        LXxMETHOD(  LXtEdgeID,
ID) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Endpoints) (
        LXtObjectID		 self,
        LXtPointID		*point0,
        LXtPointID		*point1);
        LXxMETHOD(  LxResult,
MapValue) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        float			*value);
        LXxMETHOD(  LxResult,
MapEvaluate) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        float			*value);
        LXxMETHOD(  LxResult,
SetMapValue) (
        LXtObjectID		 self,
        LXtMeshMapID		 map,
        const float		*value);
        LXxMETHOD(  LxResult,
ClearMapValue) (
        LXtObjectID		 self,
        LXtMeshMapID		 map);
        LXxMETHOD(  LxResult,
PolygonCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
PolygonByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtPolygonID		*polygonID);
        LXxMETHOD(  LxResult,
RepresentativePolygon) (
        LXtObjectID		 self,
        LXtPolygonID		*polygonID,
        unsigned int		*index);
        LXxMETHOD(  LxResult,
SharedPolygon) (
        LXtObjectID		 self,
        LXtEdgeID		 edgeID,
        LXtPolygonID		*polygonID);
        LXxMETHOD(  LxResult,
IsBorder) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Symmetry) (
        LXtObjectID		 self,
        LXtEdgeID		*edgeID);
        LXxMETHOD(  LxResult,
OnSymmetryCenter) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Index) (
        LXtObjectID		 self,
        unsigned int		*index);
        LXxMETHOD(  LxResult,
SelectByIndex) (
         LXtObjectID		 self,
         unsigned int		 index);
        LXxMETHOD(  LxResult,
Mesh) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LXtEdgeID,
NextLoopEdge) (
        LXtObjectID		 self,
        int inDirection,
        int* outDirection,
        int method,
        int ignoreBorder, 
        int verifyAngle	);
} ILxEdge;

/*
 * As mentioned previously, all accessors share common interface methods for
 * walking their respective lists.
 * 
 * This method sets the accessor to the given point map.
 * 
 * This can be used to select a map by type and name.
 * 
 * Maps can also be filtered by type which affects their enumeration.  Passing
 * a type of zero clears the filter.
 * 
 * This method returns the ID of the current map.
 * 
 * These return the map's name and type.
 * 
 * 
 * This method returns the dimension of the current map.
 * 
 * This returns LXe_TRUE if this is an edge map.
 * 
 * This returns LXe_TRUE if it is a continuous (vs. a discontinuous) map.
 * 
 * This returns LXe_TRUE if the default value of elements not in the
 * map should be zero.
 * 
 * 
 * 
 * 
 * It's possible for the client to enumerate just the elements that are members of
 * the map. This function enumerates continuous values, calling the visitor with the
 * point accessor set to each point.
 * 
 * Discontinuous values are the same but require a point and a polygon.
 * 
 * Likewise edge map can also be enumerated with an associated edge accessor.
 * 
 * This sets the map's name
 * 
 * Enumerates UV seam edges.
 * 
 * 
 * Returns with the opposite edge. Call only from the Evaluate of a the EnumerateUVSeamEdges()!
 * 
 * This method returns the bounding box for the MeshMapAccessor's current VMap.
 */
typedef struct vt_ILxMeshMap {
        ILxUnknown	 iunk;
        // QWEB_MACRO_BEGIN - Common Accessor Methods
        LXxMETHOD(  LxResult,
Spawn) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Enumerate) (
        LXtObjectID		 self,
        LXtMarkMode		 mode,
        LXtObjectID		 visitor,
        LXtObjectID		 monitor);
        // QWEB_MACRO_END - Common Accessor Methods
        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID		 self,
        LXtMeshMapID		 map);
        LXxMETHOD(  LxResult,
SelectByName) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name);
        LXxMETHOD( LxResult,
FilterByType) (
        LXtObjectID		 self,
        LXtID4			 type);
        LXxMETHOD( LXtMeshMapID,
ID) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Name) (
        LXtObjectID		 self,
        const char	       **name);
        LXxMETHOD( LxResult,
Type) (
        LXtObjectID		 self,
        LXtID4			*type);
        LXxMETHOD(  LxResult,
Dimension) (
        LXtObjectID		 self,
        unsigned int		*dimension);
        LXxMETHOD(  LxResult,
IsEdgeMap) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
IsContinuous) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
ZeroDefault) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
New) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name,
        LXtMeshMapID		*mapID);
        LXxMETHOD(  LxResult,
Remove) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Clear) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
EnumerateContinuous) (
        LXtObjectID		 self,
        LXtObjectID		 visitor,
        LXtObjectID		 point);
        LXxMETHOD(  LxResult,
EnumerateDiscontinuous) (
        LXtObjectID		 self,
        LXtObjectID		 visitor,
        LXtObjectID		 point,
        LXtObjectID		 poly);
        LXxMETHOD(  LxResult,
EnumerateEdges) (
        LXtObjectID		 self,
        LXtObjectID		 visitor,
        LXtObjectID		 edge);
        LXxMETHOD( LxResult,
SetName) (
        LXtObjectID		 self,
        const char	        *name);
        LXxMETHOD(  LxResult,
EnumerateUVSeamEdges) (
        LXtObjectID		 self,
        LXtObjectID		 visitor,
        LXtObjectID		 edge,
        LXtObjectID		 poly);
        LXxMETHOD(  LxResult,
UVSeamOppositeEdge) (
        LXtObjectID		 self,
        LXtEdgeID		 originalEdge,
        LXtPolygonID		 originalPoly,
        LXtPolygonID		*opppositePoly,
        int			*isReverse
);
        LXxMETHOD(  LxResult,
UVBoundingBox) (
        LXtObjectID		 self,
        LXtBBox			*bbox);
} ILxMeshMap;

/*
 * A mesh listener can be attached to a mesh to be informed of changes.
 * NOTE: Needs to be fleshed out!
 * 
 * This is called for mesh edit changes with event codes defined as LXf_MESHEDIT.
 */
typedef struct vt_ILxMeshListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Destroy) (
        LXtObjectID		 self);
        LXxMETHOD( void,
Changes) (
        LXtObjectID		 self,
        unsigned		 event);
} ILxMeshListener;

typedef struct vt_ILxMeshListener1 {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Destroy) (
        LXtObjectID		 self);
} ILxMeshListener1;

/*
 * Often, it can be useful to track multiple changes to a mesh within a particular
 * time period. The MeshTracker interface will record a series of mesh changes,
 * and maintain a list of modified points and polygons. The list of changes can
 * be queried, enumerated and cleared at any point. This provides a efficient way
 * to be kept informed of multiple changes, without reacting to every mesh change
 * event.
 * The Start function starts tracking mesh changes. If this tracker is already
 * running, this function does nothing. The tracker can be started and stopped
 * multiple times, however, it will only record changes when it's active.
 * 
 * The Stop function stops tracking mesh changes. If this tracker is already
 * stopped, this function does nothing. The tracker can be started and stopped
 * multiple times, however, it will only record changes when it's active.
 * 
 * This returns if the mesh tracker is active or not. The function will return
 * either LXe_TRUE or LXe_FALSE.
 * 
 * After the changes have been queried and enumerated by the client, the list
 * of changes should be cleared. The Reset function will clear the list of
 * changes, ready to start tracking new change events.
 * 
 * This function returns a flag describing the edits that have been performed
 * on the mesh. The flag will be a combination of the LXf_MESHEDIT flags.
 * 
 * Returns the ILxMesh object that the tracker is watching. If the mesh no
 * longer exists, the function will return a failure code.
 * 
 * This function allows the modified points on the mesh to be enumerated. A
 * change flag argument will be used as a mask for enumeration, for example
 * if the LXf_ELTEDIT_POINT_POS flag is provided, only points that have had
 * their position modified will be enumerated. A change flag of 0 will
 * enumerate all points.
 * 
 * This function allows the modified polygons on the mesh to be enumerated.
 * A change flag argument will be used as a mask for enumeration, for example
 * if the LXf_ELTEDIT_POLTAGS flag is provided, only polygons that have had
 * their tags modified will be enumerated. A change flag of 0 will enumerate
 * all polygons.
 * 
 * The SetChange function is used to describe the overall change performed by
 * the filter. It should be one of the LXf_MESHEDIT flags.
 * 
 * The AddPoint function is used to store a point that has been edited. An
 * edit flag allows the type of change to be recorded. The flag should be
 * one of the LXf_ELTEDIT flags.
 * 
 * The AddPolygon function is used to store a polygon that has been edited. An
 * edit flag allows the type of change to be recorded. The flag should be one
 * of the LXf_ELTEDIT flags.
 * 
 * Clients can provide a combination of change flags to filter the tracker to
 * tracker matching change types. For example, if the client only cares about
 * position changes, they can specify LXf_ELTEDIT_POINT_POS. Other kinds of
 * changes may be tracked, but this can provide a performance improvement if
 * clients are going to ignore certain change types. By default, all types of
 * changes will be tracked.
 * 
 * The filter state can also be queried.
 */
typedef struct vt_ILxMeshTracker {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Start) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Stop) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Active) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Reset) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Changes) (
        LXtObjectID		 self,
        unsigned int		*edit);
        LXxMETHOD(  LxResult,
Mesh) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
EnumeratePoints) (
        LXtObjectID		 self,
        unsigned int		 change,
        LXtObjectID		 visitor,
        LXtObjectID		 point);
        LXxMETHOD(  LxResult,
EnumeratePolygons) (
        LXtObjectID		 self,
        unsigned int		 change,
        LXtObjectID		 visitor,
        LXtObjectID		 poly);
        LXxMETHOD(  LxResult,
SetChange) (
        LXtObjectID		 self,
        unsigned int		 change);
        LXxMETHOD(  LxResult,
AddPoint) (
        LXtObjectID		 self,
        LXtPointID		 point,
        unsigned int		 change);
        LXxMETHOD(  LxResult,
AddPolygon) (
        LXtObjectID		 self,
        LXtPolygonID		 poly,
        unsigned int		 change);
        LXxMETHOD(  LxResult,
SetFilter) (
        LXtObjectID		 self,
        unsigned int		 filter);
        LXxMETHOD(  LxResult,
Filter) (
        LXtObjectID		 self,
        unsigned int		*filter);
} ILxMeshTracker;

/*
 * The Evaluate function is used to perform the main evaluation. It is given an editable
 * mesh, which should be edited in place, to perform the modeling operation. A selection
 * mark mode and selection type is provided, to limit the operation to a particular subset
 * of components.
 * 
 * 
 * If the previous mesh operation is compatible, then Convert will be called to transfer
 * variables and user data from the old mesh operation to the new mesh operation. The
 * function will be passed the old operation and any variables should be transferred.
 * 
 * The ReEvaluate function is called to perform a fast update to a previous mesh. The mesh
 * from the previous evaluation result is passed to the function, and the mesh operation
 * is expected to simply update the mesh in place.
 * 
 * The SetTransform function is used to provide the Mesh Operation with a transform
 * matrix to use for evaluation.
 * 
 * The Blend function is used to map elements generated by one mesh operation to
 * elements generated by another. A second mesh operation is provided with alternate
 * settings, along with an ILxMeshBlend object, which can be used for marking two
 * corresponding elements as equivalent.
 * 
 * The Clone function is expected to return a clone of this mesh operation and it's
 * internal state. A target item is provided to use as a key, allowing the mesh
 * operation to return an existing cloned mesh operation, if one has already been
 * created for this target item.  A source item is also provided which represents the
 * association a meshop has to its target.  It is either the meshop itself, or a stack
 * operator item through which the two are connected.
 */
typedef struct vt_ILxMeshOperation {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtID4			 type,
        LXtMarkMode		 mode);
        LXxMETHOD( int,
Compare) (
        LXtObjectID		 self,
        LXtObjectID		 other);
        LXxMETHOD( LxResult,
Convert) (
        LXtObjectID		 self,
        LXtObjectID		 other);
        LXxMETHOD( LxResult,
ReEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtID4			 type);
        LXxMETHOD( LxResult,
SetTransform) (
        LXtObjectID		 self,
        const LXtMatrix4	 matrix);
        LXxMETHOD( LxResult,
Blend) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        LXtObjectID		 blend);
        LXxMETHOD( LxResult,
Clone) (
        LXtObjectID		  self,
        LXtObjectID		  target,
        LXtObjectID		  source,
        void			**ppvObj);
} ILxMeshOperation;

typedef struct vt_ILxMeshOperation2 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtID4			 type,
        LXtMarkMode		 mode);

        LXxMETHOD( int,
Compare) (
        LXtObjectID		 self,
        LXtObjectID		 other);

        LXxMETHOD( LxResult,
Convert) (
        LXtObjectID		 self,
        LXtObjectID		 other);

        LXxMETHOD( LxResult,
ReEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtID4			 type);

        LXxMETHOD( LxResult,
SetTransform) (
        LXtObjectID		 self,
        const LXtMatrix4	 matrix);

                LXxMETHOD( LxResult,
Blend) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        LXtObjectID		 blend);

        LXxMETHOD( LxResult,
Clone) (
        LXtObjectID		  self,
        LXtObjectID		  target,
        void			**ppvObj);
} ILxMeshOperation2;

typedef struct vt_ILxMeshOperation1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtID4			 type,
        LXtMarkMode		 mode);

        LXxMETHOD( int,
Compare) (
        LXtObjectID		 self,
        LXtObjectID		 other);

        LXxMETHOD( LxResult,
Convert) (
        LXtObjectID		 self,
        LXtObjectID		 other);

        LXxMETHOD( LxResult,
ReEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtID4			 type);

        LXxMETHOD( LxResult,
SetTransform) (
        LXtObjectID		 self,
        const LXtMatrix4	 matrix);
} ILxMeshOperation1;

/*
 * Mesh filters are added to evaluation stacks in order to perform mesh
 * operations during evaluation. They can also be read during evaluation to
 * get deforming meshes.
 * The Type() method returns the type of filter, given by one of the codes
 * below.  These select which operational method is called and how its
 * results are interpreted.
 * 
 * 
 * If the type of filter is MODIFY, then the Evaluate() method is used to
 * transform a mesh.  A writable mesh is passed as input and should be
 * modified in placed based on the settings of the filter. An ILxMeshTracker
 * object is provided, allowing it to return a list of modified elements.
 * 
 * For GENERATE and SOURCE type filters the Generate() function is called
 * and it returns a new mesh to replace the input mesh.  For GENERATE filters
 * the mesh is instanced while with SOURCE filters the result is used directly.
 */
typedef struct vt_ILxMeshFilter {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned,
Type) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtObjectID		 tracker);
        LXxMETHOD(  LxResult,
Generate) (
        LXtObjectID		 self,
        void		       **ppvObj);
} ILxMeshFilter;

typedef struct vt_ILxMeshFilter1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned,
Type) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 mesh);

        LXxMETHOD(  LxResult,
Generate) (
        LXtObjectID		 self,
        void		       **ppvObj);
} ILxMeshFilter1;

/*
 * The bounding box interface only computes the mesh bounding box.
 */
typedef struct vt_ILxMeshFilterBBox {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtBBox			*box);
} ILxMeshFilterBBox;

typedef struct vt_ILxMeshFilterIdent {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Generate) (
        LXtObjectID		 self,
        const char		*ident,
        void		       **ppvObj);
} ILxMeshFilterIdent;

/*
 * The MeshFilterBlend interface allows the result of one mesh filter to be blended with
 * another.
 * The Generate method is provided with a second mesh filter storing alternate state
 * for the mesh filter. The function is expected to return an ILxMeshBlend object that
 * maps elements generated by one filter to elements generated by another.
 * 
 * 
 * The Evaluate method is provided with a second mesh filter storing alternate state
 * for the mesh filter, as well as an ILxMeshBlend object. The function is expected to
 * populate the ILxMeshBlend object, mapping elements generated by one filter to
 * elements generated by another.
 */
typedef struct vt_ILxMeshFilterBlend {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Generate) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        LXtObjectID		 blend);
} ILxMeshFilterBlend;

/*
 * It can be useful to be able to compare the result of one mesh stack with the
 * result of another. The MeshBlend object provides methods for finding equivalent
 * elements on two mesh stack results, as well as a blending the topology of one
 * mesh stack, into the positions of another.
 * The BlendMesh method returns a new mesh that contains the source mesh stack
 * topology, in the positions of the target mesh stack. The t argument determines
 * how the mesh is blended, with a value of 0.0 representing the original source
 * mesh positions, and a value of 1.0 representing the target mesh positions.
 * 
 * 
 * The SourceMesh method returns the source mesh.
 * 
 * The TargetMesh method returns the target mesh.
 * 
 * Provided with a point on the source mesh, the GetPoint method will return the
 * equivalent point on the target mesh.
 * 
 * Provided with a polygon on the source mesh, the GetPolygon method will return
 * the equivalent polygon on the target mesh.
 * 
 * Equivalent points can be updated by providing a point on the source mesh, and a
 * point on the target mesh. If the list of equivalent elements cannot be edited,
 * NOACCESS will be returned.
 * 
 * Equivalent polygons can be updated by providing a polygon on the source mesh, and
 * a polygon on the target mesh. If the list of equivalent elements cannot be edited,
 * NOACCESS will be returned.
 * 
 * Points can be enumerated by providing a source point accessor, a target point
 * accessor and a visitor. For each source point, the accessor for the source and
 * target will be set, and the visitor will be called.
 * 
 * Polygons can be enumerated by providing a source polygon accessor, a target polygon
 * accessor and a visitor. For each source polygon, the accessor for the source and
 * target will be set, and the visitor will be called.
 */
typedef struct vt_ILxMeshBlend {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
BlendMesh) (
        LXtObjectID		 self,
        double			 t,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
SourceMesh) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
TargetMesh) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
GetPoint) (
        LXtObjectID		 self,
        LXtPointID		 source,
        LXtPointID		*target);
        LXxMETHOD(  LxResult,
GetPolygon) (
        LXtObjectID		 self,
        LXtPolygonID		 source,
        LXtPolygonID		*target);
        LXxMETHOD(  LxResult,
SetPoint) (
        LXtObjectID		 self,
        LXtPointID		 source,
        LXtPointID		 target);
        LXxMETHOD(  LxResult,
SetPolygon) (
        LXtObjectID		 self,
        LXtPolygonID		 source,
        LXtPolygonID		 target);
        LXxMETHOD(  LxResult,
EnumeratePoints) (
        LXtObjectID		 self,
        LXtObjectID		 source,
        LXtObjectID		 target,
        LXtObjectID		 visitor);
        LXxMETHOD(  LxResult,
EnumeratePolygons) (
        LXtObjectID		 self,
        LXtObjectID		 source,
        LXtObjectID		 target,
        LXtObjectID		 visitor);
} ILxMeshBlend;

/*
 * Meshes are constructed from user editable elements, such as points, polygons,
 * vertex maps and polygon tags; however, meshes can also have evaluated meta data
 * that is created on demand, and invalidated whenever the mesh is modified. Clients
 * can implement new meta data through the SDK using ILxMeshMetaData.
 * The Validate method is used to update the meta data. The function is provided
 * with a mesh, an mesh xtra data interface to manipulate mesh xtra data, and a
 * change flag describing the type of change that has been performed. The xtra
 * data interface will only be valid if the server specifies xtra data support in
 * the server tags.
 * 
 * It can be useful to store additonal data per point or per polygon. The Mesh Xtra
 * Data mechanism allows either a memory pointer or a COM object to be stored per
 * element. If arbitrary data is being stored, the Free methods will be called per
 * element to release any allocated memory.
 * 
 */
typedef struct vt_ILxMeshMetaData {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Validate) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtObjectID		 xtra,
        unsigned int		 change);
        LXxMETHOD(  void,
FreePointData) (
        LXtObjectID		 self,
        void			*data);
        LXxMETHOD(  void,
FreePolygonData) (
        LXtObjectID		 self,
        void			*data);
} ILxMeshMetaData;

/*
 * This method sets the xtra data for a point to some arbitrary data. It must be
 * free'd by the ILxMeshMetaData::FreePointData method when it's no longer needed.
 * 
 * Points can also have reference counted COM objects associated with them. This
 * object is automatically released when no longer needed.
 * 
 * Once set, the xtra data for a point can easily be read. If it hasn't been set,
 * this method will return a failure code.
 * 
 * 
 * If the data associated with a point is no longer needed, the ClearPoint function
 * will remove it. The ILxMeshMetaData::FreePointData method will be called to
 * release the memory as necessary.
 * 
 * This method sets the xtra data for a polygon to some arbitrary data. It must be
 * free'd by the ILxMeshMetaData::FreePolygonData method when it's no longer needed.
 * 
 * Polygons can also have reference counted COM objects associated with them. This
 * object is automatically released when no longer needed.
 * 
 * Once set, the xtra data for a polygon can easily be read. If it hasn't been set,
 * this method will return a failure code.
 * 
 * 
 * If the data associated with a polygon is no longer needed, the ClearPolygon
 * function will remove it. The ILxMeshMetaData::FreePolygonData method will be
 * called to release the memory as necessary.
 */
typedef struct vt_ILxMeshXtraData {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
SetPointData) (
        LXtObjectID		 self,
        LXtPointID		 point,
        void			*data);
        LXxMETHOD(  LxResult,
SetPointObject) (
        LXtObjectID		 self,
        LXtPointID		 point,
        LXtObjectID		 obj);
        LXxMETHOD(  LxResult,
GetPointData) (
        LXtObjectID		 self,
        LXtPointID		 point,
        void		       **data);
        LXxMETHOD(  LxResult,
GetPointObject) (
        LXtObjectID		 self,
        LXtPointID		 point,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ClearPoint) (
        LXtObjectID		 self,
        LXtPointID		 point);
        LXxMETHOD(  LxResult,
SetPolygonData) (
        LXtObjectID		 self,
        LXtPolygonID		 poly,
        void			*data);
        LXxMETHOD(  LxResult,
SetPolygonObject) (
        LXtObjectID		 self,
        LXtPolygonID		 poly,
        LXtObjectID		 obj);
        LXxMETHOD(  LxResult,
GetPolygonData) (
        LXtObjectID		 self,
        LXtPolygonID		 poly,
        void		       **data);
        LXxMETHOD(  LxResult,
GetPolygonObject) (
        LXtObjectID		 self,
        LXtPolygonID		 poly,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ClearPolygon) (
        LXtObjectID		 self,
        LXtPolygonID		 poly);
} ILxMeshXtraData;

/*
 * The mesh service provides high-level mesh system access.  These methods are
 * provided as general services that could be useful on any mesh.
 */

        #define LXa_MESHSERVICE	"meshservice"
        #define LXu_MESHSERVICE	"82B739EC-F92E-4CC9-A5FB-584A866D5897"

        // [python] ILxMeshService:CreateMesh		obj Mesh
        // [python] ILxMeshService:MeshFromMeshID	obj Mesh
        // [python] ILxMeshService:VMapIsContinuous	bool
        // [python] ILxMeshService:VMapIsEdgeMap	bool
        // [python] ILxMeshService:VMapZeroDefault	bool
        // [python] ILxMeshService:CreateSolidDrill	obj SolidDrill
        // [python] ILxMeshService:CreateSlice		obj PolygonSlice
        // [python] ILxMeshService:IsMeshProcedural	bool
        // [python] ILxMeshService:ItemFromMesh		obj Item
        // [python] ILxMeshService:SurfaceFromMesh	obj Surface

/*
 * The the ILxMesh object is the core interface for manipulating meshes.  It is
 * also responsible for spawning accessors, which provide access to the points,
 * polygons, edges, and maps within the mesh.  Multiple independent accessors
 * can be spawned for each mesh.
 */

        #define LXa_MESH	"mesh3"
        #define LXu_MESH	"8C7F1CF3-8CE8-4395-9324-A16DD63B4AFE"

        #define LXsTYPE_MESH	"mesh"

        // [local]  ILxMesh
        // [const]  ILxMesh:PointCount
        // [const]  ILxMesh:PolygonCount
        // [const]  ILxMesh:EdgeCount
        // [const]  ILxMesh:MapCount
        // [python] ILxMesh:TestSameMesh	bool


        // [python] ILxMesh:PointAccessor	obj Point
        // [python] ILxMesh:PolygonAccessor	obj Polygon
        // [python] ILxMesh:EdgeAccessor	obj Edge
        // [python] ILxMesh:MeshMapAccessor	obj MeshMap


        #define LXf_MESHEDIT_POSITION		 0x001
        #define LXf_MESHEDIT_POINTS		 0x002
        #define LXf_MESHEDIT_POLYGONS		 0x004
        #define LXf_MESHEDIT_GEOMETRY		(LXf_MESHEDIT_POINTS | LXf_MESHEDIT_POLYGONS)
        #define LXf_MESHEDIT_POL_TAGS		 0x008
        #define LXf_MESHEDIT_POL_TYPE		 0x010
        #define LXf_MESHEDIT_MAP_CONTINUITY	 0x020
        #define LXf_MESHEDIT_MAP_UV		 0x040
        #define LXf_MESHEDIT_MAP_MORPH		 0x080
        #define LXf_MESHEDIT_MAP_OTHER		 0x100
        #define LXf_MESHEDIT_UPDATE		 0x200
        #define LXf_MESHEDIT_DELTA		 0x400

/*
 * Set and get PSUB boundary rules. They are mapped to "smooth", "crease all"
 * and "crease edges" in definitions of prman.
 */

        #define LXiPSUB_BOUND_SMOOTH		 0
        #define LXiPSUB_BOUND_CREASE		 1
        #define LXiPSUB_BOUND_CREASEEDGES	 2

/*
 * This merges the provided mesh with the current mesh, copying all the data from
 * other. The flags argument controls which elements are copied from the source mesh
 * to the target mesh.
 */

        #define LXf_MESHMERGE_PTAG		0x001
        #define LXf_MESHMERGE_VMAP_MORPH	0x002
        #define LXf_MESHMERGE_VMAP_NORMAL	0x004
        #define LXf_MESHMERGE_VMAP_UV		0x008
        #define LXf_MESHMERGE_VMAP_WEIGHT	0x010
        #define LXf_MESHMERGE_VMAP_COLOR	0x020
        #define LXf_MESHMERGE_MARK		0x040
        #define LXf_MESHMERGE_TRANSFORM		0x080
        #define LXf_MESHMERGE_SELECTIONSET	0x100
        #define LXf_MESHMERGE_VMAP_OTHERS	0x200
        #define LXf_MESHMERGE_VMAP		(LXf_MESHMERGE_VMAP_MORPH|LXf_MESHMERGE_VMAP_NORMAL|LXf_MESHMERGE_VMAP_UV|LXf_MESHMERGE_VMAP_WEIGHT|LXf_MESHMERGE_VMAP_COLOR|LXf_MESHMERGE_SELECTIONSET|LXf_MESHMERGE_VMAP_OTHERS)

        #define LXf_MESHMERGE_POLY_FACE		0x001000
        #define LXf_MESHMERGE_POLY_CURVE	0x002000
        #define LXf_MESHMERGE_POLY_BEZIER	0x004000
        #define LXf_MESHMERGE_POLY_SUBD		0x008000
        #define LXf_MESHMERGE_POLY_SPCH		0x010000
        #define LXf_MESHMERGE_POLY_TEXT		0x020000
        #define LXf_MESHMERGE_POLY_PSUB		0x040000
        #define LXf_MESHMERGE_POLY_LINE		0x080000
        #define LXf_MESHMERGE_POLY_CRVFIL	0x100000
        #define LXf_MESHMERGE_POLY_BSPLINE	0x200000
        #define LXf_MESHMERGE_POLY_OPNT		0x400000
        #define LXm_MESHMERGE_POLY		0xfff000
        #define LXm_MESHMERGE_POLY_ALL		(LXf_MESHMERGE_POLY_FACE|LXf_MESHMERGE_POLY_CURVE|LXf_MESHMERGE_POLY_BEZIER|LXf_MESHMERGE_POLY_SUBD|LXf_MESHMERGE_POLY_SPCH|LXf_MESHMERGE_POLY_TEXT|LXf_MESHMERGE_POLY_PSUB|LXf_MESHMERGE_POLY_LINE|LXf_MESHMERGE_POLY_CRVFIL|LXf_MESHMERGE_POLY_BSPLINE|LXf_MESHMERGE_POLY_OPNT)

        #define LXf_MESHMERGE_ALL		(LXf_MESHMERGE_PTAG|LXf_MESHMERGE_MARK|LXf_MESHMERGE_VMAP|LXm_MESHMERGE_POLY_ALL)

        #define LXf_MESHMERGE_FLIP		0x01000000

/*
 * This interface was retired in modo 10.1, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXa_MESH1	"mesh2"
        #define LXu_MESH1	"A9E30646-D729-4850-B4C4-F00A5E93FE25"

/*
 * This interface was retired in modo 901, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXa_MESH2	"mesh"
        #define LXu_MESH2	"1F1BB7BF-A862-4810-95FF-3346AF738209"


        // [python] ILxPoint:Spawn	obj Point
        // [python] ILxPolygon:Spawn	obj Polygon
        // [python] ILxEdge:Spawn	obj Edge
        // [python] ILxMeshMap:Spawn	obj MeshMap

/*
 * The ILxPoint is a combination of an accessor for specific points,
 * as well as providing a mechanism to walk the mesh's point list.
 */

        #define LXa_POINT	"point"
        #define LXu_POINT	"37B477FE-ED3C-4EDC-A4A8-9BB24F58A4E6"
        // [local]  ILxPoint
        // [python] ILxPoint:TestMarks		bool
        // [python] ILxPoint:MapValue		bool
        // [python] ILxPoint:MapValue:value	vector
        // [python] ILxPoint:MapEvaluate	bool
        // [python] ILxPoint:MapEvaluate:value	vector

/*
 * The ILxPolygon is used to obtain information about specific polygons,
 * as well as allowing the list of polygons to be walked.
 */

        #define LXa_POLYGON	"polygon2"
        #define LXu_POLYGON	"DD64141D-DC92-4348-B45B-F73FC64F1E52"
        // [local]  ILxPolygon
        // [python] ILxPolygon:TestMarks		bool
        // [python] ILxPolygon:FirstIsControlEndpoint	bool
        // [python] ILxPolygon:LastIsControlEndpoint	bool
        // [python] ILxPolygon:IsBorder			bool
        // [python] ILxPolygon:IntersectRay		bool
        // [python] ILxPolygon:Closest			bool
        // [python] ILxPolygon:MapValue			bool
        // [python] ILxPolygon:MapValue:value		vector
        // [python] ILxPolygon:MapEvaluate		bool
        // [python] ILxPolygon:MapEvaluate:value	vector

/*
 * A polygon has 16 bits for its point count, so it can have a large but limited
 * number of vertices.  Zero is never really valid but is nonetheless possible.
 */

        #define LXi_POLY_MAXVERT	 65535

/*
 * The quality of the UV tracking depends on this enum.
 */

        #define LXsPQ_POLY		0
        #define LXsPQ_SUBD		1

/*
 * The polygon type is given by a character string identifier which allows
 * for extensible polygon types.  A "face" polygon is just the facet defined by
 * the vertices.  A "curve" polygon is a Modeler-style spline curve.
 */

        #define LXsPTYP_FACE		"face"
        #define LXsPTYP_CURVE		"curve"
        #define LXsPTYP_BEZIER		"bezier"
        #define LXsPTYP_SUBD		"subdiv"
        #define LXsPTYP_SPCH		"spatch"
        #define LXsPTYP_TEXT		"text"
        #define LXsPTYP_PSUB		"psubdiv"
        #define LXsPTYP_LINE		"line"
        #define LXsPTYP_CRVFIL		"curveFill"
        #define LXsPTYP_BSPLINE		"BSpline"
        #define LXsPTYP_OPNT		"onePoint"
    // See Also:  PolyType

/*
 * The second method is as a numeric ID code which is much faster when the
 * type is known.  There are ways to look up the one from the other.
 */

        #define	LXiPTYP_FACE		LXxID4('F','A','C','E')
        #define	LXiPTYP_CURVE		LXxID4('C','U','R','V')
        #define	LXiPTYP_BEZIER		LXxID4('B','E','Z','R')
        #define	LXiPTYP_SUBD		LXxID4('S','U','B','D')
        #define	LXiPTYP_SPCH		LXxID4('S','P','C','H')
        #define	LXiPTYP_TEXT		LXxID4('T','E','X','T')
        #define	LXiPTYP_PSUB		LXxID4('P','S','U','B')
        #define	LXiPTYP_LINE		LXxID4('L','I','N','E')
        #define	LXiPTYP_CRVFIL		LXxID4('C','F','I','L')
        #define	LXiPTYP_BSPLINE		LXxID4('B','S','P','L')
        #define	LXiPTYP_OPNT		LXxID4('O','P','N','T')
        #define LXiPTYP_BEZR		LXiPTYP_BEZIER
        #define LXiPTYP_CURV		LXiPTYP_CURVE
        #define LXiPTYP_BSPL		LXiPTYP_BSPLINE

/*
 * Polygons have tags which can be accessed using the ILxStringTag interface
 * on the polygon accessor.
 * Polygon tag types can be arbitrary, so clients and even plugins are free to
 * invent  any type with any meaning they need for a specific application.
 * However, having some predefined common types makes some of the basic
 * applications more obvious.
 * - MATR
 * The material name for a polygon is stored in a tag of this type.  If the
 * polygon has no material, some suitable default should be used.
 * 
 * - PART
 * This tag is the name of the abstract element to which this polygon belongs.
 * It is used primarily for selection during modeling.
 * 
 * - PICK
 * This tag indicates the selection sets that this polygon belongs to.  The name
 * of the sets are separated by semicolons, for example if a polygon belongs to
 * A and B its pick tag will be: "A;B"
 * 
 * These three polygon tags are for text polygon type.
 * 
 * - FONT
 * This tag indicates the font name for this text polygon.
 * 
 * - TEXT
 * This tag includes the text string for this text polygon.
 * 
 * - JUST
 * This tag indicates the justification for this text polygon.The first character
 * takes 'T'(Top), 'M'(Middle) and 'B'(Bottom). The second character takes 'L'(Left),
 * 'C'(Center), and 'R'(Right). For example, 'BL' indicates the justification is
 * bottom-left.
 * 
 */

        #define LXi_POLYTAG_MATERIAL		LXxID4('M','A','T','R')
        #define LXi_POLYTAG_PART		LXxID4('P','A','R','T')
        #define LXi_POLYTAG_SMOOTHING_GROUP	LXxID4('S','M','G','P')
        #define LXi_POLYTAG_PICK		LXxID4('P','I','C','K')
        #define LXi_POLYTAG_FONT		LXxID4('F','O','N','T')
        #define LXi_POLYTAG_TEXT		LXxID4('T','E','X','T')
        #define LXi_POLYTAG_JUST		LXxID4('J','U','S','T')

        #define LXi_PTAG_MATR		LXi_POLYTAG_MATERIAL
        #define LXi_PTAG_PART		LXi_POLYTAG_PART
        #define LXi_PTAG_PICK		LXi_POLYTAG_PICK
        #define LXi_PTAG_FONT		LXi_POLYTAG_FONT
        #define LXi_PTAG_TEXT		LXi_POLYTAG_TEXT
        #define LXi_PTAG_JUST		LXi_POLYTAG_JUST

/*
 * - flag
 * Different bits in the flag word can be set to flag the presence or absence
 * of certain aspects of the mesh.  The caller sets the NORMALS bit to get the
 * 'norm' array computed, and the TEXTURE bit to get texture coordinates. If the
 * DYNAMIC bit is set, the mesh may be adaptively tesselated, returning varying
 * numbers of output vertices for the same input topology. Non-dynamic meshing is
 * useful for GL caching techniques. The FREEZE flag indicates that the mesh is
 * being generated for freezing, as opposed to display, which implies both that
 * the tesselation can afford more time to perform, and that the different subdivision
 * level settings may be chosen.
 */

        #define LXf_PMI_NORMALS		 0x01
        #define LXf_PMI_TEXTURE		 0x02
        #define LXf_PMI_DYNAMIC		 0x04
        #define LXf_PMI_FREEZE		 0x08
        #define LXm_PMI_ALL		(LXf_PMI_NORMALS|LXf_PMI_TEXTURE|LXf_PMI_DYNAMIC|LXf_PMI_FREEZE)

/*
 * This interface was retired in modo 901, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXa_POLYGON1	"polygon"
        #define LXu_POLYGON1	"5839056D-28BF-4D72-8A26-E4AA00DA788F"

/*
 * The ILxEdge is used to obtain information about specific edges,
 * as well as allowing the list of edges to be walked.
 */

        #define LXa_EDGE	"edge"
        #define LXu_EDGE	"19A44432-E2CF-4BCF-9EA6-D696E7A0F16E"
        // [local]  ILxEdge
        // [python] ILxEdge:TestMarks		bool
        // [python] ILxEdge:IsBorder		bool
        // [python] ILxEdge:MapValue		bool
        // [python] ILxEdge:MapValue:value	vector
        // [python] ILxEdge:MapEvaluate		bool
        // [python] ILxEdge:MapEvaluate:value	vector

/*
 * The ILxMeshMap is used to obtain information about specific point maps,
 * as well as allowing the list of maps to be walked.
 */

        #define LXa_MESHMAP	"meshmap"
        #define LXu_MESHMAP	"2AEBA454-2AC4-4F1E-B892-7A16F7601030"
        // [local]  ILxMeshMap
        // [python] ILxMeshMap:IsContinuous	bool
        // [python] ILxMeshMap:IsEdgeMap	bool
        // [python] ILxMeshMap:ZeroDefault	bool

/*
 * Map types can be arbitrary, so clients and even plugins are free to invent
 * any type with any meaning they need for a specific application.  However,
 * having some predefined common types makes some of the basic applications
 * more obvious.  The dimension of the map is given in parenthesis.
 * - OPOS(3)
 * Object-space position vectors.  This is a required singleton map and must be
 * defined for all points.  If the map is undefined then the point has no
 * base location in object space.
 * - MORF(3)
 * Morph target displacement vectors.  The position of a point in the morph
 * target is the base position of the point plus the offset stored in the map.
 * Unassigned points have an implicit displacement of zero.
 * 
 * - SPOT(3)
 * Morph target position vectors.  The position of a point in the morph
 * target is given by an absolute vector in the map.  Unassigned points have
 * their position given by the base position.
 * 
 * - NORM(3)
 * Surface normals.  These can be continuous at each point for smooth meshes
 * or discontinuous for angular shapes.
 * 
 * - TXUV(2)
 * Texture coordinates with an implicit range of 0.0 to 1.0.  Values outside
 * that range are folded back into the unit range when used.  Unassigned
 * points have no coordinates and no texturing is done for them.
 * 
 * - WGHT(1)
 * General point weights.  Although these can have any value, they should
 * map into the nominal range of 0.0 to 1.0, or -1.0 to 1.0.  Typically
 * unassigned points are treated as if they have a weight of zero, so the
 * zero value should be considered the default.  These weights can also have any
 * meaning, and may be applied to modulate shading, deformation or animation.
 * 
 * - PICK(0)
 * Point selection sets.  Since they have dimension zero, there is no actual
 * data associated with the points.  If the point has a value in the map
 * that indicates membership in the selection set.
 * 
 * - EPCK(0)
 * Edge selection sets.  Since they have dimension zero, there is no actual
 * data associated with the edges.  If the edge has a value in the map
 * that indicates membership in the selection set.
 * 
 * - RGB (3)
 * Point color information, stored as red, green and blue in the range of
 * 0.0 to 1.0.
 * 
 * - RGBA(4)
 * Point color with transparency, stored as red, green, blue and alpha.
 * 
 * - SUBV(1)
 * SubPatch point weights in the range of -1.0 to 1.0.  Unassigned points
 * have the default zero weight.
 * 
 * - VECT(3)
 * Vector expressed in the local space defined by the normal and the base vector.
 * 
 * - TBASIS(6)
 * Tangent and bitangent (binormal) packed together forming a tangent basis with 
 * the normal vector, usualy used for deforming mesh (ie. rigged character) normal 
 * mapping for real-time 3D engines.
 * 
 * - HARD(0)
 * Hard edge map.  Since they have dimension zero, there is no actual
 * data associated with the edges.  If the edge has a value in the map
 * that indicates it should be hard.
 * 
 * - INDX(1)
 * Integer index to specify 1D profile to vertex.
 * 
 */

        #define LXi_VMAP_OBJECTPOS	LXxID4('O','P','O','S')
        #define LXi_VMAP_MORPH		LXxID4('M','O','R','F')
        #define LXi_VMAP_SPOT		LXxID4('S','P','O','T')
        #define LXi_VMAP_NORMAL		LXxID4('N','O','R','M')
        #define LXi_VMAP_TEXTUREUV	LXxID4('T','X','U','V')
        #define LXi_VMAP_WEIGHT		LXxID4('W','G','H','T')
        #define LXi_VMAP_PICK		LXxID4('P','I','C','K')
        #define LXi_VMAP_EPCK		LXxID4('E','P','C','K')
        #define LXi_VMAP_RGB		LXxID4('R','G','B',' ')
        #define LXi_VMAP_RGBA		LXxID4('R','G','B','A')
        #define LXi_VMAP_SUBDIV		LXxID4('S','U','B','V')
        #define LXi_VMAP_VECTOR		LXxID4('V','E','C','T')
        #define LXi_VMAP_TBASIS		LXxID4('T','B','A','S')
        #define LXi_VMAP_BSPLINE	LXxID4('B','S','P','L')
        #define LXi_VMAP_HARDEDGE	LXxID4('H','A','R','D')
        #define LXi_VMAP_SEAM		LXxID4('S','E','A','M')
        #define LXi_VMAP_PITM		LXxID4('P','I','T','M')
        // See Also:  vmaptypes

/*
 * Sometimes it's nice to have maps that are linked to specific items, especially
 * for weights. This is done by setting a special prefix on the map name that
 * is recognized as belonging to an item. The rest of the name is the internal
 * item ident.
 */

        #define LXsVMAP_ITEMPREFIX	"__item_"


        #define LXu_MESHLISTENER	"9373A003-BEBC-44D4-ADEB-36862F0AFC38"
        // [export] ILxMeshListener ml

/*
 * This interface was retired in modo 701, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXu_MESHLISTENER1	"957900AC-BC06-45D9-B1B1-9CC5A2AEC026"
        // [export] ILxMeshListener1 ml

/*
 * The MeshTracker can also be used by clients to register individual changes to
 * specific elements. Changes are passed using the LXf_ELTEDIT flags. These describe
 * a single operation that has been performed to an element.
 * - ADD
 * An element has been added to the mesh.
 * - DELETE
 * An element has been removed from the mesh.
 * 
 * - POINT_POS
 * The position of a point has changed.
 * 
 * - VMAP_VAL
 * The value of a vertex map for a point or polygon has changed.
 * 
 * - POLY_VLIST
 * The vertex list for a polygon has been modified.
 * 
 * - POLY_TAGS
 * The tags assigned to a polygon have changed.
 * 
 * - POLY_TYPE
 * The type of the polygon has changed.
 * 
 */

        #define	LXf_ELTEDIT_ADD			 0x001
        #define	LXf_ELTEDIT_DELETE		 0x002
        #define	LXf_ELTEDIT_POINT_POS		 0x004
        #define	LXf_ELTEDIT_VMAP_VAL		 0x008
        #define LXf_ELTEDIT_POLY_VLIST		 0x010
        #define LXf_ELTEDIT_POLY_TAGS		 0x020
        #define LXf_ELTEDIT_POLY_TYPE		 0x040
        #define LXf_ELTEDIT_ALL			 (LXf_ELTEDIT_ADD|LXf_ELTEDIT_DELETE|LXf_ELTEDIT_POINT_POS|LXf_ELTEDIT_VMAP_VAL|LXf_ELTEDIT_POLY_VLIST|LXf_ELTEDIT_POLY_TAGS|LXf_ELTEDIT_POLY_TYPE)


        #define LXu_MESHTRACKER		"8FAD284F-C289-40AB-97D2-63932385BAB6"
        // [local]  ILxMeshTracker

/*
 * A mesh operation is a container for a modeling operating on a target mesh. It is a
 * simple interface that takes a writeable mesh, and modifies the mesh in any way that
 * it wants. This could be as simple as simply offsetting geometry positions, or it could
 * be more complex, such as creating new geometry or editing mesh properties.
 */

        #define	LXu_MESHOPERATION		"8B72A28C-6C2C-4E9C-8242-7D13AE80008E"
        #define LXa_MESHOPERATION		"meshoperation3"
        // [local] ILxMeshOperation
        // [export] ILxMeshOperation mop
        // [default] ILxMeshOperation:Compare = LXiMESHOP_DIFFERENT
        // [const] ILxMeshOperation:SetTransform

/*
 * When a mesh operation creates new geometry, it can be inefficient to recreate the
 * geometry for every evaluation. This set of optional functions allow the previous
 * evaluation result to be used as a starting point for the current evaluation. For
 * example, a bevel tool may use the initial evaluation to create the beveled polygons,
 * and any further evaluation calls may simply offset the position of the beveled geometry.
 * The Compare function is used to compare one mesh operation with another. The old
 * mesh operation is passed to the new mesh operation and the attributes should be
 * compared, to see if they are compatible. If the function returns DIFFERENT, then the
 * operation will be discarded and evaluated from scratch. If the function returns
 * COMPATIBLE, then the previous result will be used as a starting point for the next
 * evaluation. If the function returns IDENTICAL, then re-evaluation of the mesh operation
 * will be skipped altogether, and the previous result will be used, as is.
 */

        #define LXiMESHOP_DIFFERENT		0
        #define LXiMESHOP_COMPATIBLE		1
        #define LXiMESHOP_IDENTICAL		2


        #define	LXu_MESHOPERATION2		"71D124CB-8D2A-4E5A-814D-3921D9986D3A"
        #define LXa_MESHOPERATION2		"meshoperation2"


        #define	LXu_MESHOPERATION1		"98103095-54AC-45CD-8685-84614D996AC2"
        #define LXa_MESHOPERATION1		"meshoperation"


        #define LXiFILT_MODIFY		1
        #define LXiFILT_GENERATE	2
        #define LXiFILT_SOURCE		3


        #define LXu_MESHFILTER	"9AA6236A-CF0F-4E72-B8F3-20BBC5532B61"
        // [local]   ILxMeshFilter
        // [export]  ILxMeshFilter mfilt
        // [python]  ILxMeshFilter:Generate	obj Mesh


        #define LXu_MESHFILTER1	"F5896BA1-7EC5-4EE9-852F-BF977E451953"


        #define LXu_MESHFILTERBBOX	"FBD83166-4B50-42A0-8C91-C36D3BB76904"
        // [local]  ILxMeshFilterBBox
        // [export] ILxMeshFilterBBox mfbbox

/*
 * The ident interface returns a mesh in the mesh stack that has a matching
 * ident. The ident is usually defined as the item ident of the Mesh Operation
 * or Deformer that generated the filter in the mesh stack. If no mesh can be
 * found with the provided ident, the function will return LXe_NOTFOUND.
 * A BASE identifier will return the non-editable base mesh. And obviously
 * top will return the topmost mesh in the stack.  The identifier for the currently
 * selected deformer can be obtained through the layer service's "CurrentDeformer" function.
 */

        #define LXs_MESHFILTER_BASE	"__base__"
        #define LXs_MESHFILTER_TOP	"__top__"


        #define LXu_MESHFILTERIDENT	"68713DE3-45D8-4722-BC43-D03EF4964AB8"
        // [local]  ILxMeshFilterIdent
        // [python] ILxMeshFilterIdent:Generate	obj Mesh


        #define LXu_MESHFILTERBLEND	"590F4482-3EDE-47DB-A260-651B687D2B1E"
        // [local]  ILxMeshFilterBlend
        // [python] ILxMeshFilterBlend:Generate	obj MeshBlend


        #define LXu_MESHBLEND		"E4690A09-96B9-40CB-B264-AB900BF1D989"
        // [local]  ILxMeshBlend
        // [python] ILxMeshBlend:GenerateMesh	obj Mesh

/*
 * If clients want to store xtra data with the polygons and points on the mesh,
 * they can do so by providing the following server tags - the value of the tags
 * does not matter.
 */

        #define LXsMESHXTRADATA_POINT		"meshdata.point"
        #define LXsMESHXTRADATA_POLYGON		"meshdata.polygon"

/*
 * Metadata is invalidated when the mesh changes. Rather than invalidating on any
 * mesh change, this can be filtered using a mesh edit flag. The LXsMESHMETADATA_FLAGS
 * server tag allows a comma seperated list of change types to be specified. If the
 * mesh changes in any of these ways, the meta data is invalidated.
 */

        #define LXsMESHMETADATA_FLAGS		"meshmetadataflags"

        #define LXs_MESHEDIT_POSITION		"position"
        #define LXs_MESHEDIT_POINTS		"points"
        #define LXs_MESHEDIT_POLYGONS		"polygons"
        #define LXs_MESHEDIT_POL_TAGS		"pol_tags"
        #define LXs_MESHEDIT_POL_TYPE		"pol_type"
        #define LXs_MESHEDIT_MAP_CONTINUITY	"map_continuity"
        #define LXs_MESHEDIT_MAP_UV		"map_uv"
        #define LXs_MESHEDIT_MAP_MORPH		"map_morph"
        #define LXs_MESHEDIT_MAP_OTHER		"map_other"
        #define LXs_MESHEDIT_MAP_LIST		"map_list"

/*
 * Meta data can also be incrementally updated if the change is limited to position,
 * or vertex map changes. The Validate will be called with the LXf_MESHEDIT_DELTA
 * change flag. Any modified elements are marked with the LXsMARK_DELTA mark mode,
 * and can be enumerated to perform an incremental update to those elements.
 */

        #define LXs_MESHEDIT_DELTA		"delta"


        #define LXu_MESHMETADATA	"2C6633EE-BFB0-41B5-BB36-2B1EBE310D3E"
        #define LXa_MESHMETADATA	"meshmetadata"
        // [export] ILxMeshMetaData	 meta

/*
 * Points and Polygons accessed during mesh meta data validation can have xtra data
 * associated with them. This data persists for the lifetime of the meta data, can
 * be accessed extremely quickly and is destroyed when the mesh element is deleted.
 * The data can store either a pointer to some memory, or an reference counted COM
 * object.
 */

        #define LXu_MESHXTRADATA	"A9CC9F05-AB4F-45AD-AEB0-F3A2D1F66A98"
        #define LXa_MESHXTRADATA	"meshxtradata"
        // [local] ILxMeshXtraData

#endif
