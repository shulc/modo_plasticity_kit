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
#ifndef LXUSER_select_HPP
#define LXUSER_select_HPP

#include <lxw_select.hpp>

        #include <vector>



class CLxUser_SelectionType : public CLxLoc_SelectionType
{
        public:
        CLxUser_SelectionType () {}
        CLxUser_SelectionType (ILxUnknownID obj) : CLxLoc_SelectionType (obj) {}

        /**
         * User methods allow the selection type wrapper to be initialized given the
         * name or type code for a selection type.
         */
                bool
        fromType (
                const char		*name)
        {
                CLxLoc_SelectionService	 svc;
                LXtObjectID		 obj;
                LxResult		 rc;
        
                rc = svc.Allocate (name, &obj);
                if (LXx_FAIL (rc))
                        return false;
        
                return take (obj);
        }
        
                bool
        fromType (
                LXtID4			 type)
        {
                CLxLoc_SelectionService	 svc;
        
                return fromType (svc.LookupName (type));
        }

};

class CLxUser_SelectionService : public CLxLoc_SelectionService
{
        public:
        /**
         * Nicer ways to get a selection type implementation in C++.
         */
                bool
        GetImplementation (
                const char		*name,
                CLxLoc_SelectionType	&sel)
        {
                LXtObjectID		  obj;
                LxResult		  rc;
        
                rc = Allocate (name, &obj);
                if (LXx_FAIL (rc))
                        return false;
        
                return sel.take (obj);
        }
        
                bool
        GetImplementation (
                LXtID4			 type,
                CLxLoc_SelectionType	&sel)
        {
                const char		*name;
        
                name = LookupName (type);
                if (!name)
                        return false;
        
                return GetImplementation (name, sel);
        }
        /**
         * User class gives a nice wrapper method for getting the array.
         */
                LxResult
        GetSubtypeList (
                LXtID4			 type,
                std::vector<unsigned>	&subTypes)
        {
                LxResult		 rc;
                unsigned		*buf;
                unsigned		 i, n;
                size_t			 len;
        
                subTypes.clear ();
                len = 128;
                while (1)
                {
                        buf = new unsigned [len];
        
                        rc = CurrentSubTypes (type, buf, static_cast<unsigned>(len), &n);
                        if (rc != LXe_SHORTBUFFER)
                                break;
        
                        delete[] buf;
                        len *= 2;
                }
        
                if (LXx_OK (rc))
                        for (i = 0; i < n; i++)
                                subTypes.push_back (buf[i]);
        
                delete[] buf;
                return rc;
        }

};
#endif
