#pragma once

#include "../internal/type_quat.h"

namespace glb
{
    namespace Qtr
    {
        template<typename From, typename To>
        GLB_INLINE constexpr glbQuat_T<To> CastTo(const glbQuat_T<From>& q) noexcept
        {
            return glbQuat_T<To>(
                static_cast<To>(q.w),
                static_cast<To>(q.x),
                static_cast<To>(q.y),
                static_cast<To>(q.z);
            )
        }

        /**
         * @brief Generates a Quaternion with its `x, y, z, w` components being respectively `qx, qy, qz, qw`, in that order.
         */
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> xyzw(T qx, T qy, T qz, T qw) noexcept
        {
            return glbQuat_T<T>(w, x, y, z);
        }


    } // namespace Qtr
} // namespace glb
