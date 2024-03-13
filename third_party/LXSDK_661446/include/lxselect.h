/*
 * LX select module
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
#ifndef LX_select_H
#define LX_select_H

typedef struct vt_ILxSelectionType ** ILxSelectionTypeID;
typedef struct vt_ILxSelectionListener ** ILxSelectionListenerID;
typedef struct vt_ILxSelectionService ** ILxSelectionServiceID;
typedef struct vt_ILxSelectionPacket1Service ** ILxSelectionPacket1ServiceID;

#include <lxcom.h>

/*
 * Clients can also enumerate packets in sequence, which may be more efficient
 * than accessing them by index for loops that want to hit everything. ScanLoop()
 * gets all elements of the given type, while ScanLoopCurrent() gets only those
 * that match the current subtypes.
 */

        typedef void *		 LXtScanInfoID;



/*
 * - MessageTable
 * This returns the name of the message table for the selection type. The message
 * table will be used to find user messages for the selection type.
 * - Compare
 * This method compares two packets and returns a ranking using the same sign
 * logic as strcmp(). This is used to sort packets and to search on packets.
 * - SubType
 * This returns the subtype of the packet. For selections that can contain heterogenous
 * elements this should be non-zero, while for selections where all the elements are
 * the same this should be zero.
 * 
 */
typedef struct vt_ILxSelectionType {
        ILxUnknown	 iunk;
        LXxMETHOD(  unsigned int,
Size) (
        LXtObjectID		 self);

        LXxMETHOD(  unsigned int,
Flags) (
        LXtObjectID		 self);

        LXxMETHOD(  const char *,
MessageTable) (
        LXtObjectID		 self);

        LXxMETHOD(  int,
Compare) (
        LXtObjectID		 self,
        void			*pkey,
        void			*pelt);

        LXxMETHOD(  unsigned int,
SubType) (
        LXtObjectID		 self,
        void			*pkt);
} ILxSelectionType;

/*
 * - ADD
 * when elements are added to a selection list.
 * - REMOVE
 * when elements are removed from a selection list.
 * - CURRENT
 * when a new list is put on top of the stack making it current.
 * The subType for this event is always zero.
 * 
 * - IMPLICIT
 * when a new type is put on top of the implicit stack.
 * The subType for this event is always zero.
 * 
 * - TIME_PRE
 * Sent before the internal time is checked and updated, this allows
 * clients to prepare for possible time changes if needed.
 * 
 * - TIME
 * when the current time is altered.
 * 
 * - TIMERANGE
 * when any of the specific time ranges is altered.  The type is included in
 * the notification data.
 * 
 * The ILxSelectionListener interface allows SDK clients to listen to the global
 * selection events.  These are just methods that the client defines that
 * we will call to signal change events.
 * 
 */
typedef struct vt_ILxSelectionListener {
        ILxUnknown	 iunk;
        LXxMETHOD(  void,
Current) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  void,
Add) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 subtType);

        LXxMETHOD(  void,
Remove) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 subtType);

        LXxMETHOD(  void,
Time) (
        LXtObjectID		 self,
        double			 time);

        LXxMETHOD(  void,
TimeRange) (
        LXtObjectID		 self,
        LXtID4			 type);
} ILxSelectionListener;

/*
 * The selection system is wrapped by a selection service interface for
 * reading and altering the selection state. The ILxSelectionService interface
 * has the obligatory SQ method, and some basic methods to read the current
 * state of the selection by type.
 * 
 * 
 * Editing the selection can be done selecting or deselecting, removing packets
 * from all selections, and manipulating the batch state.
 * 
 * These methods allow clients to look up name-type associations and to
 * allocate our own instances of the packet interface.
 * 
 * These methods allow clients to read and set the current time.
 * 
 * This is like Drop() but doesn't change the current selection mode.
 * 
 * This is similar to Test(), but returns the actual selection state for
 * the element. State can have one or more of the LXf_SELECTION_* bits
 * set, or be LXf_SELECTION_NONE.
 * 
 * This returns the most recent selection type -- the one the user acted on last.
 * If 'types' is non-null, it will be an array of types terminated with zero,
 * and the type returned will be one of the ones in the list.
 * 
 * This returns the list of current subtypes into the client's array. If
 * the number of current subtypes is laarger than the length of the buffer
 * then SHORTBUFFER is returned.
 */
typedef struct vt_ILxSelectionService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  int,
Count) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  void *,
ByIndex) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned int		 idx);

        LXxMETHOD(  void *,
Recent) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LxResult,
Test) (
        LXtObjectID		 self,
        LXtID4			 type,
        void			*packet);
        LXxMETHOD(  LXtScanInfoID,
ScanLoop) (
        LXtObjectID		 self,
        LXtScanInfoID		 scan,
        LXtID4			 type,
        void		       **packet);

        LXxMETHOD(  LXtScanInfoID,
ScanLoopCurrent) (
        LXtObjectID		 self,
        LXtScanInfoID		 scan,
        LXtID4			 type,
        void		       **packet);
        LXxMETHOD(  LxResult,
Select) (
        LXtObjectID		 self,
        LXtID4			 type,
        void			*packet);

        LXxMETHOD(  LxResult,
Deselect) (
        LXtObjectID		 self,
        LXtID4			 type,
        void			*packet);

        LXxMETHOD(  LxResult,
Remove) (
        LXtObjectID		 self,
        LXtID4			 type,
        void			*packet);

        LXxMETHOD(  LxResult,
Toggle) (
        LXtObjectID		 self,
        LXtID4			 type,
        void			*packet);

        LXxMETHOD(  LxResult,
Drop) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LxResult,
StartBatch) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
EndBatch) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
AbortBatch) (
        LXtObjectID		 self);
        LXxMETHOD(  const char *,
LookupName) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LXtID4,
LookupType) (
        LXtObjectID		 self,
        const char		*name);

        LXxMETHOD( LxResult,
Allocate) (
        LXtObjectID		 self,
        const char		*name,
        void		       **ppvObj);
        LXxMETHOD(  double,
GetTime) (
        LXtObjectID		 self);

        LXxMETHOD(  LxResult,
SetTime) (
        LXtObjectID		 self,
        double			 time);
        LXxMETHOD(  LxResult,
Clear) (
        LXtObjectID		 self,
        LXtID4			 type);
        LXxMETHOD(  int,
State) (
        LXtObjectID		 self,
        LXtID4			 type,
        void			*packet);
        LXxMETHOD(  LXtID4,
CurrentType) (
        LXtObjectID		 self,
        const LXtID4		*types);
        LXxMETHOD(  LxResult,
CurrentSubTypes) (
        LXtObjectID		 self,
        LXtID4			 type,
        unsigned		*sub,
        unsigned		 len,
        unsigned		*num);
} ILxSelectionService;

/*
 * This is a legacy service global that implements a subset of the monolithic
 * service. Since we used it in the old wrappers we need to allow queries to
 * succeed.
 */
typedef struct vt_ILxSelectionPacket1Service {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);

        LXxMETHOD(  const char *,
LookupName) (
        LXtObjectID		 self,
        LXtID4			 type);

        LXxMETHOD(  LXtID4,
LookupType) (
        LXtObjectID		 self,
        const char		*name);

        LXxMETHOD( LxResult,
Allocate) (
        LXtObjectID		 self,
        const char		*name,
        void		       **ppvObj);
} ILxSelectionPacket1Service;

/*
 * The types of entities that can be selected are determined by the extensible
 * ILxSelectionType interface. Individual selections themselves are defined as opaque
 * packets which are allocated and managed by the selection system. For extracting
 * specific information about the selection, the selection type can provide an
 * alternate packet translation interface.
 */

        #define LXu_SELECTIONTYPE	"6f0E612B-4462-43B5-84D3-A6FCA7C8EF94"
        #define LXa_SELECTIONTYPE	"SelectionType"
        // [export]  ILxSelectionType selTyp
        // [local]   ILxSelectionType
        // [default] ILxSelectionType:SubType = 0

        #define LXsSELTYPE_CODE		"selType.codeID4"

/*
 * A selection type is defined by a few methods:
 * - Size
 * This returns the packet size in bytes. The selection system itself will handle
 * memory management. In general the packet should be as small as possible.
 * - Flags
 * The flags give information about the selection type. If UNDOABLE is set then
 * the selection will be managed as part of the undoable model state.
 * 
 */

        #define LXf_SELPACKET_UNDOABLE		0x01


        #define LXu_SELECTIONLISTENER	"32E1B478-F2F6-41A8-9D79-14919B793AFE"
        #define LXa_SELECTIONLISTENER	"selectionListener"
        // [local]  ILxSelectionListener
        // [export] ILxSelectionListener selEvent

/*
 * - LXf_SELECTION_NONE
 * Element is not selected, nor recently selected.
 * - LXf_SELECTION_PRIMARY
 * First element for its selection type.
 * - LXf_SELECTION_SECONDARY
 * Present in the selection, but not as the primary element.
 * 
 * - LXf_SELECTION_LAST
 * Last element of its selection type.
 * 
 * - LXf_SELECTION_CURRENT
 * Present in the current selection at any location.
 * 
 * - LXf_SELECTION_HISTORY
 * Not found in the active selection but still existing in the cache of
 * recently deselected elements.
 * 
 */

        #define LXf_SELECTION_NONE		0x00
        #define LXf_SELECTION_PRIMARY		0x01
        #define LXf_SELECTION_SECONDARY		0x02
        #define LXf_SELECTION_LAST		0x04
        #define LXf_SELECTION_CURRENT		0x08
        #define LXf_SELECTION_HISTORY		0x10

/*
 * This service has the same GUID as the old SelectionStack interface.
 * They have the same second and third methods, which are all that were ever
 * used in plug-ins, so we should be good for backwards compatibility.
 */

        #define LXu_SELECTIONSERVICE	"6AEF6F27-046F-4C04-90E0-994D742851E7"
        #define LXa_SELECTIONSERVICE	"selectionservice"
        // [python] ILxSelectionService:Allocate	obj SelectionType
        // [python] ILxSelectionService:Test		bool
        // [python] ILxSelectionService:CurrentSubTypes:sub	vector


        #define LXu_SELECTIONPACKET1SERVICE	"58D8DEAD-3B0C-41FB-AC1E-B17A36521D44"

#endif
