#pragma once

#include "tmx/internal/definitions.hpp"

namespace tmx
{
    template<typename T>
    struct quat
    {
    public:
        
        union 
        {
            struct { T w, x, y, z; };
            T values[4];
            typename internal::simdReg<4, T>::type reg;
        };


        TMX_INLINE constexpr quat(T qw, T qx, T qy, T qz) noexcept;
        TMX_INLINE constexpr quat(T qw, const vec<3, T>& xyz) noexcept;
        TMX_INLINE constexpr quat(const quat<T>& q) noexcept;
        TMX_INLINE constexpr quat() noexcept;


        TMX_INLINE constexpr T& operator[](size_t i);
        TMX_INLINE constexpr const T operator[](size_t i) const;

        TMX_INLINE constexpr const vec<3, T>& xyz() const { return vec<3, T>(x, y, z); };

        TMX_INLINE constexpr quat<T>& operator=(const quat<T>& q) noexcept = default;


        
        TMX_INLINE constexpr quat<T>& operator+=(const quat<T>& q) noexcept;
        TMX_INLINE constexpr quat<T>& operator-=(const quat<T>& q) noexcept;

        TMX_INLINE constexpr quat<T>& operator*=(T scalar) noexcept;
        TMX_INLINE constexpr quat<T>& operator*=(const quat<T>& q) noexcept;

        TMX_INLINE constexpr quat<T>& operator/=(T scalar) noexcept;
        
    };

    template<typename T>
    TMX_INLINE constexpr quat<T> operator+(const quat<T>& q) noexcept;
    template<typename T>
    TMX_INLINE constexpr quat<T> operator-(const quat<T>& q) noexcept;


    template<typename T>
    TMX_INLINE constexpr quat<T> operator+(const quat<T>& a, const quat<T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr quat<T> operator-(const quat<T>& a, const quat<T>& b) noexcept;

    template<typename T>
    TMX_INLINE constexpr quat<T> operator*(const quat<T>& a, const quat<T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr quat<T> operator*(const quat<T>& a, T scalar) noexcept;
    template<typename T>
    TMX_INLINE constexpr quat<T> operator*(T scalar, const quat<T>& a) noexcept;
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator*(const quat<T>& q, const vec<3, T>& v) noexcept;

    template<typename T>
    TMX_INLINE constexpr quat<T> operator/(const quat<T>& q, T scalar) noexcept;
    template<typename T>
    TMX_INLINE constexpr quat<T> operator/(T scalar, const quat<T>& q) noexcept;


    template<typename T>
    TMX_INLINE constexpr bool operator==(const quat<T>& a, const quat<T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr bool operator!=(const quat<T>& a, const quat<T>& b) noexcept;
}

#include "tmx/internal/type_quat.inl"