#pragma once

#include "../setup.h"

namespace glb
{
    namespace glbIntern
    {
        template<typename T, bool isFloating>
        struct computeEqual {};


        template<typename T>
        struct computeEqual<T, false>
        {
            GLB_INLINE static constexpr bool call(T a, T b) 
            {
                return a == b;
            }
        };

        template<>
        struct computeEqual<float, true>
        {
            GLB_INLINE static constexpr bool call(float a, float b) 
            {
                return std::abs(b - a) < 8.0e-05f;
            }
        };
        template<>
        struct computeEqual<double, true>
        {
            GLB_INLINE static constexpr bool call(double a, double b) 
            {
                return std::abs(b - a) < 8.0e-13;
            }
        };
        template<>
        struct computeEqual<long double, true>
        {
            GLB_INLINE static constexpr bool call(long double a, long double b) 
            {
                return std::abs(b - a) < 8.0e-16L;
            }
        };
    }
} // namespace glb
