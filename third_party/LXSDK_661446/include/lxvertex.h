/*
 * LX vertex module
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
#ifndef LX_vertex_H
#define LX_vertex_H

typedef struct vt_ILxTableauVertex ** ILxTableauVertexID;
typedef struct vt_ILxVertexFeatureService ** ILxVertexFeatureServiceID;

#include <lxcom.h>



/*
 * A tableau vertex object encodes information about the structure of the vertex
 * data for sampling elements.  Shaders and the renderer negotiate for the
 * features they want from the element.  These are added to the vertex object and
 * are given offsets into the master vector.  Once set, the vector can be queried
 * for its total size, and for the offsets of each of the selected vertex
 * features.
 */
typedef struct vt_ILxTableauVertex {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddFeature) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name,
        unsigned int		*index);

        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name,
        unsigned int		*offset);

        LXxMETHOD(  unsigned int,
Size) (
        LXtObjectID		 self);

        LXxMETHOD(  unsigned int,
Count) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtID4			*type,
        const char	       **name,
        unsigned int		*offset);
} ILxTableauVertex;

/*
 * Get a new, empty TableauVertex object.
 * 
 * This gets the ident string for a vertex feature given the type and (optional) name.
 * 
 * Given the ident the various attributes of the feature can be read.
 */
typedef struct vt_ILxVertexFeatureService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
AllocVertex) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name,
        const char	       **ident);
        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		 self,
        const char		*ident,
        LXtID4			*type);

        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        const char		*ident,
        const char	       **name);

        LXxMETHOD(  LxResult,
Dimension) (
        LXtObjectID		 self,
        const char		*ident,
        unsigned		*dimension);

        LXxMETHOD(  LxResult,
VectorType) (
        LXtObjectID		 self,
        const char		*ident,
        const char	       **vecType);

        LXxMETHOD(  LxResult,
DataType) (
        LXtObjectID		 self,
        const char		*ident,
        const char	       **typeName);

        LXxMETHOD(  LxResult,
TestCategory) (
        LXtObjectID		 self,
        const char		*ident,
        const char		*category);
} ILxVertexFeatureService;

/*
 * Vertex feature categories indicate the context where the feature is expected
 * to be valid. Currently that just surfaces and particles.
 */

        #define LXsVFCAT_SURFACE	"surface"
        #define LXsVFCAT_PARTICLE	"particle"

/*
 * A vector type can in theory be any string of unique character codes, but these
 * are the most common and most likely supported.
 */

        #define LXsVECTYPE_XY		"XY"
        #define LXsVECTYPE_XYZ		"XYZ"
        #define LXsVECTYPE_RGB		"RGB"
        #define LXsVECTYPE_RGBA		"RGBA"
        #define LXsVECTYPE_UV		"UV"
        #define LXsVECTYPE_UVW		"UVW"


        #define LXu_TABLEAUVERTEX	"F90A0A39-EE2A-4D11-912B-9338EF271DFF"
        // [local]  ILxTableauVertex

/*
 * The vertex feature service provides methods for interrogating features.
 */

        #define LXa_VERTEXFEATURESERVICE	"vertexfeatureservice"
        #define LXu_VERTEXFEATURESERVICE	"B40D51A9-6C04-46D1-BA8A-0FE9B32EAC3C"
        // [python] ILxVertexFeatureService:AllocVertex		obj TableauVertex
        // [python] ILxVertexFeatureService:TestCategory	bool

/*
 * For some subset of features we define packages. If an item type wants to be able
 * to use a package it should set this server tag to the feature category.
 */

        #define LXsPKG_USEFEATURES	"package.useFeatures"

#endif
