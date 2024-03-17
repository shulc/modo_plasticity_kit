#include "plasticity.hpp"

#include "modo.hpp"
#include <cassert>

namespace {

    TMessage OnMessageItem(std::istream& input) {
        TMessage result;
        uint32_t messageType = 0;
        input.read((char*)&messageType, sizeof(uint32_t));

        if (messageType == EMessageType::Add) {
            result.Type = EMessageType::Add;
            uint32_t numObjects = 0;
            input.read((char*)&numObjects, sizeof(uint32_t));

            while (numObjects--) {
                TObject obj;
                obj.Read(input);
                result.Objects.emplace_back(std::move(obj));
            }
        }

        return result;
    }

    TTransaction OnTransaction(std::istream& input, bool updateOnly) {
        TTransaction result;
        uint32_t filenameLength = 0;
        input.read((char*)&filenameLength, sizeof(uint32_t));
        uint32_t padding = (4 - filenameLength % 4) % 4;
        while (filenameLength--) {
            char c = input.get();
            result.Filename.push_back(c);
        }

        while (padding--) {
            input.get();
        }

        input.read((char*)&result.Version, sizeof(uint32_t));

        uint32_t numMessages = 0;
        input.read((char*)&numMessages, sizeof(uint32_t));

        while (numMessages--) {
            uint32_t itemLength = 0;
            input.read((char*)&itemLength, sizeof(uint32_t));

            std::streampos prevPos = input.tellg();
            result.Messages.emplace_back(std::move(OnMessageItem(input)));
            std::streampos pos = input.tellg();
            assert(pos - prevPos == itemLength);
        }

        return result;
    }

} // anonymous namespace

void TObject::Read(std::istream& input) {
    input.read((char*)&ObjectType, sizeof(uint32_t));
    input.read((char*)&ObjectId, sizeof(uint32_t));
    input.read((char*)&VersionId, sizeof(uint32_t));
    input.read((char*)&ParentId, sizeof(int32_t));
    input.read((char*)&MaterialId, sizeof(int32_t));
    input.read((char*)&Flags, sizeof(uint32_t));

    uint32_t nameLength = 0;
    input.read((char*)&nameLength, sizeof(uint32_t));
    uint32_t padding = (4 - (nameLength % 4)) % 4;
    while (nameLength--) {
        Name.push_back(input.get());
    }
    while (padding--) {
        input.get();
    }

    if (ObjectType == EObjectType::Solid || ObjectType == EObjectType::Sheet) {
        uint32_t numVertices = 0;
        input.read((char*)&numVertices, sizeof(uint32_t));
        if (numVertices) {
            Vertices.resize(numVertices);
            input.read((char*)&Vertices[0], sizeof(TVertex) * numVertices);
        }

        uint32_t numFaces = 0;
        input.read((char*)&numFaces, sizeof(uint32_t));
        if (numFaces) {
            Faces.resize(numFaces);
            input.read((char*)&Faces[0], sizeof(TFace) * numFaces);
        }

        uint32_t numNormals = 0;
        input.read((char*)&numNormals, sizeof(uint32_t));
        if (numNormals) {
            Normals.resize(numNormals);
            input.read((char*)&Normals[0], sizeof(TNormal) * numNormals);
        }

        uint32_t numGroups = 0;
        input.read((char*)&numGroups, sizeof(uint32_t));
        if (numGroups) {
            Groups.resize(numGroups);
            input.read((char*)&Groups[0], sizeof(int32_t) * numGroups);
        }

        uint32_t numFaceIds = 0;
        input.read((char*)&numFaceIds, sizeof(uint32_t));
        if (numFaceIds) {
            FaceIds.resize(numFaceIds);
            input.read((char*)&FaceIds[0], sizeof(int32_t) * numFaceIds);
        }
    }
}

void TObject::Dump(std::ostream& output) {
    output <<
        "\t\t type:     " << ObjectType << "\n"
        "\t\t id:       " << ObjectId << "\n"
        "\t\t version:  " << VersionId << "\n"
        "\t\t parent:   " << ParentId << "\n"
        "\t\t material: " << MaterialId << "\n"
        "\t\t flags:    " << Flags << "\n"
        "\t\t name:     " << Name << "\n";

    for (const auto& v : Vertices) {
        output << "\t\t\t v(" << v.x << ", " << v.y << ", " << v.z << " )\n";
    }
    for (const auto& f : Faces) {
        output << "\t\t\t f(" << f.index[0] << ", " << f.index[1] << ", " << f.index[2] << " )\n";
    }
    for (const auto& n : Normals) {
        output << "\t\t\t n(" << n.x << ", " << n.y << ", " << n.z << " )\n";
    }
    for (const auto& g : Groups) {
        output << "\t\t\t g(" << g << " )\n";
    }
    for (const auto& i : FaceIds) {
        output << "\t\t\t i(" << i << " )\n";
    }
}

void TState::OnMessage(std::istream& input) {
    uint32_t messageType{};
    input.read((char*)&messageType, sizeof(uint32_t));
    if (messageType == EMessageType::ListAll || messageType == EMessageType::ListSome || messageType == EMessageType::ListVisible) {
        uint32_t messageId{};
        uint32_t code{};
        input.read((char*)&messageId, sizeof(uint32_t));
        input.read((char*)&code, sizeof(uint32_t));

        TTransaction transaction = OnTransaction(input, false);

        {
            std::unique_lock<std::mutex> lock(Mutex);
            Condvar.wait(lock, [this] { return !Ready; });
        }
        {
            std::lock_guard stateGuard(MutexObjects);
            Filename = transaction.Filename;
            Objects.clear();
            for (const auto& message : transaction.Messages) {
                if (message.Type == EMessageType::Add) {
                    for (const auto& object : message.Objects) {
                        if (object.ObjectType == EObjectType::Solid
                            || object.ObjectType == EObjectType::Sheet
                            || object.ObjectType == EObjectType::Group) {
                            Objects.push_back(object);
                        }
                    }
                }
            }
        }

        {
            std::lock_guard lock(Mutex);
            Ready = true;
            Condvar.notify_one();
        }
    }
}
