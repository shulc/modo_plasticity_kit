/*
 * C++ wrapper for lxrendercache.h
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
#ifndef LXW_RENDERCACHE_HPP
#define LXW_RENDERCACHE_HPP

#include <lxrendercache.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_GeoCacheSegment = {0xCDA6EDAD,0x8E71,0x4EA9,0xA0,0x5A,0x32,0x6C,0xEA,0xD7,0xDE,0x9B};
    static const LXtGUID guid_GeoCacheSurface = {0x770BD566,0x315B,0x4EEC,0xA2,0xA5,0x26,0x6D,0x12,0x2D,0x8D,0xDF};
    static const LXtGUID guid_RenderCacheService = {0x138FF638,0x1E34,0x4CC6,0xBA,0xFC,0x4F,0x73,0x49,0x69,0xF4,0x7E};
    static const LXtGUID guid_RenderCacheListener1 = {0xE1EBCD71,0xB28A,0x42FB,0x9A,0xF7,0xFA,0xDA,0x18,0xFE,0xBF,0xC6};
    static const LXtGUID guid_RenderCache = {0x1ED14AD3,0xB202,0x46FF,0xA7,0x20,0xA1,0xDC,0xFC,0x0B,0x89,0x3A};
    static const LXtGUID guid_RenderCacheListener = {0xBBF6E7B5,0xC59D,0x45D2,0x97,0xE6,0xF4,0x95,0x92,0xA7,0xEA,0x6A};
};

class CLxLoc_GeoCacheSegment : public CLxLocalize<ILxGeoCacheSegmentID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GeoCacheSegment() {_init();}
  CLxLoc_GeoCacheSegment(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GeoCacheSegment(const CLxLoc_GeoCacheSegment &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GeoCacheSegment;}
    LxResult
  GetBBox (LXtBBox *bbox)
  {
    return m_loc[0]->GetBBox (m_loc,bbox);
  }
    void
  PolygonCount (int *count)
  {
    m_loc[0]->PolygonCount (m_loc,count);
  }
    void
  VertexCount (int *count)
  {
    m_loc[0]->VertexCount (m_loc,count);
  }
    void
  VertsPerPoly (int *count)
  {
    m_loc[0]->VertsPerPoly (m_loc,count);
  }
    void
  VertexFeatureCount (int feature, int *count)
  {
    m_loc[0]->VertexFeatureCount (m_loc,feature,count);
  }
    LxResult
  GetPolygonVertexFeature (int feature, void *featureData, int count, int start)
  {
    return m_loc[0]->GetPolygonVertexFeature (m_loc,feature,featureData,count,start);
  }
    LxResult
  GetVertexFeature (int feature, void *featureData, int count, int start)
  {
    return m_loc[0]->GetVertexFeature (m_loc,feature,featureData,count,start);
  }
    LxResult
  GetPolygonVertexInds (int *polyVertexInds, int count, int start)
  {
    return m_loc[0]->GetPolygonVertexInds (m_loc,polyVertexInds,count,start);
  }
};

class CLxLoc_GeoCacheSurface : public CLxLocalize<ILxGeoCacheSurfaceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GeoCacheSurface() {_init();}
  CLxLoc_GeoCacheSurface(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GeoCacheSurface(const CLxLoc_GeoCacheSurface &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GeoCacheSurface;}
    LxResult
  ShaderMaskName (const char **name)
  {
    return m_loc[0]->ShaderMaskName (m_loc,name);
  }
    int
  ShaderMaskType (void)
  {
    return m_loc[0]->ShaderMaskType (m_loc);
  }
    LxResult
  SourceItem (void **ppvObj)
  {
    return m_loc[0]->SourceItem (m_loc,ppvObj);
  }
    CLxResult
  SourceItem (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SourceItem(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    int
  IsInstanced (void)
  {
    return m_loc[0]->IsInstanced (m_loc);
  }
    int
  InstanceIndex (void)
  {
    return m_loc[0]->InstanceIndex (m_loc);
  }
    LxResult
  SourceSurface (void **ppvObj)
  {
    return m_loc[0]->SourceSurface (m_loc,ppvObj);
  }
    CLxResult
  SourceSurface (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SourceSurface(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetBBox (LXtBBox *bbox)
  {
    return m_loc[0]->GetBBox (m_loc,bbox);
  }
    LxResult
  GetXfrm (LXtVector pos, LXtMatrix rot, LXtVector scl, int endpoint)
  {
    return m_loc[0]->GetXfrm (m_loc,pos,rot,scl,endpoint);
  }
    void
  SegmentCount (int *count)
  {
    m_loc[0]->SegmentCount (m_loc,count);
  }
    void
  PolygonCount (int *count)
  {
    m_loc[0]->PolygonCount (m_loc,count);
  }
    void
  VertexCount (int *count)
  {
    m_loc[0]->VertexCount (m_loc,count);
  }
    LxResult
  SegmentAt (int index, void **segment)
  {
    return m_loc[0]->SegmentAt (m_loc,index,segment);
  }
    LxResult
  VisibilityFlags (LXtGeoCacheSrfVisibility *flags)
  {
    return m_loc[0]->VisibilityFlags (m_loc,flags);
  }
    int
  ID (void)
  {
    return m_loc[0]->ID (m_loc);
  }
    int
  IsValid (void)
  {
    return m_loc[0]->IsValid (m_loc);
  }
    LxResult
  LoadSegments (void)
  {
    return m_loc[0]->LoadSegments (m_loc);
  }
    LxResult
  UnloadSegments (void)
  {
    return m_loc[0]->UnloadSegments (m_loc);
  }
    ILxTableauVertexID
  GetVertexDesc (void)
  {
    return m_loc[0]->GetVertexDesc (m_loc);
  }
    const char*
  MaterialPTag (void)
  {
    return m_loc[0]->MaterialPTag (m_loc);
  }
    const char*
  PartPTag (void)
  {
    return m_loc[0]->PartPTag (m_loc);
  }
    const char*
  PickPTag (void)
  {
    return m_loc[0]->PickPTag (m_loc);
  }
    LxResult
  ShaderLayerCount (unsigned int *count)
  {
    return m_loc[0]->ShaderLayerCount (m_loc,count);
  }
    LxResult
  ShaderLayerAt (unsigned int index, void **shaderLayer)
  {
    return m_loc[0]->ShaderLayerAt (m_loc,index,shaderLayer);
  }
};

class CLxLoc_RenderCacheService : public CLxLocalizedService
{
public:
  ILxRenderCacheServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_RenderCacheService() {_init();set();}
 ~CLxLoc_RenderCacheService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxRenderCacheServiceID>(lx::GetGlobal(&lx::guid_RenderCacheService));}
    LxResult
  CreateRenderCache (void **ppvObj, unsigned int createFlags)
  {
    return m_loc[0]->CreateRenderCache (m_loc,ppvObj,createFlags);
  }
    CLxResult
  CreateRenderCache (CLxLocalizedObject &o_dest, unsigned int createFlags)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateRenderCache(m_loc,&o_obj,createFlags);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};


class CLxLoc_RenderCache : public CLxLocalize<ILxRenderCacheID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_RenderCache() {_init();}
  CLxLoc_RenderCache(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_RenderCache(const CLxLoc_RenderCache &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_RenderCache;}
    void
  Time (double *time, double *timeOffsets)
  {
    m_loc[0]->Time (m_loc,time,timeOffsets);
  }
    LxResult
  Update (double time, int force)
  {
    return m_loc[0]->Update (m_loc,time,force);
  }
    void
  Clear (void)
  {
    m_loc[0]->Clear (m_loc);
  }
    LxResult
  GeoSurfaceCount (int *count)
  {
    return m_loc[0]->GeoSurfaceCount (m_loc,count);
  }
    LxResult
  GeoSurfaceAt (int index, void **srf)
  {
    return m_loc[0]->GeoSurfaceAt (m_loc,index,srf);
  }
};

class CLxImpl_RenderCacheListener {
  public:
    virtual ~CLxImpl_RenderCacheListener() {}
    virtual void
      rli_RenderCacheDestroy (void)
        { }
    virtual void
      rli_UpdateBegin (void)
        { }
    virtual void
      rli_UpdateEnd (void)
        { }
    virtual void
      rli_GeoCacheSurfaceAdd (ILxUnknownID geoSrf)
        { }
    virtual void
      rli_GeoCacheSurfaceRemove (ILxUnknownID geoSrf)
        { }
    virtual void
      rli_GeoCacheSurfaceGeoUpdate (ILxUnknownID geoSrf)
        { }
    virtual void
      rli_GeoCacheSurfaceXformUpdate (ILxUnknownID geoSrf)
        { }
    virtual void
      rli_GeoCacheSurfaceShaderUpdate (ILxUnknownID geoSrf)
        { }
    virtual void
      rli_RenderCacheClear (void)
        { }
};
#define LXxD_RenderCacheListener_RenderCacheDestroy void rli_RenderCacheDestroy (void)
#define LXxO_RenderCacheListener_RenderCacheDestroy LXxD_RenderCacheListener_RenderCacheDestroy LXx_OVERRIDE
#define LXxC_RenderCacheListener_RenderCacheDestroy(c) void c::rli_RenderCacheDestroy (void)
#define LXxD_RenderCacheListener_UpdateBegin void rli_UpdateBegin (void)
#define LXxO_RenderCacheListener_UpdateBegin LXxD_RenderCacheListener_UpdateBegin LXx_OVERRIDE
#define LXxC_RenderCacheListener_UpdateBegin(c) void c::rli_UpdateBegin (void)
#define LXxD_RenderCacheListener_UpdateEnd void rli_UpdateEnd (void)
#define LXxO_RenderCacheListener_UpdateEnd LXxD_RenderCacheListener_UpdateEnd LXx_OVERRIDE
#define LXxC_RenderCacheListener_UpdateEnd(c) void c::rli_UpdateEnd (void)
#define LXxD_RenderCacheListener_GeoCacheSurfaceAdd void rli_GeoCacheSurfaceAdd (ILxUnknownID geoSrf)
#define LXxO_RenderCacheListener_GeoCacheSurfaceAdd LXxD_RenderCacheListener_GeoCacheSurfaceAdd LXx_OVERRIDE
#define LXxC_RenderCacheListener_GeoCacheSurfaceAdd(c) void c::rli_GeoCacheSurfaceAdd (ILxUnknownID geoSrf)
#define LXxD_RenderCacheListener_GeoCacheSurfaceRemove void rli_GeoCacheSurfaceRemove (ILxUnknownID geoSrf)
#define LXxO_RenderCacheListener_GeoCacheSurfaceRemove LXxD_RenderCacheListener_GeoCacheSurfaceRemove LXx_OVERRIDE
#define LXxC_RenderCacheListener_GeoCacheSurfaceRemove(c) void c::rli_GeoCacheSurfaceRemove (ILxUnknownID geoSrf)
#define LXxD_RenderCacheListener_GeoCacheSurfaceGeoUpdate void rli_GeoCacheSurfaceGeoUpdate (ILxUnknownID geoSrf)
#define LXxO_RenderCacheListener_GeoCacheSurfaceGeoUpdate LXxD_RenderCacheListener_GeoCacheSurfaceGeoUpdate LXx_OVERRIDE
#define LXxC_RenderCacheListener_GeoCacheSurfaceGeoUpdate(c) void c::rli_GeoCacheSurfaceGeoUpdate (ILxUnknownID geoSrf)
#define LXxD_RenderCacheListener_GeoCacheSurfaceXformUpdate void rli_GeoCacheSurfaceXformUpdate (ILxUnknownID geoSrf)
#define LXxO_RenderCacheListener_GeoCacheSurfaceXformUpdate LXxD_RenderCacheListener_GeoCacheSurfaceXformUpdate LXx_OVERRIDE
#define LXxC_RenderCacheListener_GeoCacheSurfaceXformUpdate(c) void c::rli_GeoCacheSurfaceXformUpdate (ILxUnknownID geoSrf)
#define LXxD_RenderCacheListener_GeoCacheSurfaceShaderUpdate void rli_GeoCacheSurfaceShaderUpdate (ILxUnknownID geoSrf)
#define LXxO_RenderCacheListener_GeoCacheSurfaceShaderUpdate LXxD_RenderCacheListener_GeoCacheSurfaceShaderUpdate LXx_OVERRIDE
#define LXxC_RenderCacheListener_GeoCacheSurfaceShaderUpdate(c) void c::rli_GeoCacheSurfaceShaderUpdate (ILxUnknownID geoSrf)
#define LXxD_RenderCacheListener_RenderCacheClear void rli_RenderCacheClear (void)
#define LXxO_RenderCacheListener_RenderCacheClear LXxD_RenderCacheListener_RenderCacheClear LXx_OVERRIDE
#define LXxC_RenderCacheListener_RenderCacheClear(c) void c::rli_RenderCacheClear (void)
template <class T>
class CLxIfc_RenderCacheListener : public CLxInterface
{
    static void
  RenderCacheDestroy (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_RenderCacheListener, loc);
    loc->rli_RenderCacheDestroy ();
  }
    static void
  UpdateBegin (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_RenderCacheListener, loc);
    loc->rli_UpdateBegin ();
  }
    static void
  UpdateEnd (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_RenderCacheListener, loc);
    loc->rli_UpdateEnd ();
  }
    static void
  GeoCacheSurfaceAdd (LXtObjectID wcom, LXtObjectID geoSrf)
  {
    LXCWxINST (CLxImpl_RenderCacheListener, loc);
    loc->rli_GeoCacheSurfaceAdd ((ILxUnknownID)geoSrf);
  }
    static void
  GeoCacheSurfaceRemove (LXtObjectID wcom, LXtObjectID geoSrf)
  {
    LXCWxINST (CLxImpl_RenderCacheListener, loc);
    loc->rli_GeoCacheSurfaceRemove ((ILxUnknownID)geoSrf);
  }
    static void
  GeoCacheSurfaceGeoUpdate (LXtObjectID wcom, LXtObjectID geoSrf)
  {
    LXCWxINST (CLxImpl_RenderCacheListener, loc);
    loc->rli_GeoCacheSurfaceGeoUpdate ((ILxUnknownID)geoSrf);
  }
    static void
  GeoCacheSurfaceXformUpdate (LXtObjectID wcom, LXtObjectID geoSrf)
  {
    LXCWxINST (CLxImpl_RenderCacheListener, loc);
    loc->rli_GeoCacheSurfaceXformUpdate ((ILxUnknownID)geoSrf);
  }
    static void
  GeoCacheSurfaceShaderUpdate (LXtObjectID wcom, LXtObjectID geoSrf)
  {
    LXCWxINST (CLxImpl_RenderCacheListener, loc);
    loc->rli_GeoCacheSurfaceShaderUpdate ((ILxUnknownID)geoSrf);
  }
    static void
  RenderCacheClear (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_RenderCacheListener, loc);
    loc->rli_RenderCacheClear ();
  }
  ILxRenderCacheListener vt;
public:
  CLxIfc_RenderCacheListener ()
  {
    vt.RenderCacheDestroy = RenderCacheDestroy;
    vt.UpdateBegin = UpdateBegin;
    vt.UpdateEnd = UpdateEnd;
    vt.GeoCacheSurfaceAdd = GeoCacheSurfaceAdd;
    vt.GeoCacheSurfaceRemove = GeoCacheSurfaceRemove;
    vt.GeoCacheSurfaceGeoUpdate = GeoCacheSurfaceGeoUpdate;
    vt.GeoCacheSurfaceXformUpdate = GeoCacheSurfaceXformUpdate;
    vt.GeoCacheSurfaceShaderUpdate = GeoCacheSurfaceShaderUpdate;
    vt.RenderCacheClear = RenderCacheClear;
    vTable = &vt.iunk;
    iid = &lx::guid_RenderCacheListener;
  }
};

#endif

