/*
 * LX filter module
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
#ifndef LX_filter_H
#define LX_filter_H

typedef struct vt_ILxEvaluationStack ** ILxEvaluationStackID;
typedef struct vt_ILxStackFilter ** ILxStackFilterID;
typedef struct vt_ILxStackFilter1 ** ILxStackFilter1ID;
typedef struct vt_ILxCacheData ** ILxCacheDataID;
typedef struct vt_ILxCacheService ** ILxCacheServiceID;

#include <lxcom.h>



typedef struct vt_ILxEvaluationStack {
        ILxUnknown	 iunk;
        LXxMETHOD( const char *,
Type) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Branch) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
AddFilter) (
        LXtObjectID		 self,
        LXtObjectID		 filter);
} ILxEvaluationStack;

/*
 * Stacks are made of filters.  Here we define an interface that is common to all
 * filter types:
 * - Type
 * Returns the filter type. This is a string that identifies the type of the filter,
 * and will be used to determine if two filter objects can be compared. If you don't
 * want your Compare() method called with all kinds of other filters you should make
 * sure this string is unique.
 * - Compare
 * Compares to another filter and returns LXiSTACK_IDENTICAL if the results of these
 * filters would be the same, LXiSTACK_COMPATIBLE if the output of the other filter
 * can be converted to this one's, or LXiSTACK_DIFFERENT if they are irreconcilable.
 * 
 * - Convert
 * If this filter is unused but found to be compatible with another of the same type, the
 * Convert() method will be called to convert this one to match the new desired
 * form. The filter should remember the jist of the differences and update destination
 * object when applied.
 * 
 * - Identifier
 * This is expected to return an identifier that identifies this filter in an evaluation
 * stack.
 * 
 */
typedef struct vt_ILxStackFilter {
        ILxUnknown	 iunk;
        LXxMETHOD( const char *,
Type) (
        LXtObjectID			 self);

        LXxMETHOD( unsigned,
Compare) (
        LXtObjectID			 self,
        LXtObjectID			 other);

        LXxMETHOD( LxResult,
Convert) (
        LXtObjectID			 self,
        LXtObjectID			 other);

        LXxMETHOD( LxResult,
Identifier) (
        LXtObjectID			 self,
        const char		       **identifier);
} ILxStackFilter;

typedef struct vt_ILxStackFilter1 {
        ILxUnknown	 iunk;
        LXxMETHOD( const char *,
Type) (
        LXtObjectID			 self);

        LXxMETHOD( unsigned,
Compare) (
        LXtObjectID			 self,
        LXtObjectID			 other);

        LXxMETHOD( LxResult,
Convert) (
        LXtObjectID			 self,
        LXtObjectID			 other);
} ILxStackFilter1;

/*
 * Items stored in the cache are simple COM objects with a single method - the Size method.
 * Size is provided by the client so that the cache system may effectively manage memory
 * since it has no knowledge of the data itself.
 * - Size
 * The Size method is used to allow the cache system to query the CacheData object to determine
 * its size for memory managemnt purposes and only memory management purposes. Calling this function does
 * no allocation or anything other than reporting how much memory this object uses.
 */
typedef struct vt_ILxCacheData {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned int,
Size) (
        LXtObjectID			 self);
} ILxCacheData;

/*
 * The Cache Service provides methods for modifying and accessing named caches.
 *  
 * - Register
 * Clients are added to the cache by simply registering their name. Success means
 * the new cache has been created and initialized. Failure means the named cache
 * already exists.
 * - Release
 * Releases all of the data objects stored in the named cache, and deletes the
 * named cache.
 * - GetData
 * Returns a COM object for the data stored in the named cache, for the provided
 * key.
 * - SetData
 * Sets the COM object stored in a named cache for a specific key.
 * 
 * - PurgeData
 * Releases all of the data in the named cache.
 * 
 * 
 * 
 * 
 * 
 * 
 */
typedef struct vt_ILxCacheService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
Register) (
        LXtObjectID			 self,
        const char			*name);
        LXxMETHOD( void,
Release) (
        LXtObjectID			 self,
        const char			*name);
        LXxMETHOD( LxResult,
GetData) (
        LXtObjectID			 self,
        const char			*name,
        unsigned int			 key,
        void				**ppvObj);
        LXxMETHOD( LxResult,
SetData) (
        LXtObjectID			 self,
        const char			*name,
        unsigned int			 key,
        LXtObjectID			 data);
        LXxMETHOD( void,
PurgeData) (
        LXtObjectID			 self,
        const char			*name);
} ILxCacheService;

/*
 * Evaluation stacks have a type defined as a name:
 */

        #define LXsSTACK_IMAGE		 "imageStack"
        #define LXsSTACK_MESH		 "meshStack"
        #define LXsSTACK_SHADER		 "shaderStack"
        #define LXsSTACK_TEXTURE	 "textureStack"
        #define LXsSTACK_TXTRLOC	 "txtrlocStack"
        #define LXsSTACK_GRADIENT	 "gradientStack"
        #define LXsSTACK_PARTICLE	 "particleStack"


        #define LXu_EVALUATIONSTACK	"47F3BF05-B64A-49D9-A2C1-08B0D36AB787"
        // [local]  ILxEvaluationStack
        // [python] ILxEvaluationStack:Branch	obj EvaluationStack


        #define LXiSTACK_DIFFERENT	 0
        #define LXiSTACK_COMPATIBLE	 1
        #define LXiSTACK_IDENTICAL	 2

        #define LXsCACHE_EVALSTACK	"evalstack"

        #define LXu_STACKFILTER		"D1A07939-DB83-4869-9427-A78D134DA575"
        // [local]   ILxStackFilter
        // [export]  ILxStackFilter filt
        // [default] ILxStackFilter:Compare = LXiSTACK_DIFFERENT


        #define LXu_STACKFILTER1	"B79CF5D3-C630-401B-82A5-AD866BC05B6F"


        #define LXu_CACHEDATA		"7561D111-72BD-4C0C-9E2D-9268A0EC30C2"

        // [local]   ILxCacheData
        // [export]  ILxCacheData cache


        #define LXu_CACHESERVICE	 "6BB353D3-179A-477A-AC23-946DECB45A37"

#endif
