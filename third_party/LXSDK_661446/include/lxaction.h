/*
 * LX action module
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
#ifndef LX_action_H
#define LX_action_H

typedef struct vt_ILxActionListener ** ILxActionListenerID;
typedef struct vt_ILxChannelRead ** ILxChannelReadID;
typedef struct vt_ILxChannelWrite ** ILxChannelWriteID;
typedef struct vt_ILxEvalModifier ** ILxEvalModifierID;
typedef struct vt_ILxModifier ** ILxModifierID;
typedef struct vt_ILxSimulationModifier ** ILxSimulationModifierID;
typedef struct vt_ILxEvaluation ** ILxEvaluationID;
typedef struct vt_ILxModifier1 ** ILxModifier1ID;

#include <lxcom.h>



/*
 * An action listener can be registered to watch for changes to action values.
 */
typedef struct vt_ILxActionListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
ActionChannelSignal) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 channel);

        LXxMETHOD( void,
ActionChannelConstantChange) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 channel);

        LXxMETHOD( void,
ActionChannelConstantPreChange) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 channel);
} ILxActionListener;

/*
 * The channel-read interface can be presented by anything that contains
 * values for item channels. This includes actions and scene evaluation, both
 * channel-read objects allocated through the scene interface.
 * The envelope method returns an envelope only if one exists for the channel.
 * Test to see if a channel is animated.
 * If this is an evaluated channel-read (specified by any time), IsAnimated() tests
 * whether the evaluation for the channel changes at any time during the animation.
 * 
 * If this an action channel-read, IsAnimated() tests whether a channel
 * contains animation, by looking at the whole action hierarchy and instances,
 * and also takes animated gradients into account.
 * 
 * 
 * Some channels may be baked -- that is they have samples cached over a range of
 * time. These methods test if a channel is baked and return the samples as a
 * ValueArray object.
 * 
 * The time at which values are read can be changed.
 * 
 * 801 methods for type, and getting encoded int values directly.
 */
typedef struct vt_ILxChannelRead {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
ValueObj) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Integer) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        int			*value);

        LXxMETHOD( LxResult,
Double) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        double			*value);

        LXxMETHOD( LxResult,
String) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        const char	       **value);

        LXxMETHOD( LxResult,
Envelope) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        void		       **ppvObj);

        LXxMETHOD( double,
Time) (
        LXtObjectID		 self);
        LXxMETHOD( int,
IsAnimated) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        int			 index);
        LXxMETHOD( LxResult,
IsBaked) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel);

        LXxMETHOD( LxResult,
BakedSamples) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        double			*firstSample,
        double			*spsRate,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
SetTime) (
        LXtObjectID		 self,
        double			 time);
// QWEB_MACRO_BEGIN - SDK Common: Channel type methods
        LXxMETHOD( LxResult,
Type) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        unsigned		*type);

        LXxMETHOD( LxResult,
TypeName) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        const char	       **typeName);
// QWEB_MACRO_END - SDK Common: Channel type methods

        LXxMETHOD( LxResult,
EncodedInt) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        char			*buf,
        unsigned		 len);
} ILxChannelRead;

/*
 * In some cases we can write values to channels. Values written to actions are
 * written as constants when using the Double and Integer methods, note that any
 * animation on the channel will be overwritten.
 * The DoubleKey and IntegerKey methods will create keys on channels that are
 * already animated, otherwise the constant value for the channel will be set.
 * Passing a value of one to the 'create' argument can be used to always create
 * a key.
 * 
 * The envelope method creates an envelope for the channel if it does not exist.
 * If an envelope is created it will have a key created at the time chosen when the
 * interface was obtained. The key will be created with the value of the constant
 * channel.
 * 
 * 
 * To cache baked values on a channel this method is called to set the start time and
 * samples per second. The returned ValueArray should be filled with the samples.
 * 
 * 801 methods for type and encoded ints. For writing we have a choice of setting
 * the int as a constant or a keyframe.
 */
typedef struct vt_ILxChannelWrite {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
ValueObj) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Integer) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        int			 value);

        LXxMETHOD( LxResult,
Double) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        double			 value);

        LXxMETHOD( LxResult,
String) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        const char		*value);

        LXxMETHOD( LxResult,
Envelope) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
IntegerKey) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        int			 value,
        int			 create);

        LXxMETHOD( LxResult,
DoubleKey) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        double			 value,
        int			 create);

        LXxMETHOD( LxResult,
SetState) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        unsigned int		 state);
        LXxMETHOD( LxResult,
BakeSamples) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        double			 firstSample,
        double			 spsRate,
        void		       **ppvObj);
// QWEB_MACRO_BEGIN - SDK Common: Channel type methods
        LXxMETHOD( LxResult,
Type) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        unsigned		*type);

        LXxMETHOD( LxResult,
TypeName) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        const char	       **typeName);
// QWEB_MACRO_END - SDK Common: Channel type methods

        LXxMETHOD( LxResult,
EncodedInt) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        const char		*value);

        LXxMETHOD( LxResult,
EncodedIntKey) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 channel,
        const char		*value);
} ILxChannelWrite;

/*
 * Modifiers have two forms. The modifier class is a plug-in server of type
 * ILxEvalModifier. This provides methods for creating modifier instances which
 * operate on specific channels. The instance is an object that caches specific
 * references to input and output channels and can perform computations over
 * them. For example there is only one "IK" ILxEvalModifier server, but it
 * will create instances to evaluate IK for all locators with parents.
 * Each instance is identified by a key channel. The class interface provides
 * methods for enumerating through key channels and creating and testing
 * instances.
 * - Reset
 * Set the modifier class to the given scene, and reset the count of key
 * channels for the Next() method.
 * 
 * - Next
 * Returns the item and index for the next key channel for this
 * modifier in the current scene.  If the last one has already been read, this
 * method returns null.
 * 
 * - Alloc
 * Create a new instance for the given key channel.  The eval object
 * allows the instance to create references to the channels it wants to be
 * able to read and write, and to cache the attributes interface needed to read
 * their values during evaluation.
 * 
 */
typedef struct vt_ILxEvalModifier {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Reset) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( LXtObjectID,
Next) (
        LXtObjectID		 self,
        unsigned		*index);

        LXxMETHOD( LxResult,
Alloc) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index,
        LXtObjectID		 eval,
        void		       **ppvObj);
} ILxEvalModifier;

/*
 * - Test
 * Test an instance to see if its still valid for the given key
 * channel. If it returns LXe_FALSE or an error the instance will be removed.
 * - Invalidate
 * Check to see if a change to the given input channel should invalidate the
 * current state of the modifier. LXe_OK should be returned in most cases,
 * but LXe_FALSE can be returned if the given channel has no effect on the
 * modifier.
 * - RequiredCount, Required
 * Enumerates the required channels for this modifier, getting the key item
 * for an input channel.
 * 
 * - Free
 * Free cache data for this modifier.
 * 
 */
typedef struct vt_ILxModifier {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index);

        LXxMETHOD( LxResult,
Invalidate) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index);

        LXxMETHOD( LxResult,
Validate) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index,
        LxResult		 rc);

        LXxMETHOD( unsigned,
RequiredCount) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Required) (
        LXtObjectID		 self,
        unsigned		 index,
        unsigned		*attr,
        void		       **ppvObj);

        LXxMETHOD( void,
Free) (
        LXtObjectID		 self,
        void			*cache);
} ILxModifier;

/*
 * The modifier instance can also present a simulation interface. If this is present
 * then the modifier's Evaluate() method will never be called. Instead it will only
 * be evaluated in the context of a simulation, and the results cached by the eval
 * system.
 * - Enabled
 * Returns LXe_TRUE if the simulation should be computed.
 * - Initialize
 * Called to start the simulation. Initial conditions can be read from the attributes.
 * Start time of the simulation is also passed.
 * 
 * - Cleanup
 * End the simulation.
 * 
 * - StepSize
 * Allows the modifier to request the general size of its time step. The exact step
 * size will vary, but as a rule a simulation can vary its step size based on the
 * conditions of the simulation.
 * 
 * - Step
 * Advance the simulation. This is passed the delta for this step, and it should
 * read any inputs required from the attributes and write the state of the simulation
 * to its output channels.
 * 
 * - Bake
 * The sim is given the chance to bake its own channel value.
 * 
 */
typedef struct vt_ILxSimulationModifier {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Enabled) (
        LXtObjectID		 self,
        LXtObjectID		 chanRead);

        LXxMETHOD( LxResult,
Initialize) (
        LXtObjectID		 self,
        double			 time,
        double			 sample);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
StepSize) (
        LXtObjectID		 self,
        double			*stepSize);

        LXxMETHOD( LxResult,
Step) (
        LXtObjectID		 self,
        double			 dt);

        LXxMETHOD( LxResult,
Bake) (
        LXtObjectID		 self,
        double			 time);
} ILxSimulationModifier;

/*
 * The ILxEvaluation interface is passed to the ILxEvalModifier::Alloc() method as
 * the way for instances to declare their inputs and outputs. It is also passed to
 * any other subsystems that need to be able to register their own inputs, although
 * they are generally not allowed to specify outputs.
 * Clients should not read channel values at this point. This setup assumes that
 * the inputs can have any possible value, so all contingencies should be considered.
 * During actual evaluation the client will be passed an ILxAttributes interface
 * from which to read their inputs.
 * 
 * - AddChannel
 * This adds a channel by item and index for input, output or both.  The returned
 * index in 'attr' is the index in the attributes interface provided during evaluation.
 * 
 * - AddChannelName
 * Same as above but takes the channel name instead of the index.
 * 
 * - ReadTime
 * Adds the time of the evaluation as an input attribute for those modifier nodes
 * that need it.
 * 
 * 
 * Modifiers can also perform alternate evaluation. The "set" methods are called
 * during modifier evaluation to set all inputs to the modifier to come from an
 * alternate evaluation -- essentially an alternate reality. The modifier can
 * set an alternate time, or they can set alternate channel values. The latter
 * is done by calling SetAlternate() and writing alternate values using the
 * ILxChannelWrite interface that is returned. Alternate evaluation can also
 * be cleared so that inputs come from the reality being altered.
 * 
 * Modifiers can set and get cache data objects to remember their last evaluation
 * state. These are freed by ILxModifier::Free().
 * 
 * One more useful alternate is the setup action.
 * 
 * For baked channels, this method allows the client to read the baked sample
 * before and after the current evaluation time. For 'bracket' of zero the sample
 * is returned at or just after the current time. The returned 'fraction' is a
 * value from 0 to 1 indicating how close this sample is to the next one. If the
 * fraction is non-zero then calling this again with 'bracket' of 1 returns the
 * sample just after the current time. This allows values from baked samples to
 * be exactly interpolated.
 * 
 * Get an approximate timestep for evaluating nearby values. During a simulation this
 * is the stepsize of the sim which may be less than a frame. In normal circumstances
 * this is just the frame interval.
 * 
 * Get information about simulation. The LXfSIM_ state flags indicate if the simulation
 * is just a fake preview and if so, if it's advancing over time. The range is only
 * valid for simulations that are being cached.
 */
typedef struct vt_ILxEvaluation {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
AddChannel) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index,
        unsigned		 type,
        unsigned		*attr);

        LXxMETHOD( LxResult,
AddChannelName) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        const char		*name,
        unsigned		 type,
        unsigned		*attr);

        LXxMETHOD( LxResult,
ReadTime) (
        LXtObjectID		 self,
        unsigned		*attr);
        LXxMETHOD( LxResult,
SetAlternateTime) (
        LXtObjectID		 self,
        double			 time);

        LXxMETHOD( LxResult,
SetAlternate) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
ClearAlternate) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SetCache) (
        LXtObjectID		 self,
        void			*cache);

        LXxMETHOD( void *,
GetCache) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SetAlternateSetup) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
GetBakedSample) (
        LXtObjectID		 self,
        unsigned		 index,
        unsigned		 bracket,
        double			*fraction,
        void		       **ppvObj);
        LXxMETHOD( double,
GetDT) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SimulationState) (
        LXtObjectID		 self,
        unsigned		*flags);

        LXxMETHOD( LxResult,
SimulationRange) (
        LXtObjectID		 self,
        double			*start,
        double			*end);
} ILxEvaluation;

/*
 * The ILxModifier1 interface was used in some 501 plug-ins, specifically Recoil and
 * its relatives. This translation can probably be retred post-601.  __601__
 */
typedef struct vt_ILxModifier1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Evaluate) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index);

        LXxMETHOD( LxResult,
Invalidate) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index);

        LXxMETHOD( unsigned,
RequiredCount) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Required) (
        LXtObjectID		 self,
        unsigned		 index,
        unsigned		*attr,
        void		       **ppvObj);

        LXxMETHOD( void,
Free) (
        LXtObjectID		 self,
        void			*cache);
} ILxModifier1;


        #define LXu_ACTIONLISTENER	"4819A297-A922-11D8-B1AD-000393CE9680"
        // [export] ILxActionListener actl
        // [local]  ILxActionListener


        #define LXu_CHANNELREAD		"D5A8C4FD-151C-4D8B-97E1-6E1B4087886B"
        // [local]   ILxChannelRead
        // [const]   ILxChannelRead:IsAnimated
        // [default] ILxChannelRead:IsBaked = LXe_FALSE
        // [const]   ILxChannelRead:IsBaked
        // [python]  ILxChannelRead:IsBaked		bool
        // [python]  ILxChannelRead:IsAnimated		bool
        // [python]  ILxChannelRead:BakedSamples	obj ValueArray (value)
        // [python]  ILxChannelRead:Envelope		obj Envelope (envelope)
        // [python]  ILxChannelRead:ValueObj		obj Unknown


        #define LXu_CHANNELWRITE	"91BFE3B8-16C6-4195-BFE5-3F0E3C0C5C57"
        // [local]   ILxChannelWrite
        // [python]  ILxChannelWrite:ValueObj		obj Unknown
        // [python]  ILxChannelWrite:BakeSamples	obj ValueArray
        // [python]  ILxChannelWrite:Envelope		obj Envelope


        #define LXs_ACTIONLAYER_SETUP	"setup"
        #define LXs_ACTIONLAYER_ANIM	"scene"
        #define LXs_ACTIONLAYER_EDIT	"edit"

/*
 * The modifier class can describe itself with server tags.
 * - TYPELIST
 * A whitespace-delimited list of item types.  The modifier will only
 * be made active if one of these types is present in the cinema.  Also if items
 * of this type are added or removed the modifier will be re-validated.
 * - GRAPHLIST
 * A whitespace-delimited list of graph names.  The modifier will be
 * re-validated any time links in these graphs change.
 * 
 */

        #define LXu_EVALMODIFIER	"30AAAF24-9699-4737-8E3B-E264AA4B7A3E"
        #define LXa_EVALMODIFIER	"evalModifier"
        // [export]  ILxEvalModifier eval
        // [local]   ILxEvalModifier
        // [default] ILxEvalModifier:Next = 0
        #define LXsMOD_TYPELIST		"modifier.typeList"
        #define LXsMOD_GRAPHLIST	"modifier.graphList"
        #define LXsMOD_GUIDLIST		"modifier.guidList"
        #define LXsMOD_REQUIREDTYPE	"modifier.required"

/*
 * The modifier instance, allocated for a specific key channel in the scene,
 * is given by an ILxModifier interface.
 * - Evaluate
 * Evaluate a modifier instance given an attribute interfaces for reading
 * and writing channel values. The result code for the evaluation can be
 * read using the ILxEvaluation interface, and can contain information about
 * changes since the last invalidation. General codes allow for identical
 * result, and the default is totally different.
 */

        #define LXeEVAL_IDENTICAL	LXxGOODCODE(LXeSYS_EVAL,1)
        #define LXeEVAL_DIFFERENT	LXe_OK


        #define LXu_MODIFIER		"8D3BEC86-E10B-426A-8BA3-846250E25AF4"
        // [local]   ILxModifier
        // [export]  ILxModifier mod
        // [default] ILxModifier:RequiredCount = 0
        // [default] ILxModifier:Test = LXe_TRUE
        // [python]  ILxModifier:Required	obj Item (item)
        // [python]  ILxModifier:Test		bool
        // [python]  ILxModifier:Invalidate	bool

/*
 * There is a special case where some modifiers can have read-write channels, where the modifier
 * takes their inputs and modifies them for output. For these channels to be recognized as intenally
 * modifier, a special tag can be placed on these packages. For now, the mere presence of the tag
 * is enough to flag these channels as potentially modified.
 */

        #define LXs_MODIFIER_OPTIONS		"modifierOptions"


        #define LXu_SIMULATIONMODIFIER		"A44F37F3-E94F-4042-85E2-1BBF633E00D2"
        // [export]  ILxSimulationModifier sim
        // [local]   ILxSimulationModifier
        // [default] ILxSimulationModifier:Enabled = LXe_TRUE
        // [python]  ILxSimulationModifier:Enabled   bool

/*
 * The channel type can be READ, WRITE, or both. The modifier should also set the
 * SETUP flag if a channel will be read in setup mode. The FORCE flag is used in
 * conjunction with the READ flag, and specifies an input channel that may not
 * always be read by the modifier. If the FORCE flag is set, the modifier will
 * always be invalidated when the channel changes, even if the modifier doesn't
 * explicitly read the the input channel.
 */

        #define LXfECHAN_READ		 0x01
        #define LXfECHAN_WRITE		 0x02
        #define LXfECHAN_SETUP		 0x04
        #define LXfECHAN_FORCE		 0x08

        #define LXfSIM_NOCACHE		 0x01
        #define LXfSIM_CONTINUOUS	 0x02

        #define LXu_EVALUATION		"FB552E5F-746E-4d74-885C-40A931B82B84"
        // [local]   ILxEvaluation
        // [default] ILxEvaluation:GetCache = 0
        // [python]  ILxEvaluation:GetBakedSample	obj Unknown
        // [python]  ILxEvaluation:SetAlternate		obj ChannelWrite


        #define LXu_MODIFIER1		"FA406E1C-5E6A-4574-A795-AA0F07DFAFB5"

#endif
