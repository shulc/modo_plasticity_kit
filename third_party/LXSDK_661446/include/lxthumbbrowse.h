/*
 * LX thumbbrowse module
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
#ifndef LX_thumbbrowse_H
#define LX_thumbbrowse_H

typedef struct vt_ILxDTBBadgeOverride ** ILxDTBBadgeOverrideID;
typedef struct vt_ILxDTBDropPreview ** ILxDTBDropPreviewID;
typedef struct vt_ILxDTBGroupSortOverride ** ILxDTBGroupSortOverrideID;

#include <lxserver.h>
#include <lxvalue.h>



/*
 * 
 * This indicates if an action badge should always be visible, or visible only
 * when the mouse is over th thumbnail.  This is useful for the download badge
 * when the asset isn't yet downloaded. Setting this to false will make it vsiible
 * only when the mouse is over the thumbnail, and is useful to for the downlooad
 * badge when the asset is already downloaded, allowing the user to re-download it.
 * 
 * 
 * Get a tooltip string (as a message table lookup in the form of @table@messsage@)
 * to display for the badge.  This is most useful for the download badge, as the
 * icon tends to be different depending on if the local copy is newer or older than
 * the cloud copy.
 * 
 * The star rating badge returns two things: a star rating as an number from 0-5,
 * and an alternate image for the star rating.  This allows cloud ratings to be
 * visually distinct from local ratings, although the name field can be empty if
 * the default star icon should be used.
 * As above, this should return NOTIMPL if the client can't support the file.
 * 
 * 
 * When the user clicks on a badge, this method is called so that the client can
 * perform an action.    If the server doesn't handle actions on this entry, it
 * should return NOTIMPL.
 * 
 * Similarly, this is called when the user changes the star rating.  Again, this
 * should return NOTIMPL if the entry isn't handled.
 */
typedef struct vt_ILxDTBBadgeOverride {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
BadgesSupported) (
        LXtObjectID		  self,
        LXtObjectID		  entry,
        int			 *badges);
        LXxMETHOD(  LxResult,
BadgeIsAlwaysVisible) (
        LXtObjectID		  self,
        LXtObjectID		  entry,
        int			  badge);
        LXxMETHOD(  LxResult,
BadgeOverride) (
        LXtObjectID		  self,
        LXtObjectID		  entry,
        int			  badge,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
BadgeTooltip) (
        LXtObjectID		  self,
        LXtObjectID		  entry,
        int			  badge,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
BadgeStarRatingOverride) (
        LXtObjectID		  self,
        LXtObjectID		  entry,
        int			 *rating,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
BadgeAction) (
        LXtObjectID		  self,
        LXtObjectID		  entry,
        int			  badge);
        LXxMETHOD(  LxResult,
BadgeStarRatingAction) (
        LXtObjectID		  self,
        LXtObjectID		  entry,
        int			  rating);
} ILxDTBBadgeOverride;

/*
 * Mark nothing at all in the browser.
 * 
 * When the browser is in grid mode, this marks a drop location within a directory as given
 * by its path and the x/y coordinates of the grid cell.  If not in grid mode, this does
 * nothing.
 * Note that this is the only option available in grid mode, and all other methods save
 * MarkNone() will return NOTIMPL when in grid mode.  Similarly, this method is not available
 * when not in grid mode.
 * 
 * 
 * Mark a specific file or directory for the drop via its path.  If the file/dir is not
 * visible, this does nothing.  This is most useful when dropping a file into a directory,
 * or when the drop would change the file being dropped on (say, by changing its thumbnail,
 * or overwriting an existing file).
 * 
 * 
 * This draws drop marker between two adjacent files or directories.  The path of one of these
 * entries the markBefore flag are provided.  When the flag is true, the mark draws before the
 * entry's thumbnail, and when false it is drawn after.  This is commonly used for manual sorting,
 * or (more rarely) when you know where a newly-created file will be inserted into the sorted list.
 * 
 * For some operations, you just want to mark "anywhere" in the browser.  What this really means
 * is anywhere within the directory.  This is commonly used when the drop would create a new file
 * in that directory, but you don't know exactly where it will show up realtive to the other files.
 */
typedef struct vt_ILxDTBDropPreview {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
MarkNone) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
MarkGridPos) (
        LXtObjectID		  self,
        const char		 *path,
        unsigned int		  x,
        unsigned int		  y);
        LXxMETHOD(  LxResult,
MarkEntry) (
        LXtObjectID		  self,
        const char		 *path);
        LXxMETHOD(  LxResult,
MarkBetween) (
        LXtObjectID		  self,
        const char		 *path,
        int			  markBefore);
        LXxMETHOD(  LxResult,
MarkAnywhere) (
        LXtObjectID		  self,
        const char		 *path);
} ILxDTBDropPreview;

/*
 * After being instanced, an optional argument string is passed to this method, or it may
 * not be called at all if no arguments have been set.
 * This method is called to filter two strings relative to each other.  Returning a number
 * less than zero indicates that the first string sorts earlier than the second, while
 * a number greater than zero sorts the second one first.  Zero means the two strings are
 * equal.  This is standard strcmp()-style return codes.  
 * Note that the sort method must be thread safe.
 * 
 */
typedef struct vt_ILxDTBGroupSortOverride {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
SetArguments) (
        LXtObjectID		  self,
        const char		 *args);
        LXxMETHOD(  int,
Sort) (
        LXtObjectID		  self,
        const char		 *string1,
        const char		 *string2);
} ILxDTBGroupSortOverride;

/*
 * Certain badges in the browser can be overridden by specific clients.  The implementation
 * case is the cloud asset browser, where the star rating badge and cloud badge are need
 * to change based on if the user has set their own star rating, and if the version of the
 * file on disk is newer, older, or doesn't exist with respect to the version in the cloud.
 * ILxDTBBadgeOverride provides two methods that are implemented by the client to override
 * badges.  These are caleld with an object with an ILxDirCacheEntry interface. If it also
 * has an ILxMergedDirCacheEntry interface, then the client can look at the individual
 * entries that make up this merged entry so that it can decide what the cloud badge should
 * be.  The client is expected to fail gracefully (ie: return NOTIMPL) for any paths that
 * it doesn't support, so that other clients can try them.
 * For star ratings, the StarRatingOveride() method is used, while simpler badges use the
 * BadgeOverride() method.
 * 
 * When the user clicks a badge, the appropriate method is called so the client can take
 * whatever action it deems fit.
 * 
 */

        #define LXu_DTBBADGEOVERRIDE		"7cc3ec4f-974b-4467-9f26-c3ef78825918"
        #define LXa_DTBBADGEOVERRIDE		"dtbbadgeoverride"
        //[export] ILxDTBBadgeOverride dtbbo
        //[local]  ILxDTBBadgeOverride
        //[python] ILxDTBBadgeOverride:BadgeIsAlwaysVisible	bool

/*
 * Servers are sorted by an ordinal set as a server tag.
 */

        #define LXsDTBBO_ORDINAL		 "dtbbadgeoverride.ordinal"

/*
 * The server indicates which badges an entry supports with this method.  This determines
 * if those badges are even present at all.
 */

        #define LXfDTBBO_HAS_DOWNLOAD		 0x00000001
        #define LXfDTBBO_HAS_STARS		 0x00000002

/*
 * BadgeOverride() is passed a flag indicating which badge is being overridden. Currently
 * only the "download" badge is supported, but more may be added in the future.
 * If the client wants to override the badge, this should return success and indirectly
 * return the name of the icon resource representing the badge to display.  Note that
 * returning success and an empty name is valid, and indicates that you want no badge
 * displayed.  This is different from returning NOTIMPL, as an empty name keeps other
 * clients from being able to test for badges.
 */

        #define LXiDTBBO_DOWNLOAD		 1

/*
 * The DirThumbBrowser (which commonly used to show files and folders in the Preset Browser)
 * supports a prevew interface for drag and drop.  More specifically, it provides a way to
 * change which drop mark is shown in the browser based on how the drop server will apply it.
 */

        #define LXu_DTBDROPPREVIEW		"7ccfca70-79d5-42ed-a5bf-5dfd5bc3262b"
        #define LXa_DTBDROPPREVIEW		"dtbdroppreview"
        //[local]  ILxDTBDropPreview

/*
 * Primarily meant for baked apps, this allows a server to define the sort order for groups
 * in the browse when the view is set to show mutliple groups at once.  It does not affect
 * the DirBrowser attached to the thumb browser/list.
 */

        #define LXu_DTBGROUPSORTOVERRIDE	"0da992be-74c8-4c25-a402-c69216e52dfb"
        #define LXa_DTBGROUPSORTOVERRIDE	"dtbgroupsortoverride"
        //[local]  ILxDTBGroupSortOverride
        //[export] ILxDTBGroupSortOverride gso

#endif
