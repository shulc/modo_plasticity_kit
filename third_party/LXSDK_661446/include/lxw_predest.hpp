/*
 * C++ wrapper for lxpredest.h
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
#ifndef LXW_PREDEST_HPP
#define LXW_PREDEST_HPP

#include <lxpredest.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_MeshLayerPreDest = {0x052B08CD,0xF2F2,0x4C0F,0x9D,0x32,0x1A,0xAF,0xEF,0x49,0x4D,0x36};
    static const LXtGUID guid_Profile2DPreDest = {0x449009ED,0x847D,0x4925,0x94,0xBC,0xC5,0xE8,0xEC,0xCA,0xD5,0x15};
    static const LXtGUID guid_ColorPreDest = {0x307b5aab,0xf8df,0x4c5b,0xb9,0x16,0x22,0x31,0x72,0xea,0x92,0x1e};
    static const LXtGUID guid_Profile1DPreDest1 = {0xA4E5FAD3,0xE3A7,0x4ed9,0xA1,0xE3,0x4E,0xB0,0xD3,0x1A,0x41,0x87};
    static const LXtGUID guid_SceneItemPreDest = {0xF81AD9DB,0x6068,0x4782,0xB1,0xBB,0x7F,0x45,0x23,0x36,0x82,0xDC};
    static const LXtGUID guid_PresetDestinationService = {0xA4305404,0x7D11,0x4A9F,0xB8,0x69,0xF5,0x78,0x61,0xCE,0x1D,0x4D};
    static const LXtGUID guid_ShaderPreDest = {0x51CE68B9,0xBDED,0x41FC,0xBD,0x33,0x37,0xBB,0xAF,0xFD,0x18,0x0B};
    static const LXtGUID guid_Profile1DPreDest = {0x66879EE7,0x45AE,0x4704,0x8E,0x03,0x19,0xF9,0x98,0xEF,0xDE,0x73};
    static const LXtGUID guid_Profile2DPreDest1 = {0xF845F4AD,0x7DFC,0x4a41,0x98,0xD1,0x0F,0xFB,0x2C,0xA7,0x44,0xFB};
};

class CLxImpl_MeshLayerPreDest {
  public:
    virtual ~CLxImpl_MeshLayerPreDest() {}
    virtual LxResult
      mlpd_Mesh (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mlpd_Transform (LXtMatrix4 xform)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mlpd_ShaderDest (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_MeshLayerPreDest_Mesh LxResult mlpd_Mesh (void **ppvObj)
#define LXxO_MeshLayerPreDest_Mesh LXxD_MeshLayerPreDest_Mesh LXx_OVERRIDE
#define LXxC_MeshLayerPreDest_Mesh(c) LxResult c::mlpd_Mesh (void **ppvObj)
#define LXxD_MeshLayerPreDest_Transform LxResult mlpd_Transform (LXtMatrix4 xform)
#define LXxO_MeshLayerPreDest_Transform LXxD_MeshLayerPreDest_Transform LXx_OVERRIDE
#define LXxC_MeshLayerPreDest_Transform(c) LxResult c::mlpd_Transform (LXtMatrix4 xform)
#define LXxD_MeshLayerPreDest_ShaderDest LxResult mlpd_ShaderDest (void **ppvObj)
#define LXxO_MeshLayerPreDest_ShaderDest LXxD_MeshLayerPreDest_ShaderDest LXx_OVERRIDE
#define LXxC_MeshLayerPreDest_ShaderDest(c) LxResult c::mlpd_ShaderDest (void **ppvObj)
template <class T>
class CLxIfc_MeshLayerPreDest : public CLxInterface
{
    static LxResult
  Mesh (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_MeshLayerPreDest, loc);
    try {
      return loc->mlpd_Mesh (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Transform (LXtObjectID wcom, LXtMatrix4 xform)
  {
    LXCWxINST (CLxImpl_MeshLayerPreDest, loc);
    try {
      return loc->mlpd_Transform (xform);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ShaderDest (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_MeshLayerPreDest, loc);
    try {
      return loc->mlpd_ShaderDest (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxMeshLayerPreDest vt;
public:
  CLxIfc_MeshLayerPreDest ()
  {
    vt.Mesh = Mesh;
    vt.Transform = Transform;
    vt.ShaderDest = ShaderDest;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshLayerPreDest;
  }
};
class CLxLoc_MeshLayerPreDest : public CLxLocalize<ILxMeshLayerPreDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshLayerPreDest() {_init();}
  CLxLoc_MeshLayerPreDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshLayerPreDest(const CLxLoc_MeshLayerPreDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshLayerPreDest;}
    LxResult
  Mesh (void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,ppvObj);
  }
    CLxResult
  Mesh (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Mesh(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Transform (LXtMatrix4 xform)
  {
    return m_loc[0]->Transform (m_loc,xform);
  }
    LxResult
  ShaderDest (void **ppvObj)
  {
    return m_loc[0]->ShaderDest (m_loc,ppvObj);
  }
    CLxResult
  ShaderDest (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ShaderDest(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_Profile2DPreDest {
  public:
    virtual ~CLxImpl_Profile2DPreDest() {}
    virtual LxResult
      p2pd_MoveTo (double x, double y)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p2pd_LineTo (double x, double y)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p2pd_CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p2pd_NewPath (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p2pd_Closed (int closed)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p2pd_Box (LXtBBox *box)
        { return LXe_NOTIMPL; }
    virtual unsigned
      p2pd_Count (void)
        = 0;
    virtual LxResult
      p2pd_SelectByIndex (unsigned index)
        { return LXe_NOTIMPL; }
};
#define LXxD_Profile2DPreDest_MoveTo LxResult p2pd_MoveTo (double x, double y)
#define LXxO_Profile2DPreDest_MoveTo LXxD_Profile2DPreDest_MoveTo LXx_OVERRIDE
#define LXxC_Profile2DPreDest_MoveTo(c) LxResult c::p2pd_MoveTo (double x, double y)
#define LXxD_Profile2DPreDest_LineTo LxResult p2pd_LineTo (double x, double y)
#define LXxO_Profile2DPreDest_LineTo LXxD_Profile2DPreDest_LineTo LXx_OVERRIDE
#define LXxC_Profile2DPreDest_LineTo(c) LxResult c::p2pd_LineTo (double x, double y)
#define LXxD_Profile2DPreDest_CurveTo LxResult p2pd_CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
#define LXxO_Profile2DPreDest_CurveTo LXxD_Profile2DPreDest_CurveTo LXx_OVERRIDE
#define LXxC_Profile2DPreDest_CurveTo(c) LxResult c::p2pd_CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
#define LXxD_Profile2DPreDest_NewPath LxResult p2pd_NewPath (void)
#define LXxO_Profile2DPreDest_NewPath LXxD_Profile2DPreDest_NewPath LXx_OVERRIDE
#define LXxC_Profile2DPreDest_NewPath(c) LxResult c::p2pd_NewPath (void)
#define LXxD_Profile2DPreDest_Closed LxResult p2pd_Closed (int closed)
#define LXxO_Profile2DPreDest_Closed LXxD_Profile2DPreDest_Closed LXx_OVERRIDE
#define LXxC_Profile2DPreDest_Closed(c) LxResult c::p2pd_Closed (int closed)
#define LXxD_Profile2DPreDest_Box LxResult p2pd_Box (LXtBBox *box)
#define LXxO_Profile2DPreDest_Box LXxD_Profile2DPreDest_Box LXx_OVERRIDE
#define LXxC_Profile2DPreDest_Box(c) LxResult c::p2pd_Box (LXtBBox *box)
#define LXxD_Profile2DPreDest_Count unsigned p2pd_Count (void)
#define LXxO_Profile2DPreDest_Count LXxD_Profile2DPreDest_Count LXx_OVERRIDE
#define LXxC_Profile2DPreDest_Count(c) unsigned c::p2pd_Count (void)
#define LXxD_Profile2DPreDest_SelectByIndex LxResult p2pd_SelectByIndex (unsigned index)
#define LXxO_Profile2DPreDest_SelectByIndex LXxD_Profile2DPreDest_SelectByIndex LXx_OVERRIDE
#define LXxC_Profile2DPreDest_SelectByIndex(c) LxResult c::p2pd_SelectByIndex (unsigned index)
template <class T>
class CLxIfc_Profile2DPreDest : public CLxInterface
{
    static LxResult
  MoveTo (LXtObjectID wcom, double x, double y)
  {
    LXCWxINST (CLxImpl_Profile2DPreDest, loc);
    try {
      return loc->p2pd_MoveTo (x,y);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LineTo (LXtObjectID wcom, double x, double y)
  {
    LXCWxINST (CLxImpl_Profile2DPreDest, loc);
    try {
      return loc->p2pd_LineTo (x,y);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CurveTo (LXtObjectID wcom, double x0, double y0, double x1, double y1, double x2, double y2)
  {
    LXCWxINST (CLxImpl_Profile2DPreDest, loc);
    try {
      return loc->p2pd_CurveTo (x0,y0,x1,y1,x2,y2);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NewPath (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Profile2DPreDest, loc);
    try {
      return loc->p2pd_NewPath ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Closed (LXtObjectID wcom, int closed)
  {
    LXCWxINST (CLxImpl_Profile2DPreDest, loc);
    try {
      return loc->p2pd_Closed (closed);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Box (LXtObjectID wcom, LXtBBox *box)
  {
    LXCWxINST (CLxImpl_Profile2DPreDest, loc);
    try {
      return loc->p2pd_Box (box);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Profile2DPreDest, loc);
    return loc->p2pd_Count ();
  }
    static LxResult
  SelectByIndex (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_Profile2DPreDest, loc);
    try {
      return loc->p2pd_SelectByIndex (index);
    } catch (LxResult rc) { return rc; }
  }
  ILxProfile2DPreDest vt;
public:
  CLxIfc_Profile2DPreDest ()
  {
    vt.MoveTo = MoveTo;
    vt.LineTo = LineTo;
    vt.CurveTo = CurveTo;
    vt.NewPath = NewPath;
    vt.Closed = Closed;
    vt.Box = Box;
    vt.Count = Count;
    vt.SelectByIndex = SelectByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_Profile2DPreDest;
  }
};
class CLxLoc_Profile2DPreDest : public CLxLocalize<ILxProfile2DPreDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Profile2DPreDest() {_init();}
  CLxLoc_Profile2DPreDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Profile2DPreDest(const CLxLoc_Profile2DPreDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Profile2DPreDest;}
    LxResult
  MoveTo (double x, double y)
  {
    return m_loc[0]->MoveTo (m_loc,x,y);
  }
    LxResult
  LineTo (double x, double y)
  {
    return m_loc[0]->LineTo (m_loc,x,y);
  }
    LxResult
  CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
  {
    return m_loc[0]->CurveTo (m_loc,x0,y0,x1,y1,x2,y2);
  }
    LxResult
  NewPath (void)
  {
    return m_loc[0]->NewPath (m_loc);
  }
    LxResult
  Closed (int closed)
  {
    return m_loc[0]->Closed (m_loc,closed);
  }
    LxResult
  Box (LXtBBox *box)
  {
    return m_loc[0]->Box (m_loc,box);
  }
    unsigned
  Count (void)
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  SelectByIndex (unsigned index)
  {
    return m_loc[0]->SelectByIndex (m_loc,index);
  }
};

class CLxImpl_ColorPreDest {
  public:
    virtual ~CLxImpl_ColorPreDest() {}
    virtual LxResult
      colpd_SetColor (const LXtVector rgb)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colpd_SetColorModel (const char *name, const double *vec)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colpd_Apply (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_ColorPreDest_SetColor LxResult colpd_SetColor (const LXtVector rgb)
#define LXxO_ColorPreDest_SetColor LXxD_ColorPreDest_SetColor LXx_OVERRIDE
#define LXxC_ColorPreDest_SetColor(c) LxResult c::colpd_SetColor (const LXtVector rgb)
#define LXxD_ColorPreDest_SetColorModel LxResult colpd_SetColorModel (const char *name, const double *vec)
#define LXxO_ColorPreDest_SetColorModel LXxD_ColorPreDest_SetColorModel LXx_OVERRIDE
#define LXxC_ColorPreDest_SetColorModel(c) LxResult c::colpd_SetColorModel (const char *name, const double *vec)
#define LXxD_ColorPreDest_Apply LxResult colpd_Apply (void)
#define LXxO_ColorPreDest_Apply LXxD_ColorPreDest_Apply LXx_OVERRIDE
#define LXxC_ColorPreDest_Apply(c) LxResult c::colpd_Apply (void)
template <class T>
class CLxIfc_ColorPreDest : public CLxInterface
{
    static LxResult
  SetColor (LXtObjectID wcom, const LXtVector rgb)
  {
    LXCWxINST (CLxImpl_ColorPreDest, loc);
    try {
      return loc->colpd_SetColor (rgb);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetColorModel (LXtObjectID wcom, const char *name, const double *vec)
  {
    LXCWxINST (CLxImpl_ColorPreDest, loc);
    try {
      return loc->colpd_SetColorModel (name,vec);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Apply (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ColorPreDest, loc);
    try {
      return loc->colpd_Apply ();
    } catch (LxResult rc) { return rc; }
  }
  ILxColorPreDest vt;
public:
  CLxIfc_ColorPreDest ()
  {
    vt.SetColor = SetColor;
    vt.SetColorModel = SetColorModel;
    vt.Apply = Apply;
    vTable = &vt.iunk;
    iid = &lx::guid_ColorPreDest;
  }
};
class CLxLoc_ColorPreDest : public CLxLocalize<ILxColorPreDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ColorPreDest() {_init();}
  CLxLoc_ColorPreDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ColorPreDest(const CLxLoc_ColorPreDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ColorPreDest;}
    LxResult
  SetColor (const LXtVector rgb)
  {
    return m_loc[0]->SetColor (m_loc,rgb);
  }
    LxResult
  SetColorModel (const char *name, const double *vec)
  {
    return m_loc[0]->SetColorModel (m_loc,name,vec);
  }
    LxResult
  Apply (void)
  {
    return m_loc[0]->Apply (m_loc);
  }
};

class CLxImpl_Profile1DPreDest1 {
  public:
    virtual ~CLxImpl_Profile1DPreDest1() {}
    virtual LxResult
      p1pd_MoveTo (double x, double y)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p1pd_LineTo (double x, double y)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p1pd_CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
        { return LXe_NOTIMPL; }
    virtual double
      p1pd_Evaluate (double t, int flags, int axis)
        = 0;
    virtual int
      p1pd_PathSteps (double tol, int flags, double *x, double *y, int nstep)
        = 0;
    virtual LxResult
      p1pd_Box (LXtBBox *box)
        { return LXe_NOTIMPL; }
};
#define LXxD_Profile1DPreDest1_MoveTo LxResult p1pd_MoveTo (double x, double y)
#define LXxO_Profile1DPreDest1_MoveTo LXxD_Profile1DPreDest1_MoveTo LXx_OVERRIDE
#define LXxC_Profile1DPreDest1_MoveTo(c) LxResult c::p1pd_MoveTo (double x, double y)
#define LXxD_Profile1DPreDest1_LineTo LxResult p1pd_LineTo (double x, double y)
#define LXxO_Profile1DPreDest1_LineTo LXxD_Profile1DPreDest1_LineTo LXx_OVERRIDE
#define LXxC_Profile1DPreDest1_LineTo(c) LxResult c::p1pd_LineTo (double x, double y)
#define LXxD_Profile1DPreDest1_CurveTo LxResult p1pd_CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
#define LXxO_Profile1DPreDest1_CurveTo LXxD_Profile1DPreDest1_CurveTo LXx_OVERRIDE
#define LXxC_Profile1DPreDest1_CurveTo(c) LxResult c::p1pd_CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
#define LXxD_Profile1DPreDest1_Evaluate double p1pd_Evaluate (double t, int flags, int axis)
#define LXxO_Profile1DPreDest1_Evaluate LXxD_Profile1DPreDest1_Evaluate LXx_OVERRIDE
#define LXxC_Profile1DPreDest1_Evaluate(c) double c::p1pd_Evaluate (double t, int flags, int axis)
#define LXxD_Profile1DPreDest1_PathSteps int p1pd_PathSteps (double tol, int flags, double *x, double *y, int nstep)
#define LXxO_Profile1DPreDest1_PathSteps LXxD_Profile1DPreDest1_PathSteps LXx_OVERRIDE
#define LXxC_Profile1DPreDest1_PathSteps(c) int c::p1pd_PathSteps (double tol, int flags, double *x, double *y, int nstep)
#define LXxD_Profile1DPreDest1_Box LxResult p1pd_Box (LXtBBox *box)
#define LXxO_Profile1DPreDest1_Box LXxD_Profile1DPreDest1_Box LXx_OVERRIDE
#define LXxC_Profile1DPreDest1_Box(c) LxResult c::p1pd_Box (LXtBBox *box)
template <class T>
class CLxIfc_Profile1DPreDest1 : public CLxInterface
{
    static LxResult
  MoveTo (LXtObjectID wcom, double x, double y)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
    try {
      return loc->p1pd_MoveTo (x,y);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LineTo (LXtObjectID wcom, double x, double y)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
    try {
      return loc->p1pd_LineTo (x,y);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CurveTo (LXtObjectID wcom, double x0, double y0, double x1, double y1, double x2, double y2)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
    try {
      return loc->p1pd_CurveTo (x0,y0,x1,y1,x2,y2);
    } catch (LxResult rc) { return rc; }
  }
    static double
  Evaluate (LXtObjectID wcom, double t, int flags, int axis)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
    return loc->p1pd_Evaluate (t,flags,axis);
  }
    static int
  PathSteps (LXtObjectID wcom, double tol, int flags, double *x, double *y, int nstep)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
    return loc->p1pd_PathSteps (tol,flags,x,y,nstep);
  }
    static LxResult
  Box (LXtObjectID wcom, LXtBBox *box)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest1, loc);
    try {
      return loc->p1pd_Box (box);
    } catch (LxResult rc) { return rc; }
  }
  ILxProfile1DPreDest1 vt;
public:
  CLxIfc_Profile1DPreDest1 ()
  {
    vt.MoveTo = MoveTo;
    vt.LineTo = LineTo;
    vt.CurveTo = CurveTo;
    vt.Evaluate = Evaluate;
    vt.PathSteps = PathSteps;
    vt.Box = Box;
    vTable = &vt.iunk;
    iid = &lx::guid_Profile1DPreDest1;
  }
};
class CLxLoc_Profile1DPreDest1 : public CLxLocalize<ILxProfile1DPreDest1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Profile1DPreDest1() {_init();}
  CLxLoc_Profile1DPreDest1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Profile1DPreDest1(const CLxLoc_Profile1DPreDest1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Profile1DPreDest1;}
    LxResult
  MoveTo (double x, double y)
  {
    return m_loc[0]->MoveTo (m_loc,x,y);
  }
    LxResult
  LineTo (double x, double y)
  {
    return m_loc[0]->LineTo (m_loc,x,y);
  }
    LxResult
  CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
  {
    return m_loc[0]->CurveTo (m_loc,x0,y0,x1,y1,x2,y2);
  }
    double
  Evaluate (double t, int flags, int axis)
  {
    return m_loc[0]->Evaluate (m_loc,t,flags,axis);
  }
    int
  PathSteps (double tol, int flags, double *x, double *y, int nstep)
  {
    return m_loc[0]->PathSteps (m_loc,tol,flags,x,y,nstep);
  }
    LxResult
  Box (LXtBBox *box)
  {
    return m_loc[0]->Box (m_loc,box);
  }
};

class CLxImpl_SceneItemPreDest {
  public:
    virtual ~CLxImpl_SceneItemPreDest() {}
    virtual LxResult
      sipd_Scene (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sipd_Item (int *mode, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sipd_ContainerItem (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sipd_Position (LXtVector pos)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sipd_Orientation (LXtMatrix xfrm)
        { return LXe_NOTIMPL; }
};
#define LXxD_SceneItemPreDest_Scene LxResult sipd_Scene (void **ppvObj)
#define LXxO_SceneItemPreDest_Scene LXxD_SceneItemPreDest_Scene LXx_OVERRIDE
#define LXxC_SceneItemPreDest_Scene(c) LxResult c::sipd_Scene (void **ppvObj)
#define LXxD_SceneItemPreDest_Item LxResult sipd_Item (int *mode, void **ppvObj)
#define LXxO_SceneItemPreDest_Item LXxD_SceneItemPreDest_Item LXx_OVERRIDE
#define LXxC_SceneItemPreDest_Item(c) LxResult c::sipd_Item (int *mode, void **ppvObj)
#define LXxD_SceneItemPreDest_ContainerItem LxResult sipd_ContainerItem (void **ppvObj)
#define LXxO_SceneItemPreDest_ContainerItem LXxD_SceneItemPreDest_ContainerItem LXx_OVERRIDE
#define LXxC_SceneItemPreDest_ContainerItem(c) LxResult c::sipd_ContainerItem (void **ppvObj)
#define LXxD_SceneItemPreDest_Position LxResult sipd_Position (LXtVector pos)
#define LXxO_SceneItemPreDest_Position LXxD_SceneItemPreDest_Position LXx_OVERRIDE
#define LXxC_SceneItemPreDest_Position(c) LxResult c::sipd_Position (LXtVector pos)
#define LXxD_SceneItemPreDest_Orientation LxResult sipd_Orientation (LXtMatrix xfrm)
#define LXxO_SceneItemPreDest_Orientation LXxD_SceneItemPreDest_Orientation LXx_OVERRIDE
#define LXxC_SceneItemPreDest_Orientation(c) LxResult c::sipd_Orientation (LXtMatrix xfrm)
template <class T>
class CLxIfc_SceneItemPreDest : public CLxInterface
{
    static LxResult
  Scene (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SceneItemPreDest, loc);
    try {
      return loc->sipd_Scene (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Item (LXtObjectID wcom, int *mode, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SceneItemPreDest, loc);
    try {
      return loc->sipd_Item (mode,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ContainerItem (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SceneItemPreDest, loc);
    try {
      return loc->sipd_ContainerItem (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Position (LXtObjectID wcom, LXtVector pos)
  {
    LXCWxINST (CLxImpl_SceneItemPreDest, loc);
    try {
      return loc->sipd_Position (pos);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Orientation (LXtObjectID wcom, LXtMatrix xfrm)
  {
    LXCWxINST (CLxImpl_SceneItemPreDest, loc);
    try {
      return loc->sipd_Orientation (xfrm);
    } catch (LxResult rc) { return rc; }
  }
  ILxSceneItemPreDest vt;
public:
  CLxIfc_SceneItemPreDest ()
  {
    vt.Scene = Scene;
    vt.Item = Item;
    vt.ContainerItem = ContainerItem;
    vt.Position = Position;
    vt.Orientation = Orientation;
    vTable = &vt.iunk;
    iid = &lx::guid_SceneItemPreDest;
  }
};
class CLxLoc_SceneItemPreDest : public CLxLocalize<ILxSceneItemPreDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneItemPreDest() {_init();}
  CLxLoc_SceneItemPreDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SceneItemPreDest(const CLxLoc_SceneItemPreDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SceneItemPreDest;}
    LxResult
  Scene (void **ppvObj)
  {
    return m_loc[0]->Scene (m_loc,ppvObj);
  }
    CLxResult
  Scene (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Scene(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Item (int *mode, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,mode,ppvObj);
  }
    CLxResult
  Item (int *mode, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,mode,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ContainerItem (void **ppvObj)
  {
    return m_loc[0]->ContainerItem (m_loc,ppvObj);
  }
    CLxResult
  ContainerItem (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ContainerItem(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Position (LXtVector pos)
  {
    return m_loc[0]->Position (m_loc,pos);
  }
    LxResult
  Orientation (LXtMatrix xfrm)
  {
    return m_loc[0]->Orientation (m_loc,xfrm);
  }
};

class CLxLoc_PresetDestinationService : public CLxLocalizedService
{
public:
  ILxPresetDestinationServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_PresetDestinationService() {_init();set();}
 ~CLxLoc_PresetDestinationService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxPresetDestinationServiceID>(lx::GetGlobal(&lx::guid_PresetDestinationService));}
    LxResult
  ShaderPDFromItem (ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->ShaderPDFromItem (m_loc,(ILxUnknownID)item,ppvObj);
  }
    CLxResult
  ShaderPDFromItem (ILxUnknownID item, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ShaderPDFromItem(m_loc,(ILxUnknownID)item,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CreateMeshLayerPD (ILxUnknownID mesh, ILxUnknownID shadeItem, void **ppvObj)
  {
    return m_loc[0]->CreateMeshLayerPD (m_loc,(ILxUnknownID)mesh,(ILxUnknownID)shadeItem,ppvObj);
  }
    CLxResult
  CreateMeshLayerPD (ILxUnknownID mesh, ILxUnknownID shadeItem, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateMeshLayerPD(m_loc,(ILxUnknownID)mesh,(ILxUnknownID)shadeItem,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Profile1DPDFromPath (const char *filepath, void **ppvObj)
  {
    return m_loc[0]->Profile1DPDFromPath (m_loc,filepath,ppvObj);
  }
    CLxResult
  Profile1DPDFromPath (const char *filepath, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Profile1DPDFromPath(m_loc,filepath,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Profile2DPDFromPath (const char *filepath, void **ppvObj)
  {
    return m_loc[0]->Profile2DPDFromPath (m_loc,filepath,ppvObj);
  }
    CLxResult
  Profile2DPDFromPath (const char *filepath, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Profile2DPDFromPath(m_loc,filepath,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ApplyProfilePDToMesh (ILxUnknownID predest, double tolerance, int freeze, int axis, ILxUnknownID mesh)
  {
    return m_loc[0]->ApplyProfilePDToMesh (m_loc,(ILxUnknownID)predest,tolerance,freeze,axis,(ILxUnknownID)mesh);
  }
    LxResult
  ApplyMeshPresetToMeshPD (ILxUnknownID predest, const char *filepath)
  {
    return m_loc[0]->ApplyMeshPresetToMeshPD (m_loc,(ILxUnknownID)predest,filepath);
  }
};

class CLxImpl_ShaderPreDest {
  public:
    virtual ~CLxImpl_ShaderPreDest() {}
    virtual LxResult
      spd_Scene (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      spd_Item (int *mode, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      spd_ContainerItem (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      spd_HitItem (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      spd_GetTag (LXtID4 type, const char **tag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      spd_Mode (int *mode)
        { return LXe_NOTIMPL; }
};
#define LXxD_ShaderPreDest_Scene LxResult spd_Scene (void **ppvObj)
#define LXxO_ShaderPreDest_Scene LXxD_ShaderPreDest_Scene LXx_OVERRIDE
#define LXxC_ShaderPreDest_Scene(c) LxResult c::spd_Scene (void **ppvObj)
#define LXxD_ShaderPreDest_Item LxResult spd_Item (int *mode, void **ppvObj)
#define LXxO_ShaderPreDest_Item LXxD_ShaderPreDest_Item LXx_OVERRIDE
#define LXxC_ShaderPreDest_Item(c) LxResult c::spd_Item (int *mode, void **ppvObj)
#define LXxD_ShaderPreDest_ContainerItem LxResult spd_ContainerItem (void **ppvObj)
#define LXxO_ShaderPreDest_ContainerItem LXxD_ShaderPreDest_ContainerItem LXx_OVERRIDE
#define LXxC_ShaderPreDest_ContainerItem(c) LxResult c::spd_ContainerItem (void **ppvObj)
#define LXxD_ShaderPreDest_HitItem LxResult spd_HitItem (void **ppvObj)
#define LXxO_ShaderPreDest_HitItem LXxD_ShaderPreDest_HitItem LXx_OVERRIDE
#define LXxC_ShaderPreDest_HitItem(c) LxResult c::spd_HitItem (void **ppvObj)
#define LXxD_ShaderPreDest_GetTag LxResult spd_GetTag (LXtID4 type, const char **tag)
#define LXxO_ShaderPreDest_GetTag LXxD_ShaderPreDest_GetTag LXx_OVERRIDE
#define LXxC_ShaderPreDest_GetTag(c) LxResult c::spd_GetTag (LXtID4 type, const char **tag)
#define LXxD_ShaderPreDest_Mode LxResult spd_Mode (int *mode)
#define LXxO_ShaderPreDest_Mode LXxD_ShaderPreDest_Mode LXx_OVERRIDE
#define LXxC_ShaderPreDest_Mode(c) LxResult c::spd_Mode (int *mode)
template <class T>
class CLxIfc_ShaderPreDest : public CLxInterface
{
    static LxResult
  Scene (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ShaderPreDest, loc);
    try {
      return loc->spd_Scene (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Item (LXtObjectID wcom, int *mode, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ShaderPreDest, loc);
    try {
      return loc->spd_Item (mode,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ContainerItem (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ShaderPreDest, loc);
    try {
      return loc->spd_ContainerItem (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HitItem (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ShaderPreDest, loc);
    try {
      return loc->spd_HitItem (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetTag (LXtObjectID wcom, LXtID4 type, const char **tag)
  {
    LXCWxINST (CLxImpl_ShaderPreDest, loc);
    try {
      return loc->spd_GetTag (type,tag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Mode (LXtObjectID wcom, int *mode)
  {
    LXCWxINST (CLxImpl_ShaderPreDest, loc);
    try {
      return loc->spd_Mode (mode);
    } catch (LxResult rc) { return rc; }
  }
  ILxShaderPreDest vt;
public:
  CLxIfc_ShaderPreDest ()
  {
    vt.Scene = Scene;
    vt.Item = Item;
    vt.ContainerItem = ContainerItem;
    vt.HitItem = HitItem;
    vt.GetTag = GetTag;
    vt.Mode = Mode;
    vTable = &vt.iunk;
    iid = &lx::guid_ShaderPreDest;
  }
};
class CLxLoc_ShaderPreDest : public CLxLocalize<ILxShaderPreDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ShaderPreDest() {_init();}
  CLxLoc_ShaderPreDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ShaderPreDest(const CLxLoc_ShaderPreDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ShaderPreDest;}
    LxResult
  Scene (void **ppvObj)
  {
    return m_loc[0]->Scene (m_loc,ppvObj);
  }
    CLxResult
  Scene (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Scene(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Item (int *mode, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,mode,ppvObj);
  }
    CLxResult
  Item (int *mode, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,mode,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ContainerItem (void **ppvObj)
  {
    return m_loc[0]->ContainerItem (m_loc,ppvObj);
  }
    CLxResult
  ContainerItem (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ContainerItem(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  HitItem (void **ppvObj)
  {
    return m_loc[0]->HitItem (m_loc,ppvObj);
  }
    CLxResult
  HitItem (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->HitItem(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetTag (LXtID4 type, const char **tag)
  {
    return m_loc[0]->GetTag (m_loc,type,tag);
  }
    LxResult
  Mode (int *mode)
  {
    return m_loc[0]->Mode (m_loc,mode);
  }
};

class CLxImpl_Profile1DPreDest {
  public:
    virtual ~CLxImpl_Profile1DPreDest() {}
    virtual LxResult
      p1pd_MoveTo (double x, double y)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p1pd_LineTo (double x, double y)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p1pd_CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
        { return LXe_NOTIMPL; }
    virtual double
      p1pd_Evaluate (double t, int flags, int axis)
        = 0;
    virtual int
      p1pd_PathSteps (double tol, int flags, double *x, double *y, int nstep)
        = 0;
    virtual LxResult
      p1pd_Box (LXtBBox *box)
        { return LXe_NOTIMPL; }
    virtual unsigned
      p1pd_Count (void)
        = 0;
    virtual LxResult
      p1pd_SelectByIndex (unsigned index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p1pd_SelectByParameter (double t)
        { return LXe_NOTIMPL; }
    virtual LxResult
      p1pd_SelectByVertex (LXtMeshID meshID, LXtPointID pointID)
        { return LXe_NOTIMPL; }
};
#define LXxD_Profile1DPreDest_MoveTo LxResult p1pd_MoveTo (double x, double y)
#define LXxO_Profile1DPreDest_MoveTo LXxD_Profile1DPreDest_MoveTo LXx_OVERRIDE
#define LXxC_Profile1DPreDest_MoveTo(c) LxResult c::p1pd_MoveTo (double x, double y)
#define LXxD_Profile1DPreDest_LineTo LxResult p1pd_LineTo (double x, double y)
#define LXxO_Profile1DPreDest_LineTo LXxD_Profile1DPreDest_LineTo LXx_OVERRIDE
#define LXxC_Profile1DPreDest_LineTo(c) LxResult c::p1pd_LineTo (double x, double y)
#define LXxD_Profile1DPreDest_CurveTo LxResult p1pd_CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
#define LXxO_Profile1DPreDest_CurveTo LXxD_Profile1DPreDest_CurveTo LXx_OVERRIDE
#define LXxC_Profile1DPreDest_CurveTo(c) LxResult c::p1pd_CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
#define LXxD_Profile1DPreDest_Evaluate double p1pd_Evaluate (double t, int flags, int axis)
#define LXxO_Profile1DPreDest_Evaluate LXxD_Profile1DPreDest_Evaluate LXx_OVERRIDE
#define LXxC_Profile1DPreDest_Evaluate(c) double c::p1pd_Evaluate (double t, int flags, int axis)
#define LXxD_Profile1DPreDest_PathSteps int p1pd_PathSteps (double tol, int flags, double *x, double *y, int nstep)
#define LXxO_Profile1DPreDest_PathSteps LXxD_Profile1DPreDest_PathSteps LXx_OVERRIDE
#define LXxC_Profile1DPreDest_PathSteps(c) int c::p1pd_PathSteps (double tol, int flags, double *x, double *y, int nstep)
#define LXxD_Profile1DPreDest_Box LxResult p1pd_Box (LXtBBox *box)
#define LXxO_Profile1DPreDest_Box LXxD_Profile1DPreDest_Box LXx_OVERRIDE
#define LXxC_Profile1DPreDest_Box(c) LxResult c::p1pd_Box (LXtBBox *box)
#define LXxD_Profile1DPreDest_Count unsigned p1pd_Count (void)
#define LXxO_Profile1DPreDest_Count LXxD_Profile1DPreDest_Count LXx_OVERRIDE
#define LXxC_Profile1DPreDest_Count(c) unsigned c::p1pd_Count (void)
#define LXxD_Profile1DPreDest_SelectByIndex LxResult p1pd_SelectByIndex (unsigned index)
#define LXxO_Profile1DPreDest_SelectByIndex LXxD_Profile1DPreDest_SelectByIndex LXx_OVERRIDE
#define LXxC_Profile1DPreDest_SelectByIndex(c) LxResult c::p1pd_SelectByIndex (unsigned index)
#define LXxD_Profile1DPreDest_SelectByParameter LxResult p1pd_SelectByParameter (double t)
#define LXxO_Profile1DPreDest_SelectByParameter LXxD_Profile1DPreDest_SelectByParameter LXx_OVERRIDE
#define LXxC_Profile1DPreDest_SelectByParameter(c) LxResult c::p1pd_SelectByParameter (double t)
#define LXxD_Profile1DPreDest_SelectByVertex LxResult p1pd_SelectByVertex (LXtMeshID meshID, LXtPointID pointID)
#define LXxO_Profile1DPreDest_SelectByVertex LXxD_Profile1DPreDest_SelectByVertex LXx_OVERRIDE
#define LXxC_Profile1DPreDest_SelectByVertex(c) LxResult c::p1pd_SelectByVertex (LXtMeshID meshID, LXtPointID pointID)
template <class T>
class CLxIfc_Profile1DPreDest : public CLxInterface
{
    static LxResult
  MoveTo (LXtObjectID wcom, double x, double y)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest, loc);
    try {
      return loc->p1pd_MoveTo (x,y);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LineTo (LXtObjectID wcom, double x, double y)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest, loc);
    try {
      return loc->p1pd_LineTo (x,y);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CurveTo (LXtObjectID wcom, double x0, double y0, double x1, double y1, double x2, double y2)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest, loc);
    try {
      return loc->p1pd_CurveTo (x0,y0,x1,y1,x2,y2);
    } catch (LxResult rc) { return rc; }
  }
    static double
  Evaluate (LXtObjectID wcom, double t, int flags, int axis)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest, loc);
    return loc->p1pd_Evaluate (t,flags,axis);
  }
    static int
  PathSteps (LXtObjectID wcom, double tol, int flags, double *x, double *y, int nstep)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest, loc);
    return loc->p1pd_PathSteps (tol,flags,x,y,nstep);
  }
    static LxResult
  Box (LXtObjectID wcom, LXtBBox *box)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest, loc);
    try {
      return loc->p1pd_Box (box);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest, loc);
    return loc->p1pd_Count ();
  }
    static LxResult
  SelectByIndex (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest, loc);
    try {
      return loc->p1pd_SelectByIndex (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SelectByParameter (LXtObjectID wcom, double t)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest, loc);
    try {
      return loc->p1pd_SelectByParameter (t);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SelectByVertex (LXtObjectID wcom, LXtMeshID meshID, LXtPointID pointID)
  {
    LXCWxINST (CLxImpl_Profile1DPreDest, loc);
    try {
      return loc->p1pd_SelectByVertex (meshID,pointID);
    } catch (LxResult rc) { return rc; }
  }
  ILxProfile1DPreDest vt;
public:
  CLxIfc_Profile1DPreDest ()
  {
    vt.MoveTo = MoveTo;
    vt.LineTo = LineTo;
    vt.CurveTo = CurveTo;
    vt.Evaluate = Evaluate;
    vt.PathSteps = PathSteps;
    vt.Box = Box;
    vt.Count = Count;
    vt.SelectByIndex = SelectByIndex;
    vt.SelectByParameter = SelectByParameter;
    vt.SelectByVertex = SelectByVertex;
    vTable = &vt.iunk;
    iid = &lx::guid_Profile1DPreDest;
  }
};
class CLxLoc_Profile1DPreDest : public CLxLocalize<ILxProfile1DPreDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Profile1DPreDest() {_init();}
  CLxLoc_Profile1DPreDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Profile1DPreDest(const CLxLoc_Profile1DPreDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Profile1DPreDest;}
    LxResult
  MoveTo (double x, double y)
  {
    return m_loc[0]->MoveTo (m_loc,x,y);
  }
    LxResult
  LineTo (double x, double y)
  {
    return m_loc[0]->LineTo (m_loc,x,y);
  }
    LxResult
  CurveTo (double x0, double y0, double x1, double y1, double x2, double y2)
  {
    return m_loc[0]->CurveTo (m_loc,x0,y0,x1,y1,x2,y2);
  }
    double
  Evaluate (double t, int flags, int axis)
  {
    return m_loc[0]->Evaluate (m_loc,t,flags,axis);
  }
    int
  PathSteps (double tol, int flags, double *x, double *y, int nstep)
  {
    return m_loc[0]->PathSteps (m_loc,tol,flags,x,y,nstep);
  }
    LxResult
  Box (LXtBBox *box)
  {
    return m_loc[0]->Box (m_loc,box);
  }
    unsigned
  Count (void)
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  SelectByIndex (unsigned index)
  {
    return m_loc[0]->SelectByIndex (m_loc,index);
  }
    LxResult
  SelectByParameter (double t)
  {
    return m_loc[0]->SelectByParameter (m_loc,t);
  }
    LxResult
  SelectByVertex (LXtMeshID meshID, LXtPointID pointID)
  {
    return m_loc[0]->SelectByVertex (m_loc,meshID,pointID);
  }
};


#endif

