/*
 * LX treeview module
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
#ifndef LX_treeview_H
#define LX_treeview_H

typedef struct vt_ILxTreeView ** ILxTreeViewID;
typedef struct vt_ILxTreeView3 ** ILxTreeView3ID;
typedef struct vt_ILxTreeView2 ** ILxTreeView2ID;
typedef struct vt_ILxTreeView1 ** ILxTreeView1ID;

#include <lxcom.h>
#include <lxtree.h>
#include <lxserver.h>
#include <lxvalue.h>



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
 * the viewport.  If not set, there are no options for the viewport.
 * 
 * 
 * These methods are called to load or save any per-instance state for the pane provided.
 * Such state is commonly stored in the application's config.
 * 
 * 
 * Note that the above flags MUST match the ICTSf_ (comp) and TPSTYLEf_ (panes) flags!
 * 
 * These methods are used for controlling what columns are present in the tree view and some of their
 * properties. ColumnCount() returns the total number of columns.
 * 
 * 
 * This method defines the column and sets its title and width.
 * 'buf' is a simple character buffer of length 'len' that is to be set to the human-readable title displayed
 * in the column header, usually in the form of a "@table@msg" message table lokoup.  Titles support message
 * alternates, where the longest of the available messages that will fit is displayed in the title.  The
 * longest title is also displed in the hide/show column context menu (when you've also set an internal name
 * with ColumnSetInternalName()).  For this reason you should not encode icons in your title, instead specifying
 * them separately via ColumnSetIconResource();
 * 
 * 'columnWidth' returns the width of the column.  Positive numbers define the width in pixels, while negative
 * numbers will set a column's width to its relative fraction of the total remaining space. For example, two
 * columns with widths -2 and -3 would get 2/5th and 3/5th of the width remaining in the pane after the fixed
 * width columns are subtracted. A width of zero behaves the same as -1.
 * 
 * 
 * nexus 10.1 introduces new column defintions that enchance the behavior of trees:
 * - Defining any column icon separately from the title.
 * - Column widths are remembered for you between sessions in the config.
 * - The user can hide and show columns by right clicking in the column header.
 * - The user can drag and drop the column headers to reorder the columns.
 * - Column justification.
 * The internal name is used to store the column properties in the config in a localization-netural
 * manner.  This includes the column width, column position relative to the other columns, and if
 * the column is hidden or visible.
 * 
 * It is very important that you set this for every column, or else you won't get any of those
 * features.
 * 
 * 
 * An optional icon resource name can also be set for the column.  This will be displayed in place
 * of the column's title if the column is too narrow for it to fit.  The icon should be 13x13 pixels.
 * 
 * 
 * The final method of the treeview setup functionality is PrimaryColumnPosition. This allows you to change
 * where in the treeview the primary column (the one with index 0 that contains the nesting) is displayed.
 * 0 leaves it where it is, and other number pushing it that number of columns to the right.
 * 
 * Selection methods. ToPrimary should set the current referenced item to be the primary selection, and
 * IsSelected returns LXe_TRUE or LXe_FALSE to determine whether the current item is selected or not.
 * Select is called when a new primary selection is made (dropping any current selection)first, or when
 * additional selections are added or removed. It is up to the client to maintain the list of selected
 * items.
 * 
 * Batch begin and end events are sent to the Select() method to wrap multiple ADD or REMOVE events,
 * which commonly happens when range selecting by holding shift and clicking on an element.
 * 
 * MAKE_TOPMOST is a request to make the selection type topmost without changing the selection itself.
 * This is most useful when mutliple trees use the same underlying select type but different selection
 * subtypes, and you want to make sure that commands are operating on the correct tree's selection.
 * 
 * 
 * Command cells are a powerful feature for both defining the contents of a cell and for interacting
 * with it.  Since all user interaction with a tree should be done with commands, it makes sense to
 * use the command to define the cell itself.
 * CellCommand() and BatchCommand() are similar, with the former providing a command string unique to
 * that one cell, while the other provides a command that applies to the entire selection.  Often
 * these are the same command, such as "item.visible state:? item:itemIdentHere" for the cell command,
 * where the optional "item" argument is used to taret a specific row of the tree, while the batch
 * command omits the "item" argument as "item.visible state:?" and thus applies to all selected rows.
 * 
 * In both cases the command returned should have an argument makred for query.  CellCommand() will
 * figure out what kind of behaviors are supported by the cell based on the datatype of the argument.
 * Interacting with the cell executes the command with the new value, much like how forms work.
 * 
 * The following datatypes are currently supported for command cells:
 * 
 * - boolean
 * Draw a checkmark in the cell.  Clicking the cell toggles the checkmark.  The user can also click
 * and drag down a column of these checkmarks to toggle multiple rows in a single action.
 * 
 * - numeric (integer, float, etc)
 * This includes all numeric variants (such as percent, distance, etc), and will create a cell with
 * a minislider.  Clicking and dragging in the cell will change the value, and clicking without
 * dragging will open an inline edit field to enter a new value.
 * 
 * - string
 * Draws a string.  Clicking in the cell opens an inline edit field to change the value.
 * 
 * - popups
 * If a string or integer cell defines a popup (either via popup methods or LXtTextValueHints), the
 * cell will be drawn with a popup widget and clicking the cell will open the popup.
 * 
 * - asyncmonitor
 * A special cell type that draws an asynchronous progress monitor.
 * 
 * Since these are commands, the cell values are automatically update when the command's notifier
 * sends a VALUE invalidation.
 * 
 * The value displayed in a cell can be overriden by returning an appropraite string from the
 * ILxAttributes interface.  However, normally you want the value from the command itself to be
 * used, in which case the attributes should return NOTIMPL so that the command's queried value
 * is used instead.
 * 
 * 
 * The ToolTip() methodcan be implemented to populate a tooltip string for the curent cell.
 * 
 * Description text is optional smaller text displayed below the main text in a cell, usually providing
 * secondary information like the path to a file or image resolution.
 * 
 * This should return LXe_TRUE (or NOTIMPL) if the description text should be shown
 * for the entire view, and false to hide it.
 * 
 * This sets if the tree supports icons.  Icons are defined through image resources,
 * and space is resreved for them even if no icon is returned, ensuring that everything
 * lines up nicely.  By convention icons are 13x13, but other sizes can be chosen, and
 * each column can have its own icon metrics.  If iconAsValue is true, the icon will be
 * drawn centered as the entire contents of the cell.
 * 
 * Get the icon by returning a string representing its resource name.  If the icon is
 * larger than the width and height requested, it will simply not be drawn.
 * 
 * This sets if the tree supports thumbnails, reserving space for them and causing
 * the tree to be asked for thumbnails to display.  Note that only one column can
 * have thumbnails at this time.  Setting w/h to 0/0 will effectively turn off
 * thumbnail support.
 * 
 * If space is reserved for a thumbnail, this method is called to return it as an ILxImageID.  The thumbnail
 * is drawn to the immediate left of the cell's contents.
 * Optimally, the thumbnail is already the correct resolution or smaller.  If it is larger, by default it will
 * be synchronously resized to fit, but this is slow and should be avoided if at all possible.
 * 
 * The buf/len pair is used to get an identifier string to identify the thumbnail.  This is only necessariy
 * if you want the tree system to efficiently resize the thumbnail for you.  If this string is empty, the
 * thumbanil will be slowly resized (or not at all, if it's equal to or smaller than requested size).
 * 
 * When the string is not empty, large thumbnails will be asynchronously resized in the background to fit
 * the reserved space.  If a thumbnail with this string already exists in the cache, the ILxImageID returned
 * is ignored and the cached one is used instead. Multiple entries in the tree can use the same thumbnail
 * (by using the same string) if desired.
 * 
 * If you are always returning icons at the requested size or smaller, you do not need to provide an
 * identifier string, as the image can be used directly.
 * 
 * 
 * 
 * 
 * 
 * This is used by trees containing an input map based regions. If the given cell corresponds to a region at
 * this location, the function should return LXe_TRUE. This allows regions to be restricted to specific items,
 * types and/or columns. Selection and command execution will automatically be performed as necessary.
 * 
 * 
 * The following method is entirely optional. Descendant selection highlighting will still work if
 * this is not implemented, but if this IS implemented the treeview will be significantly more
 * responsive. This should return true if the current node or any of it's children is currently
 * selected, or false otherwise.
 * 
 * - SHOW
 * The element matched the filter, and should be shown in the tree.
 * - HIDE
 * The element did not match the filter, and will not be shown in the tree.
 * 
 * - SHOW_IF_CHILDREN_MATCH
 * The element will be shown if it has the SHOW flag, or if any of its children also
 * match the filter.  This allows a parent to be visible if a child matches but the
 * parent itself does not.  This is only true for immediate children; grandchildren
 * will also need to set this flag if their parents should be visible if they are
 * visible. This is usually paired with the HIDE flag.
 * 
 * - SHOW_WITH_ALL_CHILDREN
 * If the element is shown (due to SHOW or SHOW_IF_CHILDREN_MATCH), then its immediate
 * children will be shown as though they matched the filter.  This affects the
 * entire hiearchy from this point down.
 * 
 */
typedef struct vt_ILxTreeView {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
StoreState) (
        LXtObjectID		 self,
        const char		*uid );

        LXxMETHOD(  LxResult,
RestoreState) (
        LXtObjectID		 self,
        const char		*uid );
        LXxMETHOD(  LxResult,
StyleHints) (
        LXtObjectID		 self,
        int			*flags );
        LXxMETHOD( LxResult,
ColumnCount) (
        LXtObjectID		 self,
        unsigned*		 colCount);
        LXxMETHOD( LxResult,
ColumnByIndex) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len,
        int			*columnWidth);
        LXxMETHOD( LxResult,
ColumnInternalName) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len);
        LXxMETHOD( LxResult,
ColumnIconResource) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len);
        LXxMETHOD( LxResult,
ColumnJustification) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        int			*justification);
        LXxMETHOD( LxResult,
PrimaryColumnPosition) (
        LXtObjectID		 self,
        unsigned		*index);
        LXxMETHOD(  LxResult,
ToPrimary) (
        LXtObjectID	self);

        LXxMETHOD(  LxResult,
IsSelected) (
        LXtObjectID	self);

        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID	self,
        unsigned	mode);
        LXxMETHOD( LxResult,
CellCommand) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);

        LXxMETHOD( LxResult,
BatchCommand) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);
        LXxMETHOD( LxResult,
ToolTip) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);
        LXxMETHOD( LxResult,
DescriptionText) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);
        LXxMETHOD( LxResult,
ShowDescriptionText) (
        LXtObjectID	self);
        LXxMETHOD(  LxResult,
ReservedSpaceForIcons) (
        LXtObjectID		  self,
        int			 *columnIndex,
        int			 *width,
        int			 *height,
        int			 *iconAsValue);
        LXxMETHOD( LxResult,
IconResource) (
        LXtObjectID		  self,
        unsigned		  columnIndex,
        int			  width,
        int			  height,
        char			 *buf,
        unsigned		  len);
        LXxMETHOD(  LxResult,
ReservedSpaceForThumbnails) (
        LXtObjectID		  self,
        int			 *columnIndex,
        int			 *width,
        int			 *height);
        LXxMETHOD( LxResult,
Thumbnail) (
        LXtObjectID		  self,
        unsigned		  columnIndex,
        int			  width,
        int			  height,
        void			**ppvObj,
        char			 *buf,
        unsigned		  len);
        LXxMETHOD( LxResult,
BadgeType) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 badgeIndex,
        unsigned		*badgeType);
        LXxMETHOD( LxResult,
BadgeType2) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 badgeIndex,
        unsigned		*badgeType);
        LXxMETHOD( LxResult,
BadgeDetail) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 badgeIndex,
        unsigned		 badgeDetail,
        char			*buf,
        unsigned		 len);
        LXxMETHOD( LxResult,
IsInputRegion) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 regionID);
        LXxMETHOD( LxResult,
SupportedDragDropSourceTypes) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
GetDragDropSourceObject) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        const char		*type,
        void			**ppvObj);

        LXxMETHOD( LxResult,
GetDragDropDestinationObject) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 location,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
IsDescendantSelected) (
        LXtObjectID	self);
        LXxMETHOD(  LxResult,
CanFilter) (
        LXtObjectID	 self);

        LXxMETHOD(  LxResult,
Filter) (
        LXtObjectID	 self,
        int		*flags);
} ILxTreeView;

typedef struct vt_ILxTreeView3 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
StoreState) (
        LXtObjectID		 self,
        const char		*uid );

        LXxMETHOD(  LxResult,
RestoreState) (
        LXtObjectID		 self,
        const char		*uid );

        LXxMETHOD( LxResult,
ColumnCount) (
        LXtObjectID		 self,
        unsigned*		 colCount);

        LXxMETHOD( LxResult,
ColumnByIndex) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len,
        int			*columnWidth);

        LXxMETHOD( LxResult,
ColumnInternalName) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
ColumnIconResource) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
ColumnJustification) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        int			*justification);

        LXxMETHOD( LxResult,
PrimaryColumnPosition) (
        LXtObjectID		 self,
        unsigned		*index);

        LXxMETHOD(  LxResult,
ToPrimary) (
        LXtObjectID	self);

        LXxMETHOD(  LxResult,
IsSelected) (
        LXtObjectID	self);

        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID	self,
        unsigned	mode);

        LXxMETHOD( LxResult,
CellCommand) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);

        LXxMETHOD( LxResult,
BatchCommand) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);

        LXxMETHOD( LxResult,
ToolTip) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);

        LXxMETHOD( LxResult,
BadgeType) (
        LXtObjectID	 self,
        unsigned	 columnIndex,
        unsigned	 badgeIndex,
        unsigned	*badgeType);

        LXxMETHOD( LxResult,
BadgeDetail) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 badgeIndex,
        unsigned		 badgeDetail,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
IsInputRegion) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 regionID);

        LXxMETHOD( LxResult,
SupportedDragDropSourceTypes) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
GetDragDropSourceObject) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        const char		*type,
        void			**ppvObj);

        LXxMETHOD( LxResult,
GetDragDropDestinationObject) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 location,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
IsDescendantSelected) (
        LXtObjectID	self);
} ILxTreeView3;

typedef struct vt_ILxTreeView2 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
StoreState) (
        LXtObjectID		 self,
        const char		*uid );

        LXxMETHOD(  LxResult,
RestoreState) (
        LXtObjectID		 self,
        const char		*uid );

        LXxMETHOD( LxResult,
ColumnCount) (
        LXtObjectID		 self,
        unsigned*		 colCount);

        LXxMETHOD( LxResult,
ColumnByIndex) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len,
        int			*columnWidth);

        LXxMETHOD( LxResult,
ColumnInternalName) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
ColumnIconResource) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
ColumnJustification) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        int			*justification);

        LXxMETHOD( LxResult,
PrimaryColumnPosition) (
        LXtObjectID		 self,
        unsigned		*index);

        LXxMETHOD(  LxResult,
ToPrimary) (
        LXtObjectID	self);

        LXxMETHOD(  LxResult,
IsSelected) (
        LXtObjectID	self);

        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID	self,
        unsigned	mode);

        LXxMETHOD( LxResult,
CellCommand) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);

        LXxMETHOD( LxResult,
BatchCommand) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);

        LXxMETHOD( LxResult,
ToolTip) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);

        LXxMETHOD( LxResult,
BadgeType) (
        LXtObjectID	 self,
        unsigned	 columnIndex,
        unsigned	 badgeIndex,
        unsigned	*badgeType);

        LXxMETHOD( LxResult,
BadgeDetail) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 badgeIndex,
        unsigned		 badgeDetail,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
IsInputRegion) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 regionID);

        LXxMETHOD( LxResult,
SupportedDragDropSourceTypes) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
GetDragDropSourceObject) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        const char		*type,
        void			**ppvObj);

        LXxMETHOD( LxResult,
GetDragDropDestinationObject) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 location,
        void			**ppvObj);
} ILxTreeView2;

typedef struct vt_ILxTreeView1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
StoreState) (
        LXtObjectID		 self,
        const char		*uid );

        LXxMETHOD(  LxResult,
RestoreState) (
        LXtObjectID		 self,
        const char		*uid );

        LXxMETHOD( LxResult,
ColumnCount) (
        LXtObjectID		 self,
        unsigned*		 colCount);

        LXxMETHOD( LxResult,
ColumnByIndex) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len,
        int			*columnWidth);

        LXxMETHOD(  LxResult,
ToPrimary) (
        LXtObjectID	self);

        LXxMETHOD(  LxResult,
IsSelected) (
        LXtObjectID	self);

        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID	self,
        unsigned	mode);

        LXxMETHOD( LxResult,
CellCommand) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);

        LXxMETHOD( LxResult,
BatchCommand) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);

        LXxMETHOD( LxResult,
ToolTip) (
        LXtObjectID	self,
        unsigned	columnIndex,
        char	       *buf,
        unsigned	len);

        LXxMETHOD( LxResult,
BadgeType) (
        LXtObjectID	 self,
        unsigned	 columnIndex,
        unsigned	 badgeIndex,
        unsigned	*badgeType);

        LXxMETHOD( LxResult,
BadgeDetail) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 badgeIndex,
        unsigned		 badgeDetail,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
IsInputRegion) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        unsigned		 regionID);

        LXxMETHOD( LxResult,
SupportedDragDropSourceTypes) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
GetDragDropSourceObject) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        const char		*type,
        void			**ppvObj);

        LXxMETHOD( LxResult,
GetDragDropDestinationObject) (
        LXtObjectID		 self,
        unsigned		 columnIndex,
        void			**ppvObj);
} ILxTreeView1;

/*
 * This interace defines a TreeView client, which is able to use Python calls (or whatever) to
 * set up a TreeView-based interface.
 * Objects with the ILxTreeView interface rely on the ILxTree interface as well.  If both aren't
 * available, no viewport will be defined for that server.
 */

        #define LXu_TREEVIEW			"86e7a5cc-9a4b-4621-9f97-996e6f7f0a62"
        #define LXa_TREEVIEW			"treeview"
        //[export] ILxTreeView treeview
        //[local]  ILxTreeView
        //[python] ILxTreeView:IsSelected				bool
        //[python] ILxTreeView:IsDescendantSelected			bool
        //[python] ILxTreeView:IsInputRegion				bool
        //[python] ILxTreeView:ToPrimary				bool
        //[python] ILxTreeView:IsDescendantSelected			bool
        //[python] ILxTreeView:GetDragDropSourceObject			obj Unknown
        //[python] ILxTreeView:GetDragDropDestinationObject		obj Unknown
        //[python] ILxTreeView:Thumbnail				obj Image
        //[python] ILxTreeView:CanFilter				bool

/*
 * Servers are expected to expose tags that define their viewport type.  These allow them to show up as
 * first-class viewports.  Without these tags, no viewport will be defined for the server.
 */

        #define LXsTREEVIEW_TYPE		"TreeViewType"
        #define LXsTREEVIEW_EMBEDABILITY	"TreeViewEmbedability"
        #define LXsTREEVIEW_OPTIONS_FORM	"TreeViewOptionsForm"

/*
 * This returns some style hints of the tree by returning a combination of flags.
 * - SECTIONS
 * Root-level entries in the tree hierarchy will be drawn as section headers that
 * span all columns.  Clicking anywhere on the section row will act as though its
 * children where hidden/shown.  The label for the section comes from the value
 * of the hierarchy column.
 * - CHILDREN
 * Indicates that the tree may have children.  This simply reserves space for
 * the hide/show (aka "disclosure triangle" widget in the tree.  If you don't
 * have any children, you can save space by omitting this flag.
 * 
 * - ATTRIBUTES
 * Similar to children, this reservces space for the +/- widgets to hide/show
 * attributes of an item.
 * 
 * By default CHILDREN and ATTRIBUTES are set.
 * 
 */

        #define LXfTREEVIEWSTYLE_SECTIONS		0x0001
        #define LXfTREEVIEWSTYLE_CHILDREN		0x0002
        #define LXfTREEVIEWSTYLE_ATTRIBUTES		0x0004

        #define LXfTREEVIEWSTYLE_DEFAULT		(LXfTREEVIEWSTYLE_CHILDREN | LXfTREEVIEWSTYLE_ATTRIBUTES)

/*
 * This changes the justfication of the contents of the column.  The primary column is always left
 * justified, but the other columns can be centered or right justified if desired.
 */

        #define LXiTREEJUST_LEFT		0
        #define LXiTREEJUST_CENTER		1
        #define LXiTREEJUST_RIGHT		2


        #define LXiTREEVIEW_SELECT_PRIMARY		0x001
        #define LXiTREEVIEW_SELECT_ADD			0x002
        #define LXiTREEVIEW_SELECT_REMOVE		0x003
        #define LXiTREEVIEW_SELECT_CLEAR		0x004

        #define LXiTREEVIEW_BATCH_BEGIN			0x010
        #define LXiTREEVIEW_BATCH_END			0x020

        #define LXiTREEVIEW_MAKE_TOPMOST		0x100

        #define LXiTREEVIEWm_SELECT			0x00F
        #define LXiTREEVIEWm_BATCH			0x0F0

        #define LXiTREEVIEWx_IS_SELECT(m)		((m) & TPSELm_SELECT)
        #define LXiTREEVIEWx_IS_BATCH(m)		((m) & TPSELm_BATCH)

/*
 * There are two ways to defined badges, through a simple set of presets and a more robust set of flags.
 * There are 4 different preset badge types supported by ILxTreeView: Info badges, which are simply there or not in
 * order to indicate state, toggle badges which can be on or off and are togglable through user selection, action
 * badges that are used to perform an action on the cell, and star rating badges. BadgeType returns the badge preset
 * badge we're dealing with with an incrementing badgeIndex. Returning zero indicates there are no further badges
 * for the current cell.
 * - INFO
 * An informational badge with a static image.  These are always drawn with the icon you provide.
 * 
 * - TOGGLE_ON
 * - TOGGLE_OFF
 * A badge that can be toggled on or off with a click.  These are always drawn with the on or off icons you
 * provide.
 * 
 * - ACTION
 * A badge that is clicked on to perform an action.  These are only drawn with the icon you provide when the
 * mouse is over the cell.
 * 
 * - RATING
 * Star ratings badges.  When the mouse is off the cell, the current rating (1 to 5 stars) are drawn.  Moving
 * the mouse over the cell shows all the stars so the user can click to change the rating.
 * 
 */

        #define LXiTREEVIEW_BADGE_INFO			0x01
        #define LXiTREEVIEW_BADGE_TOGGLE_ON		0x02
        #define LXiTREEVIEW_BADGE_TOGGLE_OFF		0x03
        #define LXiTREEVIEW_BADGE_ACTION		0x04
        #define LXiTREEVIEW_BADGE_RATING		0x05

/*
 * Instead of using presets, you can use this newer method to more directly configure your badges by
 * combining a series of flags.  Notable customizations include allowing the value of the badge can be
 * found automatically by querying the command associated with it, hidding badges, and hiding toggle
 * badges when they are in their off state.
 * Being flags, these are all "LXf" defines instead of "LXi" defines.
 * The basic types are as above.  One of these flags must always be set.
 * 
 * - INFO
 * An informational badge with a static image.  These are always drawn with the icon you provide.
 * 
 * - TOGGLE
 * A badge that can be toggled on or off with a click.  These are always drawn with the on or off icons you
 * provide.  Set the IS_ON flag if you want the toggle to be drawn in the "on" state.
 * 
 * - ACTION
 * A badge that is clicked on to perform an action.  These are only drawn with the icon you provide when the
 * mouse is over the cell.
 * 
 * - RATING
 * Star ratings badges.  When the mouse is off the cell, the current rating (1 to 5 stars) are drawn.  Moving
 * the mouse over the cell shows all the stars so the user can click to change the rating.
 * 
 * You can also define one badge as drawing immediately to the right of the label:
 * 
 * - SPECIAL
 * This badge is specially drawn immediately to the right of the label.  Only one badge can have this flag set.
 * All other badges are drawn on the right edge of the cell.
 * 
 * You can also decide if the badge should be visible or not:
 * 
 * - IS_VISIBLE
 * Show the badge.  It can be useful to hide badges that don't make apply for a given cell while using the
 * same badge indices for all cells.  You'll usually want to set this flag, or else your badge won't be drawn.
 * 
 * - IS_VISIBLE_WHEN_OFF
 * Show a toggle badge when it is off and the mouse is not over the cell.  By default, toggles are always
 * drawn even iin their off state.
 * 
 * Finally, the command associated with the badge can be automatically queried for its value:
 * 
 * - VALUE_FROM_QUERY
 * When this is set, the badge's command is quered for its value, and that (integer or boolean) value is
 * used to for the star rating or to decide if a toggle is on or off.
 * 
 */

        #define LXfTREEVIEW_BADGE_INFO			0x10000000			// Always visible badge, usually to indicate some permenant state
        #define LXfTREEVIEW_BADGE_TOGGLE		0x20000000			// Badge that represents a state on the item, and may be on or off
        #define LXfTREEVIEW_BADGE_ACTION		0x30000000			// Badge that is only visible when the mouse moves over the cell, and is usually clicked as a button by the user
        #define LXfTREEVIEW_BADGE_STARRATING		0x40000000			// Special badge that the user can use to choose a star rating

        #define LXfTREEVIEW_BADGE_SPECIAL		0x01000000			// Badge appears immediately to the right of the label, instead of the far right edge of the cell.  Only one badge can have this flag, and it must be the last one in the list.

        #define LXfTREEVIEW_BADGE_IS_VISIBLE		0x00100000			// True if the badge should be drawn; false to hide it
        #define LXfTREEVIEW_BADGE_IS_VISIBLE_WHEN_OFF	0x00200000			// True if a toggle badge should be drawn even off; false if it should only be drawn when on or when the mouse is over the cell

        #define LXfTREEVIEW_BADGE_IS_ON			0x00000001			// True if the badge should be drawn in its "on" state

        #define LXfTREEVIEW_BADGE_VALUE_FROM_QUERY	0x00001000			// When set, the value is obtained by querying the action command

/*
 * If a badge is defined for the current cell and badgeIndex combination, BadgeDetail is then called to obtain
 * information about that badge. ICON_ON and ICON_OFF should return a reference to the relevant 14x14 icons to
 * be used by the badge. Action should return a command string that is executed when the user clicks the badge.
 * In the case of a star badge this should be a query command that returns an integer indicating the star rating.
 */

        #define LXiTREEVIEW_BADGE_DETAIL_ICON_ON	0x01
        #define LXiTREEVIEW_BADGE_DETAIL_ICON_OFF	0x02
        #define LXiTREEVIEW_BADGE_DETAIL_ACTION		0x03
        #define LXiTREEVIEW_BADGE_DETAIL_TOOLTIP	0x04

/*
 * The following methods implement the new ILxDrop approach to drag and drop functionality. Details of
 * the ILxDrop system can be found in awin_sdk.html
 * SupportedDragDropSourceTypes returns a space-seperated string of source type tags supported by the
 * identified cell, with the GetDragDrop methods providing the source and destination COM objects for
 * the ILxDrop system.
 * The drop location will be one of the following, depending if the drop is on, before or after this
 * item in the tree.  If the drop is in the dead space after all of the items in the tree, then the
 * location will be set to DEADSPACE isntad.
 * 
 */

        #define LXiTREEVIEW_DROPLOC_ON		 0
        #define LXiTREEVIEW_DROPLOC_BEFORE	 1
        #define LXiTREEVIEW_DROPLOC_AFTER	 2
        #define LXiTREEVIEW_DROPLOC_DEADSPACE	-1

/*
 * Filtering can be applied to the tree.  The tree object does the filtering itself, but
 * by going into the filtering mode it tells the tree view to do some specific behaviors
 * to help make entries more visible.  Filtering is applied whenever CanFilter() returns
 * true on the root node during a rebuild (ie: NewShape() event).
 * Wehn CanFilter() returns true, each element of the tree has its Filter() method called.
 * The results of filtering are stored by the tree object via the SetItemState() method
 * through the LXfTREEITEM_FITLER_ flags, and are retrieved by the tree view via ItemState()
 * (see those methods in the IKxTreeView docs for more information).
 * Filter() returns a combination of the following for each item:
 * 
 */

        #define LXfTREEFILTER_SHOW			 0x00000
        #define LXfTREEFILTER_HIDE			 0x00001

        #define LXfTREEFILTER_SHOW_IF_CHILDREN_MATCH	 0x00010
        #define LXfTREEFILTER_SHOW_WITH_ALL_CHILDREN	 0x00020

        #define LXfTREEFILTERx_SHOW(f)			 (((f) & LXfTREEFILTER_HIDE) ? 0 : 1)

/*
 * This interface was retired in after 11.0v1, and was replaced with an updated one
 * that adds the style support.
 */

        #define LXu_TREEVIEW3		"ec0c5d6f-9477-4bae-97e8-2205ed1cdb23"
        //[export] ILxTreeView3 treeview3
        //[local]  ILxTreeView3
        //[python] ILxTreeView3:IsSelected	bool
        //[python] ILxTreeView3:IsInputRegion	bool
        //[python] ILxTreeView3:ToPrimary	bool
        //[python] ILxTreeView3:GetDragDropSourceObject		obj Unknown
        //[python] ILxTreeView3:GetDragDropDestinationObject	obj Unknown

/*
 * This interface was retired in after 10.1v2, and was replaced with an updated one
 * that adds the IsDependentSelected method, allowing for more efficient implementations.
 */

        #define LXu_TREEVIEW2		"8307d6f1-c30b-48e7-a0ee-aab0a45bcf1d"
        //[export] ILxTreeView2 treeview2
        //[local]  ILxTreeView2
        //[python] ILxTreeView2:IsSelected	bool
        //[python] ILxTreeView2:IsInputRegion	bool
        //[python] ILxTreeView2:ToPrimary	bool
        //[python] ILxTreeView2:GetDragDropSourceObject		obj Unknown
        //[python] ILxTreeView2:GetDragDropDestinationObject	obj Unknown

/*
 * This interface was retired in after 901, and was replaced with an updated one
 * that adds drop position.
 */

        #define LXu_TREEVIEW1		"e4b1f6b4-fed6-4668-9b6b-9526b59cd9ee"
        //[export] ILxTreeView1 treeview1
        //[local]  ILxTreeView1
        //[python] ILxTreeView1:IsSelected	bool
        //[python] ILxTreeView1:IsInputRegion	bool
        //[python] ILxTreeView1:ToPrimary	bool
        //[python] ILxTreeView1:GetDragDropSourceObject		obj Unknown
        //[python] ILxTreeView1:GetDragDropDestinationObject	obj Unknown

#endif
