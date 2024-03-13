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
#ifndef LXUSER_value_HPP
#define LXUSER_value_HPP

#include <lxw_value.hpp>

#include <lxu_getstring.hpp>



class CLxUser_Value : public CLxLoc_Value
{
        public:
        CLxUser_Value () {}
        CLxUser_Value (ILxUnknownID obj) : CLxLoc_Value (obj) {}

        /**
         * For C++ developers, a method is provided that returns the Comparison value
         * directly.
         */
                int
        Compare (
                ILxUnknownID		 other)
        {
                int			 diff;
        
                if (LXx_FAIL (CLxLoc_Value::Compare (other, &diff)))
                        return -1;
        
                return diff;
        }
        LxResult
        sgs_GetString (char *buf, unsigned len)
        {
                return GetString (buf, len);
        }
        
                bool
        String (
                std::string		&text)
        {
                CLxSafeGetString<CLxUser_Value>	 sgs;
        
                return sgs.GetStringBool (*this, text);
        }
        /**
         * For setting at least we can infer the type from the argument.
         */
                void
        Set (
                int			 value)
        {
                SetInt (value);
        }
        
                void
        Set (
                double			 value)
        {
                SetFlt (value);
        }
        
                void
        Set (
                const char		*value)
        {
                SetString (value);
        }

};

class CLxUser_StringConversion : public CLxLoc_StringConversion
{
        public:
        CLxUser_StringConversion () {}
        CLxUser_StringConversion (ILxUnknownID obj) : CLxLoc_StringConversion (obj) {}

        // QWEB_MACRO_BEGIN - Conv $$ user class method
        class Tmp_Sgs {
            public:
                CLxLoc_StringConversion		*conv;
        
                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return conv->Encode (buf, len);
                }
        };
        
                LxResult
        EncodeStr (
                std::string		&text)
        {
                Tmp_Sgs				 tmp;
                CLxSafeGetString<Tmp_Sgs>	 sgs;
        
                tmp.conv = this;
                return sgs.GetString (tmp, text);
        }
                // QWEB_MACRO_END - Conv $$ user class method

};

class CLxUser_StringConversionNice : public CLxLoc_StringConversionNice
{
        public:
        CLxUser_StringConversionNice () {}
        CLxUser_StringConversionNice (ILxUnknownID obj) : CLxLoc_StringConversionNice (obj) {}

        // QWEB_MACRO_BEGIN - Conv $$ user class method
        class Tmp_Sgs {
            public:
                CLxLoc_StringConversionNice		*conv;
        
                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return conv->Encode (buf, len);
                }
        };
        
                LxResult
        EncodeStr (
                std::string		&text)
        {
                Tmp_Sgs				 tmp;
                CLxSafeGetString<Tmp_Sgs>	 sgs;
        
                tmp.conv = this;
                return sgs.GetString (tmp, text);
        }
                // QWEB_MACRO_END - Conv $$ user class method

};

class CLxUser_ValueMath : public CLxLoc_ValueMath
{
        public:
        CLxUser_ValueMath () {}
        CLxUser_ValueMath (ILxUnknownID obj) : CLxLoc_ValueMath (obj) {}



};

class CLxUser_ValueReference : public CLxLoc_ValueReference
{
        public:
        CLxUser_ValueReference () {}
        CLxUser_ValueReference (ILxUnknownID obj) : CLxLoc_ValueReference (obj) {}

        bool
        Get (
                CLxLocalizedObject	&loc)
        {
                return GetObject (loc);
        }
        
                bool
        TakeObject (
                ILxUnknownID		 obj)
        {
                if (LXx_FAIL (SetObject (obj)))
                        return false;
        
                lx::UnkRelease (obj);
                return true;
        }

};

class CLxUser_ValueConversion : public CLxLoc_ValueConversion
{
        public:
        CLxUser_ValueConversion () {}
        CLxUser_ValueConversion (ILxUnknownID obj) : CLxLoc_ValueConversion (obj) {}



};

class CLxUser_Attributes : public CLxLoc_Attributes
{
        public:
        CLxUser_Attributes () {}
        CLxUser_Attributes (ILxUnknownID obj) : CLxLoc_Attributes (obj) {}

        /**
         * FindIndex() is an analogue of Lookup(), but returns the attribute index or
         * -1 for none.
         */
                int
        FindIndex (
                const std::string	&name)
        {
                unsigned		 index;
        
                if (LXx_OK (Lookup (name.c_str (), &index)))
                        return index;
                else
                        return -1;
        }
        
                int
        FindIndex (
                const char		*name)
        {
                unsigned		 index;
        
                if (LXx_OK (Lookup (name, &index)))
                        return index;
                else
                        return -1;
        }
        
                int
        Type (
                unsigned		 index)
        {
                unsigned		 type;
        
                if (LXx_OK (CLxLoc_Attributes::Type (index, &type))) {
                        return type;
                }
                else {
                        return -1;
                }
        }
        
                bool
        Name (
                unsigned		 index,
                std::string		&name)
        {
                const char	*nameChars;
                bool		 foundName;
        
                foundName = LXx_OK (CLxLoc_Attributes::Name (index, &nameChars));
                if (foundName) {
                        name = std::string (nameChars);
                        foundName = true;
                }
                else {
                        name = "";
                }
        
                return foundName;
        }
        /**
         * There are a few alternate methods defined in the C++ user class for
         * handling some of the type conversions.
         */
                bool
        Set (
                unsigned		 index,
                bool			 val)
        {
                return LXx_OK (SetInt (index, val ? 1 : 0));
        }
        
                bool
        Set (
                unsigned		 index,
                int			 val)
        {
                return LXx_OK (SetInt (index, val));
        }
        
                bool
        Set (
                unsigned		 index,
                double			 val)
        {
                return LXx_OK (SetFlt (index, val));
        }
        
                bool
        Set (
                unsigned		 index,
                const char		*val)
        {
                return LXx_OK (SetString (index, val));
        }
        /**
         * Simpler get methods return the value without error checking.
         */
                bool
        Bool (
                unsigned		 index,
                bool			 preset = false)
        {
                int                      val;
        
                if (LXx_FAIL (GetInt (index, &val)))
                        return preset;
        
                return val ? true : false;
        }
        
                int
        Int (
                unsigned		 index,
                int			 preset = 0)
        {
                int                      val;
        
                if (LXx_FAIL (GetInt (index, &val)))
                        return preset;
        
                return val;
        }
        
                double
        Float (
                unsigned		 index,
                double			 preset = 0.0)
        {
                double                   val;
        
                if (LXx_FAIL (GetFlt (index, &val)))
                        return preset;
        
                return val;
        }
        /**
         * Strings can be set and read using the STL string class.
         */
                bool
        Set (
                unsigned		 index,
                const std::string	&text)
        {
                return LXx_OK (SetString (index, text.c_str ()));
        }
        
        class Tmp_Sgs {
            public:
                CLxLoc_Attributes	*attr;
                unsigned		 index;
        
                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return attr->GetString (index, buf, len);
                }
        };
        
                bool
        String (
                unsigned		 index,
                std::string		&text)
        {
                Tmp_Sgs				 tmp;
                CLxSafeGetString<Tmp_Sgs>	 sgs;
        
                tmp.attr  = this;
                tmp.index = index;
                return sgs.GetStringBool (tmp, text);
        }
        /**
         * Object values can be read into any interface localization, for read-only
         * access or for read-write.
         */
                bool
        ObjectRO (
                unsigned		 index,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Value (index, &obj, 0)))
                        return false;
        
                return loc.take (obj);
        }
        
                bool
        ObjectRW (
                unsigned		 index,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (Value (index, &obj, 1)))
                        return false;
        
                return loc.take (obj);
        }
        /**
         * If the object is of the OBJREF type, then it's actually a container
         * for another object. These methods allow the content to be accessed directly.
         */
                LxResult
        GetRef (
                unsigned		 index,
                void		       **ppvObj)
        {
                CLxLoc_ValueReference	 ref;
                LxResult		 rc;
        
                rc = Value (index, ref, 0);
                if (LXx_FAIL (rc))
                        return rc;
        
                return ref.GetObject (ppvObj);
        }
        
                bool
        GetRef (
                unsigned		 index,
                CLxLocalizedObject	&loc)
        {
                LXtObjectID		 obj;
        
                return LXx_OK (GetRef (index, &obj)) && loc.take (obj);
        }
        
                LxResult
        SetRef (
                unsigned		 index,
                ILxUnknownID		 obj)
        {
                CLxLoc_ValueReference	 ref;
                LxResult		 rc;
        
                rc = Value (index, ref, 1);
                if (LXx_FAIL (rc))
                        return rc;
        
                return ref.SetObject (obj);
        }
        
                bool
        TakeRef (
                unsigned		 index,
                ILxUnknownID		 obj)
        {
                if (LXx_FAIL (SetRef (index, obj)))
                        return false;
        
                lx::UnkRelease (obj);
                return true;
        }

};

class CLxUser_Message : public CLxLoc_Message
{
        public:
        CLxUser_Message () {}
        CLxUser_Message (ILxUnknownID obj) : CLxLoc_Message (obj) {}

        /**
         * The user class has alternate methods for setting the argument based on
         * different types.
         */
                bool
        SetArg (
                unsigned		 arg,
                int			 val)
        {
                return LXx_OK (SetArgumentInt (arg, val));
        }
        
                bool
        SetArg (
                unsigned		 arg,
                double			 val)
        {
                return LXx_OK (SetArgumentFloat (arg, val));
        }
        
                bool
        SetArg (
                unsigned		 arg,
                const char		*val)
        {
                return LXx_OK (SetArgumentString (arg, val));
        }
        /**
         * It also has some alternates for setting the message itself using either
         * dictionary string or message ID. If you pass just a string it will use common
         * message 99 which just displays argument 1. This is not recommended for
         * commercial plug-ins, but it lets you use literal text for quick hacks.
         */
                bool
        SetMsg (
                const char		*table,
                unsigned		 id)
        {
                return LXx_OK (SetMessage (table, 0, id));
        }
        
                bool
        SetMsg (
                const char		*table,
                const char		*name)
        {
                return LXx_OK (SetMessage (table, name, 0));
        }
        
                bool
        SetMsg (
                const char		*string)
        {
                return SetMsg ("common", 99) && SetArg (1, string);
        }

};

class CLxUser_ValueArray : public CLxLoc_ValueArray
{
        public:
        CLxUser_ValueArray () {}
        CLxUser_ValueArray (ILxUnknownID obj) : CLxLoc_ValueArray (obj) {}

        /**
         * There are a few alternate methods in the user class for varying arg types.
         */
                bool
        AddEmpty (
                CLxLocalizedObject	&val)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (AddEmptyValue (&obj)))
                        return false;
        
                return val.take (obj);
        }
        
                bool
        Add (
                CLxLoc_Value		&val)
        {
                return LXx_OK (AddValue (val));
        }
        
                bool
        Add (
                bool			 val)
        {
                return LXx_OK (AddInt (val ? 1 : 0));
        }
        
                bool
        Add (
                int			 val)
        {
                return LXx_OK (AddInt (val));
        }
        
                bool
        Add (
                double			 val)
        {
                return LXx_OK (AddFloat (val));
        }
        
                bool
        Add (
                const char		*val)
        {
                return LXx_OK (AddString (val));
        }
class Tmp_Sgs {
            public:
                CLxLoc_ValueArray	*vary;
                unsigned		 index;
        
                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return vary->GetString (index, buf, len);
                }
        };
        
                bool
        String (
                unsigned		 index,
                std::string		&text)
        {
                Tmp_Sgs				 tmp;
                CLxSafeGetString<Tmp_Sgs>	 sgs;
        
                tmp.vary  = this;
                tmp.index = index;
                return sgs.GetStringBool (tmp, text);
        }

};

class CLxUser_ScriptQuery : public CLxLoc_ScriptQuery
{
        public:
        CLxUser_ScriptQuery () {}
        CLxUser_ScriptQuery (ILxUnknownID obj) : CLxLoc_ScriptQuery (obj) {}

        /**
         * The script query C++ user class has a method that allows it to init from
         * any global.  This is done by *casting* to the ILxValueService interface,
         * which we know is defined, and calling the ScriptQuery() method.  Any
         * well-formed global will have this as their first method, but there is some
         * danger here in casting.
         */
                bool
        fromGlobal (
                LXtObjectID		 obj)
        {
                ILxValueServiceID	 srv = reinterpret_cast<ILxValueServiceID> (obj);
        
                if (LXx_OK (srv[0]->ScriptQuery (srv, &obj)))
                        return take (obj);
        
                clear ();
                return false;
        }

};

class CLxUser_StringTag : public CLxLoc_StringTag
{
        public:
        CLxUser_StringTag () {}
        CLxUser_StringTag (ILxUnknownID obj) : CLxLoc_StringTag (obj) {}

        /**
         * User class method gets the string from the tag, or null if not found.
         */
                const char *
        Value (
                LXtID4			 type)
        {
                const char		*tag;
        
                if (LXx_OK (Get (type, &tag)))
                        return tag;
                else
                        return 0;
        }
        /**
         * User class method returns true if the tag matches the string.
         */
                bool
        Match (
                LXtID4			 type,
                const char		*str)
        {
                const char		*tag;
        
                return LXx_OK (Get (type, &tag)) && (strcmp (str, tag) == 0);
        }
        /**
         * User class method returns true if the tag contains the string.
         */
                bool
        Contains (
                LXtID4			 type,
                const char		*str)
        {
                const char		*tag = NULL;
        
                if (str && LXx_OK (Get (type, &tag)) && tag)
                {
                        std::string		 tagStr (tag);
                        
                        return (tagStr.find (std::string (str)) != std::string::npos);
                }
                
                return false;
        }

};

class CLxUser_Matrix : public CLxLoc_Matrix
{
        public:
        CLxUser_Matrix () {}
        CLxUser_Matrix (ILxUnknownID obj) : CLxLoc_Matrix (obj) {}



};

class CLxUser_Quaternion : public CLxLoc_Quaternion
{
        public:
        CLxUser_Quaternion () {}
        CLxUser_Quaternion (ILxUnknownID obj) : CLxLoc_Quaternion (obj) {}



};

class CLxUser_TextEncoding : public CLxLoc_TextEncoding
{
        public:
        CLxUser_TextEncoding () {}
        CLxUser_TextEncoding (ILxUnknownID obj) : CLxLoc_TextEncoding (obj) {}

        bool
        ConvertString (
                const std::string	&src,
                std::string		&dst)
        {
                char			*tmp;
                unsigned		 max;
        
                if (CLxLoc_TextEncoding::Source () == CLxLoc_TextEncoding::Target ())
                        return false;
        
                max = (unsigned)src.length () * 2 + 1;
                tmp = new char[max];
                if (LXx_OK (CLxLoc_TextEncoding::Convert (src.c_str (), tmp, max)))
                        dst = tmp;
                delete [] tmp;
                return !dst.empty ();
        }

};

class CLxUser_ValueService : public CLxLoc_ValueService
{
        public:
        /**
         * Safer version for C++.
         */
        class Tmp_Sgs {
            public:
                CLxLoc_ValueService	*vsrv;
                const LXtTextValueHint	*hint;
                int			 value;
        
                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return vsrv->TextHintEncode (value, hint, buf, len);
                }
        };
        
                bool
        EncodeHint (
                int			 value,
                const LXtTextValueHint	*hint,
                std::string		&text)
        {
                Tmp_Sgs				 tmp;
                CLxSafeGetString<Tmp_Sgs>	 sgs;
        
                tmp.vsrv  = this;
                tmp.value = value;
                tmp.hint  = hint;
                return sgs.GetStringBool (tmp, text);
        }
        bool
        NewValue (
                CLxLocalizedObject	&value,
                const char		*type)
        {
                LXtObjectID		 obj;
        
                if (LXx_FAIL (CreateValue (type, &obj)))
                        return false;
        
                return value.take (obj);
        }

};

class CLxUser_TextEncodingService : public CLxLoc_TextEncodingService
{
        public:
        bool
        NewTextEncoding (
                CLxLoc_TextEncoding	 &txe)
        {
                LXtObjectID		  obj;
                LxResult		  rc;
        
                rc = Allocate (&obj);
                if (LXx_FAIL (rc))
                        return false;
        
                return txe.take (obj);
        }

};
#endif
