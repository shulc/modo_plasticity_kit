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
 * This implements global module and main entry point for a C++ plug-in.
 */
#include <lx_plugin.hpp>
#include <string.h>
#include <stdlib.h>

using namespace lx;


/*
 * These utilities call methods on thisModule from parts of the code that
 * shouldn't know about thisModule. Specifically getting a GUID from a string
 * and a global interface from a GUID.
 */
        const LXtGUID *
lx::LookupGUID (
        const char		*name)
{
        return thisModule.LookupGUID (name);
}

        LXtObjectID
lx::GetGlobal (
        const LXtGUID		*guid)
{
        return thisModule.GetGlobal (guid);
}

        void
lx::AddServer (
        const char		*name,
        CLxGenericPolymorph	*srv)
{
        thisModule.AddServer (name, srv);
}

        CLxGenericPolymorph *
lx::FindServer (
        const char		*name)
{
        return thisModule.FindServer (name);
}

        void
lx::AddSpawner (
        const char		*name,
        CLxGenericPolymorph	*srv)
{
        thisModule.AddSpawner (name, srv);
}

        CLxGenericPolymorph *
lx::FindSpawner (
        const char		*name)
{
        return thisModule.FindSpawner (name);
}

        void
lx::QueueInit (
        CLxDeferredInitializer	*initer)
{
        CLxGlobalCache::QueueInit (initer);
}

        unsigned
lx::Lifecycle ()
{
        return thisModule.lifecycle;
}


/*
 * ----------------------------------------------------------
 *
 * Exported module.  A single module instance is created and exported
 * for the purpose of hooking the system to the host application.  This
 * acts as it's own polymorph, so the NewObj() method returns this itself,
 * and the FreeObj() method cleans up the state, releasing the cached
 * globals.
 */
        void *
CLxThisModule::NewObj ()
{
        return reinterpret_cast<void *> (this);
}

        void
CLxThisModule::FreeObj (
        void			*obj)
{
        cleanup ();
        lifecycle = LXiLIFECYCLE_AFTER;
        FreeGlobal ();
}


/*
 * The client adds new servers (polymorphs) with this function.  We insert
 * the name and the default interface into the master list.
 */
        void
CLxThisModule::AddServer (
        const char		*name,
        CLxGenericPolymorph	*poly)
{
        if (numSrv >= bufferSize)
        {
                bufferSize += 20;

                if (NULL == (iPoly = (CLxGenericPolymorph**)realloc (iPoly, bufferSize * sizeof *iPoly)) ||
                    NULL == (iName = (const char**)         realloc (iName, bufferSize * sizeof *iName)) ||
                    NULL == (iGUID = (const LXtGUID**)      realloc (iGUID, bufferSize * sizeof *iGUID)))
                {
                        numSrv = bufferSize = 0;
                        throw (LXe_OUTOFMEMORY);
                }
        }
        
        if(poly)
                poly->SetIdentifier (name);

        iPoly[numSrv] = poly;
        iName[numSrv] = name;
        iGUID[numSrv] = poly->DefaultInterface ();
        numSrv++;
}

/*
 * Lookup a cached polymorph by name.
 */
        CLxGenericPolymorph *
CLxThisModule::FindServer (
        const char		*name)
{
        for (unsigned i = 0; i < numSrv; i++)
                if (!strcmp (name, iName[i]))
                        return iPoly[i];

        return 0;
}

/*
 * The Generate() method on the ILxModule interface uses the list of servers
 * to find the right polymorph and spawn a new instance with the appropriate
 * wrapper.
 */
        LxResult
CLxThisModule::mod_Generate (
        const char		*name,
        const LXtGUID		*iid,
        void		       **ppvObj)
{
        for (unsigned i = 0; i < numSrv; i++)
                if (!strcmp (name, iName[i]) && !GUIDCompare (iid, iGUID[i])) {
                        ppvObj[0] = iPoly[i]->Spawn (iid);
                        if (ppvObj[0])
                                return LXe_OK;
                        else
                                return LXe_FAILED;
                }

        return LXe_NOTFOUND;
}


/*
 * The module's ILxTagDescription interface lists the servers by name and
 * interface ID.
 */
        unsigned
CLxThisModule::tag_Count ()
{
        return numSrv;
}

        LxResult
CLxThisModule::tag_Describe (
        unsigned		 index,
        LXtTagInfoDesc		*desc)
{
        if (index >= numSrv)
                return LXe_OUTOFBOUNDS;

        desc->type = LXsMOD_SERVER;
        desc->info = iName[index];
        desc->guid = iGUID[index];
        return LXe_OK;
}


/*
 * The module's ILxNeedContext interface gets the master global from the
 * application. We pass this to the CLxGlobalCache initialization method.
 */
        LxResult
CLxThisModule::need_SetContext (
        ILxUnknownID		 app)
{
        InitGlobal (app);
        return LXe_OK;
}

/*
 * Module constructor initializes the polymorph wrappers for itself.
 */
CLxThisModule::CLxThisModule ()
{
        numSrv = bufferSize = 0;
        lifecycle = LXiLIFECYCLE_BEFORE;

        iPoly = NULL;
        iName = NULL;
        iGUID = NULL;

        AddInterface (new CLxIfc_Module        <CLxThisModule>);
        AddInterface (new CLxIfc_TagDescription<CLxThisModule>);
        AddInterface (new CLxIfc_NeedContext   <CLxThisModule>);
}

/*
 * Module destructor frees allocated buffers
 */
CLxThisModule::~CLxThisModule ()
{
        if (iPoly)
            free (iPoly);
        if (iName)
            free (iName);
        if (iGUID)
            free (iGUID);
}


/*
 * The global state consists of the static module, plus the entry point
 * from the host system. We allow clients to initialize their servers and
 * add them to the module, both directly and through the deferred list.
 * Then we return a COM wrapper for the module itself back to the host
 * application.
 */
CLxThisModule		thisModule;

extern "C"
{
 #ifdef _WIN32
                __declspec(dllexport)
 #else
 	#pragma GCC visibility push(default)
 #endif

                ILxModuleID
        _ILxModule_Create (void)
        {
                static bool  init = 1;

                if (init) {
                        try {
                                initialize ();
                                thisModule.InitAll ();

                                thisModule.lifecycle = LXiLIFECYCLE_DURING;
                        } catch (...) {
                                return NULL;
                        }

                        init = 0;
                }
                return reinterpret_cast<ILxModuleID> (thisModule.Spawn ());
        }
#ifndef _WIN32
        #pragma GCC visibility pop
#endif
}


