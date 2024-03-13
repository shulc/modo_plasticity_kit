/*
 * C++ wrapper for lxvaluehud.h
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
#ifndef LXW_VALUEHUD_HPP
#define LXW_VALUEHUD_HPP

#include <lxvaluehud.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ValueHUDService = {0x7ed5ebf7,0x578c,0x4cf6,0x98,0xe7,0x2e,0x0a,0xf5,0x3e,0x56,0xfa};
};

class CLxLoc_ValueHUDService : public CLxLocalizedService
{
public:
  ILxValueHUDServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_ValueHUDService() {_init();set();}
 ~CLxLoc_ValueHUDService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxValueHUDServiceID>(lx::GetGlobal(&lx::guid_ValueHUDService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    CLxResult
  ScriptQuery (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ScriptQuery(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetHUDCommands (const char *cookie, const char *command1, const char *command2, const char *command3, int alphaSort)
  {
    return m_loc[0]->SetHUDCommands (m_loc,cookie,command1,command2,command3,alphaSort);
  }
    LxResult
  ClearHUD (const char *cookie)
  {
    return m_loc[0]->ClearHUD (m_loc,cookie);
  }
};

#endif

