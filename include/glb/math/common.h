#pragma once

#include "../internal/definitions.h"
#include <concepts>

namespace glb
{
    namespace Math
    {
        template<typename T>
        GLB_INLINE constexpr T Min(T a, T b) noexcept;
        template<typename T>
        GLB_INLINE constexpr T Max(T a, T b) noexcept;


        template<typename T>
        GLB_INLINE constexpr T Clamp(T val, T max, T min) noexcept;
        template<typename T>
        GLB_INLINE constexpr T Clamp01(T val) noexcept;
        template<typename T>
        GLB_INLINE constexpr T Saturate(T val) noexcept;


        template<typename T>
        GLB_INLINE constexpr T Sign(T val) noexcept;


        template<typename T>
        GLB_INLINE constexpr T Abs(T val) noexcept;


        template<typename T>
        GLB_INLINE constexpr T Round(T val) noexcept;
        template<typename T>
        GLB_INLINE constexpr T Floor(T val) noexcept;
        template<typename T>
        GLB_INLINE constexpr T Ceil(T val) noexcept;
        template<typename T>
        GLB_INLINE constexpr T Trunc(T val) noexcept;
        template<typename T>
        GLB_INLINE constexpr T Fract(T val) noexcept;

        GLB_INLINE constexpr int32_t RoundToInt(float val) noexcept;
        GLB_INLINE constexpr int32_t FloorToInt(float val) noexcept;
        GLB_INLINE constexpr int32_t CeilToInt(float val) noexcept;
        GLB_INLINE constexpr int32_t TruncToInt(float val) noexcept;


        template<typename T>
        GLB_INLINE constexpr T Mod(T val, T modulus) noexcept;


        template<typename T>
        GLB_INLINE constexpr T Repeat(T val, T max) noexcept;
        template<typename T>
        GLB_INLINE constexpr T PingPong(T val, T max) noexcept;


        template<typename T>
        GLB_INLINE constexpr bool ApproxEqual(T a, T b) noexcept;
        template<typename T>
        GLB_INLINE constexpr bool ApproxZero(T val) noexcept;


        template<typename T>
        GLB_INLINE constexpr bool IsNan(T val) noexcept;
        template<typename T>
        GLB_INLINE constexpr bool IsInf(T val) noexcept;


    } // namespace Math
} // namespace glb

#include "../internal/math/compute_common.inl"
