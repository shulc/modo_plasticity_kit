/*
 * LX clip module
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
#ifndef LX_clip_H
#define LX_clip_H

typedef struct vt_ILxVideoClipItem ** ILxVideoClipItemID;

#include <lxcom.h>



/*
 * A video clip item presents a special interface to allow it to be a video
 * clip.
 * - PrepFilter
 * Given an ILxEvaluation interface, Add the channels needed to compute the
 * filter. Data can be cached in the cache pointer.
 * - AllocFilter
 * Allocate an ILxImageFilter object using the cache. Values for this item
 * can be read from the attributes.
 * 
 * - Cleanup
 * Delete the cache, if any.
 * 
 */
typedef struct vt_ILxVideoClipItem {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
PrepFilter) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        void		       **cache);

        LXxMETHOD(  LxResult,
AllocFilter) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        void			*cache,
        void		       **ppvObj);

        LXxMETHOD(  void,
Cleanup) (
        LXtObjectID		 self,
        void			*cache);
} ILxVideoClipItem;


        #define LXu_VIDEOCLIPITEM	"340FD1AD-B576-4BC3-8B6F-7DF1F5C312FB"
        // [export] ILxVideoClipItem vclip
        // [local]  ILxVideoClipItem
        // [python] ILxVideoClipItem:AllocFilter	obj ImageFilter (image)

#endif
