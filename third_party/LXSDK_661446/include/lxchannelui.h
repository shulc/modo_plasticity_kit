/*
 * LX channelui module
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
#ifndef LX_channelui_H
#define LX_channelui_H

typedef struct vt_ILxChannelUI ** ILxChannelUIID;
typedef struct vt_ILxChannelUI1 ** ILxChannelUI1ID;
typedef struct vt_ILxChannelUIService ** ILxChannelUIServiceID;

#include <lxitem.h>



/*
 * The enable method works very much like a command enable function, and returns
 * the same kinds of codes:  LXe_CMD_DISABLED if disabled, LXe_OK for enabled and
 * anything else for a failure code.  The item type and channel name are provided
 * as arguments, allowing the same object to handle multiple different channels.
 * A disable message can be returned as part of the ILxMessageID.  Note that, as
 * with commands, the code stored in the ILxMessageID should also be returned by
 * the enable function.
 * The item argument may be NULL, or may be provided by the caller.  The object
 * can use this for for more specific enable tests.  Note that it is valid for
 * the item to be NULL, in which case a general test should be applied to item
 * type itself.
 * 
 * 
 * item.channel needs a way to know what other channels this channel might depend on
 * for its enable state.  The following methods are used to see if a recently changed
 * channel is a dependency of this channel and thus control if this channel is enabled
 * (i.e., available for user interaction) or not (i.e., "ghosted").  If the changed channel
 * is a dependency, then this channel's UI representation is told to update it's
 * "enabled" state with that returned by the Enabled() method.
 * Note that the dependency mechanism only allows watching channels on the same item.
 * This includes allowing packages to watch for changes to channels on other packages
 * as long as both packages are on the same item.  If you need more flexibility, you'll
 * need to implement your own notifier through the UIHints() method.  The depItemType
 * argument thus indicates a channel in different package on the item, or a supertype
 * of the item itself.
 * 
 * 
 * 
 * This variation is more robust, taking an item type as a string instead of an integer
 * code.  This works well for packages, which do not support type codes.  Clients only
 * need to implement one of those, although DependencyByIndexName() is preferred.
 * 
 * Entire items can also be disabled or enabled.  When disabled, all controls related
 * to item (such as channel controls in property forms) will be considered disabled,
 * and the item will be marked as disabled in the Item List.  The item argument is the
 * specific item being tested.
 * 
 * An item can return a specific icon resource name based on some state, like an item tag.
 * This isn't updated too frequently, and thus should be a relatively static icon.  If this
 * returns a failure code or is not implemented, the icon found referenced in the Item Help
 * configs is used.  The resource name should not include any size suffix (ie: return
 * "MyItemIcon", not "MyItemIcon_20").
 * 
 * A channel's UI hints are automatically populated for it before being used for the
 * UI.  However, items further tweak these by implementing this method and setting
 * the UI hints properties themselves.
 * 
 * Channels can similar return a specific UIValueHints object for their UI, and
 * to provide a per-channel notifier list.
 * 
 * Each item/channel pair can have a cookie associated with it.  This is primarily
 * used to associate global data with the channel, which is often stored in the
 * config.  A common case is to provide a value preset popup for numeric channels.
 * The cookie is optional.  This method can return any failure code, such as
 * LXe_NOTIMPL or LXe_NOTFOUND, if the channel does not have a cookie.  A single
 * channel may have multiple cookies for different purposes, and in fact may use
 * the same cookie for multiple states.  This allows the channel to support one
 * global but not another.  Which cookie the client wants is determined by the
 * requestedFor argument.
 * 
 */
typedef struct vt_ILxChannelUI {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Enabled) (
        LXtObjectID		 self,
        const char		*channelName,
        LXtObjectID		 msg,
        LXtObjectID		 item,
        LXtObjectID		 chanRead);
        LXxMETHOD(  LxResult,
DependencyCount) (
        LXtObjectID		  self,
        const char		 *channelName,
        unsigned		 *count);
        LXxMETHOD(  LxResult,
DependencyByIndex) (
        LXtObjectID		  self,
        const char		 *channelName,
        unsigned		  index,
        LXtItemType		 *depItemType,
        const char		**depChannelName);
        LXxMETHOD(  LxResult,
DependencyByIndexName) (
        LXtObjectID		  self,
        const char		 *channelName,
        unsigned		  index,
        const char		**depItemTypeName,
        const char		**depChannelName);
        LXxMETHOD(  LxResult,
ItemEnabled) (
        LXtObjectID		 self,
        LXtObjectID		 msg,
        LXtObjectID		 item);
        LXxMETHOD(  LxResult,
ItemIcon) (
        LXtObjectID		  self,
        LXtObjectID		  item,
        const char		**icon);
        LXxMETHOD(  LxResult,
UIHints) (
        LXtObjectID		  self,
        const char		 *channelName,
        LXtObjectID		  hints);
        LXxMETHOD(  LxResult,
UIValueHints) (
        LXtObjectID		  self,
        const char		 *channelName,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Cookie) (
        LXtObjectID		  self,
        const char		 *channelName,
        const char		 *requestedFor,
        const char		**cookie);
} ILxChannelUI;

typedef struct vt_ILxChannelUI1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Enabled) (
        LXtObjectID		 self,
        const char		*channelName,
        LXtObjectID		 msg,
        LXtObjectID		 item,
        LXtObjectID		 chanRead);

        LXxMETHOD(  LxResult,
DependencyCount) (
        LXtObjectID		  self,
        const char		 *channelName,
        unsigned		 *count);

        LXxMETHOD(  LxResult,
DependencyByIndex) (
        LXtObjectID		  self,
        const char		 *channelName,
        unsigned		  index,
        LXtItemType		 *depItemType,
        const char		**depChannelName);

        LXxMETHOD(  LxResult,
ItemEnabled) (
        LXtObjectID		 self,
        LXtObjectID		 msg,
        LXtObjectID		 item);

        LXxMETHOD(  LxResult,
UIHints) (
        LXtObjectID		  self,
        const char		 *channelName,
        LXtObjectID		  hints);

        LXxMETHOD(  LxResult,
UIValueHints) (
        LXtObjectID		  self,
        const char		 *channelName,
        void			**ppvObj);

        LXxMETHOD(  LxResult,
Cookie) (
        LXtObjectID		  self,
        const char		 *channelName,
        const char		 *requestedFor,
        const char		**cookie);
} ILxChannelUI1;

/*
 * 
 * Given an item type, these returns the type's username (not the internal name)
 * and description, as defined in the ItemHelp configs.  If useSuper is true,
 * the supertye's information will be used if no information can be found for
 * the specific type.
 * 
 * This returns the name of the icon for this item type, optionally falling
 * back to its supertype.
 * 
 * Get the username of a mesh map given its internal name.  If addIcon is
 * true, the icon will be encoded into the buffer as a rich text string.
 * 
 * Get the username, description and toolitp of a channel given
 * an item (not an item type) and the channel index.
 */
typedef struct vt_ILxChannelUIService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ItemTypeName) (
        LXtObjectID		 self,
        LXtItemType		 typeID,
        unsigned		 useSuper,
        const char	       **name);

        LXxMETHOD(  LxResult,
ItemTypeDesc) (
        LXtObjectID		 self,
        LXtItemType		 typeID,
        unsigned		 useSuper,
        const char	       **name);
        LXxMETHOD(  LxResult,
ItemTypeIconText) (
        LXtObjectID		 self,
        LXtItemType		 typeID,
        unsigned		 useSuper,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
MeshMapUserName) (
        LXtObjectID		 self,
        const char		*name,
        unsigned		 addIcon,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
ChannelUserName) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 channel,
        char			*buf,
        unsigned		 len);

        LXxMETHOD(  LxResult,
ChannelDescription) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 channel,
        const char	       **desc);

        LXxMETHOD(  LxResult,
ChannelToolTip) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 channel,
        const char	       **tip);
} ILxChannelUIService;

/*
 * The item.channel command is used to show channels as controls in the UI.  For full
 * support the channels need to provide some way to tell the UI if the channel is enabled
 * or when the some state changes.  This is done by providing an ILxChannelUI interface
 * on the item type/package object.
 */

        #define LXu_CHANNELUI	"d04810aa-d88a-44ef-92c2-797374b42365"
        #define LXa_CHANNELUI	"channelui"
        // [export] ILxChannelUI cui
        // [local]  ILxChannelUI
        // [python] ILxChannelUI:UIValueHints	obj UIValueHints (command)


        #define LXu_CHANNELUI1	"BF1BFE3B-F0F5-490b-8961-721795DA57B4"
        #define LXa_CHANNELUI1	"channelui1"
        // [export] ILxUIChannelUI1 cui1
        // [local]  ILxUIChannelUI1

/*
 * The service interface provides some general methods for getting information about.
 */

        #define LXu_CHANNELUISERVICE	"3C3A2D98-7EF1-43F4-845C-39EF2D8F6D52"
        #define LXa_CHANNELUISERVICE	"channelUIservice"

#endif
