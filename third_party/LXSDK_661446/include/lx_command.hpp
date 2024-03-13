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
#ifndef LXUSER_command_HPP
#define LXUSER_command_HPP

#include <lxw_command.hpp>
/*
 * Includes for the user classes.
 */

#include <lx_message.hpp>



class CLxUser_Command : public CLxLoc_Command
{
        public:
        CLxUser_Command () {}
        CLxUser_Command (ILxUnknownID obj) : CLxLoc_Command (obj) {}

        bool
        GetMessage (
                CLxLoc_Message		 &msg )
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( Message( &obj ) ) )
                        return false;
        
                return msg.take( obj );
        }
        /**
         * These are only needed to trigger the macros until there are some real ones
         * elsewhere.
         */
        

};

class CLxUser_CommandEvent : public CLxLoc_CommandEvent
{
        public:
        CLxUser_CommandEvent () {}
        CLxUser_CommandEvent (ILxUnknownID obj) : CLxLoc_CommandEvent (obj) {}



};

class CLxUser_UIHints : public CLxLoc_UIHints
{
        public:
        CLxUser_UIHints () {}
        CLxUser_UIHints (ILxUnknownID obj) : CLxLoc_UIHints (obj) {}



};

class CLxUser_AttributesUI : public CLxLoc_AttributesUI
{
        public:
        CLxUser_AttributesUI () {}
        CLxUser_AttributesUI (ILxUnknownID obj) : CLxLoc_AttributesUI (obj) {}



};

class CLxUser_CommandService : public CLxLoc_CommandService
{
        public:
        bool
        GetProto (
                LXtCommandTag		  tag,
                const char		 *name,
                CLxLoc_Command		 &cmd )
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( Proto( tag, name, &obj ) ) )
                        return false;
        
                return cmd.take( obj );
        }
        bool
        GetProtoFromCommand (
                LXtCommandTag		  tag,
                const char		 *name,
                CLxLoc_Command		 &cmd )
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( Proto( tag, name, &obj ) ) )
                        return false;
        
                return cmd.take( obj );
        }
        LXtCommandTag
        GetTag (
                const char		 *name)
        {
                LXtCommandTag		  tag;
        
                if (LXx_FAIL (Lookup (name, &tag)))
                        return LXiCTAG_NULL;
                else
                        return tag;
        }
        bool
        NewCommand (
                CLxLoc_Command		 &cmd,
                LXtCommandTag		  tag)
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( Spawn( tag, 0, &obj ) ) )
                        return false;
        
                return cmd.take( obj );
        }
        
                bool
        NewCommand (
                CLxLoc_Command		 &cmd,
                const char		 *name)
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( Spawn( LXiCTAG_NULL, name, &obj ) ) )
                        return false;
        
                return cmd.take( obj );
        }
        bool
        NewCommandFromCommand (
                CLxLoc_Command		 &cmd,
                CLxLoc_Command		 &source)
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( SpawnFromCommand( source, &obj ) ) )
                        return false;
        
                return cmd.take( obj );
        }
        bool
        NewCommandFromString (
                CLxLoc_Command		 &cmd,
                const char		 *args,
                unsigned int		 &execFlags,
                int			 &queryArgIndex )
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( SpawnFromString( args, &execFlags, &queryArgIndex, &obj ) ) )
                        return false;
        
                return cmd.take( obj );
        }
        bool
        CommandGetToggleArgState (
                CLxLoc_Command		 &cmd,
                int			 &state)
        {
                return LXx_OK (GetToggleArgState( cmd, &state, 0 ));
        }
        
                bool
        CommandGetToggleArgState (
                CLxLoc_Command		 &cmd,
                CLxLoc_Value		 &value)
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( GetToggleArgState( cmd, 0, (void **)&obj ) ) )
                        return false;
        
                return value.take( obj );
        }
        
                bool
        CommandGetToggleArgState (
                CLxLoc_Command		 &cmd,
                int			 &state,
                CLxLoc_Value		 &value)
        {
                LXtObjectID		  obj;
        
                if (LXx_FAIL (GetToggleArgState( cmd, &state, &obj )))
                        return false;
        
                return value.take (obj);
        }
        bool
        NewCommandImplicitScript (
                const char		 *definition,
                CLxLoc_Command		 &cmd )
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( SpawnImplicitScript( definition, &obj ) ) )
                        return false;
        
                return cmd.take( obj );
        }
        bool
        QueryIndex (
                CLxLoc_Command		&cmd,
                unsigned int		 index,
                CLxLoc_ValueArray	&vaQuery)
        {
                LXtObjectID		 obj;
                LxResult		 rc;
        
                rc = Query (cmd, index, &obj);
                if (LXx_FAIL (rc))
                        return false;
        
                return vaQuery.take (obj);
        }
        LxResult
        CommandQueryArgString (
                CLxLoc_Command		 &cmd,
                unsigned int		  alertFlags,
                const char		 *args,
                CLxLoc_ValueArray	 &vaQuery,
                unsigned int		 &queryIndex,
                bool			  includesCmdName = false)
        {
                LXtObjectID		  obj;
                LxResult		  rc;
        
                rc = QueryArgString( cmd, alertFlags, args, &obj, &queryIndex, (int)includesCmdName );
                if( LXx_FAIL( rc ) )
                        return rc;
        
                return vaQuery.take( obj ) ? LXe_OK : LXe_FAILED;
        }
        bool
        NewQueryObject (
                CLxLoc_ValueArray	 &valueArray,
                const char		 *typeName )
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( CreateQueryObject( typeName, (void **)&obj ) ) )
                        return false;
        
                return valueArray.take( obj );
        }


};
#endif
