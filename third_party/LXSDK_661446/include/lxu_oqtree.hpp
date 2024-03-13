/*
 * lxu_oqtree.hpp	Hybrid octree/quadtree in the form of a <templated> container class and thus, just a header...
 *
 *	Copyright (c) 2008-2022 The Foundry Group LLC
 *	
 *	Permission is hereby granted, free of charge, to any person obtaining a
 *	copy of this software and associated documentation files (the "Software"),
 *	to deal in the Software without restriction, including without limitation
 *	the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *	and/or sell copies of the Software, and to permit persons to whom the
 *	Software is furnished to do so, subject to the following conditions:
 *	
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.   Except as contained
 *	in this notice, the name(s) of the above copyright holders shall not be
 *	used in advertising or otherwise to promote the sale, use or other dealings
 *	in this Software without prior written authorization.
 *	
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *	DEALINGS IN THE SOFTWARE.
 *
 *	Author: A. Cachelin 
 *	Revision: 1.0  5/14/2013
 */

// the element class contains the actual node data and the position in 2/3D space

#include <list>

template <class oqElmData>
class oqTreeElement {
    public:
        LXtVector				 pos;
        oqElmData				*data;
        unsigned int			 index;

        oqTreeElement(const LXtVector p, oqElmData *dat, unsigned idx) { data = dat; LXx_VCPY (pos, p); index = idx; };

        ~oqTreeElement() { if (data) delete data; }
};


// The node class contains either a list of elements (for leaf nodes) or a set of 
// subnodes representing the octants/quadrants composing the node
template <class oqElement, int ND>
class oqTreeNode {
    public:
        typedef typename std::vector<oqElement*>::iterator ElementIterator;

        oqTreeNode				*sub[8], *parent;
        std::vector<oqElement*>			 eltList; 
        double					 scale;
        unsigned				 pos[3];
        unsigned				 count;

        oqTreeNode (const LXtVector p, double s=1) {
                LXx_VCPY (pos, p); 
                scale = s; 
                count = 0; 
                parent = NULL;
                for (int i = 0; i < 8; i++) 
                        sub[i] = NULL;
        };
        ~oqTreeNode () {
                oqElement	*elm;
                for (int i = 0; i < 8; i++) {
                        if (sub[i]) {
                                delete sub[i];
                                sub[i] = NULL;
                        }
                }
                for (ElementIterator iter = eltList.begin(); iter !=eltList.end(); iter++) {
                        elm = *iter;
                        delete elm;
                }
                eltList.clear ();
        }

        bool FitNode (LXtVector apos) {
                double                   rel;
                for (int i = 0; i < ND; i++) {
                        rel = apos[i] - scale * pos[i];
                        if (rel < 0 || rel > scale)
                                return false;
                }
                return true;
        }

        int PosIndex (LXtVector apos) {
                double                   rel, s2;
                int                      i, idx;

                idx = 0;
                s2  = scale / 2;
                for (i = 0; i < ND; i++) {
                        rel = apos[i] - scale * pos[i];
                        if (rel > s2)
                                idx |= (1 << i);
                }
                return idx;
        }

        bool IsLeaf () {
                return !sub[0] && !sub[1] && !sub[2] && !sub[3]
                    && !sub[4] && !sub[5] && !sub[6] && !sub[7];
        }

        oqTreeNode* NewSubNode (int index) {
                double		 sc = scale / 2.0;
                LXtVector	 apos;

                LXx_VSCL3 (apos, pos, 2);

                for (int i = 0; i < ND; i++)
                        if (index & (1 << i))
                                apos[i]++;

                sub[index] = new oqTreeNode (apos, sc);
                sub[index]->parent = this;
                return sub[index];
        }

        // A new root node has to be added to expand the space. It expands by two, and
        // the old root becomes the 0|0|0 sub-node since its position is all zeros.

        oqTreeNode* NewSuperNode () {
                double		 sc = scale * 2.0;
                LXtVector	 apos;
                oqTreeNode 	*big;

                LXx_VCLR (apos);
                big = new oqTreeNode (apos, sc);
                big->sub[0] = this;
                parent = big;
                return big;
        }
// Recursively find childless node containing pos
        oqTreeNode* FindLeaf (LXtVector apos) {
                int idx = PosIndex (apos);
                if (!sub[idx]) {
                        if (IsLeaf ())
                                return this;

                        return NewSubNode (idx);
                }
                return sub[idx]->FindLeaf (apos);
        }

//	
        void SplitNode () {
                
                //assert (IsLeaf ());

                LXtVector               apos;
                int                      idx;
                ElementIterator		 it;
                oqElement		*elt;
                for (it = eltList.begin(); it != eltList.end(); it++) { // move elements to appropriate sub nodes
                        elt = it[0];
                        LXx_VUOP2 (apos, elt->pos, LXxABS);
                        idx = PosIndex (apos);
                        if (!sub[idx])
                                sub[idx] =  NewSubNode (idx);
                        sub[idx]->eltList.push_back (elt);
                }
                eltList.clear ();
        }
};


#define NEARCONT	list
template <class oqElmData, int ND>
class oqTree {
    public:
        typedef oqTreeNode<oqTreeElement<oqElmData>,ND>		oqNode;
        typedef oqTreeElement<oqElmData>			oqElement;
        class ONearCandidate {
           public:
                oqNode		        *node;
                double                   min, max;
                int                      octant;
                bool                     cullMe;

                //bool operator < (const ONearCandidate *c2) const {
                //	return (max < c2.max);
                //}

        };
        static bool maxComp (const ONearCandidate *c1, const ONearCandidate *c2) {
                return (c1->max < c2->max);
        }

        typedef typename std::NEARCONT<ONearCandidate*>::iterator NearIterator;
        
        bool CullCandidate (const ONearCandidate *can) {  // remove_if() predicate function
                if (can->cullMe) {
                        delete can;
                        return true; 
                }
                return false;
        };

        typedef struct st_Neighbor {
                LXtVector		 pos;
                oqElmData		*data;
                int			 index;
                double			 d2;
        } Neighbor;

        oqNode					*root[8];
        int					 rank;
        int					 dimension; // 2 or 3
        int					 count;
        float					 quantum; // min. initial scale in newNode

        oqTree (int r=1) { 
                rank = r;
                dimension = ND;
                quantum = 1e-3;// 1e-5;
                count = 0;
                for (int i = 0; i < 8; i++)
                        root[i] = NULL;
        }

        ~oqTree () {
                clear ();
        }

        void clear ()  {
                for (int i = 0; i < 8; i++) {
                        if (root[i]) {
                                delete root[i];
                                root[i] = NULL;
                        }
                }
                count = 0;
        }
        size_t size () {
                return count;
        }

        bool empty () {
                return count ? true : false;
        }

//This returns the squared minimum distance between the box and the point. If the
//point is in the box this returns zero.
        double BBoxDistanceToPoint (LXtBBox *box, LXtVector pos)
        {
                double			 d2;
                int			 i;

                d2 = 0.0;
                for (i = 0; i < ND; i++) {
                        if (pos[i] < box->min[i])
                                d2 += (pos[i] - box->min[i]) * (pos[i] - box->min[i]);

                        else if (pos[i] > box->max[i])
                                d2 += (pos[i] - box->max[i]) * (pos[i] - box->max[i]);
                }

                return d2;
        }

//The returns the squared maximum distance between this point and any part of the
//box interior.
        double BBoxDistanceFromPoint (LXtBBox *box, LXtVector pos)
        {
                double			 d2, a0, a1;
                int			 i;

                d2 = 0.0;
                for (i = 0; i < ND; i++) {
                        a0 = pos[i] - box->min[i];
                        a1 = pos[i] - box->max[i];
                        a0 = a0 * a0;
                        a1 = a1 * a1;
                        d2 += LXxMAX (a0, a1);
                }

                return d2;
        }

        int AxisMaxExtentF (const LXtVector v)
        {
                if (LXxABS(v[0]) > LXxABS(v[1]) && (ND<3 || LXxABS(v[0]) > LXxABS(v[2])))
                        return 0;
                else if (LXxABS(v[1]) >= LXxABS(v[0]) && (ND<3 || LXxABS(v[1]) > LXxABS(v[2])))
                        return 1;
                else
                        return 2;
        }

        bool NewRootNode (const LXtVector apos, int index) {
                double scale, max = apos [ AxisMaxExtentF (apos) ];
                max = LXxMAX (max, quantum);

                scale = 1.0;
                while (scale > max)
                        scale /= 2.0;

                while (scale < max)
                        scale *= 2.0;
                oqNode *node = new oqNode (apos, scale);
                root[index] = node;
                return true;
        }

        int AddPoint (const LXtVector pos, oqElmData *data) {
                int i, idx = 0;
                LXtVector apos;
                oqNode *node, *p;
                LXx_VCLR (apos); // clear out potential extra dimension in ND==2

                for (i = 0; i < ND; i++) {
                        if (pos[i] < 0.0) {
                                idx |= (1 << i);
                                apos[i] = -pos[i];
                        } else
                                apos[i] =  pos[i];
                }
                if (!root[idx]) {
                        NewRootNode (apos, idx);
                        node = root[idx];
                } else {
                        while (!root[idx]->FitNode (apos))
                                root[idx] = root[idx]->NewSuperNode ();

                        node = root[idx]->FindLeaf (apos);
                }
                oqElement *elt = new oqElement(pos, data, count);
                node->eltList.push_back (elt);
                count++;
                for (p = node; p; p = p->parent)
                        p->count++;

                if (node->pos[0] < 35000000 && node->pos[1] < 35000000 && (ND<3 || node->pos[2] < 35000000)
                    && node->scale > 5.0e-11 && node->count > rank)
                {
                        node->SplitNode ();
                }
                return count-1;
        }


        
        void NearList_Add (std::NEARCONT<ONearCandidate*> &nearList, oqNode *node, int octant, LXtVector pos, double maxD2) {
                ONearCandidate		*can;
                LXtBBox			 box;
                double			 min, a, b;
                int			 i, sign;

                LXx_VCLR (box.min);
                LXx_VCLR (box.max);
                LXx_VCLR (box.center);
                LXx_VCLR (box.extent);
                for (i = 0; i < ND; i++) {
                        sign = ( (octant & (1 << i)) ? -1 : +1);
                        a = node->scale * (node->pos[i] + 0) * sign;
                        b = node->scale * (node->pos[i] + 1) * sign;
                        box.min[i] = LXxMIN (a, b);
                        box.max[i] = LXxMAX (a, b);
                        box.center[i] = (box.max[i] + box.min[i])/2;
                        box.extent[i] = (box.max[i] - box.min[i]);
                }

                min = BBoxDistanceToPoint (&box, pos);
                if (maxD2 > 0 && min > maxD2)
                        return;

                can = new ONearCandidate;
                can->node   = node;
                can->cullMe   = false;
                can->octant = octant;
                can->min    = min;
                can->max    = BBoxDistanceFromPoint (&box, pos);

                nearList.push_back (can);
        };

        void NearTable_AddPoint ( Neighbor *result, int max, int *num, LXtVector pos, double maxD2, oqElement  *elt) {
                LXtVector                del;
                double                   d2;
                int                      k;

                LXx_VSUB3 (del, pos, elt->pos);
                d2 = LXx_VDOT (del, del);
                if (d2 > maxD2)
                        return;

                for (k = num[0] - 1; k >= 0; k--)
                {
                        if (d2 > result[k].d2)
                                break;

                        if (k + 1 < max)
                        {
                                LXx_VCPY (result[k + 1].pos, result[k].pos);
                                result[k + 1].data = result[k].data;
                                result[k + 1].d2   = result[k].d2;
                                result[k + 1].index   = result[k].index;

                                num[0] = LXxMAX (num[0], k + 2);
                        }
                }

                if (k + 1 < max)
                {
                        LXx_VCPY (result[k + 1].pos, elt->pos);
                        result[k + 1].data = elt->data;
                        result[k + 1].d2   = d2;
                        result[k + 1].index   = elt->index;

                        num[0] = LXxMAX (num[0], k + 2);
                }
        }


        // We find nearest neighbors using a breadth-first traversal. We maintain a list of
        // candidate nodes, each with a distance range, which is initialized to the root
        // boxes on each signed octant. The iterative process does three steps.

        // First we sort the nodes by their max distance. Walking from closest to farthest,
        // we accumulate the number of points in each node until we have at least as many
        // as we need. The second loop purges any candidates whose minimum distance is
        // greater than this new limit, since we know that we have all we need closer in.
        // The third step expands each box, replacing it with the up-to 8 sub-boxes. The
        // new min distance is use for quick culling of those candiates as well. When all
        // the boxes are leaves, we're done.

        //Finally the points in the leaf nodes are sorted into the client's result array.
        int NearestNeighbors (LXtVector pos, double maxDist, Neighbor *result, int max) {
                ONearCandidate          *can;
                //oqElement	        *elt;
                double                   maxD2, limit;
                int                      num = (1<<ND), i, k, done;
                std::NEARCONT<ONearCandidate*>	 nearList, subList;


                if (maxDist > 0.0)
                        maxD2 = maxDist * maxDist;
                else
                        maxD2 = -1.0;

                for (k = 0; k < (1<<ND); k++) // 4 or 8
                        if (root[k])
                                NearList_Add (nearList, root[k], k, pos, maxD2);

                done = (nearList.size () == 0);

                NearIterator iter;
                while (!done)
                {
                        //std::sort (nearList.begin (), nearList.end ());
                        //nearList.sort (); // sort nearest to farthest
                        nearList.sort (maxComp); // sort nearest to farthest

                        num = 0;
                        i = 0;
                        for (iter = nearList.begin(); iter !=nearList.end(); iter++, i++) {
                                can = *iter;
                                if (num) {
                                        num  += can->node->count;
                                        limit = LXxMAX (limit, can->max);
                                } else {
                                        num = can->node->count;
                                        limit = can->max;
                                }

                                if (num >= max)
                                        break;
                        }

                        if (maxD2 < 0.0 || limit < maxD2) {
                                maxD2 = limit;
                                iter = nearList.end();
                                do {
                                        iter--;
                                        can = *iter;
                                        if (can->min > limit) {
                                                delete can;
                                                iter = nearList.erase (iter);
                                        }
                                } while (iter != nearList.begin());
                                
                        }

                        done = 1;
                        // move any non-leaf nodes' contents that are near enough into sublist, mark those nodes to ignore/cull
                        for (iter = nearList.begin(); iter !=nearList.end(); iter++, i++) {
                                can = *iter;
                                if (can->node->IsLeaf ())
                                        continue;
                                if (can->cullMe)
                                        continue;

                                can->cullMe = true;
                                for (k = 0; k < 8; k++)
                                        if (can->node->sub[k])
                                                NearList_Add (subList, can->node->sub[k], can->octant, pos, maxD2);

                                done = 0;
                        }
                        
                        if (nearList.size () != 0)
                        {
                                iter = nearList.end();
                                do {
                                        iter--;
                                        can = *iter;
                                        if (can->cullMe) {
                                                delete can;
                                                iter = nearList.erase (iter);
                                        }
                                } while (iter != nearList.begin());
                        }

                        nearList.splice (nearList.end(), subList); // move subnodes into main list

                        // CullCandidate not only checks cullMe, it also calls the destructor on culled candidates
                        //nearList.erase (std::remove_if (nearList.begin(), nearList.end(), CullCandidate), nearList.end());
                }
                // only leaf nodes remaining
                //nearList.sort (); // sort nearest to farthest
                nearList.sort (maxComp); // sort nearest to farthest
                num = 0;
                for (iter = nearList.begin(); iter !=nearList.end(); iter++, i++) {
                        can = *iter;
                        typename oqNode::ElementIterator  elt;
                        for (elt = can->node->eltList.begin(); elt != can->node->eltList.end(); elt++, i++) {
                                NearTable_AddPoint (result, max, &num, pos, maxD2, elt[0]);
                        }

                }
                for (iter = nearList.begin(); iter !=nearList.end(); iter++, i++) {
                        can = *iter;
                        delete can;
                }
                nearList.clear ();
                return num;
        }

};

