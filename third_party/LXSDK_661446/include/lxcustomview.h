/*
 * LX customview module
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
#ifndef LX_customview_H
#define LX_customview_H

typedef struct vt_ILxCustomPane ** ILxCustomPaneID;
typedef struct vt_ILxCustomView ** ILxCustomViewID;

#include <lxserver.h>
#include <lxvalue.h>

/*
 * This interace defines a CustomView client, which is able to use Python calls (or whatever) to
 * populate a Custom-based interface
 */

      typedef void*    LXtPaneHandleID;



/*
 * Returns the parent window handle for the custom pane, which can be used to parent any user generated
 * UI. In Python this will be returned as an int representing a pointer, and will need to be converted into a proper
 * PyObject.
 * 
 * Returns the unique identifier for the instance of the CustomPane. This is useful for storing state for the particular
 * instance of the pane in the config, for example.
 */
typedef struct vt_ILxCustomPane {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetParent) (
        LXtObjectID		 self,
        LXtPaneHandleID		*handle );
        LXxMETHOD( LxResult,
GetIdentifier) (
        LXtObjectID		 self,
        const char**		 ident );
} ILxCustomPane;

/*
 * - TYPE
 * This tag consists of four space-delimited strings:
 * - The class of the viewport, mostly for organizational purposes.  Options include:
 *    vp3dEdit, vptoolbars, vpproperties, vpdataLists, vpinfo, vpeditors, vputility, and vpapplication.
 * - Exactly four characters representing the viewport's type as an LXtID4.
 * - An internal string representing the viewport's type as a name.
 * - A message table lookup in the form of "@table@message@"
 * For example:  "vpapplication MYVP myViewportTypeName @myViewportTypeTable@myViewportTypeUsername@"
 * - EMBEDABILITY
 * Determines how the viewport can be embedded into a Form View.  Thre are three options:
 * - "normal", which is the default mode if this tag isn't set, indicates that the viewport doesn't
 *   specifically support embedding.  These can still be embedded via viewport presets, but they may
 *   not display properly.
 * - "embedAware", meaning that the viewport knows how to handle embedding.
 * - "embedOnly", meaning the viewport can only be embedded and cannot be used in normal layouts.
 * 
 * - OPTIONS_FORM
 * A string representing the hash of a form to display when the user clicks the gear widget for
 * the viewport.
 * 
 * This is called to tell the server to set up as part of the widget with the name provided.
 * 
 * 
 * This is called to clean up the widget just before the view is torn down.
 * 
 * These methods are called to load or save any per-instance state for the pane provided.
 */
typedef struct vt_ILxCustomView {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Init) (
        LXtObjectID		 self,
        LXtObjectID		 pane );
        LXxMETHOD(  LxResult,
Cleanup) (
        LXtObjectID		self,
        LXtObjectID		pane);
        LXxMETHOD(  LxResult,
StoreState) (
        LXtObjectID		 self,
        LXtObjectID		 pane );

        LXxMETHOD(  LxResult,
RestoreState) (
        LXtObjectID		 self,
        LXtObjectID		 pane );
} ILxCustomView;

/*
 * This interface is what is passed to the plugin and used to obtain the parent's pointer. Could be extended to
 * return other useful bits of information, but at the moment just contains the window handle to parent with
 */

        #define LXu_CUSTOMPANE			"7412C685-3ED9-4622-915F-253105012BC4"
        #define LXa_CUSTOMPANE			"custompane"
        //[local] ILxCustomPane



        #define LXu_CUSTOMVIEW			"b427f640-821a-48ee-b7ec-f4aafe799695"
        #define LXa_CUSTOMVIEW			"customview"
        //[export] ILxCustomView customview
        //[local]  ILxCustomView
        //[python] type LXtPaneHandleID		id

/*
 * Servers are expected to expose tags that define their viewport type.  These allow them to show up as
 * first-class viewports.  If the TYPE tag is not present, then they can still be instanced from a Custom
 * Viewport view's viewport options.
 */

        #define LXsCUSTOMVIEW_TYPE		"CustomViewType"
        #define LXsCUSTOMVIEW_EMBEDABILITY	"CustomViewEmbedability"
        #define LXsCUSTOMVIEW_OPTIONS_FORM	"CustomViewOptionsForm"

#endif
