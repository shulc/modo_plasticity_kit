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
#ifndef LXUSER_schematic_HPP
#define LXUSER_schematic_HPP

#include <lxw_schematic.hpp>

#include <lxw_item.hpp>



class CLxUser_SchematicConnection : public CLxLoc_SchematicConnection
{
        public:
        CLxUser_SchematicConnection () {}
        CLxUser_SchematicConnection (ILxUnknownID obj) : CLxLoc_SchematicConnection (obj) {}



};

class CLxUser_SchemaDest : public CLxLoc_SchemaDest
{
        public:
        CLxUser_SchemaDest () {}
        CLxUser_SchemaDest (ILxUnknownID obj) : CLxLoc_SchemaDest (obj) {}

        bool
        GetGroup (
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Item (&obj)))
                        return false;
        
                return item.take (obj);
        }
        
                bool
        GetItem (
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Item (&obj)))
                        return false;
        
                return item.take (obj);
        }

};

class CLxUser_SchematicGroup : public CLxLoc_SchematicGroup
{
        public:
        CLxUser_SchematicGroup () {}
        CLxUser_SchematicGroup (ILxUnknownID obj) : CLxLoc_SchematicGroup (obj) {}

        unsigned int
        NNodes ()
        {
                unsigned int		 count = 0;
        
                if (LXx_OK (NodeCount (&count)))
                        return count;
        
                return 0;
        }

};

class CLxUser_SchematicNode : public CLxLoc_SchematicNode
{
        public:
        CLxUser_SchematicNode () {}
        CLxUser_SchematicNode (ILxUnknownID obj) : CLxLoc_SchematicNode (obj) {}

        unsigned int
        NSubNodes ()
        {
                unsigned int		 count = 0;
        
                if (LXx_OK (SubNodeCount (&count)))
                        return count;
        
                return 0;
        }

};
#endif
