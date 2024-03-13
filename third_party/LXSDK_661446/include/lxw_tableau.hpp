/*
 * C++ wrapper for lxtableau.h
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
#ifndef LXW_TABLEAU_HPP
#define LXW_TABLEAU_HPP

#include <lxtableau.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_TableauInstance = {0x77837A98,0x2BC5,0x466C,0x83,0x4F,0xDC,0x93,0x76,0x42,0x55,0x8B};
    static const LXtGUID guid_TableauListener = {0x848C5B64,0x4C9F,0x404E,0x8E,0x3F,0xCF,0x72,0x50,0x07,0xF7,0x4D};
    static const LXtGUID guid_NodalService = {0x2055F206,0x1682,0x11E3,0x9F,0x05,0x6A,0xCC,0x60,0x88,0x70,0x9B};
    static const LXtGUID guid_TableauService = {0x8DF92316,0x3172,0x465A,0xA1,0x99,0x25,0x47,0x92,0xD3,0x77,0x32};
    static const LXtGUID guid_Instanceable = {0x9CC7F9F4,0x9540,0x4EEA,0x8E,0xE9,0x71,0x0D,0x58,0xEC,0x68,0xF9};
    static const LXtGUID guid_TableauVolume = {0x97962302,0x4B49,0x4282,0xB2,0x59,0xF3,0x47,0xF1,0x01,0x28,0x18};
    static const LXtGUID guid_ShaderSlice = {0x47B885B9,0xB1D9,0x4F86,0x82,0x9F,0xA6,0xAA,0xBB,0xD7,0xFF,0xF7};
    static const LXtGUID guid_LightSample = {0x43734621,0x9B93,0x4174,0xAC,0x63,0xE2,0xFE,0x7D,0xDA,0x87,0x94};
    static const LXtGUID guid_TableauSource1 = {0x1121C167,0xF934,0x4421,0x8A,0xBE,0x32,0xF8,0xE4,0x65,0x93,0x24};
    static const LXtGUID guid_TableauElement = {0x71D90AD9,0x3E30,0x4CE8,0x9E,0x2B,0xF7,0x0D,0xA2,0x81,0xB2,0xDC};
    static const LXtGUID guid_Tableau = {0x76C4EDD9,0x5FF9,0x4342,0xBB,0x08,0xEF,0xCD,0x0B,0x34,0x40,0x04};
    static const LXtGUID guid_TableauSource = {0x9CC7F9F4,0x9540,0x4EEA,0x8E,0xE9,0x71,0x0D,0x58,0xEC,0x68,0xF9};
    static const LXtGUID guid_TableauProxy = {0xFB34BD64,0x099C,0x4B30,0x8E,0xF7,0x2B,0xB0,0x4C,0xA0,0xE9,0x2C};
    static const LXtGUID guid_TableauShader = {0xA0E3B574,0xB0AC,0x4530,0xA4,0x3F,0x7C,0xC8,0xDA,0x53,0x6E,0x25};
    static const LXtGUID guid_TableauInstance1 = {0x9B57D0DB,0xC0B4,0x435E,0x8C,0xDD,0xE3,0xDD,0xCF,0x66,0x17,0x2D};
    static const LXtGUID guid_TableauSurface = {0xF785D229,0x6BA5,0x4C8E,0x99,0x94,0x3E,0x50,0x20,0x53,0xB8,0x3C};
    static const LXtGUID guid_TriangleSoup = {0x17536C2D,0x07BD,0x49C8,0x83,0x48,0xCE,0xBD,0xE4,0xD3,0xA8,0x56};
    static const LXtGUID guid_TableauSurface1 = {0xB5769A8B,0x6254,0x42E3,0x86,0x2F,0x0A,0x81,0x1E,0x71,0x6E,0x21};
    static const LXtGUID guid_TableauFilter = {0xFD1326E7,0xEECF,0x4EAC,0xB9,0xAD,0xB1,0xD6,0x4E,0x75,0x03,0xBE};
    static const LXtGUID guid_TableauLight = {0x7FE816D1,0x4A7F,0x4BE5,0x96,0x89,0x49,0x91,0xC0,0x3C,0xAE,0xE0};
};

class CLxImpl_TableauInstance {
  public:
    virtual ~CLxImpl_TableauInstance() {}
    virtual LxResult
      tins_Properties (ILxUnknownID vecstack)
        { return LXe_OK; }
    virtual LxResult
      tins_GetTransform (unsigned endPoint, LXtVector offset, LXtMatrix xfrm)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tins_GetDissolve (double *dissolve)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tins_ParticleDescription (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tins_ParticleArray (float *vector)
        { return LXe_NOTIMPL; }
};
#define LXxD_TableauInstance_Properties LxResult tins_Properties (ILxUnknownID vecstack)
#define LXxO_TableauInstance_Properties LXxD_TableauInstance_Properties LXx_OVERRIDE
#define LXxC_TableauInstance_Properties(c) LxResult c::tins_Properties (ILxUnknownID vecstack)
#define LXxD_TableauInstance_GetTransform LxResult tins_GetTransform (unsigned endPoint, LXtVector offset, LXtMatrix xfrm)
#define LXxO_TableauInstance_GetTransform LXxD_TableauInstance_GetTransform LXx_OVERRIDE
#define LXxC_TableauInstance_GetTransform(c) LxResult c::tins_GetTransform (unsigned endPoint, LXtVector offset, LXtMatrix xfrm)
#define LXxD_TableauInstance_GetDissolve LxResult tins_GetDissolve (double *dissolve)
#define LXxO_TableauInstance_GetDissolve LXxD_TableauInstance_GetDissolve LXx_OVERRIDE
#define LXxC_TableauInstance_GetDissolve(c) LxResult c::tins_GetDissolve (double *dissolve)
#define LXxD_TableauInstance_ParticleDescription LxResult tins_ParticleDescription (void **ppvObj)
#define LXxO_TableauInstance_ParticleDescription LXxD_TableauInstance_ParticleDescription LXx_OVERRIDE
#define LXxC_TableauInstance_ParticleDescription(c) LxResult c::tins_ParticleDescription (void **ppvObj)
#define LXxD_TableauInstance_ParticleArray LxResult tins_ParticleArray (float *vector)
#define LXxO_TableauInstance_ParticleArray LXxD_TableauInstance_ParticleArray LXx_OVERRIDE
#define LXxC_TableauInstance_ParticleArray(c) LxResult c::tins_ParticleArray (float *vector)
template <class T>
class CLxIfc_TableauInstance : public CLxInterface
{
    static LxResult
  Properties (LXtObjectID wcom, LXtObjectID vecstack)
  {
    LXCWxINST (CLxImpl_TableauInstance, loc);
    try {
      return loc->tins_Properties ((ILxUnknownID)vecstack);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetTransform (LXtObjectID wcom, unsigned endPoint, LXtVector offset, LXtMatrix xfrm)
  {
    LXCWxINST (CLxImpl_TableauInstance, loc);
    try {
      return loc->tins_GetTransform (endPoint,offset,xfrm);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetDissolve (LXtObjectID wcom, double *dissolve)
  {
    LXCWxINST (CLxImpl_TableauInstance, loc);
    try {
      return loc->tins_GetDissolve (dissolve);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ParticleDescription (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauInstance, loc);
    try {
      return loc->tins_ParticleDescription (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ParticleArray (LXtObjectID wcom, float *vector)
  {
    LXCWxINST (CLxImpl_TableauInstance, loc);
    try {
      return loc->tins_ParticleArray (vector);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauInstance vt;
public:
  CLxIfc_TableauInstance ()
  {
    vt.Properties = Properties;
    vt.GetTransform = GetTransform;
    vt.GetDissolve = GetDissolve;
    vt.ParticleDescription = ParticleDescription;
    vt.ParticleArray = ParticleArray;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauInstance;
  }
};
class CLxLoc_TableauInstance : public CLxLocalize<ILxTableauInstanceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauInstance() {_init();}
  CLxLoc_TableauInstance(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauInstance(const CLxLoc_TableauInstance &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauInstance;}
    LxResult
  Properties (ILxUnknownID vecstack)
  {
    return m_loc[0]->Properties (m_loc,(ILxUnknownID)vecstack);
  }
    LxResult
  GetTransform (unsigned endPoint, LXtVector offset, LXtMatrix xfrm)
  {
    return m_loc[0]->GetTransform (m_loc,endPoint,offset,xfrm);
  }
    LxResult
  GetDissolve (double *dissolve)
  {
    return m_loc[0]->GetDissolve (m_loc,dissolve);
  }
    LxResult
  ParticleDescription (void **ppvObj)
  {
    return m_loc[0]->ParticleDescription (m_loc,ppvObj);
  }
    CLxResult
  ParticleDescription (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ParticleDescription(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ParticleArray (float *vector)
  {
    return m_loc[0]->ParticleArray (m_loc,vector);
  }
};

class CLxImpl_TableauListener {
  public:
    virtual ~CLxImpl_TableauListener() {}
    virtual void
      tli_ChannelChange (ILxUnknownID tableau, ILxUnknownID item, int channel)
        { }
    virtual void
      tli_FlushElements (ILxUnknownID tableau)
        { }
    virtual void
      tli_TableauDestroy (ILxUnknownID tableau)
        { }
};
#define LXxD_TableauListener_ChannelChange void tli_ChannelChange (ILxUnknownID tableau, ILxUnknownID item, int channel)
#define LXxO_TableauListener_ChannelChange LXxD_TableauListener_ChannelChange LXx_OVERRIDE
#define LXxC_TableauListener_ChannelChange(c) void c::tli_ChannelChange (ILxUnknownID tableau, ILxUnknownID item, int channel)
#define LXxD_TableauListener_FlushElements void tli_FlushElements (ILxUnknownID tableau)
#define LXxO_TableauListener_FlushElements LXxD_TableauListener_FlushElements LXx_OVERRIDE
#define LXxC_TableauListener_FlushElements(c) void c::tli_FlushElements (ILxUnknownID tableau)
#define LXxD_TableauListener_TableauDestroy void tli_TableauDestroy (ILxUnknownID tableau)
#define LXxO_TableauListener_TableauDestroy LXxD_TableauListener_TableauDestroy LXx_OVERRIDE
#define LXxC_TableauListener_TableauDestroy(c) void c::tli_TableauDestroy (ILxUnknownID tableau)
template <class T>
class CLxIfc_TableauListener : public CLxInterface
{
    static void
  ChannelChange (LXtObjectID wcom, LXtObjectID tableau, LXtObjectID item, int channel)
  {
    LXCWxINST (CLxImpl_TableauListener, loc);
    loc->tli_ChannelChange ((ILxUnknownID)tableau,(ILxUnknownID)item,channel);
  }
    static void
  FlushElements (LXtObjectID wcom, LXtObjectID tableau)
  {
    LXCWxINST (CLxImpl_TableauListener, loc);
    loc->tli_FlushElements ((ILxUnknownID)tableau);
  }
    static void
  TableauDestroy (LXtObjectID wcom, LXtObjectID tableau)
  {
    LXCWxINST (CLxImpl_TableauListener, loc);
    loc->tli_TableauDestroy ((ILxUnknownID)tableau);
  }
  ILxTableauListener vt;
public:
  CLxIfc_TableauListener ()
  {
    vt.ChannelChange = ChannelChange;
    vt.FlushElements = FlushElements;
    vt.TableauDestroy = TableauDestroy;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauListener;
  }
};

class CLxLoc_NodalService : public CLxLocalizedService
{
public:
  ILxNodalServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_NodalService() {_init();set();}
 ~CLxLoc_NodalService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxNodalServiceID>(lx::GetGlobal(&lx::guid_NodalService));}
    int
  AddSampleChan (ILxUnknownID eval, ILxUnknownID item, int chanIndex, int *idxArray, int type)
  {
    return m_loc[0]->AddSampleChan (m_loc,(ILxUnknownID)eval,(ILxUnknownID)item,chanIndex,idxArray,type);
  }
    int
  AddSampleChanName (ILxUnknownID eval, ILxUnknownID item, const char *chanName, int *idxArray, int type)
  {
    return m_loc[0]->AddSampleChanName (m_loc,(ILxUnknownID)eval,(ILxUnknownID)item,chanName,idxArray,type);
  }
    double
  GetFloat (ILxUnknownID etor, int *idxArray, int index, double orig) const
  {
    return m_loc[0]->GetFloat (m_loc,(ILxUnknownID)etor,idxArray,index,orig);
  }
    int
  GetInt (ILxUnknownID etor, int *idxArray, int index, int orig) const
  {
    return m_loc[0]->GetInt (m_loc,(ILxUnknownID)etor,idxArray,index,orig);
  }
    void*
  GetValue (ILxUnknownID etor, int *idxArray, int index, void *orig) const
  {
    return m_loc[0]->GetValue (m_loc,(ILxUnknownID)etor,idxArray,index,orig);
  }
    int
  IsDriven (ILxUnknownID item, int chanIndex)
  {
    return m_loc[0]->IsDriven (m_loc,(ILxUnknownID)item,chanIndex);
  }
    int
  IsDrivenName (ILxUnknownID item, const char *chanName)
  {
    return m_loc[0]->IsDrivenName (m_loc,(ILxUnknownID)item,chanName);
  }
    int
  AnyDrivenChans (int *chans, int count)
  {
    return m_loc[0]->AnyDrivenChans (m_loc,chans,count);
  }
};

class CLxLoc_TableauService : public CLxLocalizedService
{
public:
  ILxTableauServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_TableauService() {_init();set();}
 ~CLxLoc_TableauService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxTableauServiceID>(lx::GetGlobal(&lx::guid_TableauService));}
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
  AllocVertex (void **ppvObj)
  {
    return m_loc[0]->AllocVertex (m_loc,ppvObj);
  }
    CLxResult
  AllocVertex (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AllocVertex(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  VertexFromFeatures (ILxUnknownID surfObj, ILxUnknownID vertex)
  {
    return m_loc[0]->VertexFromFeatures (m_loc,(ILxUnknownID)surfObj,(ILxUnknownID)vertex);
  }
};

class CLxImpl_Instanceable {
  public:
    virtual ~CLxImpl_Instanceable() {}
    virtual int
      instable_Compare (ILxUnknownID other)
        = 0;
    virtual LxResult
      instable_AddElements (ILxUnknownID tableau, ILxUnknownID instT0, ILxUnknownID instT1)
        { return LXe_NOTIMPL; }
    virtual LxResult
      instable_GetSurface (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_Instanceable_Compare int instable_Compare (ILxUnknownID other)
#define LXxO_Instanceable_Compare LXxD_Instanceable_Compare LXx_OVERRIDE
#define LXxC_Instanceable_Compare(c) int c::instable_Compare (ILxUnknownID other)
#define LXxD_Instanceable_AddElements LxResult instable_AddElements (ILxUnknownID tableau, ILxUnknownID instT0, ILxUnknownID instT1)
#define LXxO_Instanceable_AddElements LXxD_Instanceable_AddElements LXx_OVERRIDE
#define LXxC_Instanceable_AddElements(c) LxResult c::instable_AddElements (ILxUnknownID tableau, ILxUnknownID instT0, ILxUnknownID instT1)
#define LXxD_Instanceable_GetSurface LxResult instable_GetSurface (void **ppvObj)
#define LXxO_Instanceable_GetSurface LXxD_Instanceable_GetSurface LXx_OVERRIDE
#define LXxC_Instanceable_GetSurface(c) LxResult c::instable_GetSurface (void **ppvObj)
template <class T>
class CLxIfc_Instanceable : public CLxInterface
{
    static int
  Compare (LXtObjectID wcom, LXtObjectID other)
  {
    LXCWxINST (CLxImpl_Instanceable, loc);
    return loc->instable_Compare ((ILxUnknownID)other);
  }
    static LxResult
  AddElements (LXtObjectID wcom, LXtObjectID tableau, LXtObjectID instT0, LXtObjectID instT1)
  {
    LXCWxINST (CLxImpl_Instanceable, loc);
    try {
      return loc->instable_AddElements ((ILxUnknownID)tableau,(ILxUnknownID)instT0,(ILxUnknownID)instT1);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetSurface (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Instanceable, loc);
    try {
      return loc->instable_GetSurface (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxInstanceable vt;
public:
  CLxIfc_Instanceable ()
  {
    vt.Compare = Compare;
    vt.AddElements = AddElements;
    vt.GetSurface = GetSurface;
    vTable = &vt.iunk;
    iid = &lx::guid_Instanceable;
  }
};
class CLxLoc_Instanceable : public CLxLocalize<ILxInstanceableID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Instanceable() {_init();}
  CLxLoc_Instanceable(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Instanceable(const CLxLoc_Instanceable &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Instanceable;}
    int
  Compare (ILxUnknownID other)
  {
    return m_loc[0]->Compare (m_loc,(ILxUnknownID)other);
  }
    LxResult
  AddElements (ILxUnknownID tableau, ILxUnknownID instT0, ILxUnknownID instT1)
  {
    return m_loc[0]->AddElements (m_loc,(ILxUnknownID)tableau,(ILxUnknownID)instT0,(ILxUnknownID)instT1);
  }
    LxResult
  GetSurface (void **ppvObj)
  {
    return m_loc[0]->GetSurface (m_loc,ppvObj);
  }
    CLxResult
  GetSurface (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetSurface(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_TableauVolume {
  public:
    virtual ~CLxImpl_TableauVolume() {}
    virtual LxResult
      tvol_Bound (LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      tvol_FeatureCount (LXtID4 type)
        { return 0; }
    virtual LxResult
      tvol_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
        { return LXe_OUTOFBOUNDS; }
    virtual LxResult
      tvol_SetVertex (ILxUnknownID vdesc)
        { return LXe_NOTIMPL; }
    virtual int
      tvol_Type (void)
        = 0;
    virtual LxResult
      tvol_RenderInit (ILxUnknownID sv)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tvol_RaySample (ILxUnknownID densitySlice, ILxUnknownID shadingSlice, ILxUnknownID sv, ILxUnknownID raycastObj, ILxUnknownID raymarchObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tvol_RayCast (ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, double *dist, int *localShader)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tvol_Density (ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, const LXtVector pos, int worldPos, double *dens)
        { return LXe_NOTIMPL; }
};
#define LXxD_TableauVolume_Bound LxResult tvol_Bound (LXtTableauBox bbox)
#define LXxO_TableauVolume_Bound LXxD_TableauVolume_Bound LXx_OVERRIDE
#define LXxC_TableauVolume_Bound(c) LxResult c::tvol_Bound (LXtTableauBox bbox)
#define LXxD_TableauVolume_FeatureCount unsigned int tvol_FeatureCount (LXtID4 type)
#define LXxO_TableauVolume_FeatureCount LXxD_TableauVolume_FeatureCount LXx_OVERRIDE
#define LXxC_TableauVolume_FeatureCount(c) unsigned int c::tvol_FeatureCount (LXtID4 type)
#define LXxD_TableauVolume_FeatureByIndex LxResult tvol_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
#define LXxO_TableauVolume_FeatureByIndex LXxD_TableauVolume_FeatureByIndex LXx_OVERRIDE
#define LXxC_TableauVolume_FeatureByIndex(c) LxResult c::tvol_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
#define LXxD_TableauVolume_SetVertex LxResult tvol_SetVertex (ILxUnknownID vdesc)
#define LXxO_TableauVolume_SetVertex LXxD_TableauVolume_SetVertex LXx_OVERRIDE
#define LXxC_TableauVolume_SetVertex(c) LxResult c::tvol_SetVertex (ILxUnknownID vdesc)
#define LXxD_TableauVolume_Type int tvol_Type (void)
#define LXxO_TableauVolume_Type LXxD_TableauVolume_Type LXx_OVERRIDE
#define LXxC_TableauVolume_Type(c) int c::tvol_Type (void)
#define LXxD_TableauVolume_RenderInit LxResult tvol_RenderInit (ILxUnknownID sv)
#define LXxO_TableauVolume_RenderInit LXxD_TableauVolume_RenderInit LXx_OVERRIDE
#define LXxC_TableauVolume_RenderInit(c) LxResult c::tvol_RenderInit (ILxUnknownID sv)
#define LXxD_TableauVolume_RaySample LxResult tvol_RaySample (ILxUnknownID densitySlice, ILxUnknownID shadingSlice, ILxUnknownID sv, ILxUnknownID raycastObj, ILxUnknownID raymarchObj)
#define LXxO_TableauVolume_RaySample LXxD_TableauVolume_RaySample LXx_OVERRIDE
#define LXxC_TableauVolume_RaySample(c) LxResult c::tvol_RaySample (ILxUnknownID densitySlice, ILxUnknownID shadingSlice, ILxUnknownID sv, ILxUnknownID raycastObj, ILxUnknownID raymarchObj)
#define LXxD_TableauVolume_RayCast LxResult tvol_RayCast (ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, double *dist, int *localShader)
#define LXxO_TableauVolume_RayCast LXxD_TableauVolume_RayCast LXx_OVERRIDE
#define LXxC_TableauVolume_RayCast(c) LxResult c::tvol_RayCast (ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, double *dist, int *localShader)
#define LXxD_TableauVolume_Density LxResult tvol_Density (ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, const LXtVector pos, int worldPos, double *dens)
#define LXxO_TableauVolume_Density LXxD_TableauVolume_Density LXx_OVERRIDE
#define LXxC_TableauVolume_Density(c) LxResult c::tvol_Density (ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, const LXtVector pos, int worldPos, double *dens)
template <class T>
class CLxIfc_TableauVolume : public CLxInterface
{
    static LxResult
  Bound (LXtObjectID wcom, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_Bound (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  FeatureCount (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    return loc->tvol_FeatureCount (type);
  }
    static LxResult
  FeatureByIndex (LXtObjectID wcom, LXtID4 type, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_FeatureByIndex (type,index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetVertex (LXtObjectID wcom, LXtObjectID vdesc)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_SetVertex ((ILxUnknownID)vdesc);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    return loc->tvol_Type ();
  }
    static LxResult
  RenderInit (LXtObjectID wcom, LXtObjectID sv)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_RenderInit ((ILxUnknownID)sv);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RaySample (LXtObjectID wcom, LXtObjectID densitySlice, LXtObjectID shadingSlice, LXtObjectID sv, LXtObjectID raycastObj, LXtObjectID raymarchObj)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_RaySample ((ILxUnknownID)densitySlice,(ILxUnknownID)shadingSlice,(ILxUnknownID)sv,(ILxUnknownID)raycastObj,(ILxUnknownID)raymarchObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RayCast (LXtObjectID wcom, LXtObjectID densitySlice, LXtObjectID sv, LXtObjectID raycastObj, double *dist, int *localShader)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_RayCast ((ILxUnknownID)densitySlice,(ILxUnknownID)sv,(ILxUnknownID)raycastObj,dist,localShader);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Density (LXtObjectID wcom, LXtObjectID densitySlice, LXtObjectID sv, LXtObjectID raycastObj, const LXtVector pos, int worldPos, double *dens)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_Density ((ILxUnknownID)densitySlice,(ILxUnknownID)sv,(ILxUnknownID)raycastObj,pos,worldPos,dens);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauVolume vt;
public:
  CLxIfc_TableauVolume ()
  {
    vt.Bound = Bound;
    vt.FeatureCount = FeatureCount;
    vt.FeatureByIndex = FeatureByIndex;
    vt.SetVertex = SetVertex;
    vt.Type = Type;
    vt.RenderInit = RenderInit;
    vt.RaySample = RaySample;
    vt.RayCast = RayCast;
    vt.Density = Density;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauVolume;
  }
};
class CLxLoc_TableauVolume : public CLxLocalize<ILxTableauVolumeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauVolume() {_init();}
  CLxLoc_TableauVolume(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauVolume(const CLxLoc_TableauVolume &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauVolume;}
    LxResult
  Bound (LXtTableauBox bbox)
  {
    return m_loc[0]->Bound (m_loc,bbox);
  }
    unsigned int
  FeatureCount (LXtID4 type)
  {
    return m_loc[0]->FeatureCount (m_loc,type);
  }
    LxResult
  FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
  {
    return m_loc[0]->FeatureByIndex (m_loc,type,index,name);
  }
    LxResult
  SetVertex (ILxUnknownID vdesc)
  {
    return m_loc[0]->SetVertex (m_loc,(ILxUnknownID)vdesc);
  }
    int
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  RenderInit (ILxUnknownID sv)
  {
    return m_loc[0]->RenderInit (m_loc,(ILxUnknownID)sv);
  }
    LxResult
  RaySample (ILxUnknownID densitySlice, ILxUnknownID shadingSlice, ILxUnknownID sv, ILxUnknownID raycastObj, ILxUnknownID raymarchObj)
  {
    return m_loc[0]->RaySample (m_loc,(ILxUnknownID)densitySlice,(ILxUnknownID)shadingSlice,(ILxUnknownID)sv,(ILxUnknownID)raycastObj,(ILxUnknownID)raymarchObj);
  }
    LxResult
  RayCast (ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, double *dist, int *localShader)
  {
    return m_loc[0]->RayCast (m_loc,(ILxUnknownID)densitySlice,(ILxUnknownID)sv,(ILxUnknownID)raycastObj,dist,localShader);
  }
    LxResult
  Density (ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, const LXtVector pos, int worldPos, double *dens)
  {
    return m_loc[0]->Density (m_loc,(ILxUnknownID)densitySlice,(ILxUnknownID)sv,(ILxUnknownID)raycastObj,pos,worldPos,dens);
  }
};

class CLxLoc_ShaderSlice : public CLxLocalize<ILxShaderSliceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ShaderSlice() {_init();}
  CLxLoc_ShaderSlice(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ShaderSlice(const CLxLoc_ShaderSlice &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ShaderSlice;}
    LxResult
  Evaluate (ILxUnknownID vecstack)
  {
    return m_loc[0]->Evaluate (m_loc,(ILxUnknownID)vecstack);
  }
};

class CLxLoc_LightSample : public CLxLocalize<ILxLightSampleID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LightSample() {_init();}
  CLxLoc_LightSample(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LightSample(const CLxLoc_LightSample &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LightSample;}
    void
  Vertex (const float *vertex)
  {
    m_loc[0]->Vertex (m_loc,vertex);
  }
};

class CLxImpl_TableauSource1 {
  public:
    virtual ~CLxImpl_TableauSource1() {}
    virtual LxResult
      tsrc_Elements (ILxUnknownID tableau)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_Preview (ILxUnknownID tableau)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_Instance (ILxUnknownID tableau, ILxUnknownID instance)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_SubShader (ILxUnknownID tableau, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_PreviewUpdate (int chanIndex, int *update)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_GetCurves (ILxUnknownID tableau, ILxUnknownID tags, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_TableauSource1_Elements LxResult tsrc_Elements (ILxUnknownID tableau)
#define LXxO_TableauSource1_Elements LXxD_TableauSource1_Elements LXx_OVERRIDE
#define LXxC_TableauSource1_Elements(c) LxResult c::tsrc_Elements (ILxUnknownID tableau)
#define LXxD_TableauSource1_Preview LxResult tsrc_Preview (ILxUnknownID tableau)
#define LXxO_TableauSource1_Preview LXxD_TableauSource1_Preview LXx_OVERRIDE
#define LXxC_TableauSource1_Preview(c) LxResult c::tsrc_Preview (ILxUnknownID tableau)
#define LXxD_TableauSource1_Instance LxResult tsrc_Instance (ILxUnknownID tableau, ILxUnknownID instance)
#define LXxO_TableauSource1_Instance LXxD_TableauSource1_Instance LXx_OVERRIDE
#define LXxC_TableauSource1_Instance(c) LxResult c::tsrc_Instance (ILxUnknownID tableau, ILxUnknownID instance)
#define LXxD_TableauSource1_SubShader LxResult tsrc_SubShader (ILxUnknownID tableau, void **ppvObj)
#define LXxO_TableauSource1_SubShader LXxD_TableauSource1_SubShader LXx_OVERRIDE
#define LXxC_TableauSource1_SubShader(c) LxResult c::tsrc_SubShader (ILxUnknownID tableau, void **ppvObj)
#define LXxD_TableauSource1_PreviewUpdate LxResult tsrc_PreviewUpdate (int chanIndex, int *update)
#define LXxO_TableauSource1_PreviewUpdate LXxD_TableauSource1_PreviewUpdate LXx_OVERRIDE
#define LXxC_TableauSource1_PreviewUpdate(c) LxResult c::tsrc_PreviewUpdate (int chanIndex, int *update)
#define LXxD_TableauSource1_GetCurves LxResult tsrc_GetCurves (ILxUnknownID tableau, ILxUnknownID tags, void **ppvObj)
#define LXxO_TableauSource1_GetCurves LXxD_TableauSource1_GetCurves LXx_OVERRIDE
#define LXxC_TableauSource1_GetCurves(c) LxResult c::tsrc_GetCurves (ILxUnknownID tableau, ILxUnknownID tags, void **ppvObj)
template <class T>
class CLxIfc_TableauSource1 : public CLxInterface
{
    static LxResult
  Elements (LXtObjectID wcom, LXtObjectID tableau)
  {
    LXCWxINST (CLxImpl_TableauSource1, loc);
    try {
      return loc->tsrc_Elements ((ILxUnknownID)tableau);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Preview (LXtObjectID wcom, LXtObjectID tableau)
  {
    LXCWxINST (CLxImpl_TableauSource1, loc);
    try {
      return loc->tsrc_Preview ((ILxUnknownID)tableau);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Instance (LXtObjectID wcom, LXtObjectID tableau, LXtObjectID instance)
  {
    LXCWxINST (CLxImpl_TableauSource1, loc);
    try {
      return loc->tsrc_Instance ((ILxUnknownID)tableau,(ILxUnknownID)instance);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SubShader (LXtObjectID wcom, LXtObjectID tableau, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauSource1, loc);
    try {
      return loc->tsrc_SubShader ((ILxUnknownID)tableau,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PreviewUpdate (LXtObjectID wcom, int chanIndex, int *update)
  {
    LXCWxINST (CLxImpl_TableauSource1, loc);
    try {
      return loc->tsrc_PreviewUpdate (chanIndex,update);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetCurves (LXtObjectID wcom, LXtObjectID tableau, LXtObjectID tags, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauSource1, loc);
    try {
      return loc->tsrc_GetCurves ((ILxUnknownID)tableau,(ILxUnknownID)tags,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauSource1 vt;
public:
  CLxIfc_TableauSource1 ()
  {
    vt.Elements = Elements;
    vt.Preview = Preview;
    vt.Instance = Instance;
    vt.SubShader = SubShader;
    vt.PreviewUpdate = PreviewUpdate;
    vt.GetCurves = GetCurves;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauSource1;
  }
};

class CLxLoc_TableauElement : public CLxLocalize<ILxTableauElementID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauElement() {_init();}
  CLxLoc_TableauElement(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauElement(const CLxLoc_TableauElement &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauElement;}
    LxResult
  Bound (LXtTableauBox bbox)
  {
    return m_loc[0]->Bound (m_loc,bbox);
  }
    unsigned int
  FeatureCount (LXtID4 type)
  {
    return m_loc[0]->FeatureCount (m_loc,type);
  }
    LxResult
  FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
  {
    return m_loc[0]->FeatureByIndex (m_loc,type,index,name);
  }
    LxResult
  SetVertex (ILxUnknownID vdesc)
  {
    return m_loc[0]->SetVertex (m_loc,(ILxUnknownID)vdesc);
  }
};

class CLxLoc_Tableau : public CLxLocalize<ILxTableauID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Tableau() {_init();}
  CLxLoc_Tableau(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Tableau(const CLxLoc_Tableau &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Tableau;}
    LxResult
  Time (float *t0, float *interval)
  {
    return m_loc[0]->Time (m_loc,t0,interval);
  }
    LxResult
  AddElement (ILxUnknownID element, ILxUnknownID shader)
  {
    return m_loc[0]->AddElement (m_loc,(ILxUnknownID)element,(ILxUnknownID)shader);
  }
    LxResult
  AddInstance (ILxUnknownID inst, ILxUnknownID element, ILxUnknownID shader)
  {
    return m_loc[0]->AddInstance (m_loc,(ILxUnknownID)inst,(ILxUnknownID)element,(ILxUnknownID)shader);
  }
    LxResult
  Channels (unsigned type, void **ppvObj)
  {
    return m_loc[0]->Channels (m_loc,type,ppvObj);
  }
    CLxResult
  Channels (unsigned type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Channels(m_loc,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Visible (ILxUnknownID item)
  {
    return m_loc[0]->Visible (m_loc,(ILxUnknownID)item);
  }
    LxResult
  FindShader (ILxUnknownID item, ILxUnknownID tags, void **ppvObj)
  {
    return m_loc[0]->FindShader (m_loc,(ILxUnknownID)item,(ILxUnknownID)tags,ppvObj);
  }
    CLxResult
  FindShader (ILxUnknownID item, ILxUnknownID tags, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->FindShader(m_loc,(ILxUnknownID)item,(ILxUnknownID)tags,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    ILxUnknownID
  InstanceItem (void)
  {
    return (ILxUnknownID) m_loc[0]->InstanceItem (m_loc);
  }
    LxResult
  Update (ILxUnknownID visitor, int immediate)
  {
    return m_loc[0]->Update (m_loc,(ILxUnknownID)visitor,immediate);
  }
    LxResult
  UpdateAll (void)
  {
    return m_loc[0]->UpdateAll (m_loc);
  }
    LxResult
  EltNotify (ILxUnknownID element, int event)
  {
    return m_loc[0]->EltNotify (m_loc,(ILxUnknownID)element,event);
  }
    LxResult
  InstNotify (ILxUnknownID instance, int event)
  {
    return m_loc[0]->InstNotify (m_loc,(ILxUnknownID)instance,event);
  }
    LxResult
  AddInstanceItem (ILxUnknownID instItem, ILxUnknownID fromItem, ILxUnknownID inst, ILxUnknownID vdesc, const float *vertex)
  {
    return m_loc[0]->AddInstanceItem (m_loc,(ILxUnknownID)instItem,(ILxUnknownID)fromItem,(ILxUnknownID)inst,(ILxUnknownID)vdesc,vertex);
  }
    LxResult
  AddInstanceableElement (ILxUnknownID elt, ILxUnknownID tags)
  {
    return m_loc[0]->AddInstanceableElement (m_loc,(ILxUnknownID)elt,(ILxUnknownID)tags);
  }
};

class CLxImpl_TableauSource {
  public:
    virtual ~CLxImpl_TableauSource() {}
    virtual LxResult
      tsrc_Elements (ILxUnknownID tableau)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_Preview (ILxUnknownID tableau)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_Instance (ILxUnknownID tableau, ILxUnknownID instance)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_SubShader (ILxUnknownID tableau, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_PreviewUpdate (int chanIndex, int *update)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_GetCurves (ILxUnknownID tableau, ILxUnknownID tags, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_ElementType (int type, int *supported)
        { return LXe_NOTIMPL; }
};
#define LXxD_TableauSource_Elements LxResult tsrc_Elements (ILxUnknownID tableau)
#define LXxO_TableauSource_Elements LXxD_TableauSource_Elements LXx_OVERRIDE
#define LXxC_TableauSource_Elements(c) LxResult c::tsrc_Elements (ILxUnknownID tableau)
#define LXxD_TableauSource_Preview LxResult tsrc_Preview (ILxUnknownID tableau)
#define LXxO_TableauSource_Preview LXxD_TableauSource_Preview LXx_OVERRIDE
#define LXxC_TableauSource_Preview(c) LxResult c::tsrc_Preview (ILxUnknownID tableau)
#define LXxD_TableauSource_Instance LxResult tsrc_Instance (ILxUnknownID tableau, ILxUnknownID instance)
#define LXxO_TableauSource_Instance LXxD_TableauSource_Instance LXx_OVERRIDE
#define LXxC_TableauSource_Instance(c) LxResult c::tsrc_Instance (ILxUnknownID tableau, ILxUnknownID instance)
#define LXxD_TableauSource_SubShader LxResult tsrc_SubShader (ILxUnknownID tableau, void **ppvObj)
#define LXxO_TableauSource_SubShader LXxD_TableauSource_SubShader LXx_OVERRIDE
#define LXxC_TableauSource_SubShader(c) LxResult c::tsrc_SubShader (ILxUnknownID tableau, void **ppvObj)
#define LXxD_TableauSource_PreviewUpdate LxResult tsrc_PreviewUpdate (int chanIndex, int *update)
#define LXxO_TableauSource_PreviewUpdate LXxD_TableauSource_PreviewUpdate LXx_OVERRIDE
#define LXxC_TableauSource_PreviewUpdate(c) LxResult c::tsrc_PreviewUpdate (int chanIndex, int *update)
#define LXxD_TableauSource_GetCurves LxResult tsrc_GetCurves (ILxUnknownID tableau, ILxUnknownID tags, void **ppvObj)
#define LXxO_TableauSource_GetCurves LXxD_TableauSource_GetCurves LXx_OVERRIDE
#define LXxC_TableauSource_GetCurves(c) LxResult c::tsrc_GetCurves (ILxUnknownID tableau, ILxUnknownID tags, void **ppvObj)
#define LXxD_TableauSource_ElementType LxResult tsrc_ElementType (int type, int *supported)
#define LXxO_TableauSource_ElementType LXxD_TableauSource_ElementType LXx_OVERRIDE
#define LXxC_TableauSource_ElementType(c) LxResult c::tsrc_ElementType (int type, int *supported)
template <class T>
class CLxIfc_TableauSource : public CLxInterface
{
    static LxResult
  Elements (LXtObjectID wcom, LXtObjectID tableau)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_Elements ((ILxUnknownID)tableau);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Preview (LXtObjectID wcom, LXtObjectID tableau)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_Preview ((ILxUnknownID)tableau);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Instance (LXtObjectID wcom, LXtObjectID tableau, LXtObjectID instance)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_Instance ((ILxUnknownID)tableau,(ILxUnknownID)instance);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SubShader (LXtObjectID wcom, LXtObjectID tableau, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_SubShader ((ILxUnknownID)tableau,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PreviewUpdate (LXtObjectID wcom, int chanIndex, int *update)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_PreviewUpdate (chanIndex,update);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetCurves (LXtObjectID wcom, LXtObjectID tableau, LXtObjectID tags, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_GetCurves ((ILxUnknownID)tableau,(ILxUnknownID)tags,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ElementType (LXtObjectID wcom, int type, int *supported)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_ElementType (type,supported);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauSource vt;
public:
  CLxIfc_TableauSource ()
  {
    vt.Elements = Elements;
    vt.Preview = Preview;
    vt.Instance = Instance;
    vt.SubShader = SubShader;
    vt.PreviewUpdate = PreviewUpdate;
    vt.GetCurves = GetCurves;
    vt.ElementType = ElementType;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauSource;
  }
};
class CLxLoc_TableauSource : public CLxLocalize<ILxTableauSourceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauSource() {_init();}
  CLxLoc_TableauSource(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauSource(const CLxLoc_TableauSource &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauSource;}
    LxResult
  Elements (ILxUnknownID tableau)
  {
    return m_loc[0]->Elements (m_loc,(ILxUnknownID)tableau);
  }
    LxResult
  Preview (ILxUnknownID tableau)
  {
    return m_loc[0]->Preview (m_loc,(ILxUnknownID)tableau);
  }
    LxResult
  Instance (ILxUnknownID tableau, ILxUnknownID instance)
  {
    return m_loc[0]->Instance (m_loc,(ILxUnknownID)tableau,(ILxUnknownID)instance);
  }
    LxResult
  SubShader (ILxUnknownID tableau, void **ppvObj)
  {
    return m_loc[0]->SubShader (m_loc,(ILxUnknownID)tableau,ppvObj);
  }
    CLxResult
  SubShader (ILxUnknownID tableau, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SubShader(m_loc,(ILxUnknownID)tableau,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  PreviewUpdate (int chanIndex, int *update)
  {
    return m_loc[0]->PreviewUpdate (m_loc,chanIndex,update);
  }
    LxResult
  GetCurves (ILxUnknownID tableau, ILxUnknownID tags, void **ppvObj)
  {
    return m_loc[0]->GetCurves (m_loc,(ILxUnknownID)tableau,(ILxUnknownID)tags,ppvObj);
  }
    CLxResult
  GetCurves (ILxUnknownID tableau, ILxUnknownID tags, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetCurves(m_loc,(ILxUnknownID)tableau,(ILxUnknownID)tags,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ElementType (int type, int *supported)
  {
    return m_loc[0]->ElementType (m_loc,type,supported);
  }
};

class CLxImpl_TableauProxy {
  public:
    virtual ~CLxImpl_TableauProxy() {}
    virtual LxResult
      tpro_Bound (LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      tpro_FeatureCount (LXtID4 type)
        { return 0; }
    virtual LxResult
      tpro_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
        { return LXe_OUTOFBOUNDS; }
    virtual LxResult
      tpro_SetVertex (ILxUnknownID vdesc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tpro_Sample (const LXtTableauBox bbox, ILxUnknownID tableau)
        { return LXe_NOTIMPL; }
};
#define LXxD_TableauProxy_Bound LxResult tpro_Bound (LXtTableauBox bbox)
#define LXxO_TableauProxy_Bound LXxD_TableauProxy_Bound LXx_OVERRIDE
#define LXxC_TableauProxy_Bound(c) LxResult c::tpro_Bound (LXtTableauBox bbox)
#define LXxD_TableauProxy_FeatureCount unsigned int tpro_FeatureCount (LXtID4 type)
#define LXxO_TableauProxy_FeatureCount LXxD_TableauProxy_FeatureCount LXx_OVERRIDE
#define LXxC_TableauProxy_FeatureCount(c) unsigned int c::tpro_FeatureCount (LXtID4 type)
#define LXxD_TableauProxy_FeatureByIndex LxResult tpro_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
#define LXxO_TableauProxy_FeatureByIndex LXxD_TableauProxy_FeatureByIndex LXx_OVERRIDE
#define LXxC_TableauProxy_FeatureByIndex(c) LxResult c::tpro_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
#define LXxD_TableauProxy_SetVertex LxResult tpro_SetVertex (ILxUnknownID vdesc)
#define LXxO_TableauProxy_SetVertex LXxD_TableauProxy_SetVertex LXx_OVERRIDE
#define LXxC_TableauProxy_SetVertex(c) LxResult c::tpro_SetVertex (ILxUnknownID vdesc)
#define LXxD_TableauProxy_Sample LxResult tpro_Sample (const LXtTableauBox bbox, ILxUnknownID tableau)
#define LXxO_TableauProxy_Sample LXxD_TableauProxy_Sample LXx_OVERRIDE
#define LXxC_TableauProxy_Sample(c) LxResult c::tpro_Sample (const LXtTableauBox bbox, ILxUnknownID tableau)
template <class T>
class CLxIfc_TableauProxy : public CLxInterface
{
    static LxResult
  Bound (LXtObjectID wcom, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TableauProxy, loc);
    try {
      return loc->tpro_Bound (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  FeatureCount (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_TableauProxy, loc);
    return loc->tpro_FeatureCount (type);
  }
    static LxResult
  FeatureByIndex (LXtObjectID wcom, LXtID4 type, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_TableauProxy, loc);
    try {
      return loc->tpro_FeatureByIndex (type,index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetVertex (LXtObjectID wcom, LXtObjectID vdesc)
  {
    LXCWxINST (CLxImpl_TableauProxy, loc);
    try {
      return loc->tpro_SetVertex ((ILxUnknownID)vdesc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Sample (LXtObjectID wcom, const LXtTableauBox bbox, LXtObjectID tableau)
  {
    LXCWxINST (CLxImpl_TableauProxy, loc);
    try {
      return loc->tpro_Sample (bbox,(ILxUnknownID)tableau);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauProxy vt;
public:
  CLxIfc_TableauProxy ()
  {
    vt.Bound = Bound;
    vt.FeatureCount = FeatureCount;
    vt.FeatureByIndex = FeatureByIndex;
    vt.SetVertex = SetVertex;
    vt.Sample = Sample;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauProxy;
  }
};
class CLxLoc_TableauProxy : public CLxLocalize<ILxTableauProxyID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauProxy() {_init();}
  CLxLoc_TableauProxy(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauProxy(const CLxLoc_TableauProxy &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauProxy;}
    LxResult
  Bound (LXtTableauBox bbox)
  {
    return m_loc[0]->Bound (m_loc,bbox);
  }
    unsigned int
  FeatureCount (LXtID4 type)
  {
    return m_loc[0]->FeatureCount (m_loc,type);
  }
    LxResult
  FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
  {
    return m_loc[0]->FeatureByIndex (m_loc,type,index,name);
  }
    LxResult
  SetVertex (ILxUnknownID vdesc)
  {
    return m_loc[0]->SetVertex (m_loc,(ILxUnknownID)vdesc);
  }
    LxResult
  Sample (const LXtTableauBox bbox, ILxUnknownID tableau)
  {
    return m_loc[0]->Sample (m_loc,bbox,(ILxUnknownID)tableau);
  }
};

class CLxImpl_TableauShader {
  public:
    virtual ~CLxImpl_TableauShader() {}
    virtual LxResult
      tsha_Select (ILxUnknownID teElt, ILxUnknownID tvDesc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsha_Slice (ILxUnknownID vtOutput, ILxUnknownID tvDesc, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_TableauShader_Select LxResult tsha_Select (ILxUnknownID teElt, ILxUnknownID tvDesc)
#define LXxO_TableauShader_Select LXxD_TableauShader_Select LXx_OVERRIDE
#define LXxC_TableauShader_Select(c) LxResult c::tsha_Select (ILxUnknownID teElt, ILxUnknownID tvDesc)
#define LXxD_TableauShader_Slice LxResult tsha_Slice (ILxUnknownID vtOutput, ILxUnknownID tvDesc, void **ppvObj)
#define LXxO_TableauShader_Slice LXxD_TableauShader_Slice LXx_OVERRIDE
#define LXxC_TableauShader_Slice(c) LxResult c::tsha_Slice (ILxUnknownID vtOutput, ILxUnknownID tvDesc, void **ppvObj)
template <class T>
class CLxIfc_TableauShader : public CLxInterface
{
    static LxResult
  Select (LXtObjectID wcom, LXtObjectID teElt, LXtObjectID tvDesc)
  {
    LXCWxINST (CLxImpl_TableauShader, loc);
    try {
      return loc->tsha_Select ((ILxUnknownID)teElt,(ILxUnknownID)tvDesc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Slice (LXtObjectID wcom, LXtObjectID vtOutput, LXtObjectID tvDesc, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauShader, loc);
    try {
      return loc->tsha_Slice ((ILxUnknownID)vtOutput,(ILxUnknownID)tvDesc,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauShader vt;
public:
  CLxIfc_TableauShader ()
  {
    vt.Select = Select;
    vt.Slice = Slice;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauShader;
  }
};
class CLxLoc_TableauShader : public CLxLocalize<ILxTableauShaderID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauShader() {_init();}
  CLxLoc_TableauShader(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauShader(const CLxLoc_TableauShader &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauShader;}
    LxResult
  Select (ILxUnknownID teElt, ILxUnknownID tvDesc)
  {
    return m_loc[0]->Select (m_loc,(ILxUnknownID)teElt,(ILxUnknownID)tvDesc);
  }
    LxResult
  Slice (ILxUnknownID vtOutput, ILxUnknownID tvDesc, void **ppvObj)
  {
    return m_loc[0]->Slice (m_loc,(ILxUnknownID)vtOutput,(ILxUnknownID)tvDesc,ppvObj);
  }
    CLxResult
  Slice (ILxUnknownID vtOutput, ILxUnknownID tvDesc, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Slice(m_loc,(ILxUnknownID)vtOutput,(ILxUnknownID)tvDesc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};


class CLxImpl_TableauSurface {
  public:
    virtual ~CLxImpl_TableauSurface() {}
    virtual LxResult
      tsrf_Bound (LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      tsrf_FeatureCount (LXtID4 type)
        { return 0; }
    virtual LxResult
      tsrf_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
        { return LXe_OUTOFBOUNDS; }
    virtual LxResult
      tsrf_SetVertex (ILxUnknownID vdesc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrf_Sample (const LXtTableauBox bbox, float scale, ILxUnknownID trisoup)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrf_Padding (float *dist)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrf_SegmentBox (unsigned int segID, LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
};
#define LXxD_TableauSurface_Bound LxResult tsrf_Bound (LXtTableauBox bbox)
#define LXxO_TableauSurface_Bound LXxD_TableauSurface_Bound LXx_OVERRIDE
#define LXxC_TableauSurface_Bound(c) LxResult c::tsrf_Bound (LXtTableauBox bbox)
#define LXxD_TableauSurface_FeatureCount unsigned int tsrf_FeatureCount (LXtID4 type)
#define LXxO_TableauSurface_FeatureCount LXxD_TableauSurface_FeatureCount LXx_OVERRIDE
#define LXxC_TableauSurface_FeatureCount(c) unsigned int c::tsrf_FeatureCount (LXtID4 type)
#define LXxD_TableauSurface_FeatureByIndex LxResult tsrf_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
#define LXxO_TableauSurface_FeatureByIndex LXxD_TableauSurface_FeatureByIndex LXx_OVERRIDE
#define LXxC_TableauSurface_FeatureByIndex(c) LxResult c::tsrf_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
#define LXxD_TableauSurface_SetVertex LxResult tsrf_SetVertex (ILxUnknownID vdesc)
#define LXxO_TableauSurface_SetVertex LXxD_TableauSurface_SetVertex LXx_OVERRIDE
#define LXxC_TableauSurface_SetVertex(c) LxResult c::tsrf_SetVertex (ILxUnknownID vdesc)
#define LXxD_TableauSurface_Sample LxResult tsrf_Sample (const LXtTableauBox bbox, float scale, ILxUnknownID trisoup)
#define LXxO_TableauSurface_Sample LXxD_TableauSurface_Sample LXx_OVERRIDE
#define LXxC_TableauSurface_Sample(c) LxResult c::tsrf_Sample (const LXtTableauBox bbox, float scale, ILxUnknownID trisoup)
#define LXxD_TableauSurface_Padding LxResult tsrf_Padding (float *dist)
#define LXxO_TableauSurface_Padding LXxD_TableauSurface_Padding LXx_OVERRIDE
#define LXxC_TableauSurface_Padding(c) LxResult c::tsrf_Padding (float *dist)
#define LXxD_TableauSurface_SegmentBox LxResult tsrf_SegmentBox (unsigned int segID, LXtTableauBox bbox)
#define LXxO_TableauSurface_SegmentBox LXxD_TableauSurface_SegmentBox LXx_OVERRIDE
#define LXxC_TableauSurface_SegmentBox(c) LxResult c::tsrf_SegmentBox (unsigned int segID, LXtTableauBox bbox)
template <class T>
class CLxIfc_TableauSurface : public CLxInterface
{
    static LxResult
  Bound (LXtObjectID wcom, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_Bound (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  FeatureCount (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    return loc->tsrf_FeatureCount (type);
  }
    static LxResult
  FeatureByIndex (LXtObjectID wcom, LXtID4 type, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_FeatureByIndex (type,index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetVertex (LXtObjectID wcom, LXtObjectID vdesc)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_SetVertex ((ILxUnknownID)vdesc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Sample (LXtObjectID wcom, const LXtTableauBox bbox, float scale, LXtObjectID trisoup)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_Sample (bbox,scale,(ILxUnknownID)trisoup);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Padding (LXtObjectID wcom, float *dist)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_Padding (dist);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SegmentBox (LXtObjectID wcom, unsigned int segID, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_SegmentBox (segID,bbox);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauSurface vt;
public:
  CLxIfc_TableauSurface ()
  {
    vt.Bound = Bound;
    vt.FeatureCount = FeatureCount;
    vt.FeatureByIndex = FeatureByIndex;
    vt.SetVertex = SetVertex;
    vt.Sample = Sample;
    vt.Padding = Padding;
    vt.SegmentBox = SegmentBox;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauSurface;
  }
};
class CLxLoc_TableauSurface : public CLxLocalize<ILxTableauSurfaceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauSurface() {_init();}
  CLxLoc_TableauSurface(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauSurface(const CLxLoc_TableauSurface &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauSurface;}
    LxResult
  Bound (LXtTableauBox bbox)
  {
    return m_loc[0]->Bound (m_loc,bbox);
  }
    unsigned int
  FeatureCount (LXtID4 type)
  {
    return m_loc[0]->FeatureCount (m_loc,type);
  }
    LxResult
  FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
  {
    return m_loc[0]->FeatureByIndex (m_loc,type,index,name);
  }
    LxResult
  SetVertex (ILxUnknownID vdesc)
  {
    return m_loc[0]->SetVertex (m_loc,(ILxUnknownID)vdesc);
  }
    LxResult
  Sample (const LXtTableauBox bbox, float scale, ILxUnknownID trisoup)
  {
    return m_loc[0]->Sample (m_loc,bbox,scale,(ILxUnknownID)trisoup);
  }
    LxResult
  Padding (float *dist)
  {
    return m_loc[0]->Padding (m_loc,dist);
  }
    LxResult
  SegmentBox (unsigned int segID, LXtTableauBox bbox)
  {
    return m_loc[0]->SegmentBox (m_loc,segID,bbox);
  }
};

class CLxImpl_TriangleSoup {
  public:
    virtual ~CLxImpl_TriangleSoup() {}
    virtual unsigned int
      soup_TestBox (const LXtTableauBox bbox)
        { return 1; }
    virtual LxResult
      soup_Segment (unsigned int segID, unsigned int type)
        { return LXe_TRUE; }
    virtual LxResult
      soup_Vertex (const float *vertex, unsigned int *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      soup_Polygon (unsigned int v0, unsigned int v1, unsigned int v2)
        { return LXe_NOTIMPL; }
    virtual void
      soup_Connect (unsigned int type)
        { }
};
#define LXxD_TriangleSoup_TestBox unsigned int soup_TestBox (const LXtTableauBox bbox)
#define LXxO_TriangleSoup_TestBox LXxD_TriangleSoup_TestBox LXx_OVERRIDE
#define LXxC_TriangleSoup_TestBox(c) unsigned int c::soup_TestBox (const LXtTableauBox bbox)
#define LXxD_TriangleSoup_Segment LxResult soup_Segment (unsigned int segID, unsigned int type)
#define LXxO_TriangleSoup_Segment LXxD_TriangleSoup_Segment LXx_OVERRIDE
#define LXxC_TriangleSoup_Segment(c) LxResult c::soup_Segment (unsigned int segID, unsigned int type)
#define LXxD_TriangleSoup_Vertex LxResult soup_Vertex (const float *vertex, unsigned int *index)
#define LXxO_TriangleSoup_Vertex LXxD_TriangleSoup_Vertex LXx_OVERRIDE
#define LXxC_TriangleSoup_Vertex(c) LxResult c::soup_Vertex (const float *vertex, unsigned int *index)
#define LXxD_TriangleSoup_Polygon LxResult soup_Polygon (unsigned int v0, unsigned int v1, unsigned int v2)
#define LXxO_TriangleSoup_Polygon LXxD_TriangleSoup_Polygon LXx_OVERRIDE
#define LXxC_TriangleSoup_Polygon(c) LxResult c::soup_Polygon (unsigned int v0, unsigned int v1, unsigned int v2)
#define LXxD_TriangleSoup_Connect void soup_Connect (unsigned int type)
#define LXxO_TriangleSoup_Connect LXxD_TriangleSoup_Connect LXx_OVERRIDE
#define LXxC_TriangleSoup_Connect(c) void c::soup_Connect (unsigned int type)
template <class T>
class CLxIfc_TriangleSoup : public CLxInterface
{
    static unsigned int
  TestBox (LXtObjectID wcom, const LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TriangleSoup, loc);
    return loc->soup_TestBox (bbox);
  }
    static LxResult
  Segment (LXtObjectID wcom, unsigned int segID, unsigned int type)
  {
    LXCWxINST (CLxImpl_TriangleSoup, loc);
    try {
      return loc->soup_Segment (segID,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Vertex (LXtObjectID wcom, const float *vertex, unsigned int *index)
  {
    LXCWxINST (CLxImpl_TriangleSoup, loc);
    try {
      return loc->soup_Vertex (vertex,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Polygon (LXtObjectID wcom, unsigned int v0, unsigned int v1, unsigned int v2)
  {
    LXCWxINST (CLxImpl_TriangleSoup, loc);
    try {
      return loc->soup_Polygon (v0,v1,v2);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Connect (LXtObjectID wcom, unsigned int type)
  {
    LXCWxINST (CLxImpl_TriangleSoup, loc);
    loc->soup_Connect (type);
  }
  ILxTriangleSoup vt;
public:
  CLxIfc_TriangleSoup ()
  {
    vt.TestBox = TestBox;
    vt.Segment = Segment;
    vt.Vertex = Vertex;
    vt.Polygon = Polygon;
    vt.Connect = Connect;
    vTable = &vt.iunk;
    iid = &lx::guid_TriangleSoup;
  }
};
class CLxLoc_TriangleSoup : public CLxLocalize<ILxTriangleSoupID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TriangleSoup() {_init();}
  CLxLoc_TriangleSoup(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TriangleSoup(const CLxLoc_TriangleSoup &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TriangleSoup;}
    unsigned int
  TestBox (const LXtTableauBox bbox)
  {
    return m_loc[0]->TestBox (m_loc,bbox);
  }
    LxResult
  Segment (unsigned int segID, unsigned int type)
  {
    return m_loc[0]->Segment (m_loc,segID,type);
  }
    LxResult
  Vertex (const float *vertex, unsigned int *index)
  {
    return m_loc[0]->Vertex (m_loc,vertex,index);
  }
    LxResult
  Polygon (unsigned int v0, unsigned int v1, unsigned int v2)
  {
    return m_loc[0]->Polygon (m_loc,v0,v1,v2);
  }
    void
  Connect (unsigned int type)
  {
    m_loc[0]->Connect (m_loc,type);
  }
};

class CLxImpl_TableauSurface1 {
  public:
    virtual ~CLxImpl_TableauSurface1() {}
    virtual LxResult
      tsrf_Bound (LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      tsrf_FeatureCount (LXtID4 type)
        { return 0; }
    virtual LxResult
      tsrf_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
        { return LXe_OUTOFBOUNDS; }
    virtual LxResult
      tsrf_SetVertex (ILxUnknownID vdesc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrf_Sample (const LXtTableauBox bbox, float scale, ILxUnknownID trisoup)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrf_Padding (float *dist)
        { return LXe_NOTIMPL; }
};
#define LXxD_TableauSurface1_Bound LxResult tsrf_Bound (LXtTableauBox bbox)
#define LXxO_TableauSurface1_Bound LXxD_TableauSurface1_Bound LXx_OVERRIDE
#define LXxC_TableauSurface1_Bound(c) LxResult c::tsrf_Bound (LXtTableauBox bbox)
#define LXxD_TableauSurface1_FeatureCount unsigned int tsrf_FeatureCount (LXtID4 type)
#define LXxO_TableauSurface1_FeatureCount LXxD_TableauSurface1_FeatureCount LXx_OVERRIDE
#define LXxC_TableauSurface1_FeatureCount(c) unsigned int c::tsrf_FeatureCount (LXtID4 type)
#define LXxD_TableauSurface1_FeatureByIndex LxResult tsrf_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
#define LXxO_TableauSurface1_FeatureByIndex LXxD_TableauSurface1_FeatureByIndex LXx_OVERRIDE
#define LXxC_TableauSurface1_FeatureByIndex(c) LxResult c::tsrf_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
#define LXxD_TableauSurface1_SetVertex LxResult tsrf_SetVertex (ILxUnknownID vdesc)
#define LXxO_TableauSurface1_SetVertex LXxD_TableauSurface1_SetVertex LXx_OVERRIDE
#define LXxC_TableauSurface1_SetVertex(c) LxResult c::tsrf_SetVertex (ILxUnknownID vdesc)
#define LXxD_TableauSurface1_Sample LxResult tsrf_Sample (const LXtTableauBox bbox, float scale, ILxUnknownID trisoup)
#define LXxO_TableauSurface1_Sample LXxD_TableauSurface1_Sample LXx_OVERRIDE
#define LXxC_TableauSurface1_Sample(c) LxResult c::tsrf_Sample (const LXtTableauBox bbox, float scale, ILxUnknownID trisoup)
#define LXxD_TableauSurface1_Padding LxResult tsrf_Padding (float *dist)
#define LXxO_TableauSurface1_Padding LXxD_TableauSurface1_Padding LXx_OVERRIDE
#define LXxC_TableauSurface1_Padding(c) LxResult c::tsrf_Padding (float *dist)
template <class T>
class CLxIfc_TableauSurface1 : public CLxInterface
{
    static LxResult
  Bound (LXtObjectID wcom, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TableauSurface1, loc);
    try {
      return loc->tsrf_Bound (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  FeatureCount (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_TableauSurface1, loc);
    return loc->tsrf_FeatureCount (type);
  }
    static LxResult
  FeatureByIndex (LXtObjectID wcom, LXtID4 type, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_TableauSurface1, loc);
    try {
      return loc->tsrf_FeatureByIndex (type,index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetVertex (LXtObjectID wcom, LXtObjectID vdesc)
  {
    LXCWxINST (CLxImpl_TableauSurface1, loc);
    try {
      return loc->tsrf_SetVertex ((ILxUnknownID)vdesc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Sample (LXtObjectID wcom, const LXtTableauBox bbox, float scale, LXtObjectID trisoup)
  {
    LXCWxINST (CLxImpl_TableauSurface1, loc);
    try {
      return loc->tsrf_Sample (bbox,scale,(ILxUnknownID)trisoup);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Padding (LXtObjectID wcom, float *dist)
  {
    LXCWxINST (CLxImpl_TableauSurface1, loc);
    try {
      return loc->tsrf_Padding (dist);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauSurface1 vt;
public:
  CLxIfc_TableauSurface1 ()
  {
    vt.Bound = Bound;
    vt.FeatureCount = FeatureCount;
    vt.FeatureByIndex = FeatureByIndex;
    vt.SetVertex = SetVertex;
    vt.Sample = Sample;
    vt.Padding = Padding;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauSurface1;
  }
};
class CLxLoc_TableauSurface1 : public CLxLocalize<ILxTableauSurface1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauSurface1() {_init();}
  CLxLoc_TableauSurface1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauSurface1(const CLxLoc_TableauSurface1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauSurface1;}
    LxResult
  Bound (LXtTableauBox bbox)
  {
    return m_loc[0]->Bound (m_loc,bbox);
  }
    unsigned int
  FeatureCount (LXtID4 type)
  {
    return m_loc[0]->FeatureCount (m_loc,type);
  }
    LxResult
  FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
  {
    return m_loc[0]->FeatureByIndex (m_loc,type,index,name);
  }
    LxResult
  SetVertex (ILxUnknownID vdesc)
  {
    return m_loc[0]->SetVertex (m_loc,(ILxUnknownID)vdesc);
  }
    LxResult
  Sample (const LXtTableauBox bbox, float scale, ILxUnknownID trisoup)
  {
    return m_loc[0]->Sample (m_loc,bbox,scale,(ILxUnknownID)trisoup);
  }
    LxResult
  Padding (float *dist)
  {
    return m_loc[0]->Padding (m_loc,dist);
  }
};


class CLxImpl_TableauLight {
  public:
    virtual ~CLxImpl_TableauLight() {}
    virtual LxResult
      tlgt_Bound (LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      tlgt_FeatureCount (LXtID4 type)
        { return 0; }
    virtual LxResult
      tlgt_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
        { return LXe_OUTOFBOUNDS; }
    virtual LxResult
      tlgt_SetVertex (ILxUnknownID vdesc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tlgt_Sample (float u, float v, const LXtFVector dir, LXtFVector wPos, LXtFVector oPos, LXtFVector norm, float t)
        { return LXe_NOTIMPL; }
    virtual int
      tlgt_Geometry (void *gc)
        = 0;
    virtual LxResult
      tlgt_Emit (unsigned int nPhotons, int offset, ILxUnknownID slice, LXtSampleVectorID sv)
        { return LXe_NOTIMPL; }
    virtual int
      tlgt_ShadowMap (void **ppvObj)
        = 0;
};
#define LXxD_TableauLight_Bound LxResult tlgt_Bound (LXtTableauBox bbox)
#define LXxO_TableauLight_Bound LXxD_TableauLight_Bound LXx_OVERRIDE
#define LXxC_TableauLight_Bound(c) LxResult c::tlgt_Bound (LXtTableauBox bbox)
#define LXxD_TableauLight_FeatureCount unsigned int tlgt_FeatureCount (LXtID4 type)
#define LXxO_TableauLight_FeatureCount LXxD_TableauLight_FeatureCount LXx_OVERRIDE
#define LXxC_TableauLight_FeatureCount(c) unsigned int c::tlgt_FeatureCount (LXtID4 type)
#define LXxD_TableauLight_FeatureByIndex LxResult tlgt_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
#define LXxO_TableauLight_FeatureByIndex LXxD_TableauLight_FeatureByIndex LXx_OVERRIDE
#define LXxC_TableauLight_FeatureByIndex(c) LxResult c::tlgt_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
#define LXxD_TableauLight_SetVertex LxResult tlgt_SetVertex (ILxUnknownID vdesc)
#define LXxO_TableauLight_SetVertex LXxD_TableauLight_SetVertex LXx_OVERRIDE
#define LXxC_TableauLight_SetVertex(c) LxResult c::tlgt_SetVertex (ILxUnknownID vdesc)
#define LXxD_TableauLight_Sample LxResult tlgt_Sample (float u, float v, const LXtFVector dir, LXtFVector wPos, LXtFVector oPos, LXtFVector norm, float t)
#define LXxO_TableauLight_Sample LXxD_TableauLight_Sample LXx_OVERRIDE
#define LXxC_TableauLight_Sample(c) LxResult c::tlgt_Sample (float u, float v, const LXtFVector dir, LXtFVector wPos, LXtFVector oPos, LXtFVector norm, float t)
#define LXxD_TableauLight_Geometry int tlgt_Geometry (void *gc)
#define LXxO_TableauLight_Geometry LXxD_TableauLight_Geometry LXx_OVERRIDE
#define LXxC_TableauLight_Geometry(c) int c::tlgt_Geometry (void *gc)
#define LXxD_TableauLight_Emit LxResult tlgt_Emit (unsigned int nPhotons, int offset, ILxUnknownID slice, LXtSampleVectorID sv)
#define LXxO_TableauLight_Emit LXxD_TableauLight_Emit LXx_OVERRIDE
#define LXxC_TableauLight_Emit(c) LxResult c::tlgt_Emit (unsigned int nPhotons, int offset, ILxUnknownID slice, LXtSampleVectorID sv)
#define LXxD_TableauLight_ShadowMap int tlgt_ShadowMap (void **ppvObj)
#define LXxO_TableauLight_ShadowMap LXxD_TableauLight_ShadowMap LXx_OVERRIDE
#define LXxC_TableauLight_ShadowMap(c) int c::tlgt_ShadowMap (void **ppvObj)
template <class T>
class CLxIfc_TableauLight : public CLxInterface
{
    static LxResult
  Bound (LXtObjectID wcom, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    try {
      return loc->tlgt_Bound (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  FeatureCount (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    return loc->tlgt_FeatureCount (type);
  }
    static LxResult
  FeatureByIndex (LXtObjectID wcom, LXtID4 type, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    try {
      return loc->tlgt_FeatureByIndex (type,index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetVertex (LXtObjectID wcom, LXtObjectID vdesc)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    try {
      return loc->tlgt_SetVertex ((ILxUnknownID)vdesc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Sample (LXtObjectID wcom, float u, float v, const LXtFVector dir, LXtFVector wPos, LXtFVector oPos, LXtFVector norm, float t)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    try {
      return loc->tlgt_Sample (u,v,dir,wPos,oPos,norm,t);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Geometry (LXtObjectID wcom, void *gc)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    return loc->tlgt_Geometry (gc);
  }
    static LxResult
  Emit (LXtObjectID wcom, unsigned int nPhotons, int offset, LXtObjectID slice, LXtSampleVectorID sv)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    try {
      return loc->tlgt_Emit (nPhotons,offset,(ILxUnknownID)slice,sv);
    } catch (LxResult rc) { return rc; }
  }
    static int
  ShadowMap (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    return loc->tlgt_ShadowMap (ppvObj);
  }
  ILxTableauLight vt;
public:
  CLxIfc_TableauLight ()
  {
    vt.Bound = Bound;
    vt.FeatureCount = FeatureCount;
    vt.FeatureByIndex = FeatureByIndex;
    vt.SetVertex = SetVertex;
    vt.Sample = Sample;
    vt.Geometry = Geometry;
    vt.Emit = Emit;
    vt.ShadowMap = ShadowMap;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauLight;
  }
};
class CLxLoc_TableauLight : public CLxLocalize<ILxTableauLightID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauLight() {_init();}
  CLxLoc_TableauLight(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauLight(const CLxLoc_TableauLight &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauLight;}
    LxResult
  Bound (LXtTableauBox bbox)
  {
    return m_loc[0]->Bound (m_loc,bbox);
  }
    unsigned int
  FeatureCount (LXtID4 type)
  {
    return m_loc[0]->FeatureCount (m_loc,type);
  }
    LxResult
  FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
  {
    return m_loc[0]->FeatureByIndex (m_loc,type,index,name);
  }
    LxResult
  SetVertex (ILxUnknownID vdesc)
  {
    return m_loc[0]->SetVertex (m_loc,(ILxUnknownID)vdesc);
  }
    LxResult
  Sample (float u, float v, const LXtFVector dir, LXtFVector wPos, LXtFVector oPos, LXtFVector norm, float t)
  {
    return m_loc[0]->Sample (m_loc,u,v,dir,wPos,oPos,norm,t);
  }
    int
  Geometry (void *gc)
  {
    return m_loc[0]->Geometry (m_loc,gc);
  }
    LxResult
  Emit (unsigned int nPhotons, int offset, ILxUnknownID slice, LXtSampleVectorID sv)
  {
    return m_loc[0]->Emit (m_loc,nPhotons,offset,(ILxUnknownID)slice,sv);
  }
    int
  ShadowMap (void **ppvObj)
  {
    return m_loc[0]->ShadowMap (m_loc,ppvObj);
  }
};

#endif

