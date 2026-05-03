#pragma once

#include "tmx/internal/definitions.hpp"

namespace tmx
{
    namespace Math
    {
        template<typename T = Real>
        TMX_INLINE constexpr T Min(T a, T b) noexcept;
        template<typename T = Real>
        TMX_INLINE constexpr T Max(T a, T b) noexcept;


        template<typename T = Real>
        TMX_INLINE constexpr T Clamp(T val, T max, T min) noexcept;
        template<typename T = Real>
        TMX_INLINE constexpr T Clamp01(T val) noexcept;
        template<typename T = Real>
        TMX_INLINE constexpr T Saturate(T val) noexcept;


        template<typename T = Real>
        TMX_INLINE constexpr T Sign(T val) noexcept;


        template<typename T = Real>
        TMX_INLINE constexpr T Abs(T val) noexcept;


        template<typename T = Real>
        TMX_INLINE constexpr T Round(T val) noexcept;
        template<typename T = Real>
        TMX_INLINE constexpr T Floor(T val) noexcept;
        template<typename T = Real>
        TMX_INLINE constexpr T Ceil(T val) noexcept;
        template<typename T = Real>
        TMX_INLINE constexpr T Trunc(T val) noexcept;
        template<typename T = Real>
        TMX_INLINE constexpr T Fract(T val) noexcept;


        template<typename T = Real>
        TMX_INLINE constexpr T Mod(T val, T modulus) noexcept;

    } // namespace Math
} // namespace tmx

#include "tmx/internal/math/compute_common.inl"
