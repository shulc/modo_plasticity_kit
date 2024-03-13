/*
 * C++ wrapper for lxpackage.h
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
#ifndef LXW_PACKAGE_HPP
#define LXW_PACKAGE_HPP

#include <lxpackage.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_AddChannel1 = {0x6E732ACC,0xAAA5,0x4695,0xB5,0xDE,0x80,0x59,0xA2,0x80,0x05,0x54};
    static const LXtGUID guid_SceneEvalListener = {0x7793643D,0xFA56,0x4198,0x96,0x3B,0xAE,0x8F,0xAC,0x69,0xF4,0x8D};
    static const LXtGUID guid_SceneItemListener = {0xAFB67180,0xEC4F,0x4E9B,0xAA,0xF1,0x67,0xAA,0x47,0x09,0x7C,0x29};
    static const LXtGUID guid_AssemblyAlias = {0x1794FFAE,0x1E80,0x4211,0xB1,0xE8,0xCE,0x09,0xB4,0x70,0xB2,0x0C};
    static const LXtGUID guid_SceneEvalListener1 = {0x816116A8,0xB180,0x49E1,0x99,0x84,0x0D,0xE3,0x53,0x1B,0xDE,0x55};
    static const LXtGUID guid_AddChannel = {0x47C1E8A9,0x6C76,0x4068,0xBD,0x4F,0x36,0x00,0x15,0x68,0x3C,0xD0};
    static const LXtGUID guid_ItemCollection = {0x8D37934E,0xF517,0x45F1,0x90,0xF0,0x8C,0x17,0xF5,0x95,0xDC,0x7D};
    static const LXtGUID guid_Package1 = {0x6383211E,0x2624,0x492e,0x8C,0x4B,0xD0,0x6B,0xB4,0x38,0x86,0xA7};
    static const LXtGUID guid_PackageInstance1 = {0x09D603F7,0xCCF6,0x4A5C,0xB4,0x1C,0x02,0x1A,0xC6,0xC1,0x7A,0x94};
    static const LXtGUID guid_SceneItemListener1 = {0xBCCD05F8,0xE560,0x11D7,0xB3,0xB8,0x00,0x03,0x93,0xCE,0x96,0x80};
    static const LXtGUID guid_SceneItemListener2 = {0xC72C641E,0xCDCD,0x431B,0xAD,0xD9,0xD7,0x55,0x54,0xD6,0x56,0xE1};
    static const LXtGUID guid_PackageInstance = {0x68DD1902,0xE5AB,0x4591,0xBF,0x93,0xB8,0x3C,0x85,0x6D,0x19,0x08};
    static const LXtGUID guid_Item1 = {0x5B14C8B6,0x29EF,0x473A,0xB1,0xB3,0x56,0x8D,0xFD,0x9A,0xE8,0xD7};
    static const LXtGUID guid_Scene1 = {0x4340A8FC,0xF984,0x4E04,0xA4,0xBB,0x83,0x93,0x1A,0x63,0x35,0xAF};
    static const LXtGUID guid_SceneLoaderTarget = {0xA914B4F9,0x947C,0x4334,0x9D,0x89,0x64,0xBB,0x8D,0xC2,0x6B,0xF6};
    static const LXtGUID guid_Package = {0x01DA3920,0x484A,0x415F,0xAF,0xF7,0x5A,0x27,0x4B,0x77,0xAC,0x3A};
};

class CLxLoc_AddChannel1 : public CLxLocalize<ILxAddChannel1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AddChannel1() {_init();}
  CLxLoc_AddChannel1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AddChannel1(const CLxLoc_AddChannel1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AddChannel1;}
    LxResult
  NewChannel (const char *name, const char *type)
  {
    return m_loc[0]->NewChannel (m_loc,name,type);
  }
    LxResult
  SetGradient (const char *inType)
  {
    return m_loc[0]->SetGradient (m_loc,inType);
  }
    LxResult
  SetStorage (const char *stType)
  {
    return m_loc[0]->SetStorage (m_loc,stType);
  }
    LxResult
  SetVector (const char *vecType)
  {
    return m_loc[0]->SetVector (m_loc,vecType);
  }
    LxResult
  SetDefault (double defFlt, int defInt)
  {
    return m_loc[0]->SetDefault (m_loc,defFlt,defInt);
  }
    LxResult
  SetDefaultVec (const double *defVec)
  {
    return m_loc[0]->SetDefaultVec (m_loc,defVec);
  }
    LxResult
  SetHint (const LXtTextValueHint *hint)
  {
    return m_loc[0]->SetHint (m_loc,hint);
  }
    LxResult
  SetDefaultObj (void **ppvObj)
  {
    return m_loc[0]->SetDefaultObj (m_loc,ppvObj);
  }
    CLxResult
  SetDefaultObj (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SetDefaultObj(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void
  SetInternal (void)
  {
    m_loc[0]->SetInternal (m_loc);
  }
};

class CLxImpl_SceneEvalListener {
  public:
    virtual ~CLxImpl_SceneEvalListener() {}
    virtual void
      sel_ChannelValue (ILxUnknownID item, unsigned index)
        { }
    virtual void
      sel_ChannelPreValue (void)
        { }
    virtual void
      sel_ChannelPostValue (void)
        { }
};
#define LXxD_SceneEvalListener_ChannelValue void sel_ChannelValue (ILxUnknownID item, unsigned index)
#define LXxO_SceneEvalListener_ChannelValue LXxD_SceneEvalListener_ChannelValue LXx_OVERRIDE
#define LXxC_SceneEvalListener_ChannelValue(c) void c::sel_ChannelValue (ILxUnknownID item, unsigned index)
#define LXxD_SceneEvalListener_ChannelPreValue void sel_ChannelPreValue (void)
#define LXxO_SceneEvalListener_ChannelPreValue LXxD_SceneEvalListener_ChannelPreValue LXx_OVERRIDE
#define LXxC_SceneEvalListener_ChannelPreValue(c) void c::sel_ChannelPreValue (void)
#define LXxD_SceneEvalListener_ChannelPostValue void sel_ChannelPostValue (void)
#define LXxO_SceneEvalListener_ChannelPostValue LXxD_SceneEvalListener_ChannelPostValue LXx_OVERRIDE
#define LXxC_SceneEvalListener_ChannelPostValue(c) void c::sel_ChannelPostValue (void)
template <class T>
class CLxIfc_SceneEvalListener : public CLxInterface
{
    static void
  ChannelValue (LXtObjectID wcom, LXtObjectID item, unsigned index)
  {
    LXCWxINST (CLxImpl_SceneEvalListener, loc);
    loc->sel_ChannelValue ((ILxUnknownID)item,index);
  }
    static void
  ChannelPreValue (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SceneEvalListener, loc);
    loc->sel_ChannelPreValue ();
  }
    static void
  ChannelPostValue (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SceneEvalListener, loc);
    loc->sel_ChannelPostValue ();
  }
  ILxSceneEvalListener vt;
public:
  CLxIfc_SceneEvalListener ()
  {
    vt.ChannelValue = ChannelValue;
    vt.ChannelPreValue = ChannelPreValue;
    vt.ChannelPostValue = ChannelPostValue;
    vTable = &vt.iunk;
    iid = &lx::guid_SceneEvalListener;
  }
};
class CLxLoc_SceneEvalListener : public CLxLocalize<ILxSceneEvalListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneEvalListener() {_init();}
  CLxLoc_SceneEvalListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SceneEvalListener(const CLxLoc_SceneEvalListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SceneEvalListener;}
    void
  ChannelValue (ILxUnknownID item, unsigned index)
  {
    m_loc[0]->ChannelValue (m_loc,(ILxUnknownID)item,index);
  }
    void
  ChannelPreValue (void)
  {
    m_loc[0]->ChannelPreValue (m_loc);
  }
    void
  ChannelPostValue (void)
  {
    m_loc[0]->ChannelPostValue (m_loc);
  }
};

class CLxImpl_SceneItemListener {
  public:
    virtual ~CLxImpl_SceneItemListener() {}
    virtual void
      sil_SceneCreate (ILxUnknownID scene)
        { }
    virtual void
      sil_SceneDestroy (ILxUnknownID scene)
        { }
    virtual void
      sil_SceneFilename (ILxUnknownID scene, const char *filename)
        { }
    virtual void
      sil_SceneClear (ILxUnknownID scene)
        { }
    virtual void
      sil_ItemPreChange (ILxUnknownID scene)
        { }
    virtual void
      sil_ItemPostDelete (ILxUnknownID scene)
        { }
    virtual void
      sil_ItemAdd (ILxUnknownID item)
        { }
    virtual void
      sil_ItemRemove (ILxUnknownID item)
        { }
    virtual void
      sil_ItemParent (ILxUnknownID item)
        { }
    virtual void
      sil_ItemChild (ILxUnknownID item)
        { }
    virtual void
      sil_ItemAddChannel (ILxUnknownID item)
        { }
    virtual void
      sil_ItemLocal (ILxUnknownID item)
        { }
    virtual void
      sil_ItemName (ILxUnknownID item)
        { }
    virtual void
      sil_ItemSource (ILxUnknownID item)
        { }
    virtual void
      sil_ItemPackage (ILxUnknownID item)
        { }
    virtual void
      sil_ChannelValue (const char *action, ILxUnknownID item, unsigned index)
        { }
    virtual void
      sil_LinkAdd (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
        { }
    virtual void
      sil_LinkRemBefore (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
        { }
    virtual void
      sil_LinkRemAfter (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
        { }
    virtual void
      sil_LinkSet (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
        { }
    virtual void
      sil_ChanLinkAdd (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
        { }
    virtual void
      sil_ChanLinkRemBefore (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
        { }
    virtual void
      sil_ChanLinkRemAfter (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
        { }
    virtual void
      sil_ChanLinkSet (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
        { }
    virtual void
      sil_ItemTag (ILxUnknownID item)
        { }
    virtual void
      sil_ItemRemoveChannel (ILxUnknownID item)
        { }
    virtual void
      sil_ItemChannelName (ILxUnknownID item, unsigned int index)
        { }
    virtual void
      sil_ItemChannelDefault (ILxUnknownID item, unsigned int index)
        { }
    virtual void
      sil_ItemChannelMinMax (ILxUnknownID item, unsigned int index)
        { }
    virtual void
      sil_ItemChannelType (ILxUnknownID item, unsigned int index)
        { }
};
#define LXxD_SceneItemListener_SceneCreate void sil_SceneCreate (ILxUnknownID scene)
#define LXxO_SceneItemListener_SceneCreate LXxD_SceneItemListener_SceneCreate LXx_OVERRIDE
#define LXxC_SceneItemListener_SceneCreate(c) void c::sil_SceneCreate (ILxUnknownID scene)
#define LXxD_SceneItemListener_SceneDestroy void sil_SceneDestroy (ILxUnknownID scene)
#define LXxO_SceneItemListener_SceneDestroy LXxD_SceneItemListener_SceneDestroy LXx_OVERRIDE
#define LXxC_SceneItemListener_SceneDestroy(c) void c::sil_SceneDestroy (ILxUnknownID scene)
#define LXxD_SceneItemListener_SceneFilename void sil_SceneFilename (ILxUnknownID scene, const char *filename)
#define LXxO_SceneItemListener_SceneFilename LXxD_SceneItemListener_SceneFilename LXx_OVERRIDE
#define LXxC_SceneItemListener_SceneFilename(c) void c::sil_SceneFilename (ILxUnknownID scene, const char *filename)
#define LXxD_SceneItemListener_SceneClear void sil_SceneClear (ILxUnknownID scene)
#define LXxO_SceneItemListener_SceneClear LXxD_SceneItemListener_SceneClear LXx_OVERRIDE
#define LXxC_SceneItemListener_SceneClear(c) void c::sil_SceneClear (ILxUnknownID scene)
#define LXxD_SceneItemListener_ItemPreChange void sil_ItemPreChange (ILxUnknownID scene)
#define LXxO_SceneItemListener_ItemPreChange LXxD_SceneItemListener_ItemPreChange LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemPreChange(c) void c::sil_ItemPreChange (ILxUnknownID scene)
#define LXxD_SceneItemListener_ItemPostDelete void sil_ItemPostDelete (ILxUnknownID scene)
#define LXxO_SceneItemListener_ItemPostDelete LXxD_SceneItemListener_ItemPostDelete LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemPostDelete(c) void c::sil_ItemPostDelete (ILxUnknownID scene)
#define LXxD_SceneItemListener_ItemAdd void sil_ItemAdd (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemAdd LXxD_SceneItemListener_ItemAdd LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemAdd(c) void c::sil_ItemAdd (ILxUnknownID item)
#define LXxD_SceneItemListener_ItemRemove void sil_ItemRemove (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemRemove LXxD_SceneItemListener_ItemRemove LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemRemove(c) void c::sil_ItemRemove (ILxUnknownID item)
#define LXxD_SceneItemListener_ItemParent void sil_ItemParent (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemParent LXxD_SceneItemListener_ItemParent LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemParent(c) void c::sil_ItemParent (ILxUnknownID item)
#define LXxD_SceneItemListener_ItemChild void sil_ItemChild (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemChild LXxD_SceneItemListener_ItemChild LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemChild(c) void c::sil_ItemChild (ILxUnknownID item)
#define LXxD_SceneItemListener_ItemAddChannel void sil_ItemAddChannel (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemAddChannel LXxD_SceneItemListener_ItemAddChannel LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemAddChannel(c) void c::sil_ItemAddChannel (ILxUnknownID item)
#define LXxD_SceneItemListener_ItemLocal void sil_ItemLocal (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemLocal LXxD_SceneItemListener_ItemLocal LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemLocal(c) void c::sil_ItemLocal (ILxUnknownID item)
#define LXxD_SceneItemListener_ItemName void sil_ItemName (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemName LXxD_SceneItemListener_ItemName LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemName(c) void c::sil_ItemName (ILxUnknownID item)
#define LXxD_SceneItemListener_ItemSource void sil_ItemSource (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemSource LXxD_SceneItemListener_ItemSource LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemSource(c) void c::sil_ItemSource (ILxUnknownID item)
#define LXxD_SceneItemListener_ItemPackage void sil_ItemPackage (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemPackage LXxD_SceneItemListener_ItemPackage LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemPackage(c) void c::sil_ItemPackage (ILxUnknownID item)
#define LXxD_SceneItemListener_ChannelValue void sil_ChannelValue (const char *action, ILxUnknownID item, unsigned index)
#define LXxO_SceneItemListener_ChannelValue LXxD_SceneItemListener_ChannelValue LXx_OVERRIDE
#define LXxC_SceneItemListener_ChannelValue(c) void c::sil_ChannelValue (const char *action, ILxUnknownID item, unsigned index)
#define LXxD_SceneItemListener_LinkAdd void sil_LinkAdd (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxO_SceneItemListener_LinkAdd LXxD_SceneItemListener_LinkAdd LXx_OVERRIDE
#define LXxC_SceneItemListener_LinkAdd(c) void c::sil_LinkAdd (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxD_SceneItemListener_LinkRemBefore void sil_LinkRemBefore (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxO_SceneItemListener_LinkRemBefore LXxD_SceneItemListener_LinkRemBefore LXx_OVERRIDE
#define LXxC_SceneItemListener_LinkRemBefore(c) void c::sil_LinkRemBefore (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxD_SceneItemListener_LinkRemAfter void sil_LinkRemAfter (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxO_SceneItemListener_LinkRemAfter LXxD_SceneItemListener_LinkRemAfter LXx_OVERRIDE
#define LXxC_SceneItemListener_LinkRemAfter(c) void c::sil_LinkRemAfter (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxD_SceneItemListener_LinkSet void sil_LinkSet (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxO_SceneItemListener_LinkSet LXxD_SceneItemListener_LinkSet LXx_OVERRIDE
#define LXxC_SceneItemListener_LinkSet(c) void c::sil_LinkSet (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxD_SceneItemListener_ChanLinkAdd void sil_ChanLinkAdd (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxO_SceneItemListener_ChanLinkAdd LXxD_SceneItemListener_ChanLinkAdd LXx_OVERRIDE
#define LXxC_SceneItemListener_ChanLinkAdd(c) void c::sil_ChanLinkAdd (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxD_SceneItemListener_ChanLinkRemBefore void sil_ChanLinkRemBefore (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxO_SceneItemListener_ChanLinkRemBefore LXxD_SceneItemListener_ChanLinkRemBefore LXx_OVERRIDE
#define LXxC_SceneItemListener_ChanLinkRemBefore(c) void c::sil_ChanLinkRemBefore (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxD_SceneItemListener_ChanLinkRemAfter void sil_ChanLinkRemAfter (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxO_SceneItemListener_ChanLinkRemAfter LXxD_SceneItemListener_ChanLinkRemAfter LXx_OVERRIDE
#define LXxC_SceneItemListener_ChanLinkRemAfter(c) void c::sil_ChanLinkRemAfter (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxD_SceneItemListener_ChanLinkSet void sil_ChanLinkSet (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxO_SceneItemListener_ChanLinkSet LXxD_SceneItemListener_ChanLinkSet LXx_OVERRIDE
#define LXxC_SceneItemListener_ChanLinkSet(c) void c::sil_ChanLinkSet (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxD_SceneItemListener_ItemTag void sil_ItemTag (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemTag LXxD_SceneItemListener_ItemTag LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemTag(c) void c::sil_ItemTag (ILxUnknownID item)
#define LXxD_SceneItemListener_ItemRemoveChannel void sil_ItemRemoveChannel (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemRemoveChannel LXxD_SceneItemListener_ItemRemoveChannel LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemRemoveChannel(c) void c::sil_ItemRemoveChannel (ILxUnknownID item)
#define LXxD_SceneItemListener_ItemChannelName void sil_ItemChannelName (ILxUnknownID item, unsigned int index)
#define LXxO_SceneItemListener_ItemChannelName LXxD_SceneItemListener_ItemChannelName LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemChannelName(c) void c::sil_ItemChannelName (ILxUnknownID item, unsigned int index)
#define LXxD_SceneItemListener_ItemChannelDefault void sil_ItemChannelDefault (ILxUnknownID item, unsigned int index)
#define LXxO_SceneItemListener_ItemChannelDefault LXxD_SceneItemListener_ItemChannelDefault LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemChannelDefault(c) void c::sil_ItemChannelDefault (ILxUnknownID item, unsigned int index)
#define LXxD_SceneItemListener_ItemChannelMinMax void sil_ItemChannelMinMax (ILxUnknownID item, unsigned int index)
#define LXxO_SceneItemListener_ItemChannelMinMax LXxD_SceneItemListener_ItemChannelMinMax LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemChannelMinMax(c) void c::sil_ItemChannelMinMax (ILxUnknownID item, unsigned int index)
#define LXxD_SceneItemListener_ItemChannelType void sil_ItemChannelType (ILxUnknownID item, unsigned int index)
#define LXxO_SceneItemListener_ItemChannelType LXxD_SceneItemListener_ItemChannelType LXx_OVERRIDE
#define LXxC_SceneItemListener_ItemChannelType(c) void c::sil_ItemChannelType (ILxUnknownID item, unsigned int index)
template <class T>
class CLxIfc_SceneItemListener : public CLxInterface
{
    static void
  SceneCreate (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_SceneCreate ((ILxUnknownID)scene);
  }
    static void
  SceneDestroy (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_SceneDestroy ((ILxUnknownID)scene);
  }
    static void
  SceneFilename (LXtObjectID wcom, LXtObjectID scene, const char *filename)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_SceneFilename ((ILxUnknownID)scene,filename);
  }
    static void
  SceneClear (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_SceneClear ((ILxUnknownID)scene);
  }
    static void
  ItemPreChange (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemPreChange ((ILxUnknownID)scene);
  }
    static void
  ItemPostDelete (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemPostDelete ((ILxUnknownID)scene);
  }
    static void
  ItemAdd (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemAdd ((ILxUnknownID)item);
  }
    static void
  ItemRemove (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemRemove ((ILxUnknownID)item);
  }
    static void
  ItemParent (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemParent ((ILxUnknownID)item);
  }
    static void
  ItemChild (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemChild ((ILxUnknownID)item);
  }
    static void
  ItemAddChannel (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemAddChannel ((ILxUnknownID)item);
  }
    static void
  ItemLocal (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemLocal ((ILxUnknownID)item);
  }
    static void
  ItemName (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemName ((ILxUnknownID)item);
  }
    static void
  ItemSource (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemSource ((ILxUnknownID)item);
  }
    static void
  ItemPackage (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemPackage ((ILxUnknownID)item);
  }
    static void
  ChannelValue (LXtObjectID wcom, const char *action, LXtObjectID item, unsigned index)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ChannelValue (action,(ILxUnknownID)item,index);
  }
    static void
  LinkAdd (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, LXtObjectID itemTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_LinkAdd (graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    static void
  LinkRemBefore (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, LXtObjectID itemTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_LinkRemBefore (graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    static void
  LinkRemAfter (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, LXtObjectID itemTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_LinkRemAfter (graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    static void
  LinkSet (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, LXtObjectID itemTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_LinkSet (graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    static void
  ChanLinkAdd (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, unsigned chanFrom, LXtObjectID itemTo, unsigned chanTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ChanLinkAdd (graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    static void
  ChanLinkRemBefore (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, unsigned chanFrom, LXtObjectID itemTo, unsigned chanTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ChanLinkRemBefore (graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    static void
  ChanLinkRemAfter (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, unsigned chanFrom, LXtObjectID itemTo, unsigned chanTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ChanLinkRemAfter (graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    static void
  ChanLinkSet (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, unsigned chanFrom, LXtObjectID itemTo, unsigned chanTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ChanLinkSet (graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    static void
  ItemTag (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemTag ((ILxUnknownID)item);
  }
    static void
  ItemRemoveChannel (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemRemoveChannel ((ILxUnknownID)item);
  }
    static void
  ItemChannelName (LXtObjectID wcom, LXtObjectID item, unsigned int index)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemChannelName ((ILxUnknownID)item,index);
  }
    static void
  ItemChannelDefault (LXtObjectID wcom, LXtObjectID item, unsigned int index)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemChannelDefault ((ILxUnknownID)item,index);
  }
    static void
  ItemChannelMinMax (LXtObjectID wcom, LXtObjectID item, unsigned int index)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemChannelMinMax ((ILxUnknownID)item,index);
  }
    static void
  ItemChannelType (LXtObjectID wcom, LXtObjectID item, unsigned int index)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemChannelType ((ILxUnknownID)item,index);
  }
  ILxSceneItemListener vt;
public:
  CLxIfc_SceneItemListener ()
  {
    vt.SceneCreate = SceneCreate;
    vt.SceneDestroy = SceneDestroy;
    vt.SceneFilename = SceneFilename;
    vt.SceneClear = SceneClear;
    vt.ItemPreChange = ItemPreChange;
    vt.ItemPostDelete = ItemPostDelete;
    vt.ItemAdd = ItemAdd;
    vt.ItemRemove = ItemRemove;
    vt.ItemParent = ItemParent;
    vt.ItemChild = ItemChild;
    vt.ItemAddChannel = ItemAddChannel;
    vt.ItemLocal = ItemLocal;
    vt.ItemName = ItemName;
    vt.ItemSource = ItemSource;
    vt.ItemPackage = ItemPackage;
    vt.ChannelValue = ChannelValue;
    vt.LinkAdd = LinkAdd;
    vt.LinkRemBefore = LinkRemBefore;
    vt.LinkRemAfter = LinkRemAfter;
    vt.LinkSet = LinkSet;
    vt.ChanLinkAdd = ChanLinkAdd;
    vt.ChanLinkRemBefore = ChanLinkRemBefore;
    vt.ChanLinkRemAfter = ChanLinkRemAfter;
    vt.ChanLinkSet = ChanLinkSet;
    vt.ItemTag = ItemTag;
    vt.ItemRemoveChannel = ItemRemoveChannel;
    vt.ItemChannelName = ItemChannelName;
    vt.ItemChannelDefault = ItemChannelDefault;
    vt.ItemChannelMinMax = ItemChannelMinMax;
    vt.ItemChannelType = ItemChannelType;
    vTable = &vt.iunk;
    iid = &lx::guid_SceneItemListener;
  }
};
class CLxLoc_SceneItemListener : public CLxLocalize<ILxSceneItemListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneItemListener() {_init();}
  CLxLoc_SceneItemListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SceneItemListener(const CLxLoc_SceneItemListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SceneItemListener;}
    void
  SceneCreate (ILxUnknownID scene)
  {
    m_loc[0]->SceneCreate (m_loc,(ILxUnknownID)scene);
  }
    void
  SceneDestroy (ILxUnknownID scene)
  {
    m_loc[0]->SceneDestroy (m_loc,(ILxUnknownID)scene);
  }
    void
  SceneFilename (ILxUnknownID scene, const char *filename)
  {
    m_loc[0]->SceneFilename (m_loc,(ILxUnknownID)scene,filename);
  }
    void
  SceneClear (ILxUnknownID scene)
  {
    m_loc[0]->SceneClear (m_loc,(ILxUnknownID)scene);
  }
    void
  ItemPreChange (ILxUnknownID scene)
  {
    m_loc[0]->ItemPreChange (m_loc,(ILxUnknownID)scene);
  }
    void
  ItemPostDelete (ILxUnknownID scene)
  {
    m_loc[0]->ItemPostDelete (m_loc,(ILxUnknownID)scene);
  }
    void
  ItemAdd (ILxUnknownID item)
  {
    m_loc[0]->ItemAdd (m_loc,(ILxUnknownID)item);
  }
    void
  ItemRemove (ILxUnknownID item)
  {
    m_loc[0]->ItemRemove (m_loc,(ILxUnknownID)item);
  }
    void
  ItemParent (ILxUnknownID item)
  {
    m_loc[0]->ItemParent (m_loc,(ILxUnknownID)item);
  }
    void
  ItemChild (ILxUnknownID item)
  {
    m_loc[0]->ItemChild (m_loc,(ILxUnknownID)item);
  }
    void
  ItemAddChannel (ILxUnknownID item)
  {
    m_loc[0]->ItemAddChannel (m_loc,(ILxUnknownID)item);
  }
    void
  ItemLocal (ILxUnknownID item)
  {
    m_loc[0]->ItemLocal (m_loc,(ILxUnknownID)item);
  }
    void
  ItemName (ILxUnknownID item)
  {
    m_loc[0]->ItemName (m_loc,(ILxUnknownID)item);
  }
    void
  ItemSource (ILxUnknownID item)
  {
    m_loc[0]->ItemSource (m_loc,(ILxUnknownID)item);
  }
    void
  ItemPackage (ILxUnknownID item)
  {
    m_loc[0]->ItemPackage (m_loc,(ILxUnknownID)item);
  }
    void
  ChannelValue (const char *action, ILxUnknownID item, unsigned index)
  {
    m_loc[0]->ChannelValue (m_loc,action,(ILxUnknownID)item,index);
  }
    void
  LinkAdd (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
  {
    m_loc[0]->LinkAdd (m_loc,graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    void
  LinkRemBefore (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
  {
    m_loc[0]->LinkRemBefore (m_loc,graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    void
  LinkRemAfter (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
  {
    m_loc[0]->LinkRemAfter (m_loc,graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    void
  LinkSet (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
  {
    m_loc[0]->LinkSet (m_loc,graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    void
  ChanLinkAdd (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
  {
    m_loc[0]->ChanLinkAdd (m_loc,graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    void
  ChanLinkRemBefore (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
  {
    m_loc[0]->ChanLinkRemBefore (m_loc,graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    void
  ChanLinkRemAfter (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
  {
    m_loc[0]->ChanLinkRemAfter (m_loc,graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    void
  ChanLinkSet (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
  {
    m_loc[0]->ChanLinkSet (m_loc,graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    void
  ItemTag (ILxUnknownID item)
  {
    m_loc[0]->ItemTag (m_loc,(ILxUnknownID)item);
  }
    void
  ItemRemoveChannel (ILxUnknownID item)
  {
    m_loc[0]->ItemRemoveChannel (m_loc,(ILxUnknownID)item);
  }
    void
  ItemChannelName (ILxUnknownID item, unsigned int index)
  {
    m_loc[0]->ItemChannelName (m_loc,(ILxUnknownID)item,index);
  }
    void
  ItemChannelDefault (ILxUnknownID item, unsigned int index)
  {
    m_loc[0]->ItemChannelDefault (m_loc,(ILxUnknownID)item,index);
  }
    void
  ItemChannelMinMax (ILxUnknownID item, unsigned int index)
  {
    m_loc[0]->ItemChannelMinMax (m_loc,(ILxUnknownID)item,index);
  }
    void
  ItemChannelType (ILxUnknownID item, unsigned int index)
  {
    m_loc[0]->ItemChannelType (m_loc,(ILxUnknownID)item,index);
  }
};

class CLxImpl_AssemblyAlias {
  public:
    virtual ~CLxImpl_AssemblyAlias() {}
    virtual LxResult
      alias_Test (ILxUnknownID assembly, ILxUnknownID other)
        { return LXe_NOTIMPL; }
    virtual LxResult
      alias_Configure (ILxUnknownID assembly, ILxUnknownID other, ILxUnknownID alias, const unsigned int change)
        { return LXe_NOTIMPL; }
    virtual LxResult
      alias_SuperType (LXtItemType *type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      alias_Flags (unsigned int *flags)
        { return LXe_NOTIMPL; }
};
#define LXxD_AssemblyAlias_Test LxResult alias_Test (ILxUnknownID assembly, ILxUnknownID other)
#define LXxO_AssemblyAlias_Test LXxD_AssemblyAlias_Test LXx_OVERRIDE
#define LXxC_AssemblyAlias_Test(c) LxResult c::alias_Test (ILxUnknownID assembly, ILxUnknownID other)
#define LXxD_AssemblyAlias_Configure LxResult alias_Configure (ILxUnknownID assembly, ILxUnknownID other, ILxUnknownID alias, const unsigned int change)
#define LXxO_AssemblyAlias_Configure LXxD_AssemblyAlias_Configure LXx_OVERRIDE
#define LXxC_AssemblyAlias_Configure(c) LxResult c::alias_Configure (ILxUnknownID assembly, ILxUnknownID other, ILxUnknownID alias, const unsigned int change)
#define LXxD_AssemblyAlias_SuperType LxResult alias_SuperType (LXtItemType *type)
#define LXxO_AssemblyAlias_SuperType LXxD_AssemblyAlias_SuperType LXx_OVERRIDE
#define LXxC_AssemblyAlias_SuperType(c) LxResult c::alias_SuperType (LXtItemType *type)
#define LXxD_AssemblyAlias_Flags LxResult alias_Flags (unsigned int *flags)
#define LXxO_AssemblyAlias_Flags LXxD_AssemblyAlias_Flags LXx_OVERRIDE
#define LXxC_AssemblyAlias_Flags(c) LxResult c::alias_Flags (unsigned int *flags)
template <class T>
class CLxIfc_AssemblyAlias : public CLxInterface
{
    static LxResult
  Test (LXtObjectID wcom, LXtObjectID assembly, LXtObjectID other)
  {
    LXCWxINST (CLxImpl_AssemblyAlias, loc);
    try {
      return loc->alias_Test ((ILxUnknownID)assembly,(ILxUnknownID)other);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Configure (LXtObjectID wcom, LXtObjectID assembly, LXtObjectID other, LXtObjectID alias, const unsigned int change)
  {
    LXCWxINST (CLxImpl_AssemblyAlias, loc);
    try {
      return loc->alias_Configure ((ILxUnknownID)assembly,(ILxUnknownID)other,(ILxUnknownID)alias,change);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SuperType (LXtObjectID wcom, LXtItemType *type)
  {
    LXCWxINST (CLxImpl_AssemblyAlias, loc);
    try {
      return loc->alias_SuperType (type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Flags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_AssemblyAlias, loc);
    try {
      return loc->alias_Flags (flags);
    } catch (LxResult rc) { return rc; }
  }
  ILxAssemblyAlias vt;
public:
  CLxIfc_AssemblyAlias ()
  {
    vt.Test = Test;
    vt.Configure = Configure;
    vt.SuperType = SuperType;
    vt.Flags = Flags;
    vTable = &vt.iunk;
    iid = &lx::guid_AssemblyAlias;
  }
};


class CLxLoc_AddChannel : public CLxLocalize<ILxAddChannelID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AddChannel() {_init();}
  CLxLoc_AddChannel(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AddChannel(const CLxLoc_AddChannel &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AddChannel;}
    LxResult
  NewChannel (const char *name, const char *type)
  {
    return m_loc[0]->NewChannel (m_loc,name,type);
  }
    LxResult
  SetGradient (const char *inType)
  {
    return m_loc[0]->SetGradient (m_loc,inType);
  }
    LxResult
  SetStorage (const char *stType)
  {
    return m_loc[0]->SetStorage (m_loc,stType);
  }
    LxResult
  SetVector (const char *vecType)
  {
    return m_loc[0]->SetVector (m_loc,vecType);
  }
    LxResult
  SetDefault (double defFlt, int defInt)
  {
    return m_loc[0]->SetDefault (m_loc,defFlt,defInt);
  }
    LxResult
  SetDefaultVec (const double *defVec)
  {
    return m_loc[0]->SetDefaultVec (m_loc,defVec);
  }
    LxResult
  SetHint (const LXtTextValueHint *hint)
  {
    return m_loc[0]->SetHint (m_loc,hint);
  }
    LxResult
  SetUserHint (const LXtTextValueHint *hint)
  {
    return m_loc[0]->SetUserHint (m_loc,hint);
  }
    LxResult
  SetDefaultObj (void **ppvObj)
  {
    return m_loc[0]->SetDefaultObj (m_loc,ppvObj);
  }
    CLxResult
  SetDefaultObj (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SetDefaultObj(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void
  SetInternal (void)
  {
    m_loc[0]->SetInternal (m_loc);
  }
};

class CLxLoc_ItemCollection : public CLxLocalize<ILxItemCollectionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemCollection() {_init();}
  CLxLoc_ItemCollection(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemCollection(const CLxLoc_ItemCollection &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemCollection;}
    LxResult
  Test (ILxUnknownID item)
  {
    return m_loc[0]->Test (m_loc,(ILxUnknownID)item);
  }
    LxResult
  Count (int type, unsigned *count)
  {
    return m_loc[0]->Count (m_loc,type,count);
  }
    LxResult
  ByIndex (int type, unsigned index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,type,index,ppvObj);
  }
    CLxResult
  ByIndex (int type, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ByIndex(m_loc,type,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Add (ILxUnknownID item)
  {
    return m_loc[0]->Add (m_loc,(ILxUnknownID)item);
  }
};





class CLxImpl_PackageInstance {
  public:
    virtual ~CLxImpl_PackageInstance() {}
    virtual LxResult
      pins_Initialize (ILxUnknownID item, ILxUnknownID super)
        { return LXe_NOTIMPL; }
    virtual void
      pins_Cleanup (void)
        { }
    virtual LxResult
      pins_SynthName (char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual unsigned
      pins_DupType (void)
        { return 0; }
    virtual LxResult
      pins_TestParent (ILxUnknownID item)
        { return LXe_TRUE; }
    virtual LxResult
      pins_Newborn (ILxUnknownID original, unsigned flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pins_Loading (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pins_AfterLoad (void)
        { return LXe_NOTIMPL; }
    virtual void
      pins_Doomed (void)
        { }
    virtual LxResult
      pins_Add (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pins_Remove (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_PackageInstance_Initialize LxResult pins_Initialize (ILxUnknownID item, ILxUnknownID super)
#define LXxO_PackageInstance_Initialize LXxD_PackageInstance_Initialize LXx_OVERRIDE
#define LXxC_PackageInstance_Initialize(c) LxResult c::pins_Initialize (ILxUnknownID item, ILxUnknownID super)
#define LXxD_PackageInstance_Cleanup void pins_Cleanup (void)
#define LXxO_PackageInstance_Cleanup LXxD_PackageInstance_Cleanup LXx_OVERRIDE
#define LXxC_PackageInstance_Cleanup(c) void c::pins_Cleanup (void)
#define LXxD_PackageInstance_SynthName LxResult pins_SynthName (char *buf, unsigned len)
#define LXxO_PackageInstance_SynthName LXxD_PackageInstance_SynthName LXx_OVERRIDE
#define LXxC_PackageInstance_SynthName(c) LxResult c::pins_SynthName (char *buf, unsigned len)
#define LXxD_PackageInstance_DupType unsigned pins_DupType (void)
#define LXxO_PackageInstance_DupType LXxD_PackageInstance_DupType LXx_OVERRIDE
#define LXxC_PackageInstance_DupType(c) unsigned c::pins_DupType (void)
#define LXxD_PackageInstance_TestParent LxResult pins_TestParent (ILxUnknownID item)
#define LXxO_PackageInstance_TestParent LXxD_PackageInstance_TestParent LXx_OVERRIDE
#define LXxC_PackageInstance_TestParent(c) LxResult c::pins_TestParent (ILxUnknownID item)
#define LXxD_PackageInstance_Newborn LxResult pins_Newborn (ILxUnknownID original, unsigned flags)
#define LXxO_PackageInstance_Newborn LXxD_PackageInstance_Newborn LXx_OVERRIDE
#define LXxC_PackageInstance_Newborn(c) LxResult c::pins_Newborn (ILxUnknownID original, unsigned flags)
#define LXxD_PackageInstance_Loading LxResult pins_Loading (void)
#define LXxO_PackageInstance_Loading LXxD_PackageInstance_Loading LXx_OVERRIDE
#define LXxC_PackageInstance_Loading(c) LxResult c::pins_Loading (void)
#define LXxD_PackageInstance_AfterLoad LxResult pins_AfterLoad (void)
#define LXxO_PackageInstance_AfterLoad LXxD_PackageInstance_AfterLoad LXx_OVERRIDE
#define LXxC_PackageInstance_AfterLoad(c) LxResult c::pins_AfterLoad (void)
#define LXxD_PackageInstance_Doomed void pins_Doomed (void)
#define LXxO_PackageInstance_Doomed LXxD_PackageInstance_Doomed LXx_OVERRIDE
#define LXxC_PackageInstance_Doomed(c) void c::pins_Doomed (void)
#define LXxD_PackageInstance_Add LxResult pins_Add (void)
#define LXxO_PackageInstance_Add LXxD_PackageInstance_Add LXx_OVERRIDE
#define LXxC_PackageInstance_Add(c) LxResult c::pins_Add (void)
#define LXxD_PackageInstance_Remove LxResult pins_Remove (void)
#define LXxO_PackageInstance_Remove LXxD_PackageInstance_Remove LXx_OVERRIDE
#define LXxC_PackageInstance_Remove(c) LxResult c::pins_Remove (void)
template <class T>
class CLxIfc_PackageInstance : public CLxInterface
{
    static LxResult
  Initialize (LXtObjectID wcom, LXtObjectID item, LXtObjectID super)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_Initialize ((ILxUnknownID)item,(ILxUnknownID)super);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    loc->pins_Cleanup ();
  }
    static LxResult
  SynthName (LXtObjectID wcom, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_SynthName (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned
  DupType (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    return loc->pins_DupType ();
  }
    static LxResult
  TestParent (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_TestParent ((ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Newborn (LXtObjectID wcom, LXtObjectID original, unsigned flags)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_Newborn ((ILxUnknownID)original,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Loading (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_Loading ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AfterLoad (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_AfterLoad ();
    } catch (LxResult rc) { return rc; }
  }
    static void
  Doomed (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    loc->pins_Doomed ();
  }
    static LxResult
  Add (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_Add ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Remove (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_Remove ();
    } catch (LxResult rc) { return rc; }
  }
  ILxPackageInstance vt;
public:
  CLxIfc_PackageInstance ()
  {
    vt.Initialize = Initialize;
    vt.Cleanup = Cleanup;
    vt.SynthName = SynthName;
    vt.DupType = DupType;
    vt.TestParent = TestParent;
    vt.Newborn = Newborn;
    vt.Loading = Loading;
    vt.AfterLoad = AfterLoad;
    vt.Doomed = Doomed;
    vt.Add = Add;
    vt.Remove = Remove;
    vTable = &vt.iunk;
    iid = &lx::guid_PackageInstance;
  }
};
class CLxLoc_PackageInstance : public CLxLocalize<ILxPackageInstanceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PackageInstance() {_init();}
  CLxLoc_PackageInstance(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PackageInstance(const CLxLoc_PackageInstance &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PackageInstance;}
    LxResult
  Initialize (ILxUnknownID item, ILxUnknownID super)
  {
    return m_loc[0]->Initialize (m_loc,(ILxUnknownID)item,(ILxUnknownID)super);
  }
    void
  Cleanup (void)
  {
    m_loc[0]->Cleanup (m_loc);
  }
    LxResult
  SynthName (char *buf, unsigned len)
  {
    return m_loc[0]->SynthName (m_loc,buf,len);
  }
    LxResult
  SynthName (std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->SynthName (m_loc,buf,len);
    LXWx_SBUF2
  }
    unsigned
  DupType (void)
  {
    return m_loc[0]->DupType (m_loc);
  }
    LxResult
  TestParent (ILxUnknownID item)
  {
    return m_loc[0]->TestParent (m_loc,(ILxUnknownID)item);
  }
    LxResult
  Newborn (ILxUnknownID original, unsigned flags)
  {
    return m_loc[0]->Newborn (m_loc,(ILxUnknownID)original,flags);
  }
    LxResult
  Loading (void)
  {
    return m_loc[0]->Loading (m_loc);
  }
    LxResult
  AfterLoad (void)
  {
    return m_loc[0]->AfterLoad (m_loc);
  }
    void
  Doomed (void)
  {
    m_loc[0]->Doomed (m_loc);
  }
    LxResult
  Add (void)
  {
    return m_loc[0]->Add (m_loc);
  }
    LxResult
  Remove (void)
  {
    return m_loc[0]->Remove (m_loc);
  }
};



class CLxLoc_SceneLoaderTarget : public CLxLocalize<ILxSceneLoaderTargetID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneLoaderTarget() {_init();}
  CLxLoc_SceneLoaderTarget(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SceneLoaderTarget(const CLxLoc_SceneLoaderTarget &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SceneLoaderTarget;}
    LxResult
  SetRootType (const char *typeName)
  {
    return m_loc[0]->SetRootType (m_loc,typeName);
  }
    LxResult
  SetFlags (unsigned flags)
  {
    return m_loc[0]->SetFlags (m_loc,flags);
  }
    LxResult
  ClearFlags (unsigned flags)
  {
    return m_loc[0]->ClearFlags (m_loc,flags);
  }
};

class CLxImpl_Package {
  public:
    virtual ~CLxImpl_Package() {}
    virtual LxResult
      pkg_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pkg_Attach (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pkg_TestInterface (const LXtGUID *guid)
        { return LXe_FALSE; }
    virtual LxResult
      pkg_PostLoad (ILxUnknownID scene)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pkg_CollectItems (ILxUnknownID collection, unsigned mode)
        { return LXe_NOTIMPL; }
};
#define LXxD_Package_SetupChannels LxResult pkg_SetupChannels (ILxUnknownID addChan)
#define LXxO_Package_SetupChannels LXxD_Package_SetupChannels LXx_OVERRIDE
#define LXxC_Package_SetupChannels(c) LxResult c::pkg_SetupChannels (ILxUnknownID addChan)
#define LXxD_Package_Attach LxResult pkg_Attach (void **ppvObj)
#define LXxO_Package_Attach LXxD_Package_Attach LXx_OVERRIDE
#define LXxC_Package_Attach(c) LxResult c::pkg_Attach (void **ppvObj)
#define LXxD_Package_TestInterface LxResult pkg_TestInterface (const LXtGUID *guid)
#define LXxO_Package_TestInterface LXxD_Package_TestInterface LXx_OVERRIDE
#define LXxC_Package_TestInterface(c) LxResult c::pkg_TestInterface (const LXtGUID *guid)
#define LXxD_Package_PostLoad LxResult pkg_PostLoad (ILxUnknownID scene)
#define LXxO_Package_PostLoad LXxD_Package_PostLoad LXx_OVERRIDE
#define LXxC_Package_PostLoad(c) LxResult c::pkg_PostLoad (ILxUnknownID scene)
#define LXxD_Package_CollectItems LxResult pkg_CollectItems (ILxUnknownID collection, unsigned mode)
#define LXxO_Package_CollectItems LXxD_Package_CollectItems LXx_OVERRIDE
#define LXxC_Package_CollectItems(c) LxResult c::pkg_CollectItems (ILxUnknownID collection, unsigned mode)
template <class T>
class CLxIfc_Package : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_Package, loc);
    try {
      return loc->pkg_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Attach (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Package, loc);
    try {
      return loc->pkg_Attach (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestInterface (LXtObjectID wcom, const LXtGUID *guid)
  {
    LXCWxINST (CLxImpl_Package, loc);
    try {
      return loc->pkg_TestInterface (guid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostLoad (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_Package, loc);
    try {
      return loc->pkg_PostLoad ((ILxUnknownID)scene);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CollectItems (LXtObjectID wcom, LXtObjectID collection, unsigned mode)
  {
    LXCWxINST (CLxImpl_Package, loc);
    try {
      return loc->pkg_CollectItems ((ILxUnknownID)collection,mode);
    } catch (LxResult rc) { return rc; }
  }
  ILxPackage vt;
public:
  CLxIfc_Package ()
  {
    vt.SetupChannels = SetupChannels;
    vt.Attach = Attach;
    vt.TestInterface = TestInterface;
    vt.PostLoad = PostLoad;
    vt.CollectItems = CollectItems;
    vTable = &vt.iunk;
    iid = &lx::guid_Package;
  }
};
class CLxLoc_Package : public CLxLocalize<ILxPackageID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Package() {_init();}
  CLxLoc_Package(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Package(const CLxLoc_Package &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Package;}
    LxResult
  SetupChannels (ILxUnknownID addChan)
  {
    return m_loc[0]->SetupChannels (m_loc,(ILxUnknownID)addChan);
  }
    LxResult
  Attach (void **ppvObj)
  {
    return m_loc[0]->Attach (m_loc,ppvObj);
  }
    CLxResult
  Attach (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Attach(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  TestInterface (const LXtGUID *guid)
  {
    return m_loc[0]->TestInterface (m_loc,guid);
  }
    LxResult
  PostLoad (ILxUnknownID scene)
  {
    return m_loc[0]->PostLoad (m_loc,(ILxUnknownID)scene);
  }
    LxResult
  CollectItems (ILxUnknownID collection, unsigned mode)
  {
    return m_loc[0]->CollectItems (m_loc,(ILxUnknownID)collection,mode);
  }
};

#endif

