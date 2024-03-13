/*
 * LX drawover module
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
#ifndef LX_drawover_H
#define LX_drawover_H

typedef struct vt_ILxDrawingOverride ** ILxDrawingOverrideID;

#include <lxcom.h>
#include <lxserver.h>



/*
 * The flags on the interface determine the overrides that it supports.
 * 
 * Get a collection of the affected items
 * 
 * Set a specific item and read the style bits for override.
 * 
 * Read the color for a specific style bit.
 * 
 * Initialize pass drawing with the GL context pointer.
 * 
 * Cleanup any state in the GL context.
 * 
 * Allocate a draw visitor. This is an object specific to a scene and a view,
 * and it draws itself when the Visitor::Evaluate() method is called.
 */
typedef struct vt_ILxDrawingOverride {
        ILxUnknown	 iunk;
        LXxMETHOD( int,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
AffectedItems) (
        LXtObjectID		 self,
        LXtObjectID		 scene,
        LXtObjectID		 collection);
        LXxMETHOD( LxResult,
SetItem) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*styles);
        LXxMETHOD( LxResult,
GetColor) (
        LXtObjectID		 self,
        unsigned		 style,
        LXtVector4		 rgba);
        LXxMETHOD( LxResult,
InitContext) (
        LXtObjectID		 self);
        LXxMETHOD( void,
CleanupContext) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
DrawVisitor) (
        LXtObjectID		 self,
        LXtObjectID		 scene,
        LXtObjectID		 view,
        void		       **ppvObj);
} ILxDrawingOverride;

/*
 * The DrawingOverride interface is an optional interface on package servers.
 * This allows the package, when present in a scene, to override the default
 * drawing of the scene in the interactive viewports,
 */

        #define LXu_DRAWINGOVERRIDE	"52429702-1D97-4B00-8154-6510D34EE8CA"
        // [local]  ILxDrawingOverride
        // [export] ILxDrawingOverride drov


        #define LXfDRAWOVER_ITEM_STYLES	 0x01
        #define LXfDRAWOVER_PASS_SOLID	 0x02


        #define LXfDRAWOVER_STYLE_GHOSTING	 0x01
        #define LXfDRAWOVER_STYLE_WIREFRAME	 0x02

#endif
