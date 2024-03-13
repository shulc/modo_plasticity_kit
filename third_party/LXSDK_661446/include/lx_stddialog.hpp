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
#ifndef LXUSER_stddialog_HPP
#define LXUSER_stddialog_HPP

#include <lxw_stddialog.hpp>

#include <lxw_value.hpp>
#include <lxw_io.hpp>
        #include <string>



class CLxUser_StdDialogService : public CLxLoc_StdDialogService
{
        public:
        bool
        MonitorAllocate (
                const std::string	&title,
                CLxLoc_Monitor		&monitor)
        {
                LXtObjectID		 obj;
                LxResult		 rc;
        
                rc = CLxLoc_StdDialogService::MonitorAllocate (title.c_str (), &obj);
                if (LXx_FAIL (rc))
                        return false;
        
                return monitor.take (obj);
        }
        bool
        MessageAllocate (
                CLxLoc_Message		&message)
        {
                LXtObjectID		 obj;
                LxResult		 rc;
        
                rc = CLxLoc_StdDialogService::MessageAllocate (&obj);
                if (LXx_FAIL (rc))
                        return false;
        
                return message.take (obj);
        }
        bool
        AsyncMonitorAllocate (
                const std::string	&system,
                const std::string	&title,
                CLxLoc_Monitor		&monitor)
        {
                LXtObjectID		 obj;
                LxResult		 rc;
        
                rc = CLxLoc_StdDialogService::AsyncMonitorAllocate (system.c_str (), title.c_str (), &obj);
                if (LXx_FAIL (rc))
                        return false;
        
                return monitor.take (obj);
        }
        
                bool
        AsyncMonitorSubAllocate (
                LXtObjectID		 parent,
                const std::string	&title,
                CLxLoc_Monitor		&monitor)
        {
                LXtObjectID		 obj;
                LxResult		 rc;
        
                rc = CLxLoc_StdDialogService::AsyncMonitorSubAllocate ((ILxUnknownID)parent, title.c_str (), &obj);
                if (LXx_FAIL (rc))
                        return false;
        
                return monitor.take (obj);
        }
        bool
        AsyncMonitorAllocateWithoutAbort (
                const std::string	&system,
                const std::string	&title,
                CLxLoc_Monitor		&monitor)
        {
                LXtObjectID		 obj;
                LxResult		 rc;
        
                rc = CLxLoc_StdDialogService::AsyncMonitorAllocateWithoutAbort (system.c_str (), title.c_str (), &obj);
                if (LXx_FAIL (rc))
                        return false;
        
                return monitor.take (obj);
        }

};
#endif
