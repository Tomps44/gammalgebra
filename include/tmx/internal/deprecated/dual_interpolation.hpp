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

#include "tmx/internal/type_dualQuat.hpp"

namespace tmx
{
    namespace DQua
    {
        /// @brief Linearly interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at.
        template<typename T>
        [[deprecated("Dual Quaternions are still work in progress")]]
        TMX_INLINE constexpr dQuat<T> lerpUnclamped(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept;
        /// @brief Linearly interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at. Gets clamped between 0 and 1.
        template<typename T>
        TMX_INLINE constexpr dQuat<T> lerp(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept;

        /// @brief Spherically interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at.
        template<typename T>
        TMX_INLINE constexpr dQuat<T> slerpUnclamped(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept;
        /// @brief Spherically interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at. Gets clamped between 0 and 1.
        template<typename T>
        TMX_INLINE constexpr dQuat<T> slerp(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept;

    } // namespace Vec
    
} // namespace tmx

#include "tmx/internal/quat/compute_dual_interpolation.inl"
