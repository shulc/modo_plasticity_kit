// TODO:
// 1. Live Link
// 2. Refacet

#include "modo.hpp"

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

    srv = new CLxPolymorph<TSubscribeAllPlasticity>;
    srv->AddInterface(new CLxIfc_Command<TSubscribeAllPlasticity>);
    srv->AddInterface(new CLxIfc_Attributes<TSubscribeAllPlasticity>);
    srv->AddInterface(new CLxIfc_AttributesUI<TSubscribeAllPlasticity>);
    lx::AddServer("plasticity.subscribe_all", srv);
}
