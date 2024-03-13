/*
 * LX force module
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
#ifndef LX_force_H
#define LX_force_H

typedef struct vt_ILxForce ** ILxForceID;

#include <lxvalue.h>



/*
 * Get flag bits describing the force. A force can require velocity or mass
 * as an input, and can optionally generate angular forces.
 * 
 * These single point methods are optimized for computing a force for a single
 * element. Any given force only needs to implement one of these based on the
 * flags above. The client is required to call the right API.
 * 
 * Computing forces over multiple elements is more efficiently done using runs
 * which are arrays of floats. Anything not requested by the flags will be unset.
 * Angular forces can only be computed in runs.
 */
typedef struct vt_ILxForce {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned,
Flags) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Force) (
        LXtObjectID		 self,
        const LXtFVector	 pos,
        LXtFVector		 force);

        LXxMETHOD(  LxResult,
ForceV) (
        LXtObjectID		 self,
        const LXtFVector	 pos,
        const LXtFVector	 velocity,
        LXtFVector		 force);

        LXxMETHOD(  LxResult,
ForceM) (
        LXtObjectID		 self,
        const LXtFVector	 pos,
        float			 mass,
        LXtFVector		 force);

        LXxMETHOD(  LxResult,
ForceVM) (
        LXtObjectID		 self,
        const LXtFVector	 pos,
        const LXtFVector	 velocity,
        float			 mass,
        LXtFVector		 force);
        LXxMETHOD(  LxResult,
ForceRun) (
        LXtObjectID		 self,
        const float	       **pos,
        const float	       **velocity,
        const float		*mass,
        float		       **force,
        unsigned		 num);

        LXxMETHOD(  LxResult,
ForceRunAng) (
        LXtObjectID		 self,
        const float	       **pos,
        const float	       **velocity,
        const float	       **angVel,
        const float		*mass,
        float		       **force,
        float		       **torque,
        unsigned		 num);
} ILxForce;

/*
 * Force items all derive from a common type, a type of locator. Being a
 * locator type means all forces have a location, which seems fairly
 * reasonable. All forces implicitly support enable/disable, strength
 * and inversion.
 */

        #define LXsITYPE_FORCE			"force.root"

        #define LXsICHAN_FORCE_FORCE		"forceObj"
        #define LXsICHAN_FORCE_FILTER		"filterObj"
        #define LXsICHAN_FORCE_ENABLE		"enable"
        #define LXsICHAN_FORCE_STRENGTH		"strength"
        #define LXsICHAN_FORCE_TORQUE		"torque"
        #define LXsICHAN_FORCE_INVERT		"invert"

/*
 * An item inheriting from this type writes a basic force object to the
 * 'forceObj' channel. This is then overridden by the core implementation
 * for the default behaviors. This includes a falloff on the force effect
 * which can be set with a graph link.
 */

        #define	LXsGRAPH_FORCEFALLOFF	"forceFalloff"

/*
 * The force interface allows clients to compute forces from positions
 * and other element features.
 */

        #define LXu_FORCE		"A712DF74-0DD4-4D8C-87B7-CDF66D4E6848"
        // [export]  ILxForce force
        // [local]   ILxForce
        // [default] ILxForce:Flags = 0


        #define LXfFORCE_VELOCITY	 0x01
        #define LXfFORCE_MASS		 0x02
        #define LXfFORCE_ANGULAR	 0x04

#endif
