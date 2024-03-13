/*
 * Plug-in SDK Header: Meta classes
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
 * Implementation of the basic meta classes.
 */
#include <lxu_meta.hpp>
#include <lx_log.hpp>
#include <set>

/*
 * The core of the meta class is a tree of nodes that can be searched
 * and instantiated.
 */
CLxMeta::CLxMeta ()
{
        cls_guid = 0;
}

        void
CLxMeta::add (
        CLxMeta			*sub)
{
        sub->parent = this;
        sub_list.AddTail (sub);
}

        bool
CLxMeta::test (
        const char		*type,
        const LXtGUID		*cls)
{
        if (type && m_type != type)
                return false;

        return (!cls || lx::GUIDCompare (cls_guid, cls) == 0);
}

        CLxMeta *
CLxMeta::find_sub (
        const char		*type,
        const LXtGUID		*cls)
{
        CLxMeta			*m, *f;

        for (m = sub_list.first; m; m = m->next)
                if (m->test (type, cls))
                        return m;

        for (m = sub_list.first; m; m = m->next)
                if (f = m->find_sub (type, cls))
                        return f;

        return 0;
}

        CLxMeta *
CLxMeta::find_any (
        const char		*type,
        const LXtGUID		*cls,
        CLxMeta			*except)
{
        CLxMeta			*m, *f;

        if (test (type, cls))
                return this;

        for (m = sub_list.first; m; m = m->next)
        {
                if (m == except)
                        continue;

                if (m->test (type, cls))
                        return m;

                f = m->find_sub(type, cls);
                if (f)
                        return f;
        }

        if (parent)
                return parent->find_any (type, cls, this);
        else
                return 0;
}


        CLxMetaInterfaces *
CLxMeta::get_ifcs (
        const LXtGUID		*cls)
{
        CLxMetaInterfaces	*mi;
        CLxMeta			*m;

        if (!cls)
                cls = cls_guid;

        mi = new CLxMetaInterfaces;

        for (m = sub_list.first; m; m = m->next)
                if (m->m_type == LXsMETA_INTERFACE && lx::GUIDCompare (m->cls_guid, cls) == 0)
                        mi->ifc_list.push_back (reinterpret_cast<CLxGenericPolymorph *> (m->alloc ()));

        return mi;
}

        void
CLxMeta::db_line (
        std::string		&result)
{
        char			 buf[512];

        sprintf (buf, "%p %s", this, m_type.c_str());
        result = buf;

        if (cls_guid)
        {
                sprintf (buf, "[%02X%02X%02X%02X%02X%02X]",
                         cls_guid->x1[2], cls_guid->x1[3], cls_guid->x1[4],
                         cls_guid->x1[5], cls_guid->x1[6], cls_guid->x1[7]);

                result += buf;
        }

        if (m_name.length ())
        {
                result += " \"";
                result += m_name;
                result += "\"";
        }
}

        void
CLxMeta::db_format (
        const char		*prefix,
        std::string		&result)
{
        CLxMeta                 *m;
        std::string              ln, sub;

        db_line (ln);
        result += prefix;
        result += ln;
        result += "\n";

        sub = prefix;
        sub += "    ";
        for (m = sub_list.first; m; m = m->next)
                m->db_format (sub.c_str(), result);
}


/*
 * ---------------------
 * Meta Interfaces
 *
 * Methods just aggregate the contents of the list.
 */
        bool
CLxMetaInterfaces::test (
        const LXtGUID		*iid)
{
        return (find (iid) != 0);
}

        CLxGenericPolymorph *
CLxMetaInterfaces::find (
        const LXtGUID		*iid)
{
        int			 i, n;

        n = ifc_list.size ();
        for (i = 0; i < n; i++)
                if (ifc_list[i]->TestInterface (iid))
                        return ifc_list[i];

        return 0;
}


/*
 * ---------------------
 * Server Meta
 *
 * Server metaclasses just have tags.
 */
        void
CLxMetaServer::add_tag (
        const char		*tag,
        const char		*val)
{
        tag_list.add (tag, val);
}

        void
CLxMetaServer::set_username (
        const char		*base,
        const char		*key)
{
        std::string		 comp;

        if (key)
        {
                if (!base)
                        base = m_name.c_str();

                comp  = "@";
                comp += base;
                comp += "@";
                comp += key;
                comp += "@";
                base = comp.c_str();
        }

        tag_list.add (LXsSRV_USERNAME, base);
}


/*
 * ---------------------
 * Object Meta
 *
 * Object metaclasses can be called multiple times, so store the polymorph
 * to return or spawn from.
 */
        void *
CLxMetaObject::alloc ()
{
        if (m_spawner)
                return m_spawner;

        CLxMetaInterfaces * ifcs = get_ifcs (cls_guid);
        m_spawner = new_spawner (ifcs);
        return m_spawner;
}

        void *
CLxMetaObject::spawn_raw (
        ILxUnknownID		&obj)
{
        CLxGenericPolymorph	*gp = (CLxGenericPolymorph *) alloc ();

        obj = gp->Spawn ();
        return cast_raw (obj);
}


/*
 * ---------------------
 * Root Meta
 *
 * The root meta object manages the whole tree, mainly for initialization.
 */

/*
 * Pre-init happens in multiple passes. Each pass gets all the meta objects
 * into a depth-first list, except those in the done state. We then pre_init()
 * them and mark them as done unless they ask for another pass. When the
 * list of new objects to process is empty everything has been initialized.
 */
        static void
Meta_GetRecursive (
        CLxMeta			*meta,
        std::vector<CLxMeta *>	&list,
        std::set<CLxMeta *>	&done)
{
        CLxMeta			*m;

        for (m = meta->sub_list.first; m; m = m->next)
                Meta_GetRecursive (m, list, done);

        if (done.find (meta) == done.end ())
                list.push_back (meta);
}

        static void
Meta_PreInit (
        CLxMeta			*root)
{
        CLxMeta			*m;
        std::vector<CLxMeta *>	 list;
        std::set<CLxMeta *>	 done;
        int			 i, n;

        while (1)
        {
                list.clear ();
                Meta_GetRecursive (root, list, done);

                n = list.size ();
                if (!n)
                        return;

                for (i = 0; i < n; i++)
                {
                        m = list[i];
                        if (!m->pre_init ())
                                done.insert (m);
                }
        }
}

/*
 * This recursive function adds all the SERVER type metaclasses in the
 * whole tree as servers.
 */
        static void
Meta_AddServers (
        CLxMeta			*meta)
{
        CLxMeta			*m;

        if (meta->m_type == LXsMETA_SERVER)
                lx::AddServer (meta->m_name.c_str(), (CLxGenericPolymorph *) meta->alloc ());

        for (m = meta->sub_list.first; m; m = m->next)
                Meta_AddServers (m);
}

        void
CLxMetaRoot::initialize ()
{
        if (is_done)
                return;

        is_done = true;

 #if 0
        std::string dump;
        db_format ("INIT ", dump);
        printf ("%s", dump.c_str());
 #endif
        Meta_PreInit (this);
        Meta_AddServers (this);
}


