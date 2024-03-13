/*
 * Plug-in SDK Source: C++ COM Wrapper Implementation
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
 * This implements the utility functions for the C++ COM proxy wrappers.
 * These are the functions and methods common to the plug-in and API wrappers.
 */
#include <lx_wrap.hpp>
#include <lx_log.hpp>
#include <lx_visitor.hpp>
#include <lx_message.hpp>
#include <lx_com.hpp>
#include <lxw_thread.hpp>
#include <lxu_getstring.hpp>
#include <lx_value.hpp>
#include <vector>
#include <map>

using namespace lx;


/*
 * ----------------------------------------------------------
 * Utilities:
 */

/*
 * Simple GUID comparison metric.
 */
        int
lx::GUIDCompare (
        const LXtGUID		*g1,
        const LXtGUID		*g2)
{
        int			 x;

        if ((x = (g1->x4    - g2->x4   )))	return x;
        if ((x = (g1->x2[0] - g2->x2[0])))	return x;
        if ((x = (g1->x2[1] - g2->x2[1])))	return x;
        if ((x = (g1->x1[0] - g2->x1[0])))	return x;
        if ((x = (g1->x1[1] - g2->x1[1])))	return x;
        if ((x = (g1->x1[2] - g2->x1[2])))	return x;
        if ((x = (g1->x1[3] - g2->x1[3])))	return x;
        if ((x = (g1->x1[4] - g2->x1[4])))	return x;
        if ((x = (g1->x1[5] - g2->x1[5])))	return x;
        if ((x = (g1->x1[6] - g2->x1[6])))	return x;
        if ((x = (g1->x1[7] - g2->x1[7])))	return x;
        return 0;
}

/*
 * Function to assign all the elements of a guid, which could perhaps be
 * simpler.
 */
        void
lx::GUIDSet (
        LXtGUID			*guid,
        unsigned int		 x4,
        unsigned int		 x2a,
        unsigned int		 x2b,
        unsigned int		 x1a,
        unsigned int		 x1b,
        unsigned int		 x1c,
        unsigned int		 x1d,
        unsigned int		 x1e,
        unsigned int		 x1f,
        unsigned int		 x1g,
        unsigned int		 x1h)
{
        guid->x4    = x4;
        guid->x2[0] = x2a;
        guid->x2[1] = x2b;
        guid->x1[0] = x1a;
        guid->x1[1] = x1b;
        guid->x1[2] = x1c;
        guid->x1[3] = x1d;
        guid->x1[4] = x1e;
        guid->x1[5] = x1f;
        guid->x1[6] = x1g;
        guid->x1[7] = x1h;
}


        ILxUnknownID
lx::UnkAddRef (
        ILxUnknownID		 iunk)
{
        iunk[0]->AddRef (iunk);
        return iunk;
}

        LXtObjectID
lx::ObjAddRef (
        LXtObjectID		 obj)
{
        ILxUnknownID		 iunk;

        iunk = reinterpret_cast<ILxUnknownID>(obj);
        iunk[0]->AddRef (iunk);
        return obj;
}

        void
lx::UnkRelease (
        ILxUnknownID		 iunk)
{
        iunk[0]->Release (iunk);
}

        void
lx::ObjRelease (
        LXtObjectID		 obj)
{
        ILxUnknownID		 iunk;

        iunk = reinterpret_cast<ILxUnknownID>(obj);
        iunk[0]->Release (iunk);
}

        LXtObjectID
lx::GetGlobal (
        const char		*name)
{
        return lx::GetGlobal (lx::LookupGUID (name));
}

/*
 * COM comparison queries for IUnknown and checks for pointer equivalence. There's
 * really no way that should be able to fail but we'll raise an exception if it
 * happens.
 */
        bool
lx::UnkIsSameObject (
        ILxUnknownID		 unk1,
        ILxUnknownID		 unk2)
{
        LXtObjectID		 u1, u2;
        LxResult		 rc;
        bool			 eq;

        if (!unk1 || !unk2)
                return false;

        rc = unk1[0]->QueryInterface (unk1, &lx::guid_Unknown, &u1);
        if (LXx_FAIL (rc))
                throw (rc);

        rc = unk2[0]->QueryInterface (unk2, &lx::guid_Unknown, &u2);
        if (LXx_FAIL (rc))
        {
                lx::ObjRelease (u1);
                throw (rc);
        }

        eq = (u1 == u2);
        lx::ObjRelease (u1);
        lx::ObjRelease (u2);
        return eq;
}


/*
 * Throw a LxResult exception for failure codes. The optional variant allows
 * for NOTIMPL as a valid code.
 */
        void
lx::ThrowErr (
        LxResult		 rc)
{
        if (LXx_FAIL (rc))
                throw (rc);
}

        void
lx::ThrowOpt (
        LxResult		 rc)
{
        if (rc != LXe_NOTIMPL)
                lx::ThrowErr (rc);
}


/*
 * Return true if we're only being spawned for reading tags.
 */
        bool
lx::IsTempSpawn ()
{
        CLxLoc_HostService		 host_S;

        host_S.set();
        return host_S.SpawnForTagsOnly() == LXe_TRUE;
}


/*
 * Send string back to modo, perhaps raising the "short buffer" error.
 * We return the truncated string in that case because some callers
 * expect that.
 */
        LxResult
lx::StringOut (
        const char		*string,
        char			*buf,
        unsigned		 len)
{
        if (len > strlen (string)) {
                strcpy (buf, string);
                return LXe_OK;
        } else {
                strncpy (buf, string, len - 1);
                buf[len - 1] = 0;
                return LXe_SHORTBUFFER;
        }
}

        LxResult
lx::StringOut (
        std::string		&string,
        char			*buf,
        unsigned		 len)
{
        return lx::StringOut (string.c_str (), buf, len);
}


/*
 * Get the user string for an lxresult code, if possible. If not just return
 * the code as a string.
 */
        std::string
lx::LxResultName (
        LxResult		 rc)
{
        CLxUser_MessageService	 m_S;
        CLxUser_Message		 msg;
        std::string		 res;
        char			 hex[32];

        sprintf (hex, "%08x", rc);

        if (   m_S.m_loc
            && m_S.Allocate (msg)
            && LXx_OK (msg.SetMessage ("lxresult", hex, 0))
            && LXx_OK (m_S.GetText (msg, res))
            && res.length() )
        {
                return res;
        }

        char			 buf[64];

        sprintf (buf, "%x", rc);
        return std::string (buf);
}

/*
 * ----------------------------------------------------------
 * Observer visitor
 */
        void
COMInstance_SetMaster (
        LXtCOMInstance		*instance,
        ILxUnknownID		 master,
        bool			 observe);

class CObserver : public CLxImpl_Visitor {

        public:
                        static CObserver *
                Spawn (
                        LXtCOMInstance *instance,
                        ILxUnknownID &obj)
                {
                        CLxSpawnerCreate<CObserver> spawner("__observer");
                        
                        if (spawner.created)
                                spawner.AddInterface (new CLxIfc_Visitor<CObserver>);
                        
                        CObserver *observer = spawner.Alloc(obj);
                        observer->instance = instance;
                        
                        return observer;
                }
                
                        static CObserver *
                Cast (
                        ILxUnknownID obj)
                {
                        CLxSpawner<CObserver> spawner("__observer");
                
                        if (obj)
                                return spawner.Cast(obj);
                        
                        return NULL;
                }
                
                CObserver () : instance (NULL) { }
        
                LXxO_Visitor_Evaluate {  // LxResult (void)
                        
                        if (instance)
                        {
                                COMInstance_SetMaster (instance, NULL, false);
                                instance = NULL;
                        }
                        
                        return LXe_OK;
                }

                LXtCOMInstance *instance;
};

        void
COMInstance_AddObserver (
        LXtCOMInstance		*instance,
        ILxUnknownID		 visitor)
{
        if (!instance)
                return;
                
        CLxUser_Visitor observer (visitor);
        if (observer.test ())
        {
                if (instance->observers.find (observer) == instance->observers.end ())
                {
                        instance->observers.insert (visitor);
                        lx::UnkAddRef (visitor);
                }
        }
}

        void
COMInstance_RemoveObserver (
        LXtCOMInstance		*instance,
        ILxUnknownID		 visitor)
{
        if (!instance)
                return;
                
        CLxUser_Visitor observer (visitor);
        if (observer.test ())
        {
                if (instance->observers.erase (observer) != 0)
                        lx::UnkRelease (observer);
        }
}

        void
COMInstance_SignalObservers (
        LXtCOMInstance		*instance,
        bool 			 release)
{
        if (instance && false == instance->observers.empty())
        {
                std::vector<ILxUnknownID> observers(instance->observers.begin (), instance->observers.end ());
                std::vector<ILxUnknownID>::reverse_iterator vectorIterator;
                for (vectorIterator = observers.rbegin (); vectorIterator != observers.rend (); ++vectorIterator)
                {
                        ILxUnknownID unknown = *vectorIterator;
                        if (unknown)
                        {
                                CLxUser_Visitor visitor (unknown);
                                if (visitor.test ())
                                        visitor.Evaluate ();
                        }
                }
                
                if (release)
                {
                        std::set<ILxUnknownID>::reverse_iterator setIterator;
                        for (setIterator = instance->observers.rbegin (); setIterator != instance->observers.rend (); ++setIterator)
                        {
                                ILxUnknownID unknown = *setIterator;
                                if (unknown)
                                        lx::UnkRelease (unknown);
                        }

                        instance->observers.clear ();
                }
        }
}

        void
COMInstance_SetMaster (
        LXtCOMInstance		*instance,
        ILxUnknownID		 master,
        bool			 observe)
{
        if (instance)
        {
                if (instance->master)
                {
                        if (instance->master == master)
                                return;
                                
                        if (instance->observerVisitor)
                        {
                                CLxLoc_Object object (instance->master);
                                if (object.test ())
                                        object.RemoveObserver (instance->observerVisitor);
                        
                                CObserver *observer = CObserver::Cast (instance->observerVisitor);
                                if (observer)
                                        observer->instance = NULL;
                                        
                                lx::UnkRelease (instance->observerVisitor);
                                instance->observerVisitor = NULL;
                        }
                        
                        instance->master = NULL;
                }
                
                instance->master = master;
                if (instance->master && observe)
                {
                        CLxLoc_Object object (instance->master);
                        if (object.test ())
                        {
                                if (CObserver::Spawn (instance, instance->observerVisitor))
                                        object.AddObserver (instance->observerVisitor);
                        }
                }
        }
}

/*
 * ----------------------------------------------------------
 * Utility Class Methods:
 */

static ILxThreadServiceID	gThreadSvc = NULL;
static ILxThreadMutexID		gMutex     = NULL;

/*
 * Since proxyList.Remove() & AddTail() aren't thread safe, create a mutex
 * for locking these - only available when the thread service is already there.
 * Instances of this class hold the mutex as long as they exist.
 */
class CHoldMutex
{
        
    public:
        CHoldMutex ()
        {
                if (!gMutex)
                {
                        if (!gThreadSvc)
                                gThreadSvc = (ILxThreadServiceID)lx::GetGlobal(&lx::guid_ThreadService);

                        if (gThreadSvc)
                        {
                                LxResult res;
                                res = gThreadSvc[0]->CreateMutex (gThreadSvc, (void **) &gMutex);
                                if (LXx_FAIL (res))
                                        gMutex = NULL;
                        }
                }

                if (gMutex)
                        gMutex[0]->Enter (gMutex);
        }

        ~CHoldMutex ()
        {
                if (gMutex)
                        gMutex[0]->Leave (gMutex);
        }
};


CLxRefCounted::CLxRefCounted ()
{
        ref_count = 1;

 #ifdef LX_TRACEALLOC
        trace_mode = false;
 #endif
}

        void
CLxRefCounted::acquire ()
{
        if (! gThreadSvc)
                gThreadSvc = (ILxThreadServiceID)lx::GetGlobal(&lx::guid_ThreadService);

        gThreadSvc[0]->AtomicIncrement (gThreadSvc, &ref_count);

 #ifdef LX_TRACEALLOC
        if (trace_mode)
                trace_Change (1);
 #endif
}

        void
CLxRefCounted::release ()
{
 #ifdef LX_TRACEALLOC
        if (trace_mode)
                trace_Change (-1);
 #endif

        if (0 == gThreadSvc[0]->AtomicDecrement (gThreadSvc, &ref_count))
                delete this;
}


/*
 * ----------------------------------------------------------
 * ILxObject implementation
 */
class CObject : public CLxImpl_Object {

        public:
                        static void *
                Allocate(
                        LXtCOMInstance		 *instance)
                {
                        static CLxGenericPolymorph *srv = NULL;
                        if(srv == NULL)
                        {
                                srv = new CLxPolymorph<CObject>();
                                srv->AddInterface(new CLxIfc_Object<CObject>);
                        }
                        
                        ILxUnknownID object = srv->Spawn(&guid_Object);
                        if (NULL != object)
                        {
                                CObject *data = LXCWxOBJ (object, CObject);
                                data->instance = instance;
                                return object;
                        }
                        
                        return NULL;
                }
                
                CObject()
                {
                        instance = NULL;
                }
        
                LXxO_Object_Identifier  // LxResult obj_Identifier (const char **id)
                {
                        if (!instance || !instance->polymorph)
                                return LXe_FAILED;
                                
                        *id = instance->polymorph->Identifier ();
                        return (*id) ? LXe_OK : LXe_NOTFOUND;
                }
                
                LXxO_Object_InterfaceCount  // LxResult obj_InterfaceCount (unsigned int *count)
                {
                        if (!instance || !instance->polymorph)
                                return LXe_FAILED;
                                
                        *count = instance->polymorph->InterfaceCount ();
                                
                        return LXe_OK;
                }
                
                LXxO_Object_InterfaceByIndex  // LxResult obj_InterfaceByIndex (unsigned int index, const LXtGUID **guid)
                {
                        if (!instance || !instance->polymorph)
                                return LXe_FAILED;

                        if (index < instance->polymorph->InterfaceCount ())
                        {
                                *guid = instance->polymorph->InterfaceByIndex (index);
                                if (*guid)
                                        return LXe_OK;
                        }
                        
                        return LXe_OUTOFBOUNDS;
                }
                
                LXxO_Object_AddObserver  // void obj_AddObserver (LXtObjectID visitor)
                {
                        if (instance)
                                COMInstance_AddObserver (instance, visitor);
                }
                
                LXxO_Object_RemoveObserver  // void obj_RemoveObserver (LXtObjectID visitor)
                {
                        if (instance)
                                COMInstance_RemoveObserver (instance, visitor);
                }
                
        private:
                LXtCOMInstance		*instance;
};


/*
 * ----------------------------------------------------------
 * Generic Polymorph Methods:
 */

/*
 * Find the interface given an ID.  If the interface is null or iUnknown
 * then we just use the first interface in the list.  Otherwise we scan
 * list and return the wrapper that matches and its index.
 */
        CLxInterface *
CLxGenericPolymorph::FindIID (
        const LXtGUID		*iid)
{
        CLxInterface		*wrap;

        if (!iid || GUIDCompare (iid, &lx::guid_Unknown) == 0)
                return ifc_list.first;

        for (wrap = ifc_list.first; wrap; wrap = wrap->next)
                if (GUIDCompare (iid, wrap->iid) == 0)
                        return wrap;

        return 0;
}


/*
 * Allocate a new proxy object for the given instance and ifc index. The 
 * new COM object has been addref-ed.
 */
        LXtCOMProxyID
CLxGenericPolymorph::NewProxy (
        LXtCOMInstance		*inst,
        CLxInterface		*wrap)
{
        LXtCOMProxy		*wcom;

        wcom = &inst->proxys[wrap->index];
        AddRef (wcom);
        return wcom;
}


/*
 * The query interface callback from all COM wrapper vTables. This
 * searches for a wrapper interface matching the given IID, and if found
 * creates a new proxy. For iUnknown queries we return the first proxy
 * for the instance. We'll also allocate sub-objects if needed and assign
 * their sub/master relationship.
 */
        LxResult
CLxGenericPolymorph::QueryInterface (
        LXtObjectID		 self,
        const LXtGUID		*iid,
        void		       **ppvObj)
{
        LXtCOMProxy		*wcom = reinterpret_cast<LXtCOMProxy *> (self);
        LXtCOMInstance		*inst = wcom->instance;
        LXtCOMProxy		*wsub;
        CLxInterface		*wrap;
        
        if (inst->polymorph && 0 == GUIDCompare (iid, &guid_Object))
        {
                ppvObj[0] = CObject::Allocate (inst);
                if (ppvObj[0] == NULL)
                        return LXe_NOINTERFACE;
                        
                wsub = reinterpret_cast<LXtCOMProxy *> (ppvObj[0]);
                COMInstance_SetMaster (wsub->instance, (ILxUnknownID) self, false);

                wsub->instance->polymorph->InitObj (wsub->object, inst->polymorph->RefObj (wcom->object));

                return LXe_OK;
        }

        if (inst->master)
                return inst->master[0]->QueryInterface (inst->master, iid, ppvObj);

        if (!inst->polymorph)
                return LXe_NOINTERFACE;

        wrap = inst->polymorph->FindIID (iid);
        if (wrap)
        {
                ppvObj[0] = inst->polymorph->NewProxy (inst, wrap);
                return LXe_OK;
        }

        ppvObj[0] = inst->polymorph->IsA ((ILxUnknownID) self, iid);
        if (ppvObj[0])
        {
                wsub = reinterpret_cast<LXtCOMProxy *> (ppvObj[0]);
                COMInstance_SetMaster (wsub->instance, (ILxUnknownID) self, true);

                wsub->instance->polymorph->InitObj (wsub->object, inst->polymorph->RefObj (wcom->object));

                return LXe_OK;
        }
        
        return LXe_NOINTERFACE;
}


/*
 * Reference counting methods increment and decrement the counts on the
 * proxy and the instance.  When the counts go to zero we free either or
 * both.
 */
        unsigned
CLxGenericPolymorph::AddRef (
        LXtObjectID		 self)
{
        LXtCOMProxy		*wcom = reinterpret_cast<LXtCOMProxy *> (self);
        int			 newCount, newTotal;

        if (! gThreadSvc)
                gThreadSvc = (ILxThreadServiceID)lx::GetGlobal(&lx::guid_ThreadService);

        if (gThreadSvc) {
                newCount = gThreadSvc[0]->AtomicIncrement (gThreadSvc, &wcom->refCount);
                newTotal = gThreadSvc[0]->AtomicIncrement (gThreadSvc, &wcom->instance->refCount);
        } else {
                newCount = ++(wcom->refCount);
                newTotal = ++(wcom->instance->refCount);
        }

 #ifdef LX_COM_TRACE
        if (wcom->instance->trace)
                wcom->instance->trace->event (CLxCOMTrace::ADDREF, newTotal);
 #else
        LXxUNUSED (newTotal);
 #endif

        return newCount;
}

        unsigned
CLxGenericPolymorph::Release (
        LXtObjectID		 self)
{
        LXtCOMProxy		*wcom = reinterpret_cast<LXtCOMProxy *> (self);
        LXtCOMInstance		*inst;
        int			 newCount, newTotal;

        if (! gThreadSvc)
                gThreadSvc = (ILxThreadServiceID)lx::GetGlobal(&lx::guid_ThreadService);

        if (gThreadSvc) {
                newTotal = gThreadSvc[0]->AtomicDecrement (gThreadSvc, &wcom->instance->refCount);
                newCount = gThreadSvc[0]->AtomicDecrement (gThreadSvc, &wcom->refCount);
        } else {
                newTotal = --(wcom->instance->refCount);
                newCount = --(wcom->refCount);
        }

 #ifdef LX_COM_TRACE
        if (wcom->instance->trace)
                wcom->instance->trace->event (CLxCOMTrace::RELEASE, newTotal);
 #endif

        if (newCount)
                return newCount;

        if (newTotal)
                return 0;
                
        inst = wcom->instance;
        
        /*
                Signal any observers that we're about to be destroyed.
         */
        COMInstance_SignalObservers (inst, true);
        
        /*
                Set the master to NULL. If it was set, this releases any
                reference count and stops observing the master.
         */
        COMInstance_SetMaster (inst, NULL, false);

        if (inst->polymorph)
        {
                {
                        CHoldMutex hold;
                        inst->polymorph->obj_list.Remove (inst);
                }
                inst->polymorph->FreeObj (inst->object);
        }

        delete inst;
        return 0;
}


 #ifdef LX_COM_TRACE
        void
CLxGenericPolymorph::SetTrace (
        ILxUnknownID		 ifc,
        CLxCOMTrace		*trace)
{
        LXtCOMProxy		*wcom = reinterpret_cast<LXtCOMProxy *> (ifc);

        wcom->instance->trace = trace;
        if (trace)
                trace->event (CLxCOMTrace::START, wcom->instance->refCount);
}
 #endif


/*
 * Add a new interface wrapper to the polymorph.  We initialize the
 * IUnknown methods to our local forms and add the wrapper to the list.
 */
        void
CLxGenericPolymorph::AddInterface (
        CLxInterface		*wrap)
{
        ILxUnknown		*iunk;

        iunk = wrap->vTable;
        iunk->QueryInterface = QueryInterface;
        iunk->AddRef         = AddRef;
        iunk->Release        = Release;

        ifc_list.AddTail (wrap);	// seems to be only called from main thread, so no mutex needed?
}


/*
 * The default interface for a polymorph is given by the first one added.
 */
        const LXtGUID *
CLxGenericPolymorph::DefaultInterface ()
{
        return (ifc_list.first ? ifc_list.first->iid : NULL);
}


/*
 * Test if this polymorph supports the given interface.
 */
        bool
CLxGenericPolymorph::TestInterface (
        const LXtGUID		*iid)
{
        return (FindIID (iid) != 0);
}


/*
 * Spawn generates a new instance and wraps it with an interface. The
 * requested interface must be on the master object.
 */
        ILxUnknownID
CLxGenericPolymorph::Spawn (
        const LXtGUID		*iid)
{
        CLxInterface		*wrap, *dest;
        LXtCOMInstance		*inst;
        ILxUnknownID		 com;

        dest = FindIID (iid);
        if (!dest)
                return 0;

        inst = new LXtCOMInstance;
        inst->polymorph = this;
        inst->object    = NewObj ();
        inst->master    = 0;
        inst->refCount  = 0;
        inst->observerVisitor = NULL;
 #ifdef LX_COM_TRACE
        inst->trace     = 0;
 #endif

        if (ifc_count == 0)
                for (wrap = ifc_list.first; wrap; wrap = wrap->next)
                        wrap->index = ifc_count++;

        inst->proxys.Alloc (ifc_count);

        for (wrap = ifc_list.first; wrap; wrap = wrap->next)
        {
                LXtCOMProxy		&wcom = inst->proxys[wrap->index];

                wcom.vTable    = wrap->vTable;
                wcom.object    = inst->object;
                wcom.instance  = inst;
                wcom.refCount  = 0;
        }

        {
         CHoldMutex hold;
         obj_list.AddHead (inst);
        }

        com = (ILxUnknownID) NewProxy (inst, dest);
        RawCOM (inst->object, com);
        return com;
}

        bool
CLxGenericPolymorph::SetIdentifier (
        const char		*identifier)
{
        if (id)
                return false;
                
        id = identifier;
        return true;
}

        const char *
CLxGenericPolymorph::Identifier ()
{
        return id;
}

        unsigned int
CLxGenericPolymorph::InterfaceCount ()
{
        return (ifc_count > 0) ? ifc_count : 0;
}

        const LXtGUID *
CLxGenericPolymorph::InterfaceByIndex (
        unsigned int		index)
{
        unsigned int current = 0;
        for (CLxInterface *wrap = ifc_list.first; wrap; wrap = wrap->next)
        {
                if (current == index)
                        return wrap->iid;
                current++;
        }
        
        return NULL;
}

/*
 * When destroying the polymorph we cut loose any instances and make them
 * zombies.
 */
CLxGenericPolymorph::~CLxGenericPolymorph ()
{
        LXtCOMInstance		*inst;
        int			 i;

        for (inst = obj_list.first; inst; inst = inst->next)
        {
                inst->polymorph = 0;
                inst->object    = 0;
                for (i = 0; i < ifc_count; i++)
                        inst->proxys[i].object = 0;
        }
}


/*
 * ----------------------------------------------------------
 * Global Cache Methods:
 *
 * The global cache keeps globals in a fixed-sized array.
 */
#define MAX_GLOBAL	 100

class pv_GlobalCache {
    public:
                                 pv_GlobalCache ();
                                ~pv_GlobalCache ();

        bool			 InitGUIDService ();
        bool			 InitMutex ();
        LXtObjectID		 ScanGUID (const LXtGUID *guid);
        LXtObjectID		 AddGUID (const LXtGUID *guid);

        ILxUnknownID		 global;
        ILxGUIDServiceID	 guidSvc;
        ILxThreadMutexID	 mutex;
        LXtObjectID		 gSrvc[MAX_GLOBAL];
        const LXtGUID		*gGUID[MAX_GLOBAL];
        unsigned		 numGlob;

        typedef	std::map<std::string, CLxGenericPolymorph *>		SpawnTable;
        typedef	std::map<std::string, CLxGenericPolymorph *>::iterator	SpawnTable_Itr;

        SpawnTable		 table;
        CLxList<CLxDeferredInitializer>
                                 init_list;
};

CLxDeferredInitializer *	CLxGlobalCache::di_head = NULL;
CLxGlobalCache *		CLxGlobalCache::di_gc   = NULL;


/*
 * Set everything to uninitialized to start, and destroy anything allocated
 * at the end.
 */
pv_GlobalCache::pv_GlobalCache ()
{
        global  = 0;
        guidSvc = 0;
        mutex   = 0;
        numGlob = 0;
}

pv_GlobalCache::~pv_GlobalCache ()
{
        SpawnTable_Itr		 tit;

        for (tit = table.begin (); tit != table.end (); tit++)
                delete tit->second;

        for (unsigned i = 0; i < numGlob; i++)
                ObjRelease (gSrvc[i]);
        gThreadSvc = NULL;

        if (gMutex)
                IfcRelease (gMutex);
        gMutex = NULL;

        if (guidSvc)
                IfcRelease (guidSvc);

        if (mutex)
                IfcRelease (mutex);

        if (global)
                UnkRelease (global);
}

/*
 * Lookup of GUIDs use the GUID service, which we query for here as needed.
 */
        bool
pv_GlobalCache::InitGUIDService ()
{
        if (guidSvc)
                return true;

        if (!global)
                return false;

        LXtGUID			 guid;
        LxResult		 res;

        GUIDSet (&guid,	0xB11826F1, 0xA6BC, 0x48B4,
                        0x90, 0x9B, 0x5F, 0x6D, 0x01, 0x93, 0x83, 0x27);

        res = global[0]->QueryInterface (global, &guid, (void **) &guidSvc);
        if (LXx_FAIL (res)) {
                guidSvc = 0;
                return false;
        }

        return true;
}

/*
 * Write access to the global list is protected by a mutex, which we get
 * here when needed. We're fairly low-level here, so we don't employ any
 * of the wrappers.
 */
        bool
pv_GlobalCache::InitMutex ()
{
        if (mutex)
                return true;

        if (!global)
                return false;

        ILxThreadServiceID	 tsrv;
        const LXtGUID		*guid;
        LxResult		 res;

        guid = LookupGUID (LXu_THREADSERVICE);

        res = global[0]->QueryInterface (global, guid, (void **) &tsrv);
        if (LXx_FAIL (res))
                return false;

        res = tsrv[0]->CreateMutex (tsrv, (void **) &mutex);
        IfcRelease (tsrv);

        if (LXx_FAIL (res)) {
                mutex = 0;
                return false;
        }

        return true;
}

/*
 * This does a scan of the global list for a cached global. This can be done
 * outside the mutex since the list only grows.
 */
        LXtObjectID
pv_GlobalCache::ScanGUID (
        const LXtGUID		*guid)
{
        unsigned		 i, n = numGlob;

        for (i = 0; i < n; i++)
                if (!GUIDCompare (guid, gGUID[i]))
                        return gSrvc[i];

        return 0;
}

/*
 * Add a global GUID if not aready there. This happens inside the mutex, and we
 * scan the list again to avoid duplication. This GUID must be non-volatile.
 */
        LXtObjectID
pv_GlobalCache::AddGUID (
        const LXtGUID		*guid)
{
        LXtObjectID		 obj;
        LxResult		 res;

        if (!InitMutex ())
                return 0;

        mutex[0]->Enter (mutex);

        obj = ScanGUID (guid);
        if (!obj) {
                res = global[0]->QueryInterface (global, guid, &obj);
                if (LXx_FAIL (res))
                        obj = 0;
                else {
                        gSrvc[numGlob] = obj;
                        gGUID[numGlob] = guid;
                        numGlob++;
                }
        }

        mutex[0]->Leave (mutex);
        return obj;
}


/*
 * The public class just manages the private class. Initialization inits
 * the pv pointer, and takes over any deferred init objects by moving them
 * from the global list and marking itself as the main context.
 */
CLxGlobalCache::CLxGlobalCache ()
{
        CLxDeferredInitializer *di, *next;

        pv = new pv_GlobalCache;

        for (di = di_head; di; di = next)
        {
                next = di->next;
                pv->init_list.AddTail (di);
        }

        di_head = NULL;
        di_gc   = this;
}

CLxGlobalCache::~CLxGlobalCache ()
{
        FreeGlobal ();
}

        void
CLxGlobalCache::InitGlobal (
        ILxUnknownID		 glob)
{
        pv->global = glob;	// NOTE: it comes in pre-addrefed!
}

        void
CLxGlobalCache::FreeGlobal ()
{
        if (pv)
        {
                delete pv;
                pv = 0;
        }
}


/*
 * Getting a global first tries the unprotected search, then the protected add.
 * GUIDs passed here may be volatile, so we convert them to cannonical form
 * before caching them.
 */
        LXtObjectID
CLxGlobalCache::GetGlobal (
        const LXtGUID		*guid)
{
        LXtObjectID		 obj;

        if (!pv || !pv->global || !guid)
                return 0;

        obj = pv->ScanGUID (guid);
        if (obj)
                return obj;

        return pv->AddGUID (LookupGUID (guid));
}

/*
 * Accessing GUIDs uses the service.
 */
        const LXtGUID *
CLxGlobalCache::LookupGUID (
        const char		*ident)
{
        if (!pv->InitGUIDService ())
                return 0;

        return pv->guidSvc[0]->Translate (pv->guidSvc, ident);
}

        const LXtGUID *
CLxGlobalCache::LookupGUID (
        const LXtGUID		*guid)
{
        if (!pv->InitGUIDService ())
                return 0;

        return pv->guidSvc[0]->Fixed (pv->guidSvc, guid);
}


/*
 * Using the spawner table.
 */
        void
CLxGlobalCache::AddSpawner (
        const char		*name,
        CLxGenericPolymorph	*spawn)
{
        std::string		 key (name);

        if (spawn)
                spawn->SetIdentifier (name);

        // (#466348) GlobalCache should be initialized
        if (!pv)
                return;
        pv->table[key] = spawn;
}

        CLxGenericPolymorph *
CLxGlobalCache::FindSpawner (
        const char		*name)
{
        std::string			 key (name);
        pv_GlobalCache::SpawnTable_Itr	 tit;

        // (#466348) GlobalCache should be initialized
        if (!pv)
                return NULL;

        tit = pv->table.find (key);
        return tit == pv->table.end () ? NULL : tit->second;
}


/*
 * Arming and executing deferred initalizations. If this happens before
 * initialization we just put them in the global list.
 */
        void
CLxGlobalCache::QueueInit (
        CLxDeferredInitializer	*initer)
{
        if (di_gc)
                di_gc->pv->init_list.AddTail (initer);
        else
        {
                initer->next = di_head;
                di_head = initer;
        }
}

        void
CLxGlobalCache::InitAll ()
{
        CLxDeferredInitializer	*initer;

        for (initer = pv->init_list.first; initer; initer = initer->next)
                initer->initialize ();
}


/*
 * ----------------------------------------------------------
 * Error-checking that throws exceptions.
 */
        void
lx_err::check (
        LxResult		 rc)
{
        if (LXx_FAIL (rc))
                throw (rc);
}

        void
lx_err::check (
        CLxResult		 rc)
{
        if (!rc.ok())
                throw (rc.resultCode());
}

        void
lx_err::check (
        bool			 ok,
        LxResult		 rc)
{
        if (!ok)
                throw (rc);
}

        void
lx_err::check (
        int			 nonNeg,
        LxResult		 rc)
{
        if (nonNeg < 0)
                throw (rc);
}


/*
 * ----------------------------------------------------------
 * Easy visitor object. We have a single common spawner which we use to
 * create instances when needed for this same object.
 */
class cVisitWrap :
                public CLxImpl_Visitor
{
    public:
        CLxVisitor	*vis;

        ~cVisitWrap ()
        {
                if (vis->self_destruct ())
                        delete vis;
        }

        LxResult vis_Evaluate ()	LXx_OVERRIDE
        {
                return vis->eval_RC ();
        }
};

        ILxUnknownID
CLxVisitor::init_cache ()
{
        if (!self_cache.test ())
        {
                CLxSpawnerCreate<cVisitWrap> sp ("__visitor");
                cVisitWrap	*vw;

                if (sp.created)
                        sp.AddInterface (new CLxIfc_Visitor<cVisitWrap>);

                vw = sp.Alloc (self_cache);
                vw->vis = this;
        }

        return self_cache;
}


/*
 * ----------------------------------------------------------
 * Memory tracking.
 */
        #ifndef LX_TRACEALLOC

/*
 * If there's no tracking we just need a no-op main entry point.
 */
        void
lx::TraceObjects (
        bool			 full,
        bool			 toLog)
{
}

        #else

/*
 * Tracking is handled by a table that's local to this plug-in module.
 * It keeps a stack of location strings and a map from object pointers
 * to descriptions.
 */
static class CAllocTrace {
    public:
        std::vector<const char *>		 stack;
        std::map<CLxObject *, std::string>	 map;

                void
        get_Desc (
                std::string		&desc)
        {
                int			 i = stack.size ();

                if (i)
                {
                        desc = "";
                        for (i--; i >= 0; i--)
                        {
                                desc += stack[i];
                                if (i)
                                        desc += " | ";
                        }
                } else
                        desc = "(unk)";
        }
}				 alloc_trace;

static CLxMutexLock		*lock_trace;


/*
 * The trace object pushes and pops its description string for its scope.
 */
CLxTrace::CLxTrace (
        const char		*name)
{
        if (!lock_trace)
                lock_trace = new CLxMutexLock;

        CLxArmLockedMutex	 scope_lock (*lock_trace);

        alloc_trace.stack.push_back (name);
}

CLxTrace::~CLxTrace ()
{
        CLxArmLockedMutex	 scope_lock (*lock_trace);

        alloc_trace.stack.pop_back ();
}

/*
 * Objects store themselves in the map when allocated, erase when freed.
 */
CLxObject::CLxObject ()
{
        std::string		 desc;

        alloc_trace.get_Desc (desc);
        alloc_trace.map[this] = desc;
}

CLxObject::~CLxObject ()
{
        alloc_trace.map.erase (this);
}


/*
 * Trace output can go to stdout and to the log, which we handle with two
 * varients of the same abstract class.
 *
 * NOTE: log is unimplemented.
 */
class CTraceOut {
    public:
        virtual			~CTraceOut () {}
        virtual void		 ln_Out (const char *line) {}

                void
        ln_Out (
                std::string	 &line)
        {
                ln_Out (line.c_str ());
        }
};

class CTrace_Stdout : public CTraceOut {
    public:
        CLxUser_LogService	 log_S;

                void
        ln_Out (
                const char	*line)
        {
                log_S.DebugOut (LXi_DBLOG_NORMAL, "%s\n", line);
        }
};

class CTrace_Log : public CTraceOut {
    public:
        CLxUser_LogService	 lS;

        CTrace_Log ()
        {
        }

                void
        ln_Out (
                const char	*line)
        {
        }
};

/*
 * Trace output can be the whole table or just a summary of the common
 * descriptions.
 */
        void
lx::TraceObjects (
        bool			 full,
        bool			 toLog)
{
        CTraceOut		*out;
        std::map<CLxObject *,std::string>::iterator
                                 mit, term;
        std::string		 line;
        char			 buf[64];

        if (toLog)
                out = new CTrace_Log;
        else
                out = new CTrace_Stdout;

        CLxArmAllocation<CTraceOut> free_out (out);

        mit  = alloc_trace.map.begin ();
        term = alloc_trace.map.end ();
        if (mit == term)
        {
                out->ln_Out ("no unfreed objects");
                return;
        }

        if (full)
        {
                for (; mit != term; mit++)
                {
                        sprintf (buf, "%p", mit->first);
                        line = buf;
                        line += " @ ";
                        line += mit->second;

                        out->ln_Out (line);
                }

                return;
        }

        std::map<std::string,int>		 hist;
        std::map<std::string,int>::iterator	 hit;

        for (; mit != term; mit++)
        {
                hit = hist.find (mit->second);
                if (hit != hist.end ())
                        hit->second ++;
                else
                        hist[mit->second] = 0;
        }

        for (hit = hist.begin (); hit != hist.end (); hit++)
        {
                sprintf (buf, "%d", hit->second);
                line = buf;
                line += ": ";
                line += hit->first;

                out->ln_Out (line);
        }
}

        #endif


