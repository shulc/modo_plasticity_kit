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
#ifndef LXUSER_color_HPP
#define LXUSER_color_HPP

#include <lxw_color.hpp>


class CLxUser_ColorModel : public CLxLoc_ColorModel
{
        public:
        CLxUser_ColorModel () {}
        CLxUser_ColorModel (ILxUnknownID obj) : CLxLoc_ColorModel (obj) {}

        /**
         * The server is assumed to have a message table in the form of "colormodel.<serverName>", where
         * "<serverName>" is the name of the server.  It is expected to have the following messages:
         * - Model
         * The username of the color model itself.  Just a simple string like "RGB", "HSV", "CMYK",
         * "Color Temperature", etc.
         * - Component1Short
         * - Component2Short
         * - Component3Short
         * - Component4Short
         * The short label for the individual components.  These are usually single
         * characters, such as 'R', 'G', 'B', etc.  These may be concatenated by the
         * color picker to create longer strings, like "RGB", so keep them short and
         * standard.
         * - Component1Long
         * - Component2Long
         * - Component3Long
         * - Component4Long
         * The long name for the individual components.  These are usually full words,
         * like "Red", "Green" and "Blue", and are commonly used as the labels for the
         * controls in forms.
         * We don't have any user functions; we just use this to force qmake to create
         * the appropriate files.
         */
        

};

class CLxUser_Color : public CLxLoc_Color
{
        public:
        CLxUser_Color () {}
        CLxUser_Color (ILxUnknownID obj) : CLxLoc_Color (obj) {}



};
#endif
