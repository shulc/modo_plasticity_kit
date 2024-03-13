/*
 * LX image module
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
#ifndef LX_image_H
#define LX_image_H

typedef struct vt_ILxImage ** ILxImageID;
typedef struct vt_ILxImageSegment ** ILxImageSegmentID;
typedef struct vt_ILxImageWrite ** ILxImageWriteID;
typedef struct vt_ILxIndexImage ** ILxIndexImageID;
typedef struct vt_ILxIndexImageWrite ** ILxIndexImageWriteID;
typedef struct vt_ILxLayeredImage ** ILxLayeredImageID;
typedef struct vt_ILxLayeredImageWrite ** ILxLayeredImageWriteID;
typedef struct vt_ILxTileImage ** ILxTileImageID;
typedef struct vt_ILxImageLoaderTarget1 ** ILxImageLoaderTarget1ID;
typedef struct vt_ILxImageLoaderTarget ** ILxImageLoaderTargetID;
typedef struct vt_ILxImageLevelSample ** ILxImageLevelSampleID;
typedef struct vt_ILxImageService ** ILxImageServiceID;
typedef struct vt_ILxImageBlockCodec ** ILxImageBlockCodecID;
typedef struct vt_ILxImageFilter ** ILxImageFilterID;
typedef struct vt_ILxImageFilterSample ** ILxImageFilterSampleID;
typedef struct vt_ILxImageFilterMetrics ** ILxImageFilterMetricsID;
typedef struct vt_ILxImageFilterMetrics1 ** ILxImageFilterMetrics1ID;
typedef struct vt_ILxMovie ** ILxMovieID;

#include <lxcom.h>
#include <lxio.h>
#include <lxserver.h>
#include <lxvmath.h>


        typedef unsigned int	 LXtPixelFormat;
        typedef unsigned int	 LXtProcessHint;
        typedef unsigned char	 LXtImageByte;
        typedef float		 LXtImageFloat;
        typedef unsigned int	 LXtImageIndex;
        typedef LXtImageFloat	 LXtColorRGB[3];
        typedef LXtImageFloat	 LXtColorRGBA[4];


/*
 * Legacy struct, still provided for older image loaders.
 */
typedef struct st_LXtImageTarget1 {
        LXtPixelFormat		 type;
        unsigned int		 w, h, ncolor;
} LXtImageTarget1;

/*
 * Sampling of a level is done using an array of structures, each with a pixel
 * position in the level and a location to receive the RGBA data in floating
 * point format.
 */
typedef struct st_LXtImageSample {
        unsigned		 x;
        unsigned		 y;
        LXtImageFloat		*rgba;
} LXtImageSample;

/*
 * This interface can be used to get the metrics filled in by the generator.
 * Since the generator is responsible for this, this function may cause the stack
 * to generate a with VCEVALf_METRICS_ONLY specifically for this information.
 */
typedef struct st_LXtImageMetrics {
        int		 maxRes[2];
        int		 pixelType;
        double		 aspect;
        char		 filename[512];
        char		 format[512];
        int		 layer;
        int		 colorspaceDepth;
        char		 colorspace[512];
        char		 archiveFile[512];
        char		 archiveKey[768];
        int		 isStatic;
} LXtImageMetrics;

/*
 * This interface was retired in modo 14.1.
 */
typedef struct st_LXtImageMetrics1 {
        int		 maxRes[2];
        int		 pixelType;
        double		 aspect;
        char		 filename[512];
        char		 format[512];
        int		 layer;
        int		 colorspaceDepth;
        char		 colorspace[512];
        char		 archiveFile[512];
        char		 archiveKey[768];
} LXtImageMetrics1;


/*
 * The basic image interface allows clients to read colored pixels or entire
 * lines.  When reading pixels the client should always ask for an RGBA format,
 * but for lines the full range of format conversions is possible.
 */
typedef struct vt_ILxImage {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Image methods
        LXxMETHOD( void,
Size) (
        LXtObjectID		 self,
        unsigned int		*w,
        unsigned int		*h);

        LXxMETHOD( LXtPixelFormat,
Format) (
        LXtObjectID		 self);
// QWEB_MACRO_END - SDK Common: Image methods

        LXxMETHOD( LxResult,
GetPixel) (
        LXtObjectID		 self,
        unsigned int		 x,
        unsigned int		 y,
        LXtPixelFormat		 type,
        void			*pixel);

        LXxMETHOD( const void *,
GetLine) (
        LXtObjectID		 self,
        unsigned int		 y,
        LXtPixelFormat		 type,
        void			*buf);
} ILxImage;

/*
 * An image segment is a sub-range of pixels within a scanline, which
 * is always read in FP RGBA format, and written in any given format.
 */
typedef struct vt_ILxImageSegment {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
GetSegment) (
        LXtObjectID		 self,
        unsigned int		 y,
        unsigned int		 left,
        unsigned int		 right,
        LXtImageFloat		*rgba);

        LXxMETHOD( LxResult,
SetSegment) (
        LXtObjectID		 self,
        unsigned int		 y,
        unsigned int		 left,
        unsigned int		 right,
        LXtPixelFormat		 type,
        const void		*line);
} ILxImageSegment;

/*
 * Writing to an image requires a different interface.  This provides methods
 * for assigning color values to pixels or lines.  Not all images will be
 * writable.
 */
typedef struct vt_ILxImageWrite {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Image methods
        LXxMETHOD( void,
Size) (
        LXtObjectID		 self,
        unsigned int		*w,
        unsigned int		*h);

        LXxMETHOD( LXtPixelFormat,
Format) (
        LXtObjectID		 self);
// QWEB_MACRO_END - SDK Common: Image methods
// QWEB_MACRO_BEGIN - SDK Common: Image Write methods
        LXxMETHOD(  LxResult,
AddAttribute) (
        LXtObjectID		 self,
        const char		*name,
        const char		*type,
        unsigned		*index);
// QWEB_MACRO_END - SDK Common: Image Write methods

        LXxMETHOD( LxResult,
SetPixel) (
        LXtObjectID		 self,
        unsigned int		 x,
        unsigned int		 y,
        LXtPixelFormat		 type,
        const void		*pixel);

        LXxMETHOD( LxResult,
SetLine) (
        LXtObjectID		 self,
        unsigned int		 y,
        LXtPixelFormat		 type,
        const void		*line);

} ILxImageWrite;

/*
 * An index image is one that stores index values at the pixel locations and
 * uses a lookup table to get the color.  While the ILxImage interface gets
 * the color values at each pixel, this interface allows access to the
 * underlying index and color map.
 */
typedef struct vt_ILxIndexImage {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Image methods
        LXxMETHOD( void,
Size) (
        LXtObjectID		 self,
        unsigned int		*w,
        unsigned int		*h);

        LXxMETHOD( LXtPixelFormat,
Format) (
        LXtObjectID		 self);
// QWEB_MACRO_END - SDK Common: Image methods

        LXxMETHOD( LxResult,
MapSize) (
        LXtObjectID		 self,
        unsigned		*numColors);

        LXxMETHOD( LxResult,
GetIndex) (
        LXtObjectID		 self,
        unsigned int		 x,
        unsigned int		 y,
        LXtImageIndex		*index);

        LXxMETHOD( LxResult,
GetMap) (
        LXtObjectID		 self,
        LXtImageIndex		 index,
        LXtPixelFormat		 type,
        void			*pixel);
} ILxIndexImage;

/*
 * Writing to an index image can only be done with one of these interfaces.
 */
typedef struct vt_ILxIndexImageWrite {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Image methods
        LXxMETHOD( void,
Size) (
        LXtObjectID		 self,
        unsigned int		*w,
        unsigned int		*h);

        LXxMETHOD( LXtPixelFormat,
Format) (
        LXtObjectID		 self);
// QWEB_MACRO_END - SDK Common: Image methods

// QWEB_MACRO_BEGIN - SDK Common: Image Write methods
        LXxMETHOD(  LxResult,
AddAttribute) (
        LXtObjectID		 self,
        const char		*name,
        const char		*type,
        unsigned		*index);
// QWEB_MACRO_END - SDK Common: Image Write methods

        LXxMETHOD( LxResult,
SetIndex) (
        LXtObjectID		 self,
        unsigned int		 x,
        unsigned int		 y,
        LXtImageIndex		 index);

        LXxMETHOD( LxResult,
SetMap) (
        LXtObjectID		 self,
        LXtImageIndex		 index,
        LXtPixelFormat		 type,
        const void		*pixel);
} ILxIndexImageWrite;

/*
 * In many cases it is useful to add channels to images beyond the basic R, G, B, and A.
 * In other cases, it is useful to preserve multiple sub-images in a composition. These
 * requirements can be met with a layered image object, consisting of a list of named,
 * independent sub-images, each with their own dimensions, offset, and pixel type.
 * Interlayer blending information is also associated with each layer, Photoshop style.
 * - Size
 * This returns the bounds of the image composition. While the combination
 * of layer sizes and offsets makes it possible that some layers' pixels will
 * not all be in bounds, the entire composition will be cropped at (0,0) to (w,h).
 * 
 * Adding a standard format() method here would allow this object to masquerade as
 * an ILxImage object...  probably more confusing than useful.
 * - Count
 * 	return number of layers.
 * 
 * - Image
 * 	return ILxImage for layer at 'index'.
 * 
 * - Name
 * 	return name for layer at 'index'.
 * 
 * - Type
 * 	return type string and flags for layer at 'index'.
 * 
 * 
 * - Offset
 * 	return pixel offset for layer at 'index' relative to complete
 * 	layered image composition..
 * - Blend
 * 	returns the opacity and the image blend mode for layer at 'index'.
 * 	The image blend mode is one of the LXi_IBM_ modes.
 * 
 * 
 * - ChannelName
 * 	Pass back the name of the channel at the given layer and channel
 * 	index, which may be overridden by the user by inserting semicolon
 * 	delimiters in between each channel name in the Shader Tree.
 * 
 * - Parent
 * 	Returns the parent layer index, or -1 if there is no parent
 * - IsGroup
 * 	Returns true if the layer is a group layer
 * 
 */
typedef struct vt_ILxLayeredImage {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Size) (
        LXtObjectID		 self,
        unsigned int		*w,
        unsigned int		*h);
        LXxMETHOD( unsigned int,
Count) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Image) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Name) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **name);

        LXxMETHOD( LxResult,
Type) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		*flags,
        const char	       **type);
        LXxMETHOD( LxResult,
Offset) (
        LXtObjectID		 self,
        unsigned int		 index,
        int			*x,
        int			*y);

        LXxMETHOD( LxResult,
Blend) (
        LXtObjectID		 self,
        unsigned int		 index,
        float			*opacity,
        unsigned int		*mode);
        LXxMETHOD( LxResult,
ChannelName) (
        LXtObjectID		 self,
        unsigned		 layerIndex,
        unsigned		 channelIndex,
        const char		**name);
        LXxMETHOD( LxResult,
Parent) (
        LXtObjectID		 self,
        unsigned		 layerIndex,
        int			*parentIndex);

        LXxMETHOD( LxResult,
IsGroup) (
        LXtObjectID		 self,
        unsigned		 layerIndex,
        unsigned int		*isGroup);
} ILxLayeredImage;

/*
 * Layered image objects will provide an ILxLayeredImageWrite interface for writing.
 * - AddLayer
 * This is the way a layered image is actually created, adding layers by passing
 * in ILxImage objects.  The image object will be locked and released by the
 * layered image, so clients may release the image after setting the layer.
 * - SetType
 * Layer type and flags can be set using this function.
 * 
 * - SetOffset
 * Pixel offsets for a layer are set with this function.
 * 
 * - SetBlending
 * The blending parameter (or opacity) and the blending mode are set with this function.
 * A list of modes should appear here shortly...
 * 
 */
typedef struct vt_ILxLayeredImageWrite {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
AddLayer) (
        LXtObjectID		 self,
        LXtObjectID		 image,
        const char		*name,
        const char		**channelNames);

        LXxMETHOD( LxResult,
SetType) (
        LXtObjectID		 self,
        unsigned int		 index,
        int			 flags,
        const char		*type);

        LXxMETHOD( LxResult,
SetOffset) (
        LXtObjectID		 self,
        unsigned int		 index,
        int			 x,
        int			 y);

        LXxMETHOD( LxResult,
SetBlending) (
        LXtObjectID		 self,
        unsigned int		 index,
        float			 blend,
        const char		*mode);

        LXxMETHOD(  LxResult,
AddAttribute) (
        LXtObjectID		 self,
        const char		*name,
        const char		*type,
        int			*index);

} ILxLayeredImageWrite;

/*
 * The tiled image interface provides a way for clients to implement images using
 * tile trees. Tiles will themselves simply be images, so we can manage a global cache of
 * them internally rather than depending on each implementation to manage an internal cache.
 * A tile tree is a collection of "levels", which are intended to be images of decreasing size.
 * Each image level is broken into tiles, which allows us to only work on small portions of the image
 * instead of loading an entire image. Typically, the image levels decrease in size by power of two.
 * For example, one dimension of a normal tile tree of an image with size 1024x1024, and tiles of size 256x256,
 * would look like this:
 * 
 * Level 2		   _
 * Level 1		  _ _
 * Level 0		_ _ _ _
 * 
 * Where each _ represents a tile.
 * 
 * One thing to note is that the meaning of "level" is reverse from ImageLevelSample;
 * level 0 is the base of the tile tree, where each tile is the original size, and the highest
 * value of level will have a single tile.
 * 
 * Implementations of the TileImage interface are only required to be able to get the tiles at
 * level 0; they may require the clients to generate tiles above level 0 by resizing the tiles
 * below them.
 * 
 * 	- LevelCount
 * LevelCount returns the number of levels in the tile tree.
 * 
 * 
 * 	- GetTile
 * GetTile is the direct way of getting a tile from the tile image. In general,
 * this will be loaded directly from the file off disk. Tiles will simply be an
 * ILxImageID. These should be created by the implementation, and the client will release them.
 * It should return LXe_OK if it's okay, but LXe_OUTOFBOUNDS if the tile isn't in the image.
 * 
 * 
 * 	- GetTileSize
 * GetTileSize will determine the width and height of a given tile, and place it
 * in *width and *height. For a given TileImage, these will usually be constant
 * and equal except for boundary tiles.
 * It should return LXe_OK if it's okay, but LXe_OUTOFBOUNDS if the tile isn't in the image.
 * 
 * 
 * 	- GetLevelSize
 * GetLevelSize will determine the size of an entire level both in pixel counts and tile counts.
 * It will place the former in *width and *height, and the latter in *tilesWidth and *tilesHeight.
 * Any of the pointers should be able to be NULL, if the caller only wants to get the tile dimensions,
 * for instance. It should return LXe_OUTOFBOUNDS if the level isn't in the image.
 * 
 * 
 * 	- DetermineTile
 * DetermineTile will determine which tile contains a given pixel at a given level, and place it
 * in *tileX and *tileY.
 * It should return LXe_OK normally, but LXe_OUTOFBOUNDS if the pixel isn't on that level.
 * 
 * 
 * 	- DeterminePixel
 * DeterminePixel will take in a pixel position X and Y for a given level,
 * and put in *adjX and *adjY the position of the pixel within the tile that contains it.
 * It should return LXe_OK normally, but LXe_OUTOFBOUNDS if the pixel isn't on that level.
 * 
 */
typedef struct vt_ILxTileImage {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
LevelCount) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
GetTile) (
        LXtObjectID		  self,
        unsigned int		  level,
        unsigned int		  tileX,
        unsigned int		  tileY,
        void			**ppvObj);
        LXxMETHOD( LxResult,
GetTileSize) (
        LXtObjectID		 self,
        unsigned int		 level,
        unsigned int		 tileX,
        unsigned int		 tileY,
        unsigned int		*width,
        unsigned int		*height);
        LXxMETHOD( LxResult,
GetLevelSize) (
        LXtObjectID		 self,
        unsigned int		 level,
        unsigned int		*width,
        unsigned int		*height,
        unsigned int		*tilesWidth,
        unsigned int		*tilesHeight);
        LXxMETHOD( LxResult,
DetermineTile) (
        LXtObjectID		 self,
        unsigned int		 level,
        unsigned int		 x,
        unsigned int		 y,
        unsigned int		*tileX,
        unsigned int		*tileY);
        LXxMETHOD( LxResult,
DeterminePixel) (
        LXtObjectID		 self,
        unsigned int		 level,
        unsigned int		 x,
        unsigned int		 y,
        unsigned int		*adjX,
        unsigned int		*adjY);
} ILxTileImage;

/*
 * Images can be loaded and saved with appropriate servers of the loader and
 * saver class.  Loading can be opaque for disk-based access, although most
 * loaders are currently direct, so a format, type, size and number of colors
 * must be specified by the recognition method to allow the host to create a
 * suitable image object to receive the data. This is done using a target
 * interface.
 */
typedef struct vt_ILxImageLoaderTarget1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetSize) (
        LXtObjectID		 self,
        LXtPixelFormat		 type,
        unsigned		 width,
        unsigned		 height);

        LXxMETHOD( LxResult,
SetMap) (
        LXtObjectID		 self,
        unsigned		 ncolor);
} ILxImageLoaderTarget1;

/*
 * The latest image loader target interface.
 * This has two additional methods.
 * * SetColorspaceDepth
 * * SetColorspace
 * These can be used to specify more accurately which colorspaces
 * to use for the given type.
 */
typedef struct vt_ILxImageLoaderTarget {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetSize) (
        LXtObjectID		 self,
        LXtPixelFormat		 type,
        unsigned		 width,
        unsigned		 height);

        LXxMETHOD( LxResult,
SetMap) (
        LXtObjectID		 self,
        unsigned		 ncolor);

        LXxMETHOD( LxResult,
SetColorspaceDepth) (
        LXtObjectID		 self,
        unsigned		 depth);

        LXxMETHOD( LxResult,
SetColorspace) (
        LXtObjectID		 self,
        const char		*colorspace);
} ILxImageLoaderTarget;

/*
 * Images can present an alternate interface that allows them to be accessed as
 * a set of levels. The levels are filtered versions of the image at different
 * scales, and typically are arranged in power-law series. The underlying
 * implementation may be tiled, enabling access to images that are larger than
 * the available memory, since the image server only needs sufficient memory
 * for a single tile. Levels can be used directly when rendering so that the
 * only levels used are those approximating the visual scale of the image in
 * the rendered scene.
 * The count returns the number of different levels in the image.
 * 
 * 
 * Each resolution level should be twice the size of the previous level, starting
 * at 1x1 pixels for level zero, although the tiled image load can pass back
 * slightly different dimensions for each resolution level, according to the
 * needs of the tiled format. The image may or may not provide the full image
 * as a level, although the full image must be accessible through the required
 * ILxImage interface.
 * 
 * Level images provide image data at a given resolution level, for an
 * array of image samples.
 * 
 * Pixels can be directly accessed from a given level, in either integer
 * or floating-point RGBA format, using an x- and y-coordinate in the local
 * coordinate system of the specified level.
 * 
 * Levels also support line-by-line access through a modified version of the
 * GetLine() method, which uses a y-coordinate in the local coordinate system
 * of the specified level. The data returned is always RGBA in floating point.
 */
typedef struct vt_ILxImageLevelSample {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Count) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
GetLevelSize) (
        LXtObjectID		 self,
        unsigned		 level,
        unsigned		*width,
        unsigned		*height);
        LXxMETHOD( LxResult,
SampleLevel) (
        LXtObjectID		 self,
        unsigned		 level,
        LXtImageSample		*pixel,
        unsigned		 num);
        LXxMETHOD( LxResult,
GetPixel) (
        LXtObjectID              self,
        unsigned		 level,
        unsigned int             x,
        unsigned int             y,
        LXtPixelFormat           type,
        void                    *pixel);
        LXxMETHOD( const LXtImageFloat *,
GetLine) (
        LXtObjectID		 self,
        unsigned		 level,
        unsigned		 y,
        LXtImageFloat		*buf);
} ILxImageLevelSample;

/*
 * Image facilities can be accessed through the SDK using a global service
 * interface.
 * This reads the entire image into a single buffer given the pixel format. This is
 * just like Image::GetLine() except that it does all the lines at once.
 * 
 * LaodNoCache() is the same as Load(), but the image is not added to the intenral cache.
 * This is useful when the image is only needed once (say, because it is being loaded
 * and resized).
 * 
 */
typedef struct vt_ILxImageService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Create) (
        LXtObjectID		 self,
        unsigned int		 width,
        unsigned int		 height,
        LXtPixelFormat		 type,
        unsigned int		 maxIndex,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Duplicate) (
        LXtObjectID		 self,
        LXtObjectID		 source,
        LXtPixelFormat		 type,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Load) (
        LXtObjectID		 self,
        const char		*filePath,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Save) (
        LXtObjectID		 self,
        LXtObjectID		 image,
        const char		*filePath,
        const char		*format,
        LXtObjectID		 monitor);

        LXxMETHOD(  LxResult,
Resample) (
        LXtObjectID		 self,
        LXtObjectID		 dest,
        LXtObjectID		 source,
        LXtProcessHint		 hint);

        LXxMETHOD(  LxResult,
Composite) (
        LXtObjectID		 self,
        LXtObjectID		 dest,
        LXtObjectID		 source,
        const LXtFVector2	 pos);

        LXxMETHOD(  LxResult,
DrawLine) (
        LXtObjectID		 self,
        LXtObjectID		 image,
        const LXtFVector2	 p0,
        const LXtFVector2	 p1,
        const LXtFVector	 color);

        LXxMETHOD(  LxResult,
Kelvin2RGB) (
        LXtObjectID		 self,
        float			 kelvin,
        LXtFVector		 rgbColor);

        LXxMETHOD(  LxResult,
RGB2Kelvin) (
        LXtObjectID		 self,
        const LXtFVector	 rgbColor,
        float			*kelvin);

        LXxMETHOD(  LxResult,
CreateCrop) (
        LXtObjectID		 self,
        LXtObjectID		 sourceImage,
        double			 x,
        double			 y,
        double			 w,
        double			 h,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ImageGetBuffer) (
        LXtObjectID		 self,
        LXtObjectID		 sourceImage,
        LXtPixelFormat		 type,
        void			*buf);
        LXxMETHOD(  LxResult,
LoadNoCache) (
        LXtObjectID		 self,
        const char		*filePath,
        void		       **ppvObj);
        LXxMETHOD (LxResult,
CreateLayered) (
        LXtObjectID		 self,
        unsigned int		 width,
        unsigned int		 height,
        unsigned int		 layerNum,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
SaveLayered) (
        LXtObjectID		 self,
        LXtObjectID		 layeredImage,
        const char		*filePath,
        const char		*format,
        LXtObjectID		 monitor);
} ILxImageService;

/*
 * Image block codec interfaces allow an image to be compressed into a block
 * of data which can then be included in other files, such as for thumbnails.
 * Compress() allocates and returns a block encoding the image. Free() frees
 * the block when the client is done. Decompress() creates an image from a
 * block.
 */
typedef struct vt_ILxImageBlockCodec {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Compress) (
        LXtObjectID		 self,
        LXtObjectID		 image,
        unsigned char	       **buf,
        int			*size);

        LXxMETHOD(  void,
Free) (
        LXtObjectID		 self,
        unsigned char		*buf,
        int			 size);

        LXxMETHOD(  LxResult,
Decompress) (
        LXtObjectID		 self,
        unsigned char		*buf,
        int			 size,
        void		       **ppvObj);
} ILxImageBlockCodec;

/*
 * Full image evaluation is using the ILxImageFilter interface.
 * There are two kinds of filters, Single Sample and Multi Sample.  Single Sample
 * is reminiscent of pixel filters, and are provided with a single pixel to
 * evaluate and set.  Multi Sample filters get an entire image buffer to evaluate
 * at once.  A Multi Sample filter can do everything a Single Sample filter can,
 * but you have to do more work by looping through the pixels in the image
 * yourself and creating a new image buffer, thus using more memory.
 * 
 * The Type() method returns the type of filter, given by one of the codes below.
 * These select which operational method is called and how its results are
 * interpreted.
 * 
 * 
 * Generate is called on the first filter to generate the base image.
 * 
 * Multi Sample filters can perform convolutes and other operations
 * that involve sampling multiple pixels.  They are responsible for
 * creating the output image itself, which can even be at a different
 * resolution, although I'm not sure how good of an idea this is.
 * Blurs, sharpen, trace edge and similar filters requiring multiple
 * samples of an image should be of this type.
 * 
 * Single Sample filters are provided with the RGBA values of a single
 * pixel to evaluate.  The filter function is called for each pixel in
 * turn.  This is a good choice for things like creating negatives,
 * performing gamma correction, tinting and other operations that don't
 * rely on multiple samples.
 * 
 * The multi-sample version of the single-sample filter allows an array of
 * RGBA tuples to be transformed at once. This is used when entire lines
 * need to be filtered but pixels are still independent. Filters that support
 * SingleSampleN() must also support SingleSample().
 */
typedef struct vt_ILxImageFilter {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned int,
Type) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Generate) (
        LXtObjectID		 self,
        int			 width,
        int			 height,
        LXtObjectID		 monitor,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
MultiSample) (
        LXtObjectID		 self,
        LXtObjectID		 monitor,
        LXtObjectID		 image,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
SingleSample) (
        LXtObjectID		 self,
        const LXtColorRGBA	 src,
        LXtColorRGBA		 dest);
        LXxMETHOD(  LxResult,
SingleSampleN) (
        LXtObjectID		 self,
        const LXtImageFloat	*src,
        LXtImageFloat		*dest,
        unsigned		 num);
} ILxImageFilter;

/*
 * This interface is designed for texturing.  It returns a sample in a texture
 * defined by a fraction of the width and height of the image, automatically
 * generating mip maps and blending between them.  'spotSize' is a fraction of the
 * image size.  The four element 'rgba' array will be filled with the sample.  If
 * for some reason the stack evaluation failed, this will return 0, and the 'rgba'
 * array will be set to all zeros.
 */
typedef struct vt_ILxImageFilterSample {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
SpotSample) (
        LXtObjectID		 self,
        float			 x,
        float			 y,
        float			 spotSize,
        float			*rgba);
} ILxImageFilterSample;

/*
 * - maxRes
 * This should be set to the maximum width and height that the image can be
 * generated at, or 0 for no limit.  For image loaders, this would be the size of
 * the image itself; for a Flash loader, this might be some maximum size entered
 * by the user.  Any attempt to generate an image greater than this will result in
 * an image being generated at maxRes.
 * - pixelType
 * This should be set to the pixel type for the images this stack will generate.
 * - aspect
 * This should be set to the aspect ratio of the image.  For example,
 * 4:3 aspect would be 1.3333.
 * 
 * Generate is called on the first filter to generate the base metrics.  Evaluate
 * is called for subsequent filters and may modify the metrics from the upstream
 * source.
 * 
 */
typedef struct vt_ILxImageFilterMetrics {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Generate) (
        LXtObjectID		 self,
        LXtImageMetrics		*metrics);

        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtImageMetrics		*metrics);
} ILxImageFilterMetrics;

typedef struct vt_ILxImageFilterMetrics1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Generate) (
        LXtObjectID		 self,
        LXtImageMetrics1	*metrics);
        
        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtImageMetrics1	*metrics);
} ILxImageFilterMetrics1;

/*
 * Movie creation API is pretty simple - you begin a movie, add a bunch of images
 * in sequence, and then end it.  The movie itself lives on disk at the path specified.
 * There are currently no flags defined, but there may be in the future.  Default
 * format is MP4 and default framerate is 15 fps.
 * Before adding any frames, you can change the framerate from the default of 15
 * with following method.
 * 
 * Adding an image is straightforward.  Do this in sequence.
 * 
 * When done adding images, call this to finalize the movie and write it to disk.
 * 
 * Adding an audio track. This must be called after adding all images before EndMove.
 */
typedef struct vt_ILxMovie {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
BeginMovie) (
        LXtObjectID		 self,
        const char	        *fname,
        int			 w,
        int			 h,
        int			 flags);
        LXxMETHOD(  LxResult,
SetFramerate) (
        LXtObjectID		 self,
        int			 frate);
        LXxMETHOD(  LxResult,
AddImage) (
        LXtObjectID		 self,
        LXtObjectID		 image);
        LXxMETHOD(  LxResult,
EndMovie) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
AddAudio) (
        LXtObjectID		 self,
        LXtObjectID		 audio);
} ILxMovie;

/*
 * Images are defined by their pixel format which consists of a datatype and
 * vector size.  There are two data types.  The BYTE type is an 8 bit integer in
 * the range is 0 to 255.  The FLOAT type is a 32-bit floating point number in the
 * nominal range of 0.0 to 1.0.  Operations on integer pixel values are  clamped
 * so the results are always in the valid range.  Floating point colors are not
 * clamped, so the images can represent superbright and superdark pixels.
 */

        #define LXiIMD_BYTE	0x00
        #define LXiIMD_FLOAT	0x08
        #define LXfIMD_MASK	0x08

        #define LXxIMD_TYPE(t)	(t & LXfIMD_MASK)

/*
 * The vector sizes are GREY which is one monochrome component; RGB which is a
 * vector of three color components; or RGBA which is a vector of three color
 * components and alpha.  The alpha channel is represented by 0 for transparent,
 * 255 for opaque if in byte format, and 1.0 for opaque if floating point format.
 */

        #define LXiIMV_GREY	0x01
        #define LXiIMV_RGB	0x03
        #define LXiIMV_RGBA	0x04
        #define LXfIMV_MASK	0x07

        #define LXxIMV_TYPE(v)	(v & LXfIMV_MASK)

/*
 * Index images use the index flag.
 */

        #define LXiIMT_INDEX	0x100
        #define LXiIMT_MASK	0x100

/*
 * Image pixel types are just the mask values combined together.  Here are all six
 * of the possible combinations in more convenient form.  The color bits of
 * an index mask can be acquired separately as well.
 */

        #define LXiIMP_GREY8	(LXiIMD_BYTE  | LXiIMV_GREY)
        #define LXiIMP_GREYFP	(LXiIMD_FLOAT | LXiIMV_GREY)
        #define LXiIMP_RGB24	(LXiIMD_BYTE  | LXiIMV_RGB)
        #define LXiIMP_RGBFP	(LXiIMD_FLOAT | LXiIMV_RGB)
        #define LXiIMP_RGBA32	(LXiIMD_BYTE  | LXiIMV_RGBA)
        #define LXiIMP_RGBAFP	(LXiIMD_FLOAT | LXiIMV_RGBA)

        #define LXiIMP_IGREY8	(LXiIMD_BYTE  | LXiIMV_GREY | LXiIMT_INDEX)
        #define LXiIMP_IRGB24	(LXiIMD_BYTE  | LXiIMV_RGB  | LXiIMT_INDEX)
        #define LXiIMP_IRGBA32	(LXiIMD_BYTE  | LXiIMV_RGBA | LXiIMT_INDEX)

        // macro to check for greyscale pixel types explicitly, as LXiIMV_RGB masks LXiIMV_GREY
        #define LXi_IMP_ISGREY(x) ((x == LXiIMP_GREY8) || (x == LXiIMP_GREYFP) || (x == LXiIMP_IGREY8))


        #define LXiPROCESS_FAST		0
        #define LXiPROCESS_MEDIUM	1
        #define LXiPROCESS_ACCURATE	2

/*
 * Color components in stored in vector type pixels are always in RGBA order. Use these
 * indices to access components in a more abstract way.
 */

        #define LXiIMC_RED	0
        #define LXiIMC_GREEN	1
        #define LXiIMC_BLUE	2
        #define LXiIMC_ALPHA	3

/*
 * Some name and types are defined for common attributes that are read or set by
 * the application.
 * - DPI
 * Dots per Inch, which is the number of pixels in the image that will fit
 * vertically in each inch of the printed image.  To know the horizontal DPI
 * you have to take pixel aspect into account.
 * - PIXASPECT
 * This is the aspect ratio of a single pixel in the image, computed as
 * width/height.  If the pixel height is one, then the pixel width is the same
 * as the pixel aspect.
 * 
 * - REGX0, REGX1, REGY0, REGY1
 * Pixel coordinates of the borders of the rendered region of the image.  X and
 * Y start at zero at the left and top of the image.
 * 
 * - GAMMA
 * Gamma is an exponent applied to unity-normalized color values in the image
 * before saving.  To get the "real" values for pixels in the image, the
 * inverse gamma needs to be applied.
 * 
 * - COMMENT
 * Everyone's got something to say, right?
 * 
 */

        #define LXsIATTRNAME_CAM_TRANS  		"cameraTransform"
        #define LXsIATTRTYPE_CAM_TRANS		LXsTYPE_STRING

        #define LXsIATTRNAME_WORLD_TO_CAM  		"worldToCamera"
        #define LXsIATTRTYPE_WORLD_TO_CAM		LXsTYPE_STRING

        #define LXsIATTRNAME_ISO	    		"ISO"
        #define LXsIATTRTYPE_ISO			LXsTYPE_FLOAT

        #define LXsIATTRNAME_EXPTIME			"exposureTime"
        #define LXsIATTRTYPE_EXPTIME			LXsTYPE_FLOAT

        #define LXsIATTRNAME_DPI		    "DPI"
        #define LXsIATTRTYPE_DPI		    LXsTYPE_FLOAT

        #define LXsIATTRNAME_APERATUREX	    "aperatureX"
        #define LXsIATTRTYPE_APERATUREX	    LXsTYPE_FLOAT

        #define LXsIATTRNAME_APERATUREY	    "aperatureY"
        #define LXsIATTRTYPE_APERATUREY	    LXsTYPE_FLOAT

        #define LXsIATTRNAME_CLIP_DIST	    "clipDist"
        #define LXsIATTRTYPE_CLIP_DIST	    LXsTYPE_FLOAT

        #define LXsIATTRNAME_FOC_LENGTH	    "focalLength"
        #define LXsIATTRTYPE_FOC_LENGTH	    LXsTYPE_FLOAT

        #define LXsIATTRNAME_PIXASPECT		"pixelAspect"
        #define LXsIATTRTYPE_PIXASPECT		LXsTYPE_FLOAT

        #define LXsIATTRNAME_REGX0		    "regionX0"
        #define LXsIATTRTYPE_REGX0		    LXsTYPE_INTEGER

        #define LXsIATTRNAME_REGX1		    "regionX1"
        #define LXsIATTRTYPE_REGX1		    LXsTYPE_INTEGER

        #define LXsIATTRNAME_REGY0		    "regionY0"
        #define LXsIATTRTYPE_REGY0		    LXsTYPE_INTEGER

        #define LXsIATTRNAME_REGY1		    "regionY1"
        #define LXsIATTRTYPE_REGY1		    LXsTYPE_INTEGER

        #define LXsIATTRNAME_GAMMA		    "gamma"
        #define LXsIATTRTYPE_GAMMA		    LXsTYPE_FLOAT

        #define LXsIATTRNAME_COMMENT		    "comment"
        #define LXsIATTRTYPE_COMMENT		    LXsTYPE_STRING

        #define LXsIATTRNAME_APPLY_DISPLAY_LUT	    "applyDisplayLUT"
        #define LXsIATTRTYPE_APPLY_DISPLAY_LUT	    LXsTYPE_INTEGER

        #define LXsSAV_OUTPUT_PIXEL_FORMAT	    "outputPixelFormat"
        #define LXsSAV_OUTPUT_KNOWN_COLOR_SPACE     "knownColorSpace"

        #define LXsIATTRNAME_OUTPUT_COLOR_SPACE     "outputColorSpace"
        #define LXsIATTRTYPE_OUTPUT_COLOR_SPACE	    LXsTYPE_STRING

        #define LXsIATTRNAME_COLOR_MAPPING_SERVER_NAME    "colorMappingServerName"
        #define LXsIATTRTYPE_COLOR_MAPPING_SERVER_NAME    LXsTYPE_STRING

        #define LXsIATTRNAME_OUTPUT_COLOR_SPACE_EMBEDDING     "outputColorspaceEmbedding"
        #define LXsIATTRTYPE_OUTPUT_COLOR_SPACE_EMBEDDING     LXsTYPE_INTEGER

        // Certain image formats have a particular color space which
        // can't be inferred from their pixel format (e.g. .hdr is 8-bit but linear)
        // Image IO Plugins can set the 'colorspace' field of the LXtImageTarget1
        // structure to LXsKNOWN_COLORSPACE_LINEAR in order to specify
        // that the colorspace of this image is linear.

        #define LXsKNOWN_COLORSPACE_LINEAR	    "linear"

        #define LXsDEFAULT_COLORSPACE_8BIT	    "8bit"
        #define LXsDEFAULT_COLORSPACE_16BIT	    "16bit"
        #define LXsDEFAULT_COLORSPACE_FLOAT	    "float"
        #define LXsDEFAULT_COLORSPACE_GREY	    "grey"

        // Image IO Plugins can set the 'depth' field of the LXtImageTarget1
        // structure to any of the below values.
        // Modo will choose a default colorspace for the image based on this setting.
        // If 'None' is specified, no default colorspace conversion will occur.
        //
        // But users can override this choice on a per-clip basis, by setting the
        // clip's colorspace channel.
        //
        #define LXiDEFAULT_COLORSPACE_NONE	0
        #define LXiDEFAULT_COLORSPACE_8BIT	1
        #define LXiDEFAULT_COLORSPACE_16BIT	2
        #define LXiDEFAULT_COLORSPACE_FLOAT	3
        #define LXiDEFAULT_COLORSPACE_GREY	4

/*
 * The OpenEXR file specification suggests some common metadata
 * appropriate for HDR or physically accurate images.
 * - LUMA
 * The luminance of a white pixel with r=g=b=1.0.  The units, candela/m^2,
 * match the 'whiteLuminance' OpenEXR standard attribute.
 * - FOCDIST
 * The focus distance for the camera.
 * - APERTURE
 * the aperture is given in f-stops, (focal length of the lens divided
 * by the diameter of the iris opening).
 * 
 */

        #define LXsIATTRNAME_LUMA	"luminance"
        #define LXsIATTRTYPE_LUMA	 LXsTYPE_FLOAT

        #define LXsIATTRNAME_FOCDIST	"focusDist"
        #define LXsIATTRTYPE_FOCDIST	 LXsTYPE_FLOAT

        #define LXsIATTRNAME_APERTURE	"aperture"
        #define LXsIATTRTYPE_APERTURE	 LXsTYPE_FLOAT

/*
 * This is the primary interface for image objects, and so this the GUID
 * specified when attempting to load or save images.
 */

        #define LXu_IMAGE	"469AFBB8-E6A2-4d88-9C39-5430CA72E404"
        #define LXa_IMAGE	"image"
        #define LXa_IMAGE_FLOAT	"image_float"
        #define LXsSAV_IMAGE_FLOAT "saver.imageFloat"
        //[local]  ILxImage
        //[export] ILxImage img
        //[const]  ILxImage:Size
        //[const]  ILxImage:Format
        //[const]  ILxImage:GetPixel
        //[const]  ILxImage:GetLine
        //[python] ILxImage:GetPixel:pixel	vector
        //[python] ILxImage:GetLine:buf		vector


        #define LXu_IMAGESEGMENT	"370ABB2F-119E-4EEC-98F8-03388ABE7D2C"
        #define LXa_IMAGESEGMENT	"imagesegment"
        //[local]  ILxImageSegment
        //[export] ILxImageSegment imgs
        //[const]  ILxImageSegment:GetSegment
        //[python] ILxImageSegment:GetSegment:rgba	vector
        //[python] ILxImageSegment:SetSegment:line	vector


        #define LXu_IMAGEWRITE	"8F9CF293-B6F9-498e-A124-6704E2C24662"
        #define LXa_IMAGEWRITE	"imagewrite"
        //[local]  ILxImageWrite
        //[export] ILxImageWrite imgw
        //[const]  ILxImageWrite:Size
        //[const]  ILxImageWrite:Format
        //[python] ILxImageWrite:SetPixel:pixel	vector
        //[python] ILxImageWrite:SetLine:line	vector


        #define LXu_INDEXIMAGE		"08CAE3BC-ED69-4EC4-9D7D-BBDBE4E35343"
        //[local]  ILxIndexImage
        //[const]  ILxIndexImage:Size
        //[const]  ILxIndexImage:Format
        //[const]  ILxIndexImage:MapSize
        //[const]  ILxIndexImage:GetIndex
        //[const]  ILxIndexImage:GetMap
        //[python] ILxIndexImage:GetMap:pixel	vector


        #define LXu_INDEXIMAGEWRITE	"D59C5E09-779E-445b-B317-282630CB6BD5"
        //[local]  ILxIndexImageWrite
        //[const]  ILxIndexImageWrite:Size
        //[const]  ILxIndexImageWrite:Format
        //[python] ILxIndexImageWrite:SetMap:pixel	vector


        #define LXu_LAYEREDIMAGE	"8523ECC4-B8B3-4C6E-8F14-A1D2D01E8038"
        #define LXa_LAYEREDIMAGE	"layeredimage"
        // [local]  ILxLayeredImage
        // [export] ILxLayeredImage limg
        // [const]  ILxLayeredImage:Size
        // [const]  ILxLayeredImage:Count
        // [const]  ILxLayeredImage:Name
        // [const]  ILxLayeredImage:Type
        // [const]  ILxLayeredImage:Offset
        // [const]  ILxLayeredImage:Blend
        // [const]  ILxLayeredImage:ChannelName
        // [const]  ILxLayeredImage:Parent
        // [const]  ILxLayeredImage:IsGroup
        // [python] ILxLayeredImage:Image	obj Image


        #define LXu_LAYEREDIMAGEWRITE	"79D28886-9652-4A76-9AA7-1B1E4D553DCD"
        //[local]  ILxLayeredImageWrite
        //[export] ILxLayeredImageWrite limgw


        #define LXu_TILEIMAGE	"BD12D6C3-C08F-4AD1-A080-399F958D28C0"
        #define LXa_TILEIMAGE	"tileImage"
        //[local]  ILxTileImage
        //[export] ILxTileImage tileimg
        //[const]  ILxTileImage:LevelCount
        //[const]  ILxTileImage:GetTile
        //[const]  ILxTileImage:GetTileSize
        //[const]  ILxTileImage:GetLevelSize
        //[const]  ILxTileImage:DetermineTile
        //[const]  ILxTileImage:DeterminePixel
        //[python] ILxTileImage:GetTile		obj Image


        #define LXu_IMAGELOADERTARGET1	"9F124A7B-DFC7-42E6-977B-71AE2E33B017"
        // [local]  ILxImageLoaderTarget1


        #define LXu_IMAGELOADERTARGET	"1034861C-78C4-4BEC-9588-F1D3C0B0401A"
        // [local]  ILxImageLoaderTarget


        #define LXu_IMAGELEVELSAMPLE	"79A6EA0E-9589-4D03-880C-C06A6EC6CF7D"
        #define LXa_IMAGELEVELSAMPLE	"imageLevelSample"
        // [export] ILxImageLevelSample level
        // [local]  ILxImageLevelSample
        // [const]  ILxImageLevelSample:Count
        // [const]  ILxImageLevelSample:GetLevelSize
        // [const]  ILxImageLevelSample:SampleLevel
        // [const]  ILxImageLevelSample:GetPixel
        // [const]  ILxImageLevelSample:GetLine
        // [python] ILxImageLevelSample:GetPixel:pixel	vector
        // [python] ILxImageLevelSample:GetLine:buf	vector

/*
 * These are the blending modes:
 */

        #define	LXi_IBM_NORMAL		0
        #define LXi_IBM_ERASE		1
        #define	LXi_IBM_ADD		2
        #define	LXi_IBM_SUB		3
        #define	LXi_IBM_DIFF		4
        #define	LXi_IBM_MULTIPLY	5
        #define	LXi_IBM_SCREEN		6
        #define	LXi_IBM_OVERLAY		7
        #define	LXi_IBM_SOFTLIGHT	8
        #define	LXi_IBM_HARDLIGHT	9
        #define	LXi_IBM_DARKEN		10
        #define	LXi_IBM_LIGHTEN		11
        #define	LXi_IBM_COLORDODGE	12
        #define	LXi_IBM_COLORBURN	13
        #define	LXi_IBM_SCREEN2		14
        #define	LXi_IBM_REPLACE		15
        #define	LXi_IBM_ADDNORM		16


        #define LXu_IMAGESERVICE	"03A7D258-397C-4D92-B3AF-695AD676FCF9"

        // [python] ILxImageService:Create		obj Image
        // [python] ILxImageService:CreateCrop		obj Image
        // [python] ILxImageService:Duplicate		obj Image
        // [python] ILxImageService:Load		obj Image
        // [python] ILxImageService:LoadNoCache		obj Image
        // [python] ILxImageService:ImageGetBuffer:buf	vector


        #define LXu_IMAGEBLOCKCODEC	"7960B5BA-70D3-4FAD-8CA1-BD30A7938554"
        #define LXa_IMAGEBLOCKCODEC	"imageBlockCodec"
        // [export] ILxImageBlockCodec ibc


        #define LXi_IMAGE_GENERATOR		0
        #define LXi_IMAGE_SINGLE_SAMPLE		1
        #define LXi_IMAGE_MULTI_SAMPLE		2
        #define LXi_IMAGE_SINGLE_SAMPLE_N	3


        #define LXu_IMAGEFILTER		"FB00C87C-5A34-4B45-B0E8-998926C79DC4"
        // [export]  ILxImageFilter imf
        // [local]   ILxImageFilter
        // [python]  ILxImageFilter:Generate	obj Image
        // [python]  ILxImageFilter:MultiSample	obj Image


        #define LXu_IMAGEFILTERSAMPLE	"9EC74AED-F86F-4105-ACE9-7BDAA6298736"


        #define LXu_IMAGEFILTERMETRICS	"8F7A47EB-5812-47F4-91F5-2195B053F97D"
        // [export]  ILxImageFilterMetrics imfmet
        // [local]   ILxImageFilterMetrics


        #define LXu_IMAGEFILTERMETRICS1	"0D2CA8D8-66A9-45A0-AAE6-8364D903AFDA"

/*
 * Since there's really no better place for this we'll put the simple animation
 * interface here.  This is a very simple API for creating animations.
 * The LXsMOVIE_OPTIONSCOMMAND tag identifies a command that should be executed
 * to set options for the movie saver.  It is commonly called when the user has
 * chosen the movie saver from a file dialog, and in any other situation where
 * the user needs to be presented with saver options before actually saving the
 * movie.
 */

        #define LXu_MOVIE		"B7BD9F49-9400-45F1-ADEE-BFE82A1C4A65"
        #define LXa_MOVIE		"movie"
        // [export]  ILxMovie

        #define LXsMOVIE_SAVESTEREO	"movie.stereoscopic"
        #define LXsMOVIE_OPTIONSCOMMAND	"optionsCommand"

#endif
