/*
 * LX pmodel module
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
#ifndef LX_pmodel_H
#define LX_pmodel_H

typedef struct vt_ILxMeshElementGroup ** ILxMeshElementGroupID;
typedef struct vt_ILxSelectionOperation ** ILxSelectionOperationID;
typedef struct vt_ILxSelectionOperation1 ** ILxSelectionOperation1ID;
typedef struct vt_ILxSelectionState ** ILxSelectionStateID;

#include <lxcom.h>
#include <lxmesh.h>
#include <lxserver.h>



/*
 * This method is expected to return the number of element groups.
 * 
 * This method should return the name of an element group by index.
 * 
 * This method should return the username of an element group by index. Ideally,
 * this would be a translatable entry in a message table.
 * 
 * This method returns either LXe_TRUE or LXe_FALSE, indicating whether or not the
 * given point exists in the group. The group to test is given by index.
 * 
 * This method returns either LXe_TRUE or LXe_FALSE, indicating whether or not the
 * given edge exists in the group. The group to test is given by index.
 * 
 * This method returns either LXe_TRUE or LXe_FALSE, indicating whether or not the
 * given polygon exists in the group. The group to test is given by index.
 */
typedef struct vt_ILxMeshElementGroup {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
GroupCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD( LxResult,
GroupName) (
        LXtObjectID		  self,
        unsigned int		  index,
        const char		**name);
        LXxMETHOD( LxResult,
GroupUserName) (
        LXtObjectID		  self,
        unsigned int		  index,
        const char		**username);
        LXxMETHOD( LxResult,
TestPoint) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtPointID		 point);
        LXxMETHOD( LxResult,
TestEdge) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtEdgeID		 edge);
        LXxMETHOD( LxResult,
TestPolygon) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtPolygonID		 polygon);
} ILxMeshElementGroup;

/*
 * This function is called before any elements are tested, to set the mesh that the
 * elements belong to.
 * 
 * This function is called before any elements are tested. It provides the transform
 * matrix for the mesh being tested. It can then be used for transforming any component
 * position tests into world space.
 * 
 * This method returns either LXe_TRUE or LXe_FALSE, indicating whether or not the given
 * point should be included in the selection.
 * 
 * This method returns either LXe_TRUE or LXe_FALSE, indicating whether or not the given
 * edge should be included in the selection.
 * 
 * This method returns either LXe_TRUE or LXe_FALSE, indicating whether or not the given
 * polygon should be included in the selection.
 * 
 * This function is called at the start of selection evaluation. It can be used to
 * modify a previous selection, or initialize any state needed to evaluate individual
 * elements. The function is called with the selection type that is being evaluated,
 * as well as a ILxSelectionState object. The ILxSelectionState object allows
 * individual elements to be tested for selection, and elements to be added or removed
 * from the selection.
 * If this function returns LXe_TRUE, the selection operation has finished modifying
 * the selection, and then TestPoint, TestEdge and TestPolygon functions will not be
 * called, whereas if the function returns LXe_FALSE, the various test functions will
 * be called.
 */
typedef struct vt_ILxSelectionOperation {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetMesh) (
        LXtObjectID		 self,
        LXtObjectID		 mesh);
        LXxMETHOD( LxResult,
SetTransform) (
        LXtObjectID		 self,
        LXtMatrix4		 xfrm);
        LXxMETHOD( LxResult,
TestPoint) (
        LXtObjectID		 self,
        LXtPointID		 point);
        LXxMETHOD( LxResult,
TestEdge) (
        LXtObjectID		 self,
        LXtEdgeID		 edge);
        LXxMETHOD( LxResult,
TestPolygon) (
        LXtObjectID		 self,
        LXtPolygonID		 polygon);
        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtID4			 type,
        LXtObjectID		 state);
} ILxSelectionOperation;

typedef struct vt_ILxSelectionOperation1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetMesh) (
        LXtObjectID		 self,
        LXtObjectID		 mesh);

        LXxMETHOD( LxResult,
SetTransform) (
        LXtObjectID		 self,
        LXtMatrix4		 xfrm);

        LXxMETHOD( LxResult,
TestPoint) (
        LXtObjectID		 self,
        LXtPointID		 point);

        LXxMETHOD( LxResult,
TestEdge) (
        LXtObjectID		 self,
        LXtEdgeID		 edge);

        LXxMETHOD( LxResult,
TestPolygon) (
        LXtObjectID		 self,
        LXtPolygonID		 polygon);
} ILxSelectionOperation1;

/*
 * This method returns either LXe_TRUE or LXe_FALSE, indicating whether or not the given
 * point is selected.
 * 
 * This method returns either LXe_TRUE or LXe_FALSE, indicating whether or not the given
 * edge is selected.
 * 
 * This method returns either LXe_TRUE or LXe_FALSE, indicating whether or not the given
 * polygon is selected.
 * 
 * This method is used to set a point as selected. The function should be passed either
 * LXe_TRUE or LXe_FALSE to specify the selection state.
 * 
 * This method is used to set an edge as selected. The function should be passed either
 * LXe_TRUE or LXe_FALSE to specify the selection state.
 * 
 * This method is used to set a polygon as selected. The function should be passed either
 * LXe_TRUE or LXe_FALSE to specify the selection state.
 */
typedef struct vt_ILxSelectionState {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
TestPoint) (
        LXtObjectID		 self,
        LXtPointID		 point);
        LXxMETHOD( LxResult,
TestEdge) (
        LXtObjectID		 self,
        LXtEdgeID		 edge);
        LXxMETHOD( LxResult,
TestPolygon) (
        LXtObjectID		 self,
        LXtPolygonID		 polygon);
        LXxMETHOD( LxResult,
SetPoint) (
        LXtObjectID		 self,
        LXtPointID		 point,
        LxResult		 state);
        LXxMETHOD( LxResult,
SetEdge) (
        LXtObjectID		 self,
        LXtEdgeID		 edge,
        LxResult		 state);
        LXxMETHOD( LxResult,
SetPolygon) (
        LXtObjectID		 self,
        LXtPolygonID		 polygon,
        LxResult		 state);
} ILxSelectionState;

/*
 * The procedural modeling system works by evaluating a series of mesh operations, on a
 * target mesh, to result in a final modified mesh. To integrate a mesh operation interface
 * into the procedural modeling system, the mesh operations need to be associated with an
 * item, that can be managed by the user. The mesh operation item performs this duty. It
 * contains a MeshOpObj channel which stores the mesh operation, and is evaluated by the
 * procedural modeling system, to perform an edit to the mesh.
 * Mesh Operation items all derive from a common type. This type is extremely basic and
 * has no transforms or position in 3D space. There are four default channels on every
 * Mesh Operation Item, defining things like selection type and the enable state.
 */

        #define LXsITYPE_MESHOP			"meshoperation"
        #define	LXsICHAN_MESHOP_ENABLE		"enable"
        #define	LXsICHAN_MESHOP_OBJ		"meshOpObj"
        #define	LXsICHAN_MESHOP_SELTYPE		"selectionType"
        #define LXsICHAN_MESHOP_USEXFRM		"useWorldXfrm"

/*
 * The custom creation command allows a custom command to be fired to handle the creation
 * of the mesh operation item. This is useful if additional setup is required, that is
 * unique to a specific mesh operation item.
 */

        #define	LXsPKG_MESHOP_CREATECMD		"meshop.create"

/*
 * Adding this tag to a mesh operation, selection operation or tool operation items
 * specifies that the item does not require the transform of the mesh being modified.
 * This can improve performance in certain cases, as the operation will not be
 * reevaluated when the mesh transform changes. The tag can have any value.
 */

        #define	LXsPMODEL_NOTRANSFORM		"pmodel.noXfrm"

/*
 * The steps to manually implement a Mesh Operation item can be quite complex. Because
 * of this, a simpler method is provided, allowing ILxMeshOperation interfaces to be
 * automatically converted into Mesh Operation items. This is only useful for simple
 * mesh operations, that simply take a mesh, modify it and return a modified mesh, using
 * nothing more than a few simple attributes.
 * Applying the following server tag to an ILxMeshOperation interface, will automatically
 * create a mesh operation item and a modifier, writing the mesh operation server into a
 * channel, so that it can be evaluated as part of the procedural system. The Mesh
 * Operation server being converted, should also implement an Attributes interface. The
 * attributes will be automatically converted into channels on the newly created item.
 * The value of this tag doesn't matter, as the presence of the server tag is enough to
 * automatically create a mesh operation item.
 */

        #define LXsMESHOP_PMODEL		"pmodel.meshop"

/*
 * Tool Operation items all derive from a common type, which it itself a sub-type of the
 * Mesh Operation item type.
 */

        #define LXsITYPE_TOOLOP			"tooloperation"

/*
 * The "tool" graph is automatically added to any tool operation item that performs an
 * "actor" task. It is used to connect non-actor tools into the actor tool to create a
 * mini-toolpipe. This mini tool pipe is evaluated, allowing the behavior of an actor
 * tool to be modified.
 */

        #define	LXsGRAPH_TOOL			"tool"

/*
 * There are a number of similarities between procedural mesh operations and traditional
 * tools that operate on meshes. Rather than implementing a tool for one context and a
 * mesh operation for another context, it is often desirable to implement functionality
 * once and use in both contexts. As we have a large library of existing tools, converting
 * a tool to work with the procedural modeling system needs to be quick and painless.
 * Adding the following server tag to an ILxTool server, will automatically convert the
 * tool into a Tool Operation Item, that can be integrated directly into the procedural
 * modeling system. The value of this tag doesn't matter, as the presence of the server
 * tag is enough to convert the tool to work with the procedural modeling system.
 */

        #define LXsTOOL_PMODEL			"pmodel.toolop"

/*
 * Whilst the addition of the server tag makes it simple to convert an existing tool to
 * work with the procedural modeling system, more work is often needed to the tool itself,
 * to ensure it works correctly in an evaluated context. The tool should implement a
 * GetOp function that spawns and returns a Tool Operation interface.
 * Some considerations also need to be made to the evaluation of the tool operation. The
 * general rule is that when evaluated procedurally, a tool should not rely on any global
 * state, or values that aren't provided by either tool attributes or tool packets. It
 * should not attempt any operation that requires an undo context or attempt to execute
 * commands. With some thought and design, it should be possible to convert most tools
 * that operate on meshes, to work in a procedural context, without altering the
 * functionality of the tool itself.
 * On automatically generated tool operation items, the tool object will be stored in the
 * following channel.
 * 
 */

        #define	LXsICHAN_TOOL_OBJ		"toolObj"

/*
 * Whilst it's often desirable to automatically generate a Tool Operation item from an
 * existing tool, it is also possible to manually implement Tool Operation items that can
 * be integrated into the procedural system. This is useful for writing tool operation
 * items that provide more complexity than is usually supported through the tool system.
 * To create a Tool Operation Item from scratch. A package should be created, with a
 * SuperType of LXsITYPE_TOOLOP. This will provide it with the standard set of channels,
 * common to all Tool Operation items.
 * A Modifier, associated with the Tool Operation Item, should read any channels it
 * requires to evaluate the tool. It should spawn an ILxTool interface and write it into
 * a channel on the package of the type LXsTYPE_OBJREF. The channel name used for storing
 * the tool, should be defined on the server tags using the following tag.
 * 
 */

        #define LXsPKG_TOOL_CHANNEL		"tool.channel"

/*
 * Two other server tags should also be added to the package. One defines the task of the
 * tool, and should be of the type LXs_TASK. The other defines the order of evaluation
 * and should be one of the LXs_ORDPKG_ defines here. In the majority of cases, the TASK value 
 * should match what is returned by the tool, and the ORD value should be equivalent to the LXs_ORD
 * value returned by the tool.
 */

        #define LXsPKG_TOOL_TASK		"tool.task"
        #define LXsPKG_TOOL_ORDER		"tool.order"
        
        #define LXs_ORDPKG_WORK			"workplane"
        #define LXs_ORDPKG_SYMM			"symmetry"
        #define LXs_ORDPKG_CONT			"content"
        #define LXs_ORDPKG_STYL			"stylus"
        #define LXs_ORDPKG_SNAP			"snap"
        #define LXs_ORDPKG_CONS			"constraint"
        #define LXs_ORDPKG_ACEN			"actCenter"
        #define LXs_ORDPKG_AXIS			"actAxis"
        #define LXs_ORDPKG_PATH			"path"
        #define LXs_ORDPKG_WGHT			"weight"
        #define LXs_ORDPKG_PINK			"imgInk"
        #define LXs_ORDPKG_NOZL			"nozzle"
        #define LXs_ORDPKG_BRSH			"brush"
        #define LXs_ORDPKG_PTCL			"particle"
        #define LXs_ORDPKG_SIDE			"side"
        #define LXs_ORDPKG_EFFR			"effector"
        #define LXs_ORDPKG_ACTR			"actor"
        #define LXs_ORDPKG_POST			"post"

/*
 * Mesh Operations and Tool Operations can optionally implement an ILxMeshElementGroup
 * interface. This interface is used to get named groups of elements that have been
 * modified, or created by the procedural operation. These can then be used to define
 * new selections later in the stack, allowing the user to easily access elements from
 * an earlier operation.
 * The returned groups should have a descriptive name that is easily understandable
 * to the user, and is clear how it relates to the operation. For example, a curve
 * extrude operation may return two groups; one named "End Caps" and another named
 * "Sides".
 */

        #define	LXu_MESHELEMENTGROUP		"4773EA40-C2D6-4B55-800C-59FF6E9730B7"
        #define LXa_MESHELEMENTGROUP		"meshelementgroup"
        // [local] ILxMeshElementGroup
        // [export] ILxMeshElementGroup			eltgrp
        // [python] ILxMeshElementGroup:TestPoint	bool
        // [python] ILxMeshElementGroup:TestEdge	bool
        // [python] ILxMeshElementGroup:TestPolygon	bool

        // [python] type LXtPointID			id
        // [python] type LXtEdgeID			id
        // [python] type LXtPolygonID			id

/*
 * The selection operation item provides a selection to the procedural system. It
 * encapsulates channels that can be evaluated to determine the current selection
 * state. This item will be evaluated prior to a procedural edit to determine which
 * elements should be operated on.
 * Selection Operation items all derive from a common type. This type is extremely
 * basic and has no transforms or position in 3D space. The default channels define
 * enable state, the output channel to which the ILxSelectionOperationID is written,
 * whether the selection operation should be inverted, and the blend mode used to
 * blend multiple selection operations together.
 */

        #define	LXsGRAPH_SELOP			"selop"


        #define LXsITYPE_SELOP			"selectionoperation"

        #define	LXsICHAN_SELOP_ENABLE		"enable"
        #define	LXsICHAN_SELOP_OBJ		"selopobj"
        #define LXsICHAN_SELOP_INVERT		"invert"
        #define LXsICHAN_SELOP_BLENDMODE	"blendmode"

/*
 * When multiple selection operations are connected to a mesh operation, they can be
 * blended together to create complex selections. This is similar to the concept of
 * shading, where multiple texture layers can be blended together to create a final
 * texture. The following blending modes are available:
 * - OVERRIDE
 * This blending mode (default) will override all selection operations below it in the
 * stack. Any previous selection will be discarded, and the new selection will be used
 * instead.
 * 
 * - ADD
 * This blending mode will add the new selection to the previous selection. Elements
 * will only be treated as deselected if they are deselected by all selection
 * operations in the stack.
 * 
 * - SUBTRACT
 * This blending mode will remove any elements that are selected by the selection
 * operation from the previous selection. Deselected elements will be ignored.
 * 
 * - MULTIPLY
 * This blending mode will only select elements from the second selection operation
 * that are selected by the first, essentially filtering the previous selection.
 * 
 */

        #define LXiSELOP_BLEND_OVERRIDE		 0
        #define LXiSELOP_BLEND_ADD		 1
        #define LXiSELOP_BLEND_SUBTRACT		 2
        #define LXiSELOP_BLEND_MULTIPLY		 3

/*
 * Selection Operations should specify the types of selection they support. Mesh Operation
 * and Tool Operation items should also specify the type of selections they require. This
 * combination of selection types on both the selection operation and the mesh operation,
 * helps determine which selection operations can be used with which mesh operations.
 * Supported selection types are defined using the following server tag. The server is
 * expected to provide a comma seperated list of selection types. The server can also
 * specify that no selection is required by returning the NONE value. If no tag is
 * provided, it will be assumed that all types are supported.
 * 
 */

        #define LXsPMODEL_SELECTIONTYPES	"selectionoperation"

/*
 * The server tag must have one of the following values. Any other value will be
 * treated as supporting all selection types.
 */

        #define	LXsSELOP_TYPE_NONE		"-"
        #define	LXsSELOP_TYPE_VERTEX		"VERX"
        #define	LXsSELOP_TYPE_EDGE		"EDGE"
        #define	LXsSELOP_TYPE_POLYGON		"POLY"

/*
 * The steps to manually implement a Selection Operation item can be quite complex.
 * Because of this, a simpler method is provided, allowing ILxSelectionOperation
 * interfaces to be automatically converted into Selection Operation items. This is
 * only useful for simple selection operations, that can test the selection status
 * of an element without any complex channel input->
 * Applying the following server tag to an ILxSelectionOperation interface, will
 * automatically create a selection operation item and a modifier, writing the
 * Selection operation server into a channel, so that it can be queried as part of
 * the procedural system. The Selection Operation server being converted, should
 * also implement an Attributes interface. The attributes will be automatically
 * converted into channels on the newly created item. The value of this tag doesn't
 * matter, as the presence of the server tag is enough to automatically create a
 * selection operation item.
 */

        #define LXsSELOP_PMODEL			"pmodel.selectionop"

/*
 * This interface allows the procedural modeling system to test the selection status
 * of a given element, allowing it to mark it for use during mesh operation evaluation.
 */

        #define	LXu_SELECTIONOPERATION		"AA86E146-36F1-44C3-B170-0107F600941D"
        #define LXa_SELECTIONOPERATION		"selectionoperation2"
        // [local] ILxSelectionOperation
        // [export] ILxSelectionOperation		selop
        // [python] ILxSelectionOperation:TestPoint	bool
        // [python] ILxSelectionOperation:TestEdge	bool
        // [python] ILxSelectionOperation:TestPolygon	bool

/*
 * This selection operation interface was deprecated in 10.2v1.
 */

        #define	LXu_SELECTIONOPERATION1		"563E56B1-ACC9-4E3F-B3A8-E0AFE2AB5645"
        #define LXa_SELECTIONOPERATION1		"selectionoperation"

/*
 * This interface caches the procedural selection state. It can be used by selection
 * operations to query the selection state, and well as modify the selection state.
 */

        #define	LXu_SELECTIONSTATE		"D1F068A3-5DFC-4587-AD63-FE1D4D0501ED"
        #define LXa_SELECTIONSTATE		"selectionstate"
        // [local] ILxSelectionState
        // [python] ILxSelectionState:TestPoint		bool
        // [python] ILxSelectionState:TestEdge		bool
        // [python] ILxSelectionState:TestPolygon	bool

#endif
