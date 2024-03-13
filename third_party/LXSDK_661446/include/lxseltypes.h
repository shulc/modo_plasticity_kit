/*
 * LX seltypes module
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
#ifndef LX_seltypes_H
#define LX_seltypes_H

typedef struct vt_ILxScenePacketTranslation ** ILxScenePacketTranslationID;
typedef struct vt_ILxItemPacketTranslation ** ILxItemPacketTranslationID;
typedef struct vt_ILxNodePacketTranslation ** ILxNodePacketTranslationID;
typedef struct vt_ILxChannelPacketTranslation ** ILxChannelPacketTranslationID;
typedef struct vt_ILxCenterPacketTranslation ** ILxCenterPacketTranslationID;
typedef struct vt_ILxPivotPacketTranslation ** ILxPivotPacketTranslationID;
typedef struct vt_ILxLinkPacketTranslation ** ILxLinkPacketTranslationID;
typedef struct vt_ILxActionLayerPacketTranslation ** ILxActionLayerPacketTranslationID;
typedef struct vt_ILxVertexPacketTranslation ** ILxVertexPacketTranslationID;
typedef struct vt_ILxEdgePacketTranslation ** ILxEdgePacketTranslationID;
typedef struct vt_ILxPolygonPacketTranslation ** ILxPolygonPacketTranslationID;
typedef struct vt_ILxVMapPacketTranslation ** ILxVMapPacketTranslationID;
typedef struct vt_ILxPresetPathPacketTranslation ** ILxPresetPathPacketTranslationID;
typedef struct vt_ILxItemChannel ** ILxItemChannelID;
typedef struct vt_ILxVectorShapePacketTranslation ** ILxVectorShapePacketTranslationID;
typedef struct vt_ILxVectorPathPacketTranslation ** ILxVectorPathPacketTranslationID;
typedef struct vt_ILxVectorKnotPacketTranslation ** ILxVectorKnotPacketTranslationID;

#include <lxmesh.h>
#include <lxvectortools.h>



typedef struct vt_ILxScenePacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Scene) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtObjectID		 scene);
} ILxScenePacketTranslation;

typedef struct vt_ILxItemPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtObjectID		 item);
} ILxItemPacketTranslation;

typedef struct vt_ILxNodePacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Node) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtObjectID		 node);
} ILxNodePacketTranslation;

typedef struct vt_ILxChannelPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  unsigned int,
Index) (
        LXtObjectID		 self,
        void			*packet);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 index);
} ILxChannelPacketTranslation;

typedef struct vt_ILxCenterPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtObjectID		 item);
} ILxCenterPacketTranslation;

typedef struct vt_ILxPivotPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  unsigned int,
Type) (
        LXtObjectID		 self,
        void			*packet);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 type);
} ILxPivotPacketTranslation;

typedef struct vt_ILxLinkPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
From) (
        LXtObjectID		 self,
        void			*packet,
        int			*channel,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
To) (
        LXtObjectID		 self,
        void			*packet,
        int			*channel,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtObjectID		 fromItem,
        int			 fromChannel,
        LXtObjectID		 toItem,
        int			 toChannel);
} ILxLinkPacketTranslation;

typedef struct vt_ILxActionLayerPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  unsigned int,
Index) (
        LXtObjectID		 self,
        void			*packet);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 index);
} ILxActionLayerPacketTranslation;

typedef struct vt_ILxVertexPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Vertex) (
        LXtObjectID		 self,
        void			*packet,
        LXtPointID		*vertex);

        LXxMETHOD(  LxResult,
Polygon) (
        LXtObjectID		 self,
        void			*packet,
        LXtPolygonID		*polygon);

        LXxMETHOD(  LxResult,
Mesh) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtPointID		 vertex,
        LXtPolygonID		 polygon,
        LXtObjectID		 mesh);

        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);
} ILxVertexPacketTranslation;

typedef struct vt_ILxEdgePacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Vertices) (
        LXtObjectID		 self,
        void			*packet,
        LXtPointID		*vertexA,
        LXtPointID		*vertexB);

        LXxMETHOD(  LxResult,
Polygon) (
        LXtObjectID		 self,
        void			*packet,
        LXtPolygonID		*polygon);

        LXxMETHOD(  LxResult,
Mesh) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtPointID		 vertexA,
        LXtPointID		 vertexB,
        LXtPolygonID		 polygon,
        LXtObjectID		 mesh);

        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);
} ILxEdgePacketTranslation;

typedef struct vt_ILxPolygonPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Polygon) (
        LXtObjectID		 self,
        void			*packet,
        LXtPolygonID		*polygon);

        LXxMETHOD(  LxResult,
Mesh) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtPolygonID		 polygon,
        LXtObjectID		 mesh);

        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);
} ILxPolygonPacketTranslation;

typedef struct vt_ILxVMapPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        void			*packet,
        const char	       **name);

        LXxMETHOD(  LxResult,
Type) (
        LXtObjectID		 self,
        void			*packet,
        LXtID4			*type);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*name);
} ILxVMapPacketTranslation;

/*
 * The preset path selection packet includes the path to a preset on disk, and
 * an optional client identifier that can be used as a selection sub-type.  These
 * identifiers are usually associated with a Preset Browser viewport instance.
 * See the Preset Browser documentation for more information on the preset path
 * selection packet.
 * These return the path and identifier.  If these strings are not set or empty
 * in the packet, the pointers returned will be NULL.
 * 
 * 
 * This creates anew packet from a given path and identifier.  This packet
 * is only valid until the next call to this function.
 */
typedef struct vt_ILxPresetPathPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Path) (
        LXtObjectID		  self,
        void			 *packet,
        const char		**path);

        LXxMETHOD(  LxResult,
Identifier) (
        LXtObjectID		  self,
        void			 *packet,
        const char		**identifier);
        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        const char		*path,
        const char		*identifier);
} ILxPresetPathPacketTranslation;

typedef struct vt_ILxItemChannel {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  unsigned int,
ChannelIndex) (
        LXtObjectID		 self);
} ILxItemChannel;

typedef struct vt_ILxVectorShapePacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Shape) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Canvas) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);


        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtObjectID		 shape);
} ILxVectorShapePacketTranslation;

typedef struct vt_ILxVectorPathPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Path) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Shape) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Canvas) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);


        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtObjectID		 path);
} ILxVectorPathPacketTranslation;

typedef struct vt_ILxVectorKnotPacketTranslation {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Knot) (
        LXtObjectID		 self,
        void			*packet,
        LXtVectorKnotID		*knot);

        LXxMETHOD(  LxResult,
Path) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Shape) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Canvas) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);


        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void			*packet,
        void		       **ppvObj);

        LXxMETHOD(  void *,
Packet) (
        LXtObjectID		 self,
        LXtVectorKnotID		 knot);
} ILxVectorKnotPacketTranslation;


        #define LXiSEL_ACTION		LXxID4('A','C','T','I')	// Action
        #define LXiSEL_ITEM		LXxID4('I','T','E','M')	// Item
        #define LXiSEL_VERTEX		LXxID4('V','E','R','X')	// Vertex (Point)
        #define LXiSEL_POLYGON		LXxID4('P','O','L','Y')	// Polygon
        #define LXiSEL_MODIFIER		LXxID4('M','O','D','S')	// Modifier
        #define LXiSEL_CHANNEL		LXxID4('C','H','A','N')	// Channel
        #define LXiSEL_CINEMA		LXxID4('C','I','N','E')	// Cinema
        #define LXiSEL_PARTICLE		LXxID4('P','T','C','L')	// Particle
        #define LXiSEL_ENVELOPE		LXxID4('E','N','V','L')	// Envelope
        #define LXiSEL_ENVELOPE_KEY	LXxID4('E','K','E','Y')	// Envelope Keyframe
        #define LXiSEL_GRADIENT_KEY	LXxID4('G','K','E','Y')	// Gradient Keyframe
        #define LXiSEL_EDGE		LXxID4('E','D','G','E')	// Mesh Edge
        #define LXiSEL_VMAP		LXxID4('V','M','A','P')	// Vertex Map
        #define LXiSEL_PTAG		LXxID4('P','T','A','G')	// Polygon Tag
        #define LXiSEL_PIVOT		LXxID4('P','I','V','T')	// Pivot
        #define LXiSEL_CENTER		LXxID4('C','N','T','R')	// Center
        #define LXiSEL_LINK		LXxID4('L','I','N','K')	// Link
        #define LXiSEL_VECTORSHAPE	LXxID4('V','S','H','P')	// Vector Shape
        #define LXiSEL_VECTORPATH	LXxID4('V','P','T','H')	// Vector Path
        #define LXiSEL_VECTORKNOT	LXxID4('V','K','N','T')	// Vector Knot

/*
 * Scene selection determines which scene is currently active for commands. The
 * selection packet can be read or encoded.
 */

        #define LXsSELTYP_SCENE			"cinema"
        #define LXu_SCENEPACKETTRANSLATION	"A63F8E08-94D8-11D9-96D3-000A956C2E10"
        // [local]  ILxScenePacketTranslation
        // [python] ILxScenePacketTranslation:Scene	obj Scene

/*
 * Selected items can be of different types, and each packet encodes a single
 * item selection.
 */

        #define LXsSELTYP_ITEM			"item"
        #define LXu_ITEMPACKETTRANSLATION	"029663CC-9571-11D9-B9AD-000A956C2E10"
        // [local]  ILxItemPacketTranslation
        // [python] ILxItemPacketTranslation:Item	obj Item

/*
 * Selected nodes can be of different types, and each packet encodes a single
 * node selection.
 */

        #define LXsSELTYP_NODE			"schmNode"
        #define LXu_NODEPACKETTRANSLATION	"5A560F1B-DC73-4efb-8579-C6C7D9373C60"
        // [local]  ILxNodePacketTranslation
        // [python] ILxNodePacketTranslation:Node	obj Node

/*
 * Selected channels are wrapped in a COM object that contains an item/channel pair.
 */

        #define LXsSELTYP_CHANNEL		"channel"
        #define LXu_CHANNELPACKETTRANSLATION	"00DE9D39-6A83-46DC-9C28-360662922CE5"
        // [local]  ILxChannelPacketTranslation
        // [python] ILxChannelPacketTranslation:Item	obj Item

/*
 * Selected centers are identical to selected items, but need a different translation
 * interface.
 */

        #define LXsSELTYP_CENTER		"center"
        #define LXu_CENTERPACKETTRANSLATION	"52B10EAB-9EA6-4F28-81D1-2FEC51E02933"
        // [local]  ILxCenterPacketTranslation
        // [python] ILxCenterPacketTranslation:Item	obj Item

/*
 * Pivots have an item and a type.
 * NOTE: define the types here...
 */

        #define LXsSELTYP_PIVOT			"pivot"
        #define LXu_PIVOTPACKETTRANSLATION	"9744D68E-D6CD-4652-AD33-073A24E16901"
        // [local]  ILxPivotPacketTranslation
        // [python] ILxPivotPacketTranslation:Item	obj Item

/*
 * Links are defined by a starting item and channel, and an ending item and channel.
 * NOTE: shouldn't we also know the graph?
 */

        #define LXsSELTYP_LINK			"link"
        #define LXu_LINKPACKETTRANSLATION	"EEA9F625-EB3C-43FD-A156-C8552D6D18C9"
        // [local]  ILxLinkPacketTranslation
        // [python] ILxLinkPacketTranslation:From	obj Item
        // [python] ILxLinkPacketTranslation:To		obj Item


        #define LXsSELTYP_ACTIONLAYER			"actionLayer"
        #define LXu_ACTIONLAYERPACKETTRANSLATION	"E685D569-1C0F-4E8A-94A9-4FC29453689F"
        // [local]  ILxActionLayerPacketTranslation
        // [python] ILxActionLayerPacketTranslation:Item	obj Item

/*
 * A selected vertex is part of a mesh, which can be read from the packet. The
 * selected vertex may also be discontinuous, in which case the polygon associated
 * with the selected vertex will be non-null.
 */

        #define LXsSELTYP_VERTEX		"vertex"
        #define LXu_VERTEXPACKETTRANSLATION	"D77B8382-9572-11D9-AFDE-000A956C2E10"
        // [local]  ILxVertexPacketTranslation
        // [python] ILxVertexPacketTranslation:Item	obj Item
        // [python] ILxVertexPacketTranslation:Mesh	obj Mesh

        // [python] type LXtPointID	id
        // [python] type LXtPolygonID	id

/*
 * A selected edge is given by a pair of vertices in a mesh. As with vertices,
 * edge selections may be discontinuous in which case the polygon will be non-null.
 */

        #define LXsSELTYP_EDGE			"edge"
        #define LXu_EDGEPACKETTRANSLATION	"CA4DFE14-957E-11D9-AC64-000A956C2E10"
        // [local]  ILxEdgePacketTranslation
        // [python] ILxEdgePacketTranslation:Item	obj Item
        // [python] ILxEdgePacketTranslation:Mesh	obj Mesh

/*
 * Polygon selection is just a polygon ID in a mesh.
 */

        #define LXsSELTYP_POLYGON		"polygon"
        #define LXu_POLYGONPACKETTRANSLATION	"2E0929DC-9583-11D9-B058-000A956C2E10"
        // [local]  ILxPolygonPacketTranslation
        // [python] ILxPolygonPacketTranslation:Item	obj Item
        // [python] ILxPolygonPacketTranslation:Mesh	obj Mesh

/*
 * A selected vertex map consists entirely of a name and a type. Commands
 * affect all selected mesh items that contain a vertex map with that name
 * and type.
 */

        #define LXsSELTYP_VERTEXMAP		"vmap"
        #define LXu_VMAPPACKETTRANSLATION	"BBCB6B90-9586-11D9-A3B8-000A956C2E10"
        // [local] ILxVMapPacketTranslation


        #define LXsSELTYP_PRESETPATH			"preset"
        #define LXu_PRESETPATHPACKETTRANSLATION		"6b95c2ac-9a9e-471f-9771-cf10fd5c6bcb"
        // [local]  ILxPresetPathPacketTranslation

/*
 * This simple read-only interface is used to represent a single channel in an
 * item as a single entity.
 */

        #define LXu_ITEMCHANNEL			"3cfab0aa-8e8c-452c-81e5-272842fff935"
        #define LXa_ITEMCHANNEL			"itemchannel"
        // [local]  ILxItemChannel
        // [python] ILxItemChannel:Item	obj Item

/*
 * Vector Shapes provide a shape, the canvas the shape belongs to, as well as the
 * vector item.
 */

        #define LXsSELTYP_VECTORSHAPE			"vectorShape"
        #define LXu_VECTORSHAPEPACKETTRANSLATION	"33C886D1-1574-4D8E-9DFD-D8D1CB7A21FE"
        // [local]  ILxVectorShapePacketTranslation
        // [export] ILxVectorShapePacketTranslation		shapeTrans
        // [python] ILxVectorShapePacketTranslation:Shape	obj VectorShape
        // [python] ILxVectorShapePacketTranslation:Canvas	obj VectorCanvas
        // [python] ILxVectorShapePacketTranslation:Item	obj Item

/*
 * Vector Paths provide a path, the shape and canvas the path belongs to, as well
 * as the vector item.
 */

        #define LXsSELTYP_VECTORPATH			"vectorPath"
        #define LXu_VECTORPATHPACKETTRANSLATION		"C3E6DF29-7217-4D89-9E84-DA6D45B9396E"
        // [local]  ILxVectorPathPacketTranslation
        // [export] ILxVectorPathPacketTranslation		pathTrans
        // [python] ILxVectorPathPacketTranslation:Path		obj VectorPath
        // [python] ILxVectorPathPacketTranslation:Shape	obj VectorShape
        // [python] ILxVectorPathPacketTranslation:Canvas	obj VectorCanvas
        // [python] ILxVectorPathPacketTranslation:Item		obj Item

/*
 * Vector Knots provide a knot, the path, shape and canvas the knot belongs to, as
 * well as the vector item.
 */

        #define LXsSELTYP_VECTORKNOT			"vectorKnot"
        #define LXu_VECTORKNOTPACKETTRANSLATION		"F4DDFFEA-3077-4931-8384-81C49AD1C41C"
        // [local]  ILxVectorKnotPacketTranslation
        // [export] ILxVectorKnotPacketTranslation		knotTrans
        // [python] ILxVectorKnotPacketTranslation:Path		obj VectorPath
        // [python] ILxVectorKnotPacketTranslation:Shape	obj VectorShape
        // [python] ILxVectorKnotPacketTranslation:Canvas	obj VectorCanvas
        // [python] ILxVectorKnotPacketTranslation:Item		obj Item

#endif
