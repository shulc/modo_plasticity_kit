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
 * General I/O
 */

/*
 * Disable deprecated function warning.
 */
#pragma warning(disable: 4996)

#include <lxu_format.hpp>
#include <lx_wrap.hpp>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

/*
 * ----------------------------------------------------------------
 * CLxLineFormat : Implementation
 *
 * Private data is the filename string and the file stream.  Since streams
 * have problems being closed and re-opened we allocate a new one for each
 * file.
 */
class pv_LineFormat {
    public:
        string			 s_filename;
        ofstream		*out_file;
        bool			 do_output;
};


CLxLineFormat::CLxLineFormat ()
{
        pv = new pv_LineFormat;
        pv->s_filename = "";
        pv->out_file   = 0;
        pv->do_output  = 0;
}

CLxLineFormat::~CLxLineFormat ()
{
        ff_Cleanup ();
        delete pv;
}

        bool
CLxLineFormat::ff_Open (
        const char		*filename)
{
        ff_Cleanup ();

        pv->s_filename = filename;
        file_name = pv->s_filename.c_str ();

        pv->out_file = new ofstream;
        pv->out_file->open (filename, ifstream::out);

        start_of_line = true;
        pv->do_output = true;
        return pv->out_file->good ();
}

        void
CLxLineFormat::ff_Enable (
        bool			 enable)
{
        pv->do_output = enable;
}

        bool
CLxLineFormat::ff_HasError ()
{
        return !pv->out_file || (!pv->out_file->eof () && !pv->out_file->good ());
}

        void
CLxLineFormat::ff_Cleanup ()
{
        pv->s_filename = "";
        if (pv->out_file) {
                delete pv->out_file;
                pv->out_file = 0;
        }
}


        void
CLxLineFormat::lf_Raw (
        const char		*raw)
{
        if (pv->do_output) {
                (pv->out_file[0]) << raw;
                start_of_line = false;
        }
}

        void
CLxLineFormat::lf_Delim ()
{
        if (!start_of_line)
                lf_Raw (lf_Separator ());
}

        void
CLxLineFormat::lf_Break (
        bool			 force)
{
        if (force || !start_of_line) {
                lf_Raw ("\n");
                start_of_line = true;
        }
}

        void
CLxLineFormat::lf_Output (
        std::string		&str,
        bool			 delim)
{
        lf_Output (str.c_str(), delim);
}

        void
CLxLineFormat::lf_Output (
        const char		*str,
        bool			 delim)
{
        if (delim)
                lf_Delim ();

        lf_Raw (str);
}

        void
CLxLineFormat::lf_Quote (
        const char		*str,
        bool			 delim)
{
        char			 cs[2];

        if (delim)
                lf_Delim ();

        if (strchr (str, ' ') || strchr (str, '\t')) {
                lf_Raw ("\"");
                for (cs[1] = 0; *str; str++)
                        if (*str == '"')
                                lf_Raw ("\\\"");
                        else {
                                cs[0] = *str++;
                                lf_Raw (cs);
                        }

                lf_Raw ("\"");
        } else
                lf_Raw (str);
}

        void
CLxLineFormat::lf_Output (
        double			 value,
        bool			 delim)
{
        std::string		 num;

        if (delim)
                lf_Delim ();

        lx::Encode (value, num);
        lf_Raw (num.c_str ());
}

        void
CLxLineFormat::lf_Output (
        int			 value,
        bool			 delim)
{
        char			 buf[20];

        if (delim)
                lf_Delim ();

        sprintf (buf, "%d", value);
        lf_Raw (buf);
}

        void
CLxLineFormat::lf_Output (
        unsigned		 value,
        bool			 delim)
{
        char			 buf[20];

        if (delim)
                lf_Delim ();

        sprintf (buf, "%d", value);
        lf_Raw (buf);
}

/*
 * ----------------------------------------------------------------
 * CLxBinaryFormat : Implementation
 *
 * Private data is the filename string and the file stream.  Since streams
 * have problems being closed and re-opened we allocate a new one for each
 * file.
 */
class pv_BinaryFormat {
    public:
        string			 s_filename;
        ofstream		*out_file;
        bool			 do_output;
};


CLxBinaryFormat::CLxBinaryFormat ()
{
        pv = new pv_BinaryFormat;
        pv->s_filename = "";
        pv->out_file   = 0;
        pv->do_output  = 0;
}

CLxBinaryFormat::~CLxBinaryFormat ()
{
        ff_Cleanup ();
        delete pv;
}

        bool
CLxBinaryFormat::ff_Open (
        const char		*filename)
{
        ff_Cleanup ();

        pv->s_filename = filename;
        file_name = pv->s_filename.c_str ();

        pv->out_file = new ofstream;
        pv->out_file->open (filename, ifstream::out | ifstream::binary);

        pv->do_output = true;
        return pv->out_file->good ();
}

        void
CLxBinaryFormat::ff_Enable (
        bool			 enable)
{
        pv->do_output = enable;
}

        bool
CLxBinaryFormat::ff_HasError ()
{
        return !pv->out_file || (!pv->out_file->eof () && !pv->out_file->good ());
}

        void
CLxBinaryFormat::ff_Cleanup ()
{
        pv->s_filename = "";
        if (pv->out_file) {
                delete pv->out_file;
                pv->out_file = 0;
        }
}

        void
CLxBinaryFormat::lf_Output (
        std::string		&str)
{
        lf_Output (str.c_str());
}

        void
CLxBinaryFormat::lf_Output (
        const char		*str)
{
        if (pv->do_output) {
                /*
                 * Binary strings are null-terminated.
                 */
                pv->out_file->write (
                        str,
                        string(str).length () + 1);
        }
}

        void
CLxBinaryFormat::lf_Output (
        float			 value)
{
        if (pv->do_output) {
                pv->out_file->write (
                        reinterpret_cast<char*>(&value),
                        sizeof(float));
        }
}

        void
CLxBinaryFormat::lf_Output (
        double			 value)
{
        if (pv->do_output) {
                pv->out_file->write (
                        reinterpret_cast<char*>(&value),
                        sizeof(double));
        }
}

        void
CLxBinaryFormat::lf_Output (
        int			 value)
{
        if (pv->do_output) {
                pv->out_file->write (
                        reinterpret_cast<char*>(&value),
                        sizeof(int));
        }
}

        void
CLxBinaryFormat::lf_Output (
        unsigned		 value)
{
        if (pv->do_output) {
                pv->out_file->write (
                        reinterpret_cast<char*>(&value),
                        sizeof(unsigned));
        }
}


        void
lx::Encode (
        double			 value,
        std::string		&buffer)
{
        char			*sep, tmp[64];

        sprintf (tmp, "%g", value);
        sep = strchr (tmp, ',');
        if (sep)
                sep[0] = '.';

        buffer = tmp;
}

        std::string
lx::Encode (
        double			 value)
{
        std::string		 res;

        lx::Encode (value, res);
        return res;
}

        std::string
lx::Encode (
        int			 value)
{
        char			 tmp[64];

        sprintf (tmp, "%d", value);
        return std::string (tmp);
}


static LXtID4			 id4_ABCD = LXxID4('A','B','C','D');

        LXtID4
lx::StringID4 (
        const char		*string)
{
        char			 s[5] = { ' ', ' ', ' ', ' ' };
        int			 len = strlen (string);

        strncpy (s, string, len < 4 ? len : 4);

        if (((char *)&id4_ABCD)[0] == 'A') 	
                return LXxID4 (s[3], s[2], s[1], s[0]);
        else
                return LXxID4 (s[0], s[1], s[2], s[3]);
}

        std::string
lx::ID4String (
        LXtID4			 id)
{
        static char 		 buf[5] = "";
        char			*c;
        
        c = (char *)&id;
        if (((char *)&id4_ABCD)[0] == 'A')
                sprintf (buf, "%c%c%c%c", c[0], c[1], c[2], c[3]);
        else
                sprintf (buf, "%c%c%c%c", c[3], c[2], c[1], c[0]);

        return std::string (buf);
}


