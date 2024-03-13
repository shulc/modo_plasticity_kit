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
#ifndef LXUSER_itemui_HPP
#define LXUSER_itemui_HPP

#include <lxw_itemui.hpp>


class CLxUser_LocatorDest : public CLxLoc_LocatorDest
{
        public:
        CLxUser_LocatorDest () {}
        CLxUser_LocatorDest (ILxUnknownID obj) : CLxLoc_LocatorDest (obj) {}



};

class CLxUser_MeshOpDest : public CLxLoc_MeshOpDest
{
        public:
        CLxUser_MeshOpDest () {}
        CLxUser_MeshOpDest (ILxUnknownID obj) : CLxLoc_MeshOpDest (obj) {}



};

class CLxUser_MeshDest : public CLxLoc_MeshDest
{
        public:
        CLxUser_MeshDest () {}
        CLxUser_MeshDest (ILxUnknownID obj) : CLxLoc_MeshDest (obj) {}



};

class CLxUser_ChannelDest : public CLxLoc_ChannelDest
{
        public:
        CLxUser_ChannelDest () {}
        CLxUser_ChannelDest (ILxUnknownID obj) : CLxLoc_ChannelDest (obj) {}



};

class CLxUser_ChannelDropPreview : public CLxLoc_ChannelDropPreview
{
        public:
        CLxUser_ChannelDropPreview () {}
        CLxUser_ChannelDropPreview (ILxUnknownID obj) : CLxLoc_ChannelDropPreview (obj) {}

        /**
         * Empty ILxChannelDropPreview Python user class.
         */
        

};

class CLxUser_ItemTypeDest : public CLxLoc_ItemTypeDest
{
        public:
        CLxUser_ItemTypeDest () {}
        CLxUser_ItemTypeDest (ILxUnknownID obj) : CLxLoc_ItemTypeDest (obj) {}



};
#endif
