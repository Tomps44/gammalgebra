#pragma once

#include "../internal/type_vec.h"

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> LerpUnclamped(const glbVec_T<S, T>& s, const glbVec_T<S, T>& e, T t) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Lerp(const glbVec_T<S, T>& s, const glbVec_T<S, T>& e, T t) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> SlerpUnclamped(const glbVec_T<S, T>& s, const glbVec_T<S, T>& e, T t) noexcept;
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Slerp(const glbVec_T<S, T>& s, const glbVec_T<S, T>& e, T t) noexcept;

        
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> SmoothDamp(const glbVec_T<S, T>& current, const glbVec_T<S, T>& target, glbVec_T<S, T>& currentVelocity,
                                                  T smoothTime, T deltaTime, T maxSpeed = std::numeric_limits<T>::infinity()) noexcept;

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> MoveTowards(const glbVec_T<S, T>& current, const glbVec_T<S, T>& target, T maxDistanceDelta) noexcept;

    } // namespace Vec
} // namespace glb

#include "../internal/vec/compute_interpolation.inl"
