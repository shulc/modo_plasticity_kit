/*
 * Plug-in SDK Header: C++ User Classes
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
#ifndef LXUSER_envelope_HPP
#define LXUSER_envelope_HPP

#include <lxw_envelope.hpp>


class CLxUser_Envelope : public CLxLoc_Envelope
{
        public:
        CLxUser_Envelope () {}
        CLxUser_Envelope (ILxUnknownID obj) : CLxLoc_Envelope (obj) {}

        /**
         * The user class for envelopes adds a method to spawn an enumerator directly to
         * a keyframe user object.  It returns true for success.
         */
                bool
        GetKeyframe (
                CLxLoc_Keyframe		*key)
        {
                LXtObjectID		 obj;
        
                if (LXx_OK (Enumerator (&obj)))
                        return key->take (obj);
        
                clear ();
                return false;
        }
        /**
         * It also adds alternate methods for evaluating the envelope at a given time.
         */
                int
        IntValue (
                double			 time)
        {
                int			 val = 0;
        
                EvaluateI (time, &val);
                return val;
        }
        
                double
        Value (
                double			 time)
        {
                double			 val = 0.0;
        
                EvaluateF (time, &val);
                return val;
        }

};

class CLxUser_Keyframe : public CLxLoc_Keyframe
{
        public:
        CLxUser_Keyframe () {}
        CLxUser_Keyframe (ILxUnknownID obj) : CLxLoc_Keyframe (obj) {}

        /**
         * The keyframe user class has a special constructor that takes an envelope
         * user object, from which the enumerator is extracted.
         */
        CLxUser_Keyframe (
                CLxLoc_Envelope		&env)
        {
                LXtObjectID		 obj;
        
                _init ();
                if (env.test () && LXx_OK (env.Enumerator (&obj)))
                        take (obj);
        }
        /**
         * There is also a function to set the enumerator given any COM object.  The
         * method will clear the enumerator and return false if the object does not
         * present an ILxEnvelope interface.
         */
                bool
        fromEnvObject (
                ILxUnknownID		 obj)
        {
                CLxLoc_Envelope		 env (obj);
                LXtObjectID		 enObj;
        
                if (env.test () && LXx_OK (env.Enumerator (&enObj)))
                        return take (enObj);
        
                clear ();
                return false;
        }
        /**
         * Easier method for getting the time (or independent parameter) of the key.
         * This should be fine as long as you know there is a valid current key.
         */
                double
        Time ()
        {
                double			 time = 0.0;
        
                GetTime (&time);
                return time;
        }
        /**
         * Alternate methods for reading the value in the 90% case of an unbroken key.
         */
                LxResult
        Value (
                double			*val)
        {
                return GetValueF (val, LXiENVSIDE_IN);
        }
        
                double
        Value ()
        {
                double			 val = 0.0;
        
                GetValueF (&val, LXiENVSIDE_IN);
                return val;
        }
        
                LxResult
        Value (
                int			*val)
        {
                return GetValueI (val, LXiENVSIDE_IN);
        }
        
                int
        IntValue ()
        {
                int			 val = 0;
        
                GetValueI (&val, LXiENVSIDE_IN);
                return val;
        }
        /**
         * The breaking and controlling side can be read independently.
         */
                unsigned int
        Broken ()
        {
                unsigned int		 flags = 0;
        
                GetBroken (&flags, 0);
                return flags;
        }
        
                unsigned int
        ActiveSide ()
        {
                unsigned int		 flags, side = LXiENVSIDE_BOTH;
        
                GetBroken (&flags, &side);
                return side;
        }
        /**
         * The other key attributes can be read without error checking, although sidedness
         * tends to be important for these so that is provided.
         */
                double
        Slope (
                unsigned int		 side)
        {
                double			 val = 0.0;
        
                GetSlope (&val, side);
                return val;
        }
        
                LXtSlopeType
        SlopeType (
                unsigned int		 side)
        {
                LXtSlopeType		 val = LXiSLOPE_DIRECT;
        
                GetSlopeType (&val, 0, side);
                return val;
        }
        
                bool
        Weighted (
                unsigned int		 side)
        {
                LXtSlopeType		 val;
                unsigned int		 test;
        
                GetSlopeType (&val, &test, side);
                return (test != 0);
        }
        
                double
        Weight (
                unsigned int		 side)
        {
                double			 val = 0.0;
        
                GetWeight (&val, side);
                return val;
        }

};

class CLxUser_GradientFilter : public CLxLoc_GradientFilter
{
        public:
        CLxUser_GradientFilter () {}
        CLxUser_GradientFilter (ILxUnknownID obj) : CLxLoc_GradientFilter (obj) {}



};
#endif
