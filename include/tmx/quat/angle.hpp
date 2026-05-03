#pragma once

#include "tmx/internal/type_quat.hpp"
#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    enum class RotationOrder
    {
        XYZ, 
        XZY,
        YXZ,
        YZX,
        ZXY,
        ZYX
    };
    enum class RotationMode
    {
        Intrinsic,
        Extrinsic
    };

    namespace Qua
    {
        /// @brief Generates a Quaternion from an axis and an angle 
        /// @param u A unit Vector3 deciding the axis to rotate around : `(1, 0, 0)` for `X`, `(0, 1, 0)` for `Y`, `(0, 0, 1)` for `Z`
        /// @param angle The angle to rotate by, `IN RADIANS`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromAxisAngle(const vec<3, T>& u, T angle) noexcept;


        template<typename T, RotationOrder rotOrder = RotationOrder::YXZ, RotationMode rotMode = RotationMode::Intrinsic>
        TMX_INLINE constexpr quat<T> FromEuler(T x, T y, T z) noexcept;
        template<typename T, RotationOrder rotOrder = RotationOrder::YXZ, RotationMode rotMode = RotationMode::Intrinsic>
        TMX_INLINE constexpr vec<3, T> ToEuler(const quat<T>& q) noexcept;


        /// @brief Generates a Quaternion from three angles. His rotation order is XYZ.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEulerXYZ(T x, T y, T z) noexcept;

        /// @brief Generates a Quaternion from three angles. His rotation order is XZY.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEulerXZY(T x, T y, T z) noexcept;

        /// @brief Generates a Quaternion from three angles. His rotation order is YXZ.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEulerYXZ(T x, T y, T z) noexcept;

        /// @brief Generates a Quaternion from three angles. His rotation order is YZX.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEulerYZX(T x, T y, T z) noexcept;

        /// @brief Generates a Quaternion from three angles. His rotation order is ZXY.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEulerZXY(T x, T y, T z) noexcept;

        /// @brief Generates a Quaternion from three angles. His rotation order is ZYX.
        /// @param x The angle to rotate by on the X axis, `IN DEGREES`
        /// @param y The angle to rotate by on the Y axis, `IN DEGREES`
        /// @param z The angle to rotate by on the Z axis, `IN DEGREES`
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEulerZYX(T x, T y, T z) noexcept;



        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `XYZ`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEulerXYZ(const quat<T>& q) noexcept;

        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `XZY`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEulerXZY(const quat<T>& q) noexcept;

        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `YXZ`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEulerYXZ(const quat<T>& q) noexcept;

        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `YZX`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEulerYZX(const quat<T>& q) noexcept;

        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `ZXY`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEulerZXY(const quat<T>& q) noexcept;
        
        /// @brief Returns a Vector3 made of the angles to rotate around each axis, `IN DEGREES` 
        /// @param q The Quaternion to extract the angles from. His rotation order has to be `ZYX`
        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEulerZYX(const quat<T>& q) noexcept;

    } // namespace Qua 

} // namespace tmx

#include "tmx/internal/quat/compute_angle.inl"