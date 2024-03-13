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
 * Helper class for doing math with modo quaternions.
 */

#ifndef LX_QUATERNION_HPP
#define LX_QUATERNION_HPP

#include <lxvmath.h>
#include <lxu_vector.hpp>


class CLxMatrix4;

class CLxQuaternion
{
public:
        LXtQuaternion	q;

         CLxQuaternion();
        ~CLxQuaternion();
        
        CLxQuaternion(const CLxQuaternion &src);
        CLxQuaternion(double xx, double yy, double zz, double ww);
        CLxQuaternion(const double qq[4]);
        CLxQuaternion (const CLxVector &axis, double angle);
        CLxQuaternion(const CLxVector &v0, const CLxVector &v1);
        CLxQuaternion( const CLxMatrix4& mat);

        CLxMatrix4	asMatrix() const;

        CLxQuaternion& Conjugate ()  ;
        CLxQuaternion Conjugated () const ;
        
        CLxQuaternion &	operator=(const CLxMatrix4& mat);
        CLxQuaternion &	operator=(const CLxQuaternion& src) ;
        
        
        /**@brief Return the length squared of the quaternion */
        double lengthSquared() const ;
        
        /**@brief Return the length of the quaternion */
        double length() const ;
        
        
        /**@brief Scale this quaternion
         * @param s The scalar to scale by */
        CLxQuaternion& operator*=(const double s) ;
        
        /**@brief Return scaled quaternion
         * @param s The scalar to scale by */
        CLxQuaternion operator*(const double s) ;
        
        /**@brief Inversely scale this quaternion
         * @param s The scale factor */
        CLxQuaternion& operator/=(const double s) ;
        
        /**@brief Return inversely scaled quaternion
         * @param s The scale factor */
        CLxQuaternion operator/(const double s) const ;
        
        
        CLxQuaternion& normalize() ;
        CLxQuaternion normal() const ;
        
        
        /**@brief Return the dot product between this quaternion and another
         * @param q The other quaternion */
        double dot(const CLxQuaternion& qq) const ;
        
        
        // Slerp interpolates from this quat to given quat by t.
        CLxQuaternion slerp(const CLxQuaternion& qq, const double t) const ;
        
        
        /**@brief Return the product of two quaternions */
        CLxQuaternion operator*( const CLxQuaternion& qq) ;
        
        CLxQuaternion operator*( const CLxVector& vv ) ;
        CLxQuaternion operator+(const CLxQuaternion& qq) const ;
        CLxQuaternion operator-(const CLxQuaternion& qq) const ;

        bool operator==(const CLxQuaternion &qq) const ;
        bool operator!=(const CLxQuaternion &qq) const ;

        bool epsilonEquals (const CLxQuaternion &other, double epsilon = 1.0e-8 ) const ;

        /**@brief Return the negative of this quaternion
         * This simply negates each element */
        CLxQuaternion operator-() const ;

        /**@brief Return the inverse of this quaternion */
        CLxQuaternion inverse() const ;

        /**@brief Invert this quaternion */
        CLxQuaternion& invert() ;
        
        static const CLxQuaternion&	getIdentity() ;
        
        double operator[] (unsigned int i) const ;
        double& operator[] (unsigned int i) ;
        
        /**@brief Return the x value */
        const double& x() const ;
        /**@brief Return the y value */
        const double& y() const ;
        /**@brief Return the z value */
        const double& z() const ;
        /**@brief Return the w value */
        const double& w() const ;
        
};

std::ostream& operator<< (std::ostream& stream, const CLxQuaternion& quat) ;

#endif	/* LX_QUATERNION_HPP */

