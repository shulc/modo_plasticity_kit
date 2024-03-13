/*
 * C++ wrapper for lxvmodel.h
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
#ifndef LXW_VMODEL_HPP
#define LXW_VMODEL_HPP

#include <lxvmodel.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_NavigationListener = {0x61724B7C,0x59DE,0x40F7,0xB2,0x60,0x8C,0x71,0xD8,0xFE,0x97,0x10};
    static const LXtGUID guid_ToolModel4 = {0x6E3DCFCE,0xF8BF,0x43EB,0x9D,0x2E,0x61,0x70,0x70,0x57,0x47,0x36};
    static const LXtGUID guid_ToolModel1 = {0xEECE6570,0xAD5F,0x4190,0xAF,0xA7,0x15,0x06,0x75,0x00,0x45,0x4F};
    static const LXtGUID guid_ToolModel3 = {0x27DB58F5,0x5C0C,0x4CF7,0xB0,0x64,0x6B,0x07,0x18,0x8E,0x98,0x13};
    static const LXtGUID guid_ViewItem3D = {0x5E0E5E09,0x9D9F,0x447C,0xAE,0xDA,0x2F,0x6F,0x26,0x6D,0xB4,0x64};
    static const LXtGUID guid_ToolModel2 = {0xB70B1F15,0x137A,0x4716,0xA8,0x93,0x1A,0xC4,0x16,0xC5,0x47,0xE9};
    static const LXtGUID guid_ViewItem3D1 = {0x9BCE73B5,0x3264,0x48BB,0xB1,0x29,0x15,0xFF,0x53,0xFD,0x16,0x61};
    static const LXtGUID guid_AdjustTool = {0x26E85301,0x8165,0x4FF3,0xAF,0x26,0x39,0x2A,0x03,0xC9,0xE1,0xE7};
    static const LXtGUID guid_ToolModel = {0x7C98503C,0xB697,0x43D2,0xBC,0x04,0x50,0xCE,0x8E,0x48,0x39,0xB2};
    static const LXtGUID guid_VirtualModel = {0x28F7A244,0xE5B0,0x406C,0xAA,0x54,0x55,0xD3,0x3D,0x52,0xEB,0x4A};
};

class CLxImpl_NavigationListener {
  public:
    virtual ~CLxImpl_NavigationListener() {}
    virtual void
      nav_Down (ILxUnknownID view, ILxUnknownID item)
        { }
    virtual void
      nav_Move (ILxUnknownID view, ILxUnknownID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom)
        { }
    virtual void
      nav_Up (ILxUnknownID view, ILxUnknownID item)
        { }
    virtual void
      nav_Delta (ILxUnknownID view, ILxUnknownID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom)
        { }
    virtual void
      nav_Wheel (ILxUnknownID view, ILxUnknownID item)
        { }
    virtual void
      nav_HotSyncPre (ILxUnknownID view, ILxUnknownID item)
        { }
    virtual void
      nav_HotSyncPost (ILxUnknownID view, ILxUnknownID item)
        { }
};
#define LXxD_NavigationListener_Down void nav_Down (ILxUnknownID view, ILxUnknownID item)
#define LXxO_NavigationListener_Down LXxD_NavigationListener_Down LXx_OVERRIDE
#define LXxC_NavigationListener_Down(c) void c::nav_Down (ILxUnknownID view, ILxUnknownID item)
#define LXxD_NavigationListener_Move void nav_Move (ILxUnknownID view, ILxUnknownID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom)
#define LXxO_NavigationListener_Move LXxD_NavigationListener_Move LXx_OVERRIDE
#define LXxC_NavigationListener_Move(c) void c::nav_Move (ILxUnknownID view, ILxUnknownID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom)
#define LXxD_NavigationListener_Up void nav_Up (ILxUnknownID view, ILxUnknownID item)
#define LXxO_NavigationListener_Up LXxD_NavigationListener_Up LXx_OVERRIDE
#define LXxC_NavigationListener_Up(c) void c::nav_Up (ILxUnknownID view, ILxUnknownID item)
#define LXxD_NavigationListener_Delta void nav_Delta (ILxUnknownID view, ILxUnknownID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom)
#define LXxO_NavigationListener_Delta LXxD_NavigationListener_Delta LXx_OVERRIDE
#define LXxC_NavigationListener_Delta(c) void c::nav_Delta (ILxUnknownID view, ILxUnknownID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom)
#define LXxD_NavigationListener_Wheel void nav_Wheel (ILxUnknownID view, ILxUnknownID item)
#define LXxO_NavigationListener_Wheel LXxD_NavigationListener_Wheel LXx_OVERRIDE
#define LXxC_NavigationListener_Wheel(c) void c::nav_Wheel (ILxUnknownID view, ILxUnknownID item)
#define LXxD_NavigationListener_HotSyncPre void nav_HotSyncPre (ILxUnknownID view, ILxUnknownID item)
#define LXxO_NavigationListener_HotSyncPre LXxD_NavigationListener_HotSyncPre LXx_OVERRIDE
#define LXxC_NavigationListener_HotSyncPre(c) void c::nav_HotSyncPre (ILxUnknownID view, ILxUnknownID item)
#define LXxD_NavigationListener_HotSyncPost void nav_HotSyncPost (ILxUnknownID view, ILxUnknownID item)
#define LXxO_NavigationListener_HotSyncPost LXxD_NavigationListener_HotSyncPost LXx_OVERRIDE
#define LXxC_NavigationListener_HotSyncPost(c) void c::nav_HotSyncPost (ILxUnknownID view, ILxUnknownID item)
template <class T>
class CLxIfc_NavigationListener : public CLxInterface
{
    static void
  Down (LXtObjectID wcom, LXtObjectID view, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_NavigationListener, loc);
    loc->nav_Down ((ILxUnknownID)view,(ILxUnknownID)item);
  }
    static void
  Move (LXtObjectID wcom, LXtObjectID view, LXtObjectID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom)
  {
    LXCWxINST (CLxImpl_NavigationListener, loc);
    loc->nav_Move ((ILxUnknownID)view,(ILxUnknownID)item,hot,pos,rot,zoom);
  }
    static void
  Up (LXtObjectID wcom, LXtObjectID view, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_NavigationListener, loc);
    loc->nav_Up ((ILxUnknownID)view,(ILxUnknownID)item);
  }
    static void
  Delta (LXtObjectID wcom, LXtObjectID view, LXtObjectID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom)
  {
    LXCWxINST (CLxImpl_NavigationListener, loc);
    loc->nav_Delta ((ILxUnknownID)view,(ILxUnknownID)item,hot,pos,rot,zoom);
  }
    static void
  Wheel (LXtObjectID wcom, LXtObjectID view, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_NavigationListener, loc);
    loc->nav_Wheel ((ILxUnknownID)view,(ILxUnknownID)item);
  }
    static void
  HotSyncPre (LXtObjectID wcom, LXtObjectID view, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_NavigationListener, loc);
    loc->nav_HotSyncPre ((ILxUnknownID)view,(ILxUnknownID)item);
  }
    static void
  HotSyncPost (LXtObjectID wcom, LXtObjectID view, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_NavigationListener, loc);
    loc->nav_HotSyncPost ((ILxUnknownID)view,(ILxUnknownID)item);
  }
  ILxNavigationListener vt;
public:
  CLxIfc_NavigationListener ()
  {
    vt.Down = Down;
    vt.Move = Move;
    vt.Up = Up;
    vt.Delta = Delta;
    vt.Wheel = Wheel;
    vt.HotSyncPre = HotSyncPre;
    vt.HotSyncPost = HotSyncPost;
    vTable = &vt.iunk;
    iid = &lx::guid_NavigationListener;
  }
};
class CLxLoc_NavigationListener : public CLxLocalize<ILxNavigationListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_NavigationListener() {_init();}
  CLxLoc_NavigationListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_NavigationListener(const CLxLoc_NavigationListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_NavigationListener;}
    void
  Down (ILxUnknownID view, ILxUnknownID item)
  {
    m_loc[0]->Down (m_loc,(ILxUnknownID)view,(ILxUnknownID)item);
  }
    void
  Move (ILxUnknownID view, ILxUnknownID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom)
  {
    m_loc[0]->Move (m_loc,(ILxUnknownID)view,(ILxUnknownID)item,hot,pos,rot,zoom);
  }
    void
  Up (ILxUnknownID view, ILxUnknownID item)
  {
    m_loc[0]->Up (m_loc,(ILxUnknownID)view,(ILxUnknownID)item);
  }
    void
  Delta (ILxUnknownID view, ILxUnknownID item, unsigned hot, const LXtVector pos, const LXtMatrix rot, double zoom)
  {
    m_loc[0]->Delta (m_loc,(ILxUnknownID)view,(ILxUnknownID)item,hot,pos,rot,zoom);
  }
    void
  Wheel (ILxUnknownID view, ILxUnknownID item)
  {
    m_loc[0]->Wheel (m_loc,(ILxUnknownID)view,(ILxUnknownID)item);
  }
    void
  HotSyncPre (ILxUnknownID view, ILxUnknownID item)
  {
    m_loc[0]->HotSyncPre (m_loc,(ILxUnknownID)view,(ILxUnknownID)item);
  }
    void
  HotSyncPost (ILxUnknownID view, ILxUnknownID item)
  {
    m_loc[0]->HotSyncPost (m_loc,(ILxUnknownID)view,(ILxUnknownID)item);
  }
};

class CLxImpl_ToolModel4 {
  public:
    virtual ~CLxImpl_ToolModel4() {}
    virtual unsigned
      tmod_Flags (void)
        { return LXfTMOD_DRAW_3D; }
    virtual void
      tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Filter (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual void
      tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
        { }
    virtual LxResult
      tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
        { return LXe_NOTIMPL; }
    virtual void
      tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual void
      tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual const char *
      tmod_Haul (unsigned int index)
        { return 0; }
    virtual const char *
      tmod_Help (ILxUnknownID vts)
        { return 0; }
    virtual LxResult
      tmod_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Drop (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Track (ILxUnknownID vts, unsigned int eventType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_TrackFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Post (ILxUnknownID vts)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_TestType (LXtID4 type)
        { return LXe_NOTIMPL; }
    virtual const char *
      tmod_Tooltip (ILxUnknownID vts, int part)
        { return 0; }
};
#define LXxD_ToolModel4_Flags unsigned tmod_Flags (void)
#define LXxO_ToolModel4_Flags LXxD_ToolModel4_Flags LXx_OVERRIDE
#define LXxC_ToolModel4_Flags(c) unsigned c::tmod_Flags (void)
#define LXxD_ToolModel4_Draw void tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxO_ToolModel4_Draw LXxD_ToolModel4_Draw LXx_OVERRIDE
#define LXxC_ToolModel4_Draw(c) void c::tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxD_ToolModel4_Test void tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxO_ToolModel4_Test LXxD_ToolModel4_Test LXx_OVERRIDE
#define LXxC_ToolModel4_Test(c) void c::tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxD_ToolModel4_Filter void tmod_Filter (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel4_Filter LXxD_ToolModel4_Filter LXx_OVERRIDE
#define LXxC_ToolModel4_Filter(c) void c::tmod_Filter (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel4_Initialize void tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
#define LXxO_ToolModel4_Initialize LXxD_ToolModel4_Initialize LXx_OVERRIDE
#define LXxC_ToolModel4_Initialize(c) void c::tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
#define LXxD_ToolModel4_Down LxResult tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel4_Down LXxD_ToolModel4_Down LXx_OVERRIDE
#define LXxC_ToolModel4_Down(c) LxResult c::tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel4_Move void tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel4_Move LXxD_ToolModel4_Move LXx_OVERRIDE
#define LXxC_ToolModel4_Move(c) void c::tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel4_Up void tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel4_Up LXxD_ToolModel4_Up LXx_OVERRIDE
#define LXxC_ToolModel4_Up(c) void c::tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel4_Haul const char * tmod_Haul (unsigned int index)
#define LXxO_ToolModel4_Haul LXxD_ToolModel4_Haul LXx_OVERRIDE
#define LXxC_ToolModel4_Haul(c) const char * c::tmod_Haul (unsigned int index)
#define LXxD_ToolModel4_Help const char * tmod_Help (ILxUnknownID vts)
#define LXxO_ToolModel4_Help LXxD_ToolModel4_Help LXx_OVERRIDE
#define LXxC_ToolModel4_Help(c) const char * c::tmod_Help (ILxUnknownID vts)
#define LXxD_ToolModel4_Enable LxResult tmod_Enable (ILxUnknownID msg)
#define LXxO_ToolModel4_Enable LXxD_ToolModel4_Enable LXx_OVERRIDE
#define LXxC_ToolModel4_Enable(c) LxResult c::tmod_Enable (ILxUnknownID msg)
#define LXxD_ToolModel4_Drop LxResult tmod_Drop (void)
#define LXxO_ToolModel4_Drop LXxD_ToolModel4_Drop LXx_OVERRIDE
#define LXxC_ToolModel4_Drop(c) LxResult c::tmod_Drop (void)
#define LXxD_ToolModel4_Track LxResult tmod_Track (ILxUnknownID vts, unsigned int eventType)
#define LXxO_ToolModel4_Track LXxD_ToolModel4_Track LXx_OVERRIDE
#define LXxC_ToolModel4_Track(c) LxResult c::tmod_Track (ILxUnknownID vts, unsigned int eventType)
#define LXxD_ToolModel4_TrackFlags LxResult tmod_TrackFlags (unsigned int *flags)
#define LXxO_ToolModel4_TrackFlags LXxD_ToolModel4_TrackFlags LXx_OVERRIDE
#define LXxC_ToolModel4_TrackFlags(c) LxResult c::tmod_TrackFlags (unsigned int *flags)
#define LXxD_ToolModel4_Post LxResult tmod_Post (ILxUnknownID vts)
#define LXxO_ToolModel4_Post LXxD_ToolModel4_Post LXx_OVERRIDE
#define LXxC_ToolModel4_Post(c) LxResult c::tmod_Post (ILxUnknownID vts)
#define LXxD_ToolModel4_TestType LxResult tmod_TestType (LXtID4 type)
#define LXxO_ToolModel4_TestType LXxD_ToolModel4_TestType LXx_OVERRIDE
#define LXxC_ToolModel4_TestType(c) LxResult c::tmod_TestType (LXtID4 type)
#define LXxD_ToolModel4_Tooltip const char * tmod_Tooltip (ILxUnknownID vts, int part)
#define LXxO_ToolModel4_Tooltip LXxD_ToolModel4_Tooltip LXx_OVERRIDE
#define LXxC_ToolModel4_Tooltip(c) const char * c::tmod_Tooltip (ILxUnknownID vts, int part)
template <class T>
class CLxIfc_ToolModel4 : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    return loc->tmod_Flags ();
  }
    static void
  Draw (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    loc->tmod_Draw ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Test (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    loc->tmod_Test ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Filter (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    loc->tmod_Filter ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static void
  Initialize (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust, unsigned int flags)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    loc->tmod_Initialize ((ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    static LxResult
  Down (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    try {
      return loc->tmod_Down ((ILxUnknownID)vts,(ILxUnknownID)adjust);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Move (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    loc->tmod_Move ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static void
  Up (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    loc->tmod_Up ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static const char *
  Haul (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    return loc->tmod_Haul (index);
  }
    static const char *
  Help (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    return loc->tmod_Help ((ILxUnknownID)vts);
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    try {
      return loc->tmod_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Drop (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    try {
      return loc->tmod_Drop ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Track (LXtObjectID wcom, LXtObjectID vts, unsigned int eventType)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    try {
      return loc->tmod_Track ((ILxUnknownID)vts,eventType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TrackFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    try {
      return loc->tmod_TrackFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Post (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    try {
      return loc->tmod_Post ((ILxUnknownID)vts);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestType (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    try {
      return loc->tmod_TestType (type);
    } catch (LxResult rc) { return rc; }
  }
    static const char *
  Tooltip (LXtObjectID wcom, LXtObjectID vts, int part)
  {
    LXCWxINST (CLxImpl_ToolModel4, loc);
    return loc->tmod_Tooltip ((ILxUnknownID)vts,part);
  }
  ILxToolModel4 vt;
public:
  CLxIfc_ToolModel4 ()
  {
    vt.Flags = Flags;
    vt.Draw = Draw;
    vt.Test = Test;
    vt.Filter = Filter;
    vt.Initialize = Initialize;
    vt.Down = Down;
    vt.Move = Move;
    vt.Up = Up;
    vt.Haul = Haul;
    vt.Help = Help;
    vt.Enable = Enable;
    vt.Drop = Drop;
    vt.Track = Track;
    vt.TrackFlags = TrackFlags;
    vt.Post = Post;
    vt.TestType = TestType;
    vt.Tooltip = Tooltip;
    vTable = &vt.iunk;
    iid = &lx::guid_ToolModel4;
  }
};
class CLxLoc_ToolModel4 : public CLxLocalize<ILxToolModel4ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ToolModel4() {_init();}
  CLxLoc_ToolModel4(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ToolModel4(const CLxLoc_ToolModel4 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ToolModel4;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    void
  Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Draw (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Test (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Filter (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Filter (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
  {
    m_loc[0]->Initialize (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    LxResult
  Down (ILxUnknownID vts, ILxUnknownID adjust)
  {
    return m_loc[0]->Down (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Move (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Move (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Up (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Up (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    const char *
  Haul (unsigned int index)
  {
    return m_loc[0]->Haul (m_loc,index);
  }
    const char *
  Help (ILxUnknownID vts)
  {
    return m_loc[0]->Help (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  Drop (void)
  {
    return m_loc[0]->Drop (m_loc);
  }
    LxResult
  Track (ILxUnknownID vts, unsigned int eventType)
  {
    return m_loc[0]->Track (m_loc,(ILxUnknownID)vts,eventType);
  }
    LxResult
  TrackFlags (unsigned int *flags)
  {
    return m_loc[0]->TrackFlags (m_loc,flags);
  }
    LxResult
  Post (ILxUnknownID vts)
  {
    return m_loc[0]->Post (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  TestType (LXtID4 type)
  {
    return m_loc[0]->TestType (m_loc,type);
  }
    const char *
  Tooltip (ILxUnknownID vts, int part)
  {
    return m_loc[0]->Tooltip (m_loc,(ILxUnknownID)vts,part);
  }
};

class CLxImpl_ToolModel1 {
  public:
    virtual ~CLxImpl_ToolModel1() {}
    virtual unsigned
      tmod_Flags (void)
        { return LXfTMOD_DRAW_3D; }
    virtual void
      tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Filter (ILxUnknownID vts)
        { }
    virtual void
      tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
        { }
    virtual LxResult
      tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
        { return LXe_NOTIMPL; }
    virtual void
      tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual void
      tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual const char *
      tmod_Haul (unsigned int index)
        { return 0; }
    virtual const char *
      tmod_Help (ILxUnknownID vts)
        { return 0; }
    virtual LxResult
      tmod_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Drop (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Track (ILxUnknownID vts, unsigned int eventType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_TrackFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Post (ILxUnknownID vts)
        { return LXe_NOTIMPL; }
};
#define LXxD_ToolModel1_Flags unsigned tmod_Flags (void)
#define LXxO_ToolModel1_Flags LXxD_ToolModel1_Flags LXx_OVERRIDE
#define LXxC_ToolModel1_Flags(c) unsigned c::tmod_Flags (void)
#define LXxD_ToolModel1_Draw void tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxO_ToolModel1_Draw LXxD_ToolModel1_Draw LXx_OVERRIDE
#define LXxC_ToolModel1_Draw(c) void c::tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxD_ToolModel1_Test void tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxO_ToolModel1_Test LXxD_ToolModel1_Test LXx_OVERRIDE
#define LXxC_ToolModel1_Test(c) void c::tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxD_ToolModel1_Filter void tmod_Filter (ILxUnknownID vts)
#define LXxO_ToolModel1_Filter LXxD_ToolModel1_Filter LXx_OVERRIDE
#define LXxC_ToolModel1_Filter(c) void c::tmod_Filter (ILxUnknownID vts)
#define LXxD_ToolModel1_Initialize void tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
#define LXxO_ToolModel1_Initialize LXxD_ToolModel1_Initialize LXx_OVERRIDE
#define LXxC_ToolModel1_Initialize(c) void c::tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
#define LXxD_ToolModel1_Down LxResult tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel1_Down LXxD_ToolModel1_Down LXx_OVERRIDE
#define LXxC_ToolModel1_Down(c) LxResult c::tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel1_Move void tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel1_Move LXxD_ToolModel1_Move LXx_OVERRIDE
#define LXxC_ToolModel1_Move(c) void c::tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel1_Up void tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel1_Up LXxD_ToolModel1_Up LXx_OVERRIDE
#define LXxC_ToolModel1_Up(c) void c::tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel1_Haul const char * tmod_Haul (unsigned int index)
#define LXxO_ToolModel1_Haul LXxD_ToolModel1_Haul LXx_OVERRIDE
#define LXxC_ToolModel1_Haul(c) const char * c::tmod_Haul (unsigned int index)
#define LXxD_ToolModel1_Help const char * tmod_Help (ILxUnknownID vts)
#define LXxO_ToolModel1_Help LXxD_ToolModel1_Help LXx_OVERRIDE
#define LXxC_ToolModel1_Help(c) const char * c::tmod_Help (ILxUnknownID vts)
#define LXxD_ToolModel1_Enable LxResult tmod_Enable (ILxUnknownID msg)
#define LXxO_ToolModel1_Enable LXxD_ToolModel1_Enable LXx_OVERRIDE
#define LXxC_ToolModel1_Enable(c) LxResult c::tmod_Enable (ILxUnknownID msg)
#define LXxD_ToolModel1_Drop LxResult tmod_Drop (void)
#define LXxO_ToolModel1_Drop LXxD_ToolModel1_Drop LXx_OVERRIDE
#define LXxC_ToolModel1_Drop(c) LxResult c::tmod_Drop (void)
#define LXxD_ToolModel1_Track LxResult tmod_Track (ILxUnknownID vts, unsigned int eventType)
#define LXxO_ToolModel1_Track LXxD_ToolModel1_Track LXx_OVERRIDE
#define LXxC_ToolModel1_Track(c) LxResult c::tmod_Track (ILxUnknownID vts, unsigned int eventType)
#define LXxD_ToolModel1_TrackFlags LxResult tmod_TrackFlags (unsigned int *flags)
#define LXxO_ToolModel1_TrackFlags LXxD_ToolModel1_TrackFlags LXx_OVERRIDE
#define LXxC_ToolModel1_TrackFlags(c) LxResult c::tmod_TrackFlags (unsigned int *flags)
#define LXxD_ToolModel1_Post LxResult tmod_Post (ILxUnknownID vts)
#define LXxO_ToolModel1_Post LXxD_ToolModel1_Post LXx_OVERRIDE
#define LXxC_ToolModel1_Post(c) LxResult c::tmod_Post (ILxUnknownID vts)
template <class T>
class CLxIfc_ToolModel1 : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    return loc->tmod_Flags ();
  }
    static void
  Draw (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    loc->tmod_Draw ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Test (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    loc->tmod_Test ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Filter (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    loc->tmod_Filter ((ILxUnknownID)vts);
  }
    static void
  Initialize (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust, unsigned int flags)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    loc->tmod_Initialize ((ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    static LxResult
  Down (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    try {
      return loc->tmod_Down ((ILxUnknownID)vts,(ILxUnknownID)adjust);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Move (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    loc->tmod_Move ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static void
  Up (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    loc->tmod_Up ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static const char *
  Haul (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    return loc->tmod_Haul (index);
  }
    static const char *
  Help (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    return loc->tmod_Help ((ILxUnknownID)vts);
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    try {
      return loc->tmod_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Drop (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    try {
      return loc->tmod_Drop ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Track (LXtObjectID wcom, LXtObjectID vts, unsigned int eventType)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    try {
      return loc->tmod_Track ((ILxUnknownID)vts,eventType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TrackFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    try {
      return loc->tmod_TrackFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Post (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel1, loc);
    try {
      return loc->tmod_Post ((ILxUnknownID)vts);
    } catch (LxResult rc) { return rc; }
  }
  ILxToolModel1 vt;
public:
  CLxIfc_ToolModel1 ()
  {
    vt.Flags = Flags;
    vt.Draw = Draw;
    vt.Test = Test;
    vt.Filter = Filter;
    vt.Initialize = Initialize;
    vt.Down = Down;
    vt.Move = Move;
    vt.Up = Up;
    vt.Haul = Haul;
    vt.Help = Help;
    vt.Enable = Enable;
    vt.Drop = Drop;
    vt.Track = Track;
    vt.TrackFlags = TrackFlags;
    vt.Post = Post;
    vTable = &vt.iunk;
    iid = &lx::guid_ToolModel1;
  }
};
class CLxLoc_ToolModel1 : public CLxLocalize<ILxToolModel1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ToolModel1() {_init();}
  CLxLoc_ToolModel1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ToolModel1(const CLxLoc_ToolModel1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ToolModel1;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    void
  Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Draw (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Test (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Filter (ILxUnknownID vts)
  {
    m_loc[0]->Filter (m_loc,(ILxUnknownID)vts);
  }
    void
  Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
  {
    m_loc[0]->Initialize (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    LxResult
  Down (ILxUnknownID vts, ILxUnknownID adjust)
  {
    return m_loc[0]->Down (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Move (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Move (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Up (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Up (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    const char *
  Haul (unsigned int index)
  {
    return m_loc[0]->Haul (m_loc,index);
  }
    const char *
  Help (ILxUnknownID vts)
  {
    return m_loc[0]->Help (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  Drop (void)
  {
    return m_loc[0]->Drop (m_loc);
  }
    LxResult
  Track (ILxUnknownID vts, unsigned int eventType)
  {
    return m_loc[0]->Track (m_loc,(ILxUnknownID)vts,eventType);
  }
    LxResult
  TrackFlags (unsigned int *flags)
  {
    return m_loc[0]->TrackFlags (m_loc,flags);
  }
    LxResult
  Post (ILxUnknownID vts)
  {
    return m_loc[0]->Post (m_loc,(ILxUnknownID)vts);
  }
};

class CLxImpl_ToolModel3 {
  public:
    virtual ~CLxImpl_ToolModel3() {}
    virtual unsigned
      tmod_Flags (void)
        { return LXfTMOD_DRAW_3D; }
    virtual void
      tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Filter (ILxUnknownID vts)
        { }
    virtual void
      tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
        { }
    virtual LxResult
      tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
        { return LXe_NOTIMPL; }
    virtual void
      tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual void
      tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual const char *
      tmod_Haul (unsigned int index)
        { return 0; }
    virtual const char *
      tmod_Help (ILxUnknownID vts)
        { return 0; }
    virtual LxResult
      tmod_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Drop (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Track (ILxUnknownID vts, unsigned int eventType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_TrackFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Post (ILxUnknownID vts)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_TestType (LXtID4 type)
        { return LXe_NOTIMPL; }
    virtual const char *
      tmod_Tooltip (ILxUnknownID vts, int part)
        = 0;
};
#define LXxD_ToolModel3_Flags unsigned tmod_Flags (void)
#define LXxO_ToolModel3_Flags LXxD_ToolModel3_Flags LXx_OVERRIDE
#define LXxC_ToolModel3_Flags(c) unsigned c::tmod_Flags (void)
#define LXxD_ToolModel3_Draw void tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxO_ToolModel3_Draw LXxD_ToolModel3_Draw LXx_OVERRIDE
#define LXxC_ToolModel3_Draw(c) void c::tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxD_ToolModel3_Test void tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxO_ToolModel3_Test LXxD_ToolModel3_Test LXx_OVERRIDE
#define LXxC_ToolModel3_Test(c) void c::tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxD_ToolModel3_Filter void tmod_Filter (ILxUnknownID vts)
#define LXxO_ToolModel3_Filter LXxD_ToolModel3_Filter LXx_OVERRIDE
#define LXxC_ToolModel3_Filter(c) void c::tmod_Filter (ILxUnknownID vts)
#define LXxD_ToolModel3_Initialize void tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
#define LXxO_ToolModel3_Initialize LXxD_ToolModel3_Initialize LXx_OVERRIDE
#define LXxC_ToolModel3_Initialize(c) void c::tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
#define LXxD_ToolModel3_Down LxResult tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel3_Down LXxD_ToolModel3_Down LXx_OVERRIDE
#define LXxC_ToolModel3_Down(c) LxResult c::tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel3_Move void tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel3_Move LXxD_ToolModel3_Move LXx_OVERRIDE
#define LXxC_ToolModel3_Move(c) void c::tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel3_Up void tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel3_Up LXxD_ToolModel3_Up LXx_OVERRIDE
#define LXxC_ToolModel3_Up(c) void c::tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel3_Haul const char * tmod_Haul (unsigned int index)
#define LXxO_ToolModel3_Haul LXxD_ToolModel3_Haul LXx_OVERRIDE
#define LXxC_ToolModel3_Haul(c) const char * c::tmod_Haul (unsigned int index)
#define LXxD_ToolModel3_Help const char * tmod_Help (ILxUnknownID vts)
#define LXxO_ToolModel3_Help LXxD_ToolModel3_Help LXx_OVERRIDE
#define LXxC_ToolModel3_Help(c) const char * c::tmod_Help (ILxUnknownID vts)
#define LXxD_ToolModel3_Enable LxResult tmod_Enable (ILxUnknownID msg)
#define LXxO_ToolModel3_Enable LXxD_ToolModel3_Enable LXx_OVERRIDE
#define LXxC_ToolModel3_Enable(c) LxResult c::tmod_Enable (ILxUnknownID msg)
#define LXxD_ToolModel3_Drop LxResult tmod_Drop (void)
#define LXxO_ToolModel3_Drop LXxD_ToolModel3_Drop LXx_OVERRIDE
#define LXxC_ToolModel3_Drop(c) LxResult c::tmod_Drop (void)
#define LXxD_ToolModel3_Track LxResult tmod_Track (ILxUnknownID vts, unsigned int eventType)
#define LXxO_ToolModel3_Track LXxD_ToolModel3_Track LXx_OVERRIDE
#define LXxC_ToolModel3_Track(c) LxResult c::tmod_Track (ILxUnknownID vts, unsigned int eventType)
#define LXxD_ToolModel3_TrackFlags LxResult tmod_TrackFlags (unsigned int *flags)
#define LXxO_ToolModel3_TrackFlags LXxD_ToolModel3_TrackFlags LXx_OVERRIDE
#define LXxC_ToolModel3_TrackFlags(c) LxResult c::tmod_TrackFlags (unsigned int *flags)
#define LXxD_ToolModel3_Post LxResult tmod_Post (ILxUnknownID vts)
#define LXxO_ToolModel3_Post LXxD_ToolModel3_Post LXx_OVERRIDE
#define LXxC_ToolModel3_Post(c) LxResult c::tmod_Post (ILxUnknownID vts)
#define LXxD_ToolModel3_TestType LxResult tmod_TestType (LXtID4 type)
#define LXxO_ToolModel3_TestType LXxD_ToolModel3_TestType LXx_OVERRIDE
#define LXxC_ToolModel3_TestType(c) LxResult c::tmod_TestType (LXtID4 type)
#define LXxD_ToolModel3_Tooltip const char * tmod_Tooltip (ILxUnknownID vts, int part)
#define LXxO_ToolModel3_Tooltip LXxD_ToolModel3_Tooltip LXx_OVERRIDE
#define LXxC_ToolModel3_Tooltip(c) const char * c::tmod_Tooltip (ILxUnknownID vts, int part)
template <class T>
class CLxIfc_ToolModel3 : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    return loc->tmod_Flags ();
  }
    static void
  Draw (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    loc->tmod_Draw ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Test (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    loc->tmod_Test ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Filter (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    loc->tmod_Filter ((ILxUnknownID)vts);
  }
    static void
  Initialize (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust, unsigned int flags)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    loc->tmod_Initialize ((ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    static LxResult
  Down (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    try {
      return loc->tmod_Down ((ILxUnknownID)vts,(ILxUnknownID)adjust);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Move (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    loc->tmod_Move ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static void
  Up (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    loc->tmod_Up ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static const char *
  Haul (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    return loc->tmod_Haul (index);
  }
    static const char *
  Help (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    return loc->tmod_Help ((ILxUnknownID)vts);
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    try {
      return loc->tmod_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Drop (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    try {
      return loc->tmod_Drop ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Track (LXtObjectID wcom, LXtObjectID vts, unsigned int eventType)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    try {
      return loc->tmod_Track ((ILxUnknownID)vts,eventType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TrackFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    try {
      return loc->tmod_TrackFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Post (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    try {
      return loc->tmod_Post ((ILxUnknownID)vts);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestType (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    try {
      return loc->tmod_TestType (type);
    } catch (LxResult rc) { return rc; }
  }
    static const char *
  Tooltip (LXtObjectID wcom, LXtObjectID vts, int part)
  {
    LXCWxINST (CLxImpl_ToolModel3, loc);
    return loc->tmod_Tooltip ((ILxUnknownID)vts,part);
  }
  ILxToolModel3 vt;
public:
  CLxIfc_ToolModel3 ()
  {
    vt.Flags = Flags;
    vt.Draw = Draw;
    vt.Test = Test;
    vt.Filter = Filter;
    vt.Initialize = Initialize;
    vt.Down = Down;
    vt.Move = Move;
    vt.Up = Up;
    vt.Haul = Haul;
    vt.Help = Help;
    vt.Enable = Enable;
    vt.Drop = Drop;
    vt.Track = Track;
    vt.TrackFlags = TrackFlags;
    vt.Post = Post;
    vt.TestType = TestType;
    vt.Tooltip = Tooltip;
    vTable = &vt.iunk;
    iid = &lx::guid_ToolModel3;
  }
};
class CLxLoc_ToolModel3 : public CLxLocalize<ILxToolModel3ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ToolModel3() {_init();}
  CLxLoc_ToolModel3(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ToolModel3(const CLxLoc_ToolModel3 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ToolModel3;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    void
  Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Draw (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Test (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Filter (ILxUnknownID vts)
  {
    m_loc[0]->Filter (m_loc,(ILxUnknownID)vts);
  }
    void
  Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
  {
    m_loc[0]->Initialize (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    LxResult
  Down (ILxUnknownID vts, ILxUnknownID adjust)
  {
    return m_loc[0]->Down (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Move (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Move (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Up (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Up (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    const char *
  Haul (unsigned int index)
  {
    return m_loc[0]->Haul (m_loc,index);
  }
    const char *
  Help (ILxUnknownID vts)
  {
    return m_loc[0]->Help (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  Drop (void)
  {
    return m_loc[0]->Drop (m_loc);
  }
    LxResult
  Track (ILxUnknownID vts, unsigned int eventType)
  {
    return m_loc[0]->Track (m_loc,(ILxUnknownID)vts,eventType);
  }
    LxResult
  TrackFlags (unsigned int *flags)
  {
    return m_loc[0]->TrackFlags (m_loc,flags);
  }
    LxResult
  Post (ILxUnknownID vts)
  {
    return m_loc[0]->Post (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  TestType (LXtID4 type)
  {
    return m_loc[0]->TestType (m_loc,type);
  }
    const char *
  Tooltip (ILxUnknownID vts, int part)
  {
    return m_loc[0]->Tooltip (m_loc,(ILxUnknownID)vts,part);
  }
};

class CLxImpl_ViewItem3D {
  public:
    virtual ~CLxImpl_ViewItem3D() {}
    virtual LxResult
      vitm_Draw (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, const LXtVector itemColor)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_DrawBackground (ILxUnknownID chanRead, ILxUnknownID strokeDraw, const LXtVector itemColor)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_WorldSpace (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleMotion (int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleChannel (int handleIndex, int *chanIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleValueToPosition (int handleIndex, const double *chanValue, LXtVector position)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandlePositionToValue (int handleIndex, const LXtVector position, double *chanValue)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_Test (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, const LXtVector itemColor)
        { return LXe_NOTIMPL; }
};
#define LXxD_ViewItem3D_Draw LxResult vitm_Draw (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, const LXtVector itemColor)
#define LXxO_ViewItem3D_Draw LXxD_ViewItem3D_Draw LXx_OVERRIDE
#define LXxC_ViewItem3D_Draw(c) LxResult c::vitm_Draw (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, const LXtVector itemColor)
#define LXxD_ViewItem3D_DrawBackground LxResult vitm_DrawBackground (ILxUnknownID chanRead, ILxUnknownID strokeDraw, const LXtVector itemColor)
#define LXxO_ViewItem3D_DrawBackground LXxD_ViewItem3D_DrawBackground LXx_OVERRIDE
#define LXxC_ViewItem3D_DrawBackground(c) LxResult c::vitm_DrawBackground (ILxUnknownID chanRead, ILxUnknownID strokeDraw, const LXtVector itemColor)
#define LXxD_ViewItem3D_WorldSpace LxResult vitm_WorldSpace (void)
#define LXxO_ViewItem3D_WorldSpace LXxD_ViewItem3D_WorldSpace LXx_OVERRIDE
#define LXxC_ViewItem3D_WorldSpace(c) LxResult c::vitm_WorldSpace (void)
#define LXxD_ViewItem3D_HandleCount LxResult vitm_HandleCount (int *count)
#define LXxO_ViewItem3D_HandleCount LXxD_ViewItem3D_HandleCount LXx_OVERRIDE
#define LXxC_ViewItem3D_HandleCount(c) LxResult c::vitm_HandleCount (int *count)
#define LXxD_ViewItem3D_HandleMotion LxResult vitm_HandleMotion (int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset)
#define LXxO_ViewItem3D_HandleMotion LXxD_ViewItem3D_HandleMotion LXx_OVERRIDE
#define LXxC_ViewItem3D_HandleMotion(c) LxResult c::vitm_HandleMotion (int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset)
#define LXxD_ViewItem3D_HandleChannel LxResult vitm_HandleChannel (int handleIndex, int *chanIndex)
#define LXxO_ViewItem3D_HandleChannel LXxD_ViewItem3D_HandleChannel LXx_OVERRIDE
#define LXxC_ViewItem3D_HandleChannel(c) LxResult c::vitm_HandleChannel (int handleIndex, int *chanIndex)
#define LXxD_ViewItem3D_HandleValueToPosition LxResult vitm_HandleValueToPosition (int handleIndex, const double *chanValue, LXtVector position)
#define LXxO_ViewItem3D_HandleValueToPosition LXxD_ViewItem3D_HandleValueToPosition LXx_OVERRIDE
#define LXxC_ViewItem3D_HandleValueToPosition(c) LxResult c::vitm_HandleValueToPosition (int handleIndex, const double *chanValue, LXtVector position)
#define LXxD_ViewItem3D_HandlePositionToValue LxResult vitm_HandlePositionToValue (int handleIndex, const LXtVector position, double *chanValue)
#define LXxO_ViewItem3D_HandlePositionToValue LXxD_ViewItem3D_HandlePositionToValue LXx_OVERRIDE
#define LXxC_ViewItem3D_HandlePositionToValue(c) LxResult c::vitm_HandlePositionToValue (int handleIndex, const LXtVector position, double *chanValue)
#define LXxD_ViewItem3D_Test LxResult vitm_Test (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, const LXtVector itemColor)
#define LXxO_ViewItem3D_Test LXxD_ViewItem3D_Test LXx_OVERRIDE
#define LXxC_ViewItem3D_Test(c) LxResult c::vitm_Test (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, const LXtVector itemColor)
template <class T>
class CLxIfc_ViewItem3D : public CLxInterface
{
    static LxResult
  Draw (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID strokeDraw, int selectionFlags, const LXtVector itemColor)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_Draw ((ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,selectionFlags,itemColor);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DrawBackground (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID strokeDraw, const LXtVector itemColor)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_DrawBackground ((ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,itemColor);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  WorldSpace (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_WorldSpace ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_HandleCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleMotion (LXtObjectID wcom, int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_HandleMotion (handleIndex,handleFlags,min,max,plane,offset);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleChannel (LXtObjectID wcom, int handleIndex, int *chanIndex)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_HandleChannel (handleIndex,chanIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleValueToPosition (LXtObjectID wcom, int handleIndex, const double *chanValue, LXtVector position)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_HandleValueToPosition (handleIndex,chanValue,position);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandlePositionToValue (LXtObjectID wcom, int handleIndex, const LXtVector position, double *chanValue)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_HandlePositionToValue (handleIndex,position,chanValue);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Test (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID strokeDraw, int selectionFlags, const LXtVector itemColor)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_Test ((ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,selectionFlags,itemColor);
    } catch (LxResult rc) { return rc; }
  }
  ILxViewItem3D vt;
public:
  CLxIfc_ViewItem3D ()
  {
    vt.Draw = Draw;
    vt.DrawBackground = DrawBackground;
    vt.WorldSpace = WorldSpace;
    vt.HandleCount = HandleCount;
    vt.HandleMotion = HandleMotion;
    vt.HandleChannel = HandleChannel;
    vt.HandleValueToPosition = HandleValueToPosition;
    vt.HandlePositionToValue = HandlePositionToValue;
    vt.Test = Test;
    vTable = &vt.iunk;
    iid = &lx::guid_ViewItem3D;
  }
};
class CLxLoc_ViewItem3D : public CLxLocalize<ILxViewItem3DID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ViewItem3D() {_init();}
  CLxLoc_ViewItem3D(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ViewItem3D(const CLxLoc_ViewItem3D &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ViewItem3D;}
    LxResult
  Draw (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, const LXtVector itemColor)
  {
    return m_loc[0]->Draw (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,selectionFlags,itemColor);
  }
    LxResult
  DrawBackground (ILxUnknownID chanRead, ILxUnknownID strokeDraw, const LXtVector itemColor)
  {
    return m_loc[0]->DrawBackground (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,itemColor);
  }
    LxResult
  WorldSpace (void)
  {
    return m_loc[0]->WorldSpace (m_loc);
  }
    LxResult
  HandleCount (int *count)
  {
    return m_loc[0]->HandleCount (m_loc,count);
  }
    LxResult
  HandleMotion (int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset)
  {
    return m_loc[0]->HandleMotion (m_loc,handleIndex,handleFlags,min,max,plane,offset);
  }
    LxResult
  HandleChannel (int handleIndex, int *chanIndex)
  {
    return m_loc[0]->HandleChannel (m_loc,handleIndex,chanIndex);
  }
    LxResult
  HandleValueToPosition (int handleIndex, const double *chanValue, LXtVector position)
  {
    return m_loc[0]->HandleValueToPosition (m_loc,handleIndex,chanValue,position);
  }
    LxResult
  HandlePositionToValue (int handleIndex, const LXtVector position, double *chanValue)
  {
    return m_loc[0]->HandlePositionToValue (m_loc,handleIndex,position,chanValue);
  }
    LxResult
  Test (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, const LXtVector itemColor)
  {
    return m_loc[0]->Test (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,selectionFlags,itemColor);
  }
};

class CLxImpl_ToolModel2 {
  public:
    virtual ~CLxImpl_ToolModel2() {}
    virtual unsigned
      tmod_Flags (void)
        { return LXfTMOD_DRAW_3D; }
    virtual void
      tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Filter (ILxUnknownID vts)
        { }
    virtual void
      tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
        { }
    virtual LxResult
      tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
        { return LXe_NOTIMPL; }
    virtual void
      tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual void
      tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual const char *
      tmod_Haul (unsigned int index)
        { return 0; }
    virtual const char *
      tmod_Help (ILxUnknownID vts)
        { return 0; }
    virtual LxResult
      tmod_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Drop (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Track (ILxUnknownID vts, unsigned int eventType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_TrackFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Post (ILxUnknownID vts)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_TestType (LXtID4 type)
        { return LXe_NOTIMPL; }
};
#define LXxD_ToolModel2_Flags unsigned tmod_Flags (void)
#define LXxO_ToolModel2_Flags LXxD_ToolModel2_Flags LXx_OVERRIDE
#define LXxC_ToolModel2_Flags(c) unsigned c::tmod_Flags (void)
#define LXxD_ToolModel2_Draw void tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxO_ToolModel2_Draw LXxD_ToolModel2_Draw LXx_OVERRIDE
#define LXxC_ToolModel2_Draw(c) void c::tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxD_ToolModel2_Test void tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxO_ToolModel2_Test LXxD_ToolModel2_Test LXx_OVERRIDE
#define LXxC_ToolModel2_Test(c) void c::tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxD_ToolModel2_Filter void tmod_Filter (ILxUnknownID vts)
#define LXxO_ToolModel2_Filter LXxD_ToolModel2_Filter LXx_OVERRIDE
#define LXxC_ToolModel2_Filter(c) void c::tmod_Filter (ILxUnknownID vts)
#define LXxD_ToolModel2_Initialize void tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
#define LXxO_ToolModel2_Initialize LXxD_ToolModel2_Initialize LXx_OVERRIDE
#define LXxC_ToolModel2_Initialize(c) void c::tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
#define LXxD_ToolModel2_Down LxResult tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel2_Down LXxD_ToolModel2_Down LXx_OVERRIDE
#define LXxC_ToolModel2_Down(c) LxResult c::tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel2_Move void tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel2_Move LXxD_ToolModel2_Move LXx_OVERRIDE
#define LXxC_ToolModel2_Move(c) void c::tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel2_Up void tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel2_Up LXxD_ToolModel2_Up LXx_OVERRIDE
#define LXxC_ToolModel2_Up(c) void c::tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel2_Haul const char * tmod_Haul (unsigned int index)
#define LXxO_ToolModel2_Haul LXxD_ToolModel2_Haul LXx_OVERRIDE
#define LXxC_ToolModel2_Haul(c) const char * c::tmod_Haul (unsigned int index)
#define LXxD_ToolModel2_Help const char * tmod_Help (ILxUnknownID vts)
#define LXxO_ToolModel2_Help LXxD_ToolModel2_Help LXx_OVERRIDE
#define LXxC_ToolModel2_Help(c) const char * c::tmod_Help (ILxUnknownID vts)
#define LXxD_ToolModel2_Enable LxResult tmod_Enable (ILxUnknownID msg)
#define LXxO_ToolModel2_Enable LXxD_ToolModel2_Enable LXx_OVERRIDE
#define LXxC_ToolModel2_Enable(c) LxResult c::tmod_Enable (ILxUnknownID msg)
#define LXxD_ToolModel2_Drop LxResult tmod_Drop (void)
#define LXxO_ToolModel2_Drop LXxD_ToolModel2_Drop LXx_OVERRIDE
#define LXxC_ToolModel2_Drop(c) LxResult c::tmod_Drop (void)
#define LXxD_ToolModel2_Track LxResult tmod_Track (ILxUnknownID vts, unsigned int eventType)
#define LXxO_ToolModel2_Track LXxD_ToolModel2_Track LXx_OVERRIDE
#define LXxC_ToolModel2_Track(c) LxResult c::tmod_Track (ILxUnknownID vts, unsigned int eventType)
#define LXxD_ToolModel2_TrackFlags LxResult tmod_TrackFlags (unsigned int *flags)
#define LXxO_ToolModel2_TrackFlags LXxD_ToolModel2_TrackFlags LXx_OVERRIDE
#define LXxC_ToolModel2_TrackFlags(c) LxResult c::tmod_TrackFlags (unsigned int *flags)
#define LXxD_ToolModel2_Post LxResult tmod_Post (ILxUnknownID vts)
#define LXxO_ToolModel2_Post LXxD_ToolModel2_Post LXx_OVERRIDE
#define LXxC_ToolModel2_Post(c) LxResult c::tmod_Post (ILxUnknownID vts)
#define LXxD_ToolModel2_TestType LxResult tmod_TestType (LXtID4 type)
#define LXxO_ToolModel2_TestType LXxD_ToolModel2_TestType LXx_OVERRIDE
#define LXxC_ToolModel2_TestType(c) LxResult c::tmod_TestType (LXtID4 type)
template <class T>
class CLxIfc_ToolModel2 : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    return loc->tmod_Flags ();
  }
    static void
  Draw (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    loc->tmod_Draw ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Test (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    loc->tmod_Test ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Filter (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    loc->tmod_Filter ((ILxUnknownID)vts);
  }
    static void
  Initialize (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust, unsigned int flags)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    loc->tmod_Initialize ((ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    static LxResult
  Down (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    try {
      return loc->tmod_Down ((ILxUnknownID)vts,(ILxUnknownID)adjust);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Move (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    loc->tmod_Move ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static void
  Up (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    loc->tmod_Up ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static const char *
  Haul (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    return loc->tmod_Haul (index);
  }
    static const char *
  Help (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    return loc->tmod_Help ((ILxUnknownID)vts);
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    try {
      return loc->tmod_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Drop (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    try {
      return loc->tmod_Drop ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Track (LXtObjectID wcom, LXtObjectID vts, unsigned int eventType)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    try {
      return loc->tmod_Track ((ILxUnknownID)vts,eventType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TrackFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    try {
      return loc->tmod_TrackFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Post (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    try {
      return loc->tmod_Post ((ILxUnknownID)vts);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestType (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_ToolModel2, loc);
    try {
      return loc->tmod_TestType (type);
    } catch (LxResult rc) { return rc; }
  }
  ILxToolModel2 vt;
public:
  CLxIfc_ToolModel2 ()
  {
    vt.Flags = Flags;
    vt.Draw = Draw;
    vt.Test = Test;
    vt.Filter = Filter;
    vt.Initialize = Initialize;
    vt.Down = Down;
    vt.Move = Move;
    vt.Up = Up;
    vt.Haul = Haul;
    vt.Help = Help;
    vt.Enable = Enable;
    vt.Drop = Drop;
    vt.Track = Track;
    vt.TrackFlags = TrackFlags;
    vt.Post = Post;
    vt.TestType = TestType;
    vTable = &vt.iunk;
    iid = &lx::guid_ToolModel2;
  }
};
class CLxLoc_ToolModel2 : public CLxLocalize<ILxToolModel2ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ToolModel2() {_init();}
  CLxLoc_ToolModel2(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ToolModel2(const CLxLoc_ToolModel2 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ToolModel2;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    void
  Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Draw (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Test (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Filter (ILxUnknownID vts)
  {
    m_loc[0]->Filter (m_loc,(ILxUnknownID)vts);
  }
    void
  Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
  {
    m_loc[0]->Initialize (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    LxResult
  Down (ILxUnknownID vts, ILxUnknownID adjust)
  {
    return m_loc[0]->Down (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Move (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Move (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Up (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Up (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    const char *
  Haul (unsigned int index)
  {
    return m_loc[0]->Haul (m_loc,index);
  }
    const char *
  Help (ILxUnknownID vts)
  {
    return m_loc[0]->Help (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  Drop (void)
  {
    return m_loc[0]->Drop (m_loc);
  }
    LxResult
  Track (ILxUnknownID vts, unsigned int eventType)
  {
    return m_loc[0]->Track (m_loc,(ILxUnknownID)vts,eventType);
  }
    LxResult
  TrackFlags (unsigned int *flags)
  {
    return m_loc[0]->TrackFlags (m_loc,flags);
  }
    LxResult
  Post (ILxUnknownID vts)
  {
    return m_loc[0]->Post (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  TestType (LXtID4 type)
  {
    return m_loc[0]->TestType (m_loc,type);
  }
};

class CLxImpl_ViewItem3D1 {
  public:
    virtual ~CLxImpl_ViewItem3D1() {}
    virtual LxResult
      vitm_Draw (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, LXtVector itemColor)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_DrawBackground (ILxUnknownID chanRead, ILxUnknownID strokeDraw, LXtVector itemColor)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_WorldSpace (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleMotion (int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleChannel (int handleIndex, int *chanIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleValueToPosition (int handleIndex, double *chanValue, LXtVector position)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandlePositionToValue (int handleIndex, LXtVector position, double *chanValue)
        { return LXe_NOTIMPL; }
};
#define LXxD_ViewItem3D1_Draw LxResult vitm_Draw (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, LXtVector itemColor)
#define LXxO_ViewItem3D1_Draw LXxD_ViewItem3D1_Draw LXx_OVERRIDE
#define LXxC_ViewItem3D1_Draw(c) LxResult c::vitm_Draw (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, LXtVector itemColor)
#define LXxD_ViewItem3D1_DrawBackground LxResult vitm_DrawBackground (ILxUnknownID chanRead, ILxUnknownID strokeDraw, LXtVector itemColor)
#define LXxO_ViewItem3D1_DrawBackground LXxD_ViewItem3D1_DrawBackground LXx_OVERRIDE
#define LXxC_ViewItem3D1_DrawBackground(c) LxResult c::vitm_DrawBackground (ILxUnknownID chanRead, ILxUnknownID strokeDraw, LXtVector itemColor)
#define LXxD_ViewItem3D1_WorldSpace LxResult vitm_WorldSpace (void)
#define LXxO_ViewItem3D1_WorldSpace LXxD_ViewItem3D1_WorldSpace LXx_OVERRIDE
#define LXxC_ViewItem3D1_WorldSpace(c) LxResult c::vitm_WorldSpace (void)
#define LXxD_ViewItem3D1_HandleCount LxResult vitm_HandleCount (int *count)
#define LXxO_ViewItem3D1_HandleCount LXxD_ViewItem3D1_HandleCount LXx_OVERRIDE
#define LXxC_ViewItem3D1_HandleCount(c) LxResult c::vitm_HandleCount (int *count)
#define LXxD_ViewItem3D1_HandleMotion LxResult vitm_HandleMotion (int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset)
#define LXxO_ViewItem3D1_HandleMotion LXxD_ViewItem3D1_HandleMotion LXx_OVERRIDE
#define LXxC_ViewItem3D1_HandleMotion(c) LxResult c::vitm_HandleMotion (int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset)
#define LXxD_ViewItem3D1_HandleChannel LxResult vitm_HandleChannel (int handleIndex, int *chanIndex)
#define LXxO_ViewItem3D1_HandleChannel LXxD_ViewItem3D1_HandleChannel LXx_OVERRIDE
#define LXxC_ViewItem3D1_HandleChannel(c) LxResult c::vitm_HandleChannel (int handleIndex, int *chanIndex)
#define LXxD_ViewItem3D1_HandleValueToPosition LxResult vitm_HandleValueToPosition (int handleIndex, double *chanValue, LXtVector position)
#define LXxO_ViewItem3D1_HandleValueToPosition LXxD_ViewItem3D1_HandleValueToPosition LXx_OVERRIDE
#define LXxC_ViewItem3D1_HandleValueToPosition(c) LxResult c::vitm_HandleValueToPosition (int handleIndex, double *chanValue, LXtVector position)
#define LXxD_ViewItem3D1_HandlePositionToValue LxResult vitm_HandlePositionToValue (int handleIndex, LXtVector position, double *chanValue)
#define LXxO_ViewItem3D1_HandlePositionToValue LXxD_ViewItem3D1_HandlePositionToValue LXx_OVERRIDE
#define LXxC_ViewItem3D1_HandlePositionToValue(c) LxResult c::vitm_HandlePositionToValue (int handleIndex, LXtVector position, double *chanValue)
template <class T>
class CLxIfc_ViewItem3D1 : public CLxInterface
{
    static LxResult
  Draw (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID strokeDraw, int selectionFlags, LXtVector itemColor)
  {
    LXCWxINST (CLxImpl_ViewItem3D1, loc);
    try {
      return loc->vitm_Draw ((ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,selectionFlags,itemColor);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DrawBackground (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID strokeDraw, LXtVector itemColor)
  {
    LXCWxINST (CLxImpl_ViewItem3D1, loc);
    try {
      return loc->vitm_DrawBackground ((ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,itemColor);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  WorldSpace (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ViewItem3D1, loc);
    try {
      return loc->vitm_WorldSpace ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_ViewItem3D1, loc);
    try {
      return loc->vitm_HandleCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleMotion (LXtObjectID wcom, int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset)
  {
    LXCWxINST (CLxImpl_ViewItem3D1, loc);
    try {
      return loc->vitm_HandleMotion (handleIndex,handleFlags,min,max,plane,offset);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleChannel (LXtObjectID wcom, int handleIndex, int *chanIndex)
  {
    LXCWxINST (CLxImpl_ViewItem3D1, loc);
    try {
      return loc->vitm_HandleChannel (handleIndex,chanIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleValueToPosition (LXtObjectID wcom, int handleIndex, double *chanValue, LXtVector position)
  {
    LXCWxINST (CLxImpl_ViewItem3D1, loc);
    try {
      return loc->vitm_HandleValueToPosition (handleIndex,chanValue,position);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandlePositionToValue (LXtObjectID wcom, int handleIndex, LXtVector position, double *chanValue)
  {
    LXCWxINST (CLxImpl_ViewItem3D1, loc);
    try {
      return loc->vitm_HandlePositionToValue (handleIndex,position,chanValue);
    } catch (LxResult rc) { return rc; }
  }
  ILxViewItem3D1 vt;
public:
  CLxIfc_ViewItem3D1 ()
  {
    vt.Draw = Draw;
    vt.DrawBackground = DrawBackground;
    vt.WorldSpace = WorldSpace;
    vt.HandleCount = HandleCount;
    vt.HandleMotion = HandleMotion;
    vt.HandleChannel = HandleChannel;
    vt.HandleValueToPosition = HandleValueToPosition;
    vt.HandlePositionToValue = HandlePositionToValue;
    vTable = &vt.iunk;
    iid = &lx::guid_ViewItem3D1;
  }
};
class CLxLoc_ViewItem3D1 : public CLxLocalize<ILxViewItem3D1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ViewItem3D1() {_init();}
  CLxLoc_ViewItem3D1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ViewItem3D1(const CLxLoc_ViewItem3D1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ViewItem3D1;}
    LxResult
  Draw (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, LXtVector itemColor)
  {
    return m_loc[0]->Draw (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,selectionFlags,itemColor);
  }
    LxResult
  DrawBackground (ILxUnknownID chanRead, ILxUnknownID strokeDraw, LXtVector itemColor)
  {
    return m_loc[0]->DrawBackground (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,itemColor);
  }
    LxResult
  WorldSpace (void)
  {
    return m_loc[0]->WorldSpace (m_loc);
  }
    LxResult
  HandleCount (int *count)
  {
    return m_loc[0]->HandleCount (m_loc,count);
  }
    LxResult
  HandleMotion (int handleIndex, int *handleFlags, double *min, double *max, LXtVector plane, LXtVector offset)
  {
    return m_loc[0]->HandleMotion (m_loc,handleIndex,handleFlags,min,max,plane,offset);
  }
    LxResult
  HandleChannel (int handleIndex, int *chanIndex)
  {
    return m_loc[0]->HandleChannel (m_loc,handleIndex,chanIndex);
  }
    LxResult
  HandleValueToPosition (int handleIndex, double *chanValue, LXtVector position)
  {
    return m_loc[0]->HandleValueToPosition (m_loc,handleIndex,chanValue,position);
  }
    LxResult
  HandlePositionToValue (int handleIndex, LXtVector position, double *chanValue)
  {
    return m_loc[0]->HandlePositionToValue (m_loc,handleIndex,position,chanValue);
  }
};

class CLxLoc_AdjustTool : public CLxLocalize<ILxAdjustToolID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AdjustTool() {_init();}
  CLxLoc_AdjustTool(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AdjustTool(const CLxLoc_AdjustTool &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AdjustTool;}
    void
  Value (unsigned int index, ILxUnknownID val)
  {
    m_loc[0]->Value (m_loc,index,(ILxUnknownID)val);
  }
    void
  SetInt (unsigned int index, int val)
  {
    m_loc[0]->SetInt (m_loc,index,val);
  }
    void
  SetFlt (unsigned int index, double val)
  {
    m_loc[0]->SetFlt (m_loc,index,val);
  }
    void
  SetString (unsigned int index, const char *val)
  {
    m_loc[0]->SetString (m_loc,index,val);
  }
    void
  Lock (void)
  {
    m_loc[0]->Lock (m_loc);
  }
    void
  Invalidate (void)
  {
    m_loc[0]->Invalidate (m_loc);
  }
    void
  Update (void)
  {
    m_loc[0]->Update (m_loc);
  }
};

class CLxImpl_ToolModel {
  public:
    virtual ~CLxImpl_ToolModel() {}
    virtual unsigned
      tmod_Flags (void)
        { return LXfTMOD_DRAW_3D; }
    virtual void
      tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Filter (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual void
      tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
        { }
    virtual LxResult
      tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
        { return LXe_NOTIMPL; }
    virtual void
      tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual void
      tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual const char *
      tmod_Haul (unsigned int index)
        { return 0; }
    virtual LxResult
      tmod_AllowOverride (const char *attrName, unsigned int mouseInput, unsigned int haulAxis)
        { return LXe_NOTIMPL; }
    virtual const char *
      tmod_Help (ILxUnknownID vts)
        { return 0; }
    virtual LxResult
      tmod_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Drop (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Track (ILxUnknownID vts, unsigned int eventType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_TrackFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Post (ILxUnknownID vts)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_TestType (LXtID4 type)
        { return LXe_NOTIMPL; }
    virtual const char *
      tmod_Tooltip (ILxUnknownID vts, int part)
        { return 0; }
};
#define LXxD_ToolModel_Flags unsigned tmod_Flags (void)
#define LXxO_ToolModel_Flags LXxD_ToolModel_Flags LXx_OVERRIDE
#define LXxC_ToolModel_Flags(c) unsigned c::tmod_Flags (void)
#define LXxD_ToolModel_Draw void tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxO_ToolModel_Draw LXxD_ToolModel_Draw LXx_OVERRIDE
#define LXxC_ToolModel_Draw(c) void c::tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxD_ToolModel_Test void tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxO_ToolModel_Test LXxD_ToolModel_Test LXx_OVERRIDE
#define LXxC_ToolModel_Test(c) void c::tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
#define LXxD_ToolModel_Filter void tmod_Filter (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel_Filter LXxD_ToolModel_Filter LXx_OVERRIDE
#define LXxC_ToolModel_Filter(c) void c::tmod_Filter (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel_Initialize void tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
#define LXxO_ToolModel_Initialize LXxD_ToolModel_Initialize LXx_OVERRIDE
#define LXxC_ToolModel_Initialize(c) void c::tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
#define LXxD_ToolModel_Down LxResult tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel_Down LXxD_ToolModel_Down LXx_OVERRIDE
#define LXxC_ToolModel_Down(c) LxResult c::tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel_Move void tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel_Move LXxD_ToolModel_Move LXx_OVERRIDE
#define LXxC_ToolModel_Move(c) void c::tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel_Up void tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxO_ToolModel_Up LXxD_ToolModel_Up LXx_OVERRIDE
#define LXxC_ToolModel_Up(c) void c::tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
#define LXxD_ToolModel_Haul const char * tmod_Haul (unsigned int index)
#define LXxO_ToolModel_Haul LXxD_ToolModel_Haul LXx_OVERRIDE
#define LXxC_ToolModel_Haul(c) const char * c::tmod_Haul (unsigned int index)
#define LXxD_ToolModel_AllowOverride LxResult tmod_AllowOverride (const char *attrName, unsigned int mouseInput, unsigned int haulAxis)
#define LXxO_ToolModel_AllowOverride LXxD_ToolModel_AllowOverride LXx_OVERRIDE
#define LXxC_ToolModel_AllowOverride(c) LxResult c::tmod_AllowOverride (const char *attrName, unsigned int mouseInput, unsigned int haulAxis)
#define LXxD_ToolModel_Help const char * tmod_Help (ILxUnknownID vts)
#define LXxO_ToolModel_Help LXxD_ToolModel_Help LXx_OVERRIDE
#define LXxC_ToolModel_Help(c) const char * c::tmod_Help (ILxUnknownID vts)
#define LXxD_ToolModel_Enable LxResult tmod_Enable (ILxUnknownID msg)
#define LXxO_ToolModel_Enable LXxD_ToolModel_Enable LXx_OVERRIDE
#define LXxC_ToolModel_Enable(c) LxResult c::tmod_Enable (ILxUnknownID msg)
#define LXxD_ToolModel_Drop LxResult tmod_Drop (void)
#define LXxO_ToolModel_Drop LXxD_ToolModel_Drop LXx_OVERRIDE
#define LXxC_ToolModel_Drop(c) LxResult c::tmod_Drop (void)
#define LXxD_ToolModel_Track LxResult tmod_Track (ILxUnknownID vts, unsigned int eventType)
#define LXxO_ToolModel_Track LXxD_ToolModel_Track LXx_OVERRIDE
#define LXxC_ToolModel_Track(c) LxResult c::tmod_Track (ILxUnknownID vts, unsigned int eventType)
#define LXxD_ToolModel_TrackFlags LxResult tmod_TrackFlags (unsigned int *flags)
#define LXxO_ToolModel_TrackFlags LXxD_ToolModel_TrackFlags LXx_OVERRIDE
#define LXxC_ToolModel_TrackFlags(c) LxResult c::tmod_TrackFlags (unsigned int *flags)
#define LXxD_ToolModel_Post LxResult tmod_Post (ILxUnknownID vts)
#define LXxO_ToolModel_Post LXxD_ToolModel_Post LXx_OVERRIDE
#define LXxC_ToolModel_Post(c) LxResult c::tmod_Post (ILxUnknownID vts)
#define LXxD_ToolModel_TestType LxResult tmod_TestType (LXtID4 type)
#define LXxO_ToolModel_TestType LXxD_ToolModel_TestType LXx_OVERRIDE
#define LXxC_ToolModel_TestType(c) LxResult c::tmod_TestType (LXtID4 type)
#define LXxD_ToolModel_Tooltip const char * tmod_Tooltip (ILxUnknownID vts, int part)
#define LXxO_ToolModel_Tooltip LXxD_ToolModel_Tooltip LXx_OVERRIDE
#define LXxC_ToolModel_Tooltip(c) const char * c::tmod_Tooltip (ILxUnknownID vts, int part)
template <class T>
class CLxIfc_ToolModel : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    return loc->tmod_Flags ();
  }
    static void
  Draw (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Draw ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Test (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Test ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Filter (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Filter ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static void
  Initialize (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust, unsigned int flags)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Initialize ((ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    static LxResult
  Down (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_Down ((ILxUnknownID)vts,(ILxUnknownID)adjust);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Move (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Move ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static void
  Up (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Up ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static const char *
  Haul (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    return loc->tmod_Haul (index);
  }
    static LxResult
  AllowOverride (LXtObjectID wcom, const char *attrName, unsigned int mouseInput, unsigned int haulAxis)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_AllowOverride (attrName,mouseInput,haulAxis);
    } catch (LxResult rc) { return rc; }
  }
    static const char *
  Help (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    return loc->tmod_Help ((ILxUnknownID)vts);
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Drop (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_Drop ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Track (LXtObjectID wcom, LXtObjectID vts, unsigned int eventType)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_Track ((ILxUnknownID)vts,eventType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TrackFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_TrackFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Post (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_Post ((ILxUnknownID)vts);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestType (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_TestType (type);
    } catch (LxResult rc) { return rc; }
  }
    static const char *
  Tooltip (LXtObjectID wcom, LXtObjectID vts, int part)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    return loc->tmod_Tooltip ((ILxUnknownID)vts,part);
  }
  ILxToolModel vt;
public:
  CLxIfc_ToolModel ()
  {
    vt.Flags = Flags;
    vt.Draw = Draw;
    vt.Test = Test;
    vt.Filter = Filter;
    vt.Initialize = Initialize;
    vt.Down = Down;
    vt.Move = Move;
    vt.Up = Up;
    vt.Haul = Haul;
    vt.AllowOverride = AllowOverride;
    vt.Help = Help;
    vt.Enable = Enable;
    vt.Drop = Drop;
    vt.Track = Track;
    vt.TrackFlags = TrackFlags;
    vt.Post = Post;
    vt.TestType = TestType;
    vt.Tooltip = Tooltip;
    vTable = &vt.iunk;
    iid = &lx::guid_ToolModel;
  }
};
class CLxLoc_ToolModel : public CLxLocalize<ILxToolModelID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ToolModel() {_init();}
  CLxLoc_ToolModel(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ToolModel(const CLxLoc_ToolModel &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ToolModel;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    void
  Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Draw (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Test (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Filter (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Filter (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
  {
    m_loc[0]->Initialize (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    LxResult
  Down (ILxUnknownID vts, ILxUnknownID adjust)
  {
    return m_loc[0]->Down (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Move (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Move (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Up (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Up (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    const char *
  Haul (unsigned int index)
  {
    return m_loc[0]->Haul (m_loc,index);
  }
    LxResult
  AllowOverride (const char *attrName, unsigned int mouseInput, unsigned int haulAxis)
  {
    return m_loc[0]->AllowOverride (m_loc,attrName,mouseInput,haulAxis);
  }
    const char *
  Help (ILxUnknownID vts)
  {
    return m_loc[0]->Help (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  Drop (void)
  {
    return m_loc[0]->Drop (m_loc);
  }
    LxResult
  Track (ILxUnknownID vts, unsigned int eventType)
  {
    return m_loc[0]->Track (m_loc,(ILxUnknownID)vts,eventType);
  }
    LxResult
  TrackFlags (unsigned int *flags)
  {
    return m_loc[0]->TrackFlags (m_loc,flags);
  }
    LxResult
  Post (ILxUnknownID vts)
  {
    return m_loc[0]->Post (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  TestType (LXtID4 type)
  {
    return m_loc[0]->TestType (m_loc,type);
  }
    const char *
  Tooltip (ILxUnknownID vts, int part)
  {
    return m_loc[0]->Tooltip (m_loc,(ILxUnknownID)vts,part);
  }
};

class CLxImpl_VirtualModel {
  public:
    virtual ~CLxImpl_VirtualModel() {}
    virtual unsigned
      vmodel_Flags (void)
        { return LXfTMOD_DRAW_3D; }
    virtual void
      vmodel_Draw (ILxUnknownID stroke)
        { }
    virtual void
      vmodel_Test (ILxUnknownID stroke)
        { }
    virtual void
      vmodel_Track (int part)
        { }
    virtual void
      vmodel_Down (ILxUnknownID vts)
        { }
    virtual void
      vmodel_Move (ILxUnknownID vts)
        { }
    virtual void
      vmodel_Up (ILxUnknownID vts)
        { }
    virtual const char *
      vmodel_Tooltip (int part)
        { return NULL; }
};
#define LXxD_VirtualModel_Flags unsigned vmodel_Flags (void)
#define LXxO_VirtualModel_Flags LXxD_VirtualModel_Flags LXx_OVERRIDE
#define LXxC_VirtualModel_Flags(c) unsigned c::vmodel_Flags (void)
#define LXxD_VirtualModel_Draw void vmodel_Draw (ILxUnknownID stroke)
#define LXxO_VirtualModel_Draw LXxD_VirtualModel_Draw LXx_OVERRIDE
#define LXxC_VirtualModel_Draw(c) void c::vmodel_Draw (ILxUnknownID stroke)
#define LXxD_VirtualModel_Test void vmodel_Test (ILxUnknownID stroke)
#define LXxO_VirtualModel_Test LXxD_VirtualModel_Test LXx_OVERRIDE
#define LXxC_VirtualModel_Test(c) void c::vmodel_Test (ILxUnknownID stroke)
#define LXxD_VirtualModel_Track void vmodel_Track (int part)
#define LXxO_VirtualModel_Track LXxD_VirtualModel_Track LXx_OVERRIDE
#define LXxC_VirtualModel_Track(c) void c::vmodel_Track (int part)
#define LXxD_VirtualModel_Down void vmodel_Down (ILxUnknownID vts)
#define LXxO_VirtualModel_Down LXxD_VirtualModel_Down LXx_OVERRIDE
#define LXxC_VirtualModel_Down(c) void c::vmodel_Down (ILxUnknownID vts)
#define LXxD_VirtualModel_Move void vmodel_Move (ILxUnknownID vts)
#define LXxO_VirtualModel_Move LXxD_VirtualModel_Move LXx_OVERRIDE
#define LXxC_VirtualModel_Move(c) void c::vmodel_Move (ILxUnknownID vts)
#define LXxD_VirtualModel_Up void vmodel_Up (ILxUnknownID vts)
#define LXxO_VirtualModel_Up LXxD_VirtualModel_Up LXx_OVERRIDE
#define LXxC_VirtualModel_Up(c) void c::vmodel_Up (ILxUnknownID vts)
#define LXxD_VirtualModel_Tooltip const char * vmodel_Tooltip (int part)
#define LXxO_VirtualModel_Tooltip LXxD_VirtualModel_Tooltip LXx_OVERRIDE
#define LXxC_VirtualModel_Tooltip(c) const char * c::vmodel_Tooltip (int part)
template <class T>
class CLxIfc_VirtualModel : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VirtualModel, loc);
    return loc->vmodel_Flags ();
  }
    static void
  Draw (LXtObjectID wcom, LXtObjectID stroke)
  {
    LXCWxINST (CLxImpl_VirtualModel, loc);
    loc->vmodel_Draw ((ILxUnknownID)stroke);
  }
    static void
  Test (LXtObjectID wcom, LXtObjectID stroke)
  {
    LXCWxINST (CLxImpl_VirtualModel, loc);
    loc->vmodel_Test ((ILxUnknownID)stroke);
  }
    static void
  Track (LXtObjectID wcom, int part)
  {
    LXCWxINST (CLxImpl_VirtualModel, loc);
    loc->vmodel_Track (part);
  }
    static void
  Down (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_VirtualModel, loc);
    loc->vmodel_Down ((ILxUnknownID)vts);
  }
    static void
  Move (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_VirtualModel, loc);
    loc->vmodel_Move ((ILxUnknownID)vts);
  }
    static void
  Up (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_VirtualModel, loc);
    loc->vmodel_Up ((ILxUnknownID)vts);
  }
    static const char *
  Tooltip (LXtObjectID wcom, int part)
  {
    LXCWxINST (CLxImpl_VirtualModel, loc);
    return loc->vmodel_Tooltip (part);
  }
  ILxVirtualModel vt;
public:
  CLxIfc_VirtualModel ()
  {
    vt.Flags = Flags;
    vt.Draw = Draw;
    vt.Test = Test;
    vt.Track = Track;
    vt.Down = Down;
    vt.Move = Move;
    vt.Up = Up;
    vt.Tooltip = Tooltip;
    vTable = &vt.iunk;
    iid = &lx::guid_VirtualModel;
  }
};
class CLxLoc_VirtualModel : public CLxLocalize<ILxVirtualModelID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VirtualModel() {_init();}
  CLxLoc_VirtualModel(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VirtualModel(const CLxLoc_VirtualModel &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VirtualModel;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    void
  Draw (ILxUnknownID stroke)
  {
    m_loc[0]->Draw (m_loc,(ILxUnknownID)stroke);
  }
    void
  Test (ILxUnknownID stroke)
  {
    m_loc[0]->Test (m_loc,(ILxUnknownID)stroke);
  }
    void
  Track (int part)
  {
    m_loc[0]->Track (m_loc,part);
  }
    void
  Down (ILxUnknownID vts)
  {
    m_loc[0]->Down (m_loc,(ILxUnknownID)vts);
  }
    void
  Move (ILxUnknownID vts)
  {
    m_loc[0]->Move (m_loc,(ILxUnknownID)vts);
  }
    void
  Up (ILxUnknownID vts)
  {
    m_loc[0]->Up (m_loc,(ILxUnknownID)vts);
  }
    const char *
  Tooltip (int part)
  {
    return m_loc[0]->Tooltip (m_loc,part);
  }
};

#endif

