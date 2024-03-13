/*
 * C++ wrapper for lxcom.h
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
#ifndef LXW_COM_HPP
#define LXW_COM_HPP

#include <lxcom.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_GUIDService = {0xB11826F1,0xA6BC,0x48B4,0x90,0x9B,0x5F,0x6D,0x01,0x93,0x83,0x27};
    static const LXtGUID guid_Object = {0x222986AB,0xFA71,0x4188,0xBF,0xB3,0xEE,0xB3,0xD5,0x03,0xAE,0x6F};
};


class CLxLoc_GUIDService : public CLxLocalizedService
{
public:
  ILxGUIDServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_GUIDService() {_init();set();}
 ~CLxLoc_GUIDService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxGUIDServiceID>(lx::GetGlobal(&lx::guid_GUIDService));}
    const LXtGUID *
  Translate (const char *guidStr)
  {
    return m_loc[0]->Translate (m_loc,guidStr);
  }
    const char *
  GetName (const LXtGUID *guid)
  {
    return m_loc[0]->GetName (m_loc,guid);
  }
    int
  Compare (const LXtGUID *guid1, const LXtGUID *guid2)
  {
    return m_loc[0]->Compare (m_loc,guid1,guid2);
  }
    const LXtGUID *
  Fixed (const LXtGUID *guid)
  {
    return m_loc[0]->Fixed (m_loc,guid);
  }
    const LXtGUID *
  Class (const LXtGUID *guid)
  {
    return m_loc[0]->Class (m_loc,guid);
  }
    const char *
  ClassName (const LXtGUID *guid)
  {
    return m_loc[0]->ClassName (m_loc,guid);
  }
};

class CLxImpl_Object {
  public:
    virtual ~CLxImpl_Object() {}
    virtual LxResult
      obj_Identifier (const char **id)
        { return LXe_NOTIMPL; }
    virtual LxResult
      obj_InterfaceCount (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      obj_InterfaceByIndex (unsigned int index, const LXtGUID **guid)
        { return LXe_NOTIMPL; }
    virtual void
      obj_AddObserver (ILxUnknownID visitor)
        { }
    virtual void
      obj_RemoveObserver (ILxUnknownID visitor)
        { }
};
#define LXxD_Object_Identifier LxResult obj_Identifier (const char **id)
#define LXxO_Object_Identifier LXxD_Object_Identifier LXx_OVERRIDE
#define LXxC_Object_Identifier(c) LxResult c::obj_Identifier (const char **id)
#define LXxD_Object_InterfaceCount LxResult obj_InterfaceCount (unsigned int *count)
#define LXxO_Object_InterfaceCount LXxD_Object_InterfaceCount LXx_OVERRIDE
#define LXxC_Object_InterfaceCount(c) LxResult c::obj_InterfaceCount (unsigned int *count)
#define LXxD_Object_InterfaceByIndex LxResult obj_InterfaceByIndex (unsigned int index, const LXtGUID **guid)
#define LXxO_Object_InterfaceByIndex LXxD_Object_InterfaceByIndex LXx_OVERRIDE
#define LXxC_Object_InterfaceByIndex(c) LxResult c::obj_InterfaceByIndex (unsigned int index, const LXtGUID **guid)
#define LXxD_Object_AddObserver void obj_AddObserver (ILxUnknownID visitor)
#define LXxO_Object_AddObserver LXxD_Object_AddObserver LXx_OVERRIDE
#define LXxC_Object_AddObserver(c) void c::obj_AddObserver (ILxUnknownID visitor)
#define LXxD_Object_RemoveObserver void obj_RemoveObserver (ILxUnknownID visitor)
#define LXxO_Object_RemoveObserver LXxD_Object_RemoveObserver LXx_OVERRIDE
#define LXxC_Object_RemoveObserver(c) void c::obj_RemoveObserver (ILxUnknownID visitor)
template <class T>
class CLxIfc_Object : public CLxInterface
{
    static LxResult
  Identifier (LXtObjectID wcom, const char **id)
  {
    LXCWxINST (CLxImpl_Object, loc);
    try {
      return loc->obj_Identifier (id);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  InterfaceCount (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_Object, loc);
    try {
      return loc->obj_InterfaceCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  InterfaceByIndex (LXtObjectID wcom, unsigned int index, const LXtGUID **guid)
  {
    LXCWxINST (CLxImpl_Object, loc);
    try {
      return loc->obj_InterfaceByIndex (index,guid);
    } catch (LxResult rc) { return rc; }
  }
    static void
  AddObserver (LXtObjectID wcom, LXtObjectID visitor)
  {
    LXCWxINST (CLxImpl_Object, loc);
    loc->obj_AddObserver ((ILxUnknownID)visitor);
  }
    static void
  RemoveObserver (LXtObjectID wcom, LXtObjectID visitor)
  {
    LXCWxINST (CLxImpl_Object, loc);
    loc->obj_RemoveObserver ((ILxUnknownID)visitor);
  }
  ILxObject vt;
public:
  CLxIfc_Object ()
  {
    vt.Identifier = Identifier;
    vt.InterfaceCount = InterfaceCount;
    vt.InterfaceByIndex = InterfaceByIndex;
    vt.AddObserver = AddObserver;
    vt.RemoveObserver = RemoveObserver;
    vTable = &vt.iunk;
    iid = &lx::guid_Object;
  }
};
class CLxLoc_Object : public CLxLocalize<ILxObjectID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Object() {_init();}
  CLxLoc_Object(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Object(const CLxLoc_Object &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Object;}
    LxResult
  Identifier (const char **id)
  {
    return m_loc[0]->Identifier (m_loc,id);
  }
    LxResult
  InterfaceCount (unsigned int *count)
  {
    return m_loc[0]->InterfaceCount (m_loc,count);
  }
    LxResult
  InterfaceByIndex (unsigned int index, const LXtGUID **guid)
  {
    return m_loc[0]->InterfaceByIndex (m_loc,index,guid);
  }
    void
  AddObserver (ILxUnknownID visitor)
  {
    m_loc[0]->AddObserver (m_loc,(ILxUnknownID)visitor);
  }
    void
  RemoveObserver (ILxUnknownID visitor)
  {
    m_loc[0]->RemoveObserver (m_loc,(ILxUnknownID)visitor);
  }
};

#endif

