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
#ifndef LXUSER_predest_HPP
#define LXUSER_predest_HPP

#include <lxw_predest.hpp>


class CLxUser_ShaderPreDest : public CLxLoc_ShaderPreDest
{
        public:
        CLxUser_ShaderPreDest () {}
        CLxUser_ShaderPreDest (ILxUnknownID obj) : CLxLoc_ShaderPreDest (obj) {}



};

class CLxUser_MeshLayerPreDest : public CLxLoc_MeshLayerPreDest
{
        public:
        CLxUser_MeshLayerPreDest () {}
        CLxUser_MeshLayerPreDest (ILxUnknownID obj) : CLxLoc_MeshLayerPreDest (obj) {}



};

class CLxUser_SceneItemPreDest : public CLxLoc_SceneItemPreDest
{
        public:
        CLxUser_SceneItemPreDest () {}
        CLxUser_SceneItemPreDest (ILxUnknownID obj) : CLxLoc_SceneItemPreDest (obj) {}



};

class CLxUser_Profile1DPreDest : public CLxLoc_Profile1DPreDest
{
        public:
        CLxUser_Profile1DPreDest () {}
        CLxUser_Profile1DPreDest (ILxUnknownID obj) : CLxLoc_Profile1DPreDest (obj) {}



};

class CLxUser_Profile2DPreDest : public CLxLoc_Profile2DPreDest
{
        public:
        CLxUser_Profile2DPreDest () {}
        CLxUser_Profile2DPreDest (ILxUnknownID obj) : CLxLoc_Profile2DPreDest (obj) {}



};

class CLxUser_ColorPreDest : public CLxLoc_ColorPreDest
{
        public:
        CLxUser_ColorPreDest () {}
        CLxUser_ColorPreDest (ILxUnknownID obj) : CLxLoc_ColorPreDest (obj) {}



};

class CLxUser_PresetDestinationService : public CLxLoc_PresetDestinationService
{
        public:


};
#endif
