#pragma once

#include "../internal/type_vec.h"

namespace glb
{
    namespace glbDetail
    {
        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> unitX_T = glbVec_T<3, T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
    
        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> unitY_T = glbVec_T<3, T>(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
    
        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> unitZ_T = glbVec_T<3, T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));

        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> zero_T = glbVec_T<3, T>();

        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> one_T = glbVec_T<3, T>(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));
        
    
    } // namespace glbDetail


    namespace Vec
    {
        template<typename From, typename To>
        GLB_INLINE constexpr glbVec_T<2, To> CastTo(const glbVec_T<2, From>& v) 
        {
            return glbVec_T<2, To>(
                static_cast<To>(v.x),
                static_cast<To>(v.y)
            );
        }
        template<typename From, typename To>
        GLB_INLINE constexpr glbVec_T<3, To> CastTo(const glbVec_T<3, From>& v) 
        {
            return glbVec_T<3, To>(
                static_cast<To>(v.x),
                static_cast<To>(v.y),
                static_cast<To>(v.z)
            );
        }
        template<typename From, typename To>
        GLB_INLINE constexpr glbVec_T<4, To> CastTo(const glbVec_T<4, From>& v) 
        {
            return glbVec_T<4, To>(
                static_cast<To>(v.x),
                static_cast<To>(v.y),
                static_cast<To>(v.z),
                static_cast<To>(v.w)
            );
        }


        template<int S>
        GLB_INLINE constexpr glbVec_T<S, int32_t> ToVecInt(const glbVec_T<S, float>& v)
        {
            return Vec::CastTo<float, int32_t>(v);
        }
        template<int S>
        GLB_INLINE constexpr glbVec_T<S, int64_t> ToVecInt(const glbVec_T<S, double>& v)
        {
            return Vec::CastTo<double, int64_t>(v);
        }



        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<2, T> ToVec2(const glbVec_T<S, T>& v) noexcept
        {
            return static_cast<glbVec_T<2, T>>(v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<3, T> ToVec3(const glbVec_T<S, T>& v) noexcept
        {
            return static_cast<glbVec_T<3, T>>(v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<4, T> ToVec4(const glbVec_T<S, T>& v) noexcept
        {
            return static_cast<glbVec_T<4, T>>(v);
        }



        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<2, T> XY(const glbVec_T<S, T>& v) noexcept
        {
            return static_cast<glbVec_T<2, T>>(v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<3, T> XYZ(const glbVec_T<S, T>& v) noexcept
        {
            return static_cast<glbVec_T<3, T>>(v);
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> SplatX(const glbVec_T<S, T>& v) noexcept
        {
            return glbVec_T<S, T>(v.x);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> SplatY(const glbVec_T<S, T>& v) noexcept
        {
            return glbVec_T<S, T>(v.y);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> SplatZ(const glbVec_T<S, T>& v) noexcept
        {
            return glbVec_T<S, T>(v.z);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> SplatW(const glbVec_T<S, T>& v) noexcept
        {
            return glbVec_T<S, T>(v.w);
        }



        GLB_INLINE constexpr glbVec_T<3, float> UnitX = glbDetail::unitX_T<float>;
        GLB_INLINE constexpr glbVec_T<3, float> UnitY = glbDetail::unitY_T<float>;
        GLB_INLINE constexpr glbVec_T<3, float> UnitZ = glbDetail::unitZ_T<float>;
        GLB_INLINE constexpr glbVec_T<3, float> Zero = glbDetail::zero_T<float>;
        GLB_INLINE constexpr glbVec_T<3, float> One = glbDetail::one_T<float>;
        
        GLB_INLINE constexpr glbVec_T<3, int32_t> UnitXi = glbDetail::unitX_T<int32_t>;
        GLB_INLINE constexpr glbVec_T<3, int32_t> UnitYi = glbDetail::unitY_T<int32_t>;
        GLB_INLINE constexpr glbVec_T<3, int32_t> UnitZi = glbDetail::unitZ_T<int32_t>;
        GLB_INLINE constexpr glbVec_T<3, int32_t> Zero_i = glbDetail::zero_T<int32_t>;
        GLB_INLINE constexpr glbVec_T<3, int32_t> One_i = glbDetail::one_T<int32_t>;
    }
}