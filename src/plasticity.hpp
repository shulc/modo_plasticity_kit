#pragma once

#include "geometry.hpp"

#include <istream>
#include <ostream>
#include <sys/_types/_int32_t.h>
#include <vector>
#include <mutex>

enum EMessageType {
    Transaction = 0,
    Add = 1,
    Update = 2,
    Delete = 3,
    Move = 4,
    Attribute = 5,

    NewVersion = 10,
    NewFile = 11,

    ListAll = 20,
    ListSome = 21,
    ListVisible = 22,
    SubscribeAll = 23,
    SubscribeSome = 24,
    UnsubscribeAll = 25,
    RefacetSome = 26,
};

enum EObjectType {
    Solid = 0,
    Sheet = 1,
    Wire = 2,
    Group = 5,
    Empty = 6,
};

enum EFacetShapeType {
    Any = 20500,
    Cut = 20501,
    Convex = 20502,
};

struct TObject {
    uint32_t ObjectType;
    uint32_t ObjectId;
    uint32_t VersionId;
    int32_t ParentId;
    int32_t MaterialId;
    uint32_t Flags;
    std::string Name;

    std::vector<TVertex> Vertices;
    std::vector<TFace> Faces;
    std::vector<TNormal> Normals;
    std::vector<int32_t> Groups;
    std::vector<int32_t> FaceIds;

    void Read(std::istream& input);
    void Dump(std::ostream& output);
};

class TTransaction {
public:
    std::string Filename;
    uint32_t Version = 0;
    std::vector<TObject> Add;
    std::vector<TObject> Update;
    std::vector<int32_t> Delete;

    TTransaction(std::istream& input);

private:
    void OnMessage(std::istream& input);
};

struct TState {
    std::string Filename;
    std::vector<TObject> Objects;

    std::mutex MutexObjects;

    bool Ready = false;
    std::mutex Mutex;
    std::condition_variable Condvar;

    void OnMessage(std::istream& input);
};