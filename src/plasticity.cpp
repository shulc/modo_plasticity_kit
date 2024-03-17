#include "plasticity.hpp"

#include "modo.hpp"
#include <cassert>

void TTransaction::OnMessage(std::istream& input) {
    uint32_t messageType = 0;
    input.read((char*)&messageType, sizeof(uint32_t));
    int32_t numObjects = 0;
    input.read((char*)&numObjects, sizeof(uint32_t));

    if (messageType == EMessageType::Delete) {
        while (numObjects--) {
            int32_t id = 0;
            input.read((char*)&id, sizeof(uint32_t));
            Delete.push_back(id);
        }
    } else if (messageType == EMessageType::Update || messageType == EMessageType::Add) {
        std::vector<TObject>& objects = (messageType == EMessageType::Update ? Update : Add);

        while (numObjects--) {
            TObject obj;
            obj.Read(input);
            objects.emplace_back(std::move(obj));
        }
    }

}

TTransaction::TTransaction(std::istream& input) {
    uint32_t filenameLength = 0;
    input.read((char*)&filenameLength, sizeof(uint32_t));
    uint32_t padding = (4 - filenameLength % 4) % 4;
    while (filenameLength--) {
        char c = input.get();
        Filename.push_back(c);
    }

    while (padding--) {
        input.get();
    }

    input.read((char*)&Version, sizeof(uint32_t));

    uint32_t numMessages = 0;
    input.read((char*)&numMessages, sizeof(uint32_t));

    while (numMessages--) {
        uint32_t itemLength = 0;
        input.read((char*)&itemLength, sizeof(uint32_t));

        std::streampos prevPos = input.tellg();
        OnMessage(input);
        std::streampos pos = input.tellg();
        assert(pos - prevPos == itemLength);
    }
}

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

    if (messageType == EMessageType::Transaction) {
        TTransaction transaction(input);

        // TODO: implement SceneHandler::on_transaction
    }
    else if (messageType == EMessageType::ListAll || messageType == EMessageType::ListSome || messageType == EMessageType::ListVisible) {
        uint32_t messageId{};
        uint32_t code{};
        input.read((char*)&messageId, sizeof(uint32_t));
        input.read((char*)&code, sizeof(uint32_t));

        TTransaction transaction(input);

        {
            std::unique_lock<std::mutex> lock(Mutex);
            Condvar.wait(lock, [this] { return !Ready; });
        }
        {
            std::lock_guard stateGuard(MutexObjects);
            Filename = transaction.Filename;
            Objects.clear();
            for (const auto& object : transaction.Add) {
                if (object.ObjectType == EObjectType::Solid
                    || object.ObjectType == EObjectType::Sheet
                    || object.ObjectType == EObjectType::Group) {
                    Objects.push_back(object);
                }
            }

            // TODO: implement delete unused items.
        }

        {
            std::lock_guard lock(Mutex);
            Ready = true;
            Condvar.notify_one();
        }
    }
}