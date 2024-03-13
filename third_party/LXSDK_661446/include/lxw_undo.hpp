/*
 * C++ wrapper for lxundo.h
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
#ifndef LXW_UNDO_HPP
#define LXW_UNDO_HPP

#include <lxundo.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_UndoService = {0xD8CA1EC8,0xF6A0,0x463E,0xAB,0x82,0x94,0x78,0xA2,0x81,0xB2,0xCB};
    static const LXtGUID guid_Undo = {0x17FF7DDF,0x6F9B,0x47F1,0x83,0x35,0x57,0xA4,0x1D,0xB3,0xD3,0xAD};
};

class CLxLoc_UndoService : public CLxLocalizedService
{
public:
  ILxUndoServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_UndoService() {_init();set();}
 ~CLxLoc_UndoService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxUndoServiceID>(lx::GetGlobal(&lx::guid_UndoService));}
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
    unsigned int
  State (void)
  {
    return m_loc[0]->State (m_loc);
  }
    LxResult
  Apply (ILxUnknownID undo)
  {
    return m_loc[0]->Apply (m_loc,(ILxUnknownID)undo);
  }
    LxResult
  Record (ILxUnknownID undo)
  {
    return m_loc[0]->Record (m_loc,(ILxUnknownID)undo);
  }
};

class CLxImpl_Undo {
  public:
    virtual ~CLxImpl_Undo() {}
    virtual void
      undo_Forward (void)
        { }
    virtual void
      undo_Reverse (void)
        { }
};
#define LXxD_Undo_Forward void undo_Forward (void)
#define LXxO_Undo_Forward LXxD_Undo_Forward LXx_OVERRIDE
#define LXxC_Undo_Forward(c) void c::undo_Forward (void)
#define LXxD_Undo_Reverse void undo_Reverse (void)
#define LXxO_Undo_Reverse LXxD_Undo_Reverse LXx_OVERRIDE
#define LXxC_Undo_Reverse(c) void c::undo_Reverse (void)
template <class T>
class CLxIfc_Undo : public CLxInterface
{
    static void
  Forward (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Undo, loc);
    loc->undo_Forward ();
  }
    static void
  Reverse (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Undo, loc);
    loc->undo_Reverse ();
  }
  ILxUndo vt;
public:
  CLxIfc_Undo ()
  {
    vt.Forward = Forward;
    vt.Reverse = Reverse;
    vTable = &vt.iunk;
    iid = &lx::guid_Undo;
  }
};
class CLxLoc_Undo : public CLxLocalize<ILxUndoID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Undo() {_init();}
  CLxLoc_Undo(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Undo(const CLxLoc_Undo &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Undo;}
    void
  Forward (void)
  {
    m_loc[0]->Forward (m_loc);
  }
    void
  Reverse (void)
  {
    m_loc[0]->Reverse (m_loc);
  }
};

#endif

