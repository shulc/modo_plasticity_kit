/*
 * Plug-in SDK Header: Quaternion Wrapper
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
#include <lxu_quaternion.hpp>
#include <lxu_math.hpp>
#include <lxu_result.hpp>
#include <lxu_matrix.hpp>

#include <sstream>      // std::stringstream
#include <cmath>
#include <cfloat>
#include <stdio.h>

#define QX		 0
#define QY		 1
#define QZ		 2
#define QW		 3


CLxQuaternion::CLxQuaternion() {
        *this = getIdentity();
}
        
CLxQuaternion::~CLxQuaternion() {
        
}
        
CLxQuaternion::CLxQuaternion(const CLxQuaternion &src) {
                *this = src;
}
        
CLxQuaternion::CLxQuaternion(double xx, double yy, double zz, double ww) {
        LXx_V4SET4( q, xx, yy, zz, ww );
}

CLxQuaternion::CLxQuaternion(const double qq[4]) {
        LXx_V4CPY( q, qq );
}

CLxQuaternion::CLxQuaternion (const CLxVector &axis, double angle) {
        q[QW] = cos (angle / 2.0);
        
        double s = sin (angle / 2.0);
        
        q[QX] = s * axis.x();
        q[QY] = s * axis.y();
        q[QZ] = s * axis.z();
}

CLxQuaternion::CLxQuaternion(const CLxVector &v0, const CLxVector &v1) {
        CLxVector u( v0.normal() );
        CLxVector v( v1.normal() );
        CLxVector w = u.cross( v );
        LXx_V4SET4( q, 1.0 + u.dot( v ), w.x(), w.y(), w.z() );
        normalize();
}


CLxQuaternion::CLxQuaternion( const CLxMatrix4& mat) {
        *this = mat;
}

CLxQuaternion &
CLxQuaternion::operator=(const CLxMatrix4& mat) {
        double tr = mat[QX][QX] + mat[QY][QY] + mat[QZ][QZ] + 1.0;
        if (tr > 0.0) {
                double s = sqrt (tr);
                q[QW] = s * 0.5;
                s = 0.5 / s;
                q[QX] = (mat[2][1] - mat[1][2]) * s;
                q[QY] = (mat[0][2] - mat[2][0]) * s;
                q[QZ] = (mat[1][0] - mat[0][1]) * s;
        }
        else {
                int i = QX;
                if (mat[QY][QY] > mat[QX][QX])
                        i = QY;
                if (mat[QZ][QZ] > mat[i][i])
                        i = QZ;
                
                int			 nxt[3] = {1, 2, 0};
                int j = nxt[i];
                int k = nxt[j];
                double s = sqrt ((mat[i][i] - (mat[j][j] + mat[k][k])) + 1.0);
                
                q[i] = s * 0.5;
                if (s > 0)
                        s = 0.5 / s;
                q[QW] = (mat[k][j] - mat[j][k]) * s;
                q[j]  = (mat[j][i] + mat[i][j]) * s;
                q[k]  = (mat[k][i] + mat[i][k]) * s;
        }
        return *this;
}



CLxMatrix4
CLxQuaternion::asMatrix() const {
        double norm = q[QX]*q[QX] + q[QY]*q[QY] + q[QZ]*q[QZ] + q[QW]*q[QW];
        double s    = (norm > 0) ? 2.0 / norm : 0;
        
        double xx = q[QX] * q[QX] * s;
        double yy = q[QY] * q[QY] * s;
        double zz = q[QZ] * q[QZ] * s;
        double xy = q[QX] * q[QY] * s;
        double xz = q[QX] * q[QZ] * s;
        double yz = q[QY] * q[QZ] * s;
        double wx = q[QW] * q[QX] * s;
        double wy = q[QW] * q[QY] * s;
        double wz = q[QW] * q[QZ] * s;
        
        CLxMatrix4 mat;
        
        mat[0][0] = 1.0 - (yy + zz);
        mat[0][1] = xy + wz;
        mat[0][2] = xz - wy;
        
        mat[1][0] = xy - wz;
        mat[1][1] = 1.0 - (xx + zz);
        mat[1][2] = yz + wx;
        
        mat[2][0] = xz + wy;
        mat[2][1] = yz - wx;
        mat[2][2] = 1.0 - (xx + yy);
        
        return mat;
}


CLxQuaternion
CLxQuaternion::Conjugated () const {
        return CLxQuaternion(  -q[QX],  -q[QY],  -q[QZ],  q[QW] );
}

CLxQuaternion&
CLxQuaternion::Conjugate () {
        LXx_VNEG( q ); // negate first 3 values.
        return *this;
}


CLxQuaternion&
CLxQuaternion::operator=(const CLxQuaternion& src) {
        LXx_V4CPY( q, src.q );
        return *this;
}


double
CLxQuaternion::lengthSquared() const {
        return dot(*this);
}

/**@brief Return the length of the quaternion */
double
CLxQuaternion::length() const {
        return sqrt(lengthSquared());
}



/**@brief Scale this quaternion
 * @param s The scalar to scale by */
CLxQuaternion&
CLxQuaternion::operator*=(const double s) {
        LXx_V4SCL( q, s );
        return *this;
}


/**@brief Return scaled quaternion
 * @param s The scalar to scale by */
CLxQuaternion
CLxQuaternion::operator*(const double s) {
        CLxQuaternion retQ( *this );
        retQ *= s;
        return retQ;
}


/**@brief Inversely scale this quaternion
 * @param s The scale factor */
CLxQuaternion&
CLxQuaternion::operator/=(const double s)
{
        return *this *= 1.0 / s;
}

/**@brief Inversely scale this quaternion
 * @param s The scale factor */
CLxQuaternion
CLxQuaternion::operator/(const double s) const
{
        CLxQuaternion retQ( *this );
        retQ *= 1.0 / s;
        return retQ;
}



CLxQuaternion&
CLxQuaternion::normalize() {
        return *this /= length();
}


CLxQuaternion
CLxQuaternion::normal() const {
        return CLxQuaternion(*this / length() );
}


/**@brief Return the dot product between this quaternion and another
 * @param q The other quaternion */
double
CLxQuaternion::dot(const CLxQuaternion& qq) const {
        return (	q[QX] * qq[QX] +
                  q[QY] * qq[QY] +
                  q[QZ] * qq[QZ] +
                  q[QW] * qq[QW]  );
}


// Slerp interpolates assuming constant velocity.
CLxQuaternion
CLxQuaternion::slerp(const CLxQuaternion& qq, const double t) const {
        double magnitude = sqrt(lengthSquared() * qq.lengthSquared());
        
        double product = dot(q) / magnitude;
        if (fabs(product) < 1.0) {
                // Take care of long angle case see http://en.wikipedia.org/wiki/Slerp
                double sign = (product < 0.0) ? -1.0 : 1.0;
                
                double theta = acos(sign * product);
                double s1 = sin(sign * t * theta);
                double d = 1.0 / sin(theta);
                double s0 = sin(1.0 - t) * theta;
                
                return CLxQuaternion(	(q[QX] * s0 + qq[QY] * s1) * d,
                                                (q[QY] * s0 + qq[QY] * s1) * d,
                                           (q[QZ] * s0 + qq[QZ] * s1) * d,
                                                (q[QW] * s0 + qq[QZ] * s1) * d );
        } else {
                return *this;
        }
}





/**@brief Return the product of two quaternions */
CLxQuaternion
CLxQuaternion::operator*( const CLxQuaternion& qq)
{
        CLxQuaternion cQ;
        LXx_VCROSS	(cQ.q, q, qq.q);
        LXx_VADDS	(cQ.q, q, qq.q[QW]);
        LXx_VADDS	(cQ.q, qq.q, q[QW]);
        cQ.q[QW] =  q[QW]*qq.q[QW] - LXx_VDOT (q, qq.q);
        return cQ;
}

CLxQuaternion
CLxQuaternion::operator*( const CLxVector& vv ) {
        return CLxQuaternion(
                                   w() * vv.x() + y() * vv.z() - z() * vv.y(),
                                   w() * vv.y() + z() * vv.x() - x() * vv.z(),
                                   w() * vv.z() + x() * vv.y() - y() * vv.x(),
                                   -x() * vv.x() - y() * vv.y() - z() * vv.z());
}


CLxQuaternion
CLxQuaternion::operator+(const CLxQuaternion& qq) const {
        return CLxQuaternion( q[QX] + qq.x(), q[QY] + qq.y(), q[QZ] + qq.z(), q[QW] + qq.w() );
}

CLxQuaternion
CLxQuaternion::operator-(const CLxQuaternion& qq) const {
        return CLxQuaternion( q[QX] - qq.x(), q[QY] - qq.y(), q[QZ] - qq.z(), q[QW] - qq.w() );
}

bool
CLxQuaternion::operator==(const CLxQuaternion &qq) const {
        return ( (qq[0]==q[0]) && (qq[1]==q[1]) && (qq[2]==q[2]) && (qq[3]==q[3]) );
}

bool
CLxQuaternion::operator!=(const CLxQuaternion &qq) const {
        return ( (qq[0]!=q[0]) || (qq[1]!=q[1]) || (qq[2]!=q[2]) || (qq[3]!=q[3]) );
}

bool
CLxQuaternion::epsilonEquals (const CLxQuaternion &other, double epsilon ) const {
        for (unsigned char i = 0; i < 4; ++i)
                if( fabs(q[i] - other.q[i] ) > fabs( epsilon ) )
                        return false;
        return true;
}

/**@brief Return the negative of this quaternion
 * This simply negates each element */
CLxQuaternion
CLxQuaternion::operator-() const {
        return CLxQuaternion(-q[QX], -q[QY], -q[QZ], -q[QW]);
}

/**@brief Return the inverse of this quaternion */
CLxQuaternion
CLxQuaternion::inverse() const {
        return CLxQuaternion(-q[QX], -q[QY], -q[QZ], q[QW]);
}

/**@brief Return the inverse of this quaternion */
CLxQuaternion&
CLxQuaternion::invert() {
        LXx_VNEG( q ); // negate first 3 values.
        return *this;
}


const CLxQuaternion&
CLxQuaternion::getIdentity() {
        static const CLxQuaternion identityQuat( 0.0, 0.0 , 0.0, 1.0);
        return identityQuat;
}


double
CLxQuaternion::operator[] (unsigned int i) const {
        if( i > 3 )
                throw CLxResult(LXe_OUTOFBOUNDS);
        else
                return q[i];
}

double&
CLxQuaternion::operator[] (unsigned int i) {
        if( i > 3 )
                throw CLxResult(LXe_OUTOFBOUNDS);
        else
                return q[i];
}


/**@brief Return the x value */
const double&
CLxQuaternion::x() const { return q[0]; }

/**@brief Return the y value */
const double&
CLxQuaternion::y() const { return q[1]; }

/**@brief Return the z value */
const double&
CLxQuaternion::z() const { return q[2]; }

/**@brief Return the w value */
const double&
CLxQuaternion::w() const { return q[3]; }


std::ostream&
operator<< (std::ostream& stream, const CLxQuaternion& quat) {
        stream << "[" ;
        stream << quat.x() << ',' ;
        stream << quat.y() << ',' ;
        stream << quat.z() << ',' ;
        stream << quat.w() << ']' ;
        
        return stream;
}



