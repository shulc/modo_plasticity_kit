/*
 * LX uiimage module
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
#ifndef LX_uiimage_H
#define LX_uiimage_H

typedef struct vt_ILxUIImageGrouper ** ILxUIImageGrouperID;
typedef struct vt_ILxUIImageService ** ILxUIImageServiceID;
typedef struct vt_ILxUIImageGroup ** ILxUIImageGroupID;

#include <lxserver.h>
#include <lxvalue.h>
        #ifdef long
         
          #include <time.h>
         
        #else
          #include <time.h>
        #endif



/*
 * UserName() returns a human-readable group name from a single path.  Multiple related paths
 * should return the same group name (for example, the six images of the same GL Environment
 * group).  This group will appear in the menu in place of all the images within.  Note that
 * the user name returned will first be run through the config system to look for a match;
 * if that fails, the raw username will be used.  If the method fails or an empty string
 * is returned, the path of the image will be used as a lookup, and finally returned as a last
 * resort.
 * 
 * Paths() finds all paths related to the input path, feeding them all into an ILxValueArray
 * object (including the input path).  Note that this should return ALL images that should
 * be in the group, even if the images do not actually exist on disk.  For example, the
 * expected path of all six reflection directions above would be returned, even if some of the
 * images do not exist, thus allowing the system to check for the existence of the entire group
 * easily.
 */
typedef struct vt_ILxUIImageGrouper {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID	 self,
        const char	*path,
        char		*buffer,
        int		 len );
        LXxMETHOD(  LxResult,
Paths) (
        LXtObjectID	 self,
        const char	*path,
        ILxValueArrayID	 array );
} ILxUIImageGrouper;

/*
 * Standard ScriptQuery method
 * 
 * These methods allow the list of registered types to be walked, returning their
 * type ID and name.  The list is not sorted in any particular order.
 * 
 * 
 * 
 * The username can also be looked up.  If there is no user name, the internal name
 * is returned.
 * 
 * This returns the LXfUIIMAGE_ flags associated with the type.
 * 
 * Types can be looked up by their internal name or type ID.  If the name is NULL,
 * the type is checked, and the index of the type is returned.  Note that indices
 * are not guarenteed to be static.
 * 
 * Each type can have a "current" or "selected" image.  This image will be selected
 * with a checkmark in the user interface popup.  Note that there can only be one
 * selected image, even if multiple clients use the same type.  In this case, the
 * most recently selected client (say, the viewport the use most recently selected,
 * in the case of the Backdrop Image type) should call this method to set the path
 * to the selected image.  The selected image path is not saved in the config, and
 * must be explicitly set by the client.
 * As before, the ILxUIImageGroupID returned should NOT be freed or AddRef()'ed.
 * Note that the selected image will never be removed from the image list, although
 * the ILxImageIDs themselves may be purged by the cache system.
 * 
 * 
 * The selected image is set by it's path.  NULL can be passed to clear the
 * selected path.
 * 
 * The list of groups of images in each category can be walked with these functions.
 * Groups are referenced by their path or by an index into the type list.  Note that
 * this index is not guarenteed to be static.  Images within groups are referenced
 * by their path or by their index within the group.  You'll save the path of the image
 * in your config.
 * Given a type, an ILxUIImageGroupID can be obtained.  These should be considered
 * transient and not held onto by clients, but rather should be looked up as needed.
 * If you really want to, you can probably hold onto the group ID and nothing bad will
 * happen.
 * 
 * 
 * 
 * A group can be also looked up by the path of one of it's images.
 * 
 * These functions allow images to be added and removed from the database.  Note that
 * adding an image to a type that supports groups, the remaining group images will
 * automatically be found and added.  If all of the images cannot be found, they are
 * still and the the method succeeds with LXe_UIIMAGE_INCOMPLETE_GROUP. If ppvObj is
 * non-NULL, it will be set to an ILxUIImageGroupID representing the new image group.
 * Note that if a group containing this image already exists, the method will succeed
 * and return the existing group instead.
 * The loadImages flag allows for more robust testing of images.  Instead of just
 * checking for file existence, it will try to actually load the images.  If any
 * image cannot be loaded, the method will fail with LXe_UIIMAGE_LOAD_FAILED.
 * 
 * 
 * This removes an image group from the database.  Once removed, further lookups will fail.
 * 
 * This removes all images for that type from the database.
 * 
 * The user can also be asked to pick an image from a file requester.  If ppvObj is
 * non-NULL, it will be set to an ILxUIImageGroupID representing the new image group
 * upon success.
 * 
 * 
 * 
 * It is often useful to embed the thumbnail image into a rich text string.  Rich text only
 * supports a-z, A-Z, 0-9 and _, which means that providing a path won't work.  To simplify
 * embedding cached images, this method can be used.
 * The ebmed string contains the appropriate \03 escape sequence, and can be directly drawn
 * as rich text.  The mode determines which cached image is returned, and is one of the
 * LXiUIIMG_CACHED_ defines above.
 * 
 */
typedef struct vt_ILxUIImageService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
RegisterType) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name,
        ILxUIImageGrouperID	 grouper,
        int			 flags);
        LXxMETHOD(  int,
TypeCount) (
        LXtObjectID		 self );
        LXxMETHOD(  LxResult,
TypeByIndex) (
        LXtObjectID		 self,
        int			 i,
        LXtID4			*type);
        LXxMETHOD(  LxResult,
TypeNameByIndex) (
        LXtObjectID		  self,
        int			  i,
        const char		**name);
        LXxMETHOD(  LxResult,
TypeUserNameByIndex) (
        LXtObjectID		  self,
        int			  i,
        const char		**username);
        LXxMETHOD(  LxResult,
TypeFlagsByIndex) (
        LXtObjectID		 self,
        int			 i,
        int			*flags);
        LXxMETHOD(  LxResult,
TypeLookup) (
        LXtObjectID		  self,
        const char		 *name,
        LXtID4			  type,
        int			 *index);
        LXxMETHOD(  LxResult,
TypeSelected) (
        LXtObjectID		  self,
        const char		 *name,
        LXtID4			  type,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
TypeSetSelected) (
        LXtObjectID		  self,
        const char		 *name,
        LXtID4			  type,
        const char		 *path);
        LXxMETHOD(  int,
GroupCount) (
        LXtObjectID		  self,
        LXtID4			  type );
        LXxMETHOD(  int,
GroupByIndex) (
        LXtObjectID		  self,
        LXtID4			  type,
        int			  i,
        void			**ppvObj );
        LXxMETHOD(  LxResult,
GroupLookup) (
        LXtObjectID		  self,
        LXtID4			  type,
        const char		 *path,
        void			**ppvObj );
        LXxMETHOD(  LxResult,
GroupAdd) (
        LXtObjectID		  self,
        LXtID4			  type,
        const char		 *path,
        int			  loadImages,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
GroupRemove) (
        LXtObjectID		  self,
        LXtID4			  type,
        ILxUIImageGroupID	  group);
        LXxMETHOD(  LxResult,
GroupClearAll) (
        LXtObjectID		  self,
        LXtID4			  type);
        LXxMETHOD(  LxResult,
GroupLoad) (
        LXtObjectID		  self,
        LXtID4			  type,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
GetCachedImage) (
        LXtObjectID		  self,
        const char		 *path,
        int			  mode,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
FlushCachedImage) (
        LXtObjectID		  self,
        const char		 *path,
        int			  mode);
        LXxMETHOD(  LxResult,
GetEmbedablePath) (
        LXtObjectID		  self,
        const char		 *path,
        int			  mode,
        const char		**embed);
} ILxUIImageService;

/*
 * This method gets the username for the group.
 * 
 * The type of the client this group belongs to can also be obtained.
 * 
 * This returns the number of images within the group.
 * 
 * 
 * This returns some metris about the image.
 * 
 * This function returns an image by index.  Note that the ILxImageID is _NOT_
 * AddRef'ed, nor should you AddRef it yourself.  The UI Image system will hold
 * hold onto the image until no one is using it anymore, and will automatically
 * purge it from memory when no longer needed.
 * 
 * A specific image in the group can be looked up by it's path.  Again, the ILxImageID
 * should NOT be AddRef'ed or released by the client; just use it and forget about it.
 * 
 * This method can be used to see if all images in a group exist in memeory, or else on
 * disk.  The group name is one returned by the type's ILxUIImageGrouper::ToGroup() method.	
 * 
 * This returns the path of the first image that exists in memory or on disk in a group.
 * This fails if none of the images can be found.
 * 
 * This is similar, but returns the index, or fails if none exist.
 * 
 * This returns the time in seconds since January 1st, 1970 (or whatever the C time()
 * function counts from) representing when an ILxImageID was last returned from one
 * of this group's methods.  The higher the number, the more recently it was used.
 * ms can be used as a tie breaker if the last used times are the same.  Either ms
 * or lastUsed can be NULL if only one is desired.
 */
typedef struct vt_ILxUIImageGroup {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		  self,
        const char		**username);
        LXxMETHOD(  LxResult,
ClientType) (
        LXtObjectID		  self,
        LXtID4			 *type);
        LXxMETHOD(  LxResult,
ImageCount) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
ImagePathByIndex) (
        LXtObjectID		  self,
        int			  i,
        char			 *buffer,
        int			  len);
        LXxMETHOD(  LxResult,
ImageMetricsByIndex) (
        LXtObjectID		  self,
        int			  i,
        int			 *w,
        int			 *h,
        int			 *depth);
        LXxMETHOD(  LxResult,
ImageByIndex) (
        LXtObjectID		  self,
        int			  i,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ImageLookup) (
        LXtObjectID		  self,
        const char		 *path,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
DoAllImagesExist) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
FirstExistingImagePath) (
        LXtObjectID		  self,
        char			 *buffer,
        int			  len);
        LXxMETHOD(  LxResult,
FirstExistingImageIndex) (
        LXtObjectID		  self,
        int			 *index);
        LXxMETHOD(  LxResult,
LastUsed) (
        LXtObjectID		  self,
        time_t			 *lastUsed,
        int			 *ms);
} ILxUIImageGroup;

/*
 * The image grouper is used to associate multiple images into a single entity.  A
 * common case is the environement reflection images, which are really six different
 * images that are manipulated as a single unit.  This interface is used when registering
 * a new category type with ILxUIImageService as described in the next section.
 */

        #define LXu_UIIMAGEGROUPER		"B69F3583-F3C7-4059-BF8D-84CB61F34260"
        #define LXa_UIIMAGEGROUPER		"uiimagegrouper"

/*
 * This global service is used to manipulate the UI Image system, including walking
 * the image list, registering new categories, requesting images, and so on.
 */

        #define LXu_UIIMAGESERVICE		"ECB8DE30-E0B1-4cda-8571-580ABEA1AC4D"
        #define LXa_UIIMAGESERVICE		"uiimageservice"

        #define LXe_UIIMAGE_INCOMPLETE_GROUP	LXxGOODCODE( LXeSYS_UIIMAGE,   1)	// Warning
        #define LXe_UIIMAGE_ALREADY_EXISTS	LXxFAILCODE( LXeSYS_UIIMAGE,   1)
        #define LXe_UIIMAGE_LOAD_FAILED		LXxFAILCODE( LXeSYS_UIIMAGE,   2)

/*
 * The UI Image system contains multiple categories of images intended for specific
 * uses.  For example, Backdrops, Default Textures and GL Environment Maps are all
 * different categories.  These are are primarily used to group the images in the
 * popup.
 * This function is called to register a new category.  An ID4 type is used for
 * quick lookup, as well as an internal name that is used for config storage and
 * username lookups.
 * The next argument is an optional ILxUIIMageGrouperID, as described above.
 * 
 * This fails with LXe_UIIMAGE_ALREADY_EXISTS if the type or name identify an
 * existing client.
 * 
 * Clients are automatically removed on shutdown.
 * 
 * Clients can support some flags.  If ALLOW_NONE is set, (none) is a valid
 * selection.  If COLOR_CORRECT is set, Adding images with GroupAdd() assumes
 * that they are already color corrected; otherwise, they will be added as
 * uncorrected images.
 * 
 */

        #define	LXfUIIMAGE_ALLOW_NONE		0x01
        #define LXfUIIMAGE_COLOR_CORRECT	0x02

/*
 * The ILxUIImageGroupID can be used to count the images in the group, get their
 * paths and get specific images.  These images are referenced by index, but can
 * also be looked up by path.
 */

        #define LXu_UIIMAGEGROUP		"B1B2816C-B1FC-4b66-9A01-D4969D37ED3C"
        #define LXa_UIIMAGEGROUP		"uiimagegroup"

/*
 * To make image access easy and relatively memory efficient, the cache system is used.  The
 * above functions that get images do so by using the image cache, a thin layer on top of the
 * cache system described in cache.qq  This can be used for an image; you are not limited to
 * using the functions above.
 * This single method is all you need to use the image cache.  The image will be loaded from
 * the path if neccessary, stored in the cache, and returned.  If the image is already in the
 * cache, it will simply be returned directly.
 * Do not hold on to the ILxImageID returned by this method, as this keeps the cache system
 * from being able to intelligently purge unnecessary images.  The client should not call
 * XObjectRelease() on any images returned by this function.
 * 
 * Either a mini-thumbnail sitable for the face of a popup, a larger thumbnail at a size set
 * in the prefs, or the main image at full res can be read.
 * 
 * Also, extra small (14 pixel tall), small (20 pixel tall) or larger (32 pixel tall) images
 * can be requested.  These are useful as icons on the face of buttons.
 * 
 * Finally, there are modifiers that can be applied to an image.  CACHED
 * 
 */

        // Base images
        #define	LXiUIIMG_CACHED_MAIN		0
        #define	LXiUIIMG_CACHED_THUMB		1
        #define	LXiUIIMG_CACHED_FACE		2
        #define	LXiUIIMG_CACHED_ICON_XSMALL	3
        #define	LXiUIIMG_CACHED_ICON_SMALL	4
        #define	LXiUIIMG_CACHED_ICON_LARGE	5

        #define LXiUIIMG_CACHED_BASE_COUNT	6

        #define LXiUIIMG_CACHED_MOD_SCALAR	4		// Used with BASE_COUNT to figure out how many cache slots we need

        // Flags to modify behavior
        #define LXfUIIMG_CACHED_CORRECTED	0x10		// Color corrected (vs. uncorrected)
        #define LXfUIIMG_CACHED_SQUARE		0x20		// Square aspect (vs. original aspect)

        // Masks
        #define LXmUIIMG_CACHED_BASE		0x0F
        #define LXmUIIMG_CACHED_MOD		0xF0

/*
 * A specific cached image can be cleared.  This is useful if the image has changed on disk and
 * the new image should be loaded.  This fails with LXe_NOTFOUND if no currently cached image
 * matches this path.
 * Either the thumbnail, the main image or both can be purged.
 */

        #define	LXfUIIMG_FLUSH_MAIN		0x01
        #define	LXfUIIMG_FLUSH_THUMB		0x02
        #define	LXfUIIMG_FLUSH_FACE		0x04
        #define	LXfUIIMG_FLUSH_ICON_XSMALL	0x08
        #define	LXfUIIMG_FLUSH_ICON_SMALL	0x10
        #define	LXfUIIMG_FLUSH_ICON_LARGE	0x20
        #define	LXiUIIMG_FLUSH_ALL	(LXfUIIMG_FLUSH_MAIN | LXfUIIMG_FLUSH_THUMB | LXfUIIMG_FLUSH_FACE | LXfUIIMG_FLUSH_ICON_XSMALL | LXfUIIMG_FLUSH_ICON_SMALL | LXfUIIMG_FLUSH_ICON_LARGE)

/*
 * After the tree has been presented to the user, this function should be used to resolve the
 * selected tree element into a ILxUIImageGroupID.  This will also destroy the tree object.
 * Be sure to check for user aborts and errors via the returned LxResult.
 * If the user selected the (none) option, this returns LXiUIIMG_NONE.  On error or user abort,
 * the group will be NULL.  if non-NULL, this is the group containing the image.  It should NOT
 * be released by the caller.
 */

        #define LXiUIIMG_NONE	((void *)-1)

#endif
