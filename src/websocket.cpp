#include "websocket.hpp"

#include "plasticity.hpp"
#include "log.hpp"

TConnectionMetadata::TConnectionMetadata(websocketpp::connection_hdl hdl, std::string uri)
    : m_hdl(hdl)
    , m_status("Connecting")
    , m_uri(uri)
    , m_server("N/A")
{}

void TConnectionMetadata::OnOpen(TClient* c, websocketpp::connection_hdl hdl) {
    m_status = "Open";

    TClient::connection_ptr con = c->get_con_from_hdl(hdl);
    m_server = con->get_response_header("Server");
}

void TConnectionMetadata::OnFail(TClient* c, websocketpp::connection_hdl hdl) {
    m_status = "Failed";

    TClient::connection_ptr con = c->get_con_from_hdl(hdl);
    m_server = con->get_response_header("Server");
    m_error_reason = con->get_ec().message();
}

void TConnectionMetadata::OnClose(TClient* c, websocketpp::connection_hdl hdl) {
    m_status = "Closed";
    TClient::connection_ptr con = c->get_con_from_hdl(hdl);
    std::ostringstream s;
    s << "close code: " << con->get_remote_close_code() << " ("
        << websocketpp::close::status::get_string(con->get_remote_close_code())
        << "), close reason: " << con->get_remote_close_reason();
    m_error_reason = s.str();
}

void TConnectionMetadata::OnMessage(websocketpp::connection_hdl, TClient::message_ptr msg) {
    std::istringstream input(msg->get_payload());
    State.OnMessage(input);
}

websocketpp::connection_hdl TConnectionMetadata::GetHdl() const {
    return m_hdl;
}

std::string TConnectionMetadata::GetStatus() const {
    return m_status;
}

TWebsocketEndpoint::TWebsocketEndpoint() {
        m_endpoint.clear_access_channels(websocketpp::log::alevel::all);
        m_endpoint.clear_error_channels(websocketpp::log::elevel::all);
        m_endpoint.set_max_message_size(1ul << 31); // 2Gb
        m_endpoint.set_max_http_body_size(1ul << 31); // 2Gb

        m_endpoint.init_asio();
        m_endpoint.start_perpetual();

        m_thread = websocketpp::lib::make_shared<websocketpp::lib::thread>(&TClient::run, &m_endpoint);
    }

TWebsocketEndpoint::~TWebsocketEndpoint() {
        m_endpoint.stop_perpetual();

        if (m_metadata && m_metadata->GetStatus() == "Open") {
            // Only close open connections

            {
                TLog() << "> Closing connection ";
            }

            websocketpp::lib::error_code ec;
            m_endpoint.close(m_metadata->GetHdl(), websocketpp::close::status::going_away, "", ec);
            if (ec) {
                TLog() << "> Error closing connection : "
                    << ec.message();
            }
        }

        m_thread->join();
    }

    bool TWebsocketEndpoint::Connect(std::string const& uri) {
        websocketpp::lib::error_code ec;

        TClient::connection_ptr con = m_endpoint.get_connection(uri, ec);

        if (ec) {
            TLog() << "> Connect initialization error: " << ec.message();
            return false;
        }

        m_metadata = websocketpp::lib::make_shared<TConnectionMetadata>(con->get_handle(), uri);

        con->set_open_handler(websocketpp::lib::bind(
            &TConnectionMetadata::OnOpen,
            m_metadata,
            &m_endpoint,
            websocketpp::lib::placeholders::_1
        ));
        con->set_fail_handler(websocketpp::lib::bind(
            &TConnectionMetadata::OnFail,
            m_metadata,
            &m_endpoint,
            websocketpp::lib::placeholders::_1
        ));
        con->set_close_handler(websocketpp::lib::bind(
            &TConnectionMetadata::OnClose,
            m_metadata,
            &m_endpoint,
            websocketpp::lib::placeholders::_1
        ));
        con->set_message_handler(websocketpp::lib::bind(
            &TConnectionMetadata::OnMessage,
            m_metadata,
            websocketpp::lib::placeholders::_1,
            websocketpp::lib::placeholders::_2
        ));

        m_endpoint.connect(con);
        TLog() << "> Connect OK!";

        return true;
    }

    void TWebsocketEndpoint::Close(websocketpp::close::status::value code, std::string reason) {
        websocketpp::lib::error_code ec;

        m_endpoint.close(m_metadata->GetHdl(), code, reason, ec);
        if (ec) {
            TLog() << "> Error initiating close: " << ec.message();
        }
        TLog() << "> Connect close";

    }

    void TWebsocketEndpoint::Send(std::string message) {
        websocketpp::lib::error_code ec;

        if (!m_metadata) {
            TLog() << "> No connection found";
            return;
        }

        m_endpoint.send(m_metadata->GetHdl(), message, websocketpp::frame::opcode::binary, ec);
        if (ec) {
            TLog() << "> Error sending message: " << ec.message();
            return;
        }
        TLog() << "> Send message";
    }

    std::string TWebsocketEndpoint::Status() const {
        if (!m_metadata) {
            return "";
        }

        return m_metadata->GetStatus();
    }

    TState* TWebsocketEndpoint::State()
    {
        if (!m_metadata)
            return nullptr;
        return &m_metadata->State;
    }
