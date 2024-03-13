/*
 * C++ wrapper for lxthread.h
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
#ifndef LXW_THREAD_HPP
#define LXW_THREAD_HPP

#include <lxthread.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ThreadMutex = {0x7624F6B7,0x83FD,0x424F,0xA6,0x8E,0x0E,0xDD,0x08,0x91,0x67,0xCB};
    static const LXtGUID guid_SharedWork = {0x4D414F97,0x35A4,0x4B26,0x84,0xFE,0x0E,0x74,0x0C,0x79,0x72,0x2C};
    static const LXtGUID guid_ThreadGroup = {0x54A9DD48,0x3AFC,0x435F,0x9F,0x17,0x2E,0xEB,0x6F,0xB4,0x6F,0xBA};
    static const LXtGUID guid_ThreadSlot = {0x365E4616,0x0FB9,0x478E,0x99,0x3D,0xD3,0x52,0x82,0xF4,0xC3,0x26};
    static const LXtGUID guid_WorkList = {0x74568CA9,0x92C9,0x4C73,0x98,0x51,0xE9,0x16,0x99,0x34,0x62,0x9A};
    static const LXtGUID guid_ThreadService = {0x0A9D5B42,0x1DA6,0x42A4,0x8F,0xC4,0x01,0xFC,0xCE,0x93,0x9A,0xC4};
    static const LXtGUID guid_Waterfall = {0x2B845B2A,0x06BE,0x4C90,0x8E,0x50,0x58,0xF7,0xFB,0xEE,0xC2,0x5E};
    static const LXtGUID guid_ThreadRangeWorker = {0x612153FE,0x572F,0x4CD6,0x80,0x33,0xB9,0x05,0x76,0x2C,0x31,0x06};
    static const LXtGUID guid_ThreadSlotClient = {0xD24835B6,0x518B,0x4E33,0x8A,0x70,0xE5,0x30,0x38,0xC2,0x9B,0xB7};
    static const LXtGUID guid_ThreadJob = {0xDE892B0B,0xA791,0x4FA5,0xB8,0x5D,0x46,0xE8,0xCA,0xCB,0x69,0x5B};
};

class CLxLoc_ThreadMutex : public CLxLocalize<ILxThreadMutexID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ThreadMutex() {_init();}
  CLxLoc_ThreadMutex(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ThreadMutex(const CLxLoc_ThreadMutex &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ThreadMutex;}
    void
  Enter (void)
  {
    m_loc[0]->Enter (m_loc);
  }
    void
  Leave (void)
  {
    m_loc[0]->Leave (m_loc);
  }
};

class CLxImpl_SharedWork {
  public:
    virtual ~CLxImpl_SharedWork() {}
    virtual LxResult
      share_Evaluate (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      share_Spawn (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      share_Share (ILxUnknownID other, unsigned int split)
        { return LXe_NOTIMPL; }
};
#define LXxD_SharedWork_Evaluate LxResult share_Evaluate (void)
#define LXxO_SharedWork_Evaluate LXxD_SharedWork_Evaluate LXx_OVERRIDE
#define LXxC_SharedWork_Evaluate(c) LxResult c::share_Evaluate (void)
#define LXxD_SharedWork_Spawn LxResult share_Spawn (void **ppvObj)
#define LXxO_SharedWork_Spawn LXxD_SharedWork_Spawn LXx_OVERRIDE
#define LXxC_SharedWork_Spawn(c) LxResult c::share_Spawn (void **ppvObj)
#define LXxD_SharedWork_Share LxResult share_Share (ILxUnknownID other, unsigned int split)
#define LXxO_SharedWork_Share LXxD_SharedWork_Share LXx_OVERRIDE
#define LXxC_SharedWork_Share(c) LxResult c::share_Share (ILxUnknownID other, unsigned int split)
template <class T>
class CLxIfc_SharedWork : public CLxInterface
{
    static LxResult
  Evaluate (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SharedWork, loc);
    try {
      return loc->share_Evaluate ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Spawn (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SharedWork, loc);
    try {
      return loc->share_Spawn (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Share (LXtObjectID wcom, LXtObjectID other, unsigned int split)
  {
    LXCWxINST (CLxImpl_SharedWork, loc);
    try {
      return loc->share_Share ((ILxUnknownID)other,split);
    } catch (LxResult rc) { return rc; }
  }
  ILxSharedWork vt;
public:
  CLxIfc_SharedWork ()
  {
    vt.Evaluate = Evaluate;
    vt.Spawn = Spawn;
    vt.Share = Share;
    vTable = &vt.iunk;
    iid = &lx::guid_SharedWork;
  }
};
class CLxLoc_SharedWork : public CLxLocalize<ILxSharedWorkID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SharedWork() {_init();}
  CLxLoc_SharedWork(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SharedWork(const CLxLoc_SharedWork &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SharedWork;}
    LxResult
  Evaluate (void)
  {
    return m_loc[0]->Evaluate (m_loc);
  }
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    CLxResult
  Spawn (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Spawn(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Share (ILxUnknownID other, unsigned int split)
  {
    return m_loc[0]->Share (m_loc,(ILxUnknownID)other,split);
  }
};

class CLxLoc_ThreadGroup : public CLxLocalize<ILxThreadGroupID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ThreadGroup() {_init();}
  CLxLoc_ThreadGroup(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ThreadGroup(const CLxLoc_ThreadGroup &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ThreadGroup;}
    void
  AddJob (ILxUnknownID job)
  {
    m_loc[0]->AddJob (m_loc,(ILxUnknownID)job);
  }
    unsigned
  NumJobs (void)
  {
    return m_loc[0]->NumJobs (m_loc);
  }
    void
  Clear (void)
  {
    m_loc[0]->Clear (m_loc);
  }
    void
  Execute (void)
  {
    m_loc[0]->Execute (m_loc);
  }
    void
  Wait (void)
  {
    m_loc[0]->Wait (m_loc);
  }
    LxResult
  Running (void)
  {
    return m_loc[0]->Running (m_loc);
  }
    void
  Kill (void)
  {
    m_loc[0]->Kill (m_loc);
  }
};

class CLxLoc_ThreadSlot : public CLxLocalize<ILxThreadSlotID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ThreadSlot() {_init();}
  CLxLoc_ThreadSlot(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ThreadSlot(const CLxLoc_ThreadSlot &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ThreadSlot;}
    LxResult
  Set (void *value)
  {
    return m_loc[0]->Set (m_loc,value);
  }
    LxResult
  Get (void **value)
  {
    return m_loc[0]->Get (m_loc,value);
  }
    LxResult
  Clear (void)
  {
    return m_loc[0]->Clear (m_loc);
  }
};

class CLxImpl_WorkList {
  public:
    virtual ~CLxImpl_WorkList() {}
    virtual LxResult
      work_IsEmpty (void)
        { return LXe_NOTIMPL; }
    virtual void *
      work_Next (void)
        = 0;
    virtual LxResult
      work_Split (unsigned mode, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual void
      work_Clear (void)
        { }
};
#define LXxD_WorkList_IsEmpty LxResult work_IsEmpty (void)
#define LXxO_WorkList_IsEmpty LXxD_WorkList_IsEmpty LXx_OVERRIDE
#define LXxC_WorkList_IsEmpty(c) LxResult c::work_IsEmpty (void)
#define LXxD_WorkList_Next void * work_Next (void)
#define LXxO_WorkList_Next LXxD_WorkList_Next LXx_OVERRIDE
#define LXxC_WorkList_Next(c) void * c::work_Next (void)
#define LXxD_WorkList_Split LxResult work_Split (unsigned mode, void **ppvObj)
#define LXxO_WorkList_Split LXxD_WorkList_Split LXx_OVERRIDE
#define LXxC_WorkList_Split(c) LxResult c::work_Split (unsigned mode, void **ppvObj)
#define LXxD_WorkList_Clear void work_Clear (void)
#define LXxO_WorkList_Clear LXxD_WorkList_Clear LXx_OVERRIDE
#define LXxC_WorkList_Clear(c) void c::work_Clear (void)
template <class T>
class CLxIfc_WorkList : public CLxInterface
{
    static LxResult
  IsEmpty (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_WorkList, loc);
    try {
      return loc->work_IsEmpty ();
    } catch (LxResult rc) { return rc; }
  }
    static void *
  Next (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_WorkList, loc);
    return loc->work_Next ();
  }
    static LxResult
  Split (LXtObjectID wcom, unsigned mode, void **ppvObj)
  {
    LXCWxINST (CLxImpl_WorkList, loc);
    try {
      return loc->work_Split (mode,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Clear (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_WorkList, loc);
    loc->work_Clear ();
  }
  ILxWorkList vt;
public:
  CLxIfc_WorkList ()
  {
    vt.IsEmpty = IsEmpty;
    vt.Next = Next;
    vt.Split = Split;
    vt.Clear = Clear;
    vTable = &vt.iunk;
    iid = &lx::guid_WorkList;
  }
};
class CLxLoc_WorkList : public CLxLocalize<ILxWorkListID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_WorkList() {_init();}
  CLxLoc_WorkList(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_WorkList(const CLxLoc_WorkList &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_WorkList;}
    LxResult
  IsEmpty (void)
  {
    return m_loc[0]->IsEmpty (m_loc);
  }
    void *
  Next (void)
  {
    return m_loc[0]->Next (m_loc);
  }
    LxResult
  Split (unsigned mode, void **ppvObj)
  {
    return m_loc[0]->Split (m_loc,mode,ppvObj);
  }
    CLxResult
  Split (unsigned mode, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Split(m_loc,mode,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void
  Clear (void)
  {
    m_loc[0]->Clear (m_loc);
  }
};

class CLxLoc_ThreadService : public CLxLocalizedService
{
public:
  ILxThreadServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_ThreadService() {_init();set();}
 ~CLxLoc_ThreadService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxThreadServiceID>(lx::GetGlobal(&lx::guid_ThreadService));}
    LxResult
  CreateMutex (void **ppvObj)
  {
    return m_loc[0]->CreateMutex (m_loc,ppvObj);
  }
    CLxResult
  CreateMutex (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateMutex(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CreateCS (void **ppvObj)
  {
    return m_loc[0]->CreateCS (m_loc,ppvObj);
  }
    CLxResult
  CreateCS (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateCS(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CreateGroup (void **ppvObj)
  {
    return m_loc[0]->CreateGroup (m_loc,ppvObj);
  }
    CLxResult
  CreateGroup (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateGroup(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned int
  NumProcs (void)
  {
    return m_loc[0]->NumProcs (m_loc);
  }
    unsigned int
  IsMainThread (void)
  {
    return m_loc[0]->IsMainThread (m_loc);
  }
    LxResult
  CreateSlot (size_t size, ILxUnknownID client, void **ppvObj)
  {
    return m_loc[0]->CreateSlot (m_loc,size,(ILxUnknownID)client,ppvObj);
  }
    CLxResult
  CreateSlot (size_t size, ILxUnknownID client, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateSlot(m_loc,size,(ILxUnknownID)client,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ProcessShared (ILxUnknownID shared)
  {
    return m_loc[0]->ProcessShared (m_loc,(ILxUnknownID)shared);
  }
    LxResult
  ProcessRange (void *data, int startIndex, int endIndex, ILxUnknownID rangeWorker)
  {
    return m_loc[0]->ProcessRange (m_loc,data,startIndex,endIndex,(ILxUnknownID)rangeWorker);
  }
    LxResult
  InitThread (void) const
  {
    return m_loc[0]->InitThread (m_loc);
  }
    LxResult
  CleanupThread (void) const
  {
    return m_loc[0]->CleanupThread (m_loc);
  }
    LxResult
  ProcessWaterfall (ILxUnknownID waterfall, unsigned threads)
  {
    return m_loc[0]->ProcessWaterfall (m_loc,(ILxUnknownID)waterfall,threads);
  }
    int
  AtomicIncrement (volatile int *addr)
  {
    return m_loc[0]->AtomicIncrement (m_loc,addr);
  }
    int
  AtomicDecrement (volatile int *addr)
  {
    return m_loc[0]->AtomicDecrement (m_loc,addr);
  }
    int
  AtomicIntegerAdd (volatile int *addr, int val)
  {
    return m_loc[0]->AtomicIntegerAdd (m_loc,addr,val);
  }
    int
  AtomicIntegerSubtract (volatile int *addr, int val)
  {
    return m_loc[0]->AtomicIntegerSubtract (m_loc,addr,val);
  }
};

class CLxImpl_Waterfall {
  public:
    virtual ~CLxImpl_Waterfall() {}
    virtual LxResult
      wfall_Spawn (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual unsigned
      wfall_State (void)
        = 0;
    virtual LxResult
      wfall_ProcessWork (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      wfall_GetWork (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      wfall_Advance (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_Waterfall_Spawn LxResult wfall_Spawn (void **ppvObj)
#define LXxO_Waterfall_Spawn LXxD_Waterfall_Spawn LXx_OVERRIDE
#define LXxC_Waterfall_Spawn(c) LxResult c::wfall_Spawn (void **ppvObj)
#define LXxD_Waterfall_State unsigned wfall_State (void)
#define LXxO_Waterfall_State LXxD_Waterfall_State LXx_OVERRIDE
#define LXxC_Waterfall_State(c) unsigned c::wfall_State (void)
#define LXxD_Waterfall_ProcessWork LxResult wfall_ProcessWork (void)
#define LXxO_Waterfall_ProcessWork LXxD_Waterfall_ProcessWork LXx_OVERRIDE
#define LXxC_Waterfall_ProcessWork(c) LxResult c::wfall_ProcessWork (void)
#define LXxD_Waterfall_GetWork LxResult wfall_GetWork (void)
#define LXxO_Waterfall_GetWork LXxD_Waterfall_GetWork LXx_OVERRIDE
#define LXxC_Waterfall_GetWork(c) LxResult c::wfall_GetWork (void)
#define LXxD_Waterfall_Advance LxResult wfall_Advance (void)
#define LXxO_Waterfall_Advance LXxD_Waterfall_Advance LXx_OVERRIDE
#define LXxC_Waterfall_Advance(c) LxResult c::wfall_Advance (void)
template <class T>
class CLxIfc_Waterfall : public CLxInterface
{
    static LxResult
  Spawn (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Waterfall, loc);
    try {
      return loc->wfall_Spawn (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned
  State (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Waterfall, loc);
    return loc->wfall_State ();
  }
    static LxResult
  ProcessWork (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Waterfall, loc);
    try {
      return loc->wfall_ProcessWork ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetWork (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Waterfall, loc);
    try {
      return loc->wfall_GetWork ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Advance (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Waterfall, loc);
    try {
      return loc->wfall_Advance ();
    } catch (LxResult rc) { return rc; }
  }
  ILxWaterfall vt;
public:
  CLxIfc_Waterfall ()
  {
    vt.Spawn = Spawn;
    vt.State = State;
    vt.ProcessWork = ProcessWork;
    vt.GetWork = GetWork;
    vt.Advance = Advance;
    vTable = &vt.iunk;
    iid = &lx::guid_Waterfall;
  }
};
class CLxLoc_Waterfall : public CLxLocalize<ILxWaterfallID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Waterfall() {_init();}
  CLxLoc_Waterfall(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Waterfall(const CLxLoc_Waterfall &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Waterfall;}
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    CLxResult
  Spawn (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Spawn(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned
  State (void)
  {
    return m_loc[0]->State (m_loc);
  }
    LxResult
  ProcessWork (void)
  {
    return m_loc[0]->ProcessWork (m_loc);
  }
    LxResult
  GetWork (void)
  {
    return m_loc[0]->GetWork (m_loc);
  }
    LxResult
  Advance (void)
  {
    return m_loc[0]->Advance (m_loc);
  }
};

class CLxImpl_ThreadRangeWorker {
  public:
    virtual ~CLxImpl_ThreadRangeWorker() {}
    virtual LxResult
      rngw_Execute (int index, void *sharedData)
        { return LXe_NOTIMPL; }
};
#define LXxD_ThreadRangeWorker_Execute LxResult rngw_Execute (int index, void *sharedData)
#define LXxO_ThreadRangeWorker_Execute LXxD_ThreadRangeWorker_Execute LXx_OVERRIDE
#define LXxC_ThreadRangeWorker_Execute(c) LxResult c::rngw_Execute (int index, void *sharedData)
template <class T>
class CLxIfc_ThreadRangeWorker : public CLxInterface
{
    static LxResult
  Execute (LXtObjectID wcom, int index, void *sharedData)
  {
    LXCWxINST (CLxImpl_ThreadRangeWorker, loc);
    try {
      return loc->rngw_Execute (index,sharedData);
    } catch (LxResult rc) { return rc; }
  }
  ILxThreadRangeWorker vt;
public:
  CLxIfc_ThreadRangeWorker ()
  {
    vt.Execute = Execute;
    vTable = &vt.iunk;
    iid = &lx::guid_ThreadRangeWorker;
  }
};
class CLxLoc_ThreadRangeWorker : public CLxLocalize<ILxThreadRangeWorkerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ThreadRangeWorker() {_init();}
  CLxLoc_ThreadRangeWorker(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ThreadRangeWorker(const CLxLoc_ThreadRangeWorker &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ThreadRangeWorker;}
    LxResult
  Execute (int index, void *sharedData)
  {
    return m_loc[0]->Execute (m_loc,index,sharedData);
  }
};

class CLxImpl_ThreadSlotClient {
  public:
    virtual ~CLxImpl_ThreadSlotClient() {}
    virtual LxResult
      tsc_Alloc (void **value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsc_Free (void *value)
        { return LXe_NOTIMPL; }
};
#define LXxD_ThreadSlotClient_Alloc LxResult tsc_Alloc (void **value)
#define LXxO_ThreadSlotClient_Alloc LXxD_ThreadSlotClient_Alloc LXx_OVERRIDE
#define LXxC_ThreadSlotClient_Alloc(c) LxResult c::tsc_Alloc (void **value)
#define LXxD_ThreadSlotClient_Free LxResult tsc_Free (void *value)
#define LXxO_ThreadSlotClient_Free LXxD_ThreadSlotClient_Free LXx_OVERRIDE
#define LXxC_ThreadSlotClient_Free(c) LxResult c::tsc_Free (void *value)
template <class T>
class CLxIfc_ThreadSlotClient : public CLxInterface
{
    static LxResult
  Alloc (LXtObjectID wcom, void **value)
  {
    LXCWxINST (CLxImpl_ThreadSlotClient, loc);
    try {
      return loc->tsc_Alloc (value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Free (LXtObjectID wcom, void *value)
  {
    LXCWxINST (CLxImpl_ThreadSlotClient, loc);
    try {
      return loc->tsc_Free (value);
    } catch (LxResult rc) { return rc; }
  }
  ILxThreadSlotClient vt;
public:
  CLxIfc_ThreadSlotClient ()
  {
    vt.Alloc = Alloc;
    vt.Free = Free;
    vTable = &vt.iunk;
    iid = &lx::guid_ThreadSlotClient;
  }
};
class CLxLoc_ThreadSlotClient : public CLxLocalize<ILxThreadSlotClientID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ThreadSlotClient() {_init();}
  CLxLoc_ThreadSlotClient(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ThreadSlotClient(const CLxLoc_ThreadSlotClient &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ThreadSlotClient;}
    LxResult
  Alloc (void **value)
  {
    return m_loc[0]->Alloc (m_loc,value);
  }
    LxResult
  Free (void *value)
  {
    return m_loc[0]->Free (m_loc,value);
  }
};

class CLxImpl_ThreadJob {
  public:
    virtual ~CLxImpl_ThreadJob() {}
    virtual void
      job_Execute (void)
        { }
};
#define LXxD_ThreadJob_Execute void job_Execute (void)
#define LXxO_ThreadJob_Execute LXxD_ThreadJob_Execute LXx_OVERRIDE
#define LXxC_ThreadJob_Execute(c) void c::job_Execute (void)
template <class T>
class CLxIfc_ThreadJob : public CLxInterface
{
    static void
  Execute (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ThreadJob, loc);
    loc->job_Execute ();
  }
  ILxThreadJob vt;
public:
  CLxIfc_ThreadJob ()
  {
    vt.Execute = Execute;
    vTable = &vt.iunk;
    iid = &lx::guid_ThreadJob;
  }
};
class CLxLoc_ThreadJob : public CLxLocalize<ILxThreadJobID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ThreadJob() {_init();}
  CLxLoc_ThreadJob(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ThreadJob(const CLxLoc_ThreadJob &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ThreadJob;}
    void
  Execute (void)
  {
    m_loc[0]->Execute (m_loc);
  }
};

#endif

