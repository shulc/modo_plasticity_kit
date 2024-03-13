/*
 * LX audio module
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
#ifndef LX_audio_H
#define LX_audio_H

typedef struct vt_ILxAudioAnimService ** ILxAudioAnimServiceID;

#include <lxcom.h>
#include <lxio.h>
#include <lxserver.h>
#include <lxvmath.h>
#include <lxmedia.h>



/*
 * Audio for animation can be accessed through the SDK using a global service
 * interface.
 * Return the audio clip item for animation.
 * 
 * 
 * Return true if the audio for animation is playing.
 * 
 * Return true if the audio for animation is loop mode.
 * 
 * Return true if the audio for animation is in mute.
 * 
 * Return true if the scurb is enabled.
 * 
 * Return the start time to play audio.
 * 
 * Return the end time to play audio.
 * 
 * Return the audio object.
 * 
 * This also return the audio object between start and end times, but this is resampled
 * with the current animation settings like Start time and Loop. The audio object must
 * be release on user side.
 * 
 * 
 * Return the audio object.
 */
typedef struct vt_ILxAudioAnimService {
        ILxUnknown	 iunk;
        LXxMETHOD(  LxResult,
Item) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Sample) (
        LXtObjectID		 self,
        double			 time,
        unsigned int		 type,
        void			*value);
        LXxMETHOD(  int,
Playing) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
Loop) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
Mute) (
        LXtObjectID		 self);
        LXxMETHOD(  int,
Scrub) (
        LXtObjectID		 self);
        LXxMETHOD(  double,
Start) (
        LXtObjectID		 self);
        LXxMETHOD(  double,
End) (
        LXtObjectID		 self);
        LXxMETHOD(  LxResult,
Audio) (
        LXtObjectID		 self,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
Preview) (
        LXtObjectID		 self,
        double			 startTime,
        double			 endTime,
        void		       **ppvObj);
        LXxMETHOD(  LxResult,
ItemSample) (
        LXtObjectID		 self,
        LXtObjectID		 obj,
        int			 loop,
        double			 time,
        unsigned int		 type,
        void			*value);
        LXxMETHOD(  LxResult,
ItemAudio) (
        LXtObjectID		 self,
        LXtObjectID		 obj,
        void		       **ppvObj);
} ILxAudioAnimService;


        #define LXu_AUDIOANIMSERVICE	"42F4A65B-A5BE-4C77-8A66-3C1B245C6BB0"
        // [python] ILxAudioAnimService:Item	obj Item
        // [python] ILxAudioAnimService:Audio	obj Audio
        // [python] ILxAudioAnimService:Preview	obj Audio
        // [python] ILxAudioAnimService:Sample:value	vector

#endif
