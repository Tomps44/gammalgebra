#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vec
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Pow(const vec<S, T>& v, const vec<S, T>& exponent) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Pow(const vec<S, T>& v, T exponent) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Sqrt(const vec<S, T>& v) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> InvSqrt(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Exp(const vec<S, T>& v) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Exp2(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Log(const vec<S, T>& v) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Log2(const vec<S, T>& v) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Log10(const vec<S, T>& v) noexcept;
    }
}

#include "tmx/internal/vec/compute_exponential.inl"