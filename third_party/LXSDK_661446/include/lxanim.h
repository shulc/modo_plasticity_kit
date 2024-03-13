/*
 * LX anim module
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
#ifndef LX_anim_H
#define LX_anim_H

typedef struct vt_ILxAnimListener ** ILxAnimListenerID;

#include <lxcom.h>
#include <lxvalue.h>
#include <lxidef.h>



/*
 * 
 * 
 * 
 * 
 */
typedef struct vt_ILxAnimListener {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
TimeChange) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
PlayStart) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
PlayEnd) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
ScrubTime) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
ScrubEnd) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
EnterSetup) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
LeaveSetup) (
        LXtObjectID		  self);
} ILxAnimListener;


        #define LXu_ANIMLISTENER	"4A0862DA-CAC6-48EC-A3DA-DE285FE528B5"
        #define LXa_ANIMLISTENER	"animlistener"
        #define LXi_PTAG_EXEC_NME       LXxID4('E','X','E','N')
        // [local]  ILxAnimListener
        // [export] ILxAnimListener	 animEvent

#endif
