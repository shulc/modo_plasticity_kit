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
#ifndef LXUSER_layer_HPP
#define LXUSER_layer_HPP

#include <lxw_layer.hpp>

#include <lxw_item.hpp>
#include <lxw_mesh.hpp>
#include <lx_visitor.hpp>
#include <lx_tool.hpp>



class CLxUser_LayerScan : public CLxLoc_LayerScan
{
        public:
        CLxUser_LayerScan () {}
        CLxUser_LayerScan (ILxUnknownID obj) : CLxLoc_LayerScan (obj) {}

        /**
         * User class methods just make nicer wrappers for the raw COM methods.
         */
                unsigned
        NumLayers ()
        {
                unsigned		 n;
        
                if (LXx_OK (Count (&n)))
                        return n;
        
                return 0;
        }
        
                bool
        ItemByIndex (
                unsigned int		 index,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (MeshItem (index, &obj)))
                        return false;
        
                return item.take (obj);
        }
        
                bool
        BaseMeshByIndex (
                unsigned int		 index,
                CLxLoc_Mesh		&mesh)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (MeshBase (index, &obj)))
                        return false;
        
                return mesh.take (obj);
        }
        
                bool
        EditMeshByIndex (
                unsigned int		 index,
                CLxLoc_Mesh		&mesh)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (MeshEdit (index, &obj)))
                        return false;
        
                return mesh.take (obj);
        }

};

class CLxUser_TransformScan : public CLxLoc_TransformScan
{
        public:
        CLxUser_TransformScan () {}
        CLxUser_TransformScan (ILxUnknownID obj) : CLxLoc_TransformScan (obj) {}

        /**
         * The user class method allows easier access to the enumeration method.
         */
                LxResult
        Enum (
                CLxImpl_AbstractVisitor	*visitor)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>	gv;
        
                gv.loc.vis = visitor;
                return Enumerate (gv);
        }

};

class CLxUser_LayerService : public CLxLoc_LayerService
{
        public:
        /**
         * - ScanAllocate()
         * Initialize and return a layer scan object.
         */
                bool
        BeginScan (
                unsigned int		 flags,
                CLxLoc_LayerScan	&scan)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ScanAllocate (flags, &obj)))
                        return false;
        
                return scan.take (obj);
        }
        bool
        BeginXfrm (
                ILxUnknownID		 toolVec,
                CLxLoc_TransformScan	&xfrm)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (XfrmAllocate (toolVec, &obj)))
                        return false;
        
                return xfrm.take (obj);
        }

};
#endif
