/*
 * C++ wrapper for lximagemon.h
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
#ifndef LXW_IMAGEMON_HPP
#define LXW_IMAGEMON_HPP

#include <lximagemon.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ImageMonitor = {0x5ef021ed,0xa2e3,0x48d3,0xab,0xa1,0x7c,0xbb,0x81,0x5f,0x15,0xb7};
    static const LXtGUID guid_ImageMonitorService = {0xf59258f8,0x3e86,0x408f,0x9e,0x92,0xf8,0x1a,0x21,0xd0,0x1b,0xde};
};

class CLxImpl_ImageMonitor {
  public:
    virtual ~CLxImpl_ImageMonitor() {}
    virtual LxResult
      imon_Image (ILxUnknownID imageToAnalyze, ILxUnknownID frameBufferToAnalyze, int bufferIndex, double x1, double y1, double x2, double y2, ILxUnknownID imageProcessingRead, ILxUnknownID processedThumbnail)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_ImageProcChanged (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_AspectRange (double *minAspect, double *maxAspect, double *idealAspect)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_Draw (ILxUnknownID imageForDrawing)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_ImageSource (const char *source)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_MouseDown (int startx, int starty, int w, int h)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_MouseMove (int startx, int starty, int cx, int cy, int w, int h)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_MouseUp (int startx, int starty, int cx, int cy, int w, int h)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_MouseTrackEnter (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_MouseTrack (int cx, int cy, int w, int h)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_MouseTrackExit (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imon_ToolTip (int cx, int cy, int w, int h, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
};
#define LXxD_ImageMonitor_Image LxResult imon_Image (ILxUnknownID imageToAnalyze, ILxUnknownID frameBufferToAnalyze, int bufferIndex, double x1, double y1, double x2, double y2, ILxUnknownID imageProcessingRead, ILxUnknownID processedThumbnail)
#define LXxO_ImageMonitor_Image LXxD_ImageMonitor_Image LXx_OVERRIDE
#define LXxC_ImageMonitor_Image(c) LxResult c::imon_Image (ILxUnknownID imageToAnalyze, ILxUnknownID frameBufferToAnalyze, int bufferIndex, double x1, double y1, double x2, double y2, ILxUnknownID imageProcessingRead, ILxUnknownID processedThumbnail)
#define LXxD_ImageMonitor_ImageProcChanged LxResult imon_ImageProcChanged (void)
#define LXxO_ImageMonitor_ImageProcChanged LXxD_ImageMonitor_ImageProcChanged LXx_OVERRIDE
#define LXxC_ImageMonitor_ImageProcChanged(c) LxResult c::imon_ImageProcChanged (void)
#define LXxD_ImageMonitor_AspectRange LxResult imon_AspectRange (double *minAspect, double *maxAspect, double *idealAspect)
#define LXxO_ImageMonitor_AspectRange LXxD_ImageMonitor_AspectRange LXx_OVERRIDE
#define LXxC_ImageMonitor_AspectRange(c) LxResult c::imon_AspectRange (double *minAspect, double *maxAspect, double *idealAspect)
#define LXxD_ImageMonitor_Draw LxResult imon_Draw (ILxUnknownID imageForDrawing)
#define LXxO_ImageMonitor_Draw LXxD_ImageMonitor_Draw LXx_OVERRIDE
#define LXxC_ImageMonitor_Draw(c) LxResult c::imon_Draw (ILxUnknownID imageForDrawing)
#define LXxD_ImageMonitor_ImageSource LxResult imon_ImageSource (const char *source)
#define LXxO_ImageMonitor_ImageSource LXxD_ImageMonitor_ImageSource LXx_OVERRIDE
#define LXxC_ImageMonitor_ImageSource(c) LxResult c::imon_ImageSource (const char *source)
#define LXxD_ImageMonitor_MouseDown LxResult imon_MouseDown (int startx, int starty, int w, int h)
#define LXxO_ImageMonitor_MouseDown LXxD_ImageMonitor_MouseDown LXx_OVERRIDE
#define LXxC_ImageMonitor_MouseDown(c) LxResult c::imon_MouseDown (int startx, int starty, int w, int h)
#define LXxD_ImageMonitor_MouseMove LxResult imon_MouseMove (int startx, int starty, int cx, int cy, int w, int h)
#define LXxO_ImageMonitor_MouseMove LXxD_ImageMonitor_MouseMove LXx_OVERRIDE
#define LXxC_ImageMonitor_MouseMove(c) LxResult c::imon_MouseMove (int startx, int starty, int cx, int cy, int w, int h)
#define LXxD_ImageMonitor_MouseUp LxResult imon_MouseUp (int startx, int starty, int cx, int cy, int w, int h)
#define LXxO_ImageMonitor_MouseUp LXxD_ImageMonitor_MouseUp LXx_OVERRIDE
#define LXxC_ImageMonitor_MouseUp(c) LxResult c::imon_MouseUp (int startx, int starty, int cx, int cy, int w, int h)
#define LXxD_ImageMonitor_MouseTrackEnter LxResult imon_MouseTrackEnter (void)
#define LXxO_ImageMonitor_MouseTrackEnter LXxD_ImageMonitor_MouseTrackEnter LXx_OVERRIDE
#define LXxC_ImageMonitor_MouseTrackEnter(c) LxResult c::imon_MouseTrackEnter (void)
#define LXxD_ImageMonitor_MouseTrack LxResult imon_MouseTrack (int cx, int cy, int w, int h)
#define LXxO_ImageMonitor_MouseTrack LXxD_ImageMonitor_MouseTrack LXx_OVERRIDE
#define LXxC_ImageMonitor_MouseTrack(c) LxResult c::imon_MouseTrack (int cx, int cy, int w, int h)
#define LXxD_ImageMonitor_MouseTrackExit LxResult imon_MouseTrackExit (void)
#define LXxO_ImageMonitor_MouseTrackExit LXxD_ImageMonitor_MouseTrackExit LXx_OVERRIDE
#define LXxC_ImageMonitor_MouseTrackExit(c) LxResult c::imon_MouseTrackExit (void)
#define LXxD_ImageMonitor_ToolTip LxResult imon_ToolTip (int cx, int cy, int w, int h, char *buf, unsigned len)
#define LXxO_ImageMonitor_ToolTip LXxD_ImageMonitor_ToolTip LXx_OVERRIDE
#define LXxC_ImageMonitor_ToolTip(c) LxResult c::imon_ToolTip (int cx, int cy, int w, int h, char *buf, unsigned len)
template <class T>
class CLxIfc_ImageMonitor : public CLxInterface
{
    static LxResult
  Image (LXtObjectID wcom, LXtObjectID imageToAnalyze, LXtObjectID frameBufferToAnalyze, int bufferIndex, double x1, double y1, double x2, double y2, LXtObjectID imageProcessingRead, LXtObjectID processedThumbnail)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_Image ((ILxUnknownID)imageToAnalyze,(ILxUnknownID)frameBufferToAnalyze,bufferIndex,x1,y1,x2,y2,(ILxUnknownID)imageProcessingRead,(ILxUnknownID)processedThumbnail);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ImageProcChanged (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_ImageProcChanged ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AspectRange (LXtObjectID wcom, double *minAspect, double *maxAspect, double *idealAspect)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_AspectRange (minAspect,maxAspect,idealAspect);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Draw (LXtObjectID wcom, LXtObjectID imageForDrawing)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_Draw ((ILxUnknownID)imageForDrawing);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ImageSource (LXtObjectID wcom, const char *source)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_ImageSource (source);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MouseDown (LXtObjectID wcom, int startx, int starty, int w, int h)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_MouseDown (startx,starty,w,h);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MouseMove (LXtObjectID wcom, int startx, int starty, int cx, int cy, int w, int h)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_MouseMove (startx,starty,cx,cy,w,h);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MouseUp (LXtObjectID wcom, int startx, int starty, int cx, int cy, int w, int h)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_MouseUp (startx,starty,cx,cy,w,h);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MouseTrackEnter (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_MouseTrackEnter ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MouseTrack (LXtObjectID wcom, int cx, int cy, int w, int h)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_MouseTrack (cx,cy,w,h);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MouseTrackExit (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_MouseTrackExit ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToolTip (LXtObjectID wcom, int cx, int cy, int w, int h, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_ImageMonitor, loc);
    try {
      return loc->imon_ToolTip (cx,cy,w,h,buf,len);
    } catch (LxResult rc) { return rc; }
  }
  ILxImageMonitor vt;
public:
  CLxIfc_ImageMonitor ()
  {
    vt.Image = Image;
    vt.ImageProcChanged = ImageProcChanged;
    vt.AspectRange = AspectRange;
    vt.Draw = Draw;
    vt.ImageSource = ImageSource;
    vt.MouseDown = MouseDown;
    vt.MouseMove = MouseMove;
    vt.MouseUp = MouseUp;
    vt.MouseTrackEnter = MouseTrackEnter;
    vt.MouseTrack = MouseTrack;
    vt.MouseTrackExit = MouseTrackExit;
    vt.ToolTip = ToolTip;
    vTable = &vt.iunk;
    iid = &lx::guid_ImageMonitor;
  }
};
class CLxLoc_ImageMonitor : public CLxLocalize<ILxImageMonitorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageMonitor() {_init();}
  CLxLoc_ImageMonitor(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageMonitor(const CLxLoc_ImageMonitor &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageMonitor;}
    LxResult
  Image (ILxUnknownID imageToAnalyze, ILxUnknownID frameBufferToAnalyze, int bufferIndex, double x1, double y1, double x2, double y2, ILxUnknownID imageProcessingRead, ILxUnknownID processedThumbnail)
  {
    return m_loc[0]->Image (m_loc,(ILxUnknownID)imageToAnalyze,(ILxUnknownID)frameBufferToAnalyze,bufferIndex,x1,y1,x2,y2,(ILxUnknownID)imageProcessingRead,(ILxUnknownID)processedThumbnail);
  }
    LxResult
  ImageProcChanged (void)
  {
    return m_loc[0]->ImageProcChanged (m_loc);
  }
    LxResult
  AspectRange (double *minAspect, double *maxAspect, double *idealAspect)
  {
    return m_loc[0]->AspectRange (m_loc,minAspect,maxAspect,idealAspect);
  }
    LxResult
  Draw (ILxUnknownID imageForDrawing)
  {
    return m_loc[0]->Draw (m_loc,(ILxUnknownID)imageForDrawing);
  }
    LxResult
  ImageSource (const char *source)
  {
    return m_loc[0]->ImageSource (m_loc,source);
  }
    LxResult
  MouseDown (int startx, int starty, int w, int h)
  {
    return m_loc[0]->MouseDown (m_loc,startx,starty,w,h);
  }
    LxResult
  MouseMove (int startx, int starty, int cx, int cy, int w, int h)
  {
    return m_loc[0]->MouseMove (m_loc,startx,starty,cx,cy,w,h);
  }
    LxResult
  MouseUp (int startx, int starty, int cx, int cy, int w, int h)
  {
    return m_loc[0]->MouseUp (m_loc,startx,starty,cx,cy,w,h);
  }
    LxResult
  MouseTrackEnter (void)
  {
    return m_loc[0]->MouseTrackEnter (m_loc);
  }
    LxResult
  MouseTrack (int cx, int cy, int w, int h)
  {
    return m_loc[0]->MouseTrack (m_loc,cx,cy,w,h);
  }
    LxResult
  MouseTrackExit (void)
  {
    return m_loc[0]->MouseTrackExit (m_loc);
  }
    LxResult
  ToolTip (int cx, int cy, int w, int h, char *buf, unsigned len)
  {
    return m_loc[0]->ToolTip (m_loc,cx,cy,w,h,buf,len);
  }
    LxResult
  ToolTip (int cx, int cy, int w, int h, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ToolTip (m_loc,cx,cy,w,h,buf,len);
    LXWx_SBUF2
  }
};

class CLxLoc_ImageMonitorService : public CLxLocalizedService
{
public:
  ILxImageMonitorServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_ImageMonitorService() {_init();set();}
 ~CLxLoc_ImageMonitorService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxImageMonitorServiceID>(lx::GetGlobal(&lx::guid_ImageMonitorService));}
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
  ServerCount (int *count)
  {
    return m_loc[0]->ServerCount (m_loc,count);
  }
    LxResult
  ServerByIndex (int index, void **ppvObj)
  {
    return m_loc[0]->ServerByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  ServerByIndex (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ServerByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ServerLookup (const char *name, void **ppvObj)
  {
    return m_loc[0]->ServerLookup (m_loc,name,ppvObj);
  }
    CLxResult
  ServerLookup (const char *name, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ServerLookup(m_loc,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ServerNameByIndex (int index, const char **name)
  {
    return m_loc[0]->ServerNameByIndex (m_loc,index,name);
  }
    LxResult
  ServerUserNameByIndex (int index, const char **name)
  {
    return m_loc[0]->ServerUserNameByIndex (m_loc,index,name);
  }
    LxResult
  SourceCount (int *count)
  {
    return m_loc[0]->SourceCount (m_loc,count);
  }
    LxResult
  SourceNameByIndex (int index, const char **name)
  {
    return m_loc[0]->SourceNameByIndex (m_loc,index,name);
  }
    LxResult
  SourceUserNameByIndex (int index, const char **username)
  {
    return m_loc[0]->SourceUserNameByIndex (m_loc,index,username);
  }
    LxResult
  SetImage (const char *imageSource, ILxUnknownID image, ILxUnknownID frameBuffer, int bufferIndex, double x1, double y1, double x2, double y2, ILxUnknownID imageProc, ILxUnknownID processedThumbnail)
  {
    return m_loc[0]->SetImage (m_loc,imageSource,(ILxUnknownID)image,(ILxUnknownID)frameBuffer,bufferIndex,x1,y1,x2,y2,(ILxUnknownID)imageProc,(ILxUnknownID)processedThumbnail);
  }
    LxResult
  GetImage (const char *imageSource, void **ppvObj_image, void **ppvObj_frameBuffer, int *bufferIndex, double *x1, double *y1, double *x2, double *y2, void **ppvObj_imageProc, void **ppvObj_processedThumbnail)
  {
    return m_loc[0]->GetImage (m_loc,imageSource,ppvObj_image,ppvObj_frameBuffer,bufferIndex,x1,y1,x2,y2,ppvObj_imageProc,ppvObj_processedThumbnail);
  }
    LxResult
  GetImagePacket (const char *imageSource, const LXtImageMonitorPacket **packet)
  {
    return m_loc[0]->GetImagePacket (m_loc,imageSource,packet);
  }
    LxResult
  RefreshViews (const char *imageSource, int immediate)
  {
    return m_loc[0]->RefreshViews (m_loc,imageSource,immediate);
  }
};

#endif

