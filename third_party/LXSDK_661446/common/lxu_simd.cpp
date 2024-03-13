/*
 * Plug-in SDK Source: SIMD Utilities
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
 * Provides SIMD utility functions for C++ plug-ins.

icl -D_CC_INTEL -Qwe117,592 -Qwd144,167,556,1786,18001 -Qvec_report2 /Zc:forScope -c -W3 -I..\..\include -D_AMD64_=1 -DWIN64 -D_WIN64 /Zi /O2 /G7 -DRELEASE -D_MSWIN -D_CRT_SECURE_NO_WARNINGS -nologo /MT /EHsc -Foi64\lxu_simd.obj lxu_simd.cpp

 */
#include <lxu_simd.hpp>

                namespace lxsimd {

        void
FarrayABset (
        Farray			 a,
        float			 b,
        unsigned		 num)
{
        unsigned		 i;

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
        for (i = 0; i < num; i++)
                a[i] = b;
}

        void
FarrayABset (
        Farray			 a,
        FarrayC			 b,
        unsigned		 num)
{
        unsigned		 i;

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
        for (i = 0; i < num; i++)
                a[i] = b[i];
}

        void
FarrayABp (
        Farray			 a,
        float			 b,
        unsigned		 num)
{
        unsigned		 i;

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
        for (i = 0; i < num; i++)
                a[i] = a[i] + b;
}

        void
FarrayABx (
        Farray			 a,
        float			 b,
        unsigned		 num)
{
        unsigned		 i;

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
        for (i = 0; i < num; i++)
                a[i] = a[i] * b;
}

        void
FarrayABxR (
        Farray			 r,
        FarrayC			 a,
        FarrayC			 b,
        unsigned		 num)
{
        unsigned		 i;

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
        for (i = 0; i < num; i++)
                r[i] = a[i] * b[i];
}

        void
FarrayABxCp (
        Farray			 a,
        float			 b,
        float			 c,
        unsigned		 num)
{
        unsigned		 i;

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
        for (i = 0; i < num; i++)
                a[i] = a[i] * b + c;
}

        void
FarrayVsmooth (
        Farray			 v,
        unsigned		 num)
{
        unsigned		 i;

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
        for (i = 0; i < num; i++)
                v[i] = (3.0f - 2.0f * v[i]) * v[i] * v[i];
}

        void
FarrayVlenR (
        Farray			 r,
        VarrayC			 v,
        unsigned		 num)
{
        const float		*x, *y, *z;
        unsigned		 i;

        x = v[0];
        y = v[1];
        z = v[2];

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
        for (i = 0; i < num; i++)
                r[i] = sqrt (x[i] * x[i] + y[i] * y[i] + z[i] * z[i]);
}

        void
FarrayVABclamp (
        Farray			 v,
        float			 a,
        float			 b,
        unsigned		 num)
{
        unsigned		 i;

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
        for (i = 0; i < num; i++)
                v[i] = v[i] + (v[i] < a) * (a - v[i]) + (v[i] > b) * (b - v[i]);
}

        void
FarrayABxABxpABxpBpR (
        Farray			 r,
        FarrayC			 a1,
        float			 b1,
        FarrayC			 a2,
        float			 b2,
        FarrayC			 a3,
        float			 b3,
        float			 b4,
        unsigned		 num)
{
        unsigned		 i;

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
        for (i = 0; i < num; i++)
                r[i] = a1[i] * b1 + a2[i] * b2 + a3[i] * b3 + b4;
}

        void
VarrayABxR (
        Varray			 r,
        VarrayC			 a,
        FarrayC			 b,
        unsigned		 num)
{
        float			*rp;
        const float		*ap;
        unsigned		 i, k;

        for (k = 0; k < 3; k++) {
                rp = r[k];
                ap = a[k];

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
                for (i = 0; i < num; i++)
                        rp[i] = ap[i] * b[i];
        }
}

        void
VarrayABCxp (
        Varray			 a,
        VarrayC			 b,
        float			 c,
        unsigned		 num)
{
        float			*ap;
        const float		*bp;
        unsigned		 i, k;

        for (k = 0; k < 3; k++) {
                ap = a[k];
                bp = b[k];

 #ifdef _CC_INTEL
  #pragma ivdep
 #endif
                for (i = 0; i < num; i++)
                        ap[i] += bp[i] * c;
        }
}

        void
VarrayAXYZvecp (
        Varray			 a,
        float			 x,
        float			 y,
        float			 z,
        unsigned		 num)
{
        float			 xyz[3];
        unsigned		 k;

        LXx_VSET3 (xyz, x, y, z);
        for (k = 0; k < 3; k++)
                FarrayABp (a[k], xyz[k], num);
}

        void
VarrayAXYZvecx (
        Varray			 a,
        float			 x,
        float			 y,
        float			 z,
        unsigned		 num)
{
        float			 xyz[3];
        unsigned		 k;

        LXx_VSET3 (xyz, x, y, z);
        for (k = 0; k < 3; k++)
                FarrayABx (a[k], xyz[k], num);
}

        void
VarrayMatrix4Multiply (
        Varray			 r,
        LXtMatrix4		 m,
        VarrayC			 v,
        unsigned		 num)
{
        unsigned		 j;

        for (j = 0; j < 3; j++)
                FarrayABxABxpABxpBpR (r[j],
                                        v[0], static_cast<float>(m[0][j]),
                                        v[1], static_cast<float>(m[1][j]),
                                        v[2], static_cast<float>(m[2][j]),
                                              static_cast<float>(m[3][j]), num);
}

                }; // END namespace

