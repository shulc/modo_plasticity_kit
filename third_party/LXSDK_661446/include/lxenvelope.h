/*
 * LX envelope module
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
#ifndef LX_envelope_H
#define LX_envelope_H

typedef struct vt_ILxEnvelope ** ILxEnvelopeID;
typedef struct vt_ILxKeyframe ** ILxKeyframeID;
typedef struct vt_ILxGradientFilter ** ILxGradientFilterID;
typedef struct vt_ILxGradientFilter1 ** ILxGradientFilter1ID;

#include <lxcom.h>

/*
 * The end behaviors determine what value the envelope takes outside the range
 * of keyframes.
 * See Also: LXtEndBehavior
 * - RESET
 * A default value, or may be just zero.
 * - CONSTANT
 * The value of the first or last keyframe. For first or last keys set to "Auto" or "Auto Flat" the slopes of
 * the keys will be adjusted to provide a smooth interpolation to or from the behavior.
 * - REPEAT
 * The values in the keyframe range repeating continuously.
 * - OSCILLATE
 * Like repeat, but the values run forwards and backward alternately. For first or last keys set to "Auto" or
 * "Auto Flat" the slopes of the keys will be adjusted to provide a smooth interpolation to or from the behavior.
 * 
 * - OFFSETREPEAT
 * Like repeat, but the values are offset in each cycle by the difference between the first and last keyframes.
 * For first or last keys set to "Auto" or "Auto Flat" the slopes of the keys will be adjusted to provide a smooth
 * interpolation to or from the behavior.
 * 
 * - LINEAR
 * Linear interpolation from the slope at the nearest keyframe.
 * 
 * - NONE
 * Indicates that the envelope does not exist before or after the explicit keyframe range.
 * This isbe used by motion evaluation code to decide whether to use the envelope for a
 * channel or to look up the parent envelope or default value.
 * 
 * - CONSTANT_KEEP_SLOPE
 * As for constant except that the slopes of the first or last keys are not changed.
 * 
 * - OSCILLATE_KEEP_SLOPE
 * As for oscillate except that the slopes of the first or last keys are not changed.
 * 
 * - OFFSETREPEAT_KEEP_SLOPE
 * As for offset repeat except that the slopes of the first or last keys are not changed.
 * 
 * 
 */

        typedef unsigned	LXtEndBehavior;

        #define LXiENV_RESET			0
        #define LXiENV_CONSTANT			1
        #define LXiENV_REPEAT			2
        #define LXiENV_OSCILLATE		3
        #define LXiENV_OFFSETREPEAT		4
        #define LXiENV_LINEAR			5
        #define LXiENV_NONE			6
        #define LXiENV_CONSTANT_KEEP_SLOPE	LXiENV_NONE
        #define LXiENV_OSCILLATE_KEEP_SLOPE	7
        #define LXiENV_OFFSETREPEAT_KEEP_SLOPE	8

/*
 * The slope can have one of the following values.
 * - LXiSLOPE_DIRECT
 * the slope of the tangent is set based on the value stored in the key.
 * - LXiSLOPE_AUTO
 * the slope of the tangent is calculated automatically with regard to
 * surrounding keys. This is similar to the slope adjustments made by TCB curves.
 * 
 * - LXiSLOPE_LINEAR_IN
 * the slope of the tangent is calculated to align with the previous key's value.
 * 
 * - LXiSLOPE_LINEAR_OUT
 * the slope of the tangent is calculated to align with the next key's value.
 * 
 * - LXiSLOPE_FLAT
 * the slope of the tangent is set to zero.
 * 
 * - LXiSLOPE_AUTOFLAT
 * the same as auto but if a neighboring key has the same value as the key the
 * slope is set to zero.
 * 
 * - LXiSLOPE_STEPPED
 * Maintains the value of the previous key between pairs of keys.
 * 
 */

        typedef unsigned	LXtSlopeType;

        #define LXiSLOPE_DIRECT		0
        #define LXiSLOPE_AUTO		1
        #define LXiSLOPE_LINEAR_IN	2
        #define LXiSLOPE_LINEAR_OUT	3
        #define LXiSLOPE_FLAT		4
        #define LXiSLOPE_AUTOFLAT	5
        #define LXiSLOPE_STEPPED	6
        #define LXiSLOPE_SMOOTHFLAT	7



/*
 * The IsInt() method returns 1 for integer-valued type envelopes, 0 otherwise.
 * This method allocates a new keyframe enumerator, allowing multiple clients to
 * query the same envelope.
 * These two methods allow the envelope to be evaluated.  The input value is given as
 * "time" although it is any independent parameter.  the correct method must be called
 * based on the envelopes numeric type.
 * 
 * The envelopes end behavior is read and set with these methods.  The side can be
 * IN or OUT to select the behavior for times prior to the first key frame or the
 * behavior after the last keyframe, respectively.  The behavior for both can be
 * set by specifying BOTH.
 * 
 * For envelopes which can be edited this removes all the keys.
 * 
 * 
 */
typedef struct vt_ILxEnvelope {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned,
IsInt) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Enumerator) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD( LxResult,
EvaluateF) (
        LXtObjectID		 self,
        double			 time,
        double			*value);

        LXxMETHOD( LxResult,
EvaluateI) (
        LXtObjectID		 self,
        double			 time,
        int			*value);
        LXxMETHOD( unsigned int,
EndBehavior) (
        LXtObjectID		 self,
        unsigned int		 side);

        LXxMETHOD( LxResult,
SetEndBehavior) (
        LXtObjectID		 self,
        unsigned int		 behavior,
        unsigned int		 side);
        LXxMETHOD( LxResult,
Clear) (
        LXtObjectID		 self);

        LXxMETHOD( unsigned int,
Interpolation) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SetInterpolation) (
        LXtObjectID		 self,
        unsigned int		 type);
} ILxEnvelope;

/*
 * The keyframe interface has a state which is a current key, so it acts as
 * an iterator.  The next four methods set the current key based on its position
 * in the sequence, or relative to the current key.  They return LXe_NOTFOUND
 * on errors.
 * Find() selects a key at or near the current time.  If side is IN then the key
 * prior or equal to the time will become current.  OUT gets the key after the given
 * time.  For BOTH the key must be exactly at the requested time.
 * 
 * The time (or other independent parameter) of the key can be read with this
 * method.
 * 
 * This method returns flags for which attributes of the key are broken and are
 * different for the incoming and outgoing sides of the key.  If the value of the
 * key itself is broken, the side flag indicates which side of the key controls
 * the value exactly at the given time.
 * 
 * Read the value of the key as a float or int for either side of the key.  For
 * unbroken keys this will be the same.
 * 
 * The slope type, slope and weight may likewise be read for the current key.
 * 
 * This alters the time (or independent parameter) of the key, potentially
 * changing its relative position in the sequence of keys.
 * 
 * These methods allow the various parameters of the keyframe to be set.  Breaking
 * and unbreaking are controlled implicitly with the 'side' parameter.  Setting
 * the side to IN or OUT will break the parameter and only affect the specified
 * side.  Setting the side to BOTH will unbreak the parameter.  The last side set
 * when breaking the value will be the controlling side for the key.
 * 
 * This will set the weight for the key unless 'reset' is true, in which case the
 * weight will be set back to automatic.
 * 
 * These methods allow keys to be created at the given time (or other independent
 * parameter) and value.
 * 
 * This deletes the current key.
 */
typedef struct vt_ILxKeyframe {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
First) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Last) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Next) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Previous) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Find) (
        LXtObjectID		 self,
        double			 time,
        unsigned int		 side);
        LXxMETHOD( LxResult,
GetTime) (
        LXtObjectID		 self,
        double			*time);
        LXxMETHOD( LxResult,
GetBroken) (
        LXtObjectID		 self,
        unsigned int		*breaks,
        unsigned int		*side);
        LXxMETHOD( LxResult,
GetValueF) (
        LXtObjectID		 self,
        double			*value,
        unsigned int		 side);

        LXxMETHOD( LxResult,
GetValueI) (
        LXtObjectID		 self,
        int			*value,
        unsigned int		 side);
        LXxMETHOD( LxResult,
GetSlopeType) (
        LXtObjectID		 self,
        LXtSlopeType		*type,
        unsigned int		*weighted,
        unsigned int		 side);

        LXxMETHOD( LxResult,
GetSlope) (
        LXtObjectID		 self,
        double			*slope,
        unsigned int		 side);

        LXxMETHOD( LxResult,
GetWeight) (
        LXtObjectID		 self,
        double			*weight,
        unsigned int		 side);
        LXxMETHOD( LxResult,
SetTime) (
        LXtObjectID		 self,
        double			 time);
        LXxMETHOD( LxResult,
SetValueF) (
        LXtObjectID		 self,
        double			 value,
        unsigned int		 side);

        LXxMETHOD( LxResult,
SetValueI) (
        LXtObjectID		 self,
        int			 value,
        unsigned int		 side);

        LXxMETHOD( LxResult,
SetSlope) (
        LXtObjectID		 self,
        double			 slope,
        unsigned int		 side);

        LXxMETHOD( LxResult,
SetSlopeType) (
        LXtObjectID		 self,
        LXtSlopeType		 type,
        unsigned int		 side);
        LXxMETHOD( LxResult,
SetWeight) (
        LXtObjectID		 self,
        double			 weight,
        unsigned int		 reset,
        unsigned int		 side);
        LXxMETHOD( LxResult,
AddF) (
        LXtObjectID		 self,
        double			 time,
        double			 value);

        LXxMETHOD( LxResult,
AddI) (
        LXtObjectID		 self,
        double			 time,
        int			 value);
        LXxMETHOD( LxResult,
Delete) (
        LXtObjectID		 self);
} ILxKeyframe;

/*
 * 
 * If the Gradient Filter is a GENERATE type filter, the Generate method will be
 * called to create a value for a specific "time" sample.
 * 
 * If the Gradient Filter is a EVALUATE type filter, the Evaluate method will be
 * called to modify an existing value for a specific "time" sample.
 * 
 * If the Gradient Filter is a MULTISAMPLE type filter, the MultiSample method will
 * be called to modify an existing value at an arbitary time sample.
 */
typedef struct vt_ILxGradientFilter {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned int,
Type) (
        LXtObjectID		 self);
        LXxMETHOD( double,
Generate) (
        LXtObjectID		 self,
        double			 time);
        LXxMETHOD( double,
Evaluate) (
        LXtObjectID		 self,
        double			 time,
        double			 value);
        LXxMETHOD( double,
MultiSample) (
        LXtObjectID		 self,
        double			 time,
        LXtObjectID		 other);
} ILxGradientFilter;

typedef struct vt_ILxGradientFilter1 {
        ILxUnknown	 iunk;
        LXxMETHOD( double,
Evaluate) (
        LXtObjectID		 self,
        double			 inVal);

        LXxMETHOD( LxResult,
AddRef) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Release) (
        LXtObjectID		 self);
} ILxGradientFilter1;

/*
 * The envelope interface provides access to the overall attributes of the
 * envelope shape, evaluation, and a keyframe accessor.
 */

        #define LXu_ENVELOPE		"E39EB451-6C35-47F4-8A7D-FF96671C0DEF"
        // [local]  ILxEnvelope
        // [python] ILxEnvelope:Enumerator	obj Keyframe


        #define LXiENVSIDE_IN			1
        #define LXiENVSIDE_OUT			2
        #define LXiENVSIDE_BOTH			3



        #define LXiENVv_INTERP_CURVE		0
        #define LXiENVv_INTERP_LINEAR		1
        #define LXiENVv_INTERP_STEPPED		2



        #define LXu_KEYFRAME		"D1D0261F-22CF-4E5D-822E-76B5DEC98AE4"
        // [local]  ILxKeyframe


        #define	LXfKEYBREAK_VALUE		(1<<0)
        #define	LXfKEYBREAK_SLOPE		(1<<1)
        #define	LXfKEYBREAK_WEIGHT		(1<<2)


/*
 * A gradient usually contains keyframe data that exists in an envelope that can be
 * directly modified by the user. However gradients can be dynamically generated
 * and modified using Gradient Filters. Gradient Filters are added to a stack, and
 * when evaluated, the stack is recursively evaluated to compute the final value for
 * a specific sample.
 * When reading a Gradient channel in an evaluated context, a Gradient Filter object
 * will be returned. Evaluating this filter for it's value, will return the final
 * computed state, regardless of whether the gradient is composed from keyframes,
 * filters, or a combination of the two.
 */

        #define LXu_GRADIENTFILTER	"B3E49419-99B9-4066-9DEC-AA4EF9802F0D"
        #define LXa_GRADIENTFILTER	"gradientFilter2"
        // [export] ILxGradientFilter grfilt
        // [local]  ILxGradientFilter
        // [default] ILxGradientFilter:Generate = 0
        // [default] ILxGradientFilter:Evaluate = 0
        // [default] ILxGradientFilter:MultiSample = 0

/*
 * Gradient filters can have two distinct types; Modify and Generate. Generate type
 * filters are expected to compute a new gradient value, ignoring anything below it
 * in the stack, whereas Modify type filters are provided with the computed value
 * of all filters below it in the stack, and it is expected to modify and return
 * the value. A multi-sample filter is a variant on the Modify filter, but instead
 * of being passed a single evaluated sample from further down the stack, the
 * MultiSample method is passed a GradientFilter from lower in the stack, allowing
 * multiple samples at arbitrary times to be evaluated. Finally, Envelope filters
 * are a special type of Generate filter, that are generated from keyframed envelope
 * data.
 */

        #define LXi_GRADIENTFILTER_GENERATE		0
        #define LXi_GRADIENTFILTER_MODIFY		1
        #define LXi_GRADIENTFILTER_MULTISAMPLE		2
        #define LXi_GRADIENTFILTER_ENVELOPE		3


        #define LXu_GRADIENTFILTER1	"ACCD7C33-D246-4FE5-ABA0-079F225BBB34"
        #define LXa_GRADIENTFILTER1	"gradientFilter"

/*
 * Gradient filters can be applied as non-destructive layers on top of a gradient
 * channel. Gradient Layers are a special item type that are not displayed in the
 * user interface.
 * Gradient layers are automatically generated from any Gradient Filter server that
 * marks itself as a layer, so should not be implemented directly. The filter must
 * present an ILxAttributes interface to allow channels on the item to be created.
 */

        #define LXsITYPE_GRADIENTLAYER		"gradientlayer"
        #define	LXsICHAN_GRADIENTLAYER_ENABLE	"enable"
        #define	LXsICHAN_GRADIENTLAYER_OBJ	"gradientFilter"

/*
 * To mark a gradient filter as a gradient layer, the following server tag must be
 * added to the server. The value of the tag does not matter.
 */

        #define	LXsSRV_GRADIENTFILTER_ADDLAYER	"gradientFilter.addLayer"

/*
 * Links from a gradient layer to a gradient channel are maintained using the
 * "gradientLinks" channel graph.
 */

        #define	LXsGRAPH_GRADIENTLINKS		"gradientLinks"

#endif
