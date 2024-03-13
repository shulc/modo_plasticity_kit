/*
 * C++ wrapper for lxintrange.h
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
#ifndef LXW_INTRANGE_HPP
#define LXW_INTRANGE_HPP

#include <lxintrange.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_IntRange = {0xFEAF19EC,0xB819,0x4C46,0xAB,0xA3,0xEC,0x85,0x93,0xF8,0xBE,0x8C};
};

class CLxLoc_IntRange : public CLxLocalize<ILxIntRangeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_IntRange() {_init();}
  CLxLoc_IntRange(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_IntRange(const CLxLoc_IntRange &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_IntRange;}
    LxResult
  AllBefore (void) const
  {
    return m_loc[0]->AllBefore (m_loc);
  }
    LxResult
  AllAfter (void) const
  {
    return m_loc[0]->AllAfter (m_loc);
  }
    LxResult
  Next (int *i)
  {
    return m_loc[0]->Next (m_loc,i);
  }
    LxResult
  Prev (int *i)
  {
    return m_loc[0]->Prev (m_loc,i);
  }
    LxResult
  Min (int *min)
  {
    return m_loc[0]->Min (m_loc,min);
  }
    LxResult
  Max (int *max)
  {
    return m_loc[0]->Max (m_loc,max);
  }
    LxResult
  First (int *first)
  {
    return m_loc[0]->First (m_loc,first);
  }
    LxResult
  Last (int *last)
  {
    return m_loc[0]->Last (m_loc,last);
  }
    LxResult
  Current (int *current) const
  {
    return m_loc[0]->Current (m_loc,current);
  }
    LxResult
  Test (int i) const
  {
    return m_loc[0]->Test (m_loc,i);
  }
};

#endif

