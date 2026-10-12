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
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Normalize(const glbDQuat_T<T>& dq) noexcept;

        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Conjugate(const glbDQuat_T<T>& dq) noexcept;

        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Inverse(const glbDQuat_T<T>& dq) noexcept;


        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> GetRotation(const glbDQuat_T<T>& dq) noexcept;

        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> GetTranslation(const glbDQuat_T<T>& dq) noexcept;

    } // namespace DQua
} // namespace glb

#include "compute_dual_geometric.inl"