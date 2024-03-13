/*
 * LX vector module
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
#ifndef LX_vector_H
#define LX_vector_H

typedef struct vt_ILxVectorPacket ** ILxVectorPacketID;
typedef struct vt_ILxVectorPacket1 ** ILxVectorPacket1ID;
typedef struct vt_ILxPacketService ** ILxPacketServiceID;
typedef struct vt_ILxVectorType ** ILxVectorTypeID;
typedef struct vt_ILxVectorStack ** ILxVectorStackID;
typedef struct vt_ILxVectorList ** ILxVectorListID;
typedef struct vt_ILxTextureEffect ** ILxTextureEffectID;
typedef struct vt_ILxPacketEffect ** ILxPacketEffectID;

#include <lxcom.h>
#include <lxvmath.h>

/*
 * Here we define the nodal effects associated to that packet, this is how we can present nodes in the schematic
 * with copnnections that oparate on the packet.
 */

        typedef enum VPacketPubType {
                PPUB_Float = 0,
                PPUB_Double,
                PPUB_Int,
        } VPacketPubType;

/*
 * These types are defined as opaque pointers as a temporary measure.
 * NOTE: TEMPORARY.
 */

        typedef struct st_GenVector *	LXtGenVectorID;


        typedef struct st_GenVector *	 LXtSampleVectorID;


/*
 * In general the offset should NOT be looked up in the shader\texture evaluate function because it is too slow.
 * It is better to get the offset during setup like when reading channel values.
 * Textures and shaders are computed using mostly geometric data.  This includes the set of
 * positions in the various reference spaces, the set of object transformation
 * matrices, the ray information for ray tracing contexts, and the spot
 * information.  The 'uv' array actually contains any features requested for the
 * surface beyond the standard 12, and 'duv' and 'dpduv' is filled in for those
 * features only if the corresponding shader requests the sample-transform packet.
 */
typedef struct st_LXpSamplePosition {
        LXtVector	 wPos;		// position in world space
        LXtVector	 wVel;		// velocity in world space (meters traveled during exposure)
        LXtVector	 oPos;		// position in object space
        LXtVector	 uPos;		// undisplaced position in object space
        float		 spot;		// spot size (width of sample perpendicular to incoming ray)
        float		 bias;		// distance by which wPos is adjusted to prevent self-shadowing
        int		 infinite;	// indicates an environment sample
        float		*uv;		// variable-length UV array
        float		*duv;		// variable-length UV delta array (like RenderMan's du and dv)
        LXtFVector	*dpduv;		// normalized UV derivative array (like RenderMan's dPdu and dPdv)
        int		*offset;	// variable-length feature offsets
        float		*dpduvLen;	// variable-length array of UV derivative vector lengths
        LXtVector	 pPos;		// world space position implied by Phong smoothing

        // NOTE: SVPositionCopy() is used for copying two SamplePosition packets, if you modify this struct, please update the SVPositionCopy()
} LXpSamplePosition;

typedef struct st_LXpSampleTransform {
        LXtMatrix	 transform;	// direct transformation
        LXtMatrix	 invert;	// inverse transformation
        LXtVector	 scale;		// object scale
        LXtVector	 wpos;		// object world position
} LXpSampleTransform;

typedef struct st_LXpSampleRay {
        LXtVector	 origin;	// origin of the ray (position)
        LXtFVector	 dir;		// direction of the ray
        LXtFVector	 color;		// color seen by the ray
        LXtFVector	 abc;		// absorption coefficients
        float		 dist;		// distance travelled by the ray
        float		 prevDist;	// total distance travelled by previous segments of the ray
        float		 nearClip;	// near and far clipping distances
        float		 farClip;
        float		 importance;	// starts at one, then diminishes as the ray tree splits
        float		 prevSpot;	// spot size of ray at its origin
        float		 cone;		// cone angle of the ray (spot = prevSpot + dist * cone)
        float		 eta;		// refractive index of the material in which the ray is traveling
        float		 wavelength;	// wavelength in nanometers for monochromatic dispersion rays
        int		 bounces;	// number of bounces
        int		 thread;	// thread number
        unsigned int	 flags;		// ray evaluation flags
        int              rayID;         // number of this ray (as a uniqueness identifier)
} LXpSampleRay;

typedef struct st_LXpSampleClip {
        void		*elt;	// clipping element ID
        float		 dist;	// clip distance on the ray
        float		 delta;	// difference between original and modified sample position on the ray
} LXpSampleClip;

/*
 * The first six members here are the colored and textured material coefficients.
 * They are multiplied by the corresponding amounts before being used by the
 * default shading functions.
 */
typedef struct st_LXpSampleParms {
        LXtFVector	 diffCol;	// diffuse color
        LXtFVector	 specCol;	// specular color
        LXtFVector	 reflCol;	// mirror reflection color
        LXtFVector	 tranCol;	// transparency color
        LXtFVector	 subsCol;	// subsurface scattering color
        LXtFVector	 lumiCol;	// luminous color
        LXtFVector	 exitCol;	// exit color
        LXtFVector	 clipCol;	// clipping color
        LXtFVector	 anisoDir;	// anisotropy direction (raw color)
        LXtFVector	 anisoDpdu;	// anisotropy U derivative
        LXtFVector	 anisoDpdv;	// anisotropy V derivative
        LXtFVector	 dif0;		// base diffuse (untextured) for irradiance interpolation
        LXtFVector	 sss0;		// base sss (untextured) for irradiance interpolation
        float		 diffAmt;	// diffuse amount
        float		 specAmt;	// specular amount
        float		 reflAmt;	// mirror reflection amount
        float		 tranAmt;	// transparency amount
        float		 subsAmt;	// subsurface scattering amount
        float		 lumiAmt;	// luminous amount
        float		 coatAmt;	// clearcoat amount
        float		 dissAmt;	// dissolve amount
        float		 bumpAmt;	// bump strength
        float		 bumpAmp;	// bump amplitude
        float		 diffRough;	// diffuse roughness (for Oren-Nayar BRDF)
        float		 clipVal;	// clipping value associated to material
        float		 rough;		// roughness value before it is converted into specular exponents
        float		 aniso;		// anisotropy strength (variation of U and V specular exponents)
        float		 anisoCos;	// anisotropy direction cosine
        float		 anisoSin;	// anisotropy direction sine
        float		 specExpU;	// specular exponent in U direction
        float		 specExpV;	// specular exponent in V direction
        float		 specFres;	// specular fresnel amount
        float		 reflFres;	// reflection fresnel amount
        float		 refIndex;	// refractive index
        float		 disperse;	// dispersion (variation of refractive index with wavelength)
        float		 tranRough;	// transparency roughness
        float		 tranDist;	// absorption distance
        float		 subsDist;	// scattering distance
        float		 subsDepth;	// scattering max depth
        float		 subsPhase;	// scattering phase function (forward/backward balance)
        int		 reflType;	// reflection type
        int		 reflRays;	// reflection rays
        int		 tranRays;	// refraction rays
        int		 subsRays;	// subsurface scattering rays
        int		 flags;		// give shaders access to LXfSURF_* flags
        int		 uvOffset;	// offset used to get u,v derivatives (for anisotropy)
        int		 vectOffset;	// offset used to get vector vmap (also for anisotropy)
        int		 clearBump;	// clear pre existing bumps
        int		 clipEnable;	// enable render clipping on surface
        int		 clipMatte;	// render clip surface as matte color
        int		 clipped;	// surface sample is clipped
        int		 radInterpol;	// radiance interpolation flag
        int		 brdfType;	// brdf type
        int		 shaderModel;	// shader Model: modo buildin, unreal, unity .. more ..
        float		 coatRough;	// clearcoat roughness
        float		 coatBump;	// clearcoat bump strength
// Added in 902:
        float		 projCulling;	// front projection culling
        float		 metallic;	// metallic - moves diffuse color to specular color
        float		 normAmt;	// normal amount
// Principled features:
        float		 sheen;		// sheen amount
        float		 sheenTint;	// sheen tint amount
        float		 specTint;	// specular tint amount
        float		 flatness;	// fake subsurface amount

// Added in 10.2:
        float		 importance;	// importance multiplier for sample counts
} LXpSampleParms;

/*
 * // SampleParms for Unreal4
 */
typedef struct st_LXpSampleUnrealParms {
        LXtFVector	 baseColor;
        LXtFVector	 emissiveColor;
        float		 specular;
        float		 opacity;
} LXpSampleUnrealParms;

/*
 * // SampleParms for Unity5
 */
typedef struct st_LXpSampleUnityParms {
        LXtFVector	 baseAlbedo;
        LXtFVector	 albedo;
        LXtFVector	 albedo2;
        LXtFVector	 emission;
        LXtFVector	 tangentNorm;
        LXtFVector	 vT;
        LXtFVector	 vB;
        LXtFVector	 vN;
        float		 emissiveLevel;
        float		 smoothness;
        float		 dielectricSpec;
        float		 normalScale;
        float		 normalScale2;
        float		 heightScale;
        float		 detailMask;
} LXpSampleUnityParms;

/*
 * // SampleParms for glTF
 */
typedef struct st_LXpSampleGLTFParms {
        LXtFVector	baseBaseColor;
        LXtFVector	baseColor;
        LXtFVector	albedo2;
        LXtFVector	baseEmission;
        LXtFVector	emission;
        LXtFVector	tangentNorm;
        LXtFVector	vT;
        LXtFVector	vB;
        LXtFVector	vN;
        float		emissiveLevel;
        float		baseRoughness;
        float		roughness;
        float		baseMetallic;
        float		metallic;
        float		normalScale;
        float		ambientOcclusionScale;
        int			shadeModel;
} LXpSampleGLTFParms;

/*
 * // SampleParms for AXF
 */
typedef struct st_LXpSampleAXFParms {
        LXtFVector	baseColorChanVal, baseColorTxtVal;
        LXtFVector	specularColorChanVal, specularColorTxtVal;

        // Normals
        LXtFVector	tangentNorm;
        LXtFVector	vT;
        LXtFVector	vB;
        LXtFVector	vN;
        float		normalScale;

        // Specular roughness
        float		tRoughness;
        float		bRoughness;
        float		roughnessScale;

        // Specular fresnel
        float		fresnelChanVal, fresnelTxtVal;

        // Transparency
        float		alphaChanVal, alphaTxtVal;

        // Anisotropy
        float		anisotropyStrength;

        // Clearcoat
        float		clearcoatAmount;
        float		clearcoatIORTxtVal;

        // Displacement
        float		displacementDistance;
} LXpSampleAXFParms;

/*
 * // SampleParms for Recolouring
 */
typedef struct st_LXpSampleRecolorParms {
        LXtFVector	 recolorOriginal;	// Color of the scanned material.
        LXtFVector	 recolorFrom;		// Base BOM - color of the dye that the recolorOriginal scanned material is dyed with.
        LXtFVector	 recolorTo;		// Target BOM - color of the dye that should be used instead.
        LXtFVector	 matMap;
} LXpSampleRecolorParms;

/*
 * This is used for shader masking.
 */
typedef struct st_LXpSampleMask {
        float		 groupOpacity;	// the opacity for a shader group
        float		 layerOpacity;	// the opacity for a layer
        int		 layerOverride;	// true if the layer evaluation should use the layerOpacity
        float		 layerOpacityMasked;	// the opacity for a layer including the effect of a mask layer (if any)
} LXpSampleMask;

typedef struct st_LXpSampleGroupMask {
        float		 groupOpacity;	// the opacity for a shader group
} LXpSampleGroupMask;

/*
 * This is used for texturing as custom channels.
 */
typedef struct st_LXpSampleDriver {
        float		 a, b, c, d;
} LXpSampleDriver;

/*
 * This packet is used for sample stenciling (AKA clip mapping) which happens at
 * the ray/geometry intersection level before any shading is computed.
 * 'textureCount' holds the number of stencil textures for a given a slice.  It is
 * important because some shaders like materials simply clear the stencil value,
 * which means they don't need all the texturing data normally passed to shaders.
 * So if the number of textures is 0 we can skip the texture evaluation setup
 * entirely, which greatly speeds up raytracing.  'texturePass' is true when the
 * stencil slice is evaluated for the number of textures.
 */
typedef struct st_LXpSampleStencil {
        float		 value;
        int		 textureCount;
        int		 texturePass;
        int		 additive;
} LXpSampleStencil;

/*
 * This packet is used for volumetric rendering.
 */
typedef struct st_LXpSampleVolume {
        LXtFVector	 scatter;
        LXtFVector	 absorb;
        LXtFVector	 ambient;
        LXtFVector	 luminosity;
        float		 scatterAmt;
        float		 absorbAmt;
        float		 luminosityAmt;
        float		 attenuate;
        float		 shift;
} LXpSampleVolume;

typedef struct st_LXpSampleFluid {
        float		 pressure;
        float		 temperature;
        float		 fuel;
} LXpSampleFluid;

/*
 * This packet is used for volume density rendering.
 */
typedef struct st_LXpSampleDensity {
        float		 density, density0;
        float		 level;
} LXpSampleDensity;

/*
 * This packet is used for sample dissolve.
 */
typedef struct st_LXpSampleDissolve {
        float		 dissolve;
} LXpSampleDissolve;

/*
 * To compute things like bump and UV derivatives we need to know what the microfacet is.
 */
typedef struct st_LXpSampleFacet {
        LXtVector	 wPos[3];		// position in world space (note that we have to use double precision)
        LXtVector	 oPos[3];		// position in object space
        LXtVector	 uPos[3];		// undisplaced position in object space
        int		 flags;			// facet flags
} LXpSampleFacet;

/*
 * Bump evaluation uses the Bump packet. Bump is evaluated on the microfacet: each vertex of the microfacet is
 * displaced using the bumpHeight, the local normal and the bump amplitude. The resulting displaced normal is the
 * 'bump' vector in the packet.
 */
typedef struct st_LXpSampleBump {
        LXtVector	 dp;			// position delta during bump map evaluation
        LXtVector	 bump;			// this is the result of bump map evaluation: the bumped normal
        float		 bumpAmplitude;		// bump amplitude as set by the material
        float		 bumpHeight;		// bump height at sample position
        float		 rndWidth;		// rounded edge width
        int		 bumpMapping;		// flag set to true during bump mapping texture evaluation
        int		 texturePass;		// flag set to true during bump texture count pass
        int		 edgePass;		// flag set to true during rounded edge evaluation
        int		 textureCount;		// bump texture count
        int		 shadeCount;		// shader counter
        int		 shadeIndex;		// current shader evaluation index
} LXpSampleBump;

/*
 * Textures are shaders that set an effect, they all take one packet as input: TextureInput and
 * produce one output packet: TextureOutput. This packet is then converted by the texture engine
 * into a final TextureValue packet which is then applied to the various effects.
 * Thus the evaluation sequence goes like this: TextureInput -> TextureOutput -> TextureValue.
 * Texture input consists of the position of the sample in texture space, the spot size
 * in texture space and the evaluation context.
 */
typedef struct st_LXpTextureInput {
        LXtFVector	 tPos;		// position in texture space
        LXtFVector	 uvw;		// UVW coordinates computed from projection
        LXtFVector	 uvw0;		// raw UVW coordinates (before wrapping, repeat options, etc)
        LXtFVector	 scale;         // texture scale
        LXtFVector	 dpdu, dpdv;    // normalized U,V derivative vectors
        float		 tSize[2], tSpot;	// texture spot size
        float		 octaveMult;	// multiplier on the number octaves for fractal textures, always between (0,1). Similar to importance but for textures
        int		 adaptiveFreq;	// enables the adaptive frequencies on fractal textures
        int		 context;	// evaluation context
        int		 axis;		// texture axis (from the locator options)
        int		 uvOffset;	// UV vertex feature offset (used during texture evaluation)
        int		 partOffset;	// PartID vertex feature offset (used during texture evaluation)
        int		 uvTile[2];	// UV tiling options
        float		 uvWrap[2];	// UV wrapping sizes
        LXtMatrix	 uvXfrm;	// UV transformation matrix, only expected to hold Z rotation and offsets on 02 and 12 positions
        LXtMatrix	 uvRotXfrm;	// UV rotation only transformation matrix
        float		 uvRot;		// UV rotation
        int		 legacyUVRot;   // Legacy UV rotation order (pre-701 scenes)
        int		 useUDIM;	// boolean to read the UV offset information from the clip (UDIM) instead of texture locator
        int		 noTile;	// should be set to ignore UV tiling options (used in GL context)
        int		 projOnly;	// true when the texture requires a projection, like image maps
        int		 sampleMesh;	// flag which should be set when doing sample mesh previews
        int		 ignoreAlpha;	// flag which should be set when doing sample mesh previews
        float		 sampleScale;	// scale of the sample mesh
        int		 offRange;	// some projections may decide to render nothing outside the [0,1] UV range. In that case 'offRange' will be true
        float		 idParm;	// texture particle ID parameter as set during texture replication (note that it is not the same as the surface particle ID)
        int		 particleIdx;	// texture particle index in the particle array
        int		 particleEval;  // particle context flag set to true when evaluating particles, this can trigger specialised evaluations modes
        float		 particleRadius;// particle radius
        void		*particleData;
        int		 tangentType;   // normal map tangent vector options
        int		*idxTloc;	// indexes of texture locator channels in the evaluator
        int		 nodalEval;	// true for nodal shader evaluation
        int		 perSample;	// true if the shader needs per sample evaluation
// added in 902:
        int		 hasTBasis;

        LXtFQuaternion	 uvInvZRotQuat; // UV inversed Z rotation quaternion, used for rotation of tangent manifolds of normal textures
        float			 dpduLen, dpdvLen;    // variable-length U,V derivative vector lenghts
} LXpTextureInput;

/*
 * The result of a texture computation is stored in the PackOutput structure which
 * holds all the possible outputs.
 * 'direct' is the flag that tells the texture engine how to compute the texture
 * value packet.  If this is false, 'blend' will be used to interpolate between
 * the two colors, values, and alphas.
 * 'value' the two texture values.  Direct textures should only set the first value.
 * 'color' color values.
 * 'alpha' alpha values.
 * 'range' indicates the min and max values.
 * 'blend' is the parameter to use to interpolate between the two sets of values
 * for indirect textures.
 */
typedef struct st_LXpTextureOutput {
        int		 direct;
        double		 value[2];
        LXtVector	 color[2];
        double		 alpha[2];
        double		 range[2];
        double		 blend;
} LXpTextureOutput;

/*
 * Finally the texture output is converted into values after applying the 'blend'
 * and the layer's invert option.
 * 'value' is the base value derived from the texture output after blend and
 * invert are applied.
 * 'rgb' is the texture output base color multiplied by the texture value.
 * 'alpha' is the texture alpha channel.
 */
typedef struct st_LXpTextureValue {
        double		 value;
        double		 alpha;
        LXtVector	 color;
} LXpTextureValue;

/*
 * The texture locator packet contains the position and transformation of the
 * locator used for the texture evaluation.
 */
typedef struct st_LXpTextureLocator {
        LXtVector	 wPos;
        LXtVector	 oPos;
        LXtMatrix	 xfrm;
        LXtMatrix	 iXfrm;
        LXtMatrix	 irXfrm;
        LXtFVector	 textureOffset;
        float		 textureOffsetAmp;
} LXpTextureLocator;

/*
 * Surface samples have different normals for different purposes.  'gNorm' is
 * always the true geometric normal of the micropolygon.  The purpose of 'uNorm'
 * is to allow baking normal maps of displaced surfaces (it's what the final
 * normal is compared against).  'wNorm0' is the starting point for bump mapping,
 * and 'wNorm' is the fully bump mapped normal which should be used for shading.
 * The CC appended versions are for clearcoat normal mapping, which will use a separate
 * normal map for clearcoat, if coatNormal is nonzero.
 */
typedef struct st_LXpSampleSurfNormal {
        LXtFVector	 gNorm;		// geometric normal (without smoothing)
        LXtFVector	 uNorm;		// undisplaced normal (with smoothing but no displacement)
        LXtFVector	 wNorm0;	// initial shading normal (with smoothing but no bump textures)
        LXtFVector	 wNorm;		// final shading normal (with smoothing and bump textures)
        LXtFVector	 tangent;	// tangent vector, used by hair rendering
        LXtFVector	 normalMap;	// normal vector evaluated by normal map textures
        LXtFVector	 objectNrm;	// object normal vector evaluated by object normal map textures
        int		 oAxis, wAxis;	// dominant axis in object and world space
        int		 back;		// true if surface is backfacing
        int		 coatNormal;	// true if surface should use clearcoat normal in favour of normal
        LXtFVector	 wNormCC;	// final clearcoat normal (with smoothing and bump textures)
        LXtFVector	 normalMapCC;	// clearcoat normal vector evaluated by normal map textures
} LXpSampleSurfNormal;

/*
 * Surface smoothing parameters are stored in this packet.  This allows the
 * material engine to get this information down to the polygonal data, for
 * computing face normals.  These values do not vary over the surface.
 */
typedef struct st_LXpSampleSurfSmooth {
        float		 smooth, csa;	// smooth amount, cos(smooth angle)
        int		 dblSided;
} LXpSampleSurfSmooth;

/*
 * This packet is used to store the displacement values used by the renderer, that
 * is the maximum displacement and the textured displacement height.
 */
typedef struct st_LXpDisplace {
        LXtFVector	 dPos;		// displaced position
        LXtFVector	 vDsp;		// vector displacement (set by textures)
        float		 max;		// max displacement
        float		 amplitude;	// displacement amplitude (set by the material)
        float		 dist;		// displacement height (set by textures)
        int		 enable;	// enable flag set to true by displacement textures (so 0 means no displacement textures).
        int		 maxPass;	// true during the 'max' evaluation pass
} LXpDisplace;

/*
 * This packet is used to store the surface element shader type.
 * This value is used during shader evaluation to filter out shader groups of the wrong type.
 */
typedef struct st_LXpShaderType {
        int		 type, hidden;
        int		 layerIndex;
} LXpShaderType;

/*
 * This is used for group layering.
 * - Enum is true when we count the layers,
 * - Count is the number of layers (set by the enumeration)
 * - Index is the current layer index during shader evaluation.
 */
typedef struct st_LXpGroupLayer {
        int		 layerEnum;	// layer enumeration flag
        int		 layerScope;	// enumeration scope
        int		 layerCount;	// number of layers
        int		 layerIndex;	// current layer evaluation index
        int		 layerTotal;	// total number of groups with scope
} LXpGroupLayer;

/*
 * This packet is used to store the fur values used by the renderer, that
 * is the maximum fur size, ect.
 */
typedef struct st_LXpFurParms {
        float		 minDist;	// minimum distance between hairs at 100% density
        float		 length;	// hair length
        float		 width;		// hair width at root (percent of distance parameter)
        float		 flex;		// how much hair flexes
        float		 density;	// hair density
        float		 display;	// display density (percen of main density)
        float		 bumpAmp;	// bump amplitude for fur bump effects
        float		 curles;	// curles amplitude
        float		 clumps;	// clumps amplitude
        float		 clumpDens;	// clumps density
        float		 clumpSize;	// clump range (m)
        float		 clumpStray;	// clump stray hair probability
        float		 clumpStrayAmp;	// clump stray strength
        int		 clumpIntr;	// clump interpolation
        float		 curlRad;	// curl radius multiplier
        float		 curlSelf;	// curl-on-itself parameter
        int		 curlMode;	// curl mode
        float		 taper;		// taper
        float		 yOffset;	// vertical offset (m)
        float		 stripRot;	// strip random rotation (%)
        float		 rootBend;	// root bending (%)
        int		 bendDir;	// bend direction
        float		 rate;		// fur rate for adaptive sampling
        float		 blendAngle;	// the limit angle for guide blending
        float		 blendAmount;	// the amount of guide blending
        float		 posJitter, sclJitter, nrmJitter, grwJitter; // jittering for position scale and orientation and growth
        float		 kinkAmp, kinkAmpTip, kinkScl, kinkYScl, kinkOff; // kink aplitude at the root, amplitude at the tip, scale, y scale, offset
        float		 frizAmp, frizAmpTip, frizScl, frizOff; // frizz amplitude at the root, amplitude at the tip, scale and offset
        int		 maxSegment;	// maximum number of segments long one hair
        int		 type;		// geometry type
        int		 furOnly;	// remove base surface polygons when true
        int		 randomSeed;	// seed for fur random sequence
        int		 adaptive;	// adaptive fur flag
        int		 autoFade;	// automatic fading (for adaptive fur) flag
        int		 culling;	// view frustrum culling flag
        int		 billboard;	// true for billboard type geometry, can be either tree or leaf. The difference is the direction: trees grow up and facing the camera and leaves grow horizontal, not facing the camera.
        int		 glColorOverride;// true if GL should use color below
        int		 useIC;	   // true if IC should be enabled on fur (OFF by default)
        LXtFVector	 glColor;	// GL color for hair strands
        LXtFVector	 glRootColor;	// GL color for hair at the root
        int		 widthMode;	// width mode (relative, aboslute)
        float		 widthAbs;	// absolute width value
        // guide settings
        int		 guides;	// how to use guides for fur geometry
        int		 guideSurf;	// true if the guides are located in the same surface (as the fur)
        int		 guideBound;	// true if surface guides need to be included in surface bounding box
        float		 guideSize;	// guide range (m)
        float		 guideLen;	// guide parametric length (%)
        char		*guideTag;	// guide polygon tag
        LXtID4		 guideType;	// guide polygon tag type
        void		*guideItem;	// guide mesh item
        // gradients
        void		*taprGrad;
        void		*flexGrad;
        void		*jitrGrad;
        void		*clmpGrad;
        void		*curlGrad;
        void		*frizGrad;
        void		*kinkGrad;
        // VMaps
        const char	*densityMap;
        const char	*lengthMap;
        const char	*vectorMap;
        const char	*clumpMap;
        const char	*curlMap;
        const char	*blendMap;
        const char	*rangeMap;
        const char	*bendMap;
        const char	*widthMap;
        int              vectorBound;
        // eval data
        LXtFVector	 bump;		// fur bump vector
        LXtFVector	 vec;		// fur vector (from vector map)
        float		 bumpHeight;	// evaluated bump height
        float		 max;		// max fur size
        float		 dist;		// fur height (set by textures)
        int		 enable;	// enable flag set to true by fur materials (so 0 means no fur material).
        int		 cylinders;	// true if hairs are made of cylinders
        int		 tgtShade;	// true if fur uses tangent shading
        int		 maxPass;	// true during the 'max' evaluation pass
        int		 bumpPass;	// true during the 'fur bump' evaluation pass
} LXpFurParms;

/*
 * This packet is used for the particles base parameters.
 * 'ID' is  a float that is unique to each particle and can be used
 * 'lenParm' is a parameter that indicates the position along the curve in the particle for hair/curve particles.
 * 'useLen' is set to true by textures which change the particle/hair attributes along its length.
 */
typedef struct st_LXpParticleSample {
        LXtFVector	 vel;		// instant velocity
        LXtFVector	 normal;	// normal map
        LXtFVector	 bump;		// bump map
        LXtFVector	 vector;	// vector map
        float		 idParm;
        float		 lenParm;
        float		 minDist;
        float		 density;
        float		 size;
        float		 dissolve;
        float		 age;
        int		 useLen;
        // Particle implicit UVs
        float		 uv[2];
        float		 duv[2];
        float		 dpdu[3];
        float		 dpdv[3];
        float		 lum;
        float		 rgb[3];
} LXpParticleSample;

/*
 * The opacity packet is used in special cases such as shadow evaluation.
 */
typedef struct st_LXpShadeOpacity {
        LXtFVector	 opa;
} LXpShadeOpacity;

/*
 * The standard shading output is divided into six components (diffuse, specular,
 * mirror reflection, transparency, subsurface scattering and luminosity) stored
 * in the LXpShadeComponents packet, and a combined final color stored in the
 * LXpShadeOutput packet.  Both packets also contains fields related to various
 * optional render outputs.
 */
typedef struct st_LXpShadeComponents {
        LXtFVector	 diff;		// diffuse reflection
        LXtFVector	 diffDir;	// diffuse (direct illumination only)
        LXtFVector	 diffInd;	// diffuse (indirect illumination only)
        LXtFVector	 diffUns;	// diffuse (unshadowed direct illumination)
        LXtFVector	 spec;		// specular reflection
        LXtFVector	 refl;		// mirror reflection
        LXtFVector	 tran;		// transparency
        LXtFVector	 subs;		// subsurface scattering
        LXtFVector	 lumi;		// luminosity
        LXtFVector	 illum;		// total illumination
        LXtFVector	 illumDir;	// direct illumination only
        LXtFVector	 illumInd;	// indirect illumination only
        LXtFVector	 illumUns;	// unshadowed direct illumination
        LXtFVector	 volLum;	// volumetic scattering
        LXtFVector	 volOpa;	// volumetric absorption
} LXpShadeComponents;

typedef struct st_LXpShadeOutput {
        LXtFVector	 color;		// final color
        LXtFVector	 mVec;		// motion vector
        LXtFVector	 sNorm;		// shading normal
        LXtFVector	 gNorm;		// geometric normal
        LXtFVector	 uv;		// UV coordinates
        LXtFVector	 dpdu;		// dPdu vector
        LXtFVector	 dpdv;		// dPdv vector
        LXtFVector	 icVal;		// nearest IC value
        float		 alpha;		// alpha channel
        float		 depth;		// depth from camera
        float		 volDepth;	// depth from camera for volume samples
        float		 shadow;	// shadow density
        float		 occlAmb;	// ambient occlusion
        float		 occlRef;	// reflection occlusion
        float		 sInc;		// incidence based on shading normal
} LXpShadeOutput;

typedef struct st_LXpShadeDiffuse {
        LXtFVector	 val;
} LXpShadeDiffuse;

typedef struct st_LXpShadeSpecular {
        LXtFVector	 val;
} LXpShadeSpecular;

typedef struct st_LXpShadeMirror {
        LXtFVector	 val;
} LXpShadeMirror;

typedef struct st_LXpShadeTransparency {
        LXtFVector	 val;
} LXpShadeTransparency;

typedef struct st_LXpShadeSubsurface {
        LXtFVector	 val;
} LXpShadeSubsurface;

typedef struct st_LXpShadeLuminosity {
        LXtFVector	 val;
} LXpShadeLuminosity;

/*
 * This packet is used to create a surface shader slice that returns flags
 * specifying whether the surface is double sided, whether it can possibly be
 * transparent, whether it casts or receives shadows, its visibility to the camera
 * and to rays, and whether to use physically-based shading.
 */
typedef struct st_LXpShadeFlags {
        void		*lightGroup;
        float		 shadeRate, dirMult, indMult, indSat, indSatOut, alphaVal, eta;
        unsigned int	 indType, alphaType, lightLink;
        unsigned int	 flags;
        char		 shadeEffect[32];
        float		 rndAngle;
} LXpShadeFlags;

/*
 * This packet is used to communicate the light path expression label of a
 * shader to a renderer.
 */
typedef struct st_LXpShadeLPE {
        char		*lpeLabel;
} LXpShadeLPE;

typedef struct st_LXpShadeFog {
        LXtFVector	 fogCol;
        float		 fogStart;
        float		 fogEnd;
        float		 fogDensity;
        float		 fogHeight;
        float		 fogFalloff;
        unsigned int	 fogType;
        unsigned int	 fogEnv;
} LXpShadeFog;


/*
 * They are defined using the ILxVectorPacket interface.  The first six methods
 * control the lifecycle of packets.
 * - Size
 * the size of the packet in bytes for data packets.  Must be a constant.
 * The size can be 0 for object packets.
 * - Interface
 * the packet COM interface for object packets.  Should be NULL if the packet is
 * data only.
 * - Initialize
 * set the initial state of the packet when first allocated.  Packets are
 * initialized to all zero bytes by default, but any additional state such as
 * object allocation should be done here.
 * - Reset
 * reset the state of the packet to what it would have been right after
 * initialization.  This is called when an existing packet is going to be reused
 * without having to free it and re-initialze.
 * 
 * - Copy
 * copy the contents of one packet to another.  Both packets will have been
 * initialized.
 * 
 * - Cleanup
 * free anything allocated in the packet.  This is called just before the packet
 * itself is freed.
 * 
 * There are also some additional methods needed, particularly for blending packets during
 * shader evaluation.
 * 
 * - Blend
 * This is like interpolate, but it also uses a blending mode to decide how to blend values.
 * 
 * - Invert
 * This inverts a packet, which is mostly used by the texture engine and doesn't always make
 * sense for all packets.
 * 
 * Finally we have some methods to expose vector packets as inputs for nodal shaders.
 * There is very little reason to use these for custom shading packets. They are mostly
 * useful for fundamental packets that present sample information that can't be read
 * any other way.
 * 
 * - NodeCount
 * This returns the number of nodal connections on the packet.
 * 
 * - NodeName
 * This returns the internal name of the output by index.
 * 
 * - NodeType
 * This returns type information by index. VPacketPubType is one of float, double,
 * or int, and 'count' is the number of components. We also return the actual data
 * type name (DISTANCE, PERCENT, etc.) and the vector type.
 * 
 * - NodeGet
 * This returns the value for a node connection given by index. The packet is passed
 * in as input. The data pointer returned points at the value as a location inside 
 * the packet, or the first element of an array of values for vector values.
 * 
 * 
 */
typedef struct vt_ILxVectorPacket {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned int,
Size) (
        LXtObjectID		 self);

        LXxMETHOD(  const LXtGUID *,
Interface) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
Initialize) (
        LXtObjectID		 self,
        void			*packet);

        LXxMETHOD(  void,
Reset) (
        LXtObjectID		 self,
        void			*packet);

        LXxMETHOD(  LxResult,
Copy) (
        LXtObjectID		 self,
        void			*packet,
        void			*from);

        LXxMETHOD(  void,
Cleanup) (
        LXtObjectID		 self,
        void			*packet);

        LXxMETHOD(  LxResult,
Blend) (
        LXtObjectID		 self,
        void			*packet,
        void			*p0,
        void			*p1,
        float			 t,
        int			 mode);

        LXxMETHOD(  LxResult,
Invert) (
        LXtObjectID		 self,
        void			*packet);

        LXxMETHOD(  unsigned int,
NodeCount) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
NodeName) (
        LXtObjectID		 self,
        unsigned int		 index,
        const char		**name);

        LXxMETHOD(  LxResult,
NodeType) (
        LXtObjectID		 self,
        unsigned int		 index,
        VPacketPubType		*dataType,
        unsigned int		*count,
        const char		**exoType,
        const char		**vecType);

        LXxMETHOD(  LxResult,
NodeGet) (
        LXtObjectID		 self,
        unsigned int		 index,
        void			*packet,
        void			**data);
} ILxVectorPacket;

/*
 * This is the old interface we keep for translation
 */
typedef struct vt_ILxVectorPacket1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned int,
Size) (
        LXtObjectID		 self);

        LXxMETHOD(  const LXtGUID *,
Interface) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
Initialize) (
        LXtObjectID		 self,
        void			*packet);

        LXxMETHOD(  void,
Reset) (
        LXtObjectID		 self,
        void			*packet);

        LXxMETHOD(  LxResult,
Copy) (
        LXtObjectID		 self,
        void			*packet,
        void			*from);

        LXxMETHOD(  void,
Cleanup) (
        LXtObjectID		 self,
        void			*packet);

        LXxMETHOD(  LxResult,
Save) (
        LXtObjectID		 self,
        void			*packet,
        unsigned int		 n,
        LXtObjectID		 writestream);

        LXxMETHOD(  LxResult,
Load) (
        LXtObjectID		 self,
        void			*packet,
        unsigned int		 n,
        LXtObjectID		 readstream);

        LXxMETHOD(  LxResult,
Interpolate) (
        LXtObjectID		 self,
        void			*packet,
        void			*p0,
        void			*p1,
        float			 t);

        LXxMETHOD(  LxResult,
Blend) (
        LXtObjectID		 self,
        void			*packet,
        void			*p0,
        void			*p1,
        float			 t,
        int			 mode);

        LXxMETHOD(  LxResult,
Invert) (
        LXtObjectID		 self,
        void			*packet);
} ILxVectorPacket1;

/*
 * The lookup is available to plug-in clients as a global service with a Lookup()
 * method to get offset from name, and a Name() method to get the name from the
 * offset. The FastPacket() interface is provided to get the packet from a raw
 * sample vector object without having to query for the interface. This speeds
 * up texture evaluations.
 * 
 * These two methods allow clients to create simple vector types. The first method
 * allocates an empty vector type, and the second method allows packets to be added
 * to the definition.
 */
typedef struct vt_ILxPacketService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		 self,
        const char		*category,
        const char		*name,
        unsigned int		*offset);

        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        const char		*category,
        unsigned int		 offset,
        const char	       **name);

        LXxMETHOD(  void *,
FastPacket) (
        LXtObjectID		 self,
        LXtObjectID		 vector,
        unsigned int		 offset);
        LXxMETHOD( LxResult,
CreateVectorType) (
        LXtObjectID		 self,
        const char		*category,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
AddPacket) (
        LXtObjectID		 self,
        LXtObjectID		 vtype,
        const char		*name,
        unsigned int		 flags);
} ILxPacketService;

/*
 * - Count
 * Given a packet flag, returns the number of packets that match one of the
 * basic flags settings above.
 * - ByIndex
 * Returns the offset for the packet of the given type at the given index.
 * As a convenience it also set the packet flags if 'flags' is set, this
 * is actually an important optimization for faster vtype processing.
 */
typedef struct vt_ILxVectorType {
        ILxUnknown	 iunk;
        LXxMETHOD(  const char *,
Category) (
        LXtObjectID		 self);

        LXxMETHOD(  unsigned int,
Test) (
        LXtObjectID		 self,
        unsigned int		 offset);

        LXxMETHOD(  unsigned int,
Count) (
        LXtObjectID		 self,
        unsigned int		 type);

        LXxMETHOD(  unsigned int,
ByIndex) (
        LXtObjectID		 self,
        unsigned int		 type,
        unsigned int		 index,
        unsigned int		*flags);
} ILxVectorType;

/*
 * The two variants are stacks and lists.  The stack interface adds methods for
 * pushing and popping, and the list interface allows access to the current value
 * index.
 */
typedef struct vt_ILxVectorStack {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Vector methods
        LXxMETHOD(  void *,
Optional) (
        LXtObjectID		 self,
        unsigned int		 offset);
        LXxMETHOD(  LxResult,
Readable) (
        LXtObjectID		 self,
        unsigned int		 offset,
        void		       **packet);
        LXxMETHOD(  LxResult,
Writable) (
        LXtObjectID		 self,
        unsigned int		 offset,
        void		       **packet);
        LXxMETHOD(  LxResult,
SetPacket) (
        LXtObjectID		 self,
        unsigned int		 offset,
        void			*pdat);
// QWEB_MACRO_END - SDK Common: Vector methods

        LXxMETHOD(  LxResult,
Push) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
Pop) (
        LXtObjectID		 self);
} ILxVectorStack;

typedef struct vt_ILxVectorList {
        ILxUnknown	 iunk;
// QWEB_MACRO_BEGIN - SDK Common: Vector methods
        LXxMETHOD(  void *,
Optional) (
        LXtObjectID		 self,
        unsigned int		 offset);
        LXxMETHOD(  LxResult,
Readable) (
        LXtObjectID		 self,
        unsigned int		 offset,
        void		       **packet);
        LXxMETHOD(  LxResult,
Writable) (
        LXtObjectID		 self,
        unsigned int		 offset,
        void		       **packet);
        LXxMETHOD(  LxResult,
SetPacket) (
        LXtObjectID		 self,
        unsigned int		 offset,
        void			*pdat);
// QWEB_MACRO_END - SDK Common: Vector methods

        LXxMETHOD(  LxResult,
Append) (
        LXtObjectID		 self,
        unsigned int		*index);

        LXxMETHOD(  unsigned int,
Current) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetCurrent) (
        LXtObjectID		 self,
        unsigned int		 index);

        LXxMETHOD(  unsigned int,
Count) (
        LXtObjectID		 self);

        LXxMETHOD(  void,
Clear) (
        LXtObjectID		 self);
} ILxVectorList;

/*
 * - Get
 * This sets the float value from the 'get' vector packets
 * - Set
 * This sets the texture output value in the 'set' sample vector packets.
 */
typedef struct vt_ILxTextureEffect {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned int,
Type) (
        LXtObjectID		 self);

        LXxMETHOD(  const char *,
TypeName) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
Get) (
        LXtObjectID		 self,
        LXtObjectID		 sv,
        float			*val,
        void			*item);

        LXxMETHOD(  LxResult,
Set) (
        LXtObjectID		 self,
        LXtObjectID		 sv,
        const float		*val,
        void			*item);
} ILxTextureEffect;

/*
 * Alternatively, this interface let's you define all the effects for a packet, this is a faster way to define texture effects for custom materials and shaders
 */
typedef struct vt_ILxPacketEffect {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Packet) (
        LXtObjectID		 self,
        const char		**packet);

        LXxMETHOD(  unsigned int,
Count) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        int			 index,
        const char		**name,
        const char		**typeName,
        int			 *type);

        LXxMETHOD(  LxResult,
Get) (
        LXtObjectID		 self,
        int			 index,
        void			*packet,
        float			*val,
        void			*item);

        LXxMETHOD(  LxResult,
Set) (
        LXtObjectID		 self,
        int			 index,
        void			*packet,
        const float		*val,
        void			*item);
} ILxPacketEffect;

/*
 * Packet types are defined as servers and so may be expanded by plug-ins.
 * Packets define their categories as a server tag.
 */

        #define LXu_VECTORPACKET1	"F74C2B0E-4BC5-4E76-8F7D-1D64DA86FD28"
        #define LXa_VECTORPACKET1	"vectorPacket1"
        // [export]  ILxVectorPacket1 vpkt

        #define LXu_VECTORPACKET	"DDD79825-3E2F-4A6B-A27A-B0B2C6FB811C"
        #define LXa_VECTORPACKET	"vectorPacket"
        #define LXsVPK_CATEGORY		"vpacket.category"
        // [export]  ILxVectorPacket vpkt
        // [default] ILxVectorPacket:NodeCount = 0


        #define LXu_PACKETSERVICE	"2B8D8867-4EFC-4A1D-8F6A-B5F103A90A9B"
        // [python] ILxPacketService:CreateVectorType	obj VectorType

/*
 * The VectorType is defined by an interface, which can be implemented by each
 * client in its own way.
 * - Category
 * This method returns the Category of this vector type
 * - Test
 * Returns the packet flags for the VectorType, which indicate how the type
 * object intends to use the packet.  GET means read-only, SET means write-only,
 * and GET+SET means read+write.  GET packets may also be optional, in which
 * case the packet will only be used if present.
 * 
 */

        #define	LXfVT_SET	 (1<<0)
        #define	LXfVT_GET	 (1<<1)
        #define	LXfVT_OPTIONAL	 (1<<2)


        #define LXu_VECTORTYPE	"791B288F-DD69-11D7-857A-000A9593D716"
        // [local]  ILxVectorType


        #define LXu_VECTORSTACK	"7915D133-4272-498B-A691-C98118F40FD5"
        #define LXu_VECTORLIST	"F091C272-C770-42C3-B314-62EE90D34C57"
        // [local]  ILxVectorList
        // [local]  ILxVectorStack

/*
 * A Sample is an arbitrary position in 3D space with a set of properties like a
 * size, a set of values measured in different references, etc. The packets that
 * make up the sample vector are in the "sample" cateogry.
 */

        #define LXsCATEGORY_SAMPLE	 "sample"

/*
 * Flags are used to specify which elements should be tested against a ray, what
 * information to compute at the hit point, and the reason for firing the ray.
 */

        #define LXfRAY_SCOPE_POLYGONS		0x00000001
        #define LXfRAY_SCOPE_VOLUMETRICS	0x00000002
        #define LXfRAY_SCOPE_ENVIRONMENT	0x00000004
        #define LXfRAY_SCOPE_BACKFACE		0x00000008
        #define LXfRAY_SCOPE_BACKONLY		0x00000010
        #define LXfRAY_SCOPE_SAMESURF		0x00000020
        #define LXfRAY_SCOPE_OTHERSURF		0x00000040
        #define LXfRAY_SCOPE_IMPLICITSURF	0x00000080

        #define LXfRAY_EVAL_NORMAL		0x00000100
        #define LXfRAY_EVAL_MATERIAL		0x00000200
        #define LXfRAY_EVAL_OPACITY		0x00000400
        #define LXfRAY_EVAL_SHADING		0x00000800
        #define LXfRAY_EVAL_IRRADIANCE		0x00001000
        #define LXfRAY_EVAL_PERSPENV		0x00002000
        #define LXfRAY_EVAL_NOFOG		0x00004000

        #define LXfRAY_TYPE_CAMERA		0x00010000
        #define LXfRAY_TYPE_SHADOW		0x00020000
        #define LXfRAY_TYPE_REFLECT		0x00040000
        #define LXfRAY_TYPE_REFRACT		0x00080000
        #define LXfRAY_TYPE_INDIRECT		0x00100000
        #define LXfRAY_TYPE_CAUSTIC		0x00200000
        #define LXfRAY_TYPE_SUBSURFACE		0x00400000
        #define LXfRAY_TYPE_SHADOWMAP		0x00800000
        #define LXfRAY_TYPE_TEXTURE		0x01000000
        #define LXfRAY_TYPE_OCCLUSION		0x02000000
        #define LXfRAY_TYPE_SHADOWVOL		0x04000000
        #define LXfRAY_TYPE_CLIPPING		0x08000000
        #define LXfRAY_TYPE_SHADOW_INFO		0x10000000
        #define LXfRAY_TYPE_PREPASS		0x20000000


        #define LXfFACET_OBJECT_POSITION	0x00000001
        #define LXfFACET_DISPLACED		0x00000002
        #define LXfFACET_NORMALIZED		0x00000004

/*
 * These sample vector packets can be accessed with the following names.
 */

        #define LXsP_SAMPLE_POSITION	"sample.position"
        #define LXsP_SAMPLE_XFRM	"sample.xfrm"
        #define LXsP_SAMPLE_RAY		"sample.ray"
        #define LXsP_SAMPLE_CLIP	"sample.clip"
        #define LXsP_SAMPLE_PARMS	"sample.parms"
        #define LXsP_SAMPLE_RECOL_PARMS	"sample.parmsRecolor"
        #define LXsP_SAMPLE_UE_PARMS	"sample.parmsUE"
        #define LXsP_SAMPLE_UT_PARMS	"sample.parmsUT"
        #define LXsP_SAMPLE_GLTF_PARMS	"sample.parmsGLTF"
        #define LXsP_SAMPLE_AXF_PARMS	"sample.parmsAXF"
        #define LXsP_SAMPLE_MASK	"sample.mask"
        #define LXsP_SAMPLE_DRIVER	"sample.driver"
        #define LXsP_SAMPLE_STENCIL	"sample.stencil"
        #define LXsP_SAMPLE_VOLUME	"sample.volume"
        #define LXsP_SAMPLE_DENSITY	"sample.density"
        #define LXsP_SAMPLE_DISSOLVE	"sample.dissolve"
        #define LXsP_SAMPLE_FACET	"sample.facet"
        #define LXsP_SAMPLE_BUMP	"sample.bump"
        #define LXsP_SAMPLE_FLUID	"sample.fluid"

/*
 * These are the UV tiling options:
 */

        #define	LXiTILE_RESET		0
        #define	LXiTILE_REPEAT		1
        #define	LXiTILE_MIRROR		2
        #define	LXiTILE_EDGE		3


        #define	LXiCULLING_ENABLED		0
        #define	LXiCULLING_DISABLED		1

/*
 * These are the normal map tangent vector options:
 */

        #define	LXiTANGENT_DPDU_DPDV	0 // use dPdu for tangent, dPdv for bitangent
        #define	LXiTANGENT_DPDU_CROSS	1 // use dPdu for tangent, cross product of normal and dPdu for bitangent


        #define LXsP_TEXTURE_INPUT	"texture.input"
        #define LXsP_TEXTURE_OUTPUT	"texture.output"
        #define LXsP_TEXTURE_VALUE	"texture.value"
        #define LXsP_TEXTURE_LOCATOR	"texture.locator"


        #define LXsP_SURF_NORMAL	"surface.normal"
        #define LXsP_SURF_SMOOTH	"surface.smoothing"


        #define LXsP_DISPLACE	 "displace"


        #define LXsP_SHADER_TYPE	 "shaderType"


        #define LXsP_GROUP_LAYER	 "groupLayer"

/*
 * The guides are either ignored, or used for clumping or used for hair interpolation.
 */

        #define	LXi_FUR_GUIDE_NONE		 0
        #define	LXi_FUR_GUIDE_CLUMP		 1
        #define	LXi_FUR_GUIDE_NORMAL		 2
        #define	LXi_FUR_GUIDE_DIRLEN		 3
        #define	LXi_FUR_GUIDE_SHAPE		 4
        #define	LXi_FUR_GUIDE_INTERPOLATE	 5


        #define	LXi_FUR_BILLBOARD_OFF		 0
        #define	LXi_FUR_BILLBOARD_TREE		 1
        #define	LXi_FUR_BILLBOARD_LEAF		 2
        #define	LXi_FUR_BILLBOARD_FEATHER	 3


        #define	LXi_FUR_BEND_DOWN		 0
        #define	LXi_FUR_BEND_NORMAL		 1


        #define	LXi_FUR_WIDTH_RELATIVE		 0
        #define	LXi_FUR_WIDTH_ABSOLUTE		 1


        #define LXsP_FUR_PARMS	 "fur"


        #define LXsP_PARTICLE_SAMPLE	 "particleSample"


        #define LXsP_SHADE_CLOSURE	"shade.closure"
        #define LXsP_SHADE_OPACITY	"shade.opacity"
        #define LXsP_SHADE_COMPONENTS	"shade.components"
        #define LXsP_SHADE_OUTPUT	"shade.output"
        #define LXsP_SHADE_DIFFUSE	"shade.diffuse"
        #define LXsP_SHADE_SPECULAR	"shade.specular"
        #define LXsP_SHADE_MIRROR	"shade.mirror"
        #define LXsP_SHADE_TRANSPARENCY	"shade.transparency"
        #define LXsP_SHADE_SUBSURFACE	"shade.subsurface"
        #define LXsP_SHADE_LUMINOSITY	"shade.luminosity"


        #define LXfSURF_DOUBLE		 0x00000001
        #define LXfSURF_TRANSP		 0x00000002
        #define LXfSURF_SUBTRACT	 0x00000004
        #define LXfSURF_BOOLMTL		 0x00000008

        #define LXfSURF_SHADCAST	 0x00000010
        #define LXfSURF_SHADRECV	 0x00000020

        #define LXfSURF_VISCAM		 0x00000100
        #define LXfSURF_VISIND		 0x00000200
        #define LXfSURF_VISREFL		 0x00000400
        #define LXfSURF_VISREFR		 0x00000800
        #define LXfSURF_VISSUBS		 0x00001000
        #define LXfSURF_VISOCCL		 0x00002000

        #define LXfSURF_PHYSICAL	 0x00010000
        #define LXfSURF_REFLSPEC	 0x00020000
        #define LXfSURF_REFLBLUR	 0x00040000
        #define LXfSURF_SAMESURF	 0x00080000

        #define LXfSURF_TANSHADE	 0x00100000
        #define LXfSURF_CLIPPING	 0x00200000
        #define LXfSURF_CMPSHADE	 0x00400000
        #define LXfSURF_IMPSHADE	 0x00800000
        #define LXfSURF_CLPMATTE	 0x01000000
        #define LXfSURF_RNDSAME		 0x02000000
        #define LXfSURF_RNDWIDTH	 0x04000000
        #define LXfSURF_RADINTER	 0x08000000
        #define LXfSURF_USEREFIDX	 0x10000000

        #define LXfSURF_HIDDEN		 0x20000000 // used to tag hidden surfaces (they exist in the geoCache but are not rendered)

        #define LXfSURF_SPECREFIDX	 0x40000000
        #define LXfSURF_PERRAYFRES	 0x80000000

        #define LXsP_SHADE_FLAGS	 "surfFlags"


        #define LXsP_SHADE_LPE	 "shadeLPE"


        #define SVPs_SHADE_LPE	 LXsP_SHADE_LPE


        #define LXsP_SHADE_FOG	 "shadeFog"


        #define SVPs_SHADE_FOG	 LXsP_SHADE_FOG

/*
 * Texture effects are like vector packet definitions.  They specify the way
 * textures operate on the sample vector.
 * The LXs_FX_ENVCOLOR and LXs_FX_ENVALTITUDE apply to environments.
 */

        #define LXs_FX_ANISODIR	       	"anisoDir"
        #define LXs_FX_BUMP	 	"bump"
        #define LXs_FX_COATAMOUNT	"coatAmount"
        #define LXs_FX_COATROUGH	"coatRough"
        #define LXs_FX_COATBUMP		"coatBump"
        #define LXs_FX_DIFFAMOUNT	"diffAmount"
        #define LXs_FX_DIFFCOLOR	"diffColor"
        #define LXs_FX_DIFFROUGH	"diffRough"
        #define LXs_FX_DISPLACE        	"displace"
        #define LXs_FX_DRIVERA          "driverA"
        #define LXs_FX_DRIVERB          "driverB"
        #define LXs_FX_DRIVERC          "driverC"
        #define LXs_FX_DRIVERD          "driverD"
        #define LXs_FX_ENVALTITUDE	"envAltitude"
        #define LXs_FX_ENVCOLOR		"envColor"
        #define LXs_FX_GROUPMASK       	"groupMask"
        #define LXs_FX_LAYERMASK       	"layerMask"
        #define LXs_FX_LUMIAMOUNT	"lumiAmount"
        #define LXs_FX_LUMICOLOR	"lumiColor"
        #define LXs_FX_NORMAL          	"normal"
        #define LXs_FX_NORMAL_COAT	"normalCoat"
        #define LXs_FX_OBJNORMAL        "objectNormal"
        #define LXs_FX_SPECAMOUNT	"specAmount"
        #define LXs_FX_SPECCOLOR	"specColor"
        #define LXs_FX_SPECFRESNEL	"specFresnel"
        #define LXs_FX_STENCIL	        "stencil"
        #define LXs_FX_REFLAMOUNT	"reflAmount"
        #define LXs_FX_REFLCOLOR	"reflColor"
        #define LXs_FX_REFLFRESNEL	"reflFresnel"
        #define LXs_FX_RNDWIDTH		"rndWidth"
        #define LXs_FX_ROUGH	       	"rough"
        #define LXs_FX_SUBSAMOUNT	"subsAmount"
        #define LXs_FX_SUBSCOLOR	"subsColor"
        #define LXs_FX_SP_DENSITY       "surfParticleDensity"
        #define LXs_FX_SP_NORMAL	"surfParticleNormal"
        #define LXs_FX_SP_HEADING	"surfParticleHeading"
        #define LXs_FX_SP_SIZE	        "surfParticleSize"
        #define LXs_FX_PART_DENS	"particleDensity"
        #define LXs_FX_PART_DISS	"particleDissolve"
        #define LXs_FX_PART_SIZE	"particleSize"
        #define LXs_FX_TRANAMOUNT	"tranAmount"
        #define LXs_FX_TRANCOLOR	"tranColor"
        #define LXs_FX_TRANROUGH       	"tranRough"
        #define LXs_FX_VECDISP        	"vectorDisplace"
        #define LXs_FX_RGBA        	"RGBA"
        #define LXs_FX_DISSOLVE        	"dissolve"
        #define LXs_FX_TXTROFFSET       "textureOffset"
        #define LXs_FX_CULLING		"projectionCulling"

        #define LXs_FX_UE_METALLIC		"metallicUE"
        #define LXs_FX_UE_BASE			"baseUE"
        #define LXs_FX_UE_ROUGH			"roughUE"
        #define LXs_FX_UE_SPEC			"specUE"
        #define LXs_FX_UE_EMIS			"emisUE"
        #define LXs_FX_UE_NORMAL		"normalUE"
        #define LXs_FX_UE_BUMP			"bumpUE"
        #define LXs_FX_UE_AO			"aoUE"
        #define LXs_FX_UE_SSS			"sssUE"
        #define LXs_FX_UE_COATAMOUNT		"ccUE"
        #define LXs_FX_UE_COATROUGH		"ccrUE"
        #define LXs_FX_UE_OPACITY		"opacUE"

        #define LXs_FX_UT_METALLIC		"metallicUT"
        #define LXs_FX_UT_ALBEDO		"albedoUT"
        #define LXs_FX_UT_SMOOTH		"smoothUT"
        #define LXs_FX_UT_EMIS			"emisUT"
        #define LXs_FX_UT_NORMAL		"normalUT"
        #define LXs_FX_UT_BUMP			"bumpUT"
        #define LXs_FX_UT_AO			"aoUT"
        #define LXs_FX_UT_DetailMask		"detailMaskUT"
        #define LXs_FX_UT_ALBEDO2		"albedo2UT"
        #define LXs_FX_UT_NORMAL2		"normal2UT"

        #define LXs_FX_GLTF_METALLIC		"metallicGLTF"
        #define LXs_FX_GLTF_BASE_COLOR		"baseColorGLTF"
        #define LXs_FX_GLTF_ROUGHNESS		"roughnessGLTF"
        #define LXs_FX_GLTF_EMIS		"emisGLTF"
        #define LXs_FX_GLTF_NORMAL		"normalGLTF"
        #define LXs_FX_GLTF_AO			"aoGLTF"

        #define LXs_FX_AXF_SPECULAR_COLOR			"specularColorAXF"
        #define LXs_FX_AXF_BASE_COLOR				"baseColorAXF"
        #define LXs_FX_AXF_SPECULAR_LOBE			"roughnessAXF"
        #define LXs_FX_AXF_NORMAL					"normalAXF"
        #define LXs_FX_AXF_ANISOTROPIC_ROTATION		"anisoDirAXF"
        #define LXs_FX_AXF_ALPHA					"alphaAXF"
        #define LXs_FX_AXF_HEIGHT					"heightAXF"
        #define LXs_FX_AXF_FRESNEL					"fresnelAXF"
        #define LXs_FX_AXF_CLEARCOAT_NORMAL			"clearcoatNormalAXF"
        #define LXs_FX_AXF_CLEARCOAT_IOR			"clearcoatIORAXF"

        #define LXs_FX_METALLIC			"metallic"
        #define LXs_FX_SPECTINT			"specularTint"
        #define LXs_FX_SHEEN			"sheen"
        #define LXs_FX_SHEENTINT		"sheenTint"
        #define LXs_FX_FLATNESS			"flatness"
        #define LXs_FX_ANISOTROPIC		"anisotropic"

        #define LXs_FX_RECOLOR_ORIGINAL		"recolorOriginal"
        #define LXs_FX_RECOLOR_FROM		"recolorFrom"
        #define LXs_FX_RECOLOR_TO		"recolorTo"
        #define LXs_FX_MATERIAL_MAP		"materialMap"

        #define LXs_FX_FUR_BEND	        "furBend"
        #define LXs_FX_FUR_BUMP	        "furBump"
        #define LXs_FX_FUR_CLDENS       "furClumpDensity"
        #define LXs_FX_FUR_CLUMPS	"furClumps"
        #define LXs_FX_FUR_CURLS	"furCurls"
        #define LXs_FX_FUR_CYLINDERS    "cylinders"
        #define LXs_FX_FUR_DENSITY	"furDensity"
        #define LXs_FX_FUR_DIRECTION	"furDirection"
        #define LXs_FX_FUR_FLEX	        "furFlex"
        #define LXs_FX_FUR_GROWJIT	"furGrowthJitter"
        #define LXs_FX_FUR_KINK		"furKink"
        #define LXs_FX_FUR_FRIZZ	"furFrizz"
        #define LXs_FX_FUR_KINK_TIP	"furKinkTip"
        #define LXs_FX_FUR_FRIZZ_TIP	"furFrizzTip"
        #define LXs_FX_FUR_STRAYS	"furStrays"

        #define LXs_FX_FUR_GUIDE_NONE       "none"
        #define LXs_FX_FUR_GUIDE_DIRLENGTH  "dirlen"
        #define LXs_FX_FUR_GUIDE_SHAPE      "shape"
        #define LXs_FX_FUR_GUIDE_RANGE      "range"
        #define LXs_FX_FUR_GUIDE_DIRECTION  "normal"
        #define LXs_FX_FUR_GUIDE_CLUMP      "clump"

        #define LXs_FX_FUR_LENGTH	"furLength"
        #define LXs_FX_FUR_STRIPS       "strips"
        #define LXs_FX_FUR_VECTOR	"furVector"

/*
 * Render output effects are reserved for use with render outputs.
 */

        #define LXs_FX_OUTPUT_FINAL_COLOR	       	       "shade.color"
        #define LXs_FX_OUTPUT_ALPHA		       	       "shade.alpha"
        #define LXs_FX_OUTPUT_LIGHT_PATH_EXPRESSION	       "shade.lpe"
        #define LXs_FX_OUTPUT_DIFFUSE_SHADING_TOTAL            "shade.diffuse"
        #define LXs_FX_OUTPUT_DIFFUSE_SHADING_DIRECT	       "shade.diffDir"
        #define LXs_FX_OUTPUT_DIFFUSE_SHADING_INDIRECT         "shade.diffInd"
        #define LXs_FX_OUTPUT_DIFFUSE_SHADING_UNSHADOWED       "shade.diffUns"
        #define LXs_FX_OUTPUT_SPECULAR_SHADING	       	       "shade.specular"
        #define LXs_FX_OUTPUT_REFLECTION_SHADING	       "shade.reflection"
        #define LXs_FX_OUTPUT_TRANSPARENT_SHADING	       "shade.transparency"
        #define LXs_FX_OUTPUT_SUBSURFACE_SHADING	       "shade.subsurface"
        #define LXs_FX_OUTPUT_LUMINOUS_SHADING	       	       "shade.luminosity"
        #define LXs_FX_OUTPUT_VOL_SCATTERING	       	       "volume.scattering"
        #define LXs_FX_OUTPUT_VOL_OPACITY	       	       "volume.opacity"
        #define LXs_FX_OUTPUT_VOL_DEPTH			       "volume.depth"
        #define LXs_FX_OUTPUT_DEPTH	       	               "depth"
        #define LXs_FX_OUTPUT_MOTION	       	               "motion"
        #define LXs_FX_OUTPUT_SHADOW_DENSITY	       	       "shadow"
        #define LXs_FX_OUTPUT_AMBIENT_OCCLUSION	       	       "occl.ambient"
        #define LXs_FX_OUTPUT_REFLECTION_OCCLUSION	       "occl.reflect"
        #define LXs_FX_OUTPUT_SHADING_NORMAL	               "shade.normal"
        #define LXs_FX_OUTPUT_SHADING_INCIDENCE	               "shade.incidence"
        #define LXs_FX_OUTPUT_GEOMETRIC_NORMAL	               "geo.normal"
        #define LXs_FX_OUTPUT_SURFACE_ID	               "geo.surface"
        #define LXs_FX_OUTPUT_SEGMENT_ID	               "geo.segment"
        #define LXs_FX_OUTPUT_OBJECT_COORDINATES               "geo.object"
        #define LXs_FX_OUTPUT_WORLD_COORDINATES                "geo.world"
        #define LXs_FX_OUTPUT_UV_COORDINATES	               "geo.uv"
        #define LXs_FX_OUTPUT_DPDU_VECTOR	               "geo.dpdu"
        #define LXs_FX_OUTPUT_DPDV_VECTOR	               "geo.dpdv"
        #define LXs_FX_OUTPUT_IC_POSITIONS	               "ic.position"
        #define LXs_FX_OUTPUT_IC_VALUES	                       "ic.value"
        #define LXs_FX_OUTPUT_DIFFUSE_COLOR		       "mat.diffCol"
        #define LXs_FX_OUTPUT_DIFFUSE_AMOUNT		       "mat.diffAmt"
        #define LXs_FX_OUTPUT_DIFFUSE_ROUGHNESS		       "mat.diffRough"
        #define LXs_FX_OUTPUT_DIFFUSE_ENERGY_CONSERVATION      "mat.diffEng"
        #define LXs_FX_OUTPUT_ROUGHNESS      		       "mat.rough"
        #define LXs_FX_OUTPUT_DIFFUSE_COEFFICIENT	       "mat.diffuse"
        #define LXs_FX_OUTPUT_SPECULAR_COEFFICIENT	       "mat.specular"
        #define LXs_FX_OUTPUT_REFLECTION_COEFFICIENT	       "mat.reflection"
        #define LXs_FX_OUTPUT_TRANSPARENT_AMOUNT	       "mat.tranAmt"
        #define LXs_FX_OUTPUT_TRANSPARENT_COLOR		       "mat.tranCol"
        #define LXs_FX_OUTPUT_SUBSURFACE_AMOUNT		       "mat.subsAmt"
        #define LXs_FX_OUTPUT_SUBSURFACE_COLOR		       "mat.subsCol"
        #define LXs_FX_OUTPUT_ALBEDO			       "mat.albedo"
        #define LXs_FX_OUTPUT_ILLUMINATION_SHADING_TOTAL       "shade.illum"
        #define LXs_FX_OUTPUT_ILLUMINATION_SHADING_DIRECT      "shade.illumDir"
        #define LXs_FX_OUTPUT_ILLUMINATION_SHADING_INDIRECT    "shade.illumInd"
        #define LXs_FX_OUTPUT_ILLUMINATION_SHADING_UNSHADOWED  "shade.illumUns"
        #define LXs_FX_OUTPUT_SHADING_SAMPLES	               "shade.samples"
        #define LXs_FX_OUTPUT_VARIANCE		               "shade.variance"
        #define LXs_FX_OUTPUT_PARTICLE_ID		       "particle.id"
        #define LXs_FX_OUTPUT_PARTICLE_AGE		       "particle.age"
        #define LXs_FX_OUTPUT_PARTICLE_VEL		       "particle.vel"
        #define LXs_FX_OUTPUT_RECOLOR_TO		       "recolor.to"
        #define LXs_FX_OUTPUT_RECOLOR_TO_WHITE		       "recolor.toWhite"
        #define LXs_FX_OUTPUT_MATERIAL_MAP		       "recolor.matMap"

/*
 * Shader shading effects are reserved for use with shaders.
 */

        #define LXs_FX_SHADER_FULL_SHADING          "fullShade"
        #define LXs_FX_SHADER_DIFFUSE_SHADING       "diffShade"
        #define LXs_FX_SHADER_SPECULAR_SHADING      "specShade"
        #define LXs_FX_SHADER_REFLECTION_SHADING    "reflShade"
        #define LXs_FX_SHADER_TRANSPARENT_SHADING   "tranShade"
        #define LXs_FX_SHADER_SUBSURFACE_SHADING    "subsShade"
        #define LXs_FX_SHADER_LUMINOUS_SHADING      "lumiShade"
        #define LXs_FX_SHADER_FOG_SHADING           "fogShade"

/*
 * Texture Layers exist in various shading categories: render, light, environment, camera, output, scene.
 * There is also the 'procedural' category which is used by texture layers that can be
 * found in all environments (image maps for example).
 * The 'output' category is reserved for shaders that produce an output used
 * by render buffers.
 * The 'scene' category is for animation shaders, for example a noise evaluated on a deformer or a gradient
 *  evaluated on a force item.
 * 
 */

        #define LXsSHADE_SURFACE	"surface"
        #define LXsSHADE_LIGHT		"light"
        #define LXsSHADE_ENVIRONMENT	"environment"
        #define LXsSHADE_PROCEDURAL	"procedural"
        #define LXsSHADE_OUTPUT		"output"
        #define LXsSHADE_CAMERA		"camera"
        #define LXsSHADE_SCENE		"scene"
        #define LXsSHADE_SGEN		"surfGen"

/*
 * Texture effects are listed in the UI in the shader tree in the 'Effect' column
 * they are extensible and can change any read and write to any number of packets.
 * An example of texture effect would be the 'diffuse color' effect, it reads the
 * LXpSampleParms packet, extracts the 'diffCol' color value, passes that value to
 * texture evaluation and finally replaces 'diffCol' in that same packet.
 * The texture effect interface is polymorphic with the vector type interface.
 * It has three additional methods used to describe how the effect operates on
 * the sample vector.
 * 
 * - Type
 * This returns the effect data type and read/write flags. The base type is one
 * of scalar, color. Optional flags include indicating if an effect
 * is read or write (or both), if the effect is used as a gradient input, or if it's
 * displayed as black and white (for scalar effects).
 * 
 */

        #define	LXi_TFX_SCALAR		0
        #define	LXi_TFX_COLOR		1

        #define	LXf_TFX_READ		0x10
        #define	LXf_TFX_WRITE		0x20
        #define	LXf_TFX_INPUT		0x40
        #define	LXf_TFX_BW		0x80

/*
 * Texture effects are defined as servers and so may be expanded by plug-ins.
 * They also define their category as a server tag.
 */

        #define LXu_TEXTUREEFFECT	"CA13032E-3855-4744-B77A-59530EC3E260"
        #define LXa_TEXTUREEFFECT	"textureEffect"
        #define LXsTFX_CATEGORY		"textureFX.category"
        // [export] ILxTextureEffect tfx
        // [local]  ILxTextureEffect


        #define LXu_PACKETEFFECT	"7e8a37ce-618b-4ae4-a429-01317ac40eb0"
        #define LXa_PACKETEFFECT	"packetEffect"
        // [export] ILxPacketEffect pfx
        // [local]  ILxPacketEffect

#endif
