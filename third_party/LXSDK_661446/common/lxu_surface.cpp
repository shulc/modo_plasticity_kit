/*
 * Plug-in SDK Header: Common Utility
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
 *
 * Surface Sampling Class
 */

/*
 * Disable deprecated function warning.
 */
//#pragma warning(disable: 4996)

#include <lxu_surface.hpp>


/*
 * ----------------------------------------------------------------
 * CLxSurfVisitTriangleSoup
 *
 * This is a singleton implementation of the TriangleSoup needed to be passed
 * to the surface sample method. Methods here pass more-or-less directly through
 * to the equivalent method of the CLxSurfaceVisitor
 */
class CLxSurfVisitTriangleSoup :
                public CLxImpl_TriangleSoup,
                public CLxSingletonPolymorph
{
    public:
        CLxSurfaceVisitor	*sv;
        unsigned int		 vrt_index;

        LXxSINGLETON_METHOD;

        CLxSurfVisitTriangleSoup ()
        {
                AddInterface (new CLxIfc_TriangleSoup<CLxSurfVisitTriangleSoup>);
        }

        unsigned int	 soup_TestBox (const LXtTableauBox bbox) LXx_OVERRIDE;
        LxResult	 soup_Segment (unsigned int segID, unsigned int type) LXx_OVERRIDE;
        LxResult	 soup_Vertex  (const float *vertex, unsigned int *index) LXx_OVERRIDE;
        LxResult	 soup_Polygon (unsigned int v0, unsigned int v1, unsigned int v2) LXx_OVERRIDE;
        void		 soup_Connect (unsigned int type) LXx_OVERRIDE;
};


/*
 * ----------------------------------------------------------------
 * CLxSurfaceVisitor : Implementation
 *
 */
class pv_SurfaceVisitor {
    public:
        bool			 throw_exceptions;
        bool			 allow_quads;
        bool			 visit_features;
        float			 sample_rate;

        CLxUser_Surface		 surf_obj;
        CLxUser_TableauVertex	 tblx_vertex;

        pv_SurfaceVisitor();

        LxResult	 err (LxResult rc)
        {
                if (throw_exceptions)
                        throw (rc);

                return rc;
        }
};

#define FAIL_(x)	return pv->err (x)
#define FAIL_NI		FAIL_ (LXe_NOINTERFACE)
#define TEST_RC		if (LXx_FAIL (rc)) FAIL_ (rc)


pv_SurfaceVisitor::pv_SurfaceVisitor ()
{
        throw_exceptions = false;
        allow_quads      = false;
        visit_features   = false;
        sample_rate      = -1.0;
}


/*
 * Manage the private object on create and destroy.
 */
CLxSurfaceVisitor::CLxSurfaceVisitor ()
{
        pv = new pv_SurfaceVisitor;
}

CLxSurfaceVisitor::~CLxSurfaceVisitor ()
{
        delete pv;
}


/*
 * Configure behavior.
 */
        void
CLxSurfaceVisitor::EnableExceptions (
        bool		 state)
{
        pv->throw_exceptions = state;
}

        void
CLxSurfaceVisitor::AllowQuads (
        bool		 state)
{
        pv->allow_quads = state;
}

        void
CLxSurfaceVisitor::VisitFeatures (
        bool		 state)
{
        pv->visit_features = state;
}

        void
CLxSurfaceVisitor::SetSampleRate (
        float		 rate)
{
        pv->sample_rate = rate;
}

        LxResult
CLxSurfaceVisitor::SetSurface (
        ILxUnknownID		 surf)
{
        if (!pv->surf_obj.set (surf))
                FAIL_NI;

        CLxUser_TableauService	 srv;

        if (!srv.NewVertex (pv->tblx_vertex))
                FAIL_ (LXe_FAILED);

        if (!pv->visit_features)
                return LXe_OK;

 #if 0
        const char		*name;
        LXtID4			 type;
        unsigned int		 i, n, k;
        LxResult		 rc;

        for (k = 0; k < 3; k++) {
                switch (k) {
                    case 0: type = LXiTBLX_BASEFEATURE;	break;
                    case 1: type = LXi_VMAP_TEXTUREUV;	break;
                    case 2: type = LXiTBLX_DPDU;	break;
                }

                rc = pv->surf_obj.FeatureCount (type, &n);
                TEST_RC;

                for (i = 0; i < n; i++) {
                        rc = pv->surf_obj.FeatureByIndex (type, i, &name);
                        TEST_RC;

                        if (TestFeature (type, name)) {
                                // add feature
                        }
                }
        }
 #endif
        return LXe_OK;
}

        LxResult
CLxSurfaceVisitor::DefaultFeatures ()
{
        unsigned		 index;
        LxResult		 rc;

        rc = pv->tblx_vertex.AddFeature (LXiTBLX_BASEFEATURE, LXsTBLX_FEATURE_POS,    &index);
        TEST_RC;
        rc = pv->tblx_vertex.AddFeature (LXiTBLX_BASEFEATURE, LXsTBLX_FEATURE_OBJPOS, &index);
        TEST_RC;
        rc = pv->tblx_vertex.AddFeature (LXiTBLX_BASEFEATURE, LXsTBLX_FEATURE_NORMAL, &index);
        TEST_RC;

        return LXe_OK;
}

        CLxUser_TableauVertex &
CLxSurfaceVisitor::Features ()
{
        return pv->tblx_vertex;
}


        LxResult
CLxSurfaceVisitor::Sample ()
{
        CLxUser_SurfaceBin	 bin;
        CLxUser_TableauSurface	 ts;
        CLxSurfVisitTriangleSoup soup;
        LXtBBox			 box;
        LXtTableauBox		 tbox;
        LXtObjectID		 obj;
        unsigned int		 i, n;
        LxResult		 rc;

        rc = pv->surf_obj.GetBBox (&box);
        TEST_RC;

        if (!TestBox (&box))
                return LXe_OK;

        rc = pv->surf_obj.BinCount (&n);
        TEST_RC;

        soup.sv = this;

        for (i = 0; i < n; i++) {
                rc = pv->surf_obj.BinByIndex (i, &obj);
                TEST_RC;

                if (!bin.take (obj))
                        FAIL_NI;

                if (!StartBin (bin))
                        continue;

                rc = bin.GetBBox (&box);
                TEST_RC;

                if (!TestBox (&box))
                        continue;

                if (!ts.set (bin))
                        FAIL_NI;

                rc = ts.SetVertex (pv->tblx_vertex);
                TEST_RC;

                tbox[0] = static_cast<float>(box.min[0]);
                tbox[1] = static_cast<float>(box.min[1]);
                tbox[2] = static_cast<float>(box.min[2]);
                tbox[3] = static_cast<float>(box.max[0]);
                tbox[4] = static_cast<float>(box.max[1]);
                tbox[5] = static_cast<float>(box.max[2]);
                rc = ts.Sample (tbox, pv->sample_rate, soup);
                TEST_RC;
        }

        return LXe_OK;
}


        unsigned int
CLxSurfVisitTriangleSoup::soup_TestBox (
        const LXtTableauBox	 bbox)
{
        LXtBBox			 box;

        box.min[0] = bbox[0];
        box.min[1] = bbox[1];
        box.min[2] = bbox[2];
        box.max[0] = bbox[3];
        box.max[1] = bbox[4];
        box.max[2] = bbox[5];

        LXx_VSUB3 (box.extent, box.max, box.min);
        LXx_VADD3 (box.center, box.min, box.max);
        LXx_VSCL  (box.center, 0.5);

        return (sv->TestBox (&box) ? 1 : 0);
}


        LxResult
CLxSurfVisitTriangleSoup::soup_Segment (
        unsigned int		 segID,
        unsigned int		 type)
{
        vrt_index = 0;
        return (sv->StartSegment (segID, type) ? LXe_TRUE : LXe_FALSE);
}


        LxResult
CLxSurfVisitTriangleSoup::soup_Vertex  (
        const float		*vertex,
        unsigned int		*index)
{
        sv->Vertex (vertex, vrt_index);
        index[0] = vrt_index++;
        return LXe_OK;
}


        LxResult
CLxSurfVisitTriangleSoup::soup_Polygon (
        unsigned int		 v0,
        unsigned int		 v1,
        unsigned int		 v2)
{
        sv->Triangle (v0, v1, v2);
        return LXe_OK;
}


        void
CLxSurfVisitTriangleSoup::soup_Connect (unsigned int type)
{
}



