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
#ifndef LXUSER_tool_HPP
#define LXUSER_tool_HPP

#include <lxw_tool.hpp>


class CLxUser_AttrSequence : public CLxLoc_AttrSequence
{
        public:
        CLxUser_AttrSequence () {}
        CLxUser_AttrSequence (ILxUnknownID obj) : CLxLoc_AttrSequence (obj) {}



};

class CLxUser_ToolOperation : public CLxLoc_ToolOperation
{
        public:
        CLxUser_ToolOperation () {}
        CLxUser_ToolOperation (ILxUnknownID obj) : CLxLoc_ToolOperation (obj) {}



};

class CLxUser_FalloffPacket : public CLxLoc_FalloffPacket
{
        public:
        CLxUser_FalloffPacket () {}
        CLxUser_FalloffPacket (ILxUnknownID obj) : CLxLoc_FalloffPacket (obj) {}



};

class CLxUser_SymmetryPacket : public CLxLoc_SymmetryPacket
{
        public:
        CLxUser_SymmetryPacket () {}
        CLxUser_SymmetryPacket (ILxUnknownID obj) : CLxLoc_SymmetryPacket (obj) {}



};

class CLxUser_Subject2Packet : public CLxLoc_Subject2Packet
{
        public:
        CLxUser_Subject2Packet () {}
        CLxUser_Subject2Packet (ILxUnknownID obj) : CLxLoc_Subject2Packet (obj) {}

        bool
        BeginScan (
                unsigned int		 flags,
                CLxLocalizedObject	&scan)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ScanAllocate (flags, &obj)))
                        return false;
        
                return scan.take (obj);
        }

};

class CLxUser_TexturePacket : public CLxLoc_TexturePacket
{
        public:
        CLxUser_TexturePacket () {}
        CLxUser_TexturePacket (ILxUnknownID obj) : CLxLoc_TexturePacket (obj) {}



};

class CLxUser_ElementAxisPacket : public CLxLoc_ElementAxisPacket
{
        public:
        CLxUser_ElementAxisPacket () {}
        CLxUser_ElementAxisPacket (ILxUnknownID obj) : CLxLoc_ElementAxisPacket (obj) {}



};

class CLxUser_ElementCenterPacket : public CLxLoc_ElementCenterPacket
{
        public:
        CLxUser_ElementCenterPacket () {}
        CLxUser_ElementCenterPacket (ILxUnknownID obj) : CLxLoc_ElementCenterPacket (obj) {}



};

class CLxUser_BagGenerator : public CLxLoc_BagGenerator
{
        public:
        CLxUser_BagGenerator () {}
        CLxUser_BagGenerator (ILxUnknownID obj) : CLxLoc_BagGenerator (obj) {}



};

class CLxUser_PathStep : public CLxLoc_PathStep
{
        public:
        CLxUser_PathStep () {}
        CLxUser_PathStep (ILxUnknownID obj) : CLxLoc_PathStep (obj) {}



};

class CLxUser_PathGeneratorPacket : public CLxLoc_PathGeneratorPacket
{
        public:
        CLxUser_PathGeneratorPacket () {}
        CLxUser_PathGeneratorPacket (ILxUnknownID obj) : CLxLoc_PathGeneratorPacket (obj) {}



};

class CLxUser_ParticleGeneratorPacket : public CLxLoc_ParticleGeneratorPacket
{
        public:
        CLxUser_ParticleGeneratorPacket () {}
        CLxUser_ParticleGeneratorPacket (ILxUnknownID obj) : CLxLoc_ParticleGeneratorPacket (obj) {}



};
#endif
