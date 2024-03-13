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
#ifndef LXUSER_message_HPP
#define LXUSER_message_HPP

#include <lxw_message.hpp>
/*
 * Includes for the user classes.
 */

#include <lx_value.hpp>


#include <lxu_getstring.hpp>
        #include <stdio.h>



class CLxUser_MessageService : public CLxLoc_MessageService
{
        public:
        bool
        NewMessage (
                CLxLoc_Message		 &msg)
        {
                LXtObjectID		  obj;
                LxResult		  rc;
        
                rc = Allocate( &obj );
                if( LXx_FAIL( rc ) )
                        return false;
        
                return msg.take( obj );
        }
        bool
        DuplicateMessage (
                CLxLoc_Message		 &msg,
                CLxLoc_Message		 &source)
        {
                LxResult		  rc;
                LXtObjectID		  obj;
        
                rc = Duplicate( source, &obj );
                if( !LXx_FAIL( rc ) )
                        return false;
        
                return msg.take( obj );
        }
        LxResult
        GetText (
                CLxLoc_Message		&msg,
                char			*buf,
                unsigned		 len)
        {
                return MessageText( msg, buf, len );
        }
        /**
         * This is a safe string "get" using a dummy class to act as callback for the safe
         * string "read" template.
         */
        class Tmp_Sgs {
            public:
                CLxLoc_MessageService	*srv;
                ILxUnknownID		 msg;
        
                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return srv->MessageText (msg, buf, len);
                }
        };
        
                LxResult
        GetText (
                CLxLoc_Message		&msg,
                std::string		&text)
        {
                Tmp_Sgs				 tmp;
        
                CLxSafeGetString<Tmp_Sgs>	 sgs;
        
                tmp.srv = this;
                tmp.msg = msg;
                return sgs.GetString (tmp, text);
        }
        /**
         * The special message table for result codes can be accessed using LxResutl values
         * as keys.
         */
                std::string
        ResultMessage (
                LxResult		 rc)
        {
                const char		*msg;
                char			 buf[16];
        
                sprintf (buf, "%08x", rc);
                rc = RawText ("lxresult", buf, &msg);
                return std::string (LXx_OK(rc) ? msg : "");
        }

};
#endif
