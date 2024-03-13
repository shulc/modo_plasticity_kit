/*
 * C++ wrapper for lxinterviewer.h
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
#ifndef LXW_INTERVIEWER_HPP
#define LXW_INTERVIEWER_HPP

#include <lxinterviewer.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_Interviewer = {0x7039c075,0x3d04,0x4cc0,0xb3,0xcf,0xf3,0xde,0x50,0x9b,0x6a,0x20};
    static const LXtGUID guid_InterviewerService = {0x5f892557,0x80a5,0x4490,0xb3,0x14,0xd5,0xf1,0x9f,0xf9,0xa6,0xb6};
};

class CLxImpl_Interviewer {
  public:
    virtual ~CLxImpl_Interviewer() {}
    virtual LxResult
      intrv_Title (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      intrv_Description (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      intrv_ButtonLabel (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      intrv_ButtonCommand (char *buf, int len)
        { return LXe_NOTIMPL; }
};
#define LXxD_Interviewer_Title LxResult intrv_Title (char *buf, int len)
#define LXxO_Interviewer_Title LXxD_Interviewer_Title LXx_OVERRIDE
#define LXxC_Interviewer_Title(c) LxResult c::intrv_Title (char *buf, int len)
#define LXxD_Interviewer_Description LxResult intrv_Description (char *buf, int len)
#define LXxO_Interviewer_Description LXxD_Interviewer_Description LXx_OVERRIDE
#define LXxC_Interviewer_Description(c) LxResult c::intrv_Description (char *buf, int len)
#define LXxD_Interviewer_ButtonLabel LxResult intrv_ButtonLabel (char *buf, int len)
#define LXxO_Interviewer_ButtonLabel LXxD_Interviewer_ButtonLabel LXx_OVERRIDE
#define LXxC_Interviewer_ButtonLabel(c) LxResult c::intrv_ButtonLabel (char *buf, int len)
#define LXxD_Interviewer_ButtonCommand LxResult intrv_ButtonCommand (char *buf, int len)
#define LXxO_Interviewer_ButtonCommand LXxD_Interviewer_ButtonCommand LXx_OVERRIDE
#define LXxC_Interviewer_ButtonCommand(c) LxResult c::intrv_ButtonCommand (char *buf, int len)
template <class T>
class CLxIfc_Interviewer : public CLxInterface
{
    static LxResult
  Title (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_Interviewer, loc);
    try {
      return loc->intrv_Title (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Description (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_Interviewer, loc);
    try {
      return loc->intrv_Description (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ButtonLabel (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_Interviewer, loc);
    try {
      return loc->intrv_ButtonLabel (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ButtonCommand (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_Interviewer, loc);
    try {
      return loc->intrv_ButtonCommand (buf,len);
    } catch (LxResult rc) { return rc; }
  }
  ILxInterviewer vt;
public:
  CLxIfc_Interviewer ()
  {
    vt.Title = Title;
    vt.Description = Description;
    vt.ButtonLabel = ButtonLabel;
    vt.ButtonCommand = ButtonCommand;
    vTable = &vt.iunk;
    iid = &lx::guid_Interviewer;
  }
};
class CLxLoc_Interviewer : public CLxLocalize<ILxInterviewerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Interviewer() {_init();}
  CLxLoc_Interviewer(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Interviewer(const CLxLoc_Interviewer &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Interviewer;}
    LxResult
  Title (char *buf, int len)
  {
    return m_loc[0]->Title (m_loc,buf,len);
  }
    LxResult
  Description (char *buf, int len)
  {
    return m_loc[0]->Description (m_loc,buf,len);
  }
    LxResult
  ButtonLabel (char *buf, int len)
  {
    return m_loc[0]->ButtonLabel (m_loc,buf,len);
  }
    LxResult
  ButtonCommand (char *buf, int len)
  {
    return m_loc[0]->ButtonCommand (m_loc,buf,len);
  }
};

class CLxLoc_InterviewerService : public CLxLocalizedService
{
public:
  ILxInterviewerServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_InterviewerService() {_init();set();}
 ~CLxLoc_InterviewerService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxInterviewerServiceID>(lx::GetGlobal(&lx::guid_InterviewerService));}
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
  Arm (const char *serverName, int target)
  {
    return m_loc[0]->Arm (m_loc,serverName,target);
  }
    LxResult
  Disarm (const char *serverName, int allowRearm)
  {
    return m_loc[0]->Disarm (m_loc,serverName,allowRearm);
  }
    LxResult
  WasFired (const char *serverName)
  {
    return m_loc[0]->WasFired (m_loc,serverName);
  }
    LxResult
  ClearDismissTimer (const char *serverName)
  {
    return m_loc[0]->ClearDismissTimer (m_loc,serverName);
  }
};

#endif

