/*
 * C++ wrapper for lxtree.h
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
#ifndef LXW_TREE_HPP
#define LXW_TREE_HPP

#include <lxtree.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_TreeListener = {0x200fe1a6,0xc764,0x42f7,0x91,0x7f,0x04,0x4a,0x0f,0x58,0xe0,0x07};
    static const LXtGUID guid_TreeListener1 = {0xEB38EE07,0x0E35,0x455F,0xA5,0x70,0xF4,0xAF,0x31,0x34,0x94,0xFD};
    static const LXtGUID guid_Tree = {0xE61F3BA6,0xB9E8,0x41B8,0x8A,0x61,0x3F,0x78,0xCB,0xC7,0x9E,0x98};
};

class CLxImpl_TreeListener {
  public:
    virtual ~CLxImpl_TreeListener() {}
    virtual LxResult
      tlis_NewAttributes (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tlis_NewShape (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tlis_NewSpaceForThumbnails (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tlis_ClearCachedThumbnail (const char *ident)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tlis_ClearAllCachedThumbnails (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tlis_NewShowDescriptionText (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_TreeListener_NewAttributes LxResult tlis_NewAttributes (void)
#define LXxO_TreeListener_NewAttributes LXxD_TreeListener_NewAttributes LXx_OVERRIDE
#define LXxC_TreeListener_NewAttributes(c) LxResult c::tlis_NewAttributes (void)
#define LXxD_TreeListener_NewShape LxResult tlis_NewShape (void)
#define LXxO_TreeListener_NewShape LXxD_TreeListener_NewShape LXx_OVERRIDE
#define LXxC_TreeListener_NewShape(c) LxResult c::tlis_NewShape (void)
#define LXxD_TreeListener_NewSpaceForThumbnails LxResult tlis_NewSpaceForThumbnails (void)
#define LXxO_TreeListener_NewSpaceForThumbnails LXxD_TreeListener_NewSpaceForThumbnails LXx_OVERRIDE
#define LXxC_TreeListener_NewSpaceForThumbnails(c) LxResult c::tlis_NewSpaceForThumbnails (void)
#define LXxD_TreeListener_ClearCachedThumbnail LxResult tlis_ClearCachedThumbnail (const char *ident)
#define LXxO_TreeListener_ClearCachedThumbnail LXxD_TreeListener_ClearCachedThumbnail LXx_OVERRIDE
#define LXxC_TreeListener_ClearCachedThumbnail(c) LxResult c::tlis_ClearCachedThumbnail (const char *ident)
#define LXxD_TreeListener_ClearAllCachedThumbnails LxResult tlis_ClearAllCachedThumbnails (void)
#define LXxO_TreeListener_ClearAllCachedThumbnails LXxD_TreeListener_ClearAllCachedThumbnails LXx_OVERRIDE
#define LXxC_TreeListener_ClearAllCachedThumbnails(c) LxResult c::tlis_ClearAllCachedThumbnails (void)
#define LXxD_TreeListener_NewShowDescriptionText LxResult tlis_NewShowDescriptionText (void)
#define LXxO_TreeListener_NewShowDescriptionText LXxD_TreeListener_NewShowDescriptionText LXx_OVERRIDE
#define LXxC_TreeListener_NewShowDescriptionText(c) LxResult c::tlis_NewShowDescriptionText (void)
template <class T>
class CLxIfc_TreeListener : public CLxInterface
{
    static LxResult
  NewAttributes (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeListener, loc);
    try {
      return loc->tlis_NewAttributes ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NewShape (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeListener, loc);
    try {
      return loc->tlis_NewShape ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NewSpaceForThumbnails (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeListener, loc);
    try {
      return loc->tlis_NewSpaceForThumbnails ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ClearCachedThumbnail (LXtObjectID wcom, const char *ident)
  {
    LXCWxINST (CLxImpl_TreeListener, loc);
    try {
      return loc->tlis_ClearCachedThumbnail (ident);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ClearAllCachedThumbnails (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeListener, loc);
    try {
      return loc->tlis_ClearAllCachedThumbnails ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NewShowDescriptionText (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeListener, loc);
    try {
      return loc->tlis_NewShowDescriptionText ();
    } catch (LxResult rc) { return rc; }
  }
  ILxTreeListener vt;
public:
  CLxIfc_TreeListener ()
  {
    vt.NewAttributes = NewAttributes;
    vt.NewShape = NewShape;
    vt.NewSpaceForThumbnails = NewSpaceForThumbnails;
    vt.ClearCachedThumbnail = ClearCachedThumbnail;
    vt.ClearAllCachedThumbnails = ClearAllCachedThumbnails;
    vt.NewShowDescriptionText = NewShowDescriptionText;
    vTable = &vt.iunk;
    iid = &lx::guid_TreeListener;
  }
};
class CLxLoc_TreeListener : public CLxLocalize<ILxTreeListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TreeListener() {_init();}
  CLxLoc_TreeListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TreeListener(const CLxLoc_TreeListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TreeListener;}
    LxResult
  NewAttributes (void)
  {
    return m_loc[0]->NewAttributes (m_loc);
  }
    LxResult
  NewShape (void)
  {
    return m_loc[0]->NewShape (m_loc);
  }
    LxResult
  NewSpaceForThumbnails (void)
  {
    return m_loc[0]->NewSpaceForThumbnails (m_loc);
  }
    LxResult
  ClearCachedThumbnail (const char *ident)
  {
    return m_loc[0]->ClearCachedThumbnail (m_loc,ident);
  }
    LxResult
  ClearAllCachedThumbnails (void)
  {
    return m_loc[0]->ClearAllCachedThumbnails (m_loc);
  }
    LxResult
  NewShowDescriptionText (void)
  {
    return m_loc[0]->NewShowDescriptionText (m_loc);
  }
};

class CLxImpl_TreeListener1 {
  public:
    virtual ~CLxImpl_TreeListener1() {}
    virtual LxResult
      tlis_NewAttributes (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tlis_NewShape (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_TreeListener1_NewAttributes LxResult tlis_NewAttributes (void)
#define LXxO_TreeListener1_NewAttributes LXxD_TreeListener1_NewAttributes LXx_OVERRIDE
#define LXxC_TreeListener1_NewAttributes(c) LxResult c::tlis_NewAttributes (void)
#define LXxD_TreeListener1_NewShape LxResult tlis_NewShape (void)
#define LXxO_TreeListener1_NewShape LXxD_TreeListener1_NewShape LXx_OVERRIDE
#define LXxC_TreeListener1_NewShape(c) LxResult c::tlis_NewShape (void)
template <class T>
class CLxIfc_TreeListener1 : public CLxInterface
{
    static LxResult
  NewAttributes (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeListener1, loc);
    try {
      return loc->tlis_NewAttributes ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NewShape (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeListener1, loc);
    try {
      return loc->tlis_NewShape ();
    } catch (LxResult rc) { return rc; }
  }
  ILxTreeListener1 vt;
public:
  CLxIfc_TreeListener1 ()
  {
    vt.NewAttributes = NewAttributes;
    vt.NewShape = NewShape;
    vTable = &vt.iunk;
    iid = &lx::guid_TreeListener1;
  }
};
class CLxLoc_TreeListener1 : public CLxLocalize<ILxTreeListener1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TreeListener1() {_init();}
  CLxLoc_TreeListener1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TreeListener1(const CLxLoc_TreeListener1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TreeListener1;}
    LxResult
  NewAttributes (void)
  {
    return m_loc[0]->NewAttributes (m_loc);
  }
    LxResult
  NewShape (void)
  {
    return m_loc[0]->NewShape (m_loc);
  }
};

class CLxImpl_Tree {
  public:
    virtual ~CLxImpl_Tree() {}
    virtual LxResult
      tree_Spawn (unsigned mode, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tree_ToParent (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tree_ToChild (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tree_ToRoot (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tree_IsRoot (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tree_ChildIsLeaf (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tree_Count (unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tree_Current (unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tree_SetCurrent (unsigned index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tree_ItemState (const char *guid, int *state)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tree_SetItemState (const char *guid, int state)
        { return LXe_NOTIMPL; }
};
#define LXxD_Tree_Spawn LxResult tree_Spawn (unsigned mode, void **ppvObj)
#define LXxO_Tree_Spawn LXxD_Tree_Spawn LXx_OVERRIDE
#define LXxC_Tree_Spawn(c) LxResult c::tree_Spawn (unsigned mode, void **ppvObj)
#define LXxD_Tree_ToParent LxResult tree_ToParent (void)
#define LXxO_Tree_ToParent LXxD_Tree_ToParent LXx_OVERRIDE
#define LXxC_Tree_ToParent(c) LxResult c::tree_ToParent (void)
#define LXxD_Tree_ToChild LxResult tree_ToChild (void)
#define LXxO_Tree_ToChild LXxD_Tree_ToChild LXx_OVERRIDE
#define LXxC_Tree_ToChild(c) LxResult c::tree_ToChild (void)
#define LXxD_Tree_ToRoot LxResult tree_ToRoot (void)
#define LXxO_Tree_ToRoot LXxD_Tree_ToRoot LXx_OVERRIDE
#define LXxC_Tree_ToRoot(c) LxResult c::tree_ToRoot (void)
#define LXxD_Tree_IsRoot LxResult tree_IsRoot (void)
#define LXxO_Tree_IsRoot LXxD_Tree_IsRoot LXx_OVERRIDE
#define LXxC_Tree_IsRoot(c) LxResult c::tree_IsRoot (void)
#define LXxD_Tree_ChildIsLeaf LxResult tree_ChildIsLeaf (void)
#define LXxO_Tree_ChildIsLeaf LXxD_Tree_ChildIsLeaf LXx_OVERRIDE
#define LXxC_Tree_ChildIsLeaf(c) LxResult c::tree_ChildIsLeaf (void)
#define LXxD_Tree_Count LxResult tree_Count (unsigned *count)
#define LXxO_Tree_Count LXxD_Tree_Count LXx_OVERRIDE
#define LXxC_Tree_Count(c) LxResult c::tree_Count (unsigned *count)
#define LXxD_Tree_Current LxResult tree_Current (unsigned *index)
#define LXxO_Tree_Current LXxD_Tree_Current LXx_OVERRIDE
#define LXxC_Tree_Current(c) LxResult c::tree_Current (unsigned *index)
#define LXxD_Tree_SetCurrent LxResult tree_SetCurrent (unsigned index)
#define LXxO_Tree_SetCurrent LXxD_Tree_SetCurrent LXx_OVERRIDE
#define LXxC_Tree_SetCurrent(c) LxResult c::tree_SetCurrent (unsigned index)
#define LXxD_Tree_ItemState LxResult tree_ItemState (const char *guid, int *state)
#define LXxO_Tree_ItemState LXxD_Tree_ItemState LXx_OVERRIDE
#define LXxC_Tree_ItemState(c) LxResult c::tree_ItemState (const char *guid, int *state)
#define LXxD_Tree_SetItemState LxResult tree_SetItemState (const char *guid, int state)
#define LXxO_Tree_SetItemState LXxD_Tree_SetItemState LXx_OVERRIDE
#define LXxC_Tree_SetItemState(c) LxResult c::tree_SetItemState (const char *guid, int state)
template <class T>
class CLxIfc_Tree : public CLxInterface
{
    static LxResult
  Spawn (LXtObjectID wcom, unsigned mode, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_Spawn (mode,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToParent (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_ToParent ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToChild (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_ToChild ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToRoot (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_ToRoot ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsRoot (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_IsRoot ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChildIsLeaf (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_ChildIsLeaf ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Count (LXtObjectID wcom, unsigned *count)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_Count (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Current (LXtObjectID wcom, unsigned *index)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_Current (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetCurrent (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_SetCurrent (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemState (LXtObjectID wcom, const char *guid, int *state)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_ItemState (guid,state);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetItemState (LXtObjectID wcom, const char *guid, int state)
  {
    LXCWxINST (CLxImpl_Tree, loc);
    try {
      return loc->tree_SetItemState (guid,state);
    } catch (LxResult rc) { return rc; }
  }
  ILxTree vt;
public:
  CLxIfc_Tree ()
  {
    vt.Spawn = Spawn;
    vt.ToParent = ToParent;
    vt.ToChild = ToChild;
    vt.ToRoot = ToRoot;
    vt.IsRoot = IsRoot;
    vt.ChildIsLeaf = ChildIsLeaf;
    vt.Count = Count;
    vt.Current = Current;
    vt.SetCurrent = SetCurrent;
    vt.ItemState = ItemState;
    vt.SetItemState = SetItemState;
    vTable = &vt.iunk;
    iid = &lx::guid_Tree;
  }
};
class CLxLoc_Tree : public CLxLocalize<ILxTreeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Tree() {_init();}
  CLxLoc_Tree(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Tree(const CLxLoc_Tree &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Tree;}
    LxResult
  Spawn (unsigned mode, void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,mode,ppvObj);
  }
    CLxResult
  Spawn (unsigned mode, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Spawn(m_loc,mode,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ToParent (void)
  {
    return m_loc[0]->ToParent (m_loc);
  }
    LxResult
  ToChild (void)
  {
    return m_loc[0]->ToChild (m_loc);
  }
    LxResult
  ToRoot (void)
  {
    return m_loc[0]->ToRoot (m_loc);
  }
    LxResult
  IsRoot (void)
  {
    return m_loc[0]->IsRoot (m_loc);
  }
    LxResult
  ChildIsLeaf (void)
  {
    return m_loc[0]->ChildIsLeaf (m_loc);
  }
    LxResult
  Count (unsigned *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  Current (unsigned *index)
  {
    return m_loc[0]->Current (m_loc,index);
  }
    LxResult
  SetCurrent (unsigned index)
  {
    return m_loc[0]->SetCurrent (m_loc,index);
  }
    LxResult
  ItemState (const char *guid, int *state)
  {
    return m_loc[0]->ItemState (m_loc,guid,state);
  }
    LxResult
  SetItemState (const char *guid, int state)
  {
    return m_loc[0]->SetItemState (m_loc,guid,state);
  }
};

#endif

