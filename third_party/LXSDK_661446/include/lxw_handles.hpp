/*
 * C++ wrapper for lxhandles.h
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
#ifndef LXW_HANDLES_HPP
#define LXW_HANDLES_HPP

#include <lxhandles.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_EventGuide = {0xB2A11425,0x25DE,0x4628,0x83,0x9C,0x99,0x50,0x20,0xBD,0x8D,0xF1};
    static const LXtGUID guid_GeoConstraintPacket = {0x0589BA62,0x5A11,0x453d,0xB8,0x4A,0x1C,0x7C,0xF3,0x0A,0x0D,0x35};
    static const LXtGUID guid_HandleDraw = {0x502ACBC8,0xADFB,0x4493,0x82,0x8C,0x3D,0x2E,0xC4,0x23,0x05,0x1B};
    static const LXtGUID guid_EventTranslatePacket = {0x4D50C150,0x8681,0x4F4A,0x91,0xE9,0xE7,0x30,0xC4,0xD1,0x17,0x3A};
    static const LXtGUID guid_ShapeDraw = {0xDC46A7E2,0x2849,0x46CE,0x90,0x75,0x23,0x94,0xE0,0x4E,0xB3,0xAE};
    static const LXtGUID guid_EventTranslatePacket1 = {0x81B7CACE,0xDB90,0x4AD7,0xAE,0x93,0x42,0xC2,0x3E,0x62,0x13,0x0D};
    static const LXtGUID guid_HandleDraw1 = {0xEEC6665A,0xBB44,0x48A4,0x8F,0x8C,0xB4,0xBC,0xDF,0x2E,0xD8,0x80};
};

class CLxLoc_EventGuide : public CLxLocalize<ILxEventGuideID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_EventGuide() {_init();}
  CLxLoc_EventGuide(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_EventGuide(const CLxLoc_EventGuide &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_EventGuide;}
    int
  Limits (double inner, double outer)
  {
    return m_loc[0]->Limits (m_loc,inner,outer);
  }
    int
  Proximity (ILxUnknownID toolVector, LXtVector pos, double *dist, int *priority, void *element)
  {
    return m_loc[0]->Proximity (m_loc,(ILxUnknownID)toolVector,pos,dist,priority,element);
  }
    int
  SetDrawState (int flags)
  {
    return m_loc[0]->SetDrawState (m_loc,flags);
  }
    void
  SetFlags (int flags)
  {
    m_loc[0]->SetFlags (m_loc,flags);
  }
    int
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
};


class CLxLoc_HandleDraw : public CLxLocalize<ILxHandleDrawID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_HandleDraw() {_init();}
  CLxLoc_HandleDraw(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_HandleDraw(const CLxLoc_HandleDraw &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_HandleDraw;}
    void
  Handle (const LXtVector pos, const LXtMatrix mat, int part, int flags)
  {
    m_loc[0]->Handle (m_loc,pos,mat,part,flags);
  }
    void
  AxisHandle (const LXtVector pos, const LXtMatrix mat, int axis, int part, double len, int flags)
  {
    m_loc[0]->AxisHandle (m_loc,pos,mat,axis,part,len,flags);
  }
    void
  MoveHandle (const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags)
  {
    m_loc[0]->MoveHandle (m_loc,pos,mat,axis,part,flags);
  }
    void
  RotateHandle (const LXtVector pos, const LXtMatrix mat, int axis, int part, double sAngle, double eAngle, int facing, int flags)
  {
    m_loc[0]->RotateHandle (m_loc,pos,mat,axis,part,sAngle,eAngle,facing,flags);
  }
    void
  RotateMouseHandle (const LXtVector center, const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags)
  {
    m_loc[0]->RotateMouseHandle (m_loc,center,pos,mat,axis,part,flags);
  }
    void
  ScaleHandle (const LXtVector pos, const LXtMatrix mat, int axis, int part, double offset, int line, int flags)
  {
    m_loc[0]->ScaleHandle (m_loc,pos,mat,axis,part,offset,line,flags);
  }
    void
  CrossHandle (const LXtVector pos, const LXtMatrix mat, int part, int flags)
  {
    m_loc[0]->CrossHandle (m_loc,pos,mat,part,flags);
  }
    void
  PointHandle (const LXtVector pos, int part, int flags)
  {
    m_loc[0]->PointHandle (m_loc,pos,part,flags);
  }
    void
  XHandle (const LXtVector pos, const LXtMatrix mat, int part, int flags)
  {
    m_loc[0]->XHandle (m_loc,pos,mat,part,flags);
  }
    void
  PlaneHandle (const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags)
  {
    m_loc[0]->PlaneHandle (m_loc,pos,mat,axis,part,flags);
  }
    void
  LineHandleHilight (const LXtVector pos, const LXtVector dir, int part, int flags)
  {
    m_loc[0]->LineHandleHilight (m_loc,pos,dir,part,flags);
  }
    void
  PlaneHandleHilight (const LXtVector pos, const LXtVector norm, int part, int flags)
  {
    m_loc[0]->PlaneHandleHilight (m_loc,pos,norm,part,flags);
  }
};

class CLxLoc_EventTranslatePacket : public CLxLocalize<ILxEventTranslatePacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_EventTranslatePacket() {_init();}
  CLxLoc_EventTranslatePacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_EventTranslatePacket(const CLxLoc_EventTranslatePacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_EventTranslatePacket;}
    int
  ToModel (ILxUnknownID toolVector, LXtVector pos, LXtVector axis)
  {
    return m_loc[0]->ToModel (m_loc,(ILxUnknownID)toolVector,pos,axis);
  }
    void
  ToModelLine (ILxUnknownID toolVector, const LXtVector center, const LXtVector dir, LXtVector pos)
  {
    m_loc[0]->ToModelLine (m_loc,(ILxUnknownID)toolVector,center,dir,pos);
  }
    void
  ToModelPlane (ILxUnknownID toolVector, const LXtVector center, const LXtVector normal, LXtVector pos)
  {
    m_loc[0]->ToModelPlane (m_loc,(ILxUnknownID)toolVector,center,normal,pos);
  }
    void
  ModelDelta (ILxUnknownID toolVector, const LXtVector handle, LXtVector delta)
  {
    m_loc[0]->ModelDelta (m_loc,(ILxUnknownID)toolVector,handle,delta);
  }
    void
  ModelLineDelta (ILxUnknownID toolVector, const LXtVector center, const LXtVector dir, const LXtVector handle, LXtVector delta)
  {
    m_loc[0]->ModelLineDelta (m_loc,(ILxUnknownID)toolVector,center,dir,handle,delta);
  }
    void
  ModelPlaneDelta (ILxUnknownID toolVector, const LXtVector center, const LXtVector normal, const LXtVector handle, LXtVector delta)
  {
    m_loc[0]->ModelPlaneDelta (m_loc,(ILxUnknownID)toolVector,center,normal,handle,delta);
  }
    void
  HitHandle (ILxUnknownID toolVector, const LXtVector handle)
  {
    m_loc[0]->HitHandle (m_loc,(ILxUnknownID)toolVector,handle);
  }
    void
  GetNewPosition (ILxUnknownID toolVector, LXtVector pos)
  {
    m_loc[0]->GetNewPosition (m_loc,(ILxUnknownID)toolVector,pos);
  }
    void
  SetLinearConstraint (ILxUnknownID toolVector, const LXtVector center, const LXtVector dir)
  {
    m_loc[0]->SetLinearConstraint (m_loc,(ILxUnknownID)toolVector,center,dir);
  }
    void
  SetPlanarConstraint (ILxUnknownID toolVector, const LXtVector center, const LXtVector normal)
  {
    m_loc[0]->SetPlanarConstraint (m_loc,(ILxUnknownID)toolVector,center,normal);
  }
    int
  GetConstraint (ILxUnknownID toolVector, LXtVector center, LXtVector vector)
  {
    return m_loc[0]->GetConstraint (m_loc,(ILxUnknownID)toolVector,center,vector);
  }
    void
  SetSnapRange (double inner, double outer)
  {
    m_loc[0]->SetSnapRange (m_loc,inner,outer);
  }
    void
  ScreenToRay (ILxUnknownID toolVector, float x, float y, LXtVector pos, LXtVector dir)
  {
    m_loc[0]->ScreenToRay (m_loc,(ILxUnknownID)toolVector,x,y,pos,dir);
  }
    void
  AddGuide (ILxUnknownID guide, void *client)
  {
    m_loc[0]->AddGuide (m_loc,(ILxUnknownID)guide,client);
  }
    int
  RemoveGuide (ILxUnknownID guide, void *client)
  {
    return m_loc[0]->RemoveGuide (m_loc,(ILxUnknownID)guide,client);
  }
    void
  SetLinearSnapConstraint (ILxUnknownID toolVector, const LXtVector center, const LXtVector dir)
  {
    m_loc[0]->SetLinearSnapConstraint (m_loc,(ILxUnknownID)toolVector,center,dir);
  }
    int
  SnapPosition (ILxUnknownID toolVector, const LXtVector pos, LXtVector snapPos)
  {
    return m_loc[0]->SnapPosition (m_loc,(ILxUnknownID)toolVector,pos,snapPos);
  }
    void
  SetPlanarSnapConstraint (ILxUnknownID toolVector, const LXtVector center, const LXtVector dir)
  {
    m_loc[0]->SetPlanarSnapConstraint (m_loc,(ILxUnknownID)toolVector,center,dir);
  }
};

class CLxLoc_ShapeDraw : public CLxLocalize<ILxShapeDrawID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ShapeDraw() {_init();}
  CLxLoc_ShapeDraw(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ShapeDraw(const CLxLoc_ShapeDraw &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ShapeDraw;}
    void
  Circle (const LXtVector col, double alpha, const LXtVector pos, double rad, int axis, int flags)
  {
    m_loc[0]->Circle (m_loc,col,alpha,pos,rad,axis,flags);
  }
    void
  Ellipse (const LXtVector col, double alpha, const LXtVector pos, const LXtVector rad, int axis, int flags)
  {
    m_loc[0]->Ellipse (m_loc,col,alpha,pos,rad,axis,flags);
  }
    void
  Pill (const LXtVector col, double alpha, const LXtVector pos, double width, double height, double rad, int axis, int flags)
  {
    m_loc[0]->Pill (m_loc,col,alpha,pos,width,height,rad,axis,flags);
  }
    void
  Bone (const LXtVector col, double rlen, int active)
  {
    m_loc[0]->Bone (m_loc,col,rlen,active);
  }
    void
  Arc (const LXtVector col, double alpha, const LXtVector pos, double rad, double start, double end, int axis, int flags)
  {
    m_loc[0]->Arc (m_loc,col,alpha,pos,rad,start,end,axis,flags);
  }
    void
  Plane (const LXtVector col, const LXtVector pos, const LXtVector size, int axis, int flags)
  {
    m_loc[0]->Plane (m_loc,col,pos,size,axis,flags);
  }
    void
  Ellipsoid (const LXtVector col, double alpha, const LXtVector pos, const LXtVector rad, int flags)
  {
    m_loc[0]->Ellipsoid (m_loc,col,alpha,pos,rad,flags);
  }
    void
  Cube (const LXtVector col, const LXtVector pos, const LXtVector size, int flags)
  {
    m_loc[0]->Cube (m_loc,col,pos,size,flags);
  }
    void
  CubeFill (const LXtVector col, double alpha, const LXtVector pos, const LXtVector size, int flags)
  {
    m_loc[0]->CubeFill (m_loc,col,alpha,pos,size,flags);
  }
    void
  BoxShape (const LXtVector colW, const LXtVector colF, const LXtVector pos, const LXtVector size, int flags)
  {
    m_loc[0]->BoxShape (m_loc,colW,colF,pos,size,flags);
  }
    void
  Pyramid (const LXtVector col, const LXtVector pos, const LXtVector size, int axis, int flags)
  {
    m_loc[0]->Pyramid (m_loc,col,pos,size,axis,flags);
  }
    void
  PyramidShape (const LXtVector colW, const LXtVector colF, const LXtVector pos, const LXtVector size, int axis, int flags)
  {
    m_loc[0]->PyramidShape (m_loc,colW,colF,pos,size,axis,flags);
  }
    void
  Rhombus (const LXtVector col, const LXtVector pos, const LXtVector size, int axis, int flags)
  {
    m_loc[0]->Rhombus (m_loc,col,pos,size,axis,flags);
  }
    void
  RhombusShape (const LXtVector colW, const LXtVector colF, const LXtVector pos, const LXtVector size, int axis, int flags)
  {
    m_loc[0]->RhombusShape (m_loc,colW,colF,pos,size,axis,flags);
  }
    void
  Cone (const LXtVector col, const LXtVector pos, double rad, double height, int axis, int flags)
  {
    m_loc[0]->Cone (m_loc,col,pos,rad,height,axis,flags);
  }
    void
  ConeShape (const LXtVector colW, const LXtVector colF, const LXtVector pos, double radius, double height, int axis, int flags)
  {
    m_loc[0]->ConeShape (m_loc,colW,colF,pos,radius,height,axis,flags);
  }
    void
  Cylinder (const LXtVector col, const LXtVector pos, double rad, double height, int axis, int flags)
  {
    m_loc[0]->Cylinder (m_loc,col,pos,rad,height,axis,flags);
  }
    void
  CylinderShape (const LXtVector colW, const LXtVector colF, const LXtVector pos, double radius, double height, int axis, int flags)
  {
    m_loc[0]->CylinderShape (m_loc,colW,colF,pos,radius,height,axis,flags);
  }
    void
  SphereShape (const LXtVector colW, const LXtVector colF, const LXtVector pos, double radius, int axis, int flags)
  {
    m_loc[0]->SphereShape (m_loc,colW,colF,pos,radius,axis,flags);
  }
    void
  CircleShape (const LXtVector colW, const LXtVector colF, const LXtVector pos, double radius, int axis, int flags)
  {
    m_loc[0]->CircleShape (m_loc,colW,colF,pos,radius,axis,flags);
  }
    void
  PlaneShape (const LXtVector colW, const LXtVector colF, const LXtVector pos, const LXtVector size, int axis, int flags)
  {
    m_loc[0]->PlaneShape (m_loc,colW,colF,pos,size,axis,flags);
  }
    void
  RadialMap (ILxUnknownID image, const LXtVector col, const LXtVector cen, double size, int sel, int flags)
  {
    m_loc[0]->RadialMap (m_loc,(ILxUnknownID)image,col,cen,size,sel,flags);
  }
    void
  RadialRays (ILxUnknownID image, const LXtVector col, const LXtVector cen, double size, int sel, int flags)
  {
    m_loc[0]->RadialRays (m_loc,(ILxUnknownID)image,col,cen,size,sel,flags);
  }
    void
  Link (const LXtVector col, const LXtVector posS, const LXtVector posE, int solid, int flags)
  {
    m_loc[0]->Link (m_loc,col,posS,posE,solid,flags);
  }
    void
  BBox (const LXtVector col, double size, int flags)
  {
    m_loc[0]->BBox (m_loc,col,size,flags);
  }
    void
  Arrow (const LXtVector col, const LXtVector pos, double size, int axis, int flags)
  {
    m_loc[0]->Arrow (m_loc,col,pos,size,axis,flags);
  }
    void
  Axis (const LXtVector col, const LXtVector pos, const LXtVector size, int flags)
  {
    m_loc[0]->Axis (m_loc,col,pos,size,flags);
  }
    void
  Star (const LXtVector col, const LXtVector pos, const LXtVector rad, int flags)
  {
    m_loc[0]->Star (m_loc,col,pos,rad,flags);
  }
    void
  Cross (const LXtVector col, const LXtVector pos, const LXtVector rad, int flags)
  {
    m_loc[0]->Cross (m_loc,col,pos,rad,flags);
  }
    void
  Line (const LXtVector v0, const LXtVector v1, const LXtVector col, double alpha, int flags)
  {
    m_loc[0]->Line (m_loc,v0,v1,col,alpha,flags);
  }
    void
  CSeg (const LXtVector cen, const LXtVector offset, double screen, const LXtVector col, int flags)
  {
    m_loc[0]->CSeg (m_loc,cen,offset,screen,col,flags);
  }
    void
  PlaneIndicator (const LXtVector col, double alpha, const LXtVector pos, double rad, int axis, int flags)
  {
    m_loc[0]->PlaneIndicator (m_loc,col,alpha,pos,rad,axis,flags);
  }
    void
  CrossHair (const LXtVector col, double alpha, const LXtVector pos, int flags)
  {
    m_loc[0]->CrossHair (m_loc,col,alpha,pos,flags);
  }
    void
  PreciseHandle (const LXtVector col, double alpha, const LXtVector pos, const LXtVector size, int flags)
  {
    m_loc[0]->PreciseHandle (m_loc,col,alpha,pos,size,flags);
  }
    void
  Ruler (const LXtVector col, const LXtVector pos, const LXtMatrix xfrm, double len, int axis, int flags)
  {
    m_loc[0]->Ruler (m_loc,col,pos,xfrm,len,axis,flags);
  }
    void
  Distance (const LXtVector col, const LXtVector pos, double dist, int axis, int flags)
  {
    m_loc[0]->Distance (m_loc,col,pos,dist,axis,flags);
  }
    void
  Dimension (const LXtVector col, const LXtVector A, const LXtVector B, const char *format, int top, int flags)
  {
    m_loc[0]->Dimension (m_loc,col,A,B,format,top,flags);
  }
    void
  Grid (const LXtVector col, const LXtVector pos, const LXtVector siz, int divX, int divY, int divZ, int axis, int flags)
  {
    m_loc[0]->Grid (m_loc,col,pos,siz,divX,divY,divZ,axis,flags);
  }
};

class CLxLoc_EventTranslatePacket1 : public CLxLocalize<ILxEventTranslatePacket1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_EventTranslatePacket1() {_init();}
  CLxLoc_EventTranslatePacket1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_EventTranslatePacket1(const CLxLoc_EventTranslatePacket1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_EventTranslatePacket1;}
    int
  ToModel (ILxUnknownID toolVector, LXtVector pos, LXtVector axis)
  {
    return m_loc[0]->ToModel (m_loc,(ILxUnknownID)toolVector,pos,axis);
  }
    void
  ToModelLine (ILxUnknownID toolVector, LXtVector center, LXtVector dir, LXtVector pos)
  {
    m_loc[0]->ToModelLine (m_loc,(ILxUnknownID)toolVector,center,dir,pos);
  }
    void
  ToModelPlane (ILxUnknownID toolVector, LXtVector center, LXtVector normal, LXtVector pos)
  {
    m_loc[0]->ToModelPlane (m_loc,(ILxUnknownID)toolVector,center,normal,pos);
  }
    void
  ModelDelta (ILxUnknownID toolVector, const LXtVector handle, LXtVector delta)
  {
    m_loc[0]->ModelDelta (m_loc,(ILxUnknownID)toolVector,handle,delta);
  }
    void
  ModelLineDelta (ILxUnknownID toolVector, const LXtVector center, const LXtVector dir, const LXtVector handle, LXtVector delta)
  {
    m_loc[0]->ModelLineDelta (m_loc,(ILxUnknownID)toolVector,center,dir,handle,delta);
  }
    void
  ModelPlaneDelta (ILxUnknownID toolVector, const LXtVector center, const LXtVector normal, const LXtVector handle, LXtVector delta)
  {
    m_loc[0]->ModelPlaneDelta (m_loc,(ILxUnknownID)toolVector,center,normal,handle,delta);
  }
    void
  HitHandle (ILxUnknownID toolVector, LXtVector handle)
  {
    m_loc[0]->HitHandle (m_loc,(ILxUnknownID)toolVector,handle);
  }
    void
  GetNewPosition (ILxUnknownID toolVector, LXtVector pos)
  {
    m_loc[0]->GetNewPosition (m_loc,(ILxUnknownID)toolVector,pos);
  }
    void
  SetLinearConstraint (ILxUnknownID toolVector, const LXtVector center, const LXtVector dir)
  {
    m_loc[0]->SetLinearConstraint (m_loc,(ILxUnknownID)toolVector,center,dir);
  }
    void
  SetPlanarConstraint (ILxUnknownID toolVector, const LXtVector center, const LXtVector normal)
  {
    m_loc[0]->SetPlanarConstraint (m_loc,(ILxUnknownID)toolVector,center,normal);
  }
    int
  GetConstraint (ILxUnknownID toolVector, LXtVector center, LXtVector vector)
  {
    return m_loc[0]->GetConstraint (m_loc,(ILxUnknownID)toolVector,center,vector);
  }
    void
  SetSnapRange (double inner, double outer)
  {
    m_loc[0]->SetSnapRange (m_loc,inner,outer);
  }
    void
  ScreenToRay (ILxUnknownID toolVector, float x, float y, LXtVector pos, LXtVector dir)
  {
    m_loc[0]->ScreenToRay (m_loc,(ILxUnknownID)toolVector,x,y,pos,dir);
  }
    void
  AddGuide (ILxUnknownID guide, void *client)
  {
    m_loc[0]->AddGuide (m_loc,(ILxUnknownID)guide,client);
  }
    int
  RemoveGuide (ILxUnknownID guide, void *client)
  {
    return m_loc[0]->RemoveGuide (m_loc,(ILxUnknownID)guide,client);
  }
};

class CLxLoc_HandleDraw1 : public CLxLocalize<ILxHandleDraw1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_HandleDraw1() {_init();}
  CLxLoc_HandleDraw1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_HandleDraw1(const CLxLoc_HandleDraw1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_HandleDraw1;}
    void
  Handle (const LXtVector pos, const LXtMatrix mat, int part, int flags)
  {
    m_loc[0]->Handle (m_loc,pos,mat,part,flags);
  }
    void
  AxisHandle (const LXtVector pos, const LXtMatrix mat, int axis, int part, double len, int flags)
  {
    m_loc[0]->AxisHandle (m_loc,pos,mat,axis,part,len,flags);
  }
    void
  MoveHandle (const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags)
  {
    m_loc[0]->MoveHandle (m_loc,pos,mat,axis,part,flags);
  }
    void
  RotateHandle (const LXtVector pos, const LXtMatrix mat, int axis, int part, double sAngle, double eAngle, int facing, int flags)
  {
    m_loc[0]->RotateHandle (m_loc,pos,mat,axis,part,sAngle,eAngle,facing,flags);
  }
    void
  RotateMouseHandle (const LXtVector center, const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags)
  {
    m_loc[0]->RotateMouseHandle (m_loc,center,pos,mat,axis,part,flags);
  }
    void
  ScaleHandle (const LXtVector pos, const LXtMatrix mat, int axis, int part, double offset, int line, int flags)
  {
    m_loc[0]->ScaleHandle (m_loc,pos,mat,axis,part,offset,line,flags);
  }
    void
  CrossHandle (const LXtVector pos, const LXtMatrix mat, int part, int flags)
  {
    m_loc[0]->CrossHandle (m_loc,pos,mat,part,flags);
  }
    void
  PointHandle (const LXtVector pos, int part, int flags)
  {
    m_loc[0]->PointHandle (m_loc,pos,part,flags);
  }
    void
  XHandle (const LXtVector pos, const LXtMatrix mat, int part, int flags)
  {
    m_loc[0]->XHandle (m_loc,pos,mat,part,flags);
  }
    void
  PlaneHandle (const LXtVector pos, const LXtMatrix mat, int axis, int part, int flags)
  {
    m_loc[0]->PlaneHandle (m_loc,pos,mat,axis,part,flags);
  }
    void
  LineHandleHilight (const LXtVector pos, const LXtVector dir, int part, int flags)
  {
    m_loc[0]->LineHandleHilight (m_loc,pos,dir,part,flags);
  }
    void
  PlaneHandleHilight (const LXtVector pos, const LXtVector norm, int part, int flags)
  {
    m_loc[0]->PlaneHandleHilight (m_loc,pos,norm,part,flags);
  }
};

#endif

