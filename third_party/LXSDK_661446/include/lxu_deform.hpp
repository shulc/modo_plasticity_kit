/*
 * Plug-in SDK Header: Deformation Wrapper Classes
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
 * Provides wrapper classes for creating deformation, fallof and influence
 * objects in C++ plug-ins.
 */
#ifndef LXU_DEFORM_HPP
#define LXU_DEFORM_HPP

#include <lx_deform.hpp>
#include <lx_mesh.hpp>
#include <lxu_meta.hpp>
#include <lxu_math.hpp>
#include <lxu_matrix.hpp>
#include <lxu_simd.hpp>
#include <lxtableau.h>


using namespace lxsimd;

/*
 * ----------------------------------------------------
 * Mesh Influence
 *
 * A mesh influence is used to perform deformations over a mesh. A mesh
 * influence consists of three things:
 *
 *	- a subset of vertices. This is given either by vertex marking or
 *	  by vertex map membership.
 *
 *	- an offset at each vertex. This is how the vertex should move in
 *	  object space. There may also be an optional transform which is
 *	  how it should move and rotate.
 *
 *	- an optional weight. Weighting vertices allows the influence to
 *	  fade smoothly at the edges. Influences without weights are assumed
 *	  to have a weight of 1.0 everywhere.
 *
 * The CLxMeshInfluence class is subclassed by the client, and the virtual
 * functions define the features of the influence.
 */
class CLxMeshInfluence
{
    public:
                                 CLxMeshInfluence ();
        virtual			~CLxMeshInfluence ();

        /*
         * These methods define gross features of the influence -- whether
         * it supports non-unity weights (default false), whether it has
         * per-vertex offsets (default true), and whether it supports
         * rotational or scaling transforms in addition to offsets (false).
         */
        virtual bool		 HasWeight () { return false; }
        virtual bool		 HasOffset () { return true; }

        /*
         * Return false if the influence is disabled and has no effect.
         */
        virtual bool		 IsEnabled () { return true; }

        /*
         * Traversal over the mesh is done either by point marking or by vertex
         * map. SelectMap() is called to select the vertex map for traversal.
         * If this returns false (the default) then MarkMode() is called to
         * mark vertices on the mesh and return the mark mode. SetXfrm() is called
         * with the world transform of the target mesh.
         */
        virtual bool		 SelectMap (CLxUser_Mesh &, CLxUser_MeshMap &) { return false; }
        virtual LXtMarkMode	 MarkMode (CLxUser_Mesh &, CLxUser_Point &) { return LXiMARK_ANY; }
        virtual void		 WorldXfrm (LXtMatrix4 xfrm) {}
        virtual void		 SourceItem (CLxUser_Item &) {}

        /*
         * During traversal these methods are called to get the offset, and the
         * optional weight of a given point.
         */
        virtual void		 Offset (CLxUser_Point &, float, LXtFVector) {}
        virtual float		 Weight (CLxUser_Point &) { return 1.0; }

        /*
         * Spawn() is called by the client to get a COM-object version of this
         * object.
         */
        void		 Spawn (void **ppvObj);

        class pv_MeshInfluence	*pv;
};



/*
 * ----------------------------------------------------
 * Falloff
 *
 * A falloff defines a scalar field defined in world space which can be sampled
 * in a variety of ways.
 */
namespace lx {

        /*
         * This templated function can be used to implement WeightRun()
         * using any suitable GetWeight() method. This has the potential to in-line
         * and vectorize (with the pragma).
         */
                template <class T>
                LxResult
        WeightRun (
                T			*that,
                const float	       **pos,
                const LXtPointID	*points,
                const LXtPolygonID	*polygons,
                float			*weight,
                unsigned		 count)
        {
                const float		*fx, *fy, *fz;

                fx = pos[0];
                fy = pos[1];
                fz = pos[2];

                 #ifdef _CC_INTEL
                  #pragma ivdep
                 #endif

                for (int i = 0; i < count; i++)
                {
                        LXtFVector		 v;

                        LXx_VSET3 (v, fx[i], fy[i], fz[i]);
                        weight[i] = that->GetWeight (v, (points ? points[i] : NULL), (polygons ? polygons[i] : NULL));
                }

                return LXe_OK;
        }
};


/*
 * The constructor for this class can be called to create a spawner for a falloff
 * implementation class:
 *
 *	initialize ()
 *	{
 *		CLxSpawner_Falloff<MyFalloff> ("myfalloffname");
 *	}
 */
template <class T>
class CLxSpawner_Falloff
{
    public:
        CLxSpawner_Falloff (
                const char		*spname)
        {
                CLxSpawnerCreate<T>	 sc (spname);

                if (sc.created)
                        sc.spawn->AddInterface (new CLxIfc_Falloff<T>);
        }
};


/*
 * ----------------------------------------------------
 * Deformation
 *
 * A deformation specifies a vector field defined in world space which can be sampled
 * in doubles or floats.
 *
 * The constructor for this class can be called to create a spawner for a deformation
 * implementation class:
 *
 *	initialize ()
 *	{
 *		CLxSpawner_Deformation<MyDeformation> ("myDeformationName");
 *	}
 */
template <class T>
class CLxSpawner_Deformation
{
    public:
        CLxSpawner_Deformation (
                const char		*spname)
        {
                CLxSpawnerCreate<T>	 sc (spname);

                if (sc.created)
                        sc.spawn->AddInterface (new CLxIfc_Deformation<T>);
        }
};


/*
 * ----------------------------------------------------
 * Falloff Metaclass
 *
 * Falloffs are quite simple -- just computing a scalar value at any point in
 * space. The only complexity is whether there's a world transform.
 */
class CLxFalloff
{
    public:
        /*
         * The falloff has a few states that are defined for all space.
         *
         *	valid()		true if some non-zero falloff can be computed
         *	bounded()	true if the non-zero region of space is limited
         *	bounds()	the smallest box containing all non-zero falloffs
         *
         * The default is for a falloff valid over all space.
         */
        virtual bool		 valid () { return true; }
        virtual bool		 bounded () { return false; }
        virtual void		 bounds (CLxBoundingBox &) {}

        /*
         * World textures compute the weight in world coordinates.
         */
        virtual float		 weight_world (const LXtFVector pos, const LXtPointID point, const LXtPolygonID polygon) { return 0.0; }
        virtual void		 run_world (const float **pos, const LXtPointID *points, const LXtPolygonID *polygons, float *weight, unsigned num) {}

        /*
         * Local textures compute the weight in coordinates relative to a
         * world matrix. The inverse matrix is a member that must be initialized.
         */
        CLxMatrix4		 world_inverse;
        virtual float		 weight_local (const LXtFVector pos, const LXtPointID point, const LXtPolygonID polygon) { return 0.0; }
        virtual void		 run_local (const float **pos, const LXtPointID *points, const LXtPolygonID *polygons, float *weight, unsigned num) {}
        
        /*
         * If the falloff requires vertex or polygon information to evaluate,
         * the set_mesh function will be called with the mesh and the transform
         * matrix for the mesh, allowing any COM interfaces to be initialized.
 	 */
        virtual void		 set_mesh (CLxUser_Mesh &mesh, CLxMatrix4 &matrix) {}
};

/*
 * Template for server metaclass. Unlike some metaclasses this one is implemented
 * entirely in the template. This allows the compiler the maximum opportunity to
 * optimise (and perhaps vectorize) the inner functions. There are actually two
 * different polymorph code paths, one for world and one for local.
 */
template <class T>
class CLxMeta_Falloff :
                public CLxMetaObject
{
    public:
        bool			 is_local, has_run;

        CLxMeta_Falloff () :
                CLxMetaObject (&lx::guid_Falloff)
        {
                is_local = false;
                has_run  = false;
        }

        class cFalloff :
                        public CLxImpl_Falloff,
                        public T
        {
            public:
                bool		 has_run;

                cFalloff () : has_run (false) {}

                LXxO_Falloff_Bounds
                {
                        T	*t = (T *) this;	// OSX compiler needs hand-holding

                        if (!t->valid ())
                                return LXe_DISABLED;

                        if (!t->bounded ())
                                return LXe_INFINITE_BOUND;

                        CLxBoundingBox	 tmp;

                        t->bounds (tmp);
                        tmp.get (box);
                        return LXe_OK;
                }

                virtual float vf_weight (const LXtFVector, const LXtPointID, const LXtPolygonID) = 0;
                virtual LxResult vf_run (const float **, const LXtPointID *, const LXtPolygonID *, float *, unsigned) = 0;

                LXxO_Falloff_WeightF
                {
                        return vf_weight (position, point, polygon);
                }

                LXxO_Falloff_WeightRun
                {
                        return vf_run (pos, points, polygons, weight, num);
                }
                
                LXxO_Falloff_SetMesh
                {
                        CLxUser_Mesh	 mesh_obj (mesh);
                        T		*t = (T *) this;	// OSX compiler needs hand-holding

                        if (mesh_obj.test ())
                        {
                                CLxMatrix4		 transform (xfrm);
                                t->set_mesh (mesh_obj, transform);
                        
                                return LXe_OK;
                        }

                        return LXe_FAILED;
                }
        };

        class cRunner_World
        {
            public:
                T * t;
                float GetWeight (const LXtFVector pos, const LXtPointID point, const LXtPolygonID polygon) { return t->weight_world (pos, point, polygon); }
        };

        class cRunner_Local
        {
            public:
                T * t;
                float GetWeight (const LXtFVector pos, const LXtPointID point, const LXtPolygonID polygon) { return t->weight_local (pos, point, polygon); }
        };

        class cFalloff_World :
                        public cFalloff
        {
            public:
                float vf_weight (const LXtFVector pos, const LXtPointID point, const LXtPolygonID polygon) LXx_OVERRIDE
                {
                        T		*t = (T *) this;
                        return t->weight_world (pos, point, polygon);
                }

                LxResult vf_run (const float **pos, const LXtPointID *points, const LXtPolygonID *polygons, float *weight, unsigned num) LXx_OVERRIDE
                {
                        T		*t = (T *) this;

                        if (this->has_run)
                        {
                                t->run_world (pos, points, polygons, weight, num);
                                return LXe_OK;
                        }

                        cRunner_World run;
                        run.t = this;
                        return lx::WeightRun (&run, pos, points, polygons, weight, num);
                }
        };

        class cFalloff_Local :
                        public cFalloff
        {
            public:
                float vf_weight (const LXtFVector pos, const LXtPointID point, const LXtPolygonID polygon) LXx_OVERRIDE
                {
                        T		*t = (T *) this;
                        LXtFVector	 loc;

                        lx::Matrix4Multiply (loc, t->world_inverse, pos);
                        return t->weight_local (loc, point, polygon);
                }

                LxResult vf_run (const float **pos, const LXtPointID *points, const LXtPolygonID *polygons, float *weight, unsigned num) LXx_OVERRIDE
                {
                        T		*t = (T *) this;
                        VarrayBuffer	 loc;

                        VarrayMatrix4Multiply (loc, t->world_inverse, pos, num);

                        if (this->has_run)
                        {
                                t->run_local (loc, points, polygons, weight, num);
                                return LXe_OK;
                        }

                        cRunner_Local run;
                        run.t = this;
                        return lx::WeightRun (&run, loc, points, polygons, weight, num);
                }
        };

        template <class F>
        class cPolymorph :
                        public CLxExtendedPolymorph<F>
        {
            public:
                bool		 has_run;

                cPolymorph (
                        CLxMetaInterfaces	*ifcs,
                        bool			 run) :
                        CLxExtendedPolymorph<F> (ifcs),
                        has_run (run)
                {
                        this->AddInterface (new CLxIfc_Falloff<F>);
                }

                        void *
                NewObj ()			 LXx_OVERRIDE
                {
                        cFalloff		*fall;

                        fall = new F;
                        fall->has_run = has_run;
                        return reinterpret_cast<void *> (fall);
                }
        };

                CLxGenericPolymorph *
        new_spawner (
                CLxMetaInterfaces	*ifcs)	LXx_OVERRIDE
        {
                if (is_local)
                        return new cPolymorph<cFalloff_Local> (ifcs, has_run);
                else
                        return new cPolymorph<cFalloff_World> (ifcs, has_run);
        }

                void *
        cast_raw (
                ILxUnknownID		 obj)	LXx_OVERRIDE
        {
                T			*ptr;

                if (is_local)
                        ptr = (T *) LXCWxOBJ (obj, cFalloff_Local);
                else
                        ptr = (T *) LXCWxOBJ (obj, cFalloff_World);

                return reinterpret_cast<void *> (ptr);
        }

        /*
         * Type-safe function for extracting the client's object.
         */
                T *
        cast (
                ILxUnknownID		 obj)
        {
                return reinterpret_cast<T *> (cast_raw (obj));
        }

        /*
         * Metaclass customization. These are intended for the client to set
         * the global state of the metaclass.
         */
                void
        set_local (
                bool			 loc = true)
        {
                is_local = loc;
        }

                void
        set_run_override (
                bool			 run = true)
        {
                has_run = run;
        }
};


#endif // LXU_DEFORM_HPP

