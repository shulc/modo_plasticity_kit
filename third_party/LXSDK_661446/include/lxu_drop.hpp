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
 * Drop Server Wrappers
 */
#ifndef LXU_DROP_HPP
#define LXU_DROP_HPP

#include <lxu_meta.hpp>
#include <lx_drop.hpp>
#include <lx_message.hpp>
#include <string>


/*
 * ----------------------------------------------------------------
 * Drop Metaclasses
 *
 * The actions a drop server can perform are given by CLxDropAction subclasses.
 * The 
 */
class CLxDrop;

class CLxDropAction :
                public CLxObject
{
    public:
        /*
         * Implement to test if this action is enabled relative to this
         * destination. Simple actions just return true or false; custom
         * actions call CLxDrop::add_custom().
         */
        virtual bool		enabled (ILxUnknownID dest) { return true; }

        /*
         * Implement to return a name for the action different from the default
         * name in the message table. The string version is called first, and if
         * that returns null then the message version is used.
         */
        virtual void		name_str (std::string &) {}

        /*
         * Implement to return a name for the action coming from a custom
         * message table.
         */
        virtual void		name_msg (CLxUser_Message &) {}

        /*
         * Implement to execute the action.
         */
        virtual void		exec () {}

        /*
         * Implement to execute a custom action given by index.
         */
        virtual void		exec_custom (unsigned index) {}

    //internal:
        virtual void		init_drop (CLxDrop *) {}
};

/*
 * Templated class adds m_drop member pointer to client drop object.
 */
template <class T>
class CLxDropActionT :
                public CLxDropAction
{
    public:
        T		*m_drop;

    //internal:
        void init_drop (CLxDrop *drop)		LXx_OVERRIDE
        {
                m_drop = dynamic_cast<T *> (drop);
        }
};


/*
 * The CLxDrop class implements the customized part of a Drop server.
 */
class CLxDrop :
                public CLxObject
{
    public:
        /*
         * Because many sources present as ValueArrays, there are two ways to
         * recognize the source data. The general recognize_any() is called
         * first and if that returns false then recognize_array() is called for
         * appropriate sources.
         *
         * Implement to get the source data as a general object and return true
         * if the source is recognized.
         */
        virtual bool		recognize_any (ILxUnknownID src) { return false; }

        /*
         * Implement to get the source as a ValueArray and return true if the
         * source is recognized.
         */
        virtual bool		recognize_array (CLxUser_ValueArray &src) { return false; }

        /*
         * Implement to test if the destination is valid for any action in this
         * drop server.
         */
        virtual bool		enabled (ILxUnknownID dest) { return true; }

        /*
         * Call this to add actions to a custom drop action, given by a name string.
         * The returned index is used for executing them.
         */
        unsigned		add_custom (const char *);

   //internal:
         CLxDrop ();
        ~CLxDrop ();

        class pv_Drop *pv;
};

/*
 * Core metaclass provides some methods for global customization.
 */
class CLxMeta_Drop_Core :
                public CLxMetaServer
{
    public:
        /*
         * Set the source of the drop from the LXsDROPSOURCE_* symbols.
         */
        void		 set_source_type (const char *);

        /*
         * Actions are added one at a time. The name is the key used for the
         * default action name in the message table. Custom drop actions can
         * add their own actions, but are not mappable.
         */
        void		 add_action (const char *name, CLxDropAction *, bool custom = false);

    //internal:
         CLxMeta_Drop_Core (const char *srvName);
        ~CLxMeta_Drop_Core ();

        virtual CLxDrop *	 new_inst () = 0;

        void *		 alloc () LXx_OVERRIDE;

        class pv_Meta_Drop *pv;
};

/*
 * Metaclass template for your specialization.
 */
template <class T>
class CLxMeta_Drop :
                public CLxMeta_Drop_Core
{
    public:
        CLxMeta_Drop (const char *srvName) : CLxMeta_Drop_Core (srvName) { }

                CLxDrop *
        new_inst ()
        {
                return new T;
        }
};


#endif /* LX_DROP_HPP */

