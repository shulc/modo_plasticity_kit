/*
 * C++ wrapper for lxscripts.h
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
#ifndef LXW_SCRIPTS_HPP
#define LXW_SCRIPTS_HPP

#include <lxscripts.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ScriptSysService = {0x5046C663,0x7990,0x44d5,0x84,0xCB,0xA8,0x59,0x10,0x1B,0x1C,0x59};
    static const LXtGUID guid_ScriptManager = {0x3699E7C5,0x44B8,0x4e07,0xB8,0xCA,0xE2,0x68,0x99,0xCD,0x7B,0x3B};
    static const LXtGUID guid_PlatformService = {0xB9596D64,0x8CB3,0x4943,0x84,0x15,0x7E,0xDF,0x52,0x7A,0xE5,0x13};
    static const LXtGUID guid_UserValue = {0xd7fb1eb0,0x47fe,0x4dc2,0xa6,0x4f,0xc8,0xa3,0x5a,0x86,0xc5,0x1e};
    static const LXtGUID guid_ScriptLineEvent = {0xDABF6619,0xA4B5,0x4919,0x83,0x89,0x8C,0x54,0xB3,0x94,0x22,0xE4};
    static const LXtGUID guid_LineExecution = {0x16947735,0x3797,0x444C,0xA9,0x07,0xDA,0xDD,0x81,0x65,0xF4,0xFB};
    static const LXtGUID guid_TextScriptInterpreter = {0xD612FFCE,0x4B94,0x4823,0xA0,0xA7,0xCC,0x7C,0xA2,0xDD,0xC3,0xD6};
    static const LXtGUID guid_UserValueListener = {0x13a85a48,0x06aa,0x4a75,0x9e,0x73,0x06,0x6e,0xe3,0xcb,0x76,0x1f};
    static const LXtGUID guid_AppActiveListener = {0x7c35c2c0,0x8116,0x43f7,0x82,0x77,0xdd,0x52,0x1d,0x1b,0xd6,0xa8};
    static const LXtGUID guid_LineInterpreter = {0x8F7DF2BE,0x69A2,0x4E1C,0xA4,0xE9,0xCB,0x3B,0xC3,0xD5,0x34,0xD5};
    static const LXtGUID guid_Kit = {0x6A961CA0,0x6174,0x4E65,0xBB,0x13,0xAC,0x19,0x9D,0xD1,0x04,0x71};
    static const LXtGUID guid_SessionListener = {0xb5cb3afe,0x3f0c,0x4498,0xb5,0x30,0x17,0x26,0x81,0x1b,0x14,0x01};
    static const LXtGUID guid_Script = {0x33C03F3F,0xA692,0x4bf4,0x8A,0xB4,0xC5,0xA9,0x5C,0xA7,0x93,0x0C};
};

class CLxLoc_ScriptSysService : public CLxLocalizedService
{
public:
  ILxScriptSysServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_ScriptSysService() {_init();set();}
 ~CLxLoc_ScriptSysService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxScriptSysServiceID>(lx::GetGlobal(&lx::guid_ScriptSysService));}
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
  Count (unsigned int *count)
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
  NameByIndex (unsigned int index, const char **name)
  {
    return m_loc[0]->NameByIndex (m_loc,index,name);
  }
    LxResult
  Lookup (const char *name, void **ppvObj)
  {
    return m_loc[0]->Lookup (m_loc,name,ppvObj);
  }
    CLxResult
  Lookup (const char *name, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Lookup(m_loc,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  UserName (ILxUnknownID manager, const char **name)
  {
    return m_loc[0]->UserName (m_loc,(ILxUnknownID)manager,name);
  }
    LxResult
  Desc (ILxUnknownID manager, const char **name)
  {
    return m_loc[0]->Desc (m_loc,(ILxUnknownID)manager,name);
  }
    LxResult
  UserValueCount (int *count)
  {
    return m_loc[0]->UserValueCount (m_loc,count);
  }
    LxResult
  UserValueByIndex (int index, void **ppvObj)
  {
    return m_loc[0]->UserValueByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  UserValueByIndex (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->UserValueByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  UserValueLookup (const char *name, void **ppvObj)
  {
    return m_loc[0]->UserValueLookup (m_loc,name,ppvObj);
  }
    CLxResult
  UserValueLookup (const char *name, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->UserValueLookup(m_loc,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ResolveAlias (const char *alias, const char **path)
  {
    return m_loc[0]->ResolveAlias (m_loc,alias,path);
  }
    LxResult
  LookupScript (const char *hash, int write, int tryAsUsername, void **service, void **script)
  {
    return m_loc[0]->LookupScript (m_loc,hash,write,tryAsUsername,service,script);
  }
    LxResult
  KitCount (int visible, int *count)
  {
    return m_loc[0]->KitCount (m_loc,visible,count);
  }
    LxResult
  KitByIndex (int index, int visible, void **ppvObj)
  {
    return m_loc[0]->KitByIndex (m_loc,index,visible,ppvObj);
  }
    CLxResult
  KitByIndex (int index, int visible, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->KitByIndex(m_loc,index,visible,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  KitLookup (const char *name, void **ppvObj)
  {
    return m_loc[0]->KitLookup (m_loc,name,ppvObj);
  }
    CLxResult
  KitLookup (const char *name, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->KitLookup(m_loc,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_ScriptManager {
  public:
    virtual ~CLxImpl_ScriptManager() {}
    virtual LxResult
      scman_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scman_Flags (int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scman_Count (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scman_ByIndex (unsigned int index, void **ppvObj, int write)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scman_Lookup (const char *hash, void **ppvObj, int write, int tryAsUserName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scman_ReadWrite (const char *hash, int index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scman_New (const char *name, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scman_Remove (ILxUnknownID script)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scman_Validate (ILxUnknownID script, ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scman_Run (ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg)
        { return LXe_NOTIMPL; }
};
#define LXxD_ScriptManager_Name LxResult scman_Name (const char **name)
#define LXxO_ScriptManager_Name LXxD_ScriptManager_Name LXx_OVERRIDE
#define LXxC_ScriptManager_Name(c) LxResult c::scman_Name (const char **name)
#define LXxD_ScriptManager_Flags LxResult scman_Flags (int *flags)
#define LXxO_ScriptManager_Flags LXxD_ScriptManager_Flags LXx_OVERRIDE
#define LXxC_ScriptManager_Flags(c) LxResult c::scman_Flags (int *flags)
#define LXxD_ScriptManager_Count LxResult scman_Count (unsigned int *count)
#define LXxO_ScriptManager_Count LXxD_ScriptManager_Count LXx_OVERRIDE
#define LXxC_ScriptManager_Count(c) LxResult c::scman_Count (unsigned int *count)
#define LXxD_ScriptManager_ByIndex LxResult scman_ByIndex (unsigned int index, void **ppvObj, int write)
#define LXxO_ScriptManager_ByIndex LXxD_ScriptManager_ByIndex LXx_OVERRIDE
#define LXxC_ScriptManager_ByIndex(c) LxResult c::scman_ByIndex (unsigned int index, void **ppvObj, int write)
#define LXxD_ScriptManager_Lookup LxResult scman_Lookup (const char *hash, void **ppvObj, int write, int tryAsUserName)
#define LXxO_ScriptManager_Lookup LXxD_ScriptManager_Lookup LXx_OVERRIDE
#define LXxC_ScriptManager_Lookup(c) LxResult c::scman_Lookup (const char *hash, void **ppvObj, int write, int tryAsUserName)
#define LXxD_ScriptManager_ReadWrite LxResult scman_ReadWrite (const char *hash, int index)
#define LXxO_ScriptManager_ReadWrite LXxD_ScriptManager_ReadWrite LXx_OVERRIDE
#define LXxC_ScriptManager_ReadWrite(c) LxResult c::scman_ReadWrite (const char *hash, int index)
#define LXxD_ScriptManager_New LxResult scman_New (const char *name, void **ppvObj)
#define LXxO_ScriptManager_New LXxD_ScriptManager_New LXx_OVERRIDE
#define LXxC_ScriptManager_New(c) LxResult c::scman_New (const char *name, void **ppvObj)
#define LXxD_ScriptManager_Remove LxResult scman_Remove (ILxUnknownID script)
#define LXxO_ScriptManager_Remove LXxD_ScriptManager_Remove LXx_OVERRIDE
#define LXxC_ScriptManager_Remove(c) LxResult c::scman_Remove (ILxUnknownID script)
#define LXxD_ScriptManager_Validate LxResult scman_Validate (ILxUnknownID script, ILxUnknownID msg)
#define LXxO_ScriptManager_Validate LXxD_ScriptManager_Validate LXx_OVERRIDE
#define LXxC_ScriptManager_Validate(c) LxResult c::scman_Validate (ILxUnknownID script, ILxUnknownID msg)
#define LXxD_ScriptManager_Run LxResult scman_Run (ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg)
#define LXxO_ScriptManager_Run LXxD_ScriptManager_Run LXx_OVERRIDE
#define LXxC_ScriptManager_Run(c) LxResult c::scman_Run (ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg)
template <class T>
class CLxIfc_ScriptManager : public CLxInterface
{
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_ScriptManager, loc);
    try {
      return loc->scman_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Flags (LXtObjectID wcom, int *flags)
  {
    LXCWxINST (CLxImpl_ScriptManager, loc);
    try {
      return loc->scman_Flags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Count (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_ScriptManager, loc);
    try {
      return loc->scman_Count (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ByIndex (LXtObjectID wcom, unsigned int index, void **ppvObj, int write)
  {
    LXCWxINST (CLxImpl_ScriptManager, loc);
    try {
      return loc->scman_ByIndex (index,ppvObj,write);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Lookup (LXtObjectID wcom, const char *hash, void **ppvObj, int write, int tryAsUserName)
  {
    LXCWxINST (CLxImpl_ScriptManager, loc);
    try {
      return loc->scman_Lookup (hash,ppvObj,write,tryAsUserName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReadWrite (LXtObjectID wcom, const char *hash, int index)
  {
    LXCWxINST (CLxImpl_ScriptManager, loc);
    try {
      return loc->scman_ReadWrite (hash,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  New (LXtObjectID wcom, const char *name, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ScriptManager, loc);
    try {
      return loc->scman_New (name,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Remove (LXtObjectID wcom, LXtObjectID script)
  {
    LXCWxINST (CLxImpl_ScriptManager, loc);
    try {
      return loc->scman_Remove ((ILxUnknownID)script);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Validate (LXtObjectID wcom, LXtObjectID script, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_ScriptManager, loc);
    try {
      return loc->scman_Validate ((ILxUnknownID)script,(ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Run (LXtObjectID wcom, LXtObjectID script, int execFlags, const char *args, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_ScriptManager, loc);
    try {
      return loc->scman_Run ((ILxUnknownID)script,execFlags,args,(ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
  ILxScriptManager vt;
public:
  CLxIfc_ScriptManager ()
  {
    vt.Name = Name;
    vt.Flags = Flags;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vt.Lookup = Lookup;
    vt.ReadWrite = ReadWrite;
    vt.New = New;
    vt.Remove = Remove;
    vt.Validate = Validate;
    vt.Run = Run;
    vTable = &vt.iunk;
    iid = &lx::guid_ScriptManager;
  }
};
class CLxLoc_ScriptManager : public CLxLocalize<ILxScriptManagerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ScriptManager() {_init();}
  CLxLoc_ScriptManager(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ScriptManager(const CLxLoc_ScriptManager &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ScriptManager;}
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  Flags (int *flags)
  {
    return m_loc[0]->Flags (m_loc,flags);
  }
    LxResult
  Count (unsigned int *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  ByIndex (unsigned int index, void **ppvObj, int write)
  {
    return m_loc[0]->ByIndex (m_loc,index,ppvObj,write);
  }
    CLxResult
  ByIndex (unsigned int index, CLxLocalizedObject &o_dest, int write)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ByIndex(m_loc,index,&o_obj,write);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Lookup (const char *hash, void **ppvObj, int write, int tryAsUserName)
  {
    return m_loc[0]->Lookup (m_loc,hash,ppvObj,write,tryAsUserName);
  }
    CLxResult
  Lookup (const char *hash, CLxLocalizedObject &o_dest, int write, int tryAsUserName)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Lookup(m_loc,hash,&o_obj,write,tryAsUserName);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ReadWrite (const char *hash, int index)
  {
    return m_loc[0]->ReadWrite (m_loc,hash,index);
  }
    LxResult
  New (const char *name, void **ppvObj)
  {
    return m_loc[0]->New (m_loc,name,ppvObj);
  }
    CLxResult
  New (const char *name, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->New(m_loc,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Remove (ILxUnknownID script)
  {
    return m_loc[0]->Remove (m_loc,(ILxUnknownID)script);
  }
    LxResult
  Validate (ILxUnknownID script, ILxUnknownID msg)
  {
    return m_loc[0]->Validate (m_loc,(ILxUnknownID)script,(ILxUnknownID)msg);
  }
    LxResult
  Run (ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg)
  {
    return m_loc[0]->Run (m_loc,(ILxUnknownID)script,execFlags,args,(ILxUnknownID)msg);
  }
};

class CLxLoc_PlatformService : public CLxLocalizedService
{
public:
  ILxPlatformServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_PlatformService() {_init();set();}
 ~CLxLoc_PlatformService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxPlatformServiceID>(lx::GetGlobal(&lx::guid_PlatformService));}
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
  LicensedTo (const char **licensee)
  {
    return m_loc[0]->LicensedTo (m_loc,licensee);
  }
    LxResult
  ExpiresIn (int *daysLeft)
  {
    return m_loc[0]->ExpiresIn (m_loc,daysLeft);
  }
    LxResult
  SerialNumber (const char **serial)
  {
    return m_loc[0]->SerialNumber (m_loc,serial);
  }
    LxResult
  NumLicenses (int *licenses)
  {
    return m_loc[0]->NumLicenses (m_loc,licenses);
  }
    LxResult
  AppName (const char **name)
  {
    return m_loc[0]->AppName (m_loc,name);
  }
    LxResult
  AppVersion (int *version)
  {
    return m_loc[0]->AppVersion (m_loc,version);
  }
    LxResult
  AppBuild (int *build)
  {
    return m_loc[0]->AppBuild (m_loc,build);
  }
    LxResult
  IsHeadless (void)
  {
    return m_loc[0]->IsHeadless (m_loc);
  }
    LxResult
  OSType (int *type)
  {
    return m_loc[0]->OSType (m_loc,type);
  }
    LxResult
  OSName (const char **name)
  {
    return m_loc[0]->OSName (m_loc,name);
  }
    LxResult
  OSVersion (const char **version)
  {
    return m_loc[0]->OSVersion (m_loc,version);
  }
    LxResult
  PathCount (int *count)
  {
    return m_loc[0]->PathCount (m_loc,count);
  }
    LxResult
  PathByIndex (int index, const char **path)
  {
    return m_loc[0]->PathByIndex (m_loc,index,path);
  }
    LxResult
  PathNameByIndex (int index, const char **name)
  {
    return m_loc[0]->PathNameByIndex (m_loc,index,name);
  }
    LxResult
  ImportPathCount (int *index)
  {
    return m_loc[0]->ImportPathCount (m_loc,index);
  }
    LxResult
  ImportPathByIndex (int index, const char **path)
  {
    return m_loc[0]->ImportPathByIndex (m_loc,index,path);
  }
    LxResult
  IsApp64Bit (void)
  {
    return m_loc[0]->IsApp64Bit (m_loc);
  }
    LxResult
  DoWhenUserIsIdle (ILxUnknownID visitor, int flags)
  {
    return m_loc[0]->DoWhenUserIsIdle (m_loc,(ILxUnknownID)visitor,flags);
  }
    LxResult
  CancelDoWhenUserIsIdle (ILxUnknownID visitor, int flags)
  {
    return m_loc[0]->CancelDoWhenUserIsIdle (m_loc,(ILxUnknownID)visitor,flags);
  }
    LxResult
  IsUserIdle (void)
  {
    return m_loc[0]->IsUserIdle (m_loc);
  }
    LxResult
  IsAppActive (void)
  {
    return m_loc[0]->IsAppActive (m_loc);
  }
    LxResult
  SessionStage (int *stage)
  {
    return m_loc[0]->SessionStage (m_loc,stage);
  }
    LxResult
  AppUsername (const char **name)
  {
    return m_loc[0]->AppUsername (m_loc,name);
  }
    LxResult
  TimerStart (ILxUnknownID visitor, int milliseconds, int idleFlags)
  {
    return m_loc[0]->TimerStart (m_loc,(ILxUnknownID)visitor,milliseconds,idleFlags);
  }
    LxResult
  TimerCancel (ILxUnknownID visitor, int idleFlags)
  {
    return m_loc[0]->TimerCancel (m_loc,(ILxUnknownID)visitor,idleFlags);
  }
    LxResult
  IsSafeMode (void)
  {
    return m_loc[0]->IsSafeMode (m_loc);
  }
    LxResult
  AppVersionMinor (int *version)
  {
    return m_loc[0]->AppVersionMinor (m_loc,version);
  }
    LxResult
  AppVersionSP (int *version)
  {
    return m_loc[0]->AppVersionSP (m_loc,version);
  }
    LxResult
  AppVersionMajor (int *version)
  {
    return m_loc[0]->AppVersionMajor (m_loc,version);
  }
};

class CLxLoc_UserValue : public CLxLocalize<ILxUserValueID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UserValue() {_init();}
  CLxLoc_UserValue(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UserValue(const CLxLoc_UserValue &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UserValue;}
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  UserName (const char **username)
  {
    return m_loc[0]->UserName (m_loc,username);
  }
    LxResult
  Type (int *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  TypeName (const char **tname)
  {
    return m_loc[0]->TypeName (m_loc,tname);
  }
    LxResult
  IsTransient (int *isTransient)
  {
    return m_loc[0]->IsTransient (m_loc,isTransient);
  }
    LxResult
  GetInt (int *val)
  {
    return m_loc[0]->GetInt (m_loc,val);
  }
    LxResult
  GetFlt (double *val)
  {
    return m_loc[0]->GetFlt (m_loc,val);
  }
    LxResult
  GetString (char *buf, unsigned len)
  {
    return m_loc[0]->GetString (m_loc,buf,len);
  }
    LxResult
  GetString (std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->GetString (m_loc,buf,len);
    LXWx_SBUF2
  }
    LxResult
  Lifespan (int *life)
  {
    return m_loc[0]->Lifespan (m_loc,life);
  }
    LxResult
  FloatRange (int *hasMin, double *min, int *hasMax, double *max)
  {
    return m_loc[0]->FloatRange (m_loc,hasMin,min,hasMax,max);
  }
    LxResult
  IntRange (int *hasMin, int *min, int *hasMax, int *max)
  {
    return m_loc[0]->IntRange (m_loc,hasMin,min,hasMax,max);
  }
    LxResult
  List (const char **list)
  {
    return m_loc[0]->List (m_loc,list);
  }
    LxResult
  ListNames (const char **listNames)
  {
    return m_loc[0]->ListNames (m_loc,listNames);
  }
    LxResult
  ArgType (const char **argType)
  {
    return m_loc[0]->ArgType (m_loc,argType);
  }
    LxResult
  Action (const char **action)
  {
    return m_loc[0]->Action (m_loc,action);
  }
    LxResult
  DeferAction (void)
  {
    return m_loc[0]->DeferAction (m_loc);
  }
    LxResult
  DialogUserName (const char **username)
  {
    return m_loc[0]->DialogUserName (m_loc,username);
  }
    LxResult
  ValuePresetCookie (const char **cookie)
  {
    return m_loc[0]->ValuePresetCookie (m_loc,cookie);
  }
    LxResult
  EnableCommand (const char **command)
  {
    return m_loc[0]->EnableCommand (m_loc,command);
  }
    LxResult
  Notifier (const char **notifier)
  {
    return m_loc[0]->Notifier (m_loc,notifier);
  }
    LxResult
  DefaultValue (void **ppvObj)
  {
    return m_loc[0]->DefaultValue (m_loc,ppvObj);
  }
    CLxResult
  DefaultValue (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->DefaultValue(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AsUI (void)
  {
    return m_loc[0]->AsUI (m_loc);
  }
    LxResult
  InvertEnableCommandTest (void)
  {
    return m_loc[0]->InvertEnableCommandTest (m_loc);
  }
    LxResult
  UIMode (int *uiMode)
  {
    return m_loc[0]->UIMode (m_loc,uiMode);
  }
};

class CLxImpl_ScriptLineEvent {
  public:
    virtual ~CLxImpl_ScriptLineEvent() {}
    virtual LxResult
      slev_Index (unsigned int *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      slev_Script (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_ScriptLineEvent_Index LxResult slev_Index (unsigned int *index)
#define LXxO_ScriptLineEvent_Index LXxD_ScriptLineEvent_Index LXx_OVERRIDE
#define LXxC_ScriptLineEvent_Index(c) LxResult c::slev_Index (unsigned int *index)
#define LXxD_ScriptLineEvent_Script LxResult slev_Script (void **ppvObj)
#define LXxO_ScriptLineEvent_Script LXxD_ScriptLineEvent_Script LXx_OVERRIDE
#define LXxC_ScriptLineEvent_Script(c) LxResult c::slev_Script (void **ppvObj)
template <class T>
class CLxIfc_ScriptLineEvent : public CLxInterface
{
    static LxResult
  Index (LXtObjectID wcom, unsigned int *index)
  {
    LXCWxINST (CLxImpl_ScriptLineEvent, loc);
    try {
      return loc->slev_Index (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Script (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ScriptLineEvent, loc);
    try {
      return loc->slev_Script (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxScriptLineEvent vt;
public:
  CLxIfc_ScriptLineEvent ()
  {
    vt.Index = Index;
    vt.Script = Script;
    vTable = &vt.iunk;
    iid = &lx::guid_ScriptLineEvent;
  }
};
class CLxLoc_ScriptLineEvent : public CLxLocalize<ILxScriptLineEventID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ScriptLineEvent() {_init();}
  CLxLoc_ScriptLineEvent(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ScriptLineEvent(const CLxLoc_ScriptLineEvent &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ScriptLineEvent;}
    LxResult
  Index (unsigned int *index)
  {
    return m_loc[0]->Index (m_loc,index);
  }
    LxResult
  Script (void **ppvObj)
  {
    return m_loc[0]->Script (m_loc,ppvObj);
  }
    CLxResult
  Script (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Script(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_LineExecution {
  public:
    virtual ~CLxImpl_LineExecution() {}
    virtual LxResult
      lin_CookedLine (const char *text)
        { return LXe_NOTIMPL; }
    virtual LxResult
      lin_Message (ILxUnknownID message)
        { return LXe_NOTIMPL; }
    virtual LxResult
      lin_Results (ILxUnknownID valArray)
        { return LXe_NOTIMPL; }
    virtual LxResult
      lin_ResultHints (const LXtTextValueHint *hints)
        { return LXe_NOTIMPL; }
    virtual LxResult
      lin_Info (const char *text)
        { return LXe_NOTIMPL; }
};
#define LXxD_LineExecution_CookedLine LxResult lin_CookedLine (const char *text)
#define LXxO_LineExecution_CookedLine LXxD_LineExecution_CookedLine LXx_OVERRIDE
#define LXxC_LineExecution_CookedLine(c) LxResult c::lin_CookedLine (const char *text)
#define LXxD_LineExecution_Message LxResult lin_Message (ILxUnknownID message)
#define LXxO_LineExecution_Message LXxD_LineExecution_Message LXx_OVERRIDE
#define LXxC_LineExecution_Message(c) LxResult c::lin_Message (ILxUnknownID message)
#define LXxD_LineExecution_Results LxResult lin_Results (ILxUnknownID valArray)
#define LXxO_LineExecution_Results LXxD_LineExecution_Results LXx_OVERRIDE
#define LXxC_LineExecution_Results(c) LxResult c::lin_Results (ILxUnknownID valArray)
#define LXxD_LineExecution_ResultHints LxResult lin_ResultHints (const LXtTextValueHint *hints)
#define LXxO_LineExecution_ResultHints LXxD_LineExecution_ResultHints LXx_OVERRIDE
#define LXxC_LineExecution_ResultHints(c) LxResult c::lin_ResultHints (const LXtTextValueHint *hints)
#define LXxD_LineExecution_Info LxResult lin_Info (const char *text)
#define LXxO_LineExecution_Info LXxD_LineExecution_Info LXx_OVERRIDE
#define LXxC_LineExecution_Info(c) LxResult c::lin_Info (const char *text)
template <class T>
class CLxIfc_LineExecution : public CLxInterface
{
    static LxResult
  CookedLine (LXtObjectID wcom, const char *text)
  {
    LXCWxINST (CLxImpl_LineExecution, loc);
    try {
      return loc->lin_CookedLine (text);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Message (LXtObjectID wcom, LXtObjectID message)
  {
    LXCWxINST (CLxImpl_LineExecution, loc);
    try {
      return loc->lin_Message ((ILxUnknownID)message);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Results (LXtObjectID wcom, LXtObjectID valArray)
  {
    LXCWxINST (CLxImpl_LineExecution, loc);
    try {
      return loc->lin_Results ((ILxUnknownID)valArray);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ResultHints (LXtObjectID wcom, const LXtTextValueHint *hints)
  {
    LXCWxINST (CLxImpl_LineExecution, loc);
    try {
      return loc->lin_ResultHints (hints);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Info (LXtObjectID wcom, const char *text)
  {
    LXCWxINST (CLxImpl_LineExecution, loc);
    try {
      return loc->lin_Info (text);
    } catch (LxResult rc) { return rc; }
  }
  ILxLineExecution vt;
public:
  CLxIfc_LineExecution ()
  {
    vt.CookedLine = CookedLine;
    vt.Message = Message;
    vt.Results = Results;
    vt.ResultHints = ResultHints;
    vt.Info = Info;
    vTable = &vt.iunk;
    iid = &lx::guid_LineExecution;
  }
};
class CLxLoc_LineExecution : public CLxLocalize<ILxLineExecutionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LineExecution() {_init();}
  CLxLoc_LineExecution(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LineExecution(const CLxLoc_LineExecution &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LineExecution;}
    LxResult
  CookedLine (const char *text)
  {
    return m_loc[0]->CookedLine (m_loc,text);
  }
    LxResult
  Message (ILxUnknownID message)
  {
    return m_loc[0]->Message (m_loc,(ILxUnknownID)message);
  }
    LxResult
  Results (ILxUnknownID valArray)
  {
    return m_loc[0]->Results (m_loc,(ILxUnknownID)valArray);
  }
    LxResult
  ResultHints (const LXtTextValueHint *hints)
  {
    return m_loc[0]->ResultHints (m_loc,hints);
  }
    LxResult
  Info (const char *text)
  {
    return m_loc[0]->Info (m_loc,text);
  }
};

class CLxImpl_TextScriptInterpreter {
  public:
    virtual ~CLxImpl_TextScriptInterpreter() {}
    virtual LxResult
      tsi_ValidateFileType (ILxUnknownID script, const char *firstLine)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsi_Validate (ILxUnknownID script, ILxUnknownID msg)
        { return LXe_OK; }
    virtual LxResult
      tsi_Run (ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg)
        { return LXe_NOTIMPL; }
};
#define LXxD_TextScriptInterpreter_ValidateFileType LxResult tsi_ValidateFileType (ILxUnknownID script, const char *firstLine)
#define LXxO_TextScriptInterpreter_ValidateFileType LXxD_TextScriptInterpreter_ValidateFileType LXx_OVERRIDE
#define LXxC_TextScriptInterpreter_ValidateFileType(c) LxResult c::tsi_ValidateFileType (ILxUnknownID script, const char *firstLine)
#define LXxD_TextScriptInterpreter_Validate LxResult tsi_Validate (ILxUnknownID script, ILxUnknownID msg)
#define LXxO_TextScriptInterpreter_Validate LXxD_TextScriptInterpreter_Validate LXx_OVERRIDE
#define LXxC_TextScriptInterpreter_Validate(c) LxResult c::tsi_Validate (ILxUnknownID script, ILxUnknownID msg)
#define LXxD_TextScriptInterpreter_Run LxResult tsi_Run (ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg)
#define LXxO_TextScriptInterpreter_Run LXxD_TextScriptInterpreter_Run LXx_OVERRIDE
#define LXxC_TextScriptInterpreter_Run(c) LxResult c::tsi_Run (ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg)
template <class T>
class CLxIfc_TextScriptInterpreter : public CLxInterface
{
    static LxResult
  ValidateFileType (LXtObjectID wcom, LXtObjectID script, const char *firstLine)
  {
    LXCWxINST (CLxImpl_TextScriptInterpreter, loc);
    try {
      return loc->tsi_ValidateFileType ((ILxUnknownID)script,firstLine);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Validate (LXtObjectID wcom, LXtObjectID script, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_TextScriptInterpreter, loc);
    try {
      return loc->tsi_Validate ((ILxUnknownID)script,(ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Run (LXtObjectID wcom, LXtObjectID script, int execFlags, const char *args, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_TextScriptInterpreter, loc);
    try {
      return loc->tsi_Run ((ILxUnknownID)script,execFlags,args,(ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
  ILxTextScriptInterpreter vt;
public:
  CLxIfc_TextScriptInterpreter ()
  {
    vt.ValidateFileType = ValidateFileType;
    vt.Validate = Validate;
    vt.Run = Run;
    vTable = &vt.iunk;
    iid = &lx::guid_TextScriptInterpreter;
  }
};
class CLxLoc_TextScriptInterpreter : public CLxLocalize<ILxTextScriptInterpreterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TextScriptInterpreter() {_init();}
  CLxLoc_TextScriptInterpreter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TextScriptInterpreter(const CLxLoc_TextScriptInterpreter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TextScriptInterpreter;}
    LxResult
  ValidateFileType (ILxUnknownID script, const char *firstLine)
  {
    return m_loc[0]->ValidateFileType (m_loc,(ILxUnknownID)script,firstLine);
  }
    LxResult
  Validate (ILxUnknownID script, ILxUnknownID msg)
  {
    return m_loc[0]->Validate (m_loc,(ILxUnknownID)script,(ILxUnknownID)msg);
  }
    LxResult
  Run (ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg)
  {
    return m_loc[0]->Run (m_loc,(ILxUnknownID)script,execFlags,args,(ILxUnknownID)msg);
  }
};

class CLxImpl_UserValueListener {
  public:
    virtual ~CLxImpl_UserValueListener() {}
    virtual LxResult
      uvl_Added (ILxUnknownID userValue)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uvl_Deleted (const char *name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uvl_DefChanged (ILxUnknownID userValue)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uvl_ValueChanged (ILxUnknownID userValue)
        { return LXe_NOTIMPL; }
};
#define LXxD_UserValueListener_Added LxResult uvl_Added (ILxUnknownID userValue)
#define LXxO_UserValueListener_Added LXxD_UserValueListener_Added LXx_OVERRIDE
#define LXxC_UserValueListener_Added(c) LxResult c::uvl_Added (ILxUnknownID userValue)
#define LXxD_UserValueListener_Deleted LxResult uvl_Deleted (const char *name)
#define LXxO_UserValueListener_Deleted LXxD_UserValueListener_Deleted LXx_OVERRIDE
#define LXxC_UserValueListener_Deleted(c) LxResult c::uvl_Deleted (const char *name)
#define LXxD_UserValueListener_DefChanged LxResult uvl_DefChanged (ILxUnknownID userValue)
#define LXxO_UserValueListener_DefChanged LXxD_UserValueListener_DefChanged LXx_OVERRIDE
#define LXxC_UserValueListener_DefChanged(c) LxResult c::uvl_DefChanged (ILxUnknownID userValue)
#define LXxD_UserValueListener_ValueChanged LxResult uvl_ValueChanged (ILxUnknownID userValue)
#define LXxO_UserValueListener_ValueChanged LXxD_UserValueListener_ValueChanged LXx_OVERRIDE
#define LXxC_UserValueListener_ValueChanged(c) LxResult c::uvl_ValueChanged (ILxUnknownID userValue)
template <class T>
class CLxIfc_UserValueListener : public CLxInterface
{
    static LxResult
  Added (LXtObjectID wcom, LXtObjectID userValue)
  {
    LXCWxINST (CLxImpl_UserValueListener, loc);
    try {
      return loc->uvl_Added ((ILxUnknownID)userValue);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Deleted (LXtObjectID wcom, const char *name)
  {
    LXCWxINST (CLxImpl_UserValueListener, loc);
    try {
      return loc->uvl_Deleted (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DefChanged (LXtObjectID wcom, LXtObjectID userValue)
  {
    LXCWxINST (CLxImpl_UserValueListener, loc);
    try {
      return loc->uvl_DefChanged ((ILxUnknownID)userValue);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ValueChanged (LXtObjectID wcom, LXtObjectID userValue)
  {
    LXCWxINST (CLxImpl_UserValueListener, loc);
    try {
      return loc->uvl_ValueChanged ((ILxUnknownID)userValue);
    } catch (LxResult rc) { return rc; }
  }
  ILxUserValueListener vt;
public:
  CLxIfc_UserValueListener ()
  {
    vt.Added = Added;
    vt.Deleted = Deleted;
    vt.DefChanged = DefChanged;
    vt.ValueChanged = ValueChanged;
    vTable = &vt.iunk;
    iid = &lx::guid_UserValueListener;
  }
};
class CLxLoc_UserValueListener : public CLxLocalize<ILxUserValueListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UserValueListener() {_init();}
  CLxLoc_UserValueListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UserValueListener(const CLxLoc_UserValueListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UserValueListener;}
    LxResult
  Added (ILxUnknownID userValue)
  {
    return m_loc[0]->Added (m_loc,(ILxUnknownID)userValue);
  }
    LxResult
  Deleted (const char *name)
  {
    return m_loc[0]->Deleted (m_loc,name);
  }
    LxResult
  DefChanged (ILxUnknownID userValue)
  {
    return m_loc[0]->DefChanged (m_loc,(ILxUnknownID)userValue);
  }
    LxResult
  ValueChanged (ILxUnknownID userValue)
  {
    return m_loc[0]->ValueChanged (m_loc,(ILxUnknownID)userValue);
  }
};

class CLxImpl_AppActiveListener {
  public:
    virtual ~CLxImpl_AppActiveListener() {}
    virtual LxResult
      activeevent_IsNowActive (int isActive)
        { return LXe_NOTIMPL; }
};
#define LXxD_AppActiveListener_IsNowActive LxResult activeevent_IsNowActive (int isActive)
#define LXxO_AppActiveListener_IsNowActive LXxD_AppActiveListener_IsNowActive LXx_OVERRIDE
#define LXxC_AppActiveListener_IsNowActive(c) LxResult c::activeevent_IsNowActive (int isActive)
template <class T>
class CLxIfc_AppActiveListener : public CLxInterface
{
    static LxResult
  IsNowActive (LXtObjectID wcom, int isActive)
  {
    LXCWxINST (CLxImpl_AppActiveListener, loc);
    try {
      return loc->activeevent_IsNowActive (isActive);
    } catch (LxResult rc) { return rc; }
  }
  ILxAppActiveListener vt;
public:
  CLxIfc_AppActiveListener ()
  {
    vt.IsNowActive = IsNowActive;
    vTable = &vt.iunk;
    iid = &lx::guid_AppActiveListener;
  }
};
class CLxLoc_AppActiveListener : public CLxLocalize<ILxAppActiveListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AppActiveListener() {_init();}
  CLxLoc_AppActiveListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AppActiveListener(const CLxLoc_AppActiveListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AppActiveListener;}
    LxResult
  IsNowActive (int isActive)
  {
    return m_loc[0]->IsNowActive (m_loc,isActive);
  }
};

class CLxImpl_LineInterpreter {
  public:
    virtual ~CLxImpl_LineInterpreter() {}
    virtual unsigned
      lin_Flags (void)
        = 0;
    virtual LxResult
      lin_Prompt (const char **prompt, unsigned type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      lin_Execute (const char *line, int execFlags, ILxUnknownID execution)
        { return LXe_NOTIMPL; }
};
#define LXxD_LineInterpreter_Flags unsigned lin_Flags (void)
#define LXxO_LineInterpreter_Flags LXxD_LineInterpreter_Flags LXx_OVERRIDE
#define LXxC_LineInterpreter_Flags(c) unsigned c::lin_Flags (void)
#define LXxD_LineInterpreter_Prompt LxResult lin_Prompt (const char **prompt, unsigned type)
#define LXxO_LineInterpreter_Prompt LXxD_LineInterpreter_Prompt LXx_OVERRIDE
#define LXxC_LineInterpreter_Prompt(c) LxResult c::lin_Prompt (const char **prompt, unsigned type)
#define LXxD_LineInterpreter_Execute LxResult lin_Execute (const char *line, int execFlags, ILxUnknownID execution)
#define LXxO_LineInterpreter_Execute LXxD_LineInterpreter_Execute LXx_OVERRIDE
#define LXxC_LineInterpreter_Execute(c) LxResult c::lin_Execute (const char *line, int execFlags, ILxUnknownID execution)
template <class T>
class CLxIfc_LineInterpreter : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_LineInterpreter, loc);
    return loc->lin_Flags ();
  }
    static LxResult
  Prompt (LXtObjectID wcom, const char **prompt, unsigned type)
  {
    LXCWxINST (CLxImpl_LineInterpreter, loc);
    try {
      return loc->lin_Prompt (prompt,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Execute (LXtObjectID wcom, const char *line, int execFlags, LXtObjectID execution)
  {
    LXCWxINST (CLxImpl_LineInterpreter, loc);
    try {
      return loc->lin_Execute (line,execFlags,(ILxUnknownID)execution);
    } catch (LxResult rc) { return rc; }
  }
  ILxLineInterpreter vt;
public:
  CLxIfc_LineInterpreter ()
  {
    vt.Flags = Flags;
    vt.Prompt = Prompt;
    vt.Execute = Execute;
    vTable = &vt.iunk;
    iid = &lx::guid_LineInterpreter;
  }
};
class CLxLoc_LineInterpreter : public CLxLocalize<ILxLineInterpreterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LineInterpreter() {_init();}
  CLxLoc_LineInterpreter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LineInterpreter(const CLxLoc_LineInterpreter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LineInterpreter;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    LxResult
  Prompt (const char **prompt, unsigned type)
  {
    return m_loc[0]->Prompt (m_loc,prompt,type);
  }
    LxResult
  Execute (const char *line, int execFlags, ILxUnknownID execution)
  {
    return m_loc[0]->Execute (m_loc,line,execFlags,(ILxUnknownID)execution);
  }
};

class CLxLoc_Kit : public CLxLocalize<ILxKitID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Kit() {_init();}
  CLxLoc_Kit(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Kit(const CLxLoc_Kit &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Kit;}
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  Version (const char **version)
  {
    return m_loc[0]->Version (m_loc,version);
  }
    LxResult
  IsEnabled (void)
  {
    return m_loc[0]->IsEnabled (m_loc);
  }
    void
  SetEnabled (int enabled)
  {
    m_loc[0]->SetEnabled (m_loc,enabled);
  }
    LxResult
  IsVisible (void)
  {
    return m_loc[0]->IsVisible (m_loc);
  }
};

class CLxImpl_SessionListener {
  public:
    virtual ~CLxImpl_SessionListener() {}
    virtual LxResult
      sesl_FirstWindowOpening (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sesl_BeforeStartupCommands (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sesl_SystemReady (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sesl_CheckQuitUI (int quitWasAborted)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sesl_QuittingUI (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sesl_LastWindowClosed (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sesl_ShuttingDown (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_SessionListener_FirstWindowOpening LxResult sesl_FirstWindowOpening (void)
#define LXxO_SessionListener_FirstWindowOpening LXxD_SessionListener_FirstWindowOpening LXx_OVERRIDE
#define LXxC_SessionListener_FirstWindowOpening(c) LxResult c::sesl_FirstWindowOpening (void)
#define LXxD_SessionListener_BeforeStartupCommands LxResult sesl_BeforeStartupCommands (void)
#define LXxO_SessionListener_BeforeStartupCommands LXxD_SessionListener_BeforeStartupCommands LXx_OVERRIDE
#define LXxC_SessionListener_BeforeStartupCommands(c) LxResult c::sesl_BeforeStartupCommands (void)
#define LXxD_SessionListener_SystemReady LxResult sesl_SystemReady (void)
#define LXxO_SessionListener_SystemReady LXxD_SessionListener_SystemReady LXx_OVERRIDE
#define LXxC_SessionListener_SystemReady(c) LxResult c::sesl_SystemReady (void)
#define LXxD_SessionListener_CheckQuitUI LxResult sesl_CheckQuitUI (int quitWasAborted)
#define LXxO_SessionListener_CheckQuitUI LXxD_SessionListener_CheckQuitUI LXx_OVERRIDE
#define LXxC_SessionListener_CheckQuitUI(c) LxResult c::sesl_CheckQuitUI (int quitWasAborted)
#define LXxD_SessionListener_QuittingUI LxResult sesl_QuittingUI (void)
#define LXxO_SessionListener_QuittingUI LXxD_SessionListener_QuittingUI LXx_OVERRIDE
#define LXxC_SessionListener_QuittingUI(c) LxResult c::sesl_QuittingUI (void)
#define LXxD_SessionListener_LastWindowClosed LxResult sesl_LastWindowClosed (void)
#define LXxO_SessionListener_LastWindowClosed LXxD_SessionListener_LastWindowClosed LXx_OVERRIDE
#define LXxC_SessionListener_LastWindowClosed(c) LxResult c::sesl_LastWindowClosed (void)
#define LXxD_SessionListener_ShuttingDown LxResult sesl_ShuttingDown (void)
#define LXxO_SessionListener_ShuttingDown LXxD_SessionListener_ShuttingDown LXx_OVERRIDE
#define LXxC_SessionListener_ShuttingDown(c) LxResult c::sesl_ShuttingDown (void)
template <class T>
class CLxIfc_SessionListener : public CLxInterface
{
    static LxResult
  FirstWindowOpening (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SessionListener, loc);
    try {
      return loc->sesl_FirstWindowOpening ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BeforeStartupCommands (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SessionListener, loc);
    try {
      return loc->sesl_BeforeStartupCommands ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SystemReady (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SessionListener, loc);
    try {
      return loc->sesl_SystemReady ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CheckQuitUI (LXtObjectID wcom, int quitWasAborted)
  {
    LXCWxINST (CLxImpl_SessionListener, loc);
    try {
      return loc->sesl_CheckQuitUI (quitWasAborted);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  QuittingUI (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SessionListener, loc);
    try {
      return loc->sesl_QuittingUI ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LastWindowClosed (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SessionListener, loc);
    try {
      return loc->sesl_LastWindowClosed ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ShuttingDown (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SessionListener, loc);
    try {
      return loc->sesl_ShuttingDown ();
    } catch (LxResult rc) { return rc; }
  }
  ILxSessionListener vt;
public:
  CLxIfc_SessionListener ()
  {
    vt.FirstWindowOpening = FirstWindowOpening;
    vt.BeforeStartupCommands = BeforeStartupCommands;
    vt.SystemReady = SystemReady;
    vt.CheckQuitUI = CheckQuitUI;
    vt.QuittingUI = QuittingUI;
    vt.LastWindowClosed = LastWindowClosed;
    vt.ShuttingDown = ShuttingDown;
    vTable = &vt.iunk;
    iid = &lx::guid_SessionListener;
  }
};
class CLxLoc_SessionListener : public CLxLocalize<ILxSessionListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SessionListener() {_init();}
  CLxLoc_SessionListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SessionListener(const CLxLoc_SessionListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SessionListener;}
    LxResult
  FirstWindowOpening (void)
  {
    return m_loc[0]->FirstWindowOpening (m_loc);
  }
    LxResult
  BeforeStartupCommands (void)
  {
    return m_loc[0]->BeforeStartupCommands (m_loc);
  }
    LxResult
  SystemReady (void)
  {
    return m_loc[0]->SystemReady (m_loc);
  }
    LxResult
  CheckQuitUI (int quitWasAborted)
  {
    return m_loc[0]->CheckQuitUI (m_loc,quitWasAborted);
  }
    LxResult
  QuittingUI (void)
  {
    return m_loc[0]->QuittingUI (m_loc);
  }
    LxResult
  LastWindowClosed (void)
  {
    return m_loc[0]->LastWindowClosed (m_loc);
  }
    LxResult
  ShuttingDown (void)
  {
    return m_loc[0]->ShuttingDown (m_loc);
  }
};

class CLxImpl_Script {
  public:
    virtual ~CLxImpl_Script() {}
    virtual LxResult
      scr_Hash (const char **hash)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_UserName (const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_SetUserName (const char *userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_Desc (const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_SetDesc (const char *desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_Icon (const char **icon)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_HelpKey (const char *args, const char **key)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_Manager (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_GetBuffer (const char **buffer, unsigned int *bufferLength)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_SetBuffer (const char *buffer, unsigned int bufferLength)
        { return LXe_NOTIMPL; }
};
#define LXxD_Script_Hash LxResult scr_Hash (const char **hash)
#define LXxO_Script_Hash LXxD_Script_Hash LXx_OVERRIDE
#define LXxC_Script_Hash(c) LxResult c::scr_Hash (const char **hash)
#define LXxD_Script_UserName LxResult scr_UserName (const char **userName)
#define LXxO_Script_UserName LXxD_Script_UserName LXx_OVERRIDE
#define LXxC_Script_UserName(c) LxResult c::scr_UserName (const char **userName)
#define LXxD_Script_SetUserName LxResult scr_SetUserName (const char *userName)
#define LXxO_Script_SetUserName LXxD_Script_SetUserName LXx_OVERRIDE
#define LXxC_Script_SetUserName(c) LxResult c::scr_SetUserName (const char *userName)
#define LXxD_Script_Desc LxResult scr_Desc (const char **desc)
#define LXxO_Script_Desc LXxD_Script_Desc LXx_OVERRIDE
#define LXxC_Script_Desc(c) LxResult c::scr_Desc (const char **desc)
#define LXxD_Script_SetDesc LxResult scr_SetDesc (const char *desc)
#define LXxO_Script_SetDesc LXxD_Script_SetDesc LXx_OVERRIDE
#define LXxC_Script_SetDesc(c) LxResult c::scr_SetDesc (const char *desc)
#define LXxD_Script_Icon LxResult scr_Icon (const char **icon)
#define LXxO_Script_Icon LXxD_Script_Icon LXx_OVERRIDE
#define LXxC_Script_Icon(c) LxResult c::scr_Icon (const char **icon)
#define LXxD_Script_HelpKey LxResult scr_HelpKey (const char *args, const char **key)
#define LXxO_Script_HelpKey LXxD_Script_HelpKey LXx_OVERRIDE
#define LXxC_Script_HelpKey(c) LxResult c::scr_HelpKey (const char *args, const char **key)
#define LXxD_Script_Manager LxResult scr_Manager (void **ppvObj)
#define LXxO_Script_Manager LXxD_Script_Manager LXx_OVERRIDE
#define LXxC_Script_Manager(c) LxResult c::scr_Manager (void **ppvObj)
#define LXxD_Script_GetBuffer LxResult scr_GetBuffer (const char **buffer, unsigned int *bufferLength)
#define LXxO_Script_GetBuffer LXxD_Script_GetBuffer LXx_OVERRIDE
#define LXxC_Script_GetBuffer(c) LxResult c::scr_GetBuffer (const char **buffer, unsigned int *bufferLength)
#define LXxD_Script_SetBuffer LxResult scr_SetBuffer (const char *buffer, unsigned int bufferLength)
#define LXxO_Script_SetBuffer LXxD_Script_SetBuffer LXx_OVERRIDE
#define LXxC_Script_SetBuffer(c) LxResult c::scr_SetBuffer (const char *buffer, unsigned int bufferLength)
template <class T>
class CLxIfc_Script : public CLxInterface
{
    static LxResult
  Hash (LXtObjectID wcom, const char **hash)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_Hash (hash);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UserName (LXtObjectID wcom, const char **userName)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_UserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetUserName (LXtObjectID wcom, const char *userName)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_SetUserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Desc (LXtObjectID wcom, const char **desc)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_Desc (desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetDesc (LXtObjectID wcom, const char *desc)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_SetDesc (desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Icon (LXtObjectID wcom, const char **icon)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_Icon (icon);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HelpKey (LXtObjectID wcom, const char *args, const char **key)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_HelpKey (args,key);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Manager (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_Manager (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetBuffer (LXtObjectID wcom, const char **buffer, unsigned int *bufferLength)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_GetBuffer (buffer,bufferLength);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetBuffer (LXtObjectID wcom, const char *buffer, unsigned int bufferLength)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_SetBuffer (buffer,bufferLength);
    } catch (LxResult rc) { return rc; }
  }
  ILxScript vt;
public:
  CLxIfc_Script ()
  {
    vt.Hash = Hash;
    vt.UserName = UserName;
    vt.SetUserName = SetUserName;
    vt.Desc = Desc;
    vt.SetDesc = SetDesc;
    vt.Icon = Icon;
    vt.HelpKey = HelpKey;
    vt.Manager = Manager;
    vt.GetBuffer = GetBuffer;
    vt.SetBuffer = SetBuffer;
    vTable = &vt.iunk;
    iid = &lx::guid_Script;
  }
};
class CLxLoc_Script : public CLxLocalize<ILxScriptID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Script() {_init();}
  CLxLoc_Script(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Script(const CLxLoc_Script &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Script;}
    LxResult
  Hash (const char **hash)
  {
    return m_loc[0]->Hash (m_loc,hash);
  }
    LxResult
  UserName (const char **userName)
  {
    return m_loc[0]->UserName (m_loc,userName);
  }
    LxResult
  SetUserName (const char *userName)
  {
    return m_loc[0]->SetUserName (m_loc,userName);
  }
    LxResult
  Desc (const char **desc)
  {
    return m_loc[0]->Desc (m_loc,desc);
  }
    LxResult
  SetDesc (const char *desc)
  {
    return m_loc[0]->SetDesc (m_loc,desc);
  }
    LxResult
  Icon (const char **icon)
  {
    return m_loc[0]->Icon (m_loc,icon);
  }
    LxResult
  HelpKey (const char *args, const char **key)
  {
    return m_loc[0]->HelpKey (m_loc,args,key);
  }
    LxResult
  Manager (void **ppvObj)
  {
    return m_loc[0]->Manager (m_loc,ppvObj);
  }
    CLxResult
  Manager (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Manager(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetBuffer (const char **buffer, unsigned int *bufferLength)
  {
    return m_loc[0]->GetBuffer (m_loc,buffer,bufferLength);
  }
    LxResult
  SetBuffer (const char *buffer, unsigned int bufferLength)
  {
    return m_loc[0]->SetBuffer (m_loc,buffer,bufferLength);
  }
};

#endif

