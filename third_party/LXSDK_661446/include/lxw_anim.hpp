/*
 * C++ wrapper for lxanim.h
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
#ifndef LXW_ANIM_HPP
#define LXW_ANIM_HPP

#include <lxanim.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_AnimListener = {0x4A0862DA,0xCAC6,0x48EC,0xA3,0xDA,0xDE,0x28,0x5F,0xE5,0x28,0xB5};
};

class CLxImpl_AnimListener {
  public:
    virtual ~CLxImpl_AnimListener() {}
    virtual LxResult
      animevent_TimeChange (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      animevent_PlayStart (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      animevent_PlayEnd (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      animevent_ScrubTime (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      animevent_ScrubEnd (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      animevent_EnterSetup (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      animevent_LeaveSetup (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_AnimListener_TimeChange LxResult animevent_TimeChange (void)
#define LXxO_AnimListener_TimeChange LXxD_AnimListener_TimeChange LXx_OVERRIDE
#define LXxC_AnimListener_TimeChange(c) LxResult c::animevent_TimeChange (void)
#define LXxD_AnimListener_PlayStart LxResult animevent_PlayStart (void)
#define LXxO_AnimListener_PlayStart LXxD_AnimListener_PlayStart LXx_OVERRIDE
#define LXxC_AnimListener_PlayStart(c) LxResult c::animevent_PlayStart (void)
#define LXxD_AnimListener_PlayEnd LxResult animevent_PlayEnd (void)
#define LXxO_AnimListener_PlayEnd LXxD_AnimListener_PlayEnd LXx_OVERRIDE
#define LXxC_AnimListener_PlayEnd(c) LxResult c::animevent_PlayEnd (void)
#define LXxD_AnimListener_ScrubTime LxResult animevent_ScrubTime (void)
#define LXxO_AnimListener_ScrubTime LXxD_AnimListener_ScrubTime LXx_OVERRIDE
#define LXxC_AnimListener_ScrubTime(c) LxResult c::animevent_ScrubTime (void)
#define LXxD_AnimListener_ScrubEnd LxResult animevent_ScrubEnd (void)
#define LXxO_AnimListener_ScrubEnd LXxD_AnimListener_ScrubEnd LXx_OVERRIDE
#define LXxC_AnimListener_ScrubEnd(c) LxResult c::animevent_ScrubEnd (void)
#define LXxD_AnimListener_EnterSetup LxResult animevent_EnterSetup (void)
#define LXxO_AnimListener_EnterSetup LXxD_AnimListener_EnterSetup LXx_OVERRIDE
#define LXxC_AnimListener_EnterSetup(c) LxResult c::animevent_EnterSetup (void)
#define LXxD_AnimListener_LeaveSetup LxResult animevent_LeaveSetup (void)
#define LXxO_AnimListener_LeaveSetup LXxD_AnimListener_LeaveSetup LXx_OVERRIDE
#define LXxC_AnimListener_LeaveSetup(c) LxResult c::animevent_LeaveSetup (void)
template <class T>
class CLxIfc_AnimListener : public CLxInterface
{
    static LxResult
  TimeChange (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AnimListener, loc);
    try {
      return loc->animevent_TimeChange ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PlayStart (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AnimListener, loc);
    try {
      return loc->animevent_PlayStart ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PlayEnd (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AnimListener, loc);
    try {
      return loc->animevent_PlayEnd ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ScrubTime (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AnimListener, loc);
    try {
      return loc->animevent_ScrubTime ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ScrubEnd (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AnimListener, loc);
    try {
      return loc->animevent_ScrubEnd ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  EnterSetup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AnimListener, loc);
    try {
      return loc->animevent_EnterSetup ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LeaveSetup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AnimListener, loc);
    try {
      return loc->animevent_LeaveSetup ();
    } catch (LxResult rc) { return rc; }
  }
  ILxAnimListener vt;
public:
  CLxIfc_AnimListener ()
  {
    vt.TimeChange = TimeChange;
    vt.PlayStart = PlayStart;
    vt.PlayEnd = PlayEnd;
    vt.ScrubTime = ScrubTime;
    vt.ScrubEnd = ScrubEnd;
    vt.EnterSetup = EnterSetup;
    vt.LeaveSetup = LeaveSetup;
    vTable = &vt.iunk;
    iid = &lx::guid_AnimListener;
  }
};
class CLxLoc_AnimListener : public CLxLocalize<ILxAnimListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AnimListener() {_init();}
  CLxLoc_AnimListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AnimListener(const CLxLoc_AnimListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AnimListener;}
    LxResult
  TimeChange (void)
  {
    return m_loc[0]->TimeChange (m_loc);
  }
    LxResult
  PlayStart (void)
  {
    return m_loc[0]->PlayStart (m_loc);
  }
    LxResult
  PlayEnd (void)
  {
    return m_loc[0]->PlayEnd (m_loc);
  }
    LxResult
  ScrubTime (void)
  {
    return m_loc[0]->ScrubTime (m_loc);
  }
    LxResult
  ScrubEnd (void)
  {
    return m_loc[0]->ScrubEnd (m_loc);
  }
    LxResult
  EnterSetup (void)
  {
    return m_loc[0]->EnterSetup (m_loc);
  }
    LxResult
  LeaveSetup (void)
  {
    return m_loc[0]->LeaveSetup (m_loc);
  }
};

#endif

