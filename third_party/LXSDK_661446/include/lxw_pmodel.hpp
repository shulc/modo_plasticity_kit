/*
 * C++ wrapper for lxpmodel.h
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
#ifndef LXW_PMODEL_HPP
#define LXW_PMODEL_HPP

#include <lxpmodel.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_SelectionOperation1 = {0x563E56B1,0xACC9,0x4E3F,0xB3,0xA8,0xE0,0xAF,0xE2,0xAB,0x56,0x45};
    static const LXtGUID guid_SelectionOperation = {0xAA86E146,0x36F1,0x44C3,0xB1,0x70,0x01,0x07,0xF6,0x00,0x94,0x1D};
    static const LXtGUID guid_SelectionState = {0xD1F068A3,0x5DFC,0x4587,0xAD,0x63,0xFE,0x1D,0x4D,0x05,0x01,0xED};
    static const LXtGUID guid_MeshElementGroup = {0x4773EA40,0xC2D6,0x4B55,0x80,0x0C,0x59,0xFF,0x6E,0x97,0x30,0xB7};
};


class CLxImpl_SelectionOperation {
  public:
    virtual ~CLxImpl_SelectionOperation() {}
    virtual LxResult
      selop_SetMesh (ILxUnknownID mesh)
        { return LXe_NOTIMPL; }
    virtual LxResult
      selop_SetTransform (LXtMatrix4 xfrm)
        { return LXe_NOTIMPL; }
    virtual LxResult
      selop_TestPoint (LXtPointID point)
        { return LXe_NOTIMPL; }
    virtual LxResult
      selop_TestEdge (LXtEdgeID edge)
        { return LXe_NOTIMPL; }
    virtual LxResult
      selop_TestPolygon (LXtPolygonID polygon)
        { return LXe_NOTIMPL; }
    virtual LxResult
      selop_Evaluate (LXtID4 type, ILxUnknownID state)
        { return LXe_NOTIMPL; }
};
#define LXxD_SelectionOperation_SetMesh LxResult selop_SetMesh (ILxUnknownID mesh)
#define LXxO_SelectionOperation_SetMesh LXxD_SelectionOperation_SetMesh LXx_OVERRIDE
#define LXxC_SelectionOperation_SetMesh(c) LxResult c::selop_SetMesh (ILxUnknownID mesh)
#define LXxD_SelectionOperation_SetTransform LxResult selop_SetTransform (LXtMatrix4 xfrm)
#define LXxO_SelectionOperation_SetTransform LXxD_SelectionOperation_SetTransform LXx_OVERRIDE
#define LXxC_SelectionOperation_SetTransform(c) LxResult c::selop_SetTransform (LXtMatrix4 xfrm)
#define LXxD_SelectionOperation_TestPoint LxResult selop_TestPoint (LXtPointID point)
#define LXxO_SelectionOperation_TestPoint LXxD_SelectionOperation_TestPoint LXx_OVERRIDE
#define LXxC_SelectionOperation_TestPoint(c) LxResult c::selop_TestPoint (LXtPointID point)
#define LXxD_SelectionOperation_TestEdge LxResult selop_TestEdge (LXtEdgeID edge)
#define LXxO_SelectionOperation_TestEdge LXxD_SelectionOperation_TestEdge LXx_OVERRIDE
#define LXxC_SelectionOperation_TestEdge(c) LxResult c::selop_TestEdge (LXtEdgeID edge)
#define LXxD_SelectionOperation_TestPolygon LxResult selop_TestPolygon (LXtPolygonID polygon)
#define LXxO_SelectionOperation_TestPolygon LXxD_SelectionOperation_TestPolygon LXx_OVERRIDE
#define LXxC_SelectionOperation_TestPolygon(c) LxResult c::selop_TestPolygon (LXtPolygonID polygon)
#define LXxD_SelectionOperation_Evaluate LxResult selop_Evaluate (LXtID4 type, ILxUnknownID state)
#define LXxO_SelectionOperation_Evaluate LXxD_SelectionOperation_Evaluate LXx_OVERRIDE
#define LXxC_SelectionOperation_Evaluate(c) LxResult c::selop_Evaluate (LXtID4 type, ILxUnknownID state)
template <class T>
class CLxIfc_SelectionOperation : public CLxInterface
{
    static LxResult
  SetMesh (LXtObjectID wcom, LXtObjectID mesh)
  {
    LXCWxINST (CLxImpl_SelectionOperation, loc);
    try {
      return loc->selop_SetMesh ((ILxUnknownID)mesh);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetTransform (LXtObjectID wcom, LXtMatrix4 xfrm)
  {
    LXCWxINST (CLxImpl_SelectionOperation, loc);
    try {
      return loc->selop_SetTransform (xfrm);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestPoint (LXtObjectID wcom, LXtPointID point)
  {
    LXCWxINST (CLxImpl_SelectionOperation, loc);
    try {
      return loc->selop_TestPoint (point);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestEdge (LXtObjectID wcom, LXtEdgeID edge)
  {
    LXCWxINST (CLxImpl_SelectionOperation, loc);
    try {
      return loc->selop_TestEdge (edge);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestPolygon (LXtObjectID wcom, LXtPolygonID polygon)
  {
    LXCWxINST (CLxImpl_SelectionOperation, loc);
    try {
      return loc->selop_TestPolygon (polygon);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Evaluate (LXtObjectID wcom, LXtID4 type, LXtObjectID state)
  {
    LXCWxINST (CLxImpl_SelectionOperation, loc);
    try {
      return loc->selop_Evaluate (type,(ILxUnknownID)state);
    } catch (LxResult rc) { return rc; }
  }
  ILxSelectionOperation vt;
public:
  CLxIfc_SelectionOperation ()
  {
    vt.SetMesh = SetMesh;
    vt.SetTransform = SetTransform;
    vt.TestPoint = TestPoint;
    vt.TestEdge = TestEdge;
    vt.TestPolygon = TestPolygon;
    vt.Evaluate = Evaluate;
    vTable = &vt.iunk;
    iid = &lx::guid_SelectionOperation;
  }
};
class CLxLoc_SelectionOperation : public CLxLocalize<ILxSelectionOperationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SelectionOperation() {_init();}
  CLxLoc_SelectionOperation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SelectionOperation(const CLxLoc_SelectionOperation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SelectionOperation;}
    LxResult
  SetMesh (ILxUnknownID mesh)
  {
    return m_loc[0]->SetMesh (m_loc,(ILxUnknownID)mesh);
  }
    LxResult
  SetTransform (LXtMatrix4 xfrm)
  {
    return m_loc[0]->SetTransform (m_loc,xfrm);
  }
    LxResult
  TestPoint (LXtPointID point)
  {
    return m_loc[0]->TestPoint (m_loc,point);
  }
    LxResult
  TestEdge (LXtEdgeID edge)
  {
    return m_loc[0]->TestEdge (m_loc,edge);
  }
    LxResult
  TestPolygon (LXtPolygonID polygon)
  {
    return m_loc[0]->TestPolygon (m_loc,polygon);
  }
    LxResult
  Evaluate (LXtID4 type, ILxUnknownID state)
  {
    return m_loc[0]->Evaluate (m_loc,type,(ILxUnknownID)state);
  }
};

class CLxLoc_SelectionState : public CLxLocalize<ILxSelectionStateID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SelectionState() {_init();}
  CLxLoc_SelectionState(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SelectionState(const CLxLoc_SelectionState &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SelectionState;}
    LxResult
  TestPoint (LXtPointID point)
  {
    return m_loc[0]->TestPoint (m_loc,point);
  }
    LxResult
  TestEdge (LXtEdgeID edge)
  {
    return m_loc[0]->TestEdge (m_loc,edge);
  }
    LxResult
  TestPolygon (LXtPolygonID polygon)
  {
    return m_loc[0]->TestPolygon (m_loc,polygon);
  }
    LxResult
  SetPoint (LXtPointID point, LxResult state)
  {
    return m_loc[0]->SetPoint (m_loc,point,state);
  }
    LxResult
  SetEdge (LXtEdgeID edge, LxResult state)
  {
    return m_loc[0]->SetEdge (m_loc,edge,state);
  }
    LxResult
  SetPolygon (LXtPolygonID polygon, LxResult state)
  {
    return m_loc[0]->SetPolygon (m_loc,polygon,state);
  }
};

class CLxImpl_MeshElementGroup {
  public:
    virtual ~CLxImpl_MeshElementGroup() {}
    virtual LxResult
      eltgrp_GroupCount (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      eltgrp_GroupName (unsigned int index, const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      eltgrp_GroupUserName (unsigned int index, const char **username)
        { return LXe_NOTIMPL; }
    virtual LxResult
      eltgrp_TestPoint (unsigned int index, LXtPointID point)
        { return LXe_NOTIMPL; }
    virtual LxResult
      eltgrp_TestEdge (unsigned int index, LXtEdgeID edge)
        { return LXe_NOTIMPL; }
    virtual LxResult
      eltgrp_TestPolygon (unsigned int index, LXtPolygonID polygon)
        { return LXe_NOTIMPL; }
};
#define LXxD_MeshElementGroup_GroupCount LxResult eltgrp_GroupCount (unsigned int *count)
#define LXxO_MeshElementGroup_GroupCount LXxD_MeshElementGroup_GroupCount LXx_OVERRIDE
#define LXxC_MeshElementGroup_GroupCount(c) LxResult c::eltgrp_GroupCount (unsigned int *count)
#define LXxD_MeshElementGroup_GroupName LxResult eltgrp_GroupName (unsigned int index, const char **name)
#define LXxO_MeshElementGroup_GroupName LXxD_MeshElementGroup_GroupName LXx_OVERRIDE
#define LXxC_MeshElementGroup_GroupName(c) LxResult c::eltgrp_GroupName (unsigned int index, const char **name)
#define LXxD_MeshElementGroup_GroupUserName LxResult eltgrp_GroupUserName (unsigned int index, const char **username)
#define LXxO_MeshElementGroup_GroupUserName LXxD_MeshElementGroup_GroupUserName LXx_OVERRIDE
#define LXxC_MeshElementGroup_GroupUserName(c) LxResult c::eltgrp_GroupUserName (unsigned int index, const char **username)
#define LXxD_MeshElementGroup_TestPoint LxResult eltgrp_TestPoint (unsigned int index, LXtPointID point)
#define LXxO_MeshElementGroup_TestPoint LXxD_MeshElementGroup_TestPoint LXx_OVERRIDE
#define LXxC_MeshElementGroup_TestPoint(c) LxResult c::eltgrp_TestPoint (unsigned int index, LXtPointID point)
#define LXxD_MeshElementGroup_TestEdge LxResult eltgrp_TestEdge (unsigned int index, LXtEdgeID edge)
#define LXxO_MeshElementGroup_TestEdge LXxD_MeshElementGroup_TestEdge LXx_OVERRIDE
#define LXxC_MeshElementGroup_TestEdge(c) LxResult c::eltgrp_TestEdge (unsigned int index, LXtEdgeID edge)
#define LXxD_MeshElementGroup_TestPolygon LxResult eltgrp_TestPolygon (unsigned int index, LXtPolygonID polygon)
#define LXxO_MeshElementGroup_TestPolygon LXxD_MeshElementGroup_TestPolygon LXx_OVERRIDE
#define LXxC_MeshElementGroup_TestPolygon(c) LxResult c::eltgrp_TestPolygon (unsigned int index, LXtPolygonID polygon)
template <class T>
class CLxIfc_MeshElementGroup : public CLxInterface
{
    static LxResult
  GroupCount (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_MeshElementGroup, loc);
    try {
      return loc->eltgrp_GroupCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GroupName (LXtObjectID wcom, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_MeshElementGroup, loc);
    try {
      return loc->eltgrp_GroupName (index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GroupUserName (LXtObjectID wcom, unsigned int index, const char **username)
  {
    LXCWxINST (CLxImpl_MeshElementGroup, loc);
    try {
      return loc->eltgrp_GroupUserName (index,username);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestPoint (LXtObjectID wcom, unsigned int index, LXtPointID point)
  {
    LXCWxINST (CLxImpl_MeshElementGroup, loc);
    try {
      return loc->eltgrp_TestPoint (index,point);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestEdge (LXtObjectID wcom, unsigned int index, LXtEdgeID edge)
  {
    LXCWxINST (CLxImpl_MeshElementGroup, loc);
    try {
      return loc->eltgrp_TestEdge (index,edge);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestPolygon (LXtObjectID wcom, unsigned int index, LXtPolygonID polygon)
  {
    LXCWxINST (CLxImpl_MeshElementGroup, loc);
    try {
      return loc->eltgrp_TestPolygon (index,polygon);
    } catch (LxResult rc) { return rc; }
  }
  ILxMeshElementGroup vt;
public:
  CLxIfc_MeshElementGroup ()
  {
    vt.GroupCount = GroupCount;
    vt.GroupName = GroupName;
    vt.GroupUserName = GroupUserName;
    vt.TestPoint = TestPoint;
    vt.TestEdge = TestEdge;
    vt.TestPolygon = TestPolygon;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshElementGroup;
  }
};
class CLxLoc_MeshElementGroup : public CLxLocalize<ILxMeshElementGroupID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshElementGroup() {_init();}
  CLxLoc_MeshElementGroup(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshElementGroup(const CLxLoc_MeshElementGroup &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshElementGroup;}
    LxResult
  GroupCount (unsigned int *count)
  {
    return m_loc[0]->GroupCount (m_loc,count);
  }
    LxResult
  GroupName (unsigned int index, const char **name)
  {
    return m_loc[0]->GroupName (m_loc,index,name);
  }
    LxResult
  GroupUserName (unsigned int index, const char **username)
  {
    return m_loc[0]->GroupUserName (m_loc,index,username);
  }
    LxResult
  TestPoint (unsigned int index, LXtPointID point)
  {
    return m_loc[0]->TestPoint (m_loc,index,point);
  }
    LxResult
  TestEdge (unsigned int index, LXtEdgeID edge)
  {
    return m_loc[0]->TestEdge (m_loc,index,edge);
  }
    LxResult
  TestPolygon (unsigned int index, LXtPolygonID polygon)
  {
    return m_loc[0]->TestPolygon (m_loc,index,polygon);
  }
};

#endif

