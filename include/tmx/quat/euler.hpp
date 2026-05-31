#pragma once

#include "tmx/internal/type_quat.hpp"
#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    
    namespace Qua
    {
        /// @brief Generates a Quaternion from an axis and an angle 
        /// @param u A unit Vector3 deciding the axis to rotate around : `(1, 0, 0)` for `X`, `(0, 1, 0)` for `Y`, `(0, 0, 1)` for `Z`
        /// @param angle The angle to rotate by, `IN RADIANS`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromAxisAngle(const vec<3, T>& u, T angle) noexcept;


        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler(T x, T y, T z) noexcept;
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler(const vec<3, T>& angles) noexcept;
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler(const quat<T>& q) noexcept;
    }

    namespace tmxDetail
    {
        /// @brief Generates a Quaternion from three angles. His rotation order is XYZ.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_XYZ(T x, T y, T z) noexcept;

        /// @brief Generates a Quaternion from three angles. His rotation order is XZY.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_XZY(T x, T y, T z) noexcept;

        /// @brief Generates a Quaternion from three angles. His rotation order is YXZ.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_YXZ(T x, T y, T z) noexcept;

        /// @brief Generates a Quaternion from three angles. His rotation order is YZX.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_YZX(T x, T y, T z) noexcept;

        /// @brief Generates a Quaternion from three angles. His rotation order is ZXY.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_ZXY(T x, T y, T z) noexcept;

        /// @brief Generates a Quaternion from three angles. His rotation order is ZYX.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_ZYX(T x, T y, T z) noexcept;



        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `XYZ`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_XYZ(const quat<T>& q) noexcept;

        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `XZY`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_XZY(const quat<T>& q) noexcept;

        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `YXZ`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_YXZ(const quat<T>& q) noexcept;

        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `YZX`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_YZX(const quat<T>& q) noexcept;

        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `ZXY`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_ZXY(const quat<T>& q) noexcept;
        
        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `ZYX`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_ZYX(const quat<T>& q) noexcept;

    } // namespace Detail

} // namespace tmx

#include "tmx/internal/quat/compute_euler.inl"