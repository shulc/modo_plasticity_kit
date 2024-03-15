#include "modo.hpp"
#include "websocket.hpp"
#include "plasticity.hpp"


static TWebsocketEndpoint* Endpoint = nullptr;

namespace {

    void SendMessage(EMessageType messageType, uint32_t& messageId) {
        std::ostringstream ss;
        uint32_t message = (uint32_t)messageType;
        ss.write((const char*)&(message), sizeof(uint32_t));
        ss.write((const char*)&(++messageId), sizeof(uint32_t));
        Endpoint->Send(ss.str());
    }

    void CreateMesh(CLxSceneBuilder& sceneBuilder, const TObject& object) {
        std::vector<uint32_t> points;
        uint32_t vertexMapID = sceneBuilder.AddMap(LXi_VMAP_NORMAL, "Vertex Normal");
        assert(object.Vertices.size() == object.Normals.size());
        for (size_t j = 0; j < object.Vertices.size(); ++j) {
            const TVertex& v = object.Vertices[j];
            const TNormal& n = object.Normals[j];

            // some hack for modo y-up
            uint32_t pointID = sceneBuilder.AddPoint(v.x, v.z, -v.y);

            std::array<float, 3> normal{ n.x, n.z, -n.y };
            sceneBuilder.SetPointMap(vertexMapID, &normal[0], pointID);
            points.push_back(pointID);
        }

        for (const TFace& f : object.Faces) {
            sceneBuilder.StartPoly(LXiPTYP_FACE);
            sceneBuilder.AddVertex(points[f.index[0]]);
            sceneBuilder.AddVertex(points[f.index[1]]);
            sceneBuilder.AddVertex(points[f.index[2]]);
            sceneBuilder.AddPolygon();
        }
    }

    void Create(const std::string& filename, const std::vector<TObject>& objects) {
        CLxSceneSelection sceneSelection;
        CLxUser_Scene scene;
        sceneSelection.Get(scene);

        CLxSceneBuilder sceneBuilder;
        sceneBuilder.Initialize(scene);

        unsigned int plasticityID = sceneBuilder.AddItem(LXsITYPE_GROUPLOCATOR);
        sceneBuilder.SetName("Plasticity");

        unsigned int fileID = sceneBuilder.AddItem(LXsITYPE_GROUPLOCATOR);
        sceneBuilder.SetName(filename.c_str());
        sceneBuilder.SetParent(plasticityID);

        std::map<uint32_t, uint32_t> objId2modoId;

        for (const TObject& object : objects) {
            if (object.ObjectType == EObjectType::Group) {
                sceneBuilder.AddItem(LXsITYPE_GROUPLOCATOR);
                sceneBuilder.SetName(object.Name.c_str());
            }
            else if (object.ObjectType == EObjectType::Solid || object.ObjectType == EObjectType::Sheet) {
                sceneBuilder.AddMesh();
                sceneBuilder.SetName(object.Name.c_str());
                CreateMesh(sceneBuilder, object);
            }

            uint32_t parentID = fileID;
            if (object.ParentId != -1) {
                const auto it = objId2modoId.find(object.ParentId);
                if (it != objId2modoId.end()) {
                    parentID = it->second;
                }
            }
            sceneBuilder.SetParent(parentID);
            objId2modoId[object.ObjectId] = sceneBuilder.CurItem();
        }
    }

    void CreateFromState() {
        auto* state = Endpoint->State();
        {
            std::unique_lock<std::mutex> lock(state->Mutex);
            state->Condvar.wait(lock, [state]() { return state->Ready; });
        }
        {
            std::lock_guard guard(state->MutexObjects);
            Create(state->Filename, state->Objects);
        }

        {
            std::unique_lock<std::mutex> lock(state->Mutex);
            state->Ready = false;
            state->Condvar.notify_one();
        }
    }

} // anonymous namespace


int TConnectPlasticity::basic_CmdFlags() {
    return LXfCMD_UI;
}

bool TConnectPlasticity::basic_Enable(CLxUser_Message& msg) {
    return !Endpoint;
}

void TConnectPlasticity::basic_Execute(unsigned flags) {
    Endpoint = new TWebsocketEndpoint();
    bool connected = Endpoint->Connect("ws://localhost:8980");
    if (!connected) {
        throw(std::runtime_error("Unable to connect"));
    }
}

int TDisconnectPlasticity::basic_CmdFlags() {
    return LXfCMD_UI;
}

bool TDisconnectPlasticity::basic_Enable(CLxUser_Message& msg) {
    return Endpoint;
}

void TDisconnectPlasticity::basic_Execute(unsigned flags) {
    delete Endpoint;
    Endpoint = nullptr;
}

class TUnsubscribeAllPlasticity : public TSyncPlasticity {
public:
    TUnsubscribeAllPlasticity() = default;

    void basic_Execute(unsigned flags) override;
};

int TSyncPlasticity::basic_CmdFlags() {
    return LXfCMD_MODEL | LXfCMD_UNDO;
}

bool TSyncPlasticity::basic_Enable(CLxUser_Message& msg) {
    return Endpoint && Endpoint->Status() == "Open";
}

void TSyncPlasticity::basic_Execute(unsigned flags) {
    SendMessage(EMessageType::ListAll, MessageId); 
    CreateFromState();
}

void TSyncVisiblePlasticity::basic_Execute(unsigned flags) {
    SendMessage(EMessageType::ListVisible, MessageId);
    CreateFromState();
}

void TSubscribeAllPlasticity::basic_Execute(unsigned flags) {
    SendMessage(EMessageType::SubscribeAll, MessageId);
}

void TUnsubscribeAllPlasticity::basic_Execute(unsigned flags) {
    SendMessage(EMessageType::UnsubscribeAll, MessageId);
}

