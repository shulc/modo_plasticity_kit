/*
 * Plug-in SDK Header: Metaclass Utilities
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
 * Provides utility classes for creating channel modifier servers.
 */
#ifndef LXU_META_HPP
#define LXU_META_HPP

#include <lx_util.hpp>
#include <lx_wrap.hpp>
#include <string>
#include <vector>

/*
 * ---------------------
 * Server Tag List
 *
 * List of tag/value pairs that present TagDescription-style methods.
 */
class CLxTagPair
{
    public:
        std::string		 tag, value;
};

class CLxTagList :
                public std::vector<CLxTagPair>
{
    public:
                void
        add (
                const char		*tag,
                const char		*val)
        {
                CLxTagPair		 proto;
                int			 i, n;

                n = size ();
                for (i = 0; i < n; i++)
                {
                        CLxTagPair	&pair = (*this)[i];

                        if (pair.tag == tag)
                        {
                                pair.value = val;
                                return;
                        }
                }

                proto.tag   = tag;
                proto.value = val;
                push_back (proto);
        }

                unsigned
        count ()
        {
                return (unsigned) this->size ();
        }

                LxResult
        describe (
                unsigned		 index,
                LXtTagInfoDesc		*desc)
        {
                if (index >= this->size ())
                        return LXe_OUTOFBOUNDS;

                desc->type = at(index).tag.c_str ();
                desc->info = at(index).value.c_str ();
                return LXe_OK;
        }
};


/*
 * ---------------------
 * Extended Polymorphs
 *
 * We can collect a list of interfaces that implement sub-features of a base
 * object class. These can be composed into a polymorph that implements the
 * sub-interfaces as well as the ones directly attached.
 */
class CLxMetaInterfaces
{
    public:
        std::vector<CLxGenericPolymorph *>	ifc_list;

        bool			test (const LXtGUID *);
        CLxGenericPolymorph *	find (const LXtGUID *);
};

template <class T>
class CLxExtendedPolymorph :
                public CLxPolymorph<T>
{
    public:
        CLxMetaInterfaces		*m_ifcs;

        CLxExtendedPolymorph (
                CLxMetaInterfaces	*ifcs = 0)
        {
                m_ifcs = ifcs;
        }

                void
        set_interfaces (
                CLxMetaInterfaces	*ifcs)
        {
                m_ifcs = ifcs;
        }

                bool
        TestInterface (
                const LXtGUID		*iid)			LXx_OVERRIDE
        {
                if (m_ifcs && m_ifcs->test (iid))
                        return true;

                return CLxGenericPolymorph::TestInterface (iid);
        }

                ILxUnknownID
        IsA (
                ILxUnknownID		 src,
                const LXtGUID		*iid)			LXx_OVERRIDE
        {
                CLxGenericPolymorph	*gp;

                if (!m_ifcs)
                        return 0;

                gp = m_ifcs->find (iid);
                if (!gp)
                        return 0;

                return gp->Spawn ();
        }
};


/*
 * ---------------------
 * Metagen Polymorph Template
 *
 * Often we just need a polymorph that can pass private data from the metaclass
 * to the server object. The client provided the server type (T) and the private
 * type (PV) and everything else is automatic. The server type needs a constructor
 * that takes the private pointer as data (as well as a normal constructor
 * because c++), and the private type needs a method to define the interfaces on
 * the server.
 */
template <class T, class PV>
class CLxMetagenPolymorph :
                public CLxExtendedPolymorph<T>
{
    public:
        PV			*m_pv;

        CLxMetagenPolymorph (
                PV			*pv)
                        :
                m_pv (pv)
        {
                pv->add_interfaces (this);
        }

                void *
        NewObj ()						LXx_OVERRIDE
        {
                return reinterpret_cast<void *> (new T (m_pv));
        }
};


/*
 * Same basic template again, but this one is for implementation classes that
 * really want to host sub-interfaces. That means they provide a ref_obj()
 * pointer for the data to be passed to the sub-object.
 */
template <class T, class PV>
class CLxMetagenPolymorphHost :
                public CLxMetagenPolymorph<T, PV>
{
    public:
        CLxMetagenPolymorphHost (
                PV			*pv,
                CLxMetaInterfaces	*ifcs)
                        :
                CLxMetagenPolymorph<T, PV> (pv)
        {
                this->set_interfaces (ifcs);
        }

                void *
        RefObj (
                void			*obj)			LXx_OVERRIDE
        {
                T			*inst = (T *) obj;

                return reinterpret_cast<void *> (inst->ref_obj());
        }
};


/*
 * ---------------------
 * Meta
 *
 * The base meta class is a node in a tree of metaclasses. Each has a type
 * (string), a name (string), and a class (GUID). Searches can find nearby
 * metaclasses by type and/or class, or lists of sub-interfaces.
 */
//@util CLxMeta

class CLxMeta :
                public CLxObject
{
    public:
        CLxMeta			*next, *prev, *parent;
        CLxList<CLxMeta>	 sub_list;

        CLxMeta ();

        std::string		 m_type, m_name;
        const LXtGUID		*cls_guid;

        void			 add (CLxMeta *);
        bool			 test (const char *type, const LXtGUID *cls);
        CLxMeta *		 find_sub (const char *type, const LXtGUID *cls = 0);
        CLxMeta *		 find_any (const char *type, const LXtGUID *cls = 0, CLxMeta *except = 0);
        CLxMetaInterfaces *	 get_ifcs (const LXtGUID * = 0);
        void			 db_format (const char *prefix, std::string &result);

        /*
         * The alloc() function returns different object types based on the
         * type of the metaclass node.
         */
        virtual void *		 alloc () { return 0; }

        /*
         * The pre_init() function is called on meta objects to allow them to
         * configure themselves and their neighbors. It can return true if the
         * object wants to be called again after the next pass.
         */
        virtual bool		 pre_init () { return false; }

        /*
         * Generate a descriptive line for debug output.
         */
        virtual void		 db_line (std::string &);
};

/*
 * LXxMETA_xxx are the type names defined for different metaclass nodes.
 * The types determine the return value from alloc():
 *
 *	ROOT		- null
 *	SERVER		- polymorph for the server.
 *	INTERFACE	- polymorph for the sub-object
 */
#define LXsMETA_ROOT		"(root)"
#define LXsMETA_SERVER		"server"
#define LXsMETA_INTERFACE	"interface"
#define LXsMETA_OBJECT		"object"


/*
 * ---------------------
 * Root Meta
 *
 * The root metaclass serves as the container for all the metaclasses in a
 * project. The common initialize() method installs all servers. The client
 * can perform the init, or it will happen automatically.
 */
class CLxMetaRoot :
                public CLxMeta,
                public CLxDeferredInitializer
{
    public:
        bool			 is_done;

        CLxMetaRoot ()
        {
                m_type  = LXsMETA_ROOT;
                is_done = false;
                lx::QueueInit (this);
        }

        void			 initialize () LXx_OVERRIDE;
};


/*
 * ---------------------
 * Server Meta
 *
 * The server metaclass adds the add_tag() method, allowing server tags to be
 * added to the metaclass. There's also a set_username() method that takes either
 * a single string, or a table name and key.
 */
class CLxMetaServer :
                public CLxMeta
{
    public:
        CLxMetaServer (const char *srvName)
        {
                m_type = LXsMETA_SERVER;
                m_name = srvName;
        }

        CLxTagList		 tag_list;
        void			 add_tag (const char *tag, const char *val);
        void			 set_username (const char *, const char *key = 0);
};


/*
 * ---------------------
 * Object Meta
 *
 * The object metaclass allocates exported objects that aren't servers. Since
 * this may happen a lot we allocate a polymorph once and reuse it. Sub-interfaces
 * are passed to the allocation, but require the client to use them. There's also
 * a method for casting from the COM object to the client's class embedded in the
 * wrapper class of the meta implementation.
 */
//@util CLxMetaObject

class CLxMetaObject :
                public CLxMeta
{
    public:
        CLxGenericPolymorph	*m_spawner;

        CLxMetaObject (const LXtGUID *cls)
        {
                m_type    = LXsMETA_OBJECT;
                cls_guid  = cls;
                m_spawner = 0;
        }

        void *			 alloc ();
        void *			 spawn_raw (ILxUnknownID &);

        virtual CLxGenericPolymorph *	 new_spawner (CLxMetaInterfaces *) = 0;
        virtual void *			 cast_raw  (ILxUnknownID) = 0;
};

#endif // LXU_META_HPP

