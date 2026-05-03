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

#include "tmx/internal/type_dualquat.hpp"

namespace tmx
{
    namespace DQua
    {
        template<typename T>
        TMX_INLINE constexpr dQuat<T> normalize(const dQuat<T>& dq) noexcept;

        template<typename T>
        TMX_INLINE constexpr dQuat<T> conjugate(const dQuat<T>& dq) noexcept;

        template<typename T>
        TMX_INLINE constexpr dQuat<T> inverse(const dQuat<T>& dq) noexcept;


        template<typename T>
        TMX_INLINE constexpr quat<T> getRotation(const dQuat<T>& dq) noexcept;

        template<typename T>
        TMX_INLINE constexpr vec<3, T> getTranslation(const dQuat<T>& dq) noexcept;

    } // namespace DQua
} // namespace tmx

#include "tmx/internal/quat/compute_dual_geometric.inl"