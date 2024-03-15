#pragma once

#include <lxu_log.hpp>
#include <sstream>

class TLog
    : public CLxLogMessage
    , public std::stringstream
{
public:
    TLog() = default;
    ~TLog();

private:
    const char* GetFormat();
    const char* GetVersion();
};