/*
 * LX itemui module
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
#ifndef LX_itemui_H
#define LX_itemui_H

typedef struct vt_ILxLocatorDest ** ILxLocatorDestID;
typedef struct vt_ILxMeshOpDest ** ILxMeshOpDestID;
typedef struct vt_ILxShaderDest ** ILxShaderDestID;
typedef struct vt_ILxMeshDest ** ILxMeshDestID;
typedef struct vt_ILxChannelDest ** ILxChannelDestID;
typedef struct vt_ILxChannelDropPreview ** ILxChannelDropPreviewID;
typedef struct vt_ILxItemTypeDest ** ILxItemTypeDestID;

#include <lxcom.h>
#include <lxvalue.h>



/*
 * The locator item that was dropped on can be obtained with this function. Note that the
 * item may be NULL if the drop was performed on a non-locator item or not on an item.
 */
typedef struct vt_ILxLocatorDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Item) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( int,
Location) (
        LXtObjectID		 self);
} ILxLocatorDest;

/*
 * Data from MeshOpDest object can be obtained using these interfaces.
 */
typedef struct vt_ILxMeshOpDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Item) (
        LXtObjectID	  self,
        void		**ppvObj);

        LXxMETHOD( LxResult,
ItemDeformer) (
        LXtObjectID	  self,
        void		**ppvObj);

        LXxMETHOD( LxResult,
ItemHG) (
        LXtObjectID	  self,
        void		**itemHG);

        LXxMETHOD( const char*,
Graph) (
        LXtObjectID	 self);

        LXxMETHOD( int,
Location) (
        LXtObjectID	 self);
} ILxMeshOpDest;

/*
 * Data from ShaderDest object can be obtained using these interfaces.
 */
typedef struct vt_ILxShaderDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Item) (
        LXtObjectID	  self,
        void		**ppvObj);

        LXxMETHOD( int,
Type) (
        LXtObjectID	 self);

        LXxMETHOD( int,
Location) (
        LXtObjectID	 self);
} ILxShaderDest;

/*
 * The mesh item that was dropped on can be obtained with this function.
 * 
 * 
 * The world position of the hit location can be obtained with this function.
 * 
 * The surface normal of the hit location in world space can be obtained with
 * this function.
 */
typedef struct vt_ILxMeshDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Item) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
HitPosition) (
        LXtObjectID		 self,
        LXtVector		 pos);
        LXxMETHOD( LxResult,
HitNormal) (
        LXtObjectID		 self,
        LXtVector		 nrm);
} ILxMeshDest;

/*
 * The channel that was dropped on can be obtained with this function.  The returned
 * object has the ILxValue and ILxItemChannel interfaces,
 */
typedef struct vt_ILxChannelDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Channel) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( int,
Location) (
        LXtObjectID		 self);
} ILxChannelDest;

/*
 * The only method simply draws the area under the mouse to indicate that it is
 * marked for the drop.  Exactly how it is marked is up to the destination.
 */
typedef struct vt_ILxChannelDropPreview {
        ILxUnknown	 iunk;
        LXxMETHOD( int,
MarkChannel) (
        LXtObjectID		 self);
} ILxChannelDropPreview;

/*
 * The item that was dropped on can be obtained with this function. Note that the
 * item may be NULL.
 */
typedef struct vt_ILxItemTypeDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Item) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( int,
Location) (
        LXtObjectID		 self);
} ILxItemTypeDest;


        #define LXu_LOCATORDEST		"451EE72D-640C-43E4-AE1A-153684133C65"
        #define LXa_LOCATORDEST		"locatorDestination"
        // [local]  ILxLocatorDest
        // [export] ILxLocatorDest locd
        // [python] ILxLocatorDest:Item		obj Item


        #define LXu_MESHOPDEST		"451EE72D-640C-43E4-AE1A-153684133C42"
        #define LXa_MESHOPDEST		"meshOpDestination"
        // [local]  ILxMeshOpDest
        // [export] ILxMeshOpDest locd
        // [python] ILxMeshOpDest:Item		obj Item
        // [python] ILxMeshOpDest:ItemDeformer	obj Item


        #define LXu_SHADERDEST		"b346d569-c841-46c8-b501-256571212666"
        #define LXa_SHADERDEST		"ShaderDestination"
        //[local]  ILxShaderDest
        //[export] ILxShaderDest locd


        #define LXu_MESHDEST		"DD13F0F7-9BA1-42EB-B36A-653B322FD520"
        #define LXa_MESHDEST		"meshDestination"
        // [local]  ILxMeshDest
        // [export] ILxMeshDest meshd
        // [python] ILxMeshDest:Item	obj Item

/*
 * 
 * Channel destinations are used the Channel List and other locations that represent
 * a channel in an item.
 * 
 */

        #define LXu_CHANNELDEST		"0C84BE94-9B18-42F5-B374-48C5CD278D55"
        #define LXa_CHANNELDEST		"channelDestination"
        // [local]  ILxChannelDest
        // [export] ILxChannelDest chand
        // [python] ILxChannelDest:Channel	obj Value

/*
 * The location is either before, on or after, and is mostly relevant to trees
 * like the Channel List.  Often drop servers will want to use "on", unless they're
 * inserting or re-ordering entries.  Deadspace is not likely to be used here, but
 * is included for completeness, and represents a drop in a tree where there isn't
 * anything.
 */

        #define LXiITEMDESTLOC_BEFORE		 0
        #define LXiITEMDESTLOC_ON		 1
        #define LXiITEMDESTLOC_AFTER		 2

        #define LXiITEMDESTLOC_DEADSPACE	-1

/*
 * Destinations representing channels may expose a channel drop preview interface.
 * This is usually used to highlight the control, row or view that represents the
 * channel, to indicate that the drop is valid there.
 * 
 */

        #define LXu_CHANNELDROPPREVIEW	"41fe952b-dd79-4fe7-b6e1-3dae47cee396"
        #define LXa_CHANNELDROPPREVIEW	"channeldroppreview"
        // [local]  ILxChannelDropPreview
        // [export] ILxChannelDropPreview chandp

/*
 * The ttem type destination is for drops on items themselves.
 * 
 */

        #define LXu_ITEMTYPEDEST	"F088D1C9-78D9-4F73-A906-9BD7EDA0B47D"
        #define LXa_ITEMTYPEDEST	"itemtypeDestination"
        // [local]  ILxItemTypeDest
        // [export] ILxItemTypeDest ityped
        // [python] ILxItemTypeDest:Item	obj Item

        #define LXsITEMTYPEPRESET_EXTENSION	".itemtype"
        #define LXsITEMTYPEFORMPRESET_EXTENSION	".itemtypeformpreset"

/*
 * The location is either before, on or after, and is mostly relevant to trees
 * like the Item List.  Often drop servers will want to use "on", unless they're
 * inserting or re-ordering entries.  Deadspace is not likely to be used here, but
 * is included for completeness, and represents a drop in a tree where there isn't
 * anything.
 */

        #define LXiCHANDESTLOC_BEFORE		 0
        #define LXiCHANDESTLOC_ON		 1
        #define LXiCHANDESTLOC_AFTER		 2

        #define LXiCHANDESTLOC_DEADSPACE	-1


        #define LXiTAG_EXPORT_PREFIX		LXxID4('E','P','F','X')
        #define LXiTAG_EXPORT_SUFFIX		LXxID4('E','S','F','X')

#endif
