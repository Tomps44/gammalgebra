#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vec
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> ToRad(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> ToDeg(const vec<S, T>& v) noexcept;


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Sin(const vec<S, T>& v) noexcept;
    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Cos(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Tan(const vec<S, T>& v) noexcept;

    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Asin(const vec<S, T>& v) noexcept;
        
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Acos(const vec<S, T>& v) noexcept;
    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Atan(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Atan2(const vec<S, T>& a, const vec<S, T>& b) noexcept;


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Sinh(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Cosh(const vec<S, T>& v) noexcept;
    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Tanh(const vec<S, T>& v) noexcept;


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Asinh(const vec<S, T>& v) noexcept;

        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Acosh(const vec<S, T>& v) noexcept;
    
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Atanh(const vec<S, T>& v) noexcept;
        
    
    } // namespace Vec
}

#include "tmx/internal/vec/compute_trigonometric.inl"