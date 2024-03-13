/*
 * LX colormapping module
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
#ifndef LX_colormapping_H
#define LX_colormapping_H

typedef struct vt_ILxColorMappingModule ** ILxColorMappingModuleID;
typedef struct vt_ILxColorMapping ** ILxColorMappingID;
typedef struct vt_ILxColorMapping1 ** ILxColorMapping1ID;
typedef struct vt_ILxColorMappingService ** ILxColorMappingServiceID;

#include <lxcom.h>
#include <lxvmath.h>
#include <lximage.h>
 #include <stdio.h>



typedef struct vt_ILxColorMappingModule {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID			self);
} ILxColorMappingModule;

/*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
typedef struct vt_ILxColorMapping {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Setup) (
        LXtObjectID			self,
        int				toLinear);
        LXxMETHOD( LxResult,
ToLinear) (
        LXtObjectID			self,
        const LXtFVector	sourceValues,
        LXtFVector			linearValues,
        unsigned int		length);
        LXxMETHOD( LxResult,
FromLinear) (
        LXtObjectID			self,
        const LXtFVector	linearValues,
        LXtFVector			targetValues,
        unsigned int		length);
        LXxMETHOD( LxResult,
ToLinearFast) (
        LXtObjectID			self,
        float*				buf,
        unsigned int		length);
        LXxMETHOD( LxResult,
FromLinearFast) (
        LXtObjectID			self,
        float*				buf,
        unsigned int		length);
        LXxMETHOD( LxResult,
GetLUTImage) (
        LXtObjectID			self,
        float			   **ptr);
        LXxMETHOD( LxResult,
GetShaderSource) (
        LXtObjectID			self,
        char			   **ptr);
        LXxMETHOD( const char*,
GetName) (
        LXtObjectID			self);
        LXxMETHOD( const char*,
GetCMServerName) (
        LXtObjectID			self);
        LXxMETHOD( unsigned char*,
GenerateICCProfile) (
        LXtObjectID			self,
        unsigned int*		length);
} ILxColorMapping;

typedef struct vt_ILxColorMapping1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Setup) (
        LXtObjectID			self,
        int				toLinear);

        LXxMETHOD( LxResult,
ToLinear) (
        LXtObjectID			self,
        const LXtFVector	sourceValues,
        LXtFVector			linearValues,
        unsigned int		length);

        LXxMETHOD( LxResult,
FromLinear) (
        LXtObjectID			self,
        const LXtFVector	linearValues,
        LXtFVector			targetValues,
        unsigned int		length);

        LXxMETHOD( LxResult,
ToLinearFast) (
        LXtObjectID			self,
        float*				buf,
        unsigned int		length);

        LXxMETHOD( LxResult,
FromLinearFast) (
        LXtObjectID			self,
        float*				buf,
        unsigned int		length);

        LXxMETHOD( LxResult,
GetLUTImage) (
        LXtObjectID			self,
        float			   **ptr);

        LXxMETHOD( LxResult,
GetShaderSource) (
        LXtObjectID			self,
        char			   **ptr);

        LXxMETHOD( const char*,
GetName) (
        LXtObjectID			self);
} ILxColorMapping1;

/*
 * 
 * 
 * 
 * 
 * Get the color mapping used for displaying colors in the interface.
 * 
 * Get the color mapping used for numeric values in the interface.
 */
typedef struct vt_ILxColorMappingService {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
MakeColorMapping) (
        LXtObjectID		 self,
        const char		*colorspaceName,
        int			 toLinear,
        void		       **ppvObj);
        LXxMETHOD( int,
ConfigCount) (
        LXtObjectID			self);
        LXxMETHOD( LxResult,
ConfigName) (
        LXtObjectID			self,
        int					index,
        const char			**configName);
        LXxMETHOD( LxResult,
ConfigFullPath) (
        LXtObjectID			self,
        int					index,
        const char			**configPath);
        LXxMETHOD( LxResult,
RegisterColorspaceForConfig) (
        LXtObjectID			self,
        const char			*configName,
        const char			*colorspaceName);
        LXxMETHOD( LxResult,
GetDisplayColorMapping) (
        LXtObjectID			self,
        void				**ppvObj);
        LXxMETHOD( LxResult,
GetNumericColorMapping) (
        LXtObjectID			self,
        void				**ppvObj);
} ILxColorMappingService;


        #define LXu_COLORMAPPINGMODULE		"99D65C3D-D394-40E2-A71A-B174E971F462"
        #define LXa_COLORMAPPINGMODULE		"colormappingmodule"
        // [export] ILxColorMappingModule cmapmod
        // [local] ILxColorMappingModule

/*
 * ColorMapping, specifies an object used for color conversion between linear and a particular
 * colorspace.
 */

        #define LXu_COLORMAPPING	"49B0319A-BBAA-4D43-8447-631BE7297FBB"
        #define LXa_COLORMAPPING	"colormapping2"
        // [export] ILxColorMapping cmap
        // [local] ILxColorMapping

        #define	CMS_GPU_LUT3D_EDGE_SIZE 32

/*
 * --------------------------------------------------------------------------------------------
 * Old ColorMapping interface
 */

        #define LXu_COLORMAPPING1	"40D65C4F-D394-40E2-A71A-B174E971F462"
        #define LXa_COLORMAPPING1	"colormapping"
        // [export] ILxColorMapping1 cmap
        // [local] ILxColorMapping1

/*
 * The color mapping service allows color mapping items to be enumerated and created.
 */

        #define LXu_COLORMAPPINGSERVICE	"c3e44fbc-45c6-47b5-aaee-f0cc002dd474"
        #define LXa_COLORMAPPINGSERVICE "colormappingservice"
        // don't need export or local for services, as it's done automatically

        // [python] ILxColorMappingService:GetDisplayColorMapping obj ColorMapping
        // [python] ILxColorMappingService:GetNumericColorMapping obj ColorMapping
        // [python] ILxColorMappingService:MakeColorMapping obj ColorMapping

#endif
