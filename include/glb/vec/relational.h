#pragma once

#include "../internal/type_vec.h"

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> GreaterThan(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> GreaterThanOrEqual(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> LessThan(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> LessThanOrEqual(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> Equal(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> NotEqual(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;

        template<int S>
        GLB_INLINE constexpr bool Any(const glbVec_T<S, bool>& v) noexcept;
        template<int S>
        GLB_INLINE constexpr bool All(const glbVec_T<S, bool>& v) noexcept;

    } // namespace Vector
} // namespace glb

#include "../internal/vec/compute_relational.inl"