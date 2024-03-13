/*
 * LX tree module
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
#ifndef LX_tree_H
#define LX_tree_H

typedef struct vt_ILxTree ** ILxTreeID;
typedef struct vt_ILxTreeListener ** ILxTreeListenerID;
typedef struct vt_ILxTreeListener1 ** ILxTreeListener1ID;


/*
 * The tree interface represents a single tier of a tree, which is a list
 * of siblings, and a currently selected member of that list.
 * Spawn() creates a new tree object referencing either the same part or
 * another part of the tree. Clients can copy this tier, or they can get
 * the tier containing the parent, or the sub-items of the current child.
 * 
 * The tree object itself can be walked around the tree.
 * 
 * This returns LXe_TRUE if this tree has no parent. If so, calling ToParent()
 * will fail.
 * 
 * This returns LXe_TRUE if the current element has no children. It's equivalent
 * to calling ToChild() and testing the count for zero.
 * 
 * This returns the number of elements in this tier. This can be zero
 * for elements with no children.
 * 
 * The tree object maintains a current element, whose properties can be
 * accessed through an ILxAttributes interface on the tree.
 * 
 */
typedef struct vt_ILxTree {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Spawn) (
        LXtObjectID		  self,
        unsigned		  mode,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ToParent) (
        LXtObjectID	 self);

        LXxMETHOD(  LxResult,
ToChild) (
        LXtObjectID	 self);

        LXxMETHOD(  LxResult,
ToRoot) (
        LXtObjectID	 self);
        LXxMETHOD(  LxResult,
IsRoot) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
ChildIsLeaf) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        unsigned		*count);
        LXxMETHOD(  LxResult,
Current) (
        LXtObjectID		 self,
        unsigned		*index);

        LXxMETHOD(  LxResult,
SetCurrent) (
        LXtObjectID		 self,
        unsigned		 index);
        LXxMETHOD( LxResult,
ItemState) (
        LXtObjectID		 self,
        const char		*guid,
        int			*state);

        LXxMETHOD( LxResult,
SetItemState) (
        LXtObjectID		 self,
        const char		*guid,
        int			 state);
} ILxTree;

/*
 * NewAttributes just refreshes the contents of the existing tree cells,
 * asking for new values to display.
 * 
 * NewShape rebuilds the entire tree, and is used when the hierarchy or number
 * visible of rows has changed in any way, including when folding or unfolding
 * an entry to hide/show its children.
 * 
 * This indicates that the size of the space reserved for thumbnails has changed,
 * and that new thumbnails hsould be obtained.
 * 
 * If the tree is using thumbnails with identifier strings, these allow it to
 * purge specific thumbnails or all thubnails from the cache when it wants to
 * provide new ones.  Thumbnails are identified by the stirng assigned to them
 * when they were originally returned.
 * 
 * This toggles the visibility of the smaller description text in the tree.
 */
typedef struct vt_ILxTreeListener {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
NewAttributes) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
NewShape) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
NewSpaceForThumbnails) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
ClearCachedThumbnail) (
        LXtObjectID		 self,
        const char		*ident);

        LXxMETHOD(  LxResult,
ClearAllCachedThumbnails) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
NewShowDescriptionText) (
        LXtObjectID		 self);
} ILxTreeListener;

typedef struct vt_ILxTreeListener1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
NewAttributes) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
NewShape) (
        LXtObjectID		 self);
} ILxTreeListener1;


        #define LXiTREE_CLONE	 0
        #define LXiTREE_PARENT	 1
        #define LXiTREE_CHILD	 2
        #define LXiTREE_ROOT	 3

/*
 * The state flags provide hints and information about the element.  Many of the flags
 * are only returned from the tree, while others are both returned and passed to the tree.
 * the tree is expected to store certain flags itself, notably, ones that match the
 * SETFLAGS state (these are the only flags that will be passed to ItemSetState()).
 * You should return those flags from ItemState() by OR'ing them into whatever other
 * get-only flags you are returning.
 * The following flags are defined.  
 * - ATTRIB
 * Item is displayed as an attribute (under the +/- expansion widget) instead of as a
 * child.
 * 
 * - EXPANDED
 * - ATTREXP
 * The children or attributes of this item are expanded and visible.  The tree is
 * expected to manage this state itself, storing it in SetItemState() and returning
 * it from ItemState().
 * 
 * - HIDDEN
 * The item is not displayed at all.
 * 
 * The filter flags are passed to SetItemState() and returned by ItemState().
 * Generally you just need to store and return them, and not directly set them
 * yourself.
 * 
 * - FILTERED
 * Indicates if the item was hidden because it was filtered out by the tree.
 * 
 * - FILTER_SKIP
 * This item and its children aren't affected by filtering, and are always visible.
 * 
 * - FILTER_EXPANDED
 * - FILTER_ATTREXP
 * This is a parent item was expanded due to filtering so that the child item is
 * visible.  This should be stored in SetItemTest() and returned from ItemState().
 * 
 * - FILTER_EXPANDED_BY_USER
 * - FILTER_ATTREXP_BY_USER
 * This is a parent item that was expadned by the user while the tree was filtered.
 * This state is only valid while the tree is filtered, and is not used once filtering
 * is turned off.
 * 
 */

        #define LXfTREEITEM_ATTRIB			 0x00000001
        #define LXfTREEITEM_EXPANDED			 0x00000002
        #define LXfTREEITEM_ATTREXP			 0x00000004

        #define LXfTREEITEM_HIDDEN			 0x00000008

        #define LXfTREEITEM_FILTERED			 0x00000040
        #define LXfTREEITEM_FILTER_SKIP			 0x00000080
        #define LXfTREEITEM_FILTER_EXPANDED		 0x00000100
        #define LXfTREEITEM_FILTER_ATTREXP		 0x00000200
        #define LXfTREEITEM_FILTER_EXPANDED_BY_USER	 0x00000400
        #define LXfTREEITEM_FILTER_ATTREXP_BY_USER	 0x00000800

        #define LXfTREEITEM_CLIENT			 0xFF000000											// Reserved for client use

        #define LXfTREEITEM_EXPFLAGS			 (LXfTREEITEM_EXPANDED | LXfTREEITEM_ATTREXP)							// Expansion flags
        #define LXfTREEITEM_FILTER_EXPFLAGS		 (LXfTREEITEM_FILTER_EXPANDED | LXfTREEITEM_FILTER_ATTREXP)					// Expanded due to filtering
        #define LXfTREEITEM_FILTER_EXPFLAGS_BY_USER	 (LXfTREEITEM_FILTER_EXPANDED_BY_USER | LXfTREEITEM_FILTER_ATTREXP_BY_USER)			// Expanded by user during filtering
        #define LXfTREEITEM_FILTER_FLAGS		 (LXfTREEITEM_FILTER_EXPFLAGS | LXfTREEITEM_FILTER_EXPFLAGS_BY_USER | LXfTREEITEM_FILTERED)	// All flags used for filtering
        #define LXfTREEITEM_SETFLAGS			 (LXfTREEITEM_EXPFLAGS | LXfTREEITEM_FILTER_FLAGS)						// All flags that may be passed to SETFLAGS

/*
 * Row colors are pre-defined flags that can be OR'ed into the state flags returned by
 * ItemState().
 */

        #define LXmTREEITEM_ROWCOLOR_MASK		 0x001F0000		// The bits used for a colors
        #define LXfTREEITEM_ROWCOLOR_NONE		 0x00000000		// No color
        #define LXfTREEITEM_ROWCOLOR_RED		 0x00010000
        #define LXfTREEITEM_ROWCOLOR_MAGENTA		 0x00020000
        #define LXfTREEITEM_ROWCOLOR_PINK		 0x00030000
        #define LXfTREEITEM_ROWCOLOR_BROWN		 0x00040000
        #define LXfTREEITEM_ROWCOLOR_ORANGE		 0x00050000
        #define LXfTREEITEM_ROWCOLOR_YELLOW		 0x00060000
        #define LXfTREEITEM_ROWCOLOR_GREEN		 0x00070000
        #define LXfTREEITEM_ROWCOLOR_LIGHT_GREEN	 0x00080000
        #define LXfTREEITEM_ROWCOLOR_CYAN		 0x00090000
        #define LXfTREEITEM_ROWCOLOR_BLUE		 0x000A0000
        #define LXfTREEITEM_ROWCOLOR_LIGHT_BLUE		 0x000B0000
        #define LXfTREEITEM_ROWCOLOR_ULTRAMARINE	 0x000C0000
        #define LXfTREEITEM_ROWCOLOR_PURPLE		 0x000D0000
        #define LXfTREEITEM_ROWCOLOR_LIGHT_PURPLE	 0x000E0000
        #define LXfTREEITEM_ROWCOLOR_DARK_GREY		 0x000F0000
        #define LXfTREEITEM_ROWCOLOR_GREY		 0x00100000
        #define LXfTREEITEM_ROWCOLOR_WHITE		 0x00110000


        #define LXu_TREE		"E61F3BA6-B9E8-41B8-8A61-3F78CBC79E98"
        #define LXa_TREE		"tree"
        // [export] ILxTree tree
        // [local]  ILxTree
        // [python] ILxTree:Spawn	obj Tree
        // [python] ILxTree:IsRoot	bool
        // [python] ILxTree:ChildIsLeaf	bool

/*
 * Tree clients can attach a listener interface (using the tree's
 * ListenerPort) which can be informed of changes to the tree, either
 * just attribute values or the structure of the tree.
 */

        #define LXu_TREELISTENER	"200fe1a6-c764-42f7-917f-044a0f58e007"
        // [export] ILxTreeListener tlis
        // [local]  ILxTreeListener

/*
 * Legacy listener with only attribute and shape support.
 */

        #define LXu_TREELISTENER1	"EB38EE07-0E35-455F-A570-F4AF313494FD"
        // [export] ILxTreeListener1 tlis
        // [local]  ILxTreeListener1

#endif
