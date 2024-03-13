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
#ifndef LXUSER_surface_HPP
#define LXUSER_surface_HPP

#include <lxw_surface.hpp>


class CLxUser_SurfaceItem : public CLxLoc_SurfaceItem
{
        public:
        CLxUser_SurfaceItem () {}
        CLxUser_SurfaceItem (ILxUnknownID obj) : CLxLoc_SurfaceItem (obj) {}

        bool
        AllocSurf (
                ILxUnknownID		 chanRead,
                bool			 morph,
                CLxLoc_Surface		&surf)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (GetSurface (chanRead, morph ? 1 : 0, &obj)))
                        return false;
        
                return surf.take (obj);
        }
        
                bool
        AllocSurf (
                ILxUnknownID		 attr,
                unsigned		 index,
                CLxLoc_Surface		&surf)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Evaluate (attr, index, &obj)))
                        return false;
        
                return surf.take (obj);
        }

};

class CLxUser_Surface : public CLxLoc_Surface
{
        public:
        CLxUser_Surface () {}
        CLxUser_Surface (ILxUnknownID obj) : CLxLoc_Surface (obj) {}

        bool
        GetBin (
                unsigned		 index,
                CLxLoc_SurfaceBin	&bin)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (BinByIndex (index, &obj)))
                        return false;
        
                return bin.take (obj);
        }

};

class CLxUser_SurfaceBin : public CLxLoc_SurfaceBin
{
        public:
        CLxUser_SurfaceBin () {}
        CLxUser_SurfaceBin (ILxUnknownID obj) : CLxLoc_SurfaceBin (obj) {}



};

class CLxUser_CurveGroup : public CLxLoc_CurveGroup
{
        public:
        CLxUser_CurveGroup () {}
        CLxUser_CurveGroup (ILxUnknownID obj) : CLxLoc_CurveGroup (obj) {}



};

class CLxUser_Curve : public CLxLoc_Curve
{
        public:
        CLxUser_Curve () {}
        CLxUser_Curve (ILxUnknownID obj) : CLxLoc_Curve (obj) {}



};
#endif
