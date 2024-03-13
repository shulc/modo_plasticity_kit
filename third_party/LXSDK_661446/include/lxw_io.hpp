/*
 * C++ wrapper for lxio.h
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
#ifndef LXW_IO_HPP
#define LXW_IO_HPP

#include <lxio.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_IOService = {0x9970CCAD,0x7322,0x4CD6,0xA6,0xBA,0x96,0x3A,0x63,0xDE,0x57,0xD7};
    static const LXtGUID guid_BlockStore = {0x9094E95E,0xE91E,0x42AE,0xAB,0xD6,0x84,0x26,0xCC,0x0A,0xE4,0x2A};
    static const LXtGUID guid_LoaderInfo = {0x4CA8BE1A,0x6ADE,0x4F93,0x99,0xF6,0x1F,0x0E,0xFC,0x8A,0x58,0x1E};
    static const LXtGUID guid_BlockRead = {0x36A00A47,0x2664,0x49E0,0xBA,0xFF,0x26,0x3E,0x63,0x85,0x32,0xB5};
    static const LXtGUID guid_Loader = {0x7711F608,0xB8FF,0x48BF,0x81,0xED,0xCE,0xBD,0xE5,0x4D,0x34,0xDE};
    static const LXtGUID guid_BlockWrite = {0xADE569E1,0xE9A1,0x4AD6,0xB6,0x25,0x63,0x40,0x93,0x66,0x09,0x65};
    static const LXtGUID guid_Monitor = {0x2B514D4C,0x5142,0x4687,0xBC,0xEF,0xB0,0xFD,0x44,0xA3,0x31,0x46};
    static const LXtGUID guid_Saver = {0x75AD8F36,0x5B69,0x413b,0xA7,0x7B,0x5A,0x78,0xD3,0x9A,0xEF,0x51};
    static const LXtGUID guid_Loader1 = {0x73333A41,0x3C0A,0x4B0E,0xA7,0xC5,0xD7,0x66,0x09,0x82,0x7A,0x2D};
    static const LXtGUID guid_StreamIO = {0x2884D6EE,0x4BA7,0x46D6,0xA7,0x76,0x8E,0xE2,0x2C,0x9F,0xD4,0x14};
};

class CLxLoc_IOService : public CLxLocalizedService
{
public:
  ILxIOServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_IOService() {_init();set();}
 ~CLxLoc_IOService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxIOServiceID>(lx::GetGlobal(&lx::guid_IOService));}
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
  SetOptions (ILxUnknownID options)
  {
    return m_loc[0]->SetOptions (m_loc,(ILxUnknownID)options);
  }
    ILxUnknownID
  PeekOptions (void)
  {
    return (ILxUnknownID) m_loc[0]->PeekOptions (m_loc);
  }
    LxResult
  OpenBlockStore (const char *filename, const char *format, unsigned flags, void **ppvObj)
  {
    return m_loc[0]->OpenBlockStore (m_loc,filename,format,flags,ppvObj);
  }
    CLxResult
  OpenBlockStore (const char *filename, const char *format, unsigned flags, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->OpenBlockStore(m_loc,filename,format,flags,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_BlockStore : public CLxLocalize<ILxBlockStoreID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_BlockStore() {_init();}
  CLxLoc_BlockStore(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_BlockStore(const CLxLoc_BlockStore &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_BlockStore;}
    LxResult
  AllocBookmark (LXtBlockBookmarkID *loc)
  {
    return m_loc[0]->AllocBookmark (m_loc,loc);
  }
    LxResult
  Lookup (LXtID4 type, const char *id, LXtBlockBookmarkID parent)
  {
    return m_loc[0]->Lookup (m_loc,type,id,parent);
  }
    LxResult
  Stack (unsigned operation)
  {
    return m_loc[0]->Stack (m_loc,operation);
  }
    LxResult
  Count (LXtID4 type, unsigned *count, LXtBlockBookmarkID parent)
  {
    return m_loc[0]->Count (m_loc,type,count,parent);
  }
    LxResult
  ByIndex (LXtID4 type, unsigned index, LXtBlockBookmarkID parent)
  {
    return m_loc[0]->ByIndex (m_loc,type,index,parent);
  }
    LxResult
  RestoreBookmark (LXtBlockBookmarkID loc)
  {
    return m_loc[0]->RestoreBookmark (m_loc,loc);
  }
    LxResult
  SaveBookmark (LXtBlockBookmarkID loc)
  {
    return m_loc[0]->SaveBookmark (m_loc,loc);
  }
    LxResult
  Type (LXtID4 *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  Ident (const char **id)
  {
    return m_loc[0]->Ident (m_loc,id);
  }
    LxResult
  Size (size_t *size)
  {
    return m_loc[0]->Size (m_loc,size);
  }
    LxResult
  Delete (void)
  {
    return m_loc[0]->Delete (m_loc);
  }
    LxResult
  WriteSize (size_t size)
  {
    return m_loc[0]->WriteSize (m_loc,size);
  }
    LxResult
  WriteBlock (const void *buf, size_t offset, size_t size)
  {
    return m_loc[0]->WriteBlock (m_loc,buf,offset,size);
  }
    LxResult
  ReadBlock (void *buf, size_t offset, size_t size)
  {
    return m_loc[0]->ReadBlock (m_loc,buf,offset,size);
  }
};

class CLxImpl_LoaderInfo {
  public:
    virtual ~CLxImpl_LoaderInfo() {}
    virtual LxResult
      linf_TestClass (const LXtGUID *clsGUID, unsigned *priority)
        { return LXe_NOTIMPL; }
    virtual LxResult
      linf_SetClass (const LXtGUID *clsGUID)
        { return LXe_NOTIMPL; }
    virtual LxResult
      linf_SetFlags (unsigned flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      linf_SetFormat (const char *format)
        { return LXe_NOTIMPL; }
};
#define LXxD_LoaderInfo_TestClass LxResult linf_TestClass (const LXtGUID *clsGUID, unsigned *priority)
#define LXxO_LoaderInfo_TestClass LXxD_LoaderInfo_TestClass LXx_OVERRIDE
#define LXxC_LoaderInfo_TestClass(c) LxResult c::linf_TestClass (const LXtGUID *clsGUID, unsigned *priority)
#define LXxD_LoaderInfo_SetClass LxResult linf_SetClass (const LXtGUID *clsGUID)
#define LXxO_LoaderInfo_SetClass LXxD_LoaderInfo_SetClass LXx_OVERRIDE
#define LXxC_LoaderInfo_SetClass(c) LxResult c::linf_SetClass (const LXtGUID *clsGUID)
#define LXxD_LoaderInfo_SetFlags LxResult linf_SetFlags (unsigned flags)
#define LXxO_LoaderInfo_SetFlags LXxD_LoaderInfo_SetFlags LXx_OVERRIDE
#define LXxC_LoaderInfo_SetFlags(c) LxResult c::linf_SetFlags (unsigned flags)
#define LXxD_LoaderInfo_SetFormat LxResult linf_SetFormat (const char *format)
#define LXxO_LoaderInfo_SetFormat LXxD_LoaderInfo_SetFormat LXx_OVERRIDE
#define LXxC_LoaderInfo_SetFormat(c) LxResult c::linf_SetFormat (const char *format)
template <class T>
class CLxIfc_LoaderInfo : public CLxInterface
{
    static LxResult
  TestClass (LXtObjectID wcom, const LXtGUID *clsGUID, unsigned *priority)
  {
    LXCWxINST (CLxImpl_LoaderInfo, loc);
    try {
      return loc->linf_TestClass (clsGUID,priority);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetClass (LXtObjectID wcom, const LXtGUID *clsGUID)
  {
    LXCWxINST (CLxImpl_LoaderInfo, loc);
    try {
      return loc->linf_SetClass (clsGUID);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetFlags (LXtObjectID wcom, unsigned flags)
  {
    LXCWxINST (CLxImpl_LoaderInfo, loc);
    try {
      return loc->linf_SetFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetFormat (LXtObjectID wcom, const char *format)
  {
    LXCWxINST (CLxImpl_LoaderInfo, loc);
    try {
      return loc->linf_SetFormat (format);
    } catch (LxResult rc) { return rc; }
  }
  ILxLoaderInfo vt;
public:
  CLxIfc_LoaderInfo ()
  {
    vt.TestClass = TestClass;
    vt.SetClass = SetClass;
    vt.SetFlags = SetFlags;
    vt.SetFormat = SetFormat;
    vTable = &vt.iunk;
    iid = &lx::guid_LoaderInfo;
  }
};
class CLxLoc_LoaderInfo : public CLxLocalize<ILxLoaderInfoID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LoaderInfo() {_init();}
  CLxLoc_LoaderInfo(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LoaderInfo(const CLxLoc_LoaderInfo &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LoaderInfo;}
    LxResult
  TestClass (const LXtGUID *clsGUID, unsigned *priority)
  {
    return m_loc[0]->TestClass (m_loc,clsGUID,priority);
  }
    LxResult
  SetClass (const LXtGUID *clsGUID)
  {
    return m_loc[0]->SetClass (m_loc,clsGUID);
  }
    LxResult
  SetFlags (unsigned flags)
  {
    return m_loc[0]->SetFlags (m_loc,flags);
  }
    LxResult
  SetFormat (const char *format)
  {
    return m_loc[0]->SetFormat (m_loc,format);
  }
};

class CLxLoc_BlockRead : public CLxLocalize<ILxBlockReadID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_BlockRead() {_init();}
  CLxLoc_BlockRead(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_BlockRead(const CLxLoc_BlockRead &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_BlockRead;}
    LxResult
  FindBlock (const LXtBlockHeader *head, int flags, LXtID4 *blkId)
  {
    return m_loc[0]->FindBlock (m_loc,head,flags,blkId);
  }
    void
  End (void)
  {
    m_loc[0]->End (m_loc);
  }
    int
  Depth (void)
  {
    return m_loc[0]->Depth (m_loc);
  }
    LxResult
  ReadI1 (char *data, int count, int *ocount)
  {
    return m_loc[0]->ReadI1 (m_loc,data,count,ocount);
  }
    LxResult
  ReadI2 (short *data, int count, int *ocount)
  {
    return m_loc[0]->ReadI2 (m_loc,data,count,ocount);
  }
    LxResult
  ReadI4 (int *data, int count, int *ocount)
  {
    return m_loc[0]->ReadI4 (m_loc,data,count,ocount);
  }
    LxResult
  ReadU1 (unsigned char *data, int count, int *ocount)
  {
    return m_loc[0]->ReadU1 (m_loc,data,count,ocount);
  }
    LxResult
  ReadU2 (unsigned short *data, int count, int *ocount)
  {
    return m_loc[0]->ReadU2 (m_loc,data,count,ocount);
  }
    LxResult
  ReadU4 (unsigned int *data, int count, int *ocount)
  {
    return m_loc[0]->ReadU4 (m_loc,data,count,ocount);
  }
    LxResult
  ReadFP (float *data, int count, int *ocount)
  {
    return m_loc[0]->ReadFP (m_loc,data,count,ocount);
  }
    LxResult
  ReadFP8 (double *data, int count, int *ocount)
  {
    return m_loc[0]->ReadFP8 (m_loc,data,count,ocount);
  }
    LxResult
  ReadString (char *buf, int max, int flags, int *ocount)
  {
    return m_loc[0]->ReadString (m_loc,buf,max,flags,ocount);
  }
    LxResult
  ReadIDCode (const LXtBlockHeader *list, LXtID4 *idCode)
  {
    return m_loc[0]->ReadIDCode (m_loc,list,idCode);
  }
    LxResult
  ReadVX (unsigned *data, int count, int *ocount)
  {
    return m_loc[0]->ReadVX (m_loc,data,count,ocount);
  }
    LxResult
  SetSourceEncoding (unsigned encoding)
  {
    return m_loc[0]->SetSourceEncoding (m_loc,encoding);
  }
    LxResult
  SetTargetEncoding (unsigned encoding)
  {
    return m_loc[0]->SetTargetEncoding (m_loc,encoding);
  }
    LxResult
  SetMiniBlockHeight (unsigned mini)
  {
    return m_loc[0]->SetMiniBlockHeight (m_loc,mini);
  }
};

class CLxImpl_Loader {
  public:
    virtual ~CLxImpl_Loader() {}
    virtual LxResult
      load_Recognize (const char *filename, ILxUnknownID loadInfo)
        { return LXe_NOTIMPL; }
    virtual LxResult
      load_LoadInstance (ILxUnknownID loadInfo, ILxUnknownID monitor, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      load_LoadObject (ILxUnknownID loadInfo, ILxUnknownID monitor, ILxUnknownID dest)
        { return LXe_NOTIMPL; }
    virtual void
      load_Cleanup (void)
        { }
    virtual LxResult
      load_SpawnOptions (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_Loader_Recognize LxResult load_Recognize (const char *filename, ILxUnknownID loadInfo)
#define LXxO_Loader_Recognize LXxD_Loader_Recognize LXx_OVERRIDE
#define LXxC_Loader_Recognize(c) LxResult c::load_Recognize (const char *filename, ILxUnknownID loadInfo)
#define LXxD_Loader_LoadInstance LxResult load_LoadInstance (ILxUnknownID loadInfo, ILxUnknownID monitor, void **ppvObj)
#define LXxO_Loader_LoadInstance LXxD_Loader_LoadInstance LXx_OVERRIDE
#define LXxC_Loader_LoadInstance(c) LxResult c::load_LoadInstance (ILxUnknownID loadInfo, ILxUnknownID monitor, void **ppvObj)
#define LXxD_Loader_LoadObject LxResult load_LoadObject (ILxUnknownID loadInfo, ILxUnknownID monitor, ILxUnknownID dest)
#define LXxO_Loader_LoadObject LXxD_Loader_LoadObject LXx_OVERRIDE
#define LXxC_Loader_LoadObject(c) LxResult c::load_LoadObject (ILxUnknownID loadInfo, ILxUnknownID monitor, ILxUnknownID dest)
#define LXxD_Loader_Cleanup void load_Cleanup (void)
#define LXxO_Loader_Cleanup LXxD_Loader_Cleanup LXx_OVERRIDE
#define LXxC_Loader_Cleanup(c) void c::load_Cleanup (void)
#define LXxD_Loader_SpawnOptions LxResult load_SpawnOptions (void **ppvObj)
#define LXxO_Loader_SpawnOptions LXxD_Loader_SpawnOptions LXx_OVERRIDE
#define LXxC_Loader_SpawnOptions(c) LxResult c::load_SpawnOptions (void **ppvObj)
template <class T>
class CLxIfc_Loader : public CLxInterface
{
    static LxResult
  Recognize (LXtObjectID wcom, const char *filename, LXtObjectID loadInfo)
  {
    LXCWxINST (CLxImpl_Loader, loc);
    try {
      return loc->load_Recognize (filename,(ILxUnknownID)loadInfo);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LoadInstance (LXtObjectID wcom, LXtObjectID loadInfo, LXtObjectID monitor, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Loader, loc);
    try {
      return loc->load_LoadInstance ((ILxUnknownID)loadInfo,(ILxUnknownID)monitor,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LoadObject (LXtObjectID wcom, LXtObjectID loadInfo, LXtObjectID monitor, LXtObjectID dest)
  {
    LXCWxINST (CLxImpl_Loader, loc);
    try {
      return loc->load_LoadObject ((ILxUnknownID)loadInfo,(ILxUnknownID)monitor,(ILxUnknownID)dest);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Loader, loc);
    loc->load_Cleanup ();
  }
    static LxResult
  SpawnOptions (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Loader, loc);
    try {
      return loc->load_SpawnOptions (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxLoader vt;
public:
  CLxIfc_Loader ()
  {
    vt.Recognize = Recognize;
    vt.LoadInstance = LoadInstance;
    vt.LoadObject = LoadObject;
    vt.Cleanup = Cleanup;
    vt.SpawnOptions = SpawnOptions;
    vTable = &vt.iunk;
    iid = &lx::guid_Loader;
  }
};
class CLxLoc_Loader : public CLxLocalize<ILxLoaderID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Loader() {_init();}
  CLxLoc_Loader(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Loader(const CLxLoc_Loader &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Loader;}
    LxResult
  Recognize (const char *filename, ILxUnknownID loadInfo)
  {
    return m_loc[0]->Recognize (m_loc,filename,(ILxUnknownID)loadInfo);
  }
    LxResult
  LoadInstance (ILxUnknownID loadInfo, ILxUnknownID monitor, void **ppvObj)
  {
    return m_loc[0]->LoadInstance (m_loc,(ILxUnknownID)loadInfo,(ILxUnknownID)monitor,ppvObj);
  }
    CLxResult
  LoadInstance (ILxUnknownID loadInfo, ILxUnknownID monitor, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->LoadInstance(m_loc,(ILxUnknownID)loadInfo,(ILxUnknownID)monitor,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  LoadObject (ILxUnknownID loadInfo, ILxUnknownID monitor, ILxUnknownID dest)
  {
    return m_loc[0]->LoadObject (m_loc,(ILxUnknownID)loadInfo,(ILxUnknownID)monitor,(ILxUnknownID)dest);
  }
    void
  Cleanup (void)
  {
    m_loc[0]->Cleanup (m_loc);
  }
    LxResult
  SpawnOptions (void **ppvObj)
  {
    return m_loc[0]->SpawnOptions (m_loc,ppvObj);
  }
    CLxResult
  SpawnOptions (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SpawnOptions(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_BlockWrite : public CLxLocalize<ILxBlockWriteID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_BlockWrite() {_init();}
  CLxLoc_BlockWrite(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_BlockWrite(const CLxLoc_BlockWrite &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_BlockWrite;}
    LxResult
  WriteBlock (const LXtBlockHeader *head, int flags)
  {
    return m_loc[0]->WriteBlock (m_loc,head,flags);
  }
    void
  End (void)
  {
    m_loc[0]->End (m_loc);
  }
    int
  Depth (void)
  {
    return m_loc[0]->Depth (m_loc);
  }
    LxResult
  WriteI1 (const char *data, int count)
  {
    return m_loc[0]->WriteI1 (m_loc,data,count);
  }
    LxResult
  WriteI2 (const short *data, int count)
  {
    return m_loc[0]->WriteI2 (m_loc,data,count);
  }
    LxResult
  WriteI4 (const int *data, int count)
  {
    return m_loc[0]->WriteI4 (m_loc,data,count);
  }
    LxResult
  WriteU1 (const unsigned char *data, int count)
  {
    return m_loc[0]->WriteU1 (m_loc,data,count);
  }
    LxResult
  WriteU2 (const unsigned short *data, int count)
  {
    return m_loc[0]->WriteU2 (m_loc,data,count);
  }
    LxResult
  WriteU4 (const unsigned int *data, int count)
  {
    return m_loc[0]->WriteU4 (m_loc,data,count);
  }
    LxResult
  WriteFP (const float *data, int count)
  {
    return m_loc[0]->WriteFP (m_loc,data,count);
  }
    LxResult
  WriteFP8 (const double *data, int count)
  {
    return m_loc[0]->WriteFP8 (m_loc,data,count);
  }
    LxResult
  WriteString (const char *str)
  {
    return m_loc[0]->WriteString (m_loc,str);
  }
    LxResult
  WriteIDCode (const LXtBlockHeader *ident)
  {
    return m_loc[0]->WriteIDCode (m_loc,ident);
  }
    LxResult
  WriteVX (const unsigned int *data, int count)
  {
    return m_loc[0]->WriteVX (m_loc,data,count);
  }
    LxResult
  SetSourceEncoding (unsigned encoding)
  {
    return m_loc[0]->SetSourceEncoding (m_loc,encoding);
  }
    LxResult
  SetTargetEncoding (unsigned encoding)
  {
    return m_loc[0]->SetTargetEncoding (m_loc,encoding);
  }
};

class CLxImpl_Monitor {
  public:
    virtual ~CLxImpl_Monitor() {}
    virtual LxResult
      mon_Initialize (unsigned int count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mon_Increment (unsigned int count)
        { return LXe_NOTIMPL; }
};
#define LXxD_Monitor_Initialize LxResult mon_Initialize (unsigned int count)
#define LXxO_Monitor_Initialize LXxD_Monitor_Initialize LXx_OVERRIDE
#define LXxC_Monitor_Initialize(c) LxResult c::mon_Initialize (unsigned int count)
#define LXxD_Monitor_Increment LxResult mon_Increment (unsigned int count)
#define LXxO_Monitor_Increment LXxD_Monitor_Increment LXx_OVERRIDE
#define LXxC_Monitor_Increment(c) LxResult c::mon_Increment (unsigned int count)
template <class T>
class CLxIfc_Monitor : public CLxInterface
{
    static LxResult
  Initialize (LXtObjectID wcom, unsigned int count)
  {
    LXCWxINST (CLxImpl_Monitor, loc);
    try {
      return loc->mon_Initialize (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Increment (LXtObjectID wcom, unsigned int count)
  {
    LXCWxINST (CLxImpl_Monitor, loc);
    try {
      return loc->mon_Increment (count);
    } catch (LxResult rc) { return rc; }
  }
  ILxMonitor vt;
public:
  CLxIfc_Monitor ()
  {
    vt.Initialize = Initialize;
    vt.Increment = Increment;
    vTable = &vt.iunk;
    iid = &lx::guid_Monitor;
  }
};
class CLxLoc_Monitor : public CLxLocalize<ILxMonitorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Monitor() {_init();}
  CLxLoc_Monitor(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Monitor(const CLxLoc_Monitor &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Monitor;}
    LxResult
  Initialize (unsigned int count)
  {
    return m_loc[0]->Initialize (m_loc,count);
  }
    LxResult
  Increment (unsigned int count)
  {
    return m_loc[0]->Increment (m_loc,count);
  }
};

class CLxImpl_Saver {
  public:
    virtual ~CLxImpl_Saver() {}
    virtual LxResult
      sav_Verify (ILxUnknownID source, ILxUnknownID message)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sav_Save (ILxUnknownID source, const char *filename, ILxUnknownID monitor)
        { return LXe_NOTIMPL; }
};
#define LXxD_Saver_Verify LxResult sav_Verify (ILxUnknownID source, ILxUnknownID message)
#define LXxO_Saver_Verify LXxD_Saver_Verify LXx_OVERRIDE
#define LXxC_Saver_Verify(c) LxResult c::sav_Verify (ILxUnknownID source, ILxUnknownID message)
#define LXxD_Saver_Save LxResult sav_Save (ILxUnknownID source, const char *filename, ILxUnknownID monitor)
#define LXxO_Saver_Save LXxD_Saver_Save LXx_OVERRIDE
#define LXxC_Saver_Save(c) LxResult c::sav_Save (ILxUnknownID source, const char *filename, ILxUnknownID monitor)
template <class T>
class CLxIfc_Saver : public CLxInterface
{
    static LxResult
  Verify (LXtObjectID wcom, LXtObjectID source, LXtObjectID message)
  {
    LXCWxINST (CLxImpl_Saver, loc);
    try {
      return loc->sav_Verify ((ILxUnknownID)source,(ILxUnknownID)message);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Save (LXtObjectID wcom, LXtObjectID source, const char *filename, LXtObjectID monitor)
  {
    LXCWxINST (CLxImpl_Saver, loc);
    try {
      return loc->sav_Save ((ILxUnknownID)source,filename,(ILxUnknownID)monitor);
    } catch (LxResult rc) { return rc; }
  }
  ILxSaver vt;
public:
  CLxIfc_Saver ()
  {
    vt.Verify = Verify;
    vt.Save = Save;
    vTable = &vt.iunk;
    iid = &lx::guid_Saver;
  }
};
class CLxLoc_Saver : public CLxLocalize<ILxSaverID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Saver() {_init();}
  CLxLoc_Saver(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Saver(const CLxLoc_Saver &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Saver;}
    LxResult
  Verify (ILxUnknownID source, ILxUnknownID message)
  {
    return m_loc[0]->Verify (m_loc,(ILxUnknownID)source,(ILxUnknownID)message);
  }
    LxResult
  Save (ILxUnknownID source, const char *filename, ILxUnknownID monitor)
  {
    return m_loc[0]->Save (m_loc,(ILxUnknownID)source,filename,(ILxUnknownID)monitor);
  }
};

class CLxImpl_Loader1 {
  public:
    virtual ~CLxImpl_Loader1() {}
    virtual LxResult
      load_Recognize (LXtLoadAccess1 *load)
        { return LXe_NOTIMPL; }
    virtual LxResult
      load_LoadInstance (LXtLoadAccess1 *load, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      load_LoadObject (LXtLoadAccess1 *load, ILxUnknownID dest)
        { return LXe_NOTIMPL; }
    virtual LxResult
      load_Cleanup (LXtLoadAccess1 *load)
        { return LXe_NOTIMPL; }
    virtual LxResult
      load_SpawnOptions (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_Loader1_Recognize LxResult load_Recognize (LXtLoadAccess1 *load)
#define LXxO_Loader1_Recognize LXxD_Loader1_Recognize LXx_OVERRIDE
#define LXxC_Loader1_Recognize(c) LxResult c::load_Recognize (LXtLoadAccess1 *load)
#define LXxD_Loader1_LoadInstance LxResult load_LoadInstance (LXtLoadAccess1 *load, void **ppvObj)
#define LXxO_Loader1_LoadInstance LXxD_Loader1_LoadInstance LXx_OVERRIDE
#define LXxC_Loader1_LoadInstance(c) LxResult c::load_LoadInstance (LXtLoadAccess1 *load, void **ppvObj)
#define LXxD_Loader1_LoadObject LxResult load_LoadObject (LXtLoadAccess1 *load, ILxUnknownID dest)
#define LXxO_Loader1_LoadObject LXxD_Loader1_LoadObject LXx_OVERRIDE
#define LXxC_Loader1_LoadObject(c) LxResult c::load_LoadObject (LXtLoadAccess1 *load, ILxUnknownID dest)
#define LXxD_Loader1_Cleanup LxResult load_Cleanup (LXtLoadAccess1 *load)
#define LXxO_Loader1_Cleanup LXxD_Loader1_Cleanup LXx_OVERRIDE
#define LXxC_Loader1_Cleanup(c) LxResult c::load_Cleanup (LXtLoadAccess1 *load)
#define LXxD_Loader1_SpawnOptions LxResult load_SpawnOptions (void **ppvObj)
#define LXxO_Loader1_SpawnOptions LXxD_Loader1_SpawnOptions LXx_OVERRIDE
#define LXxC_Loader1_SpawnOptions(c) LxResult c::load_SpawnOptions (void **ppvObj)
template <class T>
class CLxIfc_Loader1 : public CLxInterface
{
    static LxResult
  Recognize (LXtObjectID wcom, LXtLoadAccess1 *load)
  {
    LXCWxINST (CLxImpl_Loader1, loc);
    try {
      return loc->load_Recognize (load);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LoadInstance (LXtObjectID wcom, LXtLoadAccess1 *load, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Loader1, loc);
    try {
      return loc->load_LoadInstance (load,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LoadObject (LXtObjectID wcom, LXtLoadAccess1 *load, LXtObjectID dest)
  {
    LXCWxINST (CLxImpl_Loader1, loc);
    try {
      return loc->load_LoadObject (load,(ILxUnknownID)dest);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Cleanup (LXtObjectID wcom, LXtLoadAccess1 *load)
  {
    LXCWxINST (CLxImpl_Loader1, loc);
    try {
      return loc->load_Cleanup (load);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SpawnOptions (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Loader1, loc);
    try {
      return loc->load_SpawnOptions (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxLoader1 vt;
public:
  CLxIfc_Loader1 ()
  {
    vt.Recognize = Recognize;
    vt.LoadInstance = LoadInstance;
    vt.LoadObject = LoadObject;
    vt.Cleanup = Cleanup;
    vt.SpawnOptions = SpawnOptions;
    vTable = &vt.iunk;
    iid = &lx::guid_Loader1;
  }
};

class CLxImpl_StreamIO {
  public:
    virtual ~CLxImpl_StreamIO() {}
    virtual LxResult
      io_Write (ILxUnknownID stream)
        { return LXe_NOTIMPL; }
    virtual LxResult
      io_Read (ILxUnknownID stream)
        { return LXe_NOTIMPL; }
};
#define LXxD_StreamIO_Write LxResult io_Write (ILxUnknownID stream)
#define LXxO_StreamIO_Write LXxD_StreamIO_Write LXx_OVERRIDE
#define LXxC_StreamIO_Write(c) LxResult c::io_Write (ILxUnknownID stream)
#define LXxD_StreamIO_Read LxResult io_Read (ILxUnknownID stream)
#define LXxO_StreamIO_Read LXxD_StreamIO_Read LXx_OVERRIDE
#define LXxC_StreamIO_Read(c) LxResult c::io_Read (ILxUnknownID stream)
template <class T>
class CLxIfc_StreamIO : public CLxInterface
{
    static LxResult
  Write (LXtObjectID wcom, LXtObjectID stream)
  {
    LXCWxINST (CLxImpl_StreamIO, loc);
    try {
      return loc->io_Write ((ILxUnknownID)stream);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Read (LXtObjectID wcom, LXtObjectID stream)
  {
    LXCWxINST (CLxImpl_StreamIO, loc);
    try {
      return loc->io_Read ((ILxUnknownID)stream);
    } catch (LxResult rc) { return rc; }
  }
  ILxStreamIO vt;
public:
  CLxIfc_StreamIO ()
  {
    vt.Write = Write;
    vt.Read = Read;
    vTable = &vt.iunk;
    iid = &lx::guid_StreamIO;
  }
};
class CLxLoc_StreamIO : public CLxLocalize<ILxStreamIOID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StreamIO() {_init();}
  CLxLoc_StreamIO(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StreamIO(const CLxLoc_StreamIO &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StreamIO;}
    LxResult
  Write (ILxUnknownID stream)
  {
    return m_loc[0]->Write (m_loc,(ILxUnknownID)stream);
  }
    LxResult
  Read (ILxUnknownID stream)
  {
    return m_loc[0]->Read (m_loc,(ILxUnknownID)stream);
  }
};

#endif

