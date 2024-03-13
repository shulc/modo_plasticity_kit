/*
 * LX listener module
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
#ifndef LX_listener_H
#define LX_listener_H

typedef struct vt_ILxListenerService ** ILxListenerServiceID;
typedef struct vt_ILxListenerPort ** ILxListenerPortID;

#include <lxvalue.h>



/*
 * A listener service allows a client to submit itself as a global
 * listener. The client object is queried for all global listener interfaces and any
 * that are found will subsequently receive notifications as events occur.
 */
typedef struct vt_ILxListenerService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
AddListener) (
        LXtObjectID		 self,
        LXtObjectID		 object);

        LXxMETHOD(  LxResult,
RemoveListener) (
        LXtObjectID		 self,
        LXtObjectID		 object);
} ILxListenerService;

/*
 * Many nexus objects may also support listener ports. By querying for a port
 * interface on an item or scene and adding to that, the listener client will
 * receive events for changes only on that specific object.
 */
typedef struct vt_ILxListenerPort {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddListener) (
        LXtObjectID		 self,
        LXtObjectID		 object);

        LXxMETHOD(  LxResult,
RemoveListener) (
        LXtObjectID		 self,
        LXtObjectID		 object);
} ILxListenerPort;


        #define LXu_LISTENERSERVICE	"1966420D-DFED-11D7-A237-000A9593D716"


        #define LXu_LISTENERPORT	"4FBF5E77-152D-4C4F-BFD4-3F6062CCF6BA"
        // [export] ILxListenerPort lport
        // [local]  ILxListenerPort

#endif
