/*
 * Plug-in SDK Header: C++ Services
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
 * Helper class for getting preference values.
 */
#ifndef LX_PREFERENCEVALUE_HPP
#define LX_PREFERENCEVALUE_HPP

#include <lxu_queries.hpp>

/*
 * Scene Export preference values.
 */
extern const char* LXsPREFERENCE_VALUE_EXPORT_AUTHOR;
extern const char* LXsPREFERENCE_VALUE_EXPORT_COPYRIGHT;
extern const char* LXsPREFERENCE_VALUE_EXPORT_ABSOLUTE_PATH;
extern const char* LXsPREFERENCE_VALUE_EXPORT_MERGE_REFS;

/*
 * Accuracy and Units preference values.
 */
extern const char* LXsPREFERENCE_VALUE_ACCURACY_UNIT_SYSTEM;
extern const char* LXsPREFERENCE_VALUE_METERS_PER_GAME_UNIT;

/*
 * Unit Systems.
 */
enum {
        LXiPREFERENCE_VALUE_UNIT_SYSTEM_SI,
        LXiPREFERENCE_VALUE_UNIT_SYSTEM_METRIC,
        LXiPREFERENCE_VALUE_UNIT_SYSTEM_ENGLISH,
        LXiPREFERENCE_VALUE_UNIT_SYSTEM_GAME_UNITS,
        LXiPREFERENCE_VALUE_UNIT_SYSTEM_UNITLESS
};

extern const char* LXsPREFERENCE_VALUE_ACCURACY_DEFAULT_UNIT;

/*
 * SI Units.
 */
enum {
        LXsPREFERENCE_VALUE_UNIT_SI_MICRONS,
        LXsPREFERENCE_VALUE_UNIT_SI_MILLIMETERS,
        LXsPREFERENCE_VALUE_UNIT_SI_METERS,
        LXsPREFERENCE_VALUE_UNIT_SI_KILOMETERS,
        LXsPREFERENCE_VALUE_UNIT_SI_MEGAMETERS
};

/*
 * Metric Units.
 */
enum {
        LXsPREFERENCE_VALUE_UNIT_METRIC_MICRONS,
        LXsPREFERENCE_VALUE_UNIT_METRIC_MILLIMETERS,
        LXsPREFERENCE_VALUE_UNIT_METRIC_CENTIMETERS,
        LXsPREFERENCE_VALUE_UNIT_METRIC_METERS,
        LXsPREFERENCE_VALUE_UNIT_METRIC_KILOMETERS,
        LXsPREFERENCE_VALUE_UNIT_METRIC_MEGAMETERS
};

/*
 * English Units.
 */
enum {
        LXsPREFERENCE_VALUE_UNIT_ENGLISH_MILS,
        LXsPREFERENCE_VALUE_UNIT_ENGLISH_INCHES,
        LXsPREFERENCE_VALUE_UNIT_ENGLISH_FEET,
        LXsPREFERENCE_VALUE_UNIT_ENGLISH_MILES
};

/*
 * Up Axis.
 */
extern const char* LXsPREFERENCE_VALUE_ACCURACY_UP_AXIS;

/*
 * X, Y, and Z Up Axis.
 */
enum {
        LXsPREFERENCE_VALUE_UP_AXIS_X,
        LXsPREFERENCE_VALUE_UP_AXIS_Y,
        LXsPREFERENCE_VALUE_UP_AXIS_Z
};

/*
 * Animation.
 */

extern const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_FILM_24;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_PAL_25;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_NTSC_29;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_NTSC_30;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_CUSTOM;

#define LXiPVAL_ANIMATION_FPS_FILM_24    24.0
#define LXiPVAL_ANIMATION_FPS_PAL_25     25.0
#define LXiPVAL_ANIMATION_FPS_NTSC_29    29.97
#define LXiPVAL_ANIMATION_FPS_NTSC_30    30.0

extern const char* LXsPREFERENCE_VALUE_ANIMATION_AUTO_KEY;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_CHANNEL_BEHAVIOR;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_CHANNEL_INTERPOLATION;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_FPS;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_FPS_CUSTOM_RATE;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_LINK_KEYS;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_PRESERVE_KEY_TIMING;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_ROTATION_ORDER;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_SLOPE_TYPE;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_RANGE_START;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_RANGE_END;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_SNAP;
extern const char* LXsPREFERENCE_VALUE_ANIMATION_TIME_SYSTEM;

/*
 * This is a very simple class for reading preference values.
 * Preference values are presented in the Preferences panel.
 */
class CLxReadPreferenceValue : public CLxCommandQuery
{
    public:
        CLxReadPreferenceValue ()
                : CLxCommandQuery ("pref.value")
        {
        }

                bool
        Query (
                const char		*name)
        {
                if (!Arguments() . test ())
                        return false;

                if (!Arguments() . Set (0, name))
                        return false;

                if (!CLxCommandQuery::Query (1))
                        return false;

                return (Count () > 0);
        }
};

#endif	/* LX_PREFERENCEVALUE_HPP */

