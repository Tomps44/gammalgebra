#pragma once

#include "../internal/definitions.h"
#include <cmath>

namespace glb
{
    namespace Math
    {
        template<typename T>
        GLB_INLINE constexpr T ToRad(T degAngle) noexcept { return degAngle * static_cast<T>(0.0174532925199432957691391462423657899L); };
        template<typename T>
        GLB_INLINE constexpr T ToDeg(T radAngle) noexcept { return radAngle * static_cast<T>(57.295779513082320876654618402312735L); };



        template<typename T>
        GLB_INLINE constexpr T WrapAngle_0_2PI(T radAngle) noexcept 
        {
            return 
                radAngle - (
                    static_cast<T>(6.28318530717958647702561791881237241L) * // 2PI
                    std::floor(radAngle * static_cast<T>(0.15915494309189533576888376337251L)) // angle * (1/2PI)
                );
        }
        template<typename T>
        GLB_INLINE constexpr T WrapAngle_NPI_PI(T radAngle) noexcept 
        {
            return 
                radAngle - (
                    static_cast<T>(6.28318530717958647702561791881237241L) * // 2PI
                    std::floor((radAngle + static_cast<T>(3.141592653589793238462643383279502884L)) * // angle + PI
                    static_cast<T>(0.15915494309189533576888376337251L)) // 1/2PI
                );
        }

        template<typename T>
        GLB_INLINE constexpr T WrapDegAngle_0_360(T degAngle) noexcept 
        {
            return 
                degAngle - (
                    static_cast<T>(360) * 
                    std::floor(degAngle * static_cast<T>(0.00277777777777777777777777777778L))
                );
        }
        template<typename T>
        GLB_INLINE constexpr T WrapDegAngle_N180_180(T degAngle) noexcept 
        {
            return 
                degAngle - (
                    static_cast<T>(360) * 
                    std::floor((degAngle + static_cast<T>(180)) * 
                    static_cast<T>(0.00277777777777777777777777777778L))
                );
        }

        template<typename T>
        GLB_INLINE constexpr T LerpAngle(T start, T end, T t) noexcept
        {
            const T dist = std::fmod(end - start, static_cast<T>(6.28318530717958647702561791881237241L));
            const T shortDist = std::fmod(static_cast<T>(2) * dist, static_cast<T>(6.28318530717958647702561791881237241L)) - dist;
            
            return start + shortDist * t;
        }
    }
}