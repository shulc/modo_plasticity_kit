/*
 * LX formsys module
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
#ifndef LX_formsys_H
#define LX_formsys_H

typedef struct vt_ILxFormEntryDest ** ILxFormEntryDestID;
typedef struct vt_ILxFormEntryDropPreview ** ILxFormEntryDropPreviewID;
typedef struct vt_ILxFormDeleteEntryDest ** ILxFormDeleteEntryDestID;


/*
 * The hash of form containing the control that was dropped on is returned by
 * this method.  It is important to note that in some cases this may be NULL.
 * This returns the hash of the control under the mouse, or the closest one that
 * can be reasonably dropped on.  For example, if the control is synthetic, then
 * the drop location will be between the the control that defined the Form Command
 * List and the one following it.
 * Note that since some controls can be represented by forms (popover forms, popup
 * forms, etc), the control hash may be a form hash.
 * 
 * 
 */
typedef struct vt_ILxFormEntryDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
FormHash) (
        LXtObjectID		  self,
        const char		**hash);
        LXxMETHOD( LxResult,
ControlHash) (
        LXtObjectID		  self,
        const char		**hash);
        LXxMETHOD( LxResult,
SyntheticIndex) (
        LXtObjectID		  self,
        int			 *index);
        LXxMETHOD( LxResult,
Position) (
        LXtObjectID		  self,
        int			 *pos);
} ILxFormEntryDest;

typedef struct vt_ILxFormEntryDropPreview {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
MarkControl) (
        LXtObjectID		  self,
        const char		 *hash,
        int			  syntheticIndex,
        int			  pos);
} ILxFormEntryDropPreview;

/*
 * We don't really need a method, but the interface requires it, so we provide a
 * way to delete an entry (control or sheet) given its hash.
 */
typedef struct vt_ILxFormDeleteEntryDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Delete) (
        LXtObjectID		  self,
        const char		 *hash);
} ILxFormDeleteEntryDest;

/*
 * Dropping into a Form View exposes an ILxFormEntryDest object describing what is
 * under the mouse.  Synthetics are also supported in certain contexts.
 */

        #define LXu_FORMENTRYDEST	"d8c44d68-ba77-4193-942a-d59ee115d99f"
        #define LXa_FORMENTRYDEST	"formdropdest"
        //[local]  ILxFormEntryDest

/*
 * If the control is a synthetic, then this returns the index of the synthetic.
 * It returns NOTAVAILABLE if the control isn't synthetic.
 * There are certain kinds of synthetics, which can be tested with these macros.
 * If IS_INDEX() is true, then the value can be used directly as an index into
 * the source's synthetic child list.  The other cases represent specific special
 * controls, like subtext.
 */

        #define LXIFORMDROPSYNTH_NONE		(0xFFFFFFFF)		// Not synthetic

        #define LXIFORMDROPSYNTH_SUBTEXT	(-1)			// Subtext

        #define LXxFORMDROPSYNTH_IS_SUBTEXT(i)		((i == LXIFORMDROPSYNTH_SUBTEXT)     ? LXe_TRUE : LXe_FALSE)
        #define LXxFROMDROPSYNTH_IS_INDEX(i)		((i >= 0) ? LXe_TRUE : LXe_FALSE)

/*
 * This returns the position of the drop within the control as a combination of
 * the following defines.
 *   These defines match the COMPDROPPOS defines in comp.qq; we just give them
 *   SDK-friendly names here.
 */

        #define LXmFORMDROPPOS_EDGE		0x0000000F
        #define LXmFORMDROPPOS_ON		0x000000F0

        #define LXfFORMDROPPOS_NONE		0

        // The edges themselves
        #define LXfFORMDROPPOS_ON		0x00000001
        #define LXfFORMDROPPOS_LEFT		0x00000002
        #define LXfFORMDROPPOS_RIGHT		0x00000003
        #define LXfFORMDROPPOS_TOP		0x00000004
        #define LXfFORMDROPPOS_BOTTOM		0x00000005

        // These are only used if the edge is LXfFORMDROPPOS_ON
        #define LXfFORMDROPPOS_ON_ANY		0x00000000
        #define LXfFORMDROPPOS_ON_LABEL		0x00000010
        #define LXfFORMDROPPOS_ON_HOT		0x00000020

        #define LXxFORMDROPPOS_EDGE(x)		(LXmFORMDROPPOS_EDGE & (x))
        #define LXxFORMDROPPOS_ON(x)		(LXmFORMDROPPOS_ON   & (x))

/*
 * The preview interface allows the drop point to be marked within the pane.  
 */

        #define LXu_FORMENTRYDROPPREVIEW	"43908515-dd63-4b36-a8ca-5699d018825d"
        #define LXa_FORMENTRYDROPPREVIEW	"formentrydroppreview"
        //[local]  ILxFormEntryDropPreview

/*
 * This sets the hash of the control (which may be a form, for controls that are built
 * from forms) that the marker should be associated with, as well as the position 
 * relative to the control itself.  The EXTENT defines can be combined with the
 * position flag to span the entire pane instead of just the bounds of the control.
 * The syntheticIndex argument is used only when the hash resolves to a
 *   Also copied from the  COMPDROPPOS defines in comp.qq and given SDK-friendly names.
 * 
 */

        #define LXmFORMDROPPOS_EXTENT		 0x00000F00

        #define LXfFORMDROPPOS_EXTENT_COMPONENT  0x00000000
        #define LXfFORMDROPPOS_EXTENT_PANE	 0x00000100

        #define LXxFORMDROPPOS_EXTENT(x)	 ((x) & LXfFORMDROPPOS_EXTENT)

/*
 * This very simple interface exists simply to indicate that the drop is in a place
 * that can support deleting form entries.
 */

        #define LXu_FORMDELETEENTRYDEST	"a70bedf3-bd43-40c9-9e77-a7632e0f35ed"
        #define LXa_FORMDELETEENTRYDEST	"formdeleteentrydest"
        //[local]  ILxFormDeleteEntryDest

#endif
