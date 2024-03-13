/*
 * C++ wrapper for lxmessage.h
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
#ifndef LXW_MESSAGE_HPP
#define LXW_MESSAGE_HPP

#include <lxmessage.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_MessageService = {0x86A69B5D,0xACFA,0x11D9,0xB3,0x8C,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_AutoSaveListener = {0x04f41d4e,0x7267,0x430e,0x81,0xf4,0xa8,0x98,0x96,0xbf,0x74,0x6c};
};

class CLxLoc_MessageService : public CLxLocalizedService
{
public:
  ILxMessageServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_MessageService() {_init();set();}
 ~CLxLoc_MessageService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxMessageServiceID>(lx::GetGlobal(&lx::guid_MessageService));}
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
  Allocate (void **ppvObj)
  {
    return m_loc[0]->Allocate (m_loc,ppvObj);
  }
    CLxResult
  Allocate (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Allocate(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Duplicate (ILxUnknownID msg, void **ppvObj)
  {
    return m_loc[0]->Duplicate (m_loc,(ILxUnknownID)msg,ppvObj);
  }
    CLxResult
  Duplicate (ILxUnknownID msg, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Duplicate(m_loc,(ILxUnknownID)msg,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  MessageText (ILxUnknownID msg, char *buf, unsigned len)
  {
    return m_loc[0]->MessageText (m_loc,(ILxUnknownID)msg,buf,len);
  }
    LxResult
  MessageText (ILxUnknownID msg, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->MessageText (m_loc,(ILxUnknownID)msg,buf,len);
    LXWx_SBUF2
  }
    LxResult
  RawText (const char *table, const char *msg, const char **text)
  {
    return m_loc[0]->RawText (m_loc,table,msg,text);
  }
    LxResult
  ArgTypeUserName (const char *argType, char *buf, unsigned len)
  {
    return m_loc[0]->ArgTypeUserName (m_loc,argType,buf,len);
  }
    LxResult
  ArgTypeUserName (const char *argType, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ArgTypeUserName (m_loc,argType,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ArgTypeDesc (const char *argType, char *buf, unsigned len)
  {
    return m_loc[0]->ArgTypeDesc (m_loc,argType,buf,len);
  }
    LxResult
  ArgTypeDesc (const char *argType, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ArgTypeDesc (m_loc,argType,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ArgTypeOptionUserName (const char *argType, const char *option, char *buf, unsigned len)
  {
    return m_loc[0]->ArgTypeOptionUserName (m_loc,argType,option,buf,len);
  }
    LxResult
  ArgTypeOptionUserName (const char *argType, const char *option, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ArgTypeOptionUserName (m_loc,argType,option,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ArgTypeOptionDesc (const char *argType, const char *option, char *buf, unsigned len)
  {
    return m_loc[0]->ArgTypeOptionDesc (m_loc,argType,option,buf,len);
  }
    LxResult
  ArgTypeOptionDesc (const char *argType, const char *option, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ArgTypeOptionDesc (m_loc,argType,option,buf,len);
    LXWx_SBUF2
  }
    LxResult
  MessageTextRich (ILxUnknownID msg, char *buf, unsigned len)
  {
    return m_loc[0]->MessageTextRich (m_loc,(ILxUnknownID)msg,buf,len);
  }
    LxResult
  MessageTextRich (ILxUnknownID msg, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->MessageTextRich (m_loc,(ILxUnknownID)msg,buf,len);
    LXWx_SBUF2
  }
    LxResult
  RawTextRich (const char *table, const char *msg, const char **text)
  {
    return m_loc[0]->RawTextRich (m_loc,table,msg,text);
  }
    LxResult
  StripRichText (const char *string, const char **stripped)
  {
    return m_loc[0]->StripRichText (m_loc,string,stripped);
  }
    LxResult
  StringLookup (const char *table, const char *ident, const char **text)
  {
    return m_loc[0]->StringLookup (m_loc,table,ident,text);
  }
    LxResult
  ArgTypeOptionIconName (const char *argType, const char *option, char *buf, unsigned len)
  {
    return m_loc[0]->ArgTypeOptionIconName (m_loc,argType,option,buf,len);
  }
    LxResult
  ArgTypeOptionIconName (const char *argType, const char *option, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ArgTypeOptionIconName (m_loc,argType,option,buf,len);
    LXWx_SBUF2
  }
};

class CLxImpl_AutoSaveListener {
  public:
    virtual ~CLxImpl_AutoSaveListener() {}
    virtual LxResult
      asl_AutoSaveNow (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_AutoSaveListener_AutoSaveNow LxResult asl_AutoSaveNow (void)
#define LXxO_AutoSaveListener_AutoSaveNow LXxD_AutoSaveListener_AutoSaveNow LXx_OVERRIDE
#define LXxC_AutoSaveListener_AutoSaveNow(c) LxResult c::asl_AutoSaveNow (void)
template <class T>
class CLxIfc_AutoSaveListener : public CLxInterface
{
    static LxResult
  AutoSaveNow (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AutoSaveListener, loc);
    try {
      return loc->asl_AutoSaveNow ();
    } catch (LxResult rc) { return rc; }
  }
  ILxAutoSaveListener vt;
public:
  CLxIfc_AutoSaveListener ()
  {
    vt.AutoSaveNow = AutoSaveNow;
    vTable = &vt.iunk;
    iid = &lx::guid_AutoSaveListener;
  }
};
class CLxLoc_AutoSaveListener : public CLxLocalize<ILxAutoSaveListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AutoSaveListener() {_init();}
  CLxLoc_AutoSaveListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AutoSaveListener(const CLxLoc_AutoSaveListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AutoSaveListener;}
    LxResult
  AutoSaveNow (void)
  {
    return m_loc[0]->AutoSaveNow (m_loc);
  }
};

#endif

