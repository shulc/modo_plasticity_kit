/*
 * C++ wrapper for lxenvelope.h
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
#ifndef LXW_ENVELOPE_HPP
#define LXW_ENVELOPE_HPP

#include <lxenvelope.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_GradientFilter = {0xB3E49419,0x99B9,0x4066,0x9D,0xEC,0xAA,0x4E,0xF9,0x80,0x2F,0x0D};
    static const LXtGUID guid_Keyframe = {0xD1D0261F,0x22CF,0x4E5D,0x82,0x2E,0x76,0xB5,0xDE,0xC9,0x8A,0xE4};
    static const LXtGUID guid_GradientFilter1 = {0xACCD7C33,0xD246,0x4FE5,0xAB,0xA0,0x07,0x9F,0x22,0x5B,0xBB,0x34};
    static const LXtGUID guid_Envelope = {0xE39EB451,0x6C35,0x47F4,0x8A,0x7D,0xFF,0x96,0x67,0x1C,0x0D,0xEF};
};

class CLxImpl_GradientFilter {
  public:
    virtual ~CLxImpl_GradientFilter() {}
    virtual unsigned int
      grfilt_Type (void)
        = 0;
    virtual double
      grfilt_Generate (double time)
        { return 0; }
    virtual double
      grfilt_Evaluate (double time, double value)
        { return 0; }
    virtual double
      grfilt_MultiSample (double time, ILxUnknownID other)
        { return 0; }
};
#define LXxD_GradientFilter_Type unsigned int grfilt_Type (void)
#define LXxO_GradientFilter_Type LXxD_GradientFilter_Type LXx_OVERRIDE
#define LXxC_GradientFilter_Type(c) unsigned int c::grfilt_Type (void)
#define LXxD_GradientFilter_Generate double grfilt_Generate (double time)
#define LXxO_GradientFilter_Generate LXxD_GradientFilter_Generate LXx_OVERRIDE
#define LXxC_GradientFilter_Generate(c) double c::grfilt_Generate (double time)
#define LXxD_GradientFilter_Evaluate double grfilt_Evaluate (double time, double value)
#define LXxO_GradientFilter_Evaluate LXxD_GradientFilter_Evaluate LXx_OVERRIDE
#define LXxC_GradientFilter_Evaluate(c) double c::grfilt_Evaluate (double time, double value)
#define LXxD_GradientFilter_MultiSample double grfilt_MultiSample (double time, ILxUnknownID other)
#define LXxO_GradientFilter_MultiSample LXxD_GradientFilter_MultiSample LXx_OVERRIDE
#define LXxC_GradientFilter_MultiSample(c) double c::grfilt_MultiSample (double time, ILxUnknownID other)
template <class T>
class CLxIfc_GradientFilter : public CLxInterface
{
    static unsigned int
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_GradientFilter, loc);
    return loc->grfilt_Type ();
  }
    static double
  Generate (LXtObjectID wcom, double time)
  {
    LXCWxINST (CLxImpl_GradientFilter, loc);
    return loc->grfilt_Generate (time);
  }
    static double
  Evaluate (LXtObjectID wcom, double time, double value)
  {
    LXCWxINST (CLxImpl_GradientFilter, loc);
    return loc->grfilt_Evaluate (time,value);
  }
    static double
  MultiSample (LXtObjectID wcom, double time, LXtObjectID other)
  {
    LXCWxINST (CLxImpl_GradientFilter, loc);
    return loc->grfilt_MultiSample (time,(ILxUnknownID)other);
  }
  ILxGradientFilter vt;
public:
  CLxIfc_GradientFilter ()
  {
    vt.Type = Type;
    vt.Generate = Generate;
    vt.Evaluate = Evaluate;
    vt.MultiSample = MultiSample;
    vTable = &vt.iunk;
    iid = &lx::guid_GradientFilter;
  }
};
class CLxLoc_GradientFilter : public CLxLocalize<ILxGradientFilterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GradientFilter() {_init();}
  CLxLoc_GradientFilter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GradientFilter(const CLxLoc_GradientFilter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GradientFilter;}
    unsigned int
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    double
  Generate (double time)
  {
    return m_loc[0]->Generate (m_loc,time);
  }
    double
  Evaluate (double time, double value)
  {
    return m_loc[0]->Evaluate (m_loc,time,value);
  }
    double
  MultiSample (double time, ILxUnknownID other)
  {
    return m_loc[0]->MultiSample (m_loc,time,(ILxUnknownID)other);
  }
};

class CLxLoc_Keyframe : public CLxLocalize<ILxKeyframeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Keyframe() {_init();}
  CLxLoc_Keyframe(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Keyframe(const CLxLoc_Keyframe &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Keyframe;}
    LxResult
  First (void)
  {
    return m_loc[0]->First (m_loc);
  }
    LxResult
  Last (void)
  {
    return m_loc[0]->Last (m_loc);
  }
    LxResult
  Next (void)
  {
    return m_loc[0]->Next (m_loc);
  }
    LxResult
  Previous (void)
  {
    return m_loc[0]->Previous (m_loc);
  }
    LxResult
  Find (double time, unsigned int side)
  {
    return m_loc[0]->Find (m_loc,time,side);
  }
    LxResult
  GetTime (double *time)
  {
    return m_loc[0]->GetTime (m_loc,time);
  }
    LxResult
  GetBroken (unsigned int *breaks, unsigned int *side)
  {
    return m_loc[0]->GetBroken (m_loc,breaks,side);
  }
    LxResult
  GetValueF (double *value, unsigned int side)
  {
    return m_loc[0]->GetValueF (m_loc,value,side);
  }
    LxResult
  GetValueI (int *value, unsigned int side)
  {
    return m_loc[0]->GetValueI (m_loc,value,side);
  }
    LxResult
  GetSlopeType (LXtSlopeType *type, unsigned int *weighted, unsigned int side)
  {
    return m_loc[0]->GetSlopeType (m_loc,type,weighted,side);
  }
    LxResult
  GetSlope (double *slope, unsigned int side)
  {
    return m_loc[0]->GetSlope (m_loc,slope,side);
  }
    LxResult
  GetWeight (double *weight, unsigned int side)
  {
    return m_loc[0]->GetWeight (m_loc,weight,side);
  }
    LxResult
  SetTime (double time)
  {
    return m_loc[0]->SetTime (m_loc,time);
  }
    LxResult
  SetValueF (double value, unsigned int side)
  {
    return m_loc[0]->SetValueF (m_loc,value,side);
  }
    LxResult
  SetValueI (int value, unsigned int side)
  {
    return m_loc[0]->SetValueI (m_loc,value,side);
  }
    LxResult
  SetSlope (double slope, unsigned int side)
  {
    return m_loc[0]->SetSlope (m_loc,slope,side);
  }
    LxResult
  SetSlopeType (LXtSlopeType type, unsigned int side)
  {
    return m_loc[0]->SetSlopeType (m_loc,type,side);
  }
    LxResult
  SetWeight (double weight, unsigned int reset, unsigned int side)
  {
    return m_loc[0]->SetWeight (m_loc,weight,reset,side);
  }
    LxResult
  AddF (double time, double value)
  {
    return m_loc[0]->AddF (m_loc,time,value);
  }
    LxResult
  AddI (double time, int value)
  {
    return m_loc[0]->AddI (m_loc,time,value);
  }
    LxResult
  Delete (void)
  {
    return m_loc[0]->Delete (m_loc);
  }
};


class CLxLoc_Envelope : public CLxLocalize<ILxEnvelopeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Envelope() {_init();}
  CLxLoc_Envelope(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Envelope(const CLxLoc_Envelope &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Envelope;}
    unsigned
  IsInt (void)
  {
    return m_loc[0]->IsInt (m_loc);
  }
    LxResult
  Enumerator (void **ppvObj)
  {
    return m_loc[0]->Enumerator (m_loc,ppvObj);
  }
    CLxResult
  Enumerator (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Enumerator(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  EvaluateF (double time, double *value)
  {
    return m_loc[0]->EvaluateF (m_loc,time,value);
  }
    LxResult
  EvaluateI (double time, int *value)
  {
    return m_loc[0]->EvaluateI (m_loc,time,value);
  }
    unsigned int
  EndBehavior (unsigned int side)
  {
    return m_loc[0]->EndBehavior (m_loc,side);
  }
    LxResult
  SetEndBehavior (unsigned int behavior, unsigned int side)
  {
    return m_loc[0]->SetEndBehavior (m_loc,behavior,side);
  }
    LxResult
  Clear (void)
  {
    return m_loc[0]->Clear (m_loc);
  }
    unsigned int
  Interpolation (void)
  {
    return m_loc[0]->Interpolation (m_loc);
  }
    LxResult
  SetInterpolation (unsigned int type)
  {
    return m_loc[0]->SetInterpolation (m_loc,type);
  }
};

#endif

