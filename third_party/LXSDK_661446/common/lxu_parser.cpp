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
#include <lxu_parser.hpp>
#include <lx_io.hpp>
#include <lx_wrap.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>

/*
 * Suppress warnings for deprecated functions.
 */
#ifdef _MSC_VER
        #define _CRT_SECURE_NO_WARNINGS 1
        #define _CRT_SECURE_NO_DEPRECATE 1
        #pragma warning(disable: 4996)
#endif

using namespace std;


/*
 * ----------------------------------------------------------------
 * CLxStringParser : Implementation
 *
 * The methods just look at the next character and advance sometimes. Ideally
 * we never advance past a null, except for PullExpected(0).
 */
        bool
CLxStringParser::Done ()
{
        return (sp_peek() == 0);
}

/*
 * PullWhite and PullNonWhite advance tpast characters of their respective
 * types.  PullNonWhite will read into an optional string.
 */
        void
CLxStringParser::PullWhite ()
{
        while (IsBlank (sp_peek()))
                sp_advance ();
}

        void
CLxStringParser::PullNonWhite ()
{
        while (!Done () && !IsBlank (sp_peek()))
                sp_advance ();
}

        void
CLxStringParser::PullNonWhite (
        string			&dest)
{
        dest = "";
        while (!Done () && !IsBlank (sp_peek()))
        {
                dest += sp_peek ();
                sp_advance ();
        }
}

/*
 * The various Pull* methods will read a values of various types from the
 * string, advancing past them.
 */
        void
CLxStringParser::PullDown (
        string			&dest,
        const char		*mask)
{
        dest = "";
        while (!Done () && !Matches (sp_peek(), mask))
        {
                dest += sp_peek ();
                sp_advance ();
        }
}

        bool
CLxStringParser::PullNum (
        float			*value)
{
        double			 d;

        if (!PullNum (&d))
                return false;

        value[0] = (float) d;
        return true;
}

        bool
CLxStringParser::PullNum (
        double			*value)
{
        string			 buf;

        PullWhite ();
        PullNonWhite (buf);
        if (!buf.length ())
                return false;

        return lx::Decode (buf, value);
}

        bool
CLxStringParser::PullNum (
        unsigned		*value)
{
        string			 buf;

        PullWhite ();
        while (IsDigit (sp_peek()))
        {
                buf += sp_peek ();
                sp_advance ();
        }

        if (!buf.length ())
                return false;

        buf += '\0';
        value[0] = atoi (buf.c_str ());
        return true;
}

        bool
CLxStringParser::PullNum (
        int			*value)
{
        int			sign;
        unsigned		uval;

        PullWhite ();
        if (PullExpected ('-'))
                sign = -1;
        else
                sign = 1;

        if (!PullNum (&uval))
                return false;

        *value = uval * sign;
        return true;
}

        bool
CLxStringParser::PullExpected (
        char			 c)
{
        PullWhite ();
        if (sp_peek() != c)
                return false;

        sp_advance ();
        return true;
}

/*
 * Static methods for testing 7-bit ASCII character types.
 */
        bool
CLxStringParser::IsBlank (
        char			 c)
{
        return (c == ' ' || c == '\t' || c == '\n');
}

        bool
CLxStringParser::IsDigit (
        char			 c)
{
        return (c >= '0' && c <= '9');
}

        bool
CLxStringParser::Matches (
        char			 c,
        const char		*mask)
{
        for (int i = 0; mask[i]; i++)
                if (c == mask[i])
                        return true;

        return false;
}

        char
CLxStringParser::Upper (
        char			 c)
{
        if (c >= 'a' && c <= 'z')
                return c - 'a' + 'A';
        else
                return c;
}

        char
CLxStringParser::Lower (
        char			 c)
{
        if (c >= 'A' && c <= 'Z')
                return c - 'A' + 'a';
        else
                return c;
}



/*
 * ----------------------------------------------------------------
 * CLxLineParser : Implementation
 *
 * Private data is the filename string and the file stream. Since streams
 * have problems being closed and re-opened we allocate a new one for each
 * file.
 */
class pv_LineParser {
    public:
        pv_LineParser ();
        bool			 Open     (const char *name);
        void			 Close    ();
        void			 InitMon  ();
        void			 ReadLine (string &);

        string			 filename;	// filename for reading
        FILE			*file;		// file stream, when open
        CLxUser_Monitor		 mon;		// read progress monitor
        bool			 moninit;	// true if monitor needs init
        LxResult		 error;		// last error, if any
        unsigned int		 length;	// total file length
        unsigned int		 pos, monPos;	// current position, monitor position
        size_t			 bufLen;	// size of line_buf
};


pv_LineParser::pv_LineParser ()
{
        filename = "";
        file     = 0;
        moninit  = false;
        error    = LXe_FALSE;
        bufLen   = 0;
}

        bool
pv_LineParser::Open (
        const char		*name)
{
        filename = name;

        file = fopen (filename.c_str (), "rb");
        if (!file) {
                error = LXe_NOTFOUND;
                return false;
        }

        fseek (file, 0, SEEK_END);
        length = ftell (file);
        fseek (file, 0, SEEK_SET);

        if (ferror (file)) {
                error = LXe_IO_ERROR;
                return false;
        }

        pos     = 0;
        moninit = true;
        error   = LXe_OK;
        return true;
}

        void
pv_LineParser::InitMon ()
{
        if (mon.test () && moninit) {
                mon.Initialize (length);
                monPos	= pos;
                moninit = false;
        }
}

/*
 * Read a line from the input stream. Characters are appended to the dest
 * string, and we don't return until we get some kind of end-of-line
 * indicator. Special care needs to be taken for CR, LF and CRLF line endings,
 * depending on the platrform the file was created in.
 */
        void
pv_LineParser::ReadLine (
        string			&dest)
{
        int			 c, c1;

        while (1) {
                c = getc (file);
                pos++;

                if (!c || c == EOF)
                        return;

                if (c == '\n')  // LF found
                        return;

                if (c == '\r')  // CR found
                {
                        c1 = getc (file); 
                        if (!c1 || c1 == EOF || c1 == '\n') { // is next character EOF or LF?
                                pos++;
                                return; // end of file or CRLF found
                        }
                        ungetc(c1, file); // return first character of the next line back to the stream
                        return;
                }

                dest += c;
        }
}

        void
pv_LineParser::Close ()
{
        error = LXe_FALSE;
        filename = "";
        mon.clear ();
        moninit  = false;

        if (file) {
                fclose (file);
                file = 0;
        }
}


CLxLineParser::CLxLineParser ()
{
        pv = new pv_LineParser;

        cur_pos  = 0;
        line_buf = 0;
}

CLxLineParser::~CLxLineParser ()
{
        fp_Cleanup ();

        if (pv->bufLen)
        {
                delete[] line_buf;
                line_buf = 0;
        }

        delete pv;
}

        bool
CLxLineParser::fp_Open (
        const char		*filename)
{
        fp_Cleanup ();

        if (!pv->Open (filename))
                return false;

        file_name = pv->filename.c_str ();

        pv->InitMon ();
        return true;
}

        void
CLxLineParser::fp_SetMonitor (
        LXtObjectID		 monObj)
{
        pv->mon.set (monObj);
        pv->InitMon ();
}

        bool
CLxLineParser::fp_HasError ()
{
        return LXx_FAIL (pv->error);
}

        LxResult
CLxLineParser::fp_ErrorCode ()
{
        return pv->error;
}

        void
CLxLineParser::fp_Cleanup ()
{
        pv->Close ();
        cur_pos = 0;

}

        void
CLxLineParser::set_line (
        const char		*buf)
{
        size_t			 len = strlen (buf) + 24;

        if (pv->bufLen < len)
        {
                if (pv->bufLen)
                        delete [] line_buf;

                line_buf = new char [len];
                pv->bufLen = len;
        }

        strcpy (line_buf, buf);
}

        bool
CLxLineParser::lp_ReadLine (
        bool			 force)
{
        LxResult		 rc;
        unsigned int		 len;
        bool			 blank;

        if (fp_HasError ())
                return false;

        if (!pv->file || ferror (pv->file)) {
                pv->error = LXe_IO_ERROR;
                return false;
        }

        if (pv->mon.test () && pv->pos > pv->monPos) {
                rc = pv->mon.Increment (pv->pos - pv->monPos);
                pv->monPos = pv->pos;
                if (LXx_FAIL (rc)) {
                        pv->error = rc;
                        return false;
                }
        }

        do {
                string		 buf;
                char		*s;

                while (1) {
                        pv->ReadLine (buf);
                        if (ferror (pv->file)) {
                                pv->error = LXe_IO_ERROR;
                                return false;
                        }

                        if (!buf.size() && feof (pv->file)) {
                                if (force)
                                        pv->error = LXe_IO_ERROR;

                                return false;
                        }

                        set_line (buf.c_str ());

                        // check for if to Continue
                        bool shouldContinue = lp_Continue();

                        // if we don't already have to continue and haven't just got a continue, break
                        if( !shouldContinue )
                                break;

                        buf = line_buf;
                }

                if (lp_StripWhite ()) {
                        for (s = line_buf; *s && IsBlank (*s); s++)
                                ;

                        len = static_cast<unsigned int>(strlen (s));
                        if (s != line_buf)
                                memmove (line_buf, s, len + 1);

                        while (len && IsBlank (line_buf[len - 1]))
                                line_buf[--len] = 0; 
                }

                blank = lp_SkipBlank ();
                for (s = line_buf; *s && blank; s++)
                        if (!IsBlank (*s))
                                blank = false;

        } while (blank || lp_IsComment ());

        cur_pos = line_buf;
        return true;
}


/*
 * ----------------------------------------------------------------
 * CLxBinaryParser : Implementation
 */

class pv_BinaryParser {
    public:
                                 pv_BinaryParser ();
        void			 InitMon ();
        char *			 ReadLine (char *, unsigned &);

        string			 filename;
        FILE			*file;
        CLxUser_Monitor		 mon;
        LxResult		 error;
        unsigned int		 length, pos;
        bool			 moninit;
};

pv_BinaryParser::pv_BinaryParser ()
{
        filename = "";
        file     = 0;
        error    = LXe_FALSE;
        moninit  = 0;
}

        void
pv_BinaryParser::InitMon ()
{
        if (mon.test () && moninit) {
                mon.Initialize (length);
                pos     = 0;
                moninit = 0;
        }
}

CLxBinaryParser::CLxBinaryParser ()
{
        pv = new pv_BinaryParser;
}

CLxBinaryParser::~CLxBinaryParser ()
{
        fp_Cleanup ();
}

        bool
CLxBinaryParser::fp_Open (
        const char		*filename)
{
        fp_Cleanup ();

        pv->filename = filename;
        file_name = pv->filename.c_str ();

        /*
         * Open the file for reading in binary mode.
         */
        pv->file = fopen (filename, "rb");
        if (!pv->file) {
                pv->error = LXe_NOTFOUND;
                return false;
        }

        fseek (pv->file, 0, SEEK_END);
        pv->length = ftell (pv->file);
        fseek (pv->file, 0, SEEK_SET);

        if (ferror (pv->file)) {
                pv->error = LXe_IO_ERROR;
                return false;
        }

        pv->moninit = 1;
        pv->InitMon ();

        pv->error = LXe_OK;
        return true;
}

        void
CLxBinaryParser::fp_SetMonitor (
        LXtObjectID		 monObj)
{
        pv->mon.set (monObj);
        pv->InitMon ();
}

        bool
CLxBinaryParser::fp_HasError ()
{
        return LXx_FAIL (pv->error);
}

        LxResult
CLxBinaryParser::fp_ErrorCode ()
{
        return pv->error;
}

        void
CLxBinaryParser::fp_Cleanup ()
{
        pv->error = LXe_FALSE;
        pv->filename = "";
        pv->mon.clear ();
        pv->moninit  = 0;
        cur_pos = 0;

        if (pv->file) {
                fclose (pv->file);
                pv->file = 0;
        }
}

        bool
CLxBinaryParser::PullBlock (void *buf, size_t size)
{
        bool	pulled(false);

        if (buf) {
                size_t bytesRead = fread (
                        buf, 1, size, pv->file);

                pulled = (bytesRead == size);
        }
        else {
                fseek (pv->file, static_cast<long>(size), SEEK_CUR);
                pulled = true;
        }

        return pulled;
}

        size_t
CLxBinaryParser::StringLen ()
{
        size_t length(0);

        unsigned savPos = ftell (pv->file);

        unsigned char charBuf(0xFF);
        do {
                size_t bytesRead = fread (&charBuf, 1, 1, pv->file);
                if ((bytesRead == 1) && (charBuf != 0)) {
                        ++length;
                }
                else {
                        break;
                }
        } while (true);

        fseek (pv->file, savPos, SEEK_CUR);

        return length;
}

        bool
CLxBinaryParser::PullString (char *text, size_t maxSize)
{
        char *buf = text;

        bool haveString(true);
        size_t length(0);

        do {
                size_t bytesRead = fread (buf, 1, 1, pv->file);
                if ((bytesRead == 1) && (*buf != 0)) {
                        ++length;
                        if (maxSize && length >= maxSize) {
                                break;
                        }
                }
                else {
                        haveString = (bytesRead == 1);
                        break;
                }
                ++buf;
        } while (true);

        return haveString;
}

        bool
CLxBinaryParser::PullNum (float *value)
{
        size_t bytesRead = fread (
                value, 1, sizeof(float), pv->file);

        return (bytesRead == sizeof(float));
}

        bool
CLxBinaryParser::PullNum (double *value)
{
        size_t bytesRead = fread (
                value, 1, sizeof(double), pv->file);

        return (bytesRead == sizeof(double));
}

        bool
CLxBinaryParser::PullNum (unsigned *value)
{
        size_t bytesRead = fread (
                value, 1, sizeof(unsigned), pv->file);

        return (bytesRead == sizeof(unsigned));
}

        bool
CLxBinaryParser::PullNum (int *value)
{
        size_t bytesRead = fread (
                value, 1, sizeof(int), pv->file);

        return (bytesRead == sizeof(int));
}


/*
 * Code for decoding floating point types.
 */
#define WHITE(s)	(s == ' ' || s == '\t')
#define NUMER(s)	(s >= '0' && s <= '9')
#define IS_DECIMAL(c)	((c) == '.' || (c) == ',')

        static const char *
Pull_White (
        const char		*s)
{
        if (!s)
                return NULL;

        while (WHITE (*s))
                s++;

        return s;
}

        static const char *
Pull_RawInt (
        const char		*p,
        int			*val)
{
        const char		*s = p;
        int			 i = 0;

        if (!s)
                return NULL;

        while (NUMER (*s))
                i = i * 10 + (*s++ - '0');

        if (s == p)
                return NULL;

        *val = i;
        return s;
}

        static const char *
Pull_UDouble (
        const char		*p,
        double			*val)
{
        const char		*s;
        double			 v, f;
        int			 k;

        p = Pull_White (p);

        /*
         * Read integer part of number, if any.
         */
        if (!(s = Pull_RawInt (p, &k))) {
                s = p;
                k = 0;
        }

        /*
         * Read fraction, if any.
         */
        v = k;
        if (IS_DECIMAL (*s)) {
                s++;
                f = 0.1;
                while (*s >= '0' && *s <= '9') {
                        v += f * (*s++ - '0');
                        f = f / 10;
                }
        }

        /*
         * If there is no number so far return NULL for nothing.
         */
        if (s == p)
                return NULL;

        /*
         * Read exponent, if any.
         */
        p = s;
        if (*p == 'e' || *p == 'E') {
                p++;
                f = 1.0;
                if (*p == '+' || *p == '-') {
                        f = (*p == '-' ? -1.0 : 1.0);
                        p++;
                }
                if (p = Pull_RawInt (p, &k)) {
                        s = p;
                        v *= pow (10.0, k * f);
                }
        }

        *val = v;
        return s;
}

        static const char *
Pull_Double (
        const char		*p,
        double			*d)
{
        double			 val;
        int			 sgn;

        if (!p)
                return NULL;

        p = Pull_White (p);
        if (*p == '-') {
                sgn = -1;
                p++;
        } else if (*p == '+') {
                sgn = 1;
                p++;
        } else
                sgn = 1;

        if (p = Pull_UDouble (p, &val))
                *d = sgn * val;

        return p;
}

        bool
lx::Decode (
        const char		*str,
        double			*val)
{
        return (Pull_Double (str, val) != NULL);
}

        bool
lx::Decode (
        const char		*str,
        float			*val)
{
        double			 d;

        if (!lx::Decode (str, &d))
                return false;

        *val = (float)d;
        return true;
}

        bool
lx::Decode (
        std::string		&str,
        double			*val)
{
        return lx::Decode (str.c_str (), val);
}

        bool
lx::Decode (
        std::string		&str,
        float			*val)
{
        return lx::Decode (str.c_str (), val);
}


