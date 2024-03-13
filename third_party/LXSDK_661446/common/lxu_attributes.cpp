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

/*
 * Disable deprecated function warning.
 */
#pragma warning(disable: 4996)

#include <lxu_attributes.hpp>
#include <lxu_getstring.hpp>
#include <vector>
#include <string>

using namespace std;


/*
 * ----------------------------------------------------------------
 * CLxUIValue class methods to implement a nice CLxDynamicUIValue.
 * State is stored in the private class.
 */
class pv_UIValue
{
    public:
        class opt_string : public std::string
        {
            public:
                const char * get_opt ()
                {
                        if (length ())
                                return c_str();
                        else
                                return 0;
                }
        };

        class popEntry
        {
            public:
                opt_string	 internal, user, tooltip, resrc;
                int		 flags;

                popEntry ()
                {
                        flags = 0;
                }
        };

        std::vector<popEntry>	 pop_list;
        popEntry		*pop_cur;
        opt_string		 category;
        opt_string		 cue_text;
        int			 size_w, size_h;
        bool			 alpha_sort, has_size, filter;

        std::string		 col_rgb, col_alpha, alt_rgb, alt_alpha, col_swap;

        std::vector<std::string> note_cmd;
        std::vector<std::string> note_arg;

        std::vector<std::string> form_cmd;

        pv_UIValue ()
        {
                pop_cur = 0;
                alpha_sort = false;
                has_size = false;
                filter = true;
        }

                unsigned
        col_buf ()
        {
                unsigned a = LXxMAX (col_rgb.length(), col_alpha.length());
                unsigned b = LXxMAX (alt_rgb.length(), alt_alpha.length());
                unsigned c = LXxMAX (a, b);
                return LXxMAX (c, col_swap.length());
        }
};

CLxUIValue::CLxUIValue ()
{
        pv = new pv_UIValue;
}

CLxUIValue::~CLxUIValue ()
{
        delete pv;
}

        void
CLxUIValue::popup_clear ()
{
        pv->pop_list.clear ();
        pv->pop_cur = 0;
}

        void
CLxUIValue::popup_add (
        const char		*value,
        const char		*name,
        const char		*tooltip)
{
        pv_UIValue::popEntry	 proto;

        pv->pop_list.push_back (proto);
        pv->pop_cur = &pv->pop_list.back ();

        if (name)
        {
                pv->pop_cur->internal.assign (value);
                pv->pop_cur->user    .assign (name);
        } else
                pv->pop_cur->user.assign (value);

        if (tooltip)
                pv->pop_cur->tooltip.assign (tooltip);
}

        void
CLxUIValue::popup_flags (
        int			 flags)
{
        pv->pop_cur->flags = flags;
}

        void
CLxUIValue::popup_resource (
        const char		*resrc)
{
        pv->pop_cur->resrc.assign (resrc);
}

        void
CLxUIValue::popup_set_alphasort (
        bool			 state)
{
        pv->alpha_sort = state;
}

        void
CLxUIValue::popup_set_filter (
        bool			 state)
{
        pv->filter = state;
}

        void
CLxUIValue::popup_set_category (
        const char		*cat)
{
        pv->category.assign (cat);
}

        void
CLxUIValue::popup_set_imagesize (
        int			 w,
        int			 h)
{
        pv->size_w = w;
        pv->size_h = h;
        pv->has_size = true;
}

        void
CLxUIValue::color_set (
        const char		*rgb,
        const char		*alpha)
{
        pv->col_rgb   = rgb;
        pv->col_alpha = alpha;
}

        void
CLxUIValue::color_alt (
        const char		*rgb,
        const char		*alpha)
{
        pv->alt_rgb   = rgb;
        pv->alt_alpha = alpha;
}

        void
CLxUIValue::color_swap (
        const char		*swap)
{
        pv->col_swap = swap;
}

        void
CLxUIValue::notify_add (
        const char		*name,
        const char		*arg)
{
        std::string		 tmp;

        tmp = name;
        pv->note_cmd.push_back (tmp);
        tmp = arg;
        pv->note_arg.push_back (tmp);
}

        void
CLxUIValue::form_add_cmd (
        const char		*cmd)
{
        std::string		 tmp (cmd);

        pv->form_cmd.push_back (tmp);
}

        void
CLxUIValue::set_cue_text (
        const char		*text)
{
        pv->cue_text.assign (text);
}

        unsigned
CLxUIValue::Flags ()
{
        unsigned		 flag = 0;

        if (pv->pop_list.size ())
                flag |= LXfVALHINT_POPUPS;

        if (pv->alpha_sort)
                flag |= LXfVALHINT_POPUP_ALPHA_SORT;
        
        if (!pv->filter)
                flag |= LXfVALHINT_POPUPS_NO_FILTER;

        if (pv->form_cmd.size ())
                flag |= LXfVALHINT_FORM_COMMAND_LIST;

        return flag;
}

        unsigned
CLxUIValue::PopCount ()
{
        return pv->pop_list.size ();
}

        const char *
CLxUIValue::PopUserName (
        unsigned		 index)
{
        return pv->pop_list[index].user.get_opt ();
}

        const char *
CLxUIValue::PopInternalName (
        unsigned		 index)
{
        return pv->pop_list[index].internal.get_opt ();
}

        const char *
CLxUIValue::PopToolTip (
        unsigned		 index)
{
        return pv->pop_list[index].tooltip.get_opt ();
}

        int
CLxUIValue::PopFlags (
        unsigned		 index)
{
        return pv->pop_list[index].flags;
}

        LxResult
CLxUIValue::PopIconResource (
        int			 index,
        const char	       **iconResource)
{
        if (pv->pop_list[index].resrc.length() == 0)
                return LXe_NOTIMPL;

        iconResource[0] = pv->pop_list[index].resrc.c_str();
        return LXe_OK;
}

        const char *
CLxUIValue::PopCategory ()
{
        return pv->category.get_opt ();
}

        LxResult
CLxUIValue::PopIconSize (
        int			&w,
        int			&h)
{
        if (!pv->has_size)
                return LXe_NOTIMPL;

        w = pv->size_w;
        h = pv->size_h;
        return LXe_OK;
}

        LxResult
CLxUIValue::ColorPickerCommands (
        char			*rgb,
        char			*alpha,
        char			*rgbAlt,
        char			*alphaAlt,
        char			*useAlt,
        unsigned		 bufLens)
{
        if (bufLens < pv->col_buf() + 1)
                return LXe_SHORTBUFFER;

        lx::StringOut (pv->col_rgb  .c_str(), rgb,      bufLens);
        lx::StringOut (pv->col_alpha.c_str(), alpha,    bufLens);
        lx::StringOut (pv->alt_rgb  .c_str(), rgbAlt,   bufLens);
        lx::StringOut (pv->alt_alpha.c_str(), alphaAlt, bufLens);
        lx::StringOut (pv->col_swap .c_str(), useAlt,   bufLens);
        return LXe_OK;
}

        int
CLxUIValue::NotifierCount ()
{
        return pv->note_cmd.size ();
}

        LxResult
CLxUIValue::NotifierByIndex (
        int			 index,
        const char	       **name,
        const char	       **args)
{
        if (index >= pv->note_cmd.size ())
                return LXe_OUTOFBOUNDS;

        name[0] = pv->note_cmd[index].c_str();
        args[0] = pv->note_arg[index].c_str();
        return LXe_OK;
}

        int
CLxUIValue::FormCommandListCount ()
{
        return pv->form_cmd.size ();
}

        const char *
CLxUIValue::FormCommandListByIndex (
        int			 index)
{
        return pv->form_cmd[index].c_str();
}

        const char *
CLxUIValue::CueText ()
{
        return pv->cue_text.get_opt ();
}


/*
 * CUIValueHintWrapper is used to export a client CLxDynamicUIValue as a COM
 * object. The methods are all just pass-throughs to the equivalent methods
 * in the client's object, with slightly nicer APIs.
 */
class CUIValueHintWrapper :
                public CLxImpl_UIValueHints
{
    public:
        CLxDynamicUIValue	*val;
        bool			 owned;

        ~CUIValueHintWrapper ()
        {
                if (owned)
                        delete val;
        }

        unsigned	uiv_Flags (void) LXx_OVERRIDE
        {
                return val->Flags ();
        }

        unsigned	uiv_PopCount (void) LXx_OVERRIDE
        {
                return val->PopCount ();
        }

        const char *	uiv_PopUserName (unsigned index) LXx_OVERRIDE
        {
                if (index > val->PopCount()) return "**OOB**";
                return val->PopUserName (index);
        }

        const char *	uiv_PopInternalName (unsigned index) LXx_OVERRIDE
        {
                if (index > val->PopCount()) return "**OOB**";
                return val->PopInternalName (index);
        }

        const char *	uiv_PopToolTip (unsigned index) LXx_OVERRIDE
        {
                if (index > val->PopCount()) return "**OOB**";
                return val->PopToolTip (index);
        }

        LxResult	uiv_PopFlags (unsigned index, int *flags) LXx_OVERRIDE
        {
                if (index > val->PopCount()) return LXe_OUTOFBOUNDS;
                flags[0] = val->PopFlags (index);
                return LXe_OK;
        }

        LxResult	uiv_PopCategory (const char **category) LXx_OVERRIDE
        {
                category[0] = val->PopCategory ();
                return LXe_OK;
        }

        LxResult	uiv_PopIconSize (int *w, int *h) LXx_OVERRIDE
        {
                return val->PopIconSize (*w, *h);
        }

        LxResult	uiv_PopIconImage (int index, void **ppvObj) LXx_OVERRIDE
        {
                if (index > val->PopCount()) return LXe_OUTOFBOUNDS;
                return val->PopIconImage ( index, ppvObj );
        }

        LxResult	uiv_PopIconResource (int index, const char **iconResource) LXx_OVERRIDE
        {
                if (index > val->PopCount()) return LXe_OUTOFBOUNDS;
                return val->PopIconResource ( index, iconResource );
        }

        LxResult	uiv_ItemTest (ILxUnknownID item) LXx_OVERRIDE
        {
                CLxUser_Item		 ui (item);
                return val->ItemTest (ui) ? LXe_TRUE : LXe_FALSE;
        }

        LxResult	uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens) LXx_OVERRIDE
        {
                return val->ColorPickerCommands (rgb, alpha, rgbAlt, alphaAlt, useAlt, bufLens);
        }

        LxResult	uiv_NotifierCount (int *count) LXx_OVERRIDE
        {
                *count = val->NotifierCount ();
                return (count == 0) ? LXe_NOTIMPL : LXe_OK;
        }

        LxResult	uiv_NotifierByIndex (int index, const char **name, const char **args) LXx_OVERRIDE
        {
                if (index > val->NotifierCount ()) return LXe_OUTOFBOUNDS;
                return val->NotifierByIndex (index, name, args);
        }

        LxResult	uiv_FormCommandListCount (int *count) LXx_OVERRIDE
        {
                *count = val->FormCommandListCount ();
                return (*count == 0) ? LXe_NOTIMPL : LXe_OK;
        }

        LxResult	uiv_FormCommandListByIndex (int index, const char **command) LXx_OVERRIDE
        {
                if (index > val->FormCommandListCount ()) return LXe_OUTOFBOUNDS;
                *command = val->FormCommandListByIndex (index);
                return (*command == NULL) ? LXe_FAILED : LXe_OK;
        }

        LxResult	uiv_CueText (char *buf, unsigned len) LXx_OVERRIDE
        {
                const char		*text;

                text = val->CueText();
                if (!text)
                        return LXe_NOTIMPL;

                return lx::StringOut (text, buf, len);
        }
        
        LxResult	uiv_TextValidate(const char *value, char *buf, unsigned int len) LXx_OVERRIDE
        {
                return val->TextValidate(value, buf, len);
        }
};

/*
 * Public function for spawning a new UI Hints object from an internal
 * object pointer. We free it when destroying the wrapper if owned.
 */
        void
lx::UIValueHintsAllocate (
        CLxDynamicUIValue	*val,
        void		       **ppvObj,
        bool			 ownIt)
{
        CLxSpawnerCreate<CUIValueHintWrapper> spawner ("dyna.uihints");
        if (spawner.created)
        {
                spawner.AddInterface (new CLxIfc_UIValueHints<CUIValueHintWrapper>);
        }

        CUIValueHintWrapper *wrap = spawner.Alloc (ppvObj);
        wrap->val   = val;
        wrap->owned = ownIt;
}


/*
 * ----------------------------------------------------------------
 * DynaAttributes : Implementation
 *
 * Private data is a vector of DynaAttr structs containing an attribute name,
 * its type, optional text hints, and its value. Private data is allocated for
 * each instance of the class.
 */
class pv_DynaAttributes {
    public:
        typedef struct {
                string			 name;
                string			 type;
                const LXtTextValueHint	*hint;
                CLxUser_Value		 value;
                bool			 set;
                unsigned		 flags;
        } DynaAttr;

        DynaAttr &		 Elt (unsigned int index);
        void			 Set (CLxDynamicAttributes *, unsigned int index, bool value = true);

        LxResult		 sgs_GetString (char *buf, unsigned len);
        unsigned		 sgs_index;

        vector<DynaAttr>	 dlist;
};


CLxDynamicAttributes::CLxDynamicAttributes ()
{
        pv = new pv_DynaAttributes;
}

CLxDynamicAttributes::~CLxDynamicAttributes ()
{
        delete pv;
}


/*
 * The implementation is very easy, since we let nexus implement the
 * actual values. Adding a new value pushes one on the end of the struct,
 * including allocating a value of the given type.
 */
        void
CLxDynamicAttributes::dyna_Add (
        const char		*name,
        const char		*type)
{
        CLxUser_ValueService		 vs;
        pv_DynaAttributes::DynaAttr	 da;

        da.name  = name;
        da.type  = type;
        da.hint  = 0;
        da.set   = false;
        da.flags = 0;
        pv->dlist.push_back (da);

        vs.NewValue (pv->dlist.back().value, type);
}

        void
CLxDynamicAttributes::dyna_Add (
        std::string		 name,
        std::string		 type)
{
        dyna_Add (name.c_str(), type.c_str());
}


/*
 * Private method to access the DynaAttr struct for a given index. This encapsulates
 * the out-of-bounds exception.
 */
        pv_DynaAttributes::DynaAttr &
pv_DynaAttributes::Elt (
        unsigned int		 index)
{
        if (index >= dlist.size ())
                throw (LXe_OUTOFBOUNDS);

        return dlist[index];
}


/*
 * Public method for accessing the value by index.
 */
        CLxUser_Value &
CLxDynamicAttributes::dyna_Value (
        unsigned int		 index)
{
        return pv->Elt (index) . value;
}


/*
 * Public method to read the 'set' flag, which is true if the value is not its
 * default, plus a private method to set it. Setting it takes the dynamic attrs
 * object so we can call the client's Changed method.
 */
        bool
CLxDynamicAttributes::dyna_IsSet (
        unsigned int		 index)
{
        return pv->Elt (index) . set;
}

        void
pv_DynaAttributes::Set (
        CLxDynamicAttributes	*dyna,
        unsigned int		 index,
        bool			 value)
{
        Elt (index) . set = value;
        if (value)
                dyna->dyna_Changed (index);
}


/*
 * The text hints for any attribute can be set. Hints are assumed to be static.
 */
        void
CLxDynamicAttributes::dyna_SetHint (
        unsigned int		 index,
        const LXtTextValueHint	*hint)
{
        pv->Elt (index) . hint = hint;
}


/*
 * The type for an attribute can be changed on the fly. This will allocate a
 * new value of the given type. If the type is null it will still be re-allocated,
 * allowing the value to be reset to a default state.
 */
        void
CLxDynamicAttributes::dyna_SetType (
        unsigned int		 index,
        const char		*type)
{
        pv_DynaAttributes::DynaAttr	&da = pv->Elt (index);
        CLxUser_ValueService		 vs;
        std::string			 tmp;

        if (!type) {
                tmp  = da.type;
                type = tmp.c_str();

        } else if (da.type.compare (type) == 0)
                return;

        da.type = type;
        da.set  = false;
        vs.NewValue (da.value, type);
}


/*
 * The flags (used for command argument flags) can be read and written.
 */
        void
CLxDynamicAttributes::dyna_SetFlags (
        unsigned int		 index,
        unsigned		 flags)
{
        pv->Elt (index) . flags = flags;
}

        unsigned
CLxDynamicAttributes::dyna_GetFlags (
        unsigned int		 index)
{
        return pv->Elt (index) . flags;
}


/*
 * These methods implement the actual ILxAttributes interface. Querying the
 * actual list just uses the vector more or less directly.
 */
        unsigned int
CLxDynamicAttributes::attr_Count ()
{
        return static_cast<unsigned int>(pv->dlist.size());
}

        LxResult
CLxDynamicAttributes::attr_Name (
        unsigned int		 index,
        const char	       **name)
{
        name[0] = pv->Elt (index) . name.c_str ();
        return LXe_OK;
}

        LxResult
CLxDynamicAttributes::attr_Type (
        unsigned int		 index,
        unsigned int		*type)
{
        type[0] = dyna_Value (index) . Type ();
        return LXe_OK;
}

        LxResult
CLxDynamicAttributes::attr_TypeName (
        unsigned int		 index,
        const char	       **tname)
{
        tname[0] = pv->Elt (index) . type.c_str ();
        return LXe_OK;
}

        LxResult
CLxDynamicAttributes::attr_Lookup (
        const char		*name,
        unsigned int		*index)
{
        for (*index = 0; *index < pv->dlist.size (); index[0]++)
                if (!pv->dlist[*index].name.compare (name))
                        return LXe_OK;

        return LXe_NOTFOUND;
}

        const LXtTextValueHint *
CLxDynamicAttributes::attr_Hints (
        unsigned int		 index)
{
        return pv->Elt (index) . hint;
}


/*
 * For reading and writing values, all the hard work is deferred to the allocated
 * value object.
 */
        LxResult
CLxDynamicAttributes::attr_Value (
        unsigned int		 index,
        void		       **ppvObj,
        int			 writeOK)
{
        if (writeOK)
                pv->Set (this, index);

        dyna_Value (index) . get (ppvObj);
        return LXe_OK;
}

        LxResult
CLxDynamicAttributes::attr_GetBool (
        unsigned int		 index,
        bool			*val)
{
        int			 value;
        LxResult		 result;

        result = dyna_Value (index) . GetInt (&value);
        val[0] = !!value;
        return result;
}

        LxResult
CLxDynamicAttributes::attr_SetBool (
        unsigned int		 index,
        bool			 val)
{
        int			 value = val ? 1 : 0;

        pv->Set (this, index);
        return dyna_Value (index) . SetInt (value);
}

        LxResult
CLxDynamicAttributes::attr_GetInt (
        unsigned int		 index,
        int			*val)
{
        return dyna_Value (index) . GetInt (val);
}

        LxResult
CLxDynamicAttributes::attr_SetInt (
        unsigned int		 index,
        int			 val)
{
        pv->Set (this, index);
        return dyna_Value (index) . SetInt (val);
}

        LxResult
CLxDynamicAttributes::attr_GetFlt (
        unsigned int		 index,
        double			*val)
{
        return dyna_Value (index) . GetFlt (val);
}

        LxResult
CLxDynamicAttributes::attr_SetFlt (
        unsigned int		 index,
        double			 val)
{
        pv->Set (this, index);
        return dyna_Value (index) . SetFlt (val);
}

        LxResult
CLxDynamicAttributes::attr_GetString (
        unsigned int		 index,
        char			*val,
        unsigned int		 len)
{
        return dyna_Value (index) . GetString (val, len);
}

        LxResult
CLxDynamicAttributes::attr_SetString (
        unsigned int		 index,
        const char		*val)
{
        pv->Set (this, index);
        return dyna_Value (index) . SetString (val);
}


/*
 * These methods take defaults, which are returned if the attribute is unset.
 */
        bool
CLxDynamicAttributes::dyna_Bool (
        unsigned int		 index,
        bool			 value)
{
        if (dyna_IsSet (index))
                attr_GetBool (index, &value);

        return value;
}

        int
CLxDynamicAttributes::dyna_Int (
        unsigned int		 index,
        int			 value)
{
        if (dyna_IsSet (index))
                attr_GetInt (index, &value);

        return value;
}

        double
CLxDynamicAttributes::dyna_Float (
        unsigned int		 index,
        double			 value)
{
        if (dyna_IsSet (index))
                attr_GetFlt (index, &value);

        return value;
}

        bool
CLxDynamicAttributes::dyna_String (
        unsigned int		 index,
        std::string		&text,
        const char		*value)
{
        if (!dyna_IsSet (index)) {
                text = value;
                return true;
        } else
                return dyna_Value (index) . String (text);
}

        bool
CLxDynamicAttributes::dyna_Object (
        unsigned int		 index,
        CLxLocalizedObject	&loc)
{
        if (!dyna_IsSet (index))
                return false;

        return loc.set (dyna_Value (index));
}



/*
 * The safe version of GetString, the one that returns the result as a
 * dynamic string object, relies on a special named method in the private
 * class.
 */
        LxResult
pv_DynaAttributes::sgs_GetString (
        char			*buf,
        unsigned		 len)
{
        return Elt (sgs_index) . value . GetString (buf, len);
}

        LxResult
CLxDynamicAttributes::attr_GetString (
        unsigned int		 index,
        std::string		&value)
{
        CLxSafeGetString<pv_DynaAttributes> sgs;

        pv->sgs_index = index;
        return sgs.GetString (*pv, value);
}


/*
 * The ILxAttributeUI interface allows attributes to have features specific
 * to their presentation in the UI. In this case we just wrap the raw objects 
 * as nice interfaces and pass them on.
 */
        LxResult
CLxDynamicAttributes::atrui_UIHints (
        unsigned int		 index,
        ILxUnknownID		 hints)
{
        CLxUser_UIHints		 uiHints (hints);

        atrui_UIHints2 (index, uiHints);
        return LXe_OK;
}

        LxResult
CLxDynamicAttributes::atrui_DisableMsg (
        unsigned int		 index,
        ILxUnknownID		 msg)
{
        CLxUser_Message		 message (msg);

        if (!atrui_Enabled (index, message))
                message.SetCode (LXe_DISABLED);

        return message.Code ();
}


/*
 * The subclass allocates the C++ class, and we wrap it with an object.
 * We expect that the object was allocated and we now own it.
 */
 	LxResult
CLxDynamicAttributes::atrui_UIValueHints (
        unsigned int		 index,
        void		       **ppvObj)
{
        CLxDynamicUIValue	*val;

        val = atrui_UIValue (index);
        if (!val)
                return LXe_NOTIMPL;

        lx::UIValueHintsAllocate (val, ppvObj);
        return LXe_OK;
}


/*
 * ----------------------------------------------------------------
 * CLxDynamicArguments : Implementation
 *
 *
 * The GetFlags() override reads the stored flags and adds in the
 * SET flag for arguments that are set.
 */
        unsigned
CLxDynamicArguments::dyna_GetFlags (
        unsigned		 index)
{
        return CLxDynamicAttributes::dyna_GetFlags (index)
                | (dyna_IsSet (index) ? LXfCMDARG_VALUE_SET : 0);
}

/*
 * Test for variable arguments by scanning the list. We could cache the
 * state but this is not too bad.
 */
        bool
CLxDynamicArguments::dyna_HasVariable ()
{
        for (int i = 0; i < attr_Count (); i++)
                if (dyna_GetFlags (i) & LXfCMDARG_VARIABLE)
                        return true;

        return false;
}

/*
 * Variable argument types are set by first testing if we can, throwing
 * an exception if not all required args are set. Then the RFV_SET flag
 * bit is set on all args, while the variable ones have their types
 * changed using the virtual function.
 */
        void
CLxDynamicArguments::dyna_SetVariable ()
{
        unsigned int		 i, k;

        if (!dyna_HasVariable ())
                return;

        for (i = 0; i < attr_Count (); i++)
        {
                k = dyna_GetFlags (i);
                if ((k & LXfCMDARG_REQFORVARIABLE) && !dyna_IsSet (i))
                        throw (LXe_CMD_MISSING_ARGS);
        }

        for (i = 0; i < attr_Count (); i++)
        {
                k = dyna_GetFlags (i);
                dyna_SetFlags (i, k | LXfCMDARG_REQFORVAR_SET);
                if (k & LXfCMDARG_VARIABLE)
                        dyna_SetType (i, dyna_GetType (i));
        }
}


/*
 * Clearing an argument resets the type, which allocates a new value. For
 * arguments which affect the type of other arguments we have to clear all
 * the ones with variable type.
 */
        void
CLxDynamicArguments::dyna_Clear (
        unsigned		 index)
{
        unsigned int		 i, k;

        dyna_SetType (index, 0);

        if (!dyna_HasVariable () || !(dyna_GetFlags (index) & LXfCMDARG_REQFORVARIABLE))
                return;

        for (i = 0; i < attr_Count (); i++)
        {
                k = dyna_GetFlags (i);
                dyna_SetFlags (i, k & ~LXfCMDARG_REQFORVAR_SET);
                if (k & LXfCMDARG_VARIABLE)
                        dyna_Clear (i);
        }
}

        void
CLxDynamicArguments::dyna_ClearAll ()
{
        for (int i = 0; i < attr_Count (); i++)
                dyna_Clear (i);
}



/*
 * ----------------------------------------------------------------
 * CLxUIListPopup : Implementation
 *
 * We update the lists on any call to count. This is probably redundant, but it
 * assures that the lists are always up to date.
 */
        unsigned
CLxUIListPopup::Flags ()
{
        return LXfVALHINT_POPUPS;
}

        unsigned
CLxUIListPopup::PopCount ()
{
        user_list.clear ();
        internal_list.clear ();
        tooltip_list.clear ();
        UpdateLists ();

        return (unsigned)user_list.size ();
}

        const char *
CLxUIListPopup::PopUserName (
        unsigned		 index)
{
        if (index < user_list.size ())
                return user_list[index].c_str ();

        return "*O*O*B*";
}

        const char *
CLxUIListPopup::PopInternalName (
        unsigned		 index)
{
        if (index < internal_list.size ())
                return internal_list[index].c_str ();

        if (index < user_list.size ())
                return user_list[index].c_str ();

        return "*O*O*B*";
}

        const char *
CLxUIListPopup::PopToolTip (
        unsigned		 index)
{
        if (index < tooltip_list.size ())
                return tooltip_list[index].empty() ? NULL : tooltip_list[index].c_str ();

        return "*O*O*B*";
}

