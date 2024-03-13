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
#ifndef LXUSER_rndjob_HPP
#define LXUSER_rndjob_HPP

#include <lxw_rndjob.hpp>

#include <lx_image.hpp>
#include <lx_value.hpp>



class CLxUser_RenderJob : public CLxLoc_RenderJob
{
        public:
        CLxUser_RenderJob () {}
        CLxUser_RenderJob (ILxUnknownID obj) : CLxLoc_RenderJob (obj) {}

        LxResult
        RenderTurntableFPS (
                int			 &fps)
        {
                return CLxLoc_RenderJob::RenderTurntableFPS (&fps);
        }
        
                LxResult
        RenderTurntableNumFrames (
                int			 &numFrames)
        {
                return CLxLoc_RenderJob::RenderTurntableNumFrames (&numFrames);
        }
        
                LxResult
        RenderBakeVMap (
                std::string		 &vmap)
        {
                LxResult	 result;
                const char	*vmapName;
        
                result = CLxLoc_RenderJob::RenderBakeVMap (&vmapName);
                if (LXx_OK (result)) {
                        vmap = std::string(vmapName);
                }
        
                return result;
        }
        
                LxResult
        RenderBakeCageVMap (
                std::string		 &vmap)
        {
                LxResult	 result;
                const char	*vmapName;
        
                result = CLxLoc_RenderJob::RenderBakeCageVMap (&vmapName);
                if (LXx_OK (result)) {
                        vmap = std::string(vmapName);
                }
        
                return result;
        }
        
                LxResult
        RenderBakeLookDistance (
                double			 &distance)
        {
                return CLxLoc_RenderJob::RenderBakeLookDistance (&distance);
        }
        
                LxResult
        RenderBakeEffect (
                std::string		 &effect)
        {
                LxResult	 result;
                const char		*effectName;
        
                result = CLxLoc_RenderJob::RenderBakeEffect (&effectName);
                if (LXx_OK (result)) {
                        effect = std::string(effectName);
                }
        
                return result;
        }
        
                LxResult
        FrameBufferSlot (
                int			 &index)
        {
                return CLxLoc_RenderJob::FrameBufferSlot (&index);
        }
        
                LxResult
        FrameBufferRegionBackgroundSlot (
                int			 &slotIndex,
                int			 &passIndex)
        {
                return CLxLoc_RenderJob::FrameBufferRegionBackgroundSlot (&slotIndex, &passIndex);
        }
        
                LxResult
        OutputFormat (
                std::string		 &format)
        {
                LxResult	 result;
                const char	*formatName;
        
                result = CLxLoc_RenderJob::OutputFormat (&formatName);
                if (LXx_OK (result)) {
                        format = std::string(formatName);
                }
        
                return result;
        }
        
                LxResult
        OutputFilename (
                std::string		 &filename)
        {
                LxResult	 result;
                const char	*filenameChars;
        
                result = CLxLoc_RenderJob::OutputFilename (&filenameChars);
                if (LXx_OK (result)) {
                        filename = std::string(filenameChars);
                }
        
                return result;
        }
        
                LxResult
        Options (
                int			 &options)
        {
                return CLxLoc_RenderJob::Options (&options);
        }
        

};

class CLxUser_Buffer : public CLxLoc_Buffer
{
        public:
        CLxUser_Buffer () {}
        CLxUser_Buffer (ILxUnknownID obj) : CLxLoc_Buffer (obj) {}

        void
        GetSize (
                int		&width,
                int		&height) const
        {
                return CLxLoc_Buffer::GetSize (&width, &height);
        }
        
        LxResult
        Name (std::string &name) const
        {
                char	*charName = NULL;
                LxResult result = CLxLoc_Buffer::Name ((const char **)&charName);
        
                if (charName) {
                        name = std::string(charName);
                }
        
                return result;
        }
        
        LxResult
        SetUserName (const std::string &name)
        {
                return CLxLoc_Buffer::SetUserName (name.c_str ());
        }

};

class CLxUser_FrameBuffer : public CLxLoc_FrameBuffer
{
        public:
        CLxUser_FrameBuffer () {}
        CLxUser_FrameBuffer (ILxUnknownID obj) : CLxLoc_FrameBuffer (obj) {}

        bool
        Allocate (
                CLxUser_Buffer		&buffer,
                const std::string	&name,
                const std::string	&userName,
                bool			 isFactoryName,
                bool			 writeBucketsToDisk)
        {
                bool		 created = false;
        
                LXtObjectID obj = CLxLoc_FrameBuffer::Allocate (
                        name.c_str (),
                        NULL,
                        NULL,
                        userName.c_str (),
                        isFactoryName,
                        writeBucketsToDisk);
                if (obj) {
                        buffer.take (obj);
                        created = true;
                }
        
                return created;
        }
        
                bool
        NewFrameBufferTarget (
                CLxUser_Image		&image,
                LXtPixelFormat		 type,
                int			 w,
                int			 h)
        {
                LXtObjectID		 obj;
                bool			 created = false;
        
                image.clear ();
                if (LXx_OK (CLxLoc_FrameBuffer::CreateFrameBufferTargetImage (type, w, h, &obj))) {
                        image.take (obj);
                        created = true;
                }
        
                return created;
        }
        
                bool
        IsStereo (void) const
        {
                int		isStereo = 0;
        
                LxResult	result;
                result = CLxLoc_FrameBuffer::IsStereo (&isStereo);
        
                return LXx_OK (result) && isStereo;
        }
        
                bool
        Lookup (
                CLxUser_Buffer		&buffer,
                const std::string	&name) const
        {
                bool		 found = false;
        
                LXtObjectID obj = CLxLoc_FrameBuffer::Lookup (name.c_str (), NULL);
                if (obj) {
                        buffer.set (obj);
                        found = true;
                }
        
                return found;
        }
        
                bool
        ByIndex (
                CLxUser_Buffer		&buffer,
                int			 index) const
        {
                bool		 found = false;
        
                LXtObjectID obj = CLxLoc_FrameBuffer::ByIndex (index);
                if (obj) {
                        buffer.set (obj);
                        found = true;
                }
        
                return found;
        }
        
                bool
        Alpha (
                CLxUser_Buffer		&buffer,
                int			 index) const
        {
                bool		 found = false;
        
                LXtObjectID obj = CLxLoc_FrameBuffer::Alpha (index);
                if (obj) {
                        buffer.set (obj);
                        found = true;
                }
        
                return found;
        }
        
                LxResult
        AddAttribute (
                const std::string	&name,
                const std::string	&type,
                unsigned		&index)
        {
                return CLxLoc_FrameBuffer::AddAttribute (name.c_str (), type.c_str (), &index);
        }
        

};

class CLxUser_RenderService : public CLxLoc_RenderService
{
        public:
        bool
        JobGetCurrent (
                CLxLoc_RenderJob	 &job ) const
        {
                LXtObjectID		  obj;
        
                if( LXx_FAIL( JobCurrent( &obj ) ) )
                        return false;
        
                return job.take( obj );
        }
        bool
        JobGetStats (
                CLxLoc_Attributes	 &stats )
        {
                LXtObjectID		  obj;
        
                obj = JobStats();
                if( !obj )
                        return false;
        
                // Since this is a "peek", we use set() instad of take()
                return stats.set( obj );
        }
        
        bool
        JobIsSlave () const
        {
                return CLxLoc_RenderService::JobIsSlave () ? true : false;
        }
        

};

class CLxUser_ImageProcessing : public CLxLoc_ImageProcessing
{
        public:
        /**
         * // TODO:  Add methods to read/write settings to/from an object with an ILxAttributes interface
         */
                LxResult
        GetIdentifier (std::string &identifier)
        {
                LxResult	 result;
                const char	*identifierChars;
        
                result = CLxLoc_ImageProcessing::GetIdentifier (&identifierChars);
                identifier = std::string(identifierChars);
        
                return result;
        }
        
                LxResult
        SetIdentifier (const std::string &identifier)
        {
                return CLxLoc_ImageProcessing::SetIdentifier (identifier.c_str ());
        }
        

};

class CLxUser_ImageProcessingRead : public CLxLoc_ImageProcessingRead
{
        public:
        LxResult
        GetIdentifier (std::string &identifier)
        {
                LxResult	 result;
                const char	*identifierChars;
        
                result = CLxLoc_ImageProcessingRead::GetIdentifier (&identifierChars);
                identifier = std::string(identifierChars);
        
                return result;
        }

};

class CLxUser_ImageProcessingService : public CLxLoc_ImageProcessingService
{
        public:
        /**
         * Create a new image and fill in the user's user object.
         */
                bool
        New (CLxUser_ImageProcessing &imageProcessing)
        {
                LXtObjectID		 obj;
                bool			 created = false;
        
                imageProcessing.clear ();
                if (LXx_OK (CLxLoc_ImageProcessingService::Create (&obj))) {
                        imageProcessing.take (obj);
                        created = true;
                }
        
                return created;
        }

};
#endif
