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
#include <lxu_quaternion.hpp>

#include <sstream>      // std::stringstream
#include <cmath>
#include <cfloat>
#include <stdio.h>




// decompose functions pretty much copied verbatim from vmath.qq
// shoved into a namespace to avoid conflicts.
namespace CLxMatrix_namespace {
        
        enum {
                U_SCALEX,
                U_SCALEY,
                U_SCALEZ,
                U_SHEARXY,
                U_SHEARXZ,
                U_SHEARYZ,
                U_ROTATEX,
                U_ROTATEY,
                U_ROTATEZ,
                U_TRANSX,
                U_TRANSY,
                U_TRANSZ,
        };
        
        
        double
        DTolerance (
                        double			 m)
        {
#define MIN_PRECISION	(1.0e-10)
                
                if (m < 0.0)
                        m /= -3.36e6;
                else
                        m /=  3.36e6;
                
                if (m > MIN_PRECISION)
                        return (m);
                else
                        return (MIN_PRECISION);
                
        }
        
        int
        DCompare (
                    double			 a,
                    double			 b)
        {
                double			 x, y;
                
                x = fabs (a);
                y = fabs (b);
                if (y > x)
                        x = y;
                
                y = DTolerance (x);
                x = a - b;
                return (x > -y) - (x < y);
        }
        
        
        static void
        V3_Combine (
                        LXtVector			 a,
                        LXtVector			 b,
                        LXtVector			 r,
                        double			 aScl,
                        double			 bScl)
        {
                r[0] = (aScl * a[0]) + (bScl * b[0]);
                r[1] = (aScl * a[1]) + (bScl * b[1]);
                r[2] = (aScl * a[2]) + (bScl * b[2]);
        }
        
        
        
        static int Matrix4Decompose (	const CLxMatrix4		&m,
                                             double			 tran[12],
                                             int			 order)
        {
                LXtMatrix4		 m4Loc;//, m4p;
                LXtQuaternion		 r0, r1, r2, v;
                double		 r0Len, r1Len, r2Len;
                int		 haveX, haveY, haveZ, axesN;
                int		 ROTORD[6][3] = {{ 0, 1, 2 },	// XYZ
                        { 0, 2, 1 },	// XZY
                        { 1, 0, 2 },	// YXZ
                        { 1, 2, 0 },	// YZX
                        { 2, 0, 1 },	// ZXY
                        { 2, 1, 0 }};	// ZYX
                
                if (m[3][3] == 0)
                        return 0;
                
                for (unsigned char i = 0; i < 4; i++)
                        for (unsigned char j = 0; j < 4; j++)
                                m4Loc[i][j] = m[i][j];
                
                
                // TODO - this function is also in Graphics Gems 4
                //if (det4x4 (m4p) == 0.0)
                //	return 0;
                
                tran[U_SCALEX]  = 0.0;
                tran[U_SCALEY]  = 0.0;
                tran[U_SCALEZ]  = 0.0;
                tran[U_SHEARXY] = 0.0;
                tran[U_SHEARXZ] = 0.0;
                tran[U_SHEARYZ] = 0.0;
                tran[U_ROTATEX] = 0.0;
                tran[U_ROTATEY] = 0.0;
                tran[U_ROTATEZ] = 0.0;
                tran[U_TRANSX]  = 0.0;
                tran[U_TRANSY]  = 0.0;
                tran[U_TRANSZ]  = 0.0;
                
                // don't deal with matricies that have perspective
                if (m4Loc[0][3] != 0 || m4Loc[1][3] != 0 || m4Loc[2][3] != 0)
                        return 0;
                
                // translation
                for (unsigned char i = 0; i < 3; i++) {
                        tran[U_TRANSX + i] = m4Loc[3][i];
                        m4Loc[3][i] = 0;
                }
                
                r0[0] = m4Loc[0][0];
                r0[1] = m4Loc[0][1];
                r0[2] = m4Loc[0][2];
                
                r1[0] = m4Loc[1][0];
                r1[1] = m4Loc[1][1];
                r1[2] = m4Loc[1][2];
                
                r2[0] = m4Loc[2][0];
                r2[1] = m4Loc[2][1];
                r2[2] = m4Loc[2][2];
                
                r0Len = LXx_VLEN (r0);
                haveX = r0Len == 0.0 ? 0 : 1;
                r1Len = LXx_VLEN (r1);
                haveY = r1Len == 0.0 ? 0 : 1;
                r2Len = LXx_VLEN (r2);
                haveZ = r2Len == 0.0 ? 0 : 1;
                
                axesN = haveX + haveY + haveZ;
                
                if (axesN != 3) {
                        
                        // Run with -dbon:enableZeroScales to support zero scales on one or two axes.
                        // Disabled by default due to side effects & regressions.
                        //		if (DBtest ("enableZeroScales") == 0)
                        //			return 1;
                        
                        if (axesN == 0) {
                                return 1;
                        }
                        else if (axesN == 1) {
                                LXtQuaternion		 vecX, vecY, vecZ;
                                double		 dotP;
                                
                                if (haveX) {
                                        
                                        tran[U_SCALEX]  = r0Len;
                                        tran[U_SCALEY]  = 0.0;
                                        tran[U_SCALEZ]  = 0.0;
                                        tran[U_SHEARXY] = 0.0;
                                        tran[U_SHEARXZ] = 0.0;
                                        tran[U_SHEARYZ] = 0.0;
                                        
                                        LXx_VCPY (vecX, r0);
                                        lx::VectorNormalize (vecX);
                                        
                                        LXx_VUNIT (vecY, 1);
                                        
                                        dotP = LXx_VDOT (vecX, vecY);
                                        
                                        if (DCompare (dotP, 1.0) == 0) {
                                                // The X axis is pointing in the direction of the initial
                                                // 'up' axis,
                                                LXx_VCLR (vecY);
                                                vecY[0] = -1.0;
                                        }
                                        else if (DCompare (dotP, -1.0) == 0) {
                                                LXx_VCLR (vecY);
                                                vecY[0] = 1.0;
                                        }
                                        
                                        LXx_VCROSS (vecZ, vecX, vecY);
                                        LXx_VCROSS (vecY, vecZ, vecX);
                                        
                                        LXx_VCPY (r0, vecX);
                                        LXx_VCPY (r1, vecY);
                                        LXx_VCPY (r2, vecZ);
                                }
                                else if (haveY) {
                                        
                                        tran[U_SCALEX]  = 0.0;
                                        tran[U_SCALEY]  = r1Len;
                                        tran[U_SCALEZ]  = 0.0;
                                        tran[U_SHEARXY] = 0.0;
                                        tran[U_SHEARXZ] = 0.0;
                                        tran[U_SHEARYZ] = 0.0;
                                        
                                        LXx_VCPY (vecY, r1);
                                        lx::VectorNormalize (vecY);
                                        
                                        LXx_VUNIT (vecZ, 2);
                                        
                                        dotP = LXx_VDOT (vecY, vecZ);
                                        
                                        if (DCompare (dotP, 1.0) == 0) {
                                                // The Y axis is pointing in the direction of the initial
                                                // 'forward' axis,
                                                LXx_VCLR (vecZ);
                                                vecZ[1] = -1.0;
                                        }
                                        else if (DCompare (dotP, -1.0) == 0) {
                                                LXx_VCLR (vecZ);
                                                vecZ[1] = 1.0;
                                        }
                                        
                                        LXx_VCROSS (vecX, vecY, vecZ);
                                        LXx_VCROSS (vecZ, vecX, vecY);
                                        
                                        LXx_VCPY (r0, vecX);
                                        LXx_VCPY (r1, vecY);
                                        LXx_VCPY (r2, vecZ);
                                }
                                else if (haveZ) {
                                        
                                        tran[U_SCALEX]  = 0.0;
                                        tran[U_SCALEY]  = 0.0;
                                        tran[U_SCALEZ]  = r2Len;
                                        tran[U_SHEARXY] = 0.0;
                                        tran[U_SHEARXZ] = 0.0;
                                        tran[U_SHEARYZ] = 0.0;
                                        
                                        LXx_VCPY (vecZ, r2);
                                        lx::VectorNormalize (vecZ);
                                        
                                        LXx_VUNIT (vecY, 1);
                                        
                                        dotP = LXx_VDOT (vecZ, vecY);
                                        
                                        if (DCompare (dotP, 1.0) == 0) {
                                                // The Z axis is pointing in the direction of the initial
                                                // 'up' axis,
                                                LXx_VCLR (vecY);
                                                vecY[2] = -1.0;
                                        }
                                        else if (DCompare (dotP, -1.0) == 0) {
                                                LXx_VCLR (vecY);
                                                vecY[2] = 1.0;
                                        }
                                        
                                        LXx_VCROSS (vecX, vecY, vecZ);
                                        LXx_VCROSS (vecY, vecZ, vecX);
                                        
                                        LXx_VCPY (r0, vecX);
                                        LXx_VCPY (r1, vecY);
                                        LXx_VCPY (r2, vecZ);
                                }
                        }
                        else if (axesN == 2) {
                                
                                if (haveX == 0) {
                                        // The Y and Z axes are valid, make a new X axis
                                        LXx_VCROSS (r0, r1, r2);
                                        lx::VectorNormalize (r0);
                                        
                                        tran[U_SCALEX]  = 0.0;
                                        tran[U_SHEARXY] = 0.0;
                                        
                                        // Compute Y scale and normalise the second row.
                                        tran[U_SCALEY] = LXx_VLEN (r1);
                                        lx::VectorNormalize (r1);
                                        
                                        // Compute XZ and YZ shears, orthogonalise the third row.
                                        tran[U_SHEARXZ] = LXx_VDOT (r0, r2);
                                        V3_Combine (r2, r0, v, 1.0, -tran[U_SHEARXZ]);
                                        LXx_VCPY (r2, v);
                                        tran[U_SHEARYZ] = LXx_VDOT (r1, r2);
                                        V3_Combine (r2, r1, v, 1.0, -tran[U_SHEARYZ]);
                                        LXx_VCPY (r2, v);
                                        
                                        // get Z scale and normalise third row
                                        tran[U_SCALEZ] = LXx_VLEN (r2);
                                        lx::VectorNormalize (r2);
                                        tran[U_SHEARXZ] /= tran[U_SCALEZ];
                                        tran[U_SHEARYZ] /= tran[U_SCALEZ];
                                }
                                else if (haveY == 0) {
                                        // compute X scale factor and normalise first row
                                        tran[U_SCALEX] = LXx_VLEN (r0);
                                        lx::VectorNormalize (r0);
                                        
                                        // The X and Z axes are valid, make a new Y axis.
                                        LXx_VCROSS (r1, r2, r0);
                                        lx::VectorNormalize (r1);
                                        
                                        tran[U_SCALEY]  = 0.0;
                                        tran[U_SHEARXY] = 0.0;
                                        
                                        // compute XZ and YZ shears, orthogonalise third row
                                        tran[U_SHEARXZ] = LXx_VDOT (r0, r2);
                                        V3_Combine (r2, r0, v, 1.0, -tran[U_SHEARXZ]);
                                        LXx_VCPY (r2, v);
                                        tran[U_SHEARYZ] = LXx_VDOT (r1, r2);
                                        V3_Combine (r2, r1, v, 1.0, -tran[U_SHEARYZ]);
                                        LXx_VCPY (r2, v);
                                        
                                        // get Z scale and normalise third row
                                        tran[U_SCALEZ] = LXx_VLEN (r2);
                                        lx::VectorNormalize (r2);
                                        tran[U_SHEARXZ] /= tran[U_SCALEZ];
                                        tran[U_SHEARYZ] /= tran[U_SCALEZ];
                                }
                                else if (haveZ == 0) {
                                        // compute X scale factor and normalise first row
                                        tran[U_SCALEX] = LXx_VLEN (r0);
                                        lx::VectorNormalize (r0);
                                        
                                        // compute XY shear factor and make second row orthogonal to first
                                        tran[U_SHEARXY] = LXx_VDOT (r0, r1);
                                        V3_Combine (r1, r0, v, 1.0, -tran[U_SHEARXY]);
                                        LXx_VCPY (r1, v);
                                        
                                        // compute Y scale and normalise second row
                                        tran[U_SCALEY] = LXx_VLEN (r1);
                                        lx::VectorNormalize (r1);
                                        tran[U_SHEARXY] /= tran[U_SCALEY];
                                        
                                        // The X and Y axes are valid, make a new Z axis.
                                        LXx_VCROSS (r2, r1, r0);
                                        lx::VectorNormalize (r2);
                                        
                                        tran[U_SCALEZ]  = 0.0;
                                        tran[U_SHEARXZ] = 0.0;
                                        tran[U_SHEARYZ] = 0.0;
                                }
                        }
                }
                else {
                        // compute X scale factor and normalise first row
                        tran[U_SCALEX] = LXx_VLEN (r0);
                        lx::VectorNormalize (r0);
                        
                        // compute XY shear factor and make second row orthogonal to first
                        tran[U_SHEARXY] = LXx_VDOT (r0, r1);
                        V3_Combine (r1, r0, v, 1.0, -tran[U_SHEARXY]);
                        LXx_VCPY (r1, v);
                        
                        // compute Y scale and normalise second row
                        tran[U_SCALEY] = LXx_VLEN (r1);
                        lx::VectorNormalize (r1);
                        tran[U_SHEARXY] /= tran[U_SCALEY];
                        
                        // compute XZ and YZ shears, orthogonalise third row
                        tran[U_SHEARXZ] = LXx_VDOT (r0, r2);
                        V3_Combine (r2, r0, v, 1.0, -tran[U_SHEARXZ]);
                        LXx_VCPY (r2, v);
                        tran[U_SHEARYZ] = LXx_VDOT (r1, r2);
                        V3_Combine (r2, r1, v, 1.0, -tran[U_SHEARYZ]);
                        LXx_VCPY (r2, v);
                        
                        // get Z scale and normalise third row
                        tran[U_SCALEZ] = LXx_VLEN (r2);
                        lx::VectorNormalize (r2);
                        tran[U_SHEARXZ] /= tran[U_SCALEZ];
                        tran[U_SHEARYZ] /= tran[U_SCALEZ];
                }
                
                // at this point the matrix (in r0, r1, r2) is orthonormal,
                // check for a coordinate system flip, if the determinant
                // is -1 then negate the matrix and the scaling factors
                
                // Check each axis for flipping (part of #20692).
                LXx_VCROSS (v, r1, r2);
                if (LXx_VDOT (r0, v) < 0) {
                        tran[U_SCALEX] *= -1;
                        //	tran[U_SCALEY] *= -1;
                        //	tran[U_SCALEZ] *= -1;
                        
                        r0[0] *= -1; r0[1] *= -1; r0[2] *= -1;
                        //	r1[0] *= -1; r1[1] *= -1; r1[2] *= -1;
                        //	r2[0] *= -1; r2[1] *= -1; r2[2] *= -1;
                }
                
                LXx_VCROSS (v, r2, r0);
                if (LXx_VDOT (r1, v) < 0) {
                        tran[U_SCALEY] *= -1;
                        
                        r1[0] *= -1; r1[1] *= -1; r1[2] *= -1;
                }
                
                LXx_VCROSS (v, r0, r1);
                if (LXx_VDOT (r2, v) < 0) {
                        tran[U_SCALEZ] *= -1;
                        
                        r2[0] *= -1; r2[1] *= -1; r2[2] *= -1;
                }

                CLxMatrix4 m3(	r0[0], r1[0], r2[0], 0.0,
                                  		r0[1], r1[1], r2[1], 0.0,
                                  		r0[2], r1[2], r2[2], 0.0,
                                  0.0, 0.0, 0.0, 1.0 );
                
                CLxVector rot = m3.getEulerVector();
                
                // output in xyz order to match the defines - MatrixToEuler() really should do this
                // for consistency
                v[ROTORD[order][0]] = rot[0];
                v[ROTORD[order][1]] = rot[1];
                v[ROTORD[order][2]] = rot[2];
                
                tran[U_ROTATEX] = v[0];
                tran[U_ROTATEY] = v[1];
                tran[U_ROTATEZ] = v[2];
                
                return 1;
        }
}


CLxMatrix4::CLxMatrix4() {
        lx::Matrix4Ident(m);
}

CLxMatrix4::CLxMatrix4( double x1, double y1, double z1, double w1,
                             double x2, double y2, double z2, double w2,
                             double x3, double y3, double z3, double w3,
                             double x4, double y4, double z4, double w4 ) {
        set( x1, y1, z1, w1, x2, y2, z2, w2, x3, y3, z3, w3, x4, y4, z4, w4 );
}

CLxMatrix4::CLxMatrix4(const CLxMatrix4 &other) {
        for (unsigned char i = 0; i < 4; i++)
                for (unsigned char j = 0; j < 4; j++)
                        m[i][j] = other.m[i][j];
}


CLxMatrix4::CLxMatrix4(const CLxMatrix4 &otherM, const CLxVector &otherV ) {
        *this = otherM;
        setTranslation( otherV );
}


CLxMatrix4::CLxMatrix4(const CLxQuaternion &quat ) {
        *this = quat.asMatrix();
}


CLxMatrix4::CLxMatrix4(const CLxVector &v, int rotOrd  ) {
        lx::Matrix4Ident(m);
        setEuler( v, rotOrd );
}


CLxMatrix4::CLxMatrix4(double xx, double yy, double zz, int rotOrd  ) {
        lx::Matrix4Ident(m);
        setEuler( xx, yy, zz, rotOrd );
}


CLxMatrix4::CLxMatrix4(const CLxVector &x, const CLxVector &y, const CLxVector &z ) {
        lx::Matrix4Ident(m);
        set( x, y, z );
}

CLxMatrix4::CLxMatrix4(const CLxUser_Matrix &other) {
        LXtMatrix4	mat;
        other.Get4(mat);
        for (unsigned char i = 0; i < 4; ++i)
                for (unsigned char j = 0; j < 4; ++j)
                        m[i][j] = mat[i][j];
}

CLxMatrix4&
CLxMatrix4::operator= (const CLxMatrix4 &other) {
        for (unsigned char i = 0; i < 4; ++i)
                for (unsigned char j = 0; j < 4; ++j)
                        m[i][j] = other.m[i][j];
        
        return *this;
}


CLxQuaternion
CLxMatrix4::asQuaternion() const {
        return CLxQuaternion( *this );
}

CLxMatrix4::CLxMatrix4(const LXtMatrix4 mat) {
        for (unsigned char i = 0; i < 4; ++i)
                for (unsigned char j = 0; j < 4; ++j)
                        m[i][j] = mat[i][j];
}

CLxMatrix4::CLxMatrix4(const LXtMatrix mat) {
        lx::Matrix4Ident(m);
        for (unsigned char i = 0; i < 3; ++i)
                for (unsigned char j = 0; j < 3; ++j)
                        m[i][j] = mat[j][i]; // transposed!
}

CLxMatrix4
CLxMatrix4::transpose() const {
        CLxMatrix4 retM(*this);
        lx::MatrixTranspose( retM.m );
        return retM;
}




double
CLxMatrix4::determinant() const {
return (	m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
                m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
                m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
                m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
                m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
                m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
                m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
                m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
                m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
                m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
                m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
                m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3] 	);
}


CLxMatrix4
CLxMatrix4::inverseRotation() const {
        const CLxMatrix4 inv( getMatrix3x3().transpose() );
        return CLxMatrix4(inv, -getTranslation() * inv);
}

CLxMatrix4
CLxMatrix4::inverse() const {
        
        LXtMatrix4			input;
        
        for (unsigned char i = 0; i < 4; ++i)
                for (unsigned char j = 0; j < 4; ++j)
                        input[i][j] = m[i][j];
        
        CLxMatrix4			retM;
        lx::MatrixInvert ( input, retM.m );
        return retM ;
}

CLxMatrix4&
CLxMatrix4::operator*=( const CLxMatrix4 &mat ) {
        LXtMatrix4		 tmp;
        
        for (unsigned char i = 0; i < 4; ++i)
                for (unsigned char j = 0; j < 4; ++j)
                        tmp[i][j] = 0.0;
        
        for (unsigned char i = 0; i < 4; ++i)
                for (unsigned char j = 0; j < 4; ++j)
                        for (unsigned char k = 0; k < 4; ++k)
                                tmp[i][j] += m[i][k] * mat.m[k][j];
        
        for (unsigned char i = 0; i < 4; ++i)
                for (unsigned char j = 0; j < 4; ++j)
                        m[i][j] = tmp[i][j];
        
        return *this;
}

CLxMatrix4
CLxMatrix4::operator*( const CLxMatrix4 &mat ) const {
        CLxMatrix4 retM(*this);
        retM *= mat;
        return retM;
}



CLxMatrix4&
CLxMatrix4::operator*=( const CLxQuaternion &quat ) {
        *this *= quat.asMatrix();
        return *this;
}

CLxMatrix4
CLxMatrix4::operator*( const CLxQuaternion &quat ) const {
        return CLxMatrix4(*this * quat.asMatrix() );
}

CLxVector
CLxMatrix4::operator*( const CLxVector &vec ) const {
        CLxVector		 retV;
        int			 i, j;
        double			 d;

        for (i = 0; i < 3; i++)
        {
                d = 0.0;
                for (j = 0; j < 3; j++)
                        d += vec[j] * m[j][i];

                retV[i] = d;
        }
        return retV;
}

CLxVector
CLxMatrix4::getShear( ) const {
        double tran[12];
        CLxMatrix_namespace::Matrix4Decompose( *this, tran, LXi_ROTORD_ZYX );
        
        return CLxVector( tran[CLxMatrix_namespace::U_SHEARXY],
                             tran[CLxMatrix_namespace::U_SHEARXZ],
                             tran[CLxMatrix_namespace::U_SHEARYZ] );
        
}

CLxVector
CLxMatrix4::getScale( ) const {
        double tran[12];
        CLxMatrix_namespace::Matrix4Decompose( *this, tran, LXi_ROTORD_ZYX );
        
        return CLxVector( tran[CLxMatrix_namespace::U_SCALEX],
                             tran[CLxMatrix_namespace::U_SCALEY],
                             tran[CLxMatrix_namespace::U_SCALEZ] );
        
}


CLxVector
CLxMatrix4::getEulerVector( int rotOrd ) const {
        int i = 0;
        int j = 1;
        int k = 2;
        
        switch ( rotOrd ) {
                case LXi_ROTORD_XYZ:
                        i = 0;
                        j = 1;
                        k = 2;
                        break;
                case LXi_ROTORD_XZY:
                        i = 0;
                        j = 2;
                        k = 1;
                        break;
                case LXi_ROTORD_YXZ:
                        i = 1;
                        j = 0;
                        k = 2;
                        break;
                case LXi_ROTORD_YZX:
                        i = 1;
                        j = 2;
                        k = 0;
                        break;
                case LXi_ROTORD_ZXY:
                        i = 2;
                        j = 0;
                        k = 1;
                        break;
                case LXi_ROTORD_ZYX:
                        i = 2;
                        j = 1;
                        k = 0;
                        break;
                default:
                        break;
        }
        
        double			 s = sqrt (m[i][i] * m[i][i] + m[i][j] * m[i][j]);
        
        CLxVector eAngles;
        
        if (s > 16 * DBL_EPSILON) {
                eAngles[0] = atan2 ( m[j][k], m[k][k]);
                eAngles[1] = atan2 (-m[i][k], s);
                eAngles[2] = atan2 ( m[i][j], m[i][i]);

        }
        else {
                
                eAngles[0] = atan2 (-m[k][j], m[j][j]);
                eAngles[1] = atan2 (-m[i][k], s);
                eAngles[2] = 0.0;
        }
        
        // parity is even if the inner axis X is followed by the middle axis Y,
        // or Y is followed by Z, or Z is followed by X
        
        if ((i == 0 && j != 1) || (i == 1 && j != 2) || (i == 2 && j != 0)) {
                
                // parity is odd - whatever that means
                
                eAngles[0] = -eAngles[0];
                eAngles[1] = -eAngles[1];
                eAngles[2] = -eAngles[2];
        }
        
        
        return eAngles;
};


LxResult
CLxMatrix4::setEuler(const CLxVector &eulerVec, int rotOrd ) {
        return setEuler( eulerVec.x(), eulerVec.y(), eulerVec.z(), rotOrd );
}



LxResult
CLxMatrix4::setEuler(double eulerX,double eulerY,double eulerZ, int rotOrd ) {
        switch ( rotOrd ) {
                case LXi_ROTORD_XYZ:
                        lx::MatrixRotate( m, eulerX, 0 );
                        lx::MatrixRotate( m, eulerY, 1 );
                        lx::MatrixRotate( m, eulerZ, 2 );
                        break;
                case LXi_ROTORD_XZY:
                        lx::MatrixRotate( m, eulerX, 0 );
                        lx::MatrixRotate( m, eulerZ, 2 );
                        lx::MatrixRotate( m, eulerY, 1 );
                        break;
                case LXi_ROTORD_YXZ:
                        lx::MatrixRotate( m, eulerY, 1 );
                        lx::MatrixRotate( m, eulerX, 0 );
                        lx::MatrixRotate( m, eulerZ, 2 );
                        break;
                case LXi_ROTORD_YZX:
                        lx::MatrixRotate( m, eulerY, 1 );
                        lx::MatrixRotate( m, eulerZ, 2 );
                        lx::MatrixRotate( m, eulerX, 0 );
                        break;
                case LXi_ROTORD_ZXY:
                        lx::MatrixRotate( m, eulerZ, 2 );
                        lx::MatrixRotate( m, eulerX, 0 );
                        lx::MatrixRotate( m, eulerY, 1 );
                        break;
                case LXi_ROTORD_ZYX:
                        lx::MatrixRotate( m, eulerZ, 2 );
                        lx::MatrixRotate( m, eulerY, 1 );
                        lx::MatrixRotate( m, eulerX, 0 );
                        break;
                default:
                        return LXe_FAILED;
                        break;
        }
        return LXe_OK;
        
}

void
CLxMatrix4::setAxisAngle(const CLxVector &vec, double angle ) {
        lx::MatrixAxisRotation( m, vec, sin( angle ), cos( angle ) );
}


CLxMatrix4
CLxMatrix4::getMatrix3x3( ) const {
        CLxMatrix4 retM;
        
        for (unsigned char i = 0; i < 3; i++)
                for (unsigned char j = 0; j < 3; j++)
                        retM[i][j] = m[i][j];
        
        return retM;
}

void
CLxMatrix4::getMatrix3x3( LXtMatrix m3) {
        for (unsigned char i = 0; i < 3; i++)
                for (unsigned char j = 0; j < 3; j++)
                        m3[i][j] = m[j][i]; // transposed!
        
        return;
}


CLxMatrix4&
CLxMatrix4::setToIdentity( )  {
        lx::Matrix4Ident(m);
        return *this;
}



const CLxMatrix4&
CLxMatrix4::getIdentity() {
        static const CLxMatrix4 identityQuat;
        return identityQuat;
}



void
CLxMatrix4::set( double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3 ) {
        LXx_VSET3(m[0], x1, y1, z1);
        LXx_VSET3(m[1], x2, y2, z2);
        LXx_VSET3(m[2], x3, y3, z3);
}

void
CLxMatrix4::set( double x1, double y1, double z1, double w1, double x2, double y2, double z2, double w2,
                    double x3, double y3, double z3 , double w3, double x4, double y4, double z4 , double w4 ) {
        LXx_V4SET4(m[0], x1, y1, z1, w1);
        LXx_V4SET4(m[1], x2, y2, z2, w2);
        LXx_V4SET4(m[2], x3, y3, z3, w3);
        LXx_V4SET4(m[3], x4, y4, z4, w4);
}

void
CLxMatrix4::set(const CLxVector &xx, const CLxVector &yy, const CLxVector &zz ) {
        LXx_VSET3(m[0], xx[0], xx[1], xx[2] );
        LXx_VSET3(m[1], yy[0], yy[1], yy[2] );
        LXx_VSET3(m[2], zz[0], zz[1], zz[2] );
}

void
CLxMatrix4::set(int row, int column, double value ) {
        if( row < 0 || row > 3 || column < 0 || column > 3 )
                throw CLxResult(LXe_OUTOFBOUNDS);

        m[row][column] = value;
}

void
CLxMatrix4::setTranslation( const CLxVector &vec  ) {
        LXx_VCPY( m[3], vec );
}

CLxVector
CLxMatrix4::getTranslation(  ) const {
        return CLxVector( m[3] );
}


bool
CLxMatrix4::operator==(const CLxMatrix4& other) const {
        for (unsigned char i = 0; i < 4; ++i)
        {
                for (unsigned char j = 0; j < 4; ++j)
                {
                        if(lx::Compare (m[i][j], other.m[i][j]) != LXi_EQUAL_TO)
                                return false;
                }
        }
        return true;
}

bool
CLxMatrix4::operator!=(const CLxMatrix4& other) const {
        return !(*this == other);
}

bool
CLxMatrix4::epsilonEquals (const CLxMatrix4 &other, double epsilon ) const {
        for (unsigned char i = 0; i < 4; ++i)
                for (unsigned char j = 0; j < 4; ++j)
                        for (unsigned char k = 0; k < 4; ++k)
                                if( fabs(m[i][j] - other.m[i][j] ) > fabs( epsilon ) )
                                        return false;
        return true;
}




CLxMatrix4
CLxMatrix4::asRotateMatrix () const {
        double tran[12];
        CLxMatrix_namespace::Matrix4Decompose( *this, tran, LXi_ROTORD_ZYX );
        
        CLxMatrix4 retM;
        retM.setEuler( tran[CLxMatrix_namespace::U_ROTATEX], tran[CLxMatrix_namespace::U_ROTATEY], tran[CLxMatrix_namespace::U_ROTATEZ], LXi_ROTORD_ZYX );
        return retM;
}

CLxMatrix4
CLxMatrix4::asScaleMatrix () const {
        double tran[12];
        CLxMatrix_namespace::Matrix4Decompose( *this, tran, LXi_ROTORD_ZYX );
        
        CLxMatrix4 retM;
        retM[0][0] = tran[CLxMatrix_namespace::U_SCALEX];
        retM[1][1] = tran[CLxMatrix_namespace::U_SCALEY];
        retM[2][2] = tran[CLxMatrix_namespace::U_SCALEZ];
        return retM;
}


CLxMatrix4::operator LXtMatrix4&() {
        return(m);
}


double*
CLxMatrix4::operator[] (unsigned int i) {
        if( i > 4 )
                throw CLxResult(LXe_OUTOFBOUNDS);
        else
                return m[i];
}

const double*
CLxMatrix4::operator[] (unsigned int i) const {
        if( i > 4 )
                throw CLxResult(LXe_OUTOFBOUNDS);
        else
                return m[i];
}




std::ostream&
operator<< (std::ostream& stream, const CLxMatrix4& mat) {
        stream << "[" ;
        for (unsigned char i = 0; i < 4; ++i) {
                stream << "[" ;
                stream << mat.m[i][0] << ',' ;
                stream << mat.m[i][1] << ',' ;
                stream << mat.m[i][2] << ',' ;
                stream << mat.m[i][3] << ']' ;
        }
        stream << "]" ;
        
        return stream;
}

