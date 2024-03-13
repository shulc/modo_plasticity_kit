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
#ifndef LXUSER_file_HPP
#define LXUSER_file_HPP

#include <lxw_file.hpp>

        #include <string>



class CLxUser_VirtualDevice : public CLxLoc_VirtualDevice
{
        public:
        CLxUser_VirtualDevice () {}
        CLxUser_VirtualDevice (ILxUnknownID obj) : CLxLoc_VirtualDevice (obj) {}



};

class CLxUser_FileReference : public CLxLoc_FileReference
{
        public:
        CLxUser_FileReference () {}
        CLxUser_FileReference (ILxUnknownID obj) : CLxLoc_FileReference (obj) {}

        /**
         * Empty FileReference Python user class.
         */
        

};

class CLxUser_FileRedirect : public CLxLoc_FileRedirect
{
        public:
        CLxUser_FileRedirect () {}
        CLxUser_FileRedirect (ILxUnknownID obj) : CLxLoc_FileRedirect (obj) {}



};

class CLxUser_FileService : public CLxLoc_FileService
{
        public:
        LxResult
        FileSystemPath (
                const char		*name,
                std::string		&path)
        {
                LxResult		 result;
                const char		*systemPath;
        
                result = CLxLoc_FileService::FileSystemPath (name, &systemPath);
                if (LXx_OK (result))
                        path = std::string(systemPath);
        
                return result;
        }

};
#endif
