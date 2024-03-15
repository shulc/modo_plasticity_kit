#pragma once

#include "plasticity.hpp"

#include <lxu_command.hpp>
#include <lxu_scene.hpp>

#include <vector>

class TConnectPlasticity : public CLxBasicCommand {
public:
    TConnectPlasticity() = default;

    int basic_CmdFlags() final;
    bool basic_Enable(CLxUser_Message& msg) final;
    void basic_Execute(unsigned flags);
};

class TDisconnectPlasticity : public CLxBasicCommand {
public:
    TDisconnectPlasticity() = default;

    int basic_CmdFlags() final;
    bool basic_Enable(CLxUser_Message& msg) final;
    void basic_Execute(unsigned flags);
};

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

class TSubscribeAllPlasticity : public TSyncPlasticity {
public:
    TSubscribeAllPlasticity() = default;

    void basic_Execute(unsigned flags) override;
};