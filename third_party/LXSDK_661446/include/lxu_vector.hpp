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

#ifndef LX_VECTOR_HPP
#define LX_VECTOR_HPP

#include <lxvmath.h>

#include <string>

class CLxMatrix4;

template <typename T>
class CLxVectorT
{
public:
        T 	v[LXdND];  //!< the raw vector.
        
        ///
        ///The default class constructor. Creates a (0,0,0) vector.
        ///
        CLxVectorT() ;
        
        /*!
        Class constructor. Initializes the vector with the provided x, y and z values.
         \param[in] xx an scalar arguement.
         \param[in] yy an scalar arguement.
         \param[in] zz an optional scalar arguement.
        */
        CLxVectorT(T xx, T yy, T zz=(T)0.0);
        
        /*!
         Class constructor. construct from a modo vector.
         \param[in] mV an array of 3 numeric values.
         */
        CLxVectorT(const float mV[3]) ;
        CLxVectorT(const double mV[3]) ;
        
        /*!
         Class constructor. The copy constructor. Create a new vector and initialize it to the same values as the passed vector.
         \param[in] other The other CLxVector vector.
         */
        CLxVectorT(const CLxVectorT<float> &other);
        CLxVectorT(const CLxVectorT<double> &other);
        
        /*!
         Sets the vector with the provided x, y and z values.
         \param[in] xx an scalar arguement.
         \param[in] yy an scalar arguement.
         \param[in] zz an optional scalar arguement.
         */
        void set(T xx, T yy, T zz=(T)0.) ;
        
        
        /*!
         Sets all components of the vector to the provided value.
         \param[in] val an scalar arguement.
         */
        void set(T val) ;
        
        ///Sets vector to (0,0,0) .
        void clear() ;
        
        /*!
         The assignment operator.
         \param[in] other CLxVector to copy from.
         \return this CLxVector.
         */
        CLxVectorT& operator= (const CLxVectorT &other) ;
        
        /*!
         Cross product operator.
         \param[in] other CLxVector to calculate the cross product with.
         \return new CLxVector.
         */
        CLxVectorT 	cross (const CLxVectorT<T> &other) const ;
        
        /*!
         Dot product operator.
         \param[in] other CLxVector to calculate the dot product with.
         \return dot product between this and other CLxVector.
         */
        T 	dot (const CLxVectorT<T> &other) const ;
        
        /*!
         Negate operator.
         \return new negated ClxVector.
         */
        CLxVectorT	operator-() const ;
        
        /*!
         Addition in place operator.
         \param[in] other CLxVector to add.
         \return this ClxVector.
         */
        CLxVectorT& operator+= (const CLxVectorT &other ) ;
        
        /*!
         Addition operator.
         \param[in] other CLxVector to add.
         \return new ClxVector.
         */
        CLxVectorT	operator+ (const CLxVectorT &other) const ;
        
        
        /*!
         Subtraction in place operator.
         \param[in] other CLxVector to subtract.
         \return this ClxVector.
         */
        CLxVectorT& operator-= (const CLxVectorT &other ) ;
        
        /*!
         Subtraction operator.
         \param[in] other CLxVector to subtract.
         \return new ClxVector.
         */
        CLxVectorT	operator-( const CLxVectorT &other ) const ;
        
        /*!
         Multiply in place operator.
         \param[in] scale factor.
         \return this ClxVector.
         */
        CLxVectorT& operator*=( T s ) ;
        
        /*!
         Scale  operator.
         \param[in] scale factor.
         \return new scaled ClxVector.
         */
        CLxVectorT	operator*( T s ) const ;
        
        /*!
         transform in place operator.
         \param[in] ClxMatrix4.
         \return this transformed ClxVector.
         */
        CLxVectorT& operator*=( const CLxMatrix4 &mat );
        
        /*!
         transform  operator.
         \param[in] ClxMatrix4.
         \return new transformed ClxVector.
         */
        CLxVectorT	operator*( const CLxMatrix4 &mat ) const ;
        
        /*!
         Divide by in place operator.
         \param[in] scale factor.
         \return this ClxVector.
         */
        CLxVectorT&	operator/=(T s) ;
        
        /*!
         Divide by operator.
         \param[in] scale factor.
         \return new ClxVector.
         */
        CLxVectorT	operator/(T s) const ;
        
        /*!
         Equality operator.
         \param[in] other CLxVector to compare to.
         \return bool true if all components are identical.
         */
        bool		operator==(const CLxVectorT<T>& other) const ;
        
        /*!
         Inquality operator.
         \param[in] other CLxVector to compare to.
         \return bool false if any component is not identical.
         */
        bool		operator!=(const CLxVectorT<T>& other) const ;
        
        
        // utility functions
        
        /*!
         \return returns scalar length of the vector squared.
         */
        T		lengthSquared() const ;
        
        /*!
         \return returns scalar length of the vector.
         */
        T		length() const ;
        
        /*!
         \\ with throw CLxResult(LXe_INVALIDARG) if failed.
         \return returns normalized copy of this vector.
         */
        CLxVectorT	normal() const ;
        
        
        /*!
         Normalizes vector in place
         \return failed result if unable to normalize.
         */
        LxResult normalize() ;
        
        
        // returns the triple product
        T		triple (const CLxVectorT &v1, const CLxVectorT &v2 ) const ;
        
        
        // returns scalar distance between the vector and the one passed
        T		distanceTo ( const CLxVectorT &other ) const ;
        
        
        // returns the linearly interpolated vector between this and the passed vector by the scalar value
        CLxVectorT	lerp (const CLxVectorT &other, T s ) const ;
        
        /*!
         Return as slerped vector between this and the other.  Length is lerped.
         \param[in] other CLxVector compute angle from.
         */
        CLxVectorT		slerp ( const CLxVectorT &other, T s ) const ;
        
        // returns true if vectors are within epsilon of each other.
        bool		epsilonEquals (const CLxVectorT &other, T epsilon = (T)1.0e-8) const ;
        
        
        /*!
         Return the axis with the smallest absolute value
         \param[in] other CLxVector compute angle from.
         \return the angle in radians between this and the passed vector.
         */
        T		angle ( const CLxVectorT<T> &other ) const ;
        
        /*!
         Return the axis with the smallest absolute value
         \return new vector that is the absolute.
         */
        CLxVectorT	absolute() const ;
        
        /*!
         Return the axis with the smallest absolute value
         \return 0, 1, 2 equiv to x, y, z.
         */
        int		furthestAxis() const ;
        
        /*!
         Return the axis with the largest absolute value
         \return 0, 1, 2 equiv to x, y, z.
         */
        int		closestAxis() const ;
        
        /*!
         Return the axis with the smallest value
         \return 0, 1, 2 equiv to x, y, z.
         */
        int		minAxis() const ;
        
        /*!
         Return the axis with the largest value
         \return 0, 1, 2 equiv to x, y, z.
         */
        int		maxAxis() const ;
        
        bool hasNANorINF() const ;
        
        // DEPRECATED!  use stream operator.
        std::string	toString() const ;
        
        
        // accessors
        
        /**@brief Return the x value */
        const T& x() const ;
        
        /**@brief Return the y value */
        const T& y() const ;
        
        /**@brief Return the z value */
        const T& z() const ;

        operator T*() ;

        operator const T*() const;

        bool operator< (const CLxVectorT& other) const ;

                /*!
         Index operators.
         \param[in] index of component to return. [0] = x, [1] = y, [2] =z
         \return scalar component value.
         */

        T& 		operator() (unsigned int i) ;
        T& 		operator[] (unsigned int i) ;
        const T& 	operator[] (unsigned int i) const ;
};

typedef CLxVectorT<float>	CLxFVector;
typedef CLxVectorT<double>	CLxVector;

std::ostream& operator<< (std::ostream& stream, const CLxFVector& vec) ;
std::ostream& operator<< (std::ostream& stream, const CLxVector& vec) ;


#endif	/* LX_VECTOR_HPP */

