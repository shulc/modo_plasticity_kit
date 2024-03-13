/*
 * C++ wrapper for lxpvedit.h
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
#ifndef LXW_PVEDIT_HPP
#define LXW_PVEDIT_HPP

#include <lxpvedit.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_SolidDrill = {0x0D6D30C6,0x0DEB,0x4848,0xA9,0xF9,0x73,0x14,0x72,0x25,0x5B,0xA9};
    static const LXtGUID guid_PolygonSlice = {0x99C623EE,0x0873,0x4DB5,0x90,0xDF,0xCC,0x94,0x60,0xDA,0x8F,0xA8};
};

class CLxLoc_SolidDrill : public CLxLocalize<ILxSolidDrillID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SolidDrill() {_init();}
  CLxLoc_SolidDrill(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SolidDrill(const CLxLoc_SolidDrill &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SolidDrill;}
    LxResult
  Clear (void)
  {
    return m_loc[0]->Clear (m_loc);
  }
    LxResult
  AddMesh (ILxUnknownID meshObj, const LXtMatrix4 xfrm)
  {
    return m_loc[0]->AddMesh (m_loc,(ILxUnknownID)meshObj,xfrm);
  }
    LxResult
  Execute (ILxUnknownID meshObj, const LXtMatrix4 xfrm, LXtMarkMode pick, unsigned int mode, const char *sten, ILxUnknownID monitor)
  {
    return m_loc[0]->Execute (m_loc,(ILxUnknownID)meshObj,xfrm,pick,mode,sten,(ILxUnknownID)monitor);
  }
};

class CLxLoc_PolygonSlice : public CLxLocalize<ILxPolygonSliceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PolygonSlice() {_init();}
  CLxLoc_PolygonSlice(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PolygonSlice(const CLxLoc_PolygonSlice &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PolygonSlice;}
    LxResult
  SetAxis (unsigned axis)
  {
    return m_loc[0]->SetAxis (m_loc,axis);
  }
    LxResult
  SetAxisByVector (const LXtVector axis)
  {
    return m_loc[0]->SetAxisByVector (m_loc,axis);
  }
    LxResult
  Start (ILxUnknownID meshObj, LXtPolygonID pol, unsigned setAxis)
  {
    return m_loc[0]->Start (m_loc,(ILxUnknownID)meshObj,pol,setAxis);
  }
    LxResult
  ByLine (const LXtVector pos0, const LXtVector pos1)
  {
    return m_loc[0]->ByLine (m_loc,pos0,pos1);
  }
    int
  Done (void)
  {
    return m_loc[0]->Done (m_loc);
  }
};

#endif

