#pragma once

#include "tmx/internal/type_quat.hpp"

namespace tmx
{
    namespace Qua
    {
        /// @brief Generates a Quaternion from a pure Quaternion. Transforming a vector in a rotation
        /// @param q A pure Quaternion
        template<typename T>
        TMX_INLINE constexpr quat<T> Exp(const quat<T>& q) noexcept;
        
        /// @brief Generates a pure Quaternion from a Quaternion. Transforming a Quaternion in a vector
        /// @param q A Quaternion representing a rotation
        template<typename T>
        TMX_INLINE constexpr quat<T> Log(const quat<T>& q) noexcept;

        template<typename T>
        TMX_INLINE constexpr quat<T> Pow(const quat<T>& q, T exp) noexcept;
        /// @brief Equivalent to `Quaternion::pow(q, 0.5)`
        /// @param q 
        template<typename T>
        TMX_INLINE constexpr quat<T> Sqrt(const quat<T>& q) noexcept;

    } // namespace Qua
    
} // namespace tmx

#include "tmx/internal/quat/compute_exponential.inl"
