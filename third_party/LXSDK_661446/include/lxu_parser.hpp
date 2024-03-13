/*
 * Plug-in SDK Header: C++ Wrapper Classes
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
 * General I/O Wrappers
 */
#ifndef LX_PARSER_HPP
#define LX_PARSER_HPP

#include <lxw_io.hpp>

#include <string.h>
#include <string>


/*
 * ----------------------------------------------------------------
 * Abstract string parser class. The virtual methods provide a peek at
 * the next character and a way to advance. The methods will not advance
 * past a null character, except PullExpected(0).
 *
 * All these methods are valid only for 7-bit ASCII, so they can be used
 * for data files and command args, but not translated user strings.
 */
class CLxStringParser :
                public CLxObject
{
    public:
        /*
         * Implement to return the next character to be read, returning
         * zero for the end of input (required).
         */
        virtual const char	 sp_peek () const = 0;

        /*
         * Implement to advance the input by one character (required).
         */
        virtual void		 sp_advance () = 0;

        /*
         * Call to test if the input has been completely read.
         */
        bool			 Done          ();

        /*
         * Call to advance the input past whitespace.
         */
        void			 PullWhite     ();

        /*
         * Call to advance the input past non-whitespace.
         */
        void			 PullNonWhite  ();

        /*
         * Call to advance the input past non-whitespace, capturing the input
         * as a string.
         */
        void			 PullNonWhite  (std::string &dest);

        /*
         * Call to advance the input past characters matching characters in the
         * mask string, capturing the input as a string.
         */
        void			 PullDown      (std::string &dest, const char *mask);

        /*
         * Call to read and return a float from the input, returning true if a
         * valid number was found.
         */
        bool			 PullNum       (float *);

        /*
         * Call to read and return a double from the input, returning true if a
         * valid number was found.
         */
        bool			 PullNum       (double *);

        /*
         * Call to read and return an unsigned int from the input, returning true if a
         * valid number was found.
         */
        bool			 PullNum       (unsigned *);

        /*
         * Call to read and return a signed int from the input, returning true if a
         * valid number was found.
         */
        bool			 PullNum       (int *);

        /*
         * Call to advance past a single character, returning true if it matches
         * the argument.
         */
        bool			 PullExpected  (char);

        /*
         * Call to test if a character is whitespace.
         */
        static bool		 IsBlank (char);

        /*
         * Call to test if a character is numeric.
         */
        static bool		 IsDigit (char);

        /*
         * Call to test if a character matches any of the characters in the
         * mask string.
         */
        static bool		 Matches (char, const char *mask);

        /*
         * Call to test if a character is uppercase.
         */
        static char		 Upper   (char);

        /*
         * Call to test if a character is lowercase.
         */
        static char		 Lower   (char);
};


/*
 * A concrete parser to be used for a specific string and then discarded,
 * or the string can be reset for multiple uses.
 */
class CLxParseString :
                public CLxStringParser
{
    public:
        CLxParseString (const char *initPtr)
        {
                SetString (initPtr);
        }

        CLxParseString (const std::string &initStr)
        {
                SetString (initStr.c_str());
        }

                void
        SetString (const char *newPtr)
        {
                str_val = newPtr;
                str_pos = 0;
        }

    //internal:
        std::string		 str_val;
        int			 str_pos;

        const char	 sp_peek () const LXx_OVERRIDE { return str_val[str_pos]; }
        void		 sp_advance () LXx_OVERRIDE    { str_pos++; }
};


/*
 * ----------------------------------------------------------------
 * Abstract file parser class. Used as a framework for loader wrappers.
 * The details of the format should be specified by the client.
 */
class CLxFileParser :
                public CLxObject
{
    public:
        /*
         * Implement to open a named file (required).
         */
        virtual bool		 fp_Open       (const char *)	= 0;

        /*
         * Implement to set a monitor for file progress (required).
         */
        virtual void		 fp_SetMonitor (LXtObjectID)	= 0;

        /*
         * Implement to return true if there have been file errors (required).
         */
        virtual bool		 fp_HasError   ()		= 0;

        /*
         * Implement to return the result code (required).
         */
        virtual LxResult	 fp_ErrorCode  ()		= 0;

        /*
         * Implement to close file and cleanup (required).
         */
        virtual void		 fp_Cleanup    ()		= 0;

        const char		*file_name;
};

/*
 * ----------------------------------------------------------------
 * Parser for general line-based text formats. Can be easily subclassed
 * to alter the maximum line size, and how to handle whitespace, blank
 * lines and comments. Lines are read into a buffer and can then be parsed
 * using the string parser.
 */
class CLxLineParser :
                public CLxStringParser,
                public CLxFileParser
{
    public:
        /*
         * Implement to read the next line into the parser buffer.
         */
        virtual bool		 lp_ReadLine   (bool force = false);

        /*
         * Implement to test if the line is a comment (defaults to never).
         */
        virtual bool		 lp_IsComment  ()	{ return false; }

        /*
         * Implement to test if the line is continued on the next input line
         * (defaults to never).
         */
        virtual bool		 lp_Continue   ()	{ return false; }

        /*
         * Implement to direct that leading whitespace should be ignored
         * (defaults to false).
         */
        virtual bool		 lp_StripWhite ()	{ return false; }

        /*
         * Implement to direct that blank lines are ignored (defaults to false).
         */
        virtual bool		 lp_SkipBlank  ()	{ return false; }

    //internal:
        const char		 sp_peek () const LXx_OVERRIDE { return cur_pos[0]; }
        void			 sp_advance ()    LXx_OVERRIDE { cur_pos++; }

        char			*line_buf;
        char			*cur_pos;

         CLxLineParser ();
        ~CLxLineParser ();

        virtual bool		 fp_Open       (const char *)	LXx_OVERRIDE;
        virtual void		 fp_SetMonitor (LXtObjectID)	LXx_OVERRIDE;
        virtual bool		 fp_HasError   ()		LXx_OVERRIDE;
        virtual LxResult	 fp_ErrorCode  ()		LXx_OVERRIDE;
        virtual void		 fp_Cleanup    ()		LXx_OVERRIDE;

        void			 set_line (const char *);
        class pv_LineParser	*pv;
};

/*
 * ----------------------------------------------------------------
 * Parser for general binary formats.
 */
class CLxBinaryParser :
                public CLxFileParser
{
    public:
        /*
         * Call to read a block of data from the file into a buffer.
         */
        bool			 PullBlock (void *buf, size_t size);

        /*
         * Call to return the number of characters from the current position
         * to the next zero byte.
         */
        size_t			 StringLen ();

        /*
         * Call to read a string from the file.
         */
        bool			 PullString (char *text, size_t maxSize = 0);

        /*
         * Call to read a 4-byte float from the file.
         */
        bool			 PullNum (float *value);

        /*
         * Call to read an 8-byte float from the file.
         */
        bool			 PullNum (double *value);

        /*
         * Call to read a 4-byte unsigned int from the file.
         */
        bool			 PullNum (unsigned *value);

        /*
         * Call to read a 4-byte signed int from the file.
         */
        bool			 PullNum (int *value);

    //internal:
         CLxBinaryParser ();
        ~CLxBinaryParser ();

        virtual bool		 fp_Open       (const char *)	LXx_OVERRIDE;
        virtual void		 fp_SetMonitor (LXtObjectID)	LXx_OVERRIDE;
        virtual bool		 fp_HasError   ()		LXx_OVERRIDE;
        virtual LxResult	 fp_ErrorCode  ()		LXx_OVERRIDE;
        virtual void		 fp_Cleanup    ()		LXx_OVERRIDE;

        unsigned		 cur_pos;

        class pv_BinaryParser	*pv;
};

namespace lx
{
        /*
         * Convert a string to a floating-point number.
         */
        bool			 Decode (const char *,  double *);

        /*
         * Convert a string to a floating-point number.
         */
        bool			 Decode (std::string &, double *);

        /*
         * Convert a string to a floating-point number.
         */
        bool			 Decode (const char *,  float *);

        /*
         * Convert a string to a floating-point number.
         */
        bool			 Decode (std::string &, float *);
};

#endif /* LX_PARSER_HPP */

