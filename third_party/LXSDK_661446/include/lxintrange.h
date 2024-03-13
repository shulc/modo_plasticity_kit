/*
 * LX intrange module
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
#ifndef LX_intrange_H
#define LX_intrange_H

typedef struct vt_ILxIntRange ** ILxIntRangeID;


/*
 * These return true LXe_TRUE if there are leading or trailing ellipses, and LXe_FALSE
 * if not.
 * 
 * These functions allow the integer range to be walked.  The basic walking functions
 * are Next() and Prev() and increment the current position.  What is considered "next"
 * and "previous" is determined by if the list is being walked in numerical or user
 * order.  When there are no more integers left, the methods fail.
 * 
 * Numerical order starts at lowest integer in the range and goes to the highest
 * integer.  Example uses are print ranges, where you always want to print from
 * the first page to the last page.
 * User order starts from the first integer the user specified to the last, including
 * reversed ranges.  This is useful for things such as rendering sequences backward.
 * 
 * In both cases, each integer will be returned only once.  Note that these functions
 * will fail if the range consists entirely of "...", as there is no meaningful
 * beginning or end to the range.
 * 
 * Min() and Max() are used to get the lowest or highest integer and set the mode to
 * numerical order.
 * 
 * 
 * First() and Last() are used to get the first or last integer and set the mode to user
 * order.
 * 
 * This gets the current integer.
 * 
 * It is often useful to be able to simply test to see if an integer is within the range.
 * This returns LXe_TRUE if in range. This does not affect the current position used to
 * walk the range.
 */
typedef struct vt_ILxIntRange {
        ILxUnknown	 iunk;
        LXxMETHOD( LxResult,
AllBefore) (
        LXtObjectID		 self);

        LXxMETHOD( LxResult,
AllAfter) (
        LXtObjectID		 self);
        LXxMETHOD( LxResult,
Next) (
        LXtObjectID		 self,
        int			*i);

        LXxMETHOD( LxResult,
Prev) (
        LXtObjectID		 self,
        int			*i);
        LXxMETHOD( LxResult,
Min) (
        LXtObjectID		 self,
        int			*min);

        LXxMETHOD( LxResult,
Max) (
        LXtObjectID		 self,
        int			*max);
        LXxMETHOD( LxResult,
First) (
        LXtObjectID		 self,
        int			*first);

        LXxMETHOD( LxResult,
Last) (
        LXtObjectID		 self,
        int			*last);
        LXxMETHOD( LxResult,
Current) (
        LXtObjectID		 self,
        int			*current);
        LXxMETHOD( LxResult,
Test) (
        LXtObjectID		 self,
        int			 i);
} ILxIntRange;

/*
 * The ILxIntRange interface is used by the IntRange ExoType.  Ranges are entered as
 * strings, and are inclusive:  "1-5" matches 1, 2, 3, 4 and 5. A dash is used to specify
 * ranges, such as "1-20", commas add more ranges or specific integers, such as
 * "1-20,30,45-55", leading and trailing ellipses to mark all before and all after, such
 * as "...1-10,20-30", and can be used to specify an exclusive range with something like
 * "...0,11...". "..." by itself matches everything.  Negative numbers are supported,
 * such as "-1", "-1--30" or "-1-1".  Whites space is automatically skipped, making
 * negative numbers easier to read as "-1 - -30" or "-1 - 1", for example. Numbers can
 * be in reverse order, such as "10-20,5-10" or "20-10".  The range can be read in lowest
 * to highest numerical order or in the order the of the string.
 * A range that does not follow the rules, such as an ellipses in the middle of the
 * string, a dash without a number on the left side, no dash or comma between nubmers, or
 * any illegal characters, is considered failed and will return false to all requests.
 */

        #define LXu_INTRANGE		"FEAF19EC-B819-4C46-ABA3-EC8593F8BE8C"
        #define LXa_INTRANGE		"intrange"
        #define LXsTYPE_INTRANGE	"+intrange"
        //[local]  ILxIntRange
        //[const]  ILxIntRange:AllBefore
        //[const]  ILxIntRange:AllAfter
        //[const]  ILxIntRange:Current
        //[const]  ILxIntRange:Test
        //[python] ILxIntRange:AllBefore	bool
        //[python] ILxIntRange:AllAfter		bool
        //[python] ILxIntRange:Test		bool

#endif
