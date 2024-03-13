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
#ifndef LXUSER_scripts_HPP
#define LXUSER_scripts_HPP

#include <lxw_scripts.hpp>

        #include <string>
#include <lx_value.hpp>



class CLxUser_UserValue : public CLxLoc_UserValue
{
        public:
        CLxUser_UserValue () {}
        CLxUser_UserValue (ILxUnknownID obj) : CLxLoc_UserValue (obj) {}

        std::string
        Name ()
        {
                const char *name;
                CLxLoc_UserValue::Name (&name);
                return std::string(name);
        }
        
                std::string
        UserName ()
        {
                const char *username;
                CLxLoc_UserValue::UserName (&username);
                return std::string(username);
        }
        std::string
        TypeName ()
        {
                const char *tname;
                CLxLoc_UserValue::TypeName (&tname);
                return std::string(tname);
        }
        std::string
        List ()
        {
                const char *list;
                CLxLoc_UserValue::List (&list);
                return std::string(list);
        }
        
                std::string
        ListNames ()
        {
                const char *listNames;
                CLxLoc_UserValue::ListNames (&listNames);
                return std::string(listNames);
        }
        
                std::string
        ArgType ()
        {
                const char *argType;
                CLxLoc_UserValue::ArgType (&argType);
                return std::string(argType);
        }
        std::string
        Action ()
        {
                const char *action;
                CLxLoc_UserValue::Action (&action);
                return std::string(action);
        }
        std::string
        DialogUserName ()
        {
                const char *username;
                CLxLoc_UserValue::DialogUserName (&username);
                return std::string(username);
        }
        std::string
        ValuePresetCookie ()
        {
                const char *cookie;
                CLxLoc_UserValue::ValuePresetCookie (&cookie);
                return std::string(cookie);
        }
        std::string
        EnableCommand ()
        {
                const char *command;
                CLxLoc_UserValue::EnableCommand (&command);
                return std::string(command);
        }
        std::string
        Notifier ()
        {
                const char *notifier;
                CLxLoc_UserValue::Notifier (&notifier);
                return std::string(notifier);
        }

};

class CLxUser_Kit : public CLxLoc_Kit
{
        public:
        CLxUser_Kit () {}
        CLxUser_Kit (ILxUnknownID obj) : CLxLoc_Kit (obj) {}

        std::string
        Name ()
        {
                const char *name = NULL;
        
                if(LXx_OK(CLxLoc_Kit::Name (&name)))
                        return std::string(name);
        
                return std::string();
        }
        std::string
        Version ()
        {
                const char *version = NULL;
        
                if(LXx_OK(CLxLoc_Kit::Version (&version)))
                        return std::string(version);
        
                return std::string();
        }

};

class CLxUser_SessionListener : public CLxLoc_SessionListener
{
        public:
        CLxUser_SessionListener () {}
        CLxUser_SessionListener (ILxUnknownID obj) : CLxLoc_SessionListener (obj) {}

        /**
         * C++ user class.
         */
        

};

class CLxUser_UserValueListener : public CLxLoc_UserValueListener
{
        public:
        CLxUser_UserValueListener () {}
        CLxUser_UserValueListener (ILxUnknownID obj) : CLxLoc_UserValueListener (obj) {}

        /**
         * C++ user class.
         */
        

};

class CLxUser_ScriptManager : public CLxLoc_ScriptManager
{
        public:
        CLxUser_ScriptManager () {}
        CLxUser_ScriptManager (ILxUnknownID obj) : CLxLoc_ScriptManager (obj) {}



};

class CLxUser_LineInterpreter : public CLxLoc_LineInterpreter
{
        public:
        CLxUser_LineInterpreter () {}
        CLxUser_LineInterpreter (ILxUnknownID obj) : CLxLoc_LineInterpreter (obj) {}



};

class CLxUser_LineExecution : public CLxLoc_LineExecution
{
        public:
        CLxUser_LineExecution () {}
        CLxUser_LineExecution (ILxUnknownID obj) : CLxLoc_LineExecution (obj) {}



};

class CLxUser_ScriptSysService : public CLxLoc_ScriptSysService
{
        public:
        bool
        UserValueByIndex (
                int			 index,
                CLxUser_UserValue	&val)
        {
                LXtObjectID		 obj;
        
                if( LXx_FAIL( CLxLoc_ScriptSysService::UserValueByIndex( index, &obj ) ) )
                        return false;
        
                return val.take( obj );
        }
        
                bool
        UserValueLookup (
                const char		*name,
                CLxUser_UserValue	&val)
        {
                LXtObjectID		 obj;
        
                if( LXx_FAIL( CLxLoc_ScriptSysService::UserValueLookup( name, &obj ) ) )
                        return false;
        
                return val.take( obj );
        }

};

class CLxUser_PlatformService : public CLxLoc_PlatformService
{
        public:
        std::string
        LicensedTo ()
        {
                const char *licensee;
                CLxLoc_PlatformService::LicensedTo (&licensee);
                return std::string(licensee);
        }
        std::string
        SerialNumber ()
        {
                const char *serial;
                CLxLoc_PlatformService::SerialNumber (&serial);
                return std::string(serial);
        }
        std::string
        AppName ()
        {
                const char *appName;
                CLxLoc_PlatformService::AppName (&appName);
                return std::string(appName);
        }
        bool
        IsHeadless ()
        {
                return (CLxLoc_PlatformService::IsHeadless () == LXe_TRUE);
        }
        std::string
        OSName ()
        {
                const char *osName;
                CLxLoc_PlatformService::OSName (&osName);
                return std::string(osName);
        }
        std::string
        OSVersion ()
        {
                const char *osVersion;
                CLxLoc_PlatformService::OSVersion (&osVersion);
                return std::string(osVersion);
        }
        const char *
        GetPath (
                int			 index)
        {
                const char		*path = 0;
        
                PathByIndex (index, &path);
                return path;
        }
        const char *
        GetPathName (
                int			 index)
        {
                const char		*path = 0;
        
                PathNameByIndex (index, &path);
                return path;
        }
        const char *
        GetImportPath (
                int			 index)
        {
                const char		*path = NULL;
        
                ImportPathByIndex (index, &path);
                return path;
        }
        bool
        IsApp64Bit ()
        {
                return (CLxLoc_PlatformService::IsApp64Bit () == LXe_TRUE);
        }
        std::string
        AppUsername ()
        {
                const char *appName;
                CLxLoc_PlatformService::AppUsername (&appName);
                return std::string(appName);
        }

};
#endif
