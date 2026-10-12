#pragma once

#include "../internal/type_vec.h"

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Pow(const glbVec_T<S, T>& v, const glbVec_T<S, T>& exponent) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Pow(const glbVec_T<S, T>& v, T exponent) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Sqrt(const glbVec_T<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> InvSqrt(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Exp(const glbVec_T<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Exp2(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Log(const glbVec_T<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Log2(const glbVec_T<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Log10(const glbVec_T<S, T>& v) noexcept;
    }
}

#include "../internal/vec/compute_exponential.inl"