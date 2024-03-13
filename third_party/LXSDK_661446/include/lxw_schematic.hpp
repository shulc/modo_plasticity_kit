/*
 * C++ wrapper for lxschematic.h
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
#ifndef LXW_SCHEMATIC_HPP
#define LXW_SCHEMATIC_HPP

#include <lxschematic.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_SchematicConnection3 = {0x38BB9ED8,0xF21E,0x40C1,0xB1,0x18,0xE7,0x66,0xF2,0x90,0x7E,0x4F};
    static const LXtGUID guid_SchematicConnection = {0x3578D79B,0x798C,0x4250,0x95,0x38,0xCF,0x7E,0xB9,0x39,0xBB,0x6E};
    static const LXtGUID guid_SchematicNode = {0x686F59FF,0x1E3F,0x4599,0xAD,0xE0,0xE3,0x61,0x3C,0x48,0x3D,0x38};
    static const LXtGUID guid_SchemaDest = {0xAA362F0B,0xDC2F,0x4480,0x82,0xFF,0x32,0xD3,0x8F,0xD5,0x7F,0x4F};
    static const LXtGUID guid_SchematicGroup = {0xFD5B73D1,0xC9E2,0x44C2,0x8D,0x8D,0x23,0xEE,0x77,0x06,0xB3,0xAB};
    static const LXtGUID guid_SchematicConnection1 = {0x5AC0A075,0x72B7,0x4935,0x8D,0xA5,0x58,0x8D,0xF7,0x99,0x90,0x69};
    static const LXtGUID guid_SchematicNodeChannel = {0x322555CC,0xD635,0x48A4,0xBC,0xDB,0xAE,0x86,0xCC,0xFE,0x29,0xCF};
    static const LXtGUID guid_SchematicNodeConnection = {0x5E015AAB,0xE069,0x4676,0x8F,0x04,0xC7,0xC8,0xF8,0x81,0x81,0xA5};
    static const LXtGUID guid_SchematicConnection2 = {0x7E238C0E,0x0D64,0x44ed,0xA7,0x80,0x13,0xD2,0x5A,0x24,0x82,0xD3};
};

class CLxImpl_SchematicConnection3 {
  public:
    virtual ~CLxImpl_SchematicConnection3() {}
    virtual LxResult
      schm_ItemFlags (ILxUnknownID item, unsigned *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_AllowConnectType (ILxUnknownID to, unsigned int type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_GraphName (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Count (ILxUnknownID item, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
    virtual int
      schm_BaseFlags (void)
        { return 0; }
    virtual LxResult
      schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
        { return LXe_NOTIMPL; }
    virtual int
      schm_ItemFlagsValid (void)
        { return 1; }
    virtual LxResult
      schm_ChannelAllowConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ChannelIOType (unsigned int *ioType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ChannelCount (ILxUnknownID xItem, int fromIndex, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ChannelByIndex (ILxUnknownID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ChannelConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ChannelDisconnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
};
#define LXxD_SchematicConnection3_ItemFlags LxResult schm_ItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxO_SchematicConnection3_ItemFlags LXxD_SchematicConnection3_ItemFlags LXx_OVERRIDE
#define LXxC_SchematicConnection3_ItemFlags(c) LxResult c::schm_ItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxD_SchematicConnection3_AllowConnect LxResult schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
#define LXxO_SchematicConnection3_AllowConnect LXxD_SchematicConnection3_AllowConnect LXx_OVERRIDE
#define LXxC_SchematicConnection3_AllowConnect(c) LxResult c::schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
#define LXxD_SchematicConnection3_AllowConnectType LxResult schm_AllowConnectType (ILxUnknownID to, unsigned int type)
#define LXxO_SchematicConnection3_AllowConnectType LXxD_SchematicConnection3_AllowConnectType LXx_OVERRIDE
#define LXxC_SchematicConnection3_AllowConnectType(c) LxResult c::schm_AllowConnectType (ILxUnknownID to, unsigned int type)
#define LXxD_SchematicConnection3_GraphName LxResult schm_GraphName (const char **name)
#define LXxO_SchematicConnection3_GraphName LXxD_SchematicConnection3_GraphName LXx_OVERRIDE
#define LXxC_SchematicConnection3_GraphName(c) LxResult c::schm_GraphName (const char **name)
#define LXxD_SchematicConnection3_Count LxResult schm_Count (ILxUnknownID item, unsigned *count)
#define LXxO_SchematicConnection3_Count LXxD_SchematicConnection3_Count LXx_OVERRIDE
#define LXxC_SchematicConnection3_Count(c) LxResult c::schm_Count (ILxUnknownID item, unsigned *count)
#define LXxD_SchematicConnection3_ByIndex LxResult schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
#define LXxO_SchematicConnection3_ByIndex LXxD_SchematicConnection3_ByIndex LXx_OVERRIDE
#define LXxC_SchematicConnection3_ByIndex(c) LxResult c::schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
#define LXxD_SchematicConnection3_Connect LxResult schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection3_Connect LXxD_SchematicConnection3_Connect LXx_OVERRIDE
#define LXxC_SchematicConnection3_Connect(c) LxResult c::schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
#define LXxD_SchematicConnection3_Disconnect LxResult schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
#define LXxO_SchematicConnection3_Disconnect LXxD_SchematicConnection3_Disconnect LXx_OVERRIDE
#define LXxC_SchematicConnection3_Disconnect(c) LxResult c::schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
#define LXxD_SchematicConnection3_BaseFlags int schm_BaseFlags (void)
#define LXxO_SchematicConnection3_BaseFlags LXxD_SchematicConnection3_BaseFlags LXx_OVERRIDE
#define LXxC_SchematicConnection3_BaseFlags(c) int c::schm_BaseFlags (void)
#define LXxD_SchematicConnection3_PerItemFlags LxResult schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxO_SchematicConnection3_PerItemFlags LXxD_SchematicConnection3_PerItemFlags LXx_OVERRIDE
#define LXxC_SchematicConnection3_PerItemFlags(c) LxResult c::schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxD_SchematicConnection3_ItemFlagsValid int schm_ItemFlagsValid (void)
#define LXxO_SchematicConnection3_ItemFlagsValid LXxD_SchematicConnection3_ItemFlagsValid LXx_OVERRIDE
#define LXxC_SchematicConnection3_ItemFlagsValid(c) int c::schm_ItemFlagsValid (void)
#define LXxD_SchematicConnection3_ChannelAllowConnect LxResult schm_ChannelAllowConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection3_ChannelAllowConnect LXxD_SchematicConnection3_ChannelAllowConnect LXx_OVERRIDE
#define LXxC_SchematicConnection3_ChannelAllowConnect(c) LxResult c::schm_ChannelAllowConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxD_SchematicConnection3_ChannelIOType LxResult schm_ChannelIOType (unsigned int *ioType)
#define LXxO_SchematicConnection3_ChannelIOType LXxD_SchematicConnection3_ChannelIOType LXx_OVERRIDE
#define LXxC_SchematicConnection3_ChannelIOType(c) LxResult c::schm_ChannelIOType (unsigned int *ioType)
#define LXxD_SchematicConnection3_ChannelCount LxResult schm_ChannelCount (ILxUnknownID xItem, int fromIndex, unsigned *count)
#define LXxO_SchematicConnection3_ChannelCount LXxD_SchematicConnection3_ChannelCount LXx_OVERRIDE
#define LXxC_SchematicConnection3_ChannelCount(c) LxResult c::schm_ChannelCount (ILxUnknownID xItem, int fromIndex, unsigned *count)
#define LXxD_SchematicConnection3_ChannelByIndex LxResult schm_ChannelByIndex (ILxUnknownID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex)
#define LXxO_SchematicConnection3_ChannelByIndex LXxD_SchematicConnection3_ChannelByIndex LXx_OVERRIDE
#define LXxC_SchematicConnection3_ChannelByIndex(c) LxResult c::schm_ChannelByIndex (ILxUnknownID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex)
#define LXxD_SchematicConnection3_ChannelConnect LxResult schm_ChannelConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection3_ChannelConnect LXxD_SchematicConnection3_ChannelConnect LXx_OVERRIDE
#define LXxC_SchematicConnection3_ChannelConnect(c) LxResult c::schm_ChannelConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxD_SchematicConnection3_ChannelDisconnect LxResult schm_ChannelDisconnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection3_ChannelDisconnect LXxD_SchematicConnection3_ChannelDisconnect LXx_OVERRIDE
#define LXxC_SchematicConnection3_ChannelDisconnect(c) LxResult c::schm_ChannelDisconnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
template <class T>
class CLxIfc_SchematicConnection3 : public CLxInterface
{
    static LxResult
  ItemFlags (LXtObjectID wcom, LXtObjectID item, unsigned *flags)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_ItemFlags ((ILxUnknownID)item,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AllowConnect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_AllowConnect ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AllowConnectType (LXtObjectID wcom, LXtObjectID to, unsigned int type)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_AllowConnectType ((ILxUnknownID)to,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GraphName (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_GraphName (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Count (LXtObjectID wcom, LXtObjectID item, unsigned *count)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_Count ((ILxUnknownID)item,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ByIndex (LXtObjectID wcom, LXtObjectID item, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_ByIndex ((ILxUnknownID)item,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Connect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_Connect ((ILxUnknownID)from,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Disconnect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_Disconnect ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
    static int
  BaseFlags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    return loc->schm_BaseFlags ();
  }
    static LxResult
  PerItemFlags (LXtObjectID wcom, LXtObjectID item, unsigned *flags)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_PerItemFlags ((ILxUnknownID)item,flags);
    } catch (LxResult rc) { return rc; }
  }
    static int
  ItemFlagsValid (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    return loc->schm_ItemFlagsValid ();
  }
    static LxResult
  ChannelAllowConnect (LXtObjectID wcom, LXtObjectID from, int fromIndex, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_ChannelAllowConnect ((ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelIOType (LXtObjectID wcom, unsigned int *ioType)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_ChannelIOType (ioType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelCount (LXtObjectID wcom, LXtObjectID xItem, int fromIndex, unsigned *count)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_ChannelCount ((ILxUnknownID)xItem,fromIndex,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelByIndex (LXtObjectID wcom, LXtObjectID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_ChannelByIndex ((ILxUnknownID)xItem,fromIndex,index,ppvObj,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelConnect (LXtObjectID wcom, LXtObjectID from, int fromIndex, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_ChannelConnect ((ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelDisconnect (LXtObjectID wcom, LXtObjectID from, int fromIndex, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection3, loc);
    try {
      return loc->schm_ChannelDisconnect ((ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
  ILxSchematicConnection3 vt;
public:
  CLxIfc_SchematicConnection3 ()
  {
    vt.ItemFlags = ItemFlags;
    vt.AllowConnect = AllowConnect;
    vt.AllowConnectType = AllowConnectType;
    vt.GraphName = GraphName;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vt.Connect = Connect;
    vt.Disconnect = Disconnect;
    vt.BaseFlags = BaseFlags;
    vt.PerItemFlags = PerItemFlags;
    vt.ItemFlagsValid = ItemFlagsValid;
    vt.ChannelAllowConnect = ChannelAllowConnect;
    vt.ChannelIOType = ChannelIOType;
    vt.ChannelCount = ChannelCount;
    vt.ChannelByIndex = ChannelByIndex;
    vt.ChannelConnect = ChannelConnect;
    vt.ChannelDisconnect = ChannelDisconnect;
    vTable = &vt.iunk;
    iid = &lx::guid_SchematicConnection3;
  }
};
class CLxLoc_SchematicConnection3 : public CLxLocalize<ILxSchematicConnection3ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SchematicConnection3() {_init();}
  CLxLoc_SchematicConnection3(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SchematicConnection3(const CLxLoc_SchematicConnection3 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SchematicConnection3;}
    LxResult
  ItemFlags (ILxUnknownID item, unsigned *flags)
  {
    return m_loc[0]->ItemFlags (m_loc,(ILxUnknownID)item,flags);
  }
    LxResult
  AllowConnect (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->AllowConnect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    LxResult
  AllowConnectType (ILxUnknownID to, unsigned int type)
  {
    return m_loc[0]->AllowConnectType (m_loc,(ILxUnknownID)to,type);
  }
    LxResult
  GraphName (const char **name)
  {
    return m_loc[0]->GraphName (m_loc,name);
  }
    LxResult
  Count (ILxUnknownID item, unsigned *count)
  {
    return m_loc[0]->Count (m_loc,(ILxUnknownID)item,count);
  }
    LxResult
  ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,(ILxUnknownID)item,index,ppvObj);
  }
    CLxResult
  ByIndex (ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ByIndex(m_loc,(ILxUnknownID)item,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->Connect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to,toIndex);
  }
    LxResult
  Disconnect (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->Disconnect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    int
  BaseFlags (void)
  {
    return m_loc[0]->BaseFlags (m_loc);
  }
    LxResult
  PerItemFlags (ILxUnknownID item, unsigned *flags)
  {
    return m_loc[0]->PerItemFlags (m_loc,(ILxUnknownID)item,flags);
  }
    int
  ItemFlagsValid (void)
  {
    return m_loc[0]->ItemFlagsValid (m_loc);
  }
    LxResult
  ChannelAllowConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->ChannelAllowConnect (m_loc,(ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
  }
    LxResult
  ChannelIOType (unsigned int *ioType)
  {
    return m_loc[0]->ChannelIOType (m_loc,ioType);
  }
    LxResult
  ChannelCount (ILxUnknownID xItem, int fromIndex, unsigned *count)
  {
    return m_loc[0]->ChannelCount (m_loc,(ILxUnknownID)xItem,fromIndex,count);
  }
    LxResult
  ChannelByIndex (ILxUnknownID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex)
  {
    return m_loc[0]->ChannelByIndex (m_loc,(ILxUnknownID)xItem,fromIndex,index,ppvObj,toIndex);
  }
    CLxResult
  ChannelByIndex (ILxUnknownID xItem, int fromIndex, unsigned index, CLxLocalizedObject &o_dest, int *toIndex)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ChannelByIndex(m_loc,(ILxUnknownID)xItem,fromIndex,index,&o_obj,toIndex);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ChannelConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->ChannelConnect (m_loc,(ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
  }
    LxResult
  ChannelDisconnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->ChannelDisconnect (m_loc,(ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
  }
};

class CLxImpl_SchematicConnection {
  public:
    virtual ~CLxImpl_SchematicConnection() {}
    virtual LxResult
      schm_ItemFlags (ILxUnknownID item, unsigned *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_AllowConnectType (ILxUnknownID to, unsigned int type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_GraphName (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Count (ILxUnknownID item, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
    virtual int
      schm_BaseFlags (void)
        { return 0; }
    virtual LxResult
      schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
        { return LXe_NOTIMPL; }
    virtual int
      schm_ItemFlagsValid (void)
        { return 1; }
    virtual LxResult
      schm_ChannelAllowConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ChannelIOType (unsigned int *ioType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ChannelCount (ILxUnknownID xItem, int fromIndex, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ChannelByIndex (ILxUnknownID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ChannelConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ChannelDisconnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_PresetBrowserHash (ILxUnknownID item, const char **hash)
        { return LXe_NOTIMPL; }
};
#define LXxD_SchematicConnection_ItemFlags LxResult schm_ItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxO_SchematicConnection_ItemFlags LXxD_SchematicConnection_ItemFlags LXx_OVERRIDE
#define LXxC_SchematicConnection_ItemFlags(c) LxResult c::schm_ItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxD_SchematicConnection_AllowConnect LxResult schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
#define LXxO_SchematicConnection_AllowConnect LXxD_SchematicConnection_AllowConnect LXx_OVERRIDE
#define LXxC_SchematicConnection_AllowConnect(c) LxResult c::schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
#define LXxD_SchematicConnection_AllowConnectType LxResult schm_AllowConnectType (ILxUnknownID to, unsigned int type)
#define LXxO_SchematicConnection_AllowConnectType LXxD_SchematicConnection_AllowConnectType LXx_OVERRIDE
#define LXxC_SchematicConnection_AllowConnectType(c) LxResult c::schm_AllowConnectType (ILxUnknownID to, unsigned int type)
#define LXxD_SchematicConnection_GraphName LxResult schm_GraphName (const char **name)
#define LXxO_SchematicConnection_GraphName LXxD_SchematicConnection_GraphName LXx_OVERRIDE
#define LXxC_SchematicConnection_GraphName(c) LxResult c::schm_GraphName (const char **name)
#define LXxD_SchematicConnection_Count LxResult schm_Count (ILxUnknownID item, unsigned *count)
#define LXxO_SchematicConnection_Count LXxD_SchematicConnection_Count LXx_OVERRIDE
#define LXxC_SchematicConnection_Count(c) LxResult c::schm_Count (ILxUnknownID item, unsigned *count)
#define LXxD_SchematicConnection_ByIndex LxResult schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
#define LXxO_SchematicConnection_ByIndex LXxD_SchematicConnection_ByIndex LXx_OVERRIDE
#define LXxC_SchematicConnection_ByIndex(c) LxResult c::schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
#define LXxD_SchematicConnection_Connect LxResult schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection_Connect LXxD_SchematicConnection_Connect LXx_OVERRIDE
#define LXxC_SchematicConnection_Connect(c) LxResult c::schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
#define LXxD_SchematicConnection_Disconnect LxResult schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
#define LXxO_SchematicConnection_Disconnect LXxD_SchematicConnection_Disconnect LXx_OVERRIDE
#define LXxC_SchematicConnection_Disconnect(c) LxResult c::schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
#define LXxD_SchematicConnection_BaseFlags int schm_BaseFlags (void)
#define LXxO_SchematicConnection_BaseFlags LXxD_SchematicConnection_BaseFlags LXx_OVERRIDE
#define LXxC_SchematicConnection_BaseFlags(c) int c::schm_BaseFlags (void)
#define LXxD_SchematicConnection_PerItemFlags LxResult schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxO_SchematicConnection_PerItemFlags LXxD_SchematicConnection_PerItemFlags LXx_OVERRIDE
#define LXxC_SchematicConnection_PerItemFlags(c) LxResult c::schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxD_SchematicConnection_ItemFlagsValid int schm_ItemFlagsValid (void)
#define LXxO_SchematicConnection_ItemFlagsValid LXxD_SchematicConnection_ItemFlagsValid LXx_OVERRIDE
#define LXxC_SchematicConnection_ItemFlagsValid(c) int c::schm_ItemFlagsValid (void)
#define LXxD_SchematicConnection_ChannelAllowConnect LxResult schm_ChannelAllowConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection_ChannelAllowConnect LXxD_SchematicConnection_ChannelAllowConnect LXx_OVERRIDE
#define LXxC_SchematicConnection_ChannelAllowConnect(c) LxResult c::schm_ChannelAllowConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxD_SchematicConnection_ChannelIOType LxResult schm_ChannelIOType (unsigned int *ioType)
#define LXxO_SchematicConnection_ChannelIOType LXxD_SchematicConnection_ChannelIOType LXx_OVERRIDE
#define LXxC_SchematicConnection_ChannelIOType(c) LxResult c::schm_ChannelIOType (unsigned int *ioType)
#define LXxD_SchematicConnection_ChannelCount LxResult schm_ChannelCount (ILxUnknownID xItem, int fromIndex, unsigned *count)
#define LXxO_SchematicConnection_ChannelCount LXxD_SchematicConnection_ChannelCount LXx_OVERRIDE
#define LXxC_SchematicConnection_ChannelCount(c) LxResult c::schm_ChannelCount (ILxUnknownID xItem, int fromIndex, unsigned *count)
#define LXxD_SchematicConnection_ChannelByIndex LxResult schm_ChannelByIndex (ILxUnknownID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex)
#define LXxO_SchematicConnection_ChannelByIndex LXxD_SchematicConnection_ChannelByIndex LXx_OVERRIDE
#define LXxC_SchematicConnection_ChannelByIndex(c) LxResult c::schm_ChannelByIndex (ILxUnknownID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex)
#define LXxD_SchematicConnection_ChannelConnect LxResult schm_ChannelConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection_ChannelConnect LXxD_SchematicConnection_ChannelConnect LXx_OVERRIDE
#define LXxC_SchematicConnection_ChannelConnect(c) LxResult c::schm_ChannelConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxD_SchematicConnection_ChannelDisconnect LxResult schm_ChannelDisconnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection_ChannelDisconnect LXxD_SchematicConnection_ChannelDisconnect LXx_OVERRIDE
#define LXxC_SchematicConnection_ChannelDisconnect(c) LxResult c::schm_ChannelDisconnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
#define LXxD_SchematicConnection_PresetBrowserHash LxResult schm_PresetBrowserHash (ILxUnknownID item, const char **hash)
#define LXxO_SchematicConnection_PresetBrowserHash LXxD_SchematicConnection_PresetBrowserHash LXx_OVERRIDE
#define LXxC_SchematicConnection_PresetBrowserHash(c) LxResult c::schm_PresetBrowserHash (ILxUnknownID item, const char **hash)
template <class T>
class CLxIfc_SchematicConnection : public CLxInterface
{
    static LxResult
  ItemFlags (LXtObjectID wcom, LXtObjectID item, unsigned *flags)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_ItemFlags ((ILxUnknownID)item,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AllowConnect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_AllowConnect ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AllowConnectType (LXtObjectID wcom, LXtObjectID to, unsigned int type)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_AllowConnectType ((ILxUnknownID)to,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GraphName (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_GraphName (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Count (LXtObjectID wcom, LXtObjectID item, unsigned *count)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_Count ((ILxUnknownID)item,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ByIndex (LXtObjectID wcom, LXtObjectID item, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_ByIndex ((ILxUnknownID)item,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Connect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_Connect ((ILxUnknownID)from,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Disconnect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_Disconnect ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
    static int
  BaseFlags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    return loc->schm_BaseFlags ();
  }
    static LxResult
  PerItemFlags (LXtObjectID wcom, LXtObjectID item, unsigned *flags)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_PerItemFlags ((ILxUnknownID)item,flags);
    } catch (LxResult rc) { return rc; }
  }
    static int
  ItemFlagsValid (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    return loc->schm_ItemFlagsValid ();
  }
    static LxResult
  ChannelAllowConnect (LXtObjectID wcom, LXtObjectID from, int fromIndex, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_ChannelAllowConnect ((ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelIOType (LXtObjectID wcom, unsigned int *ioType)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_ChannelIOType (ioType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelCount (LXtObjectID wcom, LXtObjectID xItem, int fromIndex, unsigned *count)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_ChannelCount ((ILxUnknownID)xItem,fromIndex,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelByIndex (LXtObjectID wcom, LXtObjectID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_ChannelByIndex ((ILxUnknownID)xItem,fromIndex,index,ppvObj,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelConnect (LXtObjectID wcom, LXtObjectID from, int fromIndex, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_ChannelConnect ((ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelDisconnect (LXtObjectID wcom, LXtObjectID from, int fromIndex, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_ChannelDisconnect ((ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PresetBrowserHash (LXtObjectID wcom, LXtObjectID item, const char **hash)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_PresetBrowserHash ((ILxUnknownID)item,hash);
    } catch (LxResult rc) { return rc; }
  }
  ILxSchematicConnection vt;
public:
  CLxIfc_SchematicConnection ()
  {
    vt.ItemFlags = ItemFlags;
    vt.AllowConnect = AllowConnect;
    vt.AllowConnectType = AllowConnectType;
    vt.GraphName = GraphName;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vt.Connect = Connect;
    vt.Disconnect = Disconnect;
    vt.BaseFlags = BaseFlags;
    vt.PerItemFlags = PerItemFlags;
    vt.ItemFlagsValid = ItemFlagsValid;
    vt.ChannelAllowConnect = ChannelAllowConnect;
    vt.ChannelIOType = ChannelIOType;
    vt.ChannelCount = ChannelCount;
    vt.ChannelByIndex = ChannelByIndex;
    vt.ChannelConnect = ChannelConnect;
    vt.ChannelDisconnect = ChannelDisconnect;
    vt.PresetBrowserHash = PresetBrowserHash;
    vTable = &vt.iunk;
    iid = &lx::guid_SchematicConnection;
  }
};
class CLxLoc_SchematicConnection : public CLxLocalize<ILxSchematicConnectionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SchematicConnection() {_init();}
  CLxLoc_SchematicConnection(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SchematicConnection(const CLxLoc_SchematicConnection &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SchematicConnection;}
    LxResult
  ItemFlags (ILxUnknownID item, unsigned *flags)
  {
    return m_loc[0]->ItemFlags (m_loc,(ILxUnknownID)item,flags);
  }
    LxResult
  AllowConnect (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->AllowConnect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    LxResult
  AllowConnectType (ILxUnknownID to, unsigned int type)
  {
    return m_loc[0]->AllowConnectType (m_loc,(ILxUnknownID)to,type);
  }
    LxResult
  GraphName (const char **name)
  {
    return m_loc[0]->GraphName (m_loc,name);
  }
    LxResult
  Count (ILxUnknownID item, unsigned *count)
  {
    return m_loc[0]->Count (m_loc,(ILxUnknownID)item,count);
  }
    LxResult
  ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,(ILxUnknownID)item,index,ppvObj);
  }
    CLxResult
  ByIndex (ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ByIndex(m_loc,(ILxUnknownID)item,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->Connect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to,toIndex);
  }
    LxResult
  Disconnect (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->Disconnect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    int
  BaseFlags (void)
  {
    return m_loc[0]->BaseFlags (m_loc);
  }
    LxResult
  PerItemFlags (ILxUnknownID item, unsigned *flags)
  {
    return m_loc[0]->PerItemFlags (m_loc,(ILxUnknownID)item,flags);
  }
    int
  ItemFlagsValid (void)
  {
    return m_loc[0]->ItemFlagsValid (m_loc);
  }
    LxResult
  ChannelAllowConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->ChannelAllowConnect (m_loc,(ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
  }
    LxResult
  ChannelIOType (unsigned int *ioType)
  {
    return m_loc[0]->ChannelIOType (m_loc,ioType);
  }
    LxResult
  ChannelCount (ILxUnknownID xItem, int fromIndex, unsigned *count)
  {
    return m_loc[0]->ChannelCount (m_loc,(ILxUnknownID)xItem,fromIndex,count);
  }
    LxResult
  ChannelByIndex (ILxUnknownID xItem, int fromIndex, unsigned index, void **ppvObj, int *toIndex)
  {
    return m_loc[0]->ChannelByIndex (m_loc,(ILxUnknownID)xItem,fromIndex,index,ppvObj,toIndex);
  }
    CLxResult
  ChannelByIndex (ILxUnknownID xItem, int fromIndex, unsigned index, CLxLocalizedObject &o_dest, int *toIndex)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ChannelByIndex(m_loc,(ILxUnknownID)xItem,fromIndex,index,&o_obj,toIndex);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ChannelConnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->ChannelConnect (m_loc,(ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
  }
    LxResult
  ChannelDisconnect (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->ChannelDisconnect (m_loc,(ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
  }
    LxResult
  PresetBrowserHash (ILxUnknownID item, const char **hash)
  {
    return m_loc[0]->PresetBrowserHash (m_loc,(ILxUnknownID)item,hash);
  }
};

class CLxLoc_SchematicNode : public CLxLocalize<ILxSchematicNodeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SchematicNode() {_init();}
  CLxLoc_SchematicNode(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SchematicNode(const CLxLoc_SchematicNode &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SchematicNode;}
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
    LxResult
  AddChannel (unsigned int index)
  {
    return m_loc[0]->AddChannel (m_loc,index);
  }
    LxResult
  RemoveChannel (unsigned int index)
  {
    return m_loc[0]->RemoveChannel (m_loc,index);
  }
    LxResult
  ChannelCount (unsigned int *count) const
  {
    return m_loc[0]->ChannelCount (m_loc,count);
  }
    LxResult
  ChannelByIndex (unsigned int index, unsigned int type, void **ppvObj)
  {
    return m_loc[0]->ChannelByIndex (m_loc,index,type,ppvObj);
  }
    CLxResult
  ChannelByIndex (unsigned int index, unsigned int type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ChannelByIndex(m_loc,index,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ConnectionCount (unsigned int *count)
  {
    return m_loc[0]->ConnectionCount (m_loc,count);
  }
    LxResult
  ConnectionByIndex (unsigned int index, unsigned int type, void **ppvObj)
  {
    return m_loc[0]->ConnectionByIndex (m_loc,index,type,ppvObj);
  }
    CLxResult
  ConnectionByIndex (unsigned int index, unsigned int type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ConnectionByIndex(m_loc,index,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  IsRoot (void)
  {
    return m_loc[0]->IsRoot (m_loc);
  }
    LxResult
  RootNode (void **ppvObj)
  {
    return m_loc[0]->RootNode (m_loc,ppvObj);
  }
    CLxResult
  RootNode (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->RootNode(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SubNodeCount (unsigned int *count) const
  {
    return m_loc[0]->SubNodeCount (m_loc,count);
  }
    LxResult
  SubNodeByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->SubNodeByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  SubNodeByIndex (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SubNodeByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Position (double *x, double *y)
  {
    return m_loc[0]->Position (m_loc,x,y);
  }
    LxResult
  SetPosition (double x, double y)
  {
    return m_loc[0]->SetPosition (m_loc,x,y);
  }
    LxResult
  Size (double *width, double *height)
  {
    return m_loc[0]->Size (m_loc,width,height);
  }
    LxResult
  AbsoluteSize (double *width, double *height)
  {
    return m_loc[0]->AbsoluteSize (m_loc,width,height);
  }
    LxResult
  Expanded (void)
  {
    return m_loc[0]->Expanded (m_loc);
  }
};

class CLxImpl_SchemaDest {
  public:
    virtual ~CLxImpl_SchemaDest() {}
    virtual int
      schmd_ViewType (void)
        = 0;
    virtual LxResult
      schmd_Position (LXtVector pos)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schmd_Group (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schmd_Item (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schmd_Node (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schmd_Channel (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schmd_Graph (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schmd_Link (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_SchemaDest_ViewType int schmd_ViewType (void)
#define LXxO_SchemaDest_ViewType LXxD_SchemaDest_ViewType LXx_OVERRIDE
#define LXxC_SchemaDest_ViewType(c) int c::schmd_ViewType (void)
#define LXxD_SchemaDest_Position LxResult schmd_Position (LXtVector pos)
#define LXxO_SchemaDest_Position LXxD_SchemaDest_Position LXx_OVERRIDE
#define LXxC_SchemaDest_Position(c) LxResult c::schmd_Position (LXtVector pos)
#define LXxD_SchemaDest_Group LxResult schmd_Group (void **ppvObj)
#define LXxO_SchemaDest_Group LXxD_SchemaDest_Group LXx_OVERRIDE
#define LXxC_SchemaDest_Group(c) LxResult c::schmd_Group (void **ppvObj)
#define LXxD_SchemaDest_Item LxResult schmd_Item (void **ppvObj)
#define LXxO_SchemaDest_Item LXxD_SchemaDest_Item LXx_OVERRIDE
#define LXxC_SchemaDest_Item(c) LxResult c::schmd_Item (void **ppvObj)
#define LXxD_SchemaDest_Node LxResult schmd_Node (void **ppvObj)
#define LXxO_SchemaDest_Node LXxD_SchemaDest_Node LXx_OVERRIDE
#define LXxC_SchemaDest_Node(c) LxResult c::schmd_Node (void **ppvObj)
#define LXxD_SchemaDest_Channel LxResult schmd_Channel (void **ppvObj)
#define LXxO_SchemaDest_Channel LXxD_SchemaDest_Channel LXx_OVERRIDE
#define LXxC_SchemaDest_Channel(c) LxResult c::schmd_Channel (void **ppvObj)
#define LXxD_SchemaDest_Graph LxResult schmd_Graph (void **ppvObj)
#define LXxO_SchemaDest_Graph LXxD_SchemaDest_Graph LXx_OVERRIDE
#define LXxC_SchemaDest_Graph(c) LxResult c::schmd_Graph (void **ppvObj)
#define LXxD_SchemaDest_Link LxResult schmd_Link (void **ppvObj)
#define LXxO_SchemaDest_Link LXxD_SchemaDest_Link LXx_OVERRIDE
#define LXxC_SchemaDest_Link(c) LxResult c::schmd_Link (void **ppvObj)
template <class T>
class CLxIfc_SchemaDest : public CLxInterface
{
    static int
  ViewType (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SchemaDest, loc);
    return loc->schmd_ViewType ();
  }
    static LxResult
  Position (LXtObjectID wcom, LXtVector pos)
  {
    LXCWxINST (CLxImpl_SchemaDest, loc);
    try {
      return loc->schmd_Position (pos);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Group (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchemaDest, loc);
    try {
      return loc->schmd_Group (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Item (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchemaDest, loc);
    try {
      return loc->schmd_Item (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Node (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchemaDest, loc);
    try {
      return loc->schmd_Node (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Channel (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchemaDest, loc);
    try {
      return loc->schmd_Channel (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Graph (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchemaDest, loc);
    try {
      return loc->schmd_Graph (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Link (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchemaDest, loc);
    try {
      return loc->schmd_Link (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxSchemaDest vt;
public:
  CLxIfc_SchemaDest ()
  {
    vt.ViewType = ViewType;
    vt.Position = Position;
    vt.Group = Group;
    vt.Item = Item;
    vt.Node = Node;
    vt.Channel = Channel;
    vt.Graph = Graph;
    vt.Link = Link;
    vTable = &vt.iunk;
    iid = &lx::guid_SchemaDest;
  }
};
class CLxLoc_SchemaDest : public CLxLocalize<ILxSchemaDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SchemaDest() {_init();}
  CLxLoc_SchemaDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SchemaDest(const CLxLoc_SchemaDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SchemaDest;}
    int
  ViewType (void)
  {
    return m_loc[0]->ViewType (m_loc);
  }
    LxResult
  Position (LXtVector pos)
  {
    return m_loc[0]->Position (m_loc,pos);
  }
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
    LxResult
  Node (void **ppvObj)
  {
    return m_loc[0]->Node (m_loc,ppvObj);
  }
    CLxResult
  Node (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Node(m_loc,&o_obj);
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
    LxResult
  Graph (void **ppvObj)
  {
    return m_loc[0]->Graph (m_loc,ppvObj);
  }
    CLxResult
  Graph (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Graph(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Link (void **ppvObj)
  {
    return m_loc[0]->Link (m_loc,ppvObj);
  }
    CLxResult
  Link (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Link(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_SchematicGroup : public CLxLocalize<ILxSchematicGroupID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SchematicGroup() {_init();}
  CLxLoc_SchematicGroup(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SchematicGroup(const CLxLoc_SchematicGroup &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SchematicGroup;}
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
  IsWorkspace (void)
  {
    return m_loc[0]->IsWorkspace (m_loc);
  }
    LxResult
  AddItem (ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->AddItem (m_loc,(ILxUnknownID)item,ppvObj);
  }
    CLxResult
  AddItem (ILxUnknownID item, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AddItem(m_loc,(ILxUnknownID)item,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void
  RemoveItem (ILxUnknownID item)
  {
    m_loc[0]->RemoveItem (m_loc,(ILxUnknownID)item);
  }
    LxResult
  NodeCount (unsigned int *count)
  {
    return m_loc[0]->NodeCount (m_loc,count);
  }
    LxResult
  NodeByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->NodeByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  NodeByIndex (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->NodeByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  InputNode (void **ppvObj)
  {
    return m_loc[0]->InputNode (m_loc,ppvObj);
  }
    CLxResult
  InputNode (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->InputNode(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  OutputNode (void **ppvObj)
  {
    return m_loc[0]->OutputNode (m_loc,ppvObj);
  }
    CLxResult
  OutputNode (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->OutputNode(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_SchematicConnection1 {
  public:
    virtual ~CLxImpl_SchematicConnection1() {}
    virtual LxResult
      schm_ItemFlags (ILxUnknownID item, unsigned *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_GraphName (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Count (ILxUnknownID item, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
    virtual int
      schm_BaseFlags (void)
        { return 0; }
    virtual LxResult
      schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
        { return LXe_NOTIMPL; }
    virtual int
      schm_ItemFlagsValid (void)
        { return 1; }
};
#define LXxD_SchematicConnection1_ItemFlags LxResult schm_ItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxO_SchematicConnection1_ItemFlags LXxD_SchematicConnection1_ItemFlags LXx_OVERRIDE
#define LXxC_SchematicConnection1_ItemFlags(c) LxResult c::schm_ItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxD_SchematicConnection1_AllowConnect LxResult schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
#define LXxO_SchematicConnection1_AllowConnect LXxD_SchematicConnection1_AllowConnect LXx_OVERRIDE
#define LXxC_SchematicConnection1_AllowConnect(c) LxResult c::schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
#define LXxD_SchematicConnection1_GraphName LxResult schm_GraphName (const char **name)
#define LXxO_SchematicConnection1_GraphName LXxD_SchematicConnection1_GraphName LXx_OVERRIDE
#define LXxC_SchematicConnection1_GraphName(c) LxResult c::schm_GraphName (const char **name)
#define LXxD_SchematicConnection1_Count LxResult schm_Count (ILxUnknownID item, unsigned *count)
#define LXxO_SchematicConnection1_Count LXxD_SchematicConnection1_Count LXx_OVERRIDE
#define LXxC_SchematicConnection1_Count(c) LxResult c::schm_Count (ILxUnknownID item, unsigned *count)
#define LXxD_SchematicConnection1_ByIndex LxResult schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
#define LXxO_SchematicConnection1_ByIndex LXxD_SchematicConnection1_ByIndex LXx_OVERRIDE
#define LXxC_SchematicConnection1_ByIndex(c) LxResult c::schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
#define LXxD_SchematicConnection1_Connect LxResult schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection1_Connect LXxD_SchematicConnection1_Connect LXx_OVERRIDE
#define LXxC_SchematicConnection1_Connect(c) LxResult c::schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
#define LXxD_SchematicConnection1_Disconnect LxResult schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
#define LXxO_SchematicConnection1_Disconnect LXxD_SchematicConnection1_Disconnect LXx_OVERRIDE
#define LXxC_SchematicConnection1_Disconnect(c) LxResult c::schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
#define LXxD_SchematicConnection1_BaseFlags int schm_BaseFlags (void)
#define LXxO_SchematicConnection1_BaseFlags LXxD_SchematicConnection1_BaseFlags LXx_OVERRIDE
#define LXxC_SchematicConnection1_BaseFlags(c) int c::schm_BaseFlags (void)
#define LXxD_SchematicConnection1_PerItemFlags LxResult schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxO_SchematicConnection1_PerItemFlags LXxD_SchematicConnection1_PerItemFlags LXx_OVERRIDE
#define LXxC_SchematicConnection1_PerItemFlags(c) LxResult c::schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxD_SchematicConnection1_ItemFlagsValid int schm_ItemFlagsValid (void)
#define LXxO_SchematicConnection1_ItemFlagsValid LXxD_SchematicConnection1_ItemFlagsValid LXx_OVERRIDE
#define LXxC_SchematicConnection1_ItemFlagsValid(c) int c::schm_ItemFlagsValid (void)
template <class T>
class CLxIfc_SchematicConnection1 : public CLxInterface
{
    static LxResult
  ItemFlags (LXtObjectID wcom, LXtObjectID item, unsigned *flags)
  {
    LXCWxINST (CLxImpl_SchematicConnection1, loc);
    try {
      return loc->schm_ItemFlags ((ILxUnknownID)item,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AllowConnect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_SchematicConnection1, loc);
    try {
      return loc->schm_AllowConnect ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GraphName (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_SchematicConnection1, loc);
    try {
      return loc->schm_GraphName (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Count (LXtObjectID wcom, LXtObjectID item, unsigned *count)
  {
    LXCWxINST (CLxImpl_SchematicConnection1, loc);
    try {
      return loc->schm_Count ((ILxUnknownID)item,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ByIndex (LXtObjectID wcom, LXtObjectID item, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchematicConnection1, loc);
    try {
      return loc->schm_ByIndex ((ILxUnknownID)item,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Connect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection1, loc);
    try {
      return loc->schm_Connect ((ILxUnknownID)from,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Disconnect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_SchematicConnection1, loc);
    try {
      return loc->schm_Disconnect ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
    static int
  BaseFlags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SchematicConnection1, loc);
    return loc->schm_BaseFlags ();
  }
    static LxResult
  PerItemFlags (LXtObjectID wcom, LXtObjectID item, unsigned *flags)
  {
    LXCWxINST (CLxImpl_SchematicConnection1, loc);
    try {
      return loc->schm_PerItemFlags ((ILxUnknownID)item,flags);
    } catch (LxResult rc) { return rc; }
  }
    static int
  ItemFlagsValid (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SchematicConnection1, loc);
    return loc->schm_ItemFlagsValid ();
  }
  ILxSchematicConnection1 vt;
public:
  CLxIfc_SchematicConnection1 ()
  {
    vt.ItemFlags = ItemFlags;
    vt.AllowConnect = AllowConnect;
    vt.GraphName = GraphName;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vt.Connect = Connect;
    vt.Disconnect = Disconnect;
    vt.BaseFlags = BaseFlags;
    vt.PerItemFlags = PerItemFlags;
    vt.ItemFlagsValid = ItemFlagsValid;
    vTable = &vt.iunk;
    iid = &lx::guid_SchematicConnection1;
  }
};
class CLxLoc_SchematicConnection1 : public CLxLocalize<ILxSchematicConnection1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SchematicConnection1() {_init();}
  CLxLoc_SchematicConnection1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SchematicConnection1(const CLxLoc_SchematicConnection1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SchematicConnection1;}
    LxResult
  ItemFlags (ILxUnknownID item, unsigned *flags)
  {
    return m_loc[0]->ItemFlags (m_loc,(ILxUnknownID)item,flags);
  }
    LxResult
  AllowConnect (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->AllowConnect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    LxResult
  GraphName (const char **name)
  {
    return m_loc[0]->GraphName (m_loc,name);
  }
    LxResult
  Count (ILxUnknownID item, unsigned *count)
  {
    return m_loc[0]->Count (m_loc,(ILxUnknownID)item,count);
  }
    LxResult
  ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,(ILxUnknownID)item,index,ppvObj);
  }
    CLxResult
  ByIndex (ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ByIndex(m_loc,(ILxUnknownID)item,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->Connect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to,toIndex);
  }
    LxResult
  Disconnect (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->Disconnect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    int
  BaseFlags (void)
  {
    return m_loc[0]->BaseFlags (m_loc);
  }
    LxResult
  PerItemFlags (ILxUnknownID item, unsigned *flags)
  {
    return m_loc[0]->PerItemFlags (m_loc,(ILxUnknownID)item,flags);
  }
    int
  ItemFlagsValid (void)
  {
    return m_loc[0]->ItemFlagsValid (m_loc);
  }
};

class CLxLoc_SchematicNodeChannel : public CLxLocalize<ILxSchematicNodeChannelID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SchematicNodeChannel() {_init();}
  CLxLoc_SchematicNodeChannel(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SchematicNodeChannel(const CLxLoc_SchematicNodeChannel &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SchematicNodeChannel;}
    LxResult
  Flags (unsigned int *flags) const
  {
    return m_loc[0]->Flags (m_loc,flags);
  }
    LxResult
  Node (void **ppvObj)
  {
    return m_loc[0]->Node (m_loc,ppvObj);
  }
    CLxResult
  Node (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Node(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Index (unsigned int *index) const
  {
    return m_loc[0]->Index (m_loc,index);
  }
    LxResult
  Count (unsigned int *count) const
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  ByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  ByIndex (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Position (double *x, double *y)
  {
    return m_loc[0]->Position (m_loc,x,y);
  }
};

class CLxLoc_SchematicNodeConnection : public CLxLocalize<ILxSchematicNodeConnectionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SchematicNodeConnection() {_init();}
  CLxLoc_SchematicNodeConnection(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SchematicNodeConnection(const CLxLoc_SchematicNodeConnection &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SchematicNodeConnection;}
    LxResult
  Flags (unsigned int *flags) const
  {
    return m_loc[0]->Flags (m_loc,flags);
  }
    LxResult
  Node (void **ppvObj)
  {
    return m_loc[0]->Node (m_loc,ppvObj);
  }
    CLxResult
  Node (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Node(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Count (unsigned int *count) const
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  ByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  ByIndex (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Position (unsigned int index, double *x, double *y)
  {
    return m_loc[0]->Position (m_loc,index,x,y);
  }
};

class CLxImpl_SchematicConnection2 {
  public:
    virtual ~CLxImpl_SchematicConnection2() {}
    virtual LxResult
      schm_ItemFlags (ILxUnknownID item, unsigned *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_AllowConnectType (ILxUnknownID to, unsigned int type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_GraphName (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Count (ILxUnknownID item, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
    virtual int
      schm_BaseFlags (void)
        { return 0; }
    virtual LxResult
      schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
        { return LXe_NOTIMPL; }
    virtual int
      schm_ItemFlagsValid (void)
        { return 1; }
};
#define LXxD_SchematicConnection2_ItemFlags LxResult schm_ItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxO_SchematicConnection2_ItemFlags LXxD_SchematicConnection2_ItemFlags LXx_OVERRIDE
#define LXxC_SchematicConnection2_ItemFlags(c) LxResult c::schm_ItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxD_SchematicConnection2_AllowConnect LxResult schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
#define LXxO_SchematicConnection2_AllowConnect LXxD_SchematicConnection2_AllowConnect LXx_OVERRIDE
#define LXxC_SchematicConnection2_AllowConnect(c) LxResult c::schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
#define LXxD_SchematicConnection2_AllowConnectType LxResult schm_AllowConnectType (ILxUnknownID to, unsigned int type)
#define LXxO_SchematicConnection2_AllowConnectType LXxD_SchematicConnection2_AllowConnectType LXx_OVERRIDE
#define LXxC_SchematicConnection2_AllowConnectType(c) LxResult c::schm_AllowConnectType (ILxUnknownID to, unsigned int type)
#define LXxD_SchematicConnection2_GraphName LxResult schm_GraphName (const char **name)
#define LXxO_SchematicConnection2_GraphName LXxD_SchematicConnection2_GraphName LXx_OVERRIDE
#define LXxC_SchematicConnection2_GraphName(c) LxResult c::schm_GraphName (const char **name)
#define LXxD_SchematicConnection2_Count LxResult schm_Count (ILxUnknownID item, unsigned *count)
#define LXxO_SchematicConnection2_Count LXxD_SchematicConnection2_Count LXx_OVERRIDE
#define LXxC_SchematicConnection2_Count(c) LxResult c::schm_Count (ILxUnknownID item, unsigned *count)
#define LXxD_SchematicConnection2_ByIndex LxResult schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
#define LXxO_SchematicConnection2_ByIndex LXxD_SchematicConnection2_ByIndex LXx_OVERRIDE
#define LXxC_SchematicConnection2_ByIndex(c) LxResult c::schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
#define LXxD_SchematicConnection2_Connect LxResult schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection2_Connect LXxD_SchematicConnection2_Connect LXx_OVERRIDE
#define LXxC_SchematicConnection2_Connect(c) LxResult c::schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
#define LXxD_SchematicConnection2_Disconnect LxResult schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
#define LXxO_SchematicConnection2_Disconnect LXxD_SchematicConnection2_Disconnect LXx_OVERRIDE
#define LXxC_SchematicConnection2_Disconnect(c) LxResult c::schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
#define LXxD_SchematicConnection2_BaseFlags int schm_BaseFlags (void)
#define LXxO_SchematicConnection2_BaseFlags LXxD_SchematicConnection2_BaseFlags LXx_OVERRIDE
#define LXxC_SchematicConnection2_BaseFlags(c) int c::schm_BaseFlags (void)
#define LXxD_SchematicConnection2_PerItemFlags LxResult schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxO_SchematicConnection2_PerItemFlags LXxD_SchematicConnection2_PerItemFlags LXx_OVERRIDE
#define LXxC_SchematicConnection2_PerItemFlags(c) LxResult c::schm_PerItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxD_SchematicConnection2_ItemFlagsValid int schm_ItemFlagsValid (void)
#define LXxO_SchematicConnection2_ItemFlagsValid LXxD_SchematicConnection2_ItemFlagsValid LXx_OVERRIDE
#define LXxC_SchematicConnection2_ItemFlagsValid(c) int c::schm_ItemFlagsValid (void)
template <class T>
class CLxIfc_SchematicConnection2 : public CLxInterface
{
    static LxResult
  ItemFlags (LXtObjectID wcom, LXtObjectID item, unsigned *flags)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    try {
      return loc->schm_ItemFlags ((ILxUnknownID)item,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AllowConnect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    try {
      return loc->schm_AllowConnect ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AllowConnectType (LXtObjectID wcom, LXtObjectID to, unsigned int type)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    try {
      return loc->schm_AllowConnectType ((ILxUnknownID)to,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GraphName (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    try {
      return loc->schm_GraphName (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Count (LXtObjectID wcom, LXtObjectID item, unsigned *count)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    try {
      return loc->schm_Count ((ILxUnknownID)item,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ByIndex (LXtObjectID wcom, LXtObjectID item, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    try {
      return loc->schm_ByIndex ((ILxUnknownID)item,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Connect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    try {
      return loc->schm_Connect ((ILxUnknownID)from,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Disconnect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    try {
      return loc->schm_Disconnect ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
    static int
  BaseFlags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    return loc->schm_BaseFlags ();
  }
    static LxResult
  PerItemFlags (LXtObjectID wcom, LXtObjectID item, unsigned *flags)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    try {
      return loc->schm_PerItemFlags ((ILxUnknownID)item,flags);
    } catch (LxResult rc) { return rc; }
  }
    static int
  ItemFlagsValid (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SchematicConnection2, loc);
    return loc->schm_ItemFlagsValid ();
  }
  ILxSchematicConnection2 vt;
public:
  CLxIfc_SchematicConnection2 ()
  {
    vt.ItemFlags = ItemFlags;
    vt.AllowConnect = AllowConnect;
    vt.AllowConnectType = AllowConnectType;
    vt.GraphName = GraphName;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vt.Connect = Connect;
    vt.Disconnect = Disconnect;
    vt.BaseFlags = BaseFlags;
    vt.PerItemFlags = PerItemFlags;
    vt.ItemFlagsValid = ItemFlagsValid;
    vTable = &vt.iunk;
    iid = &lx::guid_SchematicConnection2;
  }
};
class CLxLoc_SchematicConnection2 : public CLxLocalize<ILxSchematicConnection2ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SchematicConnection2() {_init();}
  CLxLoc_SchematicConnection2(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SchematicConnection2(const CLxLoc_SchematicConnection2 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SchematicConnection2;}
    LxResult
  ItemFlags (ILxUnknownID item, unsigned *flags)
  {
    return m_loc[0]->ItemFlags (m_loc,(ILxUnknownID)item,flags);
  }
    LxResult
  AllowConnect (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->AllowConnect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    LxResult
  AllowConnectType (ILxUnknownID to, unsigned int type)
  {
    return m_loc[0]->AllowConnectType (m_loc,(ILxUnknownID)to,type);
  }
    LxResult
  GraphName (const char **name)
  {
    return m_loc[0]->GraphName (m_loc,name);
  }
    LxResult
  Count (ILxUnknownID item, unsigned *count)
  {
    return m_loc[0]->Count (m_loc,(ILxUnknownID)item,count);
  }
    LxResult
  ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,(ILxUnknownID)item,index,ppvObj);
  }
    CLxResult
  ByIndex (ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ByIndex(m_loc,(ILxUnknownID)item,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->Connect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to,toIndex);
  }
    LxResult
  Disconnect (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->Disconnect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    int
  BaseFlags (void)
  {
    return m_loc[0]->BaseFlags (m_loc);
  }
    LxResult
  PerItemFlags (ILxUnknownID item, unsigned *flags)
  {
    return m_loc[0]->PerItemFlags (m_loc,(ILxUnknownID)item,flags);
  }
    int
  ItemFlagsValid (void)
  {
    return m_loc[0]->ItemFlagsValid (m_loc);
  }
};

#endif

