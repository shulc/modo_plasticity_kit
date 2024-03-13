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
#ifndef LXUSER_item_HPP
#define LXUSER_item_HPP

#include <lxw_item.hpp>

#include <lxw_action.hpp>
#include <lxw_particle.hpp>
#include <lxw_value.hpp>
        #include <string>



class CLxUser_SceneSubset : public CLxLoc_SceneSubset
{
        public:
        CLxUser_SceneSubset () {}
        CLxUser_SceneSubset (ILxUnknownID obj) : CLxLoc_SceneSubset (obj) {}



};

class CLxUser_Scene : public CLxLoc_Scene
{
        public:
        CLxUser_Scene () {}
        CLxUser_Scene (ILxUnknownID obj) : CLxLoc_Scene (obj) {}

        /**
         * Localized scene object can be intialized from an item.
         */
                bool
        from (
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                clear ();
                if (LXx_FAIL (item.Context (&obj)))
                        return false;
        
                return take (obj);
        }
        /**
         * Or initialized in the constructor for the wrapper.
         */
        CLxUser_Scene (
                CLxLoc_Item		&item)
        {
                CLxUser_Scene ();
                from (item);
        }
        /**
         * Get evaluated channels for read at the given time.
         */
                bool
        GetChannels (
                CLxLoc_ChannelRead	&chan,
                double			 time) const
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Channels (0, time, &obj))) return false;
                return chan.take (obj);
        }
        /**
         * Get channels from a named action.
         */
                bool
        GetChannels (
                CLxLoc_ChannelRead	&chan,
                const char		*name,
                double			 time = 0.0) const
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Channels (name, time, &obj))) return false;
                return chan.take (obj);
        }
        /**
         * Get evaluated channels in setup mode.
         */
                bool
        GetSetupChannels (
                CLxLoc_ChannelRead	&chan) const
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (SetupChannels (&obj))) {
                        return false;
                }
                else {
                        return chan.take (obj);
                }
        }
        /**
         * Get an interface to write channels to a named action.
         */
                bool
        SetChannels (
                CLxLoc_ChannelWrite	&chan,
                const char		*name,
                double			 time = 0.0)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Channels (name, time, &obj))) return false;
                return chan.take (obj);
        }
        /**
         * Get the item count.
         */
                int
        NItems (
                LXtItemType		 type)
        {
                unsigned		 n;
        
                if (LXx_OK (ItemCount (type, &n)))
                        return n;
                else
                        return -1;
        }
        /**
         * Get items by index.
         */
                bool
        GetItem (
                LXtItemType		 type,
                unsigned		 index,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ItemByIndex (type, index, &obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * Get an item from the scene by name.
         */
                bool
        GetItem (
                const char		*name,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ItemLookup (name, &obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * This method gets an item by types by index.
         */
                bool
        GetItem (
                LXtItemType		*types,
                unsigned		 index,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ItemByIndexByTypes (types, index, &obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * This gets a single item of the given type, if any.
         */
                bool
        GetItem (
                LXtItemType		 type,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (AnyItemOfType (type, &obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * Create a new item by type code.
         */
                bool
        NewItem (
                LXtItemType		 type,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ItemAdd (type, &obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * Create a new item by type name using a scene service.
         */
                bool
        NewItem (
                const char		*typeName,
                CLxLoc_SceneService	&svc,
                CLxLoc_Item		&item)
        {
                LXtItemType		 type;
        
                if (LXx_FAIL (svc.ItemTypeLookup (typeName, &type)))
                        return false;
        
                return NewItem (type, item);
        }
        /**
         * Create a new item by type name without using a scene service. (The service
         * is allocated by the method.)
         */
                bool
        NewItem (
                const char		*typeName,
                CLxLoc_Item		&item)
        {
                CLxLoc_SceneService	 svc;
        
                return NewItem (typeName, svc, item);
        }
        /**
         * This method returns a scene graph from an ILxScene by name.
         */
                bool
        GetGraph (
                const char		*name,
                CLxLocalizedObject	&graph)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (GraphLookup (name, &obj)))
                        return false;
        
                return graph.take (obj);
        }
        /**
         * Remove the item from the scene.
         */
                bool
        RemItem (
                CLxLoc_Item		&item)
        {
                return LXx_OK (ItemRemove (item)) ? true : false;
        }
        /**
         * Create a new item with the specified type from passed item, replacing the original.
         */
                bool
        ReplaceItem (
                CLxLoc_Item		&item,
                LXtItemType		 type,
                CLxLoc_Item		&newItem)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ItemReplace (item, type, &obj)))
                        return false;
        
                return newItem.take (obj);
        }
        /**
         * Lookup item using ident only.
         */
                bool
        GetItemByIdent (
                const char		*name,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ItemLookupIdent (name, &obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * Lookup an imported item by it's original ident.
         */
                bool
        GetImportedItem (
                const char		*name,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (ItemLookupImported (name, &obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * Get the number of render cameras.
         */
                int
        NRenderCameras ()
        {
                int			 n;
        
                if (LXx_OK (RenderCameraCount (&n)))
                        return n;
                else
                        return 0;
        }
        /**
         * Get the render camera by index.
         */
                bool
        GetRenderCameraByIndex (
                int			 index,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (RenderCameraByIndex (index, &obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * Get the render camera index.
         */
                int
        GetRenderCameraIndex (
                CLxLoc_Evaluation	 eval)
        {
                ILxEvaluationID		 ev;
                int			 i;
        
                eval.get ((void **)&ev);
        
                if (LXx_OK (RenderCameraIndex ((ILxUnknownID)ev, &i)))
                        return i;
                else
                        return 0;
        }

};

class CLxUser_Item : public CLxLoc_Item
{
        public:
        CLxUser_Item () {}
        CLxUser_Item (ILxUnknownID obj) : CLxLoc_Item (obj) {}

        /**
         * This returns true if an item matches or inherits from a given type.
         */
                bool
        IsA (
                LXtItemType		 type)
        {
                return (TestType (type) == LXe_OK);
        }
        /**
         * This returns true if an item matches or inherits from a list of types.
         */
                bool
        IsA (
                LXtItemType		*types)
        {
                return (TestTypes (types) == LXe_OK);
        }
        /**
         * This method returns the ident pointer directly.
         */
                const char *
        IdentPtr () const
        {
                const char		*id;
        
                Ident (&id);
                return id;
        }
        /**
         * Get the item's ident as a C++ string.
         */
                std::string
        GetIdentity ()
        {
                std::string	 identity;
                const char	*ident;
        
                if (LXx_OK (Ident (&ident))) {
                        identity = std::string(ident);
                }
        
                return identity;
        }
        /**
         * Given the caveat that it might change during loading, the item ident can also be
         * used to provide operator overloads allowing items to be sorted (less-than is the
         * standard operator used for std::map searches, for example).
         */
                bool
        operator< (
                const CLxUser_Item	&rhs) const
        {
                return IdentPtr () < rhs.IdentPtr ();
        }
        /**
         * This operator allows item wrappers to be tested for equivalence.
         */
                bool
        operator== (
                const CLxUser_Item	&rhs) const
        {
                return IdentPtr () == rhs.IdentPtr ();
        }
        
                bool
        operator!= (
                const CLxUser_Item	&rhs) const
        {
                return IdentPtr () != rhs.IdentPtr ();
        }
        /**
         * Get the unique name as a C++ string.
         */
                void
        GetUniqueName (
                std::string		&name)
        {
                const char		*sptr;
        
                if (LXx_OK (UniqueName (&sptr)))
                        name = sptr;
        }
        /**
         * Get the parent of this item or return false.
         */
                bool
        GetParent (
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Parent (&obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * This returns a child item by index.
         */
                bool
        GetSubItem (
                unsigned		 index,
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (SubByIndex (index, &obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * Get the root ancestor of this item.
         */
                bool
        GetRoot (
                CLxLoc_Item		&item)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Root (&obj)))
                        return false;
        
                return item.take (obj);
        }
        /**
         * This method returns the scene that the item belongs to.
         */
                bool
        GetContext (
                CLxLoc_Scene		&scene)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Context (&obj)))
                        return false;
        
                return scene.take (obj);
        }
        /**
         * Get the number of channels on the item.
         */
                unsigned
        NChannels () const
        {
                unsigned		 count;
        
                if (LXx_OK (ChannelCount (&count)))
                        return count;
        
                return 0;
        }
        /**
         * Get the index of a named channels on the item.
         */
                int
        ChannelIndex (
                const char		*name) const
        {
                unsigned		 idx;
        
                if (LXx_OK (ChannelLookup (name, &idx)))
                        return idx;
        
                return -1;
        }
        /**
         * This method will decode a text value using hints into a numeric value.
         */
                int
        ChannelDecode (
                unsigned		 index,
                const char		*encoded) const
        {
                CLxLoc_ValueService	 valueSvc;
                int			 value;
                const LXtTextValueHint	*hints;
        
                if (  LXx_OK (ChannelIntHint (index, &hints))
                  &&  LXx_OK (valueSvc.TextHintDecode (encoded, hints, &value)) )
                        return value;
        
                return -1;
        }
        /**
         * Get the base name as a C++ string.
         */
                void
        GetBaseName (
                std::string		&name)
        {
                const char		*sptr;
        
                if (LXx_OK (BaseName (&sptr)))
                        name = sptr;
        }

};

class CLxUser_SceneGraph : public CLxLoc_SceneGraph
{
        public:
        CLxUser_SceneGraph () {}
        CLxUser_SceneGraph (ILxUnknownID obj) : CLxLoc_SceneGraph (obj) {}

        /**
         * Graphs can also be initialized from scenes and items.
         */
                // QWEB_MACRO_BEGIN - SDK Common user: Graph methods
                bool
        from (
                CLxLoc_Scene		&scene,
                const char		*name)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (scene.GraphLookup (name, &obj)))
                        return false;
        
                return take (obj);
        }
                bool
        from (
                CLxLoc_Item		&item,
                const char		*name)
        {
                CLxLoc_Scene		 scene;
                LXtObjectID		 obj;
        
                if (LXx_FAIL (item.Context (&obj)))
                        return false;
        
                scene.take (obj);
                return from (scene, name);
        }
                // QWEB_MACRO_END - SDK Common user: Graph methods

};

class CLxUser_ItemGraph : public CLxLoc_ItemGraph
{
        public:
        CLxUser_ItemGraph () {}
        CLxUser_ItemGraph (ILxUnknownID obj) : CLxLoc_ItemGraph (obj) {}

        // QWEB_MACRO_BEGIN - SDK Common user: Graph methods
                bool
        from (
                CLxLoc_Scene		&scene,
                const char		*name)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (scene.GraphLookup (name, &obj)))
                        return false;
        
                return take (obj);
        }
                bool
        from (
                CLxLoc_Item		&item,
                const char		*name)
        {
                CLxLoc_Scene		 scene;
                LXtObjectID		 obj;
        
                if (LXx_FAIL (item.Context (&obj)))
                        return false;
        
                scene.take (obj);
                return from (scene, name);
        }
                // QWEB_MACRO_END - SDK Common user: Graph methods
        /**
         * This gets the count of forward links.
         */
                unsigned
        Forward (
                CLxLoc_Item		&item)
        {
                unsigned		 n;
        
                if (LXx_FAIL (FwdCount (item, &n)))
                        n = 0;
        
                return n;
        }
        /**
         * This get the destination of the forward link by index.
         */
                bool
        Forward (
                CLxLoc_Item		&item,
                unsigned		 index,
                CLxLoc_Item		&dest)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (FwdByIndex (item, index, &obj)))
                        return false;
        
                return dest.take (obj);
        }
        /**
         * This gets the count of reverse links.
         */
                unsigned
        Reverse (
                CLxLoc_Item		&item)
        {
                unsigned		 n;
        
                if (LXx_FAIL (RevCount (item, &n)))
                        n = 0;
        
                return n;
        }
        /**
         * This get the source of the reverse link by index.
         */
                bool
        Reverse (
                CLxLoc_Item		&item,
                unsigned		 index,
                CLxLoc_Item		&dest)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (RevByIndex (item, index, &obj)))
                        return false;
        
                return dest.take (obj);
        }

};

class CLxUser_ChannelGraph : public CLxLoc_ChannelGraph
{
        public:
        CLxUser_ChannelGraph () {}
        CLxUser_ChannelGraph (ILxUnknownID obj) : CLxLoc_ChannelGraph (obj) {}

        // QWEB_MACRO_BEGIN - SDK Common user: Graph methods
                bool
        from (
                CLxLoc_Scene		&scene,
                const char		*name)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (scene.GraphLookup (name, &obj)))
                        return false;
        
                return take (obj);
        }
                bool
        from (
                CLxLoc_Item		&item,
                const char		*name)
        {
                CLxLoc_Scene		 scene;
                LXtObjectID		 obj;
        
                if (LXx_FAIL (item.Context (&obj)))
                        return false;
        
                scene.take (obj);
                return from (scene, name);
        }
                // QWEB_MACRO_END - SDK Common user: Graph methods

};

class CLxUser_SceneService : public CLxLoc_SceneService
{
        public:
        /**
         * A user method provides easier syntax.
         */
                LXtItemType
        ItemType (
                const char		*name)
        {
                LXtItemType		 type;
        
                if (LXx_FAIL (ItemTypeLookup (name, &type)))
                        return LXiTYPE_NONE;
        
                return type;
        }
        bool
        NewScene (
                CLxLoc_Scene		&scene)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateScene (&obj)))
                        return false;
        
                return scene.take (obj);
        }
        bool
        NewReplicatorEnumerator (
                ILxUnknownID			 pItem,
                CLxLoc_ReplicatorEnumerator	&replicatorEnum)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (GetReplicatorEnumerator (pItem, &obj)))
                        return false;
        
                return replicatorEnum.take (obj);
        }

};
/*
 * This is a simple utility class that provides item type IDs. First time it's
 * requested it's cached.
 */
class CLxItemType {
    public:
        const char		*type_name;
        LXtItemType		 cached_code;

        CLxItemType (
                const char	*typeName = 0)
        {
                set (typeName);
        }

                void
        set (
                const char	*typeName)
        {
                type_name   = typeName;
                cached_code = LXiTYPE_NONE;
        }

                LXtItemType
        Type ()
        {
                if (cached_code != LXiTYPE_NONE || !type_name)
                        return cached_code;

                CLxUser_SceneService srv;

                cached_code = srv.ItemType (type_name);
                return cached_code;
        }

                operator
        LXtItemType ()
        {
                return Type ();
        }
};
#endif
