#pragma once

#include "plasticity.hpp"

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

using TClient = websocketpp::client<websocketpp::config::asio_client>;

class TConnectionMetadata {
    public:
        using TPtr = websocketpp::lib::shared_ptr<TConnectionMetadata>;

        TConnectionMetadata(websocketpp::connection_hdl hdl, std::string uri);
        void OnOpen(TClient* c, websocketpp::connection_hdl hdl);
        void OnFail(TClient* c, websocketpp::connection_hdl hdl);
        void OnClose(TClient* c, websocketpp::connection_hdl hdl);
        void OnMessage(websocketpp::connection_hdl, TClient::message_ptr msg);
        websocketpp::connection_hdl GetHdl() const;
        std::string GetStatus() const;

        TState State;
    private:
        websocketpp::connection_hdl m_hdl;
        std::string m_status;
        std::string m_uri;
        std::string m_server;
        std::string m_error_reason;
        std::vector<std::string> m_messages;

};

class TWebsocketEndpoint {
public:
    TWebsocketEndpoint();
    ~TWebsocketEndpoint();
    bool Connect(std::string const& uri);
    void Close(websocketpp::close::status::value code, std::string reason);
    void Send(std::string message);
    std::string Status() const;
    TState* State();

private:
    TClient m_endpoint;
    websocketpp::lib::shared_ptr<websocketpp::lib::thread> m_thread;
    TConnectionMetadata::TPtr m_metadata = nullptr;
};