/*
 * Plug-in SDK Header: Common Utility
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
 * Selection Utility Classes
 */

#include <lxu_select.hpp>
#include <lxu_parser.hpp>
#include <lxu_format.hpp>


/*
 * ----------------------------------------------------------------
 * CLxAnySelection : Implementation
 */
CLxAnySelection::CLxAnySelection (
        const char		*selName)
{
        sel_ID = srv_sel.LookupType (selName);
}

        void
CLxAnySelection::Drop ()
{
        srv_sel.Drop (sel_ID);
}

        void
CLxAnySelection::Clear ()
{
        srv_sel.Clear (sel_ID);
}


/*
 * ----------------------------------------------------------------
 * CLxVertexSelection : Implementation
 */
CLxVertexSelection::CLxVertexSelection ()
{
        pkt_trans.autoInit ();
        sel_ID = srv_sel.LookupType (LXsSELTYP_VERTEX);
        sel_comp[0] = sel_ID;
        sel_comp[1] = srv_sel.LookupType (LXsSELTYP_EDGE);
        sel_comp[2] = srv_sel.LookupType (LXsSELTYP_POLYGON);
        sel_comp[3] = 0;
}

        bool
CLxVertexSelection::AnyDirect ()
{
        return srv_sel.Count (sel_ID) != 0;
}

        bool
CLxVertexSelection::AnyIndirect ()
{
        LXtID4			 cur;

        cur = srv_sel.CurrentType (sel_comp);
        return srv_sel.Count (cur) != 0;
}

        void
CLxVertexSelection::GetDirectList (
        MeshList		&list)
{
        CLxUser_Item		 item;
        MeshEntry		 entry;
        LXtScanInfoID		 scan;
        LXtPointID		 vrt;
        const char		*id;
        void			*pkt;
        size_t			 k;

        std::map<const char *, size_t>			entries;
        std::map<const char *, size_t>::iterator	eit;

        list.clear ();

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.Vertex (pkt, &vrt);

                pkt_trans.GetItem (pkt, item);
                item.Ident (&id);
                eit = entries.find (id);

                if (eit == entries.end ()) {
                        entry.item.set (item);
                        pkt_trans.GetMesh (pkt, entry.mesh);

                        k = list.size ();
                        entries[id] = k;
                        list.push_back (entry);
                } else
                        k = eit->second;

                list[k].list.push_back (vrt);
        }
}


/*
 * ----------------------------------------------------------------
 * CLxVertexMapSelection : Implementation
 */
CLxVertexMapSelection::CLxVertexMapSelection ()
{
        sel_ID = srv_sel.LookupType (LXsSELTYP_VERTEXMAP);
        pkt_trans.autoInit ();
}

        bool
CLxVertexMapSelection::First (
        std::string		&name)
{
        LXtScanInfoID		 scan;
        LXtID4			 type;
        const char		*str;
        void			*pkt;

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.Type (pkt, &type);
                if (!Include (type))
                        continue;

                pkt_trans.Name (pkt, &str);
                name = str;
                return true;
        }

        return false;
}

        void
CLxVertexMapSelection::GetList (
        MapList			&list)
{
        LXtScanInfoID		 scan;
        MapInfo			 info;
        const char		*str;
        void			*pkt;

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.Type (pkt, &info.type);
                if (!Include (info.type))
                        continue;

                pkt_trans.Name (pkt, &str);
                info.name = str;

                list.push_back (info);
        }
}


/*
 * ----------------------------------------------------------------
 * CLxItemSelection : Implementation
 */
CLxItemSelection::CLxItemSelection ()
{
        sel_ID = srv_sel.LookupType (LXsSELTYP_ITEM);
        pkt_trans.autoInit ();
}

        bool
CLxItemSelection::GetFirst (
        CLxUser_Item		&item)
{
        LXtScanInfoID		 scan;
        void			*pkt;

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.GetItem (pkt, item);
                if (Include (item))
                        return true;
        }

        return false;
}

        void
CLxItemSelection::GetList (
        ItemList		&list)
{
        CLxUser_Item		 item;
        LXtScanInfoID		 scan;
        void			*pkt;

        list.clear ();

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.GetItem (pkt, item);
                if (Include (item))
                        list.push_back (item);
        }
}

        void
CLxItemSelection::GetSet (
        ItemSet			&set)
{
        CLxUser_Item		 item;
        LXtScanInfoID		 scan;
        void			*pkt;

        set.clear ();

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.GetItem (pkt, item);
                if (Include (item))
                        set.insert (item);
        }
}

        void
CLxItemSelection::LoopInit ()
{
        GetList (tmp_list);
        tmp_idx = 0;
}

        void
CLxItemSelection::LoopStop ()
{
        tmp_list.clear ();
        tmp_idx = 0;
}

        bool
CLxItemSelection::LoopNext (
        CLxUser_Item		&item)
{
        if (tmp_idx < tmp_list.size ())
                return item.set (tmp_list[tmp_idx++]);

        LoopStop ();
        return false;
}

        void
CLxItemSelection::Drop ()
{
        srv_sel.Drop (sel_ID);
}

        void
CLxItemSelection::Clear ()
{
        srv_sel.Clear (sel_ID);
}

        void
CLxItemSelection::Select (
        CLxUser_Item		&item)
{
        srv_sel.Select (sel_ID, pkt_trans.Packet (item));
}

        void
CLxItemSelection::Deselect (
        CLxUser_Item		&item)
{
        srv_sel.Deselect (sel_ID, pkt_trans.Packet (item));
}


/*
 * ----------------------------------------------------------------
 * CLxItemSelectionType : Implementation
 */
        bool
CLxItemSelectionType::Include (
        CLxUser_Item		&item)
{
        return item.IsA (type);
}


/*
 * ----------------------------------------------------------------
 * CLxItemCurrentTypes : Implementation
 */
        void
CLxItemCurrentTypes::invalidate ()
{
        CLxUser_SceneService	 scene_S;
        LXtItemType		 type;
        unsigned		 i, n, max = 0;

        n = scene_S.ItemTypeCount ();
        for (i = 0; i < n; i++)
        {
                lx_err::check (scene_S.ItemTypeByIndex (i, &type));
                max = LXxMAX (max, (unsigned) type);
        }

        typ_state.Alloc (max + 1, -1);
}

        void
CLxItemCurrentTypes::SetDefault ()
{
        CLxUser_SelectionService sel_S;
        LXtID4			 typeID;

        typeID = sel_S.LookupType (LXsSELTYP_ITEM);

        sub_types.clear ();
        lx_err::check (sel_S.GetSubtypeList (typeID, sub_types));

        invalidate ();
}

        void
CLxItemCurrentTypes::SetString (
        const char		*mask)
{
        CLxUser_SceneService	 scene_S;
        CLxParseString		 parse (mask);
        std::string		 name;
        LXtItemType		 type;

        sub_types.clear ();
        while (1)
        {
                parse.PullWhite ();
                if (parse.Done ())
                        break;

                parse.PullDown (name, ";");
                if (LXx_OK (scene_S.ItemTypeLookup (name.c_str(), &type)))
                        sub_types.push_back (type);

                parse.PullExpected (';');
        }

        invalidate ();
}

        bool
CLxItemCurrentTypes::Test (
        LXtItemType		 type)
{
        int			 k, i;

        k = typ_state[(unsigned) type];
        if (k != -1)
                return (k != 0);

        CLxUser_SceneService	 scene_S;

        k = 0;
        for (i = 0; i < sub_types.size(); i++)
                if (scene_S.ItemTypeTest (type, sub_types[i]) == LXe_TRUE)
                {
                        k = 1;
                        break;
                }

        typ_state[(unsigned) type] = k;
        return k != 0;
}


/*
 * ----------------------------------------------------------------
 * CLxSceneSelection : Implementation
 */
CLxSceneSelection::CLxSceneSelection ()
{
        sel_ID = srv_sel.LookupType (LXsSELTYP_SCENE);
        pkt_trans.autoInit ();
}

        bool
CLxSceneSelection::Get (
        CLxUser_Scene		&scene)
{
        void			*pkt;

        pkt = srv_sel.Recent (sel_ID);
        if (!pkt)
                return false;

        return pkt_trans.GetScene (pkt, scene);
}

        bool
CLxSceneSelection::Get (
        CLxUser_ChannelRead	&evalChan)
{
        CLxUser_Scene		 scene;

        if (!Get (scene))
                return false;

        return scene.GetChannels (evalChan, srv_sel.GetTime ());
}

        bool
CLxSceneSelection::Get (
        CLxUser_ChannelRead	&actChan,
        const char		*action)
{
        CLxUser_Scene		 scene;

        if (!Get (scene))
                return false;

        if (!action)
                action = LXs_ACTIONLAYER_EDIT;

        return scene.GetChannels (actChan, action, srv_sel.GetTime ());
}


/*
 * ----------------------------------------------------------------
 * CLxChannelSelection : Implementation
 */
CLxChannelSelection::CLxChannelSelection () :
                CLxAnySelection (LXsSELTYP_CHANNEL)
{
        pkt_trans.autoInit ();
}

        bool
CLxChannelSelection::GetFirst (
        CLxUser_Item		&item,
        unsigned		&index)
{
        LXtScanInfoID		 scan;
        void			*pkt;

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.GetItem (pkt, item);
                index = pkt_trans.Index (pkt);
                return true;
        }

        return false;
}

        void
CLxChannelSelection::GetList (
        ChanList		&list)
{
        Chan			 chan;
        LXtScanInfoID		 scan;
        void			*pkt;

        list.clear ();

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.GetItem (pkt, chan.item);
                chan.index = pkt_trans.Index (pkt);
                list.push_back (chan);
        }
}

        void
CLxChannelSelection::GetSet (
        ChanSet			&set)
{
        Chan			 chan;
        LXtScanInfoID		 scan;
        void			*pkt;

        set.clear ();

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.GetItem (pkt, chan.item);
                chan.index = pkt_trans.Index (pkt);
                set.insert (chan);
        }
}

        void
CLxChannelSelection::LoopInit ()
{
        GetList (tmp_list);
        tmp_idx = 0;
}

        void
CLxChannelSelection::LoopStop ()
{
        tmp_list.clear ();
        tmp_idx = 0;
}

        bool
CLxChannelSelection::LoopNext (
        CLxUser_Item		&item,
        unsigned		&index)
{
        if (tmp_idx < tmp_list.size ())
        {
                Chan &chan = tmp_list[tmp_idx++];
                lx_err::check ( item.set (chan.item) );
                index = chan.index;
                return true;
        }

        LoopStop ();
        return false;
}

        void
CLxChannelSelection::Select (
        CLxUser_Item		&item,
        unsigned		 index)
{
        srv_sel.Select (sel_ID, pkt_trans.Packet (item, index));
}

        void
CLxChannelSelection::Deselect (
        CLxUser_Item		&item,
        unsigned		 index)
{
        srv_sel.Deselect (sel_ID, pkt_trans.Packet (item, index));
}

        void
CLxChannelSelection::Select (
        CLxUser_Item		&item,
        const char		*name)
{
        Select (item, item.ChannelIndex (name));
}

        void
CLxChannelSelection::Deselect (
        CLxUser_Item		&item,
        const char		*name)
{
        Deselect (item, item.ChannelIndex (name));
}


/*
 * SelectionType metaclass.
 */
class impl_SelectionType_Server;

/*
 * Private data for the metaclass itself. Everything here is global state for
 * the SelectionType.
 */
class pv_Meta_SelectionType
{
    public:
        CLxTagList		*tag_list;
        const char		*srv_name;
        const char		*m_table;
        CLxMeta_SelectionType_Core
                                *m_core;
        CLxUser_SelectionService sel_S;
        LXtID4			 id_code;
        bool			 is_undo;

        pv_Meta_SelectionType ()
        {
                tag_list  = 0;
                srv_name  = 0;
                m_table   = 0;
                m_core    = 0;
                id_code   = ~0;
                is_undo   = false;
        }

                void
        add_interfaces (
                CLxGenericPolymorph	*gp)
        {
                gp->AddInterface (new CLxIfc_SelectionType <impl_SelectionType_Server>);
                gp->AddInterface (new CLxIfc_TagDescription<impl_SelectionType_Server>);
        }
};

/*
 * Server implementation class
 */
class impl_SelectionType_Server :
                public CLxImpl_SelectionType,
                public CLxImpl_TagDescription
{
    public:
        pv_Meta_SelectionType	*mpv;
        CLxSelectionType	*inst;

        /*
         * Inialization sets up the arguments from the desc.
         */
        impl_SelectionType_Server (
                pv_Meta_SelectionType	*init = 0)
        {
                mpv = init;
                inst = mpv->m_core->new_inst ();
        }

        LXxO_SelectionType_Size // -> uint
        {
                return inst->size ();
        }

        LXxO_SelectionType_Flags // -> uint
        {
                return (mpv->is_undo ? LXf_SELPACKET_UNDOABLE : 0);
        }

        LXxO_SelectionType_MessageTable // -> const char *
        {
                return (mpv->m_table ? mpv->m_table : mpv->srv_name);
        }

        LXxO_SelectionType_Compare // (void *pkey, void *pelt) -> int
        {
                return inst->compare (pkey, pelt);
        }

        LXxO_SelectionType_SubType // (void *pkt) -> uint
        {
                return inst->subtype (pkt);
        }

        LXxO_TagDescription_Count
        {
                return mpv->tag_list->count ();
        }

        LXxO_TagDescription_Describe
        {
                return mpv->tag_list->describe (index, desc);
        }
};


/*
 * Metaclass implementation.
 */
CLxMeta_SelectionType_Core::CLxMeta_SelectionType_Core (
        const char		*srvName,
        const char		*id)
                :
        CLxMetaServer (srvName)
{
        cls_guid = &lx::guid_SelectionType;
        add_tag (LXsSELTYPE_CODE, id);

        pv = new pv_Meta_SelectionType;
        pv->tag_list = &tag_list;
        pv->srv_name = srvName;
        pv->m_core   = this;
        pv->id_code  = lx::StringID4 (id);
}

CLxMeta_SelectionType_Core::~CLxMeta_SelectionType_Core ()
{
        delete pv;
}

        void *
CLxMeta_SelectionType_Core::alloc ()
{
        return reinterpret_cast<void *>
           ( new CLxMetagenPolymorph<impl_SelectionType_Server, pv_Meta_SelectionType> (pv) );
}

        void
CLxMeta_SelectionType_Core::set_undoable (
        bool			 isUndoable)
{
        pv->is_undo = isUndoable;
}

        LXtID4
CLxMeta_SelectionType_Core::get_ID4 ()
{
        return pv->id_code;
}

        void
CLxMeta_SelectionType_Core::v_select (
        void			*pkt,
        bool			 add)
{
        if (!add)
                clear ();

        pv->sel_S.set();
        lx_err::check (pv->sel_S.Select (pv->id_code, pkt));
}

        void
CLxMeta_SelectionType_Core::v_deselect (
        void			*pkt)
{
        pv->sel_S.set();
        lx_err::check (pv->sel_S.Deselect (pv->id_code, pkt));
}

        void
CLxMeta_SelectionType_Core::clear ()
{
        pv->sel_S.set();
        lx_err::check (pv->sel_S.Clear (pv->id_code));
}

        void
CLxMeta_SelectionType_Core::drop ()
{
        pv->sel_S.set();
        lx_err::check (pv->sel_S.Drop (pv->id_code));
}


