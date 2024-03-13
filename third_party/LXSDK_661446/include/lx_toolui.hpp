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
#ifndef LXUSER_toolui_HPP
#define LXUSER_toolui_HPP

#include <lxw_toolui.hpp>
/*
 * NOTE; lxpredest not strictly needed here, but some of the packets are not useful
 * unless it's included. So this gets it into the SDK even though we have no samples.
 */

#include <lx_predest.hpp>



class CLxUser_RaycastPacket : public CLxLoc_RaycastPacket
{
        public:
        CLxUser_RaycastPacket () {}
        CLxUser_RaycastPacket (ILxUnknownID obj) : CLxLoc_RaycastPacket (obj) {}



};

class CLxUser_PaintBrushPacket : public CLxLoc_PaintBrushPacket
{
        public:
        CLxUser_PaintBrushPacket () {}
        CLxUser_PaintBrushPacket (ILxUnknownID obj) : CLxLoc_PaintBrushPacket (obj) {}



};

class CLxUser_PaintInkPacket : public CLxLoc_PaintInkPacket
{
        public:
        CLxUser_PaintInkPacket () {}
        CLxUser_PaintInkPacket (ILxUnknownID obj) : CLxLoc_PaintInkPacket (obj) {}



};

class CLxUser_PaintNozzlePacket : public CLxLoc_PaintNozzlePacket
{
        public:
        CLxUser_PaintNozzlePacket () {}
        CLxUser_PaintNozzlePacket (ILxUnknownID obj) : CLxLoc_PaintNozzlePacket (obj) {}



};
#endif
