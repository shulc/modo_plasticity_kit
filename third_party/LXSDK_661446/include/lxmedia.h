/*
 * LX media module
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
#ifndef LX_media_H
#define LX_media_H

typedef struct vt_ILxAudioLoaderTarget ** ILxAudioLoaderTargetID;
typedef struct vt_ILxAudio ** ILxAudioID;
typedef struct vt_ILxAudioWrite ** ILxAudioWriteID;
typedef struct vt_ILxAudioDevice ** ILxAudioDeviceID;
typedef struct vt_ILxAudioHandle ** ILxAudioHandleID;

#include <lxcom.h>
#include <lxio.h>
#include <lxserver.h>
#include <lxvmath.h>

/*
 * The audio handle is a context to play audio data by the system default device.
 * This provides the abstruct audio interaces. The real audio device in OS level
 * is implemented in OPAL.
 */

        typedef unsigned int	 LXtAudioState;

/*
 * The device state information.
 */

        #define LXaSTATE_STOPPED		 0
        #define LXaSTATE_PLAYING		 1
        #define LXaSTATE_PAUSED			 2
        #define LXaSTATE_INITIAL		 3


typedef struct st_LXtAudioMetrics {
        unsigned int		 channels;		// 1: mono, 2: stereo
        unsigned int		 type;			// bits per smaple. 8, 16 or 32 bits
        unsigned int		 frequency;		// sample per second (sample rate)
        unsigned int		 samples;		// total samples
        const char		*filename;		// filename
} LXtAudioMetrics;

typedef struct st_AudioTargetData {
        unsigned int		 channels;
        unsigned int		 type;
        unsigned int		 frequency;
        unsigned int		 samples;
} AudioTargetData;


typedef struct vt_ILxAudioLoaderTarget {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
SetChannels) (
        LXtObjectID		 self,
        unsigned		 channels);

        LXxMETHOD( LxResult,
SetType) (
        LXtObjectID		 self,
        unsigned		 type);

        LXxMETHOD( LxResult,
SetFrequency) (
        LXtObjectID		 self,
        unsigned		 frequency);

        LXxMETHOD( LxResult,
SetSamples) (
        LXtObjectID		 self,
        unsigned		 samples);
} ILxAudioLoaderTarget;

/*
 * This returns the number of audio channels. 1 is mono, 2 is stereo.
 * This returns the sampling rate. 8 is unsigned byte (0-255), 16 is signed
 * short (-32768 to 32767). 32 is 32 bits floating point value.
 * 
 * Frequency of buffer in Hz.
 * 
 * The triming time from start in second.
 * 
 * The time duration of buffer. This time is trimed.
 * 
 * Audio file and format.
 * 
 * This returns the size of buffer in byte. This is trimed.
 * 
 * This returns the pointer of buffer. If trim start is set, it returns the
 * offset position.
 * 
 * This returns the sampling value at the time.
 * 
 * Seek the buffer position to the given frame.
 * 
 * Return the current frame to read.
 * 
 * Read audio data to the buffer for the frames. The bytes of frames
 * is frames * channels * bytes of type. This returns the write frames and
 * it sets true to 'eof' if it reachs to the end of file.
 * 
 */
typedef struct vt_ILxAudio {
        ILxUnknown	 iunk;
        LXxMETHOD( unsigned int,
Channels) (
        LXtObjectID		 self);
        LXxMETHOD( unsigned int,
Type) (
        LXtObjectID		 self);
        LXxMETHOD( unsigned int,
Frequency) (
        LXtObjectID		 self);
        LXxMETHOD( double,
TrimStart) (
        LXtObjectID		 self);
        LXxMETHOD( double,
Duration) (
        LXtObjectID		 self);
        LXxMETHOD( const char *,
Filename) (
        LXtObjectID		 self);
        LXxMETHOD( unsigned int,
Size) (
        LXtObjectID		 self);
        LXxMETHOD( const void *,
Data) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Sample) (
        LXtObjectID		 self,
        double			 time,
        unsigned int		 type,
        void			*value);
        LXxMETHOD( void,
Seek) (
        LXtObjectID		 self,
        unsigned int		 frame);
        LXxMETHOD( unsigned int,
Tell) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Read) (
        LXtObjectID		 self,
        unsigned int		*frames,
        void			*buff,
        int			*eof);
        LXxMETHOD( void,
Metrics) (
        LXtObjectID		 self,
        LXtAudioMetrics		*metrics);
} ILxAudio;

/*
 * Initialize the audio object with the metrics. This must be called
 * before writing frames. "WriteBegin" fills "frameRange" that is the
 * start and end position in sample frames. The write data must be started
 * from the start frame.
 * Write the frame data to the object. This increments the data position.
 * This updates "frames" with the written frames.
 * 
 * This must be called after writing frames.
 * 
 * Set the sampling value at the time to the object.
 * 
 * Set the trim time from start.
 * 
 * Set the duration to play by second.
 */
typedef struct vt_ILxAudioWrite {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
WriteBegin) (
        LXtObjectID		 self,
        LXtAudioMetrics		*metrics,
        unsigned int		*frameRange);
        LXxMETHOD( LxResult,
Write) (
        LXtObjectID		 self,
        unsigned int		*frames,
        const void		*data);
        LXxMETHOD( LxResult,
WriteEnd) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SetSample) (
        LXtObjectID		 self,
        double			 time,
        unsigned int		 type,
        const void		*value);
        LXxMETHOD( LxResult,
SetStart) (
        LXtObjectID		 self,
        double			 start);
        LXxMETHOD( LxResult,
SetDuration) (
        LXtObjectID		 self,
        double			 duration);
} ILxAudioWrite;

/*
 * The audio device is virtual audio device device.
 * This provides the abstruct audio interaces. The real audio device in OS level
 * is implemented in OPAL.
 * This creates the audio handle with the audio object.
 * 
 * Stop all audio handles on the device.
 * 
 * Play the given audio file by non blocking mode.
 * 
 * Return true if the device is in playing.
 * 
 * Play the audio object in the limited range.
 */
typedef struct vt_ILxAudioDevice {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Handle) (
        LXtObjectID		 self,
        LXtObjectID		 audio,
        void			**ppvObj);
        LXxMETHOD( LxResult,
StopAll) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
PlayFile) (
        LXtObjectID		 self,
        const char		*filePath);
        LXxMETHOD( int,
Playing) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
PlayRange) (
        LXtObjectID		 self,
        LXtObjectID		 audio,
        double			 start,
        double			 end,
        double			 volume,
        double			 pitch);
} ILxAudioDevice;

/*
 * This function returns the current audio object.
 * The playback position in seconds.
 * 
 * Set the playback position in seconds. If the offset position is out of range,
 * this function modulos the position in loop mode, otherwise it sets to the end
 * of data.
 * 
 * Pitch multiplier.
 * 
 * 
 * Source gain.
 * 
 * 
 * Turn looping on (LXx_TRUE) or off (LXe_FALSE)
 * 
 * 
 * Play the audio source. If "forward" is false, it plays to backward.
 * 
 * Stop the audio source.
 * 
 * Pause the audio source.
 * 
 * Resume the audio source.
 * 
 * Returns the state of the audio device.
 */
typedef struct vt_ILxAudioHandle {
        ILxUnknown	 iunk;
        LXxMETHOD( LXtObjectID,
Audio) (
        LXtObjectID		 self);
        LXxMETHOD( double,
Offset) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SetOffset) (
        LXtObjectID		 self,
        double			 offset);
        LXxMETHOD( double,
Pitch) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SetPitch) (
        LXtObjectID		 self,
        double			 pitch);
        LXxMETHOD( double,
Volume) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SetVolume) (
        LXtObjectID		 self,
        double			 volume);
        LXxMETHOD( LxResult,
Loop) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
SetLoop) (
        LXtObjectID		 self,
        unsigned int		 loop);
        LXxMETHOD( LxResult,
Play) (
        LXtObjectID		 self,
        int			 forward);
        LXxMETHOD( LxResult,
Stop) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Pause) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Resume) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
State) (
        LXtObjectID		 self,
        LXtAudioState		*state);
} ILxAudioHandle;

/*
 * 8-bit PCM data is expressed as an unsigned value over the range 0 to 255,
 * 128 being an audio output level of zero. 16-bit PCM data is expressed as
 * a signed value over the range -32768 to 32767, 0 being an audio output
 * level of zero. Stereo data is expressed in interleaved format, left channel
 * first.
 */

        #define LXiAUDIO_CHAN_MONO	1
        #define LXiAUDIO_CHAN_STEREO	2


        #define LXiAUDIO_TYPE_U8	8
        #define LXiAUDIO_TYPE_I16	16
        #define LXiAUDIO_TYPE_F32	32


        #define LXu_AUDIOLOADERTARGET	"EDD92652-76A0-471B-B02C-F47CCC16A860"
        // [local]  ILxAudioLoaderTarget

/*
 * This is the primary interface for audio objects, and so this the GUID
 * specified when attempting to load or save audios.
 */

        #define LXu_AUDIO	"ABADACB8-A93D-45B1-B776-347CBE761B13"
        #define LXa_AUDIO	"audio"
        //[local]  ILxAudio
        //[export] ILxAudio audio
        //[python] ILxAudio:Sample:value	vector
        //[python] ILxAudio:Read:buff		vector


        #define LXu_AUDIOWRITE	"B1C160A8-6FF3-4C54-B817-8C17A49AB1D6"
        #define LXa_AUDIOWRITE	"audiowrite"
        //[local]  ILxAudioWrite
        //[export] ILxAudioWrite audiow


        #define LXu_AUDIODEVICE	"5CBC3BC8-95BB-4F24-B1A4-8474708EDE3A"
        #define LXa_AUDIODEVICE	"audioDevice"
        //[local]  ILxAudioDevice
        //[python] ILxAudioDevice:Handle	obj AudioHandle


        #define LXu_AUDIOHANDLE	"6A7F9318-A9CF-44CA-9F71-32006102FF24"
        //[local]  ILxAudioHandle

#endif
