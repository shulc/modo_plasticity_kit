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

#ifndef LX_OCTREE_HPP
#define LX_OCTREE_HPP

#include <lxu_vector.hpp>
#include <lxu_vectorarray.hpp>

#include <vector>

class CLxOcTree {
        void *data;
public:
        CLxOcTree () ;
        ~CLxOcTree () ;
        
        void    clear ()  ;
        size_t  size () ;
        bool    empty () ;
        
        int     addPoint      (const CLxVector &pos, void *data = NULL) ;

        void    addPoints     (const CLxVectorArray &posArray) ;
        
        int     nearestNeighbors (CLxVector &pos, double radius, int maxRet, std::vector<int> &indices, std::vector<double> &dists,
                                    std::vector<void*> &datas) const ;
        
        int     nearestNeighbors (CLxVector &pos, double radius, int maxRet, std::vector<int> &indices, std::vector<double> &dists) const ;
};


#endif	/* LX_OCTREE_HPP */

