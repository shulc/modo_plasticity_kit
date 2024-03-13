/*
 * Plug-in SDK Header: C++ User Classes
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
#ifndef LXUSER_io_HPP
#define LXUSER_io_HPP

#include <lxw_io.hpp>

        #include <string>



class CLxUser_BlockRead : public CLxLoc_BlockRead
{
        public:
        CLxUser_BlockRead () {}
        CLxUser_BlockRead (ILxUnknownID obj) : CLxLoc_BlockRead (obj) {}

        /**
         * User class methods are relatively more C++ friendly, using argument types and
         * throwing exceptions on errors. The read count is discarded for these methods
         * because they require reading.
         */
                bool
        Read (
                short			*val,
                bool			 force = true)
        {
                int			 count;
                LxResult		 rc;
        
                rc = ReadI2 (val, (force ? 1 : -1), &count);
                if (LXx_FAIL (rc))
                        throw (rc);
        
                return (count == 1);
        }
        
                bool
        Read (
                unsigned short		*val,
                bool			 force = true)
        {
                int			 count;
                LxResult		 rc;
        
                rc = ReadU2 (val, (force ? 1 : -1), &count);
                if (LXx_FAIL (rc))
                        throw (rc);
        
                return (count == 1);
        }
        
                bool
        Read (
                int			*val,
                bool			 force = true)
        {
                int			 count;
                LxResult		 rc;
        
                rc = ReadI4 (val, (force ? 1 : -1), &count);
                if (LXx_FAIL (rc))
                        throw (rc);
        
                return (count == 1);
        }
        
                bool
        Read (
                unsigned int		*val,
                bool			 force = true)
        {
                int			 count;
                LxResult		 rc;
        
                rc = ReadU4 (val, (force ? 1 : -1), &count);
                if (LXx_FAIL (rc))
                        throw (rc);
        
                return (count == 1);
        }
        
                bool
        Read (
                float			*val,
                bool			 force = true)
        {
                int			 count;
                LxResult		 rc;
        
                rc = ReadFP (val, (force ? 1 : -1), &count);
                if (LXx_FAIL (rc))
                        throw (rc);
        
                return (count == 1);
        }
        
                bool
        Read (
                double			*val,
                bool			 force = true)
        {
                int			 count;
                LxResult		 rc;
        
                rc = ReadFP8 (val, (force ? 1 : -1), &count);
                if (LXx_FAIL (rc))
                        throw (rc);
        
                return (count == 1);
        }
        /**
         * Reading strings in C++ does partial reads to build up an STL string. If force
         * is true it will raise an exception if the string is not found. Otherwise no
         * string and a valid empty string will both return false. The terminal string
         * has a final null, which we don't want included in the STL string.
         */
                bool
        Read (
                std::string		&result,
                bool			 force = true)
        {
                char			 buf[128];
                LxResult		 rc;
                int			 flag, got;
        
                result = "";
                flag = LXfREADSTRING_PARTIAL | (force ? LXfREADSTRING_FORCE : 0);
        
                while (1) {
                        rc = ReadString (buf, sizeof (buf), flag, &got);
                        if (LXx_FAIL (rc))
                                throw (rc);
        
                        if (rc == LXe_IO_PARTIALSTRING)
                                result.append (buf, (size_t) got);
                        else {
                                if (got)
                                        result.append (buf, (size_t) got - 1);
        
                                break;
                        }
                }
        
                return !result.empty ();
        }

};

class CLxUser_BlockWrite : public CLxLoc_BlockWrite
{
        public:
        CLxUser_BlockWrite () {}
        CLxUser_BlockWrite (ILxUnknownID obj) : CLxLoc_BlockWrite (obj) {}

        /**
         * User class methods are relatively more C++ friendly, using argument types and
         * throwing exceptions on errors.
         */
                void
        Write (
                const short		 val)
        {
                LxResult rc = WriteI2 (&val, 1);
                if (LXx_FAIL (rc))
                        throw (rc);
        }
        
                void
        Write (
                const unsigned short	 val)
        {
                LxResult rc = WriteU2 (&val, 1);
                if (LXx_FAIL (rc))
                        throw (rc);
        }
        
                void
        Write (
                const int		 val)
        {
                LxResult rc = WriteI4 (&val, 1);
                if (LXx_FAIL (rc))
                        throw (rc);
        }
        
                void
        Write (
                const unsigned int	 val)
        {
                LxResult rc = WriteU4 (&val, 1);
                if (LXx_FAIL (rc))
                        throw (rc);
        }
        
                void
        Write (
                const float		 val)
        {
                LxResult rc = WriteFP (&val, 1);
                if (LXx_FAIL (rc))
                        throw (rc);
        }
        
                void
        Write (
                const double		 val)
        {
                LxResult rc = WriteFP8 (&val, 1);
                if (LXx_FAIL (rc))
                        throw (rc);
        }
        
                void
        Write (
                const char		*val)
        {
                LxResult rc = WriteString (val);
                if (LXx_FAIL (rc))
                        throw (rc);
        }
        
                void
        Write (
                const std::string	&val)
        {
                LxResult rc = WriteString (val.c_str ());
                if (LXx_FAIL (rc))
                        throw (rc);
        }

};

class CLxUser_LoaderInfo : public CLxLoc_LoaderInfo
{
        public:
        CLxUser_LoaderInfo () {}
        CLxUser_LoaderInfo (ILxUnknownID obj) : CLxLoc_LoaderInfo (obj) {}



};

class CLxUser_Loader : public CLxLoc_Loader
{
        public:
        CLxUser_Loader () {}
        CLxUser_Loader (ILxUnknownID obj) : CLxLoc_Loader (obj) {}



};

class CLxUser_Saver : public CLxLoc_Saver
{
        public:
        CLxUser_Saver () {}
        CLxUser_Saver (ILxUnknownID obj) : CLxLoc_Saver (obj) {}



};

class CLxUser_Monitor : public CLxLoc_Monitor
{
        public:
        CLxUser_Monitor () {}
        CLxUser_Monitor (ILxUnknownID obj) : CLxLoc_Monitor (obj) {}

        /**
         * The above macros are made more or less obsolete by the user class, which
         * provides simpler methods which do nothing if there is no interface.
         */
                bool
        Init (
                unsigned int		 count)
        {
                if (test ())
                        return LXx_OK (Initialize (count));
                else
                        return true;
        }
        
                bool
        Step (
                unsigned int		 count = 1)
        {
                if (test ())
                        return LXx_FAIL (Increment (count));
                else
                        return false;
        }

};

class CLxUser_StreamIO : public CLxLoc_StreamIO
{
        public:
        CLxUser_StreamIO () {}
        CLxUser_StreamIO (ILxUnknownID obj) : CLxLoc_StreamIO (obj) {}

        /**
         * The StreamIO user class currently has no special methods, but we have to put
         * the tag here to trigger the macro.
         */
        

};

class CLxUser_BlockStore : public CLxLoc_BlockStore
{
        public:
        CLxUser_BlockStore () {}
        CLxUser_BlockStore (ILxUnknownID obj) : CLxLoc_BlockStore (obj) {}

        LxResult
        Lookup (
                LXtID4			 type,
                const char		*id,
                LXtBlockBookmarkID	 parent = 0)
        {
                return CLxLoc_BlockStore::Lookup (type, id, parent);
        }
        LxResult
        Count (
                LXtID4			 type,
                unsigned		*count,
                LXtBlockBookmarkID	 parent = 0)
        {
                return CLxLoc_BlockStore::Count (type, count, parent);
        }
        
                LxResult
        ByIndex (
                LXtID4			 type,
                unsigned		 index,
                LXtBlockBookmarkID	 parent = 0)
        {
                return CLxLoc_BlockStore::ByIndex (type, index, parent);
        }

};

class CLxUser_IOService : public CLxLoc_IOService
{
        public:


};
#endif
