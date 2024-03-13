/*
 * LX color module
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
#ifndef LX_color_H
#define LX_color_H

typedef struct vt_ILxColorModel ** ILxColorModelID;
typedef struct vt_ILxColor ** ILxColorID;

#include <lxcom.h>
#include <lxvmath.h>
#include <lxserver.h>


/*
 * Selection is usually performed by executing the select.color commands, which takes
 * each of the color command strings. as arguments,
 * Another powerful feature is support for ILxUIValueHints::ColorPickerCommands().
 * By providing the rgbCommand with a command that implements ILxCommand::UIValueHints(),
 * and then implementing ILxUIValueHints::ColorPickerCommands() from the returned
 * object, it is possible for the command itself to specify all of the other commands.
 * For example, item.channel command ("item.channel channelName ?") uses this mechanism
 * to check the channel's ILxChannelUI interface for an ILxUIValueHints object and returns
 * the ColorPickerCommands() implemented there, thus allowing a channel to specify its
 * own set of colors when it itself is selected, even if the channel referenced by
 * item.channel is not itself a color vector.
 */
typedef struct st_LXtColorPickerPacket {
        char		 rgbCommand[1024];
        char		 alphaCommand[1024];

        char		 rgbAltCommand[1024];
        char		 alphaAltCommand[1024];

        char		 useAltCommand[1024];
} LXtColorPickerPacket;


/*
 * It should be noted that color models should be "stateless".  This means that
 * everything you need to compute the values for a given method should be derived
 * from the arguments provided.  This ensures that a single color model instance
 * can be safely used across color picker views, and avoids unforeseen complications
 * from storing state in your object.
 * For speed, floats are used instead of doubles in all methods.  It is important
 * to keep this conversion in mind, as many other parts of the nexus architecture
 * use doubles for colors.  Be sure to double-check the datatype when passing
 * float/double pointers to avoid crashes.
 * Color models can have 1, 3 or 4 components.  Examples, include color temperature
 * (1), RGB/HSV/LAB (3) and CMYK (4).  Models with 2 or more than 4 components are
 * not currently supported.  This method must be implemented.
 * 
 * 
 * Each component can have its own datatype.  For example, the Hue component of
 * HSV is in degrees.  More generic units, like the components of RGB, can use
 * the "color1" datatype to have their units determined by the current color
 * system.  This must be a floating point datatype.  If not implemented, color1
 * is assumed.
 * 
 * Each component can also have its own min/max range.  For example, Hue ranges
 * from 0 to 360.  If not implemented, we default to 0.0 to 1.0.
 * 
 * The main job of a color model is to convert between RGB and a vector in the
 * model's space.  These functions facilitate this.  The vector is assumed to
 * have NumComponents() number of elements.  The output vectors will already be
 * allocated and simply need to be populated by the server.
 * 
 * By default, the color picker draws a rectangular image depecting a 2D slices
 * through the color space (or a 1D slice in the case of single-component modes).
 * It also will draw one or two horizontal strips representing the remaining axes
 * for three and four component modes.
 * The server can define it's own version of the 2D slice by implementing this
 * method.  An ILxImageID is provided to the caller, who is then responsible for
 * filling the image with a representation of the space given two numbered axes.
 * Note that this image may not initially be empty, and should be completely drawn
 * by the server.  The image will be RGBA32, and you should clear the alpha for
 * areas of the image that do not have contents.  vec[xAxis] and vec[yAxis] will
 * be undefined, but the remaining vec elements will be set from the current color.
 * If this method is not implemented, a default slice image is computed directly
 * by the color picker.
 * 
 * 
 * This second function is called to mark the current color in the image, or as
 * close as it can get.  The image will already be filled with a slice returned
 * by a previous call to DrawSlace(), and the server should simply draw a marker
 * at the position identified by vec.  If this method is not implemented, a default
 * marker will be drawn by the color picker itself.  The current fstops are also
 * provided so that the image can be drawn with the correct exposure.
 * The "down vector" is also provided to the slice.  This is the color that was
 * current at the time the mouse button went down, and may be different than the
 * current color provided by vec.  If no mouse buttons are down, this is the same
 * as vec.
 * 
 * Most clients will simply use vec to draw their marker.  Clients that do advanced
 * drawing (such as the swatches in the HSV color model) will use downVec as well,
 * updating the original downVec themselves during their FromSlicePos() call.  See
 * FromSlicePos() for more information.
 * 
 * 
 * This method is called to ask the color model if it needs to redraw the slice
 * when the current color has changed.  If it does not need to, we will simply
 * ask for a new marker to be drawn.  If this returns LXe_FALSE, we redraw the
 * slice; if it returns LXe_TRUE or any other success code, we reuse the existing
 * slice and ask for a new marker to be drawn over it (the marker is always drawn
 * fresh).  If not implemented, we will only redraw if a component of the vector
 * other than the xAxis or yAxis have changed; otherwise, we reuse the slice.
 * This is only called if you drew the slice yourself in the first palce, and
 * only if it is possible for the slice to be reused (because the image size or
 * colorspace didn't change, for example).
 * 
 * The server doesn't need to draw the marker itself, in which case it needs to
 * be able to convert the color vector into an XY coordinate within the slice
 * image for us.  This only needs to be implemented if the server is drawing
 * the image but not the marker position itself.  imgX and imgY are expected
 * to be coordinates with the image defined by imgW and imgH.
 * 
 * 
 * This reciprocal method gets a color vector given an XY coordinate in the
 * slice image itself.  Again the XY coordinates range from zero to imgW and
 * imgH, and the xAxis and yAxis of the vector provided should be set to the
 * values represented by those coordinates.  The remaining components do not
 * need to be set.
 * This function is usually called when the users is clicking and dragging over
 * the color picker.  The downVec represents the color at the time the mouse
 * button went down.  This value is initialized when the mouse button goes down,
 * and is not changed by the color picker until the next time the button goes
 * down.  This allows you to use it as a kind of scratch area, letting you
 * change the color between calls to FromSlicePos().  An example of where this
 * is useful is the HSV color model, which shows both a color wheel and a series
 * of swatches.  Clicking on a swatch would always use the downVec to compute a
 * new vec.  Meanwhile, clicking on the wheel should update downVec in case the
 * user drags from the wheel over to the swatch.
 * 
 * 
 * This method is used in 3D color models to get a "clean" color vector in the
 * model's space that the color picker will use as the basis for draw drawing
 * the horizontal strip.  The given component index in the vetor will be incremented
 * through the component's range and passed to the ToRGB() method to draw the strip,
 * so the vector should represent useful colors for the full range of the component.
 * For example, the Hue channel of an HSV model this might return a vector of
 * 0.0,1.0,1.0, while for value it might return 0.0,0.0,0.0.  Meanwhile, an RGB color
 * model would also present 0.0,0.0,0.0 for all of its components.
 * The vector passed to the method is initialized with the current color if dynamic is
 * true.  If false, a vector set to all zeros is passed in.  The dynamic flag allows
 * the client to decide if it wants to set all of the components of the vector itself
 * (when dynamic is off), or to set only some components and leave the others alone
 * (when dynamic is on).  This allows the saturation of HSV to be set to set the value
 * to 1 but leave the hue alone, causing the strip to reflect the current hue at
 * different saturation levels.
 * 
 * If this method isn't implemented, the vector provided is used directly as the base.
 * 
 */
typedef struct vt_ILxColorModel {
        ILxUnknown	 iunk;
        LXxMETHOD( int,
NumComponents) (
        LXtObjectID		  self);
        LXxMETHOD( LxResult,
ComponentType) (
        LXtObjectID		  self,
        unsigned		  component,
        const char		**type);
        LXxMETHOD( LxResult,
ComponentRange) (
        LXtObjectID		  self,
        unsigned		  component,
        float			 *min,
        float			 *max);
        LXxMETHOD( LxResult,
ToRGB) (
        LXtObjectID		  self,
        const float		 *vector,
        float			 *rgb);

        LXxMETHOD( LxResult,
FromRGB) (
        LXtObjectID		  self,
        const float		 *rgb,
        float			 *vector);
        LXxMETHOD( LxResult,
DrawSlice) (
        LXtObjectID		  self,
        LXtObjectID		  image,
        unsigned		  xAxis,
        unsigned		  yAxis,
        const float		 *vec);
        LXxMETHOD( LxResult,
DrawSliceMarker) (
        LXtObjectID		  self,
        LXtObjectID		  image,
        unsigned		  xAxis,
        unsigned		  yAxis,
        const float		 *downVec,
        const float		 *vec);
        LXxMETHOD( LxResult,
CanSliceBeReused) (
        LXtObjectID		  self,
        unsigned		  xAxis,
        unsigned		  yAxis,
        const float		 *oldVec,
        const float		 *newVec);
        LXxMETHOD( LxResult,
ToSlicePos) (
        LXtObjectID		  self,
        unsigned		  xAxis,
        unsigned		  yAxis,
        unsigned		  imgW,
        unsigned		  imgH,
        const float		 *vec,
        unsigned		 *imgX,
        unsigned		 *imgY);
        LXxMETHOD( LxResult,
FromSlicePos) (
        LXtObjectID		  self,
        unsigned		  xAxis,
        unsigned		  yAxis,
        unsigned		  imgW,
        unsigned		  imgH,
        unsigned		  imgX,
        unsigned		  imgY,
        float			 *downVec,
        float			 *vec );
        LXxMETHOD( LxResult,
StripBaseVector) (
        LXtObjectID		  self,
        unsigned		  axis,
        int			  dynamic,
        float			 *vec );
} ILxColorModel;

/*
 * These return the RGB and alpha components.  The color argument must be a
 * three element float array, which will be filled in with the color.
 * 
 * Alpha is optional.  If not implemented, it is assumed to be 1.0.
 * 
 * This returns the optional color model name, and a the color in the model's
 * model's space.  These may not be implemented, in which case the raw RGB
 * values should be used.
 * 
 * A color model can contain up to four components, and thus a four element
 * float array must be provided, which will be filled in with the vector.
 */
typedef struct vt_ILxColor {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Color) (
        LXtObjectID		  self,
        float			 *color);
        LXxMETHOD( LxResult,
Alpha) (
        LXtObjectID		  self,
        float			 *alpha);
        LXxMETHOD( LxResult,
ColorModel) (
        LXtObjectID		  self,
        const char		**model);
        LXxMETHOD( LxResult,
ColorInModelSpace) (
        LXtObjectID		  self,
        float			 *vec);
} ILxColor;


        #define ID_COLR		MK_ID('C','O','L','R')	// Color Picker Packet

/*
 * modo supports an extensible set of color models that define how the color picker
 * is displayed.  Each color model can have 1, 3 or 4 components.  They are
 * represented by the ILxColorModel interface.  We internally support the RGB color
 * model, but other models can be defined as needed by plug-ins.
 */

        #define LXu_COLORMODEL		"67d3d952-4ab0-49e5-8f9e-6c889b00f253"
        #define LXa_COLORMODEL		"colormodel"
        //[export] ILxColorModel colm
        //[local]  ILxColorModel
        //[python] ILxColorModel:ToRGB:rgb		vector (3)
        //[python] ILxColorModel:FromRGB:rgb		vector (3)
        //[python] ILxColorModel:FromRGB:vector		vector
        //[python] ILxColorModel:FromSlicePos:downVec	vector
        //[python] ILxColorModel:FromSlicePos:vec	vector
        //[python] ILxColorModel:StripBaseVector:vec	vector
        //[python] ILxColorModel:CanSliceBeReused	bool

/*
 * We support a simple notifier that can be used by custom color picker commands
 * so that they can be made aware of changes to the system.  This is pretty
 * brute-force, in that it reports any change to the current color, the color
 * model, the axis or the color unit system, sending VALUE and DISABLE events
 * to any listening clients.
 */

        #define LXs_NOTIFIER_COLOR_CHANGED	"notifier.colorChanged"

/*
 * ILxColor defines a color, and is primarily used as a source for drag and drop
 * operations that represent a color.  The object contains the RGB color (which
 * may be HDR), as well as an optional color model named and the color in that
 * model's space.  An optional alpha is also supported.
 */

        #define LXu_COLOR		"7c084df3-adb6-48ee-92d3-032d90efea05"
        #define LXa_COLOR		"color"
        //[export] ILxColor color
        //[local]  ILxColor

/*
 * Individual components within a color model can support value presets when
 * their control is shown in the UI.  Each component can have its own value
 * preset cookie.  The format is "<index>:<cookie> <index:cookie>" etc.
 */

        #define LXsCOLORMODEL_VALUEPRESET	"colorModelValuePresetCookieTag"

#endif
