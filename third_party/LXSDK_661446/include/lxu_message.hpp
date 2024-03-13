/*
 * Plug-in SDK Header: Message Utilities
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
 * Provides message utility functions for C++ plug-ins.
 */

#ifndef LXU_MESSAGE_HPP
#define LXU_MESSAGE_HPP

#include <string>

namespace lx {

        /*
         * These functions all look up message text from a table and a message
         * index or name. Use the one that best matches your needs.
         */
                bool
        GetMessageText (
                std::string		&text,
                const char		*table,
                unsigned		 msgIndex,
                const char		*msgName);

                bool
        GetMessageText (
                std::string		&text,
                const char		*table,
                const char		*msgName);

                bool
        GetMessageText (
                std::string		&text,
                const char		*table,
                unsigned		 msgIndex);

                bool
        GetMessageText (
                std::string		&text,
                const std::string	&table,
                const std::string	&msgName);

                bool
        GetMessageText (
                std::string		&text,
                const std::string	&table,
                unsigned		 msgIndex);

        /*
         * These are the same but get text from the "common" table.
         */
                bool
        CommonMessage (
                std::string		&text,
                unsigned		 msgIndex);

                bool
        CommonMessage (
                std::string		&text,
                const char		*msgName);

};	// END namespace

#endif // LXU_MESSAGE_HPP

