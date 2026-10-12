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

#include "type_dualquat.h"

namespace glb
{
    namespace DQua
    {
        /// @brief Linearly interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at.
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> LerpUnclamped(const glbDQuat_T<T>& start, const glbDQuat_T<T>& end, T t) noexcept;
        /// @brief Linearly interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at. Gets clamped between 0 and 1.
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Lerp(const glbDQuat_T<T>& start, const glbDQuat_T<T>& end, T t) noexcept;

        /// @brief Spherically interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at.
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> SlerpUnclamped(const glbDQuat_T<T>& start, const glbDQuat_T<T>& end, T t) noexcept;
        /// @brief Spherically interpolates between two Quaternions (start - end), by time t.
        /// @param start The first Quaternion, starting the interpolation. It has to be a `unit` Quaternion ! 
        /// @param end The second Quaternion, ending the interpolation. It has to be a `unit` Quaternion ! 
        /// @param t The time the interpolation is at. Gets clamped between 0 and 1.
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Slerp(const glbDQuat_T<T>& start, const glbDQuat_T<T>& end, T t) noexcept;

    } // namespace Vec
    
} // namespace glb

#include "compute_dual_interpolation.inl"
