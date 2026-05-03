#pragma once

#include "tmx/internal/definitions.hpp"

namespace tmx
{
    namespace Math
    {
        template<typename T>
        TMX_INLINE constexpr T Pow(T val, T exponent) noexcept;


        template<typename T>
        TMX_INLINE constexpr T Sqrt(T val) noexcept;
        // Returns the `Cubic Root` of `val`
        template<typename T>
        TMX_INLINE constexpr T Cbrt(T val) noexcept;
        template<typename T>
        TMX_INLINE constexpr T InvSqrt(T val) noexcept;

        /// @brief Returns `e`, euler's number, raised to the power `exponent`
        template<typename T>
        TMX_INLINE constexpr T Exp(T exponent) noexcept;
        /// @brief Returns `2` raised to the power `exponent`
        template<typename T>
        TMX_INLINE constexpr T Exp2(T exponent) noexcept;
        // Returns the `Natural Logarithm` of `val`
        template<typename T>
        TMX_INLINE constexpr T Log(T val) noexcept;
        template<typename T>
        TMX_INLINE constexpr T Log2(T val) noexcept;
        template<typename T>
        TMX_INLINE constexpr T Log10(T val) noexcept;
        

    } // namespace Math
} // namespace tmx

#include "tmx/internal/math/compute_exponential.inl"
