#include "tmx/math/common.hpp"

namespace tmx
{
    namespace Math
    {
        template<typename T>
        TMX_INLINE constexpr T Lerp(T start, T end, T t) noexcept
        {
            return (static_cast<T>(1) - t) * start + end * t;
        }
        template<typename T>
        TMX_INLINE constexpr T InvLerp(T start, T end, T val) noexcept
        {
            return (val - start) / (end - start);
        }


        template<typename T>
        TMX_INLINE constexpr T Step(T edge, T x) noexcept
        {
            return x < edge ? static_cast<T>(0) : static_cast<T>(1);
        }

        template<typename T>
        TMX_INLINE constexpr T SmoothStep(T edge0, T edge1, T x) noexcept
        {
            T t = Math::Clamp01((x - edge0) / (edge1 - edge0));
            return t * t * (static_cast<T>(3) - static_cast<T>(2) * t);
        }
        template<typename T>
        TMX_INLINE constexpr T SmootherStep(T edge0, T edge1, T x) noexcept
        {
            T t = Math::Clamp01((x - edge0) / (edge1 - edge0));
            return t * t * t * ( t * ( t * static_cast<T>(6) - static_cast<T>(15) ) + static_cast<T>(10) );
        }



        template<typename T>
        TMX_INLINE constexpr T Map(T val, T min1, T max1, T min2, T max2) noexcept
        {
            // Lerp between min2 et max2 by the inverse lerp of val in min1-max1

            return min2 + (max2 - min2) * ((val - min1) / (max1 - min1));
        }



        template<typename T>
        TMX_INLINE constexpr T SmoothDamp(T current, T target, T& currentVelocity,
                                                  T smoothTime, T deltaTime, T maxSpeed) noexcept
        {
            // Based on Game Programming Gems 4 Chapter 1.10
            smoothTime = std::max(static_cast<T>(0.0001), smoothTime);
            T omega = static_cast<T>(2) / smoothTime;

            T x = omega * deltaTime;
            T exp = static_cast<T>(1) / (static_cast<T>(1) + x + static_cast<T>(0.48) * x * x + static_cast<T>(0.235) * x * x * x);
            T change = current - target;
            T originalTo = target;

            // Clamp maximum speed
            T maxChange = maxSpeed * smoothTime;
            change = Math::Clamp(change, -maxChange, maxChange);
            target = current - change;

            T temp = (currentVelocity + omega * change) * deltaTime;
            currentVelocity = (currentVelocity - omega * temp) * exp;
            T output = target + (change + temp) * exp;

            // Prevent overshooting
            if (originalTo - current > static_cast<T>(0.0) == output > originalTo)
            {
                output = originalTo;
                currentVelocity = (output - originalTo) / deltaTime;
            }

            return output;
        }

        template<typename T>
        TMX_INLINE constexpr T MoveToward(T current, T target, T maxDelta) noexcept
        {
            if (std::abs(target - current) <= maxDelta)
                return target;

            return current + Math::Sign(target - current) * maxDelta;
        }

    } // namespace Math
} // namespace tmx

