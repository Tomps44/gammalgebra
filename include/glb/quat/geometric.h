#pragma once

#include "../internal/type_quat.h"

namespace glb
{
    namespace Qua
    {
        template<typename T>
        GLB_INLINE constexpr T Dot(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept;

        template<typename T>
        GLB_INLINE constexpr T Length(const glbQuat_T<T>& q) noexcept;
        template<typename T>
        GLB_INLINE constexpr T LengthSquared(const glbQuat_T<T>& q) noexcept;

        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Normalize(const glbQuat_T<T>& q) noexcept;

        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Conjugate(const glbQuat_T<T>& q) noexcept;
        
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Inverse(const glbQuat_T<T>& q) noexcept;

    } // namespace Qua

} // namespace glb

#include "../internal/quat/compute_geometric.inl"