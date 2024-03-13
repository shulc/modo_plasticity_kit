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
 * Helper class for doing math with modo matrices.
 */

#ifndef LX_MATRIX_HPP
#define LX_MATRIX_HPP

#include <lxlocator.h>
#include <lxvmath.h>
#include <lxu_vector.hpp>
#include <lx_value.hpp>

class CLxQuaternion;

class CLxMatrix4
{
public:
        LXtMatrix4 	m;
        
        /**@brief create an identity matrix */
        CLxMatrix4() ;
        CLxMatrix4( double x1, double y1, double z1, double w1,
                     double x2, double y2, double z2, double w2,
                     double x3, double y3, double z3, double w3,
                     double x4, double y4, double z4, double w4 ) ;
        
        CLxMatrix4(const CLxMatrix4 &other) ;
        
        // created using the passed matrix.  passed vector is then assigned as translation.
        CLxMatrix4(const CLxMatrix4 &otherM, const CLxVector &otherV ) ;
        CLxMatrix4(const LXtMatrix4 mat) ;
        // Initialize from 3x3 matrix, including transpose to compensate for historical confusion
        CLxMatrix4(const LXtMatrix mat) ;

        CLxMatrix4(const CLxQuaternion &quat) ;
        // created from three vectors.
        CLxMatrix4(const CLxVector &xx, const CLxVector &yy, const CLxVector &zz ) ;
        
        /**@brief create the matrix from euler angles
         * @param xx Pitch around X axis
         * @param yy Yaw around Y axis
         * @param zz around Z axis */
        CLxMatrix4(const CLxVector &v, int rotOrd = LXi_ROTORD_ZYX ) ;
        CLxMatrix4(double xx, double yy, double zz, int rotOrd = LXi_ROTORD_ZYX ) ;
        CLxMatrix4(const CLxUser_Matrix &other) ;

        CLxMatrix4& operator= (const CLxMatrix4 &other) ;
        
        CLxQuaternion	asQuaternion() const ;
        CLxMatrix4 		asScaleMatrix () const ;
        CLxMatrix4 		asRotateMatrix () const ;
        
        CLxMatrix4 transpose() const ;
        
        double determinant() const ;

        
        // faster inverse for pure rotations with isotropic scaling (orthogonal transforms)
        CLxMatrix4 inverseRotation() const ;
        
        CLxMatrix4 inverse() const ;
        
        CLxMatrix4& operator*=( const CLxMatrix4 &mat ) ;
        CLxMatrix4	operator*( const CLxMatrix4 &mat ) const ;
        CLxMatrix4& operator*=( const CLxQuaternion &quat ) ;
        CLxMatrix4	operator*( const CLxQuaternion &quat ) const ;
        CLxVector	operator*( const CLxVector &vec ) const ;

        CLxVector	getShear(  ) const ;
        CLxVector	getScale(  ) const ;
        
        /**@brief Get the matrix represented as euler angles , roundtrip with setEuler*/
        CLxVector getEulerVector( int rotOrd = LXi_ROTORD_ZYX) const ;
        
        /**@brief Get the matrix represented as euler angles , roundtrip with setEuler
         * @param xx Pitch around X axis
         * @param yy Yaw around Y axis
         * @param zz around Z axis */
        LxResult setEuler(double xx, double yy, double zz, int rotOrd = LXi_ROTORD_ZYX ) ;
        LxResult setEuler(const CLxVector &eulerVec, int rotOrd = LXi_ROTORD_ZYX ) ;
        
        void setAxisAngle(const CLxVector &vec, double angle ) ;
        
        CLxVector getTranslation(  ) const ;
        void setTranslation( const CLxVector &vec  ) ;
        
        /*!
         Equality operator.
         \param[in] other CLxMatrix4 to compare to.
         \return bool true if all components are identical.
         */
        bool		operator==(const CLxMatrix4& other) const ;
        
        /*!
         Inquality operator.
         \param[in] other CLxMatrix4 to compare to.
         \return bool false if any component is not identical.
         */
        bool		operator!=(const CLxMatrix4& other) const ;
        
        
        // returns true if matrices are within epsilon of each other.
        bool		epsilonEquals (const CLxMatrix4 &other, double epsilon = 1.0e-8) const ;
        
        
        CLxMatrix4	getMatrix3x3( ) const ;
        // Get 3x3 matrix including transpose for compatibility
        void	getMatrix3x3( LXtMatrix m3 ) ;
        
        static const CLxMatrix4&	getIdentity() ;
        
        
        // Set this instance to the 4x4 identity matrix
        CLxMatrix4&	setToIdentity () ;
        
        // sets the 3x3 part of the matrix
        void set( double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3 ) ;
        
        void set( double x1, double y1, double z1, double w1,
                   double x2, double y2, double z2, double w2,
                   double x3, double y3, double z3, double w3,
                   double x4, double y4, double z4, double w4 ) ;

        void set(int row, int column, double value );
        
        // sets the 3x3 part of the matrix
        // xx = left, yy = up, zz = forward
        void set(const CLxVector &xx, const CLxVector &yy, const CLxVector &zz ) ;
        
        
        operator LXtMatrix4&() ;
        
        double* 	operator[] (unsigned int i) ;
        const double* 	operator[] (unsigned int i) const ;
};

std::ostream& operator<< (std::ostream& stream, const CLxMatrix4& mat) ;






#endif	/* LX_MATRIX_HPP */

