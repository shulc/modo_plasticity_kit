/*
 * C++ wrapper for lxexternalrender.h
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
#ifndef LXW_EXTERNALRENDER_HPP
#define LXW_EXTERNALRENDER_HPP

#include <lxexternalrender.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ExternalRenderBufferQueue = {0x17F0A6B6,0x9B36,0x4BE2,0xB6,0x5B,0x76,0xD2,0xAC,0x3F,0x57,0x53};
    static const LXtGUID guid_ExternalRender = {0x4D764AD2,0xE3B8,0x4689,0x93,0xE0,0x61,0x31,0x07,0xE0,0x44,0xB8};
    static const LXtGUID guid_ExternalRenderNotifier = {0x2D7FFF27,0x5E49,0x47C2,0x92,0x8D,0x38,0x0D,0x8E,0x18,0xE8,0xF9};
};

class CLxLoc_ExternalRenderBufferQueue : public CLxLocalize<ILxExternalRenderBufferQueueID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ExternalRenderBufferQueue() {_init();}
  CLxLoc_ExternalRenderBufferQueue(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ExternalRenderBufferQueue(const CLxLoc_ExternalRenderBufferQueue &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ExternalRenderBufferQueue;}
    LxResult
  WriteBegin (LXtExternalRenderBuffer *buffer)
  {
    return m_loc[0]->WriteBegin (m_loc,buffer);
  }
    LxResult
  WriteEnd (LXtExternalRenderBuffer *buffer)
  {
    return m_loc[0]->WriteEnd (m_loc,buffer);
  }
};

class CLxImpl_ExternalRender {
  public:
    virtual ~CLxImpl_ExternalRender() {}
    virtual LxResult
      rend_Start (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rend_Stop (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rend_Pause (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rend_Reset (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rend_SelectedPixelAt (const int x, const int y)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rend_SetNotifier (ILxUnknownID notifier)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rend_SetBufferQueue (ILxUnknownID bufferQueue)
        { return LXe_NOTIMPL; }
};
#define LXxD_ExternalRender_Start LxResult rend_Start (void)
#define LXxO_ExternalRender_Start LXxD_ExternalRender_Start LXx_OVERRIDE
#define LXxC_ExternalRender_Start(c) LxResult c::rend_Start (void)
#define LXxD_ExternalRender_Stop LxResult rend_Stop (void)
#define LXxO_ExternalRender_Stop LXxD_ExternalRender_Stop LXx_OVERRIDE
#define LXxC_ExternalRender_Stop(c) LxResult c::rend_Stop (void)
#define LXxD_ExternalRender_Pause LxResult rend_Pause (void)
#define LXxO_ExternalRender_Pause LXxD_ExternalRender_Pause LXx_OVERRIDE
#define LXxC_ExternalRender_Pause(c) LxResult c::rend_Pause (void)
#define LXxD_ExternalRender_Reset LxResult rend_Reset (void)
#define LXxO_ExternalRender_Reset LXxD_ExternalRender_Reset LXx_OVERRIDE
#define LXxC_ExternalRender_Reset(c) LxResult c::rend_Reset (void)
#define LXxD_ExternalRender_SelectedPixelAt LxResult rend_SelectedPixelAt (const int x, const int y)
#define LXxO_ExternalRender_SelectedPixelAt LXxD_ExternalRender_SelectedPixelAt LXx_OVERRIDE
#define LXxC_ExternalRender_SelectedPixelAt(c) LxResult c::rend_SelectedPixelAt (const int x, const int y)
#define LXxD_ExternalRender_SetNotifier LxResult rend_SetNotifier (ILxUnknownID notifier)
#define LXxO_ExternalRender_SetNotifier LXxD_ExternalRender_SetNotifier LXx_OVERRIDE
#define LXxC_ExternalRender_SetNotifier(c) LxResult c::rend_SetNotifier (ILxUnknownID notifier)
#define LXxD_ExternalRender_SetBufferQueue LxResult rend_SetBufferQueue (ILxUnknownID bufferQueue)
#define LXxO_ExternalRender_SetBufferQueue LXxD_ExternalRender_SetBufferQueue LXx_OVERRIDE
#define LXxC_ExternalRender_SetBufferQueue(c) LxResult c::rend_SetBufferQueue (ILxUnknownID bufferQueue)
template <class T>
class CLxIfc_ExternalRender : public CLxInterface
{
    static LxResult
  Start (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ExternalRender, loc);
    try {
      return loc->rend_Start ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Stop (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ExternalRender, loc);
    try {
      return loc->rend_Stop ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Pause (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ExternalRender, loc);
    try {
      return loc->rend_Pause ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Reset (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ExternalRender, loc);
    try {
      return loc->rend_Reset ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SelectedPixelAt (LXtObjectID wcom, const int x, const int y)
  {
    LXCWxINST (CLxImpl_ExternalRender, loc);
    try {
      return loc->rend_SelectedPixelAt (x,y);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetNotifier (LXtObjectID wcom, LXtObjectID notifier)
  {
    LXCWxINST (CLxImpl_ExternalRender, loc);
    try {
      return loc->rend_SetNotifier ((ILxUnknownID)notifier);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetBufferQueue (LXtObjectID wcom, LXtObjectID bufferQueue)
  {
    LXCWxINST (CLxImpl_ExternalRender, loc);
    try {
      return loc->rend_SetBufferQueue ((ILxUnknownID)bufferQueue);
    } catch (LxResult rc) { return rc; }
  }
  ILxExternalRender vt;
public:
  CLxIfc_ExternalRender ()
  {
    vt.Start = Start;
    vt.Stop = Stop;
    vt.Pause = Pause;
    vt.Reset = Reset;
    vt.SelectedPixelAt = SelectedPixelAt;
    vt.SetNotifier = SetNotifier;
    vt.SetBufferQueue = SetBufferQueue;
    vTable = &vt.iunk;
    iid = &lx::guid_ExternalRender;
  }
};
class CLxLoc_ExternalRender : public CLxLocalize<ILxExternalRenderID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ExternalRender() {_init();}
  CLxLoc_ExternalRender(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ExternalRender(const CLxLoc_ExternalRender &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ExternalRender;}
    LxResult
  Start (void) const
  {
    return m_loc[0]->Start (m_loc);
  }
    LxResult
  Stop (void) const
  {
    return m_loc[0]->Stop (m_loc);
  }
    LxResult
  Pause (void) const
  {
    return m_loc[0]->Pause (m_loc);
  }
    LxResult
  Reset (void) const
  {
    return m_loc[0]->Reset (m_loc);
  }
    LxResult
  SelectedPixelAt (const int x, const int y) const
  {
    return m_loc[0]->SelectedPixelAt (m_loc,x,y);
  }
    LxResult
  SetNotifier (ILxUnknownID notifier)
  {
    return m_loc[0]->SetNotifier (m_loc,(ILxUnknownID)notifier);
  }
    LxResult
  SetBufferQueue (ILxUnknownID bufferQueue)
  {
    return m_loc[0]->SetBufferQueue (m_loc,(ILxUnknownID)bufferQueue);
  }
};

class CLxImpl_ExternalRenderNotifier {
  public:
    virtual ~CLxImpl_ExternalRenderNotifier() {}
    virtual LxResult
      ntf_Notify (const LXtRenderOutputProcess *rndrProcess, ILxUnknownID image, int completed)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ntf_SetStatusText (const char *text)
        { return LXe_NOTIMPL; }
};
#define LXxD_ExternalRenderNotifier_Notify LxResult ntf_Notify (const LXtRenderOutputProcess *rndrProcess, ILxUnknownID image, int completed)
#define LXxO_ExternalRenderNotifier_Notify LXxD_ExternalRenderNotifier_Notify LXx_OVERRIDE
#define LXxC_ExternalRenderNotifier_Notify(c) LxResult c::ntf_Notify (const LXtRenderOutputProcess *rndrProcess, ILxUnknownID image, int completed)
#define LXxD_ExternalRenderNotifier_SetStatusText LxResult ntf_SetStatusText (const char *text)
#define LXxO_ExternalRenderNotifier_SetStatusText LXxD_ExternalRenderNotifier_SetStatusText LXx_OVERRIDE
#define LXxC_ExternalRenderNotifier_SetStatusText(c) LxResult c::ntf_SetStatusText (const char *text)
template <class T>
class CLxIfc_ExternalRenderNotifier : public CLxInterface
{
    static LxResult
  Notify (LXtObjectID wcom, const LXtRenderOutputProcess *rndrProcess, LXtObjectID image, int completed)
  {
    LXCWxINST (CLxImpl_ExternalRenderNotifier, loc);
    try {
      return loc->ntf_Notify (rndrProcess,(ILxUnknownID)image,completed);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetStatusText (LXtObjectID wcom, const char *text)
  {
    LXCWxINST (CLxImpl_ExternalRenderNotifier, loc);
    try {
      return loc->ntf_SetStatusText (text);
    } catch (LxResult rc) { return rc; }
  }
  ILxExternalRenderNotifier vt;
public:
  CLxIfc_ExternalRenderNotifier ()
  {
    vt.Notify = Notify;
    vt.SetStatusText = SetStatusText;
    vTable = &vt.iunk;
    iid = &lx::guid_ExternalRenderNotifier;
  }
};
class CLxLoc_ExternalRenderNotifier : public CLxLocalize<ILxExternalRenderNotifierID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ExternalRenderNotifier() {_init();}
  CLxLoc_ExternalRenderNotifier(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ExternalRenderNotifier(const CLxLoc_ExternalRenderNotifier &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ExternalRenderNotifier;}
    LxResult
  Notify (const LXtRenderOutputProcess *rndrProcess, ILxUnknownID image, int completed)
  {
    return m_loc[0]->Notify (m_loc,rndrProcess,(ILxUnknownID)image,completed);
  }
    LxResult
  SetStatusText (const char *text)
  {
    return m_loc[0]->SetStatusText (m_loc,text);
  }
};

#endif

