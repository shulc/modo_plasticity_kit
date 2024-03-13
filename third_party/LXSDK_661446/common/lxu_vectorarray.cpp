/*
 * Plug-in SDK Header: VectorArray Wrapper
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
 * vectorarray
 */
#include <lxu_result.hpp>
#include <lxu_matrix.hpp>
#include <lxu_vectorarray.hpp>
#include <lxu_math.hpp>

#include <ostream>
#include <cmath>
#include <cfloat>
#include <stdio.h>

template <class T>
CLxVectorArrayT<T>::CLxVectorArrayT() {
}

template <class T>
CLxVectorArrayT<T>::CLxVectorArrayT(const float *mV, unsigned int count) {
        array.resize( count );
        for( unsigned int ii = 0 ; ii < count ; ++ii ) {
                array.at(ii).set( mV[ii*3+0], mV[ii*3+1], mV[ii*3+2]  );
        }
}

template <class T>
CLxVectorArrayT<T>::CLxVectorArrayT(const double *mV, unsigned int count) {
        array.resize( count );
        for( unsigned int ii = 0 ; ii < count ; ++ii ) {
                array.at(ii).set( mV[ii*3+0], mV[ii*3+1], mV[ii*3+2]  );
        }
}

template <class T>
CLxVectorArrayT<T>::CLxVectorArrayT(const CLxVectorArrayT<float> &other) {
        array = other.array;
}

template <class T>
CLxVectorArrayT<T>::CLxVectorArrayT(const CLxVectorArrayT<double> &other) {
        array = other.array;
}

template <class T>
CLxVectorArrayT<T>::CLxVectorArrayT (unsigned int initialSize, const CLxVectorT<T> &defaultVector ) {
        array.resize( initialSize, defaultVector );
}


template <class T>
void
CLxVectorArrayT<T>::set(T xx, T yy, T zz, unsigned int index ) {
        array.at(index).set( xx, yy, zz);
}

template <class T>
unsigned int
CLxVectorArrayT<T>::size() const {
        return (unsigned int)array.size();
}

template <class T>
void
CLxVectorArrayT<T>::clear() {
        array.clear();
}


template <class T>
unsigned int
CLxVectorArrayT<T>::append(const CLxVectorT<T> &vector) {
        array.push_back( vector );
        return array.size() - 1;
}


template <class T>
CLxVectorArrayT<T> &
CLxVectorArrayT<T>::operator= (const CLxVectorArrayT &other) {
        array = other.array;
        return *this;
}



// math operators

template <class T>
CLxVectorArrayT<T>
CLxVectorArrayT<T>::operator-() const {
        CLxVectorArrayT retA( *this );
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                retA.array.at(ii) = -array.at(ii);
        }
        return retA;
}

template <class T>
CLxVectorArrayT<T>&
CLxVectorArrayT<T>::operator+= (const CLxVectorT<T> &other ) {
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                array.at(ii) += other;
        }
        return *this;
}


template <class T>
CLxVectorArrayT<T>
CLxVectorArrayT<T>::operator+ (const CLxVectorT<T> &other) const {
        CLxVectorArrayT retA( *this );
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                retA.array.at(ii) += other;
        }
        return retA;
}




template <class T>
CLxVectorArrayT<T>&
CLxVectorArrayT<T>::operator-= (const CLxVectorT<T> &other ) {
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                array.at(ii) -= other;
        }
        return *this;
}

template <class T>
CLxVectorArrayT<T>
CLxVectorArrayT<T>::operator-( const CLxVectorT<T> &other ) const {
        CLxVectorArrayT retA( *this );
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                retA.array.at(ii) -= other;
        }
        return retA;
}

template <class T>
CLxVectorArrayT<T>&
CLxVectorArrayT<T>::operator*=( T s ) {
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                array.at(ii) *= s;
        }
        return *this;
}

template <class T>
CLxVectorArrayT<T>
CLxVectorArrayT<T>::operator*( T s ) const {
        CLxVectorArrayT retA( *this );
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                retA.array.at(ii) *= s;
        }
        return retA;
}


template <class T>
CLxVectorArrayT<T>& CLxVectorArrayT<T>::operator*=( const CLxMatrix4 &mat ) {
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                array.at(ii) *= mat;
        }
        return *this;
}

template <class T>
CLxVectorArrayT<T>
CLxVectorArrayT<T>::operator*( const CLxMatrix4 &mat ) const {
        CLxVectorArrayT retA( *this );
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                retA.array.at(ii) *= mat;
        }
        return retA;
}

template <class T>
CLxVectorArrayT<T>&
CLxVectorArrayT<T>::operator/=(T s) {
        if( s == 0.)
                throw CLxResult(LXe_INVALIDARG);
        
        return *this *= T(1.0) / s;
}


template <class T>
CLxVectorArrayT<T>
CLxVectorArrayT<T>::operator/(T s) {
        if( s == 0.)
                throw CLxResult(LXe_INVALIDARG);

        return *this * (T(1.0) / s);
}


template <class T>
CLxVectorArrayT<T>
CLxVectorArrayT<T>::normal() const {
        CLxVectorArrayT retA( *this );
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                retA.array.at(ii).normalize();
        }
        return retA;
}


template <class T>
LxResult
CLxVectorArrayT<T>::normalize() {
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                LxResult rc = array.at(ii).normalize();
                if( LXx_FAIL( rc ) ) {
                        return rc;
                }
        }
        return LXe_OK;
}



template <class T>
bool
CLxVectorArrayT<T>::operator==(const CLxVectorArrayT& other) const {
        if( array.size() != other.array.size() ) {
                return false;
        }
        
        for( unsigned int ii = 0, ni = array.size() ; ii < ni ; ++ii ) {
                if( array.at(ii) != other.array.at(ii) )
                        return false;
        }
        return true;
}


template <class T>
bool
CLxVectorArrayT<T>::operator!=(const CLxVectorArrayT& other) const {
        return !( *this == other );
}



template <class T>
CLxVectorT<T>&
CLxVectorArrayT<T>::operator[] (unsigned int index) {
        return array.at( index );
}


template <class T>
const CLxVectorT<T>&
CLxVectorArrayT<T>::operator[] (unsigned int index) const {
        return array.at( index );
}

template <class T>
CLxVectorT<T>&
CLxVectorArrayT<T>::operator() (unsigned int index) {
        return array.at( index );
}




std::ostream&
operator<< (std::ostream& stream, const CLxFVectorArray& vec) {
        stream << "[" ;
        for (int i = 0; i < vec.size (); i++)
                stream << vec[i];
        stream << ']' ;
        
        return stream;
}

std::ostream&
operator<< (std::ostream& stream, const CLxVectorArray& vec) {
        stream << "[" ;
        for (int i = 0; i < vec.size (); i++)
                stream << vec[i];
        stream << ']' ;

        return stream;
}

