/*
 * Plug-in SDK Source: Math Utilities
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
#include <lxu_math.hpp>
#include <lxu_vector.hpp>
#include <lxu_matrix.hpp>

CLxBoundingBox::CLxBoundingBox ( const CLxVectorT<double> &min,
                                        const CLxVectorT<double> &max ) {
        _valid = false;
        add (min);
        add (max);
}

CLxBoundingBox&
CLxBoundingBox::add (	const CLxVectorT<double> &vec) {
        add (vec.v);
        return *this;
}

void
CLxBoundingBox::transform( const CLxMatrix4 &mat ) {
        CLxVector min(_min);
        CLxVector max(_max);
        
        clear();
        
        add( min * mat );
        add( CLxVector( max.x(), min.y(), min.z() ) * mat );
        add( CLxVector( min.x(), min.y(), max.z() ) * mat );
        add( CLxVector( max.x(), min.y(), max.z() ) * mat );
        
        add( max * mat );
        add( CLxVector( max.x(), max.y(), min.z() ) * mat );
        add( CLxVector( min.x(), max.y(), max.z() ) * mat );
        add( CLxVector( min.x(), max.y(), min.z() ) * mat );
}


CLxVector
CLxBoundingBox::center() const {
        CLxVector cen ;
        center( cen );
        return cen;
}


CLxVector
CLxBoundingBox::min() const {
        lx_err::check (_valid);
        CLxVector cen( _min ) ;
        return cen ;
}


CLxVector
CLxBoundingBox::max() const {
        lx_err::check (_valid);
        return CLxVector( _max ) ;
}


CLxVector
CLxBoundingBox::extent() const {
        CLxVector ext ;
        extent( ext );
        return ext ;
}

double
CLxBoundingBox::closeCorner( const CLxVectorT<double> &pos ) const {
        return closeCorner( pos.v ) ;
}

double
CLxBoundingBox::farCorner( const CLxVectorT<double> &pos ) const {
        return farCorner( pos.v ) ;
}

bool
CLxBoundingBox::test( const CLxVectorT<double> &vec ) const {
        return test( vec.v );
}

bool
CLxBoundingBox::test( const CLxBoundingBox &bbox ) const {
        return test( bbox._min, bbox._max );
}

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
        float			 val)
{
        /*
         * Testing IEEE floating point numbers means looking at the bit pattern for
         * wacky values.  If the exponent is 255 then the mantissa can be used to
         * discriminate between NAN values and infinite values.
         */
        unsigned int		 n, exp, mant;

        n = ((unsigned int *) &val) [0];
        exp = (n & 0x7F800000) >> 23;
        if (exp != 255)
                return 0;

        mant = (n & 0x007FFFFF);
        if (mant != 0)
                return -1;	// NAN
        else
                return +1;	// INFINITY
}

/*
 * This function returns a tolerance value for any given input. The value returned
 * will be a positive number which is much smaller in magnitude than the input,
 * representing the minimum change required to make this value different.
 */

        double
Tolerance (
        double			 m)
{
        if (m < 0.0)
                m /= -3.36e6;
        else
                m /=  3.36e6;

        if (m > 1.0e-10)
                return (m);
        
        return 1.0e-10;
}

/*
 * The compare functions take two values and return 1 if a is greater than b, -1
 * if a is less than b, and zero if they are equal. The equivalence test takes
 * the numeric tolerance for each value into account, so values that are slightly
 * different can still return zero if the difference is not significant.
 */

        int
Compare (
        double			 a,
        double			 b)
{
        double			 x = 0.0, y = 0.0;

        x = fabs (a);
        y = fabs (b);
        
        if (y > x)
                x = y;

        y = Tolerance (x);
        x = a - b;

        return (x > -y) - (x < y);
}

};	// End Namespace lx
