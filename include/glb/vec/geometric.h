#pragma once

#include "../internal/type_vec.h"

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr T Dot(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr T Length(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr T LengthSquared(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr T Distance(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr T DistanceSquared(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Cross(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Normalize(const glbVec_T<S, T>& v) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> FaceForward(const glbVec_T<S, T>& N, const glbVec_T<S, T>& I, const glbVec_T<S, T>& Nref) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Reflect(const glbVec_T<S, T>& I, const glbVec_T<S, T>& N) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Refract(const glbVec_T<S, T>& I, const glbVec_T<S, T>& N, T eta) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Project(const glbVec_T<S, T>& proj, const glbVec_T<S, T>& base) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> ClampMagnitude(const glbVec_T<S, T>& v, T maxLength) noexcept;
        
    } // namespace Vector
}

#include "../internal/vec/compute_geometric.inl"