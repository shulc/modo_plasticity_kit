/*
 * Plug-in SDK Header: Modifier Wrapper Classes
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
 * An eval modifier is a server that allocates modifier nodes. There can be
 * many nodes depending on the items in the scene. Evaluating a modifier node
 * reads and sets channels, and any combination of channels on any items can
 * be inputs or outputs.
 *
 * This header provides wrapper classes for creating modifiers in C++
 * plug-ins.
 * 
 * See Also:
 * * [[:Category:item (lx-item.hpp)]]
 * * [[:Category:action (lx-action.hpp)]]
 * * [[Evaluation (interface)]]
 * * [[Attributes (interface)]]
 */
//@title Eval Modifiers

#ifndef LXU_MODIFIER_HPP
#define LXU_MODIFIER_HPP

#include <lx_item.hpp>
#include <lx_value.hpp>
#include <lxu_attrdesc.hpp>
#include <vector>
#include <string>

/*
 * Meta type for sub-evaluators:
 */
#define LXsMETA_EVALUATOR	"evaluator"

/*
 * ----------------------------------------------------
 * -- Common Modifier
 *
 * The CLxEvalModifier class implements the core features of any eval
 * modifier. The client creates their own subclass and uses that to
 * instantiate the meta object for the server. The base class also contains
 * methods that allow the client to access the state of the modifier node.
 *
 * See Also:
 * [[CLxMeta_EvalModifier (class)]]
 */
class CLxEvalModifier :
                public CLxObject
{
    public:
        CLxEvalModifier ();

        /*
         * ----------------
         * @sec Allocating Nodes
         *
         * If the modifier is associated with an item type, then there will
         * be one modifier allocated for each item of that type. If a different
         * behavior is required call get_all_items() on the meta object, and
         * then this function will be called for all items in the scene. Any
         * number of nodes can be allocated for that item by calling
         * mod_add_node().
         */
        virtual void		 include_item (CLxUser_Item &) {}

        /*
         * Call this to add a node for the current item. Multiple nodes can be
         * added by giving them different indices.
         */
        void			 mod_add_node (unsigned ident = 0);

        /*
         * ----------------
         * @sec Instantiation
         *
         * When a node is allocated there's also a new instance of this class,
         * and it will need to be bound to channels. These must be added with
         * these functions.
         */
        virtual void		 bind (CLxUser_Item &item, unsigned ident) {}

        /*
         * Call this to add a channel by name with the given access type.
         */
        void			 mod_add_chan (CLxUser_Item &, const char *, unsigned type = LXfECHAN_READ);

        /*
         * Call this to add a channel by index with the given access type.
         */
        void			 mod_add_chan (CLxUser_Item &, unsigned,     unsigned type = LXfECHAN_READ);

        /*
         * ----------------
         * @sec Changes
         *
         * Normally modifiers will be invalidated if their custom channels
         * change. An additional test can be added if required.
         */
        virtual bool		 change_test ()
                                        { return true; }

        /*
         * ----------------
         * @sec Evaluation
         *
         * Once a node is instantied and channels are bound, it will be called
         * to read its inputs and evaluate its outputs.
         */
        virtual void		 eval ()
                                        { }

        /*
         * The state of the modifier can be read with these methods.
         *
         * Call this to get the item for the modifier.
         */
        CLxUser_Item *		 mod_item ();

        /*
         * Call this to get the index of the node.
         */
        unsigned		 mod_index ();

        /*
         * Call this to get the Evaluation interface.
         */
        CLxUser_Evaluation *	 mod_eval ();

        /*
         * Call this to get the Attributes interface.
         */
        CLxUser_Attributes *	 mod_attr ();

        /*
         * ----------------
         * @sec Read / Write
         *
         * If a CLxAttributeDesc is associated with the meta object then eval
         * channels will have been bound and can be read with this method.
         */
        void			 mod_read_attr (void *ptr);

        /*
         * Channels added as custom can be read either from the attributes
         * interface or using these read functions.
         *
         * Call this to get the index in the Attributes interface for this
         * custom channel given by its custom channel index.
         */
        unsigned		 mod_cust_index (unsigned);

        /*
         * Call this to read a boolean channel by custom index.
         */
        void			 mod_cust_val (unsigned, bool *);

        /*
         * Call this to read an integer channel by custom index.
         */
        void			 mod_cust_val (unsigned, int *);

        /*
         * Call this to read a double channel by custom index.
         */
        void			 mod_cust_val (unsigned, double *);

        /*
         * Call this to read a matrix channel by custom index.
         */
        void			 mod_cust_val (unsigned, LXtMatrix4 &m);


        /*
         * Call this to write a boolean channel by custom index.
         */
        void			 mod_cust_write (unsigned, bool);

        /*
         * Call this to write an integer channel by custom index.
         */
        void			 mod_cust_write (unsigned, int);

        /*
         * Call this to write a double channel by custom index.
         */
        void			 mod_cust_write (unsigned, double);

        /*
         * Call this to write a matrix channel by custom index.
         */
        void			 mod_cust_write (unsigned, const LXtMatrix4 &m);

        /*
         * Call this to set the return success code for the modifier
         * (if other than LXe_OK).
         */
        void			 mod_result (LxResult);

        class pv_EvalModifier_Server	*psrv;
        class pv_EvalModifier		*pmod;
};


/*
 * ---------------------
 * -- Common Modifier Meta
 *
 * The CLxEvalModifier_Core class is the base class from which the meta
 * template classes derive. It provides methods to allow the client to
 * customize their modifier.
 */
class CLxMeta_EvalModifier_Core :
                public CLxMetaServer
{
    public:
        /*
         * Set the eval modifier server name in the constructor.
         */
        CLxMeta_EvalModifier_Core (const char *srvName);

        /*
         * If there's a package server in the meta tree then that's
         * automatically set as the main item type for the modifier.
         * That can be overridden with this call.
         */
        void		 set_itemtype (const char *);

        /*
         * A modifier associated with an item type will allocate one modifier
         * node for each item of that type. Calling get_all_items() will
         * instead configure the modifier to process all items, adding zero
         * or more nodes for each.
         */
        void		 get_all_items ();

        /*
         * A modifier can be a simulation if it also inherits from CLxSimulation.
         */
        void		 set_simulation ();

        /*
         * Modifiers can be automatically invalidated for changes related to
         * other item types. Multiple item types can be added, one at a time.
         */
        void		 add_dependent_type (const char *);

        /*
         * Modifiers can be automatically invalidated for changes related to
         * named graphs. Multiple graphs can be added, one at a time.
         */
        void		 add_dependent_graph (const char *);

        /*
         * Any change (other than item types or graphs) that require the modifier
         * nodes to be refreshed should invalidate the modifier. If 'reset' is
         * true then the results of all modifier nodes are cleared regardless.
         *
         * Call to invalidate (or reset) this modifier from a scene object.
         */
        void		 invalidate (ILxUnknownID   scene, bool reset = false);

        /*
         * Call to invalidate (or reset) this modifier from a scene.
         */
        void		 invalidate (CLxUser_Scene &scene, bool reset = false);

        /*
         * Call to invalidate (or reset) this modifier from an item.
         */
        void		 invalidate (CLxUser_Item  &item,  bool reset = false);

  //internal:
        ~CLxMeta_EvalModifier_Core ();

        virtual CLxEvalModifier *	 new_inst () = 0;
        virtual void *			 alloc ();

        class pv_Meta_EvalModifier *pv;
};

/*
 * The meta template class for the modifier is a server and can be installed
 * at the root of the meta tree.
 *
 * @code
 * class CMyEvalModifier : public CLxEvalModifier
 * {
 *     ...
 * };
 *
 * static CLxMeta_EvalModifier<CMyEvalModifier>   mod_meta ("serverName");
 *
 * initialize ()
 * {
 *     root_meta.add (&mod_meta);
 * }
 *
 * See Also:
 * [[CLxEvalModifier (class)]]
 */
template <class T>
class CLxMeta_EvalModifier :
                public CLxMeta_EvalModifier_Core
{
    public:
        /*
         * Set the eval modifier server name in the constructor.
         */
        CLxMeta_EvalModifier (const char *name) : CLxMeta_EvalModifier_Core (name)
        {
                cls_guid = &lx::guid_EvalModifier;
        }

    //internal:
                CLxEvalModifier *
        new_inst ()					LXx_OVERRIDE
        {
                return new T;
        }
};


/*
 * A Simulation modifier works the same as a normal modifier, except that it's
 * called in sequence as the simulation advances, and the state is computed in
 * the step() method, not the eval() method.
 *
 * This class cannot be used alone, but must be part of the same modifier class.
 *
 * @code
 * class CMySimMod :
 *		public CLxEvalModifier,
 *		public CLxSimulation
 * {
 *     ...
 * };
 *
 * static CLxMeta_EvalModifier<CMySimMod>  mod_meta ("serverName");
 *
 * initialize ()
 * {
 *     root_meta.add (&mod_meta);
 *     mod_meta.set_simulation ();
 * }
 *
 * See Also:
 * [[CLxMeta_EvalModifier (class)]]
 */
class CLxSimulation
{
    public:
        /*
         * Implement to test if the simulation is enabled based on reading
         * channel state.
         */
        virtual bool		enabled (CLxUser_ChannelRead &) { return true; }

        /*
         * Implement to initialize the simulation at the given start time and
         * sample rate. Initial consitions should be read as inputs.
         */
        virtual void		init_sim (double time, double sample) {}

        /*
         * Implement to shut down the simulation.
         */
        virtual void		cleanup_sim () {}

        /*
         * Implement to request a different step size for sampling.
         */
        virtual double		step_size () { return 0.0; }

        /*
         * Implement to compute the next step by reading inputs and writing
         * outputs.
         */
        virtual void		step (double dt) = 0;
};


/*
 * ---------------------
 * -- Different Evaluation Patterns
 *
 * The common modifier can be further customized by adding an alternate
 * evaluation class as a sub-meta object. This evaluator will be allocated
 * 1-to-1 with modifier nodes, and will be asked to bind as part of linking
 * channels and evaluate in place of the normal evaluation.
 */
//@util CLxEvalModifier_Evaluator

class CLxEvalModifier_Evaluator :
                public CLxObject
{
    public:
        /*
         * The alloc() function for an Evaluator metaclass returns a new
         * instance of the CLxEvalModifier_Evaluator object.
         */
    //internal:
        virtual void		 bind (CLxEvalModifier &) { }
        virtual void		 eval (CLxEvalModifier &) = 0;
};


/*
 * 	----------
 * Object evaluation will place an allocated object into an output channel.
 * The channel is given in the constructor of the meta object.
 *
 * See Also:
 * [[CLxMeta_ObjectEvaluation (class)]]
 */
class CLxObjectEvaluation
{
    public:
        /*
         * Allocate the output object from the modifier's inputs.
         */
        virtual void		 alloc_obj (CLxEvalModifier &, ILxUnknownID &) = 0;
};

/*
 * The meta object for the evaluation class is added as a sub-object of the
 * modifier meta object.
 *
 * @code
 * class CMyObjectEvaluation : public CLxObjectEvaluation
 * {
 *     ...
 * };
 *
 * static CLxMeta_EvalModifier<CMyEvalModifier>         mod_meta ("serverName");
 * static CLxMeta_ObjectEvaluation<CMyObjectEvaluation> eval_meta ("objChannelName");
 *
 * initialize ()
 * {
 *     root_meta.add (&mod_meta);
 *     mod_meta.add (&eval_meta);
 * }
 * @end
 *
 * Very often the client's CLxEvalModifier and CLxObjectEvaluation are the
 * same class.
 *
 * See Also:
 * [[CLxObjectEvaluation (class)]]
 */
template <class T>
class CLxMeta_ObjectEvaluation :
                public CLxMeta
{
    public:
    //internal:
        class cEvaluator : public CLxEvalModifier_Evaluator
        {
            public:
                T		 m_client;
                const char	*chan_name;
                unsigned	 attr_index;

                        void
                bind (
                        CLxEvalModifier	&com)	LXx_OVERRIDE
                {
                        CLxUser_Evaluation	*eval = com.mod_eval ();
                        CLxUser_Item		*item = com.mod_item ();

                        lx_err::check (eval->AddChannelName (*item, chan_name, LXfECHAN_WRITE, &attr_index));
                }

                        void
                eval (
                        CLxEvalModifier	&com)	LXx_OVERRIDE
                {
                        CLxUser_ValueReference	 ref;
                        ILxUnknownID		 obj;
        
                        m_client.alloc_obj (com, obj);
                        CLxArmUnknownRef tmp (obj);

                        lx_err::check (com.mod_attr() -> ObjectRW (attr_index, ref));
                        ref.SetObject (obj);
                }
        };

        CLxMeta_ObjectEvaluation (
                const char		*chan)
        {
                m_type = LXsMETA_EVALUATOR;
                m_name = chan;
        }

                void *
        alloc ()					LXx_OVERRIDE
        {
                cEvaluator		*etor;

                etor = new cEvaluator;
                etor->chan_name = m_name.c_str();
                return reinterpret_cast<void *> ((CLxEvalModifier_Evaluator *) etor);
        }
};


/*
 * 	----------
 * An alternate form of object evaluation gets the object from a sub-metaclass
 * from the evaluator meta. In this case the client only needs to provide the
 * type (for the templates) and an init function.
 *
 * See Also:
 * [[CLxMeta_TypeEvaluation (class)]]
 */
template <class S>
class CLxTypeEvaluation
{
    public:
        /*
         * Intialize the new object from the modifer's inputs.
         */
        virtual void		 init_obj (CLxEvalModifier &, S &) = 0;
};

/*
 * The meta object for the evaluation class is added as a sub-object of the
 * modifier meta object.
 *
 * @code
 * class CMyTypeEvaluation : public CLxTypeEvaluation<CMyType>
 * {
 *     ...
 * };
 *
 * static CLxMeta_EvalModifier<CMyEvalModifier>         mod_meta ("serverName");
 * static CLxMeta_TypeEvaluation<CMyTypeEvaluation, CMyType> eval_meta ("objChannelName");
 *
 * initialize ()
 * {
 *     root_meta.add (&mod_meta);
 *     mod_meta.add (&eval_meta);
 * }
 * @end
 *
 * Very often the client's CLxEvalModifier and CLxTypeEvaluation are the
 * same class.
 *
 * See Also:
 * [[CLxTypeEvaluation (class)]]
 */
template <class T, class S>
class CLxMeta_TypeEvaluation :
                public CLxMeta
{
    public:
    //internal:
        class cEvaluator : public CLxEvalModifier_Evaluator
        {
            public:
                T		 m_client;
                CLxMetaObject	*obj_spawn;
                const char	*chan_name;
                unsigned	 attr_index;

                        void
                bind (
                        CLxEvalModifier	&com)	LXx_OVERRIDE
                {
                        CLxUser_Evaluation	*eval = com.mod_eval ();
                        CLxUser_Item		*item = com.mod_item ();

                        lx_err::check (eval->AddChannelName (*item, chan_name, LXfECHAN_WRITE, &attr_index));
                }

                        void
                eval (
                        CLxEvalModifier	&com)	LXx_OVERRIDE
                {
                        CLxUser_ValueReference	 ref;
                        ILxUnknownID		 obj;
                        void			*ptr;

                        ptr = obj_spawn->spawn_raw (obj);
                        CLxArmUnknownRef tmp (obj);

                        m_client.init_obj (com, ((S *) ptr)[0]);

                        lx_err::check (com.mod_attr() -> ObjectRW (attr_index, ref));
                        ref.SetObject (obj);
                }
        };

        CLxMeta_TypeEvaluation (
                const char		*chan)
        {
                m_type = LXsMETA_EVALUATOR;
                m_name = chan;
        }

                void *
        alloc ()					LXx_OVERRIDE
        {
                cEvaluator		*etor;
                CLxMeta			*mobj;

                etor = new cEvaluator;
                etor->chan_name = m_name.c_str();

                mobj = find_sub (LXsMETA_OBJECT);
                etor->obj_spawn = dynamic_cast<CLxMetaObject *> (mobj);

                return reinterpret_cast<void *> ((CLxEvalModifier_Evaluator *) etor);
        }
};


/*
 * 	----------
 * Cache evaluation stores a client object in the modifier cache so that it
 * will be passed back if an evaluation happens again. The boolean will be
 * true if this is a re-evaluation.
 *
 * See Also:
 * [[CLxMeta_CacheEvaluation (class)]]
 */
class CLxCacheEvaluation
{
    public:
        /*
         * Allocate an object to store in the cache.
         */
        virtual CLxObject *	 cache_alloc () = 0;

        /*
         * Evaluate the modifier using an optional cache from previous eval.
         */
        virtual void		 cache_eval (CLxEvalModifier &, CLxObject *, bool) = 0;
};

/*
 * The meta object for the class is added as a sub-object of the modifier
 * meta object.
 *
 * @code
 * class CMyCacheEvaluation : public CLxCacheEvaluation
 * {
 *     ...
 * };
 *
 * static CLxMeta_EvalModifier<CMyEvalModifier>         mod_meta ("serverName");
 * static CLxMeta_CacheEvaluation<CMyCacheEvaluation>	eval_meta ();
 *
 * initialize ()
 * {
 *     root_meta.add (&mod_meta);
 *     mod_meta.add (&eval_meta);
 * }
 * @end
 *
 * See Also:
 * [[CLxCacheEvaluation (class)]]
 */
template <class T>
class CLxMeta_CacheEvaluation :
                public CLxMeta
{
    public:
    //internal:
        class cEvaluator : public CLxEvalModifier_Evaluator
        {
            public:
                T		 m_client;

                        void
                eval (
                        CLxEvalModifier	&com)	LXx_OVERRIDE
                {
                        CLxUser_Evaluation	*eval = com.mod_eval ();
                        CLxObject		*cache;
                        bool			 reEval;

                        cache = reinterpret_cast<CLxObject *> (eval->GetCache ());
                        if (cache)
                                reEval = true;
                        else
                        {
                                cache = m_client.cache_alloc ();
                                eval->SetCache (cache);
                                reEval = false;
                        }

                        m_client.cache_eval (com, cache, reEval);
                }
        };

        CLxMeta_CacheEvaluation ()
        {
                m_type = LXsMETA_EVALUATOR;
        }

                void *
        alloc ()					LXx_OVERRIDE
        {
                cEvaluator		*etor;

                etor = new cEvaluator;
                return reinterpret_cast<void *> ((CLxEvalModifier_Evaluator *) etor);
        }
};


// ----------- deprecated (modo 10.2)
// @skip


/*
 * ----------------------------------------------------
 * Item Modifier
 *
 * An item modifier is a server that allocates a modifier for each item of a
 * given type. The client can then read and set channels on that (or any other)
 * item.
 */

/*
 * The element is subclassed by the client, and there is one allocated for each
 * affected item.
 */
class CLxItemModifierElement :
                public CLxObject
{
    public:
        /*
         * Test if the state of this element matches what would be generated
         * using the Alloc() method on this item. Default is true, which is
         * typically correct for modifiers that don't depend on other items.
         */
        virtual bool		Test (ILxUnknownID)
                                        { return true; }

        /*
         * The Eval() method is called to read from modifier inputs and
         * write to outputs. This is the core operation of the modifier.
         */
        virtual void		Eval (CLxUser_Evaluation &, CLxUser_Attributes &)
                                        {}

        /*
         * The Cache() method allocates and returns a cache object. It is not
         * initialized but will be passed to evaluation.
         */
        virtual CLxObject *	Cache ()
                                        { return 0; }

        /*
         * The EvalCache() method is called to read from modifier inputs and
         * write to outputs for modifiers that have a non-null cache. The
         * cache object is passed plus true if this is a cache from a previous
         * evaluation.
         */
        virtual LxResult	EvalCache (CLxUser_Evaluation &, CLxUser_Attributes &, CLxObject *, bool)
                                        { return LXe_FAILED; }

        /*
         * The Validate() method is called when there are changes to the inputs
         * of a modifier with cached state. Client methods must return 'true'.
         */
        virtual bool		Validate (CLxObject *, CLxUser_Item &, unsigned, LxResult)
                                        { return false; }
};


/*
 * Modifier node is the more raw object that wraps the element. This really
 * should be private except for its use in a template in the essentially
 * private part of the next class.
 */
class CLxItemModifierNode :
                public CLxImpl_Modifier
{
    public:
        CLxItemModifierElement	*p_elt;
        CLxUser_Evaluation	 m_eval;
        CLxUser_Attributes	 m_attr;
        bool			 has_cache;

        ~CLxItemModifierNode ();

        LxResult	 mod_Evaluate ()					LXx_OVERRIDE;
        LxResult	 mod_Test (ILxUnknownID, unsigned)			LXx_OVERRIDE;
        LxResult	 mod_Validate (ILxUnknownID, unsigned, LxResult)	LXx_OVERRIDE;
        void		 mod_Free (void *)					LXx_OVERRIDE;
};


/*
 * The modifier server is subclassed by the client, and is exported as a server.
 * The virtual methods specify the item type to traverse and provide a way to allocate
 * new elements for items in the scene.
 */
class CLxItemModifierServer :
                public CLxImpl_EvalModifier,
                public CLxImpl_TagDescription
{
    public:
                         CLxItemModifierServer ();
        virtual		~CLxItemModifierServer () {}

        /*
         * This method returns the name of the item type for this
         * modifier. If set this type is required for the modifier to
         * be active.
         */
        virtual const char *			 ItemType () { return 0; }

        /*
         * This optionally returns the names of item types to watch for
         * changes. If unset it will default to ItemType().
         */
        virtual const char *			 ItemTypeList () { return 0; }

        /*
         * This optionally returns the names of graphs to watch for changes.
         */
        virtual const char *			 GraphNames () { return 0; }

        /*
         * This optionally tests an item to see if a modifier should be allocated.
         */
        virtual bool				 Include (CLxUser_Item &item) { return true; }

        /*
         * This function cmoputes the list of all item/index pairs to be 
         * allocated for this modifier in this scene. The default is to
         * include all items of the main type with index zero.
         */
        virtual void				 UpdateList (CLxUser_Scene &);

        void		add_entry (CLxUser_Item &, unsigned);

        /*
         * The Alloc() method is called to create a new modifier element for a
         * specific item. This should add channels in the evaluation interface and
         * record their indices for evaluation. The index for this modifier can be
         * read from the mod_index member variable.
         */
        virtual CLxItemModifierElement *	 Alloc (CLxUser_Evaluation &, ILxUnknownID item) = 0;

        LxResult	 eval_Reset (ILxUnknownID scene)		LXx_OVERRIDE;
        LXtObjectID	 eval_Next (unsigned *index)			LXx_OVERRIDE;
        LxResult	 eval_Alloc (ILxUnknownID item, unsigned index, ILxUnknownID eval, void **ppvObj)
                                                                        LXx_OVERRIDE;

        unsigned	 tag_Count ()					LXx_OVERRIDE;
        LxResult	 tag_Describe (unsigned, LXtTagInfoDesc *desc)	LXx_OVERRIDE;

        std::vector<std::string>		 l_tags;
        std::vector<std::string>		 l_vals;
        std::vector<CLxUser_Item>		 l_item;
        std::vector<unsigned>			 l_indx;
        unsigned				 i_scan;
        LXtItemType				 i_type;

        CLxPolymorph<CLxItemModifierNode>	*spawn;

        unsigned				 mod_index;
};


/*
 * Construtors on template classes can kind of work like functions with
 * parameterized types. Declaring and installing the modifier server can be done
 * by instantiating this object with the class of the client's subclassed version
 * of CLxItemModifierServer and the server name.
 *
 *	initialize ()
 *	{
 *		CLxExport_ItemModifierServer<CMyModifier> ("myModifier");
 *	}
 */
template <class T>
class CLxExport_ItemModifierServer
{
    public:
        CLxExport_ItemModifierServer (
                const char		*name)
        {
                CLxGenericPolymorph	*srv;

                srv = new CLxPolymorph<T>;
                srv->AddInterface (new CLxIfc_EvalModifier  <T>);
                srv->AddInterface (new CLxIfc_TagDescription<T>);
                lx::AddServer (name, srv);
        }
};



/*
 * An object-ref modifier is a modifier whose role is solely to allocate
 * an object and insert it into an objref channel. This includes falloffs,
 * deformations, and mesh influences. The latter case can require a more
 * complex class since this doesn't allow for caching.
 *
 * The client subclasses the "core" class, implementing the required virtual
 * methods.
 */
class CLxObjectRefModifierCore :
                public CLxItemModifierElement
{
    public:
        /*
         * Return the name of the item type with the channel to set, and the
         * name of the channel.
         */
        virtual const char *	ItemType () = 0;
        virtual const char *	Channel () = 0;

        virtual const char *	GraphNames () { return 0; }

        /*
         * Attach to the eval context. Just add channels for read.
         */
        virtual void		Attach (CLxUser_Evaluation &, ILxUnknownID) = 0;

        /*
         * Allocate the sub-object. The access interfaces and the starting index
         * are provided, and the new object is returned indirectly.
         */
        virtual void		Alloc (CLxUser_Evaluation &, CLxUser_Attributes &, unsigned, ILxUnknownID &) = 0;

        void		 Eval (CLxUser_Evaluation &, CLxUser_Attributes &)		LXx_OVERRIDE;
};

/*
 * The actual modifier server is declared as a template. This can all be
 * done with one arcane line in the init function:
 *
 *	initialize ()
 *	{
 *		CLxExport_ItemModifierServer<CLxObjectRefModifier<CMyCore> > ("myModifierServer");
 *	}
 */
template <class T>
class CLxObjectRefModifier :
                public CLxItemModifierServer
{
    public:
                const char *
        ItemType ()
        {
                T			 tmp;

                return tmp.ItemType ();
        }

                const char *
        GraphNames ()
        {
                T			 tmp;

                return tmp.GraphNames ();
        }

                CLxItemModifierElement *
        Alloc (
                CLxUser_Evaluation	&eval,
                ILxUnknownID		 item)
        {
                T			*elt;

                elt = new T;
                eval.AddChan (item, elt->Channel (), LXfECHAN_WRITE);

                elt->Attach (eval, item);
                return elt;
        }
};

//@read

/*
 * The render camera utility class is used for getting the list of potential render cameras
 * (and the current one) from the scene and eval. 
 */
class CLxRenderCamera
{
        public:
                CLxRenderCamera (CLxUser_Scene &scene)
                {
                        scene.get ((void **) &(this->sceneObj));
                }

                void				Camera		(CLxUser_Evaluation &, CLxUser_Item &);

                void				BuildList	(void);
                bool				ListIsValid	(void);
                unsigned			AttachIndexChan	(CLxUser_Evaluation &);
                int				Camera		(CLxUser_Attributes &);
                size_t				size		(void);
                ILxUnknownID&			operator[]	(const int);		
        private:
                ILxUnknownID			sceneObj;
                unsigned			chanIndex;
                std::vector<ILxUnknownID>	cameraList;
};

#endif // LXU_MODIFIER_HPP

