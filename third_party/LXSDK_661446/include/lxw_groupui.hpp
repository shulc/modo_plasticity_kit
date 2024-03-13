/*
 * C++ wrapper for lxgroupui.h
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
#ifndef LXW_GROUPUI_HPP
#define LXW_GROUPUI_HPP

#include <lxgroupui.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_GroupMemberItemDest = {0x15329747,0xC092,0x475A,0xB1,0x88,0x11,0xA1,0x9A,0x15,0x18,0x86};
    static const LXtGUID guid_GroupDest = {0x14B16A73,0xF0A8,0x459A,0xB1,0xFD,0x78,0x50,0xDF,0x36,0x80,0x1C};
    static const LXtGUID guid_PoseItem = {0x73582252,0x0845,0x4B33,0x90,0x00,0x59,0x6C,0x78,0x65,0x67,0x5F};
    static const LXtGUID guid_GroupMemberChanDest = {0xC52AB199,0x2410,0x4698,0xB2,0x6C,0x45,0xFA,0x02,0x4C,0xBA,0xE9};
};

class CLxImpl_GroupMemberItemDest {
  public:
    virtual ~CLxImpl_GroupMemberItemDest() {}
    virtual LxResult
      grpmid_Group (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      grpmid_Item (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual int
      grpmid_Location (void)
        = 0;
};
#define LXxD_GroupMemberItemDest_Group LxResult grpmid_Group (void **ppvObj)
#define LXxO_GroupMemberItemDest_Group LXxD_GroupMemberItemDest_Group LXx_OVERRIDE
#define LXxC_GroupMemberItemDest_Group(c) LxResult c::grpmid_Group (void **ppvObj)
#define LXxD_GroupMemberItemDest_Item LxResult grpmid_Item (void **ppvObj)
#define LXxO_GroupMemberItemDest_Item LXxD_GroupMemberItemDest_Item LXx_OVERRIDE
#define LXxC_GroupMemberItemDest_Item(c) LxResult c::grpmid_Item (void **ppvObj)
#define LXxD_GroupMemberItemDest_Location int grpmid_Location (void)
#define LXxO_GroupMemberItemDest_Location LXxD_GroupMemberItemDest_Location LXx_OVERRIDE
#define LXxC_GroupMemberItemDest_Location(c) int c::grpmid_Location (void)
template <class T>
class CLxIfc_GroupMemberItemDest : public CLxInterface
{
    static LxResult
  Group (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_GroupMemberItemDest, loc);
    try {
      return loc->grpmid_Group (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Item (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_GroupMemberItemDest, loc);
    try {
      return loc->grpmid_Item (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Location (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_GroupMemberItemDest, loc);
    return loc->grpmid_Location ();
  }
  ILxGroupMemberItemDest vt;
public:
  CLxIfc_GroupMemberItemDest ()
  {
    vt.Group = Group;
    vt.Item = Item;
    vt.Location = Location;
    vTable = &vt.iunk;
    iid = &lx::guid_GroupMemberItemDest;
  }
};
class CLxLoc_GroupMemberItemDest : public CLxLocalize<ILxGroupMemberItemDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GroupMemberItemDest() {_init();}
  CLxLoc_GroupMemberItemDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GroupMemberItemDest(const CLxLoc_GroupMemberItemDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GroupMemberItemDest;}
    LxResult
  Group (void **ppvObj)
  {
    return m_loc[0]->Group (m_loc,ppvObj);
  }
    CLxResult
  Group (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Group(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
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
    int
  Location (void)
  {
    return m_loc[0]->Location (m_loc);
  }
};

class CLxImpl_GroupDest {
  public:
    virtual ~CLxImpl_GroupDest() {}
    virtual LxResult
      grpd_Group (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual int
      grpd_Location (void)
        = 0;
};
#define LXxD_GroupDest_Group LxResult grpd_Group (void **ppvObj)
#define LXxO_GroupDest_Group LXxD_GroupDest_Group LXx_OVERRIDE
#define LXxC_GroupDest_Group(c) LxResult c::grpd_Group (void **ppvObj)
#define LXxD_GroupDest_Location int grpd_Location (void)
#define LXxO_GroupDest_Location LXxD_GroupDest_Location LXx_OVERRIDE
#define LXxC_GroupDest_Location(c) int c::grpd_Location (void)
template <class T>
class CLxIfc_GroupDest : public CLxInterface
{
    static LxResult
  Group (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_GroupDest, loc);
    try {
      return loc->grpd_Group (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Location (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_GroupDest, loc);
    return loc->grpd_Location ();
  }
  ILxGroupDest vt;
public:
  CLxIfc_GroupDest ()
  {
    vt.Group = Group;
    vt.Location = Location;
    vTable = &vt.iunk;
    iid = &lx::guid_GroupDest;
  }
};
class CLxLoc_GroupDest : public CLxLocalize<ILxGroupDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GroupDest() {_init();}
  CLxLoc_GroupDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GroupDest(const CLxLoc_GroupDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GroupDest;}
    LxResult
  Group (void **ppvObj)
  {
    return m_loc[0]->Group (m_loc,ppvObj);
  }
    CLxResult
  Group (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Group(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    int
  Location (void)
  {
    return m_loc[0]->Location (m_loc);
  }
};

class CLxLoc_PoseItem : public CLxLocalize<ILxPoseItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PoseItem() {_init();}
  CLxLoc_PoseItem(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PoseItem(const CLxLoc_PoseItem &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PoseItem;}
    LxResult
  Create (void)
  {
    return m_loc[0]->Create (m_loc);
  }
    LxResult
  SetInt (ILxUnknownID item, unsigned int channelIndex, int value)
  {
    return m_loc[0]->SetInt (m_loc,(ILxUnknownID)item,channelIndex,value);
  }
    LxResult
  SetFloat (ILxUnknownID item, unsigned int channelIndex, float value)
  {
    return m_loc[0]->SetFloat (m_loc,(ILxUnknownID)item,channelIndex,value);
  }
    LxResult
  GetInt (ILxUnknownID item, unsigned int channelIndex, int *value)
  {
    return m_loc[0]->GetInt (m_loc,(ILxUnknownID)item,channelIndex,value);
  }
    LxResult
  GetFloat (ILxUnknownID item, unsigned int channelIndex, float *value)
  {
    return m_loc[0]->GetFloat (m_loc,(ILxUnknownID)item,channelIndex,value);
  }
};

class CLxImpl_GroupMemberChanDest {
  public:
    virtual ~CLxImpl_GroupMemberChanDest() {}
    virtual LxResult
      grpmcd_Group (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      grpmcd_Channel (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual int
      grpmcd_Location (void)
        = 0;
};
#define LXxD_GroupMemberChanDest_Group LxResult grpmcd_Group (void **ppvObj)
#define LXxO_GroupMemberChanDest_Group LXxD_GroupMemberChanDest_Group LXx_OVERRIDE
#define LXxC_GroupMemberChanDest_Group(c) LxResult c::grpmcd_Group (void **ppvObj)
#define LXxD_GroupMemberChanDest_Channel LxResult grpmcd_Channel (void **ppvObj)
#define LXxO_GroupMemberChanDest_Channel LXxD_GroupMemberChanDest_Channel LXx_OVERRIDE
#define LXxC_GroupMemberChanDest_Channel(c) LxResult c::grpmcd_Channel (void **ppvObj)
#define LXxD_GroupMemberChanDest_Location int grpmcd_Location (void)
#define LXxO_GroupMemberChanDest_Location LXxD_GroupMemberChanDest_Location LXx_OVERRIDE
#define LXxC_GroupMemberChanDest_Location(c) int c::grpmcd_Location (void)
template <class T>
class CLxIfc_GroupMemberChanDest : public CLxInterface
{
    static LxResult
  Group (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_GroupMemberChanDest, loc);
    try {
      return loc->grpmcd_Group (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Channel (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_GroupMemberChanDest, loc);
    try {
      return loc->grpmcd_Channel (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Location (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_GroupMemberChanDest, loc);
    return loc->grpmcd_Location ();
  }
  ILxGroupMemberChanDest vt;
public:
  CLxIfc_GroupMemberChanDest ()
  {
    vt.Group = Group;
    vt.Channel = Channel;
    vt.Location = Location;
    vTable = &vt.iunk;
    iid = &lx::guid_GroupMemberChanDest;
  }
};
class CLxLoc_GroupMemberChanDest : public CLxLocalize<ILxGroupMemberChanDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GroupMemberChanDest() {_init();}
  CLxLoc_GroupMemberChanDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GroupMemberChanDest(const CLxLoc_GroupMemberChanDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GroupMemberChanDest;}
    LxResult
  Group (void **ppvObj)
  {
    return m_loc[0]->Group (m_loc,ppvObj);
  }
    CLxResult
  Group (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Group(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
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

#endif

