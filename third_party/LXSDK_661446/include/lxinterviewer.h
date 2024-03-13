/*
 * LX interviewer module
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
#ifndef LX_interviewer_H
#define LX_interviewer_H

typedef struct vt_ILxInterviewer ** ILxInterviewerID;
typedef struct vt_ILxInterviewerService ** ILxInterviewerServiceID;


/*
 * The server name is used as a key to detect if the user has already interacted with this message.
 * This is stored in the user config so that we don't open it again.
 * 
 * This returns a short title for the interview.  As with all these strings, it is preferred to
 * be a message table entry in the form of @table@message@ to ease localization, rather than a
 * static string.
 * 
 * 
 * A longer description string is provided with this method, which is displayed below the title.
 * 
 * 
 * The button label should represent the current label to draw based on how your options are set.
 * 
 * For boolean-style buttons, it is recommended to use phrases like "Turn On" and "Turn Off", as
 * it makes it clear what clicking the button will do.  Describing the current state of the option
 * is confusing, since it's not clear if that is what it's set to now, or is what clicking the
 * button will set it to.
 * 
 * 
 * When the button is clicked, the command string provided is executed.  The command's notifier
 * will trigger UI updates, at which point the server will be asked for strings, if applicable.
 * 
 */
typedef struct vt_ILxInterviewer {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Title) (
        LXtObjectID		 self,
        char			*buf,
        int			 len);
        LXxMETHOD(  LxResult,
Description) (
        LXtObjectID		 self,
        char			*buf,
        int			 len);
        LXxMETHOD(  LxResult,
ButtonLabel) (
        LXtObjectID		 self,
        char			*buf,
        int			 len);
        LXxMETHOD(  LxResult,
ButtonCommand) (
        LXtObjectID		 self,
        char			*buf,
        int			 len);
} ILxInterviewer;

/*
 * As with all services, we start with the ScriptQuery method, although it is
 * not implemented.
 * 
 * Disarm an interviewer.  This causes an armed or fired interviewer to be dismissed.  if
 * allowRearm is true, then it can be armed again in the future, and provides a way to
 * reset a previously-fired interviewer.
 * 
 * 
 * Returns LXe_TRUE if an interviewer was armed or fired, and LXe_FALSE if it was not.  An
 * interviewer that is currently displayed is considered fired, but one that is armed
 * but not yet displayed is not considered fired.
 * 
 * 
 * Fired interviewers are automatically dismissed if the user hasn't interacted with them.
 * This can be used to clear the timer and force the user to interact, and can be called
 * anytime after the server has been armed.
 * 
 */
typedef struct vt_ILxInterviewerService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
ScriptQuery) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Arm) (
        LXtObjectID		 self,
        const char		*serverName,
        int			 target);
        LXxMETHOD(  LxResult,
Disarm) (
        LXtObjectID		 self,
        const char		*serverName,
        int			 allowRearm);
        LXxMETHOD(  LxResult,
WasFired) (
        LXtObjectID		 self,
        const char		*serverName);
        LXxMETHOD(  LxResult,
ClearDismissTimer) (
        LXtObjectID		 self,
        const char		*serverName);
} ILxInterviewerService;

/*
 * Interviewers provide a way to ask the user a question exactly once on their first use of a feature.
 * Common examples are asking if trackball rotation should be used in the 3D view, and how spacebar
 * should operate.
 */

        #define LXu_INTERVIEWER		"7039c075-3d04-4cc0-b3cf-f3de509b6a20"
        #define LXa_INTERVIEWER		"interviewer"
        //[local]  ILxInterviewer
        //[export] ILxInterviewer intrv

/*
 * The interviewer service is used primarily to arm an interviewer.  Interviewers are added
 * to a queue, and only one can be fired at any given time .  Once one expires, the next one
 * will fire automatically.
 * 
 */

        #define LXu_INTERVIEWERSERVICE		"5f892557-80a5-4490-b314-d5f19ff9a6b6"
        #define LXa_INTERVIEWERSERVICE		"interviewerservice"

        // [python] ILxInterviewerService:WasFired	bool

/*
 * Arm an interviewer.  If it has not been fired yet, it will be presented to the user and
 * present them with the option to change.  If it has already been armed or previously fired,
 * this will return LXe_ABORT.
 * The target determine when and where the interview occurs.
 * 
 * - 3DVIEW
 * Opens inside the currently-selected 3D view as a GL overlay.
 * 
 * - FORMVIEW (not currently implemented)
 * Displays the next time an Interview viewport with the server name is instantiated.  Most
 * often this is when it is embedded in a Form View, and that part of the form is instanced.
 * Note that it may be scrolled off the view, and not be visible, so putting it at the top
 * of a form is advised.
 * 
 */

        #define LXiIVTARGET_NOT_ARMED	-1

        #define LXiIVTARGET_3DVIEW	0
        #define LXiIVTARGET_FORMVIEW	1			// Not currently implemented

#endif
