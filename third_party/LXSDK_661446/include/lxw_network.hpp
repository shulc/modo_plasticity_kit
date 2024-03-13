/*
 * C++ wrapper for lxnetwork.h
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
#ifndef LXW_NETWORK_HPP
#define LXW_NETWORK_HPP

#include <lxnetwork.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_NetworkService = {0x333d439d,0xcfc8,0x43e6,0xad,0x3c,0x1e,0x2b,0x6f,0xda,0x27,0xfb};
};

class CLxLoc_NetworkService : public CLxLocalizedService
{
public:
  ILxNetworkServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_NetworkService() {_init();set();}
 ~CLxLoc_NetworkService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxNetworkServiceID>(lx::GetGlobal(&lx::guid_NetworkService));}
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
  OneOffHostListAdd (const char *hostname, LXtIP4 ip, int port)
  {
    return m_loc[0]->OneOffHostListAdd (m_loc,hostname,ip,port);
  }
    LxResult
  OneOffHostListRemove (const char *hostname, LXtIP4 ip, int port)
  {
    return m_loc[0]->OneOffHostListRemove (m_loc,hostname,ip,port);
  }
};

#endif

