/*
 * C++ wrapper for lxpreview.h
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
#ifndef LXW_PREVIEW_HPP
#define LXW_PREVIEW_HPP

#include <lxpreview.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_Preview = {0x6817942a,0x375d,0x485f,0xb9,0x27,0xaf,0x93,0xd1,0x39,0x1d,0x73};
    static const LXtGUID guid_PreviewNotifier = {0x352039c2,0x8b70,0x46db,0x9a,0x83,0x1e,0x05,0xfd,0x88,0x7f,0xc0};
    static const LXtGUID guid_PreviewService = {0x0491f901,0x6eee,0x48e4,0xa4,0xd0,0xb2,0xe6,0xd1,0x06,0x24,0xb6};
};

class CLxLoc_Preview : public CLxLocalize<ILxPreviewID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Preview() {_init();}
  CLxLoc_Preview(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Preview(const CLxLoc_Preview &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Preview;}
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
  SetRes (int width, int height) const
  {
    return m_loc[0]->SetRes (m_loc,width,height);
  }
    LxResult
  SetRenderTime (double time)
  {
    return m_loc[0]->SetRenderTime (m_loc,time);
  }
    LxResult
  SetQuality (int quality, int samples) const
  {
    return m_loc[0]->SetQuality (m_loc,quality,samples);
  }
    LxResult
  SetMotionBlur (int enable)
  {
    return m_loc[0]->SetMotionBlur (m_loc,enable);
  }
    LxResult
  SetRenderAllOutputs (int enable) const
  {
    return m_loc[0]->SetRenderAllOutputs (m_loc,enable);
  }
    LxResult
  SetUseAllThreads (int enable) const
  {
    return m_loc[0]->SetUseAllThreads (m_loc,enable);
  }
    LxResult
  SetStereo (int enable, int eye) const
  {
    return m_loc[0]->SetStereo (m_loc,enable,eye);
  }
    LxResult
  SetNotifier (ILxUnknownID notifier)
  {
    return m_loc[0]->SetNotifier (m_loc,(ILxUnknownID)notifier);
  }
    LxResult
  SetAlpha (int enable)
  {
    return m_loc[0]->SetAlpha (m_loc,enable);
  }
    LxResult
  UseCameraOverride (int useCameraOverride)
  {
    return m_loc[0]->UseCameraOverride (m_loc,useCameraOverride);
  }
    LxResult
  SetCameraOverrideTransform (const LXtMatrix4 transform)
  {
    return m_loc[0]->SetCameraOverrideTransform (m_loc,transform);
  }
    LxResult
  SetCameraOverrideFocalLength (float focalLength)
  {
    return m_loc[0]->SetCameraOverrideFocalLength (m_loc,focalLength);
  }
    LxResult
  SetCameraOverrideApertureX (float apertureX)
  {
    return m_loc[0]->SetCameraOverrideApertureX (m_loc,apertureX);
  }
    LxResult
  SetCameraOverrideApertureY (float apertureY)
  {
    return m_loc[0]->SetCameraOverrideApertureY (m_loc,apertureY);
  }
    LxResult
  SetCameraOverrideProjectionType (int projectionType)
  {
    return m_loc[0]->SetCameraOverrideProjectionType (m_loc,projectionType);
  }
    int
  GetResWidth (void)
  {
    return m_loc[0]->GetResWidth (m_loc);
  }
    int
  GetResHeight (void)
  {
    return m_loc[0]->GetResHeight (m_loc);
  }
    double
  GetCurrentTime (void)
  {
    return m_loc[0]->GetCurrentTime (m_loc);
  }
    LxResult
  IsComplete (void) const
  {
    return m_loc[0]->IsComplete (m_loc);
  }
    LxResult
  GetBuffer (void **ppvObj) const
  {
    return m_loc[0]->GetBuffer (m_loc,ppvObj);
  }
    CLxResult
  GetBuffer (CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetBuffer(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetEffect (const char *effect) const
  {
    return m_loc[0]->SetEffect (m_loc,effect);
  }
    LxResult
  SetBakeMode (int mode) const
  {
    return m_loc[0]->SetBakeMode (m_loc,mode);
  }
    LxResult
  SetLastTexture (ILxUnknownID item) const
  {
    return m_loc[0]->SetLastTexture (m_loc,(ILxUnknownID)item);
  }
    float
  GetProgress (void) const
  {
    return m_loc[0]->GetProgress (m_loc);
  }
    void
  SetIgnoreSelections (int allow) const
  {
    m_loc[0]->SetIgnoreSelections (m_loc,allow);
  }
    LxResult
  IsFinished (void) const
  {
    return m_loc[0]->IsFinished (m_loc);
  }
};

class CLxImpl_PreviewNotifier {
  public:
    virtual ~CLxImpl_PreviewNotifier() {}
    virtual LxResult
      ntf_Notify (const LXtRenderOutputProcess *rndrProcess, ILxUnknownID image, int completed)
        { return LXe_NOTIMPL; }
};
#define LXxD_PreviewNotifier_Notify LxResult ntf_Notify (const LXtRenderOutputProcess *rndrProcess, ILxUnknownID image, int completed)
#define LXxO_PreviewNotifier_Notify LXxD_PreviewNotifier_Notify LXx_OVERRIDE
#define LXxC_PreviewNotifier_Notify(c) LxResult c::ntf_Notify (const LXtRenderOutputProcess *rndrProcess, ILxUnknownID image, int completed)
template <class T>
class CLxIfc_PreviewNotifier : public CLxInterface
{
    static LxResult
  Notify (LXtObjectID wcom, const LXtRenderOutputProcess *rndrProcess, LXtObjectID image, int completed)
  {
    LXCWxINST (CLxImpl_PreviewNotifier, loc);
    try {
      return loc->ntf_Notify (rndrProcess,(ILxUnknownID)image,completed);
    } catch (LxResult rc) { return rc; }
  }
  ILxPreviewNotifier vt;
public:
  CLxIfc_PreviewNotifier ()
  {
    vt.Notify = Notify;
    vTable = &vt.iunk;
    iid = &lx::guid_PreviewNotifier;
  }
};
class CLxLoc_PreviewNotifier : public CLxLocalize<ILxPreviewNotifierID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PreviewNotifier() {_init();}
  CLxLoc_PreviewNotifier(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PreviewNotifier(const CLxLoc_PreviewNotifier &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PreviewNotifier;}
    LxResult
  Notify (const LXtRenderOutputProcess *rndrProcess, ILxUnknownID image, int completed)
  {
    return m_loc[0]->Notify (m_loc,rndrProcess,(ILxUnknownID)image,completed);
  }
};

class CLxLoc_PreviewService : public CLxLocalizedService
{
public:
  ILxPreviewServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_PreviewService() {_init();set();}
 ~CLxLoc_PreviewService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxPreviewServiceID>(lx::GetGlobal(&lx::guid_PreviewService));}
    LxResult
  CreatePreview (void **ppvObj)
  {
    return m_loc[0]->CreatePreview (m_loc,ppvObj);
  }
    CLxResult
  CreatePreview (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreatePreview(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetMeshPreview (ILxUnknownID item, int width, int height, void **ppvObj)
  {
    return m_loc[0]->GetMeshPreview (m_loc,(ILxUnknownID)item,width,height,ppvObj);
  }
    CLxResult
  GetMeshPreview (ILxUnknownID item, int width, int height, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetMeshPreview(m_loc,(ILxUnknownID)item,width,height,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

