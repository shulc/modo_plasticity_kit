/*
 * C++ wrapper for lxvolume.h
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
#ifndef LXW_VOLUME_HPP
#define LXW_VOLUME_HPP

#include <lxvolume.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_Voxel = {0xA2B024D6,0x4D03,0x4FA0,0xB3,0xCA,0xA7,0x94,0x9D,0x7F,0x7B,0x7A};
    static const LXtGUID guid_Raymarch = {0x1E84C5A8,0xC002,0x4120,0xBA,0xB0,0x9E,0xEB,0x17,0x22,0x68,0x8B};
};

class CLxImpl_Voxel {
  public:
    virtual ~CLxImpl_Voxel() {}
    virtual LxResult
      voxel_FeatureCount (unsigned *num)
        { return LXe_NOTIMPL; }
    virtual LxResult
      voxel_FeatureByIndex (unsigned index, const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      voxel_BBox (LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
    virtual LxResult
      voxel_NextPos (float currentPos, unsigned currentSegment, float stride, float *segmentList, unsigned *nextSegment, float *nextPos)
        { return LXe_NOTIMPL; }
    virtual LxResult
      voxel_Sample (const LXtFVector pos, unsigned index, float *val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      voxel_VDBData (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      voxel_RayIntersect (const LXtVector origin, const LXtFVector direction, unsigned *numberOfSegments, float **Segmentlist)
        { return LXe_NOTIMPL; }
    virtual LxResult
      voxel_RayRelease (unsigned numberOfSegments, float **Segmentlist)
        { return LXe_NOTIMPL; }
};
#define LXxD_Voxel_FeatureCount LxResult voxel_FeatureCount (unsigned *num)
#define LXxO_Voxel_FeatureCount LXxD_Voxel_FeatureCount LXx_OVERRIDE
#define LXxC_Voxel_FeatureCount(c) LxResult c::voxel_FeatureCount (unsigned *num)
#define LXxD_Voxel_FeatureByIndex LxResult voxel_FeatureByIndex (unsigned index, const char **name)
#define LXxO_Voxel_FeatureByIndex LXxD_Voxel_FeatureByIndex LXx_OVERRIDE
#define LXxC_Voxel_FeatureByIndex(c) LxResult c::voxel_FeatureByIndex (unsigned index, const char **name)
#define LXxD_Voxel_BBox LxResult voxel_BBox (LXtTableauBox bbox)
#define LXxO_Voxel_BBox LXxD_Voxel_BBox LXx_OVERRIDE
#define LXxC_Voxel_BBox(c) LxResult c::voxel_BBox (LXtTableauBox bbox)
#define LXxD_Voxel_NextPos LxResult voxel_NextPos (float currentPos, unsigned currentSegment, float stride, float *segmentList, unsigned *nextSegment, float *nextPos)
#define LXxO_Voxel_NextPos LXxD_Voxel_NextPos LXx_OVERRIDE
#define LXxC_Voxel_NextPos(c) LxResult c::voxel_NextPos (float currentPos, unsigned currentSegment, float stride, float *segmentList, unsigned *nextSegment, float *nextPos)
#define LXxD_Voxel_Sample LxResult voxel_Sample (const LXtFVector pos, unsigned index, float *val)
#define LXxO_Voxel_Sample LXxD_Voxel_Sample LXx_OVERRIDE
#define LXxC_Voxel_Sample(c) LxResult c::voxel_Sample (const LXtFVector pos, unsigned index, float *val)
#define LXxD_Voxel_VDBData LxResult voxel_VDBData (void **ppvObj)
#define LXxO_Voxel_VDBData LXxD_Voxel_VDBData LXx_OVERRIDE
#define LXxC_Voxel_VDBData(c) LxResult c::voxel_VDBData (void **ppvObj)
#define LXxD_Voxel_RayIntersect LxResult voxel_RayIntersect (const LXtVector origin, const LXtFVector direction, unsigned *numberOfSegments, float **Segmentlist)
#define LXxO_Voxel_RayIntersect LXxD_Voxel_RayIntersect LXx_OVERRIDE
#define LXxC_Voxel_RayIntersect(c) LxResult c::voxel_RayIntersect (const LXtVector origin, const LXtFVector direction, unsigned *numberOfSegments, float **Segmentlist)
#define LXxD_Voxel_RayRelease LxResult voxel_RayRelease (unsigned numberOfSegments, float **Segmentlist)
#define LXxO_Voxel_RayRelease LXxD_Voxel_RayRelease LXx_OVERRIDE
#define LXxC_Voxel_RayRelease(c) LxResult c::voxel_RayRelease (unsigned numberOfSegments, float **Segmentlist)
template <class T>
class CLxIfc_Voxel : public CLxInterface
{
    static LxResult
  FeatureCount (LXtObjectID wcom, unsigned *num)
  {
    LXCWxINST (CLxImpl_Voxel, loc);
    try {
      return loc->voxel_FeatureCount (num);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FeatureByIndex (LXtObjectID wcom, unsigned index, const char **name)
  {
    LXCWxINST (CLxImpl_Voxel, loc);
    try {
      return loc->voxel_FeatureByIndex (index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BBox (LXtObjectID wcom, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_Voxel, loc);
    try {
      return loc->voxel_BBox (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NextPos (LXtObjectID wcom, float currentPos, unsigned currentSegment, float stride, float *segmentList, unsigned *nextSegment, float *nextPos)
  {
    LXCWxINST (CLxImpl_Voxel, loc);
    try {
      return loc->voxel_NextPos (currentPos,currentSegment,stride,segmentList,nextSegment,nextPos);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Sample (LXtObjectID wcom, const LXtFVector pos, unsigned index, float *val)
  {
    LXCWxINST (CLxImpl_Voxel, loc);
    try {
      return loc->voxel_Sample (pos,index,val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  VDBData (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Voxel, loc);
    try {
      return loc->voxel_VDBData (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RayIntersect (LXtObjectID wcom, const LXtVector origin, const LXtFVector direction, unsigned *numberOfSegments, float **Segmentlist)
  {
    LXCWxINST (CLxImpl_Voxel, loc);
    try {
      return loc->voxel_RayIntersect (origin,direction,numberOfSegments,Segmentlist);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RayRelease (LXtObjectID wcom, unsigned numberOfSegments, float **Segmentlist)
  {
    LXCWxINST (CLxImpl_Voxel, loc);
    try {
      return loc->voxel_RayRelease (numberOfSegments,Segmentlist);
    } catch (LxResult rc) { return rc; }
  }
  ILxVoxel vt;
public:
  CLxIfc_Voxel ()
  {
    vt.FeatureCount = FeatureCount;
    vt.FeatureByIndex = FeatureByIndex;
    vt.BBox = BBox;
    vt.NextPos = NextPos;
    vt.Sample = Sample;
    vt.VDBData = VDBData;
    vt.RayIntersect = RayIntersect;
    vt.RayRelease = RayRelease;
    vTable = &vt.iunk;
    iid = &lx::guid_Voxel;
  }
};
class CLxLoc_Voxel : public CLxLocalize<ILxVoxelID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Voxel() {_init();}
  CLxLoc_Voxel(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Voxel(const CLxLoc_Voxel &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Voxel;}
    LxResult
  FeatureCount (unsigned *num)
  {
    return m_loc[0]->FeatureCount (m_loc,num);
  }
    LxResult
  FeatureByIndex (unsigned index, const char **name)
  {
    return m_loc[0]->FeatureByIndex (m_loc,index,name);
  }
    LxResult
  BBox (LXtTableauBox bbox)
  {
    return m_loc[0]->BBox (m_loc,bbox);
  }
    LxResult
  NextPos (float currentPos, unsigned currentSegment, float stride, float *segmentList, unsigned *nextSegment, float *nextPos)
  {
    return m_loc[0]->NextPos (m_loc,currentPos,currentSegment,stride,segmentList,nextSegment,nextPos);
  }
    LxResult
  Sample (const LXtFVector pos, unsigned index, float *val)
  {
    return m_loc[0]->Sample (m_loc,pos,index,val);
  }
    LxResult
  VDBData (void **ppvObj)
  {
    return m_loc[0]->VDBData (m_loc,ppvObj);
  }
    CLxResult
  VDBData (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->VDBData(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RayIntersect (const LXtVector origin, const LXtFVector direction, unsigned *numberOfSegments, float **Segmentlist)
  {
    return m_loc[0]->RayIntersect (m_loc,origin,direction,numberOfSegments,Segmentlist);
  }
    LxResult
  RayRelease (unsigned numberOfSegments, float **Segmentlist)
  {
    return m_loc[0]->RayRelease (m_loc,numberOfSegments,Segmentlist);
  }
};

class CLxImpl_Raymarch {
  public:
    virtual ~CLxImpl_Raymarch() {}
    virtual LxResult
      rmrch_AddVolume (ILxUnknownID vector, LXtVolumeSample *vs)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rmrch_AddSurface (ILxUnknownID vector, LXtSurfFragment *ss)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rmrch_GetOpacity (ILxUnknownID vector, double dist, double *opa)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rmrch_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID shader)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rmrch_Jitter1D (ILxUnknownID vector, float *offset)
        { return LXe_NOTIMPL; }
};
#define LXxD_Raymarch_AddVolume LxResult rmrch_AddVolume (ILxUnknownID vector, LXtVolumeSample *vs)
#define LXxO_Raymarch_AddVolume LXxD_Raymarch_AddVolume LXx_OVERRIDE
#define LXxC_Raymarch_AddVolume(c) LxResult c::rmrch_AddVolume (ILxUnknownID vector, LXtVolumeSample *vs)
#define LXxD_Raymarch_AddSurface LxResult rmrch_AddSurface (ILxUnknownID vector, LXtSurfFragment *ss)
#define LXxO_Raymarch_AddSurface LXxD_Raymarch_AddSurface LXx_OVERRIDE
#define LXxC_Raymarch_AddSurface(c) LxResult c::rmrch_AddSurface (ILxUnknownID vector, LXtSurfFragment *ss)
#define LXxD_Raymarch_GetOpacity LxResult rmrch_GetOpacity (ILxUnknownID vector, double dist, double *opa)
#define LXxO_Raymarch_GetOpacity LXxD_Raymarch_GetOpacity LXx_OVERRIDE
#define LXxC_Raymarch_GetOpacity(c) LxResult c::rmrch_GetOpacity (ILxUnknownID vector, double dist, double *opa)
#define LXxD_Raymarch_ShaderEvaluate LxResult rmrch_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID shader)
#define LXxO_Raymarch_ShaderEvaluate LXxD_Raymarch_ShaderEvaluate LXx_OVERRIDE
#define LXxC_Raymarch_ShaderEvaluate(c) LxResult c::rmrch_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID shader)
#define LXxD_Raymarch_Jitter1D LxResult rmrch_Jitter1D (ILxUnknownID vector, float *offset)
#define LXxO_Raymarch_Jitter1D LXxD_Raymarch_Jitter1D LXx_OVERRIDE
#define LXxC_Raymarch_Jitter1D(c) LxResult c::rmrch_Jitter1D (ILxUnknownID vector, float *offset)
template <class T>
class CLxIfc_Raymarch : public CLxInterface
{
    static LxResult
  AddVolume (LXtObjectID wcom, LXtObjectID vector, LXtVolumeSample *vs)
  {
    LXCWxINST (CLxImpl_Raymarch, loc);
    try {
      return loc->rmrch_AddVolume ((ILxUnknownID)vector,vs);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddSurface (LXtObjectID wcom, LXtObjectID vector, LXtSurfFragment *ss)
  {
    LXCWxINST (CLxImpl_Raymarch, loc);
    try {
      return loc->rmrch_AddSurface ((ILxUnknownID)vector,ss);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetOpacity (LXtObjectID wcom, LXtObjectID vector, double dist, double *opa)
  {
    LXCWxINST (CLxImpl_Raymarch, loc);
    try {
      return loc->rmrch_GetOpacity ((ILxUnknownID)vector,dist,opa);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ShaderEvaluate (LXtObjectID wcom, LXtObjectID vector, LXtObjectID shader)
  {
    LXCWxINST (CLxImpl_Raymarch, loc);
    try {
      return loc->rmrch_ShaderEvaluate ((ILxUnknownID)vector,(ILxUnknownID)shader);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Jitter1D (LXtObjectID wcom, LXtObjectID vector, float *offset)
  {
    LXCWxINST (CLxImpl_Raymarch, loc);
    try {
      return loc->rmrch_Jitter1D ((ILxUnknownID)vector,offset);
    } catch (LxResult rc) { return rc; }
  }
  ILxRaymarch vt;
public:
  CLxIfc_Raymarch ()
  {
    vt.AddVolume = AddVolume;
    vt.AddSurface = AddSurface;
    vt.GetOpacity = GetOpacity;
    vt.ShaderEvaluate = ShaderEvaluate;
    vt.Jitter1D = Jitter1D;
    vTable = &vt.iunk;
    iid = &lx::guid_Raymarch;
  }
};
class CLxLoc_Raymarch : public CLxLocalize<ILxRaymarchID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Raymarch() {_init();}
  CLxLoc_Raymarch(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Raymarch(const CLxLoc_Raymarch &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Raymarch;}
    LxResult
  AddVolume (ILxUnknownID vector, LXtVolumeSample *vs)
  {
    return m_loc[0]->AddVolume (m_loc,(ILxUnknownID)vector,vs);
  }
    LxResult
  AddSurface (ILxUnknownID vector, LXtSurfFragment *ss)
  {
    return m_loc[0]->AddSurface (m_loc,(ILxUnknownID)vector,ss);
  }
    LxResult
  GetOpacity (ILxUnknownID vector, double dist, double *opa)
  {
    return m_loc[0]->GetOpacity (m_loc,(ILxUnknownID)vector,dist,opa);
  }
    LxResult
  ShaderEvaluate (ILxUnknownID vector, ILxUnknownID shader)
  {
    return m_loc[0]->ShaderEvaluate (m_loc,(ILxUnknownID)vector,(ILxUnknownID)shader);
  }
    LxResult
  Jitter1D (ILxUnknownID vector, float *offset)
  {
    return m_loc[0]->Jitter1D (m_loc,(ILxUnknownID)vector,offset);
  }
};

#endif

