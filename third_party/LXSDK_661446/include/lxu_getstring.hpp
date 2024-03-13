/*
 * Plug-in SDK Header: Common Utilities
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
 * Provides template class for getting string buffers safely.
 */

#ifndef LXU_GETSTRING_HPP
#define LXU_GETSTRING_HPP

#include <string.h>


/*
 * ----------------------------------------------------------
 * This is a simple template for code that reads a string safely through the
 * SDK interfaces into a standard string. The client implements a method called
 * sgs_GetString() that takes a buffer and length. If it returns LXe_SHORTREAD
 * we allocate a larger buffer and try again.
 *
 * Two other variants of the method return booleans or raise exceptions.
 */
template <class T>
class CLxSafeGetString
{
    public:
                LxResult
        GetString (
                T			&thing,
                std::string		&value)
        {
                LxResult		 rc;
                char			*buf;
                size_t			 len;

                len = 1024;
                while (1) {
                        buf = new char [len];
                        rc  = thing.sgs_GetString (buf, static_cast<unsigned>(len));
                        if (rc != LXe_SHORTBUFFER)
                                break;

                        delete[] buf;
                        len *= 2;
                }

                if (LXx_OK (rc))
                        value = buf;

                delete[] buf;
                return rc;
        }

                void
        GetStringEx (
                T			&thing,
                std::string		&value)
        {
                LxResult		 rc;

                rc = GetString (thing, value);
                if (LXx_FAIL (rc))
                        throw (rc);
        }

                bool
        GetStringBool (
                T			&thing,
                std::string		&value)
        {
                LxResult		 rc;

                rc = GetString (thing, value);
                return LXx_OK (rc);
        }

}; // END CLxSafeGetString template


/*
 * ----------------------------------------------------------
 * "lx" namespace for utility functions.
 */
                namespace lx {

/*
 * This utility function does the opposite. When a method is expected to return
 * a string in a buffer and length, this function will copy the string and return
 * an error if the buffer was too short.
 */
extern LxResult		StringOut (std::string &string, char *buf, unsigned len);
extern LxResult		StringOut (const char *string, char *buf, unsigned len);

/*
 * Get the name associated with a result code from the 'lxresult' message table.
 * If not possible for any reason this returns the code as a string in hex.
 */
extern std::string	LxResultName (LxResult);

                };	// END lx namespace


#endif // LXU_GETSTRING_HPP

