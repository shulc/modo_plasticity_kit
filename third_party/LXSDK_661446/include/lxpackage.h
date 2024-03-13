/*
 * LX package module
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
#ifndef LX_package_H
#define LX_package_H

typedef struct vt_ILxSceneEvalListener ** ILxSceneEvalListenerID;
typedef struct vt_ILxSceneEvalListener1 ** ILxSceneEvalListener1ID;
typedef struct vt_ILxSceneItemListener1 ** ILxSceneItemListener1ID;
typedef struct vt_ILxSceneItemListener2 ** ILxSceneItemListener2ID;
typedef struct vt_ILxSceneItemListener ** ILxSceneItemListenerID;
typedef struct vt_ILxSceneLoaderTarget ** ILxSceneLoaderTargetID;
typedef struct vt_ILxScene1 ** ILxScene1ID;
typedef struct vt_ILxItem1 ** ILxItem1ID;
typedef struct vt_ILxPackage ** ILxPackageID;
typedef struct vt_ILxAddChannel ** ILxAddChannelID;
typedef struct vt_ILxAddChannel1 ** ILxAddChannel1ID;
typedef struct vt_ILxItemCollection ** ILxItemCollectionID;
typedef struct vt_ILxPackageInstance ** ILxPackageInstanceID;
typedef struct vt_ILxAssemblyAlias ** ILxAssemblyAliasID;
typedef struct vt_ILxPackageInstance1 ** ILxPackageInstance1ID;
typedef struct vt_ILxPackage1 ** ILxPackage1ID;

#include <lxcom.h>
#include <lxvalue.h>
#include <lxvertex.h>
#include <lxitem.h>


/*
 * The following structure is used to store data during cinema loading. The item
 * type member indicates the root item type for the cinema, if any. For example,
 * this might be CIT_MESH when loading objects or CIT_CLIP when loading images.
 * When loading a cinema it is sometimes necessary for the cinema to be parented
 * to another cinema.
 */
typedef struct st_LXtSceneTarget {
        int			 itemType;
        int			 flags;
} LXtSceneTarget;


/*
 * The Scene Evaluation Listener sends events related to the evaluation of the scene.
 * The ChannelValue change signals that a channel value has changed. This is called
 * whenever any evaluated channel value changes.
 * 
 * 
 * It can be useful to know about a series of related evaluated channel changes.
 * These functions wrap the ChannelValue method call to signal the start and end
 * of a series of changes.
 */
typedef struct vt_ILxSceneEvalListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
ChannelValue) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index);
        LXxMETHOD( void,
ChannelPreValue) (
        LXtObjectID		 self);

        LXxMETHOD( void,
ChannelPostValue) (
        LXtObjectID		 self);
} ILxSceneEvalListener;

/*
 * The Scene Evaluation Listener sends events related to the evaluation of the scene.
 * Currently, this is only used for signaling changes to evaluated channel values,
 * and is called any time an evaluated channel value changes.
 */
typedef struct vt_ILxSceneEvalListener1 {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
ChannelValue) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned		 index);
} ILxSceneEvalListener1;

/*
 * Version 1, used only by recoil. Should be removed for 601.
 */
typedef struct vt_ILxSceneItemListener1 {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
SceneCreate) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
SceneDestroy) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
SceneFilename) (
        LXtObjectID		 self,
        LXtObjectID		 scene,
        const char		*filename);

        LXxMETHOD( void,
SceneClear) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
ItemPreChange) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
ItemPostDelete) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
ItemAdd) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemRemove) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemParent) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemChild) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemAddChannel) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemLocal) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemName) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemSource) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemPackage) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ChannelValue) (
        LXtObjectID		 self,
        const char		 *action,
        LXtObjectID		 item,
        unsigned		 index);
} ILxSceneItemListener1;

/*
 * Graph events, added in 501 SP1.
 */
typedef struct vt_ILxSceneItemListener2 {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
SceneCreate) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
SceneDestroy) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
SceneFilename) (
        LXtObjectID		 self,
        LXtObjectID		 scene,
        const char		*filename);

        LXxMETHOD( void,
SceneClear) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
ItemPreChange) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
ItemPostDelete) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
ItemAdd) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemRemove) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemParent) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemChild) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemAddChannel) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemLocal) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemName) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemSource) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemPackage) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ChannelValue) (
        LXtObjectID		 self,
        const char		 *action,
        LXtObjectID		 item,
        unsigned		 index);
        LXxMETHOD( void,
LinkAdd) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        LXtObjectID		 itemTo);

        LXxMETHOD( void,
LinkRemBefore) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        LXtObjectID		 itemTo);

        LXxMETHOD( void,
LinkRemAfter) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        LXtObjectID		 itemTo);

        LXxMETHOD( void,
LinkSet) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        LXtObjectID		 itemTo);

        LXxMETHOD( void,
ChanLinkAdd) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        unsigned		 chanFrom,
        LXtObjectID		 itemTo,
        unsigned		 chanTo);

        LXxMETHOD( void,
ChanLinkRemBefore) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        unsigned		 chanFrom,
        LXtObjectID		 itemTo,
        unsigned		 chanTo);

        LXxMETHOD( void,
ChanLinkRemAfter) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        unsigned		 chanFrom,
        LXtObjectID		 itemTo,
        unsigned		 chanTo);

        LXxMETHOD( void,
ChanLinkSet) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        unsigned		 chanFrom,
        LXtObjectID		 itemTo,
        unsigned		 chanTo);
} ILxSceneItemListener2;

/*
 * Item Tag events, added in 901.
 * 
 * User Channel events, added in 901.
 * This function is triggered whenever a channel is removed. It is the opposite of the
 * ItemAddChannel event.
 * 
 * 
 * This function is triggered whenever the name or the username of a channel changes.
 * 
 * This function is triggered whenever the default value of a channel is modified.
 * 
 * This function is triggered whenever the min/max of a channel is modified.
 * 
 * This function is triggered whenever a channel type is modified.
 */
typedef struct vt_ILxSceneItemListener {
        ILxUnknown	 iunk;
        LXxMETHOD( void,
SceneCreate) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
SceneDestroy) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
SceneFilename) (
        LXtObjectID		 self,
        LXtObjectID		 scene,
        const char		*filename);

        LXxMETHOD( void,
SceneClear) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
ItemPreChange) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
ItemPostDelete) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( void,
ItemAdd) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemRemove) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemParent) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemChild) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemAddChannel) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemLocal) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemName) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemSource) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ItemPackage) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( void,
ChannelValue) (
        LXtObjectID		 self,
        const char		 *action,
        LXtObjectID		 item,
        unsigned		 index);

        LXxMETHOD( void,
LinkAdd) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        LXtObjectID		 itemTo);

        LXxMETHOD( void,
LinkRemBefore) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        LXtObjectID		 itemTo);

        LXxMETHOD( void,
LinkRemAfter) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        LXtObjectID		 itemTo);

        LXxMETHOD( void,
LinkSet) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        LXtObjectID		 itemTo);

        LXxMETHOD( void,
ChanLinkAdd) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        unsigned		 chanFrom,
        LXtObjectID		 itemTo,
        unsigned		 chanTo);

        LXxMETHOD( void,
ChanLinkRemBefore) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        unsigned		 chanFrom,
        LXtObjectID		 itemTo,
        unsigned		 chanTo);

        LXxMETHOD( void,
ChanLinkRemAfter) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        unsigned		 chanFrom,
        LXtObjectID		 itemTo,
        unsigned		 chanTo);

        LXxMETHOD( void,
ChanLinkSet) (
        LXtObjectID		 self,
        const char		*graph,
        LXtObjectID		 itemFrom,
        unsigned		 chanFrom,
        LXtObjectID		 itemTo,
        unsigned		 chanTo);
        LXxMETHOD( void,
ItemTag) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD( void,
ItemRemoveChannel) (
        LXtObjectID		 self,
        LXtObjectID		 item);
        LXxMETHOD( void,
ItemChannelName) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 index);
        LXxMETHOD( void,
ItemChannelDefault) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 index);
        LXxMETHOD( void,
ItemChannelMinMax) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 index);
        LXxMETHOD( void,
ItemChannelType) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 index);
} ILxSceneItemListener;

/*
 * Loading a scene sets the target info to the root item type and some flags.
 */
typedef struct vt_ILxSceneLoaderTarget {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetRootType) (
        LXtObjectID		 self,
        const char		*typeName);

        LXxMETHOD( LxResult,
SetFlags) (
        LXtObjectID		 self,
        unsigned		 flags);

        LXxMETHOD( LxResult,
ClearFlags) (
        LXtObjectID		 self,
        unsigned		 flags);
} ILxSceneLoaderTarget;

/*
 * The ILxScene1 interface exposes a list of ILxItem1 objects, which can be accessed
 * by name or index.
 * - Lookup
 * 	Lookup an item by unique identifier (!?)
 * - ItemCount
 * 	Count items of given type. If type is NULL, all items are counted.
 * - ItemByIndex
 * 	Lookup item by index
 * 
 * - ItemByName
 * 	Lookup item by name.  Type is ignored.
 * 
 * - NewItem
 * 	Create a new item of the requested type.
 * 
 * 
 * Metadata can do good stuff... presumably.
 * 
 * Scenes can be tagged.
 * 
 * This stuff remains opaque.
 * NOTE: would be better to handle action through a separate interface defined in eval.
 * 
 * 
 */
typedef struct vt_ILxScene1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Lookup) (
        LXtObjectID		 self,
        const char		*id,
        void		       **ppvObj);

        LXxMETHOD( int,
ItemCount) (
        LXtObjectID		 self,
        const char		*type);

        LXxMETHOD( LxResult,
ItemByIndex) (
        LXtObjectID		 self,
        const char		*type,
        unsigned int		 index,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
ItemByName) (
        LXtObjectID		 self,
        const char		*type_is_ignored,
        const char		*name,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
NewItem) (
        LXtObjectID		 self,
        const char		*type,
        void		       **ppvObj);
        LXxMETHOD( void,
GetMeta) (
        LXtObjectID		 self,
        void			**xobj);

        LXxMETHOD( void,
SetMeta) (
        LXtObjectID		 self,
        LXtObjectID		 xobj);
        LXxMETHOD( const char *,
GetTag) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD( void,
SetTag) (
        LXtObjectID		 self,
        LXtID4			 type,
        const char		*tag);
        LXxMETHOD( LxResult,
Setup) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Edit) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Action) (
        LXtObjectID		 self,
        double			 time,
        void		       **ppvObj);

        LXxMETHOD( void,
ListenAction) (
        LXtObjectID		 self,
        LXtObjectID		 xobj);
        LXxMETHOD( LxResult,
LoadImage) (
        LXtObjectID		 self,
        const char		*name,
        int			*flags,
        LXtObjectID		 monitor,
        void		       **ppvObj);

} ILxScene1;

/*
 * NOTE: perhaps access channel list through ILxAttributes interface.  Could return default values.
 * - FindXfrmChannel
 * This returns an ILxItem1ID and channel index given a channel name.  If the transform item
 * does not yet exist, it will be created and returned.  The client is is responsible for
 * releasing the item.
 */
typedef struct vt_ILxItem1 {
        ILxUnknown	 iunk;
        LXxMETHOD( const char *,
Type) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
TestType) (
        LXtObjectID		 self,
        const char		*type);

        LXxMETHOD( const char *,
Ident) (
        LXtObjectID		 self);

        LXxMETHOD( const char *,
GetTag) (
        LXtObjectID		 self,
        unsigned int		 tag);

        LXxMETHOD( void,
SetTag) (
        LXtObjectID		 self,
        unsigned int		 type,
        const char		*tag);

        LXxMETHOD( int,
SubItemCount) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
SubItemByIndex) (
        LXtObjectID		 self,
        unsigned int		 index,
        void		       **ppvObj);

        LXxMETHOD( const char *,
Name) (
        LXtObjectID		 self);

        LXxMETHOD( void,
SetName) (
        LXtObjectID		 self,
        const char		*name);

        LXxMETHOD( void,
Root) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Parent) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( void,
SetParent) (
        LXtObjectID		 self,
        LXtObjectID		 parent,
        int			 pos);

        LXxMETHOD( int,
ChannelCount) (
        LXtObjectID		 self);

        LXxMETHOD( const char *,
ChannelName) (
        LXtObjectID		 self,
        unsigned int		 index);

        LXxMETHOD( LxResult,
ChannelIndex) (
        LXtObjectID		 self,
        const char		*name,
        unsigned int		*index);

        LXxMETHOD( LxResult,
FindXfrmChannel) (
        LXtObjectID		  self,
        const char		 *name,
        unsigned int		 *index,
        void			**ppvObj);
} ILxItem1;

/*
 * Packages are defined by a server interface that describes the
 * channels for the package and adds instances to items. The SetupChannels()
 * method is called once when the package is initialized to define the set
 * of channels common to all item with this package.  The Attach() method is
 * called for each item to assign as the package is being attached, and
 * should return an object implementing ILxPackageInstance.
 */
typedef struct vt_ILxPackage {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetupChannels) (
        LXtObjectID		 self,
        LXtObjectID		 addChan);

        LXxMETHOD( LxResult,
Attach) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
TestInterface) (
        LXtObjectID		 self,
        const LXtGUID		*guid);

        LXxMETHOD( LxResult,
PostLoad) (
        LXtObjectID		 self,
        LXtObjectID		 scene);

        LXxMETHOD( LxResult,
CollectItems) (
        LXtObjectID		 self,
        LXtObjectID		 collection,
        unsigned		 mode);
} ILxPackage;

/*
 * Channels are added to packages using an IlxAddChannel interface.  The
 * NewChannel() method starts a channel definition, and the rest of the
 * methods qualify it until the next channel is started.
 * If the base type for the channel is floating point, then the channel can
 * be made a gradient by calling this function. The gradient will have the
 * base type as output and this type as input.
 * 
 * If the base type for the channel is numeric then actions will be able to store
 * animated values for it. Likewise string channels can also have values stored
 * in the action, albeit constant. All other types are assumed to evaluation channels
 * only -- that is their values are only set during evaluation, not stored in actions.
 * Calling this method sets the storage type of the channel, which is the type of
 * value to be stored in the action, and can be different from the evaluation type.
 * 
 * Setting the vector type to one of the LXsCHANVEC defines will cause this one
 * channel definition to create multiple channels comprising the vector.
 * 
 * Numeric defaults can be set easily with these two methods.
 * 
 * Text hints are described in detail in their documentation.  There
 * is one important difference in handling min/max for angle channels (and
 * only angle channels):  they are specified as degrees*10000 instead of
 * radians*10000.  This allows for accurate representation of 45 degrees
 * and similar angles.  Other places that use text hints (like commands)
 * have access to another mechanism to set min/max that is not yet available
 * to channels, so they don't require this special case.
 * 
 * 
 * Default values for non-numeric storage channels can also be set by getting
 * the value object for the default.
 * 
 * This marks the channel as internal, hiding it from the user.
 */
typedef struct vt_ILxAddChannel {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
NewChannel) (
        LXtObjectID		 self,
        const char		*name,
        const char		*type);
        LXxMETHOD( LxResult,
SetGradient) (
        LXtObjectID		 self,
        const char		*inType);
        LXxMETHOD( LxResult,
SetStorage) (
        LXtObjectID		 self,
        const char		*stType);
        LXxMETHOD( LxResult,
SetVector) (
        LXtObjectID		 self,
        const char		*vecType);
        LXxMETHOD( LxResult,
SetDefault) (
        LXtObjectID		 self,
        double			 defFlt,
        int			 defInt);

        LXxMETHOD( LxResult,
SetDefaultVec) (
        LXtObjectID		 self,
        const double		*defVec);
        LXxMETHOD( LxResult,
SetHint) (
        LXtObjectID		 self,
        const LXtTextValueHint	*hint);
        LXxMETHOD( LxResult,
SetUserHint) (
        LXtObjectID		 self,
        const LXtTextValueHint	*hint);
        LXxMETHOD( LxResult,
SetDefaultObj) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD( void,
SetInternal) (
        LXtObjectID		 self);
} ILxAddChannel;

typedef struct vt_ILxAddChannel1 {
        ILxUnknown	 iunk;

        LXxMETHOD( LxResult,
NewChannel) (
        LXtObjectID		 self,
        const char		*name,
        const char		*type);

        LXxMETHOD( LxResult,
SetGradient) (
        LXtObjectID		 self,
        const char		*inType);

        LXxMETHOD( LxResult,
SetStorage) (
        LXtObjectID		 self,
        const char		*stType);

        LXxMETHOD( LxResult,
SetVector) (
        LXtObjectID		 self,
        const char		*vecType);

        LXxMETHOD( LxResult,
SetDefault) (
        LXtObjectID		 self,
        double			 defFlt,
        int			 defInt);

        LXxMETHOD( LxResult,
SetDefaultVec) (
        LXtObjectID		 self,
        const double		*defVec);

        LXxMETHOD( LxResult,
SetHint) (
        LXtObjectID		 self,
        const LXtTextValueHint	*hint);

        LXxMETHOD( LxResult,
SetDefaultObj) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( void,
SetInternal) (
        LXtObjectID		 self);
} ILxAddChannel1;

/*
 * Item collections are sets of items that can be expanded to include related items.
 * - Test
 * Test if an item is part of the collection
 * - Count, ByIndex
 * Enumerate through the items in the collection of a certain type.
 * 
 * - Add
 * Add an item to the collection.
 * 
 */
typedef struct vt_ILxItemCollection {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
Count) (
        LXtObjectID		 self,
        int			 type,
        unsigned		*count);

        LXxMETHOD( LxResult,
ByIndex) (
        LXtObjectID		 self,
        int			 type,
        unsigned		 index,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
Add) (
        LXtObjectID		 self,
        LXtObjectID		 item);
} ILxItemCollection;

/*
 * The implementation of a package (or item type) is a package instace object.
 * These are allocated by the Attach() method of the package interface, and
 * may optionally implement this interface to be informed of changes to the
 * item.
 * N5: init and cleanup are not really necessary. The arguments to init can
 * be sent to attach, and cleanup can be done in instance destroy.
 * - Initialize
 * This is called when package is attached to the item. The item is passed,
 * and for item types with supertypes the package instance for the supertype
 * package is also passed. The item is not yet part of the scene, so any
 * complex processing should wait until the Newborn() or Loaded() methods.
 * 
 * - SynthName
 * This allows the package to set the synthetic name for an item with no
 * explicitly set user name. Return NOTIMPL to get default behavior.
 * 
 * - DupType
 * Returns the item type code to use when an item of this type is instanced.
 * Return zero to use the same item type.
 * 
 * - TestParent
 * Can return LXe_FALSE to disallow this item from being parented to the
 * candidate parent.
 * 
 * - Newborn, Loading
 * One of these is called (depending on how the item was created) after the
 * item has been added to the scene. For item duplication or instancing the
 * Newborn() method gets the original item. This is only called the first
 * time, and so only undoable actions should be performed.
 * 
 * - AfterLoad
 * Called after load (or import) of the scene is complete.
 * 
 * - Add
 * Called after item is added to the scene. This will be called the first time
 * and any subsequent times caused by undos.
 * 
 * - Remove
 * Called as the item is being removed from the scene. This will be called the 
 * first time and any subsequent times caused by undos.
 * 
 * - Doomed
 * Called while the item is still part of the scene, but is destined to be
 * destroyed. This may allow the item to clean up any links or related items.
 * This is only called the first time so should make changes that can be undone.
 * 
 * - Cleanup
 * Called just before deletion.
 * 
 */
typedef struct vt_ILxPackageInstance {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        LXtObjectID		 super);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
SynthName) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( unsigned,
DupType) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
TestParent) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
Newborn) (
        LXtObjectID		 self,
        LXtObjectID		 original,
        unsigned		 flags);

        LXxMETHOD( LxResult,
Loading) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
AfterLoad) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Doomed) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Add) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
Remove) (
        LXtObjectID		 self);
} ILxPackageInstance;

/*
 * The test function is called with two items; the assembly and item within the
 * assembly that provides some unique functionality for the assembly. The function
 * should return LXe_TRUE if the assembly can be aliased by this AssemblyAlias, and
 * LXe_FALSE if it cannot.
 * 
 * The SuperType function should return the supertype of the item that will be
 * created for the alias. For example, if the assembly alias intends to act like
 * a channel modifier, the function should return the chanmodify supertype.
 * 
 */
typedef struct vt_ILxAssemblyAlias {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Test) (
        LXtObjectID		 self,
        LXtObjectID		 assembly,
        LXtObjectID		 other);
        LXxMETHOD(  LxResult,
Configure) (
        LXtObjectID		 self,
        LXtObjectID		 assembly,
        LXtObjectID		 other,
        LXtObjectID		 alias,
        const unsigned int	 change);
        LXxMETHOD(  LxResult,
SuperType) (
        LXtObjectID		 self,
        LXtItemType		*type);
        LXxMETHOD(  LxResult,
Flags) (
        LXtObjectID		 self,
        unsigned int		*flags);
} ILxAssemblyAlias;

typedef struct vt_ILxPackageInstance1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Initialize) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        LXtObjectID		 super);

        LXxMETHOD( void,
Cleanup) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
SynthName) (
        LXtObjectID		 self,
        char			*buf,
        unsigned		 len);

        LXxMETHOD( unsigned,
DupType) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
TestParent) (
        LXtObjectID		 self,
        LXtObjectID		 item);

        LXxMETHOD( LxResult,
Newborn) (
        LXtObjectID		 self,
        LXtObjectID		 original);

        LXxMETHOD( LxResult,
Loading) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
AfterLoad) (
        LXtObjectID		 self);

        LXxMETHOD( void,
Doomed) (
        LXtObjectID		 self);
} ILxPackageInstance1;

typedef struct vt_ILxPackage1 {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetupChannels) (
        LXtObjectID		 self,
        LXtObjectID		 addChan);

        LXxMETHOD( LxResult,
Attach) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD( LxResult,
TestInterface) (
        LXtObjectID		 self,
        const LXtGUID		*guid);

        LXxMETHOD( LxResult,
PostLoad) (
        LXtObjectID		 self,
        LXtObjectID		 scene);
} ILxPackage1;


        #define LXe_INCOMPATIBLE_SCENE	LXxFAILCODE(LXeSYS_ITEM,2)


        #define	LXu_SCENEEVALLISTENER	"7793643D-FA56-4198-963B-AE8FAC69F48D"
        // [export] ILxSceneEvalListener sel
        // [local]  ILxSceneEvalListener


        #define	LXu_SCENEEVALLISTENER1	"816116A8-B180-49E1-9984-0DE3531BDE55"


        #define LXu_SCENEITEMLISTENER1	"BCCD05F8-E560-11D7-B3B8-000393CE9680"


        #define LXu_SCENEITEMLISTENER2	"C72C641E-CDCD-431B-ADD9-D75554D656E1"


        #define	LXu_SCENEITEMLISTENER	"AFB67180-EC4F-4E9B-AAF1-67AA47097C29"
        // [export] ILxSceneItemListener sil
        // [local]  ILxSceneItemListener


        #define LXu_SCENELOADERTARGET	"A914B4F9-947C-4334-9D89-64BB8DC26BF6"
        // [local]  ILxSceneLoaderTarget

/*
 * Flags are all initially clear, but can be set to indicate status of the load.
 */

        #define LXf_SCENETARG_SUBCINE		1
        #define LXf_SCENETARG_NODEFAULTS	2
        #define LXf_SCENETARG_CINECHANGED	4
        #define LXf_SCENETARG_GONATIVE		8

/*
 * Loading images requires some special tricks. They must be created as sub-cinemas,
 * and in addition we want the option to ask the user for a replacement image, and
 * to search along the system search paths.
 * NOTE: this should be done through a service.
 * - LoadImage
 * 	Load the image specified by the path supplied. The two-way 'flags' argument
 * 	should be set with the combination of LXf_LOADIMG_ flags specifying what steps
 * 	may be taken to find the image. On successful return, the flags will be set
 * 	to indicate what steps were actually taken, in this way the client can determine
 * 	whether the image loaded differs from that specified due either to a user
 * 	replacement, or to expansion to an absolute path.
 * 
 */

        #define LXf_LOADIMG_SEARCH_PATHS	1
        #define LXf_LOADIMG_USER_REPLACE	2


        #define LXu_SCENE1	"4340A8FC-F984-4E04-A4BB-83931A6335AF"
        #define LXa_SCENE1	"scene"


        #define LXu_ITEM1	"5B14C8B6-29EF-473A-B1B3-568DFD9AE8D7"


        #define LXe_GRAPH_CYCLIC	LXxFAILCODE(LXeSYS_ITEM,1)


        #define LXu_PACKAGE	"01DA3920-484A-415F-AFF7-5A274B77AC3A"
        #define LXa_PACKAGE	"package2"
        // [export]  ILxPackage pkg
        // [local]   ILxPackage
        // [python]  ILxPackage:TestInterface	bool
        // [default] ILxPackage:TestInterface = LXe_FALSE

/*
 * Package servers can declare their supertype as a tag. The presense of this
 * tag promotes a package to a full item type. For root types with no supertype
 * the tag can be set to ".".
 */

        #define LXsPKG_SUPERTYPE	"super"

/*
 * Package servers may define their own graphs. This is a string of graph names
 * separated by semicolons. The name may also be followed by a plus-sign and any
 * of these single letter flags:
 * - i
 * Item graph, the default.
 * - c
 * Channel graph, mutually-exclusive with item.
 * 
 * - t
 * Tree rules, enforces that all elements in the graph have a single ancestor.
 * 
 * - a
 * Acyclic rules, enforces that there are no cycles in the graph. Superset of tree.
 * 
 * - N, X
 * Copy rules. Normally when items are copied their links are copied too. If 'N' is
 * set then no copying of links is done, and the owner of the graph is expected to
 * manage the links themself. If 'X' is set then links are copied between members of
 * a group copy, but not outside the group.
 * 
 * By default, the item list shows all locator items, but the LXsPKG_ITEMLIST_HIDE can be used to hide them from users.
 * The LXsPKG_ITEMLIST_ATTRIBUTE tag can be used to include the item as an attribute of the parent's item.
 * 
 */

        #define LXsPKG_ITEMLIST_HIDE      "pkg.itemListHide"
        #define LXsPKG_ITEMLIST_ATTRIBUTE "pkg.attribute"


        #define LXsPKG_GRAPHS		"pkg.graphs"

/*
 * Item type packages can suppress the normal ability to create from scratch. If the
 * item type requires a special command to create it, set this tag to "-".
 */

        #define LXsPKG_CREATECMD	"pkg.createCmd"
        #define LXs_PKG_NODIRECTCREATE	"-"

/*
 * Item type packages can also suppress the ability to allow another type to convert
 * to them. This is usually set in the same places as NODIRECTCREATE, but not always
 * (e.g. static meshes)
 */

        #define LXsPKG_CONVERTCMD	"pkg.convertCmd"
        #define LXs_PKG_DIRECTCONVERTOK	"-"

/*
 * Package servers can also be tagged as surface or mask item types.
 * The presense of this tag is enough, the value has no meaning.
 */

        #define LXsPKG_IS_MASK		"isMaskItem"

/*
 * Package servers can also be tagged with their shader context.
 * By default the context is the render item
 */

        #define LXsPKG_SHADER_CONTEXT		"shaderContext"

/*
 * We can also tag the serves as shader nodes, this is generally the case for all textures and shader effects
 */

        #define LXsPKG_SHADER_NODE		"shaderNode"

/*
 * Package servers can also be tagged as surface or mask item types.
 * The presense of this tag is enough, the value has no meaning.
 */

        #define LXsPKG_CREATE_INDIRECT	"createIndirect"

/*
 * Package servers can also be tagged as internal (core) MODO volumes to differentiate volumetric items from plugins and core.
 * The presense of this tag is enough, the value has no meaning.
 */

        #define LXsPKG_IS_COREVOLUME	"isCoreVolume"

/*
 *  
 * Package servers can also be tagged as allowing reads of non-evaluated channels.
 * When this tag is present for a surface item, the surface is allocated using the
 * channel read for the current state if deformers are not enabled, and the current
 * evaluation context if they are. Without the tag, surfaces will always be allocated
 * for the current evaluation context.
 * The presense of this tag is enough, the value has no meaning.
 * 
 */

        #define LXsPKG_NONEVALREAD	"allowNonEvalRead"


        #define LXu_ADDCHANNEL		"47C1E8A9-6C76-4068-BD4F-360015683CD0"

        // [local]  ILxAddChannel
        // [python] ILxAddChannel:SetDefaultObj		obj Unknown

        #define LXsCHANVEC_SCALAR	"V"
        #define LXsCHANVEC_XY		 LXsVECTYPE_XY
        #define LXsCHANVEC_XYZ		 LXsVECTYPE_XYZ
        #define LXsCHANVEC_RGB		 LXsVECTYPE_RGB
        #define LXsCHANVEC_RGBA		 LXsVECTYPE_RGBA
        #define LXsCHANVEC_UV		 LXsVECTYPE_UV
        #define LXsCHANVEC_UVW		 LXsVECTYPE_UVW

/*
 * This interface was retired in 10.2.
 */

        #define LXu_ADDCHANNEL1		"6E732ACC-AAA5-4695-B5DE-8059A2800554"

        // [local]  ILxAddChannel1
        // [python] ILxAddChannel1:SetDefaultObj		obj Unknown


        #define LXu_ITEMCOLLECTION	"8D37934E-F517-45F1-90F0-8C17F595DC7D"
        // [local]  ILxItemCollection
        // [python] ILxItemCollection:Test	bool
        // [python] ILxItemCollection:ByIndex	obj Item

/*
 * Packages can manipulate collections with their CollectItems() method. The
 * package then adds other items based on the mode.
 * - NONE
 * Can be used where a collection mode is used but none desired.
 * - IMPORT
 * Add items that should also be imported if the collection is an import. Note that
 * this same collection is also used for export, because an export is an import when
 * viewed from the other side.
 * 
 * - DEL_SHALLOW
 * Add items that must also be deleted if the collection is a deletion. This
 * is a shallow delete and should leave any items that the user might still want.
 * 
 * - DEL_DEEP
 * Add items that can also be deleted if the collection is a deletion. This is
 * a deep delete, so we want to get rid of anything that would be superfluous once
 * the main items are deleted.
 * 
 * - INSTANCES
 * This just gets all the instances of any items in the collection. The packages
 * aren't involved in this one; it's a core feature.
 * 
 */

        #define LXiCOLLECT_NONE		-1
        #define LXiCOLLECT_IMPORT	 0
        #define LXiCOLLECT_DEL_SHALLOW	 1
        #define LXiCOLLECT_DEL_DEEP	 2
        #define LXiCOLLECT_INSTANCES	 3

        #define LXxCOLLECT_IS_DELETE(m)	(m == LXiCOLLECT_DEL_SHALLOW || m == LXiCOLLECT_DEL_DEEP)


        #define LXu_PACKAGEINSTANCE	"68DD1902-E5AB-4591-BF93-B83C856D1908"
        #define LXa_PACKAGEINSTANCE	"packageInstance2"
        // [export]  ILxPackageInstance pins
        // [local]   ILxPackageInstance
        // [default] ILxPackageInstance:DupType    = 0
        // [default] ILxPackageInstance:TestParent = LXe_TRUE
        // [python]  ILxPackageInstance:TestParent	bool

        #define LXfNEWBORN_REPLACE	 0x01

/*
 * The assembly alias allows one item type to act as an alias for an alias. This
 * interface is added to any package that can act as an alias for an assembly.
 * The assembly alias interface is relatively simple; when an assembly alias is
 * created, the test function is called to see if the operation is allowed. If it
 * is, the alias is created and the configure function is called to perform any
 * required setup. When the properties of the assembly change, the configure
 * will be called again, describing the change.
 */

        #define LXa_ASSEMBLYALIAS	"assemblyAlias"
        #define LXu_ASSEMBLYALIAS	"1794FFAE-1E80-4211-B1E8-CE09B470B20C"
        // [export] ILxAssemblyAlias	alias

/*
 * The Configure function is used for sending events to the alias, allowing it to
 * configure it's properties, and initialize any state.
 * - ALIAS
 * The ALIAS event is sent when the item is initially aliased. This should only
 * be sent once when the alias is first created and can be used for any initial
 * setup.
 * - UNALIAS
 * The UNALIAS event is sent when the alias is about to be destroyed. This should
 * only be sent once when the alias is removed or deleted, and can be used for any
 * final cleanup.
 * 
 * - CHANNELS
 * The CHANNELS event is sent whenever the state of channels on the alias has changed
 * in some way. This could be channels being added, removed, or the hints on the
 * channel changing that define the username, min, max...etc.
 * 
 * - LOADPRESET
 * The LOADPRESET event is sent when the assembly alias is loaded from a preset.
 * The function can do whatever setup is needed to integrate the loaded alias item
 * into the scene.
 * 
 */

        #define LXf_ALIAS_ALIAS		0x001
        #define LXf_ALIAS_UNALIAS	0x002
        #define LXf_ALIAS_CHANNELS	0x004
        #define LXf_ALIAS_LOADPRESET	0x008

/*
 * The Flags function is called to query the assembly alias for flags.
 */

        #define	LXf_ALIAS_NEEDSOURCE	0x001

/*
 * Some item type codes are needed for the scene loading interface.
 * These MUST keep in sync with the CIT_ definitions!
 */

        #define LXi_CIT_GROUP	 	 1
        #define LXi_CIT_CLIP	 	 2
        #define LXi_CIT_LOCATOR	 	 3
        #define LXi_CIT_MESH	 	 4
        #define LXi_CIT_LIGHT	 	 5
        #define LXi_CIT_CAMERA	 	 6
        #define LXi_CIT_INSTANCE	 7
        #define LXi_CIT_T_LOC		 8
        #define LXi_CIT_RENDER		 9
        #define LXi_CIT_ENVIRON		 10
        #define LXi_CIT_BACKDROP	 11
        #define LXi_CIT_TLAYER		 12


        #define LXu_PACKAGEINSTANCE1	"09D603F7-CCF6-4A5C-B41C-021AC6C17A94"
        #define LXa_PACKAGEINSTANCE1	"packageInstance"


        #define LXu_PACKAGE1	"6383211E-2624-492e-8C4B-D06BB43886A7"
        #define LXa_PACKAGE1	"package"

#endif
