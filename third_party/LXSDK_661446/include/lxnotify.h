/*
 * LX notify module
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
#ifndef LX_notify_H
#define LX_notify_H

typedef struct vt_ILxNotifySysService ** ILxNotifySysServiceID;
typedef struct vt_ILxNotifier ** ILxNotifierID;
typedef struct vt_ILxNotify ** ILxNotifyID;

#include <lxserver.h>



/*
 * Request ScriptQuery() method.
 * 
 * A new notifier can be instanced with this function.  The plug-in class
 * name and argument string are provided.  If the notifier with these arguments
 * already exists, that notifier is used instead.  IF a notifier with this name
 * and exact arguments is already instanced, it will be returned instead of
 * spawning a new one.  In both cases the returned object must be released when
 * no longer needed.
 * 
 * These functions can be used to walk the list of instanced notifiers.  As usual,
 * the client must release any objects returned by ByIndex(), NameByIndex() and
 * Lookup().
 * 
 * 
 * 
 * Notifiers that have been instanced can be looked up with this function.
 * This will fail if the notifier has not been instanced, and the returned
 * notifier must be released when no longer needed.
 */
typedef struct vt_ILxNotifySysService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Spawn) (
        LXtObjectID		 self,
        const char		*name,
        const char		*args,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
NameByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **name);
        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		 self,
        const char		*name,
        const char		*args,
        void		       **ppvObj);
} ILxNotifySysService;

/*
 * Get the name of the notifier, which should always be the same as the plug-in's name own name.
 * These set and get the argument strings.  The argument string allows specific events
 * to be filtered through the notifier.  For example, a tool notifier might only recognize
 * specific tools, with the tool name provided through the argument string.
 * 
 * 
 * A client is added to a notifier through this method. The client object has to
 * implement an interface compatible with this type of modifier.
 * 
 * This removes a client from a notifier that has been previously added.
 */
typedef struct vt_ILxNotifier {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        const char	       **name);
        LXxMETHOD(  LxResult,
SetArgs) (
        LXtObjectID		 self,
        const char		*args);
        LXxMETHOD(  LxResult,
Args) (
        LXtObjectID		 self,
        const char	       **args);
        LXxMETHOD(  LxResult,
AddClient) (
        LXtObjectID		 self,
        LXtObjectID		 object);
        LXxMETHOD(  LxResult,
RemoveClient) (
        LXtObjectID		 self,
        LXtObjectID		 object);
} ILxNotifier;

/*
 * The notifier that triggered this event is avaible to the client.  This allows the
 * notifier's name and arguments to be read out.
 */
typedef struct vt_ILxNotify {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Notifier) (
        LXtObjectID		 self,
        void		       **ppvObj);
} ILxNotify;

/*
 * The notification service is used to manage different notifiers, such as
 * adding new notifiers or walking the notifier list.
 */

        #define LXu_NOTIFYSYSSERVICE	"4A3B31B0-A8F8-430A-9611-9D30E51CBBBA"
        // [python] ILxNotifySysService:ByIndex	obj Notifier
        // [python] ILxNotifySysService:Lookup	obj Notifier
        // [python] ILxNotifySysService:Spawn	obj Notifier


        #define LXsNOTIFIER_SELECT	"select.event"


        #define LXsNOTIFIER_MESHES	"meshes.event"


        #define LXsNOTIFIER_ITEM	"item.event"


        #define LXsNOTIFIER_GRAPHS	"graphs.event"


        #define LXsNOTIFIER_CHANNEL	"channel.event"


        #define LXsNOTIFIER_ACTION	"action.event"

/*
 * Individual notifiers support this interface.  The notifier itself simply monitors one or
 * more event ports and sends an ILxNotify object as the event data to the client.  Some
 * clients might except more interfaces on the object; for example, the attribute system
 * expects notifiers for command states to include an ILxCommandNotify interface so it can
 * know if the command's value, label or datatype needs refreshing.
 * The ILxNotify object is temporary, and must be released by the ILxNotifier after the
 * event has been sent.
 */

        #define LXu_NOTIFIER	"68725BA4-8EF9-4de4-8792-74CF090799C3"
        #define LXa_NOTIFIER	"notifier"
        // [local]  ILxNotifier
        // [export] ILxNotifier noti

/*
 * When a notification is triggered, one of these objects is sent as event data.  More
 * interfaces may be expected by the client as well, but this is the minimum.
 */

        #define LXu_NOTIFY	"15C9BFC0-A0A7-448c-8CD5-A8FCA2CB145B"

#endif
