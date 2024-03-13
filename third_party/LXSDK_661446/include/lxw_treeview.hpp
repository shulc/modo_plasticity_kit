/*
 * C++ wrapper for lxtreeview.h
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
#ifndef LXW_TREEVIEW_HPP
#define LXW_TREEVIEW_HPP

#include <lxtreeview.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_TreeView3 = {0xec0c5d6f,0x9477,0x4bae,0x97,0xe8,0x22,0x05,0xed,0x1c,0xdb,0x23};
    static const LXtGUID guid_TreeView = {0x86e7a5cc,0x9a4b,0x4621,0x9f,0x97,0x99,0x6e,0x6f,0x7f,0x0a,0x62};
    static const LXtGUID guid_TreeView2 = {0x8307d6f1,0xc30b,0x48e7,0xa0,0xee,0xaa,0xb0,0xa4,0x5b,0xcf,0x1d};
    static const LXtGUID guid_TreeView1 = {0xe4b1f6b4,0xfed6,0x4668,0x9b,0x6b,0x95,0x26,0xb5,0x9c,0xd9,0xee};
};

class CLxImpl_TreeView3 {
  public:
    virtual ~CLxImpl_TreeView3() {}
    virtual LxResult
      treeview3_StoreState (const char *uid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_RestoreState (const char *uid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_ColumnCount (unsigned* colCount)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_ColumnJustification (unsigned columnIndex, int *justification)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_PrimaryColumnPosition (unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_ToPrimary (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_IsSelected (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_Select (unsigned mode)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_CellCommand (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_ToolTip (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_IsInputRegion (unsigned columnIndex, unsigned regionID)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview3_IsDescendantSelected (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_TreeView3_StoreState LxResult treeview3_StoreState (const char *uid)
#define LXxO_TreeView3_StoreState LXxD_TreeView3_StoreState LXx_OVERRIDE
#define LXxC_TreeView3_StoreState(c) LxResult c::treeview3_StoreState (const char *uid)
#define LXxD_TreeView3_RestoreState LxResult treeview3_RestoreState (const char *uid)
#define LXxO_TreeView3_RestoreState LXxD_TreeView3_RestoreState LXx_OVERRIDE
#define LXxC_TreeView3_RestoreState(c) LxResult c::treeview3_RestoreState (const char *uid)
#define LXxD_TreeView3_ColumnCount LxResult treeview3_ColumnCount (unsigned* colCount)
#define LXxO_TreeView3_ColumnCount LXxD_TreeView3_ColumnCount LXx_OVERRIDE
#define LXxC_TreeView3_ColumnCount(c) LxResult c::treeview3_ColumnCount (unsigned* colCount)
#define LXxD_TreeView3_ColumnByIndex LxResult treeview3_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
#define LXxO_TreeView3_ColumnByIndex LXxD_TreeView3_ColumnByIndex LXx_OVERRIDE
#define LXxC_TreeView3_ColumnByIndex(c) LxResult c::treeview3_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
#define LXxD_TreeView3_ColumnInternalName LxResult treeview3_ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView3_ColumnInternalName LXxD_TreeView3_ColumnInternalName LXx_OVERRIDE
#define LXxC_TreeView3_ColumnInternalName(c) LxResult c::treeview3_ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView3_ColumnIconResource LxResult treeview3_ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView3_ColumnIconResource LXxD_TreeView3_ColumnIconResource LXx_OVERRIDE
#define LXxC_TreeView3_ColumnIconResource(c) LxResult c::treeview3_ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView3_ColumnJustification LxResult treeview3_ColumnJustification (unsigned columnIndex, int *justification)
#define LXxO_TreeView3_ColumnJustification LXxD_TreeView3_ColumnJustification LXx_OVERRIDE
#define LXxC_TreeView3_ColumnJustification(c) LxResult c::treeview3_ColumnJustification (unsigned columnIndex, int *justification)
#define LXxD_TreeView3_PrimaryColumnPosition LxResult treeview3_PrimaryColumnPosition (unsigned *index)
#define LXxO_TreeView3_PrimaryColumnPosition LXxD_TreeView3_PrimaryColumnPosition LXx_OVERRIDE
#define LXxC_TreeView3_PrimaryColumnPosition(c) LxResult c::treeview3_PrimaryColumnPosition (unsigned *index)
#define LXxD_TreeView3_ToPrimary LxResult treeview3_ToPrimary (void)
#define LXxO_TreeView3_ToPrimary LXxD_TreeView3_ToPrimary LXx_OVERRIDE
#define LXxC_TreeView3_ToPrimary(c) LxResult c::treeview3_ToPrimary (void)
#define LXxD_TreeView3_IsSelected LxResult treeview3_IsSelected (void)
#define LXxO_TreeView3_IsSelected LXxD_TreeView3_IsSelected LXx_OVERRIDE
#define LXxC_TreeView3_IsSelected(c) LxResult c::treeview3_IsSelected (void)
#define LXxD_TreeView3_Select LxResult treeview3_Select (unsigned mode)
#define LXxO_TreeView3_Select LXxD_TreeView3_Select LXx_OVERRIDE
#define LXxC_TreeView3_Select(c) LxResult c::treeview3_Select (unsigned mode)
#define LXxD_TreeView3_CellCommand LxResult treeview3_CellCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView3_CellCommand LXxD_TreeView3_CellCommand LXx_OVERRIDE
#define LXxC_TreeView3_CellCommand(c) LxResult c::treeview3_CellCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView3_BatchCommand LxResult treeview3_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView3_BatchCommand LXxD_TreeView3_BatchCommand LXx_OVERRIDE
#define LXxC_TreeView3_BatchCommand(c) LxResult c::treeview3_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView3_ToolTip LxResult treeview3_ToolTip (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView3_ToolTip LXxD_TreeView3_ToolTip LXx_OVERRIDE
#define LXxC_TreeView3_ToolTip(c) LxResult c::treeview3_ToolTip (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView3_BadgeType LxResult treeview3_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
#define LXxO_TreeView3_BadgeType LXxD_TreeView3_BadgeType LXx_OVERRIDE
#define LXxC_TreeView3_BadgeType(c) LxResult c::treeview3_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
#define LXxD_TreeView3_BadgeDetail LxResult treeview3_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
#define LXxO_TreeView3_BadgeDetail LXxD_TreeView3_BadgeDetail LXx_OVERRIDE
#define LXxC_TreeView3_BadgeDetail(c) LxResult c::treeview3_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
#define LXxD_TreeView3_IsInputRegion LxResult treeview3_IsInputRegion (unsigned columnIndex, unsigned regionID)
#define LXxO_TreeView3_IsInputRegion LXxD_TreeView3_IsInputRegion LXx_OVERRIDE
#define LXxC_TreeView3_IsInputRegion(c) LxResult c::treeview3_IsInputRegion (unsigned columnIndex, unsigned regionID)
#define LXxD_TreeView3_SupportedDragDropSourceTypes LxResult treeview3_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView3_SupportedDragDropSourceTypes LXxD_TreeView3_SupportedDragDropSourceTypes LXx_OVERRIDE
#define LXxC_TreeView3_SupportedDragDropSourceTypes(c) LxResult c::treeview3_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView3_GetDragDropSourceObject LxResult treeview3_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
#define LXxO_TreeView3_GetDragDropSourceObject LXxD_TreeView3_GetDragDropSourceObject LXx_OVERRIDE
#define LXxC_TreeView3_GetDragDropSourceObject(c) LxResult c::treeview3_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
#define LXxD_TreeView3_GetDragDropDestinationObject LxResult treeview3_GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
#define LXxO_TreeView3_GetDragDropDestinationObject LXxD_TreeView3_GetDragDropDestinationObject LXx_OVERRIDE
#define LXxC_TreeView3_GetDragDropDestinationObject(c) LxResult c::treeview3_GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
#define LXxD_TreeView3_IsDescendantSelected LxResult treeview3_IsDescendantSelected (void)
#define LXxO_TreeView3_IsDescendantSelected LXxD_TreeView3_IsDescendantSelected LXx_OVERRIDE
#define LXxC_TreeView3_IsDescendantSelected(c) LxResult c::treeview3_IsDescendantSelected (void)
template <class T>
class CLxIfc_TreeView3 : public CLxInterface
{
    static LxResult
  StoreState (LXtObjectID wcom, const char *uid)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_StoreState (uid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RestoreState (LXtObjectID wcom, const char *uid)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_RestoreState (uid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnCount (LXtObjectID wcom, unsigned* colCount)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_ColumnCount (colCount);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnByIndex (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_ColumnByIndex (columnIndex,buf,len,columnWidth);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnInternalName (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_ColumnInternalName (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnIconResource (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_ColumnIconResource (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnJustification (LXtObjectID wcom, unsigned columnIndex, int *justification)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_ColumnJustification (columnIndex,justification);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PrimaryColumnPosition (LXtObjectID wcom, unsigned *index)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_PrimaryColumnPosition (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToPrimary (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_ToPrimary ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsSelected (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_IsSelected ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Select (LXtObjectID wcom, unsigned mode)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_Select (mode);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CellCommand (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_CellCommand (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BatchCommand (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_BatchCommand (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToolTip (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_ToolTip (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeType (LXtObjectID wcom, unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_BadgeType (columnIndex,badgeIndex,badgeType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeDetail (LXtObjectID wcom, unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_BadgeDetail (columnIndex,badgeIndex,badgeDetail,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsInputRegion (LXtObjectID wcom, unsigned columnIndex, unsigned regionID)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_IsInputRegion (columnIndex,regionID);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SupportedDragDropSourceTypes (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_SupportedDragDropSourceTypes (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetDragDropSourceObject (LXtObjectID wcom, unsigned columnIndex, const char *type, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_GetDragDropSourceObject (columnIndex,type,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetDragDropDestinationObject (LXtObjectID wcom, unsigned columnIndex, unsigned location, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_GetDragDropDestinationObject (columnIndex,location,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsDescendantSelected (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView3, loc);
    try {
      return loc->treeview3_IsDescendantSelected ();
    } catch (LxResult rc) { return rc; }
  }
  ILxTreeView3 vt;
public:
  CLxIfc_TreeView3 ()
  {
    vt.StoreState = StoreState;
    vt.RestoreState = RestoreState;
    vt.ColumnCount = ColumnCount;
    vt.ColumnByIndex = ColumnByIndex;
    vt.ColumnInternalName = ColumnInternalName;
    vt.ColumnIconResource = ColumnIconResource;
    vt.ColumnJustification = ColumnJustification;
    vt.PrimaryColumnPosition = PrimaryColumnPosition;
    vt.ToPrimary = ToPrimary;
    vt.IsSelected = IsSelected;
    vt.Select = Select;
    vt.CellCommand = CellCommand;
    vt.BatchCommand = BatchCommand;
    vt.ToolTip = ToolTip;
    vt.BadgeType = BadgeType;
    vt.BadgeDetail = BadgeDetail;
    vt.IsInputRegion = IsInputRegion;
    vt.SupportedDragDropSourceTypes = SupportedDragDropSourceTypes;
    vt.GetDragDropSourceObject = GetDragDropSourceObject;
    vt.GetDragDropDestinationObject = GetDragDropDestinationObject;
    vt.IsDescendantSelected = IsDescendantSelected;
    vTable = &vt.iunk;
    iid = &lx::guid_TreeView3;
  }
};
class CLxLoc_TreeView3 : public CLxLocalize<ILxTreeView3ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TreeView3() {_init();}
  CLxLoc_TreeView3(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TreeView3(const CLxLoc_TreeView3 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TreeView3;}
    LxResult
  StoreState (const char *uid)
  {
    return m_loc[0]->StoreState (m_loc,uid);
  }
    LxResult
  RestoreState (const char *uid)
  {
    return m_loc[0]->RestoreState (m_loc,uid);
  }
    LxResult
  ColumnCount (unsigned* colCount)
  {
    return m_loc[0]->ColumnCount (m_loc,colCount);
  }
    LxResult
  ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
  {
    return m_loc[0]->ColumnByIndex (m_loc,columnIndex,buf,len,columnWidth);
  }
    LxResult
  ColumnByIndex (unsigned columnIndex, std::string &result, int *columnWidth)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ColumnByIndex (m_loc,columnIndex,buf,len,columnWidth);
    LXWx_SBUF2
  }
    LxResult
  ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->ColumnInternalName (m_loc,columnIndex,buf,len);
  }
    LxResult
  ColumnInternalName (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ColumnInternalName (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->ColumnIconResource (m_loc,columnIndex,buf,len);
  }
    LxResult
  ColumnIconResource (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ColumnIconResource (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ColumnJustification (unsigned columnIndex, int *justification)
  {
    return m_loc[0]->ColumnJustification (m_loc,columnIndex,justification);
  }
    LxResult
  PrimaryColumnPosition (unsigned *index)
  {
    return m_loc[0]->PrimaryColumnPosition (m_loc,index);
  }
    LxResult
  ToPrimary (void)
  {
    return m_loc[0]->ToPrimary (m_loc);
  }
    LxResult
  IsSelected (void)
  {
    return m_loc[0]->IsSelected (m_loc);
  }
    LxResult
  Select (unsigned mode)
  {
    return m_loc[0]->Select (m_loc,mode);
  }
    LxResult
  CellCommand (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->CellCommand (m_loc,columnIndex,buf,len);
  }
    LxResult
  CellCommand (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->CellCommand (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  BatchCommand (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->BatchCommand (m_loc,columnIndex,buf,len);
  }
    LxResult
  BatchCommand (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->BatchCommand (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ToolTip (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->ToolTip (m_loc,columnIndex,buf,len);
  }
    LxResult
  ToolTip (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ToolTip (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
  {
    return m_loc[0]->BadgeType (m_loc,columnIndex,badgeIndex,badgeType);
  }
    LxResult
  BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
  {
    return m_loc[0]->BadgeDetail (m_loc,columnIndex,badgeIndex,badgeDetail,buf,len);
  }
    LxResult
  BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->BadgeDetail (m_loc,columnIndex,badgeIndex,badgeDetail,buf,len);
    LXWx_SBUF2
  }
    LxResult
  IsInputRegion (unsigned columnIndex, unsigned regionID)
  {
    return m_loc[0]->IsInputRegion (m_loc,columnIndex,regionID);
  }
    LxResult
  SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->SupportedDragDropSourceTypes (m_loc,columnIndex,buf,len);
  }
    LxResult
  SupportedDragDropSourceTypes (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->SupportedDragDropSourceTypes (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
  {
    return m_loc[0]->GetDragDropSourceObject (m_loc,columnIndex,type,ppvObj);
  }
    CLxResult
  GetDragDropSourceObject (unsigned columnIndex, const char *type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetDragDropSourceObject(m_loc,columnIndex,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
  {
    return m_loc[0]->GetDragDropDestinationObject (m_loc,columnIndex,location,ppvObj);
  }
    CLxResult
  GetDragDropDestinationObject (unsigned columnIndex, unsigned location, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetDragDropDestinationObject(m_loc,columnIndex,location,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  IsDescendantSelected (void)
  {
    return m_loc[0]->IsDescendantSelected (m_loc);
  }
};

class CLxImpl_TreeView {
  public:
    virtual ~CLxImpl_TreeView() {}
    virtual LxResult
      treeview_StoreState (const char *uid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_RestoreState (const char *uid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_StyleHints (int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_ColumnCount (unsigned* colCount)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_ColumnJustification (unsigned columnIndex, int *justification)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_PrimaryColumnPosition (unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_ToPrimary (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_IsSelected (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_Select (unsigned mode)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_CellCommand (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_ToolTip (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_DescriptionText (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_ShowDescriptionText (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_ReservedSpaceForIcons (int *columnIndex, int *width, int *height, int *iconAsValue)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_IconResource (unsigned columnIndex, int width, int height, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_ReservedSpaceForThumbnails (int *columnIndex, int *width, int *height)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_Thumbnail (unsigned columnIndex, int width, int height, void **ppvObj, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_BadgeType2 (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_IsInputRegion (unsigned columnIndex, unsigned regionID)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_IsDescendantSelected (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_CanFilter (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview_Filter (int *flags)
        { return LXe_NOTIMPL; }
};
#define LXxD_TreeView_StoreState LxResult treeview_StoreState (const char *uid)
#define LXxO_TreeView_StoreState LXxD_TreeView_StoreState LXx_OVERRIDE
#define LXxC_TreeView_StoreState(c) LxResult c::treeview_StoreState (const char *uid)
#define LXxD_TreeView_RestoreState LxResult treeview_RestoreState (const char *uid)
#define LXxO_TreeView_RestoreState LXxD_TreeView_RestoreState LXx_OVERRIDE
#define LXxC_TreeView_RestoreState(c) LxResult c::treeview_RestoreState (const char *uid)
#define LXxD_TreeView_StyleHints LxResult treeview_StyleHints (int *flags)
#define LXxO_TreeView_StyleHints LXxD_TreeView_StyleHints LXx_OVERRIDE
#define LXxC_TreeView_StyleHints(c) LxResult c::treeview_StyleHints (int *flags)
#define LXxD_TreeView_ColumnCount LxResult treeview_ColumnCount (unsigned* colCount)
#define LXxO_TreeView_ColumnCount LXxD_TreeView_ColumnCount LXx_OVERRIDE
#define LXxC_TreeView_ColumnCount(c) LxResult c::treeview_ColumnCount (unsigned* colCount)
#define LXxD_TreeView_ColumnByIndex LxResult treeview_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
#define LXxO_TreeView_ColumnByIndex LXxD_TreeView_ColumnByIndex LXx_OVERRIDE
#define LXxC_TreeView_ColumnByIndex(c) LxResult c::treeview_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
#define LXxD_TreeView_ColumnInternalName LxResult treeview_ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView_ColumnInternalName LXxD_TreeView_ColumnInternalName LXx_OVERRIDE
#define LXxC_TreeView_ColumnInternalName(c) LxResult c::treeview_ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView_ColumnIconResource LxResult treeview_ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView_ColumnIconResource LXxD_TreeView_ColumnIconResource LXx_OVERRIDE
#define LXxC_TreeView_ColumnIconResource(c) LxResult c::treeview_ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView_ColumnJustification LxResult treeview_ColumnJustification (unsigned columnIndex, int *justification)
#define LXxO_TreeView_ColumnJustification LXxD_TreeView_ColumnJustification LXx_OVERRIDE
#define LXxC_TreeView_ColumnJustification(c) LxResult c::treeview_ColumnJustification (unsigned columnIndex, int *justification)
#define LXxD_TreeView_PrimaryColumnPosition LxResult treeview_PrimaryColumnPosition (unsigned *index)
#define LXxO_TreeView_PrimaryColumnPosition LXxD_TreeView_PrimaryColumnPosition LXx_OVERRIDE
#define LXxC_TreeView_PrimaryColumnPosition(c) LxResult c::treeview_PrimaryColumnPosition (unsigned *index)
#define LXxD_TreeView_ToPrimary LxResult treeview_ToPrimary (void)
#define LXxO_TreeView_ToPrimary LXxD_TreeView_ToPrimary LXx_OVERRIDE
#define LXxC_TreeView_ToPrimary(c) LxResult c::treeview_ToPrimary (void)
#define LXxD_TreeView_IsSelected LxResult treeview_IsSelected (void)
#define LXxO_TreeView_IsSelected LXxD_TreeView_IsSelected LXx_OVERRIDE
#define LXxC_TreeView_IsSelected(c) LxResult c::treeview_IsSelected (void)
#define LXxD_TreeView_Select LxResult treeview_Select (unsigned mode)
#define LXxO_TreeView_Select LXxD_TreeView_Select LXx_OVERRIDE
#define LXxC_TreeView_Select(c) LxResult c::treeview_Select (unsigned mode)
#define LXxD_TreeView_CellCommand LxResult treeview_CellCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView_CellCommand LXxD_TreeView_CellCommand LXx_OVERRIDE
#define LXxC_TreeView_CellCommand(c) LxResult c::treeview_CellCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView_BatchCommand LxResult treeview_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView_BatchCommand LXxD_TreeView_BatchCommand LXx_OVERRIDE
#define LXxC_TreeView_BatchCommand(c) LxResult c::treeview_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView_ToolTip LxResult treeview_ToolTip (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView_ToolTip LXxD_TreeView_ToolTip LXx_OVERRIDE
#define LXxC_TreeView_ToolTip(c) LxResult c::treeview_ToolTip (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView_DescriptionText LxResult treeview_DescriptionText (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView_DescriptionText LXxD_TreeView_DescriptionText LXx_OVERRIDE
#define LXxC_TreeView_DescriptionText(c) LxResult c::treeview_DescriptionText (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView_ShowDescriptionText LxResult treeview_ShowDescriptionText (void)
#define LXxO_TreeView_ShowDescriptionText LXxD_TreeView_ShowDescriptionText LXx_OVERRIDE
#define LXxC_TreeView_ShowDescriptionText(c) LxResult c::treeview_ShowDescriptionText (void)
#define LXxD_TreeView_ReservedSpaceForIcons LxResult treeview_ReservedSpaceForIcons (int *columnIndex, int *width, int *height, int *iconAsValue)
#define LXxO_TreeView_ReservedSpaceForIcons LXxD_TreeView_ReservedSpaceForIcons LXx_OVERRIDE
#define LXxC_TreeView_ReservedSpaceForIcons(c) LxResult c::treeview_ReservedSpaceForIcons (int *columnIndex, int *width, int *height, int *iconAsValue)
#define LXxD_TreeView_IconResource LxResult treeview_IconResource (unsigned columnIndex, int width, int height, char *buf, unsigned len)
#define LXxO_TreeView_IconResource LXxD_TreeView_IconResource LXx_OVERRIDE
#define LXxC_TreeView_IconResource(c) LxResult c::treeview_IconResource (unsigned columnIndex, int width, int height, char *buf, unsigned len)
#define LXxD_TreeView_ReservedSpaceForThumbnails LxResult treeview_ReservedSpaceForThumbnails (int *columnIndex, int *width, int *height)
#define LXxO_TreeView_ReservedSpaceForThumbnails LXxD_TreeView_ReservedSpaceForThumbnails LXx_OVERRIDE
#define LXxC_TreeView_ReservedSpaceForThumbnails(c) LxResult c::treeview_ReservedSpaceForThumbnails (int *columnIndex, int *width, int *height)
#define LXxD_TreeView_Thumbnail LxResult treeview_Thumbnail (unsigned columnIndex, int width, int height, void **ppvObj, char *buf, unsigned len)
#define LXxO_TreeView_Thumbnail LXxD_TreeView_Thumbnail LXx_OVERRIDE
#define LXxC_TreeView_Thumbnail(c) LxResult c::treeview_Thumbnail (unsigned columnIndex, int width, int height, void **ppvObj, char *buf, unsigned len)
#define LXxD_TreeView_BadgeType LxResult treeview_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
#define LXxO_TreeView_BadgeType LXxD_TreeView_BadgeType LXx_OVERRIDE
#define LXxC_TreeView_BadgeType(c) LxResult c::treeview_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
#define LXxD_TreeView_BadgeType2 LxResult treeview_BadgeType2 (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
#define LXxO_TreeView_BadgeType2 LXxD_TreeView_BadgeType2 LXx_OVERRIDE
#define LXxC_TreeView_BadgeType2(c) LxResult c::treeview_BadgeType2 (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
#define LXxD_TreeView_BadgeDetail LxResult treeview_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
#define LXxO_TreeView_BadgeDetail LXxD_TreeView_BadgeDetail LXx_OVERRIDE
#define LXxC_TreeView_BadgeDetail(c) LxResult c::treeview_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
#define LXxD_TreeView_IsInputRegion LxResult treeview_IsInputRegion (unsigned columnIndex, unsigned regionID)
#define LXxO_TreeView_IsInputRegion LXxD_TreeView_IsInputRegion LXx_OVERRIDE
#define LXxC_TreeView_IsInputRegion(c) LxResult c::treeview_IsInputRegion (unsigned columnIndex, unsigned regionID)
#define LXxD_TreeView_SupportedDragDropSourceTypes LxResult treeview_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView_SupportedDragDropSourceTypes LXxD_TreeView_SupportedDragDropSourceTypes LXx_OVERRIDE
#define LXxC_TreeView_SupportedDragDropSourceTypes(c) LxResult c::treeview_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView_GetDragDropSourceObject LxResult treeview_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
#define LXxO_TreeView_GetDragDropSourceObject LXxD_TreeView_GetDragDropSourceObject LXx_OVERRIDE
#define LXxC_TreeView_GetDragDropSourceObject(c) LxResult c::treeview_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
#define LXxD_TreeView_GetDragDropDestinationObject LxResult treeview_GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
#define LXxO_TreeView_GetDragDropDestinationObject LXxD_TreeView_GetDragDropDestinationObject LXx_OVERRIDE
#define LXxC_TreeView_GetDragDropDestinationObject(c) LxResult c::treeview_GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
#define LXxD_TreeView_IsDescendantSelected LxResult treeview_IsDescendantSelected (void)
#define LXxO_TreeView_IsDescendantSelected LXxD_TreeView_IsDescendantSelected LXx_OVERRIDE
#define LXxC_TreeView_IsDescendantSelected(c) LxResult c::treeview_IsDescendantSelected (void)
#define LXxD_TreeView_CanFilter LxResult treeview_CanFilter (void)
#define LXxO_TreeView_CanFilter LXxD_TreeView_CanFilter LXx_OVERRIDE
#define LXxC_TreeView_CanFilter(c) LxResult c::treeview_CanFilter (void)
#define LXxD_TreeView_Filter LxResult treeview_Filter (int *flags)
#define LXxO_TreeView_Filter LXxD_TreeView_Filter LXx_OVERRIDE
#define LXxC_TreeView_Filter(c) LxResult c::treeview_Filter (int *flags)
template <class T>
class CLxIfc_TreeView : public CLxInterface
{
    static LxResult
  StoreState (LXtObjectID wcom, const char *uid)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_StoreState (uid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RestoreState (LXtObjectID wcom, const char *uid)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_RestoreState (uid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  StyleHints (LXtObjectID wcom, int *flags)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_StyleHints (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnCount (LXtObjectID wcom, unsigned* colCount)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_ColumnCount (colCount);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnByIndex (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_ColumnByIndex (columnIndex,buf,len,columnWidth);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnInternalName (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_ColumnInternalName (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnIconResource (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_ColumnIconResource (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnJustification (LXtObjectID wcom, unsigned columnIndex, int *justification)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_ColumnJustification (columnIndex,justification);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PrimaryColumnPosition (LXtObjectID wcom, unsigned *index)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_PrimaryColumnPosition (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToPrimary (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_ToPrimary ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsSelected (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_IsSelected ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Select (LXtObjectID wcom, unsigned mode)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_Select (mode);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CellCommand (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_CellCommand (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BatchCommand (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_BatchCommand (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToolTip (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_ToolTip (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DescriptionText (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_DescriptionText (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ShowDescriptionText (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_ShowDescriptionText ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReservedSpaceForIcons (LXtObjectID wcom, int *columnIndex, int *width, int *height, int *iconAsValue)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_ReservedSpaceForIcons (columnIndex,width,height,iconAsValue);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IconResource (LXtObjectID wcom, unsigned columnIndex, int width, int height, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_IconResource (columnIndex,width,height,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReservedSpaceForThumbnails (LXtObjectID wcom, int *columnIndex, int *width, int *height)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_ReservedSpaceForThumbnails (columnIndex,width,height);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Thumbnail (LXtObjectID wcom, unsigned columnIndex, int width, int height, void **ppvObj, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_Thumbnail (columnIndex,width,height,ppvObj,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeType (LXtObjectID wcom, unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_BadgeType (columnIndex,badgeIndex,badgeType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeType2 (LXtObjectID wcom, unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_BadgeType2 (columnIndex,badgeIndex,badgeType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeDetail (LXtObjectID wcom, unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_BadgeDetail (columnIndex,badgeIndex,badgeDetail,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsInputRegion (LXtObjectID wcom, unsigned columnIndex, unsigned regionID)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_IsInputRegion (columnIndex,regionID);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SupportedDragDropSourceTypes (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_SupportedDragDropSourceTypes (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetDragDropSourceObject (LXtObjectID wcom, unsigned columnIndex, const char *type, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_GetDragDropSourceObject (columnIndex,type,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetDragDropDestinationObject (LXtObjectID wcom, unsigned columnIndex, unsigned location, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_GetDragDropDestinationObject (columnIndex,location,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsDescendantSelected (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_IsDescendantSelected ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CanFilter (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_CanFilter ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Filter (LXtObjectID wcom, int *flags)
  {
    LXCWxINST (CLxImpl_TreeView, loc);
    try {
      return loc->treeview_Filter (flags);
    } catch (LxResult rc) { return rc; }
  }
  ILxTreeView vt;
public:
  CLxIfc_TreeView ()
  {
    vt.StoreState = StoreState;
    vt.RestoreState = RestoreState;
    vt.StyleHints = StyleHints;
    vt.ColumnCount = ColumnCount;
    vt.ColumnByIndex = ColumnByIndex;
    vt.ColumnInternalName = ColumnInternalName;
    vt.ColumnIconResource = ColumnIconResource;
    vt.ColumnJustification = ColumnJustification;
    vt.PrimaryColumnPosition = PrimaryColumnPosition;
    vt.ToPrimary = ToPrimary;
    vt.IsSelected = IsSelected;
    vt.Select = Select;
    vt.CellCommand = CellCommand;
    vt.BatchCommand = BatchCommand;
    vt.ToolTip = ToolTip;
    vt.DescriptionText = DescriptionText;
    vt.ShowDescriptionText = ShowDescriptionText;
    vt.ReservedSpaceForIcons = ReservedSpaceForIcons;
    vt.IconResource = IconResource;
    vt.ReservedSpaceForThumbnails = ReservedSpaceForThumbnails;
    vt.Thumbnail = Thumbnail;
    vt.BadgeType = BadgeType;
    vt.BadgeType2 = BadgeType2;
    vt.BadgeDetail = BadgeDetail;
    vt.IsInputRegion = IsInputRegion;
    vt.SupportedDragDropSourceTypes = SupportedDragDropSourceTypes;
    vt.GetDragDropSourceObject = GetDragDropSourceObject;
    vt.GetDragDropDestinationObject = GetDragDropDestinationObject;
    vt.IsDescendantSelected = IsDescendantSelected;
    vt.CanFilter = CanFilter;
    vt.Filter = Filter;
    vTable = &vt.iunk;
    iid = &lx::guid_TreeView;
  }
};
class CLxLoc_TreeView : public CLxLocalize<ILxTreeViewID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TreeView() {_init();}
  CLxLoc_TreeView(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TreeView(const CLxLoc_TreeView &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TreeView;}
    LxResult
  StoreState (const char *uid)
  {
    return m_loc[0]->StoreState (m_loc,uid);
  }
    LxResult
  RestoreState (const char *uid)
  {
    return m_loc[0]->RestoreState (m_loc,uid);
  }
    LxResult
  StyleHints (int *flags)
  {
    return m_loc[0]->StyleHints (m_loc,flags);
  }
    LxResult
  ColumnCount (unsigned* colCount)
  {
    return m_loc[0]->ColumnCount (m_loc,colCount);
  }
    LxResult
  ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
  {
    return m_loc[0]->ColumnByIndex (m_loc,columnIndex,buf,len,columnWidth);
  }
    LxResult
  ColumnByIndex (unsigned columnIndex, std::string &result, int *columnWidth)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ColumnByIndex (m_loc,columnIndex,buf,len,columnWidth);
    LXWx_SBUF2
  }
    LxResult
  ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->ColumnInternalName (m_loc,columnIndex,buf,len);
  }
    LxResult
  ColumnInternalName (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ColumnInternalName (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->ColumnIconResource (m_loc,columnIndex,buf,len);
  }
    LxResult
  ColumnIconResource (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ColumnIconResource (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ColumnJustification (unsigned columnIndex, int *justification)
  {
    return m_loc[0]->ColumnJustification (m_loc,columnIndex,justification);
  }
    LxResult
  PrimaryColumnPosition (unsigned *index)
  {
    return m_loc[0]->PrimaryColumnPosition (m_loc,index);
  }
    LxResult
  ToPrimary (void)
  {
    return m_loc[0]->ToPrimary (m_loc);
  }
    LxResult
  IsSelected (void)
  {
    return m_loc[0]->IsSelected (m_loc);
  }
    LxResult
  Select (unsigned mode)
  {
    return m_loc[0]->Select (m_loc,mode);
  }
    LxResult
  CellCommand (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->CellCommand (m_loc,columnIndex,buf,len);
  }
    LxResult
  CellCommand (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->CellCommand (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  BatchCommand (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->BatchCommand (m_loc,columnIndex,buf,len);
  }
    LxResult
  BatchCommand (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->BatchCommand (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ToolTip (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->ToolTip (m_loc,columnIndex,buf,len);
  }
    LxResult
  ToolTip (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ToolTip (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  DescriptionText (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->DescriptionText (m_loc,columnIndex,buf,len);
  }
    LxResult
  DescriptionText (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->DescriptionText (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ShowDescriptionText (void)
  {
    return m_loc[0]->ShowDescriptionText (m_loc);
  }
    LxResult
  ReservedSpaceForIcons (int *columnIndex, int *width, int *height, int *iconAsValue)
  {
    return m_loc[0]->ReservedSpaceForIcons (m_loc,columnIndex,width,height,iconAsValue);
  }
    LxResult
  IconResource (unsigned columnIndex, int width, int height, char *buf, unsigned len)
  {
    return m_loc[0]->IconResource (m_loc,columnIndex,width,height,buf,len);
  }
    LxResult
  IconResource (unsigned columnIndex, int width, int height, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->IconResource (m_loc,columnIndex,width,height,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ReservedSpaceForThumbnails (int *columnIndex, int *width, int *height)
  {
    return m_loc[0]->ReservedSpaceForThumbnails (m_loc,columnIndex,width,height);
  }
    LxResult
  Thumbnail (unsigned columnIndex, int width, int height, void **ppvObj, char *buf, unsigned len)
  {
    return m_loc[0]->Thumbnail (m_loc,columnIndex,width,height,ppvObj,buf,len);
  }
    CLxResult
  Thumbnail (unsigned columnIndex, int width, int height, CLxLocalizedObject &o_dest, char *buf, unsigned len)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Thumbnail(m_loc,columnIndex,width,height,&o_obj,buf,len);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Thumbnail (unsigned columnIndex, int width, int height, void **ppvObj, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->Thumbnail (m_loc,columnIndex,width,height,ppvObj,buf,len);
    LXWx_SBUF2
  }
    LxResult
  BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
  {
    return m_loc[0]->BadgeType (m_loc,columnIndex,badgeIndex,badgeType);
  }
    LxResult
  BadgeType2 (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
  {
    return m_loc[0]->BadgeType2 (m_loc,columnIndex,badgeIndex,badgeType);
  }
    LxResult
  BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
  {
    return m_loc[0]->BadgeDetail (m_loc,columnIndex,badgeIndex,badgeDetail,buf,len);
  }
    LxResult
  BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->BadgeDetail (m_loc,columnIndex,badgeIndex,badgeDetail,buf,len);
    LXWx_SBUF2
  }
    LxResult
  IsInputRegion (unsigned columnIndex, unsigned regionID)
  {
    return m_loc[0]->IsInputRegion (m_loc,columnIndex,regionID);
  }
    LxResult
  SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->SupportedDragDropSourceTypes (m_loc,columnIndex,buf,len);
  }
    LxResult
  SupportedDragDropSourceTypes (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->SupportedDragDropSourceTypes (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
  {
    return m_loc[0]->GetDragDropSourceObject (m_loc,columnIndex,type,ppvObj);
  }
    CLxResult
  GetDragDropSourceObject (unsigned columnIndex, const char *type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetDragDropSourceObject(m_loc,columnIndex,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
  {
    return m_loc[0]->GetDragDropDestinationObject (m_loc,columnIndex,location,ppvObj);
  }
    CLxResult
  GetDragDropDestinationObject (unsigned columnIndex, unsigned location, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetDragDropDestinationObject(m_loc,columnIndex,location,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  IsDescendantSelected (void)
  {
    return m_loc[0]->IsDescendantSelected (m_loc);
  }
    LxResult
  CanFilter (void)
  {
    return m_loc[0]->CanFilter (m_loc);
  }
    LxResult
  Filter (int *flags)
  {
    return m_loc[0]->Filter (m_loc,flags);
  }
};

class CLxImpl_TreeView2 {
  public:
    virtual ~CLxImpl_TreeView2() {}
    virtual LxResult
      treeview2_StoreState (const char *uid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_RestoreState (const char *uid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_ColumnCount (unsigned* colCount)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_ColumnJustification (unsigned columnIndex, int *justification)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_PrimaryColumnPosition (unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_ToPrimary (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_IsSelected (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_Select (unsigned mode)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_CellCommand (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_ToolTip (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_IsInputRegion (unsigned columnIndex, unsigned regionID)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview2_GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_TreeView2_StoreState LxResult treeview2_StoreState (const char *uid)
#define LXxO_TreeView2_StoreState LXxD_TreeView2_StoreState LXx_OVERRIDE
#define LXxC_TreeView2_StoreState(c) LxResult c::treeview2_StoreState (const char *uid)
#define LXxD_TreeView2_RestoreState LxResult treeview2_RestoreState (const char *uid)
#define LXxO_TreeView2_RestoreState LXxD_TreeView2_RestoreState LXx_OVERRIDE
#define LXxC_TreeView2_RestoreState(c) LxResult c::treeview2_RestoreState (const char *uid)
#define LXxD_TreeView2_ColumnCount LxResult treeview2_ColumnCount (unsigned* colCount)
#define LXxO_TreeView2_ColumnCount LXxD_TreeView2_ColumnCount LXx_OVERRIDE
#define LXxC_TreeView2_ColumnCount(c) LxResult c::treeview2_ColumnCount (unsigned* colCount)
#define LXxD_TreeView2_ColumnByIndex LxResult treeview2_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
#define LXxO_TreeView2_ColumnByIndex LXxD_TreeView2_ColumnByIndex LXx_OVERRIDE
#define LXxC_TreeView2_ColumnByIndex(c) LxResult c::treeview2_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
#define LXxD_TreeView2_ColumnInternalName LxResult treeview2_ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView2_ColumnInternalName LXxD_TreeView2_ColumnInternalName LXx_OVERRIDE
#define LXxC_TreeView2_ColumnInternalName(c) LxResult c::treeview2_ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView2_ColumnIconResource LxResult treeview2_ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView2_ColumnIconResource LXxD_TreeView2_ColumnIconResource LXx_OVERRIDE
#define LXxC_TreeView2_ColumnIconResource(c) LxResult c::treeview2_ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView2_ColumnJustification LxResult treeview2_ColumnJustification (unsigned columnIndex, int *justification)
#define LXxO_TreeView2_ColumnJustification LXxD_TreeView2_ColumnJustification LXx_OVERRIDE
#define LXxC_TreeView2_ColumnJustification(c) LxResult c::treeview2_ColumnJustification (unsigned columnIndex, int *justification)
#define LXxD_TreeView2_PrimaryColumnPosition LxResult treeview2_PrimaryColumnPosition (unsigned *index)
#define LXxO_TreeView2_PrimaryColumnPosition LXxD_TreeView2_PrimaryColumnPosition LXx_OVERRIDE
#define LXxC_TreeView2_PrimaryColumnPosition(c) LxResult c::treeview2_PrimaryColumnPosition (unsigned *index)
#define LXxD_TreeView2_ToPrimary LxResult treeview2_ToPrimary (void)
#define LXxO_TreeView2_ToPrimary LXxD_TreeView2_ToPrimary LXx_OVERRIDE
#define LXxC_TreeView2_ToPrimary(c) LxResult c::treeview2_ToPrimary (void)
#define LXxD_TreeView2_IsSelected LxResult treeview2_IsSelected (void)
#define LXxO_TreeView2_IsSelected LXxD_TreeView2_IsSelected LXx_OVERRIDE
#define LXxC_TreeView2_IsSelected(c) LxResult c::treeview2_IsSelected (void)
#define LXxD_TreeView2_Select LxResult treeview2_Select (unsigned mode)
#define LXxO_TreeView2_Select LXxD_TreeView2_Select LXx_OVERRIDE
#define LXxC_TreeView2_Select(c) LxResult c::treeview2_Select (unsigned mode)
#define LXxD_TreeView2_CellCommand LxResult treeview2_CellCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView2_CellCommand LXxD_TreeView2_CellCommand LXx_OVERRIDE
#define LXxC_TreeView2_CellCommand(c) LxResult c::treeview2_CellCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView2_BatchCommand LxResult treeview2_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView2_BatchCommand LXxD_TreeView2_BatchCommand LXx_OVERRIDE
#define LXxC_TreeView2_BatchCommand(c) LxResult c::treeview2_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView2_ToolTip LxResult treeview2_ToolTip (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView2_ToolTip LXxD_TreeView2_ToolTip LXx_OVERRIDE
#define LXxC_TreeView2_ToolTip(c) LxResult c::treeview2_ToolTip (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView2_BadgeType LxResult treeview2_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
#define LXxO_TreeView2_BadgeType LXxD_TreeView2_BadgeType LXx_OVERRIDE
#define LXxC_TreeView2_BadgeType(c) LxResult c::treeview2_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
#define LXxD_TreeView2_BadgeDetail LxResult treeview2_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
#define LXxO_TreeView2_BadgeDetail LXxD_TreeView2_BadgeDetail LXx_OVERRIDE
#define LXxC_TreeView2_BadgeDetail(c) LxResult c::treeview2_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
#define LXxD_TreeView2_IsInputRegion LxResult treeview2_IsInputRegion (unsigned columnIndex, unsigned regionID)
#define LXxO_TreeView2_IsInputRegion LXxD_TreeView2_IsInputRegion LXx_OVERRIDE
#define LXxC_TreeView2_IsInputRegion(c) LxResult c::treeview2_IsInputRegion (unsigned columnIndex, unsigned regionID)
#define LXxD_TreeView2_SupportedDragDropSourceTypes LxResult treeview2_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView2_SupportedDragDropSourceTypes LXxD_TreeView2_SupportedDragDropSourceTypes LXx_OVERRIDE
#define LXxC_TreeView2_SupportedDragDropSourceTypes(c) LxResult c::treeview2_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView2_GetDragDropSourceObject LxResult treeview2_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
#define LXxO_TreeView2_GetDragDropSourceObject LXxD_TreeView2_GetDragDropSourceObject LXx_OVERRIDE
#define LXxC_TreeView2_GetDragDropSourceObject(c) LxResult c::treeview2_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
#define LXxD_TreeView2_GetDragDropDestinationObject LxResult treeview2_GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
#define LXxO_TreeView2_GetDragDropDestinationObject LXxD_TreeView2_GetDragDropDestinationObject LXx_OVERRIDE
#define LXxC_TreeView2_GetDragDropDestinationObject(c) LxResult c::treeview2_GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
template <class T>
class CLxIfc_TreeView2 : public CLxInterface
{
    static LxResult
  StoreState (LXtObjectID wcom, const char *uid)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_StoreState (uid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RestoreState (LXtObjectID wcom, const char *uid)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_RestoreState (uid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnCount (LXtObjectID wcom, unsigned* colCount)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_ColumnCount (colCount);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnByIndex (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_ColumnByIndex (columnIndex,buf,len,columnWidth);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnInternalName (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_ColumnInternalName (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnIconResource (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_ColumnIconResource (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnJustification (LXtObjectID wcom, unsigned columnIndex, int *justification)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_ColumnJustification (columnIndex,justification);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PrimaryColumnPosition (LXtObjectID wcom, unsigned *index)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_PrimaryColumnPosition (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToPrimary (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_ToPrimary ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsSelected (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_IsSelected ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Select (LXtObjectID wcom, unsigned mode)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_Select (mode);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CellCommand (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_CellCommand (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BatchCommand (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_BatchCommand (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToolTip (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_ToolTip (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeType (LXtObjectID wcom, unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_BadgeType (columnIndex,badgeIndex,badgeType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeDetail (LXtObjectID wcom, unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_BadgeDetail (columnIndex,badgeIndex,badgeDetail,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsInputRegion (LXtObjectID wcom, unsigned columnIndex, unsigned regionID)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_IsInputRegion (columnIndex,regionID);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SupportedDragDropSourceTypes (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_SupportedDragDropSourceTypes (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetDragDropSourceObject (LXtObjectID wcom, unsigned columnIndex, const char *type, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_GetDragDropSourceObject (columnIndex,type,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetDragDropDestinationObject (LXtObjectID wcom, unsigned columnIndex, unsigned location, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TreeView2, loc);
    try {
      return loc->treeview2_GetDragDropDestinationObject (columnIndex,location,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxTreeView2 vt;
public:
  CLxIfc_TreeView2 ()
  {
    vt.StoreState = StoreState;
    vt.RestoreState = RestoreState;
    vt.ColumnCount = ColumnCount;
    vt.ColumnByIndex = ColumnByIndex;
    vt.ColumnInternalName = ColumnInternalName;
    vt.ColumnIconResource = ColumnIconResource;
    vt.ColumnJustification = ColumnJustification;
    vt.PrimaryColumnPosition = PrimaryColumnPosition;
    vt.ToPrimary = ToPrimary;
    vt.IsSelected = IsSelected;
    vt.Select = Select;
    vt.CellCommand = CellCommand;
    vt.BatchCommand = BatchCommand;
    vt.ToolTip = ToolTip;
    vt.BadgeType = BadgeType;
    vt.BadgeDetail = BadgeDetail;
    vt.IsInputRegion = IsInputRegion;
    vt.SupportedDragDropSourceTypes = SupportedDragDropSourceTypes;
    vt.GetDragDropSourceObject = GetDragDropSourceObject;
    vt.GetDragDropDestinationObject = GetDragDropDestinationObject;
    vTable = &vt.iunk;
    iid = &lx::guid_TreeView2;
  }
};
class CLxLoc_TreeView2 : public CLxLocalize<ILxTreeView2ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TreeView2() {_init();}
  CLxLoc_TreeView2(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TreeView2(const CLxLoc_TreeView2 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TreeView2;}
    LxResult
  StoreState (const char *uid)
  {
    return m_loc[0]->StoreState (m_loc,uid);
  }
    LxResult
  RestoreState (const char *uid)
  {
    return m_loc[0]->RestoreState (m_loc,uid);
  }
    LxResult
  ColumnCount (unsigned* colCount)
  {
    return m_loc[0]->ColumnCount (m_loc,colCount);
  }
    LxResult
  ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
  {
    return m_loc[0]->ColumnByIndex (m_loc,columnIndex,buf,len,columnWidth);
  }
    LxResult
  ColumnByIndex (unsigned columnIndex, std::string &result, int *columnWidth)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ColumnByIndex (m_loc,columnIndex,buf,len,columnWidth);
    LXWx_SBUF2
  }
    LxResult
  ColumnInternalName (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->ColumnInternalName (m_loc,columnIndex,buf,len);
  }
    LxResult
  ColumnInternalName (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ColumnInternalName (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ColumnIconResource (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->ColumnIconResource (m_loc,columnIndex,buf,len);
  }
    LxResult
  ColumnIconResource (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ColumnIconResource (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ColumnJustification (unsigned columnIndex, int *justification)
  {
    return m_loc[0]->ColumnJustification (m_loc,columnIndex,justification);
  }
    LxResult
  PrimaryColumnPosition (unsigned *index)
  {
    return m_loc[0]->PrimaryColumnPosition (m_loc,index);
  }
    LxResult
  ToPrimary (void)
  {
    return m_loc[0]->ToPrimary (m_loc);
  }
    LxResult
  IsSelected (void)
  {
    return m_loc[0]->IsSelected (m_loc);
  }
    LxResult
  Select (unsigned mode)
  {
    return m_loc[0]->Select (m_loc,mode);
  }
    LxResult
  CellCommand (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->CellCommand (m_loc,columnIndex,buf,len);
  }
    LxResult
  CellCommand (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->CellCommand (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  BatchCommand (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->BatchCommand (m_loc,columnIndex,buf,len);
  }
    LxResult
  BatchCommand (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->BatchCommand (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ToolTip (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->ToolTip (m_loc,columnIndex,buf,len);
  }
    LxResult
  ToolTip (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ToolTip (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
  {
    return m_loc[0]->BadgeType (m_loc,columnIndex,badgeIndex,badgeType);
  }
    LxResult
  BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
  {
    return m_loc[0]->BadgeDetail (m_loc,columnIndex,badgeIndex,badgeDetail,buf,len);
  }
    LxResult
  BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->BadgeDetail (m_loc,columnIndex,badgeIndex,badgeDetail,buf,len);
    LXWx_SBUF2
  }
    LxResult
  IsInputRegion (unsigned columnIndex, unsigned regionID)
  {
    return m_loc[0]->IsInputRegion (m_loc,columnIndex,regionID);
  }
    LxResult
  SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->SupportedDragDropSourceTypes (m_loc,columnIndex,buf,len);
  }
    LxResult
  SupportedDragDropSourceTypes (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->SupportedDragDropSourceTypes (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
  {
    return m_loc[0]->GetDragDropSourceObject (m_loc,columnIndex,type,ppvObj);
  }
    CLxResult
  GetDragDropSourceObject (unsigned columnIndex, const char *type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetDragDropSourceObject(m_loc,columnIndex,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetDragDropDestinationObject (unsigned columnIndex, unsigned location, void **ppvObj)
  {
    return m_loc[0]->GetDragDropDestinationObject (m_loc,columnIndex,location,ppvObj);
  }
    CLxResult
  GetDragDropDestinationObject (unsigned columnIndex, unsigned location, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetDragDropDestinationObject(m_loc,columnIndex,location,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_TreeView1 {
  public:
    virtual ~CLxImpl_TreeView1() {}
    virtual LxResult
      treeview1_StoreState (const char *uid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_RestoreState (const char *uid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_ColumnCount (unsigned* colCount)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_ToPrimary (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_IsSelected (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_Select (unsigned mode)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_CellCommand (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_ToolTip (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_IsInputRegion (unsigned columnIndex, unsigned regionID)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      treeview1_GetDragDropDestinationObject (unsigned columnIndex, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_TreeView1_StoreState LxResult treeview1_StoreState (const char *uid)
#define LXxO_TreeView1_StoreState LXxD_TreeView1_StoreState LXx_OVERRIDE
#define LXxC_TreeView1_StoreState(c) LxResult c::treeview1_StoreState (const char *uid)
#define LXxD_TreeView1_RestoreState LxResult treeview1_RestoreState (const char *uid)
#define LXxO_TreeView1_RestoreState LXxD_TreeView1_RestoreState LXx_OVERRIDE
#define LXxC_TreeView1_RestoreState(c) LxResult c::treeview1_RestoreState (const char *uid)
#define LXxD_TreeView1_ColumnCount LxResult treeview1_ColumnCount (unsigned* colCount)
#define LXxO_TreeView1_ColumnCount LXxD_TreeView1_ColumnCount LXx_OVERRIDE
#define LXxC_TreeView1_ColumnCount(c) LxResult c::treeview1_ColumnCount (unsigned* colCount)
#define LXxD_TreeView1_ColumnByIndex LxResult treeview1_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
#define LXxO_TreeView1_ColumnByIndex LXxD_TreeView1_ColumnByIndex LXx_OVERRIDE
#define LXxC_TreeView1_ColumnByIndex(c) LxResult c::treeview1_ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
#define LXxD_TreeView1_ToPrimary LxResult treeview1_ToPrimary (void)
#define LXxO_TreeView1_ToPrimary LXxD_TreeView1_ToPrimary LXx_OVERRIDE
#define LXxC_TreeView1_ToPrimary(c) LxResult c::treeview1_ToPrimary (void)
#define LXxD_TreeView1_IsSelected LxResult treeview1_IsSelected (void)
#define LXxO_TreeView1_IsSelected LXxD_TreeView1_IsSelected LXx_OVERRIDE
#define LXxC_TreeView1_IsSelected(c) LxResult c::treeview1_IsSelected (void)
#define LXxD_TreeView1_Select LxResult treeview1_Select (unsigned mode)
#define LXxO_TreeView1_Select LXxD_TreeView1_Select LXx_OVERRIDE
#define LXxC_TreeView1_Select(c) LxResult c::treeview1_Select (unsigned mode)
#define LXxD_TreeView1_CellCommand LxResult treeview1_CellCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView1_CellCommand LXxD_TreeView1_CellCommand LXx_OVERRIDE
#define LXxC_TreeView1_CellCommand(c) LxResult c::treeview1_CellCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView1_BatchCommand LxResult treeview1_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView1_BatchCommand LXxD_TreeView1_BatchCommand LXx_OVERRIDE
#define LXxC_TreeView1_BatchCommand(c) LxResult c::treeview1_BatchCommand (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView1_ToolTip LxResult treeview1_ToolTip (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView1_ToolTip LXxD_TreeView1_ToolTip LXx_OVERRIDE
#define LXxC_TreeView1_ToolTip(c) LxResult c::treeview1_ToolTip (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView1_BadgeType LxResult treeview1_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
#define LXxO_TreeView1_BadgeType LXxD_TreeView1_BadgeType LXx_OVERRIDE
#define LXxC_TreeView1_BadgeType(c) LxResult c::treeview1_BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
#define LXxD_TreeView1_BadgeDetail LxResult treeview1_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
#define LXxO_TreeView1_BadgeDetail LXxD_TreeView1_BadgeDetail LXx_OVERRIDE
#define LXxC_TreeView1_BadgeDetail(c) LxResult c::treeview1_BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
#define LXxD_TreeView1_IsInputRegion LxResult treeview1_IsInputRegion (unsigned columnIndex, unsigned regionID)
#define LXxO_TreeView1_IsInputRegion LXxD_TreeView1_IsInputRegion LXx_OVERRIDE
#define LXxC_TreeView1_IsInputRegion(c) LxResult c::treeview1_IsInputRegion (unsigned columnIndex, unsigned regionID)
#define LXxD_TreeView1_SupportedDragDropSourceTypes LxResult treeview1_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
#define LXxO_TreeView1_SupportedDragDropSourceTypes LXxD_TreeView1_SupportedDragDropSourceTypes LXx_OVERRIDE
#define LXxC_TreeView1_SupportedDragDropSourceTypes(c) LxResult c::treeview1_SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
#define LXxD_TreeView1_GetDragDropSourceObject LxResult treeview1_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
#define LXxO_TreeView1_GetDragDropSourceObject LXxD_TreeView1_GetDragDropSourceObject LXx_OVERRIDE
#define LXxC_TreeView1_GetDragDropSourceObject(c) LxResult c::treeview1_GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
#define LXxD_TreeView1_GetDragDropDestinationObject LxResult treeview1_GetDragDropDestinationObject (unsigned columnIndex, void **ppvObj)
#define LXxO_TreeView1_GetDragDropDestinationObject LXxD_TreeView1_GetDragDropDestinationObject LXx_OVERRIDE
#define LXxC_TreeView1_GetDragDropDestinationObject(c) LxResult c::treeview1_GetDragDropDestinationObject (unsigned columnIndex, void **ppvObj)
template <class T>
class CLxIfc_TreeView1 : public CLxInterface
{
    static LxResult
  StoreState (LXtObjectID wcom, const char *uid)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_StoreState (uid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RestoreState (LXtObjectID wcom, const char *uid)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_RestoreState (uid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnCount (LXtObjectID wcom, unsigned* colCount)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_ColumnCount (colCount);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColumnByIndex (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_ColumnByIndex (columnIndex,buf,len,columnWidth);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToPrimary (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_ToPrimary ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsSelected (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_IsSelected ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Select (LXtObjectID wcom, unsigned mode)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_Select (mode);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CellCommand (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_CellCommand (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BatchCommand (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_BatchCommand (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToolTip (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_ToolTip (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeType (LXtObjectID wcom, unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_BadgeType (columnIndex,badgeIndex,badgeType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeDetail (LXtObjectID wcom, unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_BadgeDetail (columnIndex,badgeIndex,badgeDetail,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsInputRegion (LXtObjectID wcom, unsigned columnIndex, unsigned regionID)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_IsInputRegion (columnIndex,regionID);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SupportedDragDropSourceTypes (LXtObjectID wcom, unsigned columnIndex, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_SupportedDragDropSourceTypes (columnIndex,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetDragDropSourceObject (LXtObjectID wcom, unsigned columnIndex, const char *type, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_GetDragDropSourceObject (columnIndex,type,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetDragDropDestinationObject (LXtObjectID wcom, unsigned columnIndex, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TreeView1, loc);
    try {
      return loc->treeview1_GetDragDropDestinationObject (columnIndex,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxTreeView1 vt;
public:
  CLxIfc_TreeView1 ()
  {
    vt.StoreState = StoreState;
    vt.RestoreState = RestoreState;
    vt.ColumnCount = ColumnCount;
    vt.ColumnByIndex = ColumnByIndex;
    vt.ToPrimary = ToPrimary;
    vt.IsSelected = IsSelected;
    vt.Select = Select;
    vt.CellCommand = CellCommand;
    vt.BatchCommand = BatchCommand;
    vt.ToolTip = ToolTip;
    vt.BadgeType = BadgeType;
    vt.BadgeDetail = BadgeDetail;
    vt.IsInputRegion = IsInputRegion;
    vt.SupportedDragDropSourceTypes = SupportedDragDropSourceTypes;
    vt.GetDragDropSourceObject = GetDragDropSourceObject;
    vt.GetDragDropDestinationObject = GetDragDropDestinationObject;
    vTable = &vt.iunk;
    iid = &lx::guid_TreeView1;
  }
};
class CLxLoc_TreeView1 : public CLxLocalize<ILxTreeView1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TreeView1() {_init();}
  CLxLoc_TreeView1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TreeView1(const CLxLoc_TreeView1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TreeView1;}
    LxResult
  StoreState (const char *uid)
  {
    return m_loc[0]->StoreState (m_loc,uid);
  }
    LxResult
  RestoreState (const char *uid)
  {
    return m_loc[0]->RestoreState (m_loc,uid);
  }
    LxResult
  ColumnCount (unsigned* colCount)
  {
    return m_loc[0]->ColumnCount (m_loc,colCount);
  }
    LxResult
  ColumnByIndex (unsigned columnIndex, char *buf, unsigned len, int *columnWidth)
  {
    return m_loc[0]->ColumnByIndex (m_loc,columnIndex,buf,len,columnWidth);
  }
    LxResult
  ColumnByIndex (unsigned columnIndex, std::string &result, int *columnWidth)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ColumnByIndex (m_loc,columnIndex,buf,len,columnWidth);
    LXWx_SBUF2
  }
    LxResult
  ToPrimary (void)
  {
    return m_loc[0]->ToPrimary (m_loc);
  }
    LxResult
  IsSelected (void)
  {
    return m_loc[0]->IsSelected (m_loc);
  }
    LxResult
  Select (unsigned mode)
  {
    return m_loc[0]->Select (m_loc,mode);
  }
    LxResult
  CellCommand (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->CellCommand (m_loc,columnIndex,buf,len);
  }
    LxResult
  CellCommand (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->CellCommand (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  BatchCommand (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->BatchCommand (m_loc,columnIndex,buf,len);
  }
    LxResult
  BatchCommand (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->BatchCommand (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ToolTip (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->ToolTip (m_loc,columnIndex,buf,len);
  }
    LxResult
  ToolTip (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ToolTip (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  BadgeType (unsigned columnIndex, unsigned badgeIndex, unsigned *badgeType)
  {
    return m_loc[0]->BadgeType (m_loc,columnIndex,badgeIndex,badgeType);
  }
    LxResult
  BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, char *buf, unsigned len)
  {
    return m_loc[0]->BadgeDetail (m_loc,columnIndex,badgeIndex,badgeDetail,buf,len);
  }
    LxResult
  BadgeDetail (unsigned columnIndex, unsigned badgeIndex, unsigned badgeDetail, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->BadgeDetail (m_loc,columnIndex,badgeIndex,badgeDetail,buf,len);
    LXWx_SBUF2
  }
    LxResult
  IsInputRegion (unsigned columnIndex, unsigned regionID)
  {
    return m_loc[0]->IsInputRegion (m_loc,columnIndex,regionID);
  }
    LxResult
  SupportedDragDropSourceTypes (unsigned columnIndex, char *buf, unsigned len)
  {
    return m_loc[0]->SupportedDragDropSourceTypes (m_loc,columnIndex,buf,len);
  }
    LxResult
  SupportedDragDropSourceTypes (unsigned columnIndex, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->SupportedDragDropSourceTypes (m_loc,columnIndex,buf,len);
    LXWx_SBUF2
  }
    LxResult
  GetDragDropSourceObject (unsigned columnIndex, const char *type, void **ppvObj)
  {
    return m_loc[0]->GetDragDropSourceObject (m_loc,columnIndex,type,ppvObj);
  }
    CLxResult
  GetDragDropSourceObject (unsigned columnIndex, const char *type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetDragDropSourceObject(m_loc,columnIndex,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetDragDropDestinationObject (unsigned columnIndex, void **ppvObj)
  {
    return m_loc[0]->GetDragDropDestinationObject (m_loc,columnIndex,ppvObj);
  }
    CLxResult
  GetDragDropDestinationObject (unsigned columnIndex, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetDragDropDestinationObject(m_loc,columnIndex,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

