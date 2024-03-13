/*
 * C++ wrapper for lxprojdir.h
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
#ifndef LXW_PROJDIR_HPP
#define LXW_PROJDIR_HPP

#include <lxprojdir.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ProjDirOverride = {0x257bac48,0x5e70,0x42a3,0xb5,0xa4,0x7e,0xb3,0x3f,0xdb,0xa1,0x14};
};

class CLxImpl_ProjDirOverride {
  public:
    virtual ~CLxImpl_ProjDirOverride() {}
    virtual LxResult
      pdo_OverrideWith (const char *originalPath, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
};
#define LXxD_ProjDirOverride_OverrideWith LxResult pdo_OverrideWith (const char *originalPath, char *buf, unsigned len)
#define LXxO_ProjDirOverride_OverrideWith LXxD_ProjDirOverride_OverrideWith LXx_OVERRIDE
#define LXxC_ProjDirOverride_OverrideWith(c) LxResult c::pdo_OverrideWith (const char *originalPath, char *buf, unsigned len)
template <class T>
class CLxIfc_ProjDirOverride : public CLxInterface
{
    static LxResult
  OverrideWith (LXtObjectID wcom, const char *originalPath, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_ProjDirOverride, loc);
    try {
      return loc->pdo_OverrideWith (originalPath,buf,len);
    } catch (LxResult rc) { return rc; }
  }
  ILxProjDirOverride vt;
public:
  CLxIfc_ProjDirOverride ()
  {
    vt.OverrideWith = OverrideWith;
    vTable = &vt.iunk;
    iid = &lx::guid_ProjDirOverride;
  }
};
class CLxLoc_ProjDirOverride : public CLxLocalize<ILxProjDirOverrideID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ProjDirOverride() {_init();}
  CLxLoc_ProjDirOverride(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ProjDirOverride(const CLxLoc_ProjDirOverride &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ProjDirOverride;}
    LxResult
  OverrideWith (const char *originalPath, char *buf, unsigned len)
  {
    return m_loc[0]->OverrideWith (m_loc,originalPath,buf,len);
  }
    LxResult
  OverrideWith (const char *originalPath, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->OverrideWith (m_loc,originalPath,buf,len);
    LXWx_SBUF2
  }
};

#endif

