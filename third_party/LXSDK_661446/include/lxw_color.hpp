/*
 * C++ wrapper for lxcolor.h
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
#ifndef LXW_COLOR_HPP
#define LXW_COLOR_HPP

#include <lxcolor.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_Color = {0x7c084df3,0xadb6,0x48ee,0x92,0xd3,0x03,0x2d,0x90,0xef,0xea,0x05};
    static const LXtGUID guid_ColorModel = {0x67d3d952,0x4ab0,0x49e5,0x8f,0x9e,0x6c,0x88,0x9b,0x00,0xf2,0x53};
};

class CLxImpl_Color {
  public:
    virtual ~CLxImpl_Color() {}
    virtual LxResult
      color_Color (float *color)
        { return LXe_NOTIMPL; }
    virtual LxResult
      color_Alpha (float *alpha)
        { return LXe_NOTIMPL; }
    virtual LxResult
      color_ColorModel (const char **model)
        { return LXe_NOTIMPL; }
    virtual LxResult
      color_ColorInModelSpace (float *vec)
        { return LXe_NOTIMPL; }
};
#define LXxD_Color_Color LxResult color_Color (float *color)
#define LXxO_Color_Color LXxD_Color_Color LXx_OVERRIDE
#define LXxC_Color_Color(c) LxResult c::color_Color (float *color)
#define LXxD_Color_Alpha LxResult color_Alpha (float *alpha)
#define LXxO_Color_Alpha LXxD_Color_Alpha LXx_OVERRIDE
#define LXxC_Color_Alpha(c) LxResult c::color_Alpha (float *alpha)
#define LXxD_Color_ColorModel LxResult color_ColorModel (const char **model)
#define LXxO_Color_ColorModel LXxD_Color_ColorModel LXx_OVERRIDE
#define LXxC_Color_ColorModel(c) LxResult c::color_ColorModel (const char **model)
#define LXxD_Color_ColorInModelSpace LxResult color_ColorInModelSpace (float *vec)
#define LXxO_Color_ColorInModelSpace LXxD_Color_ColorInModelSpace LXx_OVERRIDE
#define LXxC_Color_ColorInModelSpace(c) LxResult c::color_ColorInModelSpace (float *vec)
template <class T>
class CLxIfc_Color : public CLxInterface
{
    static LxResult
  Color (LXtObjectID wcom, float *color)
  {
    LXCWxINST (CLxImpl_Color, loc);
    try {
      return loc->color_Color (color);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Alpha (LXtObjectID wcom, float *alpha)
  {
    LXCWxINST (CLxImpl_Color, loc);
    try {
      return loc->color_Alpha (alpha);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColorModel (LXtObjectID wcom, const char **model)
  {
    LXCWxINST (CLxImpl_Color, loc);
    try {
      return loc->color_ColorModel (model);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColorInModelSpace (LXtObjectID wcom, float *vec)
  {
    LXCWxINST (CLxImpl_Color, loc);
    try {
      return loc->color_ColorInModelSpace (vec);
    } catch (LxResult rc) { return rc; }
  }
  ILxColor vt;
public:
  CLxIfc_Color ()
  {
    vt.Color = Color;
    vt.Alpha = Alpha;
    vt.ColorModel = ColorModel;
    vt.ColorInModelSpace = ColorInModelSpace;
    vTable = &vt.iunk;
    iid = &lx::guid_Color;
  }
};
class CLxLoc_Color : public CLxLocalize<ILxColorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Color() {_init();}
  CLxLoc_Color(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Color(const CLxLoc_Color &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Color;}
    LxResult
  Color (float *color)
  {
    return m_loc[0]->Color (m_loc,color);
  }
    LxResult
  Alpha (float *alpha)
  {
    return m_loc[0]->Alpha (m_loc,alpha);
  }
    LxResult
  ColorModel (const char **model)
  {
    return m_loc[0]->ColorModel (m_loc,model);
  }
    LxResult
  ColorInModelSpace (float *vec)
  {
    return m_loc[0]->ColorInModelSpace (m_loc,vec);
  }
};

class CLxImpl_ColorModel {
  public:
    virtual ~CLxImpl_ColorModel() {}
    virtual int
      colm_NumComponents (void)
        = 0;
    virtual LxResult
      colm_ComponentType (unsigned component, const char **type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_ComponentRange (unsigned component, float *min, float *max)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_ToRGB (const float *vector, float *rgb)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_FromRGB (const float *rgb, float *vector)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_DrawSlice (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *vec)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_DrawSliceMarker (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *downVec, const float *vec)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_CanSliceBeReused (unsigned xAxis, unsigned yAxis, const float *oldVec, const float *newVec)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_ToSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float *vec, unsigned *imgX, unsigned *imgY)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_FromSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float *downVec, float *vec)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_StripBaseVector (unsigned axis, int dynamic, float *vec)
        { return LXe_NOTIMPL; }
};
#define LXxD_ColorModel_NumComponents int colm_NumComponents (void)
#define LXxO_ColorModel_NumComponents LXxD_ColorModel_NumComponents LXx_OVERRIDE
#define LXxC_ColorModel_NumComponents(c) int c::colm_NumComponents (void)
#define LXxD_ColorModel_ComponentType LxResult colm_ComponentType (unsigned component, const char **type)
#define LXxO_ColorModel_ComponentType LXxD_ColorModel_ComponentType LXx_OVERRIDE
#define LXxC_ColorModel_ComponentType(c) LxResult c::colm_ComponentType (unsigned component, const char **type)
#define LXxD_ColorModel_ComponentRange LxResult colm_ComponentRange (unsigned component, float *min, float *max)
#define LXxO_ColorModel_ComponentRange LXxD_ColorModel_ComponentRange LXx_OVERRIDE
#define LXxC_ColorModel_ComponentRange(c) LxResult c::colm_ComponentRange (unsigned component, float *min, float *max)
#define LXxD_ColorModel_ToRGB LxResult colm_ToRGB (const float *vector, float *rgb)
#define LXxO_ColorModel_ToRGB LXxD_ColorModel_ToRGB LXx_OVERRIDE
#define LXxC_ColorModel_ToRGB(c) LxResult c::colm_ToRGB (const float *vector, float *rgb)
#define LXxD_ColorModel_FromRGB LxResult colm_FromRGB (const float *rgb, float *vector)
#define LXxO_ColorModel_FromRGB LXxD_ColorModel_FromRGB LXx_OVERRIDE
#define LXxC_ColorModel_FromRGB(c) LxResult c::colm_FromRGB (const float *rgb, float *vector)
#define LXxD_ColorModel_DrawSlice LxResult colm_DrawSlice (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *vec)
#define LXxO_ColorModel_DrawSlice LXxD_ColorModel_DrawSlice LXx_OVERRIDE
#define LXxC_ColorModel_DrawSlice(c) LxResult c::colm_DrawSlice (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *vec)
#define LXxD_ColorModel_DrawSliceMarker LxResult colm_DrawSliceMarker (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *downVec, const float *vec)
#define LXxO_ColorModel_DrawSliceMarker LXxD_ColorModel_DrawSliceMarker LXx_OVERRIDE
#define LXxC_ColorModel_DrawSliceMarker(c) LxResult c::colm_DrawSliceMarker (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *downVec, const float *vec)
#define LXxD_ColorModel_CanSliceBeReused LxResult colm_CanSliceBeReused (unsigned xAxis, unsigned yAxis, const float *oldVec, const float *newVec)
#define LXxO_ColorModel_CanSliceBeReused LXxD_ColorModel_CanSliceBeReused LXx_OVERRIDE
#define LXxC_ColorModel_CanSliceBeReused(c) LxResult c::colm_CanSliceBeReused (unsigned xAxis, unsigned yAxis, const float *oldVec, const float *newVec)
#define LXxD_ColorModel_ToSlicePos LxResult colm_ToSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float *vec, unsigned *imgX, unsigned *imgY)
#define LXxO_ColorModel_ToSlicePos LXxD_ColorModel_ToSlicePos LXx_OVERRIDE
#define LXxC_ColorModel_ToSlicePos(c) LxResult c::colm_ToSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float *vec, unsigned *imgX, unsigned *imgY)
#define LXxD_ColorModel_FromSlicePos LxResult colm_FromSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float *downVec, float *vec)
#define LXxO_ColorModel_FromSlicePos LXxD_ColorModel_FromSlicePos LXx_OVERRIDE
#define LXxC_ColorModel_FromSlicePos(c) LxResult c::colm_FromSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float *downVec, float *vec)
#define LXxD_ColorModel_StripBaseVector LxResult colm_StripBaseVector (unsigned axis, int dynamic, float *vec)
#define LXxO_ColorModel_StripBaseVector LXxD_ColorModel_StripBaseVector LXx_OVERRIDE
#define LXxC_ColorModel_StripBaseVector(c) LxResult c::colm_StripBaseVector (unsigned axis, int dynamic, float *vec)
template <class T>
class CLxIfc_ColorModel : public CLxInterface
{
    static int
  NumComponents (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    return loc->colm_NumComponents ();
  }
    static LxResult
  ComponentType (LXtObjectID wcom, unsigned component, const char **type)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_ComponentType (component,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ComponentRange (LXtObjectID wcom, unsigned component, float *min, float *max)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_ComponentRange (component,min,max);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToRGB (LXtObjectID wcom, const float *vector, float *rgb)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_ToRGB (vector,rgb);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FromRGB (LXtObjectID wcom, const float *rgb, float *vector)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_FromRGB (rgb,vector);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DrawSlice (LXtObjectID wcom, LXtObjectID image, unsigned xAxis, unsigned yAxis, const float *vec)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_DrawSlice ((ILxUnknownID)image,xAxis,yAxis,vec);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DrawSliceMarker (LXtObjectID wcom, LXtObjectID image, unsigned xAxis, unsigned yAxis, const float *downVec, const float *vec)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_DrawSliceMarker ((ILxUnknownID)image,xAxis,yAxis,downVec,vec);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CanSliceBeReused (LXtObjectID wcom, unsigned xAxis, unsigned yAxis, const float *oldVec, const float *newVec)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_CanSliceBeReused (xAxis,yAxis,oldVec,newVec);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToSlicePos (LXtObjectID wcom, unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float *vec, unsigned *imgX, unsigned *imgY)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_ToSlicePos (xAxis,yAxis,imgW,imgH,vec,imgX,imgY);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FromSlicePos (LXtObjectID wcom, unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float *downVec, float *vec)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_FromSlicePos (xAxis,yAxis,imgW,imgH,imgX,imgY,downVec,vec);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  StripBaseVector (LXtObjectID wcom, unsigned axis, int dynamic, float *vec)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_StripBaseVector (axis,dynamic,vec);
    } catch (LxResult rc) { return rc; }
  }
  ILxColorModel vt;
public:
  CLxIfc_ColorModel ()
  {
    vt.NumComponents = NumComponents;
    vt.ComponentType = ComponentType;
    vt.ComponentRange = ComponentRange;
    vt.ToRGB = ToRGB;
    vt.FromRGB = FromRGB;
    vt.DrawSlice = DrawSlice;
    vt.DrawSliceMarker = DrawSliceMarker;
    vt.CanSliceBeReused = CanSliceBeReused;
    vt.ToSlicePos = ToSlicePos;
    vt.FromSlicePos = FromSlicePos;
    vt.StripBaseVector = StripBaseVector;
    vTable = &vt.iunk;
    iid = &lx::guid_ColorModel;
  }
};
class CLxLoc_ColorModel : public CLxLocalize<ILxColorModelID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ColorModel() {_init();}
  CLxLoc_ColorModel(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ColorModel(const CLxLoc_ColorModel &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ColorModel;}
    int
  NumComponents (void)
  {
    return m_loc[0]->NumComponents (m_loc);
  }
    LxResult
  ComponentType (unsigned component, const char **type)
  {
    return m_loc[0]->ComponentType (m_loc,component,type);
  }
    LxResult
  ComponentRange (unsigned component, float *min, float *max)
  {
    return m_loc[0]->ComponentRange (m_loc,component,min,max);
  }
    LxResult
  ToRGB (const float *vector, float *rgb)
  {
    return m_loc[0]->ToRGB (m_loc,vector,rgb);
  }
    LxResult
  FromRGB (const float *rgb, float *vector)
  {
    return m_loc[0]->FromRGB (m_loc,rgb,vector);
  }
    LxResult
  DrawSlice (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *vec)
  {
    return m_loc[0]->DrawSlice (m_loc,(ILxUnknownID)image,xAxis,yAxis,vec);
  }
    LxResult
  DrawSliceMarker (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *downVec, const float *vec)
  {
    return m_loc[0]->DrawSliceMarker (m_loc,(ILxUnknownID)image,xAxis,yAxis,downVec,vec);
  }
    LxResult
  CanSliceBeReused (unsigned xAxis, unsigned yAxis, const float *oldVec, const float *newVec)
  {
    return m_loc[0]->CanSliceBeReused (m_loc,xAxis,yAxis,oldVec,newVec);
  }
    LxResult
  ToSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float *vec, unsigned *imgX, unsigned *imgY)
  {
    return m_loc[0]->ToSlicePos (m_loc,xAxis,yAxis,imgW,imgH,vec,imgX,imgY);
  }
    LxResult
  FromSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float *downVec, float *vec)
  {
    return m_loc[0]->FromSlicePos (m_loc,xAxis,yAxis,imgW,imgH,imgX,imgY,downVec,vec);
  }
    LxResult
  StripBaseVector (unsigned axis, int dynamic, float *vec)
  {
    return m_loc[0]->StripBaseVector (m_loc,axis,dynamic,vec);
  }
};

#endif

