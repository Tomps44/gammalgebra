#pragma once

#include "../internal/type_mat.h"
#include "../vec/util.h"

namespace glb
{
    namespace Vec
    {
        template<typename From, typename To>
        GLB_INLINE constexpr glbMat_T<2, 2, To> CastTo(const glbMat_T<2, 2, From>& m) 
        {
            return glbMat_T<2, 2, To>(
                Vec::CastTo<From, To>(m[0]),
                Vec::CastTo<From, To>(m[1]);
            )
        }
        template<typename From, typename To>
        GLB_INLINE constexpr glbMat_T<3, 3, To> CastTo(const glbMat_T<3, 3, From>& m) 
        {
            return glbMat_T<3, 3, To>(
                Vec::CastTo<From, To>(m[0]),
                Vec::CastTo<From, To>(m[1]),
                Vec::CastTo<From, To>(m[2]);
            )
        }
        template<typename From, typename To>
        GLB_INLINE constexpr glbMat_T<4, 4, To> CastTo(const glbMat_T<4, 4, From>& m) 
        {
            return glbMat_T<4, 4, To>(
                Vec::CastTo<From, To>(m[0]),
                Vec::CastTo<From, To>(m[1]),
                Vec::CastTo<From, To>(m[2]),
                Vec::CastTo<From, To>(m[3]);
            )
        }



        template<int R, int C, typename T>
        GLB_INLINE constexpr glbMat_T<2, 2, T> ToMat2x2(const glbMat_T<R, C, T>& m) noexcept
        {
            return static_cast<glbMat_T<2, 2, T>>(m);
        }
        template<int R, int C, typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> ToMat3x3(const glbMat_T<R, C, T>& m) noexcept
        {
            return static_cast<glbMat_T<3, 3, T>>(m);
        }
        template<int R, int C, typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> ToMat4x4(const glbMat_T<R, C, T>& m) noexcept
        {
            return static_cast<glbMat_T<4, 4, T>>(m);
        }

    }

    
}