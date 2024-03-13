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
 * Dynamic Attributes
 */
#include <lxu_attrdesc.hpp>
#include <lx_tableau.hpp>
#include <lx_chanmod.hpp>

#include <stdio.h>

using namespace lx_err;


/*
 * AttributeDesc is mostly implemented by the private class.
 */
class pv_AttributeDesc
{
    public:
        static const int		 TYP_NONE	= 0;
        static const int		 TYP_INT	= 1;
        static const int		 TYP_BOOL	= 2;
        static const int		 TYP_DOUBLE	= 3;
        static const int		 TYP_STRING	= 4;
        static const int		 TYP_VECTOR	= 5;
        static const int		 TYP_OBJECT	= 6;

        static const int		 CHMOD_VALUE	= 0;
        static const int		 CHMOD_ARRAY	= 1;
        static const int		 CHMOD_MATRIX	= 2;
        static const int		 CHMOD_TIME	= 3;

        class cDep
        {
            public:
                std::string	 chan, type;
                bool		 local;
        };

        class cRange
        {
            public:
                double		 fval;
                int		 ival;
                bool		 exist, clamp, isint;
        };

        /*
         * Attr objects define the values in the attribute list. They
         * are required to have a name and type, and also have a bunch
         * of other optional attributes.
         */
        class Attr :
                        public CLxObject
        {
            public:
                Attr			*next, *prev;
                std::string		 name, type;
                unsigned		 index;
                bool			 is_channel;
                bool			 is_storage;

                const char		*vec_type;
                LXtTextValueHint	*text_hint;
                unsigned		 arg_flag;
                int			 vec_N;
                int			 bool_type;

                int			 def_type;
                double			 def_f;
                int			 def_i;
                std::string		 def_str;
                CLxArray<double>	 def_vec;

                bool			 eval_ok;
                unsigned		 eval_flag;
                unsigned		 eval_idx;

                int			 st_type;
                int			 st_offset;
                bool			 st_hasset;
                int			 st_isset;

                bool			 chmod_ok;
                int			 chmod_flags;
                int			 chmod_type;

                bool			 node_ok;
                unsigned		 node_chan;

                std::vector<cDep>	 chan_deps;
                CLxCustomChannelUI	*chan_ui;
                CLxCustomArgumentUI	*arg_ui;
                CLxDynamicUIValue	*ui_val;
                cRange			 r_min, r_max;
                unsigned		 chan_flags;

                ~Attr ()
                {
                        if (chan_ui)
                                delete chan_ui;

                        if (arg_ui)
                                delete arg_ui;

                        if (ui_val)
                                delete ui_val;
                }

                /*
                 * For vector attributes get the name of the sub-attribute
                 * by index.
                 */
                        void
                vec_channel (
                        std::string		&full,
                        int			 i)
                {
                        full = name;
                        full += ".";
                        full += vec_type[i];
                }

                /*
                 * Template methods to set, get and compare elements of the
                 * structure by offset.
                 */
                        template <class T>
                        void
                p_set (
                        void			*ptr,
                        const T			&value,
                        int			 index = 0)
                {
                        char *base = reinterpret_cast<char *> (ptr);
                        T *dest = reinterpret_cast<T *> (base + st_offset);
                        dest[index] = value;
                }

                        void
                p_set (
                        void			*ptr,
                        ILxUnknownID		 value)
                {
                        char *base = reinterpret_cast<char *> (ptr);
                        CLxLocalizedObject *dest = reinterpret_cast<CLxLocalizedObject *> (base + st_offset);
                        dest->take (value);
                }

                        template <class T>
                        void
                p_get (
                        void			*ptr,
                        T			&value,
                        int			 index = 0)
                {
                        char *base = reinterpret_cast<char *> (ptr);
                        const T *src = reinterpret_cast<T *> (base + st_offset);
                        value = src[index];
                }

                        template <class T>
                        int
                p_comp (
                        void			*p1,
                        void			*p2,
                        int			 index = 0)
                {
                        T			 t1, t2;

                        p_get (p1, t1, index);
                        p_get (p2, t2, index);
                        return (t1 > t2) - (t2 > t1);
                }

                        double
                clamp_range (
                        double			 val)
                {
                        if (r_min.clamp)
                                val = LXxMAX (r_min.fval, val);

                        if (r_max.clamp)
                                val = LXxMIN (r_max.fval, val);

                        return val;
                }

                        int
                clamp_range (
                        int			 val)
                {
                        if (r_min.clamp)
                                val = LXxMAX (r_min.ival, val);

                        if (r_max.clamp)
                                val = LXxMIN (r_max.ival, val);

                        return val;
                }

                        void
                range_hints (
                        CLxUser_UIHints		&hint)
                {
                        if (r_min.exist)
                        {
                                if (r_min.isint)
                                        hint.MinInt (r_min.ival);
                                else
                                        hint.MinFloat (r_min.fval);
                        }

                        if (r_max.exist)
                        {
                                if (r_max.isint)
                                        hint.MaxInt (r_max.ival);
                                else
                                        hint.MaxFloat (r_max.fval);
                        }
                }
        };

        CLxObjectList<Attr>		 list;
        unsigned			 count;
        Attr				*cur;
        bool				 chanUI;

        pv_AttributeDesc ()
        {
                count  = 0;
                cur    = 0;
                chanUI = false;
        }

        /*
         * Add default attribute with nothing optional.
         */
                void
        add (
                const char		*name,
                const char		*type)
        {
                cur = list.AllocTail ();
                cur->name  = name;
                cur->type  = type;
                cur->index = count++;

                cur->is_channel = true;
                cur->is_storage = false;
                cur->vec_type   = 0;
                cur->vec_N      = 0;
                cur->text_hint  = 0;
                cur->arg_flag   = 0;
                cur->def_type   = TYP_NONE;
                cur->st_type    = TYP_NONE;
                cur->st_hasset  = false;
                cur->eval_ok    = false;
                cur->chmod_ok   = false;
                cur->chan_ui    = 0;
                cur->arg_ui     = 0;
                cur->ui_val     = 0;

                cur->r_min.exist = false;
                cur->r_min.clamp = false;
                cur->r_max.exist = false;
                cur->r_max.clamp = false;
                cur->chan_flags  = 0;
        }

        /*
         * Lookup attribute record by internal index. (We could use a vector
         * for this).
         */
                Attr *
        lookup (
                unsigned		 index,
                LxResult		 err = LXe_OUTOFBOUNDS)
        {
                Attr			*at;

                for (at = list.first; at; at = at->next)
                        if (at->index == index)
                                return at;

                throw (err);
        }

        /*
         * Lookup attribute record by name. Vector types need to have the
         * suffix stripped. If we fail to find it in the first pass we make
         * a more generous second pass that will match anything that can.
         */
                Attr *
        lookup (
                const char		*name,
                LxResult		 err = LXe_OUTOFBOUNDS)
        {
                Attr			*at;
                std::string		 sub;
                int			 len;
                bool			 isvec = false;

                len = strlen (name);
                if (len > 2 && name[len - 2] == '.')
                {
                        isvec = true;
                        sub = std::string(name).substr(0, len - 2);
                        name = sub.c_str();
                }

                for (at = list.first; at; at = at->next)
                        if (at->name.compare (name) == 0 && (at->vec_type != 0) == isvec)
                                return at;

                for (at = list.first; at; at = at->next)
                        if (at->name.compare (name) == 0)
                                return at;

                throw (err);
        }

        /*
         * Get name by index or index by name.
         */
                const char *
        by_index (
                unsigned		 index)
        {
                Attr			*at;

                at = lookup (index);
                return at->name.c_str();
        }

                unsigned
        by_name (
                const char		*name)
        {
                Attr			*at;

                at = lookup (name);
                return at->index;
        }

        /*
         * Convert internal attrs to calls into the AddChannel interface.
         */
                LxResult
        setup_channels (
                ILxUnknownID		 addchan)
        {
                CLxUser_AddChannel	 ac (addchan);
                CLxUser_Value		 val;
                Attr			*at;

                for (at = list.first; at; at = at->next)
                {
                        if (!at->is_channel)
                                continue;

                        ac.NewChannel (at->name.c_str(), at->type.c_str());

                        if (at->vec_type)
                                ac.SetVector (at->vec_type);

                        if (at->text_hint)
                                ac.SetHint (at->text_hint);

                        if (at->def_type == TYP_DOUBLE || at->def_type == TYP_INT || at->def_type == TYP_BOOL)
                                ac.SetDefault (at->def_f, at->def_i);

                        else if (at->def_type == TYP_VECTOR)
                                ac.SetDefaultVec (at->def_vec.array);

                        else if (at->def_type == TYP_STRING)
                        {
                                ac.SetStorage (at->type.c_str());
                                ac.SetDefaultObj (val);
                                val.SetString (at->def_str.c_str());

                        } else if (at->chmod_ok && at->type == LXsTYPE_MATRIX4)
                                ac.SetStorage (at->type.c_str());

                        else if (at->is_storage)
                                ac.SetStorage (at->type.c_str());
                }

                return LXe_OK;
        }

        /*
         * Add eval channels to evaluation. We break open the vector channels
         * into individual values. Return result is the first index.
         */
                unsigned
        eval_attach (
                CLxUser_Evaluation	&eval,
                ILxUnknownID		 item)
        {
                Attr			*at;
                unsigned		 k, r, idx;

                k   = 0;
                idx = 0;
                for (at = list.first; at; at = at->next)
                {
                        if (!at->eval_ok)
                                continue;

                        at->eval_idx = k;

                        if (!at->is_channel)
                        {
                                r = eval.AddTime ();
                                if (k == 0)
                                        idx = r;

                                k ++;

                        } else if (at->vec_type)
                        {
                                std::string	 name;
                                unsigned	 i;

                                for (i = 0; i < at->vec_N; i++)
                                {
                                        at->vec_channel (name, i);
                                        r = eval.AddChan (item, name.c_str(), at->eval_flag);
                                        if (k == 0 && i == 0)
                                                idx = r;
                                }
                                k += at->vec_N;
                        } else
                        {
                                r = eval.AddChan (item, at->name.c_str(), at->eval_flag);
                                if (k == 0)
                                        idx = r;

                                k ++;
                        }
                }

                return idx;
        }

        /*
         * Read eval channels from attributes. Reverse of above.
         */
                void
        eval_read (
                CLxUser_Attributes	&attr,
                unsigned		 index,
                void			*ptr)
        {
                Attr			*at;

                for (at = list.first; at; at = at->next)
                {
                        if (!at->eval_ok || !(at->eval_flag & LXfECHAN_READ))
                                continue;

                        if (at->st_type == TYP_INT)
                        {
                                int v = attr.Int (index + at->eval_idx);
                                at->p_set (ptr, at->clamp_range (v));

                        } else if (at->st_type == TYP_BOOL)
                        {
                                bool v = attr.Bool (index + at->eval_idx);
                                at->p_set (ptr, !!v);

                        } else if (at->st_type == TYP_DOUBLE)
                        {
                                double v = attr.Float (index + at->eval_idx);
                                at->p_set (ptr, at->clamp_range (v));

                        } else if (at->st_type == TYP_STRING)
                        {
                                std::string	 stmp;
                                attr.String (index + at->eval_idx, stmp);
                                at->p_set (ptr, stmp);

                        } else if (at->st_type == TYP_OBJECT)
                        {
                                ILxUnknownID	 obj;
                                attr.Value (index + at->eval_idx, (void **) &obj, 0);
                                at->p_set (ptr, obj);

                        } else if (at->st_type == TYP_VECTOR)
                        {
                                int	 i;

                                for (i = 0; i < at->vec_N; i++)
                                {
                                        double v = attr.Float (index + at->eval_idx + i);
                                        at->p_set (ptr, at->clamp_range (v), i);
                                }
                        }
                }
        }

        /*
         * Read from ChannelRead object. All types are supported here.
         */
                void
        chan_read (
                CLxUser_ChannelRead	&read,
                CLxUser_Item		&item,
                void			*ptr)
        {
                Attr			*at;

                for (at = list.first; at; at = at->next)
                {
                        if (!at->is_channel)
                                continue;

                        if (at->st_type == TYP_INT)
                        {
                                int v = read.IValue (item, at->name.c_str());
                                at->p_set (ptr, at->clamp_range (v));

                        } else if (at->st_type == TYP_DOUBLE)
                        {
                                double v = read.FValue (item, at->name.c_str());
                                at->p_set (ptr, at->clamp_range (v));

                        } else if (at->st_type == TYP_BOOL)
                        {
                                bool btmp = read.IValue (item, at->name.c_str());
                                at->p_set (ptr, !!btmp);

                        } else if (at->st_type == TYP_STRING)
                        {
                                std::string stmp;
                                read.GetString (item, at->name.c_str(), stmp);
                                at->p_set (ptr, stmp);

                        } else if (at->st_type == TYP_OBJECT)
                        {
                                ILxUnknownID obj;
                                int idx = item.ChannelIndex (at->name.c_str());
                                read.ValueObj (item, idx, (void **) &obj);
                                at->p_set (ptr, obj);

                        } else if (at->st_type == TYP_VECTOR)
                        {
                                std::string	 name;
                                int		 i, base;

                                at->vec_channel (name, 0);
                                base = item.ChannelIndex (name.c_str());
                                for (i = 0; i < at->vec_N; i++)
                                {
                                        double v = read.FValue (item, base + i);
                                        at->p_set (ptr, at->clamp_range (v), i);
                                }
                        }
                }
        }

        /*
         * Add the channels as channel modifier inputs and outputs.
         */
                void
        chanmod_define (
                CLxUser_ChannelModSetup	&setup)
        {
                Attr			*at;

                for (at = list.first; at; at = at->next)
                {
                        if (!at->chmod_ok)
                                continue;

                        if (at->chmod_type == CHMOD_TIME)
                        {
                                check (setup.AddTime ());

                        } else if (at->vec_type)
                        {
                                std::string	 name;

                                for (int i = 0; i < at->vec_N; i++)
                                {
                                        at->vec_channel (name, i);
                                        check (setup.AddChannel (name.c_str(), at->chmod_flags));
                                }
                        } else
                        {
                                check (setup.AddChannel (at->name.c_str(), at->chmod_flags));
                        }
                }
        }

        /*
         * Bind channel modifier channels to values in the operator.
         */
                void
        chanmod_bind (
                CLxUser_ChannelModSetup	&setup,
                void			*ptr)
        {
                char			*base = reinterpret_cast<char *> (ptr);
                void			*dest;
                CLxUser_Value		*pvalue;
                CLxUser_Matrix		*pmat;
                CLxUser_ValueArray	*parray;
                Attr			*at;

                for (at = list.first; at; at = at->next)
                {
                        if (!at->chmod_ok)
                                continue;

                        dest = (void *) (base + at->st_offset);

                        if (at->chmod_type == CHMOD_TIME)
                        {
                                pvalue = reinterpret_cast<CLxUser_Value *> (dest);
                                check (setup.ReadTimeValue (*pvalue));

                        } else if (at->chmod_type == CHMOD_ARRAY)
                        {
                                parray = reinterpret_cast<CLxUser_ValueArray *> (dest);
                                check (setup.ReadArray (at->name.c_str(), *parray));

                        } else if (at->chmod_type == CHMOD_MATRIX)
                        {
                                pmat = reinterpret_cast<CLxUser_Matrix *> (dest);
                                if (at->chmod_flags & LXfCHMOD_OUTPUT)
                                        check (setup.WriteValue (at->name.c_str(), *pmat));
                                else
                                        check (setup.ReadValue (at->name.c_str(), *pmat));

                        } else if (at->vec_type)
                        {
                                std::string	 name;

                                pvalue = reinterpret_cast<CLxUser_Value *> (dest);
                                for (int i = 0; i < at->vec_N; i++)
                                {
                                        at->vec_channel (name, i);
                                        if (at->chmod_flags & LXfCHMOD_OUTPUT)
                                                check (setup.WriteValue (name.c_str(), pvalue[i]));
                                        else
                                                check (setup.ReadValue (name.c_str(), pvalue[i]));
                                }
                        } else
                        {
                                pvalue = reinterpret_cast<CLxUser_Value *> (dest);
                                if (at->chmod_flags & LXfCHMOD_OUTPUT)
                                        check (setup.WriteValue (at->name.c_str(), *pvalue));
                                else
                                        check (setup.ReadValue (at->name.c_str(), *pvalue));
                        }
                }
        }

        /*
         * Convert list of attributes to CLxDynamicArguments initialization.
         */
                void
        setup_args (
                CLxDynamicArguments	&cmd)
        {
                Attr			*at;

                for (at = list.first; at; at = at->next)
                {
                        cmd.dyna_Add (at->name.c_str(), at->type.c_str());
                        if (at->text_hint)
                                cmd.dyna_SetHint (at->index, at->text_hint);

                        cmd.dyna_SetFlags (at->index, at->arg_flag);
                }
        }

        /*
         * Read argument values from a CLxBasicCommand with defaults if unset.
         */
                void
        read_args (
                CLxDynamicAttributes	&cmd,
                void			*ptr)
        {
                Attr			*at;

                for (at = list.first; at; at = at->next)
                {
                        if (at->st_type == TYP_INT)
                        {
                                int d = (at->def_type == TYP_INT ? at->def_i : 0);
                                int v = cmd.dyna_Int (at->index, d);
                                at->p_set (ptr, at->clamp_range (v));

                        } else if (at->st_type == TYP_BOOL)
                        {
                                bool d = (at->def_type == TYP_BOOL ? at->def_i : 0) != 0;
                                at->p_set (ptr, !!cmd.dyna_Bool (at->index, d));

                        } else if (at->st_type == TYP_DOUBLE)
                        {
                                double d = (at->def_type == TYP_DOUBLE ? at->def_f : 0.0);
                                double v = cmd.dyna_Float (at->index, d);
                                at->p_set (ptr, at->clamp_range (v));

                        } else if (at->st_type == TYP_STRING)
                        {
                                std::string v;
                                if (at->def_type == TYP_STRING)
                                        cmd.dyna_String (at->index, v, at->def_str.c_str());
                                else
                                        cmd.dyna_String (at->index, v);

                                at->p_set (ptr, v);

                        } else if (at->st_type == TYP_OBJECT)
                        {
                                ILxUnknownID obj;
                                cmd.attr_Value (at->index, (void **) &obj, 0);
                                at->p_set (ptr, obj);
                        }
                }
        }

        /*
         * Read argument set state into isset bool members.
         */
                void
        read_args_isset (
                CLxDynamicAttributes	&cmd,
                void			*ptr)
        {
                char			*base = reinterpret_cast<char *> (ptr);
                Attr			*at;

                for (at = list.first; at; at = at->next)
                {
                        if (!at->st_hasset)
                                continue;

                        bool *dest = reinterpret_cast<bool *> (base + at->st_isset);
                        dest[0] = cmd.dyna_IsSet (at->index);
                }
        }

        /*
         * Init a dialog with default argument values.
         */
                void
        dialog_init (
                CLxDynamicAttributes	&cmd)
        {
                Attr			*at;

                for (at = list.first; at; at = at->next)
                {
                        if (cmd.dyna_IsSet (at->index))
                                continue;
                                
                        if (at->def_type == TYP_DOUBLE)
                                cmd.attr_SetFlt (at->index, at->def_f);

                        else if (at->def_type == TYP_INT || at->def_type == TYP_BOOL)
                                cmd.attr_SetInt (at->index, at->def_i);

                        else if (at->def_type == TYP_STRING)
                                cmd.attr_SetString (at->index, at->def_str.c_str());
                }
        }

        /*
         * Compare all elements of a struct, returning the first non-zero.
         */
                int
        struct_compare (
                void			*p1,
                void			*p2)
        {
                Attr			*at;
                int			 k = 0;

                for (at = list.first; at; at = at->next)
                {
                        if (at->st_type == TYP_NONE)
                                continue;

                        if (at->st_type == TYP_INT)
                                k = at->p_comp<int> (p1, p2);

                        else if (at->st_type == TYP_DOUBLE)
                                k = at->p_comp<double> (p1, p2);

                        else if (at->st_type == TYP_BOOL)
                                k = at->p_comp<bool> (p1, p2);

                        else if (at->st_type == TYP_STRING)
                                k = at->p_comp<std::string> (p1, p2);

                        else if (at->st_type == TYP_VECTOR)
                        {
                                int		 i, k;

                                for (i = 0; i < at->vec_N; i++)
                                {
                                        k = at->p_comp<double> (p1, p2, i);
                                        if (k)
                                                break;
                                }
                        }

                        if (k)
                                break;
                }

                return k;
        }

        CLxUser_NodalService		 nodal_service;

        /*
         * Add nodal channels as sample inputs. Sets 'node_chan' for
         * subsequent methods.
         */
                void
        nodal_link (
                ILxUnknownID		 eval,
                ILxUnknownID		 item,
                int			*idx)
        {
                CLxUser_Item		 it (item);
                Attr			*at;

                nodal_service.set ();

                for (at = list.first; at; at = at->next)
                {
                        if (!at->node_ok)
                                continue;

                        if (at->vec_type)
                        {
                                std::string	 name;
                                unsigned	 i;

                                for (i = 0; i < at->vec_N; i++)
                                {
                                        at->vec_channel (name, i);
                                        if (i == 0)
                                                at->node_chan = it.ChannelIndex (name.c_str());

                                        nodal_service.AddSampleChan (eval, item, at->node_chan + i, idx, LXfECHAN_READ);
                                }
                        } else
                        {
                                at->node_chan = it.ChannelIndex (at->name.c_str());
                                nodal_service.AddSampleChan (eval, item, at->node_chan, idx, LXfECHAN_READ);
                        }

                }
        }

        /*
         * Return true if any channels are driven.
         */
                bool
        nodal_driven (
                int			*idx)
        {
                Attr			*at;
                int			 i, n;

                for (at = list.first; at; at = at->next)
                {
                        if (!at->node_ok)
                                continue;

                        if (at->vec_type)
                                n = at->vec_N;
                        else
                                n = 1;

                        for (i = 0; i < n; i++)
                                if (idx[at->node_chan + i] != LXiNODAL_NOT_DRIVEN)
                                        return true;
                }

                return false;
        }

        /*
         * Read any nodally-driven channels. Non-driven values will come from
         * 'fixed' struct.
         */
                void
        nodal_read (
                ILxUnknownID		 etor,
                int			*idx,
                void			*dest,
                void			*fixed)
        {
                Attr			*at;

                for (at = list.first; at; at = at->next)
                {
                        if (!at->node_ok)
                                continue;

                        if (at->st_type == TYP_INT)
                        {
                                int v, d;
                                at->p_get (fixed, d);
                                v = nodal_service.GetInt (etor, idx, at->node_chan, d);
                                at->p_set (dest, at->clamp_range (v));

                        } else if (at->st_type == TYP_DOUBLE)
                        {
                                double v, d;
                                at->p_get (fixed, d);
                                v = nodal_service.GetFloat (etor, idx, at->node_chan, d);
                                at->p_set (dest, at->clamp_range (v));

                        } else if (at->st_type == TYP_BOOL)
                        {
                                bool b;
                                int v, d;
                                at->p_get (fixed, b);
                                d = (b ? 1 : 0);
                                v = nodal_service.GetInt (etor, idx, at->node_chan, d);
                                at->p_set (dest, (v != 0));

                        } else if (at->st_type == TYP_VECTOR)
                        {
                                double		 v, d;
                                int		 i;

                                for (i = 0; i < at->vec_N; i++)
                                {
                                        at->p_get (fixed, d, i);
                                        v = nodal_service.GetFloat (etor, idx, at->node_chan + i, d);
                                        at->p_set (dest, at->clamp_range (v), i);
                                }
                        }
                }
        }

        /*
         * Get a string from any attribute.
         */
                bool
        to_string (
                std::string		&result,
                Attr			*at,
                void			*ptr)
        {
                if (at->st_type == TYP_STRING)
                {
                        at->p_get (ptr, result);
                        return true;
                }

                char buf[64];

                if (at->st_type == TYP_INT)
                {
                        int v;
                        at->p_get (ptr, v);
                        sprintf (buf, "%d", v);
                        result = buf;

                } else if (at->st_type == TYP_DOUBLE)
                {
                        double v;
                        at->p_get (ptr, v);
                        sprintf (buf, "%g", v);
                        result = buf;

                } else if (at->st_type == TYP_BOOL)
                {
                        bool v;
                        at->p_get (ptr, v);
                        if (at->bool_type == CLxAttributeDesc::BOOL_CHECKMARK)
                                result = (v ? "\03(i:MIMG_CHECKMARK)" : "");
                        else if (at->bool_type == CLxAttributeDesc::BOOL_EYEBALL)
                                result = (v ? "\03(i:uiicon_visible_item,33554431)" : "");
                        else
                                result = (v ? "true" : "false");

                } else
                        return false;

                return true;
        }
};


/*
 * The public class creates the private one and passes many of the methods
 * directly through. Most of the variable-type methods are handled here.
 */
CLxAttributeDesc::CLxAttributeDesc ()
{
        pv = new pv_AttributeDesc;
}

CLxAttributeDesc::~CLxAttributeDesc ()
{
        delete pv;
}

/*
 * Set features of the current attr.
 */
        void
CLxAttributeDesc::add (
        const char		*name,
        const char		*type)
{
        pv->add (name, type);
}

        void
CLxAttributeDesc::vector_type (
        const char		*vtype)
{
        pv->cur->vec_type = vtype;
        pv->cur->vec_N    = (int)strlen (vtype);
}

        void
CLxAttributeDesc::default_val (
        double			 value)
{
        pv->cur->def_type = pv_AttributeDesc::TYP_DOUBLE;
        pv->cur->def_f    = value;
}

        void
CLxAttributeDesc::default_val (
        int			 value)
{
        pv->cur->def_type = pv_AttributeDesc::TYP_INT;
        pv->cur->def_i    = value;
}

        void
CLxAttributeDesc::default_val (
        bool			 value)
{
        pv->cur->def_type = pv_AttributeDesc::TYP_BOOL;
        pv->cur->def_i    = (value ? 1 : 0);
}

        void
CLxAttributeDesc::default_val (
        const char		*value)
{
        pv->cur->def_type = pv_AttributeDesc::TYP_STRING;
        pv->cur->def_str  = value;
}

        void
CLxAttributeDesc::default_val (
        std::string		&value)
{
        pv->cur->def_type = pv_AttributeDesc::TYP_STRING;
        pv->cur->def_str  = value;
}

        void
CLxAttributeDesc::default_val (
        double			*value)
{
        pv_AttributeDesc::Attr	*at = pv->cur;
        int			 i, n;

        at->def_type = pv_AttributeDesc::TYP_VECTOR;

        n = sizeof (at->vec_type);
        at->def_vec.Alloc (n);
        for (i = 0; i < n; i++)
                at->def_vec[i] = value[i];
}

        void
CLxAttributeDesc::struct_offset (
        double			*value)
{
        pv->cur->st_type   = pv_AttributeDesc::TYP_DOUBLE;
        pv->cur->st_offset = int (size_t (value));
}

        void
CLxAttributeDesc::struct_offset (
        int			*value)
{
        pv->cur->st_type   = pv_AttributeDesc::TYP_INT;
        pv->cur->st_offset = int (size_t (value));
}

        void
CLxAttributeDesc::struct_offset (
        bool			*value)
{
        pv->cur->st_type   = pv_AttributeDesc::TYP_BOOL;
        pv->cur->st_offset = int (size_t (value));
}

        void
CLxAttributeDesc::struct_offset (
        std::string		*value)
{
        pv->cur->st_type   = pv_AttributeDesc::TYP_STRING;
        pv->cur->st_offset = int (size_t (value));
}

        void
CLxAttributeDesc::struct_offset (
        double		       **value)
{
        pv->cur->st_type   = pv_AttributeDesc::TYP_VECTOR;
        pv->cur->st_offset = int (size_t (value));
}

        void
CLxAttributeDesc::struct_offset (
        LXtVector		*value)
{
        struct_offset ((double **) value);
}

        void
CLxAttributeDesc::struct_offset (
        CLxLocalizedObject	*value)
{
        pv->cur->st_type   = pv_AttributeDesc::TYP_OBJECT;
        pv->cur->st_offset = int (size_t (value));
}

        void
CLxAttributeDesc::isset_offset (
        bool			*value)
{
        pv->cur->st_hasset = true;
        pv->cur->st_isset  = int (size_t (value));
}

        void
CLxAttributeDesc::chanmod_chan (
        int			 flags,
        CLxUser_Value		*value)
{
        pv->cur->chmod_ok    = true;
        pv->cur->chmod_flags = flags & ~LXfCHMOD_MULTILINK;
        pv->cur->chmod_type  = pv_AttributeDesc::CHMOD_VALUE;
        pv->cur->st_offset   = int (size_t (value));
}

        void
CLxAttributeDesc::chanmod_chan (
        int			 flags,
        CLxUser_Value	       **value)
{
        pv->cur->chmod_ok    = true;
        pv->cur->chmod_flags = flags & ~LXfCHMOD_MULTILINK;
        pv->cur->chmod_type  = pv_AttributeDesc::CHMOD_VALUE;
        pv->cur->st_offset   = int (size_t (value));
}

        void
CLxAttributeDesc::chanmod_chan (
        int			 flags,
        CLxUser_Matrix		*value)
{
        pv->cur->chmod_ok    = true;
        pv->cur->chmod_flags = flags & ~LXfCHMOD_MULTILINK;
        pv->cur->chmod_type  = pv_AttributeDesc::CHMOD_MATRIX;
        pv->cur->st_offset   = int (size_t (value));
}

        void
CLxAttributeDesc::chanmod_chan (
        int			 flags,
        CLxUser_ValueArray	*value)
{
        pv->cur->chmod_ok    = true;
        pv->cur->chmod_flags = flags | LXfCHMOD_MULTILINK;
        pv->cur->chmod_type  = pv_AttributeDesc::CHMOD_ARRAY;
        pv->cur->st_offset   = int (size_t (value));
}

        void
CLxAttributeDesc::chanmod_time (
        CLxUser_Value		*value)
{
        pv->add ("-time-", "time");

        pv->cur->is_channel = false;
        pv->cur->chmod_ok   = true;
        pv->cur->chmod_type = pv_AttributeDesc::CHMOD_TIME;
        pv->cur->st_offset  = int (size_t (value));
}

        void
CLxAttributeDesc::eval_flag (
        unsigned		 flag)
{
        pv->cur->eval_ok   = true;
        pv->cur->eval_flag = flag;
}

        void
CLxAttributeDesc::eval_time (
        double			*value)
{
        pv->add ("-time-", "time");

        pv->cur->is_channel = false;
        pv->cur->eval_ok    = true;
        pv->cur->eval_flag  = LXfECHAN_READ;

        pv->cur->st_type    = pv_AttributeDesc::TYP_DOUBLE;
        pv->cur->st_offset  = int (size_t (value));
}

        void
CLxAttributeDesc::arg_flag (
        unsigned		 flag)
{
        pv->cur->arg_flag = flag;
}

        void
CLxAttributeDesc::set_hint (
        LXtTextValueHint	*hint)
{
        pv->cur->text_hint = hint;
}

        void
CLxAttributeDesc::nodal_input ()
{
        pv->cur->node_ok = true;
}

        void
CLxAttributeDesc::bool_type (
        int			 type)
{
        pv->cur->bool_type = type;
}

        void
CLxAttributeDesc::set_storage ()
{
        pv->cur->is_storage = true;
}

        void
CLxAttributeDesc::chan_add_dependency (
        const char		*channel,
        const char		*itemtype)
{
        pv_AttributeDesc::cDep	 proto;

        proto.chan  = channel;
        proto.local = true;

        if (itemtype)
        {
                proto.type  = itemtype;
                proto.local = false;
        }

        pv->cur->chan_deps.push_back (proto);
        pv->chanUI = true;
}

        void
CLxAttributeDesc::chan_set_custom (
        CLxCustomChannelUI	*ui)
{
        pv->cur->chan_ui = ui;
        ui->channel = pv->cur->name.c_str();
        pv->chanUI = true;
}

        void
CLxAttributeDesc::arg_set_custom (
        CLxCustomArgumentUI	*ui)
{
        pv->cur->arg_ui = ui;
}

        void
CLxAttributeDesc::chan_flags (
        unsigned		 flags)
{
        pv->cur->chan_flags = flags;
        pv->chanUI = true;
}

        void
CLxAttributeDesc::set_uivalue (
        CLxDynamicUIValue	*uival)
{
        pv->cur->ui_val = uival;
        pv->chanUI = true;
}

        void
CLxAttributeDesc::set_min (
        int			 val,
        bool			 clamp)
{
        pv->cur->r_min.ival  = val;
        pv->cur->r_min.exist = true;
        pv->cur->r_min.clamp = clamp;
        pv->cur->r_min.isint = true;
        pv->chanUI = true;
}

        void
CLxAttributeDesc::set_max (
        int			 val,
        bool			 clamp)
{
        pv->cur->r_max.ival  = val;
        pv->cur->r_max.exist = true;
        pv->cur->r_max.clamp = clamp;
        pv->cur->r_max.isint = true;
        pv->chanUI = true;
}

        void
CLxAttributeDesc::set_min (
        double			 val,
        bool			 clamp)
{
        pv->cur->r_min.fval  = val;
        pv->cur->r_min.exist = true;
        pv->cur->r_min.clamp = clamp;
        pv->cur->r_min.isint = false;
        pv->chanUI = true;
}

        void
CLxAttributeDesc::set_max (
        double			 val,
        bool			 clamp)
{
        pv->cur->r_max.fval  = val;
        pv->cur->r_max.exist = true;
        pv->cur->r_max.clamp = clamp;
        pv->cur->r_max.isint = false;
        pv->chanUI = true;
}


/*
 * Read out gross features.
 */
        unsigned
CLxAttributeDesc::count ()
{
        return pv->count;
}

        LxResult
CLxAttributeDesc::count (
        unsigned		*intPtr)
{
        intPtr[0] = count ();
        return LXe_OK;
}

        const char *
CLxAttributeDesc::by_index (
        unsigned		 index)
{
        return pv->by_index (index);
}

        unsigned
CLxAttributeDesc::by_name (
        const char		*name)
{
        return pv->by_name (name);
}

        bool
CLxAttributeDesc::need_chan_ui ()
{
        return pv->chanUI;
}

        int
CLxAttributeDesc::struct_compare (
        void			*p1,
        void			*p2)
{
        return pv->struct_compare (p1, p2);
}

/*
 * Perform required boilerplate.
 */
        LxResult
CLxAttributeDesc::setup_channels (
        ILxUnknownID		 addchan)
{
        return pv->setup_channels (addchan);
}

        unsigned
CLxAttributeDesc::eval_attach (
        CLxUser_Evaluation	&eval,
        ILxUnknownID		 item)
{
        return pv->eval_attach (eval, item);
}

        unsigned
CLxAttributeDesc::eval_attach (
        ILxUnknownID		 evalObj,
        ILxUnknownID		 item)
{
        CLxUser_Evaluation	 eval (evalObj);

        return eval_attach (eval, item);
}

        void
CLxAttributeDesc::eval_read (
        CLxUser_Attributes	&attr,
        unsigned		 index,
        void			*ptr)
{
        pv->eval_read (attr, index, ptr);
}

        void
CLxAttributeDesc::eval_read (
        ILxUnknownID		 attrObj,
        unsigned		 index,
        void			*ptr)
{
        CLxUser_Attributes	 attr (attrObj);

        eval_read (attr, index, ptr);
}

        void
CLxAttributeDesc::chan_read (
        CLxUser_ChannelRead	&read,
        CLxUser_Item		&item,
        void			*ptr)
{
        pv->chan_read (read, item, ptr);
}

        void
CLxAttributeDesc::chan_read (
        ILxUnknownID		 chanRead,
        ILxUnknownID		 itemObj,
        void			*ptr)
{
        CLxUser_ChannelRead	 read (chanRead);
        CLxUser_Item		 item (itemObj);

        chan_read (read, item, ptr);
}

        LxResult
CLxAttributeDesc::chanmod_define (
        ILxUnknownID		 cmod)
{
        CLxUser_ChannelModSetup	 setup (cmod);

        pv->chanmod_define (setup);
        return LXe_OK;
}

        void
CLxAttributeDesc::chanmod_bind (
        ILxUnknownID		 cmod,
        void			*ptr)
{
        CLxUser_ChannelModSetup	 setup (cmod);

        pv->chanmod_bind (setup, ptr);
}

        void
CLxAttributeDesc::setup_args (
        CLxDynamicArguments	&cmd)
{
        pv->setup_args (cmd);
}

        void
CLxAttributeDesc::read_args (
        CLxDynamicAttributes	&cmd,
        void			*ptr)
{
        pv->read_args (cmd, ptr);
        pv->read_args_isset (cmd, ptr);
}

        void
CLxAttributeDesc::read_args_isset (
        CLxDynamicAttributes	&cmd,
        void			*ptr)
{
        pv->read_args_isset (cmd, ptr);
}

        LxResult
CLxAttributeDesc::dialog_init (
        CLxDynamicAttributes	&cmd)
{
        pv->dialog_init (cmd);
        return LXe_OK;
}

        const char *
CLxAttributeDesc::arg_get_type (
        unsigned		 index,
        CLxCommand		&inst)
{
        pv_AttributeDesc::Attr	*at = pv->lookup (index);

        if (at->arg_ui)
                return at->arg_ui->type (inst);

        return 0;
}

        bool
CLxAttributeDesc::arg_enabled (
        unsigned		 index,
        CLxCommand		&inst)
{
        pv_AttributeDesc::Attr	*at = pv->lookup (index);

        if (at->arg_ui)
                return at->arg_ui->enabled (inst);

        return true;
}

        void
CLxAttributeDesc::arg_query (
        unsigned		 index,
        CLxCommand		&inst)
{
        pv_AttributeDesc::Attr	*at = pv->lookup (index);

        if (at->arg_ui)
                at->arg_ui->query (inst);
}

        void
CLxAttributeDesc::arg_uihints (
        unsigned		 index,
        CLxUser_UIHints		&hint,
        CLxCommand		&inst)
{
        pv_AttributeDesc::Attr	*at = pv->lookup (index);

        if (at->arg_ui && at->arg_ui->hints (inst, hint))
                return;

        at->range_hints (hint);
}

        CLxDynamicUIValue *
CLxAttributeDesc::arg_uivalue (
        unsigned		 index,
        CLxCommand		&inst)
{
        pv_AttributeDesc::Attr	*at = pv->lookup (index);

        if (at->arg_ui)
                return at->arg_ui->uivalue (inst);

        return 0;
}

        LxResult
CLxAttributeDesc::nodal_link (
        ILxUnknownID		 eval,
        ILxUnknownID		 item,
        int			*idx)
{
        pv->nodal_link (eval, item, idx);
        return LXe_OK;
}

        LxResult
CLxAttributeDesc::nodal_driven (
        int			*idx)
{
        return (pv->nodal_driven (idx) ? LXe_TRUE : LXe_FALSE);
}

        void
CLxAttributeDesc::nodal_read (
        ILxUnknownID		 etor,
        int			*idx,
        void			*dest,
        void			*fixed)
{
        pv->nodal_read (etor, idx, dest, fixed);
}

        LxResult
CLxAttributeDesc::chan_enabled (
        const char		*name,
        ILxUnknownID		 itemObj,
        ILxUnknownID		 chanRead,
        ILxUnknownID		 message)
{
        pv_AttributeDesc::Attr	*at = pv->lookup (name, LXe_NOTIMPL);

        if (!at->chan_ui)
                return LXe_OK;

        CLxUser_Item		 item (itemObj);
        CLxUser_ChannelRead	 read (chanRead);
        CLxUser_Message		 msg (message);

        if (at->chan_ui->enabled (item, read, msg))
                return LXe_OK;

        msg.SetCode (LXe_CMD_DISABLED);
        return LXe_CMD_DISABLED;
}

        int
CLxAttributeDesc::chan_dep_count (
        const char		*name)
{
        pv_AttributeDesc::Attr	*at = pv->lookup (name, LXe_NOTIMPL);

        return at->chan_deps.size ();
}

        void
CLxAttributeDesc::chan_dep_byindex (
        const char		*name,
        unsigned		 index,
        const char	       **chan,
        const char	       **type)
{
        pv_AttributeDesc::Attr	*at = pv->lookup (name, LXe_NOTIMPL);
        pv_AttributeDesc::cDep	&cd = at->chan_deps[index];

        chan[0] = cd.chan.c_str();
        if (cd.local)
                type[0] = 0;
        else
                type[0] = cd.type.c_str();
}

        LxResult
CLxAttributeDesc::chan_uihints (
        const char		*name,
        ILxUnknownID		 hobj)
{
        pv_AttributeDesc::Attr	*at = pv->lookup (name, LXe_NOTIMPL);
        CLxUser_UIHints		 hint (hobj);

        if (at->chan_ui && at->chan_ui->hints (hint))
                return LXe_OK;

        at->range_hints (hint);

        if (at->chan_flags)
                hint.ChannelFlags (at->chan_flags);

        return LXe_OK;
}

        LxResult
CLxAttributeDesc::chan_uivalue (
        const char		*name,
        void		       **ppvObj)
{
        pv_AttributeDesc::Attr	*at = pv->lookup (name, LXe_NOTIMPL);
        CLxDynamicUIValue	*uival = 0;
        bool			 own = true;

        if (at->chan_ui)
                uival = at->chan_ui->uivalue ();

        if (!uival)
        {
                uival = at->ui_val;
                own = false;
        }

        if (!uival)
                return LXe_NOTFOUND;

        lx::UIValueHintsAllocate (uival, ppvObj, own);
        return LXe_OK;
}



/*
 * AttributesFromDesc implements an attributes interface from a description
 * and a value.
 */
CLxAttributesFromDesc::CLxAttributesFromDesc ()
{
        afd_desc = 0;
        afd_data = 0;
}

        unsigned int
CLxAttributesFromDesc::attr_Count ()
{
        return afd_desc->pv->count;
}

        LxResult
CLxAttributesFromDesc::attr_Name (unsigned int index, const char **name)
{
        name[0] = afd_desc->by_index (index);
        return LXe_OK;
}

        LxResult
CLxAttributesFromDesc::attr_Lookup (const char *name, unsigned int *index)
{
        index[0] = afd_desc->by_name (name);
        return LXe_OK; 
}

        LxResult
CLxAttributesFromDesc::attr_Type (unsigned int index, unsigned int *type)
{
        pv_AttributeDesc::Attr *at = afd_desc->pv->lookup (index);
        CLxUser_ValueService val_S;
        return val_S.ValueType (at->type.c_str(), type);
}

        LxResult
CLxAttributesFromDesc::attr_TypeName (unsigned int index, const char **tname)
{
        pv_AttributeDesc::Attr *at = afd_desc->pv->lookup (index);
        tname[0] = at->type.c_str();
        return LXe_OK;
}

        const LXtTextValueHint *
CLxAttributesFromDesc::attr_Hints (unsigned int index)
{
        pv_AttributeDesc::Attr *at = afd_desc->pv->lookup (index);
        return at->text_hint;
}

        LxResult
CLxAttributesFromDesc::attr_Value (unsigned int index, void **ppvObj, int writeOK)
{
        return LXe_NOTIMPL; 
}

        LxResult
CLxAttributesFromDesc::attr_GetInt (unsigned int index, int *val)
{
        pv_AttributeDesc::Attr *at = afd_desc->pv->lookup (index);
        at->p_get (afd_data, *val);
        return LXe_OK;
}

        LxResult
CLxAttributesFromDesc::attr_SetInt (unsigned int index, int val)
{
        pv_AttributeDesc::Attr *at = afd_desc->pv->lookup (index);
        at->p_set (afd_data, at->clamp_range (val));
        value_changed (at->name.c_str());
        return LXe_OK;
}

        LxResult
CLxAttributesFromDesc::attr_GetFlt (unsigned int index, double *val)
{
        pv_AttributeDesc::Attr *at = afd_desc->pv->lookup (index);
        at->p_get (afd_data, *val);
        return LXe_OK;
}

        LxResult
CLxAttributesFromDesc::attr_SetFlt (unsigned int index, double val)
{
        pv_AttributeDesc::Attr *at = afd_desc->pv->lookup (index);
        at->p_set (afd_data, at->clamp_range (val));
        value_changed (at->name.c_str());
        return LXe_OK;
}

        LxResult
CLxAttributesFromDesc::attr_GetString (unsigned int index, char *buf, unsigned len)
{
        pv_AttributeDesc::Attr *at = afd_desc->pv->lookup (index);
        std::string tmp;

        if (afd_desc->pv->to_string (tmp, at, afd_data))
                return lx::StringOut (tmp, buf, len);
        else
                return LXe_NOTFOUND;
}

        LxResult
CLxAttributesFromDesc::attr_SetString (unsigned int index, const char *val)
{
        pv_AttributeDesc::Attr *at = afd_desc->pv->lookup (index);
        std::string tmp = val;
        at->p_set (afd_data, tmp);
        value_changed (at->name.c_str());
        return LXe_OK;
}


