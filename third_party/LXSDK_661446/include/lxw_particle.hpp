/*
 * C++ wrapper for lxparticle.h
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
#ifndef LXW_PARTICLE_HPP
#define LXW_PARTICLE_HPP

#include <lxparticle.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ParticleCoOperator = {0xDFBCF67B,0xC327,0x496E,0x8A,0x30,0x20,0xB6,0x4C,0x31,0xA9,0xBB};
    static const LXtGUID guid_ParticleFilter = {0x04A3C0C5,0x1C5C,0x43F5,0x85,0x59,0xAC,0xF3,0xBA,0xE7,0x9C,0x0B};
    static const LXtGUID guid_ParticleItem = {0xBA13DD5D,0x5093,0x4D0D,0xBE,0xFE,0x11,0x9A,0xD4,0xF1,0xFA,0xCB};
    static const LXtGUID guid_ParticleEvalFrame = {0x1AC26263,0xA422,0x4B17,0xA9,0x29,0x2F,0x61,0x60,0x37,0x75,0x4F};
    static const LXtGUID guid_ParticleService = {0x34928BF8,0x3917,0x47EF,0x83,0x50,0xDD,0x3A,0x3D,0xDE,0xD7,0xEE};
    static const LXtGUID guid_PointCacheItem = {0x10930C44,0x62D3,0x42D1,0xBD,0x6B,0x8F,0xE0,0x15,0xD9,0xC5,0x66};
    static const LXtGUID guid_ReplicatorEnumerator = {0x01EC90A9,0x924F,0x4475,0xBA,0x6A,0xFF,0xF8,0xA2,0x69,0x1C,0xD5};
};

class CLxImpl_ParticleCoOperator {
  public:
    virtual ~CLxImpl_ParticleCoOperator() {}
    virtual LxResult
      pcoi_Initialize (ILxUnknownID eval)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pcoi_Cleanup (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pcoi_Step (double dT)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pcoi_Particle (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_ParticleCoOperator_Initialize LxResult pcoi_Initialize (ILxUnknownID eval)
#define LXxO_ParticleCoOperator_Initialize LXxD_ParticleCoOperator_Initialize LXx_OVERRIDE
#define LXxC_ParticleCoOperator_Initialize(c) LxResult c::pcoi_Initialize (ILxUnknownID eval)
#define LXxD_ParticleCoOperator_Cleanup LxResult pcoi_Cleanup (void)
#define LXxO_ParticleCoOperator_Cleanup LXxD_ParticleCoOperator_Cleanup LXx_OVERRIDE
#define LXxC_ParticleCoOperator_Cleanup(c) LxResult c::pcoi_Cleanup (void)
#define LXxD_ParticleCoOperator_Step LxResult pcoi_Step (double dT)
#define LXxO_ParticleCoOperator_Step LXxD_ParticleCoOperator_Step LXx_OVERRIDE
#define LXxC_ParticleCoOperator_Step(c) LxResult c::pcoi_Step (double dT)
#define LXxD_ParticleCoOperator_Particle LxResult pcoi_Particle (void)
#define LXxO_ParticleCoOperator_Particle LXxD_ParticleCoOperator_Particle LXx_OVERRIDE
#define LXxC_ParticleCoOperator_Particle(c) LxResult c::pcoi_Particle (void)
template <class T>
class CLxIfc_ParticleCoOperator : public CLxInterface
{
    static LxResult
  Initialize (LXtObjectID wcom, LXtObjectID eval)
  {
    LXCWxINST (CLxImpl_ParticleCoOperator, loc);
    try {
      return loc->pcoi_Initialize ((ILxUnknownID)eval);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Cleanup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ParticleCoOperator, loc);
    try {
      return loc->pcoi_Cleanup ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Step (LXtObjectID wcom, double dT)
  {
    LXCWxINST (CLxImpl_ParticleCoOperator, loc);
    try {
      return loc->pcoi_Step (dT);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Particle (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ParticleCoOperator, loc);
    try {
      return loc->pcoi_Particle ();
    } catch (LxResult rc) { return rc; }
  }
  ILxParticleCoOperator vt;
public:
  CLxIfc_ParticleCoOperator ()
  {
    vt.Initialize = Initialize;
    vt.Cleanup = Cleanup;
    vt.Step = Step;
    vt.Particle = Particle;
    vTable = &vt.iunk;
    iid = &lx::guid_ParticleCoOperator;
  }
};
class CLxLoc_ParticleCoOperator : public CLxLocalize<ILxParticleCoOperatorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ParticleCoOperator() {_init();}
  CLxLoc_ParticleCoOperator(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ParticleCoOperator(const CLxLoc_ParticleCoOperator &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ParticleCoOperator;}
    LxResult
  Initialize (ILxUnknownID eval)
  {
    return m_loc[0]->Initialize (m_loc,(ILxUnknownID)eval);
  }
    LxResult
  Cleanup (void)
  {
    return m_loc[0]->Cleanup (m_loc);
  }
    LxResult
  Step (double dT)
  {
    return m_loc[0]->Step (m_loc,dT);
  }
    LxResult
  Particle (void)
  {
    return m_loc[0]->Particle (m_loc);
  }
};

class CLxImpl_ParticleFilter {
  public:
    virtual ~CLxImpl_ParticleFilter() {}
    virtual LXtObjectID
      pfilt_Vertex (ILxUnknownID full)
        = 0;
    virtual unsigned
      pfilt_Flags (void)
        = 0;
    virtual LxResult
      pfilt_Initialize (ILxUnknownID vertex, ILxUnknownID frame, double time)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pfilt_Step (ILxUnknownID other, double dt)
        { return LXe_NOTIMPL; }
    virtual void
      pfilt_Cleanup (void)
        { }
    virtual LxResult
      pfilt_Frame (unsigned stage)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pfilt_Run (unsigned stage, float **values, const unsigned *alive, unsigned base, unsigned count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pfilt_Particle (unsigned stage, float *vertex)
        { return LXe_NOTIMPL; }
};
#define LXxD_ParticleFilter_Vertex LXtObjectID pfilt_Vertex (ILxUnknownID full)
#define LXxO_ParticleFilter_Vertex LXxD_ParticleFilter_Vertex LXx_OVERRIDE
#define LXxC_ParticleFilter_Vertex(c) LXtObjectID c::pfilt_Vertex (ILxUnknownID full)
#define LXxD_ParticleFilter_Flags unsigned pfilt_Flags (void)
#define LXxO_ParticleFilter_Flags LXxD_ParticleFilter_Flags LXx_OVERRIDE
#define LXxC_ParticleFilter_Flags(c) unsigned c::pfilt_Flags (void)
#define LXxD_ParticleFilter_Initialize LxResult pfilt_Initialize (ILxUnknownID vertex, ILxUnknownID frame, double time)
#define LXxO_ParticleFilter_Initialize LXxD_ParticleFilter_Initialize LXx_OVERRIDE
#define LXxC_ParticleFilter_Initialize(c) LxResult c::pfilt_Initialize (ILxUnknownID vertex, ILxUnknownID frame, double time)
#define LXxD_ParticleFilter_Step LxResult pfilt_Step (ILxUnknownID other, double dt)
#define LXxO_ParticleFilter_Step LXxD_ParticleFilter_Step LXx_OVERRIDE
#define LXxC_ParticleFilter_Step(c) LxResult c::pfilt_Step (ILxUnknownID other, double dt)
#define LXxD_ParticleFilter_Cleanup void pfilt_Cleanup (void)
#define LXxO_ParticleFilter_Cleanup LXxD_ParticleFilter_Cleanup LXx_OVERRIDE
#define LXxC_ParticleFilter_Cleanup(c) void c::pfilt_Cleanup (void)
#define LXxD_ParticleFilter_Frame LxResult pfilt_Frame (unsigned stage)
#define LXxO_ParticleFilter_Frame LXxD_ParticleFilter_Frame LXx_OVERRIDE
#define LXxC_ParticleFilter_Frame(c) LxResult c::pfilt_Frame (unsigned stage)
#define LXxD_ParticleFilter_Run LxResult pfilt_Run (unsigned stage, float **values, const unsigned *alive, unsigned base, unsigned count)
#define LXxO_ParticleFilter_Run LXxD_ParticleFilter_Run LXx_OVERRIDE
#define LXxC_ParticleFilter_Run(c) LxResult c::pfilt_Run (unsigned stage, float **values, const unsigned *alive, unsigned base, unsigned count)
#define LXxD_ParticleFilter_Particle LxResult pfilt_Particle (unsigned stage, float *vertex)
#define LXxO_ParticleFilter_Particle LXxD_ParticleFilter_Particle LXx_OVERRIDE
#define LXxC_ParticleFilter_Particle(c) LxResult c::pfilt_Particle (unsigned stage, float *vertex)
template <class T>
class CLxIfc_ParticleFilter : public CLxInterface
{
    static LXtObjectID
  Vertex (LXtObjectID wcom, LXtObjectID full)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    return loc->pfilt_Vertex ((ILxUnknownID)full);
  }
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    return loc->pfilt_Flags ();
  }
    static LxResult
  Initialize (LXtObjectID wcom, LXtObjectID vertex, LXtObjectID frame, double time)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    try {
      return loc->pfilt_Initialize ((ILxUnknownID)vertex,(ILxUnknownID)frame,time);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Step (LXtObjectID wcom, LXtObjectID other, double dt)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    try {
      return loc->pfilt_Step ((ILxUnknownID)other,dt);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    loc->pfilt_Cleanup ();
  }
    static LxResult
  Frame (LXtObjectID wcom, unsigned stage)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    try {
      return loc->pfilt_Frame (stage);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Run (LXtObjectID wcom, unsigned stage, float **values, const unsigned *alive, unsigned base, unsigned count)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    try {
      return loc->pfilt_Run (stage,values,alive,base,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Particle (LXtObjectID wcom, unsigned stage, float *vertex)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    try {
      return loc->pfilt_Particle (stage,vertex);
    } catch (LxResult rc) { return rc; }
  }
  ILxParticleFilter vt;
public:
  CLxIfc_ParticleFilter ()
  {
    vt.Vertex = Vertex;
    vt.Flags = Flags;
    vt.Initialize = Initialize;
    vt.Step = Step;
    vt.Cleanup = Cleanup;
    vt.Frame = Frame;
    vt.Run = Run;
    vt.Particle = Particle;
    vTable = &vt.iunk;
    iid = &lx::guid_ParticleFilter;
  }
};
class CLxLoc_ParticleFilter : public CLxLocalize<ILxParticleFilterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ParticleFilter() {_init();}
  CLxLoc_ParticleFilter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ParticleFilter(const CLxLoc_ParticleFilter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ParticleFilter;}
    ILxUnknownID
  Vertex (ILxUnknownID full)
  {
    return (ILxUnknownID) m_loc[0]->Vertex (m_loc,(ILxUnknownID)full);
  }
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    LxResult
  Initialize (ILxUnknownID vertex, ILxUnknownID frame, double time)
  {
    return m_loc[0]->Initialize (m_loc,(ILxUnknownID)vertex,(ILxUnknownID)frame,time);
  }
    LxResult
  Step (ILxUnknownID other, double dt)
  {
    return m_loc[0]->Step (m_loc,(ILxUnknownID)other,dt);
  }
    void
  Cleanup (void)
  {
    m_loc[0]->Cleanup (m_loc);
  }
    LxResult
  Frame (unsigned stage)
  {
    return m_loc[0]->Frame (m_loc,stage);
  }
    LxResult
  Run (unsigned stage, float **values, const unsigned *alive, unsigned base, unsigned count)
  {
    return m_loc[0]->Run (m_loc,stage,values,alive,base,count);
  }
    LxResult
  Particle (unsigned stage, float *vertex)
  {
    return m_loc[0]->Particle (m_loc,stage,vertex);
  }
};

class CLxImpl_ParticleItem {
  public:
    virtual ~CLxImpl_ParticleItem() {}
    virtual LxResult
      prti_Prepare (ILxUnknownID eval, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      prti_Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_ParticleItem_Prepare LxResult prti_Prepare (ILxUnknownID eval, unsigned *index)
#define LXxO_ParticleItem_Prepare LXxD_ParticleItem_Prepare LXx_OVERRIDE
#define LXxC_ParticleItem_Prepare(c) LxResult c::prti_Prepare (ILxUnknownID eval, unsigned *index)
#define LXxD_ParticleItem_Evaluate LxResult prti_Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
#define LXxO_ParticleItem_Evaluate LXxD_ParticleItem_Evaluate LXx_OVERRIDE
#define LXxC_ParticleItem_Evaluate(c) LxResult c::prti_Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
template <class T>
class CLxIfc_ParticleItem : public CLxInterface
{
    static LxResult
  Prepare (LXtObjectID wcom, LXtObjectID eval, unsigned *index)
  {
    LXCWxINST (CLxImpl_ParticleItem, loc);
    try {
      return loc->prti_Prepare ((ILxUnknownID)eval,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Evaluate (LXtObjectID wcom, LXtObjectID attr, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ParticleItem, loc);
    try {
      return loc->prti_Evaluate ((ILxUnknownID)attr,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxParticleItem vt;
public:
  CLxIfc_ParticleItem ()
  {
    vt.Prepare = Prepare;
    vt.Evaluate = Evaluate;
    vTable = &vt.iunk;
    iid = &lx::guid_ParticleItem;
  }
};
class CLxLoc_ParticleItem : public CLxLocalize<ILxParticleItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ParticleItem() {_init();}
  CLxLoc_ParticleItem(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ParticleItem(const CLxLoc_ParticleItem &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ParticleItem;}
    LxResult
  Prepare (ILxUnknownID eval, unsigned *index)
  {
    return m_loc[0]->Prepare (m_loc,(ILxUnknownID)eval,index);
  }
    LxResult
  Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
  {
    return m_loc[0]->Evaluate (m_loc,(ILxUnknownID)attr,index,ppvObj);
  }
    CLxResult
  Evaluate (ILxUnknownID attr, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Evaluate(m_loc,(ILxUnknownID)attr,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_ParticleEvalFrame : public CLxLocalize<ILxParticleEvalFrameID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ParticleEvalFrame() {_init();}
  CLxLoc_ParticleEvalFrame(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ParticleEvalFrame(const CLxLoc_ParticleEvalFrame &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ParticleEvalFrame;}
    ILxUnknownID
  VertexDescription (void)
  {
    return (ILxUnknownID) m_loc[0]->VertexDescription (m_loc);
  }
    unsigned
  MaxCount (void)
  {
    return m_loc[0]->MaxCount (m_loc);
  }
    unsigned
  AliveCount (void)
  {
    return m_loc[0]->AliveCount (m_loc);
  }
    LxResult
  AddParticle (const float *state, unsigned *index)
  {
    return m_loc[0]->AddParticle (m_loc,state,index);
  }
    LxResult
  KillParticle (unsigned index)
  {
    return m_loc[0]->KillParticle (m_loc,index);
  }
    unsigned
  IsAlive (unsigned index)
  {
    return m_loc[0]->IsAlive (m_loc,index);
  }
    LxResult
  GetVector (unsigned index, float *vector)
  {
    return m_loc[0]->GetVector (m_loc,index,vector);
  }
    LxResult
  SetVector (unsigned index, const float *vector)
  {
    return m_loc[0]->SetVector (m_loc,index,vector);
  }
    LxResult
  AliveRun (unsigned first, const unsigned **alive, unsigned *count)
  {
    return m_loc[0]->AliveRun (m_loc,first,alive,count);
  }
    LxResult
  VectorRun (unsigned first, float **values, unsigned *count)
  {
    return m_loc[0]->VectorRun (m_loc,first,values,count);
  }
    LxResult
  Neighbors (LXtFVector pos, double maxDist, int maxCount, unsigned *index, double *dist, unsigned *count)
  {
    return m_loc[0]->Neighbors (m_loc,pos,maxDist,maxCount,index,dist,count);
  }
};

class CLxLoc_ParticleService : public CLxLocalizedService
{
public:
  ILxParticleServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_ParticleService() {_init();set();}
 ~CLxLoc_ParticleService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxParticleServiceID>(lx::GetGlobal(&lx::guid_ParticleService));}
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
  GetReplicatorEnumerator (ILxUnknownID replicatorItem, void **ppvObj)
  {
    return m_loc[0]->GetReplicatorEnumerator (m_loc,(ILxUnknownID)replicatorItem,ppvObj);
  }
    CLxResult
  GetReplicatorEnumerator (ILxUnknownID replicatorItem, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetReplicatorEnumerator(m_loc,(ILxUnknownID)replicatorItem,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  EnumParticleFeatures (ILxUnknownID item, ILxUnknownID visitor)
  {
    return m_loc[0]->EnumParticleFeatures (m_loc,(ILxUnknownID)item,(ILxUnknownID)visitor);
  }
    LxResult
  FeatureIdent (const char **ident)
  {
    return m_loc[0]->FeatureIdent (m_loc,ident);
  }
    LxResult
  FeatureOffset (unsigned *offset)
  {
    return m_loc[0]->FeatureOffset (m_loc,offset);
  }
    LxResult
  TriGroupToParticle (ILxUnknownID triGroup, void **ppvObj)
  {
    return m_loc[0]->TriGroupToParticle (m_loc,(ILxUnknownID)triGroup,ppvObj);
  }
    CLxResult
  TriGroupToParticle (ILxUnknownID triGroup, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->TriGroupToParticle(m_loc,(ILxUnknownID)triGroup,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  TriGroupBlend (ILxUnknownID triGroup0, ILxUnknownID triGroup1, double blend)
  {
    return m_loc[0]->TriGroupBlend (m_loc,(ILxUnknownID)triGroup0,(ILxUnknownID)triGroup1,blend);
  }
    LxResult
  EnumeratorPrepare (ILxUnknownID eval, ILxUnknownID replItem, unsigned *index)
  {
    return m_loc[0]->EnumeratorPrepare (m_loc,(ILxUnknownID)eval,(ILxUnknownID)replItem,index);
  }
    LxResult
  EnumeratorEvaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
  {
    return m_loc[0]->EnumeratorEvaluate (m_loc,(ILxUnknownID)attr,index,ppvObj);
  }
    CLxResult
  EnumeratorEvaluate (ILxUnknownID attr, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->EnumeratorEvaluate(m_loc,(ILxUnknownID)attr,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemToParticle (ILxUnknownID item, ILxUnknownID chanRead, void **ppvObj)
  {
    return m_loc[0]->ItemToParticle (m_loc,(ILxUnknownID)item,(ILxUnknownID)chanRead,ppvObj);
  }
    CLxResult
  ItemToParticle (ILxUnknownID item, ILxUnknownID chanRead, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemToParticle(m_loc,(ILxUnknownID)item,(ILxUnknownID)chanRead,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_PointCacheItem {
  public:
    virtual ~CLxImpl_PointCacheItem() {}
    virtual LxResult
      pcache_Prepare (ILxUnknownID eval, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pcache_Initialize (ILxUnknownID vdesc, ILxUnknownID attr, unsigned index, double time, double sample)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pcache_SaveFrame (ILxUnknownID pobj, double time)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pcache_Cleanup (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_PointCacheItem_Prepare LxResult pcache_Prepare (ILxUnknownID eval, unsigned *index)
#define LXxO_PointCacheItem_Prepare LXxD_PointCacheItem_Prepare LXx_OVERRIDE
#define LXxC_PointCacheItem_Prepare(c) LxResult c::pcache_Prepare (ILxUnknownID eval, unsigned *index)
#define LXxD_PointCacheItem_Initialize LxResult pcache_Initialize (ILxUnknownID vdesc, ILxUnknownID attr, unsigned index, double time, double sample)
#define LXxO_PointCacheItem_Initialize LXxD_PointCacheItem_Initialize LXx_OVERRIDE
#define LXxC_PointCacheItem_Initialize(c) LxResult c::pcache_Initialize (ILxUnknownID vdesc, ILxUnknownID attr, unsigned index, double time, double sample)
#define LXxD_PointCacheItem_SaveFrame LxResult pcache_SaveFrame (ILxUnknownID pobj, double time)
#define LXxO_PointCacheItem_SaveFrame LXxD_PointCacheItem_SaveFrame LXx_OVERRIDE
#define LXxC_PointCacheItem_SaveFrame(c) LxResult c::pcache_SaveFrame (ILxUnknownID pobj, double time)
#define LXxD_PointCacheItem_Cleanup LxResult pcache_Cleanup (void)
#define LXxO_PointCacheItem_Cleanup LXxD_PointCacheItem_Cleanup LXx_OVERRIDE
#define LXxC_PointCacheItem_Cleanup(c) LxResult c::pcache_Cleanup (void)
template <class T>
class CLxIfc_PointCacheItem : public CLxInterface
{
    static LxResult
  Prepare (LXtObjectID wcom, LXtObjectID eval, unsigned *index)
  {
    LXCWxINST (CLxImpl_PointCacheItem, loc);
    try {
      return loc->pcache_Prepare ((ILxUnknownID)eval,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Initialize (LXtObjectID wcom, LXtObjectID vdesc, LXtObjectID attr, unsigned index, double time, double sample)
  {
    LXCWxINST (CLxImpl_PointCacheItem, loc);
    try {
      return loc->pcache_Initialize ((ILxUnknownID)vdesc,(ILxUnknownID)attr,index,time,sample);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SaveFrame (LXtObjectID wcom, LXtObjectID pobj, double time)
  {
    LXCWxINST (CLxImpl_PointCacheItem, loc);
    try {
      return loc->pcache_SaveFrame ((ILxUnknownID)pobj,time);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Cleanup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PointCacheItem, loc);
    try {
      return loc->pcache_Cleanup ();
    } catch (LxResult rc) { return rc; }
  }
  ILxPointCacheItem vt;
public:
  CLxIfc_PointCacheItem ()
  {
    vt.Prepare = Prepare;
    vt.Initialize = Initialize;
    vt.SaveFrame = SaveFrame;
    vt.Cleanup = Cleanup;
    vTable = &vt.iunk;
    iid = &lx::guid_PointCacheItem;
  }
};
class CLxLoc_PointCacheItem : public CLxLocalize<ILxPointCacheItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PointCacheItem() {_init();}
  CLxLoc_PointCacheItem(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PointCacheItem(const CLxLoc_PointCacheItem &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PointCacheItem;}
    LxResult
  Prepare (ILxUnknownID eval, unsigned *index)
  {
    return m_loc[0]->Prepare (m_loc,(ILxUnknownID)eval,index);
  }
    LxResult
  Initialize (ILxUnknownID vdesc, ILxUnknownID attr, unsigned index, double time, double sample)
  {
    return m_loc[0]->Initialize (m_loc,(ILxUnknownID)vdesc,(ILxUnknownID)attr,index,time,sample);
  }
    LxResult
  SaveFrame (ILxUnknownID pobj, double time)
  {
    return m_loc[0]->SaveFrame (m_loc,(ILxUnknownID)pobj,time);
  }
    LxResult
  Cleanup (void)
  {
    return m_loc[0]->Cleanup (m_loc);
  }
};

class CLxLoc_ReplicatorEnumerator : public CLxLocalize<ILxReplicatorEnumeratorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ReplicatorEnumerator() {_init();}
  CLxLoc_ReplicatorEnumerator(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ReplicatorEnumerator(const CLxLoc_ReplicatorEnumerator &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ReplicatorEnumerator;}
    LxResult
  Enumerate (ILxUnknownID visitor, ILxUnknownID chan, int localXform)
  {
    return m_loc[0]->Enumerate (m_loc,(ILxUnknownID)visitor,(ILxUnknownID)chan,localXform);
  }
    LxResult
  Item (void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,ppvObj);
  }
    CLxResult
  Item (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void
  Position (LXtVector pos)
  {
    m_loc[0]->Position (m_loc,pos);
  }
    void
  Orientation (LXtMatrix mx)
  {
    m_loc[0]->Orientation (m_loc,mx);
  }
    float
  Id (void)
  {
    return m_loc[0]->Id (m_loc);
  }
    float
  Dissolve (void)
  {
    return m_loc[0]->Dissolve (m_loc);
  }
    float
  GroupId (void)
  {
    return m_loc[0]->GroupId (m_loc);
  }
    LxResult
  Geometry (void **ppvObj)
  {
    return m_loc[0]->Geometry (m_loc,ppvObj);
  }
    CLxResult
  Geometry (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Geometry(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

