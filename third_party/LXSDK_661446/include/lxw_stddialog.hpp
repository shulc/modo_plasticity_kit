/*
 * C++ wrapper for lxstddialog.h
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
#ifndef LXW_STDDIALOG_HPP
#define LXW_STDDIALOG_HPP

#include <lxstddialog.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_AsyncMonitorInfo = {0x79f3c06f,0xf36d,0x477d,0xb9,0x46,0xf6,0xf7,0x8a,0x83,0x82,0x30};
    static const LXtGUID guid_ColorDialog = {0x2AB01AAE,0x110B,0x11DF,0xBF,0xD0,0x0A,0xC7,0x56,0xD8,0x95,0x93};
    static const LXtGUID guid_AsyncMonitorSystem = {0xc573842a,0xd4fd,0x48eb,0x8f,0xb0,0x07,0x8a,0x72,0x1e,0x5e,0x0f};
    static const LXtGUID guid_AsyncMonitorInfo1 = {0xadf5bb35,0x7180,0x4d6e,0x93,0x48,0x49,0x20,0x6a,0xe7,0xe6,0xca};
    static const LXtGUID guid_FileDialogClient = {0x77F97D4C,0x8AF9,0x4E3A,0xAA,0x58,0xE8,0x41,0x89,0x90,0xFC,0xA8};
    static const LXtGUID guid_StdDialogService = {0xA78FA063,0x6C8D,0x471f,0x89,0x81,0x6B,0xAE,0xFF,0x62,0xBE,0xE3};
};

class CLxImpl_AsyncMonitorInfo {
  public:
    virtual ~CLxImpl_AsyncMonitorInfo() {}
    virtual LxResult
      amonsys_System (const char **system)
        { return LXe_NOTIMPL; }
    virtual LxResult
      amonsys_Title (const char **title)
        { return LXe_NOTIMPL; }
    virtual LxResult
      amonsys_Progress (double *progress)
        { return LXe_NOTIMPL; }
    virtual LxResult
      amonsys_OverallProgress (double *progress)
        { return LXe_NOTIMPL; }
    virtual LxResult
      amonsys_Parent (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      amonsys_Child (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      amonsys_Identifier (const char **ident)
        { return LXe_NOTIMPL; }
    virtual LxResult
      amonsys_CanAbort (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      amonsys_Abort (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      amonsys_IsAborted (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_AsyncMonitorInfo_System LxResult amonsys_System (const char **system)
#define LXxO_AsyncMonitorInfo_System LXxD_AsyncMonitorInfo_System LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo_System(c) LxResult c::amonsys_System (const char **system)
#define LXxD_AsyncMonitorInfo_Title LxResult amonsys_Title (const char **title)
#define LXxO_AsyncMonitorInfo_Title LXxD_AsyncMonitorInfo_Title LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo_Title(c) LxResult c::amonsys_Title (const char **title)
#define LXxD_AsyncMonitorInfo_Progress LxResult amonsys_Progress (double *progress)
#define LXxO_AsyncMonitorInfo_Progress LXxD_AsyncMonitorInfo_Progress LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo_Progress(c) LxResult c::amonsys_Progress (double *progress)
#define LXxD_AsyncMonitorInfo_OverallProgress LxResult amonsys_OverallProgress (double *progress)
#define LXxO_AsyncMonitorInfo_OverallProgress LXxD_AsyncMonitorInfo_OverallProgress LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo_OverallProgress(c) LxResult c::amonsys_OverallProgress (double *progress)
#define LXxD_AsyncMonitorInfo_Parent LxResult amonsys_Parent (void **ppvObj)
#define LXxO_AsyncMonitorInfo_Parent LXxD_AsyncMonitorInfo_Parent LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo_Parent(c) LxResult c::amonsys_Parent (void **ppvObj)
#define LXxD_AsyncMonitorInfo_Child LxResult amonsys_Child (void **ppvObj)
#define LXxO_AsyncMonitorInfo_Child LXxD_AsyncMonitorInfo_Child LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo_Child(c) LxResult c::amonsys_Child (void **ppvObj)
#define LXxD_AsyncMonitorInfo_Identifier LxResult amonsys_Identifier (const char **ident)
#define LXxO_AsyncMonitorInfo_Identifier LXxD_AsyncMonitorInfo_Identifier LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo_Identifier(c) LxResult c::amonsys_Identifier (const char **ident)
#define LXxD_AsyncMonitorInfo_CanAbort LxResult amonsys_CanAbort (void)
#define LXxO_AsyncMonitorInfo_CanAbort LXxD_AsyncMonitorInfo_CanAbort LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo_CanAbort(c) LxResult c::amonsys_CanAbort (void)
#define LXxD_AsyncMonitorInfo_Abort LxResult amonsys_Abort (void)
#define LXxO_AsyncMonitorInfo_Abort LXxD_AsyncMonitorInfo_Abort LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo_Abort(c) LxResult c::amonsys_Abort (void)
#define LXxD_AsyncMonitorInfo_IsAborted LxResult amonsys_IsAborted (void)
#define LXxO_AsyncMonitorInfo_IsAborted LXxD_AsyncMonitorInfo_IsAborted LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo_IsAborted(c) LxResult c::amonsys_IsAborted (void)
template <class T>
class CLxIfc_AsyncMonitorInfo : public CLxInterface
{
    static LxResult
  System (LXtObjectID wcom, const char **system)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
    try {
      return loc->amonsys_System (system);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Title (LXtObjectID wcom, const char **title)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
    try {
      return loc->amonsys_Title (title);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Progress (LXtObjectID wcom, double *progress)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
    try {
      return loc->amonsys_Progress (progress);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  OverallProgress (LXtObjectID wcom, double *progress)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
    try {
      return loc->amonsys_OverallProgress (progress);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Parent (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
    try {
      return loc->amonsys_Parent (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Child (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
    try {
      return loc->amonsys_Child (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Identifier (LXtObjectID wcom, const char **ident)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
    try {
      return loc->amonsys_Identifier (ident);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CanAbort (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
    try {
      return loc->amonsys_CanAbort ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Abort (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
    try {
      return loc->amonsys_Abort ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsAborted (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo, loc);
    try {
      return loc->amonsys_IsAborted ();
    } catch (LxResult rc) { return rc; }
  }
  ILxAsyncMonitorInfo vt;
public:
  CLxIfc_AsyncMonitorInfo ()
  {
    vt.System = System;
    vt.Title = Title;
    vt.Progress = Progress;
    vt.OverallProgress = OverallProgress;
    vt.Parent = Parent;
    vt.Child = Child;
    vt.Identifier = Identifier;
    vt.CanAbort = CanAbort;
    vt.Abort = Abort;
    vt.IsAborted = IsAborted;
    vTable = &vt.iunk;
    iid = &lx::guid_AsyncMonitorInfo;
  }
};
class CLxLoc_AsyncMonitorInfo : public CLxLocalize<ILxAsyncMonitorInfoID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AsyncMonitorInfo() {_init();}
  CLxLoc_AsyncMonitorInfo(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AsyncMonitorInfo(const CLxLoc_AsyncMonitorInfo &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AsyncMonitorInfo;}
    LxResult
  System (const char **system)
  {
    return m_loc[0]->System (m_loc,system);
  }
    LxResult
  Title (const char **title)
  {
    return m_loc[0]->Title (m_loc,title);
  }
    LxResult
  Progress (double *progress)
  {
    return m_loc[0]->Progress (m_loc,progress);
  }
    LxResult
  OverallProgress (double *progress)
  {
    return m_loc[0]->OverallProgress (m_loc,progress);
  }
    LxResult
  Parent (void **ppvObj)
  {
    return m_loc[0]->Parent (m_loc,ppvObj);
  }
    CLxResult
  Parent (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Parent(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Child (void **ppvObj)
  {
    return m_loc[0]->Child (m_loc,ppvObj);
  }
    CLxResult
  Child (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Child(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Identifier (const char **ident)
  {
    return m_loc[0]->Identifier (m_loc,ident);
  }
    LxResult
  CanAbort (void)
  {
    return m_loc[0]->CanAbort (m_loc);
  }
    LxResult
  Abort (void)
  {
    return m_loc[0]->Abort (m_loc);
  }
    LxResult
  IsAborted (void)
  {
    return m_loc[0]->IsAborted (m_loc);
  }
};

class CLxImpl_ColorDialog {
  public:
    virtual ~CLxImpl_ColorDialog() {}
    virtual LxResult
      colordlg_DoDialog (const char *title, double stops, double gamma, double *rgb)
        { return LXe_NOTIMPL; }
};
#define LXxD_ColorDialog_DoDialog LxResult colordlg_DoDialog (const char *title, double stops, double gamma, double *rgb)
#define LXxO_ColorDialog_DoDialog LXxD_ColorDialog_DoDialog LXx_OVERRIDE
#define LXxC_ColorDialog_DoDialog(c) LxResult c::colordlg_DoDialog (const char *title, double stops, double gamma, double *rgb)
template <class T>
class CLxIfc_ColorDialog : public CLxInterface
{
    static LxResult
  DoDialog (LXtObjectID wcom, const char *title, double stops, double gamma, double *rgb)
  {
    LXCWxINST (CLxImpl_ColorDialog, loc);
    try {
      return loc->colordlg_DoDialog (title,stops,gamma,rgb);
    } catch (LxResult rc) { return rc; }
  }
  ILxColorDialog vt;
public:
  CLxIfc_ColorDialog ()
  {
    vt.DoDialog = DoDialog;
    vTable = &vt.iunk;
    iid = &lx::guid_ColorDialog;
  }
};
class CLxLoc_ColorDialog : public CLxLocalize<ILxColorDialogID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ColorDialog() {_init();}
  CLxLoc_ColorDialog(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ColorDialog(const CLxLoc_ColorDialog &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ColorDialog;}
    LxResult
  DoDialog (const char *title, double stops, double gamma, double *rgb)
  {
    return m_loc[0]->DoDialog (m_loc,title,stops,gamma,rgb);
  }
};

class CLxLoc_AsyncMonitorSystem : public CLxLocalize<ILxAsyncMonitorSystemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AsyncMonitorSystem() {_init();}
  CLxLoc_AsyncMonitorSystem(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AsyncMonitorSystem(const CLxLoc_AsyncMonitorSystem &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AsyncMonitorSystem;}
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  Count (int *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  ByIndex (int index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  ByIndex (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_AsyncMonitorInfo1 {
  public:
    virtual ~CLxImpl_AsyncMonitorInfo1() {}
    virtual LxResult
      asy_System (const char **system)
        { return LXe_NOTIMPL; }
    virtual LxResult
      asy_Title (const char **title)
        { return LXe_NOTIMPL; }
    virtual LxResult
      asy_Progress (double *progress)
        { return LXe_NOTIMPL; }
    virtual LxResult
      asy_OverallProgress (double *progress)
        { return LXe_NOTIMPL; }
    virtual LxResult
      asy_Parent (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      asy_Child (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      asy_Identifier (const char **ident)
        { return LXe_NOTIMPL; }
    virtual LxResult
      asy_Abort (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      asy_IsAborted (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_AsyncMonitorInfo1_System LxResult asy_System (const char **system)
#define LXxO_AsyncMonitorInfo1_System LXxD_AsyncMonitorInfo1_System LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo1_System(c) LxResult c::asy_System (const char **system)
#define LXxD_AsyncMonitorInfo1_Title LxResult asy_Title (const char **title)
#define LXxO_AsyncMonitorInfo1_Title LXxD_AsyncMonitorInfo1_Title LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo1_Title(c) LxResult c::asy_Title (const char **title)
#define LXxD_AsyncMonitorInfo1_Progress LxResult asy_Progress (double *progress)
#define LXxO_AsyncMonitorInfo1_Progress LXxD_AsyncMonitorInfo1_Progress LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo1_Progress(c) LxResult c::asy_Progress (double *progress)
#define LXxD_AsyncMonitorInfo1_OverallProgress LxResult asy_OverallProgress (double *progress)
#define LXxO_AsyncMonitorInfo1_OverallProgress LXxD_AsyncMonitorInfo1_OverallProgress LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo1_OverallProgress(c) LxResult c::asy_OverallProgress (double *progress)
#define LXxD_AsyncMonitorInfo1_Parent LxResult asy_Parent (void **ppvObj)
#define LXxO_AsyncMonitorInfo1_Parent LXxD_AsyncMonitorInfo1_Parent LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo1_Parent(c) LxResult c::asy_Parent (void **ppvObj)
#define LXxD_AsyncMonitorInfo1_Child LxResult asy_Child (void **ppvObj)
#define LXxO_AsyncMonitorInfo1_Child LXxD_AsyncMonitorInfo1_Child LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo1_Child(c) LxResult c::asy_Child (void **ppvObj)
#define LXxD_AsyncMonitorInfo1_Identifier LxResult asy_Identifier (const char **ident)
#define LXxO_AsyncMonitorInfo1_Identifier LXxD_AsyncMonitorInfo1_Identifier LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo1_Identifier(c) LxResult c::asy_Identifier (const char **ident)
#define LXxD_AsyncMonitorInfo1_Abort LxResult asy_Abort (void)
#define LXxO_AsyncMonitorInfo1_Abort LXxD_AsyncMonitorInfo1_Abort LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo1_Abort(c) LxResult c::asy_Abort (void)
#define LXxD_AsyncMonitorInfo1_IsAborted LxResult asy_IsAborted (void)
#define LXxO_AsyncMonitorInfo1_IsAborted LXxD_AsyncMonitorInfo1_IsAborted LXx_OVERRIDE
#define LXxC_AsyncMonitorInfo1_IsAborted(c) LxResult c::asy_IsAborted (void)
template <class T>
class CLxIfc_AsyncMonitorInfo1 : public CLxInterface
{
    static LxResult
  System (LXtObjectID wcom, const char **system)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
    try {
      return loc->asy_System (system);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Title (LXtObjectID wcom, const char **title)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
    try {
      return loc->asy_Title (title);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Progress (LXtObjectID wcom, double *progress)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
    try {
      return loc->asy_Progress (progress);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  OverallProgress (LXtObjectID wcom, double *progress)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
    try {
      return loc->asy_OverallProgress (progress);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Parent (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
    try {
      return loc->asy_Parent (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Child (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
    try {
      return loc->asy_Child (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Identifier (LXtObjectID wcom, const char **ident)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
    try {
      return loc->asy_Identifier (ident);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Abort (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
    try {
      return loc->asy_Abort ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsAborted (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AsyncMonitorInfo1, loc);
    try {
      return loc->asy_IsAborted ();
    } catch (LxResult rc) { return rc; }
  }
  ILxAsyncMonitorInfo1 vt;
public:
  CLxIfc_AsyncMonitorInfo1 ()
  {
    vt.System = System;
    vt.Title = Title;
    vt.Progress = Progress;
    vt.OverallProgress = OverallProgress;
    vt.Parent = Parent;
    vt.Child = Child;
    vt.Identifier = Identifier;
    vt.Abort = Abort;
    vt.IsAborted = IsAborted;
    vTable = &vt.iunk;
    iid = &lx::guid_AsyncMonitorInfo1;
  }
};
class CLxLoc_AsyncMonitorInfo1 : public CLxLocalize<ILxAsyncMonitorInfo1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AsyncMonitorInfo1() {_init();}
  CLxLoc_AsyncMonitorInfo1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AsyncMonitorInfo1(const CLxLoc_AsyncMonitorInfo1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AsyncMonitorInfo1;}
    LxResult
  System (const char **system)
  {
    return m_loc[0]->System (m_loc,system);
  }
    LxResult
  Title (const char **title)
  {
    return m_loc[0]->Title (m_loc,title);
  }
    LxResult
  Progress (double *progress)
  {
    return m_loc[0]->Progress (m_loc,progress);
  }
    LxResult
  OverallProgress (double *progress)
  {
    return m_loc[0]->OverallProgress (m_loc,progress);
  }
    LxResult
  Parent (void **ppvObj)
  {
    return m_loc[0]->Parent (m_loc,ppvObj);
  }
    CLxResult
  Parent (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Parent(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Child (void **ppvObj)
  {
    return m_loc[0]->Child (m_loc,ppvObj);
  }
    CLxResult
  Child (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Child(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Identifier (const char **ident)
  {
    return m_loc[0]->Identifier (m_loc,ident);
  }
    LxResult
  Abort (void)
  {
    return m_loc[0]->Abort (m_loc);
  }
    LxResult
  IsAborted (void)
  {
    return m_loc[0]->IsAborted (m_loc);
  }
};

class CLxImpl_FileDialogClient {
  public:
    virtual ~CLxImpl_FileDialogClient() {}
    virtual unsigned
      filedlg_Flags (void)
        { return LXfFILEDIALOG_LOAD; }
    virtual LxResult
      filedlg_Title (ILxUnknownID message)
        { return LXe_NOTIMPL; }
    virtual const char *
      filedlg_FileClass (void)
        { return 0; }
    virtual LxResult
      filedlg_ContextString (const char **context)
        { return LXe_NOTIMPL; }
    virtual LxResult
      filedlg_FileFormat (const char **format)
        { return LXe_NOTIMPL; }
    virtual LxResult
      filedlg_StartPath (const char **filepath)
        { return LXe_NOTIMPL; }
    virtual LxResult
      filedlg_ResultPath (const char *filepath)
        { return LXe_NOTIMPL; }
    virtual LxResult
      filedlg_ResultFormat (const char *format)
        { return LXe_NOTIMPL; }
};
#define LXxD_FileDialogClient_Flags unsigned filedlg_Flags (void)
#define LXxO_FileDialogClient_Flags LXxD_FileDialogClient_Flags LXx_OVERRIDE
#define LXxC_FileDialogClient_Flags(c) unsigned c::filedlg_Flags (void)
#define LXxD_FileDialogClient_Title LxResult filedlg_Title (ILxUnknownID message)
#define LXxO_FileDialogClient_Title LXxD_FileDialogClient_Title LXx_OVERRIDE
#define LXxC_FileDialogClient_Title(c) LxResult c::filedlg_Title (ILxUnknownID message)
#define LXxD_FileDialogClient_FileClass const char * filedlg_FileClass (void)
#define LXxO_FileDialogClient_FileClass LXxD_FileDialogClient_FileClass LXx_OVERRIDE
#define LXxC_FileDialogClient_FileClass(c) const char * c::filedlg_FileClass (void)
#define LXxD_FileDialogClient_ContextString LxResult filedlg_ContextString (const char **context)
#define LXxO_FileDialogClient_ContextString LXxD_FileDialogClient_ContextString LXx_OVERRIDE
#define LXxC_FileDialogClient_ContextString(c) LxResult c::filedlg_ContextString (const char **context)
#define LXxD_FileDialogClient_FileFormat LxResult filedlg_FileFormat (const char **format)
#define LXxO_FileDialogClient_FileFormat LXxD_FileDialogClient_FileFormat LXx_OVERRIDE
#define LXxC_FileDialogClient_FileFormat(c) LxResult c::filedlg_FileFormat (const char **format)
#define LXxD_FileDialogClient_StartPath LxResult filedlg_StartPath (const char **filepath)
#define LXxO_FileDialogClient_StartPath LXxD_FileDialogClient_StartPath LXx_OVERRIDE
#define LXxC_FileDialogClient_StartPath(c) LxResult c::filedlg_StartPath (const char **filepath)
#define LXxD_FileDialogClient_ResultPath LxResult filedlg_ResultPath (const char *filepath)
#define LXxO_FileDialogClient_ResultPath LXxD_FileDialogClient_ResultPath LXx_OVERRIDE
#define LXxC_FileDialogClient_ResultPath(c) LxResult c::filedlg_ResultPath (const char *filepath)
#define LXxD_FileDialogClient_ResultFormat LxResult filedlg_ResultFormat (const char *format)
#define LXxO_FileDialogClient_ResultFormat LXxD_FileDialogClient_ResultFormat LXx_OVERRIDE
#define LXxC_FileDialogClient_ResultFormat(c) LxResult c::filedlg_ResultFormat (const char *format)
template <class T>
class CLxIfc_FileDialogClient : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_FileDialogClient, loc);
    return loc->filedlg_Flags ();
  }
    static LxResult
  Title (LXtObjectID wcom, LXtObjectID message)
  {
    LXCWxINST (CLxImpl_FileDialogClient, loc);
    try {
      return loc->filedlg_Title ((ILxUnknownID)message);
    } catch (LxResult rc) { return rc; }
  }
    static const char *
  FileClass (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_FileDialogClient, loc);
    return loc->filedlg_FileClass ();
  }
    static LxResult
  ContextString (LXtObjectID wcom, const char **context)
  {
    LXCWxINST (CLxImpl_FileDialogClient, loc);
    try {
      return loc->filedlg_ContextString (context);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FileFormat (LXtObjectID wcom, const char **format)
  {
    LXCWxINST (CLxImpl_FileDialogClient, loc);
    try {
      return loc->filedlg_FileFormat (format);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  StartPath (LXtObjectID wcom, const char **filepath)
  {
    LXCWxINST (CLxImpl_FileDialogClient, loc);
    try {
      return loc->filedlg_StartPath (filepath);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ResultPath (LXtObjectID wcom, const char *filepath)
  {
    LXCWxINST (CLxImpl_FileDialogClient, loc);
    try {
      return loc->filedlg_ResultPath (filepath);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ResultFormat (LXtObjectID wcom, const char *format)
  {
    LXCWxINST (CLxImpl_FileDialogClient, loc);
    try {
      return loc->filedlg_ResultFormat (format);
    } catch (LxResult rc) { return rc; }
  }
  ILxFileDialogClient vt;
public:
  CLxIfc_FileDialogClient ()
  {
    vt.Flags = Flags;
    vt.Title = Title;
    vt.FileClass = FileClass;
    vt.ContextString = ContextString;
    vt.FileFormat = FileFormat;
    vt.StartPath = StartPath;
    vt.ResultPath = ResultPath;
    vt.ResultFormat = ResultFormat;
    vTable = &vt.iunk;
    iid = &lx::guid_FileDialogClient;
  }
};

class CLxLoc_StdDialogService : public CLxLocalizedService
{
public:
  ILxStdDialogServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_StdDialogService() {_init();set();}
 ~CLxLoc_StdDialogService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxStdDialogServiceID>(lx::GetGlobal(&lx::guid_StdDialogService));}
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
  MonitorAllocate (const char *title, void **ppvObj)
  {
    return m_loc[0]->MonitorAllocate (m_loc,title,ppvObj);
  }
    CLxResult
  MonitorAllocate (const char *title, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->MonitorAllocate(m_loc,title,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  MonitorRelease (void)
  {
    return m_loc[0]->MonitorRelease (m_loc);
  }
    LxResult
  MessageAllocate (void **ppvObj)
  {
    return m_loc[0]->MessageAllocate (m_loc,ppvObj);
  }
    CLxResult
  MessageAllocate (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->MessageAllocate(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  MessageOpen (ILxUnknownID message, const char *title, const char *helpURL, const char *cookie)
  {
    return m_loc[0]->MessageOpen (m_loc,(ILxUnknownID)message,title,helpURL,cookie);
  }
    LxResult
  AsyncMonitorAllocate (const char *system, const char *title, void **ppvObj)
  {
    return m_loc[0]->AsyncMonitorAllocate (m_loc,system,title,ppvObj);
  }
    CLxResult
  AsyncMonitorAllocate (const char *system, const char *title, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AsyncMonitorAllocate(m_loc,system,title,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AsyncMonitorSubAllocate (ILxUnknownID parent, const char *title, void **ppvObj)
  {
    return m_loc[0]->AsyncMonitorSubAllocate (m_loc,(ILxUnknownID)parent,title,ppvObj);
  }
    CLxResult
  AsyncMonitorSubAllocate (ILxUnknownID parent, const char *title, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AsyncMonitorSubAllocate(m_loc,(ILxUnknownID)parent,title,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AsyncMonitorRelease (ILxUnknownID monitor)
  {
    return m_loc[0]->AsyncMonitorRelease (m_loc,(ILxUnknownID)monitor);
  }
    LxResult
  AsyncMonitorSystemCount (int *count)
  {
    return m_loc[0]->AsyncMonitorSystemCount (m_loc,count);
  }
    LxResult
  AsyncMonitorSystemByIndex (int index, void **ppvObj)
  {
    return m_loc[0]->AsyncMonitorSystemByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  AsyncMonitorSystemByIndex (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AsyncMonitorSystemByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AsyncMonitorSystemLookup (const char *name, void **ppvObj)
  {
    return m_loc[0]->AsyncMonitorSystemLookup (m_loc,name,ppvObj);
  }
    CLxResult
  AsyncMonitorSystemLookup (const char *name, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AsyncMonitorSystemLookup(m_loc,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AsyncMonitorLookup (const char *ident, void **ppvObj)
  {
    return m_loc[0]->AsyncMonitorLookup (m_loc,ident,ppvObj);
  }
    CLxResult
  AsyncMonitorLookup (const char *ident, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AsyncMonitorLookup(m_loc,ident,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  FileDialog (ILxUnknownID dlgObj)
  {
    return m_loc[0]->FileDialog (m_loc,(ILxUnknownID)dlgObj);
  }
    LxResult
  AsyncMonitorAllocateWithoutAbort (const char *system, const char *title, void **ppvObj)
  {
    return m_loc[0]->AsyncMonitorAllocateWithoutAbort (m_loc,system,title,ppvObj);
  }
    CLxResult
  AsyncMonitorAllocateWithoutAbort (const char *system, const char *title, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AsyncMonitorAllocateWithoutAbort(m_loc,system,title,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  MonitorReleaseObj (ILxUnknownID monitor)
  {
    return m_loc[0]->MonitorReleaseObj (m_loc,(ILxUnknownID)monitor);
  }
};

#endif

