/*
 * LX chanmod module
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
#ifndef LX_chanmod_H
#define LX_chanmod_H

typedef struct vt_ILxChannelModItem ** ILxChannelModItemID;
typedef struct vt_ILxChannelModifier ** ILxChannelModifierID;
typedef struct vt_ILxChannelModManager ** ILxChannelModManagerID;
typedef struct vt_ILxChannelModOperator ** ILxChannelModOperatorID;
typedef struct vt_ILxChannelModSetup ** ILxChannelModSetupID;

#include <lxcom.h>
#include <lxvalue.h>



typedef struct vt_ILxChannelModItem {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Allocate) (
        LXtObjectID		 self,
        LXtObjectID		 cmod,
        LXtObjectID		 eval,
        LXtObjectID		 item,
        void		       **ppvData);

        LXxMETHOD(  unsigned int,
Flags) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 index);

        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self,
        LXtObjectID		 cmod,
        LXtObjectID		 attr,
        void			*data);

        LXxMETHOD(  void,
Cleanup) (
        LXtObjectID		 self,
        void			*data);
} ILxChannelModItem;

typedef struct vt_ILxChannelModifier {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddInput) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 index);

        LXxMETHOD(  LxResult,
AddOutput) (
        LXtObjectID		 self,
        LXtObjectID		 item,
        unsigned int		 index);

        LXxMETHOD(  LxResult,
AddTime) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
InputCount) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		*nInputs);

        LXxMETHOD(  LxResult,
OutputCount) (
        LXtObjectID		 self,
        unsigned int		 index,
        unsigned int		*nOutputs);

        LXxMETHOD(  LxResult,
ReadInputFloat) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 inputIndex,
        double			*dVal);

        LXxMETHOD(  LxResult,
ReadInputFloatByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 inputIndex,
        unsigned int		 linkIndex,
        double			*dVal);

        LXxMETHOD(  LxResult,
ReadInputAngle) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 inputIndex,
        double			*dVal);

        LXxMETHOD(  LxResult,
ReadInputInt) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 inputIndex,
        int			*iVal);

        LXxMETHOD(  LxResult,
ReadInputIntByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 inputIndex,
        unsigned int		 linkIndex,
        int			*iVal);

        LXxMETHOD(  LxResult,
ReadInputVal) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 inputIndex,
        void			**val);

        LXxMETHOD(  LxResult,
ReadInputValByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 inputIndex,
        unsigned int		 linkIndex,
        void			**val);

        LXxMETHOD(  LxResult,
WriteOutputFloat) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 outputIndex,
        double			 dVal);

        LXxMETHOD(  LxResult,
WriteOutputInt) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 outputIndex,
        int			 iVal);

        LXxMETHOD(  LxResult,
WriteOutputVal) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 outputIndex,
        void			**val);

        LXxMETHOD(  LxResult,
WriteOutputValByIndex) (
        LXtObjectID		 self,
        LXtObjectID		 attr,
        unsigned int		 outputIndex,
        unsigned int		 linkIndex,
        void			**val);
} ILxChannelModifier;

/*
 * The channel modifier manager is defined as an interface on the package implementing
 * the item type. The manager provides methods to describe the channels it wants to
 * use, and to allocate the actual operator object that performs the evaluation.
 * The Define() method is passed a ChannelModSetup interface and is expected to call
 * AddChannel() or AddTime() methods on that object to add the channels it wants for
 * reading and writing. The names are all for channels on items of this type, and
 * may be set as inputs or outputs.
 * 
 * 
 * The Allocate() method is also passed the setup object and will allocate the
 * operator for this channel modifier.
 */
typedef struct vt_ILxChannelModManager {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Define) (
        LXtObjectID		 self,
        LXtObjectID		 cmod);
        LXxMETHOD(  LxResult,
Allocate) (
        LXtObjectID		 self,
        LXtObjectID		 cmod,
        void		       **ppvObj);
} ILxChannelModManager;

/*
 * Once set up, the operator will be called to read inputs and set outputs. Ideally
 * there will be no reason to do any queries during the evaluation.
 */
typedef struct vt_ILxChannelModOperator {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Evaluate) (
        LXtObjectID		 self);
} ILxChannelModOperator;

/*
 * This interface provides methods for setting up the desired modifier channels and
 * linking to their values.
 * This function is used to assign a channel as part of the modifier operation, and 
 * can only be used from the Define() method.
 * 
 * 
 * Channel modifiers that need to know the current evaluation time can use the
 * following function to add time as an input to the modifier. This can be read back 
 * in the Evaluate function as a floating point value. 
 * 
 * Reading and writing is done by allocating Value and ValueArray interfaces from the
 * setup object. These functions are called duirng the allocation stage for the 
 * operator, and return persistent objects for use in evaluation.
 * This returns a single Value for a given input index. If there are multiple inputs
 * linked to this channel only the first is returned.
 * 
 * 
 * This returns multiple values for an input index as a ValueArray object. The
 * individual input links can be examined and processed separately.
 * 
 * Time is read as a value as well.
 * 
 * This returns a single Value object for a given output index. There is no ability
 * to individually address multiple outputs. If this is a matrix channel, then the
 * value object can be queried for a Matrix interface and the output set using those
 * methods.
 * 
 * During channel binding the operator can also get a peek at the ILxEvalautionID
 * for the modifier.
 */
typedef struct vt_ILxChannelModSetup {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AddChannel) (
        LXtObjectID		 self,
        const char		*name,
        unsigned int		 flags);
        LXxMETHOD(  LxResult,
AddTime) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
ReadValue) (
        LXtObjectID		 self,
        const char		*name,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ReadArray) (
        LXtObjectID		 self,
        const char		*name,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ReadTimeValue) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
WriteValue) (
        LXtObjectID		 self,
        const char		*name,
        void		       **ppvObj);
        LXxMETHOD(  LXtObjectID,
GetEvaluation) (
        LXtObjectID		 self);
} ILxChannelModSetup;


        #define LXu_CHANNELMODITEM	"1955CFD9-9E56-42AB-94C8-BF6BE1B069D6"
        #define LXa_CHANNELMODITEM	"channelmoditem"
        // [export]  ILxChannelModItem cmod


        #define LXu_CHANNELMODIFIER	"7D633F1B-41A9-4151-B94E-A50322DB62EB"
        #define LXa_CHANNELMODIFIER	"channelmodifier"
        // [local]  ILxChannelModifier

/*
 * Channel Modifiers are represented graphically in the Schematic viewport as nodes 
 * with input and output connectors for linking the channels with items and other 
 * Channel Modifiers via Channel Links.
 * The flags passed with each channel provide information to the Schematic as to the 
 * role of the channels belonging to the modifier. For any given channel on the item 
 * the function can return some combination of the following flags. Note that zero is
 * also a valid flag value and indicates a channel that's used as input but doesn't
 * need to be added to schematic by default.
 * - LXfCHMOD_OUTPUT
 * This flag is used to inform the Schematic that a channel is to be represented as an output from
 * the modifier and will be drawn with a Channel Link connector on the righthand side of the node.
 * Channels specified as outputs will be automatically added to the node when the modifier is added
 * to the Schematic view.
 * 
 * - LXfCHMOD_INPUT
 * Since all channels are treated as inputs by default this flag is used by the Schematic to identify
 * 'primary' inputs that will be automatically added to a Channel Modifier node when it is first
 * added to the Schematic.
 * 
 * - LXfCHMOD_MULTILINK
 * This flag is used in combination with the input flag to specify that an input channel can accept
 * multiple Channel Links connected to it. If this flag is not set then the Schematic will prevent
 * more than one link being made to the channel.
 * 
 */

        #define LXfCHMOD_INPUT		0x0001
        #define LXfCHMOD_OUTPUT		0x0002
        #define LXfCHMOD_MULTILINK	0x0004


        #define LXu_CHANNELMODMANAGER	"0F9981DD-C1F7-4D92-8D3D-6F3C64401162"
        #define LXa_CHANNELMODMANAGER	"channelmodmanager"
        // [export]  ILxChannelModManager cman

        #define LXu_CHANNELMODOPERATOR	"B9D8203C-54D4-424C-B76F-339439803F1E"
        // [export]  ILxChannelModOperator cmop


        #define LXu_CHANNELMODSETUP	"75D1C574-C10E-47A0-B6DA-96298AB267E7"
        // [local]  ILxChannelModSetup
        // [python] ILxChannelModSetup:ReadValue	obj Value
        // [python] ILxChannelModSetup:ReadTimeValue	obj Value
        // [python] ILxChannelModSetup:ReadArray	obj ValueArray
        // [python] ILxChannelModSetup:WriteValue	obj Value

#endif
