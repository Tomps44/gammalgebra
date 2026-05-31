#pragma once

#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace tmxDetail
    {
        template<typename T>
        TMX_INLINE constexpr vec<3, T> unitX = vec<3, T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
    
        template<typename T>
        TMX_INLINE constexpr vec<3, T> unitY = vec<3, T>(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
    
        template<typename T>
        TMX_INLINE constexpr vec<3, T> unitZ = vec<3, T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));

        template<typename T>
        TMX_INLINE constexpr vec<3, T> zero = vec<3, T>();

        template<typename T>
        TMX_INLINE constexpr vec<3, T> one = vec<3, T>(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));
        
    
    } // namespace tmxDetail


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


        template<int S>
        TMX_INLINE constexpr vec<S, int32_t> ToVecInt(const vec<S, float>& v)
        {
            return Vec::CastTo<float, int32_t>(v);
        }
        template<int S>
        TMX_INLINE constexpr vec<S, int64_t> ToVecInt(const vec<S, double>& v)
        {
            return Vec::CastTo<double, int64_t>(v);
        }



        template<int S, typename T>
        TMX_INLINE constexpr vec<2, T> ToVec2(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<2, T>>(v);
        }
        template<int S, typename T>
        TMX_INLINE constexpr vec<3, T> ToVec3(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<3, T>>(v);
        }
        template<int S, typename T>
        TMX_INLINE constexpr vec<4, T> ToVec4(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<4, T>>(v);
        }



        template<int S, typename T>
        TMX_INLINE constexpr vec<2, T> XY(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<2, T>>(v);
        }
        template<int S, typename T>
        TMX_INLINE constexpr vec<3, T> XYZ(const vec<S, T>& v) noexcept
        {
            return static_cast<vec<3, T>>(v);
        }


        template<int S, typename T>
        TMX_INLINE constexpr vec<S, T> SplatX(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.x);
        }
        template<int S, typename T>
        TMX_INLINE constexpr vec<S, T> SplatY(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.y);
        }
        template<int S, typename T>
        TMX_INLINE constexpr vec<S, T> SplatZ(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.z);
        }
        template<int S, typename T>
        TMX_INLINE constexpr vec<S, T> SplatW(const vec<S, T>& v) noexcept
        {
            return vec<S, T>(v.w);
        }



        TMX_INLINE constexpr vec<3, float> UnitX = tmxDetail::unitX<float>;
        TMX_INLINE constexpr vec<3, float> UnitY = tmxDetail::unitY<float>;
        TMX_INLINE constexpr vec<3, float> UnitZ = tmxDetail::unitZ<float>;
        TMX_INLINE constexpr vec<3, float> Zero = tmxDetail::zero<float>;
        TMX_INLINE constexpr vec<3, float> One = tmxDetail::one<float>;
        
        TMX_INLINE constexpr vec<3, int32_t> UnitXInt = tmxDetail::unitX<int32_t>;
        TMX_INLINE constexpr vec<3, int32_t> UnitYInt = tmxDetail::unitY<int32_t>;
        TMX_INLINE constexpr vec<3, int32_t> UnitZInt = tmxDetail::unitZ<int32_t>;
        TMX_INLINE constexpr vec<3, int32_t> ZeroInt = tmxDetail::zero<int32_t>;
        TMX_INLINE constexpr vec<3, int32_t> OneInt = tmxDetail::one<int32_t>;

    }

    
}