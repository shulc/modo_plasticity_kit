/*
 * Plug-in SDK Header: C++ Services
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
 * Wrapper for accessing surface items.
 */
#ifndef LX_SURFACE_HPP
#define LX_SURFACE_HPP

#include <lx_surface.hpp>
#include <lx_tableau.hpp>
#include <lx_vertex.hpp>
#include <lxu_package.hpp>


/*
 * ----------------------------------------------------------------
 * SurfaceItem Metaclass
 *
 * CLxMeta_SurfaceItem adds a surface object to a package. This is
 * an unusual metaclass in that there is no overrideable base class.
 * It just needs to be instantiated with the name of the channel
 * holding the surface object.
 */
class CLxMeta_SurfaceItem :
                public CLxMeta
{
    public:
        CLxMeta_SurfaceItem (const char *channel);

    //internal:
        void *		 alloc () LXx_OVERRIDE;
};


/*
 * ----------------------------------------------------------------
 * Surface Metaclass
 *
 * Surfaces are objects that contain triangles organized into bins. Each
 * bin has tags that define the material or part for the bin. Bins are
 * only needed for the most 
 */
class CLxSurfaceBin :
                public CLxObject
{
    public:
        /*
         * Tags for the bin are added one at a time.
         */
        void		add_tag (const char *tag, const char *value);

        virtual void	bounds (LXtBBox *box) = 0;
        virtual void	front_bounds (LXtBBox *box) { bounds (box); }

        virtual void	sample (CLxUser_TriangleSoup &)= 0;

        virtual bool	segment_box (unsigned, LXtBBox *) { return false; }

        class pv_SurfaceBin *pv;
};

class CLxSurface :
                public CLxObject
{
    public:
        /*
         * The easiest way to implement a procedural surface is with the
         * getMesh() method. This is called with an empty mesh that you 
         * popuualte with your geometry. Everything after that is automatic.
         */
        virtual void	get_mesh (CLxUser_Mesh &) {}

        /*
         * To manually manage bins, add each bin to the surface. Once added
         * they belong to the surface.
         */
        void		add_bin (CLxSurfaceBin *);

        /*
         * Normally bounds are computed automatically. Overriding these methods
         * can be useful if they can be computed more easily, but is optional.
         */
        virtual void	bounds (LXtBBox *box);
        virtual void	front_bounds (LXtBBox *box);

        class pv_Surface *pv;
};

class CLxMeta_Surface_Core :
                public CLxMetaObject
{
    public:
        /*
         * Set xxx to world space.
         */
        void	set_xxx (bool world = true);

    //internal:
        CLxMeta_Surface_Core ();

        class pv_Meta_Surface	*pv;

        virtual CLxSurface *	 new_inst () = 0;
        void *			 alloc () LXx_OVERRIDE;
};

template <class T>
class CLxMeta_Surface :
                public CLxMeta_Surface_Core
{
    public:
                CLxSurface *
        new_inst ()
        {
                return new T;
        }
};


/*
 * ----------------------------------------------------------------
 * CLxSurfaceVisitor allows a client to sample surfaces to get triangles and quads.
 */
class CLxSurfaceVisitor
{
    public:
                         CLxSurfaceVisitor ();
        virtual		~CLxSurfaceVisitor ();

        virtual bool	 TestFeature  (LXtID4 type, const char *name)
                                        { return false; }
        virtual bool	 TestBox      (LXtBBox *box)
                                        { return true; }
        virtual bool	 StartBin     (CLxUser_SurfaceBin &bin)
                                        { return true; }
        virtual bool	 StartSegment (unsigned int segID, unsigned int type)
                                        { return true; }
        virtual void	 Vertex       (const float *vertex, unsigned int index)
                                        {}
        virtual void	 Triangle     (unsigned int v0, unsigned int v1, unsigned int v2)
                                        {}
        virtual void	 Quad         (unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3)
                                        {}

        void		 EnableExceptions (bool state);
        void		 AllowQuads (bool state);
        void		 VisitFeatures (bool state);
        void		 SetSampleRate (float rate);

        LxResult	 SetSurface (ILxUnknownID surf);
        LxResult	 DefaultFeatures ();
        CLxUser_TableauVertex &
                         Features ();

        LxResult	 Sample ();

        class pv_SurfaceVisitor	*pv;
};



#endif	/* LX_SURFACE_HPP */

