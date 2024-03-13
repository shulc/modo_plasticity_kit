/*
 * C++ wrapper for lxlistcache.h
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
#ifndef LXW_LISTCACHE_HPP
#define LXW_LISTCACHE_HPP

#include <lxlistcache.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ItemListType = {0x14EC78B2,0x8DAB,0x4E8B,0x8D,0x38,0x14,0x20,0x92,0x95,0x0A,0xE8};
};

class CLxImpl_ItemListType {
  public:
    virtual ~CLxImpl_ItemListType() {}
    virtual LxResult
      ilt_SetArgument (const char *arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ilt_SetRootItem (ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ilt_GenerateList (ILxUnknownID scene, ILxUnknownID collection)
        { return LXe_NOTIMPL; }
};
#define LXxD_ItemListType_SetArgument LxResult ilt_SetArgument (const char *arg)
#define LXxO_ItemListType_SetArgument LXxD_ItemListType_SetArgument LXx_OVERRIDE
#define LXxC_ItemListType_SetArgument(c) LxResult c::ilt_SetArgument (const char *arg)
#define LXxD_ItemListType_SetRootItem LxResult ilt_SetRootItem (ILxUnknownID item)
#define LXxO_ItemListType_SetRootItem LXxD_ItemListType_SetRootItem LXx_OVERRIDE
#define LXxC_ItemListType_SetRootItem(c) LxResult c::ilt_SetRootItem (ILxUnknownID item)
#define LXxD_ItemListType_GenerateList LxResult ilt_GenerateList (ILxUnknownID scene, ILxUnknownID collection)
#define LXxO_ItemListType_GenerateList LXxD_ItemListType_GenerateList LXx_OVERRIDE
#define LXxC_ItemListType_GenerateList(c) LxResult c::ilt_GenerateList (ILxUnknownID scene, ILxUnknownID collection)
template <class T>
class CLxIfc_ItemListType : public CLxInterface
{
    static LxResult
  SetArgument (LXtObjectID wcom, const char *arg)
  {
    LXCWxINST (CLxImpl_ItemListType, loc);
    try {
      return loc->ilt_SetArgument (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetRootItem (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_ItemListType, loc);
    try {
      return loc->ilt_SetRootItem ((ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GenerateList (LXtObjectID wcom, LXtObjectID scene, LXtObjectID collection)
  {
    LXCWxINST (CLxImpl_ItemListType, loc);
    try {
      return loc->ilt_GenerateList ((ILxUnknownID)scene,(ILxUnknownID)collection);
    } catch (LxResult rc) { return rc; }
  }
  ILxItemListType vt;
public:
  CLxIfc_ItemListType ()
  {
    vt.SetArgument = SetArgument;
    vt.SetRootItem = SetRootItem;
    vt.GenerateList = GenerateList;
    vTable = &vt.iunk;
    iid = &lx::guid_ItemListType;
  }
};
class CLxLoc_ItemListType : public CLxLocalize<ILxItemListTypeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemListType() {_init();}
  CLxLoc_ItemListType(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemListType(const CLxLoc_ItemListType &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemListType;}
    LxResult
  SetArgument (const char *arg)
  {
    return m_loc[0]->SetArgument (m_loc,arg);
  }
    LxResult
  SetRootItem (ILxUnknownID item)
  {
    return m_loc[0]->SetRootItem (m_loc,(ILxUnknownID)item);
  }
    LxResult
  GenerateList (ILxUnknownID scene, ILxUnknownID collection)
  {
    return m_loc[0]->GenerateList (m_loc,(ILxUnknownID)scene,(ILxUnknownID)collection);
  }
};

#endif

