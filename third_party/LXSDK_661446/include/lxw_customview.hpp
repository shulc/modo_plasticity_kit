/*
 * C++ wrapper for lxcustomview.h
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
#ifndef LXW_CUSTOMVIEW_HPP
#define LXW_CUSTOMVIEW_HPP

#include <lxcustomview.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_CustomPane = {0x7412C685,0x3ED9,0x4622,0x91,0x5F,0x25,0x31,0x05,0x01,0x2B,0xC4};
    static const LXtGUID guid_CustomView = {0xb427f640,0x821a,0x48ee,0xb7,0xec,0xf4,0xaa,0xfe,0x79,0x96,0x95};
};

class CLxLoc_CustomPane : public CLxLocalize<ILxCustomPaneID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CustomPane() {_init();}
  CLxLoc_CustomPane(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CustomPane(const CLxLoc_CustomPane &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CustomPane;}
    LxResult
  GetParent (LXtPaneHandleID *handle)
  {
    return m_loc[0]->GetParent (m_loc,handle);
  }
    LxResult
  GetIdentifier (const char** ident)
  {
    return m_loc[0]->GetIdentifier (m_loc,ident);
  }
};

class CLxImpl_CustomView {
  public:
    virtual ~CLxImpl_CustomView() {}
    virtual LxResult
      customview_Init (ILxUnknownID pane)
        { return LXe_NOTIMPL; }
    virtual LxResult
      customview_Cleanup (ILxUnknownID pane)
        { return LXe_NOTIMPL; }
    virtual LxResult
      customview_StoreState (ILxUnknownID pane)
        { return LXe_NOTIMPL; }
    virtual LxResult
      customview_RestoreState (ILxUnknownID pane)
        { return LXe_NOTIMPL; }
};
#define LXxD_CustomView_Init LxResult customview_Init (ILxUnknownID pane)
#define LXxO_CustomView_Init LXxD_CustomView_Init LXx_OVERRIDE
#define LXxC_CustomView_Init(c) LxResult c::customview_Init (ILxUnknownID pane)
#define LXxD_CustomView_Cleanup LxResult customview_Cleanup (ILxUnknownID pane)
#define LXxO_CustomView_Cleanup LXxD_CustomView_Cleanup LXx_OVERRIDE
#define LXxC_CustomView_Cleanup(c) LxResult c::customview_Cleanup (ILxUnknownID pane)
#define LXxD_CustomView_StoreState LxResult customview_StoreState (ILxUnknownID pane)
#define LXxO_CustomView_StoreState LXxD_CustomView_StoreState LXx_OVERRIDE
#define LXxC_CustomView_StoreState(c) LxResult c::customview_StoreState (ILxUnknownID pane)
#define LXxD_CustomView_RestoreState LxResult customview_RestoreState (ILxUnknownID pane)
#define LXxO_CustomView_RestoreState LXxD_CustomView_RestoreState LXx_OVERRIDE
#define LXxC_CustomView_RestoreState(c) LxResult c::customview_RestoreState (ILxUnknownID pane)
template <class T>
class CLxIfc_CustomView : public CLxInterface
{
    static LxResult
  Init (LXtObjectID wcom, LXtObjectID pane)
  {
    LXCWxINST (CLxImpl_CustomView, loc);
    try {
      return loc->customview_Init ((ILxUnknownID)pane);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Cleanup (LXtObjectID wcom, LXtObjectID pane)
  {
    LXCWxINST (CLxImpl_CustomView, loc);
    try {
      return loc->customview_Cleanup ((ILxUnknownID)pane);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  StoreState (LXtObjectID wcom, LXtObjectID pane)
  {
    LXCWxINST (CLxImpl_CustomView, loc);
    try {
      return loc->customview_StoreState ((ILxUnknownID)pane);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RestoreState (LXtObjectID wcom, LXtObjectID pane)
  {
    LXCWxINST (CLxImpl_CustomView, loc);
    try {
      return loc->customview_RestoreState ((ILxUnknownID)pane);
    } catch (LxResult rc) { return rc; }
  }
  ILxCustomView vt;
public:
  CLxIfc_CustomView ()
  {
    vt.Init = Init;
    vt.Cleanup = Cleanup;
    vt.StoreState = StoreState;
    vt.RestoreState = RestoreState;
    vTable = &vt.iunk;
    iid = &lx::guid_CustomView;
  }
};
class CLxLoc_CustomView : public CLxLocalize<ILxCustomViewID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CustomView() {_init();}
  CLxLoc_CustomView(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CustomView(const CLxLoc_CustomView &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CustomView;}
    LxResult
  Init (ILxUnknownID pane)
  {
    return m_loc[0]->Init (m_loc,(ILxUnknownID)pane);
  }
    LxResult
  Cleanup (ILxUnknownID pane)
  {
    return m_loc[0]->Cleanup (m_loc,(ILxUnknownID)pane);
  }
    LxResult
  StoreState (ILxUnknownID pane)
  {
    return m_loc[0]->StoreState (m_loc,(ILxUnknownID)pane);
  }
    LxResult
  RestoreState (ILxUnknownID pane)
  {
    return m_loc[0]->RestoreState (m_loc,(ILxUnknownID)pane);
  }
};

#endif

