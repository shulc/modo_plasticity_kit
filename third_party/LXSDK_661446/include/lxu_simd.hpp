/*
 * Plug-in SDK Header: SIMD Utilities
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
 * Provides vectorization utility functions and types for C++ plug-ins.
 */
#ifndef LXU_SIMD_HPP
#define LXU_SIMD_HPP

#include <lxthread.h>
#include <lxvmath.h>

                /*
                 * Everything is in a namespace, since these are somewhat
                 * non-standard SDK names.
                 */
                namespace lxsimd {

/*
 * An Farray is an array of floats, the fundamental unit of SIMD computation. The
 * MAXRUN define allows us to declare buffers large enough for any result.
 */
typedef float *		Farray;
typedef const float *	FarrayC;
typedef float		FarrayBuffer[LXi_SIMD_MAXRUN];

/*
 * A Varray is a vector Farray, basically an array of pointers to arrays of floats.
 * The VarrayBuffer class allocates space for three buffers and returns an array
 * of pointers to to.
 */
typedef Farray *	Varray;
typedef FarrayC *	VarrayC;

class VarrayBuffer {
    public:
        float		*vf [3];
        FarrayBuffer	 buf[3];

        VarrayBuffer()
        {
                vf[0] = &buf[0][0];
                vf[1] = &buf[1][0];
                vf[2] = &buf[2][0];
        }

        operator Varray  () { return           vf; }
        operator VarrayC () { return (VarrayC) vf; }
};


/*
 * Access functions convert between Varray entries and vectors. These are
 * implemented as templates so different vector types can be used, but mostly
 * so that they will in-line.
 */
        template <class F>
        void
VarrayGet (
        VarrayC			 va,
        F			*vec,
        unsigned		 i)
{
        vec[0] = va[0][i];
        vec[1] = va[1][i];
        vec[2] = va[2][i];
}

        template <class F>
        void
VarraySet (
        Varray			 va,
        const F			*vec,
        unsigned		 i)
{
        va[0][i] = vec[0];
        va[1][i] = vec[1];
        va[2][i] = vec[2];
}


/*
 * Farray Functions
 *
 * Farray functions take a writable Farray as their first argument, and perform some
 * math operation over it using additional arguments. The description is in reverse
 * Polish stack notation. For example, 'ABset' is "push A, push B, set", or:
 *
 *	a = b
 */
extern void	FarrayABset (Farray a, float b, unsigned num);
extern void	FarrayABset (Farray a, FarrayC b, unsigned num);

/*
 *	a = a + b
 */
extern void	FarrayABp (Farray a, const float b, unsigned num);

/*
 *	a = a * b
 */
extern void	FarrayABx (Farray a, const float b, unsigned num);

/*
 * ABxR is "push A, push B, times, result". The result goes into R rather than
 * either of the other two.
 *
 *	r = a * b
 */
extern void	FarrayABxR (Farray r, FarrayC a, FarrayC b, unsigned num);

/*
 *	a = a * b + c
 */
extern void	FarrayABxCp (Farray a, float b, float c, unsigned num);

/*
 * 	r = a1 * b1 + a2 * b2 + a3 * b3 + b4
 */
extern void	FarrayABxABxpABxpBpR (Farray r, FarrayC a1, float b1, FarrayC a2, float b2, FarrayC a3, float b3, float b4, unsigned num);

/*
 * 	v = 3 * v^2 - 2 * v^3
 */
extern void	FarrayVsmooth (Farray v, unsigned num);

/*
 * 	r = sqrt (v dot v)
 */
extern void	FarrayVlenR (Farray r, VarrayC v, unsigned num);

/*
 * 	v = CLAMP (v, a, b)
 */
extern void	FarrayVABclamp (Farray v, float a, float b, unsigned num);

/*
 * Varray Functions
 *
 * Varray functions take a writable Varray as their first argument, performing
 * a math operation over the other arguments.
 *
 *	r = a * b
 */
extern void	VarrayABxR (Varray r, VarrayC a, FarrayC b, unsigned num);

/*
 *	a = a + b * c
 */
extern void	VarrayABCxp (Varray a, VarrayC b, float c, unsigned num);

/*
 * Because C++ can't tell the difference between float[3] and float*, we have to
 * pass the components of a non-varying vector individually.
 *
 *	a = a + [x, y, z]
 */
extern void	VarrayAXYZvecp (Varray r, float x, float y, float z, unsigned num);

/*
 *	a = a * [x, y, z]
 */
extern void	VarrayAXYZvecx (Varray r, float x, float y, float z, unsigned num);

/*
 * Matrix multiply input vectors times a 4x4 matrix, returning result vectors.
 *
 * 	r = M v
 */
extern void	VarrayMatrix4Multiply (Varray r, LXtMatrix4 m, VarrayC v, unsigned num);

                }; // END namespace

#endif // LXU_SIMD_HPP

