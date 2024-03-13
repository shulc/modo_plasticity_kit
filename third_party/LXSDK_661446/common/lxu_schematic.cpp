/*
 * Plug-in SDK Source: Package Utilities
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
 * Provides package utility classes.
 */
#include <lxu_schematic.hpp>
#include <string>


/*
 * ------------------------------------------------------
 * Meta SchematicConnection
 *
 * pv_Meta_SchematicConnection is the common data allocated for the metaclass,
 * and pv_SchematicConnection is local to each server. The common data keeps
 * a list of all the locals.
 */
class pv_SchematicConnection;

class pv_Meta_SchematicConnection
{
    public:
        CLxTagList		*tag_list;
        CLxMeta_SchematicConnection_Core
                                *m_core;
        CLxList<pv_SchematicConnection>
                                 inst_list;
        std::string		 graph_name, item_type;
        bool			 b_reverse, b_manual, b_dynamic, b_bytype;
        int			 type_flags, type_num;

        pv_Meta_SchematicConnection ()
        {
                tag_list   = 0;
                m_core     = 0;
                b_reverse  = b_dynamic = b_bytype = false;
                b_manual   = true;
                type_flags = 0;
                type_num   = -1;
        }

                int
        type_code ()
        {
                if (type_num != -1)
                        return type_num;

                CLxUser_SceneService	 scn_S;

                scn_S.ItemTypeLookup (item_type.c_str(), &type_num);
                return type_num;
        }
};

class pv_SchematicConnection
{
    public:
        pv_SchematicConnection		*next, *prev;
        pv_Meta_SchematicConnection	*pv;
        CLxUser_Item		 cur_item;
        std::vector<CLxUser_Item>
                                 item_list;
        int			 tmp_flags;
        bool			 flags_valid;

        pv_SchematicConnection ()
        {
                flags_valid = true;
                tmp_flags = 0;
                pv = 0;
        }

                void
        set_parent (
                pv_Meta_SchematicConnection *parent)
        {
                pv = parent;
                pv->inst_list.AddTail (this);
        }

        ~pv_SchematicConnection ()
        {
                pv->inst_list.Remove (this);
        }
};


/*
 * The SchematicConnection server object implements the SchematicConnection and
 * Tags interfaces.
 */
class meta_SchematicConnectionServer :
                public CLxImpl_SchematicConnection,
                public CLxImpl_TagDescription
{
    public:
        class pv_Meta_SchematicConnection	*pv;
        CLxSchematicConnection			*sc;

        LXxO_SchematicConnection_ItemFlags
        {
                CLxUser_Item		 uitem (item);

                if (pv->b_bytype)
                {
                        if (uitem.IsA (pv->type_code ()))
                                flags[0] = pv->type_flags;
                        else
                                flags[0] = 0;

                        return LXe_OK;
                }

                if (pv->b_dynamic)
                        flags[0] = LXfSCON_PERITEM;
                else
                        flags[0] = 0;

                return LXe_OK;
        }

        LXxO_SchematicConnection_AllowConnect
        {
                CLxUser_Item		 iFrom (from), iTo (to);

                return (sc->allow (iFrom, iTo) ? LXe_TRUE : LXe_FALSE);
        }

        LXxO_SchematicConnection_GraphName
        {
                if (pv->graph_name.length ())
                {
                        name[0] = pv->graph_name.c_str();
                        return LXe_OK;
                }

                return LXe_NOTFOUND;
        }

                void
        refresh_list (
                ILxUnknownID		 itemObj)
        {
                CLxUser_Item		 item (itemObj);

                if (sc->pv->cur_item.test() && sc->pv->cur_item == item)
                        return;

                sc->pv->cur_item.set (item);
                sc->pv->item_list.clear ();
                sc->get_list (item);
        }

        LXxO_SchematicConnection_Count
        {
                if (!pv->b_manual)
                        return LXe_NOTIMPL;

                refresh_list (item);
                count[0] = sc->pv->item_list.size ();
                return LXe_OK;
        }

        LXxO_SchematicConnection_ByIndex
        {
                if (!pv->b_manual)
                        return LXe_NOTIMPL;

                refresh_list (item);
                if (index >= sc->pv->item_list.size ())
                        return LXe_OUTOFBOUNDS;

                return sc->pv->item_list[index].get (ppvObj);
        }

        LXxO_SchematicConnection_Connect
        {
                if (!pv->b_manual)
                        return LXe_NOTIMPL;

                CLxUser_Item		 iFrom (from), iTo (to);

                sc->pv->cur_item.clear ();
                sc->connect (iFrom, iTo, toIndex);
                return LXe_OK;
        }

        LXxO_SchematicConnection_Disconnect
        {
                if (!pv->b_manual)
                        return LXe_NOTIMPL;

                CLxUser_Item		 iFrom (from), iTo (to);

                sc->pv->cur_item.clear ();
                sc->disconnect (iFrom, iTo);
                return LXe_OK;
        }

        LXxO_SchematicConnection_BaseFlags
        {
                return (pv->b_reverse ? LXfSCON_REVERSE   : 0)
                    |  (pv->b_manual  ? LXfSCON_USESERVER : 0)
                    |  (pv->b_dynamic ? LXfSCON_PERITEM   : 0);
        }

        LXxO_SchematicConnection_PerItemFlags
        {
                if (!pv->b_dynamic)
                        return LXe_NOTIMPL;

                CLxUser_Item		 uitem (item);

                sc->pv->tmp_flags = 0;
                sc->test_item (uitem);
                flags[0] = sc->pv->tmp_flags;
                return LXe_OK;
        }

        LXxO_SchematicConnection_ItemFlagsValid
        {
                int ok = (sc->pv->flags_valid ? 1 : 0);
                sc->pv->flags_valid = true;
                return ok;
        }

        LXxO_TagDescription_Count
        {
                return pv->tag_list->count ();
        }

        LXxO_TagDescription_Describe
        {
                return pv->tag_list->describe (index, desc);
        }
};


/*
 * Methods on the public root class just store settings for the actual
 * implementation methods.
 */
CLxSchematicConnection::CLxSchematicConnection ()
{
        pv = new pv_SchematicConnection;
}

CLxSchematicConnection::~CLxSchematicConnection ()
{
        delete pv;
}

        void
CLxSchematicConnection::set_single ()
{
        pv->tmp_flags |= LXfSCON_SINGLE;
}

        void
CLxSchematicConnection::set_multiple (
        bool			 ordered)
{
        pv->tmp_flags |= LXfSCON_MULTIPLE;
        if (ordered)
                pv->tmp_flags |= LXfSCON_ORDERED;
}

        void
CLxSchematicConnection::add_item (
        CLxUser_Item		&item)
{
        pv->item_list.push_back (item);
}


/*
 * The package polymorph allows sub-objects and passes the PV data to the
 * new package instances.
 */
class meta_SchematicConnectionPolymorph :
                public CLxPolymorph<meta_SchematicConnectionServer>
{
    public:
        class pv_Meta_SchematicConnection	*pv;

        meta_SchematicConnectionPolymorph (
                class pv_Meta_SchematicConnection	*ptr)
        {
                this->AddInterface (new CLxIfc_SchematicConnection<meta_SchematicConnectionServer>);
                this->AddInterface (new CLxIfc_TagDescription<meta_SchematicConnectionServer>);
                pv = ptr;
        }

                void *
        NewObj ()			 LXx_OVERRIDE
        {
                meta_SchematicConnectionServer *obj;

                obj = new meta_SchematicConnectionServer;
                obj->pv = pv;
                obj->sc = pv->m_core->new_inst ();
                obj->sc->pv->set_parent (pv);
                return reinterpret_cast<void *> (obj);
        }
};


/*
 * The metaclass holds the global settings.
 */
CLxMeta_SchematicConnection_Core::CLxMeta_SchematicConnection_Core (
        const char		*srvName)
                :
        CLxMetaServer (srvName)
{
        pv = new pv_Meta_SchematicConnection;
        pv->m_core   =  this;
        pv->tag_list = &tag_list;

        cls_guid = &lx::guid_SchematicConnection;
}

CLxMeta_SchematicConnection_Core::~CLxMeta_SchematicConnection_Core ()
{
        delete pv;
}

        void *
CLxMeta_SchematicConnection_Core::alloc ()
{
        return reinterpret_cast<void *> (new meta_SchematicConnectionPolymorph (pv));
}

        void
CLxMeta_SchematicConnection_Core::set_graph (
        const char		*graph,
        bool			 reverse,
        bool			 manual)
{
        pv->graph_name = graph;
        pv->b_reverse  = reverse;
        pv->b_manual   = manual;
}

        void
CLxMeta_SchematicConnection_Core::set_itemtype (
        const char		*typeName,
        bool			 multiple,
        bool			 ordered)
{
        pv->item_type  = typeName;
        pv->b_bytype   = true;
        pv->b_dynamic  = false;
        pv->type_flags =   (multiple ? LXfSCON_MULTIPLE : LXfSCON_SINGLE)
                         | (ordered  ? LXfSCON_ORDERED  : 0);
}

        void
CLxMeta_SchematicConnection_Core::set_dynamic ()
{
        pv->b_dynamic = true;
        pv->b_bytype  = false;
}

        void
CLxMeta_SchematicConnection_Core::invalidate ()
{
        pv_SchematicConnection	*sc;

        for (sc = pv->inst_list.first; sc; sc = sc->next)
        {
                sc->flags_valid = false;
                sc->cur_item.clear ();
        }
}


