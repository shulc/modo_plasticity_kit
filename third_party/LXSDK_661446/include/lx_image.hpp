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
#ifndef LXUSER_image_HPP
#define LXUSER_image_HPP

#include <lxw_image.hpp>

        #include <string>



class CLxUser_Image : public CLxLoc_Image
{
        public:
        CLxUser_Image () {}
        CLxUser_Image (ILxUnknownID obj) : CLxLoc_Image (obj) {}

        // QWEB_MACRO_BEGIN - SDK Common User: Size methods
                unsigned
        Width () const
        {
                unsigned		 w, h;
        
                Size (&w, &h);
                return w;
        }
        
                unsigned
        Height () const
        {
                unsigned		 w, h;
        
                Size (&w, &h);
                return h;
        }
                // QWEB_MACRO_END - SDK Common User: Size methods
                // QWEB_MACRO_BEGIN - SDK Common User: Format methods
                bool
        IsFloat () const
        {
                return LXxIMD_TYPE (Format ()) == LXiIMD_FLOAT;
        }
        
                unsigned
        Components () const
        {
                return LXxIMV_TYPE (Format ());
        }
                // QWEB_MACRO_END - SDK Common User: Format methods

};

class CLxUser_ImageWrite : public CLxLoc_ImageWrite
{
        public:
        CLxUser_ImageWrite () {}
        CLxUser_ImageWrite (ILxUnknownID obj) : CLxLoc_ImageWrite (obj) {}

        LxResult
        AddAttribute (
                const std::string	&name,
                const std::string	&type,
                unsigned		&index)
        {
                return CLxLoc_ImageWrite::AddAttribute (name.c_str (), type.c_str (), &index);
        }
        
        // QWEB_MACRO_BEGIN - SDK Common User: Size methods
                unsigned
        Width () const
        {
                unsigned		 w, h;
        
                Size (&w, &h);
                return w;
        }
        
                unsigned
        Height () const
        {
                unsigned		 w, h;
        
                Size (&w, &h);
                return h;
        }
        // QWEB_MACRO_END - SDK Common User: Size methods
        // QWEB_MACRO_BEGIN - SDK Common User: Format methods
                bool
        IsFloat () const
        {
                return LXxIMD_TYPE (Format ()) == LXiIMD_FLOAT;
        }
        
                unsigned
        Components () const
        {
                return LXxIMV_TYPE (Format ());
        }
        // QWEB_MACRO_END - SDK Common User: Format methods

};

class CLxUser_IndexImage : public CLxLoc_IndexImage
{
        public:
        CLxUser_IndexImage () {}
        CLxUser_IndexImage (ILxUnknownID obj) : CLxLoc_IndexImage (obj) {}

        // QWEB_MACRO_BEGIN - SDK Common User: Size methods
                unsigned
        Width () const
        {
                unsigned		 w, h;
        
                Size (&w, &h);
                return w;
        }
        
                unsigned
        Height () const
        {
                unsigned		 w, h;
        
                Size (&w, &h);
                return h;
        }
                // QWEB_MACRO_END - SDK Common User: Size methods
                // QWEB_MACRO_BEGIN - SDK Common User: Format methods
                bool
        IsFloat () const
        {
                return LXxIMD_TYPE (Format ()) == LXiIMD_FLOAT;
        }
        
                unsigned
        Components () const
        {
                return LXxIMV_TYPE (Format ());
        }
                // QWEB_MACRO_END - SDK Common User: Format methods

};

class CLxUser_IndexImageWrite : public CLxLoc_IndexImageWrite
{
        public:
        CLxUser_IndexImageWrite () {}
        CLxUser_IndexImageWrite (ILxUnknownID obj) : CLxLoc_IndexImageWrite (obj) {}

        LxResult
        AddAttribute (
                const std::string	&name,
                const std::string	&type,
                unsigned		&index)
        {
                return CLxLoc_IndexImageWrite::AddAttribute (name.c_str (), type.c_str (), &index);
        }
        
        // QWEB_MACRO_BEGIN - SDK Common User: Size methods
                unsigned
        Width () const
        {
                unsigned		 w, h;
        
                Size (&w, &h);
                return w;
        }
        
                unsigned
        Height () const
        {
                unsigned		 w, h;
        
                Size (&w, &h);
                return h;
        }
        // QWEB_MACRO_END - SDK Common User: Size methods
        // QWEB_MACRO_BEGIN - SDK Common User: Format methods
                bool
        IsFloat () const
        {
                return LXxIMD_TYPE (Format ()) == LXiIMD_FLOAT;
        }
        
                unsigned
        Components () const
        {
                return LXxIMV_TYPE (Format ());
        }
        // QWEB_MACRO_END - SDK Common User: Format methods

};

class CLxUser_LayeredImage : public CLxLoc_LayeredImage
{
        public:
        CLxUser_LayeredImage () {}
        CLxUser_LayeredImage (ILxUnknownID obj) : CLxLoc_LayeredImage (obj) {}


        // QWEB_MACRO_BEGIN - SDK Common User: Size methods
                unsigned
        Width () const
        {
                unsigned		 w, h;
        
                Size (&w, &h);
                return w;
        }
        
                unsigned
        Height () const
        {
                unsigned		 w, h;
        
                Size (&w, &h);
                return h;
        }
        // QWEB_MACRO_END - SDK Common User: Size methods
        
                bool
        GetImage (
                unsigned int		 index,
                CLxLoc_Image		&img)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Image (index, &obj)))
                        return false;
        
                return img.take (obj);
        }

};

class CLxUser_LayeredImageWrite : public CLxLoc_LayeredImageWrite
{
        public:
        CLxUser_LayeredImageWrite () {}
        CLxUser_LayeredImageWrite (ILxUnknownID obj) : CLxLoc_LayeredImageWrite (obj) {}



};

class CLxUser_TileImage : public CLxLoc_TileImage
{
        public:
        CLxUser_TileImage () {}
        CLxUser_TileImage (ILxUnknownID obj) : CLxLoc_TileImage (obj) {}



};

class CLxUser_ImageLoaderTarget1 : public CLxLoc_ImageLoaderTarget1
{
        public:
        CLxUser_ImageLoaderTarget1 () {}
        CLxUser_ImageLoaderTarget1 (ILxUnknownID obj) : CLxLoc_ImageLoaderTarget1 (obj) {}



};

class CLxUser_ImageLoaderTarget : public CLxLoc_ImageLoaderTarget
{
        public:
        CLxUser_ImageLoaderTarget () {}
        CLxUser_ImageLoaderTarget (ILxUnknownID obj) : CLxLoc_ImageLoaderTarget (obj) {}



};

class CLxUser_ImageFilter : public CLxLoc_ImageFilter
{
        public:
        CLxUser_ImageFilter () {}
        CLxUser_ImageFilter (ILxUnknownID obj) : CLxLoc_ImageFilter (obj) {}



};

class CLxUser_ImageFilterMetrics : public CLxLoc_ImageFilterMetrics
{
        public:
        CLxUser_ImageFilterMetrics () {}
        CLxUser_ImageFilterMetrics (ILxUnknownID obj) : CLxLoc_ImageFilterMetrics (obj) {}



};

class CLxUser_ImageService : public CLxLoc_ImageService
{
        public:
        /**
         * Create a new image and fill in the user's user object.
         */
                bool
        New (
                CLxUser_Image		&image,
                unsigned int		 w,
                unsigned int		 h,
                LXtPixelFormat		 type,
                unsigned int		 maxIndex = 0)
        {
                LXtObjectID		 obj;
                bool			 created = false;
        
                image.clear ();
                if (LXx_OK (Create (w, h, type, maxIndex, &obj))) {
                        image.take (obj);
                        created = true;
                }
        
                return created;
        }
        
                bool
        NewCrop (
                CLxUser_Image		&image,
                CLxUser_Image		&sourceImage,
                double			 x,
                double			 y,
                double			 w,
                double			 h)
        {
                LXtObjectID		 obj;
                bool			 created = false;
        
                image.clear ();
                if (LXx_OK (CLxLoc_ImageService::CreateCrop (sourceImage, x, y, w, h, &obj))) {
                        image.take (obj);
                        created = true;
                }
        
                return created;
        }
        
                bool
        Load (
                CLxUser_Image		&image,
                const std::string	&filePath)
        {
                LXtObjectID		 obj;
                bool			 found = false;
        
                image.clear ();
                if (LXx_OK (CLxLoc_ImageService::Load (filePath.c_str (), &obj))) {
                        image.take (obj);
                        found = true;
                }
        
                return found;
        }
        
                bool
        LoadNoCache (
                CLxUser_Image		&image,
                const std::string	&filePath)
        {
                LXtObjectID		 obj;
                bool			 found = false;
        
                image.clear ();
                if (LXx_OK (CLxLoc_ImageService::LoadNoCache (filePath.c_str (), &obj))) {
                        image.take (obj);
                        found = true;
                }
        
                return found;
        }
        
                LxResult
        Save (
                CLxUser_Image		&image,
                const std::string	&filePath,
                const std::string	&format,
                ILxUnknownID		 monitor = 0)
        {
                return CLxLoc_ImageService::Save (image, filePath.c_str (), format.c_str (), monitor);
        }
        
                LxResult
        Resample (
                CLxUser_Image		&destImage,
                CLxUser_Image		&sourceImage,
                LXtProcessHint		 hint)
        {
                return CLxLoc_ImageService::Resample (destImage, sourceImage, hint);
        }
        
                LxResult
        Composite (
                CLxUser_Image		&destImage,
                CLxUser_Image		&sourceImage,
                const LXtFVector2	 pos)
        {
                return CLxLoc_ImageService::Composite (destImage, sourceImage, pos);
        }
        
                LxResult
        DrawLine (
                CLxUser_Image		&image,
                const LXtFVector2	 p0,
                const LXtFVector2	 p1,
                LXtFVector		 color)
        {
                return CLxLoc_ImageService::DrawLine (image, p0, p1, color);
        }
        
                bool
        NewLayered (
                CLxUser_LayeredImage		&layeredImage,
                unsigned int		 w,
                unsigned int		 h,
                unsigned int		 layerNum = 1)
        {
                LXtObjectID		 obj;
                bool			 created = false;
        
                layeredImage.clear ();
                if (LXx_OK (CreateLayered (w, h, layerNum, &obj))) {
                        layeredImage.take (obj);
                        created = true;
                }
        
                return created;
        }
        
                LxResult
        Save (
                CLxUser_LayeredImage	&layeredImage,
                const std::string		&filePath,
                const std::string		&format,
                ILxUnknownID			monitor = 0)
        {
                return CLxLoc_ImageService::SaveLayered (layeredImage, filePath.c_str (), format.c_str (), monitor);
        }
        

};
#endif
