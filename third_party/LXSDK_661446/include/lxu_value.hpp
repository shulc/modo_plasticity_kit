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
 * Helper classes for implementing Value servers.
 */
#ifndef LXU_VALUE_HPP
#define LXU_VALUE_HPP

#include <lx_value.hpp>
#include <lx_io.hpp>
#include <lxu_meta.hpp>
#include <string>


/*
 * -------------------------------------
 * Value Metaclass
 *
 * The base class defines standard Value methods.
 */
class CLxValue :
                public CLxObject
{
    public:
        /*
         * Implement to copy the value of a different value object into this
         * one. Required method, will need a dynamic cast to get the client's
         * sublcass.
         */
        virtual void		copy (const CLxValue *) = 0;

        /*
         * Implement to compare a different value object to this one and return
         * a difference value on a linear metric, like strcmp(). Required method,
         * will need a dynamic cast to get the client's sublcass.
         */
        virtual int		compare (const CLxValue *) = 0;

        /*
         * Implement to set the value from an integer if this is a numeric type.
         */
        virtual void		set_int (int)			{ throw (LXe_NOTIMPL); }

        /*
         * Implement to set the value from a double if this is a numeric type.
         */
        virtual void		set_float (double)		{ throw (LXe_NOTIMPL); }

        /*
         * Implement to set the value from a string.
         */
        virtual void		set_string (const char *)	{ throw (LXe_NOTIMPL); }

        /*
         * Implement to read out the value as an integer.
         */
        virtual int		get_int ()			{ throw (LXe_NOTIMPL); }

        /*
         * Implement to read out the value as a double.
         */
        virtual double		get_float ()			{ throw (LXe_NOTIMPL); }

        /*
         * Implement to read out the value as a string.
         */
        virtual std::string	get_string ()			{ throw (LXe_NOTIMPL); }

    //internal:
        class pv_Meta_Value	*_mpv;
};


/*
 * Optional subclasses. The client Value class may also derive from any of
 * these classes to implement additional interfaces with more features.
 *
 * StreamIO allows the Value to be read and written to block streams. Both
 * the save() and load() methods are required.
 */
class CLxValue_StreamIO
{
    public:
        /*
         * Implement to linearize the contents of the value object to a
         * block stream.
         */
        virtual void		save (CLxUser_BlockWrite &) = 0;

        /*
         * Implement to read a block stream and set the value of this object.
         */
        virtual void		load (CLxUser_BlockRead &) = 0;
};


/*
 * This class allows the Value to present "nice" values which are used to
 * display the value directly to the user. If missing the ordinary string
 * conversions are used. Both are required.
 */
class CLxValue_StringConversionNice
{
    public:
        /*
         * Implement to read out the value as a nice string.
         */
        virtual std::string	get_nice ()= 0;

        /*
         * Implement to set the value from a nice string.
         */
        virtual void		set_nice (const char *) = 0;
};


/*
 * This class allows the Value to be the target of math operations.
 */
class CLxValue_ValueMath
{
    public:
        /*
         * Implement to increase or decrease the value by one step in
         * either direction. Steps should move to detents if nearby.
         */
        virtual void		step (int) {}

        /*
         * Implement to determine if the current value is on a detent.
         */
        virtual int		detent () const { return LXiDETENT_NONE; }

        /*
         * Implement to offset by a delta.
         */
        virtual void		add (double) {}

        /*
         * Implement to scale by a factor.
         */
        virtual void		multiply (double) {}

        /*
         * Implement to blend between this value and a different one. If the
         * blend is zero then the value is unchanged
         */
        virtual void		blend (CLxValue *, double) {}
};


/*
 * Core metaclass sets global properties.
 */
class CLxMeta_Value_Core :
                public CLxMetaServer
{
    public:
         CLxMeta_Value_Core (const char *srvName);
        ~CLxMeta_Value_Core ();

        /*
         * Call this functions to add a Strings interface to the value object.
         * This just uses the normal get/set string API on the value.
         */
        void		add_strings ();

        /*
         * Call this function to add a Nice Strings interface to the value
         * object. The class must derive from CLxValue_StringConversionNice.
         */
        void		add_nice_strings ();

        /*
         * Call this function to add a StreamIO interface to the value
         * object. The class must derive from CLxValue_StreamIO.
         */
        void		add_streamIO ();

        /*
         * Call this function to add a Value Math interface to the value
         * object. The class must derive from CLxValue_ValueMath.
         */
        void		add_math ();

        /*
         * Call this function to get the type name for the value server.
         */
        const char *	type_name ();

    //internal:
        CLxValue *		extract (ILxUnknownID);
        virtual CLxValue *	new_inst () = 0;
        void *			alloc () LXx_OVERRIDE;

        class pv_Meta_Value	*pv;
};


/*
 * Template for server metaclass.
 */
template <class T>
class CLxMeta_Value :
                public CLxMeta_Value_Core
{
    public:
        CLxMeta_Value (const char *srvName) : CLxMeta_Value_Core (srvName) { }

        /*
         * Call this function to get the value class from an object.
         */
                T *
        cast (
                ILxUnknownID		 obj)
        {
                return dynamic_cast<T *> (extract (obj));
        }

    //internal:
                CLxValue *
        new_inst ()		LXx_OVERRIDE
        {
                return new T;
        }
};


#endif // LXU_VALUE_HPP

