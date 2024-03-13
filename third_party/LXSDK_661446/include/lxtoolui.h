/*
 * LX toolui module
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
#ifndef LX_toolui_H
#define LX_toolui_H

typedef struct vt_ILxRaycastPacket ** ILxRaycastPacketID;
typedef struct vt_ILxRaycastPacket1 ** ILxRaycastPacket1ID;
typedef struct vt_ILxRaycastPacket2 ** ILxRaycastPacket2ID;
typedef struct vt_ILxPaintBrushPacket ** ILxPaintBrushPacketID;
typedef struct vt_ILxPaintInkPacket ** ILxPaintInkPacketID;
typedef struct vt_ILxPaintNozzlePacket ** ILxPaintNozzlePacketID;
typedef struct vt_ILxItemReplacement1 ** ILxItemReplacement1ID;
typedef struct vt_ILxItemReplacement ** ILxItemReplacementID;

#include <lxcom.h>
#include <lxvalue.h>
#include <lxvector.h>
#include <lximage.h>
#include <lxmesh.h>
#include <lxtool.h>


/*
 * The 'type' is the viewport type on the mouse down event position.
 * 'viewProjection' is the AGLViewType() one of the LXiVIEWv_xxx
 */
typedef struct st_LXpToolViewEvent {
        struct st_Viewport      *vport;
        struct st_AGLView       *view;
        unsigned		 flags;
        unsigned		 type;
        unsigned		 vportType;
        unsigned		 viewProjection;
} LXpToolViewEvent;

/*
 * The 3D event packet has four sets of coordinates: v0 is the down event position
 * and dv is the vector for from v0 to the current 3D event as it is updated
 * during move events.  The read-only rv0 and rdv vectors are the raw vectors fed
 * into the event pipeline, untouched by other tools.
 * This packet is only valid in the context of a stroke list.  Primary 3D event
 * information should be calculated using the EventTranslation object.
 */
typedef struct st_LXpTool3DEvent {
        LXtVector		 v0, dv;
        LXtVector		 rv0, rdv;
} LXpTool3DEvent;

typedef struct st_LXpToolScreenEvent {
        int		 px, py;
        int		 cx, cy;
        float		 fpx, fpy;
        float		 fcx, fcy;
//	ViewportPointer3D	*pointer3D;
        void	*pointer3D;
        LXtVector	 ppos, pdir;
} LXpToolScreenEvent;

typedef struct st_LXpToolInputEvent {
        int		 mode;				// Appears to be the modifier keys, in non-SDK-friendly defines
        int		 input;				// LXiTIE_ define indicating the user-remappable input event
        int		 count;				// 1 for single click, 2 for double click
        int		 part;				// Tool-defined part, or INVIS for clicks elsewhere
        int		 type;				// LXiTIE_TYPE_ define indicating if this is a down/move/up event or none
        int		 haul;				// True when attribute hauling is happening
} LXpToolInputEvent;

/*
 * Tools which can do something useful with tablets can request the tablet
 * event packet.  This is the information from the tablet device about the
 * current event (or the event along the stroke).  The packet will contain
 * default values if the input comes from a mouse or from some other device
 * that does not support all the inputs.  You can also see if the tablet even
 * exists and if the tablet is in use or not (if not in use, default mouse
 * values will be set for the other parameters)
 */
typedef struct st_LXpToolTabletEvent {
        int			 exists;
        int			 inUse;

        double			 normal;
        double			 tangent;
        double			 tilt[2];
        double			 twist;
} LXpToolTabletEvent;

/*
 * Tools can work with colors, the color packet can be used to set the foreground and
 * background colors which can be shared by tools in the pipe.
 */
typedef struct st_LXpToolColor {
        float		 fg[4];
        float		 bg[4];
} LXpToolColor;

/*
 * - HitPolygon
 * - HitEdge
 * - HitVertex
 * - HitItem
 * These methods perform ray casting looking for an element of the given type.
 * If none is found under the screen coord.s given, it returns 0. The different 'hit'
 * types encode information gleaned from the hit.  All have the element ID and 3D position.
 * Polygons have a normal (the interpolated normal from the limit surface) and UV
 * coordinates for the selected UV map.  Edges have the fraction from the A to B vertex
 * for the edge. The 'nrm' member of the HitItem structure is only set if the item is
 * a surface item, in which case the 'isMesh' member will be set to true.
 * 'layer' select the layers to be processed: ACTIVE is all current meshes; INACTIVE is
 * all visible but inactive meshes.
 * !!!N.B. the use of opaque LXtPolygonID type pointers may be limiting compared to delivering an ILxMesh
 * and LXtMeshPolyInfo, or the mesh and ID, given that a lookup method is added to the mesh.
 * 
 */
typedef struct st_LXtHitPolygon {
        LXtPolygonID		 pol;
        LXtVector		 pos;
        LXtVector		 nrm;
        float			 uv[2];
        float			 cosine;
        float			 disp;
        LXtObjectID		 item;
        void			*mbin;
} LXtHitPolygon;

typedef struct st_LXtHitEdge {
        LXtEdgeID		 edge;
        LXtVector		 pos;
        float    		 t;
} LXtHitEdge;

typedef struct st_LXtHitVertex {
        LXtPointID		 vrt;
        LXtVector 		 pos;
} LXtHitVertex;

typedef struct st_LXpToolHitEvent {
        LXtHitPolygon		 hit;
        float			 dist;
} LXpToolHitEvent;

typedef struct st_LXtHitItem {
        LXtObjectID		 item;
        LXtVector 		 pos;
        LXtVector 		 nrm;
        int			 isMesh;
} LXtHitItem;

typedef struct st_LXtHitElement {
        LXtObjectID		 item;
        LXtObjectID		 mesh;
        int			 isUV;
        LXtID4			 type;
        LXtPointID		 vrt;
        LXtEdgeID		 edge;
        LXtPolygonID		 pol;
        LXtVector		 lPos;
        LXtVector		 wPos;
} LXtHitElement;

/*
 * The paint target is the image that is being edited (read only), the (xc,yc) coordinates
 * of the paint operation (usually the brush center) and the (xp,yp) coordinates of the
 * pixel (usually the brush's pixel coordinates in the image).
 * This packet is used by most paint tools to know what the current paint position is.
 * 'projMode' is enabled when projection painting is used.
 * 'projWidth\Height' are set with the current pane size used for projection painting.
 */
typedef struct st_LXpToolPaintTarget {
        ILxImageID		 image;
        int			 projMode, projWidth, projHeight;
        int		    	 xc, yc;
        int 	  		 xp, yp;
        float			 fxp, fyp;
} LXpToolPaintTarget;

typedef struct st_LXpToolPaintStroke {
        float		 start[2], end[2];
        float		 length;
        float		 total;
        float		 current;
        int		 align, colorEval;
} LXpToolPaintStroke;

/*
 * The paint brush is a very simple structure with a width and a height, a pointer to the
 * weight values and an optional pointer to color values.
 * - mode
 * Specifies how pixels are transferred from the brush to the canvas.
 * - stepFlags
 * Painting usually uses brush stepping to speedup painting. This is sometimes not desirable
 * though, for example when the brush is very smooth and painting on the bump channel because
 * steps become very visible. With the stepFlags the brush can activate stepping in the bump channel.
 * 'roller' should be set for 'roller' brushes.
 * The LXfPAINT_SCREEN flag is used to indicate that the positions passed to the Eval3D method are
 * in screen space.
 * 
 */
typedef struct st_LXtPaintBrush {
        int		 width, height;
        float		*wgt;
        float		*rgb;
        float		 rotation;
        int		 mode;
        int		 flags;
} LXtPaintBrush;

/*
 * The profile packet set the profile destination object of the selected
 * profile preset.
 */
typedef struct st_LXpToolProfile {
        LXtObjectID		 xobj;
        int			 dimension;
} LXpToolProfile;

typedef struct st_LXpToolImage {
        char			*path;
        int			 flags;
} LXpToolImage;

/*
 * The Snapped Element packet set the informations when element snap tool
 * made an element snapped. This is a packet to communicate element snap tools
 * and the downstream tools.
 */
typedef struct st_LXpToolSnapElement {
        LXtMeshID		 mesh;
        LXtMeshMapID		 vmap;
        LXtID4			 type;
        LXtPolygonID		 pol;
        LXtPointID		 vrt0, vrt1;
        LXtVector		 pos;
        double			 cx, cy;
        double			 dist;
        struct st_AGLView	*view;
} LXpToolSnapElement;


/*
 * To allow clients to do raycasting on the mesh, we add an object packet containing
 * a tracing interface.  The object itself encodes all the information about the
 * view mapping and active geometry.
 * - HitPolygon1
 * - HitEdge1
 * - HitVertex1
 * - HitClosest
 * 
 * New hit testing methods for vertex, edge and polygon support UV space as well as
 * 3D mesh element. When the hit position in the structure is in UV space, 'isUV' 
 * is set. The 'pol' in LXtHitElement structure is for discontinuous UV vertex or 
 * UV edge. The new structures also contain 'mesh' and 'item' members. 'type is type 
 * of hit element. LXi_VPHIT_VERT, LXi_VPHIT_EDGE or LXi_VPHIT_POLY is set.
 * 'lPos' is the hit position in local mesh space. 'wPos' is in world space.
 * 
 */
typedef struct vt_ILxRaycastPacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
HitPolygon) (
        LXtObjectID 	  	 self,
        LXtObjectID		 toolVector,
        unsigned		 layer,
        float	    		 x,
        float    		 y,
        LXtHitPolygon 		*hit);

        LXxMETHOD(  int,
HitEdge) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        unsigned		 layer,
        float	    		 x,
        float    		 y,
        LXtHitEdge   		*hit);

        LXxMETHOD(  int,
HitVertex) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        unsigned		 layer,
        float	    		 x,
        float    		 y,
        LXtHitVertex 		*hit);

        LXxMETHOD(  int,
HitItem) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        float	    		 x,
        float    		 y,
        LXtHitItem 		*hit);
        LXxMETHOD(  int,
HitPolygon1) (
        LXtObjectID 	  	 self,
        LXtObjectID		 toolVector,
        unsigned		 layer,
        float	    		 x,
        float    		 y,
        LXtHitElement 		*hit);

        LXxMETHOD(  int,
HitEdge1) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        unsigned		 layer,
        float	    		 x,
        float    		 y,
        LXtHitElement   	*hit);

        LXxMETHOD(  int,
HitVertex1) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        unsigned		 layer,
        float	    		 x,
        float    		 y,
        LXtHitElement 		*hit);

        LXxMETHOD(  int,
HitClosest) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        unsigned		 layer,
        float	    		 x,
        float    		 y,
        LXtHitElement 		*hit);

        LXxMETHOD(  int,
HitCached) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        LXtHitElement 		*hit);
} ILxRaycastPacket;

typedef struct vt_ILxRaycastPacket1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
HitPolygon) (
        LXtObjectID 	  	 self,
        LXtObjectID		 toolVector,
        float	    		 x,
        float    		 y,
        LXtHitPolygon 		*hit);

        LXxMETHOD(  int,
HitEdge) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        float	    		 x,
        float    		 y,
        LXtHitEdge   		*hit);

        LXxMETHOD(  int,
HitVertex) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        float	    		 x,
        float    		 y,
        LXtHitVertex 		*hit);

        LXxMETHOD(  int,
HitItem) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        float	    		 x,
        float    		 y,
        LXtHitItem 		*hit);
} ILxRaycastPacket1;

typedef struct vt_ILxRaycastPacket2 {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
HitPolygon) (
        LXtObjectID 	  	 self,
        LXtObjectID		 toolVector,
        unsigned		 layer,
        float	    		 x,
        float    		 y,
        LXtHitPolygon 		*hit);

        LXxMETHOD(  int,
HitEdge) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        unsigned		 layer,
        float	    		 x,
        float    		 y,
        LXtHitEdge   		*hit);

        LXxMETHOD(  int,
HitVertex) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        unsigned		 layer,
        float	    		 x,
        float    		 y,
        LXtHitVertex 		*hit);

        LXxMETHOD(  int,
HitItem) (
        LXtObjectID  		 self,
        LXtObjectID		 toolVector,
        float	    		 x,
        float    		 y,
        LXtHitItem 		*hit);
} ILxRaycastPacket2;

/*
 * - Size
 * This method returns the brush size in screen space (the size is expressed in pixels).
 * - BBox
 * This method sets the brush bounding box given the brush center in 3D space and the size multiplier.
 * Returns 0 if the brush is not 3D.
 * - Eval2D
 * This method returns a brush as a bitmap. The arguments are the toolvector, the size multiplier and the brush to set.
 * The  brush returned can be of any size though the size should be set according to the multiplier. So if the
 * tool ise set to have a 20 pixel size and the multiplier comes in as 0.5 then the brush size should be 10.
 * This function returns 0 in case of failure.
 * - Eval3D
 * For 3D brushes, this method returns the brush 'falloff' at the given position in space. If the brush also
 * defines the volume color, then 'rgba' will be set with that color.
 * 'wpos' is the wordl position
 * 'bpos' is the position in brush space.
 * 'rad'  is the brush radius.
 * 
 */
typedef struct vt_ILxPaintBrushPacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD(  float,
Size) (
        LXtObjectID		 self);

        LXxMETHOD(  int,
BBox) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        double			 size,
        LXtBBox			*bbox);

        LXxMETHOD(  int,
Eval2D) (
        LXtObjectID		 self,
        LXtObjectID		 toolVector,
        float			 multiplier,
        LXtPaintBrush	 	*brush);

        LXxMETHOD(  double,
Eval3D) (
        LXtObjectID   		 self,
        LXtObjectID		 toolVector,
        const LXtVector		 center,
        const LXtVector		 wpos,
        const LXtVector		 bpos,
        double			 rad,
        float			*rgba);
} ILxPaintBrushPacket;

/*
 * - Color
 * This method returns a color with alpha. The arguments are the toolvector,
 * the mode and the color itself as a float vector.
 * The 'mode' specifies which paint color should be used in combination
 * with the ink color. 'raw' means that the color returned is the raw image color,
 * other modes multiply the selected color with the pixel image color.
 * - Stamp
 * This method returns a stamp brush used to override the tool vector brush.
 */
typedef struct vt_ILxPaintInkPacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
Flags) (
        LXtObjectID	   	 self,
        LXtObjectID		 toolVector);

        LXxMETHOD(  int,
Color) (
        LXtObjectID   		 self,
        LXtObjectID		 toolVector,
        int			 flags,
        LXtColorRGBA		 rgba);

        LXxMETHOD(  int,
Stamp) (
        LXtObjectID   	 self,
        LXtPaintBrush	*brush);
} ILxPaintInkPacket;

/*
 * The paint nozzle is an object packet that can be used by paint tools.
 * - Paint
 * This method returns true if a paint operation should happen for the given paint
 * target.
 * - Jitter
 * This method returns a position used to paint a brush. The arguments are the toolvector, the image,
 * the brush size and the jittered brush position in the image.
 * The base paint position can be read from the paint target.
 * - Nozzle
 * The is the main method which sets the strength, size and rotation values.
 * 
 */
typedef struct vt_ILxPaintNozzlePacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
Paint) (
        LXtObjectID   	 self,
        LXtObjectID		 toolVector,
        float		 brushSize);

        LXxMETHOD(  int,
Jitter) (
        LXtObjectID   	 self,
        LXtObjectID		 toolVector,
        float		 brushSize,
        int			*xj,
        int			*yj);

        LXxMETHOD(  int,
Nozzle) (
        LXtObjectID   	 self,
        LXtObjectID		 toolVector,
        float		*strength,
        float		*size,
        float		*rotation);
} ILxPaintNozzlePacket;

typedef struct vt_ILxItemReplacement1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
ReplaceItems) (
        LXtObjectID		 self,
        LXtObjectID		 current,
        LXtObjectID		 replacement);

        LXxMETHOD( LxResult,
Types) (
        LXtObjectID		  self,
        const char		 *curType,
        const char		**repTypes);

        LXxMETHOD( LxResult,
NotifierCount) (
        LXtObjectID		 self,
        const char		*itemType,
        const char		*channelName,
        unsigned		*count);

        LXxMETHOD( LxResult,
NotifierByIndex) (
        LXtObjectID		 self,
        const char		*itemType,
        const char		*channelName,
        unsigned		 index,
        char			*buf,
        unsigned		 len);
} ILxItemReplacement1;

/*
 * The server is given an ItemCollection object with the selected items matching
 * the initial type. The server should return a new collection to replace the
 * selected items.
 * 
 * Given an item type name, this method should return the types of items that would
 * be used to replace it. It can be a list of type names separated by white space.
 * 
 * The replacement can also define additional notifiers for an item.channel using
 * the replacement. This can be useful for updating controls if graphs change that
 * define the redirection. Notifiers are given by a string containing the
 * notifier name and args.
 */
typedef struct vt_ILxItemReplacement {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
ReplaceItems) (
        LXtObjectID		 self,
        LXtObjectID		 current,
        LXtObjectID		 replacement,
        int			 targetType);
        LXxMETHOD( LxResult,
Types) (
        LXtObjectID		  self,
        const char		 *curType,
        const char		**repTypes);
        LXxMETHOD( LxResult,
NotifierCount) (
        LXtObjectID		 self,
        const char		*itemType,
        const char		*channelName,
        unsigned		*count);

        LXxMETHOD( LxResult,
NotifierByIndex) (
        LXtObjectID		 self,
        const char		*itemType,
        const char		*channelName,
        unsigned		 index,
        char			*buf,
        unsigned		 len);
} ILxItemReplacement;


        #define LXsP_TOOL_VIEW_EVENT	"ToolViewEvent"
        #define LXi_VIEWTYPE_3D		0
        #define LXi_VIEWTYPE_UV		1
        #define LXi_VIEWTYPE_2D		2


        #define LXsP_TOOL_3D_EVENT	"Tool3DEvent"


        #define LXsP_TOOL_SCREEN_EVENT	"ToolScreenEvent"

/*
 * - type
 * There are different input event types corresponding to the cases in which
 * the event function may be called.  NONE is included to allow the filter
 * method to determine if it's being called as part of drawing.
 */

        #define LXiTIE_TYPE_NONE	0
        #define LXiTIE_TYPE_DOWN	1
        #define LXiTIE_TYPE_MOVE	2
        #define LXiTIE_TYPE_UP		3

/*
 * - input
 * The inputs are classified as I0 and I1 which by default maps to the left and
 * right mouse buttons for the normal input patterns.  For the CURVE input
 * pattern we have a different set of possible input events.  Any event which
 * has no effect for a tool should revert to EDIT.
 */

        #define LXiTIE_INPUT_I0			0
        #define LXiTIE_INPUT_I1			1

        #define LXiTIE_CURVE_EDIT		2
        #define LXiTIE_CURVE_ADD		3
        #define LXiTIE_CURVE_DELETE		4
        #define LXiTIE_CURVE_DELETE_ALL		5
        #define LXiTIE_CURVE_MOVE		6
        #define LXiTIE_CURVE_MOVE_ALL		7
        #define LXiTIE_CURVE_MOVE_CONS		8
        #define LXiTIE_CURVE_MOVE_CONS_ALL	9
        #define LXiTIE_CURVE_SCALE		10
        #define LXiTIE_CURVE_SCALE_ALL		11
        #define LXiTIE_CURVE_ALT		12
        #define LXiTIE_CURVE_CLOSED		13

        #define LXiTIE_GENERAL_PRI		20
        #define LXiTIE_GENERAL_SEC		21
        #define LXiTIE_GENERAL_TER		22
        #define LXiTIE_GENERAL_PRI_ALT		23
        #define LXiTIE_GENERAL_SEC_ALT		24
        #define LXiTIE_GENERAL_TER_ALT		25
        #define LXiTIE_GENERAL_PRI_CONS		26
        #define LXiTIE_GENERAL_SEC_CONS		27
        #define LXiTIE_GENERAL_TER_CONS		28
        #define LXiTIE_GENERAL_CLICK_1		29
        #define LXiTIE_GENERAL_CLICK_2		30
        #define LXiTIE_GENERAL_PRI_ALT_CONS	32
        #define LXiTIE_GENERAL_SEC_ALT_CONS	33
        #define LXiTIE_GENERAL_TER_ALT_CONS	34

        #define LXiTIE_XFRM_DUPLICATE		31
        #define LXiTIE_XFRM_3RDDIM		35

/*
 * - haul
 * The 'haul' flag is raised when automatic attribute hauling is happening.
 */

        #define LXsP_TOOL_INPUT_EVENT	"ToolInputEvent"

/*
 * - normal
 * This is the pressure normal to the pen tip.  Defaults to 1.0.
 * - tangent
 * This is the tangent pressure, as controlled by the airbrush wheel on stylii
 * that support this.  Defaults to 0.0.
 * - tilt
 * These are the angles in radians of the pen tip relative to the tablet.
 * tilt[0] is the azimuth of the pen relative to the tablet measured clockwise.
 * Defaults to 0.0, which is a pen with the tip pointing "up" the tablet.
 * tilt[1] is the angle of deviation of the pen from vertical.  Defaults to 0.0.
 * 
 * - twist
 * Twist of the pen around its own axis in radians.  Defaults to 0.0.
 * 
 */

        #define LXsP_TOOL_TABLET_EVENT	"ToolTabletEvent"


        #define LXsP_TOOL_COLOR		"ToolColor"


    #define LXf_LAYER_ACTIVE		0x01
    #define LXf_LAYER_INACTIVE		0x02


        #define LXu_RAYCASTPACKET		"B2973789-447F-45AA-98F3-79484A3480D8"
        // [local]  ILxRaycastPacket


        #define LXsP_TOOL_RAYCAST		"ToolRaycast"

/*
 * This interface was retired in modo 701, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXu_RAYCASTPACKET1		"D622B573-2638-4A47-AD91-6BC7A6D2D30B"
        // [local]  ILxRaycastPacket1

/*
 * This interface was retired in Modo 11.1, and was replaced with an updated one
 * that adds a few more methods.
 */

        #define LXu_RAYCASTPACKET2		"4AC0C624-15EE-4BB1-91EB-CDF9395A9193"
        // [local]  ILxRaycastPacket2

/*
 * When a tool asks for this in its vector type, the 3D view traces the polygon
 * under the mouse at each event, filling in the hit info in the packet.
 * The 'dist' is the distance from the default eye 'pos' for the event ray.
 * If there is no hit, hit.pol will be NULL.
 */

        #define LXsP_TOOL_HIT_EVENT	"ToolHitEvent"

/*
 * The stroke vector is just built up by appending the packets for the current event to the list.
 * Which packets are included is determined by the ones requested by the tool normally.  Generally
 * the ones which may be found in the stroke are those whose values change on each mouse move.  Any
 * packets which are fixed should stay fixed while those which change for each move event are appended
 * to the vector list as the mouse input traces out a stroke.
 */

        typedef ILxVectorList 		ILxStrokePacket;
        typedef ILxVectorListID		ILxStrokePacketID;


        #define LXsP_TOOL_STROKE_EVENT	"ToolStrokeEvent"


        #define LXsP_TOOL_PAINT_TARGET	"ToolPaintTarget"

/*
 * The paint stroke packets holds the information about the current stroke with
 * the 'start' and 'end' points in pixel coordinates (note that we use floats because
 * positions are interpolated).
 * 'length' is the stroke length in pixels (between 'start' and 'end').
 * 'total' is the total stroke length since mouse DOWN.
 * 'current' is the position on the stroke for the current paint operation.
 * 'align' is true if the brush is aligned to the stroke.
 */

        #define LXsP_TOOL_PAINT_STROKE	"ToolPaintStroke"

/*
 * The paint brush is an object packet that can be used by paint tools.
 * Paint brushes can be 2D or 3D or both, thus we provide a set of methods to compute
 * values in 2D and 3D.
 * - Flags
 * This method returns brush flags, these indicate what type of brush (2D and\or 3D).
 */

        #define LXfPAINTBRUSH_2D		0x01
        #define LXfPAINTBRUSH_3D		0x02
        #define LXfPAINTBRUSH_3D_RGBA		0x04


        #define LXiPAINTMODE_SET	0
        #define LXiPAINTMODE_ADD	1
        #define LXiPAINTMODE_MAX	2


        #define LXfPAINTSTEP_BUMP	0x01
        #define LXfPAINT_ROLLER		0x02
        #define LXfPAINT_STAMP		0x04
        #define LXfPAINT_NOROT		0x08
        #define LXfPAINT_SCREEN		0x10


        #define LXu_PAINTBRUSHPACKET		"9283C21E-77FC-402D-B22A-7B26285888C4"
        #define LXa_PAINTBRUSHPACKET		"PaintBrushPacket"
        // [local]  ILxPaintBrushPacket


        #define LXsP_TOOL_PAINT_BRUSH		"ToolPaintBrush"

/*
 * The paint ink is an object packet that can be used by paint tools.
 * It mostly consists of a method used to obtain a color at a given position.
 * - Flags
 * This method returns the ink flags. By default the color is the same for the entire brush.
 * There is a flag that tells if the ink should be evaluated for each pixel
 * and another one if the ink requires 3D parameters (which may require interpolating
 * costly geometric parameters).
 */

        #define LXf_PAINT_INK_PERPIXEL		0x01
        #define LXf_PAINT_INK_3D		0x02
        #define LXf_PAINT_INK_STAMP		0x04
        #define LXf_PAINT_INK_REPLACE_RGB	0x08
        #define LXf_PAINT_INK_REPLACE_ALPHA	0x10

        #define LXf_PAINT_INK_REPLACE_RGBA	LXf_PAINT_INK_REPLACE_RGB | LXf_PAINT_INK_REPLACE_ALPHA


        #define LXu_PAINTINKPACKET		"340EE412-232D-4619-974D-7E59C7B39353"
        #define LXa_PAINTINKPACKET		"PaintInkPacket"
        // [local]  ILxPaintInkPacket


        #define LXsP_TOOL_PAINT_INK		"ToolPaintInk"


        #define LXu_PAINTNOZZLEPACKET		"F0BB49ED-0BBB-448a-8339-F69F78E95048"
        #define LXa_PAINTNOZZLEPACKET		"PaintNozzlePacket"
        // [local]  ILxPaintNozzlePacket


        #define LXsP_TOOL_PAINT_NOZZLE		"ToolPaintNozzle"


        #define LXsP_TOOL_PROFILE	"toolProfile"


        #define LXsP_TOOL_IMAGE		"toolImage"


        #define LXsP_TOOL_SNAPELEMENT	"toolSnapElement"


        #define LXsP_TOOL_SUBJECT2	"tool.subject2"

/*
 * This interface was retired in modo11a, in order to update ReplaceItems function
 */

        #define LXu_ITEMREPLACEMENT1		"3C256C60-DDE0-4347-82BB-10BF6E3AE887"
        #define LXa_ITEMREPLACEMENT1		"itemreplacement"
        //[export] ILxItemReplacement1 itemrep
        //[local]  ILxItemReplacement1

/*
 * The 'item.channel' command supports item type replacement. This allows us to create
 * controls for channels on items that aren't selected, provided they have some
 * relationship to the selected items. The format for this is 'item.channel
 * itemtype(replace)$channelname', where 'replace' is the name of an ItemReplacement 
 * server.
 */

        #define LXu_ITEMREPLACEMENT		"2829760d-fd93-400e-aac5-f98f1b9a1500"
        #define LXa_ITEMREPLACEMENT		"itemreplacement.v2"
        //[export] ILxItemReplacement itemrep
        //[local]  ILxItemReplacement

#endif
