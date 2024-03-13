/*
 * LX message module
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
#ifndef LX_message_H
#define LX_message_H

typedef struct vt_ILxMessageService ** ILxMessageServiceID;
typedef struct vt_ILxAutoSaveListener ** ILxAutoSaveListenerID;

#include <lxcom.h>
#include <lxio.h>
#include <lxserver.h>



/*
 * As usual, the service starts with a ScriptQuery method.
 * This allocate a new ILxMessage object.  This object can then be populated with a message
 * code and message table entry.
 * 
 * An existing ILxMessage object can be duplicated with this method.
 * 
 * This return a human-readable string from the given message object.
 * This fails if there is no message text, but will also set the
 * buffer to an empty string.
 * Note that messages returned in this way will not have any rich
 * text encodings from modo markup in them.  If you want the encodings,
 * see MessageTextRich().
 * 
 * 
 * Finally it's possible to get the raw message pattern directly from the message table,
 * without substitution and without using an ILxMessage object. If 'table' is null, the
 * message text will be decoded using the '@table@msg@' format.
 * Note that messages returned in this way will not have any rich
 * text encodings from modo markup in them.  If you want the encodings,
 * see RawTextRich().
 * 
 * 
 * These methods return the username and description of a given argument type.
 * 
 * These get a specific user string given an internal option name and an argument type name.
 * 
 * For backwards compatibility, message strings have any modo markup removed before
 * they are returned.  This makes them suitable for use in non-modo UIs, like web
 * pages or Qt widgets.  These functions return the string without stripping the
 * decoded markup, allowing them to be displayed as rich text in modo.
 * 
 * 
 * If you do have a srting with rich text codes in it, they can be stripped with
 * this function.  The string returned should be considered volatile, and used or
 * copied as soon as possible.
 * 
 * Strings tables are like message tables, but aren't localized.  They can be
 * useful if you want to store an internal string in a config so that ti can
 * be easily changed.  This looks up a string given a table/ident pair and
 * returns it.
 * 
 * This gets an icon name given an internal option name and an argument type name.
 * 
 */
typedef struct vt_ILxMessageService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Allocate) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Duplicate) (
        LXtObjectID		 self,
        LXtObjectID		 msg,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
MessageText) (
        LXtObjectID		 self,
        LXtObjectID		 msg,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
RawText) (
        LXtObjectID		 self,
        const char		*table,
        const char		*msg,
        const char	       **text);
        LXxMETHOD(  LxResult,
ArgTypeUserName) (
        LXtObjectID		 self,
        const char		*argType,
        char			*buf,
        unsigned		 len);

        LXxMETHOD(  LxResult,
ArgTypeDesc) (
        LXtObjectID		 self,
        const char		*argType,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
ArgTypeOptionUserName) (
        LXtObjectID		 self,
        const char		*argType,
        const char		*option,
        char			*buf,
        unsigned		 len);

        LXxMETHOD(  LxResult,
ArgTypeOptionDesc) (
        LXtObjectID		 self,
        const char		*argType,
        const char		*option,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
MessageTextRich) (
        LXtObjectID		 self,
        LXtObjectID		 msg,
        char			*buf,
        unsigned		 len);
        LXxMETHOD(  LxResult,
RawTextRich) (
        LXtObjectID		 self,
        const char		*table,
        const char		*msg,
        const char	       **text);
        LXxMETHOD(  LxResult,
StripRichText) (
        LXtObjectID		 self,
        const char		*string,
        const char	       **stripped);
        LXxMETHOD(  LxResult,
StringLookup) (
        LXtObjectID		 self,
        const char		*table,
        const char		*ident,
        const char	       **text);
        LXxMETHOD(  LxResult,
ArgTypeOptionIconName) (
        LXtObjectID		 self,
        const char		*argType,
        const char		*option,
        char			*buf,
        unsigned		 len);
} ILxMessageService;

typedef struct vt_ILxAutoSaveListener {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
AutoSaveNow) (
        LXtObjectID		 self);
} ILxAutoSaveListener;

/*
 * The "common" message table contains a set of translatable strings that
 * have consistent uses throughout the application. The codes are all old-style
 * numeric, defined here.
 */

        #define LXiCM_ACT_ERROR			100
        #define LXiCM_ACT_WARNING		101
        #define LXiCM_ACT_OK			102
        #define LXiCM_ACT_CANCEL		103
        #define LXiCM_ACT_YES			104
        #define LXiCM_ACT_NO			105
        #define LXiCM_ACT_DONE			106
        #define LXiCM_ACT_YESALL		107
        #define LXiCM_ACT_RENAME		108
        #define LXiCM_ACT_ADD			109
        #define LXiCM_ACT_DELETE		110
        #define LXiCM_ACT_CLEAR			111
        #define LXiCM_ACT_SAVE			112
        #define LXiCM_ACT_NOSAVE		113
        #define LXiCM_ACT_LOAD			114
        #define LXiCM_ACT_CLOSE			117
        #define LXiCM_ACT_CONTINUE		118
        #define LXiCM_SPC_NONE			125
        #define LXiCM_SPC_UNNAMED		126
        #define LXiCM_SPC_MIXED			127
        #define LXiCM_ACT_INFO			128
        #define LXiCM_ACT_QUIT			132
        #define LXiCM_ACT_NAME			133
        #define LXiCM_ACT_TYPE			134
        #define LXiCM_ACT_PROJ			135
        #define LXiCM_ACT_AXIS			136
        #define LXiCM_SPC_UNKNOWN		137
        #define LXiCM_ACT_COPY			138
        #define LXiCM_ACT_CUT			139
        #define LXiCM_ACT_PASTE			140
        #define LXiCM_SPC_NEW			141
        #define LXiCM_ACT_NEW			141
        #define LXiCM_ACT_VOID			142
        #define LXiCM_SPC_VOID			142
        #define LXiCM_ACT_ALL			143
        #define LXiCM_SPC_ALL			143
        #define LXiCM_ACT_EXPORT		144
        #define LXiCM_ACT_PROPS			145
        #define LXiCM_ACT_HELP			146
        #define LXiCM_ACT_FUTURE		147
        #define LXiCM_ACT_SHOWM			148
        #define LXiCM_ACT_HIDE			149
        #define LXiCM_SPC_UNTITLE		150
        #define LXiCM_ACT_REPLACE		151
        #define LXiCM_ACT_RELOAD		152
        #define LXiCM_ACT_DUPLICATE		153
        #define LXiCM_SPC_PRIVATE		169
        #define LXiCM_SPC_PLUGINS		170
        #define LXiCM_SPC_ALLFILES		171
        #define LXiCM_SPC_ALLFORMATS		172
        #define LXiCM_ACT_SAVEAS		173
        #define LXiCM_ACT_BAKE			188
        #define LXiCM_ACT_INSTANCE		195
        #define LXiCM_SPC_DEFAULT		196
        #define LXiCM_ACT_LOADIMAGE		197
        #define LXiCM_ACT_NOALL			198
        #define LXiCM_ACT_NEWIMAGE		203
        #define LXiCM_ACT_LOADSEQ		213
        #define LXiCM_ACT_NEWSEQ		214
        #define LXiCM_ACT_DEFORM		216
        #define LXiCM_ACT_CHOOSECOLOR		217
        #define LXiCM_ACT_ADDMAP		218
        #define LXiCM_ACT_EMPTY_PAREN		219

// Values after 220 are already defined in commsg.cfg.  Best to just add others there so you don't stomp on existing vlaues.  Or maybe use strings for lookups instead of numbers...
// Values after 220 are already defined in commsg.cfg.  Best to just add others there so you don't stomp
//  on existing vlaues (bug 419133).  Or maybe use strings for lookups instead of numbers...

        #define LXiCM_ACT_MOVE			700
        #define LXiCM_ACT_PERFORMDROP		701
        #define LXiCM_ACT_CREATEPRESET		702
        #define LXiCM_ACT_CANCELDROP		703

        #define LXiCM_ACT_GRADIENT_PAREN	710
        #define LXiCM_ACT_MATRIX4_PAREN		711
        #define LXiCM_ACT_MESH_PAREN		712

/*
 * MessageService provides access to message tables, which contain localized human-readable versions
 * of internal strings used within the application.  All strings presented to the user should come
 * from messagte tables.
 */

        #define LXu_MESSAGESERVICE	"86A69B5D-ACFA-11D9-B38C-000A956C2E10"
        #define LXa_MESSAGESERVICE	"messageservice"
        // [python] ILxMessageService:Allocate	obj Message
        // [python] ILxMessageService:Duplicate	obj Message

/*
 * Auto-saving is triggered periodically based on user preferences, modified by when the system
 * believes an autosave is safe to perform.  Other clients can get in on this by listening to
 * the auto-save event port.  There is only one event, AutoSaveNow(), at which point the client
 * can safely perform an auto-save if applicable.  This event is sent after the nexus has done
 * its own auto-saving.
 */

        #define LXa_AUTOSAVELISTENER	"autosavelistener"
        #define LXu_AUTOSAVELISTENER	"04f41d4e-7267-430e-81f4-a89896bf746c"
        // [export] ILxAutoSaveListener		asl
        // [local] ILxAutoSaveListener

#endif
