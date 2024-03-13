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
#ifndef LXUSER_mesh_HPP
#define LXUSER_mesh_HPP

#include <lxw_mesh.hpp>

#include <lx_visitor.hpp>
#include <lx_pvedit.hpp>
#include <lx_item.hpp>



class CLxUser_Mesh : public CLxLoc_Mesh
{
        public:
        CLxUser_Mesh () {}
        CLxUser_Mesh (ILxUnknownID obj) : CLxLoc_Mesh (obj) {}

        /**
         * User class variants gets the counts directly, with minimal checking.
         */
                int
        NPoints () const
        {
                unsigned	 count;
        
                if (LXx_OK (PointCount (&count)))
                        return count;
                return -1;
        }
        
                int
        NPolygons () const
        {
                unsigned	 count;
        
                if (LXx_OK (PolygonCount (&count)))
                        return count;
                return -1;
        }
        
                int
        NEdges () const
        {
                unsigned	 count;
        
                if (LXx_OK (EdgeCount (&count)))
                        return count;
                return -1;
        }
        
                int
        NMaps () const
        {
                unsigned	 count;
        
                if (LXx_OK (MapCount (&count)))
                        return count;
                return -1;
        }
        /**
         * User class methods allocate directly into the user classes for the accessors.
         */
                bool
        GetPoints (
                CLxLoc_Point		&acc)
        {
                return PointAccessor (acc);
        }
        
                bool
        GetPolygons (
                CLxLoc_Polygon		&acc)
        {
                return PolygonAccessor (acc);
        }
        
                bool
        GetEdges (
                CLxLoc_Edge		&acc)
        {
                return EdgeAccessor (acc);
        }
        
                bool
        GetMaps (
                CLxLoc_MeshMap		&acc)
        {
                return MeshMapAccessor (acc);
        }
        bool
        IsSame (
                ILxUnknownID		 other)
        {
                return (TestSameMesh (other) == LXe_TRUE);
        }

};

class CLxUser_Point : public CLxLoc_Point
{
        public:
        CLxUser_Point () {}
        CLxUser_Point (ILxUnknownID obj) : CLxLoc_Point (obj) {}

        // QWEB_MACRO_BEGIN - Common $$ User Methods
        CLxUser_Point (
                CLxLoc_Mesh		&mesh)
        {
                _init ();
                fromMesh (mesh);
        }
        
                bool
        fromMesh (
                CLxLoc_Mesh		&mesh)
        {
                LXtObjectID		 acc;
        
                clear ();
                if (mesh.test () && LXx_OK (mesh.PointAccessor (&acc)))
                        return take (acc);
        
                return false;
        }
        
                bool
        fromMeshObj (
                ILxUnknownID		 obj)
        {
                CLxLoc_Mesh		 mesh (obj);
                LXtObjectID		 acc;
        
                clear ();
                if (mesh.test () && LXx_OK (mesh.PointAccessor (&acc)))
                        return take (acc);
        
                return false;
        }
        
                bool
        duplicate (
                CLxLoc_Point		&acc)
        {
                LXtObjectID		 obj;
        
                acc.clear ();
                if (LXx_FAIL (Spawn (&obj)))
                        return false;
        
                return acc.take (obj);
        }
                // QWEB_MACRO_END - Common $$ User Methods
                // QWEB_MACRO_BEGIN - Common Marking User Methods
                bool
        Test (
                LXtMarkMode		 mode)
        {
                return (TestMarks (mode) == LXe_TRUE);
        }
                // QWEB_MACRO_END - Common Marking User Methods
                // QWEB_MACRO_BEGIN - Common Enumerator User Methods
                LxResult
        Enum (
                CLxImpl_AbstractVisitor	*visitor,
                LXtMarkMode		 mode = LXiMARK_ANY,
                ILxUnknownID		 mon  = 0)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return Enumerate (mode, gv, mon);
        }
                // QWEB_MACRO_END - Common Enumerator User Methods

};

class CLxUser_Polygon : public CLxLoc_Polygon
{
        public:
        CLxUser_Polygon () {}
        CLxUser_Polygon (ILxUnknownID obj) : CLxLoc_Polygon (obj) {}

        // QWEB_MACRO_BEGIN - Common $$ User Methods
        CLxUser_Polygon (
                CLxLoc_Mesh		&mesh)
        {
                _init ();
                fromMesh (mesh);
        }
        
                bool
        fromMesh (
                CLxLoc_Mesh		&mesh)
        {
                LXtObjectID		 acc;
        
                clear ();
                if (mesh.test () && LXx_OK (mesh.PolygonAccessor (&acc)))
                        return take (acc);
        
                return false;
        }
        
                bool
        fromMeshObj (
                ILxUnknownID		 obj)
        {
                CLxLoc_Mesh		 mesh (obj);
                LXtObjectID		 acc;
        
                clear ();
                if (mesh.test () && LXx_OK (mesh.PolygonAccessor (&acc)))
                        return take (acc);
        
                return false;
        }
        
                bool
        duplicate (
                CLxLoc_Polygon		&acc)
        {
                LXtObjectID		 obj;
        
                acc.clear ();
                if (LXx_FAIL (Spawn (&obj)))
                        return false;
        
                return acc.take (obj);
        }
                // QWEB_MACRO_END - Common $$ User Methods
                // QWEB_MACRO_BEGIN - Common Marking User Methods
                bool
        Test (
                LXtMarkMode		 mode)
        {
                return (TestMarks (mode) == LXe_TRUE);
        }
                // QWEB_MACRO_END - Common Marking User Methods
                // QWEB_MACRO_BEGIN - Common Enumerator User Methods
                LxResult
        Enum (
                CLxImpl_AbstractVisitor	*visitor,
                LXtMarkMode		 mode = LXiMARK_ANY,
                ILxUnknownID		 mon  = 0)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return Enumerate (mode, gv, mon);
        }
                // QWEB_MACRO_END - Common Enumerator User Methods

};

class CLxUser_Edge : public CLxLoc_Edge
{
        public:
        CLxUser_Edge () {}
        CLxUser_Edge (ILxUnknownID obj) : CLxLoc_Edge (obj) {}

        // QWEB_MACRO_BEGIN - Common $$ User Methods
        CLxUser_Edge (
                CLxLoc_Mesh		&mesh)
        {
                _init ();
                fromMesh (mesh);
        }
        
                bool
        fromMesh (
                CLxLoc_Mesh		&mesh)
        {
                LXtObjectID		 acc;
        
                clear ();
                if (mesh.test () && LXx_OK (mesh.EdgeAccessor (&acc)))
                        return take (acc);
        
                return false;
        }
        
                bool
        fromMeshObj (
                ILxUnknownID		 obj)
        {
                CLxLoc_Mesh		 mesh (obj);
                LXtObjectID		 acc;
        
                clear ();
                if (mesh.test () && LXx_OK (mesh.EdgeAccessor (&acc)))
                        return take (acc);
        
                return false;
        }
        
                bool
        duplicate (
                CLxLoc_Edge		&acc)
        {
                LXtObjectID		 obj;
        
                acc.clear ();
                if (LXx_FAIL (Spawn (&obj)))
                        return false;
        
                return acc.take (obj);
        }
                // QWEB_MACRO_END - Common $$ User Methods
                // QWEB_MACRO_BEGIN - Common Marking User Methods
                bool
        Test (
                LXtMarkMode		 mode)
        {
                return (TestMarks (mode) == LXe_TRUE);
        }
                // QWEB_MACRO_END - Common Marking User Methods
                // QWEB_MACRO_BEGIN - Common Enumerator User Methods
                LxResult
        Enum (
                CLxImpl_AbstractVisitor	*visitor,
                LXtMarkMode		 mode = LXiMARK_ANY,
                ILxUnknownID		 mon  = 0)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return Enumerate (mode, gv, mon);
        }
                // QWEB_MACRO_END - Common Enumerator User Methods

};

class CLxUser_MeshMap : public CLxLoc_MeshMap
{
        public:
        CLxUser_MeshMap () {}
        CLxUser_MeshMap (ILxUnknownID obj) : CLxLoc_MeshMap (obj) {}

        // QWEB_MACRO_BEGIN - Common $$ User Methods
        CLxUser_MeshMap (
                CLxLoc_Mesh		&mesh)
        {
                _init ();
                fromMesh (mesh);
        }
        
                bool
        fromMesh (
                CLxLoc_Mesh		&mesh)
        {
                LXtObjectID		 acc;
        
                clear ();
                if (mesh.test () && LXx_OK (mesh.MeshMapAccessor (&acc)))
                        return take (acc);
        
                return false;
        }
        
                bool
        fromMeshObj (
                ILxUnknownID		 obj)
        {
                CLxLoc_Mesh		 mesh (obj);
                LXtObjectID		 acc;
        
                clear ();
                if (mesh.test () && LXx_OK (mesh.MeshMapAccessor (&acc)))
                        return take (acc);
        
                return false;
        }
        
                bool
        duplicate (
                CLxLoc_MeshMap		&acc)
        {
                LXtObjectID		 obj;
        
                acc.clear ();
                if (LXx_FAIL (Spawn (&obj)))
                        return false;
        
                return acc.take (obj);
        }
                // QWEB_MACRO_END - Common $$ User Methods
                // QWEB_MACRO_BEGIN - Common Enumerator User Methods
                LxResult
        Enum (
                CLxImpl_AbstractVisitor	*visitor,
                LXtMarkMode		 mode = LXiMARK_ANY,
                ILxUnknownID		 mon  = 0)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return Enumerate (mode, gv, mon);
        }
                // QWEB_MACRO_END - Common Enumerator User Methods
        /**
         * User methods all have the same name but different arguments. They also wrap
         * the native C++ visitor in a layer of chocolatey COM goodness.
         */
                LxResult
        EnumContents (
                CLxImpl_AbstractVisitor	*visitor,
                CLxLoc_Point		&point)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return EnumerateContinuous (gv, point);
        }
        
                LxResult
        EnumContents (
                CLxImpl_AbstractVisitor	*visitor,
                CLxLoc_Point		&point,
                CLxLoc_Polygon		&poly)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return EnumerateDiscontinuous (gv, point, poly);
        }
        
                LxResult
        EnumContents (
                CLxImpl_AbstractVisitor	*visitor,
                CLxLoc_Edge		&edge)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return EnumerateEdges (gv, edge);
        }

};

class CLxUser_MeshTracker : public CLxLoc_MeshTracker
{
        public:
        CLxUser_MeshTracker () {}
        CLxUser_MeshTracker (ILxUnknownID obj) : CLxLoc_MeshTracker (obj) {}

        LxResult
        EnumPoints (
                unsigned int		 change,
                CLxImpl_AbstractVisitor	*visitor,
                CLxLoc_Point		&point)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
                
                gv.loc.vis = visitor;
        
                return EnumeratePoints (change, gv, point);
        }
        
                LxResult
        EnumPolygons (
                unsigned int		 change,
                CLxImpl_AbstractVisitor	*visitor,
                CLxLoc_Polygon		&poly)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
                
                gv.loc.vis = visitor;
        
                return EnumeratePolygons (change, gv, poly);
        }

};

class CLxUser_MeshOperation : public CLxLoc_MeshOperation
{
        public:
        CLxUser_MeshOperation () {}
        CLxUser_MeshOperation (ILxUnknownID obj) : CLxLoc_MeshOperation (obj) {}



};

class CLxUser_MeshFilter : public CLxLoc_MeshFilter
{
        public:
        CLxUser_MeshFilter () {}
        CLxUser_MeshFilter (ILxUnknownID obj) : CLxLoc_MeshFilter (obj) {}

        bool
        GetMesh (
                CLxLoc_Mesh		&mesh)
        {
                return Generate (mesh);
        }

};

class CLxUser_MeshFilterBBox : public CLxLoc_MeshFilterBBox
{
        public:
        CLxUser_MeshFilterBBox () {}
        CLxUser_MeshFilterBBox (ILxUnknownID obj) : CLxLoc_MeshFilterBBox (obj) {}



};

class CLxUser_MeshFilterIdent : public CLxLoc_MeshFilterIdent
{
        public:
        CLxUser_MeshFilterIdent () {}
        CLxUser_MeshFilterIdent (ILxUnknownID obj) : CLxLoc_MeshFilterIdent (obj) {}

        bool
        GetMesh (
                std::string		 ident,
                CLxLoc_Mesh		&mesh)
        {
                if (ident.length () > 0)
                        return Generate (ident.c_str (), mesh);
                
                return false;
        }

};

class CLxUser_MeshFilterBlend : public CLxLoc_MeshFilterBlend
{
        public:
        CLxUser_MeshFilterBlend () {}
        CLxUser_MeshFilterBlend (ILxUnknownID obj) : CLxLoc_MeshFilterBlend (obj) {}



};

class CLxUser_MeshBlend : public CLxLoc_MeshBlend
{
        public:
        CLxUser_MeshBlend () {}
        CLxUser_MeshBlend (ILxUnknownID obj) : CLxLoc_MeshBlend (obj) {}



};

class CLxUser_MeshXtraData : public CLxLoc_MeshXtraData
{
        public:
        CLxUser_MeshXtraData () {}
        CLxUser_MeshXtraData (ILxUnknownID obj) : CLxLoc_MeshXtraData (obj) {}



};

class CLxUser_MeshService : public CLxLoc_MeshService
{
        public:
        /**
         * The user class has a couple of methods to get modes that just set and clear.
         */
                LXtMarkMode
        SetMode (
                const char		*set)
        {
                LXtMarkMode		 mode;
        
                ModeCompose (set, 0, &mode);
                return mode;
        }
        
                LXtMarkMode
        ClearMode (
                const char		*clr)
        {
                LXtMarkMode		 mode;
        
                ModeCompose (0, clr, &mode);
                return mode;
        }
        bool
        NewMesh (
                CLxLoc_Mesh		&mesh)
        {
                return CreateMesh (mesh);
        }
        bool
        NewSolidDrill (
                CLxLoc_SolidDrill	&drill)
        {
                return CreateSolidDrill (drill);
        }
        bool
        GetMeshItem (
                ILxUnknownID		 mesh,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj = NULL;
        
                if (LXx_FAIL (ItemFromMesh (mesh, &obj)))
                        return false;
        
                return item.take (obj);
        }

};
#endif
