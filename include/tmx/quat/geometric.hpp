#pragma once

#include "tmx/internal/type_quat.hpp"

namespace tmx
{
    namespace Qua
    {
        template<typename T>
        TMX_INLINE constexpr T Dot(const quat<T>& a, const quat<T>& b) noexcept;

        template<typename T>
        TMX_INLINE constexpr T Length(const quat<T>& q) noexcept;
        template<typename T>
        TMX_INLINE constexpr T LengthSquared(const quat<T>& q) noexcept;

        template<typename T>
        TMX_INLINE constexpr quat<T> Normalize(const quat<T>& q) noexcept;

        template<typename T>
        TMX_INLINE constexpr quat<T> Conjugate(const quat<T>& q) noexcept;
        
        template<typename T>
        TMX_INLINE constexpr quat<T> Inverse(const quat<T>& q) noexcept;

    } // namespace Qua

} // namespace tmx

#include "tmx/internal/quat/compute_geometric.inl"