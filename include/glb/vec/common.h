#pragma once

#include "../internal/type_vec.h"

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Min(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Min(const glbVec_T<S, T>& v, T scalar) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Max(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Max(const glbVec_T<S, T>& v, T scalar) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Abs(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Clamp(const glbVec_T<S, T>& v, const glbVec_T<S, T>& minVal, const glbVec_T<S, T>& mxVal) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Clamp(const glbVec_T<S, T>& v, T minVal, T mxVal) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Clamp01(const glbVec_T<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Saturate(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Floor(const glbVec_T<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Ceil(const glbVec_T<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Round(const glbVec_T<S, T>& v) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Trunc(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Mod(const glbVec_T<S, T>& v, const glbVec_T<S, T>& modulus) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Mod(const glbVec_T<S, T>& v, T modulus) noexcept;
    }
}

#include "../internal/vec/compute_common.inl"