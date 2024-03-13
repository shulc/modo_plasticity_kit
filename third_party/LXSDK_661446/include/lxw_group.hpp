/*
 * C++ wrapper for lxgroup.h
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
#ifndef LXW_GROUP_HPP
#define LXW_GROUP_HPP

#include <lxgroup.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_GroupItem = {0x47FDFD87,0x3FBA,0x41A4,0x80,0x44,0x74,0xEC,0x9D,0x9A,0xA9,0x86};
    static const LXtGUID guid_GroupEnumerator = {0xCA4E1FE0,0xB655,0x429F,0x96,0x74,0x3E,0x1D,0x7D,0xEA,0x5D,0x04};
};

class CLxLoc_GroupItem : public CLxLocalize<ILxGroupItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GroupItem() {_init();}
  CLxLoc_GroupItem(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GroupItem(const CLxLoc_GroupItem &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GroupItem;}
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
  Type (int *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  SetType (int type)
  {
    return m_loc[0]->SetType (m_loc,type);
  }
};

class CLxLoc_GroupEnumerator : public CLxLocalize<ILxGroupEnumeratorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GroupEnumerator() {_init();}
  CLxLoc_GroupEnumerator(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GroupEnumerator(const CLxLoc_GroupEnumerator &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GroupEnumerator;}
    LxResult
  Enumerate (ILxUnknownID visitor, unsigned mask)
  {
    return m_loc[0]->Enumerate (m_loc,(ILxUnknownID)visitor,mask);
  }
    unsigned
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
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
    LxResult
  Channel (void **ppvObj, unsigned *index)
  {
    return m_loc[0]->Channel (m_loc,ppvObj,index);
  }
    CLxResult
  Channel (CLxLocalizedObject &o_dest, unsigned *index)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Channel(m_loc,&o_obj,index);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

