/*
 * C++ wrapper for lxcommand.h
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
#ifndef LXW_COMMAND_HPP
#define LXW_COMMAND_HPP

#include <lxcommand.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_CommandBlock = {0x65AEBD9F,0xD518,0x47b2,0x8C,0xC6,0xE4,0x53,0xF8,0xC4,0x3C,0xB6};
    static const LXtGUID guid_AttributesUI = {0x44D9C65E,0xAE2E,0x4012,0xAB,0x57,0xE2,0x83,0x97,0x34,0xF7,0xFF};
    static const LXtGUID guid_Command2 = {0x5e981e16,0x94b7,0x4364,0x92,0xf0,0xd7,0x67,0x92,0x36,0xf3,0xd1};
    static const LXtGUID guid_CommandService = {0x9DB8BA65,0x8C36,0x45A7,0xB4,0x03,0xDF,0x7B,0xA5,0x9B,0xA6,0xC2};
    static const LXtGUID guid_UIHints = {0x944D9CFD,0xDB04,0x4bba,0xB8,0xB1,0xAD,0xE4,0x24,0x69,0x5E,0xDC};
    static const LXtGUID guid_CommandPostEnd = {0xAEB6B7BF,0x34B9,0x4991,0x90,0x4C,0x29,0x8B,0x8D,0xB1,0xAE,0x12};
    static const LXtGUID guid_CommandDBHelp = {0x7c8a58e0,0x0052,0x4d8e,0xad,0xdb,0x73,0x87,0xfb,0xa9,0xd5,0xbf};
    static const LXtGUID guid_UIHintsRead = {0x8f22a96d,0x94e5,0x49c8,0xb3,0xd4,0xa4,0x08,0x0f,0xbe,0xe9,0x1b};
    static const LXtGUID guid_Command1 = {0x4F540BF1,0xF97E,0x4D46,0x8A,0x5F,0x6B,0x27,0x50,0xA6,0xCE,0xB9};
    static const LXtGUID guid_UIValueHints3 = {0xded71bdb,0x080c,0x4ce8,0xbf,0x06,0x69,0xe3,0x72,0xea,0x8b,0xea};
    static const LXtGUID guid_Command = {0x1db2d294,0x3b52,0x4442,0xa6,0x34,0xf3,0xd4,0xc6,0xce,0x8d,0xc4};
    static const LXtGUID guid_CommandEvent = {0xF7CD29B5,0x6858,0x445b,0xBE,0x6D,0x83,0x47,0x60,0x3B,0x47,0xE9};
    static const LXtGUID guid_UIValueHints2 = {0xf37bb385,0x7214,0x42d5,0x9b,0xed,0x55,0x2f,0xf4,0x73,0x89,0x08};
    static const LXtGUID guid_Command3 = {0xdb970a3b,0xdce1,0x4679,0xa4,0xbf,0xb5,0xf1,0xdf,0xf4,0xdb,0x0d};
    static const LXtGUID guid_CmdSysListener = {0xd89ccb72,0x43b9,0x4bf2,0xbb,0x7d,0x7e,0x81,0x6b,0xb4,0xd9,0xd8};
    static const LXtGUID guid_UIValueHints = {0x57E8F131,0xCE2D,0x42C6,0x82,0x41,0xA3,0x95,0x25,0x3B,0x37,0xD6};
    static const LXtGUID guid_UIValueHints1 = {0x7BB10C3F,0x1FFB,0x4104,0x8F,0xBE,0xCB,0x1C,0x33,0x4E,0xE3,0xC1};
};


class CLxImpl_AttributesUI {
  public:
    virtual ~CLxImpl_AttributesUI() {}
    virtual LxResult
      atrui_UIHints (unsigned int index, ILxUnknownID hints)
        { return LXe_NOTIMPL; }
    virtual LxResult
      atrui_UIValueHints (unsigned int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      atrui_DisableMsg (unsigned int index, ILxUnknownID message)
        { return LXe_NOTIMPL; }
};
#define LXxD_AttributesUI_UIHints LxResult atrui_UIHints (unsigned int index, ILxUnknownID hints)
#define LXxO_AttributesUI_UIHints LXxD_AttributesUI_UIHints LXx_OVERRIDE
#define LXxC_AttributesUI_UIHints(c) LxResult c::atrui_UIHints (unsigned int index, ILxUnknownID hints)
#define LXxD_AttributesUI_UIValueHints LxResult atrui_UIValueHints (unsigned int index, void **ppvObj)
#define LXxO_AttributesUI_UIValueHints LXxD_AttributesUI_UIValueHints LXx_OVERRIDE
#define LXxC_AttributesUI_UIValueHints(c) LxResult c::atrui_UIValueHints (unsigned int index, void **ppvObj)
#define LXxD_AttributesUI_DisableMsg LxResult atrui_DisableMsg (unsigned int index, ILxUnknownID message)
#define LXxO_AttributesUI_DisableMsg LXxD_AttributesUI_DisableMsg LXx_OVERRIDE
#define LXxC_AttributesUI_DisableMsg(c) LxResult c::atrui_DisableMsg (unsigned int index, ILxUnknownID message)
template <class T>
class CLxIfc_AttributesUI : public CLxInterface
{
    static LxResult
  UIHints (LXtObjectID wcom, unsigned int index, LXtObjectID hints)
  {
    LXCWxINST (CLxImpl_AttributesUI, loc);
    try {
      return loc->atrui_UIHints (index,(ILxUnknownID)hints);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UIValueHints (LXtObjectID wcom, unsigned int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_AttributesUI, loc);
    try {
      return loc->atrui_UIValueHints (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DisableMsg (LXtObjectID wcom, unsigned int index, LXtObjectID message)
  {
    LXCWxINST (CLxImpl_AttributesUI, loc);
    try {
      return loc->atrui_DisableMsg (index,(ILxUnknownID)message);
    } catch (LxResult rc) { return rc; }
  }
  ILxAttributesUI vt;
public:
  CLxIfc_AttributesUI ()
  {
    vt.UIHints = UIHints;
    vt.UIValueHints = UIValueHints;
    vt.DisableMsg = DisableMsg;
    vTable = &vt.iunk;
    iid = &lx::guid_AttributesUI;
  }
};
class CLxLoc_AttributesUI : public CLxLocalize<ILxAttributesUIID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AttributesUI() {_init();}
  CLxLoc_AttributesUI(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AttributesUI(const CLxLoc_AttributesUI &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AttributesUI;}
    LxResult
  UIHints (unsigned int index, ILxUnknownID hints)
  {
    return m_loc[0]->UIHints (m_loc,index,(ILxUnknownID)hints);
  }
    LxResult
  UIValueHints (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->UIValueHints (m_loc,index,ppvObj);
  }
    CLxResult
  UIValueHints (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->UIValueHints(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  DisableMsg (unsigned int index, ILxUnknownID message)
  {
    return m_loc[0]->DisableMsg (m_loc,index,(ILxUnknownID)message);
  }
};

class CLxImpl_Command2 {
  public:
    virtual ~CLxImpl_Command2() {}
    virtual LxResult
      cmd2_Tag (LXtCommandTag *tag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_UserName (const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ButtonName (const char **buttonName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Desc (const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Tooltip (const char **tooltip)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Help (const char **help)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Example (const char **example)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Icon (const char **iconNames)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Flags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_PostExecFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_PostExecBehaviorFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_PostExecHints (unsigned int *hints)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_SandboxGUID (const LXtGUID **guid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Message (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ContainedEnable (LXtID4 *types)
        { return LXe_NOTIMPL; }
    virtual void
      cmd2_Interact (void)
        { }
    virtual void
      cmd2_PreExecute (void)
        { }
    virtual void
      cmd2_Execute (unsigned int flags)
        { }
    virtual LxResult
      cmd2_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgFlags (unsigned int index, unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgClear (unsigned int index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgResetAll (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgSetDatatypes (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgUserName (unsigned int index, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgDesc (unsigned int index, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgExample (unsigned int index, const char **example)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgType (unsigned int index, const char **type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgTypeUserName (unsigned int index, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgTypeDesc (unsigned int index, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_DialogInit (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_DialogArgChange (unsigned int arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgEnable (unsigned int arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_ArgParseString (unsigned int argIndex, const char *argString)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Copy (ILxUnknownID sourceCommand)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_Query (unsigned int index, ILxUnknownID vaQuery)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_NotifyAddClient (int argument, ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_NotifyRemoveClient (ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd2_DialogFormatting (const char **formatting)
        { return LXe_NOTIMPL; }
};
#define LXxD_Command2_Tag LxResult cmd2_Tag (LXtCommandTag *tag)
#define LXxO_Command2_Tag LXxD_Command2_Tag LXx_OVERRIDE
#define LXxC_Command2_Tag(c) LxResult c::cmd2_Tag (LXtCommandTag *tag)
#define LXxD_Command2_Name LxResult cmd2_Name (const char **name)
#define LXxO_Command2_Name LXxD_Command2_Name LXx_OVERRIDE
#define LXxC_Command2_Name(c) LxResult c::cmd2_Name (const char **name)
#define LXxD_Command2_UserName LxResult cmd2_UserName (const char **userName)
#define LXxO_Command2_UserName LXxD_Command2_UserName LXx_OVERRIDE
#define LXxC_Command2_UserName(c) LxResult c::cmd2_UserName (const char **userName)
#define LXxD_Command2_ButtonName LxResult cmd2_ButtonName (const char **buttonName)
#define LXxO_Command2_ButtonName LXxD_Command2_ButtonName LXx_OVERRIDE
#define LXxC_Command2_ButtonName(c) LxResult c::cmd2_ButtonName (const char **buttonName)
#define LXxD_Command2_Desc LxResult cmd2_Desc (const char **desc)
#define LXxO_Command2_Desc LXxD_Command2_Desc LXx_OVERRIDE
#define LXxC_Command2_Desc(c) LxResult c::cmd2_Desc (const char **desc)
#define LXxD_Command2_Tooltip LxResult cmd2_Tooltip (const char **tooltip)
#define LXxO_Command2_Tooltip LXxD_Command2_Tooltip LXx_OVERRIDE
#define LXxC_Command2_Tooltip(c) LxResult c::cmd2_Tooltip (const char **tooltip)
#define LXxD_Command2_Help LxResult cmd2_Help (const char **help)
#define LXxO_Command2_Help LXxD_Command2_Help LXx_OVERRIDE
#define LXxC_Command2_Help(c) LxResult c::cmd2_Help (const char **help)
#define LXxD_Command2_Example LxResult cmd2_Example (const char **example)
#define LXxO_Command2_Example LXxD_Command2_Example LXx_OVERRIDE
#define LXxC_Command2_Example(c) LxResult c::cmd2_Example (const char **example)
#define LXxD_Command2_Icon LxResult cmd2_Icon (const char **iconNames)
#define LXxO_Command2_Icon LXxD_Command2_Icon LXx_OVERRIDE
#define LXxC_Command2_Icon(c) LxResult c::cmd2_Icon (const char **iconNames)
#define LXxD_Command2_Flags LxResult cmd2_Flags (unsigned int *flags)
#define LXxO_Command2_Flags LXxD_Command2_Flags LXx_OVERRIDE
#define LXxC_Command2_Flags(c) LxResult c::cmd2_Flags (unsigned int *flags)
#define LXxD_Command2_PostExecFlags LxResult cmd2_PostExecFlags (unsigned int *flags)
#define LXxO_Command2_PostExecFlags LXxD_Command2_PostExecFlags LXx_OVERRIDE
#define LXxC_Command2_PostExecFlags(c) LxResult c::cmd2_PostExecFlags (unsigned int *flags)
#define LXxD_Command2_PostExecBehaviorFlags LxResult cmd2_PostExecBehaviorFlags (unsigned int *flags)
#define LXxO_Command2_PostExecBehaviorFlags LXxD_Command2_PostExecBehaviorFlags LXx_OVERRIDE
#define LXxC_Command2_PostExecBehaviorFlags(c) LxResult c::cmd2_PostExecBehaviorFlags (unsigned int *flags)
#define LXxD_Command2_PostExecHints LxResult cmd2_PostExecHints (unsigned int *hints)
#define LXxO_Command2_PostExecHints LXxD_Command2_PostExecHints LXx_OVERRIDE
#define LXxC_Command2_PostExecHints(c) LxResult c::cmd2_PostExecHints (unsigned int *hints)
#define LXxD_Command2_SandboxGUID LxResult cmd2_SandboxGUID (const LXtGUID **guid)
#define LXxO_Command2_SandboxGUID LXxD_Command2_SandboxGUID LXx_OVERRIDE
#define LXxC_Command2_SandboxGUID(c) LxResult c::cmd2_SandboxGUID (const LXtGUID **guid)
#define LXxD_Command2_Message LxResult cmd2_Message (void **ppvObj)
#define LXxO_Command2_Message LXxD_Command2_Message LXx_OVERRIDE
#define LXxC_Command2_Message(c) LxResult c::cmd2_Message (void **ppvObj)
#define LXxD_Command2_Enable LxResult cmd2_Enable (ILxUnknownID msg)
#define LXxO_Command2_Enable LXxD_Command2_Enable LXx_OVERRIDE
#define LXxC_Command2_Enable(c) LxResult c::cmd2_Enable (ILxUnknownID msg)
#define LXxD_Command2_ContainedEnable LxResult cmd2_ContainedEnable (LXtID4 *types)
#define LXxO_Command2_ContainedEnable LXxD_Command2_ContainedEnable LXx_OVERRIDE
#define LXxC_Command2_ContainedEnable(c) LxResult c::cmd2_ContainedEnable (LXtID4 *types)
#define LXxD_Command2_Interact void cmd2_Interact (void)
#define LXxO_Command2_Interact LXxD_Command2_Interact LXx_OVERRIDE
#define LXxC_Command2_Interact(c) void c::cmd2_Interact (void)
#define LXxD_Command2_PreExecute void cmd2_PreExecute (void)
#define LXxO_Command2_PreExecute LXxD_Command2_PreExecute LXx_OVERRIDE
#define LXxC_Command2_PreExecute(c) void c::cmd2_PreExecute (void)
#define LXxD_Command2_Execute void cmd2_Execute (unsigned int flags)
#define LXxO_Command2_Execute LXxD_Command2_Execute LXx_OVERRIDE
#define LXxC_Command2_Execute(c) void c::cmd2_Execute (unsigned int flags)
#define LXxD_Command2_ToggleArg LxResult cmd2_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
#define LXxO_Command2_ToggleArg LXxD_Command2_ToggleArg LXx_OVERRIDE
#define LXxC_Command2_ToggleArg(c) LxResult c::cmd2_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
#define LXxD_Command2_ArgFlags LxResult cmd2_ArgFlags (unsigned int index, unsigned int *flags)
#define LXxO_Command2_ArgFlags LXxD_Command2_ArgFlags LXx_OVERRIDE
#define LXxC_Command2_ArgFlags(c) LxResult c::cmd2_ArgFlags (unsigned int index, unsigned int *flags)
#define LXxD_Command2_ArgClear LxResult cmd2_ArgClear (unsigned int index)
#define LXxO_Command2_ArgClear LXxD_Command2_ArgClear LXx_OVERRIDE
#define LXxC_Command2_ArgClear(c) LxResult c::cmd2_ArgClear (unsigned int index)
#define LXxD_Command2_ArgResetAll LxResult cmd2_ArgResetAll (void)
#define LXxO_Command2_ArgResetAll LXxD_Command2_ArgResetAll LXx_OVERRIDE
#define LXxC_Command2_ArgResetAll(c) LxResult c::cmd2_ArgResetAll (void)
#define LXxD_Command2_ArgSetDatatypes LxResult cmd2_ArgSetDatatypes (void)
#define LXxO_Command2_ArgSetDatatypes LXxD_Command2_ArgSetDatatypes LXx_OVERRIDE
#define LXxC_Command2_ArgSetDatatypes(c) LxResult c::cmd2_ArgSetDatatypes (void)
#define LXxD_Command2_ArgUserName LxResult cmd2_ArgUserName (unsigned int index, const char **userName)
#define LXxO_Command2_ArgUserName LXxD_Command2_ArgUserName LXx_OVERRIDE
#define LXxC_Command2_ArgUserName(c) LxResult c::cmd2_ArgUserName (unsigned int index, const char **userName)
#define LXxD_Command2_ArgDesc LxResult cmd2_ArgDesc (unsigned int index, const char **desc)
#define LXxO_Command2_ArgDesc LXxD_Command2_ArgDesc LXx_OVERRIDE
#define LXxC_Command2_ArgDesc(c) LxResult c::cmd2_ArgDesc (unsigned int index, const char **desc)
#define LXxD_Command2_ArgExample LxResult cmd2_ArgExample (unsigned int index, const char **example)
#define LXxO_Command2_ArgExample LXxD_Command2_ArgExample LXx_OVERRIDE
#define LXxC_Command2_ArgExample(c) LxResult c::cmd2_ArgExample (unsigned int index, const char **example)
#define LXxD_Command2_ArgType LxResult cmd2_ArgType (unsigned int index, const char **type)
#define LXxO_Command2_ArgType LXxD_Command2_ArgType LXx_OVERRIDE
#define LXxC_Command2_ArgType(c) LxResult c::cmd2_ArgType (unsigned int index, const char **type)
#define LXxD_Command2_ArgTypeUserName LxResult cmd2_ArgTypeUserName (unsigned int index, const char **userName)
#define LXxO_Command2_ArgTypeUserName LXxD_Command2_ArgTypeUserName LXx_OVERRIDE
#define LXxC_Command2_ArgTypeUserName(c) LxResult c::cmd2_ArgTypeUserName (unsigned int index, const char **userName)
#define LXxD_Command2_ArgTypeDesc LxResult cmd2_ArgTypeDesc (unsigned int index, const char **desc)
#define LXxO_Command2_ArgTypeDesc LXxD_Command2_ArgTypeDesc LXx_OVERRIDE
#define LXxC_Command2_ArgTypeDesc(c) LxResult c::cmd2_ArgTypeDesc (unsigned int index, const char **desc)
#define LXxD_Command2_ArgOptionUserName LxResult cmd2_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
#define LXxO_Command2_ArgOptionUserName LXxD_Command2_ArgOptionUserName LXx_OVERRIDE
#define LXxC_Command2_ArgOptionUserName(c) LxResult c::cmd2_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
#define LXxD_Command2_ArgOptionDesc LxResult cmd2_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
#define LXxO_Command2_ArgOptionDesc LXxD_Command2_ArgOptionDesc LXx_OVERRIDE
#define LXxC_Command2_ArgOptionDesc(c) LxResult c::cmd2_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
#define LXxD_Command2_DialogInit LxResult cmd2_DialogInit (void)
#define LXxO_Command2_DialogInit LXxD_Command2_DialogInit LXx_OVERRIDE
#define LXxC_Command2_DialogInit(c) LxResult c::cmd2_DialogInit (void)
#define LXxD_Command2_DialogArgChange LxResult cmd2_DialogArgChange (unsigned int arg)
#define LXxO_Command2_DialogArgChange LXxD_Command2_DialogArgChange LXx_OVERRIDE
#define LXxC_Command2_DialogArgChange(c) LxResult c::cmd2_DialogArgChange (unsigned int arg)
#define LXxD_Command2_ArgEnable LxResult cmd2_ArgEnable (unsigned int arg)
#define LXxO_Command2_ArgEnable LXxD_Command2_ArgEnable LXx_OVERRIDE
#define LXxC_Command2_ArgEnable(c) LxResult c::cmd2_ArgEnable (unsigned int arg)
#define LXxD_Command2_ArgParseString LxResult cmd2_ArgParseString (unsigned int argIndex, const char *argString)
#define LXxO_Command2_ArgParseString LXxD_Command2_ArgParseString LXx_OVERRIDE
#define LXxC_Command2_ArgParseString(c) LxResult c::cmd2_ArgParseString (unsigned int argIndex, const char *argString)
#define LXxD_Command2_Copy LxResult cmd2_Copy (ILxUnknownID sourceCommand)
#define LXxO_Command2_Copy LXxD_Command2_Copy LXx_OVERRIDE
#define LXxC_Command2_Copy(c) LxResult c::cmd2_Copy (ILxUnknownID sourceCommand)
#define LXxD_Command2_Query LxResult cmd2_Query (unsigned int index, ILxUnknownID vaQuery)
#define LXxO_Command2_Query LXxD_Command2_Query LXx_OVERRIDE
#define LXxC_Command2_Query(c) LxResult c::cmd2_Query (unsigned int index, ILxUnknownID vaQuery)
#define LXxD_Command2_NotifyAddClient LxResult cmd2_NotifyAddClient (int argument, ILxUnknownID object)
#define LXxO_Command2_NotifyAddClient LXxD_Command2_NotifyAddClient LXx_OVERRIDE
#define LXxC_Command2_NotifyAddClient(c) LxResult c::cmd2_NotifyAddClient (int argument, ILxUnknownID object)
#define LXxD_Command2_NotifyRemoveClient LxResult cmd2_NotifyRemoveClient (ILxUnknownID object)
#define LXxO_Command2_NotifyRemoveClient LXxD_Command2_NotifyRemoveClient LXx_OVERRIDE
#define LXxC_Command2_NotifyRemoveClient(c) LxResult c::cmd2_NotifyRemoveClient (ILxUnknownID object)
#define LXxD_Command2_DialogFormatting LxResult cmd2_DialogFormatting (const char **formatting)
#define LXxO_Command2_DialogFormatting LXxD_Command2_DialogFormatting LXx_OVERRIDE
#define LXxC_Command2_DialogFormatting(c) LxResult c::cmd2_DialogFormatting (const char **formatting)
template <class T>
class CLxIfc_Command2 : public CLxInterface
{
    static LxResult
  Tag (LXtObjectID wcom, LXtCommandTag *tag)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Tag (tag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UserName (LXtObjectID wcom, const char **userName)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_UserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ButtonName (LXtObjectID wcom, const char **buttonName)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ButtonName (buttonName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Desc (LXtObjectID wcom, const char **desc)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Desc (desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Tooltip (LXtObjectID wcom, const char **tooltip)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Tooltip (tooltip);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Help (LXtObjectID wcom, const char **help)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Help (help);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Example (LXtObjectID wcom, const char **example)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Example (example);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Icon (LXtObjectID wcom, const char **iconNames)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Icon (iconNames);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Flags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Flags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_PostExecFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecBehaviorFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_PostExecBehaviorFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecHints (LXtObjectID wcom, unsigned int *hints)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_PostExecHints (hints);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SandboxGUID (LXtObjectID wcom, const LXtGUID **guid)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_SandboxGUID (guid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Message (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Message (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ContainedEnable (LXtObjectID wcom, LXtID4 *types)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ContainedEnable (types);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Interact (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    loc->cmd2_Interact ();
  }
    static void
  PreExecute (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    loc->cmd2_PreExecute ();
  }
    static void
  Execute (LXtObjectID wcom, unsigned int flags)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    loc->cmd2_Execute (flags);
  }
    static LxResult
  ToggleArg (LXtObjectID wcom, unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ToggleArg (index,ppvObj,typeID,typeName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgFlags (LXtObjectID wcom, unsigned int index, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgClear (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgClear (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgResetAll (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgResetAll ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgSetDatatypes (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgSetDatatypes ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgUserName (LXtObjectID wcom, unsigned int index, const char **userName)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgUserName (index,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgDesc (LXtObjectID wcom, unsigned int index, const char **desc)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgDesc (index,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgExample (LXtObjectID wcom, unsigned int index, const char **example)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgExample (index,example);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgType (LXtObjectID wcom, unsigned int index, const char **type)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgType (index,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgTypeUserName (LXtObjectID wcom, unsigned int index, const char **userName)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgTypeUserName (index,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgTypeDesc (LXtObjectID wcom, unsigned int index, const char **desc)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgTypeDesc (index,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionUserName (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **userName)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgOptionUserName (index,optIndex,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionDesc (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **desc)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgOptionDesc (index,optIndex,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogInit (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_DialogInit ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogArgChange (LXtObjectID wcom, unsigned int arg)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_DialogArgChange (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgEnable (LXtObjectID wcom, unsigned int arg)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgEnable (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgParseString (LXtObjectID wcom, unsigned int argIndex, const char *argString)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_ArgParseString (argIndex,argString);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Copy (LXtObjectID wcom, LXtObjectID sourceCommand)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Copy ((ILxUnknownID)sourceCommand);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Query (LXtObjectID wcom, unsigned int index, LXtObjectID vaQuery)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_Query (index,(ILxUnknownID)vaQuery);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifyAddClient (LXtObjectID wcom, int argument, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_NotifyAddClient (argument,(ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifyRemoveClient (LXtObjectID wcom, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_NotifyRemoveClient ((ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogFormatting (LXtObjectID wcom, const char **formatting)
  {
    LXCWxINST (CLxImpl_Command2, loc);
    try {
      return loc->cmd2_DialogFormatting (formatting);
    } catch (LxResult rc) { return rc; }
  }
  ILxCommand2 vt;
public:
  CLxIfc_Command2 ()
  {
    vt.Tag = Tag;
    vt.Name = Name;
    vt.UserName = UserName;
    vt.ButtonName = ButtonName;
    vt.Desc = Desc;
    vt.Tooltip = Tooltip;
    vt.Help = Help;
    vt.Example = Example;
    vt.Icon = Icon;
    vt.Flags = Flags;
    vt.PostExecFlags = PostExecFlags;
    vt.PostExecBehaviorFlags = PostExecBehaviorFlags;
    vt.PostExecHints = PostExecHints;
    vt.SandboxGUID = SandboxGUID;
    vt.Message = Message;
    vt.Enable = Enable;
    vt.ContainedEnable = ContainedEnable;
    vt.Interact = Interact;
    vt.PreExecute = PreExecute;
    vt.Execute = Execute;
    vt.ToggleArg = ToggleArg;
    vt.ArgFlags = ArgFlags;
    vt.ArgClear = ArgClear;
    vt.ArgResetAll = ArgResetAll;
    vt.ArgSetDatatypes = ArgSetDatatypes;
    vt.ArgUserName = ArgUserName;
    vt.ArgDesc = ArgDesc;
    vt.ArgExample = ArgExample;
    vt.ArgType = ArgType;
    vt.ArgTypeUserName = ArgTypeUserName;
    vt.ArgTypeDesc = ArgTypeDesc;
    vt.ArgOptionUserName = ArgOptionUserName;
    vt.ArgOptionDesc = ArgOptionDesc;
    vt.DialogInit = DialogInit;
    vt.DialogArgChange = DialogArgChange;
    vt.ArgEnable = ArgEnable;
    vt.ArgParseString = ArgParseString;
    vt.Copy = Copy;
    vt.Query = Query;
    vt.NotifyAddClient = NotifyAddClient;
    vt.NotifyRemoveClient = NotifyRemoveClient;
    vt.DialogFormatting = DialogFormatting;
    vTable = &vt.iunk;
    iid = &lx::guid_Command2;
  }
};
class CLxLoc_Command2 : public CLxLocalize<ILxCommand2ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Command2() {_init();}
  CLxLoc_Command2(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Command2(const CLxLoc_Command2 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Command2;}
    LxResult
  Tag (LXtCommandTag *tag)
  {
    return m_loc[0]->Tag (m_loc,tag);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  UserName (const char **userName)
  {
    return m_loc[0]->UserName (m_loc,userName);
  }
    LxResult
  ButtonName (const char **buttonName)
  {
    return m_loc[0]->ButtonName (m_loc,buttonName);
  }
    LxResult
  Desc (const char **desc)
  {
    return m_loc[0]->Desc (m_loc,desc);
  }
    LxResult
  Tooltip (const char **tooltip)
  {
    return m_loc[0]->Tooltip (m_loc,tooltip);
  }
    LxResult
  Help (const char **help)
  {
    return m_loc[0]->Help (m_loc,help);
  }
    LxResult
  Example (const char **example)
  {
    return m_loc[0]->Example (m_loc,example);
  }
    LxResult
  Icon (const char **iconNames)
  {
    return m_loc[0]->Icon (m_loc,iconNames);
  }
    LxResult
  Flags (unsigned int *flags)
  {
    return m_loc[0]->Flags (m_loc,flags);
  }
    LxResult
  PostExecFlags (unsigned int *flags)
  {
    return m_loc[0]->PostExecFlags (m_loc,flags);
  }
    LxResult
  PostExecBehaviorFlags (unsigned int *flags)
  {
    return m_loc[0]->PostExecBehaviorFlags (m_loc,flags);
  }
    LxResult
  PostExecHints (unsigned int *hints)
  {
    return m_loc[0]->PostExecHints (m_loc,hints);
  }
    LxResult
  SandboxGUID (const LXtGUID **guid)
  {
    return m_loc[0]->SandboxGUID (m_loc,guid);
  }
    LxResult
  Message (void **ppvObj)
  {
    return m_loc[0]->Message (m_loc,ppvObj);
  }
    CLxResult
  Message (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Message(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  ContainedEnable (LXtID4 *types)
  {
    return m_loc[0]->ContainedEnable (m_loc,types);
  }
    void
  Interact (void)
  {
    m_loc[0]->Interact (m_loc);
  }
    void
  PreExecute (void)
  {
    m_loc[0]->PreExecute (m_loc);
  }
    void
  Execute (unsigned int flags)
  {
    m_loc[0]->Execute (m_loc,flags);
  }
    LxResult
  ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
  {
    return m_loc[0]->ToggleArg (m_loc,index,ppvObj,typeID,typeName);
  }
    CLxResult
  ToggleArg (unsigned int *index, CLxLocalizedObject &o_dest, unsigned int *typeID, const char **typeName)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ToggleArg(m_loc,index,&o_obj,typeID,typeName);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ArgFlags (unsigned int index, unsigned int *flags)
  {
    return m_loc[0]->ArgFlags (m_loc,index,flags);
  }
    LxResult
  ArgClear (unsigned int index)
  {
    return m_loc[0]->ArgClear (m_loc,index);
  }
    LxResult
  ArgResetAll (void)
  {
    return m_loc[0]->ArgResetAll (m_loc);
  }
    LxResult
  ArgSetDatatypes (void)
  {
    return m_loc[0]->ArgSetDatatypes (m_loc);
  }
    LxResult
  ArgUserName (unsigned int index, const char **userName)
  {
    return m_loc[0]->ArgUserName (m_loc,index,userName);
  }
    LxResult
  ArgDesc (unsigned int index, const char **desc)
  {
    return m_loc[0]->ArgDesc (m_loc,index,desc);
  }
    LxResult
  ArgExample (unsigned int index, const char **example)
  {
    return m_loc[0]->ArgExample (m_loc,index,example);
  }
    LxResult
  ArgType (unsigned int index, const char **type)
  {
    return m_loc[0]->ArgType (m_loc,index,type);
  }
    LxResult
  ArgTypeUserName (unsigned int index, const char **userName)
  {
    return m_loc[0]->ArgTypeUserName (m_loc,index,userName);
  }
    LxResult
  ArgTypeDesc (unsigned int index, const char **desc)
  {
    return m_loc[0]->ArgTypeDesc (m_loc,index,desc);
  }
    LxResult
  ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
  {
    return m_loc[0]->ArgOptionUserName (m_loc,index,optIndex,userName);
  }
    LxResult
  ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
  {
    return m_loc[0]->ArgOptionDesc (m_loc,index,optIndex,desc);
  }
    LxResult
  DialogInit (void)
  {
    return m_loc[0]->DialogInit (m_loc);
  }
    LxResult
  DialogArgChange (unsigned int arg)
  {
    return m_loc[0]->DialogArgChange (m_loc,arg);
  }
    LxResult
  ArgEnable (unsigned int arg)
  {
    return m_loc[0]->ArgEnable (m_loc,arg);
  }
    LxResult
  ArgParseString (unsigned int argIndex, const char *argString)
  {
    return m_loc[0]->ArgParseString (m_loc,argIndex,argString);
  }
    LxResult
  Copy (ILxUnknownID sourceCommand)
  {
    return m_loc[0]->Copy (m_loc,(ILxUnknownID)sourceCommand);
  }
    LxResult
  Query (unsigned int index, ILxUnknownID vaQuery)
  {
    return m_loc[0]->Query (m_loc,index,(ILxUnknownID)vaQuery);
  }
    LxResult
  NotifyAddClient (int argument, ILxUnknownID object)
  {
    return m_loc[0]->NotifyAddClient (m_loc,argument,(ILxUnknownID)object);
  }
    LxResult
  NotifyRemoveClient (ILxUnknownID object)
  {
    return m_loc[0]->NotifyRemoveClient (m_loc,(ILxUnknownID)object);
  }
    LxResult
  DialogFormatting (const char **formatting)
  {
    return m_loc[0]->DialogFormatting (m_loc,formatting);
  }
};

class CLxLoc_CommandService : public CLxLocalizedService
{
public:
  ILxCommandServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_CommandService() {_init();set();}
 ~CLxLoc_CommandService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxCommandServiceID>(lx::GetGlobal(&lx::guid_CommandService));}
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
  MasterStatus (unsigned int *status)
  {
    return m_loc[0]->MasterStatus (m_loc,status);
  }
    LxResult
  GetNameSep (unsigned int *sep)
  {
    return m_loc[0]->GetNameSep (m_loc,sep);
  }
    LxResult
  SetNameSep (unsigned int sep)
  {
    return m_loc[0]->SetNameSep (m_loc,sep);
  }
    LxResult
  Proto (LXtCommandTag tag, const char *name, void **ppvObj)
  {
    return m_loc[0]->Proto (m_loc,tag,name,ppvObj);
  }
    CLxResult
  Proto (LXtCommandTag tag, const char *name, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Proto(m_loc,tag,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ProtoFromCommand (ILxUnknownID cmd, void **ppvObj)
  {
    return m_loc[0]->ProtoFromCommand (m_loc,(ILxUnknownID)cmd,ppvObj);
  }
    CLxResult
  ProtoFromCommand (ILxUnknownID cmd, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ProtoFromCommand(m_loc,(ILxUnknownID)cmd,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Lookup (const char *name, LXtCommandTag *tag)
  {
    return m_loc[0]->Lookup (m_loc,name,tag);
  }
    LxResult
  Spawn (LXtCommandTag tag, const char *name, void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,tag,name,ppvObj);
  }
    CLxResult
  Spawn (LXtCommandTag tag, const char *name, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Spawn(m_loc,tag,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SpawnFromCommand (ILxUnknownID cmd, void **ppvObj)
  {
    return m_loc[0]->SpawnFromCommand (m_loc,(ILxUnknownID)cmd,ppvObj);
  }
    CLxResult
  SpawnFromCommand (ILxUnknownID cmd, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SpawnFromCommand(m_loc,(ILxUnknownID)cmd,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SpawnFromString (const char *args, unsigned int *execFlags, int *queryArgIndex, void **ppvObj)
  {
    return m_loc[0]->SpawnFromString (m_loc,args,execFlags,queryArgIndex,ppvObj);
  }
    CLxResult
  SpawnFromString (const char *args, unsigned int *execFlags, int *queryArgIndex, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SpawnFromString(m_loc,args,execFlags,queryArgIndex,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ExecuteArgString (unsigned int execFlags, LXtCommandTag tag, const char *args)
  {
    return m_loc[0]->ExecuteArgString (m_loc,execFlags,tag,args);
  }
    LxResult
  ExecuteToggleArgString (unsigned int execFlags, LXtCommandTag tag, const char *args, int newState)
  {
    return m_loc[0]->ExecuteToggleArgString (m_loc,execFlags,tag,args,newState);
  }
    LxResult
  IsToggleArgString (const char *string)
  {
    return m_loc[0]->IsToggleArgString (m_loc,string);
  }
    LxResult
  IsBooleanArgString (const char *string)
  {
    return m_loc[0]->IsBooleanArgString (m_loc,string);
  }
    LxResult
  ExecuteBooleanArgString (unsigned int execFlags, LXtCommandTag tag, const char *args)
  {
    return m_loc[0]->ExecuteBooleanArgString (m_loc,execFlags,tag,args);
  }
    LxResult
  ExecuteSpecial (unsigned int execFlags, ILxUnknownID cmd, int specialArgIndex)
  {
    return m_loc[0]->ExecuteSpecial (m_loc,execFlags,(ILxUnknownID)cmd,specialArgIndex);
  }
    LxResult
  ExecuteAttribObject (unsigned int execFlags, LXtCommandTag tag, const char *cmdName, ILxUnknownID attribArgs)
  {
    return m_loc[0]->ExecuteAttribObject (m_loc,execFlags,tag,cmdName,(ILxUnknownID)attribArgs);
  }
    LxResult
  ProcessStringFlags (unsigned int flags, const char *string, unsigned int *newFlags, const char **afterFlags)
  {
    return m_loc[0]->ProcessStringFlags (m_loc,flags,string,newFlags,afterFlags);
  }
    LxResult
  ExecFlagsAsPrefixString (unsigned int flags, char *buf, unsigned int len)
  {
    return m_loc[0]->ExecFlagsAsPrefixString (m_loc,flags,buf,len);
  }
    LxResult
  ExecFlagsAsPrefixString (unsigned int flags, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ExecFlagsAsPrefixString (m_loc,flags,buf,len);
    LXWx_SBUF2
  }
    LxResult
  SetToggleArgState (ILxUnknownID cmd, int state)
  {
    return m_loc[0]->SetToggleArgState (m_loc,(ILxUnknownID)cmd,state);
  }
    LxResult
  GetToggleArgState (ILxUnknownID cmd, int *state, void **ppvObj)
  {
    return m_loc[0]->GetToggleArgState (m_loc,(ILxUnknownID)cmd,state,ppvObj);
  }
    CLxResult
  GetToggleArgState (ILxUnknownID cmd, int *state, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetToggleArgState(m_loc,(ILxUnknownID)cmd,state,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  IsImplicitScript (const char *definition)
  {
    return m_loc[0]->IsImplicitScript (m_loc,definition);
  }
    LxResult
  SpawnImplicitScript (const char *definition, void **ppvObj)
  {
    return m_loc[0]->SpawnImplicitScript (m_loc,definition,ppvObj);
  }
    CLxResult
  SpawnImplicitScript (const char *definition, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SpawnImplicitScript(m_loc,definition,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ExecuteImplicitScript (const char *definition, unsigned int execFlags)
  {
    return m_loc[0]->ExecuteImplicitScript (m_loc,definition,execFlags);
  }
    LxResult
  RefireBegin (void)
  {
    return m_loc[0]->RefireBegin (m_loc);
  }
    LxResult
  RefireEnd (void)
  {
    return m_loc[0]->RefireEnd (m_loc);
  }
    LxResult
  RefireState (unsigned int *state)
  {
    return m_loc[0]->RefireState (m_loc,state);
  }
    LxResult
  RefireCmd (void **ppvObj)
  {
    return m_loc[0]->RefireCmd (m_loc,ppvObj);
  }
    CLxResult
  RefireCmd (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->RefireCmd(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RefireBlock (const char **name)
  {
    return m_loc[0]->RefireBlock (m_loc,name);
  }
    LxResult
  PostModeBegin (ILxUnknownID cmd, LXtCommandTag tag, const char *name, const char *args, ILxUnknownID postEndObj)
  {
    return m_loc[0]->PostModeBegin (m_loc,(ILxUnknownID)cmd,tag,name,args,(ILxUnknownID)postEndObj);
  }
    LxResult
  PostModeEnd (void)
  {
    return m_loc[0]->PostModeEnd (m_loc);
  }
    LxResult
  PostModeState (void)
  {
    return m_loc[0]->PostModeState (m_loc);
  }
    LxResult
  PostModeRestart (void)
  {
    return m_loc[0]->PostModeRestart (m_loc);
  }
    LxResult
  CurrentExecDepth (int *depth)
  {
    return m_loc[0]->CurrentExecDepth (m_loc,depth);
  }
    LxResult
  BlockBegin (const char *name, unsigned int flags)
  {
    return m_loc[0]->BlockBegin (m_loc,name,flags);
  }
    LxResult
  BlockEnd (void)
  {
    return m_loc[0]->BlockEnd (m_loc);
  }
    LxResult
  BlockCurrent (void **block)
  {
    return m_loc[0]->BlockCurrent (m_loc,block);
  }
    LxResult
  SandboxFlags (unsigned int *flags)
  {
    return m_loc[0]->SandboxFlags (m_loc,flags);
  }
    LxResult
  SandboxAddObject (ILxUnknownID object)
  {
    return m_loc[0]->SandboxAddObject (m_loc,(ILxUnknownID)object);
  }
    LxResult
  SandboxObjectCount (unsigned int *count)
  {
    return m_loc[0]->SandboxObjectCount (m_loc,count);
  }
    LxResult
  SandboxObjectByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->SandboxObjectByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  SandboxObjectByIndex (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SandboxObjectByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SandboxObjectLookup (const LXtGUID *guid, void **ppvObj)
  {
    return m_loc[0]->SandboxObjectLookup (m_loc,guid,ppvObj);
  }
    CLxResult
  SandboxObjectLookup (const LXtGUID *guid, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SandboxObjectLookup(m_loc,guid,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SandboxObjectByCommand (ILxUnknownID cmd, void **ppvObj)
  {
    return m_loc[0]->SandboxObjectByCommand (m_loc,(ILxUnknownID)cmd,ppvObj);
  }
    CLxResult
  SandboxObjectByCommand (ILxUnknownID cmd, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SandboxObjectByCommand(m_loc,(ILxUnknownID)cmd,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SandboxBegin (unsigned int flags)
  {
    return m_loc[0]->SandboxBegin (m_loc,flags);
  }
    LxResult
  SandboxState (void)
  {
    return m_loc[0]->SandboxState (m_loc);
  }
    LxResult
  SandboxEnd (void)
  {
    return m_loc[0]->SandboxEnd (m_loc);
  }
    LxResult
  ParseArgString (ILxUnknownID cmd, int alertFlags, const char *args)
  {
    return m_loc[0]->ParseArgString (m_loc,(ILxUnknownID)cmd,alertFlags,args);
  }
    LxResult
  ParseAttribObject (ILxUnknownID cmd, unsigned int alertFlags, ILxUnknownID attribArgs)
  {
    return m_loc[0]->ParseAttribObject (m_loc,(ILxUnknownID)cmd,alertFlags,(ILxUnknownID)attribArgs);
  }
    LxResult
  Usage (ILxUnknownID cmd, const char **buffer)
  {
    return m_loc[0]->Usage (m_loc,(ILxUnknownID)cmd,buffer);
  }
    LxResult
  ArgsAsString (ILxUnknownID cmd, char *buf, unsigned int len, unsigned int includeCmd)
  {
    return m_loc[0]->ArgsAsString (m_loc,(ILxUnknownID)cmd,buf,len,includeCmd);
  }
    LxResult
  ArgsAsString (ILxUnknownID cmd, std::string &result, unsigned int includeCmd)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ArgsAsString (m_loc,(ILxUnknownID)cmd,buf,len,includeCmd);
    LXWx_SBUF2
  }
    LxResult
  Query (ILxUnknownID cmd, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->Query (m_loc,(ILxUnknownID)cmd,index,ppvObj);
  }
    CLxResult
  Query (ILxUnknownID cmd, unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Query(m_loc,(ILxUnknownID)cmd,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  QueryArgString (ILxUnknownID cmd, unsigned int alertFlags, const char *args, void **ppvObj, unsigned int *queryIndex, unsigned int includesCmdName)
  {
    return m_loc[0]->QueryArgString (m_loc,(ILxUnknownID)cmd,alertFlags,args,ppvObj,queryIndex,includesCmdName);
  }
    CLxResult
  QueryArgString (ILxUnknownID cmd, unsigned int alertFlags, const char *args, CLxLocalizedObject &o_dest, unsigned int *queryIndex, unsigned int includesCmdName)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->QueryArgString(m_loc,(ILxUnknownID)cmd,alertFlags,args,&o_obj,queryIndex,includesCmdName);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CreateQueryObject (const char *typeName, void **ppvObj)
  {
    return m_loc[0]->CreateQueryObject (m_loc,typeName,ppvObj);
  }
    CLxResult
  CreateQueryObject (const char *typeName, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateQueryObject(m_loc,typeName,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AliasCreate (const char *name, ILxUnknownID targetCmd, LXtCommandTag targetTag, const char *targetName, const char *args)
  {
    return m_loc[0]->AliasCreate (m_loc,name,(ILxUnknownID)targetCmd,targetTag,targetName,args);
  }
    LxResult
  AliasDelete (ILxUnknownID alias, LXtCommandTag tag, const char *name)
  {
    return m_loc[0]->AliasDelete (m_loc,(ILxUnknownID)alias,tag,name);
  }
    LxResult
  IsContainer (ILxUnknownID cmd)
  {
    return m_loc[0]->IsContainer (m_loc,(ILxUnknownID)cmd);
  }
    LxResult
  IsAliased (ILxUnknownID cmd)
  {
    return m_loc[0]->IsAliased (m_loc,(ILxUnknownID)cmd);
  }
    LxResult
  CommandCount (unsigned int *count)
  {
    return m_loc[0]->CommandCount (m_loc,count);
  }
    LxResult
  CommandByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->CommandByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  CommandByIndex (unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CommandByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ExecEntryType (int index, int *type)
  {
    return m_loc[0]->ExecEntryType (m_loc,index,type);
  }
    LxResult
  ExecEntryUserName (int index, const char **userName)
  {
    return m_loc[0]->ExecEntryUserName (m_loc,index,userName);
  }
    LxResult
  ExecEntryName (int index, const char **name)
  {
    return m_loc[0]->ExecEntryName (m_loc,index,name);
  }
    LxResult
  ExecEntryAsArgString (int index, char *buf, int len)
  {
    return m_loc[0]->ExecEntryAsArgString (m_loc,index,buf,len);
  }
    LxResult
  IsGlobalInteractionOK (void)
  {
    return m_loc[0]->IsGlobalInteractionOK (m_loc);
  }
    LxResult
  ArgsAsStringLen (ILxUnknownID cmd, char *buf, unsigned int len, unsigned int includeCmd)
  {
    return m_loc[0]->ArgsAsStringLen (m_loc,(ILxUnknownID)cmd,buf,len,includeCmd);
  }
    LxResult
  ArgsAsStringLen (ILxUnknownID cmd, std::string &result, unsigned int includeCmd)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ArgsAsStringLen (m_loc,(ILxUnknownID)cmd,buf,len,includeCmd);
    LXWx_SBUF2
  }
    LxResult
  SpawnUnaliased (LXtCommandTag tag, const char *name, void **ppvObj)
  {
    return m_loc[0]->SpawnUnaliased (m_loc,tag,name,ppvObj);
  }
    CLxResult
  SpawnUnaliased (LXtCommandTag tag, const char *name, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SpawnUnaliased(m_loc,tag,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetIsGlobalInteractionOK (int isOK)
  {
    return m_loc[0]->SetIsGlobalInteractionOK (m_loc,isOK);
  }
    LxResult
  ExecuteArgString2 (unsigned int execFlags, LXtCommandTag tag, const char *args, void **ppvObj)
  {
    return m_loc[0]->ExecuteArgString2 (m_loc,execFlags,tag,args,ppvObj);
  }
    CLxResult
  ExecuteArgString2 (unsigned int execFlags, LXtCommandTag tag, const char *args, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ExecuteArgString2(m_loc,execFlags,tag,args,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ExecuteToggleArgString2 (unsigned int execFlags, LXtCommandTag tag, const char *args, int newState, void **ppvObj)
  {
    return m_loc[0]->ExecuteToggleArgString2 (m_loc,execFlags,tag,args,newState,ppvObj);
  }
    CLxResult
  ExecuteToggleArgString2 (unsigned int execFlags, LXtCommandTag tag, const char *args, int newState, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ExecuteToggleArgString2(m_loc,execFlags,tag,args,newState,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ExecuteBooleanArgString2 (unsigned int execFlags, LXtCommandTag tag, const char *args, void **ppvObj)
  {
    return m_loc[0]->ExecuteBooleanArgString2 (m_loc,execFlags,tag,args,ppvObj);
  }
    CLxResult
  ExecuteBooleanArgString2 (unsigned int execFlags, LXtCommandTag tag, const char *args, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ExecuteBooleanArgString2(m_loc,execFlags,tag,args,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ExecuteAttribObject2 (unsigned int execFlags, LXtCommandTag tag, const char *cmdName, ILxUnknownID attribArgs, void **ppvObj)
  {
    return m_loc[0]->ExecuteAttribObject2 (m_loc,execFlags,tag,cmdName,(ILxUnknownID)attribArgs,ppvObj);
  }
    CLxResult
  ExecuteAttribObject2 (unsigned int execFlags, LXtCommandTag tag, const char *cmdName, ILxUnknownID attribArgs, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ExecuteAttribObject2(m_loc,execFlags,tag,cmdName,(ILxUnknownID)attribArgs,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ExecuteImplicitScript2 (const char *definition, unsigned int execFlags, void **ppvObj)
  {
    return m_loc[0]->ExecuteImplicitScript2 (m_loc,definition,execFlags,ppvObj);
  }
    CLxResult
  ExecuteImplicitScript2 (const char *definition, unsigned int execFlags, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ExecuteImplicitScript2(m_loc,definition,execFlags,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AllocateUIHintsFromCommand (ILxUnknownID cmd, int argIndex, void **ppvObj)
  {
    return m_loc[0]->AllocateUIHintsFromCommand (m_loc,(ILxUnknownID)cmd,argIndex,ppvObj);
  }
    CLxResult
  AllocateUIHintsFromCommand (ILxUnknownID cmd, int argIndex, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AllocateUIHintsFromCommand(m_loc,(ILxUnknownID)cmd,argIndex,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  DoAtEndOfRootLevelUndoableCommand (ILxUnknownID visitor)
  {
    return m_loc[0]->DoAtEndOfRootLevelUndoableCommand (m_loc,(ILxUnknownID)visitor);
  }
    LxResult
  CancelDoAtEndOfRootLevelUndoableCommand (ILxUnknownID visitor)
  {
    return m_loc[0]->CancelDoAtEndOfRootLevelUndoableCommand (m_loc,(ILxUnknownID)visitor);
  }
    LxResult
  ArgsAsStringWithOptions (ILxUnknownID cmd, char *buf, unsigned int len, int options)
  {
    return m_loc[0]->ArgsAsStringWithOptions (m_loc,(ILxUnknownID)cmd,buf,len,options);
  }
    LxResult
  ArgsAsStringWithOptions (ILxUnknownID cmd, std::string &result, int options)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ArgsAsStringWithOptions (m_loc,(ILxUnknownID)cmd,buf,len,options);
    LXWx_SBUF2
  }
    LxResult
  CurrentExecIsRoot (int ignoreBlocks)
  {
    return m_loc[0]->CurrentExecIsRoot (m_loc,ignoreBlocks);
  }
};

class CLxLoc_UIHints : public CLxLocalize<ILxUIHintsID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UIHints() {_init();}
  CLxLoc_UIHints(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UIHints(const CLxLoc_UIHints &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UIHints;}
    LxResult
  Class (const char *c)
  {
    return m_loc[0]->Class (m_loc,c);
  }
    LxResult
  Label (const char *label)
  {
    return m_loc[0]->Label (m_loc,label);
  }
    LxResult
  MinInt (int min)
  {
    return m_loc[0]->MinInt (m_loc,min);
  }
    LxResult
  MaxInt (int max)
  {
    return m_loc[0]->MaxInt (m_loc,max);
  }
    LxResult
  MinFloat (double min)
  {
    return m_loc[0]->MinFloat (m_loc,min);
  }
    LxResult
  MaxFloat (double max)
  {
    return m_loc[0]->MaxFloat (m_loc,max);
  }
    LxResult
  StepInt (int step)
  {
    return m_loc[0]->StepInt (m_loc,step);
  }
    LxResult
  StepFloat (double step)
  {
    return m_loc[0]->StepFloat (m_loc,step);
  }
    LxResult
  Track (unsigned int state)
  {
    return m_loc[0]->Track (m_loc,state);
  }
    LxResult
  StringList (const char **strings)
  {
    return m_loc[0]->StringList (m_loc,strings);
  }
    LxResult
  TextLines (unsigned int lines)
  {
    return m_loc[0]->TextLines (m_loc,lines);
  }
    LxResult
  TextFixedWidthFont (unsigned int state)
  {
    return m_loc[0]->TextFixedWidthFont (m_loc,state);
  }
    LxResult
  TextPasswordMode (unsigned int state)
  {
    return m_loc[0]->TextPasswordMode (m_loc,state);
  }
    LxResult
  ValuePresetCookie (const char *cookie)
  {
    return m_loc[0]->ValuePresetCookie (m_loc,cookie);
  }
    LxResult
  ForceUpdate (void)
  {
    return m_loc[0]->ForceUpdate (m_loc);
  }
    LxResult
  BooleanStyle (unsigned int style)
  {
    return m_loc[0]->BooleanStyle (m_loc,style);
  }
    LxResult
  ChannelFlags (unsigned int flags)
  {
    return m_loc[0]->ChannelFlags (m_loc,flags);
  }
    LxResult
  ButtonHasPopoverDecoration (int state)
  {
    return m_loc[0]->ButtonHasPopoverDecoration (m_loc,state);
  }
    LxResult
  ClipChoiceSupportsGroups (unsigned flags)
  {
    return m_loc[0]->ClipChoiceSupportsGroups (m_loc,flags);
  }
    LxResult
  VertmapType (LXtID4 type)
  {
    return m_loc[0]->VertmapType (m_loc,type);
  }
    LxResult
  VertmapAllowNone (int state)
  {
    return m_loc[0]->VertmapAllowNone (m_loc,state);
  }
    LxResult
  VertmapItemMode (int state)
  {
    return m_loc[0]->VertmapItemMode (m_loc,state);
  }
    LxResult
  InfoTextUseSmallFont (int state)
  {
    return m_loc[0]->InfoTextUseSmallFont (m_loc,state);
  }
    LxResult
  FormFilterPriority (int priority)
  {
    return m_loc[0]->FormFilterPriority (m_loc,priority);
  }
};


class CLxLoc_CommandDBHelp : public CLxLocalize<ILxCommandDBHelpID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CommandDBHelp() {_init();}
  CLxLoc_CommandDBHelp(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CommandDBHelp(const CLxLoc_CommandDBHelp &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CommandDBHelp;}
    LxResult
  DBHelp (const char **dbhelp)
  {
    return m_loc[0]->DBHelp (m_loc,dbhelp);
  }
    LxResult
  DBTooltip (const char **dbtooltip)
  {
    return m_loc[0]->DBTooltip (m_loc,dbtooltip);
  }
};

class CLxLoc_UIHintsRead : public CLxLocalize<ILxUIHintsReadID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UIHintsRead() {_init();}
  CLxLoc_UIHintsRead(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UIHintsRead(const CLxLoc_UIHintsRead &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UIHintsRead;}
    LxResult
  Class (char *buf, int len)
  {
    return m_loc[0]->Class (m_loc,buf,len);
  }
    LxResult
  Label (char *buf, int len)
  {
    return m_loc[0]->Label (m_loc,buf,len);
  }
    LxResult
  MinInt (int *min)
  {
    return m_loc[0]->MinInt (m_loc,min);
  }
    LxResult
  MaxInt (int *max)
  {
    return m_loc[0]->MaxInt (m_loc,max);
  }
    LxResult
  MinFloat (double *min)
  {
    return m_loc[0]->MinFloat (m_loc,min);
  }
    LxResult
  MaxFloat (double *max)
  {
    return m_loc[0]->MaxFloat (m_loc,max);
  }
    LxResult
  StepInt (int *step)
  {
    return m_loc[0]->StepInt (m_loc,step);
  }
    LxResult
  StepFloat (double *step)
  {
    return m_loc[0]->StepFloat (m_loc,step);
  }
    LxResult
  Track (unsigned int *state)
  {
    return m_loc[0]->Track (m_loc,state);
  }
    LxResult
  StringListCount (int *count)
  {
    return m_loc[0]->StringListCount (m_loc,count);
  }
    LxResult
  StringListByIndex (int index, char *buf, int len)
  {
    return m_loc[0]->StringListByIndex (m_loc,index,buf,len);
  }
    LxResult
  TextLines (unsigned int *lines)
  {
    return m_loc[0]->TextLines (m_loc,lines);
  }
    LxResult
  TextFixedWidthFont (unsigned int *state)
  {
    return m_loc[0]->TextFixedWidthFont (m_loc,state);
  }
    LxResult
  TextPasswordMode (unsigned int *state)
  {
    return m_loc[0]->TextPasswordMode (m_loc,state);
  }
    LxResult
  ValuePresetCookie (char *buf, int len)
  {
    return m_loc[0]->ValuePresetCookie (m_loc,buf,len);
  }
    LxResult
  ForceUpdate (int *state)
  {
    return m_loc[0]->ForceUpdate (m_loc,state);
  }
    LxResult
  BooleanStyle (unsigned int *style)
  {
    return m_loc[0]->BooleanStyle (m_loc,style);
  }
    LxResult
  ChannelFlags (unsigned int *flags)
  {
    return m_loc[0]->ChannelFlags (m_loc,flags);
  }
    LxResult
  ButtonHasPopoverDecoration (int *state)
  {
    return m_loc[0]->ButtonHasPopoverDecoration (m_loc,state);
  }
    LxResult
  ClipChoiceSupportsGroups (unsigned *flags)
  {
    return m_loc[0]->ClipChoiceSupportsGroups (m_loc,flags);
  }
    LxResult
  VertmapType (LXtID4 *type)
  {
    return m_loc[0]->VertmapType (m_loc,type);
  }
    LxResult
  VertmapAllowNone (int *state)
  {
    return m_loc[0]->VertmapAllowNone (m_loc,state);
  }
    LxResult
  VertmapItemMode (int *state)
  {
    return m_loc[0]->VertmapItemMode (m_loc,state);
  }
    LxResult
  InfoTextUseSmallFont (int *state)
  {
    return m_loc[0]->InfoTextUseSmallFont (m_loc,state);
  }
    LxResult
  FormFilterPriority (int *priority)
  {
    return m_loc[0]->FormFilterPriority (m_loc,priority);
  }
};

class CLxImpl_Command1 {
  public:
    virtual ~CLxImpl_Command1() {}
    virtual LxResult
      cmd1_Tag (LXtCommandTag *tag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_UserName (const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ButtonName (const char **buttonName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Desc (const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Tooltip (const char **tooltip)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Help (const char **help)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Example (const char **example)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Icon (const char **iconNames)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Flags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_PostExecFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_PostExecBehaviorFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_PostExecHints (unsigned int *hints)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_SandboxGUID (const LXtGUID **guid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Message (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ContainedEnable (LXtID4 *types)
        { return LXe_NOTIMPL; }
    virtual void
      cmd1_Interact (void)
        { }
    virtual void
      cmd1_PreExecute (void)
        { }
    virtual void
      cmd1_Execute (unsigned int flags)
        { }
    virtual LxResult
      cmd1_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgFlags (unsigned int index, unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgClear (unsigned int index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgResetAll (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgSetDatatypes (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgUserName (unsigned int index, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgDesc (unsigned int index, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgExample (unsigned int index, const char **example)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgType (unsigned int index, const char **type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgTypeUserName (unsigned int index, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgTypeDesc (unsigned int index, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_DialogInit (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_DialogArgChange (unsigned int arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgEnable (unsigned int arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgParseString (unsigned int argIndex, const char *argString)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Copy (ILxUnknownID sourceCommand)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Query (unsigned int index, ILxUnknownID vaQuery)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_NotifyAddClient (int argument, ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_NotifyRemoveClient (ILxUnknownID object)
        { return LXe_NOTIMPL; }
};
#define LXxD_Command1_Tag LxResult cmd1_Tag (LXtCommandTag *tag)
#define LXxO_Command1_Tag LXxD_Command1_Tag LXx_OVERRIDE
#define LXxC_Command1_Tag(c) LxResult c::cmd1_Tag (LXtCommandTag *tag)
#define LXxD_Command1_Name LxResult cmd1_Name (const char **name)
#define LXxO_Command1_Name LXxD_Command1_Name LXx_OVERRIDE
#define LXxC_Command1_Name(c) LxResult c::cmd1_Name (const char **name)
#define LXxD_Command1_UserName LxResult cmd1_UserName (const char **userName)
#define LXxO_Command1_UserName LXxD_Command1_UserName LXx_OVERRIDE
#define LXxC_Command1_UserName(c) LxResult c::cmd1_UserName (const char **userName)
#define LXxD_Command1_ButtonName LxResult cmd1_ButtonName (const char **buttonName)
#define LXxO_Command1_ButtonName LXxD_Command1_ButtonName LXx_OVERRIDE
#define LXxC_Command1_ButtonName(c) LxResult c::cmd1_ButtonName (const char **buttonName)
#define LXxD_Command1_Desc LxResult cmd1_Desc (const char **desc)
#define LXxO_Command1_Desc LXxD_Command1_Desc LXx_OVERRIDE
#define LXxC_Command1_Desc(c) LxResult c::cmd1_Desc (const char **desc)
#define LXxD_Command1_Tooltip LxResult cmd1_Tooltip (const char **tooltip)
#define LXxO_Command1_Tooltip LXxD_Command1_Tooltip LXx_OVERRIDE
#define LXxC_Command1_Tooltip(c) LxResult c::cmd1_Tooltip (const char **tooltip)
#define LXxD_Command1_Help LxResult cmd1_Help (const char **help)
#define LXxO_Command1_Help LXxD_Command1_Help LXx_OVERRIDE
#define LXxC_Command1_Help(c) LxResult c::cmd1_Help (const char **help)
#define LXxD_Command1_Example LxResult cmd1_Example (const char **example)
#define LXxO_Command1_Example LXxD_Command1_Example LXx_OVERRIDE
#define LXxC_Command1_Example(c) LxResult c::cmd1_Example (const char **example)
#define LXxD_Command1_Icon LxResult cmd1_Icon (const char **iconNames)
#define LXxO_Command1_Icon LXxD_Command1_Icon LXx_OVERRIDE
#define LXxC_Command1_Icon(c) LxResult c::cmd1_Icon (const char **iconNames)
#define LXxD_Command1_Flags LxResult cmd1_Flags (unsigned int *flags)
#define LXxO_Command1_Flags LXxD_Command1_Flags LXx_OVERRIDE
#define LXxC_Command1_Flags(c) LxResult c::cmd1_Flags (unsigned int *flags)
#define LXxD_Command1_PostExecFlags LxResult cmd1_PostExecFlags (unsigned int *flags)
#define LXxO_Command1_PostExecFlags LXxD_Command1_PostExecFlags LXx_OVERRIDE
#define LXxC_Command1_PostExecFlags(c) LxResult c::cmd1_PostExecFlags (unsigned int *flags)
#define LXxD_Command1_PostExecBehaviorFlags LxResult cmd1_PostExecBehaviorFlags (unsigned int *flags)
#define LXxO_Command1_PostExecBehaviorFlags LXxD_Command1_PostExecBehaviorFlags LXx_OVERRIDE
#define LXxC_Command1_PostExecBehaviorFlags(c) LxResult c::cmd1_PostExecBehaviorFlags (unsigned int *flags)
#define LXxD_Command1_PostExecHints LxResult cmd1_PostExecHints (unsigned int *hints)
#define LXxO_Command1_PostExecHints LXxD_Command1_PostExecHints LXx_OVERRIDE
#define LXxC_Command1_PostExecHints(c) LxResult c::cmd1_PostExecHints (unsigned int *hints)
#define LXxD_Command1_SandboxGUID LxResult cmd1_SandboxGUID (const LXtGUID **guid)
#define LXxO_Command1_SandboxGUID LXxD_Command1_SandboxGUID LXx_OVERRIDE
#define LXxC_Command1_SandboxGUID(c) LxResult c::cmd1_SandboxGUID (const LXtGUID **guid)
#define LXxD_Command1_Message LxResult cmd1_Message (void **ppvObj)
#define LXxO_Command1_Message LXxD_Command1_Message LXx_OVERRIDE
#define LXxC_Command1_Message(c) LxResult c::cmd1_Message (void **ppvObj)
#define LXxD_Command1_Enable LxResult cmd1_Enable (ILxUnknownID msg)
#define LXxO_Command1_Enable LXxD_Command1_Enable LXx_OVERRIDE
#define LXxC_Command1_Enable(c) LxResult c::cmd1_Enable (ILxUnknownID msg)
#define LXxD_Command1_ContainedEnable LxResult cmd1_ContainedEnable (LXtID4 *types)
#define LXxO_Command1_ContainedEnable LXxD_Command1_ContainedEnable LXx_OVERRIDE
#define LXxC_Command1_ContainedEnable(c) LxResult c::cmd1_ContainedEnable (LXtID4 *types)
#define LXxD_Command1_Interact void cmd1_Interact (void)
#define LXxO_Command1_Interact LXxD_Command1_Interact LXx_OVERRIDE
#define LXxC_Command1_Interact(c) void c::cmd1_Interact (void)
#define LXxD_Command1_PreExecute void cmd1_PreExecute (void)
#define LXxO_Command1_PreExecute LXxD_Command1_PreExecute LXx_OVERRIDE
#define LXxC_Command1_PreExecute(c) void c::cmd1_PreExecute (void)
#define LXxD_Command1_Execute void cmd1_Execute (unsigned int flags)
#define LXxO_Command1_Execute LXxD_Command1_Execute LXx_OVERRIDE
#define LXxC_Command1_Execute(c) void c::cmd1_Execute (unsigned int flags)
#define LXxD_Command1_ToggleArg LxResult cmd1_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
#define LXxO_Command1_ToggleArg LXxD_Command1_ToggleArg LXx_OVERRIDE
#define LXxC_Command1_ToggleArg(c) LxResult c::cmd1_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
#define LXxD_Command1_ArgFlags LxResult cmd1_ArgFlags (unsigned int index, unsigned int *flags)
#define LXxO_Command1_ArgFlags LXxD_Command1_ArgFlags LXx_OVERRIDE
#define LXxC_Command1_ArgFlags(c) LxResult c::cmd1_ArgFlags (unsigned int index, unsigned int *flags)
#define LXxD_Command1_ArgClear LxResult cmd1_ArgClear (unsigned int index)
#define LXxO_Command1_ArgClear LXxD_Command1_ArgClear LXx_OVERRIDE
#define LXxC_Command1_ArgClear(c) LxResult c::cmd1_ArgClear (unsigned int index)
#define LXxD_Command1_ArgResetAll LxResult cmd1_ArgResetAll (void)
#define LXxO_Command1_ArgResetAll LXxD_Command1_ArgResetAll LXx_OVERRIDE
#define LXxC_Command1_ArgResetAll(c) LxResult c::cmd1_ArgResetAll (void)
#define LXxD_Command1_ArgSetDatatypes LxResult cmd1_ArgSetDatatypes (void)
#define LXxO_Command1_ArgSetDatatypes LXxD_Command1_ArgSetDatatypes LXx_OVERRIDE
#define LXxC_Command1_ArgSetDatatypes(c) LxResult c::cmd1_ArgSetDatatypes (void)
#define LXxD_Command1_ArgUserName LxResult cmd1_ArgUserName (unsigned int index, const char **userName)
#define LXxO_Command1_ArgUserName LXxD_Command1_ArgUserName LXx_OVERRIDE
#define LXxC_Command1_ArgUserName(c) LxResult c::cmd1_ArgUserName (unsigned int index, const char **userName)
#define LXxD_Command1_ArgDesc LxResult cmd1_ArgDesc (unsigned int index, const char **desc)
#define LXxO_Command1_ArgDesc LXxD_Command1_ArgDesc LXx_OVERRIDE
#define LXxC_Command1_ArgDesc(c) LxResult c::cmd1_ArgDesc (unsigned int index, const char **desc)
#define LXxD_Command1_ArgExample LxResult cmd1_ArgExample (unsigned int index, const char **example)
#define LXxO_Command1_ArgExample LXxD_Command1_ArgExample LXx_OVERRIDE
#define LXxC_Command1_ArgExample(c) LxResult c::cmd1_ArgExample (unsigned int index, const char **example)
#define LXxD_Command1_ArgType LxResult cmd1_ArgType (unsigned int index, const char **type)
#define LXxO_Command1_ArgType LXxD_Command1_ArgType LXx_OVERRIDE
#define LXxC_Command1_ArgType(c) LxResult c::cmd1_ArgType (unsigned int index, const char **type)
#define LXxD_Command1_ArgTypeUserName LxResult cmd1_ArgTypeUserName (unsigned int index, const char **userName)
#define LXxO_Command1_ArgTypeUserName LXxD_Command1_ArgTypeUserName LXx_OVERRIDE
#define LXxC_Command1_ArgTypeUserName(c) LxResult c::cmd1_ArgTypeUserName (unsigned int index, const char **userName)
#define LXxD_Command1_ArgTypeDesc LxResult cmd1_ArgTypeDesc (unsigned int index, const char **desc)
#define LXxO_Command1_ArgTypeDesc LXxD_Command1_ArgTypeDesc LXx_OVERRIDE
#define LXxC_Command1_ArgTypeDesc(c) LxResult c::cmd1_ArgTypeDesc (unsigned int index, const char **desc)
#define LXxD_Command1_ArgOptionUserName LxResult cmd1_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
#define LXxO_Command1_ArgOptionUserName LXxD_Command1_ArgOptionUserName LXx_OVERRIDE
#define LXxC_Command1_ArgOptionUserName(c) LxResult c::cmd1_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
#define LXxD_Command1_ArgOptionDesc LxResult cmd1_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
#define LXxO_Command1_ArgOptionDesc LXxD_Command1_ArgOptionDesc LXx_OVERRIDE
#define LXxC_Command1_ArgOptionDesc(c) LxResult c::cmd1_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
#define LXxD_Command1_DialogInit LxResult cmd1_DialogInit (void)
#define LXxO_Command1_DialogInit LXxD_Command1_DialogInit LXx_OVERRIDE
#define LXxC_Command1_DialogInit(c) LxResult c::cmd1_DialogInit (void)
#define LXxD_Command1_DialogArgChange LxResult cmd1_DialogArgChange (unsigned int arg)
#define LXxO_Command1_DialogArgChange LXxD_Command1_DialogArgChange LXx_OVERRIDE
#define LXxC_Command1_DialogArgChange(c) LxResult c::cmd1_DialogArgChange (unsigned int arg)
#define LXxD_Command1_ArgEnable LxResult cmd1_ArgEnable (unsigned int arg)
#define LXxO_Command1_ArgEnable LXxD_Command1_ArgEnable LXx_OVERRIDE
#define LXxC_Command1_ArgEnable(c) LxResult c::cmd1_ArgEnable (unsigned int arg)
#define LXxD_Command1_ArgParseString LxResult cmd1_ArgParseString (unsigned int argIndex, const char *argString)
#define LXxO_Command1_ArgParseString LXxD_Command1_ArgParseString LXx_OVERRIDE
#define LXxC_Command1_ArgParseString(c) LxResult c::cmd1_ArgParseString (unsigned int argIndex, const char *argString)
#define LXxD_Command1_Copy LxResult cmd1_Copy (ILxUnknownID sourceCommand)
#define LXxO_Command1_Copy LXxD_Command1_Copy LXx_OVERRIDE
#define LXxC_Command1_Copy(c) LxResult c::cmd1_Copy (ILxUnknownID sourceCommand)
#define LXxD_Command1_Query LxResult cmd1_Query (unsigned int index, ILxUnknownID vaQuery)
#define LXxO_Command1_Query LXxD_Command1_Query LXx_OVERRIDE
#define LXxC_Command1_Query(c) LxResult c::cmd1_Query (unsigned int index, ILxUnknownID vaQuery)
#define LXxD_Command1_NotifyAddClient LxResult cmd1_NotifyAddClient (int argument, ILxUnknownID object)
#define LXxO_Command1_NotifyAddClient LXxD_Command1_NotifyAddClient LXx_OVERRIDE
#define LXxC_Command1_NotifyAddClient(c) LxResult c::cmd1_NotifyAddClient (int argument, ILxUnknownID object)
#define LXxD_Command1_NotifyRemoveClient LxResult cmd1_NotifyRemoveClient (ILxUnknownID object)
#define LXxO_Command1_NotifyRemoveClient LXxD_Command1_NotifyRemoveClient LXx_OVERRIDE
#define LXxC_Command1_NotifyRemoveClient(c) LxResult c::cmd1_NotifyRemoveClient (ILxUnknownID object)
template <class T>
class CLxIfc_Command1 : public CLxInterface
{
    static LxResult
  Tag (LXtObjectID wcom, LXtCommandTag *tag)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Tag (tag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UserName (LXtObjectID wcom, const char **userName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_UserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ButtonName (LXtObjectID wcom, const char **buttonName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ButtonName (buttonName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Desc (LXtObjectID wcom, const char **desc)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Desc (desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Tooltip (LXtObjectID wcom, const char **tooltip)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Tooltip (tooltip);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Help (LXtObjectID wcom, const char **help)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Help (help);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Example (LXtObjectID wcom, const char **example)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Example (example);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Icon (LXtObjectID wcom, const char **iconNames)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Icon (iconNames);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Flags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Flags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_PostExecFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecBehaviorFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_PostExecBehaviorFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecHints (LXtObjectID wcom, unsigned int *hints)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_PostExecHints (hints);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SandboxGUID (LXtObjectID wcom, const LXtGUID **guid)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_SandboxGUID (guid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Message (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Message (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ContainedEnable (LXtObjectID wcom, LXtID4 *types)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ContainedEnable (types);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Interact (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    loc->cmd1_Interact ();
  }
    static void
  PreExecute (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    loc->cmd1_PreExecute ();
  }
    static void
  Execute (LXtObjectID wcom, unsigned int flags)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    loc->cmd1_Execute (flags);
  }
    static LxResult
  ToggleArg (LXtObjectID wcom, unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ToggleArg (index,ppvObj,typeID,typeName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgFlags (LXtObjectID wcom, unsigned int index, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgClear (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgClear (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgResetAll (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgResetAll ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgSetDatatypes (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgSetDatatypes ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgUserName (LXtObjectID wcom, unsigned int index, const char **userName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgUserName (index,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgDesc (LXtObjectID wcom, unsigned int index, const char **desc)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgDesc (index,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgExample (LXtObjectID wcom, unsigned int index, const char **example)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgExample (index,example);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgType (LXtObjectID wcom, unsigned int index, const char **type)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgType (index,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgTypeUserName (LXtObjectID wcom, unsigned int index, const char **userName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgTypeUserName (index,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgTypeDesc (LXtObjectID wcom, unsigned int index, const char **desc)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgTypeDesc (index,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionUserName (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **userName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgOptionUserName (index,optIndex,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionDesc (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **desc)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgOptionDesc (index,optIndex,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogInit (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_DialogInit ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogArgChange (LXtObjectID wcom, unsigned int arg)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_DialogArgChange (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgEnable (LXtObjectID wcom, unsigned int arg)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgEnable (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgParseString (LXtObjectID wcom, unsigned int argIndex, const char *argString)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgParseString (argIndex,argString);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Copy (LXtObjectID wcom, LXtObjectID sourceCommand)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Copy ((ILxUnknownID)sourceCommand);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Query (LXtObjectID wcom, unsigned int index, LXtObjectID vaQuery)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Query (index,(ILxUnknownID)vaQuery);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifyAddClient (LXtObjectID wcom, int argument, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_NotifyAddClient (argument,(ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifyRemoveClient (LXtObjectID wcom, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_NotifyRemoveClient ((ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
  ILxCommand1 vt;
public:
  CLxIfc_Command1 ()
  {
    vt.Tag = Tag;
    vt.Name = Name;
    vt.UserName = UserName;
    vt.ButtonName = ButtonName;
    vt.Desc = Desc;
    vt.Tooltip = Tooltip;
    vt.Help = Help;
    vt.Example = Example;
    vt.Icon = Icon;
    vt.Flags = Flags;
    vt.PostExecFlags = PostExecFlags;
    vt.PostExecBehaviorFlags = PostExecBehaviorFlags;
    vt.PostExecHints = PostExecHints;
    vt.SandboxGUID = SandboxGUID;
    vt.Message = Message;
    vt.Enable = Enable;
    vt.ContainedEnable = ContainedEnable;
    vt.Interact = Interact;
    vt.PreExecute = PreExecute;
    vt.Execute = Execute;
    vt.ToggleArg = ToggleArg;
    vt.ArgFlags = ArgFlags;
    vt.ArgClear = ArgClear;
    vt.ArgResetAll = ArgResetAll;
    vt.ArgSetDatatypes = ArgSetDatatypes;
    vt.ArgUserName = ArgUserName;
    vt.ArgDesc = ArgDesc;
    vt.ArgExample = ArgExample;
    vt.ArgType = ArgType;
    vt.ArgTypeUserName = ArgTypeUserName;
    vt.ArgTypeDesc = ArgTypeDesc;
    vt.ArgOptionUserName = ArgOptionUserName;
    vt.ArgOptionDesc = ArgOptionDesc;
    vt.DialogInit = DialogInit;
    vt.DialogArgChange = DialogArgChange;
    vt.ArgEnable = ArgEnable;
    vt.ArgParseString = ArgParseString;
    vt.Copy = Copy;
    vt.Query = Query;
    vt.NotifyAddClient = NotifyAddClient;
    vt.NotifyRemoveClient = NotifyRemoveClient;
    vTable = &vt.iunk;
    iid = &lx::guid_Command1;
  }
};
class CLxLoc_Command1 : public CLxLocalize<ILxCommand1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Command1() {_init();}
  CLxLoc_Command1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Command1(const CLxLoc_Command1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Command1;}
    LxResult
  Tag (LXtCommandTag *tag)
  {
    return m_loc[0]->Tag (m_loc,tag);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  UserName (const char **userName)
  {
    return m_loc[0]->UserName (m_loc,userName);
  }
    LxResult
  ButtonName (const char **buttonName)
  {
    return m_loc[0]->ButtonName (m_loc,buttonName);
  }
    LxResult
  Desc (const char **desc)
  {
    return m_loc[0]->Desc (m_loc,desc);
  }
    LxResult
  Tooltip (const char **tooltip)
  {
    return m_loc[0]->Tooltip (m_loc,tooltip);
  }
    LxResult
  Help (const char **help)
  {
    return m_loc[0]->Help (m_loc,help);
  }
    LxResult
  Example (const char **example)
  {
    return m_loc[0]->Example (m_loc,example);
  }
    LxResult
  Icon (const char **iconNames)
  {
    return m_loc[0]->Icon (m_loc,iconNames);
  }
    LxResult
  Flags (unsigned int *flags)
  {
    return m_loc[0]->Flags (m_loc,flags);
  }
    LxResult
  PostExecFlags (unsigned int *flags)
  {
    return m_loc[0]->PostExecFlags (m_loc,flags);
  }
    LxResult
  PostExecBehaviorFlags (unsigned int *flags)
  {
    return m_loc[0]->PostExecBehaviorFlags (m_loc,flags);
  }
    LxResult
  PostExecHints (unsigned int *hints)
  {
    return m_loc[0]->PostExecHints (m_loc,hints);
  }
    LxResult
  SandboxGUID (const LXtGUID **guid)
  {
    return m_loc[0]->SandboxGUID (m_loc,guid);
  }
    LxResult
  Message (void **ppvObj)
  {
    return m_loc[0]->Message (m_loc,ppvObj);
  }
    CLxResult
  Message (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Message(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  ContainedEnable (LXtID4 *types)
  {
    return m_loc[0]->ContainedEnable (m_loc,types);
  }
    void
  Interact (void)
  {
    m_loc[0]->Interact (m_loc);
  }
    void
  PreExecute (void)
  {
    m_loc[0]->PreExecute (m_loc);
  }
    void
  Execute (unsigned int flags)
  {
    m_loc[0]->Execute (m_loc,flags);
  }
    LxResult
  ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
  {
    return m_loc[0]->ToggleArg (m_loc,index,ppvObj,typeID,typeName);
  }
    CLxResult
  ToggleArg (unsigned int *index, CLxLocalizedObject &o_dest, unsigned int *typeID, const char **typeName)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ToggleArg(m_loc,index,&o_obj,typeID,typeName);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ArgFlags (unsigned int index, unsigned int *flags)
  {
    return m_loc[0]->ArgFlags (m_loc,index,flags);
  }
    LxResult
  ArgClear (unsigned int index)
  {
    return m_loc[0]->ArgClear (m_loc,index);
  }
    LxResult
  ArgResetAll (void)
  {
    return m_loc[0]->ArgResetAll (m_loc);
  }
    LxResult
  ArgSetDatatypes (void)
  {
    return m_loc[0]->ArgSetDatatypes (m_loc);
  }
    LxResult
  ArgUserName (unsigned int index, const char **userName)
  {
    return m_loc[0]->ArgUserName (m_loc,index,userName);
  }
    LxResult
  ArgDesc (unsigned int index, const char **desc)
  {
    return m_loc[0]->ArgDesc (m_loc,index,desc);
  }
    LxResult
  ArgExample (unsigned int index, const char **example)
  {
    return m_loc[0]->ArgExample (m_loc,index,example);
  }
    LxResult
  ArgType (unsigned int index, const char **type)
  {
    return m_loc[0]->ArgType (m_loc,index,type);
  }
    LxResult
  ArgTypeUserName (unsigned int index, const char **userName)
  {
    return m_loc[0]->ArgTypeUserName (m_loc,index,userName);
  }
    LxResult
  ArgTypeDesc (unsigned int index, const char **desc)
  {
    return m_loc[0]->ArgTypeDesc (m_loc,index,desc);
  }
    LxResult
  ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
  {
    return m_loc[0]->ArgOptionUserName (m_loc,index,optIndex,userName);
  }
    LxResult
  ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
  {
    return m_loc[0]->ArgOptionDesc (m_loc,index,optIndex,desc);
  }
    LxResult
  DialogInit (void)
  {
    return m_loc[0]->DialogInit (m_loc);
  }
    LxResult
  DialogArgChange (unsigned int arg)
  {
    return m_loc[0]->DialogArgChange (m_loc,arg);
  }
    LxResult
  ArgEnable (unsigned int arg)
  {
    return m_loc[0]->ArgEnable (m_loc,arg);
  }
    LxResult
  ArgParseString (unsigned int argIndex, const char *argString)
  {
    return m_loc[0]->ArgParseString (m_loc,argIndex,argString);
  }
    LxResult
  Copy (ILxUnknownID sourceCommand)
  {
    return m_loc[0]->Copy (m_loc,(ILxUnknownID)sourceCommand);
  }
    LxResult
  Query (unsigned int index, ILxUnknownID vaQuery)
  {
    return m_loc[0]->Query (m_loc,index,(ILxUnknownID)vaQuery);
  }
    LxResult
  NotifyAddClient (int argument, ILxUnknownID object)
  {
    return m_loc[0]->NotifyAddClient (m_loc,argument,(ILxUnknownID)object);
  }
    LxResult
  NotifyRemoveClient (ILxUnknownID object)
  {
    return m_loc[0]->NotifyRemoveClient (m_loc,(ILxUnknownID)object);
  }
};

class CLxImpl_UIValueHints3 {
  public:
    virtual ~CLxImpl_UIValueHints3() {}
    virtual unsigned
      uiv_Flags (void)
        = 0;
    virtual unsigned
      uiv_PopCount (void)
        = 0;
    virtual const char *
      uiv_PopUserName (unsigned index)
        = 0;
    virtual const char *
      uiv_PopInternalName (unsigned index)
        = 0;
    virtual const char *
      uiv_PopToolTip (unsigned index)
        = 0;
    virtual unsigned
      uiv_PopIconSize (int *w, int *h)
        = 0;
    virtual LxResult
      uiv_PopIconImage (int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopIconResource (int index, const char **iconResource)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopFlags (unsigned index, int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopCategory (const char **category)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ItemTest (ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierByIndex (int index, const char **name, const char **args)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListByIndex (int index, const char **command)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_CueText (char *buf, unsigned len)
        { return LXe_NOTIMPL; }
};
#define LXxD_UIValueHints3_Flags unsigned uiv_Flags (void)
#define LXxO_UIValueHints3_Flags LXxD_UIValueHints3_Flags LXx_OVERRIDE
#define LXxC_UIValueHints3_Flags(c) unsigned c::uiv_Flags (void)
#define LXxD_UIValueHints3_PopCount unsigned uiv_PopCount (void)
#define LXxO_UIValueHints3_PopCount LXxD_UIValueHints3_PopCount LXx_OVERRIDE
#define LXxC_UIValueHints3_PopCount(c) unsigned c::uiv_PopCount (void)
#define LXxD_UIValueHints3_PopUserName const char * uiv_PopUserName (unsigned index)
#define LXxO_UIValueHints3_PopUserName LXxD_UIValueHints3_PopUserName LXx_OVERRIDE
#define LXxC_UIValueHints3_PopUserName(c) const char * c::uiv_PopUserName (unsigned index)
#define LXxD_UIValueHints3_PopInternalName const char * uiv_PopInternalName (unsigned index)
#define LXxO_UIValueHints3_PopInternalName LXxD_UIValueHints3_PopInternalName LXx_OVERRIDE
#define LXxC_UIValueHints3_PopInternalName(c) const char * c::uiv_PopInternalName (unsigned index)
#define LXxD_UIValueHints3_PopToolTip const char * uiv_PopToolTip (unsigned index)
#define LXxO_UIValueHints3_PopToolTip LXxD_UIValueHints3_PopToolTip LXx_OVERRIDE
#define LXxC_UIValueHints3_PopToolTip(c) const char * c::uiv_PopToolTip (unsigned index)
#define LXxD_UIValueHints3_PopIconSize unsigned uiv_PopIconSize (int *w, int *h)
#define LXxO_UIValueHints3_PopIconSize LXxD_UIValueHints3_PopIconSize LXx_OVERRIDE
#define LXxC_UIValueHints3_PopIconSize(c) unsigned c::uiv_PopIconSize (int *w, int *h)
#define LXxD_UIValueHints3_PopIconImage LxResult uiv_PopIconImage (int index, void **ppvObj)
#define LXxO_UIValueHints3_PopIconImage LXxD_UIValueHints3_PopIconImage LXx_OVERRIDE
#define LXxC_UIValueHints3_PopIconImage(c) LxResult c::uiv_PopIconImage (int index, void **ppvObj)
#define LXxD_UIValueHints3_PopIconResource LxResult uiv_PopIconResource (int index, const char **iconResource)
#define LXxO_UIValueHints3_PopIconResource LXxD_UIValueHints3_PopIconResource LXx_OVERRIDE
#define LXxC_UIValueHints3_PopIconResource(c) LxResult c::uiv_PopIconResource (int index, const char **iconResource)
#define LXxD_UIValueHints3_PopFlags LxResult uiv_PopFlags (unsigned index, int *flags)
#define LXxO_UIValueHints3_PopFlags LXxD_UIValueHints3_PopFlags LXx_OVERRIDE
#define LXxC_UIValueHints3_PopFlags(c) LxResult c::uiv_PopFlags (unsigned index, int *flags)
#define LXxD_UIValueHints3_PopCategory LxResult uiv_PopCategory (const char **category)
#define LXxO_UIValueHints3_PopCategory LXxD_UIValueHints3_PopCategory LXx_OVERRIDE
#define LXxC_UIValueHints3_PopCategory(c) LxResult c::uiv_PopCategory (const char **category)
#define LXxD_UIValueHints3_ItemTest LxResult uiv_ItemTest (ILxUnknownID item)
#define LXxO_UIValueHints3_ItemTest LXxD_UIValueHints3_ItemTest LXx_OVERRIDE
#define LXxC_UIValueHints3_ItemTest(c) LxResult c::uiv_ItemTest (ILxUnknownID item)
#define LXxD_UIValueHints3_ColorPickerCommands LxResult uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
#define LXxO_UIValueHints3_ColorPickerCommands LXxD_UIValueHints3_ColorPickerCommands LXx_OVERRIDE
#define LXxC_UIValueHints3_ColorPickerCommands(c) LxResult c::uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
#define LXxD_UIValueHints3_NotifierCount LxResult uiv_NotifierCount (int *count)
#define LXxO_UIValueHints3_NotifierCount LXxD_UIValueHints3_NotifierCount LXx_OVERRIDE
#define LXxC_UIValueHints3_NotifierCount(c) LxResult c::uiv_NotifierCount (int *count)
#define LXxD_UIValueHints3_NotifierByIndex LxResult uiv_NotifierByIndex (int index, const char **name, const char **args)
#define LXxO_UIValueHints3_NotifierByIndex LXxD_UIValueHints3_NotifierByIndex LXx_OVERRIDE
#define LXxC_UIValueHints3_NotifierByIndex(c) LxResult c::uiv_NotifierByIndex (int index, const char **name, const char **args)
#define LXxD_UIValueHints3_FormCommandListCount LxResult uiv_FormCommandListCount (int *count)
#define LXxO_UIValueHints3_FormCommandListCount LXxD_UIValueHints3_FormCommandListCount LXx_OVERRIDE
#define LXxC_UIValueHints3_FormCommandListCount(c) LxResult c::uiv_FormCommandListCount (int *count)
#define LXxD_UIValueHints3_FormCommandListByIndex LxResult uiv_FormCommandListByIndex (int index, const char **command)
#define LXxO_UIValueHints3_FormCommandListByIndex LXxD_UIValueHints3_FormCommandListByIndex LXx_OVERRIDE
#define LXxC_UIValueHints3_FormCommandListByIndex(c) LxResult c::uiv_FormCommandListByIndex (int index, const char **command)
#define LXxD_UIValueHints3_CueText LxResult uiv_CueText (char *buf, unsigned len)
#define LXxO_UIValueHints3_CueText LXxD_UIValueHints3_CueText LXx_OVERRIDE
#define LXxC_UIValueHints3_CueText(c) LxResult c::uiv_CueText (char *buf, unsigned len)
template <class T>
class CLxIfc_UIValueHints3 : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    return loc->uiv_Flags ();
  }
    static unsigned
  PopCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    return loc->uiv_PopCount ();
  }
    static const char *
  PopUserName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    return loc->uiv_PopUserName (index);
  }
    static const char *
  PopInternalName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    return loc->uiv_PopInternalName (index);
  }
    static const char *
  PopToolTip (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    return loc->uiv_PopToolTip (index);
  }
    static unsigned
  PopIconSize (LXtObjectID wcom, int *w, int *h)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    return loc->uiv_PopIconSize (w,h);
  }
    static LxResult
  PopIconImage (LXtObjectID wcom, int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_PopIconImage (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopIconResource (LXtObjectID wcom, int index, const char **iconResource)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_PopIconResource (index,iconResource);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopFlags (LXtObjectID wcom, unsigned index, int *flags)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_PopFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopCategory (LXtObjectID wcom, const char **category)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_PopCategory (category);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemTest (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_ItemTest ((ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColorPickerCommands (LXtObjectID wcom, char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_ColorPickerCommands (rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_NotifierCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierByIndex (LXtObjectID wcom, int index, const char **name, const char **args)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_NotifierByIndex (index,name,args);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_FormCommandListCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListByIndex (LXtObjectID wcom, int index, const char **command)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_FormCommandListByIndex (index,command);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CueText (LXtObjectID wcom, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_UIValueHints3, loc);
    try {
      return loc->uiv_CueText (buf,len);
    } catch (LxResult rc) { return rc; }
  }
  ILxUIValueHints3 vt;
public:
  CLxIfc_UIValueHints3 ()
  {
    vt.Flags = Flags;
    vt.PopCount = PopCount;
    vt.PopUserName = PopUserName;
    vt.PopInternalName = PopInternalName;
    vt.PopToolTip = PopToolTip;
    vt.PopIconSize = PopIconSize;
    vt.PopIconImage = PopIconImage;
    vt.PopIconResource = PopIconResource;
    vt.PopFlags = PopFlags;
    vt.PopCategory = PopCategory;
    vt.ItemTest = ItemTest;
    vt.ColorPickerCommands = ColorPickerCommands;
    vt.NotifierCount = NotifierCount;
    vt.NotifierByIndex = NotifierByIndex;
    vt.FormCommandListCount = FormCommandListCount;
    vt.FormCommandListByIndex = FormCommandListByIndex;
    vt.CueText = CueText;
    vTable = &vt.iunk;
    iid = &lx::guid_UIValueHints3;
  }
};
class CLxLoc_UIValueHints3 : public CLxLocalize<ILxUIValueHints3ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UIValueHints3() {_init();}
  CLxLoc_UIValueHints3(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UIValueHints3(const CLxLoc_UIValueHints3 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UIValueHints3;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    unsigned
  PopCount (void)
  {
    return m_loc[0]->PopCount (m_loc);
  }
    const char *
  PopUserName (unsigned index)
  {
    return m_loc[0]->PopUserName (m_loc,index);
  }
    const char *
  PopInternalName (unsigned index)
  {
    return m_loc[0]->PopInternalName (m_loc,index);
  }
    const char *
  PopToolTip (unsigned index)
  {
    return m_loc[0]->PopToolTip (m_loc,index);
  }
    unsigned
  PopIconSize (int *w, int *h)
  {
    return m_loc[0]->PopIconSize (m_loc,w,h);
  }
    LxResult
  PopIconImage (int index, void **ppvObj)
  {
    return m_loc[0]->PopIconImage (m_loc,index,ppvObj);
  }
    CLxResult
  PopIconImage (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->PopIconImage(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  PopIconResource (int index, const char **iconResource)
  {
    return m_loc[0]->PopIconResource (m_loc,index,iconResource);
  }
    LxResult
  PopFlags (unsigned index, int *flags)
  {
    return m_loc[0]->PopFlags (m_loc,index,flags);
  }
    LxResult
  PopCategory (const char **category)
  {
    return m_loc[0]->PopCategory (m_loc,category);
  }
    LxResult
  ItemTest (ILxUnknownID item)
  {
    return m_loc[0]->ItemTest (m_loc,(ILxUnknownID)item);
  }
    LxResult
  ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    return m_loc[0]->ColorPickerCommands (m_loc,rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
  }
    LxResult
  NotifierCount (int *count)
  {
    return m_loc[0]->NotifierCount (m_loc,count);
  }
    LxResult
  NotifierByIndex (int index, const char **name, const char **args)
  {
    return m_loc[0]->NotifierByIndex (m_loc,index,name,args);
  }
    LxResult
  FormCommandListCount (int *count)
  {
    return m_loc[0]->FormCommandListCount (m_loc,count);
  }
    LxResult
  FormCommandListByIndex (int index, const char **command)
  {
    return m_loc[0]->FormCommandListByIndex (m_loc,index,command);
  }
    LxResult
  CueText (char *buf, unsigned len)
  {
    return m_loc[0]->CueText (m_loc,buf,len);
  }
    LxResult
  CueText (std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->CueText (m_loc,buf,len);
    LXWx_SBUF2
  }
};

class CLxImpl_Command {
  public:
    virtual ~CLxImpl_Command() {}
    virtual LxResult
      cmd_Tag (LXtCommandTag *tag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_UserName (const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ButtonName (const char **buttonName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Desc (const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Tooltip (const char **tooltip)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Help (const char **help)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Example (const char **example)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Icon (const char **iconNames)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Flags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_PostExecFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_PostExecBehaviorFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_PostExecHints (unsigned int *hints)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_SandboxGUID (const LXtGUID **guid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Message (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ContainedEnable (LXtID4 *types)
        { return LXe_NOTIMPL; }
    virtual void
      cmd_Interact (void)
        { }
    virtual void
      cmd_PreExecute (void)
        { }
    virtual void
      cmd_Execute (unsigned int flags)
        { }
    virtual LxResult
      cmd_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgFlags (unsigned int index, unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgClear (unsigned int index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgResetAll (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgSetDatatypes (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgUserName (unsigned int index, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgDesc (unsigned int index, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgExample (unsigned int index, const char **example)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgType (unsigned int index, const char **type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgTypeUserName (unsigned int index, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgTypeDesc (unsigned int index, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_DialogInit (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_DialogArgChange (unsigned int arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgEnable (unsigned int arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgParseString (unsigned int argIndex, const char *argString)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Copy (ILxUnknownID sourceCommand)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Query (unsigned int index, ILxUnknownID vaQuery)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_NotifyAddClient (int argument, ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_NotifyRemoveClient (ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_DialogFormatting (const char **formatting)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_IconImage (int w, int h, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgOptionIconName (unsigned int index, unsigned int optIndex, const char **iconName)
        { return LXe_NOTIMPL; }
};
#define LXxD_Command_Tag LxResult cmd_Tag (LXtCommandTag *tag)
#define LXxO_Command_Tag LXxD_Command_Tag LXx_OVERRIDE
#define LXxC_Command_Tag(c) LxResult c::cmd_Tag (LXtCommandTag *tag)
#define LXxD_Command_Name LxResult cmd_Name (const char **name)
#define LXxO_Command_Name LXxD_Command_Name LXx_OVERRIDE
#define LXxC_Command_Name(c) LxResult c::cmd_Name (const char **name)
#define LXxD_Command_UserName LxResult cmd_UserName (const char **userName)
#define LXxO_Command_UserName LXxD_Command_UserName LXx_OVERRIDE
#define LXxC_Command_UserName(c) LxResult c::cmd_UserName (const char **userName)
#define LXxD_Command_ButtonName LxResult cmd_ButtonName (const char **buttonName)
#define LXxO_Command_ButtonName LXxD_Command_ButtonName LXx_OVERRIDE
#define LXxC_Command_ButtonName(c) LxResult c::cmd_ButtonName (const char **buttonName)
#define LXxD_Command_Desc LxResult cmd_Desc (const char **desc)
#define LXxO_Command_Desc LXxD_Command_Desc LXx_OVERRIDE
#define LXxC_Command_Desc(c) LxResult c::cmd_Desc (const char **desc)
#define LXxD_Command_Tooltip LxResult cmd_Tooltip (const char **tooltip)
#define LXxO_Command_Tooltip LXxD_Command_Tooltip LXx_OVERRIDE
#define LXxC_Command_Tooltip(c) LxResult c::cmd_Tooltip (const char **tooltip)
#define LXxD_Command_Help LxResult cmd_Help (const char **help)
#define LXxO_Command_Help LXxD_Command_Help LXx_OVERRIDE
#define LXxC_Command_Help(c) LxResult c::cmd_Help (const char **help)
#define LXxD_Command_Example LxResult cmd_Example (const char **example)
#define LXxO_Command_Example LXxD_Command_Example LXx_OVERRIDE
#define LXxC_Command_Example(c) LxResult c::cmd_Example (const char **example)
#define LXxD_Command_Icon LxResult cmd_Icon (const char **iconNames)
#define LXxO_Command_Icon LXxD_Command_Icon LXx_OVERRIDE
#define LXxC_Command_Icon(c) LxResult c::cmd_Icon (const char **iconNames)
#define LXxD_Command_Flags LxResult cmd_Flags (unsigned int *flags)
#define LXxO_Command_Flags LXxD_Command_Flags LXx_OVERRIDE
#define LXxC_Command_Flags(c) LxResult c::cmd_Flags (unsigned int *flags)
#define LXxD_Command_PostExecFlags LxResult cmd_PostExecFlags (unsigned int *flags)
#define LXxO_Command_PostExecFlags LXxD_Command_PostExecFlags LXx_OVERRIDE
#define LXxC_Command_PostExecFlags(c) LxResult c::cmd_PostExecFlags (unsigned int *flags)
#define LXxD_Command_PostExecBehaviorFlags LxResult cmd_PostExecBehaviorFlags (unsigned int *flags)
#define LXxO_Command_PostExecBehaviorFlags LXxD_Command_PostExecBehaviorFlags LXx_OVERRIDE
#define LXxC_Command_PostExecBehaviorFlags(c) LxResult c::cmd_PostExecBehaviorFlags (unsigned int *flags)
#define LXxD_Command_PostExecHints LxResult cmd_PostExecHints (unsigned int *hints)
#define LXxO_Command_PostExecHints LXxD_Command_PostExecHints LXx_OVERRIDE
#define LXxC_Command_PostExecHints(c) LxResult c::cmd_PostExecHints (unsigned int *hints)
#define LXxD_Command_SandboxGUID LxResult cmd_SandboxGUID (const LXtGUID **guid)
#define LXxO_Command_SandboxGUID LXxD_Command_SandboxGUID LXx_OVERRIDE
#define LXxC_Command_SandboxGUID(c) LxResult c::cmd_SandboxGUID (const LXtGUID **guid)
#define LXxD_Command_Message LxResult cmd_Message (void **ppvObj)
#define LXxO_Command_Message LXxD_Command_Message LXx_OVERRIDE
#define LXxC_Command_Message(c) LxResult c::cmd_Message (void **ppvObj)
#define LXxD_Command_Enable LxResult cmd_Enable (ILxUnknownID msg)
#define LXxO_Command_Enable LXxD_Command_Enable LXx_OVERRIDE
#define LXxC_Command_Enable(c) LxResult c::cmd_Enable (ILxUnknownID msg)
#define LXxD_Command_ContainedEnable LxResult cmd_ContainedEnable (LXtID4 *types)
#define LXxO_Command_ContainedEnable LXxD_Command_ContainedEnable LXx_OVERRIDE
#define LXxC_Command_ContainedEnable(c) LxResult c::cmd_ContainedEnable (LXtID4 *types)
#define LXxD_Command_Interact void cmd_Interact (void)
#define LXxO_Command_Interact LXxD_Command_Interact LXx_OVERRIDE
#define LXxC_Command_Interact(c) void c::cmd_Interact (void)
#define LXxD_Command_PreExecute void cmd_PreExecute (void)
#define LXxO_Command_PreExecute LXxD_Command_PreExecute LXx_OVERRIDE
#define LXxC_Command_PreExecute(c) void c::cmd_PreExecute (void)
#define LXxD_Command_Execute void cmd_Execute (unsigned int flags)
#define LXxO_Command_Execute LXxD_Command_Execute LXx_OVERRIDE
#define LXxC_Command_Execute(c) void c::cmd_Execute (unsigned int flags)
#define LXxD_Command_ToggleArg LxResult cmd_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
#define LXxO_Command_ToggleArg LXxD_Command_ToggleArg LXx_OVERRIDE
#define LXxC_Command_ToggleArg(c) LxResult c::cmd_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
#define LXxD_Command_ArgFlags LxResult cmd_ArgFlags (unsigned int index, unsigned int *flags)
#define LXxO_Command_ArgFlags LXxD_Command_ArgFlags LXx_OVERRIDE
#define LXxC_Command_ArgFlags(c) LxResult c::cmd_ArgFlags (unsigned int index, unsigned int *flags)
#define LXxD_Command_ArgClear LxResult cmd_ArgClear (unsigned int index)
#define LXxO_Command_ArgClear LXxD_Command_ArgClear LXx_OVERRIDE
#define LXxC_Command_ArgClear(c) LxResult c::cmd_ArgClear (unsigned int index)
#define LXxD_Command_ArgResetAll LxResult cmd_ArgResetAll (void)
#define LXxO_Command_ArgResetAll LXxD_Command_ArgResetAll LXx_OVERRIDE
#define LXxC_Command_ArgResetAll(c) LxResult c::cmd_ArgResetAll (void)
#define LXxD_Command_ArgSetDatatypes LxResult cmd_ArgSetDatatypes (void)
#define LXxO_Command_ArgSetDatatypes LXxD_Command_ArgSetDatatypes LXx_OVERRIDE
#define LXxC_Command_ArgSetDatatypes(c) LxResult c::cmd_ArgSetDatatypes (void)
#define LXxD_Command_ArgUserName LxResult cmd_ArgUserName (unsigned int index, const char **userName)
#define LXxO_Command_ArgUserName LXxD_Command_ArgUserName LXx_OVERRIDE
#define LXxC_Command_ArgUserName(c) LxResult c::cmd_ArgUserName (unsigned int index, const char **userName)
#define LXxD_Command_ArgDesc LxResult cmd_ArgDesc (unsigned int index, const char **desc)
#define LXxO_Command_ArgDesc LXxD_Command_ArgDesc LXx_OVERRIDE
#define LXxC_Command_ArgDesc(c) LxResult c::cmd_ArgDesc (unsigned int index, const char **desc)
#define LXxD_Command_ArgExample LxResult cmd_ArgExample (unsigned int index, const char **example)
#define LXxO_Command_ArgExample LXxD_Command_ArgExample LXx_OVERRIDE
#define LXxC_Command_ArgExample(c) LxResult c::cmd_ArgExample (unsigned int index, const char **example)
#define LXxD_Command_ArgType LxResult cmd_ArgType (unsigned int index, const char **type)
#define LXxO_Command_ArgType LXxD_Command_ArgType LXx_OVERRIDE
#define LXxC_Command_ArgType(c) LxResult c::cmd_ArgType (unsigned int index, const char **type)
#define LXxD_Command_ArgTypeUserName LxResult cmd_ArgTypeUserName (unsigned int index, const char **userName)
#define LXxO_Command_ArgTypeUserName LXxD_Command_ArgTypeUserName LXx_OVERRIDE
#define LXxC_Command_ArgTypeUserName(c) LxResult c::cmd_ArgTypeUserName (unsigned int index, const char **userName)
#define LXxD_Command_ArgTypeDesc LxResult cmd_ArgTypeDesc (unsigned int index, const char **desc)
#define LXxO_Command_ArgTypeDesc LXxD_Command_ArgTypeDesc LXx_OVERRIDE
#define LXxC_Command_ArgTypeDesc(c) LxResult c::cmd_ArgTypeDesc (unsigned int index, const char **desc)
#define LXxD_Command_ArgOptionUserName LxResult cmd_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
#define LXxO_Command_ArgOptionUserName LXxD_Command_ArgOptionUserName LXx_OVERRIDE
#define LXxC_Command_ArgOptionUserName(c) LxResult c::cmd_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
#define LXxD_Command_ArgOptionDesc LxResult cmd_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
#define LXxO_Command_ArgOptionDesc LXxD_Command_ArgOptionDesc LXx_OVERRIDE
#define LXxC_Command_ArgOptionDesc(c) LxResult c::cmd_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
#define LXxD_Command_DialogInit LxResult cmd_DialogInit (void)
#define LXxO_Command_DialogInit LXxD_Command_DialogInit LXx_OVERRIDE
#define LXxC_Command_DialogInit(c) LxResult c::cmd_DialogInit (void)
#define LXxD_Command_DialogArgChange LxResult cmd_DialogArgChange (unsigned int arg)
#define LXxO_Command_DialogArgChange LXxD_Command_DialogArgChange LXx_OVERRIDE
#define LXxC_Command_DialogArgChange(c) LxResult c::cmd_DialogArgChange (unsigned int arg)
#define LXxD_Command_ArgEnable LxResult cmd_ArgEnable (unsigned int arg)
#define LXxO_Command_ArgEnable LXxD_Command_ArgEnable LXx_OVERRIDE
#define LXxC_Command_ArgEnable(c) LxResult c::cmd_ArgEnable (unsigned int arg)
#define LXxD_Command_ArgParseString LxResult cmd_ArgParseString (unsigned int argIndex, const char *argString)
#define LXxO_Command_ArgParseString LXxD_Command_ArgParseString LXx_OVERRIDE
#define LXxC_Command_ArgParseString(c) LxResult c::cmd_ArgParseString (unsigned int argIndex, const char *argString)
#define LXxD_Command_Copy LxResult cmd_Copy (ILxUnknownID sourceCommand)
#define LXxO_Command_Copy LXxD_Command_Copy LXx_OVERRIDE
#define LXxC_Command_Copy(c) LxResult c::cmd_Copy (ILxUnknownID sourceCommand)
#define LXxD_Command_Query LxResult cmd_Query (unsigned int index, ILxUnknownID vaQuery)
#define LXxO_Command_Query LXxD_Command_Query LXx_OVERRIDE
#define LXxC_Command_Query(c) LxResult c::cmd_Query (unsigned int index, ILxUnknownID vaQuery)
#define LXxD_Command_NotifyAddClient LxResult cmd_NotifyAddClient (int argument, ILxUnknownID object)
#define LXxO_Command_NotifyAddClient LXxD_Command_NotifyAddClient LXx_OVERRIDE
#define LXxC_Command_NotifyAddClient(c) LxResult c::cmd_NotifyAddClient (int argument, ILxUnknownID object)
#define LXxD_Command_NotifyRemoveClient LxResult cmd_NotifyRemoveClient (ILxUnknownID object)
#define LXxO_Command_NotifyRemoveClient LXxD_Command_NotifyRemoveClient LXx_OVERRIDE
#define LXxC_Command_NotifyRemoveClient(c) LxResult c::cmd_NotifyRemoveClient (ILxUnknownID object)
#define LXxD_Command_DialogFormatting LxResult cmd_DialogFormatting (const char **formatting)
#define LXxO_Command_DialogFormatting LXxD_Command_DialogFormatting LXx_OVERRIDE
#define LXxC_Command_DialogFormatting(c) LxResult c::cmd_DialogFormatting (const char **formatting)
#define LXxD_Command_IconImage LxResult cmd_IconImage (int w, int h, void **ppvObj)
#define LXxO_Command_IconImage LXxD_Command_IconImage LXx_OVERRIDE
#define LXxC_Command_IconImage(c) LxResult c::cmd_IconImage (int w, int h, void **ppvObj)
#define LXxD_Command_ArgOptionIconName LxResult cmd_ArgOptionIconName (unsigned int index, unsigned int optIndex, const char **iconName)
#define LXxO_Command_ArgOptionIconName LXxD_Command_ArgOptionIconName LXx_OVERRIDE
#define LXxC_Command_ArgOptionIconName(c) LxResult c::cmd_ArgOptionIconName (unsigned int index, unsigned int optIndex, const char **iconName)
template <class T>
class CLxIfc_Command : public CLxInterface
{
    static LxResult
  Tag (LXtObjectID wcom, LXtCommandTag *tag)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Tag (tag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UserName (LXtObjectID wcom, const char **userName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_UserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ButtonName (LXtObjectID wcom, const char **buttonName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ButtonName (buttonName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Desc (LXtObjectID wcom, const char **desc)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Desc (desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Tooltip (LXtObjectID wcom, const char **tooltip)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Tooltip (tooltip);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Help (LXtObjectID wcom, const char **help)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Help (help);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Example (LXtObjectID wcom, const char **example)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Example (example);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Icon (LXtObjectID wcom, const char **iconNames)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Icon (iconNames);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Flags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Flags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_PostExecFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecBehaviorFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_PostExecBehaviorFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecHints (LXtObjectID wcom, unsigned int *hints)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_PostExecHints (hints);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SandboxGUID (LXtObjectID wcom, const LXtGUID **guid)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_SandboxGUID (guid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Message (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Message (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ContainedEnable (LXtObjectID wcom, LXtID4 *types)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ContainedEnable (types);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Interact (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command, loc);
    loc->cmd_Interact ();
  }
    static void
  PreExecute (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command, loc);
    loc->cmd_PreExecute ();
  }
    static void
  Execute (LXtObjectID wcom, unsigned int flags)
  {
    LXCWxINST (CLxImpl_Command, loc);
    loc->cmd_Execute (flags);
  }
    static LxResult
  ToggleArg (LXtObjectID wcom, unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ToggleArg (index,ppvObj,typeID,typeName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgFlags (LXtObjectID wcom, unsigned int index, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgClear (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgClear (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgResetAll (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgResetAll ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgSetDatatypes (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgSetDatatypes ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgUserName (LXtObjectID wcom, unsigned int index, const char **userName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgUserName (index,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgDesc (LXtObjectID wcom, unsigned int index, const char **desc)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgDesc (index,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgExample (LXtObjectID wcom, unsigned int index, const char **example)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgExample (index,example);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgType (LXtObjectID wcom, unsigned int index, const char **type)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgType (index,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgTypeUserName (LXtObjectID wcom, unsigned int index, const char **userName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgTypeUserName (index,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgTypeDesc (LXtObjectID wcom, unsigned int index, const char **desc)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgTypeDesc (index,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionUserName (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **userName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgOptionUserName (index,optIndex,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionDesc (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **desc)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgOptionDesc (index,optIndex,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogInit (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_DialogInit ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogArgChange (LXtObjectID wcom, unsigned int arg)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_DialogArgChange (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgEnable (LXtObjectID wcom, unsigned int arg)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgEnable (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgParseString (LXtObjectID wcom, unsigned int argIndex, const char *argString)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgParseString (argIndex,argString);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Copy (LXtObjectID wcom, LXtObjectID sourceCommand)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Copy ((ILxUnknownID)sourceCommand);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Query (LXtObjectID wcom, unsigned int index, LXtObjectID vaQuery)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Query (index,(ILxUnknownID)vaQuery);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifyAddClient (LXtObjectID wcom, int argument, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_NotifyAddClient (argument,(ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifyRemoveClient (LXtObjectID wcom, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_NotifyRemoveClient ((ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogFormatting (LXtObjectID wcom, const char **formatting)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_DialogFormatting (formatting);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IconImage (LXtObjectID wcom, int w, int h, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_IconImage (w,h,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionIconName (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **iconName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgOptionIconName (index,optIndex,iconName);
    } catch (LxResult rc) { return rc; }
  }
  ILxCommand vt;
public:
  CLxIfc_Command ()
  {
    vt.Tag = Tag;
    vt.Name = Name;
    vt.UserName = UserName;
    vt.ButtonName = ButtonName;
    vt.Desc = Desc;
    vt.Tooltip = Tooltip;
    vt.Help = Help;
    vt.Example = Example;
    vt.Icon = Icon;
    vt.Flags = Flags;
    vt.PostExecFlags = PostExecFlags;
    vt.PostExecBehaviorFlags = PostExecBehaviorFlags;
    vt.PostExecHints = PostExecHints;
    vt.SandboxGUID = SandboxGUID;
    vt.Message = Message;
    vt.Enable = Enable;
    vt.ContainedEnable = ContainedEnable;
    vt.Interact = Interact;
    vt.PreExecute = PreExecute;
    vt.Execute = Execute;
    vt.ToggleArg = ToggleArg;
    vt.ArgFlags = ArgFlags;
    vt.ArgClear = ArgClear;
    vt.ArgResetAll = ArgResetAll;
    vt.ArgSetDatatypes = ArgSetDatatypes;
    vt.ArgUserName = ArgUserName;
    vt.ArgDesc = ArgDesc;
    vt.ArgExample = ArgExample;
    vt.ArgType = ArgType;
    vt.ArgTypeUserName = ArgTypeUserName;
    vt.ArgTypeDesc = ArgTypeDesc;
    vt.ArgOptionUserName = ArgOptionUserName;
    vt.ArgOptionDesc = ArgOptionDesc;
    vt.DialogInit = DialogInit;
    vt.DialogArgChange = DialogArgChange;
    vt.ArgEnable = ArgEnable;
    vt.ArgParseString = ArgParseString;
    vt.Copy = Copy;
    vt.Query = Query;
    vt.NotifyAddClient = NotifyAddClient;
    vt.NotifyRemoveClient = NotifyRemoveClient;
    vt.DialogFormatting = DialogFormatting;
    vt.IconImage = IconImage;
    vt.ArgOptionIconName = ArgOptionIconName;
    vTable = &vt.iunk;
    iid = &lx::guid_Command;
  }
};
class CLxLoc_Command : public CLxLocalize<ILxCommandID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Command() {_init();}
  CLxLoc_Command(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Command(const CLxLoc_Command &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Command;}
    LxResult
  Tag (LXtCommandTag *tag)
  {
    return m_loc[0]->Tag (m_loc,tag);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  UserName (const char **userName)
  {
    return m_loc[0]->UserName (m_loc,userName);
  }
    LxResult
  ButtonName (const char **buttonName)
  {
    return m_loc[0]->ButtonName (m_loc,buttonName);
  }
    LxResult
  Desc (const char **desc)
  {
    return m_loc[0]->Desc (m_loc,desc);
  }
    LxResult
  Tooltip (const char **tooltip)
  {
    return m_loc[0]->Tooltip (m_loc,tooltip);
  }
    LxResult
  Help (const char **help)
  {
    return m_loc[0]->Help (m_loc,help);
  }
    LxResult
  Example (const char **example)
  {
    return m_loc[0]->Example (m_loc,example);
  }
    LxResult
  Icon (const char **iconNames)
  {
    return m_loc[0]->Icon (m_loc,iconNames);
  }
    LxResult
  Flags (unsigned int *flags)
  {
    return m_loc[0]->Flags (m_loc,flags);
  }
    LxResult
  PostExecFlags (unsigned int *flags)
  {
    return m_loc[0]->PostExecFlags (m_loc,flags);
  }
    LxResult
  PostExecBehaviorFlags (unsigned int *flags)
  {
    return m_loc[0]->PostExecBehaviorFlags (m_loc,flags);
  }
    LxResult
  PostExecHints (unsigned int *hints)
  {
    return m_loc[0]->PostExecHints (m_loc,hints);
  }
    LxResult
  SandboxGUID (const LXtGUID **guid)
  {
    return m_loc[0]->SandboxGUID (m_loc,guid);
  }
    LxResult
  Message (void **ppvObj)
  {
    return m_loc[0]->Message (m_loc,ppvObj);
  }
    CLxResult
  Message (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Message(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  ContainedEnable (LXtID4 *types)
  {
    return m_loc[0]->ContainedEnable (m_loc,types);
  }
    void
  Interact (void)
  {
    m_loc[0]->Interact (m_loc);
  }
    void
  PreExecute (void)
  {
    m_loc[0]->PreExecute (m_loc);
  }
    void
  Execute (unsigned int flags)
  {
    m_loc[0]->Execute (m_loc,flags);
  }
    LxResult
  ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
  {
    return m_loc[0]->ToggleArg (m_loc,index,ppvObj,typeID,typeName);
  }
    CLxResult
  ToggleArg (unsigned int *index, CLxLocalizedObject &o_dest, unsigned int *typeID, const char **typeName)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ToggleArg(m_loc,index,&o_obj,typeID,typeName);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ArgFlags (unsigned int index, unsigned int *flags)
  {
    return m_loc[0]->ArgFlags (m_loc,index,flags);
  }
    LxResult
  ArgClear (unsigned int index)
  {
    return m_loc[0]->ArgClear (m_loc,index);
  }
    LxResult
  ArgResetAll (void)
  {
    return m_loc[0]->ArgResetAll (m_loc);
  }
    LxResult
  ArgSetDatatypes (void)
  {
    return m_loc[0]->ArgSetDatatypes (m_loc);
  }
    LxResult
  ArgUserName (unsigned int index, const char **userName)
  {
    return m_loc[0]->ArgUserName (m_loc,index,userName);
  }
    LxResult
  ArgDesc (unsigned int index, const char **desc)
  {
    return m_loc[0]->ArgDesc (m_loc,index,desc);
  }
    LxResult
  ArgExample (unsigned int index, const char **example)
  {
    return m_loc[0]->ArgExample (m_loc,index,example);
  }
    LxResult
  ArgType (unsigned int index, const char **type)
  {
    return m_loc[0]->ArgType (m_loc,index,type);
  }
    LxResult
  ArgTypeUserName (unsigned int index, const char **userName)
  {
    return m_loc[0]->ArgTypeUserName (m_loc,index,userName);
  }
    LxResult
  ArgTypeDesc (unsigned int index, const char **desc)
  {
    return m_loc[0]->ArgTypeDesc (m_loc,index,desc);
  }
    LxResult
  ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
  {
    return m_loc[0]->ArgOptionUserName (m_loc,index,optIndex,userName);
  }
    LxResult
  ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
  {
    return m_loc[0]->ArgOptionDesc (m_loc,index,optIndex,desc);
  }
    LxResult
  DialogInit (void)
  {
    return m_loc[0]->DialogInit (m_loc);
  }
    LxResult
  DialogArgChange (unsigned int arg)
  {
    return m_loc[0]->DialogArgChange (m_loc,arg);
  }
    LxResult
  ArgEnable (unsigned int arg)
  {
    return m_loc[0]->ArgEnable (m_loc,arg);
  }
    LxResult
  ArgParseString (unsigned int argIndex, const char *argString)
  {
    return m_loc[0]->ArgParseString (m_loc,argIndex,argString);
  }
    LxResult
  Copy (ILxUnknownID sourceCommand)
  {
    return m_loc[0]->Copy (m_loc,(ILxUnknownID)sourceCommand);
  }
    LxResult
  Query (unsigned int index, ILxUnknownID vaQuery)
  {
    return m_loc[0]->Query (m_loc,index,(ILxUnknownID)vaQuery);
  }
    LxResult
  NotifyAddClient (int argument, ILxUnknownID object)
  {
    return m_loc[0]->NotifyAddClient (m_loc,argument,(ILxUnknownID)object);
  }
    LxResult
  NotifyRemoveClient (ILxUnknownID object)
  {
    return m_loc[0]->NotifyRemoveClient (m_loc,(ILxUnknownID)object);
  }
    LxResult
  DialogFormatting (const char **formatting)
  {
    return m_loc[0]->DialogFormatting (m_loc,formatting);
  }
    LxResult
  IconImage (int w, int h, void **ppvObj)
  {
    return m_loc[0]->IconImage (m_loc,w,h,ppvObj);
  }
    CLxResult
  IconImage (int w, int h, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->IconImage(m_loc,w,h,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ArgOptionIconName (unsigned int index, unsigned int optIndex, const char **iconName)
  {
    return m_loc[0]->ArgOptionIconName (m_loc,index,optIndex,iconName);
  }
};

class CLxImpl_CommandEvent {
  public:
    virtual ~CLxImpl_CommandEvent() {}
    virtual LxResult
      cevt_Event (unsigned int flags)
        { return LXe_NOTIMPL; }
};
#define LXxD_CommandEvent_Event LxResult cevt_Event (unsigned int flags)
#define LXxO_CommandEvent_Event LXxD_CommandEvent_Event LXx_OVERRIDE
#define LXxC_CommandEvent_Event(c) LxResult c::cevt_Event (unsigned int flags)
template <class T>
class CLxIfc_CommandEvent : public CLxInterface
{
    static LxResult
  Event (LXtObjectID wcom, unsigned int flags)
  {
    LXCWxINST (CLxImpl_CommandEvent, loc);
    try {
      return loc->cevt_Event (flags);
    } catch (LxResult rc) { return rc; }
  }
  ILxCommandEvent vt;
public:
  CLxIfc_CommandEvent ()
  {
    vt.Event = Event;
    vTable = &vt.iunk;
    iid = &lx::guid_CommandEvent;
  }
};
class CLxLoc_CommandEvent : public CLxLocalize<ILxCommandEventID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CommandEvent() {_init();}
  CLxLoc_CommandEvent(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CommandEvent(const CLxLoc_CommandEvent &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CommandEvent;}
    LxResult
  Event (unsigned int flags)
  {
    return m_loc[0]->Event (m_loc,flags);
  }
};

class CLxImpl_UIValueHints2 {
  public:
    virtual ~CLxImpl_UIValueHints2() {}
    virtual unsigned
      uiv_Flags (void)
        = 0;
    virtual unsigned
      uiv_PopCount (void)
        = 0;
    virtual const char *
      uiv_PopUserName (unsigned index)
        = 0;
    virtual const char *
      uiv_PopInternalName (unsigned index)
        = 0;
    virtual unsigned
      uiv_PopIconSize (int *w, int *h)
        = 0;
    virtual LxResult
      uiv_PopIconImage (int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopIconResource (int index, const char **iconResource)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopFlags (unsigned index, int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopCategory (const char **category)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ItemTest (ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierByIndex (int index, const char **name, const char **args)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListByIndex (int index, const char **command)
        { return LXe_NOTIMPL; }
};
#define LXxD_UIValueHints2_Flags unsigned uiv_Flags (void)
#define LXxO_UIValueHints2_Flags LXxD_UIValueHints2_Flags LXx_OVERRIDE
#define LXxC_UIValueHints2_Flags(c) unsigned c::uiv_Flags (void)
#define LXxD_UIValueHints2_PopCount unsigned uiv_PopCount (void)
#define LXxO_UIValueHints2_PopCount LXxD_UIValueHints2_PopCount LXx_OVERRIDE
#define LXxC_UIValueHints2_PopCount(c) unsigned c::uiv_PopCount (void)
#define LXxD_UIValueHints2_PopUserName const char * uiv_PopUserName (unsigned index)
#define LXxO_UIValueHints2_PopUserName LXxD_UIValueHints2_PopUserName LXx_OVERRIDE
#define LXxC_UIValueHints2_PopUserName(c) const char * c::uiv_PopUserName (unsigned index)
#define LXxD_UIValueHints2_PopInternalName const char * uiv_PopInternalName (unsigned index)
#define LXxO_UIValueHints2_PopInternalName LXxD_UIValueHints2_PopInternalName LXx_OVERRIDE
#define LXxC_UIValueHints2_PopInternalName(c) const char * c::uiv_PopInternalName (unsigned index)
#define LXxD_UIValueHints2_PopIconSize unsigned uiv_PopIconSize (int *w, int *h)
#define LXxO_UIValueHints2_PopIconSize LXxD_UIValueHints2_PopIconSize LXx_OVERRIDE
#define LXxC_UIValueHints2_PopIconSize(c) unsigned c::uiv_PopIconSize (int *w, int *h)
#define LXxD_UIValueHints2_PopIconImage LxResult uiv_PopIconImage (int index, void **ppvObj)
#define LXxO_UIValueHints2_PopIconImage LXxD_UIValueHints2_PopIconImage LXx_OVERRIDE
#define LXxC_UIValueHints2_PopIconImage(c) LxResult c::uiv_PopIconImage (int index, void **ppvObj)
#define LXxD_UIValueHints2_PopIconResource LxResult uiv_PopIconResource (int index, const char **iconResource)
#define LXxO_UIValueHints2_PopIconResource LXxD_UIValueHints2_PopIconResource LXx_OVERRIDE
#define LXxC_UIValueHints2_PopIconResource(c) LxResult c::uiv_PopIconResource (int index, const char **iconResource)
#define LXxD_UIValueHints2_PopFlags LxResult uiv_PopFlags (unsigned index, int *flags)
#define LXxO_UIValueHints2_PopFlags LXxD_UIValueHints2_PopFlags LXx_OVERRIDE
#define LXxC_UIValueHints2_PopFlags(c) LxResult c::uiv_PopFlags (unsigned index, int *flags)
#define LXxD_UIValueHints2_PopCategory LxResult uiv_PopCategory (const char **category)
#define LXxO_UIValueHints2_PopCategory LXxD_UIValueHints2_PopCategory LXx_OVERRIDE
#define LXxC_UIValueHints2_PopCategory(c) LxResult c::uiv_PopCategory (const char **category)
#define LXxD_UIValueHints2_ItemTest LxResult uiv_ItemTest (ILxUnknownID item)
#define LXxO_UIValueHints2_ItemTest LXxD_UIValueHints2_ItemTest LXx_OVERRIDE
#define LXxC_UIValueHints2_ItemTest(c) LxResult c::uiv_ItemTest (ILxUnknownID item)
#define LXxD_UIValueHints2_ColorPickerCommands LxResult uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
#define LXxO_UIValueHints2_ColorPickerCommands LXxD_UIValueHints2_ColorPickerCommands LXx_OVERRIDE
#define LXxC_UIValueHints2_ColorPickerCommands(c) LxResult c::uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
#define LXxD_UIValueHints2_NotifierCount LxResult uiv_NotifierCount (int *count)
#define LXxO_UIValueHints2_NotifierCount LXxD_UIValueHints2_NotifierCount LXx_OVERRIDE
#define LXxC_UIValueHints2_NotifierCount(c) LxResult c::uiv_NotifierCount (int *count)
#define LXxD_UIValueHints2_NotifierByIndex LxResult uiv_NotifierByIndex (int index, const char **name, const char **args)
#define LXxO_UIValueHints2_NotifierByIndex LXxD_UIValueHints2_NotifierByIndex LXx_OVERRIDE
#define LXxC_UIValueHints2_NotifierByIndex(c) LxResult c::uiv_NotifierByIndex (int index, const char **name, const char **args)
#define LXxD_UIValueHints2_FormCommandListCount LxResult uiv_FormCommandListCount (int *count)
#define LXxO_UIValueHints2_FormCommandListCount LXxD_UIValueHints2_FormCommandListCount LXx_OVERRIDE
#define LXxC_UIValueHints2_FormCommandListCount(c) LxResult c::uiv_FormCommandListCount (int *count)
#define LXxD_UIValueHints2_FormCommandListByIndex LxResult uiv_FormCommandListByIndex (int index, const char **command)
#define LXxO_UIValueHints2_FormCommandListByIndex LXxD_UIValueHints2_FormCommandListByIndex LXx_OVERRIDE
#define LXxC_UIValueHints2_FormCommandListByIndex(c) LxResult c::uiv_FormCommandListByIndex (int index, const char **command)
template <class T>
class CLxIfc_UIValueHints2 : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    return loc->uiv_Flags ();
  }
    static unsigned
  PopCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    return loc->uiv_PopCount ();
  }
    static const char *
  PopUserName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    return loc->uiv_PopUserName (index);
  }
    static const char *
  PopInternalName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    return loc->uiv_PopInternalName (index);
  }
    static unsigned
  PopIconSize (LXtObjectID wcom, int *w, int *h)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    return loc->uiv_PopIconSize (w,h);
  }
    static LxResult
  PopIconImage (LXtObjectID wcom, int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    try {
      return loc->uiv_PopIconImage (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopIconResource (LXtObjectID wcom, int index, const char **iconResource)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    try {
      return loc->uiv_PopIconResource (index,iconResource);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopFlags (LXtObjectID wcom, unsigned index, int *flags)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    try {
      return loc->uiv_PopFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopCategory (LXtObjectID wcom, const char **category)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    try {
      return loc->uiv_PopCategory (category);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemTest (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    try {
      return loc->uiv_ItemTest ((ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColorPickerCommands (LXtObjectID wcom, char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    try {
      return loc->uiv_ColorPickerCommands (rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    try {
      return loc->uiv_NotifierCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierByIndex (LXtObjectID wcom, int index, const char **name, const char **args)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    try {
      return loc->uiv_NotifierByIndex (index,name,args);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    try {
      return loc->uiv_FormCommandListCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListByIndex (LXtObjectID wcom, int index, const char **command)
  {
    LXCWxINST (CLxImpl_UIValueHints2, loc);
    try {
      return loc->uiv_FormCommandListByIndex (index,command);
    } catch (LxResult rc) { return rc; }
  }
  ILxUIValueHints2 vt;
public:
  CLxIfc_UIValueHints2 ()
  {
    vt.Flags = Flags;
    vt.PopCount = PopCount;
    vt.PopUserName = PopUserName;
    vt.PopInternalName = PopInternalName;
    vt.PopIconSize = PopIconSize;
    vt.PopIconImage = PopIconImage;
    vt.PopIconResource = PopIconResource;
    vt.PopFlags = PopFlags;
    vt.PopCategory = PopCategory;
    vt.ItemTest = ItemTest;
    vt.ColorPickerCommands = ColorPickerCommands;
    vt.NotifierCount = NotifierCount;
    vt.NotifierByIndex = NotifierByIndex;
    vt.FormCommandListCount = FormCommandListCount;
    vt.FormCommandListByIndex = FormCommandListByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_UIValueHints2;
  }
};
class CLxLoc_UIValueHints2 : public CLxLocalize<ILxUIValueHints2ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UIValueHints2() {_init();}
  CLxLoc_UIValueHints2(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UIValueHints2(const CLxLoc_UIValueHints2 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UIValueHints2;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    unsigned
  PopCount (void)
  {
    return m_loc[0]->PopCount (m_loc);
  }
    const char *
  PopUserName (unsigned index)
  {
    return m_loc[0]->PopUserName (m_loc,index);
  }
    const char *
  PopInternalName (unsigned index)
  {
    return m_loc[0]->PopInternalName (m_loc,index);
  }
    unsigned
  PopIconSize (int *w, int *h)
  {
    return m_loc[0]->PopIconSize (m_loc,w,h);
  }
    LxResult
  PopIconImage (int index, void **ppvObj)
  {
    return m_loc[0]->PopIconImage (m_loc,index,ppvObj);
  }
    CLxResult
  PopIconImage (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->PopIconImage(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  PopIconResource (int index, const char **iconResource)
  {
    return m_loc[0]->PopIconResource (m_loc,index,iconResource);
  }
    LxResult
  PopFlags (unsigned index, int *flags)
  {
    return m_loc[0]->PopFlags (m_loc,index,flags);
  }
    LxResult
  PopCategory (const char **category)
  {
    return m_loc[0]->PopCategory (m_loc,category);
  }
    LxResult
  ItemTest (ILxUnknownID item)
  {
    return m_loc[0]->ItemTest (m_loc,(ILxUnknownID)item);
  }
    LxResult
  ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    return m_loc[0]->ColorPickerCommands (m_loc,rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
  }
    LxResult
  NotifierCount (int *count)
  {
    return m_loc[0]->NotifierCount (m_loc,count);
  }
    LxResult
  NotifierByIndex (int index, const char **name, const char **args)
  {
    return m_loc[0]->NotifierByIndex (m_loc,index,name,args);
  }
    LxResult
  FormCommandListCount (int *count)
  {
    return m_loc[0]->FormCommandListCount (m_loc,count);
  }
    LxResult
  FormCommandListByIndex (int index, const char **command)
  {
    return m_loc[0]->FormCommandListByIndex (m_loc,index,command);
  }
};


class CLxImpl_CmdSysListener {
  public:
    virtual ~CLxImpl_CmdSysListener() {}
    virtual void
      cmdsysevent_SystemReady (void)
        { }
    virtual void
      cmdsysevent_UndoLockout (int isLockedOut)
        { }
    virtual void
      cmdsysevent_CommandAdded (const char *name)
        { }
    virtual void
      cmdsysevent_AliasAdded (const char *name, int isOverride)
        { }
    virtual void
      cmdsysevent_AliasRemoved (const char *name, int isOverride)
        { }
    virtual void
      cmdsysevent_ExecutePre (ILxUnknownID cmd, int type, int isSandboxed, int isPostCmd)
        { }
    virtual void
      cmdsysevent_ExecuteResult (ILxUnknownID cmd, int type, int isSandboxed, int isPostCmd, int wasSuccessful)
        { }
    virtual void
      cmdsysevent_ExecutePost (ILxUnknownID cmd, int isSandboxed, int isPostCmd)
        { }
    virtual void
      cmdsysevent_BlockBegin (ILxUnknownID block, int isSandboxed)
        { }
    virtual void
      cmdsysevent_BlockEnd (ILxUnknownID block, int isSandboxed, int wasDiscarded)
        { }
    virtual void
      cmdsysevent_BlockEndedPostMode (const char *name, int isSandboxed)
        { }
    virtual void
      cmdsysevent_RefireBegin (void)
        { }
    virtual void
      cmdsysevent_RefireEnd (void)
        { }
    virtual void
      cmdsysevent_RefiringNext (void)
        { }
    virtual void
      cmdsysevent_PostModeBegin (void)
        { }
    virtual void
      cmdsysevent_PostModeEnd (void)
        { }
    virtual void
      cmdsysevent_PostModeRestart (void)
        { }
    virtual void
      cmdsysevent_PostModeUndoNext (void)
        { }
    virtual void
      cmdsysevent_UserUndo (void)
        { }
    virtual void
      cmdsysevent_UserRedo (void)
        { }
};
#define LXxD_CmdSysListener_SystemReady void cmdsysevent_SystemReady (void)
#define LXxO_CmdSysListener_SystemReady LXxD_CmdSysListener_SystemReady LXx_OVERRIDE
#define LXxC_CmdSysListener_SystemReady(c) void c::cmdsysevent_SystemReady (void)
#define LXxD_CmdSysListener_UndoLockout void cmdsysevent_UndoLockout (int isLockedOut)
#define LXxO_CmdSysListener_UndoLockout LXxD_CmdSysListener_UndoLockout LXx_OVERRIDE
#define LXxC_CmdSysListener_UndoLockout(c) void c::cmdsysevent_UndoLockout (int isLockedOut)
#define LXxD_CmdSysListener_CommandAdded void cmdsysevent_CommandAdded (const char *name)
#define LXxO_CmdSysListener_CommandAdded LXxD_CmdSysListener_CommandAdded LXx_OVERRIDE
#define LXxC_CmdSysListener_CommandAdded(c) void c::cmdsysevent_CommandAdded (const char *name)
#define LXxD_CmdSysListener_AliasAdded void cmdsysevent_AliasAdded (const char *name, int isOverride)
#define LXxO_CmdSysListener_AliasAdded LXxD_CmdSysListener_AliasAdded LXx_OVERRIDE
#define LXxC_CmdSysListener_AliasAdded(c) void c::cmdsysevent_AliasAdded (const char *name, int isOverride)
#define LXxD_CmdSysListener_AliasRemoved void cmdsysevent_AliasRemoved (const char *name, int isOverride)
#define LXxO_CmdSysListener_AliasRemoved LXxD_CmdSysListener_AliasRemoved LXx_OVERRIDE
#define LXxC_CmdSysListener_AliasRemoved(c) void c::cmdsysevent_AliasRemoved (const char *name, int isOverride)
#define LXxD_CmdSysListener_ExecutePre void cmdsysevent_ExecutePre (ILxUnknownID cmd, int type, int isSandboxed, int isPostCmd)
#define LXxO_CmdSysListener_ExecutePre LXxD_CmdSysListener_ExecutePre LXx_OVERRIDE
#define LXxC_CmdSysListener_ExecutePre(c) void c::cmdsysevent_ExecutePre (ILxUnknownID cmd, int type, int isSandboxed, int isPostCmd)
#define LXxD_CmdSysListener_ExecuteResult void cmdsysevent_ExecuteResult (ILxUnknownID cmd, int type, int isSandboxed, int isPostCmd, int wasSuccessful)
#define LXxO_CmdSysListener_ExecuteResult LXxD_CmdSysListener_ExecuteResult LXx_OVERRIDE
#define LXxC_CmdSysListener_ExecuteResult(c) void c::cmdsysevent_ExecuteResult (ILxUnknownID cmd, int type, int isSandboxed, int isPostCmd, int wasSuccessful)
#define LXxD_CmdSysListener_ExecutePost void cmdsysevent_ExecutePost (ILxUnknownID cmd, int isSandboxed, int isPostCmd)
#define LXxO_CmdSysListener_ExecutePost LXxD_CmdSysListener_ExecutePost LXx_OVERRIDE
#define LXxC_CmdSysListener_ExecutePost(c) void c::cmdsysevent_ExecutePost (ILxUnknownID cmd, int isSandboxed, int isPostCmd)
#define LXxD_CmdSysListener_BlockBegin void cmdsysevent_BlockBegin (ILxUnknownID block, int isSandboxed)
#define LXxO_CmdSysListener_BlockBegin LXxD_CmdSysListener_BlockBegin LXx_OVERRIDE
#define LXxC_CmdSysListener_BlockBegin(c) void c::cmdsysevent_BlockBegin (ILxUnknownID block, int isSandboxed)
#define LXxD_CmdSysListener_BlockEnd void cmdsysevent_BlockEnd (ILxUnknownID block, int isSandboxed, int wasDiscarded)
#define LXxO_CmdSysListener_BlockEnd LXxD_CmdSysListener_BlockEnd LXx_OVERRIDE
#define LXxC_CmdSysListener_BlockEnd(c) void c::cmdsysevent_BlockEnd (ILxUnknownID block, int isSandboxed, int wasDiscarded)
#define LXxD_CmdSysListener_BlockEndedPostMode void cmdsysevent_BlockEndedPostMode (const char *name, int isSandboxed)
#define LXxO_CmdSysListener_BlockEndedPostMode LXxD_CmdSysListener_BlockEndedPostMode LXx_OVERRIDE
#define LXxC_CmdSysListener_BlockEndedPostMode(c) void c::cmdsysevent_BlockEndedPostMode (const char *name, int isSandboxed)
#define LXxD_CmdSysListener_RefireBegin void cmdsysevent_RefireBegin (void)
#define LXxO_CmdSysListener_RefireBegin LXxD_CmdSysListener_RefireBegin LXx_OVERRIDE
#define LXxC_CmdSysListener_RefireBegin(c) void c::cmdsysevent_RefireBegin (void)
#define LXxD_CmdSysListener_RefireEnd void cmdsysevent_RefireEnd (void)
#define LXxO_CmdSysListener_RefireEnd LXxD_CmdSysListener_RefireEnd LXx_OVERRIDE
#define LXxC_CmdSysListener_RefireEnd(c) void c::cmdsysevent_RefireEnd (void)
#define LXxD_CmdSysListener_RefiringNext void cmdsysevent_RefiringNext (void)
#define LXxO_CmdSysListener_RefiringNext LXxD_CmdSysListener_RefiringNext LXx_OVERRIDE
#define LXxC_CmdSysListener_RefiringNext(c) void c::cmdsysevent_RefiringNext (void)
#define LXxD_CmdSysListener_PostModeBegin void cmdsysevent_PostModeBegin (void)
#define LXxO_CmdSysListener_PostModeBegin LXxD_CmdSysListener_PostModeBegin LXx_OVERRIDE
#define LXxC_CmdSysListener_PostModeBegin(c) void c::cmdsysevent_PostModeBegin (void)
#define LXxD_CmdSysListener_PostModeEnd void cmdsysevent_PostModeEnd (void)
#define LXxO_CmdSysListener_PostModeEnd LXxD_CmdSysListener_PostModeEnd LXx_OVERRIDE
#define LXxC_CmdSysListener_PostModeEnd(c) void c::cmdsysevent_PostModeEnd (void)
#define LXxD_CmdSysListener_PostModeRestart void cmdsysevent_PostModeRestart (void)
#define LXxO_CmdSysListener_PostModeRestart LXxD_CmdSysListener_PostModeRestart LXx_OVERRIDE
#define LXxC_CmdSysListener_PostModeRestart(c) void c::cmdsysevent_PostModeRestart (void)
#define LXxD_CmdSysListener_PostModeUndoNext void cmdsysevent_PostModeUndoNext (void)
#define LXxO_CmdSysListener_PostModeUndoNext LXxD_CmdSysListener_PostModeUndoNext LXx_OVERRIDE
#define LXxC_CmdSysListener_PostModeUndoNext(c) void c::cmdsysevent_PostModeUndoNext (void)
#define LXxD_CmdSysListener_UserUndo void cmdsysevent_UserUndo (void)
#define LXxO_CmdSysListener_UserUndo LXxD_CmdSysListener_UserUndo LXx_OVERRIDE
#define LXxC_CmdSysListener_UserUndo(c) void c::cmdsysevent_UserUndo (void)
#define LXxD_CmdSysListener_UserRedo void cmdsysevent_UserRedo (void)
#define LXxO_CmdSysListener_UserRedo LXxD_CmdSysListener_UserRedo LXx_OVERRIDE
#define LXxC_CmdSysListener_UserRedo(c) void c::cmdsysevent_UserRedo (void)
template <class T>
class CLxIfc_CmdSysListener : public CLxInterface
{
    static void
  SystemReady (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_SystemReady ();
  }
    static void
  UndoLockout (LXtObjectID wcom, int isLockedOut)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_UndoLockout (isLockedOut);
  }
    static void
  CommandAdded (LXtObjectID wcom, const char *name)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_CommandAdded (name);
  }
    static void
  AliasAdded (LXtObjectID wcom, const char *name, int isOverride)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_AliasAdded (name,isOverride);
  }
    static void
  AliasRemoved (LXtObjectID wcom, const char *name, int isOverride)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_AliasRemoved (name,isOverride);
  }
    static void
  ExecutePre (LXtObjectID wcom, LXtObjectID cmd, int type, int isSandboxed, int isPostCmd)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_ExecutePre ((ILxUnknownID)cmd,type,isSandboxed,isPostCmd);
  }
    static void
  ExecuteResult (LXtObjectID wcom, LXtObjectID cmd, int type, int isSandboxed, int isPostCmd, int wasSuccessful)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_ExecuteResult ((ILxUnknownID)cmd,type,isSandboxed,isPostCmd,wasSuccessful);
  }
    static void
  ExecutePost (LXtObjectID wcom, LXtObjectID cmd, int isSandboxed, int isPostCmd)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_ExecutePost ((ILxUnknownID)cmd,isSandboxed,isPostCmd);
  }
    static void
  BlockBegin (LXtObjectID wcom, LXtObjectID block, int isSandboxed)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_BlockBegin ((ILxUnknownID)block,isSandboxed);
  }
    static void
  BlockEnd (LXtObjectID wcom, LXtObjectID block, int isSandboxed, int wasDiscarded)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_BlockEnd ((ILxUnknownID)block,isSandboxed,wasDiscarded);
  }
    static void
  BlockEndedPostMode (LXtObjectID wcom, const char *name, int isSandboxed)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_BlockEndedPostMode (name,isSandboxed);
  }
    static void
  RefireBegin (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_RefireBegin ();
  }
    static void
  RefireEnd (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_RefireEnd ();
  }
    static void
  RefiringNext (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_RefiringNext ();
  }
    static void
  PostModeBegin (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_PostModeBegin ();
  }
    static void
  PostModeEnd (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_PostModeEnd ();
  }
    static void
  PostModeRestart (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_PostModeRestart ();
  }
    static void
  PostModeUndoNext (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_PostModeUndoNext ();
  }
    static void
  UserUndo (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_UserUndo ();
  }
    static void
  UserRedo (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_CmdSysListener, loc);
    loc->cmdsysevent_UserRedo ();
  }
  ILxCmdSysListener vt;
public:
  CLxIfc_CmdSysListener ()
  {
    vt.SystemReady = SystemReady;
    vt.UndoLockout = UndoLockout;
    vt.CommandAdded = CommandAdded;
    vt.AliasAdded = AliasAdded;
    vt.AliasRemoved = AliasRemoved;
    vt.ExecutePre = ExecutePre;
    vt.ExecuteResult = ExecuteResult;
    vt.ExecutePost = ExecutePost;
    vt.BlockBegin = BlockBegin;
    vt.BlockEnd = BlockEnd;
    vt.BlockEndedPostMode = BlockEndedPostMode;
    vt.RefireBegin = RefireBegin;
    vt.RefireEnd = RefireEnd;
    vt.RefiringNext = RefiringNext;
    vt.PostModeBegin = PostModeBegin;
    vt.PostModeEnd = PostModeEnd;
    vt.PostModeRestart = PostModeRestart;
    vt.PostModeUndoNext = PostModeUndoNext;
    vt.UserUndo = UserUndo;
    vt.UserRedo = UserRedo;
    vTable = &vt.iunk;
    iid = &lx::guid_CmdSysListener;
  }
};
class CLxLoc_CmdSysListener : public CLxLocalize<ILxCmdSysListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CmdSysListener() {_init();}
  CLxLoc_CmdSysListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CmdSysListener(const CLxLoc_CmdSysListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CmdSysListener;}
    void
  SystemReady (void)
  {
    m_loc[0]->SystemReady (m_loc);
  }
    void
  UndoLockout (int isLockedOut)
  {
    m_loc[0]->UndoLockout (m_loc,isLockedOut);
  }
    void
  CommandAdded (const char *name)
  {
    m_loc[0]->CommandAdded (m_loc,name);
  }
    void
  AliasAdded (const char *name, int isOverride)
  {
    m_loc[0]->AliasAdded (m_loc,name,isOverride);
  }
    void
  AliasRemoved (const char *name, int isOverride)
  {
    m_loc[0]->AliasRemoved (m_loc,name,isOverride);
  }
    void
  ExecutePre (ILxUnknownID cmd, int type, int isSandboxed, int isPostCmd)
  {
    m_loc[0]->ExecutePre (m_loc,(ILxUnknownID)cmd,type,isSandboxed,isPostCmd);
  }
    void
  ExecuteResult (ILxUnknownID cmd, int type, int isSandboxed, int isPostCmd, int wasSuccessful)
  {
    m_loc[0]->ExecuteResult (m_loc,(ILxUnknownID)cmd,type,isSandboxed,isPostCmd,wasSuccessful);
  }
    void
  ExecutePost (ILxUnknownID cmd, int isSandboxed, int isPostCmd)
  {
    m_loc[0]->ExecutePost (m_loc,(ILxUnknownID)cmd,isSandboxed,isPostCmd);
  }
    void
  BlockBegin (ILxUnknownID block, int isSandboxed)
  {
    m_loc[0]->BlockBegin (m_loc,(ILxUnknownID)block,isSandboxed);
  }
    void
  BlockEnd (ILxUnknownID block, int isSandboxed, int wasDiscarded)
  {
    m_loc[0]->BlockEnd (m_loc,(ILxUnknownID)block,isSandboxed,wasDiscarded);
  }
    void
  BlockEndedPostMode (const char *name, int isSandboxed)
  {
    m_loc[0]->BlockEndedPostMode (m_loc,name,isSandboxed);
  }
    void
  RefireBegin (void)
  {
    m_loc[0]->RefireBegin (m_loc);
  }
    void
  RefireEnd (void)
  {
    m_loc[0]->RefireEnd (m_loc);
  }
    void
  RefiringNext (void)
  {
    m_loc[0]->RefiringNext (m_loc);
  }
    void
  PostModeBegin (void)
  {
    m_loc[0]->PostModeBegin (m_loc);
  }
    void
  PostModeEnd (void)
  {
    m_loc[0]->PostModeEnd (m_loc);
  }
    void
  PostModeRestart (void)
  {
    m_loc[0]->PostModeRestart (m_loc);
  }
    void
  PostModeUndoNext (void)
  {
    m_loc[0]->PostModeUndoNext (m_loc);
  }
    void
  UserUndo (void)
  {
    m_loc[0]->UserUndo (m_loc);
  }
    void
  UserRedo (void)
  {
    m_loc[0]->UserRedo (m_loc);
  }
};

class CLxImpl_UIValueHints {
  public:
    virtual ~CLxImpl_UIValueHints() {}
    virtual unsigned
      uiv_Flags (void)
        = 0;
    virtual unsigned
      uiv_PopCount (void)
        = 0;
    virtual const char *
      uiv_PopUserName (unsigned index)
        = 0;
    virtual const char *
      uiv_PopInternalName (unsigned index)
        = 0;
    virtual const char *
      uiv_PopToolTip (unsigned index)
        = 0;
    virtual unsigned
      uiv_PopIconSize (int *w, int *h)
        = 0;
    virtual LxResult
      uiv_PopIconImage (int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopIconResource (int index, const char **iconResource)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopFlags (unsigned index, int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopCategory (const char **category)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ItemTest (ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierByIndex (int index, const char **name, const char **args)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListByIndex (int index, const char **command)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_CueText (char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_TextValidate (const char *value, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
};
#define LXxD_UIValueHints_Flags unsigned uiv_Flags (void)
#define LXxO_UIValueHints_Flags LXxD_UIValueHints_Flags LXx_OVERRIDE
#define LXxC_UIValueHints_Flags(c) unsigned c::uiv_Flags (void)
#define LXxD_UIValueHints_PopCount unsigned uiv_PopCount (void)
#define LXxO_UIValueHints_PopCount LXxD_UIValueHints_PopCount LXx_OVERRIDE
#define LXxC_UIValueHints_PopCount(c) unsigned c::uiv_PopCount (void)
#define LXxD_UIValueHints_PopUserName const char * uiv_PopUserName (unsigned index)
#define LXxO_UIValueHints_PopUserName LXxD_UIValueHints_PopUserName LXx_OVERRIDE
#define LXxC_UIValueHints_PopUserName(c) const char * c::uiv_PopUserName (unsigned index)
#define LXxD_UIValueHints_PopInternalName const char * uiv_PopInternalName (unsigned index)
#define LXxO_UIValueHints_PopInternalName LXxD_UIValueHints_PopInternalName LXx_OVERRIDE
#define LXxC_UIValueHints_PopInternalName(c) const char * c::uiv_PopInternalName (unsigned index)
#define LXxD_UIValueHints_PopToolTip const char * uiv_PopToolTip (unsigned index)
#define LXxO_UIValueHints_PopToolTip LXxD_UIValueHints_PopToolTip LXx_OVERRIDE
#define LXxC_UIValueHints_PopToolTip(c) const char * c::uiv_PopToolTip (unsigned index)
#define LXxD_UIValueHints_PopIconSize unsigned uiv_PopIconSize (int *w, int *h)
#define LXxO_UIValueHints_PopIconSize LXxD_UIValueHints_PopIconSize LXx_OVERRIDE
#define LXxC_UIValueHints_PopIconSize(c) unsigned c::uiv_PopIconSize (int *w, int *h)
#define LXxD_UIValueHints_PopIconImage LxResult uiv_PopIconImage (int index, void **ppvObj)
#define LXxO_UIValueHints_PopIconImage LXxD_UIValueHints_PopIconImage LXx_OVERRIDE
#define LXxC_UIValueHints_PopIconImage(c) LxResult c::uiv_PopIconImage (int index, void **ppvObj)
#define LXxD_UIValueHints_PopIconResource LxResult uiv_PopIconResource (int index, const char **iconResource)
#define LXxO_UIValueHints_PopIconResource LXxD_UIValueHints_PopIconResource LXx_OVERRIDE
#define LXxC_UIValueHints_PopIconResource(c) LxResult c::uiv_PopIconResource (int index, const char **iconResource)
#define LXxD_UIValueHints_PopFlags LxResult uiv_PopFlags (unsigned index, int *flags)
#define LXxO_UIValueHints_PopFlags LXxD_UIValueHints_PopFlags LXx_OVERRIDE
#define LXxC_UIValueHints_PopFlags(c) LxResult c::uiv_PopFlags (unsigned index, int *flags)
#define LXxD_UIValueHints_PopCategory LxResult uiv_PopCategory (const char **category)
#define LXxO_UIValueHints_PopCategory LXxD_UIValueHints_PopCategory LXx_OVERRIDE
#define LXxC_UIValueHints_PopCategory(c) LxResult c::uiv_PopCategory (const char **category)
#define LXxD_UIValueHints_ItemTest LxResult uiv_ItemTest (ILxUnknownID item)
#define LXxO_UIValueHints_ItemTest LXxD_UIValueHints_ItemTest LXx_OVERRIDE
#define LXxC_UIValueHints_ItemTest(c) LxResult c::uiv_ItemTest (ILxUnknownID item)
#define LXxD_UIValueHints_ColorPickerCommands LxResult uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
#define LXxO_UIValueHints_ColorPickerCommands LXxD_UIValueHints_ColorPickerCommands LXx_OVERRIDE
#define LXxC_UIValueHints_ColorPickerCommands(c) LxResult c::uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
#define LXxD_UIValueHints_NotifierCount LxResult uiv_NotifierCount (int *count)
#define LXxO_UIValueHints_NotifierCount LXxD_UIValueHints_NotifierCount LXx_OVERRIDE
#define LXxC_UIValueHints_NotifierCount(c) LxResult c::uiv_NotifierCount (int *count)
#define LXxD_UIValueHints_NotifierByIndex LxResult uiv_NotifierByIndex (int index, const char **name, const char **args)
#define LXxO_UIValueHints_NotifierByIndex LXxD_UIValueHints_NotifierByIndex LXx_OVERRIDE
#define LXxC_UIValueHints_NotifierByIndex(c) LxResult c::uiv_NotifierByIndex (int index, const char **name, const char **args)
#define LXxD_UIValueHints_FormCommandListCount LxResult uiv_FormCommandListCount (int *count)
#define LXxO_UIValueHints_FormCommandListCount LXxD_UIValueHints_FormCommandListCount LXx_OVERRIDE
#define LXxC_UIValueHints_FormCommandListCount(c) LxResult c::uiv_FormCommandListCount (int *count)
#define LXxD_UIValueHints_FormCommandListByIndex LxResult uiv_FormCommandListByIndex (int index, const char **command)
#define LXxO_UIValueHints_FormCommandListByIndex LXxD_UIValueHints_FormCommandListByIndex LXx_OVERRIDE
#define LXxC_UIValueHints_FormCommandListByIndex(c) LxResult c::uiv_FormCommandListByIndex (int index, const char **command)
#define LXxD_UIValueHints_CueText LxResult uiv_CueText (char *buf, unsigned len)
#define LXxO_UIValueHints_CueText LXxD_UIValueHints_CueText LXx_OVERRIDE
#define LXxC_UIValueHints_CueText(c) LxResult c::uiv_CueText (char *buf, unsigned len)
#define LXxD_UIValueHints_TextValidate LxResult uiv_TextValidate (const char *value, char *buf, unsigned len)
#define LXxO_UIValueHints_TextValidate LXxD_UIValueHints_TextValidate LXx_OVERRIDE
#define LXxC_UIValueHints_TextValidate(c) LxResult c::uiv_TextValidate (const char *value, char *buf, unsigned len)
template <class T>
class CLxIfc_UIValueHints : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_Flags ();
  }
    static unsigned
  PopCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_PopCount ();
  }
    static const char *
  PopUserName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_PopUserName (index);
  }
    static const char *
  PopInternalName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_PopInternalName (index);
  }
    static const char *
  PopToolTip (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_PopToolTip (index);
  }
    static unsigned
  PopIconSize (LXtObjectID wcom, int *w, int *h)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_PopIconSize (w,h);
  }
    static LxResult
  PopIconImage (LXtObjectID wcom, int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_PopIconImage (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopIconResource (LXtObjectID wcom, int index, const char **iconResource)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_PopIconResource (index,iconResource);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopFlags (LXtObjectID wcom, unsigned index, int *flags)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_PopFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopCategory (LXtObjectID wcom, const char **category)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_PopCategory (category);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemTest (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_ItemTest ((ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColorPickerCommands (LXtObjectID wcom, char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_ColorPickerCommands (rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_NotifierCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierByIndex (LXtObjectID wcom, int index, const char **name, const char **args)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_NotifierByIndex (index,name,args);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_FormCommandListCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListByIndex (LXtObjectID wcom, int index, const char **command)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_FormCommandListByIndex (index,command);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CueText (LXtObjectID wcom, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_CueText (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TextValidate (LXtObjectID wcom, const char *value, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_TextValidate (value,buf,len);
    } catch (LxResult rc) { return rc; }
  }
  ILxUIValueHints vt;
public:
  CLxIfc_UIValueHints ()
  {
    vt.Flags = Flags;
    vt.PopCount = PopCount;
    vt.PopUserName = PopUserName;
    vt.PopInternalName = PopInternalName;
    vt.PopToolTip = PopToolTip;
    vt.PopIconSize = PopIconSize;
    vt.PopIconImage = PopIconImage;
    vt.PopIconResource = PopIconResource;
    vt.PopFlags = PopFlags;
    vt.PopCategory = PopCategory;
    vt.ItemTest = ItemTest;
    vt.ColorPickerCommands = ColorPickerCommands;
    vt.NotifierCount = NotifierCount;
    vt.NotifierByIndex = NotifierByIndex;
    vt.FormCommandListCount = FormCommandListCount;
    vt.FormCommandListByIndex = FormCommandListByIndex;
    vt.CueText = CueText;
    vt.TextValidate = TextValidate;
    vTable = &vt.iunk;
    iid = &lx::guid_UIValueHints;
  }
};
class CLxLoc_UIValueHints : public CLxLocalize<ILxUIValueHintsID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UIValueHints() {_init();}
  CLxLoc_UIValueHints(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UIValueHints(const CLxLoc_UIValueHints &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UIValueHints;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    unsigned
  PopCount (void)
  {
    return m_loc[0]->PopCount (m_loc);
  }
    const char *
  PopUserName (unsigned index)
  {
    return m_loc[0]->PopUserName (m_loc,index);
  }
    const char *
  PopInternalName (unsigned index)
  {
    return m_loc[0]->PopInternalName (m_loc,index);
  }
    const char *
  PopToolTip (unsigned index)
  {
    return m_loc[0]->PopToolTip (m_loc,index);
  }
    unsigned
  PopIconSize (int *w, int *h)
  {
    return m_loc[0]->PopIconSize (m_loc,w,h);
  }
    LxResult
  PopIconImage (int index, void **ppvObj)
  {
    return m_loc[0]->PopIconImage (m_loc,index,ppvObj);
  }
    CLxResult
  PopIconImage (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->PopIconImage(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  PopIconResource (int index, const char **iconResource)
  {
    return m_loc[0]->PopIconResource (m_loc,index,iconResource);
  }
    LxResult
  PopFlags (unsigned index, int *flags)
  {
    return m_loc[0]->PopFlags (m_loc,index,flags);
  }
    LxResult
  PopCategory (const char **category)
  {
    return m_loc[0]->PopCategory (m_loc,category);
  }
    LxResult
  ItemTest (ILxUnknownID item)
  {
    return m_loc[0]->ItemTest (m_loc,(ILxUnknownID)item);
  }
    LxResult
  ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    return m_loc[0]->ColorPickerCommands (m_loc,rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
  }
    LxResult
  NotifierCount (int *count)
  {
    return m_loc[0]->NotifierCount (m_loc,count);
  }
    LxResult
  NotifierByIndex (int index, const char **name, const char **args)
  {
    return m_loc[0]->NotifierByIndex (m_loc,index,name,args);
  }
    LxResult
  FormCommandListCount (int *count)
  {
    return m_loc[0]->FormCommandListCount (m_loc,count);
  }
    LxResult
  FormCommandListByIndex (int index, const char **command)
  {
    return m_loc[0]->FormCommandListByIndex (m_loc,index,command);
  }
    LxResult
  CueText (char *buf, unsigned len)
  {
    return m_loc[0]->CueText (m_loc,buf,len);
  }
    LxResult
  CueText (std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->CueText (m_loc,buf,len);
    LXWx_SBUF2
  }
    LxResult
  TextValidate (const char *value, char *buf, unsigned len)
  {
    return m_loc[0]->TextValidate (m_loc,value,buf,len);
  }
    LxResult
  TextValidate (const char *value, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->TextValidate (m_loc,value,buf,len);
    LXWx_SBUF2
  }
};

class CLxImpl_UIValueHints1 {
  public:
    virtual ~CLxImpl_UIValueHints1() {}
    virtual unsigned
      uiv_Flags (void)
        = 0;
    virtual unsigned
      uiv_PopCount (void)
        = 0;
    virtual const char *
      uiv_PopUserName (unsigned index)
        = 0;
    virtual const char *
      uiv_PopInternalName (unsigned index)
        = 0;
    virtual LxResult
      uiv_PopFlags (unsigned index, int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopCategory (const char **category)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ItemTest (ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierByIndex (const char **name, const char **args)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListByIndex (int index, const char **command)
        { return LXe_NOTIMPL; }
};
#define LXxD_UIValueHints1_Flags unsigned uiv_Flags (void)
#define LXxO_UIValueHints1_Flags LXxD_UIValueHints1_Flags LXx_OVERRIDE
#define LXxC_UIValueHints1_Flags(c) unsigned c::uiv_Flags (void)
#define LXxD_UIValueHints1_PopCount unsigned uiv_PopCount (void)
#define LXxO_UIValueHints1_PopCount LXxD_UIValueHints1_PopCount LXx_OVERRIDE
#define LXxC_UIValueHints1_PopCount(c) unsigned c::uiv_PopCount (void)
#define LXxD_UIValueHints1_PopUserName const char * uiv_PopUserName (unsigned index)
#define LXxO_UIValueHints1_PopUserName LXxD_UIValueHints1_PopUserName LXx_OVERRIDE
#define LXxC_UIValueHints1_PopUserName(c) const char * c::uiv_PopUserName (unsigned index)
#define LXxD_UIValueHints1_PopInternalName const char * uiv_PopInternalName (unsigned index)
#define LXxO_UIValueHints1_PopInternalName LXxD_UIValueHints1_PopInternalName LXx_OVERRIDE
#define LXxC_UIValueHints1_PopInternalName(c) const char * c::uiv_PopInternalName (unsigned index)
#define LXxD_UIValueHints1_PopFlags LxResult uiv_PopFlags (unsigned index, int *flags)
#define LXxO_UIValueHints1_PopFlags LXxD_UIValueHints1_PopFlags LXx_OVERRIDE
#define LXxC_UIValueHints1_PopFlags(c) LxResult c::uiv_PopFlags (unsigned index, int *flags)
#define LXxD_UIValueHints1_PopCategory LxResult uiv_PopCategory (const char **category)
#define LXxO_UIValueHints1_PopCategory LXxD_UIValueHints1_PopCategory LXx_OVERRIDE
#define LXxC_UIValueHints1_PopCategory(c) LxResult c::uiv_PopCategory (const char **category)
#define LXxD_UIValueHints1_ItemTest LxResult uiv_ItemTest (ILxUnknownID item)
#define LXxO_UIValueHints1_ItemTest LXxD_UIValueHints1_ItemTest LXx_OVERRIDE
#define LXxC_UIValueHints1_ItemTest(c) LxResult c::uiv_ItemTest (ILxUnknownID item)
#define LXxD_UIValueHints1_ColorPickerCommands LxResult uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
#define LXxO_UIValueHints1_ColorPickerCommands LXxD_UIValueHints1_ColorPickerCommands LXx_OVERRIDE
#define LXxC_UIValueHints1_ColorPickerCommands(c) LxResult c::uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
#define LXxD_UIValueHints1_NotifierCount LxResult uiv_NotifierCount (int *count)
#define LXxO_UIValueHints1_NotifierCount LXxD_UIValueHints1_NotifierCount LXx_OVERRIDE
#define LXxC_UIValueHints1_NotifierCount(c) LxResult c::uiv_NotifierCount (int *count)
#define LXxD_UIValueHints1_NotifierByIndex LxResult uiv_NotifierByIndex (const char **name, const char **args)
#define LXxO_UIValueHints1_NotifierByIndex LXxD_UIValueHints1_NotifierByIndex LXx_OVERRIDE
#define LXxC_UIValueHints1_NotifierByIndex(c) LxResult c::uiv_NotifierByIndex (const char **name, const char **args)
#define LXxD_UIValueHints1_FormCommandListCount LxResult uiv_FormCommandListCount (int *count)
#define LXxO_UIValueHints1_FormCommandListCount LXxD_UIValueHints1_FormCommandListCount LXx_OVERRIDE
#define LXxC_UIValueHints1_FormCommandListCount(c) LxResult c::uiv_FormCommandListCount (int *count)
#define LXxD_UIValueHints1_FormCommandListByIndex LxResult uiv_FormCommandListByIndex (int index, const char **command)
#define LXxO_UIValueHints1_FormCommandListByIndex LXxD_UIValueHints1_FormCommandListByIndex LXx_OVERRIDE
#define LXxC_UIValueHints1_FormCommandListByIndex(c) LxResult c::uiv_FormCommandListByIndex (int index, const char **command)
template <class T>
class CLxIfc_UIValueHints1 : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    return loc->uiv_Flags ();
  }
    static unsigned
  PopCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    return loc->uiv_PopCount ();
  }
    static const char *
  PopUserName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    return loc->uiv_PopUserName (index);
  }
    static const char *
  PopInternalName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    return loc->uiv_PopInternalName (index);
  }
    static LxResult
  PopFlags (LXtObjectID wcom, unsigned index, int *flags)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_PopFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopCategory (LXtObjectID wcom, const char **category)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_PopCategory (category);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemTest (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_ItemTest ((ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColorPickerCommands (LXtObjectID wcom, char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_ColorPickerCommands (rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_NotifierCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierByIndex (LXtObjectID wcom, const char **name, const char **args)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_NotifierByIndex (name,args);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_FormCommandListCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListByIndex (LXtObjectID wcom, int index, const char **command)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_FormCommandListByIndex (index,command);
    } catch (LxResult rc) { return rc; }
  }
  ILxUIValueHints1 vt;
public:
  CLxIfc_UIValueHints1 ()
  {
    vt.Flags = Flags;
    vt.PopCount = PopCount;
    vt.PopUserName = PopUserName;
    vt.PopInternalName = PopInternalName;
    vt.PopFlags = PopFlags;
    vt.PopCategory = PopCategory;
    vt.ItemTest = ItemTest;
    vt.ColorPickerCommands = ColorPickerCommands;
    vt.NotifierCount = NotifierCount;
    vt.NotifierByIndex = NotifierByIndex;
    vt.FormCommandListCount = FormCommandListCount;
    vt.FormCommandListByIndex = FormCommandListByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_UIValueHints1;
  }
};
class CLxLoc_UIValueHints1 : public CLxLocalize<ILxUIValueHints1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UIValueHints1() {_init();}
  CLxLoc_UIValueHints1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UIValueHints1(const CLxLoc_UIValueHints1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UIValueHints1;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    unsigned
  PopCount (void)
  {
    return m_loc[0]->PopCount (m_loc);
  }
    const char *
  PopUserName (unsigned index)
  {
    return m_loc[0]->PopUserName (m_loc,index);
  }
    const char *
  PopInternalName (unsigned index)
  {
    return m_loc[0]->PopInternalName (m_loc,index);
  }
    LxResult
  PopFlags (unsigned index, int *flags)
  {
    return m_loc[0]->PopFlags (m_loc,index,flags);
  }
    LxResult
  PopCategory (const char **category)
  {
    return m_loc[0]->PopCategory (m_loc,category);
  }
    LxResult
  ItemTest (ILxUnknownID item)
  {
    return m_loc[0]->ItemTest (m_loc,(ILxUnknownID)item);
  }
    LxResult
  ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    return m_loc[0]->ColorPickerCommands (m_loc,rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
  }
    LxResult
  NotifierCount (int *count)
  {
    return m_loc[0]->NotifierCount (m_loc,count);
  }
    LxResult
  NotifierByIndex (const char **name, const char **args)
  {
    return m_loc[0]->NotifierByIndex (m_loc,name,args);
  }
    LxResult
  FormCommandListCount (int *count)
  {
    return m_loc[0]->FormCommandListCount (m_loc,count);
  }
    LxResult
  FormCommandListByIndex (int index, const char **command)
  {
    return m_loc[0]->FormCommandListByIndex (m_loc,index,command);
  }
};

#endif

