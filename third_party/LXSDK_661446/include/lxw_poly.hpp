/*
 * C++ wrapper for lxpoly.h
 *
 *	Copyright (c) 2008-2022 The Foundry Group LLC
 *	
 *	Permission is hereby granted, free of charge, to any person obtaining a
 *	copy of this software and associated documentation files (the "Software"),
 *	to deal in the Software without restriction, including without limitation
 *	the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *	and/or sell copies of the Software, and to permit persons to whom the
 *	Software is furnished to do so, subject to the following conditions:
 *	
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.   Except as contained
 *	in this notice, the name(s) of the above copyright holders shall not be
 *	used in advertising or otherwise to promote the sale, use or other dealings
 *	in this Software without prior written authorization.
 *	
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *	DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef LXW_POLY_HPP
#define LXW_POLY_HPP

#include <lxpoly.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_Subdivision = {0x0910EEE5,0x01DF,0x4120,0xB6,0x64,0xE8,0x04,0xCA,0xC3,0x8A,0xF5};
    static const LXtGUID guid_SUBDPolyType = {0x3441291E,0x3686,0x42F1,0xA4,0xCA,0x71,0xFC,0x4A,0xE5,0x24,0x3A};
};

class CLxImpl_Subdivision {
  public:
    virtual ~CLxImpl_Subdivision() {}
    virtual LxResult
      subdiv_Validate (ILxUnknownID mesh)
        { return LXe_NOTIMPL; }
    virtual LxResult
      subdiv_Refine (ILxUnknownID mesh)
        { return LXe_NOTIMPL; }
    virtual void
      subdiv_InvalidateTopology (void)
        { }
    virtual void
      subdiv_InvalidatePosition (void)
        { }
    virtual int
      subdiv_Status (void)
        = 0;
    virtual int
      subdiv_MaxLevel (void)
        = 0;
    virtual int
      subdiv_SetMaxLevel (int level)
        = 0;
    virtual int
      subdiv_BoundaryRule (void)
        = 0;
    virtual int
      subdiv_SetBoundaryRule (int bound)
        = 0;
    virtual int
      subdiv_UVBoundaryRule (void)
        = 0;
    virtual int
      subdiv_SetUVBoundaryRule (int bound)
        = 0;
    virtual int
      subdiv_Scheme (void)
        = 0;
    virtual int
      subdiv_SetScheme (int scheme)
        = 0;
    virtual int
      subdiv_Backend (void)
        = 0;
    virtual int
      subdiv_SetBackend (int backend)
        = 0;
    virtual int
      subdiv_Adaptive (void)
        = 0;
    virtual int
      subdiv_SetAdaptive (int adaptive)
        = 0;
    virtual int
      subdiv_NumFaces (void)
        = 0;
    virtual int
      subdiv_FaceDepth (int faceIndex)
        = 0;
    virtual int
      subdiv_NumVerticesOfFace (int faceIndex)
        = 0;
    virtual int
      subdiv_VertexOfFace (int faceIndex, int vertofface)
        = 0;
    virtual int
      subdiv_NumLevelFaces (int level)
        = 0;
    virtual int
      subdiv_FirstFaceOffset (int level)
        = 0;
    virtual int
      subdiv_ChildFace (int faceIndex, int vertOfFace)
        = 0;
    virtual int
      subdiv_ParentFace (int faceIndex)
        = 0;
    virtual LXtPolygonID
      subdiv_PolygonID (int faceIndex)
        = 0;
    virtual int
      subdiv_PolygonFace (LXtPolygonID polyID)
        = 0;
    virtual int
      subdiv_NumVertices (void)
        = 0;
    virtual int
      subdiv_NumLevelVertices (int level)
        = 0;
    virtual int
      subdiv_FirstVertexOffset (int level)
        = 0;
    virtual int
      subdiv_ParentVertex (int vertIndex)
        = 0;
    virtual float *
      subdiv_VertexPosition (int vertIndex)
        = 0;
    virtual float *
      subdiv_VertexNormal (int vertIndex)
        = 0;
    virtual int
      subdiv_AddUVMap (const char *name)
        = 0;
    virtual int
      subdiv_NumUVMap (void)
        = 0;
    virtual const char *
      subdiv_UVMapName (int mapIndex)
        = 0;
    virtual int
      subdiv_LookupUVMap (const char *name)
        = 0;
    virtual float *
      subdiv_GetUV (int mapIndex, int faceIndex, int vertOfFace)
        = 0;
};
#define LXxD_Subdivision_Validate LxResult subdiv_Validate (ILxUnknownID mesh)
#define LXxO_Subdivision_Validate LXxD_Subdivision_Validate LXx_OVERRIDE
#define LXxC_Subdivision_Validate(c) LxResult c::subdiv_Validate (ILxUnknownID mesh)
#define LXxD_Subdivision_Refine LxResult subdiv_Refine (ILxUnknownID mesh)
#define LXxO_Subdivision_Refine LXxD_Subdivision_Refine LXx_OVERRIDE
#define LXxC_Subdivision_Refine(c) LxResult c::subdiv_Refine (ILxUnknownID mesh)
#define LXxD_Subdivision_InvalidateTopology void subdiv_InvalidateTopology (void)
#define LXxO_Subdivision_InvalidateTopology LXxD_Subdivision_InvalidateTopology LXx_OVERRIDE
#define LXxC_Subdivision_InvalidateTopology(c) void c::subdiv_InvalidateTopology (void)
#define LXxD_Subdivision_InvalidatePosition void subdiv_InvalidatePosition (void)
#define LXxO_Subdivision_InvalidatePosition LXxD_Subdivision_InvalidatePosition LXx_OVERRIDE
#define LXxC_Subdivision_InvalidatePosition(c) void c::subdiv_InvalidatePosition (void)
#define LXxD_Subdivision_Status int subdiv_Status (void)
#define LXxO_Subdivision_Status LXxD_Subdivision_Status LXx_OVERRIDE
#define LXxC_Subdivision_Status(c) int c::subdiv_Status (void)
#define LXxD_Subdivision_MaxLevel int subdiv_MaxLevel (void)
#define LXxO_Subdivision_MaxLevel LXxD_Subdivision_MaxLevel LXx_OVERRIDE
#define LXxC_Subdivision_MaxLevel(c) int c::subdiv_MaxLevel (void)
#define LXxD_Subdivision_SetMaxLevel int subdiv_SetMaxLevel (int level)
#define LXxO_Subdivision_SetMaxLevel LXxD_Subdivision_SetMaxLevel LXx_OVERRIDE
#define LXxC_Subdivision_SetMaxLevel(c) int c::subdiv_SetMaxLevel (int level)
#define LXxD_Subdivision_BoundaryRule int subdiv_BoundaryRule (void)
#define LXxO_Subdivision_BoundaryRule LXxD_Subdivision_BoundaryRule LXx_OVERRIDE
#define LXxC_Subdivision_BoundaryRule(c) int c::subdiv_BoundaryRule (void)
#define LXxD_Subdivision_SetBoundaryRule int subdiv_SetBoundaryRule (int bound)
#define LXxO_Subdivision_SetBoundaryRule LXxD_Subdivision_SetBoundaryRule LXx_OVERRIDE
#define LXxC_Subdivision_SetBoundaryRule(c) int c::subdiv_SetBoundaryRule (int bound)
#define LXxD_Subdivision_UVBoundaryRule int subdiv_UVBoundaryRule (void)
#define LXxO_Subdivision_UVBoundaryRule LXxD_Subdivision_UVBoundaryRule LXx_OVERRIDE
#define LXxC_Subdivision_UVBoundaryRule(c) int c::subdiv_UVBoundaryRule (void)
#define LXxD_Subdivision_SetUVBoundaryRule int subdiv_SetUVBoundaryRule (int bound)
#define LXxO_Subdivision_SetUVBoundaryRule LXxD_Subdivision_SetUVBoundaryRule LXx_OVERRIDE
#define LXxC_Subdivision_SetUVBoundaryRule(c) int c::subdiv_SetUVBoundaryRule (int bound)
#define LXxD_Subdivision_Scheme int subdiv_Scheme (void)
#define LXxO_Subdivision_Scheme LXxD_Subdivision_Scheme LXx_OVERRIDE
#define LXxC_Subdivision_Scheme(c) int c::subdiv_Scheme (void)
#define LXxD_Subdivision_SetScheme int subdiv_SetScheme (int scheme)
#define LXxO_Subdivision_SetScheme LXxD_Subdivision_SetScheme LXx_OVERRIDE
#define LXxC_Subdivision_SetScheme(c) int c::subdiv_SetScheme (int scheme)
#define LXxD_Subdivision_Backend int subdiv_Backend (void)
#define LXxO_Subdivision_Backend LXxD_Subdivision_Backend LXx_OVERRIDE
#define LXxC_Subdivision_Backend(c) int c::subdiv_Backend (void)
#define LXxD_Subdivision_SetBackend int subdiv_SetBackend (int backend)
#define LXxO_Subdivision_SetBackend LXxD_Subdivision_SetBackend LXx_OVERRIDE
#define LXxC_Subdivision_SetBackend(c) int c::subdiv_SetBackend (int backend)
#define LXxD_Subdivision_Adaptive int subdiv_Adaptive (void)
#define LXxO_Subdivision_Adaptive LXxD_Subdivision_Adaptive LXx_OVERRIDE
#define LXxC_Subdivision_Adaptive(c) int c::subdiv_Adaptive (void)
#define LXxD_Subdivision_SetAdaptive int subdiv_SetAdaptive (int adaptive)
#define LXxO_Subdivision_SetAdaptive LXxD_Subdivision_SetAdaptive LXx_OVERRIDE
#define LXxC_Subdivision_SetAdaptive(c) int c::subdiv_SetAdaptive (int adaptive)
#define LXxD_Subdivision_NumFaces int subdiv_NumFaces (void)
#define LXxO_Subdivision_NumFaces LXxD_Subdivision_NumFaces LXx_OVERRIDE
#define LXxC_Subdivision_NumFaces(c) int c::subdiv_NumFaces (void)
#define LXxD_Subdivision_FaceDepth int subdiv_FaceDepth (int faceIndex)
#define LXxO_Subdivision_FaceDepth LXxD_Subdivision_FaceDepth LXx_OVERRIDE
#define LXxC_Subdivision_FaceDepth(c) int c::subdiv_FaceDepth (int faceIndex)
#define LXxD_Subdivision_NumVerticesOfFace int subdiv_NumVerticesOfFace (int faceIndex)
#define LXxO_Subdivision_NumVerticesOfFace LXxD_Subdivision_NumVerticesOfFace LXx_OVERRIDE
#define LXxC_Subdivision_NumVerticesOfFace(c) int c::subdiv_NumVerticesOfFace (int faceIndex)
#define LXxD_Subdivision_VertexOfFace int subdiv_VertexOfFace (int faceIndex, int vertofface)
#define LXxO_Subdivision_VertexOfFace LXxD_Subdivision_VertexOfFace LXx_OVERRIDE
#define LXxC_Subdivision_VertexOfFace(c) int c::subdiv_VertexOfFace (int faceIndex, int vertofface)
#define LXxD_Subdivision_NumLevelFaces int subdiv_NumLevelFaces (int level)
#define LXxO_Subdivision_NumLevelFaces LXxD_Subdivision_NumLevelFaces LXx_OVERRIDE
#define LXxC_Subdivision_NumLevelFaces(c) int c::subdiv_NumLevelFaces (int level)
#define LXxD_Subdivision_FirstFaceOffset int subdiv_FirstFaceOffset (int level)
#define LXxO_Subdivision_FirstFaceOffset LXxD_Subdivision_FirstFaceOffset LXx_OVERRIDE
#define LXxC_Subdivision_FirstFaceOffset(c) int c::subdiv_FirstFaceOffset (int level)
#define LXxD_Subdivision_ChildFace int subdiv_ChildFace (int faceIndex, int vertOfFace)
#define LXxO_Subdivision_ChildFace LXxD_Subdivision_ChildFace LXx_OVERRIDE
#define LXxC_Subdivision_ChildFace(c) int c::subdiv_ChildFace (int faceIndex, int vertOfFace)
#define LXxD_Subdivision_ParentFace int subdiv_ParentFace (int faceIndex)
#define LXxO_Subdivision_ParentFace LXxD_Subdivision_ParentFace LXx_OVERRIDE
#define LXxC_Subdivision_ParentFace(c) int c::subdiv_ParentFace (int faceIndex)
#define LXxD_Subdivision_PolygonID LXtPolygonID subdiv_PolygonID (int faceIndex)
#define LXxO_Subdivision_PolygonID LXxD_Subdivision_PolygonID LXx_OVERRIDE
#define LXxC_Subdivision_PolygonID(c) LXtPolygonID c::subdiv_PolygonID (int faceIndex)
#define LXxD_Subdivision_PolygonFace int subdiv_PolygonFace (LXtPolygonID polyID)
#define LXxO_Subdivision_PolygonFace LXxD_Subdivision_PolygonFace LXx_OVERRIDE
#define LXxC_Subdivision_PolygonFace(c) int c::subdiv_PolygonFace (LXtPolygonID polyID)
#define LXxD_Subdivision_NumVertices int subdiv_NumVertices (void)
#define LXxO_Subdivision_NumVertices LXxD_Subdivision_NumVertices LXx_OVERRIDE
#define LXxC_Subdivision_NumVertices(c) int c::subdiv_NumVertices (void)
#define LXxD_Subdivision_NumLevelVertices int subdiv_NumLevelVertices (int level)
#define LXxO_Subdivision_NumLevelVertices LXxD_Subdivision_NumLevelVertices LXx_OVERRIDE
#define LXxC_Subdivision_NumLevelVertices(c) int c::subdiv_NumLevelVertices (int level)
#define LXxD_Subdivision_FirstVertexOffset int subdiv_FirstVertexOffset (int level)
#define LXxO_Subdivision_FirstVertexOffset LXxD_Subdivision_FirstVertexOffset LXx_OVERRIDE
#define LXxC_Subdivision_FirstVertexOffset(c) int c::subdiv_FirstVertexOffset (int level)
#define LXxD_Subdivision_ParentVertex int subdiv_ParentVertex (int vertIndex)
#define LXxO_Subdivision_ParentVertex LXxD_Subdivision_ParentVertex LXx_OVERRIDE
#define LXxC_Subdivision_ParentVertex(c) int c::subdiv_ParentVertex (int vertIndex)
#define LXxD_Subdivision_VertexPosition float * subdiv_VertexPosition (int vertIndex)
#define LXxO_Subdivision_VertexPosition LXxD_Subdivision_VertexPosition LXx_OVERRIDE
#define LXxC_Subdivision_VertexPosition(c) float * c::subdiv_VertexPosition (int vertIndex)
#define LXxD_Subdivision_VertexNormal float * subdiv_VertexNormal (int vertIndex)
#define LXxO_Subdivision_VertexNormal LXxD_Subdivision_VertexNormal LXx_OVERRIDE
#define LXxC_Subdivision_VertexNormal(c) float * c::subdiv_VertexNormal (int vertIndex)
#define LXxD_Subdivision_AddUVMap int subdiv_AddUVMap (const char *name)
#define LXxO_Subdivision_AddUVMap LXxD_Subdivision_AddUVMap LXx_OVERRIDE
#define LXxC_Subdivision_AddUVMap(c) int c::subdiv_AddUVMap (const char *name)
#define LXxD_Subdivision_NumUVMap int subdiv_NumUVMap (void)
#define LXxO_Subdivision_NumUVMap LXxD_Subdivision_NumUVMap LXx_OVERRIDE
#define LXxC_Subdivision_NumUVMap(c) int c::subdiv_NumUVMap (void)
#define LXxD_Subdivision_UVMapName const char * subdiv_UVMapName (int mapIndex)
#define LXxO_Subdivision_UVMapName LXxD_Subdivision_UVMapName LXx_OVERRIDE
#define LXxC_Subdivision_UVMapName(c) const char * c::subdiv_UVMapName (int mapIndex)
#define LXxD_Subdivision_LookupUVMap int subdiv_LookupUVMap (const char *name)
#define LXxO_Subdivision_LookupUVMap LXxD_Subdivision_LookupUVMap LXx_OVERRIDE
#define LXxC_Subdivision_LookupUVMap(c) int c::subdiv_LookupUVMap (const char *name)
#define LXxD_Subdivision_GetUV float * subdiv_GetUV (int mapIndex, int faceIndex, int vertOfFace)
#define LXxO_Subdivision_GetUV LXxD_Subdivision_GetUV LXx_OVERRIDE
#define LXxC_Subdivision_GetUV(c) float * c::subdiv_GetUV (int mapIndex, int faceIndex, int vertOfFace)
template <class T>
class CLxIfc_Subdivision : public CLxInterface
{
    static LxResult
  Validate (LXtObjectID wcom, LXtObjectID mesh)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    try {
      return loc->subdiv_Validate ((ILxUnknownID)mesh);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Refine (LXtObjectID wcom, LXtObjectID mesh)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    try {
      return loc->subdiv_Refine ((ILxUnknownID)mesh);
    } catch (LxResult rc) { return rc; }
  }
    static void
  InvalidateTopology (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    loc->subdiv_InvalidateTopology ();
  }
    static void
  InvalidatePosition (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    loc->subdiv_InvalidatePosition ();
  }
    static int
  Status (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_Status ();
  }
    static int
  MaxLevel (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_MaxLevel ();
  }
    static int
  SetMaxLevel (LXtObjectID wcom, int level)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_SetMaxLevel (level);
  }
    static int
  BoundaryRule (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_BoundaryRule ();
  }
    static int
  SetBoundaryRule (LXtObjectID wcom, int bound)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_SetBoundaryRule (bound);
  }
    static int
  UVBoundaryRule (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_UVBoundaryRule ();
  }
    static int
  SetUVBoundaryRule (LXtObjectID wcom, int bound)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_SetUVBoundaryRule (bound);
  }
    static int
  Scheme (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_Scheme ();
  }
    static int
  SetScheme (LXtObjectID wcom, int scheme)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_SetScheme (scheme);
  }
    static int
  Backend (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_Backend ();
  }
    static int
  SetBackend (LXtObjectID wcom, int backend)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_SetBackend (backend);
  }
    static int
  Adaptive (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_Adaptive ();
  }
    static int
  SetAdaptive (LXtObjectID wcom, int adaptive)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_SetAdaptive (adaptive);
  }
    static int
  NumFaces (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_NumFaces ();
  }
    static int
  FaceDepth (LXtObjectID wcom, int faceIndex)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_FaceDepth (faceIndex);
  }
    static int
  NumVerticesOfFace (LXtObjectID wcom, int faceIndex)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_NumVerticesOfFace (faceIndex);
  }
    static int
  VertexOfFace (LXtObjectID wcom, int faceIndex, int vertofface)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_VertexOfFace (faceIndex,vertofface);
  }
    static int
  NumLevelFaces (LXtObjectID wcom, int level)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_NumLevelFaces (level);
  }
    static int
  FirstFaceOffset (LXtObjectID wcom, int level)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_FirstFaceOffset (level);
  }
    static int
  ChildFace (LXtObjectID wcom, int faceIndex, int vertOfFace)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_ChildFace (faceIndex,vertOfFace);
  }
    static int
  ParentFace (LXtObjectID wcom, int faceIndex)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_ParentFace (faceIndex);
  }
    static LXtPolygonID
  PolygonID (LXtObjectID wcom, int faceIndex)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_PolygonID (faceIndex);
  }
    static int
  PolygonFace (LXtObjectID wcom, LXtPolygonID polyID)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_PolygonFace (polyID);
  }
    static int
  NumVertices (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_NumVertices ();
  }
    static int
  NumLevelVertices (LXtObjectID wcom, int level)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_NumLevelVertices (level);
  }
    static int
  FirstVertexOffset (LXtObjectID wcom, int level)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_FirstVertexOffset (level);
  }
    static int
  ParentVertex (LXtObjectID wcom, int vertIndex)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_ParentVertex (vertIndex);
  }
    static float *
  VertexPosition (LXtObjectID wcom, int vertIndex)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_VertexPosition (vertIndex);
  }
    static float *
  VertexNormal (LXtObjectID wcom, int vertIndex)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_VertexNormal (vertIndex);
  }
    static int
  AddUVMap (LXtObjectID wcom, const char *name)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_AddUVMap (name);
  }
    static int
  NumUVMap (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_NumUVMap ();
  }
    static const char *
  UVMapName (LXtObjectID wcom, int mapIndex)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_UVMapName (mapIndex);
  }
    static int
  LookupUVMap (LXtObjectID wcom, const char *name)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_LookupUVMap (name);
  }
    static float *
  GetUV (LXtObjectID wcom, int mapIndex, int faceIndex, int vertOfFace)
  {
    LXCWxINST (CLxImpl_Subdivision, loc);
    return loc->subdiv_GetUV (mapIndex,faceIndex,vertOfFace);
  }
  ILxSubdivision vt;
public:
  CLxIfc_Subdivision ()
  {
    vt.Validate = Validate;
    vt.Refine = Refine;
    vt.InvalidateTopology = InvalidateTopology;
    vt.InvalidatePosition = InvalidatePosition;
    vt.Status = Status;
    vt.MaxLevel = MaxLevel;
    vt.SetMaxLevel = SetMaxLevel;
    vt.BoundaryRule = BoundaryRule;
    vt.SetBoundaryRule = SetBoundaryRule;
    vt.UVBoundaryRule = UVBoundaryRule;
    vt.SetUVBoundaryRule = SetUVBoundaryRule;
    vt.Scheme = Scheme;
    vt.SetScheme = SetScheme;
    vt.Backend = Backend;
    vt.SetBackend = SetBackend;
    vt.Adaptive = Adaptive;
    vt.SetAdaptive = SetAdaptive;
    vt.NumFaces = NumFaces;
    vt.FaceDepth = FaceDepth;
    vt.NumVerticesOfFace = NumVerticesOfFace;
    vt.VertexOfFace = VertexOfFace;
    vt.NumLevelFaces = NumLevelFaces;
    vt.FirstFaceOffset = FirstFaceOffset;
    vt.ChildFace = ChildFace;
    vt.ParentFace = ParentFace;
    vt.PolygonID = PolygonID;
    vt.PolygonFace = PolygonFace;
    vt.NumVertices = NumVertices;
    vt.NumLevelVertices = NumLevelVertices;
    vt.FirstVertexOffset = FirstVertexOffset;
    vt.ParentVertex = ParentVertex;
    vt.VertexPosition = VertexPosition;
    vt.VertexNormal = VertexNormal;
    vt.AddUVMap = AddUVMap;
    vt.NumUVMap = NumUVMap;
    vt.UVMapName = UVMapName;
    vt.LookupUVMap = LookupUVMap;
    vt.GetUV = GetUV;
    vTable = &vt.iunk;
    iid = &lx::guid_Subdivision;
  }
};
class CLxLoc_Subdivision : public CLxLocalize<ILxSubdivisionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Subdivision() {_init();}
  CLxLoc_Subdivision(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Subdivision(const CLxLoc_Subdivision &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Subdivision;}
    LxResult
  Validate (ILxUnknownID mesh)
  {
    return m_loc[0]->Validate (m_loc,(ILxUnknownID)mesh);
  }
    LxResult
  Refine (ILxUnknownID mesh)
  {
    return m_loc[0]->Refine (m_loc,(ILxUnknownID)mesh);
  }
    void
  InvalidateTopology (void)
  {
    m_loc[0]->InvalidateTopology (m_loc);
  }
    void
  InvalidatePosition (void)
  {
    m_loc[0]->InvalidatePosition (m_loc);
  }
    int
  Status (void)
  {
    return m_loc[0]->Status (m_loc);
  }
    int
  MaxLevel (void)
  {
    return m_loc[0]->MaxLevel (m_loc);
  }
    int
  SetMaxLevel (int level)
  {
    return m_loc[0]->SetMaxLevel (m_loc,level);
  }
    int
  BoundaryRule (void)
  {
    return m_loc[0]->BoundaryRule (m_loc);
  }
    int
  SetBoundaryRule (int bound)
  {
    return m_loc[0]->SetBoundaryRule (m_loc,bound);
  }
    int
  UVBoundaryRule (void)
  {
    return m_loc[0]->UVBoundaryRule (m_loc);
  }
    int
  SetUVBoundaryRule (int bound)
  {
    return m_loc[0]->SetUVBoundaryRule (m_loc,bound);
  }
    int
  Scheme (void)
  {
    return m_loc[0]->Scheme (m_loc);
  }
    int
  SetScheme (int scheme)
  {
    return m_loc[0]->SetScheme (m_loc,scheme);
  }
    int
  Backend (void)
  {
    return m_loc[0]->Backend (m_loc);
  }
    int
  SetBackend (int backend)
  {
    return m_loc[0]->SetBackend (m_loc,backend);
  }
    int
  Adaptive (void)
  {
    return m_loc[0]->Adaptive (m_loc);
  }
    int
  SetAdaptive (int adaptive)
  {
    return m_loc[0]->SetAdaptive (m_loc,adaptive);
  }
    int
  NumFaces (void)
  {
    return m_loc[0]->NumFaces (m_loc);
  }
    int
  FaceDepth (int faceIndex)
  {
    return m_loc[0]->FaceDepth (m_loc,faceIndex);
  }
    int
  NumVerticesOfFace (int faceIndex)
  {
    return m_loc[0]->NumVerticesOfFace (m_loc,faceIndex);
  }
    int
  VertexOfFace (int faceIndex, int vertofface)
  {
    return m_loc[0]->VertexOfFace (m_loc,faceIndex,vertofface);
  }
    int
  NumLevelFaces (int level)
  {
    return m_loc[0]->NumLevelFaces (m_loc,level);
  }
    int
  FirstFaceOffset (int level)
  {
    return m_loc[0]->FirstFaceOffset (m_loc,level);
  }
    int
  ChildFace (int faceIndex, int vertOfFace)
  {
    return m_loc[0]->ChildFace (m_loc,faceIndex,vertOfFace);
  }
    int
  ParentFace (int faceIndex)
  {
    return m_loc[0]->ParentFace (m_loc,faceIndex);
  }
    LXtPolygonID
  PolygonID (int faceIndex)
  {
    return m_loc[0]->PolygonID (m_loc,faceIndex);
  }
    int
  PolygonFace (LXtPolygonID polyID)
  {
    return m_loc[0]->PolygonFace (m_loc,polyID);
  }
    int
  NumVertices (void)
  {
    return m_loc[0]->NumVertices (m_loc);
  }
    int
  NumLevelVertices (int level)
  {
    return m_loc[0]->NumLevelVertices (m_loc,level);
  }
    int
  FirstVertexOffset (int level)
  {
    return m_loc[0]->FirstVertexOffset (m_loc,level);
  }
    int
  ParentVertex (int vertIndex)
  {
    return m_loc[0]->ParentVertex (m_loc,vertIndex);
  }
    float *
  VertexPosition (int vertIndex)
  {
    return m_loc[0]->VertexPosition (m_loc,vertIndex);
  }
    float *
  VertexNormal (int vertIndex)
  {
    return m_loc[0]->VertexNormal (m_loc,vertIndex);
  }
    int
  AddUVMap (const char *name)
  {
    return m_loc[0]->AddUVMap (m_loc,name);
  }
    int
  NumUVMap (void)
  {
    return m_loc[0]->NumUVMap (m_loc);
  }
    const char *
  UVMapName (int mapIndex)
  {
    return m_loc[0]->UVMapName (m_loc,mapIndex);
  }
    int
  LookupUVMap (const char *name)
  {
    return m_loc[0]->LookupUVMap (m_loc,name);
  }
    float *
  GetUV (int mapIndex, int faceIndex, int vertOfFace)
  {
    return m_loc[0]->GetUV (m_loc,mapIndex,faceIndex,vertOfFace);
  }
};


#endif

