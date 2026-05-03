#pragma once

#include "tmx/internal/definitions.hpp"
#include <limits>

namespace tmx
{
    namespace Math
    {
        /// @brief Lineraly interpolates between `start` and `end` by time t 
        /// @param start The starting value of the interpolation
        /// @param end The ending value of the interpolation
        /// @param t The time of the interpolation
        /// @attention The precise - but slower - formula, is used : `(1 - t) * start + end * t`
        template<typename T = Real>
        TMX_INLINE constexpr T Lerp(T start, T end, T t) noexcept;
        /// @brief Returns the time of the interpolation between `start`and `end`, if the value is `val`
        /// @param start The starting value of the interpolation
        /// @param end The starting value of the interpolation
        /// @param val The value between `start` and `end`, giving the time t
        /// ```cpp
        /// #include "tmx/math/interpolation"
        ///
        /// int main()
        /// {
        ///     std::cout << Math::invLerp(0.0f, 10.0f, 2.5f) // 0.25f
        /// }
        /// ```
        template<typename T = Real>
        TMX_INLINE constexpr T InvLerp(T start, T end, T val) noexcept;

        /// @brief Returns `0` if `x` is strictly smaller than `edge`, else returns `1`
        /// @param edge The value with which `x` will be checked
        /// @param x The value to check that it is smaller than `edge`
        template<typename T = Real>
        TMX_INLINE constexpr T Step(T edge, T x) noexcept;
        template<typename T = Real>
        TMX_INLINE constexpr T SmoothStep(T edge0, T edge1, T x) noexcept;
        template<typename T = Real>
        TMX_INLINE constexpr T SmootherStep(T edge0, T edge1, T x) noexcept;


        /// @brief Maps `val`, contained in [`min1`; `max1`], to [`min2`; `max2`]
        /// @param val The value to map, contained between `min1`and `max1`
        /// @param min1 The smallest value of the first serie, containing `val`
        /// @param max1 The largest value of the first serie, containing `val`
        /// @param min2 The smallest value of the second serie
        /// @param max2 The largest value of the second serie
        template<typename T = Real>
        TMX_INLINE constexpr T Map(T val, T min1, T max1, T min2, T max2) noexcept;


        template<typename T = Real>
        TMX_INLINE constexpr T SmoothDamp(T current, T target, T& currentVelocity,
                                                  T smoothTime, T deltaTime, T maxSpeed = std::numeric_limits<T>::infinity()) noexcept;

        template<typename T = Real>
        TMX_INLINE constexpr T MoveToward(T current, T target, T maxDelta) noexcept;

    } // namespace Math
} // namespace tmx

#include "tmx/internal/math/compute_interpolation.inl"
