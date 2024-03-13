/*
 * Plug-in SDK Header: Plug-in Header
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
 * This defines the global thisModule, and all the other code needed to make
 * a plug-in module.
 */
#ifndef LX_PLUGIN_HPP
#define LX_PLUGIN_HPP

#include <lx_wrap.hpp>


/*
 * ----------------------------------------------------------
 * The Global Module
 *
 * The Module itself is defined as a single static object which is
 * both a module and its own polymorph.  Clients should really only
 * call the AddServer() function to add new polymorphs for output.
 */
class CLxThisModule :
                public CLxImpl_Module,
                public CLxImpl_TagDescription,
                public CLxImpl_NeedContext,
                public CLxGenericPolymorph,
                public CLxGlobalCache
{
        CLxGenericPolymorph	**iPoly;
        const char		**iName;
        const LXtGUID		**iGUID;
        unsigned		 numSrv;
        unsigned		 bufferSize;

    public:
        unsigned		 lifecycle;

                                  CLxThisModule ();
                                 ~CLxThisModule ();

        void *			 NewObj  ()						LXx_OVERRIDE;
        void			 FreeObj (void *self)					LXx_OVERRIDE;

        unsigned		 tag_Count ()						LXx_OVERRIDE;
        LxResult		 tag_Describe (unsigned, LXtTagInfoDesc *)		LXx_OVERRIDE;
        LxResult		 need_SetContext (ILxUnknownID)				LXx_OVERRIDE;
        LxResult		 mod_Generate (const char *, const LXtGUID *, void **)	LXx_OVERRIDE;

        void			 AddServer  (const char *, CLxGenericPolymorph *);
        CLxGenericPolymorph *	 FindServer (const char *);

}; // END CLxThisModule


/*
 * The module for the plug-in is globally accessible, although the generic
 * accessor functions should normally be sufficient.
 */
extern class CLxThisModule	 thisModule;


/*
 * The "initialize()" function is defined by the plug-in client, and is the
 * right time to call AddServer() to define the servers for this plug-in
 * module. The "cleanup()" function is optional, and allows the plug-in client
 * to do any last-minute cleanup before quit.
 */
extern void			 initialize (void);
extern void			 cleanup (void);


#endif

