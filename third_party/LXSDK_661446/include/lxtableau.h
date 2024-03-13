/*
 * LX tableau module
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
#ifndef LX_tableau_H
#define LX_tableau_H

typedef struct vt_ILxTableauSurface1 ** ILxTableauSurface1ID;
typedef struct vt_ILxTableau ** ILxTableauID;
typedef struct vt_ILxTableauElement ** ILxTableauElementID;
typedef struct vt_ILxTableauSurface ** ILxTableauSurfaceID;
typedef struct vt_ILxTriangleSoup ** ILxTriangleSoupID;
typedef struct vt_ILxTableauVolume ** ILxTableauVolumeID;
typedef struct vt_ILxTableauLight ** ILxTableauLightID;
typedef struct vt_ILxLightSample ** ILxLightSampleID;
typedef struct vt_ILxTableauProxy ** ILxTableauProxyID;
typedef struct vt_ILxTableauInstance ** ILxTableauInstanceID;
typedef struct vt_ILxTableauShader ** ILxTableauShaderID;
typedef struct vt_ILxShaderSlice ** ILxShaderSliceID;
typedef struct vt_ILxTableauFilter ** ILxTableauFilterID;
typedef struct vt_ILxTableauSource ** ILxTableauSourceID;
typedef struct vt_ILxInstanceable ** ILxInstanceableID;
typedef struct vt_ILxTableauService ** ILxTableauServiceID;
typedef struct vt_ILxNodalService ** ILxNodalServiceID;
typedef struct vt_ILxTableauListener ** ILxTableauListenerID;
typedef struct vt_ILxTableauSource1 ** ILxTableauSource1ID;
typedef struct vt_ILxTableauInstance1 ** ILxTableauInstance1ID;

#include <lxvector.h>


        typedef float		 LXtTableauBox[6];


/*
 * The shader computes the light intensity and other parameters based on the sample
 * and the ray.  Sample source position is in homogeneous coordinates so it can
 * include distant sources.
 * Quality and shadowing are determined reading packets from the shader.  These are
 * fixed for a given light, so they can be evaluated once and should not depend on
 * any other inputs.  The quality is given by a requested number of samples for the
 * light, as well as approximate information about falloff.  For local lights,
 * 'center' and 'radius' define a region in which the light's sample points reside.
 * For directional lights, 'radius' is half the spread in radians.  'dir' is the
 * direction the light is pointing.  'power' is the radiant flux of the light in
 * watts and is used for allocating emitted photons.  'infinite' should be one for
 * directional lights, zero otherwise.  'indirect' should be one for portal lights,
 * zero otherwise.  'item' is for light linking and points to the cinema light item
 * that corresponds to this element.
 */
typedef struct st_LXpLightQuality {
        LXtFVector		 center;
        LXtFVector		 dir;
        float			 radius;
        float			 cosine;
        float			 radiance;
        float			 intensity;
        float			 power;
        float			 importance;
        unsigned int		 infinite;
        unsigned int		 indirect;
        unsigned int		 fallType;
        unsigned int		 shadType;
        unsigned int		 samples;
        unsigned int		 linkMode;
        void			*linkGroup;
        void			*item;
        char			*lpeLabel;
} LXpLightQuality;

/*
 * Lights that want to use a shadow map can compute this packet.  It indicates the
 * center, direction, orientation, spread angle and resolution of the requested
 * shadow map.
 * 'exclude' is for self shadowing.  Some items do their own self shadowing and
 * don't want to be included in the shadow computation.
 */
typedef struct st_LXpLightShadowing {
        LXtFVector		 pos;
        LXtFVector		 ray, up;
        float			 angle;
        unsigned int		 mapRes;
        void			*exclude;
} LXpLightShadowing;

/*
 * The light color and brightness for locations in space is computed using another
 * shader slice.  This packet is initialized with the world and object position
 * and the ray for the light sample being shaded.
 */
typedef struct st_LXpLightSource {
        LXtFVector		 wPos, oPos;
        LXtFVector		 dir, norm;
        float			 len;
        float			 nDotWi;
        int			 sampleIndex;
        void			*lightSource;
        void			*lightItem;
} LXpLightSource;

/*
 * The colors at the given sample location are computed by the light and returned
 * in this packet.  Brightness takes into account falloff and light shape, and the
 * colors are not pre-multiplied by the attenuation.  'unshad' is not set by the
 * light shader itself but is used in computing shadow alpha.  'pdf' is used for
 * multiple importance sampling.
 */
typedef struct st_LXpLightColor {
        LXtFVector		 color;
        LXtFVector		 shadow;
        LXtFVector		 unshad;
        float			 diffuse;
        float			 specular;
        float			 caustics;
        float			 subsurface;
        float			 brightness;
        float			 pdf;
} LXpLightColor;

/*
 * The environment in the tableau is given as a list of shaders.
 * The primary function of an environment is to read the direction of the camera
 * ray and output the color at infinity. Origin is also provided, although for
 * environment shaders this can be ignored since the background is assumed to be
 * at infinity.  Spread is the angular size of the sampling cone, in radians.
 */
typedef struct st_LXpCameraRay {
        LXtFVector		 dir;
        LXtFVector		 origin;
        float			 spread;
} LXpCameraRay;

typedef struct st_LXpEnvInfiniteColor {
        LXtFVector		 rgb;
        float			 intensity;
} LXpEnvInfiniteColor;

/*
 * An environment can also provide flags to determine where it is visible.
 * Typically only one environment would be visible in a specific context. If there
 * are multiple environments visible to the camera, for example, it's undetermined
 * what the render camera will see. Environments can also be restricted to match
 * particular light path expressions with a label.
 */
typedef struct st_LXpEnvVisibility {
        unsigned int		 camera;
        unsigned int		 indirect;
        unsigned int		 reflection;
        unsigned int		 refraction;
        char			*lpeLabel;
} LXpEnvVisibility;

/*
 * In PhotoView, sometimes we render the environment as if it were an actual sphere
 * in the background of everything. This packet is used for that feature.
 */
typedef struct st_LXpEnvShape {
        unsigned int		 sphereVis;
        float			 size;
        float			 height;
        unsigned int		 flatten;
        LXtVector		 pos;
        LXtMatrix		 xfrmInv;
} LXpEnvShape;

/*
 * An environment can also provide fog values indicating color and absorption values.
 */
typedef struct st_LXpEnvFog {
        LXtFVector		 color;
        LXtFVector		 opacity;
} LXpEnvFog;

/*
 * The environment shaders can also provide global render settings. Each of these
 * packets should occur in only one shader, or else the result is undetermined.
 * The global lighting packet sets ambient illumination and some basic raytracing
 * settings.
 */
typedef struct st_LXpGlobalLighting {
        LXtFVector		 ambientColor;
        float			 ambientIntensity;
        float			 rayThresh;
        float			 rayClamp;
        float			 rayOffset;
        unsigned int		 shadDepth;
        unsigned int		 reflDepth;
        unsigned int		 refrDepth;
        unsigned int		 unbiased;
        unsigned int		 specSmps;
        unsigned int		 animNoise;
        unsigned int		 rayAccel;
        unsigned int		 batchSize;
        unsigned int		 impBoost;
        unsigned int		 directSmps;
        unsigned int		 directMIS;
        unsigned int		 reflSmps;
        unsigned int		 refrSmps;
        unsigned int		 subsSmps;
        unsigned int		 noiseSeed;
        float			 smpThresh;
        float			 varThresh;
        float			 pathThresh;
} LXpGlobalLighting;

/*
 * Displacement settings.
 */
typedef struct st_LXpGlobalDisplacement {
        float			 rate;
        float			 ratio;
        float			 jitter;
        float			 edgeMin;
        unsigned int		 enable;
        unsigned int		 smooth;
        unsigned int		 useBump;
} LXpGlobalDisplacement;

/*
 * Indirect illumination and caustics settings.
 */
typedef struct st_LXpGlobalIndirect {
        float			 range;
        float			 irrRays2;
        float			 irrRate;
        float			 irrRatio;
        float			 irrSmooth;
        float			 irrRetrace;
        unsigned int		 enable;
        unsigned int		 scope;
        unsigned int		 limit;
        unsigned int		 rays;
        unsigned int		 subs;
        unsigned int		 vols;
        unsigned int		 bump;
        unsigned int		 super;
        unsigned int		 reject;
        unsigned int		 caus;
        unsigned int		 giBack;
        unsigned int		 irrCache;
        unsigned int		 irrDirect2;
        unsigned int		 irrRays;
        unsigned int		 irrVals;
        unsigned int		 irrGrads;
        unsigned int		 irrSample;
        unsigned int		 irrData;
        unsigned int		 irrStart;
        unsigned int		 irrEnd;
        unsigned int		 irrWalk;
        unsigned int		 irrLEnable;
        unsigned int		 irrSEnable;
        unsigned int		 radCache;
        unsigned int		 envSample;
        unsigned int		 envRays;
        unsigned int		 envMIS;
        char			*irrLName;
        char			*irrSName;
} LXpGlobalIndirect;

typedef struct st_LXpGlobalCaustics {
        float			 multiplier;
        unsigned int		 total;
        unsigned int		 local;
        unsigned int		 walk;
} LXpGlobalCaustics;

/*
 * Miscellaneous render settings, specific to our built-in renderer.
 */
typedef struct st_LXpGlobalRendering {
        float			 subdRate;
        float			 coarseRate;
        float			 fineRate;
        float			 fineThresh;
        float			 aaImpMin;
        unsigned int		 multiGeo;
        unsigned int		 mergeFur;
        unsigned int		 subdAdapt;
        unsigned int		 renderType;
        unsigned int		 aa;
        unsigned int		 aaFilter;
        unsigned int		 motionBlur;
        unsigned int		 field;
        unsigned int		 frmPasses;
        unsigned int		 dof;
        unsigned int		 stereo;
        unsigned int		 stereoEye;
        unsigned int		 stereoComp;
        unsigned int		 upAxis;
        unsigned int		 bucketX;
        unsigned int		 bucketY;
        unsigned int		 bktOrder;
        unsigned int		 bktReverse;
        unsigned int		 bktWrite;
        unsigned int		 bktSkip;
        unsigned int		 bktRefine;
        unsigned int		 aRefine;
        unsigned int		 mergeRad;
        unsigned int		 bakeDir;
        unsigned int		 outputMasking;
        unsigned int		 proxyExp;
        unsigned int		 rayEngine;
        unsigned int		 sppMin;
        unsigned int		 sppMax;
        unsigned int		 shdEngine;
} LXpGlobalRendering;

/*
 * The environment shader also provides packets to describe the camera used
 * for rendering.  Some are required and some are optional, and which ones
 * are present determines the type of camera to use for the rendering.
 * This required packet defines the frame buffer size in pixels and the
 * per-pixel sampling.  Sampling quality is given by a floating point number of
 * samples per pixel, and a shading rate.  These may be interpreted in any
 * manner appropriate to the renderer.
 */
typedef struct st_LXpCameraResolution {
        unsigned int		 width;
        unsigned int		 height;
        float			 pixelAspect;
        float			 dpi;
//	float			 samples;
//	float			 rate;
        float			 regX0, regX1, regY0, regY1;
} LXpCameraResolution;

/*
 * Orthographic cameras are specified by a set of parameters which define the view
 * frustum, lens and aperture.  Eye position and transform are the location and
 * orientation of the camera in world coordinates.  Focal length, focus distance
 * and f-Stop define the camera's zoom and depth of field.  Iris blades, rotation,
 * and bias affect the depth of field "bokeh" shape.  Distort is a barrel or
 * pin-cushion value and is 1.0 for a flat projection.  Interocular distance is
 * the distance between the eyes for stereo rendering.  The remaining parameters
 * define the projection from 3D to 2D, ala Maya.
 */
typedef struct st_LXpCameraFrustum {
        LXtFVector		 eyePos;
        LXtMatrix		 xfrm, invXfrm;
        float			 focalLength;
        float			 focusDist, fStop;
        float			 irisRot, irisBias, distort;
        float			 ioDist, convDist;
        float			 blurLength, blurOffset;
        float			 apertureX, apertureY;
        float			 offsetX, offsetY;
        float			 squeeze;
        float			 target;
        float			 clipDist;
        int			 clipping;
        int			 filmFit;
        int			 projType;
        int			 irisBlades;
        void			*item;
        int			 useMask;
        float			 overscan;
        float			 filmRoll;
} LXpCameraFrustum;

/*
 * In addition to simple distortion, raytrace camera distortions can be computed
 * procedurally for each pixel.  If the environment has a slice that reads the
 * camera pixel packet and writes the LXpCameraRay packet, then the slice will be
 * evaluated before raytracing.  The slice reads the buffer XY, and optionally the
 * ray direction packet (which is initialized based on the frustum if any), and
 * writes an updated ray direction.
 */
typedef struct st_LXpCameraPixel {
        float			 x, y;
} LXpCameraPixel;

/*
 * A camera intended to perform UV baking is specified by providing one of these
 * packets instead of a frustum.  The packet contains the name of the feature
 * which is the source of the UV coordinates.  Any element that doesn't support
 * this UV feature name is not rendered.
 */
typedef struct st_LXpCameraUVBake {
        const char		*name;
} LXpCameraUVBake;

/*
 * This structure can be used to simplify conversion from the older value textures.
 * It contains 3 indexes, the channel index inthe item, the evaluator index for the
 * per-layer data, and the evaluator index for the per-sample data.
 */
typedef struct st_LXtSampleIndex {
        unsigned	 chan;
        unsigned	 layer;
} LXtSampleIndex;


/*
 * For 901 the TableauSurface interface adds the SegmentBox() method.
 */
typedef struct vt_ILxTableauSurface1 {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Element methods
        LXxMETHOD(  LxResult,
Bound) (
        LXtObjectID		 self,
        LXtTableauBox		 bbox);
        LXxMETHOD(  unsigned int,
FeatureCount) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LxResult,
FeatureByIndex) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 index,
        const char	       **name);

        LXxMETHOD(  LxResult,
SetVertex) (
        LXtObjectID		 self,
        LXtObjectID		 vdesc);
// QWEB_MACRO_END - SDK Common: Element methods

        LXxMETHOD(  LxResult,
Sample) (
        LXtObjectID		 self,
        const LXtTableauBox	 bbox,
        float			 scale,
        LXtObjectID		 trisoup);

        LXxMETHOD(  LxResult,
Padding) (
        LXtObjectID		 self,
        float			*dist);
} ILxTableauSurface1;

/*
 * A Tableau is a snapshot of the 3D scene, partially frozen in time and suitable
 * for rendering.  It consists of a collection of various types of elements such
 * as surfaces, volumes, lights, and filters which all contribute to the final
 * rendered appearance.  A tableau is created by traversing the item database.
 * Tableaus have a start time and duration interval, and method for adding new
 * elements or instances of existing elements.  This interface is provided
 * mainly so clients can add elements to populate the tableau, so this does
 * not give full access.
 * 
 * 
 * Get a ChannelRead object for subframe times: 'type' is 0,1,2 for t0, t1 and frame time.
 * 
 * Returns LXe_TRUE for items that are visible in this tableau.
 * 
 * Get a tableau shader given an item and string tags for material tags.
 * 
 * Return a peek of the item currently being instanced.
 * 
 * These events are used for incremental updates to the tableau.
 * Update takes in a visitor, which acts as a callback to update the tableau data.
 * When the tableau is "safe", such as when the render is stopped, it will perform
 * the update. The "immediate" argument is whether or not the tableau contains
 * dangerous / invalid data, in which case any tableau clients need to stop / abort
 * immediately
 * 
 * The tableau will add-ref and release the visitor when it's done, so the client
 * doesn't need to keep a reference around.
 * 
 * UpdateAll tells the tableau that it needs to be completely invalidated and rebuilt.
 * 
 * EltNotify notifies clients of the tableau (like the render caches) that a tableau
 * element has changed. It takes in the element object (which the tableau source
 * should have retained) and the event indicating what's changed.
 * 
 * InstNotify is effectively the same.
 * 
 * 
 * This allows clients to add instance of other items, not just their own elements.
 * This takes the item to be instanced (inst), the item doing the instacing (from), the TableauInstance
 * object  giving the transforms for the item. The final arguments give a TableauVertex
 * for particle features and an array of those features, and can both be null if there
 * are no particle features for the instance.
 * 
 * Items that provide an instanceable object channel call this method to 
 * define the elements that make up the item. The element is the TableauElement
 * to be added and the tags are the string tags to be used for getting shaders
 * for this element. Both objects are often the same.
 */
typedef struct vt_ILxTableau {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Time) (
        LXtObjectID		 self,
        float			*t0,
        float			*interval);

        LXxMETHOD(  LxResult,
AddElement) (
        LXtObjectID		 self,
        LXtObjectID		 element,
        LXtObjectID		 shader);

        LXxMETHOD(  LxResult,
AddInstance) (
        LXtObjectID		 self,
        LXtObjectID		 inst,
        LXtObjectID		 element,
        LXtObjectID		 shader);
        LXxMETHOD(  LxResult,
Channels) (
        LXtObjectID		 self,
        unsigned		 type,
        void		       **ppvObj);
        LXxMETHOD (  LxResult,
Visible) (
        LXtObjectID              self,
        LXtObjectID              item);
        LXxMETHOD(  LxResult,
FindShader) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        LXtObjectID		 tags,
        void		       **ppvObj);
        LXxMETHOD(  LXtObjectID,
InstanceItem) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Update) (
        LXtObjectID		 self,
        LXtObjectID		 visitor,
        int			 immediate);

        LXxMETHOD(  LxResult,
UpdateAll) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
EltNotify) (
        LXtObjectID		 self,
        LXtObjectID		 element,
        int			 event);

        LXxMETHOD(  LxResult,
InstNotify) (
        LXtObjectID		 self,
        LXtObjectID		 instance,
        int			 event);
        LXxMETHOD(  LxResult,
AddInstanceItem) (
        LXtObjectID		 self,
        LXtObjectID		 instItem,
        LXtObjectID		 fromItem,
        LXtObjectID		 inst,
        LXtObjectID		 vdesc,
        const float		*vertex);
        LXxMETHOD(  LxResult,
AddInstanceableElement) (
        LXtObjectID		 self,
        LXtObjectID		 elt,
        LXtObjectID		 tags);
} ILxTableau;

/*
 * We have an element interface, but all the other elements have the same
 * functions at the start as well.
 */
typedef struct vt_ILxTableauElement {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Element methods
        LXxMETHOD(  LxResult,
Bound) (
        LXtObjectID		 self,
        LXtTableauBox		 bbox);
        LXxMETHOD(  unsigned int,
FeatureCount) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LxResult,
FeatureByIndex) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 index,
        const char	       **name);

        LXxMETHOD(  LxResult,
SetVertex) (
        LXtObjectID		 self,
        LXtObjectID		 vdesc);
// QWEB_MACRO_END - SDK Common: Element methods
} ILxTableauElement;

/*
 * 2D surface elements are 3D elements that interact with the renderer as a pool
 * of triangles.  The Sample() method is called with a bounding box that intersects
 * the surface element, a feature scale, and an interface to collect triangles.
 * The scale parameter gives an approximate edge length scale that is used to
 * determine surface dicing.  The vertex vector description should already have
 * been set for this element.
 * 
 * Surface elements can also provide a padding distance that will be added to the
 * bounding box. In general this will be zero but certain surfaces need to add an extra
 * padding. For example surfaces modeling hair may need to set the padding distance
 * as the maximum length of hair guides.
 * 
 * The bounding boxes of individual segments can be read. The client need to get the 
 * segment IDs by sampling the surface, but once given they can be passed to this
 * function. If it return any error (incluing not-impl) the client should assume that 
 * no box is available.
 */
typedef struct vt_ILxTableauSurface {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Element methods
        LXxMETHOD(  LxResult,
Bound) (
        LXtObjectID		 self,
        LXtTableauBox		 bbox);
        LXxMETHOD(  unsigned int,
FeatureCount) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LxResult,
FeatureByIndex) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 index,
        const char	       **name);

        LXxMETHOD(  LxResult,
SetVertex) (
        LXtObjectID		 self,
        LXtObjectID		 vdesc);
// QWEB_MACRO_END - SDK Common: Element methods

        LXxMETHOD(  LxResult,
Sample) (
        LXtObjectID		 self,
        const LXtTableauBox	 bbox,
        float			 scale,
        LXtObjectID		 trisoup);
        LXxMETHOD(  LxResult,
Padding) (
        LXtObjectID		 self,
        float			*dist);
        LXxMETHOD(  LxResult,
SegmentBox) (
        LXtObjectID		 self,
        unsigned int		 segID,
        LXtTableauBox		 bbox);
} ILxTableauSurface;

/*
 * A triangle "soup" consists of unconnected triangles grouped into segments.  The
 * idea of a soup is that although triangles may border on each other and share
 * normals at those borders, there is no connectivity information in the data
 * structure.  What we have is just a big batch of triangles and it's up to the
 * renderer to assure that any transformations it applies will maintain continuity.
 * While this places definite limitations on the renderer, it also makes it much
 * easier to deal with gigantic meshes since they can be processed in arbitrarily
 * small units.
 * The triangle soup interface is passed to the surface object from the renderer,
 * and the surface has the job of generating all the triangles that intersect the
 * bounding box.  The triangles are grouped into segments by the surface, each
 * with a unique ID code.  Before sending a segment the surface calls the
 * Segment() method with the ID, and the renderer can return LXe_TRUE or LXe_FALSE.
 * If false the segment is skipped, which allows the renderer to cache segments and
 * only update them as needed.  Each segment can contain either points, lines, or
 * triangles.
 * 
 * 
 * Within each segment the surface calls Vertex() and Polygon() any number of
 * times in any combination.  Each call to Vertex() takes the vector of floats
 * which define the vertex, and the vertices in the fragment are numbered
 * starting from zero, incrementing by one each call.  The Polygon() function
 * knits vertices together into a part of the visible surface.  For points and
 * lines the Polygon() function ignores the last one or two vertex indices.
 * 
 * Connect allows the source to give hints about the connectivity of the elements
 * in the soup. This is completely optional and there is no possibility of an
 * error return.
 */
typedef struct vt_ILxTriangleSoup {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned int,
TestBox) (
        LXtObjectID		 self,
        const LXtTableauBox	 bbox);

        LXxMETHOD(  LxResult,
Segment) (
        LXtObjectID		 self,
        unsigned int		 segID,
        unsigned int		 type);
        LXxMETHOD(  LxResult,
Vertex) (
        LXtObjectID		 self,
        const float		*vertex,
        unsigned int		*index);

        LXxMETHOD(  LxResult,
Polygon) (
        LXtObjectID		 self,
        unsigned int		 v0,
        unsigned int		 v1,
        unsigned int		 v2);
        LXxMETHOD(  void,
Connect) (
        LXtObjectID		 self,
        unsigned int		 type);
} ILxTriangleSoup;

/*
 * - RenderInit
 * After the tableau has fully been populated and the sample vector has been set, but before the first ray is fired,
 * volumes are initialized.
 * - RaySample
 * Volumes are sampled with ray marching: during ray tracing volumes are intersected by
 * rays and are evaluated to contribute to the ray.
 * 'densitySlice' is the volume density shader slice
 * 'shadingSlice' is the volume sample shader slice
 * 'sv' is the sample vector.
 * - RayCast
 * Implicit surfaces need to be raycasted, these are volumes that can be evaluated as a surface usually by tracing the isosurface
 * of the volume density field. This method returns the hit distance. It should also set the normal, position and facet packets.
 * - Density
 * Returns the density at the given position, if 'worldPos' is true it means that the position is in world space.
 * The density is zero outside the volume so this can also be used to find out if we are inside or outside said volume.
 * 
 */
typedef struct vt_ILxTableauVolume {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Element methods
        LXxMETHOD(  LxResult,
Bound) (
        LXtObjectID		 self,
        LXtTableauBox		 bbox);
        LXxMETHOD(  unsigned int,
FeatureCount) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LxResult,
FeatureByIndex) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 index,
        const char	       **name);

        LXxMETHOD(  LxResult,
SetVertex) (
        LXtObjectID		 self,
        LXtObjectID		 vdesc);
// QWEB_MACRO_END - SDK Common: Element methods

        LXxMETHOD(  int,
Type) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
RenderInit) (
        LXtObjectID		 self,
        LXtObjectID		 sv);

        LXxMETHOD(  LxResult,
RaySample) (
        LXtObjectID		 self,
        LXtObjectID		 densitySlice,
        LXtObjectID		 shadingSlice,
        LXtObjectID		 sv,
        LXtObjectID		 raycastObj,
        LXtObjectID		 raymarchObj);

        LXxMETHOD(  LxResult,
RayCast) (
        LXtObjectID		 self,
        LXtObjectID		 densitySlice,
        LXtObjectID		 sv,
        LXtObjectID		 raycastObj,
        double			*dist,
        int			*localShader);

        LXxMETHOD(  LxResult,
Density) (
        LXtObjectID		 self,
        LXtObjectID		 densitySlice,
        LXtObjectID		 sv,
        LXtObjectID		 raycastObj,
        const LXtVector		 pos,
        int			 worldPos,
        double			*dens);
} ILxTableauVolume;

/*
 * Lights are 3D elements, where the bound (if any) represents the effective
 * coverage area for anything illuminated by the light.  The light source can
 * be sampled at any desired quality level, which is simply the number of
 * samples over the emissive volume defined by the light.
 * 'Emit' traces photons from a light.
 * 'ShadowMap' returns the map and true if the light uses a shadow map.
 * 
 */
typedef struct vt_ILxTableauLight {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Element methods
        LXxMETHOD(  LxResult,
Bound) (
        LXtObjectID		 self,
        LXtTableauBox		 bbox);
        LXxMETHOD(  unsigned int,
FeatureCount) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LxResult,
FeatureByIndex) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 index,
        const char	       **name);

        LXxMETHOD(  LxResult,
SetVertex) (
        LXtObjectID		 self,
        LXtObjectID		 vdesc);
// QWEB_MACRO_END - SDK Common: Element methods

        LXxMETHOD(  LxResult,
Sample) (
        LXtObjectID		 self,
        float			 u,
        float			 v,
        const LXtFVector	 dir,
        LXtFVector		 wPos,
        LXtFVector		 oPos,
        LXtFVector		 norm,
        float			 t);

        LXxMETHOD(  int,
Geometry) (
        LXtObjectID		 self,
        void			*gc);

        LXxMETHOD(  LxResult,
Emit) (
        LXtObjectID		 self,
        unsigned int		 nPhotons,
        int			 offset,
        LXtObjectID		 slice,
        LXtSampleVectorID	 sv);

        LXxMETHOD(  int,
ShadowMap) (
        LXtObjectID		 self,
        void		       **ppvObj);
} ILxTableauLight;

typedef struct vt_ILxLightSample {
        ILxUnknown	 iunk;
        LXxMETHOD(  void,
Vertex) (
        LXtObjectID		 self,
        const float		*vertex);
} ILxLightSample;

/*
 * A proxy is sampled to add elements to the tableau.  The proxy object needs to
 * keep track of which sub-elements have been added to the tableau so they are
 * only added once.
 */
typedef struct vt_ILxTableauProxy {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Element methods
        LXxMETHOD(  LxResult,
Bound) (
        LXtObjectID		 self,
        LXtTableauBox		 bbox);
        LXxMETHOD(  unsigned int,
FeatureCount) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LxResult,
FeatureByIndex) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 index,
        const char	       **name);

        LXxMETHOD(  LxResult,
SetVertex) (
        LXtObjectID		 self,
        LXtObjectID		 vdesc);
// QWEB_MACRO_END - SDK Common: Element methods

        LXxMETHOD(  LxResult,
Sample) (
        LXtObjectID		 self,
        const LXtTableauBox	 bbox,
        LXtObjectID		 tableau);
} ILxTableauProxy;

/*
 * An instance is a copy of another element, with variations. It most likely
 * has a different position and orientation, and it may have differences in
 * shading or shading parameters. These differences are encoded in the
 * instance interface. Any normal element may also present this interface,
 * if it wants to have these attributes as well.
 * Instances can set packets in the sample vector for global parameters
 * of the element to be used by its shader.
 * 
 * 
 * The transformation of an instance (or any element) can be read with this
 * method. The endpoint can specify either the start or end of the tableau
 * time interval.
 * 
 * The instance may be dissolved independently.
 * 
 * An instance can define particle features. These are given by a tableau
 * vertex to describe the feature vector, which can then be read.
 */
typedef struct vt_ILxTableauInstance {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Properties) (
        LXtObjectID		 self,
        LXtObjectID		 vecstack);
        LXxMETHOD(  LxResult,
GetTransform) (
        LXtObjectID		 self,
        unsigned		 endPoint,
        LXtVector		 offset,
        LXtMatrix		 xfrm);
        LXxMETHOD(  LxResult,
GetDissolve) (
        LXtObjectID		 self,
        double			*dissolve);
        LXxMETHOD(  LxResult,
ParticleDescription) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
ParticleArray) (
        LXtObjectID		 self,
        float			*vector);
} ILxTableauInstance;

/*
 * All 3D elements have shaders, which are used by the renderer to compute desired
 * sample vector packets from a set of input packets.  Shaders are polymorphic
 * with an ILxVectorType interface, so it's easy to determine what they take as
 * input and output.
 * To perform computations we need to "slice" the shader, which basically selects
 * a set of desired output packets.  The output packets are determined by the
 * vector type, and the vertex description provides information about vertex
 * packets to use during computation.
 */
typedef struct vt_ILxTableauShader {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID		 self,
        LXtObjectID		 teElt,
        LXtObjectID		 tvDesc);

        LXxMETHOD(  LxResult,
Slice) (
        LXtObjectID		 self,
        LXtObjectID		 vtOutput,
        LXtObjectID		 tvDesc,
        void		       **ppvObj);
} ILxTableauShader;

/*
 * The result of a successful slice is a shader slice interface.  This is also
 * polymorphic with an ILxVectorType to select its inputs.  The Evaluate() method
 * computes the output packets for a sample vector.
 */
typedef struct vt_ILxShaderSlice {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 vecstack);
} ILxShaderSlice;

/*
 * Filters are fundamentally 2D elements, and operate in the image space over
 * the frame buffer.  The bound method for a filter returns a 2D bounding box
 * and a kernel radius, plus some flags.
 * 
 * The Pixel() and Region() methods are used to do proecessing based on the
 * filter type.  Both get the frame buffer and the
 */
typedef struct vt_ILxTableauFilter {
        ILxUnknown	 iunk;
        LXxMETHOD(  const char *,
Order) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID		 self,
        LXtObjectID		 framebuf);

        LXxMETHOD(  unsigned int,
Bound) (
        LXtObjectID		 self,
        float			 box[4],
        float			*kernel);
        LXxMETHOD(  unsigned int,
Pixel) (
        LXtObjectID		 self,
        LXtObjectID		 framebuf,
        const float		 pos[2]);

        LXxMETHOD(  unsigned int,
Region) (
        LXtObjectID		 self,
        LXtObjectID		 framebuf,
        const float		 box[4]);
} ILxTableauFilter;

typedef struct vt_ILxTableauSource {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Elements) (
        LXtObjectID		 self,
        LXtObjectID		 tableau);

        LXxMETHOD(  LxResult,
Preview) (
        LXtObjectID		 self,
        LXtObjectID		 tableau);

        LXxMETHOD(  LxResult,
Instance) (
        LXtObjectID		 self,
        LXtObjectID		 tableau,
        LXtObjectID		 instance);

        LXxMETHOD(  LxResult,
SubShader) (
        LXtObjectID		 self,
        LXtObjectID		 tableau,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
PreviewUpdate) (
        LXtObjectID		 self,
        int			 chanIndex,
        int			*update);

        LXxMETHOD(  LxResult,
GetCurves) (
        LXtObjectID		 self,
        LXtObjectID		 tableau,
        LXtObjectID		 tags,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
ElementType) (
        LXtObjectID		 self,
        int			 type,
        int			*supported);
} ILxTableauSource;

/*
 * Compare this instanceable to another of the same type and return a value on
 * a comparison metric. The value is the same sense as strcmp(), with zero for 
 * identical objects, and positive and negative values indicating relatve order.
 * 
 * When the elements are needed -- such as when the item itself is to be
 * rendered or instanced -- the AddElements() method is called. The T0 and
 * T1 instanceable objects are from the shutter open and close times, and
 * can be read to compute state that changes while the shutter is open. The
 * object itself is computed at the frame time. The method should call
 * AddInstanceableElement() for all elements in the item.
 * 
 * Alternately the instanceable object can provide a Surface object which
 * will be added to the tableau.
 */
typedef struct vt_ILxInstanceable {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
Compare) (
        LXtObjectID		 self,
        LXtObjectID		 other);
        LXxMETHOD(  LxResult,
AddElements) (
        LXtObjectID		 self,
        LXtObjectID		 tableau,
        LXtObjectID		 instT0,
        LXtObjectID		 instT1);
        LXxMETHOD(  LxResult,
GetSurface) (
        LXtObjectID		 self,
        void		       **ppvObj);
} ILxInstanceable;

/*
 * 
 * This utility method will populate a vertex description with all the known
 * features of the tableau surface object. It puts the four required features
 * at the front as normal.
 */
typedef struct vt_ILxTableauService {
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
VertexFromFeatures) (
        LXtObjectID		 self,
        LXtObjectID		 surfObj,
        LXtObjectID		 vertex);
} ILxTableauService;

/*
 * The nodal service is used to establish and evaluate channels as part of the Nodal
 * Shading system. The service is used by textures & shaders in two ways: as part
 * of the Shader Tree, their inputs can be evaluated on a per-sample basis, and their
 * outputs can also be requested as part of the Nodal Modifier system.
 * The Nodal Service will transparently handle both of these cases.
 * AddSampleChan & AddSampleChanName are used to add a channel of an item to the nodal
 * evaluation system. When processed as part of the Shader Tree, the evaluator index will
 * be stored in the 'idxArray' passed, and when processed as a nodal modifier, the evaluator
 * index will be stored internally within the nodal evaluator (and 'idxArray' may be NULL).
 * Additionally, within the Shader Tree, if the channel is not actually driven on a
 * per-sample basis for the current pass, the evaluator index is stored as LXiNODAL_NOT_DRIVEN.
 * This value speeds up the evaluations by letting the Get* methods know that the value
 * does not have to be read from the evaluator.
 * 
 * When adding channels for texture locators, LXfECHAN_LOCATOR should be ORed with the
 * LXfECHAN_READ and/or LXfECHAN_WRITE flags.
 * 
 * GetFloat, GetInt & GetValue are used to get the current sample values from a nodal evaluator.
 * 'index' is the index of channel in the item. For evaluations in Shader Tree, the values will
 * be read from the evaluator using the 'idxArray' passed, unless the stored index is LXiNODAL_NOT_DRIVEN,
 * in which case the 'orig' value will be returned. When evaluated as a nodal modifier, the internal
 * index array will be used.
 * 
 * IsDriven & IsDrivenName are used to determine if a channel is driven per-sample,
 * and therefore needs to be read at every sample. If not, the value can be read
 * once per layer.
 * 
 * AnyDrivenChans is used for optimization of the evaluation. It is passed a contiguous array
 * of evaluator indexes, and will return LXe_TRUE for the first sample-driven channel,
 * and LXe_FALSE if none are found.
 * 
 */
typedef struct vt_ILxNodalService {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
AddSampleChan) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 item,
        int		         chanIndex,
        int		        *idxArray,
        int		         type);

        LXxMETHOD(  int,
AddSampleChanName) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 item,
        const char		*chanName,
        int		        *idxArray,
        int		         type);

        LXxMETHOD(  double,
GetFloat) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        int		        *idxArray,
        int		         index,
        double			 orig);

        LXxMETHOD(  int,
GetInt) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        int		        *idxArray,
        int		         index,
        int			 orig);

        LXxMETHOD(  void*,
GetValue) (
        LXtObjectID		 self,
        LXtObjectID		 etor,
        int		        *idxArray,
        int		         index,
        void			*orig);

        LXxMETHOD(  int,
IsDriven) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        int		         chanIndex);

        LXxMETHOD(  int,
IsDrivenName) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        const char		*chanName);

        LXxMETHOD(  int,
AnyDrivenChans) (
        LXtObjectID		 self,
        int			*chans,
        int		         count);
} ILxNodalService;

/*
 * In order for plugins to listen to events, we provide the following event translator
 * interface.
 * A tableau channel change event is a general event such that a plugin can listen for any
 * channel changes through the tableau. This is useful for plugins which generate tableau
 * elements, as it gets events on both animation and general modification events, so it's
 * simple to then fire a tableau update event.
 * 
 * The only two other events are when a tableau indicates that every element in the tableau
 * is being flushed, and when the tableau is warning clients that it is being destroyed.
 * 
 */
typedef struct vt_ILxTableauListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
ChannelChange) (
        LXtObjectID		 self,
        LXtObjectID		 tableau,
        LXtObjectID		 item,
        int			 channel);
        LXxMETHOD( void,
FlushElements) (
        LXtObjectID		 self,
        LXtObjectID		 tableau);
        LXxMETHOD( void,
TableauDestroy) (
        LXtObjectID		 self,
        LXtObjectID		 tableau);
} ILxTableauListener;

/*
 * The TableauSource1 interface is the legacy interface, without the ElementType function.
 */
typedef struct vt_ILxTableauSource1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Elements) (
        LXtObjectID		 self,
        LXtObjectID		 tableau);

        LXxMETHOD(  LxResult,
Preview) (
        LXtObjectID		 self,
        LXtObjectID		 tableau);

        LXxMETHOD(  LxResult,
Instance) (
        LXtObjectID		 self,
        LXtObjectID		 tableau,
        LXtObjectID		 instance);

        LXxMETHOD(  LxResult,
SubShader) (
        LXtObjectID		 self,
        LXtObjectID		 tableau,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
PreviewUpdate) (
        LXtObjectID		 self,
        int			 chanIndex,
        int			*update);

        LXxMETHOD(  LxResult,
GetCurves) (
        LXtObjectID		 self,
        LXtObjectID		 tableau,
        LXtObjectID		 tags,
        void		       **ppvObj);
} ILxTableauSource1;

typedef struct vt_ILxTableauInstance1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Properties) (
        LXtObjectID		 self,
        LXtObjectID		 vecstack);

        LXxMETHOD(  LxResult,
GetTransform) (
        LXtObjectID		 self,
        unsigned		 endPoint,
        LXtVector		 offset,
        LXtMatrix		 xfrm);
} ILxTableauInstance1;


        #define	LXsITYPE_LIGHTMATERIAL			"lightMaterial"
        #define	LXsICHAN_LIGHTMATERIAL_LIGHTCOL		"lightCol"
        #define	LXsICHAN_LIGHTMATERIAL_DIFFUSE		"diffuse"
        #define	LXsICHAN_LIGHTMATERIAL_SPECULAR		"specular"
        #define	LXsICHAN_LIGHTMATERIAL_CAUSTICS		"caustics"
        #define	LXsICHAN_LIGHTMATERIAL_SUBSURF		"subsurface"
        #define	LXsICHAN_LIGHTMATERIAL_SHADCOL		"shadCol"
        #define	LXsICHAN_LIGHTMATERIAL_SCATCOL		"scatteringColor"
        #define	LXsICHAN_LIGHTMATERIAL_SCATTER		"scattering"
        #define	LXsICHAN_LIGHTMATERIAL_DENSITY		"density"
        #define	LXsICHAN_LIGHTMATERIAL_ATTENUATE	"attenuate"
        #define	LXsICHAN_LIGHTMATERIAL_SHIFT		"shift"


        // Render Item Type and Channels
        #define	LXsITYPE_RENDER			"render"
        #define	LXsICHAN_RENDER_AMBCOLOR	"ambColor"
        #define	LXsICHAN_RENDER_AMBRAD		"ambRad"
        #define	LXsICHAN_RENDER_GLOBENABLE	"globEnable"
        #define	LXsICHAN_RENDER_GLOBSCOPE	"globScope"
        #define	LXsICHAN_RENDER_GLOBLIMIT	"globLimit"
        #define	LXsICHAN_RENDER_GLOBRAYS	"globRays"
        #define	LXsICHAN_RENDER_GLOBRANGE	"globRange"
        #define	LXsICHAN_RENDER_GLOBSUBS	"globSubs"
        #define	LXsICHAN_RENDER_GLOBVOLS	"globVols"
        #define	LXsICHAN_RENDER_GLOBBUMP	"globBump"
        #define	LXsICHAN_RENDER_GLOBSUPER	"globSuper"
        #define	LXsICHAN_RENDER_GLOBREJECT	"globReject"
        #define	LXsICHAN_RENDER_GLOBCAUS	"globCaus"
        #define	LXsICHAN_RENDER_IRRCACHE	"irrCache"
        #define	LXsICHAN_RENDER_IRRUSAGE	"irrUsage"
        #define	LXsICHAN_RENDER_IRRDIRECT2	"irrDirect2"
        #define	LXsICHAN_RENDER_IRRRAYS		"irrRays"
        #define	LXsICHAN_RENDER_IRRRAYS2	"irrRays2"
        #define	LXsICHAN_RENDER_IRRRATE		"irrRate"
        #define	LXsICHAN_RENDER_IRRRATIO	"irrRatio"
        #define LXsICHAN_RENDER_IRRSMOOTH	"irrSmooth"
        #define	LXsICHAN_RENDER_IRRRETRACE	"irrRetrace"
        #define	LXsICHAN_RENDER_IRRVALS		"irrVals"
        #define	LXsICHAN_RENDER_IRRGRADS	"irrGrads"
        #define	LXsICHAN_RENDER_IRRSAMPLE	"irrSample"
        #define	LXsICHAN_RENDER_IRRDATA		"irrData"
        #define	LXsICHAN_RENDER_IRRSTART	"irrStart"
        #define	LXsICHAN_RENDER_IRREND		"irrEnd"
        #define	LXsICHAN_RENDER_IRRWALK		"irrWalk"
        #define	LXsICHAN_RENDER_IRRLENABLE	"irrLEnable"
        #define	LXsICHAN_RENDER_IRRLNAME	"irrLName"
        #define	LXsICHAN_RENDER_IRRSENABLE	"irrSEnable"
        #define	LXsICHAN_RENDER_IRRSNAME	"irrSName"
        #define	LXsICHAN_RENDER_RADCACHE	"radCache"
        #define	LXsICHAN_RENDER_CAMERA		"cameraIndex"
        #define	LXsICHAN_RENDER_ENVSAMPLE	"envSample"
        #define	LXsICHAN_RENDER_ENVRAYS		"envRays"
        #define	LXsICHAN_RENDER_ENVMIS		"envMIS"
        #define	LXsICHAN_RENDER_CAUSENABLE	"causEnable"
        #define	LXsICHAN_RENDER_CAUSMULT	"causMult"
        #define	LXsICHAN_RENDER_CAUSTOTAL	"causTotal"
        #define	LXsICHAN_RENDER_CAUSLOCAL	"causLocal"
        #define	LXsICHAN_RENDER_CAUSWALK	"causWalk"
        #define	LXsICHAN_RENDER_RAYSHADOW	"rayShadow"
        #define	LXsICHAN_RENDER_DIFFDEPTH	"diffDepth"
        #define	LXsICHAN_RENDER_REFLDEPTH	"reflDepth"
        #define	LXsICHAN_RENDER_REFRDEPTH	"refrDepth"
        #define	LXsICHAN_RENDER_RAYTHRESH	"rayThresh"
        #define	LXsICHAN_RENDER_PATHTHRESH	"pathThresh"
        #define	LXsICHAN_RENDER_UNBIASED	"unbiased"
        #define	LXsICHAN_RENDER_RAYCLAMP	"rayClamp"
        #define	LXsICHAN_RENDER_RAYOFFSET	"rayOffset"
        #define LXsICHAN_RENDER_REFLSMPS	"reflSmps"
        #define LXsICHAN_RENDER_REFRSMPS	"refrSmps"
        #define	LXsICHAN_RENDER_SPECSMPS	"specSmps"
        #define	LXsICHAN_RENDER_SUBSSMPS	"subsSmps"
        #define	LXsICHAN_RENDER_SMPTHRESH	"smpThresh"
        #define	LXsICHAN_RENDER_VARTHRESH	"varThresh"
        #define	LXsICHAN_RENDER_ANIMNOISE	"animNoise"
        #define	LXsICHAN_RENDER_NOISESEED	"noiseSeed"
        #define	LXsICHAN_RENDER_RAYACCEL	"rayAccel"
        #define	LXsICHAN_RENDER_BATCHSIZE	"batchSize"
        #define	LXsICHAN_RENDER_IMPBOOST	"impBoost"
        #define LXsICHAN_RENDER_DIRECTSMPS	"directSmps"
        #define LXsICHAN_RENDER_DIRECTMIS	"directMIS"
        #define	LXsICHAN_RENDER_MULTIGEO	"multiGeo"
        #define LXsICHAN_RENDER_PROXYEXP	"proxyExp"
        #define	LXsICHAN_RENDER_MERGEFUR	"allowFurMerge"
        #define	LXsICHAN_RENDER_SUBDADAPT	"subdAdapt"
        #define	LXsICHAN_RENDER_SUBDRATE	"subdRate"
        #define	LXsICHAN_RENDER_DISPENABLE	"dispEnable"
        #define	LXsICHAN_RENDER_DISPRATE	"dispRate"
        #define	LXsICHAN_RENDER_DISPRATIO	"dispRatio"
        #define	LXsICHAN_RENDER_DISPJITTER	"dispJitter"
        #define	LXsICHAN_RENDER_EDGEMIN		"edgeMin"
        #define	LXsICHAN_RENDER_DISPSMOOTH	"dispSmooth"
        #define	LXsICHAN_RENDER_DISPBUMP	"dispBump"
        #define	LXsICHAN_RENDER_SHADE_STACK	"shadeStack"
        #define	LXsICHAN_RENDER_BIN_STACK	"binStack"
        #define	LXsICHAN_RENDER_SPG_STACK	"spgStack"
        #define	LXsICHAN_RENDER_SAMPLEVEC	"sampleVec"

        // Render "globScope" Channel Text Hints
        #define	LXsICVAL_RENDER_GLOBSCOPE_ENVIRONMENT	"environment"
        #define	LXsICVAL_RENDER_GLOBSCOPE_GEOMETRY	"geometry"
        #define	LXsICVAL_RENDER_GLOBSCOPE_VOLUMETRICS	"volumetrics"
        #define	LXsICVAL_RENDER_GLOBSCOPE_ALL		"all"

        // Render "globSubs" Channel Text Hints
        #define	LXsICVAL_RENDER_GLOBSUBS_NONE		"none"
        #define	LXsICVAL_RENDER_GLOBSUBS_GIAFFECTSSS	"giaffectsss"
        #define	LXsICVAL_RENDER_GLOBSUBS_SSSAFFECTGI	"sssaffectgi"
        #define	LXsICVAL_RENDER_GLOBSUBS_BOTH		"both"

        // Render "globCaus" Channel Text Hints
        #define	LXsICVAL_RENDER_GLOBCAUS_NONE		"none"
        #define	LXsICVAL_RENDER_GLOBCAUS_REFLECTION	"reflection"
        #define	LXsICVAL_RENDER_GLOBCAUS_REFRACTION	"refraction"
        #define	LXsICVAL_RENDER_GLOBCAUS_BOTH		"both"

        // Render "irrUsage" Channel Text Hints
        #define	LXsICVAL_RENDER_IRRUSAGE_FIRST		"first"
        #define	LXsICVAL_RENDER_IRRUSAGE_SECOND		"second"
        #define	LXsICVAL_RENDER_IRRUSAGE_BOTH		"both"

        // Render "irrGrads" Channel Text Hints
        #define	LXsICVAL_RENDER_IRRGRADS_NONE		"none"
        #define	LXsICVAL_RENDER_IRRGRADS_ROTATION	"rotation"
        #define	LXsICVAL_RENDER_IRRGRADS_TRANSLATION	"translation"
        #define	LXsICVAL_RENDER_IRRGRADS_BOTH		"both"

        // Render "irrSample" Channel Text Hints
        #define	LXsICVAL_RENDER_IRRSAMPLE_JITTER	"jitter"
        #define	LXsICVAL_RENDER_IRRSAMPLE_POISSON	"poisson"
        #define	LXsICVAL_RENDER_IRRSAMPLE_CONCENTRIC	"concentric"

        // Render "irrData" Channel Text Hints
        #define	LXsICVAL_RENDER_IRRDATA_SMALL		"small"
        #define	LXsICVAL_RENDER_IRRDATA_FAST		"fast"

        // Render "irrGrads" Channel Text Hints
        #define	LXsICVAL_RENDER_IRRGRADS_NONE		"none"
        #define	LXsICVAL_RENDER_IRRGRADS_ROTATION	"rotation"
        #define	LXsICVAL_RENDER_IRRGRADS_TRANSLATION	"translation"
        #define	LXsICVAL_RENDER_IRRGRADS_BOTH		"both"

        // Render "irrStart" Channel Text Hints
        #define	LXsICVAL_RENDER_IRRSTART_S2		"s2"
        #define	LXsICVAL_RENDER_IRRSTART_S4		"s4"
        #define	LXsICVAL_RENDER_IRRSTART_S8		"s8"
        #define	LXsICVAL_RENDER_IRRSTART_S16		"s16"
        #define	LXsICVAL_RENDER_IRRSTART_S32		"s32"
        #define	LXsICVAL_RENDER_IRRSTART_S64		"s64"

        // Render "envMIS" Channel Text Hints
        #define	LXsICVAL_RENDER_ENVMIS_NONE		"none"
        #define	LXsICVAL_RENDER_ENVMIS_DIFFUSE		"diffuse"
        #define	LXsICVAL_RENDER_ENVMIS_REFLECTION	"reflection"
        #define	LXsICVAL_RENDER_ENVMIS_BOTH		"both"

        // Render "directMIS" Channel Text Hints
        #define	LXsICVAL_RENDER_DIRECTMIS_NONE		"none"
        #define	LXsICVAL_RENDER_DIRECTMIS_DIFFUSE	"diffuse"
        #define	LXsICVAL_RENDER_DIRECTMIS_SPECULAR	"specular"
        #define	LXsICVAL_RENDER_DIRECTMIS_BOTH		"both"


        // PolyRender Item Type and Channels
        #define	LXsITYPE_POLYRENDER			"polyRender"
        #define	LXsICHAN_POLYRENDER_FIRST		"first"
        #define	LXsICHAN_POLYRENDER_LAST		"last"
        #define	LXsICHAN_POLYRENDER_STEP		"step"
        #define	LXsICHAN_POLYRENDER_RESUNIT		"resUnit"
        #define	LXsICHAN_POLYRENDER_DPI			"dpi"
        #define	LXsICHAN_POLYRENDER_RESX		"resX"
        #define	LXsICHAN_POLYRENDER_RESY		"resY"
        #define	LXsICHAN_POLYRENDER_PLAYMULT		"playMult"
        #define	LXsICHAN_POLYRENDER_PASPECT		"pAspect"
        #define	LXsICHAN_POLYRENDER_REGION		"region"
        #define	LXsICHAN_POLYRENDER_REGX0		"regX0"
        #define	LXsICHAN_POLYRENDER_REGX1		"regX1"
        #define	LXsICHAN_POLYRENDER_REGY0		"regY0"
        #define	LXsICHAN_POLYRENDER_REGY1		"regY1"
        #define	LXsICHAN_POLYRENDER_RENDTYPE		"rendType"
        #define	LXsICHAN_POLYRENDER_RAYENGINE		"rayEngine"
        #define	LXsICHAN_POLYRENDER_SHDENGINE		"shdEngine"
        #define	LXsICHAN_POLYRENDER_SPPMIN		"sppMin"
        #define	LXsICHAN_POLYRENDER_SPPMAX		"sppMax"
        #define	LXsICHAN_POLYRENDER_AA			"aa"
        #define	LXsICHAN_POLYRENDER_AAFILTER		"aaFilter"
        #define	LXsICHAN_POLYRENDER_AAIMPMIN		"aaImpMin"
        #define	LXsICHAN_POLYRENDER_COARSERATE		"coarseRate"
        #define	LXsICHAN_POLYRENDER_FINERATE		"fineRate"
        #define	LXsICHAN_POLYRENDER_FINETHRESH		"fineThresh"
        #define	LXsICHAN_POLYRENDER_BKTREFINE		"bktRefine"
        #define	LXsICHAN_POLYRENDER_AREFINE		"aRefine"
        #define	LXsICHAN_POLYRENDER_MERGERAD		"mergeRad"
        #define	LXsICHAN_POLYRENDER_FIELD		"field"
        #define	LXsICHAN_POLYRENDER_BUCKETX		"bucketX"
        #define	LXsICHAN_POLYRENDER_BUCKETY		"bucketY"
        #define	LXsICHAN_POLYRENDER_BKTORDER		"bktOrder"
        #define	LXsICHAN_POLYRENDER_BKTORDERPT		"bktOrderPT"
        #define	LXsICHAN_POLYRENDER_BKTREVERSE		"bktReverse"
        #define	LXsICHAN_POLYRENDER_BKTWRITE		"bktWrite"
        #define	LXsICHAN_POLYRENDER_BKTSKIP		"bktSkip"
        #define	LXsICHAN_POLYRENDER_FRMPASSES		"frmPasses"
        #define	LXsICHAN_POLYRENDER_FRMRANGE		"frmRange"
        #define	LXsICHAN_POLYRENDER_OUTPAT		"outPat"
        #define	LXsICHAN_POLYRENDER_BAKEU0		"bakeU0"
        #define	LXsICHAN_POLYRENDER_BAKEU1		"bakeU1"
        #define	LXsICHAN_POLYRENDER_BAKEV0		"bakeV0"
        #define	LXsICHAN_POLYRENDER_BAKEV1		"bakeV1"
        #define	LXsICHAN_POLYRENDER_BAKEX		"bakeX"
        #define	LXsICHAN_POLYRENDER_BAKEY		"bakeY"
        #define	LXsICHAN_POLYRENDER_BAKEDIR		"bakeDir"
        #define	LXsICHAN_POLYRENDER_PROGCONV		"progConv"
        #define	LXsICHAN_POLYRENDER_PROGTIME		"progTime"
        #define	LXsICHAN_POLYRENDER_OUTPUTMASK		"outputMasking"

        // Render "resUnit" Channel Text Hints
        #define	LXsICVAL_RENDER_RESUNIT_PIXELS		"pixels"
        #define	LXsICVAL_RENDER_RESUNIT_INCHES		"inches"
        #define	LXsICVAL_RENDER_RESUNIT_CM		"cm"

        // Render "playMult" Channel Text Hints
        #define	LXsICVAL_RENDER_PLAYMULT_12		"m12"
        #define	LXsICVAL_RENDER_PLAYMULT_25		"m25"
        #define	LXsICVAL_RENDER_PLAYMULT_50		"m50"
        #define	LXsICVAL_RENDER_PLAYMULT_100		"m100"

        // Render "rendType" Channel Text Hints
        #define	LXsICVAL_RENDER_RENDTYPE_AUTOMATIC	"auto"
        #define	LXsICVAL_RENDER_RENDTYPE_SCANLINE	"scanline"
        #define	LXsICVAL_RENDER_RENDTYPE_RAYTRACE	"raytrace"
        #define	LXsICVAL_RENDER_RENDTYPE_PATHTRACE	"pathtrace"
//	#define	LXsICVAL_RENDER_RENDTYPE_INTERACTIVE	"interactive"

        // Render "rayEngine" Channel Text Hints
        #define	LXsICVAL_RENDER_RAYENGINE_SSE		"sse"
        #define	LXsICVAL_RENDER_RAYENGINE_EMBREE	"embree"
        #define	LXsICVAL_RENDER_RAYENGINE_OPTIX_ASYNC	"optixasync"

        // Render "shdEngine" Channel Text Hints
        #define	LXsICVAL_RENDER_SHDENGINE_BASE		"base"
        #define	LXsICVAL_RENDER_SHDENGINE_CPU		"cpu"
        #define	LXsICVAL_RENDER_SHDENGINE_CUDA		"cuda"

        // Render "aa" Channel Text Hints
        #define	LXsICVAL_RENDER_AA_S1			"s1"
        #define	LXsICVAL_RENDER_AA_S2			"s2"
        #define	LXsICVAL_RENDER_AA_S4			"s4"
        #define	LXsICVAL_RENDER_AA_S8			"s8"
        #define	LXsICVAL_RENDER_AA_S16			"s16"
        #define	LXsICVAL_RENDER_AA_S32			"s32"
        #define	LXsICVAL_RENDER_AA_S64			"s64"
        #define	LXsICVAL_RENDER_AA_S128			"s128"
        #define	LXsICVAL_RENDER_AA_S256			"s256"
        #define	LXsICVAL_RENDER_AA_S512			"s512"
        #define	LXsICVAL_RENDER_AA_S1024		"s1024"
        #define	LXsICVAL_RENDER_AA_S2048		"s2048"
        #define	LXsICVAL_RENDER_AA_S4096		"s4096"

        // Render "aaFilter" Channel Text Hints
        #define	LXsICVAL_RENDER_AAFILTER_BOX		"box"
        #define	LXsICVAL_RENDER_AAFILTER_TRIANGLE	"triangle"
        #define	LXsICVAL_RENDER_AAFILTER_GAUSSIAN	"gaussian"
        #define	LXsICVAL_RENDER_AAFILTER_CATMULL	"catmull"
        #define	LXsICVAL_RENDER_AAFILTER_MITCHELL	"mitchell"

        // Render "field" Channel Text Hints
        #define	LXsICVAL_RENDER_FIELD_OFF		"off"
        #define	LXsICVAL_RENDER_FIELD_UPPER		"upper"
        #define	LXsICVAL_RENDER_FIELD_LOWER		"lower"

        // Render "bktOrder" Channel Text Hints
        #define	LXsICVAL_RENDER_BKTORDER_ROWS		"rows"
        #define	LXsICVAL_RENDER_BKTORDER_COLUMNS	"columns"
        #define	LXsICVAL_RENDER_BKTORDER_SPIRAL		"spiral"
        #define	LXsICVAL_RENDER_BKTORDER_HILBERT	"hilbert"
        #define	LXsICVAL_RENDER_BKTORDER_RANDOM		"random"

        #define	LXsICVAL_RENDER_BAKE_RGBA		"rgba"
        #define	LXsICVAL_RENDER_BAKE_RGB		"rgb"
        #define	LXsICVAL_RENDER_BAKE_RED_ONLY		"red"
        #define	LXsICVAL_RENDER_BAKE_GREEN_ONLY		"green"
        #define	LXsICVAL_RENDER_BAKE_BLUE_ONLY		"blue"
        #define	LXsICVAL_RENDER_BAKE_ALPHA_ONLY		"alpha"
        #define	LXsICVAL_RENDER_BAKE_SWIZZLING		"swizzling"


        // swizzling baking options
        #define LXi_BAKE_OUTPUT_FILT_PASS	0
        #define LXi_BAKE_OUTPUT_FILT_RGB	1
        #define LXi_BAKE_OUTPUT_FILT_R		2
        #define LXi_BAKE_OUTPUT_FILT_G		3
        #define LXi_BAKE_OUTPUT_FILT_B		4
        #define LXi_BAKE_OUTPUT_FILT_A		5

        #define LXi_BAKE_SWIZZLING_RGBA		0
        #define LXi_BAKE_SWIZZLING_RGB		1
        #define LXi_BAKE_SWIZZLING_R		2
        #define LXi_BAKE_SWIZZLING_G		3
        #define LXi_BAKE_SWIZZLING_B		4
        #define LXi_BAKE_SWIZZLING_A		5
        #define LXi_BAKE_SWIZZLING_PASS		6


        #define LXu_TABLEAUSURFACE1	"B5769A8B-6254-42E3-862F-0A811E716E21"
        // [local]   ILxTableauSurface1
        // [export]  ILxTableauSurface1 tsrf
        // [default] ILxTableauSurface1:FeatureCount   = 0
        // [default] ILxTableauSurface1:FeatureByIndex = LXe_OUTOFBOUNDS



        #define	LXi_ENVMATERIAL_ENVTYPE_CONSTANT	0
        #define	LXi_ENVMATERIAL_ENVTYPE_GRAD2		1
        #define	LXi_ENVMATERIAL_ENVTYPE_GRAD4		2
        #define	LXi_ENVMATERIAL_ENVTYPE_OVERCAST	3
        #define	LXi_ENVMATERIAL_ENVTYPE_PHYSICAL	4
        #define	LXi_ENVMATERIAL_ENVTYPE_CLEAR		5

/*
 * A bake item represents a rendering process, and it presents the user-editable
 * attributes of the baking as channels for the user.  There can be different
 * kinds of bake items, such as render output baking, texture baking, etc.
 */

        // Bake item type and channels
        #define	LXsITYPE_BAKE				"bake"
        #define	LXsICHAN_BAKE_UVNAME			"uvname"
        #define	LXsICHAN_BAKE_MORPHNAME			"morphname"
        #define	LXsICHAN_BAKE_DISTANCE			"distance"
        #define	LXsICHAN_BAKE_BAKEFROM			"bakeFrom"
        #define	LXsICHAN_BAKE_HIDDEN_TGT		"hiddenTarget"
        #define	LXsICHAN_BAKE_HIDDEN_SRC		"hiddenSource"
        #define	LXsICHAN_BAKE_HIDDEN_OUT		"hiddenOutput"
        #define	LXsICHAN_BAKE_RGBAFROM			"rgbaFrom"
        #define	LXsICHAN_BAKE_RGBATO			"rgbaTo"
        #define	LXsICHAN_BAKE_SAVE_OUTPUT_FILE		"saveOutputFile"
        #define	LXsICHAN_BAKE_USE_NORMAL_PRESET		"useNormalPreset"

        // Bake item render output specific channel
        #define	LXsICHAN_BAKERO_WIDTH			"width"
        #define	LXsICHAN_BAKERO_HEIGHT			"height"
        #define	LXsICHAN_BAKERO_OUTPUT_PATTERN		"outPattern"
        #define	LXsICHAN_BAKERO_OUTPUT_LOCATION		"outLocation"
        #define	LXsICHAN_BAKERO_OUTPUT_FORMAT		"outFormat"
        #define	LXsICHAN_BAKERO_USE_UDIM		"useUDIM"
        #define	LXsICHAN_BAKERO_START_UDIM		"startUDIM"
        #define	LXsICHAN_BAKERO_END_UDIM		"endUDIM"

        #define	LXsITYPE_BAKE_RENDER_OUTPUTS		"bakeItemRO"
        #define	LXsITYPE_BAKE_TEX_LAYERS		"bakeItemTexture"

/*
 * The Bake items use 2 different graphs to connect to the surface items and outputs items
 * that are included in the bake.
 */

        #define LXsGRAPH_BAKE_SURF		"bakeSurf"
        #define LXsGRAPH_BAKE_OUTPUT		"bakeOutput"
        #define LXsGRAPH_BAKE_SOURCE		"bakesource"
        #define LXsGRAPH_BAKE_TEX_LAYER		"baketexture"


        #define LXiTBX_CHANS_T0			0
        #define LXiTBX_CHANS_T1			1
        #define LXiTBX_CHANS_FRAME		2

/*
 * EltNotify can have the following events.
 */

        #define LXiTBX_SURF_ADD			0x0
        #define LXiTBX_SURF_REMOVE		(LXiTBX_SURF_ADD + 1)
        #define LXiTBX_SURF_GEO			(LXiTBX_SURF_REMOVE + 1)
        #define LXiTBX_SURF_XFRM		(LXiTBX_SURF_GEO + 1)
        #define LXiTBX_SURF_SHADER		(LXiTBX_SURF_XFRM + 1)

        #define LXiTBX_LGT_ADD			(LXiTBX_SURF_SHADER + 1)
        #define LXiTBX_LGT_REMOVE		(LXiTBX_LGT_ADD + 1)
        #define LXiTBX_LGT_DATA			(LXiTBX_LGT_REMOVE + 1)
        #define LXiTBX_LGT_XFRM			(LXiTBX_LGT_DATA + 1)
        #define LXiTBX_LGT_SHADER		(LXiTBX_LGT_XFRM + 1)
        #define LXiTBX_LGT_GEO			(LXiTBX_VOL_SHADER + 1)

        #define LXiTBX_VOL_ADD			(LXiTBX_LGT_SHADER + 1)
        #define LXiTBX_VOL_REMOVE		(LXiTBX_VOL_ADD + 1)
        #define LXiTBX_VOL_DATA			(LXiTBX_VOL_REMOVE + 1)
        #define LXiTBX_VOL_XFRM			(LXiTBX_VOL_DATA + 1)
        #define LXiTBX_VOL_SHADER		(LXiTBX_VOL_XFRM + 1)
        

/*
 * And InstNotify has a smaller set of events.
 */

        #define LXiTBX_INST_ADD			0x0
        #define LXiTBX_INST_REMOVE		(LXiTBX_INST_ADD + 1)
        #define LXiTBX_INST_XFRM		(LXiTBX_INST_REMOVE + 1)


        #define LXu_TABLEAU	"76C4EDD9-5FF9-4342-BB08-EFCD0B344004"
        // [local]  ILxTableau
        // [python] ILxTableau:Channels		obj ChannelRead (action)
        // [python] ILxTableau:FindShader	obj TableauShader
        // [python] ILxTableau:Visible		bool


        #define LXe_INFINITE_BOUND	LXxGOODCODE(LXeSYS_REND,1)

/*
 * This feature type and set of names define the most basic set of features
 * that most elements support.  Velocity is in object space.  Normals exist
 * only for surface samples, and radius is meaningful only for line samples.
 */

        #define LXiTBLX_BASEFEATURE	LXxID4(' ','v','r','t')
        #define LXsTBLX_FEATURE_POS		"pos"
        #define LXsTBLX_FEATURE_OBJPOS		"opos"
        #define LXsTBLX_FEATURE_VEL		"vel"
        #define LXsTBLX_FEATURE_NORMAL		"norm"
        #define LXsTBLX_FEATURE_RADIUS		"rad"
        #define LXsTBLX_FEATURE_PARAM_LENGTH	"plen"
        #define LXsTBLX_FEATURE_PARTID		"partID"
        #define LXsTBLX_FEATURE_RADIANCE	"radiance"
        #define LXsTBLX_FEATURE_TENSION		"tension"
        #define LXsTBLX_FEATURE_TORSION		"torsion"
 	#define LXiTBLX_DPDU		LXxID4('d','p','d','u')
        #define LXiTBLX_TBASIS		LXxID4('T','B','A','S')


        #define LXu_TABLEAUELEMENT	"71D90AD9-3E30-4CE8-9E2B-F70DA281B2DC"
        #define LXa_TABLEAUELEMENT	"tableauElement"
        // [local]  ILxTableauElement

/*
 * The Bound() method for surfaces (since it cannot return "infinite") may also return
 * a success code indicating that the surface supports adaptive subdivision.
 */

        #define LXeTBLXSURF_ADAPTIVE	 LXxGOODCODE(LXeSYS_REND,2)


        #define LXiTBLX_SEG_POINT	 1
        #define LXiTBLX_SEG_LINE	 2
        #define LXiTBLX_SEG_TRIANGLE	 3

/*
 * - QUAD
 * This indicates that two triangles form a quad. If a quad is given by the points
 * 0, 1, 2, 3, then the calls would be polygon(0,1,2), connect(QUAD), polygon(0,2,3).
 * For clients that understand quads, the last point of the second triangle is the
 * fourth point of the quad.
 * - BEGIN, END
 * These mark the start and end of continuous curves. If the soup has type
 * 2, such that each polygon is really a pair of endpoints, then this can be used
 * to indicate that the lines are really part of a curve. For a curve consisting of
 * the points 0, 1, 2, 3, the calling sequence is connect(BEGIN), polygon(0,1),
 * polygon(1,2), polygon(2,3), polygon(3,4), connect(END).
 */

        #define LXiTBLX_CONNECT_QUAD	 0
        #define LXiTBLX_CONNECT_BEGIN	 1
        #define LXiTBLX_CONNECT_END	 2


        #define LXu_TABLEAUSURFACE	"F785D229-6BA5-4C8E-9994-3E502053B83C"
        // [local]   ILxTableauSurface
        // [export]  ILxTableauSurface tsrf
        // [default] ILxTableauSurface:FeatureCount   = 0
        // [default] ILxTableauSurface:FeatureByIndex = LXe_OUTOFBOUNDS

        #define LXu_TRIANGLESOUP	"17536C2D-07BD-49C8-8348-CEBDE4D3A856"
        // [local]   ILxTriangleSoup
        // [export]  ILxTriangleSoup soup
        // [default] ILxTriangleSoup:TestBox = 1
        // [default] ILxTriangleSoup:Segment = LXe_TRUE

/*
 * Volume elements are 3D elements with a depth and internal structure.  They need
 * to be evaluated over the entire volume rather than just at the 2D surface.
 * - Type
 * Returns the volume evaluate flags. We support 3 types that can be implemented simultaneously
 * on the same element:
 */

        #define LXfTBLX_VOL_VOLUME	 1
        #define LXfTBLX_VOL_CLIPPING	 2
        #define LXfTBLX_VOL_IMPSURF	 4
        #define LXfTBLX_VOL_LOCAL_SHADER	 5


        #define LXu_TABLEAUVOLUME	"97962302-4B49-4282-B259-F347F1012818"
        #define LXa_TABLEAUVOLUME	"tableauVolume"
        // [local]   ILxTableauVolume
        // [export]  ILxTableauVolume tvol
        // [default] ILxTableauVolume:FeatureCount   = 0
        // [default] ILxTableauVolume:FeatureByIndex = LXe_OUTOFBOUNDS


        #define LXu_TABLEAULIGHT	"7FE816D1-4A7F-4BE5-9689-4991C03CAEE0"
        #define LXa_TABLEAULIGHT	"tableauLight"
        #define LXu_LIGHTSAMPLE		"43734621-9B93-4174-AC63-E2FE7DDA8794"
        // [local]   ILxTableauLight
        // [export]  ILxTableauLight tlgt
        // [default] ILxTableauLight:FeatureCount   = 0
        // [default] ILxTableauLight:FeatureByIndex = LXe_OUTOFBOUNDS
        // [local]   ILxLightSample


        #define LXsP_LGT_QUALITY	"light.quality"
        #define LXsP_LGT_SHADOWING	"light.shadowing"
        #define LXsP_LGT_SOURCE		"light.source"
        #define LXsP_LGT_COLOR		"light.color"

/*
 * These are the texture effect names that apply to lights.
 */

        #define LXs_FX_LIGHTCOLOR	"lightColor"
        #define LXs_FX_LIGHTSHADOW	"lightShadow"
        #define LXs_FX_LIGHTDIFFUSE	"lightDiffuse"
        #define LXs_FX_LIGHTSPECULAR	"lightSpecular"
        #define LXs_FX_LIGHTCAUSTICS	"lightCaustics"
        #define LXs_FX_LIGHTDISTANCE	"lightDistance"
        #define LXs_FX_LIGHTANGLE	"lightAngle"

/*
 * These are the texture effect names that apply to volumetrics.
 */

        #define LXs_FX_VOLSCATTER	"volScattering"
        #define LXs_FX_VOLSCATTER_COL	"volScatteringColor"
        #define LXs_FX_VOLABSORB	"volAbsorption"
        #define LXs_FX_VOLABSORB_COL	"volAbsorptionColor"
        #define LXs_FX_VOLDENSITY	"volDensity"
        #define LXs_FX_VOLLEVEL		"volLevel"
        #define LXs_FX_VOLSMPDENSITY	"volSampleDensity"
        #define LXs_FX_VOLAMB_COL	"volAmbientColor"
        #define LXs_FX_VOLLUMI		"volLuminosity"
        #define LXs_FX_VOLLUMI_COL	"volLuminosityColor"


        #define LXu_TABLEAUPROXY	"FB34BD64-099C-4B30-8EF7-2BB04CA0E92C"
        #define LXa_TABLEAUPROXY	"tableauProxy"
        // [local]   ILxTableauProxy
        // [export]  ILxTableauProxy tpro
        // [default] ILxTableauProxy:FeatureCount   = 0
        // [default] ILxTableauProxy:FeatureByIndex = LXe_OUTOFBOUNDS


        #define LXu_TABLEAUINSTANCE	"77837A98-2BC5-466C-834F-DC937642558B"
        #define LXa_TABLEAUINSTANCE	"tableauInstance2"
        // [local]   ILxTableauInstance
        // [export]  ILxTableauInstance tins
        // [default] ILxTableauInstance:Properties = LXe_OK

        #define LXiTBLX_ENDPOINT_T0	 0
        #define LXiTBLX_ENDPOINT_T1	 1


        #define LXu_TABLEAUSHADER	"A0E3B574-B0AC-4530-A43F-7CC8DA536E25"
        #define LXa_TABLEAUSHADER	"tableauShader"
        #define LXu_SHADERSLICE		"47B885B9-B1D9-4F86-829F-A6AABBD7FFF7"
        // [export] ILxTableauShader tsha
        // [local]  ILxTableauShader
        // [python] ILxTableauShader:Slice	obj ShaderSlice
        // [local]  ILxShaderSlice

/*
 * There are actually two camera ray packets.  The default one contains the camera
 * ray at time t0, the start interval for the tableau.  The second ray packet
 * contains the ray at time T1, the end of the interval.  Good environment shaders
 * will interpolate colors along an arc between the two rays to account for motion
 * blurring of the environment as the camera rotates.
 */

        #define LXsP_CAM_RAY		"camera.ray"
        #define LXsP_CAM_RAY_T1		"camera.ray_T1"
        #define LXsP_ENV_INFINITECOLOR	"environment.color"
        #define LXsP_ENV_VISIBILITY	"environment.visibility"
        #define LXsP_GLO_LIGHTING	"global.lighting"
        #define LXsP_GLO_DISPLACEMENT	"global.displacement"
        #define LXsP_GLO_INDIRECT	"global.indirect"
        #define LXsP_GLO_CAUSTICS	"global.caustics"
        #define LXsP_GLO_RENDERING	"global.rendering"

/*
 * The frustum may be a source of motion blur, so the renderer will query for one
 * at time T0 and another at time T1.  If the T1 frustum is missing, the camera
 * is assumed to be non-moving.
 */

        #define LXsP_CAM_RESOLUTION	"camera.resolution"
        #define LXsP_CAM_FRUSTUM	"camera.frustum"
        #define LXsP_CAM_FRUSTUM_T1	"camera.frustum_T1"
        #define LXsP_CAM_PIXEL		"camera.pixel"
        #define LXsP_CAM_UVBAKE		"camera.uvBake"

/*
 * - PIXEL
 * the filter can process individual pixels, and the Pixel() method is used
 * rather than the region method.  If the kernel is also zero then the filter
 * can be used on a single pixel at a time without needing any other region
 * information.
 * - STRIP
 * the filter requires complete strips in order to run.  The Region() method
 * will be called with strips scanned from top to bottom of the image.  This
 * is typically used by filters which act as image-savers.
 * - RELATIVE
 * the filter's bounding box and kernel are given as a percentage of the
 * minimum dimenion of the entire frame.  This allows for filters that are
 * independent of the size of the rendering.
 * 
 */

        #define LXfTBLX_FILT_PIXEL	 0x01
        #define LXfTBLX_FILT_STRIP	 0x02
        #define LXfTBLX_FILT_RELATIVE	 0x04


        #define LXu_TABLEAUFILTER	"FD1326E7-EECF-4EAC-B9AD-B1D64E7503BE"
        #define LXa_TABLEAUFILTER	"tableauFilter"

/*
 * A channel change can have no affect on the preview, or it may be necessary
 * to update the geometry or the shading. The item can decide how individual
 * channels should update the preview by returning the appropriate combination
 * of the following values when the PreviewUpdate function is called.
 */

        #define LXfTBLX_PREVIEW_UPDATE_NONE	 0x00
        #define LXfTBLX_PREVIEW_UPDATE_GEOMETRY	 0x01
        #define LXfTBLX_PREVIEW_UPDATE_SHADING	 0x02

/*
 * Any item can potentially participate in rendering by adding elements to the
 * tableau.  Any item (or package) which presents the following interface will
 * get called upon when it's time to create a tableau from a cinema.
 * - Elements
 * This is called to let the item add elements directly to a tableau.
 * - Preview
 * This is similar, but is used for adding elements needed to preview this item.
 * 
 * - Instance
 * This will be called by other items which want instances of this item. The
 * item should add elements to instance itself given the tableua instance
 * object as reference.
 * 
 * - SubShader
 * Elements such as lights can affect their own shading. If that's the case,
 * this method will be called to allow the item to create a shader to be used
 * as a part of the shader for this item.
 * 
 * - GetCurves
 * Elements may be able to provide curves which can be used as hair guides. The
 * string tag interface selects a subset of curves, and the object returned is
 * a tableau surface element which can be sampled.
 * 
 * - ElementType
 * If implemented, ElementType allows the tableau source to specify what types
 * of elements it can add to the tableau. It is queried with one of the following
 * types, and puts 1 into *supported if it will add elements of that type, 0 if it
 * won't, or -1 if it doesn't know.
 * 
 */

        #define LXiTBXELT_SURFACE	0
        #define LXiTBXELT_VOLUME	1
        #define LXiTBXELT_LIGHT		2
        #define LXiTBXELT_FILTER	3
        #define LXiTBXELT_PROXY		4


        #define LXu_TABLEAUSOURCE	"9CC7F9F4-9540-4EEA-8EE9-710D58EC68F9"
        // [local]   ILxTableauSource
        // [export]  ILxTableauSource tsrc
        // [default] ILxTableauSource:ElementType = LXe_NOTIMPL

/*
 * The cleanest way for items to provide elements that can be instanced is
 * to implement an Instanceable object. This is stored in an OBJREF channel
 * on the item, given by a server tag on the package. The item type will
 * implement a modifier for computing the instanceable object from the state
 * of the item's channels.
 */

        #define LXu_INSTANCEABLE	"9CC7F9F4-9540-4EEA-8EE9-710D58EC68F9"
        // [local]   ILxInstanceable
        // [export]  ILxInstanceable instable

        #define LXsPKG_INSTANCEABLE_CHANNEL	"inst.channel"


        #define LXu_TABLEAUSERVICE	"8DF92316-3172-465A-A199-254792D37732"
        // [python] ILxTableauService:AllocVertex	obj TableauVertex


        #define LXfECHAN_LOCATOR	0x40000000

        #define LXiNODAL_NOT_DRIVEN	0xFFFFFFFF

        #define LXu_NODALSERVICE	"2055F206-1682-11E3-9F05-6ACC6088709B"
        // [local]  ILxNodalService
        // [const]  ILxNodalService:GetFloat
        // [const]  ILxNodalService:GetInt
        // [const]  ILxNodalService:GetValue


        #define LXu_TABLEAULISTENER	"848C5B64-4C9F-404E-8E3F-CF725007F74D"
        // [export] ILxTableauListener tli


        #define LXu_TABLEAUSOURCE1	"1121C167-F934-4421-8ABE-32F8E4659324"
        // [export]  ILxTableauSource1 tsrc


        #define LXu_TABLEAUINSTANCE1	"9B57D0DB-C0B4-435E-8CDD-E3DDCF66172D"
        #define LXa_TABLEAUINSTANCE1	"tableauInstance"


        // Environment Material Item Type and Channels
        #define	LXsITYPE_ENVMATERIAL			"envMaterial"
        #define	LXsICHAN_ENVMATERIAL_TYPE		"type"
        #define	LXsICHAN_ENVMATERIAL_ZENCOLOR		"zenColor"
        #define	LXsICHAN_ENVMATERIAL_SKYCOLOR		"skyColor"
        #define	LXsICHAN_ENVMATERIAL_GNDCOLOR		"gndColor"
        #define	LXsICHAN_ENVMATERIAL_NADCOLOR		"nadColor"
        #define	LXsICHAN_ENVMATERIAL_SKYEXP		"skyExp"
        #define	LXsICHAN_ENVMATERIAL_GNDEXP		"gndExp"
        #define	LXsICHAN_ENVMATERIAL_HAZE		"haze"
        #define	LXsICHAN_ENVMATERIAL_NORMALIZE		"normalize"
        #define	LXsICHAN_ENVMATERIAL_DISC		"disc"
        #define	LXsICHAN_ENVMATERIAL_CLMPGAMMA		"clampedGamma"
        #define	LXsICHAN_ENVMATERIAL_FOG_TYPE		"fogType"
        #define	LXsICHAN_ENVMATERIAL_FOG_START		"fogStart"
        #define	LXsICHAN_ENVMATERIAL_FOG_END		"fogEnd"
        #define	LXsICHAN_ENVMATERIAL_FOG_DENSITY	"fogDensity"
        #define	LXsICHAN_ENVMATERIAL_FOG_HEIGHT		"fogHeight"
        #define	LXsICHAN_ENVMATERIAL_FOG_FALLOFF	"fogFalloff"
        #define	LXsICHAN_ENVMATERIAL_ALBEDOCOLOR	"albedo"
        #define	LXsICHAN_ENVMATERIAL_DISCCOLOR		"discCol"
        #define	LXsICHAN_ENVMATERIAL_INSCATTER		"inscatter"

        // Environment Material "type" Channel Text Hints
        #define	LXsICVAL_ENVMATERIAL_ENVTYPE_CONSTANT	"constant"
        #define	LXsICVAL_ENVMATERIAL_ENVTYPE_GRAD2	"grad2"
        #define	LXsICVAL_ENVMATERIAL_ENVTYPE_GRAD4	"grad4"
        #define	LXsICVAL_ENVMATERIAL_ENVTYPE_OVERCAST	"overcast"
        #define	LXsICVAL_ENVMATERIAL_ENVTYPE_PHYSICAL	"physical"

#endif
