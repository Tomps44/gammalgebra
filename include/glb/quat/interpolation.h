#pragma once

#include "../internal/type_quat.h"

namespace glb
{
    namespace Qtr
    {
        /** @brief Linearly interpolates between the two Quaternions `start` and `end`, by a factor of `t`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> LerpUnclamped(const glbQuat_T<T>& start, const glbQuat_T<T>& end, T t) noexcept;
        /** @brief Linearly interpolates between the two Quaternions `start` and `end`, by a factor of `t`, 
         * which gets clamped in the range of `[0; 1]`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Lerp(const glbQuat_T<T>& start, const glbQuat_T<T>& end, T t) noexcept;

        /** @brief Spherically interpolates between the two Quaternions `start` and `end`, by a factor of `t`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> SlerpUnclamped(const glbQuat_T<T>& start, const glbQuat_T<T>& end, T t) noexcept;
        /** @brief Spherically interpolates between the two Quaternions `start` and `end`, by a factor of `t`, 
         * which gets clamped in the range of `[0; 1]`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Slerp(const glbQuat_T<T>& start, const glbQuat_T<T>& end, T t) noexcept;

    } // namespace Vec
    
} // namespace glb

#include "../internal/quat/compute_interpolation.inl"
