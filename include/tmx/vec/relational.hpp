#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vec
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> GreaterThan(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> GreaterThanOrEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> LessThan(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> LessThanOrEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> Equal(const vec<S, T>& a, const vec<S, T>& b) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, bool> NotEqual(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S>
        TMX_INLINE constexpr bool Any(const vec<S, bool>& v) noexcept;
        template<size_t S>
        TMX_INLINE constexpr bool All(const vec<S, bool>& v) noexcept;

    } // namespace Vector
} // namespace tmx

#include "tmx/internal/vec/compute_relational.inl"