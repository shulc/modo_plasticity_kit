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
#ifndef LXUSER_channelui_HPP
#define LXUSER_channelui_HPP

#include <lxw_channelui.hpp>

#include <lx_command.hpp>
#include <lxu_getstring.hpp>



class CLxUser_ChannelUIService : public CLxLoc_ChannelUIService
{
        public:
class Tmp_Sgs {
            public:
                CLxLoc_ChannelUIService	*srv;
                LXtItemType		 typeID;
                const char		*mapName;
                unsigned		 useSuper, addIcon;
                bool			 isMap;
        
                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        if (isMap)
                                return srv->MeshMapUserName (mapName, addIcon, buf, len);
                        else
                                return srv->ItemTypeIconText (typeID, useSuper, buf, len);
                }
        };
        
                LxResult
        GetTypeIcon (
                LXtItemType		 typeID,
                unsigned		 useSuper,
                std::string		&text)
        {
                Tmp_Sgs				 tmp;
                CLxSafeGetString<Tmp_Sgs>	 sgs;
        
                tmp.srv      = this;
                tmp.typeID   = typeID;
                tmp.useSuper = useSuper;
                tmp.isMap    = false;
                return sgs.GetString (tmp, text);
        }
        
                LxResult
        GetMapUserName (
                const char		*name,
                unsigned		 addIcon,
                std::string		&text)
        {
                Tmp_Sgs				 tmp;
                CLxSafeGetString<Tmp_Sgs>	 sgs;
        
                tmp.srv     = this;
                tmp.mapName = name;
                tmp.addIcon = addIcon;
                tmp.isMap   = true;
                return sgs.GetString (tmp, text);
        }

};
#endif
