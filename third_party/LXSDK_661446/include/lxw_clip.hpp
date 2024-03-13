/*
 * C++ wrapper for lxclip.h
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
#ifndef LXW_CLIP_HPP
#define LXW_CLIP_HPP

#include <lxclip.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_VideoClipItem = {0x340FD1AD,0xB576,0x4BC3,0x8B,0x6F,0x7D,0xF1,0xF5,0xC3,0x12,0xFB};
};

class CLxImpl_VideoClipItem {
  public:
    virtual ~CLxImpl_VideoClipItem() {}
    virtual LxResult
      vclip_PrepFilter (ILxUnknownID eval, void **cache)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vclip_AllocFilter (ILxUnknownID attr, void *cache, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual void
      vclip_Cleanup (void *cache)
        { }
};
#define LXxD_VideoClipItem_PrepFilter LxResult vclip_PrepFilter (ILxUnknownID eval, void **cache)
#define LXxO_VideoClipItem_PrepFilter LXxD_VideoClipItem_PrepFilter LXx_OVERRIDE
#define LXxC_VideoClipItem_PrepFilter(c) LxResult c::vclip_PrepFilter (ILxUnknownID eval, void **cache)
#define LXxD_VideoClipItem_AllocFilter LxResult vclip_AllocFilter (ILxUnknownID attr, void *cache, void **ppvObj)
#define LXxO_VideoClipItem_AllocFilter LXxD_VideoClipItem_AllocFilter LXx_OVERRIDE
#define LXxC_VideoClipItem_AllocFilter(c) LxResult c::vclip_AllocFilter (ILxUnknownID attr, void *cache, void **ppvObj)
#define LXxD_VideoClipItem_Cleanup void vclip_Cleanup (void *cache)
#define LXxO_VideoClipItem_Cleanup LXxD_VideoClipItem_Cleanup LXx_OVERRIDE
#define LXxC_VideoClipItem_Cleanup(c) void c::vclip_Cleanup (void *cache)
template <class T>
class CLxIfc_VideoClipItem : public CLxInterface
{
    static LxResult
  PrepFilter (LXtObjectID wcom, LXtObjectID eval, void **cache)
  {
    LXCWxINST (CLxImpl_VideoClipItem, loc);
    try {
      return loc->vclip_PrepFilter ((ILxUnknownID)eval,cache);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AllocFilter (LXtObjectID wcom, LXtObjectID attr, void *cache, void **ppvObj)
  {
    LXCWxINST (CLxImpl_VideoClipItem, loc);
    try {
      return loc->vclip_AllocFilter ((ILxUnknownID)attr,cache,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *cache)
  {
    LXCWxINST (CLxImpl_VideoClipItem, loc);
    loc->vclip_Cleanup (cache);
  }
  ILxVideoClipItem vt;
public:
  CLxIfc_VideoClipItem ()
  {
    vt.PrepFilter = PrepFilter;
    vt.AllocFilter = AllocFilter;
    vt.Cleanup = Cleanup;
    vTable = &vt.iunk;
    iid = &lx::guid_VideoClipItem;
  }
};
class CLxLoc_VideoClipItem : public CLxLocalize<ILxVideoClipItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VideoClipItem() {_init();}
  CLxLoc_VideoClipItem(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VideoClipItem(const CLxLoc_VideoClipItem &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VideoClipItem;}
    LxResult
  PrepFilter (ILxUnknownID eval, void **cache)
  {
    return m_loc[0]->PrepFilter (m_loc,(ILxUnknownID)eval,cache);
  }
    LxResult
  AllocFilter (ILxUnknownID attr, void *cache, void **ppvObj)
  {
    return m_loc[0]->AllocFilter (m_loc,(ILxUnknownID)attr,cache,ppvObj);
  }
    CLxResult
  AllocFilter (ILxUnknownID attr, void *cache, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AllocFilter(m_loc,(ILxUnknownID)attr,cache,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    void
  Cleanup (void *cache)
  {
    m_loc[0]->Cleanup (m_loc,cache);
  }
};

#endif

