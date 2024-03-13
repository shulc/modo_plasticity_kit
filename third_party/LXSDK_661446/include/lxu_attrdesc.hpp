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
 * Attribute Description
 */
#ifndef LXU_ATTRDESC_HPP
#define LXU_ATTRDESC_HPP

class CLxAttributeDesc;

#include <lx_action.hpp>
#include <lx_package.hpp>
#include <lxu_command.hpp>
#include <lxu_attributes.hpp>
#include <lxu_meta.hpp>
#include <string>


/*
 * The CLxCustomChannelUI class allows channels to be specialized with custom
 * UI behaviors. The client overrides any of the optional methods to disable
 * channels based on other channels, set hints, or compute complex channel state.
 */
class CLxCustomChannelUI :
                public CLxObject
{
    public:
        const char *		 channel;

        /*
         * Implement to return the enable state of an argument based on the
         * state of other channels. A disable message can also be set.
         */
        virtual bool		 enabled (CLxUser_Item &, CLxUser_ChannelRead &, CLxUser_Message &) { return true; }

        /*
         * Implement to set UI hints on the channel. If hints have been supplied
         * this method should return true.
         */
        virtual bool		 hints (CLxUser_UIHints &) { return false; }

        /*
         * Implement to provide an implmentation of UI value hints. A new object
         * should be allocated each time this is called.
         */
        virtual CLxDynamicUIValue *
                                 uivalue () { return 0; }
};


class CLxCommand;

/*
 * The CLxCustomArgumentUI class allows command arguments to be specialized
 * with custom UI behaviors. The client overrides any of the optional methods
 * to disable arguments, query argument values, set the type of variable type
 * arguments, and to set UI hints. The CLxCommand passed as argument is
 * actually an instance of the specific client class, so it can be
 * dynamically cast.
 */
class CLxCustomArgumentUI :
                public CLxObject
{
    public:
        /*
         * Implement to get the query results for an argument. This is
         * done by calling CLxCommand::cmd_arg_query() for all results.
         */
        virtual void		query (CLxCommand &) {}

        /*
         * Implement to return the current type of an argument with
         * variable type
         */
        virtual const char *	type (CLxCommand &) { return 0; }

        /*
         * Implement to return the enable state of an argument. A disable
         * message can also be set on the command itself.
         */
        virtual bool		enabled (CLxCommand &) { return true; }

        /*
         * Implement to set UI hints on the channel. If hints have been supplied
         * this method should return true.
         */
        virtual bool		hints (CLxCommand &, CLxUser_UIHints &) { return false; }

        /*
         * Implement to provide an implmentation of UI value hints. A new object
         * should be allocated each time this is called.
         */
        virtual CLxDynamicUIValue *
                                uivalue (CLxCommand &) { return 0; }
};



/*
 * The attribute description object consists of a list of attributes with
 * a name and type. Attributes can have a set of other optional features.
 * Once defined the attribute description can be used to implement methods
 * on channels or command arguments. The entire set of channels can be
 * read into a structure.
 */
class CLxAttributeDesc
{
    public:
         static const int	 BOOL_TRUEFALSE = 0;
         static const int	 BOOL_CHECKMARK = 1;
         static const int	 BOOL_EYEBALL   = 2;

         CLxAttributeDesc ();
        ~CLxAttributeDesc ();

        /*
         * @sec Defining attributes.
         *
         * Call add() to add a new attribute with a name and type. This becomes
         * the current attribute and further methods can customize the attribute.
         */
        void		add (const char *name, const char *type);

        /*
         * Set the attribute to be a vector, like LXsCHANVEC_RGB or XYZ.
         */
        void		vector_type (const char *vtype);

        /*
         * Set the text hints for encoding int values.
         */
        void		set_hint (LXtTextValueHint *);

        /*
         * (Older version of previous function, not present in Python.)
         */
        void		hint (LXtTextValueHint *h) { set_hint(h); }

        /*
         * Set a channel attribute to be read or written from an associated
         * modifier (LXfECHAN_* flag bits).
         */
        void		eval_flag (unsigned flag);

        /*
         * Set flags for a command argument attribute (LXfCMDARG_* flag bits).
         */
        void		arg_flag (unsigned flag);

        /*
         * Set a channel attribute as a nodal texture input.
         */
        void		nodal_input ();

        /*
         * Set a boolean attribute to display as checkmarks or eyes in trees.
         */
        void		bool_type (int type);

        /*
         * Set unconventional channel types to have stored values.
         */
        void		set_storage ();

        /*
         * Set a default value for an attribute matching its type.
         */
        void		default_val (double value);
        void		default_val (int value);
        void		default_val (bool value);
        void		default_val (const char *value);
        void		default_val (std::string &value);
        void		default_val (double *value);

        /*
         * You can define a struct or class that contains members matching
         * the list of attributes. For each attribute you can call
         * struct_offset() with the address of a member of the struct or
         * class relative to a null pointer to that class. For example:
         *@code
         *	MyAttrStruct *my = 0;
         *	attr.struct_offset (&my->member);
         *@end
         *
         * This allows values to be written directly to the struct.
         */
        void		struct_offset (double *);
        void		struct_offset (int *);
        void		struct_offset (bool *);
        void		struct_offset (std::string *);
        void		struct_offset (double **);
        void		struct_offset (LXtVector *);
        void		struct_offset (CLxLocalizedObject *);
        void		isset_offset (bool *);

        /*
         * Set the channel as an input or output of a channel modifier. The
         * client must provide an offset for an object.
         */
        void		chanmod_chan (int flags, CLxUser_Value *);
        void		chanmod_chan (int flags, CLxUser_Value **);
        void		chanmod_chan (int flags, CLxUser_Matrix *);
        void		chanmod_chan (int flags, CLxUser_ValueArray *);
        void		chanmod_time (CLxUser_Value *);

        /*
         * Add time evaluation for an associated modifier with a destination
         * for the result.
         */
        void		eval_time (double *);

        /*
         * These template functions make quick work of defining the main
         * features of channels or command arguments.
         */
                template <class T>
                void
        add_channel (
                const char		*name,
                const char		*type,
                T			 defVal,
                T			*offset = (T*)(1),
                unsigned		 eval   = 0,
                bool			 nodal  = false)
        {
                add (name, type);
                default_val (defVal);

                if (offset != (T*)(1))
                        struct_offset (offset);

                if (eval)
                        eval_flag (eval);

                if (nodal)
                        nodal_input ();
        }

                template <class T>
                void
        add_argument (
                const char		*name,
                const char		*type,
                unsigned		 flags,
                T			 defVal,
                T			*offset = (T*)(1))
        {
                add (name, type);
                arg_flag (flags);
                default_val (defVal);

                if (offset != (T*)(1))
                        struct_offset (offset);
        }

        /*
         * UI customization. Note that some of these only apply if the
         * attribute is a channel.
         */
        void		chan_add_dependency (const char *channel, const char *itemtype = 0);
        void		chan_set_custom (CLxCustomChannelUI *ui);
        void		arg_set_custom (CLxCustomArgumentUI *ui);
        void		chan_flags (unsigned flags = LXfUIHINTCHAN_SUGGESTED);
        void		set_uivalue (CLxDynamicUIValue *);
        void		set_min (int, bool clamp = true);
        void		set_max (int, bool clamp = true);
        void		set_min (double, bool clamp = true);
        void		set_max (double, bool clamp = true);

        /*
         * Examining attributes.
         */
        unsigned	count ();
        LxResult	count (unsigned *);
        const char *	by_index (unsigned);
        unsigned	by_name (const char *);

        /*
         * Given two structs this method compares them in the sense of
         * strcmp(), returning zero for identical.
         */
        int		struct_compare (void *p1, void *p2);

    //internal:
        bool		need_chan_ui ();

        /*
         * Using attributes as channels.
         *
         * If your attributes are channels, this function can be used for
         * the pkg_SetupChannels() method in your package class.
         */
        LxResult	setup_channels (ILxUnknownID addchan);

        /*
         * If you have set eval flags on your channels, these functions can
         * be used to add the channels to an evaluation, and to read the
         * channels from the corresponding attributes into your struct.
         */
        unsigned	eval_attach (CLxUser_Evaluation &, ILxUnknownID item);
        unsigned	eval_attach (ILxUnknownID eval, ILxUnknownID item);
        void		eval_read (CLxUser_Attributes &, unsigned index, void *ptr);
        void		eval_read (ILxUnknownID attr, unsigned index, void *ptr);

        /*
         * Channels can also be read directly from a channel read interface
         * into your struct.
         */
        void		chan_read (CLxUser_ChannelRead &, CLxUser_Item &, void *ptr);
        void		chan_read (ILxUnknownID chanRead, ILxUnknownID item, void *ptr);

        /*
         * Channel modifiers can be defined and values read into an operator.
         */
        LxResult	chanmod_define (ILxUnknownID cmod);
        void		chanmod_bind (ILxUnknownID cmod, void *ptr);

        /*
         * For nodal texture inputs we can link them, test them, a read them.
         */
        LxResult	nodal_link (ILxUnknownID eval, ILxUnknownID item, int *);
        LxResult	nodal_driven (int *);
        void		nodal_read (ILxUnknownID etor, int *, void *dest, void *fixed);

        /*
         * Get some of the UI properties of channels.
         */
        LxResult	chan_enabled (const char *, ILxUnknownID item, ILxUnknownID chan, ILxUnknownID msg);
        int		chan_dep_count (const char *);
        void		chan_dep_byindex (const char *, unsigned, const char **, const char **);
        LxResult	chan_uihints (const char *, ILxUnknownID);
        LxResult	chan_uivalue (const char *, void **);

        /*
         * Using attributes as command arguments.
         *
         * If your attributes are command arguments, this functions can 
         * be used for setting up a CLxDynamicArguments object.
         */
        void		setup_args (CLxDynamicArguments &);

        /*
         * Arguments values can be read into a structure.
         */
        void		read_args (CLxDynamicAttributes &, void *);
        void		read_args_isset (CLxDynamicAttributes &, void *);

        /*
         * Arguments can be given their default values in cmd_DialogInit().
         */
        LxResult	dialog_init (CLxDynamicAttributes &);

        /*
         * Get the type of a variable type argument.
         */
        const char *	arg_get_type (unsigned, CLxCommand &);

        /*
         * Get the enable state of an argument.
         */
        bool		arg_enabled (unsigned, CLxCommand &);

        /*
         * Query an argument.
         */
        void		arg_query (unsigned, CLxCommand &);

        /*
         * UI hints.
         */
        void		arg_uihints (unsigned, CLxUser_UIHints &, CLxCommand &);
        CLxDynamicUIValue *
                        arg_uivalue (unsigned, CLxCommand &);

        class pv_AttributeDesc	*pv;
};


/*
 * A channel metaclass can be created with a client class with just one
 * method. This will be found automatically by package and modifier metas.
 */
class CLxChannels
{
    public:
        virtual void	init_chan (CLxAttributeDesc &desc) = 0;
};

#define LXsMETA_ATTRDESC	"attrdesc"

template <class T>
class CLxMeta_Channels :
                public CLxMeta
{
    public:
        CLxAttributeDesc	 attr_desc;

        CLxMeta_Channels ()
        {
                m_type = LXsMETA_ATTRDESC;
        }

        void * alloc ()				LXx_OVERRIDE
        {
                if (attr_desc.count () == 0)
                {
                        T tmp;
                        tmp.init_chan (attr_desc);
                }

                return &attr_desc;
        }

              CLxAttributeDesc* operator-> ()		{ return &attr_desc; }
        const CLxAttributeDesc* operator-> () const	{ return &attr_desc; }
};


// ------------ following declaractions are deprecated
//@skip

/*
 * An attribute description can also be used to export an Attribute interface.
 * The client just has to set the pointer to the description and to the data
 * structure holding the current value. The virtual function can be overridden
 * to be informed of changes.
 */
class CLxAttributesFromDesc :
                public CLxImpl_Attributes
{
    public:
        CLxAttributeDesc	*afd_desc;
        void			*afd_data;

        CLxAttributesFromDesc ();

        virtual void		 value_changed (const char *) {}

        LXxO_Attributes_Count;
        LXxO_Attributes_Name;
        LXxO_Attributes_Lookup;
        LXxO_Attributes_Type;
        LXxO_Attributes_TypeName;
        LXxO_Attributes_Hints;
        LXxO_Attributes_Value;
        LXxO_Attributes_GetInt;
        LXxO_Attributes_SetInt;
        LXxO_Attributes_GetFlt;
        LXxO_Attributes_SetFlt;
        LXxO_Attributes_GetString;
        LXxO_Attributes_SetString;
};


#endif /* LX_ATTRDESC_HPP */

