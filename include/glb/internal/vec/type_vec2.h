#pragma once

#include "../definitions.h"
#include "../type_vec.h"

namespace glb
{
    template<typename T>
    struct alignas(sizeof(T) * 4) glbVec_T<2, T>
    {
        union 
        {
            struct { T x, y; };
            struct { T r, g; };
            struct { T s, t; };
            T values[2];
        };

        GLB_INLINE explicit constexpr glbVec_T(T x, T y) noexcept;
        GLB_INLINE explicit constexpr glbVec_T(T scalar = static_cast<T>(0.0)) noexcept; 
        GLB_INLINE constexpr glbVec_T(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE explicit constexpr glbVec_T(const glbVec_T<3, T>& v) noexcept;
        GLB_INLINE explicit constexpr glbVec_T(const glbVec_T<4, T>& v) noexcept;


        GLB_INLINE constexpr const T* data() const noexcept { return &x; };


        GLB_INLINE constexpr T& operator[](int index);
        GLB_INLINE constexpr const T& operator[](int index) const;


        GLB_INLINE constexpr explicit operator glbVec_T<3, T>() const noexcept { return glbVec_T<3, T>(*this); };
        GLB_INLINE constexpr explicit operator glbVec_T<4, T>() const noexcept { return glbVec_T<4, T>(*this); };


        GLB_INLINE constexpr glbVec_T<2, T>& operator=(const glbVec_T<2, T>& v) noexcept = default;


        GLB_INLINE constexpr glbVec_T<2, T>& operator+=(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<2, T>& operator+=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<2, T>& operator-=(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<2, T>& operator-=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<2, T>& operator*=(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<2, T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<2, T>& operator/=(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<2, T>& operator/=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<2, T>& operator%=(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<2, T>& operator%=(T scalar) noexcept;


        GLB_INLINE constexpr glbVec_T<2, T>& operator&=(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<2, T>& operator&=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<2, T>& operator|=(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<2, T>& operator|=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<2, T>& operator^=(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<2, T>& operator^=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<2, T>& operator<<=(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<2, T>& operator<<=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<2, T>& operator>>=(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<2, T>& operator>>=(T scalar) noexcept;
    };
}

#include "type_vec2.inl"