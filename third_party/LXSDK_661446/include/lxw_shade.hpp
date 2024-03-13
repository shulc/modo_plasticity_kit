/*
 * C++ wrapper for lxshade.h
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
#ifndef LXW_SHADE_HPP
#define LXW_SHADE_HPP

#include <lxshade.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_CompShader1 = {0x06717e9d,0x610d,0x439f,0x93,0x5b,0xaf,0x08,0x05,0x82,0x7e,0xde};
    static const LXtGUID guid_ValueTexture = {0x9A2DD931,0xF442,0x488a,0x8C,0x6A,0xAF,0x6B,0xDD,0xC3,0x0B,0x32};
    static const LXtGUID guid_TextureLayer = {0x42369FE7,0x869E,0x4c61,0x8D,0x40,0xAC,0x62,0xE5,0x29,0xDD,0x15};
    static const LXtGUID guid_TextureGL = {0x55CE355E,0xC838,0x4222,0xAB,0xED,0xCB,0xDD,0x80,0x82,0x09,0xAF};
    static const LXtGUID guid_TextureVMap = {0x0C68AC79,0x993C,0x4823,0x97,0xFA,0xEA,0xD5,0xEF,0xF9,0x7B,0x64};
    static const LXtGUID guid_CustomMaterial3 = {0xB6297ECF,0xCFE9,0x4923,0xA7,0x0C,0xDB,0x87,0x27,0x9B,0x04,0x11};
    static const LXtGUID guid_ValueTexture1 = {0xCA0E3524,0x6F82,0x44B8,0xAA,0xC9,0xDC,0x25,0x8F,0x54,0x8C,0x02};
    static const LXtGUID guid_CustomMaterial2 = {0x64e2dd96,0xff7f,0x4c9b,0x96,0x7e,0x24,0xde,0xc8,0x3b,0xfb,0x72};
    static const LXtGUID guid_TextureEval1 = {0x847C1567,0x1725,0x4e98,0xBA,0x09,0xEA,0x1F,0x90,0x49,0xD7,0x6A};
    static const LXtGUID guid_TextureMask = {0x701E81D3,0xFFA6,0x475a,0xA0,0x2D,0xEC,0xE9,0xAB,0x15,0xB4,0xCD};
    static const LXtGUID guid_TextureEval = {0x5791A0B4,0x4B5C,0x44EC,0x8D,0x1D,0xD8,0xCA,0x53,0x83,0x0F,0xC9};
    static const LXtGUID guid_Texture = {0x6376D941,0x9437,0x4cf8,0xB6,0xEC,0xAB,0x50,0x79,0x1F,0xE6,0x0F};
    static const LXtGUID guid_CustomMaterial1 = {0xd0c4106c,0xdfd5,0x4a58,0xad,0x48,0x45,0xb5,0x0a,0xe6,0x3f,0x59};
    static const LXtGUID guid_ValueTextureCustom = {0xDE3298A6,0x1607,0x4338,0xB0,0x61,0x18,0x55,0x28,0xE6,0xFB,0x51};
    static const LXtGUID guid_CustomMaterial = {0x3AEBDFE5,0xAB69,0x4B58,0x8B,0x8F,0xE1,0x09,0x1D,0x5F,0x6D,0xD5};
    static const LXtGUID guid_CompShader = {0x371e8b57,0x3a1e,0x444b,0x91,0xf8,0x5e,0x43,0xc7,0x5b,0xf1,0xcb};
};

class CLxImpl_CompShader1 {
  public:
    virtual ~CLxImpl_CompShader1() {}
    virtual LxResult
      csh_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_ReadChannels (ILxUnknownID attr, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_Customize (ILxUnknownID custom, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual void
      csh_Evaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
        { }
    virtual LxResult
      csh_SetShadeFlags (LXpShadeFlags *sFlg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_SetOpaque (int *opaque)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_CustomPacket (const char **packet)
        { return LXe_NOTIMPL; }
    virtual void
      csh_Cleanup (void *data)
        { }
};
#define LXxD_CompShader1_SetupChannels LxResult csh_SetupChannels (ILxUnknownID addChan)
#define LXxO_CompShader1_SetupChannels LXxD_CompShader1_SetupChannels LXx_OVERRIDE
#define LXxC_CompShader1_SetupChannels(c) LxResult c::csh_SetupChannels (ILxUnknownID addChan)
#define LXxD_CompShader1_LinkChannels LxResult csh_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxO_CompShader1_LinkChannels LXxD_CompShader1_LinkChannels LXx_OVERRIDE
#define LXxC_CompShader1_LinkChannels(c) LxResult c::csh_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxD_CompShader1_ReadChannels LxResult csh_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxO_CompShader1_ReadChannels LXxD_CompShader1_ReadChannels LXx_OVERRIDE
#define LXxC_CompShader1_ReadChannels(c) LxResult c::csh_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxD_CompShader1_Customize LxResult csh_Customize (ILxUnknownID custom, void **ppvData)
#define LXxO_CompShader1_Customize LXxD_CompShader1_Customize LXx_OVERRIDE
#define LXxC_CompShader1_Customize(c) LxResult c::csh_Customize (ILxUnknownID custom, void **ppvData)
#define LXxD_CompShader1_Evaluate void csh_Evaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
#define LXxO_CompShader1_Evaluate LXxD_CompShader1_Evaluate LXx_OVERRIDE
#define LXxC_CompShader1_Evaluate(c) void c::csh_Evaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
#define LXxD_CompShader1_SetShadeFlags LxResult csh_SetShadeFlags (LXpShadeFlags *sFlg)
#define LXxO_CompShader1_SetShadeFlags LXxD_CompShader1_SetShadeFlags LXx_OVERRIDE
#define LXxC_CompShader1_SetShadeFlags(c) LxResult c::csh_SetShadeFlags (LXpShadeFlags *sFlg)
#define LXxD_CompShader1_SetOpaque LxResult csh_SetOpaque (int *opaque)
#define LXxO_CompShader1_SetOpaque LXxD_CompShader1_SetOpaque LXx_OVERRIDE
#define LXxC_CompShader1_SetOpaque(c) LxResult c::csh_SetOpaque (int *opaque)
#define LXxD_CompShader1_CustomPacket LxResult csh_CustomPacket (const char **packet)
#define LXxO_CompShader1_CustomPacket LXxD_CompShader1_CustomPacket LXx_OVERRIDE
#define LXxC_CompShader1_CustomPacket(c) LxResult c::csh_CustomPacket (const char **packet)
#define LXxD_CompShader1_Cleanup void csh_Cleanup (void *data)
#define LXxO_CompShader1_Cleanup LXxD_CompShader1_Cleanup LXx_OVERRIDE
#define LXxC_CompShader1_Cleanup(c) void c::csh_Cleanup (void *data)
template <class T>
class CLxIfc_CompShader1 : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_CompShader1, loc);
    try {
      return loc->csh_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkChannels (LXtObjectID wcom, LXtObjectID eval, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_CompShader1, loc);
    try {
      return loc->csh_LinkChannels ((ILxUnknownID)eval,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReadChannels (LXtObjectID wcom, LXtObjectID attr, void **ppvData)
  {
    LXCWxINST (CLxImpl_CompShader1, loc);
    try {
      return loc->csh_ReadChannels ((ILxUnknownID)attr,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Customize (LXtObjectID wcom, LXtObjectID custom, void **ppvData)
  {
    LXCWxINST (CLxImpl_CompShader1, loc);
    try {
      return loc->csh_Customize ((ILxUnknownID)custom,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Evaluate (LXtObjectID wcom, LXtObjectID vector, LXtObjectID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
  {
    LXCWxINST (CLxImpl_CompShader1, loc);
    loc->csh_Evaluate ((ILxUnknownID)vector,(ILxUnknownID)rayObj,sCmp,sOut,data);
  }
    static LxResult
  SetShadeFlags (LXtObjectID wcom, LXpShadeFlags *sFlg)
  {
    LXCWxINST (CLxImpl_CompShader1, loc);
    try {
      return loc->csh_SetShadeFlags (sFlg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetOpaque (LXtObjectID wcom, int *opaque)
  {
    LXCWxINST (CLxImpl_CompShader1, loc);
    try {
      return loc->csh_SetOpaque (opaque);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CustomPacket (LXtObjectID wcom, const char **packet)
  {
    LXCWxINST (CLxImpl_CompShader1, loc);
    try {
      return loc->csh_CustomPacket (packet);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_CompShader1, loc);
    loc->csh_Cleanup (data);
  }
  ILxCompShader1 vt;
public:
  CLxIfc_CompShader1 ()
  {
    vt.SetupChannels = SetupChannels;
    vt.LinkChannels = LinkChannels;
    vt.ReadChannels = ReadChannels;
    vt.Customize = Customize;
    vt.Evaluate = Evaluate;
    vt.SetShadeFlags = SetShadeFlags;
    vt.SetOpaque = SetOpaque;
    vt.CustomPacket = CustomPacket;
    vt.Cleanup = Cleanup;
    vTable = &vt.iunk;
    iid = &lx::guid_CompShader1;
  }
};

class CLxImpl_ValueTexture {
  public:
    virtual ~CLxImpl_ValueTexture() {}
    virtual LxResult
      vtx_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtx_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtx_LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
        { return LXe_OK; }
    virtual LxResult
      vtx_ReadChannels (ILxUnknownID attr, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtx_Customize (ILxUnknownID custom, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtx_Setup (void *data)
        { return LXe_OK; }
    virtual void
      vtx_Evaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, LXpTextureOutput *tOut, void *data)
        { }
    virtual void
      vtx_Cleanup (void *data)
        { }
    virtual int
      vtx_IsSampleDriven (int *idx)
        { return LXe_FALSE; }
};
#define LXxD_ValueTexture_SetupChannels LxResult vtx_SetupChannels (ILxUnknownID addChan)
#define LXxO_ValueTexture_SetupChannels LXxD_ValueTexture_SetupChannels LXx_OVERRIDE
#define LXxC_ValueTexture_SetupChannels(c) LxResult c::vtx_SetupChannels (ILxUnknownID addChan)
#define LXxD_ValueTexture_LinkChannels LxResult vtx_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxO_ValueTexture_LinkChannels LXxD_ValueTexture_LinkChannels LXx_OVERRIDE
#define LXxC_ValueTexture_LinkChannels(c) LxResult c::vtx_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxD_ValueTexture_LinkSampleChannels LxResult vtx_LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
#define LXxO_ValueTexture_LinkSampleChannels LXxD_ValueTexture_LinkSampleChannels LXx_OVERRIDE
#define LXxC_ValueTexture_LinkSampleChannels(c) LxResult c::vtx_LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
#define LXxD_ValueTexture_ReadChannels LxResult vtx_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxO_ValueTexture_ReadChannels LXxD_ValueTexture_ReadChannels LXx_OVERRIDE
#define LXxC_ValueTexture_ReadChannels(c) LxResult c::vtx_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxD_ValueTexture_Customize LxResult vtx_Customize (ILxUnknownID custom, void **ppvData)
#define LXxO_ValueTexture_Customize LXxD_ValueTexture_Customize LXx_OVERRIDE
#define LXxC_ValueTexture_Customize(c) LxResult c::vtx_Customize (ILxUnknownID custom, void **ppvData)
#define LXxD_ValueTexture_Setup LxResult vtx_Setup (void *data)
#define LXxO_ValueTexture_Setup LXxD_ValueTexture_Setup LXx_OVERRIDE
#define LXxC_ValueTexture_Setup(c) LxResult c::vtx_Setup (void *data)
#define LXxD_ValueTexture_Evaluate void vtx_Evaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, LXpTextureOutput *tOut, void *data)
#define LXxO_ValueTexture_Evaluate LXxD_ValueTexture_Evaluate LXx_OVERRIDE
#define LXxC_ValueTexture_Evaluate(c) void c::vtx_Evaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, LXpTextureOutput *tOut, void *data)
#define LXxD_ValueTexture_Cleanup void vtx_Cleanup (void *data)
#define LXxO_ValueTexture_Cleanup LXxD_ValueTexture_Cleanup LXx_OVERRIDE
#define LXxC_ValueTexture_Cleanup(c) void c::vtx_Cleanup (void *data)
#define LXxD_ValueTexture_IsSampleDriven int vtx_IsSampleDriven (int *idx)
#define LXxO_ValueTexture_IsSampleDriven LXxD_ValueTexture_IsSampleDriven LXx_OVERRIDE
#define LXxC_ValueTexture_IsSampleDriven(c) int c::vtx_IsSampleDriven (int *idx)
template <class T>
class CLxIfc_ValueTexture : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    try {
      return loc->vtx_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkChannels (LXtObjectID wcom, LXtObjectID eval, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    try {
      return loc->vtx_LinkChannels ((ILxUnknownID)eval,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkSampleChannels (LXtObjectID wcom, LXtObjectID nodalEtor, LXtObjectID item, int *idx)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    try {
      return loc->vtx_LinkSampleChannels ((ILxUnknownID)nodalEtor,(ILxUnknownID)item,idx);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReadChannels (LXtObjectID wcom, LXtObjectID attr, void **ppvData)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    try {
      return loc->vtx_ReadChannels ((ILxUnknownID)attr,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Customize (LXtObjectID wcom, LXtObjectID custom, void **ppvData)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    try {
      return loc->vtx_Customize ((ILxUnknownID)custom,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Setup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    try {
      return loc->vtx_Setup (data);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Evaluate (LXtObjectID wcom, LXtObjectID etor, int *idx, LXtObjectID vector, LXpTextureOutput *tOut, void *data)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    loc->vtx_Evaluate ((ILxUnknownID)etor,idx,(ILxUnknownID)vector,tOut,data);
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    loc->vtx_Cleanup (data);
  }
    static int
  IsSampleDriven (LXtObjectID wcom, int *idx)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    return loc->vtx_IsSampleDriven (idx);
  }
  ILxValueTexture vt;
public:
  CLxIfc_ValueTexture ()
  {
    vt.SetupChannels = SetupChannels;
    vt.LinkChannels = LinkChannels;
    vt.LinkSampleChannels = LinkSampleChannels;
    vt.ReadChannels = ReadChannels;
    vt.Customize = Customize;
    vt.Setup = Setup;
    vt.Evaluate = Evaluate;
    vt.Cleanup = Cleanup;
    vt.IsSampleDriven = IsSampleDriven;
    vTable = &vt.iunk;
    iid = &lx::guid_ValueTexture;
  }
};
class CLxLoc_ValueTexture : public CLxLocalize<ILxValueTextureID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueTexture() {_init();}
  CLxLoc_ValueTexture(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ValueTexture(const CLxLoc_ValueTexture &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ValueTexture;}
    LxResult
  SetupChannels (ILxUnknownID addChan)
  {
    return m_loc[0]->SetupChannels (m_loc,(ILxUnknownID)addChan);
  }
    LxResult
  LinkChannels (ILxUnknownID eval, ILxUnknownID item)
  {
    return m_loc[0]->LinkChannels (m_loc,(ILxUnknownID)eval,(ILxUnknownID)item);
  }
    LxResult
  LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
  {
    return m_loc[0]->LinkSampleChannels (m_loc,(ILxUnknownID)nodalEtor,(ILxUnknownID)item,idx);
  }
    LxResult
  ReadChannels (ILxUnknownID attr, void **ppvData)
  {
    return m_loc[0]->ReadChannels (m_loc,(ILxUnknownID)attr,ppvData);
  }
    LxResult
  Customize (ILxUnknownID custom, void **ppvData)
  {
    return m_loc[0]->Customize (m_loc,(ILxUnknownID)custom,ppvData);
  }
    LxResult
  Setup (void *data)
  {
    return m_loc[0]->Setup (m_loc,data);
  }
    void
  Evaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, LXpTextureOutput *tOut, void *data)
  {
    m_loc[0]->Evaluate (m_loc,(ILxUnknownID)etor,idx,(ILxUnknownID)vector,tOut,data);
  }
    void
  Cleanup (void *data)
  {
    m_loc[0]->Cleanup (m_loc,data);
  }
    int
  IsSampleDriven (int *idx)
  {
    return m_loc[0]->IsSampleDriven (m_loc,idx);
  }
};




class CLxImpl_CustomMaterial3 {
  public:
    virtual ~CLxImpl_CustomMaterial3() {}
    virtual LxResult
      cmt_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
        { return LXe_OK; }
    virtual int
      cmt_IsSampleDriven (int *idx)
        { return LXe_FALSE; }
    virtual LxResult
      cmt_ReadChannels (ILxUnknownID attr, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_Customize (ILxUnknownID custom, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual void
      cmt_MaterialEvaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, void *data)
        { }
    virtual void
      cmt_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
        { }
    virtual LxResult
      cmt_SetShadeFlags (LXpShadeFlags *sFlg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetBump (float *bumpAmplitude, int *clearBump)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetDisplacement (float *dispDist)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetOpaque (int *opaque)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetSmoothing (double *smooth, double *angle)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_CustomPacket (const char **packet)
        { return LXe_NOTIMPL; }
    virtual void
      cmt_Cleanup (void *data)
        { }
    virtual LxResult
      cmt_UpdatePreview (int chanIdx, int *flags)
        { return LXe_NOTIMPL; }
    virtual int
      cmt_Flags (void)
        = 0;
};
#define LXxD_CustomMaterial3_SetupChannels LxResult cmt_SetupChannels (ILxUnknownID addChan)
#define LXxO_CustomMaterial3_SetupChannels LXxD_CustomMaterial3_SetupChannels LXx_OVERRIDE
#define LXxC_CustomMaterial3_SetupChannels(c) LxResult c::cmt_SetupChannels (ILxUnknownID addChan)
#define LXxD_CustomMaterial3_LinkChannels LxResult cmt_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxO_CustomMaterial3_LinkChannels LXxD_CustomMaterial3_LinkChannels LXx_OVERRIDE
#define LXxC_CustomMaterial3_LinkChannels(c) LxResult c::cmt_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxD_CustomMaterial3_LinkSampleChannels LxResult cmt_LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
#define LXxO_CustomMaterial3_LinkSampleChannels LXxD_CustomMaterial3_LinkSampleChannels LXx_OVERRIDE
#define LXxC_CustomMaterial3_LinkSampleChannels(c) LxResult c::cmt_LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
#define LXxD_CustomMaterial3_IsSampleDriven int cmt_IsSampleDriven (int *idx)
#define LXxO_CustomMaterial3_IsSampleDriven LXxD_CustomMaterial3_IsSampleDriven LXx_OVERRIDE
#define LXxC_CustomMaterial3_IsSampleDriven(c) int c::cmt_IsSampleDriven (int *idx)
#define LXxD_CustomMaterial3_ReadChannels LxResult cmt_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxO_CustomMaterial3_ReadChannels LXxD_CustomMaterial3_ReadChannels LXx_OVERRIDE
#define LXxC_CustomMaterial3_ReadChannels(c) LxResult c::cmt_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxD_CustomMaterial3_Customize LxResult cmt_Customize (ILxUnknownID custom, void **ppvData)
#define LXxO_CustomMaterial3_Customize LXxD_CustomMaterial3_Customize LXx_OVERRIDE
#define LXxC_CustomMaterial3_Customize(c) LxResult c::cmt_Customize (ILxUnknownID custom, void **ppvData)
#define LXxD_CustomMaterial3_MaterialEvaluate void cmt_MaterialEvaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, void *data)
#define LXxO_CustomMaterial3_MaterialEvaluate LXxD_CustomMaterial3_MaterialEvaluate LXx_OVERRIDE
#define LXxC_CustomMaterial3_MaterialEvaluate(c) void c::cmt_MaterialEvaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, void *data)
#define LXxD_CustomMaterial3_ShaderEvaluate void cmt_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
#define LXxO_CustomMaterial3_ShaderEvaluate LXxD_CustomMaterial3_ShaderEvaluate LXx_OVERRIDE
#define LXxC_CustomMaterial3_ShaderEvaluate(c) void c::cmt_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
#define LXxD_CustomMaterial3_SetShadeFlags LxResult cmt_SetShadeFlags (LXpShadeFlags *sFlg)
#define LXxO_CustomMaterial3_SetShadeFlags LXxD_CustomMaterial3_SetShadeFlags LXx_OVERRIDE
#define LXxC_CustomMaterial3_SetShadeFlags(c) LxResult c::cmt_SetShadeFlags (LXpShadeFlags *sFlg)
#define LXxD_CustomMaterial3_SetBump LxResult cmt_SetBump (float *bumpAmplitude, int *clearBump)
#define LXxO_CustomMaterial3_SetBump LXxD_CustomMaterial3_SetBump LXx_OVERRIDE
#define LXxC_CustomMaterial3_SetBump(c) LxResult c::cmt_SetBump (float *bumpAmplitude, int *clearBump)
#define LXxD_CustomMaterial3_SetDisplacement LxResult cmt_SetDisplacement (float *dispDist)
#define LXxO_CustomMaterial3_SetDisplacement LXxD_CustomMaterial3_SetDisplacement LXx_OVERRIDE
#define LXxC_CustomMaterial3_SetDisplacement(c) LxResult c::cmt_SetDisplacement (float *dispDist)
#define LXxD_CustomMaterial3_SetOpaque LxResult cmt_SetOpaque (int *opaque)
#define LXxO_CustomMaterial3_SetOpaque LXxD_CustomMaterial3_SetOpaque LXx_OVERRIDE
#define LXxC_CustomMaterial3_SetOpaque(c) LxResult c::cmt_SetOpaque (int *opaque)
#define LXxD_CustomMaterial3_SetSmoothing LxResult cmt_SetSmoothing (double *smooth, double *angle)
#define LXxO_CustomMaterial3_SetSmoothing LXxD_CustomMaterial3_SetSmoothing LXx_OVERRIDE
#define LXxC_CustomMaterial3_SetSmoothing(c) LxResult c::cmt_SetSmoothing (double *smooth, double *angle)
#define LXxD_CustomMaterial3_CustomPacket LxResult cmt_CustomPacket (const char **packet)
#define LXxO_CustomMaterial3_CustomPacket LXxD_CustomMaterial3_CustomPacket LXx_OVERRIDE
#define LXxC_CustomMaterial3_CustomPacket(c) LxResult c::cmt_CustomPacket (const char **packet)
#define LXxD_CustomMaterial3_Cleanup void cmt_Cleanup (void *data)
#define LXxO_CustomMaterial3_Cleanup LXxD_CustomMaterial3_Cleanup LXx_OVERRIDE
#define LXxC_CustomMaterial3_Cleanup(c) void c::cmt_Cleanup (void *data)
#define LXxD_CustomMaterial3_UpdatePreview LxResult cmt_UpdatePreview (int chanIdx, int *flags)
#define LXxO_CustomMaterial3_UpdatePreview LXxD_CustomMaterial3_UpdatePreview LXx_OVERRIDE
#define LXxC_CustomMaterial3_UpdatePreview(c) LxResult c::cmt_UpdatePreview (int chanIdx, int *flags)
#define LXxD_CustomMaterial3_Flags int cmt_Flags (void)
#define LXxO_CustomMaterial3_Flags LXxD_CustomMaterial3_Flags LXx_OVERRIDE
#define LXxC_CustomMaterial3_Flags(c) int c::cmt_Flags (void)
template <class T>
class CLxIfc_CustomMaterial3 : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkChannels (LXtObjectID wcom, LXtObjectID eval, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_LinkChannels ((ILxUnknownID)eval,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkSampleChannels (LXtObjectID wcom, LXtObjectID nodalEtor, LXtObjectID item, int *idx)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_LinkSampleChannels ((ILxUnknownID)nodalEtor,(ILxUnknownID)item,idx);
    } catch (LxResult rc) { return rc; }
  }
    static int
  IsSampleDriven (LXtObjectID wcom, int *idx)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    return loc->cmt_IsSampleDriven (idx);
  }
    static LxResult
  ReadChannels (LXtObjectID wcom, LXtObjectID attr, void **ppvData)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_ReadChannels ((ILxUnknownID)attr,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Customize (LXtObjectID wcom, LXtObjectID custom, void **ppvData)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_Customize ((ILxUnknownID)custom,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static void
  MaterialEvaluate (LXtObjectID wcom, LXtObjectID etor, int *idx, LXtObjectID vector, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    loc->cmt_MaterialEvaluate ((ILxUnknownID)etor,idx,(ILxUnknownID)vector,data);
  }
    static void
  ShaderEvaluate (LXtObjectID wcom, LXtObjectID vector, LXtObjectID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    loc->cmt_ShaderEvaluate ((ILxUnknownID)vector,(ILxUnknownID)rayObj,sCmp,sOut,data);
  }
    static LxResult
  SetShadeFlags (LXtObjectID wcom, LXpShadeFlags *sFlg)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_SetShadeFlags (sFlg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetBump (LXtObjectID wcom, float *bumpAmplitude, int *clearBump)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_SetBump (bumpAmplitude,clearBump);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetDisplacement (LXtObjectID wcom, float *dispDist)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_SetDisplacement (dispDist);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetOpaque (LXtObjectID wcom, int *opaque)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_SetOpaque (opaque);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetSmoothing (LXtObjectID wcom, double *smooth, double *angle)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_SetSmoothing (smooth,angle);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CustomPacket (LXtObjectID wcom, const char **packet)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_CustomPacket (packet);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    loc->cmt_Cleanup (data);
  }
    static LxResult
  UpdatePreview (LXtObjectID wcom, int chanIdx, int *flags)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    try {
      return loc->cmt_UpdatePreview (chanIdx,flags);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CustomMaterial3, loc);
    return loc->cmt_Flags ();
  }
  ILxCustomMaterial3 vt;
public:
  CLxIfc_CustomMaterial3 ()
  {
    vt.SetupChannels = SetupChannels;
    vt.LinkChannels = LinkChannels;
    vt.LinkSampleChannels = LinkSampleChannels;
    vt.IsSampleDriven = IsSampleDriven;
    vt.ReadChannels = ReadChannels;
    vt.Customize = Customize;
    vt.MaterialEvaluate = MaterialEvaluate;
    vt.ShaderEvaluate = ShaderEvaluate;
    vt.SetShadeFlags = SetShadeFlags;
    vt.SetBump = SetBump;
    vt.SetDisplacement = SetDisplacement;
    vt.SetOpaque = SetOpaque;
    vt.SetSmoothing = SetSmoothing;
    vt.CustomPacket = CustomPacket;
    vt.Cleanup = Cleanup;
    vt.UpdatePreview = UpdatePreview;
    vt.Flags = Flags;
    vTable = &vt.iunk;
    iid = &lx::guid_CustomMaterial3;
  }
};

class CLxImpl_ValueTexture1 {
  public:
    virtual ~CLxImpl_ValueTexture1() {}
    virtual LxResult
      vtx_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtx_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtx_ReadChannels (ILxUnknownID attr, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtx_Customize (ILxUnknownID custom, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual void
      vtx_Evaluate (ILxUnknownID vector, LXpTextureOutput *tOut, void *data)
        { }
    virtual void
      vtx_Cleanup (void *data)
        { }
};
#define LXxD_ValueTexture1_SetupChannels LxResult vtx_SetupChannels (ILxUnknownID addChan)
#define LXxO_ValueTexture1_SetupChannels LXxD_ValueTexture1_SetupChannels LXx_OVERRIDE
#define LXxC_ValueTexture1_SetupChannels(c) LxResult c::vtx_SetupChannels (ILxUnknownID addChan)
#define LXxD_ValueTexture1_LinkChannels LxResult vtx_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxO_ValueTexture1_LinkChannels LXxD_ValueTexture1_LinkChannels LXx_OVERRIDE
#define LXxC_ValueTexture1_LinkChannels(c) LxResult c::vtx_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxD_ValueTexture1_ReadChannels LxResult vtx_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxO_ValueTexture1_ReadChannels LXxD_ValueTexture1_ReadChannels LXx_OVERRIDE
#define LXxC_ValueTexture1_ReadChannels(c) LxResult c::vtx_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxD_ValueTexture1_Customize LxResult vtx_Customize (ILxUnknownID custom, void **ppvData)
#define LXxO_ValueTexture1_Customize LXxD_ValueTexture1_Customize LXx_OVERRIDE
#define LXxC_ValueTexture1_Customize(c) LxResult c::vtx_Customize (ILxUnknownID custom, void **ppvData)
#define LXxD_ValueTexture1_Evaluate void vtx_Evaluate (ILxUnknownID vector, LXpTextureOutput *tOut, void *data)
#define LXxO_ValueTexture1_Evaluate LXxD_ValueTexture1_Evaluate LXx_OVERRIDE
#define LXxC_ValueTexture1_Evaluate(c) void c::vtx_Evaluate (ILxUnknownID vector, LXpTextureOutput *tOut, void *data)
#define LXxD_ValueTexture1_Cleanup void vtx_Cleanup (void *data)
#define LXxO_ValueTexture1_Cleanup LXxD_ValueTexture1_Cleanup LXx_OVERRIDE
#define LXxC_ValueTexture1_Cleanup(c) void c::vtx_Cleanup (void *data)
template <class T>
class CLxIfc_ValueTexture1 : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_ValueTexture1, loc);
    try {
      return loc->vtx_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkChannels (LXtObjectID wcom, LXtObjectID eval, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_ValueTexture1, loc);
    try {
      return loc->vtx_LinkChannels ((ILxUnknownID)eval,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReadChannels (LXtObjectID wcom, LXtObjectID attr, void **ppvData)
  {
    LXCWxINST (CLxImpl_ValueTexture1, loc);
    try {
      return loc->vtx_ReadChannels ((ILxUnknownID)attr,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Customize (LXtObjectID wcom, LXtObjectID custom, void **ppvData)
  {
    LXCWxINST (CLxImpl_ValueTexture1, loc);
    try {
      return loc->vtx_Customize ((ILxUnknownID)custom,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Evaluate (LXtObjectID wcom, LXtObjectID vector, LXpTextureOutput *tOut, void *data)
  {
    LXCWxINST (CLxImpl_ValueTexture1, loc);
    loc->vtx_Evaluate ((ILxUnknownID)vector,tOut,data);
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_ValueTexture1, loc);
    loc->vtx_Cleanup (data);
  }
  ILxValueTexture1 vt;
public:
  CLxIfc_ValueTexture1 ()
  {
    vt.SetupChannels = SetupChannels;
    vt.LinkChannels = LinkChannels;
    vt.ReadChannels = ReadChannels;
    vt.Customize = Customize;
    vt.Evaluate = Evaluate;
    vt.Cleanup = Cleanup;
    vTable = &vt.iunk;
    iid = &lx::guid_ValueTexture1;
  }
};





class CLxLoc_Texture : public CLxLocalize<ILxTextureID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Texture() {_init();}
  CLxLoc_Texture(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Texture(const CLxLoc_Texture &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Texture;}
    LxResult
  Locator (void **ppvObj)
  {
    return m_loc[0]->Locator (m_loc,ppvObj);
  }
    CLxResult
  Locator (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Locator(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetLocator (ILxUnknownID tloc)
  {
    return m_loc[0]->SetLocator (m_loc,(ILxUnknownID)tloc);
  }
    LxResult
  Image (void **ppvObj)
  {
    return m_loc[0]->Image (m_loc,ppvObj);
  }
    CLxResult
  Image (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Image(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetImage (ILxUnknownID img)
  {
    return m_loc[0]->SetImage (m_loc,(ILxUnknownID)img);
  }
    const char *
  ImageName (void)
  {
    return m_loc[0]->ImageName (m_loc);
  }
    LxResult
  EvalImage (ILxUnknownID scene, void **ppvObj)
  {
    return m_loc[0]->EvalImage (m_loc,(ILxUnknownID)scene,ppvObj);
  }
    CLxResult
  EvalImage (ILxUnknownID scene, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->EvalImage(m_loc,(ILxUnknownID)scene,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    int
  LocatorProjectionMode (double time)
  {
    return m_loc[0]->LocatorProjectionMode (m_loc,time);
  }
    int
  LocatorProjectionAxis (double time)
  {
    return m_loc[0]->LocatorProjectionAxis (m_loc,time);
  }
    const char *
  Effect (void)
  {
    return m_loc[0]->Effect (m_loc);
  }
    LxResult
  SetEffect (const char *effect)
  {
    return m_loc[0]->SetEffect (m_loc,effect);
  }
};

class CLxImpl_CustomMaterial1 {
  public:
    virtual ~CLxImpl_CustomMaterial1() {}
    virtual LxResult
      cmt_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_ReadChannels (ILxUnknownID attr, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_Customize (ILxUnknownID custom, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual void
      cmt_MaterialEvaluate (ILxUnknownID vector, void *data)
        { }
    virtual void
      cmt_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
        { }
    virtual LxResult
      cmt_SetShadeFlags (LXpShadeFlags *sFlg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetBump (float *bumpAmplitude, int *clearBump)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetDisplacement (float *dispDist)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetOpaque (int *opaque)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetSmoothing (double *smooth, double *angle)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_CustomPacket (const char **packet)
        { return LXe_NOTIMPL; }
    virtual void
      cmt_Cleanup (void *data)
        { }
    virtual LxResult
      cmt_UpdatePreview (int chanIdx, int *flags)
        { return LXe_NOTIMPL; }
};
#define LXxD_CustomMaterial1_SetupChannels LxResult cmt_SetupChannels (ILxUnknownID addChan)
#define LXxO_CustomMaterial1_SetupChannels LXxD_CustomMaterial1_SetupChannels LXx_OVERRIDE
#define LXxC_CustomMaterial1_SetupChannels(c) LxResult c::cmt_SetupChannels (ILxUnknownID addChan)
#define LXxD_CustomMaterial1_LinkChannels LxResult cmt_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxO_CustomMaterial1_LinkChannels LXxD_CustomMaterial1_LinkChannels LXx_OVERRIDE
#define LXxC_CustomMaterial1_LinkChannels(c) LxResult c::cmt_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxD_CustomMaterial1_ReadChannels LxResult cmt_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxO_CustomMaterial1_ReadChannels LXxD_CustomMaterial1_ReadChannels LXx_OVERRIDE
#define LXxC_CustomMaterial1_ReadChannels(c) LxResult c::cmt_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxD_CustomMaterial1_Customize LxResult cmt_Customize (ILxUnknownID custom, void **ppvData)
#define LXxO_CustomMaterial1_Customize LXxD_CustomMaterial1_Customize LXx_OVERRIDE
#define LXxC_CustomMaterial1_Customize(c) LxResult c::cmt_Customize (ILxUnknownID custom, void **ppvData)
#define LXxD_CustomMaterial1_MaterialEvaluate void cmt_MaterialEvaluate (ILxUnknownID vector, void *data)
#define LXxO_CustomMaterial1_MaterialEvaluate LXxD_CustomMaterial1_MaterialEvaluate LXx_OVERRIDE
#define LXxC_CustomMaterial1_MaterialEvaluate(c) void c::cmt_MaterialEvaluate (ILxUnknownID vector, void *data)
#define LXxD_CustomMaterial1_ShaderEvaluate void cmt_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
#define LXxO_CustomMaterial1_ShaderEvaluate LXxD_CustomMaterial1_ShaderEvaluate LXx_OVERRIDE
#define LXxC_CustomMaterial1_ShaderEvaluate(c) void c::cmt_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
#define LXxD_CustomMaterial1_SetShadeFlags LxResult cmt_SetShadeFlags (LXpShadeFlags *sFlg)
#define LXxO_CustomMaterial1_SetShadeFlags LXxD_CustomMaterial1_SetShadeFlags LXx_OVERRIDE
#define LXxC_CustomMaterial1_SetShadeFlags(c) LxResult c::cmt_SetShadeFlags (LXpShadeFlags *sFlg)
#define LXxD_CustomMaterial1_SetBump LxResult cmt_SetBump (float *bumpAmplitude, int *clearBump)
#define LXxO_CustomMaterial1_SetBump LXxD_CustomMaterial1_SetBump LXx_OVERRIDE
#define LXxC_CustomMaterial1_SetBump(c) LxResult c::cmt_SetBump (float *bumpAmplitude, int *clearBump)
#define LXxD_CustomMaterial1_SetDisplacement LxResult cmt_SetDisplacement (float *dispDist)
#define LXxO_CustomMaterial1_SetDisplacement LXxD_CustomMaterial1_SetDisplacement LXx_OVERRIDE
#define LXxC_CustomMaterial1_SetDisplacement(c) LxResult c::cmt_SetDisplacement (float *dispDist)
#define LXxD_CustomMaterial1_SetOpaque LxResult cmt_SetOpaque (int *opaque)
#define LXxO_CustomMaterial1_SetOpaque LXxD_CustomMaterial1_SetOpaque LXx_OVERRIDE
#define LXxC_CustomMaterial1_SetOpaque(c) LxResult c::cmt_SetOpaque (int *opaque)
#define LXxD_CustomMaterial1_SetSmoothing LxResult cmt_SetSmoothing (double *smooth, double *angle)
#define LXxO_CustomMaterial1_SetSmoothing LXxD_CustomMaterial1_SetSmoothing LXx_OVERRIDE
#define LXxC_CustomMaterial1_SetSmoothing(c) LxResult c::cmt_SetSmoothing (double *smooth, double *angle)
#define LXxD_CustomMaterial1_CustomPacket LxResult cmt_CustomPacket (const char **packet)
#define LXxO_CustomMaterial1_CustomPacket LXxD_CustomMaterial1_CustomPacket LXx_OVERRIDE
#define LXxC_CustomMaterial1_CustomPacket(c) LxResult c::cmt_CustomPacket (const char **packet)
#define LXxD_CustomMaterial1_Cleanup void cmt_Cleanup (void *data)
#define LXxO_CustomMaterial1_Cleanup LXxD_CustomMaterial1_Cleanup LXx_OVERRIDE
#define LXxC_CustomMaterial1_Cleanup(c) void c::cmt_Cleanup (void *data)
#define LXxD_CustomMaterial1_UpdatePreview LxResult cmt_UpdatePreview (int chanIdx, int *flags)
#define LXxO_CustomMaterial1_UpdatePreview LXxD_CustomMaterial1_UpdatePreview LXx_OVERRIDE
#define LXxC_CustomMaterial1_UpdatePreview(c) LxResult c::cmt_UpdatePreview (int chanIdx, int *flags)
template <class T>
class CLxIfc_CustomMaterial1 : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkChannels (LXtObjectID wcom, LXtObjectID eval, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_LinkChannels ((ILxUnknownID)eval,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReadChannels (LXtObjectID wcom, LXtObjectID attr, void **ppvData)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_ReadChannels ((ILxUnknownID)attr,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Customize (LXtObjectID wcom, LXtObjectID custom, void **ppvData)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_Customize ((ILxUnknownID)custom,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static void
  MaterialEvaluate (LXtObjectID wcom, LXtObjectID vector, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    loc->cmt_MaterialEvaluate ((ILxUnknownID)vector,data);
  }
    static void
  ShaderEvaluate (LXtObjectID wcom, LXtObjectID vector, LXtObjectID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    loc->cmt_ShaderEvaluate ((ILxUnknownID)vector,(ILxUnknownID)rayObj,sCmp,sOut,data);
  }
    static LxResult
  SetShadeFlags (LXtObjectID wcom, LXpShadeFlags *sFlg)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_SetShadeFlags (sFlg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetBump (LXtObjectID wcom, float *bumpAmplitude, int *clearBump)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_SetBump (bumpAmplitude,clearBump);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetDisplacement (LXtObjectID wcom, float *dispDist)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_SetDisplacement (dispDist);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetOpaque (LXtObjectID wcom, int *opaque)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_SetOpaque (opaque);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetSmoothing (LXtObjectID wcom, double *smooth, double *angle)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_SetSmoothing (smooth,angle);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CustomPacket (LXtObjectID wcom, const char **packet)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_CustomPacket (packet);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    loc->cmt_Cleanup (data);
  }
    static LxResult
  UpdatePreview (LXtObjectID wcom, int chanIdx, int *flags)
  {
    LXCWxINST (CLxImpl_CustomMaterial1, loc);
    try {
      return loc->cmt_UpdatePreview (chanIdx,flags);
    } catch (LxResult rc) { return rc; }
  }
  ILxCustomMaterial1 vt;
public:
  CLxIfc_CustomMaterial1 ()
  {
    vt.SetupChannels = SetupChannels;
    vt.LinkChannels = LinkChannels;
    vt.ReadChannels = ReadChannels;
    vt.Customize = Customize;
    vt.MaterialEvaluate = MaterialEvaluate;
    vt.ShaderEvaluate = ShaderEvaluate;
    vt.SetShadeFlags = SetShadeFlags;
    vt.SetBump = SetBump;
    vt.SetDisplacement = SetDisplacement;
    vt.SetOpaque = SetOpaque;
    vt.SetSmoothing = SetSmoothing;
    vt.CustomPacket = CustomPacket;
    vt.Cleanup = Cleanup;
    vt.UpdatePreview = UpdatePreview;
    vTable = &vt.iunk;
    iid = &lx::guid_CustomMaterial1;
  }
};

class CLxLoc_ValueTextureCustom : public CLxLocalize<ILxValueTextureCustomID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueTextureCustom() {_init();}
  CLxLoc_ValueTextureCustom(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ValueTextureCustom(const CLxLoc_ValueTextureCustom &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ValueTextureCustom;}
    LxResult
  AddFeature (LXtID4 type, const char *name)
  {
    return m_loc[0]->AddFeature (m_loc,type,name);
  }
    LxResult
  AddPacket (const char *name)
  {
    return m_loc[0]->AddPacket (m_loc,name);
  }
};

class CLxImpl_CustomMaterial {
  public:
    virtual ~CLxImpl_CustomMaterial() {}
    virtual LxResult
      cmt_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
        { return LXe_OK; }
    virtual int
      cmt_IsSampleDriven (int *idx)
        { return LXe_FALSE; }
    virtual LxResult
      cmt_ReadChannels (ILxUnknownID attr, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_Customize (ILxUnknownID custom, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual void
      cmt_MaterialEvaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, void *data)
        { }
    virtual void
      cmt_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
        { }
    virtual LxResult
      cmt_SetShadeFlags (LXpShadeFlags *sFlg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetBump (float *bumpAmplitude, int *clearBump)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetDisplacement (float *dispDist)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetOpaque (int *opaque)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetSmoothing (double *smooth, double *angle, int *weighting, int *normalMethod, int *creasing)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_CustomPacket (const char **packet)
        { return LXe_NOTIMPL; }
    virtual void
      cmt_Cleanup (void *data)
        { }
    virtual LxResult
      cmt_UpdatePreview (int chanIdx, int *flags)
        { return LXe_NOTIMPL; }
    virtual int
      cmt_Flags (void)
        = 0;
};
#define LXxD_CustomMaterial_SetupChannels LxResult cmt_SetupChannels (ILxUnknownID addChan)
#define LXxO_CustomMaterial_SetupChannels LXxD_CustomMaterial_SetupChannels LXx_OVERRIDE
#define LXxC_CustomMaterial_SetupChannels(c) LxResult c::cmt_SetupChannels (ILxUnknownID addChan)
#define LXxD_CustomMaterial_LinkChannels LxResult cmt_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxO_CustomMaterial_LinkChannels LXxD_CustomMaterial_LinkChannels LXx_OVERRIDE
#define LXxC_CustomMaterial_LinkChannels(c) LxResult c::cmt_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxD_CustomMaterial_LinkSampleChannels LxResult cmt_LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
#define LXxO_CustomMaterial_LinkSampleChannels LXxD_CustomMaterial_LinkSampleChannels LXx_OVERRIDE
#define LXxC_CustomMaterial_LinkSampleChannels(c) LxResult c::cmt_LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
#define LXxD_CustomMaterial_IsSampleDriven int cmt_IsSampleDriven (int *idx)
#define LXxO_CustomMaterial_IsSampleDriven LXxD_CustomMaterial_IsSampleDriven LXx_OVERRIDE
#define LXxC_CustomMaterial_IsSampleDriven(c) int c::cmt_IsSampleDriven (int *idx)
#define LXxD_CustomMaterial_ReadChannels LxResult cmt_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxO_CustomMaterial_ReadChannels LXxD_CustomMaterial_ReadChannels LXx_OVERRIDE
#define LXxC_CustomMaterial_ReadChannels(c) LxResult c::cmt_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxD_CustomMaterial_Customize LxResult cmt_Customize (ILxUnknownID custom, void **ppvData)
#define LXxO_CustomMaterial_Customize LXxD_CustomMaterial_Customize LXx_OVERRIDE
#define LXxC_CustomMaterial_Customize(c) LxResult c::cmt_Customize (ILxUnknownID custom, void **ppvData)
#define LXxD_CustomMaterial_MaterialEvaluate void cmt_MaterialEvaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, void *data)
#define LXxO_CustomMaterial_MaterialEvaluate LXxD_CustomMaterial_MaterialEvaluate LXx_OVERRIDE
#define LXxC_CustomMaterial_MaterialEvaluate(c) void c::cmt_MaterialEvaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, void *data)
#define LXxD_CustomMaterial_ShaderEvaluate void cmt_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
#define LXxO_CustomMaterial_ShaderEvaluate LXxD_CustomMaterial_ShaderEvaluate LXx_OVERRIDE
#define LXxC_CustomMaterial_ShaderEvaluate(c) void c::cmt_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
#define LXxD_CustomMaterial_SetShadeFlags LxResult cmt_SetShadeFlags (LXpShadeFlags *sFlg)
#define LXxO_CustomMaterial_SetShadeFlags LXxD_CustomMaterial_SetShadeFlags LXx_OVERRIDE
#define LXxC_CustomMaterial_SetShadeFlags(c) LxResult c::cmt_SetShadeFlags (LXpShadeFlags *sFlg)
#define LXxD_CustomMaterial_SetBump LxResult cmt_SetBump (float *bumpAmplitude, int *clearBump)
#define LXxO_CustomMaterial_SetBump LXxD_CustomMaterial_SetBump LXx_OVERRIDE
#define LXxC_CustomMaterial_SetBump(c) LxResult c::cmt_SetBump (float *bumpAmplitude, int *clearBump)
#define LXxD_CustomMaterial_SetDisplacement LxResult cmt_SetDisplacement (float *dispDist)
#define LXxO_CustomMaterial_SetDisplacement LXxD_CustomMaterial_SetDisplacement LXx_OVERRIDE
#define LXxC_CustomMaterial_SetDisplacement(c) LxResult c::cmt_SetDisplacement (float *dispDist)
#define LXxD_CustomMaterial_SetOpaque LxResult cmt_SetOpaque (int *opaque)
#define LXxO_CustomMaterial_SetOpaque LXxD_CustomMaterial_SetOpaque LXx_OVERRIDE
#define LXxC_CustomMaterial_SetOpaque(c) LxResult c::cmt_SetOpaque (int *opaque)
#define LXxD_CustomMaterial_SetSmoothing LxResult cmt_SetSmoothing (double *smooth, double *angle, int *weighting, int *normalMethod, int *creasing)
#define LXxO_CustomMaterial_SetSmoothing LXxD_CustomMaterial_SetSmoothing LXx_OVERRIDE
#define LXxC_CustomMaterial_SetSmoothing(c) LxResult c::cmt_SetSmoothing (double *smooth, double *angle, int *weighting, int *normalMethod, int *creasing)
#define LXxD_CustomMaterial_CustomPacket LxResult cmt_CustomPacket (const char **packet)
#define LXxO_CustomMaterial_CustomPacket LXxD_CustomMaterial_CustomPacket LXx_OVERRIDE
#define LXxC_CustomMaterial_CustomPacket(c) LxResult c::cmt_CustomPacket (const char **packet)
#define LXxD_CustomMaterial_Cleanup void cmt_Cleanup (void *data)
#define LXxO_CustomMaterial_Cleanup LXxD_CustomMaterial_Cleanup LXx_OVERRIDE
#define LXxC_CustomMaterial_Cleanup(c) void c::cmt_Cleanup (void *data)
#define LXxD_CustomMaterial_UpdatePreview LxResult cmt_UpdatePreview (int chanIdx, int *flags)
#define LXxO_CustomMaterial_UpdatePreview LXxD_CustomMaterial_UpdatePreview LXx_OVERRIDE
#define LXxC_CustomMaterial_UpdatePreview(c) LxResult c::cmt_UpdatePreview (int chanIdx, int *flags)
#define LXxD_CustomMaterial_Flags int cmt_Flags (void)
#define LXxO_CustomMaterial_Flags LXxD_CustomMaterial_Flags LXx_OVERRIDE
#define LXxC_CustomMaterial_Flags(c) int c::cmt_Flags (void)
template <class T>
class CLxIfc_CustomMaterial : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkChannels (LXtObjectID wcom, LXtObjectID eval, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_LinkChannels ((ILxUnknownID)eval,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkSampleChannels (LXtObjectID wcom, LXtObjectID nodalEtor, LXtObjectID item, int *idx)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_LinkSampleChannels ((ILxUnknownID)nodalEtor,(ILxUnknownID)item,idx);
    } catch (LxResult rc) { return rc; }
  }
    static int
  IsSampleDriven (LXtObjectID wcom, int *idx)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    return loc->cmt_IsSampleDriven (idx);
  }
    static LxResult
  ReadChannels (LXtObjectID wcom, LXtObjectID attr, void **ppvData)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_ReadChannels ((ILxUnknownID)attr,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Customize (LXtObjectID wcom, LXtObjectID custom, void **ppvData)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_Customize ((ILxUnknownID)custom,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static void
  MaterialEvaluate (LXtObjectID wcom, LXtObjectID etor, int *idx, LXtObjectID vector, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    loc->cmt_MaterialEvaluate ((ILxUnknownID)etor,idx,(ILxUnknownID)vector,data);
  }
    static void
  ShaderEvaluate (LXtObjectID wcom, LXtObjectID vector, LXtObjectID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    loc->cmt_ShaderEvaluate ((ILxUnknownID)vector,(ILxUnknownID)rayObj,sCmp,sOut,data);
  }
    static LxResult
  SetShadeFlags (LXtObjectID wcom, LXpShadeFlags *sFlg)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetShadeFlags (sFlg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetBump (LXtObjectID wcom, float *bumpAmplitude, int *clearBump)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetBump (bumpAmplitude,clearBump);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetDisplacement (LXtObjectID wcom, float *dispDist)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetDisplacement (dispDist);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetOpaque (LXtObjectID wcom, int *opaque)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetOpaque (opaque);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetSmoothing (LXtObjectID wcom, double *smooth, double *angle, int *weighting, int *normalMethod, int *creasing)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetSmoothing (smooth,angle,weighting,normalMethod,creasing);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CustomPacket (LXtObjectID wcom, const char **packet)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_CustomPacket (packet);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    loc->cmt_Cleanup (data);
  }
    static LxResult
  UpdatePreview (LXtObjectID wcom, int chanIdx, int *flags)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_UpdatePreview (chanIdx,flags);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    return loc->cmt_Flags ();
  }
  ILxCustomMaterial vt;
public:
  CLxIfc_CustomMaterial ()
  {
    vt.SetupChannels = SetupChannels;
    vt.LinkChannels = LinkChannels;
    vt.LinkSampleChannels = LinkSampleChannels;
    vt.IsSampleDriven = IsSampleDriven;
    vt.ReadChannels = ReadChannels;
    vt.Customize = Customize;
    vt.MaterialEvaluate = MaterialEvaluate;
    vt.ShaderEvaluate = ShaderEvaluate;
    vt.SetShadeFlags = SetShadeFlags;
    vt.SetBump = SetBump;
    vt.SetDisplacement = SetDisplacement;
    vt.SetOpaque = SetOpaque;
    vt.SetSmoothing = SetSmoothing;
    vt.CustomPacket = CustomPacket;
    vt.Cleanup = Cleanup;
    vt.UpdatePreview = UpdatePreview;
    vt.Flags = Flags;
    vTable = &vt.iunk;
    iid = &lx::guid_CustomMaterial;
  }
};
class CLxLoc_CustomMaterial : public CLxLocalize<ILxCustomMaterialID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CustomMaterial() {_init();}
  CLxLoc_CustomMaterial(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CustomMaterial(const CLxLoc_CustomMaterial &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CustomMaterial;}
    LxResult
  SetupChannels (ILxUnknownID addChan)
  {
    return m_loc[0]->SetupChannels (m_loc,(ILxUnknownID)addChan);
  }
    LxResult
  LinkChannels (ILxUnknownID eval, ILxUnknownID item)
  {
    return m_loc[0]->LinkChannels (m_loc,(ILxUnknownID)eval,(ILxUnknownID)item);
  }
    LxResult
  LinkSampleChannels (ILxUnknownID nodalEtor, ILxUnknownID item, int *idx)
  {
    return m_loc[0]->LinkSampleChannels (m_loc,(ILxUnknownID)nodalEtor,(ILxUnknownID)item,idx);
  }
    int
  IsSampleDriven (int *idx)
  {
    return m_loc[0]->IsSampleDriven (m_loc,idx);
  }
    LxResult
  ReadChannels (ILxUnknownID attr, void **ppvData)
  {
    return m_loc[0]->ReadChannels (m_loc,(ILxUnknownID)attr,ppvData);
  }
    LxResult
  Customize (ILxUnknownID custom, void **ppvData)
  {
    return m_loc[0]->Customize (m_loc,(ILxUnknownID)custom,ppvData);
  }
    void
  MaterialEvaluate (ILxUnknownID etor, int *idx, ILxUnknownID vector, void *data)
  {
    m_loc[0]->MaterialEvaluate (m_loc,(ILxUnknownID)etor,idx,(ILxUnknownID)vector,data);
  }
    void
  ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
  {
    m_loc[0]->ShaderEvaluate (m_loc,(ILxUnknownID)vector,(ILxUnknownID)rayObj,sCmp,sOut,data);
  }
    LxResult
  SetShadeFlags (LXpShadeFlags *sFlg)
  {
    return m_loc[0]->SetShadeFlags (m_loc,sFlg);
  }
    LxResult
  SetBump (float *bumpAmplitude, int *clearBump)
  {
    return m_loc[0]->SetBump (m_loc,bumpAmplitude,clearBump);
  }
    LxResult
  SetDisplacement (float *dispDist)
  {
    return m_loc[0]->SetDisplacement (m_loc,dispDist);
  }
    LxResult
  SetOpaque (int *opaque)
  {
    return m_loc[0]->SetOpaque (m_loc,opaque);
  }
    LxResult
  SetSmoothing (double *smooth, double *angle, int *weighting, int *normalMethod, int *creasing)
  {
    return m_loc[0]->SetSmoothing (m_loc,smooth,angle,weighting,normalMethod,creasing);
  }
    LxResult
  CustomPacket (const char **packet)
  {
    return m_loc[0]->CustomPacket (m_loc,packet);
  }
    void
  Cleanup (void *data)
  {
    m_loc[0]->Cleanup (m_loc,data);
  }
    LxResult
  UpdatePreview (int chanIdx, int *flags)
  {
    return m_loc[0]->UpdatePreview (m_loc,chanIdx,flags);
  }
    int
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
};

class CLxImpl_CompShader {
  public:
    virtual ~CLxImpl_CompShader() {}
    virtual LxResult
      csh_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_ReadChannels (ILxUnknownID attr, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_Customize (ILxUnknownID custom, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual void
      csh_Evaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
        { }
    virtual LxResult
      csh_SetShadeFlags (LXpShadeFlags *sFlg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_SetOpaque (int *opaque)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_CustomPacket (const char **packet)
        { return LXe_NOTIMPL; }
    virtual void
      csh_Cleanup (void *data)
        { }
    virtual int
      csh_Flags (void)
        = 0;
};
#define LXxD_CompShader_SetupChannels LxResult csh_SetupChannels (ILxUnknownID addChan)
#define LXxO_CompShader_SetupChannels LXxD_CompShader_SetupChannels LXx_OVERRIDE
#define LXxC_CompShader_SetupChannels(c) LxResult c::csh_SetupChannels (ILxUnknownID addChan)
#define LXxD_CompShader_LinkChannels LxResult csh_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxO_CompShader_LinkChannels LXxD_CompShader_LinkChannels LXx_OVERRIDE
#define LXxC_CompShader_LinkChannels(c) LxResult c::csh_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
#define LXxD_CompShader_ReadChannels LxResult csh_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxO_CompShader_ReadChannels LXxD_CompShader_ReadChannels LXx_OVERRIDE
#define LXxC_CompShader_ReadChannels(c) LxResult c::csh_ReadChannels (ILxUnknownID attr, void **ppvData)
#define LXxD_CompShader_Customize LxResult csh_Customize (ILxUnknownID custom, void **ppvData)
#define LXxO_CompShader_Customize LXxD_CompShader_Customize LXx_OVERRIDE
#define LXxC_CompShader_Customize(c) LxResult c::csh_Customize (ILxUnknownID custom, void **ppvData)
#define LXxD_CompShader_Evaluate void csh_Evaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
#define LXxO_CompShader_Evaluate LXxD_CompShader_Evaluate LXx_OVERRIDE
#define LXxC_CompShader_Evaluate(c) void c::csh_Evaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
#define LXxD_CompShader_SetShadeFlags LxResult csh_SetShadeFlags (LXpShadeFlags *sFlg)
#define LXxO_CompShader_SetShadeFlags LXxD_CompShader_SetShadeFlags LXx_OVERRIDE
#define LXxC_CompShader_SetShadeFlags(c) LxResult c::csh_SetShadeFlags (LXpShadeFlags *sFlg)
#define LXxD_CompShader_SetOpaque LxResult csh_SetOpaque (int *opaque)
#define LXxO_CompShader_SetOpaque LXxD_CompShader_SetOpaque LXx_OVERRIDE
#define LXxC_CompShader_SetOpaque(c) LxResult c::csh_SetOpaque (int *opaque)
#define LXxD_CompShader_CustomPacket LxResult csh_CustomPacket (const char **packet)
#define LXxO_CompShader_CustomPacket LXxD_CompShader_CustomPacket LXx_OVERRIDE
#define LXxC_CompShader_CustomPacket(c) LxResult c::csh_CustomPacket (const char **packet)
#define LXxD_CompShader_Cleanup void csh_Cleanup (void *data)
#define LXxO_CompShader_Cleanup LXxD_CompShader_Cleanup LXx_OVERRIDE
#define LXxC_CompShader_Cleanup(c) void c::csh_Cleanup (void *data)
#define LXxD_CompShader_Flags int csh_Flags (void)
#define LXxO_CompShader_Flags LXxD_CompShader_Flags LXx_OVERRIDE
#define LXxC_CompShader_Flags(c) int c::csh_Flags (void)
template <class T>
class CLxIfc_CompShader : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkChannels (LXtObjectID wcom, LXtObjectID eval, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_LinkChannels ((ILxUnknownID)eval,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReadChannels (LXtObjectID wcom, LXtObjectID attr, void **ppvData)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_ReadChannels ((ILxUnknownID)attr,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Customize (LXtObjectID wcom, LXtObjectID custom, void **ppvData)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_Customize ((ILxUnknownID)custom,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Evaluate (LXtObjectID wcom, LXtObjectID vector, LXtObjectID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    loc->csh_Evaluate ((ILxUnknownID)vector,(ILxUnknownID)rayObj,sCmp,sOut,data);
  }
    static LxResult
  SetShadeFlags (LXtObjectID wcom, LXpShadeFlags *sFlg)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_SetShadeFlags (sFlg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetOpaque (LXtObjectID wcom, int *opaque)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_SetOpaque (opaque);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CustomPacket (LXtObjectID wcom, const char **packet)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_CustomPacket (packet);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    loc->csh_Cleanup (data);
  }
    static int
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    return loc->csh_Flags ();
  }
  ILxCompShader vt;
public:
  CLxIfc_CompShader ()
  {
    vt.SetupChannels = SetupChannels;
    vt.LinkChannels = LinkChannels;
    vt.ReadChannels = ReadChannels;
    vt.Customize = Customize;
    vt.Evaluate = Evaluate;
    vt.SetShadeFlags = SetShadeFlags;
    vt.SetOpaque = SetOpaque;
    vt.CustomPacket = CustomPacket;
    vt.Cleanup = Cleanup;
    vt.Flags = Flags;
    vTable = &vt.iunk;
    iid = &lx::guid_CompShader;
  }
};
class CLxLoc_CompShader : public CLxLocalize<ILxCompShaderID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CompShader() {_init();}
  CLxLoc_CompShader(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CompShader(const CLxLoc_CompShader &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CompShader;}
    LxResult
  SetupChannels (ILxUnknownID addChan)
  {
    return m_loc[0]->SetupChannels (m_loc,(ILxUnknownID)addChan);
  }
    LxResult
  LinkChannels (ILxUnknownID eval, ILxUnknownID item)
  {
    return m_loc[0]->LinkChannels (m_loc,(ILxUnknownID)eval,(ILxUnknownID)item);
  }
    LxResult
  ReadChannels (ILxUnknownID attr, void **ppvData)
  {
    return m_loc[0]->ReadChannels (m_loc,(ILxUnknownID)attr,ppvData);
  }
    LxResult
  Customize (ILxUnknownID custom, void **ppvData)
  {
    return m_loc[0]->Customize (m_loc,(ILxUnknownID)custom,ppvData);
  }
    void
  Evaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
  {
    m_loc[0]->Evaluate (m_loc,(ILxUnknownID)vector,(ILxUnknownID)rayObj,sCmp,sOut,data);
  }
    LxResult
  SetShadeFlags (LXpShadeFlags *sFlg)
  {
    return m_loc[0]->SetShadeFlags (m_loc,sFlg);
  }
    LxResult
  SetOpaque (int *opaque)
  {
    return m_loc[0]->SetOpaque (m_loc,opaque);
  }
    LxResult
  CustomPacket (const char **packet)
  {
    return m_loc[0]->CustomPacket (m_loc,packet);
  }
    void
  Cleanup (void *data)
  {
    m_loc[0]->Cleanup (m_loc,data);
  }
    int
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
};

#endif

