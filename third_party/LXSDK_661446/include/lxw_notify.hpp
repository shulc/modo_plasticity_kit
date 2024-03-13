/*
 * C++ wrapper for lxnotify.h
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
#ifndef LXW_NOTIFY_HPP
#define LXW_NOTIFY_HPP

#include <lxnotify.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_NotifySysService = {0x4A3B31B0,0xA8F8,0x430A,0x96,0x11,0x9D,0x30,0xE5,0x1C,0xBB,0xBA};
    static const LXtGUID guid_Notifier = {0x68725BA4,0x8EF9,0x4de4,0x87,0x92,0x74,0xCF,0x09,0x07,0x99,0xC3};
    static const LXtGUID guid_Notify = {0x15C9BFC0,0xA0A7,0x448c,0x8C,0xD5,0xA8,0xFC,0xA2,0xCB,0x14,0x5B};
};

class CLxLoc_NotifySysService : public CLxLocalizedService
{
public:
  ILxNotifySysServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_NotifySysService() {_init();set();}
 ~CLxLoc_NotifySysService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxNotifySysServiceID>(lx::GetGlobal(&lx::guid_NotifySysService));}
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
  Spawn (const char *name, const char *args, void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,name,args,ppvObj);
  }
    CLxResult
  Spawn (const char *name, const char *args, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Spawn(m_loc,name,args,&o_obj);
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
  Lookup (const char *name, const char *args, void **ppvObj)
  {
    return m_loc[0]->Lookup (m_loc,name,args,ppvObj);
  }
    CLxResult
  Lookup (const char *name, const char *args, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Lookup(m_loc,name,args,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_Notifier {
  public:
    virtual ~CLxImpl_Notifier() {}
    virtual LxResult
      noti_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      noti_SetArgs (const char *args)
        { return LXe_NOTIMPL; }
    virtual LxResult
      noti_Args (const char **args)
        { return LXe_NOTIMPL; }
    virtual LxResult
      noti_AddClient (ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      noti_RemoveClient (ILxUnknownID object)
        { return LXe_NOTIMPL; }
};
#define LXxD_Notifier_Name LxResult noti_Name (const char **name)
#define LXxO_Notifier_Name LXxD_Notifier_Name LXx_OVERRIDE
#define LXxC_Notifier_Name(c) LxResult c::noti_Name (const char **name)
#define LXxD_Notifier_SetArgs LxResult noti_SetArgs (const char *args)
#define LXxO_Notifier_SetArgs LXxD_Notifier_SetArgs LXx_OVERRIDE
#define LXxC_Notifier_SetArgs(c) LxResult c::noti_SetArgs (const char *args)
#define LXxD_Notifier_Args LxResult noti_Args (const char **args)
#define LXxO_Notifier_Args LXxD_Notifier_Args LXx_OVERRIDE
#define LXxC_Notifier_Args(c) LxResult c::noti_Args (const char **args)
#define LXxD_Notifier_AddClient LxResult noti_AddClient (ILxUnknownID object)
#define LXxO_Notifier_AddClient LXxD_Notifier_AddClient LXx_OVERRIDE
#define LXxC_Notifier_AddClient(c) LxResult c::noti_AddClient (ILxUnknownID object)
#define LXxD_Notifier_RemoveClient LxResult noti_RemoveClient (ILxUnknownID object)
#define LXxO_Notifier_RemoveClient LXxD_Notifier_RemoveClient LXx_OVERRIDE
#define LXxC_Notifier_RemoveClient(c) LxResult c::noti_RemoveClient (ILxUnknownID object)
template <class T>
class CLxIfc_Notifier : public CLxInterface
{
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Notifier, loc);
    try {
      return loc->noti_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetArgs (LXtObjectID wcom, const char *args)
  {
    LXCWxINST (CLxImpl_Notifier, loc);
    try {
      return loc->noti_SetArgs (args);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Args (LXtObjectID wcom, const char **args)
  {
    LXCWxINST (CLxImpl_Notifier, loc);
    try {
      return loc->noti_Args (args);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddClient (LXtObjectID wcom, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Notifier, loc);
    try {
      return loc->noti_AddClient ((ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RemoveClient (LXtObjectID wcom, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Notifier, loc);
    try {
      return loc->noti_RemoveClient ((ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
  ILxNotifier vt;
public:
  CLxIfc_Notifier ()
  {
    vt.Name = Name;
    vt.SetArgs = SetArgs;
    vt.Args = Args;
    vt.AddClient = AddClient;
    vt.RemoveClient = RemoveClient;
    vTable = &vt.iunk;
    iid = &lx::guid_Notifier;
  }
};
class CLxLoc_Notifier : public CLxLocalize<ILxNotifierID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Notifier() {_init();}
  CLxLoc_Notifier(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Notifier(const CLxLoc_Notifier &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Notifier;}
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  SetArgs (const char *args)
  {
    return m_loc[0]->SetArgs (m_loc,args);
  }
    LxResult
  Args (const char **args)
  {
    return m_loc[0]->Args (m_loc,args);
  }
    LxResult
  AddClient (ILxUnknownID object)
  {
    return m_loc[0]->AddClient (m_loc,(ILxUnknownID)object);
  }
    LxResult
  RemoveClient (ILxUnknownID object)
  {
    return m_loc[0]->RemoveClient (m_loc,(ILxUnknownID)object);
  }
};


#endif

