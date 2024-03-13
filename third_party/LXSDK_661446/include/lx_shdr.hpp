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
#ifndef LXUSER_shdr_HPP
#define LXUSER_shdr_HPP

#include <lxw_shdr.hpp>

#include <lx_visitor.hpp>



class CLxUser_Shader : public CLxLoc_Shader
{
        public:
        CLxUser_Shader () {}
        CLxUser_Shader (ILxUnknownID obj) : CLxLoc_Shader (obj) {}

CLxUser_Shader (
                CLxLoc_Item		meshItem,
                LXtPolygonID		poly = NULL)
        {
                CLxLoc_ShaderService	 shdrSrv;
                LXtObjectID		 acc;
                LxResult		 resultCode;
        
                _init ();
                clear ();
        
                if (poly != NULL)
                        resultCode = shdrSrv.PolyShaderAccessor (meshItem, poly, &acc);
                else
                        resultCode = shdrSrv.MeshShaderAccessor (meshItem, &acc);
        
                if (LXx_OK (resultCode)) {
                        take (acc);
                }
        }
        
                LxResult
        Enum (
                CLxImpl_AbstractVisitor	*visitor)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return Enumerate (gv);
        }
        
                bool
        duplicate (
                CLxLoc_Shader		&acc)
        {
                LXtObjectID		 obj;
        
                acc.clear ();
                if (LXx_FAIL (Spawn (&obj)))
                        return false;
        
                return acc.take (obj);
        }
        bool
        GetShaderItem (
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ShaderItemGet (&obj)))
                        return false;
        
                return item.take (obj);
        }

};

class CLxUser_ShaderService : public CLxLoc_ShaderService
{
        public:
        bool
        GetMeshShaders (
                CLxLoc_Item		&meshItem,
                CLxLoc_Shader		&acc)
        {
                LXtObjectID		 obj;
        
                acc.clear ();
                if (LXx_FAIL (MeshShaderAccessor (meshItem, &obj)))
                        return false;
        
                return acc.take (obj);
        }
        
                bool
        GetPolyShaders (
                CLxLoc_Item		&meshItem,
                LXtPolygonID		 polyID,
                CLxLoc_Shader		&acc)
        {
                LXtObjectID		 obj;
        
                acc.clear ();
                if (LXx_FAIL (PolyShaderAccessor (meshItem, polyID, &obj)))
                        return false;
        
                return acc.take (obj);
        }

};
#endif
