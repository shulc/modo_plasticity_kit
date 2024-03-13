/*
 * Plug-in SDK Header: Common Utility
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
 * Logging utility class.
 */

/*
 * Suppress warnings for deprecated functions.
 */
#ifdef _MSC_VER
        #define _CRT_SECURE_NO_WARNINGS 1
        #define _CRT_SECURE_NO_DEPRECATE 1
        #pragma warning(disable: 4996)
#endif

#include <lxu_log.hpp>
#include <lx_log.hpp>
#include <lx_message.hpp>
#include <lx_thread.hpp>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


/*
 * CLxLogMessage : Implementation
 *
 * We maintain the service as a member for speed. We attach to the subsystem
 * lazily to get the best chance for it to exist.
 */
class pv_LogMessage {
    public:
        const char		*name;
        string			 warn, info;
        CLxUser_LogService	 svLog;
        CLxUser_MessageService   svMsg;
        CLxUser_Log		 log;
        CLxUser_LogEntry	 lastRoot;

        const char *		 GetMessage (string &, int, const char *);
};

        const char *
pv_LogMessage::GetMessage (
        string			&cache,
        int			 msgIdx,
        const char		*raw)
{
        if (cache.empty ()) {
                CLxUser_ThreadService	 ts;

                if (ts.IsMainThread ()) {
                        CLxUser_Message	 message;

                        svMsg.NewMessage (message);
                        message.SetMessage ("common", 0, msgIdx);

                        svMsg.GetText (message, cache);
                } else
                        cache = raw;
        }

        return cache.c_str ();
}


CLxLogMessage::CLxLogMessage (
        const char		*name)
{
        pv = new pv_LogMessage;
        pv->name = name;
}

CLxLogMessage::~CLxLogMessage ()
{
        delete pv;
}

        const char *
CLxLogMessage::GetCopyright ()
{
        return 0;
}

        bool
CLxLogMessage::Setup ()
{
        if (pv->log.test ())
                return true;

        pv->svLog.set ();
        pv->svMsg.set ();
        pv->log.setByName (pv->name);
        if (!pv->log.test ())
                return false;

        return true;
}

        void
CLxLogMessage::Message (
        LxResult		 code,
        const char		*who,
        const char		*what,
        const char		*why)
{
        CLxUser_LogEntry	 main, sub;
        string			 str;

        if (!Setup ())
                return;

        str  = who;
        if (what && *what) {
                str += ": ";
                str += what;
        }

        if (pv->svLog.NewEntry (code, str.c_str (), main) &&
            pv->svLog.NewEntry (LXe_INFO, why, sub) &&
            LXx_OK (main.AddEntry (sub)))
        {
                pv->log.AddEntry (main);
                pv->lastRoot.set (main);
        }
}

        void
CLxLogMessage::SubMessage (
        LxResult		 code,
        const char		*who,
        const char		*what,
        const char		*why)
{
        if (!pv->lastRoot.test ())
                return Message (code, who, what, why);

        CLxUser_LogEntry	 sub;

        if (pv->svLog.NewEntry (LXe_INFO, why, sub))
            pv->lastRoot.AddEntry (sub);
}

static const int MSG_LOADER_SAVER_ERROR	= 2401;
static const int MSG_LOADER_SAVER_INFO	= 2402;

        void
CLxLogMessage::Error (
        const char		*msg)
{
        if (!Setup ())
                return;

        Message (LXe_WARNING,
                 GetFormat (),
                 pv->GetMessage (pv->warn, MSG_LOADER_SAVER_ERROR, "load/save error"),
                 msg);
}

        void
CLxLogMessage::Info (
        const char		*msg)
{
        if (!Setup ())
                return;

        Message (LXe_INFO,
                 GetFormat (),
                 pv->GetMessage (pv->info, MSG_LOADER_SAVER_INFO, "load/save"),
                 msg);
}

        void
CLxLogMessage::SubInfo (
        const char		*msg)
{
        if (! pv->lastRoot.test ())
                return Info (msg);

        return SubMessage (LXe_INFO, NULL, NULL, msg);
}


