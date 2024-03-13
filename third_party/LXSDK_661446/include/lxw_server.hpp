/*
 * C++ wrapper for lxserver.h
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
#ifndef LXW_SERVER_HPP
#define LXW_SERVER_HPP

#include <lxserver.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_HostService = {0x525802A6,0xBF5F,0x46E9,0x98,0x63,0xC0,0x3B,0x54,0xA3,0xD9,0x08};
    static const LXtGUID guid_NeedContext = {0x7D30408C,0x74AB,0x4d87,0xB7,0x1C,0xC6,0x28,0x08,0x83,0x86,0x3C};
    static const LXtGUID guid_Module = {0x4DB9C543,0xB192,0x4EDD,0xA6,0x5D,0xDD,0x01,0x2F,0xC2,0x74,0x16};
    static const LXtGUID guid_Module1 = {0xBD6F0E53,0xC903,0x46D3,0x92,0x11,0x75,0x85,0x58,0xD9,0x5C,0xAA};
    static const LXtGUID guid_ServiceExtension = {0xE7C6F1A2,0x2F31,0x4FA5,0xB2,0xEF,0x42,0x1B,0xE1,0x59,0xD0,0xD8};
    static const LXtGUID guid_TagDescription = {0x5582E0EE,0xD682,0x47BC,0xBF,0x3D,0xFB,0x14,0xD5,0x99,0x48,0xC1};
    static const LXtGUID guid_Factory = {0x2431A79E,0x3412,0x4B0D,0x98,0x7D,0x87,0x54,0x89,0x46,0x6C,0x58};
};

class CLxLoc_HostService : public CLxLocalizedService
{
public:
  ILxHostServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_HostService() {_init();set();}
 ~CLxLoc_HostService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxHostServiceID>(lx::GetGlobal(&lx::guid_HostService));}
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
  LookupServer (const char *className, const char *name, unsigned allowLoad, void **ppvObj)
  {
    return m_loc[0]->LookupServer (m_loc,className,name,allowLoad,ppvObj);
  }
    CLxResult
  LookupServer (const char *className, const char *name, unsigned allowLoad, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->LookupServer(m_loc,className,name,allowLoad,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  TestServer (const char *className, const char *name)
  {
    return m_loc[0]->TestServer (m_loc,className,name);
  }
    unsigned
  NumServers (const char *className)
  {
    return m_loc[0]->NumServers (m_loc,className);
  }
    LxResult
  ServerByIndex (const char *className, unsigned index, void **ppvObj)
  {
    return m_loc[0]->ServerByIndex (m_loc,className,index,ppvObj);
  }
    CLxResult
  ServerByIndex (const char *className, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ServerByIndex(m_loc,className,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ServerGetIndex (const char *className, const char *name, unsigned *index)
  {
    return m_loc[0]->ServerGetIndex (m_loc,className,name,index);
  }
    LxResult
  AddServer (ILxUnknownID factory)
  {
    return m_loc[0]->AddServer (m_loc,(ILxUnknownID)factory);
  }
    LxResult
  DefaultPath (const char **path)
  {
    return m_loc[0]->DefaultPath (m_loc,path);
  }
    LxResult
  SpawnForTagsOnly (void)
  {
    return m_loc[0]->SpawnForTagsOnly (m_loc);
  }
    LxResult
  UpdateModule (const char *name)
  {
    return m_loc[0]->UpdateModule (m_loc,name);
  }
    LxResult
  SaverVerify (const char *format, ILxUnknownID object, ILxUnknownID msg)
  {
    return m_loc[0]->SaverVerify (m_loc,format,(ILxUnknownID)object,(ILxUnknownID)msg);
  }
    LxResult
  SaverSave (const char *filename, const char *format, ILxUnknownID object, ILxUnknownID monitor)
  {
    return m_loc[0]->SaverSave (m_loc,filename,format,(ILxUnknownID)object,(ILxUnknownID)monitor);
  }
};

class CLxImpl_NeedContext {
  public:
    virtual ~CLxImpl_NeedContext() {}
    virtual LxResult
      need_SetContext (ILxUnknownID app)
        { return LXe_NOTIMPL; }
};
#define LXxD_NeedContext_SetContext LxResult need_SetContext (ILxUnknownID app)
#define LXxO_NeedContext_SetContext LXxD_NeedContext_SetContext LXx_OVERRIDE
#define LXxC_NeedContext_SetContext(c) LxResult c::need_SetContext (ILxUnknownID app)
template <class T>
class CLxIfc_NeedContext : public CLxInterface
{
    static LxResult
  SetContext (LXtObjectID wcom, LXtObjectID app)
  {
    LXCWxINST (CLxImpl_NeedContext, loc);
    try {
      return loc->need_SetContext ((ILxUnknownID)app);
    } catch (LxResult rc) { return rc; }
  }
  ILxNeedContext vt;
public:
  CLxIfc_NeedContext ()
  {
    vt.SetContext = SetContext;
    vTable = &vt.iunk;
    iid = &lx::guid_NeedContext;
  }
};
class CLxLoc_NeedContext : public CLxLocalize<ILxNeedContextID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_NeedContext() {_init();}
  CLxLoc_NeedContext(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_NeedContext(const CLxLoc_NeedContext &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_NeedContext;}
    LxResult
  SetContext (ILxUnknownID app)
  {
    return m_loc[0]->SetContext (m_loc,(ILxUnknownID)app);
  }
};

class CLxImpl_Module {
  public:
    virtual ~CLxImpl_Module() {}
    virtual LxResult
      mod_Generate (const char *name, const LXtGUID *iid, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mod_GetTags (const char *name, const LXtGUID *iid, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_Module_Generate LxResult mod_Generate (const char *name, const LXtGUID *iid, void **ppvObj)
#define LXxO_Module_Generate LXxD_Module_Generate LXx_OVERRIDE
#define LXxC_Module_Generate(c) LxResult c::mod_Generate (const char *name, const LXtGUID *iid, void **ppvObj)
#define LXxD_Module_GetTags LxResult mod_GetTags (const char *name, const LXtGUID *iid, void **ppvObj)
#define LXxO_Module_GetTags LXxD_Module_GetTags LXx_OVERRIDE
#define LXxC_Module_GetTags(c) LxResult c::mod_GetTags (const char *name, const LXtGUID *iid, void **ppvObj)
template <class T>
class CLxIfc_Module : public CLxInterface
{
    static LxResult
  Generate (LXtObjectID wcom, const char *name, const LXtGUID *iid, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Module, loc);
    try {
      return loc->mod_Generate (name,iid,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetTags (LXtObjectID wcom, const char *name, const LXtGUID *iid, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Module, loc);
    try {
      return loc->mod_GetTags (name,iid,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxModule vt;
public:
  CLxIfc_Module ()
  {
    vt.Generate = Generate;
    vt.GetTags = GetTags;
    vTable = &vt.iunk;
    iid = &lx::guid_Module;
  }
};
class CLxLoc_Module : public CLxLocalize<ILxModuleID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Module() {_init();}
  CLxLoc_Module(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Module(const CLxLoc_Module &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Module;}
    LxResult
  Generate (const char *name, const LXtGUID *iid, void **ppvObj)
  {
    return m_loc[0]->Generate (m_loc,name,iid,ppvObj);
  }
    CLxResult
  Generate (const char *name, const LXtGUID *iid, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Generate(m_loc,name,iid,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetTags (const char *name, const LXtGUID *iid, void **ppvObj)
  {
    return m_loc[0]->GetTags (m_loc,name,iid,ppvObj);
  }
    CLxResult
  GetTags (const char *name, const LXtGUID *iid, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetTags(m_loc,name,iid,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};


class CLxImpl_ServiceExtension {
  public:
    virtual ~CLxImpl_ServiceExtension() {}
    virtual void
      ser_Dummy (void)
        { }
};
#define LXxD_ServiceExtension_Dummy void ser_Dummy (void)
#define LXxO_ServiceExtension_Dummy LXxD_ServiceExtension_Dummy LXx_OVERRIDE
#define LXxC_ServiceExtension_Dummy(c) void c::ser_Dummy (void)
template <class T>
class CLxIfc_ServiceExtension : public CLxInterface
{
    static void
  Dummy (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ServiceExtension, loc);
    loc->ser_Dummy ();
  }
  ILxServiceExtension vt;
public:
  CLxIfc_ServiceExtension ()
  {
    vt.Dummy = Dummy;
    vTable = &vt.iunk;
    iid = &lx::guid_ServiceExtension;
  }
};

class CLxImpl_TagDescription {
  public:
    virtual ~CLxImpl_TagDescription() {}
    virtual unsigned
      tag_Count (void)
        = 0;
    virtual LxResult
      tag_Describe (unsigned index, LXtTagInfoDesc *desc)
        { return LXe_NOTIMPL; }
};
#define LXxD_TagDescription_Count unsigned tag_Count (void)
#define LXxO_TagDescription_Count LXxD_TagDescription_Count LXx_OVERRIDE
#define LXxC_TagDescription_Count(c) unsigned c::tag_Count (void)
#define LXxD_TagDescription_Describe LxResult tag_Describe (unsigned index, LXtTagInfoDesc *desc)
#define LXxO_TagDescription_Describe LXxD_TagDescription_Describe LXx_OVERRIDE
#define LXxC_TagDescription_Describe(c) LxResult c::tag_Describe (unsigned index, LXtTagInfoDesc *desc)
template <class T>
class CLxIfc_TagDescription : public CLxInterface
{
    static unsigned
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TagDescription, loc);
    return loc->tag_Count ();
  }
    static LxResult
  Describe (LXtObjectID wcom, unsigned index, LXtTagInfoDesc *desc)
  {
    LXCWxINST (CLxImpl_TagDescription, loc);
    try {
      return loc->tag_Describe (index,desc);
    } catch (LxResult rc) { return rc; }
  }
  ILxTagDescription vt;
public:
  CLxIfc_TagDescription ()
  {
    vt.Count = Count;
    vt.Describe = Describe;
    vTable = &vt.iunk;
    iid = &lx::guid_TagDescription;
  }
};
class CLxLoc_TagDescription : public CLxLocalize<ILxTagDescriptionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TagDescription() {_init();}
  CLxLoc_TagDescription(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TagDescription(const CLxLoc_TagDescription &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TagDescription;}
    unsigned
  Count (void)
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  Describe (unsigned index, LXtTagInfoDesc *desc)
  {
    return m_loc[0]->Describe (m_loc,index,desc);
  }
};

class CLxImpl_Factory {
  public:
    virtual ~CLxImpl_Factory() {}
    virtual LxResult
      fac_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_UserName (const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_ClassGUID (LXtGUID *guid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_Module (const char **module)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_InfoTag (const char *type, const char **value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_TagCount (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_TagByIndex (unsigned int index, const char **type, const char **value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_Spawn (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_Factory_Name LxResult fac_Name (const char **name)
#define LXxO_Factory_Name LXxD_Factory_Name LXx_OVERRIDE
#define LXxC_Factory_Name(c) LxResult c::fac_Name (const char **name)
#define LXxD_Factory_UserName LxResult fac_UserName (const char **userName)
#define LXxO_Factory_UserName LXxD_Factory_UserName LXx_OVERRIDE
#define LXxC_Factory_UserName(c) LxResult c::fac_UserName (const char **userName)
#define LXxD_Factory_ClassGUID LxResult fac_ClassGUID (LXtGUID *guid)
#define LXxO_Factory_ClassGUID LXxD_Factory_ClassGUID LXx_OVERRIDE
#define LXxC_Factory_ClassGUID(c) LxResult c::fac_ClassGUID (LXtGUID *guid)
#define LXxD_Factory_Module LxResult fac_Module (const char **module)
#define LXxO_Factory_Module LXxD_Factory_Module LXx_OVERRIDE
#define LXxC_Factory_Module(c) LxResult c::fac_Module (const char **module)
#define LXxD_Factory_InfoTag LxResult fac_InfoTag (const char *type, const char **value)
#define LXxO_Factory_InfoTag LXxD_Factory_InfoTag LXx_OVERRIDE
#define LXxC_Factory_InfoTag(c) LxResult c::fac_InfoTag (const char *type, const char **value)
#define LXxD_Factory_TagCount LxResult fac_TagCount (unsigned int *count)
#define LXxO_Factory_TagCount LXxD_Factory_TagCount LXx_OVERRIDE
#define LXxC_Factory_TagCount(c) LxResult c::fac_TagCount (unsigned int *count)
#define LXxD_Factory_TagByIndex LxResult fac_TagByIndex (unsigned int index, const char **type, const char **value)
#define LXxO_Factory_TagByIndex LXxD_Factory_TagByIndex LXx_OVERRIDE
#define LXxC_Factory_TagByIndex(c) LxResult c::fac_TagByIndex (unsigned int index, const char **type, const char **value)
#define LXxD_Factory_Spawn LxResult fac_Spawn (void **ppvObj)
#define LXxO_Factory_Spawn LXxD_Factory_Spawn LXx_OVERRIDE
#define LXxC_Factory_Spawn(c) LxResult c::fac_Spawn (void **ppvObj)
template <class T>
class CLxIfc_Factory : public CLxInterface
{
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UserName (LXtObjectID wcom, const char **userName)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_UserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ClassGUID (LXtObjectID wcom, LXtGUID *guid)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_ClassGUID (guid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Module (LXtObjectID wcom, const char **module)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_Module (module);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  InfoTag (LXtObjectID wcom, const char *type, const char **value)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_InfoTag (type,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TagCount (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_TagCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TagByIndex (LXtObjectID wcom, unsigned int index, const char **type, const char **value)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_TagByIndex (index,type,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Spawn (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_Spawn (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxFactory vt;
public:
  CLxIfc_Factory ()
  {
    vt.Name = Name;
    vt.UserName = UserName;
    vt.ClassGUID = ClassGUID;
    vt.Module = Module;
    vt.InfoTag = InfoTag;
    vt.TagCount = TagCount;
    vt.TagByIndex = TagByIndex;
    vt.Spawn = Spawn;
    vTable = &vt.iunk;
    iid = &lx::guid_Factory;
  }
};
class CLxLoc_Factory : public CLxLocalize<ILxFactoryID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Factory() {_init();}
  CLxLoc_Factory(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Factory(const CLxLoc_Factory &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Factory;}
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  UserName (const char **userName)
  {
    return m_loc[0]->UserName (m_loc,userName);
  }
    LxResult
  ClassGUID (LXtGUID *guid)
  {
    return m_loc[0]->ClassGUID (m_loc,guid);
  }
    LxResult
  Module (const char **module)
  {
    return m_loc[0]->Module (m_loc,module);
  }
    LxResult
  InfoTag (const char *type, const char **value)
  {
    return m_loc[0]->InfoTag (m_loc,type,value);
  }
    LxResult
  TagCount (unsigned int *count)
  {
    return m_loc[0]->TagCount (m_loc,count);
  }
    LxResult
  TagByIndex (unsigned int index, const char **type, const char **value)
  {
    return m_loc[0]->TagByIndex (m_loc,index,type,value);
  }
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    CLxResult
  Spawn (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Spawn(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

