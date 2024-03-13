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
#ifndef LXUSER_groupui_HPP
#define LXUSER_groupui_HPP

#include <lxw_groupui.hpp>


class CLxUser_GroupDest : public CLxLoc_GroupDest
{
        public:
        CLxUser_GroupDest () {}
        CLxUser_GroupDest (ILxUnknownID obj) : CLxLoc_GroupDest (obj) {}



};

class CLxUser_GroupMemberItemDest : public CLxLoc_GroupMemberItemDest
{
        public:
        CLxUser_GroupMemberItemDest () {}
        CLxUser_GroupMemberItemDest (ILxUnknownID obj) : CLxLoc_GroupMemberItemDest (obj) {}



};

class CLxUser_GroupMemberChanDest : public CLxLoc_GroupMemberChanDest
{
        public:
        CLxUser_GroupMemberChanDest () {}
        CLxUser_GroupMemberChanDest (ILxUnknownID obj) : CLxLoc_GroupMemberChanDest (obj) {}



};

class CLxUser_PoseItem : public CLxLoc_PoseItem
{
        public:
        CLxUser_PoseItem () {}
        CLxUser_PoseItem (ILxUnknownID obj) : CLxLoc_PoseItem (obj) {}

        bool
        Create ()
        {
                if (LXx_OK(CLxLoc_PoseItem::Create()))
                        return true;
                else
                        return false;
        }
        
                bool
        SetFloat(
                CLxUser_Item		&item,
                std::string const	&channelName,
                double			value)
        {
                int channelIndex = item.ChannelIndex(channelName.c_str());
                if (channelIndex < 0)
                        return false;
        
                return LXx_OK(CLxLoc_PoseItem::SetFloat(item, channelIndex, value));
        }
        
                bool
        SetInt(
                CLxUser_Item		&item,
                std::string const	&channelName,
                int			value)
        {
                int channelIndex = item.ChannelIndex(channelName.c_str());
                if (channelIndex < 0)
                        return false;
        
                return LXx_OK(CLxLoc_PoseItem::SetInt(item, channelIndex, value));
        }
        
                bool
        SetValue(
                CLxUser_Item		&item,
                std::string const	&channelName,
                CLxUser_ChannelRead	&chanRead)
        {
                int channelIndex = item.ChannelIndex(channelName.c_str());
                if (channelIndex < 0)
                        return false;
        
                unsigned int channelType;
                if (LXx_FAIL(item.ChannelType (channelIndex, &channelType)))
                        return false;
        
                switch (channelType)
                {
                case LXiCHANTYPE_FLOAT:
                        {
                                double value = chanRead.FValue(item, channelIndex);
                                return LXx_OK(CLxLoc_PoseItem::SetFloat(item, channelIndex, value));
                        }
                        break;
        
                case LXiCHANTYPE_INTEGER:
                        {
                                int value = chanRead.IValue(item, channelIndex);
                                return LXx_OK(CLxLoc_PoseItem::SetInt(item, channelIndex, value));
                        }
                        break;
                }
        
                return false;
        }
        
                float
        GetFloat(
                CLxUser_Item		&item,
                std::string const	&channelName)
        {
                int channelIndex = item.ChannelIndex(channelName.c_str());
                if (channelIndex < 0)
                        return false;
        
                float value = 0.0f;
                if (LXx_OK(CLxLoc_PoseItem::GetFloat(item, channelIndex, &value)))
                {
                        return value;
                }
                
                return 0.0f;
        }
        
                int
        GetInt(
                CLxUser_Item		&item,
                std::string const	&channelName)
        {
                int channelIndex = item.ChannelIndex(channelName.c_str());
                if (channelIndex < 0)
                        return false;
        
                int value = 0;
                if (LXx_OK(CLxLoc_PoseItem::GetInt(item, channelIndex, &value)))
                {
                        return value;
                }
                
                return 0.0f;
        }

};
#endif
