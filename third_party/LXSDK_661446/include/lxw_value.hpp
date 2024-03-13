/*
 * C++ wrapper for lxvalue.h
 *
 *	Copyright (c) 2008-2022 The Foundry Group LLC
 *	
 *	Permission is hereby granted, free of charge, to any person obtaining a
 *	copy of this software and associated documentation files (the "Software"),
 *	to deal in the Software without restriction, including without limitation
 *	the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *	and/or sell copies of the Software, and to permit persons to whom the
 *	Software is furnished to do so, subject to the following conditions:
 *	
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.   Except as contained
 *	in this notice, the name(s) of the above copyright holders shall not be
 *	used in advertising or otherwise to promote the sale, use or other dealings
 *	in this Software without prior written authorization.
 *	
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *	DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef LXW_VALUE_HPP
#define LXW_VALUE_HPP

#include <lxvalue.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ValueConversion = {0xAE427D16,0xAA5E,0x4135,0x87,0x22,0x38,0xD6,0x9F,0x48,0xF9,0xEC};
    static const LXtGUID guid_Value1 = {0x62E1DBE9,0x2FFE,0x4B5C,0xB2,0x86,0xE5,0x4E,0x79,0x41,0x53,0x03};
    static const LXtGUID guid_Visitor = {0xC8FCAD70,0xDDDF,0x499E,0xA0,0x3B,0xA0,0x8B,0x90,0x6D,0x3E,0x53};
    static const LXtGUID guid_ValueArray = {0x6DAC2F05,0xD95B,0x11E8,0x96,0x84,0xE2,0x00,0xE9,0x30,0x97,0x01};
    static const LXtGUID guid_Array = {0xd1e1ba61,0x700e,0x48ad,0xaa,0xda,0x68,0x65,0x14,0x8f,0xcc,0x40};
    static const LXtGUID guid_Message = {0xDDDBF46A,0x0865,0x4AB7,0x99,0x62,0x72,0xE7,0xB4,0x77,0xFD,0x22};
    static const LXtGUID guid_Attributes = {0x117957D0,0x5A13,0x11D7,0xA1,0x8C,0x00,0x0A,0x95,0x76,0x5C,0x9E};
    static const LXtGUID guid_ValueService = {0xDD2C3059,0x2CD0,0x4c7d,0x86,0x0C,0xCF,0x35,0x3C,0xFB,0x2F,0x92};
    static const LXtGUID guid_Value = {0x83065459,0xD9EA,0x11E8,0xAE,0xB4,0xE2,0x00,0xE9,0x30,0x97,0x01};
    static const LXtGUID guid_StringTag = {0xC2004BC7,0x6A90,0x4BD3,0xBD,0xF7,0xB3,0x75,0xC7,0x90,0xDB,0x70};
    static const LXtGUID guid_ValueMath = {0x752B4D2E,0x6F13,0x4B2C,0xB0,0xB3,0x0B,0xA8,0xCA,0x6B,0x06,0x92};
    static const LXtGUID guid_ScriptQuery = {0x0434F07E,0xAD4A,0x492f,0xAD,0x43,0x32,0x49,0xBD,0x16,0x99,0x4D};
    static const LXtGUID guid_TextEncodingService = {0x7753B6E4,0xCF23,0x491E,0x89,0xC1,0x2C,0xA2,0x6B,0xE5,0xC8,0x9F};
    static const LXtGUID guid_StringConversionNice = {0x5407328B,0xDE99,0x4F15,0x86,0x6F,0xF6,0xE2,0x14,0xFF,0xA4,0x12};
    static const LXtGUID guid_Quaternion = {0xB8697DEB,0xDCD0,0x4C86,0xB8,0x22,0x70,0x2D,0x5E,0xDE,0xFA,0x76};
    static const LXtGUID guid_ValueReference = {0x0567BC88,0xF782,0x426E,0x98,0xC5,0x83,0x02,0xFD,0x52,0xD9,0xE4};
    static const LXtGUID guid_ValueArray1 = {0xA964962F,0x9028,0x4CA3,0x96,0x12,0x17,0xD3,0x60,0xDF,0x92,0xBA};
    static const LXtGUID guid_StringConversion = {0x5CB3EEDB,0xE4E0,0x499E,0xB0,0xBA,0xA7,0xFB,0x51,0xBA,0xBE,0x3C};
    static const LXtGUID guid_Matrix = {0xEF9FDE7B,0xE7FA,0x48B2,0x83,0x8E,0xA5,0xA8,0xF7,0xD5,0xC2,0x54};
    static const LXtGUID guid_TextEncoding = {0xEE4989E5,0xF1E5,0x43D4,0x80,0xCC,0x16,0xF5,0x06,0xEF,0xD6,0x32};
};

class CLxImpl_ValueConversion {
  public:
    virtual ~CLxImpl_ValueConversion() {}
    virtual LxResult
      conv_Test (const char *fromType, const char *toType)
        { return LXe_NOTIMPL; }
    virtual LxResult
      conv_Convert (ILxUnknownID from, const char *fromType, ILxUnknownID to, const char *toType)
        { return LXe_NOTIMPL; }
};
#define LXxD_ValueConversion_Test LxResult conv_Test (const char *fromType, const char *toType)
#define LXxO_ValueConversion_Test LXxD_ValueConversion_Test LXx_OVERRIDE
#define LXxC_ValueConversion_Test(c) LxResult c::conv_Test (const char *fromType, const char *toType)
#define LXxD_ValueConversion_Convert LxResult conv_Convert (ILxUnknownID from, const char *fromType, ILxUnknownID to, const char *toType)
#define LXxO_ValueConversion_Convert LXxD_ValueConversion_Convert LXx_OVERRIDE
#define LXxC_ValueConversion_Convert(c) LxResult c::conv_Convert (ILxUnknownID from, const char *fromType, ILxUnknownID to, const char *toType)
template <class T>
class CLxIfc_ValueConversion : public CLxInterface
{
    static LxResult
  Test (LXtObjectID wcom, const char *fromType, const char *toType)
  {
    LXCWxINST (CLxImpl_ValueConversion, loc);
    try {
      return loc->conv_Test (fromType,toType);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Convert (LXtObjectID wcom, LXtObjectID from, const char *fromType, LXtObjectID to, const char *toType)
  {
    LXCWxINST (CLxImpl_ValueConversion, loc);
    try {
      return loc->conv_Convert ((ILxUnknownID)from,fromType,(ILxUnknownID)to,toType);
    } catch (LxResult rc) { return rc; }
  }
  ILxValueConversion vt;
public:
  CLxIfc_ValueConversion ()
  {
    vt.Test = Test;
    vt.Convert = Convert;
    vTable = &vt.iunk;
    iid = &lx::guid_ValueConversion;
  }
};
class CLxLoc_ValueConversion : public CLxLocalize<ILxValueConversionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueConversion() {_init();}
  CLxLoc_ValueConversion(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ValueConversion(const CLxLoc_ValueConversion &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ValueConversion;}
    LxResult
  Test (const char *fromType, const char *toType)
  {
    return m_loc[0]->Test (m_loc,fromType,toType);
  }
    LxResult
  Convert (ILxUnknownID from, const char *fromType, ILxUnknownID to, const char *toType)
  {
    return m_loc[0]->Convert (m_loc,(ILxUnknownID)from,fromType,(ILxUnknownID)to,toType);
  }
};


class CLxImpl_Visitor {
  public:
    virtual ~CLxImpl_Visitor() {}
    virtual LxResult
      vis_Evaluate (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_Visitor_Evaluate LxResult vis_Evaluate (void)
#define LXxO_Visitor_Evaluate LXxD_Visitor_Evaluate LXx_OVERRIDE
#define LXxC_Visitor_Evaluate(c) LxResult c::vis_Evaluate (void)
template <class T>
class CLxIfc_Visitor : public CLxInterface
{
    static LxResult
  Evaluate (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Visitor, loc);
    try {
      return loc->vis_Evaluate ();
    } catch (LxResult rc) { return rc; }
  }
  ILxVisitor vt;
public:
  CLxIfc_Visitor ()
  {
    vt.Evaluate = Evaluate;
    vTable = &vt.iunk;
    iid = &lx::guid_Visitor;
  }
};
class CLxLoc_Visitor : public CLxLocalize<ILxVisitorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Visitor() {_init();}
  CLxLoc_Visitor(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Visitor(const CLxLoc_Visitor &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Visitor;}
    LxResult
  Evaluate (void)
  {
    return m_loc[0]->Evaluate (m_loc);
  }
};

class CLxImpl_ValueArray {
  public:
    virtual ~CLxImpl_ValueArray() {}
    virtual LxResult
      va_Type (unsigned int *type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_TypeName (const char **name)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      va_Count (void)
        = 0;
    virtual LxResult
      va_AddEmptyValue (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_AddValue (ILxUnknownID value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_AddInt (int value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_AddFloat (double value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_AddString (const char *value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_GetValue (unsigned int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_GetInt (unsigned int index, int *value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_GetFloat (unsigned int index, double *value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_GetString (unsigned int index, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_FirstUnique (unsigned int *uniqueIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_Reset (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_Remove (unsigned int index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_SetValue (unsigned int index, ILxUnknownID value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_SetInt (unsigned int index, int value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_SetFloat (unsigned int index, double value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_SetString (unsigned int index, const char *value)
        { return LXe_NOTIMPL; }
};
#define LXxD_ValueArray_Type LxResult va_Type (unsigned int *type)
#define LXxO_ValueArray_Type LXxD_ValueArray_Type LXx_OVERRIDE
#define LXxC_ValueArray_Type(c) LxResult c::va_Type (unsigned int *type)
#define LXxD_ValueArray_TypeName LxResult va_TypeName (const char **name)
#define LXxO_ValueArray_TypeName LXxD_ValueArray_TypeName LXx_OVERRIDE
#define LXxC_ValueArray_TypeName(c) LxResult c::va_TypeName (const char **name)
#define LXxD_ValueArray_Count unsigned int va_Count (void)
#define LXxO_ValueArray_Count LXxD_ValueArray_Count LXx_OVERRIDE
#define LXxC_ValueArray_Count(c) unsigned int c::va_Count (void)
#define LXxD_ValueArray_AddEmptyValue LxResult va_AddEmptyValue (void **ppvObj)
#define LXxO_ValueArray_AddEmptyValue LXxD_ValueArray_AddEmptyValue LXx_OVERRIDE
#define LXxC_ValueArray_AddEmptyValue(c) LxResult c::va_AddEmptyValue (void **ppvObj)
#define LXxD_ValueArray_AddValue LxResult va_AddValue (ILxUnknownID value)
#define LXxO_ValueArray_AddValue LXxD_ValueArray_AddValue LXx_OVERRIDE
#define LXxC_ValueArray_AddValue(c) LxResult c::va_AddValue (ILxUnknownID value)
#define LXxD_ValueArray_AddInt LxResult va_AddInt (int value)
#define LXxO_ValueArray_AddInt LXxD_ValueArray_AddInt LXx_OVERRIDE
#define LXxC_ValueArray_AddInt(c) LxResult c::va_AddInt (int value)
#define LXxD_ValueArray_AddFloat LxResult va_AddFloat (double value)
#define LXxO_ValueArray_AddFloat LXxD_ValueArray_AddFloat LXx_OVERRIDE
#define LXxC_ValueArray_AddFloat(c) LxResult c::va_AddFloat (double value)
#define LXxD_ValueArray_AddString LxResult va_AddString (const char *value)
#define LXxO_ValueArray_AddString LXxD_ValueArray_AddString LXx_OVERRIDE
#define LXxC_ValueArray_AddString(c) LxResult c::va_AddString (const char *value)
#define LXxD_ValueArray_GetValue LxResult va_GetValue (unsigned int index, void **ppvObj)
#define LXxO_ValueArray_GetValue LXxD_ValueArray_GetValue LXx_OVERRIDE
#define LXxC_ValueArray_GetValue(c) LxResult c::va_GetValue (unsigned int index, void **ppvObj)
#define LXxD_ValueArray_GetInt LxResult va_GetInt (unsigned int index, int *value)
#define LXxO_ValueArray_GetInt LXxD_ValueArray_GetInt LXx_OVERRIDE
#define LXxC_ValueArray_GetInt(c) LxResult c::va_GetInt (unsigned int index, int *value)
#define LXxD_ValueArray_GetFloat LxResult va_GetFloat (unsigned int index, double *value)
#define LXxO_ValueArray_GetFloat LXxD_ValueArray_GetFloat LXx_OVERRIDE
#define LXxC_ValueArray_GetFloat(c) LxResult c::va_GetFloat (unsigned int index, double *value)
#define LXxD_ValueArray_GetString LxResult va_GetString (unsigned int index, char *buf, unsigned len)
#define LXxO_ValueArray_GetString LXxD_ValueArray_GetString LXx_OVERRIDE
#define LXxC_ValueArray_GetString(c) LxResult c::va_GetString (unsigned int index, char *buf, unsigned len)
#define LXxD_ValueArray_FirstUnique LxResult va_FirstUnique (unsigned int *uniqueIndex)
#define LXxO_ValueArray_FirstUnique LXxD_ValueArray_FirstUnique LXx_OVERRIDE
#define LXxC_ValueArray_FirstUnique(c) LxResult c::va_FirstUnique (unsigned int *uniqueIndex)
#define LXxD_ValueArray_Reset LxResult va_Reset (void)
#define LXxO_ValueArray_Reset LXxD_ValueArray_Reset LXx_OVERRIDE
#define LXxC_ValueArray_Reset(c) LxResult c::va_Reset (void)
#define LXxD_ValueArray_Remove LxResult va_Remove (unsigned int index)
#define LXxO_ValueArray_Remove LXxD_ValueArray_Remove LXx_OVERRIDE
#define LXxC_ValueArray_Remove(c) LxResult c::va_Remove (unsigned int index)
#define LXxD_ValueArray_SetValue LxResult va_SetValue (unsigned int index, ILxUnknownID value)
#define LXxO_ValueArray_SetValue LXxD_ValueArray_SetValue LXx_OVERRIDE
#define LXxC_ValueArray_SetValue(c) LxResult c::va_SetValue (unsigned int index, ILxUnknownID value)
#define LXxD_ValueArray_SetInt LxResult va_SetInt (unsigned int index, int value)
#define LXxO_ValueArray_SetInt LXxD_ValueArray_SetInt LXx_OVERRIDE
#define LXxC_ValueArray_SetInt(c) LxResult c::va_SetInt (unsigned int index, int value)
#define LXxD_ValueArray_SetFloat LxResult va_SetFloat (unsigned int index, double value)
#define LXxO_ValueArray_SetFloat LXxD_ValueArray_SetFloat LXx_OVERRIDE
#define LXxC_ValueArray_SetFloat(c) LxResult c::va_SetFloat (unsigned int index, double value)
#define LXxD_ValueArray_SetString LxResult va_SetString (unsigned int index, const char *value)
#define LXxO_ValueArray_SetString LXxD_ValueArray_SetString LXx_OVERRIDE
#define LXxC_ValueArray_SetString(c) LxResult c::va_SetString (unsigned int index, const char *value)
template <class T>
class CLxIfc_ValueArray : public CLxInterface
{
    static LxResult
  Type (LXtObjectID wcom, unsigned int *type)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_Type (type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TypeName (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_TypeName (name);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    return loc->va_Count ();
  }
    static LxResult
  AddEmptyValue (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_AddEmptyValue (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddValue (LXtObjectID wcom, LXtObjectID value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_AddValue ((ILxUnknownID)value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddInt (LXtObjectID wcom, int value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_AddInt (value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddFloat (LXtObjectID wcom, double value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_AddFloat (value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddString (LXtObjectID wcom, const char *value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_AddString (value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetValue (LXtObjectID wcom, unsigned int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_GetValue (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetInt (LXtObjectID wcom, unsigned int index, int *value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_GetInt (index,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetFloat (LXtObjectID wcom, unsigned int index, double *value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_GetFloat (index,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetString (LXtObjectID wcom, unsigned int index, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_GetString (index,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FirstUnique (LXtObjectID wcom, unsigned int *uniqueIndex)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_FirstUnique (uniqueIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Reset (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_Reset ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Remove (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_Remove (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetValue (LXtObjectID wcom, unsigned int index, LXtObjectID value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_SetValue (index,(ILxUnknownID)value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetInt (LXtObjectID wcom, unsigned int index, int value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_SetInt (index,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetFloat (LXtObjectID wcom, unsigned int index, double value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_SetFloat (index,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetString (LXtObjectID wcom, unsigned int index, const char *value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_SetString (index,value);
    } catch (LxResult rc) { return rc; }
  }
  ILxValueArray vt;
public:
  CLxIfc_ValueArray ()
  {
    vt.Type = Type;
    vt.TypeName = TypeName;
    vt.Count = Count;
    vt.AddEmptyValue = AddEmptyValue;
    vt.AddValue = AddValue;
    vt.AddInt = AddInt;
    vt.AddFloat = AddFloat;
    vt.AddString = AddString;
    vt.GetValue = GetValue;
    vt.GetInt = GetInt;
    vt.GetFloat = GetFloat;
    vt.GetString = GetString;
    vt.FirstUnique = FirstUnique;
    vt.Reset = Reset;
    vt.Remove = Remove;
    vt.SetValue = SetValue;
    vt.SetInt = SetInt;
    vt.SetFloat = SetFloat;
    vt.SetString = SetString;
    vTable = &vt.iunk;
    iid = &lx::guid_ValueArray;
  }
};
class CLxLoc_ValueArray : public CLxLocalize<ILxValueArrayID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueArray() {_init();}
  CLxLoc_ValueArray(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ValueArray(const CLxLoc_ValueArray &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ValueArray;}
    LxResult
  Type (unsigned int *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  TypeName (const char **name)
  {
    return m_loc[0]->TypeName (m_loc,name);
  }
    unsigned int
  Count (void)
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  AddEmptyValue (void **ppvObj)
  {
    return m_loc[0]->AddEmptyValue (m_loc,ppvObj);
  }
    CLxResult
  AddEmptyValue (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AddEmptyValue(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AddValue (ILxUnknownID value)
  {
    return m_loc[0]->AddValue (m_loc,(ILxUnknownID)value);
  }
    LxResult
  AddInt (int value)
  {
    return m_loc[0]->AddInt (m_loc,value);
  }
    LxResult
  AddFloat (double value)
  {
    return m_loc[0]->AddFloat (m_loc,value);
  }
    LxResult
  AddString (const char *value)
  {
    return m_loc[0]->AddString (m_loc,value);
  }
    LxResult
  GetValue (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->GetValue (m_loc,index,ppvObj);
  }
    CLxResult
  GetValue (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetValue(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetInt (unsigned int index, int *value)
  {
    return m_loc[0]->GetInt (m_loc,index,value);
  }
    LxResult
  GetFloat (unsigned int index, double *value)
  {
    return m_loc[0]->GetFloat (m_loc,index,value);
  }
    LxResult
  GetString (unsigned int index, char *buf, unsigned len)
  {
    return m_loc[0]->GetString (m_loc,index,buf,len);
  }
    LxResult
  GetString (unsigned int index, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->GetString (m_loc,index,buf,len);
    LXWx_SBUF2
  }
    LxResult
  FirstUnique (unsigned int *uniqueIndex)
  {
    return m_loc[0]->FirstUnique (m_loc,uniqueIndex);
  }
    LxResult
  Reset (void)
  {
    return m_loc[0]->Reset (m_loc);
  }
    LxResult
  Remove (unsigned int index)
  {
    return m_loc[0]->Remove (m_loc,index);
  }
    LxResult
  SetValue (unsigned int index, ILxUnknownID value)
  {
    return m_loc[0]->SetValue (m_loc,index,(ILxUnknownID)value);
  }
    LxResult
  SetInt (unsigned int index, int value)
  {
    return m_loc[0]->SetInt (m_loc,index,value);
  }
    LxResult
  SetFloat (unsigned int index, double value)
  {
    return m_loc[0]->SetFloat (m_loc,index,value);
  }
    LxResult
  SetString (unsigned int index, const char *value)
  {
    return m_loc[0]->SetString (m_loc,index,value);
  }
};


class CLxImpl_Message {
  public:
    virtual ~CLxImpl_Message() {}
    virtual LxResult
      msg_Code (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetCode (LxResult code)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetMessage (const char *table, const char *name, unsigned id)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetArgumentInt (unsigned arg, int value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetArgumentFloat (unsigned arg, double value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetArgumentString (unsigned arg, const char *string)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetArgumentObject (unsigned arg, ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_Reset (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_Table (const char **table)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetMessageResult (unsigned id)
        { return LXe_NOTIMPL; }
};
#define LXxD_Message_Code LxResult msg_Code (void)
#define LXxO_Message_Code LXxD_Message_Code LXx_OVERRIDE
#define LXxC_Message_Code(c) LxResult c::msg_Code (void)
#define LXxD_Message_SetCode LxResult msg_SetCode (LxResult code)
#define LXxO_Message_SetCode LXxD_Message_SetCode LXx_OVERRIDE
#define LXxC_Message_SetCode(c) LxResult c::msg_SetCode (LxResult code)
#define LXxD_Message_SetMessage LxResult msg_SetMessage (const char *table, const char *name, unsigned id)
#define LXxO_Message_SetMessage LXxD_Message_SetMessage LXx_OVERRIDE
#define LXxC_Message_SetMessage(c) LxResult c::msg_SetMessage (const char *table, const char *name, unsigned id)
#define LXxD_Message_SetArgumentInt LxResult msg_SetArgumentInt (unsigned arg, int value)
#define LXxO_Message_SetArgumentInt LXxD_Message_SetArgumentInt LXx_OVERRIDE
#define LXxC_Message_SetArgumentInt(c) LxResult c::msg_SetArgumentInt (unsigned arg, int value)
#define LXxD_Message_SetArgumentFloat LxResult msg_SetArgumentFloat (unsigned arg, double value)
#define LXxO_Message_SetArgumentFloat LXxD_Message_SetArgumentFloat LXx_OVERRIDE
#define LXxC_Message_SetArgumentFloat(c) LxResult c::msg_SetArgumentFloat (unsigned arg, double value)
#define LXxD_Message_SetArgumentString LxResult msg_SetArgumentString (unsigned arg, const char *string)
#define LXxO_Message_SetArgumentString LXxD_Message_SetArgumentString LXx_OVERRIDE
#define LXxC_Message_SetArgumentString(c) LxResult c::msg_SetArgumentString (unsigned arg, const char *string)
#define LXxD_Message_SetArgumentObject LxResult msg_SetArgumentObject (unsigned arg, ILxUnknownID object)
#define LXxO_Message_SetArgumentObject LXxD_Message_SetArgumentObject LXx_OVERRIDE
#define LXxC_Message_SetArgumentObject(c) LxResult c::msg_SetArgumentObject (unsigned arg, ILxUnknownID object)
#define LXxD_Message_Reset LxResult msg_Reset (void)
#define LXxO_Message_Reset LXxD_Message_Reset LXx_OVERRIDE
#define LXxC_Message_Reset(c) LxResult c::msg_Reset (void)
#define LXxD_Message_Table LxResult msg_Table (const char **table)
#define LXxO_Message_Table LXxD_Message_Table LXx_OVERRIDE
#define LXxC_Message_Table(c) LxResult c::msg_Table (const char **table)
#define LXxD_Message_Name LxResult msg_Name (const char **name)
#define LXxO_Message_Name LXxD_Message_Name LXx_OVERRIDE
#define LXxC_Message_Name(c) LxResult c::msg_Name (const char **name)
#define LXxD_Message_SetMessageResult LxResult msg_SetMessageResult (unsigned id)
#define LXxO_Message_SetMessageResult LXxD_Message_SetMessageResult LXx_OVERRIDE
#define LXxC_Message_SetMessageResult(c) LxResult c::msg_SetMessageResult (unsigned id)
template <class T>
class CLxIfc_Message : public CLxInterface
{
    static LxResult
  Code (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_Code ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetCode (LXtObjectID wcom, LxResult code)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetCode (code);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetMessage (LXtObjectID wcom, const char *table, const char *name, unsigned id)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetMessage (table,name,id);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetArgumentInt (LXtObjectID wcom, unsigned arg, int value)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetArgumentInt (arg,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetArgumentFloat (LXtObjectID wcom, unsigned arg, double value)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetArgumentFloat (arg,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetArgumentString (LXtObjectID wcom, unsigned arg, const char *string)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetArgumentString (arg,string);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetArgumentObject (LXtObjectID wcom, unsigned arg, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetArgumentObject (arg,(ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Reset (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_Reset ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Table (LXtObjectID wcom, const char **table)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_Table (table);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetMessageResult (LXtObjectID wcom, unsigned id)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetMessageResult (id);
    } catch (LxResult rc) { return rc; }
  }
  ILxMessage vt;
public:
  CLxIfc_Message ()
  {
    vt.Code = Code;
    vt.SetCode = SetCode;
    vt.SetMessage = SetMessage;
    vt.SetArgumentInt = SetArgumentInt;
    vt.SetArgumentFloat = SetArgumentFloat;
    vt.SetArgumentString = SetArgumentString;
    vt.SetArgumentObject = SetArgumentObject;
    vt.Reset = Reset;
    vt.Table = Table;
    vt.Name = Name;
    vt.SetMessageResult = SetMessageResult;
    vTable = &vt.iunk;
    iid = &lx::guid_Message;
  }
};
class CLxLoc_Message : public CLxLocalize<ILxMessageID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Message() {_init();}
  CLxLoc_Message(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Message(const CLxLoc_Message &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Message;}
    LxResult
  Code (void)
  {
    return m_loc[0]->Code (m_loc);
  }
    LxResult
  SetCode (LxResult code)
  {
    return m_loc[0]->SetCode (m_loc,code);
  }
    LxResult
  SetMessage (const char *table, const char *name, unsigned id)
  {
    return m_loc[0]->SetMessage (m_loc,table,name,id);
  }
    LxResult
  SetArgumentInt (unsigned arg, int value)
  {
    return m_loc[0]->SetArgumentInt (m_loc,arg,value);
  }
    LxResult
  SetArgumentFloat (unsigned arg, double value)
  {
    return m_loc[0]->SetArgumentFloat (m_loc,arg,value);
  }
    LxResult
  SetArgumentString (unsigned arg, const char *string)
  {
    return m_loc[0]->SetArgumentString (m_loc,arg,string);
  }
    LxResult
  SetArgumentObject (unsigned arg, ILxUnknownID object)
  {
    return m_loc[0]->SetArgumentObject (m_loc,arg,(ILxUnknownID)object);
  }
    LxResult
  Reset (void)
  {
    return m_loc[0]->Reset (m_loc);
  }
    LxResult
  Table (const char **table)
  {
    return m_loc[0]->Table (m_loc,table);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  SetMessageResult (unsigned id)
  {
    return m_loc[0]->SetMessageResult (m_loc,id);
  }
};

class CLxImpl_Attributes {
  public:
    virtual ~CLxImpl_Attributes() {}
    virtual unsigned int
      attr_Count (void)
        { return 0; }
    virtual LxResult
      attr_Name (unsigned int index, const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_Lookup (const char *name, unsigned int *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_Type (unsigned int index, unsigned int *type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_TypeName (unsigned int index, const char **tname)
        { return LXe_NOTIMPL; }
    virtual const LXtTextValueHint *
      attr_Hints (unsigned int index)
        { return 0; }
    virtual LxResult
      attr_Value (unsigned int index, void **ppvObj, int writeOK)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_GetInt (unsigned int index, int *val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_SetInt (unsigned int index, int val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_GetFlt (unsigned int index, double *val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_SetFlt (unsigned int index, double val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_GetString (unsigned int index, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_SetString (unsigned int index, const char *val)
        { return LXe_NOTIMPL; }
};
#define LXxD_Attributes_Count unsigned int attr_Count (void)
#define LXxO_Attributes_Count LXxD_Attributes_Count LXx_OVERRIDE
#define LXxC_Attributes_Count(c) unsigned int c::attr_Count (void)
#define LXxD_Attributes_Name LxResult attr_Name (unsigned int index, const char **name)
#define LXxO_Attributes_Name LXxD_Attributes_Name LXx_OVERRIDE
#define LXxC_Attributes_Name(c) LxResult c::attr_Name (unsigned int index, const char **name)
#define LXxD_Attributes_Lookup LxResult attr_Lookup (const char *name, unsigned int *index)
#define LXxO_Attributes_Lookup LXxD_Attributes_Lookup LXx_OVERRIDE
#define LXxC_Attributes_Lookup(c) LxResult c::attr_Lookup (const char *name, unsigned int *index)
#define LXxD_Attributes_Type LxResult attr_Type (unsigned int index, unsigned int *type)
#define LXxO_Attributes_Type LXxD_Attributes_Type LXx_OVERRIDE
#define LXxC_Attributes_Type(c) LxResult c::attr_Type (unsigned int index, unsigned int *type)
#define LXxD_Attributes_TypeName LxResult attr_TypeName (unsigned int index, const char **tname)
#define LXxO_Attributes_TypeName LXxD_Attributes_TypeName LXx_OVERRIDE
#define LXxC_Attributes_TypeName(c) LxResult c::attr_TypeName (unsigned int index, const char **tname)
#define LXxD_Attributes_Hints const LXtTextValueHint * attr_Hints (unsigned int index)
#define LXxO_Attributes_Hints LXxD_Attributes_Hints LXx_OVERRIDE
#define LXxC_Attributes_Hints(c) const LXtTextValueHint * c::attr_Hints (unsigned int index)
#define LXxD_Attributes_Value LxResult attr_Value (unsigned int index, void **ppvObj, int writeOK)
#define LXxO_Attributes_Value LXxD_Attributes_Value LXx_OVERRIDE
#define LXxC_Attributes_Value(c) LxResult c::attr_Value (unsigned int index, void **ppvObj, int writeOK)
#define LXxD_Attributes_GetInt LxResult attr_GetInt (unsigned int index, int *val)
#define LXxO_Attributes_GetInt LXxD_Attributes_GetInt LXx_OVERRIDE
#define LXxC_Attributes_GetInt(c) LxResult c::attr_GetInt (unsigned int index, int *val)
#define LXxD_Attributes_SetInt LxResult attr_SetInt (unsigned int index, int val)
#define LXxO_Attributes_SetInt LXxD_Attributes_SetInt LXx_OVERRIDE
#define LXxC_Attributes_SetInt(c) LxResult c::attr_SetInt (unsigned int index, int val)
#define LXxD_Attributes_GetFlt LxResult attr_GetFlt (unsigned int index, double *val)
#define LXxO_Attributes_GetFlt LXxD_Attributes_GetFlt LXx_OVERRIDE
#define LXxC_Attributes_GetFlt(c) LxResult c::attr_GetFlt (unsigned int index, double *val)
#define LXxD_Attributes_SetFlt LxResult attr_SetFlt (unsigned int index, double val)
#define LXxO_Attributes_SetFlt LXxD_Attributes_SetFlt LXx_OVERRIDE
#define LXxC_Attributes_SetFlt(c) LxResult c::attr_SetFlt (unsigned int index, double val)
#define LXxD_Attributes_GetString LxResult attr_GetString (unsigned int index, char *buf, unsigned len)
#define LXxO_Attributes_GetString LXxD_Attributes_GetString LXx_OVERRIDE
#define LXxC_Attributes_GetString(c) LxResult c::attr_GetString (unsigned int index, char *buf, unsigned len)
#define LXxD_Attributes_SetString LxResult attr_SetString (unsigned int index, const char *val)
#define LXxO_Attributes_SetString LXxD_Attributes_SetString LXx_OVERRIDE
#define LXxC_Attributes_SetString(c) LxResult c::attr_SetString (unsigned int index, const char *val)
template <class T>
class CLxIfc_Attributes : public CLxInterface
{
    static unsigned int
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    return loc->attr_Count ();
  }
    static LxResult
  Name (LXtObjectID wcom, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_Name (index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Lookup (LXtObjectID wcom, const char *name, unsigned int *index)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_Lookup (name,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Type (LXtObjectID wcom, unsigned int index, unsigned int *type)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_Type (index,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TypeName (LXtObjectID wcom, unsigned int index, const char **tname)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_TypeName (index,tname);
    } catch (LxResult rc) { return rc; }
  }
    static const LXtTextValueHint *
  Hints (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    return loc->attr_Hints (index);
  }
    static LxResult
  Value (LXtObjectID wcom, unsigned int index, void **ppvObj, int writeOK)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_Value (index,ppvObj,writeOK);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetInt (LXtObjectID wcom, unsigned int index, int *val)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_GetInt (index,val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetInt (LXtObjectID wcom, unsigned int index, int val)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_SetInt (index,val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetFlt (LXtObjectID wcom, unsigned int index, double *val)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_GetFlt (index,val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetFlt (LXtObjectID wcom, unsigned int index, double val)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_SetFlt (index,val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetString (LXtObjectID wcom, unsigned int index, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_GetString (index,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetString (LXtObjectID wcom, unsigned int index, const char *val)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_SetString (index,val);
    } catch (LxResult rc) { return rc; }
  }
  ILxAttributes vt;
public:
  CLxIfc_Attributes ()
  {
    vt.Count = Count;
    vt.Name = Name;
    vt.Lookup = Lookup;
    vt.Type = Type;
    vt.TypeName = TypeName;
    vt.Hints = Hints;
    vt.Value = Value;
    vt.GetInt = GetInt;
    vt.SetInt = SetInt;
    vt.GetFlt = GetFlt;
    vt.SetFlt = SetFlt;
    vt.GetString = GetString;
    vt.SetString = SetString;
    vTable = &vt.iunk;
    iid = &lx::guid_Attributes;
  }
};
class CLxLoc_Attributes : public CLxLocalize<ILxAttributesID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Attributes() {_init();}
  CLxLoc_Attributes(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Attributes(const CLxLoc_Attributes &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Attributes;}
    unsigned int
  Count (void) const
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  Name (unsigned int index, const char **name) const
  {
    return m_loc[0]->Name (m_loc,index,name);
  }
    LxResult
  Lookup (const char *name, unsigned int *index) const
  {
    return m_loc[0]->Lookup (m_loc,name,index);
  }
    LxResult
  Type (unsigned int index, unsigned int *type) const
  {
    return m_loc[0]->Type (m_loc,index,type);
  }
    LxResult
  TypeName (unsigned int index, const char **tname) const
  {
    return m_loc[0]->TypeName (m_loc,index,tname);
  }
    const LXtTextValueHint *
  Hints (unsigned int index) const
  {
    return m_loc[0]->Hints (m_loc,index);
  }
    LxResult
  Value (unsigned int index, void **ppvObj, int writeOK)
  {
    return m_loc[0]->Value (m_loc,index,ppvObj,writeOK);
  }
    CLxResult
  Value (unsigned int index, CLxLocalizedObject &o_dest, int writeOK)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Value(m_loc,index,&o_obj,writeOK);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetInt (unsigned int index, int *val) const
  {
    return m_loc[0]->GetInt (m_loc,index,val);
  }
    LxResult
  SetInt (unsigned int index, int val)
  {
    return m_loc[0]->SetInt (m_loc,index,val);
  }
    LxResult
  GetFlt (unsigned int index, double *val) const
  {
    return m_loc[0]->GetFlt (m_loc,index,val);
  }
    LxResult
  SetFlt (unsigned int index, double val)
  {
    return m_loc[0]->SetFlt (m_loc,index,val);
  }
    LxResult
  GetString (unsigned int index, char *buf, unsigned len) const
  {
    return m_loc[0]->GetString (m_loc,index,buf,len);
  }
    LxResult
  GetString (unsigned int index, std::string &result) const
  {
    LXWx_SBUF1
    rc = m_loc[0]->GetString (m_loc,index,buf,len);
    LXWx_SBUF2
  }
    LxResult
  SetString (unsigned int index, const char *val)
  {
    return m_loc[0]->SetString (m_loc,index,val);
  }
};

class CLxLoc_ValueService : public CLxLocalizedService
{
public:
  ILxValueServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_ValueService() {_init();set();}
 ~CLxLoc_ValueService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxValueServiceID>(lx::GetGlobal(&lx::guid_ValueService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    CLxResult
  ScriptQuery (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ScriptQuery(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  TextHintEncode (int value, const LXtTextValueHint *hint, char *buf, unsigned len)
  {
    return m_loc[0]->TextHintEncode (m_loc,value,hint,buf,len);
  }
    LxResult
  TextHintEncode (int value, const LXtTextValueHint *hint, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->TextHintEncode (m_loc,value,hint,buf,len);
    LXWx_SBUF2
  }
    LxResult
  TextHintDecode (const char *buf, const LXtTextValueHint *hint, int *value)
  {
    return m_loc[0]->TextHintDecode (m_loc,buf,hint,value);
  }
    LxResult
  CreateValue (const char *type, void **ppvObj)
  {
    return m_loc[0]->CreateValue (m_loc,type,ppvObj);
  }
    CLxResult
  CreateValue (const char *type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateValue(m_loc,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ValueType (const char *type, unsigned *valType)
  {
    return m_loc[0]->ValueType (m_loc,type,valType);
  }
    LxResult
  TextHintDuplicate (const LXtTextValueHint *hint, LXtTextValueHint **copy)
  {
    return m_loc[0]->TextHintDuplicate (m_loc,hint,copy);
  }
    LxResult
  TextHintFreeDuplicate (LXtTextValueHint *copy)
  {
    return m_loc[0]->TextHintFreeDuplicate (m_loc,copy);
  }
    int
  FloatType (float val)
  {
    return m_loc[0]->FloatType (m_loc,val);
  }
    double
  GetFPS (void)
  {
    return m_loc[0]->GetFPS (m_loc);
  }
    double
  TimeToFrame (double time)
  {
    return m_loc[0]->TimeToFrame (m_loc,time);
  }
    double
  FrameToTime (double frame)
  {
    return m_loc[0]->FrameToTime (m_loc,frame);
  }
    double
  TimeToFrameFPS (double time, double fps)
  {
    return m_loc[0]->TimeToFrameFPS (m_loc,time,fps);
  }
    double
  FrameToTimeFPS (double frame, double fps)
  {
    return m_loc[0]->FrameToTimeFPS (m_loc,frame,fps);
  }
    LxResult
  ConvertValues (const char *from, const char *to, void **ppvObj)
  {
    return m_loc[0]->ConvertValues (m_loc,from,to,ppvObj);
  }
    CLxResult
  ConvertValues (const char *from, const char *to, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ConvertValues(m_loc,from,to,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_Value {
  public:
    virtual ~CLxImpl_Value() {}
    virtual LxResult
      val_Clone (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_Copy (ILxUnknownID from)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_Compare (ILxUnknownID other, int *diff)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      val_Type (void)
        = 0;
    virtual LxResult
      val_TypeName (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_SubTypeName (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_GetInt (int *val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_SetInt (int val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_GetFlt (double *val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_SetFlt (double val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_GetString (char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_SetString (const char *val)
        { return LXe_NOTIMPL; }
    virtual void *
      val_Intrinsic (void)
        { return 0; }
};
#define LXxD_Value_Clone LxResult val_Clone (void **ppvObj)
#define LXxO_Value_Clone LXxD_Value_Clone LXx_OVERRIDE
#define LXxC_Value_Clone(c) LxResult c::val_Clone (void **ppvObj)
#define LXxD_Value_Copy LxResult val_Copy (ILxUnknownID from)
#define LXxO_Value_Copy LXxD_Value_Copy LXx_OVERRIDE
#define LXxC_Value_Copy(c) LxResult c::val_Copy (ILxUnknownID from)
#define LXxD_Value_Compare LxResult val_Compare (ILxUnknownID other, int *diff)
#define LXxO_Value_Compare LXxD_Value_Compare LXx_OVERRIDE
#define LXxC_Value_Compare(c) LxResult c::val_Compare (ILxUnknownID other, int *diff)
#define LXxD_Value_Type unsigned int val_Type (void)
#define LXxO_Value_Type LXxD_Value_Type LXx_OVERRIDE
#define LXxC_Value_Type(c) unsigned int c::val_Type (void)
#define LXxD_Value_TypeName LxResult val_TypeName (const char **name)
#define LXxO_Value_TypeName LXxD_Value_TypeName LXx_OVERRIDE
#define LXxC_Value_TypeName(c) LxResult c::val_TypeName (const char **name)
#define LXxD_Value_SubTypeName LxResult val_SubTypeName (const char **name)
#define LXxO_Value_SubTypeName LXxD_Value_SubTypeName LXx_OVERRIDE
#define LXxC_Value_SubTypeName(c) LxResult c::val_SubTypeName (const char **name)
#define LXxD_Value_GetInt LxResult val_GetInt (int *val)
#define LXxO_Value_GetInt LXxD_Value_GetInt LXx_OVERRIDE
#define LXxC_Value_GetInt(c) LxResult c::val_GetInt (int *val)
#define LXxD_Value_SetInt LxResult val_SetInt (int val)
#define LXxO_Value_SetInt LXxD_Value_SetInt LXx_OVERRIDE
#define LXxC_Value_SetInt(c) LxResult c::val_SetInt (int val)
#define LXxD_Value_GetFlt LxResult val_GetFlt (double *val)
#define LXxO_Value_GetFlt LXxD_Value_GetFlt LXx_OVERRIDE
#define LXxC_Value_GetFlt(c) LxResult c::val_GetFlt (double *val)
#define LXxD_Value_SetFlt LxResult val_SetFlt (double val)
#define LXxO_Value_SetFlt LXxD_Value_SetFlt LXx_OVERRIDE
#define LXxC_Value_SetFlt(c) LxResult c::val_SetFlt (double val)
#define LXxD_Value_GetString LxResult val_GetString (char *buf, unsigned len)
#define LXxO_Value_GetString LXxD_Value_GetString LXx_OVERRIDE
#define LXxC_Value_GetString(c) LxResult c::val_GetString (char *buf, unsigned len)
#define LXxD_Value_SetString LxResult val_SetString (const char *val)
#define LXxO_Value_SetString LXxD_Value_SetString LXx_OVERRIDE
#define LXxC_Value_SetString(c) LxResult c::val_SetString (const char *val)
#define LXxD_Value_Intrinsic void * val_Intrinsic (void)
#define LXxO_Value_Intrinsic LXxD_Value_Intrinsic LXx_OVERRIDE
#define LXxC_Value_Intrinsic(c) void * c::val_Intrinsic (void)
template <class T>
class CLxIfc_Value : public CLxInterface
{
    static LxResult
  Clone (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_Clone (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Copy (LXtObjectID wcom, LXtObjectID from)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_Copy ((ILxUnknownID)from);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Compare (LXtObjectID wcom, LXtObjectID other, int *diff)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_Compare ((ILxUnknownID)other,diff);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Value, loc);
    return loc->val_Type ();
  }
    static LxResult
  TypeName (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_TypeName (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SubTypeName (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_SubTypeName (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetInt (LXtObjectID wcom, int *val)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_GetInt (val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetInt (LXtObjectID wcom, int val)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_SetInt (val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetFlt (LXtObjectID wcom, double *val)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_GetFlt (val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetFlt (LXtObjectID wcom, double val)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_SetFlt (val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetString (LXtObjectID wcom, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_GetString (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetString (LXtObjectID wcom, const char *val)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_SetString (val);
    } catch (LxResult rc) { return rc; }
  }
    static void *
  Intrinsic (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Value, loc);
    return loc->val_Intrinsic ();
  }
  ILxValue vt;
public:
  CLxIfc_Value ()
  {
    vt.Clone = Clone;
    vt.Copy = Copy;
    vt.Compare = Compare;
    vt.Type = Type;
    vt.TypeName = TypeName;
    vt.SubTypeName = SubTypeName;
    vt.GetInt = GetInt;
    vt.SetInt = SetInt;
    vt.GetFlt = GetFlt;
    vt.SetFlt = SetFlt;
    vt.GetString = GetString;
    vt.SetString = SetString;
    vt.Intrinsic = Intrinsic;
    vTable = &vt.iunk;
    iid = &lx::guid_Value;
  }
};
class CLxLoc_Value : public CLxLocalize<ILxValueID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Value() {_init();}
  CLxLoc_Value(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Value(const CLxLoc_Value &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Value;}
    LxResult
  Clone (void **ppvObj)
  {
    return m_loc[0]->Clone (m_loc,ppvObj);
  }
    CLxResult
  Clone (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Clone(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Copy (ILxUnknownID from)
  {
    return m_loc[0]->Copy (m_loc,(ILxUnknownID)from);
  }
    LxResult
  Compare (ILxUnknownID other, int *diff) const
  {
    return m_loc[0]->Compare (m_loc,(ILxUnknownID)other,diff);
  }
    unsigned int
  Type (void) const
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  TypeName (const char **name)
  {
    return m_loc[0]->TypeName (m_loc,name);
  }
    LxResult
  SubTypeName (const char **name)
  {
    return m_loc[0]->SubTypeName (m_loc,name);
  }
    LxResult
  GetInt (int *val) const
  {
    return m_loc[0]->GetInt (m_loc,val);
  }
    LxResult
  SetInt (int val)
  {
    return m_loc[0]->SetInt (m_loc,val);
  }
    LxResult
  GetFlt (double *val) const
  {
    return m_loc[0]->GetFlt (m_loc,val);
  }
    LxResult
  SetFlt (double val)
  {
    return m_loc[0]->SetFlt (m_loc,val);
  }
    LxResult
  GetString (char *buf, unsigned len) const
  {
    return m_loc[0]->GetString (m_loc,buf,len);
  }
    LxResult
  GetString (std::string &result) const
  {
    LXWx_SBUF1
    rc = m_loc[0]->GetString (m_loc,buf,len);
    LXWx_SBUF2
  }
    LxResult
  SetString (const char *val)
  {
    return m_loc[0]->SetString (m_loc,val);
  }
    void *
  Intrinsic (void) const
  {
    return m_loc[0]->Intrinsic (m_loc);
  }
};

class CLxImpl_StringTag {
  public:
    virtual ~CLxImpl_StringTag() {}
    virtual LxResult
      stag_Get (LXtID4 type, const char **tag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      stag_Set (LXtID4 type, const char *tag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      stag_Count (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      stag_ByIndex (unsigned int index, LXtID4 *type, const char **tag)
        { return LXe_NOTIMPL; }
};
#define LXxD_StringTag_Get LxResult stag_Get (LXtID4 type, const char **tag)
#define LXxO_StringTag_Get LXxD_StringTag_Get LXx_OVERRIDE
#define LXxC_StringTag_Get(c) LxResult c::stag_Get (LXtID4 type, const char **tag)
#define LXxD_StringTag_Set LxResult stag_Set (LXtID4 type, const char *tag)
#define LXxO_StringTag_Set LXxD_StringTag_Set LXx_OVERRIDE
#define LXxC_StringTag_Set(c) LxResult c::stag_Set (LXtID4 type, const char *tag)
#define LXxD_StringTag_Count LxResult stag_Count (unsigned int *count)
#define LXxO_StringTag_Count LXxD_StringTag_Count LXx_OVERRIDE
#define LXxC_StringTag_Count(c) LxResult c::stag_Count (unsigned int *count)
#define LXxD_StringTag_ByIndex LxResult stag_ByIndex (unsigned int index, LXtID4 *type, const char **tag)
#define LXxO_StringTag_ByIndex LXxD_StringTag_ByIndex LXx_OVERRIDE
#define LXxC_StringTag_ByIndex(c) LxResult c::stag_ByIndex (unsigned int index, LXtID4 *type, const char **tag)
template <class T>
class CLxIfc_StringTag : public CLxInterface
{
    static LxResult
  Get (LXtObjectID wcom, LXtID4 type, const char **tag)
  {
    LXCWxINST (CLxImpl_StringTag, loc);
    try {
      return loc->stag_Get (type,tag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Set (LXtObjectID wcom, LXtID4 type, const char *tag)
  {
    LXCWxINST (CLxImpl_StringTag, loc);
    try {
      return loc->stag_Set (type,tag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Count (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_StringTag, loc);
    try {
      return loc->stag_Count (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ByIndex (LXtObjectID wcom, unsigned int index, LXtID4 *type, const char **tag)
  {
    LXCWxINST (CLxImpl_StringTag, loc);
    try {
      return loc->stag_ByIndex (index,type,tag);
    } catch (LxResult rc) { return rc; }
  }
  ILxStringTag vt;
public:
  CLxIfc_StringTag ()
  {
    vt.Get = Get;
    vt.Set = Set;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_StringTag;
  }
};
class CLxLoc_StringTag : public CLxLocalize<ILxStringTagID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StringTag() {_init();}
  CLxLoc_StringTag(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StringTag(const CLxLoc_StringTag &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StringTag;}
    LxResult
  Get (LXtID4 type, const char **tag)
  {
    return m_loc[0]->Get (m_loc,type,tag);
  }
    LxResult
  Set (LXtID4 type, const char *tag)
  {
    return m_loc[0]->Set (m_loc,type,tag);
  }
    LxResult
  Count (unsigned int *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  ByIndex (unsigned int index, LXtID4 *type, const char **tag)
  {
    return m_loc[0]->ByIndex (m_loc,index,type,tag);
  }
};

class CLxImpl_ValueMath {
  public:
    virtual ~CLxImpl_ValueMath() {}
    virtual LxResult
      math_Step (int direction)
        { return LXe_NOTIMPL; }
    virtual int
      math_Detent (void)
        = 0;
    virtual LxResult
      math_Add (double delta)
        { return LXe_NOTIMPL; }
    virtual LxResult
      math_Multiply (double factor)
        { return LXe_NOTIMPL; }
    virtual LxResult
      math_Blend (ILxUnknownID other, double blend)
        { return LXe_NOTIMPL; }
};
#define LXxD_ValueMath_Step LxResult math_Step (int direction)
#define LXxO_ValueMath_Step LXxD_ValueMath_Step LXx_OVERRIDE
#define LXxC_ValueMath_Step(c) LxResult c::math_Step (int direction)
#define LXxD_ValueMath_Detent int math_Detent (void)
#define LXxO_ValueMath_Detent LXxD_ValueMath_Detent LXx_OVERRIDE
#define LXxC_ValueMath_Detent(c) int c::math_Detent (void)
#define LXxD_ValueMath_Add LxResult math_Add (double delta)
#define LXxO_ValueMath_Add LXxD_ValueMath_Add LXx_OVERRIDE
#define LXxC_ValueMath_Add(c) LxResult c::math_Add (double delta)
#define LXxD_ValueMath_Multiply LxResult math_Multiply (double factor)
#define LXxO_ValueMath_Multiply LXxD_ValueMath_Multiply LXx_OVERRIDE
#define LXxC_ValueMath_Multiply(c) LxResult c::math_Multiply (double factor)
#define LXxD_ValueMath_Blend LxResult math_Blend (ILxUnknownID other, double blend)
#define LXxO_ValueMath_Blend LXxD_ValueMath_Blend LXx_OVERRIDE
#define LXxC_ValueMath_Blend(c) LxResult c::math_Blend (ILxUnknownID other, double blend)
template <class T>
class CLxIfc_ValueMath : public CLxInterface
{
    static LxResult
  Step (LXtObjectID wcom, int direction)
  {
    LXCWxINST (CLxImpl_ValueMath, loc);
    try {
      return loc->math_Step (direction);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Detent (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ValueMath, loc);
    return loc->math_Detent ();
  }
    static LxResult
  Add (LXtObjectID wcom, double delta)
  {
    LXCWxINST (CLxImpl_ValueMath, loc);
    try {
      return loc->math_Add (delta);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Multiply (LXtObjectID wcom, double factor)
  {
    LXCWxINST (CLxImpl_ValueMath, loc);
    try {
      return loc->math_Multiply (factor);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Blend (LXtObjectID wcom, LXtObjectID other, double blend)
  {
    LXCWxINST (CLxImpl_ValueMath, loc);
    try {
      return loc->math_Blend ((ILxUnknownID)other,blend);
    } catch (LxResult rc) { return rc; }
  }
  ILxValueMath vt;
public:
  CLxIfc_ValueMath ()
  {
    vt.Step = Step;
    vt.Detent = Detent;
    vt.Add = Add;
    vt.Multiply = Multiply;
    vt.Blend = Blend;
    vTable = &vt.iunk;
    iid = &lx::guid_ValueMath;
  }
};
class CLxLoc_ValueMath : public CLxLocalize<ILxValueMathID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueMath() {_init();}
  CLxLoc_ValueMath(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ValueMath(const CLxLoc_ValueMath &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ValueMath;}
    LxResult
  Step (int direction)
  {
    return m_loc[0]->Step (m_loc,direction);
  }
    int
  Detent (void) const
  {
    return m_loc[0]->Detent (m_loc);
  }
    LxResult
  Add (double delta)
  {
    return m_loc[0]->Add (m_loc,delta);
  }
    LxResult
  Multiply (double factor)
  {
    return m_loc[0]->Multiply (m_loc,factor);
  }
    LxResult
  Blend (ILxUnknownID other, double blend)
  {
    return m_loc[0]->Blend (m_loc,(ILxUnknownID)other,blend);
  }
};

class CLxImpl_ScriptQuery {
  public:
    virtual ~CLxImpl_ScriptQuery() {}
    virtual LxResult
      sq_Select (const char *attribute, const char *which)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sq_Query (const char *attribute, ILxUnknownID query)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sq_Type (const char *attribute, int *type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sq_TypeName (const char *attribute, const char **type)
        { return LXe_NOTIMPL; }
};
#define LXxD_ScriptQuery_Select LxResult sq_Select (const char *attribute, const char *which)
#define LXxO_ScriptQuery_Select LXxD_ScriptQuery_Select LXx_OVERRIDE
#define LXxC_ScriptQuery_Select(c) LxResult c::sq_Select (const char *attribute, const char *which)
#define LXxD_ScriptQuery_Query LxResult sq_Query (const char *attribute, ILxUnknownID query)
#define LXxO_ScriptQuery_Query LXxD_ScriptQuery_Query LXx_OVERRIDE
#define LXxC_ScriptQuery_Query(c) LxResult c::sq_Query (const char *attribute, ILxUnknownID query)
#define LXxD_ScriptQuery_Type LxResult sq_Type (const char *attribute, int *type)
#define LXxO_ScriptQuery_Type LXxD_ScriptQuery_Type LXx_OVERRIDE
#define LXxC_ScriptQuery_Type(c) LxResult c::sq_Type (const char *attribute, int *type)
#define LXxD_ScriptQuery_TypeName LxResult sq_TypeName (const char *attribute, const char **type)
#define LXxO_ScriptQuery_TypeName LXxD_ScriptQuery_TypeName LXx_OVERRIDE
#define LXxC_ScriptQuery_TypeName(c) LxResult c::sq_TypeName (const char *attribute, const char **type)
template <class T>
class CLxIfc_ScriptQuery : public CLxInterface
{
    static LxResult
  Select (LXtObjectID wcom, const char *attribute, const char *which)
  {
    LXCWxINST (CLxImpl_ScriptQuery, loc);
    try {
      return loc->sq_Select (attribute,which);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Query (LXtObjectID wcom, const char *attribute, LXtObjectID query)
  {
    LXCWxINST (CLxImpl_ScriptQuery, loc);
    try {
      return loc->sq_Query (attribute,(ILxUnknownID)query);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Type (LXtObjectID wcom, const char *attribute, int *type)
  {
    LXCWxINST (CLxImpl_ScriptQuery, loc);
    try {
      return loc->sq_Type (attribute,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TypeName (LXtObjectID wcom, const char *attribute, const char **type)
  {
    LXCWxINST (CLxImpl_ScriptQuery, loc);
    try {
      return loc->sq_TypeName (attribute,type);
    } catch (LxResult rc) { return rc; }
  }
  ILxScriptQuery vt;
public:
  CLxIfc_ScriptQuery ()
  {
    vt.Select = Select;
    vt.Query = Query;
    vt.Type = Type;
    vt.TypeName = TypeName;
    vTable = &vt.iunk;
    iid = &lx::guid_ScriptQuery;
  }
};
class CLxLoc_ScriptQuery : public CLxLocalize<ILxScriptQueryID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ScriptQuery() {_init();}
  CLxLoc_ScriptQuery(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ScriptQuery(const CLxLoc_ScriptQuery &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ScriptQuery;}
    LxResult
  Select (const char *attribute, const char *which)
  {
    return m_loc[0]->Select (m_loc,attribute,which);
  }
    LxResult
  Query (const char *attribute, ILxUnknownID query)
  {
    return m_loc[0]->Query (m_loc,attribute,(ILxUnknownID)query);
  }
    LxResult
  Type (const char *attribute, int *type)
  {
    return m_loc[0]->Type (m_loc,attribute,type);
  }
    LxResult
  TypeName (const char *attribute, const char **type)
  {
    return m_loc[0]->TypeName (m_loc,attribute,type);
  }
};

class CLxLoc_TextEncodingService : public CLxLocalizedService
{
public:
  ILxTextEncodingServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_TextEncodingService() {_init();set();}
 ~CLxLoc_TextEncodingService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxTextEncodingServiceID>(lx::GetGlobal(&lx::guid_TextEncodingService));}
    LxResult
  Allocate (void **ppvObj)
  {
    return m_loc[0]->Allocate (m_loc,ppvObj);
  }
    CLxResult
  Allocate (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Allocate(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_StringConversionNice {
  public:
    virtual ~CLxImpl_StringConversionNice() {}
    virtual LxResult
      nicestr_Encode (char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      nicestr_Decode (const char *buf)
        { return LXe_NOTIMPL; }
};
#define LXxD_StringConversionNice_Encode LxResult nicestr_Encode (char *buf, unsigned len)
#define LXxO_StringConversionNice_Encode LXxD_StringConversionNice_Encode LXx_OVERRIDE
#define LXxC_StringConversionNice_Encode(c) LxResult c::nicestr_Encode (char *buf, unsigned len)
#define LXxD_StringConversionNice_Decode LxResult nicestr_Decode (const char *buf)
#define LXxO_StringConversionNice_Decode LXxD_StringConversionNice_Decode LXx_OVERRIDE
#define LXxC_StringConversionNice_Decode(c) LxResult c::nicestr_Decode (const char *buf)
template <class T>
class CLxIfc_StringConversionNice : public CLxInterface
{
    static LxResult
  Encode (LXtObjectID wcom, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_StringConversionNice, loc);
    try {
      return loc->nicestr_Encode (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Decode (LXtObjectID wcom, const char *buf)
  {
    LXCWxINST (CLxImpl_StringConversionNice, loc);
    try {
      return loc->nicestr_Decode (buf);
    } catch (LxResult rc) { return rc; }
  }
  ILxStringConversionNice vt;
public:
  CLxIfc_StringConversionNice ()
  {
    vt.Encode = Encode;
    vt.Decode = Decode;
    vTable = &vt.iunk;
    iid = &lx::guid_StringConversionNice;
  }
};
class CLxLoc_StringConversionNice : public CLxLocalize<ILxStringConversionNiceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StringConversionNice() {_init();}
  CLxLoc_StringConversionNice(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StringConversionNice(const CLxLoc_StringConversionNice &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StringConversionNice;}
    LxResult
  Encode (char *buf, unsigned len) const
  {
    return m_loc[0]->Encode (m_loc,buf,len);
  }
    LxResult
  Encode (std::string &result) const
  {
    LXWx_SBUF1
    rc = m_loc[0]->Encode (m_loc,buf,len);
    LXWx_SBUF2
  }
    LxResult
  Decode (const char *buf)
  {
    return m_loc[0]->Decode (m_loc,buf);
  }
};

class CLxLoc_Quaternion : public CLxLocalize<ILxQuaternionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Quaternion() {_init();}
  CLxLoc_Quaternion(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Quaternion(const CLxLoc_Quaternion &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Quaternion;}
    LxResult
  GetQuaternion (LXtQuaternion q) const
  {
    return m_loc[0]->GetQuaternion (m_loc,q);
  }
    LxResult
  GetMatrix (LXtMatrix mat3) const
  {
    return m_loc[0]->GetMatrix (m_loc,mat3);
  }
    LxResult
  GetAngleAxis (double *ang, LXtVector axis) const
  {
    return m_loc[0]->GetAngleAxis (m_loc,ang,axis);
  }
    LxResult
  SetQuaternion (const LXtQuaternion q)
  {
    return m_loc[0]->SetQuaternion (m_loc,q);
  }
    LxResult
  SetMatrix (const LXtMatrix mat3)
  {
    return m_loc[0]->SetMatrix (m_loc,mat3);
  }
    LxResult
  SetAngleAxis (double ang, const LXtVector axis)
  {
    return m_loc[0]->SetAngleAxis (m_loc,ang,axis);
  }
};

class CLxLoc_ValueReference : public CLxLocalize<ILxValueReferenceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueReference() {_init();}
  CLxLoc_ValueReference(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ValueReference(const CLxLoc_ValueReference &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ValueReference;}
    LxResult
  IsSet (void) const
  {
    return m_loc[0]->IsSet (m_loc);
  }
    LxResult
  GetObject (void **ppvObj) const
  {
    return m_loc[0]->GetObject (m_loc,ppvObj);
  }
    CLxResult
  GetObject (CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetObject(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetObject (ILxUnknownID obj)
  {
    return m_loc[0]->SetObject (m_loc,(ILxUnknownID)obj);
  }
};


class CLxImpl_StringConversion {
  public:
    virtual ~CLxImpl_StringConversion() {}
    virtual LxResult
      str_Encode (char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      str_Decode (const char *buf)
        { return LXe_NOTIMPL; }
};
#define LXxD_StringConversion_Encode LxResult str_Encode (char *buf, unsigned len)
#define LXxO_StringConversion_Encode LXxD_StringConversion_Encode LXx_OVERRIDE
#define LXxC_StringConversion_Encode(c) LxResult c::str_Encode (char *buf, unsigned len)
#define LXxD_StringConversion_Decode LxResult str_Decode (const char *buf)
#define LXxO_StringConversion_Decode LXxD_StringConversion_Decode LXx_OVERRIDE
#define LXxC_StringConversion_Decode(c) LxResult c::str_Decode (const char *buf)
template <class T>
class CLxIfc_StringConversion : public CLxInterface
{
    static LxResult
  Encode (LXtObjectID wcom, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_StringConversion, loc);
    try {
      return loc->str_Encode (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Decode (LXtObjectID wcom, const char *buf)
  {
    LXCWxINST (CLxImpl_StringConversion, loc);
    try {
      return loc->str_Decode (buf);
    } catch (LxResult rc) { return rc; }
  }
  ILxStringConversion vt;
public:
  CLxIfc_StringConversion ()
  {
    vt.Encode = Encode;
    vt.Decode = Decode;
    vTable = &vt.iunk;
    iid = &lx::guid_StringConversion;
  }
};
class CLxLoc_StringConversion : public CLxLocalize<ILxStringConversionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StringConversion() {_init();}
  CLxLoc_StringConversion(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StringConversion(const CLxLoc_StringConversion &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StringConversion;}
    LxResult
  Encode (char *buf, unsigned len) const
  {
    return m_loc[0]->Encode (m_loc,buf,len);
  }
    LxResult
  Encode (std::string &result) const
  {
    LXWx_SBUF1
    rc = m_loc[0]->Encode (m_loc,buf,len);
    LXWx_SBUF2
  }
    LxResult
  Decode (const char *buf)
  {
    return m_loc[0]->Decode (m_loc,buf);
  }
};

class CLxLoc_Matrix : public CLxLocalize<ILxMatrixID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Matrix() {_init();}
  CLxLoc_Matrix(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Matrix(const CLxLoc_Matrix &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Matrix;}
    LxResult
  Get3 (LXtMatrix mat3) const
  {
    return m_loc[0]->Get3 (m_loc,mat3);
  }
    LxResult
  Get4 (LXtMatrix4 mat4) const
  {
    return m_loc[0]->Get4 (m_loc,mat4);
  }
    LxResult
  GetOffset (LXtVector offset) const
  {
    return m_loc[0]->GetOffset (m_loc,offset);
  }
    LxResult
  MultiplyVector (const LXtVector vector, LXtVector result) const
  {
    return m_loc[0]->MultiplyVector (m_loc,vector,result);
  }
    LxResult
  Set3 (const LXtMatrix mat3)
  {
    return m_loc[0]->Set3 (m_loc,mat3);
  }
    LxResult
  Set4 (const LXtMatrix4 mat4)
  {
    return m_loc[0]->Set4 (m_loc,mat4);
  }
    LxResult
  SetOffset (const LXtVector offset)
  {
    return m_loc[0]->SetOffset (m_loc,offset);
  }
    LxResult
  SetIdentity (void)
  {
    return m_loc[0]->SetIdentity (m_loc);
  }
    LxResult
  Multiply3 (const LXtMatrix mat3)
  {
    return m_loc[0]->Multiply3 (m_loc,mat3);
  }
    LxResult
  Multiply4 (const LXtMatrix4 mat4)
  {
    return m_loc[0]->Multiply4 (m_loc,mat4);
  }
    LxResult
  Invert (void)
  {
    return m_loc[0]->Invert (m_loc);
  }
    LxResult
  Transpose (void)
  {
    return m_loc[0]->Transpose (m_loc);
  }
};

class CLxLoc_TextEncoding : public CLxLocalize<ILxTextEncodingID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TextEncoding() {_init();}
  CLxLoc_TextEncoding(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TextEncoding(const CLxLoc_TextEncoding &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TextEncoding;}
    unsigned
  Default (void)
  {
    return m_loc[0]->Default (m_loc);
  }
    unsigned
  Source (void)
  {
    return m_loc[0]->Source (m_loc);
  }
    unsigned
  Target (void)
  {
    return m_loc[0]->Target (m_loc);
  }
    LxResult
  SetSource (unsigned encoding)
  {
    return m_loc[0]->SetSource (m_loc,encoding);
  }
    LxResult
  SetTarget (unsigned encoding)
  {
    return m_loc[0]->SetTarget (m_loc,encoding);
  }
    LxResult
  Convert (const char *src, char *buf, unsigned max)
  {
    return m_loc[0]->Convert (m_loc,src,buf,max);
  }
    int
  NumChar (const char *string, int target)
  {
    return m_loc[0]->NumChar (m_loc,string,target);
  }
    const char *
  PullChar (const char *string, int *code, int *len, int target)
  {
    return m_loc[0]->PullChar (m_loc,string,code,len,target);
  }
};

#endif

