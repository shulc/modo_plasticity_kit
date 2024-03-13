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
 * Helper class for opening user dialogs.
 */
#ifndef LXU_DIALOG_HPP
#define LXU_DIALOG_HPP

#include <lx_stddialog.hpp>
#include <string>
#include <vector>


/*
 * The FileDialog utility class lets the client set up a dialog and then
 * use it to get files for load and save.
 */
class CLxFileDialog
{
    public:
        /*
         * Set the object class for files to find, as well as optional context.
         * The context helps to remember the specific path for this usage,
         * especially for common type like images.
         */
        void		set_class (const char *cls, const char *context = 0);

        /*
         * Set the title, given by tablename and key. The table name can be used
         * verbatim if there's no key, and no translation is required.
         */
        void		set_title (const char *table, const char *key = 0);

        /*
         * Set the starting format for the save dialog, matching the class.
         */
        void		set_format (const char *);

        /*
         * Set the starting path, if any. This is reset after every dialog.
         */
        void		set_start_path (const char *);

        /*
         * Remove the ability to change formats from the dialog.
         */
        void		no_formats ();

        /*
         * Pick a single file for loading. The basename can be set if there's
         * no starting path, otherwise it should be part of the path.
         */
        bool		load_single (std::string &, const char *basename = 0);

        /*
         * Pick a list of files for loading.
         */
        bool		load_multiple (std::vector<std::string> &);

        /*
         * Pick a file for saving. Overwrite allows an existing file to be picked.
         */
        bool		save (std::string &, bool overwrite = true);

        /*
         * Pick a directory location. The result is a directory path.
         */
        bool		pick_directory (std::string &);

    //internal:
         CLxFileDialog ();
        ~CLxFileDialog ();

        class pv_FileDialog	*pv;
};


#endif	/* LXU_DIALOG_HPP */

