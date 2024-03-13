/*
 * LX vectortools module
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
#ifndef LX_vectortools_H
#define LX_vectortools_H

typedef struct vt_ILxVectorCanvas ** ILxVectorCanvasID;
typedef struct vt_ILxVectorShape ** ILxVectorShapeID;
typedef struct vt_ILxVectorPath ** ILxVectorPathID;
typedef struct vt_ILxVectorListener ** ILxVectorListenerID;

#include <lxcom.h>


        typedef void *	 LXtVectorKnotID;

        // [python] type LXtVectorKnotID	id



/*
 * The GetItem function returns the item that the vector canvas server is stored on.
 * If the canvas is not associated with an item, the function will return NOTAVAILABLE.
 * 
 * Editing canvas data can be expensive, as any change to the data can trigger
 * events that other systems react to. The edit batch allows a group of similar
 * changes to be combined, so the events will not be triggered until the edit is
 * finished and the batch is closed.
 */
typedef struct vt_ILxVectorCanvas {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
GetItem) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
BeginEditBatch) (
        LXtObjectID		  self);

        LXxMETHOD( LxResult,
EndEditBatch) (
        LXtObjectID		  self);
} ILxVectorCanvas;

/*
 * Shapes can contain multiple sub-shapes. This function returns the number of
 * child shapes that a shape contains.
 * 
 * This allows a child shape to be accessed by index. The object returned can be
 * queried for an ILxVectorShape interface.
 * 
 * A shape can be queried for it's parent using the following function. If this
 * shape is the top-most shape, the function will return NOTFOUND, however this
 * shape can be queried for an ILxVectorCanvas interface.
 * 
 * A shape can contain multiple paths. This function returns the number of paths
 * stored on a shape.
 * 
 * This allows a path to be accessed by index. The object returned can be queried
 * for an ILxVectorPath interface.
 * 
 * A shape can be transformed by passing a 3x3 matrix that encodes a 2D rotation,
 * 2D transform, and 2D scale to be applied to the shape.
 */
typedef struct vt_ILxVectorShape {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
ShapeCount) (
        LXtObjectID		  self,
        unsigned int		 *count);
        LXxMETHOD( LxResult,
ShapeByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Parent) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
PathCount) (
        LXtObjectID		  self,
        unsigned int		 *count);
        LXxMETHOD( LxResult,
PathByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Transform) (
        LXtObjectID		  self,
        const LXtMatrix		  matrix);
} ILxVectorShape;

/*
 * Paths can either be open or closed. This state can be queried and modified using
 * the following functions.
 * This function returns the number of knots that make up the path.
 * 
 * Knots can be "selected" by index. When a knot is selected, querying the
 * properties of the knot will return information about this knot.
 * 
 * Knots can be "selected" directly. When a knot is selected, querying the
 * properties of the knot will return information about this knot.
 * 
 * Knots can be enumerated using a visitor. For each knot, the visitor evaluate
 * function will be called, and the path accessor will be updated to point at the
 * new knot.
 * 
 * This methods returns the ID of the curent knot or null if none.
 * 
 * This methods returns the position of the curent knot.
 */
typedef struct vt_ILxVectorPath {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
IsPathClosed) (
        LXtObjectID		  self);

        LXxMETHOD( LxResult,
SetPathClosed) (
        LXtObjectID		  self,
        LxResult		  closed);
        LXxMETHOD( LxResult,
KnotCount) (
        LXtObjectID		  self,
        unsigned int		 *count);
        LXxMETHOD( LxResult,
SelectKnotByIndex) (
        LXtObjectID		  self,
        unsigned int		  index);
        LXxMETHOD( LxResult,
SelectKnot) (
        LXtObjectID		  self,
        LXtVectorKnotID		  knot);
        LXxMETHOD( LxResult,
KnotEnumerate) (
        LXtObjectID		  self,
        LXtObjectID		  visitor);
        LXxMETHOD( LXtVectorKnotID,
ID) (
        LXtObjectID		  self);
        LXxMETHOD( LxResult,
Pos) (
        LXtObjectID		  self,
        double			 *x,
        double			 *y);
} ILxVectorPath;

/*
 * This event is sent when the canvas is destroyed.
 * 
 * After a shape is added, this event will be called. The shape is passed as an
 * argument.
 * 
 * Before a shape is removed, this event will be called. The shape is passed as an
 * argument.
 * 
 * This event is used to mark a shape style change. The shape and name of the
 * style are passed as arguments.
 * 
 * After a path is added, this event will be called. The shape and path are passed
 * as arguments.
 * 
 * Before a path is removed, this event will be called. The shape and path are
 * passed as arguments.
 * 
 * When a knot changes position, this event will be called. The shape and path are
 * provided as arguments, and the path accessor is pointing at the knot that has
 * changed.
 */
typedef struct vt_ILxVectorListener {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Destroy) (
        LXtObjectID		  self);
        LXxMETHOD( LxResult,
ShapeAdd) (
        LXtObjectID		  self,
        LXtObjectID		  shape);
        LXxMETHOD( LxResult,
ShapeRemove) (
        LXtObjectID		  self,
        LXtObjectID		  shape);
        LXxMETHOD( LxResult,
ShapeStyle) (
        LXtObjectID		  self,
        LXtObjectID		  shape,
        const char		 *name);
        LXxMETHOD( LxResult,
PathAdd) (
        LXtObjectID		  self,
        LXtObjectID		  shape,
        LXtObjectID		  path);
        LXxMETHOD( LxResult,
PathRemove) (
        LXtObjectID		  self,
        LXtObjectID		  shape,
        LXtObjectID		  path);
        LXxMETHOD( LxResult,
KnotPosition) (
        LXtObjectID		  self,
        LXtObjectID		  shape,
        LXtObjectID		  path);
} ILxVectorListener;

/*
 * The Vector Canvas interface is used to store all the vector data associated with
 * a vector item. It is usually stored in a channel, and can contain multiple
 * shapes, paths and knots. The server implementing the vector canvas interface
 * will also present a ILxVectorShape interface representing a single shape that
 * contains all of the vector data and any sub-shapes.
 */

        #define	LXu_VECTORCANVAS		"7A7915F0-E496-40D3-BD22-733D73885652"
        #define LXa_VECTORCANVAS		"vectorcanvas"
        // [local] ILxVectorCanvas
        // [export] ILxVectorCanvas		 canvas
        // [python] ILxVectorCanvas:GetItem	 obj Item

/*
 * Items declare that they can provide a vector canvas with a package tag giving
 * the name of the vector canvas channel. Read in an evaluated context, this will
 * be a ValueReference object channel holding the vector canvas object.
 */

        #define LXsPKG_CANVAS_CHANNEL	"vectorCanvas.channel"

/*
 * The Vector Shape interface represents a single shape in the canvas. Each shape
 * has some basic properties, a collection of paths that make up the shape, as well
 * as any number of sub-shapes. The server can be queried for an ILxAttributes
 * interface, allowing the style properties of the shape to be accessed and
 * potentially manipulated.
 */

        #define	LXu_VECTORSHAPE			"2B56643A-9697-42F4-99F9-04F96038D45E"
        #define LXa_VECTORSHAPE			"vectorshape"
        // [local] ILxVectorShape
        // [export] ILxVectorShape		 shape
        // [python] ILxVectorShape:ShapeByIndex	 obj VectorShape
        // [python] ILxVectorShape:Parent	 obj VectorShape
        // [python] ILxVectorShape:PathByIndex	 obj VectorPath

/*
 * The Vector Path interface provides access to some basic properties, such as
 * if the path is closed or not, as well as providing an accessor to access path
 * knots.
 */

        #define	LXu_VECTORPATH			"13C5B133-4AE3-4934-B748-E2B1D3904874"
        #define LXa_VECTORPATH			"vectorpath"
        // [local] ILxVectorPath
        // [export] ILxVectorPath		 path
        // [python] ILxVectorPath:IsPathClosed	 bool

/*
 * The Vector Listener allows clients to be signalled whenever the canvas state
 * changes. Clients can attach to a ListenerPort interface on the Canvas object,
 * and be signaled about changes through the ILxVectorListener interface that they
 * implement.
 */

        #define	LXu_VECTORLISTENER		"90310E7B-85DB-4E5D-839B-25562FF50713"
        #define LXa_VECTORLISTENER		"vectorlistener"
        // [local] ILxVectorListener
        // [export] ILxVectorListener		 vtl

#endif
