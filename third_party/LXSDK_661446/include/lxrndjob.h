/*
 * LX rndjob module
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
#ifndef LX_rndjob_H
#define LX_rndjob_H

typedef struct vt_ILxRenderService ** ILxRenderServiceID;
typedef struct vt_ILxRenderJob ** ILxRenderJobID;
typedef struct vt_ILxRenderJob1 ** ILxRenderJob1ID;
typedef struct vt_ILxRenderProgressListener ** ILxRenderProgressListenerID;
typedef struct vt_ILxRenderStats ** ILxRenderStatsID;
typedef struct vt_ILxBuffer ** ILxBufferID;
typedef struct vt_ILxFrameBuffer ** ILxFrameBufferID;
typedef struct vt_ILxImageProcessing ** ILxImageProcessingID;
typedef struct vt_ILxImageProcessingListener ** ILxImageProcessingListenerID;
typedef struct vt_ILxImageProcessingRead ** ILxImageProcessingReadID;
typedef struct vt_ILxImageProcessingService ** ILxImageProcessingServiceID;

#include <lxresult.h>
#include <lxcom.h>
#include <lxvmath.h>
#include <lxitem.h>
#include <lxvector.h>
#include <lxvalue.h>
#include <lximage.h>
#include <lxrender.h>
#include <lxcolormapping.h>

/*
 * See the RenderSettings documentation for details about the individual
 * member variables in the LXtRenderOutputProcess structure.
 * The maximum number of outputs is fixed by RenderSettings, and so a simple,
 * fixed-size array is used in the LXtRenderOutputProcessList structure.
 */

        typedef struct st_Buffer	*LXtBufferID;
        typedef void 			*LXtTileTreeID;



/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.  Since there is currently no ScriptQuery interface, this method
 * will always fail.
 * 
 * The client provides information about how to render a scene with a render job.
 * This is a COM object with an ILxRenderJob interface, as described below.
 * Frames, animations, turntables and baking can be rendered by providing a job
 * to the render service.
 * A specific render job can be set as the current job with this method, or the
 * current job can be set to nothing by passing NULL.  Attempting to set the
 * render job will fail if another job is currently being rendered.  The job
 * provided will be AddRef()'ed by the service.
 * 
 * 
 * This returns the current render job, failing if there is no current job.  The
 * returned object must be released by the caller if the method returns success.
 * 
 * This method can be used to start rendering the current job, using the
 * properties of the job to render the scene.  This function does not block,
 * and will return immediately.  Status updates are sent to various methods
 * on the job object itself.
 * 
 * This aborts a currently running render job.  It will fail if no jobs are
 * currently rendering.  Note that although this function returns immediately,
 * it may take some time before the render has finished aborting.
 * 
 * This returns the current status of a render job as an LxResult code.
 * - LXe_RENDER_IDLE
 * A job is loaded (JobCurrent() would succeed), but is not currently rendering
 * a frame.  The system is effectively idle and waiting for JobStart() to be
 * called, or for a new job to be loaded.
 * 
 * - LXe_RENDER_RENDERING
 * Returns true if the currently loaded job is rendering a frame.
 * 
 * - LXe_RENDER_NO_JOB
 * There is no current current job (and thus JobCurrent() would fail).  A new
 * job must be set with JobSetCurrent() before calling JobStart().
 * 
 * - LXe_RENDER_ABORTING
 * JobAbort() was called and the job is in the process of aborting, but has not
 * yet finished.
 * 
 * 
 * This returns an ILxRenderStats container object containing information about the current
 * render  See the ILxRenderStats description below for more information.  The container and
 * the individual stats objects are dynamically updated while rendering, so you can hold on
 * to the container object for the life of the render.  The object must be released when no
 * longer needed.
 * 
 * Return whether or not the current job is running in slave mode.
 * 
 * This utility can be used to reclaim memory after a render has completed.  If
 * clearJob is true, this also clears out the current job by implicitly calling
 * JobSetCurrent(NULL);
 * 
 * These are used to get the number of outputs and their username strings while
 * a render is in progress.  This information can be used to populate a render outputs
 * popup that the user can change while rendering via the job's ProgressImageMetrics()
 * method.  These methods are only valid while rendering, and will return Lx_ when
 * not.
 * 
 * This related function returns the type of a render output as an LXiRENDEROUTPUT_
 * define.
 * 
 * This causes the render service to call the current job's ProgressImage
 * method with the progress image from the current.
 * 
 * This is used to indicate that the metrics of the progress image need to
 * be refreshed by the client.  The client should then call UpdateProgressImage()
 * to get a new image with the new metrics.
 * 
 * Writes the framebuffer to disk in a proprietary format. The frame buffer
 * can be recalled later on for display to the user.
 * FrameStore and FrameRecall are commonly used in a system to enable
 * reloading previous renders.
 * 
 * FrameStore is called internally before a job's ProgressFrameEnd() method, but
 * can also be called after baking operations that modify the frame buffer pixel
 * colors, to make those changes permanent.
 * 
 * This function should still be called even if Write Buckets To Disk is used, in
 * which case the frame buffer pixels are written to disk separately, and this call
 * will simply write the meta-data that is required to re-load the frame buffer
 * later on.
 * 
 * Once a frame and its pixels has been written to disk, the header can be re-written
 * without affecting the pixels by passing in zero for the writePixels parameter.
 * 
 * 
 * Loads a previously saved frame buffer from disk at the "slot" and "render
 * pass" indices provided and returns an object with an ILxFrameBufferID interface.
 * 
 * Tests if a frame buffer is present on disk at the given slot and pass indices.
 * FrameTestRecall can be called in a loop to get a count of the number of passes by
 * incrementing passIndex until LXe_NOTFOUND is returned.
 * 
 * 
 * This convenience method returns the number of render passes.
 * (The implementation calls FrameTestRecall() with successively larger passIndex values,
 * until FrameTestRecall returns LXe_NOTFOUND.)
 * 
 * 
 * Return the render pass name, size, and number of render outputs of the frame buffer
 * at the given slot and pass indices.
 * If the slot or pass is not found, FrameRenderPassInfo returns LXe_NOTFOUND.
 * 
 * 
 * Return the same information as the FrameRenderPassInfo function, along with the
 * persistent values that are saved for the render outputs of the frame buffer at
 * the given slot and pass indices, in a LXtRenderOutputProcessList structure.
 * The actual pixels are not read in, so this function can be much faster than obtaining
 * render output info through the full FrameRecall function.
 * 
 * 
 * Save a frame buffer to disk as a simple image or a layered image.
 * 
 * Save a frame buffer to disk as a layered image, only for its own pass.
 * 
 * Save a frame buffer to disk as a simple image or a layered image,
 * for each render pass at the given slot index.
 * 
 * These methods are used to save and load the stats for a frame buffer.
 * The stats are reprresented by an object with an ILxRenderStats interface.
 * The object returned by FrameRecallStats() must be released by the caller
 * when it is no longer needed.
 * Stats are automatically stored by the renderer, so clients won't usually
 * need to call FrameStoreStats().  FrameRecallStats() is more useful, and
 * will return an ILxRenderStats object with stats for the entire render on
 * that frame buffer.  FrameDelete() will delete the stats file as well.
 * 
 * These methods are thread safe.
 * 
 * 
 * Clients can also save a thumbnail image for each slot.  This image may be
 * any size, but something like 256x256 is commonly used.  The thumbnail is
 * indented to be used to populate a browser without needing to load the entire
 * frame buffer into memory.  The thumbnail is saved as a sidecar file to the
 * frame buffer.
 * These methods are thread safe.  Note that the renderer does not save a
 * thumbnail itself; it is up to the client if they want to save a thumbnail.
 * These methods just provide an easy way to assocaite a thumbnail with a
 * frame buffer.  FrameDelete() will delete the thumbnail as well.
 * 
 * When loading a thumbanil with FrameRecallThumbnail(), the caller is
 * responsible for freeing the image when it is no longer needed.
 * 
 * 
 * Delete the frame buffer file at the given slot index.  This also deletes
 * associated data, such as stats files and thumbnails.
 * 
 * This function returns the Effect name from a given render type value. 
 * e.g LXiRENDEROUTPUT_FINALCOLOR to "shader.color"
 * 
 * This function returns type for a given effect name and the number of components. 
 * For instance, "alpha" will have one component, whereas "shade.color" will have 3.
 */
typedef struct vt_ILxRenderService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
JobSetCurrent) (
        LXtObjectID		  self,
        LXtObjectID		  job);
        LXxMETHOD(  LxResult,
JobCurrent) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
JobStart) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
JobAbort) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
JobStatus) (
        LXtObjectID		  self);

        LXxMETHOD(  LXtObjectID,
JobStats) (
        LXtObjectID		  self);

        LXxMETHOD(  int,
JobIsSlave) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
JobCleanup) (
        LXtObjectID		  self,
        int			  clearJob);

        LXxMETHOD(  LxResult,
JobRenderOutputCount) (
        LXtObjectID		  self,
        int			 *count);

        LXxMETHOD(  LxResult,
JobRenderOutputName) (
        LXtObjectID		  self,
        int			  index,
        const char		**name);

        LXxMETHOD(  LxResult,
JobRenderOutputType) (
        LXtObjectID		  self,
        int			  index,
        int			 *type);
        LXxMETHOD(  LxResult,
UpdateProgressImage) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
RefreshProgressImageMetrics) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
FrameStore) (
        LXtObjectID		 self,
        LXtObjectID		 frameBuffer,
        int			 writePixels);

        LXxMETHOD(  LxResult,
FrameRecall) (
        LXtObjectID		  self,
        int			  slotIndex,
        int			  passIndex,
        LXtObjectID		  monitor,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
FrameTestRecall) (
        LXtObjectID		  self,
        int			  slotIndex,
        int			  passIndex);

        LXxMETHOD(  LxResult,
FrameRenderPassCount) (
        LXtObjectID		  self,
        int			  slotIndex,
        int			 *numPasses);

        LXxMETHOD(  LxResult,
FrameRenderPassInfo) (
        LXtObjectID		 self,
        int			 slotIndex,
        int			 passIndex,
        char			*name,
        unsigned		*width,
        unsigned		*height,
        unsigned		*outputCount,
        int			*isStereo,
        LXtStereoEye		*eyeDisplay,
        LXtStereoComposite	*stereoComposite);

        LXxMETHOD(  LxResult,
FrameRenderPassOutputInfo) (
        LXtObjectID		 self,
        int			 slotIndex,
        int			 passIndex,
        char			*renderPassName,
        unsigned		*width,
        unsigned		*height,
        LXtRenderOutputProcessList	*outputs);

        LXxMETHOD(  LxResult,
FrameSaveImage) (
        LXtObjectID		  self,
        LXtObjectID		  framebuffer,
        int			  bufferIndex,
        const char		 *filename,
        const char		 *format,
        LXtObjectID		  message,
        LXtObjectID		  monitor);

        LXxMETHOD(  LxResult,
FrameSaveLayered) (
        LXtObjectID		  self,
        LXtObjectID		  framebuffer,
        const char		 *filename,
        const char		 *format,
        LXtObjectID		  message,
        LXtObjectID		  monitor);

        LXxMETHOD(  LxResult,
FrameSavePassLayered) (
        LXtObjectID		  self,
        LXtObjectID		  framebuffer,
        const char		 *filename,
        const char		 *format,
        LXtObjectID		  message,
        LXtObjectID		  monitor);

        LXxMETHOD(  LxResult,
FrameSavePassesAsImages) (
        LXtObjectID		  self,
        int			  slotIndex,
        const char		 *filename,
        const char		 *format,
        LXtObjectID		  message,
        LXtObjectID		  monitor);

        LXxMETHOD(  LxResult,
FrameSavePassesAsLayeredImages) (
        LXtObjectID		  self,
        int			  slotIndex,
        const char		 *filename,
        const char		 *format,
        LXtObjectID		  message,
        LXtObjectID		  monitor);

        LXxMETHOD(  LxResult,
FrameStoreStats) (
        LXtObjectID		  self,
        int			  slotIndex,
        LXtObjectID		  stats);

        LXxMETHOD(  LxResult,
FrameRecallStats) (
        LXtObjectID		  self,
        int			  slotIndex,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
FrameStoreThumbnail) (
        LXtObjectID		  self,
        int			  slotIndex,
        LXtObjectID		  image);

        LXxMETHOD(  LxResult,
FrameRecallThumbnail) (
        LXtObjectID		  self,
        int			  slotIndex,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
FrameDelete) (
        LXtObjectID		  self,
        int			  slotIndex);

        LXxMETHOD( LxResult,
RenderEffectFromRenderType) (
        LXtObjectID		self,	
        int			type,
        const char**		effectName );
        LXxMETHOD( LxResult,
RenderEffectToType) (
        LXtObjectID		self,	
        const char*		effect,
        int*			type,
        int*			size );
} ILxRenderService;

/*
 * This method returns the render item, which in turn contains the various
 * settings for this scene. The item will be released by the caller, so be
 * sure to AddRef() it before returning it.
 * This returns the name of the action used to evaluate the scene's
 * channels.
 * 
 * This returns the name of the group whose layers should be rendered.
 * If not implemented (or if the group string is NULL or the method fails),
 * everything is rendered.
 * 
 * 
 * If the mode is FRAME or one of the TURNTABLEs, the RenderAtTime() method
 * will be called to get the scene time in seconds at which to render.  If not
 * implemented, the renderer will use the current scene time, whatever that may
 * be.
 * 
 * This determines how many frames are rendered when using one of the TURNTABLE
 * modes.  If not implemented, the default of 30 frames is used.
 * 
 * This determines the frame rate of the TURNTABLE-style animation when
 * rendering to a movie format.  If not implemented, it will default to
 * the current system frame rate.
 * 
 * This returns the name of the vertex map used when using one of the
 * BAKE render types.  This should be a UV map when using texture baking.
 * 
 * This returns the look distance used when baking.
 * 
 * When baking to a texture, this sets which texture item that is used.
 * If the texture item needs to be included in the bake, 'include' should be set to true.
 * The object should be AddRef()'ed when returned, as the caller will
 * release it.
 * 
 * When baking to a texture, this determines the baking effect.  These
 * effects are the same as used by texture layers.  LXs_FX_NORMAL,
 * LXs_FX_DISPLACE and LXs_FX_VECDISPLACE are common effects.
 * 
 * When baking to a texture, this is the ILxImageID that will contain the
 * result of the bake.  The caller will release the object when it is done
 * with it.  This object must have both ILxImage and ILxImageWrite interfaces.
 * 
 * The TestItem() method returns LXe_FASLE if the item should be ignored, LXe_TRUE 
 * if it should be rendered, or LXe_RENDER_BAKE_TARGET if it's the target of a bake.
 * If the method is not implemented, all visible items will return TRUE. An 
 * evaluation context is also provided as an object with an ILxChannelRead interface,
 * which allows the job to evaluate the scene for states like the item visibility 
 * channel.
 * 
 * This determines what "slot" is used to store the frame buffer on disk.
 * The slot index can be arbitrary (although it must be positive), and is
 * used as part of the frame buffer's filename.  If this method fails or
 * is not implemented, slot zero is used.  The frame buffer represents
 * the raw rendered frame, and should not be confused with the OutputFormat()
 * and OutputFilename() methods, which save the frame buffer as a standard
 * image file.
 * 
 * This determines what "slot" is used as the background of a region
 * render.  Region renders are sub-sets of a frame, and are often composited
 * over another render for display in a render window.  If this method is
 * not implemented or otherwise fails, no backgorund frame buffer is displayed
 * under the region.
 * 
 * This method returns the file format to save the rendered image in as a
 * string, and may be a layered format, or a movie format if rendering an
 * animation.  If it returns LXe_RENDER_USE_OUTPUT_ITEMS, the output items
 * in the scene will be used for the format.  If it returns
 * LXe_RENDER_WITHOUT_SAVING, no images will be saved.
 * 
 * This returns the filename to save the rendered image. to.  Returning
 * LXe_RENDER_USE_OUTPUT_ITEMS will cause the filenames set in the output
 * items to be used.  Returning LXe_RENDER_WITHOUT_SAVING will cause no
 * images to be saved.
 * 
 * 
 * These methods are called as the scene renders to provide status updates.  These
 * methods do not need to be implemented.
 * This method is called if the render is aborted or fails for any reason.
 * 
 * 
 * These methods are called when a render begins or ends.  All other progress messages
 * will be sent between these two calls.  ProgressBegin() is provided with the
 * ILxRenderStats representing all of the stats for the render.  It is initially empty,
 * will be populated as frames and render passes start to render.  This object may be
 * AddRef()'ed if desired, so that it can be used throughout the render and afterward.
 * This object is identical to the one returned by ILxRenderService::JobStats()
 * 
 * ProgressEnd() is provided with an ILxAttributesID representing the final stats for
 * the scene, as well as the IlxFrameBufferID for the last frame rendered.  These
 * objects may be AddRef()'ed if desired.  Note that the ILxFrameBuffer may be NULL
 * if the render was aborted or otherwise failed.
 * 
 * While rendering, this is called with the current progress of the render
 * as a number between 0.0 and 1.0.  The render can be canceled by returning
 * LXe_ABORT.
 * 
 * Before rendering a frame, the job is asked for the desired resolution of the
 * progress image, as well as any zoom factor or panning offset within the image.
 * These metrics can be changed at an time by calling
 * ILxRenderService::RefreshProgressImageMetrics(), which in turn will call
 * ProgressImageMetrics() and UpdateProgressImage().
 * resX and resH are the actual dimensions of the rendered image.
 * 
 * Setting w and h to 0 will result in no progress image, as would returning
 * LXe_RENDER_NO_PROGRESS_IMAGE or not implementing the method.
 * 
 * w and h are the maximum size of the progress image itself.  The image may be
 * smaller than this depending on the zoom factor, but will never be larger.
 * 
 * zoom determines the zoom factor within the image, with 1.0 is 100%.
 * 
 * panX and panY are offsets into the image, and are used to pan around it when
 * the render is larger than w/h.
 * 
 * output is the index of the render output that is drawn into the progress
 * image.  A list of outputs in the current render can be obtained from
 * ILxRenderService::JobRenderOutputCount() and JobRenderOutputName().  If
 * the output is -1 or otherwise out of range, the current/default output is
 * used instead.
 * 
 * 
 * We have a series of begin/end pairs indicating which frame, render pass and
 * sub-frame pass that is currently being rendered.  The hierarchy is like so:
 * - ProgressBegin()			Begin rendering
 * - - ProgressFrameBegin()		Begin rendering a frame
 * - - - ProgressRenderPassBegin()		Begin rendering a pass of a frame
 * - - - - ProgressFramePassBegin()	Begin rendering a sub-frame pass within a frame
 * - - - - ProgressFramePassEnd()		Finish rendering a sub-frame pass witihn a frame
 * - - - ProgressRenderPassEnd()		Finish rendering a passes of a frame
 * - - ProgressFrameEnd()			Finish rendering a frame
 * - ProgressEnd()				Finish rendering
 * 
 * This is called when an individual frame within a pass begins rendering.
 * The frame number and eye (for stereoscopic rendering) is sent to both
 * methods.  The width and height of the frame are also provided to the
 * Begin() method, which may prove useful when setting up a render progress
 * window.
 * 
 * 
 * When a frame finishes rendering, this method is called with the frame,
 * eye, and an object with an ILxAttributes interface.
 * The ILxAttributes object provides statistics representing the final
 * state of the frame. This object can be AddRef()'ed by the job and held
 * onto for future use, if so desired.  The frame buffer is not provided
 * as each pass in the frame has its own unique frame buffer.
 * 
 * 
 * Note that the renderPassName may be NULL if the pass is unnamed.
 * 
 * The frame is further broken down into frame passes (not to be confused with
 * render passes).  These methods are called when a frame pass begins or ends.
 * 
 * Individual buckets are rendered within each frame pass.  These methods
 * are called when a bucket starts or ends, and must be thread safe.  Note
 * that multiple buckets may be rendered at the same time, and thus multiple
 * begin calls may occur before an end call is received.
 * When a bucket begins, this method is called with the row and column of
 * the bucket passed, (where 0,0 is the top-left corner).
 * 
 * 
 * This is called when the bucket ends.  The bucket index is provided along
 * with an LxResult code specifying how the bucket finished.  This can be an
 * OK code for success, LXe_ABORT for a user abort or a failure code.  Note that
 * ProgressAbort() will still be called from the main thread when a LXe_ABORT
 * is sent to ProgressBucketEnd().
 * 
 * As the render progresses, this function is called with a status string,
 * which the client can display in its UI.  The first string provided is
 * an internal string, while the second is a user-readable, translated
 * string.  Note that an empty info string/user string is valid, and usually
 * just means that the any previous string can now be cleared as it is no
 * longer relevant.
 * 
 * Every time a pixel is rendered, the progress image (an object with the
 * ILxImageID interface) is updated.  This image is created when a frame
 * starts rendering, and is passed to the job through this method.  The
 * job can hold onto this image for redrawing by incrementing its reference
 * count.  This image should be considered read-only, The image dimensions
 * may be smaller than the actual render resolution.
 * If the image's dimensions have changed (due to a call to RefreshProgressImageMetrics()),
 * this may be called during a render.  The client should AddRef() the image
 * so they can draw it in the future.
 * 
 * 
 * The progress image is updated frequently during the render, and the job
 * is notified of this through the ProgressImageUpdated() method.  Since
 * this may be called very frequently, so you'll likely want to use this
 * method to set a "dirty" flag in your UI, and actually redraw your UI
 * only a few times a second.
 * This is sent only when the contents of the image previously sent via
 * ProgressImage() have changed.  If the dimmensions of the image have
 * changed, ProgressImage() will be called again, rather than
 * ProgressImageUpdate().
 * 
 * 
 * It is common from render jobs to present an interactive UI.  To keep the
 * render from locking out the UI when both are in the same thread, the job
 * can implement the "tickle" method.  This method is called frequently enough
 * (about 8 times a second) to allow a UI to check for input without causing
 * undue overhead.
 * The job can abort the render by returning LXe_ABORT.
 * 
 * 
 * This returns the name of the vertex map used when doing cage baking.
 * This should be a morph vmap.
 * 
 * This returns the bake item: baking can be controlled by baking items which contains
 * information about the render target, UV name and all that.
 * 
 * This returns the UDIM tile to bake to. This value causes the bake region to be
 * overridden with this UDIM tile (but only if it's a valid UDIM number).
 * 
 * When baking to a texture, this returns the mode of baking to RGBA channels of the texture
 * 
 * When baking to a texture, this returns the mode of baking from RGBA channels of source frames
 */
typedef struct vt_ILxRenderJob {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
RenderItem) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ActionName) (
        LXtObjectID		  self,
        const char		**action);
        LXxMETHOD(  LxResult,
GroupName) (
        LXtObjectID		  self,
        const char		**group);
        LXxMETHOD(  LxResult,
RenderAs) (
        LXtObjectID		  self,
        int			 *mode);
        LXxMETHOD(  LxResult,
RenderAtTime) (
        LXtObjectID		  self,
        double			 *time);
        LXxMETHOD(  LxResult,
RenderTurntableNumFrames) (
        LXtObjectID		  self,
        int			 *numFrames);
        LXxMETHOD(  LxResult,
RenderTurntableFPS) (
        LXtObjectID		  self,
        int			 *fps);
        LXxMETHOD(  LxResult,
RenderBakeVMap) (
        LXtObjectID		  self,
        const char		**vmap);
        LXxMETHOD(  LxResult,
RenderBakeLookDistance) (
        LXtObjectID		  self,
        double			 *distance);
        LXxMETHOD(  LxResult,
RenderBakeItem) (
        LXtObjectID		  self,
        int			*include,
        void			**item);
        LXxMETHOD(  LxResult,
RenderBakeEffect) (
        LXtObjectID		  self,
        const char		**effect);
        LXxMETHOD(  LxResult,
RenderBakeImage) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
TestItem) (
        LXtObjectID		  self,
        LXtObjectID		  item,
        LXtObjectID		  eval);
        LXxMETHOD(  LxResult,
FrameBufferSlot) (
        LXtObjectID		  self,
        int			 *index);
        LXxMETHOD(  LxResult,
FrameBufferRegionBackgroundSlot) (
        LXtObjectID		  self,
        int			 *slotIndex,
        int			 *passIndex);
        LXxMETHOD(  LxResult,
OutputFormat) (
        LXtObjectID		  self,
        const char		**format);
        LXxMETHOD(  LxResult,
OutputFilename) (
        LXtObjectID		  self,
        const char		**filename);
        LXxMETHOD(  LxResult,
Options) (
        LXtObjectID		  self,
        int			 *options);
        LXxMETHOD(  LxResult,
ProgressAborted) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
ProgressBegin) (
        LXtObjectID		  self,
        LXtObjectID		  renderStats);
        LXxMETHOD(  LxResult,
ProgressEnd) (
        LXtObjectID		  self,
        LXtObjectID		  finalFrameBuffer,
        LXtObjectID		  finalStats);
        LXxMETHOD(  LxResult,
ProgressPercentDone) (
        LXtObjectID		  self,
        double			  progressScene,
        double			  progressFrame,
        double			  progressRenderPass);
        LXxMETHOD(  LxResult,
ProgressImageMetrics) (
        LXtObjectID		  self,
        int			  resX,
        int			  resH,
        int			 *w,
        int			 *h,
        double			 *zoom,
        int			 *panX,
        int			 *panY,
        int			 *output);
        LXxMETHOD(  LxResult,
ProgressFrameBegin) (
        LXtObjectID		  self,
        int			  frame,
        int			  w,
        int			  h);
        LXxMETHOD(  LxResult,
ProgressFrameEnd) (
        LXtObjectID		  self,
        int			  frame,
        LXtObjectID		  stats);
        LXxMETHOD(  LxResult,
ProgressRenderPassBegin) (
        LXtObjectID		  self,
        int			  frameIndex,
        int			  renderPassIndex,
        const char		 *renderPassName,
        int			  eye);

        LXxMETHOD(  LxResult,
ProgressRenderPassEnd) (
        LXtObjectID		  self,
        int			  frame,
        int			  renderPassIndex,
        const char		 *renderPassName,
        int			  eye,
        LXtObjectID		  frameBuffer,
        LXtObjectID		  stats);
        LXxMETHOD(  LxResult,
ProgressFramePassBegin) (
        LXtObjectID		  self,
        int			  frame,
        int			  renderPass,
        int			  eye,
        int			  pass);

        LXxMETHOD(  LxResult,
ProgressFramePassEnd) (
        LXtObjectID		  self,
        int			  frame,
        int			  renderPass,
        int			  eye,
        int			  pass);
        LXxMETHOD(  LxResult,
ProgressBucketBegin) (
        LXtObjectID		  self,
        int			  row,
        int			  col);
        LXxMETHOD(  LxResult,
ProgressBucketEnd) (
        LXtObjectID		  self,
        int			  row,
        int			  col,
        LxResult		  code);
        LXxMETHOD(  LxResult,
ProgressString) (
        LXtObjectID		  self,
        const char		 *infoString,
        const char		 *userString);
        LXxMETHOD(  LxResult,
ProgressImage) (
        LXtObjectID		  self,
        LXtObjectID		  img);
        LXxMETHOD(  LxResult,
ProgressImageUpdated) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
ProgressTickle) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
RenderBakeCageVMap) (
        LXtObjectID		  self,
        const char		**vmap);
        LXxMETHOD(  LxResult,
BakeItem) (
        LXtObjectID		  self,
        void		**item);
        LXxMETHOD(  LxResult,
UDIM) (
        LXtObjectID		  self,
        int			 *udim);
        LXxMETHOD(  LxResult,
RenderBakeToRGBA) (
        LXtObjectID		  self,
        int			 *mode);
        LXxMETHOD(  LxResult,
RenderBakeFromRGBA) (
        LXtObjectID		  self,
        int			 *mode);
} ILxRenderJob;

typedef struct vt_ILxRenderJob1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
RenderItem) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
ActionName) (
        LXtObjectID		  self,
        const char		**action);

        LXxMETHOD(  LxResult,
GroupName) (
        LXtObjectID		  self,
        const char		**group);

        LXxMETHOD(  LxResult,
RenderAs) (
        LXtObjectID		  self,
        int			 *mode);

        LXxMETHOD(  LxResult,
RenderAtTime) (
        LXtObjectID		  self,
        double			 *time);

        LXxMETHOD(  LxResult,
RenderTurntableNumFrames) (
        LXtObjectID		  self,
        int			 *numFrames);

        LXxMETHOD(  LxResult,
RenderTurntableFPS) (
        LXtObjectID		  self,
        int			 *fps);

        LXxMETHOD(  LxResult,
RenderBakeVMap) (
        LXtObjectID		  self,
        const char		**vmap);

        LXxMETHOD(  LxResult,
RenderBakeLookDistance) (
        LXtObjectID		  self,
        double			 *distance);

        LXxMETHOD(  LxResult,
RenderBakeItem) (
        LXtObjectID		  self,
        int			*include,
        void			**item);

        LXxMETHOD(  LxResult,
RenderBakeEffect) (
        LXtObjectID		  self,
        const char		**effect);

        LXxMETHOD(  LxResult,
RenderBakeImage) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
TestItem) (
        LXtObjectID		  self,
        LXtObjectID		  item,
        LXtObjectID		  eval);

        LXxMETHOD(  LxResult,
FrameBufferSlot) (
        LXtObjectID		  self,
        int			 *index);

        LXxMETHOD(  LxResult,
FrameBufferRegionBackgroundSlot) (
        LXtObjectID		  self,
        int			 *slotIndex,
        int			 *passIndex);

        LXxMETHOD(  LxResult,
OutputFormat) (
        LXtObjectID		  self,
        const char		**format);

        LXxMETHOD(  LxResult,
OutputFilename) (
        LXtObjectID		  self,
        const char		**filename);

        LXxMETHOD(  LxResult,
Options) (
        LXtObjectID		  self,
        int			 *options);

        LXxMETHOD(  LxResult,
ProgressAborted) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
ProgressBegin) (
        LXtObjectID		  self,
        LXtObjectID		  renderStats);

        LXxMETHOD(  LxResult,
ProgressEnd) (
        LXtObjectID		  self,
        LXtObjectID		  finalFrameBuffer,
        LXtObjectID		  finalStats);

        LXxMETHOD(  LxResult,
ProgressPercentDone) (
        LXtObjectID		  self,
        double			  progressScene,
        double			  progressFrame,
        double			  progressRenderPass);

        LXxMETHOD(  LxResult,
ProgressImageMetrics) (
        LXtObjectID		  self,
        int			  resX,
        int			  resH,
        int			 *w,
        int			 *h,
        double			 *zoom,
        int			 *panX,
        int			 *panY,
        int			 *output);

        LXxMETHOD(  LxResult,
ProgressFrameBegin) (
        LXtObjectID		  self,
        int			  frame,
        int			  w,
        int			  h);

        LXxMETHOD(  LxResult,
ProgressFrameEnd) (
        LXtObjectID		  self,
        int			  frame,
        LXtObjectID		  stats);

        LXxMETHOD(  LxResult,
ProgressRenderPassBegin) (
        LXtObjectID		  self,
        int			  frameIndex,
        int			  renderPassIndex,
        const char		 *renderPassName,
        int			  eye);

        LXxMETHOD(  LxResult,
ProgressRenderPassEnd) (
        LXtObjectID		  self,
        int			  frame,
        int			  renderPassIndex,
        const char		 *renderPassName,
        int			  eye,
        LXtObjectID		  frameBuffer,
        LXtObjectID		  stats);

        LXxMETHOD(  LxResult,
ProgressFramePassBegin) (
        LXtObjectID		  self,
        int			  frame,
        int			  renderPass,
        int			  eye,
        int			  pass);

        LXxMETHOD(  LxResult,
ProgressFramePassEnd) (
        LXtObjectID		  self,
        int			  frame,
        int			  renderPass,
        int			  eye,
        int			  pass);

        LXxMETHOD(  LxResult,
ProgressBucketBegin) (
        LXtObjectID		  self,
        int			  row,
        int			  col);

        LXxMETHOD(  LxResult,
ProgressBucketEnd) (
        LXtObjectID		  self,
        int			  row,
        int			  col,
        LxResult		  code);

        LXxMETHOD(  LxResult,
ProgressString) (
        LXtObjectID		  self,
        const char		 *infoString,
        const char		 *userString);

        LXxMETHOD(  LxResult,
ProgressImage) (
        LXtObjectID		  self,
        LXtObjectID		  img);

        LXxMETHOD(  LxResult,
ProgressImageUpdated) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
ProgressTickle) (
        LXtObjectID		  self);

        LXxMETHOD(  LxResult,
RenderBakeCageVMap) (
        LXtObjectID		  self,
        const char		**vmap);
} ILxRenderJob1;

typedef struct vt_ILxRenderProgressListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Begin) (
        LXtObjectID		 self );
        LXxMETHOD( void,
End) (
        LXtObjectID		 self,
        LXtObjectID		 stats );
} ILxRenderProgressListener;

/*
 * This returns the number of frames in the render.
 * 
 * This returns the number of passes per frame.  Under normal circumstances
 * all frames will have the same number of passes, but if the render is in
 * progress or aborted the last frame (the one currently being rendered) may
 * not yet have stats for all of its passes (ie: the ones not yet rendered).
 * 
 * This can be used to get the ILxAttributes object for a particular pass.
 * Frames and passes are referenced by index. not by frame number or pass
 * name or anything like that.  As usual, the object must be released when
 * no longer needed.
 * 
 * This convenience function gets the stats representing an entire frame
 * (ie: the last pass in the frame).  As usual, the object must be released
 * when no longer needed.
 * 
 * This similarly gets the stats representing the entire scene (ie: the
 * last pass in the last frame).  As usual, the object must be released
 * when no longer needed.
 */
typedef struct vt_ILxRenderStats {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
NumFrames) (
        LXtObjectID		  self,
        int			 *count);
        LXxMETHOD(  LxResult,
NumPasses) (
        LXtObjectID		  self,
        int			  frameIndex,
        int			 *count);
        LXxMETHOD(  LxResult,
GetPassStats) (
        LXtObjectID		  self,
        int			  frameIndex,
        int			  passIndex,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
GetFrameStats) (
        LXtObjectID		  self,
        int			  frameIndex,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
GetSceneStats) (
        LXtObjectID		  self,
        void			**ppvObj);
} ILxRenderStats;

/*
 * 
 * Render buffers have a vector type which tells the renderer which packets it
 * expects from the sample vector.
 * 
 * This method allocates the buffer itself given its width and height.  While
 * you can theoretically have buffers with different sizes in the same frame
 * buffer, in practice they are all the same size.
 * 
 * This returns the width and height of the buffer.
 * 
 * Set the current eye side to left or right.
 * This function only works with buffers contained within stereo frame buffers.
 * 
 * 
 * This method clears the pixel at the given coordinates.
 * 
 * This method is called when the sample vector is complete and ready to be
 * recorded to the render buffers.  The job of this function is to get the
 * packet(s) from the vector and to convert it into values that will be set into
 * the buffer at the given pixel coordinates with the given blend value.
 * 
 * This method returns a pointer to the pixel of coordinates (x, y).
 * 
 * This method returns a pointer to the array of pixels at line y.
 * 
 * This method returns the buffer name's internal name, and can be
 * used for lookup or other similar purposes.
 * 
 * These methods set and retrieve the username for the buffer.  This
 * should be a string obtained from a message table so that it can be
 * translated.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
typedef struct vt_ILxBuffer {
        ILxUnknown	 iunk;
        LXxMETHOD(  void,
SetFlags) (
        LXtObjectID		 self,
        int			 flags);

        LXxMETHOD(  int,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD(  unsigned,
DataType) (
        LXtObjectID		 self);

        LXxMETHOD(  LXtObjectID,
VectorType) (
        LXtObjectID		 self);

        LXxMETHOD(  void,
SetSize) (
        LXtObjectID		 self,
        int			 width,
        int			 height,
        int			 writeBucketsToDisk,
        int			 isStereo);

        LXxMETHOD(  void,
GetSize) (
        LXtObjectID		 self,
        int			*width,
        int			*height);

        LXxMETHOD(  LxResult,
SetEyeSide) (
        LXtObjectID		 self,
        int			 eyeSide);
        LXxMETHOD(  void,
Clear) (
        LXtObjectID		 self,
        int			 x,
        int			 y);
        LXxMETHOD(  LxResult,
Convert) (
        LXtObjectID		 self,
        LXtGenVectorID		 gv,
        int			 x,
        int			 y,
        float			 blend);
        LXxMETHOD(  void *,
Pixel) (
        LXtObjectID		 self,
        int			 x,
        int			 y);
        LXxMETHOD(  void *,
Line) (
        LXtObjectID		 self,
        int			 y);

        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  LxResult,
SetUserName) (
        LXtObjectID		 self,
        const char		*name);

        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  LxResult,
CreateImageTileTree) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
DestroyImageTileTree) (
        LXtObjectID		 self);

        LXxMETHOD(  LXtTileTreeID,
GetImageTileTree) (
        LXtObjectID		 self);

        LXxMETHOD(  size_t,
GetImageTileTreeSize) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
ResetImageTileTree) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
IncrementTileTreeSize) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
DecrementTileTreeSize) (
        LXtObjectID		 self);

} ILxBuffer;

/*
 * Allocating a render buffer is done by name and an optional identity.
 * An item may be optionally set to create a buffer specific to the given item.
 * 
 * For instance, the 'goo' shader may have created its own buffer definition and
 * the 'goo' shader on the 'xxx' material may want to have its own 'goo.xxx' buffer.
 * 
 * If the buffer has already been created it is simply returned.
 * 
 * 
 * Check if a given frame buffer is rendered with stereo outputs.
 * 
 * Get the stereo eye display mode (left, right, or both).
 * 
 * Set the stereo eye display mode (left, right, or both).
 * 
 * Set the stereo compositing style (anaglyph, side-by-side, etc.)
 * 
 * Set the stereo compositing style (anaglyph, side-by-side, etc.)
 * 
 * Set the current eye side to left or right.
 * This function only works with buffers contained within stereo frame buffers.
 * 
 * 
 * 
 * When creating images that will be targets for image processing, call
 * CreateFrameBufferTargetImage to prepare the image, which takes care of
 * stereo handling depending on the stero image processing settings.
 * 
 * Return the name of the render pass associated with the frame buffer.
 * If the pass name is not set, the returned name is empty.
 * 
 * 
 * Set the name of the render pass associated with the frame buffer.
 * 
 * 
 * This returns the render buffer of the given name and item in the frame buffer.
 * 
 * This returns the render buffer of the given identity in the frame buffer.
 * 
 * Returns the total number of buffers.
 * 
 * Returns the buffer given its index in the list.
 * 
 * Return the buffer for the associated alpha channel (if any).
 * 
 * Return the index of the buffer for the alpha channel associated with the
 * color buffer at the given index (if any).
 * 
 * Return the width and height of the buffer at the given index.
 * 
 * 
 * Return if images should be saved with post-processing applied.
 * 
 * Set if images should be saved with post-processing applied.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Arbitrary attributes may be added to frame buffer objects.  These can be
 * read and set using the image ILxAttributes interface.
 * This function allows a client to add an attribute to an ILxFrameBuffer object by
 * providing an attribute name and an exotype name.  If the attribute has been
 * added successfully, its index will be returned.
 * 
 * 
 * This function allocates a RenderOutputProcess for a given buffer index.
 * Clients can use this to find out more information for a given render output.
 * Because we need to allocate the render output process, don't forget to deallocate as well 
 * with the RenderProcessDeallocate call
 * 
 * This function frees the memory allocated for the render Process requested with
 * RenderProcessAllocate. This is because we might make changes to the renderprocess struct
 * in future versions
 */
typedef struct vt_ILxFrameBuffer {
        ILxUnknown	 iunk;
        LXxMETHOD(  ILxBufferID,
Allocate) (
        LXtObjectID		 self,
        const char		*name,
        LXtObjectID		 item,
        const char		*identity,
        const char		*userName,
        int			 isFactoryName,
        int			 writeBucketsToDisk);

        LXxMETHOD(  LxResult,
IsStereo) (
        LXtObjectID		 self,
        int			*isStereo);

        LXxMETHOD(  LxResult,
GetStereoEyeDisplay) (
        LXtObjectID		 self,
        LXtStereoEye		*eyeDisplay);

        LXxMETHOD(  LxResult,
SetStereoEyeDisplay) (
        LXtObjectID		 self,
        LXtStereoEye		 eyeDisplay);

        LXxMETHOD(  LxResult,
GetStereoComposite) (
        LXtObjectID		 self,
        LXtStereoComposite	*composite);

        LXxMETHOD(  LxResult,
SetStereoComposite) (
        LXtObjectID		 self,
        LXtStereoComposite	 composite);

        LXxMETHOD(  LxResult,
SetEyeSide) (
        LXtObjectID		 self,
        int			 eyeSide);

        LXxMETHOD(  LxResult,
GetLineBuffer) (
        LXtObjectID		 self,
        float			**buf);

        LXxMETHOD(  LxResult,
CreateFrameBufferTargetImage) (
        LXtObjectID		 self,
        LXtPixelFormat		 type,
        int			 w,
        int			 h,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
GetRenderPassName) (
        LXtObjectID		 self,
        char			*name);

        LXxMETHOD(  LxResult,
SetRenderPassName) (
        LXtObjectID		 self,
        const char		*name);

        LXxMETHOD(  unsigned int,
BucketsOnDisk) (
        LXtObjectID		 self,
        int			 index);

        LXxMETHOD(  LXtObjectID,
Lookup) (
        LXtObjectID		 self,
        const char		*name,
        LXtObjectID		 item);

        LXxMETHOD(  LXtObjectID,
LookupByIdentity) (
        LXtObjectID		 self,
        const char		*identity);

        LXxMETHOD(  unsigned int,
Count) (
        LXtObjectID		 self);

        LXxMETHOD(  LXtObjectID,
ByIndex) (
        LXtObjectID		 self,
        int			 index);

        LXxMETHOD(  LXtObjectID,
Alpha) (
        LXtObjectID		 self,
        int			 index);

        LXxMETHOD(  int,
AlphaIndex) (
        LXtObjectID		 self,
        int			 index);

        LXxMETHOD(  LxResult,
Size) (
        LXtObjectID		 self,
        int			 index,
        int			*width,
        int			*height);

        LXxMETHOD(  LxResult,
AreaProcessingActive) (
        LXtObjectID		 self,
        int			 bufferIndex,
        int			*active);

        LXxMETHOD(  int,
GetSaveProcessed) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetSaveProcessed) (
        LXtObjectID		 self,
        int			 bufferIndex,
        int			 enabled);

        LXxMETHOD(  int,
GetBloomEnabled) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetBloomEnabled) (
        LXtObjectID		 self,
        int			 bufferIndex,
        int			 enabled);

        LXxMETHOD(  double,
GetBloomThreshold) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetBloomThreshold) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 threshold);

        LXxMETHOD(  double,
GetBloomRadius) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetBloomRadius) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 radius);

        LXxMETHOD(  double,
GetVignetteAmount) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetVignetteAmount) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 radius);

        LXxMETHOD(  double,
GetInputBlackLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputBlackLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 blackLevel);

        LXxMETHOD(  double,
GetInputGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  double,
GetInvInputGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 gamma);

        LXxMETHOD(  double,
GetInputWhiteLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputWhiteLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 whiteLevel);

        LXxMETHOD(  double,
GetInputMinRedLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputMinRedLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 level);

        LXxMETHOD(  double,
GetInputRedGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  double,
GetInvInputRedGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputRedGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 gamma);

        LXxMETHOD(  double,
GetInputMaxRedLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputMaxRedLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 level);

        LXxMETHOD(  double,
GetInputMinGreenLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputMinGreenLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 level);

        LXxMETHOD(  double,
GetInputGreenGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  double,
GetInvInputGreenGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputGreenGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 gamma);

        LXxMETHOD(  double,
GetInputMaxGreenLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputMaxGreenLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 level);

        LXxMETHOD(  double,
GetInputMinBlueLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputMinBlueLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 level);

        LXxMETHOD(  double,
GetInputBlueGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  double,
GetInvInputBlueGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputBlueGrayLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 gamma);

        LXxMETHOD(  double,
GetInputMaxBlueLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetInputMaxBlueLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 level);

        LXxMETHOD(  int,
GetExpType) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetExpType) (
        LXtObjectID		 self,
        int			 bufferIndex,
        int			 expType);

        LXxMETHOD(  double,
GetISO) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetISO) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 iso);

        LXxMETHOD(  int,
GetToneMap) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetToneMap) (
        LXtObjectID		 self,
        int			 bufferIndex,
        int			 toneMap);

        LXxMETHOD(  double,
GetToneAmt) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetToneAmt) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 toneAmt);

        LXxMETHOD(  double,
GetHueOffset) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetHueOffset) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 hueOffset);

        LXxMETHOD(  double,
GetSaturation) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetSaturation) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 saturation);

        LXxMETHOD(  double,
GetColorization) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetColorization) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 colorization);

        LXxMETHOD(  void,
GetTargetColor) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			*color);

        LXxMETHOD(  LxResult,
SetTargetColor) (
        LXtObjectID		 self,
        int			 bufferIndex,
        const double		*color);

        LXxMETHOD(  double,
GetOutputBlackLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetOutputBlackLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 blackLevel);

        LXxMETHOD(  double,
GetOutputWhiteLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetOutputWhiteLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 whiteLevel);

        LXxMETHOD(  double,
GetOutputMinRedLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetOutputMinRedLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 blackLevel);

        LXxMETHOD(  double,
GetOutputMaxRedLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetOutputMaxRedLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 whiteLevel);

        LXxMETHOD(  double,
GetOutputMinGreenLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetOutputMinGreenLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 blackLevel);

        LXxMETHOD(  double,
GetOutputMaxGreenLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetOutputMaxGreenLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 whiteLevel);

        LXxMETHOD(  double,
GetOutputMinBlueLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetOutputMinBlueLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 blackLevel);

        LXxMETHOD(  double,
GetOutputMaxBlueLevel) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetOutputMaxBlueLevel) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 whiteLevel);

        LXxMETHOD(  double,
GetOutputGamma) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  double,
GetOutputInvGamma) (
        LXtObjectID		 self,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
SetOutputGamma) (
        LXtObjectID		 self,
        int			 bufferIndex,
        double			 gamma);

        LXxMETHOD(	const char*,
GetOutputColorspace) (
        LXtObjectID		self);

        LXxMETHOD(	LxResult,
SetOutputColorspace) (
        LXtObjectID		self,
        const char*		colorspace);

        LXxMETHOD(  ILxColorMappingID,
GetOutputColormapping) (
        LXtObjectID		self);

        LXxMETHOD(  LxResult,
SetOutputColormapping) (
        LXtObjectID		self,
        LXtObjectID colormapping);

        LXxMETHOD(  LxResult,
AddAttribute) (
        LXtObjectID		 self,
        const char		*name,
        const char		*type,
        unsigned		*index);
        LXxMETHOD(  LxResult,
RenderProcessAllocate) (
        LXtObjectID			  self,
        int				  bufferIndex,
        const LXtRenderOutputProcess	**rndrProcess );
        LXxMETHOD(  LxResult,
RenderProcessDeallocate) (
        LXtObjectID			  self,
        const LXtRenderOutputProcess	**rndrProcess );
} ILxFrameBuffer;

/*
 * This method provides access to a read-only version of the ILxImageProcessing object
 * through an ILxImageProcessingInfo object, which is useful when you want others to
 * look but not touch.  This is not a morph; this returns a new object that references
 * the original.
 * 
 * A processing object can include an identifier string.  If set, any changes to the
 * object's image processing objects will be broadcast over the global image processing
 * port.  If the object is being used as a one-off, then this string need not be set.
 * 
 * The Reset method restores all of the remaining states to default values
 * (the identifier is not affect).
 * 
 * 
 * 
 * Copy image processing settings from a frame buffer.
 * 
 * Copy image processing settings from a frame buffer.
 * 
 * Apply image processing settings to an image from a frame buffer.
 * 
 * Apply image processing settings directly to a frame buffer.
 * 
 * Apply image processing settings to an image.
 * 
 * Control which image processing operators are enabled.
 * 
 * 
 * Determine if area image processing is active.
 * When image processing is limited to functions that operate on pixels with no
 * dependencies on neighboring pixels, it is safe to optimize by passing in a
 * cropped portion of the overall image.
 * 
 * For example, if the image is larger than the viewport, or is zoomed in, just
 * that portion of the image can be passed to the Apply functions if the
 * AreaProcessingActive function indicates that area functions are inactive.
 * 
 * 
 * Source image gamma is the original gamma of an image loaded into an image
 * slot in the render window.
 * This gamma is used to convert the image into linear space before image processing begins.
 * 
 * Gamma is re-applied using the output gamma before the image is saved.
 * 
 * 
 * A stereo image can be stored in a side-by-side format, which can be displayed
 * as stereo when this setting is enabled.
 * 
 * SaveProcessed controls whether or not an image is saved with post-
 * processing effects applied. When SaveProcessed is turned off, the raw,
 * original image is saved with no post processing.
 * 
 * See the LXtStereoEye type for the stereo eye modes, and the LXtStereoComposite
 * type for the stereo composite modes.
 * 
 * Bloom options control a post-processing effect that redistributes excess
 * energy to neighboring pixels.
 * Bloom threshold is the level above which the bloom effect is applied.
 * 
 * Bloom radius controls the size of the bloom effect.
 * 
 * The bloom effect can be switched on or off with the BloomEnabled setting.
 * 
 * 
 * Vignette amount is the amount of darkening to apply to pixels based on their
 * distance from the center of the frame.
 * 
 * Input black and white levels set the true black and white exposure levels
 * of the rendered or source image, after which additional post processing
 * is applied.
 * Gray level is a subjective gamma adjustment to the midtone levels
 * of the image colors, which is applied as part of the input level adjustment.
 * 
 * (The inverse functions provide a pre-computed inverse of the last set gray level.)
 * 
 * 
 * Exposure control determines how frame buffer pixel values (expressed in
 * physical units of radiance) should be mapped to output pixel values.  The
 * simple way is to specify a white level (the input value that corresponds
 * to an output of 1.0), but another method is to emulate a camera's film or
 * sensor, in which the mapping depends on film speed (ISO), exposure time,
 * and f-stop.
 * 
 * Tone mapping remaps the dynamic range of the image colors, enabling high-
 * dynamic-range (HDR) colors to be brought into the visible range, and also to be
 * mapped for saving to low-dynamic-range (LDR) integer file formats.
 * 
 * Hue offset is an angle of rotation for the hue of the image colors, given
 * in radians. For example, rotating by PI radians changes red colors to cyan.
 * 
 * Saturation is a multiplier on the existing saturation of the image colors,
 * such that values greater than 1.0 increase saturation, and values smaller
 * than 1.0 decrease saturation.
 * The default value of 1.0 has no effect.
 * 
 * 
 * Colorization and target color pull the colors of an image.
 * Colorization is the amount of pull, where 0 is no pull and 1.0
 * is maximum pull.
 * 
 * The target color is the color towards which the colors of the image are pulled.
 * 
 * 
 * Output black and white levels set the final mapping to white and black,
 * which is applied just before output gamma as the image is output to its
 * final destination.
 * 
 * Output gamma is the final level adjustment intended to conform the final image
 * levels to a standard gamma level, such as 2.2 for sRGB.
 * The inverse functions provide a pre-computed inverse of the last set value.
 * 
 * 
 * Output colorspace holds information about the name and mapping of the colorspace
 * intended for the final image color display. Additionaly colorspace embedding toggle 
 * has been exposed to enable or disable embedding ICC profile and EXIF data in the exported images.
 */
typedef struct vt_ILxImageProcessing {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetAsReadOnly) (
        LXtObjectID		  self,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
SetIdentifier) (
        LXtObjectID		 self,
        const char		*string);

        LXxMETHOD(  LxResult,
GetIdentifier) (
        LXtObjectID		  self,
        const char		**string);

        LXxMETHOD(  LxResult,
Reset) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
CopyToRenderProcess) (
        LXtObjectID		 self,
        LXtRenderOutputProcess	*rop);

        LXxMETHOD(  LxResult,
CopyFromRenderProcess) (
        LXtObjectID			self,
        const LXtRenderOutputProcess	*rop);

        LXxMETHOD(  LxResult,
CopySettingsFromFrameBuffer) (
        LXtObjectID		 self,
        LXtObjectID		 frameBuffer,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
CopySettingsToFrameBuffer) (
        LXtObjectID		 self,
        LXtObjectID		 frameBuffer,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
ApplyToImageFromFrameBuffer) (
        LXtObjectID			 self,
        LXtObjectID			 frameBuffer,
        int				 bufferIndex,
        LXtObjectID			 image,
        float				 xOffset,
        float				 yOffset,
        float				 zoom);

        LXxMETHOD(  LxResult,
ApplyToImageFromFrameBufferOverride) (
        LXtObjectID			 self,
        LXtObjectID			 frameBuffer,
        int				 bufferIndex,
        LXtObjectID			 image,
        float				 xOffset,
        float				 yOffset,
        float				 zoom,
        LXtImageProcessingOperators	 opOverride);

        LXxMETHOD(  LxResult,
ApplyToFrameBuffer) (
        LXtObjectID			 self,
        LXtObjectID			 frameBuffer,
        int				 bufferIndex);

        LXxMETHOD(  LxResult,
ApplyToFrameBufferOverride) (
        LXtObjectID			 self,
        LXtObjectID			 frameBuffer,
        int				 bufferIndex,
        LXtImageProcessingOperators	 opOverride);

        LXxMETHOD(  LxResult,
ApplyToImage) (
        LXtObjectID		 self,
        LXtObjectID		 srcImage,
        LXtObjectID		 dstImage);

        LXxMETHOD(  LxResult,
ApplyToImageOverride) (
        LXtObjectID			 self,
        LXtObjectID			 srcImage,
        LXtObjectID			 dstImage,
        LXtImageProcessingOperators	 opOverride);

        LXxMETHOD(  LxResult,
GetImageProcessingOperators) (
        LXtObjectID			 self,
        LXtImageProcessingOperators	*ops);

        LXxMETHOD(  LxResult,
SetImageProcessingOperators) (
        LXtObjectID			self,
        LXtImageProcessingOperators	ops);

        LXxMETHOD(  LxResult,
AreaProcessingActive) (
        LXtObjectID		 self,
        int			*active);

        LXxMETHOD(  LxResult,
GetSourceImageGamma) (
        LXtObjectID		 self,
        double			*gamma);

        LXxMETHOD(  LxResult,
SetSourceImageGamma) (
        LXtObjectID		 self,
        double			 gamma);

        LXxMETHOD(  LxResult,
GetSourceImageIsStereoSideBySide) (
        LXtObjectID		 self,
        int			*isStereo);

        LXxMETHOD(  LxResult,
SetSourceImageIsStereoSideBySide) (
        LXtObjectID		 self,
        int			 isStereo);

        LXxMETHOD(  LxResult,
GetSaveProcessed) (
        LXtObjectID		 self,
        int			*enabled);

        LXxMETHOD(  LxResult,
SetSaveProcessed) (
        LXtObjectID		 self,
        int			 enabled);

        LXxMETHOD(  LxResult,
GetStereoEye) (
        LXtObjectID		 self,
        LXtStereoEye		*eye);

        LXxMETHOD(  LxResult,
SetStereoEye) (
        LXtObjectID		 self,
        LXtStereoEye		 eye);

        LXxMETHOD(  LxResult,
GetStereoComposite) (
        LXtObjectID		 self,
        LXtStereoComposite	*mode);

        LXxMETHOD(  LxResult,
SetStereoComposite) (
        LXtObjectID		 self,
        LXtStereoComposite	 mode);
        LXxMETHOD(  LxResult,
GetBloomEnabled) (
        LXtObjectID		 self,
        int			*enabled);

        LXxMETHOD(  LxResult,
SetBloomEnabled) (
        LXtObjectID		 self,
        int			 enabled);

        LXxMETHOD(  LxResult,
GetBloomThreshold) (
        LXtObjectID		 self,
        double			*threshold);

        LXxMETHOD(  LxResult,
SetBloomThreshold) (
        LXtObjectID		 self,
        double			 threshold);

        LXxMETHOD(  LxResult,
GetBloomRadius) (
        LXtObjectID		 self,
        double			*radius);

        LXxMETHOD(  LxResult,
SetBloomRadius) (
        LXtObjectID		 self,
        double			 radius);

        LXxMETHOD(  LxResult,
GetVignetteAmount) (
        LXtObjectID		 self,
        double			*amount);

        LXxMETHOD(  LxResult,
SetVignetteAmount) (
        LXtObjectID		 self,
        double			 amount);

        LXxMETHOD(  LxResult,
GetInputBlackLevel) (
        LXtObjectID		 self,
        double			*inputBlackLevel);

        LXxMETHOD(  LxResult,
SetInputBlackLevel) (
        LXtObjectID		 self,
        double			 blackLevel);

        LXxMETHOD(  LxResult,
GetInputGrayLevel) (
        LXtObjectID		 self,
        double			*gamma);

        LXxMETHOD(  LxResult,
GetInvInputGrayLevel) (
        LXtObjectID		 self,
        double			*invGamma);

        LXxMETHOD(  LxResult,
SetInputGrayLevel) (
        LXtObjectID		 self,
        double			 gamma);

        LXxMETHOD(  LxResult,
GetInputWhiteLevel) (
        LXtObjectID		 self,
        double			*inputWhiteLevel);

        LXxMETHOD(  LxResult,
SetInputWhiteLevel) (
        LXtObjectID		 self,
        double			 whiteLevel);

        LXxMETHOD(  LxResult,
GetInputMinRedLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
SetInputMinRedLevel) (
        LXtObjectID		 self,
        double			 level);

        LXxMETHOD(  LxResult,
GetInputRedGrayLevel) (
        LXtObjectID		 self,
        double			*gamma);

        LXxMETHOD(  LxResult,
GetInvInputRedGrayLevel) (
        LXtObjectID		 self,
        double			*invGamma);

        LXxMETHOD(  LxResult,
SetInputRedGrayLevel) (
        LXtObjectID		 self,
        double			 gamma);

        LXxMETHOD(  LxResult,
GetInputMaxRedLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
SetInputMaxRedLevel) (
        LXtObjectID		 self,
        double			 level);

        LXxMETHOD(  LxResult,
GetInputMinGreenLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
SetInputMinGreenLevel) (
        LXtObjectID		 self,
        double			 level);

        LXxMETHOD(  LxResult,
GetInputGreenGrayLevel) (
        LXtObjectID		 self,
        double			*gamma);

        LXxMETHOD(  LxResult,
GetInvInputGreenGrayLevel) (
        LXtObjectID		 self,
        double			*invGamma);

        LXxMETHOD(  LxResult,
SetInputGreenGrayLevel) (
        LXtObjectID		 self,
        double			 gamma);

        LXxMETHOD(  LxResult,
GetInputMaxGreenLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
SetInputMaxGreenLevel) (
        LXtObjectID		 self,
        double			 level);

        LXxMETHOD(  LxResult,
GetInputMinBlueLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
SetInputMinBlueLevel) (
        LXtObjectID		 self,
        double			 level);

        LXxMETHOD(  LxResult,
GetInputBlueGrayLevel) (
        LXtObjectID		 self,
        double			*gamma);

        LXxMETHOD(  LxResult,
GetInvInputBlueGrayLevel) (
        LXtObjectID		 self,
        double			*invGamma);

        LXxMETHOD(  LxResult,
SetInputBlueGrayLevel) (
        LXtObjectID		 self,
        double			 gamma);

        LXxMETHOD(  LxResult,
GetInputMaxBlueLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
SetInputMaxBlueLevel) (
        LXtObjectID		 self,
        double			 level);

        LXxMETHOD(  LxResult,
GetExpType) (
        LXtObjectID		 self,
        int			*expType);

        LXxMETHOD(  LxResult,
SetExpType) (
        LXtObjectID		 self,
        int			 expType);

        LXxMETHOD(  LxResult,
GetISO) (
        LXtObjectID		 self,
        double			*iso);

        LXxMETHOD(  LxResult,
SetISO) (
        LXtObjectID		 self,
        double			 iso);

        LXxMETHOD(  LxResult,
GetToneMap) (
        LXtObjectID		 self,
        int			*toneMap);

        LXxMETHOD(  LxResult,
SetToneMap) (
        LXtObjectID		 self,
        int			 toneMap);

        LXxMETHOD(  LxResult,
GetToneAmt) (
        LXtObjectID		 self,
        double			*toneAmt);

        LXxMETHOD(  LxResult,
SetToneAmt) (
        LXtObjectID		 self,
        double			 toneAmt);

        LXxMETHOD(  LxResult,
GetHueOffset) (
        LXtObjectID		 self,
        double			*hueOffset);

        LXxMETHOD(  LxResult,
SetHueOffset) (
        LXtObjectID		 self,
        double			 hueOffset);


        LXxMETHOD(  LxResult,
GetSaturation) (
        LXtObjectID		 self,
        double			*saturation);

        LXxMETHOD(  LxResult,
SetSaturation) (
        LXtObjectID		 self,
        double			 saturation);

        LXxMETHOD(  LxResult,
GetColorization) (
        LXtObjectID		 self,
        double			*colorization);

        LXxMETHOD(  LxResult,
SetColorization) (
        LXtObjectID		 self,
        double			 colorization);

        LXxMETHOD(  LxResult,
GetTargetColor) (
        LXtObjectID		 self,
        double			*color);

        LXxMETHOD(  LxResult,
SetTargetColor) (
        LXtObjectID		 self,
        const double		*color);

        LXxMETHOD(  LxResult,
GetOutputBlackLevel) (
        LXtObjectID		 self,
        double			*outputBlackLevel);

        LXxMETHOD(  LxResult,
SetOutputBlackLevel) (
        LXtObjectID		 self,
        double			 blackLevel);

        LXxMETHOD(  LxResult,
GetOutputWhiteLevel) (
        LXtObjectID		 self,
        double			*outputWhiteLevel);

        LXxMETHOD(  LxResult,
SetOutputWhiteLevel) (
        LXtObjectID		 self,
        double			 whiteLevel);

        LXxMETHOD(  LxResult,
GetOutputMinRedLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
SetOutputMinRedLevel) (
        LXtObjectID		 self,
        double			 outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMaxRedLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
SetOutputMaxRedLevel) (
        LXtObjectID		 self,
        double			 outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMinGreenLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
SetOutputMinGreenLevel) (
        LXtObjectID		 self,
        double			 outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMaxGreenLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
SetOutputMaxGreenLevel) (
        LXtObjectID		 self,
        double			 outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMinBlueLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
SetOutputMinBlueLevel) (
        LXtObjectID		 self,
        double			 outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMaxBlueLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
SetOutputMaxBlueLevel) (
        LXtObjectID		 self,
        double			 outputLevel);

        LXxMETHOD(  LxResult,
GetOutputGamma) (
        LXtObjectID		 self,
        double			*outputGamma);

        LXxMETHOD(  LxResult,
GetOutputInvGamma) (
        LXtObjectID		 self,
        double			*outputInvGamma);

        LXxMETHOD(  LxResult,
SetOutputGamma) (
        LXtObjectID		 self,
        double			 gamma);

        LXxMETHOD(	const char*,
GetOutputColorspace) (
        LXtObjectID		self);

        LXxMETHOD(	LxResult,
SetOutputColorspace) (
        LXtObjectID		self,
        const char*		colorspace);

        LXxMETHOD(  ILxColorMappingID,
GetOutputColormapping) (
        LXtObjectID		self);

        LXxMETHOD(  LxResult,
SetOutputColormapping) (
        LXtObjectID		self,
        LXtObjectID colormapping);

        LXxMETHOD(  LxResult,
GetColorSpaceEmbedding) (
        LXtObjectID		self,
        int				*colorSpaceEmbedding);

        LXxMETHOD(  LxResult,
SetColorSpaceEmbedding) (
        LXtObjectID		self,
        const int		colorSpaceEmbedding);

} ILxImageProcessing;

/*
 * 
 * We call the Reset() method when an ILxImageProcessing object with an identifier
 * set has its Reset() method called.  At this point all of the ILxImageProcessing
 * object's properties have been reset to defaults, save for the identifier itself.
 */
typedef struct vt_ILxImageProcessingListener {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Changed) (
        LXtObjectID		 self,
        const char		*identifier,
        int			 eventCode);
        LXxMETHOD(  LxResult,
Reset) (
        LXtObjectID		 self,
        const char		*identifier);
} ILxImageProcessingListener;

/*
 * These methods are identical to the Get...() methods in ILxImageProcessing; see
 * that interface for more information.
 */
typedef struct vt_ILxImageProcessingRead {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
GetIdentifier) (
        LXtObjectID		 self,
        const char	       **string);

        LXxMETHOD(  LxResult,
CopyToRenderProcess) (
        LXtObjectID		 self,
        LXtRenderOutputProcess	*rop);

        LXxMETHOD(  LxResult,
CopySettingsToFrameBuffer) (
        LXtObjectID		 self,
        LXtObjectID		 frameBuffer,
        int			 bufferIndex);

        LXxMETHOD(  LxResult,
ApplyToImageFromFrameBuffer) (
        LXtObjectID			 self,
        LXtObjectID			 frameBuffer,
        int				 bufferIndex,
        LXtObjectID			 image,
        float				 xOffset,
        float				 yOffset,
        float				 zoom);

        LXxMETHOD(  LxResult,
ApplyToImageFromFrameBufferOverride) (
        LXtObjectID			 self,
        LXtObjectID			 frameBuffer,
        int				 bufferIndex,
        LXtObjectID			 image,
        float				 xOffset,
        float				 yOffset,
        float				 zoom,
        LXtImageProcessingOperators	 opOverride);

        LXxMETHOD(  LxResult,
ApplyToFrameBuffer) (
        LXtObjectID			 self,
        LXtObjectID			 frameBuffer,
        int				 bufferIndex);

        LXxMETHOD(  LxResult,
ApplyToFrameBufferOverride) (
        LXtObjectID			 self,
        LXtObjectID			 frameBuffer,
        int				 bufferIndex,
        LXtImageProcessingOperators	 opOverride);

        LXxMETHOD(  LxResult,
ApplyToImage) (
        LXtObjectID			 self,
        LXtObjectID			 srcImage,
        LXtObjectID			 dstImage);

        LXxMETHOD(  LxResult,
ApplyToImageOverride) (
        LXtObjectID			 self,
        LXtObjectID			 srcImage,
        LXtObjectID			 dstImage,
        LXtImageProcessingOperators	 opOverride);

        LXxMETHOD(  LxResult,
GetImageProcessingOperators) (
        LXtObjectID			 self,
        LXtImageProcessingOperators	*ops);

        LXxMETHOD(  LxResult,
AreaProcessingActive) (
        LXtObjectID		 self,
        int			*active);

        LXxMETHOD(  LxResult,
GetSourceImageGamma) (
        LXtObjectID		 self,
        double			*gamma);

        LXxMETHOD(  LxResult,
GetSourceImageIsStereoSideBySide) (
        LXtObjectID		 self,
        int			*isStereo);

        LXxMETHOD(  LxResult,
GetSaveProcessed) (
        LXtObjectID		 self,
        int			*enabled);

        LXxMETHOD(  LxResult,
GetStereoEye) (
        LXtObjectID		 self,
        int			*eye);

        LXxMETHOD(  LxResult,
GetStereoComposite) (
        LXtObjectID		 self,
        int			*mode);

        LXxMETHOD(  LxResult,
GetBloomEnabled) (
        LXtObjectID		 self,
        int			*enabled);

        LXxMETHOD(  LxResult,
GetBloomThreshold) (
        LXtObjectID		 self,
        double			*threshold);

        LXxMETHOD(  LxResult,
GetBloomRadius) (
        LXtObjectID		 self,
        double			*radius);

        LXxMETHOD(  LxResult,
GetInputBlackLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
GetInputGrayLevel) (
        LXtObjectID		 self,
        double			*gamma);

        LXxMETHOD(  LxResult,
GetInvInputGrayLevel) (
        LXtObjectID		 self,
        double			*invGamma);

        LXxMETHOD(  LxResult,
GetInputWhiteLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
GetInputMinRedLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
GetInputRedGrayLevel) (
        LXtObjectID		 self,
        double			*gamma);

        LXxMETHOD(  LxResult,
GetInvInputRedGrayLevel) (
        LXtObjectID		 self,
        double			*invGamma);

        LXxMETHOD(  LxResult,
GetInputMaxRedLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
GetInputMinGreenLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
GetInputGreenGrayLevel) (
        LXtObjectID		 self,
        double			*gamma);

        LXxMETHOD(  LxResult,
GetInvInputGreenGrayLevel) (
        LXtObjectID		 self,
        double			*invGamma);

        LXxMETHOD(  LxResult,
GetInputMaxGreenLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
GetInputMinBlueLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
GetInputBlueGrayLevel) (
        LXtObjectID		 self,
        double			*gamma);

        LXxMETHOD(  LxResult,
GetInvInputBlueGrayLevel) (
        LXtObjectID		 self,
        double			*invGamma);

        LXxMETHOD(  LxResult,
GetInputMaxBlueLevel) (
        LXtObjectID		 self,
        double			*inputLevel);

        LXxMETHOD(  LxResult,
GetExpType) (
        LXtObjectID		 self,
        int			*expType);

        LXxMETHOD(  LxResult,
GetISO) (
        LXtObjectID		 self,
        double			*iso);

        LXxMETHOD(  LxResult,
GetToneMap) (
        LXtObjectID		 self,
        int			*toneMap);

        LXxMETHOD(  LxResult,
GetToneAmt) (
        LXtObjectID		 self,
        double			*toneAmt);

        LXxMETHOD(  LxResult,
GetHueOffset) (
        LXtObjectID		 self,
        double			*hueOffset);

        LXxMETHOD(  LxResult,
GetSaturation) (
        LXtObjectID		 self,
        double			*saturation);

        LXxMETHOD(  LxResult,
GetColorization) (
        LXtObjectID		 self,
        double			*colorization);

        LXxMETHOD(  LxResult,
GetTargetColor) (
        LXtObjectID		 self,
        double			*color);

        LXxMETHOD(  LxResult,
GetOutputBlackLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
GetOutputWhiteLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMinRedLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMaxRedLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMinGreenLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMaxGreenLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMinBlueLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
GetOutputMaxBlueLevel) (
        LXtObjectID		 self,
        double			*outputLevel);

        LXxMETHOD(  LxResult,
GetOutputGamma) (
        LXtObjectID		 self,
        double			*outputGamma);

        LXxMETHOD(  LxResult,
GetOutputInvGamma) (
        LXtObjectID		 self,
        double			*outputInvGamma);

        LXxMETHOD(	const char*,
GetOutputColorspace) (
        LXtObjectID		self);

        LXxMETHOD(  ILxColorMappingID,
GetOutputColormapping) (
        LXtObjectID		self);

} ILxImageProcessingRead;

/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.  Since there is currently no ScriptQuery interface, this method
 * will always fail.
 * This is the important methods, which returns a new image processing object.
 */
typedef struct vt_ILxImageProcessingService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Create) (
        LXtObjectID		 self,
        void			**ppvObj);
} ILxImageProcessingService;

/*
 * The render service provides a way for clients to spawn and submit render jobs,
 * check the status of a render, obtain frame buffers for the currently rendering/
 * most recently rendered frame, and stopping render jobs.  The render service is
 * defined as a global.  We define a number of LxResult codes as well.
 */

        #define LXa_RENDERSERVICE		"renderservice"
        #define LXu_RENDERSERVICE		"8D1710CE-7AF4-46cd-B6B1-222A7DC4C53F"
        // [const]  ILxRenderService:JobCurrent
        // [const]  ILxRenderService:JobGetCurrent
        // [const]  ILxRenderService:JobStatus
        // [const]  ILxRenderService:JobIsSlave
        // [const]  ILxRenderService:JobRenderOutputCount
        // [const]  ILxRenderService:JobRenderOutputName
        // [const]  ILxRenderService:JobRenderOutputType
        // [python] ILxRenderService:FrameRecall		obj FrameBuffer
        // [python] ILxRenderService:FrameRecallStats		obj RenderStats
        // [python] ILxRenderService:FrameRecallThumbnail	obj Image
        // [python] ILxRenderService:JobCurrent			obj RenderJob
        // [python] ILxRenderService:FrameTestRecall		bool

        #define LXe_RENDER_IDLE			LXxGOODCODE( LXeSYS_RENDER, 1)
        #define LXe_RENDER_RENDERING		LXxGOODCODE( LXeSYS_RENDER, 2)
        #define LXe_RENDER_USE_OUTPUT_ITEMS	LXxGOODCODE( LXeSYS_RENDER, 3)
        #define LXe_RENDER_WITHOUT_SAVING	LXxGOODCODE( LXeSYS_RENDER, 4)

        #define LXe_RENDER_NO_PROGRESS_IMAGE	LXxGOODCODE( LXeSYS_RENDER, 5)
        #define LXe_RENDER_BAKE_TARGET		LXxGOODCODE( LXeSYS_RENDER, 6)

        // Failure codes
        #define LXe_RENDER_NO_JOB		LXxFAILCODE( LXeSYS_RENDER, 1)
        #define LXe_RENDER_IN_PROGRESS		LXxFAILCODE( LXeSYS_RENDER, 2)
        #define LXe_RENDER_NOT_RENDERING	LXxFAILCODE( LXeSYS_RENDER, 3)

        #define LXe_RENDER_NO_MFP_WITH_WB2D	LXxFAILCODE( LXeSYS_RENDER, 4)
        #define LXe_RENDER_NO_VISIBLE_OUTPUTS	LXxFAILCODE( LXeSYS_RENDER, 5)
        #define LXe_RENDER_INVALID_DENOISER	LXxFAILCODE( LXeSYS_RENDER, 6)
        #define LXe_RENDER_OPTIX_CONTEXT	LXxFAILCODE( LXeSYS_RENDER, 7)
        #define LXe_RENDER_OPTIX_SCENE		LXxFAILCODE( LXeSYS_RENDER, 8)
        #define LXe_RENDER_OPTIX_LAUNCH		LXxFAILCODE( LXeSYS_RENDER, 9)
        #define LXe_RENDER_EMBREE_CONTEXT       LXxFAILCODE( LXeSYS_RENDER, 10)
        #define LXe_RENDER_EMBREE_SCENE         LXxFAILCODE( LXeSYS_RENDER, 11)
        #define LXe_RENDER_EMBREE_LAUNCH        LXxFAILCODE( LXeSYS_RENDER, 12)
        
        #define LXe_RENDER_ABORTING		LXe_ABORT

/*
 * A render job represents a series of settings used to render a frame.  The
 * client defines a job object with this interface and submits it to the render
 * service for rendering.  The job's methods both provide state for the render
 * and are used to obtain feedback during the render.
 * All methods may be called when doing a local render.  The following methods
 * will be called for both a local render and slave mode.  Notably, the progress
 * methods will not be called during slave mode:
 * - RenderItem()
 * - ActionName()
 * - GroupName()
 * - RenderAs()
 * - RenderAtTime()
 * - RenderTurntableFPS()
 * - RenderTurntableNumFrames()
 * - RenderBakeVMap()
 * - RenderBakeCageVMap()
 * - RenderBakeLookDistance()
 * - RenderBakeItem()
 * - RenderBakeEffect()
 * - RenderBakeImage()
 * - UDIM()
 * - RenderTestItem()
 * - OutputFilename()
 * - OutputFormat()
 * - Options()
 * 
 */

        #define LXa_RENDERJOB			"renderjob"
        #define LXu_RENDERJOB			"97a84077-9ce3-46cc-96ca-d6ee6e3d0109"
        // [local]  ILxRenderJob
        // [export] ILxRenderJob rjob
        // [const]  ILxRenderJob:RenderItem
        // [const]  ILxRenderJob:BakeItem
        // [const]  ILxRenderJob:ActionName
        // [const]  ILxRenderJob:GroupName
        // [const]  ILxRenderJob:RenderAs
        // [const]  ILxRenderJob:RenderAtTime
        // [const]  ILxRenderJob:RenderTurntableFPS
        // [const]  ILxRenderJob:RenderTurntableNumFrames
        // [const]  ILxRenderJob:RenderBakeVMap
        // [const]  ILxRenderJob:RenderBakeCageVMap
        // [const]  ILxRenderJob:RenderBakeLookDistance
        // [const]  ILxRenderJob:RenderBakeItem
        // [const]  ILxRenderJob:RenderBakeEffect
        // [const]  ILxRenderJob:RenderBakeImage
        // [const]  ILxRenderJob:UDIM
        // [const]  ILxRenderJob:FrameBufferSlot
        // [const]  ILxRenderJob:FrameBufferRegionBackgroundSlot
        // [const]  ILxRenderJob:OutputFormat
        // [const]  ILxRenderJob:OutputFilename
        // [const]  ILxRenderJob:Options
        // [python] ILxRenderJob:RenderBakeImage	obj Image (image)
        // [python] ILxRenderJob:RenderItem		obj Item (item)
        // [python] ILxRenderJob:BakeItem		obj Item (item)

/*
 * This method determines how to render the scene.
 * - FRAME
 * Render a single frame at the scene time returned by RenderAtTime().
 * - ANIM
 * Render a complete animation using the scene's properties for first frame,
 * last frame and frame step.
 * 
 * - TURNTABLE_CAMERA
 * Render a turntable animation by rotating the camera around the object.
 * RenderAtTime() determines at what scene time the turntable animation is
 * done. RenderTurntableNumFrames() determines how many frames are rendered,
 * while RenderTurntableFPS() determines the frame rate when saving as a
 * movie.
 * 
 * - TURNTABLE_GEOMETRY
 * Render a turntable animation by rotating the geometry in place. RenderAtTime(),
 * RenderTurntableNumFrames() and RenderTurntableFPS() are used in the same manner
 * as for TURNTABLE_CAMERA
 * 
 * - BAKE_GEOMETRY
 * Bake into the geometry.
 * 
 * - BAKE_TEXTURE
 * Bake into a texture.
 * 
 */

        #define LXiRENDERTYPE_FRAME			0
        #define LXiRENDERTYPE_ANIM			1
        #define LXiRENDERTYPE_TURNTABLE_CAMERA		2
        #define LXiRENDERTYPE_TURNTABLE_GEOMETRY	3
        #define LXiRENDERTYPE_BAKE_SCENE		4
        #define LXiRENDERTYPE_BAKE_TEXTURE		5

/*
 * This returns a series of options as a mask.  The following flags are
 * defined:
 */

        #define	LXfRENDEROPT_NO_WAITING		0x0001
        #define	LXfRENDEROPT_NO_IMAGE		0x0002
        #define	LXfRENDEROPT_NO_CLEANUP		0x0004
        #define	LXfRENDEROPT_IC_ONLY		0x0008
        #define	LXfRENDEROPT_PLAY		0x0010

/*
 * One or more render passes may be rendered per frame.  Each render pass (not to
 * be confused with a frame pass) represents some variation of the frame.  These
 * methods are called when a render pass begins or ends.  ProgressRenderPassEnd()
 * is provided with an ILxAttributesID representing the state of the render at the
 * time the pass finished, as well as an ILxFrameBuffer representing the rendered
 * pass.  These can be AddRef()'ed and held onto for future use, if so desired.
 * Note that the frame buffer may be NULL if the render was aborted.
 * If stereo is on, then the left, right or both eyes will be rendered.  The eye
 * argument will be one of the XiRENDEREYE_* values, with MONO being passed if stereo
 * rendering is disabled.
 */

        #define LXiRENDEREYE_MONO	0         // [ 0 0]
        #define LXiRENDEREYE_LEFT	(1 << 0) // [ 0 1]
        #define LXiRENDEREYE_RIGHT	(1 << 1) // [ 1 0]
        #define LXiRENDEREYE_BOTH	(LXiRENDEREYE_LEFT | LXiRENDEREYE_RIGHT) // [ 1 1]


        #define LXa_RENDERJOB1			"renderjob1"
        #define LXu_RENDERJOB1			"091C8EB2-5DC1-4d01-AF9B-3C735F2FFB1D"

/*
 * Clients can use ILxRenderProgressListener to listen for events indicating
 * the start and end of a render.  The end event includes an ILxRenderStatsID
 * that can be used to obtain detailed information about the just-completed
 * render.
 * For real-time feedback on a render, clients can listen to the "render"
 * system's rolling log messages via ILxLogListener.
 */

        #define LXu_RENDERPROGRESSLISTENER			"db045a41-0ed0-4372-a51a-09b21387c4ae"
        // [local]  ILxRenderProgressListener
        // [export] ILxRenderProgressListener rndprog

/*
 * Various statistics are available for the rendered frames.  Each render
 * pass of each frame has its own set of stats, and is represented by an
 * ILxAttributes object.  The stats for an entire rendered animation are
 * available to clients.
 * Each ILxAttributes contains not only the stats for the specific render
 * pass, but also a snapshot of the stats for the frame that owns the pass
 * and the scene itself.  Thus, the stats for the last pass in a frame
 * also contain the final stats for the frame, and the stats for the last
 * frame represent the final stats for the entire scene.
 * Stats are provided through a container object, ILxRenderStats.  This
 * object can be queried to obtain the ILxAttributes for a specific render
 * pass in a specific frame.  There are also utility methods to get the
 * ILxAttributes representing the entire frame or the entire scene.
 * 
 * Note that while a render is in progress, the ILxAttributes object
 * representing the scene itself or a specific frame will change as each
 * pass or frame finishes rendering.  This is because each stats object is
 * a snapshot of the render, with the last pass in a frame representing the
 * frame and the last frame in the scene representing the scene.  Thus,
 * during rendering you will need to update which object you're using as
 * each frame/pass completes.  For simplicity, you can just obtain the
 * ILxAttributes object on demand, rather than holding onto it indefinitely,
 * at least until the render completes.
 * 
 */

        #define LXa_RENDERSTATS			"renderstats"
        #define LXu_RENDERSTATS			"d7630419-eef3-4725-a6cc-1c8ce09dbd6d"
        // [local]  ILxRenderStats

/*
 * Render buffers are defined using the ILxBuffer interface.
 */

        #define LXa_BUFFER	"renderBuffer"
        #define LXu_BUFFER	"088D0A6B-7A83-4774-AA56-473F6C241F40"
        //[local]  ILxBuffer
        //[export] ILxBuffer buff
        //[const]  ILxBuffer:GetSize
        //[const]  ILxBuffer:Pixel
        //[const]  ILxBuffer:Line
        //[const]  ILxBuffer:Name
        //[const]  ILxBuffer:UserName
        //[const]  ILxBuffer:DataType
        //[const]  ILxBuffer:Flags
        //[const]  ILxBuffer:VectorType
        //[const]  ILxBuffer:GetImageTileTree
        //[const]  ILxBuffer:GetImageTileTreeSize
        //[python] ILxBuffer:VectorType		obj VectorType
        //[python] type LXtTileTreeID id

/*
 * Buffers have flags, such as anti-aliasing and dithering.
 * Buffers also track whether or not they are factory-named, to enable
 * automatic naming rules for channels.
 */

        #define LXf_RBF_NO_AA		 0x01	// render buffer is not anti-aliased
        #define LXf_RBF_DITHER		 0x02	// render buffer can be dithered
        #define LXf_RBF_IS_FACTORY_NAME	 0x08	// render buffer is factory named

/*
 * This returns the datatype of the buffer.  Often this is a single float for
 * simple greyscale buffers or a float triple representing RGB or similar sets
 * of channels.
 */

        #define LXiRBD_FLOAT		 0
        #define LXiRBD_FLOAT3		 1
        #define LXiRBD_OTHER		 2


        #define LXa_FRAMEBUFFER		"frameBuffer"
        #define LXu_FRAMEBUFFER		"90B060B4-1EC2-45F4-A6A8-9A3822B9B39C"
        //[local] ILxFrameBuffer
        //[export] ILxFrameBuffer fbuf
        //[const] ILxFrameBuffer:IsStereo
        //[const] ILxFrameBuffer:GetStereoEyeDisplay
        //[const] ILxFrameBuffer:GetStereoComposite
        //[const] ILxFrameBuffer:Lookup
        //[const] ILxFrameBuffer:Count
        //[const] ILxFrameBuffer:ByIndex
        //[const] ILxFrameBuffer:Alpha

        //[python] ILxFrameBuffer:Lookup		obj Buffer
        //[python] ILxFrameBuffer:LookupByIdentity	obj Buffer
        //[python] ILxFrameBuffer:ByIndex		obj Buffer
        //[python] ILxFrameBuffer:Alpha			obj Buffer

        //[python] type LXtPixelFormat			unsigned
        //[python] type LXtStereoEye			unsigned
        //[python] type LXtStereoComposite		unsigned
        //[python] type LXtImageProcessingOperators	unsigned

/*
 * This interface allows a series of common image processing operations to be applied
 * to an image or frame buffer.  Clients set the various options and then call one of
 * the Apply methods to apply these operations to a new image or frame buffer.
 */

        #define LXa_IMAGEPROCESSING		"imageprocessing"
        #define LXu_IMAGEPROCESSING		"1a89cc09-5326-44d6-9605-3b66bf9c03f5"
        // [local]  ILxImageProcessing
        // [const]  ILxImageProcessing:GetIdentifier
        // [const]  ILxImageProcessing:GetBloomEnabled
        // [python] ILxImageProcessing:GetAsReadOnly	obj ImageProcessing

/*
 * Plug-ins can listen for when an ILxImageProcessing's Set...() methods have been called
 * by implementing this listener object.  This contains a single method, Changed(), which
 * is called with the setting that has changed.  Note that events are only sent for
 * image processing objects that have their identifier set to a non-NULL string.  The
 * identifier string is included as an argument to the change event.
 */

        #define LXa_IMAGEPROCESSINGLISTENER	"imageprocessinglistener"
        #define LXu_IMAGEPROCESSINGLISTENER	"4a4ca8b2-df07-4156-b1c3-a5fc63318ea8"
        //[export] ILxImageProcessingListener improl
        //[local]  ILxImageProcessingListener

/*
 * An LXiIMAGEPROC_EVENT_CHANGED event is sent whenever any Set..() method is called (except
 * SetIdentifier()).  The event data is the object's identifier string.  The defines are in
 * an SDK block as they are passed to the Change() method of the listener.
 * An LXiIMAGEPROC_EVENT_RESET event is set when the Reset() method is called, rather than
 * sending a bunch of individual CHANGED events.
 * The low bits are reserved for when the events are used as part of a text hint array, and
 * tend to encode UI update notification flags.
 * 
 */

        #define LXfIMAGEPROC_EVENT_CHANGED					 0x40000000	// One of the image processing Set...() methods was called
        #define LXfIMAGEPROC_EVENT_MAINTENANCE					 0x80000000	// A maintenance method like Reset() was called

        #define LXmIMAGEPROC_EVENT_RESERVED					 0x0000000F	// Reserved for internal use (see above)

        #define LXiIMAGEPROC_EVENT_CHANGED_OPERATORS				(0x00000010 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_SOURCE_IMAGE_GAMMA			(0x00000020 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_SAVE_PROCESSED			(0x00000040 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_CHANGED_BLOOM_ENABLED			(0x00000080 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_BLOOM_THRESHOLD			(0x00000100 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_BLOOM_RADIUS				(0x00000200 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_CHANGED_VIGNETTE_AMOUNT			(0x10000000 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_CHANGED_INPUT_BLACK_LEVEL			(0x00000800 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_INPUT_GRAY_LEVEL			(0x00001000 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_INPUT_WHITE_LEVEL			(0x00002000 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_CHANGED_INPUT_MIN_RGB_LEVEL			(0x00004000 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_INPUT_GRAY_RGB_LEVEL			(0x00008000 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_INPUT_MAX_RGB_LEVEL			(0x00010000 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_CHANGED_TONE_MAPPING				(0x00020000 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_CHANGED_HUE_OFFSET				(0x00040000 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_SATURATION				(0x00080000 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_COLORIZATION				(0x00100000 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_TARGET_COLOR				(0x00200000 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_BLACK_LEVEL			(0x00400000 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_WHITE_LEVEL			(0x00800000 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_MIN_RGB_LEVEL			(0x01000000 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_MAX_RGB_LEVEL			(0x02000000 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_GAMMA				(0x04000000 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_RESPECT_RENDER_VIEW_GAMMA_PREF	(0x08000000 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_COLORSPACE			(0x10000000 | LXfIMAGEPROC_EVENT_CHANGED)
        #define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_COLOR_SPACE_EMBEDDING	(0x20000000 | LXfIMAGEPROC_EVENT_CHANGED)

        #define LXiIMAGEPROC_EVENT_RESET					(0x00000001 | LXfIMAGEPROC_EVENT_MAINTENANCE)

/*
 * This interface provides read-only access to an ILxImageProcessing interface.
 */

        #define LXa_IMAGEPROCESSINGREAD		"imageprocessingread"
        #define LXu_IMAGEPROCESSINGREAD		"154307c9-5fa3-4749-8853-088e2cc1f5ed"
        //[local]  ILxImageProcessingRead
        //[const]  ILxImageProcessingRead:GetIdentifier
        //[const]  ILxImageProcessingRead:CopySettingsToFrameBuffer

/*
 * The service's main job is to create an object with an ILxImageProcessing object.
 */

        #define LXa_IMAGEPROCESSINGSERVICE	"imageprocessingservice"
        #define LXu_IMAGEPROCESSINGSERVICE	"2f403a5c-a6aa-4d5a-88f6-a2dff23da523"
        // [python] ILxImageProcessingService:Create	obj ImageProcessing

#endif
