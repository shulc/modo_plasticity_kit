/*
 * C++ wrapper for lxmedia.h
 *
 *	Copyright (c) 2008-2022 The Foundry Group LLC
 *	
 *	Permission is hereby granted, free of charge, to any person obtaining a
 *	copy of this software and associated documentation files (the "Software"),
 *	to deal in the Software without restriction, including without limitation
 *	the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *	and/or sell copies of the Software, and to permit persons to whom the
 *	Software is furnished to do so, subject to the following conditions:
 *	
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.   Except as contained
 *	in this notice, the name(s) of the above copyright holders shall not be
 *	used in advertising or otherwise to promote the sale, use or other dealings
 *	in this Software without prior written authorization.
 *	
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *	DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef LXW_MEDIA_HPP
#define LXW_MEDIA_HPP

#include <lxmedia.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_AudioDevice = {0x5CBC3BC8,0x95BB,0x4F24,0xB1,0xA4,0x84,0x74,0x70,0x8E,0xDE,0x3A};
    static const LXtGUID guid_AudioHandle = {0x6A7F9318,0xA9CF,0x44CA,0x9F,0x71,0x32,0x00,0x61,0x02,0xFF,0x24};
    static const LXtGUID guid_AudioWrite = {0xB1C160A8,0x6FF3,0x4C54,0xB8,0x17,0x8C,0x17,0xA4,0x9A,0xB1,0xD6};
    static const LXtGUID guid_Audio = {0xABADACB8,0xA93D,0x45B1,0xB7,0x76,0x34,0x7C,0xBE,0x76,0x1B,0x13};
    static const LXtGUID guid_AudioLoaderTarget = {0xEDD92652,0x76A0,0x471B,0xB0,0x2C,0xF4,0x7C,0xCC,0x16,0xA8,0x60};
};

class CLxLoc_AudioDevice : public CLxLocalize<ILxAudioDeviceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AudioDevice() {_init();}
  CLxLoc_AudioDevice(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AudioDevice(const CLxLoc_AudioDevice &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AudioDevice;}
    LxResult
  Handle (ILxUnknownID audio, void **ppvObj)
  {
    return m_loc[0]->Handle (m_loc,(ILxUnknownID)audio,ppvObj);
  }
    CLxResult
  Handle (ILxUnknownID audio, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Handle(m_loc,(ILxUnknownID)audio,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  StopAll (void)
  {
    return m_loc[0]->StopAll (m_loc);
  }
    LxResult
  PlayFile (const char *filePath)
  {
    return m_loc[0]->PlayFile (m_loc,filePath);
  }
    int
  Playing (void)
  {
    return m_loc[0]->Playing (m_loc);
  }
    LxResult
  PlayRange (ILxUnknownID audio, double start, double end, double volume, double pitch)
  {
    return m_loc[0]->PlayRange (m_loc,(ILxUnknownID)audio,start,end,volume,pitch);
  }
};

class CLxLoc_AudioHandle : public CLxLocalize<ILxAudioHandleID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AudioHandle() {_init();}
  CLxLoc_AudioHandle(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AudioHandle(const CLxLoc_AudioHandle &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AudioHandle;}
    ILxUnknownID
  Audio (void)
  {
    return (ILxUnknownID) m_loc[0]->Audio (m_loc);
  }
    double
  Offset (void)
  {
    return m_loc[0]->Offset (m_loc);
  }
    LxResult
  SetOffset (double offset)
  {
    return m_loc[0]->SetOffset (m_loc,offset);
  }
    double
  Pitch (void)
  {
    return m_loc[0]->Pitch (m_loc);
  }
    LxResult
  SetPitch (double pitch)
  {
    return m_loc[0]->SetPitch (m_loc,pitch);
  }
    double
  Volume (void)
  {
    return m_loc[0]->Volume (m_loc);
  }
    LxResult
  SetVolume (double volume)
  {
    return m_loc[0]->SetVolume (m_loc,volume);
  }
    LxResult
  Loop (void)
  {
    return m_loc[0]->Loop (m_loc);
  }
    LxResult
  SetLoop (unsigned int loop)
  {
    return m_loc[0]->SetLoop (m_loc,loop);
  }
    LxResult
  Play (int forward)
  {
    return m_loc[0]->Play (m_loc,forward);
  }
    LxResult
  Stop (void)
  {
    return m_loc[0]->Stop (m_loc);
  }
    LxResult
  Pause (void)
  {
    return m_loc[0]->Pause (m_loc);
  }
    LxResult
  Resume (void)
  {
    return m_loc[0]->Resume (m_loc);
  }
    LxResult
  State (LXtAudioState *state)
  {
    return m_loc[0]->State (m_loc,state);
  }
};

class CLxImpl_AudioWrite {
  public:
    virtual ~CLxImpl_AudioWrite() {}
    virtual LxResult
      audiow_WriteBegin (LXtAudioMetrics *metrics, unsigned int *frameRange)
        { return LXe_NOTIMPL; }
    virtual LxResult
      audiow_Write (unsigned int *frames, const void *data)
        { return LXe_NOTIMPL; }
    virtual LxResult
      audiow_WriteEnd (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      audiow_SetSample (double time, unsigned int type, const void *value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      audiow_SetStart (double start)
        { return LXe_NOTIMPL; }
    virtual LxResult
      audiow_SetDuration (double duration)
        { return LXe_NOTIMPL; }
};
#define LXxD_AudioWrite_WriteBegin LxResult audiow_WriteBegin (LXtAudioMetrics *metrics, unsigned int *frameRange)
#define LXxO_AudioWrite_WriteBegin LXxD_AudioWrite_WriteBegin LXx_OVERRIDE
#define LXxC_AudioWrite_WriteBegin(c) LxResult c::audiow_WriteBegin (LXtAudioMetrics *metrics, unsigned int *frameRange)
#define LXxD_AudioWrite_Write LxResult audiow_Write (unsigned int *frames, const void *data)
#define LXxO_AudioWrite_Write LXxD_AudioWrite_Write LXx_OVERRIDE
#define LXxC_AudioWrite_Write(c) LxResult c::audiow_Write (unsigned int *frames, const void *data)
#define LXxD_AudioWrite_WriteEnd LxResult audiow_WriteEnd (void)
#define LXxO_AudioWrite_WriteEnd LXxD_AudioWrite_WriteEnd LXx_OVERRIDE
#define LXxC_AudioWrite_WriteEnd(c) LxResult c::audiow_WriteEnd (void)
#define LXxD_AudioWrite_SetSample LxResult audiow_SetSample (double time, unsigned int type, const void *value)
#define LXxO_AudioWrite_SetSample LXxD_AudioWrite_SetSample LXx_OVERRIDE
#define LXxC_AudioWrite_SetSample(c) LxResult c::audiow_SetSample (double time, unsigned int type, const void *value)
#define LXxD_AudioWrite_SetStart LxResult audiow_SetStart (double start)
#define LXxO_AudioWrite_SetStart LXxD_AudioWrite_SetStart LXx_OVERRIDE
#define LXxC_AudioWrite_SetStart(c) LxResult c::audiow_SetStart (double start)
#define LXxD_AudioWrite_SetDuration LxResult audiow_SetDuration (double duration)
#define LXxO_AudioWrite_SetDuration LXxD_AudioWrite_SetDuration LXx_OVERRIDE
#define LXxC_AudioWrite_SetDuration(c) LxResult c::audiow_SetDuration (double duration)
template <class T>
class CLxIfc_AudioWrite : public CLxInterface
{
    static LxResult
  WriteBegin (LXtObjectID wcom, LXtAudioMetrics *metrics, unsigned int *frameRange)
  {
    LXCWxINST (CLxImpl_AudioWrite, loc);
    try {
      return loc->audiow_WriteBegin (metrics,frameRange);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Write (LXtObjectID wcom, unsigned int *frames, const void *data)
  {
    LXCWxINST (CLxImpl_AudioWrite, loc);
    try {
      return loc->audiow_Write (frames,data);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  WriteEnd (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_AudioWrite, loc);
    try {
      return loc->audiow_WriteEnd ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetSample (LXtObjectID wcom, double time, unsigned int type, const void *value)
  {
    LXCWxINST (CLxImpl_AudioWrite, loc);
    try {
      return loc->audiow_SetSample (time,type,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetStart (LXtObjectID wcom, double start)
  {
    LXCWxINST (CLxImpl_AudioWrite, loc);
    try {
      return loc->audiow_SetStart (start);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetDuration (LXtObjectID wcom, double duration)
  {
    LXCWxINST (CLxImpl_AudioWrite, loc);
    try {
      return loc->audiow_SetDuration (duration);
    } catch (LxResult rc) { return rc; }
  }
  ILxAudioWrite vt;
public:
  CLxIfc_AudioWrite ()
  {
    vt.WriteBegin = WriteBegin;
    vt.Write = Write;
    vt.WriteEnd = WriteEnd;
    vt.SetSample = SetSample;
    vt.SetStart = SetStart;
    vt.SetDuration = SetDuration;
    vTable = &vt.iunk;
    iid = &lx::guid_AudioWrite;
  }
};
class CLxLoc_AudioWrite : public CLxLocalize<ILxAudioWriteID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AudioWrite() {_init();}
  CLxLoc_AudioWrite(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AudioWrite(const CLxLoc_AudioWrite &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AudioWrite;}
    LxResult
  WriteBegin (LXtAudioMetrics *metrics, unsigned int *frameRange)
  {
    return m_loc[0]->WriteBegin (m_loc,metrics,frameRange);
  }
    LxResult
  Write (unsigned int *frames, const void *data)
  {
    return m_loc[0]->Write (m_loc,frames,data);
  }
    LxResult
  WriteEnd (void)
  {
    return m_loc[0]->WriteEnd (m_loc);
  }
    LxResult
  SetSample (double time, unsigned int type, const void *value)
  {
    return m_loc[0]->SetSample (m_loc,time,type,value);
  }
    LxResult
  SetStart (double start)
  {
    return m_loc[0]->SetStart (m_loc,start);
  }
    LxResult
  SetDuration (double duration)
  {
    return m_loc[0]->SetDuration (m_loc,duration);
  }
};

class CLxImpl_Audio {
  public:
    virtual ~CLxImpl_Audio() {}
    virtual unsigned int
      audio_Channels (void)
        = 0;
    virtual unsigned int
      audio_Type (void)
        = 0;
    virtual unsigned int
      audio_Frequency (void)
        = 0;
    virtual double
      audio_TrimStart (void)
        = 0;
    virtual double
      audio_Duration (void)
        = 0;
    virtual const char *
      audio_Filename (void)
        = 0;
    virtual unsigned int
      audio_Size (void)
        = 0;
    virtual const void *
      audio_Data (void)
        = 0;
    virtual LxResult
      audio_Sample (double time, unsigned int type, void *value)
        { return LXe_NOTIMPL; }
    virtual void
      audio_Seek (unsigned int frame)
        { }
    virtual unsigned int
      audio_Tell (void)
        = 0;
    virtual LxResult
      audio_Read (unsigned int *frames, void *buff, int *eof)
        { return LXe_NOTIMPL; }
    virtual void
      audio_Metrics (LXtAudioMetrics *metrics)
        { }
};
#define LXxD_Audio_Channels unsigned int audio_Channels (void)
#define LXxO_Audio_Channels LXxD_Audio_Channels LXx_OVERRIDE
#define LXxC_Audio_Channels(c) unsigned int c::audio_Channels (void)
#define LXxD_Audio_Type unsigned int audio_Type (void)
#define LXxO_Audio_Type LXxD_Audio_Type LXx_OVERRIDE
#define LXxC_Audio_Type(c) unsigned int c::audio_Type (void)
#define LXxD_Audio_Frequency unsigned int audio_Frequency (void)
#define LXxO_Audio_Frequency LXxD_Audio_Frequency LXx_OVERRIDE
#define LXxC_Audio_Frequency(c) unsigned int c::audio_Frequency (void)
#define LXxD_Audio_TrimStart double audio_TrimStart (void)
#define LXxO_Audio_TrimStart LXxD_Audio_TrimStart LXx_OVERRIDE
#define LXxC_Audio_TrimStart(c) double c::audio_TrimStart (void)
#define LXxD_Audio_Duration double audio_Duration (void)
#define LXxO_Audio_Duration LXxD_Audio_Duration LXx_OVERRIDE
#define LXxC_Audio_Duration(c) double c::audio_Duration (void)
#define LXxD_Audio_Filename const char * audio_Filename (void)
#define LXxO_Audio_Filename LXxD_Audio_Filename LXx_OVERRIDE
#define LXxC_Audio_Filename(c) const char * c::audio_Filename (void)
#define LXxD_Audio_Size unsigned int audio_Size (void)
#define LXxO_Audio_Size LXxD_Audio_Size LXx_OVERRIDE
#define LXxC_Audio_Size(c) unsigned int c::audio_Size (void)
#define LXxD_Audio_Data const void * audio_Data (void)
#define LXxO_Audio_Data LXxD_Audio_Data LXx_OVERRIDE
#define LXxC_Audio_Data(c) const void * c::audio_Data (void)
#define LXxD_Audio_Sample LxResult audio_Sample (double time, unsigned int type, void *value)
#define LXxO_Audio_Sample LXxD_Audio_Sample LXx_OVERRIDE
#define LXxC_Audio_Sample(c) LxResult c::audio_Sample (double time, unsigned int type, void *value)
#define LXxD_Audio_Seek void audio_Seek (unsigned int frame)
#define LXxO_Audio_Seek LXxD_Audio_Seek LXx_OVERRIDE
#define LXxC_Audio_Seek(c) void c::audio_Seek (unsigned int frame)
#define LXxD_Audio_Tell unsigned int audio_Tell (void)
#define LXxO_Audio_Tell LXxD_Audio_Tell LXx_OVERRIDE
#define LXxC_Audio_Tell(c) unsigned int c::audio_Tell (void)
#define LXxD_Audio_Read LxResult audio_Read (unsigned int *frames, void *buff, int *eof)
#define LXxO_Audio_Read LXxD_Audio_Read LXx_OVERRIDE
#define LXxC_Audio_Read(c) LxResult c::audio_Read (unsigned int *frames, void *buff, int *eof)
#define LXxD_Audio_Metrics void audio_Metrics (LXtAudioMetrics *metrics)
#define LXxO_Audio_Metrics LXxD_Audio_Metrics LXx_OVERRIDE
#define LXxC_Audio_Metrics(c) void c::audio_Metrics (LXtAudioMetrics *metrics)
template <class T>
class CLxIfc_Audio : public CLxInterface
{
    static unsigned int
  Channels (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    return loc->audio_Channels ();
  }
    static unsigned int
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    return loc->audio_Type ();
  }
    static unsigned int
  Frequency (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    return loc->audio_Frequency ();
  }
    static double
  TrimStart (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    return loc->audio_TrimStart ();
  }
    static double
  Duration (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    return loc->audio_Duration ();
  }
    static const char *
  Filename (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    return loc->audio_Filename ();
  }
    static unsigned int
  Size (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    return loc->audio_Size ();
  }
    static const void *
  Data (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    return loc->audio_Data ();
  }
    static LxResult
  Sample (LXtObjectID wcom, double time, unsigned int type, void *value)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    try {
      return loc->audio_Sample (time,type,value);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Seek (LXtObjectID wcom, unsigned int frame)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    loc->audio_Seek (frame);
  }
    static unsigned int
  Tell (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    return loc->audio_Tell ();
  }
    static LxResult
  Read (LXtObjectID wcom, unsigned int *frames, void *buff, int *eof)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    try {
      return loc->audio_Read (frames,buff,eof);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Metrics (LXtObjectID wcom, LXtAudioMetrics *metrics)
  {
    LXCWxINST (CLxImpl_Audio, loc);
    loc->audio_Metrics (metrics);
  }
  ILxAudio vt;
public:
  CLxIfc_Audio ()
  {
    vt.Channels = Channels;
    vt.Type = Type;
    vt.Frequency = Frequency;
    vt.TrimStart = TrimStart;
    vt.Duration = Duration;
    vt.Filename = Filename;
    vt.Size = Size;
    vt.Data = Data;
    vt.Sample = Sample;
    vt.Seek = Seek;
    vt.Tell = Tell;
    vt.Read = Read;
    vt.Metrics = Metrics;
    vTable = &vt.iunk;
    iid = &lx::guid_Audio;
  }
};
class CLxLoc_Audio : public CLxLocalize<ILxAudioID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Audio() {_init();}
  CLxLoc_Audio(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Audio(const CLxLoc_Audio &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Audio;}
    unsigned int
  Channels (void)
  {
    return m_loc[0]->Channels (m_loc);
  }
    unsigned int
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    unsigned int
  Frequency (void)
  {
    return m_loc[0]->Frequency (m_loc);
  }
    double
  TrimStart (void)
  {
    return m_loc[0]->TrimStart (m_loc);
  }
    double
  Duration (void)
  {
    return m_loc[0]->Duration (m_loc);
  }
    const char *
  Filename (void)
  {
    return m_loc[0]->Filename (m_loc);
  }
    unsigned int
  Size (void)
  {
    return m_loc[0]->Size (m_loc);
  }
    const void *
  Data (void)
  {
    return m_loc[0]->Data (m_loc);
  }
    LxResult
  Sample (double time, unsigned int type, void *value)
  {
    return m_loc[0]->Sample (m_loc,time,type,value);
  }
    void
  Seek (unsigned int frame)
  {
    m_loc[0]->Seek (m_loc,frame);
  }
    unsigned int
  Tell (void)
  {
    return m_loc[0]->Tell (m_loc);
  }
    LxResult
  Read (unsigned int *frames, void *buff, int *eof)
  {
    return m_loc[0]->Read (m_loc,frames,buff,eof);
  }
    void
  Metrics (LXtAudioMetrics *metrics)
  {
    m_loc[0]->Metrics (m_loc,metrics);
  }
};

class CLxLoc_AudioLoaderTarget : public CLxLocalize<ILxAudioLoaderTargetID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AudioLoaderTarget() {_init();}
  CLxLoc_AudioLoaderTarget(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AudioLoaderTarget(const CLxLoc_AudioLoaderTarget &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AudioLoaderTarget;}
    LxResult
  SetChannels (unsigned channels)
  {
    return m_loc[0]->SetChannels (m_loc,channels);
  }
    LxResult
  SetType (unsigned type)
  {
    return m_loc[0]->SetType (m_loc,type);
  }
    LxResult
  SetFrequency (unsigned frequency)
  {
    return m_loc[0]->SetFrequency (m_loc,frequency);
  }
    LxResult
  SetSamples (unsigned samples)
  {
    return m_loc[0]->SetSamples (m_loc,samples);
  }
};

#endif

