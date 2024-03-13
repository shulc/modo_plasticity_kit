/*
 * LX particle module
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
#ifndef LX_particle_H
#define LX_particle_H

typedef struct vt_ILxParticleItem ** ILxParticleItemID;
typedef struct vt_ILxReplicatorEnumerator ** ILxReplicatorEnumeratorID;
typedef struct vt_ILxParticleEvalFrame ** ILxParticleEvalFrameID;
typedef struct vt_ILxParticleFilter ** ILxParticleFilterID;
typedef struct vt_ILxParticleCoOperator ** ILxParticleCoOperatorID;
typedef struct vt_ILxPointCacheItem ** ILxPointCacheItemID;
typedef struct vt_ILxParticleService ** ILxParticleServiceID;

/*
 * This packet is used by deformers.
 */
typedef struct st_LXpAnimDeform {
        LXtFVector	 dir;
        float		 amplitude;
} LXpAnimDeform;

/*
 * This packet is used by deformers.
 */
typedef struct st_LXpSampleFalloff {
        float		 value;
} LXpSampleFalloff;


/*
 * Any item can potentially act as a particle source. This interface allocates a
 * particle object for a given item.
 * - Prepare
 * Given an ILxEvaluation interface, the item selects that channels it needs for
 * input. It can return an index, generally for the first channel it added.
 * - Evaluate
 * After prepping, this method is called to allocate the particle source object.
 * The ILxAttributes interface and index are used to read channels selected by
 * the Prepare() method.
 * 
 * The particle object doesn't have a specialized
 * interface, and is instead implemented using a TableauSurface interface to get
 * the point data, and an attributes interface to set the special attributes.
 * 
 */
typedef struct vt_ILxParticleItem {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Prepare) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        unsigned		*index);

        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned		 index,
        void		       **ppvObj);
} ILxParticleItem;

/*
 * The Enumerate() method takes a visitor and calls its Evaluate() method for
 * each replicant of a replicator. During each Evaluate() call, the visitor can get information
 * about the member. If 'localXform' is true, then the transforms from the Replicator Item &
 * Particle Source are *not* applied.
 */
typedef struct vt_ILxReplicatorEnumerator {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Enumerate) (
        LXtObjectID		 self,
        LXtObjectID		 visitor,
        LXtObjectID		 chan,
        int			 localXform);

        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  void,
Position) (
        LXtObjectID		 self,
        LXtVector		 pos);

        LXxMETHOD(  void,
Orientation) (
        LXtObjectID		 self,
        LXtMatrix		 mx);

        LXxMETHOD(  float,
Id) (
        LXtObjectID		 self);

        LXxMETHOD(  float,
Dissolve) (
        LXtObjectID		 self);

        LXxMETHOD (float,
GroupId) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Geometry) (
        LXtObjectID		 self,
        void		       **ppvObj);
} ILxReplicatorEnumerator;

/*
 * The particle evaluation frame object maintains the state of the particle simulation.
 * There can be any number of particles, but all of them contain the same information
 * in the form of a vector of floats. This method gets the description of the complete
 * vertex vector for the simulation.
 * 
 * 
 * MaxCount() returns the number of particle slots, although not all will contain active
 * particles. AliveCount() returns the number of active particles.
 * 
 * AddParticle() adds a new particle with an initial state given by the vector. After
 * this the tags can be set through the StringTag interface. The index of the particle
 * is returned.
 * 
 * This changes an active particle into an inactive one. Inactive particle slots may be
 * reused for new particles.
 * 
 * This method tests if a given particle is active.
 * 
 * The state vector for a particle can be read and set using these methods. For
 * GetVector() the client has to pass a sufficient buffer to recieve the requested
 * state vector.
 * 
 * Particles can also be accessed in runs to improve performance. These methods
 * return runs of 'alive' flags and vector values starting from particle index
 * 'first' and containing 'count' particles.
 * 
 * Find nearest particles to the given 3D position. The maxDist is the range to search for
 * particles, and can be -1 for searching everywhere. The maxCount is the maximum number
 * to return, and the index and dist arrays should be at least that long. If you are giving
 * an existing particle position you need to ask for one more particle than you want since
 * the particle itself will be first.
 */
typedef struct vt_ILxParticleEvalFrame {
        ILxUnknown	 iunk;
        LXxMETHOD( LXtObjectID,
VertexDescription) (
        LXtObjectID		 self);
        LXxMETHOD( unsigned,
MaxCount) (
        LXtObjectID		 self);

        LXxMETHOD( unsigned,
AliveCount) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
AddParticle) (
        LXtObjectID		 self,
        const float		*state,
        unsigned		*index);
        LXxMETHOD( LxResult,
KillParticle) (
        LXtObjectID		 self,
        unsigned		 index);
        LXxMETHOD( unsigned,
IsAlive) (
        LXtObjectID		 self,
        unsigned		 index);
        LXxMETHOD( LxResult,
GetVector) (
        LXtObjectID		 self,
        unsigned		 index,
        float			*vector);

        LXxMETHOD( LxResult,
SetVector) (
        LXtObjectID		 self,
        unsigned		 index,
        const float		*vector);
        LXxMETHOD( LxResult,
AliveRun) (
        LXtObjectID		 self,
        unsigned		 first,
        const unsigned	       **alive,
        unsigned		*count);

        LXxMETHOD( LxResult,
VectorRun) (
        LXtObjectID		 self,
        unsigned		 first,
        float		       **values,
        unsigned		*count);
        LXxMETHOD( LxResult,
Neighbors) (
        LXtObjectID		 self,
        LXtFVector		 pos,
        double			 maxDist,
        int			 maxCount,
        unsigned		*index,
        double			*dist,
        unsigned		*count);
} ILxParticleEvalFrame;

/*
 * Process layers are filters that are called in sequence to generate the
 * simulation.
 * The filter provides a peek at the vertex features that it wants to read or write.
 * For all operations on the particle state, these are the only features that the
 * filter will see. The particle frame will remap the full state into the state
 * requested by the filter.
 * 
 * If 'full' is null, then this should return the features required by this filter.
 * If 'full' is non-null, then it contains the full set of features in the simulation
 * and the filter can return a second vertex containing any of the features in the
 * full set. Filters that don't want optional features can just return the same
 * required vertex for both cases.
 * 
 * 
 * A filter can have one of several types. These determine which processing method
 * will be used for the filter. Additional flags can be set to select the stage
 * of the process where the filter wants to run.
 * 
 * Initialize() is called at start of simulation and gets the frame object and
 * start time.
 * 
 * Step() is called for each new time step. The 'other' pointer is another instance
 * of this same filters, and contains the evaluation state for this timestep.
 * 
 * Cleanup() is called when the simulation is complete.
 * 
 * Frame() is called for filters of type LXi_PFILT_FRAME and allows the filter
 * to process the entire frame in any manner. This is the only way to add or
 * remove particles, for example.
 * 
 * Run() is called for filters of type LXi_PFILT_RUN and allows the filter to process
 * a run of particles starting at 'base' for 'count' particles. The values arrays that
 * are passed in match the description of the requested vertex vector. Some of these
 * particles may be dead, but it may be faster to process them than to test. The alive
 * state can be read by setting the ALIVERUN flag.
 * 
 * Particle() is called for filters of type LXi_PFILT_PARTICLE or LXi_PFILT_NEW_PARTICLE
 * and allows the filter to process a single particle at a time. Again the vector passed
 * matches the request by the filter. For the 'NEW' case this method is only called for
 * particles added by a previous particle filter. This can return LXePARTICLE_KILL to
 * kill the particle.
 */
typedef struct vt_ILxParticleFilter {
        ILxUnknown	 iunk;
        LXxMETHOD( LXtObjectID,
Vertex) (
        LXtObjectID		 self,
        LXtObjectID		 full);
        LXxMETHOD( unsigned,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 vertex,
        LXtObjectID		 frame,
        double			 time);
        LXxMETHOD( LxResult,
Step) (
        LXtObjectID		 self,
        LXtObjectID		 other,
        double			 dt);
        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Frame) (
        LXtObjectID		 self,
        unsigned		 stage);
        LXxMETHOD( LxResult,
Run) (
        LXtObjectID		 self,
        unsigned		 stage,
        float		       **values,
        const unsigned		*alive,
        unsigned		 base,
        unsigned		 count);
        LXxMETHOD( LxResult,
Particle) (
        LXtObjectID		 self,
        unsigned		 stage,
        float			*vertex);
} ILxParticleFilter;

/*
 * A particle co-operator is an item that can be linked to a particle operator. This
 * allows it to be part of the process for a specific operator. Init and cleanup
 * are called at the start and end of the sim.
 * 
 * The operator is called at the start of the step with the time, and for each
 * particle.
 */
typedef struct vt_ILxParticleCoOperator {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 eval);

        LXxMETHOD( LxResult,
Cleanup) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Step) (
        LXtObjectID		 self,
        double			 dT);

        LXxMETHOD( LxResult,
Particle) (
        LXtObjectID		 self);
} ILxParticleCoOperator;

/*
 * Other items can function as point caches. If they provide a PointCacheItem interface
 * then the particle simulation can store its results into the cache. The cache item
 * will typically also have a ParticleItem interface to allow the cache to be used.
 * - Prepare
 * Allow the point cache to attach itself to an evaluation context by adding channels.
 * - Initialize
 * This is called to start writing frames into the cache. Any previous contents of the
 * cache should be cleared. This is passed the vertex description for the particle
 * features to be saved, and the attributes for reading added channels. It also gets
 * the start time and sample rate.
 * 
 * - SaveFrame
 * This saves a single frame of particle data to the cache. The object is a particle
 * object with a TableauSurface interface.
 * 
 * - Cleanup
 * This is called when writing data to the cache is complete.
 * 
 */
typedef struct vt_ILxPointCacheItem {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Prepare) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        unsigned		*index);

        LXxMETHOD( LxResult,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 vdesc,
        LXtObjectID		 attr,
        unsigned		 index,
        double			 time,
        double			 sample);

        LXxMETHOD( LxResult,
SaveFrame) (
        LXtObjectID		 self,
        LXtObjectID		 pobj,
        double			 time);

        LXxMETHOD( LxResult,
Cleanup) (
        LXtObjectID		 self);
} ILxPointCacheItem;

/*
 * Get an enumerator for a replicator. This requires a valid replicator item, and will
 * need an evaluated channel-read object to enumerate.
 * 
 * Enumerate the particle features added to an item. Any item can set the USEFEATURES
 * server tag to allow features to be added. For each feature the visitor can read the
 * ident string and channel offset.
 * 
 * 
 * 
 * If you have a triGroup object with positional data and other particle features,
 * you can convert it to a particle object with this function.
 * 
 * You can also blend two tri-groups representing particle state. Group 0 will be
 * changed based on the amount, with 0.0 being no change and 1.0 being complete
 * replacement.
 * 
 * These methods are provided for accessing a replicator enumerator as part of a
 * modifier. The channel-read object in this case should be NULL.
 * 
 * Get a particle object from any particle item. Takes an eval channel read object.
 */
typedef struct vt_ILxParticleService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
GetReplicatorEnumerator) (
        LXtObjectID		 self,
        LXtObjectID		 replicatorItem,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
EnumParticleFeatures) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        LXtObjectID		 visitor);
        LXxMETHOD( LxResult,
FeatureIdent) (
        LXtObjectID		 self,
        const char	       **ident);
        LXxMETHOD( LxResult,
FeatureOffset) (
        LXtObjectID		 self,
        unsigned		*offset);
        LXxMETHOD( LxResult,
TriGroupToParticle) (
        LXtObjectID		 self,
        LXtObjectID		 triGroup,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
TriGroupBlend) (
        LXtObjectID		 self,
        LXtObjectID		 triGroup0,
        LXtObjectID		 triGroup1,
        double			 blend);
        LXxMETHOD( LxResult,
EnumeratorPrepare) (
        LXtObjectID		 self,
        LXtObjectID		 eval,
        LXtObjectID		 replItem,
        unsigned		*index);

        LXxMETHOD( LxResult,
EnumeratorEvaluate) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned		 index,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
ItemToParticle) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        LXtObjectID		 chanRead,
        void		       **ppvObj);
} ILxParticleService;


        #define LXsPKG_REPLICATOR	"pkg.replicator"
        #define LXs_PKG_IS_REPLICATOR	"-"


        #define LXu_PARTICLEITEM	"BA13DD5D-5093-4D0D-BEFE-119AD4F1FACB"
        // [export] ILxParticleItem prti
        // [local]  ILxParticleItem
        // [python] ILxParticleItem:Evaluate	obj Unknown

/*
 * Any item can read particle sources by setting this tag. This allows particle graph
 * connections for the item.
 */

        #define LXsPKG_READPARTICLES		"readsParticles"
        #define LXsITYPE_SINGLEPARTICLE		"1"
        #define LXsITYPE_MULTIPARTICLE		"*"
        #define LXsITYPE_ORDEREDPARTICLE	"o"

/*
 * The particle object can also support an ILxAttributes interface to provide
 * options that the client can set.
 * - SEED
 * integer attribute that is the random seed for the particle ID or other random
 * attributes of the paricle source.
 * - USEPOL
 * integer setting that can be set on mesh particle sources. 0 generates particles on
 * all vertices; 1 generates particles at polygon centers rather than on points; and
 * 2 generates particles only at detached vertices.
 * 
 * - UPAXIS
 * integer channel which defines the up axis as 0, 1 or 2. This is used for point
 * clouds to determine the best way to orient the particles.
 * 
 * - DEFORM
 * integer boolean that can be set on mesh particle sources. When true particles
 * are on the deformed mesh, on the base mesh if not.
 * 
 * - SPACING
 * spacing is used to increase the number of particles at render time with the render multiplier
 * 
 */

        #define LXsPARTICLEATTR_SEED		"seed"
        #define LXsPARTICLEATTR_USEPOL		"usePol"
        #define LXsPARTICLEATTR_UPAXIS		"upAxis"
        #define LXsPARTICLEATTR_DEFORM		"deform"
        #define LXsPARTICLEATTR_SPACING		"spacing"

/*
 * Particle features defined for vertices in the source. For legacy reasons these
 * defines have a tableau prefix.
 */

        #define LXiTBLX_PARTICLES	 LXxID4('p','r','t','i')
        #define LXsTBLX_PARTICLE_POS	"pos"
        #define LXsTBLX_PARTICLE_XFRM	"xfrm"
        #define LXsTBLX_PARTICLE_ID	"id"
        #define LXsTBLX_PARTICLE_SIZE	"size"
        #define LXsTBLX_PARTICLE_VEL	"vel"
        #define LXsTBLX_PARTICLE_MASS	"mass"
        #define LXsTBLX_PARTICLE_FORCE	"force"
        #define LXsTBLX_PARTICLE_AGE	"age"
        #define LXsTBLX_PARTICLE_PATH	"pathLength"
        #define LXsTBLX_PARTICLE_DISS	"dissolve"
        #define LXsTBLX_PARTICLE_RATE	"rate"
        #define LXsTBLX_PARTICLE_ITEM	"item"
        #define LXsTBLX_PARTICLE_ANGVEL	"angVel"
        #define LXsTBLX_PARTICLE_TORQUE	"torque"
        #define LXsTBLX_PARTICLE_PPREV	"posPrev"
        #define LXsTBLX_PARTICLE_LUM	"lum"
        #define LXsTBLX_PARTICLE_RGB	"rgb"

        #define LXiTBLX_COLLISION	 LXxID4('c','o','l','l')
        #define LXsTBLX_COLLISION_VAL	"val"
        #define LXsTBLX_COLLISION_POS	"pos"
        #define LXsTBLX_COLLISION_NORM	"norm"
        #define LXsTBLX_COLLISION_COUNT	"count"
        #define LXsTBLX_COLLISION_TIME	"time"

/*
 * The ReplicatorEnumerator interface allows traversal of the members of the particle
 * item.
 */

        #define LXu_REPLICATORENUMERATOR	"01EC90A9-924F-4475-BA6A-FFF8A2691CD5"
        // [local]  ILxReplicatorEnumerator
        // [python] ILxReplicatorEnumerator:Item	obj Item
        // [python] ILxReplicatorEnumerator:Geometry	obj Unknown

/*
 * The 'alive' run holds state bits for each particle. Newborn particles are alive+changed,
 * just killed particles are dead+changed. The changed flag is cleared at the start of each
 * timestep.
 */

        #define LXfFRAME_ALIVE		 0x01
        #define LXfFRAME_CHANGED	 0x02


        #define LXu_PARTICLEEVALFRAME	"1AC26263-A422-4B17-A929-2F616037754F"
        // [local]  ILxParticleEvalFrame


        #define LXiPFILT_FRAME		0x00
        #define LXiPFILT_RUN		0x01
        #define LXiPFILT_PARTICLE	0x02
        #define LXiPFILT_NEW_PARTICLE	0x03
        #define LXmPFILT_TYPE		0x0F
        #define LXfPFILT_PRESTAGE	0x10
        #define LXfPFILT_DERIVSTAGE	0x20
        #define LXfPFILT_POSTSTAGE	0x40
        #define LXfPFILT_ALIVERUN	0x80


        #define LXu_PARTICLEFILTER	"04A3C0C5-1C5C-43F5-8559-ACF3BAE79C0B"
        // [export] ILxParticleFilter pfilt
        // [local]  ILxParticleFilter
        // [python] ILxParticleFilter:Particle:vertex	vector

        #define LXsPKG_PFILT_CHANNEL	"particleFilter.channel"

        #define LXsPFILT_ENABLECHANNEL	"pfiltEnable"

        #define LXePARTICLE_KILL	LXxGOODCODE(LXeSYS_PSYS,1)


        #define LXu_PARTICLECOOPERATOR	"DFBCF67B-C327-496E-8A30-20B64C31A9BB"
        // [export] ILxParticleCoOperator pcoi
        // [local]  ILxParticleCoOperator

        #define LXsPKG_PCOOP_CHANNEL	"particleCoop.channel"
        #define LXsGRAPH_PARTICLEOP	"particleOp"


        #define LXu_POINTCACHEITEM	"10930C44-62D3-42D1-BD6B-8FE015D9C566"
        // [export] ILxPointCacheItem pcache
        // [local]  ILxPointCacheItem

        #define LXsGRAPH_POINTCACHE	"pointCache"


        #define	LXsITYPE_PSIM		 "particleSim"
        #define	LXsICHAN_PSIM_ENABLE	 "enable"
        #define	LXsICHAN_PSIM_SAMPLES	 "samples"
        #define	LXsICHAN_PSIM_ADDAGE	 "addAge"
        #define	LXsICHAN_PSIM_ADDPATH	 "addPath"
        #define	LXsICHAN_PSIM_STOREFORCE "storeForce"
        #define	LXsICHAN_PSIM_STOREMASS	 "storeMass"
        #define	LXsICHAN_PSIM_AGEKILL	 "ageKill"
        #define	LXsICHAN_PSIM_AGEMAX	 "ageMax"
        #define	LXsICHAN_PSIM_AGEEXTEND	 "ageExtend"
        #define	LXsICHAN_PSIM_GRAVENABLE "gravEnable"
        #define	LXsICHAN_PSIM_GRAVAXIS	 "gravAxis"
        #define	LXsICHAN_PSIM_GRAVITY	 "gravity"
        #define	LXsICHAN_PSIM_DRAGENABLE "dragEnable"
        #define	LXsICHAN_PSIM_DRAG	 "drag"
        #define	LXsICHAN_PSIM_COLOR	 "color"
        #define	LXsICHAN_PSIM_TGROUP	 "tgroup"
        #define	LXsICHAN_PSIM_PCOUNT	 "pCount"
        #define	LXsICHAN_PSIM_NTHREAD	 "nThread"
        #define	LXsICHAN_PSIM_CACHEMEM	 "cacheMem"

        #define	LXsGRAPH_PSIM		 "particleSim"

/*
 * The particle service provides methods for accessing particle-related information.
 */

        #define LXa_PARTICLESERVICE	"particleservice"
        #define LXu_PARTICLESERVICE	"34928BF8-3917-47EF-8350-DD3A3DDED7EE"
        // [python] ILxParticleService:GetReplicatorEnumerator	obj ReplicatorEnumerator
        // [python] ILxParticleService:EnumeratorEvaluate	obj ReplicatorEnumerator


        #define LXsP_ANIM_DEFORM	"animDeform"

/*
 * For now we have one deformer effect: amplitude.
 */

        #define LXs_FX_DEFORM_AMP	"deformAmplitude"


        #define LXsP_SAMPLE_FALLOFF	"sampleFalloff"

/*
 * For now we have one falloff effect: value.
 */

        #define LXs_FX_FALLOFF_VALUE	"falloffValue"

#endif
