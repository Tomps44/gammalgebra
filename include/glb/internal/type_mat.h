#pragma once
#include "definitions.h"

namespace glb
{
    // -- Unary operators ---

    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator+(const glbMat_T<R, C, T>& v) noexcept; 
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator-(const glbMat_T<R, C, T>& v) noexcept; 

    // --- Arithmetic operators ---
    
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator+(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b) noexcept;
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator+(const glbMat_T<R, C, T>& v, T scalar) noexcept;

    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator-(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b) noexcept;
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator-(const glbMat_T<R, C, T>& v, T scalar) noexcept;

    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator*(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b) noexcept;
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator*(const glbMat_T<R, C, T>& v, T scalar) noexcept;
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator*(T scalar, const glbMat_T<R, C, T>& v) noexcept;

    template<int R, int C, typename T>
    GLB_INLINE constexpr typename glbMat_T<R, C, T>::colType operator*(const glbMat_T<R, C, T>& m, const typename glbMat_T<R, C, T>::colType& v) noexcept;

    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator/(const glbMat_T<R, C, T>& v, T scalar) noexcept;

   


    template<int R, int C, typename T>
    GLB_INLINE constexpr bool operator==(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b) noexcept;
    template<int R, int C, typename T>
    GLB_INLINE constexpr bool operator!=(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b) noexcept;
}

#include "type_mat.inl"