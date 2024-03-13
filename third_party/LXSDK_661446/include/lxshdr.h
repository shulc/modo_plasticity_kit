/*
 * LX shdr module
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
#ifndef LX_shdr_H
#define LX_shdr_H

typedef struct vt_ILxShaderService ** ILxShaderServiceID;
typedef struct vt_ILxShader ** ILxShaderID;

#include <lxvmath.h>
#include <lxcom.h>
#include <lxmesh.h>



/*
 * This function is essentially an SDK wrapper for SchlickFresnel.
 * These functions are used for packet blending (like blending two materials
 * in the shader tree).
 * 
 * This function will convert a sample drawn from asquare 2D sampling
 * distribution in the (-1, -1) to (1, 1) range to a circular distribution.
 * 
 * This returns an ILxSampleCloud object. This can be used to generate sample points on a surface
 * with xtra data attached to it. The client simply needs to provide a cloud sample interface.
 * 
 * 
 * These shader service methods allow a custom shader to perform Russian Roulette,
 * to stochastically and unbiasedly terminate rays. It returns the importance
 * multiplier used to compensate for the termination of some rays.
 * 
 * This method allows a shader to make a thread-safe request for a random float,
 * distributed from 0.0 to 1.0.
 * 
 * PoissonOffset returns a 2D offset in the unit disc with a nice poisson distribution.
 * 
 * Given a collection, add items needed for shading.
 */
typedef struct vt_ILxShaderService {
        ILxUnknown	 iunk;
        LXxMETHOD(  float,
ComputeFresnel) (
        LXtObjectID		 self,
        const LXtFVector	 inRay,
        const LXtFVector	 normalRay,
        float			 normReflAmt);
        LXxMETHOD(  float,
ScalarBlendValue) (
        LXtObjectID		 self,
        float			 v1,
        float			 v2,
        float			 opa,
        int			 mode);

        LXxMETHOD(  void,
ColorBlendValue) (
        LXtObjectID		 self,
        LXtFVector		 c,
        const LXtFVector	 c1,
        const LXtFVector	 c2,
        float			 opa,
        int			 mode);
        LXxMETHOD(  void,
SquareToCircle) (
        LXtObjectID		 self,
        float			*x,
        float			*y);
        LXxMETHOD(  LxResult,
SampleCloud) (
        LXtObjectID		 self,
        LXtObjectID		 sample,
        void			**ppvObj);
        LXxMETHOD(		  LxResult,
MeshShaderAccessor) (
        LXtObjectID		  self,
        LXtObjectID		  meshItem,
        void			**ppvObj);

        LXxMETHOD(		  LxResult,
PolyShaderAccessor) (
        LXtObjectID		  self,
        LXtObjectID		  meshItem,
        LXtPolygonID		  polyID,
        void			**ppvObj);
        LXxMETHOD(  float,
RussianRoulette) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        float			 importance);
        LXxMETHOD(  float,
NextRandom) (
        LXtObjectID		 self,
        LXtObjectID		 vector);
        LXxMETHOD(  LxResult,
PoissonOffset) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        float			*u,
        float			*v);
        LXxMETHOD(  LxResult,
CollectMaterials) (
        LXtObjectID		 self,
        LXtObjectID		 collection);
} ILxShaderService;

/*
 * This is used to actually enumerate over all the shaders in the list
 * These are used to duplicate a shader enumerator.
 * 
 */
typedef struct vt_ILxShader {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Enumerate) (
        LXtObjectID		 self,
        LXtObjectID		 visitor);
        LXxMETHOD(  LxResult,
Spawn) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ShaderItemGet) (
        LXtObjectID		  self,
        void			**ppvObj);
} ILxShader;

/*
 * The shader service provides SDK programmers useful functions to mimic
 * some of modo's internal shading features.
 */

        #define LXu_SHADERSERVICE	 "0b4e73ac-9325-4920-afcc-7814953a26b6"
        #define LXa_SHADERSERVICE	 "shaderservice"
        // [local]  ILxShaderService
        // [const]  ILxShaderService:ComputeFresnel
        // [const]  ILxShaderService:ScalarBlend
        // [const]  ILxShaderService:ColorBlend
        // [const]  ILxShaderService:SquareToCircle
        // [const]  ILxShaderService:SampleCloud
        // [const]  ILxShaderService:RussianRoulette
        // [const]  ILxShaderService:NextRandom
        // [const]  ILxShaderService:PoissonOffset
        // [python] ILxShaderService:SampleCloud	obj SampleCloud
        // [python] ILxShaderService:MeshShaderAccessor	obj Shader
        // [python] ILxShaderService:PolyShaderAccessor	obj Shader
        // [python] ILxShaderService:SquareToCircle:x	vector
        // [python] ILxShaderService:SquareToCircle:y	vector
        // [python] type LXtPolygonID	id


        #define LXa_SHADER	"shader"
        #define LXu_SHADER	"051ba6d8-46ba-4722-8b07-943961c3aeda"
        // [local]  ILxShader
        // [python] ILxShader:ShaderItemGet	obj Item
        // [python] ILxShader:Spawn		obj Shader

#endif
