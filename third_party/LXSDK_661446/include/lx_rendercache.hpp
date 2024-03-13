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
#ifndef LXUSER_rendercache_HPP
#define LXUSER_rendercache_HPP

#include <lxw_rendercache.hpp>


class CLxUser_RenderCache : public CLxLoc_RenderCache
{
        public:
        CLxUser_RenderCache () {}
        CLxUser_RenderCache (ILxUnknownID obj) : CLxLoc_RenderCache (obj) {}

        bool
        GetGeoSurface (
                int		index,
        CLxLoc_GeoCacheSurface	&srf)
        {
                LXtObjectID	obj;
        
                if (LXx_FAIL (GeoSurfaceAt (index, &obj)))
                        return false;
        
                return srf.set (obj);
        }

};

class CLxUser_GeoCacheSegment : public CLxLoc_GeoCacheSegment
{
        public:
        CLxUser_GeoCacheSegment () {}
        CLxUser_GeoCacheSegment (ILxUnknownID obj) : CLxLoc_GeoCacheSegment (obj) {}



};

class CLxUser_GeoCacheSurface : public CLxLoc_GeoCacheSurface
{
        public:
        CLxUser_GeoCacheSurface () {}
        CLxUser_GeoCacheSurface (ILxUnknownID obj) : CLxLoc_GeoCacheSurface (obj) {}

        bool
        GetSourceItem (
                CLxLoc_Item	&item)
        {
                LXtObjectID		obj;
        
                if (LXx_FAIL (SourceItem (&obj)))
                        return false;
        
                return item.set (obj);
        }
        bool
        GetSourceSurface (
                CLxLoc_GeoCacheSurface	&srf)
        {
                LXtObjectID		obj;
        
                if (LXx_FAIL (SourceSurface (&obj)))
                        return false;
        
                return srf.set (obj);
        }
        bool
        GetSegment (
                int			index,
                CLxLoc_GeoCacheSegment	&seg)
        {
                LXtObjectID		obj;
        
                if (LXx_FAIL (SegmentAt (index, &obj)))
                        return false;
        
                return seg.set (obj);
        }
        bool
        GetShaderLayer (
                unsigned int	index,
                CLxLoc_Item		&item)
        {
                LXtObjectID		obj;
        
                if (LXx_FAIL (ShaderLayerAt (index, &obj)))
                        return false;
        
                return item.set (obj);
        }

};

class CLxUser_RenderCacheService : public CLxLoc_RenderCacheService
{
        public:
        bool
        NewRenderCache (
                CLxLoc_RenderCache	&rcache,
                unsigned		 createFlags)
        {
                LXtObjectID		obj;
        
                if (LXx_FAIL (CreateRenderCache (&obj, createFlags)))
                        return false;
        
                return rcache.take (obj);
        }

};
#endif
