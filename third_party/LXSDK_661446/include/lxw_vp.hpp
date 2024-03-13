/*
 * C++ wrapper for lxvp.h
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
#ifndef LXW_VP_HPP
#define LXW_VP_HPP

#include <lxvp.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_GLViewportClient = {0x2975C75E,0x1F2C,0x4448,0x98,0xBB,0xD3,0xFA,0x8A,0xDF,0x85,0x95};
    static const LXtGUID guid_SimulationListener = {0x628A3377,0xC56B,0x4801,0x87,0x8C,0x8B,0xF8,0x7A,0x09,0x7D,0x29};
    static const LXtGUID guid_GLViewport = {0x9F4D9937,0xFF49,0x45E4,0x97,0x81,0x80,0x85,0xA9,0x46,0x36,0x61};
    static const LXtGUID guid_View3D = {0x02DBFE75,0xC1AB,0x4E23,0xA4,0xC9,0x90,0x50,0x8C,0x7C,0xD7,0xC3};
    static const LXtGUID guid_View3DportService = {0xD84FF812,0xE4E9,0x41DC,0xB8,0x2F,0xB5,0x50,0xAC,0xF2,0xE4,0x0A};
};

class CLxImpl_GLViewportClient {
  public:
    virtual ~CLxImpl_GLViewportClient() {}
    virtual LxResult
      glclient_Invalidate (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      glclient_MousePosition (int *x, int *y)
        { return LXe_NOTIMPL; }
    virtual LxResult
      glclient_MouseButton (unsigned *button)
        { return LXe_NOTIMPL; }
    virtual LxResult
      glclient_TabletPressure (double *press)
        { return LXe_NOTIMPL; }
    virtual LxResult
      glclient_TabletTilt (double *tilt)
        { return LXe_NOTIMPL; }
    virtual LxResult
      glclient_MouseCount (int *count)
        { return LXe_NOTIMPL; }
};
#define LXxD_GLViewportClient_Invalidate LxResult glclient_Invalidate (void)
#define LXxO_GLViewportClient_Invalidate LXxD_GLViewportClient_Invalidate LXx_OVERRIDE
#define LXxC_GLViewportClient_Invalidate(c) LxResult c::glclient_Invalidate (void)
#define LXxD_GLViewportClient_MousePosition LxResult glclient_MousePosition (int *x, int *y)
#define LXxO_GLViewportClient_MousePosition LXxD_GLViewportClient_MousePosition LXx_OVERRIDE
#define LXxC_GLViewportClient_MousePosition(c) LxResult c::glclient_MousePosition (int *x, int *y)
#define LXxD_GLViewportClient_MouseButton LxResult glclient_MouseButton (unsigned *button)
#define LXxO_GLViewportClient_MouseButton LXxD_GLViewportClient_MouseButton LXx_OVERRIDE
#define LXxC_GLViewportClient_MouseButton(c) LxResult c::glclient_MouseButton (unsigned *button)
#define LXxD_GLViewportClient_TabletPressure LxResult glclient_TabletPressure (double *press)
#define LXxO_GLViewportClient_TabletPressure LXxD_GLViewportClient_TabletPressure LXx_OVERRIDE
#define LXxC_GLViewportClient_TabletPressure(c) LxResult c::glclient_TabletPressure (double *press)
#define LXxD_GLViewportClient_TabletTilt LxResult glclient_TabletTilt (double *tilt)
#define LXxO_GLViewportClient_TabletTilt LXxD_GLViewportClient_TabletTilt LXx_OVERRIDE
#define LXxC_GLViewportClient_TabletTilt(c) LxResult c::glclient_TabletTilt (double *tilt)
#define LXxD_GLViewportClient_MouseCount LxResult glclient_MouseCount (int *count)
#define LXxO_GLViewportClient_MouseCount LXxD_GLViewportClient_MouseCount LXx_OVERRIDE
#define LXxC_GLViewportClient_MouseCount(c) LxResult c::glclient_MouseCount (int *count)
template <class T>
class CLxIfc_GLViewportClient : public CLxInterface
{
    static LxResult
  Invalidate (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_GLViewportClient, loc);
    try {
      return loc->glclient_Invalidate ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MousePosition (LXtObjectID wcom, int *x, int *y)
  {
    LXCWxINST (CLxImpl_GLViewportClient, loc);
    try {
      return loc->glclient_MousePosition (x,y);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MouseButton (LXtObjectID wcom, unsigned *button)
  {
    LXCWxINST (CLxImpl_GLViewportClient, loc);
    try {
      return loc->glclient_MouseButton (button);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TabletPressure (LXtObjectID wcom, double *press)
  {
    LXCWxINST (CLxImpl_GLViewportClient, loc);
    try {
      return loc->glclient_TabletPressure (press);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TabletTilt (LXtObjectID wcom, double *tilt)
  {
    LXCWxINST (CLxImpl_GLViewportClient, loc);
    try {
      return loc->glclient_TabletTilt (tilt);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MouseCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_GLViewportClient, loc);
    try {
      return loc->glclient_MouseCount (count);
    } catch (LxResult rc) { return rc; }
  }
  ILxGLViewportClient vt;
public:
  CLxIfc_GLViewportClient ()
  {
    vt.Invalidate = Invalidate;
    vt.MousePosition = MousePosition;
    vt.MouseButton = MouseButton;
    vt.TabletPressure = TabletPressure;
    vt.TabletTilt = TabletTilt;
    vt.MouseCount = MouseCount;
    vTable = &vt.iunk;
    iid = &lx::guid_GLViewportClient;
  }
};
class CLxLoc_GLViewportClient : public CLxLocalize<ILxGLViewportClientID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GLViewportClient() {_init();}
  CLxLoc_GLViewportClient(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GLViewportClient(const CLxLoc_GLViewportClient &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GLViewportClient;}
    LxResult
  Invalidate (void)
  {
    return m_loc[0]->Invalidate (m_loc);
  }
    LxResult
  MousePosition (int *x, int *y)
  {
    return m_loc[0]->MousePosition (m_loc,x,y);
  }
    LxResult
  MouseButton (unsigned *button)
  {
    return m_loc[0]->MouseButton (m_loc,button);
  }
    LxResult
  TabletPressure (double *press)
  {
    return m_loc[0]->TabletPressure (m_loc,press);
  }
    LxResult
  TabletTilt (double *tilt)
  {
    return m_loc[0]->TabletTilt (m_loc,tilt);
  }
    LxResult
  MouseCount (int *count)
  {
    return m_loc[0]->MouseCount (m_loc,count);
  }
};

class CLxLoc_SimulationListener : public CLxLocalize<ILxSimulationListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SimulationListener() {_init();}
  CLxLoc_SimulationListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SimulationListener(const CLxLoc_SimulationListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SimulationListener;}
    LxResult
  Start (ILxUnknownID channels)
  {
    return m_loc[0]->Start (m_loc,(ILxUnknownID)channels);
  }
    LxResult
  End (void)
  {
    return m_loc[0]->End (m_loc);
  }
    LxResult
  Time (double time)
  {
    return m_loc[0]->Time (m_loc,time);
  }
    LxResult
  Invalidate (void)
  {
    return m_loc[0]->Invalidate (m_loc);
  }
};

class CLxLoc_GLViewport : public CLxLocalize<ILxGLViewportID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GLViewport() {_init();}
  CLxLoc_GLViewport(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GLViewport(const CLxLoc_GLViewport &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GLViewport;}
    LxResult
  Initialize (ILxUnknownID client)
  {
    return m_loc[0]->Initialize (m_loc,(ILxUnknownID)client);
  }
    LxResult
  SetSize (unsigned w, unsigned h)
  {
    return m_loc[0]->SetSize (m_loc,w,h);
  }
    LxResult
  Draw (void)
  {
    return m_loc[0]->Draw (m_loc);
  }
    LxResult
  MouseEvent (unsigned event)
  {
    return m_loc[0]->MouseEvent (m_loc,event);
  }
    LxResult
  SelectViewport (void)
  {
    return m_loc[0]->SelectViewport (m_loc);
  }
    LxResult
  DropDestination (int x, int y, void **ppvObj)
  {
    return m_loc[0]->DropDestination (m_loc,x,y,ppvObj);
  }
    CLxResult
  DropDestination (int x, int y, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->DropDestination(m_loc,x,y,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_View3D : public CLxLocalize<ILxView3DID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_View3D() {_init();}
  CLxLoc_View3D(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_View3D(const CLxLoc_View3D &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_View3D;}
    LXtID4
  Space (void)
  {
    return m_loc[0]->Space (m_loc);
  }
    int
  Axis (int *cam, LXtVector axis)
  {
    return m_loc[0]->Axis (m_loc,cam,axis);
  }
    LxResult
  Bounds (int *x, int *y, int *w, int *h)
  {
    return m_loc[0]->Bounds (m_loc,x,y,w,h);
  }
    int
  Style (int option)
  {
    return m_loc[0]->Style (m_loc,option);
  }
    double
  PixelSize (void)
  {
    return m_loc[0]->PixelSize (m_loc);
  }
    LxResult
  Center (LXtVector center)
  {
    return m_loc[0]->Center (m_loc,center);
  }
    double
  EyeVector (LXtVector pos, LXtVector dir)
  {
    return m_loc[0]->EyeVector (m_loc,pos,dir);
  }
    LxResult
  Matrix (LXtMatrix mat, int inverse)
  {
    return m_loc[0]->Matrix (m_loc,mat,inverse);
  }
    LxResult
  Angles (LXtVector hpb)
  {
    return m_loc[0]->Angles (m_loc,hpb);
  }
    int
  WorkPlane (LXtVector center)
  {
    return m_loc[0]->WorkPlane (m_loc,center);
  }
    LxResult
  To3D (float x, float y, LXtVector pos, int flags)
  {
    return m_loc[0]->To3D (m_loc,x,y,pos,flags);
  }
    LxResult
  To3DHit (float x, float y, LXtVector pos, LXtVector nrm)
  {
    return m_loc[0]->To3DHit (m_loc,x,y,pos,nrm);
  }
    LxResult
  Backdrop (void **item)
  {
    return m_loc[0]->Backdrop (m_loc,item);
  }
    const char*
  BackdropName (void)
  {
    return m_loc[0]->BackdropName (m_loc);
  }
    LxResult
  BackdropPlace (double *cx, double *cy, double *w, double *h)
  {
    return m_loc[0]->BackdropPlace (m_loc,cx,cy,w,h);
  }
    int
  BackdropAspect (double *asp)
  {
    return m_loc[0]->BackdropAspect (m_loc,asp);
  }
    int
  BackdropOrient (double *ang)
  {
    return m_loc[0]->BackdropOrient (m_loc,ang);
  }
    int
  BackdropLook (double *brit, double *cont, double *trns)
  {
    return m_loc[0]->BackdropLook (m_loc,brit,cont,trns);
  }
    int
  BackdropRender (int *resolution, int *blend)
  {
    return m_loc[0]->BackdropRender (m_loc,resolution,blend);
  }
    int
  HitElement (LXtID4 type, float x, float y, void **list)
  {
    return m_loc[0]->HitElement (m_loc,type,x,y,list);
  }
    double
  GridSize (void)
  {
    return m_loc[0]->GridSize (m_loc);
  }
    double
  FrameRate (void)
  {
    return m_loc[0]->FrameRate (m_loc);
  }
    LxResult
  SetMatrix (const LXtMatrix mat)
  {
    return m_loc[0]->SetMatrix (m_loc,mat);
  }
    LxResult
  SetCenter (const LXtVector vec)
  {
    return m_loc[0]->SetCenter (m_loc,vec);
  }
    LxResult
  SetScale (double scl)
  {
    return m_loc[0]->SetScale (m_loc,scl);
  }
    LxResult
  ItemShade (ILxUnknownID item, unsigned *shade)
  {
    return m_loc[0]->ItemShade (m_loc,(ILxUnknownID)item,shade);
  }
    LxResult
  ItemColor (ILxUnknownID item, LXtFVector4 color)
  {
    return m_loc[0]->ItemColor (m_loc,(ILxUnknownID)item,color);
  }
    LxResult
  ItemSelColor (ILxUnknownID item, LXtFVector4 color)
  {
    return m_loc[0]->ItemSelColor (m_loc,(ILxUnknownID)item,color);
  }
    LxResult
  ItemWireOverlay (ILxUnknownID item, LXtFVector4 color, unsigned *wireframe)
  {
    return m_loc[0]->ItemWireOverlay (m_loc,(ILxUnknownID)item,color,wireframe);
  }
    LxResult
  Deformers (void)
  {
    return m_loc[0]->Deformers (m_loc);
  }
    LxResult
  ItemIsVisible (ILxUnknownID item)
  {
    return m_loc[0]->ItemIsVisible (m_loc,(ILxUnknownID)item);
  }
    LxResult
  ToUVHit (const char *name, float x, float y, unsigned layer, float *u, float *v)
  {
    return m_loc[0]->ToUVHit (m_loc,name,x,y,layer,u,v);
  }
    LxResult
  InvalidateSurface (ILxUnknownID item)
  {
    return m_loc[0]->InvalidateSurface (m_loc,(ILxUnknownID)item);
  }
};

class CLxLoc_View3DportService : public CLxLocalizedService
{
public:
  ILxView3DportServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_View3DportService() {_init();set();}
 ~CLxLoc_View3DportService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxView3DportServiceID>(lx::GetGlobal(&lx::guid_View3DportService));}
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
    int
  Count (void)
  {
    return m_loc[0]->Count (m_loc);
  }
    int
  Current (void)
  {
    return m_loc[0]->Current (m_loc);
  }
    LxResult
  View (int index, void **ppvObj)
  {
    return m_loc[0]->View (m_loc,index,ppvObj);
  }
    CLxResult
  View (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->View(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    int
  Mouse (int *x, int *y)
  {
    return m_loc[0]->Mouse (m_loc,x,y);
  }
    LxResult
  SetHitUVMap (const char *name)
  {
    return m_loc[0]->SetHitUVMap (m_loc,name);
  }
    int
  InvalidateOverrider (ILxUnknownID scene, const char *pkgName)
  {
    return m_loc[0]->InvalidateOverrider (m_loc,(ILxUnknownID)scene,pkgName);
  }
    LxResult
  GLMaterial (ILxUnknownID bin, ILxUnknownID item, ILxUnknownID view, void **ppvObj)
  {
    return m_loc[0]->GLMaterial (m_loc,(ILxUnknownID)bin,(ILxUnknownID)item,(ILxUnknownID)view,ppvObj);
  }
    CLxResult
  GLMaterial (ILxUnknownID bin, ILxUnknownID item, ILxUnknownID view, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GLMaterial(m_loc,(ILxUnknownID)bin,(ILxUnknownID)item,(ILxUnknownID)view,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  TriGroupToViewObject (unsigned int type, ILxUnknownID triGroup, void **ppvObj)
  {
    return m_loc[0]->TriGroupToViewObject (m_loc,type,(ILxUnknownID)triGroup,ppvObj);
  }
    CLxResult
  TriGroupToViewObject (unsigned int type, ILxUnknownID triGroup, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->TriGroupToViewObject(m_loc,type,(ILxUnknownID)triGroup,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ImageToGLImage (ILxUnknownID image, void **ppvObj)
  {
    return m_loc[0]->ImageToGLImage (m_loc,(ILxUnknownID)image,ppvObj);
  }
    CLxResult
  ImageToGLImage (ILxUnknownID image, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ImageToGLImage(m_loc,(ILxUnknownID)image,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AllocGLViewport (void **ppvObj)
  {
    return m_loc[0]->AllocGLViewport (m_loc,ppvObj);
  }
    CLxResult
  AllocGLViewport (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AllocGLViewport(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AddVirtualModel (ILxUnknownID vmodel)
  {
    return m_loc[0]->AddVirtualModel (m_loc,(ILxUnknownID)vmodel);
  }
    void
  RemoveVirtualModel (ILxUnknownID vmodel)
  {
    m_loc[0]->RemoveVirtualModel (m_loc,(ILxUnknownID)vmodel);
  }
    void
  UpdateVirtualModel (ILxUnknownID vmodel)
  {
    m_loc[0]->UpdateVirtualModel (m_loc,(ILxUnknownID)vmodel);
  }
    LxResult
  SurfaceToViewObject (unsigned int type, ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->SurfaceToViewObject (m_loc,type,(ILxUnknownID)item,ppvObj);
  }
    CLxResult
  SurfaceToViewObject (unsigned int type, ILxUnknownID item, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SurfaceToViewObject(m_loc,type,(ILxUnknownID)item,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

