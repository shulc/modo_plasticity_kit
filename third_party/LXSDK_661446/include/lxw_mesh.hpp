/*
 * C++ wrapper for lxmesh.h
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
#ifndef LXW_MESH_HPP
#define LXW_MESH_HPP

#include <lxmesh.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_MeshListener = {0x9373A003,0xBEBC,0x44D4,0xAD,0xEB,0x36,0x86,0x2F,0x0A,0xFC,0x38};
    static const LXtGUID guid_MeshFilter = {0x9AA6236A,0xCF0F,0x4E72,0xB8,0xF3,0x20,0xBB,0xC5,0x53,0x2B,0x61};
    static const LXtGUID guid_MeshOperation2 = {0x71D124CB,0x8D2A,0x4E5A,0x81,0x4D,0x39,0x21,0xD9,0x98,0x6D,0x3A};
    static const LXtGUID guid_MeshBlend = {0xE4690A09,0x96B9,0x40CB,0xB2,0x64,0xAB,0x90,0x0B,0xF1,0xD9,0x89};
    static const LXtGUID guid_Point = {0x37B477FE,0xED3C,0x4EDC,0xA4,0xA8,0x9B,0xB2,0x4F,0x58,0xA4,0xE6};
    static const LXtGUID guid_Polygon = {0xDD64141D,0xDC92,0x4348,0xB4,0x5B,0xF7,0x3F,0xC6,0x4F,0x1E,0x52};
    static const LXtGUID guid_MeshMetaData = {0x2C6633EE,0xBFB0,0x41B5,0xBB,0x36,0x2B,0x1E,0xBE,0x31,0x0D,0x3E};
    static const LXtGUID guid_MeshFilterBBox = {0xFBD83166,0x4B50,0x42A0,0x8C,0x91,0xC3,0x6D,0x3B,0xB7,0x69,0x04};
    static const LXtGUID guid_MeshTracker = {0x8FAD284F,0xC289,0x40AB,0x97,0xD2,0x63,0x93,0x23,0x85,0xBA,0xB6};
    static const LXtGUID guid_MeshFilterBlend = {0x590F4482,0x3EDE,0x47DB,0xA2,0x60,0x65,0x1B,0x68,0x7D,0x2B,0x1E};
    static const LXtGUID guid_MeshFilter1 = {0xF5896BA1,0x7EC5,0x4EE9,0x85,0x2F,0xBF,0x97,0x7E,0x45,0x19,0x53};
    static const LXtGUID guid_Polygon1 = {0x5839056D,0x28BF,0x4D72,0x8A,0x26,0xE4,0xAA,0x00,0xDA,0x78,0x8F};
    static const LXtGUID guid_Mesh1 = {0xA9E30646,0xD729,0x4850,0xB4,0xC4,0xF0,0x0A,0x5E,0x93,0xFE,0x25};
    static const LXtGUID guid_MeshOperation = {0x8B72A28C,0x6C2C,0x4E9C,0x82,0x42,0x7D,0x13,0xAE,0x80,0x00,0x8E};
    static const LXtGUID guid_Edge = {0x19A44432,0xE2CF,0x4BCF,0x9E,0xA6,0xD6,0x96,0xE7,0xA0,0xF1,0x6E};
    static const LXtGUID guid_MeshService = {0x82B739EC,0xF92E,0x4CC9,0xA5,0xFB,0x58,0x4A,0x86,0x6D,0x58,0x97};
    static const LXtGUID guid_MeshXtraData = {0xA9CC9F05,0xAB4F,0x45AD,0xAE,0xB0,0xF3,0xA2,0xD1,0xF6,0x6A,0x98};
    static const LXtGUID guid_Mesh = {0x8C7F1CF3,0x8CE8,0x4395,0x93,0x24,0xA1,0x6D,0xD6,0x3B,0x4A,0xFE};
    static const LXtGUID guid_Mesh2 = {0x1F1BB7BF,0xA862,0x4810,0x95,0xFF,0x33,0x46,0xAF,0x73,0x82,0x09};
    static const LXtGUID guid_MeshListener1 = {0x957900AC,0xBC06,0x45D9,0xB1,0xB1,0x9C,0xC5,0xA2,0xAE,0xC0,0x26};
    static const LXtGUID guid_MeshOperation1 = {0x98103095,0x54AC,0x45CD,0x86,0x85,0x84,0x61,0x4D,0x99,0x6A,0xC2};
    static const LXtGUID guid_MeshFilterIdent = {0x68713DE3,0x45D8,0x4722,0xBC,0x43,0xD0,0x3E,0xF4,0x96,0x4A,0xB8};
    static const LXtGUID guid_MeshMap = {0x2AEBA454,0x2AC4,0x4F1E,0xB8,0x92,0x7A,0x16,0xF7,0x60,0x10,0x30};
};

class CLxImpl_MeshListener {
  public:
    virtual ~CLxImpl_MeshListener() {}
    virtual void
      ml_Destroy (void)
        { }
    virtual void
      ml_Changes (unsigned event)
        { }
};
#define LXxD_MeshListener_Destroy void ml_Destroy (void)
#define LXxO_MeshListener_Destroy LXxD_MeshListener_Destroy LXx_OVERRIDE
#define LXxC_MeshListener_Destroy(c) void c::ml_Destroy (void)
#define LXxD_MeshListener_Changes void ml_Changes (unsigned event)
#define LXxO_MeshListener_Changes LXxD_MeshListener_Changes LXx_OVERRIDE
#define LXxC_MeshListener_Changes(c) void c::ml_Changes (unsigned event)
template <class T>
class CLxIfc_MeshListener : public CLxInterface
{
    static void
  Destroy (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_MeshListener, loc);
    loc->ml_Destroy ();
  }
    static void
  Changes (LXtObjectID wcom, unsigned event)
  {
    LXCWxINST (CLxImpl_MeshListener, loc);
    loc->ml_Changes (event);
  }
  ILxMeshListener vt;
public:
  CLxIfc_MeshListener ()
  {
    vt.Destroy = Destroy;
    vt.Changes = Changes;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshListener;
  }
};

class CLxImpl_MeshFilter {
  public:
    virtual ~CLxImpl_MeshFilter() {}
    virtual unsigned
      mfilt_Type (void)
        = 0;
    virtual LxResult
      mfilt_Evaluate (ILxUnknownID mesh, ILxUnknownID tracker)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mfilt_Generate (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_MeshFilter_Type unsigned mfilt_Type (void)
#define LXxO_MeshFilter_Type LXxD_MeshFilter_Type LXx_OVERRIDE
#define LXxC_MeshFilter_Type(c) unsigned c::mfilt_Type (void)
#define LXxD_MeshFilter_Evaluate LxResult mfilt_Evaluate (ILxUnknownID mesh, ILxUnknownID tracker)
#define LXxO_MeshFilter_Evaluate LXxD_MeshFilter_Evaluate LXx_OVERRIDE
#define LXxC_MeshFilter_Evaluate(c) LxResult c::mfilt_Evaluate (ILxUnknownID mesh, ILxUnknownID tracker)
#define LXxD_MeshFilter_Generate LxResult mfilt_Generate (void **ppvObj)
#define LXxO_MeshFilter_Generate LXxD_MeshFilter_Generate LXx_OVERRIDE
#define LXxC_MeshFilter_Generate(c) LxResult c::mfilt_Generate (void **ppvObj)
template <class T>
class CLxIfc_MeshFilter : public CLxInterface
{
    static unsigned
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_MeshFilter, loc);
    return loc->mfilt_Type ();
  }
    static LxResult
  Evaluate (LXtObjectID wcom, LXtObjectID mesh, LXtObjectID tracker)
  {
    LXCWxINST (CLxImpl_MeshFilter, loc);
    try {
      return loc->mfilt_Evaluate ((ILxUnknownID)mesh,(ILxUnknownID)tracker);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Generate (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_MeshFilter, loc);
    try {
      return loc->mfilt_Generate (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxMeshFilter vt;
public:
  CLxIfc_MeshFilter ()
  {
    vt.Type = Type;
    vt.Evaluate = Evaluate;
    vt.Generate = Generate;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshFilter;
  }
};
class CLxLoc_MeshFilter : public CLxLocalize<ILxMeshFilterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshFilter() {_init();}
  CLxLoc_MeshFilter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshFilter(const CLxLoc_MeshFilter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshFilter;}
    unsigned
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  Evaluate (ILxUnknownID mesh, ILxUnknownID tracker)
  {
    return m_loc[0]->Evaluate (m_loc,(ILxUnknownID)mesh,(ILxUnknownID)tracker);
  }
    LxResult
  Generate (void **ppvObj)
  {
    return m_loc[0]->Generate (m_loc,ppvObj);
  }
    CLxResult
  Generate (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Generate(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};


class CLxLoc_MeshBlend : public CLxLocalize<ILxMeshBlendID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshBlend() {_init();}
  CLxLoc_MeshBlend(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshBlend(const CLxLoc_MeshBlend &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshBlend;}
    LxResult
  BlendMesh (double t, void **ppvObj)
  {
    return m_loc[0]->BlendMesh (m_loc,t,ppvObj);
  }
    CLxResult
  BlendMesh (double t, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->BlendMesh(m_loc,t,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SourceMesh (void **ppvObj)
  {
    return m_loc[0]->SourceMesh (m_loc,ppvObj);
  }
    CLxResult
  SourceMesh (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SourceMesh(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  TargetMesh (void **ppvObj)
  {
    return m_loc[0]->TargetMesh (m_loc,ppvObj);
  }
    CLxResult
  TargetMesh (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->TargetMesh(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetPoint (LXtPointID source, LXtPointID *target)
  {
    return m_loc[0]->GetPoint (m_loc,source,target);
  }
    LxResult
  GetPolygon (LXtPolygonID source, LXtPolygonID *target)
  {
    return m_loc[0]->GetPolygon (m_loc,source,target);
  }
    LxResult
  SetPoint (LXtPointID source, LXtPointID target)
  {
    return m_loc[0]->SetPoint (m_loc,source,target);
  }
    LxResult
  SetPolygon (LXtPolygonID source, LXtPolygonID target)
  {
    return m_loc[0]->SetPolygon (m_loc,source,target);
  }
    LxResult
  EnumeratePoints (ILxUnknownID source, ILxUnknownID target, ILxUnknownID visitor)
  {
    return m_loc[0]->EnumeratePoints (m_loc,(ILxUnknownID)source,(ILxUnknownID)target,(ILxUnknownID)visitor);
  }
    LxResult
  EnumeratePolygons (ILxUnknownID source, ILxUnknownID target, ILxUnknownID visitor)
  {
    return m_loc[0]->EnumeratePolygons (m_loc,(ILxUnknownID)source,(ILxUnknownID)target,(ILxUnknownID)visitor);
  }
};

class CLxLoc_Point : public CLxLocalize<ILxPointID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Point() {_init();}
  CLxLoc_Point(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Point(const CLxLoc_Point &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Point;}
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    CLxResult
  Spawn (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Spawn(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Enumerate (LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor)
  {
    return m_loc[0]->Enumerate (m_loc,mode,(ILxUnknownID)visitor,(ILxUnknownID)monitor);
  }
    LxResult
  TestMarks (LXtMarkMode mode)
  {
    return m_loc[0]->TestMarks (m_loc,mode);
  }
    LxResult
  SetMarks (LXtMarkMode set)
  {
    return m_loc[0]->SetMarks (m_loc,set);
  }
    LxResult
  Select (LXtPointID point)
  {
    return m_loc[0]->Select (m_loc,point);
  }
    LxResult
  SelectByIndex (unsigned int index)
  {
    return m_loc[0]->SelectByIndex (m_loc,index);
  }
    LxResult
  SelectPolygonVertex (LXtPolygonID polygon, unsigned int index)
  {
    return m_loc[0]->SelectPolygonVertex (m_loc,polygon,index);
  }
    LXtPointID
  ID (void)
  {
    return m_loc[0]->ID (m_loc);
  }
    LxResult
  Index (unsigned int *index)
  {
    return m_loc[0]->Index (m_loc,index);
  }
    LxResult
  Pos (LXtFVector pos)
  {
    return m_loc[0]->Pos (m_loc,pos);
  }
    LxResult
  Normal (LXtPolygonID pol, LXtVector normal)
  {
    return m_loc[0]->Normal (m_loc,pol,normal);
  }
    LxResult
  MapValue (LXtMeshMapID map, float *value)
  {
    return m_loc[0]->MapValue (m_loc,map,value);
  }
    LxResult
  MapEvaluate (LXtMeshMapID map, float *value)
  {
    return m_loc[0]->MapEvaluate (m_loc,map,value);
  }
    LxResult
  PolygonCount (unsigned int *count)
  {
    return m_loc[0]->PolygonCount (m_loc,count);
  }
    LxResult
  PolygonByIndex (unsigned int index, LXtPolygonID *polygonID)
  {
    return m_loc[0]->PolygonByIndex (m_loc,index,polygonID);
  }
    LxResult
  New (const LXtVector pos, LXtPointID *pointID)
  {
    return m_loc[0]->New (m_loc,pos,pointID);
  }
    LxResult
  Copy (LXtPointID *pointID)
  {
    return m_loc[0]->Copy (m_loc,pointID);
  }
    LxResult
  Remove (void)
  {
    return m_loc[0]->Remove (m_loc);
  }
    LxResult
  SetPos (const LXtVector pos)
  {
    return m_loc[0]->SetPos (m_loc,pos);
  }
    LxResult
  SetMapValue (LXtMeshMapID map, const float *value)
  {
    return m_loc[0]->SetMapValue (m_loc,map,value);
  }
    LxResult
  ClearMapValue (LXtMeshMapID map)
  {
    return m_loc[0]->ClearMapValue (m_loc,map);
  }
    LxResult
  Corner (LXtFVector pos)
  {
    return m_loc[0]->Corner (m_loc,pos);
  }
    LxResult
  PointCount (unsigned int *count)
  {
    return m_loc[0]->PointCount (m_loc,count);
  }
    LxResult
  PointByIndex (unsigned int index, LXtPointID *pointID)
  {
    return m_loc[0]->PointByIndex (m_loc,index,pointID);
  }
    LxResult
  EdgeCount (unsigned int *count)
  {
    return m_loc[0]->EdgeCount (m_loc,count);
  }
    LxResult
  EdgeByIndex (unsigned int index, LXtEdgeID *edgeID)
  {
    return m_loc[0]->EdgeByIndex (m_loc,index,edgeID);
  }
    LxResult
  Symmetry (LXtPointID *pointID)
  {
    return m_loc[0]->Symmetry (m_loc,pointID);
  }
    LxResult
  OnSymmetryCenter (void)
  {
    return m_loc[0]->OnSymmetryCenter (m_loc);
  }
    LxResult
  Mesh (void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,ppvObj);
  }
    CLxResult
  Mesh (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Mesh(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Part (unsigned int *part)
  {
    return m_loc[0]->Part (m_loc,part);
  }
    LxResult
  NewOnEdge (LXtPointID A, LXtPointID B, float percent, LXtPointID *newPoint)
  {
    return m_loc[0]->NewOnEdge (m_loc,A,B,percent,newPoint);
  }
};

class CLxLoc_Polygon : public CLxLocalize<ILxPolygonID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Polygon() {_init();}
  CLxLoc_Polygon(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Polygon(const CLxLoc_Polygon &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Polygon;}
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    CLxResult
  Spawn (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Spawn(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Enumerate (LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor)
  {
    return m_loc[0]->Enumerate (m_loc,mode,(ILxUnknownID)visitor,(ILxUnknownID)monitor);
  }
    LxResult
  TestMarks (LXtMarkMode mode)
  {
    return m_loc[0]->TestMarks (m_loc,mode);
  }
    LxResult
  SetMarks (LXtMarkMode set)
  {
    return m_loc[0]->SetMarks (m_loc,set);
  }
    LxResult
  Select (LXtPolygonID polygon)
  {
    return m_loc[0]->Select (m_loc,polygon);
  }
    LxResult
  SelectByIndex (unsigned int index)
  {
    return m_loc[0]->SelectByIndex (m_loc,index);
  }
    LXtPolygonID
  ID (void)
  {
    return m_loc[0]->ID (m_loc);
  }
    LxResult
  Index (int *index)
  {
    return m_loc[0]->Index (m_loc,index);
  }
    LxResult
  Type (LXtID4 *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  VertexCount (unsigned int *count)
  {
    return m_loc[0]->VertexCount (m_loc,count);
  }
    LxResult
  VertexByIndex (unsigned int index, LXtPointID *point)
  {
    return m_loc[0]->VertexByIndex (m_loc,index,point);
  }
    LxResult
  FirstIsControlEndpoint (void)
  {
    return m_loc[0]->FirstIsControlEndpoint (m_loc);
  }
    LxResult
  LastIsControlEndpoint (void)
  {
    return m_loc[0]->LastIsControlEndpoint (m_loc);
  }
    LxResult
  Normal (LXtVector normal)
  {
    return m_loc[0]->Normal (m_loc,normal);
  }
    LxResult
  MapValue (LXtMeshMapID map, LXtPointID point, float *value)
  {
    return m_loc[0]->MapValue (m_loc,map,point,value);
  }
    LxResult
  MapEvaluate (LXtMeshMapID map, LXtPointID point, float *value)
  {
    return m_loc[0]->MapEvaluate (m_loc,map,point,value);
  }
    LxResult
  Area (double *area)
  {
    return m_loc[0]->Area (m_loc,area);
  }
    LxResult
  New (LXtID4 type, const LXtPointID *vertices, unsigned int numVert, unsigned int rev, LXtPolygonID *polygonID)
  {
    return m_loc[0]->New (m_loc,type,vertices,numVert,rev,polygonID);
  }
    LxResult
  NewProto (LXtID4 type, const LXtPointID *vertices, unsigned int numVert, unsigned int rev, LXtPolygonID *polygonID)
  {
    return m_loc[0]->NewProto (m_loc,type,vertices,numVert,rev,polygonID);
  }
    LxResult
  Remove (void)
  {
    return m_loc[0]->Remove (m_loc);
  }
    LxResult
  SetFirstIsControlEndpoint (int state)
  {
    return m_loc[0]->SetFirstIsControlEndpoint (m_loc,state);
  }
    LxResult
  SetLastIsControlEndpoint (int state)
  {
    return m_loc[0]->SetLastIsControlEndpoint (m_loc,state);
  }
    LxResult
  SetVertexList (const LXtPointID *vertices, unsigned int numVert, unsigned int rev)
  {
    return m_loc[0]->SetVertexList (m_loc,vertices,numVert,rev);
  }
    LxResult
  SetMapValue (LXtPointID point, LXtMeshMapID map, const float *value)
  {
    return m_loc[0]->SetMapValue (m_loc,point,map,value);
  }
    LxResult
  ClearMapValue (LXtPointID point, LXtMeshMapID map)
  {
    return m_loc[0]->ClearMapValue (m_loc,point,map);
  }
    LxResult
  StartContour (void)
  {
    return m_loc[0]->StartContour (m_loc);
  }
    LxResult
  AddContourEdge (LXtPointID startPt, LXtPointID endPt)
  {
    return m_loc[0]->AddContourEdge (m_loc,startPt,endPt);
  }
    LxResult
  GenerateContour (LXtID4 type, LXtPolygonID *polygonID)
  {
    return m_loc[0]->GenerateContour (m_loc,type,polygonID);
  }
    LxResult
  GenerateContourProto (LXtPolygonID *polygonID)
  {
    return m_loc[0]->GenerateContourProto (m_loc,polygonID);
  }
    LxResult
  IntersectRay (const LXtVector pos, const LXtVector dir, LXtVector hitNorm, double *hitDist)
  {
    return m_loc[0]->IntersectRay (m_loc,pos,dir,hitNorm,hitDist);
  }
    LxResult
  Closest (double maxDist, const LXtVector pos, LXtVector hitPos, LXtVector hitNorm, double *hitDist)
  {
    return m_loc[0]->Closest (m_loc,maxDist,pos,hitPos,hitNorm,hitDist);
  }
    LxResult
  PointIndex (LXtPointID pointID, unsigned int *index)
  {
    return m_loc[0]->PointIndex (m_loc,pointID,index);
  }
    LxResult
  EdgeIndex (LXtEdgeID edgeID, unsigned int *index)
  {
    return m_loc[0]->EdgeIndex (m_loc,edgeID,index);
  }
    LxResult
  SharedEdge (LXtPolygonID polygonID, LXtEdgeID *edgeID)
  {
    return m_loc[0]->SharedEdge (m_loc,polygonID,edgeID);
  }
    LxResult
  IsBorder (void)
  {
    return m_loc[0]->IsBorder (m_loc);
  }
    LxResult
  RepresentativePosition (LXtVector pos)
  {
    return m_loc[0]->RepresentativePosition (m_loc,pos);
  }
    LxResult
  GoodPoint (const LXtPointID *points, unsigned int nPoints, unsigned int *index)
  {
    return m_loc[0]->GoodPoint (m_loc,points,nPoints,index);
  }
    LxResult
  GenerateTriangles (unsigned int *count)
  {
    return m_loc[0]->GenerateTriangles (m_loc,count);
  }
    LxResult
  TriangleByIndex (unsigned index, LXtPointID *point0, LXtPointID *point1, LXtPointID *point2)
  {
    return m_loc[0]->TriangleByIndex (m_loc,index,point0,point1,point2);
  }
    LxResult
  ClearTriangles (void)
  {
    return m_loc[0]->ClearTriangles (m_loc);
  }
    LxResult
  EnumerateBBox (LXtMarkMode mode, ILxUnknownID visitor, const LXtVector min, const LXtVector max)
  {
    return m_loc[0]->EnumerateBBox (m_loc,mode,(ILxUnknownID)visitor,min,max);
  }
    LxResult
  EnumerateRay (LXtMarkMode mode, ILxUnknownID visitor, const LXtVector org, const LXtVector ray)
  {
    return m_loc[0]->EnumerateRay (m_loc,mode,(ILxUnknownID)visitor,org,ray);
  }
    LxResult
  EnumerateLine (LXtMarkMode mode, ILxUnknownID visitor, const LXtVector org, const LXtVector dir)
  {
    return m_loc[0]->EnumerateLine (m_loc,mode,(ILxUnknownID)visitor,org,dir);
  }
    LxResult
  NewCurveFill (const LXtPolygonID *polygons, unsigned int numPols, LXtPolygonID *polygonID)
  {
    return m_loc[0]->NewCurveFill (m_loc,polygons,numPols,polygonID);
  }
    LxResult
  Symmetry (LXtPolygonID *polygonID)
  {
    return m_loc[0]->Symmetry (m_loc,polygonID);
  }
    LxResult
  UVLookup (const char *vMapName, const LXtVector2 uv, LXtVector surfacePosition, LXtVector surfaceNormal, LXtVector surfaceDPDU, LXtVector surfaceDPDV)
  {
    return m_loc[0]->UVLookup (m_loc,vMapName,uv,surfacePosition,surfaceNormal,surfaceDPDU,surfaceDPDV);
  }
    LxResult
  EnumerateByUV (LXtMarkMode mode, const char *vMapName, int quality, const LXtVector2 uv, ILxUnknownID visitor)
  {
    return m_loc[0]->EnumerateByUV (m_loc,mode,vMapName,quality,uv,(ILxUnknownID)visitor);
  }
    LxResult
  EnumerateBin (LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID bin)
  {
    return m_loc[0]->EnumerateBin (m_loc,mode,(ILxUnknownID)visitor,(ILxUnknownID)bin);
  }
    LxResult
  Mesh (void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,ppvObj);
  }
    CLxResult
  Mesh (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Mesh(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  EnumerateByPTag (LXtMarkMode mode, LXtID4 type, const char *tag, ILxUnknownID visitor)
  {
    return m_loc[0]->EnumerateByPTag (m_loc,mode,type,tag,(ILxUnknownID)visitor);
  }
    LxResult
  Part (unsigned int *part)
  {
    return m_loc[0]->Part (m_loc,part);
  }
    LxResult
  UVPart (LXtMeshMapID map, unsigned int *part)
  {
    return m_loc[0]->UVPart (m_loc,map,part);
  }
    LxResult
  Tessellate (unsigned int flags, LXtPolyMeshInfo *info)
  {
    return m_loc[0]->Tessellate (m_loc,flags,info);
  }
};

class CLxImpl_MeshMetaData {
  public:
    virtual ~CLxImpl_MeshMetaData() {}
    virtual LxResult
      meta_Validate (ILxUnknownID mesh, ILxUnknownID xtra, unsigned int change)
        { return LXe_NOTIMPL; }
    virtual void
      meta_FreePointData (void *data)
        { }
    virtual void
      meta_FreePolygonData (void *data)
        { }
};
#define LXxD_MeshMetaData_Validate LxResult meta_Validate (ILxUnknownID mesh, ILxUnknownID xtra, unsigned int change)
#define LXxO_MeshMetaData_Validate LXxD_MeshMetaData_Validate LXx_OVERRIDE
#define LXxC_MeshMetaData_Validate(c) LxResult c::meta_Validate (ILxUnknownID mesh, ILxUnknownID xtra, unsigned int change)
#define LXxD_MeshMetaData_FreePointData void meta_FreePointData (void *data)
#define LXxO_MeshMetaData_FreePointData LXxD_MeshMetaData_FreePointData LXx_OVERRIDE
#define LXxC_MeshMetaData_FreePointData(c) void c::meta_FreePointData (void *data)
#define LXxD_MeshMetaData_FreePolygonData void meta_FreePolygonData (void *data)
#define LXxO_MeshMetaData_FreePolygonData LXxD_MeshMetaData_FreePolygonData LXx_OVERRIDE
#define LXxC_MeshMetaData_FreePolygonData(c) void c::meta_FreePolygonData (void *data)
template <class T>
class CLxIfc_MeshMetaData : public CLxInterface
{
    static LxResult
  Validate (LXtObjectID wcom, LXtObjectID mesh, LXtObjectID xtra, unsigned int change)
  {
    LXCWxINST (CLxImpl_MeshMetaData, loc);
    try {
      return loc->meta_Validate ((ILxUnknownID)mesh,(ILxUnknownID)xtra,change);
    } catch (LxResult rc) { return rc; }
  }
    static void
  FreePointData (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_MeshMetaData, loc);
    loc->meta_FreePointData (data);
  }
    static void
  FreePolygonData (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_MeshMetaData, loc);
    loc->meta_FreePolygonData (data);
  }
  ILxMeshMetaData vt;
public:
  CLxIfc_MeshMetaData ()
  {
    vt.Validate = Validate;
    vt.FreePointData = FreePointData;
    vt.FreePolygonData = FreePolygonData;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshMetaData;
  }
};

class CLxImpl_MeshFilterBBox {
  public:
    virtual ~CLxImpl_MeshFilterBBox() {}
    virtual LxResult
      mfbbox_Evaluate (LXtBBox *box)
        { return LXe_NOTIMPL; }
};
#define LXxD_MeshFilterBBox_Evaluate LxResult mfbbox_Evaluate (LXtBBox *box)
#define LXxO_MeshFilterBBox_Evaluate LXxD_MeshFilterBBox_Evaluate LXx_OVERRIDE
#define LXxC_MeshFilterBBox_Evaluate(c) LxResult c::mfbbox_Evaluate (LXtBBox *box)
template <class T>
class CLxIfc_MeshFilterBBox : public CLxInterface
{
    static LxResult
  Evaluate (LXtObjectID wcom, LXtBBox *box)
  {
    LXCWxINST (CLxImpl_MeshFilterBBox, loc);
    try {
      return loc->mfbbox_Evaluate (box);
    } catch (LxResult rc) { return rc; }
  }
  ILxMeshFilterBBox vt;
public:
  CLxIfc_MeshFilterBBox ()
  {
    vt.Evaluate = Evaluate;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshFilterBBox;
  }
};
class CLxLoc_MeshFilterBBox : public CLxLocalize<ILxMeshFilterBBoxID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshFilterBBox() {_init();}
  CLxLoc_MeshFilterBBox(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshFilterBBox(const CLxLoc_MeshFilterBBox &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshFilterBBox;}
    LxResult
  Evaluate (LXtBBox *box)
  {
    return m_loc[0]->Evaluate (m_loc,box);
  }
};

class CLxLoc_MeshTracker : public CLxLocalize<ILxMeshTrackerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshTracker() {_init();}
  CLxLoc_MeshTracker(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshTracker(const CLxLoc_MeshTracker &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshTracker;}
    LxResult
  Start (void)
  {
    return m_loc[0]->Start (m_loc);
  }
    LxResult
  Stop (void)
  {
    return m_loc[0]->Stop (m_loc);
  }
    LxResult
  Active (void)
  {
    return m_loc[0]->Active (m_loc);
  }
    LxResult
  Reset (void)
  {
    return m_loc[0]->Reset (m_loc);
  }
    LxResult
  Changes (unsigned int *edit)
  {
    return m_loc[0]->Changes (m_loc,edit);
  }
    LxResult
  Mesh (void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,ppvObj);
  }
    CLxResult
  Mesh (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Mesh(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  EnumeratePoints (unsigned int change, ILxUnknownID visitor, ILxUnknownID point)
  {
    return m_loc[0]->EnumeratePoints (m_loc,change,(ILxUnknownID)visitor,(ILxUnknownID)point);
  }
    LxResult
  EnumeratePolygons (unsigned int change, ILxUnknownID visitor, ILxUnknownID poly)
  {
    return m_loc[0]->EnumeratePolygons (m_loc,change,(ILxUnknownID)visitor,(ILxUnknownID)poly);
  }
    LxResult
  SetChange (unsigned int change)
  {
    return m_loc[0]->SetChange (m_loc,change);
  }
    LxResult
  AddPoint (LXtPointID point, unsigned int change)
  {
    return m_loc[0]->AddPoint (m_loc,point,change);
  }
    LxResult
  AddPolygon (LXtPolygonID poly, unsigned int change)
  {
    return m_loc[0]->AddPolygon (m_loc,poly,change);
  }
    LxResult
  SetFilter (unsigned int filter)
  {
    return m_loc[0]->SetFilter (m_loc,filter);
  }
    LxResult
  Filter (unsigned int *filter)
  {
    return m_loc[0]->Filter (m_loc,filter);
  }
};

class CLxLoc_MeshFilterBlend : public CLxLocalize<ILxMeshFilterBlendID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshFilterBlend() {_init();}
  CLxLoc_MeshFilterBlend(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshFilterBlend(const CLxLoc_MeshFilterBlend &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshFilterBlend;}
    LxResult
  Generate (ILxUnknownID other, void **ppvObj)
  {
    return m_loc[0]->Generate (m_loc,(ILxUnknownID)other,ppvObj);
  }
    CLxResult
  Generate (ILxUnknownID other, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Generate(m_loc,(ILxUnknownID)other,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Evaluate (ILxUnknownID other, ILxUnknownID blend)
  {
    return m_loc[0]->Evaluate (m_loc,(ILxUnknownID)other,(ILxUnknownID)blend);
  }
};




class CLxImpl_MeshOperation {
  public:
    virtual ~CLxImpl_MeshOperation() {}
    virtual LxResult
      mop_Evaluate (ILxUnknownID mesh, LXtID4 type, LXtMarkMode mode)
        { return LXe_NOTIMPL; }
    virtual int
      mop_Compare (ILxUnknownID other)
        { return LXiMESHOP_DIFFERENT; }
    virtual LxResult
      mop_Convert (ILxUnknownID other)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mop_ReEvaluate (ILxUnknownID mesh, LXtID4 type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mop_SetTransform (const LXtMatrix4 matrix)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mop_Blend (ILxUnknownID other, ILxUnknownID blend)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mop_Clone (ILxUnknownID target, ILxUnknownID source, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_MeshOperation_Evaluate LxResult mop_Evaluate (ILxUnknownID mesh, LXtID4 type, LXtMarkMode mode)
#define LXxO_MeshOperation_Evaluate LXxD_MeshOperation_Evaluate LXx_OVERRIDE
#define LXxC_MeshOperation_Evaluate(c) LxResult c::mop_Evaluate (ILxUnknownID mesh, LXtID4 type, LXtMarkMode mode)
#define LXxD_MeshOperation_Compare int mop_Compare (ILxUnknownID other)
#define LXxO_MeshOperation_Compare LXxD_MeshOperation_Compare LXx_OVERRIDE
#define LXxC_MeshOperation_Compare(c) int c::mop_Compare (ILxUnknownID other)
#define LXxD_MeshOperation_Convert LxResult mop_Convert (ILxUnknownID other)
#define LXxO_MeshOperation_Convert LXxD_MeshOperation_Convert LXx_OVERRIDE
#define LXxC_MeshOperation_Convert(c) LxResult c::mop_Convert (ILxUnknownID other)
#define LXxD_MeshOperation_ReEvaluate LxResult mop_ReEvaluate (ILxUnknownID mesh, LXtID4 type)
#define LXxO_MeshOperation_ReEvaluate LXxD_MeshOperation_ReEvaluate LXx_OVERRIDE
#define LXxC_MeshOperation_ReEvaluate(c) LxResult c::mop_ReEvaluate (ILxUnknownID mesh, LXtID4 type)
#define LXxD_MeshOperation_SetTransform LxResult mop_SetTransform (const LXtMatrix4 matrix)
#define LXxO_MeshOperation_SetTransform LXxD_MeshOperation_SetTransform LXx_OVERRIDE
#define LXxC_MeshOperation_SetTransform(c) LxResult c::mop_SetTransform (const LXtMatrix4 matrix)
#define LXxD_MeshOperation_Blend LxResult mop_Blend (ILxUnknownID other, ILxUnknownID blend)
#define LXxO_MeshOperation_Blend LXxD_MeshOperation_Blend LXx_OVERRIDE
#define LXxC_MeshOperation_Blend(c) LxResult c::mop_Blend (ILxUnknownID other, ILxUnknownID blend)
#define LXxD_MeshOperation_Clone LxResult mop_Clone (ILxUnknownID target, ILxUnknownID source, void **ppvObj)
#define LXxO_MeshOperation_Clone LXxD_MeshOperation_Clone LXx_OVERRIDE
#define LXxC_MeshOperation_Clone(c) LxResult c::mop_Clone (ILxUnknownID target, ILxUnknownID source, void **ppvObj)
template <class T>
class CLxIfc_MeshOperation : public CLxInterface
{
    static LxResult
  Evaluate (LXtObjectID wcom, LXtObjectID mesh, LXtID4 type, LXtMarkMode mode)
  {
    LXCWxINST (CLxImpl_MeshOperation, loc);
    try {
      return loc->mop_Evaluate ((ILxUnknownID)mesh,type,mode);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Compare (LXtObjectID wcom, LXtObjectID other)
  {
    LXCWxINST (CLxImpl_MeshOperation, loc);
    return loc->mop_Compare ((ILxUnknownID)other);
  }
    static LxResult
  Convert (LXtObjectID wcom, LXtObjectID other)
  {
    LXCWxINST (CLxImpl_MeshOperation, loc);
    try {
      return loc->mop_Convert ((ILxUnknownID)other);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReEvaluate (LXtObjectID wcom, LXtObjectID mesh, LXtID4 type)
  {
    LXCWxINST (CLxImpl_MeshOperation, loc);
    try {
      return loc->mop_ReEvaluate ((ILxUnknownID)mesh,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetTransform (LXtObjectID wcom, const LXtMatrix4 matrix)
  {
    LXCWxINST (CLxImpl_MeshOperation, loc);
    try {
      return loc->mop_SetTransform (matrix);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Blend (LXtObjectID wcom, LXtObjectID other, LXtObjectID blend)
  {
    LXCWxINST (CLxImpl_MeshOperation, loc);
    try {
      return loc->mop_Blend ((ILxUnknownID)other,(ILxUnknownID)blend);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Clone (LXtObjectID wcom, LXtObjectID target, LXtObjectID source, void **ppvObj)
  {
    LXCWxINST (CLxImpl_MeshOperation, loc);
    try {
      return loc->mop_Clone ((ILxUnknownID)target,(ILxUnknownID)source,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxMeshOperation vt;
public:
  CLxIfc_MeshOperation ()
  {
    vt.Evaluate = Evaluate;
    vt.Compare = Compare;
    vt.Convert = Convert;
    vt.ReEvaluate = ReEvaluate;
    vt.SetTransform = SetTransform;
    vt.Blend = Blend;
    vt.Clone = Clone;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshOperation;
  }
};
class CLxLoc_MeshOperation : public CLxLocalize<ILxMeshOperationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshOperation() {_init();}
  CLxLoc_MeshOperation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshOperation(const CLxLoc_MeshOperation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshOperation;}
    LxResult
  Evaluate (ILxUnknownID mesh, LXtID4 type, LXtMarkMode mode)
  {
    return m_loc[0]->Evaluate (m_loc,(ILxUnknownID)mesh,type,mode);
  }
    int
  Compare (ILxUnknownID other)
  {
    return m_loc[0]->Compare (m_loc,(ILxUnknownID)other);
  }
    LxResult
  Convert (ILxUnknownID other)
  {
    return m_loc[0]->Convert (m_loc,(ILxUnknownID)other);
  }
    LxResult
  ReEvaluate (ILxUnknownID mesh, LXtID4 type)
  {
    return m_loc[0]->ReEvaluate (m_loc,(ILxUnknownID)mesh,type);
  }
    LxResult
  SetTransform (const LXtMatrix4 matrix) const
  {
    return m_loc[0]->SetTransform (m_loc,matrix);
  }
    LxResult
  Blend (ILxUnknownID other, ILxUnknownID blend)
  {
    return m_loc[0]->Blend (m_loc,(ILxUnknownID)other,(ILxUnknownID)blend);
  }
    LxResult
  Clone (ILxUnknownID target, ILxUnknownID source, void **ppvObj)
  {
    return m_loc[0]->Clone (m_loc,(ILxUnknownID)target,(ILxUnknownID)source,ppvObj);
  }
    CLxResult
  Clone (ILxUnknownID target, ILxUnknownID source, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Clone(m_loc,(ILxUnknownID)target,(ILxUnknownID)source,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_Edge : public CLxLocalize<ILxEdgeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Edge() {_init();}
  CLxLoc_Edge(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Edge(const CLxLoc_Edge &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Edge;}
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    CLxResult
  Spawn (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Spawn(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Enumerate (LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor)
  {
    return m_loc[0]->Enumerate (m_loc,mode,(ILxUnknownID)visitor,(ILxUnknownID)monitor);
  }
    LxResult
  TestMarks (LXtMarkMode mode)
  {
    return m_loc[0]->TestMarks (m_loc,mode);
  }
    LxResult
  SetMarks (LXtMarkMode set)
  {
    return m_loc[0]->SetMarks (m_loc,set);
  }
    LxResult
  Select (LXtEdgeID edge)
  {
    return m_loc[0]->Select (m_loc,edge);
  }
    LxResult
  SelectEndpoints (LXtPointID v0, LXtPointID v1)
  {
    return m_loc[0]->SelectEndpoints (m_loc,v0,v1);
  }
    LXtEdgeID
  ID (void)
  {
    return m_loc[0]->ID (m_loc);
  }
    LxResult
  Endpoints (LXtPointID *point0, LXtPointID *point1)
  {
    return m_loc[0]->Endpoints (m_loc,point0,point1);
  }
    LxResult
  MapValue (LXtMeshMapID map, float *value)
  {
    return m_loc[0]->MapValue (m_loc,map,value);
  }
    LxResult
  MapEvaluate (LXtMeshMapID map, float *value)
  {
    return m_loc[0]->MapEvaluate (m_loc,map,value);
  }
    LxResult
  SetMapValue (LXtMeshMapID map, const float *value)
  {
    return m_loc[0]->SetMapValue (m_loc,map,value);
  }
    LxResult
  ClearMapValue (LXtMeshMapID map)
  {
    return m_loc[0]->ClearMapValue (m_loc,map);
  }
    LxResult
  PolygonCount (unsigned int *count)
  {
    return m_loc[0]->PolygonCount (m_loc,count);
  }
    LxResult
  PolygonByIndex (unsigned int index, LXtPolygonID *polygonID)
  {
    return m_loc[0]->PolygonByIndex (m_loc,index,polygonID);
  }
    LxResult
  RepresentativePolygon (LXtPolygonID *polygonID, unsigned int *index)
  {
    return m_loc[0]->RepresentativePolygon (m_loc,polygonID,index);
  }
    LxResult
  SharedPolygon (LXtEdgeID edgeID, LXtPolygonID *polygonID)
  {
    return m_loc[0]->SharedPolygon (m_loc,edgeID,polygonID);
  }
    LxResult
  IsBorder (void)
  {
    return m_loc[0]->IsBorder (m_loc);
  }
    LxResult
  Symmetry (LXtEdgeID *edgeID)
  {
    return m_loc[0]->Symmetry (m_loc,edgeID);
  }
    LxResult
  OnSymmetryCenter (void)
  {
    return m_loc[0]->OnSymmetryCenter (m_loc);
  }
    LxResult
  Index (unsigned int *index)
  {
    return m_loc[0]->Index (m_loc,index);
  }
    LxResult
  SelectByIndex (unsigned int index)
  {
    return m_loc[0]->SelectByIndex (m_loc,index);
  }
    LxResult
  Mesh (void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,ppvObj);
  }
    CLxResult
  Mesh (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Mesh(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LXtEdgeID
  NextLoopEdge (int inDirection, int* outDirection, int method, int ignoreBorder, int verifyAngle)
  {
    return m_loc[0]->NextLoopEdge (m_loc,inDirection,outDirection,method,ignoreBorder,verifyAngle);
  }
};

class CLxLoc_MeshService : public CLxLocalizedService
{
public:
  ILxMeshServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_MeshService() {_init();set();}
 ~CLxLoc_MeshService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxMeshServiceID>(lx::GetGlobal(&lx::guid_MeshService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    CLxResult
  ScriptQuery (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ScriptQuery(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ModeCompose (const char *set, const char *clear, LXtMarkMode *mode)
  {
    return m_loc[0]->ModeCompose (m_loc,set,clear,mode);
  }
    LxResult
  VMapLookupType (const char *name, LXtID4 *type)
  {
    return m_loc[0]->VMapLookupType (m_loc,name,type);
  }
    LxResult
  VMapLookupName (LXtID4 type, const char **name)
  {
    return m_loc[0]->VMapLookupName (m_loc,type,name);
  }
    LxResult
  VMapDimension (LXtID4 type, unsigned int *dimension)
  {
    return m_loc[0]->VMapDimension (m_loc,type,dimension);
  }
    LxResult
  VMapIsEdgeMap (LXtID4 type)
  {
    return m_loc[0]->VMapIsEdgeMap (m_loc,type);
  }
    LxResult
  VMapIsContinuous (LXtID4 type)
  {
    return m_loc[0]->VMapIsContinuous (m_loc,type);
  }
    LxResult
  VMapZeroDefault (LXtID4 type)
  {
    return m_loc[0]->VMapZeroDefault (m_loc,type);
  }
    LxResult
  CreateMesh (void **ppvObj)
  {
    return m_loc[0]->CreateMesh (m_loc,ppvObj);
  }
    CLxResult
  CreateMesh (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateMesh(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ConvertMesh (ILxUnknownID triGroupObj, ILxUnknownID meshObj)
  {
    return m_loc[0]->ConvertMesh (m_loc,(ILxUnknownID)triGroupObj,(ILxUnknownID)meshObj);
  }
    LxResult
  MeshFromMeshID (LXtMeshID meshID, void **ppvObj)
  {
    return m_loc[0]->MeshFromMeshID (m_loc,meshID,ppvObj);
  }
    CLxResult
  MeshFromMeshID (LXtMeshID meshID, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->MeshFromMeshID(m_loc,meshID,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LXtMeshID
  MeshToMeshID (ILxUnknownID mesh)
  {
    return m_loc[0]->MeshToMeshID (m_loc,(ILxUnknownID)mesh);
  }
    LxResult
  SurfaceToTriGroup (ILxUnknownID triGroupObj, ILxUnknownID surfObj)
  {
    return m_loc[0]->SurfaceToTriGroup (m_loc,(ILxUnknownID)triGroupObj,(ILxUnknownID)surfObj);
  }
    LxResult
  MeshFromTriGroup (ILxUnknownID meshObj, ILxUnknownID triGroupObj)
  {
    return m_loc[0]->MeshFromTriGroup (m_loc,(ILxUnknownID)meshObj,(ILxUnknownID)triGroupObj);
  }
    LxResult
  TriGroupTransform (ILxUnknownID triGroupObj, LXtMatrix4 xfrm)
  {
    return m_loc[0]->TriGroupTransform (m_loc,(ILxUnknownID)triGroupObj,xfrm);
  }
    LxResult
  CreateSlice (void **ppvObj)
  {
    return m_loc[0]->CreateSlice (m_loc,ppvObj);
  }
    CLxResult
  CreateSlice (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateSlice(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CreateSolidDrill (void **ppvObj)
  {
    return m_loc[0]->CreateSolidDrill (m_loc,ppvObj);
  }
    CLxResult
  CreateSolidDrill (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateSolidDrill(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  IsMeshProcedural (ILxUnknownID item)
  {
    return m_loc[0]->IsMeshProcedural (m_loc,(ILxUnknownID)item);
  }
    LxResult
  ItemFromMesh (ILxUnknownID mesh, void **ppvObj)
  {
    return m_loc[0]->ItemFromMesh (m_loc,(ILxUnknownID)mesh,ppvObj);
  }
    CLxResult
  ItemFromMesh (ILxUnknownID mesh, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemFromMesh(m_loc,(ILxUnknownID)mesh,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CurveGroupFromMesh (ILxUnknownID mesh, const LXtMatrix4 xfrm, void **ppvObj)
  {
    return m_loc[0]->CurveGroupFromMesh (m_loc,(ILxUnknownID)mesh,xfrm,ppvObj);
  }
    CLxResult
  CurveGroupFromMesh (ILxUnknownID mesh, const LXtMatrix4 xfrm, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CurveGroupFromMesh(m_loc,(ILxUnknownID)mesh,xfrm,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  MeshFromSurface (ILxUnknownID meshObj, ILxUnknownID surfItem, ILxUnknownID surfObj)
  {
    return m_loc[0]->MeshFromSurface (m_loc,(ILxUnknownID)meshObj,(ILxUnknownID)surfItem,(ILxUnknownID)surfObj);
  }
    LxResult
  SurfaceFromMesh (ILxUnknownID mesh, ILxUnknownID meshItem, void **ppvObj)
  {
    return m_loc[0]->SurfaceFromMesh (m_loc,(ILxUnknownID)mesh,(ILxUnknownID)meshItem,ppvObj);
  }
    CLxResult
  SurfaceFromMesh (ILxUnknownID mesh, ILxUnknownID meshItem, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SurfaceFromMesh(m_loc,(ILxUnknownID)mesh,(ILxUnknownID)meshItem,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ValidateMetaData (ILxUnknownID mesh, const char *name, void **ppvObj)
  {
    return m_loc[0]->ValidateMetaData (m_loc,(ILxUnknownID)mesh,name,ppvObj);
  }
    CLxResult
  ValidateMetaData (ILxUnknownID mesh, const char *name, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ValidateMetaData(m_loc,(ILxUnknownID)mesh,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Tessellate (ILxUnknownID meshTess, ILxUnknownID meshSource, const LXtMatrix4 xfrm, unsigned int flags)
  {
    return m_loc[0]->Tessellate (m_loc,(ILxUnknownID)meshTess,(ILxUnknownID)meshSource,xfrm,flags);
  }
};

class CLxLoc_MeshXtraData : public CLxLocalize<ILxMeshXtraDataID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshXtraData() {_init();}
  CLxLoc_MeshXtraData(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshXtraData(const CLxLoc_MeshXtraData &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshXtraData;}
    LxResult
  SetPointData (LXtPointID point, void *data)
  {
    return m_loc[0]->SetPointData (m_loc,point,data);
  }
    LxResult
  SetPointObject (LXtPointID point, ILxUnknownID obj)
  {
    return m_loc[0]->SetPointObject (m_loc,point,(ILxUnknownID)obj);
  }
    LxResult
  GetPointData (LXtPointID point, void **data)
  {
    return m_loc[0]->GetPointData (m_loc,point,data);
  }
    LxResult
  GetPointObject (LXtPointID point, void **ppvObj)
  {
    return m_loc[0]->GetPointObject (m_loc,point,ppvObj);
  }
    CLxResult
  GetPointObject (LXtPointID point, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetPointObject(m_loc,point,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ClearPoint (LXtPointID point)
  {
    return m_loc[0]->ClearPoint (m_loc,point);
  }
    LxResult
  SetPolygonData (LXtPolygonID poly, void *data)
  {
    return m_loc[0]->SetPolygonData (m_loc,poly,data);
  }
    LxResult
  SetPolygonObject (LXtPolygonID poly, ILxUnknownID obj)
  {
    return m_loc[0]->SetPolygonObject (m_loc,poly,(ILxUnknownID)obj);
  }
    LxResult
  GetPolygonData (LXtPolygonID poly, void **data)
  {
    return m_loc[0]->GetPolygonData (m_loc,poly,data);
  }
    LxResult
  GetPolygonObject (LXtPolygonID poly, void **ppvObj)
  {
    return m_loc[0]->GetPolygonObject (m_loc,poly,ppvObj);
  }
    CLxResult
  GetPolygonObject (LXtPolygonID poly, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetPolygonObject(m_loc,poly,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ClearPolygon (LXtPolygonID poly)
  {
    return m_loc[0]->ClearPolygon (m_loc,poly);
  }
};

class CLxLoc_Mesh : public CLxLocalize<ILxMeshID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Mesh() {_init();}
  CLxLoc_Mesh(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Mesh(const CLxLoc_Mesh &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Mesh;}
    LxResult
  PointCount (unsigned int *count) const
  {
    return m_loc[0]->PointCount (m_loc,count);
  }
    LxResult
  PolygonCount (unsigned int *count) const
  {
    return m_loc[0]->PolygonCount (m_loc,count);
  }
    LxResult
  EdgeCount (unsigned int *count) const
  {
    return m_loc[0]->EdgeCount (m_loc,count);
  }
    LxResult
  MapCount (unsigned int *count) const
  {
    return m_loc[0]->MapCount (m_loc,count);
  }
    LxResult
  BoundingBox (LXtMarkMode pick, LXtBBox *bbox)
  {
    return m_loc[0]->BoundingBox (m_loc,pick,bbox);
  }
    LxResult
  MaxPointPolygons (LXtMarkMode pick, unsigned int *count)
  {
    return m_loc[0]->MaxPointPolygons (m_loc,pick,count);
  }
    LxResult
  MaxPolygonSize (LXtMarkMode pick, unsigned int *count)
  {
    return m_loc[0]->MaxPolygonSize (m_loc,pick,count);
  }
    LxResult
  PolyTagSetDefault (LXtID4 type, const char *tag)
  {
    return m_loc[0]->PolyTagSetDefault (m_loc,type,tag);
  }
    LxResult
  PointAccessor (void **ppvObj)
  {
    return m_loc[0]->PointAccessor (m_loc,ppvObj);
  }
    CLxResult
  PointAccessor (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->PointAccessor(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  PolygonAccessor (void **ppvObj)
  {
    return m_loc[0]->PolygonAccessor (m_loc,ppvObj);
  }
    CLxResult
  PolygonAccessor (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->PolygonAccessor(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  EdgeAccessor (void **ppvObj)
  {
    return m_loc[0]->EdgeAccessor (m_loc,ppvObj);
  }
    CLxResult
  EdgeAccessor (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->EdgeAccessor(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  MeshMapAccessor (void **ppvObj)
  {
    return m_loc[0]->MeshMapAccessor (m_loc,ppvObj);
  }
    CLxResult
  MeshMapAccessor (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->MeshMapAccessor(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetMeshEdits (unsigned int edits)
  {
    return m_loc[0]->SetMeshEdits (m_loc,edits);
  }
    LxResult
  SUBDGetLevel (int *n)
  {
    return m_loc[0]->SUBDGetLevel (m_loc,n);
  }
    LxResult
  SUBDSetLevel (int n)
  {
    return m_loc[0]->SUBDSetLevel (m_loc,n);
  }
    LxResult
  SUBDGetLinearUV (int *isLinear)
  {
    return m_loc[0]->SUBDGetLinearUV (m_loc,isLinear);
  }
    LxResult
  SUBDSetLinearUV (int isLinear)
  {
    return m_loc[0]->SUBDSetLinearUV (m_loc,isLinear);
  }
    LxResult
  PSUBGetBoundRule (int *bound)
  {
    return m_loc[0]->PSUBGetBoundRule (m_loc,bound);
  }
    LxResult
  PSUBSetBoundRule (int bound)
  {
    return m_loc[0]->PSUBSetBoundRule (m_loc,bound);
  }
    LxResult
  TestSameMesh (ILxUnknownID other)
  {
    return m_loc[0]->TestSameMesh (m_loc,(ILxUnknownID)other);
  }
    unsigned
  PTagCount (LXtID4 type)
  {
    return m_loc[0]->PTagCount (m_loc,type);
  }
    LxResult
  PTagByIndex (LXtID4 type, unsigned index, const char **tag)
  {
    return m_loc[0]->PTagByIndex (m_loc,type,index,tag);
  }
    LxResult
  PSUBGetLevel (int *n)
  {
    return m_loc[0]->PSUBGetLevel (m_loc,n);
  }
    LxResult
  PSUBSetLevel (int n)
  {
    return m_loc[0]->PSUBSetLevel (m_loc,n);
  }
    LxResult
  PSUBGetCurrentLevel (int *n)
  {
    return m_loc[0]->PSUBGetCurrentLevel (m_loc,n);
  }
    LxResult
  PSUBSetCurrentLevel (int n)
  {
    return m_loc[0]->PSUBSetCurrentLevel (m_loc,n);
  }
    LxResult
  PSUBSetSubdivObj (ILxUnknownID subObj)
  {
    return m_loc[0]->PSUBSetSubdivObj (m_loc,(ILxUnknownID)subObj);
  }
    LxResult
  ChangeEvent (unsigned event)
  {
    return m_loc[0]->ChangeEvent (m_loc,event);
  }
    LxResult
  PSUBDispNumLayer (int *num)
  {
    return m_loc[0]->PSUBDispNumLayer (m_loc,num);
  }
    const char *
  PSUBDispLayerName (int index)
  {
    return m_loc[0]->PSUBDispLayerName (m_loc,index);
  }
    LxResult
  PSUBDispLayerLookupByName (const char *name, int *index)
  {
    return m_loc[0]->PSUBDispLayerLookupByName (m_loc,name,index);
  }
    LxResult
  PSUBDispLayerCurrent (int *index)
  {
    return m_loc[0]->PSUBDispLayerCurrent (m_loc,index);
  }
    LxResult
  PSUBDispLayerEnable (int index, int *enable)
  {
    return m_loc[0]->PSUBDispLayerEnable (m_loc,index,enable);
  }
    LxResult
  PSUBDispLayerOpacity (int index, double *opacity)
  {
    return m_loc[0]->PSUBDispLayerOpacity (m_loc,index,opacity);
  }
    LxResult
  PSUBDispLayerSetOpacity (int index, double opacity)
  {
    return m_loc[0]->PSUBDispLayerSetOpacity (m_loc,index,opacity);
  }
    LxResult
  BeginEditBatch (void)
  {
    return m_loc[0]->BeginEditBatch (m_loc);
  }
    LxResult
  EndEditBatch (void)
  {
    return m_loc[0]->EndEditBatch (m_loc);
  }
    LxResult
  Merge (ILxUnknownID other, unsigned int flags)
  {
    return m_loc[0]->Merge (m_loc,(ILxUnknownID)other,flags);
  }
    LxResult
  Clear (void)
  {
    return m_loc[0]->Clear (m_loc);
  }
    LxResult
  TrackChanges (void **ppvObj)
  {
    return m_loc[0]->TrackChanges (m_loc,ppvObj);
  }
    CLxResult
  TrackChanges (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->TrackChanges(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  MergeWithTransform (ILxUnknownID other, const LXtMatrix4 xfrm, unsigned int flags)
  {
    return m_loc[0]->MergeWithTransform (m_loc,(ILxUnknownID)other,xfrm,flags);
  }
};


class CLxImpl_MeshListener1 {
  public:
    virtual ~CLxImpl_MeshListener1() {}
    virtual void
      ml_Destroy (void)
        { }
};
#define LXxD_MeshListener1_Destroy void ml_Destroy (void)
#define LXxO_MeshListener1_Destroy LXxD_MeshListener1_Destroy LXx_OVERRIDE
#define LXxC_MeshListener1_Destroy(c) void c::ml_Destroy (void)
template <class T>
class CLxIfc_MeshListener1 : public CLxInterface
{
    static void
  Destroy (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_MeshListener1, loc);
    loc->ml_Destroy ();
  }
  ILxMeshListener1 vt;
public:
  CLxIfc_MeshListener1 ()
  {
    vt.Destroy = Destroy;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshListener1;
  }
};


class CLxLoc_MeshFilterIdent : public CLxLocalize<ILxMeshFilterIdentID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshFilterIdent() {_init();}
  CLxLoc_MeshFilterIdent(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshFilterIdent(const CLxLoc_MeshFilterIdent &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshFilterIdent;}
    LxResult
  Generate (const char *ident, void **ppvObj)
  {
    return m_loc[0]->Generate (m_loc,ident,ppvObj);
  }
    CLxResult
  Generate (const char *ident, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Generate(m_loc,ident,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_MeshMap : public CLxLocalize<ILxMeshMapID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshMap() {_init();}
  CLxLoc_MeshMap(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshMap(const CLxLoc_MeshMap &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshMap;}
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    CLxResult
  Spawn (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Spawn(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Enumerate (LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor)
  {
    return m_loc[0]->Enumerate (m_loc,mode,(ILxUnknownID)visitor,(ILxUnknownID)monitor);
  }
    LxResult
  Select (LXtMeshMapID map)
  {
    return m_loc[0]->Select (m_loc,map);
  }
    LxResult
  SelectByName (LXtID4 type, const char *name)
  {
    return m_loc[0]->SelectByName (m_loc,type,name);
  }
    LxResult
  FilterByType (LXtID4 type)
  {
    return m_loc[0]->FilterByType (m_loc,type);
  }
    LXtMeshMapID
  ID (void)
  {
    return m_loc[0]->ID (m_loc);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  Type (LXtID4 *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  Dimension (unsigned int *dimension)
  {
    return m_loc[0]->Dimension (m_loc,dimension);
  }
    LxResult
  IsEdgeMap (void)
  {
    return m_loc[0]->IsEdgeMap (m_loc);
  }
    LxResult
  IsContinuous (void)
  {
    return m_loc[0]->IsContinuous (m_loc);
  }
    LxResult
  ZeroDefault (void)
  {
    return m_loc[0]->ZeroDefault (m_loc);
  }
    LxResult
  New (LXtID4 type, const char *name, LXtMeshMapID *mapID)
  {
    return m_loc[0]->New (m_loc,type,name,mapID);
  }
    LxResult
  Remove (void)
  {
    return m_loc[0]->Remove (m_loc);
  }
    LxResult
  Clear (void)
  {
    return m_loc[0]->Clear (m_loc);
  }
    LxResult
  EnumerateContinuous (ILxUnknownID visitor, ILxUnknownID point)
  {
    return m_loc[0]->EnumerateContinuous (m_loc,(ILxUnknownID)visitor,(ILxUnknownID)point);
  }
    LxResult
  EnumerateDiscontinuous (ILxUnknownID visitor, ILxUnknownID point, ILxUnknownID poly)
  {
    return m_loc[0]->EnumerateDiscontinuous (m_loc,(ILxUnknownID)visitor,(ILxUnknownID)point,(ILxUnknownID)poly);
  }
    LxResult
  EnumerateEdges (ILxUnknownID visitor, ILxUnknownID edge)
  {
    return m_loc[0]->EnumerateEdges (m_loc,(ILxUnknownID)visitor,(ILxUnknownID)edge);
  }
    LxResult
  SetName (const char *name)
  {
    return m_loc[0]->SetName (m_loc,name);
  }
    LxResult
  EnumerateUVSeamEdges (ILxUnknownID visitor, ILxUnknownID edge, ILxUnknownID poly)
  {
    return m_loc[0]->EnumerateUVSeamEdges (m_loc,(ILxUnknownID)visitor,(ILxUnknownID)edge,(ILxUnknownID)poly);
  }
    LxResult
  UVSeamOppositeEdge (LXtEdgeID originalEdge, LXtPolygonID originalPoly, LXtPolygonID *opppositePoly, int *isReverse)
  {
    return m_loc[0]->UVSeamOppositeEdge (m_loc,originalEdge,originalPoly,opppositePoly,isReverse);
  }
    LxResult
  UVBoundingBox (LXtBBox *bbox)
  {
    return m_loc[0]->UVBoundingBox (m_loc,bbox);
  }
};

#endif

