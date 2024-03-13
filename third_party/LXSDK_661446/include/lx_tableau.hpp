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
#ifndef LXUSER_tableau_HPP
#define LXUSER_tableau_HPP

#include <lxw_tableau.hpp>

#include <lxw_vertex.hpp>
#include <lxw_action.hpp>
#include <lx_visitor.hpp>



class CLxUser_Tableau : public CLxLoc_Tableau
{
        public:
        CLxUser_Tableau () {}
        CLxUser_Tableau (ILxUnknownID obj) : CLxLoc_Tableau (obj) {}

        float
        Time0 (void)
        {
                float			 t0, dt;
        
                Time (&t0, &dt);
                return t0;
        }
        
                float
        Time1 (void)
        {
                float			 t0, dt;
        
                Time (&t0, &dt);
                return t0 + dt;
        }
        
                bool
        IsVisible (
                ILxUnknownID		 item)
        {
                return (Visible (item) == LXe_TRUE) ? true : false;
        }
        
                bool
        GetShader (
                CLxLoc_TableauShader	&shader,
                ILxUnknownID		 item,
                ILxUnknownID		 tags)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (FindShader (item, tags, &obj)))
                        return false;
        
                return shader.take (obj);
        }
        
                bool
        GetChannels (
                CLxLoc_ChannelRead	&chan,
                unsigned		 type)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Channels (type, &obj)))
                        return false;
        
                return chan.take (obj);
        }
        
                LxResult
        VisitorUpdate (
                CLxImpl_AbstractVisitor		*visitor,
                int				 immediate)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
        
                return Update (gv, immediate);
        }

};

class CLxUser_TableauElement : public CLxLoc_TableauElement
{
        public:
        CLxUser_TableauElement () {}
        CLxUser_TableauElement (ILxUnknownID obj) : CLxLoc_TableauElement (obj) {}



};

class CLxUser_TableauSurface : public CLxLoc_TableauSurface
{
        public:
        CLxUser_TableauSurface () {}
        CLxUser_TableauSurface (ILxUnknownID obj) : CLxLoc_TableauSurface (obj) {}



};

class CLxUser_TriangleSoup : public CLxLoc_TriangleSoup
{
        public:
        CLxUser_TriangleSoup () {}
        CLxUser_TriangleSoup (ILxUnknownID obj) : CLxLoc_TriangleSoup (obj) {}

        /**
         * The user method allows quads to be created with connectivity.
         */
                LxResult
        Quad (
                unsigned int		 v0,
                unsigned int		 v1,
                unsigned int		 v2,
                unsigned int		 v3)
        {
                LxResult		 rc;
        
                rc = Polygon (v0, v1, v2);
                if (LXx_FAIL (rc))
                        return rc;
        
                Connect (LXiTBLX_CONNECT_QUAD);
                return Polygon (v0, v2, v3);
        }

};

class CLxUser_TableauInstance : public CLxLoc_TableauInstance
{
        public:
        CLxUser_TableauInstance () {}
        CLxUser_TableauInstance (ILxUnknownID obj) : CLxLoc_TableauInstance (obj) {}



};

class CLxUser_TableauShader : public CLxLoc_TableauShader
{
        public:
        CLxUser_TableauShader () {}
        CLxUser_TableauShader (ILxUnknownID obj) : CLxLoc_TableauShader (obj) {}

        bool
        GetSlice (
                CLxLoc_ShaderSlice	&slice,
                ILxUnknownID		 vtOutput,
                ILxUnknownID		 tvDesc)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Slice (vtOutput, tvDesc, &obj)))
                        return false;
        
                return slice.take (obj);
        }

};

class CLxUser_TableauService : public CLxLoc_TableauService
{
        public:
        bool
        NewVertex (
                CLxLoc_TableauVertex	&vert)
        {
                LXtObjectID		 obj;
        
                vert.clear ();
                if (LXx_FAIL (AllocVertex (&obj)))
                        return false;
        
                return vert.take (obj);
        }

};

class CLxUser_NodalService : public CLxLoc_NodalService
{
        public:


};
#endif
