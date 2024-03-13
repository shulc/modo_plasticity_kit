/*
 * C++ wrapper for lxinputmap.h
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
#ifndef LXW_INPUTMAP_HPP
#define LXW_INPUTMAP_HPP

#include <lxinputmap.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_RegionHandler = {0x05811721,0x08E9,0x49e0,0xAD,0xFE,0x92,0xC6,0xD4,0xA3,0xE5,0xE6};
    static const LXtGUID guid_InputMapClientTest = {0x7653F32B,0x8FDA,0x40ce,0x8E,0xDE,0x0D,0x55,0x23,0xBC,0x76,0x09};
    static const LXtGUID guid_InputContextClientTest = {0xFB08280B,0x5F3E,0x4852,0xB3,0x1F,0x8A,0x87,0xA6,0xE7,0x42,0x7F};
    static const LXtGUID guid_InputDeviceInstance = {0xfd2edfc9,0xc3db,0x4409,0xa4,0x78,0xfc,0xe1,0x51,0x1b,0x9f,0xf0};
    static const LXtGUID guid_InputMapService = {0xDEDDBC50,0xF747,0x43a4,0x83,0x8D,0xD7,0x06,0xED,0x68,0x84,0x16};
    static const LXtGUID guid_InputDevices = {0x0a70601b,0x750d,0x4325,0xb3,0x8a,0x86,0xf3,0x19,0x93,0x3e,0x17};
};




class CLxImpl_InputDeviceInstance {
  public:
    virtual ~CLxImpl_InputDeviceInstance() {}
    virtual LxResult
      indevinst_Name (const char *name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      indevinst_IsConnected (void)
        { return LXe_NOTIMPL; }
    virtual int
      indevinst_ButtonCount (void)
        { return 0; }
    virtual LxResult
      indevinst_ButtonName (int index, char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      indevinst_ButtonUserName (int index, char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      indevinst_ButtonIsDown (int index)
        { return LXe_NOTIMPL; }
    virtual int
      indevinst_AnalogCount (void)
        { return 0; }
    virtual LxResult
      indevinst_AnalogName (int index, char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      indevinst_AnalogUserName (int index, char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      indevinst_AnalogMetrics (int index, int *isAbsolute, int *isDirectional)
        { return LXe_NOTIMPL; }
    virtual LxResult
      indevinst_AnalogValue (int index, double *value)
        { return LXe_NOTIMPL; }
};
#define LXxD_InputDeviceInstance_Name LxResult indevinst_Name (const char *name)
#define LXxO_InputDeviceInstance_Name LXxD_InputDeviceInstance_Name LXx_OVERRIDE
#define LXxC_InputDeviceInstance_Name(c) LxResult c::indevinst_Name (const char *name)
#define LXxD_InputDeviceInstance_IsConnected LxResult indevinst_IsConnected (void)
#define LXxO_InputDeviceInstance_IsConnected LXxD_InputDeviceInstance_IsConnected LXx_OVERRIDE
#define LXxC_InputDeviceInstance_IsConnected(c) LxResult c::indevinst_IsConnected (void)
#define LXxD_InputDeviceInstance_ButtonCount int indevinst_ButtonCount (void)
#define LXxO_InputDeviceInstance_ButtonCount LXxD_InputDeviceInstance_ButtonCount LXx_OVERRIDE
#define LXxC_InputDeviceInstance_ButtonCount(c) int c::indevinst_ButtonCount (void)
#define LXxD_InputDeviceInstance_ButtonName LxResult indevinst_ButtonName (int index, char *buf, int len)
#define LXxO_InputDeviceInstance_ButtonName LXxD_InputDeviceInstance_ButtonName LXx_OVERRIDE
#define LXxC_InputDeviceInstance_ButtonName(c) LxResult c::indevinst_ButtonName (int index, char *buf, int len)
#define LXxD_InputDeviceInstance_ButtonUserName LxResult indevinst_ButtonUserName (int index, char *buf, int len)
#define LXxO_InputDeviceInstance_ButtonUserName LXxD_InputDeviceInstance_ButtonUserName LXx_OVERRIDE
#define LXxC_InputDeviceInstance_ButtonUserName(c) LxResult c::indevinst_ButtonUserName (int index, char *buf, int len)
#define LXxD_InputDeviceInstance_ButtonIsDown LxResult indevinst_ButtonIsDown (int index)
#define LXxO_InputDeviceInstance_ButtonIsDown LXxD_InputDeviceInstance_ButtonIsDown LXx_OVERRIDE
#define LXxC_InputDeviceInstance_ButtonIsDown(c) LxResult c::indevinst_ButtonIsDown (int index)
#define LXxD_InputDeviceInstance_AnalogCount int indevinst_AnalogCount (void)
#define LXxO_InputDeviceInstance_AnalogCount LXxD_InputDeviceInstance_AnalogCount LXx_OVERRIDE
#define LXxC_InputDeviceInstance_AnalogCount(c) int c::indevinst_AnalogCount (void)
#define LXxD_InputDeviceInstance_AnalogName LxResult indevinst_AnalogName (int index, char *buf, int len)
#define LXxO_InputDeviceInstance_AnalogName LXxD_InputDeviceInstance_AnalogName LXx_OVERRIDE
#define LXxC_InputDeviceInstance_AnalogName(c) LxResult c::indevinst_AnalogName (int index, char *buf, int len)
#define LXxD_InputDeviceInstance_AnalogUserName LxResult indevinst_AnalogUserName (int index, char *buf, int len)
#define LXxO_InputDeviceInstance_AnalogUserName LXxD_InputDeviceInstance_AnalogUserName LXx_OVERRIDE
#define LXxC_InputDeviceInstance_AnalogUserName(c) LxResult c::indevinst_AnalogUserName (int index, char *buf, int len)
#define LXxD_InputDeviceInstance_AnalogMetrics LxResult indevinst_AnalogMetrics (int index, int *isAbsolute, int *isDirectional)
#define LXxO_InputDeviceInstance_AnalogMetrics LXxD_InputDeviceInstance_AnalogMetrics LXx_OVERRIDE
#define LXxC_InputDeviceInstance_AnalogMetrics(c) LxResult c::indevinst_AnalogMetrics (int index, int *isAbsolute, int *isDirectional)
#define LXxD_InputDeviceInstance_AnalogValue LxResult indevinst_AnalogValue (int index, double *value)
#define LXxO_InputDeviceInstance_AnalogValue LXxD_InputDeviceInstance_AnalogValue LXx_OVERRIDE
#define LXxC_InputDeviceInstance_AnalogValue(c) LxResult c::indevinst_AnalogValue (int index, double *value)
template <class T>
class CLxIfc_InputDeviceInstance : public CLxInterface
{
    static LxResult
  Name (LXtObjectID wcom, const char *name)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    try {
      return loc->indevinst_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsConnected (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    try {
      return loc->indevinst_IsConnected ();
    } catch (LxResult rc) { return rc; }
  }
    static int
  ButtonCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    return loc->indevinst_ButtonCount ();
  }
    static LxResult
  ButtonName (LXtObjectID wcom, int index, char *buf, int len)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    try {
      return loc->indevinst_ButtonName (index,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ButtonUserName (LXtObjectID wcom, int index, char *buf, int len)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    try {
      return loc->indevinst_ButtonUserName (index,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ButtonIsDown (LXtObjectID wcom, int index)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    try {
      return loc->indevinst_ButtonIsDown (index);
    } catch (LxResult rc) { return rc; }
  }
    static int
  AnalogCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    return loc->indevinst_AnalogCount ();
  }
    static LxResult
  AnalogName (LXtObjectID wcom, int index, char *buf, int len)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    try {
      return loc->indevinst_AnalogName (index,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AnalogUserName (LXtObjectID wcom, int index, char *buf, int len)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    try {
      return loc->indevinst_AnalogUserName (index,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AnalogMetrics (LXtObjectID wcom, int index, int *isAbsolute, int *isDirectional)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    try {
      return loc->indevinst_AnalogMetrics (index,isAbsolute,isDirectional);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AnalogValue (LXtObjectID wcom, int index, double *value)
  {
    LXCWxINST (CLxImpl_InputDeviceInstance, loc);
    try {
      return loc->indevinst_AnalogValue (index,value);
    } catch (LxResult rc) { return rc; }
  }
  ILxInputDeviceInstance vt;
public:
  CLxIfc_InputDeviceInstance ()
  {
    vt.Name = Name;
    vt.IsConnected = IsConnected;
    vt.ButtonCount = ButtonCount;
    vt.ButtonName = ButtonName;
    vt.ButtonUserName = ButtonUserName;
    vt.ButtonIsDown = ButtonIsDown;
    vt.AnalogCount = AnalogCount;
    vt.AnalogName = AnalogName;
    vt.AnalogUserName = AnalogUserName;
    vt.AnalogMetrics = AnalogMetrics;
    vt.AnalogValue = AnalogValue;
    vTable = &vt.iunk;
    iid = &lx::guid_InputDeviceInstance;
  }
};
class CLxLoc_InputDeviceInstance : public CLxLocalize<ILxInputDeviceInstanceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_InputDeviceInstance() {_init();}
  CLxLoc_InputDeviceInstance(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_InputDeviceInstance(const CLxLoc_InputDeviceInstance &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_InputDeviceInstance;}
    LxResult
  Name (const char *name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  IsConnected (void)
  {
    return m_loc[0]->IsConnected (m_loc);
  }
    int
  ButtonCount (void)
  {
    return m_loc[0]->ButtonCount (m_loc);
  }
    LxResult
  ButtonName (int index, char *buf, int len)
  {
    return m_loc[0]->ButtonName (m_loc,index,buf,len);
  }
    LxResult
  ButtonUserName (int index, char *buf, int len)
  {
    return m_loc[0]->ButtonUserName (m_loc,index,buf,len);
  }
    LxResult
  ButtonIsDown (int index)
  {
    return m_loc[0]->ButtonIsDown (m_loc,index);
  }
    int
  AnalogCount (void)
  {
    return m_loc[0]->AnalogCount (m_loc);
  }
    LxResult
  AnalogName (int index, char *buf, int len)
  {
    return m_loc[0]->AnalogName (m_loc,index,buf,len);
  }
    LxResult
  AnalogUserName (int index, char *buf, int len)
  {
    return m_loc[0]->AnalogUserName (m_loc,index,buf,len);
  }
    LxResult
  AnalogMetrics (int index, int *isAbsolute, int *isDirectional)
  {
    return m_loc[0]->AnalogMetrics (m_loc,index,isAbsolute,isDirectional);
  }
    LxResult
  AnalogValue (int index, double *value)
  {
    return m_loc[0]->AnalogValue (m_loc,index,value);
  }
};

class CLxLoc_InputMapService : public CLxLocalizedService
{
public:
  ILxInputMapServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_InputMapService() {_init();set();}
 ~CLxLoc_InputMapService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxInputMapServiceID>(lx::GetGlobal(&lx::guid_InputMapService));}
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
  Define (LXtInputContextID context, const char *name, LXtInputMapID *im)
  {
    return m_loc[0]->Define (m_loc,context,name,im);
  }
    LxResult
  DefineGroup (const char *group)
  {
    return m_loc[0]->DefineGroup (m_loc,group);
  }
    LxResult
  DefineStandardEvent (int event, int flags)
  {
    return m_loc[0]->DefineStandardEvent (m_loc,event,flags);
  }
    LxResult
  DefineCustomEvent (int event, const char *name, int flags)
  {
    return m_loc[0]->DefineCustomEvent (m_loc,event,name,flags);
  }
    LxResult
  DefineClientTests (ILxUnknownID tester)
  {
    return m_loc[0]->DefineClientTests (m_loc,(ILxUnknownID)tester);
  }
    LxResult
  DefineRegion (int event, const char *name)
  {
    return m_loc[0]->DefineRegion (m_loc,event,name);
  }
    LxResult
  Count (LXtInputContextID context, int *count)
  {
    return m_loc[0]->Count (m_loc,context,count);
  }
    LxResult
  ByIndex (LXtInputContextID context, int index, LXtInputMapID *im)
  {
    return m_loc[0]->ByIndex (m_loc,context,index,im);
  }
    LxResult
  Lookup (LXtInputContextID context, const char *name, LXtInputMapID *im)
  {
    return m_loc[0]->Lookup (m_loc,context,name,im);
  }
    LxResult
  GroupCount (LXtInputMapGroupID group, int *count)
  {
    return m_loc[0]->GroupCount (m_loc,group,count);
  }
    LxResult
  GroupByIndex (LXtInputMapGroupID group, int index, LXtInputMapGroupID *subgroup)
  {
    return m_loc[0]->GroupByIndex (m_loc,group,index,subgroup);
  }
    LxResult
  GroupIMCount (LXtInputMapGroupID group, int *count)
  {
    return m_loc[0]->GroupIMCount (m_loc,group,count);
  }
    LxResult
  GroupIMByIndex (LXtInputMapGroupID group, int index, LXtInputMapID *im)
  {
    return m_loc[0]->GroupIMByIndex (m_loc,group,index,im);
  }
    LxResult
  GroupGetName (LXtInputMapGroupID group, const char *name)
  {
    return m_loc[0]->GroupGetName (m_loc,group,name);
  }
    LxResult
  GroupGetUserName (LXtInputMapGroupID group, const char *username)
  {
    return m_loc[0]->GroupGetUserName (m_loc,group,username);
  }
    LxResult
  Name (LXtInputMapID im, const char **name)
  {
    return m_loc[0]->Name (m_loc,im,name);
  }
    LxResult
  Group (LXtInputMapID im, const char **groupPath, LXtInputMapGroupID *group)
  {
    return m_loc[0]->Group (m_loc,im,groupPath,group);
  }
    LxResult
  Data (LXtInputMapID im, void **data)
  {
    return m_loc[0]->Data (m_loc,im,data);
  }
    LxResult
  EventCount (LXtInputMapID im, int *count)
  {
    return m_loc[0]->EventCount (m_loc,im,count);
  }
    LxResult
  EventName (LXtInputMapID im, int index, const char **name)
  {
    return m_loc[0]->EventName (m_loc,im,index,name);
  }
    LxResult
  EventType (LXtInputMapID im, int index, int *type)
  {
    return m_loc[0]->EventType (m_loc,im,index,type);
  }
    LxResult
  EventFlags (LXtInputMapID im, int index, int *flags)
  {
    return m_loc[0]->EventFlags (m_loc,im,index,flags);
  }
    LxResult
  CanEventsCoexist (LXtInputMapID im, int event1, int event2)
  {
    return m_loc[0]->CanEventsCoexist (m_loc,im,event1,event2);
  }
    LxResult
  StandardEventName (int event, const char **name)
  {
    return m_loc[0]->StandardEventName (m_loc,event,name);
  }
    LxResult
  StandardEventFlags (int event, int *flags)
  {
    return m_loc[0]->StandardEventFlags (m_loc,event,flags);
  }
    LxResult
  RegionCount (LXtInputMapID im, int *count)
  {
    return m_loc[0]->RegionCount (m_loc,im,count);
  }
    LxResult
  RegionName (LXtInputMapID im, int i, const char **name)
  {
    return m_loc[0]->RegionName (m_loc,im,i,name);
  }
    LxResult
  RegionType (LXtInputMapID im, int i, int *type)
  {
    return m_loc[0]->RegionType (m_loc,im,i,type);
  }
    LxResult
  FindEvent (LXtInputMapID im, const char *name, int type, int *index)
  {
    return m_loc[0]->FindEvent (m_loc,im,name,type,index);
  }
    LxResult
  FindRegion (LXtInputMapID im, const char *name, int type, int *index)
  {
    return m_loc[0]->FindRegion (m_loc,im,name,type,index);
  }
    LxResult
  UserName (LXtInputMapID im, const char **username)
  {
    return m_loc[0]->UserName (m_loc,im,username);
  }
    LxResult
  Desc (LXtInputMapID im, const char **desc)
  {
    return m_loc[0]->Desc (m_loc,im,desc);
  }
    LxResult
  HelpURL (LXtInputMapID im, const char **helpURL)
  {
    return m_loc[0]->HelpURL (m_loc,im,helpURL);
  }
    LxResult
  EventUserName (LXtInputMapID im, const char *stateName, const char *name, int index, const char **username)
  {
    return m_loc[0]->EventUserName (m_loc,im,stateName,name,index,username);
  }
    LxResult
  EventDesc (LXtInputMapID im, const char *stateName, const char *name, int index, const char **desc)
  {
    return m_loc[0]->EventDesc (m_loc,im,stateName,name,index,desc);
  }
    LxResult
  EventHelpURL (LXtInputMapID im, const char *stateName, const char *name, int index, const char **helpURL)
  {
    return m_loc[0]->EventHelpURL (m_loc,im,stateName,name,index,helpURL);
  }
    LxResult
  RegionUserName (LXtInputMapID im, const char *stateName, const char *name, int index, const char **username)
  {
    return m_loc[0]->RegionUserName (m_loc,im,stateName,name,index,username);
  }
    LxResult
  RegionDesc (LXtInputMapID im, const char *stateName, const char *name, int index, const char **desc)
  {
    return m_loc[0]->RegionDesc (m_loc,im,stateName,name,index,desc);
  }
    LxResult
  RegionHelpURL (LXtInputMapID im, const char *stateName, const char *name, int index, const char **helpURL)
  {
    return m_loc[0]->RegionHelpURL (m_loc,im,stateName,name,index,helpURL);
  }
    LxResult
  GroupUserName (const char *path, int depth, const char **username)
  {
    return m_loc[0]->GroupUserName (m_loc,path,depth,username);
  }
    LxResult
  StateUserName (const char *state, const char **name)
  {
    return m_loc[0]->StateUserName (m_loc,state,name);
  }
    LxResult
  StateCatUserName (const char *cat, const char **name)
  {
    return m_loc[0]->StateCatUserName (m_loc,cat,name);
  }
    LxResult
  StateLookup (LXtInputMapID im, const char *name, int add, LXtInputStateID *state)
  {
    return m_loc[0]->StateLookup (m_loc,im,name,add,state);
  }
    LxResult
  StateCount (LXtInputMapID im, int *count)
  {
    return m_loc[0]->StateCount (m_loc,im,count);
  }
    LxResult
  StateByIndex (LXtInputMapID im, int i, LXtInputStateID *state)
  {
    return m_loc[0]->StateByIndex (m_loc,im,i,state);
  }
    LxResult
  StateName (LXtInputStateID state, const char **name)
  {
    return m_loc[0]->StateName (m_loc,state,name);
  }
    LxResult
  StateInputMap (LXtInputStateID state, LXtInputMapID *im)
  {
    return m_loc[0]->StateInputMap (m_loc,state,im);
  }
    LxResult
  TestState (LXtInputMapID im, const char *state, int *priority)
  {
    return m_loc[0]->TestState (m_loc,im,state,priority);
  }
    LxResult
  StateUIListCatCount (int *count)
  {
    return m_loc[0]->StateUIListCatCount (m_loc,count);
  }
    LxResult
  StateUIListCatName (int index, const char **name)
  {
    return m_loc[0]->StateUIListCatName (m_loc,index,name);
  }
    LxResult
  StateUIListCount (const char *cat, int *count)
  {
    return m_loc[0]->StateUIListCount (m_loc,cat,count);
  }
    LxResult
  StateUIListName (const char *cat, int index, const char **name)
  {
    return m_loc[0]->StateUIListName (m_loc,cat,index,name);
  }
    LxResult
  StateUIFallbacksCount (const char *stateName, int *count)
  {
    return m_loc[0]->StateUIFallbacksCount (m_loc,stateName,count);
  }
    LxResult
  StateUIFallbacksName (const char *stateName, int index, const char **name)
  {
    return m_loc[0]->StateUIFallbacksName (m_loc,stateName,index,name);
  }
    LxResult
  StateUITestEvent (LXtInputMapID im, const char *stateName, int eventID)
  {
    return m_loc[0]->StateUITestEvent (m_loc,im,stateName,eventID);
  }
    LxResult
  StateUITestRegion (LXtInputMapID im, const char *stateName, int regionID)
  {
    return m_loc[0]->StateUITestRegion (m_loc,im,stateName,regionID);
  }
    LxResult
  RefreshStates (int flags)
  {
    return m_loc[0]->RefreshStates (m_loc,flags);
  }
    LxResult
  DefineContext (const char *name, int type, ILxUnknownID clientTest, LXtInputContextID *context)
  {
    return m_loc[0]->DefineContext (m_loc,name,type,(ILxUnknownID)clientTest,context);
  }
    LxResult
  ContextCount (int *count)
  {
    return m_loc[0]->ContextCount (m_loc,count);
  }
    LxResult
  ContextByIndex (int index, LXtInputContextID *context)
  {
    return m_loc[0]->ContextByIndex (m_loc,index,context);
  }
    LxResult
  ContextLookup (const char *name, LXtInputContextID *context)
  {
    return m_loc[0]->ContextLookup (m_loc,name,context);
  }
    LxResult
  TestContext (LXtInputContextID context, int *priority)
  {
    return m_loc[0]->TestContext (m_loc,context,priority);
  }
    LxResult
  ContextName (LXtInputContextID context, const char **name)
  {
    return m_loc[0]->ContextName (m_loc,context,name);
  }
    LxResult
  ContextType (LXtInputContextID context, int *type)
  {
    return m_loc[0]->ContextType (m_loc,context,type);
  }
    LxResult
  ContextUserName (LXtInputContextID context, const char **name)
  {
    return m_loc[0]->ContextUserName (m_loc,context,name);
  }
    LxResult
  ContextDesc (LXtInputContextID context, const char **desc)
  {
    return m_loc[0]->ContextDesc (m_loc,context,desc);
  }
    LxResult
  ContextHelpURL (LXtInputContextID context, const char **helpURL)
  {
    return m_loc[0]->ContextHelpURL (m_loc,context,helpURL);
  }
    LxResult
  Context (LXtInputMapID im, LXtInputContextID *context)
  {
    return m_loc[0]->Context (m_loc,im,context);
  }
    LxResult
  RefreshContexts (void)
  {
    return m_loc[0]->RefreshContexts (m_loc);
  }
    LxResult
  EventMappingCount (LXtInputStateID state, const char *eventName, int eventIndex, int eventType, int *count)
  {
    return m_loc[0]->EventMappingCount (m_loc,state,eventName,eventIndex,eventType,count);
  }
    LxResult
  EventMappingByIndex (LXtInputStateID state, const char *eventName, int eventIndex, int eventType, int index, LXtDualKeyCombo *combo)
  {
    return m_loc[0]->EventMappingByIndex (m_loc,state,eventName,eventIndex,eventType,index,combo);
  }
    LxResult
  RegionMappingCount (LXtInputStateID state, const char *regionName, int regionIndex, int regionType, int *count)
  {
    return m_loc[0]->RegionMappingCount (m_loc,state,regionName,regionIndex,regionType,count);
  }
    LxResult
  RegionMappingByIndex (LXtInputStateID state, const char *regionName, int regionIndex, int regionType, int index, LXtDualKeyCombo *combo, const char **command)
  {
    return m_loc[0]->RegionMappingByIndex (m_loc,state,regionName,regionIndex,regionType,index,combo,command);
  }
    LxResult
  RegionMappingFind (LXtInputStateID state, const char *regionName, int regionIndex, int regionType, const LXtDualKeyCombo combo, int *index)
  {
    return m_loc[0]->RegionMappingFind (m_loc,state,regionName,regionIndex,regionType,combo,index);
  }
    LxResult
  ComboMapsTo (LXtInputStateID state, LXtDualKeyCombo combo, int eventFlags, int index, int *type)
  {
    return m_loc[0]->ComboMapsTo (m_loc,state,combo,eventFlags,index,type);
  }
    LxResult
  ComboToString (LXtDualKeyCombo combo, char *buffer, int bufLen)
  {
    return m_loc[0]->ComboToString (m_loc,combo,buffer,bufLen);
  }
    LxResult
  ComboEncode (LXtDualKeyCombo combo, char *buffer, int bufLen)
  {
    return m_loc[0]->ComboEncode (m_loc,combo,buffer,bufLen);
  }
    LxResult
  ComboDecode (const char *string, LXtDualKeyCombo *combo, int mode)
  {
    return m_loc[0]->ComboDecode (m_loc,string,combo,mode);
  }
    LxResult
  ComboCompare (LXtDualKeyCombo combo1, LXtDualKeyCombo combo2)
  {
    return m_loc[0]->ComboCompare (m_loc,combo1,combo2);
  }
    LxResult
  ComboEncodePart (LXtDualKey part, char *buffer, int bufLen)
  {
    return m_loc[0]->ComboEncodePart (m_loc,part,buffer,bufLen);
  }
    LxResult
  ComboDecodePart (const char *string, LXtDualKey *part)
  {
    return m_loc[0]->ComboDecodePart (m_loc,string,part);
  }
    LxResult
  GetMouseMap (LXtInputMapID im, void **ppvObj)
  {
    return m_loc[0]->GetMouseMap (m_loc,im,ppvObj);
  }
    CLxResult
  GetMouseMap (LXtInputMapID im, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetMouseMap(m_loc,im,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AttachRegions (LXtInputMapID im, void *pane, int mouserPriority, ILxUnknownID handler, void **mouser)
  {
    return m_loc[0]->AttachRegions (m_loc,im,pane,mouserPriority,(ILxUnknownID)handler,mouser);
  }
    LxResult
  UpdateDeviceList (void)
  {
    return m_loc[0]->UpdateDeviceList (m_loc);
  }
    LxResult
  UpdateDeviceInstance (const char *name)
  {
    return m_loc[0]->UpdateDeviceInstance (m_loc,name);
  }
};

class CLxImpl_InputDevices {
  public:
    virtual ~CLxImpl_InputDevices() {}
    virtual int
      indev_DeviceCount (void)
        { return 0; }
    virtual LxResult
      indev_DeviceNameByIndex (int index, const char *name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      indev_DeviceInstanceByIndex (int index, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_InputDevices_DeviceCount int indev_DeviceCount (void)
#define LXxO_InputDevices_DeviceCount LXxD_InputDevices_DeviceCount LXx_OVERRIDE
#define LXxC_InputDevices_DeviceCount(c) int c::indev_DeviceCount (void)
#define LXxD_InputDevices_DeviceNameByIndex LxResult indev_DeviceNameByIndex (int index, const char *name)
#define LXxO_InputDevices_DeviceNameByIndex LXxD_InputDevices_DeviceNameByIndex LXx_OVERRIDE
#define LXxC_InputDevices_DeviceNameByIndex(c) LxResult c::indev_DeviceNameByIndex (int index, const char *name)
#define LXxD_InputDevices_DeviceInstanceByIndex LxResult indev_DeviceInstanceByIndex (int index, void **ppvObj)
#define LXxO_InputDevices_DeviceInstanceByIndex LXxD_InputDevices_DeviceInstanceByIndex LXx_OVERRIDE
#define LXxC_InputDevices_DeviceInstanceByIndex(c) LxResult c::indev_DeviceInstanceByIndex (int index, void **ppvObj)
template <class T>
class CLxIfc_InputDevices : public CLxInterface
{
    static int
  DeviceCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_InputDevices, loc);
    return loc->indev_DeviceCount ();
  }
    static LxResult
  DeviceNameByIndex (LXtObjectID wcom, int index, const char *name)
  {
    LXCWxINST (CLxImpl_InputDevices, loc);
    try {
      return loc->indev_DeviceNameByIndex (index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DeviceInstanceByIndex (LXtObjectID wcom, int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_InputDevices, loc);
    try {
      return loc->indev_DeviceInstanceByIndex (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxInputDevices vt;
public:
  CLxIfc_InputDevices ()
  {
    vt.DeviceCount = DeviceCount;
    vt.DeviceNameByIndex = DeviceNameByIndex;
    vt.DeviceInstanceByIndex = DeviceInstanceByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_InputDevices;
  }
};
class CLxLoc_InputDevices : public CLxLocalize<ILxInputDevicesID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_InputDevices() {_init();}
  CLxLoc_InputDevices(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_InputDevices(const CLxLoc_InputDevices &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_InputDevices;}
    int
  DeviceCount (void)
  {
    return m_loc[0]->DeviceCount (m_loc);
  }
    LxResult
  DeviceNameByIndex (int index, const char *name)
  {
    return m_loc[0]->DeviceNameByIndex (m_loc,index,name);
  }
    LxResult
  DeviceInstanceByIndex (int index, void **ppvObj)
  {
    return m_loc[0]->DeviceInstanceByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  DeviceInstanceByIndex (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->DeviceInstanceByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

