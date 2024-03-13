/*
 * LX txtr module
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
#ifndef LX_txtr_H
#define LX_txtr_H

typedef struct vt_ILxTextureMapFilter ** ILxTextureMapFilterID;
typedef struct vt_ILxTextureMapFilter2 ** ILxTextureMapFilter2ID;
typedef struct vt_ILxTextureMapFilter1 ** ILxTextureMapFilter1ID;
typedef struct vt_ILxTextureSpotFilter ** ILxTextureSpotFilterID;
typedef struct vt_ILxTextureFalloffFilter ** ILxTextureFalloffFilterID;

#include <lxcom.h>
#include <lxvector.h>



/*
 * 'Evaluate' computes the texture coordinates using the texture mapping options.
 * It sets the texture position packet.
 */
typedef struct vt_ILxTextureMapFilter {
        ILxUnknown	 iunk;
        LXxMETHOD(  void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        LXtSampleVectorID	 sv,
        double			*res,
        int			 i);

        LXxMETHOD(  int,
UVMap) (
        LXtObjectID		 self,
        const char	       **name,
        int			*tile,
        double			*wrap,
        int			*proj,
        int			*axis,
        double			*offset,
        double			*rot,
        int			*udim,
        int			*randomOffset,
        double			*xfrm,
        LXtFQuaternion		uvInvZRotQuat);

        LXxMETHOD(  int,
VectorMap) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  int,
UVTBasis) (
        LXtObjectID		 self,
        int			*tangentType);

} ILxTextureMapFilter;

/*
 * Legacy Interface, retired in 15.2v2
 */
typedef struct vt_ILxTextureMapFilter2 {
        ILxUnknown	 iunk;
        LXxMETHOD(  void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        LXtSampleVectorID	 sv,
        double			*res,
        int			 i);

        LXxMETHOD(  int,
UVMap) (
        LXtObjectID		 self,
        const char	       **name,
        int			*tile,
        double			*wrap,
        int			*proj,
        int			*axis,
        double			*offset,
        double			*rot,
        int			*udim,
        int			*randomOffset,
        double			*xfrm);

        LXxMETHOD(  int,
VectorMap) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  int,
UVTBasis) (
        LXtObjectID		 self,
        int			*tangentType);

} ILxTextureMapFilter2;

/*
 * Legacy Interface, retired in 11.2.
 */
typedef struct vt_ILxTextureMapFilter1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        LXtSampleVectorID	 sv,
        double			*res,
        int			 i);

        LXxMETHOD(  int,
UVMap) (
        LXtObjectID		 self,
        const char	       **name,
        int			*tile,
        double			*wrap,
        int			*proj,
        int			*axis,
        double			*offset,
        double			*rot,
        int			*udim,
        int			*randomOffset);

        LXxMETHOD(  int,
VectorMap) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  int,
UVTBasis) (
        LXtObjectID		 self,
        int			*tangentType);

} ILxTextureMapFilter1;

/*
 * 'Evaluate' computes the spot size given the input spot size and the
 * projection options.
 * 'Count' returns the number of textures hitting the spot.
 */
typedef struct vt_ILxTextureSpotFilter {
        ILxUnknown	 iunk;
        LXxMETHOD(  void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        LXtSampleVectorID	 sv,
        double			*res);
        
        LXxMETHOD(  int,
Count) (
        LXtObjectID		 self,
        LXtSampleVectorID	 sv);
} ILxTextureSpotFilter;

/*
 * This interface computes the falloff amount at the given position.
 */
typedef struct vt_ILxTextureFalloffFilter {
        ILxUnknown	 iunk;
        LXxMETHOD(  void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        LXtSampleVectorID	 sv,
        double			*res,
        int			 i);
} ILxTextureFalloffFilter;



        #define	LXi_TEXTURE_FALLOFF_CUBIC		0
        #define	LXi_TEXTURE_FALLOFF_SPHERE		1
        #define	LXi_TEXTURE_FALLOFF_LINEARX		2
        #define	LXi_TEXTURE_FALLOFF_LINEARY		3
        #define	LXi_TEXTURE_FALLOFF_LINEARZ		4



        #define	LXi_TEXTURE_RNDOFFSET_NONE		0
        #define	LXi_TEXTURE_RNDOFFSET_PART		1
        #define	LXi_TEXTURE_RNDOFFSET_MESH		2
        #define	LXi_TEXTURE_RNDOFFSET_ITEM		3


        #define LXu_TEXTUREMAPFILTER		"96704B31-F861-47A7-9A1B-ABDC41159EB6"


        #define LXu_TEXTUREMAPFILTER2		"3DC4AA9C-DEF6-4794-B0BE-F23D2869BCDC"


        #define LXu_TEXTUREMAPFILTER1		"81F4F08A-7A37-42dE-ACDE-FC5490E519C6"


        #define LXu_TEXTURESPOTFILTER		"179AD9C3-8B7B-4F91-8BB6-A23FAD3D153E"


        #define LXu_TEXTUREFALLOFFFILTER	"8F3154A6-AC4D-4610-96EF-B54E9611164B"

#endif
