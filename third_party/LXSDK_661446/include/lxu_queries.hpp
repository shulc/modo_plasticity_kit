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
 * Helper class for getting user values.
 */
#ifndef LX_QUERIES_HPP
#define LX_QUERIES_HPP

#include <lxu_attributes.hpp>
#include <string>


/*
 * ----------------------------------------------------------------
 * The CLxCommandQuery class makes it easy to query a command.
 */
class CLxCommandQuery
{
    public:
         CLxCommandQuery (const char *);
        ~CLxCommandQuery ();

        CLxUser_Attributes &	 Arguments ();
        bool			 Query     (unsigned int argIndex);
        const char *		 ValueType ();
        unsigned		 Count     ();
        void			 SetIndex  (unsigned int valIndex);
        int			 GetInt    ();
        double			 GetFloat  ();
        const char *		 GetString (char *, unsigned);
        void			 GetString (std::string &string);

        bool			 GetValue(CLxLocalizedObject& o_dest);

        void			 ResetArgs();

        LxResult		 IntHint (const LXtTextValueHint **hints);

    private:
        class pv_CommandQuery	*pv;
};


/*
 * This is a very simple class for reading user values.  User values
 * can be declared in configs and presented in interfaces.
 */
class CLxReadUserValue
{
    public:
         CLxReadUserValue ();
        ~CLxReadUserValue ();

        bool			 Query (const char *);
        const char *		 ValueType ();
        int			 GetInt    ();
        double			 GetFloat  ();
        void			 GetString (std::string &string);

    private:
        class pv_ReadUserValue	*pv;
};


#endif	/* LX_QUERIES_HPP */

