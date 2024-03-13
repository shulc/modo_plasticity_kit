/*
 * C++ wrapper for lxcolormapping.h
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
#ifndef LXW_COLORMAPPING_HPP
#define LXW_COLORMAPPING_HPP

#include <lxcolormapping.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ColorMapping = {0x49B0319A,0xBBAA,0x4D43,0x84,0x47,0x63,0x1B,0xE7,0x29,0x7F,0xBB};
    static const LXtGUID guid_ColorMapping1 = {0x40D65C4F,0xD394,0x40E2,0xA7,0x1A,0xB1,0x74,0xE9,0x71,0xF4,0x62};
    static const LXtGUID guid_ColorMappingModule = {0x99D65C3D,0xD394,0x40E2,0xA7,0x1A,0xB1,0x74,0xE9,0x71,0xF4,0x62};
    static const LXtGUID guid_ColorMappingService = {0xc3e44fbc,0x45c6,0x47b5,0xaa,0xee,0xf0,0xcc,0x00,0x2d,0xd4,0x74};
};

class CLxImpl_ColorMapping {
  public:
    virtual ~CLxImpl_ColorMapping() {}
    virtual LxResult
      cmap_Setup (int toLinear)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_ToLinear (const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_FromLinear (const LXtFVector linearValues, LXtFVector targetValues, unsigned int length)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_ToLinearFast (float* buf, unsigned int length)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_FromLinearFast (float* buf, unsigned int length)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_GetLUTImage (float **ptr)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_GetShaderSource (char **ptr)
        { return LXe_NOTIMPL; }
    virtual const char*
      cmap_GetName (void)
        = 0;
    virtual const char*
      cmap_GetCMServerName (void)
        = 0;
    virtual unsigned char*
      cmap_GenerateICCProfile (unsigned int* length)
        = 0;
};
#define LXxD_ColorMapping_Setup LxResult cmap_Setup (int toLinear)
#define LXxO_ColorMapping_Setup LXxD_ColorMapping_Setup LXx_OVERRIDE
#define LXxC_ColorMapping_Setup(c) LxResult c::cmap_Setup (int toLinear)
#define LXxD_ColorMapping_ToLinear LxResult cmap_ToLinear (const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length)
#define LXxO_ColorMapping_ToLinear LXxD_ColorMapping_ToLinear LXx_OVERRIDE
#define LXxC_ColorMapping_ToLinear(c) LxResult c::cmap_ToLinear (const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length)
#define LXxD_ColorMapping_FromLinear LxResult cmap_FromLinear (const LXtFVector linearValues, LXtFVector targetValues, unsigned int length)
#define LXxO_ColorMapping_FromLinear LXxD_ColorMapping_FromLinear LXx_OVERRIDE
#define LXxC_ColorMapping_FromLinear(c) LxResult c::cmap_FromLinear (const LXtFVector linearValues, LXtFVector targetValues, unsigned int length)
#define LXxD_ColorMapping_ToLinearFast LxResult cmap_ToLinearFast (float* buf, unsigned int length)
#define LXxO_ColorMapping_ToLinearFast LXxD_ColorMapping_ToLinearFast LXx_OVERRIDE
#define LXxC_ColorMapping_ToLinearFast(c) LxResult c::cmap_ToLinearFast (float* buf, unsigned int length)
#define LXxD_ColorMapping_FromLinearFast LxResult cmap_FromLinearFast (float* buf, unsigned int length)
#define LXxO_ColorMapping_FromLinearFast LXxD_ColorMapping_FromLinearFast LXx_OVERRIDE
#define LXxC_ColorMapping_FromLinearFast(c) LxResult c::cmap_FromLinearFast (float* buf, unsigned int length)
#define LXxD_ColorMapping_GetLUTImage LxResult cmap_GetLUTImage (float **ptr)
#define LXxO_ColorMapping_GetLUTImage LXxD_ColorMapping_GetLUTImage LXx_OVERRIDE
#define LXxC_ColorMapping_GetLUTImage(c) LxResult c::cmap_GetLUTImage (float **ptr)
#define LXxD_ColorMapping_GetShaderSource LxResult cmap_GetShaderSource (char **ptr)
#define LXxO_ColorMapping_GetShaderSource LXxD_ColorMapping_GetShaderSource LXx_OVERRIDE
#define LXxC_ColorMapping_GetShaderSource(c) LxResult c::cmap_GetShaderSource (char **ptr)
#define LXxD_ColorMapping_GetName const char* cmap_GetName (void)
#define LXxO_ColorMapping_GetName LXxD_ColorMapping_GetName LXx_OVERRIDE
#define LXxC_ColorMapping_GetName(c) const char* c::cmap_GetName (void)
#define LXxD_ColorMapping_GetCMServerName const char* cmap_GetCMServerName (void)
#define LXxO_ColorMapping_GetCMServerName LXxD_ColorMapping_GetCMServerName LXx_OVERRIDE
#define LXxC_ColorMapping_GetCMServerName(c) const char* c::cmap_GetCMServerName (void)
#define LXxD_ColorMapping_GenerateICCProfile unsigned char* cmap_GenerateICCProfile (unsigned int* length)
#define LXxO_ColorMapping_GenerateICCProfile LXxD_ColorMapping_GenerateICCProfile LXx_OVERRIDE
#define LXxC_ColorMapping_GenerateICCProfile(c) unsigned char* c::cmap_GenerateICCProfile (unsigned int* length)
template <class T>
class CLxIfc_ColorMapping : public CLxInterface
{
    static LxResult
  Setup (LXtObjectID wcom, int toLinear)
  {
    LXCWxINST (CLxImpl_ColorMapping, loc);
    try {
      return loc->cmap_Setup (toLinear);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToLinear (LXtObjectID wcom, const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length)
  {
    LXCWxINST (CLxImpl_ColorMapping, loc);
    try {
      return loc->cmap_ToLinear (sourceValues,linearValues,length);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FromLinear (LXtObjectID wcom, const LXtFVector linearValues, LXtFVector targetValues, unsigned int length)
  {
    LXCWxINST (CLxImpl_ColorMapping, loc);
    try {
      return loc->cmap_FromLinear (linearValues,targetValues,length);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToLinearFast (LXtObjectID wcom, float* buf, unsigned int length)
  {
    LXCWxINST (CLxImpl_ColorMapping, loc);
    try {
      return loc->cmap_ToLinearFast (buf,length);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FromLinearFast (LXtObjectID wcom, float* buf, unsigned int length)
  {
    LXCWxINST (CLxImpl_ColorMapping, loc);
    try {
      return loc->cmap_FromLinearFast (buf,length);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetLUTImage (LXtObjectID wcom, float **ptr)
  {
    LXCWxINST (CLxImpl_ColorMapping, loc);
    try {
      return loc->cmap_GetLUTImage (ptr);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetShaderSource (LXtObjectID wcom, char **ptr)
  {
    LXCWxINST (CLxImpl_ColorMapping, loc);
    try {
      return loc->cmap_GetShaderSource (ptr);
    } catch (LxResult rc) { return rc; }
  }
    static const char*
  GetName (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ColorMapping, loc);
    return loc->cmap_GetName ();
  }
    static const char*
  GetCMServerName (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ColorMapping, loc);
    return loc->cmap_GetCMServerName ();
  }
    static unsigned char*
  GenerateICCProfile (LXtObjectID wcom, unsigned int* length)
  {
    LXCWxINST (CLxImpl_ColorMapping, loc);
    return loc->cmap_GenerateICCProfile (length);
  }
  ILxColorMapping vt;
public:
  CLxIfc_ColorMapping ()
  {
    vt.Setup = Setup;
    vt.ToLinear = ToLinear;
    vt.FromLinear = FromLinear;
    vt.ToLinearFast = ToLinearFast;
    vt.FromLinearFast = FromLinearFast;
    vt.GetLUTImage = GetLUTImage;
    vt.GetShaderSource = GetShaderSource;
    vt.GetName = GetName;
    vt.GetCMServerName = GetCMServerName;
    vt.GenerateICCProfile = GenerateICCProfile;
    vTable = &vt.iunk;
    iid = &lx::guid_ColorMapping;
  }
};
class CLxLoc_ColorMapping : public CLxLocalize<ILxColorMappingID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ColorMapping() {_init();}
  CLxLoc_ColorMapping(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ColorMapping(const CLxLoc_ColorMapping &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ColorMapping;}
    LxResult
  Setup (int toLinear)
  {
    return m_loc[0]->Setup (m_loc,toLinear);
  }
    LxResult
  ToLinear (const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length)
  {
    return m_loc[0]->ToLinear (m_loc,sourceValues,linearValues,length);
  }
    LxResult
  FromLinear (const LXtFVector linearValues, LXtFVector targetValues, unsigned int length)
  {
    return m_loc[0]->FromLinear (m_loc,linearValues,targetValues,length);
  }
    LxResult
  ToLinearFast (float* buf, unsigned int length)
  {
    return m_loc[0]->ToLinearFast (m_loc,buf,length);
  }
    LxResult
  FromLinearFast (float* buf, unsigned int length)
  {
    return m_loc[0]->FromLinearFast (m_loc,buf,length);
  }
    LxResult
  GetLUTImage (float **ptr)
  {
    return m_loc[0]->GetLUTImage (m_loc,ptr);
  }
    LxResult
  GetShaderSource (char **ptr)
  {
    return m_loc[0]->GetShaderSource (m_loc,ptr);
  }
    const char*
  GetName (void)
  {
    return m_loc[0]->GetName (m_loc);
  }
    const char*
  GetCMServerName (void)
  {
    return m_loc[0]->GetCMServerName (m_loc);
  }
    unsigned char*
  GenerateICCProfile (unsigned int* length)
  {
    return m_loc[0]->GenerateICCProfile (m_loc,length);
  }
};

class CLxImpl_ColorMapping1 {
  public:
    virtual ~CLxImpl_ColorMapping1() {}
    virtual LxResult
      cmap_Setup (int toLinear)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_ToLinear (const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_FromLinear (const LXtFVector linearValues, LXtFVector targetValues, unsigned int length)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_ToLinearFast (float* buf, unsigned int length)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_FromLinearFast (float* buf, unsigned int length)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_GetLUTImage (float **ptr)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmap_GetShaderSource (char **ptr)
        { return LXe_NOTIMPL; }
    virtual const char*
      cmap_GetName (void)
        = 0;
};
#define LXxD_ColorMapping1_Setup LxResult cmap_Setup (int toLinear)
#define LXxO_ColorMapping1_Setup LXxD_ColorMapping1_Setup LXx_OVERRIDE
#define LXxC_ColorMapping1_Setup(c) LxResult c::cmap_Setup (int toLinear)
#define LXxD_ColorMapping1_ToLinear LxResult cmap_ToLinear (const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length)
#define LXxO_ColorMapping1_ToLinear LXxD_ColorMapping1_ToLinear LXx_OVERRIDE
#define LXxC_ColorMapping1_ToLinear(c) LxResult c::cmap_ToLinear (const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length)
#define LXxD_ColorMapping1_FromLinear LxResult cmap_FromLinear (const LXtFVector linearValues, LXtFVector targetValues, unsigned int length)
#define LXxO_ColorMapping1_FromLinear LXxD_ColorMapping1_FromLinear LXx_OVERRIDE
#define LXxC_ColorMapping1_FromLinear(c) LxResult c::cmap_FromLinear (const LXtFVector linearValues, LXtFVector targetValues, unsigned int length)
#define LXxD_ColorMapping1_ToLinearFast LxResult cmap_ToLinearFast (float* buf, unsigned int length)
#define LXxO_ColorMapping1_ToLinearFast LXxD_ColorMapping1_ToLinearFast LXx_OVERRIDE
#define LXxC_ColorMapping1_ToLinearFast(c) LxResult c::cmap_ToLinearFast (float* buf, unsigned int length)
#define LXxD_ColorMapping1_FromLinearFast LxResult cmap_FromLinearFast (float* buf, unsigned int length)
#define LXxO_ColorMapping1_FromLinearFast LXxD_ColorMapping1_FromLinearFast LXx_OVERRIDE
#define LXxC_ColorMapping1_FromLinearFast(c) LxResult c::cmap_FromLinearFast (float* buf, unsigned int length)
#define LXxD_ColorMapping1_GetLUTImage LxResult cmap_GetLUTImage (float **ptr)
#define LXxO_ColorMapping1_GetLUTImage LXxD_ColorMapping1_GetLUTImage LXx_OVERRIDE
#define LXxC_ColorMapping1_GetLUTImage(c) LxResult c::cmap_GetLUTImage (float **ptr)
#define LXxD_ColorMapping1_GetShaderSource LxResult cmap_GetShaderSource (char **ptr)
#define LXxO_ColorMapping1_GetShaderSource LXxD_ColorMapping1_GetShaderSource LXx_OVERRIDE
#define LXxC_ColorMapping1_GetShaderSource(c) LxResult c::cmap_GetShaderSource (char **ptr)
#define LXxD_ColorMapping1_GetName const char* cmap_GetName (void)
#define LXxO_ColorMapping1_GetName LXxD_ColorMapping1_GetName LXx_OVERRIDE
#define LXxC_ColorMapping1_GetName(c) const char* c::cmap_GetName (void)
template <class T>
class CLxIfc_ColorMapping1 : public CLxInterface
{
    static LxResult
  Setup (LXtObjectID wcom, int toLinear)
  {
    LXCWxINST (CLxImpl_ColorMapping1, loc);
    try {
      return loc->cmap_Setup (toLinear);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToLinear (LXtObjectID wcom, const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length)
  {
    LXCWxINST (CLxImpl_ColorMapping1, loc);
    try {
      return loc->cmap_ToLinear (sourceValues,linearValues,length);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FromLinear (LXtObjectID wcom, const LXtFVector linearValues, LXtFVector targetValues, unsigned int length)
  {
    LXCWxINST (CLxImpl_ColorMapping1, loc);
    try {
      return loc->cmap_FromLinear (linearValues,targetValues,length);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToLinearFast (LXtObjectID wcom, float* buf, unsigned int length)
  {
    LXCWxINST (CLxImpl_ColorMapping1, loc);
    try {
      return loc->cmap_ToLinearFast (buf,length);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FromLinearFast (LXtObjectID wcom, float* buf, unsigned int length)
  {
    LXCWxINST (CLxImpl_ColorMapping1, loc);
    try {
      return loc->cmap_FromLinearFast (buf,length);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetLUTImage (LXtObjectID wcom, float **ptr)
  {
    LXCWxINST (CLxImpl_ColorMapping1, loc);
    try {
      return loc->cmap_GetLUTImage (ptr);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetShaderSource (LXtObjectID wcom, char **ptr)
  {
    LXCWxINST (CLxImpl_ColorMapping1, loc);
    try {
      return loc->cmap_GetShaderSource (ptr);
    } catch (LxResult rc) { return rc; }
  }
    static const char*
  GetName (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ColorMapping1, loc);
    return loc->cmap_GetName ();
  }
  ILxColorMapping1 vt;
public:
  CLxIfc_ColorMapping1 ()
  {
    vt.Setup = Setup;
    vt.ToLinear = ToLinear;
    vt.FromLinear = FromLinear;
    vt.ToLinearFast = ToLinearFast;
    vt.FromLinearFast = FromLinearFast;
    vt.GetLUTImage = GetLUTImage;
    vt.GetShaderSource = GetShaderSource;
    vt.GetName = GetName;
    vTable = &vt.iunk;
    iid = &lx::guid_ColorMapping1;
  }
};
class CLxLoc_ColorMapping1 : public CLxLocalize<ILxColorMapping1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ColorMapping1() {_init();}
  CLxLoc_ColorMapping1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ColorMapping1(const CLxLoc_ColorMapping1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ColorMapping1;}
    LxResult
  Setup (int toLinear)
  {
    return m_loc[0]->Setup (m_loc,toLinear);
  }
    LxResult
  ToLinear (const LXtFVector sourceValues, LXtFVector linearValues, unsigned int length)
  {
    return m_loc[0]->ToLinear (m_loc,sourceValues,linearValues,length);
  }
    LxResult
  FromLinear (const LXtFVector linearValues, LXtFVector targetValues, unsigned int length)
  {
    return m_loc[0]->FromLinear (m_loc,linearValues,targetValues,length);
  }
    LxResult
  ToLinearFast (float* buf, unsigned int length)
  {
    return m_loc[0]->ToLinearFast (m_loc,buf,length);
  }
    LxResult
  FromLinearFast (float* buf, unsigned int length)
  {
    return m_loc[0]->FromLinearFast (m_loc,buf,length);
  }
    LxResult
  GetLUTImage (float **ptr)
  {
    return m_loc[0]->GetLUTImage (m_loc,ptr);
  }
    LxResult
  GetShaderSource (char **ptr)
  {
    return m_loc[0]->GetShaderSource (m_loc,ptr);
  }
    const char*
  GetName (void)
  {
    return m_loc[0]->GetName (m_loc);
  }
};

class CLxImpl_ColorMappingModule {
  public:
    virtual ~CLxImpl_ColorMappingModule() {}
    virtual unsigned
      cmapmod_Flags (void)
        = 0;
};
#define LXxD_ColorMappingModule_Flags unsigned cmapmod_Flags (void)
#define LXxO_ColorMappingModule_Flags LXxD_ColorMappingModule_Flags LXx_OVERRIDE
#define LXxC_ColorMappingModule_Flags(c) unsigned c::cmapmod_Flags (void)
template <class T>
class CLxIfc_ColorMappingModule : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ColorMappingModule, loc);
    return loc->cmapmod_Flags ();
  }
  ILxColorMappingModule vt;
public:
  CLxIfc_ColorMappingModule ()
  {
    vt.Flags = Flags;
    vTable = &vt.iunk;
    iid = &lx::guid_ColorMappingModule;
  }
};
class CLxLoc_ColorMappingModule : public CLxLocalize<ILxColorMappingModuleID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ColorMappingModule() {_init();}
  CLxLoc_ColorMappingModule(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ColorMappingModule(const CLxLoc_ColorMappingModule &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ColorMappingModule;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
};

class CLxLoc_ColorMappingService : public CLxLocalizedService
{
public:
  ILxColorMappingServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_ColorMappingService() {_init();set();}
 ~CLxLoc_ColorMappingService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxColorMappingServiceID>(lx::GetGlobal(&lx::guid_ColorMappingService));}
    LxResult
  MakeColorMapping (const char *colorspaceName, int toLinear, void **ppvObj)
  {
    return m_loc[0]->MakeColorMapping (m_loc,colorspaceName,toLinear,ppvObj);
  }
    CLxResult
  MakeColorMapping (const char *colorspaceName, int toLinear, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->MakeColorMapping(m_loc,colorspaceName,toLinear,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    int
  ConfigCount (void)
  {
    return m_loc[0]->ConfigCount (m_loc);
  }
    LxResult
  ConfigName (int index, const char **configName)
  {
    return m_loc[0]->ConfigName (m_loc,index,configName);
  }
    LxResult
  ConfigFullPath (int index, const char **configPath)
  {
    return m_loc[0]->ConfigFullPath (m_loc,index,configPath);
  }
    LxResult
  RegisterColorspaceForConfig (const char *configName, const char *colorspaceName)
  {
    return m_loc[0]->RegisterColorspaceForConfig (m_loc,configName,colorspaceName);
  }
    LxResult
  GetDisplayColorMapping (void **ppvObj)
  {
    return m_loc[0]->GetDisplayColorMapping (m_loc,ppvObj);
  }
    CLxResult
  GetDisplayColorMapping (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetDisplayColorMapping(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetNumericColorMapping (void **ppvObj)
  {
    return m_loc[0]->GetNumericColorMapping (m_loc,ppvObj);
  }
    CLxResult
  GetNumericColorMapping (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetNumericColorMapping(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

