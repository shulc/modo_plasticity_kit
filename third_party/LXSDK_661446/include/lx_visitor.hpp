/*
 * Plug-in SDK Header: C++ Wrapper Classes
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
 * Specialized "visitor" wrappers.
 */
#ifndef LXCW_VISITOR_HPP
#define LXCW_VISITOR_HPP

#include <lxw_value.hpp>


/*
 * -- CLxVisitor
 *
 * This class can be used to implement visitor objects using derived classes.
 * The client can override either the evaluate() method, or the eval_RC() method
 * in the more rare case that a return code is needed. The actual visitor object
 * is accessed by casting.
 *
 * class CMyVisitor : public CLxVisitor
 * {
 *     int count;
 *     CMyVisitor () { count = 0; }
 *     void evaluate () { count++; }
 * };
 *
 *     CMyVisitor counter_vis;
 *     dest_obj.Enumerate (counter_vis);
 *     dest_total = counter_vis.count;
 */
class CLxVisitor :
                public CLxObject
{
    public:
        /*
         * Implement to evaluate each visted element without the need for
         * a result code.
         */
        virtual void		 evaluate () {}

        /*
         * Implement to evaluate each visted element and return a result code.
         */
        virtual LxResult	 eval_RC  () { evaluate (); return LXe_OK; }

        /*
         * Override this to return true in order for this object to be destroyed
         * when the interface is freed. Generally only needed for visitors that
         * are allocated and need to be freed automatically.
         */
        virtual bool		 self_destruct () { return false; }

        /*
         * Cast to get the COM object to pass to enumeration methods.
         */
        operator ILxUnknownID	 () { return init_cache (); }

    //internal:
        CLxLoc_Visitor		 self_cache;
        ILxUnknownID		 init_cache ();
};

//@skip

/*
 * User class to fill in a hole in generated classes.
 */
class CLxUser_Visitor : public CLxLoc_Visitor
{
    public:
        CLxUser_Visitor () {}
        CLxUser_Visitor (ILxUnknownID obj) : CLxLoc_Visitor (obj) {}
};

/*
 * CLxImpl_AbstractVisitor: abstract class for implementing simple visitors
 */
class CLxImpl_AbstractVisitor :
                public CLxObject
{
    public:
        virtual LxResult	 Evaluate (void) = 0;
};

/*
 * As we swirl round and round trying to find a way to interact with
 * generic clients in a strictly typed langauge we find crazy things
 * like this.  It's basically a visitor-like object that can call an
 * abstract visitor stored as local data.
 */
class CLxGenericVisitor :
                public CLxObject
{
    public:
        virtual LxResult	 Evaluate (void)
        {
                return vis->Evaluate ();
        }
        CLxImpl_AbstractVisitor	*vis;
};


/*
 * CLxInst_OneVisitor is a template that makes an object that contains a COM
 * object which can be passed as a visitor.
 *
 *  {
 *	CLxInst_OneVisitor<CMyVisitor>	myVis;
 *
 *	myVis.loc.data = data;
 *	polygon[0]->Enumerate (LXiMARK_ANY, myVis, 0);
 *  }
 */
template <class T>
class CLxInst_OneVisitor :
                public CLxGenericPolymorph,
                public CLxImpl_Visitor
{
    public:
        LXtObjectID		 m_visitor;
        T			 loc;
        CLxIfc_Visitor<CLxInst_OneVisitor>
                                 m_ifc;

                LxResult
        vis_Evaluate ()
                                 LXx_OVERRIDE
        {
                return loc.Evaluate ();
        }

                operator
        ILxUnknownID ()
        {
                return reinterpret_cast <ILxUnknownID> (m_visitor);
        }

                void *
        NewObj ()
                                 LXx_OVERRIDE
        {
                return this;
        }

                void
        FreeObj (
                void		*self)
                                 LXx_OVERRIDE
        {
        }

        CLxInst_OneVisitor ()
        {
                AddInterface (&m_ifc);
                m_visitor = Spawn (0);
        }

        ~CLxInst_OneVisitor ()
        {
                lx::ObjRelease (m_visitor);
        }
}; // END CLxInst_OneVisitor



#endif

