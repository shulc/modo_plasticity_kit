/*
 * Plug-in SDK Header: C++ User Classes
 *
 * Copyright (c) 2008-2022 The Foundry Group LLC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.   Except as contained
 * in this notice, the name(s) of the above copyright holders shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef LXUSER_server_HPP
#define LXUSER_server_HPP

#include <lxw_server.hpp>


class CLxUser_Factory : public CLxLoc_Factory
{
        public:
        CLxUser_Factory () {}
        CLxUser_Factory (ILxUnknownID obj) : CLxLoc_Factory (obj) {}

        bool
        New (
                CLxLocalizedObject	&loc)
        {
                return Spawn (loc);
        }

};

class CLxUser_HostService : public CLxLoc_HostService
{
        public:
        /**
         * The C++ service has methods to get a factory directly into a user object.
         */
                bool
        Lookup (
                CLxLoc_Factory		&fac,
                const char		*className,
                const char		*name,
                bool			 allowLoad = true)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (LookupServer (className, name, allowLoad, &obj)))
                        return false;
        
                return fac.take (obj);
        }
        
                bool
        ByIndex (
                CLxLoc_Factory		&fac,
                const char		*className,
                unsigned int		 index)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ServerByIndex (className, index, &obj)))
                        return false;
        
                return fac.take (obj);
        }

};
#endif
