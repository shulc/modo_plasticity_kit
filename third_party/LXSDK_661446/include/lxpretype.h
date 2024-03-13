/*
 * LX pretype module
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
#ifndef LX_pretype_H
#define LX_pretype_H

typedef struct vt_ILxPresetLoaderTarget ** ILxPresetLoaderTargetID;
typedef struct vt_ILxPresetType ** ILxPresetTypeID;
typedef struct vt_ILxPresetType1 ** ILxPresetType1ID;
typedef struct vt_ILxPresetMetrics ** ILxPresetMetricsID;
typedef struct vt_ILxPresetMetrics1 ** ILxPresetMetrics1ID;
typedef struct vt_ILxPresetDo ** ILxPresetDoID;
typedef struct vt_ILxPresetBrowserSource ** ILxPresetBrowserSourceID;
typedef struct vt_ILxPresetBrowserService ** ILxPresetBrowserServiceID;
typedef struct vt_ILxPBSpecialSelListener ** ILxPBSpecialSelListenerID;

#include <lxserver.h>
#include <lxvalue.h>
#include <lxdirbrowse.h>



/*
 * When using LoaderFind() or LoaderFindAny(), the LoadAccess->target member will point
 * to one of these objects. This contains the name of the server that recognized
 * the file, and the categories that the server said the file belongs to.
 */
typedef struct vt_ILxPresetLoaderTarget {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
ServerName) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);
        LXxMETHOD( LxResult,
CategoryCount) (
        LXtObjectID		 self,
        int			*count);
        LXxMETHOD( LxResult,
CategoryByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**category);
} ILxPresetLoaderTarget;

/*
 * The recognize method is passed the full path to a file.  The server should
 * return an OK code if the server wants to take ownership of it, in which
 * case it may be asked to present the relative metrics, thumbnails and so on,
 * or asked to apply (load) the preset into a compatible object.  Returning a
 * failure code will pass the file on to the next server.  If no servers recognize
 * the file, it will not be shown in the browser, and no servers will be asked to
 * try to load the file.
 * A category string is returned indirectly, and should be one of the categories
 * provided by the server through LXsPBS_CATEGORY.  This is used to decide if
 * the preset should be be shown when the browser is set to only show a specific
 * category.
 * As of 801, the Recognize() method does not return a GUID.  Pre-801 servers
 * may return a GUID for use with drag and drop, but modern clients use ILxDrop
 * to handle arbitrary drop sources and targets, and the Apply() method may
 * support multiple possible interfaces.  As such, the old GUID is considred
 * obsolete and was removed.
 * 
 * Note that the Recognize() method must be thread-safe, as it is called
 * asynchronously to filter the preset browser's file list.
 * 
 * 
 * The Apply() method is also obsolete.  It was previous used for legacy D&D,
 * but that has been superceded by ILxDrop servers.  Servers can not implement
 * this method and simply return LXe_NOTIMPL, in which case an ILxDrop server
 * must be used to apply the preset.
 * In legacy D&D, once a preset has been recognized the client may ask the server
 * to apply the preset, or it may simply ask for metrics (see the section on metrics
 * for more information on the latter).
 * 
 * To apply the preset, a client would call this method.  The client needs to
 * provide the path to a file that was previously identified with the above
 * Recognize() call.  The destination argument is a COM object containing one
 * or more interfaces that the prset can use to decide how to apply itself.
 * 
 * The Apply() method itself will query the destination object for the required
 * interface, failing if it is not found.
 * 
 * By default, the server is assumed to support Apply(), and will be considered
 * when testing servers for drag and drop support.  If it does not support Apply(),
 * the LXsPBS_CANAPPLY server tag must be present with a value of "false".  This
 * is particularly useful for things like images, which aren't presets per say,
 * but still show up in the browser.
 * 
 * 
 * It is also possible to load a preset without a destination.  An example would
 * be double-clicking on a preset in the browser, rather than using drag and drop.
 * In this case, the server needs to look at the current selection state and
 * intelligently apply the preset itself.  We just call this a "do" instead of an
 * "apply".
 * Note that the Do() method should call a command to actually do the apply.  This
 * is because preset.do is a UI command, and they only way to promot it to undoable
 * or side-effect behavior is by executing another command within it.
 * 
 * By default, the server is assumed to support Do(), and thus will be considered
 * when evaluating servers in preset.do.  If it does not support Do(), the LXsPBS_CANDO
 * server tag must be present with a value of "false".
 * 
 * 
 * This method returns the execution flags for a file previously recognized by the
 * server.  If not implemented, the default UI flags are used.
 * 
 * Lastly, it is valid for a client to return LXe_NOTIMPL and not generate any metrics
 * at all.  This allows the creation of clients that only recognize file types and
 * allow them to show up in the browser with default properties.
 * 
 * Servers can define a generic named resource image that is used if the metrics
 * themselves do not provide either a specific thumbnail or a named resource.  If
 * this fails, no thumbnail will be shown.
 * 
 * Servers can also define an aspect ratio that should be used for the thumbnails
 * representing their content.  If not implemented, the default aspect of 1.0 is
 * used.  Since the browser can only show one aspect, there is no point in returning
 * per-thumbnail aspects.  Note that thumbnail images themselves need not be this
 * aspect, and will automatically be centered within the thumbnail's bounds.
 * 
 * The user can update the thumbnail at will.  If the preset format supports it,
 * the new thumbnail can be stored directly in the prefest file itself when this
 * method is called.  If not supported, this can return LXe_NOTIMPL.
 * 
 * This indicates that any previously stored thumbnail should be removed and the
 * default should be used.  This only makes sense if a thumbnail can be generated
 * procedurally, and can return LXe_NOTIMPL if this isn't supported.
 * 
 * User-defined markup (favorites, tags, etc) can be stored in the file.  The
 * object passed in will have an ILxAttributes interface, and its contents should
 * be written to the file, if the format supports it.  If not, this can return
 * LXe_NOTIMPL.
 * 
 * This represents the shared markup (meaning, markup stored in the file itself),
 * not the per-user markup, which is automatically stored in a standard user
 * location.
 * 
 */
typedef struct vt_ILxPresetType {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Recognize) (
        LXtObjectID		  self,
        const char		 *path,
        const char		**category);
        LXxMETHOD( LxResult,
Apply) (
        LXtObjectID		  self,
        const char		 *path,
        LXtObjectID		  destination);
        LXxMETHOD( LxResult,
Do) (
        LXtObjectID		  self,
        const char		 *path);
        LXxMETHOD( LxResult,
DoCommandFlags) (
        LXtObjectID		  self,
        const char		 *path,
        int			 *flags);
        LXxMETHOD( LxResult,
Metrics) (
        LXtObjectID		  self,
        const char		 *path,
        int			  flags,
        int			  w,
        int			  h,
        LXtObjectID		  prevMetrics,
        void			**ppvObj);
        LXxMETHOD( LxResult,
GenericThumbnailResource) (
        LXtObjectID		  self,
        const char		 *path,
        const char		**resourceName);
        LXxMETHOD( LxResult,
BaseAspect) (
        LXtObjectID		  self,
        float			 *aspect);
        LXxMETHOD( LxResult,
StoreThumbnail) (
        LXtObjectID		  self,
        const char		 *path,
        LXtObjectID		  image);
        LXxMETHOD( LxResult,
DefaultThumbnail) (
        LXtObjectID		  self,
        const char		 *path);
        LXxMETHOD( LxResult,
StoreMarkup) (
        LXtObjectID		  self,
        const char		 *path,
        LXtObjectID		  attr);
} ILxPresetType;

/*
 * For legacy servers, the method returns a GUID to decide how to load the file,
 * based on what the server found in the file.  The object passed to the (also
 * obsolete) Apply() method is expected to have this interface.  Often this is
 * not a common GUID like ILxItem, but rather defines a container that holds the
 * true target of the preset load.  For example, it may have a method to return
 * an item, scene, image or other common object, but also may include secondary
 * information that will help the server determine how the client would like the
 * preset loaded.  Different sub-types of  object might have different application
 * objects as well.  For example, both lights and materials are items with the
 * ILxItem interface, but they may be wrapped in another object with the appropriate
 * ILxLightPresetDestination or ILxMaterialPresetDestination interface. Alternatively,
 * the requested interface may in fact be normally preset on the specific objects
 * themselves along with their normal interfaces, thus obviating the need for a
 * special container to wrap them.
 */
typedef struct vt_ILxPresetType1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Recognize) (
        LXtObjectID		  self,
        const char		 *path,
        const LXtGUID		**guid,
        const char		**category);

        LXxMETHOD( LxResult,
Apply) (
        LXtObjectID		  self,
        const char		 *path,
        LXtObjectID		  destination);

        LXxMETHOD( LxResult,
Do) (
        LXtObjectID		  self,
        const char		 *path);

        LXxMETHOD( LxResult,
DoCommandFlags) (
        LXtObjectID		  self,
        const char		 *path,
        int			 *flags);

        LXxMETHOD( LxResult,
Metrics) (
        LXtObjectID		  self,
        const char		 *path,
        int			  flags,
        int			  w,
        int			  h,
        LXtObjectID		  prevMetrics,
        void			**ppvObj);

        LXxMETHOD( LxResult,
GenericThumbnailResource) (
        LXtObjectID		  self,
        const char		 *path,
        const char		**resourceName);

        LXxMETHOD( LxResult,
BaseAspect) (
        LXtObjectID		  self,
        float			 *aspect);
} ILxPresetType1;

/*
 * This method returns an ILxImageID representing the thumbnail of a preset. The
 * dimensions of the thumbnail should be those passed to the ILxPresetBrowserClient's
 * Metrics() method, or smaller if the dimensions requested are larger than the preset
 * can provide.  Returning a larger image is discouraged, but if done it will be
 * scaled down as necessary.  The returned image can be NULL if no thumbnail is
 * available, but if non-NULL it should be AddRef()'ed, as the caller will release it.
 * 
 * The ideal width and height are the native resolution of the thumbnail.  When no
 * new thumbnail is yet available, the browser will temporarily scale the old thumbnail
 * to be no larger than the ideal size.  This avoids popping if the image were to
 * become larger than ideal, then pop back to ideal when the final image comes in.
 * If the thumbnail is computed dynamically and thus has no ideal or maximum size,
 * idealW and idealH can be set to 0.
 * 
 * If the above method fails, this method will be called to get a generic image
 * representing the preset.  The image a named resource that will be looked up
 * from the configs, and will be scaled down as appropriate (it won't be scaled
 * up, only down).  If this also fails, we fall back to the server's
 * GenericThumbnailResource() method.
 * 
 * 
 * Markup is defined by the browser and is generated by the user, and includes things
 * like star ratings, tags and ohter properties.
 * 
 * Servers can also return per-file flags, which indicate special behaviors for the file.
 * These are the same LXiDCFM_ defines used by the DirBrowser.  For example,
 * LXiDCFM_DYNAMIC_THUMBNAILS is commonly set on color presets, since the thumbnail can be
 * quickly generated at an arbitrary size, and thus need not be cached on disk.
 */
typedef struct vt_ILxPresetMetrics {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
ThumbnailImage) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
ThumbnailIdealSize) (
        LXtObjectID		  self,
        int			 *idealW,
        int			 *idealH);
        LXxMETHOD( LxResult,
ThumbnailResource) (
        LXtObjectID		  self,
        const char		**resourceName);
        LXxMETHOD( LxResult,
Metadata) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Markup) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Flags) (
        LXtObjectID		  self,
        int			 *flags);
} ILxPresetMetrics;

typedef struct vt_ILxPresetMetrics1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Label) (
        LXtObjectID		  self,
        const char		**label);

        LXxMETHOD( LxResult,
ThumbnailImage) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD( LxResult,
ThumbnailIdealSize) (
        LXtObjectID		  self,
        int			 *idealW,
        int			 *idealH);

        LXxMETHOD( LxResult,
ThumbnailResource) (
        LXtObjectID		  self,
        const char		**resourceName);

        LXxMETHOD( LxResult,
Caption) (
        LXtObjectID		  self,
        const char		**caption);

        LXxMETHOD( LxResult,
ToolTip) (
        LXtObjectID		  self,
        const char		**tooltip);
} ILxPresetMetrics1;

/*
 * When a file is double-clicked, the Test() method is called to see if the server can handle
 * the preset.  It should return a success code (LXe_OK, for example) if it can handle the
 * file, and a failure code if it can't.
 * Note that this may be passed an empty path when "do on deselect" is set for the browser,
 * allowing the client to do special behaviors when the selection is cleared.
 * 
 * The Do() method is called to actually perform an action on a double-click..  If the server
 * recognizes the file and wants to handle it, it should perform the action and return LXe_OK.
 * Again, this may pass an empty string for the path.
 * 
 */
typedef struct vt_ILxPresetDo {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Test) (
        LXtObjectID		 self,
        const char		*path);
        LXxMETHOD(  LxResult,
Do) (
        LXtObjectID		 self,
        const char		*path);
} ILxPresetDo;

/*
 * The single method returns the hash of the viewport.
 */
typedef struct vt_ILxPresetBrowserSource {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ViewportHash) (
        LXtObjectID		 self,
        char			*buf,
        int			 len);
} ILxPresetBrowserSource;

/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.
 * The packets in a particular subtype can then be walked with the SelClient...()
 * series of functions defined in sel.qq.  The selection client and index together
 * are used to walk a particular list of packets.  There is also a function to
 * listen for events for a specific subtype.
 * Selection should also be done with the select.preset command, and dropped with
 * select.presetDrop.  This ensures that only one subtype is affected.  There is
 * also a special "global" subtype that can be obtained by passing NULL to
 * SubtypeFromIdentifier().  Note that this is not the same as uses the clientless
 * selection functions; the global selection subtype is considered separate from
 * the other subtypes, while the clientless selection functions ignore subtypes
 * and operates on the entire selection.
 * 
 * As described above, this method returns a selection subtype for a given client
 * identifier, which can be any arbitrary string that the client would like to
 * use to identify its sub-selection. If NULL is passed in, then the "global"
 * subtype is returned.  The optional identifier may be used to further narrow
 * the selection down to a specialized client, which is unique and separate from
 * a NULL identifier.  See the LXtPresetPathPacket section for more information
 * on identifiers.
 * 
 * 
 * On the flip side, the client needs to notify the browser when its state changes
 * externally.  This method will update the preset selection if necessary, as well
 * as updating the current path of any preset browser with that identifier so that
 * the current selection is visible there.  The identifier must be non-NULL.
 * Note that this works by executing commands for the normal selection mode.  If
 * in special selection mode, SetSpecialSelModePath() sohuld be used isntead.
 * 
 * 
 * These methods allow the server list to be walked, and allow a server to be
 * looked up by name.  When a COM object is returned, the client is responsible
 * for freeing it as usual.
 * 
 * These methods return the name and username of a server given an index.
 * 
 * 
 * This is identical to RecognizeFile(), but does not use any cached recognized
 * state.
 * 
 * The rescan method is a wrapper for ILxDirCacheService::ScanForChanges(),
 * and updates a single path or the entire cache for any new changes to the
 * files and directories on disk.  If the path provided is NULL, the entire
 * cache is scanned for updates.
 * 
 * 
 * Normally, preset selection is done through the selection system.  However,
 * this requires executing commands, which can limit how the browser is used
 * (such as using the Preset Browser as a clipChoice component).  To handle this,
 * the Preset Browser can be set to a special selection mode that allows only
 * one path to be selected at a time.  This path (given an identifier) can set
 * and read with these methods.
 * Toggling the special selection mode is done with viewport arguments when
 * embedded in a form, or through the viewport preset when in a layout.  Note
 * that when in this mode, the "do" (double-click) behavior and the preset
 * region in general are disabled, as those require executing commands and the
 * selection system.
 * 
 * These functions will always work, even if the a viewport with the identifier
 * doesn't exist or isn't in special selection mode.  This allows the path to
 * be set and read at any time.
 * 
 * When setting, if asInteractive is true, the "do" action associated with
 * browser is executed for the path as though the user had double-clicked it.
 * 
 */
typedef struct vt_ILxPresetBrowserService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
SubtypeFromIdentifier) (
        LXtObjectID		 self,
        const char		*identifier,
        int			*subtype);
        LXxMETHOD(  LxResult,
UpdateIdentifierState) (
        LXtObjectID		 self,
        const char		*identifier,
        const char		*path);
        LXxMETHOD(  LxResult,
ServerCount) (
        LXtObjectID		 self,
        int			*count);

        LXxMETHOD(  LxResult,
ServerByIndex) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
ServerLookup) (
        LXtObjectID		  self,
        const char		 *name,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ServerNameByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**name);

        LXxMETHOD(  LxResult,
ServerUserNameByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**name);
        LXxMETHOD(  LxResult,
RecognizeFile) (
        LXtObjectID		  self,
        const char		 *path,
        int			  flags,
        const char		**serverName,
        const char		**category);
        LXxMETHOD(  LxResult,
RecognizeFileForce) (
        LXtObjectID		  self,
        const char		 *path,
        int			  flags,
        const char		**serverName,
        const char		**category);
        LXxMETHOD(  LxResult,
Rescan) (
        LXtObjectID		 self,
        const char		*path);
        LXxMETHOD(  LxResult,
IsViewportVisible) (
        LXtObjectID		 self,
        const char		*identifier,
        const char		*hash);
        LXxMETHOD(  LxResult,
GetSpecialSelModePath) (
        LXtObjectID		 self,
        const char		*identifier,
        char			*buf,
        int			 len);

        LXxMETHOD(  LxResult,
SetSpecialSelModePath) (
        LXtObjectID		 self,
        const char		*identifier,
        const char		*path,
        int			 asInteractive);
} ILxPresetBrowserService;

typedef struct vt_ILxPBSpecialSelListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
SelChangedAny) (
        LXtObjectID		 self,
        const char		*identifier,
        const char		*path);

        LXxMETHOD( void,
SelChangedInteractiveOnly) (
        LXtObjectID		 self,
        const char		*identifier,
        const char		*path);
} ILxPBSpecialSelListener;


        #define LXiSEL_PRST	LXxID4('P','R','S','T')	// Preset

/*
 * There isn't actually a true ILxPreset interface.  It's really just a construct that
 * exists so we can fit into the ILxLoader system.
 */

        #define LXu_PRESET			"CA09DCB1-4E6B-4cbb-BC5E-378CE759B9E1"
        #define LXa_PRESET			"preset"


        #define LXu_PRESETLOADERTARGET		"3B15936E-11F4-4D4A-8ADC-8310C6D9508E"
        // [local]  ILxPresetLoaderTarget

/*
 * Clients that want to have their contents show up in the preset browser need to
 * register a server with the system.  This is done simply by defining a new plug-in
 * with the ILxPreset interface.
 * This interface is not only used to populate the browser, but also used to actually
 * load and apply presets.
 */

        #define LXu_PRESETTYPE			"ea04c0c2-61af-4f45-b1a1-bce681e8982d"
        #define LXa_PRESETTYPE			"presetType"
        //[export] ILxPresetType ptyp
        //[local]  ILxPresetType
        //[python] ILxPresetType:Metrics	obj PresetMetrics

/*
 * Do() is usally called from a command, but this is often a UI command, and does
 * not contain undo blocks.  Ideally, the server's own Do() method should also call
 * a command with the proper flags for undos or whatnot, and ideally that command
 * would be preset.do.  The idea is that you'd call commands to set up the appropriate
 * state, and then call execute preset.do to do the actual work.  These commands
 * should not involve anything that couldn't be done by simply double-clicking on
 * a preset in the Preset Browser (i.e., no viewport coordinates or other UI-centric
 * things like that).
 * Some presets support scripts that perform special behaviors.  One is to detect
 * that a preset is already applied and that it doesn't need to be applied again.
 * This should not be considered a failure, so we have this special code to indicate
 * this.
 */

        #define LXe_PRESET_ALREADY_APPLIED	LXxGOODCODE( LXeSYS_PRESET, 1 )

/*
 * - DOSPATTERN
 * A pattern string for filenames in Microsoft Windows (really DOS) format.
 * This is typically something like "*.lxp;*.lxp2".  This functionality is identical
 * to the LXsLOD_DOSPATTERN tag used by loaders.
 * - CANAPPLY
 * For a conventional preset, you want to support the Apply() method so that the
 * preset can loaded into an object.  However, the browser can also be used to
 * display other kinds of data that isn't handled like presets, such as images
 * and scenes.  These do not implement the Apply() method, and are skipped by
 * the special preset dummy loader.  ILxPresetBrowserService:RecognizeFile()
 * will also fail to identify these types.  Instead, they area handled as normal
 * DDEXT_FILE drops on the destination.  If this tag is not present, it is assumed
 * to be true, although it can be explicitly set to "true" if desired.  To disable
 * it, set its value to the string "false".
 * - CANDO
 * If present, this flag means that the Do() method is implemented and the file
 * be loaded via a double-click in the preset browse.
 * 
 * - ORDINAL
 * If present, this defines a custom sort order for this server relative to the
 * other servers.  Lower number ordinals are tested first, and the higher ordinal
 * servers are only tested if a lower oridnal server doesn't match.  If two
 * servers have the same ordinal, the sort order is undefined.  If the ordinal tag
 * is not present, the server is given a default ordinal of 127.
 * 
 * - DYNAMICTHUMBNAILS
 * If set, the thumbnail will never be cached on disk and will always be asked to
 * be regenerated when needed.  This is used for simple preset types like colors,
 * which are fast to generate and silly to cache as images on disk.  If you need
 * to set this on a per-file basis, use the ILxPresetMetrics::Flags() method instead.
 * If the tag is not present, it is assumed to be false, although it can be explicitly
 * set to "false" if desired.  To enable it, the value should be "true".
 * 
 * - SYNTHETICSUPPORT
 * If set, the server will be called for both real paths and synthetic paths (ie:
 * paths starting with "[basename]:").  Synthetic files don't actually exist on disk,
 * and will require keying off the path itself or using information provided by the
 * synthetic server that defines the path.  To indicate this support, set the value
 * to "true".
 * 
 */

        #define LXsPBS_CATEGORY			"presettype.category"
        #define LXsPBS_DOSPATTERN		"presettype.dosPattern"
        #define LXsPBS_CANAPPLY			"presettype.canApply"
        #define LXsPBS_CANDO			"presettype.canDo"
        #define LXsPBS_ORDINAL			"presettype.ordinal"
        #define LXsPBS_DYNAMICTHUMBNAILS	"presettype.dynamicThumbnails"
        #define LXsPBS_SYNTHETICSUPPORT		"presettype.syntheticSupport"

/*
 * The metrics method is used to request information about the file.  This may
 * be called multiple times and may be called concurrently.  As such, this method
 * must be thread safe.
 * Such information is requested through the Metrics() method.  The results are returned
 * as an object containing an ILxPresetMetrics interface.  The preset browser expects
 * the returned object to be AddRef()'ed before it is returned, and it will be Release()'ed
 * by the browser when no longer needed.
 * Exactly what kind of information is being requested is determined by the flags
 * argument:
 * 
 * - THUMBNAIL_IMAGE
 * The client should generate a suitable thumbnail, which will be later obtained
 * through ThumbnailImage().
 * 
 * - BASIC_INFO
 * The Label(), Caption() and ToolTip() methods should be initialized so that they
 * can return useful information about the preset, if desired.
 * 
 * - EXTRA_ATTRIBUTES
 * The client should load any state that can be used to return ILxAttributes objects
 * from the Metadata() and Markup() methods, if supported.  Note that the Metrics()
 * object should include the label, caption and tooltip properties, even though
 * those methods exist on the metrics object itself.
 * 
 */

        #define LXiPBMETRICS_THUMBNAIL_IMAGE		0x0001
        #define LXiPBMETRICS_BASIC_INFO			0x0002
        #define LXiPBMETRICS_EXTRA_ATTRIBUTES		0x0004

        #define LXiPBMETRICS_ALL			(LXiPBMETRICS_THUMBNAIL_IMAGE | LXiPBMETRICS_BASIC_INFO | LXiPBMETRICS_EXTRA_ATTRIBUTES)

/*
 * If a flag isn't set, then that data isn't needed -- there's no point spending the
 * time generating a thumbnail if all the browser wants is basic metrics.
 * The metrics method is called with the the path to the image and the desired width
 * and height of the thumbnail.  If there was a previous call to this method for
 * this path, the old metrics object may also be passed in as prevMetrics. The server
 * is expected to return a valid object with an ILxPresetMetrics interface.
 * Note that if prevMetrics is not NULL, the server may use it as a reference.  As
 * of nexus 801, this will always be NULL, but in older versions it may be passed.
 * The server should NOT in-place modify prevMetrics.  This is because the Metrics()
 * method may be called from a thread, and prevMetrics may be in active use; changing
 * it could result in a crash.  An example of using prevMetrics as a reference may be
 * to obtain its thumbnail image, check to see if it matches the requested width and
 * height, and if so then AddRef()'ing it, and storing it in the new metrics structure.
 * Of course, there's no need to even do this if the THUMBNAIL_IMAGE flag isn't set.
 * If the metrics are identical to prevMetrics, you can simply AddRef() it and return
 * it.
 * 
 * If w/h are LXiPBTHUMBSIZE_FULL and LXiPBMETRICS_THUMBNAIL_IMAGE is set, then the
 * full resolution image should be returned.
 * 
 */

        #define LXiPBTHUMBSIZE_FULL		LXiDCE_THUMBSIZE_FULL

/*
 * The old version of this interface was retired in 801, and is missing some of the newer
 * methods and has changes to others.
 */

        #define LXu_PRESETTYPE1		"2ED1F957-16BE-4d83-82A3-BE5AF7821891"
        //[export] ILxPresetType1 ptyp1
        //[local]  ILxPresetType1
        //[python] ILxPresetType1:Metrics	obj PresetMetrics

/*
 * The metrics object is passed to the server's Metrics() method to get information
 * about the file.
 */

        #define LXu_PRESETMETRICS		"3139ccf8-57ee-472c-8dc9-d51f8c0acb6b"
        #define LXa_PRESETMETRICS		"presetmetrics"
        //[export] ILxPresetMetrics pmet
        //[local]  ILxPresetMetrics
        //[python] ILxPresetMetrics:ThumbnailImage	obj Image
        //[python] ILxPresetMetrics:Metadata		obj Attributes
        //[python] ILxPresetMetrics:Markup		obj Attributes

/*
 * The metrics interface can return two objects with ILxAttributes interfaces, one
 * for metadata defined by the preset itself, and one for markup stored in the file
 * by the Preset Browser.
 * Metadata includes properties such as the width and height of an image, the number
 * of polygons in a mesh, etc.  Note that this should also include the label, caption
 * and tooltip as returned from the above methods.
 * Some common metadata includes:
 * 
 * - label (string)
 * The label displayed for the file in the browser in place of the filename.  If
 * not present, the filename without the extension will be used instead, with
 * underscores replaced by spaces.
 * 
 * - caption (string)
 * A very short descriptive text (just a couple of words) normally displayed underneath
 * the thumbnail. For example, color presets use this for the RGB values of the color,
 * while item presets use it for the name of the item type, and image presets use it
 * for the image resolution and bit depth.
 * 
 * - tooltip (string)
 * A tooltip displayed when the user hovers the mouse over the file's thumbnail.
 * If omitted, then a tooltip is automatically generated based on other metadata.
 * 
 * - type (string)
 * A short internal string identifying the kind of preset.  This is for use with filtering
 * and sorting, and so that clients can esaily identify recognized files in the dir cache
 * without having to parse them themselves.  This isn't always present, and it is possible
 * for multiple presets to indicate the same type if they can be used the same way, even
 * if different preset servers handle them.
 * 
 */

        #define LXsPBMETA_LABEL		"label"
        #define LXsPBMETA_CAPTION	"caption"
        #define LXsPBMETA_TOOLTIP	"tooltip"
        #define LXsPBMETA_PRESET_TYPE	"presetType"

/*
 * The old version of this interface was retired in 801, and is missing some of the newer
 * methods.
 */

        #define LXu_PRESETMETRICS1		"79185753-0696-4c54-9daa-fe01253bfc07"
        //[export] ILxPresetMetrics1 pmet1
        //[local]  ILxPresetMetrics1
        //[python] ILxPresetMetrics1:ThumbnailImage	obj Image

/*
 * Double-clicks normally execute the Do() method of the preset type server associated with
 * the preset.  This works for the general preset browser, but there are focused cases where
 * we want overrides.  For example, the MatCap PBView shows images, but double-clicking one
 * should load it as a matcap instead of as a clip.  By implementing an ILxPresetDo server
 * and setting it on the PBView, it can do exactly that.
 */

        #define LXu_PRESETDO		"468f8808-e3cc-40fb-96be-119f91e01b87"
        #define LXa_PRESETDO		"presetdo"
        //[export] ILxPresetDo pdo
        //[local]  ILxPresetDo

/*
 * Dragging from the preset browser is done with LXsDROUPSOURCE_FILES and
 * LXsDROUPSOURCE_FILES_SYNTH.  It also includes an ILxPresetBrowserSource
 * interface to provideo the hash of the browser, mostly for adding the
 * dropped preset to a matching recent list.
 * The metrics object is passed to the server's Metrics() method to get information
 * about the file.
 */

        #define LXu_PRESETBROWSERSOURCE		"cc776670-63a8-4fa9-9618-e369b5a22f62"
        #define LXa_PRESETBROWSERSOURCE		"presebrowsersource"
        //[local]  ILxPresetBrowserSource

/*
 * The global service allows clients to request updates to the browser and walk
 * the server list.
 */

        #define LXu_PRESETBROWSERSERVICE	"05C3FF8F-5C3C-4463-AF6E-439C52621DCA"
        #define LXa_PRESETBROWSERSERVICE	"presetbrowserservice"
        // [python] ILxPresetBrowserService:ServerByIndex	obj PresetType
        // [python] ILxPresetBrowserService:ServerLookup	obj PresetType
        // [python] ILxPresetBrowserService:IsViewportVisible	bool

/*
 * This method scans all of the servers, looking for one that can identify
 * the file.  If successful, it indirectly the name of the server that
 * identified it, although the argument may be NULL if desired.
 * The flags determine what subset of servers will be scanned.  This can
 * inclued servers that have the (now-obsolete) Apply() and/or Do() methods,
 * or all servers.
 */

        #define LXfPRESETRECOGNIZE_CAN_APPLY		0x01
        #define LXfPRESETRECOGNIZE_CAN_DO		0x02

        #define LXiPRESETRECOGNIZE_ALL			0

/*
 * When a preset browser is in special mode, we need a way to tell any clients
 * when the selection changes.  This listener can be used to monitor for changes
 * to any changes to that selection, and provides the identifier and the selected
 * path.
 * There are two methods:  the first reports all changes, including changes made
 * through calls to ILxPresetBrowserService::GetSpecialSelModePath(), while the
 * second one only reports changes made by the user by clicking on a preset in
 * the browser.
 */

        #define LXu_PBSPECIALSELLISTENER	"e278629d-c00f-49c8-9057-f6112b6ae074"
        #define LXa_PBSPECIALSELLISTENER	"presetbrowserspecialsellistener"

#endif
