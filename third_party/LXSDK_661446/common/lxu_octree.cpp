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
#include <lxu_octree.hpp>
#include <lxu_vectorarray.hpp>
#include <lxu_oqtree.hpp>

#define OCTREE_DIM 3

struct ocTreeData {
        void	*data;
};

CLxOcTree::CLxOcTree () {
        data = new oqTree<ocTreeData,OCTREE_DIM>;
}

CLxOcTree::~CLxOcTree () {
        delete (oqTree<ocTreeData,OCTREE_DIM>*)data;
}

void
CLxOcTree::clear ()  {
        oqTree<ocTreeData,OCTREE_DIM> *tree =  (oqTree<ocTreeData,OCTREE_DIM>*)(this->data);
        tree->clear();
}

size_t
CLxOcTree::size () {
        oqTree<ocTreeData,OCTREE_DIM> *tree =  (oqTree<ocTreeData,OCTREE_DIM>*)(this->data);
        return tree->size();
}

bool
CLxOcTree::empty () {
        oqTree<ocTreeData,OCTREE_DIM> *tree =  (oqTree<ocTreeData,OCTREE_DIM>*)(this->data);
        return tree->empty();
        
}

int
CLxOcTree::addPoint (const CLxVector &pos, void *in_data) {
        oqTree<ocTreeData,OCTREE_DIM> *tree =  (oqTree<ocTreeData,OCTREE_DIM>*)(this->data);
        return tree->AddPoint(pos.v, (ocTreeData*)in_data);
}
/*
void
CLxOcTree::addPoints (const CLxVectorArray &posArray) {
        oqTree<ocTreeData,OCTREE_DIM> *tree =  (oqTree<ocTreeData,OCTREE_DIM>*)(this->data);

        for( unsigned int ii = 0, ni = posArray.size() ; ii < ni ; ++ii ) {
                tree->AddPoint(posArray[ii].v, (ocTreeData*)NULL);
        }
}
*/
int
CLxOcTree::nearestNeighbors (CLxVector &pos, double maxDist, int max, std::vector<int> &indices, std::vector<double> &dists,
                                     std::vector<void*> &datas) const
{
        oqTree<ocTreeData,OCTREE_DIM> *tree =  (oqTree<ocTreeData,OCTREE_DIM>*)(this->data);
        oqTree<ocTreeData,OCTREE_DIM>::Neighbor	 *reslt = new oqTree<ocTreeData,OCTREE_DIM>::Neighbor[max];
        
        int n = tree->NearestNeighbors (pos.v, maxDist, reslt, max);
        
        indices.reserve(n);
        datas.reserve(n);
        dists.reserve(n);
        
        for(int ii = 0 ; ii < n ; ++ii ) {
                indices.push_back(reslt[ii].index);
                datas.push_back(reslt[ii].data);
                dists.push_back( sqrt( reslt[ii].d2 ) );
        }
        
        delete [] reslt;
        
        return n;
}


int
CLxOcTree::nearestNeighbors (CLxVector &pos, double maxDist, int max, std::vector<int> &indices, std::vector<double> &dists) const {
        oqTree<ocTreeData,OCTREE_DIM> *tree =  (oqTree<ocTreeData,OCTREE_DIM>*)(this->data);
        oqTree<ocTreeData,OCTREE_DIM>::Neighbor	 *reslt = new oqTree<ocTreeData,OCTREE_DIM>::Neighbor[max];
        
        int n = tree->NearestNeighbors (pos.v, maxDist, reslt, max);
        
        indices.reserve(n);
        dists.reserve(n);
        
        for(int ii = 0 ; ii < n ; ++ii ) {
                indices.push_back(reslt[ii].index);
                dists.push_back( sqrt( reslt[ii].d2 ) );
        }
        
        delete [] reslt;

        return n;
}



