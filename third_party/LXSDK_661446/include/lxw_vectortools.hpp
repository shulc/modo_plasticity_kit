/*
 * C++ wrapper for lxvectortools.h
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
#ifndef LXW_VECTORTOOLS_HPP
#define LXW_VECTORTOOLS_HPP

#include <lxvectortools.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_VectorShape = {0x2B56643A,0x9697,0x42F4,0x99,0xF9,0x04,0xF9,0x60,0x38,0xD4,0x5E};
    static const LXtGUID guid_VectorCanvas = {0x7A7915F0,0xE496,0x40D3,0xBD,0x22,0x73,0x3D,0x73,0x88,0x56,0x52};
    static const LXtGUID guid_VectorListener = {0x90310E7B,0x85DB,0x4E5D,0x83,0x9B,0x25,0x56,0x2F,0xF5,0x07,0x13};
    static const LXtGUID guid_VectorPath = {0x13C5B133,0x4AE3,0x4934,0xB7,0x48,0xE2,0xB1,0xD3,0x90,0x48,0x74};
};

class CLxImpl_VectorShape {
  public:
    virtual ~CLxImpl_VectorShape() {}
    virtual LxResult
      shape_ShapeCount (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      shape_ShapeByIndex (unsigned int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      shape_Parent (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      shape_PathCount (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      shape_PathByIndex (unsigned int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      shape_Transform (const LXtMatrix matrix)
        { return LXe_NOTIMPL; }
};
#define LXxD_VectorShape_ShapeCount LxResult shape_ShapeCount (unsigned int *count)
#define LXxO_VectorShape_ShapeCount LXxD_VectorShape_ShapeCount LXx_OVERRIDE
#define LXxC_VectorShape_ShapeCount(c) LxResult c::shape_ShapeCount (unsigned int *count)
#define LXxD_VectorShape_ShapeByIndex LxResult shape_ShapeByIndex (unsigned int index, void **ppvObj)
#define LXxO_VectorShape_ShapeByIndex LXxD_VectorShape_ShapeByIndex LXx_OVERRIDE
#define LXxC_VectorShape_ShapeByIndex(c) LxResult c::shape_ShapeByIndex (unsigned int index, void **ppvObj)
#define LXxD_VectorShape_Parent LxResult shape_Parent (void **ppvObj)
#define LXxO_VectorShape_Parent LXxD_VectorShape_Parent LXx_OVERRIDE
#define LXxC_VectorShape_Parent(c) LxResult c::shape_Parent (void **ppvObj)
#define LXxD_VectorShape_PathCount LxResult shape_PathCount (unsigned int *count)
#define LXxO_VectorShape_PathCount LXxD_VectorShape_PathCount LXx_OVERRIDE
#define LXxC_VectorShape_PathCount(c) LxResult c::shape_PathCount (unsigned int *count)
#define LXxD_VectorShape_PathByIndex LxResult shape_PathByIndex (unsigned int index, void **ppvObj)
#define LXxO_VectorShape_PathByIndex LXxD_VectorShape_PathByIndex LXx_OVERRIDE
#define LXxC_VectorShape_PathByIndex(c) LxResult c::shape_PathByIndex (unsigned int index, void **ppvObj)
#define LXxD_VectorShape_Transform LxResult shape_Transform (const LXtMatrix matrix)
#define LXxO_VectorShape_Transform LXxD_VectorShape_Transform LXx_OVERRIDE
#define LXxC_VectorShape_Transform(c) LxResult c::shape_Transform (const LXtMatrix matrix)
template <class T>
class CLxIfc_VectorShape : public CLxInterface
{
    static LxResult
  ShapeCount (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_VectorShape, loc);
    try {
      return loc->shape_ShapeCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ShapeByIndex (LXtObjectID wcom, unsigned int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorShape, loc);
    try {
      return loc->shape_ShapeByIndex (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Parent (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorShape, loc);
    try {
      return loc->shape_Parent (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PathCount (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_VectorShape, loc);
    try {
      return loc->shape_PathCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PathByIndex (LXtObjectID wcom, unsigned int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorShape, loc);
    try {
      return loc->shape_PathByIndex (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Transform (LXtObjectID wcom, const LXtMatrix matrix)
  {
    LXCWxINST (CLxImpl_VectorShape, loc);
    try {
      return loc->shape_Transform (matrix);
    } catch (LxResult rc) { return rc; }
  }
  ILxVectorShape vt;
public:
  CLxIfc_VectorShape ()
  {
    vt.ShapeCount = ShapeCount;
    vt.ShapeByIndex = ShapeByIndex;
    vt.Parent = Parent;
    vt.PathCount = PathCount;
    vt.PathByIndex = PathByIndex;
    vt.Transform = Transform;
    vTable = &vt.iunk;
    iid = &lx::guid_VectorShape;
  }
};
class CLxLoc_VectorShape : public CLxLocalize<ILxVectorShapeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VectorShape() {_init();}
  CLxLoc_VectorShape(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VectorShape(const CLxLoc_VectorShape &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VectorShape;}
    LxResult
  ShapeCount (unsigned int *count)
  {
    return m_loc[0]->ShapeCount (m_loc,count);
  }
    LxResult
  ShapeByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->ShapeByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  ShapeByIndex (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ShapeByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
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
  PathCount (unsigned int *count)
  {
    return m_loc[0]->PathCount (m_loc,count);
  }
    LxResult
  PathByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->PathByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  PathByIndex (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->PathByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Transform (const LXtMatrix matrix)
  {
    return m_loc[0]->Transform (m_loc,matrix);
  }
};

class CLxImpl_VectorCanvas {
  public:
    virtual ~CLxImpl_VectorCanvas() {}
    virtual LxResult
      canvas_GetItem (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      canvas_BeginEditBatch (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      canvas_EndEditBatch (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_VectorCanvas_GetItem LxResult canvas_GetItem (void **ppvObj)
#define LXxO_VectorCanvas_GetItem LXxD_VectorCanvas_GetItem LXx_OVERRIDE
#define LXxC_VectorCanvas_GetItem(c) LxResult c::canvas_GetItem (void **ppvObj)
#define LXxD_VectorCanvas_BeginEditBatch LxResult canvas_BeginEditBatch (void)
#define LXxO_VectorCanvas_BeginEditBatch LXxD_VectorCanvas_BeginEditBatch LXx_OVERRIDE
#define LXxC_VectorCanvas_BeginEditBatch(c) LxResult c::canvas_BeginEditBatch (void)
#define LXxD_VectorCanvas_EndEditBatch LxResult canvas_EndEditBatch (void)
#define LXxO_VectorCanvas_EndEditBatch LXxD_VectorCanvas_EndEditBatch LXx_OVERRIDE
#define LXxC_VectorCanvas_EndEditBatch(c) LxResult c::canvas_EndEditBatch (void)
template <class T>
class CLxIfc_VectorCanvas : public CLxInterface
{
    static LxResult
  GetItem (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorCanvas, loc);
    try {
      return loc->canvas_GetItem (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BeginEditBatch (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VectorCanvas, loc);
    try {
      return loc->canvas_BeginEditBatch ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  EndEditBatch (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VectorCanvas, loc);
    try {
      return loc->canvas_EndEditBatch ();
    } catch (LxResult rc) { return rc; }
  }
  ILxVectorCanvas vt;
public:
  CLxIfc_VectorCanvas ()
  {
    vt.GetItem = GetItem;
    vt.BeginEditBatch = BeginEditBatch;
    vt.EndEditBatch = EndEditBatch;
    vTable = &vt.iunk;
    iid = &lx::guid_VectorCanvas;
  }
};
class CLxLoc_VectorCanvas : public CLxLocalize<ILxVectorCanvasID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VectorCanvas() {_init();}
  CLxLoc_VectorCanvas(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VectorCanvas(const CLxLoc_VectorCanvas &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VectorCanvas;}
    LxResult
  GetItem (void **ppvObj)
  {
    return m_loc[0]->GetItem (m_loc,ppvObj);
  }
    CLxResult
  GetItem (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetItem(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  BeginEditBatch (void)
  {
    return m_loc[0]->BeginEditBatch (m_loc);
  }
    LxResult
  EndEditBatch (void)
  {
    return m_loc[0]->EndEditBatch (m_loc);
  }
};

class CLxImpl_VectorListener {
  public:
    virtual ~CLxImpl_VectorListener() {}
    virtual LxResult
      vtl_Destroy (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtl_ShapeAdd (ILxUnknownID shape)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtl_ShapeRemove (ILxUnknownID shape)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtl_ShapeStyle (ILxUnknownID shape, const char *name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtl_PathAdd (ILxUnknownID shape, ILxUnknownID path)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtl_PathRemove (ILxUnknownID shape, ILxUnknownID path)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtl_KnotPosition (ILxUnknownID shape, ILxUnknownID path)
        { return LXe_NOTIMPL; }
};
#define LXxD_VectorListener_Destroy LxResult vtl_Destroy (void)
#define LXxO_VectorListener_Destroy LXxD_VectorListener_Destroy LXx_OVERRIDE
#define LXxC_VectorListener_Destroy(c) LxResult c::vtl_Destroy (void)
#define LXxD_VectorListener_ShapeAdd LxResult vtl_ShapeAdd (ILxUnknownID shape)
#define LXxO_VectorListener_ShapeAdd LXxD_VectorListener_ShapeAdd LXx_OVERRIDE
#define LXxC_VectorListener_ShapeAdd(c) LxResult c::vtl_ShapeAdd (ILxUnknownID shape)
#define LXxD_VectorListener_ShapeRemove LxResult vtl_ShapeRemove (ILxUnknownID shape)
#define LXxO_VectorListener_ShapeRemove LXxD_VectorListener_ShapeRemove LXx_OVERRIDE
#define LXxC_VectorListener_ShapeRemove(c) LxResult c::vtl_ShapeRemove (ILxUnknownID shape)
#define LXxD_VectorListener_ShapeStyle LxResult vtl_ShapeStyle (ILxUnknownID shape, const char *name)
#define LXxO_VectorListener_ShapeStyle LXxD_VectorListener_ShapeStyle LXx_OVERRIDE
#define LXxC_VectorListener_ShapeStyle(c) LxResult c::vtl_ShapeStyle (ILxUnknownID shape, const char *name)
#define LXxD_VectorListener_PathAdd LxResult vtl_PathAdd (ILxUnknownID shape, ILxUnknownID path)
#define LXxO_VectorListener_PathAdd LXxD_VectorListener_PathAdd LXx_OVERRIDE
#define LXxC_VectorListener_PathAdd(c) LxResult c::vtl_PathAdd (ILxUnknownID shape, ILxUnknownID path)
#define LXxD_VectorListener_PathRemove LxResult vtl_PathRemove (ILxUnknownID shape, ILxUnknownID path)
#define LXxO_VectorListener_PathRemove LXxD_VectorListener_PathRemove LXx_OVERRIDE
#define LXxC_VectorListener_PathRemove(c) LxResult c::vtl_PathRemove (ILxUnknownID shape, ILxUnknownID path)
#define LXxD_VectorListener_KnotPosition LxResult vtl_KnotPosition (ILxUnknownID shape, ILxUnknownID path)
#define LXxO_VectorListener_KnotPosition LXxD_VectorListener_KnotPosition LXx_OVERRIDE
#define LXxC_VectorListener_KnotPosition(c) LxResult c::vtl_KnotPosition (ILxUnknownID shape, ILxUnknownID path)
template <class T>
class CLxIfc_VectorListener : public CLxInterface
{
    static LxResult
  Destroy (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VectorListener, loc);
    try {
      return loc->vtl_Destroy ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ShapeAdd (LXtObjectID wcom, LXtObjectID shape)
  {
    LXCWxINST (CLxImpl_VectorListener, loc);
    try {
      return loc->vtl_ShapeAdd ((ILxUnknownID)shape);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ShapeRemove (LXtObjectID wcom, LXtObjectID shape)
  {
    LXCWxINST (CLxImpl_VectorListener, loc);
    try {
      return loc->vtl_ShapeRemove ((ILxUnknownID)shape);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ShapeStyle (LXtObjectID wcom, LXtObjectID shape, const char *name)
  {
    LXCWxINST (CLxImpl_VectorListener, loc);
    try {
      return loc->vtl_ShapeStyle ((ILxUnknownID)shape,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PathAdd (LXtObjectID wcom, LXtObjectID shape, LXtObjectID path)
  {
    LXCWxINST (CLxImpl_VectorListener, loc);
    try {
      return loc->vtl_PathAdd ((ILxUnknownID)shape,(ILxUnknownID)path);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PathRemove (LXtObjectID wcom, LXtObjectID shape, LXtObjectID path)
  {
    LXCWxINST (CLxImpl_VectorListener, loc);
    try {
      return loc->vtl_PathRemove ((ILxUnknownID)shape,(ILxUnknownID)path);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  KnotPosition (LXtObjectID wcom, LXtObjectID shape, LXtObjectID path)
  {
    LXCWxINST (CLxImpl_VectorListener, loc);
    try {
      return loc->vtl_KnotPosition ((ILxUnknownID)shape,(ILxUnknownID)path);
    } catch (LxResult rc) { return rc; }
  }
  ILxVectorListener vt;
public:
  CLxIfc_VectorListener ()
  {
    vt.Destroy = Destroy;
    vt.ShapeAdd = ShapeAdd;
    vt.ShapeRemove = ShapeRemove;
    vt.ShapeStyle = ShapeStyle;
    vt.PathAdd = PathAdd;
    vt.PathRemove = PathRemove;
    vt.KnotPosition = KnotPosition;
    vTable = &vt.iunk;
    iid = &lx::guid_VectorListener;
  }
};
class CLxLoc_VectorListener : public CLxLocalize<ILxVectorListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VectorListener() {_init();}
  CLxLoc_VectorListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VectorListener(const CLxLoc_VectorListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VectorListener;}
    LxResult
  Destroy (void)
  {
    return m_loc[0]->Destroy (m_loc);
  }
    LxResult
  ShapeAdd (ILxUnknownID shape)
  {
    return m_loc[0]->ShapeAdd (m_loc,(ILxUnknownID)shape);
  }
    LxResult
  ShapeRemove (ILxUnknownID shape)
  {
    return m_loc[0]->ShapeRemove (m_loc,(ILxUnknownID)shape);
  }
    LxResult
  ShapeStyle (ILxUnknownID shape, const char *name)
  {
    return m_loc[0]->ShapeStyle (m_loc,(ILxUnknownID)shape,name);
  }
    LxResult
  PathAdd (ILxUnknownID shape, ILxUnknownID path)
  {
    return m_loc[0]->PathAdd (m_loc,(ILxUnknownID)shape,(ILxUnknownID)path);
  }
    LxResult
  PathRemove (ILxUnknownID shape, ILxUnknownID path)
  {
    return m_loc[0]->PathRemove (m_loc,(ILxUnknownID)shape,(ILxUnknownID)path);
  }
    LxResult
  KnotPosition (ILxUnknownID shape, ILxUnknownID path)
  {
    return m_loc[0]->KnotPosition (m_loc,(ILxUnknownID)shape,(ILxUnknownID)path);
  }
};

class CLxImpl_VectorPath {
  public:
    virtual ~CLxImpl_VectorPath() {}
    virtual LxResult
      path_IsPathClosed (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      path_SetPathClosed (LxResult closed)
        { return LXe_NOTIMPL; }
    virtual LxResult
      path_KnotCount (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      path_SelectKnotByIndex (unsigned int index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      path_SelectKnot (LXtVectorKnotID knot)
        { return LXe_NOTIMPL; }
    virtual LxResult
      path_KnotEnumerate (ILxUnknownID visitor)
        { return LXe_NOTIMPL; }
    virtual LXtVectorKnotID
      path_ID (void)
        = 0;
    virtual LxResult
      path_Pos (double *x, double *y)
        { return LXe_NOTIMPL; }
};
#define LXxD_VectorPath_IsPathClosed LxResult path_IsPathClosed (void)
#define LXxO_VectorPath_IsPathClosed LXxD_VectorPath_IsPathClosed LXx_OVERRIDE
#define LXxC_VectorPath_IsPathClosed(c) LxResult c::path_IsPathClosed (void)
#define LXxD_VectorPath_SetPathClosed LxResult path_SetPathClosed (LxResult closed)
#define LXxO_VectorPath_SetPathClosed LXxD_VectorPath_SetPathClosed LXx_OVERRIDE
#define LXxC_VectorPath_SetPathClosed(c) LxResult c::path_SetPathClosed (LxResult closed)
#define LXxD_VectorPath_KnotCount LxResult path_KnotCount (unsigned int *count)
#define LXxO_VectorPath_KnotCount LXxD_VectorPath_KnotCount LXx_OVERRIDE
#define LXxC_VectorPath_KnotCount(c) LxResult c::path_KnotCount (unsigned int *count)
#define LXxD_VectorPath_SelectKnotByIndex LxResult path_SelectKnotByIndex (unsigned int index)
#define LXxO_VectorPath_SelectKnotByIndex LXxD_VectorPath_SelectKnotByIndex LXx_OVERRIDE
#define LXxC_VectorPath_SelectKnotByIndex(c) LxResult c::path_SelectKnotByIndex (unsigned int index)
#define LXxD_VectorPath_SelectKnot LxResult path_SelectKnot (LXtVectorKnotID knot)
#define LXxO_VectorPath_SelectKnot LXxD_VectorPath_SelectKnot LXx_OVERRIDE
#define LXxC_VectorPath_SelectKnot(c) LxResult c::path_SelectKnot (LXtVectorKnotID knot)
#define LXxD_VectorPath_KnotEnumerate LxResult path_KnotEnumerate (ILxUnknownID visitor)
#define LXxO_VectorPath_KnotEnumerate LXxD_VectorPath_KnotEnumerate LXx_OVERRIDE
#define LXxC_VectorPath_KnotEnumerate(c) LxResult c::path_KnotEnumerate (ILxUnknownID visitor)
#define LXxD_VectorPath_ID LXtVectorKnotID path_ID (void)
#define LXxO_VectorPath_ID LXxD_VectorPath_ID LXx_OVERRIDE
#define LXxC_VectorPath_ID(c) LXtVectorKnotID c::path_ID (void)
#define LXxD_VectorPath_Pos LxResult path_Pos (double *x, double *y)
#define LXxO_VectorPath_Pos LXxD_VectorPath_Pos LXx_OVERRIDE
#define LXxC_VectorPath_Pos(c) LxResult c::path_Pos (double *x, double *y)
template <class T>
class CLxIfc_VectorPath : public CLxInterface
{
    static LxResult
  IsPathClosed (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VectorPath, loc);
    try {
      return loc->path_IsPathClosed ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetPathClosed (LXtObjectID wcom, LxResult closed)
  {
    LXCWxINST (CLxImpl_VectorPath, loc);
    try {
      return loc->path_SetPathClosed (closed);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  KnotCount (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_VectorPath, loc);
    try {
      return loc->path_KnotCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SelectKnotByIndex (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_VectorPath, loc);
    try {
      return loc->path_SelectKnotByIndex (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SelectKnot (LXtObjectID wcom, LXtVectorKnotID knot)
  {
    LXCWxINST (CLxImpl_VectorPath, loc);
    try {
      return loc->path_SelectKnot (knot);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  KnotEnumerate (LXtObjectID wcom, LXtObjectID visitor)
  {
    LXCWxINST (CLxImpl_VectorPath, loc);
    try {
      return loc->path_KnotEnumerate ((ILxUnknownID)visitor);
    } catch (LxResult rc) { return rc; }
  }
    static LXtVectorKnotID
  ID (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VectorPath, loc);
    return loc->path_ID ();
  }
    static LxResult
  Pos (LXtObjectID wcom, double *x, double *y)
  {
    LXCWxINST (CLxImpl_VectorPath, loc);
    try {
      return loc->path_Pos (x,y);
    } catch (LxResult rc) { return rc; }
  }
  ILxVectorPath vt;
public:
  CLxIfc_VectorPath ()
  {
    vt.IsPathClosed = IsPathClosed;
    vt.SetPathClosed = SetPathClosed;
    vt.KnotCount = KnotCount;
    vt.SelectKnotByIndex = SelectKnotByIndex;
    vt.SelectKnot = SelectKnot;
    vt.KnotEnumerate = KnotEnumerate;
    vt.ID = ID;
    vt.Pos = Pos;
    vTable = &vt.iunk;
    iid = &lx::guid_VectorPath;
  }
};
class CLxLoc_VectorPath : public CLxLocalize<ILxVectorPathID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VectorPath() {_init();}
  CLxLoc_VectorPath(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VectorPath(const CLxLoc_VectorPath &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VectorPath;}
    LxResult
  IsPathClosed (void)
  {
    return m_loc[0]->IsPathClosed (m_loc);
  }
    LxResult
  SetPathClosed (LxResult closed)
  {
    return m_loc[0]->SetPathClosed (m_loc,closed);
  }
    LxResult
  KnotCount (unsigned int *count)
  {
    return m_loc[0]->KnotCount (m_loc,count);
  }
    LxResult
  SelectKnotByIndex (unsigned int index)
  {
    return m_loc[0]->SelectKnotByIndex (m_loc,index);
  }
    LxResult
  SelectKnot (LXtVectorKnotID knot)
  {
    return m_loc[0]->SelectKnot (m_loc,knot);
  }
    LxResult
  KnotEnumerate (ILxUnknownID visitor)
  {
    return m_loc[0]->KnotEnumerate (m_loc,(ILxUnknownID)visitor);
  }
    LXtVectorKnotID
  ID (void)
  {
    return m_loc[0]->ID (m_loc);
  }
    LxResult
  Pos (double *x, double *y)
  {
    return m_loc[0]->Pos (m_loc,x,y);
  }
};

#endif

