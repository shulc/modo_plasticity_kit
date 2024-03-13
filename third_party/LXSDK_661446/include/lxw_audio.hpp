/*
 * C++ wrapper for lxaudio.h
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
#ifndef LXW_AUDIO_HPP
#define LXW_AUDIO_HPP

#include <lxaudio.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_AudioAnimService = {0x42F4A65B,0xA5BE,0x4C77,0x8A,0x66,0x3C,0x1B,0x24,0x5C,0x6B,0xB0};
};

class CLxLoc_AudioAnimService : public CLxLocalizedService
{
public:
  ILxAudioAnimServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_AudioAnimService() {_init();set();}
 ~CLxLoc_AudioAnimService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxAudioAnimServiceID>(lx::GetGlobal(&lx::guid_AudioAnimService));}
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
    LxResult
  Sample (double time, unsigned int type, void *value)
  {
    return m_loc[0]->Sample (m_loc,time,type,value);
  }
    int
  Playing (void)
  {
    return m_loc[0]->Playing (m_loc);
  }
    int
  Loop (void)
  {
    return m_loc[0]->Loop (m_loc);
  }
    int
  Mute (void)
  {
    return m_loc[0]->Mute (m_loc);
  }
    int
  Scrub (void)
  {
    return m_loc[0]->Scrub (m_loc);
  }
    double
  Start (void)
  {
    return m_loc[0]->Start (m_loc);
  }
    double
  End (void)
  {
    return m_loc[0]->End (m_loc);
  }
    LxResult
  Audio (void **ppvObj)
  {
    return m_loc[0]->Audio (m_loc,ppvObj);
  }
    CLxResult
  Audio (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Audio(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Preview (double startTime, double endTime, void **ppvObj)
  {
    return m_loc[0]->Preview (m_loc,startTime,endTime,ppvObj);
  }
    CLxResult
  Preview (double startTime, double endTime, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Preview(m_loc,startTime,endTime,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemSample (ILxUnknownID obj, int loop, double time, unsigned int type, void *value)
  {
    return m_loc[0]->ItemSample (m_loc,(ILxUnknownID)obj,loop,time,type,value);
  }
    LxResult
  ItemAudio (ILxUnknownID obj, void **ppvObj)
  {
    return m_loc[0]->ItemAudio (m_loc,(ILxUnknownID)obj,ppvObj);
  }
    CLxResult
  ItemAudio (ILxUnknownID obj, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemAudio(m_loc,(ILxUnknownID)obj,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

