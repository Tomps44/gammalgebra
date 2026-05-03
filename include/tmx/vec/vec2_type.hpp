#pragma once

#include "tmx/internal/vec/type_vec2.hpp"
#include <cstdint>

namespace tmx
{
    typedef vec<2, float> Vec2;
    typedef vec<2, double> Vec2HighP;
    typedef vec<2, std::int32_t> Vec2Int; // int or std::int32_t ? For the second case, create an alias ?
    typedef vec<2, bool> Vec2Bool;
}