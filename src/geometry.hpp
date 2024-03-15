#pragma once

#include <cstdint>

struct TVertex {
    float x, y, z;
};

struct TFace {
    int32_t index[3];
};

struct TNormal {
    float x, y, z;
};



