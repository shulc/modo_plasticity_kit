/*
 * C++ wrapper for lxitem.h
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
#ifndef LXW_ITEM_HPP
#define LXW_ITEM_HPP

#include <lxitem.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_SceneService = {0x50190141,0x0059,0x48FE,0xB2,0x7D,0x6C,0x98,0xE1,0x34,0x8D,0x7B};
    static const LXtGUID guid_InstanceAssets = {0xC7454DED,0x84A7,0x4E5E,0x8F,0xBE,0xA9,0x8D,0x0E,0xE3,0xC6,0xB4};
    static const LXtGUID guid_ItemGraph = {0xC34D7C65,0x031A,0x4c9d,0x8C,0x01,0x31,0x87,0xD3,0x83,0x93,0x7B};
    static const LXtGUID guid_SceneGraph = {0xFE07D3C5,0xC7E4,0x46af,0x8F,0x0A,0x5A,0xB1,0x73,0xD4,0x84,0x45};
    static const LXtGUID guid_Scene = {0xFF870F44,0xFED9,0x4dbc,0x95,0xBA,0x29,0x72,0xA4,0x3F,0xC9,0x36};
    static const LXtGUID guid_SceneSubset = {0xBC46E557,0xA612,0x4820,0x85,0xF8,0x12,0x2D,0x0F,0xF5,0x52,0x1C};
    static const LXtGUID guid_Scene2Service = {0x3B1E02DD,0x8ACA,0x4f30,0x99,0xC4,0xF8,0x7B,0x62,0x6D,0x4F,0xA3};
    static const LXtGUID guid_Item = {0x7FF2D6D5,0x5E28,0x4650,0x93,0xED,0x89,0xFF,0x25,0x7F,0x96,0x29};
    static const LXtGUID guid_SceneAssets = {0xFB35AE38,0x4BF6,0x4B6E,0x87,0xE0,0x6A,0x6C,0xB2,0x99,0x5B,0x78};
    static const LXtGUID guid_ChannelGraph = {0xF70C8AD7,0xC15F,0x42e7,0x98,0xF6,0x4C,0x4C,0x7F,0x6D,0x57,0x7E};
};

class CLxLoc_SceneService : public CLxLocalizedService
{
public:
  ILxSceneServiceID m_loc;
  void _init() {m_loc=0;}
  CLxLoc_SceneService() {_init();set();}
 ~CLxLoc_SceneService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxSceneServiceID>(lx::GetGlobal(&lx::guid_SceneService));}
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
  Root (void **ppvObj)
  {
    return m_loc[0]->Root (m_loc,ppvObj);
  }
    CLxResult
  Root (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Root(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned
  ItemTypeCount (void)
  {
    return m_loc[0]->ItemTypeCount (m_loc);
  }
    LxResult
  ItemTypeByIndex (unsigned index, LXtItemType *type)
  {
    return m_loc[0]->ItemTypeByIndex (m_loc,index,type);
  }
    LxResult
  ItemTypeLookup (const char *name, LXtItemType *type)
  {
    return m_loc[0]->ItemTypeLookup (m_loc,name,type);
  }
    LxResult
  ItemTypeName (LXtItemType type, const char **name)
  {
    return m_loc[0]->ItemTypeName (m_loc,type,name);
  }
    LxResult
  ItemTypeTest (LXtItemType what, LXtItemType isA)
  {
    return m_loc[0]->ItemTypeTest (m_loc,what,isA);
  }
    LxResult
  ItemTypeSuper (LXtItemType type, LXtItemType *super)
  {
    return m_loc[0]->ItemTypeSuper (m_loc,type,super);
  }
    LxResult
  ItemTypeCommonChannels (ILxUnknownID item1, ILxUnknownID item2, unsigned *count)
  {
    return m_loc[0]->ItemTypeCommonChannels (m_loc,(ILxUnknownID)item1,(ILxUnknownID)item2,count);
  }
    LxResult
  ItemSubTypeCount (LXtItemType type, unsigned int *count)
  {
    return m_loc[0]->ItemSubTypeCount (m_loc,type,count);
  }
    LxResult
  ItemSubTypeByIndex (LXtItemType type, unsigned int index, const char **subtype)
  {
    return m_loc[0]->ItemSubTypeByIndex (m_loc,type,index,subtype);
  }
    LxResult
  ChannelVectorSize (unsigned int mode, unsigned int *size)
  {
    return m_loc[0]->ChannelVectorSize (m_loc,mode,size);
  }
    LxResult
  ChannelVectorTextHints (const LXtTextValueHint **hints)
  {
    return m_loc[0]->ChannelVectorTextHints (m_loc,hints);
  }
    LxResult
  CreateScene (void **ppvObj)
  {
    return m_loc[0]->CreateScene (m_loc,ppvObj);
  }
    CLxResult
  CreateScene (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->CreateScene(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  DestroyScene (ILxUnknownID scene)
  {
    return m_loc[0]->DestroyScene (m_loc,(ILxUnknownID)scene);
  }
    LxResult
  SubSceneAdd (ILxUnknownID scene, ILxUnknownID other, unsigned refItems)
  {
    return m_loc[0]->SubSceneAdd (m_loc,(ILxUnknownID)scene,(ILxUnknownID)other,refItems);
  }
    LxResult
  SubSceneLoad (ILxUnknownID scene, const char *path, ILxUnknownID monitor, void **ppvObj)
  {
    return m_loc[0]->SubSceneLoad (m_loc,(ILxUnknownID)scene,path,(ILxUnknownID)monitor,ppvObj);
  }
    CLxResult
  SubSceneLoad (ILxUnknownID scene, const char *path, ILxUnknownID monitor, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SubSceneLoad(m_loc,(ILxUnknownID)scene,path,(ILxUnknownID)monitor,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetMeshInstSourceItem (ILxUnknownID inst, void **ppvObj)
  {
    return m_loc[0]->GetMeshInstSourceItem (m_loc,(ILxUnknownID)inst,ppvObj);
  }
    CLxResult
  GetMeshInstSourceItem (ILxUnknownID inst, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetMeshInstSourceItem(m_loc,(ILxUnknownID)inst,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    int
  MeshInstanceCount (ILxUnknownID mesh)
  {
    return m_loc[0]->MeshInstanceCount (m_loc,(ILxUnknownID)mesh);
  }
    LxResult
  MeshInstanceByIndex (ILxUnknownID mesh, int index, void **ppvObj)
  {
    return m_loc[0]->MeshInstanceByIndex (m_loc,(ILxUnknownID)mesh,index,ppvObj);
  }
    CLxResult
  MeshInstanceByIndex (ILxUnknownID mesh, int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->MeshInstanceByIndex(m_loc,(ILxUnknownID)mesh,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  LoadImage (ILxUnknownID scene, const char *path, ILxUnknownID monitor, void **ppvObj)
  {
    return m_loc[0]->LoadImage (m_loc,(ILxUnknownID)scene,path,(ILxUnknownID)monitor,ppvObj);
  }
    CLxResult
  LoadImage (ILxUnknownID scene, const char *path, ILxUnknownID monitor, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->LoadImage(m_loc,(ILxUnknownID)scene,path,(ILxUnknownID)monitor,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetReplicatorEnumerator (ILxUnknownID replicatorItem, void **ppvObj)
  {
    return m_loc[0]->GetReplicatorEnumerator (m_loc,(ILxUnknownID)replicatorItem,ppvObj);
  }
    CLxResult
  GetReplicatorEnumerator (ILxUnknownID replicatorItem, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetReplicatorEnumerator(m_loc,(ILxUnknownID)replicatorItem,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemTypeGetTag (LXtItemType type, const char *tag, unsigned super, const char **value)
  {
    return m_loc[0]->ItemTypeGetTag (m_loc,type,tag,super,value);
  }
    LxResult
  ItemGraphCollection (ILxUnknownID collection, LXtItemType type, const char *graph, int fwd)
  {
    return m_loc[0]->ItemGraphCollection (m_loc,(ILxUnknownID)collection,type,graph,fwd);
  }
    LxResult
  AllocEmptyCollection (void **ppvObj)
  {
    return m_loc[0]->AllocEmptyCollection (m_loc,ppvObj);
  }
    CLxResult
  AllocEmptyCollection (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AllocEmptyCollection(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  CloseCollection (ILxUnknownID collection, unsigned mode)
  {
    return m_loc[0]->CloseCollection (m_loc,(ILxUnknownID)collection,mode);
  }
    LxResult
  ItemTypeSupportsInterface (LXtItemType type, const LXtGUID *guid)
  {
    return m_loc[0]->ItemTypeSupportsInterface (m_loc,type,guid);
  }
};

class CLxImpl_InstanceAssets {
  public:
    virtual ~CLxImpl_InstanceAssets() {}
    virtual LxResult
      instass_Count (unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      instass_IdentByIndex (unsigned index, unsigned *isSeq, const char **fileType, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      instass_Category (unsigned index, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      instass_GetPath (const char *ident, char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      instass_SetPath (const char *ident, const char *newPath)
        { return LXe_NOTIMPL; }
};
#define LXxD_InstanceAssets_Count LxResult instass_Count (unsigned *count)
#define LXxO_InstanceAssets_Count LXxD_InstanceAssets_Count LXx_OVERRIDE
#define LXxC_InstanceAssets_Count(c) LxResult c::instass_Count (unsigned *count)
#define LXxD_InstanceAssets_IdentByIndex LxResult instass_IdentByIndex (unsigned index, unsigned *isSeq, const char **fileType, char *buf, unsigned len)
#define LXxO_InstanceAssets_IdentByIndex LXxD_InstanceAssets_IdentByIndex LXx_OVERRIDE
#define LXxC_InstanceAssets_IdentByIndex(c) LxResult c::instass_IdentByIndex (unsigned index, unsigned *isSeq, const char **fileType, char *buf, unsigned len)
#define LXxD_InstanceAssets_Category LxResult instass_Category (unsigned index, char *buf, unsigned len)
#define LXxO_InstanceAssets_Category LXxD_InstanceAssets_Category LXx_OVERRIDE
#define LXxC_InstanceAssets_Category(c) LxResult c::instass_Category (unsigned index, char *buf, unsigned len)
#define LXxD_InstanceAssets_GetPath LxResult instass_GetPath (const char *ident, char *buf, unsigned len)
#define LXxO_InstanceAssets_GetPath LXxD_InstanceAssets_GetPath LXx_OVERRIDE
#define LXxC_InstanceAssets_GetPath(c) LxResult c::instass_GetPath (const char *ident, char *buf, unsigned len)
#define LXxD_InstanceAssets_SetPath LxResult instass_SetPath (const char *ident, const char *newPath)
#define LXxO_InstanceAssets_SetPath LXxD_InstanceAssets_SetPath LXx_OVERRIDE
#define LXxC_InstanceAssets_SetPath(c) LxResult c::instass_SetPath (const char *ident, const char *newPath)
template <class T>
class CLxIfc_InstanceAssets : public CLxInterface
{
    static LxResult
  Count (LXtObjectID wcom, unsigned *count)
  {
    LXCWxINST (CLxImpl_InstanceAssets, loc);
    try {
      return loc->instass_Count (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IdentByIndex (LXtObjectID wcom, unsigned index, unsigned *isSeq, const char **fileType, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_InstanceAssets, loc);
    try {
      return loc->instass_IdentByIndex (index,isSeq,fileType,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Category (LXtObjectID wcom, unsigned index, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_InstanceAssets, loc);
    try {
      return loc->instass_Category (index,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetPath (LXtObjectID wcom, const char *ident, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_InstanceAssets, loc);
    try {
      return loc->instass_GetPath (ident,buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetPath (LXtObjectID wcom, const char *ident, const char *newPath)
  {
    LXCWxINST (CLxImpl_InstanceAssets, loc);
    try {
      return loc->instass_SetPath (ident,newPath);
    } catch (LxResult rc) { return rc; }
  }
  ILxInstanceAssets vt;
public:
  CLxIfc_InstanceAssets ()
  {
    vt.Count = Count;
    vt.IdentByIndex = IdentByIndex;
    vt.Category = Category;
    vt.GetPath = GetPath;
    vt.SetPath = SetPath;
    vTable = &vt.iunk;
    iid = &lx::guid_InstanceAssets;
  }
};
class CLxLoc_InstanceAssets : public CLxLocalize<ILxInstanceAssetsID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_InstanceAssets() {_init();}
  CLxLoc_InstanceAssets(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_InstanceAssets(const CLxLoc_InstanceAssets &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_InstanceAssets;}
    LxResult
  Count (unsigned *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  IdentByIndex (unsigned index, unsigned *isSeq, const char **fileType, char *buf, unsigned len) const
  {
    return m_loc[0]->IdentByIndex (m_loc,index,isSeq,fileType,buf,len);
  }
    LxResult
  IdentByIndex (unsigned index, unsigned *isSeq, const char **fileType, std::string &result) const
  {
    LXWx_SBUF1
    rc = m_loc[0]->IdentByIndex (m_loc,index,isSeq,fileType,buf,len);
    LXWx_SBUF2
  }
    LxResult
  Category (unsigned index, char *buf, unsigned len) const
  {
    return m_loc[0]->Category (m_loc,index,buf,len);
  }
    LxResult
  Category (unsigned index, std::string &result) const
  {
    LXWx_SBUF1
    rc = m_loc[0]->Category (m_loc,index,buf,len);
    LXWx_SBUF2
  }
    LxResult
  GetPath (const char *ident, char *buf, unsigned len) const
  {
    return m_loc[0]->GetPath (m_loc,ident,buf,len);
  }
    LxResult
  GetPath (const char *ident, std::string &result) const
  {
    LXWx_SBUF1
    rc = m_loc[0]->GetPath (m_loc,ident,buf,len);
    LXWx_SBUF2
  }
    LxResult
  SetPath (const char *ident, const char *newPath)
  {
    return m_loc[0]->SetPath (m_loc,ident,newPath);
  }
};

class CLxLoc_ItemGraph : public CLxLocalize<ILxItemGraphID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemGraph() {_init();}
  CLxLoc_ItemGraph(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemGraph(const CLxLoc_ItemGraph &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemGraph;}
    LxResult
  AddLink (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->AddLink (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    LxResult
  SetLink (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->SetLink (m_loc,(ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
  }
    LxResult
  DeleteLink (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->DeleteLink (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    LxResult
  FwdCount (ILxUnknownID item, unsigned *count)
  {
    return m_loc[0]->FwdCount (m_loc,(ILxUnknownID)item,count);
  }
    LxResult
  FwdByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
  {
    return m_loc[0]->FwdByIndex (m_loc,(ILxUnknownID)item,index,ppvObj);
  }
    CLxResult
  FwdByIndex (ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->FwdByIndex(m_loc,(ILxUnknownID)item,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RevCount (ILxUnknownID item, unsigned *count)
  {
    return m_loc[0]->RevCount (m_loc,(ILxUnknownID)item,count);
  }
    LxResult
  RevByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
  {
    return m_loc[0]->RevByIndex (m_loc,(ILxUnknownID)item,index,ppvObj);
  }
    CLxResult
  RevByIndex (ILxUnknownID item, unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->RevByIndex(m_loc,(ILxUnknownID)item,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxLoc_SceneGraph : public CLxLocalize<ILxSceneGraphID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneGraph() {_init();}
  CLxLoc_SceneGraph(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SceneGraph(const CLxLoc_SceneGraph &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SceneGraph;}
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  Context (void **ppvObj)
  {
    return m_loc[0]->Context (m_loc,ppvObj);
  }
    CLxResult
  Context (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Context(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RootCount (int *count)
  {
    return m_loc[0]->RootCount (m_loc,count);
  }
    LxResult
  RootByIndex (int index, void **ppvObj)
  {
    return m_loc[0]->RootByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  RootByIndex (int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->RootByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RootFirst (void **ppvObj)
  {
    return m_loc[0]->RootFirst (m_loc,ppvObj);
  }
    CLxResult
  RootFirst (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->RootFirst(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RootNext (void **ppvObj)
  {
    return m_loc[0]->RootNext (m_loc,ppvObj);
  }
    CLxResult
  RootNext (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->RootNext(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RootSetPos (ILxUnknownID item, int pos)
  {
    return m_loc[0]->RootSetPos (m_loc,(ILxUnknownID)item,pos);
  }
    LxResult
  RootRemove (ILxUnknownID item)
  {
    return m_loc[0]->RootRemove (m_loc,(ILxUnknownID)item);
  }
};

class CLxLoc_Scene : public CLxLocalize<ILxSceneID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Scene() {_init();}
  CLxLoc_Scene(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Scene(const CLxLoc_Scene &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Scene;}
    LXtItemType
  ItemRootType (void)
  {
    return m_loc[0]->ItemRootType (m_loc);
  }
    LxResult
  Filename (const char **filename)
  {
    return m_loc[0]->Filename (m_loc,filename);
  }
    LxResult
  FriendlyFilename (unsigned flags, const char **filename)
  {
    return m_loc[0]->FriendlyFilename (m_loc,flags,filename);
  }
    LxResult
  FileFormat (const char **format)
  {
    return m_loc[0]->FileFormat (m_loc,format);
  }
    LxResult
  Changed (unsigned changed)
  {
    return m_loc[0]->Changed (m_loc,changed);
  }
    LxResult
  HasChanged (unsigned int *numChanges)
  {
    return m_loc[0]->HasChanged (m_loc,numChanges);
  }
    LxResult
  Parent (void **ppvObj)
  {
    return m_loc[0]->Parent (m_loc,ppvObj);
  }
    CLxResult
  Parent (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Parent(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SubSceneCount (LXtItemType type, unsigned int *count)
  {
    return m_loc[0]->SubSceneCount (m_loc,type,count);
  }
    LxResult
  SubSceneByIndex (LXtItemType type, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->SubSceneByIndex (m_loc,type,index,ppvObj);
  }
    CLxResult
  SubSceneByIndex (LXtItemType type, unsigned int index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SubSceneByIndex(m_loc,type,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    unsigned
  LoadFlags (void)
  {
    return m_loc[0]->LoadFlags (m_loc);
  }
    LxResult
  Channels (const char *name, double time, void **ppvObj) const
  {
    return m_loc[0]->Channels (m_loc,name,time,ppvObj);
  }
    CLxResult
  Channels (const char *name, double time, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Channels(m_loc,name,time,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemCount (LXtItemType type, unsigned int *count) const
  {
    return m_loc[0]->ItemCount (m_loc,type,count);
  }
    LxResult
  ItemByIndex (LXtItemType type, unsigned int index, void **ppvObj) const
  {
    return m_loc[0]->ItemByIndex (m_loc,type,index,ppvObj);
  }
    CLxResult
  ItemByIndex (LXtItemType type, unsigned int index, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemByIndex(m_loc,type,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemLookup (const char *id, void **ppvObj) const
  {
    return m_loc[0]->ItemLookup (m_loc,id,ppvObj);
  }
    CLxResult
  ItemLookup (const char *id, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemLookup(m_loc,id,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemCountByTypes (const LXtItemType *types, unsigned *count) const
  {
    return m_loc[0]->ItemCountByTypes (m_loc,types,count);
  }
    LxResult
  ItemByIndexByTypes (const LXtItemType *types, unsigned index, void **ppvObj) const
  {
    return m_loc[0]->ItemByIndexByTypes (m_loc,types,index,ppvObj);
  }
    CLxResult
  ItemByIndexByTypes (const LXtItemType *types, unsigned index, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemByIndexByTypes(m_loc,types,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AnyItemOfType (LXtItemType type, void **ppvObj) const
  {
    return m_loc[0]->AnyItemOfType (m_loc,type,ppvObj);
  }
    CLxResult
  AnyItemOfType (LXtItemType type, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AnyItemOfType(m_loc,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemLocalize (ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->ItemLocalize (m_loc,(ILxUnknownID)item,ppvObj);
  }
    CLxResult
  ItemLocalize (ILxUnknownID item, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemLocalize(m_loc,(ILxUnknownID)item,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemAdd (LXtItemType type, void **ppvObj)
  {
    return m_loc[0]->ItemAdd (m_loc,type,ppvObj);
  }
    CLxResult
  ItemAdd (LXtItemType type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemAdd(m_loc,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemInstance (ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->ItemInstance (m_loc,(ILxUnknownID)item,ppvObj);
  }
    CLxResult
  ItemInstance (ILxUnknownID item, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemInstance(m_loc,(ILxUnknownID)item,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemAddReference (ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->ItemAddReference (m_loc,(ILxUnknownID)item,ppvObj);
  }
    CLxResult
  ItemAddReference (ILxUnknownID item, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemAddReference(m_loc,(ILxUnknownID)item,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GraphLookup (const char *name, void **ppvObj) const
  {
    return m_loc[0]->GraphLookup (m_loc,name,ppvObj);
  }
    CLxResult
  GraphLookup (const char *name, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GraphLookup(m_loc,name,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GraphCount (int *count) const
  {
    return m_loc[0]->GraphCount (m_loc,count);
  }
    LxResult
  GraphByIndex (unsigned index, void **ppvObj) const
  {
    return m_loc[0]->GraphByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  GraphByIndex (unsigned index, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GraphByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemRemove (ILxUnknownID item)
  {
    return m_loc[0]->ItemRemove (m_loc,(ILxUnknownID)item);
  }
    LxResult
  Import (const char *path, ILxUnknownID monitor)
  {
    return m_loc[0]->Import (m_loc,path,(ILxUnknownID)monitor);
  }
    LxResult
  EvalModInvalidate (const char *modName)
  {
    return m_loc[0]->EvalModInvalidate (m_loc,modName);
  }
    LxResult
  EvalModReset (const char *modName)
  {
    return m_loc[0]->EvalModReset (m_loc,modName);
  }
    LxResult
  ItemReplace (ILxUnknownID item, int type, void **ppvObj)
  {
    return m_loc[0]->ItemReplace (m_loc,(ILxUnknownID)item,type,ppvObj);
  }
    CLxResult
  ItemReplace (ILxUnknownID item, int type, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemReplace(m_loc,(ILxUnknownID)item,type,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetupMode (void)
  {
    return m_loc[0]->SetupMode (m_loc);
  }
    LxResult
  SetupChannels (void **ppvObj) const
  {
    return m_loc[0]->SetupChannels (m_loc,ppvObj);
  }
    CLxResult
  SetupChannels (CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SetupChannels(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemLookupIdent (const char *id, void **ppvObj)
  {
    return m_loc[0]->ItemLookupIdent (m_loc,id,ppvObj);
  }
    CLxResult
  ItemLookupIdent (const char *id, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemLookupIdent(m_loc,id,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  ItemLookupImported (const char *id, void **ppvObj)
  {
    return m_loc[0]->ItemLookupImported (m_loc,id,ppvObj);
  }
    CLxResult
  ItemLookupImported (const char *id, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemLookupImported(m_loc,id,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RenderCameraCount (int *count) const
  {
    return m_loc[0]->RenderCameraCount (m_loc,count);
  }
    LxResult
  RenderCameraByIndex (int index, void **ppvObj) const
  {
    return m_loc[0]->RenderCameraByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  RenderCameraByIndex (int index, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->RenderCameraByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RenderCameraIndex (ILxUnknownID eval, int *index) const
  {
    return m_loc[0]->RenderCameraIndex (m_loc,(ILxUnknownID)eval,index);
  }
    LxResult
  ItemCopy (ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->ItemCopy (m_loc,(ILxUnknownID)item,ppvObj);
  }
    CLxResult
  ItemCopy (ILxUnknownID item, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ItemCopy(m_loc,(ILxUnknownID)item,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  BatchCreateBegin (void)
  {
    return m_loc[0]->BatchCreateBegin (m_loc);
  }
    LxResult
  BatchCreateEnd (void)
  {
    return m_loc[0]->BatchCreateEnd (m_loc);
  }
    LxResult
  BatchCreateAbort (void)
  {
    return m_loc[0]->BatchCreateAbort (m_loc);
  }
    LxResult
  BatchCopyBegin (ILxUnknownID destination)
  {
    return m_loc[0]->BatchCopyBegin (m_loc,(ILxUnknownID)destination);
  }
    LxResult
  BatchCopyEnd (void)
  {
    return m_loc[0]->BatchCopyEnd (m_loc);
  }
    LxResult
  BatchCopyAbort (void)
  {
    return m_loc[0]->BatchCopyAbort (m_loc);
  }
    LxResult
  WorkPlaneRotation (ILxUnknownID chanRead, LXtMatrix m3)
  {
    return m_loc[0]->WorkPlaneRotation (m_loc,(ILxUnknownID)chanRead,m3);
  }
    LxResult
  WorkPlanePosition (ILxUnknownID chanRead, LXtVector pos)
  {
    return m_loc[0]->WorkPlanePosition (m_loc,(ILxUnknownID)chanRead,pos);
  }
    LxResult
  GeneralCollection (const char *typeName, const char *arg, ILxUnknownID rootItem, void **ppvObj)
  {
    return m_loc[0]->GeneralCollection (m_loc,typeName,arg,(ILxUnknownID)rootItem,ppvObj);
  }
    CLxResult
  GeneralCollection (const char *typeName, const char *arg, ILxUnknownID rootItem, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GeneralCollection(m_loc,typeName,arg,(ILxUnknownID)rootItem,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GeneralCollectionRaw (const char *typeName, const char *arg, ILxUnknownID rootItem, void **ppvObj)
  {
    return m_loc[0]->GeneralCollectionRaw (m_loc,typeName,arg,(ILxUnknownID)rootItem,ppvObj);
  }
    CLxResult
  GeneralCollectionRaw (const char *typeName, const char *arg, ILxUnknownID rootItem, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GeneralCollectionRaw(m_loc,typeName,arg,(ILxUnknownID)rootItem,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  AllocAssets (void **ppvObj)
  {
    return m_loc[0]->AllocAssets (m_loc,ppvObj);
  }
    CLxResult
  AllocAssets (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->AllocAssets(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  DeleteCollection (ILxUnknownID collection, unsigned closeMode)
  {
    return m_loc[0]->DeleteCollection (m_loc,(ILxUnknownID)collection,closeMode);
  }
    LxResult
  CustomLoad (ILxUnknownID visitor)
  {
    return m_loc[0]->CustomLoad (m_loc,(ILxUnknownID)visitor);
  }
    LxResult
  TextureCopy (ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->TextureCopy (m_loc,(ILxUnknownID)item,ppvObj);
  }
    CLxResult
  TextureCopy (ILxUnknownID item, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->TextureCopy(m_loc,(ILxUnknownID)item,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

class CLxImpl_SceneSubset {
  public:
    virtual ~CLxImpl_SceneSubset() {}
    virtual LxResult
      scnsub_GetScene (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scnsub_GetCollection (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_SceneSubset_GetScene LxResult scnsub_GetScene (void **ppvObj)
#define LXxO_SceneSubset_GetScene LXxD_SceneSubset_GetScene LXx_OVERRIDE
#define LXxC_SceneSubset_GetScene(c) LxResult c::scnsub_GetScene (void **ppvObj)
#define LXxD_SceneSubset_GetCollection LxResult scnsub_GetCollection (void **ppvObj)
#define LXxO_SceneSubset_GetCollection LXxD_SceneSubset_GetCollection LXx_OVERRIDE
#define LXxC_SceneSubset_GetCollection(c) LxResult c::scnsub_GetCollection (void **ppvObj)
template <class T>
class CLxIfc_SceneSubset : public CLxInterface
{
    static LxResult
  GetScene (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SceneSubset, loc);
    try {
      return loc->scnsub_GetScene (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetCollection (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SceneSubset, loc);
    try {
      return loc->scnsub_GetCollection (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxSceneSubset vt;
public:
  CLxIfc_SceneSubset ()
  {
    vt.GetScene = GetScene;
    vt.GetCollection = GetCollection;
    vTable = &vt.iunk;
    iid = &lx::guid_SceneSubset;
  }
};
class CLxLoc_SceneSubset : public CLxLocalize<ILxSceneSubsetID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneSubset() {_init();}
  CLxLoc_SceneSubset(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SceneSubset(const CLxLoc_SceneSubset &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SceneSubset;}
    LxResult
  GetScene (void **ppvObj)
  {
    return m_loc[0]->GetScene (m_loc,ppvObj);
  }
    CLxResult
  GetScene (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetScene(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  GetCollection (void **ppvObj)
  {
    return m_loc[0]->GetCollection (m_loc,ppvObj);
  }
    CLxResult
  GetCollection (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->GetCollection(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};


class CLxLoc_Item : public CLxLocalize<ILxItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Item() {_init();}
  CLxLoc_Item(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Item(const CLxLoc_Item &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Item;}
    LXtItemType
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  TestType (LXtItemType type)
  {
    return m_loc[0]->TestType (m_loc,type);
  }
    LxResult
  TestTypes (const LXtItemType *types)
  {
    return m_loc[0]->TestTypes (m_loc,types);
  }
    LxResult
  Ident (const char **ident) const
  {
    return m_loc[0]->Ident (m_loc,ident);
  }
    LxResult
  SetIdent (const char *ident)
  {
    return m_loc[0]->SetIdent (m_loc,ident);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  SetName (const char *name)
  {
    return m_loc[0]->SetName (m_loc,name);
  }
    LxResult
  UniqueName (const char **name)
  {
    return m_loc[0]->UniqueName (m_loc,name);
  }
    LxResult
  UniqueIndex (unsigned *index)
  {
    return m_loc[0]->UniqueIndex (m_loc,index);
  }
    LxResult
  SetUniqueIndex (unsigned index)
  {
    return m_loc[0]->SetUniqueIndex (m_loc,index);
  }
    LxResult
  Parent (void **ppvObj)
  {
    return m_loc[0]->Parent (m_loc,ppvObj);
  }
    CLxResult
  Parent (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Parent(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetParent (ILxUnknownID parent)
  {
    return m_loc[0]->SetParent (m_loc,(ILxUnknownID)parent);
  }
    LxResult
  SubCount (unsigned *count)
  {
    return m_loc[0]->SubCount (m_loc,count);
  }
    LxResult
  SubByIndex (unsigned index, void **ppvObj)
  {
    return m_loc[0]->SubByIndex (m_loc,index,ppvObj);
  }
    CLxResult
  SubByIndex (unsigned index, CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->SubByIndex(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Root (void **ppvObj)
  {
    return m_loc[0]->Root (m_loc,ppvObj);
  }
    CLxResult
  Root (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Root(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Context (void **ppvObj)
  {
    return m_loc[0]->Context (m_loc,ppvObj);
  }
    CLxResult
  Context (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Context(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Reference (void **ppvObj)
  {
    return m_loc[0]->Reference (m_loc,ppvObj);
  }
    CLxResult
  Reference (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Reference(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  IsReferenced (void)
  {
    return m_loc[0]->IsReferenced (m_loc);
  }
    LxResult
  Source (void **ppvObj)
  {
    return m_loc[0]->Source (m_loc,ppvObj);
  }
    CLxResult
  Source (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Source(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  SetSource (ILxUnknownID source)
  {
    return m_loc[0]->SetSource (m_loc,(ILxUnknownID)source);
  }
    LxResult
  ChannelCount (unsigned *count) const
  {
    return m_loc[0]->ChannelCount (m_loc,count);
  }
    LxResult
  ChannelLookup (const char *name, unsigned *index) const
  {
    return m_loc[0]->ChannelLookup (m_loc,name,index);
  }
    LxResult
  ChannelName (unsigned index, const char **name) const
  {
    return m_loc[0]->ChannelName (m_loc,index,name);
  }
    LxResult
  ChannelType (unsigned index, unsigned *type)
  {
    return m_loc[0]->ChannelType (m_loc,index,type);
  }
    LxResult
  ChannelVectorMode (unsigned index, unsigned *mode, unsigned *components)
  {
    return m_loc[0]->ChannelVectorMode (m_loc,index,mode,components);
  }
    LxResult
  ChannelStorageType (unsigned index, const char **type)
  {
    return m_loc[0]->ChannelStorageType (m_loc,index,type);
  }
    LxResult
  ChannelEvalType (unsigned index, const char **type)
  {
    return m_loc[0]->ChannelEvalType (m_loc,index,type);
  }
    LxResult
  ChannelGradient (unsigned index, const char **input, const char **output)
  {
    return m_loc[0]->ChannelGradient (m_loc,index,input,output);
  }
    LxResult
  ChannelIntHint (unsigned index, const LXtTextValueHint **hints) const
  {
    return m_loc[0]->ChannelIntHint (m_loc,index,hints);
  }
    LxResult
  ChannelPackage (unsigned index, const char **package)
  {
    return m_loc[0]->ChannelPackage (m_loc,index,package);
  }
    LxResult
  PackageAdd (const char *package)
  {
    return m_loc[0]->PackageAdd (m_loc,package);
  }
    LxResult
  PackageTest (const char *package) const
  {
    return m_loc[0]->PackageTest (m_loc,package);
  }
    LxResult
  PackageStartIndex (const char *package, unsigned *index)
  {
    return m_loc[0]->PackageStartIndex (m_loc,package,index);
  }
    LxResult
  PackageRemove (const char *package)
  {
    return m_loc[0]->PackageRemove (m_loc,package);
  }
    LxResult
  ChannelAdd (void **ppvObj)
  {
    return m_loc[0]->ChannelAdd (m_loc,ppvObj);
  }
    CLxResult
  ChannelAdd (CLxLocalizedObject &o_dest)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->ChannelAdd(m_loc,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    const char *
  GetTag (LXtID4 type)
  {
    return m_loc[0]->GetTag (m_loc,type);
  }
    LxResult
  SetTag (LXtID4 type, const char *tag)
  {
    return m_loc[0]->SetTag (m_loc,type,tag);
  }
    void
  InvalidateName (void)
  {
    m_loc[0]->InvalidateName (m_loc);
  }
    LxResult
  WasLoaded (unsigned test)
  {
    return m_loc[0]->WasLoaded (m_loc,test);
  }
    LxResult
  Delete (void)
  {
    return m_loc[0]->Delete (m_loc);
  }
    LxResult
  ChannelIsDriven (unsigned index)
  {
    return m_loc[0]->ChannelIsDriven (m_loc,index);
  }
    LxResult
  SetParentAndPosition (ILxUnknownID parent, unsigned pos)
  {
    return m_loc[0]->SetParentAndPosition (m_loc,(ILxUnknownID)parent,pos);
  }
    LxResult
  BaseName (const char **name)
  {
    return m_loc[0]->BaseName (m_loc,name);
  }
};

class CLxLoc_SceneAssets : public CLxLocalize<ILxSceneAssetsID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneAssets() {_init();}
  CLxLoc_SceneAssets(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SceneAssets(const CLxLoc_SceneAssets &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SceneAssets;}
    LxResult
  Count (unsigned *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  Item (unsigned index, void **ppvObj) const
  {
    return m_loc[0]->Item (m_loc,index,ppvObj);
  }
    CLxResult
  Item (unsigned index, CLxLocalizedObject &o_dest) const
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->Item(m_loc,index,&o_obj);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  Ident (unsigned index, const char **ident)
  {
    return m_loc[0]->Ident (m_loc,index,ident);
  }
    LxResult
  FileType (unsigned index, const char **type)
  {
    return m_loc[0]->FileType (m_loc,index,type);
  }
    LxResult
  Category (unsigned index, const char **category) const
  {
    return m_loc[0]->Category (m_loc,index,category);
  }
    LxResult
  IsSequence (unsigned index)
  {
    return m_loc[0]->IsSequence (m_loc,index);
  }
    LxResult
  GetPath (ILxUnknownID item, const char *ident, char *buf, unsigned len) const
  {
    return m_loc[0]->GetPath (m_loc,(ILxUnknownID)item,ident,buf,len);
  }
    LxResult
  GetPath (ILxUnknownID item, const char *ident, std::string &result) const
  {
    LXWx_SBUF1
    rc = m_loc[0]->GetPath (m_loc,(ILxUnknownID)item,ident,buf,len);
    LXWx_SBUF2
  }
    LxResult
  SetPath (ILxUnknownID item, const char *ident, const char *newPath)
  {
    return m_loc[0]->SetPath (m_loc,(ILxUnknownID)item,ident,newPath);
  }
};

class CLxLoc_ChannelGraph : public CLxLocalize<ILxChannelGraphID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelGraph() {_init();}
  CLxLoc_ChannelGraph(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelGraph(const CLxLoc_ChannelGraph &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelGraph;}
    LxResult
  AddLink (ILxUnknownID from, int fromChan, ILxUnknownID to, int toChan)
  {
    return m_loc[0]->AddLink (m_loc,(ILxUnknownID)from,fromChan,(ILxUnknownID)to,toChan);
  }
    LxResult
  SetLink (ILxUnknownID from, int fromChan, int fromIndex, ILxUnknownID to, int toChan, int toIndex)
  {
    return m_loc[0]->SetLink (m_loc,(ILxUnknownID)from,fromChan,fromIndex,(ILxUnknownID)to,toChan,toIndex);
  }
    LxResult
  DeleteLink (ILxUnknownID from, int fromChan, ILxUnknownID to, int toChan)
  {
    return m_loc[0]->DeleteLink (m_loc,(ILxUnknownID)from,fromChan,(ILxUnknownID)to,toChan);
  }
    LxResult
  FwdCount (ILxUnknownID item, int channel, unsigned *count)
  {
    return m_loc[0]->FwdCount (m_loc,(ILxUnknownID)item,channel,count);
  }
    LxResult
  FwdByIndex (ILxUnknownID item, int channel, unsigned index, void **ppvObj, int *objChan)
  {
    return m_loc[0]->FwdByIndex (m_loc,(ILxUnknownID)item,channel,index,ppvObj,objChan);
  }
    CLxResult
  FwdByIndex (ILxUnknownID item, int channel, unsigned index, CLxLocalizedObject &o_dest, int *objChan)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->FwdByIndex(m_loc,(ILxUnknownID)item,channel,index,&o_obj,objChan);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
    LxResult
  RevCount (ILxUnknownID item, int channel, unsigned *count)
  {
    return m_loc[0]->RevCount (m_loc,(ILxUnknownID)item,channel,count);
  }
    LxResult
  RevByIndex (ILxUnknownID item, int channel, unsigned index, void **ppvObj, int *objChan)
  {
    return m_loc[0]->RevByIndex (m_loc,(ILxUnknownID)item,channel,index,ppvObj,objChan);
  }
    CLxResult
  RevByIndex (ILxUnknownID item, int channel, unsigned index, CLxLocalizedObject &o_dest, int *objChan)
  {
    LXtObjectID o_obj;
    LxResult r_c = m_loc[0]->RevByIndex(m_loc,(ILxUnknownID)item,channel,index,&o_obj,objChan);
    return lx::TakeResult(o_dest,r_c,o_obj);
  }
};

#endif

