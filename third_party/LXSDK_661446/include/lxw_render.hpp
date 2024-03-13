/*
 * C++ wrapper for lxrender.h
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
#ifndef LXW_RENDER_HPP
#define LXW_RENDER_HPP

#include <lxrender.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_RenderBucket = {0xED6F0ABE,0xF76F,0x4EED,0xBE,0xF5,0xA3,0x0F,0xF7,0xF7,0x10,0x98};
};

class CLxLoc_RenderBucket : public CLxLocalize<ILxRenderBucketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_RenderBucket() {_init();}
  CLxLoc_RenderBucket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_RenderBucket(const CLxLoc_RenderBucket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_RenderBucket;}
    unsigned int
  Thread (void)
  {
    return m_loc[0]->Thread (m_loc);
  }
    LxResult
  SampleVec (void **ppvObj)
  {
    return m_loc[0]->SampleVec (m_loc,ppvObj);
  }
    CLxResult
  SampleVec (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SampleVec(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  PushRay (void)
  {
    return m_loc[0]->PushRay (m_loc);
  }
    LxResult
  PopRay (void)
  {
    return m_loc[0]->PopRay (m_loc);
  }
    int
  GetGIBounce (void)
  {
    return m_loc[0]->GetGIBounce (m_loc);
  }
    void
  GetPixel (int *x, int *y)
  {
    m_loc[0]->GetPixel (m_loc,x,y);
  }
    void
  GetSubPixel (float *x, float *y)
  {
    m_loc[0]->GetSubPixel (m_loc,x,y);
  }
    float
  GetTimeOffset (void)
  {
    return m_loc[0]->GetTimeOffset (m_loc);
  }
};

#endif

