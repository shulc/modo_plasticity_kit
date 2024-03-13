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
#ifndef LXUSER_persist_HPP
#define LXUSER_persist_HPP

#include <lxw_persist.hpp>

#include <lx_visitor.hpp>
        #include <string>



class CLxUser_PersistentEntry : public CLxLoc_PersistentEntry
{
        public:
        CLxUser_PersistentEntry () {}
        CLxUser_PersistentEntry (ILxUnknownID obj) : CLxLoc_PersistentEntry (obj) {}

        /**
         * Easier way to get the entry count, with -1 for errors.
         */
                int
        Number ()
        {
                unsigned int		 n;
        
                if (LXx_OK (Count (&n)))
                        return n;
        
                return -1;
        }
        /**
         * Standard string lookup.
         */
                LxResult
        Lookup (const std::string &key)
        {
                return CLxLoc_PersistentEntry::Lookup (key.c_str ());
        }
        /**
         * Standard string insertion.
         */
                LxResult
        Insert (const std::string &key)
        {
                return CLxLoc_PersistentEntry::Insert (key.c_str ());
        }

};

class CLxUser_PersistenceService : public CLxLoc_PersistenceService
{
        public:
        /**
         * This user method on the service takes a C++ visitor object and wraps it for COM.
         */
                LxResult
        ConfigureVis (
                const char		*name,
                CLxImpl_AbstractVisitor	*visitor)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return Configure (name, gv);
        }
        /**
         * Alternate version of the End() method to get the persistent entry in more C++
         * friendly terms.
         */
                bool
        EndDef (
                CLxLoc_PersistentEntry	&entry)
        {
                LXtObjectID		 obj;
        
                entry.clear ();
                if (LXx_FAIL (End (&obj)))
                        return false;
        
                return entry.take (obj);
        }

};
#endif
