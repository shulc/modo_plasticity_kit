/*
 * C++ wrapper for lxforce.h
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
#ifndef LXW_FORCE_HPP
#define LXW_FORCE_HPP

#include <lxforce.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_Force = {0xA712DF74,0x0DD4,0x4D8C,0x87,0xB7,0xCD,0xF6,0x6D,0x4E,0x68,0x48};
};

class CLxImpl_Force {
  public:
    virtual ~CLxImpl_Force() {}
    virtual unsigned
      force_Flags (void)
        { return 0; }
    virtual LxResult
      force_Force (const LXtFVector pos, LXtFVector force)
        { return LXe_NOTIMPL; }
    virtual LxResult
      force_ForceV (const LXtFVector pos, const LXtFVector velocity, LXtFVector force)
        { return LXe_NOTIMPL; }
    virtual LxResult
      force_ForceM (const LXtFVector pos, float mass, LXtFVector force)
        { return LXe_NOTIMPL; }
    virtual LxResult
      force_ForceVM (const LXtFVector pos, const LXtFVector velocity, float mass, LXtFVector force)
        { return LXe_NOTIMPL; }
    virtual LxResult
      force_ForceRun (const float **pos, const float **velocity, const float *mass, float **force, unsigned num)
        { return LXe_NOTIMPL; }
    virtual LxResult
      force_ForceRunAng (const float **pos, const float **velocity, const float **angVel, const float *mass, float **force, float **torque, unsigned num)
        { return LXe_NOTIMPL; }
};
#define LXxD_Force_Flags unsigned force_Flags (void)
#define LXxO_Force_Flags LXxD_Force_Flags LXx_OVERRIDE
#define LXxC_Force_Flags(c) unsigned c::force_Flags (void)
#define LXxD_Force_Force LxResult force_Force (const LXtFVector pos, LXtFVector force)
#define LXxO_Force_Force LXxD_Force_Force LXx_OVERRIDE
#define LXxC_Force_Force(c) LxResult c::force_Force (const LXtFVector pos, LXtFVector force)
#define LXxD_Force_ForceV LxResult force_ForceV (const LXtFVector pos, const LXtFVector velocity, LXtFVector force)
#define LXxO_Force_ForceV LXxD_Force_ForceV LXx_OVERRIDE
#define LXxC_Force_ForceV(c) LxResult c::force_ForceV (const LXtFVector pos, const LXtFVector velocity, LXtFVector force)
#define LXxD_Force_ForceM LxResult force_ForceM (const LXtFVector pos, float mass, LXtFVector force)
#define LXxO_Force_ForceM LXxD_Force_ForceM LXx_OVERRIDE
#define LXxC_Force_ForceM(c) LxResult c::force_ForceM (const LXtFVector pos, float mass, LXtFVector force)
#define LXxD_Force_ForceVM LxResult force_ForceVM (const LXtFVector pos, const LXtFVector velocity, float mass, LXtFVector force)
#define LXxO_Force_ForceVM LXxD_Force_ForceVM LXx_OVERRIDE
#define LXxC_Force_ForceVM(c) LxResult c::force_ForceVM (const LXtFVector pos, const LXtFVector velocity, float mass, LXtFVector force)
#define LXxD_Force_ForceRun LxResult force_ForceRun (const float **pos, const float **velocity, const float *mass, float **force, unsigned num)
#define LXxO_Force_ForceRun LXxD_Force_ForceRun LXx_OVERRIDE
#define LXxC_Force_ForceRun(c) LxResult c::force_ForceRun (const float **pos, const float **velocity, const float *mass, float **force, unsigned num)
#define LXxD_Force_ForceRunAng LxResult force_ForceRunAng (const float **pos, const float **velocity, const float **angVel, const float *mass, float **force, float **torque, unsigned num)
#define LXxO_Force_ForceRunAng LXxD_Force_ForceRunAng LXx_OVERRIDE
#define LXxC_Force_ForceRunAng(c) LxResult c::force_ForceRunAng (const float **pos, const float **velocity, const float **angVel, const float *mass, float **force, float **torque, unsigned num)
template <class T>
class CLxIfc_Force : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Force, loc);
    return loc->force_Flags ();
  }
    static LxResult
  Force (LXtObjectID wcom, const LXtFVector pos, LXtFVector force)
  {
    LXCWxINST (CLxImpl_Force, loc);
    try {
      return loc->force_Force (pos,force);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ForceV (LXtObjectID wcom, const LXtFVector pos, const LXtFVector velocity, LXtFVector force)
  {
    LXCWxINST (CLxImpl_Force, loc);
    try {
      return loc->force_ForceV (pos,velocity,force);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ForceM (LXtObjectID wcom, const LXtFVector pos, float mass, LXtFVector force)
  {
    LXCWxINST (CLxImpl_Force, loc);
    try {
      return loc->force_ForceM (pos,mass,force);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ForceVM (LXtObjectID wcom, const LXtFVector pos, const LXtFVector velocity, float mass, LXtFVector force)
  {
    LXCWxINST (CLxImpl_Force, loc);
    try {
      return loc->force_ForceVM (pos,velocity,mass,force);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ForceRun (LXtObjectID wcom, const float **pos, const float **velocity, const float *mass, float **force, unsigned num)
  {
    LXCWxINST (CLxImpl_Force, loc);
    try {
      return loc->force_ForceRun (pos,velocity,mass,force,num);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ForceRunAng (LXtObjectID wcom, const float **pos, const float **velocity, const float **angVel, const float *mass, float **force, float **torque, unsigned num)
  {
    LXCWxINST (CLxImpl_Force, loc);
    try {
      return loc->force_ForceRunAng (pos,velocity,angVel,mass,force,torque,num);
    } catch (LxResult rc) { return rc; }
  }
  ILxForce vt;
public:
  CLxIfc_Force ()
  {
    vt.Flags = Flags;
    vt.Force = Force;
    vt.ForceV = ForceV;
    vt.ForceM = ForceM;
    vt.ForceVM = ForceVM;
    vt.ForceRun = ForceRun;
    vt.ForceRunAng = ForceRunAng;
    vTable = &vt.iunk;
    iid = &lx::guid_Force;
  }
};
class CLxLoc_Force : public CLxLocalize<ILxForceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Force() {_init();}
  CLxLoc_Force(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Force(const CLxLoc_Force &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Force;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    LxResult
  Force (const LXtFVector pos, LXtFVector force)
  {
    return m_loc[0]->Force (m_loc,pos,force);
  }
    LxResult
  ForceV (const LXtFVector pos, const LXtFVector velocity, LXtFVector force)
  {
    return m_loc[0]->ForceV (m_loc,pos,velocity,force);
  }
    LxResult
  ForceM (const LXtFVector pos, float mass, LXtFVector force)
  {
    return m_loc[0]->ForceM (m_loc,pos,mass,force);
  }
    LxResult
  ForceVM (const LXtFVector pos, const LXtFVector velocity, float mass, LXtFVector force)
  {
    return m_loc[0]->ForceVM (m_loc,pos,velocity,mass,force);
  }
    LxResult
  ForceRun (const float **pos, const float **velocity, const float *mass, float **force, unsigned num)
  {
    return m_loc[0]->ForceRun (m_loc,pos,velocity,mass,force,num);
  }
    LxResult
  ForceRunAng (const float **pos, const float **velocity, const float **angVel, const float *mass, float **force, float **torque, unsigned num)
  {
    return m_loc[0]->ForceRunAng (m_loc,pos,velocity,angVel,mass,force,torque,num);
  }
};

#endif

