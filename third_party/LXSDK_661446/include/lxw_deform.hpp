/*
 * C++ wrapper for lxdeform.h
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
#ifndef LXW_DEFORM_HPP
#define LXW_DEFORM_HPP

#include <lxdeform.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_GroupDeformer = {0x4BC04F3F,0x29FC,0x4EA3,0xB0,0x90,0x10,0x28,0x03,0x31,0xC7,0x57};
    static const LXtGUID guid_Deformation = {0xA4736B27,0x142A,0x46B2,0xAF,0x7D,0xF5,0x00,0x80,0x51,0xFC,0xD6};
    static const LXtGUID guid_Falloff1 = {0xB7D1DEF8,0x1F45,0x4924,0xB5,0x18,0xE2,0xF2,0xA7,0x6D,0x02,0x59};
    static const LXtGUID guid_WeightMapDeformerItem = {0xA9C81E0B,0x20F0,0x4D8B,0x83,0x8B,0xB5,0x93,0xEA,0xF3,0xDF,0xB8};
    static const LXtGUID guid_MeshInfluence = {0xD70AA410,0x75BB,0x480E,0x90,0xE2,0x17,0xE2,0x05,0x9E,0xB4,0x0B};
    static const LXtGUID guid_Deformer = {0x505D1B5A,0x74FF,0x4642,0xB9,0x92,0x17,0x48,0x59,0x76,0x6E,0xA3};
    static const LXtGUID guid_ItemInfluence = {0x2141BD0B,0xDEFC,0x4A92,0xA4,0xA5,0x30,0x76,0x0C,0x09,0xF1,0x8B};
    static const LXtGUID guid_Deformation1 = {0xF5705327,0x7382,0x47C5,0x8D,0x7B,0xAF,0x2C,0xC1,0x8B,0x3E,0x8A};
    static const LXtGUID guid_DeformerService = {0x8267068C,0xFDBB,0x430A,0x82,0x30,0xBE,0x64,0xF7,0x2C,0xE3,0xE3};
    static const LXtGUID guid_Deformer1 = {0xF029A563,0xA937,0x4DB2,0x99,0x2E,0x15,0x92,0x08,0x1F,0x64,0xCC};
    static const LXtGUID guid_Falloff = {0xB75CFFA3,0xD25C,0x4520,0xB1,0xC6,0x3C,0xB3,0x92,0x4B,0xF5,0x97};
};

class CLxLoc_GroupDeformer : public CLxLocalize<ILxGroupDeformerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GroupDeformer() {_init();}
  CLxLoc_GroupDeformer(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GroupDeformer(const CLxLoc_GroupDeformer &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GroupDeformer;}
    unsigned
  DeformerCount (void)
  {
    return m_loc[0]->DeformerCount (m_loc);
  }
    LxResult
  DeformerByIndex (unsigned index, void **ppvObj)
  {
    return m_loc[0]->DeformerByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  DeformerByIndex (unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->DeformerByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  PointEffect (unsigned meshIndex, LXtPointID point, unsigned *deformer, float *weight, unsigned *count, unsigned max)
  {
    return m_loc[0]->PointEffect (m_loc,meshIndex,point,deformer,weight,count,max);
  }
};

class CLxImpl_Deformation {
  public:
    virtual ~CLxImpl_Deformation() {}
    virtual unsigned
      deform_Flags (void)
        { return 0; }
    virtual LxResult
      deform_Transform (LXtMatrix4 xfrm)
        { return LXe_NOTIMPL; }
    virtual void
      deform_OffsetF (const LXtFVector position, int idx, float weight, LXtFVector offset)
        { }
    virtual void
      deform_OBSOLETE (void)
        { }
    virtual LxResult
      deform_OffsetRun (const float **pos, const int *idx, const float *weight, float **offset, unsigned num)
        { return LXe_NOTIMPL; }
};
#define LXxD_Deformation_Flags unsigned deform_Flags (void)
#define LXxO_Deformation_Flags LXxD_Deformation_Flags LXx_OVERRIDE
#define LXxC_Deformation_Flags(c) unsigned c::deform_Flags (void)
#define LXxD_Deformation_Transform LxResult deform_Transform (LXtMatrix4 xfrm)
#define LXxO_Deformation_Transform LXxD_Deformation_Transform LXx_OVERRIDE
#define LXxC_Deformation_Transform(c) LxResult c::deform_Transform (LXtMatrix4 xfrm)
#define LXxD_Deformation_OffsetF void deform_OffsetF (const LXtFVector position, int idx, float weight, LXtFVector offset)
#define LXxO_Deformation_OffsetF LXxD_Deformation_OffsetF LXx_OVERRIDE
#define LXxC_Deformation_OffsetF(c) void c::deform_OffsetF (const LXtFVector position, int idx, float weight, LXtFVector offset)
#define LXxD_Deformation_OBSOLETE void deform_OBSOLETE (void)
#define LXxO_Deformation_OBSOLETE LXxD_Deformation_OBSOLETE LXx_OVERRIDE
#define LXxC_Deformation_OBSOLETE(c) void c::deform_OBSOLETE (void)
#define LXxD_Deformation_OffsetRun LxResult deform_OffsetRun (const float **pos, const int *idx, const float *weight, float **offset, unsigned num)
#define LXxO_Deformation_OffsetRun LXxD_Deformation_OffsetRun LXx_OVERRIDE
#define LXxC_Deformation_OffsetRun(c) LxResult c::deform_OffsetRun (const float **pos, const int *idx, const float *weight, float **offset, unsigned num)
template <class T>
class CLxIfc_Deformation : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Deformation, loc);
    return loc->deform_Flags ();
  }
    static LxResult
  Transform (LXtObjectID wcom, LXtMatrix4 xfrm)
  {
    LXCWxINST (CLxImpl_Deformation, loc);
    try {
      return loc->deform_Transform (xfrm);
    } catch (LxResult rc) { return rc; }
  }
    static void
  OffsetF (LXtObjectID wcom, const LXtFVector position, int idx, float weight, LXtFVector offset)
  {
    LXCWxINST (CLxImpl_Deformation, loc);
    loc->deform_OffsetF (position,idx,weight,offset);
  }
    static void
  OBSOLETE (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Deformation, loc);
    loc->deform_OBSOLETE ();
  }
    static LxResult
  OffsetRun (LXtObjectID wcom, const float **pos, const int *idx, const float *weight, float **offset, unsigned num)
  {
    LXCWxINST (CLxImpl_Deformation, loc);
    try {
      return loc->deform_OffsetRun (pos,idx,weight,offset,num);
    } catch (LxResult rc) { return rc; }
  }
  ILxDeformation vt;
public:
  CLxIfc_Deformation ()
  {
    vt.Flags = Flags;
    vt.Transform = Transform;
    vt.OffsetF = OffsetF;
    vt.OBSOLETE = OBSOLETE;
    vt.OffsetRun = OffsetRun;
    vTable = &vt.iunk;
    iid = &lx::guid_Deformation;
  }
};
class CLxLoc_Deformation : public CLxLocalize<ILxDeformationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Deformation() {_init();}
  CLxLoc_Deformation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Deformation(const CLxLoc_Deformation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Deformation;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    LxResult
  Transform (LXtMatrix4 xfrm)
  {
    return m_loc[0]->Transform (m_loc,xfrm);
  }
    void
  OffsetF (const LXtFVector position, int idx, float weight, LXtFVector offset)
  {
    m_loc[0]->OffsetF (m_loc,position,idx,weight,offset);
  }
    void
  OBSOLETE (void)
  {
    m_loc[0]->OBSOLETE (m_loc);
  }
    LxResult
  OffsetRun (const float **pos, const int *idx, const float *weight, float **offset, unsigned num)
  {
    return m_loc[0]->OffsetRun (m_loc,pos,idx,weight,offset,num);
  }
};


class CLxImpl_WeightMapDeformerItem {
  public:
    virtual ~CLxImpl_WeightMapDeformerItem() {}
    virtual LxResult
      wmd_GetMapName (ILxUnknownID chanRead, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      wmd_GetColor (ILxUnknownID chanRead, LXtVector col)
        { return LXeDEFORM_AUTO_COLOR; }
};
#define LXxD_WeightMapDeformerItem_GetMapName LxResult wmd_GetMapName (ILxUnknownID chanRead, char *buf, unsigned len)
#define LXxO_WeightMapDeformerItem_GetMapName LXxD_WeightMapDeformerItem_GetMapName LXx_OVERRIDE
#define LXxC_WeightMapDeformerItem_GetMapName(c) LxResult c::wmd_GetMapName (ILxUnknownID chanRead, char *buf, unsigned len)
#define LXxD_WeightMapDeformerItem_GetColor LxResult wmd_GetColor (ILxUnknownID chanRead, LXtVector col)
#define LXxO_WeightMapDeformerItem_GetColor LXxD_WeightMapDeformerItem_GetColor LXx_OVERRIDE
#define LXxC_WeightMapDeformerItem_GetColor(c) LxResult c::wmd_GetColor (ILxUnknownID chanRead, LXtVector col)
template <class T>
class CLxIfc_WeightMapDeformerItem : public CLxInterface
{
    static LxResult
  GetMapName (LXtObjectID wcom, LXtObjectID chanRead, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_WeightMapDeformerItem, loc);
    try {
      return loc->wmd_GetMapName ((ILxUnknownID)chanRead,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetColor (LXtObjectID wcom, LXtObjectID chanRead, LXtVector col)
  {
    LXCWxINST (CLxImpl_WeightMapDeformerItem, loc);
    try {
      return loc->wmd_GetColor ((ILxUnknownID)chanRead,col);
    } catch (LxResult rc) { return rc; }
  }
  ILxWeightMapDeformerItem vt;
public:
  CLxIfc_WeightMapDeformerItem ()
  {
    vt.GetMapName = GetMapName;
    vt.GetColor = GetColor;
    vTable = &vt.iunk;
    iid = &lx::guid_WeightMapDeformerItem;
  }
};
class CLxLoc_WeightMapDeformerItem : public CLxLocalize<ILxWeightMapDeformerItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_WeightMapDeformerItem() {_init();}
  CLxLoc_WeightMapDeformerItem(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_WeightMapDeformerItem(const CLxLoc_WeightMapDeformerItem &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_WeightMapDeformerItem;}
    LxResult
  GetMapName (ILxUnknownID chanRead, char *buf, unsigned len)
  {
    return m_loc[0]->GetMapName (m_loc,(ILxUnknownID)chanRead,buf,len);
  }
    LxResult
  GetMapName (ILxUnknownID chanRead, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->GetMapName (m_loc,(ILxUnknownID)chanRead,buf,len);
    LXWx_SBUF2
  }
    LxResult
  GetColor (ILxUnknownID chanRead, LXtVector col)
  {
    return m_loc[0]->GetColor (m_loc,(ILxUnknownID)chanRead,col);
  }
};

class CLxImpl_MeshInfluence {
  public:
    virtual ~CLxImpl_MeshInfluence() {}
    virtual unsigned
      minf_MeshCount (void)
        { return 0; }
    virtual LxResult
      minf_MeshByIndex (unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual unsigned
      minf_PartitionIndex (unsigned index)
        { return index; }
    virtual LxResult
      minf_SetMesh (unsigned index, ILxUnknownID mesh, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      minf_SetTransform (unsigned index, LXtMatrix4 xfrm)
        { return LXe_NOTIMPL; }
    virtual LxResult
      minf_MeshChange (unsigned index, LxResult change)
        { return LXe_NOTIMPL; }
};
#define LXxD_MeshInfluence_MeshCount unsigned minf_MeshCount (void)
#define LXxO_MeshInfluence_MeshCount LXxD_MeshInfluence_MeshCount LXx_OVERRIDE
#define LXxC_MeshInfluence_MeshCount(c) unsigned c::minf_MeshCount (void)
#define LXxD_MeshInfluence_MeshByIndex LxResult minf_MeshByIndex (unsigned index, void **ppvObj)
#define LXxO_MeshInfluence_MeshByIndex LXxD_MeshInfluence_MeshByIndex LXx_OVERRIDE
#define LXxC_MeshInfluence_MeshByIndex(c) LxResult c::minf_MeshByIndex (unsigned index, void **ppvObj)
#define LXxD_MeshInfluence_PartitionIndex unsigned minf_PartitionIndex (unsigned index)
#define LXxO_MeshInfluence_PartitionIndex LXxD_MeshInfluence_PartitionIndex LXx_OVERRIDE
#define LXxC_MeshInfluence_PartitionIndex(c) unsigned c::minf_PartitionIndex (unsigned index)
#define LXxD_MeshInfluence_SetMesh LxResult minf_SetMesh (unsigned index, ILxUnknownID mesh, ILxUnknownID item)
#define LXxO_MeshInfluence_SetMesh LXxD_MeshInfluence_SetMesh LXx_OVERRIDE
#define LXxC_MeshInfluence_SetMesh(c) LxResult c::minf_SetMesh (unsigned index, ILxUnknownID mesh, ILxUnknownID item)
#define LXxD_MeshInfluence_SetTransform LxResult minf_SetTransform (unsigned index, LXtMatrix4 xfrm)
#define LXxO_MeshInfluence_SetTransform LXxD_MeshInfluence_SetTransform LXx_OVERRIDE
#define LXxC_MeshInfluence_SetTransform(c) LxResult c::minf_SetTransform (unsigned index, LXtMatrix4 xfrm)
#define LXxD_MeshInfluence_MeshChange LxResult minf_MeshChange (unsigned index, LxResult change)
#define LXxO_MeshInfluence_MeshChange LXxD_MeshInfluence_MeshChange LXx_OVERRIDE
#define LXxC_MeshInfluence_MeshChange(c) LxResult c::minf_MeshChange (unsigned index, LxResult change)
template <class T>
class CLxIfc_MeshInfluence : public CLxInterface
{
    static unsigned
  MeshCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_MeshInfluence, loc);
    return loc->minf_MeshCount ();
  }
    static LxResult
  MeshByIndex (LXtObjectID wcom, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_MeshInfluence, loc);
    try {
      return loc->minf_MeshByIndex (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned
  PartitionIndex (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_MeshInfluence, loc);
    return loc->minf_PartitionIndex (index);
  }
    static LxResult
  SetMesh (LXtObjectID wcom, unsigned index, LXtObjectID mesh, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_MeshInfluence, loc);
    try {
      return loc->minf_SetMesh (index,(ILxUnknownID)mesh,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetTransform (LXtObjectID wcom, unsigned index, LXtMatrix4 xfrm)
  {
    LXCWxINST (CLxImpl_MeshInfluence, loc);
    try {
      return loc->minf_SetTransform (index,xfrm);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MeshChange (LXtObjectID wcom, unsigned index, LxResult change)
  {
    LXCWxINST (CLxImpl_MeshInfluence, loc);
    try {
      return loc->minf_MeshChange (index,change);
    } catch (LxResult rc) { return rc; }
  }
  ILxMeshInfluence vt;
public:
  CLxIfc_MeshInfluence ()
  {
    vt.MeshCount = MeshCount;
    vt.MeshByIndex = MeshByIndex;
    vt.PartitionIndex = PartitionIndex;
    vt.SetMesh = SetMesh;
    vt.SetTransform = SetTransform;
    vt.MeshChange = MeshChange;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshInfluence;
  }
};
class CLxLoc_MeshInfluence : public CLxLocalize<ILxMeshInfluenceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshInfluence() {_init();}
  CLxLoc_MeshInfluence(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshInfluence(const CLxLoc_MeshInfluence &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshInfluence;}
    unsigned
  MeshCount (void)
  {
    return m_loc[0]->MeshCount (m_loc);
  }
    LxResult
  MeshByIndex (unsigned index, void **ppvObj)
  {
    return m_loc[0]->MeshByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  MeshByIndex (unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->MeshByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned
  PartitionIndex (unsigned index)
  {
    return m_loc[0]->PartitionIndex (m_loc,index);
  }
    LxResult
  SetMesh (unsigned index, ILxUnknownID mesh, ILxUnknownID item)
  {
    return m_loc[0]->SetMesh (m_loc,index,(ILxUnknownID)mesh,(ILxUnknownID)item);
  }
    LxResult
  SetTransform (unsigned index, LXtMatrix4 xfrm)
  {
    return m_loc[0]->SetTransform (m_loc,index,xfrm);
  }
    LxResult
  MeshChange (unsigned index, LxResult change)
  {
    return m_loc[0]->MeshChange (m_loc,index,change);
  }
};

class CLxImpl_Deformer {
  public:
    virtual ~CLxImpl_Deformer() {}
    virtual unsigned
      dinf_Flags (void)
        = 0;
    virtual unsigned
      dinf_PartitionCount (void)
        { return 0; }
    virtual LxResult
      dinf_EnumeratePartition (ILxUnknownID visitor, unsigned part)
        { return LXe_NOTIMPL; }
    virtual LXtDeformElt
      dinf_Element (unsigned *segment)
        = 0;
    virtual LxResult
      dinf_SetPartition (unsigned part)
        { return LXe_NOTIMPL; }
    virtual float
      dinf_Weight (LXtDeformElt elt, const LXtFVector pos, int idx)
        { return 1; }
    virtual void
      dinf_Offset (LXtDeformElt elt, float weight, const LXtFVector pos, int idx, LXtFVector offset)
        { }
    virtual LxResult
      dinf_WeightRun (unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, float *weight, unsigned num)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dinf_OffsetRun (unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, const float *weight, float **offset, unsigned num)
        { return LXe_NOTIMPL; }
};
#define LXxD_Deformer_Flags unsigned dinf_Flags (void)
#define LXxO_Deformer_Flags LXxD_Deformer_Flags LXx_OVERRIDE
#define LXxC_Deformer_Flags(c) unsigned c::dinf_Flags (void)
#define LXxD_Deformer_PartitionCount unsigned dinf_PartitionCount (void)
#define LXxO_Deformer_PartitionCount LXxD_Deformer_PartitionCount LXx_OVERRIDE
#define LXxC_Deformer_PartitionCount(c) unsigned c::dinf_PartitionCount (void)
#define LXxD_Deformer_EnumeratePartition LxResult dinf_EnumeratePartition (ILxUnknownID visitor, unsigned part)
#define LXxO_Deformer_EnumeratePartition LXxD_Deformer_EnumeratePartition LXx_OVERRIDE
#define LXxC_Deformer_EnumeratePartition(c) LxResult c::dinf_EnumeratePartition (ILxUnknownID visitor, unsigned part)
#define LXxD_Deformer_Element LXtDeformElt dinf_Element (unsigned *segment)
#define LXxO_Deformer_Element LXxD_Deformer_Element LXx_OVERRIDE
#define LXxC_Deformer_Element(c) LXtDeformElt c::dinf_Element (unsigned *segment)
#define LXxD_Deformer_SetPartition LxResult dinf_SetPartition (unsigned part)
#define LXxO_Deformer_SetPartition LXxD_Deformer_SetPartition LXx_OVERRIDE
#define LXxC_Deformer_SetPartition(c) LxResult c::dinf_SetPartition (unsigned part)
#define LXxD_Deformer_Weight float dinf_Weight (LXtDeformElt elt, const LXtFVector pos, int idx)
#define LXxO_Deformer_Weight LXxD_Deformer_Weight LXx_OVERRIDE
#define LXxC_Deformer_Weight(c) float c::dinf_Weight (LXtDeformElt elt, const LXtFVector pos, int idx)
#define LXxD_Deformer_Offset void dinf_Offset (LXtDeformElt elt, float weight, const LXtFVector pos, int idx, LXtFVector offset)
#define LXxO_Deformer_Offset LXxD_Deformer_Offset LXx_OVERRIDE
#define LXxC_Deformer_Offset(c) void c::dinf_Offset (LXtDeformElt elt, float weight, const LXtFVector pos, int idx, LXtFVector offset)
#define LXxD_Deformer_WeightRun LxResult dinf_WeightRun (unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, float *weight, unsigned num)
#define LXxO_Deformer_WeightRun LXxD_Deformer_WeightRun LXx_OVERRIDE
#define LXxC_Deformer_WeightRun(c) LxResult c::dinf_WeightRun (unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, float *weight, unsigned num)
#define LXxD_Deformer_OffsetRun LxResult dinf_OffsetRun (unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, const float *weight, float **offset, unsigned num)
#define LXxO_Deformer_OffsetRun LXxD_Deformer_OffsetRun LXx_OVERRIDE
#define LXxC_Deformer_OffsetRun(c) LxResult c::dinf_OffsetRun (unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, const float *weight, float **offset, unsigned num)
template <class T>
class CLxIfc_Deformer : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Deformer, loc);
    return loc->dinf_Flags ();
  }
    static unsigned
  PartitionCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Deformer, loc);
    return loc->dinf_PartitionCount ();
  }
    static LxResult
  EnumeratePartition (LXtObjectID wcom, LXtObjectID visitor, unsigned part)
  {
    LXCWxINST (CLxImpl_Deformer, loc);
    try {
      return loc->dinf_EnumeratePartition ((ILxUnknownID)visitor,part);
    } catch (LxResult rc) { return rc; }
  }
    static LXtDeformElt
  Element (LXtObjectID wcom, unsigned *segment)
  {
    LXCWxINST (CLxImpl_Deformer, loc);
    return loc->dinf_Element (segment);
  }
    static LxResult
  SetPartition (LXtObjectID wcom, unsigned part)
  {
    LXCWxINST (CLxImpl_Deformer, loc);
    try {
      return loc->dinf_SetPartition (part);
    } catch (LxResult rc) { return rc; }
  }
    static float
  Weight (LXtObjectID wcom, LXtDeformElt elt, const LXtFVector pos, int idx)
  {
    LXCWxINST (CLxImpl_Deformer, loc);
    return loc->dinf_Weight (elt,pos,idx);
  }
    static void
  Offset (LXtObjectID wcom, LXtDeformElt elt, float weight, const LXtFVector pos, int idx, LXtFVector offset)
  {
    LXCWxINST (CLxImpl_Deformer, loc);
    loc->dinf_Offset (elt,weight,pos,idx,offset);
  }
    static LxResult
  WeightRun (LXtObjectID wcom, unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, float *weight, unsigned num)
  {
    LXCWxINST (CLxImpl_Deformer, loc);
    try {
      return loc->dinf_WeightRun (segment,elt,pos,idx,weight,num);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  OffsetRun (LXtObjectID wcom, unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, const float *weight, float **offset, unsigned num)
  {
    LXCWxINST (CLxImpl_Deformer, loc);
    try {
      return loc->dinf_OffsetRun (segment,elt,pos,idx,weight,offset,num);
    } catch (LxResult rc) { return rc; }
  }
  ILxDeformer vt;
public:
  CLxIfc_Deformer ()
  {
    vt.Flags = Flags;
    vt.PartitionCount = PartitionCount;
    vt.EnumeratePartition = EnumeratePartition;
    vt.Element = Element;
    vt.SetPartition = SetPartition;
    vt.Weight = Weight;
    vt.Offset = Offset;
    vt.WeightRun = WeightRun;
    vt.OffsetRun = OffsetRun;
    vTable = &vt.iunk;
    iid = &lx::guid_Deformer;
  }
};
class CLxLoc_Deformer : public CLxLocalize<ILxDeformerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Deformer() {_init();}
  CLxLoc_Deformer(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Deformer(const CLxLoc_Deformer &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Deformer;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    unsigned
  PartitionCount (void)
  {
    return m_loc[0]->PartitionCount (m_loc);
  }
    LxResult
  EnumeratePartition (ILxUnknownID visitor, unsigned part)
  {
    return m_loc[0]->EnumeratePartition (m_loc,(ILxUnknownID)visitor,part);
  }
    LXtDeformElt
  Element (unsigned *segment)
  {
    return m_loc[0]->Element (m_loc,segment);
  }
    LxResult
  SetPartition (unsigned part)
  {
    return m_loc[0]->SetPartition (m_loc,part);
  }
    float
  Weight (LXtDeformElt elt, const LXtFVector pos, int idx)
  {
    return m_loc[0]->Weight (m_loc,elt,pos,idx);
  }
    void
  Offset (LXtDeformElt elt, float weight, const LXtFVector pos, int idx, LXtFVector offset)
  {
    m_loc[0]->Offset (m_loc,elt,weight,pos,idx,offset);
  }
    LxResult
  WeightRun (unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, float *weight, unsigned num)
  {
    return m_loc[0]->WeightRun (m_loc,segment,elt,pos,idx,weight,num);
  }
    LxResult
  OffsetRun (unsigned segment, const LXtDeformElt *elt, const float **pos, const int *idx, const float *weight, float **offset, unsigned num)
  {
    return m_loc[0]->OffsetRun (m_loc,segment,elt,pos,idx,weight,offset,num);
  }
};

class CLxImpl_ItemInfluence {
  public:
    virtual ~CLxImpl_ItemInfluence() {}
    virtual LxResult
      iinf_HasItems (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      iinf_Enumerate (ILxUnknownID visitor)
        { return LXe_NOTIMPL; }
    virtual LxResult
      iinf_GetItem (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      iinf_AllowTransform (unsigned index, unsigned *flags)
        { return LXe_NOTIMPL; }
};
#define LXxD_ItemInfluence_HasItems LxResult iinf_HasItems (void)
#define LXxO_ItemInfluence_HasItems LXxD_ItemInfluence_HasItems LXx_OVERRIDE
#define LXxC_ItemInfluence_HasItems(c) LxResult c::iinf_HasItems (void)
#define LXxD_ItemInfluence_Enumerate LxResult iinf_Enumerate (ILxUnknownID visitor)
#define LXxO_ItemInfluence_Enumerate LXxD_ItemInfluence_Enumerate LXx_OVERRIDE
#define LXxC_ItemInfluence_Enumerate(c) LxResult c::iinf_Enumerate (ILxUnknownID visitor)
#define LXxD_ItemInfluence_GetItem LxResult iinf_GetItem (void **ppvObj)
#define LXxO_ItemInfluence_GetItem LXxD_ItemInfluence_GetItem LXx_OVERRIDE
#define LXxC_ItemInfluence_GetItem(c) LxResult c::iinf_GetItem (void **ppvObj)
#define LXxD_ItemInfluence_AllowTransform LxResult iinf_AllowTransform (unsigned index, unsigned *flags)
#define LXxO_ItemInfluence_AllowTransform LXxD_ItemInfluence_AllowTransform LXx_OVERRIDE
#define LXxC_ItemInfluence_AllowTransform(c) LxResult c::iinf_AllowTransform (unsigned index, unsigned *flags)
template <class T>
class CLxIfc_ItemInfluence : public CLxInterface
{
    static LxResult
  HasItems (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ItemInfluence, loc);
    try {
      return loc->iinf_HasItems ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Enumerate (LXtObjectID wcom, LXtObjectID visitor)
  {
    LXCWxINST (CLxImpl_ItemInfluence, loc);
    try {
      return loc->iinf_Enumerate ((ILxUnknownID)visitor);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetItem (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ItemInfluence, loc);
    try {
      return loc->iinf_GetItem (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AllowTransform (LXtObjectID wcom, unsigned index, unsigned *flags)
  {
    LXCWxINST (CLxImpl_ItemInfluence, loc);
    try {
      return loc->iinf_AllowTransform (index,flags);
    } catch (LxResult rc) { return rc; }
  }
  ILxItemInfluence vt;
public:
  CLxIfc_ItemInfluence ()
  {
    vt.HasItems = HasItems;
    vt.Enumerate = Enumerate;
    vt.GetItem = GetItem;
    vt.AllowTransform = AllowTransform;
    vTable = &vt.iunk;
    iid = &lx::guid_ItemInfluence;
  }
};
class CLxLoc_ItemInfluence : public CLxLocalize<ILxItemInfluenceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemInfluence() {_init();}
  CLxLoc_ItemInfluence(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemInfluence(const CLxLoc_ItemInfluence &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemInfluence;}
    LxResult
  HasItems (void)
  {
    return m_loc[0]->HasItems (m_loc);
  }
    LxResult
  Enumerate (ILxUnknownID visitor)
  {
    return m_loc[0]->Enumerate (m_loc,(ILxUnknownID)visitor);
  }
    LxResult
  GetItem (void **ppvObj)
  {
    return m_loc[0]->GetItem (m_loc,ppvObj);
  }
    CLxResult
  GetItem (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetItem(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AllowTransform (unsigned index, unsigned *flags)
  {
    return m_loc[0]->AllowTransform (m_loc,index,flags);
  }
};


class CLxLoc_DeformerService : public CLxLocalizedService
{
public:
  ILxDeformerServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_DeformerService() {_init();set();}
 ~CLxLoc_DeformerService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxDeformerServiceID>(lx::GetGlobal(&lx::guid_DeformerService));}
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
  DeformerFlags (ILxUnknownID item, unsigned *flags)
  {
    return m_loc[0]->DeformerFlags (m_loc,(ILxUnknownID)item,flags);
  }
    LxResult
  DeformerChannel (ILxUnknownID item, unsigned *index)
  {
    return m_loc[0]->DeformerChannel (m_loc,(ILxUnknownID)item,index);
  }
    LxResult
  MergeChangeState (LxResult c1, LxResult c2)
  {
    return m_loc[0]->MergeChangeState (m_loc,c1,c2);
  }
    LxResult
  MeshCount (ILxUnknownID defItem, unsigned *count)
  {
    return m_loc[0]->MeshCount (m_loc,(ILxUnknownID)defItem,count);
  }
    LxResult
  MeshByIndex (ILxUnknownID defItem, unsigned index, void **ppvObj)
  {
    return m_loc[0]->MeshByIndex (m_loc,(ILxUnknownID)defItem,index,ppvObj);
  }
    CLxResult
  MeshByIndex (ILxUnknownID defItem, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->MeshByIndex(m_loc,(ILxUnknownID)defItem,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GroupDeformer (ILxUnknownID dgroup, ILxUnknownID chanRead, void **ppvObj)
  {
    return m_loc[0]->GroupDeformer (m_loc,(ILxUnknownID)dgroup,(ILxUnknownID)chanRead,ppvObj);
  }
    CLxResult
  GroupDeformer (ILxUnknownID dgroup, ILxUnknownID chanRead, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GroupDeformer(m_loc,(ILxUnknownID)dgroup,(ILxUnknownID)chanRead,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  DeformerDeformationItem (ILxUnknownID defItem, void **ppvObj)
  {
    return m_loc[0]->DeformerDeformationItem (m_loc,(ILxUnknownID)defItem,ppvObj);
  }
    CLxResult
  DeformerDeformationItem (ILxUnknownID defItem, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->DeformerDeformationItem(m_loc,(ILxUnknownID)defItem,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void
  InvalidateTargets (ILxUnknownID scene)
  {
    m_loc[0]->InvalidateTargets (m_loc,(ILxUnknownID)scene);
  }
    LXtDeformElt
  ItemToDeformElt (ILxUnknownID item)
  {
    return m_loc[0]->ItemToDeformElt (m_loc,(ILxUnknownID)item);
  }
    ILxUnknownID
  DeformEltToItem (LXtDeformElt elt)
  {
    return (ILxUnknownID) m_loc[0]->DeformEltToItem (m_loc,elt);
  }
    LxResult
  StackTargetCount (ILxUnknownID defItem, unsigned *count)
  {
    return m_loc[0]->StackTargetCount (m_loc,(ILxUnknownID)defItem,count);
  }
    LxResult
  StackTargetByIndex (ILxUnknownID defItem, unsigned index, void **ppvObj)
  {
    return m_loc[0]->StackTargetByIndex (m_loc,(ILxUnknownID)defItem,index,ppvObj);
  }
    CLxResult
  StackTargetByIndex (ILxUnknownID defItem, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->StackTargetByIndex(m_loc,(ILxUnknownID)defItem,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};


class CLxImpl_Falloff {
  public:
    virtual ~CLxImpl_Falloff() {}
    virtual LxResult
      fall_Bounds (LXtBBox *box)
        { return LXe_NOTIMPL; }
    virtual float
      fall_WeightF (const LXtFVector position, LXtPointID point, LXtPolygonID polygon)
        = 0;
    virtual LxResult
      fall_WeightRun (const float **pos, const LXtPointID *points, const LXtPolygonID *polygons, float *weight, unsigned num)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fall_SetMesh (ILxUnknownID mesh, LXtMatrix4 xfrm)
        { return LXe_NOTIMPL; }
};
#define LXxD_Falloff_Bounds LxResult fall_Bounds (LXtBBox *box)
#define LXxO_Falloff_Bounds LXxD_Falloff_Bounds LXx_OVERRIDE
#define LXxC_Falloff_Bounds(c) LxResult c::fall_Bounds (LXtBBox *box)
#define LXxD_Falloff_WeightF float fall_WeightF (const LXtFVector position, LXtPointID point, LXtPolygonID polygon)
#define LXxO_Falloff_WeightF LXxD_Falloff_WeightF LXx_OVERRIDE
#define LXxC_Falloff_WeightF(c) float c::fall_WeightF (const LXtFVector position, LXtPointID point, LXtPolygonID polygon)
#define LXxD_Falloff_WeightRun LxResult fall_WeightRun (const float **pos, const LXtPointID *points, const LXtPolygonID *polygons, float *weight, unsigned num)
#define LXxO_Falloff_WeightRun LXxD_Falloff_WeightRun LXx_OVERRIDE
#define LXxC_Falloff_WeightRun(c) LxResult c::fall_WeightRun (const float **pos, const LXtPointID *points, const LXtPolygonID *polygons, float *weight, unsigned num)
#define LXxD_Falloff_SetMesh LxResult fall_SetMesh (ILxUnknownID mesh, LXtMatrix4 xfrm)
#define LXxO_Falloff_SetMesh LXxD_Falloff_SetMesh LXx_OVERRIDE
#define LXxC_Falloff_SetMesh(c) LxResult c::fall_SetMesh (ILxUnknownID mesh, LXtMatrix4 xfrm)
template <class T>
class CLxIfc_Falloff : public CLxInterface
{
    static LxResult
  Bounds (LXtObjectID wcom, LXtBBox *box)
  {
    LXCWxINST (CLxImpl_Falloff, loc);
    try {
      return loc->fall_Bounds (box);
    } catch (LxResult rc) { return rc; }
  }
    static float
  WeightF (LXtObjectID wcom, const LXtFVector position, LXtPointID point, LXtPolygonID polygon)
  {
    LXCWxINST (CLxImpl_Falloff, loc);
    return loc->fall_WeightF (position,point,polygon);
  }
    static LxResult
  WeightRun (LXtObjectID wcom, const float **pos, const LXtPointID *points, const LXtPolygonID *polygons, float *weight, unsigned num)
  {
    LXCWxINST (CLxImpl_Falloff, loc);
    try {
      return loc->fall_WeightRun (pos,points,polygons,weight,num);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetMesh (LXtObjectID wcom, LXtObjectID mesh, LXtMatrix4 xfrm)
  {
    LXCWxINST (CLxImpl_Falloff, loc);
    try {
      return loc->fall_SetMesh ((ILxUnknownID)mesh,xfrm);
    } catch (LxResult rc) { return rc; }
  }
  ILxFalloff vt;
public:
  CLxIfc_Falloff ()
  {
    vt.Bounds = Bounds;
    vt.WeightF = WeightF;
    vt.WeightRun = WeightRun;
    vt.SetMesh = SetMesh;
    vTable = &vt.iunk;
    iid = &lx::guid_Falloff;
  }
};
class CLxLoc_Falloff : public CLxLocalize<ILxFalloffID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Falloff() {_init();}
  CLxLoc_Falloff(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Falloff(const CLxLoc_Falloff &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Falloff;}
    LxResult
  Bounds (LXtBBox *box)
  {
    return m_loc[0]->Bounds (m_loc,box);
  }
    float
  WeightF (const LXtFVector position, LXtPointID point, LXtPolygonID polygon)
  {
    return m_loc[0]->WeightF (m_loc,position,point,polygon);
  }
    LxResult
  WeightRun (const float **pos, const LXtPointID *points, const LXtPolygonID *polygons, float *weight, unsigned num)
  {
    return m_loc[0]->WeightRun (m_loc,pos,points,polygons,weight,num);
  }
    LxResult
  SetMesh (ILxUnknownID mesh, LXtMatrix4 xfrm)
  {
    return m_loc[0]->SetMesh (m_loc,(ILxUnknownID)mesh,xfrm);
  }
};

#endif

