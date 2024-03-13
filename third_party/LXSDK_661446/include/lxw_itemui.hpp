/*
 * C++ wrapper for lxitemui.h
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
#ifndef LXW_ITEMUI_HPP
#define LXW_ITEMUI_HPP

#include <lxitemui.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ItemTypeDest = {0xF088D1C9,0x78D9,0x4F73,0xA9,0x06,0x9B,0xD7,0xED,0xA0,0xB4,0x7D};
    static const LXtGUID guid_MeshOpDest = {0x451EE72D,0x640C,0x43E4,0xAE,0x1A,0x15,0x36,0x84,0x13,0x3C,0x42};
    static const LXtGUID guid_MeshDest = {0xDD13F0F7,0x9BA1,0x42EB,0xB3,0x6A,0x65,0x3B,0x32,0x2F,0xD5,0x20};
    static const LXtGUID guid_ChannelDropPreview = {0x41fe952b,0xdd79,0x4fe7,0xb6,0xe1,0x3d,0xae,0x47,0xce,0xe3,0x96};
    static const LXtGUID guid_ChannelDest = {0x0C84BE94,0x9B18,0x42F5,0xB3,0x74,0x48,0xC5,0xCD,0x27,0x8D,0x55};
    static const LXtGUID guid_ShaderDest = {0xb346d569,0xc841,0x46c8,0xb5,0x01,0x25,0x65,0x71,0x21,0x26,0x66};
    static const LXtGUID guid_LocatorDest = {0x451EE72D,0x640C,0x43E4,0xAE,0x1A,0x15,0x36,0x84,0x13,0x3C,0x65};
};

class CLxImpl_ItemTypeDest {
  public:
    virtual ~CLxImpl_ItemTypeDest() {}
    virtual LxResult
      ityped_Item (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual int
      ityped_Location (void)
        = 0;
};
#define LXxD_ItemTypeDest_Item LxResult ityped_Item (void **ppvObj)
#define LXxO_ItemTypeDest_Item LXxD_ItemTypeDest_Item LXx_OVERRIDE
#define LXxC_ItemTypeDest_Item(c) LxResult c::ityped_Item (void **ppvObj)
#define LXxD_ItemTypeDest_Location int ityped_Location (void)
#define LXxO_ItemTypeDest_Location LXxD_ItemTypeDest_Location LXx_OVERRIDE
#define LXxC_ItemTypeDest_Location(c) int c::ityped_Location (void)
template <class T>
class CLxIfc_ItemTypeDest : public CLxInterface
{
    static LxResult
  Item (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ItemTypeDest, loc);
    try {
      return loc->ityped_Item (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Location (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ItemTypeDest, loc);
    return loc->ityped_Location ();
  }
  ILxItemTypeDest vt;
public:
  CLxIfc_ItemTypeDest ()
  {
    vt.Item = Item;
    vt.Location = Location;
    vTable = &vt.iunk;
    iid = &lx::guid_ItemTypeDest;
  }
};
class CLxLoc_ItemTypeDest : public CLxLocalize<ILxItemTypeDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemTypeDest() {_init();}
  CLxLoc_ItemTypeDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemTypeDest(const CLxLoc_ItemTypeDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemTypeDest;}
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
  Location (void)
  {
    return m_loc[0]->Location (m_loc);
  }
};

class CLxImpl_MeshOpDest {
  public:
    virtual ~CLxImpl_MeshOpDest() {}
    virtual LxResult
      locd_Item (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      locd_ItemDeformer (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      locd_ItemHG (void **itemHG)
        { return LXe_NOTIMPL; }
    virtual const char*
      locd_Graph (void)
        = 0;
    virtual int
      locd_Location (void)
        = 0;
};
#define LXxD_MeshOpDest_Item LxResult locd_Item (void **ppvObj)
#define LXxO_MeshOpDest_Item LXxD_MeshOpDest_Item LXx_OVERRIDE
#define LXxC_MeshOpDest_Item(c) LxResult c::locd_Item (void **ppvObj)
#define LXxD_MeshOpDest_ItemDeformer LxResult locd_ItemDeformer (void **ppvObj)
#define LXxO_MeshOpDest_ItemDeformer LXxD_MeshOpDest_ItemDeformer LXx_OVERRIDE
#define LXxC_MeshOpDest_ItemDeformer(c) LxResult c::locd_ItemDeformer (void **ppvObj)
#define LXxD_MeshOpDest_ItemHG LxResult locd_ItemHG (void **itemHG)
#define LXxO_MeshOpDest_ItemHG LXxD_MeshOpDest_ItemHG LXx_OVERRIDE
#define LXxC_MeshOpDest_ItemHG(c) LxResult c::locd_ItemHG (void **itemHG)
#define LXxD_MeshOpDest_Graph const char* locd_Graph (void)
#define LXxO_MeshOpDest_Graph LXxD_MeshOpDest_Graph LXx_OVERRIDE
#define LXxC_MeshOpDest_Graph(c) const char* c::locd_Graph (void)
#define LXxD_MeshOpDest_Location int locd_Location (void)
#define LXxO_MeshOpDest_Location LXxD_MeshOpDest_Location LXx_OVERRIDE
#define LXxC_MeshOpDest_Location(c) int c::locd_Location (void)
template <class T>
class CLxIfc_MeshOpDest : public CLxInterface
{
    static LxResult
  Item (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_MeshOpDest, loc);
    try {
      return loc->locd_Item (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemDeformer (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_MeshOpDest, loc);
    try {
      return loc->locd_ItemDeformer (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemHG (LXtObjectID wcom, void **itemHG)
  {
    LXCWxINST (CLxImpl_MeshOpDest, loc);
    try {
      return loc->locd_ItemHG (itemHG);
    } catch (LxResult rc) { return rc; }
  }
    static const char*
  Graph (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_MeshOpDest, loc);
    return loc->locd_Graph ();
  }
    static int
  Location (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_MeshOpDest, loc);
    return loc->locd_Location ();
  }
  ILxMeshOpDest vt;
public:
  CLxIfc_MeshOpDest ()
  {
    vt.Item = Item;
    vt.ItemDeformer = ItemDeformer;
    vt.ItemHG = ItemHG;
    vt.Graph = Graph;
    vt.Location = Location;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshOpDest;
  }
};
class CLxLoc_MeshOpDest : public CLxLocalize<ILxMeshOpDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshOpDest() {_init();}
  CLxLoc_MeshOpDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshOpDest(const CLxLoc_MeshOpDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshOpDest;}
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
  ItemDeformer (void **ppvObj)
  {
    return m_loc[0]->ItemDeformer (m_loc,ppvObj);
  }
    CLxResult
  ItemDeformer (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemDeformer(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemHG (void **itemHG)
  {
    return m_loc[0]->ItemHG (m_loc,itemHG);
  }
    const char*
  Graph (void)
  {
    return m_loc[0]->Graph (m_loc);
  }
    int
  Location (void)
  {
    return m_loc[0]->Location (m_loc);
  }
};

class CLxImpl_MeshDest {
  public:
    virtual ~CLxImpl_MeshDest() {}
    virtual LxResult
      meshd_Item (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      meshd_HitPosition (LXtVector pos)
        { return LXe_NOTIMPL; }
    virtual LxResult
      meshd_HitNormal (LXtVector nrm)
        { return LXe_NOTIMPL; }
};
#define LXxD_MeshDest_Item LxResult meshd_Item (void **ppvObj)
#define LXxO_MeshDest_Item LXxD_MeshDest_Item LXx_OVERRIDE
#define LXxC_MeshDest_Item(c) LxResult c::meshd_Item (void **ppvObj)
#define LXxD_MeshDest_HitPosition LxResult meshd_HitPosition (LXtVector pos)
#define LXxO_MeshDest_HitPosition LXxD_MeshDest_HitPosition LXx_OVERRIDE
#define LXxC_MeshDest_HitPosition(c) LxResult c::meshd_HitPosition (LXtVector pos)
#define LXxD_MeshDest_HitNormal LxResult meshd_HitNormal (LXtVector nrm)
#define LXxO_MeshDest_HitNormal LXxD_MeshDest_HitNormal LXx_OVERRIDE
#define LXxC_MeshDest_HitNormal(c) LxResult c::meshd_HitNormal (LXtVector nrm)
template <class T>
class CLxIfc_MeshDest : public CLxInterface
{
    static LxResult
  Item (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_MeshDest, loc);
    try {
      return loc->meshd_Item (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HitPosition (LXtObjectID wcom, LXtVector pos)
  {
    LXCWxINST (CLxImpl_MeshDest, loc);
    try {
      return loc->meshd_HitPosition (pos);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HitNormal (LXtObjectID wcom, LXtVector nrm)
  {
    LXCWxINST (CLxImpl_MeshDest, loc);
    try {
      return loc->meshd_HitNormal (nrm);
    } catch (LxResult rc) { return rc; }
  }
  ILxMeshDest vt;
public:
  CLxIfc_MeshDest ()
  {
    vt.Item = Item;
    vt.HitPosition = HitPosition;
    vt.HitNormal = HitNormal;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshDest;
  }
};
class CLxLoc_MeshDest : public CLxLocalize<ILxMeshDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshDest() {_init();}
  CLxLoc_MeshDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshDest(const CLxLoc_MeshDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshDest;}
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
  HitPosition (LXtVector pos)
  {
    return m_loc[0]->HitPosition (m_loc,pos);
  }
    LxResult
  HitNormal (LXtVector nrm)
  {
    return m_loc[0]->HitNormal (m_loc,nrm);
  }
};

class CLxImpl_ChannelDropPreview {
  public:
    virtual ~CLxImpl_ChannelDropPreview() {}
    virtual int
      chandp_MarkChannel (void)
        = 0;
};
#define LXxD_ChannelDropPreview_MarkChannel int chandp_MarkChannel (void)
#define LXxO_ChannelDropPreview_MarkChannel LXxD_ChannelDropPreview_MarkChannel LXx_OVERRIDE
#define LXxC_ChannelDropPreview_MarkChannel(c) int c::chandp_MarkChannel (void)
template <class T>
class CLxIfc_ChannelDropPreview : public CLxInterface
{
    static int
  MarkChannel (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ChannelDropPreview, loc);
    return loc->chandp_MarkChannel ();
  }
  ILxChannelDropPreview vt;
public:
  CLxIfc_ChannelDropPreview ()
  {
    vt.MarkChannel = MarkChannel;
    vTable = &vt.iunk;
    iid = &lx::guid_ChannelDropPreview;
  }
};
class CLxLoc_ChannelDropPreview : public CLxLocalize<ILxChannelDropPreviewID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelDropPreview() {_init();}
  CLxLoc_ChannelDropPreview(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelDropPreview(const CLxLoc_ChannelDropPreview &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelDropPreview;}
    int
  MarkChannel (void)
  {
    return m_loc[0]->MarkChannel (m_loc);
  }
};

class CLxImpl_ChannelDest {
  public:
    virtual ~CLxImpl_ChannelDest() {}
    virtual LxResult
      chand_Channel (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual int
      chand_Location (void)
        = 0;
};
#define LXxD_ChannelDest_Channel LxResult chand_Channel (void **ppvObj)
#define LXxO_ChannelDest_Channel LXxD_ChannelDest_Channel LXx_OVERRIDE
#define LXxC_ChannelDest_Channel(c) LxResult c::chand_Channel (void **ppvObj)
#define LXxD_ChannelDest_Location int chand_Location (void)
#define LXxO_ChannelDest_Location LXxD_ChannelDest_Location LXx_OVERRIDE
#define LXxC_ChannelDest_Location(c) int c::chand_Location (void)
template <class T>
class CLxIfc_ChannelDest : public CLxInterface
{
    static LxResult
  Channel (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ChannelDest, loc);
    try {
      return loc->chand_Channel (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Location (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ChannelDest, loc);
    return loc->chand_Location ();
  }
  ILxChannelDest vt;
public:
  CLxIfc_ChannelDest ()
  {
    vt.Channel = Channel;
    vt.Location = Location;
    vTable = &vt.iunk;
    iid = &lx::guid_ChannelDest;
  }
};
class CLxLoc_ChannelDest : public CLxLocalize<ILxChannelDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelDest() {_init();}
  CLxLoc_ChannelDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelDest(const CLxLoc_ChannelDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelDest;}
    LxResult
  Channel (void **ppvObj)
  {
    return m_loc[0]->Channel (m_loc,ppvObj);
  }
    CLxResult
  Channel (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Channel(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    int
  Location (void)
  {
    return m_loc[0]->Location (m_loc);
  }
};

class CLxImpl_ShaderDest {
  public:
    virtual ~CLxImpl_ShaderDest() {}
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
#define LXxD_ShaderDest_Item LxResult locd_Item (void **ppvObj)
#define LXxO_ShaderDest_Item LXxD_ShaderDest_Item LXx_OVERRIDE
#define LXxC_ShaderDest_Item(c) LxResult c::locd_Item (void **ppvObj)
#define LXxD_ShaderDest_Type int locd_Type (void)
#define LXxO_ShaderDest_Type LXxD_ShaderDest_Type LXx_OVERRIDE
#define LXxC_ShaderDest_Type(c) int c::locd_Type (void)
#define LXxD_ShaderDest_Location int locd_Location (void)
#define LXxO_ShaderDest_Location LXxD_ShaderDest_Location LXx_OVERRIDE
#define LXxC_ShaderDest_Location(c) int c::locd_Location (void)
template <class T>
class CLxIfc_ShaderDest : public CLxInterface
{
    static LxResult
  Item (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ShaderDest, loc);
    try {
      return loc->locd_Item (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ShaderDest, loc);
    return loc->locd_Type ();
  }
    static int
  Location (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ShaderDest, loc);
    return loc->locd_Location ();
  }
  ILxShaderDest vt;
public:
  CLxIfc_ShaderDest ()
  {
    vt.Item = Item;
    vt.Type = Type;
    vt.Location = Location;
    vTable = &vt.iunk;
    iid = &lx::guid_ShaderDest;
  }
};
class CLxLoc_ShaderDest : public CLxLocalize<ILxShaderDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ShaderDest() {_init();}
  CLxLoc_ShaderDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ShaderDest(const CLxLoc_ShaderDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ShaderDest;}
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

class CLxImpl_LocatorDest {
  public:
    virtual ~CLxImpl_LocatorDest() {}
    virtual LxResult
      locd_Item (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual int
      locd_Location (void)
        = 0;
};
#define LXxD_LocatorDest_Item LxResult locd_Item (void **ppvObj)
#define LXxO_LocatorDest_Item LXxD_LocatorDest_Item LXx_OVERRIDE
#define LXxC_LocatorDest_Item(c) LxResult c::locd_Item (void **ppvObj)
#define LXxD_LocatorDest_Location int locd_Location (void)
#define LXxO_LocatorDest_Location LXxD_LocatorDest_Location LXx_OVERRIDE
#define LXxC_LocatorDest_Location(c) int c::locd_Location (void)
template <class T>
class CLxIfc_LocatorDest : public CLxInterface
{
    static LxResult
  Item (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_LocatorDest, loc);
    try {
      return loc->locd_Item (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Location (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_LocatorDest, loc);
    return loc->locd_Location ();
  }
  ILxLocatorDest vt;
public:
  CLxIfc_LocatorDest ()
  {
    vt.Item = Item;
    vt.Location = Location;
    vTable = &vt.iunk;
    iid = &lx::guid_LocatorDest;
  }
};
class CLxLoc_LocatorDest : public CLxLocalize<ILxLocatorDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LocatorDest() {_init();}
  CLxLoc_LocatorDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LocatorDest(const CLxLoc_LocatorDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LocatorDest;}
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
  Location (void)
  {
    return m_loc[0]->Location (m_loc);
  }
};

#endif

