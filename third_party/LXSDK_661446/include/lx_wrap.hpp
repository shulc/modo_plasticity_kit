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
 * The wrapper classes defined here provide three services.
 *
 *  (1) C++ objects can be wrapped with COM interfaces to be exported to nexus.
 *
 *  (2) COM objects from nexus can be localized with C++ object wrappers.
 *
 *  (3) The entire dynamic library can be exposed to nexus as a module, and
 * nexus can instantiate the servers defined here. This also provides access
 * to nexus internal state and service globals.
 */
#ifndef LX_CWRAP_HPP
#define LX_CWRAP_HPP

#include <lx_util.hpp>
#include <lxthread.h>
#include <exception>

#include <set>

/*
 * Disable the multiple assignment operators warning in Visual C++.
 * (CLxLocalize has const and non-const versions of the assignment operator.)
 */
#ifdef _MSC_VER
        #pragma warning(disable: 4522)
#endif


namespace lx {
    static const LXtGUID guid_Unknown = {0x00000000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC4};
};


/*
 * ----------------------------------------------------------
 * -- Localized COM Objects:
 *
 * COM objects from nexus come in as ILxUnknownID pointers. These can be
 * localized to a specific interface which is a sub-class of this abstract
 * class.
 */
//@util CLxLocalizedObject

class CLxLocalizedObject :
                public CLxObject
{
    public:
        /*
         * Set the localization wrapper to use the object. The wrapper takes
         * ownership by incrementing the ref count on the object.
         */
        virtual bool		 set   (LXtObjectID obj)	= 0;

        /*
         * Set the localization wrapper to use the object. The wrapper takes
         * ownership without incrementing the ref count, effectively stealing
         * the reference from the caller.
         */
        virtual bool		 take  (LXtObjectID obj)	= 0;

        /*
         * Sets the wrapper to use the same object as another.
         */
        virtual bool		 copy  (CLxLocalizedObject& loc)= 0;

        /*
         * Returns true if this wrapper has a valid interface.
         */
        virtual bool		 test  () const			= 0;

        /*
         * Releases the interface for the current object, makng the wrapper
         * unset.
         */
        virtual void		 clear ()			= 0;

        /*
         * Sets a ppvObj pointer for exporting wrapped objects. The exported
         * will have its reference count increased.
         */
        virtual LxResult	 get   (void **ppvObj) const	= 0;

        /*
         * Casts the wrapper back to a raw COM interface, as when passing
         * arguments to SDK methods.
         */
        virtual operator  ILxUnknownID () const			= 0;

    //internal:
        virtual const LXtGUID *	 guid  () const			= 0;
};


/*
 * Services are automatically set to point to the global service for the
 * current module, so they cannot be changed or cleared.
 */
class CLxLocalizedService
{
    public:
        /*
         * Calling this assures that the service is available. It may not be
         * if the constructor was called before the global modules were valid.
         */
        void			 set (void) {}
};


/*
 * This template is part of a localization for a specific interface.  The actual
 * methods of the interface are implemented as part of the CLxLoc_??? class,
 * which is also where all the constructors are defined.
 */
template <class T>
class CLxLocalize : public CLxLocalizedObject
{
    public:
        T			 m_loc;

        /*
         * Set this wrapper to use the same interface as another.
         */
        CLxLocalize& operator=(CLxLocalize& right)
        {
                set (right);
                return *this;
        }

        /*
         * Set this wrapper to use the same interface as another.
         */
        CLxLocalize& operator=(const CLxLocalize& right)
        {
                set (const_cast<CLxLocalize&>(right));
                return *this;
        }

        /*
         * Test if this wrapper is using the same object as another.
         */
        bool operator== (const ILxUnknownID rhs) const
        {
                return lx::UnkIsSameObject (*this, rhs);
        }

        /*
         * Test if this wrapper is not using the same object as another.
         */
        bool operator!= (const ILxUnknownID rhs) const
        {
                return !lx::UnkIsSameObject (*this, rhs);
        }

    //internal:
        ~CLxLocalize ()
        {
                clear ();
        }

        bool set (LXtObjectID obj)
                                 LXx_OVERRIDE
        {
                T		 loc;

                if (obj && lx::ObjQuery (obj, guid (), &loc)) {
                        clear ();
                        m_loc = loc;
                        return true;
                }

                clear ();
                return false;
        }

        bool take (LXtObjectID obj)
                                 LXx_OVERRIDE
        {
                if (!obj) {
                        clear ();
                        return false;
                }

                set (obj);
                lx::ObjRelease (obj);
                return test ();
        }

        bool copy (CLxLocalizedObject& loc)
                                 LXx_OVERRIDE
        {
                ILxUnknownID		 unk = loc;

                return set (reinterpret_cast<LXtObjectID>(unk));
        }

        void clear()
                                 LXx_OVERRIDE
        {
                if (m_loc) {
                        lx::IfcRelease (m_loc);
                        m_loc = 0;
                }
        }

        bool test() const
                                 LXx_OVERRIDE
        {
                return (m_loc != 0);
        }

        LxResult get (void **ppvObj) const
                                 LXx_OVERRIDE
        {
                if (!test ())
                        return LXe_NOTFOUND;

                lx::IfcAddRef (m_loc);
                ppvObj[0] = m_loc;
                return LXe_OK;
        }

        operator ILxUnknownID() const
                                 LXx_OVERRIDE
        {
                return reinterpret_cast<ILxUnknownID>(m_loc);
        }
};


/*
 * Catch LxResult or allocation exceptions and return the RC code. Returns
 * OK if the 'try' succeeded.
 */
#define LXx_CATCH_RET	catch (std::bad_alloc &) { return LXe_OUTOFMEMORY; }	\
                        catch (LxResult rc)      { return rc; }			\
                        return LXe_OK

/*
 * Macros for making localized versions of functions that read strings into
 * a buffer and length. Between 1 & 2 the rc code is set to the attempt to
 * get the string.
 */
   #if 1

#define LXWx_SBUF1								\
        try { unsigned len=512; char *buf=0; LxResult rc;			\
          while (!buf) { buf=new char[len];

#define LXWx_SBUF2								\
            if (rc==LXe_SHORTBUFFER) { delete[] buf; buf=0; len*=2; }		\
            else if (LXx_FAIL(rc)) { result.clear(); delete[] buf; return rc; }	\
          } result = buf; delete[] buf;						\
        } LXx_CATCH_RET;

   #else
   /* 
    * NOTE: When using the std::string::reserve() method it doesn't update the Size member of std::string.
    *       The Size member is used to determine the string length, i.e. both size() and length() will return 0
    *       event the internal pointer actually contains the string data. That's on Microsoft STL implementation.
    *       In the string operator+ implementation if size() is 0 the string wont be appended.
    * 
    *       Using resize() instead of reserve() wont help either. In that case the size != strlen(), the result
    *       will be the same number as used when reserve() is called.
    * 
    *       I've reverted the code to use the new/delete. Fixes #52819
    */ 

#define LXWx_SBUF1								\
        try { LxResult rc; result.reserve(512);					\
          do { unsigned len = result.capacity(); char *buf = &result[0];

#define LXWx_SBUF2								\
            if (rc == LXe_SHORTBUFFER) result.reserve(result.capacity() * 2);	\
            else if (LXx_FAIL(rc)) return rc;					\
          } while (rc == LXe_SHORTBUFFER);					\
        } LXx_CATCH_RET;

   #endif


/*
 * ----------------------------------------------------------
 * -- Exported COM Objects:
 *
 * We create our own COM objects that conform to the binary standard
 * regardless of compiler.  Our COM objects are proxies that are implemented
 * by a C++ object, and the interfaces are hooked to the objects using
 * simple glue stubs implemented as template classes.
 *
 * We can trace add-ref and release of COM interfaces by defining this
 * symbol. Individual objects can then have tracing enabled. Since this
 * affects common classes everything has to be rebuilt when enabling this.
 */
//#define LX_COM_TRACE

 #ifdef LX_COM_TRACE
/*
 * The trace class permits clients to be informed of ref count changes.
 */
//@util CLxCOMTrace
class CLxCOMTrace
{
    public:
        static const int	 START   =  0;
        static const int	 ADDREF  =  1;
        static const int	 RELEASE = -1;

        virtual void		 event (int type, int newCount) = 0;
};
 #endif

/*
 * An interface wrapper is an abstract class that defines a VTable for an
 * interface plus it's GUID.  Typically the vTable contains stubs that
 * decode the COM proxy object and pass control to the underlying class.
 */
class CLxInterface
{
    public:
        CLxInterface		*next, *prev;
        ILxUnknown		*vTable;
        const LXtGUID		*iid;
        int			 index;
};


typedef struct st_LXtCOMProxy *		LXtCOMProxyID;
typedef struct st_LXtCOMInstance *	LXtCOMInstanceID;
class CLxGenericPolymorph;

/*
 * A Proxy is a real COM object with a vTable at the start. The proxy
 * points back to the instance to keep counts rights, and it also has the
 * object cached locally for quicker access. Note that there does not
 * seem to be a way to do this with type-safety, so we rely on a void
 * pointer to the actual client object.
 */
typedef struct st_LXtCOMProxy {
        ILxUnknown		*vTable;
        LXtCOMInstanceID	 instance;
        void			*object;
        int			 refCount;
} LXtCOMProxy;

/*
 * An instance is a struct holding the actual object and a list of its
 * proxies. Again the actual client object is a void pointer and it will
 * be null for a zombie instance whose polymorph has been destroyed. 
 */
typedef struct st_LXtCOMInstance {
        CLxGenericPolymorph	*polymorph;
        LXtCOMInstanceID	 next, prev;
        CLxArray<LXtCOMProxy>	 proxys;
        void			*object;
        ILxUnknownID		 master;
        int			 refCount;
        std::set<ILxUnknownID>	 observers;
        ILxUnknownID		 observerVisitor;
        
    #ifdef LX_COM_TRACE
        CLxCOMTrace		*trace;
    #endif
} LXtCOMInstance;


/*
 * Macros to extract the real data type from a proxy.
 *
 *	LXCWxOBJ(p,X)	given a proxy 'p', this macro performs a cast, a deref,
 *			another cast, and returns the referenced object as a
 *			pointer to type X
 *
 *	LXCWxWCOM(X)	same again, but the proxy is always called 'wcom'
 *
 *	LXCWxINST(Y,v)	given the 'wcom' COM proxy, this macro first gets the
 *			object pointer as type 'T', then performs a static
 *			cast to a Y pointer and sets v to that value
 */
#define LXCWxOBJ(p,X)	reinterpret_cast<X*>((reinterpret_cast<LXtCOMProxy*>(p))->object)
#define LXCWxWCOM(X)	LXCWxOBJ(wcom,X)
#define LXCWxINST(Y,v)	Y *v = static_cast<Y*> (LXCWxWCOM(T))


/*
 * A polymorph is the COM front-end for some internal object type. It
 * effectively acts as a factory for COM objects based on client objects.
 * It's also has methods for dealing with those COM objects, and for
 * handling interfaces.
 */
//@util CLxGenericPolymorph

class CLxGenericPolymorph
{
    private:
        CLxList<LXtCOMInstance>	 obj_list;
        CLxList<CLxInterface>	 ifc_list;
        int			 ifc_count;
        const char		*id;

        CLxInterface *		 FindIID (const LXtGUID *iid);
        LXtCOMProxyID		 NewProxy (LXtCOMInstance *, CLxInterface *);

        static LxResult		 QueryInterface (LXtObjectID, const LXtGUID *, void **);
        static unsigned		 AddRef (LXtObjectID);
        static unsigned		 Release (LXtObjectID);

    public:
        /*
         * Test if the given interface is supported by objects of this type.
         */
        virtual bool		 TestInterface (const LXtGUID *);

        /*
         * Call during initialization to add interfaces to the object type.
         */
        void			 AddInterface (CLxInterface *);

        /*
         * Get the default interface for the object type, which is the first
         * interface added.
         */
        const LXtGUID *		 DefaultInterface ();

        /*
         * Create a new instance of a COM object of this type.
         */
        ILxUnknownID		 Spawn (const LXtGUID *iid = 0);

    #ifdef LX_COM_TRACE
        static void		 SetTrace (ILxUnknownID, CLxCOMTrace *);
    #endif

        /*
         * Set the identifier for this GenericPolymorph. This is automatically
         * done when this object is added as a spawner or a server. Attempts to
         * change this twice will have no effect.
         */
        bool			 SetIdentifier (const char *identifier);

        /*
         * Returns the identifier for this GenericPolymorph, if it is set.
         */
        const char		*Identifier ();
        
        /*
         * Returns the number of interfaces exposed on the polymorph.
         */
        unsigned int		 InterfaceCount ();
        
        /*
         * Returns and interface GUID specified by index. Note: Interfaces are
         * stored in a linked list, so the list must be traversed to find the
         * index we need - thankfully the list is usually quite small.
         */
        const LXtGUID		*InterfaceByIndex (unsigned int);

        /*
         * The client
         * has to provide the NewObj() and FreeObj() methods to allocate and free
         * their actual object.  AddInterface() is used to add new interface
         * wrappers that act on the object.  Once fully defined, Spawn() is used
         * to create new instances wrapped as COM objects.
         */
    //internal:
                                 CLxGenericPolymorph () : ifc_count (0), id (NULL) {}
        virtual			~CLxGenericPolymorph ();
        virtual ILxUnknownID	 IsA (ILxUnknownID, const LXtGUID *iid) { return 0; }
        virtual void *		 NewObj  ()       = 0;
        virtual void		 FreeObj (void *obj) = 0;
        virtual void *		 RefObj  (void *obj) { return 0; }
        virtual void		 InitObj (void *obj, void *) {}
        virtual void		 RawCOM  (void *, ILxUnknownID) {}
};


/*
 * The basic polymorph template call can create the NewObj() and FreeObj()
 * for any C++ datatype. It also has a method for "casting" a wrapped COM
 * object of this type back to the base type, and for allocating a new
 * instance and returning the internal object.
 */
template <class T>
class CLxPolymorph : public CLxGenericPolymorph
{
    public:
        /*
         * Given a COM ILxUnknownID pointer, this function returns the client's
         * object from inside the wrapper.
         */
                T *
        Cast (
                ILxUnknownID		 wcom)
        {
                return LXCWxOBJ (wcom, T);
        }

        /*
         * Allocate a new COM instance as void **ppvObj.
         */
                T *
        Alloc (
                void		       **ppvObj)
        {
                ILxUnknownID		 obj;

                obj = Spawn ();
                if (!obj)
                        throw (LXe_FAILED);

                ppvObj[0] = obj;
                return Cast (obj);
        }

        /*
         * Allocate a new COM instance as an ILxUnknownID.
         */
                T *
        Alloc (
                ILxUnknownID		&obj)
        {
                return Alloc ((void **) &obj);
        }

        /*
         * Allocate a new COM instance as localized object wrapper.
         */
                T *
        Alloc (
                CLxLocalizedObject	&loc)
        {
                ILxUnknownID		 obj;

                obj = Spawn ();
                if (!obj)
                        throw (LXe_FAILED);

                loc.take (obj);
                return Cast (loc);
        }

    //internal:
                void *
        NewObj ()
                                                 LXx_OVERRIDE
        {
                return reinterpret_cast<void *> (new T);
        }

                void
        FreeObj (
                void			*obj)
                                                 LXx_OVERRIDE
        {
                T			*elt = reinterpret_cast<T*> (obj);

                delete elt;
        }

        virtual void	SetCOM (T *, ILxUnknownID) {}

                void
        RawCOM (
                void			*objCPP,
                ILxUnknownID		 objCOM)
                                                 LXx_OVERRIDE
        {
                SetCOM (reinterpret_cast<T*> (objCPP), objCOM);
        }
};


/*
 * A singleton polymorph is a generic polymorph that can be cast to a
 * single instance of itself. The base class has to implement the NewObj()
 * method as provided in the macro below. Typically subclasses will add
 * their interfaces in their constructor to prevent timing issues with
 * when the instance is spawned.
 */
class CLxSingletonPolymorph :
                public CLxGenericPolymorph
{
    public:
        LXtObjectID		 m_ifc;

        CLxSingletonPolymorph ()
        {
                m_ifc = 0;
        }

        ~CLxSingletonPolymorph ()
        {
                if (m_ifc)
                        lx::ObjRelease (m_ifc);
        }

        /*
         * Casting this object to ILxUnknownID will allocate the instance.
         */
                operator
        ILxUnknownID ()
        {
                if (!m_ifc)
                        m_ifc = Spawn ();

                return reinterpret_cast <ILxUnknownID> (m_ifc);
        }

    //internal:
                void
        FreeObj (
                void		*self)
                                 LXx_OVERRIDE
        {
        }
};

#define LXxSINGLETON_METHOD	void * NewObj() LXx_OVERRIDE { return this; }


/*
 * Deferred initialization can be done by any object of this type. The
 * initialize() function will be called after all servers have had a chance
 * to initialize themselves.
 */
//@util CLxDeferredInitializer

class CLxDeferredInitializer
{
    public:
        CLxDeferredInitializer	*next, *prev;

        virtual void		 initialize () = 0;
};


/*
 * Common setup functions.
 */
namespace lx {

        /*
         * Queue object for deferred initialization.
         */
        extern void			QueueInit (CLxDeferredInitializer *);

        /*
         * Plug-ins and client apps can register new servers by calling this generic
         * utility function. The polymorph will be added as a server of the given name.
         * FindServer() gets the generic back again.
         */
        extern void			AddServer (const char *, CLxGenericPolymorph *);
        extern CLxGenericPolymorph *	FindServer (const char *);

        /*
         * Plug-ins and client apps can store their own spawners (polymorphs) in a global
         * table. FindSpawner() gets the generic.
         */
        extern void			AddSpawner (const char *, CLxGenericPolymorph *);
        extern CLxGenericPolymorph *	FindSpawner (const char *);

        /*
         * Get the type-specific polymorph for a server. This is a template
         * function that take the class of the wrapped object.
         */
                template <class T>
                CLxPolymorph<T> *
        GetServer (
                const char		*name)
        {
                CLxGenericPolymorph	*pg;

                pg = FindServer (name);
                return dynamic_cast<CLxPolymorph<T> *> (pg);
        }

        /*
         * Get the type-specific polymorph for a spawner. This is a template
         * function that take the class of the wrapped object.
         */
                template <class T>
                CLxPolymorph<T> *
        GetSpawner (
                const char		*name)
        {
                CLxGenericPolymorph	*pg;

                pg = FindSpawner (name);
                return dynamic_cast<CLxPolymorph<T> *> (pg);
        }

        /*
         * Cast a COM server instance back to the C++ object that it contains.
         */
                template <class T>
                void
        CastServer (
                const char		*name,
                ILxUnknownID		 unk,
                T		       *&tptr)
        {
                tptr = GetServer<T> (name) -> Cast (unk);
        }

        /*
         * Return a CLxResult based on a method that creates a new object. If
         * the method failed we clear the localized object and return the failure
         * code. If the method succeeded we try to take the new object and return
         * a code for that.
         */
                template <class T>
                CLxResult
        TakeResult (
                T			&loc,
                LxResult		 rc,
                LXtObjectID		 obj)
        {
                if (CLxResult::ok (rc))
                        return CLxResult (loc.take (obj), LXe_NOINTERFACE);

                loc.clear ();
                return CLxResult (rc);
        }

}	// END namespace


//@skip
/*
 * ----------------------------------------------------------
 * Interfaces and Wrappers.
 *
 * An interface is simply an abstract class that defines methods which
 * correspond 1 to 1 with the function vectors of the COM interface.
 * The client would inherit from one or more of these interfaces and
 * fill in their implementations.
 *
 * A wrapper template acts as a translator from COM proxies to the
 * client's class implementation.  They provide static entry points 
 * which extract the client's object pointer from the proxy, and then
 * does a static cast to convert the client's object type into the type
 * of the abstract class.  Then it simply calls the methods.
 */
#include <lxw_server.hpp>


//@read
/*
 * Global cache is a utility class for maintaining globals. There can be
 * only one of these in any plug-in or application.
 */
class CLxGlobalCache
{
    public:
        /*
         * Get a GUID pointer from a GUID string or alias.
         */
        const LXtGUID *		 LookupGUID (const char *);

        /*
         * Get the cannonical GUID pointer from any GUID pointer.
         */
        const LXtGUID *		 LookupGUID (const LXtGUID *);

        /*
         * Get the interface for a global service by GUID.
         */
        LXtObjectID		 GetGlobal  (const LXtGUID *);

        /*
         * Get the interface for a global service by name.
         */
        LXtObjectID		 GetGlobal  (const char *ident)
                                  {  return GetGlobal (LookupGUID (ident));  }

        /*
         * Add a polymorph to a table addressed by name.
         */
        void			 AddSpawner (const char *, CLxGenericPolymorph *);

        /*
         * Find the polymorph given the name.
         */
        CLxGenericPolymorph *	 FindSpawner (const char *);

    //internal:
        static CLxDeferredInitializer	*di_head;
        static CLxGlobalCache		*di_gc;

                                 CLxGlobalCache ();
                                ~CLxGlobalCache ();

        void			 InitGlobal (ILxUnknownID);
        void			 FreeGlobal ();
        static void		 QueueInit (CLxDeferredInitializer *);
        void			 InitAll ();

    private:
        class pv_GlobalCache	*pv;
};


//@skip
/*
 * Simple utility class to treat an array of LXtTagInfoDesc structs as
 * a server tags API.
 */
class CLxStaticTagArray
{
    public:
        LXtTagInfoDesc		*list;
        
        CLxStaticTagArray (LXtTagInfoDesc *array)
        {
                list = array;
        }

                unsigned
        count ()
        {
                unsigned		 n;

                if (!list)
                        return 0;

                for (n = 0; list[n].type; n++)
                        ;

                return n;
        }

                LxResult
        describe (
                unsigned		 index,
                LXtTagInfoDesc		*desc)
        {
                if (index >= count ())
                        return LXe_OUTOFBOUNDS;

                *desc = list[index];
                return LXe_OK;
        }
};


/*
 * This is a non-standard Tag Description wrapper.  This allows a client
 * class to define a static array of descriptions to be displayed as a
 * Tag Description COM interface.
 */
template <class T>
class CLxIfc_StaticDesc :
                public CLxInterface
{
                static unsigned
        Count (
                LXtObjectID		 wcom)
        {
                T			*obj  = LXCWxWCOM(T);
                CLxStaticTagArray	 sta (obj->descInfo);

                return sta.count ();
        }

                static LxResult
        Describe (
                LXtObjectID		 wcom,
                unsigned		 index,
                LXtTagInfoDesc		*desc)
        {
                T			*obj  = LXCWxWCOM(T);
                CLxStaticTagArray	 sta (obj->descInfo);

                return sta.describe (index, desc);
        }

                ILxTagDescription	 vt;
        public:

        CLxIfc_StaticDesc ()
        {
                vt.Count	= Count;
                vt.Describe	= Describe;
                vTable		= &vt.iunk;
                iid		= &lx::guid_TagDescription;
        }
};


//@read

/*
 * Spawners hold a polymorph for a specific class and pass common methods
 * for allocating and testing through directly.
 */
template <class T>
class CLxSpawnerCommon
{
    public:
        CLxPolymorph<T>			*spawn;

        T *	Cast  (ILxUnknownID wcom)	{ return spawn->Cast (wcom); }
        T *	Alloc (void **ppvObj)		{ return spawn->Alloc (ppvObj); }
        T *	Alloc (ILxUnknownID &obj)	{ return spawn->Alloc (obj); }
        T *	Alloc (CLxLocalizedObject &loc)	{ return spawn->Alloc (loc); }

                void
        AddInterface (
                CLxInterface		*ifc)
        {
                spawn->AddInterface (ifc);
        }

                LxResult
        TestInterfaceRC (
                const LXtGUID		*guid)
        {
                return (spawn->TestInterface (guid) ? LXe_TRUE : LXe_FALSE);
        }
};


/*
 * A spawner object can be declared for a given type and spawner name. If the
 * spawner has already been registered then this provides methods for creating
 * COM-object instances for the given type.
 *
 * @code
 *	CLxSpawner<MyClass>	 sp ("spawn.name");
 *	MyClass			*my;
 *	ILxUnknownID		 obj;
 *
 *	my = sp.Alloc (obj);
 * @end
 *
 * Spawners can also be bound later using the set() method.
 */
template <class T>
class CLxSpawner :
                 public CLxSpawnerCommon<T>
{
    public:
        CLxSpawner ()
        {
                CLxSpawnerCommon<T>::spawn = 0;
        }

                void
        set (
                const char		*spname)
        {
                if (CLxSpawnerCommon<T>::spawn)
                        return;

                CLxGenericPolymorph	*gp;

                gp = lx::FindSpawner (spname);
                CLxSpawnerCommon<T>::spawn = dynamic_cast<CLxPolymorph<T> *> (gp);
        }

        CLxSpawner (
                const char		*spname)
        {
                CLxSpawnerCommon<T>::spawn = 0;
                set (spname);
        }

};

/*
 * This is the same but will create the spawner if it doesn't already exist.
 * The client of this object should add appropriate interfaces when spawners
 * are created.
 *
 * @code
 *	CLxSpawnerCreate<MyClass>	 sp ("MyClass");
 *	MyClass				*my;
 *	ILxUnknownID			 obj;
 *
 *	if (sp.created)
 *		sp.AddInterface(new CLxImpl_SomeInterface<MyClass>);
 *
 *	my = sp.Alloc (obj);
 */
template <class T>
class CLxSpawnerCreate :
                 public CLxSpawnerCommon<T>
{
    public:
        bool				 created;

        CLxSpawnerCreate (
                const char		*spname)
        {
                CLxGenericPolymorph	*gp;

                gp = lx::FindSpawner (spname);
                if (gp) {
                        CLxSpawnerCommon<T>::spawn = dynamic_cast<CLxPolymorph<T> *> (gp);
                        created = false;
                } else {
                        CLxSpawnerCommon<T>::spawn = new CLxPolymorph<T>;
                        lx::AddSpawner (spname, CLxSpawnerCommon<T>::spawn);
                        created = true;
                }
        }
};


/*
 * A typical server consists of a single interface of the server's type, plus
 * a static description for its tags.
 */
#define LXx_ADD_SERVER(what,T,name)\
        { CLxGenericPolymorph *srv = new CLxPolymorph<T>;\
        srv->AddInterface (new CLxIfc_##what<T>);\
        srv->AddInterface (new CLxIfc_StaticDesc<T>);\
        lx::AddServer (name, srv); }


#endif

