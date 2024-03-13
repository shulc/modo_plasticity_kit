/*
 * LX shade module
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
#ifndef LX_shade_H
#define LX_shade_H

typedef struct vt_ILxTextureLayer ** ILxTextureLayerID;
typedef struct vt_ILxTextureEval1 ** ILxTextureEval1ID;
typedef struct vt_ILxTextureEval ** ILxTextureEvalID;
typedef struct vt_ILxTextureVMap ** ILxTextureVMapID;
typedef struct vt_ILxTextureMask ** ILxTextureMaskID;
typedef struct vt_ILxTextureGL ** ILxTextureGLID;
typedef struct vt_ILxValueTexture1 ** ILxValueTexture1ID;
typedef struct vt_ILxValueTexture ** ILxValueTextureID;
typedef struct vt_ILxValueTextureCustom ** ILxValueTextureCustomID;
typedef struct vt_ILxTexture ** ILxTextureID;
typedef struct vt_ILxCompShader1 ** ILxCompShader1ID;
typedef struct vt_ILxCompShader ** ILxCompShaderID;
typedef struct vt_ILxCustomMaterial1 ** ILxCustomMaterial1ID;
typedef struct vt_ILxCustomMaterial2 ** ILxCustomMaterial2ID;
typedef struct vt_ILxCustomMaterial3 ** ILxCustomMaterial3ID;
typedef struct vt_ILxCustomMaterial ** ILxCustomMaterialID;

#include <lxcom.h>
#include <lximage.h>
#include <lxvector.h>
#include <lxraycast.h>
#include <lxaction.h>

/*
 * This is the interface used to evaluate texture stack layers.
 * 'Slice' is called during shader slicing and returns the slice index used for evaluation.
 * 'Output' is called just before slicing and determines what the shader output is for the desired
 * output.
 * 'Opaque': if the output completely overwrites existing valuyes then 'opaque' should be true.
 * 'VType': returns the eval vtype, that is the total evaluation vtype that includes all slices the effect vtype.
 * 'Effect': returns the effect vtype.
 */

        typedef struct st_MeshBin *		LXtMeshBinID;


/*
 * The preview event structure contains some flags indicating what was changed and
 * the image, item and scene objects that were changed (note that it can represent
 * several events).  For item events, the channel index is also set.
 */
typedef struct st_LXtPreviewEvent {
        int		 flags;
        ILxImageID	 image;
        void		*item;
        void		*cine;
        void		*bin;
        int		 chan;
} LXtPreviewEvent;


/*
 * This is the interface used to get the flags, vector type and 2 evaluation
 * interfaces.
 * 'Flags' textures have a number of flags that indicate how the texture behaves in general. For examples flags are used to indicate if a texture references
 * clip or locator items, or if it references things like vmaps.
 * 'VectorType' returns the texture global vector type. NOTE: this should probably be implemented as ISA
 * 'Preview' is used to process item events and returns preview change flags.
 * 'PrepFilter' adds the channels for the texture modifier
 * 'AllocFilter'  allocates a full texture filter object
 * 'AllocTexture'  allocates a simpler texture evaluation object.
 */
typedef struct vt_ILxTextureLayer {
        ILxUnknown	 iunk;
        LXxMETHOD( int,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
VectorType) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( int,
Preview) (
        LXtObjectID		 self,
        LXtPreviewEvent		*event);

        LXxMETHOD( LxResult,
PrepFilter) (
        LXtObjectID		 self,
        LXtObjectID		 eval);

        LXxMETHOD( LxResult,
AllocFilter) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        int			*offset,
        int			 chan,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
AllocTexture) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        int			 offset,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
LinkSampleChans) (
        LXtObjectID		 self,
        LXtObjectID		 nodalEtor,
        int			*idx,
        int			*idxLoc);

        LXxMETHOD( int,
IsSampleDriven) (
        LXtObjectID		 self);
} ILxTextureLayer;

/*
 * N5: Item() returns the internal item pointer!
 */
typedef struct vt_ILxTextureEval1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Setup) (
        LXtObjectID		 self,
        int			 slice);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        LXtObjectID		 vs,
        int			 slice);

        LXxMETHOD( void,
Output) (
        LXtObjectID		 self,
        LXtObjectID		 vtOutput,
        LXtObjectID		*vtSubset);

        LXxMETHOD( int,
Slice) (
        LXtObjectID		 self,
        LXtObjectID		 vtOutput,
        LXtObjectID		 tvDesc,
        LXtMeshBinID		 meshbin,
        int			 srfType);

        LXxMETHOD( void,
Select) (
        LXtObjectID		 self,
        LXtObjectID		 teElt,
        LXtObjectID		 tvDesc,
        LXtMeshBinID		 meshbin,
        int			 srfType);

        LXxMETHOD( int,
Smoothing) (
        LXtObjectID		 self,
        double			*smooth,
        double			*angle,
        int			*useArea);

        LXxMETHOD( int,
Layer) (
        LXtObjectID		 self,
        double			*opa,
        int			*invert,
        int			*blend);

        LXxMETHOD( int,
Opaque) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
VType) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Effect) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Item) (
        LXtObjectID		 self,
        void		       **item);

        LXxMETHOD( int,
Implicit) (
        LXtObjectID		 self);

        LXxMETHOD( int,
Shader) (
        LXtObjectID		 self);

        LXxMETHOD( int,
Material) (
        LXtObjectID		 self);
} ILxTextureEval1;

/*
 * The new interface supports the updated Smoothing method.
 */
typedef struct vt_ILxTextureEval {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Setup) (
        LXtObjectID		 self,
        int			 slice);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        LXtObjectID		 vs,
        int			 slice);

        LXxMETHOD( void,
Output) (
        LXtObjectID		 self,
        LXtObjectID		 vtOutput,
        LXtObjectID		*vtSubset);

        LXxMETHOD( int,
Slice) (
        LXtObjectID		 self,
        LXtObjectID		 vtOutput,
        LXtObjectID		 tvDesc,
        LXtMeshBinID		 meshbin,
        int			 srfType);

        LXxMETHOD( void,
Select) (
        LXtObjectID		 self,
        LXtObjectID		 teElt,
        LXtObjectID		 tvDesc,
        LXtMeshBinID		 meshbin,
        int			 srfType);

        LXxMETHOD( int,
Smoothing) (
        LXtObjectID		 self,
        double			*smooth,
        double			*angle,
        int			*weighting,
        int			*normalMethod,
        int			*creasing);

        LXxMETHOD( int,
Layer) (
        LXtObjectID		 self,
        double			*opa,
        int			*invert,
        int			*blend);

        LXxMETHOD( int,
Opaque) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
VType) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Effect) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Item) (
        LXtObjectID		 self,
        void		       **item);

        LXxMETHOD( int,
Implicit) (
        LXtObjectID		 self);

        LXxMETHOD( int,
Shader) (
        LXtObjectID		 self);

        LXxMETHOD( int,
Material) (
        LXtObjectID		 self);
} ILxTextureEval;

/*
 * This is the interface used to find out vmaps used by texture layers.
 * -	Count
 * This returns the number of vmaps referenced by the texture
 * - Name
 * This returns the name of the vmap given its index
 * - Type
 * This returns the vmap type given its index.
 * 
 */
typedef struct vt_ILxTextureVMap {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Count) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Name) (
        LXtObjectID		 self,
        unsigned		 index,
        const char	       **name);

        LXxMETHOD( LXtID4,
Type) (
        LXtObjectID		 self,
        unsigned		 index);
} ILxTextureVMap;

/*
 * Mask layers have a specific interface used to compute partitioning. Partitioning
 * is done by ptags and objects, it can use either or both at the same time.
 * For example, a mesh can be partionned by a material name and an object ID, so you
 * could have ptag:"Default", object:"Mesh A". This would apply the mask on all polygons
 * with the "Default" material ptag on object "Mesh A".
 * -	Tag
 * This returns the polygon tag type used for partioning.
 * -	String
 * This returns the name used on polygon tags, like the material name.
 * 
 * -	Object
 * This returns item ID of the object used for partitioning.
 * 
 * -	Type
 * This returns the shader type.
 * 
 * -	Stack
 * This returns the mask evaluation sub-stack, that is the stack for all the mask's child
 * items.
 * 
 * N5: Object() returns the internal item pointer.
 * 
 * N5: Stack() returns the internal EvalStackID (for which we currently have no COM option!).
 * 
 */
typedef struct vt_ILxTextureMask {
        ILxUnknown	 iunk;
        LXxMETHOD( LXtID4,
Tag) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
String) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD( LxResult,
Object) (
        LXtObjectID		 self,
        void		       **item);

        LXxMETHOD( unsigned,
Type) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Stack) (
        LXtObjectID		 self,
        void		       **stack);

        LXxMETHOD( int,
ApplyToSub) (
        LXtObjectID		 self);
} ILxTextureMask;

/*
 * Texture layers have a specific GL interface used to evaluate GL surface
 * attributes.
 */
typedef struct vt_ILxTextureGL {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 chan,
        LXtMeshBinID		 mbin,
        LXtObjectID		 item,
        void			*gls);

        LXxMETHOD( int,
IsShader) (
        LXtObjectID		 self,
        LXtObjectID		 chan,
        LXtMeshBinID		 mbin,
        LXtObjectID		 item);
} ILxTextureGL;

/*
 * A value texture is a simple type of texture, also called procedural although
 * that's incorrect since value textures can come from data sources other than
 * algorithms. A value texture provides a scalar, color or vector value at every
 * point on a surface.
 * - SetupChannels
 * This is called when the item type is first defined to determine the channels
 * that should be added to the item definition.
 * - LinkChannels
 * This is called with an ILxEvaluation interface and the texture should add any
 * channels that it wants to read.
 * 
 * - ReadChannels
 * This is called with an ILxAttributes interface so the texture can read any of
 * the values that it needs at the current time. The values read should be cached
 * (along with any other needed scratch space) to an allocated block of data
 * returned indirectly.
 * 
 * - Customize
 * After channels are read the value texture can request surface features and
 * sample vector packets. No guarantees.
 * 
 * - Evaluate
 * This is called during rendering for every sample where the value texture
 * applies. The function should use the spot parameters of the sample in the
 * input packet, and write results to the output packet.
 * 
 * - Cleanup
 * Frees the data block allocated by ReadChannels() method.
 * 
 */
typedef struct vt_ILxValueTexture1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetupChannels) (
        LXtObjectID		 self,
        LXtObjectID		 addChan);

        LXxMETHOD( LxResult,
LinkChannels) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
ReadChannels) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        void		       **ppvData);

        LXxMETHOD( LxResult,
Customize) (
        LXtObjectID		 self,
        LXtObjectID		 custom,
        void		       **ppvData);

        LXxMETHOD( void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        LXpTextureOutput	*tOut,
        void			*data);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self,
        void			*data);
} ILxValueTexture1;

/*
 * The new and current version of the interface support the 'LinkSampleChannels',
 * 'IsSampleDriven' and 'Setup' methods.
 * - LinkSampleChannels
 * This is called with an ILxEvaluation/ILxAttributes interface and the texture should add any
 * channels that it wants to read on a per-sample basis. This method should also be used to store
 * a copy of the CLxUser_Attributes derived from the nodalEtor passed in. If your 'evalData' is
 * derived from the CLxSampleRendData user class, then you can simply perform an 'rd->at.set (nodalEtor)'
 * as shown in the example below.
 * - IsSampleDriven
 * For efficiency, it helps if the shading system knows if a texture has any channels that are
 * per-sample driven. If not, much of the per-sample setup can be skipped, making rendering faster.
 * This will be called to ask if the texture is in any way sample-driven for the current pass.
 * This can be determined by using the CLxUser_NodalService::AnyDrivenChans() method.
 * 
 * - Setup
 * This is called when a new shader slice is created. It may be called multiple times when setting
 * up a render or preview - once for each new slice.
 * 
 */
typedef struct vt_ILxValueTexture {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetupChannels) (
        LXtObjectID		 self,
        LXtObjectID		 addChan);

        LXxMETHOD( LxResult,
LinkChannels) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
LinkSampleChannels) (
        LXtObjectID		 self,
        LXtObjectID		 nodalEtor,
        LXtObjectID		 item,
        int			*idx);

        LXxMETHOD( LxResult,
ReadChannels) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        void		       **ppvData);

        LXxMETHOD( LxResult,
Customize) (
        LXtObjectID		 self,
        LXtObjectID		 custom,
        void		       **ppvData);

        LXxMETHOD( LxResult,
Setup) (
        LXtObjectID		 self,
        void			*data);

        LXxMETHOD( void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        int			*idx,
        LXtObjectID		 vector,
        LXpTextureOutput	*tOut,
        void			*data);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self,
        void			*data);

        LXxMETHOD( int,
IsSampleDriven) (
        LXtObjectID		 self,
        int			*idx);
} ILxValueTexture;

/*
 * This interface is passed to the Customize() method.
 */
typedef struct vt_ILxValueTextureCustom {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
AddFeature) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name);

        LXxMETHOD( LxResult,
AddPacket) (
        LXtObjectID		 self,
        const char		*name);
} ILxValueTextureCustom;

typedef struct vt_ILxTexture {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Locator) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
SetLocator) (
        LXtObjectID		 self,
        LXtObjectID	         tloc);

        LXxMETHOD(  LxResult,
Image) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
SetImage) (
        LXtObjectID		 self,
        LXtObjectID	         img);

        LXxMETHOD(  const char *,
ImageName) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
EvalImage) (
        LXtObjectID		 self,
        LXtObjectID		 scene,
        void		       **ppvObj);

        LXxMETHOD(  int,
LocatorProjectionMode) (
        LXtObjectID		 self,
        double			 time);

        LXxMETHOD(  int,
LocatorProjectionAxis) (
        LXtObjectID		 self,
        double			 time);

        LXxMETHOD(  const char *,
Effect) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetEffect) (
        LXtObjectID		 self,
        const char		*effect);
} ILxTexture;

/*
 * A component shader is a simple type of shader that sets the shading component and output packets.
 * - SetupChannels
 * This is called when the item type is first defined to determine the channels
 * that should be added to the item definition.
 * - LinkChannels
 * This is called with an ILxEvaluation interface and the texture should add any
 * channels that it wants to read.
 * 
 * - ReadChannels
 * This is called with an ILxAttributes interface so the texture can read any of
 * the values that it needs at the current time. The values read should be cached
 * (along with any other needed scratch space) to an allocated block of data
 * returned indirectly.
 * 
 * - Customize
 * After channels are read the value texture can request surface features and
 * sample vector packets. No guarantees.
 * 
 * - Evaluate
 * This is called during rendering for every sample where the shader applies.
 * The function gets the raycast object and  the shade component and
 * output packets that it can alter.
 * 
 * - SetShadeFlags
 * This is called before rendering and allows a component shader to set the
 * shading flags, which allows it do things like be transparent to shadow
 * rays or be double sided, or set a light linking group.
 * 
 * - SetOpaque
 * This allows the shader to override its "opaqueness". For shaders that
 * use other shaders as inputs, such as the cel and halftone shader, it
 * is necessary that they are not opaque.
 * 
 * - CustomPacket
 * This allows the shader to specify a custom packet it GETS.
 * 
 * - Cleanup
 * Frees the data block allocated by ReadChannels() method.
 * 
 */
typedef struct vt_ILxCompShader1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetupChannels) (
        LXtObjectID		 self,
        LXtObjectID		 addChan);

        LXxMETHOD( LxResult,
LinkChannels) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
ReadChannels) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        void		       **ppvData);

        LXxMETHOD( LxResult,
Customize) (
        LXtObjectID		 self,
        LXtObjectID		 custom,
        void		       **ppvData);

        LXxMETHOD( void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        LXtObjectID		 rayObj,
        LXpShadeComponents	*sCmp,
        LXpShadeOutput		*sOut,
        void			*data);

        LXxMETHOD( LxResult,
SetShadeFlags) (
        LXtObjectID		 self,
        LXpShadeFlags		*sFlg);

        LXxMETHOD( LxResult,
SetOpaque) (
        LXtObjectID		 self,
        int			*opaque);

        LXxMETHOD( LxResult,
CustomPacket) (
        LXtObjectID		 self,
        const char		**packet);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self,
        void			*data);
} ILxCompShader1;

/*
 * The new and current version of the interface support the 'Flags' method.
 * - Flags
 * This returns some of the LXfSHADERFLAGS_ to describe basic shader behaviors.
 */
typedef struct vt_ILxCompShader {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetupChannels) (
        LXtObjectID		 self,
        LXtObjectID		 addChan);

        LXxMETHOD( LxResult,
LinkChannels) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
ReadChannels) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        void		       **ppvData);

        LXxMETHOD( LxResult,
Customize) (
        LXtObjectID		 self,
        LXtObjectID		 custom,
        void		       **ppvData);

        LXxMETHOD( void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        LXtObjectID		 rayObj,
        LXpShadeComponents	*sCmp,
        LXpShadeOutput		*sOut,
        void			*data);

        LXxMETHOD( LxResult,
SetShadeFlags) (
        LXtObjectID		 self,
        LXpShadeFlags		*sFlg);

        LXxMETHOD( LxResult,
SetOpaque) (
        LXtObjectID		 self,
        int			*opaque);

        LXxMETHOD( LxResult,
CustomPacket) (
        LXtObjectID		 self,
        const char		**packet);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self,
        void			*data);

        LXxMETHOD( int,
Flags) (
        LXtObjectID		 self);
} ILxCompShader;

/*
 * A custom material is a more advanced type of shader. It can change material attributes AND perform its own shading.
 * The custom material looks like a material item in the shader tree but it also has an implicit shader that is evaluated
 * after the base shader. Because it is a material item it can textured, the texturing works by defining a custom packet (in which the
 * texturable attributes are stored) and number of texture effects, one for each texturable attribute. The easiest way to add such effects
 * is through the ILxPacketEffect.
 * - SetupChannels
 * This is called when the item type is first defined to determine the channels
 * that should be added to the item definition.
 * - LinkChannels
 * This is called with an ILxEvaluation interface and the texture should add any
 * channels that it wants to read.
 * 
 * - ReadChannels
 * This is called with an ILxAttributes interface so the texture can read any of
 * the values that it needs at the current time. The values read should be cached
 * (along with any other needed scratch space) to an allocated block of data
 * returned indirectly.
 * 
 * - Customize
 * After channels are read the value texture can request surface features and
 * sample vector packets. No guarantees.
 * 
 * - MaterialEvaluate
 * This is called during rendering for every sample where the material
 * applies.
 * 
 * - ShaderEvaluate
 * This is called during rendering for every sample where the material applies.
 * The function gets the raycast object and  the shade component and
 * output packets that it can alter.
 * 
 * - SetShadeFlags
 * This is called before rendering and allows a component shader to set the
 * shading flags, which allows it do things like be transparent to shadow
 * rays or be double sided, or set a light linking group.
 * 
 * - SetBump
 * This is called before rendering and allows a component shader to set its
 * own bump amplitude, so it is evaluate for bump mapping.
 * 
 * - SetDisplacement
 * This works like set bump, but for displacement height.
 * 
 * - SetOpaque
 * This allows the shader to override its "opaqueness". For shaders that
 * use other shaders as inputs, such as the cel and halftone shader, it
 * is necessary that they are not opaque.
 * 
 * - SetSmoothing
 * This allows the shader to set its material smoothing amount, angle.
 * 
 * - CustomPacket
 * This allows the shader to specify a custom packet it SETS.
 * 
 * - Cleanup
 * Frees the data block allocated by ReadChannels() method.
 * 
 * - UpdatePreview
 * This allows the shader to specify the update flags it might trigger
 * for Preview.
 * 
 */
typedef struct vt_ILxCustomMaterial1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetupChannels) (
        LXtObjectID		 self,
        LXtObjectID		 addChan);

        LXxMETHOD( LxResult,
LinkChannels) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
ReadChannels) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        void		       **ppvData);

        LXxMETHOD( LxResult,
Customize) (
        LXtObjectID		 self,
        LXtObjectID		 custom,
        void		       **ppvData);

        LXxMETHOD( void,
MaterialEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        void			*data);

        LXxMETHOD( void,
ShaderEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        LXtObjectID		 rayObj,
        LXpShadeComponents	*sCmp,
        LXpShadeOutput		*sOut,
        void			*data);

        LXxMETHOD( LxResult,
SetShadeFlags) (
        LXtObjectID		 self,
        LXpShadeFlags		*sFlg);

        LXxMETHOD( LxResult,
SetBump) (
        LXtObjectID		 self,
        float			*bumpAmplitude,
        int			*clearBump);

        LXxMETHOD( LxResult,
SetDisplacement) (
        LXtObjectID		 self,
        float			*dispDist);

        LXxMETHOD( LxResult,
SetOpaque) (
        LXtObjectID		 self,
        int			*opaque);

        LXxMETHOD( LxResult,
SetSmoothing) (
        LXtObjectID		 self,
        double			*smooth,
        double			*angle);

        LXxMETHOD( LxResult,
CustomPacket) (
        LXtObjectID		 self,
        const char		**packet);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self,
        void			*data);

        LXxMETHOD( LxResult,
UpdatePreview) (
        LXtObjectID		 self,
        int			 chanIdx,
        int			*flags);
} ILxCustomMaterial1;

/*
 * The previous version of the interface support the 'Flags' method.
 * - Flags
 * This returns some of the LXfSHADERFLAGS_ to describe basic shader behaviors.
 */
typedef struct vt_ILxCustomMaterial2 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetupChannels) (
        LXtObjectID		 self,
        LXtObjectID		 addChan);

        LXxMETHOD( LxResult,
LinkChannels) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
ReadChannels) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        void		       **ppvData);

        LXxMETHOD( LxResult,
Customize) (
        LXtObjectID		 self,
        LXtObjectID		 custom,
        void		       **ppvData);

        LXxMETHOD( void,
MaterialEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        void			*data);

        LXxMETHOD( void,
ShaderEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        LXtObjectID		 rayObj,
        LXpShadeComponents	*sCmp,
        LXpShadeOutput		*sOut,
        void			*data);

        LXxMETHOD( LxResult,
SetShadeFlags) (
        LXtObjectID		 self,
        LXpShadeFlags		*sFlg);

        LXxMETHOD( LxResult,
SetBump) (
        LXtObjectID		 self,
        float			*bumpAmplitude,
        int			*clearBump);

        LXxMETHOD( LxResult,
SetDisplacement) (
        LXtObjectID		 self,
        float			*dispDist);

        LXxMETHOD( LxResult,
SetOpaque) (
        LXtObjectID		 self,
        int			*opaque);

        LXxMETHOD( LxResult,
SetSmoothing) (
        LXtObjectID		 self,
        double			*smooth,
        double			*angle);

        LXxMETHOD( LxResult,
CustomPacket) (
        LXtObjectID		 self,
        const char		**packet);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self,
        void			*data);

        LXxMETHOD( LxResult,
UpdatePreview) (
        LXtObjectID		 self,
        int			 chanIdx,
        int			*flags);

        LXxMETHOD( int,
Flags) (
        LXtObjectID		 self);
} ILxCustomMaterial2;

/*
 * - LinkSampleChannels
 * This is called with an ILxEvaluation/ILxAttributes interface and the texture should add any
 * channels that it wants to read on a per-sample basis. This method should also be used to store
 * a copy of the CLxUser_Attributes derived from the nodalEtor passed in. If your 'evalData' is
 * derived from the CLxSampleRendData user class, then you can simply perform an 'rd->at.set (nodalEtor)'
 * as shown in the example below.
 * - IsSampleDriven
 * For efficiency, it helps if the shading system knows if a texture has any channels that are
 * per-sample driven. If not, much of the per-sample setup can be skipped, making rendering faster.
 * This will be called to ask if the texture is in any way sample-driven for the current pass.
 * This can be determined by using the CLxUser_NodalService::AnyDrivenChans() method.
 */
typedef struct vt_ILxCustomMaterial3 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetupChannels) (
        LXtObjectID		 self,
        LXtObjectID		 addChan);

        LXxMETHOD( LxResult,
LinkChannels) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
LinkSampleChannels) (
        LXtObjectID		 self,
        LXtObjectID		 nodalEtor,
        LXtObjectID		 item,
        int			*idx);

        LXxMETHOD( int,
IsSampleDriven) (
        LXtObjectID		 self,
        int			*idx);

        LXxMETHOD( LxResult,
ReadChannels) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        void		       **ppvData);

        LXxMETHOD( LxResult,
Customize) (
        LXtObjectID		 self,
        LXtObjectID		 custom,
        void		       **ppvData);

        LXxMETHOD( void,
MaterialEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        int			*idx,
        LXtObjectID		 vector,
        void			*data);

        LXxMETHOD( void,
ShaderEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        LXtObjectID		 rayObj,
        LXpShadeComponents	*sCmp,
        LXpShadeOutput		*sOut,
        void			*data);

        LXxMETHOD( LxResult,
SetShadeFlags) (
        LXtObjectID		 self,
        LXpShadeFlags		*sFlg);

        LXxMETHOD( LxResult,
SetBump) (
        LXtObjectID		 self,
        float			*bumpAmplitude,
        int			*clearBump);

        LXxMETHOD( LxResult,
SetDisplacement) (
        LXtObjectID		 self,
        float			*dispDist);

        LXxMETHOD( LxResult,
SetOpaque) (
        LXtObjectID		 self,
        int			*opaque);

        LXxMETHOD( LxResult,
SetSmoothing) (
        LXtObjectID		 self,
        double			*smooth,
        double			*angle);

        LXxMETHOD( LxResult,
CustomPacket) (
        LXtObjectID		 self,
        const char	       **packet);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self,
        void			*data);

        LXxMETHOD( LxResult,
UpdatePreview) (
        LXtObjectID		 self,
        int			 chanIdx,
        int			*flags);

        LXxMETHOD( int,
Flags) (
        LXtObjectID		 self);
} ILxCustomMaterial3;

/*
 * The new and current version of the interface support the updated 'SetSmoothing' method.
 * - SetSmoothing
 * This allows the shader to set its material smoothing amount, angle, weighting flags, normal generation method and creasing flags.
 */
typedef struct vt_ILxCustomMaterial {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetupChannels) (
        LXtObjectID		 self,
        LXtObjectID		 addChan);

        LXxMETHOD( LxResult,
LinkChannels) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
LinkSampleChannels) (
        LXtObjectID		 self,
        LXtObjectID		 nodalEtor,
        LXtObjectID		 item,
        int			*idx);

        LXxMETHOD( int,
IsSampleDriven) (
        LXtObjectID		 self,
        int			*idx);

        LXxMETHOD( LxResult,
ReadChannels) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        void		       **ppvData);

        LXxMETHOD( LxResult,
Customize) (
        LXtObjectID		 self,
        LXtObjectID		 custom,
        void		       **ppvData);

        LXxMETHOD( void,
MaterialEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        int			*idx,
        LXtObjectID		 vector,
        void			*data);

        LXxMETHOD( void,
ShaderEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        LXtObjectID		 rayObj,
        LXpShadeComponents	*sCmp,
        LXpShadeOutput		*sOut,
        void			*data);

        LXxMETHOD( LxResult,
SetShadeFlags) (
        LXtObjectID		 self,
        LXpShadeFlags		*sFlg);

        LXxMETHOD( LxResult,
SetBump) (
        LXtObjectID		 self,
        float			*bumpAmplitude,
        int			*clearBump);

        LXxMETHOD( LxResult,
SetDisplacement) (
        LXtObjectID		 self,
        float			*dispDist);

        LXxMETHOD( LxResult,
SetOpaque) (
        LXtObjectID		 self,
        int			*opaque);

        LXxMETHOD( LxResult,
SetSmoothing) (
        LXtObjectID		 self,
        double			*smooth,
        double			*angle,
        int			*weighting,
        int			*normalMethod,
        int			*creasing);

        LXxMETHOD( LxResult,
CustomPacket) (
        LXtObjectID		 self,
        const char	       **packet);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self,
        void			*data);

        LXxMETHOD( LxResult,
UpdatePreview) (
        LXtObjectID		 self,
        int			 chanIdx,
        int			*flags);

        LXxMETHOD( int,
Flags) (
        LXtObjectID		 self);
} ILxCustomMaterial;


        #define	LXi_TEXLAYER_BLEND_NORMAL	0
        #define	LXi_TEXLAYER_BLEND_ADD		1
        #define	LXi_TEXLAYER_BLEND_SUB		2
        #define	LXi_TEXLAYER_BLEND_DIFF		3
        #define	LXi_TEXLAYER_BLEND_NORMALMULT	4
        #define	LXi_TEXLAYER_BLEND_DIV		5
        #define	LXi_TEXLAYER_BLEND_MULTIPLY	6
        #define	LXi_TEXLAYER_BLEND_SCREEN	7
        #define	LXi_TEXLAYER_BLEND_OVERLAY	8
        #define	LXi_TEXLAYER_BLEND_SOFTLIGHT	9
        #define	LXi_TEXLAYER_BLEND_HARDLIGHT	10
        #define	LXi_TEXLAYER_BLEND_DARKEN	11
        #define	LXi_TEXLAYER_BLEND_LIGHTEN	12
        #define	LXi_TEXLAYER_BLEND_COLORDODGE	13
        #define	LXi_TEXLAYER_BLEND_COLORBURN	14


        #define LXi_BRDFTYPE_BLINN	0
        #define LXi_BRDFTYPE_ASHIKHMIN	1
        #define LXi_BRDFTYPE_GTR	2
        #define LXi_BRDFTYPE_PRINCIPLED	3


        #define	LXi_SHADERMODEL_MODO			0
        #define	LXi_SHADERMODEL_UNREAL			1
        #define	LXi_SHADERMODEL_UNITY			2
        #define	LXi_SHADERMODEL_PRINCIPLED		3
        #define	LXi_SHADERMODEL_PRINCIPLED_COAT		4
        #define	LXi_SHADERMODEL_PRINCIPLED_SHEEN	5
        #define	LXi_SHADERMODEL_GLTF			6
        #define	LXi_SHADERMODEL_AXF			7

/*
 * Two glTF shading models are supported:
 */

        #define	LXi_GLTFSHADINGMODELv_PBR	0
        #define	LXi_GLTFSHADINGMODELv_UNLIT	1


        #define	LXi_REFLTYPE_FULL	0
        #define	LXi_REFLTYPE_ENVIRON	1

/*
 * Options for normal calculation.
 */

        #define LXf_SMOOTHING_WEIGHT_AREA		0x01
        #define LXf_SMOOTHING_WEIGHT_AREA_SUM		0x02
        #define LXf_SMOOTHING_WEIGHT_ANGLE		0x04
        #define LXf_SMOOTHING_WEIGHT_FULL		0x08
        #define LXf_SMOOTHING_WEIGHT_DEFAULT		0

        #define LXi_SMOOTHING_NORMAL_DEFAULT		0
        #define LXi_SMOOTHING_NORMAL_NEWELL		1

        #define LXf_SMOOTHING_CREASE_ANGLE		0x01
        #define LXf_SMOOTHING_CREASE_GROUPS		0x02
        #define LXf_SMOOTHING_CREASE_FORCEGROUPS	0x04
        #define LXf_SMOOTHING_CREASE_HARDEDGES		0x08
        #define LXf_SMOOTHING_CREASE_DEFAULT		LXf_SMOOTHING_CREASE_ANGLE | LXf_SMOOTHING_CREASE_GROUPS | LXf_SMOOTHING_CREASE_HARDEDGES

/*
 * The group item has three channels: 'ptag' stores the ptag value, 'ptyp' stores
 * the ptag type, and 'subm' to apply the group textures to its submasks.
 * The item also has an object link to reference objects for masking.
 * The 'styp' channel is for surface type which at the moment is (all), triangle or fur:
 */

        #define LXi_SURF_ALL			0
        #define LXi_SURF_TRIANGLE		1
        #define LXi_SURF_FUR			2
        #define LXi_SURF_CURVE_TRIANGLE		3


        #define LXsITYPE_UNITY_SHADER	"unityShader"
        #define LXsITYPE_UNREAL_SHADER	"unrealShader"
        #define LXsITYPE_GLTF_SHADER	"glTFShader"
        #define LXsITYPE_AXF_SHADER	"AxFShader"

/*
 * Flags are used to specify the texture special behaviors.
 */

        #define LXfSHADERFLAGS_USE_LOCATOR	0x0001
        #define LXfSHADERFLAGS_USE_CLIP		0x0002
        #define LXfSHADERFLAGS_USE_LIGHT	0x0004
        #define LXfSHADERFLAGS_USE_GROUP	0x0008
        #define LXfSHADERFLAGS_NEED_UVS		0x0800
        #define LXfSHADERFLAGS_USE_CAMERA	0x2000000

/*
 * These are the preview event flags.
 */

        #define	LXfPREV_EVENT_MESH		0x01
        #define	LXfPREV_EVENT_ITEM		0x02
        #define	LXfPREV_EVENT_IMAGE		0x04
        #define	LXfPREV_EVENT_CINE		0x08
        #define	LXfPREV_EVENT_MESH_FEATURE	0x10
        #define	LXfPREV_EVENT_MESH_BIN		0x20

/*
 * These are the preview update flags, returned by the preview interface.
 */

        #define	LXfPREV_UPDATE_GEOMETRY		0x01	// geometry change on an entire item
        #define	LXfPREV_UPDATE_SHADING		0x02	// surface shader change
        #define LXfPREV_UPDATE_LIGHT		0x04	// light change (usually for shadow maps)
        #define	LXfPREV_UPDATE_BACKDROP		0x08	// environment change
        #define	LXfPREV_UPDATE_IMAGE		0x10	// image edit
        #define	LXfPREV_UPDATE_CAMERA		0x20	// camera change (like during camera navigtion)
        #define	LXfPREV_UPDATE_CLIP		0x40	// clip change

        #define	LXfPREV_UPDATE_FORCE		0XFF	// All flags


        #define LXu_TEXTURELAYER	"42369FE7-869E-4c61-8D40-AC62E529DD15"
        #define LXa_TEXTURELAYER	"textureLayer"
        #define LXsTLR_CATEGORY		"textureLayer.category"
        // [default] ILxTextureEval:LinkSampleChans = LXe_OK


        #define LXu_TEXTUREEVAL1		"847C1567-1725-4e98-BA09-EA1F9049D76A"
        #define LXa_TEXTUREEVAL1		"textureEval1"
        // [default] ILxTextureEval1:LinkSampleChans = LXe_OK
        // [default] ILxTextureEval1:IsSampleDriven = LXe_FALSE


        #define LXu_TEXTUREEVAL		"5791A0B4-4B5C-44EC-8D1D-D8CA53830FC9"
        #define LXa_TEXTUREEVAL		"textureEval"
        // [default] ILxTextureEval:LinkSampleChans = LXe_OK
        // [default] ILxTextureEval:IsSampleDriven = LXe_FALSE


        #define LXu_TEXTUREVMAP		"0C68AC79-993C-4823-97FA-EAD5EFF97B64"
        #define LXa_TEXTUREVMAP		"textureVMap"


        #define LXu_TEXTUREMASK		"701E81D3-FFA6-475a-A02D-ECE9AB15B4CD"
        #define LXa_TEXTUREMASK		"textureMask"


        #define LXu_TEXTUREGL		"55CE355E-C838-4222-ABED-CBDD808209AF"
        #define LXa_TEXTUREGL		"textureGL"


        #define LXu_VALUETEXTURE1	"CA0E3524-6F82-44B8-AAC9-DC258F548C02"
        #define LXa_VALUETEXTURE1	"valueTexture"
        // [export]  ILxValueTexture1 vtx

        #define LXu_VALUETEXTURE	"9A2DD931-F442-488a-8C6A-AF6BDDC30B32"
        #define LXa_VALUETEXTURE	"valueTexture2"
        #define LXu_VALUETEXTURECUSTOM	"DE3298A6-1607-4338-B061-185528E6FB51"
        // [export]  ILxValueTexture vtx
        // [default] ILxValueTexture:Setup = LXe_OK
        // [default] ILxValueTexture:LinkSampleChannels = LXe_OK
        // [default] ILxValueTexture:IsSampleDriven = LXe_FALSE
        // [local]   ILxValueTexture
        // [local]   ILxValueTextureCustom


        #define LXa_TEXTURE	"texture"
        #define LXu_TEXTURE	"6376D941-9437-4cf8-B6EC-AB50791FE60F"
        // [local]  ILxTexture
        // [python] ILxTexture:EvalImage	obj Image (image)
        // [python] ILxTexture:Image		obj Item
        // [python] ILxTexture:Locator		obj Item


        #define	LXi_TEXTURE_PROJ_MODE_NONE		0
        #define	LXi_TEXTURE_PROJ_MODE_PLANAR		1
        #define	LXi_TEXTURE_PROJ_MODE_CYLINDRICAL	2
        #define	LXi_TEXTURE_PROJ_MODE_SPHERICAL		3
        #define	LXi_TEXTURE_PROJ_MODE_CUBIC		4
        #define	LXi_TEXTURE_PROJ_MODE_FRONT		5
        #define	LXi_TEXTURE_PROJ_MODE_UVMAP		6
        #define	LXi_TEXTURE_PROJ_MODE_LIGHTPROBE	7
        #define	LXi_TEXTURE_PROJ_MODE_IMPLICIT		8
        #define	LXi_TEXTURE_PROJ_MODE_BOX		9

        #define	LXi_TEXTURE_PROJ_DIR_X			0
        #define	LXi_TEXTURE_PROJ_DIR_Y			1
        #define	LXi_TEXTURE_PROJ_DIR_Z			2




        #define LXi_IMAGEMAP_PIXBLEND_NEAREST	0
        #define LXi_IMAGEMAP_PIXBLEND_BILINEAR	1
        #define LXi_IMAGEMAP_PIXBLEND_BICUBIC	2



        // Image Map Channel Swizzling mode
        #define	LXi_IMAGEMAP_SWIZZLING_RGB			0
        #define	LXi_IMAGEMAP_SWIZZLING_RGBA			1
        #define	LXi_IMAGEMAP_SWIZZLING_ALPHA_ONLY		2
        #define	LXi_IMAGEMAP_SWIZZLING_RED_ONLY		3
        #define	LXi_IMAGEMAP_SWIZZLING_GREEN_ONLY		4
        #define	LXi_IMAGEMAP_SWIZZLING_BLUE_ONLY		5


        #define LXu_COMPSHADER1		"06717e9d-610d-439f-935b-af0805827ede"
        #define LXa_COMPSHADER1		"compShader"
        // [export]  ILxCompShader1 csh


        #define LXu_COMPSHADER		"371e8b57-3a1e-444b-91f8-5e43c75bf1cb"
        #define LXa_COMPSHADER		"compShader2"
        // [export]  ILxCompShader csh
        // [local]   ILxCompShader


        #define LXu_CUSTOMMATERIAL1		"d0c4106c-dfd5-4a58-ad48-45b50ae63f59"
        #define LXa_CUSTOMMATERIAL1		"customMaterial"
        // [export]  ILxCustomMaterial1 cmt


        #define LXu_CUSTOMMATERIAL2		"64e2dd96-ff7f-4c9b-967e-24dec83bfb72"
        #define LXa_CUSTOMMATERIAL2		"customMaterial2"
        // [export]  ILxCustomMaterial1 cmt


        #define LXu_CUSTOMMATERIAL3		"B6297ECF-CFE9-4923-A70C-DB87279B0411"
        #define LXa_CUSTOMMATERIAL3		"customMaterial3"
        // [export]  ILxCustomMaterial3 cmt
        // [default] ILxCustomMaterial3:LinkSampleChannels = LXe_OK
        // [default] ILxCustomMaterial3:IsSampleDriven = LXe_FALSE


        #define LXu_CUSTOMMATERIAL		"3AEBDFE5-AB69-4B58-8B8F-E1091D5F6DD5"
        #define LXa_CUSTOMMATERIAL		"customMaterial4"
        // [export]  ILxCustomMaterial cmt
        // [default] ILxCustomMaterial:LinkSampleChannels = LXe_OK
        // [default] ILxCustomMaterial:IsSampleDriven = LXe_FALSE
        // [local]   ILxCustomMaterial

/*
 * When added as item-type tags (internal) or host server tags (SDK), the graph specified by the
 * tag will be traversed to find additional items that need to be processed nodally.
 * LXsPKG_NODALITEMG is used to find layer items linked to this modifier item. If the tag beings
 * with '-', the graph will be treated as a reversed graph. If the tag begins with a '*', any
 * linked groups will be traversed and its layer items will be processed as well.
 */

        #define	LXsPKG_NODALITEMG		"nodalItemGraph"

#endif
