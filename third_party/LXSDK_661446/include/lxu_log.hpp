/*
 * Plug-in SDK Header: C++ Services
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
 *
 * Helper class for posting warnings and catching errors and reporting
 * them to the I/O status log, with identification of the message poster.
 */
#ifndef LX_LOGUTIL_HPP
#define LX_LOGUTIL_HPP

#include <stdlib.h>
#include <string>
#include <sstream>
#include <lxresult.h>
#include <lxversion.h>
#include <lx_scripts.hpp>


class CLxLogMessage
{
    public:
        /*
         * Implement to return identity string (required).
         */
        virtual const char *	 GetFormat  () = 0;

        /*
         * Implement to return version string (required).
         */
        virtual const char *	 GetVersion () = 0;

        /*
         * Implement to return copyright notice.
         */
        virtual const char *	 GetCopyright ();

        /*
         * Call to add a three part message string with result code to log.
         */
        void			 Message (LxResult, const char *who, const char *what, const char *why);

        /*
         * Call to add an error message to the log.
         */
        void			 Error (const char *msg);

        /*
         * Call to add an error message to the log.
         */
        void			 Error (const std::string &msg)   { Error (msg.c_str ()); }

        /*
         * Call to add an info message to the log.
         */
        void			 Info (const char *msg);

        /*
         * Call to add an info message to the log.
         */
        void			 Info (const std::string &msg)    { Info (msg.c_str ()); }

        /*
         * Call to initialize the log and display initial message. Returns true
         * on success. Is also called automatically before adding first message.
         */
        bool			 Setup ();

        /*
         * Call to append a three part message string with result code to the
         * previous log entry.
         */
        void			 SubMessage (LxResult, const char *who, const char *what, const char *why);

        /*
         * Call to add an info message to the previous log entry.
         */
        void			 SubInfo (const char *msg);

        /*
         * Call to add an info message to the previous log entry.
         */
        void			 SubInfo (const std::string &msg) { SubInfo (msg.c_str ()); }

    //internal:
                 CLxLogMessage (const char *log = "io-status");
        virtual ~CLxLogMessage ();

        class pv_LogMessage	*pv;
};

//@skip

class CLxLuxologyLogMessage : public CLxLogMessage
{
    public:
        CLxLuxologyLogMessage (const char *log = "io-status") : CLxLogMessage (log) { }

        const char *	 GetVersion ()
        {
                if (_versionString.size () == 0)
                {
                        std::stringstream	 ss;
                        int			 versionMajor = 1, versionMinor = 0, versionSP = 0;
                
                        _pfmSvc.AppVersion (&versionMajor);
                        _pfmSvc.AppVersionMinor (&versionMinor);
                        _pfmSvc.AppVersionSP (&versionSP);
                
                        ss << versionMajor << "." << versionMinor << "v" << versionSP;

                        _versionString = ss.str ();
                }
        
                return _versionString.c_str ();
        }

        virtual const char *	 GetCopyright ()
        {
                return "Copyright " LXs_VERSION_YEAR " The Foundry Group LLC";
        }
        
    private:
        CLxUser_PlatformService	 _pfmSvc;
        std::string		 _versionString;
};

#endif	/* LX_LOGUTIL_HPP */

