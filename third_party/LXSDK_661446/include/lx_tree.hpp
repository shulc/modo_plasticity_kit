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
#ifndef LXUSER_tree_HPP
#define LXUSER_tree_HPP

#include <lxw_tree.hpp>


class CLxUser_Tree : public CLxLoc_Tree
{
        public:
        CLxUser_Tree () {}
        CLxUser_Tree (ILxUnknownID obj) : CLxLoc_Tree (obj) {}

        bool
        Clone (
                unsigned		 mode,
                CLxUser_Tree		&tree)
        {
                LXtObjectID		obj;
        
                return (LXx_OK (Spawn (mode, &obj)) && tree.take (obj));
        }

};

class CLxUser_TreeListener : public CLxLoc_TreeListener
{
        public:
        CLxUser_TreeListener () {}
        CLxUser_TreeListener (ILxUnknownID obj) : CLxLoc_TreeListener (obj) {}

        /**
         * Empty TreeListener user classed.
         */
        

};
#endif
