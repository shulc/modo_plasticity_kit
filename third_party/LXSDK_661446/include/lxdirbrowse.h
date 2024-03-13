/*
 * LX dirbrowse module
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
#ifndef LX_dirbrowse_H
#define LX_dirbrowse_H

typedef struct vt_ILxDirCacheService ** ILxDirCacheServiceID;
typedef struct vt_ILxDirCacheEntry ** ILxDirCacheEntryID;
typedef struct vt_ILxDirEntryThumbAsync ** ILxDirEntryThumbAsyncID;
typedef struct vt_ILxMergedDirCacheEntry ** ILxMergedDirCacheEntryID;
typedef struct vt_ILxDirCacheFileMetrics ** ILxDirCacheFileMetricsID;
typedef struct vt_ILxDirCacheSynthetic ** ILxDirCacheSyntheticID;
typedef struct vt_ILxDirCacheSyntheticEntry1 ** ILxDirCacheSyntheticEntry1ID;
typedef struct vt_ILxDirCacheSyntheticEntry ** ILxDirCacheSyntheticEntryID;
typedef struct vt_ILxBasePathAddDest ** ILxBasePathAddDestID;
typedef struct vt_ILxDirCacheManualOrderDest ** ILxDirCacheManualOrderDestID;
typedef struct vt_ILxDirCacheGridPosDest ** ILxDirCacheGridPosDestID;
typedef struct vt_ILxFileSysDest ** ILxFileSysDestID;
typedef struct vt_ILxMergedFileSysDest ** ILxMergedFileSysDestID;
typedef struct vt_ILxDirBrowserBasePathEntryDest ** ILxDirBrowserBasePathEntryDestID;

#include <lxserver.h>
#include <lxvalue.h>



/*
 * As with all services, we start with the ScriptQuery method, although it is
 * not implemented.
 * Entries within a cache are represented by objects with an ILxDirCacheEntry
 * interface.  These can represent a file or directory, which can be either "real"
 * (as in, it exists on disk) a synthetic construct.  Often these objects also
 * implement an ILxAttributes interface to expose various bits of metadata.
 * Its worth noting that not all non-synthetic files are in base paths.  For example,
 * a synthetic directory may be displaying all clips loaded in the scene, and those
 * clips may not be from the standard content that are part of the default base paths.
 * 
 * The root paths usually match the base paths of all of the DirBrowserBasePaths
 * instances.  However, if a base path is the child of another base path, then only
 * the more root path will be in the root of the cache, as the other path will
 * already be in the cache as a child.
 * 
 * These functions allow the cache to be walked.  Passing in NULL for the parent will
 * return the root-level paths (ie: the base paths from all the DirBrowserBasePaths).
 * 
 * 
 * When using the above two methods, it is important to lock the list so that it
 * doesn't change out from under you.  This is accomplished with the locking
 * methods.  Lock calls are reentrant within a thread, and can be nested.
 * It is usually wise to make a copy of the root list and then unlock it.  This avoids
 * any possible deadlocks that may arise from a lock being held on the root list while
 * one of the dir cache threads attempts to lock it while already having a lock on one
 * of its entries.  The deadlock arises from each thread waiting for the other to release
 * its lock so that it can obtain the next lock.  This isn't a problem if you always walk
 * up the list (from base to child), but it will be an issue if you walk up the list
 * (say, checking to see if a specific entry is a root entry by locking the entry and
 * then locking the root).  As long as the root is locked before any entries are locked
 * in the thread, this issue can be avoided -- or you can just copy the root list.
 * 
 * 
 * Lookup a cache entry by its path anywhere in the hierarchy.  The path is expected to
 * be in local platform format.  This is thread-safe.
 * 
 * This aborts any pending async operations given an identifier string.  This is tested
 * against that returned by all of the pending async objects' Ident() methods, and all
 * that match are canceled.
 * 
 * It is not uncommon to create a new file by D&D'ing some content into a Preset Browser.
 * If the view supports manual ordering or grid mode, it is often desirable to respect that
 * and place the newly-created file in the appropraite location.
 * This method handles all of that for you.  You just need to provide an LXtObjectID from
 * the drop destination and the path of the file you created, and this will update the
 * manual order and grid position as appropraite.  Note that the file's path must match
 * that of the directory provided by the destination object, or this will do nothing.
 * 
 * It is important to note that this is only realy good for updating a single file; calling
 * this multiple times may result in the paths being shuffled around oddly, as you really
 * want to take into account the previosuly positioned file instead of just the information
 * present in the destination object.
 * 
 * With the introduction of merged base paths, the new SetPosOnDropForCLlent() should be
 * used instead
 * 
 * 
 * 
 * The dir cache needs to be told when a file or directory changes.  On app activation
 * it will automatically rescan all directories looking for changes, and update as
 * appropriate.  If the files or dirs are added or removed while the app is running,
 * this function should be called by the client that did that modification so that the
 * cache will be refreshed.
 * If the path provided points to a directory, that directory and its children will be
 * scanned for changes.  If the path is a file, the directory that contains the file
 * and its children will be scanned.  If the path is NULL, the entire cache is rescanned.
 * 
 * Rescanning involves hitting the disk, testing each file and its sidecar files for
 * changes.  Scanning the entire standard content directory hierarchy in a development
 * build on a spinning disk hard drive takes about four seconds, which isn't too bad
 * for 4000 or so files and dirs.  Targetting a specific directory should be nearly
 * instant from the user's point of view.
 * 
 * 
 * While it operates as a low-priority thread, dir cache background isn't always
 * desirable. A preference determines if the cache should always upgrade in the
 * background or only when a client is actively using it.
 * Clients declare that they're using it by calling this method to increment the
 * use count.  This keeps the cache thread running and makes sure that everything
 * is up to date.  If a client attempts to access the cache without increasing
 * the use count, they may have stale cache data or no cache data at all.
 * 
 * 
 * When a client no longer needs to access the cache, it should remove itself.
 * This just keeps the cache from doing any further updates, but it will first
 * finish writing any changes to disk as needed.
 * 
 * With the introduction of synthetic paths, we need a way to parse those paths.
 * This will automatically handle both file system paths and synthetic paths,
 * with the caveat that the paths must be absolute (ie: a synthetic path starts
 * with "[servername]:") so that it can be properly identified.
 * 
 * Similarly, this will compose a path, inserting the appropriate separators
 * for synthetic vs. local paths.  The filename buffer will be a combination
 * of the path, a separator, and the basename, although if the basename is
 * absolute it will be the only thing in the filename buffer.
 * 
 * Test to see if a path is a child of another path, returning LXe_TRUE if it
 * is and LXe_FALSE if it's not.  This works on both real and synthetic paths.
 * 
 * This retuns the local version of a path.  Synthetic paths are simply returned
 * as the original path, while non-synethic paths are returned as though
 * ILxFileService::ToLocalAlias() was called on it.
 * 
 * This returns if two paths are equal. Synthetic paths are considered to be case
 * insensitive.
 * 
 * This returns true if a path can be renamed with the file.rename and dircache.rename
 * commands.
 * 
 * This ensures that the path provided exists on disk, creating the directories along the
 * path if they don't.  At leaast the first component of the path must exist, and the user
 * must have approriate permissions to modify the path.  If any part of the path can't be
 * created, this will fail.
 * If skipLastPart is true, we assume that part is the file component and will not try to
 * create a directory there, but will create them for all components up to that point.
 * 
 * This works only on local paths, and will fail on synthetics and merged entries.
 * 
 * 
 * This generates a new path that has a guaranteed unique filename relative in the directory
 * represented by the entry provided (more on that below).  The name is a base filename that
 * is appended to the entry's path, and should include an extension, such as "color.lxc".
 * A unique name is generated by inserting "_1", "_2", etc just before the extension until
 * a file cannot be found at that location.
 * The following objects can be passed to this method:
 * 
 * - ILxDirCacheEntry
 * If this is a directory, it will return a unique filename in that directory.  If it is a
 * file, it will return a unique filename in the parent directory.
 * 
 * - ILxMergedDirCacheEntry
 * Same as for ILxDirCacheEntry, but the new name will be unique in all of the component
 * entries that make up this merged entry, with the final path being composed from the user
 * path and the name provided.
 * 
 * - ILxFileSysDest
 * The new name is unique within the local path found in the destination.
 * 
 * - ILxMergedFileSysDest
 * The new name is unique within the paths of all entries in the merged destination.  The
 * final path will be placed in the ILxFileSysDest path if available, falling back to the
 * path of the first entry if not.
 * 
 */
typedef struct vt_ILxDirCacheService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
RootCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
RootByIndex) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
RootLock) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
RootUnlock) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		  self,
        const char		 *path,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
CachedThumbnailAsyncCancel) (
        LXtObjectID		  self,
        const char		 *ident);
        LXxMETHOD(  LxResult,
SetPosOnDrop) (
        LXtObjectID		  self,
        const char		 *path,
        LXtObjectID		  dest);
        LXxMETHOD(  LxResult,
AttributesChanged) (
        LXtObjectID		  self,
        LXtObjectID		  dirCacheEntry,
        int			  which,
        const char		 *attribute);
        LXxMETHOD(  LxResult,
ScanForChanges) (
        LXtObjectID		  self,
        const char		 *path);
        LXxMETHOD(  LxResult,
AddClient) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
RemoveClient) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
ParseName) (
        LXtObjectID		 self,
        const char		*filename,
        char			*baseName,
        int			 baseNameLen,
        char			*path,
        int			 pathLen);
        LXxMETHOD(  LxResult,
PathCompose) (
        LXtObjectID		 self,
        char			*filename,
        int			 filenameLen,
        const char		*baseName,
        const char		*path);
        LXxMETHOD(  LxResult,
IsChildOfPath) (
        LXtObjectID		 self,
        const char		*possibleChild,
        const char		*parentToTestAgainsts,
        int			 orIsSame);
        LXxMETHOD(  LxResult,
ToLocalAlias) (
        LXtObjectID		 self,
        char			*path,
        char			*buf,
        int			 len);
        LXxMETHOD(  LxResult,
ArePathsEqual) (
        LXtObjectID		 self,
        const char		*path1,
        const char		*path2);
        LXxMETHOD(  LxResult,
CanBeRenamed) (
        LXtObjectID		 self,
        const char		*path);
        LXxMETHOD(  LxResult,
MakeDirHierarchy) (
        LXtObjectID		 self,
        const char		*path,
        int			 skipLastPart);
        LXxMETHOD(  LxResult,
MakeUniqueIn) (
        LXtObjectID		 self,
        LXtObjectID		 object,
        const char		*filename,
        char			*buf,
        int			 len);
} ILxDirCacheService;

/*
 * 
 * There are times when you just need a quick count of the entries or a way to tell
 * if there are any at all.  This returns that count.
 * 
 * These can be used to get the local format path, name part (the last part of the path,
 * including any extension) and extension, if available.
 * 
 * The size of the file in bytes can also be read as a float.  This is only supported
 * for files, and will not currently return the size of the contents of a directory
 * hierarchy (it doesn't fail; it just returns 0 instead).
 * 
 * The time the file or directory was created or modified on disk (whichever time is
 * more recent) can be read as a string.  The format is "YYYY:MM:DD HH:MM:SS", which
 * makes it easy to compare dates with strcmp().
 * 
 * This returns the parent of an entry, or fails with NOTFOUND if this is a base entry.
 * 
 * If the entry is a reference, this returns the entry it is referencing.
 * 
 * These can be used to get an ILxArrayID containing the list of entries referencing
 * this entry as their source.  As with the dir/file lists, the array maintains a read
 * lock on the entry until it is released, and thus should be released as soon as
 * possible.
 * Note that as of modo 12.2, the asCopy argument is always considered to be true.  This
 * change in behavior avoids deadlocks that could happen in cerrtain circumstances.  Always
 * returning a copy avoids these problem with no real penalties
 * 
 * 
 * This quickly returns a count of referencess to this entry, without the overhead
 * of allocating an array object.
 * 
 * This returns LXe_TRUE if the file was recognized by a server, and
 * LXe_FALSE if it was not.  Unrecognized files are usually hidden from
 * the browser.
 * 
 * These methods return ILxAttributes interfaces assocaited with the entry.
 * This metadata is basic information like image resolution or the number of
 * polygons, and is read only.
 * 
 * Markup contains user-defined features like tags and star ratings.  These
 * objects are normally read only, but you can request a writable object
 * by setting the isWrite flag to true.
 * 
 * The writable object is a copy of the original markup to which you can
 * make any changes you like.  Once you are finished, you must call one
 * of the following functions to commit the changes.  The contents of
 * the object will be copied into the entry, after which your object can
 * be freed.  Note that you can also create a new object yourself
 * (meaning, there is no need to use a writable object obtained by
 * calling the above functions), which is most useful when you need
 * to add or remove attributes instead of simply changing their values.
 * Since this obtains a write lock, care must be taken to ensure that
 * you do not currently have a lcok on the entry (say, by having a
 * non-copied array returned from DirList()) or else the app will
 * deadlock.
 * 
 * 
 * These utilities return label, tooltip and description strings.  If they aren't
 * available from the metadata, they are generated from the filename.
 * 
 * There is one other special case:  If the client returns an idealW/idealH of 0,0,
 * the image is unbounded and any size is valid.
 * Note that this method does not use the cache, and will always hit the disk, but it
 * is capacble of getting an image up to the ideal size (the cache is limited to
 * 512x512).
 * 
 * Also note that if the image is from a resource, this will fail unless it is called
 * from the main thread, as image resources cannot be processed from any other thread.
 * 
 * 
 * This method will block until it can return an image or fail.  Note that images
 * for resrouces can only be read from the main thread, meaning that if the thumbnail
 * isn't already cached this call will simply fail for those cases.
 * 
 * This related method returns a cached thumbnail scaled to the desired size.
 * If necessary, it will load the closest cached thumbnail from disk and resize
 * it as needed.  The maximum size is 512x512.  As above, this will block until
 * it can return an image or has failed.
 * 
 * This version of the method returns as quickly as possible.  If an image is avaialble
 * in the in-memory cache, it returns that image directly; if not, it will be queued and
 * loaded asynchronously and the method will return LXe_NOTREADY.  The ILxDirEntryThumbAsyncID
 * object provided will be called from the main thread when the thumbnail is ready.  The async
 * handler provided will be owned by this system and released when no longer needed.
 * If this filename is already queued with this ident, the existing one will be removed and
 * the new one will be added to the head of the list.
 * 
 * These operations can be canceled by calling ILxDirCacheService::CachedThumbnailAsyncCancel().
 * 
 * 
 * A directory maintains a manual sort list of all of the files/dirs contained within.
 * Initially, all entries are alpha-sorted with directories sorted first.
 * The manual sort position of an entry within a directory can be read with this method.
 * The function takes either the name part of the entry or the full path (the last part
 * of the path is always used), and returns the index of that entry relative to the other
 * entries in the directory.
 * 
 * Note that manual sort order is intended for sorting files relative to each other.  It
 * is possible for the order to return empty gaps between two otherwise adjacent entries.
 * The most common cause of this is when a file is both copied to a directory and its
 * order is set.  Since the directory hasn't been rescanned for the new file(s) yet, the
 * manual sort list contains paths that don't currently exist in the child file/dir list.
 * 
 * The childPath argument can be a full path or simply the name of the file/dir itself.
 * 
 * 
 * 
 * A directory maintains the grid positions of each of the files within when
 * (directories are not supported for grid mode).  Grid mode is commonly used
 * in things like color pickers, where a palette of user-defined colors can
 * be re-arranged at will.  Entries in the grid need not be contiguous, allowing
 * for gaps between entries.  Grid positions are arbitrary, but must be positive
 * numbers.
 * Directories cannot be placed in the grid; this is only available for files.
 * 
 * This looks up the grid position for a given child path.  Only the filename
 * portion of the path need be provided, but you can pass the whole path if you
 * like.
 * 
 * If no grid positions are assigned when this is called, the files in the dir
 * are implicitly assigned new positions, starting with 0,0, with each row being
 * 10 enries wide.
 * 
 * If new files are added to the directory after the grid has been initialized,
 * they are added to a new row below the last entry  This ensures that new files
 * are still in the grid, but aren't inadvertently filling in gaps that were
 * intentionally left by the user.
 * 
 * Note that when doing a lookup on a file's path, none of the children should
 * be locked in the same thread, as it may be necessary to walk the children
 * from this function.  If any children are locked in the same thread, this will
 * result in a deadlock.
 * 
 * 
 * This sets the grid position of an entry.  If another entry is already at
 * that position, the two will be swapped.  If the new entry didn't have a
 * previous position, it will be moved to after the last entry in the grid.
 * 
 * This returns the rightmost and bottommost coordinates of a region all of
 * the entries within the grid.  While the box they define (starting from
 * 0,0) will never be smaller than the region defined by the thumbnails
 * coordinates, it may be larger.  This larger space allows for "padding"
 * into which users can D&D files outside of the bounds of the existing
 * entries.
 * 
 * This allows the extents to be changed at any time.  Attempting to make
 * the extents smaller than the coordinates of the entries (meaning,
 * attempting to make it so that some entries are not within the extents)
 * will result in the extents being resized to fit the thumbnails.  Thus,
 * passing in 0,0 will result in the bottom right enclosing all entries.
 * 
 * 
 * This similarly removes rows or columns from the grid.  If force
 * is false, then rows/columns will be removed only if no entries
 * exist in that row/columm.  If true, then entries will be shifted
 * over to fill the empty slots, but nothing will happent to entries
 * occupying those slots.  Passing in a very larger number for "count"
 * will effectively remove any empty space between entries.
 * As with inserting rows, setting both x and y to valid coordinates
 * will affect only cells on that row/column, while setting one of
 * them to LXiDCEGRID_NONE will affect all entries with positions
 * equal to or greater than the x or y coordinates provided.
 * 
 * Removing may decrease the extents of the grid, including when
 * removing empty rows/columns from the far bottom/right.
 * 
 * 
 * This returns LXe_TRUE if a grid row or column is empty, and
 * LXe_FALSE if not.  Setting both x and y to non-LXiDCEGRID_NONE
 * values will test the row or column from that point on.
 * 
 * This returns LXe_TRUE if a grid cell or column is empty, and LXe_FALSE
 * if not
 * If it returns false, the ILxDirCachenEntry representing the thumb at that
 * cell can be returned; if you don't need this, ppvObj can be set to NULL.
 * If it is set, the object must be released when no longer needed.
 * 
 * 
 * This returns the username of the entry.  It's primarily intended for
 * synthetic directories, which may have usernames that are different from
 * the internal name.  For everything else, this just returns the internal
 * name, which is that component of the path.  Files can provide alternate
 * names through the "label" property of their metadata.
 * 
 * Return the overriden parent
 * 
 */
typedef struct vt_ILxDirCacheEntry {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		  self,
        int			 *type);
        LXxMETHOD(  LxResult,
DirList) (
        LXtObjectID		  self,
        int			  listMode,
        void			**ppvObj,
        int			  asCopy);
        LXxMETHOD(  unsigned int,
DirCount) (
        LXtObjectID		  self,
        int			  listMode);
        LXxMETHOD(  LxResult,
Path) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
Extension) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
Size) (
        LXtObjectID		  self,
        double			 *size);
        LXxMETHOD(  LxResult,
ModTime) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
Parent) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ReferenceSource) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ReferencedList) (
        LXtObjectID		  self,
        void			**ppvObj,
        int			  asCopy);
        LXxMETHOD(  unsigned int,
ReferencedCount) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
WasRecognized) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
Metadata) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
UserMarkup) (
        LXtObjectID		  self,
        void			**ppvObj,
        int			  asWritable);

        LXxMETHOD(  LxResult,
SharedMarkup) (
        LXtObjectID		  self,
        void			**ppvObj,
        int			  asWritable);
        LXxMETHOD(  LxResult,
CommitUserMarkup) (
        LXtObjectID		  self,
        LXtObjectID		  userMarkup);

        LXxMETHOD(  LxResult,
CommitSharedMarkup) (
        LXtObjectID		  self,
        LXtObjectID		  sharedMarkup);
        LXxMETHOD(  LxResult,
Label) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
Desc) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
ToolTip) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
Thumbnail) (
        LXtObjectID		  self,
        int			  w,
        int			  h,
        unsigned int		 *idealW,
        unsigned int		 *idealH,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
CachedThumbnail) (
        LXtObjectID		  self,
        int			  size,
        unsigned int		 *idealW,
        unsigned int		 *idealH,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
CachedThumbnailCustom) (
        LXtObjectID		  self,
        int			  w,
        int			  h,
        unsigned int		 *idealW,
        unsigned int		 *idealH,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
CachedThumbnailAsync) (
        LXtObjectID		  self,
        int			  size,
        unsigned int		 *idealW,
        unsigned int		 *idealH,
        void			**ppvObj,
        LXtObjectID		  asyncHandler);

        LXxMETHOD(  LxResult,
CachedThumbnailCustomAsync) (
        LXtObjectID		  self,
        int			  w,
        int			  h,
        unsigned int		 *idealW,
        unsigned int		 *idealH,
        void			**ppvObj,
        LXtObjectID		  asyncHandler);
        LXxMETHOD(  LxResult,
ChildManualOrderLookup) (
        LXtObjectID		 self,
        const char		*childPath,
        unsigned int		*pos);
        LXxMETHOD(  LxResult,
ChildManualOrderSet) (
        LXtObjectID		 self,
        const char		*childPath,
        unsigned int		 pos);
        LXxMETHOD(  LxResult,
ChildGridPositionLookup) (
        LXtObjectID		 self,
        const char		*childPath,
        unsigned int		*x,
        unsigned int		*y);
        LXxMETHOD(  LxResult,
ChildGridPositionSet) (
        LXtObjectID		 self,
        const char		*childPath,
        unsigned int		 x,
        unsigned int		 y);
        LXxMETHOD(  LxResult,
GridExtents) (
        LXtObjectID		 self,
        unsigned int		*bottom,
        unsigned int		*right );
        LXxMETHOD(  LxResult,
GridSetExtents) (
        LXtObjectID		 self,
        unsigned int		 bottom,
        unsigned int		 right );
        LXxMETHOD(  LxResult,
GridInsert) (
        LXtObjectID		 self,
        int			 doRows,
        unsigned int		 x,
        unsigned int		 y,
        unsigned int		 count );
        LXxMETHOD(  LxResult,
GridRemove) (
        LXtObjectID		 self,
        int			 doRows,
        unsigned int		 x,
        unsigned int		 y,
        unsigned int		 count,
        int			 force );
        LXxMETHOD(  LxResult,
GridIsEmpty) (
        LXtObjectID		 self,
        int			 doRows,
        unsigned int		 x,
        unsigned int		 y);
        LXxMETHOD(  LxResult,
GridIsEmptyCell) (
        LXtObjectID		  self,
        unsigned int		  x,
        unsigned int		  y,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Username) (
        LXtObjectID		 self,
        char			*buf,
        int			 len);
        LXxMETHOD(  LxResult,
OverrideParent) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);
} ILxDirCacheEntry;

/*
 * 
 * The Ident() method is used to allow the client to cancel any pending async operations.
 * It returns an arbitrary string, and is compared against the one passed into
 * CachedThumbnailAsyncCancel(). All instances with that ident are canceled.  If this
 * method returns NOTIMPL, the operation cannot be canceled.
 */
typedef struct vt_ILxDirEntryThumbAsync {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Ready) (
        LXtObjectID		  self,
        LXtObjectID		  dirCacheEntry,
        unsigned int		  idealW,
        unsigned int		  idealH,
        LXtObjectID		  image);

        LXxMETHOD(  LxResult,
Failed) (
        LXtObjectID		  self,
        LXtObjectID		  dirCacheEntry);
        LXxMETHOD(  LxResult,
Ident) (
        LXtObjectID		  self,
        const char		**ident);
} ILxDirEntryThumbAsync;

/*
 * Get the path of this entry in the merged hierarchy, which means it starts with
 * "#basePathIdent(setName):".  For directories, this is the same as their actual
 * path, since merged directories are their own construct.  For files, this will
 * be different from the path returned by ILxDirCacheEntry::Path(), wtih the
 * former being a merged path and the latter being the path of the entry that
 * was merged to create this entry.
 * Get the list of entries that were merged to create this entry.  These will only
 * have the ILxDirCacheEntry interface, not the merged interface.
 * 
 * For directories, this returns the user path, which is where new files are writen to. 
 * For files, this is the location the file would exist if it were in the user path
 * (and will be if it actually does exist there).
 * 
 * This returns the parent directory as a merged object.
 */
typedef struct vt_ILxMergedDirCacheEntry {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Path) (
        LXtObjectID		 self,
        char			*buf,
        int			 len);
        LXxMETHOD(  LxResult,
EntryCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
EntryByIndex) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
UserPath) (
        LXtObjectID		 self,
        char			*buf,
        int			 len);
        LXxMETHOD(  LxResult,
Parent) (
        LXtObjectID		  self,
        void			**ppvObj);
} ILxMergedDirCacheEntry;

/*
 * This method returns an object with an ILxAttributes interface containing
 * metadata from the file.  This includes properties that are part of the file's
 * definition and won't be changed from the browser itself, such as an image's
 * dimensions and bit depth, or a meshes polygon count.  Metadata is considered
 * read only.
 * 
 * This returns an object with an ILxAttributes interface representing the user-defined
 * markup that is stored in the file itself.  This includes properties like tags, star
 * ratings and so on.  Such markup is defined by the cache system; the file is just
 * storing it for us.
 * If this method returns NOTIMPL, it is assumed that markup cannot be stored in the
 * file at all.  Returning NOTFOUND indicates that markup is supported, but that the
 * file simply didn't contain any.  An OK code indicates that markup was found and
 * the object returned is valid.
 * 
 * 
 * - DYNAMIC_THUMBNAIL
 * If set, this indicates that the thumbnail images can be quickly dynamically generated
 * and do not need to be stored in the on-disk cache.  A prime example of this is the
 * color switches used by color presets.
 */
typedef struct vt_ILxDirCacheFileMetrics {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Metadata) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Markup) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		  self,
        int			 *flags);
} ILxDirCacheFileMetrics;

/*
 * The synthetic server returns synthetic entry objects representing
 * directories with an and files with an ILxDirCacheSyntheticEntry
 * interface.
 * 
 * Given a path, this returns a matching interface, or returns LXe_NOTAVAILABLE
 * if the path can't be found.  Note that all paths will be absolute and start
 * with "[servername]:", although the root ommits the colon.
 * 
 * 
 * This returns the root entry, and is identical to calling Lookup() with
 * "[servername]".
 */
typedef struct vt_ILxDirCacheSynthetic {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		  self,
        const char		 *path,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Root) (
        LXtObjectID		  self,
        void			**ppvObj);
} ILxDirCacheSynthetic;

typedef struct vt_ILxDirCacheSyntheticEntry1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Path) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
DirUsername) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
FileExtension) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
IsFile) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
DirBuild) (
        LXtObjectID		  self);

        LXxMETHOD(  unsigned int,
DirCount) (
        LXtObjectID		  self,
        int			  listMode);

        LXxMETHOD( LxResult,
DirByIndex) (
        LXtObjectID		  self,
        int			  listMode,
        unsigned int		  index,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
ModTime) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  double,
Size) (
        LXtObjectID		  self);
} ILxDirCacheSyntheticEntry1;

/*
 * Returns the path to this entry, including the "[servername]:" portion.
 * Due to the nature of synthetic dirs, the path should be a generic path
 * without any localization (ie: an internal name string).
 * 
 * Return a user defined parent path of this directory entry.
 * If implemented, this path is used instead of the real parent
 * when the user wants to go up to the parent directory (like inside packages files, cf. extra/package)
 * It could include the "[servername]:" or any recognised path.
 * Return a "" path will return to the root of any presetChoice.
 * Return LXe_NOTIMPL will used the default implementation.
 * 
 * These return the username and internal name of the entry itself.  The
 * internal name is suitable for building a path  For files, the name is
 * execpted to include any extension, if present.
 * The username is for display purposes, and is only used for directories.
 * Files get their username from the label stored in the metadata.
 * 
 * 
 * For files, this returns the extension, if there is any.  Files are not
 * required to have extensions, and some synthetic files may have periods
 * that are not mark an extension, so this makes it very clear what the
 * extension is to the caller.
 * If there is no extension, this can return LXe_NOTFOUND, or simply
 * LXe_NOTIMPL when no extensions are supported.  Other codes will be
 * considered actual failures.  As usual, SHORTBUF should be returned
 * if the buffer isn't big enough.
 * 
 * 
 * This returns LXe_TRUE if the entry is a file, and LXe_FALSE if it is
 * a directory that can contain other files.
 * 
 * For directories, these methods allow the list of files and directories
 * to be walked.
 * 
 * First, a scan request is made.  Often the child list is burned into the
 * synthetic entry on creation, in which case this does nothing and returns
 * immediately, but in other cases but it is desirable to build
 * the child list just before it is walked.  If this fails, we consider the
 * directory to be empty, but it can be marked for rescan later with
 * ILxDirCacheService::ScanForChanges().
 * 
 * Since these lists are commonly used in threads, care should be taken to
 * not change them out from under the caller.
 * 
 * 
 * listMode is a LXvDCELIST_ indicating if files, directories or both
 * are going to be requested by the upcoming DirCount() and DirByIndex() calls.
 * The object returned from DirByIndex() should have the ILxDirCacheSyntheticEntry
 * interface.
 * 
 * 
 * This returns the modification time of the entry as a string.  The exact
 * nature of this is arbitrary and up to the server, but it should be possible
 * to compare it with strcmp() such that more recent dates are considered
 * larger than less recent dates. This is used to decide if the dir cache needs
 * ot be updated with new state from the synthetic folder.
 * If this is a directory, then if any of the files inside of it have changed,
 * the directory time should also have changed.  If the stirng is empty, it
 * is always considered to have changed.
 * 
 * 
 * Get the size of a file in bytes.  This is mostly used for searches/filtering,
 * and is expected to return 0 for directories, or for files where size
 * doesn't make sense.  This is returned as a double to handle very large file
 * sizes beyond what a 32 bit int can hold.
 */
typedef struct vt_ILxDirCacheSyntheticEntry {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Path) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
OverrideParent) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
DirUsername) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
FileExtension) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
IsFile) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
DirBuild) (
        LXtObjectID		  self);
        LXxMETHOD(  unsigned int,
DirCount) (
        LXtObjectID		  self,
        int			  listMode);

        LXxMETHOD( LxResult,
DirByIndex) (
        LXtObjectID		  self,
        int			  listMode,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ModTime) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);
        LXxMETHOD(  double,
Size) (
        LXtObjectID		  self);
} ILxDirCacheSyntheticEntry;

/*
 * Calling this method adds a new base path to the named set in the associated browser,
 * creating the set if needed.
 */
typedef struct vt_ILxBasePathAddDest {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddBasePath) (
        LXtObjectID		  self,
        const char		 *setName,
        const char		 *path);
} ILxBasePathAddDest;

/*
 * This method returns the names of the two files/dirs that the drop point is between.  It will
 * return NULL for a name if the drop point is at the beginning/end of the list.  Clients can
 * call ILxDirCacheEntry::ManualChildOrderSet() on the parent object (returned as ppvObj) to
 * set the position of a path relative to another path.  If the asPaths is true, then the
 * strings returned represent the full path instead of just the name.
 */
typedef struct vt_ILxDirCacheManualOrderDest {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
BetweenPaths) (
        LXtObjectID		  self,
        void			**ppvObj,
        const char		**nameBefore,
        const char		**nameAfter,
        int			  asPaths);
} ILxDirCacheManualOrderDest;

/*
 * This method returns the ILxDirCacheEntry containing the drop point, as well as the x and y
 * coordinates of the drop point.  The coordinates represent an empty cell or a cell already in
 * use by a file.  Clients can call ILxDirCacheEntry::ChildGridPositionSet() on the directory
 * (returned as ppvObj) to set new coordiantes for a file within.
 */
typedef struct vt_ILxDirCacheGridPosDest {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GridPos) (
        LXtObjectID		  self,
        void			**ppvObj,
        unsigned int		 *x,
        unsigned int		 *y);
} ILxDirCacheGridPosDest;

/*
 * This returns the destination's path.  The server can use this to create new files,
 * move existing files to the path, or overwrite an existing file with a new one.
 * 
 * This utility returns LXe_TRUE if the path is a file, and LXe_FALSE if it is a directory.
 * 
 * This is similar to Path().  The difference is that the path returned by Path() may point
 * to a file or directory.  AsDir() will return Path() if IsDir() would return false, but
 * if not it will instead return the parent of Path().  This is useful if the intention of
 * the drop is to create a new file in the same directory as a file path returned by Path().
 */
typedef struct vt_ILxFileSysDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Path) (
        LXtObjectID		  self,
        const char		**path);
        LXxMETHOD( LxResult,
IsDir) (
        LXtObjectID		  self);
        LXxMETHOD( LxResult,
AsDir) (
        LXtObjectID		  self,
        const char		**dir);
} ILxFileSysDest;

/*
 * This returns the entry represented by the merged path.  This can be queried for the ILxDirCacheEntry
 * and ILxMergedDirCacheEntry interfaces
 * The rest of these methods are just convenience methods that pass through to the object
 * returned by MergedEntry().
 * These allow the list of paths that were merged to create this specific destination point to
 * be walked.  If the drop location is on a file, this is a list of filenames that exist in the
 * merged directories.  If the location is a dir, this is all the dirs that were merged.  The
 * first entry in the list represents the "user" location, and is where edits should be made
 * on a drop (such as where to create a new directory).  This is also the path that is always
 * returned by the ILxFileSysDest interface.  The objects returned from ByIndex() will have
 * the ILxDirCacheEntryID interface, and in the case of directories, also the
 * ILxMergedDirCacheEntryID interface.
 * 
 * 
 * 
 * This returns the merged version of the path (ie: "#basePathIdent(setName):path").
 */
typedef struct vt_ILxMergedFileSysDest {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
MergedEntry) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
EntryCount) (
        LXtObjectID		  self,
        unsigned int		 *count);
        LXxMETHOD(  LxResult,
EntryByIndex) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Path) (
        LXtObjectID		  self,
        char			 *buf,
        int			  len);
} ILxMergedFileSysDest;

/*
 * Get the path of the set being dragged into, in the form of
 * "#basePathIdent(setName):".
 * Ordinals may be NULL if this is the beginning/end of the list.
 * 
 */
typedef struct vt_ILxDirBrowserBasePathEntryDest {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
SetPath) (
        LXtObjectID		  self,
        const char		**path);
        LXxMETHOD(  LxResult,
OrdinalBefore) (
        LXtObjectID		  self,
        const char		**ordinal);
        LXxMETHOD(  LxResult,
OrdinalAfter) (
        LXtObjectID		  self,
        const char		**ordinal);
} ILxDirBrowserBasePathEntryDest;

/*
 * The service provides access to the root entires of the cache (which are all of
 * the base paths from all of the browsers).
 */

        #define LXu_DIRCACHESERVICE		"b61119fa-4cd9-4067-ba48-ba83ad1fa544"
        #define LXa_DIRCACHESERVICE		"dircacheservice"
        // [python] ILxDirCacheService:RootByIndex	obj DirCacheEntry
        // [python] ILxDirCacheService:Lookup		obj DirCacheEntry

/*
 * If you make changes to a markup attribute, you need to notify the dir cache service
 * through this method so that it can update its state and so the attributes can be saved
 * into the files.  Simply pass in the ILxDirCacheEntry and the name of the attribute you
 * updated, or NULL if multiple attributes were changed on that entry.  The "which" flag
 * indicates if the attribute was changed in the user markup, the shared markup or both.
 * Note that contrary to most other entry methods, if the entry is a file then it must
 * NOT be locked before calling this method.  The method will do its own locking, and
 * attempting to lock it yourself can result in a deadlock.  Directories can be locked
 * without issue, as only the directory itself is updated, while for files, the parent
 * directory also needs to be updated.
 */

        #define LXiDCEMARKUP_UPDATED_USER	1
        #define LXiDCEMARKUP_UPDATED_SHARED	2
        #define LXiDCEMARKUP_UPDATED_BOTH	(LXiDCEMARKUP_UPDATED_USER | LXiDCEMARKUP_UPDATED_SHARED)

/*
 * The ILxDirCacheEntry represents a single file or directory.  It may be "real" (as in,
 * it exists on disk), or it may be a synthetic object that exists only in memmory.
 * Objects with this interface usually also implement an ILxAttributes interface so that
 * their metadata can be read.
 */

        #define LXu_DIRCACHEENTRY		"1013a289-aa27-416a-b273-666732ce3d88"
        #define LXa_DIRCACHEENTRY		"dircacheentry"
        // [local]  ILxDirCacheEntry
        // [python] ILxDirCacheEntry:CachedThumbnail		obj Image
        // [python] ILxDirCacheEntry:CachedThumbnailAsync	obj Image
        // [python] ILxDirCacheEntry:CachedThumbnailCustom	obj Image
        // [python] ILxDirCacheEntry:CachedThumbnailCustomAsync	obj Image
        // [python] ILxDirCacheEntry:DirList			obj Array
        // [python] ILxDirCacheEntry:GridIsEmptyCell		obj DirCacheEntry
        // [python] ILxDirCacheEntry:Metadata			obj Attributes
        // [python] ILxDirCacheEntry:Parent			obj DirCacheEntry
        // [python] ILxDirCacheEntry:ReferenceSource		obj DirCacheEntry
        // [python] ILxDirCacheEntry:ReferencedList		obj Array
        // [python] ILxDirCacheEntry:SharedMarkup		obj Unknown
        // [python] ILxDirCacheEntry:Thumbnail			obj Image
        // [python] ILxDirCacheEntry:UserMarkup			obj Unknown
        // [python] ILxDirCacheEntry:GridIsEmpty		bool
        // [python] ILxDirCacheEntry:GridIsEmptyCell		bool

/*
 * This returns the type of the file as a bitmask.  Files represent an end-point in the
 * hierarchy, while directories contain child entries.  References are synthetic entries
 * that point to other files/dirs (synthetic or real), and are commonly used to create
 * things similar to "playlists" -- user-defined in-memory fodlers that contain arbitrary
 * collections of files -- and smart directories whose contents are defined by filters.
 * Note that references never point to other references; attempting to do so weill cause
 * both to point to the actual referenced entry.
 * The FILE and DIR flags indicate the file type, and may be merged with the SYNTHETIC
 * or REFERENCE flags.  If neither FILE or DIR are set, then the entry does not exist.
 * Usually non-existant entries simply aren't in the cache, but they are used for base
 * paths.
 */

        #define LXvDCETYPE_INVALID		0x00000000

        // Masks
        #define	LXmDCETYPE_FILEDIR		0x0000000F
        #define	LXmDCETYPE_FLAGS		0x000000F0
        #define	LXmDCETYPE_SYNTH		0x00000F00
        #define	LXmDCETYPE_SPECIAL		0x0000F000

        // Bits
        #define LXfDCETYPE_FILE			0x00000001				// File
        #define LXfDCETYPE_DIR			0x00000002				// Directory

        #define LXfDCETYPE_READONLY		0x00000010				// Read-only, and cannot be deleted, renamed or otherwise modified
        #define LXfDCETYPE_DIR_AS_FILE		0x00000020				// Directory that is treated as a file.  It will show up as a file in the browser, but exists as a directory for access purposes (ie: it can't be opened for read/write like a file)

        #define LXfDCETYPE_SYNTHETIC		0x00000100				// Synthetic entry that does not exist on disk
        #define LXfDCETYPE_REFERENCE		0x00000200				// Synthetic entry that references another entry, which may itself be synthetic.  References do not point to other references
        #define LXfDCETYPE_FILTERED		0x00000400				// A synthetic directory whose contents is defined by its filter

        // Macros
        #define LXxDCETYPE_IS_FILE(t)		((t) & LXfDCETYPE_FILE)									// File flag is set
        #define LXxDCETYPE_IS_DIR(t)		((t) & LXfDCETYPE_DIR)									// Dir flag is set

        #define LXfDCETYPE_EXISTS(t)		(LXxDCETYPE_IS_FILE(t) || LXxDCETYPE_IS_DIR(t))
        #define LXxDCETYPE_IS_DIR_AS_FILE(t)	(((t) & LXfDCETYPE_DIR) && ((t) & LXfDCETYPE_DIR_AS_FILE))

        #define LXxDCETYPE_AS_FILE(t)		(LXxDCETYPE_IS_FILE(t) || (LXxDCETYPE_IS_DIR(t) && LXxDCETYPE_IS_DIR_AS_FILE(t)))	// Treat the path as a file
        #define LXxDCETYPE_AS_DIR(t)		(LXxDCETYPE_IS_DIR(t)  && !LXxDCETYPE_IS_DIR_AS_FILE(t))				// Treat the path as a dir

        #define LXxDCETYPE_IS_READONLY(t)	((t) & LXfDCETYPE_READONLY)
        #define LXxDCETYPE_IS_READWRITE(t)	(!((t) & LXfDCETYPE_READONLY))

        #define LXxDCETYPE_IS_REAL(t)		(((t) & LXmDCETYPE_SYNTH) == 0)		// AKA "not synthetic" (also not a reference)
        #define LXxDCETYPE_IS_SYNTHETIC(t)	 ((t) & LXfDCETYPE_SYNTHETIC)
        #define LXxDCETYPE_IS_REFERENCE(t)	 ((t) & LXfDCETYPE_REFERENCE)
        #define LXxDCETYPE_IS_FILTERED(t)	(((t) & LXfDCETYPE_FILTERED) && DBCExTYPE_IS_DIR(t))

/*
 * This macro just returns true if the path string is synthetic by testing the
 * first character, for cases where you don't have the type.
 */

        #define LXxDIRCACHE_IS_SYNTHETIC_PATH(p)	((((p) != NULL) && ((p)[0] != '[')) ? 0 : 1)

/*
 * This similar macro tests for merged paths.  Merged paths always start with a octothorpe (#)
 * to indicate their unique status, and represent the contents of multiple real or synthetic
 * paths merged into a single view.  A full merged path prefix should be in the form of,
 * "#basePathIdent(name):", where basePathIdent is the name of config key (hash, identifier,
 * whatever) used to associate this set with this browesr, and name is the name of the set.
 */

        #define LXxDIRCACHE_IS_MERGED_PATH(p)	((((p) != NULL) && ((p)[0] != '#')) ? 0 : 1)

/*
 * For directory types, this returns the child files and/or directories as a read-only
 * ILxArray object.  For conveience, this can return just files (including dirs-as-files),
 * just dirs, or both.
 * It's important to note that the returned array object should be considered transient,
 * and should be released as soon as possible.  The array object maintains a read lock
 * on the entry to ensure that it doesn't change while you are using it.  This means that
 * no part of the entry can be modified until the array is released.
 * If you need to modify the directory entry while you have the array object, you can
 * avoid the read lock by requesting a copy of the array.  This is slower than just
 * getting the array directly, but there is no lock to worry about, and since it's a
 * copy the list won't change out form under you.
 * 
 * Note that as of modo 12.2, the asCopy argument is always considered to be true.  This
 * change in behavior avoids deadlocks that could happen in cerrtain circumstances.  Always
 * returning a copy avoids these problem with no real penalties.
 * 
 */

        #define	LXvDCELIST_DIRS			0x1
        #define	LXvDCELIST_FILES		0x2
        #define	LXvDCELIST_BOTH			(LXvDCELIST_DIRS | LXvDCELIST_FILES)

/*
 * Get the thumbnail for an entry.  You can request any size, but the image you actually
 * get back may be larger or smaller than the one requested.  The ideal width and height
 * are returned indirectlry, and represent the full-resolution image.
 * There are also two special image resolutions available, and are used if either the
 * width or height are set to them:
 * - IDEAL_ONLY
 * *ppvObj will be NULL, but idealW and idealH will be set to the full image resolution.
 * 
 * - FULL
 * *ppvObj will be set to the full-resolution image.
 * 
 */

        #define LXiDCE_THUMBSIZE_IDEAL_ONLY	0
        #define LXiDCE_THUMBSIZE_FULL		0xFFFFFFFF

/*
 * The cache system does mantain an on-disk cache of thumbnails in a few fiuxed
 * sizes.  Furthermore, there is an in-memory cache capacble of storing images
 * of arbitrary sizes. Requesting one of these is much faster than loading the
 * full-size image from the source file with Thumbnail().
 * If no cached version exists, the 512x512 size is loaded from the source, resized
 * and saved into the various cache images, and then returned in the desired size.
 * This means that the first time a cached thumbnail is requested may take longer
 * than normal, but subsequent requests will be faster, even though it still has
 * to be loaded from disk.
 */

        #define LXiDCE_CACHEDTHUMBSIZE_32	0
        #define LXiDCE_CACHEDTHUMBSIZE_64	1
        #define LXiDCE_CACHEDTHUMBSIZE_128	2
        #define LXiDCE_CACHEDTHUMBSIZE_256	3
        #define LXiDCE_CACHEDTHUMBSIZE_512	4

        #define LXiDCE_CAHCEDTHUMBSIZE_COUNT	5

/*
 * The ILxDirEntryThumbAsync interface is pretty simple.  If the image was successfully
 * loaded, the Ready() method is called with the image and ideal w/h.  If it fails, the
 * Failed() method is called instead.  Both methods include the ILxDirCacheEntry that
 * the method was called on, and are always called from the main thread.
 */

        #define LXu_DIRENTRYTHUMBASYNC		"0a3c97de-37b8-44b2-a52b-b1b91c77e597"
        #define LXa_DIRENTRYTHUMBASYNC		"direntrythumbasync"
        // [local] ILxDirEntryThumbAsync
        // [export] ILxDirEntryThumbAsync detasync

/*
 * This method allows the sort order of a child entry to be set.  The special defines
 * can be used to move the entry to the first or last position in the list.  Passing
 * in a position greater than the highest position will move it to the end of the list,
 * and is equivalent to LXiDCE_MANUALORDER_LAST.
 * Again, the childPath argument can be either the full path or just name part of the
 * file/dir.
 */

        #define LXiDCE_MANUALORDER_FIRST	0xFFFFFFFF
        #define LXiDCE_MANUALORDER_LAST		0xFFFFFFFE

/*
 * This allows empty rows and columns to be insert into the grid by
 * shifting the coordinates of the entries at a given grid position.
 * right (columns) or down (rows) Passing a count of 0 will result in
 * no change.  If doRows is true, "count" rows will be added at the
 * coordinate provided; otherwise, it adds columns.
 * The x and y coordinates determine which entries are moved.  If both
 * x and y are set along with doRows, then "count" empty cells are
 * inserted below the specific cell at (x,y).  If instead x was set
 * to LXiDCEGRID_NONE, then "count" row of blank cells would be
 * inserted between all entries at "y" or lower
 * Inserting always increases the extents of the grid, even if
 * adding empty rows/columns to the far bottom/right.  If the
 * x/y are beyond the extents, the extents are padded to that
 * position and then the rows are inserted.
 * 
 */

        #define LXiDCEGRID_NONE		0xFFFFFFFF

/*
 * When using merged hierarchies, the ILxMergedDirCacheEntry is available on the object
 * in addition to the ILxDirCacheEntry interface.  This provides a list of the
 * ILxDirCacheEntry objects that were merged to create this entry.
 * For directories, this is the list of directories whose contents were merged, in local
 * format.
 * For a file, this is the list of files that exist in all of the merged directories
 * this file is from, in local format.
 * 
 * In both cases, the ILxDirCacheEntryID points to the the best match for this location,
 * and that can be used for most operations.  The merged location is most useful for
 * special operations, such as checking the local version of a file against a cloud
 * version.
 * 
 * The entry at index 0 os the same as the one returned by the ILxDirCacheEntryID,
 * with them all being sorted in the order they are arranged in the base path list.
 * 
 * The paths of the file and its parent directory in merged format can be returned,
 * as well as the object representing the merged parent.  This is different from the
 * ILxDirCacheEntry's parent method, which returns the true local parent.
 * 
 */

        #define LXu_MERGEDDIRCACHEENTRY		"38986948-6e89-4208-a734-411d28ab4815"
        #define LXa_MERGEDDIRCACHEENTRY		"mergeddircacheentry"
        // [local]  ILxMergedDirCacheEntry
        // [python] ILxMergedDirCacheEntry:EntryByIndex		obj DirCacheEntry
        // [python] ILxMergedDirCacheEntry:Parent		obj DirCacheEntry

/*
 * An object with this interface is returned by clients registed with the cache system.
 * Currently this is only used internally, and won't be called form the SDK, but is made
 * public in case future expansion warrants it.  See ILxPresetType for information on
 * exposing file state from the Preset Browser system, even if your file is not a preset
 * per say.
 * ILxDirCacheFileMetrics objects are commonly used in threads, and must be thread safe.
 */

        #define LXu_DIRCACHEFILEMETRICS		"2c00a80c-ac90-401c-8cb8-abfdf3ba26dd"
        #define LXa_DIRCACHEFILEMETRICS		"dircachefilemetrics"
        // [local]  ILxDirCacheFileMetrics
        // [export] ILxDirCacheFileMetrics dcfilemetrics
        // [python] ILxDirCacheFileMetrics:Metadata	obj Attributes
        // [python] ILxDirCacheFileMetrics:Markup	obj Attributes

/*
 * This returns some special flags for the file.
 */

        #define LXiDCFM_DYNAMIC_THUMBNAILS		0x00000001

/*
 * The core dir cache looks at a subset of the file system defined by
 * base paths.  It is also possible for plug-ins to serve content that
 * doesn't exist on disk through synthetic folders.
 * Each server defines a single synthetic base path derived from its
 * server name.  These are considered root-level paths in the cache,
 * using the volume identifier "[servername]" Paths inside those dirs
 * are accessed in neutral format, prefixed with the "[servername]:"
 * identifier (ie: "[servername]:dir/file.ext").  If there a path
 * component can be represented as a username or an internal name,
 * it will always be encoded as the internal name.
 * 
 * Information is read from the paths representing "files" through preset
 * servers, just like for any other path.  Such servers have to be flagged
 * to support synthetic paths.  Similarly, drag and drop requires clients
 * to explicitly handle LXsDROPSOURCE_FILES_SYNTH, which may include both
 * real and synthetic paths.
 * 
 * Since all cache scanning is done through threads, all methods on
 * the server must be thread safe.  In particular, synthetics and preset
 * servers should not be written in Python, as it is not thread safe.
 * 
 */

        #define LXu_DIRCACHESYNTHETIC		"d269abf7-7bd3-4982-a6bd-cb46fcebe1e3"
        #define LXa_DIRCACHESYNTHETIC		"dircachesynthetic"
        // [local] ILxDirCacheSynthetic
        // [export] ILxDirCacheSynthetic dcsyn
        // [python] ILxDirCacheSynthetic:Lookup		obj DirCacheSyntheticEntry
        // [python] ILxDirCacheSynthetic:Root		obj DirCacheSyntheticEntry

/*
 * This server tag indicates the backing of the synthetic folder.  It
 * directly determiens the scan priority of the server's folders relative
 * to other servers.  The current values are:
 * - MEMORY
 * State that already exists in memory and is very fast to load.
 * - NETWORK_SINGLE
 * Network access to a server.  This is specifically with regards to quickly pulling down
 * a single file that contains all of the information for a directory.  As such, the individual
 * files inside the folder will be prioritized as MEMORY.
 * 
 * - NETWORK_MULTIPLE
 * Same, but both files and dirs will be processed after in-memory files, as files
 * are assumed to require extra network calls to get information about them.
 * 
 * - FILE_SINGLE
 * An entire directory populated by a single file.  Directories will be processed
 * after NETWORK backings, but their files will be processed with MEMORY priority.
 * 
 * - FILE_MULTIPLE
 * Each file and directory is separately processed by hitting the disk.  These are always
 * prioritized last.
 * 
 * If the tag isn't set or has an unknown value, OTHER is assumed.
 * 
 */

        #define LXsDCSYNTH_BACKING			"dirCacheSynthetic.backing"

        #define LXsDCSYNTH_BACKING_MEMORY		"memory"
        #define LXsDCSYNTH_BACKING_NETWORK_SINGLE	"network.single"
        #define LXsDCSYNTH_BACKING_NETWORK_MULTIPLE	"network.multiple"
        #define LXsDCSYNTH_BACKING_FILE_SINGLE		"file.single"
        #define LXsDCSYNTH_BACKING_FILE_MULTIPLE	"file.multiple"

/*
 * Old Interface. This was changed to add OverrideParent function. (15.2)
 */

        #define LXu_DIRCACHESYNTHETICENTRY1	"c85d528d-50aa-4974-bbf0-6122b4e00d5b"
        // [local]  ILxDirCacheSyntheticEntry1
        // [export] ILxDirCacheSyntheticEntry1 dcsyne
        // [python] ILxDirCacheSyntheticEntry1:DirByIndex	obj DirCacheSyntheticEntry
        // [python] ILxDirCacheSyntheticEntry1:IsFile		bool

/*
 * The synthetic entry represents a single directory or file, from the root
 * at "[servername]:" through to to individual files.  For directories, it
 * provides access files and dirs within as yet more synthetic entries.
 * All methods on this interface must be thread safe.  The most common way
 * to construct an entry is to build one when requested such that all of the
 * state it needs is part of the entry object, without any external dependencies.
 * This ensures that if whatever was used to build the entry changes in another
 * thread, the scan thread will still have a valid entry object.  In effect,
 * the entry is a snapshot of the dir/file state and is considered disposable.
 * 
 * The first time an directory entry is requested, the server may need to do
 * some expensive setup.  Rather than blocking the scan thread, it can return
 * that it has zero children, do the setup separately, and later call
 * ILxDirCacheService::ScanForChanges() to tell the dir cache to update that path.
 * 
 */

        #define LXu_DIRCACHESYNTHETICENTRY	"9d741627-beea-4c7f-8666-ccbdb2cd3e72"
        #define LXa_DIRCACHESYNTHETICENTRY	"dircachesyntheticentry"
        // [local]  ILxDirCacheSyntheticEntry
        // [export] ILxDirCacheSyntheticEntry dcsyne
        // [python] ILxDirCacheSyntheticEntry:DirByIndex	obj DirCacheSyntheticEntry
        // [python] ILxDirCacheSyntheticEntry:IsFile		bool

/*
 * An object with this interface is exposed during drag and drop in the Dir Browser.  Its single
 * method can be called by an ILxDrop server to add a new base path to the browser.
 */

        #define LXu_BASEPATHADDDEST		"1710a8c1-a493-4e65-a190-009effc4a134"
        #define LXa_BASEPATHADDDEST		"basepathadddest"
        //[local]  ILxBasePathAddDest

/*
 * The dir cache also manages the manual sort order of files/dirs within a directory.  This is
 * exposed through drag and drop through an ILxDirCacheManualOrderDest interface on the destination
 * object.
 */

        #define LXu_DIRCACHEMANUALORDERDEST	"fb69c873-9f95-4ba1-ba1f-1235307e3c88"
        #define LXa_DIRCACHEMANUALORDERDEST	"dircachemanualorderdest"
        //[local]  ILxDirCacheManualOrderDest
        //[python] ILxDirCacheManualOrderDest:BetweenPaths	obj DirCacheEntry

/*
 * The dir cache also manages the grid positions of files within a directory (directories themseves
 * cannot be placed on the grid, and are not supported).  This is exposed through drag and drop
 * through an ILxDirCacheGridPosDest interface on the destination object.
 */

        #define LXu_DIRCACHEGRIDPOSDEST		"09a9db0d-131f-40ed-910a-8916a636dc36"
        #define LXa_DIRCACHEGRIDPOSDEST		"dircachegridposdest"
        //[local]  ILxDirCacheGridPosDest
        //[python] ILxDirCacheGridPosDest:GridPos	obj DirCacheEntry

/*
 * The FilePath destination simply provides a path to a file or directory.  This is often
 * used to create new files or move existing files at the time of the drop.
 */

        #define LXu_FILESYSDEST		"79d4f661-3249-4455-bfb9-486120c18f24"
        #define LXa_FILESYSDEST		"fileSystemDestination"
        //[local]  ILxFileSysDest
        //[python] ILxFileSysDest:IsDir		bool

/*
 * When dropping into a merged directory, ILxFileSysDest isn't quite good enough.  While it can
 * still be used for drops into the user dir, extra information is available through this interface.
 * Both interfaces are usually present on the same object when merged paths are available.
 */

        #define LXu_MERGEDFILESYSDEST		"a58450c6-5789-4072-84eb-92154d632dc2"
        #define LXa_MERGEDFILESYSDEST		"mergedFileSystemDestination"
        //[local]  ILxMergedFileSysDest
        // [local]  ILxMergedDirCacheEntry
        // [python] ILxMergedDirCacheEntry:MergedEntry		obj DirCacheEntry
        // [python] ILxMergedDirCacheEntry:EntryByIndex		obj DirCacheEntry
        // [python] ILxMergedDirCacheEntry:Parent		obj DirCacheEntry

/*
 * This internal interface is used when dragging and dropping onto a
 * base path entry, and is used to re-order the entries in a set.
 * The two ordinals of the entries before and after the drop location
 * are provided, and the dropped path should be inserted between them.
 * This is commonly used with the BASEPATHENTRIES source type, which is
 * an ILxValueArrayID containing strings in the form of
 * "#basePathIdent(setName):entryPath".
 */

        #define LXsDROPSOURCE_BASEPATHENTRIES		"basePathEntries"

        #define LXu_DIRBROWSERBASEPATHENTRYDEST		"56a0f290-9aca-4e44-b036-b2bbb7be28d2"
        #define LXa_DIRBROWSERBASEPATHENTRYDEST		"dirBrowserBasePathEntryDest"
        //[local]  ILxDirBrowserBasePathEntryDest

#endif
