/*
 * Plug-in SDK Source: Metaclasses
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
 * Implements Value metaclass.
 */
#include <lxu_value.hpp>
#include <lx_com.hpp>

using namespace lx_err;


/*
 * ------------------------------------------------------
 * Meta Value
 */
class impl_Value_Server;

/*
 * This private state is global to each Value metaclass.
 */
class pv_Meta_Value
{
    public:
        CLxTagList		*tag_list;
        CLxMeta_Value_Core	*m_core;
        CLxPolymorph<impl_Value_Server>
                                *srv_spawn;
        std::string		 type_name;

        pv_Meta_Value ()
        {
                tag_list   = 0;
                m_core     = 0;
        }

                void
        add_interfaces (
                CLxGenericPolymorph	*gp)
        {
                gp->AddInterface (new CLxIfc_Value         <impl_Value_Server>);
                gp->AddInterface (new CLxIfc_TagDescription<impl_Value_Server>);
        }
};


/*
 * The Value server object implements the Value and Tags interfaces.
 */
class impl_Value_Server :
                public CLxImpl_Value,
                public CLxImpl_TagDescription
{
    public:
        pv_Meta_Value		*mpv;
        CLxValue		*inst;

        impl_Value_Server (
                pv_Meta_Value		*init = 0)
        {
                mpv = init;
                inst = mpv->m_core->new_inst ();
                inst->_mpv = mpv;
        }

                CLxValue *
        ref_obj ()
        {
                return inst;
        }

        LXxO_Value_Clone // (void **ppvObj)
        {
                impl_Value_Server	*that;

                that = mpv->srv_spawn->Alloc (ppvObj);
                that->inst->copy (inst);
                return LXe_OK;
        }

        LXxO_Value_Copy // (ILxUnknownID from)
        {
                impl_Value_Server	*that;

                that = mpv->srv_spawn->Cast (from);
                inst->copy (that->inst);
                return LXe_OK;
        }

        LXxO_Value_Compare // (ILxUnknownID other, int *diff)
        {
                impl_Value_Server	*that;

                that = mpv->srv_spawn->Cast (other);
                diff[0] = inst->compare (that->inst);
                return LXe_OK;
        }

        LXxO_Value_Type // (void)
        {
                return LXi_TYPE_OBJECT;
        }

        LXxO_Value_GetInt // (int *val)
        {
                val[0] = inst->get_int ();
                return LXe_OK;
        }

        LXxO_Value_SetInt // (int val)
        {
                inst->set_int (val);
                return LXe_OK;
        }

        LXxO_Value_GetFlt // (double *val)
        {
                val[0] = inst->get_float ();
                return LXe_OK;
        }

        LXxO_Value_SetFlt // (double val)
        {
                inst->set_float (val);
                return LXe_OK;
        }

        LXxO_Value_GetString // (char *buf, unsigned len)
        {
                std::string		 val = inst->get_string ();

                return lx::StringOut (val, buf, len);
        }

        LXxO_Value_SetString // (const char *val)
        {
                inst->set_string (val);
                return LXe_OK;
        }
        
        LXxO_Value_TypeName // (const char **name)
        {
                if(NULL == mpv)
                        return LXe_FAILED;
        
                *name = mpv->type_name.c_str();
                return LXe_OK;
        }

        /*
         * Server tags from metaclass core.
         */
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
 * The metaclass holds the global settings.
 */
CLxMeta_Value_Core::CLxMeta_Value_Core (
        const char		*srvName)
                :
        CLxMetaServer (srvName)
{
        pv = new pv_Meta_Value;
        pv->m_core   =  this;
        pv->tag_list = &tag_list;

        cls_guid = &lx::guid_Value;
}

CLxMeta_Value_Core::~CLxMeta_Value_Core ()
{
        delete pv;
}

        void *
CLxMeta_Value_Core::alloc ()
{
        pv->srv_spawn =
                new CLxMetagenPolymorphHost<impl_Value_Server, pv_Meta_Value>
                        (pv, get_ifcs ());

        return reinterpret_cast<void *> (pv->srv_spawn);
}

        const char *
CLxMeta_Value_Core::type_name ()
{
        if (!pv->type_name.size())
        {
                pv->type_name  = "+";
                pv->type_name +=  m_name;
        }

        return pv->type_name.c_str();
}

        CLxValue *
CLxMeta_Value_Core::extract (
        ILxUnknownID			 obj)
{
        impl_Value_Server		*impl;

        if (!obj)
                return 0;

        impl = pv->srv_spawn->Cast (obj);
        return impl->inst;
}


/*
 * This crazy template does all the work needed to define a meta object for
 * an optional Value interface. The macro fills in allt he places that the
 * same class name needs to be inserted into the declaration.
 */
template <class IMPL, class IFC, class PUB>
class meta_valueOptional :
                public CLxMeta
{
    public:
        class _polymorph :
                        public CLxPolymorph<IMPL>
        {
            public:
                _polymorph ()
                {
                        this->AddInterface (new IFC);
                }

                        void
                InitObj (
                        void			*impl,
                        void			*inst)			LXx_OVERRIDE
                {
                        IMPL			*dest = (IMPL *) impl;

                        dest->val = reinterpret_cast<CLxValue *> (inst);
                        dest->inst = dynamic_cast<PUB *> (dest->val);
                }
        };

        meta_valueOptional ()
        {
                m_type = LXsMETA_INTERFACE;
                cls_guid = &lx::guid_Value;
        }

                void *
        alloc ()
        {
                return new _polymorph;
        }
};

#define META_OPT(cls)	meta_valueOptional<impl_##cls, CLxIfc_##cls<impl_##cls>, CLxValue_##cls>


/*
 * ------------------------------------------------------
 * StringConversion
 * 
 * The sub-object is allocated as needed, and points back to the same value
 * instance.
 */
class impl_StringConversion :
                public CLxImpl_StringConversion
{
    public:
        CLxValue		*val;
        CLxValue		*inst;

        LXxO_StringConversion_Encode // (char *buf, unsigned len)
        {
                std::string res = inst->get_string ();
                return lx::StringOut (res, buf, len);
        }

        LXxO_StringConversion_Decode // (const char *buf)
        {
                inst->set_string (buf);
                return LXe_OK;
        }
};

        void
CLxMeta_Value_Core::add_strings ()
{
        add (new meta_valueOptional<impl_StringConversion, CLxIfc_StringConversion<impl_StringConversion>, CLxValue>);
}


/*
 * ------------------------------------------------------
 * StringConversionNice
 * 
 * The sub-object is allocated as needed, and points back to the same value
 * instance.
 */
class impl_StringConversionNice :
                public CLxImpl_StringConversionNice
{
    public:
        CLxValue		*val;
        CLxValue_StringConversionNice
                                *inst;

        LXxO_StringConversionNice_Encode // (char *buf, unsigned len)
        {
                std::string res = inst->get_nice ();
                return lx::StringOut (res, buf, len);
        }

        LXxO_StringConversionNice_Decode // (const char *buf)
        {
                inst->set_nice (buf);
                return LXe_OK;
        }
};

        void
CLxMeta_Value_Core::add_nice_strings ()
{
        add (new META_OPT(StringConversionNice));
}


/*
 * ------------------------------------------------------
 * StreamIO interface
 * 
 * The stream sub-object is allocated as needed, and points back to the
 * same value instance.
 */
class impl_StreamIO :
                public CLxImpl_StreamIO
{
    public:
        CLxValue		*val;
        CLxValue_StreamIO	*inst;

        LXxO_StreamIO_Write // (ILxUnknownID stream)
        {
                CLxUser_BlockWrite	 strm (stream);

                inst->save (strm);
                return LXe_OK;
        }

        LXxO_StreamIO_Read // (ILxUnknownID stream)
        {
                CLxUser_BlockRead	 strm (stream);

                inst->load (strm);
                return LXe_OK;
        }
};

 #if 0
class polymorph_StreamIO :
                public CLxPolymorph<impl_StreamIO>
{
    public:
        polymorph_StreamIO ()
        {
                AddInterface (new CLxIfc_StreamIO<impl_StreamIO>);
        }

                void
        InitObj (
                void			*impl,
                void			*inst)			LXx_OVERRIDE
        {
                CLxValue		*val = reinterpret_cast<CLxValue *> (inst);

                ((impl_StreamIO *) impl) -> inst = dynamic_cast<CLxValue_StreamIO *> (val);
        }
};

class meta_StreamIO :
                public CLxMeta
{
    public:
        meta_StreamIO ()
        {
                m_type = LXsMETA_INTERFACE;
                cls_guid = &lx::guid_Value;
        }

                void *
        alloc ()
        {
                return new polymorph_StreamIO;
        }
};
 #endif

        void
CLxMeta_Value_Core::add_streamIO ()
{
        add (new META_OPT(StreamIO));
}


/*
 * ------------------------------------------------------
 * ValueMath interface
 * 
 * The math sub-object is allocated as needed, and points back to the
 * same value instance.
 */
class impl_ValueMath :
                public CLxImpl_ValueMath
{
    public:
        CLxValue		*val;
        CLxValue_ValueMath	*inst;

        LXxO_ValueMath_Step // (int direction)
        {
                inst->step (direction);
                return LXe_OK;
        }

        LXxO_ValueMath_Detent // (void)
        {
                return inst->detent ();
        }

        LXxO_ValueMath_Add // (double delta)
        {
                inst->add (delta);
                return LXe_OK;
        }

        LXxO_ValueMath_Multiply // (double factor)
        {
                inst->multiply (factor);
                return LXe_OK;
        }

        LXxO_ValueMath_Blend // (ILxUnknownID other, double blend)
        {
                impl_Value_Server	*that;

                that = val->_mpv->srv_spawn->Cast (other);
                inst->blend (that->inst, blend);
                return LXe_OK;
        }
};

        void
CLxMeta_Value_Core::add_math ()
{
        add (new META_OPT(ValueMath));
}


