/*
 * LX pattern module
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
#ifndef LX_pattern_H
#define LX_pattern_H

typedef struct vt_ILxPattern ** ILxPatternID;


/*
 * The Test method returns LXe_TRUE or LXe_FALSE for the specified index in the
 * pattern. The offset for the index can be specified. For example, if the pattern
 * True, False, True, True, False, and the index is 1 and the offset is 0, the
 * return value would be LXe_FALSE. However, if the offset is 2, the returned value
 * would match the fourth element in the pattern and return LXe_TRUE.
 * 
 * Given a start index and an end index, this method will return a comma seperated
 * string populated with any number between the start and end index, masked by the
 * filter. For example if the pattern is True, False, True, True, False, and the
 * start and end of the range is 0 and 9 respectively, the returned string will be
 * "0,2,3,5,7,8". Similar to the Test method, the offset argument allows the pattern
 * to be offset.
 */
typedef struct vt_ILxPattern {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
Test) (
        LXtObjectID		 self,
        int			 index,
        int			 offset);
        LXxMETHOD( LxResult,
GenerateSequenceString) (
        LXtObjectID		 self,
        int			 start,
        int			 end,
        char			*buf,
        unsigned int		 len);
} ILxPattern;

/*
 * The Pattern Value type presents an ILxValue object, allowing the pattern to be
 * set from a string, as well as String Conversion and String Conversion Nice to
 * allow the value to be encoded and decoded as a string. A StreamIO interface
 * allows the pattern to be written to an external file format, and a ValueArray
 * interface is provided, allowing elements in the pattern to be accessed as
 * booleans. Finally, the object provides an ILxPattern interface, allowing the
 * pattern to be tested, and converted into a sequence.
 */

        #define LXsTYPE_PATTERN		"+pattern"

/*
 * The ILxPattern interface is used by the Pattern ExoType. Patterns can be used to
 * mask a sequence when iterating over some entity. Patterns are defined as a
 * sequence of True/False values, seperated by a comma. The user can enter 0 or 1,
 * True or False, T or F, and Yes or No, to determine if an element in a sequence is
 * masked by a pattern.
 */

        #define LXu_PATTERN		"16EE409B-6B63-4CB0-8DE6-C3D9AD124DBE"
        #define LXa_PATTERN		"pattern"
        //[local]  ILxPattern
        //[const]  ILxPattern:Test
        //[const]  ILxPattern:GenerateSequenceString
        //[python] ILxPattern:Test		bool

#endif
