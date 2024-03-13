/*
 * LX predest module
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
#ifndef LX_predest_H
#define LX_predest_H

typedef struct vt_ILxShaderPreDest ** ILxShaderPreDestID;
typedef struct vt_ILxMeshLayerPreDest ** ILxMeshLayerPreDestID;
typedef struct vt_ILxSceneItemPreDest ** ILxSceneItemPreDestID;
typedef struct vt_ILxProfile1DPreDest ** ILxProfile1DPreDestID;
typedef struct vt_ILxProfile1DPreDest1 ** ILxProfile1DPreDest1ID;
typedef struct vt_ILxProfile2DPreDest ** ILxProfile2DPreDestID;
typedef struct vt_ILxProfile2DPreDest1 ** ILxProfile2DPreDest1ID;
typedef struct vt_ILxColorPreDest ** ILxColorPreDestID;
typedef struct vt_ILxPresetDestinationService ** ILxPresetDestinationServiceID;

#include <lxcom.h>
#include <lxresult.h>
#include <lxvalue.h>
#include <lxvector.h>
#include <lxitem.h>
#include <lxmesh.h>



/*
 * The shader preset may need a scene to load into, if it was no item is directly applicable.
 * In this case, the contents of the preset will simply be added to the scene.
 * The destination item will 'receive' the preset, and either have some channels changed,
 * or have some items added as children, or possibly, have its children all killed, and replaced
 * by new children that it must love just as much.  The mode argument gives the loader's Apply
 * method a hint about how to treat the destination content.
 * 
 * This method returns the parent or container for the the destination item. In most cases,
 * this is simply the scene's render item, and if this method returns NOT_IMPLEMENTED, the client
 * can just find the first render item in the scene, as so much other code does.
 * It will often be useful however, to provide a container group for the preset.
 * In the case of a material preset, this could specify the group into which the material
 * should be added, (though the Item should have returned a material in this group...).
 * For a group preset, the group would be added inside the container, which will let a preset
 * import be encapsulated by the client.
 * 
 * This method returns the geometry item the preset was dropped on.
 * This may be NULL if the preset wasn't dropped on actual geometry.
 * 
 * This method allows the client to read tags defining the surface being shaded. This
 * can be useful for positioning some more complex shading presets.
 * 
 * This method returns the preset mode either add or apply.
 */
typedef struct vt_ILxShaderPreDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Scene) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Item) (
        LXtObjectID		  self,
        int			 *mode,
        void			**ppvObj);
        LXxMETHOD( LxResult,
ContainerItem) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
HitItem) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
GetTag) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char	       **tag);
        LXxMETHOD( LxResult,
Mode) (
        LXtObjectID		 self,
        int			*mode);
} ILxShaderPreDest;

/*
 * The mesh layer preset needs an existing mesh to load into (what else?).
 * This method returns the destination mesh. It may be a current user mesh, or
 * it may be a newly created 'template' mesh which will then be used like a BG layer
 * for cloning, booleans, etc.
 * 
 * For false convenience, and to adhere to the fascination with bloated, lossy homogeneous matrices
 * for passing transformations around, the desired transformation of the mesh elements as they are
 * placed in the mesh is returned in an LXtMatrix4 by this function. If this function returns not
 * implemented, no transformation is applied.
 * 
 * To facilitate the loading of a mesh layer's various shader tree components, we will simply
 * demand a shader tree destination object.
 */
typedef struct vt_ILxMeshLayerPreDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Mesh) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Transform) (
        LXtObjectID		 self,
        LXtMatrix4		 xform);
        LXxMETHOD( LxResult,
ShaderDest) (
        LXtObjectID		  self,
        void			**ppvObj);
} ILxMeshLayerPreDest;

/*
 * Return the ILxScene
 * 
 * This is the target item, presumably the same type as the preset, that will have channels replaced
 * by the incoming item's channels.. or whatever.  It can be null to just add a new item from the preset
 * to the scene.
 * 
 * This method returns the parent or container for the the destination item.
 * 
 * This method returns a position at which to place the item, if it has been set, or LXe_FAIL otherwise
 * 
 * This method returns an orientation for the item, if it has been set, or LXe_FAIL otherwise.
 * The orientation is stored in a matrix to assure that no useful information can be retrieved from it and
 * rotations are clipped to 1 cycle.
 */
typedef struct vt_ILxSceneItemPreDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Scene) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Item) (
        LXtObjectID		  self,
        int			 *mode,
        void			**ppvObj);
        LXxMETHOD( LxResult,
ContainerItem) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Position) (
        LXtObjectID		  self,
        LXtVector		  pos);
        LXxMETHOD( LxResult,
Orientation) (
        LXtObjectID		  self,
        LXtMatrix		  xfrm);
} ILxSceneItemPreDest;

/*
 * 1D profile is a single path consist of lines and cubic bezier curves and
 * it would be used for a parametric function to modulate a scale parameter
 * along a path in modeling tools such as tube, sketch extrude and path step
 * generator. The 1D profile would be also worked with lathe tool as a source
 * profile curve.
 * The following are methods to build an open path. "MoveTo" sets the start
 * position. "LineTo" makes a segment line with the last position and the
 * given position. "CurveTo" defines a cubic bezier curve.
 * 
 * 
 * 
 * 
 * "Evaluate" method returns X or Y value at position 't' along the path.
 * If 'NORMALIZE' is set, it returns the normalized value between 0 and 1.
 * If 'RESETZERO' is set, the origin is reset to the minimum of the bbox.
 * 
 * "PathSteps" generates all freezed positions and it returns the number
 * of steps. "tol" is allowable maximum height when the function subdivides
 * bezier curve to polyline. If "nstep" is zero, it returns only returns
 * the best number of steps with the given tolerance.
 * 
 * "Box" method sets the bounding box on the profile space.
 * 
 * 
 * "Count" method returns the number of profile in the packet.
 * 
 * 
 * "SelectByIndex" method sets the current profile to generate by "PathSteps" by
 * index. The index must be between 0 to count-1.
 * 
 * 
 * "SelectByParameter" method sets the current profile to generate by "PathSteps" by
 * parameter value between 0.0 to 1.0."PathSteps" generates an interpolated x and
 * y positions at 't'.
 * 
 * 
 * "SelectByVertex" method sets the current profile to generate by "PathSteps" for
 * the given vertex.
 */
typedef struct vt_ILxProfile1DPreDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
MoveTo) (
        LXtObjectID		 self,
        double			 x,
        double			 y);
        LXxMETHOD( LxResult,
LineTo) (
        LXtObjectID		 self,
        double			 x,
        double			 y);
        LXxMETHOD( LxResult,
CurveTo) (
        LXtObjectID		 self,
        double			 x0,
        double			 y0,
        double			 x1,
        double			 y1,
        double			 x2,
        double			 y2);
        LXxMETHOD( double,
Evaluate) (
        LXtObjectID		 self,
        double			 t,
        int			 flags,
        int			 axis);
        LXxMETHOD( int,
PathSteps) (
        LXtObjectID		 self,
        double			 tol,
        int			 flags,
        double			*x,
        double			*y,
        int			 nstep);
        LXxMETHOD( LxResult,
Box) (
        LXtObjectID		 self,
        LXtBBox			*box);
        LXxMETHOD( unsigned,
Count) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SelectByIndex) (
        LXtObjectID		 self,
        unsigned		 index);
        LXxMETHOD( LxResult,
SelectByParameter) (
        LXtObjectID		 self,
        double			 t);
        LXxMETHOD( LxResult,
SelectByVertex) (
        LXtObjectID		 self,
        LXtMeshID		 meshID,
        LXtPointID               pointID);
} ILxProfile1DPreDest;

typedef struct vt_ILxProfile1DPreDest1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
MoveTo) (
        LXtObjectID		 self,
        double			 x,
        double			 y);

        LXxMETHOD( LxResult,
LineTo) (
        LXtObjectID		 self,
        double			 x,
        double			 y);

        LXxMETHOD( LxResult,
CurveTo) (
        LXtObjectID		 self,
        double			 x0,
        double			 y0,
        double			 x1,
        double			 y1,
        double			 x2,
        double			 y2);

        LXxMETHOD( double,
Evaluate) (
        LXtObjectID		 self,
        double			 t,
        int			 flags,
        int			 axis);

        LXxMETHOD( int,
PathSteps) (
        LXtObjectID		 self,
        double			 tol,
        int			 flags,
        double			*x,
        double			*y,
        int			 nstep);

        LXxMETHOD( LxResult,
Box) (
        LXtObjectID		 self,
        LXtBBox			*box);
} ILxProfile1DPreDest1;

/*
 * 2D profile is a 2-dimentional pattern shape consist of lines and cubic
 * bezier curves. This profile would be useful when it is used with sweep
 * tools.
 * The following are methods to build an open path. "MoveTo" sets the start
 * position. "LineTo" makes a segment line with the last position and the
 * given position. "CurveTo" defines a cubic bezier curve.
 * 
 * 
 * 
 * "NewPath" starts a new profile in the object. 2D profile allows to have
 * multiple pathes.
 * 
 * Set closed flag to the current path. The default is true.
 * 
 * "Box" method sets the bounding box on the profile space.
 * 
 * 
 * "Count" method returns the number of profile in the packet.
 * 
 * 
 * "SelectByIndex" method sets the current profile to generate by "PathSteps" by
 * index. The index must be between 0 to count-1.
 * 
 */
typedef struct vt_ILxProfile2DPreDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
MoveTo) (
        LXtObjectID		 self,
        double			 x,
        double			 y);
        LXxMETHOD( LxResult,
LineTo) (
        LXtObjectID		 self,
        double			 x,
        double			 y);
        LXxMETHOD( LxResult,
CurveTo) (
        LXtObjectID		 self,
        double			 x0,
        double			 y0,
        double			 x1,
        double			 y1,
        double			 x2,
        double			 y2);
        LXxMETHOD( LxResult,
NewPath) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Closed) (
        LXtObjectID		 self,
        int			 closed);
        LXxMETHOD( LxResult,
Box) (
        LXtObjectID		 self,
        LXtBBox			*box);
        LXxMETHOD( unsigned,
Count) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SelectByIndex) (
        LXtObjectID		 self,
        unsigned		 index);
} ILxProfile2DPreDest;

typedef struct vt_ILxProfile2DPreDest1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
MoveTo) (
        LXtObjectID		 self,
        double			 x,
        double			 y);

        LXxMETHOD( LxResult,
LineTo) (
        LXtObjectID		 self,
        double			 x,
        double			 y);

        LXxMETHOD( LxResult,
CurveTo) (
        LXtObjectID		 self,
        double			 x0,
        double			 y0,
        double			 x1,
        double			 y1,
        double			 x2,
        double			 y2);

        LXxMETHOD( LxResult,
NewPath) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Closed) (
        LXtObjectID		 self,
        int			 closed);

        LXxMETHOD( LxResult,
Box) (
        LXtObjectID		 self,
        LXtBBox			*box);
} ILxProfile2DPreDest1;

/*
 * This method is called by the preset server to set the HDR RGB color on the destination.
 * If this method fails, Apply() will not be called.
 * Colors should always be set in linear space.
 * 
 * 
 * This optional method sets the name of the color model server that the color was originally
 * saved in, as well as the color in the model's space.  Only color pickers generally care
 * about this.
 * 
 * SetColor() will always be called, but SetColorModel() may not be.  Once set, the preset
 * loader will call Apply() so that the destination can perform its specific apply of the
 * color to the target, preferably through a command (to ensure that it is undable and
 * scriptable).
 */
typedef struct vt_ILxColorPreDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetColor) (
        LXtObjectID		 self,
        const LXtVector		 rgb);
        LXxMETHOD( LxResult,
SetColorModel) (
        LXtObjectID		 self,
        const char		*name,
        const double		*vec);
        LXxMETHOD( LxResult,
Apply) (
        LXtObjectID		 self);
} ILxColorPreDest;

/*
 * Various preset destination objects can be allocated
 * through the SDK.
 * - ShaderPDFromItem
 * A ShaderPreDest object can be created from a material
 * group item in the scene.
 * - CreateMeshLayerPD
 * A MeshLayerPreDest object can be created from a mesh.  The
 * optional shadeItem is a material group where any loaded
 * materials will be applied.
 * - Profile1DPDFromPath
 * A Profile1DPreDest object can be created from a filepath
 * pointing to a valid 1D profile preset.
 * 
 * - Profile2DPDFromPath
 * A Profile2DPreDest object can be created from a filepath
 * pointing to a valid 2D profile preset.
 * 
 * 
 * 
 * Some Preset Destination items can be applied 
 * programmatically as well.
 * This function makes mesh elements from the preset. If 'freeze' is on,
 * it converts the preset to face polygons. If 'center' is NULL, the shape
 * center will be located in the raw position of the file. 'tol' is the
 * tolerance to subdive curve. If 'tol' is zero, this subdivide curves based
 * on curve display level. "metrics" stores optional data to transform
 * the profile.
 * 
 * - ApplyProfilePDToMesh
 * A ProfilePreDest object can be loaded into an existing mesh.
 * It requires setting a distance tolerance for subdividing the profile curves,
 * a freeze boolean to force convert the shape into face polygons, and integer
 * representing the plane axis (0,1,2 for x,y,z) to load the preset on, and the
 * editable mesh to load the preset shape into.
 * 
 * #item ApplyMeshPresetToMeshPD
 * A MeshLayerPreDest object can have a mesh preset loaded into it.
 * 
 */
typedef struct vt_ILxPresetDestinationService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ShaderPDFromItem) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        void			**ppvObj);
        
        LXxMETHOD(  LxResult,
CreateMeshLayerPD) (
        LXtObjectID		 self,
        LXtObjectID		 mesh,
        LXtObjectID		 shadeItem,
        void			**ppvObj);
        
        LXxMETHOD(  LxResult,
Profile1DPDFromPath) (
        LXtObjectID		 self,
        const char		*filepath,
        void			**ppvObj);
        
        LXxMETHOD(  LxResult,
Profile2DPDFromPath) (
        LXtObjectID		 self,
        const char		*filepath,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ApplyProfilePDToMesh) (
        LXtObjectID		 self,
        LXtObjectID		 predest,
        double			 tolerance,
        int			 freeze,
        int			 axis,
        LXtObjectID		 mesh);

        LXxMETHOD(  LxResult,
ApplyMeshPresetToMeshPD) (
        LXtObjectID		 self,
        LXtObjectID		 predest,
        const char		*filepath);
} ILxPresetDestinationService;

/*
 * Item presets are .LXP (IFF LXPR) files that require a destination item and/or scene
 * to apply themselves, usually somewhere in a shader tree. The presets store a primary
 * item, and possibly also linked or child items. Their destination requirements are
 * identified based on the type of the primary item, which will typically be a material
 * item, or a group/mask item with material, texture(s), etc.
 */

        #define LXu_SHADERPREDEST		"51CE68B9-BDED-41FC-BD33-37BBAFFD180B"
        #define LXa_SHADERPREDEST		"shaderPresetDestination"
        // [local]  ILxShaderPreDest
        // [export] ILxShaderPreDest spd
        // [python] ILxShaderPreDest:ContainerItem	obj Item
        // [python] ILxShaderPreDest:HitItem		obj Item
        // [python] ILxShaderPreDest:Item		obj Item
        // [python] ILxShaderPreDest:Scene		obj Scene

/*
 * At this point the vague consensus serving as a design indicates mesh presets will be
 * single layer mesh information, along with the necessary materials. (we will ignore for
 * a moment the completely open-ended nature of this requirement, given the potential
 * dependency of shading a single poly on the entire scene graph.)
 * All that we need for a mesh preset destination, besides a potentially infinite
 * bit of the shader tree, is a mesh. While it has been suggested that the destination
 * should also supply a transformation for the mesh elements, this does not make sense in
 * the driving scenario of meshpaint, since each painted mesh will need a different transform.
 * If the transform is built into the destination, it implies that each painted clone will be
 * reloaded from disk individually. Further, existing tools that use mesh layers (booleans, meshpaint, etc)
 * expect to work with a source mesh, and little else.  Nevertheless, a transform may be specified, for a
 * initial transformation. Clients which will be duplicating the mesh with different transforms are
 * expected to hold the mesh themselves, rather than reloading it, and transform the copies as needed.
 */

        #define LXu_MESHLAYERPREDEST	"052B08CD-F2F2-4C0F-9D32-1AAFEF494D36"
        #define LXa_MESHLAYERPREDEST	"meshPresetDestination"
        // [local]  ILxMeshLayerPreDest
        // [export] ILxMeshLayerPreDest mlpd
        // [python] ILxMeshLayerPreDest:Mesh		obj Mesh
        // [python] ILxMeshLayerPreDest:ShaderDest	obj ShaderPreDest


#define 	LXSHPRE_MODEi_ADD 	0
#define 	LXSHPRE_MODEi_APPLY 1
#define		LXSHPRE_MODEi_REF	2

/*
 * Destination requirements for a general item preset seem, based on the current vague consensus
 * of what an item preset does, to be similar to tha shader destination; there is possibly a target item,
 * or there might be an item that should become the parent, and there is almost certainly a scene. Thus for
 * efficiency we can start of with an identical interface, and see where it goes as requirements are first
 * defined then refined.
 */

        #define LXu_SCENEITEMPREDEST		"F81AD9DB-6068-4782-B1BB-7F45233682DC"
        #define LXa_SCENEITEMPREDEST		"sceneItemPresetDestination"
        // [local]  ILxSceneItemPreDest
        // [export] ILxSceneItemPreDest sipd
        // [python] ILxSceneItemPreDest:ContainerItem	obj Item
        // [python] ILxSceneItemPreDest:Item		obj Item
        // [python] ILxSceneItemPreDest:Scene		obj Scene


        #define LXu_PHOTOMETRYPREDEST		"C64CB56A-16EA-4B4D-96EC-B6911459103A"
        #define LXa_PHOTOMETRYPREDEST		"photometryPresetDestination"

/*
 * Profile presets store a geometry pattern used with modeling tools. There
 * are two types of profile.
 */

        #define LXu_PROFILE1DPREDEST		"66879EE7-45AE-4704-8E03-19F998EFDE73"
        #define LXa_PROFILE1DPREDEST		"profile1DPresetDestination2"
        // [local]  ILxProfile1DPreDest
        // [export] ILxProfile1DPreDest p1pd
        // [python] ILxProfile1DPreDest:PathSteps:x	vector
        // [python] ILxProfile1DPreDest:PathSteps:y	vector

        #define LXu_PROFILE2DPREDEST		"449009ED-847D-4925-94BC-C5E8ECCAD515"
        #define LXa_PROFILE2DPREDEST		"profile2DPresetDestination2"
        // [local]  ILxProfile2DPreDest
        // [export] ILxProfile2DPreDest p2pd


        #define 	LXPROFILEf_NORMALIZE 	0x1
        #define 	LXPROFILEf_RESETZERO 	0x2
        #define 	LXPROFILEf_BLENDING 	0x4

/*
 * This interface was retired in modo 10.1, and was replaced with an updated one
 * that adds a method for multiple profile support.
 */

        #define LXu_PROFILE1DPREDEST1		"A4E5FAD3-E3A7-4ed9-A1E3-4EB0D31A4187"
        #define LXa_PROFILE1DPREDEST1		"profile1DPresetDestination"
        // [local]  ILxProfile1DPreDest1
        // [export] ILxProfile1DPreDest1 p1pd

/*
 * This interface was retired in modo 10.1, and was replaced with an updated one
 * that adds a method for multiple profile support.
 */

        #define LXu_PROFILE2DPREDEST1		"F845F4AD-7DFC-4a41-98D1-0FFB2CA744FB"
        #define LXa_PROFILE2DPREDEST1		"profile2DPresetDestination"

/*
 * The color preset destination is used to apply color presets to a target.  Due to the
 * various ways that colors can be used, we let the destination decide how to actually
 * perform the apply.
 * The destination works by the preset loader calling its various methods to set up state,
 * followed by the Apply() method.  Appy() should execute a command (thus ensuring it is
 * undoable) that actually applies the contents of the object to the desired target.
 */

        #define LXu_COLORPREDEST		"307b5aab-f8df-4c5b-b916-223172ea921e"
        #define LXa_COLORPREDEST		"colorPresetDestination"
        //[local]  ILxColorPreDest
        //[export] ILxColorPreDest colpd

/*
 * The preset destination service provides utilities for allocating preset destination objects.
 */

        #define LXa_PRESETDESTINATIONSERVICE	"presetdestinationservice"
        #define LXu_PRESETDESTINATIONSERVICE	"A4305404-7D11-4A9F-B869-F57861CE1D4D"

        // [python] ILxPresetDestinationService:ProfilePreDestToMesh obj Mesh
        // [python] ILxPresetDestinationService:MeshLayerPreDestToMesh obj Mesh

/*
 * Brush Tool presets have no destination object, because they apply their embedded ToolPreset
 * directly to the global toolpipe using the tpipe.qq API. Nevertheless, these guys need their own unique GUIDs,
 * since they could also be recognized for the images they are (they are PNG files with a toolpreset config snippet
 * in comment metadata) which can lead to confusion.
 */

        #define LXu_BRUSHTOOLPRESET		"D03E22CE-970E-4CC1-BF76-A74639624647"
        #define LXa_BRUSHTOOLPRESET		"brushToolPreset"

#endif
