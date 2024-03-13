/*
 * LX projdir module
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
#ifndef LX_projdir_H
#define LX_projdir_H

typedef struct vt_ILxProjDirOverride ** ILxProjDirOverrideID;

#include <lxcom.h>
#include <lxserver.h>



/*
 * The interface has a single method.  Returning a failure code will cause the search to
 * walk up the hierarchy of the scene as normal.  A success code will cause the search to
 * start from the path provided by the method.  If that path is empty or doesn't exist, we
 * will not try to find a project directory.
 * We only really expect one server to exist at a time, since this interface is intended
 * for special cases only.  If multiple servers are found, the order is undefined and the
 * first one that returns a success code is the path that is tested.
 */
typedef struct vt_ILxProjDirOverride {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
OverrideWith) (
        LXtObjectID		  self,
        const char		 *originalPath,
        char			 *buf,
        unsigned		  len);
} ILxProjDirOverride;

/*
 * The project directory is normally found by walking up the directory hierarchy containing
 * the scene file itself to look for a .luxproject file.  This can be overridden to look
 * in an arbitrary path by implmenting an ILxProjDirOverride server.
 */

        #define LXu_PROJDIROVERRIDE	"257bac48-5e70-42a3-b5a4-7eb33fdba114"
        #define LXa_PROJDIROVERRIDE	"projdiroverride"

        // [local] ILxProjDirOverride
        // [export] ILxProjDirOverride pdo

#endif
