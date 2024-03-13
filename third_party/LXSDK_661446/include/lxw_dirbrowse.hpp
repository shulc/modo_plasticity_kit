/*
 * C++ wrapper for lxdirbrowse.h
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
#ifndef LXW_DIRBROWSE_HPP
#define LXW_DIRBROWSE_HPP

#include <lxdirbrowse.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_DirBrowserBasePathEntryDest = {0x56a0f290,0x9aca,0x4e44,0xb0,0x36,0xb2,0xbb,0xb7,0xbe,0x28,0xd2};
    static const LXtGUID guid_DirCacheSyntheticEntry = {0x9d741627,0xbeea,0x4c7f,0x86,0x66,0xcc,0xbd,0xb2,0xcd,0x3e,0x72};
    static const LXtGUID guid_MergedFileSysDest = {0xa58450c6,0x5789,0x4072,0x84,0xeb,0x92,0x15,0x4d,0x63,0x2d,0xc2};
    static const LXtGUID guid_FileSysDest = {0x79d4f661,0x3249,0x4455,0xbf,0xb9,0x48,0x61,0x20,0xc1,0x8f,0x24};
    static const LXtGUID guid_DirCacheManualOrderDest = {0xfb69c873,0x9f95,0x4ba1,0xba,0x1f,0x12,0x35,0x30,0x7e,0x3c,0x88};
    static const LXtGUID guid_DirCacheGridPosDest = {0x09a9db0d,0x131f,0x40ed,0x91,0x0a,0x89,0x16,0xa6,0x36,0xdc,0x36};
    static const LXtGUID guid_DirCacheSynthetic = {0xd269abf7,0x7bd3,0x4982,0xa6,0xbd,0xcb,0x46,0xfc,0xeb,0xe1,0xe3};
    static const LXtGUID guid_BasePathAddDest = {0x1710a8c1,0xa493,0x4e65,0xa1,0x90,0x00,0x9e,0xff,0xc4,0xa1,0x34};
    static const LXtGUID guid_DirCacheService = {0xb61119fa,0x4cd9,0x4067,0xba,0x48,0xba,0x83,0xad,0x1f,0xa5,0x44};
    static const LXtGUID guid_DirCacheEntry = {0x1013a289,0xaa27,0x416a,0xb2,0x73,0x66,0x67,0x32,0xce,0x3d,0x88};
    static const LXtGUID guid_DirCacheFileMetrics = {0x2c00a80c,0xac90,0x401c,0x8c,0xb8,0xab,0xfd,0xf3,0xba,0x26,0xdd};
    static const LXtGUID guid_DirCacheSyntheticEntry1 = {0xc85d528d,0x50aa,0x4974,0xbb,0xf0,0x61,0x22,0xb4,0xe0,0x0d,0x5b};
    static const LXtGUID guid_DirEntryThumbAsync = {0x0a3c97de,0x37b8,0x44b2,0xa5,0x2b,0xb1,0xb9,0x1c,0x77,0xe5,0x97};
    static const LXtGUID guid_MergedDirCacheEntry = {0x38986948,0x6e89,0x4208,0xa7,0x34,0x41,0x1d,0x28,0xab,0x48,0x15};
};

class CLxLoc_DirBrowserBasePathEntryDest : public CLxLocalize<ILxDirBrowserBasePathEntryDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DirBrowserBasePathEntryDest() {_init();}
  CLxLoc_DirBrowserBasePathEntryDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DirBrowserBasePathEntryDest(const CLxLoc_DirBrowserBasePathEntryDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DirBrowserBasePathEntryDest;}
    LxResult
  SetPath (const char **path)
  {
    return m_loc[0]->SetPath (m_loc,path);
  }
    LxResult
  OrdinalBefore (const char **ordinal)
  {
    return m_loc[0]->OrdinalBefore (m_loc,ordinal);
  }
    LxResult
  OrdinalAfter (const char **ordinal)
  {
    return m_loc[0]->OrdinalAfter (m_loc,ordinal);
  }
};

class CLxImpl_DirCacheSyntheticEntry {
  public:
    virtual ~CLxImpl_DirCacheSyntheticEntry() {}
    virtual LxResult
      dcsyne_Path (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_OverrideParent (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_Name (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_DirUsername (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_FileExtension (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_IsFile (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_DirBuild (void)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      dcsyne_DirCount (int listMode)
        = 0;
    virtual LxResult
      dcsyne_DirByIndex (int listMode, unsigned int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_ModTime (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual double
      dcsyne_Size (void)
        = 0;
};
#define LXxD_DirCacheSyntheticEntry_Path LxResult dcsyne_Path (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry_Path LXxD_DirCacheSyntheticEntry_Path LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_Path(c) LxResult c::dcsyne_Path (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry_OverrideParent LxResult dcsyne_OverrideParent (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry_OverrideParent LXxD_DirCacheSyntheticEntry_OverrideParent LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_OverrideParent(c) LxResult c::dcsyne_OverrideParent (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry_Name LxResult dcsyne_Name (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry_Name LXxD_DirCacheSyntheticEntry_Name LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_Name(c) LxResult c::dcsyne_Name (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry_DirUsername LxResult dcsyne_DirUsername (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry_DirUsername LXxD_DirCacheSyntheticEntry_DirUsername LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_DirUsername(c) LxResult c::dcsyne_DirUsername (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry_FileExtension LxResult dcsyne_FileExtension (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry_FileExtension LXxD_DirCacheSyntheticEntry_FileExtension LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_FileExtension(c) LxResult c::dcsyne_FileExtension (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry_IsFile LxResult dcsyne_IsFile (void)
#define LXxO_DirCacheSyntheticEntry_IsFile LXxD_DirCacheSyntheticEntry_IsFile LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_IsFile(c) LxResult c::dcsyne_IsFile (void)
#define LXxD_DirCacheSyntheticEntry_DirBuild LxResult dcsyne_DirBuild (void)
#define LXxO_DirCacheSyntheticEntry_DirBuild LXxD_DirCacheSyntheticEntry_DirBuild LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_DirBuild(c) LxResult c::dcsyne_DirBuild (void)
#define LXxD_DirCacheSyntheticEntry_DirCount unsigned int dcsyne_DirCount (int listMode)
#define LXxO_DirCacheSyntheticEntry_DirCount LXxD_DirCacheSyntheticEntry_DirCount LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_DirCount(c) unsigned int c::dcsyne_DirCount (int listMode)
#define LXxD_DirCacheSyntheticEntry_DirByIndex LxResult dcsyne_DirByIndex (int listMode, unsigned int index, void **ppvObj)
#define LXxO_DirCacheSyntheticEntry_DirByIndex LXxD_DirCacheSyntheticEntry_DirByIndex LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_DirByIndex(c) LxResult c::dcsyne_DirByIndex (int listMode, unsigned int index, void **ppvObj)
#define LXxD_DirCacheSyntheticEntry_ModTime LxResult dcsyne_ModTime (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry_ModTime LXxD_DirCacheSyntheticEntry_ModTime LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_ModTime(c) LxResult c::dcsyne_ModTime (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry_Size double dcsyne_Size (void)
#define LXxO_DirCacheSyntheticEntry_Size LXxD_DirCacheSyntheticEntry_Size LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry_Size(c) double c::dcsyne_Size (void)
template <class T>
class CLxIfc_DirCacheSyntheticEntry : public CLxInterface
{
    static LxResult
  Path (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    try {
      return loc->dcsyne_Path (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  OverrideParent (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    try {
      return loc->dcsyne_OverrideParent (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    try {
      return loc->dcsyne_Name (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DirUsername (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    try {
      return loc->dcsyne_DirUsername (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FileExtension (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    try {
      return loc->dcsyne_FileExtension (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsFile (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    try {
      return loc->dcsyne_IsFile ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DirBuild (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    try {
      return loc->dcsyne_DirBuild ();
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  DirCount (LXtObjectID wcom, int listMode)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    return loc->dcsyne_DirCount (listMode);
  }
    static LxResult
  DirByIndex (LXtObjectID wcom, int listMode, unsigned int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    try {
      return loc->dcsyne_DirByIndex (listMode,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ModTime (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    try {
      return loc->dcsyne_ModTime (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static double
  Size (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry, loc);
    return loc->dcsyne_Size ();
  }
  ILxDirCacheSyntheticEntry vt;
public:
  CLxIfc_DirCacheSyntheticEntry ()
  {
    vt.Path = Path;
    vt.OverrideParent = OverrideParent;
    vt.Name = Name;
    vt.DirUsername = DirUsername;
    vt.FileExtension = FileExtension;
    vt.IsFile = IsFile;
    vt.DirBuild = DirBuild;
    vt.DirCount = DirCount;
    vt.DirByIndex = DirByIndex;
    vt.ModTime = ModTime;
    vt.Size = Size;
    vTable = &vt.iunk;
    iid = &lx::guid_DirCacheSyntheticEntry;
  }
};
class CLxLoc_DirCacheSyntheticEntry : public CLxLocalize<ILxDirCacheSyntheticEntryID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DirCacheSyntheticEntry() {_init();}
  CLxLoc_DirCacheSyntheticEntry(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DirCacheSyntheticEntry(const CLxLoc_DirCacheSyntheticEntry &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DirCacheSyntheticEntry;}
    LxResult
  Path (char *buf, int len)
  {
    return m_loc[0]->Path (m_loc,buf,len);
  }
    LxResult
  OverrideParent (char *buf, int len)
  {
    return m_loc[0]->OverrideParent (m_loc,buf,len);
  }
    LxResult
  Name (char *buf, int len)
  {
    return m_loc[0]->Name (m_loc,buf,len);
  }
    LxResult
  DirUsername (char *buf, int len)
  {
    return m_loc[0]->DirUsername (m_loc,buf,len);
  }
    LxResult
  FileExtension (char *buf, int len)
  {
    return m_loc[0]->FileExtension (m_loc,buf,len);
  }
    LxResult
  IsFile (void)
  {
    return m_loc[0]->IsFile (m_loc);
  }
    LxResult
  DirBuild (void)
  {
    return m_loc[0]->DirBuild (m_loc);
  }
    unsigned int
  DirCount (int listMode)
  {
    return m_loc[0]->DirCount (m_loc,listMode);
  }
    LxResult
  DirByIndex (int listMode, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->DirByIndex (m_loc,listMode,index,ppvObj);
  }
    CLxResult
  DirByIndex (int listMode, unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->DirByIndex(m_loc,listMode,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ModTime (char *buf, int len)
  {
    return m_loc[0]->ModTime (m_loc,buf,len);
  }
    double
  Size (void)
  {
    return m_loc[0]->Size (m_loc);
  }
};

class CLxLoc_MergedFileSysDest : public CLxLocalize<ILxMergedFileSysDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MergedFileSysDest() {_init();}
  CLxLoc_MergedFileSysDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MergedFileSysDest(const CLxLoc_MergedFileSysDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MergedFileSysDest;}
    LxResult
  MergedEntry (void **ppvObj)
  {
    return m_loc[0]->MergedEntry (m_loc,ppvObj);
  }
    CLxResult
  MergedEntry (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->MergedEntry(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  EntryCount (unsigned int *count)
  {
    return m_loc[0]->EntryCount (m_loc,count);
  }
    LxResult
  EntryByIndex (int index, void **ppvObj)
  {
    return m_loc[0]->EntryByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  EntryByIndex (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->EntryByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Path (char *buf, int len)
  {
    return m_loc[0]->Path (m_loc,buf,len);
  }
};

class CLxLoc_FileSysDest : public CLxLocalize<ILxFileSysDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_FileSysDest() {_init();}
  CLxLoc_FileSysDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_FileSysDest(const CLxLoc_FileSysDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_FileSysDest;}
    LxResult
  Path (const char **path)
  {
    return m_loc[0]->Path (m_loc,path);
  }
    LxResult
  IsDir (void)
  {
    return m_loc[0]->IsDir (m_loc);
  }
    LxResult
  AsDir (const char **dir)
  {
    return m_loc[0]->AsDir (m_loc,dir);
  }
};

class CLxLoc_DirCacheManualOrderDest : public CLxLocalize<ILxDirCacheManualOrderDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DirCacheManualOrderDest() {_init();}
  CLxLoc_DirCacheManualOrderDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DirCacheManualOrderDest(const CLxLoc_DirCacheManualOrderDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DirCacheManualOrderDest;}
    LxResult
  BetweenPaths (void **ppvObj, const char **nameBefore, const char **nameAfter, int asPaths)
  {
    return m_loc[0]->BetweenPaths (m_loc,ppvObj,nameBefore,nameAfter,asPaths);
  }
    CLxResult
  BetweenPaths (CLxLocalizedObject &o_dest, const char **nameBefore, const char **nameAfter, int asPaths)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->BetweenPaths(m_loc,&o_obj,nameBefore,nameAfter,asPaths);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_DirCacheGridPosDest : public CLxLocalize<ILxDirCacheGridPosDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DirCacheGridPosDest() {_init();}
  CLxLoc_DirCacheGridPosDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DirCacheGridPosDest(const CLxLoc_DirCacheGridPosDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DirCacheGridPosDest;}
    LxResult
  GridPos (void **ppvObj, unsigned int *x, unsigned int *y)
  {
    return m_loc[0]->GridPos (m_loc,ppvObj,x,y);
  }
    CLxResult
  GridPos (CLxLocalizedObject &o_dest, unsigned int *x, unsigned int *y)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GridPos(m_loc,&o_obj,x,y);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_DirCacheSynthetic {
  public:
    virtual ~CLxImpl_DirCacheSynthetic() {}
    virtual LxResult
      dcsyn_Lookup (const char *path, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyn_Root (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_DirCacheSynthetic_Lookup LxResult dcsyn_Lookup (const char *path, void **ppvObj)
#define LXxO_DirCacheSynthetic_Lookup LXxD_DirCacheSynthetic_Lookup LXx_OVERRIDE
#define LXxC_DirCacheSynthetic_Lookup(c) LxResult c::dcsyn_Lookup (const char *path, void **ppvObj)
#define LXxD_DirCacheSynthetic_Root LxResult dcsyn_Root (void **ppvObj)
#define LXxO_DirCacheSynthetic_Root LXxD_DirCacheSynthetic_Root LXx_OVERRIDE
#define LXxC_DirCacheSynthetic_Root(c) LxResult c::dcsyn_Root (void **ppvObj)
template <class T>
class CLxIfc_DirCacheSynthetic : public CLxInterface
{
    static LxResult
  Lookup (LXtObjectID wcom, const char *path, void **ppvObj)
  {
    LXCWxINST (CLxImpl_DirCacheSynthetic, loc);
    try {
      return loc->dcsyn_Lookup (path,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Root (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_DirCacheSynthetic, loc);
    try {
      return loc->dcsyn_Root (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxDirCacheSynthetic vt;
public:
  CLxIfc_DirCacheSynthetic ()
  {
    vt.Lookup = Lookup;
    vt.Root = Root;
    vTable = &vt.iunk;
    iid = &lx::guid_DirCacheSynthetic;
  }
};
class CLxLoc_DirCacheSynthetic : public CLxLocalize<ILxDirCacheSyntheticID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DirCacheSynthetic() {_init();}
  CLxLoc_DirCacheSynthetic(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DirCacheSynthetic(const CLxLoc_DirCacheSynthetic &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DirCacheSynthetic;}
    LxResult
  Lookup (const char *path, void **ppvObj)
  {
    return m_loc[0]->Lookup (m_loc,path,ppvObj);
  }
    CLxResult
  Lookup (const char *path, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Lookup(m_loc,path,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Root (void **ppvObj)
  {
    return m_loc[0]->Root (m_loc,ppvObj);
  }
    CLxResult
  Root (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Root(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_BasePathAddDest : public CLxLocalize<ILxBasePathAddDestID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_BasePathAddDest() {_init();}
  CLxLoc_BasePathAddDest(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_BasePathAddDest(const CLxLoc_BasePathAddDest &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_BasePathAddDest;}
    LxResult
  AddBasePath (const char *setName, const char *path)
  {
    return m_loc[0]->AddBasePath (m_loc,setName,path);
  }
};

class CLxLoc_DirCacheService : public CLxLocalizedService
{
public:
  ILxDirCacheServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_DirCacheService() {_init();set();}
 ~CLxLoc_DirCacheService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxDirCacheServiceID>(lx::GetGlobal(&lx::guid_DirCacheService));}
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
  RootCount (int *count)
  {
    return m_loc[0]->RootCount (m_loc,count);
  }
    LxResult
  RootByIndex (int index, void **ppvObj)
  {
    return m_loc[0]->RootByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  RootByIndex (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->RootByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RootLock (void)
  {
    return m_loc[0]->RootLock (m_loc);
  }
    LxResult
  RootUnlock (void)
  {
    return m_loc[0]->RootUnlock (m_loc);
  }
    LxResult
  Lookup (const char *path, void **ppvObj)
  {
    return m_loc[0]->Lookup (m_loc,path,ppvObj);
  }
    CLxResult
  Lookup (const char *path, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Lookup(m_loc,path,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CachedThumbnailAsyncCancel (const char *ident)
  {
    return m_loc[0]->CachedThumbnailAsyncCancel (m_loc,ident);
  }
    LxResult
  SetPosOnDrop (const char *path, ILxUnknownID dest)
  {
    return m_loc[0]->SetPosOnDrop (m_loc,path,(ILxUnknownID)dest);
  }
    LxResult
  AttributesChanged (ILxUnknownID dirCacheEntry, int which, const char *attribute)
  {
    return m_loc[0]->AttributesChanged (m_loc,(ILxUnknownID)dirCacheEntry,which,attribute);
  }
    LxResult
  ScanForChanges (const char *path)
  {
    return m_loc[0]->ScanForChanges (m_loc,path);
  }
    LxResult
  AddClient (void)
  {
    return m_loc[0]->AddClient (m_loc);
  }
    LxResult
  RemoveClient (void)
  {
    return m_loc[0]->RemoveClient (m_loc);
  }
    LxResult
  ParseName (const char *filename, char *baseName, int baseNameLen, char *path, int pathLen)
  {
    return m_loc[0]->ParseName (m_loc,filename,baseName,baseNameLen,path,pathLen);
  }
    LxResult
  PathCompose (char *filename, int filenameLen, const char *baseName, const char *path)
  {
    return m_loc[0]->PathCompose (m_loc,filename,filenameLen,baseName,path);
  }
    LxResult
  IsChildOfPath (const char *possibleChild, const char *parentToTestAgainsts, int orIsSame)
  {
    return m_loc[0]->IsChildOfPath (m_loc,possibleChild,parentToTestAgainsts,orIsSame);
  }
    LxResult
  ToLocalAlias (char *path, char *buf, int len)
  {
    return m_loc[0]->ToLocalAlias (m_loc,path,buf,len);
  }
    LxResult
  ArePathsEqual (const char *path1, const char *path2)
  {
    return m_loc[0]->ArePathsEqual (m_loc,path1,path2);
  }
    LxResult
  CanBeRenamed (const char *path)
  {
    return m_loc[0]->CanBeRenamed (m_loc,path);
  }
    LxResult
  MakeDirHierarchy (const char *path, int skipLastPart)
  {
    return m_loc[0]->MakeDirHierarchy (m_loc,path,skipLastPart);
  }
    LxResult
  MakeUniqueIn (ILxUnknownID object, const char *filename, char *buf, int len)
  {
    return m_loc[0]->MakeUniqueIn (m_loc,(ILxUnknownID)object,filename,buf,len);
  }
};

class CLxLoc_DirCacheEntry : public CLxLocalize<ILxDirCacheEntryID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DirCacheEntry() {_init();}
  CLxLoc_DirCacheEntry(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DirCacheEntry(const CLxLoc_DirCacheEntry &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DirCacheEntry;}
    LxResult
  Type (int *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  DirList (int listMode, void **ppvObj, int asCopy)
  {
    return m_loc[0]->DirList (m_loc,listMode,ppvObj,asCopy);
  }
    CLxResult
  DirList (int listMode, CLxLocalizedObject &o_dest, int asCopy)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->DirList(m_loc,listMode,&o_obj,asCopy);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned int
  DirCount (int listMode)
  {
    return m_loc[0]->DirCount (m_loc,listMode);
  }
    LxResult
  Path (char *buf, int len)
  {
    return m_loc[0]->Path (m_loc,buf,len);
  }
    LxResult
  Name (char *buf, int len)
  {
    return m_loc[0]->Name (m_loc,buf,len);
  }
    LxResult
  Extension (char *buf, int len)
  {
    return m_loc[0]->Extension (m_loc,buf,len);
  }
    LxResult
  Size (double *size)
  {
    return m_loc[0]->Size (m_loc,size);
  }
    LxResult
  ModTime (char *buf, int len)
  {
    return m_loc[0]->ModTime (m_loc,buf,len);
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
  ReferenceSource (void **ppvObj)
  {
    return m_loc[0]->ReferenceSource (m_loc,ppvObj);
  }
    CLxResult
  ReferenceSource (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ReferenceSource(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ReferencedList (void **ppvObj, int asCopy)
  {
    return m_loc[0]->ReferencedList (m_loc,ppvObj,asCopy);
  }
    CLxResult
  ReferencedList (CLxLocalizedObject &o_dest, int asCopy)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ReferencedList(m_loc,&o_obj,asCopy);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned int
  ReferencedCount (void)
  {
    return m_loc[0]->ReferencedCount (m_loc);
  }
    LxResult
  WasRecognized (void)
  {
    return m_loc[0]->WasRecognized (m_loc);
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
  UserMarkup (void **ppvObj, int asWritable)
  {
    return m_loc[0]->UserMarkup (m_loc,ppvObj,asWritable);
  }
    CLxResult
  UserMarkup (CLxLocalizedObject &o_dest, int asWritable)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->UserMarkup(m_loc,&o_obj,asWritable);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SharedMarkup (void **ppvObj, int asWritable)
  {
    return m_loc[0]->SharedMarkup (m_loc,ppvObj,asWritable);
  }
    CLxResult
  SharedMarkup (CLxLocalizedObject &o_dest, int asWritable)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SharedMarkup(m_loc,&o_obj,asWritable);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CommitUserMarkup (ILxUnknownID userMarkup)
  {
    return m_loc[0]->CommitUserMarkup (m_loc,(ILxUnknownID)userMarkup);
  }
    LxResult
  CommitSharedMarkup (ILxUnknownID sharedMarkup)
  {
    return m_loc[0]->CommitSharedMarkup (m_loc,(ILxUnknownID)sharedMarkup);
  }
    LxResult
  Label (char *buf, int len)
  {
    return m_loc[0]->Label (m_loc,buf,len);
  }
    LxResult
  Desc (char *buf, int len)
  {
    return m_loc[0]->Desc (m_loc,buf,len);
  }
    LxResult
  ToolTip (char *buf, int len)
  {
    return m_loc[0]->ToolTip (m_loc,buf,len);
  }
    LxResult
  Thumbnail (int w, int h, unsigned int *idealW, unsigned int *idealH, void **ppvObj)
  {
    return m_loc[0]->Thumbnail (m_loc,w,h,idealW,idealH,ppvObj);
  }
    CLxResult
  Thumbnail (int w, int h, unsigned int *idealW, unsigned int *idealH, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Thumbnail(m_loc,w,h,idealW,idealH,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CachedThumbnail (int size, unsigned int *idealW, unsigned int *idealH, void **ppvObj)
  {
    return m_loc[0]->CachedThumbnail (m_loc,size,idealW,idealH,ppvObj);
  }
    CLxResult
  CachedThumbnail (int size, unsigned int *idealW, unsigned int *idealH, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CachedThumbnail(m_loc,size,idealW,idealH,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CachedThumbnailCustom (int w, int h, unsigned int *idealW, unsigned int *idealH, void **ppvObj)
  {
    return m_loc[0]->CachedThumbnailCustom (m_loc,w,h,idealW,idealH,ppvObj);
  }
    CLxResult
  CachedThumbnailCustom (int w, int h, unsigned int *idealW, unsigned int *idealH, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CachedThumbnailCustom(m_loc,w,h,idealW,idealH,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CachedThumbnailAsync (int size, unsigned int *idealW, unsigned int *idealH, void **ppvObj, ILxUnknownID asyncHandler)
  {
    return m_loc[0]->CachedThumbnailAsync (m_loc,size,idealW,idealH,ppvObj,(ILxUnknownID)asyncHandler);
  }
    CLxResult
  CachedThumbnailAsync (int size, unsigned int *idealW, unsigned int *idealH, CLxLocalizedObject &o_dest, ILxUnknownID asyncHandler)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CachedThumbnailAsync(m_loc,size,idealW,idealH,&o_obj,(ILxUnknownID)asyncHandler);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CachedThumbnailCustomAsync (int w, int h, unsigned int *idealW, unsigned int *idealH, void **ppvObj, ILxUnknownID asyncHandler)
  {
    return m_loc[0]->CachedThumbnailCustomAsync (m_loc,w,h,idealW,idealH,ppvObj,(ILxUnknownID)asyncHandler);
  }
    CLxResult
  CachedThumbnailCustomAsync (int w, int h, unsigned int *idealW, unsigned int *idealH, CLxLocalizedObject &o_dest, ILxUnknownID asyncHandler)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CachedThumbnailCustomAsync(m_loc,w,h,idealW,idealH,&o_obj,(ILxUnknownID)asyncHandler);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ChildManualOrderLookup (const char *childPath, unsigned int *pos)
  {
    return m_loc[0]->ChildManualOrderLookup (m_loc,childPath,pos);
  }
    LxResult
  ChildManualOrderSet (const char *childPath, unsigned int pos)
  {
    return m_loc[0]->ChildManualOrderSet (m_loc,childPath,pos);
  }
    LxResult
  ChildGridPositionLookup (const char *childPath, unsigned int *x, unsigned int *y)
  {
    return m_loc[0]->ChildGridPositionLookup (m_loc,childPath,x,y);
  }
    LxResult
  ChildGridPositionSet (const char *childPath, unsigned int x, unsigned int y)
  {
    return m_loc[0]->ChildGridPositionSet (m_loc,childPath,x,y);
  }
    LxResult
  GridExtents (unsigned int *bottom, unsigned int *right)
  {
    return m_loc[0]->GridExtents (m_loc,bottom,right);
  }
    LxResult
  GridSetExtents (unsigned int bottom, unsigned int right)
  {
    return m_loc[0]->GridSetExtents (m_loc,bottom,right);
  }
    LxResult
  GridInsert (int doRows, unsigned int x, unsigned int y, unsigned int count)
  {
    return m_loc[0]->GridInsert (m_loc,doRows,x,y,count);
  }
    LxResult
  GridRemove (int doRows, unsigned int x, unsigned int y, unsigned int count, int force)
  {
    return m_loc[0]->GridRemove (m_loc,doRows,x,y,count,force);
  }
    LxResult
  GridIsEmpty (int doRows, unsigned int x, unsigned int y)
  {
    return m_loc[0]->GridIsEmpty (m_loc,doRows,x,y);
  }
    LxResult
  GridIsEmptyCell (unsigned int x, unsigned int y, void **ppvObj)
  {
    return m_loc[0]->GridIsEmptyCell (m_loc,x,y,ppvObj);
  }
    CLxResult
  GridIsEmptyCell (unsigned int x, unsigned int y, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GridIsEmptyCell(m_loc,x,y,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Username (char *buf, int len)
  {
    return m_loc[0]->Username (m_loc,buf,len);
  }
    LxResult
  OverrideParent (char *buf, int len)
  {
    return m_loc[0]->OverrideParent (m_loc,buf,len);
  }
};

class CLxImpl_DirCacheFileMetrics {
  public:
    virtual ~CLxImpl_DirCacheFileMetrics() {}
    virtual LxResult
      dcfilemetrics_Metadata (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcfilemetrics_Markup (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcfilemetrics_Flags (int *flags)
        { return LXe_NOTIMPL; }
};
#define LXxD_DirCacheFileMetrics_Metadata LxResult dcfilemetrics_Metadata (void **ppvObj)
#define LXxO_DirCacheFileMetrics_Metadata LXxD_DirCacheFileMetrics_Metadata LXx_OVERRIDE
#define LXxC_DirCacheFileMetrics_Metadata(c) LxResult c::dcfilemetrics_Metadata (void **ppvObj)
#define LXxD_DirCacheFileMetrics_Markup LxResult dcfilemetrics_Markup (void **ppvObj)
#define LXxO_DirCacheFileMetrics_Markup LXxD_DirCacheFileMetrics_Markup LXx_OVERRIDE
#define LXxC_DirCacheFileMetrics_Markup(c) LxResult c::dcfilemetrics_Markup (void **ppvObj)
#define LXxD_DirCacheFileMetrics_Flags LxResult dcfilemetrics_Flags (int *flags)
#define LXxO_DirCacheFileMetrics_Flags LXxD_DirCacheFileMetrics_Flags LXx_OVERRIDE
#define LXxC_DirCacheFileMetrics_Flags(c) LxResult c::dcfilemetrics_Flags (int *flags)
template <class T>
class CLxIfc_DirCacheFileMetrics : public CLxInterface
{
    static LxResult
  Metadata (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_DirCacheFileMetrics, loc);
    try {
      return loc->dcfilemetrics_Metadata (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Markup (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_DirCacheFileMetrics, loc);
    try {
      return loc->dcfilemetrics_Markup (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Flags (LXtObjectID wcom, int *flags)
  {
    LXCWxINST (CLxImpl_DirCacheFileMetrics, loc);
    try {
      return loc->dcfilemetrics_Flags (flags);
    } catch (LxResult rc) { return rc; }
  }
  ILxDirCacheFileMetrics vt;
public:
  CLxIfc_DirCacheFileMetrics ()
  {
    vt.Metadata = Metadata;
    vt.Markup = Markup;
    vt.Flags = Flags;
    vTable = &vt.iunk;
    iid = &lx::guid_DirCacheFileMetrics;
  }
};
class CLxLoc_DirCacheFileMetrics : public CLxLocalize<ILxDirCacheFileMetricsID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DirCacheFileMetrics() {_init();}
  CLxLoc_DirCacheFileMetrics(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DirCacheFileMetrics(const CLxLoc_DirCacheFileMetrics &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DirCacheFileMetrics;}
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

class CLxImpl_DirCacheSyntheticEntry1 {
  public:
    virtual ~CLxImpl_DirCacheSyntheticEntry1() {}
    virtual LxResult
      dcsyne_Path (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_Name (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_DirUsername (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_FileExtension (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_IsFile (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_DirBuild (void)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      dcsyne_DirCount (int listMode)
        = 0;
    virtual LxResult
      dcsyne_DirByIndex (int listMode, unsigned int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dcsyne_ModTime (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual double
      dcsyne_Size (void)
        = 0;
};
#define LXxD_DirCacheSyntheticEntry1_Path LxResult dcsyne_Path (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry1_Path LXxD_DirCacheSyntheticEntry1_Path LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry1_Path(c) LxResult c::dcsyne_Path (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry1_Name LxResult dcsyne_Name (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry1_Name LXxD_DirCacheSyntheticEntry1_Name LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry1_Name(c) LxResult c::dcsyne_Name (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry1_DirUsername LxResult dcsyne_DirUsername (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry1_DirUsername LXxD_DirCacheSyntheticEntry1_DirUsername LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry1_DirUsername(c) LxResult c::dcsyne_DirUsername (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry1_FileExtension LxResult dcsyne_FileExtension (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry1_FileExtension LXxD_DirCacheSyntheticEntry1_FileExtension LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry1_FileExtension(c) LxResult c::dcsyne_FileExtension (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry1_IsFile LxResult dcsyne_IsFile (void)
#define LXxO_DirCacheSyntheticEntry1_IsFile LXxD_DirCacheSyntheticEntry1_IsFile LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry1_IsFile(c) LxResult c::dcsyne_IsFile (void)
#define LXxD_DirCacheSyntheticEntry1_DirBuild LxResult dcsyne_DirBuild (void)
#define LXxO_DirCacheSyntheticEntry1_DirBuild LXxD_DirCacheSyntheticEntry1_DirBuild LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry1_DirBuild(c) LxResult c::dcsyne_DirBuild (void)
#define LXxD_DirCacheSyntheticEntry1_DirCount unsigned int dcsyne_DirCount (int listMode)
#define LXxO_DirCacheSyntheticEntry1_DirCount LXxD_DirCacheSyntheticEntry1_DirCount LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry1_DirCount(c) unsigned int c::dcsyne_DirCount (int listMode)
#define LXxD_DirCacheSyntheticEntry1_DirByIndex LxResult dcsyne_DirByIndex (int listMode, unsigned int index, void **ppvObj)
#define LXxO_DirCacheSyntheticEntry1_DirByIndex LXxD_DirCacheSyntheticEntry1_DirByIndex LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry1_DirByIndex(c) LxResult c::dcsyne_DirByIndex (int listMode, unsigned int index, void **ppvObj)
#define LXxD_DirCacheSyntheticEntry1_ModTime LxResult dcsyne_ModTime (char *buf, int len)
#define LXxO_DirCacheSyntheticEntry1_ModTime LXxD_DirCacheSyntheticEntry1_ModTime LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry1_ModTime(c) LxResult c::dcsyne_ModTime (char *buf, int len)
#define LXxD_DirCacheSyntheticEntry1_Size double dcsyne_Size (void)
#define LXxO_DirCacheSyntheticEntry1_Size LXxD_DirCacheSyntheticEntry1_Size LXx_OVERRIDE
#define LXxC_DirCacheSyntheticEntry1_Size(c) double c::dcsyne_Size (void)
template <class T>
class CLxIfc_DirCacheSyntheticEntry1 : public CLxInterface
{
    static LxResult
  Path (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
    try {
      return loc->dcsyne_Path (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
    try {
      return loc->dcsyne_Name (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DirUsername (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
    try {
      return loc->dcsyne_DirUsername (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FileExtension (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
    try {
      return loc->dcsyne_FileExtension (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IsFile (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
    try {
      return loc->dcsyne_IsFile ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DirBuild (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
    try {
      return loc->dcsyne_DirBuild ();
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  DirCount (LXtObjectID wcom, int listMode)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
    return loc->dcsyne_DirCount (listMode);
  }
    static LxResult
  DirByIndex (LXtObjectID wcom, int listMode, unsigned int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
    try {
      return loc->dcsyne_DirByIndex (listMode,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ModTime (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
    try {
      return loc->dcsyne_ModTime (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static double
  Size (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_DirCacheSyntheticEntry1, loc);
    return loc->dcsyne_Size ();
  }
  ILxDirCacheSyntheticEntry1 vt;
public:
  CLxIfc_DirCacheSyntheticEntry1 ()
  {
    vt.Path = Path;
    vt.Name = Name;
    vt.DirUsername = DirUsername;
    vt.FileExtension = FileExtension;
    vt.IsFile = IsFile;
    vt.DirBuild = DirBuild;
    vt.DirCount = DirCount;
    vt.DirByIndex = DirByIndex;
    vt.ModTime = ModTime;
    vt.Size = Size;
    vTable = &vt.iunk;
    iid = &lx::guid_DirCacheSyntheticEntry1;
  }
};
class CLxLoc_DirCacheSyntheticEntry1 : public CLxLocalize<ILxDirCacheSyntheticEntry1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DirCacheSyntheticEntry1() {_init();}
  CLxLoc_DirCacheSyntheticEntry1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DirCacheSyntheticEntry1(const CLxLoc_DirCacheSyntheticEntry1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DirCacheSyntheticEntry1;}
    LxResult
  Path (char *buf, int len)
  {
    return m_loc[0]->Path (m_loc,buf,len);
  }
    LxResult
  Name (char *buf, int len)
  {
    return m_loc[0]->Name (m_loc,buf,len);
  }
    LxResult
  DirUsername (char *buf, int len)
  {
    return m_loc[0]->DirUsername (m_loc,buf,len);
  }
    LxResult
  FileExtension (char *buf, int len)
  {
    return m_loc[0]->FileExtension (m_loc,buf,len);
  }
    LxResult
  IsFile (void)
  {
    return m_loc[0]->IsFile (m_loc);
  }
    LxResult
  DirBuild (void)
  {
    return m_loc[0]->DirBuild (m_loc);
  }
    unsigned int
  DirCount (int listMode)
  {
    return m_loc[0]->DirCount (m_loc,listMode);
  }
    LxResult
  DirByIndex (int listMode, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->DirByIndex (m_loc,listMode,index,ppvObj);
  }
    CLxResult
  DirByIndex (int listMode, unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->DirByIndex(m_loc,listMode,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ModTime (char *buf, int len)
  {
    return m_loc[0]->ModTime (m_loc,buf,len);
  }
    double
  Size (void)
  {
    return m_loc[0]->Size (m_loc);
  }
};

class CLxImpl_DirEntryThumbAsync {
  public:
    virtual ~CLxImpl_DirEntryThumbAsync() {}
    virtual LxResult
      detasync_Ready (ILxUnknownID dirCacheEntry, unsigned int idealW, unsigned int idealH, ILxUnknownID image)
        { return LXe_NOTIMPL; }
    virtual LxResult
      detasync_Failed (ILxUnknownID dirCacheEntry)
        { return LXe_NOTIMPL; }
    virtual LxResult
      detasync_Ident (const char **ident)
        { return LXe_NOTIMPL; }
};
#define LXxD_DirEntryThumbAsync_Ready LxResult detasync_Ready (ILxUnknownID dirCacheEntry, unsigned int idealW, unsigned int idealH, ILxUnknownID image)
#define LXxO_DirEntryThumbAsync_Ready LXxD_DirEntryThumbAsync_Ready LXx_OVERRIDE
#define LXxC_DirEntryThumbAsync_Ready(c) LxResult c::detasync_Ready (ILxUnknownID dirCacheEntry, unsigned int idealW, unsigned int idealH, ILxUnknownID image)
#define LXxD_DirEntryThumbAsync_Failed LxResult detasync_Failed (ILxUnknownID dirCacheEntry)
#define LXxO_DirEntryThumbAsync_Failed LXxD_DirEntryThumbAsync_Failed LXx_OVERRIDE
#define LXxC_DirEntryThumbAsync_Failed(c) LxResult c::detasync_Failed (ILxUnknownID dirCacheEntry)
#define LXxD_DirEntryThumbAsync_Ident LxResult detasync_Ident (const char **ident)
#define LXxO_DirEntryThumbAsync_Ident LXxD_DirEntryThumbAsync_Ident LXx_OVERRIDE
#define LXxC_DirEntryThumbAsync_Ident(c) LxResult c::detasync_Ident (const char **ident)
template <class T>
class CLxIfc_DirEntryThumbAsync : public CLxInterface
{
    static LxResult
  Ready (LXtObjectID wcom, LXtObjectID dirCacheEntry, unsigned int idealW, unsigned int idealH, LXtObjectID image)
  {
    LXCWxINST (CLxImpl_DirEntryThumbAsync, loc);
    try {
      return loc->detasync_Ready ((ILxUnknownID)dirCacheEntry,idealW,idealH,(ILxUnknownID)image);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Failed (LXtObjectID wcom, LXtObjectID dirCacheEntry)
  {
    LXCWxINST (CLxImpl_DirEntryThumbAsync, loc);
    try {
      return loc->detasync_Failed ((ILxUnknownID)dirCacheEntry);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Ident (LXtObjectID wcom, const char **ident)
  {
    LXCWxINST (CLxImpl_DirEntryThumbAsync, loc);
    try {
      return loc->detasync_Ident (ident);
    } catch (LxResult rc) { return rc; }
  }
  ILxDirEntryThumbAsync vt;
public:
  CLxIfc_DirEntryThumbAsync ()
  {
    vt.Ready = Ready;
    vt.Failed = Failed;
    vt.Ident = Ident;
    vTable = &vt.iunk;
    iid = &lx::guid_DirEntryThumbAsync;
  }
};
class CLxLoc_DirEntryThumbAsync : public CLxLocalize<ILxDirEntryThumbAsyncID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DirEntryThumbAsync() {_init();}
  CLxLoc_DirEntryThumbAsync(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DirEntryThumbAsync(const CLxLoc_DirEntryThumbAsync &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DirEntryThumbAsync;}
    LxResult
  Ready (ILxUnknownID dirCacheEntry, unsigned int idealW, unsigned int idealH, ILxUnknownID image)
  {
    return m_loc[0]->Ready (m_loc,(ILxUnknownID)dirCacheEntry,idealW,idealH,(ILxUnknownID)image);
  }
    LxResult
  Failed (ILxUnknownID dirCacheEntry)
  {
    return m_loc[0]->Failed (m_loc,(ILxUnknownID)dirCacheEntry);
  }
    LxResult
  Ident (const char **ident)
  {
    return m_loc[0]->Ident (m_loc,ident);
  }
};

class CLxLoc_MergedDirCacheEntry : public CLxLocalize<ILxMergedDirCacheEntryID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MergedDirCacheEntry() {_init();}
  CLxLoc_MergedDirCacheEntry(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MergedDirCacheEntry(const CLxLoc_MergedDirCacheEntry &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MergedDirCacheEntry;}
    LxResult
  Path (char *buf, int len)
  {
    return m_loc[0]->Path (m_loc,buf,len);
  }
    LxResult
  EntryCount (int *count)
  {
    return m_loc[0]->EntryCount (m_loc,count);
  }
    LxResult
  EntryByIndex (int index, void **ppvObj)
  {
    return m_loc[0]->EntryByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  EntryByIndex (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->EntryByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  UserPath (char *buf, int len)
  {
    return m_loc[0]->UserPath (m_loc,buf,len);
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
};

#endif

