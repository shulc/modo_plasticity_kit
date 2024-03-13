/*
 * C++ wrapper for lximage.h
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
#ifndef LXW_IMAGE_HPP
#define LXW_IMAGE_HPP

#include <lximage.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ImageService = {0x03A7D258,0x397C,0x4D92,0xB3,0xAF,0x69,0x5A,0xD6,0x76,0xFC,0xF9};
    static const LXtGUID guid_ImageBlockCodec = {0x7960B5BA,0x70D3,0x4FAD,0x8C,0xA1,0xBD,0x30,0xA7,0x93,0x85,0x54};
    static const LXtGUID guid_LayeredImageWrite = {0x79D28886,0x9652,0x4A76,0x9A,0xA7,0x1B,0x1E,0x4D,0x55,0x3D,0xCD};
    static const LXtGUID guid_TileImage = {0xBD12D6C3,0xC08F,0x4AD1,0xA0,0x80,0x39,0x9F,0x95,0x8D,0x28,0xC0};
    static const LXtGUID guid_ImageFilterSample = {0x9EC74AED,0xF86F,0x4105,0xAC,0xE9,0x7B,0xDA,0xA6,0x29,0x87,0x36};
    static const LXtGUID guid_ImageFilter = {0xFB00C87C,0x5A34,0x4B45,0xB0,0xE8,0x99,0x89,0x26,0xC7,0x9D,0xC4};
    static const LXtGUID guid_LayeredImage = {0x8523ECC4,0xB8B3,0x4C6E,0x8F,0x14,0xA1,0xD2,0xD0,0x1E,0x80,0x38};
    static const LXtGUID guid_ImageSegment = {0x370ABB2F,0x119E,0x4EEC,0x98,0xF8,0x03,0x38,0x8A,0xBE,0x7D,0x2C};
    static const LXtGUID guid_ImageWrite = {0x8F9CF293,0xB6F9,0x498e,0xA1,0x24,0x67,0x04,0xE2,0xC2,0x46,0x62};
    static const LXtGUID guid_Image = {0x469AFBB8,0xE6A2,0x4d88,0x9C,0x39,0x54,0x30,0xCA,0x72,0xE4,0x04};
    static const LXtGUID guid_IndexImageWrite = {0xD59C5E09,0x779E,0x445b,0xB3,0x17,0x28,0x26,0x30,0xCB,0x6B,0xD5};
    static const LXtGUID guid_ImageFilterMetrics = {0x8F7A47EB,0x5812,0x47F4,0x91,0xF5,0x21,0x95,0xB0,0x53,0xF9,0x7D};
    static const LXtGUID guid_ImageLevelSample = {0x79A6EA0E,0x9589,0x4D03,0x88,0x0C,0xC0,0x6A,0x6E,0xC6,0xCF,0x7D};
    static const LXtGUID guid_ImageLoaderTarget = {0x1034861C,0x78C4,0x4BEC,0x95,0x88,0xF1,0xD3,0xC0,0xB0,0x40,0x1A};
    static const LXtGUID guid_ImageFilterMetrics1 = {0x0D2CA8D8,0x66A9,0x45A0,0xAA,0xE6,0x83,0x64,0xD9,0x03,0xAF,0xDA};
    static const LXtGUID guid_ImageLoaderTarget1 = {0x9F124A7B,0xDFC7,0x42E6,0x97,0x7B,0x71,0xAE,0x2E,0x33,0xB0,0x17};
    static const LXtGUID guid_Movie = {0xB7BD9F49,0x9400,0x45F1,0xAD,0xEE,0xBF,0xE8,0x2A,0x1C,0x4A,0x65};
    static const LXtGUID guid_IndexImage = {0x08CAE3BC,0xED69,0x4EC4,0x9D,0x7D,0xBB,0xDB,0xE4,0xE3,0x53,0x43};
};

class CLxLoc_ImageService : public CLxLocalizedService
{
public:
  ILxImageServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_ImageService() {_init();set();}
 ~CLxLoc_ImageService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxImageServiceID>(lx::GetGlobal(&lx::guid_ImageService));}
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
  Create (unsigned int width, unsigned int height, LXtPixelFormat type, unsigned int maxIndex, void **ppvObj)
  {
    return m_loc[0]->Create (m_loc,width,height,type,maxIndex,ppvObj);
  }
    CLxResult
  Create (unsigned int width, unsigned int height, LXtPixelFormat type, unsigned int maxIndex, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Create(m_loc,width,height,type,maxIndex,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Duplicate (ILxUnknownID source, LXtPixelFormat type, void **ppvObj)
  {
    return m_loc[0]->Duplicate (m_loc,(ILxUnknownID)source,type,ppvObj);
  }
    CLxResult
  Duplicate (ILxUnknownID source, LXtPixelFormat type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Duplicate(m_loc,(ILxUnknownID)source,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Load (const char *filePath, void **ppvObj)
  {
    return m_loc[0]->Load (m_loc,filePath,ppvObj);
  }
    CLxResult
  Load (const char *filePath, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Load(m_loc,filePath,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Save (ILxUnknownID image, const char *filePath, const char *format, ILxUnknownID monitor)
  {
    return m_loc[0]->Save (m_loc,(ILxUnknownID)image,filePath,format,(ILxUnknownID)monitor);
  }
    LxResult
  Resample (ILxUnknownID dest, ILxUnknownID source, LXtProcessHint hint)
  {
    return m_loc[0]->Resample (m_loc,(ILxUnknownID)dest,(ILxUnknownID)source,hint);
  }
    LxResult
  Composite (ILxUnknownID dest, ILxUnknownID source, const LXtFVector2 pos)
  {
    return m_loc[0]->Composite (m_loc,(ILxUnknownID)dest,(ILxUnknownID)source,pos);
  }
    LxResult
  DrawLine (ILxUnknownID image, const LXtFVector2 p0, const LXtFVector2 p1, const LXtFVector color)
  {
    return m_loc[0]->DrawLine (m_loc,(ILxUnknownID)image,p0,p1,color);
  }
    LxResult
  Kelvin2RGB (float kelvin, LXtFVector rgbColor)
  {
    return m_loc[0]->Kelvin2RGB (m_loc,kelvin,rgbColor);
  }
    LxResult
  RGB2Kelvin (const LXtFVector rgbColor, float *kelvin)
  {
    return m_loc[0]->RGB2Kelvin (m_loc,rgbColor,kelvin);
  }
    LxResult
  CreateCrop (ILxUnknownID sourceImage, double x, double y, double w, double h, void **ppvObj)
  {
    return m_loc[0]->CreateCrop (m_loc,(ILxUnknownID)sourceImage,x,y,w,h,ppvObj);
  }
    CLxResult
  CreateCrop (ILxUnknownID sourceImage, double x, double y, double w, double h, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateCrop(m_loc,(ILxUnknownID)sourceImage,x,y,w,h,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ImageGetBuffer (ILxUnknownID sourceImage, LXtPixelFormat type, void *buf)
  {
    return m_loc[0]->ImageGetBuffer (m_loc,(ILxUnknownID)sourceImage,type,buf);
  }
    LxResult
  LoadNoCache (const char *filePath, void **ppvObj)
  {
    return m_loc[0]->LoadNoCache (m_loc,filePath,ppvObj);
  }
    CLxResult
  LoadNoCache (const char *filePath, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->LoadNoCache(m_loc,filePath,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CreateLayered (unsigned int width, unsigned int height, unsigned int layerNum, void **ppvObj)
  {
    return m_loc[0]->CreateLayered (m_loc,width,height,layerNum,ppvObj);
  }
    CLxResult
  CreateLayered (unsigned int width, unsigned int height, unsigned int layerNum, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateLayered(m_loc,width,height,layerNum,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SaveLayered (ILxUnknownID layeredImage, const char *filePath, const char *format, ILxUnknownID monitor)
  {
    return m_loc[0]->SaveLayered (m_loc,(ILxUnknownID)layeredImage,filePath,format,(ILxUnknownID)monitor);
  }
};

class CLxImpl_ImageBlockCodec {
  public:
    virtual ~CLxImpl_ImageBlockCodec() {}
    virtual LxResult
      ibc_Compress (ILxUnknownID image, unsigned char **buf, int *size)
        { return LXe_NOTIMPL; }
    virtual void
      ibc_Free (unsigned char *buf, int size)
        { }
    virtual LxResult
      ibc_Decompress (unsigned char *buf, int size, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_ImageBlockCodec_Compress LxResult ibc_Compress (ILxUnknownID image, unsigned char **buf, int *size)
#define LXxO_ImageBlockCodec_Compress LXxD_ImageBlockCodec_Compress LXx_OVERRIDE
#define LXxC_ImageBlockCodec_Compress(c) LxResult c::ibc_Compress (ILxUnknownID image, unsigned char **buf, int *size)
#define LXxD_ImageBlockCodec_Free void ibc_Free (unsigned char *buf, int size)
#define LXxO_ImageBlockCodec_Free LXxD_ImageBlockCodec_Free LXx_OVERRIDE
#define LXxC_ImageBlockCodec_Free(c) void c::ibc_Free (unsigned char *buf, int size)
#define LXxD_ImageBlockCodec_Decompress LxResult ibc_Decompress (unsigned char *buf, int size, void **ppvObj)
#define LXxO_ImageBlockCodec_Decompress LXxD_ImageBlockCodec_Decompress LXx_OVERRIDE
#define LXxC_ImageBlockCodec_Decompress(c) LxResult c::ibc_Decompress (unsigned char *buf, int size, void **ppvObj)
template <class T>
class CLxIfc_ImageBlockCodec : public CLxInterface
{
    static LxResult
  Compress (LXtObjectID wcom, LXtObjectID image, unsigned char **buf, int *size)
  {
    LXCWxINST (CLxImpl_ImageBlockCodec, loc);
    try {
      return loc->ibc_Compress ((ILxUnknownID)image,buf,size);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Free (LXtObjectID wcom, unsigned char *buf, int size)
  {
    LXCWxINST (CLxImpl_ImageBlockCodec, loc);
    loc->ibc_Free (buf,size);
  }
    static LxResult
  Decompress (LXtObjectID wcom, unsigned char *buf, int size, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ImageBlockCodec, loc);
    try {
      return loc->ibc_Decompress (buf,size,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxImageBlockCodec vt;
public:
  CLxIfc_ImageBlockCodec ()
  {
    vt.Compress = Compress;
    vt.Free = Free;
    vt.Decompress = Decompress;
    vTable = &vt.iunk;
    iid = &lx::guid_ImageBlockCodec;
  }
};

class CLxImpl_LayeredImageWrite {
  public:
    virtual ~CLxImpl_LayeredImageWrite() {}
    virtual LxResult
      limgw_AddLayer (ILxUnknownID image, const char *name, const char **channelNames)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limgw_SetType (unsigned int index, int flags, const char *type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limgw_SetOffset (unsigned int index, int x, int y)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limgw_SetBlending (unsigned int index, float blend, const char *mode)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limgw_AddAttribute (const char *name, const char *type, int *index)
        { return LXe_NOTIMPL; }
};
#define LXxD_LayeredImageWrite_AddLayer LxResult limgw_AddLayer (ILxUnknownID image, const char *name, const char **channelNames)
#define LXxO_LayeredImageWrite_AddLayer LXxD_LayeredImageWrite_AddLayer LXx_OVERRIDE
#define LXxC_LayeredImageWrite_AddLayer(c) LxResult c::limgw_AddLayer (ILxUnknownID image, const char *name, const char **channelNames)
#define LXxD_LayeredImageWrite_SetType LxResult limgw_SetType (unsigned int index, int flags, const char *type)
#define LXxO_LayeredImageWrite_SetType LXxD_LayeredImageWrite_SetType LXx_OVERRIDE
#define LXxC_LayeredImageWrite_SetType(c) LxResult c::limgw_SetType (unsigned int index, int flags, const char *type)
#define LXxD_LayeredImageWrite_SetOffset LxResult limgw_SetOffset (unsigned int index, int x, int y)
#define LXxO_LayeredImageWrite_SetOffset LXxD_LayeredImageWrite_SetOffset LXx_OVERRIDE
#define LXxC_LayeredImageWrite_SetOffset(c) LxResult c::limgw_SetOffset (unsigned int index, int x, int y)
#define LXxD_LayeredImageWrite_SetBlending LxResult limgw_SetBlending (unsigned int index, float blend, const char *mode)
#define LXxO_LayeredImageWrite_SetBlending LXxD_LayeredImageWrite_SetBlending LXx_OVERRIDE
#define LXxC_LayeredImageWrite_SetBlending(c) LxResult c::limgw_SetBlending (unsigned int index, float blend, const char *mode)
#define LXxD_LayeredImageWrite_AddAttribute LxResult limgw_AddAttribute (const char *name, const char *type, int *index)
#define LXxO_LayeredImageWrite_AddAttribute LXxD_LayeredImageWrite_AddAttribute LXx_OVERRIDE
#define LXxC_LayeredImageWrite_AddAttribute(c) LxResult c::limgw_AddAttribute (const char *name, const char *type, int *index)
template <class T>
class CLxIfc_LayeredImageWrite : public CLxInterface
{
    static LxResult
  AddLayer (LXtObjectID wcom, LXtObjectID image, const char *name, const char **channelNames)
  {
    LXCWxINST (CLxImpl_LayeredImageWrite, loc);
    try {
      return loc->limgw_AddLayer ((ILxUnknownID)image,name,channelNames);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetType (LXtObjectID wcom, unsigned int index, int flags, const char *type)
  {
    LXCWxINST (CLxImpl_LayeredImageWrite, loc);
    try {
      return loc->limgw_SetType (index,flags,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetOffset (LXtObjectID wcom, unsigned int index, int x, int y)
  {
    LXCWxINST (CLxImpl_LayeredImageWrite, loc);
    try {
      return loc->limgw_SetOffset (index,x,y);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetBlending (LXtObjectID wcom, unsigned int index, float blend, const char *mode)
  {
    LXCWxINST (CLxImpl_LayeredImageWrite, loc);
    try {
      return loc->limgw_SetBlending (index,blend,mode);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddAttribute (LXtObjectID wcom, const char *name, const char *type, int *index)
  {
    LXCWxINST (CLxImpl_LayeredImageWrite, loc);
    try {
      return loc->limgw_AddAttribute (name,type,index);
    } catch (LxResult rc) { return rc; }
  }
  ILxLayeredImageWrite vt;
public:
  CLxIfc_LayeredImageWrite ()
  {
    vt.AddLayer = AddLayer;
    vt.SetType = SetType;
    vt.SetOffset = SetOffset;
    vt.SetBlending = SetBlending;
    vt.AddAttribute = AddAttribute;
    vTable = &vt.iunk;
    iid = &lx::guid_LayeredImageWrite;
  }
};
class CLxLoc_LayeredImageWrite : public CLxLocalize<ILxLayeredImageWriteID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LayeredImageWrite() {_init();}
  CLxLoc_LayeredImageWrite(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LayeredImageWrite(const CLxLoc_LayeredImageWrite &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LayeredImageWrite;}
    LxResult
  AddLayer (ILxUnknownID image, const char *name, const char **channelNames)
  {
    return m_loc[0]->AddLayer (m_loc,(ILxUnknownID)image,name,channelNames);
  }
    LxResult
  SetType (unsigned int index, int flags, const char *type)
  {
    return m_loc[0]->SetType (m_loc,index,flags,type);
  }
    LxResult
  SetOffset (unsigned int index, int x, int y)
  {
    return m_loc[0]->SetOffset (m_loc,index,x,y);
  }
    LxResult
  SetBlending (unsigned int index, float blend, const char *mode)
  {
    return m_loc[0]->SetBlending (m_loc,index,blend,mode);
  }
    LxResult
  AddAttribute (const char *name, const char *type, int *index)
  {
    return m_loc[0]->AddAttribute (m_loc,name,type,index);
  }
};

class CLxImpl_TileImage {
  public:
    virtual ~CLxImpl_TileImage() {}
    virtual unsigned
      tileimg_LevelCount (void)
        = 0;
    virtual LxResult
      tileimg_GetTile (unsigned int level, unsigned int tileX, unsigned int tileY, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tileimg_GetTileSize (unsigned int level, unsigned int tileX, unsigned int tileY, unsigned int *width, unsigned int *height)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tileimg_GetLevelSize (unsigned int level, unsigned int *width, unsigned int *height, unsigned int *tilesWidth, unsigned int *tilesHeight)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tileimg_DetermineTile (unsigned int level, unsigned int x, unsigned int y, unsigned int *tileX, unsigned int *tileY)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tileimg_DeterminePixel (unsigned int level, unsigned int x, unsigned int y, unsigned int *adjX, unsigned int *adjY)
        { return LXe_NOTIMPL; }
};
#define LXxD_TileImage_LevelCount unsigned tileimg_LevelCount (void)
#define LXxO_TileImage_LevelCount LXxD_TileImage_LevelCount LXx_OVERRIDE
#define LXxC_TileImage_LevelCount(c) unsigned c::tileimg_LevelCount (void)
#define LXxD_TileImage_GetTile LxResult tileimg_GetTile (unsigned int level, unsigned int tileX, unsigned int tileY, void **ppvObj)
#define LXxO_TileImage_GetTile LXxD_TileImage_GetTile LXx_OVERRIDE
#define LXxC_TileImage_GetTile(c) LxResult c::tileimg_GetTile (unsigned int level, unsigned int tileX, unsigned int tileY, void **ppvObj)
#define LXxD_TileImage_GetTileSize LxResult tileimg_GetTileSize (unsigned int level, unsigned int tileX, unsigned int tileY, unsigned int *width, unsigned int *height)
#define LXxO_TileImage_GetTileSize LXxD_TileImage_GetTileSize LXx_OVERRIDE
#define LXxC_TileImage_GetTileSize(c) LxResult c::tileimg_GetTileSize (unsigned int level, unsigned int tileX, unsigned int tileY, unsigned int *width, unsigned int *height)
#define LXxD_TileImage_GetLevelSize LxResult tileimg_GetLevelSize (unsigned int level, unsigned int *width, unsigned int *height, unsigned int *tilesWidth, unsigned int *tilesHeight)
#define LXxO_TileImage_GetLevelSize LXxD_TileImage_GetLevelSize LXx_OVERRIDE
#define LXxC_TileImage_GetLevelSize(c) LxResult c::tileimg_GetLevelSize (unsigned int level, unsigned int *width, unsigned int *height, unsigned int *tilesWidth, unsigned int *tilesHeight)
#define LXxD_TileImage_DetermineTile LxResult tileimg_DetermineTile (unsigned int level, unsigned int x, unsigned int y, unsigned int *tileX, unsigned int *tileY)
#define LXxO_TileImage_DetermineTile LXxD_TileImage_DetermineTile LXx_OVERRIDE
#define LXxC_TileImage_DetermineTile(c) LxResult c::tileimg_DetermineTile (unsigned int level, unsigned int x, unsigned int y, unsigned int *tileX, unsigned int *tileY)
#define LXxD_TileImage_DeterminePixel LxResult tileimg_DeterminePixel (unsigned int level, unsigned int x, unsigned int y, unsigned int *adjX, unsigned int *adjY)
#define LXxO_TileImage_DeterminePixel LXxD_TileImage_DeterminePixel LXx_OVERRIDE
#define LXxC_TileImage_DeterminePixel(c) LxResult c::tileimg_DeterminePixel (unsigned int level, unsigned int x, unsigned int y, unsigned int *adjX, unsigned int *adjY)
template <class T>
class CLxIfc_TileImage : public CLxInterface
{
    static unsigned
  LevelCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TileImage, loc);
    return loc->tileimg_LevelCount ();
  }
    static LxResult
  GetTile (LXtObjectID wcom, unsigned int level, unsigned int tileX, unsigned int tileY, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TileImage, loc);
    try {
      return loc->tileimg_GetTile (level,tileX,tileY,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetTileSize (LXtObjectID wcom, unsigned int level, unsigned int tileX, unsigned int tileY, unsigned int *width, unsigned int *height)
  {
    LXCWxINST (CLxImpl_TileImage, loc);
    try {
      return loc->tileimg_GetTileSize (level,tileX,tileY,width,height);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetLevelSize (LXtObjectID wcom, unsigned int level, unsigned int *width, unsigned int *height, unsigned int *tilesWidth, unsigned int *tilesHeight)
  {
    LXCWxINST (CLxImpl_TileImage, loc);
    try {
      return loc->tileimg_GetLevelSize (level,width,height,tilesWidth,tilesHeight);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DetermineTile (LXtObjectID wcom, unsigned int level, unsigned int x, unsigned int y, unsigned int *tileX, unsigned int *tileY)
  {
    LXCWxINST (CLxImpl_TileImage, loc);
    try {
      return loc->tileimg_DetermineTile (level,x,y,tileX,tileY);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DeterminePixel (LXtObjectID wcom, unsigned int level, unsigned int x, unsigned int y, unsigned int *adjX, unsigned int *adjY)
  {
    LXCWxINST (CLxImpl_TileImage, loc);
    try {
      return loc->tileimg_DeterminePixel (level,x,y,adjX,adjY);
    } catch (LxResult rc) { return rc; }
  }
  ILxTileImage vt;
public:
  CLxIfc_TileImage ()
  {
    vt.LevelCount = LevelCount;
    vt.GetTile = GetTile;
    vt.GetTileSize = GetTileSize;
    vt.GetLevelSize = GetLevelSize;
    vt.DetermineTile = DetermineTile;
    vt.DeterminePixel = DeterminePixel;
    vTable = &vt.iunk;
    iid = &lx::guid_TileImage;
  }
};
class CLxLoc_TileImage : public CLxLocalize<ILxTileImageID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TileImage() {_init();}
  CLxLoc_TileImage(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TileImage(const CLxLoc_TileImage &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TileImage;}
    unsigned
  LevelCount (void) const
  {
    return m_loc[0]->LevelCount (m_loc);
  }
    LxResult
  GetTile (unsigned int level, unsigned int tileX, unsigned int tileY, void **ppvObj) const
  {
    return m_loc[0]->GetTile (m_loc,level,tileX,tileY,ppvObj);
  }
    CLxResult
  GetTile (unsigned int level, unsigned int tileX, unsigned int tileY, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetTile(m_loc,level,tileX,tileY,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetTileSize (unsigned int level, unsigned int tileX, unsigned int tileY, unsigned int *width, unsigned int *height) const
  {
    return m_loc[0]->GetTileSize (m_loc,level,tileX,tileY,width,height);
  }
    LxResult
  GetLevelSize (unsigned int level, unsigned int *width, unsigned int *height, unsigned int *tilesWidth, unsigned int *tilesHeight) const
  {
    return m_loc[0]->GetLevelSize (m_loc,level,width,height,tilesWidth,tilesHeight);
  }
    LxResult
  DetermineTile (unsigned int level, unsigned int x, unsigned int y, unsigned int *tileX, unsigned int *tileY) const
  {
    return m_loc[0]->DetermineTile (m_loc,level,x,y,tileX,tileY);
  }
    LxResult
  DeterminePixel (unsigned int level, unsigned int x, unsigned int y, unsigned int *adjX, unsigned int *adjY) const
  {
    return m_loc[0]->DeterminePixel (m_loc,level,x,y,adjX,adjY);
  }
};


class CLxImpl_ImageFilter {
  public:
    virtual ~CLxImpl_ImageFilter() {}
    virtual unsigned int
      imf_Type (void)
        = 0;
    virtual LxResult
      imf_Generate (int width, int height, ILxUnknownID monitor, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imf_MultiSample (ILxUnknownID monitor, ILxUnknownID image, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imf_SingleSample (const LXtColorRGBA src, LXtColorRGBA dest)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imf_SingleSampleN (const LXtImageFloat *src, LXtImageFloat *dest, unsigned num)
        { return LXe_NOTIMPL; }
};
#define LXxD_ImageFilter_Type unsigned int imf_Type (void)
#define LXxO_ImageFilter_Type LXxD_ImageFilter_Type LXx_OVERRIDE
#define LXxC_ImageFilter_Type(c) unsigned int c::imf_Type (void)
#define LXxD_ImageFilter_Generate LxResult imf_Generate (int width, int height, ILxUnknownID monitor, void **ppvObj)
#define LXxO_ImageFilter_Generate LXxD_ImageFilter_Generate LXx_OVERRIDE
#define LXxC_ImageFilter_Generate(c) LxResult c::imf_Generate (int width, int height, ILxUnknownID monitor, void **ppvObj)
#define LXxD_ImageFilter_MultiSample LxResult imf_MultiSample (ILxUnknownID monitor, ILxUnknownID image, void **ppvObj)
#define LXxO_ImageFilter_MultiSample LXxD_ImageFilter_MultiSample LXx_OVERRIDE
#define LXxC_ImageFilter_MultiSample(c) LxResult c::imf_MultiSample (ILxUnknownID monitor, ILxUnknownID image, void **ppvObj)
#define LXxD_ImageFilter_SingleSample LxResult imf_SingleSample (const LXtColorRGBA src, LXtColorRGBA dest)
#define LXxO_ImageFilter_SingleSample LXxD_ImageFilter_SingleSample LXx_OVERRIDE
#define LXxC_ImageFilter_SingleSample(c) LxResult c::imf_SingleSample (const LXtColorRGBA src, LXtColorRGBA dest)
#define LXxD_ImageFilter_SingleSampleN LxResult imf_SingleSampleN (const LXtImageFloat *src, LXtImageFloat *dest, unsigned num)
#define LXxO_ImageFilter_SingleSampleN LXxD_ImageFilter_SingleSampleN LXx_OVERRIDE
#define LXxC_ImageFilter_SingleSampleN(c) LxResult c::imf_SingleSampleN (const LXtImageFloat *src, LXtImageFloat *dest, unsigned num)
template <class T>
class CLxIfc_ImageFilter : public CLxInterface
{
    static unsigned int
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ImageFilter, loc);
    return loc->imf_Type ();
  }
    static LxResult
  Generate (LXtObjectID wcom, int width, int height, LXtObjectID monitor, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ImageFilter, loc);
    try {
      return loc->imf_Generate (width,height,(ILxUnknownID)monitor,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  MultiSample (LXtObjectID wcom, LXtObjectID monitor, LXtObjectID image, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ImageFilter, loc);
    try {
      return loc->imf_MultiSample ((ILxUnknownID)monitor,(ILxUnknownID)image,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SingleSample (LXtObjectID wcom, const LXtColorRGBA src, LXtColorRGBA dest)
  {
    LXCWxINST (CLxImpl_ImageFilter, loc);
    try {
      return loc->imf_SingleSample (src,dest);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SingleSampleN (LXtObjectID wcom, const LXtImageFloat *src, LXtImageFloat *dest, unsigned num)
  {
    LXCWxINST (CLxImpl_ImageFilter, loc);
    try {
      return loc->imf_SingleSampleN (src,dest,num);
    } catch (LxResult rc) { return rc; }
  }
  ILxImageFilter vt;
public:
  CLxIfc_ImageFilter ()
  {
    vt.Type = Type;
    vt.Generate = Generate;
    vt.MultiSample = MultiSample;
    vt.SingleSample = SingleSample;
    vt.SingleSampleN = SingleSampleN;
    vTable = &vt.iunk;
    iid = &lx::guid_ImageFilter;
  }
};
class CLxLoc_ImageFilter : public CLxLocalize<ILxImageFilterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageFilter() {_init();}
  CLxLoc_ImageFilter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageFilter(const CLxLoc_ImageFilter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageFilter;}
    unsigned int
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  Generate (int width, int height, ILxUnknownID monitor, void **ppvObj)
  {
    return m_loc[0]->Generate (m_loc,width,height,(ILxUnknownID)monitor,ppvObj);
  }
    CLxResult
  Generate (int width, int height, ILxUnknownID monitor, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Generate(m_loc,width,height,(ILxUnknownID)monitor,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  MultiSample (ILxUnknownID monitor, ILxUnknownID image, void **ppvObj)
  {
    return m_loc[0]->MultiSample (m_loc,(ILxUnknownID)monitor,(ILxUnknownID)image,ppvObj);
  }
    CLxResult
  MultiSample (ILxUnknownID monitor, ILxUnknownID image, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->MultiSample(m_loc,(ILxUnknownID)monitor,(ILxUnknownID)image,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SingleSample (const LXtColorRGBA src, LXtColorRGBA dest)
  {
    return m_loc[0]->SingleSample (m_loc,src,dest);
  }
    LxResult
  SingleSampleN (const LXtImageFloat *src, LXtImageFloat *dest, unsigned num)
  {
    return m_loc[0]->SingleSampleN (m_loc,src,dest,num);
  }
};

class CLxImpl_LayeredImage {
  public:
    virtual ~CLxImpl_LayeredImage() {}
    virtual LxResult
      limg_Size (unsigned int *w, unsigned int *h)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      limg_Count (void)
        = 0;
    virtual LxResult
      limg_Image (unsigned int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limg_Name (unsigned int index, const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limg_Type (unsigned int index, unsigned int *flags, const char **type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limg_Offset (unsigned int index, int *x, int *y)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limg_Blend (unsigned int index, float *opacity, unsigned int *mode)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limg_ChannelName (unsigned layerIndex, unsigned channelIndex, const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limg_Parent (unsigned layerIndex, int *parentIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      limg_IsGroup (unsigned layerIndex, unsigned int *isGroup)
        { return LXe_NOTIMPL; }
};
#define LXxD_LayeredImage_Size LxResult limg_Size (unsigned int *w, unsigned int *h)
#define LXxO_LayeredImage_Size LXxD_LayeredImage_Size LXx_OVERRIDE
#define LXxC_LayeredImage_Size(c) LxResult c::limg_Size (unsigned int *w, unsigned int *h)
#define LXxD_LayeredImage_Count unsigned int limg_Count (void)
#define LXxO_LayeredImage_Count LXxD_LayeredImage_Count LXx_OVERRIDE
#define LXxC_LayeredImage_Count(c) unsigned int c::limg_Count (void)
#define LXxD_LayeredImage_Image LxResult limg_Image (unsigned int index, void **ppvObj)
#define LXxO_LayeredImage_Image LXxD_LayeredImage_Image LXx_OVERRIDE
#define LXxC_LayeredImage_Image(c) LxResult c::limg_Image (unsigned int index, void **ppvObj)
#define LXxD_LayeredImage_Name LxResult limg_Name (unsigned int index, const char **name)
#define LXxO_LayeredImage_Name LXxD_LayeredImage_Name LXx_OVERRIDE
#define LXxC_LayeredImage_Name(c) LxResult c::limg_Name (unsigned int index, const char **name)
#define LXxD_LayeredImage_Type LxResult limg_Type (unsigned int index, unsigned int *flags, const char **type)
#define LXxO_LayeredImage_Type LXxD_LayeredImage_Type LXx_OVERRIDE
#define LXxC_LayeredImage_Type(c) LxResult c::limg_Type (unsigned int index, unsigned int *flags, const char **type)
#define LXxD_LayeredImage_Offset LxResult limg_Offset (unsigned int index, int *x, int *y)
#define LXxO_LayeredImage_Offset LXxD_LayeredImage_Offset LXx_OVERRIDE
#define LXxC_LayeredImage_Offset(c) LxResult c::limg_Offset (unsigned int index, int *x, int *y)
#define LXxD_LayeredImage_Blend LxResult limg_Blend (unsigned int index, float *opacity, unsigned int *mode)
#define LXxO_LayeredImage_Blend LXxD_LayeredImage_Blend LXx_OVERRIDE
#define LXxC_LayeredImage_Blend(c) LxResult c::limg_Blend (unsigned int index, float *opacity, unsigned int *mode)
#define LXxD_LayeredImage_ChannelName LxResult limg_ChannelName (unsigned layerIndex, unsigned channelIndex, const char **name)
#define LXxO_LayeredImage_ChannelName LXxD_LayeredImage_ChannelName LXx_OVERRIDE
#define LXxC_LayeredImage_ChannelName(c) LxResult c::limg_ChannelName (unsigned layerIndex, unsigned channelIndex, const char **name)
#define LXxD_LayeredImage_Parent LxResult limg_Parent (unsigned layerIndex, int *parentIndex)
#define LXxO_LayeredImage_Parent LXxD_LayeredImage_Parent LXx_OVERRIDE
#define LXxC_LayeredImage_Parent(c) LxResult c::limg_Parent (unsigned layerIndex, int *parentIndex)
#define LXxD_LayeredImage_IsGroup LxResult limg_IsGroup (unsigned layerIndex, unsigned int *isGroup)
#define LXxO_LayeredImage_IsGroup LXxD_LayeredImage_IsGroup LXx_OVERRIDE
#define LXxC_LayeredImage_IsGroup(c) LxResult c::limg_IsGroup (unsigned layerIndex, unsigned int *isGroup)
template <class T>
class CLxIfc_LayeredImage : public CLxInterface
{
    static LxResult
  Size (LXtObjectID wcom, unsigned int *w, unsigned int *h)
  {
    LXCWxINST (CLxImpl_LayeredImage, loc);
    try {
      return loc->limg_Size (w,h);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_LayeredImage, loc);
    return loc->limg_Count ();
  }
    static LxResult
  Image (LXtObjectID wcom, unsigned int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_LayeredImage, loc);
    try {
      return loc->limg_Image (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_LayeredImage, loc);
    try {
      return loc->limg_Name (index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Type (LXtObjectID wcom, unsigned int index, unsigned int *flags, const char **type)
  {
    LXCWxINST (CLxImpl_LayeredImage, loc);
    try {
      return loc->limg_Type (index,flags,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Offset (LXtObjectID wcom, unsigned int index, int *x, int *y)
  {
    LXCWxINST (CLxImpl_LayeredImage, loc);
    try {
      return loc->limg_Offset (index,x,y);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Blend (LXtObjectID wcom, unsigned int index, float *opacity, unsigned int *mode)
  {
    LXCWxINST (CLxImpl_LayeredImage, loc);
    try {
      return loc->limg_Blend (index,opacity,mode);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ChannelName (LXtObjectID wcom, unsigned layerIndex, unsigned channelIndex, const char **name)
  {
    LXCWxINST (CLxImpl_LayeredImage, loc);
    try {
      return loc->limg_ChannelName (layerIndex,channelIndex,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Parent (LXtObjectID wcom, unsigned layerIndex, int *parentIndex)
  {
    LXCWxINST (CLxImpl_LayeredImage, loc);
    try {
      return loc->limg_Parent (layerIndex,parentIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsGroup (LXtObjectID wcom, unsigned layerIndex, unsigned int *isGroup)
  {
    LXCWxINST (CLxImpl_LayeredImage, loc);
    try {
      return loc->limg_IsGroup (layerIndex,isGroup);
    } catch (LxResult rc) { return rc; }
  }
  ILxLayeredImage vt;
public:
  CLxIfc_LayeredImage ()
  {
    vt.Size = Size;
    vt.Count = Count;
    vt.Image = Image;
    vt.Name = Name;
    vt.Type = Type;
    vt.Offset = Offset;
    vt.Blend = Blend;
    vt.ChannelName = ChannelName;
    vt.Parent = Parent;
    vt.IsGroup = IsGroup;
    vTable = &vt.iunk;
    iid = &lx::guid_LayeredImage;
  }
};
class CLxLoc_LayeredImage : public CLxLocalize<ILxLayeredImageID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LayeredImage() {_init();}
  CLxLoc_LayeredImage(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LayeredImage(const CLxLoc_LayeredImage &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LayeredImage;}
    LxResult
  Size (unsigned int *w, unsigned int *h) const
  {
    return m_loc[0]->Size (m_loc,w,h);
  }
    unsigned int
  Count (void) const
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  Image (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->Image (m_loc,index,ppvObj);
  }
    CLxResult
  Image (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Image(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Name (unsigned int index, const char **name) const
  {
    return m_loc[0]->Name (m_loc,index,name);
  }
    LxResult
  Type (unsigned int index, unsigned int *flags, const char **type) const
  {
    return m_loc[0]->Type (m_loc,index,flags,type);
  }
    LxResult
  Offset (unsigned int index, int *x, int *y) const
  {
    return m_loc[0]->Offset (m_loc,index,x,y);
  }
    LxResult
  Blend (unsigned int index, float *opacity, unsigned int *mode) const
  {
    return m_loc[0]->Blend (m_loc,index,opacity,mode);
  }
    LxResult
  ChannelName (unsigned layerIndex, unsigned channelIndex, const char **name) const
  {
    return m_loc[0]->ChannelName (m_loc,layerIndex,channelIndex,name);
  }
    LxResult
  Parent (unsigned layerIndex, int *parentIndex) const
  {
    return m_loc[0]->Parent (m_loc,layerIndex,parentIndex);
  }
    LxResult
  IsGroup (unsigned layerIndex, unsigned int *isGroup) const
  {
    return m_loc[0]->IsGroup (m_loc,layerIndex,isGroup);
  }
};

class CLxImpl_ImageSegment {
  public:
    virtual ~CLxImpl_ImageSegment() {}
    virtual LxResult
      imgs_GetSegment (unsigned int y, unsigned int left, unsigned int right, LXtImageFloat *rgba)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imgs_SetSegment (unsigned int y, unsigned int left, unsigned int right, LXtPixelFormat type, const void *line)
        { return LXe_NOTIMPL; }
};
#define LXxD_ImageSegment_GetSegment LxResult imgs_GetSegment (unsigned int y, unsigned int left, unsigned int right, LXtImageFloat *rgba)
#define LXxO_ImageSegment_GetSegment LXxD_ImageSegment_GetSegment LXx_OVERRIDE
#define LXxC_ImageSegment_GetSegment(c) LxResult c::imgs_GetSegment (unsigned int y, unsigned int left, unsigned int right, LXtImageFloat *rgba)
#define LXxD_ImageSegment_SetSegment LxResult imgs_SetSegment (unsigned int y, unsigned int left, unsigned int right, LXtPixelFormat type, const void *line)
#define LXxO_ImageSegment_SetSegment LXxD_ImageSegment_SetSegment LXx_OVERRIDE
#define LXxC_ImageSegment_SetSegment(c) LxResult c::imgs_SetSegment (unsigned int y, unsigned int left, unsigned int right, LXtPixelFormat type, const void *line)
template <class T>
class CLxIfc_ImageSegment : public CLxInterface
{
    static LxResult
  GetSegment (LXtObjectID wcom, unsigned int y, unsigned int left, unsigned int right, LXtImageFloat *rgba)
  {
    LXCWxINST (CLxImpl_ImageSegment, loc);
    try {
      return loc->imgs_GetSegment (y,left,right,rgba);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetSegment (LXtObjectID wcom, unsigned int y, unsigned int left, unsigned int right, LXtPixelFormat type, const void *line)
  {
    LXCWxINST (CLxImpl_ImageSegment, loc);
    try {
      return loc->imgs_SetSegment (y,left,right,type,line);
    } catch (LxResult rc) { return rc; }
  }
  ILxImageSegment vt;
public:
  CLxIfc_ImageSegment ()
  {
    vt.GetSegment = GetSegment;
    vt.SetSegment = SetSegment;
    vTable = &vt.iunk;
    iid = &lx::guid_ImageSegment;
  }
};
class CLxLoc_ImageSegment : public CLxLocalize<ILxImageSegmentID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageSegment() {_init();}
  CLxLoc_ImageSegment(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageSegment(const CLxLoc_ImageSegment &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageSegment;}
    LxResult
  GetSegment (unsigned int y, unsigned int left, unsigned int right, LXtImageFloat *rgba) const
  {
    return m_loc[0]->GetSegment (m_loc,y,left,right,rgba);
  }
    LxResult
  SetSegment (unsigned int y, unsigned int left, unsigned int right, LXtPixelFormat type, const void *line)
  {
    return m_loc[0]->SetSegment (m_loc,y,left,right,type,line);
  }
};

class CLxImpl_ImageWrite {
  public:
    virtual ~CLxImpl_ImageWrite() {}
    virtual void
      imgw_Size (unsigned int *w, unsigned int *h)
        { }
    virtual LXtPixelFormat
      imgw_Format (void)
        = 0;
    virtual LxResult
      imgw_AddAttribute (const char *name, const char *type, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imgw_SetPixel (unsigned int x, unsigned int y, LXtPixelFormat type, const void *pixel)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imgw_SetLine (unsigned int y, LXtPixelFormat type, const void *line)
        { return LXe_NOTIMPL; }
};
#define LXxD_ImageWrite_Size void imgw_Size (unsigned int *w, unsigned int *h)
#define LXxO_ImageWrite_Size LXxD_ImageWrite_Size LXx_OVERRIDE
#define LXxC_ImageWrite_Size(c) void c::imgw_Size (unsigned int *w, unsigned int *h)
#define LXxD_ImageWrite_Format LXtPixelFormat imgw_Format (void)
#define LXxO_ImageWrite_Format LXxD_ImageWrite_Format LXx_OVERRIDE
#define LXxC_ImageWrite_Format(c) LXtPixelFormat c::imgw_Format (void)
#define LXxD_ImageWrite_AddAttribute LxResult imgw_AddAttribute (const char *name, const char *type, unsigned *index)
#define LXxO_ImageWrite_AddAttribute LXxD_ImageWrite_AddAttribute LXx_OVERRIDE
#define LXxC_ImageWrite_AddAttribute(c) LxResult c::imgw_AddAttribute (const char *name, const char *type, unsigned *index)
#define LXxD_ImageWrite_SetPixel LxResult imgw_SetPixel (unsigned int x, unsigned int y, LXtPixelFormat type, const void *pixel)
#define LXxO_ImageWrite_SetPixel LXxD_ImageWrite_SetPixel LXx_OVERRIDE
#define LXxC_ImageWrite_SetPixel(c) LxResult c::imgw_SetPixel (unsigned int x, unsigned int y, LXtPixelFormat type, const void *pixel)
#define LXxD_ImageWrite_SetLine LxResult imgw_SetLine (unsigned int y, LXtPixelFormat type, const void *line)
#define LXxO_ImageWrite_SetLine LXxD_ImageWrite_SetLine LXx_OVERRIDE
#define LXxC_ImageWrite_SetLine(c) LxResult c::imgw_SetLine (unsigned int y, LXtPixelFormat type, const void *line)
template <class T>
class CLxIfc_ImageWrite : public CLxInterface
{
    static void
  Size (LXtObjectID wcom, unsigned int *w, unsigned int *h)
  {
    LXCWxINST (CLxImpl_ImageWrite, loc);
    loc->imgw_Size (w,h);
  }
    static LXtPixelFormat
  Format (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ImageWrite, loc);
    return loc->imgw_Format ();
  }
    static LxResult
  AddAttribute (LXtObjectID wcom, const char *name, const char *type, unsigned *index)
  {
    LXCWxINST (CLxImpl_ImageWrite, loc);
    try {
      return loc->imgw_AddAttribute (name,type,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetPixel (LXtObjectID wcom, unsigned int x, unsigned int y, LXtPixelFormat type, const void *pixel)
  {
    LXCWxINST (CLxImpl_ImageWrite, loc);
    try {
      return loc->imgw_SetPixel (x,y,type,pixel);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetLine (LXtObjectID wcom, unsigned int y, LXtPixelFormat type, const void *line)
  {
    LXCWxINST (CLxImpl_ImageWrite, loc);
    try {
      return loc->imgw_SetLine (y,type,line);
    } catch (LxResult rc) { return rc; }
  }
  ILxImageWrite vt;
public:
  CLxIfc_ImageWrite ()
  {
    vt.Size = Size;
    vt.Format = Format;
    vt.AddAttribute = AddAttribute;
    vt.SetPixel = SetPixel;
    vt.SetLine = SetLine;
    vTable = &vt.iunk;
    iid = &lx::guid_ImageWrite;
  }
};
class CLxLoc_ImageWrite : public CLxLocalize<ILxImageWriteID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageWrite() {_init();}
  CLxLoc_ImageWrite(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageWrite(const CLxLoc_ImageWrite &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageWrite;}
    void
  Size (unsigned int *w, unsigned int *h) const
  {
    m_loc[0]->Size (m_loc,w,h);
  }
    LXtPixelFormat
  Format (void) const
  {
    return m_loc[0]->Format (m_loc);
  }
    LxResult
  AddAttribute (const char *name, const char *type, unsigned *index)
  {
    return m_loc[0]->AddAttribute (m_loc,name,type,index);
  }
    LxResult
  SetPixel (unsigned int x, unsigned int y, LXtPixelFormat type, const void *pixel)
  {
    return m_loc[0]->SetPixel (m_loc,x,y,type,pixel);
  }
    LxResult
  SetLine (unsigned int y, LXtPixelFormat type, const void *line)
  {
    return m_loc[0]->SetLine (m_loc,y,type,line);
  }
};

class CLxImpl_Image {
  public:
    virtual ~CLxImpl_Image() {}
    virtual void
      img_Size (unsigned int *w, unsigned int *h)
        { }
    virtual LXtPixelFormat
      img_Format (void)
        = 0;
    virtual LxResult
      img_GetPixel (unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel)
        { return LXe_NOTIMPL; }
    virtual const void *
      img_GetLine (unsigned int y, LXtPixelFormat type, void *buf)
        = 0;
};
#define LXxD_Image_Size void img_Size (unsigned int *w, unsigned int *h)
#define LXxO_Image_Size LXxD_Image_Size LXx_OVERRIDE
#define LXxC_Image_Size(c) void c::img_Size (unsigned int *w, unsigned int *h)
#define LXxD_Image_Format LXtPixelFormat img_Format (void)
#define LXxO_Image_Format LXxD_Image_Format LXx_OVERRIDE
#define LXxC_Image_Format(c) LXtPixelFormat c::img_Format (void)
#define LXxD_Image_GetPixel LxResult img_GetPixel (unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel)
#define LXxO_Image_GetPixel LXxD_Image_GetPixel LXx_OVERRIDE
#define LXxC_Image_GetPixel(c) LxResult c::img_GetPixel (unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel)
#define LXxD_Image_GetLine const void * img_GetLine (unsigned int y, LXtPixelFormat type, void *buf)
#define LXxO_Image_GetLine LXxD_Image_GetLine LXx_OVERRIDE
#define LXxC_Image_GetLine(c) const void * c::img_GetLine (unsigned int y, LXtPixelFormat type, void *buf)
template <class T>
class CLxIfc_Image : public CLxInterface
{
    static void
  Size (LXtObjectID wcom, unsigned int *w, unsigned int *h)
  {
    LXCWxINST (CLxImpl_Image, loc);
    loc->img_Size (w,h);
  }
    static LXtPixelFormat
  Format (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Image, loc);
    return loc->img_Format ();
  }
    static LxResult
  GetPixel (LXtObjectID wcom, unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel)
  {
    LXCWxINST (CLxImpl_Image, loc);
    try {
      return loc->img_GetPixel (x,y,type,pixel);
    } catch (LxResult rc) { return rc; }
  }
    static const void *
  GetLine (LXtObjectID wcom, unsigned int y, LXtPixelFormat type, void *buf)
  {
    LXCWxINST (CLxImpl_Image, loc);
    return loc->img_GetLine (y,type,buf);
  }
  ILxImage vt;
public:
  CLxIfc_Image ()
  {
    vt.Size = Size;
    vt.Format = Format;
    vt.GetPixel = GetPixel;
    vt.GetLine = GetLine;
    vTable = &vt.iunk;
    iid = &lx::guid_Image;
  }
};
class CLxLoc_Image : public CLxLocalize<ILxImageID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Image() {_init();}
  CLxLoc_Image(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Image(const CLxLoc_Image &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Image;}
    void
  Size (unsigned int *w, unsigned int *h) const
  {
    m_loc[0]->Size (m_loc,w,h);
  }
    LXtPixelFormat
  Format (void) const
  {
    return m_loc[0]->Format (m_loc);
  }
    LxResult
  GetPixel (unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel) const
  {
    return m_loc[0]->GetPixel (m_loc,x,y,type,pixel);
  }
    const void *
  GetLine (unsigned int y, LXtPixelFormat type, void *buf) const
  {
    return m_loc[0]->GetLine (m_loc,y,type,buf);
  }
};

class CLxLoc_IndexImageWrite : public CLxLocalize<ILxIndexImageWriteID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_IndexImageWrite() {_init();}
  CLxLoc_IndexImageWrite(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_IndexImageWrite(const CLxLoc_IndexImageWrite &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_IndexImageWrite;}
    void
  Size (unsigned int *w, unsigned int *h) const
  {
    m_loc[0]->Size (m_loc,w,h);
  }
    LXtPixelFormat
  Format (void) const
  {
    return m_loc[0]->Format (m_loc);
  }
    LxResult
  AddAttribute (const char *name, const char *type, unsigned *index)
  {
    return m_loc[0]->AddAttribute (m_loc,name,type,index);
  }
    LxResult
  SetIndex (unsigned int x, unsigned int y, LXtImageIndex index)
  {
    return m_loc[0]->SetIndex (m_loc,x,y,index);
  }
    LxResult
  SetMap (LXtImageIndex index, LXtPixelFormat type, const void *pixel)
  {
    return m_loc[0]->SetMap (m_loc,index,type,pixel);
  }
};

class CLxImpl_ImageFilterMetrics {
  public:
    virtual ~CLxImpl_ImageFilterMetrics() {}
    virtual LxResult
      imfmet_Generate (LXtImageMetrics *metrics)
        { return LXe_NOTIMPL; }
    virtual LxResult
      imfmet_Evaluate (LXtImageMetrics *metrics)
        { return LXe_NOTIMPL; }
};
#define LXxD_ImageFilterMetrics_Generate LxResult imfmet_Generate (LXtImageMetrics *metrics)
#define LXxO_ImageFilterMetrics_Generate LXxD_ImageFilterMetrics_Generate LXx_OVERRIDE
#define LXxC_ImageFilterMetrics_Generate(c) LxResult c::imfmet_Generate (LXtImageMetrics *metrics)
#define LXxD_ImageFilterMetrics_Evaluate LxResult imfmet_Evaluate (LXtImageMetrics *metrics)
#define LXxO_ImageFilterMetrics_Evaluate LXxD_ImageFilterMetrics_Evaluate LXx_OVERRIDE
#define LXxC_ImageFilterMetrics_Evaluate(c) LxResult c::imfmet_Evaluate (LXtImageMetrics *metrics)
template <class T>
class CLxIfc_ImageFilterMetrics : public CLxInterface
{
    static LxResult
  Generate (LXtObjectID wcom, LXtImageMetrics *metrics)
  {
    LXCWxINST (CLxImpl_ImageFilterMetrics, loc);
    try {
      return loc->imfmet_Generate (metrics);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Evaluate (LXtObjectID wcom, LXtImageMetrics *metrics)
  {
    LXCWxINST (CLxImpl_ImageFilterMetrics, loc);
    try {
      return loc->imfmet_Evaluate (metrics);
    } catch (LxResult rc) { return rc; }
  }
  ILxImageFilterMetrics vt;
public:
  CLxIfc_ImageFilterMetrics ()
  {
    vt.Generate = Generate;
    vt.Evaluate = Evaluate;
    vTable = &vt.iunk;
    iid = &lx::guid_ImageFilterMetrics;
  }
};
class CLxLoc_ImageFilterMetrics : public CLxLocalize<ILxImageFilterMetricsID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageFilterMetrics() {_init();}
  CLxLoc_ImageFilterMetrics(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageFilterMetrics(const CLxLoc_ImageFilterMetrics &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageFilterMetrics;}
    LxResult
  Generate (LXtImageMetrics *metrics)
  {
    return m_loc[0]->Generate (m_loc,metrics);
  }
    LxResult
  Evaluate (LXtImageMetrics *metrics)
  {
    return m_loc[0]->Evaluate (m_loc,metrics);
  }
};

class CLxImpl_ImageLevelSample {
  public:
    virtual ~CLxImpl_ImageLevelSample() {}
    virtual unsigned
      level_Count (void)
        = 0;
    virtual LxResult
      level_GetLevelSize (unsigned level, unsigned *width, unsigned *height)
        { return LXe_NOTIMPL; }
    virtual LxResult
      level_SampleLevel (unsigned level, LXtImageSample *pixel, unsigned num)
        { return LXe_NOTIMPL; }
    virtual LxResult
      level_GetPixel (unsigned level, unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel)
        { return LXe_NOTIMPL; }
    virtual const LXtImageFloat *
      level_GetLine (unsigned level, unsigned y, LXtImageFloat *buf)
        = 0;
};
#define LXxD_ImageLevelSample_Count unsigned level_Count (void)
#define LXxO_ImageLevelSample_Count LXxD_ImageLevelSample_Count LXx_OVERRIDE
#define LXxC_ImageLevelSample_Count(c) unsigned c::level_Count (void)
#define LXxD_ImageLevelSample_GetLevelSize LxResult level_GetLevelSize (unsigned level, unsigned *width, unsigned *height)
#define LXxO_ImageLevelSample_GetLevelSize LXxD_ImageLevelSample_GetLevelSize LXx_OVERRIDE
#define LXxC_ImageLevelSample_GetLevelSize(c) LxResult c::level_GetLevelSize (unsigned level, unsigned *width, unsigned *height)
#define LXxD_ImageLevelSample_SampleLevel LxResult level_SampleLevel (unsigned level, LXtImageSample *pixel, unsigned num)
#define LXxO_ImageLevelSample_SampleLevel LXxD_ImageLevelSample_SampleLevel LXx_OVERRIDE
#define LXxC_ImageLevelSample_SampleLevel(c) LxResult c::level_SampleLevel (unsigned level, LXtImageSample *pixel, unsigned num)
#define LXxD_ImageLevelSample_GetPixel LxResult level_GetPixel (unsigned level, unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel)
#define LXxO_ImageLevelSample_GetPixel LXxD_ImageLevelSample_GetPixel LXx_OVERRIDE
#define LXxC_ImageLevelSample_GetPixel(c) LxResult c::level_GetPixel (unsigned level, unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel)
#define LXxD_ImageLevelSample_GetLine const LXtImageFloat * level_GetLine (unsigned level, unsigned y, LXtImageFloat *buf)
#define LXxO_ImageLevelSample_GetLine LXxD_ImageLevelSample_GetLine LXx_OVERRIDE
#define LXxC_ImageLevelSample_GetLine(c) const LXtImageFloat * c::level_GetLine (unsigned level, unsigned y, LXtImageFloat *buf)
template <class T>
class CLxIfc_ImageLevelSample : public CLxInterface
{
    static unsigned
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ImageLevelSample, loc);
    return loc->level_Count ();
  }
    static LxResult
  GetLevelSize (LXtObjectID wcom, unsigned level, unsigned *width, unsigned *height)
  {
    LXCWxINST (CLxImpl_ImageLevelSample, loc);
    try {
      return loc->level_GetLevelSize (level,width,height);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SampleLevel (LXtObjectID wcom, unsigned level, LXtImageSample *pixel, unsigned num)
  {
    LXCWxINST (CLxImpl_ImageLevelSample, loc);
    try {
      return loc->level_SampleLevel (level,pixel,num);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetPixel (LXtObjectID wcom, unsigned level, unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel)
  {
    LXCWxINST (CLxImpl_ImageLevelSample, loc);
    try {
      return loc->level_GetPixel (level,x,y,type,pixel);
    } catch (LxResult rc) { return rc; }
  }
    static const LXtImageFloat *
  GetLine (LXtObjectID wcom, unsigned level, unsigned y, LXtImageFloat *buf)
  {
    LXCWxINST (CLxImpl_ImageLevelSample, loc);
    return loc->level_GetLine (level,y,buf);
  }
  ILxImageLevelSample vt;
public:
  CLxIfc_ImageLevelSample ()
  {
    vt.Count = Count;
    vt.GetLevelSize = GetLevelSize;
    vt.SampleLevel = SampleLevel;
    vt.GetPixel = GetPixel;
    vt.GetLine = GetLine;
    vTable = &vt.iunk;
    iid = &lx::guid_ImageLevelSample;
  }
};
class CLxLoc_ImageLevelSample : public CLxLocalize<ILxImageLevelSampleID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageLevelSample() {_init();}
  CLxLoc_ImageLevelSample(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageLevelSample(const CLxLoc_ImageLevelSample &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageLevelSample;}
    unsigned
  Count (void) const
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  GetLevelSize (unsigned level, unsigned *width, unsigned *height) const
  {
    return m_loc[0]->GetLevelSize (m_loc,level,width,height);
  }
    LxResult
  SampleLevel (unsigned level, LXtImageSample *pixel, unsigned num) const
  {
    return m_loc[0]->SampleLevel (m_loc,level,pixel,num);
  }
    LxResult
  GetPixel (unsigned level, unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel) const
  {
    return m_loc[0]->GetPixel (m_loc,level,x,y,type,pixel);
  }
    const LXtImageFloat *
  GetLine (unsigned level, unsigned y, LXtImageFloat *buf) const
  {
    return m_loc[0]->GetLine (m_loc,level,y,buf);
  }
};

class CLxLoc_ImageLoaderTarget : public CLxLocalize<ILxImageLoaderTargetID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageLoaderTarget() {_init();}
  CLxLoc_ImageLoaderTarget(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageLoaderTarget(const CLxLoc_ImageLoaderTarget &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageLoaderTarget;}
    LxResult
  SetSize (LXtPixelFormat type, unsigned width, unsigned height)
  {
    return m_loc[0]->SetSize (m_loc,type,width,height);
  }
    LxResult
  SetMap (unsigned ncolor)
  {
    return m_loc[0]->SetMap (m_loc,ncolor);
  }
    LxResult
  SetColorspaceDepth (unsigned depth)
  {
    return m_loc[0]->SetColorspaceDepth (m_loc,depth);
  }
    LxResult
  SetColorspace (const char *colorspace)
  {
    return m_loc[0]->SetColorspace (m_loc,colorspace);
  }
};


class CLxLoc_ImageLoaderTarget1 : public CLxLocalize<ILxImageLoaderTarget1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageLoaderTarget1() {_init();}
  CLxLoc_ImageLoaderTarget1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageLoaderTarget1(const CLxLoc_ImageLoaderTarget1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageLoaderTarget1;}
    LxResult
  SetSize (LXtPixelFormat type, unsigned width, unsigned height)
  {
    return m_loc[0]->SetSize (m_loc,type,width,height);
  }
    LxResult
  SetMap (unsigned ncolor)
  {
    return m_loc[0]->SetMap (m_loc,ncolor);
  }
};

class CLxImpl_Movie {
  public:
    virtual ~CLxImpl_Movie() {}
    virtual LxResult
      mov_BeginMovie (const char *fname, int w, int h, int flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mov_SetFramerate (int frate)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mov_AddImage (ILxUnknownID image)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mov_EndMovie (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mov_AddAudio (ILxUnknownID audio)
        { return LXe_NOTIMPL; }
};
#define LXxD_Movie_BeginMovie LxResult mov_BeginMovie (const char *fname, int w, int h, int flags)
#define LXxO_Movie_BeginMovie LXxD_Movie_BeginMovie LXx_OVERRIDE
#define LXxC_Movie_BeginMovie(c) LxResult c::mov_BeginMovie (const char *fname, int w, int h, int flags)
#define LXxD_Movie_SetFramerate LxResult mov_SetFramerate (int frate)
#define LXxO_Movie_SetFramerate LXxD_Movie_SetFramerate LXx_OVERRIDE
#define LXxC_Movie_SetFramerate(c) LxResult c::mov_SetFramerate (int frate)
#define LXxD_Movie_AddImage LxResult mov_AddImage (ILxUnknownID image)
#define LXxO_Movie_AddImage LXxD_Movie_AddImage LXx_OVERRIDE
#define LXxC_Movie_AddImage(c) LxResult c::mov_AddImage (ILxUnknownID image)
#define LXxD_Movie_EndMovie LxResult mov_EndMovie (void)
#define LXxO_Movie_EndMovie LXxD_Movie_EndMovie LXx_OVERRIDE
#define LXxC_Movie_EndMovie(c) LxResult c::mov_EndMovie (void)
#define LXxD_Movie_AddAudio LxResult mov_AddAudio (ILxUnknownID audio)
#define LXxO_Movie_AddAudio LXxD_Movie_AddAudio LXx_OVERRIDE
#define LXxC_Movie_AddAudio(c) LxResult c::mov_AddAudio (ILxUnknownID audio)
template <class T>
class CLxIfc_Movie : public CLxInterface
{
    static LxResult
  BeginMovie (LXtObjectID wcom, const char *fname, int w, int h, int flags)
  {
    LXCWxINST (CLxImpl_Movie, loc);
    try {
      return loc->mov_BeginMovie (fname,w,h,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetFramerate (LXtObjectID wcom, int frate)
  {
    LXCWxINST (CLxImpl_Movie, loc);
    try {
      return loc->mov_SetFramerate (frate);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddImage (LXtObjectID wcom, LXtObjectID image)
  {
    LXCWxINST (CLxImpl_Movie, loc);
    try {
      return loc->mov_AddImage ((ILxUnknownID)image);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  EndMovie (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Movie, loc);
    try {
      return loc->mov_EndMovie ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddAudio (LXtObjectID wcom, LXtObjectID audio)
  {
    LXCWxINST (CLxImpl_Movie, loc);
    try {
      return loc->mov_AddAudio ((ILxUnknownID)audio);
    } catch (LxResult rc) { return rc; }
  }
  ILxMovie vt;
public:
  CLxIfc_Movie ()
  {
    vt.BeginMovie = BeginMovie;
    vt.SetFramerate = SetFramerate;
    vt.AddImage = AddImage;
    vt.EndMovie = EndMovie;
    vt.AddAudio = AddAudio;
    vTable = &vt.iunk;
    iid = &lx::guid_Movie;
  }
};

class CLxLoc_IndexImage : public CLxLocalize<ILxIndexImageID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_IndexImage() {_init();}
  CLxLoc_IndexImage(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_IndexImage(const CLxLoc_IndexImage &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_IndexImage;}
    void
  Size (unsigned int *w, unsigned int *h) const
  {
    m_loc[0]->Size (m_loc,w,h);
  }
    LXtPixelFormat
  Format (void) const
  {
    return m_loc[0]->Format (m_loc);
  }
    LxResult
  MapSize (unsigned *numColors) const
  {
    return m_loc[0]->MapSize (m_loc,numColors);
  }
    LxResult
  GetIndex (unsigned int x, unsigned int y, LXtImageIndex *index) const
  {
    return m_loc[0]->GetIndex (m_loc,x,y,index);
  }
    LxResult
  GetMap (LXtImageIndex index, LXtPixelFormat type, void *pixel) const
  {
    return m_loc[0]->GetMap (m_loc,index,type,pixel);
  }
};

#endif

