#pragma once

#include "../internal/definitions.h"

namespace glb
{
    namespace Math
    {
        template<typename T>
        GLB_INLINE constexpr T Pow(T val, T exponent) noexcept;


        template<typename T>
        GLB_INLINE constexpr T Sqrt(T val) noexcept;
        // Returns the `Cubic Root` of `val`
        template<typename T>
        GLB_INLINE constexpr T Cbrt(T val) noexcept;
        template<typename T>
        GLB_INLINE constexpr T InvSqrt(T val) noexcept;
        GLB_INLINE float FastInvSqrt(float val) noexcept;

        /// @brief Returns `e`, euler's number, raised to the power `exponent`
        template<typename T>
        GLB_INLINE constexpr T Exp(T exponent) noexcept;
        /// @brief Returns `2` raised to the power `exponent`
        template<typename T>
        GLB_INLINE constexpr T Exp2(T exponent) noexcept;
        // Returns the `Natural Logarithm` of `val`
        template<typename T>
        GLB_INLINE constexpr T Log(T val) noexcept;
        template<typename T>
        GLB_INLINE constexpr T Log2(T val) noexcept;
        template<typename T>
        GLB_INLINE constexpr T Log10(T val) noexcept;

        
        GLB_INLINE constexpr bool IsPowerOfTwo(int8_t val) noexcept;
        GLB_INLINE constexpr bool IsPowerOfTwo(int16_t val) noexcept;
        GLB_INLINE constexpr bool IsPowerOfTwo(int32_t val) noexcept;
        GLB_INLINE constexpr bool IsPowerOfTwo(int64_t val) noexcept;
        
        GLB_INLINE constexpr uint8_t NextPowerOfTwo(uint8_t val) noexcept;
        GLB_INLINE constexpr uint16_t NextPowerOfTwo(uint16_t val) noexcept;
        GLB_INLINE constexpr uint32_t NextPowerOfTwo(uint32_t val) noexcept;
        GLB_INLINE constexpr uint64_t NextPowerOfTwo(uint64_t val) noexcept;

    } // namespace Math
} // namespace glb

#include "../internal/math/compute_exponential.inl"
