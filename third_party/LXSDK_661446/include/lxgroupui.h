/*
 * LX groupui module
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
#ifndef LX_groupui_H
#define LX_groupui_H

typedef struct vt_ILxGroupDest ** ILxGroupDestID;
typedef struct vt_ILxGroupMemberItemDest ** ILxGroupMemberItemDestID;
typedef struct vt_ILxGroupMemberChanDest ** ILxGroupMemberChanDestID;
typedef struct vt_ILxPoseItem ** ILxPoseItemID;

#include <lxcom.h>
#include <lxvalue.h>



/*
 * This method is used to obtain the Group item at the drop location.
 * The location of the drop is obtained with this method.
 * 
 */
typedef struct vt_ILxGroupDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Group) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( int,
Location) (
        LXtObjectID		 self);
} ILxGroupDest;

/*
 * This method is used to obtain the Group item that the source items are being dropped into.
 * This method is used to obtain the item in the Group that the source items are being dropped onto
 * or next to.
 * This will be NULL if the items are being dropped onto a Group item.
 * 
 * The location of the drop is obtained with this method.
 */
typedef struct vt_ILxGroupMemberItemDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Group) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Item) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( int,
Location) (
        LXtObjectID		 self);
} ILxGroupMemberItemDest;

/*
 * This method is used to obtain the Group item that the source channels are being dropped into.
 * This method is used to obtain the channel in the Group that the source channels are being dropped onto
 * or next to.
 * This will be NULL if the channels are being dropped onto a Group item.
 * 
 * The location of the drop is obtained with this method.
 * 
 */
typedef struct vt_ILxGroupMemberChanDest {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Group) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( LxResult,
Channel) (
        LXtObjectID		 self,
        void			**ppvObj);
        LXxMETHOD( int,
Location) (
        LXtObjectID		 self);
} ILxGroupMemberChanDest;

/*
 * The Create method should be used to create a new Pose Item. This will construct
 * the package local data, which creates an ActionClip.
 * 
 * The ActionClip of the Pose Item stores channel values. This method stores an integer
 * channel value in the ActionClip.
 * 
 * The ActionClip of the Pose Item stores channel values. This method stores a float
 * channel value in the ActionClip.
 * 
 * The ActionClip of the Pose Item stores channel values. This method retrieves 
 * an integer channel value that was stored in the ActionClip.
 * 
 * The ActionClip of the Pose Item stores channel values. This method retrieves 
 * an integer channel value that was stored in the ActionClip.
 */
typedef struct vt_ILxPoseItem {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Create)(
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SetInt)(
        LXtObjectID		 self,
        LXtObjectID		 item,	
        unsigned int		 channelIndex,
        int			 value);
        LXxMETHOD( LxResult,
SetFloat)(
        LXtObjectID		 self,
        LXtObjectID		 item,	
        unsigned int		 channelIndex,
        float			 value);
        LXxMETHOD( LxResult,
GetInt)(
        LXtObjectID		 self,
        LXtObjectID		 item,	
        unsigned int		 channelIndex,
        int			*value);
        LXxMETHOD( LxResult,
GetFloat)(
        LXtObjectID		 self,
        LXtObjectID		 item,	
        unsigned int		 channelIndex,
        float			*value);
} ILxPoseItem;


        #define LXu_GROUPDEST			"14B16A73-F0A8-459A-B1FD-7850DF36801C"
        #define LXa_GROUPDEST			"groupDest"
        // [local]  ILxGroupDest
        // [export] ILxGroupDest grpd
        // [python] ILxGroupDest:Group	obj Item


        #define LXu_GROUPMEMBERITEMDEST		"15329747-C092-475A-B188-11A19A151886"
        #define LXa_GROUPMEMBERITEMDEST		"groupMemberItemDest"
        //[local]  ILxGroupMemberItemDest
        //[export] ILxGroupMemberItemDest	 grpmid


        #define LXu_GROUPMEMBERCHANDEST		"C52AB199-2410-4698-B26C-45FA024CBAE9"
        #define LXa_GROUPMEMBERCHANDEST		"groupMemberChanDest"
        //[local]  ILxGroupMemberChanDest
        //[export] ILxGroupMemberChanDest	 grpmcd

/*
 * The PoseItem interface provides services for operating on a pose action clip. 
 */

        #define LXu_POSEITEM		"73582252-0845-4B33-9000-596C7865675F"
        // [local]  ILxPoseItem

#endif
