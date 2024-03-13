/*
 * LX com module
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
#ifndef LX_com_H
#define LX_com_H
/*
 * An object is a pointer.  The first element of the pointer is the vTable, so an
 * object of type IUnknown (all COM objects) is a pointer to a pointer to the
 * IUnknown vTable.
 */

        typedef void *			 LXtObjectID;
        typedef struct vt_ILxUnknown **	 ILxUnknownID;
    // See Also:  LXtObjectID ILxUnknownID


typedef struct vt_ILxObject ** ILxObjectID;
typedef struct vt_ILxGUIDService ** ILxGUIDServiceID;

#include <lxresult.h>

/*
 * An ID code is a 32-bit word, with values constructed by passing four
 * characters to the macro below.
 */

        typedef unsigned int		 LXtID4;

/*
 * This is the IUnknown interface.  In COM terminology, an "interface" describes
 * the layout
 * of a table containing method function vectors, or "vTable."  Three functions
 * at the start of all COM object vTables control polymorphism and reference
 * counting.  The LXxMETHOD macro allows us to control the function declaration
 * across different systems or compilers, although it is just the default for now.
 */

        #define LXxMETHOD(rv,fn)	rv (*fn)
        struct st_LXtGUID;
        typedef struct vt_ILxUnknown {
                        LXxMETHOD (LxResult,
                QueryInterface) (
                        LXtObjectID		 self,
                        const struct st_LXtGUID	*iid,
                        void		       **ppvObj);

                        LXxMETHOD (unsigned int,
                AddRef) (
                        LXtObjectID		 self);

                        LXxMETHOD (unsigned int,
                Release) (
                        LXtObjectID		 self);
        } ILxUnknown;


/*
 * GUIDs are structures containing 128 bits of pure noise, hopefully unique
 * throughout all time and space.  They are used to identify interfaces and
 * object classes.
 */
typedef struct st_LXtGUID {
        unsigned int		 x4;
        unsigned short		 x2[2];
        unsigned char		 x1[8];
    // See Also:  LXtGUID
} LXtGUID;


/*
 * Returns the identifier of the COM object.
 * Returns the number of interfaces implemented by the object.
 * 
 * Returns the GUID of an interface specified by index.
 * 
 * Attach a visitor to the lifetime of the COM object. When the reference count
 * of the COM object reaches zero, and the object is destroyed, the Evaluate
 * method on the visitor will be called.
 * 
 * Detaches the visitor from tracking the lifetime of the COM object.
 */
typedef struct vt_ILxObject {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Identifier) (
        LXtObjectID		 self,
        const char		**id);
        LXxMETHOD( LxResult,
InterfaceCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD( LxResult,
InterfaceByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        const LXtGUID		**guid);
        LXxMETHOD( void,
AddObserver) (
        LXtObjectID		 self,
        LXtObjectID		 visitor);
        LXxMETHOD( void,
RemoveObserver) (
        LXtObjectID		 self,
        LXtObjectID		 visitor);
} ILxObject;

/*
 * A service interface for converting between GUID strings and LXtGUID structs
 * is exported as part of the application global.
 * - Translate
 * takes a GUID string (either the LXu_* long format or an LXa_* alias) and
 * returns a pointer to an LXtGUID.  The returned pointer is non-volatile and
 * can be stored.
 * - GetName
 * takes a pointer to an LXtGUID struct and returns the name for the GUID.  This
 * will be the short alias for the GUID if it exists.
 * 
 * - Compare
 * takes two LXtGUID pointers and returns a ranking metric for sorting them.
 * The result is similar to strcmp().
 * 
 * - Fixed
 * takes a GUID pointer that may be volatile and returns a non-volatile version
 * from the global pool.
 * 
 * - Class
 * takes a GUID pointer and returns the class GUID, if any.
 * 
 * - ClassName
 * takes a GUID pointer and returns the name for the class, if any.
 * 
 */
typedef struct vt_ILxGUIDService {
        ILxUnknown	 iunk;
        LXxMETHOD( const LXtGUID *,
Translate) (
        LXtObjectID		 self,
        const char		*guidStr);

        LXxMETHOD( const char *,
GetName) (
        LXtObjectID		 self,
        const LXtGUID		*guid);

        LXxMETHOD( int,
Compare) (
        LXtObjectID		 self,
        const LXtGUID		*guid1,
        const LXtGUID		*guid2);

        LXxMETHOD( const LXtGUID *,
Fixed) (
        LXtObjectID		 self,
        const LXtGUID		*guid);

        LXxMETHOD( const LXtGUID *,
Class) (
        LXtObjectID		 self,
        const LXtGUID		*guid);

        LXxMETHOD( const char *,
ClassName) (
        LXtObjectID		 self,
        const LXtGUID		*guid);
} ILxGUIDService;

/*
 * Since using a GUID directly is a bit of a pain, we define them using
 * strings in what Microsoft calls "registry format".  This is the GUID for IUnknown.
 */

        #define LXu_UNKNOWN	"00000000-0000-0000-0000-0000000000C4"


        #define LXxID4(a,b,c,d)		((a) << 24 | (b) << 16 | (c) << 8 | (d))

/*
 * COM objects are relative black boxes; They are passed around as ILxUnknown
 * objects, and only become more descriptive and useful when queried for an
 * interface. Often it can be helpful for clients to be able to perform basic
 * interaction with the COM object, without knowing which interfaces it implements.
 * The ILxObject interface is implemented by all COM objects. It provides methods
 * for querying the object name, as well as enumerating over interfaces implemented
 * by the COM interface.
 */

        #define	LXu_OBJECT	"222986AB-FA71-4188-BFB3-EEB3D503AE6F"
        #define LXa_OBJECT	"object"
        // [local] ILxObject
        // [export] ILxObject	obj


        #define LXu_GUIDSERVICE		"B11826F1-A6BC-48B4-909B-5F6D01938327"
        #define LXa_GUIDSERVICE		"guidservice"

/*
 * Crazy-ass Mac code needed to define LXx_OVERRIDE, which doesn't need to be
 * part of the public docs.
 */

#if defined(_MSC_VER)
        // QWEB_MACRO_BEGIN - SDK_dec: override keyword
        #define LXx_OVERRIDE override
        // QWEB_MACRO_END - SDK_dec: override keyword
#else
        #ifndef __has_feature
                #define __has_feature(x) 0
        #endif

        #if __has_feature(cxx_override_control)
                // QWEB_MACRO_BEGIN - SDK_dec: override keyword
        #define LXx_OVERRIDE override
                // QWEB_MACRO_END - SDK_dec: override keyword
        #else
                #define LXx_OVERRIDE
        #endif
#endif

#endif
