/*
 * LX render module
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
#ifndef LX_render_H
#define LX_render_H

typedef struct vt_ILxRenderBucket ** ILxRenderBucketID;

#include <lxvector.h>
#include <lxcolormapping.h>

/*
 * Image processing operators control how the rendered image is processed, and
 * are non-destructive.
 */

        // LS - "ALL" now includes display color mapping, so it must be flagged off if not required.
        #define LXiIP_ALL_OPERATORS_ENABLED	0xFFFFFFFF
        #define LXiIP_ALL_OPERATORS_DISABLED	0x00000000
        #define LXiIP_NO_OPERATOR_OVERRIDE	0x80000000

        #define LXiIP_STEREO			0x00000001
        #define LXiIP_COMPONENT_STEREO		0x00000002

        #define LXiIP_SOURCE_IMAGE_GAMMA	0x00000004

        #define LXiIP_BLOOM			0x00000008

        #define LXiIP_VIGNETTE			0x00000010

        #define LXiIP_INPUT_BLACK_LEVEL		0x00000080
        #define LXiIP_INPUT_GRAY_LEVEL		0x00000100
        #define LXiIP_INPUT_WHITE_LEVEL		0x00000200

        #define LXiIP_INPUT_MIN_RGB_LEVEL	0x00000400
        #define LXiIP_INPUT_RGB_GRAY_LEVEL	0x00000800
        #define LXiIP_INPUT_MAX_RGB_LEVEL	0x00001000

        #define LXiIP_TONE_MAPPING		0x00002000
        #define LXiIP_HUE_OFFSET		0x00004000
        #define LXiIP_SATURATION		0x00008000
        #define LXiIP_COLORIZATION		0x00010000
        #define LXiIP_OUTPUT_BLACK_LEVEL	0x00020000
        #define LXiIP_OUTPUT_WHITE_LEVEL	0x00040000

        #define LXiIP_OUTPUT_MIN_RGB_LEVEL	0x00080000
        #define LXiIP_OUTPUT_MAX_RGB_LEVEL	0x00100000

        #define LXiIP_OUTPUT_GAMMA		0x00200000

        #define LXiIP_DITHER			0x00400000

        #define LXiIP_USE_DISPLAY_GAMMA_PREF	0x00800000		// If both this and OUTPUT_GAMMA are set, OUTPUT_GAMMA is used

        #define LXiIP_APPLY_DISPLAY_COLORSPACE	0x01000000

        typedef unsigned int			LXtImageProcessingOperators;

        #define LXiSE_LEFT			0
        #define LXiSE_RIGHT			1
        #define LXiSE_BOTH			2

        typedef unsigned int			LXtStereoEye;

        #define LXeSC_NO_COMPOSITE		0

        #define LXeSC_ANAGLYPH_RED_CYAN		1
        #define LXeSC_ANAGLYPH_GRAYSCALE	2
        #define LXeSC_ANAGLYPH_RED_CYAN_HALF	3
        #define LXeSC_ANAGLYPH_RED_CYAN_OPT	4
        #define LXeSC_ANAGLYPH_RED_BLUE_LS	5
        #define LXeSC_LAST_ANAGLYPH_MODE	LXeSC_ANAGLYPH_RED_BLUE_LS

        #define LXeSC_SIDE_BY_SIDE		6
        #define LXeSC_SIDE_BY_SIDE_FULL_WIDTH	7
        #define LXeSC_SIDE_BY_SIDE_CROSSED	8
        #define LXeSC_SIDE_BY_SIDE_CROSSED_FULL	9
        #define LXeSC_LAST_SIDE_BY_SIDE_MODE	LXeSC_SIDE_BY_SIDE_CROSSED_FULL

        #define LXeSC_DROPDOWN_COUNT		(LXeSC_LAST_SIDE_BY_SIDE_MODE + 1)

        #define LXeSC_UNDEFINED			0xFFFF

        typedef unsigned int			LXtStereoComposite;

        typedef struct st_LXtRenderOutputProcess
        {
                LXtImageProcessingOperators	ops;

                int				type;
                int				typeSize;

                int				unpremul;
                int				alphaIndex;
                int				isFactoryName;

                float				sourceImageGamma;
                int				sourceImageIsStereoSideBySide;

                int				saveProcessed;

                int				stereoEye;
                int				stereoComposite;

                int				bloom;
                float				bloomThr;
                float				bloomRad;

                float				invResX, invResY, vignAmt;

                float				inputBlackLevel;
                float				inputGrayLevel;
                float				invInputGrayLevel;
                float				white;
                float				exposure;

                float				inputMinRedLevel;
                float				inputRedGrayLevel;
                float				invInputRedGrayLevel;
                float				red;
                float				redExposure;

                float				inputMinGreenLevel;
                float				inputGreenGrayLevel;
                float				invInputGreenGrayLevel;
                float				green;
                float				greenExposure;

                float				inputMinBlueLevel;
                float				inputBlueGrayLevel;
                float				invInputBlueGrayLevel;
                float				blue;
                float				blueExposure;

                int				expType;
                float				iso;
                float				expTime;
                float				fStop;

                int				toneMap;
                float				toneAmt;

                float				hueOffset;
                float				saturation;
                float				colorization;
                LXtVector			targetColor;
                LXtVector			targetHSV;

                float				outputBlackLevel;
                float				outputWhiteLevel;

                float				outputMinRedLevel;
                float				outputMaxRedLevel;

                float				outputMinGreenLevel;
                float				outputMaxGreenLevel;

                float				outputMinBlueLevel;
                float				outputMaxBlueLevel;

                float				gamma;
                float				invGamma;

                const char*			colorspace;
                ILxColorMappingID	colormapping;
                int					colorspaceEmbedding;

                char				userName[64];
                char				identity[256];
                int				itemUniqueIndex;
        } LXtRenderOutputProcess;

        typedef struct st_LXtRenderOutputProcessList
        {
                unsigned		 count;
                LXtRenderOutputProcess	*outputs;
        } LXtRenderOutputProcessList;

/*
 * Render outputs currently have specific type codes for efficiency (avoiding the
 * need for string comparisons).
 */

        #define LXiRENDEROUTPUT_INVALID		-1

        #define LXiRENDEROUTPUT_COLOR		 0
        #define LXiRENDEROUTPUT_ALPHA		 1

        #define LXiRENDEROUTPUT_DIFF		 2
        #define LXiRENDEROUTPUT_DIFFDIR		 3
        #define LXiRENDEROUTPUT_DIFFIND		 4
        #define LXiRENDEROUTPUT_DIFFUNS		 5
        #define LXiRENDEROUTPUT_SPEC		 6
        #define LXiRENDEROUTPUT_REFL		 7
        #define LXiRENDEROUTPUT_TRAN		 8
        #define LXiRENDEROUTPUT_SUBS		 9
        #define LXiRENDEROUTPUT_LUMI		 10

        #define LXiRENDEROUTPUT_DEPTH		 11
        #define LXiRENDEROUTPUT_MOTION		 12
        #define LXiRENDEROUTPUT_SHADOW		 13
        #define LXiRENDEROUTPUT_OCCLAMB		 14
        #define LXiRENDEROUTPUT_OCCLREF		 15

        #define LXiRENDEROUTPUT_SNORM		 16
        #define LXiRENDEROUTPUT_SINC		 17
        #define LXiRENDEROUTPUT_GNORM		 18
        #define LXiRENDEROUTPUT_GINC		 19

        #define LXiRENDEROUTPUT_SURFACE		 20
        #define LXiRENDEROUTPUT_SEGMENT		 21

        #define LXiRENDEROUTPUT_OPOS		 22 
        #define LXiRENDEROUTPUT_WPOS		 23
 
        #define LXiRENDEROUTPUT_UV		 24 
        #define LXiRENDEROUTPUT_DPDU		 25
        #define LXiRENDEROUTPUT_DPDV		 26

        #define LXiRENDEROUTPUT_ICPOS		 27
        #define LXiRENDEROUTPUT_ICVAL		 28

        #define LXiRENDEROUTPUT_MDIFFCOL	 29
        #define LXiRENDEROUTPUT_MDIFFAMT	 30
        #define LXiRENDEROUTPUT_MDIFFROUGH	 31
        #define LXiRENDEROUTPUT_MDIFFENG	 32
        #define LXiRENDEROUTPUT_ROUGHNESS	 33
        #define LXiRENDEROUTPUT_MDIFF		 34
        #define LXiRENDEROUTPUT_MSPEC		 35
        #define LXiRENDEROUTPUT_MREFL		 36

        #define LXiRENDEROUTPUT_ILLUM		 37
        #define LXiRENDEROUTPUT_ILLUMDIR	 38
        #define LXiRENDEROUTPUT_ILLUMIND	 39
        #define LXiRENDEROUTPUT_ILLUMUNS	 40

        #define LXiRENDEROUTPUT_SAMPLES		 41
        #define LXiRENDEROUTPUT_VARIANCE	 42
        
        #define LXiRENDEROUTPUT_VOL_LUM		 43
        #define LXiRENDEROUTPUT_VOL_OPA		 44
        #define LXiRENDEROUTPUT_VOL_DEPTH	 45

        #define LXiRENDEROUTPUT_SUBS_AMOUNT	 46
        #define LXiRENDEROUTPUT_SUBS_COLOR	 47

        #define LXiRENDEROUTPUT_TRAN_AMOUNT	 48
        #define LXiRENDEROUTPUT_TRAN_COLOR	 49

        #define LXiRENDEROUTPUT_PARTICLE_ID	 50
        #define LXiRENDEROUTPUT_PARTICLE_AGE	 51
        #define LXiRENDEROUTPUT_PARTICLE_VEL	 52

        #define LXiRENDEROUTPUT_DRIVER_A	 53
        #define LXiRENDEROUTPUT_DRIVER_B	 54
        #define LXiRENDEROUTPUT_DRIVER_C	 55
        #define LXiRENDEROUTPUT_DRIVER_D	 56

        #define LXiRENDEROUTPUT_RECOLOR_TO	 57
        #define LXiRENDEROUTPUT_RECOLOR_WHITE	 58
        #define LXiRENDEROUTPUT_MATERIAL_MAP	 59

        #define LXiRENDEROUTPUT_LPE		 60

        #define LXiRENDEROUTPUT_ALBEDO		 61

        #define LXiRENDEROUTPUT_CRYPTOMATTE		 62
        #define LXiRENDEROUTPUT_CRYPTOMATTE_ID		 63
        #define LXiRENDEROUTPUT_CRYPTOMATTE_COVERAGE	 64



/*
 * The bucket is exposed to clients via the render bucket interface, which is
 * actually a packet in the sample vector.
 * The simplest thing the RenderBucket interface can be used for is to get the
 * thread number of the current rendering thread. This will be a value from 0
 * through n-1, where n is the number of rendering threads.
 * 
 * 
 * We can also get the sample vector back from the bucket object.
 * 
 * We can push and pop rays onto the ray stack. These functions are equivalent to those
 * in the Raycast interface.
 * 
 * 
 * GetGIBounce will directly return the number of global illumination bounces prior to the current
 * shading evaluation. This will allow a shader to compare it against the maximum global illumination
 * bounces, and exit if it's already reached the maximum.
 * 
 * GetPixel will indirectly (through the x and y argument pointers) return the current pixel being
 * evaluated by this thread.
 * 
 * GetSubPixel will get the position of the current sample being evaluated within the pixel. It
 * indirectly returns the values via the pointers to x and y. The values returned are between 0.0
 * and 1.0.
 * 
 * GetTimeOffset will return a value between 0.0 and 1.0 indicating the time within an exposure
 * being currently evaluated (to allow motion / temporal blur in shading, for instance).
 */
typedef struct vt_ILxRenderBucket {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned int,
Thread) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
SampleVec) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
PushRay) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
PopRay) (
        LXtObjectID		 self);
        LXxMETHOD (  int,
GetGIBounce) (
        LXtObjectID		 self);
        LXxMETHOD (  void,
GetPixel) (
        LXtObjectID		 self,
        int			*x,
        int			*y);
        LXxMETHOD (  void,
GetSubPixel) (
        LXtObjectID		 self,
        float			*x,
        float			*y);
        LXxMETHOD (  float,
GetTimeOffset) (
        LXtObjectID		 self);
} ILxRenderBucket;

/*
 * Geometry caches include memory blocks for fast allocation of geometry elements
 * with fewer system memory calls.  This scheme also increases the chances that
 * elements used together will be in the same area of memory and generally results
 * in faster rendering.
 */

        #define LXe_GEO_SIZE_LIMIT	 LXxFAILCODE(LXeSYS_REND,1)


        #define LXu_RENDERBUCKET	"ED6F0ABE-F76F-4EED-BEF5-A30FF7F71098"
        #define LXa_RENDERBUCKET	"renderBucket"
        #define LXsP_RENDERBUCKET	"renderBucket"
        // [local]  ILxRenderBucket

#endif
