#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vec
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> LerpUnclamped(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Lerp(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> SlerpUnclamped(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Slerp(const vec<S, T>& s, const vec<S, T>& e, T t) noexcept;

        
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> SmoothDamp(const vec<S, T>& current, const vec<S, T>& target, vec<S, T>& currentVelocity,
                                                  T smoothTime, T deltaTime, T maxSpeed = std::numeric_limits<T>::infinity()) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> MoveTowards(const vec<S, T>& current, const vec<S, T>& target, T maxDistanceDelta) noexcept;

    } // namespace Vec
} // namespace tmx

#include "tmx/internal/vec/compute_interpolation.inl"
