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
 * General utilities that are used in the wrappers, not necessarily for
 * anything else.
 */
#ifndef LX_CWUTIL_HPP
#define LX_CWUTIL_HPP

#include <lxcom.h>


/*
 * ----------------------------------------------------------
 * LxResult codes are returned from most methods and can be converted to
 * a C++ friendly form using these wrappers.
 */
class CLxResult
{
        LxResult	m_rc;

    public:
        /*
         * Static function for testing an LxResult for success.
         */
        static inline bool ok (const LxResult &rc)
        {
                return LXx_OK( rc );
        }

        /*
         * Static function for testing an LxResult for true.
         */
        static inline bool isTrue (const LxResult &rc)
        {
                return (LXe_TRUE == rc);
        }

        /*
         * Static function for testing an LxResult for false.
         */
        static inline bool isFalse (const LxResult &rc)
        {
                return (LXe_FALSE == rc);
        }

        /*
         * Constructor takes optional result code.
         */
        CLxResult (const LxResult rc = LXe_OK)
        {
                set (rc);
        }

        /*
         * Constructor can also start with a test and failure code.
         */
        CLxResult (const bool test, const LxResult failRC)
        {
                set (test ? LXe_OK : failRC);
        }

        /*
         * Set the result code.
         */
        void set (const LxResult rc)
        {
                m_rc = rc;
        }

        /*
         * Returns true if there was no error
         */
        inline bool ok() const
        {
                return ok (m_rc);
        }

        /*
         * Returns true if there was an error
         */
        inline bool fail() const
        {
                return !ok (m_rc);
        }

        /*
         * Returns true if the result was true
         */
        inline bool isTrue() const
        {
                return isTrue (m_rc);
        }

        /*
         * Returns true if the result was false
         */
        inline bool isFalse() const
        {
                return isFalse (m_rc);
        }

        /*
         * Copy operator that takes a raw result code
         */
        inline CLxResult & 	operator= (const LxResult &rc)
        {
                set( rc );
                return *this;
        }

        /*
         * Copy operator that takes another CLxResult
         */
        inline CLxResult & 	operator= (const CLxResult &rhs)
        {
                set( rhs.m_rc );
                return *this;
        }

        /*
         * Compare operator that takes raw result code
         */
        inline bool operator== (const LxResult &rc) const
        {
                return (m_rc == rc);
        }

        /*
         * Compare operator that takes another CLxResult
         */
        inline bool operator== (const CLxResult &rhs) const
        {
                return (m_rc == rhs.m_rc);
        }

        /*
         * Not equal compare operator that takes raw result code
         */
        inline bool operator!= (const LxResult &rc) const
        {
                return (m_rc != rc);
        }

        /*
         * Not equal compare operator that takes another CLxResult
         */
        inline bool operator!= (const CLxResult &rhs) const
        {
                return (m_rc != rhs.m_rc);
        }

        /*
         * The raw result code
         */
        inline LxResult resultCode() const
        {
                return m_rc;
        }

        /*
         * Cast to a result code when required.
         */
        inline operator LxResult() const
        {
                return m_rc;
        }

        /*
         * Casting to boolean returns false for error, not for a FALSE result
         * code.
         */
        inline operator bool() const
        {
                return ok();
        }
};


/*
 * ----------------------------------------------------------
 * Allocation tracking is done by declaring trace contexts. These mark
 * the current scope with a name so that allocations made (or in nested
 * scopes) there can be traced back.
 *
 * This behavior is controlled by the compile-time TRACEALLOC define.
 * Normally this is defined when RELEASE is defined, but that can be
 * overridden by the NO_TRACE and YES_TRACE defines. The common lib must
 * be compiled with the same state for the define.
 *
 *   {
 *           CLxTrace _here ("Class::Method");
 *
 *           do_allocations ();
 *   }
 */
#define LX_NO_TRACE

#ifdef LX_NO_TRACE
  #undef  LX_TRACEALLOC

#elif LX_YES_TRACE
  #define LX_TRACEALLOC

#else
  #ifndef RELEASE
    #define LX_TRACEALLOC
  #else
    #undef  LX_TRACEALLOC
  #endif
#endif

class CLxTrace
{
    public:
    #ifdef LX_TRACEALLOC
         CLxTrace (const char *);
        ~CLxTrace ();
    #else
         CLxTrace (const char *)	{}
        ~CLxTrace ()			{}
    #endif
};


/*
 * ----------------------------------------------------------
 * C++ treats all classes as unique datatypes, so you can't just have a
 * pointer to an object of unknown type. In cases where that's necessary
 * classes can derive from CLxObject, which is just something guaranteed
 * to have a virtual destructor to allow 'delete'.
 *
 * Inheriting from the basic object class is also useful for tracing
 * allocation. Any allocated CLxObject is added to the trace.
 */
class CLxObject
{
    public:
    #ifdef LX_TRACEALLOC
                 CLxObject();
        virtual ~CLxObject();
    #else
        virtual ~CLxObject() {}
    #endif
};


/*
 * ----------------------------------------------------------
 * One such class that requires a virtual delete is this superclass that
 * allows sub-classes to be ref-counted. The constructor sets the ref-
 * count to 1. acquire() increases the ref-count, and release() decrements
 * the count. When the count hits zero the destrutor is called.
 *
 * When tracing is enabled, the trace_mode flag can be set to true and the
 * trace_Change() method will be called for ref count changes.
 */
class CLxRefCounted :
                public CLxObject
{
    public:
        int	ref_count;

                CLxRefCounted ();
        void	acquire ();
        void	release ();

    #ifdef LX_TRACEALLOC
        bool			 trace_mode;
        virtual void		 trace_Change (int) {}
    #endif
};


/*
 * ----------------------------------------------------------
 * This template class serves as a caddy to hold a CLxRefCounted subclass.
 * set() / drop() and destructor manage the ref counts, and the meaty
 * object inside can be accessed by casting or dereferencing.
 */
template <class T>
class CLxHolder
{
    public:
        T			*ref;

        CLxHolder ()
        {
                ref = 0;
        }

        ~CLxHolder ()
        {
                drop ();
        }

                void
        drop ()
        {
                if (ref)
                {
                        ref->release ();
                        ref = 0;
                }
        }

                void
        alloc ()
        {
                CLxTrace here ("CLxHolder::alloc");
                drop ();
                ref = new T;
        }

                void
        set (
                T		*replace)
        {
                drop ();
                ref = replace;
                if (ref)
                        ref->acquire ();
        }

        operator       T *  ()		{	return  ref;	}
        operator const T *  ()		{	return  ref;	}

              T& operator*  ()		{	return *ref;	}
        const T& operator*  () const	{	return *ref;	}

              T* operator-> ()		{	return  ref;	}
        const T* operator-> () const	{	return  ref;	}
};


/*
 * ----------------------------------------------------------
 * This template class serves as a holder for one of anything. This is
 * useful when you need a singleton of something that's shared by multiple
 * clients. In this case the ref-counting is done locally.
 */
template <class T>
class CLxSingleHolder
{
    public:
        T			*ref;
        unsigned		 count;

        CLxSingleHolder ()
        {
                ref   = 0;
                count = 0;
        }

        ~CLxSingleHolder ()
        {
                while (count)
                        release ();
        }

                void
        acquire ()
        {
                CLxTrace here ("CLxSingleHolder::acquire");
                if (!count)
                        ref = new T;

                count++;
        }

                void
        release ()
        {
                if (0 != count)
                {
                        if (!--count)
                        {
                                delete ref;
                                ref = 0;
                        }
                }
        }

        operator       T *  ()		{	return  ref;	}
        operator const T *  ()		{	return  ref;	}

              T& operator*  ()		{	return *ref;	}
        const T& operator*  () const	{	return *ref;	}

              T* operator-> ()		{	return  ref;	}
        const T* operator-> () const	{	return  ref;	}
};


/*
 * ----------------------------------------------------------
 * List template.  Doubly-liked lists, but using "next" and "prev"
 * pointers directly in the client's data object.
 */
template <class T>
class CLxList
{
    public:
        T			*first;
        T			*last;

        CLxList ()
        {
                first = 0;
                last  = 0;
        }

                void
        AddHead (
                T			*elt)
        {
                if (first)
                        first->prev = elt;
                else
                        last = elt;

                elt->next = first;
                elt->prev = 0;
                first = elt;
        }

                void
        AddTail (
                T			*elt)
        {
                if (last)
                        last->next = elt;
                else
                        first = elt;

                elt->prev = last;
                elt->next = 0;
                last = elt;
        }

                void
        Remove (
                T			*elt)
        {
                if (elt->prev)
                        elt->prev->next = elt->next;
                else
                        first = elt->next;

                if (elt->next)
                        elt->next->prev = elt->prev;
                else
                        last = elt->prev;
        }
};


/*
 * Add methods for create and destroy of elements when that's possible. Objects
 * in the list are owned by the list and are freed on destruction.
 *
 * NOTE: mac build seems to need the superfluous "this->"
 */
template <class T>
class CLxObjectList :
                public CLxList<T>
{
    public:
        ~CLxObjectList ()
        {
                Clear ();
        }

                T *
        AllocTail ()
        {
                T			*elt;

                CLxTrace here ("CLxObjectList::Alloc");
                elt = new T;
                this->AddTail (elt);
                return elt;
        }

                void
        Delete (
                T			*elt)
        {
                this->Remove (elt);
                delete elt;
        }

                void
        Clear ()
        {
                while (this->first)
                        this->Delete (this->first);
        }
};


/*
 * Array of elements. This is like an STL 'vector' but much simpler.
 */
template <class T>
class CLxArray
{
    public:
        T		*array;
        int		 size;

        CLxArray ()
        {
                array = 0;
                size  = 0;
        }

        CLxArray (int n)
        {
                array = 0;
                size  = 0;

                Alloc (n);
        }

        ~CLxArray ()
        {
                Free ();
        }

                void
        Alloc (const int n)
        {
                Free ();
                CLxTrace here ("CLxArray::alloc");
                array = new T [n];
                size  = n;
        }

                void
        Alloc (const int n, const T &val)
        {
                Alloc (n);
                SetAll (val);
        }

                void
        Free ()
        {
                if (!array)
                        return;

                delete [] array;
                array = 0;
                size  = 0;
        }

                void
        SetAll (const T &val)
        {
                if (!array)
                        return;

                for (int i = 0; i < size; i++)
                        array[i] = val;
        }

                T &
        operator[] (const int index) const
        {
                if (index < 0 || index >= size)
                        throw (LXe_OUTOFBOUNDS);

                return array[index];
        }
};


/*
 * ----------------------------------------------------------
 * Arm objects. These can be declared in a scope and will be destroyed on leaving
 * the scope, performing their arm action. Typically these are disarmed before the
 * natural end of the scope, so that the arm action is only fired on an unexpected
 * end of scope -- like an exception.
 */
class CLxArm
{
    public:
        bool		 armed;

        CLxArm ()
        {
                arm ();
        }

                void
        arm ()
        {
                armed = true;
        }

                void
        disarm ()
        {
                armed = false;
        }
};

/*
 * Perform an assignment of a value to a variable holding the value. Unless disarmed
 * the value will be set back at the end of the scope.
 */
template <class T>
class CLxArmAssignment :
                public CLxArm
{
    public:
        T		*m_ptr;
        T		 m_val;

        CLxArmAssignment (T *ptr, T value)
        {
                m_ptr = ptr;
                m_val = m_ptr[0];
                m_ptr[0] = value;
        }

        ~CLxArmAssignment ()
        {
                if (armed)
                        m_ptr[0] = m_val;
        }
};

/*
 * Allocate an object of a given type, or hold on to an allocated object. Unless
 * disarmed the object will be freed at the end of scope.
 */
template <class T>
class CLxArmAllocation :
                public CLxArm
{
    public:
        T		*m_object;
        bool		 is_array;

        CLxArmAllocation (T *init = 0)
        {
                CLxTrace here ("CLxArmAllocation");
                is_array = false;
                if (init)
                        m_object = init;
                else
                        m_object = new T;
        }

        CLxArmAllocation (int n)
        {
                CLxTrace here ("CLxArmAllocation");
                is_array = true;
                m_object = new T [n];
        }

        ~CLxArmAllocation ()
        {
                if (armed && is_array)
                        delete [] m_object;
                else if (armed)
                        delete m_object;
        }
};

/*
 * Hold on to a reference to an ILxUnknownID interface pointer. If 'take' is
 * true (the default) the reference is stolen and will be released unless
 * disarmed.
 */
class CLxArmUnknownRef :
                public CLxArm
{
    public:
        ILxUnknownID	 unk_ifc;

        CLxArmUnknownRef (ILxUnknownID unk, bool take = true)
        {
                unk_ifc = unk;
                if (!take)
                        unk_ifc[0]->AddRef (unk_ifc);
        }

        ~CLxArmUnknownRef ()
        {
                if (armed)
                        unk_ifc[0]->Release (unk_ifc);
        }
};


/*
 * ----------------------------------------------------------
 * "lx" namespace for utility functions.
 */
                namespace lx
                {

/*
 * Functions for the basic IUnknown methods -- QueryInterface, AddRef and
 * Release -- in three flavors.  The "Ifc" functions take any interface, the
 * "Obj" functions take an LXtObjectID, and the "Unk" functions take an
 * ILxUknownID.  Some are templates, some not as needed.
 */
        template <class T, class U>
        bool
IfcQuery (
        T			 iface,
        const LXtGUID		*iid,
        U			*other)
{
        LxResult		 res;
        void			*pv;

        res = (iface[0]->iunk.QueryInterface) (iface, iid, &pv);
        if (LXx_OK (res)) {
                other[0] = reinterpret_cast<U> (pv);
                return true;
        } else
                return false;
};

        template <class U>
        bool
ObjQuery (
        LXtObjectID		 obj,
        const LXtGUID		*iid,
        U			*other)
{
        ILxUnknownID		 iunk;
        LxResult		 res;
        void			*pv;

        iunk = reinterpret_cast<ILxUnknownID> (obj);
        res = (iunk[0]->QueryInterface) (iunk, iid, &pv);
        if (LXx_OK (res)) {
                other[0] = reinterpret_cast<U> (pv);
                return true;
        } else
                return false;
};

        template <class U>
        bool
UnkQuery (
        ILxUnknownID		 iunk,
        const LXtGUID		*iid,
        U			*other)
{
        LxResult		 res;
        void			*pv;

        res = (iunk[0]->QueryInterface) (iunk, iid, &pv);
        if (LXx_OK (res)) {
                other[0] = reinterpret_cast<U> (pv);
                return true;
        } else
                return false;
};

        template <class T>
        T
IfcAddRef (
        T			 iface)
{
        (iface[0]->iunk.AddRef) (iface);
        return iface;
};

extern LXtObjectID	 ObjAddRef  (LXtObjectID);
extern ILxUnknownID	 UnkAddRef  (ILxUnknownID);

        template <class T>
        unsigned int
IfcRelease (
        T			 iface)
{
        return (iface[0]->iunk.Release) (iface);
};

extern void		 ObjRelease (LXtObjectID);
extern void		 UnkRelease (ILxUnknownID);

/*
 * Test any two COM interfaces to see if they are the same object.
 */
extern bool		 UnkIsSameObject (const ILxUnknownID, const ILxUnknownID);


/*
 * Methods to throw LxResult codes as exceptions. ThrowErr() ignores any that
 * aren't error codes, and ThrowOpt() ignores any non-errors including NOTIMPL.
 */
extern void		 ThrowErr (LxResult);
extern void		 ThrowOpt (LxResult);


/*
 * Where are we in the plugin or app lifecycle? BEFORE initialize, DURING normal
 * operation, or AFTER cleanup.
 */
#define LXiLIFECYCLE_BEFORE	 0
#define LXiLIFECYCLE_DURING	 1
#define LXiLIFECYCLE_AFTER	 2

extern unsigned		 Lifecycle (void);

/*
 * Sometimes servers are spawned just to read their tags and then are immediately
 * destroyed. In that case we want to do as little setup as possible.
 */
extern bool		 IsTempSpawn (void);

/*
 * Dump currently allocated CLxObjects either to stdout or the log.
 */
extern void		 TraceObjects (bool full = false, bool toLog = false);


/*
 * There are often times where a variable is only used in debug, like for testing a function that
 * should typically return success. For the non-debug cases, this macro can be used to let the
 * compiler know you are specifically ignoring the value.
 *
 * Note: in C, defining LXxUNUSED(x) as ((void)(x)) is sufficient, but in C++, that doesn't
 * prevent the warning 'variable "x" was set but never used' (at least for Intel Compiler)
 */
#define LXxUNUSED(x)		(&reinterpret_cast<const int&>(x))

/*
 * Functions to lookup GUIDs and get globals. These are needed as basis
 * functions for much of anything else, and the implementation depends on
 * whether we are a plug-in or a client application.
 */
extern const LXtGUID *	 LookupGUID (const char *);
extern LXtObjectID	 GetGlobal  (const char *);
extern LXtObjectID	 GetGlobal  (const LXtGUID *);


/*
 * Simple GUID functions to set and compare.
 */
extern int	GUIDCompare (const LXtGUID *g1, const LXtGUID *g2);
extern void	GUIDSet (LXtGUID *, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int);

                };	// END lx namespace


/*
 * ----------------------------------------------------------
 * "lx_err" namespace for result check functions.
 *
 * Some very common check functions that just throw LxResult errors if something
 * fails. It's useful to have these be short names, so it's a different namespace
 * to allow "using" without getting everything else from "lx".
 */
#ifdef check
   #undef check
#endif

                namespace lx_err
                {

extern void	check (LxResult rc);			// throw rc if fail code
extern void	check (CLxResult rc);			// throw rc if fail code
extern void	check (bool, LxResult rc = LXe_FAILED);	// throw rc if false
extern void	check (int,  LxResult rc = LXe_FAILED);	// throw rc if negative

                };	// END lx_err namespace


#endif

