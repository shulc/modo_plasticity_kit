/*
 * Plug-in SDK Header: Common Utility
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
 *
 * Preference value access.  This is implemented as a helper utility to
 * encapsulate the command interfaces, which are undocumented and subject
 * to change.
 */
#include <lx_command.hpp>
#include <lxu_prefvalue.hpp>

/*
 * Scene Export preference values.
 */
const char* LXsPREFERENCE_VALUE_EXPORT_AUTHOR		= "export.author";
const char* LXsPREFERENCE_VALUE_EXPORT_COPYRIGHT	= "export.copyright";
const char* LXsPREFERENCE_VALUE_EXPORT_ABSOLUTE_PATH	= "export.absPath";
const char* LXsPREFERENCE_VALUE_EXPORT_MERGE_REFS	= "export.mergsRefs";

/*
 * Accuracy and Units preference values.
 */
const char* LXsPREFERENCE_VALUE_ACCURACY_UNIT_SYSTEM	= "units.system";
const char* LXsPREFERENCE_VALUE_METERS_PER_GAME_UNIT	= "units.gameScale";
const char* LXsPREFERENCE_VALUE_ACCURACY_DEFAULT_UNIT	= "units.default";

/*
 * Up Axis.
 */
const char* LXsPREFERENCE_VALUE_ACCURACY_UP_AXIS	= "units.upAxis";

/*
 * Animation.
 */

const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_FILM_24           = "film";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_PAL_25            = "pal";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_NTSC_29           = "ntsc29";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_NTSC_30           = "ntsc30";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_CUSTOM            = "custom";
 
const char* LXsPREFERENCE_VALUE_ANIMATION_AUTO_KEY              = "animation.autoKey";
const char* LXsPREFERENCE_VALUE_ANIMATION_CHANNEL_BEHAVIOR      = "animation.envBehavior";
const char* LXsPREFERENCE_VALUE_ANIMATION_CHANNEL_INTERPOLATION = "animation.envInterp";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS                   = "animation.fps";
const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_CUSTOM_RATE       = "animation.fpsCustom";
const char* LXsPREFERENCE_VALUE_ANIMATION_LINK_KEYS             = "animation.linkKeys";
const char* LXsPREFERENCE_VALUE_ANIMATION_PRESERVE_KEY_TIMING   = "animation.fpsKeepTiming";
const char* LXsPREFERENCE_VALUE_ANIMATION_ROTATION_ORDER        = "animation.rotOrder";
const char* LXsPREFERENCE_VALUE_ANIMATION_SLOPE_TYPE            = "animation.slopeType";
const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_RANGE_START      = "animation.timeRangeS";
const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_RANGE_END        = "animation.timeRangeE";
const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_SNAP             = "animation.timeSnap";
const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_SYSTEM           = "animation.timeSys";




