/*
 * C++ wrapper for lxpretype.h
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
#ifndef LXW_PRETYPE_HPP
#define LXW_PRETYPE_HPP

#include <lxpretype.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_PresetMetrics = {0x3139ccf8,0x57ee,0x472c,0x8d,0xc9,0xd5,0x1f,0x8c,0x0a,0xcb,0x6b};
    static const LXtGUID guid_PBSpecialSelListener = {0xe278629d,0xc00f,0x49c8,0x90,0x57,0xf6,0x11,0x2b,0x6a,0xe0,0x74};
    static const LXtGUID guid_PresetType1 = {0x2ED1F957,0x16BE,0x4d83,0x82,0xA3,0xBE,0x5A,0xF7,0x82,0x18,0x91};
    static const LXtGUID guid_PresetType = {0xea04c0c2,0x61af,0x4f45,0xb1,0xa1,0xbc,0xe6,0x81,0xe8,0x98,0x2d};
    static const LXtGUID guid_PresetLoaderTarget = {0x3B15936E,0x11F4,0x4D4A,0x8A,0xDC,0x83,0x10,0xC6,0xD9,0x50,0x8E};
    static const LXtGUID guid_PresetMetrics1 = {0x79185753,0x0696,0x4c54,0x9d,0xaa,0xfe,0x01,0x25,0x3b,0xfc,0x07};
    static const LXtGUID guid_PresetBrowserSource = {0xcc776670,0x63a8,0x4fa9,0x96,0x18,0xe3,0x69,0xb5,0xa2,0x2f,0x62};
    static const LXtGUID guid_PresetBrowserService = {0x05C3FF8F,0x5C3C,0x4463,0xAF,0x6E,0x43,0x9C,0x52,0x62,0x1D,0xCA};
    static const LXtGUID guid_PresetDo = {0x468f8808,0xe3cc,0x40fb,0x96,0xbe,0x11,0x9f,0x91,0xe0,0x1b,0x87};
};

class CLxImpl_PresetMetrics {
  public:
    virtual ~CLxImpl_PresetMetrics() {}
    virtual LxResult
      pmet_ThumbnailImage (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pmet_ThumbnailIdealSize (int *idealW, int *idealH)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pmet_ThumbnailResource (const char **resourceName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pmet_Metadata (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pmet_Markup (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pmet_Flags (int *flags)
        { return LXe_NOTIMPL; }
};
#define LXxD_PresetMetrics_ThumbnailImage LxResult pmet_ThumbnailImage (void **ppvObj)
#define LXxO_PresetMetrics_ThumbnailImage LXxD_PresetMetrics_ThumbnailImage LXx_OVERRIDE
#define LXxC_PresetMetrics_ThumbnailImage(c) LxResult c::pmet_ThumbnailImage (void **ppvObj)
#define LXxD_PresetMetrics_ThumbnailIdealSize LxResult pmet_ThumbnailIdealSize (int *idealW, int *idealH)
#define LXxO_PresetMetrics_ThumbnailIdealSize LXxD_PresetMetrics_ThumbnailIdealSize LXx_OVERRIDE
#define LXxC_PresetMetrics_ThumbnailIdealSize(c) LxResult c::pmet_ThumbnailIdealSize (int *idealW, int *idealH)
#define LXxD_PresetMetrics_ThumbnailResource LxResult pmet_ThumbnailResource (const char **resourceName)
#define LXxO_PresetMetrics_ThumbnailResource LXxD_PresetMetrics_ThumbnailResource LXx_OVERRIDE
#define LXxC_PresetMetrics_ThumbnailResource(c) LxResult c::pmet_ThumbnailResource (const char **resourceName)
#define LXxD_PresetMetrics_Metadata LxResult pmet_Metadata (void **ppvObj)
#define LXxO_PresetMetrics_Metadata LXxD_PresetMetrics_Metadata LXx_OVERRIDE
#define LXxC_PresetMetrics_Metadata(c) LxResult c::pmet_Metadata (void **ppvObj)
#define LXxD_PresetMetrics_Markup LxResult pmet_Markup (void **ppvObj)
#define LXxO_PresetMetrics_Markup LXxD_PresetMetrics_Markup LXx_OVERRIDE
#define LXxC_PresetMetrics_Markup(c) LxResult c::pmet_Markup (void **ppvObj)
#define LXxD_PresetMetrics_Flags LxResult pmet_Flags (int *flags)
#define LXxO_PresetMetrics_Flags LXxD_PresetMetrics_Flags LXx_OVERRIDE
#define LXxC_PresetMetrics_Flags(c) LxResult c::pmet_Flags (int *flags)
template <class T>
class CLxIfc_PresetMetrics : public CLxInterface
{
    static LxResult
  ThumbnailImage (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_PresetMetrics, loc);
    try {
      return loc->pmet_ThumbnailImage (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ThumbnailIdealSize (LXtObjectID wcom, int *idealW, int *idealH)
  {
    LXCWxINST (CLxImpl_PresetMetrics, loc);
    try {
      return loc->pmet_ThumbnailIdealSize (idealW,idealH);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ThumbnailResource (LXtObjectID wcom, const char **resourceName)
  {
    LXCWxINST (CLxImpl_PresetMetrics, loc);
    try {
      return loc->pmet_ThumbnailResource (resourceName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Metadata (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_PresetMetrics, loc);
    try {
      return loc->pmet_Metadata (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Markup (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_PresetMetrics, loc);
    try {
      return loc->pmet_Markup (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Flags (LXtObjectID wcom, int *flags)
  {
    LXCWxINST (CLxImpl_PresetMetrics, loc);
    try {
      return loc->pmet_Flags (flags);
    } catch (LxResult rc) { return rc; }
  }
  ILxPresetMetrics vt;
public:
  CLxIfc_PresetMetrics ()
  {
    vt.ThumbnailImage = ThumbnailImage;
    vt.ThumbnailIdealSize = ThumbnailIdealSize;
    vt.ThumbnailResource = ThumbnailResource;
    vt.Metadata = Metadata;
    vt.Markup = Markup;
    vt.Flags = Flags;
    vTable = &vt.iunk;
    iid = &lx::guid_PresetMetrics;
  }
};
class CLxLoc_PresetMetrics : public CLxLocalize<ILxPresetMetricsID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PresetMetrics() {_init();}
  CLxLoc_PresetMetrics(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PresetMetrics(const CLxLoc_PresetMetrics &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PresetMetrics;}
    LxResult
  ThumbnailImage (void **ppvObj)
  {
    return m_loc[0]->ThumbnailImage (m_loc,ppvObj);
  }
    CLxResult
  ThumbnailImage (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ThumbnailImage(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ThumbnailIdealSize (int *idealW, int *idealH)
  {
    return m_loc[0]->ThumbnailIdealSize (m_loc,idealW,idealH);
  }
    LxResult
  ThumbnailResource (const char **resourceName)
  {
    return m_loc[0]->ThumbnailResource (m_loc,resourceName);
  }
    LxResult
  Metadata (void **ppvObj)
  {
    return m_loc[0]->Metadata (m_loc,ppvObj);
  }
    CLxResult
  Metadata (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Metadata(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Markup (void **ppvObj)
  {
    return m_loc[0]->Markup (m_loc,ppvObj);
  }
    CLxResult
  Markup (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Markup(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Flags (int *flags)
  {
    return m_loc[0]->Flags (m_loc,flags);
  }
};


class CLxImpl_PresetType1 {
  public:
    virtual ~CLxImpl_PresetType1() {}
    virtual LxResult
      ptyp1_Recognize (const char *path, const LXtGUID **guid, const char **category)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp1_Apply (const char *path, ILxUnknownID destination)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp1_Do (const char *path)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp1_DoCommandFlags (const char *path, int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp1_Metrics (const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp1_GenericThumbnailResource (const char *path, const char **resourceName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp1_BaseAspect (float *aspect)
        { return LXe_NOTIMPL; }
};
#define LXxD_PresetType1_Recognize LxResult ptyp1_Recognize (const char *path, const LXtGUID **guid, const char **category)
#define LXxO_PresetType1_Recognize LXxD_PresetType1_Recognize LXx_OVERRIDE
#define LXxC_PresetType1_Recognize(c) LxResult c::ptyp1_Recognize (const char *path, const LXtGUID **guid, const char **category)
#define LXxD_PresetType1_Apply LxResult ptyp1_Apply (const char *path, ILxUnknownID destination)
#define LXxO_PresetType1_Apply LXxD_PresetType1_Apply LXx_OVERRIDE
#define LXxC_PresetType1_Apply(c) LxResult c::ptyp1_Apply (const char *path, ILxUnknownID destination)
#define LXxD_PresetType1_Do LxResult ptyp1_Do (const char *path)
#define LXxO_PresetType1_Do LXxD_PresetType1_Do LXx_OVERRIDE
#define LXxC_PresetType1_Do(c) LxResult c::ptyp1_Do (const char *path)
#define LXxD_PresetType1_DoCommandFlags LxResult ptyp1_DoCommandFlags (const char *path, int *flags)
#define LXxO_PresetType1_DoCommandFlags LXxD_PresetType1_DoCommandFlags LXx_OVERRIDE
#define LXxC_PresetType1_DoCommandFlags(c) LxResult c::ptyp1_DoCommandFlags (const char *path, int *flags)
#define LXxD_PresetType1_Metrics LxResult ptyp1_Metrics (const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, void **ppvObj)
#define LXxO_PresetType1_Metrics LXxD_PresetType1_Metrics LXx_OVERRIDE
#define LXxC_PresetType1_Metrics(c) LxResult c::ptyp1_Metrics (const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, void **ppvObj)
#define LXxD_PresetType1_GenericThumbnailResource LxResult ptyp1_GenericThumbnailResource (const char *path, const char **resourceName)
#define LXxO_PresetType1_GenericThumbnailResource LXxD_PresetType1_GenericThumbnailResource LXx_OVERRIDE
#define LXxC_PresetType1_GenericThumbnailResource(c) LxResult c::ptyp1_GenericThumbnailResource (const char *path, const char **resourceName)
#define LXxD_PresetType1_BaseAspect LxResult ptyp1_BaseAspect (float *aspect)
#define LXxO_PresetType1_BaseAspect LXxD_PresetType1_BaseAspect LXx_OVERRIDE
#define LXxC_PresetType1_BaseAspect(c) LxResult c::ptyp1_BaseAspect (float *aspect)
template <class T>
class CLxIfc_PresetType1 : public CLxInterface
{
    static LxResult
  Recognize (LXtObjectID wcom, const char *path, const LXtGUID **guid, const char **category)
  {
    LXCWxINST (CLxImpl_PresetType1, loc);
    try {
      return loc->ptyp1_Recognize (path,guid,category);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Apply (LXtObjectID wcom, const char *path, LXtObjectID destination)
  {
    LXCWxINST (CLxImpl_PresetType1, loc);
    try {
      return loc->ptyp1_Apply (path,(ILxUnknownID)destination);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Do (LXtObjectID wcom, const char *path)
  {
    LXCWxINST (CLxImpl_PresetType1, loc);
    try {
      return loc->ptyp1_Do (path);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DoCommandFlags (LXtObjectID wcom, const char *path, int *flags)
  {
    LXCWxINST (CLxImpl_PresetType1, loc);
    try {
      return loc->ptyp1_DoCommandFlags (path,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Metrics (LXtObjectID wcom, const char *path, int flags, int w, int h, LXtObjectID prevMetrics, void **ppvObj)
  {
    LXCWxINST (CLxImpl_PresetType1, loc);
    try {
      return loc->ptyp1_Metrics (path,flags,w,h,(ILxUnknownID)prevMetrics,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GenericThumbnailResource (LXtObjectID wcom, const char *path, const char **resourceName)
  {
    LXCWxINST (CLxImpl_PresetType1, loc);
    try {
      return loc->ptyp1_GenericThumbnailResource (path,resourceName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BaseAspect (LXtObjectID wcom, float *aspect)
  {
    LXCWxINST (CLxImpl_PresetType1, loc);
    try {
      return loc->ptyp1_BaseAspect (aspect);
    } catch (LxResult rc) { return rc; }
  }
  ILxPresetType1 vt;
public:
  CLxIfc_PresetType1 ()
  {
    vt.Recognize = Recognize;
    vt.Apply = Apply;
    vt.Do = Do;
    vt.DoCommandFlags = DoCommandFlags;
    vt.Metrics = Metrics;
    vt.GenericThumbnailResource = GenericThumbnailResource;
    vt.BaseAspect = BaseAspect;
    vTable = &vt.iunk;
    iid = &lx::guid_PresetType1;
  }
};
class CLxLoc_PresetType1 : public CLxLocalize<ILxPresetType1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PresetType1() {_init();}
  CLxLoc_PresetType1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PresetType1(const CLxLoc_PresetType1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PresetType1;}
    LxResult
  Recognize (const char *path, const LXtGUID **guid, const char **category)
  {
    return m_loc[0]->Recognize (m_loc,path,guid,category);
  }
    LxResult
  Apply (const char *path, ILxUnknownID destination)
  {
    return m_loc[0]->Apply (m_loc,path,(ILxUnknownID)destination);
  }
    LxResult
  Do (const char *path)
  {
    return m_loc[0]->Do (m_loc,path);
  }
    LxResult
  DoCommandFlags (const char *path, int *flags)
  {
    return m_loc[0]->DoCommandFlags (m_loc,path,flags);
  }
    LxResult
  Metrics (const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, void **ppvObj)
  {
    return m_loc[0]->Metrics (m_loc,path,flags,w,h,(ILxUnknownID)prevMetrics,ppvObj);
  }
    CLxResult
  Metrics (const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Metrics(m_loc,path,flags,w,h,(ILxUnknownID)prevMetrics,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GenericThumbnailResource (const char *path, const char **resourceName)
  {
    return m_loc[0]->GenericThumbnailResource (m_loc,path,resourceName);
  }
    LxResult
  BaseAspect (float *aspect)
  {
    return m_loc[0]->BaseAspect (m_loc,aspect);
  }
};

class CLxImpl_PresetType {
  public:
    virtual ~CLxImpl_PresetType() {}
    virtual LxResult
      ptyp_Recognize (const char *path, const char **category)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp_Apply (const char *path, ILxUnknownID destination)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp_Do (const char *path)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp_DoCommandFlags (const char *path, int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp_Metrics (const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp_GenericThumbnailResource (const char *path, const char **resourceName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp_BaseAspect (float *aspect)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp_StoreThumbnail (const char *path, ILxUnknownID image)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp_DefaultThumbnail (const char *path)
        { return LXe_NOTIMPL; }
    virtual LxResult
      ptyp_StoreMarkup (const char *path, ILxUnknownID attr)
        { return LXe_NOTIMPL; }
};
#define LXxD_PresetType_Recognize LxResult ptyp_Recognize (const char *path, const char **category)
#define LXxO_PresetType_Recognize LXxD_PresetType_Recognize LXx_OVERRIDE
#define LXxC_PresetType_Recognize(c) LxResult c::ptyp_Recognize (const char *path, const char **category)
#define LXxD_PresetType_Apply LxResult ptyp_Apply (const char *path, ILxUnknownID destination)
#define LXxO_PresetType_Apply LXxD_PresetType_Apply LXx_OVERRIDE
#define LXxC_PresetType_Apply(c) LxResult c::ptyp_Apply (const char *path, ILxUnknownID destination)
#define LXxD_PresetType_Do LxResult ptyp_Do (const char *path)
#define LXxO_PresetType_Do LXxD_PresetType_Do LXx_OVERRIDE
#define LXxC_PresetType_Do(c) LxResult c::ptyp_Do (const char *path)
#define LXxD_PresetType_DoCommandFlags LxResult ptyp_DoCommandFlags (const char *path, int *flags)
#define LXxO_PresetType_DoCommandFlags LXxD_PresetType_DoCommandFlags LXx_OVERRIDE
#define LXxC_PresetType_DoCommandFlags(c) LxResult c::ptyp_DoCommandFlags (const char *path, int *flags)
#define LXxD_PresetType_Metrics LxResult ptyp_Metrics (const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, void **ppvObj)
#define LXxO_PresetType_Metrics LXxD_PresetType_Metrics LXx_OVERRIDE
#define LXxC_PresetType_Metrics(c) LxResult c::ptyp_Metrics (const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, void **ppvObj)
#define LXxD_PresetType_GenericThumbnailResource LxResult ptyp_GenericThumbnailResource (const char *path, const char **resourceName)
#define LXxO_PresetType_GenericThumbnailResource LXxD_PresetType_GenericThumbnailResource LXx_OVERRIDE
#define LXxC_PresetType_GenericThumbnailResource(c) LxResult c::ptyp_GenericThumbnailResource (const char *path, const char **resourceName)
#define LXxD_PresetType_BaseAspect LxResult ptyp_BaseAspect (float *aspect)
#define LXxO_PresetType_BaseAspect LXxD_PresetType_BaseAspect LXx_OVERRIDE
#define LXxC_PresetType_BaseAspect(c) LxResult c::ptyp_BaseAspect (float *aspect)
#define LXxD_PresetType_StoreThumbnail LxResult ptyp_StoreThumbnail (const char *path, ILxUnknownID image)
#define LXxO_PresetType_StoreThumbnail LXxD_PresetType_StoreThumbnail LXx_OVERRIDE
#define LXxC_PresetType_StoreThumbnail(c) LxResult c::ptyp_StoreThumbnail (const char *path, ILxUnknownID image)
#define LXxD_PresetType_DefaultThumbnail LxResult ptyp_DefaultThumbnail (const char *path)
#define LXxO_PresetType_DefaultThumbnail LXxD_PresetType_DefaultThumbnail LXx_OVERRIDE
#define LXxC_PresetType_DefaultThumbnail(c) LxResult c::ptyp_DefaultThumbnail (const char *path)
#define LXxD_PresetType_StoreMarkup LxResult ptyp_StoreMarkup (const char *path, ILxUnknownID attr)
#define LXxO_PresetType_StoreMarkup LXxD_PresetType_StoreMarkup LXx_OVERRIDE
#define LXxC_PresetType_StoreMarkup(c) LxResult c::ptyp_StoreMarkup (const char *path, ILxUnknownID attr)
template <class T>
class CLxIfc_PresetType : public CLxInterface
{
    static LxResult
  Recognize (LXtObjectID wcom, const char *path, const char **category)
  {
    LXCWxINST (CLxImpl_PresetType, loc);
    try {
      return loc->ptyp_Recognize (path,category);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Apply (LXtObjectID wcom, const char *path, LXtObjectID destination)
  {
    LXCWxINST (CLxImpl_PresetType, loc);
    try {
      return loc->ptyp_Apply (path,(ILxUnknownID)destination);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Do (LXtObjectID wcom, const char *path)
  {
    LXCWxINST (CLxImpl_PresetType, loc);
    try {
      return loc->ptyp_Do (path);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DoCommandFlags (LXtObjectID wcom, const char *path, int *flags)
  {
    LXCWxINST (CLxImpl_PresetType, loc);
    try {
      return loc->ptyp_DoCommandFlags (path,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Metrics (LXtObjectID wcom, const char *path, int flags, int w, int h, LXtObjectID prevMetrics, void **ppvObj)
  {
    LXCWxINST (CLxImpl_PresetType, loc);
    try {
      return loc->ptyp_Metrics (path,flags,w,h,(ILxUnknownID)prevMetrics,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GenericThumbnailResource (LXtObjectID wcom, const char *path, const char **resourceName)
  {
    LXCWxINST (CLxImpl_PresetType, loc);
    try {
      return loc->ptyp_GenericThumbnailResource (path,resourceName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BaseAspect (LXtObjectID wcom, float *aspect)
  {
    LXCWxINST (CLxImpl_PresetType, loc);
    try {
      return loc->ptyp_BaseAspect (aspect);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  StoreThumbnail (LXtObjectID wcom, const char *path, LXtObjectID image)
  {
    LXCWxINST (CLxImpl_PresetType, loc);
    try {
      return loc->ptyp_StoreThumbnail (path,(ILxUnknownID)image);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DefaultThumbnail (LXtObjectID wcom, const char *path)
  {
    LXCWxINST (CLxImpl_PresetType, loc);
    try {
      return loc->ptyp_DefaultThumbnail (path);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  StoreMarkup (LXtObjectID wcom, const char *path, LXtObjectID attr)
  {
    LXCWxINST (CLxImpl_PresetType, loc);
    try {
      return loc->ptyp_StoreMarkup (path,(ILxUnknownID)attr);
    } catch (LxResult rc) { return rc; }
  }
  ILxPresetType vt;
public:
  CLxIfc_PresetType ()
  {
    vt.Recognize = Recognize;
    vt.Apply = Apply;
    vt.Do = Do;
    vt.DoCommandFlags = DoCommandFlags;
    vt.Metrics = Metrics;
    vt.GenericThumbnailResource = GenericThumbnailResource;
    vt.BaseAspect = BaseAspect;
    vt.StoreThumbnail = StoreThumbnail;
    vt.DefaultThumbnail = DefaultThumbnail;
    vt.StoreMarkup = StoreMarkup;
    vTable = &vt.iunk;
    iid = &lx::guid_PresetType;
  }
};
class CLxLoc_PresetType : public CLxLocalize<ILxPresetTypeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PresetType() {_init();}
  CLxLoc_PresetType(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PresetType(const CLxLoc_PresetType &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PresetType;}
    LxResult
  Recognize (const char *path, const char **category)
  {
    return m_loc[0]->Recognize (m_loc,path,category);
  }
    LxResult
  Apply (const char *path, ILxUnknownID destination)
  {
    return m_loc[0]->Apply (m_loc,path,(ILxUnknownID)destination);
  }
    LxResult
  Do (const char *path)
  {
    return m_loc[0]->Do (m_loc,path);
  }
    LxResult
  DoCommandFlags (const char *path, int *flags)
  {
    return m_loc[0]->DoCommandFlags (m_loc,path,flags);
  }
    LxResult
  Metrics (const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, void **ppvObj)
  {
    return m_loc[0]->Metrics (m_loc,path,flags,w,h,(ILxUnknownID)prevMetrics,ppvObj);
  }
    CLxResult
  Metrics (const char *path, int flags, int w, int h, ILxUnknownID prevMetrics, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Metrics(m_loc,path,flags,w,h,(ILxUnknownID)prevMetrics,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GenericThumbnailResource (const char *path, const char **resourceName)
  {
    return m_loc[0]->GenericThumbnailResource (m_loc,path,resourceName);
  }
    LxResult
  BaseAspect (float *aspect)
  {
    return m_loc[0]->BaseAspect (m_loc,aspect);
  }
    LxResult
  StoreThumbnail (const char *path, ILxUnknownID image)
  {
    return m_loc[0]->StoreThumbnail (m_loc,path,(ILxUnknownID)image);
  }
    LxResult
  DefaultThumbnail (const char *path)
  {
    return m_loc[0]->DefaultThumbnail (m_loc,path);
  }
    LxResult
  StoreMarkup (const char *path, ILxUnknownID attr)
  {
    return m_loc[0]->StoreMarkup (m_loc,path,(ILxUnknownID)attr);
  }
};

class CLxLoc_PresetLoaderTarget : public CLxLocalize<ILxPresetLoaderTargetID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PresetLoaderTarget() {_init();}
  CLxLoc_PresetLoaderTarget(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PresetLoaderTarget(const CLxLoc_PresetLoaderTarget &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PresetLoaderTarget;}
    LxResult
  ServerName (char *buf, unsigned len)
  {
    return m_loc[0]->ServerName (m_loc,buf,len);
  }
    LxResult
  ServerName (std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ServerName (m_loc,buf,len);
    LXWx_SBUF2
  }
    LxResult
  CategoryCount (int *count)
  {
    return m_loc[0]->CategoryCount (m_loc,count);
  }
    LxResult
  CategoryByIndex (int index, const char **category)
  {
    return m_loc[0]->CategoryByIndex (m_loc,index,category);
  }
};

class CLxImpl_PresetMetrics1 {
  public:
    virtual ~CLxImpl_PresetMetrics1() {}
    virtual LxResult
      pmet1_Label (const char **label)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pmet1_ThumbnailImage (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pmet1_ThumbnailIdealSize (int *idealW, int *idealH)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pmet1_ThumbnailResource (const char **resourceName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pmet1_Caption (const char **caption)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pmet1_ToolTip (const char **tooltip)
        { return LXe_NOTIMPL; }
};
#define LXxD_PresetMetrics1_Label LxResult pmet1_Label (const char **label)
#define LXxO_PresetMetrics1_Label LXxD_PresetMetrics1_Label LXx_OVERRIDE
#define LXxC_PresetMetrics1_Label(c) LxResult c::pmet1_Label (const char **label)
#define LXxD_PresetMetrics1_ThumbnailImage LxResult pmet1_ThumbnailImage (void **ppvObj)
#define LXxO_PresetMetrics1_ThumbnailImage LXxD_PresetMetrics1_ThumbnailImage LXx_OVERRIDE
#define LXxC_PresetMetrics1_ThumbnailImage(c) LxResult c::pmet1_ThumbnailImage (void **ppvObj)
#define LXxD_PresetMetrics1_ThumbnailIdealSize LxResult pmet1_ThumbnailIdealSize (int *idealW, int *idealH)
#define LXxO_PresetMetrics1_ThumbnailIdealSize LXxD_PresetMetrics1_ThumbnailIdealSize LXx_OVERRIDE
#define LXxC_PresetMetrics1_ThumbnailIdealSize(c) LxResult c::pmet1_ThumbnailIdealSize (int *idealW, int *idealH)
#define LXxD_PresetMetrics1_ThumbnailResource LxResult pmet1_ThumbnailResource (const char **resourceName)
#define LXxO_PresetMetrics1_ThumbnailResource LXxD_PresetMetrics1_ThumbnailResource LXx_OVERRIDE
#define LXxC_PresetMetrics1_ThumbnailResource(c) LxResult c::pmet1_ThumbnailResource (const char **resourceName)
#define LXxD_PresetMetrics1_Caption LxResult pmet1_Caption (const char **caption)
#define LXxO_PresetMetrics1_Caption LXxD_PresetMetrics1_Caption LXx_OVERRIDE
#define LXxC_PresetMetrics1_Caption(c) LxResult c::pmet1_Caption (const char **caption)
#define LXxD_PresetMetrics1_ToolTip LxResult pmet1_ToolTip (const char **tooltip)
#define LXxO_PresetMetrics1_ToolTip LXxD_PresetMetrics1_ToolTip LXx_OVERRIDE
#define LXxC_PresetMetrics1_ToolTip(c) LxResult c::pmet1_ToolTip (const char **tooltip)
template <class T>
class CLxIfc_PresetMetrics1 : public CLxInterface
{
    static LxResult
  Label (LXtObjectID wcom, const char **label)
  {
    LXCWxINST (CLxImpl_PresetMetrics1, loc);
    try {
      return loc->pmet1_Label (label);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ThumbnailImage (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_PresetMetrics1, loc);
    try {
      return loc->pmet1_ThumbnailImage (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ThumbnailIdealSize (LXtObjectID wcom, int *idealW, int *idealH)
  {
    LXCWxINST (CLxImpl_PresetMetrics1, loc);
    try {
      return loc->pmet1_ThumbnailIdealSize (idealW,idealH);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ThumbnailResource (LXtObjectID wcom, const char **resourceName)
  {
    LXCWxINST (CLxImpl_PresetMetrics1, loc);
    try {
      return loc->pmet1_ThumbnailResource (resourceName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Caption (LXtObjectID wcom, const char **caption)
  {
    LXCWxINST (CLxImpl_PresetMetrics1, loc);
    try {
      return loc->pmet1_Caption (caption);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToolTip (LXtObjectID wcom, const char **tooltip)
  {
    LXCWxINST (CLxImpl_PresetMetrics1, loc);
    try {
      return loc->pmet1_ToolTip (tooltip);
    } catch (LxResult rc) { return rc; }
  }
  ILxPresetMetrics1 vt;
public:
  CLxIfc_PresetMetrics1 ()
  {
    vt.Label = Label;
    vt.ThumbnailImage = ThumbnailImage;
    vt.ThumbnailIdealSize = ThumbnailIdealSize;
    vt.ThumbnailResource = ThumbnailResource;
    vt.Caption = Caption;
    vt.ToolTip = ToolTip;
    vTable = &vt.iunk;
    iid = &lx::guid_PresetMetrics1;
  }
};
class CLxLoc_PresetMetrics1 : public CLxLocalize<ILxPresetMetrics1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PresetMetrics1() {_init();}
  CLxLoc_PresetMetrics1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PresetMetrics1(const CLxLoc_PresetMetrics1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PresetMetrics1;}
    LxResult
  Label (const char **label)
  {
    return m_loc[0]->Label (m_loc,label);
  }
    LxResult
  ThumbnailImage (void **ppvObj)
  {
    return m_loc[0]->ThumbnailImage (m_loc,ppvObj);
  }
    CLxResult
  ThumbnailImage (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ThumbnailImage(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ThumbnailIdealSize (int *idealW, int *idealH)
  {
    return m_loc[0]->ThumbnailIdealSize (m_loc,idealW,idealH);
  }
    LxResult
  ThumbnailResource (const char **resourceName)
  {
    return m_loc[0]->ThumbnailResource (m_loc,resourceName);
  }
    LxResult
  Caption (const char **caption)
  {
    return m_loc[0]->Caption (m_loc,caption);
  }
    LxResult
  ToolTip (const char **tooltip)
  {
    return m_loc[0]->ToolTip (m_loc,tooltip);
  }
};

class CLxLoc_PresetBrowserSource : public CLxLocalize<ILxPresetBrowserSourceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PresetBrowserSource() {_init();}
  CLxLoc_PresetBrowserSource(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PresetBrowserSource(const CLxLoc_PresetBrowserSource &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PresetBrowserSource;}
    LxResult
  ViewportHash (char *buf, int len)
  {
    return m_loc[0]->ViewportHash (m_loc,buf,len);
  }
};

class CLxLoc_PresetBrowserService : public CLxLocalizedService
{
public:
  ILxPresetBrowserServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_PresetBrowserService() {_init();set();}
 ~CLxLoc_PresetBrowserService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxPresetBrowserServiceID>(lx::GetGlobal(&lx::guid_PresetBrowserService));}
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
  SubtypeFromIdentifier (const char *identifier, int *subtype)
  {
    return m_loc[0]->SubtypeFromIdentifier (m_loc,identifier,subtype);
  }
    LxResult
  UpdateIdentifierState (const char *identifier, const char *path)
  {
    return m_loc[0]->UpdateIdentifierState (m_loc,identifier,path);
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
  RecognizeFile (const char *path, int flags, const char **serverName, const char **category)
  {
    return m_loc[0]->RecognizeFile (m_loc,path,flags,serverName,category);
  }
    LxResult
  RecognizeFileForce (const char *path, int flags, const char **serverName, const char **category)
  {
    return m_loc[0]->RecognizeFileForce (m_loc,path,flags,serverName,category);
  }
    LxResult
  Rescan (const char *path)
  {
    return m_loc[0]->Rescan (m_loc,path);
  }
    LxResult
  IsViewportVisible (const char *identifier, const char *hash)
  {
    return m_loc[0]->IsViewportVisible (m_loc,identifier,hash);
  }
    LxResult
  GetSpecialSelModePath (const char *identifier, char *buf, int len)
  {
    return m_loc[0]->GetSpecialSelModePath (m_loc,identifier,buf,len);
  }
    LxResult
  SetSpecialSelModePath (const char *identifier, const char *path, int asInteractive)
  {
    return m_loc[0]->SetSpecialSelModePath (m_loc,identifier,path,asInteractive);
  }
};

class CLxImpl_PresetDo {
  public:
    virtual ~CLxImpl_PresetDo() {}
    virtual LxResult
      pdo_Test (const char *path)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pdo_Do (const char *path)
        { return LXe_NOTIMPL; }
};
#define LXxD_PresetDo_Test LxResult pdo_Test (const char *path)
#define LXxO_PresetDo_Test LXxD_PresetDo_Test LXx_OVERRIDE
#define LXxC_PresetDo_Test(c) LxResult c::pdo_Test (const char *path)
#define LXxD_PresetDo_Do LxResult pdo_Do (const char *path)
#define LXxO_PresetDo_Do LXxD_PresetDo_Do LXx_OVERRIDE
#define LXxC_PresetDo_Do(c) LxResult c::pdo_Do (const char *path)
template <class T>
class CLxIfc_PresetDo : public CLxInterface
{
    static LxResult
  Test (LXtObjectID wcom, const char *path)
  {
    LXCWxINST (CLxImpl_PresetDo, loc);
    try {
      return loc->pdo_Test (path);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Do (LXtObjectID wcom, const char *path)
  {
    LXCWxINST (CLxImpl_PresetDo, loc);
    try {
      return loc->pdo_Do (path);
    } catch (LxResult rc) { return rc; }
  }
  ILxPresetDo vt;
public:
  CLxIfc_PresetDo ()
  {
    vt.Test = Test;
    vt.Do = Do;
    vTable = &vt.iunk;
    iid = &lx::guid_PresetDo;
  }
};
class CLxLoc_PresetDo : public CLxLocalize<ILxPresetDoID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PresetDo() {_init();}
  CLxLoc_PresetDo(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PresetDo(const CLxLoc_PresetDo &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PresetDo;}
    LxResult
  Test (const char *path)
  {
    return m_loc[0]->Test (m_loc,path);
  }
    LxResult
  Do (const char *path)
  {
    return m_loc[0]->Do (m_loc,path);
  }
};

#endif

