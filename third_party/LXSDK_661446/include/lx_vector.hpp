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
#ifndef LXUSER_vector_HPP
#define LXUSER_vector_HPP

#include <lxw_vector.hpp>


class CLxUser_VectorType : public CLxLoc_VectorType
{
        public:
        CLxUser_VectorType () {}
        CLxUser_VectorType (ILxUnknownID obj) : CLxLoc_VectorType (obj) {}



};

class CLxUser_VectorList : public CLxLoc_VectorList
{
        public:
        CLxUser_VectorList () {}
        CLxUser_VectorList (ILxUnknownID obj) : CLxLoc_VectorList (obj) {}

        // QWEB_MACRO_BEGIN - SDK Common user: Vector methods
                void *
        Read (
                unsigned int		 offset)
        {
                void			*pkt;
        
                if (LXx_FAIL (Readable (offset, &pkt)))
                        return 0;
        
                return pkt;
        }
        
                void *
        Write (
                unsigned int		 offset)
        {
                void			*pkt;
        
                if (LXx_FAIL (Writable (offset, &pkt)))
                        return 0;
        
                return pkt;
        }
        
                bool
        ReadObject (
                unsigned int		 offset,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
        
                loc.clear ();
                if (LXx_FAIL (Readable (offset, &obj)))
                        return false;
        
                return loc.set (obj);
        }
        
                bool
        WriteObject (
                unsigned int		 offset,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
        
                loc.clear ();
                if (LXx_FAIL (Writable (offset, &obj)))
                        return false;
        
                return loc.set (obj);
        }
                // QWEB_MACRO_END - SDK Common user: Vector methods

};

class CLxUser_VectorStack : public CLxLoc_VectorStack
{
        public:
        CLxUser_VectorStack () {}
        CLxUser_VectorStack (ILxUnknownID obj) : CLxLoc_VectorStack (obj) {}

        // QWEB_MACRO_BEGIN - SDK Common user: Vector methods
                void *
        Read (
                unsigned int		 offset)
        {
                void			*pkt;
        
                if (LXx_FAIL (Readable (offset, &pkt)))
                        return 0;
        
                return pkt;
        }
        
                void *
        Write (
                unsigned int		 offset)
        {
                void			*pkt;
        
                if (LXx_FAIL (Writable (offset, &pkt)))
                        return 0;
        
                return pkt;
        }
        
                bool
        ReadObject (
                unsigned int		 offset,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
        
                loc.clear ();
                if (LXx_FAIL (Readable (offset, &obj)))
                        return false;
        
                return loc.set (obj);
        }
        
                bool
        WriteObject (
                unsigned int		 offset,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
        
                loc.clear ();
                if (LXx_FAIL (Writable (offset, &obj)))
                        return false;
        
                return loc.set (obj);
        }
                // QWEB_MACRO_END - SDK Common user: Vector methods

};

class CLxUser_PacketService : public CLxLoc_PacketService
{
        public:
        unsigned
        GetOffset (
                const char		*category,
                const char		*name)
        {
                unsigned		 offset;
        
                if (LXx_OK (Lookup (category, name, &offset)))
                        return offset;
        
                return ~0;
        }
        
                bool
        PacketObject (
                ILxUnknownID		 vector,
                unsigned int		 offset,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
        
                obj = FastPacket (vector, offset);
                if (!obj)
                        return false;
        
                return loc.set (obj);
        }
        
                bool
        NewVectorType (
                const char		*category,
                CLxLoc_VectorType	&vtype)
        {
                LXtObjectID		 obj;
        
                vtype.clear ();
                if (LXx_FAIL (CreateVectorType (category, &obj)))
                        return false;
        
                return vtype.take (obj);
        }

};
#endif
