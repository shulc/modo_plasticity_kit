/*
 * C++ wrapper for lxdrop.h
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
#ifndef LXW_DROP_HPP
#define LXW_DROP_HPP

#include <lxdrop.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_Drop1 = {0xabea8de3,0xd821,0x4437,0x88,0xb3,0x05,0xf2,0x02,0x76,0xff,0xeb};
    static const LXtGUID guid_AddDropAction = {0x05C3FF8F,0x5C3C,0x4463,0xAF,0x6E,0x43,0x9C,0x52,0x62,0x1D,0xCA};
    static const LXtGUID guid_Drop = {0xca3c0d04,0x5ebe,0x40a7,0xbb,0x1a,0xd3,0x84,0x88,0xc7,0x96,0x7d};
    static const LXtGUID guid_DropService = {0x44345a07,0x014c,0x4deb,0xab,0xa8,0x8a,0x31,0x47,0xbb,0xa2,0x12};
    static const LXtGUID guid_DropPreviewDefault = {0xf3823495,0xd23f,0x448f,0xa5,0xdd,0x16,0xa1,0x76,0x14,0x45,0xa0};
};

class CLxImpl_Drop1 {
  public:
    virtual ~CLxImpl_Drop1() {}
    virtual LxResult
      drop1_Recognize (ILxUnknownID source)
        { return LXe_NOTIMPL; }
    virtual LxResult
      drop1_ActionList (ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction)
        { return LXe_NOTIMPL; }
    virtual LxResult
      drop1_Drop (ILxUnknownID source, ILxUnknownID dest, int action)
        { return LXe_NOTIMPL; }
};
#define LXxD_Drop1_Recognize LxResult drop1_Recognize (ILxUnknownID source)
#define LXxO_Drop1_Recognize LXxD_Drop1_Recognize LXx_OVERRIDE
#define LXxC_Drop1_Recognize(c) LxResult c::drop1_Recognize (ILxUnknownID source)
#define LXxD_Drop1_ActionList LxResult drop1_ActionList (ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction)
#define LXxO_Drop1_ActionList LXxD_Drop1_ActionList LXx_OVERRIDE
#define LXxC_Drop1_ActionList(c) LxResult c::drop1_ActionList (ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction)
#define LXxD_Drop1_Drop LxResult drop1_Drop (ILxUnknownID source, ILxUnknownID dest, int action)
#define LXxO_Drop1_Drop LXxD_Drop1_Drop LXx_OVERRIDE
#define LXxC_Drop1_Drop(c) LxResult c::drop1_Drop (ILxUnknownID source, ILxUnknownID dest, int action)
template <class T>
class CLxIfc_Drop1 : public CLxInterface
{
    static LxResult
  Recognize (LXtObjectID wcom, LXtObjectID source)
  {
    LXCWxINST (CLxImpl_Drop1, loc);
    try {
      return loc->drop1_Recognize ((ILxUnknownID)source);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ActionList (LXtObjectID wcom, LXtObjectID source, LXtObjectID dest, LXtObjectID addDropAction)
  {
    LXCWxINST (CLxImpl_Drop1, loc);
    try {
      return loc->drop1_ActionList ((ILxUnknownID)source,(ILxUnknownID)dest,(ILxUnknownID)addDropAction);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Drop (LXtObjectID wcom, LXtObjectID source, LXtObjectID dest, int action)
  {
    LXCWxINST (CLxImpl_Drop1, loc);
    try {
      return loc->drop1_Drop ((ILxUnknownID)source,(ILxUnknownID)dest,action);
    } catch (LxResult rc) { return rc; }
  }
  ILxDrop1 vt;
public:
  CLxIfc_Drop1 ()
  {
    vt.Recognize = Recognize;
    vt.ActionList = ActionList;
    vt.Drop = Drop;
    vTable = &vt.iunk;
    iid = &lx::guid_Drop1;
  }
};
class CLxLoc_Drop1 : public CLxLocalize<ILxDrop1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Drop1() {_init();}
  CLxLoc_Drop1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Drop1(const CLxLoc_Drop1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Drop1;}
    LxResult
  Recognize (ILxUnknownID source)
  {
    return m_loc[0]->Recognize (m_loc,(ILxUnknownID)source);
  }
    LxResult
  ActionList (ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction)
  {
    return m_loc[0]->ActionList (m_loc,(ILxUnknownID)source,(ILxUnknownID)dest,(ILxUnknownID)addDropAction);
  }
    LxResult
  Drop (ILxUnknownID source, ILxUnknownID dest, int action)
  {
    return m_loc[0]->Drop (m_loc,(ILxUnknownID)source,(ILxUnknownID)dest,action);
  }
};

class CLxLoc_AddDropAction : public CLxLocalize<ILxAddDropActionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AddDropAction() {_init();}
  CLxLoc_AddDropAction(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AddDropAction(const CLxLoc_AddDropAction &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AddDropAction;}
    LxResult
  AddAction (int action, const char *message)
  {
    return m_loc[0]->AddAction (m_loc,action,message);
  }
    LxResult
  Peek (void **ppvObj)
  {
    return m_loc[0]->Peek (m_loc,ppvObj);
  }
    CLxResult
  Peek (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Peek(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_Drop {
  public:
    virtual ~CLxImpl_Drop() {}
    virtual LxResult
      drop_Recognize (ILxUnknownID source)
        { return LXe_NOTIMPL; }
    virtual LxResult
      drop_ActionList (ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction)
        { return LXe_NOTIMPL; }
    virtual LxResult
      drop_Preview (ILxUnknownID source, ILxUnknownID dest, int action, ILxUnknownID draw)
        { return LXe_NOTIMPL; }
    virtual LxResult
      drop_Drop (ILxUnknownID source, ILxUnknownID dest, int action)
        { return LXe_NOTIMPL; }
};
#define LXxD_Drop_Recognize LxResult drop_Recognize (ILxUnknownID source)
#define LXxO_Drop_Recognize LXxD_Drop_Recognize LXx_OVERRIDE
#define LXxC_Drop_Recognize(c) LxResult c::drop_Recognize (ILxUnknownID source)
#define LXxD_Drop_ActionList LxResult drop_ActionList (ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction)
#define LXxO_Drop_ActionList LXxD_Drop_ActionList LXx_OVERRIDE
#define LXxC_Drop_ActionList(c) LxResult c::drop_ActionList (ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction)
#define LXxD_Drop_Preview LxResult drop_Preview (ILxUnknownID source, ILxUnknownID dest, int action, ILxUnknownID draw)
#define LXxO_Drop_Preview LXxD_Drop_Preview LXx_OVERRIDE
#define LXxC_Drop_Preview(c) LxResult c::drop_Preview (ILxUnknownID source, ILxUnknownID dest, int action, ILxUnknownID draw)
#define LXxD_Drop_Drop LxResult drop_Drop (ILxUnknownID source, ILxUnknownID dest, int action)
#define LXxO_Drop_Drop LXxD_Drop_Drop LXx_OVERRIDE
#define LXxC_Drop_Drop(c) LxResult c::drop_Drop (ILxUnknownID source, ILxUnknownID dest, int action)
template <class T>
class CLxIfc_Drop : public CLxInterface
{
    static LxResult
  Recognize (LXtObjectID wcom, LXtObjectID source)
  {
    LXCWxINST (CLxImpl_Drop, loc);
    try {
      return loc->drop_Recognize ((ILxUnknownID)source);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ActionList (LXtObjectID wcom, LXtObjectID source, LXtObjectID dest, LXtObjectID addDropAction)
  {
    LXCWxINST (CLxImpl_Drop, loc);
    try {
      return loc->drop_ActionList ((ILxUnknownID)source,(ILxUnknownID)dest,(ILxUnknownID)addDropAction);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Preview (LXtObjectID wcom, LXtObjectID source, LXtObjectID dest, int action, LXtObjectID draw)
  {
    LXCWxINST (CLxImpl_Drop, loc);
    try {
      return loc->drop_Preview ((ILxUnknownID)source,(ILxUnknownID)dest,action,(ILxUnknownID)draw);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Drop (LXtObjectID wcom, LXtObjectID source, LXtObjectID dest, int action)
  {
    LXCWxINST (CLxImpl_Drop, loc);
    try {
      return loc->drop_Drop ((ILxUnknownID)source,(ILxUnknownID)dest,action);
    } catch (LxResult rc) { return rc; }
  }
  ILxDrop vt;
public:
  CLxIfc_Drop ()
  {
    vt.Recognize = Recognize;
    vt.ActionList = ActionList;
    vt.Preview = Preview;
    vt.Drop = Drop;
    vTable = &vt.iunk;
    iid = &lx::guid_Drop;
  }
};
class CLxLoc_Drop : public CLxLocalize<ILxDropID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Drop() {_init();}
  CLxLoc_Drop(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Drop(const CLxLoc_Drop &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Drop;}
    LxResult
  Recognize (ILxUnknownID source)
  {
    return m_loc[0]->Recognize (m_loc,(ILxUnknownID)source);
  }
    LxResult
  ActionList (ILxUnknownID source, ILxUnknownID dest, ILxUnknownID addDropAction)
  {
    return m_loc[0]->ActionList (m_loc,(ILxUnknownID)source,(ILxUnknownID)dest,(ILxUnknownID)addDropAction);
  }
    LxResult
  Preview (ILxUnknownID source, ILxUnknownID dest, int action, ILxUnknownID draw)
  {
    return m_loc[0]->Preview (m_loc,(ILxUnknownID)source,(ILxUnknownID)dest,action,(ILxUnknownID)draw);
  }
    LxResult
  Drop (ILxUnknownID source, ILxUnknownID dest, int action)
  {
    return m_loc[0]->Drop (m_loc,(ILxUnknownID)source,(ILxUnknownID)dest,action);
  }
};

class CLxLoc_DropService : public CLxLocalizedService
{
public:
  ILxDropServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_DropService() {_init();set();}
 ~CLxLoc_DropService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxDropServiceID>(lx::GetGlobal(&lx::guid_DropService));}
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
  Destination (void **ppvObj)
  {
    return m_loc[0]->Destination (m_loc,ppvObj);
  }
    CLxResult
  Destination (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Destination(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Source (const char **sourceType, void **ppvObj)
  {
    return m_loc[0]->Source (m_loc,sourceType,ppvObj);
  }
    CLxResult
  Source (const char **sourceType, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Source(m_loc,sourceType,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Action (const char **serverName, int *actionCode)
  {
    return m_loc[0]->Action (m_loc,serverName,actionCode);
  }
};

class CLxLoc_DropPreviewDefault : public CLxLocalize<ILxDropPreviewDefaultID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DropPreviewDefault() {_init();}
  CLxLoc_DropPreviewDefault(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DropPreviewDefault(const CLxLoc_DropPreviewDefault &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DropPreviewDefault;}
    LxResult
  Draw (void)
  {
    return m_loc[0]->Draw (m_loc);
  }
};

#endif

