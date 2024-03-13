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
#ifndef LXUSER_deform_HPP
#define LXUSER_deform_HPP

#include <lxw_deform.hpp>

#include <lx_item.hpp>
#include <lx_visitor.hpp>
        #include <vector>



class CLxUser_Falloff : public CLxLoc_Falloff
{
        public:
        CLxUser_Falloff () {}
        CLxUser_Falloff (ILxUnknownID obj) : CLxLoc_Falloff (obj) {}



};

class CLxUser_Deformation : public CLxLoc_Deformation
{
        public:
        CLxUser_Deformation () {}
        CLxUser_Deformation (ILxUnknownID obj) : CLxLoc_Deformation (obj) {}



};

class CLxUser_Deformer : public CLxLoc_Deformer
{
        public:
        CLxUser_Deformer () {}
        CLxUser_Deformer (ILxUnknownID obj) : CLxLoc_Deformer (obj) {}

        /**
         * The user class offers enumeration methods using C++ visitors.
         */
                LxResult
        EnumPartition (
                unsigned		 index,
                CLxImpl_AbstractVisitor	*visitor)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return EnumeratePartition (gv, index);
        }

};

class CLxUser_MeshInfluence : public CLxLoc_MeshInfluence
{
        public:
        CLxUser_MeshInfluence () {}
        CLxUser_MeshInfluence (ILxUnknownID obj) : CLxLoc_MeshInfluence (obj) {}

        bool
        GetMesh (
                unsigned		 index,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (MeshByIndex (index, &obj)))
                        return false;
        
                return item.take (obj);
        }

};

class CLxUser_ItemInfluence : public CLxLoc_ItemInfluence
{
        public:
        CLxUser_ItemInfluence () {}
        CLxUser_ItemInfluence (ILxUnknownID obj) : CLxLoc_ItemInfluence (obj) {}

        LxResult
        Enum (
                CLxImpl_AbstractVisitor	*visitor)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;
        
                gv.loc.vis = visitor;
                return Enumerate (gv);
        }
        
                bool
        CurItem (
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                return LXx_OK (GetItem (&obj)) && item.take (obj);
        }

};

class CLxUser_GroupDeformer : public CLxLoc_GroupDeformer
{
        public:
        CLxUser_GroupDeformer () {}
        CLxUser_GroupDeformer (ILxUnknownID obj) : CLxLoc_GroupDeformer (obj) {}

        bool
        GetDeformer (
                unsigned		 index,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (DeformerByIndex (index, &obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * The user class allows the effect at each point to be read safely into a vector
         * of composite elements.
         */
        class CDeformerWeight {
            public:
                unsigned		 deformer;
                float			 weight;
        };
        
        typedef std::vector<CDeformerWeight>	DeformerWeightArray;
        
                LxResult
        PointEffectList (
                unsigned		 meshIndex,
                LXtPointID		 point,
                DeformerWeightArray	&list)
        {
                LxResult		 rc;
                unsigned		*ibuf;
                float			*fbuf;
                unsigned		 i, n;
                size_t			 len;
        
                list.clear ();
        
                len = 16;
                while (1) {
                        ibuf = new unsigned [len];
                        fbuf = new float    [len];
        
                        rc = PointEffect (meshIndex, point, ibuf, fbuf, &n, static_cast<unsigned>(len));
                        if (rc != LXe_SHORTBUFFER)
                                break;
        
                        delete[] ibuf;
                        delete[] fbuf;
                        len *= 2;
                }
        
                if (LXx_OK (rc))
                        for (i = 0; i < n; i++) {
                                CDeformerWeight	 dw;
        
                                dw.deformer = ibuf[i];
                                dw.weight   = fbuf[i];
                                list.push_back (dw);
                        }
        
                delete[] ibuf;
                delete[] fbuf;
                return rc;
        }

};

class CLxUser_WeightMapDeformerItem : public CLxLoc_WeightMapDeformerItem
{
        public:
        CLxUser_WeightMapDeformerItem () {}
        CLxUser_WeightMapDeformerItem (ILxUnknownID obj) : CLxLoc_WeightMapDeformerItem (obj) {}



};

class CLxUser_DeformerService : public CLxLoc_DeformerService
{
        public:
        bool
        IsDeformer (
                ILxUnknownID		 item)
        {
                unsigned		 flags;
        
                return DeformerFlags (item, &flags) != LXe_NOTFOUND;
        }
        bool
        GetMesh (
                ILxUnknownID		 defItem,
                unsigned		 index,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (MeshByIndex (defItem, index, &obj)))
                        return false;
        
                return item.take (obj);
        }
        bool
        GetGroupDeformer (
                ILxUnknownID		 dgItem,
                ILxUnknownID		 chanRead,
                CLxLoc_GroupDeformer	&dgObj)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (GroupDeformer (dgItem, chanRead, &obj)))
                        return false;
        
                return dgObj.take (obj);
        }
        bool
        GetDeformerDeformationItem (
                ILxUnknownID		 deformer,
                CLxLoc_Item		&deformerItem,
                bool			&isLocator)
        {
                LXtObjectID		 obj = NULL;
                LxResult		 rc;
        
                rc = DeformerDeformationItem (deformer, &obj);
                if (LXx_FAIL (rc))
                        return false;
        
                isLocator = (rc == LXe_TRUE);
                return deformerItem.take (obj);
        }

};
#endif
