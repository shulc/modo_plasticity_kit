/*
 * LX deform module
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
#ifndef LX_deform_H
#define LX_deform_H

typedef struct vt_ILxFalloff ** ILxFalloffID;
typedef struct vt_ILxFalloff1 ** ILxFalloff1ID;
typedef struct vt_ILxDeformation ** ILxDeformationID;
typedef struct vt_ILxDeformation1 ** ILxDeformation1ID;
typedef struct vt_ILxDeformer ** ILxDeformerID;
typedef struct vt_ILxDeformer1 ** ILxDeformer1ID;
typedef struct vt_ILxMeshInfluence ** ILxMeshInfluenceID;
typedef struct vt_ILxItemInfluence ** ILxItemInfluenceID;
typedef struct vt_ILxGroupDeformer ** ILxGroupDeformerID;
typedef struct vt_ILxWeightMapDeformerItem ** ILxWeightMapDeformerItemID;
typedef struct vt_ILxDeformerService ** ILxDeformerServiceID;

#include <lxmesh.h>

/*
 * A deform influence describes a collection of elements and how they might move.
 * The flags indicate if the deformation has internal weights, offsets and/or a
 * per-element transform.
 */

        typedef void *		 LXtDeformElt;

        // [python] type LXtDeformElt	id



/*
 * For any falloff with a specific bounds, the falloff can return a bounding box.
 * 
 * Clients can either query by position, by vertex, by polygon or a combination of
 * all three.
 * 
 * Weights can also be evaluated in runs.
 * 
 * If the falloff is being evaluated using a vertex or polygon, the SetMesh should
 * be called to provide a context for any subsequent weight evaluations.
 */
typedef struct vt_ILxFalloff {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Bounds) (
        LXtObjectID		 self,
        LXtBBox			*box);
        LXxMETHOD( float,
WeightF) (
        LXtObjectID		 self,
        const LXtFVector	 position,
        LXtPointID		 point,
        LXtPolygonID		 polygon);
        LXxMETHOD( LxResult,
WeightRun) (
        LXtObjectID		 self,
        const float	       **pos,
        const LXtPointID	*points,
        const LXtPolygonID	*polygons,
        float			*weight,
        unsigned		 num);
        LXxMETHOD( LxResult,
SetMesh) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtMatrix4		 xfrm);
} ILxFalloff;

/*
 * Translation from ILxFalloff to legacy interfaces.
 */
typedef struct vt_ILxFalloff1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Bounds) (
        LXtObjectID		 self,
        LXtBBox			*box);

        LXxMETHOD( float,
WeightF) (
        LXtObjectID		 self,
        const LXtFVector	 position);

        LXxMETHOD( LxResult,
WeightRun) (
        LXtObjectID		 self,
        const float	       **pos,
        float			*weight,
        unsigned		 num);
} ILxFalloff1;

/*
 * Flag bits indicate if a deformation is non-linear and/or rigid. Non-linear means
 * that offsets don't lie on a simple line for different weight values but instead
 * trace curves. Rigid means that the transform at weight 1 can be described by a
 * 4x4 matrix.  
 * The LXfDEFORMATION_USESUBSET flag indicates that only some of the weighted points
 * in a deformer's partition will be affected, which can help with optimization in
 * certain cases.  Most deformations will affect all weighted points in a partition 
 * when evaluated, but deformations limited to a maximum distance from an effector, 
 * for instance, may only affect nearby points.
 * 
 * 
 * For rigid deformations, this method returns the matrix for unity weight.
 * 
 * These three methods compute the offset from a starting position at a given
 * weight value. OffsetF() takes a single point and a weight; OffsetRun() takes
 * vector arrays for faster computation, and the weight array pointer can be null
 * to indicate unity.
 */
typedef struct vt_ILxDeformation {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Transform) (
        LXtObjectID		 self,
        LXtMatrix4		 xfrm);
        LXxMETHOD( void,
OffsetF) (
        LXtObjectID		 self,
        const LXtFVector	 position,
        int			 idx,
        float			 weight,
        LXtFVector		 offset);

        LXxMETHOD( void,
OBSOLETE) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
OffsetRun) (
        LXtObjectID		 self,
        const float	       **pos,
        const int		*idx,
        const float		*weight,
        float		       **offset,
        unsigned		 num);
} ILxDeformation;

typedef struct vt_ILxDeformation1 {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Transform) (
        LXtObjectID		 self,
        LXtMatrix4		 xfrm);

        LXxMETHOD( void,
OffsetF) (
        LXtObjectID		 self,
        const LXtFVector	 position,
        float			 weight,
        LXtFVector		 offset);

        LXxMETHOD( void,
OBSOLETE) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
OffsetRun) (
        LXtObjectID		 self,
        const float	       **pos,
        const float		*weight,
        float		       **offset,
        unsigned		 num);
} ILxDeformation1;

/*
 * Flags are the same flags assigned to the deformer item type, plus a runtime flag
 * to indicate if linear interpolation should be used.
 * 
 * All the elements affected by this deformer exist in partitions. This method
 * enumerates the elements in a specific partition.
 * 
 * The element pointer can be read out during enumeration. For a mesh partition the
 * element must be a LXtPointID, and for and item partition the element must be an
 * ILxUnknownID for the item. For deformers that support items, the items are all
 * assumed to be in partition zero.
 * Elements in a partition can be further segmented by numeric ID which is also returned
 * from this method. All the elements in a run will come from the same segment.
 * 
 * 
 * As an alternative to enumerating elements, the client can set a specific element
 * ID and partition before quering for attributes.
 * 
 * The query methods get data about specific elements given their element ID. Weight()
 * gets the degree of influence on the element, and Offset() gets the weighted offset
 * for the deformation. Both of these get an input position that may be the real input
 * position or may be a hypothetical.
 * 
 * The "Run" versions of the interfaces operate on arrays of elements, positions and
 * weights. OffsetRun() can be called with a null 'weight' pointer to get offsets with
 * all unity weight.
 */
typedef struct vt_ILxDeformer {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD( unsigned,
PartitionCount) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
EnumeratePartition) (
        LXtObjectID		 self,
        LXtObjectID		 visitor,
        unsigned		 part);
        LXxMETHOD( LXtDeformElt,
Element) (
        LXtObjectID		 self,
        unsigned		*segment);
        LXxMETHOD( LxResult,
SetPartition) (
        LXtObjectID		 self,
        unsigned		 part);
        LXxMETHOD( float,
Weight) (
        LXtObjectID		 self,
        LXtDeformElt		 elt,
        const LXtFVector	 pos,
        int			 idx);

        LXxMETHOD( void,
Offset) (
        LXtObjectID		 self,
        LXtDeformElt		 elt,
        float			 weight,
        const LXtFVector	 pos,
        int			 idx,
        LXtFVector		 offset);
        LXxMETHOD( LxResult,
WeightRun) (
        LXtObjectID		 self,
        unsigned		 segment,
        const LXtDeformElt	*elt,
        const float	       **pos,
        const int		*idx,
        float			*weight,
        unsigned		 num);

        LXxMETHOD( LxResult,
OffsetRun) (
        LXtObjectID		 self,
        unsigned		 segment,
        const LXtDeformElt	*elt,
        const float	       **pos,
        const int		*idx,
        const float		*weight,
        float		       **offset,
        unsigned		 num);
} ILxDeformer;

typedef struct vt_ILxDeformer1 {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD( unsigned,
PartitionCount) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
EnumeratePartition) (
        LXtObjectID		 self,
        LXtObjectID		 visitor,
        unsigned		 part);

        LXxMETHOD( LXtDeformElt,
Element) (
        LXtObjectID		 self,
        unsigned		*segment);

        LXxMETHOD( LxResult,
SetPartition) (
        LXtObjectID		 self,
        unsigned		 part);

        LXxMETHOD( float,
Weight) (
        LXtObjectID		 self,
        LXtDeformElt		 elt,
        const LXtFVector	 pos);

        LXxMETHOD( void,
Offset) (
        LXtObjectID		 self,
        LXtDeformElt		 elt,
        float			 weight,
        const LXtFVector	 pos,
        LXtFVector		 offset);

        LXxMETHOD( LxResult,
WeightRun) (
        LXtObjectID		 self,
        unsigned		 segment,
        const LXtDeformElt	*elt,
        const float	       **pos,
        float			*weight,
        unsigned		 num);

        LXxMETHOD( LxResult,
OffsetRun) (
        LXtObjectID		 self,
        unsigned		 segment,
        const LXtDeformElt	*elt,
        const float	       **pos,
        const float		*weight,
        float		       **offset,
        unsigned		 num);
} ILxDeformer1;

/*
 * A mesh influence is a specific sub-type of deform influence that operates on
 * points in meshes. The partition of the mesh influence is different meshes.
 * The mesh influence interface can be found in two contexts. The first is by
 * reading the influence channel of an item that affects meshes. In that case
 * it will be polymorphic with the deform influence interface, and each mesh in
 * the list is a partition in the deform.
 * 
 * The mesh influence interface may also be found on items. If it is then that
 * item affects direct control over a set of meshes. An item without a mesh
 * influence interface that nonetheless generates a mesh influence object on its
 * influence channel is an "any mesh" influence. It will be automatically wrapped
 * as a deform influence acting on linked meshes.
 * 
 * Meshes are given by a count and indices. MeshByIndex() actually gets the mesh
 * item affected.
 * 
 * 
 * This returns the partition index for the given mesh index, since they may not
 * match exactly.
 * 
 * Before reading out values, the client sets the actual mesh and transform based
 * on the index of the mesh item. Once set these don't change unless the mesh
 * or transform are changed.
 */
typedef struct vt_ILxMeshInfluence {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
MeshCount) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
MeshByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);
        LXxMETHOD( unsigned,
PartitionIndex) (
        LXtObjectID		 self,
        unsigned		 index);
        LXxMETHOD( LxResult,
SetMesh) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtObjectID		 mesh,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
SetTransform) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtMatrix4		 xfrm);

        LXxMETHOD( LxResult,
MeshChange) (
        LXtObjectID		 self,
        unsigned		 index,
        LxResult		 change);
} ILxMeshInfluence;

/*
 * Analogous to MeshInfluence, except that there's no concept of a partition. It's
 * just a list of items. The list is accessed with a visitor.
 */
typedef struct vt_ILxItemInfluence {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
HasItems) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Enumerate) (
        LXtObjectID		 self,
        LXtObjectID		 visitor);

        LXxMETHOD( LxResult,
GetItem) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
AllowTransform) (
        LXtObjectID		 self,
        unsigned		 index,
        unsigned		*flags);
} ILxItemInfluence;

/*
 * The ILxGroupDeformer interface allows clients to read out the blended weights
 * affecting each point in the group. The DeformerCount / ByIndex() methods allow
 * the client to see the members of the group. PointEffect() takes a point in
 * one of the target meshes and returns lists of member deformer indicies and their
 * weights. If the provided buffers are too small this returns LXe_SHORTBUFFER.
 */
typedef struct vt_ILxGroupDeformer {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
DeformerCount) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
DeformerByIndex) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
PointEffect) (
        LXtObjectID		 self,
        unsigned		 meshIndex,
        LXtPointID		 point,
        unsigned		*deformer,
        float			*weight,
        unsigned		*count,
        unsigned		 max);
} ILxGroupDeformer;

/*
 * A subset of deformer items get their weights from weight maps. This interface allows
 * the weight map for the deformer to be displayed and edited in the 3D view.
 */
typedef struct vt_ILxWeightMapDeformerItem {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
GetMapName) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( LxResult,
GetColor) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead,
        LXtVector		 col);
} ILxWeightMapDeformerItem;

/*
 * 
 * The DeformerFlags() method returns the LXfDEFORMER_* flags for the item, or
 * NOTFOUND if this is not a deformer. DeformerChannel() returns the channel index
 * for the evaluated deformer object.
 * 
 * Compute the merge of two change states.
 * 
 * Given a deformer, get the set of meshes that it influences. The MeshCount() interface
 * will return LXe_FALSE if the deformer is currently inactive as result of being part
 * of a deformation group.
 * 
 * Given a group deformer item and a channel read object (for evaluation, not action)
 * this returns the group deformer interface.
 * 
 * Given a deformer, this returns the deformation item. If this is a locator deformer
 * then it returns LXe_TRUE, otherwise FALSE.
 * 
 * Some events can cause the set of items that are targets for deformations to change
 * implicitly. If that happens, a client can call this method to cause the deformation
 * system to update.
 * 
 * The LXtDeformElt type can represent a point or an item (so far). For points the value
 * is the same as the LXtPointID for the point. For items it's a special pointer that
 * can be converted to and from an item ILxUnknownID using these functions.
 * 
 * Clients which handle their own deformer partitions and MeshCounts by implementing the 
 * MeshInfluence interface may also want to account for target meshes belonging to stack 
 * operators.  The mesh targets for any meshop stack which a given deformer is linked
 * into can be walked using the StackTargetCount and StackTargetByIndex functions.
 */
typedef struct vt_ILxDeformerService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
DeformerFlags) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*flags);

        LXxMETHOD(  LxResult,
DeformerChannel) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*index);
        LXxMETHOD(  LxResult,
MergeChangeState) (
        LXtObjectID		 self,
        LxResult		 c1,
        LxResult		 c2);
        LXxMETHOD(  LxResult,
MeshCount) (
        LXtObjectID		 self,
        LXtObjectID		 defItem,
        unsigned		*count);

        LXxMETHOD(  LxResult,
MeshByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 defItem,
        unsigned		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
GroupDeformer) (
        LXtObjectID		 self,
        LXtObjectID		 dgroup,
        LXtObjectID		 chanRead,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
DeformerDeformationItem) (
        LXtObjectID		 self,
        LXtObjectID		 defItem,
        void		       **ppvObj);
        LXxMETHOD(  void,
InvalidateTargets) (
        LXtObjectID		 self,
        LXtObjectID		 scene);
        LXxMETHOD(  LXtDeformElt,
ItemToDeformElt) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD(  LXtObjectID,
DeformEltToItem) (
        LXtObjectID		 self,
        LXtDeformElt		 elt);
        LXxMETHOD(  LxResult,
StackTargetCount) (
        LXtObjectID		 self,
        LXtObjectID		 defItem,
        unsigned		*count);

        LXxMETHOD(  LxResult,
StackTargetByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 defItem,
        unsigned		 index,
        void		       **ppvObj);
} ILxDeformerService;

/*
 * A falloff is a scalar field, filling space with a weight value typically between
 * zero and one.
 */

        #define LXu_FALLOFF		"B75CFFA3-D25C-4520-B1C6-3CB3924BF597"
        #define LXa_FALLOFF		"falloff2"
        // [export]  ILxFalloff	fall
        // [local]   ILxFalloff

        // [python] type LXtPointID	id
        // [python] type LXtPolygonID	id

/*
 * Falloff items all derive from a common type, a type of locator.
 * Being a locator type allows all falloffs to act as influences and to perform
 * direct deformations, even if a specific falloff type has no location. It also
 * allows the falloff to present a Tool interface, so it can be evaluated as a
 * falloff in a procedural modeling context.
 */

        #define LXsITYPE_FALLOFF		"falloff"

        #define LXsICHAN_FALLOFF_FALLOFF	"falloffObj"
        #define LXsICHAN_FALLOFF_DEFORMER	"deformerObj"
        #define LXsICHAN_FALLOFF_FALLENAB	"enableFalloff"
        #define LXsICHAN_FALLOFF_DEFORMENAB	"enableDeform"
        #define LXsICHAN_FALLOFF_STRENGTH	"strength"
        #define LXsICHAN_FALLOFF_INVERT		"invert"
        #define LXsICHAN_FALLOFF_TOOL		"toolObj"
        #define	LXsICHAN_FALLOFF_GRADIENT	"gradient"


        #define LXu_FALLOFF1		"B7D1DEF8-1F45-4924-B518-E2F2A76D0259"
        #define	LXa_FALLOFF1		"falloff1"


        #define LXfDEFORMATION_NONLINEAR	 0x01
        #define LXfDEFORMATION_RIGIDXFRM	 0x02
        #define LXfDEFORMATION_USESUBSET	 0x04

/*
 * A deformation is basically a warping of space. Given an input point location and
 * a weight value typically from 0 to 1, the deformation computes the offset of the
 * point. The offset must approach zero as the weight approaches zero.
 * 
 */

        #define LXu_DEFORMATION		"A4736B27-142A-46B2-AF7D-F5008051FCD6"
        // [export]  ILxDeformation deform
        // [local]   ILxDeformation
        // [default] ILxDeformation:Flags = 0


        #define LXu_DEFORMATION1	"F5705327-7382-47C5-8D7B-AF2CC18B3E8A"

/*
 * Deformation items indicate their deformation object channel through a server
 * tag on their package.
 */

        #define LXsPKG_DEFORMATION_CHANNEL	"deformation.channel"

/*
 * Item types provide a mesh influence through an object reference channel, the name
 * given by a server tag. An optional tag can also define default mesh influence flags.
 */

        #define LXsPKG_DEFORMER_CHANNEL		"deformer.channel"
        #define LXsPKG_DEFORMER_FLAGS		"deformer.flags"
        #define LXsPKG_DEFORMER_CREATECMD	"deformer.create"

/*
 * If defined, the flags string is a "+" character followed by a set of single letters.
 * - NO_WEIGHT
 * Given by 'W', this indicates that the mesh influence has no weights. All the points
 * are equally weighted at 100%.
 * - NO_OFFSET
 * Given by 'O', this indicates that the influence does not define it's own offsets.
 * Instead offsets need to be provided by a deformation.
 * 
 * - IS_FALLOFF
 * This is an internal flag which indicates that the mesh influence is derived from a
 * falloff plus locator deformation.
 * 
 * - IS_MESHOP
 * This is an internal flag which indicates that the mesh operation is performing a
 * procedural modeling operation.
 * 
 * - NULL_WEIGHT
 * Given by 'N', this flag indicates that the effector wishes to operate on 0-weighted
 * vertices.  By default, these points are skipped by general influences.
 * 
 * - USE_LINEAR
 * Linear weighting simply means that a given point's deformed offset can be scaled
 * by that point's weight rather than the weight being required to compute the offset.  In
 * these cases, a weight of 1.0 is always passed to the deformer, and the offset will be
 * scaled by the point's weight internally which can be a faster calculation.
 * 
 * - IS_STACK
 * This is an internal flag which indicates that the item is a meshop stack, and 
 * meshes are modified by the meshops and deformers linked to its input graph. 
 * 
 */

#define LXfDEFORMER_NO_WEIGHT		0x001
#define LXfDEFORMER_NO_OFFSET		0x002
#define LXfDEFORMER_USESUBSET		LXfDEFORMATION_USESUBSET // 0x04
#define LXfDEFORMER_REQ_WEIGHT		0x008
#define LXfDEFORMER_REQ_OFFSET		0x010
#define LXfDEFORMER_IS_FALLOFF		0x020
#define LXfDEFORMER_IS_MESHOP		0x040
#define LXfDEFORMER_NULL_WEIGHT		0x080
#define LXfDEFORMER_USE_LINEAR		0x100
#define LXfDEFORMER_IS_STACK		0x200

/*
 * 	Influences define weighted deformations over specific domains. Each influence does
 * two things -- it provides all the information necessary to perform the deformation,
 * and it allows deformations to be composed. Thus it may completely control the
 * deformation of the target domain, or it may be under the control of another influence
 * driving its weights.
 */

        #define LXu_DEFORMER		"505D1B5A-74FF-4642-B992-174859766EA3"
        // [export]  ILxDeformer dinf
        // [local]   ILxDeformer
        // [default] ILxDeformer:Weight = 1
        // [default] ILxDeformer:PartitionCount = 0


        #define LXu_DEFORMER1		"F029A563-A937-4DB2-992E-1592081F64CC"

/*
 * The modifier's Evaluate() method can return codes indicating the type of
 * changes that happened. IDENTICAL means no change at all and previous cached
 * results will be reused. NEWOFFSET means that offsets changed, but the set of
 * affected element and the weights are the same. NEWWEIGHT means that the set of
 * element is the same but the weights have changed. DIFFERENT (same as the
 * default 'OK') means that the set of elements may have changed.
 */

        #define LXeDEFORM_IDENTICAL	LXeEVAL_IDENTICAL
        #define LXeDEFORM_NEWOFFSET	LXxGOODCODE(LXeSYS_DEFORM,21)
        #define LXeDEFORM_NEWWEIGHT	LXxGOODCODE(LXeSYS_DEFORM,22)
        #define LXeDEFORM_DIFFERENT	LXeEVAL_DIFFERENT


        #define LXu_MESHINFLUENCE	"D70AA410-75BB-480E-90E2-17E2059EB40B"
        // [export]  ILxMeshInfluence minf
        // [local]   ILxMeshInfluence
        // [default] ILxMeshInfluence:MeshCount = 0
        // [default] ILxMeshInfluence:PartitionIndex = index
        // [python]  ILxMeshInfluence:MeshByIndex	obj Item


        #define LXu_ITEMINFLUENCE	"2141BD0B-DEFC-4A92-A4A5-30760C09F18B"
        // [export]  ILxItemInfluence iinf
        // [local]   ILxItemInfluence
        // [python]  ILxItemInfluence:GetItem	obj Item
        // [python]  ILxItemInfluence:HasItems	bool

        #define LXfITEMINF_POSITION	 0x01
        #define LXfITEMINF_ROTATION	 0x02
        #define LXfITEMINF_SCALE	 0x04
        #define LXfITEMINF_PROBEWEIGHTS	 0x08

/*
 * Deformer group items can be parents to other deformers in the deformTree
 * hierarchy. A deform group is itself a deformer that performs a composite
 * deformation of the child deformers.
 */

        #define LXsITYPE_DEFORMGROUP			"deformGroup"

        #define LXsICHAN_DEFORMGROUP_DEFORMER		"deformObj"
        #define LXsICHAN_DEFORMGROUP_ENABLE		"enable"
        #define LXsICHAN_DEFORMGROUP_INTERPOLATION	"interpolation"
        #define LXsICHAN_DEFORMGROUP_LIMITENABLE	"limitEnable"
        #define LXsICHAN_DEFORMGROUP_LIMITMAX		"limitMax"
        #define LXsICHAN_DEFORMGROUP_THRESHOLD		"threshold"
        #define LXsICHAN_DEFORMGROUP_SHARPNESS		"sharpness"

        #define LXsICVAL_DEFORMGROUP_INTERPOLATION_LOCAL	"local"
        #define LXsICVAL_DEFORMGROUP_INTERPOLATION_LINEAR	"linear"
        #define LXsICVAL_DEFORMGROUP_INTERPOLATION_DQS		"dqs"


        #define LXu_GROUPDEFORMER	"4BC04F3F-29FC-4EA3-B090-10280331C757"
        // [local]   ILxGroupDeformer
        // [python]  ILxGroupDeformer:DeformerByIndex	obj Item
        // [python]  ILxGroupDeformer:PointEffect:deformer	vector
        // [python]  ILxGroupDeformer:PointEffect:weight	vector

/*
 * A deformer folder is just a grouping construct. Deformers that are children of
 * a folder are still applied bottom to top at the location of the folder. The
 * enable state of the folder can disable all children as well.
 */

        #define LXsITYPE_DEFORMFOLDER		"deformFolder"

        #define LXsICHAN_DEFORMFOLDER_ENABLE	"enable"


        #define LXu_WEIGHTMAPDEFORMERITEM	"A9C81E0B-20F0-4D8B-838B-B593EAF3DFB8"
        // [export]  ILxWeightMapDeformerItem wmd
        // [local]   ILxWeightMapDeformerItem
        // [default] ILxWeightMapDeformerItem:GetColor = LXeDEFORM_AUTO_COLOR

        #define LXeDEFORM_AUTO_COLOR	LXxGOODCODE(LXeSYS_DEFORM, 12)

/*
 * The itemInfluence item type (really Item Deformer) serves as the container
 * influence object for deforming items.
 */

        #define LXsITYPE_ITEMINFLUENCE			"itemInfluence"

        #define LXsICHAN_ITEMINFLUENCE_ITEMINF		"itemInf"
        #define LXsICHAN_ITEMINFLUENCE_ENABLE		"enable"
        #define LXsICHAN_ITEMINFLUENCE_INTERPOLATION	"interpolation"
        #define LXsICHAN_ITEMINFLUENCE_POSENABLE	"posEnable"
        #define LXsICHAN_ITEMINFLUENCE_ROTENABLE	"rotEnable"
        #define LXsICHAN_ITEMINFLUENCE_SCLENABLE	"sclEnable"
        #define LXsICHAN_ITEMINFLUENCE_SAMPLEWEIGHT	"sampleWeight"

        #define LXsICVAL_ITEMINFLUENCE_INTERPOLATION_LOCAL	"local"
        #define LXsICVAL_ITEMINFLUENCE_INTERPOLATION_LINEAR	"linear"


        #define LXa_DEFORMERSERVICE	"deformerservice"
        #define LXu_DEFORMERSERVICE	"8267068C-FDBB-430A-8230-BE64F72CE3E3"
        // [python] ILxDeformerService:DeformerDeformationItem	obj item
        // [python] ILxDeformerService:GroupDeformer		obj GroupDeformer
        // [python] ILxDeformerService:MeshByIndex		obj Item (item)
        // [python] ILxDeformerService:StackTargetByIndex	obj Item (item)

#endif
