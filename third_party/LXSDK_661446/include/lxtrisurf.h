/*
 * LX trisurf module
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
#ifndef LX_trisurf_H
#define LX_trisurf_H

typedef struct vt_ILxTriangleSurface ** ILxTriangleSurfaceID;
typedef struct vt_ILxTriangleGroup ** ILxTriangleGroupID;
typedef struct vt_ILxTriangleGroup1 ** ILxTriangleGroup1ID;

#include <lxcom.h>



typedef struct vt_ILxTriangleSurface {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
SetSize) (
        LXtObjectID		 self,
        unsigned		 nvrt,
        unsigned		 ntri);

        LXxMETHOD(  LxResult,
AddVector) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name,
        unsigned		*index);

        LXxMETHOD(  float *,
SetVector) (
        LXtObjectID		 self,
        unsigned		 index,
        unsigned		 vrt);

        LXxMETHOD(  unsigned *,
SetTriangle) (
        LXtObjectID		 self,
        unsigned		 tri);

        LXxMETHOD(  unsigned *,
FixNormals) (
        LXtObjectID		 self);

        LXxMETHOD(  void,
GetSize) (
        LXtObjectID		 self,
        unsigned		*nvrt,
        unsigned		*ntri);

        LXxMETHOD(  unsigned *,
Triangles) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
VectorInfo) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtID4			*type,
        const char	       **name,
        unsigned		*dim);

        LXxMETHOD(  float *,
Vector) (
        LXtObjectID		 self,
        unsigned		 index);

        LXxMETHOD(  LxResult,
SetEdgeCount) (
        LXtObjectID		 self,
        unsigned		 nedge);

        LXxMETHOD(  unsigned *,
SetEdge) (
        LXtObjectID		 self,
        unsigned		 edge);

} ILxTriangleSurface;

typedef struct vt_ILxTriangleGroup {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddSurface) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
GetSurface) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Cleanup) (
        LXtObjectID		 self);
} ILxTriangleGroup;

typedef struct vt_ILxTriangleGroup1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddSurface) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
GetSurface) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);
} ILxTriangleGroup1;

/*
 * TriGroups have an exo-type that allows them to be channel values. There's also a
 * function for accessing the internal pointer from the exo-value.
 */

        #define LXsTYPE_TRIGROUP	"tgroup"


        #define LXu_TRIANGLESURFACE	"B1D985A7-34D6-4251-94AA-EEFB2C7527F9"
        #define LXu_TRIANGLEGROUP	"3A0597DF-EA75-4272-8831-6B7A2BA5FEE3"
        // [local]  ILxTriangleSurface
        // [local]  ILxTriangleGroup
        // [python] ILxTriangleGroup:AddSurface		obj TriangleSurface
        // [python] ILxTriangleGroup:GetSurface		obj TriangleSurface

/*
 * This interface was retired in modo 801, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXu_TRIANGLEGROUP1	"6975B2A4-69E8-4ED2-9058-9C0948CBB43C"

#endif
