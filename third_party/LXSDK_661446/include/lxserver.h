/*
 * LX server module
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
#ifndef LX_server_H
#define LX_server_H

typedef struct vt_ILxFactory ** ILxFactoryID;
typedef struct vt_ILxHostService ** ILxHostServiceID;
typedef struct vt_ILxModule ** ILxModuleID;
typedef struct vt_ILxTagDescription ** ILxTagDescriptionID;
typedef struct vt_ILxNeedContext ** ILxNeedContextID;
typedef struct vt_ILxServiceExtension ** ILxServiceExtensionID;
typedef struct vt_ILxModule1 ** ILxModule1ID;
/*
 * We have to make sure some of the common definitions are made available to
 * the host plug-in implementation at the right points.
 */

#include <lxio.h>
#include <lxvalue.h>


/*
 * Modules are servers are self-describing by presenting a Tag Description
 * interface.  For a module the tags of "server" type give the name (as info) and
 * the interface type (as GUID) for the servers in the module, and is used by
 * the nexus to determine which servers are exported by an unknown module.
 * For servers the tags can define various properties, including the user
 * name.
 */
typedef struct st_LXtTagInfoDesc {
        const char		*type;
        const char		*info;
        const LXtGUID		*guid;
} LXtTagInfoDesc;


/*
 * Accessors for the server's name, username and class.
 * 
 * 
 * 
 * Get the module the server is in, or NULL if this is a built-in server.
 * 
 * This allow reading the tags for a factory. These do not need to be implemented
 * by extension factories since the tags are read from the server instance.
 * 
 * Aditionally, servers can be spawned using these functions.  The COM interface
 * returned needs to be released by the caller using Release(), as usual.
 */
typedef struct vt_ILxFactory {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        const char		**name);
        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		  self,
        const char		**userName);
        LXxMETHOD(  LxResult,
ClassGUID) (
        LXtObjectID		  self,
        LXtGUID			 *guid);
        LXxMETHOD(  LxResult,
Module) (
        LXtObjectID		 self,
        const char	       **module);
        LXxMETHOD(  LxResult,
InfoTag) (
        LXtObjectID		 self,
        const char		*type,
        const char	       **value);

        LXxMETHOD(  LxResult,
TagCount) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD(  LxResult,
TagByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **type,
        const char	       **value);
        LXxMETHOD(  LxResult,
Spawn) (
        LXtObjectID		  self,
        void			**ppvObj);
} ILxFactory;

/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.
 * 
 * This method can be used to lookup a factory it's class and server name.  If
 * allowLoad is true it will prompt the user to find a module if the server
 * is not known.  The factory must be released when no longer needed.
 * 
 * This simply tests to see if a server exists, and skips the error reporting.
 * 
 * These methods allow the server database to be scanned.  These first two
 * allow the server list to walked by class.  The factory returned must be
 * released when no longer needed.
 * 
 * 
 * Servers can also be looked up by name to get their index.
 * 
 * Application hosts can add servers as factories. This should not be done by
 * plug-ins becuase they can add servers through the module method.
 * 
 * This returns the path to the plug-in directory.
 * 
 * We can also query things specific to our module. This return LXe_TRUE if the
 * server is being spawned only to read tags.
 * 
 * Dynamic modules can update - well, dynamically. Calling this method will force
 * the server database to update the contents of the dynamic module.
 * 
 * Saver verification can be triggered directly for a given format and data object.
 * 
 * This will perform a save using the filename, format and data object. The monitor
 * is optional.
 */
typedef struct vt_ILxHostService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
LookupServer) (
        LXtObjectID		 self,
        const char		*className,
        const char		*name,
        unsigned		 allowLoad,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
TestServer) (
        LXtObjectID		 self,
        const char		*className,
        const char		*name);
        LXxMETHOD(  unsigned,
NumServers) (
        LXtObjectID		 self,
        const char		*className);
        LXxMETHOD(  LxResult,
ServerByIndex) (
        LXtObjectID		 self,
        const char		*className,
        unsigned		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ServerGetIndex) (
        LXtObjectID		 self,
        const char		*className,
        const char		*name,
        unsigned		*index);
        LXxMETHOD(  LxResult,
AddServer) (
        LXtObjectID		 self,
        LXtObjectID		 factory);
        LXxMETHOD(  LxResult,
DefaultPath) (
        LXtObjectID		  self,
        const char		**path);
        LXxMETHOD(  LxResult,
SpawnForTagsOnly) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
UpdateModule) (
        LXtObjectID		 self,
        const char		*name);
        LXxMETHOD(  LxResult,
SaverVerify) (
        LXtObjectID		 self,
        const char		*format,
        LXtObjectID		 object,
        LXtObjectID		 msg);
        LXxMETHOD(  LxResult,
SaverSave) (
        LXtObjectID		 self,
        const char		*filename,
        const char		*format,
        LXtObjectID		 object,
        LXtObjectID		 monitor);
} ILxHostService;

/*
 * Plug-in modules are loaded like any file, using an ILxLoader.  The load is
 * opaque, and the object type loaded is "module".
 * An ILxModule is a special type of factory capable of spawning servers
 * of different classes which are the servers implemented by the module.
 * - Generate
 * creates a new server instance given the class GUID and server name.
 * 
 * - GetTags
 * optional method returns a StringTag interface for a server based on the
 * name and class ID. Allows tags to be read without creating a server inst.
 * 
 */
typedef struct vt_ILxModule {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Generate) (
        LXtObjectID		 self,
        const char		*name,
        const LXtGUID		*iid,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
GetTags) (
        LXtObjectID		 self,
        const char		*name,
        const LXtGUID		*iid,
        void		       **ppvObj);
} ILxModule;

/*
 * The Count() function returns the number of info tags for the object, and
 * the Describe() method fills in the info for a given tag index.
 */
typedef struct vt_ILxTagDescription {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Count) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Describe) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtTagInfoDesc		*desc);
} ILxTagDescription;

/*
 * The "need context" interface can be defined by any module or server
 * that wants to be informed about the application context when it's first
 * created.  The application passed to the SetContext() method can be queried
 * for globals, and is owned by the client and needs to be released. Note: this
 * conflicts with the COM standard, so you cannot "set" this argument, you must
 * "take" it.
 */
typedef struct vt_ILxNeedContext {
        ILxUnknown	 iunk;
        LXxMETHOD ( LxResult,
SetContext) (
        LXtObjectID		 self,
        LXtObjectID		 app);
} ILxNeedContext;

/*
 * Global services can be extended by plug-ins. The extension interface itself is
 * just a handle that lets lets us allocate a server object, which is then queried
 * for the real service interface.
 */
typedef struct vt_ILxServiceExtension {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Dummy) (
        LXtObjectID		 self);
} ILxServiceExtension;

/*
 * Legacy Module1 interface, which is exported by all the pre-701 plug-ins. We
 * declare it here, add a translator, and convert from one to the other.
 */
typedef struct vt_ILxModule1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Generate) (
        LXtObjectID		 self,
        const char		*name,
        const LXtGUID		*iid,
        void		       **ppvObj);

        LXxMETHOD( unsigned,
IsLocked) (
        LXtObjectID		 self);
} ILxModule1;

/*
 * The nexus plug-in system maintains a database of the external servers
 * which can be accessed.  The servers in the system are referenced by a
 * combination of class and name.
 * A Server Class is a GUID which determines the type of service which the
 * server can perform.  This is also the main interface provided by the
 * server.  There can be many servers of the same class, including many
 * built-in to the nexus application.
 * A Server Name is a string which refers to a specific server within a
 * given class.  This might be something like "FractalNoise3D" or "JPEG".
 * The name must be unique among the servers of the same class.  A server
 * name must be a byte string containing characters only in the ASCII range
 * 33-127.  It can contain no spaces and except for built-in servers must
 * start with an alphabetic character.  Case is significant unless it is
 * ignored in a specific usage context, such as commands which are looked up
 * in a case-insensitive manner.
 * 
 * Servers also have a set of tagged strings which define their fixed
 * attributes, and which describe the kinds of services they perform
 * within their class.  These tags strings are read from the server and are
 * stored in the database for reference while the server is not loaded.
 * There are some tags common to all servers:
 * 
 * - USERNAME
 * is the name of the server to be presented to the user in the UI. This can be
 * a reference to a message table using "@table@msg@" syntax.
 * 
 * - LICENSE
 * indicates that the server needs a license in order to function. The
 * license string is the product ID followed by a feature or build number.
 * For example "iblend 12231" or "corel_X 300". Feature numbers should
 * always be multiple digits for security. The string can also optionally
 * contain a date for maintainance licenses, of the form "d:YYYY.MMDD".
 * Example: "product 99999 d:2015.0130".
 * 
 * - OWNER, SERIAL
 * are set to the name of the license holder and the serial number for the
 * license, for plug-ins that require licenses. The plug-in can read these
 * values by looking up itself in the host service.
 * 
 */

        #define LXsSRV_USERNAME		"server.username"
        #define LXsSRV_LICENSE		"server.license"
        #define LXsSRV_OWNER		"server.owner"
        #define LXsSRV_SERIAL		"server.serial"

/*
 * An ILxFactory is an internal nexus object that can create servers of a specific
 * type.  Internally it has a handle to a plug-in module which will be loaded
 * as needed.
 */

        #define LXu_FACTORY		"2431A79E-3412-4B0D-987D-875489466C58"
        // [export] ILxFactory
        // [local]  ILxFactory
        // [python] ILxFactory:Spawn	obj Unknown

/*
 * This provides access to the list of factories.  For convenience these methods
 * all take the class GUID as a string, which is how they are defined in the API.
 */

        #define LXu_HOSTSERVICE		"525802A6-BF5F-46E9-9863-C03B54A3D908"
        #define LXa_HOSTSERVICE		"hostservice"

        // [python] ILxHostService:LookupServer		obj Factory
        // [python] ILxHostService:ServerByIndex	obj Factory
        // [python] ILxHostService:TestServer		bool


        #define LXu_MODULE	"4DB9C543-B192-4EDD-A65D-DD012FC27416"
        #define LXa_MODULE	"module2"
        // [local]  ILxModule
        // [export] ILxModule
        // [python] ILxModule:Generate	obj Unknown
        // [python] ILxModule:GetTags	obj StringTag


        #define LXu_TAGDESCRIPTION	"5582E0EE-D682-47BC-BF3D-FB14D59948C1"
        #define LXsMOD_SERVER		"server"
        // [export] ILxTagDescription
        // [local]  ILxTagDescription


        #define LXu_NEEDCONTEXT		"7D30408C-74AB-4d87-B71C-C6280883863C"
        // [local]  ILxNeedContext
        // [export] ILxNeedContext


        #define LXu_SERVICEEXTENSION	"E7C6F1A2-2F31-4FA5-B2EF-421BE159D0D8"
        #define LXa_SERVICEEXTENSION	"serviceExtension"
        // [export]  ILxServiceExtension

        #define LXsSRVEXT_GUID		"extension.guid"


        #define LXu_MODULE1	"BD6F0E53-C903-46D3-9211-758558D95CAA"
        #define LXa_MODULE1	"module"

#endif
