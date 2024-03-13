/*
 * LX layer module
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
#ifndef LX_layer_H
#define LX_layer_H

typedef struct vt_ILxLayerService ** ILxLayerServiceID;
typedef struct vt_ILxLayerScan ** ILxLayerScanID;
typedef struct vt_ILxTransformScan ** ILxTransformScanID;
typedef struct vt_ILxScene1Service ** ILxScene1ServiceID;

        #define NEW_SURF_INTERFACE



/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.
 * 
 * The layer service functions operate with to a certain scene.  This scene should
 * be specified by the client BEFORE any other methods are used, as an initialization
 * step.  The scene can also be reset at any time, either to a new scene, or to force a refresh
 * of the layer data.
 * 
 * The following functions operate on these lists, with indices based, naturally, on the
 * position within the given list.
 * 
 * 
 * These methods find an item's position in one of the lists based on
 * the item itself, or on its name.  They will return an error AND set the
 * index to -1 if the item is not found in the specified list.  To use this
 * index in layer commands, use LXi_LAYER_ALL mode.
 * 
 * These methods access the parent-child relationships among layers.  They return
 * an index into the LXi_LAYER_ALL list, or -1.
 * 
 * 
 * The meshes in the layer list have a number of associated entities like vertex maps, image clips, and textures.
 * APIs are provided to access these entities, presumable as the appropriate COM objects.
 * The list of vert. maps present in the active and background layers can be accessed using these methods.
 * Multiple VMaps with the same name and type are represented as a single entry.
 * 
 * 
 * - LayerVMapCount()
 * Return the number of vertex maps. If type is non-NULL, only maps of that type will be included.
 * - LayerVMap()
 * Return the vertex maps at 'index'. If type is non-NULL, only maps of that type will be considered.
 * 
 * Similar methods provide access to the Clips and Textures used by
 * 
 * 
 * - LayerMaterialCount()
 * Returns the number of materials in the active layers.
 * - LayerMaterial()
 * Returns the material item (ILxItem) at the given index in the list of materials in the active layers.
 * 
 * - LayerClipCount()
 * Returns the number of clips used by materials in the active layers.
 * 
 * - LayerClip()
 * Returns the clip item at the given index.
 * 
 * 
 * - LayerPartCount()
 * Returns the number of parts in the active layers.
 * - LayerPart()
 * Returns the part name at the given index.
 * 
 * Access the selection sets for items, polys, or vert/edge using types ID_ITEM, ID_POLY, or ID_VERX/ID_EDGE respectively
 * 
 * 
 * The set of texture items applied to an item, or a part thereof are
 * accessed with these functions.
 * 
 * - LayerTextureCount()
 * Return the number of textures applied to the given mesh layer.
 * - LayerTexture()
 * Returns the texture item at the given index in the list of textures applied to the specified mesh layer.
 * 
 * The set of textures applied based on a given (PART or MATR) polygon tag may
 * also be accessed.
 * 
 * 
 * Mesh elements (vertices, polygons, edges) can also retrieved, hopefully based on
 * the layer list mode as well as a marking system yet to be described...
 * 
 * - LayerVertexCount()
 * - LayerVertex()
 * - LayerPolyCount()
 * - LayerPoly()
 * 
 * - LayerEdgeCount()
 * - LayerEdge()
 * 
 * 
 * 
 * 
 * A transform scan object is allocated using the layer service. The client must also
 * pass the tool vector object which contains info about weights and axes.
 * 
 * You can also allocate a layer scan object for one mesh layer.
 * 
 * The IsProcedural function determines if a layer is procedural or not. However,
 * this function also takes the UI state into account, so if ghosting is enabled
 * in the mesh operation stack and the base mesh is selected, the function will
 * return false, even if the mesh is procedural. This is useful for setting the
 * enable and disable state of tools or commands that operate on procedural layers.
 * 
 * These functions set, clear and test for the mark used .
 * 
 * 
 * 
 * This function returns the name of the user's currently selected deformer for the mesh item
 * passed in, allowing the expected mesh to be retrieved through ILxMeshFilterIdent.  If ghosting 
 * is disabled, no deformer is currently selected, or the item passed in is not a mesh, then 
 * LXs_MESHFILTER_TOP will be returned.  If the base mesh for the given mesh item is currently selected, 
 * LXs_MESHFILTER_BASE will be returned.  Any other selection will return the identity of the 
 * currently selected deformer.
 */
typedef struct vt_ILxLayerService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
SetScene) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD(  LxResult,
Scene) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        unsigned int		*count);

        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	       **name);

        LXxMETHOD(  LxResult,
Slot) (
        LXtObjectID		 self,
        unsigned int		 index,
        int		        *slot);

        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Mesh) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		 self,
        unsigned int		 index,
        int		        *flags);

        LXxMETHOD(  LxResult,
Pivot) (
        LXtObjectID		 self,
        unsigned int		 index,
        double			*pivot);

        LXxMETHOD(  LxResult,
PatchSubdivision) (
        LXtObjectID		 self,
        unsigned int		 index,
        int			*level);

        LXxMETHOD(  LxResult,
Bounds) (
        LXtObjectID		 self,
        unsigned int		 index,
        LXtVector		 min,
        LXtVector		 max);

        LXxMETHOD(  LxResult,
CurveSmoothAngle) (
        LXtObjectID		 self,
        unsigned int		 index,
        double			*angle);

        LXxMETHOD(  LxResult,
SplinePatchSubdivision) (
        LXtObjectID		 self,
        unsigned int		 index,
        int			*level);
        LXxMETHOD(  LxResult,
ItemLookup) (
        LXtObjectID		 self,
        int 			 mode,
        LXtObjectID		 item,
        int			*index);

        LXxMETHOD(  LxResult,
NameLookup) (
        LXtObjectID		 self,
        int 			 mode,
        const char		*name,
        int			*index);
        LXxMETHOD(  LxResult,
LayerParent) (
        LXtObjectID		 self,
        int 			 index,
        int			*parentIndex);
        LXxMETHOD(  LxResult,
LayerChildCount) (
        LXtObjectID		 self,
        int 			 index,
        int			*num);

        LXxMETHOD(  LxResult,
LayerChild) (
        LXtObjectID		 self,
        int 			 index,
        int			 childNumber,
        int			*childIndex);
        LXxMETHOD(  LxResult,
LayerVMapCount) (
        LXtObjectID		 self,
        int			*num);

        LXxMETHOD(  LxResult,
LayerVMap) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
LayerClipCount) (
        LXtObjectID		 self,
        int			*num);

        LXxMETHOD(  LxResult,
LayerClip) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
LayerMaterialCount) (
        LXtObjectID		 self,
        int			*num);

        LXxMETHOD(  LxResult,
LayerMaterial) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
LayerPartCount) (
        LXtObjectID		 self,
        int			*num);

        LXxMETHOD(  LxResult,
LayerPart) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char	        **part);
        LXxMETHOD(  LxResult,
LayerSelSetCount) (
        LXtObjectID		 self,
        unsigned int		 type,
        int			*num);

        LXxMETHOD(  LxResult,
LayerSelSet) (
        LXtObjectID		 self,
        unsigned int		 type,
        unsigned int		 index,
        const char	        **selSet);
        LXxMETHOD(  LxResult,
LayerTextureCount) (
        LXtObjectID		 self,
        int			 layer,
        int			*num);

        LXxMETHOD(  LxResult,
LayerTexture) (
        LXtObjectID		 self,
        int			 layer,
        unsigned int		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
LayerTagTextureCount) (
        LXtObjectID		 self,
        int			 layer,
        unsigned int		 type,
        const char		*tag,
        int			*num);

        LXxMETHOD(  LxResult,
LayerTagTexture) (
        LXtObjectID		 self,
        int			 layer,
        unsigned int		 type,
        const char		*tag,
        unsigned int		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
LayerVertexCount) (
        LXtObjectID		 self,
        int 			 mode,
        int			*num);

        LXxMETHOD(  LxResult,
LayerVertex) (
        LXtObjectID		 self,
        int 			 mode,
        unsigned int		 index,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
LayerPolyCount) (
        LXtObjectID		 self,
        int 			 mode,
        int			*num);

        LXxMETHOD(  LxResult,
LayerPoly) (
        LXtObjectID		 self,
        int 			 mode,
        unsigned int		 index,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
LayerEdgeCount) (
        LXtObjectID		 self,
        int 			 mode,
        int			*num);

        LXxMETHOD(  LxResult,
LayerEdge) (
        LXtObjectID		 self,
        int 			 mode,
        unsigned int		 index,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
ScanAllocate) (
        LXtObjectID		 self,
        unsigned		 flags,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
CurrentMap) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		**name);
        LXxMETHOD( LxResult,
XfrmAllocate) (
        LXtObjectID		 self,
        LXtObjectID		 toolVec,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
ScanAllocateItem) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 flags,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
IsProcedural) (
        LXtObjectID		 self,
        unsigned int		 index);
        LXxMETHOD(  LxResult,
SetMark) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD(  LxResult,
ClearMark) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD(  int,
TestMark) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD(  LxResult,
CurrentDeformer) (
        LXtObjectID		 self,
        LXtObjectID		 meshItem,
        const char		**name);
} ILxLayerService;

/*
 * Called at the end of an edit operation, Apply() performs all the mesh edits and
 * terminates the scan. If this is not called for an edit scan any edits will be
 * abandonded.
 * 
 * Get the number of layers in the scan.
 * 
 * Query the state of a given layer. The state is a combination of the ACTIVE, BACKGROUND
 * or PRIMARY layer scan flags.
 * 
 * Each layer is associated with a mesh item. The client can also get the action for the
 * item to read channel values.
 * 
 * Clients can access the mesh in one of three forms. The "base" mesh is the mesh as stored
 * in the scene. The "instance" mesh is the same mesh but deformed by the currently selected
 * modeling morph. The "edit" mesh is the same mesh again, but allowing modifications. This
 * version is only available if the WRITEMESH flag was set.
 * 
 * The layer scan client is responsible for indicating what types of changes they are
 * making to a mesh. The mesh change bit mask should be set for all edited meshes before
 * changes are applied.
 * 
 * Called at intermediate points of an edit operation, Update() performs the mesh edits,
 * but does not terminate the scan.
 * 
 * Clients can access the mesh item transforms using this function. It returns a Matrix4
 * representing the world transform of the mesh item.
 */
typedef struct vt_ILxLayerScan {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Apply) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Count) (
        LXtObjectID		 self,
        unsigned		*count);
        LXxMETHOD( LxResult,
GetState) (
        LXtObjectID		 self,
        unsigned		 index,
        unsigned		*state);
        LXxMETHOD( LxResult,
MeshItem) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
MeshAction) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
MeshBase) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
MeshInstance) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
MeshEdit) (
        LXtObjectID		 self,
        unsigned		 index,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
SetMeshChange) (
        LXtObjectID		 self,
        unsigned		 index,
        unsigned int		 edits);
        LXxMETHOD( LxResult,
Update) (
        LXtObjectID		 self);
        LXxMETHOD ( LxResult,
MeshTransform) (
        LXtObjectID		 self,
        unsigned		 index,
        LXtMatrix4		 matrix);
} ILxLayerScan;

/*
 * The transform scan interface is also for editing, but is specifically for use
 * in tools which perform transformations. The encapsulates all the different element
 * types -- meshes, items, pivots, etc. -- as well as some tricky elements of the
 * tool pipe like per-element centers and axes.
 * The client passes a visitor to enumerate over all the elements to transform,
 * and will be called back for each one in sequence. The flags method can read out
 * the properties of the current element.
 * 
 * 
 * The main function of the transform is to read the current position and write a
 * new one.
 * 
 * The methods allow values to be read for per-element properties indicated by the
 * flags.
 */
typedef struct vt_ILxTransformScan {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Enumerate) (
        LXtObjectID		 self,
        LXtObjectID		 visitor);

        LXxMETHOD( unsigned int,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD( const float *,
Position) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
SetPosition) (
        LXtObjectID		 self,
        LXtFVector		 pos);
        LXxMETHOD( double,
Weight) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
AlternateCenter) (
        LXtObjectID		 self,
        LXtFVector		 center);

        LXxMETHOD( LxResult,
AlternateAxis) (
        LXtObjectID		 self,
        LXtMatrix		 matrix,
        LXtMatrix		 inverse);
} ILxTransformScan;

/*
 * The Scene1Service interface is obsolete. There is a new one with more and better
 * methods, and these methods have been moved to ILxTransform.
 */
typedef struct vt_ILxScene1Service {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
ItemWorldTransform) (
        LXtObjectID		 self,
        LXtObjectID		 locator,
        double			 time,
        LXtMatrix		 xfrm,
        LXtVector		 pos);

        LXxMETHOD(  LxResult,
ItemWorldRotation) (
        LXtObjectID		 self,
        LXtObjectID		 locator,
        double			 time,
        LXtMatrix		 xfrm);
} ILxScene1Service;

/*
 * A portion of the Layer API is wrapped as a Global Service object.
 */

        #define LXu_LAYERSERVICE	"F12B06AA-BF92-4585-800E-45AB99D47A20"
        #define LXa_LAYERSERVICE	"layerservice"
        // [python] ILxLayerService:Item		obj Item
        // [python] ILxLayerService:LayerClip		obj Item
        // [python] ILxLayerService:LayerEdge		obj Unknown
        // [python] ILxLayerService:LayerMaterial	obj Item
        // [python] ILxLayerService:LayerPoly		obj Unknown
        // [python] ILxLayerService:LayerTagTexture	obj Item
        // [python] ILxLayerService:LayerTexture	obj Item
        // [python] ILxLayerService:LayerVMap		obj Unknown
        // [python] ILxLayerService:LayerVertex		obj Unknown
        // [python] ILxLayerService:Mesh		obj Mesh
        // [python] ILxLayerService:ScanAllocate	obj LayerScan
        // [python] ILxLayerService:ScanAllocateItem	obj LayerScan
        // [python] ILxLayerService:Scene		obj Scene
        // [python] ILxLayerService:XfrmAllocate	obj TransformScan

/*
 * - SetScene()
 * This function must be called to initialize the Layer Service Object and set the scene.
 * The argument 'scene' should be an ILxScene1 object, or NULL to use the currently selected scene.
 * - Scene()
 * This function returns the ILxScene1 currently set. It should be released by the client.
 * 
 * Layer elements (items) can be accessed in lists based on their selection and
 * foreground state, as specified by the following modes:
 * 
 */

        #define LXi_LAYER_PRIMARY		0
        #define LXi_LAYER_FOREGROUND		1
        #define LXi_LAYER_BACKGROUND		2
        #define LXi_LAYER_ALL			3

/*
 * - Count()
 * This function returns the number of layers in the list.
 * - Name()
 * Return the name of the layer in the list at the given index.
 * - Slot()
 * Return the UI slot number of the layer in the list at the given index.
 * 
 * - Item()
 * Return the item in the list at the given index.  It is
 * the client's responsibility to release this object.
 * 
 * - Mesh()
 * Return the ILxMesh in the list at the given index.  It is
 * the client's responsibility to release this object.
 * 
 * - Flags
 * Returns the layer flags, used to determine whether a layer is in foreground,
 * background, is main, or none of those.
 * 
 */

        #define LXf_LAYER_FOREGROUND		1
        #define LXf_LAYER_BACKGROUND		2
        #define LXf_LAYER_MAIN			4

/*
 * The LayerScan interface is the main way to do mesh edits. It can also be used in a
 * non-edit mode to confirm what will happen when editing.
 */

        #define LXu_LAYERSCAN	"097DB669-91C3-11D9-8EA2-000A956C2E10"
        #define LXa_LAYERSCAN	"layerscan"
        // [local]  ILxLayerScan
        // [python] ILxLayerScan:MeshAction	obj ChannelRead
        // [python] ILxLayerScan:MeshBase	obj Mesh
        // [python] ILxLayerScan:MeshEdit	obj Mesh
        // [python] ILxLayerScan:MeshInstance	obj Mesh
        // [python] ILxLayerScan:MeshItem	obj Item
        // [const]  ILxLayerScan:MeshTransform

/*
 * Flags select the layers to be processed: ACTIVE is all current meshes; BACKGROUND is
 * all visible but inactive meshes; PRIMARY is the one main selected mesh. The marking
 * flags will mark the various element types as selected. So if MARKVERTS is set, for
 * example, all selected vertices will have the "select" mark mode set. As always if
 * no vertices are selected all will be marked.
 * Set WRITEMESH to enable layer edits.
 */

        #define LXf_LAYERSCAN_ACTIVE		 0x001
        #define LXf_LAYERSCAN_BACKGROUND	 0x002
        #define LXf_LAYERSCAN_PRIMARY		 0x004
        #define LXf_LAYERSCAN_ALL		(LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_BACKGROUND)

        #define LXf_LAYERSCAN_MARKVERTS		 0x010
        #define LXf_LAYERSCAN_MARKEDGES		 0x020
        #define LXf_LAYERSCAN_MARKPOLYS		 0x040
        #define LXf_LAYERSCAN_MARKDVRTS		 0x080
        #define LXf_LAYERSCAN_MARKALL		(LXf_LAYERSCAN_MARKVERTS | LXf_LAYERSCAN_MARKEDGES | LXf_LAYERSCAN_MARKPOLYS | LXf_LAYERSCAN_MARKDVRTS)

        #define LXf_LAYERSCAN_WRITEMESH		 0x100

        #define LXf_LAYERSCAN_EDIT		(LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKALL)
        #define LXf_LAYERSCAN_EDIT_POLYS	(LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKPOLYS)
        #define LXf_LAYERSCAN_EDIT_VERTS	(LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKVERTS)
        #define LXf_LAYERSCAN_EDIT_EDGES	(LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKEDGES)
        #define LXf_LAYERSCAN_EDIT_DVRTS	(LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKDVRTS)
        #define LXf_LAYERSCAN_EDIT_POLVRT	(LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKPOLYS | LXf_LAYERSCAN_MARKVERTS)

/*
 * The flag bits determine which properties apply to the current element. If the
 * weight is not set it can be assumed to be unity.
 */

        #define LXfXFRMSCAN_WEIGHT	 0x01
        #define LXfXFRMSCAN_ALTCENTER	 0x02
        #define LXfXFRMSCAN_ALTAXIS	 0x04


        #define LXu_TRANSFORMSCAN	"6DD4BC9B-BEDC-46B9-B5AC-850A06AD5EEB"
        // [local] ILxTransformScan


        #define LXu_SCENE1SERVICE	"11D99CDC-F662-40FF-9AC3-B76E59C8DEB0"
        #define LXa_SCENE1SERVICE	"sceneservice"

#endif
