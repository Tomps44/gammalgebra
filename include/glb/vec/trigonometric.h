#pragma once

#include "../internal/type_vec.h"

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> ToRad(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> ToDeg(const glbVec_T<S, T>& v) noexcept;


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Sin(const glbVec_T<S, T>& v) noexcept;
    
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Cos(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Tan(const glbVec_T<S, T>& v) noexcept;

    
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Asin(const glbVec_T<S, T>& v) noexcept;
        
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Acos(const glbVec_T<S, T>& v) noexcept;
    
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Atan(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Atan2(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Sinh(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Cosh(const glbVec_T<S, T>& v) noexcept;
    
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Tanh(const glbVec_T<S, T>& v) noexcept;


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Asinh(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Acosh(const glbVec_T<S, T>& v) noexcept;
    
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Atanh(const glbVec_T<S, T>& v) noexcept;
        
    
    } // namespace Vec
}

#include "../internal/vec/compute_trigonometric.inl"