/*
 * C++ wrapper for lxfile.h
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
#ifndef LXW_FILE_HPP
#define LXW_FILE_HPP

#include <lxfile.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_File1Service = {0xD792F5C0,0x0555,0x4FC7,0x83,0x2C,0xD2,0x00,0xCD,0xA4,0x2D,0x97};
    static const LXtGUID guid_FileService = {0x742B3D3D,0x1151,0x4AB7,0xAF,0x4F,0x66,0x8D,0x18,0x46,0x8D,0x7F};
    static const LXtGUID guid_FileReference = {0xA18B9A9D,0x6623,0x4463,0xB6,0xAF,0x46,0x97,0x71,0xB4,0x14,0x85};
    static const LXtGUID guid_VirtualDevice = {0x60B61E9D,0x17F3,0x4068,0x85,0xC2,0x37,0x99,0xA7,0x3F,0x5D,0x95};
    static const LXtGUID guid_FileRedirect = {0x05DACE30,0xBFA0,0x453C,0xAB,0x7A,0x33,0xDF,0x35,0x82,0x7A,0x35};
};


class CLxLoc_FileService : public CLxLocalizedService
{
public:
  ILxFileServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_FileService() {_init();set();}
 ~CLxLoc_FileService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxFileServiceID>(lx::GetGlobal(&lx::guid_FileService));}
    LxResult
  FileSystemPath (const char *name, const char **path)
  {
    return m_loc[0]->FileSystemPath (m_loc,name,path);
  }
    LxResult
  IsAbsolutePath (const char *path)
  {
    return m_loc[0]->IsAbsolutePath (m_loc,path);
  }
    LxResult
  ArePathsEqual (const char *path1, const char *path2)
  {
    return m_loc[0]->ArePathsEqual (m_loc,path1,path2);
  }
    LxResult
  ParsePath (const char *filename, unsigned component, char *buf, unsigned len)
  {
    return m_loc[0]->ParsePath (m_loc,filename,component,buf,len);
  }
    LxResult
  ParsePath (const char *filename, unsigned component, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ParsePath (m_loc,filename,component,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ComposePath (const char *basename, const char *path, char *buf, unsigned len)
  {
    return m_loc[0]->ComposePath (m_loc,basename,path,buf,len);
  }
    LxResult
  ComposePath (const char *basename, const char *path, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ComposePath (m_loc,basename,path,buf,len);
    LXWx_SBUF2
  }
    LxResult
  SetExtension (const char *filename, const char *extension, char *buf, unsigned len)
  {
    return m_loc[0]->SetExtension (m_loc,filename,extension,buf,len);
  }
    LxResult
  SetExtension (const char *filename, const char *extension, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->SetExtension (m_loc,filename,extension,buf,len);
    LXWx_SBUF2
  }
    LxResult
  MakeRelative (const char *filename, const char *path, char *buf, unsigned len)
  {
    return m_loc[0]->MakeRelative (m_loc,filename,path,buf,len);
  }
    LxResult
  MakeRelative (const char *filename, const char *path, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->MakeRelative (m_loc,filename,path,buf,len);
    LXWx_SBUF2
  }
    LxResult
  MakeUnique (const char *filename, char *buf, unsigned len)
  {
    return m_loc[0]->MakeUnique (m_loc,filename,buf,len);
  }
    LxResult
  MakeUnique (const char *filename, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->MakeUnique (m_loc,filename,buf,len);
    LXWx_SBUF2
  }
    LxResult
  MakeDirectory (const char *path)
  {
    return m_loc[0]->MakeDirectory (m_loc,path);
  }
    LxResult
  TestFileType (const char *filename, unsigned *type)
  {
    return m_loc[0]->TestFileType (m_loc,filename,type);
  }
    LxResult
  TestFileMode (const char *filename, unsigned *mode)
  {
    return m_loc[0]->TestFileMode (m_loc,filename,mode);
  }
    LxResult
  RenameFile (const char *from, const char *to)
  {
    return m_loc[0]->RenameFile (m_loc,from,to);
  }
    LxResult
  FileCopy (const char *srcFilePath, const char *dstFilePath, unsigned overwrite)
  {
    return m_loc[0]->FileCopy (m_loc,srcFilePath,dstFilePath,overwrite);
  }
    LxResult
  FileDelete (const char *filename)
  {
    return m_loc[0]->FileDelete (m_loc,filename);
  }
    LxResult
  DirDelete (const char *filename)
  {
    return m_loc[0]->DirDelete (m_loc,filename);
  }
    LxResult
  OpenFileWithDefaultApp (const char *filename)
  {
    return m_loc[0]->OpenFileWithDefaultApp (m_loc,filename);
  }
    LxResult
  RevealInFileViewer (const char *filename)
  {
    return m_loc[0]->RevealInFileViewer (m_loc,filename);
  }
    LxResult
  Execute (const char **argv, int show, int force32)
  {
    return m_loc[0]->Execute (m_loc,argv,show,force32);
  }
    LxResult
  FileToURL (const char *filename, char *buf, unsigned len)
  {
    return m_loc[0]->FileToURL (m_loc,filename,buf,len);
  }
    LxResult
  FileToURL (const char *filename, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->FileToURL (m_loc,filename,buf,len);
    LXWx_SBUF2
  }
    LxResult
  FileFromURL (const char *url, char *buf, unsigned len)
  {
    return m_loc[0]->FileFromURL (m_loc,url,buf,len);
  }
    LxResult
  FileFromURL (const char *url, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->FileFromURL (m_loc,url,buf,len);
    LXWx_SBUF2
  }
    LxResult
  FromLocal (const char *local, char *buf, unsigned len)
  {
    return m_loc[0]->FromLocal (m_loc,local,buf,len);
  }
    LxResult
  FromLocal (const char *local, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->FromLocal (m_loc,local,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ToLocal (char *neutral, char *buf, unsigned len)
  {
    return m_loc[0]->ToLocal (m_loc,neutral,buf,len);
  }
    LxResult
  ToLocal (char *neutral, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ToLocal (m_loc,neutral,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ToLocalAlias (const char *neutral, char *buf, unsigned len)
  {
    return m_loc[0]->ToLocalAlias (m_loc,neutral,buf,len);
  }
    LxResult
  ToLocalAlias (const char *neutral, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ToLocalAlias (m_loc,neutral,buf,len);
    LXWx_SBUF2
  }
    LxResult
  AllocReference (const char *path, void **ppvObj)
  {
    return m_loc[0]->AllocReference (m_loc,path,ppvObj);
  }
    CLxResult
  AllocReference (const char *path, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AllocReference(m_loc,path,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  FindSequencePattern (const char *filename, char *buf, unsigned len)
  {
    return m_loc[0]->FindSequencePattern (m_loc,filename,buf,len);
  }
    LxResult
  FindSequencePattern (const char *filename, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->FindSequencePattern (m_loc,filename,buf,len);
    LXWx_SBUF2
  }
    LxResult
  FindSequenceBounds (const char *pattern, unsigned *first, unsigned *last)
  {
    return m_loc[0]->FindSequenceBounds (m_loc,pattern,first,last);
  }
    LxResult
  GenerateSequenceName (const char *pattern, unsigned frame, char *buf, unsigned len)
  {
    return m_loc[0]->GenerateSequenceName (m_loc,pattern,frame,buf,len);
  }
    LxResult
  GenerateSequenceName (const char *pattern, unsigned frame, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->GenerateSequenceName (m_loc,pattern,frame,buf,len);
    LXWx_SBUF2
  }
    LxResult
  ValidateLicense (const char *product, int versionNum)
  {
    return m_loc[0]->ValidateLicense (m_loc,product,versionNum);
  }
    LxResult
  FileDateString (const char *filename, char *buf, int len)
  {
    return m_loc[0]->FileDateString (m_loc,filename,buf,len);
  }
    LxResult
  AllocRedirect (void **ppvObj)
  {
    return m_loc[0]->AllocRedirect (m_loc,ppvObj);
  }
    CLxResult
  AllocRedirect (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AllocRedirect(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  MakeLegalFilename (char *filename, int replaceDot)
  {
    return m_loc[0]->MakeLegalFilename (m_loc,filename,replaceDot);
  }
    unsigned
  PkgCountFiles (const char *package)
  {
    return m_loc[0]->PkgCountFiles (m_loc,package);
  }
    LxResult
  PkgFilename (const char *package, unsigned id, char *buf, int len)
  {
    return m_loc[0]->PkgFilename (m_loc,package,id,buf,len);
  }
    LxResult
  PkgHasFile (const char *package, const char *file)
  {
    return m_loc[0]->PkgHasFile (m_loc,package,file);
  }
    LxResult
  PkgExtract (const char *package, const char *file, const char *dest)
  {
    return m_loc[0]->PkgExtract (m_loc,package,file,dest);
  }
    LxResult
  PkgExtractAll (const char *package, const char *dest, const char *subDir)
  {
    return m_loc[0]->PkgExtractAll (m_loc,package,dest,subDir);
  }
};

class CLxLoc_FileReference : public CLxLocalize<ILxFileReferenceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_FileReference() {_init();}
  CLxLoc_FileReference(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_FileReference(const CLxLoc_FileReference &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_FileReference;}
    LxResult
  Path (const char **path)
  {
    return m_loc[0]->Path (m_loc,path);
  }
    LxResult
  NiceName (char *buf, unsigned len)
  {
    return m_loc[0]->NiceName (m_loc,buf,len);
  }
    LxResult
  NiceName (std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->NiceName (m_loc,buf,len);
    LXWx_SBUF2
  }
    LxResult
  Type (unsigned *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  Mode (unsigned *mode)
  {
    return m_loc[0]->Mode (m_loc,mode);
  }
    LxResult
  SubCount (unsigned *count)
  {
    return m_loc[0]->SubCount (m_loc,count);
  }
    LxResult
  SubByIndex (unsigned index, void **ppvObj)
  {
    return m_loc[0]->SubByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  SubByIndex (unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SubByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_VirtualDevice {
  public:
    virtual ~CLxImpl_VirtualDevice() {}
    virtual LxResult
      vdev_Initialize (const char *path)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vdev_Select (const char *sub)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vdev_Extract (const char *dest)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vdev_Scan (ILxUnknownID visitor)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vdev_Type (unsigned *type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vdev_Name (char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vdev_Date (char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vdev_Size (double *bytes)
        { return LXe_NOTIMPL; }
};
#define LXxD_VirtualDevice_Initialize LxResult vdev_Initialize (const char *path)
#define LXxO_VirtualDevice_Initialize LXxD_VirtualDevice_Initialize LXx_OVERRIDE
#define LXxC_VirtualDevice_Initialize(c) LxResult c::vdev_Initialize (const char *path)
#define LXxD_VirtualDevice_Select LxResult vdev_Select (const char *sub)
#define LXxO_VirtualDevice_Select LXxD_VirtualDevice_Select LXx_OVERRIDE
#define LXxC_VirtualDevice_Select(c) LxResult c::vdev_Select (const char *sub)
#define LXxD_VirtualDevice_Extract LxResult vdev_Extract (const char *dest)
#define LXxO_VirtualDevice_Extract LXxD_VirtualDevice_Extract LXx_OVERRIDE
#define LXxC_VirtualDevice_Extract(c) LxResult c::vdev_Extract (const char *dest)
#define LXxD_VirtualDevice_Scan LxResult vdev_Scan (ILxUnknownID visitor)
#define LXxO_VirtualDevice_Scan LXxD_VirtualDevice_Scan LXx_OVERRIDE
#define LXxC_VirtualDevice_Scan(c) LxResult c::vdev_Scan (ILxUnknownID visitor)
#define LXxD_VirtualDevice_Type LxResult vdev_Type (unsigned *type)
#define LXxO_VirtualDevice_Type LXxD_VirtualDevice_Type LXx_OVERRIDE
#define LXxC_VirtualDevice_Type(c) LxResult c::vdev_Type (unsigned *type)
#define LXxD_VirtualDevice_Name LxResult vdev_Name (char *buf, unsigned len)
#define LXxO_VirtualDevice_Name LXxD_VirtualDevice_Name LXx_OVERRIDE
#define LXxC_VirtualDevice_Name(c) LxResult c::vdev_Name (char *buf, unsigned len)
#define LXxD_VirtualDevice_Date LxResult vdev_Date (char *buf, unsigned len)
#define LXxO_VirtualDevice_Date LXxD_VirtualDevice_Date LXx_OVERRIDE
#define LXxC_VirtualDevice_Date(c) LxResult c::vdev_Date (char *buf, unsigned len)
#define LXxD_VirtualDevice_Size LxResult vdev_Size (double *bytes)
#define LXxO_VirtualDevice_Size LXxD_VirtualDevice_Size LXx_OVERRIDE
#define LXxC_VirtualDevice_Size(c) LxResult c::vdev_Size (double *bytes)
template <class T>
class CLxIfc_VirtualDevice : public CLxInterface
{
    static LxResult
  Initialize (LXtObjectID wcom, const char *path)
  {
    LXCWxINST (CLxImpl_VirtualDevice, loc);
    try {
      return loc->vdev_Initialize (path);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Select (LXtObjectID wcom, const char *sub)
  {
    LXCWxINST (CLxImpl_VirtualDevice, loc);
    try {
      return loc->vdev_Select (sub);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Extract (LXtObjectID wcom, const char *dest)
  {
    LXCWxINST (CLxImpl_VirtualDevice, loc);
    try {
      return loc->vdev_Extract (dest);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Scan (LXtObjectID wcom, LXtObjectID visitor)
  {
    LXCWxINST (CLxImpl_VirtualDevice, loc);
    try {
      return loc->vdev_Scan ((ILxUnknownID)visitor);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Type (LXtObjectID wcom, unsigned *type)
  {
    LXCWxINST (CLxImpl_VirtualDevice, loc);
    try {
      return loc->vdev_Type (type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_VirtualDevice, loc);
    try {
      return loc->vdev_Name (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Date (LXtObjectID wcom, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_VirtualDevice, loc);
    try {
      return loc->vdev_Date (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Size (LXtObjectID wcom, double *bytes)
  {
    LXCWxINST (CLxImpl_VirtualDevice, loc);
    try {
      return loc->vdev_Size (bytes);
    } catch (LxResult rc) { return rc; }
  }
  ILxVirtualDevice vt;
public:
  CLxIfc_VirtualDevice ()
  {
    vt.Initialize = Initialize;
    vt.Select = Select;
    vt.Extract = Extract;
    vt.Scan = Scan;
    vt.Type = Type;
    vt.Name = Name;
    vt.Date = Date;
    vt.Size = Size;
    vTable = &vt.iunk;
    iid = &lx::guid_VirtualDevice;
  }
};
class CLxLoc_VirtualDevice : public CLxLocalize<ILxVirtualDeviceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VirtualDevice() {_init();}
  CLxLoc_VirtualDevice(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VirtualDevice(const CLxLoc_VirtualDevice &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VirtualDevice;}
    LxResult
  Initialize (const char *path)
  {
    return m_loc[0]->Initialize (m_loc,path);
  }
    LxResult
  Select (const char *sub)
  {
    return m_loc[0]->Select (m_loc,sub);
  }
    LxResult
  Extract (const char *dest)
  {
    return m_loc[0]->Extract (m_loc,dest);
  }
    LxResult
  Scan (ILxUnknownID visitor)
  {
    return m_loc[0]->Scan (m_loc,(ILxUnknownID)visitor);
  }
    LxResult
  Type (unsigned *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  Name (char *buf, unsigned len)
  {
    return m_loc[0]->Name (m_loc,buf,len);
  }
    LxResult
  Name (std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->Name (m_loc,buf,len);
    LXWx_SBUF2
  }
    LxResult
  Date (char *buf, unsigned len)
  {
    return m_loc[0]->Date (m_loc,buf,len);
  }
    LxResult
  Date (std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->Date (m_loc,buf,len);
    LXWx_SBUF2
  }
    LxResult
  Size (double *bytes)
  {
    return m_loc[0]->Size (m_loc,bytes);
  }
};

class CLxLoc_FileRedirect : public CLxLocalize<ILxFileRedirectID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_FileRedirect() {_init();}
  CLxLoc_FileRedirect(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_FileRedirect(const CLxLoc_FileRedirect &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_FileRedirect;}
    LxResult
  NeutralFormat (unsigned allow)
  {
    return m_loc[0]->NeutralFormat (m_loc,allow);
  }
    LxResult
  AddSearchPath (const char *path)
  {
    return m_loc[0]->AddSearchPath (m_loc,path);
  }
    LxResult
  Locate (const char *path, const char *type, char *buf, unsigned len)
  {
    return m_loc[0]->Locate (m_loc,path,type,buf,len);
  }
    LxResult
  Locate (const char *path, const char *type, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->Locate (m_loc,path,type,buf,len);
    LXWx_SBUF2
  }
    LxResult
  LocateSequence (const char *pattern, const char *type, unsigned *first, unsigned *last, char *buf, unsigned len)
  {
    return m_loc[0]->LocateSequence (m_loc,pattern,type,first,last,buf,len);
  }
    LxResult
  LocateSequence (const char *pattern, const char *type, unsigned *first, unsigned *last, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->LocateSequence (m_loc,pattern,type,first,last,buf,len);
    LXWx_SBUF2
  }
    LxResult
  Reference (const char *path, char *buf, unsigned len)
  {
    return m_loc[0]->Reference (m_loc,path,buf,len);
  }
    LxResult
  Reference (const char *path, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->Reference (m_loc,path,buf,len);
    LXWx_SBUF2
  }
};

#endif

