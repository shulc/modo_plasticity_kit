/*
 * C++ wrapper for lxvariation.h
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
#ifndef LXW_VARIATION_HPP
#define LXW_VARIATION_HPP

#include <lxvariation.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_VariationService = {0x2BD9441B,0xC671,0x4F3C,0x9B,0x02,0x45,0xE9,0xD7,0x50,0xE8,0x0B};
    static const LXtGUID guid_Variation = {0x9EEA0765,0x4008,0x426C,0xA5,0x50,0x88,0xF6,0xEB,0x08,0xB2,0xE4};
};

class CLxLoc_VariationService : public CLxLocalizedService
{
public:
  ILxVariationServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_VariationService() {_init();set();}
 ~CLxLoc_VariationService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxVariationServiceID>(lx::GetGlobal(&lx::guid_VariationService));}
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
    void
  InvalidateItem (ILxUnknownID item)
  {
    m_loc[0]->InvalidateItem (m_loc,(ILxUnknownID)item);
  }
};

class CLxImpl_Variation {
  public:
    virtual ~CLxImpl_Variation() {}
    virtual LxResult
      var_TestItem (ILxUnknownID item, ILxUnknownID chanRead)
        { return LXe_NOTIMPL; }
    virtual LxResult
      var_Initialize (double *x, double *y, ILxUnknownID item, ILxUnknownID chanRead)
        { return LXe_NOTIMPL; }
    virtual LxResult
      var_RangeX (double *min, double *max)
        { return LXe_NOTIMPL; }
    virtual LxResult
      var_RangeY (double *min, double *max)
        { return LXe_NOTIMPL; }
    virtual LxResult
      var_Thumb (double x, double y, unsigned int size, ILxUnknownID chanRead, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      var_Do (double x, double y)
        { return LXe_NOTIMPL; }
};
#define LXxD_Variation_TestItem LxResult var_TestItem (ILxUnknownID item, ILxUnknownID chanRead)
#define LXxO_Variation_TestItem LXxD_Variation_TestItem LXx_OVERRIDE
#define LXxC_Variation_TestItem(c) LxResult c::var_TestItem (ILxUnknownID item, ILxUnknownID chanRead)
#define LXxD_Variation_Initialize LxResult var_Initialize (double *x, double *y, ILxUnknownID item, ILxUnknownID chanRead)
#define LXxO_Variation_Initialize LXxD_Variation_Initialize LXx_OVERRIDE
#define LXxC_Variation_Initialize(c) LxResult c::var_Initialize (double *x, double *y, ILxUnknownID item, ILxUnknownID chanRead)
#define LXxD_Variation_RangeX LxResult var_RangeX (double *min, double *max)
#define LXxO_Variation_RangeX LXxD_Variation_RangeX LXx_OVERRIDE
#define LXxC_Variation_RangeX(c) LxResult c::var_RangeX (double *min, double *max)
#define LXxD_Variation_RangeY LxResult var_RangeY (double *min, double *max)
#define LXxO_Variation_RangeY LXxD_Variation_RangeY LXx_OVERRIDE
#define LXxC_Variation_RangeY(c) LxResult c::var_RangeY (double *min, double *max)
#define LXxD_Variation_Thumb LxResult var_Thumb (double x, double y, unsigned int size, ILxUnknownID chanRead, void **ppvObj)
#define LXxO_Variation_Thumb LXxD_Variation_Thumb LXx_OVERRIDE
#define LXxC_Variation_Thumb(c) LxResult c::var_Thumb (double x, double y, unsigned int size, ILxUnknownID chanRead, void **ppvObj)
#define LXxD_Variation_Do LxResult var_Do (double x, double y)
#define LXxO_Variation_Do LXxD_Variation_Do LXx_OVERRIDE
#define LXxC_Variation_Do(c) LxResult c::var_Do (double x, double y)
template <class T>
class CLxIfc_Variation : public CLxInterface
{
    static LxResult
  TestItem (LXtObjectID wcom, LXtObjectID item, LXtObjectID chanRead)
  {
    LXCWxINST (CLxImpl_Variation, loc);
    try {
      return loc->var_TestItem ((ILxUnknownID)item,(ILxUnknownID)chanRead);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Initialize (LXtObjectID wcom, double *x, double *y, LXtObjectID item, LXtObjectID chanRead)
  {
    LXCWxINST (CLxImpl_Variation, loc);
    try {
      return loc->var_Initialize (x,y,(ILxUnknownID)item,(ILxUnknownID)chanRead);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RangeX (LXtObjectID wcom, double *min, double *max)
  {
    LXCWxINST (CLxImpl_Variation, loc);
    try {
      return loc->var_RangeX (min,max);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RangeY (LXtObjectID wcom, double *min, double *max)
  {
    LXCWxINST (CLxImpl_Variation, loc);
    try {
      return loc->var_RangeY (min,max);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Thumb (LXtObjectID wcom, double x, double y, unsigned int size, LXtObjectID chanRead, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Variation, loc);
    try {
      return loc->var_Thumb (x,y,size,(ILxUnknownID)chanRead,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Do (LXtObjectID wcom, double x, double y)
  {
    LXCWxINST (CLxImpl_Variation, loc);
    try {
      return loc->var_Do (x,y);
    } catch (LxResult rc) { return rc; }
  }
  ILxVariation vt;
public:
  CLxIfc_Variation ()
  {
    vt.TestItem = TestItem;
    vt.Initialize = Initialize;
    vt.RangeX = RangeX;
    vt.RangeY = RangeY;
    vt.Thumb = Thumb;
    vt.Do = Do;
    vTable = &vt.iunk;
    iid = &lx::guid_Variation;
  }
};
class CLxLoc_Variation : public CLxLocalize<ILxVariationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Variation() {_init();}
  CLxLoc_Variation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Variation(const CLxLoc_Variation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Variation;}
    LxResult
  TestItem (ILxUnknownID item, ILxUnknownID chanRead)
  {
    return m_loc[0]->TestItem (m_loc,(ILxUnknownID)item,(ILxUnknownID)chanRead);
  }
    LxResult
  Initialize (double *x, double *y, ILxUnknownID item, ILxUnknownID chanRead)
  {
    return m_loc[0]->Initialize (m_loc,x,y,(ILxUnknownID)item,(ILxUnknownID)chanRead);
  }
    LxResult
  RangeX (double *min, double *max)
  {
    return m_loc[0]->RangeX (m_loc,min,max);
  }
    LxResult
  RangeY (double *min, double *max)
  {
    return m_loc[0]->RangeY (m_loc,min,max);
  }
    LxResult
  Thumb (double x, double y, unsigned int size, ILxUnknownID chanRead, void **ppvObj)
  {
    return m_loc[0]->Thumb (m_loc,x,y,size,(ILxUnknownID)chanRead,ppvObj);
  }
    CLxResult
  Thumb (double x, double y, unsigned int size, ILxUnknownID chanRead, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Thumb(m_loc,x,y,size,(ILxUnknownID)chanRead,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Do (double x, double y)
  {
    return m_loc[0]->Do (m_loc,x,y);
  }
};

#endif

