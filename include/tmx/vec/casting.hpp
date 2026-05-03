#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Vec
    {
        template<typename From, typename To>
        TMX_INLINE constexpr vec<2, To> CastTo(const vec<2, From>& v) 
        {
            return vec<2, To>(
                static_cast<To>(v.x),
                static_cast<To>(v.y)
            );
        }
        template<typename From, typename To>
        TMX_INLINE constexpr vec<3, To> CastTo(const vec<3, From>& v) 
        {
            return vec<3, To>(
                static_cast<To>(v.x),
                static_cast<To>(v.y),
                static_cast<To>(v.z)
            );
        }
        template<typename From, typename To>
        TMX_INLINE constexpr vec<4, To> CastTo(const vec<4, From>& v) 
        {
            return vec<4, To>(
                static_cast<To>(v.x),
                static_cast<To>(v.y),
                static_cast<To>(v.z),
                static_cast<To>(v.w)
            );
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<2, T> ToVec2(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<2, T>>(v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<3, T> ToVec3(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<3, T>>(v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<4, T> ToVec4(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<4, T>>(v);
        }



        template<size_t S, typename T>
        TMX_INLINE constexpr vec<2, T> Xy(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<2, T>>(v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<3, T> Xyz(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<3, T>>(v);
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> SplatX(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.x);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> SplatY(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.y);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> SplatZ(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.z);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> SplatW(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.w);
        }
    }
}