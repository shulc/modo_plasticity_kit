/*
 * Plug-in SDK Header: Math Utilities
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
 * Provides math utility functions for C++ plug-ins.
 */

#ifndef LXU_MATH_HPP
#define LXU_MATH_HPP

#include <lxvmath.h>
#include <lx_util.hpp>
#include <lxu_vector.hpp>
#include <vector>


/*
 * ----------------------------------------------------------
 * "lx" namespace for utility functions.
 */
                namespace lx {


/*
 * IEEE floating point numbers actually store the results of irrational math
 * operations.  This function can be used to test a 32-bit float for weird
 * conditions.  It returns 0 for a valid number, -1 for an invalid number, and
 * +1 for infinity.
 */
        int
IEEEFloatTest (
        float			 val);

/*
 * This function returns a tolerance value for any given input. The value returned
 * will be a positive number which is much smaller in magnitude than the input,
 * representing the minimum change required to make this value different.
 */

        double
Tolerance (
        double			 m);

/*
 * The compare functions take two values and return 1 if a is greater than b, -1
 * if a is less than b, and zero if they are equal. The equivalence test takes
 * the numeric tolerance for each value into account, so values that are slightly
 * different can still return zero if the difference is not significant.
 */

#define LXi_LESS_THAN		 -1
#define LXi_EQUAL_TO		  0
#define LXi_GREATER_THAN	  1

        int
Compare (
        double			 a,
        double			 b);


/*
 * Templates for making ident matrices.
 */
        template <class M>
        void
MatrixIdent (
        M			 dst)
{
        int			 i, j;

        for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                        dst[i][j] = (i == j ? 1.0 : 0.0);
}

        template <class M>
        void
Matrix4Ident (
        M			 dst)
{
        int			 i, j;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        dst[i][j] = (i == j ? 1.0 : 0.0);
}


/*
 * Template for copying a 3x3 matrix. The types are a bit weird, but so is C++.
 */
        template <class F, class M>
        void
MatrixCopy (
        F		       (*dst)[3],
        const M	&		 src)
{
        int			 i, j;

        for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                        dst[i][j] = src[i][j];
}

/*
 * This flips the matrix around the diagonal.
 *
 */
        template <class M>
        void
MatrixTranspose (
        M			&m)
{
        double			 t;

        t       = m[0][1];
        m[0][1] = m[1][0];
        m[1][0] = t;

        t       = m[2][1];
        m[2][1] = m[1][2];
        m[1][2] = t;

        t       = m[0][2];
        m[0][2] = m[2][0];
        m[2][0] = t;
}

/*
 * A 3x3 matrix can be placed into a 4x4 matrix with this function. The translation
 * row in the destination matrix is not affected. Set the transpose flag if the source
 * matrix was made with the 3x3 matrix functions.
 */
        template <class M4, class M>
        void
Matrix4SetSubMatrix (
        M4			&m4,
        const M			&m3,
        bool			 transpose)
{
        int			 i, j;

        if (transpose) {
                M                   tmp;

                MatrixCopy (tmp, m3);
                MatrixTranspose (tmp);

                for (i = 0; i < 3; i++)
                        for (j = 0; j < 3; j++)
                                m4[i][j] = tmp[i][j];
        }
        else {
                for (i = 0; i < 3; i++)
                        for (j = 0; j < 3; j++)
                                m4[i][j] = m3[i][j];
        }
}

        template <class M4, class M>
        void
Matrix4GetSubMatrix (
        const M4		&m4,
        M			&m3,
        bool			 transpose)
{
        int			 i, j;
        
        if (transpose) {
                M                   tmp;
                for (i = 0; i < 3; i++)
                        for (j = 0; j < 3; j++)
                                tmp[i][j] = m4[i][j];
                
                MatrixTranspose (tmp);
                MatrixCopy (m3, tmp);
        }
        else {
                for (i = 0; i < 3; i++)
                        for (j = 0; j < 3; j++)
                                m3[i][j] = m4[i][j];
        }
}
                        

/*
 * Template for multiplying a vector times a matrix, in our unusual order.
 *
 *	r = m * x;
 */
        template <class M, class VIN, class VOUT>
        void
MatrixMultiply (
        VOUT			 r,
        const M			 m,
        const VIN		 x)
{
        int			 i, j;
        double			 d;

        for (i = 0; i < 3; i++)
        {
                d = 0.0;
                for (j = 0; j < 3; j++)
                        d += x[j] * m[i][j];

                r[i] = d;
        }
}


/*
 * Template for multiplying a matrix by another matrix.
 *
 *	M = M * X;
 */
        template <class M>
        void
MatrixMultiply (
        M			 m,
        const M			 x)
{
        LXtMatrix4		 tmp;
        int			 i, j, k;

        for (i = 0; i < 3; i++)
                LXx_VCLR (tmp[i]);

        for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                        for (k = 0; k < 3; k++)
                                tmp[i][j] += m[k][j] * x[i][k];

        for (i = 0; i < 3; i++)
                LXx_VCPY (m[i], tmp[i]);
}


/*
 * Template for copying a 4x4 matrix.
 */
        template <class M>
        void
Matrix4Copy (
        M			 dst,
        const M			 src)
{
        int			 i, j;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        dst[i][j] = src[i][j];
}


/*
 * Template for multiplying a 3-component vector times a 4x4 matrix. More
 * typical order this time.
 *
 *	r = m * x;
 */
        template <class M, class VIN, class VOUT>
        void
Matrix4Multiply (
        VOUT			 r,
        const M			 m,
        const VIN		 x)
{
        int			 i, j;
        double			 d, t[4];

        t[0] = x[0];
        t[1] = x[1];
        t[2] = x[2];
        t[3] = 1.0;
        for (i = 0; i < 3; i++)
        {
                d = 0.0;
                for (j = 0; j < 4; j++)
                        d += t[j] * m[j][i];

                r[i] = d;
        }
}


/*
 * Template for multiplying a 4x4 matrix by another matrix.
 *
 *	M = M * X;
 */
        template <class M>
        void
Matrix4Multiply (
        M			 m,
        const M			 x)
{
        LXtMatrix4		 tmp;
        int			 i, j, k;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        tmp[i][j] = 0.0;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        for (k = 0; k < 4; k++)
                                tmp[i][j] += m[i][k] * x[k][j];

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        m[i][j] = tmp[i][j];
}

        template <class M>
        void
MatrixRotate (
        M			&m,
        double			 angle,
        int			 axis)
{
        static const int	 axis0[] = { 1, 2, 0 };
        static const int	 axis1[] = { 2, 0, 1 };
        M			 rot;
        double			 s;
        int			 a, b;

        if (angle == 0.0)
                return;

        a = axis0[axis];
        b = axis1[axis];

        MatrixIdent (rot);

        s = sin (angle);
        rot[a][b] = -s;
        rot[b][a] =  s;
        rot[a][a] = rot[b][b] = cos (angle);
        MatrixMultiply (m, rot);
}

/*
 * Template to compute a new matrix that encodes a rotation about an arbitrary axis.
 * The angle is input as sine and cosine, which are sometimes easier to compute than
 * the actual angle.
 */
        template <class M, class V>
        void
MatrixAxisRotation (
        M			 m,
        V			 a,
        double			 s,
        double			 c)
{
        double			 t;

        t = 1.0 - c;
        m[0][0] = t * a[0] * a[0] + c;
        m[0][1] = t * a[0] * a[1] - s * a[2];
        m[0][2] = t * a[0] * a[2] + s * a[1];
        m[1][0] = t * a[1] * a[0] + s * a[2];
        m[1][1] = t * a[1] * a[1] + c;
        m[1][2] = t * a[1] * a[2] - s * a[0];
        m[2][0] = t * a[2] * a[0] - s * a[1];
        m[2][1] = t * a[2] * a[1] + s * a[0];
        m[2][2] = t * a[2] * a[2] + c;
}

/*
 * Template for calculating determinant of a 3x3 matrix.
 */
        template <class M>
        double
MatrixDeterminant (
        const M	&		 m)
{
        return
                (m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
                -m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
                +m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]));
}
                        
/*
 * Template for inverting a 4x4 matrix.
 */
        template <class M>
        void
MatrixInvert (const M input, M output)
{
        /*
         *	This function inverts a matrix 4.
         */
        
        LXtMatrix4			temp;
        double				inv_det = 0.0, det = 0.0;
        double				a0, a1, a2, a3, a4, a5, b0, b1, b2, b3, b4, b5;
        
        MatrixIdent (output);
        
        a0 = input[0][0] * input[1][1] - input[0][1] * input[1][0];
        a1 = input[0][0] * input[1][2] - input[0][2] * input[1][0];
        a2 = input[0][0] * input[1][3] - input[0][3] * input[1][0];
        a3 = input[0][1] * input[1][2] - input[0][2] * input[1][1];
        a4 = input[0][1] * input[1][3] - input[0][3] * input[1][1];
        a5 = input[0][2] * input[1][3] - input[0][3] * input[1][2];
        b0 = input[2][0] * input[3][1] - input[2][1] * input[3][0];
        b1 = input[2][0] * input[3][2] - input[2][2] * input[3][0];
        b2 = input[2][0] * input[3][3] - input[2][3] * input[3][0];
        b3 = input[2][1] * input[3][2] - input[2][2] * input[3][1];
        b4 = input[2][1] * input[3][3] - input[2][3] * input[3][1];
        b5 = input[2][2] * input[3][3] - input[2][3] * input[3][2];
        
        det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
        
        if (det == 0.0)
                return;
        
        temp[0][0] = + input[1][1] * b5 - input[1][2] * b4 + input[1][3] * b3;
        temp[1][0] = - input[1][0] * b5 + input[1][2] * b2 - input[1][3] * b1;
        temp[2][0] = + input[1][0] * b4 - input[1][1] * b2 + input[1][3] * b0;
        temp[3][0] = - input[1][0] * b3 + input[1][1] * b1 - input[1][2] * b0;
        temp[0][1] = - input[0][1] * b5 + input[0][2] * b4 - input[0][3] * b3;
        temp[1][1] = + input[0][0] * b5 - input[0][2] * b2 + input[0][3] * b1;
        temp[2][1] = - input[0][0] * b4 + input[0][1] * b2 - input[0][3] * b0;
        temp[3][1] = + input[0][0] * b3 - input[0][1] * b1 + input[0][2] * b0;
        temp[0][2] = + input[3][1] * a5 - input[3][2] * a4 + input[3][3] * a3;
        temp[1][2] = - input[3][0] * a5 + input[3][2] * a2 - input[3][3] * a1;
        temp[2][2] = + input[3][0] * a4 - input[3][1] * a2 + input[3][3] * a0;
        temp[3][2] = - input[3][0] * a3 + input[3][1] * a1 - input[3][2] * a0;
        temp[0][3] = - input[2][1] * a5 + input[2][2] * a4 - input[2][3] * a3;
        temp[1][3] = + input[2][0] * a5 - input[2][2] * a2 + input[2][3] * a1;
        temp[2][3] = - input[2][0] * a4 + input[2][1] * a2 - input[2][3] * a0;
        temp[3][3] = + input[2][0] * a3 - input[2][1] * a1 + input[2][2] * a0;
        
        inv_det = 1.0 / det;
        
        for (unsigned i=0; i<4; i++)
        {
                for (unsigned j=0; j<4; j++)
                {
                        temp[i][j] *= inv_det;
                }
        }
        
        Matrix4Copy (output, temp);
}
        
/*
 * Template for copying basis vectors into a 3x3 matrix.
 *
 */
        template <class M, class VIN>
        void
MatrixFromXYZ (
                M			 mat,
               const VIN		 x,
               const VIN		 y,
               const VIN		 z)
{
        mat[0][0] = x[0];
        mat[1][0] = x[1];
        mat[2][0] = x[2];
        mat[0][1] = y[0];
        mat[1][1] = y[1];
        mat[2][1] = y[2];
        mat[0][2] = z[0];
        mat[1][2] = z[1];
        mat[2][2] = z[2];
}

/*
 * Template for copying basis vectors into a 4x4 matrix.
 *
 */
        template <class M, class VIN>
        void
Matrix4FromXYZ (
               M			 m,
               const VIN		 x,
               const VIN		 y,
               const VIN		 z)
{
        LXtMatrix	 mat;
        Matrix4Ident(m);
        
        mat[0][0] = x[0];
        mat[1][0] = x[1];
        mat[2][0] = x[2];
        mat[0][1] = y[0];
        mat[1][1] = y[1];
        mat[2][1] = y[2];
        mat[0][2] = z[0];
        mat[1][2] = z[1];
        mat[2][2] = z[2];
        
        Matrix4SetSubMatrix (m, mat, 1); // set with transpose
        
}

/*
 * Template for copying the translation vector out of a matrix.
 *
 */
template <class M, class VOUT>
void
        Matrix4GetTranslation(
                M			 m,
                VOUT		&t)
{
        LXx_VCPY(t, m[3]);
}

/*
 * Normalize non-zero vectors and return the length.
 */
        template <class V>
        double
VectorNormalize (
        V			v)
{
        double		m, p;
        m = LXx_VDOT (v, v);
        if (m<=0)
                return 0;
        m = sqrt (m);
        p = 1.0 / m;
        LXx_VSCL (v, p);
        return m;
}


/*
 * Taking a value from zero to one, this returns a cubic smoothed version.
 */
        template <class F>
        F
Smooth (
        F			 a)
{
        return (3.0 - 2.0 * a) * a * a;
}

/*
 * Interpolate between four points using a cubic. p0, p1, p2, p3 are uniform
 * samples along a line. 'f' is the fraction between p1 and p2, from 0 to 1.
 */
        template <class F>
        F
CubicInterp (
        F			 p0,
        F			 p1,
        F			 p2,
        F			 p3,
        F			 f)
{
        F			 a0, a1, a2, a3;

        a0 =  p1;
        a1 = (-2.0 * p0 + p1 + 4.0 * p2 - p3) / 6.0;
        a2 = (p0 + p2) / 2.0 - p1;
        a3 = (-p0 - p1 - p2 + p3) / 6.0;

        return a0 + a1 * f + a2 * f * f + a3 * f * f * f;
}

                }; // END namespace lx


template <class T>
class CLxVectorT;
class CLxMatrix4;

/*
 * ----------------------------------------------------------------
 * Class for computing and managing bounding boxes.
 */
class CLxBoundingBox
{
    public:
        LXtVector			 _min, _max;
        bool				 _valid;

        /*
         * The valid flag is true only if the box has been set, and is
         * false initially. It can also be cleared to start computing the
         * bounds of a set of points.
         */
        CLxBoundingBox ()
        {
                _valid = false;
        }
        
        CLxBoundingBox ( 	const CLxVectorT<double> &min,
                            const CLxVectorT<double> &max ) ;
        
        
                bool
        isSet ()
        {
                return _valid;
        }

                void
        clear ()
        {
                _valid = false;
        }

        /*
         * Points or other boxes can be added to the box to initially set or
         * to increase its size.
         */
                template <class T>
                void
        add (
                const T			*pos)
        {
                if (_valid)
                {
                        LXx_VBOP (_min, pos, LXxMIN);
                        LXx_VBOP (_max, pos, LXxMAX);

                } else
                {
                        LXx_VCPY (_min, pos);
                        LXx_VCPY (_max, pos);
                        _valid = true;
                }
        }

                template <class T>
                void
        add (
                T			 x,
                T			 y,
                T			 z)
        {
                T			 vec[3];

                vec[0] = x;
                vec[1] = y;
                vec[2] = z;
                add (vec);
        }

                void
        add (
                const CLxBoundingBox	&box)
        {
                add (box._min);
                add (box._max);
        }

        void
        add (
             const LXtBBox		&box)
        {
                add (box.min);
                add (box.max);
        }
        
        CLxBoundingBox&
        add (	const CLxVectorT<double> &vec) ;
        
        
        void transform( const CLxMatrix4 &mat ) ;
        
                void
        set (
                const LXtBBox		&box)
        {
                LXx_VCPY (_min, box.min);
                LXx_VCPY (_max, box.max);
                _valid = true;
        }

                void
        inflate (
                double			 size)
        {
                lx_err::check (_valid);
                _min[0] -= size;
                _min[1] -= size;
                _min[2] -= size;
                _max[0] += size;
                _max[1] += size;
                _max[2] += size;
        }

        /*
         * The box can be read as a standard C SDK box, or other attributes
         * can be computed.
         */
                void
        get (
                LXtBBox			&box) const
        {
                lx_err::check (_valid);
                LXx_VCPY (box.min, _min);
                LXx_VCPY (box.max, _max);
                center (box.center);
                extent (box.extent);
        }

                void
        get (
                LXtBBox			*box) const
        {
                get (*box);
        }

                void
        center (
                LXtVector		 cen) const
        {
                lx_err::check (_valid);
                LXx_VADD3 (cen, _min, _max);
                LXx_VSCL  (cen, 0.5);
        }

        CLxVectorT<double> center() const ;
        CLxVectorT<double> min() const ;
        CLxVectorT<double> max() const ;
        CLxVectorT<double> extent() const ;
        bool test( const CLxVectorT<double> &vec ) const ;
        bool test( const CLxBoundingBox &bbox ) const ;

        void
        extent (
                LXtVector		 ext) const
        {
                lx_err::check (_valid);
                LXx_VSUB3 (ext, _min, _max);
                LXx_VUOP  (ext, fabs);
        }

                unsigned
        longAxis () const
        {
                LXtVector		 ext;

                extent (ext);
                if (ext[0] > ext[1])
                        return (ext[0] > ext[2] ? 0 : 2);
                else
                        return (ext[1] > ext[2] ? 1 : 2);
        }

                unsigned
        shortAxis () const
        {
                LXtVector		 ext;

                extent (ext);
                if (ext[0] < ext[1])
                        return (ext[0] < ext[2] ? 0 : 2);
                else
                        return (ext[1] < ext[2] ? 1 : 2);
        }

        /*
         * The closest and farthest corners from a given position are given 
         * as distances. The box is fully outside the close distance and
         * fully inside the far distance.
         */
        
        double closeCorner( const CLxVectorT<double> &pos) const ;

        
                template <class T>
                double
        closeCorner (
                const T			*pos) const
        {
                double			 d, d2;

                lx_err::check (_valid);

                d2 = 0.0;
                for (int i = 0; i < 3; i++)
                {
                        d   = LXxMAX (_min[i] - pos[i], pos[i] - _max[i]);
                        d   = LXxMAX (d, 0);
                        d2 += d * d;
                }
                return sqrt (d2);
        }

        double farCorner( const CLxVectorT<double> &pos) const ;
        
        
                template <class T>
                double
        farCorner (
                const T			*pos) const
        {
                double			 a, b, d2;

                lx_err::check (_valid);

                d2 = 0.0;
                for (int i = 0; i < 3; i++)
                {
                        a   = pos[i] - _min[i];
                        b   = pos[i] - _max[i];
                        d2 += LXxMAX (a * a, b * b);
                }
                return sqrt (d2);
        }

        /*
         * Testing against a box returns true if the point or other box touch
         * this box.
         */
                template <class T>
                bool
        test (
                T			*pos) const
        {
                lx_err::check (_valid);
                return	   (pos[0] >= _min[0] && pos[0] < _max[0])
                        && (pos[1] >= _min[1] && pos[1] < _max[1])
                        && (pos[2] >= _min[2] && pos[2] < _max[2]) ;
        }

                template <class T>
                bool
        test (
                T			*min,
                T			*max) const
        {
                lx_err::check (_valid);
                return	   (min[0] < _max[0] && max[0] <= _min[0])
                        && (min[1] < _max[1] && max[1] <= _min[1])
                        && (min[2] < _max[2] && max[2] <= _min[2]) ;
        }

        template <class T>
        bool
        test (
                T			 x,
                T			 y,
                T			 z ) const
        {
                lx_err::check (_valid);
                return	   (x >= _min[0] && x < _max[0])
                && (y >= _min[1] && y < _max[1])
                && (z >= _min[2] && z < _max[2]) ;
        }
        
        
        /*
         * Since the tableau box varient is just an array of 6 floats it can get
         * caught by the template above. As result the methods for this type of
         * box have different names.
         */
                void
        addBox6 (
                const float		*box)
        {
                LXtFVector	 t;

                LXx_VSET3 (t, box[0], box[1], box[2]);
                add (t);
                LXx_VSET3 (t, box[3], box[4], box[5]);
                add (t);
        }

                void
        setBox6 (
                const float		*box)
        {
                LXx_VSET3 (_min, box[0], box[1], box[2]);
                LXx_VSET3 (_max, box[3], box[4], box[5]);
                _valid = true;
        }

                bool
        testBox6 (
                float			*box) const
        {
                return test (&box[0], &box[3]);
        }

                void
        getBox6 (
                float			*box) const
        {
                lx_err::check (_valid);
                box[0] = (float)_min[0];
                box[1] = (float)_min[1];
                box[2] = (float)_min[2];
                box[3] = (float)_max[0];
                box[4] = (float)_max[1];
                box[5] = (float)_max[2];
        }
        
                double
        volume() const
        {
                return (_max[0] - _min[0]) * (_max[1] - _min[1]) * (_max[2] - _min[2]);
        }
};

/*
 * ----------------------------------------------------------------
 * Class for computing centroid and axis from a set of positions.
 */
class CLxPositionData
{
    public:
        std::vector <CLxVector>		 _positions;
        CLxVector			 _cachedCtr;
        bool				 _cacheValid;
        
                bool
        isSet ()
        {
                return _positions.size() > 0;
        }

                void
        clear ()
        {
                _positions.clear();
        }

        /*
         * Points can be added to the data
         */

                void
        add (	const CLxVectorT<double> &vec)
        {
                CLxVector	p(vec);
                _positions.push_back(p);
                _cacheValid = false;
        }

                template <class T>
                void
        add (
                T			 x,
                T			 y,
                T			 z)
        {
                CLxVector	p(x,y,z);
                add(p);
        }

                template <class T>
                void
        add (
                T			 x,
                T			 y)
        {
                CLxVector	p(x,y,0.0);
                add(p);
        }

        /*
         * Set a CLxBoundingBox using previously added points
         */
                void
        setBBox (CLxBoundingBox &box)
        {
                for (int i = 0; i < _positions.size(); i++)
                        box.add(_positions[i]);
        }


                CLxVector
        center (void) 
        {
                CLxVector	 c(0,0,0);
                int		 i, n = _positions.size();

                if (_cacheValid)
                        return _cachedCtr;

                if (!n)
                        return c;

                for (i=0; i<n; i++) 
                        c += _positions[i];

                c /= n;
                _cachedCtr = CLxVector(c);
                _cacheValid = true;
                return c;
        }
                
                CLxVector
        axis (void)
        {
                CLxVector	 r, ctr, axis(0,0,0);
                double		 xx(0), xy(0), xz(0), yy(0), yz(0), zz(0);
                double		 detX, detY, detZ, detMax(0);
                int		 i, n = _positions.size();
        
                
                if (n < 3)
                        return axis;

                ctr = center();

                for (i=0; i<n; i++) {
                        r = _positions[i] - ctr;
                        xx += r[0] * r[0];
                        xy += r[0] * r[1];
                        xz += r[0] * r[2];
                        yy += r[1] * r[1];
                        yz += r[1] * r[2];
                        zz += r[2] * r[2];
                }

                detX = yy*zz - yz*yz;
                if (detX > detMax) {
                        axis.set(detX, xz*yz - xy*zz, xy*yz - xz*yy);
                        detMax = detX;
                }

                detY = xx*zz - xz*xz;
                if (detY > detMax) {
                        axis.set(xz*yz - xy*zz, detY, xy*xz - yz*xx);
                        detMax = detY;
                }
                detZ = xx*yy - xy*xy;
                if (detZ > detMax) 
                        axis.set(xy*yz - xz*yy, xy*xz - yz*xx, detZ);

                if (axis.length() > DBL_EPSILON)
                        axis.normalize();
                return axis;
        }

        /*
         * 2D axes are computed a little differently
         */
                CLxVector
        axis2D (void)
        {
                CLxVector	 r, ctr, axis(0,0,0);
                double		 xx(0), xy(0);
                int		 i, n = _positions.size();
        
                if (n < 2)
                        return axis;

                ctr = center();

                for (i=0; i<n; i++) {
                        r = _positions[i] - ctr;
                        xx += r[0] * r[0];
                        xy += r[0] * r[1];
                }

                axis.set(xy, -xx, 0.0);

                if (axis.length() > FLT_EPSILON)
                        axis.normalize();
                return axis;
        }
};


/*
 * ----------------------------------------------------------------
 * Class for computing various types of smoothing profiles over a
 * zero-to-one range.
 */
#define LXfEASE_NEGATIVE	0x01
#define LXfEASE_DOUBLE		0x02

#define LXiESHP_LINEAR		 0
#define LXiESHP_EASE_IN		 1
#define LXiESHP_EASE_OUT	 2
#define LXiESHP_SMOOTH		 3

class CLxEaseFraction
{
    public:
        double			 p0;
        double			 p1;
        int			 flags;

        CLxEaseFraction()
        {
                p0 = 1.0;
                p1 = 1.0;
                flags = 0;
        }

                template <class F>
                void
        hermite (
                F			 t,
                F			 h[4])
        {
                F			 t2, t3, z;

                t2 = t * t;
                t3 = t * t2;
                z = 3.0 * t2 - t3 - t3;

                h[0] = 1.0 - z;
                h[1] = z;
                h[2] = t3 - t2 - t2 + t;
                h[3] = t3 - t2;
        }

        /*
         * Set the shape to one of the LXiESHP presets.
         */
                void
        set_shape (
                int			 shape)
        {
                int			 sp0[] = { 1, 2, 0, 0 };
                int			 sp1[] = { 1, 0, 2, 0 };

                if ((shape >= 0) && (shape < 4))
                {
                        p0 = sp0[shape];
                        p1 = sp1[shape];
                }
        }

        /*
         * Given a input generate an eased output.
         */
                template <class F>
                F
        evaluate (
                F			x) 
        {
                F			 hc[4];

                if (flags & LXfEASE_DOUBLE)
                        x = LXxABS (x);

                if (flags & LXfEASE_NEGATIVE)
                        x = 1.0 - x;

                if (x >= 1.0)
                        return 1.0;
                else if (x <= 0.0)
                        return 0.0;

                hermite (x, hc);
                return hc[1] + p0 * hc[2] + p1 * hc[3];
        }
};


/*
 * ----------------------------------------------------------------
 * Class for generating pseudo-random numbers of various types.
 */
class CLxPseudoRandom {
        static const int	 ARAND = 16807;
        static const int	 MRAND = 2147483647;
        static const int	 QRAND = 127773;
        static const int	 RRAND = 2836;
    public:
        int			 random_seed;

        CLxPseudoRandom ()
        {
                random_seed = 3216913;
        }

        CLxPseudoRandom (
                int		 seedInit)
        {
                seed (seedInit);
        }

                void
        seed (
                int		 seed)
        {
                random_seed = LXxMAX (1, seed);
        }

        /*
         * Get a random number from 0.0 to just less than 1.0.
         */
                float
        uniform ()
        {
                int		 hi, lo, test;

                hi = random_seed / QRAND;
                lo = random_seed % QRAND;
                test = ARAND * lo - RRAND * hi;
                random_seed = (test > 0) ? test : test + MRAND;
                return static_cast<float>((random_seed * (1.0 / (float) MRAND)));
        }

        /*
         * Get a random number from zero to just less than 'n'.
         */
                template<class T>
                T
        range (
                T		 n)
        {
                return (T)(uniform () * n);
        }

        /*
         * Get a random number from 'low' to just less than 'high'.
         */
                template<class T>
                T
        range (
                T		 low,
                T		 high)
        {
                return low + range (high - low);
        }

        /*
         * Get a uniform random number centered on zero, from -1.0 to 1.0.
         */
                float
        centered ()
        {
                return uniform () * 2 - 1;
        }

        /*
         * Vary a base value by +/- delta.
         */
                float
        vary (
                float		 base,
                float		 delta)
        {
                return base + delta * centered ();
        }

        /*
         * Get a random number in an approximately normal (Gaussian)
         * distribution with stddev of 1.0.  (Box-Muller transform)
         */
                double
        normal ()
        {
                float		 u = centered ();
                float		 v = centered ();
                double		 r, c;

                r = u * u + v * v;
                if (r == 0 || r > 1)
                        return normal ();

                c = sqrt (-2.0 * log (r) / r);
                return u * c;
        }

        /*
         * Get a random integer in an approximately Poisson distribution
         * with a given lambda (average rate).
         *
         * For small lambda we use Knuth's iterative method. For large
         * numbers where interation takes too long and exp(-lambda) gets
         * too close to zero to be useful, we switch to a Gaussian
         * approximation.
         */
                unsigned
        poisson (
                double		 lambda)
        {
                double		 limit, p;
                int		 n;

                if (lambda > 60.0)
                {
                        n = (int) (lambda + sqrt (lambda) * normal ());
                        return (n > 0 ? n : 0);
                }

                limit = exp ( -lambda );
                p     = 1.0;
                n     = 0;

                while (limit > 0.0)	// prevents hangs on bad input
                {
                        p *= uniform ();
                        if (p < limit)
                                break;
                        n++;
                }
                return n;
        }

        /*
         * Generate a barycentric coordinate, which is just a vector where
         * the components are all 0-1 and sum to 1.
         */
                void
        barycentric (
                LXtVector	 b)
        {
                while (1)
                {
                        b[0] = uniform ();
                        b[1] = uniform ();
                        b[2] = 1.0 - b[0] - b[1];
                        if (b[2] >= 0.0)
                                return;
                }
        }

        /*
         * Get a random point in a unit sphere. This is done by generating
         * points in a cube until we get one inside the sphere. The square
         * of the vector length is returned, and cannot be zero.
         */
                double
        sphere (
                LXtVector	 p)
        {
                double		 r2;

                while (1)
                {
                        LXx_VSET3 (p, centered (), centered (), centered ());
                        r2 = LXx_VDOT (p, p);
                        if (r2 <= 1.0)
                                return r2;
                }
        }
};


/*
 * ----------------------------------------------------------------
 * Class for generating Perlin-style smooth deterministic noise. This
 * implementation was adapted from code submitted to the FlipCode archive
 * by John Ratcliff, which was adapted from code by Ken Perlin.
 *
 * http://www.flipcode.com/archives/Perlin_Noise_Class.shtml
 */
template<class T>
class CLxPerlin
{
    public:

        CLxPerlin (
                int		 octaves = 4,
                T		 freq    = 1,
                T		 amp     = 1,
                int		 seed    = 94) 
        {
                mOctaves   = octaves;
                mFrequency = freq;
                mAmplitude = amp;

                init(seed);
        }

                T
        eval (
                T		 x)
        {
                return noise_1D(x);
        }

                T
        eval (
                T		 x,
                T		 y)
        {
                T		 vec[2];

                vec[0] = x;
                vec[1] = y;

                return noise_2D(vec);
        }

                T
        eval (
                T		 x,
                T		 y,
                T		 z)
        {
                T		 vec[3];

                vec[0] = x;
                vec[1] = y;
                vec[2] = z;

                return noise_3D(vec);
        }

                T
        eval (
                const LXtVector		 pos)
        {
                return eval (pos[0], pos[1], pos[2]);
        }

                T
        eval (
                const LXtFVector	 pos)
        {
                return eval (pos[0], pos[1], pos[2]);
        }

private:
        static const unsigned	 SAMPLE_SIZE	= 1024;
        static const unsigned	 N		= 0x1000;
        static const unsigned	 NP		= 12;   /* 2^N */
        static const unsigned	 NM		= 0xfff;
        static const unsigned	 B		= SAMPLE_SIZE;
        static const unsigned	 BM		= SAMPLE_SIZE - 1;

        int		 mOctaves;
        T		 mFrequency;
        T		 mAmplitude;

        int		 p [SAMPLE_SIZE + SAMPLE_SIZE + 2];
        T		 g3[SAMPLE_SIZE + SAMPLE_SIZE + 2][3];
        T		 g2[SAMPLE_SIZE + SAMPLE_SIZE + 2][2];
        T		 g1[SAMPLE_SIZE + SAMPLE_SIZE + 2];

                T
        noise_1D (
                T		 val)
        {
                T		 amp    = mAmplitude;
                T		 result = 0.0;

                val *= mFrequency;

                for( int i = 0; i < mOctaves; i++ )
                {
                        result += noise1(val) * amp;
                        val    *= 2.0;
                        amp    *= 0.5;
                }

                return result;
        }

                T
        noise_2D (
                T		 vec[2])
        {
                T		 amp    = mAmplitude;
                T		 result = 0.0;

                vec[0] *= mFrequency;
                vec[1] *= mFrequency;

                for( int i = 0; i < mOctaves; i++ )
                {
                        result += noise2(vec) * amp;
                        vec[0] *= 2.0;
                        vec[1] *= 2.0;
                        amp    *= 0.5;
                }

                return result;
        }

                T
        noise_3D (
                T		 vec[3])
        {
                T		 amp    = mAmplitude;
                T		 result = 0.0;

                vec[0] *= mFrequency;
                vec[1] *= mFrequency;
                vec[2] *= mFrequency;

                for( int i = 0; i < mOctaves; i++ )
                {
                        result += noise3(vec) * amp;
                        vec[0] *= 2.0;
                        vec[1] *= 2.0;
                        vec[2] *= 2.0;
                        amp    *= 0.5;
                }

                return result;
        }

                T
        s_curve (
                T		 t)
        {
                return t * t * (3.0 - 2.0 * t);
        }

                T
        lerp (
                T		 t,
                T		 a,
                T		 b)
        {
                return a + t * (b - a);
        }

                void
        setup (
                T		 t,
                int		&b0,
                int		&b1,
                T		&r0,
                T		&r1)
        {
                t += N;
                b0 = ((int) t) & BM;
                b1 = (b0 + 1)  & BM;
                r0 = t - (int)t;
                r1 = r0 - 1.0;
        }

                T
        at2 (
                T		 rx,
                T		 ry,
                int		 b)
        {
                return rx * g2[b][0] + ry * g2[b][1];
        }

                T
        at3 (
                T		 rx,
                T		 ry,
                T		 rz,
                int		 b)
        {
                return rx * g3[b][0] + ry * g3[b][1] + rz * g3[b][2];
        }

                T
        noise1 (
                T		 arg)
        {
                int		 bx0, bx1;
                T		 rx0, rx1, sx, u, v;

                setup(arg, bx0,bx1, rx0,rx1);

                sx = s_curve(rx0);

                u = rx0 * g1[ p[ bx0 ] ];
                v = rx1 * g1[ p[ bx1 ] ];

                return lerp(sx, u, v);
        }

                T
        noise2 (
                T		 vec[2])
        {
                int		 bx0, bx1, by0, by1, b00, b10, b01, b11;
                T		 rx0, rx1, ry0, ry1, sx, sy, a, b, u, v;
                int		 i, j;

                setup(vec[0],bx0,bx1,rx0,rx1);
                setup(vec[1],by0,by1,ry0,ry1);

                i = p[bx0];
                j = p[bx1];

                b00 = p[i + by0];
                b10 = p[j + by0];
                b01 = p[i + by1];
                b11 = p[j + by1];

                sx = s_curve(rx0);
                sy = s_curve(ry0);

                u = at2(rx0,ry0,b00);
                v = at2(rx1,ry0,b10);
                a = lerp(sx, u, v);

                u = at2(rx0,ry1,b01);
                v = at2(rx1,ry1,b11);
                b = lerp(sx, u, v);

                return lerp(sy, a, b);
        }

                T
        noise3 (
                T		 vec[3])
        {
                int		 bx0, bx1, by0, by1, bz0, bz1, b00, b10, b01, b11;
                T		 rx0, rx1, ry0, ry1, rz0, rz1, sy, sz, a, b, c, d, t, u, v;
                int		 i, j;

                setup(vec[0], bx0,bx1, rx0,rx1);
                setup(vec[1], by0,by1, ry0,ry1);
                setup(vec[2], bz0,bz1, rz0,rz1);

                i = p[ bx0 ];
                j = p[ bx1 ];

                b00 = p[ i + by0 ];
                b10 = p[ j + by0 ];
                b01 = p[ i + by1 ];
                b11 = p[ j + by1 ];

                t  = s_curve(rx0);
                sy = s_curve(ry0);
                sz = s_curve(rz0);

                u = at3(rx0,ry0,rz0,b00 + bz0);
                v = at3(rx1,ry0,rz0,b10 + bz0);
                a = lerp(t, u, v);

                u = at3(rx0,ry1,rz0,b01 + bz0);
                v = at3(rx1,ry1,rz0,b11 + bz0);
                b = lerp(t, u, v);

                c = lerp(sy, a, b);

                u = at3(rx0,ry0,rz1,b00 + bz1);
                v = at3(rx1,ry0,rz1,b10 + bz1);
                a = lerp(t, u, v);

                u = at3(rx0,ry1,rz1,b01 + bz1);
                v = at3(rx1,ry1,rz1,b11 + bz1);
                b = lerp(t, u, v);

                d = lerp(sy, a, b);

                return lerp(sz, c, d);
        }

                void
        normalize2 (
                T		 v[2])
        {
                T		 s;

                s = (T)sqrt(v[0] * v[0] + v[1] * v[1]);
                s = 1.0 / s;

                v[0] = v[0] * s;
                v[1] = v[1] * s;
        }

                void
        normalize3 (
                T		 v[3])
        {
                T		 s;

                s = (T)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
                s = 1.0 / s;

                v[0] = v[0] * s;
                v[1] = v[1] * s;
                v[2] = v[2] * s;
        }

                void
        init (
                int		 seed)
        {
                CLxPseudoRandom	 psr (seed);
                int		 i, j, k;

                for (i = 0 ; i < B ; i++)
                {
                        p[i] = i;

                        g1[i] = psr.centered();

                        for (j = 0 ; j < 2 ; j++)
                                g2[i][j] = psr.centered();

                        normalize2(g2[i]);

                        for (j = 0 ; j < 3 ; j++)
                                g3[i][j] = psr.centered();

                        normalize3(g3[i]);
                }

                while (--i)
                {
                        j    = psr.range((int)B);
                        k    = p[i];
                        p[i] = p[j];
                        p[j] = k;
                }

                for (i = 0 ; i < B + 2 ; i++)
                {
                        p [B + i] = p[i];
                        g1[B + i] = g1[i];
                        for (j = 0 ; j < 2 ; j++)
                                g2[B + i][j] = g2[i][j];
                        for (j = 0 ; j < 3 ; j++)
                                g3[B + i][j] = g3[i][j];
                }
        }
};


#endif // LXU_MATH_HPP

