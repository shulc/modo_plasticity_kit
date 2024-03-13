/*
 * LX persist module
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
#ifndef LX_persist_H
#define LX_persist_H

typedef struct vt_ILxPersistenceService ** ILxPersistenceServiceID;
typedef struct vt_ILxPersistenceClient ** ILxPersistenceClientID;
typedef struct vt_ILxPersistentEntry ** ILxPersistentEntryID;


/*
 * 
 * Clients call this method to define a set of persistent attributes. The name
 * will define a top-level atom in the config file which should be unique. The
 * object can be a visitor which, when evaluated, should add entries and values.
 * It should be noted that this function should only be called once for any
 * top-level name during the lifetime of the application. Attempting to call it
 * again will return an error.
 * 
 * 
 * During configuration, these calls define the nested hierarchy of entries.
 * Each entry has a name and a type -- atom, hash or list. Ending the entry
 * definition returns the persistent entry object which can be use to traverse
 * persistent values.
 * 
 * While in an entry definition, values can be added. Currently only one value
 * per entry is allowed. The type name is any of the value types.
 */
typedef struct vt_ILxPersistenceService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
Configure) (
        LXtObjectID		 self,
        const char		*name,
        LXtObjectID		 obj);
        LXxMETHOD( LxResult,
Start) (
        LXtObjectID		 self,
        const char		*name,
        unsigned int		 type);

        LXxMETHOD( LxResult,
End) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
AddValue) (
        LXtObjectID		 self,
        const char		*typeName);
} ILxPersistenceService;

/*
 * - Setup
 * Called to configure the entries and values, like Evaluate() from a visitor.
 * - SyncRead
 * Called when the client should read its state from the application. This will
 * be called after a successful initial setup.
 * - SyncRead
 * Called when the client should write its cached state to the application.
 * 
 */
typedef struct vt_ILxPersistenceClient {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Setup) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
SyncRead) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
SyncWrite) (
        LXtObjectID		 self);
} ILxPersistenceClient;

/*
 * Entry objects also have an ILxAttributes interface for accessing their values,
 * although for now all values are index 0.
 * Count() tells you how many values there are for this entry. For atoms this is
 * 0 or 1, depending on whether it's defined. For lists and hashes this can be
 * more than one.
 * 
 * These methods pick the specific entry. Select() uses and index and works for
 * lists or hashes, and Lookup() uses a key and is only for hashes. Entries that
 * are atoms don't need to be explicitly selected.
 * 
 * These methods add new values -- Append() for atoms and lists, and Insert() for
 * hashes.
 * 
 * These methods remove values. Delete() removes this specific value, while Clear()
 * removes all values of this type from the current parent.
 * 
 * For hash entries, this returns the hash itself.
 */
typedef struct vt_ILxPersistentEntry {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Count) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD( LxResult,
Select) (
        LXtObjectID		 self,
        unsigned int		 index);

        LXxMETHOD( LxResult,
Lookup) (
        LXtObjectID		 self,
        const char		*key);
        LXxMETHOD( LxResult,
Append) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Insert) (
        LXtObjectID		 self,
        const char		*key);
        LXxMETHOD( LxResult,
Delete) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Clear) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Hash) (
        LXtObjectID		  self,
        const char		**key);
} ILxPersistentEntry;

/*
 * The service provides methods to define the setup of the configuration.
 */

        #define LXu_PERSISTENCESERVICE	"4CB5705E-C705-499D-9561-6FD369CEFE99"
        #define LXa_PERSISTENCESERVICE	"persistenceservice"
        // [python] ILxPersistenceService:End	obj PersistentEntry


        #define LXi_PERSIST_ATOM	 0
        #define LXi_PERSIST_HASH	 1
        #define LXi_PERSIST_LIST	 2

/*
 * In most case the client will maintain persistent state in the host app and
 * read it whenever it's needed. This allows the client to react to changes to
 * the application persistent state (like if the user imports new configs) but
 * it can be slower than desired for very complex resource definitions, for
 * example. If that's the case the client will want to cache their state internally,
 * but they then need to be able to react to config system events.
 * If this is required the client can pass a PersistenceClient object in the
 * call to Configure() instead of a visitor. In this case the object itself will
 * persist, and methods will be used to manage synchnonization.
 */

        #define LXu_PERSISTENCECLIENT	"435E3BEE-8317-4DEB-92A8-74E115384F3F"
        #define LXa_PERSISTENCECLIENT	"persistenceclient"
        // [local]  ILxPersistenceClient
        // [export] ILxPersistenceClient cc

/*
 * Access to persistent state is through a persistent entry interface. The value
 * for sub-entries depends on the values of their parent entries, so those need
 * to be set in order to get valid results for sub-entries.
 */

        #define LXu_PERSISTENTENTRY	"BD3F1DF5-967B-441F-86A7-A091F2E6CDA5"
        // [local] ILxPersistentEntry

#endif
