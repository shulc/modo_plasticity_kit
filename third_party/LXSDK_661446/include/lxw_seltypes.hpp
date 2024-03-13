/*
 * C++ wrapper for lxseltypes.h
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
#ifndef LXW_SELTYPES_HPP
#define LXW_SELTYPES_HPP

#include <lxseltypes.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_VMapPacketTranslation = {0xBBCB6B90,0x9586,0x11D9,0xA3,0xB8,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_VertexPacketTranslation = {0xD77B8382,0x9572,0x11D9,0xAF,0xDE,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_PivotPacketTranslation = {0x9744D68E,0xD6CD,0x4652,0xAD,0x33,0x07,0x3A,0x24,0xE1,0x69,0x01};
    static const LXtGUID guid_ChannelPacketTranslation = {0x00DE9D39,0x6A83,0x46DC,0x9C,0x28,0x36,0x06,0x62,0x92,0x2C,0xE5};
    static const LXtGUID guid_EdgePacketTranslation = {0xCA4DFE14,0x957E,0x11D9,0xAC,0x64,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_PresetPathPacketTranslation = {0x6b95c2ac,0x9a9e,0x471f,0x97,0x71,0xcf,0x10,0xfd,0x5c,0x6b,0xcb};
    static const LXtGUID guid_CenterPacketTranslation = {0x52B10EAB,0x9EA6,0x4F28,0x81,0xD1,0x2F,0xEC,0x51,0xE0,0x29,0x33};
    static const LXtGUID guid_VectorKnotPacketTranslation = {0xF4DDFFEA,0x3077,0x4931,0x83,0x84,0x81,0xC4,0x9A,0xD1,0xC4,0x1C};
    static const LXtGUID guid_VectorPathPacketTranslation = {0xC3E6DF29,0x7217,0x4D89,0x9E,0x84,0xDA,0x6D,0x45,0xB9,0x39,0x6E};
    static const LXtGUID guid_LinkPacketTranslation = {0xEEA9F625,0xEB3C,0x43FD,0xA1,0x56,0xC8,0x55,0x2D,0x6D,0x18,0xC9};
    static const LXtGUID guid_ItemChannel = {0x3cfab0aa,0x8e8c,0x452c,0x81,0xe5,0x27,0x28,0x42,0xff,0xf9,0x35};
    static const LXtGUID guid_ActionLayerPacketTranslation = {0xE685D569,0x1C0F,0x4E8A,0x94,0xA9,0x4F,0xC2,0x94,0x53,0x68,0x9F};
    static const LXtGUID guid_ItemPacketTranslation = {0x029663CC,0x9571,0x11D9,0xB9,0xAD,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_NodePacketTranslation = {0x5A560F1B,0xDC73,0x4efb,0x85,0x79,0xC6,0xC7,0xD9,0x37,0x3C,0x60};
    static const LXtGUID guid_VectorShapePacketTranslation = {0x33C886D1,0x1574,0x4D8E,0x9D,0xFD,0xD8,0xD1,0xCB,0x7A,0x21,0xFE};
    static const LXtGUID guid_ScenePacketTranslation = {0xA63F8E08,0x94D8,0x11D9,0x96,0xD3,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_PolygonPacketTranslation = {0x2E0929DC,0x9583,0x11D9,0xB0,0x58,0x00,0x0A,0x95,0x6C,0x2E,0x10};
};

class CLxLoc_VMapPacketTranslation : public CLxLocalize<ILxVMapPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VMapPacketTranslation() {_init();}
  CLxLoc_VMapPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VMapPacketTranslation(const CLxLoc_VMapPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VMapPacketTranslation;}
    LxResult
  Name (void *packet, const char **name)
  {
    return m_loc[0]->Name (m_loc,packet,name);
  }
    LxResult
  Type (void *packet, LXtID4 *type)
  {
    return m_loc[0]->Type (m_loc,packet,type);
  }
    void *
  Packet (LXtID4 type, const char *name)
  {
    return m_loc[0]->Packet (m_loc,type,name);
  }
};

class CLxLoc_VertexPacketTranslation : public CLxLocalize<ILxVertexPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VertexPacketTranslation() {_init();}
  CLxLoc_VertexPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VertexPacketTranslation(const CLxLoc_VertexPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VertexPacketTranslation;}
    LxResult
  Vertex (void *packet, LXtPointID *vertex)
  {
    return m_loc[0]->Vertex (m_loc,packet,vertex);
  }
    LxResult
  Polygon (void *packet, LXtPolygonID *polygon)
  {
    return m_loc[0]->Polygon (m_loc,packet,polygon);
  }
    LxResult
  Mesh (void *packet, void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,packet,ppvObj);
  }
    CLxResult
  Mesh (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Mesh(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (LXtPointID vertex, LXtPolygonID polygon, ILxUnknownID mesh)
  {
    return m_loc[0]->Packet (m_loc,vertex,polygon,(ILxUnknownID)mesh);
  }
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_PivotPacketTranslation : public CLxLocalize<ILxPivotPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PivotPacketTranslation() {_init();}
  CLxLoc_PivotPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PivotPacketTranslation(const CLxLoc_PivotPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PivotPacketTranslation;}
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned int
  Type (void *packet)
  {
    return m_loc[0]->Type (m_loc,packet);
  }
    void *
  Packet (ILxUnknownID item, unsigned int type)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)item,type);
  }
};

class CLxLoc_ChannelPacketTranslation : public CLxLocalize<ILxChannelPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelPacketTranslation() {_init();}
  CLxLoc_ChannelPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelPacketTranslation(const CLxLoc_ChannelPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelPacketTranslation;}
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned int
  Index (void *packet)
  {
    return m_loc[0]->Index (m_loc,packet);
  }
    void *
  Packet (ILxUnknownID item, unsigned int index)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)item,index);
  }
};

class CLxLoc_EdgePacketTranslation : public CLxLocalize<ILxEdgePacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_EdgePacketTranslation() {_init();}
  CLxLoc_EdgePacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_EdgePacketTranslation(const CLxLoc_EdgePacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_EdgePacketTranslation;}
    LxResult
  Vertices (void *packet, LXtPointID *vertexA, LXtPointID *vertexB)
  {
    return m_loc[0]->Vertices (m_loc,packet,vertexA,vertexB);
  }
    LxResult
  Polygon (void *packet, LXtPolygonID *polygon)
  {
    return m_loc[0]->Polygon (m_loc,packet,polygon);
  }
    LxResult
  Mesh (void *packet, void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,packet,ppvObj);
  }
    CLxResult
  Mesh (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Mesh(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (LXtPointID vertexA, LXtPointID vertexB, LXtPolygonID polygon, ILxUnknownID mesh)
  {
    return m_loc[0]->Packet (m_loc,vertexA,vertexB,polygon,(ILxUnknownID)mesh);
  }
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_PresetPathPacketTranslation : public CLxLocalize<ILxPresetPathPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PresetPathPacketTranslation() {_init();}
  CLxLoc_PresetPathPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PresetPathPacketTranslation(const CLxLoc_PresetPathPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PresetPathPacketTranslation;}
    LxResult
  Path (void *packet, const char **path)
  {
    return m_loc[0]->Path (m_loc,packet,path);
  }
    LxResult
  Identifier (void *packet, const char **identifier)
  {
    return m_loc[0]->Identifier (m_loc,packet,identifier);
  }
    void *
  Packet (const char *path, const char *identifier)
  {
    return m_loc[0]->Packet (m_loc,path,identifier);
  }
};

class CLxLoc_CenterPacketTranslation : public CLxLocalize<ILxCenterPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CenterPacketTranslation() {_init();}
  CLxLoc_CenterPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CenterPacketTranslation(const CLxLoc_CenterPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CenterPacketTranslation;}
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (ILxUnknownID item)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)item);
  }
};

class CLxImpl_VectorKnotPacketTranslation {
  public:
    virtual ~CLxImpl_VectorKnotPacketTranslation() {}
    virtual LxResult
      knottrans_Knot (void *packet, LXtVectorKnotID *knot)
        { return LXe_NOTIMPL; }
    virtual LxResult
      knottrans_Path (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      knottrans_Shape (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      knottrans_Canvas (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      knottrans_Item (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual void *
      knottrans_Packet (LXtVectorKnotID knot)
        = 0;
};
#define LXxD_VectorKnotPacketTranslation_Knot LxResult knottrans_Knot (void *packet, LXtVectorKnotID *knot)
#define LXxO_VectorKnotPacketTranslation_Knot LXxD_VectorKnotPacketTranslation_Knot LXx_OVERRIDE
#define LXxC_VectorKnotPacketTranslation_Knot(c) LxResult c::knottrans_Knot (void *packet, LXtVectorKnotID *knot)
#define LXxD_VectorKnotPacketTranslation_Path LxResult knottrans_Path (void *packet, void **ppvObj)
#define LXxO_VectorKnotPacketTranslation_Path LXxD_VectorKnotPacketTranslation_Path LXx_OVERRIDE
#define LXxC_VectorKnotPacketTranslation_Path(c) LxResult c::knottrans_Path (void *packet, void **ppvObj)
#define LXxD_VectorKnotPacketTranslation_Shape LxResult knottrans_Shape (void *packet, void **ppvObj)
#define LXxO_VectorKnotPacketTranslation_Shape LXxD_VectorKnotPacketTranslation_Shape LXx_OVERRIDE
#define LXxC_VectorKnotPacketTranslation_Shape(c) LxResult c::knottrans_Shape (void *packet, void **ppvObj)
#define LXxD_VectorKnotPacketTranslation_Canvas LxResult knottrans_Canvas (void *packet, void **ppvObj)
#define LXxO_VectorKnotPacketTranslation_Canvas LXxD_VectorKnotPacketTranslation_Canvas LXx_OVERRIDE
#define LXxC_VectorKnotPacketTranslation_Canvas(c) LxResult c::knottrans_Canvas (void *packet, void **ppvObj)
#define LXxD_VectorKnotPacketTranslation_Item LxResult knottrans_Item (void *packet, void **ppvObj)
#define LXxO_VectorKnotPacketTranslation_Item LXxD_VectorKnotPacketTranslation_Item LXx_OVERRIDE
#define LXxC_VectorKnotPacketTranslation_Item(c) LxResult c::knottrans_Item (void *packet, void **ppvObj)
#define LXxD_VectorKnotPacketTranslation_Packet void * knottrans_Packet (LXtVectorKnotID knot)
#define LXxO_VectorKnotPacketTranslation_Packet LXxD_VectorKnotPacketTranslation_Packet LXx_OVERRIDE
#define LXxC_VectorKnotPacketTranslation_Packet(c) void * c::knottrans_Packet (LXtVectorKnotID knot)
template <class T>
class CLxIfc_VectorKnotPacketTranslation : public CLxInterface
{
    static LxResult
  Knot (LXtObjectID wcom, void *packet, LXtVectorKnotID *knot)
  {
    LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
    try {
      return loc->knottrans_Knot (packet,knot);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Path (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
    try {
      return loc->knottrans_Path (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Shape (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
    try {
      return loc->knottrans_Shape (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Canvas (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
    try {
      return loc->knottrans_Canvas (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Item (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
    try {
      return loc->knottrans_Item (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static void *
  Packet (LXtObjectID wcom, LXtVectorKnotID knot)
  {
    LXCWxINST (CLxImpl_VectorKnotPacketTranslation, loc);
    return loc->knottrans_Packet (knot);
  }
  ILxVectorKnotPacketTranslation vt;
public:
  CLxIfc_VectorKnotPacketTranslation ()
  {
    vt.Knot = Knot;
    vt.Path = Path;
    vt.Shape = Shape;
    vt.Canvas = Canvas;
    vt.Item = Item;
    vt.Packet = Packet;
    vTable = &vt.iunk;
    iid = &lx::guid_VectorKnotPacketTranslation;
  }
};
class CLxLoc_VectorKnotPacketTranslation : public CLxLocalize<ILxVectorKnotPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VectorKnotPacketTranslation() {_init();}
  CLxLoc_VectorKnotPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VectorKnotPacketTranslation(const CLxLoc_VectorKnotPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VectorKnotPacketTranslation;}
    LxResult
  Knot (void *packet, LXtVectorKnotID *knot)
  {
    return m_loc[0]->Knot (m_loc,packet,knot);
  }
    LxResult
  Path (void *packet, void **ppvObj)
  {
    return m_loc[0]->Path (m_loc,packet,ppvObj);
  }
    CLxResult
  Path (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Path(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Shape (void *packet, void **ppvObj)
  {
    return m_loc[0]->Shape (m_loc,packet,ppvObj);
  }
    CLxResult
  Shape (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Shape(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Canvas (void *packet, void **ppvObj)
  {
    return m_loc[0]->Canvas (m_loc,packet,ppvObj);
  }
    CLxResult
  Canvas (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Canvas(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (LXtVectorKnotID knot)
  {
    return m_loc[0]->Packet (m_loc,knot);
  }
};

class CLxImpl_VectorPathPacketTranslation {
  public:
    virtual ~CLxImpl_VectorPathPacketTranslation() {}
    virtual LxResult
      pathtrans_Path (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pathtrans_Shape (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pathtrans_Canvas (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pathtrans_Item (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual void *
      pathtrans_Packet (ILxUnknownID path)
        = 0;
};
#define LXxD_VectorPathPacketTranslation_Path LxResult pathtrans_Path (void *packet, void **ppvObj)
#define LXxO_VectorPathPacketTranslation_Path LXxD_VectorPathPacketTranslation_Path LXx_OVERRIDE
#define LXxC_VectorPathPacketTranslation_Path(c) LxResult c::pathtrans_Path (void *packet, void **ppvObj)
#define LXxD_VectorPathPacketTranslation_Shape LxResult pathtrans_Shape (void *packet, void **ppvObj)
#define LXxO_VectorPathPacketTranslation_Shape LXxD_VectorPathPacketTranslation_Shape LXx_OVERRIDE
#define LXxC_VectorPathPacketTranslation_Shape(c) LxResult c::pathtrans_Shape (void *packet, void **ppvObj)
#define LXxD_VectorPathPacketTranslation_Canvas LxResult pathtrans_Canvas (void *packet, void **ppvObj)
#define LXxO_VectorPathPacketTranslation_Canvas LXxD_VectorPathPacketTranslation_Canvas LXx_OVERRIDE
#define LXxC_VectorPathPacketTranslation_Canvas(c) LxResult c::pathtrans_Canvas (void *packet, void **ppvObj)
#define LXxD_VectorPathPacketTranslation_Item LxResult pathtrans_Item (void *packet, void **ppvObj)
#define LXxO_VectorPathPacketTranslation_Item LXxD_VectorPathPacketTranslation_Item LXx_OVERRIDE
#define LXxC_VectorPathPacketTranslation_Item(c) LxResult c::pathtrans_Item (void *packet, void **ppvObj)
#define LXxD_VectorPathPacketTranslation_Packet void * pathtrans_Packet (ILxUnknownID path)
#define LXxO_VectorPathPacketTranslation_Packet LXxD_VectorPathPacketTranslation_Packet LXx_OVERRIDE
#define LXxC_VectorPathPacketTranslation_Packet(c) void * c::pathtrans_Packet (ILxUnknownID path)
template <class T>
class CLxIfc_VectorPathPacketTranslation : public CLxInterface
{
    static LxResult
  Path (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorPathPacketTranslation, loc);
    try {
      return loc->pathtrans_Path (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Shape (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorPathPacketTranslation, loc);
    try {
      return loc->pathtrans_Shape (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Canvas (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorPathPacketTranslation, loc);
    try {
      return loc->pathtrans_Canvas (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Item (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorPathPacketTranslation, loc);
    try {
      return loc->pathtrans_Item (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static void *
  Packet (LXtObjectID wcom, LXtObjectID path)
  {
    LXCWxINST (CLxImpl_VectorPathPacketTranslation, loc);
    return loc->pathtrans_Packet ((ILxUnknownID)path);
  }
  ILxVectorPathPacketTranslation vt;
public:
  CLxIfc_VectorPathPacketTranslation ()
  {
    vt.Path = Path;
    vt.Shape = Shape;
    vt.Canvas = Canvas;
    vt.Item = Item;
    vt.Packet = Packet;
    vTable = &vt.iunk;
    iid = &lx::guid_VectorPathPacketTranslation;
  }
};
class CLxLoc_VectorPathPacketTranslation : public CLxLocalize<ILxVectorPathPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VectorPathPacketTranslation() {_init();}
  CLxLoc_VectorPathPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VectorPathPacketTranslation(const CLxLoc_VectorPathPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VectorPathPacketTranslation;}
    LxResult
  Path (void *packet, void **ppvObj)
  {
    return m_loc[0]->Path (m_loc,packet,ppvObj);
  }
    CLxResult
  Path (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Path(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Shape (void *packet, void **ppvObj)
  {
    return m_loc[0]->Shape (m_loc,packet,ppvObj);
  }
    CLxResult
  Shape (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Shape(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Canvas (void *packet, void **ppvObj)
  {
    return m_loc[0]->Canvas (m_loc,packet,ppvObj);
  }
    CLxResult
  Canvas (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Canvas(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (ILxUnknownID path)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)path);
  }
};

class CLxLoc_LinkPacketTranslation : public CLxLocalize<ILxLinkPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LinkPacketTranslation() {_init();}
  CLxLoc_LinkPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LinkPacketTranslation(const CLxLoc_LinkPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LinkPacketTranslation;}
    LxResult
  From (void *packet, int *channel, void **ppvObj)
  {
    return m_loc[0]->From (m_loc,packet,channel,ppvObj);
  }
    CLxResult
  From (void *packet, int *channel, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->From(m_loc,packet,channel,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  To (void *packet, int *channel, void **ppvObj)
  {
    return m_loc[0]->To (m_loc,packet,channel,ppvObj);
  }
    CLxResult
  To (void *packet, int *channel, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->To(m_loc,packet,channel,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (ILxUnknownID fromItem, int fromChannel, ILxUnknownID toItem, int toChannel)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)fromItem,fromChannel,(ILxUnknownID)toItem,toChannel);
  }
};

class CLxLoc_ItemChannel : public CLxLocalize<ILxItemChannelID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemChannel() {_init();}
  CLxLoc_ItemChannel(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemChannel(const CLxLoc_ItemChannel &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemChannel;}
    LxResult
  Item (void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,ppvObj);
  }
    CLxResult
  Item (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned int
  ChannelIndex (void)
  {
    return m_loc[0]->ChannelIndex (m_loc);
  }
};

class CLxLoc_ActionLayerPacketTranslation : public CLxLocalize<ILxActionLayerPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ActionLayerPacketTranslation() {_init();}
  CLxLoc_ActionLayerPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ActionLayerPacketTranslation(const CLxLoc_ActionLayerPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ActionLayerPacketTranslation;}
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned int
  Index (void *packet)
  {
    return m_loc[0]->Index (m_loc,packet);
  }
    void *
  Packet (ILxUnknownID item, unsigned int index)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)item,index);
  }
};

class CLxLoc_ItemPacketTranslation : public CLxLocalize<ILxItemPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemPacketTranslation() {_init();}
  CLxLoc_ItemPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemPacketTranslation(const CLxLoc_ItemPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemPacketTranslation;}
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (ILxUnknownID item)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)item);
  }
};

class CLxLoc_NodePacketTranslation : public CLxLocalize<ILxNodePacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_NodePacketTranslation() {_init();}
  CLxLoc_NodePacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_NodePacketTranslation(const CLxLoc_NodePacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_NodePacketTranslation;}
    LxResult
  Node (void *packet, void **ppvObj)
  {
    return m_loc[0]->Node (m_loc,packet,ppvObj);
  }
    CLxResult
  Node (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Node(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (ILxUnknownID node)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)node);
  }
};

class CLxImpl_VectorShapePacketTranslation {
  public:
    virtual ~CLxImpl_VectorShapePacketTranslation() {}
    virtual LxResult
      shapetrans_Shape (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      shapetrans_Canvas (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      shapetrans_Item (void *packet, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual void *
      shapetrans_Packet (ILxUnknownID shape)
        = 0;
};
#define LXxD_VectorShapePacketTranslation_Shape LxResult shapetrans_Shape (void *packet, void **ppvObj)
#define LXxO_VectorShapePacketTranslation_Shape LXxD_VectorShapePacketTranslation_Shape LXx_OVERRIDE
#define LXxC_VectorShapePacketTranslation_Shape(c) LxResult c::shapetrans_Shape (void *packet, void **ppvObj)
#define LXxD_VectorShapePacketTranslation_Canvas LxResult shapetrans_Canvas (void *packet, void **ppvObj)
#define LXxO_VectorShapePacketTranslation_Canvas LXxD_VectorShapePacketTranslation_Canvas LXx_OVERRIDE
#define LXxC_VectorShapePacketTranslation_Canvas(c) LxResult c::shapetrans_Canvas (void *packet, void **ppvObj)
#define LXxD_VectorShapePacketTranslation_Item LxResult shapetrans_Item (void *packet, void **ppvObj)
#define LXxO_VectorShapePacketTranslation_Item LXxD_VectorShapePacketTranslation_Item LXx_OVERRIDE
#define LXxC_VectorShapePacketTranslation_Item(c) LxResult c::shapetrans_Item (void *packet, void **ppvObj)
#define LXxD_VectorShapePacketTranslation_Packet void * shapetrans_Packet (ILxUnknownID shape)
#define LXxO_VectorShapePacketTranslation_Packet LXxD_VectorShapePacketTranslation_Packet LXx_OVERRIDE
#define LXxC_VectorShapePacketTranslation_Packet(c) void * c::shapetrans_Packet (ILxUnknownID shape)
template <class T>
class CLxIfc_VectorShapePacketTranslation : public CLxInterface
{
    static LxResult
  Shape (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorShapePacketTranslation, loc);
    try {
      return loc->shapetrans_Shape (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Canvas (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorShapePacketTranslation, loc);
    try {
      return loc->shapetrans_Canvas (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Item (LXtObjectID wcom, void *packet, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VectorShapePacketTranslation, loc);
    try {
      return loc->shapetrans_Item (packet,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static void *
  Packet (LXtObjectID wcom, LXtObjectID shape)
  {
    LXCWxINST (CLxImpl_VectorShapePacketTranslation, loc);
    return loc->shapetrans_Packet ((ILxUnknownID)shape);
  }
  ILxVectorShapePacketTranslation vt;
public:
  CLxIfc_VectorShapePacketTranslation ()
  {
    vt.Shape = Shape;
    vt.Canvas = Canvas;
    vt.Item = Item;
    vt.Packet = Packet;
    vTable = &vt.iunk;
    iid = &lx::guid_VectorShapePacketTranslation;
  }
};
class CLxLoc_VectorShapePacketTranslation : public CLxLocalize<ILxVectorShapePacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VectorShapePacketTranslation() {_init();}
  CLxLoc_VectorShapePacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VectorShapePacketTranslation(const CLxLoc_VectorShapePacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VectorShapePacketTranslation;}
    LxResult
  Shape (void *packet, void **ppvObj)
  {
    return m_loc[0]->Shape (m_loc,packet,ppvObj);
  }
    CLxResult
  Shape (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Shape(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Canvas (void *packet, void **ppvObj)
  {
    return m_loc[0]->Canvas (m_loc,packet,ppvObj);
  }
    CLxResult
  Canvas (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Canvas(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (ILxUnknownID shape)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)shape);
  }
};

class CLxLoc_ScenePacketTranslation : public CLxLocalize<ILxScenePacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ScenePacketTranslation() {_init();}
  CLxLoc_ScenePacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ScenePacketTranslation(const CLxLoc_ScenePacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ScenePacketTranslation;}
    LxResult
  Scene (void *packet, void **ppvObj)
  {
    return m_loc[0]->Scene (m_loc,packet,ppvObj);
  }
    CLxResult
  Scene (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Scene(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (ILxUnknownID scene)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)scene);
  }
};

class CLxLoc_PolygonPacketTranslation : public CLxLocalize<ILxPolygonPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PolygonPacketTranslation() {_init();}
  CLxLoc_PolygonPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PolygonPacketTranslation(const CLxLoc_PolygonPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PolygonPacketTranslation;}
    LxResult
  Polygon (void *packet, LXtPolygonID *polygon)
  {
    return m_loc[0]->Polygon (m_loc,packet,polygon);
  }
    LxResult
  Mesh (void *packet, void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,packet,ppvObj);
  }
    CLxResult
  Mesh (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Mesh(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void *
  Packet (LXtPolygonID polygon, ILxUnknownID mesh)
  {
    return m_loc[0]->Packet (m_loc,polygon,(ILxUnknownID)mesh);
  }
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    CLxResult
  Item (void *packet, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,packet,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

