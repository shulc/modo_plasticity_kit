/*
* Plug-in SDK Source: Geometry Triangulation Utilities
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
* Polygon Triangulation - this triangulation function (TriangulateFace ()) is 1-1 compatible 
* with Modo's internal polygon triangulation. This is useful, for example, when 3rd party apps
* are loading data from .lxo files and exact triangulation is needed for normal mapping and
* exact shading between Modo and respective 3rd party apps.
* 
* Note that large polygon (> 1024 vertices) TriangulateLargeFacePolygon () results depend
* on a random seed, so 1-1 triangulation compatibility is not possible at this point. 
* Workaround for this issue is to keep the per-polygon vertices number <= 1024, which we 
* deem to be quite reasonable.
*
* Note for Modo devs: This code has to be kept 1-1 in sync with internal triangulation code,
* for it to be useful to 3rd parties.
*/
#include <lxu_geometry_triangulation.hpp>

#include <math.h>

using namespace std;
using namespace lx;

#define TESTAXISf_MATRIX	1
#define TESTAXISf_INVERSE	2


#define TRIMAX_ISECT		128
#define TRIMAX_TRY		50
#define TRIMAX_NVERT		1024
#define TRIMAX_DEPTH		50

#define TWOPI		(6.2831853071795864769252867665590)

#define ND		 3
typedef double		 Matrix[ND][ND];
typedef double		 Vector[ND];

#define PX(v)           ((v)[tax->ix])
#define PY(v)           ((v)[tax->iy])

struct PosVec {
        LXtFVector v;
};

struct TestAxis {
        int		axis;
        int		ix, iy;
        int		flags;
        Matrix		m, mInv;
};

        int
AxisMaxExtentF (LXtVector v)
{
        if (LXxABS (v[0]) > LXxABS (v[1]) && LXxABS (v[0]) > LXxABS (v[2]))
                return 0;
        else if (LXxABS (v[1]) >= LXxABS (v[0]) && LXxABS (v[1]) > LXxABS (v[2]))
                return 1;
        else
                return 2;
}

// The axis acts as a valid flag and is set to 3 if the polygon is degenerate.
        int
ComputeFaceAxis (LXtVector polyGeoNormal)
{
        if (polyGeoNormal && (LXx_VDOT (polyGeoNormal, polyGeoNormal) > 0.0))
                return AxisMaxExtentF (polyGeoNormal);
        else
                return 3;
}

// This function takes an axis as input and computes the two axes which are
// orthogonal to that one.  The result is left-handed if the input axis is
// treated as "az" in the triple.
        void
AxisGetNormals (
        int			 axis,
        int			*ax,
        int			*ay)
{
        static const int	 axis0[] = { 1, 2, 0 };
        static const int	 axis1[] = { 2, 0, 1 };

        //ASSERT (axis >= 0 && axis < ND);
        *ax = axis0[axis];
        *ay = axis1[axis];
}

// This function sets the input matrix to be the indentity matrix, with zeros
// everywhere except on the diagonal.
        void
MatrixIdent (
        Matrix			 m)
{
        m[0][0] = m[1][1] = m[2][2] = 1.0;
        m[0][1] = m[0][2] = 0.0;
        m[1][0] = m[1][2] = 0.0;
        m[2][0] = m[2][1] = 0.0;
}

// This function sets a test axis plane for polygon calculations.This takes
// the perpendicular axis and picks the other two in a nice way.
        void
AxisTestSet (
        TestAxis		*tax,
        int			 axis)
{
        tax->axis = axis;
        AxisGetNormals (axis, &tax->ix, &tax->iy);
        MatrixIdent (tax->m);
        MatrixIdent (tax->mInv);
        tax->flags = 0;
}

        int
PolyOrientation (
        std::vector<PosVec>	&points,
        const TestAxis		*tax,
        unsigned int		 vertsNo)
{
        double			 v0[2], v1[2];
        double			 area;
        int			 i;

        /*
        * Do the wrap-around first.
        */
        v0[0] = points[0].v[tax->ix];
        v0[1] = points[0].v[tax->iy];
        v1[0] = points[vertsNo - 1].v[tax->ix];
        v1[1] = points[vertsNo - 1].v[tax->iy];
        area = v1[0] * v0[1] - v0[0] * v1[1];

        /*
        * Compute the area (times 2) of the polygon where sign gives
        * orientation.
        */
        for (i = 0; i < vertsNo - 1; i++)
        {
                v1[0] = points[i + 1].v[tax->ix];
                v1[1] = points[i + 1].v[tax->iy];
                area += v0[0] * v1[1] - v1[0] * v0[1];
                v0[0] = v1[0];
                v0[1] = v1[1];
        }

        return (area >= 0.0);
}

// Return triangle area * 2 with sign for direction.  Triangle given by
// three sequential vertices.
        double
TriDeterm (
        const TestAxis		*tax,
        const float		*p1,
        const float		*p2,
        const float		*p3)
{
        double			 a, b;

        a = (p2[tax->ix] - p1[tax->ix]) * (p3[tax->iy] - p1[tax->iy]);
        b = (p3[tax->ix] - p1[tax->ix]) * (p2[tax->iy] - p1[tax->iy]);

        return a - b;
}

        double
TriArea (
        const float		*p1,
        const float		*p2,
        const float		*p3)
{
        Vector			 A, B;
        double			 AB, AR;

        LXx_VSUB3 (A, p2, p1);
        LXx_VSUB3 (B, p3, p1);
        AB = LXx_VDOT (A, B);
        AR = LXx_VDOT (A, A) * LXx_VDOT (B, B) - AB * AB;
        if (AR > 0.0)
                return AR;
        else
                return 0.0;
}

// Return triangle orientation: same sense as above.  Triangle is given by three
// vertices.
        int
TriOrient (
        const TestAxis		*tax,
        const float		*p1,
        const float		*p2,
        const float		*p3)
{
        return TriDeterm (tax, p1, p2, p3) >= 0.0;
}

//Return false if the three vertices are on the same line, otherwise this compares
//the orients.

        int
TestTriCorner (
        const TestAxis		*tax,
        const float		*p1,
        const float		*p2,
        const float		*p3,
        int			 ori)
{
        double			 det;

        det = TriDeterm (tax, p1, p2, p3);
        if (!det)
                return 0;

        return (det > 0.0) == ori;

}

// Returns true if none of the vertices in the array is inside the given triangle
// and the triangle matches the orientation of the parent polygon.
        int
GoodTriangle (
        const TestAxis		*tax,
        std::vector<int>&	 nl,
        std::vector<PosVec>&	 pl,
        int			 n,
        int			 ori,
        int			 n1,
        int			 n2,
        int			 n3)
{
        const float		*p1, *p2, *p3, *p;
        int			 i;

        /*
        * Not good if orientation does not match.
        */
        p1 = pl[n1].v;
        p2 = pl[n2].v;
        p3 = pl[n3].v;
        if (TriOrient (tax, p1, p2, p3) != ori)
                return 0;

        for (i = 0; i < n; i++)
        {
                p = pl[nl[i]].v;

                /*
                * Don't bother checking the triangle corners.
                */
                if ((p == p1) || (p == p2) || (p == p3))
                        continue;

                if (TestTriCorner (tax, p2, p1, p, ori)
                        || TestTriCorner (tax, p1, p3, p, ori)
                        || TestTriCorner (tax, p3, p2, p, ori))
                {
                        continue;	/* point is outside */
                }
                else
                        return 0;	/* point is inside */
        }
        return 1;
}

        int
Face_GoodPoint (
        const TestAxis		*tax,
        int			 ori,
        int			 nvert,
        std::vector<int>&	 nl,
        std::vector<PosVec>&	 pl)
{
        double			 d;
        int			 ok, i, m, n1, n2, n3;

        d = 0.0;
        n2 = nl[nvert - 1];
        n3 = nl[0];
        ok = 0;
        // It is not necessary to test 3rd and 4th corners for quadrangle.
        m = (nvert == 4) ? 2 : nvert;
        for (i = 0; i < m; i++)
        {
                n1 = n2;
                n2 = n3;
                n3 = nl[(i + 1) % nvert];

                if (GoodTriangle (tax, nl, pl, nvert, ori, n1, n2, n3))
                {
                        ok = 1;
                        break;
                }

                d += TriArea (pl[n1].v, pl[n2].v, pl[n3].v);
        }
        if (!ok)
        {
                if (d > 4.0e-16)
                {
                        //ASSERT (0);
                        i = 0;
                }
                else
                {
                        n1 = nl[nvert - 1];
                        n2 = nl[0];
                        n3 = nl[1];
                        i = 0;
                }
        }
        return i;
}

        void
Face_LoopCenter (
        const TestAxis		*tax,
        int			 nvert,
        std::vector<int>&	 nl,
        std::vector<PosVec>&	 pl,
        Vector&			 cent)
{
        double			 s;
        const float		*fx;
        int			 i;

        LXx_VCLR (cent);
        for (i = 0; i < nvert; i++)
        {
                fx = pl[nl[i]].v;
                LXx_VADD (cent, fx);
        }

        s = 1.0 / (double)nvert;
        LXx_VSCL (cent, s);
}

        int
Face_Intersect (
        const TestAxis		*tax,
        int			 nvert,
        std::vector<int>&	 nl,
        std::vector<PosVec>&	 pl,
        Vector			 cent,
        double			 angle,
        int			*ix,
        double			*tx)
{
        int			 i, j, k, nx = 0;
        double			 s, t;
        double			 x0, y0, x1, y1, x2, y2, x3, y3;
        const float		*fv;

        x0 = cent[tax->ix];
        y0 = cent[tax->iy];
        x1 = x0 + cos (angle);
        y1 = y0 + sin (angle);
        fv = pl[nl[0]].v;
        x2 = fv[tax->ix];
        y2 = fv[tax->iy];
        for (i = 0; i < nvert; i++)
        {
                fv = pl[nl[(i + 1) % nvert]].v;
                x3 = fv[tax->ix];
                y3 = fv[tax->iy];
                s = ((x3 - x2) * (y2 - y0) - (y3 - y2) * (x2 - x0)) /
                        ((x3 - x2) * (y1 - y0) - (y3 - y2) * (x1 - x0));
                t = ((x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0)) /
                        ((x3 - x2) * (y1 - y0) - (y3 - y2) * (x1 - x0));
                x2 = x3;
                y2 = y3;
                if (t < 0.0 || t > 1.0)
                        continue;
                if (nx >= TRIMAX_ISECT)
                        return 0;
                ix[nx] = i;
                tx[nx] = s;
                nx++;
        }

        if (nx == 0 || nx % 2)
                return 0;

        for (i = 0; i < nx - 1; i++)
        {
                t = tx[i];
                k = i;
                for (j = i + 1; j < nx; j++)
                {
                        if (tx[j] > t)
                        {
                                t = tx[j];
                                k = j;
                        }
                }
                if (k != i)
                {
                        t = tx[i]; tx[i] = tx[k]; tx[k] = t;
                        j = ix[i]; ix[i] = ix[k]; ix[k] = j;
                }
        }

        return nx;
}

// Line distance using simple metric, floating point version.
        double
LineDistance (
        double		x0,
        double		y0,
        double		x1,
        double		y1,
        double		mx,
        double		my)
{
        double		ax, bx, ay, by;
        double		dx, dy;
        int		xok = 0, yok = 0;

        dx = HUGE_VAL;

        ax = x0 - mx;
        ay = y0 - my;
        bx = x1 - x0;
        by = y1 - y0;

        if (by > 0.0)
        {
                if (ay <= 0.0 && -ay <= by)
                        xok = 1;
        }
        else if (by < 0.0)
        {
                if (ay >= 0.0 && -ay >= by)
                        xok = 1;
        }
        if (xok)
        {
                dx = ax - (bx * ay) / by;
                if (dx < 0.0)
                        dx = -dx;
        }
        if (bx > 0.0)
        {
                if (ax <= 0.0 && -ax <= bx)
                        yok = 1;
        }
        else if (bx < 0.0)
        {
                if (ax >= 0.0 && -ax >= bx)
                        yok = 1;
        }
        if (yok)
        {
                dy = ay - (by * ax) / bx;
                if (dy < 0.0)
                        dy = -dy;
                if ((xok && dy < dx) || (!xok))
                        dx = dy;
        }
        else if (bx == 0.0 && by == 0.0)
        {
                dx = ax;
                if (dx < 0.0)
                        dx = -dx;
                if (ay < 0.0)
                        ay = -ay;
                if (ay > dx)
                        dx = ay;
        }
        return dx;
}


/*
        Intersecting two edges can give an intersection point at one of the two
        ends, in the middle or nowhere.
*/

#define EI_MID		0
#define EI_END0		1
#define EI_END1		2
#define EI_NONE		3

/*
        Computation with floating point numbers means dealing with round-off errors.
        The method used here is to allow a respectable tolerance for errors based on
        the magnitude of each floating point value.  If the value represents meters,
        then a measure of exactly one meter is valid to within about 34 microns, and
        the smallest value that can be accurately represented is about 0.001
        nanometers.  These values are adequate for real-world applications while
        tolerating the buildup of errors in the low bits of the mantissas of single
        precision IEEE floating point values.

        This function returns a tolerance value for any given input.  The value
        returned will be a positive number which is much smaller in magnitude than
        the input, representing the minimum change required to make this value
        different.
*/
        double
DToleranceTri (
        double			 m)
{
#define MIN_PRECISION	(1.0e-10)

        if (m < 0.0)
                m /= -3.36e6;
        else
                m /= 3.36e6;

        if (m > MIN_PRECISION)
                return (m);
        else
                return (MIN_PRECISION);
}

#define ARAND 16807
#define MRAND 2147483647
#define QRAND 127773
#define RRAND 2836

static int rand_seed = 1;

// This returns a floating point random number in the range of 0.0 to 1.0.
        float
FRandom (void)
{
        // << Random: Advance seed >>
        /*
        The result is that the seed advances through a pseudo-random sequence with seed
        ranging from 0 to MRAND.  The particular magic constants used here are
        discussed in numerous articles on the net.
        */
        int			 hi, lo, test;

        hi = rand_seed / QRAND;
        lo = rand_seed % QRAND;
        test = ARAND * lo - RRAND * hi;
        rand_seed = (test > 0) ? test : test + MRAND;

        return (rand_seed * (1.0 / (float)MRAND));
}

/*
        Return true if the given value (x) lies within the bounds (x0,x1)
        plus tolerance.
*/
        int
InBounds (
        double			x,
        double			x0,
        double			x1,
        double			tol)
{
        double			t;

        if (x0 > x1)
        {
                t = x0;
                x0 = x1;
                x1 = t;
        }
        return (x > x0 - tol && x < x1 + tol);
}

/*
        Find the intersection point between two line segments allowing a tolerance
        for vertex intersections.  Intersection is returned in frac as a fraction
        along line between v0 and v1.  The return code indicates if there was an
        intersection and if so, if it was on one of the vertices.  Tax gives the
        plane in which to compute the intersection.
*/
        int
EdgeIntersectTolByPos (
        const TestAxis		*tax,
        const Vector		 v0,
        const Vector		 v1,
        const Vector		 p0,
        const Vector		 p1,
        double			 tol,
        double			*frac)
{
        double			 v0x, v0y, v1x, v1y, p0x, p0y, p1x, p1y;
        double			 dpx, dpy, dvx, dvy, d0x, d0y;
        double			 det;
        double			 t;

        v0x = PX (v0);	v0y = PY (v0);
        v1x = PX (v1);	v1y = PY (v1);
        p0x = PX (p0);	p0y = PY (p0);
        p1x = PX (p1);	p1y = PY (p1);

        //<< Edge Intersection >>

        /*
        * Calculate some useful differences.
        */
        dpx = p1x - p0x;	dpy = p1y - p0y;
        dvx = v1x - v0x;	dvy = v1y - v0y;
        d0x = p0x - v0x;	d0y = p0y - v0y;

        /*
        * Test if v0 lies on P including tolerance zones.  If so, return
        * v0 as intersection point.
        */
        if (LineDistance (p0x, p0y, p1x, p1y, v0x, v0y) < tol)
        {
                *frac = 0.0;
                return EI_END0;
        }

        /*
        * Test if v1 lies on P including tolerance zones.  If so, return
        * v1 as intersection point.
        */
        if (LineDistance (p0x, p0y, p1x, p1y, v1x, v1y) < tol)
        {
                *frac = 1.0;
                return EI_END1;
        }

        /*
        * Calculate determinant and drop out if it is zero.  This may need
        * refinement, because lines could still interact within the tolerance
        * even if they are parallel.
        */
        det = dvy * dpx - dpy * dvx;
        if (det == 0.0)
        {
                /*
                #ifndef RELEASE
                if (p0 == p1)
                DBprintf ("EdgeIntersectTol DET is ZERO: EI_NONE\n");
                #endif
                */
                return EI_NONE;
        }

        /*
        * Get fraction along V from v0 to v1.	This will either be clearly
        * within the segment or clearly outside the range, since the end
        * cases have already been tested for.
        */
        t = (dpx * d0y - dpy * d0x) / det;
        if (t <= 0.0 || t >= 1.0)
                return EI_NONE;

        /*
        * Test if the intersection point is in the tolerance range for P.
        * If so, this is a valid P intersection as well as V.
        */
        if (fabs (dpx) > fabs (dpy))
        {
                if (!InBounds (v0x + t * dvx, p0x, p1x, tol))
                        return EI_NONE;
        }
        else
        {
                if (!InBounds (v0y + t * dvy, p0y, p1y, tol))
                        return EI_NONE;
        }

        *frac = t;
        return EI_MID;
}

// Return true if p1-p2 will be a brige to split the vertex list.
        int
Face_TestBridge (
        const TestAxis		*tax,
        int			 nvert,
        std::vector<int>&	 nl,
        std::vector<PosVec>&	 pl,
        int			 p1,
        int			 p2)
{
        Vector			 v1, v2, x1, x2;
        const float		*fv;
        double			 tol, tol2, t, dx, dy, x;
        double			 vx, vy, px, py, cx, cy, cdx, cdy, pdy;
        int			 i, j, k, kin, n1, n2;

        /*
        * Return false if 'p1', 'p2' are used as a bridge edge for the loop.
        */
        n1 = n2 = 0;
        for (i = 0; i < nvert; i++)
        {
                if (p1 == nl[i]) n1++;
                if (p2 == nl[i]) n2++;
        }
        if (n1 != 1 || n2 != 1)
                return 0;

        /*
        * Test intersection between p1-p2 and all of edges except ones connected
        * to p1 or p2.
        */
        tol = DToleranceTri (0.0);

        fv = pl[p1].v;
        LXx_VCPY (v1, fv);
        fv = pl[p2].v;
        LXx_VCPY (v2, fv);

        fv = pl[nl[0]].v;
        LXx_VCPY (x1, fv);
        for (i = 0; i < nvert; i++)
        {
                j = (i + 1) % nvert;
                fv = pl[nl[j]].v;
                LXx_VCPY (x2, fv);
                if (nl[i] != p1 && nl[i] != p2 && nl[j] != p1 && nl[j] != p2)
                {
                        kin = EdgeIntersectTolByPos (tax, v1, v2, x1, x2, tol, &t);
                        if (kin != EI_NONE)
                                return 0;
                }
                LXx_VCPY (x1, x2);
        }

        /*
        * Determine if the given point is inside the polygon given by the
        * vertex list in the given test plane.
        */
        k = 0;
        LXx_VADD (v1, v2);
        LXx_VSCL (v1, 0.5);

        vx = v1[tax->ix];
        vy = v1[tax->iy];

        fv = pl[nl[nvert - 1]].v;
        px = fv[tax->ix];
        py = fv[tax->iy];
        for (i = 0; i < nvert; i++)
        {
                fv = pl[nl[i]].v;
                cx = fv[tax->ix];
                cy = fv[tax->iy];

                cdx = vx - cx;
                cdy = vy - cy;
                pdy = vy - py;

                /*
                * Test for intolerant cases before making the line
                * intersection test and calculation.
                */
                if (fabs (cdy) < tol)
                {
                        /*
                        * First check to see that the given point does not
                        * lie on the current vertex.
                        */
                        if (fabs (cdx) < tol)
                                return 0;

                        /*
                        * Check for an edge that passes horizontally through
                        * the point and reject those.
                        */
                        if (fabs (pdy) < tol && ((vx < px) ^ (vx < cx)))
                                return 0;
                }

                /*
                * Intersection test is reasonable.
                */
                if ((cy > vy) ^ (py > vy))
                {
                        /*
                        * In addition to calculating the intersection point,
                        * we need to get a measure for the tolerance, taking
                        * the slope of the line into account.
                        */
                        dx = px - cx;
                        dy = py - cy;
                        tol2 = tol * sqrt (dx * dx + dy * dy) / dy;
                        x = cdy * dx / dy - cdx;

                        /*
                        * If the intersection falls within the tolerance,
                        * the point lies in the edge and is indeterminate.
                        */
                        if (fabs (x) < tol2)
                                return 0;

                        if (x > 0.0)
                                k++;
                }
                px = cx;
                py = cy;
        }

        return k % 2;
}

        int
Face_SplitList (
        const TestAxis		*tax,
        int			 nvert,
        std::vector<int>&	 nl,
        std::vector<PosVec>&	 pl,
        int			*i1,
        int			*i2,
        int			*n1,
        int			*n2,
        int			*depth,
        int			*badFace)
{
        int			 ix[TRIMAX_ISECT];
        double			 tx[TRIMAX_ISECT];
        Vector			 cent;
        double			 angle;
        int			 i, j, nx;

        *badFace = 0;

        if (nvert < TRIMAX_NVERT)
                return 0;

        if (depth[0] > TRIMAX_DEPTH)
                return 0;

        Face_LoopCenter (tax, nvert, nl, pl, cent);

        for (j = 0; j < TRIMAX_TRY; j++)
        {
                angle = FRandom () * TWOPI;
                nx = Face_Intersect (tax, nvert, nl, pl, cent, angle, ix, tx);
                if (nx == 0)
                        continue;
                for (i = 0; i < nx; i += 2)
                {
                        *i1 = ix[i];
                        *i2 = ix[i + 1];
                        if (*i2 > *i1)
                        {
                                *n1 = *i2 - *i1 + 1;
                                *n2 = nvert - *n1 + 2;
                        }
                        else
                        {
                                *n1 = *i2 - *i1 + nvert + 1;
                                *n2 = nvert - *n1 + 2;
                        }
                        if (*n1 > 3 && *n2 > 3)
                        {
                                if (Face_TestBridge (tax, nvert, nl, pl, nl[*i1], nl[*i2]))
                                {
                                        depth[0] ++;
                                        return 1;
                                }
                        }
                }
        }

        *i1 = 0;
        *i2 = 0;
        *n1 = nvert;
        *n2 = 0;
        *badFace = 1;
        return 0;
}

        void
Face_Output (
        std::vector<unsigned short>&	 triBuf,
        unsigned int&			 triBufInd,
        int				 n0,
        int				 n1,
        int				 n2)
{
        triBuf[triBufInd++] = n0;
        triBuf[triBufInd++] = n1;
        triBuf[triBufInd++] = n2;
}

        void
Face_VertexList (
        std::vector<unsigned short>&	 triBuf,
        unsigned int&			 triBufInd,
        const TestAxis			*tax,
        int				 ori,
        int				 reverse,
        int				 nvert,
        std::vector<int>&		 nl,
        std::vector<PosVec>&		 pl,
        int				*depth)
{

        int			 vp, vc, vn;
        int			 i, ivert, i1, i2, n1, n2, badFace = 0;

        if (Face_SplitList (tax, nvert, nl, pl, &i1, &i2, &n1, &n2, depth, &badFace))
        {
                vector<int>		 vl (nvert);

                for (i = 0; i < n1; i++)
                        vl[i] = nl[(i + i1) % nvert];
                Face_VertexList (triBuf, triBufInd, tax, ori, reverse, n1, vl, pl, depth);

                for (i = 0; i < n2; i++)
                        vl[i] = nl[(i + i2) % nvert];
                Face_VertexList (triBuf, triBufInd, tax, ori, reverse, n2, vl, pl, depth);

                return;
        }

        /*
        * Clear unused indices when split is failed at top level. (#56155)
        */
        if (badFace && (depth[0] == 0))
        {
                for (i = 0; i < 3 * (nvert - 2); i++)
                        triBuf[i] = 0;
                return;
        }

        /*
        * Slice off clean triangles until nothing remains.  Pick a point
        * which is a corner and slice it off, shrinking the polygon as
        * we go.
        */
        while (nvert > 3)
        {
                /*
                * Loop through remaining vertices and find a good one.
                */
                ivert = Face_GoodPoint (tax, ori, nvert, nl, pl);

                /*
                * Create best triangle.
                */
                vp = nl[(ivert + nvert - 1) % nvert];
                vc = nl[ivert];
                vn = nl[(ivert + 1) % nvert];
                if (reverse)
                        Face_Output (triBuf, triBufInd, vp, vn, vc);
                else
                        Face_Output (triBuf, triBufInd, vp, vc, vn);

                /*
                * Remove the triangle from the polygon.
                */
                nvert -= 1;
                for (i = ivert; i < nvert; i++)
                        nl[i] = nl[i + 1];
        }

        /*
        * Create the final triangle.
        */
        if (reverse)
                Face_Output (triBuf, triBufInd, nl[0], nl[2], nl[1]);
        else
                Face_Output (triBuf, triBufInd, nl[0], nl[1], nl[2]);
}

        void
TriangulateLargeFacePolygon (	std::vector<unsigned short>&	 triBuf,
                                std::vector<PosVec>&		 pl,  // vertex (point) positions
                                const TestAxis			*tax,
                                unsigned int			 trisNo,
                                unsigned int			 vertsNo,
                                int				 ori,
                                int				 reverse)
{
        unsigned int		 triBufInd = 0;
        int			 depth = 0;
        int			 i;
        std::vector<int>	 nl (vertsNo);

        for (i = 0; i < vertsNo; i++)
                nl[i] = i;

        Face_VertexList (triBuf, triBufInd, tax, ori, reverse, vertsNo, nl, pl, &depth);
}


/*
        The index array is initialized with the vertices in linear sequence.  As long
        as there are more than three vertices in the array, we'll pick a convex one and
        make a triangle.  We perform a brute force search for a convex vertex, spin it
        off as a triangle in the triBuf and then compress the array.  We might do
        better by pulling polygons off in GL triangle-strip order, but we can try that
        later.  When there is only one left, we generate it directly, which saves some
        possible failures.
*/
        void
TriangulateGeneralFacePolygon (std::vector<unsigned short>&	 triBuf,
        std::vector<PosVec>&		 points,
        const TestAxis			*tax,
        unsigned int			 trisNo,
        unsigned int			 vertsNo,
        int				 ori,
        int				 reverse)
{
        double				 d;
        int				 i, j, k, m, n, n1, n2, n3, ok;
        std::vector<int>		 nl (vertsNo);

        n = vertsNo;
        for (i = 0; i < vertsNo; i++)
                nl[i] = i;

        k = 0;
        n1 = 0;
        while (n > 3)
        {
                d = 0.0;
                n2 = nl[n - 1];
                n3 = nl[0];
                ok = 0;
                // It is not necessary to test 3rd and 4th corners for quadrangle.
                m = (n == 4) ? 2 : n;
                for (i = 0; i < m; i++)
                {
                        n1 = n2;
                        n2 = n3;
                        n3 = nl[(i + 1) % n];

                        if (GoodTriangle (tax, nl, points, n, ori, n1, n2, n3))
                        {
                                ok = 1;
                                break;
                        }

                        d += TriArea (points[n1].v, points[n2].v, points[n3].v);
                }
                if (!ok)
                {
                        if (d > 4.0e-16)
                        {
                                //ASSERT (0);
                                break;
                        }
                        else
                        {
                                // use any triangle if the total area is 0. (#10334)
                                n1 = nl[n - 1];
                                n2 = nl[0];
                                n3 = nl[1];
                                i = 0;
                        }
                }

                triBuf[k++] = n2;
                if (reverse)
                {
                        triBuf[k++] = n1;
                        triBuf[k++] = n3;
                }
                else
                {
                        triBuf[k++] = n3;
                        triBuf[k++] = n1;
                }

                n--;
                for (j = i; j < n; j++)
                        nl[j] = nl[j + 1];
        }

        triBuf[k++] = nl[1];
        if (reverse)
        {
                triBuf[k++] = nl[0];
                triBuf[k++] = nl[2];
        }
        else
        {
                triBuf[k++] = nl[2];
                triBuf[k++] = nl[0];
        }

        // Clear unused indices when triangulation is failed at line 3990. (#43103)
        for (i = k; i < 3 * (vertsNo - 2); i++)
                triBuf[i] = 0;

        // ASSERT (k == 3 * (vertsNo - 2));
}

        std::vector<GeoTriangle>
lx::TriangulateFace (	CLxUser_Polygon&	poly,
                        CLxUser_Point&		point)
{
        LXtVector			polyNormal;
        int				polyAxis;
        std::vector<PosVec>		points;
        std::vector<GeoTriangle>	ret;
        unsigned int			vertsNo;
        LXtPointID			vID;
        int				ori, reverse;
        int				i, k;
        TestAxis			tax;

        poly.Normal (polyNormal);

        polyAxis = ComputeFaceAxis (polyNormal);

        poly.VertexCount (&vertsNo);

        if (vertsNo == 3)
        {
                GeoTriangle tmp;
                tmp.v0 = 0;
                tmp.v1 = 1;
                tmp.v2 = 2;
                ret.push_back (tmp);
                return ret;
        }

        for (int vInd = 0; vInd < vertsNo; vInd++)
        {
                LXtFVector	tmpPos;
                PosVec		tmpPosVec;

                poly.VertexByIndex (vInd, &vID);

                point.Select (vID);

                point.Pos (tmpPos);
                LXx_VCPY (tmpPosVec.v, tmpPos);
                points.push_back (tmpPosVec);
        }

        if (polyAxis < 3)
        {
                AxisTestSet (&tax, polyAxis);

                i = (polyNormal[tax.axis] < 0.0);

                ori = PolyOrientation (points, &tax, vertsNo);
                reverse = ((i ^ ori) == 0);
        }
        else
        {
                AxisTestSet (&tax, 0);
                ori = PolyOrientation (points, &tax, vertsNo);
                reverse = 0;
        }

        k = 3 * (vertsNo - 2);
        ret.resize (k / 3);

        std::vector<unsigned short>	triBuf;
        triBuf.resize (k);

        // TRIMAX_POLY_NVERT is still rough threshold to use new triangulation method. (Bug 57879)
        if (vertsNo > TRIMAX_NVERT)
        {
                TriangulateLargeFacePolygon (triBuf, points, &tax, k, vertsNo, ori, reverse);
        }
        else
        {
                TriangulateGeneralFacePolygon (triBuf, points, &tax, k, vertsNo, ori, reverse);
        }

        for (int j = 0; j < k / 3; j++)
        {
                ret[j].v0 = triBuf[j * 3 + 0];
                ret[j].v1 = triBuf[j * 3 + 1];
                ret[j].v2 = triBuf[j * 3 + 2];
        }

        return ret;
}
