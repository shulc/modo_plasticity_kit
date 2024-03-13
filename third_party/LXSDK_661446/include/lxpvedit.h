/*
 * LX pvedit module
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
#ifndef LX_pvedit_H
#define LX_pvedit_H

typedef struct vt_ILxPolygonSlice ** ILxPolygonSliceID;
typedef struct vt_ILxSolidDrill ** ILxSolidDrillID;

#include <lxcom.h>
#include <lxmesh.h>



/*
 * Set the polygon slicing plane.  This can be set at any time, but must be
 * set before any knives are applied.
 * 
 * Initialize the slice data for the given polygon.  This decomposes the
 * polygon into edges and is ready for knife action.  If "setAxis" is true,
 * the slice axis will be set based on the polygon.
 * 
 * Cut the polygon by the line segment given by two positions.
 * 
 * Complete the slicing of a polygon.  This will either leave the polygon
 * unmarked if it was untouched by any knife, or it will leave the polygon
 * marked for deletion and create a set of new polygons to replace the
 * old, after having been sliced by all the knives.
 * 
 */
typedef struct vt_ILxPolygonSlice {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
SetAxis) (
        LXtObjectID		 self,
        unsigned		 axis);
        LXxMETHOD(  LxResult,
SetAxisByVector) (
        LXtObjectID		 self,
        const LXtVector		 axis);
        LXxMETHOD(  LxResult,
Start) (
        LXtObjectID		 self,
        LXtObjectID		 meshObj,
        LXtPolygonID		 pol,
        unsigned		 setAxis);
        LXxMETHOD(  LxResult,
ByLine) (
        LXtObjectID		 self,
        const LXtVector		 pos0,
        const LXtVector		 pos1);
        LXxMETHOD(  int,
Done) (
        LXtObjectID		 self);
} ILxPolygonSlice;

/*
 * This object provides the interface to access internal solid drill and CSG
 * boolean functions.
 * 
 * Clear the solid drill context.
 * 
 * Add a mesh to drill the edit mesh. The xfrm is the matrix to convert the
 * vertex positions in the driver mesh to the local space for the edit mesh.
 * If the space of driver mesh is same as the edit mesh, "xfrm" can be null.
 * The solid drill uses only FACE polygons and the mesh shape must be closed.
 * This must be called in the main thread.
 * 
 * Execute the given operation to the edit mesh by added driver meshes. The
 * operation modes are exact same as options from solid drill and CSG boolean
 * commands. "sten" is a string for STENCIL mode.  This must be called in the 
 * main thread.
 */
typedef struct vt_ILxSolidDrill {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Clear) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
AddMesh) (
        LXtObjectID		 self,
        LXtObjectID		 meshObj,
        const LXtMatrix4	 xfrm);
        LXxMETHOD(  LxResult,
Execute) (
        LXtObjectID		 self,
        LXtObjectID		 meshObj,
        const LXtMatrix4	 xfrm,
        LXtMarkMode		 pick,
        unsigned int		 mode,
        const char		*sten,
        LXtObjectID		 monitor);
} ILxSolidDrill;


        #define LXa_POLYGONSLICE	"polygonSlice"
        #define LXu_POLYGONSLICE	"99C623EE-0873-4DB5-90DF-CC9460DA8FA8"

        // [local]  ILxPolygonSlice
        // [python] type LXtPolygonID id


        #define LXi_SDRILLv_CORE		 0
        #define LXi_SDRILLv_TUNNEL		 1
        #define LXi_SDRILLv_STENCIL		 2
        #define LXi_SDRILLv_NONE		 3

        #define LXi_SDRILLv_CSG_UNION		 4
        #define LXi_SDRILLv_CSG_INTERSECT	 5
        #define LXi_SDRILLv_CSG_SUBTRACT	 6
        #define LXi_SDRILLv_CSG_ADD		 7


        #define LXa_SOLIDDRILL	"solidDrill"
        #define LXu_SOLIDDRILL	"0D6D30C6-0DEB-4848-A9F9-731472255BA9"

        // [local]  ILxSolidDrill
        // [python] type LXtMarkMode unsigned

#endif
