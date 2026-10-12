#pragma once
#include "definitions.h"

namespace glb
{
    // -- Unary operators ---

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator+(const glbVec_T<S, T>& v) noexcept; 
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator-(const glbVec_T<S, T>& v) noexcept; 

    // --- Arithmetic (binary) operators ---
    
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator+(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator+(const glbVec_T<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator+(T scalar, const glbVec_T<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator-(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator-(const glbVec_T<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator-(T scalar, const glbVec_T<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator*(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator*(const glbVec_T<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator*(T scalar, const glbVec_T<S, T>& v) noexcept;

    /// @brief DO NOT DIVIDE BY ZERO IF T IS AN INTEGRAL TYPE !!!
    /// @tparam T 
    /// @tparam S 
    /// @param a 
    /// @param b 
    /// @return 
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator/(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator/(const glbVec_T<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator/(T scalar, const glbVec_T<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator%(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator%(const glbVec_T<S, T>& v, T scalar) noexcept;

    // --- Bitwise operators

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator&(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator&(const glbVec_T<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator&(T scalar, const glbVec_T<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator|(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator|(const glbVec_T<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator|(T scalar, const glbVec_T<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator^(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator^(const glbVec_T<S, T>& v, T scalar) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator^(T scalar, const glbVec_T<S, T>& v) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator<<(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator<<(const glbVec_T<S, T>& v, T scalar) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator>>(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator>>(const glbVec_T<S, T>& v, T scalar) noexcept;


    template<int S, typename T>
    GLB_INLINE constexpr bool operator==(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr bool operator!=(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;

    template<int S, typename T>
    GLB_INLINE constexpr bool operator<(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr bool operator<=(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr bool operator>(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
    template<int S, typename T>
    GLB_INLINE constexpr bool operator>=(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;

    // --- Unary Bitwise operators

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator~(const glbVec_T<S, T>& v) noexcept;



    
}

#include "type_vec.inl"