/*
 * LX inputmap module
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
#ifndef LX_inputmap_H
#define LX_inputmap_H
/*
 * An alternate method is to call ILxInputMapservice methods.  This isn't
 * recommended, as your server may not be loaded until well after the system
 * has started, and thus won't be present in the input editor.  It only makes
 * sense for clients that are guaranteed to be started during app startup,
 * which mostly limits it to internal servers (as opposed to plug-ins).
 * Each client creates its own input map using this function.  Usually a client
 * will create one root input map is created for an entire module, not for each
 * instance of the module.
 * The opaque LXtInputMapID is used as a handle to an input map.
 * 
 */

        typedef void * LXtInputMapID;
        // [python] type LXtInputMapID       id

/*
 * The list of input maps can also be read from their hierarchical grouping.  To
 * see the root list of groups, use a NULL group.  The list of groups and input
 * maps within a group can be read.  Both are alpha sorted for convenience.
 */

        typedef void * LXtInputMapGroupID;


typedef struct vt_ILxInputMapService ** ILxInputMapServiceID;
typedef struct vt_ILxInputMapClientTest ** ILxInputMapClientTestID;
typedef struct vt_ILxInputContextClientTest ** ILxInputContextClientTestID;
typedef struct vt_ILxRegionHandler ** ILxRegionHandlerID;
typedef struct vt_ILxInputDevices ** ILxInputDevicesID;
typedef struct vt_ILxInputDeviceInstance ** ILxInputDeviceInstanceID;

#include <lxserver.h>
#include <lxvalue.h>
#include <lxcommand.h>

/*
 * Clients can define states, which are looked up by name.  These allow clients to
 * provide finer grained remapping based on a dynamic state.  Event and region
 * assignments are always linked to a state.
 */

        typedef void *  		LXtInputStateID;

/*
 * Contexts are very similar to states, but they are applied just above the global
 * input map and below all other input maps.  This allows for very low level
 * overrides to application-wide assignments irrespective of the current viewport.
 * A prime application of this is animation vs. component mode key assignments.
 */

        typedef void *  		LXtInputContextID;

/*
 * The type may be one of the following.  These are used to organize the contexts
 * in the Input Editor.
 */

        #define LXiIMCONTEXTTYPE_INVALID		-1		// Invalid

        #define LXiIMCONTEXTTYPE_CONTEXTLESS		 0		// Identifies the global context
        #define LXiIMCONTEXTTYPE_SELECTION		 1		// Selection-oriented contexts (item vs. component mode)
        #define LXiIMCONTEXTTYPE_LAYOUT			 2		// Layout-specific contexts (see frame.qq for more information)

        #define LXiIMCONTEXTTYPE_SPECIAL		 3		// Special context that is not shown in the Input Editor

/*
 * Combos meant for mouse input contain are used for events and regions.  These
 * often contain a mouse button and any number of modifier keys, plus mouse
 * modifiers such as double-click.
 * We define a DualKeyCombo to make it clear that when we return a DualKey *,
 * we're returning an array of keys.
 */

        typedef unsigned short  		LXtDualKey;			// Should be in awin.qq, but it doesn't have an SDK yet.
        typedef LXtDualKey *			LXtDualKeyCombo;



/*
 * As with all globals, the first method gets the ILxScriptQueryID interface for
 * the system.
 * 
 * A context is required to return the correct LXtInputMapID, although the input
 * map will be added to all contexts.  The context may be NULL to use the gloal
 * context.
 * 
 * The remaining definition methods all operate on the most recently created input
 * map.  Once defined, an input map cannot be edited dynamically.
 * 
 * Each input map can belong to one group for user interface purposes.  Common
 * groups are Viewports, Controls and Components, etc.  Groups are specified as a
 * path, such as "viewports/3d".  Each path and each component of the path
 * (i.e., "viewport" and "viewport/3d" in the above example) are looked up as message
 * ID 1 in their own message tables using the form "{inputmapgroup} grouppath".
 * Don't forget to make message tables for each part of the path.
 * 
 * 
 * Standard events can be added to an input map with this method.  These inputs
 * can then be assigned to specific mouse/key combinations by the user.  Standard
 * events have set names and flags, and may be mapped globally or only for
 * specific clients.
 * 
 * 
 * This adds the client test object (InputMapClientTest interface) to the input map.
 * 
 * Input maps can specify regions for triggering context menus.  Each region's
 * type and internal name are defined using this function.  Region types can be
 * anything but 0, and can overlap with the event codes.
 * 
 * The list of input maps can be walked with these functions.  The list is alpha
 * sorted for convenience.  These require a context to operate on, as the assignments
 * will be different depending on the context.  A NULL context can be used to get
 * the global assignments.
 * 
 * This is used to look up an input map by its internal name.
 * 
 * 
 * These return the internal name and user name of the group.
 * 
 * 
 * These methods provide access to the raw input map properties, such as obtaining
 * the internal name and listing events and regions.  
 * This returns the internal name of an input map.
 * 
 * 
 * This returns the internal name of the group the input map belongs to,
 * as well as the group itself.  Either arg can be NULL.  See DefineGroup()
 * for information on how groups are arranged.
 * 
 * This gets the user data from the input map.  This is really only useful
 * for client that created the map.
 * 
 * The following define should be used when calling a function that takes a region
 * index, but you are doing a lookup based on name or type.
 * The list of available events can be walked using these methods.
 * 
 * 
 * These methods return the event name, type and flags for a specific event given
 * its index in the input map.  LXiINMAPINDEX_NOEVENT can be used as a NULL for
 * functions that can take a type if a name or index is provided instead.
 * 
 * 
 * 
 * This checks to see if two events (by event type) conflict with each other.
 * This returns LXe_TRUE if two events with mutually exclusive flags cover
 * different regions of the mouser, and thus can both use the same key combo.
 * 
 * If you just want the event name/flags irrespective of the input map (these are
 * standardized, after all), you can use these methods.
 * 
 * 
 * 
 * These methods return the region name and type.  An index of LXiINMAPINDEX_ANYWHERE will
 * return the special "entire map" region with the name of LXsINMAPREGION_ANYWHERE and a
 * type of LXiINMAPTYPE_NULL.  Similarly, an index of LXiINMAPINDEX_NOOP will return the
 * the "noop" region with the name LXsINMAPREGION_NOOP and type of LXiINMAPTYPE_NULL.
 * 
 * These methods can be used to lookup an event or region by name or type,
 * returning its index.  If the name is NULL, the type will be used for
 * the lookup.  LXiINMAPINDEX_NOEVENT can be used as the type when looking
 * up by name.
 * 
 * For regions, a NULL name or an LXsINMAPREGION_ANYWHERE name and a type
 * of LXiINMAPTYPE_NULL will return -1 (LXiINMAPINDEX_ANYWHERE), representing
 * the "entire map" key assignment region.  A name of LXsINMAPREGION_NOOP and
 * a type of LXiINMAPTYPE_NULL will returnt he "noop" region.  This returns
 * LXiINMAPINDEX_NOREGION if it cannot be found.
 * 
 * These get the usernames for the input map itself and its specific events and regions.
 * If a username cannot be found, the internal name is returned.  For events and regions,
 * NULL is returned if the event/region does not exist (out of bounds, etc).
 * 
 * 
 * For the event and region functions, either the name of the event/region or its index
 * must be provided.  If name is NULL, the index is used.  LXe_NOTFOUND or LXe_OUTOFBOUNDS
 * are the common error codes; LXe_FAILED may be returned if there is string of this type
 * in the help.  As usual, the username functions will fall back to the internal name
 * as long as the event exists in the input map.
 * User strings are looked up first by checking the input map and state name combination,
 * falling back to the input map, and finally to the global map for global events.  The
 * state name can be LXsINMAPSTATE_GLOBAL if no state test is desired.
 * 
 * 
 * 
 * The name of a group can be obtained with this method.  The string is a group in the
 * form of "path/group", while depth is what part of the path to return.  -1 can be used
 * to get the username for the entire path.  Paths can be from read input maps using
 * the Group() method.
 * 
 * The username for states is also available.  If the state is NULL, then the global
 * stateless name is returned.  If a username cannot be found, the internal name passed
 * in is returned.  This method will always return a valid string.
 * 
 * This returns the username for a state category given an internal name.
 * 
 * 
 * These functions can be used to walk the list of states with assignments in an
 * input map.  Only states containing assignments are stored.
 * 
 * 
 * This returns the internal name of a state.  The global state will return
 * LXsINMAPSTATE_GLOBAL.
 * 
 * This returns the input map that the state belongs to.
 * 
 * This checks to see if a current state is active.  This can be used to decide
 * which assignments should be applied to the mouse map defined by the input map,
 * returning LXe_TRUE if the state is active.  Note that multiple states may be
 * active at once, which is where the priority comes in; the higher priority state
 * assignments will take input first, falling through to the lower priority state
 * assignments.  The global "stateless" state will always return true with a
 * priority of 0.
 * 
 * These can be used to walk the list of category states as provided by the clients.
 * These are only used in things like the Input Editor, and while they should contain
 * an all-inclusive list of states, that may not be true.
 * 
 * These can be used to get an alpha-sorted list of all known states within a specific
 * category as provided by the input maps.
 * 
 * These walk the list of fallback states for a given state, such as having unmapped
 * Tool Preset events "fall through" to the specific Tool assignments within.
 * 
 * It is also possible to test to see if an event or region is supported by a state.
 * For example, some tools may not use all of the available events in the input map,
 * so there's no need to show them in the UI.
 * 
 * 
 * The ppvObj argument returrns an object with LXtInputContext interface, while
 * the clientTest object should have the InputContextClientTest interface.
 * 
 * These allow the context list to be walked.  For convenience, contexts are sorted
 * alphabetically, with the global context listed first.
 * 
 * 
 * This checks to see if a context is currently active.  This can be used to decide
 * which assignments should be applied between the global map and the location-
 * specific input maps, and returns LXe_TRUE if the context is active.  As with
 * states, multiple contexts may be active at once, and thus the priority is used
 * to decide which gets precedence, with the the higher priority contexts taking
 * input first and falling through to the lower priority context assignments.  The
 * global "contextless" context will always return true with a priority of 0.
 * 
 * These get the name and type of a context.
 * 
 * 
 * This gets a human-readable user name of a context from the config.  This uses the
 * command help mechanism that is also used to get event user strings;
 * 
 * This gets the context that an input map belongs to.
 * 
 * 
 * When the context has changed, the client owning the context should call this function.
 * This will force all mouse maps to update for the context change.
 * 
 * Both events and regions can have multiple assignments.  In the case of events, this means
 * that the same event can be assigned to multiple combos.  In the case of regions the same
 * is true, plus a different command can also be associated.
 * 
 * The count of assigments within an event is read with this method.  Only one of name
 * (non-NULL), index (>-2) or eventType are required, not all.
 * 
 * 
 * This returns the n'th mapping of this event within the state.
 * 
 * Regions are a bit more complex.  Each region can have multiple commands assigned
 * to different mouse/modifier combinations.  Thus the list of mapped combinations
 * for a region is walked like any other list.
 * Note that region assignments can consists of either a mouse/modifier combo or
 * a key combo.  The latter allows for location-specific keyboard equivilants.y 
 * Also it is possible to use a region ID of 0 for keyboard assignments that are
 * valid over the entire input map.  Note that this does not work for mouse/modifier
 * combos, only for key combos.
 * 
 * The count of assigments within a region is read with this method.  Only one of name
 * (non-NULL), index (>-2) or regionType are required, not all.
 * 
 * 
 * This gets back the mouse/modifier combo and the command string, which can be passed
 * directly to the command execution methods of cmds2.  Only one of name (non-NULL),
 * index (>-2) or type are required for lookup.  Either command or combo can be NULL
 * if you only want one of them.  The LXtDualKeyCombo returned is only valid until the
 * next call to RegionMappingByIndex()
 * Note that the "entire map" key asignment region has a name of LXsINMAPREGION_ANYWHERE,
 * an index of LXiINMAPINDEX_ANYWHERE and a type of LXiINMAPTYPE_NULL.  Only key combos
 * (not mouse/modifier combos) can be assigned to this special region.  When doing a
 * lookup by type, be sure to set name to NULL and index to LXiINMAPINDEX_NOREGION.
 * 
 * The "noop" region has a name of LXsINMAPREGION_NOOP, an index of LXiINMAPINDEX_NOOP
 * and a type of LXiINMAPTYPE_NULL.  Any mouse or key combo can be assigned here.
 * 
 * 
 * This can be used to look up a region mapping index given a combo.
 * 
 * Many times it is useful to tell what combo maps to which event or region.
 * This method returns true if an combo is already assigned within a specific
 * input map.  This tests against both event and region combinations, returning
 * LXe_INPUTMAP_EVENT_FOUND or LXe_INPUTMAP_REGION_FOUND as appropriate on success.  
 * Note that it is possible for compatible events to overlap.  This means that the
 * same combo can be assigned to different LXfINPUTEVENT_CLICK and LXfINPUTEVENT_DRAG
 * events at the same time.  The eventFlags argument determines which you are testing
 * for, and can also be LXfINPUTEVENT_BOTH.  When checking for a combo to be used
 * with a region, LXfINPUTEVENT_CLICK should be supplied.
 * 
 * The type that the mapping is assigned to can also be obtained with the type
 * argument.  If LXe_INPUTMAP_REGION_FOUND is returned.
 * 
 * Note that it is possible for multiple events to be assigned to the same combo. The
 * index argument is used to step through those combos: simply start with index 0 and
 * call this method in a loop until it fails.
 * 
 * 
 * This can be used to convert the combo into a human-readable string.
 * 
 * These methods encode and decode combos to and from strings suitable for config and
 * command argument use.  Both functions can be used on either key or mouse/modifier
 * combos.
 * 
 * 
 * This helper compares two combos.  This returns LXe_TRUE if they match and
 * LXe_FALSE if they don't, and LXe_FAILED on an error.
 * 
 * These can be used to encode and decoded individual LXtDualKey codes.
 * 
 * 
 * 
 * The MouseMapID is owned by the input map, and is automatic destroyed on shutdown; you should NOT
 * free the mouse map yourself.  This will be more useful once we have an SDK for mousers.  Until
 * then, we have to deal with a void *.  The same mouse map may be attached to multiple mousers.
 * TODO:  Replace void * with COM MouserID when available
 * 
 * 
 * Regions are attached by directly attaching their own mouser to the pane at
 * the priority level provided.    The handler object should have the
 * RegionHandler interface.
 * TODO:  Replace void * with COM WinPaneID when available
 * TODO:  Replace void ** with COM MouserID when available
 * 
 * 
 * InputMapService provides two methods to tell inmap that something has
 * changed with regards to input devices.
 * This should be called when the list of available devices has changed.
 * All InputDevices servers will be scanned, with new devices added and
 * old ones removed from the list. 
 * 
 * 
 * This tells inmap that a device's state has changed, such as due to a
 * button being pushed.  The device will be polled for new values for all
 * of its buttons and analog inputs.
 */
typedef struct vt_ILxInputMapService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Define) (
        LXtObjectID		 self,
        LXtInputContextID	 context,
        const char	        *name,
        LXtInputMapID		*im);
        LXxMETHOD(  LxResult,
DefineGroup) (
        LXtObjectID		 self,
        const char		*group);
        LXxMETHOD(  LxResult,
DefineStandardEvent) (
        LXtObjectID		 self,
        int			 event,
        int			 flags);
        LXxMETHOD(  LxResult,
DefineCustomEvent) (
        LXtObjectID		 self,
        int			 event,
        const char		*name,
        int			 flags);
        LXxMETHOD(  LxResult,
DefineClientTests) (
        LXtObjectID		 self,
        LXtObjectID		 tester);
        LXxMETHOD(  LxResult,
DefineRegion) (
        LXtObjectID		 self,
        int			 event,
        const char		*name);
        LXxMETHOD(  LxResult,
Count) (
        LXtObjectID		 self,
        LXtInputContextID	 context,
        int			*count);

        LXxMETHOD(  LxResult,
ByIndex) (
        LXtObjectID		 self,
        LXtInputContextID	 context,
        int			 index,
        LXtInputMapID		*im);
        LXxMETHOD(  LxResult,
Lookup) (
        LXtObjectID		 self,
        LXtInputContextID	 context,
        const char		*name,
        LXtInputMapID		*im);
        LXxMETHOD(  LxResult,
GroupCount) (
        LXtObjectID		 self,
        LXtInputMapGroupID	 group,
        int			*count);

        LXxMETHOD(  LxResult,
GroupByIndex) (
        LXtObjectID		 self,
        LXtInputMapGroupID	 group,
        int			 index,
        LXtInputMapGroupID	*subgroup);

        LXxMETHOD(  LxResult,
GroupIMCount) (
        LXtObjectID		 self,
        LXtInputMapGroupID	 group,
        int			*count);

        LXxMETHOD(  LxResult,
GroupIMByIndex) (
        LXtObjectID		 self,
        LXtInputMapGroupID	 group,
        int			 index,
        LXtInputMapID		*im);
        LXxMETHOD(  LxResult,
GroupGetName) (
        LXtObjectID		 self,
        LXtInputMapGroupID	 group,
        const char		*name);
        LXxMETHOD(  LxResult,
GroupGetUserName) (
        LXtObjectID		 self,
        LXtInputMapGroupID	 group,
        const char		*username);
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char	       **name);
        LXxMETHOD(  LxResult,
Group) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char	       **groupPath,
        LXtInputMapGroupID	*group);
        LXxMETHOD(  LxResult,
Data) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        void		       **data);
        LXxMETHOD(  LxResult,
EventCount) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        int			*count);
        LXxMETHOD(  LxResult,
EventName) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        int			 index,
        const char	       **name);
        LXxMETHOD(  LxResult,
EventType) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        int			 index,
        int			*type);
        LXxMETHOD(  LxResult,
EventFlags) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        int			 index,
        int			*flags);
        LXxMETHOD(  LxResult,
CanEventsCoexist) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        int			 event1,
        int			 event2);
        LXxMETHOD(  LxResult,
StandardEventName) (
        LXtObjectID		 self,
        int			 event,
        const char	       **name);
        LXxMETHOD(  LxResult,
StandardEventFlags) (
        LXtObjectID		 self,
        int			 event,
        int			*flags);
        LXxMETHOD(  LxResult,
RegionCount) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        int			*count);
        LXxMETHOD(  LxResult,
RegionName) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        int			 i,
        const char	       **name);

        LXxMETHOD(  LxResult,
RegionType) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        int			 i,
        int			*type);
        LXxMETHOD(  LxResult,
FindEvent) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char		*name,
        int			 type,
        int			*index);
        LXxMETHOD(  LxResult,
FindRegion) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char		*name,
        int			 type,
        int			*index);
        LXxMETHOD(  LxResult,
UserName) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char	       **username);

        LXxMETHOD(  LxResult,
Desc) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char	       **desc);

        LXxMETHOD(  LxResult,
HelpURL) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char	       **helpURL);
        LXxMETHOD(  LxResult,
EventUserName) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char		*stateName,
        const char		*name,
        int			 index,
        const char	       **username);

        LXxMETHOD(  LxResult,
EventDesc) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char		*stateName,
        const char		*name,
        int			 index,
        const char	       **desc);

        LXxMETHOD(  LxResult,
EventHelpURL) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char		*stateName,
        const char		*name,
        int			 index,
        const char	       **helpURL);
        LXxMETHOD(  LxResult,
RegionUserName) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char		*stateName,
        const char		*name,
        int			 index,
        const char	       **username);

        LXxMETHOD(  LxResult,
RegionDesc) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char		*stateName,
        const char		*name,
        int			 index,
        const char	       **desc);

        LXxMETHOD(  LxResult,
RegionHelpURL) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char		*stateName,
        const char		*name,
        int			 index,
        const char	       **helpURL);
        LXxMETHOD(  LxResult,
GroupUserName) (
        LXtObjectID		 self,
        const char	        *path,
        int			 depth,
        const char	       **username);
        LXxMETHOD(  LxResult,
StateUserName) (
        LXtObjectID		  self,
        const char		 *state,
        const char		**name );
        LXxMETHOD(  LxResult,
StateCatUserName) (
        LXtObjectID		  self,
        const char		 *cat,
        const char		**name );
        LXxMETHOD(  LxResult,
StateLookup) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char		*name,
        int			 add,
        LXtInputStateID		*state );
        LXxMETHOD(  LxResult,
StateCount) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        int			*count );
        LXxMETHOD(  LxResult,
StateByIndex) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        int			 i,
        LXtInputStateID		*state );
        LXxMETHOD(  LxResult,
StateName) (
        LXtObjectID		  self,
        LXtInputStateID		  state,
        const char		**name );
        LXxMETHOD(  LxResult,
StateInputMap) (
        LXtObjectID		  self,
        LXtInputStateID		  state,
        LXtInputMapID		 *im );
        LXxMETHOD(  LxResult,
TestState) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        const char		*state,
        int			*priority);
        LXxMETHOD(  LxResult,
StateUIListCatCount) (
        LXtObjectID		 self,
        int			*count);

        LXxMETHOD(  LxResult,
StateUIListCatName) (
        LXtObjectID		  self,
        int			  index,
        const char		**name);
        LXxMETHOD(  LxResult,
StateUIListCount) (
        LXtObjectID		 self,
        const char		*cat,
        int			*count);

        LXxMETHOD(  LxResult,
StateUIListName) (
        LXtObjectID		  self,
        const char		 *cat,
        int			  index,
        const char		**name);
        LXxMETHOD(  LxResult,
StateUIFallbacksCount) (
        LXtObjectID		   self,
        const char		  *stateName,
        int			  *count);

        LXxMETHOD(  LxResult,
StateUIFallbacksName) (
        LXtObjectID		   self,
        const char		  *stateName,
        int			   index,
        const char		 **name);
        LXxMETHOD(  LxResult,
StateUITestEvent) (
        LXtObjectID		   self,
        LXtInputMapID		   im,
        const char		  *stateName,
        int			   eventID);

        LXxMETHOD(  LxResult,
StateUITestRegion) (
        LXtObjectID		   self,
        LXtInputMapID		   im,
        const char		  *stateName,
        int			   regionID);
        LXxMETHOD(  LxResult,
RefreshStates) (
        LXtObjectID		 self,
        int			 flags);
        LXxMETHOD(  LxResult,
DefineContext) (
        LXtObjectID		 self,
        const char		*name,
        int			 type,
        LXtObjectID		 clientTest,
        LXtInputContextID	*context);
        LXxMETHOD(  LxResult,
ContextCount) (
        LXtObjectID		 self,
        int			*count);

        LXxMETHOD(  LxResult,
ContextByIndex) (
        LXtObjectID		  self,
        int			  index,
        LXtInputContextID	 *context);
        LXxMETHOD(  LxResult,
ContextLookup) (
        LXtObjectID		 self,
        const char		*name,
        LXtInputContextID	*context );
        LXxMETHOD(  LxResult,
TestContext) (
        LXtObjectID		 self,
        LXtInputContextID	 context,
        int			*priority);
        LXxMETHOD(  LxResult,
ContextName) (
        LXtObjectID		  self,
        LXtInputContextID	  context,
        const char		**name);
        LXxMETHOD(  LxResult,
ContextType) (
        LXtObjectID		  self,
        LXtInputContextID	  context,
        int			 *type);
        LXxMETHOD(  LxResult,
ContextUserName) (
        LXtObjectID		  self,
        LXtInputContextID	  context,
        const char		**name);

        LXxMETHOD(  LxResult,
ContextDesc) (
        LXtObjectID		  self,
        LXtInputContextID	  context,
        const char		**desc);

        LXxMETHOD(  LxResult,
ContextHelpURL) (
        LXtObjectID		  self,
        LXtInputContextID	  context,
        const char		**helpURL);
        LXxMETHOD(  LxResult,
Context) (
        LXtObjectID		  self,
        LXtInputMapID		  im,
        LXtInputContextID	 *context);
        LXxMETHOD(  LxResult,
RefreshContexts) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
EventMappingCount) (
        LXtObjectID		 self,
        LXtInputStateID		 state,
        const char		*eventName,
        int			 eventIndex,
        int			 eventType,
        int			*count);
        LXxMETHOD(  LxResult,
EventMappingByIndex) (
        LXtObjectID		 self,
        LXtInputStateID		 state,
        const char		*eventName,
        int			 eventIndex,
        int			 eventType,
        int			 index,
        LXtDualKeyCombo		*combo);
        LXxMETHOD(  LxResult,
RegionMappingCount) (
        LXtObjectID		 self,
        LXtInputStateID		 state,
        const char		*regionName,
        int			 regionIndex,
        int			 regionType,
        int			*count);
        LXxMETHOD(  LxResult,
RegionMappingByIndex) (
        LXtObjectID		 self,
        LXtInputStateID		 state,
        const char		*regionName,
        int			 regionIndex,
        int			 regionType,
        int			 index,
        LXtDualKeyCombo		*combo,
        const char	       **command);
        LXxMETHOD(  LxResult,
RegionMappingFind) (
        LXtObjectID		 self,
        LXtInputStateID		 state,
        const char		*regionName,
        int			 regionIndex,
        int			 regionType,
        const LXtDualKeyCombo	 combo,
        int			*index);
        LXxMETHOD(  LxResult,
ComboMapsTo) (
        LXtObjectID		 self,
        LXtInputStateID		 state,
        LXtDualKeyCombo		 combo,
        int			 eventFlags,
        int			 index,
        int			*type);
        LXxMETHOD(  LxResult,
ComboToString) (
        LXtObjectID		 self,
        LXtDualKeyCombo		 combo,
        char			*buffer,
        int			 bufLen);
        LXxMETHOD(  LxResult,
ComboEncode) (
        LXtObjectID		 self,
        LXtDualKeyCombo		 combo,
        char			*buffer,
        int			 bufLen);
        LXxMETHOD(  LxResult,
ComboDecode) (
        LXtObjectID		 self,
        const char		*string,
        LXtDualKeyCombo		*combo,
        int			 mode);
        LXxMETHOD(  LxResult,
ComboCompare) (
        LXtObjectID		 self,
        LXtDualKeyCombo		 combo1,
        LXtDualKeyCombo		 combo2 );
        LXxMETHOD(  LxResult,
ComboEncodePart) (
        LXtObjectID		 self,
        LXtDualKey		 part,
        char			*buffer,
        int			 bufLen);
        LXxMETHOD(  LxResult,
ComboDecodePart) (
        LXtObjectID		 self,
        const char		*string,
        LXtDualKey		*part );
        LXxMETHOD(  LxResult,
GetMouseMap) (
        LXtObjectID		 self,
        LXtInputMapID		 im,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
AttachRegions) (
        LXtObjectID		  self,
        LXtInputMapID		  im,
        void			 *pane,
        int			  mouserPriority,
        LXtObjectID		  handler,
        void			**mouser);
        LXxMETHOD(  LxResult,
UpdateDeviceList) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
UpdateDeviceInstance) (
        LXtObjectID		 self,
        const char		*name);
} ILxInputMapService;

/*
 * If the client wants to support state-specific mappings, it needs a way for inmap
 * to test the current state.  This is done with the TestState() method.  The state
 * name is passed, and the client should return LXe_TRUE if that state is active and
 * LXe_FALSE if not.  If not implemented, the input map will be stateless.  Multiple
 * states can be active at the same time; for example, not only would a Tool Preset's
 * state be active, but so would all of the Tool states that make up that preset.
 * The priority is the ordering of the states' assignments within the mouse map.
 * Higher priority states will have their events listed first, and thus will capture
 * input first; lower priority states can be considered "fall through" states and
 * their assignments will be used if no higher priority assignment catches the input.
 * The global "stateless" state has a priority of 0, so your states should be higher
 * than that.  The order of states with the same priority is undefined.
 * 
 * 
 * Clients also provide a list of possible states that the user can map to.  This
 * is handled by the count and name functions.  These are used solely for the user
 * interface, and should be internal names, which will be resolved into usernames
 * via cmdhelp.
 * State names must be part of a category.  This is done simply by prefixing the
 * name with the category, such as "toolPreset.ElementMove", where the first period
 * found marks the end of the category name.  Each state can belong to one category,
 * but multiple states can be in the same category.  This is used purely by the input
 * editor to group related states.
 * 
 * Note that a state only needs to be listed by one client, even if multiple clients
 * use it.  Also note that state names should be unique, as states are referenced
 * by name.
 * 
 * 
 * We also have the concept of fallback states.  Let's say the user assigns an event
 * in a Tool Preset to something, but leaves the rest of the events unmapped.  What we
 * want to happen is for the mapping to fall through to the specific tool underneath.
 * Normally, TestState()'s priority argument will be used to resolve this, but for the UI
 * we want to show not only the global stateless assignment, but also the state-specific
 * assignments as they would be layered in the mouse maps themselves.  Thus we need to
 * know which states are layered on top of which other states 
 * 
 * These functions are called with a specific state name, and should return the count and
 * names of the sub-states that can be used as fallbacks.  The UI will show the assignment
 * of the highest level mapping first (i.e., the state name this function is called with),
 * and if the event is unmapped it will fall through to the first state in the fallback
 * list, and so on.  After running out of fallbacks, the global stateless state is used.
 * 
 * As with the state list count/name functions, only one client needs to provide this
 * for each state, as all clients use the same fallbacks, and this function is used only
 * in the input editor.  If the client does not know how to handle the state, it should
 * simply fail with LXe_FAILED.  If the client can handle the state, it should return
 * LXe_OK and the count or name.
 * 
 * 
 * 
 * These functions are used by the editor to decide if an event or region is valid within
 * a state. A prime example is tools, where the active tool determines which events in the
 * input map are applicable.  The input map is passed along with the state name and event
 * ID, as each input map may have a different set of events, wihle the state namespace is
 * shared across all input maps.
 * 
 * When the user assigns a mouse/modifier combo to an event, we want to let them
 * know if it is already assigned to another event that is handled in the same area.
 * To do with, we need the input map to provide a coexistence test function.
 * 
 * The method takes two events, and returns true if they can both exist in the same
 * place with the same combo.  Note that both standard and custom events may be
 * tested.  The method should return LXe_TRUE if the events can coexist.
 * 
 * If not implement, then it is assumed all events conflict with all other events with
 * incompatible flags.
 * 
 * The handler is released when the pane (and thus the mouser) is destroyed.
 * 
 */
typedef struct vt_ILxInputMapClientTest {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
TestState) (
        LXtObjectID		 self,
        const char		*stateName,
        int			*priority);
        LXxMETHOD(  LxResult,
StateUICount) (
        LXtObjectID		 self,
        int			*count);

        LXxMETHOD(  LxResult,
StateUIName) (
        LXtObjectID		  self,
        int			  index,
        const char		**name);

        LXxMETHOD(  LxResult,
StateUIUserName) (
        LXtObjectID		  self,
        const char		 *name,
        const char		**username);
        LXxMETHOD(  LxResult,
StateUIFallbacksCount) (
        LXtObjectID		   self,
        const char		  *stateName,
        int			  *count);
        LXxMETHOD(  LxResult,
StateUIFallbacksName) (
        LXtObjectID		   self,
        const char		  *stateName,
        int			   index,
        const char 		 **name);
        LXxMETHOD(  LxResult,
StateUITestEvent) (
        LXtObjectID		   self,
        LXtInputMapID		   im,
        const char		  *stateName,
        int			   eventID);

        LXxMETHOD(  LxResult,
StateUITestRegion) (
        LXtObjectID		   self,
        LXtInputMapID		   im,
        const char		  *stateName,
        int			   regionID);
        LXxMETHOD(  LxResult,
TestCoexistence) (
        LXtObjectID		 self,
        int			 event1,
        int			 event2);
} ILxInputMapClientTest;

typedef struct vt_ILxInputContextClientTest {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Test) (
        LXtObjectID		 self,
        LXtInputContextID	 context,
        int			*priority);
} ILxInputContextClientTest;

/*
 * The Test method is used to see if a region is within a specific set of coordinates.
 * In general, this acts like the mouser test function.  The region argument is the 
 * region being tested for these coordinates; if it is 0, then all regions should be
 * tested at this location.  The method should return LXe_OK if the region falls within
 * the coordinates, and LXe_NOTFOUND otherwise.
 * 
 * Note that the Test() function is also responsible for testing the validity of the
 * "anywhere" region.  This means that if the test region returns false for the 0
 * event, then the anywhere region will also fail to function.  Noop events will always
 * fail.
 * 
 * 
 * 
 * Before the system opens a context menu, it calls the pick method.  This is
 * necessary so that commands that will be executed form the context menu have
 * a valid selection to operate on.  The input map should determine what region
 * is at the coordinates given, and see if the current selection is appropriate
 * to the contetx menu.  If so, they do simply return LXe_OK; if not, then
 * perform the necessary selection and return LXe_OK.  Note that as long as the
 * coordinates are within a valid region, this method should always return success
 * and allow the context menu to open; only on a real error should this fail.
 * The region is also passed on to the client.  This allows it perform specific
 * selections based on the region, which is useful if multiple possible selections
 * are in the same location.
 * 
 * 
 * 
 * A tooltip function is also available.  Generally, this should describe what
 * the region represents, not what will happen when you click on it, as that
 * can be remapped.  Note that the tooltip method will be called only if
 * something is mapped to that region.
 */
typedef struct vt_ILxRegionHandler {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Test) (
        LXtObjectID		 self,
        int			 x,
        int			 y,
        int			 region);
        LXxMETHOD(  LxResult,
Test3D) (
        LXtObjectID		 self,
        int			 x,
        int			 y,
        void			*pointer3D,
        int			 region);
        LXxMETHOD(  LxResult,
Pick) (
        LXtObjectID		 self,
        int			 x,
        int			 y,
        int			 region);
        LXxMETHOD(  LxResult,
Pick3D) (
        LXtObjectID		 self,
        int			 x,
        int			 y,
        void			*pointer3D,
        int			 region);
        LXxMETHOD(  LxResult,
ToolTip) (
        LXtObjectID		  self,
        int			  x,
        int			  y,
        int			  region,
        const char		**toolTip);
} ILxRegionHandler;

/*
 * These methods walk the list of devices currently available from the server.
 * 
 * This returns the unique name of this device.  This name should be unique
 * across devices of the same type (ie: two identical pieces of game controller
 * hardware should have different "names"), and is used to decide if devices
 * have been added or removed.
 * 
 * This returns an instance of the device object, and expects to get back an object
 * with the ILxInputDeviceInstance interface.
 */
typedef struct vt_ILxInputDevices {
        ILxUnknown	 iunk;
        LXxMETHOD(  int,
DeviceCount) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
DeviceNameByIndex) (
        LXtObjectID		  self,
        int			  index,
        const char		 *name);
        LXxMETHOD(  LxResult,
DeviceInstanceByIndex) (
        LXtObjectID		  self,
        int			  index,
        void			**ppvObj);
} ILxInputDevices;

/*
 * This returns the unqiue name of the device instance.  If multiple identical pieces
 * of hardware are connected, each must still have a unique name.  These names are
 * expected to persist between sessions, so that any mappings associated with it can
 * be restored properly when the app is relaunched.
 * 
 * This returns LXe_TRUE if the device is currently connected.
 * 
 * There can be an arbitrary number of buttons on the device, the count of which is
 * returned by this method.
 * 
 * Each button has an internal name and a username.  The username, as always, should
 * be a message table lookup, and returning "@table@message@" is all that is necessary
 * for inmap to do the lookup for you.  The internal name is used for storing any
 * mappings to this button in the config.
 * 
 * This returns LXe_TRUE if the button is down, and LXe_FALSE if up.
 * 
 * There are two kinds of analog inputs, aboslute and relative.  Arbitrary numbers
 * of analog inputs are supported.  An analog input only has a single value, and
 * thus moves on a single axis.  Joysticks, for example, are two analog inputs,
 * one for the X axis and one for the Y axis.
 * 
 * 
 * As with buttons, each input has an internal name and a username.
 * 
 * Analog inputs also have some other metrics telling us how they behave.
 * If isAbsolute is true, this is considered to be an absolute axis like
 * a slider, and the values will be used directly.  If false, it is
 * considered to be a relative adjustment to existing values.
 * 
 * If isDirectional is true, the values returned by the axis are expected
 * to be in the 0 to 1 range.  This is common for sliders and analog triggers
 * on game controllers.  If false, then this is a bidirectional axis like
 * a joystick, where the values range from -1 to 1.
 * 
 * 
 * This returns the current value of an analog input.  This should be
 * normalized to 0 to 1 or -1 to 1.
 */
typedef struct vt_ILxInputDeviceInstance {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Name) (
        LXtObjectID		  self,
        const char		 *name);
        LXxMETHOD(  LxResult,
IsConnected) (
        LXtObjectID		  self);
        LXxMETHOD(  int,
ButtonCount) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
ButtonName) (
        LXtObjectID		  self,
        int			  index,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
ButtonUserName) (
        LXtObjectID		  self,
        int			  index,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
ButtonIsDown) (
        LXtObjectID		  self,
        int			  index);
        LXxMETHOD(  int,
AnalogCount) (
        LXtObjectID		  self);
        LXxMETHOD(  LxResult,
AnalogName) (
        LXtObjectID		  self,
        int			  index,
        char			 *buf,
        int			  len);

        LXxMETHOD(  LxResult,
AnalogUserName) (
        LXtObjectID		  self,
        int			  index,
        char			 *buf,
        int			  len);
        LXxMETHOD(  LxResult,
AnalogMetrics) (
        LXtObjectID		  self,
        int			  index,
        int			 *isAbsolute,
        int			 *isDirectional);
        LXxMETHOD(  LxResult,
AnalogValue) (
        LXtObjectID		  self,
        int			  index,
        double			 *value);
} ILxInputDeviceInstance;

/*
 * There are no individual objects for the Input Map API.  Instead, everything
 * is handled throught the ILxInputMapService.  Whle input maps can be created
 * through calls to this service, the most common way is through server tags.
 * First, some error codes we use.
 */

        #define LXe_INPUTMAP_UNMAPPED			LXxFAILCODE(LXeSYS_INPUTMAP,1)
        #define LXe_INPUTMAP_UNKNOWN_EVENT		LXxFAILCODE(LXeSYS_INPUTMAP,2)	// Input map does not support this event
        #define LXe_INPUTMAP_UNKNOWN_REGION		LXxFAILCODE(LXeSYS_INPUTMAP,3)	// Input map does not support this region
        #define LXe_INPUTMAP_BAD_COMBO			LXxFAILCODE(LXeSYS_INPUTMAP,4)	// Combo needs LMB, RMB or MMB set
        #define LXe_INPUTMAP_COMBO_GLOBALLY_MAPPED	LXxFAILCODE(LXeSYS_INPUTMAP,5)	// Combo is already mapped globally
        #define LXe_INPUTMAP_EVENT_GLOBALLY_MAPPED	LXxFAILCODE(LXeSYS_INPUTMAP,6)	// Event is already mapped globally

        #define LXe_INPUTMAP_EVENT_FOUND		LXxGOODCODE(LXeSYS_INPUTMAP,7)	// Successful; event found
        #define LXe_INPUTMAP_REGION_FOUND		LXxGOODCODE(LXeSYS_INPUTMAP,8)	// Successful; region found

/*
 * The Input Map service allows input maps to be created and walked.
 */

        #define LXu_INPUTMAPSERVICE	"DEDDBC50-F747-43a4-838D-D706ED688416"
        #define LXa_INPUTMAPSERVICE	"inputmapservice"

/*
 * There are two ways to define an input map.  The simplest way is to use server
 * tags, and this method is recommended.
 * The entire input map is defined with a single long server tag.  This includes
 * the name of the input map, and any regions and/or events the map will contain.
 */

        #define LXsINMAP_DEFINE		"inputmap.define"

/*
 * Input maps must each have a unique internal name.  This name is used for
 * storing assignments into the config and for looking up message information in a
 * manner similar to cmdhelp.  Input map names starting with a period, such as
 * ".global", are reserved.
 */

        #define	LXsINMAP_GLOBALMAP	".global"

/*
 * These define the standard set of input events.  Values with a non-zero high nibble
 * are reserved as standard events; lower values can be used for custom events.
 * Event code 0 is also reserved.  The standard events have a common prefix value
 * which can be tested, and what they do pretty much follows from their names. 
 * The only tricky case is NAV_ROTATE, which shows up in the UI as "Rotate (or Pan)".  
 * If the viewport is 3D this is a rotation, while if the viewport is 2D only then
 * this should still be accepted but treated as panning.
 */

        #define LXmINEVENT_STANDARD		 0xF0000000
        #define LXmINEVENT_TYPE			 0xF0000000
        #define LXiINEVENT_TYPE_NAV		 0x80000000
        #define LXiINEVENT_TYPE_SEL		 0x90000000
        #define LXiINEVENT_TYPE_SEL3D		 0xA0000000
        #define LXiINEVENT_TYPE_DRAG		 0xB0000000

        // Standard types
        #define	LXiINEVENT_NAV_PAN		 0x80000001		// Drag
        #define	LXiINEVENT_NAV_ZOOM		 0x80000002		// Drag
        #define	LXiINEVENT_NAV_BOX_ZOOM		 0x80000003		// Drag
        #define	LXiINEVENT_NAV_ROTATE		 0x80000004		// Drag
        #define	LXiINEVENT_NAV_FREEWHEEL	 0x80000005		// Drag
        #define	LXiINEVENT_NAV_ROLL		 0x80000006		// Drag
        #define	LXiINEVENT_NAV_PAN_XZ		 0x80000007		// Drag
        #define	LXiINEVENT_NAV_PAN_Y		 0x80000008		// Drag
        #define	LXiINEVENT_NAV_ROTATE_FPS	 0x80000009		// Drag

        #define	LXiINEVENT_SEL_PICK		 0x90000010		// Click
        #define	LXiINEVENT_SEL_ADD		 0x90000011		// Click
        #define	LXiINEVENT_SEL_SUBTRACT		 0x90000012		// Click
        #define	LXiINEVENT_SEL_TOGGLE		 0x90000013		// Click
        #define	LXiINEVENT_SEL_RANGE		 0x90000014		// Click

        #define	LXiINEVENT_SEL_LASSO		 0x90000015		// Drag
        #define	LXiINEVENT_SEL_LASSO_ADD	 0x90000016		// Drag
        #define	LXiINEVENT_SEL_LASSO_SUB	 0x90000017		// Drag
        #define	LXiINEVENT_SEL_LASSO_TOG	 0x90000018		// Drag

        #define	LXiINEVENT_SEL3D_PICK		 0xA0000020		// Click and Drag
        #define	LXiINEVENT_SEL3D_ADD		 0xA0000021		// Click and Drag
        #define	LXiINEVENT_SEL3D_SUBTRACT	 0xA0000022		// Click and Drag
        #define	LXiINEVENT_SEL3D_TOGGLE		 0xA0000023		// Click and Drag
        #define	LXiINEVENT_SEL3D_OPTION		 0xA000002C		// Click and Drag

        #define	LXiINEVENT_SEL3D_AREA		 0xA0000024		// Drag
        #define	LXiINEVENT_SEL3D_AREA_ADD	 0xA0000025		// Drag
        #define	LXiINEVENT_SEL3D_AREA_SUB	 0xA0000026		// Drag
        #define	LXiINEVENT_SEL3D_AREA_TOG	 0xA0000027		// Drag

        #define	LXiINEVENT_SEL3D_THRU		 0xA0000028		// Drag
        #define	LXiINEVENT_SEL3D_THRU_ADD	 0xA0000029		// Drag
        #define	LXiINEVENT_SEL3D_THRU_SUB	 0xA000002A		// Drag
        #define	LXiINEVENT_SEL3D_THRU_TOG	 0xA000002B		// Drag

/*
 * We also have this special event to initial drag and drop.  While it must be present
 * in the client's input map to initiate D&D, the event is not actually mapped to any
 * specific mouse/modifier combo, and will never show up in the Input Editor.  Instead,
 * it is used as the default drag event when no other event is mapped to a given
 * mouse/modifier combo, allowing D&D to be initiated by holding down any modifiers
 * and dragging with any mouse button (again, as long as nothing ismapped to it).
 * In effect, it is always mapped to "any key and any button".
 * Note that although it is not mapped in Input Ed, it must still be assigned in the
 * configs.  Withotu this, we wouldn't know which specific input context or state
 * (if any) to allow the event in.  Usually this assignment is "anykey-anybutton",
 * but no matter how it is assigned it will be loaded as "anykey-anybutton".  
 */

        #define	LXiINEVENT_DRAG_DROP_BEGIN	 0xB0000030		// Drag.  Special in that this event is never actually mapped to anything

/*
 * Standard event names are also defined here, primarily for use with defining
 * input maps through server tags.
 */

        #define	LXsINEVENT_NAV_PAN		"navPan"
        #define	LXsINEVENT_NAV_ZOOM		"navZoom"
        #define	LXsINEVENT_NAV_BOX_ZOOM		"navBoxZoom"
        #define	LXsINEVENT_NAV_ROTATE		"navRotate"
        #define	LXsINEVENT_NAV_FREEWHEEL	"navFreewheel"
        #define	LXsINEVENT_NAV_ROLL		"navRoll"
        #define	LXsINEVENT_NAV_PAN_XZ		"navPanXZ"
        #define	LXsINEVENT_NAV_PAN_Y		"navPanY"
        #define	LXsINEVENT_NAV_ROTATE_FPS	"navRotateFPS"

        #define	LXsINEVENT_SEL_PICK		"selPick"
        #define	LXsINEVENT_SEL_ADD		"selAdd"
        #define	LXsINEVENT_SEL_SUBTRACT		"selSubtract"
        #define	LXsINEVENT_SEL_TOGGLE		"selToggle"
        #define	LXsINEVENT_SEL_RANGE		"selRange"

        #define	LXsINEVENT_SEL_LASSO		"selLasso"
        #define	LXsINEVENT_SEL_LASSO_ADD	"selLassoAdd"
        #define	LXsINEVENT_SEL_LASSO_SUB	"selLassoSubtract"
        #define	LXsINEVENT_SEL_LASSO_TOG	"selLassoToggle"

        #define	LXsINEVENT_SEL3D_PICK		"sel3DPick"
        #define	LXsINEVENT_SEL3D_ADD		"sel3DAdd"
        #define	LXsINEVENT_SEL3D_SUBTRACT	"sel3DSubtract"
        #define	LXsINEVENT_SEL3D_TOGGLE		"sel3DToggle"
        #define	LXsINEVENT_SEL3D_OPTION		"sel3DOption"

        #define	LXsINEVENT_SEL3D_AREA		"sel3DArea"
        #define	LXsINEVENT_SEL3D_AREA_ADD	"sel3DAreaAdd"
        #define	LXsINEVENT_SEL3D_AREA_SUB	"sel3DAreaSubtract"
        #define	LXsINEVENT_SEL3D_AREA_TOG	"sel3DAreaToggle"

        #define	LXsINEVENT_SEL3D_THRU		"sel3DThru"
        #define	LXsINEVENT_SEL3D_THRU_ADD	"sel3DThruAdd"
        #define	LXsINEVENT_SEL3D_THRU_SUB	"sel3DThruSubtract"
        #define	LXsINEVENT_SEL3D_THRU_TOG	"sel3DThruToggle"

        #define	LXsINEVENT_DRAG_DROP_BEGIN	"dragDropBegin"

/*
 * The track flag can be set for both global and custom events.  This causes the
 * event to get tracking priority over other mousers.  This is useful if a higher
 * lower priotiy mouser should get track events.  For example, roll-overs in trees
 * are handled by the tree's own mouser, but region mousers added on top of that
 * would take the tracking state instead.  Thus the puts the TRACK flag on all it's
 * events.
 * Conversely, the trackless flag can be set.  This is automatically applied for
 * all regions, and takes precedence over the track flag.  When set, the event
 * will not be considered for tracking, and it's test function will only be called
 * if the event exactly matches the input state.  This behavior is particularly
 * useful for slow test functions.
 * The INDEPENDANT_CLICKDRAG flag is described in the next section. 
 * 
 * The CONSTANT_MOVES flag causes move events to be sent continuously while a mouse
 * button is down, even if the mouse isn't moving.  This is useful for airbrush-style
 * tools, where paint should still be sparying even though the mouse isn't moving.
 * 
 */

        #define LXfINPUTEVENT_TRACK			0x1000
        #define LXfINPUTEVENT_TRACKLESS			0x2000

        #define	LXfINPUTEVENT_INDEPENDANT_CLICKDRAG	0x4000

        #define	LXfINPUTEVENT_CONSTANT_MOVES		0x8000

        #define LXmINPUTEVENT_FLAGS			0xF000
        #define LXxINPUTEVENT_FLAGS(flags)		(flags & LXmINPUTEVENT_FLAGS)

/*
 * Custom events allow a client to define new kinds of events for its own use.
 * The name and event ID must be unique within the input map, and must be below
 * 0x80000000 and not 0.
 * The flags argument is a combination of these flags, which determine when and
 * how the event is tripped.  Currently, Click and Drag types are defined.
 * LXfINPUTEVENT_BOTH means that this event is triggered by both clicks and then
 * uses drags to perform in its operation.
 * DELTADRAG defines 1D drag events.  Different DELTADRAG events can be assigned
 * to the vertical and horizontal mouse axes.
 * 
 * Note that click-only and drag-only events can overlap, meaning that the user
 * can assign one combo to a click-style event, and assign that same combo to a
 * drag-style event.  The TRACK event described above can also be used with these
 * events.
 * 
 * The INDEPENDANT_CLICKDRAG flag allows LXfINPUTEVENT_BOTH events to operate as
 * click-only events when a drag event shares the same combo.  This should only
 * be set for click+drag events that perform an operation on click as well as drag,
 * as opposed to events that specify click+drag just for immediate feedback.
 * 
 */

        #define	LXfINPUTEVENT_CLICK			0x0001
        #define	LXfINPUTEVENT_DRAG			0x0002

        #define	LXfINPUTEVENT_BOTH			(LXfINPUTEVENT_CLICK | LXfINPUTEVENT_DRAG)

        #define	LXfINPUTEVENT_DELTADRAG			0x0004

        #define	LXmINPUTEVENT_TYPE			0x000F
        #define LXxINPUTEVENT_TYPE(flags)		(flags & LXmINPUTEVENT_TYPE)

        #define LXxINPUTEVENT_BOTH(flags)		(LXxINPUTEVENT_TYPE(flags) == LXfINPUTEVENT_BOTH)
        #define LXxINPUTEVENT_ISDRAG(flags)		(LXxINPUTEVENT_TYPE(flags) != LXfINPUTEVENT_CLICK)

/*
 * There are a few useful client states that inmap can test.  These are contained
 * in an ILxInputMapClientTest object, and are not required.
 */

        #define LXu_INPUTMAPCLIENTTEST	"7653F32B-8FDA-40ce-8EDE-0D5523BC7609"
        #define LXa_INPUTMAPCLIENTTEST	"inputmapclienttest"

/*
 * Regions are used to mark areas that can open context menus.  They are defined
 * in a similar manner to to custom events, each having a unique type and name.  
 * Along with the client-defined regions, there is a special "entire map" region
 * used for key assignments that affect the entire input map.  This applies only
 * to key assignments, and cannot be used for mouse/modifier assignments.  This
 * region has a name of LXsINMAPREGION_ANYWHERE, a type of LXiINMAPTYPE_NULL and
 * an index of LXiINMAPINDEX_ANYWHERE.
 * A final special region is the noop.  Combos assigned to this region do nothing,
 * as the name implies.  However, they also block events from being triggered at
 * by any lower input maps (as opposed to the normal behavior, where unammped
 * combos are passed through to children), effectively making it a dead combo.
 * 
 * Note that the count does not include this special region; it includes only
 * the client defined regions.
 * 
 * The following define should be used when calling a function that takes a region
 * index, but you are doing a lookup based on name or type.  The index for the
 * anywhere region is also provided as a define here.
 * 
 */

        #define	LXiINMAPINDEX_NOREGION		-3
        #define LXiINMAPINDEX_NOOP		-2
        #define LXiINMAPINDEX_ANYWHERE		-1

        #define	LXiINMAPINDEX_NOEVENT		-1

        #define	LXiINMAPINDEX_NOMAPPING		-1

        #define	LXiINMAPTYPE_NULL		 0

        #define LXsINMAPREGION_ANYWHERE		".anywhere"
        #define LXsINMAPREGION_NOOP		".noop"

/*
 * This can be used to look up a input map assignments by state via the state's name. 
 * This fails if there are no assignments in that state within this input map.  That
 * doesn't mean the state is neccesarily invalid; it just means that there aren't any
 * assignments for that state here.  The global state can looked up with a NULL name;
 * an empty string or the string LXsINMAPSTATE_GLOBAL will also return the global state.
 * All input maps have at least the global state.
 * If the add flag is set, then the state will be added to the input map if it does
 * not already exist.  This only really makes sense if the input map can support the
 * state, but any input map can have any state applied; it just might never be used.
 */

        #define	LXsINMAPSTATE_GLOBAL		 "(stateless)"

/*
 * When a client's state has changed or new states have been added to the state list,
 * the client should call this function.  This will force all mouse maps to update
 * for the new state(s) and/or rebuild the state list for the UI.
 */

        #define	LXfINPUTSTATE_UPDATE_CURRENT	0x0001
        #define	LXfINPUTSTATE_UPDATE_LIST	0x0002

/*
 * Clients can define contexts with this method.  Like states, contexts simply
 * consist of a name to which events and regions are associated.
 * Also like states, an object is needed to test to see if the context is active.
 * This object has  a single method, which returns LXe_TRUE if the state is
 * active and LXe_FALSE if not.  As multiple contexts may be active at once, this
 * method also return a priority decide which gets precedence, with the the higher
 * priority contexts taking input first and falling through to the lower priority
 * context assignments.  The global "contextless" context will always return true
 * with a priority of 0.
 */

        #define LXu_INPUTCONTEXTCLIENTTEST	"FB08280B-5F3E-4852-B31F-8A87A6E7427F"
        #define LXa_INPUTCONTEXTCLIENTTEST	"inputmapcontextclienttest"

/*
 * This can be used to look up assignments by context via the context's name.  This
 * fails if the context is not defined.  The global context can be looked up with a NULL
 * name; an empty string or the string LXsINMAPCONTEXT_GLOBAL will also return the global
 * context.  The global context is always defined.
 */

        #define	LXsINMAPCONTEXT_GLOBAL		 "(contextless)"

/*
 * When deecoding, the combo buffer must be big enough to hold the decoded keys;
 * a 32 element DualKey array should be fine.  The LXtDualKeyCombo returned is
 * only valid until the next call to ComboDecode().  The mode flag determines if
 * event-style (mouse/modifier combos only) or region-style (both mouse/modifier
 * combos and key combos) are valid.  If you want to decode any valid combo, use
 * LXi_IMCOMBOTEST_REGIONS.  The BASIC mode can be used to decode any combo,
 * even if the action key is missing.
 * LXi_IMCOMBOTEST_MODIFIERS can be used to skip the validation test and sort
 * the combo in modifier form.  This is useful when decoding modifier combos that
 * do not have action keys or mouse buttons.
 */

        #define LXi_IMCOMBOTEST_EVENTS			1
        #define LXi_IMCOMBOTEST_REGIONS			2
        #define LXi_IMCOMBOTEST_MODIFIERS		3

/*
 * The handler object consits of two methods, Test and Pick.  The handler is released
 * when the pane (and thus the mouser) is destroyed.
 */

        #define LXu_REGIONHANDLER	"05811721-08E9-49e0-ADFE-92C6D4A3E5E6"
        #define LXa_REGIONHANDLER	"inputmapregionhandler"

/*
 * The input device server is used by inmap to walk the list of input devices
 * and attributes, and is able to poll the device for its current state at any
 * time.
 */

        #define LXu_INPUTDEVICES	"0a70601b-750d-4325-b38a-86f319933e17"
        #define LXa_INPUTDEVICES	"inputdevices"
        //[export]  ILxInputDevices indev
        //[local]   ILxInputDevices
        //[python]  ILxInputDevices:DeviceInstanceByIndex	obj InputDeviceInstance
        //[default] ILxInputDevices:DeviceCount = 0

/*
 * Some devices require polling, while others push data to the app.  To enable
 * polling, set the POLLRATE server tag, with the value an integer as a string
 * representing how frequently to poll in milliseconds (ie: "50").  This is a
 * lower bounds, and the device will not be polled more frequently than this value,
 * at least as long as it's above the minimum poll threshold defined by inmap itself.
 */

        #define LXsINPUTDEVICES_POLLRATE		"inputdevices.pollrate"

/*
 * An object with the ILxInputDeviceInstance interface is used by inmap to get
 * information about a specific input device, such as the buttons it has and their
 * names.  It is also used to poll the device for its current state.
 */

        #define LXu_INPUTDEVICEINSTANCE	"fd2edfc9-c3db-4409-a478-fce1511b9ff0"
        #define LXa_INPUTDEVICEINSTANCE	"inputdeviceinstance"
        //[export]  ILxInputDeviceInstance indevinst
        //[local]   ILxInputDeviceInstance
        //[default] ILxInputDeviceInstance:ButtonCount = 0
        //[default] ILxInputDeviceInstance:AnalogCount = 0
        //[python]  ILxInputDeviceInstance:ButtonIsDown				bool

#endif
