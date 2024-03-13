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
#ifndef LXUSER_dirbrowse_HPP
#define LXUSER_dirbrowse_HPP

#include <lxw_dirbrowse.hpp>


class CLxUser_DirCacheEntry : public CLxLoc_DirCacheEntry
{
        public:
        CLxUser_DirCacheEntry () {}
        CLxUser_DirCacheEntry (ILxUnknownID obj) : CLxLoc_DirCacheEntry (obj) {}

        /**
         * Empty DirCacheEntry Python user class.
         */
        

};

class CLxUser_DirEntryThumbAsync : public CLxLoc_DirEntryThumbAsync
{
        public:
        CLxUser_DirEntryThumbAsync () {}
        CLxUser_DirEntryThumbAsync (ILxUnknownID obj) : CLxLoc_DirEntryThumbAsync (obj) {}

        /**
         * Empty DirEntryThumbAsync Python user class.
         */
        

};

class CLxUser_MergedDirCacheEntry : public CLxLoc_MergedDirCacheEntry
{
        public:
        CLxUser_MergedDirCacheEntry () {}
        CLxUser_MergedDirCacheEntry (ILxUnknownID obj) : CLxLoc_MergedDirCacheEntry (obj) {}

        /**
         * Empty MergedDirCacheEntry Python user class.
         */
        

};

class CLxUser_DirCacheFileMetrics : public CLxLoc_DirCacheFileMetrics
{
        public:
        CLxUser_DirCacheFileMetrics () {}
        CLxUser_DirCacheFileMetrics (ILxUnknownID obj) : CLxLoc_DirCacheFileMetrics (obj) {}

        /**
         * Empty DirCacheFileMetrics Python user class.
         */
        

};

class CLxUser_BasePathAddDest : public CLxLoc_BasePathAddDest
{
        public:
        CLxUser_BasePathAddDest () {}
        CLxUser_BasePathAddDest (ILxUnknownID obj) : CLxLoc_BasePathAddDest (obj) {}



};

class CLxUser_DirCacheManualOrderDest : public CLxLoc_DirCacheManualOrderDest
{
        public:
        CLxUser_DirCacheManualOrderDest () {}
        CLxUser_DirCacheManualOrderDest (ILxUnknownID obj) : CLxLoc_DirCacheManualOrderDest (obj) {}



};

class CLxUser_DirCacheGridPosDest : public CLxLoc_DirCacheGridPosDest
{
        public:
        CLxUser_DirCacheGridPosDest () {}
        CLxUser_DirCacheGridPosDest (ILxUnknownID obj) : CLxLoc_DirCacheGridPosDest (obj) {}



};

class CLxUser_FileSysDest : public CLxLoc_FileSysDest
{
        public:
        CLxUser_FileSysDest () {}
        CLxUser_FileSysDest (ILxUnknownID obj) : CLxLoc_FileSysDest (obj) {}



};

class CLxUser_MergedFileSysDest : public CLxLoc_MergedFileSysDest
{
        public:
        CLxUser_MergedFileSysDest () {}
        CLxUser_MergedFileSysDest (ILxUnknownID obj) : CLxLoc_MergedFileSysDest (obj) {}



};

class CLxUser_DirBrowserBasePathEntryDest : public CLxLoc_DirBrowserBasePathEntryDest
{
        public:
        CLxUser_DirBrowserBasePathEntryDest () {}
        CLxUser_DirBrowserBasePathEntryDest (ILxUnknownID obj) : CLxLoc_DirBrowserBasePathEntryDest (obj) {}



};

class CLxUser_DirCacheService : public CLxLoc_DirCacheService
{
        public:
        /**
         * Empty DirCache service user classes.
         */
        

};
#endif
