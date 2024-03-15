#include "log.hpp"

TLog::~TLog() {
    Info(str());
}

const char* TLog::GetFormat() {
    return "plasticity";
}
const char* TLog::GetVersion() {
    return "0.0.1";
}