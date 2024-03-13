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
 * Wrapper for accessing different selection types. These are objects that are meant
 * to be created by the client and used for traversing the selection for different
 * varieties of elements. A few allow customization by subclassing.
 */
#ifndef LXU_SELECT_HPP
#define LXU_SELECT_HPP

#include <lx_select.hpp>
#include <lx_seltypes.hpp>
#include <lx_action.hpp>
#include <lx_item.hpp>
#include <lx_mesh.hpp>
#include <lxu_meta.hpp>
#include <vector>
#include <map>
#include <set>


/*
 * --------------------------------------------------------------
 * Selection root class. Get Drop() and Clear() behaviors for all
 * classes.
 */
class CLxAnySelection :
                public CLxObject
{
    public:
        CLxUser_SelectionService	 srv_sel;
        LXtID4				 sel_ID;

        CLxAnySelection (const char *selName);

        void		Drop  ();
        void		Clear ();
};


/*
 * --------------------------------------------------------------
 * Vertex selection object.
 */
class CLxVertexSelection
{
    public:
        typedef std::vector<LXtPointID>			PointList;
        typedef std::vector<LXtPointID>::iterator	PointList_Itr;
        class MeshEntry {
            public:
                CLxUser_Mesh		 mesh;
                CLxUser_Item		 item;
                PointList		 list;
        };
        typedef std::vector<MeshEntry>			MeshList;
        typedef std::vector<MeshEntry>::iterator	MeshList_Itr;

        CLxUser_SelectionService	 srv_sel;
        CLxUser_VertexPacketTranslation	 pkt_trans;
        LXtID4				 sel_ID;
        LXtID4				 sel_comp[4];

                        CLxVertexSelection ();

        /*
         * Return true if there are any vertices directly or indirectly
         * selected.
         */
        bool		AnyDirect ();
        bool		AnyIndirect ();

        /*
         * Get the selected vertices as a nested list: the mesh items that contain
         * selected vertices, and for each the list of selected vertices.
         */
        void		GetDirectList (MeshList &);
};


/*
 * --------------------------------------------------------------
 * Vertex map selection object.
 */
class CLxVertexMapSelection
{
    public:
        class MapInfo {
            public:
                LXtID4			 type;
                std::string		 name;
        };
        typedef std::vector<MapInfo>		MapList;
        typedef std::vector<MapInfo>::iterator	MapList_Itr;

        CLxUser_SelectionService	 srv_sel;
        CLxUser_VMapPacketTranslation	 pkt_trans;
        LXtID4				 sel_ID;

                         CLxVertexMapSelection ();
        virtual		~CLxVertexMapSelection () {}

        /*
         * Get the first selected map, or return false if none.
         */
        bool		First (std::string &);

        /*
         * Get a complete list of selected maps, given by type and name.
         */
        void		GetList (MapList &);

        /*
         * The methods above can be limited to map types that pass this
         * test, which can be overridden by subclasses.
         */
        virtual bool	Include (LXtID4 type)
                        { return true; }
};


/*
 * --------------------------------------------------------------
 * Item selection object.
 */
class CLxItemSelection
{
    public:
        typedef std::vector<CLxUser_Item>		ItemList;
        typedef std::vector<CLxUser_Item>::iterator	ItemList_Itr;
        typedef std::set<CLxUser_Item>			ItemSet;
        typedef std::set<CLxUser_Item>::iterator	ItemSet_Itr;

        CLxUser_SelectionService	 srv_sel;
        CLxUser_ItemPacketTranslation	 pkt_trans;
        LXtID4				 sel_ID;
        ItemList			 tmp_list;
        unsigned			 tmp_idx;

                         CLxItemSelection ();
        virtual		~CLxItemSelection () {}

        /*
         * Get the first selected item, or return false if none.
         */
        bool		GetFirst (CLxUser_Item &);

        /*
         * Return collections of selected items.
         */
        void		GetList (ItemList &);
        void		GetSet  (ItemSet &);

        /*
         * To loop over items, call LoopInit() and then call LoopNext() as long as
         * it returns true. LoopStop() can be called for early exit.
         */
        void		LoopInit ();
        bool		LoopNext (CLxUser_Item &);
        void		LoopStop ();

        /*
         * All the methods above can be limited to items that pass the inclusion
         * test, which can be overridden by subclasses.
         */
        virtual bool	Include (CLxUser_Item &item)
                        { return true; }

        /*
         * Methods to manipulate the selection.
         */
        void		Drop     ();
        void		Clear    ();
        void		Select   (CLxUser_Item &);
        void		Deselect (CLxUser_Item &);
};

/*
 * --------------------------------------------------------------
 * Item selection object, filtered for a single item type.
 */
class CLxItemSelectionType :
                public CLxItemSelection
{
    public:
        CLxItemType			 type;

        CLxItemSelectionType (const char *typeName) : type (typeName) {}

        bool		Include (CLxUser_Item &);
};


/*
 * --------------------------------------------------------------
 * Current item type object. This is used for managing the set of item
 * types -- often called the mask -- which are valid for a specific
 * command.
 */
class CLxItemCurrentTypes
{
    public:
        std::vector<unsigned>		 sub_types;
        CLxArray<int>			 typ_state;

        CLxItemCurrentTypes ();

        /*
         * The current type mask can come from two sources. If a mask
         * string is provided (which is a list of item type names separated
         * by semi-colons), that can be set directly. If there's no explicit
         * mask then the default mask can be read from the current state of
         * item selections.
         */
        void		SetString (const char *mask);
        void		SetDefault ();

        /*
         * Item types in the selection can then be tested against the mask.
         */
        bool		Test (LXtItemType type);

        void		invalidate ();
};


/*
 * --------------------------------------------------------------
 * Channel selection object.
 */
class CLxChannelSelection :
                public CLxAnySelection
{
    public:
        class Chan
        {
            public:
                CLxUser_Item		 item;
                unsigned		 index;

                        bool
                operator< (
                        const Chan	&rhs) const
                {
                        if (item == rhs.item)
                                return index < rhs.index;

                        return (item < rhs.item);
                }
        };

        typedef std::vector<Chan>		ChanList;
        typedef std::vector<Chan>::iterator	ChanList_Itr;
        typedef std::set<Chan>			ChanSet;
        typedef std::set<Chan>::iterator	ChanSet_Itr;

        CLxUser_ChannelPacketTranslation pkt_trans;
        ChanList			 tmp_list;
        unsigned			 tmp_idx;

                        CLxChannelSelection ();

        /*
         * Get the first selected channel, or return false if none.
         */
        bool		GetFirst (CLxUser_Item &, unsigned &);

        /*
         * Return collections of selected channels.
         */
        void		GetList (ChanList &);
        void		GetSet  (ChanSet &);

        /*
         * To loop over channels, call LoopInit() and then call LoopNext() as
         * long as it returns true. LoopStop() can be called for early exit.
         */
        void		LoopInit ();
        bool		LoopNext (CLxUser_Item &, unsigned &);
        void		LoopStop ();

        /*
         * Methods to manipulate the selection.
         */
        void		Select   (CLxUser_Item &, unsigned);
        void		Deselect (CLxUser_Item &, unsigned);

        void		Select   (CLxUser_Item &, const char *);
        void		Deselect (CLxUser_Item &, const char *);
};


/*
 * --------------------------------------------------------------
 * Scene selection object.
 */
class CLxSceneSelection
{
    public:
        CLxUser_SelectionService	 srv_sel;
        CLxUser_ScenePacketTranslation	 pkt_trans;
        LXtID4				 sel_ID;

                        CLxSceneSelection ();

        /*
         * Get the currently selected scene.
         */
        bool		Get (CLxUser_Scene &);

        /*
         * Get evaluated channels from the currently selected scene at the
         * current time.
         */
        bool		Get (CLxUser_ChannelRead &evalChan);

        /*
         * Get action values from the currently selected scene and named
         * action. If the name pointer is null the edit action is used.
         */
        bool		Get (CLxUser_ChannelRead &actChan, const char *action);
};


/*
 * --------------------------------------------------------------
 * SelectionType Metaclass
 *
 * The base class is an abstract class for implementing the methods needed
 * for packets.
 */
class CLxSelectionType :
                public CLxObject
{
    public:
        /*
         * This must be implemented to return the size of the selection packet.
         */
        virtual size_t	size () = 0;

        /*
         * This must be implemented to compare two packets, returning an int
         * with the same sense as strcmp().
         */
        virtual int	compare (void *pkt1, void *pkt2) = 0;

        /*
         * Implement this to return the subtype code for the packet.
         */
        virtual int	subtype (void *pkt) { return 0; }
};

/*
 * This template implements a selection type class based on a packet struct.
 * Note that this is a struct that must not need a copy method or destructor.
 * The struct is expected to have a '<' operator.
 */
template <class P>
class CLxSelectionTypePkt :
                public CLxSelectionType
{
    public:
        /*
         * size() and compare() are fully overloaded.
         */
                size_t
        size ()						LXx_OVERRIDE
        {
                return sizeof (P);
        }

                int
        compare (
                void		*pkt1,
                void		*pkt2)			LXx_OVERRIDE
        {
                P		*p1 = reinterpret_cast<P *> (pkt1);
                P		*p2 = reinterpret_cast<P *> (pkt2);

                return ((*p2) < (*p1)) - ((*p1) < (*p2));
        }

        /*
         * subtype() will take a P* as argument.
         */
                int
        subtype (
                void		*pkt)			LXx_OVERRIDE
        {
                return subtype (reinterpret_cast<P *> (pkt));
        }

        virtual int	subtype (P *pkt) { return 0; }
};

/*
 * Core metaclass sets and gets global properties.
 */
class CLxMeta_SelectionType_Core :
                public CLxMetaServer
{
    public:
         CLxMeta_SelectionType_Core (const char *srvName, const char *id);
        ~CLxMeta_SelectionType_Core ();

        /*
         * Set the selection to be undoable. Default is non-undoable.
         */
        void		set_undoable (bool isUndoable = true);

        /*
         * Get the type code for the selection.
         */
        LXtID4		get_ID4 ();

        /*
         * These utility methods manipulate the global selection.
         */
        void		v_select (void *pkt, bool add = true);
        void		v_deselect (void *pkt);
        void		v_remove (void *pkt);
        void		clear ();
        void		drop ();

    //internal:
        virtual CLxSelectionType *	 new_inst () = 0;

        void *		alloc () LXx_OVERRIDE;

        class pv_Meta_SelectionType	*pv;
};

/*
 * Template for server metaclass. This takes an optional packet struct type,
 * which if omitted has no real effect. If present it creates some type-safe
 * methods.
 */
template <class T, class P = void>
class CLxMeta_SelectionType :
                public CLxMeta_SelectionType_Core
{
    public:
        CLxMeta_SelectionType (const char *srvName, const char *id) : CLxMeta_SelectionType_Core (srvName, id) { }

                CLxSelectionType *
        new_inst ()
        {
                return new T;
        }

                void
        select (P *pkt, bool add = true)
        {
                v_select (reinterpret_cast<void *> (pkt), add);
        }

                void
        deselect (P *pkt)
        {
                v_deselect (reinterpret_cast<void *> (pkt));
        }

                void
        remove (P *pkt)
        {
                v_remove (reinterpret_cast<void *> (pkt));
        }
};


#endif	/* LXU_SELECT_HPP */

