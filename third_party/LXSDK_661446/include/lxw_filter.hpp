/*
 * C++ wrapper for lxfilter.h
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
#ifndef LXW_FILTER_HPP
#define LXW_FILTER_HPP

#include <lxfilter.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_EvaluationStack = {0x47F3BF05,0xB64A,0x49D9,0xA2,0xC1,0x08,0xB0,0xD3,0x6A,0xB7,0x87};
    static const LXtGUID guid_StackFilter = {0xD1A07939,0xDB83,0x4869,0x94,0x27,0xA7,0x8D,0x13,0x4D,0xA5,0x75};
    static const LXtGUID guid_CacheData = {0x7561D111,0x72BD,0x4C0C,0x9E,0x2D,0x92,0x68,0xA0,0xEC,0x30,0xC2};
    static const LXtGUID guid_StackFilter1 = {0xB79CF5D3,0xC630,0x401B,0x82,0xA5,0xAD,0x86,0x6B,0xC0,0x5B,0x6F};
    static const LXtGUID guid_CacheService = {0x6BB353D3,0x179A,0x477A,0xAC,0x23,0x94,0x6D,0xEC,0xB4,0x5A,0x37};
};

class CLxLoc_EvaluationStack : public CLxLocalize<ILxEvaluationStackID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_EvaluationStack() {_init();}
  CLxLoc_EvaluationStack(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_EvaluationStack(const CLxLoc_EvaluationStack &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_EvaluationStack;}
    const char *
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  Branch (void **ppvObj)
  {
    return m_loc[0]->Branch (m_loc,ppvObj);
  }
    CLxResult
  Branch (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Branch(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AddFilter (ILxUnknownID filter)
  {
    return m_loc[0]->AddFilter (m_loc,(ILxUnknownID)filter);
  }
};

class CLxImpl_StackFilter {
  public:
    virtual ~CLxImpl_StackFilter() {}
    virtual const char *
      filt_Type (void)
        = 0;
    virtual unsigned
      filt_Compare (ILxUnknownID other)
        { return LXiSTACK_DIFFERENT; }
    virtual LxResult
      filt_Convert (ILxUnknownID other)
        { return LXe_NOTIMPL; }
    virtual LxResult
      filt_Identifier (const char **identifier)
        { return LXe_NOTIMPL; }
};
#define LXxD_StackFilter_Type const char * filt_Type (void)
#define LXxO_StackFilter_Type LXxD_StackFilter_Type LXx_OVERRIDE
#define LXxC_StackFilter_Type(c) const char * c::filt_Type (void)
#define LXxD_StackFilter_Compare unsigned filt_Compare (ILxUnknownID other)
#define LXxO_StackFilter_Compare LXxD_StackFilter_Compare LXx_OVERRIDE
#define LXxC_StackFilter_Compare(c) unsigned c::filt_Compare (ILxUnknownID other)
#define LXxD_StackFilter_Convert LxResult filt_Convert (ILxUnknownID other)
#define LXxO_StackFilter_Convert LXxD_StackFilter_Convert LXx_OVERRIDE
#define LXxC_StackFilter_Convert(c) LxResult c::filt_Convert (ILxUnknownID other)
#define LXxD_StackFilter_Identifier LxResult filt_Identifier (const char **identifier)
#define LXxO_StackFilter_Identifier LXxD_StackFilter_Identifier LXx_OVERRIDE
#define LXxC_StackFilter_Identifier(c) LxResult c::filt_Identifier (const char **identifier)
template <class T>
class CLxIfc_StackFilter : public CLxInterface
{
    static const char *
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_StackFilter, loc);
    return loc->filt_Type ();
  }
    static unsigned
  Compare (LXtObjectID wcom, LXtObjectID other)
  {
    LXCWxINST (CLxImpl_StackFilter, loc);
    return loc->filt_Compare ((ILxUnknownID)other);
  }
    static LxResult
  Convert (LXtObjectID wcom, LXtObjectID other)
  {
    LXCWxINST (CLxImpl_StackFilter, loc);
    try {
      return loc->filt_Convert ((ILxUnknownID)other);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Identifier (LXtObjectID wcom, const char **identifier)
  {
    LXCWxINST (CLxImpl_StackFilter, loc);
    try {
      return loc->filt_Identifier (identifier);
    } catch (LxResult rc) { return rc; }
  }
  ILxStackFilter vt;
public:
  CLxIfc_StackFilter ()
  {
    vt.Type = Type;
    vt.Compare = Compare;
    vt.Convert = Convert;
    vt.Identifier = Identifier;
    vTable = &vt.iunk;
    iid = &lx::guid_StackFilter;
  }
};
class CLxLoc_StackFilter : public CLxLocalize<ILxStackFilterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StackFilter() {_init();}
  CLxLoc_StackFilter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StackFilter(const CLxLoc_StackFilter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StackFilter;}
    const char *
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    unsigned
  Compare (ILxUnknownID other)
  {
    return m_loc[0]->Compare (m_loc,(ILxUnknownID)other);
  }
    LxResult
  Convert (ILxUnknownID other)
  {
    return m_loc[0]->Convert (m_loc,(ILxUnknownID)other);
  }
    LxResult
  Identifier (const char **identifier)
  {
    return m_loc[0]->Identifier (m_loc,identifier);
  }
};

class CLxImpl_CacheData {
  public:
    virtual ~CLxImpl_CacheData() {}
    virtual unsigned int
      cache_Size (void)
        = 0;
};
#define LXxD_CacheData_Size unsigned int cache_Size (void)
#define LXxO_CacheData_Size LXxD_CacheData_Size LXx_OVERRIDE
#define LXxC_CacheData_Size(c) unsigned int c::cache_Size (void)
template <class T>
class CLxIfc_CacheData : public CLxInterface
{
    static unsigned int
  Size (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CacheData, loc);
    return loc->cache_Size ();
  }
  ILxCacheData vt;
public:
  CLxIfc_CacheData ()
  {
    vt.Size = Size;
    vTable = &vt.iunk;
    iid = &lx::guid_CacheData;
  }
};
class CLxLoc_CacheData : public CLxLocalize<ILxCacheDataID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CacheData() {_init();}
  CLxLoc_CacheData(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CacheData(const CLxLoc_CacheData &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CacheData;}
    unsigned int
  Size (void)
  {
    return m_loc[0]->Size (m_loc);
  }
};


class CLxLoc_CacheService : public CLxLocalizedService
{
public:
  ILxCacheServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_CacheService() {_init();set();}
 ~CLxLoc_CacheService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxCacheServiceID>(lx::GetGlobal(&lx::guid_CacheService));}
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
  Register (const char *name)
  {
    return m_loc[0]->Register (m_loc,name);
  }
    void
  Release (const char *name)
  {
    m_loc[0]->Release (m_loc,name);
  }
    LxResult
  GetData (const char *name, unsigned int key, void **ppvObj)
  {
    return m_loc[0]->GetData (m_loc,name,key,ppvObj);
  }
    CLxResult
  GetData (const char *name, unsigned int key, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetData(m_loc,name,key,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetData (const char *name, unsigned int key, ILxUnknownID data)
  {
    return m_loc[0]->SetData (m_loc,name,key,(ILxUnknownID)data);
  }
    void
  PurgeData (const char *name)
  {
    m_loc[0]->PurgeData (m_loc,name);
  }
};

#endif

