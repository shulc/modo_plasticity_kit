        /*
 * Plug-in SDK Header: Vector Wrapper
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
 * vector
 */
#include <lxu_result.hpp>
#include <lxu_matrix.hpp>
#include <lxu_vector.hpp>
#include <lxu_math.hpp>

#include <sstream>
#include <ostream>
#include <cmath>
#include <cfloat>
#include <stdio.h>

template <class T>
CLxVectorT<T>::CLxVectorT() {
        LXx_VCLR( v );
}

template <class T>
CLxVectorT<T>::CLxVectorT(T xx, T yy, T zz ) {
        LXx_VSET3(v, xx, yy, zz);
}

template <class T>
CLxVectorT<T>::CLxVectorT(const float mV[3]) {
        LXx_VCPY(v, mV);
}

template <class T>
CLxVectorT<T>::CLxVectorT(const double mV[3]) {
        LXx_VCPY(v, mV);
}

template <class T>
CLxVectorT<T>::CLxVectorT(const CLxVectorT<float> &other) {
        LXx_VCPY(v, other.v);
}

template <class T>
CLxVectorT<T>::CLxVectorT(const CLxVectorT<double> &other) {
        LXx_VCPY(v, other.v);
}


template <class T>
void
CLxVectorT<T>::set(T xx, T yy, T zz ) {
        LXx_VSET3(v, xx, yy, zz);
}

template <class T>
void
CLxVectorT<T>::set(T val) {
        LXx_VSET3(v, val, val, val);
}

template <class T>
void
CLxVectorT<T>::clear() {
        set((T)0);
}


template <class T>
CLxVectorT<T> &
CLxVectorT<T>::operator= (const CLxVectorT &other) {
        LXx_VCPY(v, other.v);
        return *this;
}

template <class T>
CLxVectorT<T>
CLxVectorT<T>::cross (const CLxVectorT<T> &other) const {
        return CLxVectorT(	v[1] * other.v[2] - v[2] * other.v[1],
                                v[2] * other.v[0] - v[0] * other.v[2],
                                v[0] * other.v[1] - v[1] * other.v[0] );
}

template <class T>
T
CLxVectorT<T>::dot (const CLxVectorT<T> &other) const {
        return LXx_VDOT(v, other.v);
}

// math operators

template <class T>
CLxVectorT<T>
CLxVectorT<T>::operator-() const {
        return CLxVectorT( -v[0], -v[1], -v[2] );
}

template <class T>
CLxVectorT<T>&
CLxVectorT<T>::operator+= (const CLxVectorT &other ) {
        LXx_VADD(v, other.v);
        return *this;
}


template <class T>
//template <typename U>
CLxVectorT<T>
CLxVectorT<T>::operator+ (const CLxVectorT &other) const {
        return CLxVectorT(	v[0] + other.v[0],
                                v[1] + other.v[1],
                                v[2] + other.v[2] );
}




template <class T>
CLxVectorT<T>&
CLxVectorT<T>::operator-= (const CLxVectorT &other ) {
        LXx_VSUB(v, other.v);
        return *this;
}

template <class T>
CLxVectorT<T>
CLxVectorT<T>::operator-( const CLxVectorT &other ) const {
        return CLxVectorT(	v[0] - other.v[0],
                                v[1] - other.v[1],
                                v[2] - other.v[2]);
}

template <class T>
CLxVectorT<T>&
CLxVectorT<T>::operator*=( T s ) {
        LXx_VSCL(v, s);
        return *this;
}

template <class T>
CLxVectorT<T>
CLxVectorT<T>::operator*( T s ) const {
        return CLxVectorT(v[0] * s, v[1] * s, v[2] * s);
}


template <class T>
CLxVectorT<T>& CLxVectorT<T>::operator*=( const CLxMatrix4 &mat ) {
        CLxVectorT retV;
        lx::Matrix4Multiply( retV.v, mat.m, v );
        *this = retV;
        return *this;
} 

template <class T>
CLxVectorT<T>
CLxVectorT<T>::operator*( const CLxMatrix4 &mat ) const {
        CLxVectorT retV;
        lx::Matrix4Multiply( retV.v, mat.m, v );
        return retV;
}

template <class T>
CLxVectorT<T>&
CLxVectorT<T>::operator/=(T s) {
        if( s == 0.)
                throw LXe_INVALIDARG;
        
        return *this *= T(1.0) / s;
}


template <class T>
CLxVectorT<T>
CLxVectorT<T>::operator/(T s) const {
        if( s == 0.)
                throw LXe_INVALIDARG;
        
        return *this * (T(1.0) / s);
}


template <class T>
bool
CLxVectorT<T>::operator==(const CLxVectorT<T>& other) const {
        return LXx_VEQ( v, other.v );
}


template <class T>
bool
CLxVectorT<T>::operator!=(const CLxVectorT<T>& other) const {
        return !(LXx_VEQ( v, other.v ) );
}


#define MIN_PRECISION	(1.0e-10)

double DTolerance ( double m ) {
        
        if (m < 0.0)
                m /= -3.36e6;
        else
                m /=  3.36e6;
        
        if (m > MIN_PRECISION)
                return (m);
        else
                return (MIN_PRECISION);
}

bool DCompare( double a, double b ) {
        double x = fabs (a);
        double y = fabs (b);
        if (y > x)
                x = y;
        
        y = DTolerance (x);
        x = a - b;
        return (x > -y) - (x < y);
}

template <class T>
bool
CLxVectorT<T>::operator< (const CLxVectorT& other) const{
        for (unsigned char ii = 0; ii < 3; ++ii)
                if( DCompare(v[ii], other.v[ii]))
                        return (v[ii] < other.v[ii]);
        
        return false;
}


template <class T>
T
CLxVectorT<T>::lengthSquared() const {
        return LXx_VLENSQ(v);
}


template <class T>
T
CLxVectorT<T>::length() const {
        return LXx_VLEN(v);
}


template <class T>
CLxVectorT<T>
CLxVectorT<T>::normal() const {
        CLxVectorT norm(*this);
        LxResult rc = norm.normalize();
        if( LXx_FAIL( rc ) )
                throw LXe_INVALIDARG;

        return norm;
}


template <class T>
LxResult
CLxVectorT<T>::normalize() {
        // do this here rather then by calling other mathing functions to avoid
        // float round errors.
        CLxVectorT<double> absVec( fabs(v[0]), fabs(v[1]), fabs(v[2]) );
        int maxIndex = absVec.maxAxis();
        if (absVec[maxIndex] > 0.0)	{
                *this /= absVec[maxIndex];
                double scl = 1.0 / LXx_VLEN(v);
                LXx_VSCL(v, scl );
                return LXe_OK;
        }
        return LXe_FAILED;
}


template <class T>
T
CLxVectorT<T>::triple (const CLxVectorT &v1, const CLxVectorT &v2 ) const {
        return
        v[0] * (v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1]) +
        v[1] * (v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2]) +
        v[2] * (v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]);
}

template <class T>
T
CLxVectorT<T>::distanceTo ( const CLxVectorT &other ) const {
        return (other - *this).length();
}

template <class T>
CLxVectorT<T>
CLxVectorT<T>::lerp (const CLxVectorT &other, T s ) const {
        CLxVectorT retV;
        LXx_VLERP( retV.v, v, other.v, s );
        return  retV;
}


template <class T>
CLxVectorT<T>
CLxVectorT<T>::slerp ( const CLxVectorT<T> &other, T s ) const {
        double dP = dot( other );
        
#define CLAMP(number,minval,maxval) (number<minval?minval:(number>maxval?maxval:number))
#define LERP(a,b,x) ( a + ((b-a)*x)  )
        dP = CLAMP(dP, -1.0, 1.0);
        
        double theta = acos(dP) * s;
        CLxVectorT RelativeVec( other - (*this*dP) );
        CLxResult rc = RelativeVec.normalize();
        if( rc.fail() )
                return *this;
        
        CLxVectorT retV((*this*cos(theta)) + (RelativeVec*sin(theta)));
        retV.normalize();
        retV *= LERP(length(), other.length(), s );
        return retV;
}


template <class T>
bool
CLxVectorT<T>::epsilonEquals (const CLxVectorT &other, T epsilon ) const {
        T m = v[0];
        
        if (m < 0.0)
                m /= -3.36e6;
        else
                m /=  3.36e6;
        
        if (m > epsilon)
                epsilon = m;
        
        return (fabs( v[0] - other.v[0] ) < fabs(epsilon) &&
                  fabs( v[1] - other.v[1] ) < fabs(epsilon) &&
                  fabs( v[2] - other.v[2] ) < fabs(epsilon) );
        
}


template <class T>
T
CLxVectorT<T>::angle ( const CLxVectorT<T> &other ) const {
        return (T)std::acos(normal().dot( other.normal() ) );
}




template <class T>
CLxVectorT<T>
CLxVectorT<T>::absolute() const {
        return CLxVectorT( fabs(v[0]), fabs(v[1]), fabs(v[2]) );
}

template <class T>
int
CLxVectorT<T>::furthestAxis() const {
        return absolute().minAxis();
}

template <class T>
int
CLxVectorT<T>::closestAxis() const {
        return absolute().maxAxis();
}

template <class T>
int
CLxVectorT<T>::minAxis() const {
        return v[0] < v[1] ? (v[0] <v[2] ? 0 : 2) : (v[1] <v[2] ? 1 : 2);
}

template <class T>
int
CLxVectorT<T>::maxAxis() const {
        return v[0] < v[1] ? (v[1] <v[2] ? 2 : 1) : (v[0] <v[2] ? 2 : 0);
}

template <class T>
bool
CLxVectorT<T>::hasNANorINF() const {
#define IS_NAN_OR_INF(x) 	 ((x*0.) != 0. )
        return IS_NAN_OR_INF(v[0]) ||  IS_NAN_OR_INF(v[1]) || IS_NAN_OR_INF(v[2])   ;
}


template <class T>
std::string
CLxVectorT<T>::toString() const {
        std::stringstream strstrm ;
        strstrm << *this;
        return strstrm.str();
}


template <class T>
const T&
CLxVectorT<T>::x() const {
        return v[0];
}

template <class T>
const T&
CLxVectorT<T>::y() const {
        return v[1];
}

template <class T>
const T&
CLxVectorT<T>::z() const {
        return v[2];
}


template <class T>
CLxVectorT<T>::operator T*() {
        return(v);
}

template <class T>
CLxVectorT<T>::operator const T*() const {
        return(v);
}

template <class T>
T&
CLxVectorT<T>::operator() (unsigned int i) {
        if( i > LXdND )
                throw LXe_OUTOFBOUNDS;
        else
                return v[i];
}

template <class T>
T&
CLxVectorT<T>::operator[] (unsigned int i) {
        if( i > LXdND )
                throw LXe_OUTOFBOUNDS;
        else
                return v[i];
}


template <class T>
const T&
CLxVectorT<T>::operator[] (unsigned int i) const {
        if( i > LXdND )
                throw LXe_OUTOFBOUNDS;
        else
                return v[i];
}



std::ostream&
operator<< (std::ostream& stream, const CLxFVector& vec) {
        stream << "[" ;
        stream << vec.x() << ',' ;
        stream << vec.y() << ',' ;
        stream << vec.z() << ']' ;
        
        return stream;
}

std::ostream&
operator<< (std::ostream& stream, const CLxVector& vec) {
        stream << "[" ;
        stream << vec.x() << ',' ;
        stream << vec.y() << ',' ;
        stream << vec.z() << ']' ;
        
        return stream;
}


template class CLxVectorT<float>;
template class CLxVectorT<double>;

