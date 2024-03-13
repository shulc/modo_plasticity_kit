/*
 * Plug-in SDK Header: Geometry Utilities
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
 * Provides geometry utility functions for C++ plug-ins.
 */

#ifndef LXU_GEOMETRY_HPP
#define LXU_GEOMETRY_HPP

#include <lxvmath.h>
#include <vector>

        namespace lx
        {

/*
 * Points for standard template containers.
 */
struct GeoPoint
{
        LXtVector vec;
};

struct GeoUV
{
        LXtFVector2 uv;
};

/*
 * Generate vertex normals for a triangle list,
 * with normal smoothing for shared vertices.
 */
        void
GenerateNormals (
        std::vector<GeoPoint>	&points,
        std::vector<unsigned>	&triangles,
        std::vector<GeoPoint>	&normals);

/*
 * Generate vertex normals for a convex polygon list,
 * with normal smoothing for shared vertices.
 */
        void
GeneratePolyNormals (
        std::vector<GeoPoint>	&points,
        std::vector<unsigned>	&polyInds,
        std::vector<unsigned>	&polyCounts,
        std::vector<GeoPoint>	&normals);

/*
 * Generate vertex dPdu/dPdv values, with smoothing for shared vertices.
 */
        void
GenerateDPDUs (
        std::vector<GeoPoint>	&points,
        std::vector<GeoUV>	&uvs,
        std::vector<unsigned>	&triangles,
        std::vector<GeoPoint>	&dPdus,
        std::vector<GeoPoint>	&dPdvs);

        void
GeneratePolyDPDUs (
        std::vector<GeoPoint>	&points,
        std::vector<GeoUV>		&uvs,
        bool					uvsFacevarying,
        std::vector<unsigned>	&polyInds,
        std::vector<unsigned>	&polyCounts,
        std::vector<GeoPoint>	&dPdus,
        std::vector<GeoPoint>	&dPdvs);

        };	// END lx namespace

#endif // LXU_GEOMETRY_HPP

