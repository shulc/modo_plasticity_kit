/*
 * LX poly module
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
#ifndef LX_poly_H
#define LX_poly_H

typedef struct vt_ILxSUBDPolyType ** ILxSUBDPolyTypeID;
typedef struct vt_ILxSubdivision ** ILxSubdivisionID;

#include <lxmesh.h>



/*
 * The SDK interface is a polymorphic interface of the mesh.  It's the only way
 * to get the quad patch directly.
 */
typedef struct vt_ILxSUBDPolyType {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetCorner) (
        LXtObjectID		 self,
        LXtPointID		 pnt,
        LXtFVector		 pos);

        LXxMETHOD(  LxResult,
GetQuad) (
        LXtObjectID		 self,
        LXtPolygonID		 pol,
        unsigned int		 index,
        LXtFVector		 qp[9]);
} ILxSUBDPolyType;

/*
 * Subdivision object provides the interface to use external subdivision engine for PSUB polygon
 * type. The PSUB polygon type calculates subdivision points by this object while it is set instead
 * of internal methods.
 * 	
 * Generates topological net for subdivision surface with cage polygons
 * in the given mesh.
 * 
 * Update position and normal buffer with new cage vertex positions in
 * the give mesh.
 * 
 * Invalidate the stat to update topology at "Validate".
 * 
 * Invalidate the stat to update position at "Validate".
 * 
 * Return the current status for validation
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Returns total number of faces for all levels.
 * 
 * Returns the depth of the given face.
 * 
 * Returns number of vertex in the given face.
 * 
 * Returns vertex ID of the vertex of face.
 * 
 * Returns number of face for the given level.
 * 
 * Return face offset at the top of the level.
 * 
 * Returns child face ID of the vertex of face.  If not, it returns -1.
 * 
 * Returns the parent face ID. If not, it returns -1.
 * 
 * Returns the source polygon ID of the face.
 * 
 * Returns the face ID at the top level from the given polygon.
 * 
 * Returns total number of vertices.
 * 
 * Returns number of vertices for the given level.
 * 
 * Return vertex offset at the top of the level.
 * 
 * Return vertex position of the given vertex.
 * 
 * Return vertex position of the given vertex.
 * 
 * Return vertex normal vector of the given vertex.
 * 
 * Add the name of uv texture map to subdivide. It returns the entry index number.
 * If set null, to reset thelist of texture name.
 * 
 * Return the number of texture map in the current name list.
 * 
 * Return the name for texture map given by index.
 * 
 * Return the index number for the given texture map. If nothing, it returns -1.
 * 
 * Return the pointer of UV value for the given vert of face at the current level 
 * for the given uv texture map.
 */
typedef struct vt_ILxSubdivision {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Validate) (
        LXtObjectID		 self,
        LXtObjectID	         mesh);
        LXxMETHOD(  LxResult,
Refine) (
        LXtObjectID		 self,
        LXtObjectID	         mesh);
        LXxMETHOD(  void,
InvalidateTopology) (
        LXtObjectID		 self);
        LXxMETHOD(  void,
InvalidatePosition) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
Status) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
MaxLevel) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
SetMaxLevel) (
        LXtObjectID		 self,
        int			 level);
        LXxMETHOD(  int,
BoundaryRule) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
SetBoundaryRule) (
        LXtObjectID		 self,
        int			 bound);
        LXxMETHOD(  int,
UVBoundaryRule) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
SetUVBoundaryRule) (
        LXtObjectID		 self,
        int			 bound);
        LXxMETHOD(  int,
Scheme) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
SetScheme) (
        LXtObjectID		 self,
        int			 scheme);
        LXxMETHOD(  int,
Backend) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
SetBackend) (
        LXtObjectID		 self,
        int			 backend);
        LXxMETHOD(  int,
Adaptive) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
SetAdaptive) (
        LXtObjectID		 self,
        int			 adaptive);
        LXxMETHOD(  int,
NumFaces) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
FaceDepth) (
        LXtObjectID		 self,
        int		         faceIndex);
        LXxMETHOD(  int,
NumVerticesOfFace) (
        LXtObjectID		 self,
        int		         faceIndex);
        LXxMETHOD(  int,
VertexOfFace) (
        LXtObjectID		 self,
        int		         faceIndex,
        int		         vertofface);
        LXxMETHOD(  int,
NumLevelFaces) (
        LXtObjectID		 self,
        int			 level);
        LXxMETHOD(  int,
FirstFaceOffset) (
        LXtObjectID		 self,
        int			 level);
        LXxMETHOD(  int,
ChildFace) (
        LXtObjectID		 self,
        int			 faceIndex,
        int			 vertOfFace);
        LXxMETHOD(  int,
ParentFace) (
        LXtObjectID		 self,
        int			 faceIndex);
        LXxMETHOD(  LXtPolygonID,
PolygonID) (
        LXtObjectID		 self,
        int		         faceIndex);
        LXxMETHOD(  int,
PolygonFace) (
        LXtObjectID		 self,
        LXtPolygonID	         polyID);
        LXxMETHOD(  int,
NumVertices) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
NumLevelVertices) (
        LXtObjectID		 self,
        int			 level);
        LXxMETHOD(  int,
FirstVertexOffset) (
        LXtObjectID		 self,
        int			 level);
        LXxMETHOD(  int,
ParentVertex) (
        LXtObjectID		 self,
        int		         vertIndex);
        LXxMETHOD(  float *,
VertexPosition) (
        LXtObjectID		 self,
        int		         vertIndex);
        LXxMETHOD(  float *,
VertexNormal) (
        LXtObjectID		 self,
        int		         vertIndex);
        LXxMETHOD(  int,
AddUVMap) (
        LXtObjectID		 self,
        const char	        *name);
        LXxMETHOD(  int,
NumUVMap) (
        LXtObjectID		 self);
        LXxMETHOD(  const char *,
UVMapName) (
        LXtObjectID		 self,
        int			 mapIndex);
        LXxMETHOD(  int,
LookupUVMap) (
        LXtObjectID		 self,
        const char	        *name);
        LXxMETHOD(  float *,
GetUV) (
        LXtObjectID		 self,
        int			 mapIndex,
        int			 faceIndex,
        int			 vertOfFace);
} ILxSubdivision;


        #define LXu_SUBDPOLYTYPE	"3441291E-3686-42F1-A4CA-71FC4AE5243A"


        #define LXfSUBD_STATUS_VALID		 0x0
        #define LXfSUBD_STATUS_POSITION		 0x1
        #define LXfSUBD_STATUS_TOPOLOGY		 0x2


        #define LXiSUBD_BOUND_NONE		 0
        #define LXiSUBD_BOUND_EDGEONLY		 1
        #define LXiSUBD_BOUND_EDGEANDCORNER	 2
        #define LXiSUBD_BOUND_ALWAYSSHARP	 3


        #define LXiSUBD_SCHEME_CATMARK		 0
        #define LXiSUBD_SCHEME_LOOP		 1
        #define LXiSUBD_SCHEME_BILINEAR		 2


        #define LXiSUBD_BACKEND_CPU		 0
        #define LXiSUBD_BACKEND_OPENCL		 1
        #define LXiSUBD_BACKEND_CUDA		 2


        #define LXa_SUBDIVISION		"subdivision"
        #define LXu_SUBDIVISION		"0910EEE5-01DF-4120-B664-E804CAC38AF5"
        // [export] ILxSubdivision subdiv
        // [local]  ILxSubdivision

#endif
