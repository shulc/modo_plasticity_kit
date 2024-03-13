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
#ifndef LXUSER_log_HPP
#define LXUSER_log_HPP

#include <lxw_log.hpp>
/*
 * Includes for the user classes.
 */

#include <lx_value.hpp>



class CLxUser_Log : public CLxLoc_Log
{
        public:
        CLxUser_Log () {}
        CLxUser_Log (ILxUnknownID obj) : CLxLoc_Log (obj) {}

        /**
         * An alternate constructor for the subsystem allows the name to be specified. Or
         * later, of you prefer.
         */
        CLxUser_Log (
                const char		*name)
        {
                _init ();
                setByName (name);
        }
        
                bool
        setByName (
                const char		*name)
        {
                CLxLoc_LogService	 svc;
                LXtObjectID		 obj;
        
                if (LXx_FAIL (svc.SubSystemLookup (name, &obj)))
                        return false;
        
                return take (obj);
        }
        /**
         * For the most common case of a single text message we also have a user method
         * to make that easy.  Be sure to watch your string length due to the 1k buffer.
         * You can increase the size of this buffer if necessary.
         */
                bool
        Message (
                LxResult		 type,
                const char		*format,
                ...)
        {
                CLxLoc_LogService	 svc;
                CLxLoc_LogEntry		 entry;
                LXtObjectID		 obj;
                char			 buf[1024];
                va_list			 marker;
        
                va_start (marker, format);
                vsprintf (buf, format, marker);
                va_end (marker);
        
                if (LXx_FAIL (svc.CreateEntryMessage (type, buf, &obj)))
                        return false;
        
                if (!entry.take (obj))
                        return false;
        
                return LXx_OK (AddEntry (entry));
        }
        
                bool
        Info (
                const char		*text)
        {
                return Message (LXe_INFO, text);
        }
        
                bool
        Warn (
                const char		*text)
        {
                return Message (LXe_WARNING, text);
        }

};

class CLxUser_LogEntry : public CLxLoc_LogEntry
{
        public:
        CLxUser_LogEntry () {}
        CLxUser_LogEntry (ILxUnknownID obj) : CLxLoc_LogEntry (obj) {}

        /**
         * These are only needed to trigger the macros until there are some real ones
         * elsewhere.
         */
        

};

class CLxUser_LogInfoBlock : public CLxLoc_LogInfoBlock
{
        public:
        CLxUser_LogInfoBlock () {}
        CLxUser_LogInfoBlock (ILxUnknownID obj) : CLxLoc_LogInfoBlock (obj) {}



};

class CLxUser_LogService : public CLxLoc_LogService
{
        public:
        /**
         * The user class has methods for getting subsystems by index or by name.
         */
                bool
        GetSubSystem (
                unsigned		 index,
                CLxLoc_Log		&sys)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (SubSystemByIndex (index, &obj)))
                        return false;
        
                return sys.take (obj);
        }
        
                bool
        GetSubSystem (
                const char		*name,
                CLxLoc_Log		&sys)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (SubSystemLookup (name, &obj)))
                        return false;
        
                return sys.take (obj);
        }
        /**
         * After an entry has been created and filled in, it can be added to a subsystem
         * using ILxLog::AddEntry() or ILxLog::RollEntry().  Message entries can be added as
         * children of other message entries via ILxLogEntry::AddEntry(). Note that the
         * AddEntry() and RollEntry() methods do their own AddRef().  This allows the same
         * message to be added to multiple subsystems, but also means that you must release
         * the object you created when you are done with it.
         * The C++ user classes methods get new entries and stores them in our user wrappers.
         * These new COM objects are take()en by the CLxLoc_LogEntry(), and thus will
         * automatically be released when the C++ class's destructor is called; you do NOT
         * have to explicitly release their COM objects unless you explicitly AddRef()ed them.
         */
                bool
        NewEntry (
                LxResult		 type,
                const char		*message,
                CLxLoc_LogEntry		&entry)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateEntryMessage (type, message, &obj)))
                        return false;
        
                return entry.take (obj);
        }
        
                bool
        NewBlockEntry (
                LxResult		 type,
                const char		*name,
                CLxLoc_LogEntry		&entry)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateEntryInfoBlock (type, name, &obj)))
                        return false;
        
                return entry.take (obj);
        }
        
                bool
        NewPairEntry (
                LxResult		 type,
                CLxLoc_LogEntry		&entry)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateEntryPaired (type, &obj)))
                        return false;
        
                return entry.take (obj);
        }
        bool
        NewEntryFromMsgObj (
                CLxLoc_Message		&message,
                CLxLoc_LogEntry		&entry)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateEntryMessageFromMsgObj (message, &obj)))
                        return false;
        
                return entry.take (obj);
        }
        /**
         * Be careful when using DebugOut() and DebugOutSys(), as large strings will
         * overflow the 1k buffers.  You can increase the size of these buffers if
         * necessary.
         */
                bool
        DebugOut (
                unsigned int		 level,
                const char		*format,
                ...)
        {
                char			 buf[1024];
                va_list			 marker;
        
                va_start (marker, format);
                vsprintf (buf, format, marker);
                va_end (marker);
        
                return LXx_OK (DebugLogOutput (level, buf));
        }
        bool
        DebugOutSys (
                unsigned int             level,
                const char		*logSystem,
                const char		*format,
                ...)
        {
                char			 buf[1024];
                va_list			 marker;
        
                va_start (marker, format);
                vsprintf (buf, format, marker);
                va_end (marker);
        
                return LXx_OK (DebugLogOutputSys (level, logSystem, buf));
        }

};
#endif
