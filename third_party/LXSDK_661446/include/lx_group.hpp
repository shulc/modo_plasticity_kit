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
#ifndef LXUSER_group_HPP
#define LXUSER_group_HPP

#include <lxw_group.hpp>

#include <lx_visitor.hpp>



class CLxUser_GroupItem : public CLxLoc_GroupItem
{
        public:
        CLxUser_GroupItem () {}
        CLxUser_GroupItem (ILxUnknownID obj) : CLxLoc_GroupItem (obj) {}

        bool
        GetEnumerator (
                CLxLoc_GroupEnumerator	&grpEnum)
        {
                LXtObjectID		 obj;
        
                if (LXx_OK (Enumerator (&obj)))
                        return grpEnum.take (obj);
        
                grpEnum.clear ();
                return false;
        }
        
                int
        GetType ()
        {
                int type;
                if (LXx_OK(Type(&type)))
                {
                        return type;
                }
        
                return LXi_GROUP_TYPE_STANDARD;
        }
        
                bool
        SetType (
                int type)
        {
                if (LXx_OK(CLxLoc_GroupItem::SetType(type)))
                        return true;
        
                return false;
        }

};

class CLxUser_GroupEnumerator : public CLxLoc_GroupEnumerator
{
        public:
        CLxUser_GroupEnumerator () {}
        CLxUser_GroupEnumerator (ILxUnknownID obj) : CLxLoc_GroupEnumerator (obj) {}

        LxResult
        Enum (
                CLxImpl_AbstractVisitor	*visitor,
                unsigned		 mask = LXfGRPTYPE_BOTH)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return Enumerate (gv, mask);
        }
        
                bool
        GetItem (
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_OK (Item (&obj)))
                        return item.take (obj);
        
                item.clear ();
                return false;
        }

};
#endif
