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

#include "../definitions.h"
#include "../type_quat.h"

namespace glb
{
    /**
     * DO NOT USE THIS TYPE, IT'S STILL IN DEVELOPMENT !!!
     */
    template<typename T>
    struct alignas(sizeof(T) * 4) glbDQuat_T
    {
    public:
        
        glbQuat_T<T> real, dual;
        

        GLB_INLINE constexpr glbDQuat_T() noexcept;
        GLB_INLINE constexpr glbDQuat_T(const glbDQuat_T<T>& dq) noexcept;
        GLB_INLINE constexpr glbDQuat_T(const glbQuat_T<T>& rot, const glbVec_T<3, T>& trsl) noexcept;
        GLB_INLINE constexpr glbDQuat_T(const glbQuat_T<T>& rot, const glbQuat_T<T>& trsl) noexcept;
        GLB_INLINE constexpr glbDQuat_T(const glbQuat_T<T>& rot) noexcept;
        GLB_INLINE constexpr glbDQuat_T(const glbVec_T<3, T>& trsl) noexcept;


        GLB_INLINE constexpr glbQuat_T<T>& operator[](int i);
        GLB_INLINE constexpr const glbQuat_T<T>& operator[](int i) const;

        GLB_INLINE constexpr glbDQuat_T<T>& operator=(const glbDQuat_T<T>& dq) = default;


        GLB_INLINE constexpr glbDQuat_T<T>& operator+=(const glbDQuat_T<T>& dq) noexcept;
        GLB_INLINE constexpr glbDQuat_T<T>& operator-=(const glbDQuat_T<T>& dq) noexcept;
        
        GLB_INLINE constexpr glbDQuat_T<T>& operator*=(const glbDQuat_T<T>& dq) noexcept;
        GLB_INLINE constexpr glbDQuat_T<T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr glbDQuat_T<T>& operator/=(T scalar) noexcept;
    };

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator+(const glbDQuat_T<T>& dq) noexcept;
    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator-(const glbDQuat_T<T>& dq) noexcept;

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator+(const glbDQuat_T<T>& a, const glbDQuat_T<T>& b) noexcept;
    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator-(const glbDQuat_T<T>& a, const glbDQuat_T<T>& b) noexcept;

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator*(const glbDQuat_T<T>& a, const glbDQuat_T<T>& b) noexcept;
    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator*(const glbDQuat_T<T>& dq, T scalar) noexcept;
    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator*(T scalar, const glbDQuat_T<T>& dq) noexcept;
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T> operator*(const glbDQuat_T<T>& dq, const glbVec_T<3, T>& point) noexcept;

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator/(const glbDQuat_T<T>& dq, T scalar) noexcept;


    template<typename T>
    GLB_INLINE constexpr bool operator==(const glbDQuat_T<T>& a, const glbDQuat_T<T>& b) noexcept;
    template<typename T>
    GLB_INLINE constexpr bool operator!=(const glbDQuat_T<T>& a, const glbDQuat_T<T>& b) noexcept;
} // namespace glb

#include "type_dualquat.inl"
