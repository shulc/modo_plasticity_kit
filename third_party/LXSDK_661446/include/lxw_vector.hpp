/*
 * C++ wrapper for lxvector.h
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
#ifndef LXW_VECTOR_HPP
#define LXW_VECTOR_HPP

#include <lxvector.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_PacketService = {0x2B8D8867,0x4EFC,0x4A1D,0x8F,0x6A,0xB5,0xF1,0x03,0xA9,0x0A,0x9B};
    static const LXtGUID guid_VectorType = {0x791B288F,0xDD69,0x11D7,0x85,0x7A,0x00,0x0A,0x95,0x93,0xD7,0x16};
    static const LXtGUID guid_VectorPacket1 = {0xF74C2B0E,0x4BC5,0x4E76,0x8F,0x7D,0x1D,0x64,0xDA,0x86,0xFD,0x28};
    static const LXtGUID guid_VectorPacket = {0xDDD79825,0x3E2F,0x4A6B,0xA2,0x7A,0xB0,0xB2,0xC6,0xFB,0x81,0x1C};
    static const LXtGUID guid_VectorStack = {0x7915D133,0x4272,0x498B,0xA6,0x91,0xC9,0x81,0x18,0xF4,0x0F,0xD5};
    static const LXtGUID guid_VectorList = {0xF091C272,0xC770,0x42C3,0xB3,0x14,0x62,0xEE,0x90,0xD3,0x4C,0x57};
    static const LXtGUID guid_PacketEffect = {0x7e8a37ce,0x618b,0x4ae4,0xa4,0x29,0x01,0x31,0x7a,0xc4,0x0e,0xb0};
    static const LXtGUID guid_TextureEffect = {0xCA13032E,0x3855,0x4744,0xB7,0x7A,0x59,0x53,0x0E,0xC3,0xE2,0x60};
};

class CLxLoc_PacketService : public CLxLocalizedService
{
public:
  ILxPacketServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_PacketService() {_init();set();}
 ~CLxLoc_PacketService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxPacketServiceID>(lx::GetGlobal(&lx::guid_PacketService));}
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
  Lookup (const char *category, const char *name, unsigned int *offset)
  {
    return m_loc[0]->Lookup (m_loc,category,name,offset);
  }
    LxResult
  Name (const char *category, unsigned int offset, const char **name)
  {
    return m_loc[0]->Name (m_loc,category,offset,name);
  }
    void *
  FastPacket (ILxUnknownID vector, unsigned int offset)
  {
    return m_loc[0]->FastPacket (m_loc,(ILxUnknownID)vector,offset);
  }
    LxResult
  CreateVectorType (const char *category, void **ppvObj)
  {
    return m_loc[0]->CreateVectorType (m_loc,category,ppvObj);
  }
    CLxResult
  CreateVectorType (const char *category, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateVectorType(m_loc,category,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AddPacket (ILxUnknownID vtype, const char *name, unsigned int flags)
  {
    return m_loc[0]->AddPacket (m_loc,(ILxUnknownID)vtype,name,flags);
  }
};

class CLxLoc_VectorType : public CLxLocalize<ILxVectorTypeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VectorType() {_init();}
  CLxLoc_VectorType(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VectorType(const CLxLoc_VectorType &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VectorType;}
    const char *
  Category (void)
  {
    return m_loc[0]->Category (m_loc);
  }
    unsigned int
  Test (unsigned int offset)
  {
    return m_loc[0]->Test (m_loc,offset);
  }
    unsigned int
  Count (unsigned int type)
  {
    return m_loc[0]->Count (m_loc,type);
  }
    unsigned int
  ByIndex (unsigned int type, unsigned int index, unsigned int *flags)
  {
    return m_loc[0]->ByIndex (m_loc,type,index,flags);
  }
};

class CLxImpl_VectorPacket1 {
  public:
    virtual ~CLxImpl_VectorPacket1() {}
    virtual unsigned int
      vpkt_Size (void)
        = 0;
    virtual const LXtGUID *
      vpkt_Interface (void)
        = 0;
    virtual LxResult
      vpkt_Initialize (void *packet)
        { return LXe_NOTIMPL; }
    virtual void
      vpkt_Reset (void *packet)
        { }
    virtual LxResult
      vpkt_Copy (void *packet, void *from)
        { return LXe_NOTIMPL; }
    virtual void
      vpkt_Cleanup (void *packet)
        { }
    virtual LxResult
      vpkt_Save (void *packet, unsigned int n, ILxUnknownID writestream)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vpkt_Load (void *packet, unsigned int n, ILxUnknownID readstream)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vpkt_Interpolate (void *packet, void *p0, void *p1, float t)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vpkt_Blend (void *packet, void *p0, void *p1, float t, int mode)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vpkt_Invert (void *packet)
        { return LXe_NOTIMPL; }
};
#define LXxD_VectorPacket1_Size unsigned int vpkt_Size (void)
#define LXxO_VectorPacket1_Size LXxD_VectorPacket1_Size LXx_OVERRIDE
#define LXxC_VectorPacket1_Size(c) unsigned int c::vpkt_Size (void)
#define LXxD_VectorPacket1_Interface const LXtGUID * vpkt_Interface (void)
#define LXxO_VectorPacket1_Interface LXxD_VectorPacket1_Interface LXx_OVERRIDE
#define LXxC_VectorPacket1_Interface(c) const LXtGUID * c::vpkt_Interface (void)
#define LXxD_VectorPacket1_Initialize LxResult vpkt_Initialize (void *packet)
#define LXxO_VectorPacket1_Initialize LXxD_VectorPacket1_Initialize LXx_OVERRIDE
#define LXxC_VectorPacket1_Initialize(c) LxResult c::vpkt_Initialize (void *packet)
#define LXxD_VectorPacket1_Reset void vpkt_Reset (void *packet)
#define LXxO_VectorPacket1_Reset LXxD_VectorPacket1_Reset LXx_OVERRIDE
#define LXxC_VectorPacket1_Reset(c) void c::vpkt_Reset (void *packet)
#define LXxD_VectorPacket1_Copy LxResult vpkt_Copy (void *packet, void *from)
#define LXxO_VectorPacket1_Copy LXxD_VectorPacket1_Copy LXx_OVERRIDE
#define LXxC_VectorPacket1_Copy(c) LxResult c::vpkt_Copy (void *packet, void *from)
#define LXxD_VectorPacket1_Cleanup void vpkt_Cleanup (void *packet)
#define LXxO_VectorPacket1_Cleanup LXxD_VectorPacket1_Cleanup LXx_OVERRIDE
#define LXxC_VectorPacket1_Cleanup(c) void c::vpkt_Cleanup (void *packet)
#define LXxD_VectorPacket1_Save LxResult vpkt_Save (void *packet, unsigned int n, ILxUnknownID writestream)
#define LXxO_VectorPacket1_Save LXxD_VectorPacket1_Save LXx_OVERRIDE
#define LXxC_VectorPacket1_Save(c) LxResult c::vpkt_Save (void *packet, unsigned int n, ILxUnknownID writestream)
#define LXxD_VectorPacket1_Load LxResult vpkt_Load (void *packet, unsigned int n, ILxUnknownID readstream)
#define LXxO_VectorPacket1_Load LXxD_VectorPacket1_Load LXx_OVERRIDE
#define LXxC_VectorPacket1_Load(c) LxResult c::vpkt_Load (void *packet, unsigned int n, ILxUnknownID readstream)
#define LXxD_VectorPacket1_Interpolate LxResult vpkt_Interpolate (void *packet, void *p0, void *p1, float t)
#define LXxO_VectorPacket1_Interpolate LXxD_VectorPacket1_Interpolate LXx_OVERRIDE
#define LXxC_VectorPacket1_Interpolate(c) LxResult c::vpkt_Interpolate (void *packet, void *p0, void *p1, float t)
#define LXxD_VectorPacket1_Blend LxResult vpkt_Blend (void *packet, void *p0, void *p1, float t, int mode)
#define LXxO_VectorPacket1_Blend LXxD_VectorPacket1_Blend LXx_OVERRIDE
#define LXxC_VectorPacket1_Blend(c) LxResult c::vpkt_Blend (void *packet, void *p0, void *p1, float t, int mode)
#define LXxD_VectorPacket1_Invert LxResult vpkt_Invert (void *packet)
#define LXxO_VectorPacket1_Invert LXxD_VectorPacket1_Invert LXx_OVERRIDE
#define LXxC_VectorPacket1_Invert(c) LxResult c::vpkt_Invert (void *packet)
template <class T>
class CLxIfc_VectorPacket1 : public CLxInterface
{
    static unsigned int
  Size (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    return loc->vpkt_Size ();
  }
    static const LXtGUID *
  Interface (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    return loc->vpkt_Interface ();
  }
    static LxResult
  Initialize (LXtObjectID wcom, void *packet)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    try {
      return loc->vpkt_Initialize (packet);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Reset (LXtObjectID wcom, void *packet)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    loc->vpkt_Reset (packet);
  }
    static LxResult
  Copy (LXtObjectID wcom, void *packet, void *from)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    try {
      return loc->vpkt_Copy (packet,from);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *packet)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    loc->vpkt_Cleanup (packet);
  }
    static LxResult
  Save (LXtObjectID wcom, void *packet, unsigned int n, LXtObjectID writestream)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    try {
      return loc->vpkt_Save (packet,n,(ILxUnknownID)writestream);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Load (LXtObjectID wcom, void *packet, unsigned int n, LXtObjectID readstream)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    try {
      return loc->vpkt_Load (packet,n,(ILxUnknownID)readstream);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Interpolate (LXtObjectID wcom, void *packet, void *p0, void *p1, float t)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    try {
      return loc->vpkt_Interpolate (packet,p0,p1,t);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Blend (LXtObjectID wcom, void *packet, void *p0, void *p1, float t, int mode)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    try {
      return loc->vpkt_Blend (packet,p0,p1,t,mode);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Invert (LXtObjectID wcom, void *packet)
  {
    LXCWxINST (CLxImpl_VectorPacket1, loc);
    try {
      return loc->vpkt_Invert (packet);
    } catch (LxResult rc) { return rc; }
  }
  ILxVectorPacket1 vt;
public:
  CLxIfc_VectorPacket1 ()
  {
    vt.Size = Size;
    vt.Interface = Interface;
    vt.Initialize = Initialize;
    vt.Reset = Reset;
    vt.Copy = Copy;
    vt.Cleanup = Cleanup;
    vt.Save = Save;
    vt.Load = Load;
    vt.Interpolate = Interpolate;
    vt.Blend = Blend;
    vt.Invert = Invert;
    vTable = &vt.iunk;
    iid = &lx::guid_VectorPacket1;
  }
};

class CLxImpl_VectorPacket {
  public:
    virtual ~CLxImpl_VectorPacket() {}
    virtual unsigned int
      vpkt_Size (void)
        = 0;
    virtual const LXtGUID *
      vpkt_Interface (void)
        = 0;
    virtual LxResult
      vpkt_Initialize (void *packet)
        { return LXe_NOTIMPL; }
    virtual void
      vpkt_Reset (void *packet)
        { }
    virtual LxResult
      vpkt_Copy (void *packet, void *from)
        { return LXe_NOTIMPL; }
    virtual void
      vpkt_Cleanup (void *packet)
        { }
    virtual LxResult
      vpkt_Blend (void *packet, void *p0, void *p1, float t, int mode)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vpkt_Invert (void *packet)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      vpkt_NodeCount (void)
        { return 0; }
    virtual LxResult
      vpkt_NodeName (unsigned int index, const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vpkt_NodeType (unsigned int index, VPacketPubType *dataType, unsigned int *count, const char **exoType, const char **vecType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vpkt_NodeGet (unsigned int index, void *packet, void **data)
        { return LXe_NOTIMPL; }
};
#define LXxD_VectorPacket_Size unsigned int vpkt_Size (void)
#define LXxO_VectorPacket_Size LXxD_VectorPacket_Size LXx_OVERRIDE
#define LXxC_VectorPacket_Size(c) unsigned int c::vpkt_Size (void)
#define LXxD_VectorPacket_Interface const LXtGUID * vpkt_Interface (void)
#define LXxO_VectorPacket_Interface LXxD_VectorPacket_Interface LXx_OVERRIDE
#define LXxC_VectorPacket_Interface(c) const LXtGUID * c::vpkt_Interface (void)
#define LXxD_VectorPacket_Initialize LxResult vpkt_Initialize (void *packet)
#define LXxO_VectorPacket_Initialize LXxD_VectorPacket_Initialize LXx_OVERRIDE
#define LXxC_VectorPacket_Initialize(c) LxResult c::vpkt_Initialize (void *packet)
#define LXxD_VectorPacket_Reset void vpkt_Reset (void *packet)
#define LXxO_VectorPacket_Reset LXxD_VectorPacket_Reset LXx_OVERRIDE
#define LXxC_VectorPacket_Reset(c) void c::vpkt_Reset (void *packet)
#define LXxD_VectorPacket_Copy LxResult vpkt_Copy (void *packet, void *from)
#define LXxO_VectorPacket_Copy LXxD_VectorPacket_Copy LXx_OVERRIDE
#define LXxC_VectorPacket_Copy(c) LxResult c::vpkt_Copy (void *packet, void *from)
#define LXxD_VectorPacket_Cleanup void vpkt_Cleanup (void *packet)
#define LXxO_VectorPacket_Cleanup LXxD_VectorPacket_Cleanup LXx_OVERRIDE
#define LXxC_VectorPacket_Cleanup(c) void c::vpkt_Cleanup (void *packet)
#define LXxD_VectorPacket_Blend LxResult vpkt_Blend (void *packet, void *p0, void *p1, float t, int mode)
#define LXxO_VectorPacket_Blend LXxD_VectorPacket_Blend LXx_OVERRIDE
#define LXxC_VectorPacket_Blend(c) LxResult c::vpkt_Blend (void *packet, void *p0, void *p1, float t, int mode)
#define LXxD_VectorPacket_Invert LxResult vpkt_Invert (void *packet)
#define LXxO_VectorPacket_Invert LXxD_VectorPacket_Invert LXx_OVERRIDE
#define LXxC_VectorPacket_Invert(c) LxResult c::vpkt_Invert (void *packet)
#define LXxD_VectorPacket_NodeCount unsigned int vpkt_NodeCount (void)
#define LXxO_VectorPacket_NodeCount LXxD_VectorPacket_NodeCount LXx_OVERRIDE
#define LXxC_VectorPacket_NodeCount(c) unsigned int c::vpkt_NodeCount (void)
#define LXxD_VectorPacket_NodeName LxResult vpkt_NodeName (unsigned int index, const char **name)
#define LXxO_VectorPacket_NodeName LXxD_VectorPacket_NodeName LXx_OVERRIDE
#define LXxC_VectorPacket_NodeName(c) LxResult c::vpkt_NodeName (unsigned int index, const char **name)
#define LXxD_VectorPacket_NodeType LxResult vpkt_NodeType (unsigned int index, VPacketPubType *dataType, unsigned int *count, const char **exoType, const char **vecType)
#define LXxO_VectorPacket_NodeType LXxD_VectorPacket_NodeType LXx_OVERRIDE
#define LXxC_VectorPacket_NodeType(c) LxResult c::vpkt_NodeType (unsigned int index, VPacketPubType *dataType, unsigned int *count, const char **exoType, const char **vecType)
#define LXxD_VectorPacket_NodeGet LxResult vpkt_NodeGet (unsigned int index, void *packet, void **data)
#define LXxO_VectorPacket_NodeGet LXxD_VectorPacket_NodeGet LXx_OVERRIDE
#define LXxC_VectorPacket_NodeGet(c) LxResult c::vpkt_NodeGet (unsigned int index, void *packet, void **data)
template <class T>
class CLxIfc_VectorPacket : public CLxInterface
{
    static unsigned int
  Size (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    return loc->vpkt_Size ();
  }
    static const LXtGUID *
  Interface (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    return loc->vpkt_Interface ();
  }
    static LxResult
  Initialize (LXtObjectID wcom, void *packet)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    try {
      return loc->vpkt_Initialize (packet);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Reset (LXtObjectID wcom, void *packet)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    loc->vpkt_Reset (packet);
  }
    static LxResult
  Copy (LXtObjectID wcom, void *packet, void *from)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    try {
      return loc->vpkt_Copy (packet,from);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *packet)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    loc->vpkt_Cleanup (packet);
  }
    static LxResult
  Blend (LXtObjectID wcom, void *packet, void *p0, void *p1, float t, int mode)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    try {
      return loc->vpkt_Blend (packet,p0,p1,t,mode);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Invert (LXtObjectID wcom, void *packet)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    try {
      return loc->vpkt_Invert (packet);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  NodeCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    return loc->vpkt_NodeCount ();
  }
    static LxResult
  NodeName (LXtObjectID wcom, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    try {
      return loc->vpkt_NodeName (index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NodeType (LXtObjectID wcom, unsigned int index, VPacketPubType *dataType, unsigned int *count, const char **exoType, const char **vecType)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    try {
      return loc->vpkt_NodeType (index,dataType,count,exoType,vecType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NodeGet (LXtObjectID wcom, unsigned int index, void *packet, void **data)
  {
    LXCWxINST (CLxImpl_VectorPacket, loc);
    try {
      return loc->vpkt_NodeGet (index,packet,data);
    } catch (LxResult rc) { return rc; }
  }
  ILxVectorPacket vt;
public:
  CLxIfc_VectorPacket ()
  {
    vt.Size = Size;
    vt.Interface = Interface;
    vt.Initialize = Initialize;
    vt.Reset = Reset;
    vt.Copy = Copy;
    vt.Cleanup = Cleanup;
    vt.Blend = Blend;
    vt.Invert = Invert;
    vt.NodeCount = NodeCount;
    vt.NodeName = NodeName;
    vt.NodeType = NodeType;
    vt.NodeGet = NodeGet;
    vTable = &vt.iunk;
    iid = &lx::guid_VectorPacket;
  }
};

class CLxLoc_VectorStack : public CLxLocalize<ILxVectorStackID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VectorStack() {_init();}
  CLxLoc_VectorStack(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VectorStack(const CLxLoc_VectorStack &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VectorStack;}
    void *
  Optional (unsigned int offset)
  {
    return m_loc[0]->Optional (m_loc,offset);
  }
    LxResult
  Readable (unsigned int offset, void **packet)
  {
    return m_loc[0]->Readable (m_loc,offset,packet);
  }
    LxResult
  Writable (unsigned int offset, void **packet)
  {
    return m_loc[0]->Writable (m_loc,offset,packet);
  }
    LxResult
  SetPacket (unsigned int offset, void *pdat)
  {
    return m_loc[0]->SetPacket (m_loc,offset,pdat);
  }
    LxResult
  Push (void)
  {
    return m_loc[0]->Push (m_loc);
  }
    LxResult
  Pop (void)
  {
    return m_loc[0]->Pop (m_loc);
  }
};

class CLxLoc_VectorList : public CLxLocalize<ILxVectorListID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VectorList() {_init();}
  CLxLoc_VectorList(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VectorList(const CLxLoc_VectorList &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VectorList;}
    void *
  Optional (unsigned int offset)
  {
    return m_loc[0]->Optional (m_loc,offset);
  }
    LxResult
  Readable (unsigned int offset, void **packet)
  {
    return m_loc[0]->Readable (m_loc,offset,packet);
  }
    LxResult
  Writable (unsigned int offset, void **packet)
  {
    return m_loc[0]->Writable (m_loc,offset,packet);
  }
    LxResult
  SetPacket (unsigned int offset, void *pdat)
  {
    return m_loc[0]->SetPacket (m_loc,offset,pdat);
  }
    LxResult
  Append (unsigned int *index)
  {
    return m_loc[0]->Append (m_loc,index);
  }
    unsigned int
  Current (void)
  {
    return m_loc[0]->Current (m_loc);
  }
    LxResult
  SetCurrent (unsigned int index)
  {
    return m_loc[0]->SetCurrent (m_loc,index);
  }
    unsigned int
  Count (void)
  {
    return m_loc[0]->Count (m_loc);
  }
    void
  Clear (void)
  {
    m_loc[0]->Clear (m_loc);
  }
};

class CLxImpl_PacketEffect {
  public:
    virtual ~CLxImpl_PacketEffect() {}
    virtual LxResult
      pfx_Packet (const char **packet)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      pfx_Count (void)
        = 0;
    virtual LxResult
      pfx_ByIndex (int index, const char **name, const char **typeName, int *type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pfx_Get (int index, void *packet, float *val, void *item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pfx_Set (int index, void *packet, const float *val, void *item)
        { return LXe_NOTIMPL; }
};
#define LXxD_PacketEffect_Packet LxResult pfx_Packet (const char **packet)
#define LXxO_PacketEffect_Packet LXxD_PacketEffect_Packet LXx_OVERRIDE
#define LXxC_PacketEffect_Packet(c) LxResult c::pfx_Packet (const char **packet)
#define LXxD_PacketEffect_Count unsigned int pfx_Count (void)
#define LXxO_PacketEffect_Count LXxD_PacketEffect_Count LXx_OVERRIDE
#define LXxC_PacketEffect_Count(c) unsigned int c::pfx_Count (void)
#define LXxD_PacketEffect_ByIndex LxResult pfx_ByIndex (int index, const char **name, const char **typeName, int *type)
#define LXxO_PacketEffect_ByIndex LXxD_PacketEffect_ByIndex LXx_OVERRIDE
#define LXxC_PacketEffect_ByIndex(c) LxResult c::pfx_ByIndex (int index, const char **name, const char **typeName, int *type)
#define LXxD_PacketEffect_Get LxResult pfx_Get (int index, void *packet, float *val, void *item)
#define LXxO_PacketEffect_Get LXxD_PacketEffect_Get LXx_OVERRIDE
#define LXxC_PacketEffect_Get(c) LxResult c::pfx_Get (int index, void *packet, float *val, void *item)
#define LXxD_PacketEffect_Set LxResult pfx_Set (int index, void *packet, const float *val, void *item)
#define LXxO_PacketEffect_Set LXxD_PacketEffect_Set LXx_OVERRIDE
#define LXxC_PacketEffect_Set(c) LxResult c::pfx_Set (int index, void *packet, const float *val, void *item)
template <class T>
class CLxIfc_PacketEffect : public CLxInterface
{
    static LxResult
  Packet (LXtObjectID wcom, const char **packet)
  {
    LXCWxINST (CLxImpl_PacketEffect, loc);
    try {
      return loc->pfx_Packet (packet);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PacketEffect, loc);
    return loc->pfx_Count ();
  }
    static LxResult
  ByIndex (LXtObjectID wcom, int index, const char **name, const char **typeName, int *type)
  {
    LXCWxINST (CLxImpl_PacketEffect, loc);
    try {
      return loc->pfx_ByIndex (index,name,typeName,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Get (LXtObjectID wcom, int index, void *packet, float *val, void *item)
  {
    LXCWxINST (CLxImpl_PacketEffect, loc);
    try {
      return loc->pfx_Get (index,packet,val,item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Set (LXtObjectID wcom, int index, void *packet, const float *val, void *item)
  {
    LXCWxINST (CLxImpl_PacketEffect, loc);
    try {
      return loc->pfx_Set (index,packet,val,item);
    } catch (LxResult rc) { return rc; }
  }
  ILxPacketEffect vt;
public:
  CLxIfc_PacketEffect ()
  {
    vt.Packet = Packet;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vt.Get = Get;
    vt.Set = Set;
    vTable = &vt.iunk;
    iid = &lx::guid_PacketEffect;
  }
};
class CLxLoc_PacketEffect : public CLxLocalize<ILxPacketEffectID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PacketEffect() {_init();}
  CLxLoc_PacketEffect(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PacketEffect(const CLxLoc_PacketEffect &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PacketEffect;}
    LxResult
  Packet (const char **packet)
  {
    return m_loc[0]->Packet (m_loc,packet);
  }
    unsigned int
  Count (void)
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  ByIndex (int index, const char **name, const char **typeName, int *type)
  {
    return m_loc[0]->ByIndex (m_loc,index,name,typeName,type);
  }
    LxResult
  Get (int index, void *packet, float *val, void *item)
  {
    return m_loc[0]->Get (m_loc,index,packet,val,item);
  }
    LxResult
  Set (int index, void *packet, const float *val, void *item)
  {
    return m_loc[0]->Set (m_loc,index,packet,val,item);
  }
};

class CLxImpl_TextureEffect {
  public:
    virtual ~CLxImpl_TextureEffect() {}
    virtual unsigned int
      tfx_Type (void)
        = 0;
    virtual const char *
      tfx_TypeName (void)
        = 0;
    virtual LxResult
      tfx_Get (ILxUnknownID sv, float *val, void *item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tfx_Set (ILxUnknownID sv, const float *val, void *item)
        { return LXe_NOTIMPL; }
};
#define LXxD_TextureEffect_Type unsigned int tfx_Type (void)
#define LXxO_TextureEffect_Type LXxD_TextureEffect_Type LXx_OVERRIDE
#define LXxC_TextureEffect_Type(c) unsigned int c::tfx_Type (void)
#define LXxD_TextureEffect_TypeName const char * tfx_TypeName (void)
#define LXxO_TextureEffect_TypeName LXxD_TextureEffect_TypeName LXx_OVERRIDE
#define LXxC_TextureEffect_TypeName(c) const char * c::tfx_TypeName (void)
#define LXxD_TextureEffect_Get LxResult tfx_Get (ILxUnknownID sv, float *val, void *item)
#define LXxO_TextureEffect_Get LXxD_TextureEffect_Get LXx_OVERRIDE
#define LXxC_TextureEffect_Get(c) LxResult c::tfx_Get (ILxUnknownID sv, float *val, void *item)
#define LXxD_TextureEffect_Set LxResult tfx_Set (ILxUnknownID sv, const float *val, void *item)
#define LXxO_TextureEffect_Set LXxD_TextureEffect_Set LXx_OVERRIDE
#define LXxC_TextureEffect_Set(c) LxResult c::tfx_Set (ILxUnknownID sv, const float *val, void *item)
template <class T>
class CLxIfc_TextureEffect : public CLxInterface
{
    static unsigned int
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TextureEffect, loc);
    return loc->tfx_Type ();
  }
    static const char *
  TypeName (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TextureEffect, loc);
    return loc->tfx_TypeName ();
  }
    static LxResult
  Get (LXtObjectID wcom, LXtObjectID sv, float *val, void *item)
  {
    LXCWxINST (CLxImpl_TextureEffect, loc);
    try {
      return loc->tfx_Get ((ILxUnknownID)sv,val,item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Set (LXtObjectID wcom, LXtObjectID sv, const float *val, void *item)
  {
    LXCWxINST (CLxImpl_TextureEffect, loc);
    try {
      return loc->tfx_Set ((ILxUnknownID)sv,val,item);
    } catch (LxResult rc) { return rc; }
  }
  ILxTextureEffect vt;
public:
  CLxIfc_TextureEffect ()
  {
    vt.Type = Type;
    vt.TypeName = TypeName;
    vt.Get = Get;
    vt.Set = Set;
    vTable = &vt.iunk;
    iid = &lx::guid_TextureEffect;
  }
};
class CLxLoc_TextureEffect : public CLxLocalize<ILxTextureEffectID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TextureEffect() {_init();}
  CLxLoc_TextureEffect(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TextureEffect(const CLxLoc_TextureEffect &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TextureEffect;}
    unsigned int
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    const char *
  TypeName (void)
  {
    return m_loc[0]->TypeName (m_loc);
  }
    LxResult
  Get (ILxUnknownID sv, float *val, void *item)
  {
    return m_loc[0]->Get (m_loc,(ILxUnknownID)sv,val,item);
  }
    LxResult
  Set (ILxUnknownID sv, const float *val, void *item)
  {
    return m_loc[0]->Set (m_loc,(ILxUnknownID)sv,val,item);
  }
};

#endif

