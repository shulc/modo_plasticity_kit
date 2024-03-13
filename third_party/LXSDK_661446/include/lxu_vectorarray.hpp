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
 * Helper class for doing math with modo vectors.
 */

#ifndef LX_VECTORARRAY_HPP
#define LX_VECTORARRAY_HPP

#include <lxu_vector.hpp>

#include <vector>

class CLxMatrix4;

template <typename T>
class CLxVectorArrayT
{
public:
        std::vector<CLxVectorT<T> > 	array;
        
        ///
        ///The default class constructor. Creates a (0,0,0) vector.
        ///
        CLxVectorArrayT() ;
        
        /*!
         Class constructor. construct from a scalar array.
         \param[in] mV an array of 3 numeric values.
         */
        CLxVectorArrayT(const float *fV, unsigned int count) ;
        CLxVectorArrayT(const double *dV, unsigned int count) ;
        
        /*!
         Class constructor. The copy constructor. Create a new array and initialize it to the same values as the passed array.
         \param[in] other The other CLxVector vector.
         */
        CLxVectorArrayT(const CLxVectorArrayT<float> &other);
        CLxVectorArrayT(const CLxVectorArrayT<double> &other);
        
        CLxVectorArrayT (unsigned int initialSize, const CLxVectorT<T> &defaultVector=CLxVectorT<T>( 0.0, 0.0, 0.0 ) );
        /*!
         Sets the vector with the provided x, y and z values.
         \param[in] xx an scalar arguement.
         \param[in] yy an scalar arguement.
         \param[in] zz an optional scalar arguement.
         */
        void set(T xx, T yy, T zz, unsigned int index ) ;
        
        unsigned int size() const;
        
        ///Sets vector to (0,0,0) .
        void clear() ;
        
        unsigned int 	append (const CLxVectorT<T> &vector) ;
        
        /*!
         The assignment operator.
         \param[in] other CLxVector to copy from.
         \return this CLxVector.
         */
        CLxVectorArrayT& operator= (const CLxVectorArrayT &other) ;
        
        
        /*!
         Negate operator.
         \return new negated ClxVector.
         */
        CLxVectorArrayT operator-() const ;
        /*!
         Addition in place operator.
         \param[in] other CLxVector to add.
         \return this ClxVector.
         */
        CLxVectorArrayT& operator+= (const CLxVectorT<T> &other ) ;
        
        /*!
         Addition operator.
         \param[in] other CLxVector to add.
         \return new ClxVector.
         */
        CLxVectorArrayT	operator+ (const CLxVectorT<T> &other) const ;
        
        
        /*!
         Subtraction in place operator.
         \param[in] other CLxVector to subtract.
         \return this CLxVectorArrayT.
         */
        CLxVectorArrayT& operator-= (const CLxVectorT<T> &other ) ;
        
        /*!
         Subtraction operator.
         \param[in] other CLxVector to subtract.
         \return new CLxVectorArrayT.
         */
        CLxVectorArrayT	operator-( const CLxVectorT<T> &other ) const ;
        
        /*!
         Multiply in place operator.
         \param[in] scale factor.
         \return this CLxVectorArrayT.
         */
        CLxVectorArrayT& operator*=( T s ) ;
        
        /*!
         Scale  operator.
         \param[in] scale factor.
         \return new scaled CLxVectorArrayT.
         */
        CLxVectorArrayT	operator*( T s ) const ;
        
        /*!
         transform in place operator.
         \param[in] ClxMatrix4.
         \return this transformed CLxVectorArrayT.
         */
        CLxVectorArrayT& operator*=( const CLxMatrix4 &mat );
        
        /*!
         transform  operator.
         \param[in] ClxMatrix4.
         \return new transformed CLxVectorArrayT.
         */
        CLxVectorArrayT	operator*( const CLxMatrix4 &mat ) const ;
        
        /*!
         Divide by in place operator.
         \param[in] scale factor.
         \return this CLxVectorArrayT.
         */
        CLxVectorArrayT&	operator/=(T s) ;
        
        /*!
         Divide by operator.
         \param[in] scale factor.
         \return new CLxVectorArrayT.
         */
        CLxVectorArrayT	operator/(T s) ;
        
        
        /*!
         \\ with throw CLxResult(LXe_INVALIDARG) if failed.
         \return returns normalized copy of this vector array.
         */
        CLxVectorArrayT	normal() const ;
        
        
        /*!
         Normalizes array in place
         \return LXe_OK on success.
         */
        LxResult normalize() ;
        
        
        /*!
         Equality operator.
         \param[in] other CLxVector to compare to.
         \return bool true if all components are identical.
         */
        bool		operator==(const CLxVectorArrayT& other) const ;
        
        /*!
         Inquality operator.
         \param[in] other CLxVector to compare to.
         \return bool false if any component is not identical.
         */
        bool		operator!=(const CLxVectorArrayT& other) const ;
        
        
        // accessors
        /*!
         Index operators.
         \param[in] index of component to return. [0] = x, [1] = y, [2] =z
         \return scalar component value.
         */

        const CLxVectorT<T> & 	operator[] ( unsigned int index ) const ;
        CLxVectorT<T> & 		operator[] ( unsigned int index )  ;
        CLxVectorT<T> & 		operator() ( unsigned int index ) ;

};

typedef CLxVectorArrayT<float>	CLxFVectorArray;
typedef CLxVectorArrayT<double>	CLxVectorArray;

std::ostream& operator<< (std::ostream& stream, const CLxFVectorArray& vec) ;
std::ostream& operator<< (std::ostream& stream, const CLxVectorArray& vec) ;


#endif	/* LX_VECTORARRAY_HPP */

