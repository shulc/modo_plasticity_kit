/*
 * Plug-in SDK Header: C++ User Classes
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
 */
#ifndef LXUSER_thread_HPP
#define LXUSER_thread_HPP

#include <lxw_thread.hpp>

#include <lx_util.hpp>



class CLxUser_WorkList : public CLxLoc_WorkList
{
        public:
        CLxUser_WorkList () {}
        CLxUser_WorkList (ILxUnknownID obj) : CLxLoc_WorkList (obj) {}

        bool
        Split (
                CLxLoc_WorkList		&wlist,
                unsigned		 mode = LXiWLSPLIT_NONE)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CLxLoc_WorkList::Split (mode, &obj)))
                        return false;
        
                return wlist.take (obj);
        }

};

class CLxUser_ThreadMutex : public CLxLoc_ThreadMutex
{
        public:
        CLxUser_ThreadMutex () {}
        CLxUser_ThreadMutex (ILxUnknownID obj) : CLxLoc_ThreadMutex (obj) {}



};

class CLxUser_ThreadGroup : public CLxLoc_ThreadGroup
{
        public:
        CLxUser_ThreadGroup () {}
        CLxUser_ThreadGroup (ILxUnknownID obj) : CLxLoc_ThreadGroup (obj) {}



};

class CLxUser_ThreadSlot : public CLxLoc_ThreadSlot
{
        public:
        CLxUser_ThreadSlot () {}
        CLxUser_ThreadSlot (ILxUnknownID obj) : CLxLoc_ThreadSlot (obj) {}



};

class CLxUser_ThreadService : public CLxLoc_ThreadService
{
        public:
        bool
        NewMutex (
                CLxLoc_ThreadMutex	&mux)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateMutex (&obj)))
                        return false;
        
                return mux.take (obj);
        }
        bool
        NewCritSec (
                CLxLoc_ThreadMutex	&cs)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateCS (&obj)))
                        return false;
        
                return cs.take (obj);
        }
        bool
        NewGroup (
                CLxLoc_ThreadGroup	&tg)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateGroup (&obj)))
                        return false;
        
                return tg.take (obj);
        }
        bool
        NewSlot (
                CLxLoc_ThreadSlot	&ts,
                size_t			 size)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateSlot (size, 0, &obj)))
                        return false;
        
                return ts.take (obj);
        }
        
                bool
        NewSlot (
                CLxLoc_ThreadSlot	&ts,
                ILxUnknownID		 client)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateSlot (0, client, &obj)))
                        return false;
        
                return ts.take (obj);
        }
        

};
/*
 * We also provide a couple of simple classes for self-allocating locks and
 * automatically scoped enter and leave.
 */
class CLxMutexLock : public CLxUser_ThreadMutex
{
    public:
        CLxMutexLock ()
        {
                CLxUser_ThreadService ts;
                ts.NewMutex (*this);
        }
};

class CLxCritSecLock : public CLxUser_ThreadMutex
{
    public:
        CLxCritSecLock ()
        {
                CLxUser_ThreadService ts;
                ts.NewCritSec (*this);
        }
};

class CLxArmLockedMutex : public CLxArm
{
    public:
        CLxUser_ThreadMutex	&lock;

        CLxArmLockedMutex (CLxUser_ThreadMutex &mux) : lock (mux)
        {
                lock.Enter ();
        }

        ~CLxArmLockedMutex ()
        {
                if (armed)
                        lock.Leave ();
        }
};
#endif
