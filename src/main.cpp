// TODO:
// 1. Live Link
// 2. Refacet

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

#include <lxu_command.hpp>
#include <lxu_log.hpp>
#include <lxu_scene.hpp>

#include <lx_layer.hpp>

// #include <iostream>
#include <sstream>
#include <fstream>
#include <string>

// for sleep
#include <chrono> 
#include <thread>

constexpr const char* SRVNAME_COMMAND = "plasticity.sync";

class TLog
    : public CLxLogMessage
    , public std::stringstream
{
public:
    ~TLog() {
        Info(str());
    }

private:
    const char* GetFormat() { return SRVNAME_COMMAND; }
    const char* GetVersion() { return "0.0.1"; }
};

namespace websocketpp
{
    namespace log
    {
        template<typename concurrency, typename names>
        class my_logger : public basic<concurrency, names>
        {
        public:
            typedef basic<concurrency, names> base;

            my_logger<concurrency, names>(channel_type_hint::value hint = channel_type_hint::access)
                : basic<concurrency, names>(hint), m_channel_type_hint(hint)
                , m_stream("C:\\Users\\alexa\\Documents\\plasticity_plugin_logger.txt", std::ios::app)
            {
            }

            my_logger<concurrency, names>(level channels, channel_type_hint::value hint = channel_type_hint::access)
                : basic<concurrency, names>(channels, hint), m_channel_type_hint(hint)
                , m_stream("C:\\Users\\alexa\\Documents\\plasticity_plugin_logger.txt", std::ios::app)
            {
            }

            void write(level channel, std::string const& msg)
            {
                write(channel, msg.c_str());
            }

            void write(level channel, char const* msg)
            {
                scoped_lock_type lock(base::m_lock);
                // if (!this->dynamic_test(channel)) return;
                m_stream << "[" << timestamp << "] "
                    << "[" << names::channel_name(channel) << "] "
                    << msg << "\n";
                m_stream.flush();
            }

        private:
            static std::ostream& timestamp(std::ostream& os) {
                std::time_t t = std::time(NULL);
                std::tm lt = lib::localtime(t);
#ifdef _WEBSOCKETPP_PUTTIME_
                return os << std::put_time(&lt, "%Y-%m-%d %H:%M:%S");
#else // Falls back to strftime, which requires a temporary copy of the string.
                char buffer[20];
                size_t result = std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &lt);
                return os << (result == 0 ? "Unknown" : buffer);
#endif
            }

            typedef typename base::scoped_lock_type scoped_lock_type;
            channel_type_hint::value m_channel_type_hint;
            std::ofstream m_stream;
        };
    } // log
} // websocketpp

struct asio_client_with_logger : public websocketpp::config::asio_client {
    typedef websocketpp::log::my_logger<concurrency_type, websocketpp::log::elevel> elog_type;
    typedef websocketpp::log::my_logger<concurrency_type, websocketpp::log::alevel> alog_type;

    struct my_transport_config : public websocketpp::config::asio_client::transport_config {
        typedef asio_client_with_logger::alog_type alog_type;
        typedef asio_client_with_logger::elog_type elog_type;
    };

    // let `my_config` know to create transport endpoints with `my_transport_config`
    typedef websocketpp::transport::asio::endpoint<my_transport_config>
        transport_type;
};

typedef websocketpp::client<websocketpp::config::asio_client> client;

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

 struct TVertex {
    float x, y, z;
};

struct TFace {
    int32_t index[3];
};

struct TNormal {
    float x, y, z;
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

    void Read(std::istringstream& ss) {
        ss.read((char*)&ObjectType, sizeof(uint32_t));
        ss.read((char*)&ObjectId, sizeof(uint32_t));
        ss.read((char*)&VersionId, sizeof(uint32_t));
        ss.read((char*)&ParentId, sizeof(int32_t));
        ss.read((char*)&MaterialId, sizeof(int32_t));
        ss.read((char*)&Flags, sizeof(uint32_t));

        uint32_t nameLength = 0;
        ss.read((char*)&nameLength, sizeof(uint32_t));
        uint32_t padding = (4 - (nameLength % 4)) % 4;
        while (nameLength--) {
            Name.push_back(ss.get());
        }
        while (padding--) {
            ss.get();
        }

        if (ObjectType == EObjectType::Solid || ObjectType == EObjectType::Sheet) {
            uint32_t numVertices = 0;
            ss.read((char*)&numVertices, sizeof(uint32_t));
             if (numVertices) {
                Vertices.resize(numVertices);
                ss.read((char*)&Vertices[0], sizeof(TVertex) * numVertices);
            }

            uint32_t numFaces = 0;
            ss.read((char*)&numFaces, sizeof(uint32_t));
            if (numFaces) {
                Faces.resize(numFaces);
                ss.read((char*)&Faces[0], sizeof(TFace) * numFaces);
            }

            uint32_t numNormals = 0;
            ss.read((char*)&numNormals, sizeof(uint32_t));
            if (numNormals) {
                Normals.resize(numNormals);
                ss.read((char*)&Normals[0], sizeof(TNormal) * numNormals);
            }

            uint32_t numGroups = 0;
            ss.read((char*)&numGroups, sizeof(uint32_t));
            if (numGroups) {
                Groups.resize(numGroups);
                ss.read((char*)&Groups[0], sizeof(int32_t) * numGroups);
            }

            uint32_t numFaceIds = 0;
            ss.read((char*)&numFaceIds, sizeof(uint32_t));
            if (numFaceIds) {
                FaceIds.resize(numFaceIds);
                ss.read((char*)&FaceIds[0], sizeof(int32_t) * numFaceIds);
            }
        }
    }

    void Dump() {
        /*
        std::cerr <<
            "\t\t type:     " << ObjectType << "\n"
            "\t\t id:       " << ObjectId << "\n"
            "\t\t version:  " << VersionId << "\n"
            "\t\t parent:   " << ParentId << "\n"
            "\t\t material: " << MaterialId << "\n"
            "\t\t flags:    " << Flags << "\n"
            "\t\t name:     " << Name << "\n";

        for (const auto& v : Vertices) {
            std::cerr << "\t\t\t v(" << v.x << ", " << v.y << ", " << v.z << " )\n";
        }
        for (const auto& f : Faces) {
            std::cerr << "\t\t\t f(" << f.index[0] << ", " << f.index[1] << ", " << f.index[2] << " )\n";
        }
        for (const auto& n : Normals) {
            std::cerr << "\t\t\t n(" << n.x << ", " << n.y << ", " << n.z << " )\n";
        }
        for (const auto& g : Groups) {
            std::cerr << "\t\t\t g(" << g << " )\n";
        }
        for (const auto& i : FaceIds) {
            std::cerr << "\t\t\t i(" << i << " )\n";
        }
        */
    }
};

struct TMessage {
    EMessageType Type;
    std::vector<TObject> Objects;
};

struct TTransaction {
    std::string Filename;
    uint32_t Version = 0;
    std::vector<TMessage> Messages;
};

TMessage OnMessageItem(std::istringstream& ss) {
    TMessage result;
    uint32_t messageType = 0;
    ss.read((char*)&messageType, sizeof(uint32_t));

    if (messageType == EMessageType::Add) {
        result.Type = EMessageType::Add;
        uint32_t numObjects = 0;
        ss.read((char*)&numObjects, sizeof(uint32_t));

        while (numObjects--) {
            TObject obj;
            obj.Read(ss);
            result.Objects.emplace_back(std::move(obj));
        }
    }

    return result;
}

TTransaction OnTransaction(std::istringstream& ss) {
    TTransaction result;
    uint32_t filenameLength = 0;
    ss.read((char*)&filenameLength, sizeof(uint32_t));
    uint32_t padding = (4 - filenameLength % 4) % 4;
    while(filenameLength--) {
        char c = ss.get();
        result.Filename.push_back(c);
    }

    while (padding--) {
        ss.get();
    }

    ss.read((char*)&result.Version, sizeof(uint32_t));

    uint32_t numMessages = 0;
    ss.read((char*)&numMessages, sizeof(uint32_t));

    while (numMessages--) {
        uint32_t itemLength = 0;
        ss.read((char*)&itemLength, sizeof(uint32_t));

        std::streampos prevPos = ss.tellg();
        result.Messages.emplace_back(std::move(OnMessageItem(ss)));
        std::streampos pos = ss.tellg();
        assert(pos - prevPos == itemLength);
    }

    return result;
}

class connection_metadata {
public:
    typedef websocketpp::lib::shared_ptr<connection_metadata> ptr;

    connection_metadata(websocketpp::connection_hdl hdl, std::string uri)
        : m_hdl(hdl)
        , m_status("Connecting")
        , m_uri(uri)
        , m_server("N/A")
    {}

    void on_open(client* c, websocketpp::connection_hdl hdl) {
        m_status = "Open";

        client::connection_ptr con = c->get_con_from_hdl(hdl);
        m_server = con->get_response_header("Server");
    }

    void on_fail(client* c, websocketpp::connection_hdl hdl) {
        m_status = "Failed";

        client::connection_ptr con = c->get_con_from_hdl(hdl);
        m_server = con->get_response_header("Server");
        m_error_reason = con->get_ec().message();
    }

    void on_close(client* c, websocketpp::connection_hdl hdl) {
        m_status = "Closed";
        client::connection_ptr con = c->get_con_from_hdl(hdl);
        std::ostringstream s;
        s << "close code: " << con->get_remote_close_code() << " ("
            << websocketpp::close::status::get_string(con->get_remote_close_code())
            << "), close reason: " << con->get_remote_close_reason();
        m_error_reason = s.str();
    }

    void on_message(websocketpp::connection_hdl, client::message_ptr msg) {
        uint32_t messageType{};
        std::istringstream ss(msg->get_payload());
        ss.read((char*)&messageType, sizeof(uint32_t));
        if (messageType == EMessageType::ListAll || messageType == EMessageType::ListSome || messageType == EMessageType::ListVisible) {
            uint32_t messageId{};
            uint32_t code{};
            ss.read((char*)&messageId, sizeof(uint32_t));
            ss.read((char*)&code, sizeof(uint32_t));

            std::ostringstream mss;
            mss << "<< ListAll "
                << messageId << " "
                << code;
            m_messages.push_back(mss.str());
            {
                std::cerr << m_messages.back() << "\n";
            }

            TTransaction transaction = OnTransaction(ss);
            std::unique_lock<std::mutex> lock(Mutex);
            Condvar.wait(lock, [this] { return Processed; });
            Objects.clear();
            Filename = transaction.Filename;
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
            Processed = false;
            lock.unlock();
            Condvar.notify_one();
        }
    }

    websocketpp::connection_hdl get_hdl() const {
        return m_hdl;
    }

    std::string get_status() const {
        return m_status;
    }

    void record_sent_message(std::string message) {
        m_messages.push_back(">> " + websocketpp::utility::to_hex(message));
    }

    friend std::ostream& operator<< (std::ostream& out, connection_metadata const& data);
    friend bool Read(connection_metadata& data);

private:
    websocketpp::connection_hdl m_hdl;
    std::string m_status;
    std::string m_uri;
    std::string m_server;
    std::string m_error_reason;
    std::vector<std::string> m_messages;

    std::string Filename;
    std::vector<TObject> Objects;
    std::mutex Mutex;
    std::condition_variable Condvar;
    bool Processed = true;
};

std::ostream& operator<< (std::ostream& out, connection_metadata const& data) {
    out << "> URI: " << data.m_uri << "\n"
        << "> Status: " << data.m_status << "\n"
        << "> Remote Server: " << (data.m_server.empty() ? "None Specified" : data.m_server) << "\n"
        << "> Error/close reason: " << (data.m_error_reason.empty() ? "N/A" : data.m_error_reason);

    std::vector<std::string>::const_iterator it;
    for (it = data.m_messages.begin(); it != data.m_messages.end(); ++it) {
        out << *it << "\n";
    }

    return out;
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

bool Read(connection_metadata& data) {
    std::unique_lock<std::mutex> lock(data.Mutex);
    data.Condvar.wait_for(lock, std::chrono::seconds(1), [&data] { return !data.Processed; });


    const auto& object = data.Objects.front();
 
    CLxSceneSelection sceneSelection;
    CLxUser_Scene scene;
    sceneSelection.Get(scene);
    
    CLxSceneBuilder sceneBuilder;
    sceneBuilder.Initialize(scene);

    unsigned int plasticityID = sceneBuilder.AddItem(LXsITYPE_GROUPLOCATOR);
    sceneBuilder.SetName("Plasticity");

    unsigned int fileID = sceneBuilder.AddItem(LXsITYPE_GROUPLOCATOR);
    sceneBuilder.SetName(data.Filename.c_str());
    sceneBuilder.SetParent(plasticityID);

    std::map<uint32_t, uint32_t> objId2modoId;

    for (const TObject& object : data.Objects) {
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
    data.Processed = true;
    data.Condvar.notify_one();

    return true;
}

class websocket_endpoint {
public:
    websocket_endpoint() {
        m_endpoint.clear_access_channels(websocketpp::log::alevel::all);
        m_endpoint.clear_error_channels(websocketpp::log::elevel::all);
        m_endpoint.set_max_message_size(1 << 31); // 2Gb
        m_endpoint.set_max_http_body_size(1 << 31); // 2Gb

        m_endpoint.init_asio();
        m_endpoint.start_perpetual();

        m_thread = websocketpp::lib::make_shared<websocketpp::lib::thread>(&client::run, &m_endpoint);
    }

    ~websocket_endpoint() {
        m_endpoint.stop_perpetual();

        if (m_metadata && m_metadata->get_status() == "Open") {
            // Only close open connections

            {
                TLog() << "> Closing connection ";
            }

            websocketpp::lib::error_code ec;
            m_endpoint.close(m_metadata->get_hdl(), websocketpp::close::status::going_away, "", ec);
            if (ec) {
                TLog() << "> Error closing connection : "
                    << ec.message();
            }
        }

        m_thread->join();
    }

    bool connect(std::string const& uri) {
        websocketpp::lib::error_code ec;

        client::connection_ptr con = m_endpoint.get_connection(uri, ec);

        if (ec) {
            TLog() << "> Connect initialization error: " << ec.message();
            return false;
        }

        m_metadata = websocketpp::lib::make_shared<connection_metadata>(con->get_handle(), uri);

        con->set_open_handler(websocketpp::lib::bind(
            &connection_metadata::on_open,
            m_metadata,
            &m_endpoint,
            websocketpp::lib::placeholders::_1
        ));
        con->set_fail_handler(websocketpp::lib::bind(
            &connection_metadata::on_fail,
            m_metadata,
            &m_endpoint,
            websocketpp::lib::placeholders::_1
        ));
        con->set_close_handler(websocketpp::lib::bind(
            &connection_metadata::on_close,
            m_metadata,
            &m_endpoint,
            websocketpp::lib::placeholders::_1
        ));
        con->set_message_handler(websocketpp::lib::bind(
            &connection_metadata::on_message,
            m_metadata,
            websocketpp::lib::placeholders::_1,
            websocketpp::lib::placeholders::_2
        ));

        m_endpoint.connect(con);
        TLog() << "> Connect OK!";

        return true;
    }

    void close(websocketpp::close::status::value code, std::string reason) {
        websocketpp::lib::error_code ec;

        m_endpoint.close(m_metadata->get_hdl(), code, reason, ec);
        if (ec) {
            TLog() << "> Error initiating close: " << ec.message();
        }
        TLog() << "> Connect close";

    }

    void send(std::string message) {
        websocketpp::lib::error_code ec;

        if (!m_metadata) {
            TLog() << "> No connection found";
            return;
        }

        m_endpoint.send(m_metadata->get_hdl(), message, websocketpp::frame::opcode::binary, ec);
        if (ec) {
            TLog() << "> Error sending message: " << ec.message();
            return;
        }
        TLog() << "> Send message"; 

        m_metadata->record_sent_message(message);
    }

    void Dump() {
        size_t count = 100;
        while (!Read(*m_metadata)) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            TLog() << "> Wait read.";
            if (!--count) {
                return;
            }
        }
        // TLog() << *m_metadata;
    }


private:
    client m_endpoint;
    websocketpp::lib::shared_ptr<websocketpp::lib::thread> m_thread;
    connection_metadata::ptr m_metadata = nullptr;
};

static websocket_endpoint* Endpoint = nullptr;

class TConnectPlasticity : public CLxBasicCommand {
public:
    TConnectPlasticity() = default;

    int basic_CmdFlags() final;
    bool basic_Enable(CLxUser_Message& msg) final;
    void basic_Execute(unsigned flags);
};

int TConnectPlasticity::basic_CmdFlags() {
    return LXfCMD_UI;
}

bool TConnectPlasticity::basic_Enable(CLxUser_Message& msg) {
    return !Endpoint;
}

void TConnectPlasticity::basic_Execute(unsigned flags) {
    Endpoint = new websocket_endpoint();
    bool connected = Endpoint->connect("ws://localhost:8980");
    if (!connected) {
        throw(std::runtime_error("Unable to connect"));
    } 
}

class TDisconnectPlasticity : public CLxBasicCommand {
public:
    TDisconnectPlasticity() = default;

    int basic_CmdFlags() final;
    bool basic_Enable(CLxUser_Message& msg) final;
    void basic_Execute(unsigned flags);
};

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

class TSyncPlasticity : public CLxBasicCommand {
public:
    TSyncPlasticity() = default;

    int basic_CmdFlags() final;
    bool basic_Enable(CLxUser_Message& msg) final;
    void basic_Execute(unsigned flags) override;

protected:
    uint32_t MessageId = 0;
};

class TSyncVisiblePlasticity : public TSyncPlasticity {
public:
    TSyncVisiblePlasticity() = default;

    void basic_Execute(unsigned flags) override;
};

int TSyncPlasticity::basic_CmdFlags() {
    return LXfCMD_MODEL | LXfCMD_UNDO;
}

bool TSyncPlasticity::basic_Enable(CLxUser_Message& msg) {
    return Endpoint;
}

void TSyncPlasticity::basic_Execute(unsigned flags) {
    // Send ListAll command:
    {
        std::ostringstream ss;
        uint32_t messageType = (uint32_t)EMessageType::ListAll;
        ss.write((const char*)&(messageType), sizeof(uint32_t));
        ss.write((const char*)&(++MessageId), sizeof(uint32_t));
        Endpoint->send(ss.str());
    }
    // 
    // std::this_thread::sleep_for(std::chrono::seconds(1));

    Endpoint->Dump();
}

void TSyncVisiblePlasticity::basic_Execute(unsigned flags) {
    // Send ListAll command:
    {
        std::ostringstream ss;
        uint32_t messageType = (uint32_t)EMessageType::ListVisible;
        ss.write((const char*)&(messageType), sizeof(uint32_t));
        ss.write((const char*)&(++MessageId), sizeof(uint32_t));
        Endpoint->send(ss.str());
    }
    // 
    // std::this_thread::sleep_for(std::chrono::seconds(1));

    Endpoint->Dump();
}

void initialize() {
    CLxGenericPolymorph* srv = nullptr;

    srv = new CLxPolymorph<TConnectPlasticity>;
    srv->AddInterface(new CLxIfc_Command<TConnectPlasticity>);
    srv->AddInterface(new CLxIfc_Attributes<TConnectPlasticity>);
    srv->AddInterface(new CLxIfc_AttributesUI<TConnectPlasticity>);
    lx::AddServer("plasticity.connect", srv);

    srv = new CLxPolymorph<TDisconnectPlasticity>;
    srv->AddInterface(new CLxIfc_Command<TDisconnectPlasticity>);
    srv->AddInterface(new CLxIfc_Attributes<TDisconnectPlasticity>);
    srv->AddInterface(new CLxIfc_AttributesUI<TDisconnectPlasticity>);
    lx::AddServer("plasticity.disconnect", srv);

    srv = new CLxPolymorph<TSyncPlasticity>;
    srv->AddInterface(new CLxIfc_Command<TSyncPlasticity>);
    srv->AddInterface(new CLxIfc_Attributes<TSyncPlasticity>);
    srv->AddInterface(new CLxIfc_AttributesUI<TSyncPlasticity>);
    lx::AddServer("plasticity.sync", srv);

    srv = new CLxPolymorph<TSyncVisiblePlasticity>;
    srv->AddInterface(new CLxIfc_Command<TSyncVisiblePlasticity>);
    srv->AddInterface(new CLxIfc_Attributes<TSyncVisiblePlasticity>);
    srv->AddInterface(new CLxIfc_AttributesUI<TSyncVisiblePlasticity>);
    lx::AddServer("plasticity.sync_visible", srv);
}
