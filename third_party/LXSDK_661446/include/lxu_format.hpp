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
#ifndef LX_FORMAT_HPP
#define LX_FORMAT_HPP

#include <lxw_io.hpp>
#include <string>


/*
 * ----------------------------------------------------------------
 * Abstract file format class. Used as a framework for saver wrappers.
 * The details of the format should be specified by the client.
 */
class CLxFileFormat
{
    public:
        virtual			~CLxFileFormat () {}

        virtual bool		 ff_Open       (const char *)	= 0;
        virtual void		 ff_Enable     (bool)		= 0;
        virtual bool		 ff_HasError   ()		= 0;
        virtual void		 ff_Cleanup    ()		= 0;

        const char		*file_name;
};


/*
 * ----------------------------------------------------------------
 * Format for general line-based text files.
 */
class CLxLineFormat : public CLxFileFormat
{
    public:
                                 CLxLineFormat ();
        virtual			~CLxLineFormat ();

        virtual bool		 ff_Open       (const char *)	LXx_OVERRIDE;
        virtual void		 ff_Enable     (bool)		LXx_OVERRIDE;
        virtual bool		 ff_HasError   ()		LXx_OVERRIDE;
        virtual void		 ff_Cleanup    ()		LXx_OVERRIDE;

        virtual const char *	 lf_Separator  ()		{ return ""; }
        virtual void		 lf_Raw        (const char *);
        virtual void		 lf_Delim      ();
        virtual void		 lf_Break      (bool force = false);

        virtual void		 lf_Output     (std::string &, bool delim = true);
        virtual void		 lf_Output     (const char *,  bool delim = true);
        virtual void		 lf_Quote      (const char *,  bool delim = true);
        virtual void		 lf_Output     (double,        bool delim = true);
        virtual void		 lf_Output     (int,           bool delim = true);
        virtual void		 lf_Output     (unsigned,      bool delim = true);

        bool			 start_of_line;

    private:
        class pv_LineFormat	*pv;
};

/*
 * ----------------------------------------------------------------
 * Format for general binary files.
 */
class CLxBinaryFormat : public CLxFileFormat
{
    public:
                                 CLxBinaryFormat ();
        virtual			~CLxBinaryFormat ();

        virtual bool		 ff_Open       (const char *)	LXx_OVERRIDE;
        virtual void		 ff_Enable     (bool)		LXx_OVERRIDE;
        virtual bool		 ff_HasError   ()		LXx_OVERRIDE;
        virtual void		 ff_Cleanup    ()		LXx_OVERRIDE;

        virtual void		 lf_Output     (std::string &);
        virtual void		 lf_Output     (const char *str);
        virtual void		 lf_Output     (float value);
        virtual void		 lf_Output     (double value);
        virtual void		 lf_Output     (int value);
        virtual void		 lf_Output     (unsigned value);

    private:
        class pv_BinaryFormat	*pv;
};

namespace lx
{
        /*
         * Encode a double for writing to text files. This always uses "." as the
         * decimal separator regardless of locale settings.
         */
        void			 Encode (double, std::string &);
        std::string		 Encode (double);

        /*
         * Encode an int.
         */
        std::string		 Encode (int);

        /*
         * Conversions between ID4 code and string.
         */
        LXtID4			 StringID4 (const char *);
        std::string		 ID4String (LXtID4);
};

#endif /* LX_FORMAT_HPP */

