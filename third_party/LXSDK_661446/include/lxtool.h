/*
 * LX tool module
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
#ifndef LX_tool_H
#define LX_tool_H

typedef struct vt_ILxTool ** ILxToolID;
typedef struct vt_ILxTool1 ** ILxTool1ID;
typedef struct vt_ILxAttrSequence ** ILxAttrSequenceID;
typedef struct vt_ILxToolOperation ** ILxToolOperationID;
typedef struct vt_ILxToolOperation1 ** ILxToolOperation1ID;
typedef struct vt_ILxFalloffPacket ** ILxFalloffPacketID;
typedef struct vt_ILxFalloffPacket1 ** ILxFalloffPacket1ID;
typedef struct vt_ILxSymmetryPacket ** ILxSymmetryPacketID;
typedef struct vt_ILxSubject2Packet ** ILxSubject2PacketID;
typedef struct vt_ILxTexturePacket ** ILxTexturePacketID;
typedef struct vt_ILxElementAxisPacket ** ILxElementAxisPacketID;
typedef struct vt_ILxElementCenterPacket ** ILxElementCenterPacketID;
typedef struct vt_ILxPathGeneratorPacket ** ILxPathGeneratorPacketID;
typedef struct vt_ILxBagGenerator ** ILxBagGeneratorID;
typedef struct vt_ILxPathStep ** ILxPathStepID;
typedef struct vt_ILxParticleGeneratorPacket ** ILxParticleGeneratorPacketID;
typedef struct vt_ILxParticleGeneratorPacket1 ** ILxParticleGeneratorPacket1ID;

#include <lxcom.h>
#include <lxvalue.h>
#include <lxvector.h>
#include <lxmesh.h>
#include <lxpmodel.h>


/*
 * The subject packet as a mesh, a vmap and the selection type to operate on.
 */
typedef struct st_LXpToolSubject {
        LXtMeshID		 mesh;
        LXtMeshMapID		 vmap;
        LXtID4			 type;
        LXtMeshID		 base;
} LXpToolSubject;

/*
 * The action center will be mostly used by transform tools like scale and rotate.
 * The packet is set by action center tools, like the mouse (Auto) action center tool
 * which converts the 2D position into a 3D position.
 */
typedef struct st_LXpToolActionCenter {
        LXtVector		 v;
} LXpToolActionCenter;

/*
 * This packet is set by axis tools, like the Auto-Axis tool which sets the axis
 * using a principal axis chosen by the event translation object.  The axis is a
 * unit vector which will often be along a principal axis.  In this case, the
 * 'axIndex' will have the index for that axis.  Otherwise, axIndex will be -1.
 * The axIndex should be treated as a hint, so a tool setting this packet should
 * assure that a correct axis vector is set even if a principal axis is selected
 * and the index is set.  A tool reading this packet should be prepared to use the
 * axis vector, since the index may be set to -1 even though the vector happens to
 * lie along a principal direction.  The axis vector is also the 'forward' vector.
 * The 'up' vector is a unit vector perpendicular to the axis, which is nominally
 * in the 'up' direction.  The 'right' vector is the last vector to form the basis.
 * The 'm' matrix is the matrix formed by the 3 basis vectors and 'mInv' is its
 * inverse.
 */
typedef struct st_LXpToolAxis {
        LXtVector		 axis;
        LXtVector		 up;
        LXtVector		 right;
        LXtMatrix		 m, mInv;
        int 			 axIndex;
        int			 type;
} LXpToolAxis;

/*
 * Tools may be transformed by other tools.  For instance, a construction plane
 * tool will apply the plane's transformation to the following tools in the pipe.
 * The construction plane tool can do that by setting the Xfrm packet matrix and
 * position vector.  Tools which set this packet may provide an inverse transform
 * matrix, to save redundant or more difficult inversions downstream.
 */
typedef struct st_LXpToolXfrm {
        LXtVector		 v;
        LXtMatrix		 m;
        LXtMatrix		 mInv;
        int			 flags;
        int			 handedness;
        unsigned int		 marks;
} LXpToolXfrm;

/*
 * Most paths are defined by a series of control points (knots). These knots are
 * characterized by a position, a parameter value on the path, some tangents, and flags
 * which tell, among other things, wether the tangents are continuous. It is expected
 * that all discontinuities in a path are represented by knots.
 */
typedef struct st_LXtPathKnot {
        LXtFVector		 position;
        LXtFVector		 tanIn;
        LXtFVector		 tanOut;
        int			 flags;
        void			*clientData;
        double			 bank;
} LXtPathKnot;

/*
 * A particle generator object manages an ordered sequence of particles, or
 * transforms, each defined by its own position, rotation and scale.  While the
 * scale and orientation could be combined in a single matrix, they will be
 * preserved separately for the convenience of working with orthonormal matrices.
 * A
 */
typedef struct st_LXtPGenParticle {
        LXtFVector		 position;
        LXtFVector		 scale;
        LXtMatrix		 orientation;
        int			 flags;
} LXtPGenParticle;

/*
 * The Preset Content Packet holds the name, type and commonly used attributes for content preset files.
 * It should be written to be TASK_CONT type tools, and read-only for tools downstream. The
 * flags are used for boolean attributes, and may be interpreted differently for each type of content.
 */
typedef struct st_LXpToolContent {
        const char		*path;
        const char		*type;
        double			 scale;
        LXtVector		 axis;
        LXtVector		 offset;
        int 			 axIndex;
        int			 flags;
        void			*data;

         // Temporary changes to ensure the content browser works correctly when running as a toolop.
         // We cannot store pointers to strings owned by toolops in the same way we would for non-procedural tools.
         // because the toolop data is not guaranteed to still exist when the packet is read by the next tool.
         // We should replace this structure with a COM object as soon as possible.

        char			 pathBuffer[1024];
        char			 typeBuffer[64];
} LXpToolContent;

/*
 * This packet holds common style attributes for vector composition elements.
 */
typedef struct st_LXpToolStyle {
        float			 lineWidth;
        LXtFVector		 lineColor;
        float			 lineAlpha;
        int			 lineDashType;
        unsigned                 lineDashPattern;
        int 			 lineFlags;
        int 			 lineCap;
        int			 lineJoin;
        float			 lineMiterLimit;

        LXtFVector		 fillColor;
        float			 fillAlpha;
        float			 fillHeight;
        const char		*fillType;
        const char		*fillParams;
        int 			 fillFlags;
} LXpToolStyle;


/*
 * The basic interface for tools is ILxTool.  This has a set of methods that
 * manage the state of the tool, and query the fundamental tool properties.
 * - Reset
 * The Reset method sets the tool attributes back to their initial/default state.
 * 
 * - Evaluate
 * This method applys the tool, recursively applying any hierarchy of
 * sub-tools.  Naturally, it validates the tool state upon completion.
 * 
 * - VectorType
 * This method returns the tool vector type, describing the vector packets
 * required for processing.
 * 
 * - Order
 * Specifies the order in the pipe, by returning an Ordinal string.
 * 
 * - Task
 * Specifies the type of task performed by the tool.
 * 
 * - Sequence
 * This method uses the attribute sequence object given to store the tool's
 * complete state by generating the sequence of attribute changes needed to
 * reproduce that exact state.  A tool whose state is expressed entirely by its
 * attributes may return LXe_NOTIMPL from this method, and let the system build
 * the sequence directly from the attribute list.
 * 
 * 
 * - ShouldBeAttribute
 * To help overcome the excessive factorization of tools into separated tasks, which
 * confounds user expectations and prevents toolpipe elements from working closely together,
 * This method allows a tool to specify which other tool task types should be considered more like
 * tool attributes, so that changing the tool doesn't 'break' the Tool Preset, but instead,
 * overwrites it with the new pipe contents. This allows paint tool presets to remember their brushes
 * almost as well as as they would have if the brush was an attribute of the tool, rather than a
 * separate element. Users who don't don't want their presets automatically destroyed can simply manually
 * rebuild the preset when they need it. While this complicates and undermines the integrity of toolpresets,
 * it also adds mysterious complexity to the toolpipe for users, who will see some presets break when
 * their tool list changes, and others merely accept the changes and destroy the original preset without
 * comment or warning. Numerous other incompletely anticipated consequences are also bound to arise from this
 * new mode of crosstalk between tools and their pipelines. Maybe some of them will not be bugs.
 * The ShouldBeAttribute method returns flags to indicate whether the given task type should be accepted into
 * a preset as a replacement without considering the preset to be different, or whether it should behave
 * in accordance with reason and the system design.
 * 
 * 
 * It is often desirable to perform incremental updates to meshes, rather than simply
 * evaluating a tool from scratch, every time an attribute changes. This is performed
 * using a tool operation. A tool operation is spawned for every mesh the tool is expected
 * to edit, and is used to perform an initial edit to the mesh. When a tool attribute
 * changes, the tool operation is compared against the current state of the tool. If the
 * tool operation is still valid, it will be updated to use the new tool attributes and
 * re-evaluated to perform an incremental update to the previous evaluation.
 * 
 * Tool Operations also are used in a procedural context. When a tool has been auto
 * converted into a procedural tool item, it's tool operation is evaluated as part of
 * the procedural modeling system to perform initial and incremental edits to a procedural
 * mesh.
 * 
 * This set of functions is used to get the tool op, compare it against tool state and
 * update the tool operation if the tool state is still valid.
 * 
 * - GetOp
 * The GetOp method is used to spawn a Tool Operation interface that can be used for
 * evaluation and re-evaluation of a mesh edit. The tool is expected to spawn and return
 * a new tool operation every time this function is called. The tool should store any
 * user data in the tool operation before returning. The flags argument is used to pass
 * various flags that specify the context in which the tool is being evaluated; as part
 * of the tool pipe, or procedurally. In future, more flags may be supported.
 * 
 * 
 * 
 * - UpdateOp
 * If the CompareOp function specifies that a previous tool operation is compatible with
 * the current state of the tool, then this function will be called to copy updated
 * attributes and user data from the tool, to the previous tool operation. The tool
 * operation will then be re-evaluated using this updated data.
 */
typedef struct vt_ILxTool {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Reset) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( LXtObjectID,
VectorType) (
        LXtObjectID		 self);

        LXxMETHOD( const char *,
Order) (
        LXtObjectID		 self);

        LXxMETHOD( LXtID4,
Task) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Sequence) (
        LXtObjectID		 self,
        LXtObjectID		 seq);
        LXxMETHOD( int,
ShouldBeAttribute) (
        LXtObjectID		 self,
        LXtID4			 task);
        LXxMETHOD( LxResult,
GetOp) (
        LXtObjectID		  self,
        void			**ppvObj,
        unsigned		  flags);
        LXxMETHOD( unsigned,
CompareOp) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 toolop);
        LXxMETHOD( LxResult,
UpdateOp) (
        LXtObjectID		 self,
        LXtObjectID		 toolop);
} ILxTool;

/*
 * This interface was retired in modo 901, and was replaced with an updated one
 * that adds a few more methods.
 */
typedef struct vt_ILxTool1 {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
Reset) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( LXtObjectID,
VectorType) (
        LXtObjectID		 self);

        LXxMETHOD( const char *,
Order) (
        LXtObjectID		 self);

        LXxMETHOD( LXtID4,
Task) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Sequence) (
        LXtObjectID		 self,
        LXtObjectID		 seq);

        LXxMETHOD( int,
ShouldBeAttribute) (
        LXtObjectID		 self,
        LXtID4			 task);
} ILxTool1;

/*
 * The ILxAttrSequence interface is intended to complement attribute lists by
 * capturing the sequence of attribute edits required to create a specific state
 * within an object which implements the ILxAttributes interface.  An attribute
 * list is a minimal snapshot of an object's exposed data, which may not fully
 * describe the internal state of the object.  This would be the case if attribute
 * changes had a cumulative effect on the object (e.g. adding elements to a list).
 * Preserving this state is accomplished by using the ILxAttrSequence interface to
 * 'record' the necessary attribute changes for some host, which can then
 * regenerate the object state by 'playing back' the edits.
 * - Integer
 * Use this method to record a change to an integer type attribute by specifying
 * the attribute name and the new value.
 * - Float
 * Use this method to record a change to an floating point attribute (a double).
 * 
 * - String
 * Use this method to record a change to an string attribute.
 * 
 * - Value
 * Use this method to record a change to an attribute using a generic ILxValue.
 * 
 * - HaulingOverride
 * Use this method to record a change to an attribute hauling override selection.
 * 
 */
typedef struct vt_ILxAttrSequence {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Integer) (
        LXtObjectID		 self,
        const char		*name,
        int			 value);

        LXxMETHOD( LxResult,
Float) (
        LXtObjectID		 self,
        const char		*name,
        double			 value);

        LXxMETHOD( LxResult,
String) (
        LXtObjectID		 self,
        const char		*name,
        const char		*value);

        LXxMETHOD( LxResult,
Value) (
        LXtObjectID		 self,
        const char		*name,
        LXtObjectID		 value);

        LXxMETHOD( LxResult,
HaulingOverride) (
        LXtObjectID 	 xobj,
        const char 		*name,
        const char 		*value);

} ILxAttrSequence;

/*
 * A Tool Operation is a special interface that allows tools to be incrementally evaluated.
 * The tool spawns and returns a Tool Operation interface. This tool operation interface
 * is then used for evaluation and re-evaluation of the tool.
 * - Evaluate
 * Once a tool has spawned a tool operation, this function will be called to perform an
 * initial evaluation.
 * 
 * 
 * - ReEvaluate
 * Subsequent evaluations of the tool operation will be performed using the ReEvaluate
 * function. The tool will test the tool operation to see if it is still compatible. If
 * it is, it's state will be updated and then ReEvaluate will be called to perform an
 * incremental update.
 * 
 * - Blend
 * The Blend function is used to map elements generated by one actor tool operation to
 * elements generated by another. A second tool operation is provided with alternate
 * settings, along with an ILxToolOperation object, which can be used for marking two
 * corresponding elements as equivalent.
 */
typedef struct vt_ILxToolOperation {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
        LXxMETHOD( LxResult,
ReEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
        LXxMETHOD( LxResult,
Blend) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        LXtObjectID		 blend);
} ILxToolOperation;

typedef struct vt_ILxToolOperation1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD( LxResult,
ReEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
} ILxToolOperation1;

/*
 * The falloff packet is set by falloff tools.  It is a COM object with the
 * ILxToolFalloff interface.
 */
typedef struct vt_ILxFalloffPacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  double,
Evaluate) (
        LXtObjectID		 self,
        LXtFVector		 pos,
        LXtPointID		 vrx,
        LXtPolygonID		 poly);

        LXxMETHOD(  double,
Screen) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        int			 x,
        int			 y);
} ILxFalloffPacket;

typedef struct vt_ILxFalloffPacket1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  double,
Evaluate) (
        LXtObjectID		 self,
        LXtFVector		 pos,
        LXtPointID		 vrx);

        LXxMETHOD(  double,
Screen) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        int			 x,
        int			 y);
} ILxFalloffPacket1;

/*
 * The symmetry packet provides interfaces to tools about the state of the
 * symmetry.
 * - Active
 * This function returns the activity of the symmetry.
 * - Axis
 * This function fills the axis vector of the symmetry and the offset value, and
 * it returns the axis number (0-2) for XYZ, otherwise 3 for arbitrary axis.
 * - Point
 * This function returns the symmetric vertex for the given vertex.  If there is
 * none, null is returned.
 * - Polygon
 * This function returns the symmetric polygon for the given polygon.  If there is
 * none, null is returned.
 * 
 * - Edge
 * This function returns the symmetric edge for the given edge.  If there is none,
 * null is returned.
 * 
 * - Position
 * This function takes any position and fills the symmetric position.  If the
 * position is on the symmetric plane, it returns zero, otherwise nonzero.
 * 
 * 
 */
typedef struct vt_ILxSymmetryPacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
Active) (
        LXtObjectID		 self);

        LXxMETHOD(  int,
Axis) (
        LXtObjectID		 self,
        LXtFVector		 axvec,
        float			*offset);

        LXxMETHOD(  LXtPointID,
Point) (
        LXtObjectID		 self,
        LXtMeshID		 mesh,
        LXtPointID		 vrx);

        LXxMETHOD(  LXtPolygonID,
Polygon) (
        LXtObjectID		 self,
        LXtMeshID		 mesh,
        LXtPolygonID		 pol);

        LXxMETHOD(  LXtEdgeID,
Edge) (
        LXtObjectID		 self,
        LXtMeshID		 mesh,
        LXtEdgeID		 edge);

        LXxMETHOD(  int,
Position) (
        LXtObjectID		 self,
        const LXtFVector	 pos,
        LXtFVector		 sv);

        LXxMETHOD(  int,
BaseSide) (
        LXtObjectID		 self);

        LXxMETHOD(  void,
SetBase) (
        LXtObjectID		 self,
        const LXtFVector	 pos);

        LXxMETHOD(  int,
TestSide) (
        LXtObjectID		 self,
        const LXtFVector	 pos,
        int			 useBase);
} ILxSymmetryPacket;

/*
 * The subject packet provides a wrapper around the layer service, allowing a layer scan
 * object to be allocated for accessing geometry.
 * - ScanAllocate
 * This function allocates a layer scan object, which can be used for accessing and
 * enumerating meshes in the scene. The flags passed to the flag argument should be the
 * same as the flags passed to the ScanAllocate function in the Layer Service.
 * - Type
 * This function returns the current selection type.
 * 
 */
typedef struct vt_ILxSubject2Packet {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScanAllocate) (
        LXtObjectID		  self,
        unsigned		  flags,
        void			**ppvObj);
        LXxMETHOD(  LXtID4,
Type) (
        LXtObjectID		  self);
} ILxSubject2Packet;

/*
 * The texture packet is similar to the falloff packet.  It does essentially the
 * same thing which is to compute a value given a 3D position/mesh elemement.  The
 * difference with the falloff packet is that the texture packet may compute
 * different  data types: scalar, color or vectors, unlike the falloff function
 * which only returns scalar values.
 */
typedef struct vt_ILxTexturePacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtFVector		 pos,
        LXtPointID		 vrx,
        LXtPolygonID		 pol,
        int			 context,
        double			*res);
} ILxTexturePacket;

/*
 * Elements are groups of vertices (or polygons) linked by virtue of their
 * interconnections.  The element axis packet has one method to compute the local
 * axis given the mesh and one vertex in the element.  For faster updates, the
 * method also precomputes the direct and inverse transformation matrices.
 */
typedef struct vt_ILxElementAxisPacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Axis) (
        LXtObjectID		 self,
        LXtPointID		 vrx,
        LXtFVector		 axis,
        LXtMatrix		 m,
        LXtMatrix		 mInv);
} ILxElementAxisPacket;

/*
 * Likewise, the element center packet compute the element center given the mesh
 * and a vertex in the element.
 */
typedef struct vt_ILxElementCenterPacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Center) (
        LXtObjectID		 self,
        LXtPointID		 vrx,
        LXtFVector		 center);
} ILxElementCenterPacket;

/*
 * A path generator packet delivers access to a continuous path through 3D space
 * defined by a parametric curve.  For some paths, the tangents may not be
 * continuous.
 * The curve implementation is not exposed.  Instead the position in 3D along the
 * path at a given parameter value is returned by the "Value" method.
 * - Value
 * Evaluates curve at parameter value 't' (0 <= t <= 1), putting the results in
 * 'pos'.
 * It is often useful to get things like the path length, or the tangent at a
 * given point.  Since some implementations can deliver these quantities without
 * doing annoying numerical derivatives (or integrals?), the path packet will
 * handle these calculations internally, and provide simple access.
 * 
 * 
 * 
 * 
 * 
 * - Count
 *  Returns the number of nodes in the path.  It will return 0 for an
 *  uninitialized or empty sequence, or a synthetic, continuous path
 *  which happens to have no nodes. A synthetic path with discontuities
 *  should have the courtesy to mark them with nodes.
 * - Knot
 *  Fills in the LXtPathKnot for the knot at 'index'.
 * 
 * - Current
 *  Returns the index of the 'current' knot, or -1 if there is none. This
 *  will allow downstream tools to build lists of extra per-knot data, and
 *  display/edit the appropriate values in the UI.
 * 
 * 
 * For many applications, a downstream client tool of the path generator
 * will want to attach some data to the each knot. Because the knots are
 * created and destroyed by undoable actions, maintaining that data would be
 * difficult for a client. Adding an optional client-defined bit of encapsulated
 * data (baggage) should help. The interface for this is the ILxBagGenerator
 * which clients will provide to create, copy and release their custom data.
 * 
 * 
 * 
 */
typedef struct vt_ILxPathGeneratorPacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Value) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        double			 t,
        LXtVector		 pos);
        LXxMETHOD(  double,
Length) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        double 			 t0,
        double			 t1);
        LXxMETHOD(  LxResult,
Tangent) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        double			 t,
        double			*tan);
        LXxMETHOD(  LXtPolygonID,
Source) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
        LXxMETHOD(  int,
Count) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD(  LxResult,
Knot) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        int			 index,
        LXtPathKnot		*knot);

        LXxMETHOD(  int,
Current) (
        LXtObjectID		 self,
        LXtObjectID		 vts);
        LXxMETHOD(  LxResult,
KnotDataSet) (
        LXtObjectID		 self,
        LXtObjectID		 gen);
        LXxMETHOD(  int,
Walk) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        LXtObjectID		 pathStep,
        double			 angle,
        double			 ti,
        double			 tf);
        LXxMETHOD(  double,
Bank) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        double			 t);
} ILxPathGeneratorPacket;

/*
 * - KnotDataSet
 *  This function sets the optional per-knot data generator. Use it
 *  to set the value of the LXtPathKnot clientData element.
 * The Bag generator interface is a simple way for clients to attach data to
 * dynamic objects like path nodes. The 'bag' pointer returned by Generate() should
 * be passed to Dispose() when it is no longer needed.
 */
typedef struct vt_ILxBagGenerator {
        ILxUnknown	 iunk;
        LXxMETHOD(  void*,
Generate) (
        LXtObjectID		 self,
        void 			*data,
        void			*cloneMe);

        LXxMETHOD(  void,
Dispose) (
        LXtObjectID		 self,
        void			*data);
} ILxBagGenerator;

/*
 * In many cases, travelling the along path can also be done more efficiently
 * internally.  The Path Generator thus provides a method for scanning the entire
 * curve with a client-supplied ILxPathStep.
 * The step function can end the walk at any time by returning a non-zero value.
 * 
 */
typedef struct vt_ILxPathStep {
        ILxUnknown	 iunk;
        LXxMETHOD(  void,
Setup) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
Step) (
        LXtObjectID		 self,
        double			 t,
        LXtVector 		 pos);
        LXxMETHOD(  void,
CleanUp) (
        LXtObjectID		 self);
} ILxPathStep;

/*
 * - Count
 *  Returns the number of particles in the sequence.  It will return 0 for an
 *  uninitialized or empty sequence, or 1 if only the InitialParticleSet method
 *  has been used to set initial conditions for the generator.
 * - Particle
 *  Fills in the LXtPGenParticleID for the particle at 'index'.
 * The generator has to be responsive to the requirements of the effector.  For
 * example, the sweep effector which is the "bit" for the lathe and extrude tool
 * composites has to be able to provide the generator with a start location.  This
 * allows the radial generator to put its first particle at the location of the
 * source data, and have the other particles spiral out from there.
 * 
 * 
 */
typedef struct vt_ILxParticleGeneratorPacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
Count) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD(  LxResult,
Particle) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        int			 index,
        LXtPGenParticle		*part);
        LXxMETHOD(  LxResult,
InitialParticleSet) (
        LXtObjectID		 self,
        const LXtPGenParticle	*part);
        LXxMETHOD(  LxResult,
HintBoxSet) (
        LXtObjectID		 self,
        const LXtBBox		*box,
        const LXtVector		 orient,
        const LXtPGenParticle	*part);
} ILxParticleGeneratorPacket;

/*
 * This packet interface has been deprecated and replaced by ILxParticleGeneratorPacket.
 */
typedef struct vt_ILxParticleGeneratorPacket1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
Count) (
        LXtObjectID		 self,
        LXtObjectID		 vts);

        LXxMETHOD(  LxResult,
Particle) (
        LXtObjectID		 self,
        LXtObjectID		 vts,
        int			 index,
        LXtPGenParticle		*part);

        LXxMETHOD(  LxResult,
InitialParticleSet) (
        LXtObjectID		 self,
        const LXtPGenParticle	*part);

        LXxMETHOD(  LxResult,
HintBoxSet) (
        LXtObjectID		 self,
        const LXtBBox		*box,
        const LXtPGenParticle	*part);
} ILxParticleGeneratorPacket1;

/*
 * Note that returning this flag from a transform tool for falloffs will quickly annhilate
 * tools like Taper and Twist.
 */

        #define LXf_SHOULDBE_ATTR		1


        #define LXiTOOLOP_TOOLPIPE	0x00000001
        #define LXiTOOLOP_PROCEDURAL	0x00000002

/*
 * - CompareOp
 * When tool attributes change, a previous tool operation could potentially still be
 * compatible, and could be used to perform incremental updates to a previous evaluation.
 * This function is called to check if a previous tool operation is compatible with the
 * current state of a tool. If it is, then the convert function will be called to update
 * the state of the tool operation, with the latest attributes associated with the tool.
 * The ReEvaluate function on the tool operation will then be called to perform an
 * incremental update to the tool. If the function specifies that the tool operation is
 * incompatible, then the previous result will be discarded, and evaluation will start
 * from scratch with a new tool operation.
 */

        #define LXiTOOLOP_DIFFERENT	0
        #define LXiTOOLOP_COMPATIBLE	1

/*
 * If a tool provides an ILxToolOperation interface, using the GetOp functions. Then it
 * should present the following server tag. This will result in the Tool Operation being
 * used to evaluate the tool. If this server tag is not present, then the standard
 * Evaluate function will be used to evaluate the tool. The value of this tag doesn't
 * matter, the presence of it is enough to signal that a tool operation will be spawned
 * to handle evaluation.
 */

        #define LXsTOOL_USETOOLOP	"tool.useToolOp"

/*
 * The standard task codes are for: snapping tools, action center and axis, weight
 * (falloff) modification tools, constraint tools, path and particle generators,
 * and the main action tools (like primitives, transforms or mesh edits).
 */

        #define LXi_TASK_SNAP		LXxID4 ('S','N','A','P')
        #define LXi_TASK_ACEN		LXxID4 ('A','C','E','N')
        #define LXi_TASK_AXIS		LXxID4 ('A','X','I','S')
        #define LXi_TASK_WGHT		LXxID4 ('W','G','H','T')
        #define LXi_TASK_CONS		LXxID4 ('C','O','N','S')
        #define LXi_TASK_ACTR		LXxID4 ('A','C','T','R')
        #define LXi_TASK_SIDE		LXxID4 ('S','I','D','E')
        #define LXi_TASK_PATH		LXxID4 ('P','A','T','H')
        #define LXi_TASK_PTCL		LXxID4 ('P','T','C','L')
        #define LXi_TASK_EFFR		LXxID4 ('E','F','F','R')
        #define LXi_TASK_BRSH		LXxID4 ('B','R','S','H')
        #define LXi_TASK_NOZL		LXxID4 ('N','O','Z','L')
        #define LXi_TASK_PINK		LXxID4 ('P','I','N','K')
        #define LXi_TASK_CONT		LXxID4 ('C','O','N','T')
        #define LXi_TASK_POST		LXxID4 ('P','O','S','T')
        #define LXi_TASK_STYL		LXxID4 ('S','T','Y','L')
        #define LXi_TASK_WORK		LXxID4 ('W','O','R','K')
        #define LXi_TASK_SYMM		LXxID4 ('S','Y','M','M')

/*
 * It's helpful to represent the tool tasks as strings for use in contexts such
 * as procedural modeling.
 */

        #define LXs_TASK_SNAP		"SNAP"
        #define LXs_TASK_ACEN		"ACEN"
        #define LXs_TASK_AXIS		"AXIS"
        #define LXs_TASK_WGHT		"WGHT"
        #define LXs_TASK_CONS		"CONS"
        #define LXs_TASK_ACTR		"ACTR"
        #define LXs_TASK_SIDE		"SIDE"
        #define LXs_TASK_PATH		"PATH"
        #define LXs_TASK_PTCL		"PTCL"
        #define LXs_TASK_EFFR		"EFFR"
        #define LXs_TASK_BRSH		"BRSH"
        #define LXs_TASK_NOZL		"NOZL"
        #define LXs_TASK_PINK		"PINK"
        #define LXs_TASK_CONT		"CONT"
        #define LXs_TASK_POST		"POST"
        #define LXs_TASK_STYL		"STYL"
        #define LXs_TASK_WORK		"WORK"
        #define LXs_TASK_SYMM		"SYMM"

/*
 * Default ordinals place these kinds of tools into their canonical order.
 * These shouldn't be changed without good reason since new ones can be inserted
 * indefinitely.
 */

        #define LXs_ORD_WORK		"\x30"
        #define LXs_ORD_SYMM		"\x31"
        #define LXs_ORD_CONT		"\x38"
        #define LXs_ORD_STYL		"\x39"
        #define LXs_ORD_SNAP		"\x40"
        #define LXs_ORD_CONS		"\x41"
        #define LXs_ORD_ACEN		"\x60"
        #define LXs_ORD_AXIS		"\x70"
        #define LXs_ORD_PATH		"\x80"
        #define LXs_ORD_WGHT		"\x90"
        #define LXs_ORD_PINK		"\xB0"
        #define LXs_ORD_NOZL		"\xB1"
        #define LXs_ORD_BRSH		"\xB2"
        #define LXs_ORD_PTCL		"\xC0"
        #define LXs_ORD_SIDE		"\xD0"
        #define LXs_ORD_EFFR		"\xD8"
        #define LXs_ORD_ACTR		"\xF0"
        #define LXs_ORD_POST		"\xF1"

/*
 * The ILxTool Interface is accessed via the LXu_TOOL unique ID, or its
 * human-readable alias, LXa_TOOL.
 */

        #define LXu_TOOL	"B2E6874C-EDD1-4F60-8B3C-F56503F96186"
        #define LXa_TOOL	"tool2"
        // [local]   ILxTool
        // [export]  ILxTool
        // [default] ILxTool:ShouldBeAttribute = 0
        // [default] ILxTool:CompareOp = LXiTOOLOP_DIFFERENT


        #define LXu_TOOL1	"12E79F81-565E-11D7-A4CF-000A95765C9E"
        #define LXa_TOOL1	"tool"

/*
 * The ILxAttrSequence Interface is accessed via the LXu_ATTRSEQUENCE unique ID.
 */

        #define LXu_ATTRSEQUENCE 		"F54FEF16-223F-439D-8593-6F350783993E"
        // [local]  ILxAttrSequence


        #define LXu_TOOLOPERATION		"116E5285-6C4A-44E8-9DC8-715E69A647A0"
        #define LXa_TOOLOPERATION		"tooloperation2"
        // [local] ILxToolOperation
        // [export] ILxToolOperation top


        #define LXu_TOOLOPERATION1		"9239B41C-AC58-44D5-8E5E-B95930E87196"
        #define LXa_TOOLOPERATION1		"tooloperation"


        #define LXsCATEGORY_TOOL	"tool"

/*
 * The Xfrm packet flags can provide hints to tools about the state of the
 * transform.  LXiTVXFMf_OFFSET should be set if the position vector 'v' is non-zero.
 * LXiTVXFMf_MATRIX should be set if the matrix is NOT the identity matrix, as an
 * indication to tools that this transformation is necessary.  LXiTVXFMf_INVERSE
 * should be set if there is a valid inverse transform matrix in 'mInv'.
 * Transforms that have no bits from LXiTVXFMf_USEFUL set are identity
 * transformations, and can be skipped.
 */

        #define LXiTVXFMf_OFFSET	1
        #define LXiTVXFMf_MATRIX	2
        #define LXiTVXFMf_INVERSE	4
        #define LXiTVXFMf_USEFUL	(LXiTVXFMf_OFFSET | LXiTVXFMf_MATRIX)

/*
 * The public versions are defined in circulardependencykludges.h, and are here for
 * reference only.
 * 	TVXFMf_OFFSET
 * 	TVXFMf_MATRIX
 * 	TVXFMf_INVERSE
 * 	TVXFMf_USEFUL
 */

        #define LXsP_TOOL_SUBJECT	"tool.subject"
        #define LXsP_TOOL_ACTCENTER	"tool.actionCenter"
        #define LXsP_TOOL_AXIS		"tool.axis"
        #define LXsP_TOOL_XFRM		"tool.xfrm"


        #define LXsP_TOOL_FALLOFF	"tool.falloff"
        #define LXsP_TOOL_SYMMETRY	"tool.symmetry"
        #define LXsP_TOOL_TEXTURE	"tool.texture"
        #define LXsP_TOOL_ELTCENTER	"tool.eltCenter"
        #define LXsP_TOOL_ELTAXIS	"tool.eltAxis"


        #define LXu_FALLOFFPACKET		"B0EA09EB-B022-4AE2-903A-4A0F5CA33835"
        // [local]  ILxFalloffPacket


        #define LXu_FALLOFFPACKET1		"D0F8CF5D-1BB5-4002-810B-0E7EF34B7867"


        #define LXu_SYMMETRYPACKET		"F13F6933-1289-4EFC-9CE1-D5C4F13EE7D8"
        // [local]  ILxSymmetryPacket


        #define LXu_SUBJECT2PACKET		"CA342D92-26C8-4A25-AD27-0163AD54730D"
        // [local]  ILxSubject2Packet
        // [python] ILxSubject2Packet:ScanAllocate	obj LayerScan


        #define LXu_TEXTUREPACKET		"851271E5-F4F4-444D-A87A-563B9E1E6EFB"
        // [local]  ILxTexturePacket


        #define LXu_ELEMENTAXISPACKET	"292A47BF-3CF5-492D-AAFD-AE761092A782"
        // [local]  ILxElementAxisPacket


        #define LXu_ELEMENTCENTERPACKET	"5221C415-073A-4610-BCB6-F820F8D7F6D0"
        // [local]  ILxElementCenterPacket

/*
 * The flags determine if the tangents are equal or not.
 */

        #define LXf_PATHKNOT_BROKEN	1

/*
 * - Generate
 *  This method allocates new client data. For convenience some node-specific data
 *  may be passed in to the generator. If the cloneMe pointer is non-NULL, it is
 *  assumed to point to suitable client data, and it will be copied into the new
 *  bag exactly.
 * - Dispose
 *  This frees the bag and its contents.
 */

        #define LXu_BAGGENERATOR		"9A368FAA-7576-42B9-9B6A-C2F8D34612F0"
        // [local]  ILxBagGenerator


        #define LXu_PATHSTEP		"B9F58563-FBA0-4CA2-866B-1DD64174A277"
        // [local]  ILxPathStep

/*
 * - Walk
 * This function 'walks' along the path, invoking the supplied ILxPathStep's
 * step() at each step with the curve parameter and the 3D position.  It
 * returns the number of steps taken, which is determined by the angle argument.
 * The angle (in radians) is the maximum angle allowed between adjacent linear
 * divisions.  For convenience, Coarse, Medium, and Fine presets (corresponding to
 * 6, 5, and 3 degrees, respectively) are defined.
 */

        #define LXv_PATHGEN_DIV_COARSE		0.105
        #define LXv_PATHGEN_DIV_MEDIUM		0.087
        #define LXv_PATHGEN_DIV_FINE		0.052

/*
 * - Bank
 * Returns the bank angle at the given parameter value.
 */

        #define LXu_PATHGENERATORPACKET		"AE70D946-8A9A-4A72-95EC-BFF856391D22"
        #define	LXa_PATHGENERATORPACKET		"pathgeneratorpacket"
        // [local]  ILxPathGeneratorPacket
        // [export] ILxPathGeneratorPacket pathgen
        // [default] ILxPathGeneratorPacket:Length = 0
        // [default] ILxPathGeneratorPacket:Source = 0
        // [default] ILxPathGeneratorPacket:Count = 0
        // [default] ILxPathGeneratorPacket:Current = 0
        // [default] ILxPathGeneratorPacket:Walk = 0
        // [default] ILxPathGeneratorPacket:Bank = 0


        #define LXsP_TOOL_PATHGEN	"tool.pathGenerator"

/*
 * For convenience, a basic implementation of the ILxPathStep interface is provided.
 * It will call a client callback at each step. The callback must be in this not unfamiliar form:
 */

        typedef void PathWalkerFunc (void *data, double t, LXtVector pos);

/*
 * - position
 *  Particle position in space
 * - scale
 *  A vector of scaling factors for each of the particle coordinates
 * - orientation
 *  The particle coordinate system, defined by an orthonormal transformation matrix.
 * 
 * - flags
 *  The 'connect' flag tells clients that the particle is part of a continuous series by
 *  indicating that this particle is connected to the one following it.  If this
 *  is the last particle, it is this flag means that the particle is connected to
 *  the first, closing the sequence.
 *  The 'absSize' flag tells clients that the particle size is absolute. In many cases the
 *  size is relative, depending on what the effector is dealing with.
 *  The 'mirror' flag is a special mode to make mirrored particles based on the scale
 *  vectors. "curve" flag is set by curve like generator which requires a duplication at 
 *  the initial particle position.
 *  The "nosymmetry" flag tells clients to ignore the current symmetry status.
 *  The 'newpath" flags tells clients to start new connecting path.
 * 
 */

        #define LXf_PARTGEN_CONNECT		0x01
        #define LXf_PARTGEN_ABSSIZE		0x02
        #define LXf_PARTGEN_MIRROR		0x04
        #define LXf_PARTGEN_CURVE		0x08
        #define LXf_PARTGEN_NOSYMMETRY		0x10
        #define LXf_PARTGEN_NEWPATH		0x20

/*
 * - InitialParticleSet
 *  Set the initial state of the particle generator.  The state of particle
 *  supplied will be copied and used as the 0th particle.
 * - HintBoxSet
 *  This is an optional method for InitialParticleSet. Set the bounding box 
 *  and the initial orientation when it defines the initial particle.
 * - InitialParticleSetFromMesh
 *  Set the initial state of the particle generator.  The state of particle
 *  supplied will be copied and used as the 0th particle.
 *  This version will use the supplied mesh instead of scanning global layers.
 * 
 */

        #define LXu_PARTICLEGENERATORPACKET	"36001340-F153-4B32-82A4-7DA438969371"
        #define	LXa_PARTICLEGENERATORPACKET	"particlegeneratorpacket2"
        // [local]  ILxParticleGeneratorPacket
        // [export] ILxParticleGeneratorPacket partgen
        // [default] ILxParticleGeneratorPacket:Count = 0


        #define LXsP_TOOL_PARTGEN	"tool.partGenerator"


        #define LXu_PARTICLEGENERATORPACKET1	"5CDF5B58-46BF-4D78-8652-659E87E19C4B"
        #define	LXa_PARTICLEGENERATORPACKET1	"particlegeneratorpacket"


        #define LXsP_TOOL_CONTENT	"tool.content"


        #define LXsP_TOOL_STYLE		"tool.style"

/*
 * Tool flags are used for the enable, visibility and hauling states.
 * Additional bits describe a tool which will be automatically activated.
 */

        #define LXf_TOOL_ENABLE			1
        #define LXf_TOOL_ACTIVE			2
        #define LXf_TOOL_HAUL			4
        #define LXf_TOOL_HAUL2			(1<<16) + LXf_TOOL_HAUL
        #define LXf_TOOL_NOHAUL			(1<<17)
        #define LXf_TOOL_AUTOACT		(1<<4)
        #define LXf_TOOL_IMPLICIT		(1<<5)
        #define LXf_TOOL_POSTAPPLY		(1<<6)
        #define LXf_TOOL_NOCACHE		(1<<7)
        #define LXf_TOOL_IMMEDIATE		(1<<8)
        #define LXf_TOOL_NOATTRS		(1<<9)
        #define LXf_TOOL_STAYACTIVE		(1<<10)
        #define LXf_TOOL_INDIRECT		(1<<11)
        #define LXf_TOOL_AUTORESET		(1<<12)
        #define LXf_TOOL_PERSIST		(1<<13)
        #define LXf_TOOL_DRAW_MASK		(0xFF<<24)
        #define LXx_TOOL_DRAWFLAGS(f)		((f)>>24)
        #define LXx_TOOL_SETDRAW(f)		((f)<<24)
        #define LXm_TOOL_TRANSIENT		(LXf_TOOL_HAUL|LXf_TOOL_HAUL2)
        #define LXm_TOOL_STATIC			(~(LXf_TOOL_ACTIVE | LXf_TOOL_IMPLICIT | LXm_TOOL_TRANSIENT))
        #define LXm_TOOL_DEFAULT		(LXf_TOOL_ENABLE | LXf_TOOL_VISIBLE)

/*
 * - LXf_TOOLf_ENABLE
 * Tool enabled state
 * - LXf_TOOLf_ACTIVE
 * Tool has been activated for interactive processing.
 * - LXf_TOOLf_HAUL
 * Tool receives primary hauling input.
 * - LXf_TOOLf_HAUL2
 * Tool receives secondary hauling input.
 * - LXf_TOOLf_AUTOACT
 * Tool activates upon insertion into toolpipe.
 * 
 * - LXf_TOOLf_IMPLICIT
 * Tool was activated indirectly as a result of downstream tool activation,
 * and has not been modified manually by the user.
 * 
 * - LXf_TOOLf_POSTAPPLY
 * Tool suggests 'Post-Apply' mode, which defers mesh operations until
 * interactive tool use is completed.
 * 
 * - LXf_TOOLf_NOCACHE
 * Tool should not be cached with user-adjustments, i.e. it is locked.
 * 
 * - LXf_TOOLf_PERSIST
 * Tool persistently uses the attributes from tool preset instead of cached attributes.
 * 
 * - LXm_TOOLm_TRANSIENT
 * Tool node flags are stored in presets, but some of the bit are transient, and
 * should not be preserved/restored as part of the preset properties.  This mask
 * defnes those bits.
 * 
 * - LXf_TOOLf_IMMEDIATE
 * The tool should deactivate upon mouse-up, disallowing further edits.
 * 
 * - LXf_TOOLf_NOATTRS
 * The tool should not save any state (attributes) in presets. This includes any
 * Attr. sequence. Tools with this flag will load into the pipeline with just the
 * default attribute values the tool creates.
 * 
 * - LXf_TOOLf_NOHAUL
 * The tool should not handle hauling events, allowing selection. This would be countermanded
 * by a ToolModel flag (NEEDSHAUL) specifying that a tool has no handles and thus requires
 * hauling, forbidding the use of selection while the tool is active.
 * 
 * - LXf_TOOLf_STAYACTIVE
 * The tool should not deactivate once it has been activated, this can be useful when used in
 * conjunction with TOOLf_IMMEDIATE as it allows keeping a tool active when the pipe auto deactivates.
 * 
 * - LXf_TOOLf_INDIRECT
 * The tool is always activated indirectly as a result of downstream tool activation.
 * 
 * - LXf_TOOL_AUTORESET
 * This is to distinguish between transform and general tools...
 * 
 * 
 * The draw flags are defined more precisely.  They are used by the ToolModel
 * interface extensively, but the tool pipe will still benefit from understanding
 * the combination of these bits which determine a tool's visibility.
 * 
 * 
 */

#define LXf_TOOL_DRAW_PLAIN		(1<<24)
#define LXf_TOOL_DRAW_FANCY		(2<<24)
#define LXf_TOOL_DRAW_PLAIN_S		(LXf_TOOL_DRAW_PLAIN<<4)
#define LXf_TOOL_DRAW_FANCY_S		(LXf_TOOL_DRAW_FANCY<<4)
#define LXf_TOOL_VISIBLE		(LXf_TOOL_DRAW_PLAIN | LXf_TOOL_DRAW_FANCY | LXf_TOOL_DRAW_PLAIN_S | LXf_TOOL_DRAW_FANCY_S)
#define LXf_TOOL_PLAIN			(LXf_TOOL_DRAW_PLAIN|LXf_TOOL_DRAW_PLAIN_S)
#define LXf_TOOL_FANCY			(LXf_TOOL_DRAW_FANCY|LXf_TOOL_DRAW_FANCY_S)

#endif
