/*
 * LX meshOLD module
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
#ifndef LX_meshOLD_H
#define LX_meshOLD_H

typedef struct vt_ILxMeshOLD ** ILxMeshOLDID;
typedef struct vt_ILxMeshOLDEdit ** ILxMeshOLDEditID;

#include <lxcom.h>
#include <lxvmath.h>

/*
 * The query interfaces define blank pointer types for points and polygons.
 * These refer to internal objects but they are not COM interfaces and
 * cannot be acted on directly.
 */

        typedef void *		 LXtPntID;
        typedef void *		 LXtPolID;
        typedef void *		 LXtOldEdgeID;
        typedef void *		 LXtVMapID;


        #ifndef   LX_DEF_LXTMESHID
          #define LX_DEF_LXTMESHID
          typedef struct st_Mesh * 	LXtMeshID;
        #endif


/*
 * The "info" structs provide information about each of the exported structs.
 * - id:    Opaque pointer to VerxID.
 * - polys: List of polys this point is connected to.
 * - npoly: Number of polys this point is part of.
 * - pos:   Position of point in object space.
 */
typedef struct st_LXtMeshPointInfo {
        LXtPntID		 id;
        const LXtPolID		*polys;
        int			 npoly;
        float			 pos[3];
} LXtMeshPointInfo;

/*
 * - id:    Opaque pointer to PolyID.
 * - type:  The name of the PolyType of this poly
 * - vlist: List of vertices that make up this poly.
 * - nvert: Number of points that make up this poly.
 * - flags: This poly's flags.
 */
typedef struct st_LXtMeshPolyInfo {
        LXtPolID		 id;
        const char		*type;
        LXtPntID		*vlist;
        int			 nvert;
        int			 flags;
        
} LXtMeshPolyInfo;

/*
 * - id:        Opaque pointer to VmapID.
 * - type:      The type of VMap.
 * - name:      The name of VMap.
 * - dimension: Number of elements.
 */
typedef struct st_LXtMeshVMapInfo {
        LXtVMapID		 id;
        int			 type;
        const char		*name;
        int			 dimension;
} LXtMeshVMapInfo;

/*
 * - id:         Opaque pointer to MeshEdgeID.
 * - A, B:       Points on each end of the edge.
 * - idxA, idxB: Mesh indices of those points.
 * - polys:      Index of polys that use this edge.
 * - npoly:      Number of polys that use this edge.
 */
typedef struct st_LXtMeshEdgeInfo {
        LXtOldEdgeID		 id;
        LXtPntID		 A;
        LXtPntID		 B;
        int			 idxA;
        int			 idxB;
        const LXtPolID		*polys;
        int			 npoly;
} LXtMeshEdgeInfo;


/*
 * Given the index of each element, the query functions fill in client-provided
 * structs with data about the element.
 * The interface allows some basic access to elements in the mesh.  The first
 * functions simply count the elements.
 * - NumPoints()
 * Number of points in the mesh.
 * 
 * - NumPolys()
 * Number of polys in the mesh.
 * 
 * - NumEdges()
 * Number of edges in the mesh.
 * 
 * - NumVMaps()
 * Number of VMaps in the mesh.  If a type is specified then the index is
 * constrained to that type.
 * 
 * - GetEdge()
 * Fills in the edge info struct with the edge at the specified index in the
 * model.
 * 
 * - IterateEdge()
 * Set the struct id to NULL when starting and each successive call will return
 * the next edge.
 * 
 * - GetPointsEdge()
 * Fills in the edge info struct with the edge that is made up of the two
 * specified points.  If none is found then id is set to NULL and the function
 * returns LXe_NOTFOUND.
 * 
 * - GetPoint()
 * Fills in the point info struct with the point at the specified index in the
 * model.
 * 
 * - GetPointConnectedEdges()
 * Fills in edges with those connected to this point.  'n' contains the number.
 * 
 * - GetPolyConnectedEdges()
 * Fills in edges with those connected to this poly.  'n' contains the number.
 * 
 * - GetPointPos()
 * Faster way to get the point position if that is all you need.
 * 
 * - GetPolyTagCount()
 * Returns the number of tags on this polygon
 * 
 * - GetPolyTagByIndex()
 * Returns the ID of the tag at the specified index.  'tag' will be pointed at the
 * value of that tag.  Returns 0 if the out of range.
 * 
 * - GetPoly()
 * Fills in the poly info struct with the poly at the specified index in the
 * model.
 * 
 * - GetPolyNormal()
 * Returns the geometric normal of this poly.
 * 
 * - GetPointNormal()
 * Returns the geometric normal of this point.  This is the average of the
 * connected poly normals.
 * 
 * - GetPointPoly()
 * Based on the polys that use this point, fills in the poly struct at the
 * specified index (i.e. a point might be part of four polys).  The index would
 * have a range of 0..3.
 * 	
 * - GetPolyPoint()
 * The opposite of the above.  Used to access the points that make up the
 * specified poly.
 * 	
 * - GetVMap()
 * Fills in the VMap info struct with the vmap at the specified index.  If a vmap
 * type is specified then the index is constrained to that type.
 * 
 * - GetPolyPointVMapValue()
 * Given a point ID and poly ID returns the value in the specified VMap.  If the
 * value is discontinuous then 'disco' is set to TRUE.
 * 
 * - GetPolyIntersect()
 * Given a position and ray directions, fills in the poly info with the first poly
 * hit.  'hitPos' is filled with the position of the intersection.  'hitNorm' is
 * filled with the normal.  LXe_NOTFOUND is returned if nothing hit.
 * 
 */
typedef struct vt_ILxMeshOLD {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetBoundingBox) (
        LXtObjectID		 self,
        LXtBBox			*bbox);

        LXxMETHOD(  int,
NumPoints) (
        LXtObjectID		 self);

        LXxMETHOD(  int,
NumPolys) (
        LXtObjectID		 self);

        LXxMETHOD(  int,
NumEdges) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
GetEdge) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtMeshEdgeInfo		*info);

        LXxMETHOD(  LxResult,
IterateEdge) (
        LXtObjectID		 self,
        LXtMeshEdgeInfo		*info);

        LXxMETHOD(  LxResult,
GetEdgeLength) (
        LXtObjectID		 self,
        LXtOldEdgeID		 e,
        double			*val);

        LXxMETHOD(  LxResult,
GetEdgeCenter) (
        LXtObjectID		 self,
        LXtOldEdgeID		 e,
        float			*pos);

        LXxMETHOD(  LxResult,
GetEdgeInfo) (
        LXtObjectID		 self,
        LXtOldEdgeID		 e,
        LXtMeshEdgeInfo		*info);

        LXxMETHOD(  LxResult,
GetPointsEdge) (
        LXtObjectID		 self,
        LXtPntID		 vA,
        LXtPntID		 vB,
        LXtMeshEdgeInfo		*info);

        LXxMETHOD(  int,
GetPointConnectedEdges) (
        LXtObjectID		 self,
        LXtPntID		 v,
        const LXtOldEdgeID	       **edges);

        LXxMETHOD(  int,
GetPolyConnectedEdges) (
        LXtObjectID		 self,
        LXtPolID		 p,
        LXtOldEdgeID	       **edges);

        LXxMETHOD(  int,
NumVMaps) (
        LXtObjectID		 self,
        int			 type);

        LXxMETHOD(  LxResult,
GetPoint) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtMeshPointInfo	*info);

        LXxMETHOD(  LxResult,
GetPointPos) (
        LXtObjectID		 self,
        unsigned int		 index,
        float			*pos);

        LXxMETHOD(  LxResult,
GetPoly) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtMeshPolyInfo		*info);

        LXxMETHOD(  const float *,
GetPolyNormal) (
        LXtObjectID		 self,
        LXtPolID		 p);

        LXxMETHOD(  LxResult,
GetPointNormal) (
        LXtObjectID		 self,
        LXtPntID		 v,
        double			*vec);

        LXxMETHOD(  LxResult,
GetPolyCenteroid) (
        LXtObjectID		 self,
        LXtPolID		 p,
        double			*pos);

        LXxMETHOD(  unsigned int,
GetPolyTagCount) (
        LXtObjectID		 self,
        LXtPolID		 p);

        LXxMETHOD(  LXtID4,
GetPolyTagByIndex) (
        LXtObjectID		 self,
        LXtPolID		 p,
        unsigned int		 index,
        const char	       **tag);

        LXxMETHOD(  const char *,
GetPolyTag) (
        LXtObjectID		 self,
        LXtPolID		 p,
        LXtID4			 type);

        LXxMETHOD(  unsigned int,
GetMaterialCount) (
        LXtObjectID		 self);

        LXxMETHOD(  const char *,
GetMaterialNameByIndex) (
        LXtObjectID		 self,
        unsigned int		 index);

        LXxMETHOD(  unsigned int,
GetPartCount) (
        LXtObjectID		 self);

        LXxMETHOD(  const char *,
GetPartNameByIndex) (
        LXtObjectID		 self,
        unsigned int		 index);

        LXxMETHOD(  LxResult,
GetPointPoly) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtPntID		 v,
        LXtMeshPolyInfo		*pInfo);

        LXxMETHOD(  LxResult,
GetPolyPoint) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtPolID		 p,
        LXtMeshPointInfo	*vinfo);

        LXxMETHOD(  LxResult,
GetVMap) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 index,
        LXtMeshVMapInfo		*vmInfo);

        LXxMETHOD(  LxResult,
GetVMapByName) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name,
        LXtMeshVMapInfo		*vmInfo);

        LXxMETHOD(  const char *,
GetVMapName) (
        LXtObjectID		 self,
        LXtVMapID		 m);

        LXxMETHOD(  float *,
GetPointVMapValue) (
        LXtObjectID		 self,
        LXtVMapID		 m,
        LXtPntID		 v);

        LXxMETHOD(  float *,
GetPolyPointVMapValue) (
        LXtObjectID		 self,
        LXtVMapID		 m,
        LXtPolID		 p,
        LXtPntID		 v,
        int			*disco);

        LXxMETHOD(  int,
GetPolyFirstConvex) (
        LXtObjectID		 self,
        LXtPolID		 p);

        LXxMETHOD(  float *,
GetEdgeVMapValue) (
        LXtObjectID		 self,
        LXtVMapID		 m,
        LXtOldEdgeID		 e);

        LXxMETHOD(  LxResult,
GetPolyIntersect) (
        LXtObjectID		 self,
        double			 pos[3],
        double			 dir[3],
        double			*hitPos,
        double			*hitNorm,
        LXtMeshPolyInfo		*pInfo);

        LXxMETHOD( unsigned int,
GetPointIndex) (
        LXtObjectID		 self,
        LXtPntID		 v);

        LXxMETHOD( unsigned int,
GetPolyIndex) (
        LXtObjectID		 self,
        LXtPolID		 p);

} ILxMeshOLD;

/*
 * The edit interface is required to perform operations on a mesh.
 * - AddPoint()
 * Given a filled in LXtMeshPointInfo struct adds a point to the mesh.
 * - AddPoly()
 * Given a filled in LXtMeshPolyInfo struct adds a poly to the mesh.
 * - MovePoint()
 * Moves the specified point to the specified position.
 * - PolyTagSetDefault()
 * Sets the the value of the specified tag that will be applied
 * to any newly created polys.
 * 
 * - PolyTagDelete()
 * Removes all tags from the poly.
 * 
 * - PolyTagCopy()
 * Copies the tags from the src poly to the dest poly.
 * 
 * - AdjustPoint()
 * Moves the specified point by the specified amount.
 * 
 * - VMapCreate()
 * Creates a VMap of the specified type with the specified name.  The
 * LXtMeshVMapInfo struct is filled in with the newly created vmap's info.
 * 
 * - SetPolyPointVMapValue()
 * Sets a value for the specified point/poly set in the specified vmap.
 * Discontinuous values are created if needed.   The number of elements in
 * 'value' should match the dimension of the vmap.
 * 
 * 
 */
typedef struct vt_ILxMeshOLDEdit {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddPoint) (
        LXtObjectID		 self,
        LXtMeshPointInfo	*info);

        LXxMETHOD(  LxResult,
AddPoly) (
        LXtObjectID		 self,
        LXtMeshPolyInfo		*info);

        LXxMETHOD(  LxResult,
MovePoint) (
        LXtObjectID		 self,
        LXtPntID		 vrt,
        const double		*pos);

        LXxMETHOD(  LxResult,
PolyTagSet) (
        LXtObjectID		 self,
        LXtPolID		 pol,
        LXtID4			 type,
        const char		*tag);

        LXxMETHOD(  LxResult,
PolyTagSetDefault) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*tag);

        LXxMETHOD(  LxResult,
PolyTagCopy) (
        LXtObjectID		 self,
        LXtPolID		 from,
        LXtPolID		 to);

        LXxMETHOD(  LxResult,
PolyTagDelete) (
        LXtObjectID		 self,
        LXtPolID		 poly);
        
        LXxMETHOD(  LxResult,
AdjustPoint) (
        LXtObjectID		 self,
        LXtPntID		 vrt,
        const double		*pos);

        LXxMETHOD(  LxResult,
VMapCreate) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name,
        LXtMeshVMapInfo		*info);

        LXxMETHOD(  LxResult,
SetPointVMapValue) (
        LXtObjectID		 self,
        LXtVMapID		 m,
        LXtPntID		 v,
        const float		*value);
        
        LXxMETHOD(  LxResult,
SetPolyPointVMapValue) (
        LXtObjectID		 self,
        LXtVMapID		 m,
        LXtPolID		 p,
        LXtPntID		 v,
        const float		*value);
        
        LXxMETHOD(  LxResult,
SetEdgeVMapValue) (
        LXtObjectID		 self,
        LXtVMapID		 m,
        LXtOldEdgeID		 p,
        const float		*value);
        
} ILxMeshOLDEdit;


        #define LXi_POLY_MAXVERT	 65535

/*
 * The polygon type is given by a character string identifier which allows
 * for extensible polygon types.  A "face" polygon is just the facet defined by 
 * the vertices.  A "patch" polygon is a subPatch and renders as a bunch of 
 * faces which approximate the patch.  A "curve" polygon is a Modeler-style 
 * spline curve.
 */

        #define LXsPTYP_FACE		"face"
        #define LXsPTYP_PATCH		"patch"
        #define LXsPTYP_CURVE		"curve"
        #define LXsPTYP_BEZIER		"bezier"
        #define LXsPTYP_SUBD		"subdiv"
        #define LXsPTYP_SPCH		"spatch"
        #define LXsPTYP_HAIR		"hair"
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
        #define	LXiPTYP_PATCH		LXxID4('P','T','C','H')
        #define	LXiPTYP_BEZIER		LXxID4('B','E','Z','R')
        #define	LXiPTYP_SUBD		LXxID4('S','U','B','D')
        #define	LXiPTYP_SPCH		LXxID4('S','P','C','H')
        #define	LXiPTYP_HAIR		LXxID4('H','A','I','R')
        #define	LXiPTYP_TEXT		LXxID4('T','E','X','T')
        #define	LXiPTYP_PSUB		LXxID4('P','S','U','B')
        #define	LXiPTYP_LINE		LXxID4('L','I','N','E')
        #define	LXiPTYP_CRVFIL		LXxID4('C','F','I','L')
        #define	LXiPTYP_BSPLINE		LXxID4('B','S','P','L')
        #define	LXiPTYP_OPNT		LXxID4('O','P','N','T')

        #define LXiPTYP_BEZR		LXiPTYP_BEZIER
        #define LXiPTYP_CURV		LXiPTYP_CURVE
        #define LXiPTYP_BSPL		LXiPTYP_BSPLINE


        #define LXi_MELTf_CCSTART	1
        #define LXi_MELTf_CCEND		2
    // See Also:  LXi_MELTf_CCSTART LXi_MELTf_CCEND


        #define LXi_POLYTAG_MATERIAL		LXxID4('M','A','T','R')
        #define LXi_POLYTAG_PART		LXxID4('P','A','R','T')
        #define LXi_POLYTAG_SMOOTHING_GROUP	LXxID4('S','M','G','P')
        #define LXi_POLYTAG_PICK		LXxID4('P','I','C','K')
        #define LXi_POLYTAG_FONT		LXxID4('F','O','N','T')
        #define LXi_POLYTAG_TEXT		LXxID4('T','E','X','T')
        #define LXi_POLYTAG_JUST		LXxID4('J','U','S','T')
        #define LXi_POLYTAG_EXEC		LXxID4('E','X','E','C')
        #define LXi_POLYTAG_HIDE		LXxID4('H','I','D','E')
        #define LXi_POLYTAG_WORKPLANE		LXxID4('W','O','R','K')


        #define LXu_MESH_OLD		"CAC2F76E-D72E-4E62-B406-A5E0ADDCF364"
        #define LXu_MESHEDIT_OLD	"AB714588-CD54-4733-A619-99B07B2057C3"


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
        #define LXi_VMAP_POSESHAPE	LXxID4('P','O','S','E')
        #define LXi_VMAP_VECTOR		LXxID4('V','E','C','T')
        #define LXi_VMAP_TBASIS		LXxID4('T','B','A','S')
 	#define LXi_VMAP_DPDU		LXxID4('d','p','d','u')
        #define LXi_VMAP_TWIST		LXxID4('T','W','S','T')
        #define LXi_VMAP_COMP		LXxID4('C','O','M','P')
        #define LXi_VMAP_BSPLINE	LXxID4('B','S','P','L')
        #define LXi_VMAP_VMRK		LXxID4('V','M','R','K')
        #define LXi_VMAP_EMRK		LXxID4('E','M','R','K')
        #define LXi_VMAP_HARD		LXxID4('H','A','R','D')
        #define LXi_VMAP_SEAM		LXxID4('S','E','A','M')
        #define LXi_VMAP_PITM		LXxID4('P','I','T','M')
        // See Also:  vmaptypes

#endif
