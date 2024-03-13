/*
 * C++ wrapper for lxchannelui.h
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
#ifndef LXW_CHANNELUI_HPP
#define LXW_CHANNELUI_HPP

#include <lxchannelui.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ChannelUIService = {0x3C3A2D98,0x7EF1,0x43F4,0x84,0x5C,0x39,0xEF,0x2D,0x8F,0x6D,0x52};
    static const LXtGUID guid_ChannelUI = {0xd04810aa,0xd88a,0x44ef,0x92,0xc2,0x79,0x73,0x74,0xb4,0x23,0x65};
    static const LXtGUID guid_ChannelUI1 = {0xBF1BFE3B,0xF0F5,0x490b,0x89,0x61,0x72,0x17,0x95,0xDA,0x57,0xB4};
};

class CLxLoc_ChannelUIService : public CLxLocalizedService
{
public:
  ILxChannelUIServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_ChannelUIService() {_init();set();}
 ~CLxLoc_ChannelUIService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxChannelUIServiceID>(lx::GetGlobal(&lx::guid_ChannelUIService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    CLxResult
  ScriptQuery (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ScriptQuery(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemTypeName (LXtItemType typeID, unsigned useSuper, const char **name)
  {
    return m_loc[0]->ItemTypeName (m_loc,typeID,useSuper,name);
  }
    LxResult
  ItemTypeDesc (LXtItemType typeID, unsigned useSuper, const char **name)
  {
    return m_loc[0]->ItemTypeDesc (m_loc,typeID,useSuper,name);
  }
    LxResult
  ItemTypeIconText (LXtItemType typeID, unsigned useSuper, char *buf, unsigned len)
  {
    return m_loc[0]->ItemTypeIconText (m_loc,typeID,useSuper,buf,len);
  }
    LxResult
  ItemTypeIconText (LXtItemType typeID, unsigned useSuper, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ItemTypeIconText (m_loc,typeID,useSuper,buf,len);
    LXWx_SBUF2
  }
    LxResult
  MeshMapUserName (const char *name, unsigned addIcon, char *buf, unsigned len)
  {
    return m_loc[0]->MeshMapUserName (m_loc,name,addIcon,buf,len);
  }
    LxResult
  MeshMapUserName (const char *name, unsigned addIcon, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->MeshMapUserName (m_loc,name,addIcon,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ChannelUserName (ILxUnknownID item, unsigned channel, char *buf, unsigned len)
  {
    return m_loc[0]->ChannelUserName (m_loc,(ILxUnknownID)item,channel,buf,len);
  }
    LxResult
  ChannelUserName (ILxUnknownID item, unsigned channel, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ChannelUserName (m_loc,(ILxUnknownID)item,channel,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ChannelDescription (ILxUnknownID item, unsigned channel, const char **desc)
  {
    return m_loc[0]->ChannelDescription (m_loc,(ILxUnknownID)item,channel,desc);
  }
    LxResult
  ChannelToolTip (ILxUnknownID item, unsigned channel, const char **tip)
  {
    return m_loc[0]->ChannelToolTip (m_loc,(ILxUnknownID)item,channel,tip);
  }
};

class CLxImpl_ChannelUI {
  public:
    virtual ~CLxImpl_ChannelUI() {}
    virtual LxResult
      cui_Enabled (const char *channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID chanRead)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_DependencyCount (const char *channelName, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_DependencyByIndex (const char *channelName, unsigned index, LXtItemType *depItemType, const char **depChannelName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_DependencyByIndexName (const char *channelName, unsigned index, const char **depItemTypeName, const char **depChannelName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_ItemEnabled (ILxUnknownID msg, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_ItemIcon (ILxUnknownID item, const char **icon)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_UIHints (const char *channelName, ILxUnknownID hints)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_UIValueHints (const char *channelName, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_Cookie (const char *channelName, const char *requestedFor, const char **cookie)
        { return LXe_NOTIMPL; }
};
#define LXxD_ChannelUI_Enabled LxResult cui_Enabled (const char *channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID chanRead)
#define LXxO_ChannelUI_Enabled LXxD_ChannelUI_Enabled LXx_OVERRIDE
#define LXxC_ChannelUI_Enabled(c) LxResult c::cui_Enabled (const char *channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID chanRead)
#define LXxD_ChannelUI_DependencyCount LxResult cui_DependencyCount (const char *channelName, unsigned *count)
#define LXxO_ChannelUI_DependencyCount LXxD_ChannelUI_DependencyCount LXx_OVERRIDE
#define LXxC_ChannelUI_DependencyCount(c) LxResult c::cui_DependencyCount (const char *channelName, unsigned *count)
#define LXxD_ChannelUI_DependencyByIndex LxResult cui_DependencyByIndex (const char *channelName, unsigned index, LXtItemType *depItemType, const char **depChannelName)
#define LXxO_ChannelUI_DependencyByIndex LXxD_ChannelUI_DependencyByIndex LXx_OVERRIDE
#define LXxC_ChannelUI_DependencyByIndex(c) LxResult c::cui_DependencyByIndex (const char *channelName, unsigned index, LXtItemType *depItemType, const char **depChannelName)
#define LXxD_ChannelUI_DependencyByIndexName LxResult cui_DependencyByIndexName (const char *channelName, unsigned index, const char **depItemTypeName, const char **depChannelName)
#define LXxO_ChannelUI_DependencyByIndexName LXxD_ChannelUI_DependencyByIndexName LXx_OVERRIDE
#define LXxC_ChannelUI_DependencyByIndexName(c) LxResult c::cui_DependencyByIndexName (const char *channelName, unsigned index, const char **depItemTypeName, const char **depChannelName)
#define LXxD_ChannelUI_ItemEnabled LxResult cui_ItemEnabled (ILxUnknownID msg, ILxUnknownID item)
#define LXxO_ChannelUI_ItemEnabled LXxD_ChannelUI_ItemEnabled LXx_OVERRIDE
#define LXxC_ChannelUI_ItemEnabled(c) LxResult c::cui_ItemEnabled (ILxUnknownID msg, ILxUnknownID item)
#define LXxD_ChannelUI_ItemIcon LxResult cui_ItemIcon (ILxUnknownID item, const char **icon)
#define LXxO_ChannelUI_ItemIcon LXxD_ChannelUI_ItemIcon LXx_OVERRIDE
#define LXxC_ChannelUI_ItemIcon(c) LxResult c::cui_ItemIcon (ILxUnknownID item, const char **icon)
#define LXxD_ChannelUI_UIHints LxResult cui_UIHints (const char *channelName, ILxUnknownID hints)
#define LXxO_ChannelUI_UIHints LXxD_ChannelUI_UIHints LXx_OVERRIDE
#define LXxC_ChannelUI_UIHints(c) LxResult c::cui_UIHints (const char *channelName, ILxUnknownID hints)
#define LXxD_ChannelUI_UIValueHints LxResult cui_UIValueHints (const char *channelName, void **ppvObj)
#define LXxO_ChannelUI_UIValueHints LXxD_ChannelUI_UIValueHints LXx_OVERRIDE
#define LXxC_ChannelUI_UIValueHints(c) LxResult c::cui_UIValueHints (const char *channelName, void **ppvObj)
#define LXxD_ChannelUI_Cookie LxResult cui_Cookie (const char *channelName, const char *requestedFor, const char **cookie)
#define LXxO_ChannelUI_Cookie LXxD_ChannelUI_Cookie LXx_OVERRIDE
#define LXxC_ChannelUI_Cookie(c) LxResult c::cui_Cookie (const char *channelName, const char *requestedFor, const char **cookie)
template <class T>
class CLxIfc_ChannelUI : public CLxInterface
{
    static LxResult
  Enabled (LXtObjectID wcom, const char *channelName, LXtObjectID msg, LXtObjectID item, LXtObjectID chanRead)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_Enabled (channelName,(ILxUnknownID)msg,(ILxUnknownID)item,(ILxUnknownID)chanRead);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DependencyCount (LXtObjectID wcom, const char *channelName, unsigned *count)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_DependencyCount (channelName,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DependencyByIndex (LXtObjectID wcom, const char *channelName, unsigned index, LXtItemType *depItemType, const char **depChannelName)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_DependencyByIndex (channelName,index,depItemType,depChannelName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DependencyByIndexName (LXtObjectID wcom, const char *channelName, unsigned index, const char **depItemTypeName, const char **depChannelName)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_DependencyByIndexName (channelName,index,depItemTypeName,depChannelName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemEnabled (LXtObjectID wcom, LXtObjectID msg, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_ItemEnabled ((ILxUnknownID)msg,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemIcon (LXtObjectID wcom, LXtObjectID item, const char **icon)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_ItemIcon ((ILxUnknownID)item,icon);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UIHints (LXtObjectID wcom, const char *channelName, LXtObjectID hints)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_UIHints (channelName,(ILxUnknownID)hints);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UIValueHints (LXtObjectID wcom, const char *channelName, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_UIValueHints (channelName,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Cookie (LXtObjectID wcom, const char *channelName, const char *requestedFor, const char **cookie)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_Cookie (channelName,requestedFor,cookie);
    } catch (LxResult rc) { return rc; }
  }
  ILxChannelUI vt;
public:
  CLxIfc_ChannelUI ()
  {
    vt.Enabled = Enabled;
    vt.DependencyCount = DependencyCount;
    vt.DependencyByIndex = DependencyByIndex;
    vt.DependencyByIndexName = DependencyByIndexName;
    vt.ItemEnabled = ItemEnabled;
    vt.ItemIcon = ItemIcon;
    vt.UIHints = UIHints;
    vt.UIValueHints = UIValueHints;
    vt.Cookie = Cookie;
    vTable = &vt.iunk;
    iid = &lx::guid_ChannelUI;
  }
};
class CLxLoc_ChannelUI : public CLxLocalize<ILxChannelUIID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelUI() {_init();}
  CLxLoc_ChannelUI(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelUI(const CLxLoc_ChannelUI &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelUI;}
    LxResult
  Enabled (const char *channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID chanRead)
  {
    return m_loc[0]->Enabled (m_loc,channelName,(ILxUnknownID)msg,(ILxUnknownID)item,(ILxUnknownID)chanRead);
  }
    LxResult
  DependencyCount (const char *channelName, unsigned *count)
  {
    return m_loc[0]->DependencyCount (m_loc,channelName,count);
  }
    LxResult
  DependencyByIndex (const char *channelName, unsigned index, LXtItemType *depItemType, const char **depChannelName)
  {
    return m_loc[0]->DependencyByIndex (m_loc,channelName,index,depItemType,depChannelName);
  }
    LxResult
  DependencyByIndexName (const char *channelName, unsigned index, const char **depItemTypeName, const char **depChannelName)
  {
    return m_loc[0]->DependencyByIndexName (m_loc,channelName,index,depItemTypeName,depChannelName);
  }
    LxResult
  ItemEnabled (ILxUnknownID msg, ILxUnknownID item)
  {
    return m_loc[0]->ItemEnabled (m_loc,(ILxUnknownID)msg,(ILxUnknownID)item);
  }
    LxResult
  ItemIcon (ILxUnknownID item, const char **icon)
  {
    return m_loc[0]->ItemIcon (m_loc,(ILxUnknownID)item,icon);
  }
    LxResult
  UIHints (const char *channelName, ILxUnknownID hints)
  {
    return m_loc[0]->UIHints (m_loc,channelName,(ILxUnknownID)hints);
  }
    LxResult
  UIValueHints (const char *channelName, void **ppvObj)
  {
    return m_loc[0]->UIValueHints (m_loc,channelName,ppvObj);
  }
    CLxResult
  UIValueHints (const char *channelName, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->UIValueHints(m_loc,channelName,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Cookie (const char *channelName, const char *requestedFor, const char **cookie)
  {
    return m_loc[0]->Cookie (m_loc,channelName,requestedFor,cookie);
  }
};


#endif

