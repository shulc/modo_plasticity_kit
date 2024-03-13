/*
 * C++ wrapper for lxdraw.h
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
#ifndef LXW_DRAW_HPP
#define LXW_DRAW_HPP

#include <lxdraw.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_GLImage = {0xDA71480A,0x95AA,0x11D9,0x93,0x6D,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_View = {0x7D171FD2,0x20D5,0x438C,0x86,0x64,0xAE,0xCC,0x2F,0x82,0x8B,0x76};
    static const LXtGUID guid_StrokeDraw = {0xDA71480A,0x95AA,0x11D9,0x93,0x6D,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_GLMaterial = {0x2AA53B64,0x9EEF,0x4504,0xBE,0x1B,0x64,0x71,0xA8,0x34,0x85,0x3D};
};

class CLxLoc_GLImage : public CLxLocalize<ILxGLImageID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GLImage() {_init();}
  CLxLoc_GLImage(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GLImage(const CLxLoc_GLImage &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GLImage;}
    LxResult
  SetImage (ILxUnknownID image)
  {
    return m_loc[0]->SetImage (m_loc,(ILxUnknownID)image);
  }
    LxResult
  Size (double *w, double *h)
  {
    return m_loc[0]->Size (m_loc,w,h);
  }
};

class CLxLoc_View : public CLxLocalize<ILxViewID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_View() {_init();}
  CLxLoc_View(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_View(const CLxLoc_View &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_View;}
    int
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    void
  Center (LXtVector center)
  {
    m_loc[0]->Center (m_loc,center);
  }
    double
  Scale (void)
  {
    return m_loc[0]->Scale (m_loc);
  }
    double
  PixelScale (void)
  {
    return m_loc[0]->PixelScale (m_loc);
  }
    double
  Aspect (void)
  {
    return m_loc[0]->Aspect (m_loc);
  }
    void
  Matrix (LXtMatrix xfrm)
  {
    m_loc[0]->Matrix (m_loc,xfrm);
  }
    void
  InvMatrix (LXtMatrix xfrm)
  {
    m_loc[0]->InvMatrix (m_loc,xfrm);
  }
    void
  Ortho (int *index, int *spin)
  {
    m_loc[0]->Ortho (m_loc,index,spin);
  }
    int
  Axis (void)
  {
    return m_loc[0]->Axis (m_loc);
  }
    double
  Zoom (void)
  {
    return m_loc[0]->Zoom (m_loc);
  }
    void
  Focal (double *flen, double *fdist)
  {
    m_loc[0]->Focal (m_loc,flen,fdist);
  }
    int
  ToScreen (const LXtVector pos, double *x, double *y)
  {
    return m_loc[0]->ToScreen (m_loc,pos,x,y);
  }
    int
  ToScreen3 (const LXtVector pos, LXtVector vp)
  {
    return m_loc[0]->ToScreen3 (m_loc,pos,vp);
  }
    void
  ToModel (int x, int y, LXtVector pos, int snap)
  {
    m_loc[0]->ToModel (m_loc,x,y,pos,snap);
  }
    void
  ScreenNormals (const LXtVector pos, LXtVector ax, LXtVector ay, LXtVector az)
  {
    m_loc[0]->ScreenNormals (m_loc,pos,ax,ay,az);
  }
    double
  EyeVector (const LXtVector pos, LXtVector eye)
  {
    return m_loc[0]->EyeVector (m_loc,pos,eye);
  }
    void
  Dimensions (int *w, int *h)
  {
    m_loc[0]->Dimensions (m_loc,w,h);
  }
    int
  WorkPlane (LXtVector center)
  {
    return m_loc[0]->WorkPlane (m_loc,center);
  }
    double
  GridSize (void)
  {
    return m_loc[0]->GridSize (m_loc);
  }
    double
  GridSnap (void)
  {
    return m_loc[0]->GridSnap (m_loc);
  }
};

class CLxLoc_StrokeDraw : public CLxLocalize<ILxStrokeDrawID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StrokeDraw() {_init();}
  CLxLoc_StrokeDraw(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StrokeDraw(const CLxLoc_StrokeDraw &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StrokeDraw;}
    void
  Begin (int type, const LXtVector color, double alpha)
  {
    m_loc[0]->Begin (m_loc,type,color,alpha);
  }
    void
  BeginW (int type, const LXtVector color, double alpha, double width)
  {
    m_loc[0]->BeginW (m_loc,type,color,alpha,width);
  }
    void
  BeginWD (int type, const LXtVector color, double alpha, double width, int dashPattern)
  {
    m_loc[0]->BeginWD (m_loc,type,color,alpha,width,dashPattern);
  }
    void
  Vertex (const LXtVector pos, int flags)
  {
    m_loc[0]->Vertex (m_loc,pos,flags);
  }
    void
  Vertex3 (double x, double y, double z, int flags)
  {
    m_loc[0]->Vertex3 (m_loc,x,y,z,flags);
  }
    void
  TextureUV (double u, double v)
  {
    m_loc[0]->TextureUV (m_loc,u,v);
  }
    void
  Text (const char *text, int just)
  {
    m_loc[0]->Text (m_loc,text,just);
  }
    void
  PushTransform (const LXtVector v, const LXtMatrix m)
  {
    m_loc[0]->PushTransform (m_loc,v,m);
  }
    void
  PopTransform (void)
  {
    m_loc[0]->PopTransform (m_loc);
  }
    void
  SetPart (int part)
  {
    m_loc[0]->SetPart (m_loc,part);
  }
    void
  BeginPoints (double size, const LXtVector color, double alpha)
  {
    m_loc[0]->BeginPoints (m_loc,size,color,alpha);
  }
    void
  Image (int texID, int just)
  {
    m_loc[0]->Image (m_loc,texID,just);
  }
    void
  BeginPolygons (int type, const LXtVector color, double alpha, double stip, double offsetX, double offsetY, int fill, int cull)
  {
    m_loc[0]->BeginPolygons (m_loc,type,color,alpha,stip,offsetX,offsetY,fill,cull);
  }
    void
  BeginI (ILxUnknownID texture, int type, const LXtVector color, double alpha)
  {
    m_loc[0]->BeginI (m_loc,(ILxUnknownID)texture,type,color,alpha);
  }
};

class CLxLoc_GLMaterial : public CLxLocalize<ILxGLMaterialID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GLMaterial() {_init();}
  CLxLoc_GLMaterial(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GLMaterial(const CLxLoc_GLMaterial &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GLMaterial;}
    LxResult
  Color (LXtFVector color)
  {
    return m_loc[0]->Color (m_loc,color);
  }
    LxResult
  Alpha (float *alpha)
  {
    return m_loc[0]->Alpha (m_loc,alpha);
  }
    LxResult
  DiffuseAmount (float *amount)
  {
    return m_loc[0]->DiffuseAmount (m_loc,amount);
  }
    LxResult
  DiffuseColor (LXtFVector color)
  {
    return m_loc[0]->DiffuseColor (m_loc,color);
  }
    LxResult
  SpecularAmount (float *amount)
  {
    return m_loc[0]->SpecularAmount (m_loc,amount);
  }
    LxResult
  SpecularColor (LXtFVector color)
  {
    return m_loc[0]->SpecularColor (m_loc,color);
  }
    LxResult
  LuminosityColor (LXtFVector color)
  {
    return m_loc[0]->LuminosityColor (m_loc,color);
  }
    LxResult
  Glossiness (float *amount)
  {
    return m_loc[0]->Glossiness (m_loc,amount);
  }
    LxResult
  ReflectionColor (LXtFVector color)
  {
    return m_loc[0]->ReflectionColor (m_loc,color);
  }
    LxResult
  TwoSide (int *value)
  {
    return m_loc[0]->TwoSide (m_loc,value);
  }
};

#endif

