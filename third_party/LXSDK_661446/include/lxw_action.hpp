/*
 * C++ wrapper for lxaction.h
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
#ifndef LXW_ACTION_HPP
#define LXW_ACTION_HPP

#include <lxaction.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_EvalModifier = {0x30AAAF24,0x9699,0x4737,0x8E,0x3B,0xE2,0x64,0xAA,0x4B,0x7A,0x3E};
    static const LXtGUID guid_SimulationModifier = {0xA44F37F3,0xE94F,0x4042,0x85,0xE2,0x1B,0xBF,0x63,0x3E,0x00,0xD2};
    static const LXtGUID guid_ChannelRead = {0xD5A8C4FD,0x151C,0x4D8B,0x97,0xE1,0x6E,0x1B,0x40,0x87,0x88,0x6B};
    static const LXtGUID guid_Modifier1 = {0xFA406E1C,0x5E6A,0x4574,0xA7,0x95,0xAA,0x0F,0x07,0xDF,0xAF,0xB5};
    static const LXtGUID guid_Evaluation = {0xFB552E5F,0x746E,0x4d74,0x88,0x5C,0x40,0xA9,0x31,0xB8,0x2B,0x84};
    static const LXtGUID guid_Modifier = {0x8D3BEC86,0xE10B,0x426A,0x8B,0xA3,0x84,0x62,0x50,0xE2,0x5A,0xF4};
    static const LXtGUID guid_ActionListener = {0x4819A297,0xA922,0x11D8,0xB1,0xAD,0x00,0x03,0x93,0xCE,0x96,0x80};
    static const LXtGUID guid_ChannelWrite = {0x91BFE3B8,0x16C6,0x4195,0xBF,0xE5,0x3F,0x0E,0x3C,0x0C,0x5C,0x57};
};

class CLxImpl_EvalModifier {
  public:
    virtual ~CLxImpl_EvalModifier() {}
    virtual LxResult
      eval_Reset (ILxUnknownID scene)
        { return LXe_NOTIMPL; }
    virtual LXtObjectID
      eval_Next (unsigned *index)
        { return 0; }
    virtual LxResult
      eval_Alloc (ILxUnknownID item, unsigned index, ILxUnknownID eval, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_EvalModifier_Reset LxResult eval_Reset (ILxUnknownID scene)
#define LXxO_EvalModifier_Reset LXxD_EvalModifier_Reset LXx_OVERRIDE
#define LXxC_EvalModifier_Reset(c) LxResult c::eval_Reset (ILxUnknownID scene)
#define LXxD_EvalModifier_Next LXtObjectID eval_Next (unsigned *index)
#define LXxO_EvalModifier_Next LXxD_EvalModifier_Next LXx_OVERRIDE
#define LXxC_EvalModifier_Next(c) LXtObjectID c::eval_Next (unsigned *index)
#define LXxD_EvalModifier_Alloc LxResult eval_Alloc (ILxUnknownID item, unsigned index, ILxUnknownID eval, void **ppvObj)
#define LXxO_EvalModifier_Alloc LXxD_EvalModifier_Alloc LXx_OVERRIDE
#define LXxC_EvalModifier_Alloc(c) LxResult c::eval_Alloc (ILxUnknownID item, unsigned index, ILxUnknownID eval, void **ppvObj)
template <class T>
class CLxIfc_EvalModifier : public CLxInterface
{
    static LxResult
  Reset (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_EvalModifier, loc);
    try {
      return loc->eval_Reset ((ILxUnknownID)scene);
    } catch (LxResult rc) { return rc; }
  }
    static LXtObjectID
  Next (LXtObjectID wcom, unsigned *index)
  {
    LXCWxINST (CLxImpl_EvalModifier, loc);
    return loc->eval_Next (index);
  }
    static LxResult
  Alloc (LXtObjectID wcom, LXtObjectID item, unsigned index, LXtObjectID eval, void **ppvObj)
  {
    LXCWxINST (CLxImpl_EvalModifier, loc);
    try {
      return loc->eval_Alloc ((ILxUnknownID)item,index,(ILxUnknownID)eval,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxEvalModifier vt;
public:
  CLxIfc_EvalModifier ()
  {
    vt.Reset = Reset;
    vt.Next = Next;
    vt.Alloc = Alloc;
    vTable = &vt.iunk;
    iid = &lx::guid_EvalModifier;
  }
};
class CLxLoc_EvalModifier : public CLxLocalize<ILxEvalModifierID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_EvalModifier() {_init();}
  CLxLoc_EvalModifier(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_EvalModifier(const CLxLoc_EvalModifier &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_EvalModifier;}
    LxResult
  Reset (ILxUnknownID scene)
  {
    return m_loc[0]->Reset (m_loc,(ILxUnknownID)scene);
  }
    ILxUnknownID
  Next (unsigned *index)
  {
    return (ILxUnknownID) m_loc[0]->Next (m_loc,index);
  }
    LxResult
  Alloc (ILxUnknownID item, unsigned index, ILxUnknownID eval, void **ppvObj)
  {
    return m_loc[0]->Alloc (m_loc,(ILxUnknownID)item,index,(ILxUnknownID)eval,ppvObj);
  }
    CLxResult
  Alloc (ILxUnknownID item, unsigned index, ILxUnknownID eval, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Alloc(m_loc,(ILxUnknownID)item,index,(ILxUnknownID)eval,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_SimulationModifier {
  public:
    virtual ~CLxImpl_SimulationModifier() {}
    virtual LxResult
      sim_Enabled (ILxUnknownID chanRead)
        { return LXe_TRUE; }
    virtual LxResult
      sim_Initialize (double time, double sample)
        { return LXe_NOTIMPL; }
    virtual void
      sim_Cleanup (void)
        { }
    virtual LxResult
      sim_StepSize (double *stepSize)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sim_Step (double dt)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sim_Bake (double time)
        { return LXe_NOTIMPL; }
};
#define LXxD_SimulationModifier_Enabled LxResult sim_Enabled (ILxUnknownID chanRead)
#define LXxO_SimulationModifier_Enabled LXxD_SimulationModifier_Enabled LXx_OVERRIDE
#define LXxC_SimulationModifier_Enabled(c) LxResult c::sim_Enabled (ILxUnknownID chanRead)
#define LXxD_SimulationModifier_Initialize LxResult sim_Initialize (double time, double sample)
#define LXxO_SimulationModifier_Initialize LXxD_SimulationModifier_Initialize LXx_OVERRIDE
#define LXxC_SimulationModifier_Initialize(c) LxResult c::sim_Initialize (double time, double sample)
#define LXxD_SimulationModifier_Cleanup void sim_Cleanup (void)
#define LXxO_SimulationModifier_Cleanup LXxD_SimulationModifier_Cleanup LXx_OVERRIDE
#define LXxC_SimulationModifier_Cleanup(c) void c::sim_Cleanup (void)
#define LXxD_SimulationModifier_StepSize LxResult sim_StepSize (double *stepSize)
#define LXxO_SimulationModifier_StepSize LXxD_SimulationModifier_StepSize LXx_OVERRIDE
#define LXxC_SimulationModifier_StepSize(c) LxResult c::sim_StepSize (double *stepSize)
#define LXxD_SimulationModifier_Step LxResult sim_Step (double dt)
#define LXxO_SimulationModifier_Step LXxD_SimulationModifier_Step LXx_OVERRIDE
#define LXxC_SimulationModifier_Step(c) LxResult c::sim_Step (double dt)
#define LXxD_SimulationModifier_Bake LxResult sim_Bake (double time)
#define LXxO_SimulationModifier_Bake LXxD_SimulationModifier_Bake LXx_OVERRIDE
#define LXxC_SimulationModifier_Bake(c) LxResult c::sim_Bake (double time)
template <class T>
class CLxIfc_SimulationModifier : public CLxInterface
{
    static LxResult
  Enabled (LXtObjectID wcom, LXtObjectID chanRead)
  {
    LXCWxINST (CLxImpl_SimulationModifier, loc);
    try {
      return loc->sim_Enabled ((ILxUnknownID)chanRead);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Initialize (LXtObjectID wcom, double time, double sample)
  {
    LXCWxINST (CLxImpl_SimulationModifier, loc);
    try {
      return loc->sim_Initialize (time,sample);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SimulationModifier, loc);
    loc->sim_Cleanup ();
  }
    static LxResult
  StepSize (LXtObjectID wcom, double *stepSize)
  {
    LXCWxINST (CLxImpl_SimulationModifier, loc);
    try {
      return loc->sim_StepSize (stepSize);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Step (LXtObjectID wcom, double dt)
  {
    LXCWxINST (CLxImpl_SimulationModifier, loc);
    try {
      return loc->sim_Step (dt);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Bake (LXtObjectID wcom, double time)
  {
    LXCWxINST (CLxImpl_SimulationModifier, loc);
    try {
      return loc->sim_Bake (time);
    } catch (LxResult rc) { return rc; }
  }
  ILxSimulationModifier vt;
public:
  CLxIfc_SimulationModifier ()
  {
    vt.Enabled = Enabled;
    vt.Initialize = Initialize;
    vt.Cleanup = Cleanup;
    vt.StepSize = StepSize;
    vt.Step = Step;
    vt.Bake = Bake;
    vTable = &vt.iunk;
    iid = &lx::guid_SimulationModifier;
  }
};
class CLxLoc_SimulationModifier : public CLxLocalize<ILxSimulationModifierID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SimulationModifier() {_init();}
  CLxLoc_SimulationModifier(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SimulationModifier(const CLxLoc_SimulationModifier &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SimulationModifier;}
    LxResult
  Enabled (ILxUnknownID chanRead)
  {
    return m_loc[0]->Enabled (m_loc,(ILxUnknownID)chanRead);
  }
    LxResult
  Initialize (double time, double sample)
  {
    return m_loc[0]->Initialize (m_loc,time,sample);
  }
    void
  Cleanup (void)
  {
    m_loc[0]->Cleanup (m_loc);
  }
    LxResult
  StepSize (double *stepSize)
  {
    return m_loc[0]->StepSize (m_loc,stepSize);
  }
    LxResult
  Step (double dt)
  {
    return m_loc[0]->Step (m_loc,dt);
  }
    LxResult
  Bake (double time)
  {
    return m_loc[0]->Bake (m_loc,time);
  }
};

class CLxLoc_ChannelRead : public CLxLocalize<ILxChannelReadID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelRead() {_init();}
  CLxLoc_ChannelRead(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelRead(const CLxLoc_ChannelRead &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelRead;}
    LxResult
  ValueObj (ILxUnknownID item, unsigned int channel, void **ppvObj)
  {
    return m_loc[0]->ValueObj (m_loc,(ILxUnknownID)item,channel,ppvObj);
  }
    CLxResult
  ValueObj (ILxUnknownID item, unsigned int channel, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ValueObj(m_loc,(ILxUnknownID)item,channel,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Integer (ILxUnknownID item, unsigned int channel, int *value)
  {
    return m_loc[0]->Integer (m_loc,(ILxUnknownID)item,channel,value);
  }
    LxResult
  Double (ILxUnknownID item, unsigned int channel, double *value)
  {
    return m_loc[0]->Double (m_loc,(ILxUnknownID)item,channel,value);
  }
    LxResult
  String (ILxUnknownID item, unsigned int channel, const char **value)
  {
    return m_loc[0]->String (m_loc,(ILxUnknownID)item,channel,value);
  }
    LxResult
  Envelope (ILxUnknownID item, unsigned int channel, void **ppvObj)
  {
    return m_loc[0]->Envelope (m_loc,(ILxUnknownID)item,channel,ppvObj);
  }
    CLxResult
  Envelope (ILxUnknownID item, unsigned int channel, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Envelope(m_loc,(ILxUnknownID)item,channel,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    double
  Time (void)
  {
    return m_loc[0]->Time (m_loc);
  }
    int
  IsAnimated (ILxUnknownID item, int index) const
  {
    return m_loc[0]->IsAnimated (m_loc,(ILxUnknownID)item,index);
  }
    LxResult
  IsBaked (ILxUnknownID item, unsigned int channel) const
  {
    return m_loc[0]->IsBaked (m_loc,(ILxUnknownID)item,channel);
  }
    LxResult
  BakedSamples (ILxUnknownID item, unsigned int channel, double *firstSample, double *spsRate, void **ppvObj)
  {
    return m_loc[0]->BakedSamples (m_loc,(ILxUnknownID)item,channel,firstSample,spsRate,ppvObj);
  }
    CLxResult
  BakedSamples (ILxUnknownID item, unsigned int channel, double *firstSample, double *spsRate, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->BakedSamples(m_loc,(ILxUnknownID)item,channel,firstSample,spsRate,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetTime (double time)
  {
    return m_loc[0]->SetTime (m_loc,time);
  }
    LxResult
  Type (ILxUnknownID item, unsigned int channel, unsigned *type)
  {
    return m_loc[0]->Type (m_loc,(ILxUnknownID)item,channel,type);
  }
    LxResult
  TypeName (ILxUnknownID item, unsigned int channel, const char **typeName)
  {
    return m_loc[0]->TypeName (m_loc,(ILxUnknownID)item,channel,typeName);
  }
    LxResult
  EncodedInt (ILxUnknownID item, unsigned int channel, char *buf, unsigned len)
  {
    return m_loc[0]->EncodedInt (m_loc,(ILxUnknownID)item,channel,buf,len);
  }
    LxResult
  EncodedInt (ILxUnknownID item, unsigned int channel, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->EncodedInt (m_loc,(ILxUnknownID)item,channel,buf,len);
    LXWx_SBUF2
  }
};


class CLxLoc_Evaluation : public CLxLocalize<ILxEvaluationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Evaluation() {_init();}
  CLxLoc_Evaluation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Evaluation(const CLxLoc_Evaluation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Evaluation;}
    LxResult
  AddChannel (ILxUnknownID item, unsigned index, unsigned type, unsigned *attr)
  {
    return m_loc[0]->AddChannel (m_loc,(ILxUnknownID)item,index,type,attr);
  }
    LxResult
  AddChannelName (ILxUnknownID item, const char *name, unsigned type, unsigned *attr)
  {
    return m_loc[0]->AddChannelName (m_loc,(ILxUnknownID)item,name,type,attr);
  }
    LxResult
  ReadTime (unsigned *attr)
  {
    return m_loc[0]->ReadTime (m_loc,attr);
  }
    LxResult
  SetAlternateTime (double time)
  {
    return m_loc[0]->SetAlternateTime (m_loc,time);
  }
    LxResult
  SetAlternate (void **ppvObj)
  {
    return m_loc[0]->SetAlternate (m_loc,ppvObj);
  }
    CLxResult
  SetAlternate (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SetAlternate(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ClearAlternate (void)
  {
    return m_loc[0]->ClearAlternate (m_loc);
  }
    LxResult
  SetCache (void *cache)
  {
    return m_loc[0]->SetCache (m_loc,cache);
  }
    void *
  GetCache (void)
  {
    return m_loc[0]->GetCache (m_loc);
  }
    LxResult
  SetAlternateSetup (void)
  {
    return m_loc[0]->SetAlternateSetup (m_loc);
  }
    LxResult
  GetBakedSample (unsigned index, unsigned bracket, double *fraction, void **ppvObj)
  {
    return m_loc[0]->GetBakedSample (m_loc,index,bracket,fraction,ppvObj);
  }
    CLxResult
  GetBakedSample (unsigned index, unsigned bracket, double *fraction, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetBakedSample(m_loc,index,bracket,fraction,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    double
  GetDT (void)
  {
    return m_loc[0]->GetDT (m_loc);
  }
    LxResult
  SimulationState (unsigned *flags)
  {
    return m_loc[0]->SimulationState (m_loc,flags);
  }
    LxResult
  SimulationRange (double *start, double *end)
  {
    return m_loc[0]->SimulationRange (m_loc,start,end);
  }
};

class CLxImpl_Modifier {
  public:
    virtual ~CLxImpl_Modifier() {}
    virtual LxResult
      mod_Evaluate (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mod_Test (ILxUnknownID item, unsigned index)
        { return LXe_TRUE; }
    virtual LxResult
      mod_Invalidate (ILxUnknownID item, unsigned index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mod_Validate (ILxUnknownID item, unsigned index, LxResult rc)
        { return LXe_NOTIMPL; }
    virtual unsigned
      mod_RequiredCount (void)
        { return 0; }
    virtual LxResult
      mod_Required (unsigned index, unsigned *attr, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual void
      mod_Free (void *cache)
        { }
};
#define LXxD_Modifier_Evaluate LxResult mod_Evaluate (void)
#define LXxO_Modifier_Evaluate LXxD_Modifier_Evaluate LXx_OVERRIDE
#define LXxC_Modifier_Evaluate(c) LxResult c::mod_Evaluate (void)
#define LXxD_Modifier_Test LxResult mod_Test (ILxUnknownID item, unsigned index)
#define LXxO_Modifier_Test LXxD_Modifier_Test LXx_OVERRIDE
#define LXxC_Modifier_Test(c) LxResult c::mod_Test (ILxUnknownID item, unsigned index)
#define LXxD_Modifier_Invalidate LxResult mod_Invalidate (ILxUnknownID item, unsigned index)
#define LXxO_Modifier_Invalidate LXxD_Modifier_Invalidate LXx_OVERRIDE
#define LXxC_Modifier_Invalidate(c) LxResult c::mod_Invalidate (ILxUnknownID item, unsigned index)
#define LXxD_Modifier_Validate LxResult mod_Validate (ILxUnknownID item, unsigned index, LxResult rc)
#define LXxO_Modifier_Validate LXxD_Modifier_Validate LXx_OVERRIDE
#define LXxC_Modifier_Validate(c) LxResult c::mod_Validate (ILxUnknownID item, unsigned index, LxResult rc)
#define LXxD_Modifier_RequiredCount unsigned mod_RequiredCount (void)
#define LXxO_Modifier_RequiredCount LXxD_Modifier_RequiredCount LXx_OVERRIDE
#define LXxC_Modifier_RequiredCount(c) unsigned c::mod_RequiredCount (void)
#define LXxD_Modifier_Required LxResult mod_Required (unsigned index, unsigned *attr, void **ppvObj)
#define LXxO_Modifier_Required LXxD_Modifier_Required LXx_OVERRIDE
#define LXxC_Modifier_Required(c) LxResult c::mod_Required (unsigned index, unsigned *attr, void **ppvObj)
#define LXxD_Modifier_Free void mod_Free (void *cache)
#define LXxO_Modifier_Free LXxD_Modifier_Free LXx_OVERRIDE
#define LXxC_Modifier_Free(c) void c::mod_Free (void *cache)
template <class T>
class CLxIfc_Modifier : public CLxInterface
{
    static LxResult
  Evaluate (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Modifier, loc);
    try {
      return loc->mod_Evaluate ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Test (LXtObjectID wcom, LXtObjectID item, unsigned index)
  {
    LXCWxINST (CLxImpl_Modifier, loc);
    try {
      return loc->mod_Test ((ILxUnknownID)item,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Invalidate (LXtObjectID wcom, LXtObjectID item, unsigned index)
  {
    LXCWxINST (CLxImpl_Modifier, loc);
    try {
      return loc->mod_Invalidate ((ILxUnknownID)item,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Validate (LXtObjectID wcom, LXtObjectID item, unsigned index, LxResult rc)
  {
    LXCWxINST (CLxImpl_Modifier, loc);
    try {
      return loc->mod_Validate ((ILxUnknownID)item,index,rc);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned
  RequiredCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Modifier, loc);
    return loc->mod_RequiredCount ();
  }
    static LxResult
  Required (LXtObjectID wcom, unsigned index, unsigned *attr, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Modifier, loc);
    try {
      return loc->mod_Required (index,attr,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Free (LXtObjectID wcom, void *cache)
  {
    LXCWxINST (CLxImpl_Modifier, loc);
    loc->mod_Free (cache);
  }
  ILxModifier vt;
public:
  CLxIfc_Modifier ()
  {
    vt.Evaluate = Evaluate;
    vt.Test = Test;
    vt.Invalidate = Invalidate;
    vt.Validate = Validate;
    vt.RequiredCount = RequiredCount;
    vt.Required = Required;
    vt.Free = Free;
    vTable = &vt.iunk;
    iid = &lx::guid_Modifier;
  }
};
class CLxLoc_Modifier : public CLxLocalize<ILxModifierID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Modifier() {_init();}
  CLxLoc_Modifier(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Modifier(const CLxLoc_Modifier &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Modifier;}
    LxResult
  Evaluate (void)
  {
    return m_loc[0]->Evaluate (m_loc);
  }
    LxResult
  Test (ILxUnknownID item, unsigned index)
  {
    return m_loc[0]->Test (m_loc,(ILxUnknownID)item,index);
  }
    LxResult
  Invalidate (ILxUnknownID item, unsigned index)
  {
    return m_loc[0]->Invalidate (m_loc,(ILxUnknownID)item,index);
  }
    LxResult
  Validate (ILxUnknownID item, unsigned index, LxResult rc)
  {
    return m_loc[0]->Validate (m_loc,(ILxUnknownID)item,index,rc);
  }
    unsigned
  RequiredCount (void)
  {
    return m_loc[0]->RequiredCount (m_loc);
  }
    LxResult
  Required (unsigned index, unsigned *attr, void **ppvObj)
  {
    return m_loc[0]->Required (m_loc,index,attr,ppvObj);
  }
    CLxResult
  Required (unsigned index, unsigned *attr, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Required(m_loc,index,attr,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void
  Free (void *cache)
  {
    m_loc[0]->Free (m_loc,cache);
  }
};

class CLxImpl_ActionListener {
  public:
    virtual ~CLxImpl_ActionListener() {}
    virtual void
      actl_ActionChannelSignal (ILxUnknownID item, unsigned channel)
        { }
    virtual void
      actl_ActionChannelConstantChange (ILxUnknownID item, unsigned channel)
        { }
    virtual void
      actl_ActionChannelConstantPreChange (ILxUnknownID item, unsigned channel)
        { }
};
#define LXxD_ActionListener_ActionChannelSignal void actl_ActionChannelSignal (ILxUnknownID item, unsigned channel)
#define LXxO_ActionListener_ActionChannelSignal LXxD_ActionListener_ActionChannelSignal LXx_OVERRIDE
#define LXxC_ActionListener_ActionChannelSignal(c) void c::actl_ActionChannelSignal (ILxUnknownID item, unsigned channel)
#define LXxD_ActionListener_ActionChannelConstantChange void actl_ActionChannelConstantChange (ILxUnknownID item, unsigned channel)
#define LXxO_ActionListener_ActionChannelConstantChange LXxD_ActionListener_ActionChannelConstantChange LXx_OVERRIDE
#define LXxC_ActionListener_ActionChannelConstantChange(c) void c::actl_ActionChannelConstantChange (ILxUnknownID item, unsigned channel)
#define LXxD_ActionListener_ActionChannelConstantPreChange void actl_ActionChannelConstantPreChange (ILxUnknownID item, unsigned channel)
#define LXxO_ActionListener_ActionChannelConstantPreChange LXxD_ActionListener_ActionChannelConstantPreChange LXx_OVERRIDE
#define LXxC_ActionListener_ActionChannelConstantPreChange(c) void c::actl_ActionChannelConstantPreChange (ILxUnknownID item, unsigned channel)
template <class T>
class CLxIfc_ActionListener : public CLxInterface
{
    static void
  ActionChannelSignal (LXtObjectID wcom, LXtObjectID item, unsigned channel)
  {
    LXCWxINST (CLxImpl_ActionListener, loc);
    loc->actl_ActionChannelSignal ((ILxUnknownID)item,channel);
  }
    static void
  ActionChannelConstantChange (LXtObjectID wcom, LXtObjectID item, unsigned channel)
  {
    LXCWxINST (CLxImpl_ActionListener, loc);
    loc->actl_ActionChannelConstantChange ((ILxUnknownID)item,channel);
  }
    static void
  ActionChannelConstantPreChange (LXtObjectID wcom, LXtObjectID item, unsigned channel)
  {
    LXCWxINST (CLxImpl_ActionListener, loc);
    loc->actl_ActionChannelConstantPreChange ((ILxUnknownID)item,channel);
  }
  ILxActionListener vt;
public:
  CLxIfc_ActionListener ()
  {
    vt.ActionChannelSignal = ActionChannelSignal;
    vt.ActionChannelConstantChange = ActionChannelConstantChange;
    vt.ActionChannelConstantPreChange = ActionChannelConstantPreChange;
    vTable = &vt.iunk;
    iid = &lx::guid_ActionListener;
  }
};
class CLxLoc_ActionListener : public CLxLocalize<ILxActionListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ActionListener() {_init();}
  CLxLoc_ActionListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ActionListener(const CLxLoc_ActionListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ActionListener;}
    void
  ActionChannelSignal (ILxUnknownID item, unsigned channel)
  {
    m_loc[0]->ActionChannelSignal (m_loc,(ILxUnknownID)item,channel);
  }
    void
  ActionChannelConstantChange (ILxUnknownID item, unsigned channel)
  {
    m_loc[0]->ActionChannelConstantChange (m_loc,(ILxUnknownID)item,channel);
  }
    void
  ActionChannelConstantPreChange (ILxUnknownID item, unsigned channel)
  {
    m_loc[0]->ActionChannelConstantPreChange (m_loc,(ILxUnknownID)item,channel);
  }
};

class CLxLoc_ChannelWrite : public CLxLocalize<ILxChannelWriteID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelWrite() {_init();}
  CLxLoc_ChannelWrite(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelWrite(const CLxLoc_ChannelWrite &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelWrite;}
    LxResult
  ValueObj (ILxUnknownID item, unsigned int channel, void **ppvObj)
  {
    return m_loc[0]->ValueObj (m_loc,(ILxUnknownID)item,channel,ppvObj);
  }
    CLxResult
  ValueObj (ILxUnknownID item, unsigned int channel, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ValueObj(m_loc,(ILxUnknownID)item,channel,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Integer (ILxUnknownID item, unsigned int channel, int value)
  {
    return m_loc[0]->Integer (m_loc,(ILxUnknownID)item,channel,value);
  }
    LxResult
  Double (ILxUnknownID item, unsigned int channel, double value)
  {
    return m_loc[0]->Double (m_loc,(ILxUnknownID)item,channel,value);
  }
    LxResult
  String (ILxUnknownID item, unsigned int channel, const char *value)
  {
    return m_loc[0]->String (m_loc,(ILxUnknownID)item,channel,value);
  }
    LxResult
  Envelope (ILxUnknownID item, unsigned int channel, void **ppvObj)
  {
    return m_loc[0]->Envelope (m_loc,(ILxUnknownID)item,channel,ppvObj);
  }
    CLxResult
  Envelope (ILxUnknownID item, unsigned int channel, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Envelope(m_loc,(ILxUnknownID)item,channel,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  IntegerKey (ILxUnknownID item, unsigned int channel, int value, int create)
  {
    return m_loc[0]->IntegerKey (m_loc,(ILxUnknownID)item,channel,value,create);
  }
    LxResult
  DoubleKey (ILxUnknownID item, unsigned int channel, double value, int create)
  {
    return m_loc[0]->DoubleKey (m_loc,(ILxUnknownID)item,channel,value,create);
  }
    LxResult
  SetState (ILxUnknownID item, unsigned int channel, unsigned int state)
  {
    return m_loc[0]->SetState (m_loc,(ILxUnknownID)item,channel,state);
  }
    LxResult
  BakeSamples (ILxUnknownID item, unsigned int channel, double firstSample, double spsRate, void **ppvObj)
  {
    return m_loc[0]->BakeSamples (m_loc,(ILxUnknownID)item,channel,firstSample,spsRate,ppvObj);
  }
    CLxResult
  BakeSamples (ILxUnknownID item, unsigned int channel, double firstSample, double spsRate, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->BakeSamples(m_loc,(ILxUnknownID)item,channel,firstSample,spsRate,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Type (ILxUnknownID item, unsigned int channel, unsigned *type)
  {
    return m_loc[0]->Type (m_loc,(ILxUnknownID)item,channel,type);
  }
    LxResult
  TypeName (ILxUnknownID item, unsigned int channel, const char **typeName)
  {
    return m_loc[0]->TypeName (m_loc,(ILxUnknownID)item,channel,typeName);
  }
    LxResult
  EncodedInt (ILxUnknownID item, unsigned int channel, const char *value)
  {
    return m_loc[0]->EncodedInt (m_loc,(ILxUnknownID)item,channel,value);
  }
    LxResult
  EncodedIntKey (ILxUnknownID item, unsigned int channel, const char *value)
  {
    return m_loc[0]->EncodedIntKey (m_loc,(ILxUnknownID)item,channel,value);
  }
};

#endif

