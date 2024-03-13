/*
 * C++ wrapper for lxthumbbrowse.h
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
#ifndef LXW_THUMBBROWSE_HPP
#define LXW_THUMBBROWSE_HPP

#include <lxthumbbrowse.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_DTBDropPreview = {0x7ccfca70,0x79d5,0x42ed,0xa5,0xbf,0x5d,0xfd,0x5b,0xc3,0x26,0x2b};
    static const LXtGUID guid_DTBGroupSortOverride = {0x0da992be,0x74c8,0x4c25,0xa4,0x02,0xc6,0x92,0x16,0xe5,0x2d,0xfb};
    static const LXtGUID guid_DTBBadgeOverride = {0x7cc3ec4f,0x974b,0x4467,0x9f,0x26,0xc3,0xef,0x78,0x82,0x59,0x18};
};

class CLxLoc_DTBDropPreview : public CLxLocalize<ILxDTBDropPreviewID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DTBDropPreview() {_init();}
  CLxLoc_DTBDropPreview(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DTBDropPreview(const CLxLoc_DTBDropPreview &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DTBDropPreview;}
    LxResult
  MarkNone (void)
  {
    return m_loc[0]->MarkNone (m_loc);
  }
    LxResult
  MarkGridPos (const char *path, unsigned int x, unsigned int y)
  {
    return m_loc[0]->MarkGridPos (m_loc,path,x,y);
  }
    LxResult
  MarkEntry (const char *path)
  {
    return m_loc[0]->MarkEntry (m_loc,path);
  }
    LxResult
  MarkBetween (const char *path, int markBefore)
  {
    return m_loc[0]->MarkBetween (m_loc,path,markBefore);
  }
    LxResult
  MarkAnywhere (const char *path)
  {
    return m_loc[0]->MarkAnywhere (m_loc,path);
  }
};

class CLxImpl_DTBGroupSortOverride {
  public:
    virtual ~CLxImpl_DTBGroupSortOverride() {}
    virtual LxResult
      gso_SetArguments (const char *args)
        { return LXe_NOTIMPL; }
    virtual int
      gso_Sort (const char *string1, const char *string2)
        = 0;
};
#define LXxD_DTBGroupSortOverride_SetArguments LxResult gso_SetArguments (const char *args)
#define LXxO_DTBGroupSortOverride_SetArguments LXxD_DTBGroupSortOverride_SetArguments LXx_OVERRIDE
#define LXxC_DTBGroupSortOverride_SetArguments(c) LxResult c::gso_SetArguments (const char *args)
#define LXxD_DTBGroupSortOverride_Sort int gso_Sort (const char *string1, const char *string2)
#define LXxO_DTBGroupSortOverride_Sort LXxD_DTBGroupSortOverride_Sort LXx_OVERRIDE
#define LXxC_DTBGroupSortOverride_Sort(c) int c::gso_Sort (const char *string1, const char *string2)
template <class T>
class CLxIfc_DTBGroupSortOverride : public CLxInterface
{
    static LxResult
  SetArguments (LXtObjectID wcom, const char *args)
  {
    LXCWxINST (CLxImpl_DTBGroupSortOverride, loc);
    try {
      return loc->gso_SetArguments (args);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Sort (LXtObjectID wcom, const char *string1, const char *string2)
  {
    LXCWxINST (CLxImpl_DTBGroupSortOverride, loc);
    return loc->gso_Sort (string1,string2);
  }
  ILxDTBGroupSortOverride vt;
public:
  CLxIfc_DTBGroupSortOverride ()
  {
    vt.SetArguments = SetArguments;
    vt.Sort = Sort;
    vTable = &vt.iunk;
    iid = &lx::guid_DTBGroupSortOverride;
  }
};
class CLxLoc_DTBGroupSortOverride : public CLxLocalize<ILxDTBGroupSortOverrideID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DTBGroupSortOverride() {_init();}
  CLxLoc_DTBGroupSortOverride(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DTBGroupSortOverride(const CLxLoc_DTBGroupSortOverride &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DTBGroupSortOverride;}
    LxResult
  SetArguments (const char *args)
  {
    return m_loc[0]->SetArguments (m_loc,args);
  }
    int
  Sort (const char *string1, const char *string2)
  {
    return m_loc[0]->Sort (m_loc,string1,string2);
  }
};

class CLxImpl_DTBBadgeOverride {
  public:
    virtual ~CLxImpl_DTBBadgeOverride() {}
    virtual LxResult
      dtbbo_BadgesSupported (ILxUnknownID entry, int *badges)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dtbbo_BadgeIsAlwaysVisible (ILxUnknownID entry, int badge)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dtbbo_BadgeOverride (ILxUnknownID entry, int badge, char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dtbbo_BadgeTooltip (ILxUnknownID entry, int badge, char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dtbbo_BadgeStarRatingOverride (ILxUnknownID entry, int *rating, char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dtbbo_BadgeAction (ILxUnknownID entry, int badge)
        { return LXe_NOTIMPL; }
    virtual LxResult
      dtbbo_BadgeStarRatingAction (ILxUnknownID entry, int rating)
        { return LXe_NOTIMPL; }
};
#define LXxD_DTBBadgeOverride_BadgesSupported LxResult dtbbo_BadgesSupported (ILxUnknownID entry, int *badges)
#define LXxO_DTBBadgeOverride_BadgesSupported LXxD_DTBBadgeOverride_BadgesSupported LXx_OVERRIDE
#define LXxC_DTBBadgeOverride_BadgesSupported(c) LxResult c::dtbbo_BadgesSupported (ILxUnknownID entry, int *badges)
#define LXxD_DTBBadgeOverride_BadgeIsAlwaysVisible LxResult dtbbo_BadgeIsAlwaysVisible (ILxUnknownID entry, int badge)
#define LXxO_DTBBadgeOverride_BadgeIsAlwaysVisible LXxD_DTBBadgeOverride_BadgeIsAlwaysVisible LXx_OVERRIDE
#define LXxC_DTBBadgeOverride_BadgeIsAlwaysVisible(c) LxResult c::dtbbo_BadgeIsAlwaysVisible (ILxUnknownID entry, int badge)
#define LXxD_DTBBadgeOverride_BadgeOverride LxResult dtbbo_BadgeOverride (ILxUnknownID entry, int badge, char *buf, int len)
#define LXxO_DTBBadgeOverride_BadgeOverride LXxD_DTBBadgeOverride_BadgeOverride LXx_OVERRIDE
#define LXxC_DTBBadgeOverride_BadgeOverride(c) LxResult c::dtbbo_BadgeOverride (ILxUnknownID entry, int badge, char *buf, int len)
#define LXxD_DTBBadgeOverride_BadgeTooltip LxResult dtbbo_BadgeTooltip (ILxUnknownID entry, int badge, char *buf, int len)
#define LXxO_DTBBadgeOverride_BadgeTooltip LXxD_DTBBadgeOverride_BadgeTooltip LXx_OVERRIDE
#define LXxC_DTBBadgeOverride_BadgeTooltip(c) LxResult c::dtbbo_BadgeTooltip (ILxUnknownID entry, int badge, char *buf, int len)
#define LXxD_DTBBadgeOverride_BadgeStarRatingOverride LxResult dtbbo_BadgeStarRatingOverride (ILxUnknownID entry, int *rating, char *buf, int len)
#define LXxO_DTBBadgeOverride_BadgeStarRatingOverride LXxD_DTBBadgeOverride_BadgeStarRatingOverride LXx_OVERRIDE
#define LXxC_DTBBadgeOverride_BadgeStarRatingOverride(c) LxResult c::dtbbo_BadgeStarRatingOverride (ILxUnknownID entry, int *rating, char *buf, int len)
#define LXxD_DTBBadgeOverride_BadgeAction LxResult dtbbo_BadgeAction (ILxUnknownID entry, int badge)
#define LXxO_DTBBadgeOverride_BadgeAction LXxD_DTBBadgeOverride_BadgeAction LXx_OVERRIDE
#define LXxC_DTBBadgeOverride_BadgeAction(c) LxResult c::dtbbo_BadgeAction (ILxUnknownID entry, int badge)
#define LXxD_DTBBadgeOverride_BadgeStarRatingAction LxResult dtbbo_BadgeStarRatingAction (ILxUnknownID entry, int rating)
#define LXxO_DTBBadgeOverride_BadgeStarRatingAction LXxD_DTBBadgeOverride_BadgeStarRatingAction LXx_OVERRIDE
#define LXxC_DTBBadgeOverride_BadgeStarRatingAction(c) LxResult c::dtbbo_BadgeStarRatingAction (ILxUnknownID entry, int rating)
template <class T>
class CLxIfc_DTBBadgeOverride : public CLxInterface
{
    static LxResult
  BadgesSupported (LXtObjectID wcom, LXtObjectID entry, int *badges)
  {
    LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
    try {
      return loc->dtbbo_BadgesSupported ((ILxUnknownID)entry,badges);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeIsAlwaysVisible (LXtObjectID wcom, LXtObjectID entry, int badge)
  {
    LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
    try {
      return loc->dtbbo_BadgeIsAlwaysVisible ((ILxUnknownID)entry,badge);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeOverride (LXtObjectID wcom, LXtObjectID entry, int badge, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
    try {
      return loc->dtbbo_BadgeOverride ((ILxUnknownID)entry,badge,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeTooltip (LXtObjectID wcom, LXtObjectID entry, int badge, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
    try {
      return loc->dtbbo_BadgeTooltip ((ILxUnknownID)entry,badge,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeStarRatingOverride (LXtObjectID wcom, LXtObjectID entry, int *rating, char *buf, int len)
  {
    LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
    try {
      return loc->dtbbo_BadgeStarRatingOverride ((ILxUnknownID)entry,rating,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeAction (LXtObjectID wcom, LXtObjectID entry, int badge)
  {
    LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
    try {
      return loc->dtbbo_BadgeAction ((ILxUnknownID)entry,badge);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BadgeStarRatingAction (LXtObjectID wcom, LXtObjectID entry, int rating)
  {
    LXCWxINST (CLxImpl_DTBBadgeOverride, loc);
    try {
      return loc->dtbbo_BadgeStarRatingAction ((ILxUnknownID)entry,rating);
    } catch (LxResult rc) { return rc; }
  }
  ILxDTBBadgeOverride vt;
public:
  CLxIfc_DTBBadgeOverride ()
  {
    vt.BadgesSupported = BadgesSupported;
    vt.BadgeIsAlwaysVisible = BadgeIsAlwaysVisible;
    vt.BadgeOverride = BadgeOverride;
    vt.BadgeTooltip = BadgeTooltip;
    vt.BadgeStarRatingOverride = BadgeStarRatingOverride;
    vt.BadgeAction = BadgeAction;
    vt.BadgeStarRatingAction = BadgeStarRatingAction;
    vTable = &vt.iunk;
    iid = &lx::guid_DTBBadgeOverride;
  }
};
class CLxLoc_DTBBadgeOverride : public CLxLocalize<ILxDTBBadgeOverrideID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_DTBBadgeOverride() {_init();}
  CLxLoc_DTBBadgeOverride(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_DTBBadgeOverride(const CLxLoc_DTBBadgeOverride &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_DTBBadgeOverride;}
    LxResult
  BadgesSupported (ILxUnknownID entry, int *badges)
  {
    return m_loc[0]->BadgesSupported (m_loc,(ILxUnknownID)entry,badges);
  }
    LxResult
  BadgeIsAlwaysVisible (ILxUnknownID entry, int badge)
  {
    return m_loc[0]->BadgeIsAlwaysVisible (m_loc,(ILxUnknownID)entry,badge);
  }
    LxResult
  BadgeOverride (ILxUnknownID entry, int badge, char *buf, int len)
  {
    return m_loc[0]->BadgeOverride (m_loc,(ILxUnknownID)entry,badge,buf,len);
  }
    LxResult
  BadgeTooltip (ILxUnknownID entry, int badge, char *buf, int len)
  {
    return m_loc[0]->BadgeTooltip (m_loc,(ILxUnknownID)entry,badge,buf,len);
  }
    LxResult
  BadgeStarRatingOverride (ILxUnknownID entry, int *rating, char *buf, int len)
  {
    return m_loc[0]->BadgeStarRatingOverride (m_loc,(ILxUnknownID)entry,rating,buf,len);
  }
    LxResult
  BadgeAction (ILxUnknownID entry, int badge)
  {
    return m_loc[0]->BadgeAction (m_loc,(ILxUnknownID)entry,badge);
  }
    LxResult
  BadgeStarRatingAction (ILxUnknownID entry, int rating)
  {
    return m_loc[0]->BadgeStarRatingAction (m_loc,(ILxUnknownID)entry,rating);
  }
};

#endif

