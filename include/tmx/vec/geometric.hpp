#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vec
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr T Dot(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr T Length(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr T LengthSquared(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr T Distance(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr T DistanceSquared(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Cross(const vec<S, T>& a, const vec<S, T>& b) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Normalize(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> FaceForward(const vec<S, T>& N, const vec<S, T>& I, const vec<S, T>& Nref) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Reflect(const vec<S, T>& I, const vec<S, T>& N) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Refract(const vec<S, T>& I, const vec<S, T>& N, T eta) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Project(const vec<S, T>& proj, const vec<S, T>& base) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> ClampMagnitude(const vec<S, T>& v, T maxLength) noexcept;
        
    } // namespace Vector
}

#include "tmx/internal/vec/compute_geometric.inl"