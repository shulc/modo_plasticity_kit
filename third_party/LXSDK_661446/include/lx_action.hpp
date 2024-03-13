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
#ifndef LXUSER_action_HPP
#define LXUSER_action_HPP

#include <lxw_action.hpp>

#include <lx_item.hpp>
#include <lx_envelope.hpp>
#include <lx_value.hpp>
        #include <string>



class CLxUser_ChannelRead : public CLxLoc_ChannelRead
{
        public:
        CLxUser_ChannelRead () {}
        CLxUser_ChannelRead (ILxUnknownID obj) : CLxLoc_ChannelRead (obj) {}

        int
        IValue (
                ILxUnknownID		 item,
                unsigned		 channel)
        {
                int			 value = 0;
        
                Integer (item, channel, &value);
                return value;
        }
        
                bool
        Encoded (
                CLxUser_Item		&item,
                unsigned		 channel,
                std::string		&result)
        {
                CLxUser_ValueService	 valueSvc;
                const LXtTextValueHint	*hints;
                int			 value;
        
                return (    LXx_OK (Integer (item, channel, &value))
                        &&  LXx_OK (item.ChannelIntHint (channel, &hints))
                        &&  valueSvc.EncodeHint (value, hints, result) );
        }
        
                double
        FValue (
                ILxUnknownID		 item,
                unsigned		 channel)
        {
                double			 value = 0.0;
        
                Double (item, channel, &value);
                return value;
        }
        
                bool
        GetString (
                ILxUnknownID		 item,
                unsigned		 channel,
                std::string		&result)
        {
                const char		*str;
        
                if (LXx_FAIL (String (item, channel, &str)))
                        return false;
        
                result = str;
                return true;
        }
        
                bool
        Object (
                ILxUnknownID		 item,
                unsigned		 channel,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ValueObj (item, channel, &obj)))
                        return false;
        
                return loc.take (obj);
        }
        
                bool
        GetEnv (
                ILxUnknownID		 item,
                unsigned		 channel,
                CLxUser_Envelope	&env)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Envelope (item, channel, &obj)))
                        return false;
        
                return env.take (obj);
        }
        
                bool
        GetBake (
                ILxUnknownID		 item,
                unsigned		 channel,
                double			*firstSample,
                double			*spsRate,
                CLxUser_ValueArray	&array)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (BakedSamples (item, channel, firstSample, spsRate, &obj)))
                        return false;
        
                return array.take (obj);
        }
        /**
         * Same again, this time taking the channel name instead of the index.
         */
                int
        IValue (
                CLxUser_Item		&item,
                const char 		*channel)
        {
                unsigned int		 index;
        
                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return 0;
        
                return IValue (item, index);
        }
        
                bool
        Encoded (
                CLxUser_Item		&item,
                const char 		*channel,
                std::string		&result)
        {
                unsigned int		 index;
        
                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;
        
                return Encoded (item, index, result);
        }
        
                double
        FValue (
                CLxUser_Item		&item,
                const char 		*channel)
        {
                unsigned int		 index;
        
                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return 0.0;
        
                return FValue (item, index);
        }
        
                bool
        GetString (
                CLxUser_Item		&item,
                const char 		*channel,
                std::string		&result)
        {
                unsigned int		 index;
        
                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;
        
                return GetString (item, index, result);
        }
        
                bool
        Object (
                const CLxUser_Item	&item,
                const char 		*channel,
                CLxLocalizedObject	&loc)
        {
                unsigned int		 index;
        
                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;
        
                return Object (reinterpret_cast<ILxUnknownID>(item.m_loc), index, loc);
        }
        
                bool
        GetEnv (
                CLxUser_Item		&item,
                const char 		*channel,
                CLxUser_Envelope	&env)
        {
                unsigned int		 index;
        
                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;
        
                return GetEnv (item, index, env);
        }
        /**
         * If the channel is of the OBJREF type then it's actually a container for
         * some other object. These methods allow direct access to the contents.
         */
                LxResult
        GetRef (
                ILxUnknownID		 item,
                unsigned		 channel,
                void		       **ppvObj)
        {
                CLxUser_ValueReference	 ref;
                LxResult		 rc;
                LXtObjectID		 obj;
        
                rc = ValueObj (item, channel, &obj);
                if (LXx_FAIL (rc))
                        return rc;
        
                if (!ref.take (obj))
                        return LXe_NOTFOUND;
        
                return ref.GetObject (ppvObj);
        }
        
                LxResult
        GetRef (
                CLxUser_Item		&item,
                const char		*channel,
                void		       **ppvObj)
        {
                unsigned int		 index;
                LxResult		 rc;
        
                rc = item.ChannelLookup (channel, &index);
                if (LXx_FAIL (rc))
                        return rc;
        
                return GetRef (item, index, ppvObj);
        }
        
                template <class T>
                bool
        GetRef (
                CLxUser_Item		&item,
                T			 channel,
                CLxLocalizedObject	&loc)
        {
                CLxUser_ValueReference	 ref;
        
                if (!Object (item, channel, ref))
                        return false;
        
                return ref.GetObject (loc);
        }
        /**
         * The general Get() method takes the value as writable argument.
         */
                bool
        Get (
                ILxUnknownID		 item,
                unsigned		 channel,
                int			*value)
        {
                return LXx_OK (Integer (item, channel, value));
        }
        
                bool
        Get (
                ILxUnknownID		 item,
                unsigned		 channel,
                unsigned		*value)
        {
                int			 ival;
                bool			 res;
        
                res = Get (item, channel, &ival);
                if (ival < 0)
                        return false;
        
                if (res)
                        *value = ival;
        
                return res;
        }
        
                bool
        Get (
                ILxUnknownID		 item,
                unsigned		 channel,
                double			*value)
        {
                return LXx_OK (Double (item, channel, value));
        }
        
                bool
        Get (
                ILxUnknownID		 item,
                unsigned		 channel,
                float			*value)
        {
                double			 dval;
                bool			 res;
        
                res = Get (item, channel, &dval);
                if (res)
                        *value = dval;
        
                return res;
        }
        
                bool
        Get (
                ILxUnknownID		 item,
                unsigned		 channel,
                const char	       **value)
        {
                return LXx_OK (String (item, channel, value));
        }
        
                bool
        Get (
                ILxUnknownID		 item,
                unsigned		 channel,
                std::string		&value)
        {
                const char		*sval;
                bool			 res;
        
                res = Get (item, channel, &sval);
                if (res)
                        value = sval;
        
                return res;
        }
        
                bool
        Get (
                CLxUser_Item		&item,
                const char		*channel,
                std::string		&value)
        {
                unsigned int		 index;
        
                return LXx_OK (item.ChannelLookup (channel, &index))
                            && Get ((ILxUnknownID) item, index, value);
        }
        
                template <class T>
                bool
        Get (
                CLxUser_Item		&item,
                const char		*channel,
                T			 value)
        {
                unsigned int		 index;
        
                return LXx_OK (item.ChannelLookup (channel, &index))
                            && Get ((ILxUnknownID) item, index, value);
        }
        /**
         * Some additional ways to init the wrapper. Commonly clients have a scene or an
         * item and they want to read channel values.
         */
                bool
        from (
                CLxUser_Scene		&scene)
        {
                LXtObjectID		 obj;
        
                return LXx_OK (scene.Channels (LXs_ACTIONLAYER_EDIT, 0.0, &obj))
                   &&  take (obj);
        }
        
                bool
        from (
                CLxUser_Scene		&scene,
                double			 time)
        {
                LXtObjectID		 obj;
        
                return LXx_OK (scene.Channels (0, time, &obj))
                   &&  take (obj);
        }
        
                bool
        from (
                CLxUser_Item		&item)
        {
                LXtObjectID		 obj;
                CLxUser_Scene		 scene;
        
                return LXx_OK (item.Context (&obj))
                   &&  scene.take (obj)
                   &&  from (scene);
        }
        
                bool
        from (
                CLxUser_Item		&item,
                double			 time)
        {
                LXtObjectID		 obj;
                CLxUser_Scene		 scene;
        
                return LXx_OK (item.Context (&obj))
                   &&  scene.take (obj)
                   &&  from (scene, time);
        }

};

class CLxUser_ChannelWrite : public CLxLoc_ChannelWrite
{
        public:
        CLxUser_ChannelWrite () {}
        CLxUser_ChannelWrite (ILxUnknownID obj) : CLxLoc_ChannelWrite (obj) {}

        /**
         * Nicer methods allow us to use localized objects and use argument types to
         * handle the different intrinsic type cases.
         */
                bool
        Set (
                ILxUnknownID		 item,
                unsigned		 channel,
                int			 value)
        {
                return LXx_OK (Integer (item, channel, value));
        }
        
                bool
        Set (
                ILxUnknownID		 item,
                unsigned		 channel,
                unsigned		 value)
        {
                return LXx_OK (Integer (item, channel, value));
        }
        
                bool
        Set (
                ILxUnknownID		 item,
                unsigned		 channel,
                double			 value)
        {
                return LXx_OK (Double (item, channel, value));
        }
        
                bool
        Set (
                ILxUnknownID		 item,
                unsigned		 channel,
                const char		*value)
        {
                return LXx_OK (String (item, channel, value));
        }
        
                bool
        Set (
                ILxUnknownID		 item,
                unsigned		 channel,
                std::string		&value)
        {
                return LXx_OK (String (item, channel, value.c_str()));
        }
        /**
         * Setting an encoded int takes a string as argument and converts that to an
         * int. Requires the item wrapper.
         */
                bool
        SetEncoded (
                CLxUser_Item		&item,
                unsigned		 channel,
                const char		*encoded)
        {
                CLxUser_ValueService	 valueSvc;
                const LXtTextValueHint	*hints;
                int			 value;
        
                if (  LXx_FAIL (item.ChannelIntHint (channel, &hints))
                  ||  LXx_FAIL (valueSvc.TextHintDecode (encoded, hints, &value)) )
                        return false;
        
                return LXx_OK (Integer (item, channel, value));
        }
        bool
        Object (
                ILxUnknownID		 item,
                unsigned		 channel,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ValueObj (item, channel, &obj)))
                        return false;
        
                return loc.take (obj);
        }
        
                bool
        AddEnv (
                ILxUnknownID		 item,
                unsigned		 channel,
                CLxUser_Envelope		&env)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Envelope (item, channel, &obj)))
                        return false;
        
                return env.take (obj);
        }
        
                bool
        WriteBake (
                ILxUnknownID		 item,
                unsigned		 channel,
                double			 firstSample,
                double			 spsRate,
                CLxUser_ValueArray	&array)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (BakeSamples (item, channel, firstSample, spsRate, &obj)))
                        return false;
        
                return array.take (obj);
        }
        /**
         * These classes permit access using a channel string rather than index, although
         * they require an item wrapper.
         */
                template <class T>
                bool
        Set (
                CLxUser_Item		&item,
                const char		*channel,
                T			 value)
        {
                unsigned int		 index;
        
                return LXx_OK (item.ChannelLookup (channel, &index))
                            && Set ((ILxUnknownID) item, index, value);
        }
        
                bool
        SetEncoded (
                CLxUser_Item		&item,
                const char		*channel,
                const char		*encoded)
        {
                unsigned int		 index;
        
                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;
        
                return SetEncoded (item, index, encoded);
        }
        
                bool
        Object (
                CLxUser_Item		&item,
                const char		*channel,
                CLxLocalizedObject	&loc)
        {
                unsigned int		 index;
        
                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;
        
                return Object (item, index, loc);
        }
        
                bool
        AddEnv (
                CLxUser_Item		&item,
                const char		*channel,
                CLxUser_Envelope	&env)
        {
                unsigned int		 index;
        
                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;
        
                return AddEnv (item, index, env);
        }
        /**
         * Directly set the contents of an OBJREF channel.
         */
                bool
        SetRef (
                ILxUnknownID		 item,
                unsigned		 channel,
                ILxUnknownID		 obj)
        {
                CLxUser_ValueReference	 ref;
        
                if (!Object (item, channel, ref))
                        return false;
        
                return LXx_OK (ref.SetObject (obj));
        }
        
                bool
        SetRef (
                CLxUser_Item		&item,
                const char		*channel,
                ILxUnknownID		 obj)
        {
                unsigned int		 index;
        
                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;
        
                return SetRef (item, index, obj);
        }
        /**
         * User class methods to initialize a write context from scene or item.
         */
                bool
        from (
                CLxUser_Scene		&scene,
                double			 time = 0.0)
        {
                LXtObjectID		 obj;
        
                return LXx_OK (scene.Channels (LXs_ACTIONLAYER_EDIT, time, &obj))
                   &&  take (obj);
        }
        
                bool
        from (
                CLxUser_Item		&item,
                double			 time = 0.0)
        {
                LXtObjectID		 obj;
                CLxUser_Scene		 scene;
        
                return LXx_OK (item.Context (&obj))
                   &&  scene.take (obj)
                   &&  from (scene, time);
        }
        
                bool
        setupFrom (
                CLxUser_Scene		&scene)
        {
                LXtObjectID		 obj;
        
                return LXx_OK (scene.Channels (LXs_ACTIONLAYER_SETUP, 0.0, &obj))
                   &&  take (obj);
        }
        
                bool
        setupFrom (
                CLxUser_Item		&item)
        {
                LXtObjectID		 obj;
                CLxUser_Scene		 scene;
        
                return LXx_OK (item.Context (&obj))
                   &&  scene.take (obj)
                   &&  setupFrom (scene);
        }

};

class CLxUser_Modifier : public CLxLoc_Modifier
{
        public:
        CLxUser_Modifier () {}
        CLxUser_Modifier (ILxUnknownID obj) : CLxLoc_Modifier (obj) {}



};

class CLxUser_Evaluation : public CLxLoc_Evaluation
{
        public:
        CLxUser_Evaluation () {}
        CLxUser_Evaluation (ILxUnknownID obj) : CLxLoc_Evaluation (obj) {}

        unsigned
        AddChan (
                ILxUnknownID		 item,
                unsigned		 index,
                unsigned		 type = LXfECHAN_READ)
        {
                LxResult		 rc;
                unsigned		 idx;
        
                rc = AddChannel (item, index, type, &idx);
                if (LXx_FAIL (rc))
                        throw (rc);
        
                return idx;
        }
        
                unsigned
        AddChan (
                ILxUnknownID		 item,
                const char		*name,
                unsigned		 type = LXfECHAN_READ)
        {
                LxResult		 rc;
                unsigned		 idx;
        
                rc = AddChannelName (item, name, type, &idx);
                if (LXx_FAIL (rc))
                        throw (rc);
        
                return idx;
        }
        
                unsigned
        AddTime ()
        {
                LxResult		 rc;
                unsigned		 idx;
        
                rc = ReadTime (&idx);
                if (LXx_FAIL (rc))
                        throw (rc);
        
                return idx;
        }
        /**
         * User method returns a channel write object.
         */
                bool
        Alternate (
                CLxUser_ChannelWrite	&cw)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (SetAlternate (&obj)))
                        return false;
        
                return cw.take (obj);
        }
        /**
         * The user method returns the fraction directly or -1 for errors.
         */
                double
        GetBaked (
                unsigned		 index,
                bool			 after,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
                double			 f;
        
                if (LXx_FAIL (GetBakedSample (index, (after ? 1 : 0), &f, &obj)))
                        return -1.0;
        
                return (loc.take (obj) ? f : -1.0);
        }

};
#endif
