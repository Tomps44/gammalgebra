/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */




#pragma once

#include "tmx/internal/definitions.hpp"
#include "tmx/internal/type_quat.hpp"

namespace tmx
{
    template<typename T>
    struct dQuat
    {
    public:
        
        quat<T> real, dual;
        

        TMX_INLINE constexpr dQuat() noexcept;
        TMX_INLINE constexpr dQuat(const dQuat<T>& dq) noexcept;
        TMX_INLINE constexpr dQuat(const quat<T>& rot, const vec<3, T>& trsl) noexcept;
        TMX_INLINE constexpr dQuat(const quat<T>& rot, const quat<T>& trsl) noexcept;
        TMX_INLINE constexpr dQuat(const quat<T>& rot) noexcept;
        TMX_INLINE constexpr dQuat(const vec<3, T>& trsl) noexcept;


        TMX_INLINE constexpr quat<T>& operator[](size_t i);
        TMX_INLINE constexpr const quat<T>& operator[](size_t i) const;

        TMX_INLINE constexpr dQuat<T>& operator=(const dQuat<T>& dq) = default;


        TMX_INLINE constexpr dQuat<T>& operator+=(const dQuat<T>& dq) noexcept;
        TMX_INLINE constexpr dQuat<T>& operator-=(const dQuat<T>& dq) noexcept;
        
        TMX_INLINE constexpr dQuat<T>& operator*=(const dQuat<T>& dq) noexcept;
        TMX_INLINE constexpr dQuat<T>& operator*=(T scalar) noexcept;

        TMX_INLINE constexpr dQuat<T>& operator/=(T scalar) noexcept;
    };

    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator+(const dQuat<T>& dq) noexcept;
    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator-(const dQuat<T>& dq) noexcept;

    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator+(const dQuat<T>& a, const dQuat<T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator-(const dQuat<T>& a, const dQuat<T>& b) noexcept;

    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator*(const dQuat<T>& a, const dQuat<T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator*(const dQuat<T>& dq, T scalar) noexcept;
    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator*(T scalar, const dQuat<T>& dq) noexcept;
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator*(const dQuat<T>& dq, const vec<3, T>& point) noexcept;

    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator/(const dQuat<T>& dq, T scalar) noexcept;


    template<typename T>
    TMX_INLINE constexpr bool operator==(const dQuat<T>& a, const dQuat<T>& b) noexcept;
    template<typename T>
    TMX_INLINE constexpr bool operator!=(const dQuat<T>& a, const dQuat<T>& b) noexcept;
} // namespace tmx

#include "tmx/internal/type_dualquat.inl"
