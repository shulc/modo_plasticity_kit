/*
 * C++ wrapper for lxtoolui.h
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
#ifndef LXW_TOOLUI_HPP
#define LXW_TOOLUI_HPP

#include <lxtoolui.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_RaycastPacket1 = {0xD622B573,0x2638,0x4A47,0xAD,0x91,0x6B,0xC7,0xA6,0xD2,0xD3,0x0B};
    static const LXtGUID guid_PaintInkPacket = {0x340EE412,0x232D,0x4619,0x97,0x4D,0x7E,0x59,0xC7,0xB3,0x93,0x53};
    static const LXtGUID guid_ItemReplacement1 = {0x3C256C60,0xDDE0,0x4347,0x82,0xBB,0x10,0xBF,0x6E,0x3A,0xE8,0x87};
    static const LXtGUID guid_RaycastPacket = {0xB2973789,0x447F,0x45AA,0x98,0xF3,0x79,0x48,0x4A,0x34,0x80,0xD8};
    static const LXtGUID guid_ItemReplacement = {0x2829760d,0xfd93,0x400e,0xaa,0xc5,0xf9,0x8f,0x1b,0x9a,0x15,0x00};
    static const LXtGUID guid_PaintNozzlePacket = {0xF0BB49ED,0x0BBB,0x448a,0x83,0x39,0xF6,0x9F,0x78,0xE9,0x50,0x48};
    static const LXtGUID guid_RaycastPacket2 = {0x4AC0C624,0x15EE,0x4BB1,0x91,0xEB,0xCD,0xF9,0x39,0x5A,0x91,0x93};
    static const LXtGUID guid_PaintBrushPacket = {0x9283C21E,0x77FC,0x402D,0xB2,0x2A,0x7B,0x26,0x28,0x58,0x88,0xC4};
};

class CLxLoc_RaycastPacket1 : public CLxLocalize<ILxRaycastPacket1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_RaycastPacket1() {_init();}
  CLxLoc_RaycastPacket1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_RaycastPacket1(const CLxLoc_RaycastPacket1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_RaycastPacket1;}
    int
  HitPolygon (ILxUnknownID toolVector, float x, float y, LXtHitPolygon *hit)
  {
    return m_loc[0]->HitPolygon (m_loc,(ILxUnknownID)toolVector,x,y,hit);
  }
    int
  HitEdge (ILxUnknownID toolVector, float x, float y, LXtHitEdge *hit)
  {
    return m_loc[0]->HitEdge (m_loc,(ILxUnknownID)toolVector,x,y,hit);
  }
    int
  HitVertex (ILxUnknownID toolVector, float x, float y, LXtHitVertex *hit)
  {
    return m_loc[0]->HitVertex (m_loc,(ILxUnknownID)toolVector,x,y,hit);
  }
    int
  HitItem (ILxUnknownID toolVector, float x, float y, LXtHitItem *hit)
  {
    return m_loc[0]->HitItem (m_loc,(ILxUnknownID)toolVector,x,y,hit);
  }
};

class CLxLoc_PaintInkPacket : public CLxLocalize<ILxPaintInkPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PaintInkPacket() {_init();}
  CLxLoc_PaintInkPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PaintInkPacket(const CLxLoc_PaintInkPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PaintInkPacket;}
    int
  Flags (ILxUnknownID toolVector)
  {
    return m_loc[0]->Flags (m_loc,(ILxUnknownID)toolVector);
  }
    int
  Color (ILxUnknownID toolVector, int flags, LXtColorRGBA rgba)
  {
    return m_loc[0]->Color (m_loc,(ILxUnknownID)toolVector,flags,rgba);
  }
    int
  Stamp (LXtPaintBrush *brush)
  {
    return m_loc[0]->Stamp (m_loc,brush);
  }
};

class CLxImpl_ItemReplacement1 {
  public:
    virtual ~CLxImpl_ItemReplacement1() {}
    virtual LxResult
      itemrep_ReplaceItems (ILxUnknownID current, ILxUnknownID replacement)
        { return LXe_NOTIMPL; }
    virtual LxResult
      itemrep_Types (const char *curType, const char **repTypes)
        { return LXe_NOTIMPL; }
    virtual LxResult
      itemrep_NotifierCount (const char *itemType, const char *channelName, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      itemrep_NotifierByIndex (const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
};
#define LXxD_ItemReplacement1_ReplaceItems LxResult itemrep_ReplaceItems (ILxUnknownID current, ILxUnknownID replacement)
#define LXxO_ItemReplacement1_ReplaceItems LXxD_ItemReplacement1_ReplaceItems LXx_OVERRIDE
#define LXxC_ItemReplacement1_ReplaceItems(c) LxResult c::itemrep_ReplaceItems (ILxUnknownID current, ILxUnknownID replacement)
#define LXxD_ItemReplacement1_Types LxResult itemrep_Types (const char *curType, const char **repTypes)
#define LXxO_ItemReplacement1_Types LXxD_ItemReplacement1_Types LXx_OVERRIDE
#define LXxC_ItemReplacement1_Types(c) LxResult c::itemrep_Types (const char *curType, const char **repTypes)
#define LXxD_ItemReplacement1_NotifierCount LxResult itemrep_NotifierCount (const char *itemType, const char *channelName, unsigned *count)
#define LXxO_ItemReplacement1_NotifierCount LXxD_ItemReplacement1_NotifierCount LXx_OVERRIDE
#define LXxC_ItemReplacement1_NotifierCount(c) LxResult c::itemrep_NotifierCount (const char *itemType, const char *channelName, unsigned *count)
#define LXxD_ItemReplacement1_NotifierByIndex LxResult itemrep_NotifierByIndex (const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len)
#define LXxO_ItemReplacement1_NotifierByIndex LXxD_ItemReplacement1_NotifierByIndex LXx_OVERRIDE
#define LXxC_ItemReplacement1_NotifierByIndex(c) LxResult c::itemrep_NotifierByIndex (const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len)
template <class T>
class CLxIfc_ItemReplacement1 : public CLxInterface
{
    static LxResult
  ReplaceItems (LXtObjectID wcom, LXtObjectID current, LXtObjectID replacement)
  {
    LXCWxINST (CLxImpl_ItemReplacement1, loc);
    try {
      return loc->itemrep_ReplaceItems ((ILxUnknownID)current,(ILxUnknownID)replacement);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Types (LXtObjectID wcom, const char *curType, const char **repTypes)
  {
    LXCWxINST (CLxImpl_ItemReplacement1, loc);
    try {
      return loc->itemrep_Types (curType,repTypes);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierCount (LXtObjectID wcom, const char *itemType, const char *channelName, unsigned *count)
  {
    LXCWxINST (CLxImpl_ItemReplacement1, loc);
    try {
      return loc->itemrep_NotifierCount (itemType,channelName,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierByIndex (LXtObjectID wcom, const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_ItemReplacement1, loc);
    try {
      return loc->itemrep_NotifierByIndex (itemType,channelName,index,buf,len);
    } catch (LxResult rc) { return rc; }
  }
  ILxItemReplacement1 vt;
public:
  CLxIfc_ItemReplacement1 ()
  {
    vt.ReplaceItems = ReplaceItems;
    vt.Types = Types;
    vt.NotifierCount = NotifierCount;
    vt.NotifierByIndex = NotifierByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_ItemReplacement1;
  }
};
class CLxLoc_ItemReplacement1 : public CLxLocalize<ILxItemReplacement1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemReplacement1() {_init();}
  CLxLoc_ItemReplacement1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemReplacement1(const CLxLoc_ItemReplacement1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemReplacement1;}
    LxResult
  ReplaceItems (ILxUnknownID current, ILxUnknownID replacement)
  {
    return m_loc[0]->ReplaceItems (m_loc,(ILxUnknownID)current,(ILxUnknownID)replacement);
  }
    LxResult
  Types (const char *curType, const char **repTypes)
  {
    return m_loc[0]->Types (m_loc,curType,repTypes);
  }
    LxResult
  NotifierCount (const char *itemType, const char *channelName, unsigned *count)
  {
    return m_loc[0]->NotifierCount (m_loc,itemType,channelName,count);
  }
    LxResult
  NotifierByIndex (const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len)
  {
    return m_loc[0]->NotifierByIndex (m_loc,itemType,channelName,index,buf,len);
  }
    LxResult
  NotifierByIndex (const char *itemType, const char *channelName, unsigned index, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->NotifierByIndex (m_loc,itemType,channelName,index,buf,len);
    LXWx_SBUF2
  }
};

class CLxLoc_RaycastPacket : public CLxLocalize<ILxRaycastPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_RaycastPacket() {_init();}
  CLxLoc_RaycastPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_RaycastPacket(const CLxLoc_RaycastPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_RaycastPacket;}
    int
  HitPolygon (ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitPolygon *hit)
  {
    return m_loc[0]->HitPolygon (m_loc,(ILxUnknownID)toolVector,layer,x,y,hit);
  }
    int
  HitEdge (ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitEdge *hit)
  {
    return m_loc[0]->HitEdge (m_loc,(ILxUnknownID)toolVector,layer,x,y,hit);
  }
    int
  HitVertex (ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitVertex *hit)
  {
    return m_loc[0]->HitVertex (m_loc,(ILxUnknownID)toolVector,layer,x,y,hit);
  }
    int
  HitItem (ILxUnknownID toolVector, float x, float y, LXtHitItem *hit)
  {
    return m_loc[0]->HitItem (m_loc,(ILxUnknownID)toolVector,x,y,hit);
  }
    int
  HitPolygon1 (ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitElement *hit)
  {
    return m_loc[0]->HitPolygon1 (m_loc,(ILxUnknownID)toolVector,layer,x,y,hit);
  }
    int
  HitEdge1 (ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitElement *hit)
  {
    return m_loc[0]->HitEdge1 (m_loc,(ILxUnknownID)toolVector,layer,x,y,hit);
  }
    int
  HitVertex1 (ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitElement *hit)
  {
    return m_loc[0]->HitVertex1 (m_loc,(ILxUnknownID)toolVector,layer,x,y,hit);
  }
    int
  HitClosest (ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitElement *hit)
  {
    return m_loc[0]->HitClosest (m_loc,(ILxUnknownID)toolVector,layer,x,y,hit);
  }
    int
  HitCached (ILxUnknownID toolVector, LXtHitElement *hit)
  {
    return m_loc[0]->HitCached (m_loc,(ILxUnknownID)toolVector,hit);
  }
};

class CLxImpl_ItemReplacement {
  public:
    virtual ~CLxImpl_ItemReplacement() {}
    virtual LxResult
      itemrep_ReplaceItems (ILxUnknownID current, ILxUnknownID replacement, int targetType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      itemrep_Types (const char *curType, const char **repTypes)
        { return LXe_NOTIMPL; }
    virtual LxResult
      itemrep_NotifierCount (const char *itemType, const char *channelName, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      itemrep_NotifierByIndex (const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
};
#define LXxD_ItemReplacement_ReplaceItems LxResult itemrep_ReplaceItems (ILxUnknownID current, ILxUnknownID replacement, int targetType)
#define LXxO_ItemReplacement_ReplaceItems LXxD_ItemReplacement_ReplaceItems LXx_OVERRIDE
#define LXxC_ItemReplacement_ReplaceItems(c) LxResult c::itemrep_ReplaceItems (ILxUnknownID current, ILxUnknownID replacement, int targetType)
#define LXxD_ItemReplacement_Types LxResult itemrep_Types (const char *curType, const char **repTypes)
#define LXxO_ItemReplacement_Types LXxD_ItemReplacement_Types LXx_OVERRIDE
#define LXxC_ItemReplacement_Types(c) LxResult c::itemrep_Types (const char *curType, const char **repTypes)
#define LXxD_ItemReplacement_NotifierCount LxResult itemrep_NotifierCount (const char *itemType, const char *channelName, unsigned *count)
#define LXxO_ItemReplacement_NotifierCount LXxD_ItemReplacement_NotifierCount LXx_OVERRIDE
#define LXxC_ItemReplacement_NotifierCount(c) LxResult c::itemrep_NotifierCount (const char *itemType, const char *channelName, unsigned *count)
#define LXxD_ItemReplacement_NotifierByIndex LxResult itemrep_NotifierByIndex (const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len)
#define LXxO_ItemReplacement_NotifierByIndex LXxD_ItemReplacement_NotifierByIndex LXx_OVERRIDE
#define LXxC_ItemReplacement_NotifierByIndex(c) LxResult c::itemrep_NotifierByIndex (const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len)
template <class T>
class CLxIfc_ItemReplacement : public CLxInterface
{
    static LxResult
  ReplaceItems (LXtObjectID wcom, LXtObjectID current, LXtObjectID replacement, int targetType)
  {
    LXCWxINST (CLxImpl_ItemReplacement, loc);
    try {
      return loc->itemrep_ReplaceItems ((ILxUnknownID)current,(ILxUnknownID)replacement,targetType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Types (LXtObjectID wcom, const char *curType, const char **repTypes)
  {
    LXCWxINST (CLxImpl_ItemReplacement, loc);
    try {
      return loc->itemrep_Types (curType,repTypes);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierCount (LXtObjectID wcom, const char *itemType, const char *channelName, unsigned *count)
  {
    LXCWxINST (CLxImpl_ItemReplacement, loc);
    try {
      return loc->itemrep_NotifierCount (itemType,channelName,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierByIndex (LXtObjectID wcom, const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_ItemReplacement, loc);
    try {
      return loc->itemrep_NotifierByIndex (itemType,channelName,index,buf,len);
    } catch (LxResult rc) { return rc; }
  }
  ILxItemReplacement vt;
public:
  CLxIfc_ItemReplacement ()
  {
    vt.ReplaceItems = ReplaceItems;
    vt.Types = Types;
    vt.NotifierCount = NotifierCount;
    vt.NotifierByIndex = NotifierByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_ItemReplacement;
  }
};
class CLxLoc_ItemReplacement : public CLxLocalize<ILxItemReplacementID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemReplacement() {_init();}
  CLxLoc_ItemReplacement(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemReplacement(const CLxLoc_ItemReplacement &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemReplacement;}
    LxResult
  ReplaceItems (ILxUnknownID current, ILxUnknownID replacement, int targetType)
  {
    return m_loc[0]->ReplaceItems (m_loc,(ILxUnknownID)current,(ILxUnknownID)replacement,targetType);
  }
    LxResult
  Types (const char *curType, const char **repTypes)
  {
    return m_loc[0]->Types (m_loc,curType,repTypes);
  }
    LxResult
  NotifierCount (const char *itemType, const char *channelName, unsigned *count)
  {
    return m_loc[0]->NotifierCount (m_loc,itemType,channelName,count);
  }
    LxResult
  NotifierByIndex (const char *itemType, const char *channelName, unsigned index, char *buf, unsigned len)
  {
    return m_loc[0]->NotifierByIndex (m_loc,itemType,channelName,index,buf,len);
  }
    LxResult
  NotifierByIndex (const char *itemType, const char *channelName, unsigned index, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->NotifierByIndex (m_loc,itemType,channelName,index,buf,len);
    LXWx_SBUF2
  }
};

class CLxLoc_PaintNozzlePacket : public CLxLocalize<ILxPaintNozzlePacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PaintNozzlePacket() {_init();}
  CLxLoc_PaintNozzlePacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PaintNozzlePacket(const CLxLoc_PaintNozzlePacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PaintNozzlePacket;}
    int
  Paint (ILxUnknownID toolVector, float brushSize)
  {
    return m_loc[0]->Paint (m_loc,(ILxUnknownID)toolVector,brushSize);
  }
    int
  Jitter (ILxUnknownID toolVector, float brushSize, int *xj, int *yj)
  {
    return m_loc[0]->Jitter (m_loc,(ILxUnknownID)toolVector,brushSize,xj,yj);
  }
    int
  Nozzle (ILxUnknownID toolVector, float *strength, float *size, float *rotation)
  {
    return m_loc[0]->Nozzle (m_loc,(ILxUnknownID)toolVector,strength,size,rotation);
  }
};

class CLxLoc_RaycastPacket2 : public CLxLocalize<ILxRaycastPacket2ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_RaycastPacket2() {_init();}
  CLxLoc_RaycastPacket2(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_RaycastPacket2(const CLxLoc_RaycastPacket2 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_RaycastPacket2;}
    int
  HitPolygon (ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitPolygon *hit)
  {
    return m_loc[0]->HitPolygon (m_loc,(ILxUnknownID)toolVector,layer,x,y,hit);
  }
    int
  HitEdge (ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitEdge *hit)
  {
    return m_loc[0]->HitEdge (m_loc,(ILxUnknownID)toolVector,layer,x,y,hit);
  }
    int
  HitVertex (ILxUnknownID toolVector, unsigned layer, float x, float y, LXtHitVertex *hit)
  {
    return m_loc[0]->HitVertex (m_loc,(ILxUnknownID)toolVector,layer,x,y,hit);
  }
    int
  HitItem (ILxUnknownID toolVector, float x, float y, LXtHitItem *hit)
  {
    return m_loc[0]->HitItem (m_loc,(ILxUnknownID)toolVector,x,y,hit);
  }
};

class CLxLoc_PaintBrushPacket : public CLxLocalize<ILxPaintBrushPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PaintBrushPacket() {_init();}
  CLxLoc_PaintBrushPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PaintBrushPacket(const CLxLoc_PaintBrushPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PaintBrushPacket;}
    int
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    float
  Size (void)
  {
    return m_loc[0]->Size (m_loc);
  }
    int
  BBox (ILxUnknownID toolVector, const LXtVector center, double size, LXtBBox *bbox)
  {
    return m_loc[0]->BBox (m_loc,(ILxUnknownID)toolVector,center,size,bbox);
  }
    int
  Eval2D (ILxUnknownID toolVector, float multiplier, LXtPaintBrush *brush)
  {
    return m_loc[0]->Eval2D (m_loc,(ILxUnknownID)toolVector,multiplier,brush);
  }
    double
  Eval3D (ILxUnknownID toolVector, const LXtVector center, const LXtVector wpos, const LXtVector bpos, double rad, float *rgba)
  {
    return m_loc[0]->Eval3D (m_loc,(ILxUnknownID)toolVector,center,wpos,bpos,rad,rgba);
  }
};

#endif

