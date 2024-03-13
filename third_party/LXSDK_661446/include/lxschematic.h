/*
 * LX schematic module
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
#ifndef LX_schematic_H
#define LX_schematic_H

typedef struct vt_ILxSchematicConnection ** ILxSchematicConnectionID;
typedef struct vt_ILxSchematicConnection3 ** ILxSchematicConnection3ID;
typedef struct vt_ILxSchematicConnection2 ** ILxSchematicConnection2ID;
typedef struct vt_ILxSchematicConnection1 ** ILxSchematicConnection1ID;
typedef struct vt_ILxSchemaDest ** ILxSchemaDestID;
typedef struct vt_ILxSchematicGroup ** ILxSchematicGroupID;
typedef struct vt_ILxSchematicNode ** ILxSchematicNodeID;
typedef struct vt_ILxSchematicNodeConnection ** ILxSchematicNodeConnectionID;
typedef struct vt_ILxSchematicNodeChannel ** ILxSchematicNodeChannelID;

#include <lxcom.h>
#include <lxvalue.h>



/*
 * A SchematicConnection server manages a particular connection point for
 * inter-item relations. Normally this is a graph link but can be any type of
 * relation that the client wants to implement. The name of the connection point
 * (the text shown on the node) is the name of the server.
 * This method is called for every item displayed in the schematic to determine if
 * and how it supports this connection point. Failure or a zero falgs value means
 * that the item does not have a connection.
 * 
 * Given a pair of items, this function returns LXe_TRUE if the connection is allowed.
 * The 'to' item is the one with the connection point, and is assumed to have valid
 * item flags, above.
 * 
 * This function returnes LXe_TRUE if the connection is allowed between an item and
 * an item type.
 * 
 * This returns the name of a single graph. For connection points that can be described
 * by one graph the graph name is sufficient for schematic to do all the legwork.
 * Connecting adds a link from the source to the target in the graph, and drawing just
 * enumerates the graph.
 * This must be implemented (to traverse output links), but all connections will be
 * handled fully by the server (as given by the methods below) as long as Count() is
 * implemented and returns LXe_OK.
 * 
 * 
 * For connections not given by a single graph, the server has to provide the list of
 * connections coming into an item presenting a connection point. These are given by
 * a count and items by index.
 * 
 * Servers that enumerate the links themselves also need to manage creating and
 * breaking links. The schematic view will call these methods from a context where
 * undos are allowed.
 * 
 * This method is called once to determine the minimum flags that will be used for
 * any item. Certain flags can vary by item type, such as LXfSCON_SINGLE, LXfSCON_MULTIPLE
 * and LXfSCON_ORDERED, but the flags LXfSCON_USESERVER and LXfSCON_REVERSE must be
 * consistent for all item types.
 * LXfSCON_PERITEM should be added as a base flag if the flags can change over time.
 * If set, ItemFlagsValid() will be called before any schematic draw.
 * 
 * Returning these flags allows us to initialize the server list once for all items.
 * 
 * If this method is not implemented, LXfSCON_USESERVER and LXfSCON_REVERSE are assumed
 * to be 0.
 * 
 * 
 * When a graph should only be present on *some* items of a particular type, this is called
 * for each item. When rejecting the graph for the element, this should return 0, otherwise
 * it should typically return the same flags as returned by ItemFlags.
 * 
 * When per-item flags are used, there are circumstances under which the flags for an item
 * may change (e.g. a Dynamics package may be added or removed from a mesh). When this
 * happens, any cached per-item data would need to be refreshed. This method is called
 * before any schematic redraw, and if implemented, should return 1 if all item flags are
 * still valid, or 0 if not.
 * This function will only be called once before validating, so once called, you can
 * restore your internal valid flag.
 * 
 * 
 * The following "Channel" functions are used for Schematic Conections that work with
 * connections between Items and Channels.
 * Given a 'from' Item and Channel index and a 'to' Item and Channel index, this function
 * returns LXe_TRUE if the connection is allowed.
 * 
 * 
 * Called to determine whether the connection should be an input or output.
 * The type should be set to LXvSCON_INPUT or LXvSCON_OUTPUT.
 * 
 * These functions are used to iterate over the Channel connections into or
 * out of an Item or Channel.
 * 
 * Servers that enumerate the links themselves also need to manage creating and
 * breaking links. The schematic view will call these methods from a context where
 * undos are allowed.
 * 
 * TODO: Description
 */
typedef struct vt_ILxSchematicConnection {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ItemFlags) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*flags);
        LXxMETHOD(  LxResult,
AllowConnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to);
        LXxMETHOD(  LxResult,
AllowConnectType) (
        LXtObjectID		 self,
        LXtObjectID		 to,
        unsigned int		 type);
        LXxMETHOD(  LxResult,
GraphName) (
        LXtObjectID		 self,
        const char	       **name);
        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*count);

        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Connect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to,
        int			 toIndex);

        LXxMETHOD(  LxResult,
Disconnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to);
        LXxMETHOD(  int,
BaseFlags) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
PerItemFlags) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*flags);
        LXxMETHOD(  int,
ItemFlagsValid) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
ChannelAllowConnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        int			 fromIndex,
        LXtObjectID		 to,
        int			 toIndex);
        LXxMETHOD(  LxResult,
ChannelIOType) (
        LXtObjectID		 self,
        unsigned int		*ioType);
        LXxMETHOD(  LxResult,
ChannelCount) (
        LXtObjectID		 self,
        LXtObjectID		 xItem,
        int			 fromIndex,
        unsigned		*count);

        LXxMETHOD(  LxResult,
ChannelByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 xItem,
        int			 fromIndex,
        unsigned		 index,
        void		       **ppvObj,
        int			*toIndex);
        LXxMETHOD(  LxResult,
ChannelConnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        int			 fromIndex,
        LXtObjectID		 to,
        int			 toIndex);

        LXxMETHOD(  LxResult,
ChannelDisconnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        int			 fromIndex,
        LXtObjectID		 to,
        int			 toIndex);
        LXxMETHOD(  LxResult,
PresetBrowserHash) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        const char		**hash);
} ILxSchematicConnection;

typedef struct vt_ILxSchematicConnection3 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ItemFlags) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*flags);

        LXxMETHOD(  LxResult,
AllowConnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to);

        LXxMETHOD(  LxResult,
AllowConnectType) (
        LXtObjectID		 self,
        LXtObjectID		 to,
        unsigned int		 type);
        
        LXxMETHOD(  LxResult,
GraphName) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*count);

        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Connect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to,
        int			 toIndex);

        LXxMETHOD(  LxResult,
Disconnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to);

        LXxMETHOD(  int,
BaseFlags) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
PerItemFlags) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*flags);

        LXxMETHOD(  int,
ItemFlagsValid) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
ChannelAllowConnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        int			 fromIndex,
        LXtObjectID		 to,
        int			 toIndex);

        LXxMETHOD(  LxResult,
ChannelIOType) (
        LXtObjectID		 self,
        unsigned int		*ioType);

        LXxMETHOD(  LxResult,
ChannelCount) (
        LXtObjectID		 self,
        LXtObjectID		 xItem,
        int			 fromIndex,
        unsigned		*count);

        LXxMETHOD(  LxResult,
ChannelByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 xItem,
        int			 fromIndex,
        unsigned		 index,
        void		       **ppvObj,
        int			*toIndex);

        LXxMETHOD(  LxResult,
ChannelConnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        int			 fromIndex,
        LXtObjectID		 to,
        int			 toIndex);

        LXxMETHOD(  LxResult,
ChannelDisconnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        int			 fromIndex,
        LXtObjectID		 to,
        int			 toIndex);
} ILxSchematicConnection3;

typedef struct vt_ILxSchematicConnection2 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ItemFlags) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*flags);

        LXxMETHOD(  LxResult,
AllowConnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to);

        LXxMETHOD(  LxResult,
AllowConnectType) (
        LXtObjectID		 self,
        LXtObjectID		 to,
        unsigned int		 type);
        
        LXxMETHOD(  LxResult,
GraphName) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*count);

        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Connect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to,
        int			 toIndex);

        LXxMETHOD(  LxResult,
Disconnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to);

        LXxMETHOD(  int,
BaseFlags) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
PerItemFlags) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*flags);

        LXxMETHOD(  int,
ItemFlagsValid) (
        LXtObjectID		 self);
} ILxSchematicConnection2;

typedef struct vt_ILxSchematicConnection1 {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ItemFlags) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*flags);

        LXxMETHOD(  LxResult,
AllowConnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to);

        LXxMETHOD(  LxResult,
GraphName) (
        LXtObjectID		 self,
        const char	       **name);

        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*count);

        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index,
        void		       **ppvObj);

        LXxMETHOD(  LxResult,
Connect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to,
        int			 toIndex);

        LXxMETHOD(  LxResult,
Disconnect) (
        LXtObjectID		 self,
        LXtObjectID		 from,
        LXtObjectID		 to);

        LXxMETHOD(  int,
BaseFlags) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
PerItemFlags) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		*flags);

        LXxMETHOD(  int,
ItemFlagsValid) (
        LXtObjectID		 self);
} ILxSchematicConnection1;

/*
 * This method returns the type of scheamtic view
 * This method is used to obtain the mouse position in the schematic
 * 
 * This method is used to obtain the Group (assembly, workspace) at the drop location.
 * 
 * This method is used to obtain the item being dropped onto, it any.
 * 
 * This method is used to obtain the schematic node being dropped onto, it any.
 * 
 * This method is used to obtain the item channel being dropped onto, it any.
 * 
 * This method is used to obtain the item graph being dropped onto, it any.
 * 
 * This method is used to obtain the schematic link being dropped onto, it any.
 */
typedef struct vt_ILxSchemaDest {
        ILxUnknown	 iunk;
        LXxMETHOD( int,
ViewType) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Position) (
        LXtObjectID		 self,
        LXtVector		 pos);
        LXxMETHOD( LxResult,
Group) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Item) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Node) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Channel) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Graph) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Link) (
        LXtObjectID		 self,
        void			**ppvObj);
} ILxSchemaDest;

/*
 * This returns the group item associated with a schematic group interface.
 * 
 * This returns LXe_TRUE or LXe_FALSE if the group is a workspace.
 * 
 * This function adds an item to the schematic group. If successful, the node is
 * returned indirectly as an ILxSchematicNode.
 * 
 * This function removes an item from the schematic group.
 * 
 * This function returns the number of schematic nodes in the workspace.
 * 
 * This function returns a schematic node by index. The returned object is of the type
 * ILxSchematicNode.
 * 
 * This function returns an assembly input node. The returned object is of the type
 * ILxSchematicNode.
 * 
 * This function returns an assembly output node. The returned object is of the type
 * ILxSchematicNode.
 */
typedef struct vt_ILxSchematicGroup {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Group) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
IsWorkspace) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
AddItem) (
        LXtObjectID		  self,
        LXtObjectID		  item,
        void			**ppvObj);
        LXxMETHOD(  void,
RemoveItem) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD(  LxResult,
NodeCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
NodeByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
InputNode) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
OutputNode) (
        LXtObjectID		  self,
        void			**ppvObj);
} ILxSchematicGroup;

/*
 * This returns the group item that the node belongs to.
 * This returns the item that the node represents.
 * 
 * This function adds a channel to a schematic node. The index provided should be the index
 * of the channel on the item this node represents. If the channel already exists on another
 * node, it will be moved.
 * 
 * Removes a channel from a schematic node. The index provided should be the index of the
 * channel on the item this node represents.
 * 
 * This function returns the number of channels on a schematic node item.
 * 
 * This function returns a SchematicNodeChannel object representing a specific channel by
 * index. The type argument should be one of the LXi_SCHMNODE values, and specifies
 * whether the input connection or the output connection is requested. The function will
 * return NOTAVAILABLE if no input or output connection is available for the requested
 * channel.
 * 
 * This function returns the number of item connections that are exposed on a schematic
 * node.
 * 
 * This function returns a SchematicNodeConnection object representing a specific item
 * connection by index. The type argument should be one of the LXi_SCHMNODE values, and
 * specifies whether the input connection or the output connection is requested. The function
 * will return NOTAVAILABLE if no input or output connection is available.
 * 
 * A single "root" node that is presented to the user may be constructed from multiple
 * sub-nodes, each representing different item types. For example, a locator item can have
 * any number of associated transform items, but these may be presented to the user as a
 * single node.
 * This function returns LXe_TRUE if the node is a root node, otherwise it returns LXe_FALSE.
 * 
 * 
 * Given any sub-node, this function returns the root node.
 * 
 * Given any node, this function returns the number of associated sub-nodes.
 * 
 * Given any node, this function allows the sub-nodes to be accessed by index. The
 * returned object is of the type ILxSchematicNode.
 * 
 * This function returns the position of the schematic node. If this schematic node is
 * a sub-node, the function will fail.
 * 
 * This function allows the position of the schematic node to be set. If this schematic
 * node is a sub-node, the function will fail.
 * 
 * This function returns the size of the schematic node. This function will return the
 * size of this specific node only, not including any sub-nodes.
 * 
 * This function returns the size of a root schematic node. If this schematic node is
 * a sub-node, the function will fail.
 * 
 * This function returns LXe_TRUE or LXe_FALSE if the node is expanded to show connections.
 */
typedef struct vt_ILxSchematicNode {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Group) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
AddChannel) (
        LXtObjectID		 self,
        unsigned int		 index);
        LXxMETHOD(  LxResult,
RemoveChannel) (
        LXtObjectID		 self,
        unsigned int		 index);
        LXxMETHOD(  LxResult,
ChannelCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
ChannelByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        unsigned int		  type,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
ConnectionCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
ConnectionByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        unsigned int		  type,
        void			**ppvObj);
        LXxMETHOD (  LxResult,
IsRoot) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
RootNode) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
SubNodeCount) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
SubNodeByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Position) (
        LXtObjectID		 self,
        double			*x,
        double			*y);
        LXxMETHOD(  LxResult,
SetPosition) (
        LXtObjectID		 self,
        double			 x,
        double			 y);
        LXxMETHOD(  LxResult,
Size) (
        LXtObjectID		 self,
        double			*width,
        double			*height);
        LXxMETHOD(  LxResult,
AbsoluteSize) (
        LXtObjectID		 self,
        double			*width,
        double			*height);
        LXxMETHOD(  LxResult,
Expanded) (
        LXtObjectID		 self);
} ILxSchematicNode;

/*
 * 
 * This function returns the schematic node that this schematic node connection belongs to.
 * 
 * The Count function will return the number of items connected to the schematic connection.
 * Currently, only input connections can be enumerated. Attempts to enumerate over output
 * connections will return NOTAVAILABLE.
 * 
 * The ByIndex function will return the SchematicNodeConnection on another item, that this
 * schematic node connection is connected to.
 * 
 * The position function will return the absolute position of the schematic connection in
 * the workspace. If the graph supports multiple connections, the position of a specific
 * connection by index can be requested.
 */
typedef struct vt_ILxSchematicNodeConnection {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		 self,
        unsigned int		*flags);
        LXxMETHOD(  LxResult,
Node) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Position) (
        LXtObjectID		 self,
        unsigned int		 index,
        double			*x,
        double			*y);
} ILxSchematicNodeConnection;

/*
 * 
 * This function returns the schematic node that this schematic node channel belongs to.
 * 
 * This function returns the channel index for this schematic node channel.
 * 
 * The Count function will return the number of channels connected to the schematic
 * connection.
 * 
 * The ByIndex function will return the SchematicNodeChannel on another item, that this
 * schematic node channel is connected to.
 * 
 * The position function will return the absolute position of the schematic connection in
 * the workspace.
 */
typedef struct vt_ILxSchematicNodeChannel {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		 self,
        unsigned int		*flags);
        LXxMETHOD(  LxResult,
Node) (
        LXtObjectID		  self,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Index) (
        LXtObjectID		 self,
        unsigned int		*index);
        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        unsigned int		*count);
        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		  self,
        unsigned int		  index,
        void			**ppvObj);
        LXxMETHOD(  LxResult,
Position) (
        LXtObjectID		 self,
        double			*x,
        double			*y);
} ILxSchematicNodeChannel;

/*
 * If any flags are set they define the type of connection this item allows.
 * - SINGLE
 * it can have a single incoming connection from one other item.
 * - MULTIPLE
 * it can have multiple incoming connection from one or more item.
 * 
 * - ORDERED
 * for multiple connections, the order of the connections is important.
 * 
 * - REVERSE
 * This server uses normal graphs, but reverses the to/from relationships. It is up to
 * the server to set this flag even if it is managing the connections itself, otherwise
 * link tool tips or missing nodes may not be properly identified.
 * 
 * - PERITEM
 * Typically an item type will have the same set of relationships for all items of that type,
 * e.g. all "Replicator" items will have "Particle Source" and "Protopyes" relationships. In some cases,
 * however, it might be desirable to have a relationship like "Dynamics" only be present for certain
 * mesh items, but not all. In this case LXfSCON_PERITEM would be used, and PerItemFlags would be
 * called for each item.
 * 
 * - NOLISTS
 * Schematic Connections can be displayed in list views, such as the deformer list.
 * This flag prevents the schematic connection from being displayed in list views,
 * limiting it to the schematic viewport only.
 * 
 * - CHANNEL
 * This flag indicates that Schematic Connections can be made between Items and Channels.
 * 
 * - USESERVER
 * This type of connection supports multiple relationships, and fully
 * implements the advanced methods such as Count() & ByIndex(). This
 * flag is typically combined with the flags above.
 * 
 * - LXfSCON_ISALIAS
 * For internal use only.
 * 
 * - LXfSCON_FULLHEIGHT
 * Multiple connection rows will be drawn full height.
 * 
 */

        #define LXfSCON_SINGLE		 0x001
        #define LXfSCON_MULTIPLE 	 0x002
        #define LXfSCON_ORDERED 	 0x004
        #define LXfSCON_REVERSE 	 0x008
        #define LXfSCON_PERITEM 	 0x010
        #define LXfSCON_NOLISTS		 0x020
        #define LXfSCON_CHANNEL		 0x040
        #define LXfSCON_USESERVER	 0x080
        #define LXfSCON_ISALIAS		 0x100
        #define LXfSCON_FULLHEIGHT	 0x200
        
        #define LXvSCON_INPUT		 0
        #define LXvSCON_OUTPUT		 1


        #define LXu_SCHEMATICCONNECTION	"3578D79B-798C-4250-9538-CF7EB939BB6E"
        #define LXa_SCHEMATICCONNECTION	"schematicConnection.v4"
        // [local]   ILxSchematicConnection
        // [export]  ILxSchematicConnection schm
        // [default] ILxSchematicConnection:BaseFlags		= 0
        // [default] ILxSchematicConnection:ItemFlagsValid	= 1
        // [python]  ILxSchematicConnection:ByIndex		obj Item
        // [python]  ILxSchematicConnection:AllowConnect	bool
        // [python]  ILxSchematicConnection:AllowConnectType	bool
        
        // [python]  ILxSchematicConnection:ChannelByIndex		obj Item
        // [python]  ILxSchematicConnection:ChannelAllowConnect		bool

/*
 * // Old Schematic Connection Interface (< 15.2)
 */

        #define LXu_SCHEMATICCONNECTION3	"38BB9ED8-F21E-40C1-B118-E766F2907E4F"
        #define LXa_SCHEMATICCONNECTION3	"schematicConnection.v3"
        // [local]   ILxSchematicConnection3
        // [export]  ILxSchematicConnection3 schm
        // [default] ILxSchematicConnection3:BaseFlags		= 0
        // [default] ILxSchematicConnection3:ItemFlagsValid	= 1
        // [python]  ILxSchematicConnection3:ByIndex		obj Item
        // [python]  ILxSchematicConnection3:AllowConnect	bool
        // [python]  ILxSchematicConnection3:AllowConnectType	bool

/*
 * // Old Schematic Connection Interface (< 14.2)
 */

        #define LXu_SCHEMATICCONNECTION2	"7E238C0E-0D64-44ed-A780-13D25A2482D3"
        #define LXa_SCHEMATICCONNECTION2	"schematicConnection.v2"
        // [local]   ILxSchematicConnection2
        // [export]  ILxSchematicConnection2 schm
        // [default] ILxSchematicConnection2:BaseFlags		= 0
        // [default] ILxSchematicConnection2:ItemFlagsValid	= 1
        // [python]  ILxSchematicConnection2:ByIndex		obj Item
        // [python]  ILxSchematicConnection2:AllowConnect	bool
        // [python]  ILxSchematicConnection2:AllowConnectType	bool

/*
 * // Old Schematic Connection Interface (< MODOP)
 */

        #define LXu_SCHEMATICCONNECTION1	"5AC0A075-72B7-4935-8DA5-588DF7999069"
        #define LXa_SCHEMATICCONNECTION1	"schematicConnection"
        // [local]   ILxSchematicConnection1
        // [export]  ILxSchematicConnection1 schm
        // [default] ILxSchematicConnection1:BaseFlags = 0
        // [default] ILxSchematicConnection1:ItemFlagsValid = 1
        // [python]  ILxSchematicConnection1:ByIndex		obj Item
        // [python]  ILxSchematicConnection1:AllowConnect	bool

/*
 * The ILxSchemaDrop interface is used when dropping items into a schematic view. This interface can be
 * used to identify the group (assembly, workspace) into which the source was dropped, as well as the
 * item, node, channel or graph that it may have been dropped on top of.
 * In addition, this also suports the ILxItem, ILxGroupDest & ILxChannelDest interfaces for alternate
 * drop actions.
 */

        #define LXu_SCHEMADEST			"AA362F0B-DC2F-4480-82FF-32D38FD57F4F"
        #define LXa_SCHEMADEST			"shemaDest"
        // [local]  ILxSchemaDest
        // [export] ILxSchemaDest		schmd
        // [python] ILxSchemaDest:Group		obj Item
        // [python] ILxSchemaDest:Item		obj Item
        // [python] ILxSchemaDest:Node		obj Item


enum SchemaViewTypes {
        SCHEMAVIEW_Workspace	=  0,		// schematic view of a workspace
        SCHEMAVIEW_Overview	=  1,		// Hierarchical view of an assembly or all assemblies (if Group returns NULL)
        SCHEMAVIEW_Assembly	=  2,		// schematic view of an assembly
};

/*
 * Group items can be queried for a schematic group interface. This interface provides
 * information about the nodes it contains, and allows the properties of the schematic
 * to be queried and manipulated.
 */

        #define	LXu_SCHEMATICGROUP			"FD5B73D1-C9E2-44C2-8D8D-23EE7706B3AB"
        #define LXa_SCHEMATICGROUP			"schematicgroup"
        // [local]  ILxSchematicGroup
        // [python] ILxSchematicGroup:Group		obj Item
        // [python] ILxSchematicGroup:AddItem		obj SchematicNode
        // [python] ILxSchematicGroup:NodeByIndex	obj SchematicNode
        // [python] ILxSchematicGroup:InputNode		obj SchematicNode
        // [python] ILxSchematicGroup:OutputNode	obj SchematicNode
        // [python] ILxSchematicGroup:IsWorkspace	bool

/*
 * Schematic Groups contain nodes, these nodes represent items, and may have properties
 * such as exposed channels, exposed graphs, input connections, output connections, as
 * well as visual properties such as a size, position and thumbnail. This interface
 * allows the properties of the node to be queried and manipulated.
 */

        #define	LXu_SCHEMATICNODE			"686F59FF-1E3F-4599-ADE0-E3613C483D38"
        #define LXa_SCHEMATICNODE			"schematicnode"
        // [local]  ILxSchematicNode
        // [const]  ILxSchematicNode:ChannelCount
        // [const]  ILxSchematicNode:SubNodeCount
        // [python] ILxSchematicNode:Group		obj Item
        // [python] ILxSchematicNode:Item		obj Item
        // [python] ILxSchematicNode:RootNode		obj SchematicNode
        // [python] ILxSchematicNode:SubNodeByIndex	obj SchematicNode
        // [python] ILxSchematicNode:IsRoot		bool
        // [python] ILxSchematicNode:ChannelByIndex	obj SchematicNodeChannel
        // [python] ILxSchematicNode:ConnectionByIndex	obj SchematicNodeConnection
        // [python] ILxSchematicNode:Expanded		bool

/*
 * - INPUT
 * Used for requesting an input channel or graph for a node.
 * - OUTPUT
 * Used for requesting an output channel or graph for a node.
 */

        #define	LXi_SCHMNODE_INPUT	 0
        #define LXi_SCHMNODE_OUTPUT	 1

/*
 * Schematic Nodes connect to each other using links. These links can either represent
 * item to item connections or channel to channel connections. The SchematicNodeConnection
 * interface allows item connections to be walked from one node to another.
 */

        #define	LXu_SCHEMATICNODECONNECTION		"5E015AAB-E069-4676-8F04-C7C8F88181A5"
        #define LXa_SCHEMATICNODECONNECTION		"schematicnodeconnection"
        // [local]  ILxSchematicNodeConnection
        // [const]  ILxSchematicNodeConnection:Flags
        // [const]  ILxSchematicNodeConnection:Count
        // [python] ILxSchematicNodeConnection:Node	obj SchematicNode
        // [python] ILxSchematicNodeConnection:ByIndex	obj SchematicNodeConnection

/*
 * The flags method returns flags that represent the state of the schematic connection.
 * It will be a bit mask containing some of the following.
 * - INPUT
 * The connection is an input connection and allows incoming connections from items.
 * - OUTPUT
 * The connection is an output connection and allows outgoing connections to items.
 * 
 * - MULTIPLE
 * The connection allows multiple items to be connected.
 * 
 * - ORDERED
 * The connection allows multiple items to be connected in a specific order. The MULTIPLE
 * flag will always be set is ORDERED is set.
 * 
 * - EXPANDED
 * If the connection supports multiple ordered connections, the connection is expanded to
 * display the multiple connections and allow them to be reordered.
 * 
 */

        #define LXf_SCHMNODECONN_INPUT		 0x01
        #define LXf_SCHMNODECONN_OUTPUT		 0x02
        #define LXf_SCHMNODECONN_MULTIPLE	 0x04
        #define LXf_SCHMNODECONN_ORDERED	 0x08
        #define LXf_SCHMNODECONN_EXPANDED	 0x10

/*
 * Schematic Nodes connect to each other using links. These links can either represent
 * item to item connections or channel to channel connections. The SchematicNodeChannel
 * interface allows channel connections to be walked from one node to another.
 */

        #define	LXu_SCHEMATICNODECHANNEL		"322555CC-D635-48A4-BCDB-AE86CCFE29CF"
        #define LXa_SCHEMATICNODECHANNEL		"schematicnodechannel"
        // [local]  ILxSchematicNodeChannel
        // [const]  ILxSchematicNodeChannel:Flags
        // [const]  ILxSchematicNodeChannel:Index
        // [const]  ILxSchematicNodeChannel:Count
        // [python] ILxSchematicNodeChannel:Node	obj SchematicNode
        // [python] ILxSchematicNodeChannel:ByIndex	obj SchematicNodeChannel

/*
 * The flags method returns flags that represent the state of the schematic channel
 * connection. It will be a bit mask containing some of the following.
 * - INPUT
 * The connection is an input connection and allows incoming connections from channels.
 * - OUTPUT
 * The connection is an output connection and allows outgoing connections to channels.
 * 
 * - MULTIPLE
 * The connection allows multiple channels to be connected.
 * 
 */

        #define LXf_SCHMNODECHAN_INPUT		 0x01
        #define LXf_SCHMNODECHAN_OUTPUT		 0x02
        #define LXf_SCHMNODECHAN_MULTIPLE	 0x04

#endif
