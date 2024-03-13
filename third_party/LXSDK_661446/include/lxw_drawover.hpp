/*
 * C++ wrapper for lxdrawover.h
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
#ifndef LXW_DRAWOVER_HPP
#define LXW_DRAWOVER_HPP

#include <lxdrawover.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_DrawingOverride = {0x52429702,0x1D97,0x4B00,0x81,0x54,0x65,0x10,0xD3,0x4E,0xE8,0xCA};
};

class CLxImpl_DrawingOverride {
  public:
    virtual ~CLxImpl_DrawingOverride() {}
    virtual int
      drov_Flags (void)
        = 0;
    virtual LxResult
      drov_AffectedItems (ILxUnknownID scene, ILxUnknownID collection)
        { return LXe_NOTIMPL; }
    virtual LxResult
      drov_SetItem (ILxUnknownID item, unsigned *styles)
        { return LXe_NOTIMPL; }
    virtual LxResult
      drov_GetColor (unsigned style, LXtVector4 rgba)
        { return LXe_NOTIMPL; }
    virtual LxResult
      drov_InitContext (void)
        { return LXe_NOTIMPL; }
    virtual void
      drov_CleanupContext (void)
        { }
    virtual LxResult
      drov_DrawVisitor (ILxUnknownID scene, ILxUnknownID view, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_DrawingOverride_Flags int drov_Flags (void)
#define LXxO_DrawingOverride_Flags LXxD_DrawingOverride_Flags LXx_OVERRIDE
#define LXxC_DrawingOverride_Flags(c) int c::drov_Flags (void)
#define LXxD_DrawingOverride_AffectedItems LxResult drov_AffectedItems (ILxUnknownID scene, ILxUnknownID collection)
#define LXxO_DrawingOverride_AffectedItems LXxD_DrawingOverride_AffectedItems LXx_OVERRIDE
#define LXxC_DrawingOverride_AffectedItems(c) LxResult c::drov_AffectedItems (ILxUnknownID scene, ILxUnknownID collection)
#define LXxD_DrawingOverride_SetItem LxResult drov_SetItem (ILxUnknownID item, unsigned *styles)
#define LXxO_DrawingOverride_SetItem LXxD_DrawingOverride_SetItem LXx_OVERRIDE
#define LXxC_DrawingOverride_SetItem(c) LxResult c::drov_SetItem (ILxUnknownID item, unsigned *styles)
#define LXxD_DrawingOverride_GetColor LxResult drov_GetColor (unsigned style, LXtVector4 rgba)
#define LXxO_DrawingOverride_GetColor LXxD_DrawingOverride_GetColor LXx_OVERRIDE
#define LXxC_DrawingOverride_GetColor(c) LxResult c::drov_GetColor (unsigned style, LXtVector4 rgba)
#define LXxD_DrawingOverride_InitContext LxResult drov_InitContext (void)
#define LXxO_DrawingOverride_InitContext LXxD_DrawingOverride_InitContext LXx_OVERRIDE
#define LXxC_DrawingOverride_InitContext(c) LxResult c::drov_InitContext (void)
#define LXxD_DrawingOverride_CleanupContext void drov_CleanupContext (void)
#define LXxO_DrawingOverride_CleanupContext LXxD_DrawingOverride_CleanupContext LXx_OVERRIDE
#define LXxC_DrawingOverride_CleanupContext(c) void c::drov_CleanupContext (void)
#define LXxD_DrawingOverride_DrawVisitor LxResult drov_DrawVisitor (ILxUnknownID scene, ILxUnknownID view, void **ppvObj)
#define LXxO_DrawingOverride_DrawVisitor LXxD_DrawingOverride_DrawVisitor LXx_OVERRIDE
#define LXxC_DrawingOverride_DrawVisitor(c) LxResult c::drov_DrawVisitor (ILxUnknownID scene, ILxUnknownID view, void **ppvObj)
template <class T>
class CLxIfc_DrawingOverride : public CLxInterface
{
    static int
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_DrawingOverride, loc);
    return loc->drov_Flags ();
  }
    static LxResult
  AffectedItems (LXtObjectID wcom, LXtObjectID scene, LXtObjectID collection)
  {
    LXCWxINST (CLxImpl_DrawingOverride, loc);
    try {
      return loc->drov_AffectedItems ((ILxUnknownID)scene,(ILxUnknownID)collection);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetItem (LXtObjectID wcom, LXtObjectID item, unsigned *styles)
  {
    LXCWxINST (CLxImpl_DrawingOverride, loc);
    try {
      return loc->drov_SetItem ((ILxUnknownID)item,styles);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetColor (LXtObjectID wcom, unsigned style, LXtVector4 rgba)
  {
    LXCWxINST (CLxImpl_DrawingOverride, loc);
    try {
      return loc->drov_GetColor (style,rgba);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  InitContext (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_DrawingOverride, loc);
    try {
      return loc->drov_InitContext ();
    } catch (LxResult rc) { return rc; }
  }
    static void
  CleanupContext (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_DrawingOverride, loc);
    loc->drov_CleanupContext ();
  }
    static LxResult
  DrawVisitor (LXtObjectID wcom, LXtObjectID scene, LXtObjectID view, void **ppvObj)
  {
    LXCWxINST (CLxImpl_DrawingOverride, loc);
    try {
      return loc->drov_DrawVisitor ((ILxUnknownID)scene,(ILxUnknownID)view,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxDrawingOverride vt;
public:
  CLxIfc_DrawingOverride ()
  {
    vt.Flags = Flags;
    vt.AffectedItems = AffectedItems;
    vt.SetItem = SetItem;
    vt.GetColor = GetColor;
    vt.InitContext = InitContext;
    vt.CleanupContext = CleanupContext;
    vt.DrawVisitor = DrawVisitor;
    vTable = &vt.iunk;
    iid = &lx::guid_DrawingOverride;
  }
};
class CLxLoc_DrawingOverride : public CLxLocalize<ILxDrawingOverrideID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DrawingOverride() {_init();}
  CLxLoc_DrawingOverride(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DrawingOverride(const CLxLoc_DrawingOverride &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DrawingOverride;}
    int
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    LxResult
  AffectedItems (ILxUnknownID scene, ILxUnknownID collection)
  {
    return m_loc[0]->AffectedItems (m_loc,(ILxUnknownID)scene,(ILxUnknownID)collection);
  }
    LxResult
  SetItem (ILxUnknownID item, unsigned *styles)
  {
    return m_loc[0]->SetItem (m_loc,(ILxUnknownID)item,styles);
  }
    LxResult
  GetColor (unsigned style, LXtVector4 rgba)
  {
    return m_loc[0]->GetColor (m_loc,style,rgba);
  }
    LxResult
  InitContext (void)
  {
    return m_loc[0]->InitContext (m_loc);
  }
    void
  CleanupContext (void)
  {
    m_loc[0]->CleanupContext (m_loc);
  }
    LxResult
  DrawVisitor (ILxUnknownID scene, ILxUnknownID view, void **ppvObj)
  {
    return m_loc[0]->DrawVisitor (m_loc,(ILxUnknownID)scene,(ILxUnknownID)view,ppvObj);
  }
    CLxResult
  DrawVisitor (ILxUnknownID scene, ILxUnknownID view, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->DrawVisitor(m_loc,(ILxUnknownID)scene,(ILxUnknownID)view,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

