/*
 * C++ wrapper for lxcliped.h
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
#ifndef LXW_CLIPED_HPP
#define LXW_CLIPED_HPP

#include <lxcliped.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ClipDest = {0x7d40b3b8,0xc5a4,0x4918,0xb8,0xe4,0x92,0x2e,0x62,0x9c,0x3f,0xfc};
};

class CLxImpl_ClipDest {
  public:
    virtual ~CLxImpl_ClipDest() {}
    virtual LxResult
      locd_Item (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual int
      locd_Type (void)
        = 0;
    virtual int
      locd_Location (void)
        = 0;
};
#define LXxD_ClipDest_Item LxResult locd_Item (void **ppvObj)
#define LXxO_ClipDest_Item LXxD_ClipDest_Item LXx_OVERRIDE
#define LXxC_ClipDest_Item(c) LxResult c::locd_Item (void **ppvObj)
#define LXxD_ClipDest_Type int locd_Type (void)
#define LXxO_ClipDest_Type LXxD_ClipDest_Type LXx_OVERRIDE
#define LXxC_ClipDest_Type(c) int c::locd_Type (void)
#define LXxD_ClipDest_Location int locd_Location (void)
#define LXxO_ClipDest_Location LXxD_ClipDest_Location LXx_OVERRIDE
#define LXxC_ClipDest_Location(c) int c::locd_Location (void)
template <class T>
class CLxIfc_ClipDest : public CLxInterface
{
    static LxResult
  Item (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ClipDest, loc);
    try {
      return loc->locd_Item (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ClipDest, loc);
    return loc->locd_Type ();
  }
    static int
  Location (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ClipDest, loc);
    return loc->locd_Location ();
  }
  ILxClipDest vt;
public:
  CLxIfc_ClipDest ()
  {
    vt.Item = Item;
    vt.Type = Type;
    vt.Location = Location;
    vTable = &vt.iunk;
    iid = &lx::guid_ClipDest;
  }
};
class CLxLoc_ClipDest : public CLxLocalize<ILxClipDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ClipDest() {_init();}
  CLxLoc_ClipDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ClipDest(const CLxLoc_ClipDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ClipDest;}
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
    int
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    int
  Location (void)
  {
    return m_loc[0]->Location (m_loc);
  }
};

#endif

