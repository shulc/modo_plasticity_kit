/*
 * C++ wrapper for lxpattern.h
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
#ifndef LXW_PATTERN_HPP
#define LXW_PATTERN_HPP

#include <lxpattern.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_Pattern = {0x16EE409B,0x6B63,0x4CB0,0x8D,0xE6,0xC3,0xD9,0xAD,0x12,0x4D,0xBE};
};

class CLxLoc_Pattern : public CLxLocalize<ILxPatternID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Pattern() {_init();}
  CLxLoc_Pattern(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Pattern(const CLxLoc_Pattern &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Pattern;}
    LxResult
  Test (int index, int offset) const
  {
    return m_loc[0]->Test (m_loc,index,offset);
  }
    LxResult
  GenerateSequenceString (int start, int end, char *buf, unsigned int len) const
  {
    return m_loc[0]->GenerateSequenceString (m_loc,start,end,buf,len);
  }
    LxResult
  GenerateSequenceString (int start, int end, std::string &result) const
  {
    LXWx_SBUF1
    rc = m_loc[0]->GenerateSequenceString (m_loc,start,end,buf,len);
    LXWx_SBUF2
  }
};

#endif

