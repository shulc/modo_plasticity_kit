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
#ifndef LXUSER_draw_HPP
#define LXUSER_draw_HPP

#include <lxw_draw.hpp>


class CLxUser_View : public CLxLoc_View
{
        public:
        CLxUser_View () {}
        CLxUser_View (ILxUnknownID obj) : CLxLoc_View (obj) {}



};

class CLxUser_StrokeDraw : public CLxLoc_StrokeDraw
{
        public:
        CLxUser_StrokeDraw () {}
        CLxUser_StrokeDraw (ILxUnknownID obj) : CLxLoc_StrokeDraw (obj) {}

        void
        Vert (
                LXtVector		 pos,
                int			 flags = LXiSTROKE_ABSOLUTE)
        {
                Vertex (pos, flags);
        }
        
                void
        Vert (
                LXtFVector		 pos,
                int			 flags = LXiSTROKE_ABSOLUTE)
        {
                Vertex3 (pos[0], pos[1], pos[2], flags);
        }
        
                void
        Vert (
                double			 x,
                double			 y,
                double			 z,
                int			 flags = LXiSTROKE_ABSOLUTE)
        {
                Vertex3 (x, y, z, flags);
        }
        
                void
        Vert (
                float			 x,
                float			 y,
                float			 z,
                int			 flags = LXiSTROKE_ABSOLUTE)
        {
                Vertex3 (x, y, z, flags);
        }
        
                void
        Vert (
                double			 x,
                double			 y,
                int			 flags = LXiSTROKE_SCREEN)
        {
                Vertex3 (x, y, 0.0, flags);
        }
        
                void
        Vert (
                float			 x,
                float			 y,
                int			 flags = LXiSTROKE_SCREEN)
        {
                Vertex3 (x, y, 0.0, flags);
        }

};

class CLxUser_GLMaterial : public CLxLoc_GLMaterial
{
        public:
        CLxUser_GLMaterial () {}
        CLxUser_GLMaterial (ILxUnknownID obj) : CLxLoc_GLMaterial (obj) {}



};

class CLxUser_GLImage : public CLxLoc_GLImage
{
        public:
        CLxUser_GLImage () {}
        CLxUser_GLImage (ILxUnknownID obj) : CLxLoc_GLImage (obj) {}



};
#endif
