/*
 * LX externalrender module
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
#ifndef LX_externalrender_H
#define LX_externalrender_H

typedef struct vt_ILxExternalRender ** ILxExternalRenderID;
typedef struct vt_ILxExternalRenderBufferQueue ** ILxExternalRenderBufferQueueID;
typedef struct vt_ILxExternalRenderNotifier ** ILxExternalRenderNotifierID;

#include <lxrender.h>


typedef struct st_LXtExternalRenderBuffer {
        void*		ptr;
        unsigned	w, h, fmt;
        unsigned	reserved;
} LXtExternalRenderBuffer;


/*
 * The first method will start an External Render rendering. The External Render could either be stopped
 * or paused. If it's neither, this will have no effect.
 * And this method will stop it.
 * 
 * Alternatively, we can pause the External Render. This stops rendering, but a future start
 * will not clear the image and will resume where it left off, unless the scene has
 * been updated.
 * 
 * This function will both set External Render such that the next time it starts, it will
 * do a full update, completely rebuilding all the render data and tableau from
 * scratch.
 * 
 * This function passes the image coordinates of the pixel of the rendered image [(0,0) is top-left]
 * on which the mouse has been clicked.
 * This allows the external renderer to perform operations such as hit detection.
 * 
 * This function takes a ILxExternalRenderNotifier object, which will get notified when a new image is available.
 * 
 */
typedef struct vt_ILxExternalRender {
        ILxUnknown	 iunk;
        LXxMETHOD (	LxResult,
Start) (
        LXtObjectID		  self);
        LXxMETHOD (	LxResult,
Stop) (
        LXtObjectID		  self);
        LXxMETHOD (	LxResult,
Pause) (
        LXtObjectID		  self);
        LXxMETHOD (	LxResult,
Reset) (
        LXtObjectID		  self);
        LXxMETHOD (	LxResult,
SelectedPixelAt) (
        LXtObjectID		  self,
        const int		  x,
        const int		  y);
        LXxMETHOD (	LxResult,
SetNotifier) (
        LXtObjectID		self,
        LXtObjectID		notifier);
        LXxMETHOD (	LxResult,
SetBufferQueue ) (
        LXtObjectID		  self,
        LXtObjectID		  bufferQueue);
} ILxExternalRender;

typedef struct vt_ILxExternalRenderBufferQueue {
        ILxUnknown	 iunk;
        LXxMETHOD (	LxResult, 
WriteBegin ) (
        LXtObjectID		 self, 
        LXtExternalRenderBuffer	*buffer);
        LXxMETHOD (	LxResult, 
WriteEnd) (
        LXtObjectID		 self, 
        LXtExternalRenderBuffer	*buffer);
} ILxExternalRenderBufferQueue;

typedef struct vt_ILxExternalRenderNotifier {
        ILxUnknown	 iunk;
        LXxMETHOD (	LxResult,
Notify) (
        LXtObjectID			 self,
        const LXtRenderOutputProcess	*rndrProcess,
        LXtObjectID			 image,
        int				 completed );
        LXxMETHOD (	LxResult,
SetStatusText) (
        LXtObjectID			 self,
        const char			*text );
} ILxExternalRenderNotifier;

/*
 * The External Render SDK API allows a plug-in to create and perform headless, interactive
 * Preview renders using external renderers.
 * External Render attribute query
 */

        #define LXs_EXTERNALRENDER_ATTR_DEVCOUNT	"render.deviceCount"
        #define LXs_EXTERNALRENDER_ATTR_DEVNAME	"render.deviceName"

/*
 * The External Render object is where all the interesting things happen.
 */

        #define LXu_EXTERNALRENDER		"4D764AD2-E3B8-4689-93E0-613107E044B8"
        #define LXa_EXTERNALRENDER		"externalrender"
        
        // [local] ILxExternalRender
        // [export] ILxExternalRender rend

        // [const] ILxExternalRender:Start
        // [const] ILxExternalRender:Stop
        // [const] ILxExternalRender:Pause
        // [const] ILxExternalRender:Reset
        // [const] ILxExternalRender:SelectedPixelAt

/*
 * The ExternalRender will use ExternalRenderBufferQueue to communicate with external render clients
 */

        #define LXu_EXTERNALRENDERBUFFERQUEUE		"17F0A6B6-9B36-4BE2-B65B-76D2AC3F5753"
        #define LXa_EXTERNALRENDERBUFFERQUEUE		"externalrenderbufferqueue"
        
        // [local] ILxExternalRenderBufferQueue

/*
 * This is the ExternalRenderNotifier interface class that users can implement to get notified when a preview image
 * is available.
 */

        #define LXu_EXTERNALRENDERNOTIFIER		"2D7FFF27-5E49-47C2-928D-380D8E18E8F9"
        #define LXa_EXTERNALRENDERNOTIFIER		"externalrendernotifier"
        
        // [local] ILxExternalRenderNotifier
        // [export] ILxExternalRenderNotifier ntf

#endif
