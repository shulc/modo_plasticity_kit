/*
 * LX imagemon module
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
#ifndef LX_imagemon_H
#define LX_imagemon_H

typedef struct vt_ILxImageMonitor ** ILxImageMonitorID;
typedef struct vt_ILxImageMonitorService ** ILxImageMonitorServiceID;

#include <lxcom.h>
#include <lxvmath.h>
#include <lxserver.h>
#include <lximage.h>
#include <lxrndjob.h>
#include <lxcommand.h>


/*
 * The selection packet for the image monitor is an ILxImageID or ILxFrameBufferID
 * buffer index pair and an optional image source name.  The ILxImageID is the
 * image to be analyzed by the monitor; if NULL, then the buffer index within the
 * ILxFrameBufferID is to be used.  The image source allows different monitors to
 * look at different images from different parts of the system. For example, one
 * viewport might be set to only monitor clip items, while another might be set to
 * analyse images selected in the render window.
 * x1, y1, x2 and y2 define an area within the image to be analyzed. An extent of
 * 0,0 to 1,1 indicates that the entire image should be analyzed.
 * The packet also contains an optional ILxImageProcessing object, which clients
 * can use to set image processing operations that the image source will apply to
 * the image for display to the user.  The image processing object has its
 * identifier set to the image source, which means that setting its properties will
 * automatically send a notification to the image source, which in turn will apply
 * said processing to the image.  If the source doesn't support processing, this
 * will be NULL.  Note that although this is a read/write obejct, clients should
 * really only use this for reading unless they are executing a command.
 * 
 * For speed, the packet may also contain a thumbnail image.  This image already
 * has image processing applied to it, and is large enough to be useful for monitor
 * analysis.  For example, render window sources provide a 256 pixel wide image.
 * Clients should be able to handle cases where the thumbnail is NULL.
 * 
 */
typedef struct st_LXtImageMonitorPacket {
        ILxImageID		 image;

        ILxFrameBufferID	 frameBuffer;
        int			 bufferIndex;

        double			 x1, y1, x2, y2;

        ILxImageProcessingID	 imageProc;

        ILxImageID		 processedThumbnail;

        char			 imageSource[256];
} LXtImageMonitorPacket;


/*
 * This is called with the image (ILxImageID) or frame buffer (ILxFrameBufferID)
 * to be analyzed.  The new image may be NULL if there is not currently an image
 * to be analyzed, and it may be the same image as previously passed in if the
 * image has changed for some reason.  If imageToAnalyze is NULL, frameBufferToAnalyze
 * may be non-NULL, in which case bufferIndex is the index of the specific buffer
 * within the frame buffer to be analyzed.  If both imageToAnalyze and
 * frameBufferToAnalyze are NULL, no image is selected and the monitor should
 * draw in a default or disabled style.
 * x1, y1, xc2 and y2 define a region within the image to analyze.  If these are
 * 0,0 and 1,1, then the entire image should be analyzed; otherwise, only the
 * specified region should be analyzed.
 * 
 * The ILxImageProcessingRead object is also provided, although this may be
 * NULL if processing options are not available.  Clients should use this to
 * read the properties in case they want to apply the effects of said options
 * to the monitor's display; they should use commands to change the properties.
 * It is important to note that the image/frame buffer will be a "clean",
 * unprocessed image, and will not have any image processing options applied
 * to it.
 * 
 * To avoid needing to process the full-sized image repeatedly on an
 * ImageProcChanged() event, this method is also called with a smaller
 * thumbnail image that already has processing applied.  The image is
 * large enough to be suitable for image analysis.  Note that this may be
 * NULL.
 * 
 * 
 * This method is called when the properties of the ILxImageProcessingRead object
 * have changed.  Monitors can use this to refresh themselves using image/frame
 * buffers and the ILxImageProcessingRead object provided to them through their
 * Image() method.  Note that Image() is also called with an updated processed
 * thumbnail suitable for analysis whenever the image processing object changes.
 * 
 * This returns the minimum and maximum aspect ratio for the monitor.  The image
 * provided (to draw the monitor into) will never exceed this aspect.  This is
 * useful for monitors like histograms that look better when laid out horizontally,
 * but don't look like much when stretched vertically.  If not implemented or if
 * one of the values is set to 0, the aspect is unconstrained.
 * 
 * This is called to draw the monitor into the ILxImageWriteID provided.
 * 
 * Image monitors accept images from an image source.  The image source is
 * set through the viewport, and is provided to the monitor through this method.
 * Clients can use the image source string to execute commands that target
 * the image source, respond to monitor-specific commands (like setting
 * ranges for display) based on image source, and so on.
 * For example, a histogram monitor for the clip items image source might be
 * embedded in the clip item's properties.  A command to change the channels
 * shown in the histogram might include the image source as an argument, so
 * that just that monitor's channel option can be changed, without affecting
 * the other histogram monitors, such as the one used by the Render Window
 * histogram.  This argument would also be used when querying the command for
 * a value.
 * 
 * This method will be called whenever the image source changes.  The server
 * should make a copy of the string for future reference.
 * 
 * 
 * We support limited mousing support through the use of the Mouse...() methods.
 * We have a down/move/up cycle that occurs when the mouse button is clicked over
 * the montior.  The server is provided with the down x/y as well as the current
 * x/y of the mosue relative to the top-left corner of the monitor.  Only the
 * left mouse button is supported at this time.  The dimensions of the drawing
 * monitor are also passed to each method.
 * 
 * We also support tracking, which is when the mouse is moving over the view but
 * is not being clicked.  TrackEnter() is called when the mouse moves into the
 * monitor, and TrackExit() is called when the mouse leaves the monitor.  Track()
 * is moved while the mouse moves over the view with the current mouse coordinates
 * and the size of the monitor.
 * 
 * Tooltips are also supported.  As usual, the tooltip should be composed from
 * a message table lookup.  Returning LXe_NOTIMPL or any other failure code
 * will result in no tooltip being displayed.
 */
typedef struct vt_ILxImageMonitor {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Image) (
        LXtObjectID		  self,
        LXtObjectID		  imageToAnalyze,
        LXtObjectID		  frameBufferToAnalyze,
        int			  bufferIndex,
        double			  x1,
        double			  y1,
        double			  x2,
        double			  y2,
        LXtObjectID		  imageProcessingRead,
        LXtObjectID		  processedThumbnail);
        LXxMETHOD( LxResult,
ImageProcChanged) (
        LXtObjectID		  self);
        LXxMETHOD( LxResult,
AspectRange) (
        LXtObjectID		  self,
        double			 *minAspect,
        double			 *maxAspect,
        double			 *idealAspect);
        LXxMETHOD( LxResult,
Draw) (
        LXtObjectID		  self,
        LXtObjectID		  imageForDrawing);
        LXxMETHOD( LxResult,
ImageSource) (
        LXtObjectID		  self,
        const char		 *source);
        LXxMETHOD( LxResult,
MouseDown) (
        LXtObjectID		  self,
        int			  startx,
        int			  starty,
        int			  w,
        int			  h );

        LXxMETHOD( LxResult,
MouseMove) (
        LXtObjectID		  self,
        int			  startx,
        int			  starty,
        int			  cx,
        int			  cy,
        int			  w,
        int			  h );

        LXxMETHOD( LxResult,
MouseUp) (
        LXtObjectID		  self,
        int			  startx,
        int			  starty,
        int			  cx,
        int			  cy,
        int			  w,
        int			  h );
        LXxMETHOD( LxResult,
MouseTrackEnter) (
        LXtObjectID		  self);

        LXxMETHOD( LxResult,
MouseTrack) (
        LXtObjectID		  self,
        int			  cx,
        int			  cy,
        int			  w,
        int			  h );

        LXxMETHOD( LxResult,
MouseTrackExit) (
        LXtObjectID		  self);
        LXxMETHOD( LxResult,
ToolTip) (
        LXtObjectID		  self,
        int			  cx,
        int			  cy,
        int			  w,
        int			  h,
        char			 *buf,
        unsigned		  len);
} ILxImageMonitor;

/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.  This is not currently implemented.
 * These methods allow the server list to be walked, and allow a server to be
 * looked up by name.  When a COM object is returned, the client is responsible
 * for releasing it as usual.
 * 
 * These methods return the name and username of a server given an index.
 * 
 * These can be used to get a list of image sources names, as defined through the
 * config system.
 * 
 * Clients can use this to change the current image in an image source.  This
 * in turn will ask associated views to analyze the new image.  Either the
 * image (ILxImageID) or frameBuffer (ILxFrameBufferID) and bufferIndex should
 * be set; if they're NULL, then no image is to be analyzed.  x1/y1 and x2/y2
 * define a window into the image to the analyzed; if 0,0 and 1,1, the entire
 * image is analyzed.  Images are set for a specific image source, and thus
 * only affects views monitoring that source.  Note that imageProc is an
 * object with an ILxImageProcessing interface, and is optional.
 * processedThumbnail is also optional, but is recommended.
 * 
 * Clients can use this to get the current image from an image source.  If
 * a pointer is NULL, that property won't be returned.
 * 
 * This can also be returned as a packet.
 * 
 * Sometimes image analysis can take a while.  This utility can be used to
 * tell all views with a particular image source to ask their server to
 * redraw their view.
 * If immediate is true, the view will be redrawn immediately.  This is
 * useful for interaction operations using the mousing methods of the
 * monitor.  If false, the view will be updated during at the normal
 * redrawing time.
 * 
 */
typedef struct vt_ILxImageMonitorService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
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
SourceCount) (
        LXtObjectID		 self,
        int			*count);

        LXxMETHOD(  LxResult,
SourceNameByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**name);

        LXxMETHOD(  LxResult,
SourceUserNameByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		**username);
        LXxMETHOD(  LxResult,
SetImage) (
        LXtObjectID		 self,
        const char		*imageSource,
        LXtObjectID		 image,
        LXtObjectID		 frameBuffer,
        int			 bufferIndex,
        double			 x1,
        double			 y1,
        double			 x2,
        double			 y2,
        LXtObjectID		 imageProc,
        LXtObjectID		 processedThumbnail );
        LXxMETHOD(  LxResult,
GetImage) (
        LXtObjectID		  self,
        const char		 *imageSource,
        void			**ppvObj_image,
        void			**ppvObj_frameBuffer,
        int			 *bufferIndex,
        double			 *x1,
        double			 *y1,
        double			 *x2,
        double			 *y2,
        void			**ppvObj_imageProc,
        void			**ppvObj_processedThumbnail );
        LXxMETHOD(  LxResult,
GetImagePacket) (
        LXtObjectID			  self,
        const char			 *imageSource,
        const LXtImageMonitorPacket	**packet );
        LXxMETHOD(  LxResult,
RefreshViews) (
        LXtObjectID		 self,
        const char		*imageSource,
        int			 immediate );
} ILxImageMonitorService;

/*
 * modo supports an extensible set of image analysis monitors.  These are essentially
 * blank canvases into which the plug-in can draw a monitor displaying an analysis of
 * the image provided.  Common monitors include histograms and vectorscopes.
 */

        #define LXu_IMAGEMONITOR	"5ef021ed-a2e3-48d3-aba1-7cbb815f15b7"
        #define LXa_IMAGEMONITOR	"imagemonitor"
        //[export] ILxImageMonitor imon
        //[local]  ILxImageMonitor

/*
 * The global image monitor service provides a few utility functions to clients.
 */

        #define LXu_IMAGEMONITORSERVICE	"f59258f8-3e86-408f-9e92-f81a21d01bde"
        #define LXa_IMAGEMONITORSERVICE	"imagemonitorservice"
        // [python] ILxImageMonitorService:ServerByIndex	obj ImageMonitor
        // [python] ILxImageMonitorService:ServerLookup		obj ImageMonitor

/*
 * We also define a notifier, "notifier.imagemonitor.source", which sends
 * a notification whenever the image source (as provided through the notifier's
 * argument string) changes with the flags provided.  For example, "renderWindow+vd"
 * will send DISABLE and VALUE notifications when the "renderWindow" image source
 * changes.
 */

        #define	LXsIMAGEMONITOR_SOURCE_NOTIFIER	"notifier.imagemonitor.source"

/*
 * Another notifier is used to listen for changes to an ILxImageProcessing object, as described
 * in lx_rndjob.hpp.  The notifier's argument format is:
 * 	<identifier> <attribute>+vdlt
 * <identifier> is the identifier string (often the an image source) set in the processing object.
 * <attribute> is the specific attribute to listen for, as defined in the text hitns array below.
 * +vdlt are any combination of the LXfCMDNOTIFY_ hints, indicating that when the specific attribute
 * changes, it should send a value, label, disable or datatype invalidation to the UI.
 * 
 */

        #define	LXsIMAGEPROC_NOTIFIER	"notifier.imageproc"

static LXtTextValueHint	 notifierImageProcEventHints[] = {					// Events as a text hints array
        // Event 
        LXiIMAGEPROC_EVENT_CHANGED_SOURCE_IMAGE_GAMMA,			"sourceImageGamma",
        LXiIMAGEPROC_EVENT_CHANGED_SAVE_PROCESSED,			"saveProcessed",
        LXiIMAGEPROC_EVENT_CHANGED_BLOOM_ENABLED,			"bloomEnabled",
        LXiIMAGEPROC_EVENT_CHANGED_BLOOM_THRESHOLD,			"bloomThreshold",
        LXiIMAGEPROC_EVENT_CHANGED_BLOOM_RADIUS,			"bloomRadius",

        LXiIMAGEPROC_EVENT_CHANGED_VIGNETTE_AMOUNT,			"vignAmt",

        LXiIMAGEPROC_EVENT_CHANGED_RESPECT_RENDER_VIEW_GAMMA_PREF,	"respectRenderViewGammaPref",

        LXiIMAGEPROC_EVENT_CHANGED_INPUT_BLACK_LEVEL,			"inputBlackLevel",
        LXiIMAGEPROC_EVENT_CHANGED_INPUT_GRAY_LEVEL,			"inputGrayLevel",
        LXiIMAGEPROC_EVENT_CHANGED_INPUT_WHITE_LEVEL,			"inputWhiteLevel",

        LXiIMAGEPROC_EVENT_CHANGED_INPUT_MIN_RGB_LEVEL,			"inputMinRGBLevel",
        LXiIMAGEPROC_EVENT_CHANGED_INPUT_GRAY_RGB_LEVEL,		"inputGrayRGBLevel",
        LXiIMAGEPROC_EVENT_CHANGED_INPUT_MAX_RGB_LEVEL,			"inputMaxRGBLevel",

        LXiIMAGEPROC_EVENT_CHANGED_TONE_MAPPING,			"toneMapping",
        LXiIMAGEPROC_EVENT_CHANGED_HUE_OFFSET,				"hueOffset",
        LXiIMAGEPROC_EVENT_CHANGED_SATURATION,				"saturation",
        LXiIMAGEPROC_EVENT_CHANGED_COLORIZATION,			"colorization",
        LXiIMAGEPROC_EVENT_CHANGED_TARGET_COLOR,			"targetColor",

        LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_BLACK_LEVEL,			"outputBlackLevel",
        LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_WHITE_LEVEL,			"outputWhiteLevel",

        LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_MIN_RGB_LEVEL,		"outputMinRGBLevel",
        LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_MAX_RGB_LEVEL,		"outputMaxRGBLevel",

        LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_GAMMA,			"outputGamma",

        // Invalidation flags for the event
        LXfCMDNOTIFY_VALUE,			"+v",
        LXfCMDNOTIFY_LABEL,			"+l",
        LXfCMDNOTIFY_DISABLE,			"+d",
        LXfCMDNOTIFY_DATATYPE,			"+t",
        0, 					 NULL
};

        #define LXfIPEVENT_EVENT		 0xFFFFFFF0			// Mask off the event
        #define LXfIPEVENT_FLAGS		 0x0000000F			// Mask off the invalidation flags

        #define LXxIPEVENT_EVENT(e)		 (LXfIPEVENT_EVENT & (e))	// Macro to mask off the event
        #define LXxIPEVENT_FLAGS(e)		 (LXfIPEVENT_FLAGS & (e))	// Macro to mask off the invalidation flags

#endif
