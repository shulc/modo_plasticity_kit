/*
 * C++ wrapper for lxlocator.h
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
#ifndef LXW_LOCATOR_HPP
#define LXW_LOCATOR_HPP

#include <lxlocator.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_Locator = {0x50DCCB9D,0x9856,0x4A33,0x9B,0xDA,0xDA,0xF3,0xA7,0x1B,0xBD,0x2D};
};

class CLxLoc_Locator : public CLxLocalize<ILxLocatorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Locator() {_init();}
  CLxLoc_Locator(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Locator(const CLxLoc_Locator &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Locator;}
    LxResult
  Visible (ILxUnknownID chanRead) const
  {
    return m_loc[0]->Visible (m_loc,(ILxUnknownID)chanRead);
  }
    LxResult
  WorldTransform (ILxUnknownID chanRead, LXtMatrix xfrm, LXtVector pos) const
  {
    return m_loc[0]->WorldTransform (m_loc,(ILxUnknownID)chanRead,xfrm,pos);
  }
    LxResult
  GetTransformItem (LXtTransformType type, void **ppvObj) const
  {
    return m_loc[0]->GetTransformItem (m_loc,type,ppvObj);
  }
    CLxResult
  GetTransformItem (LXtTransformType type, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetTransformItem(m_loc,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AddTransformItem (LXtTransformType type, void **ppvObj, unsigned *index)
  {
    return m_loc[0]->AddTransformItem (m_loc,type,ppvObj,index);
  }
    CLxResult
  AddTransformItem (LXtTransformType type, CLxLocalizedObject &o_dest, unsigned *index)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AddTransformItem(m_loc,type,&o_obj,index);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetTransformVector (ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value)
  {
    return m_loc[0]->SetTransformVector (m_loc,(ILxUnknownID)chanWrite,type,value);
  }
    LxResult
  AddPreTransformItem (ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, void **ppvObj, unsigned *index)
  {
    return m_loc[0]->AddPreTransformItem (m_loc,(ILxUnknownID)chanWrite,type,value,ppvObj,index);
  }
    CLxResult
  AddPreTransformItem (ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, CLxLocalizedObject &o_dest, unsigned *index)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AddPreTransformItem(m_loc,(ILxUnknownID)chanWrite,type,value,&o_obj,index);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AddPostTransformItem (ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, void **ppvObj, unsigned *index)
  {
    return m_loc[0]->AddPostTransformItem (m_loc,(ILxUnknownID)chanWrite,type,value,ppvObj,index);
  }
    CLxResult
  AddPostTransformItem (ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, CLxLocalizedObject &o_dest, unsigned *index)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AddPostTransformItem(m_loc,(ILxUnknownID)chanWrite,type,value,&o_obj,index);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetTarget (ILxUnknownID target, void **ppvObj)
  {
    return m_loc[0]->SetTarget (m_loc,(ILxUnknownID)target,ppvObj);
  }
    CLxResult
  SetTarget (ILxUnknownID target, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SetTarget(m_loc,(ILxUnknownID)target,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  PrependTransformItem (ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, void **ppvObj, unsigned *index)
  {
    return m_loc[0]->PrependTransformItem (m_loc,(ILxUnknownID)chanWrite,type,value,ppvObj,index);
  }
    CLxResult
  PrependTransformItem (ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, CLxLocalizedObject &o_dest, unsigned *index)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->PrependTransformItem(m_loc,(ILxUnknownID)chanWrite,type,value,&o_obj,index);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AppendTransformItem (ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, void **ppvObj, unsigned *index)
  {
    return m_loc[0]->AppendTransformItem (m_loc,(ILxUnknownID)chanWrite,type,value,ppvObj,index);
  }
    CLxResult
  AppendTransformItem (ILxUnknownID chanWrite, LXtTransformType type, const LXtVector value, CLxLocalizedObject &o_dest, unsigned *index)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AppendTransformItem(m_loc,(ILxUnknownID)chanWrite,type,value,&o_obj,index);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetPosition (ILxUnknownID chanRead, ILxUnknownID chanWrite, const LXtVector pos, unsigned type, unsigned comp)
  {
    return m_loc[0]->SetPosition (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,pos,type,comp);
  }
    LxResult
  SetRotation (ILxUnknownID chanRead, ILxUnknownID chanWrite, const LXtMatrix m3, unsigned type, unsigned comp)
  {
    return m_loc[0]->SetRotation (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,m3,type,comp);
  }
    LxResult
  SetScale (ILxUnknownID chanRead, ILxUnknownID chanWrite, const LXtMatrix4 m4, unsigned type, unsigned comp)
  {
    return m_loc[0]->SetScale (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,m4,type,comp);
  }
    LxResult
  ExtractLocalPosition (ILxUnknownID chanRead, LXtVector pos)
  {
    return m_loc[0]->ExtractLocalPosition (m_loc,(ILxUnknownID)chanRead,pos);
  }
    LxResult
  ExtractLocalRotation (ILxUnknownID chanRead, LXtMatrix m3)
  {
    return m_loc[0]->ExtractLocalRotation (m_loc,(ILxUnknownID)chanRead,m3);
  }
    LxResult
  ZeroTransform (ILxUnknownID chanRead, ILxUnknownID chanWrite, LXtTransformType type)
  {
    return m_loc[0]->ZeroTransform (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,type);
  }
    LxResult
  WorldTransform4 (ILxUnknownID chanRead, LXtMatrix4 xfrm4) const
  {
    return m_loc[0]->WorldTransform4 (m_loc,(ILxUnknownID)chanRead,xfrm4);
  }
    LxResult
  WorldInvertTransform (ILxUnknownID chanRead, LXtMatrix xfrm, LXtVector pos)
  {
    return m_loc[0]->WorldInvertTransform (m_loc,(ILxUnknownID)chanRead,xfrm,pos);
  }
    LxResult
  LocalTransform (ILxUnknownID chanRead, LXtMatrix xfrm, LXtVector pos) const
  {
    return m_loc[0]->LocalTransform (m_loc,(ILxUnknownID)chanRead,xfrm,pos);
  }
    LxResult
  LocalTransform4 (ILxUnknownID chanRead, LXtMatrix4 xfrm4) const
  {
    return m_loc[0]->LocalTransform4 (m_loc,(ILxUnknownID)chanRead,xfrm4);
  }
};

#endif

