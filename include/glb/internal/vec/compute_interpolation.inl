#include "../../vec/geometric.h"
#include <cmath>

namespace glb
{
    namespace glbIntern
    {
        template<int S, typename T, bool useSimd>
        struct vecLerpUnclamped
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& start, const glbVec_T<S, T>& end, T t) noexcept
            {
                return (static_cast<T>(1) - t) * start + end * t;
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecSlerpUnclamped
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& start, const glbVec_T<S, T>& end, T t) noexcept
            {
                T dot = Vec::Dot(start, end);

                if (std::abs(dot) > static_cast<T>(0.9995))
                {
                    return glbIntern::vecLerpUnclamped<S, T, glbIntern::useSimd<S, T>::value>::call(start, end, t);
                }

                T omega = std::acos(dot);
                T sinOmega = std::sin(omega);


                T w0 = std::sin((static_cast<T>(1) - t) * omega) / sinOmega;
                T w1 = std::sin(t * omega) / sinOmega;

                return (start * w0) + (end * w1);
            }
        };

    }

    namespace Vec
    {    
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Lerp(const glbVec_T<S, T>& start, const glbVec_T<S, T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return glbIntern::vecLerpUnclamped<S, T, glbIntern::useSimd<S, T>::value>::call(start, end, t);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> LerpUnclamped(const glbVec_T<S, T>& start, const glbVec_T<S, T>& end, T t) noexcept
        {
            return glbIntern::vecLerpUnclamped<S, T, glbIntern::useSimd<S, T>::value>::call(start, end, t);
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Slerp(const glbVec_T<S, T>& start, const glbVec_T<S, T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return glbIntern::vecSlerpUnclamped<S, T, glbIntern::useSimd<S, T>::value>::call(start, end, t);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> SlerpUnclamped(const glbVec_T<S, T>& start, const glbVec_T<S, T>& end, T t) noexcept
        {
            return glbIntern::vecSlerpUnclamped<S, T, glbIntern::useSimd<S, T>::value>::call(start, end, t);
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> SmoothDamp(const glbVec_T<S, T>& current, const glbVec_T<S, T>& target, glbVec_T<S, T>& currentVelocity,
                                                  T smoothTime, T deltaTime, T maxSpeed) noexcept
        {
            // Code taken from the Unity Engine (MODIFIED) :
            // https://github.com/Unity-Technologies/UnityCsReference/blob/master/Runtime/Export/Math/Vector3.cs


            smoothTime = std::max(static_cast<T>(0.001), smoothTime);
            T omega = static_cast<T>(2) / smoothTime;

            T x = omega * deltaTime;
            T exp = static_cast<T>(1) / (static_cast<T>(1) + x + static_cast<T>(0.48) * x * x + static_cast<T>(0.235) * x * x * x);
            T change = current - target;
            T originalTo = target;

            // Clamp maximum speed
            T maxChange = maxSpeed * smoothTime;
            change = Vec::ClampMagnitude(change, maxChange);
            target = current - change;

            T temp = (currentVelocity + omega * change) * deltaTime;
            currentVelocity = (currentVelocity - omega * temp) * exp;
            glbVec_T<S, T> res = target + (change + temp) * exp;

            // Prevent overshooting
            if (Vec::Dot(originalTo - current, res - originalTo) > static_cast<T>(0))
            {
                res = originalTo;
                currentVelocity = (res - originalTo) / deltaTime;
            }

            return res;
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> MoveTowards(const glbVec_T<S, T>& current, const glbVec_T<S, T>& target, T maxDistanceDelta) noexcept
        {
            // Code taken from the Unity Engine (MODIFIED) :
            // https://github.com/Unity-Technologies/UnityCsReference/blob/master/Runtime/Export/Math/Vector3.cs

            glbVec_T<S, T> toVector = target - current;
            T sqDist = Vec::LengthSquared(toVector);

            //                                                     checks if sqDist is equal to 0 (sqDist is squared, so abs() is not needed)
            if (sqDist <= maxDistanceDelta * maxDistanceDelta || sqDist < static_cast<T>(0.000001))
            {
                return target;
            }

            return current + ( toVector / std::sqrt(sqDist)) * maxDistanceDelta;
        }

    } // namespace Vec
} // namespace glb