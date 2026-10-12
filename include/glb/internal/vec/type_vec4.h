#pragma once

#include "../definitions.h"
#include "../type_vec.h"

namespace glb
{
    template<typename T>
    struct alignas(sizeof(T) * 4) glbVec_T<4, T>
    {
        union 
        {
            struct { T x, y, z, w; };
            struct { T r, g, b, a; };
            struct { T s, t, p, q; };
            T values[4];
            typename glbIntern::simdReg<4, T>::type reg;
        };

        GLB_INLINE explicit constexpr glbVec_T(T x, T y, T z, T w = static_cast<T>(0.0)) noexcept;
        GLB_INLINE explicit constexpr glbVec_T(T scalar = static_cast<T>(0.0)) noexcept; 
        GLB_INLINE explicit constexpr glbVec_T(const glbVec_T<3, T>& xyy, T vw = static_cast<T>(0.0)) noexcept;
        GLB_INLINE explicit constexpr glbVec_T(const glbVec_T<2, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T(const glbVec_T<4, T>& v) noexcept;


        GLB_INLINE constexpr const T* data() const noexcept { return &x; };


        GLB_INLINE constexpr T& operator[](int index);
        GLB_INLINE constexpr const T& operator[](int index) const;

        GLB_INLINE constexpr explicit operator glbVec_T<2, T>() const noexcept { return glbVec_T<2, T>(*this); };
        GLB_INLINE constexpr explicit operator glbVec_T<3, T>() const noexcept { return glbVec_T<3, T>(*this); };

        GLB_INLINE constexpr glbVec_T<4, T>& operator=(const glbVec_T<4, T>& v) noexcept = default;


        GLB_INLINE constexpr glbVec_T<4, T>& operator+=(const glbVec_T<4, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<4, T>& operator+=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<4, T>& operator-=(const glbVec_T<4, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<4, T>& operator-=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<4, T>& operator*=(const glbVec_T<4, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<4, T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<4, T>& operator/=(const glbVec_T<4, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<4, T>& operator/=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<4, T>& operator%=(const glbVec_T<4, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<4, T>& operator%=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<4, T>& operator&=(const glbVec_T<4, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<4, T>& operator&=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<4, T>& operator|=(const glbVec_T<4, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<4, T>& operator|=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<4, T>& operator^=(const glbVec_T<4, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<4, T>& operator^=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<4, T>& operator<<=(const glbVec_T<4, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<4, T>& operator<<=(T scalar) noexcept;

        GLB_INLINE constexpr glbVec_T<4, T>& operator>>=(const glbVec_T<4, T>& v) noexcept;
        GLB_INLINE constexpr glbVec_T<4, T>& operator>>=(T scalar) noexcept;
    };
}

#include "type_vec4.inl"
