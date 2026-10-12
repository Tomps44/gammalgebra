#include <cmath>
#include <concepts>
#include <limits>

namespace glb
{
    namespace Math
    {
        template<typename T>
        GLB_INLINE constexpr T Min(T a, T b) noexcept
        {
            return a < b ? a : b;
        }
        template<typename T>
        GLB_INLINE constexpr T Max(T a, T b) noexcept
        {
            return a > b ? a : b;
        }


        template<typename T>
        GLB_INLINE constexpr T Clamp(T val, T minVal, T maxVal) noexcept
        {
            return Math::Min(Math::Max(val, minVal), maxVal);
        }
        template<typename T>
        GLB_INLINE constexpr T Clamp01(T val) noexcept
        {
            return Math::Min(Math::Max(val, static_cast<T>(0)), static_cast<T>(1));
        }
        template<typename T>
        GLB_INLINE constexpr T Saturate(T val) noexcept
        {
            return Math::Min(Math::Max(val, static_cast<T>(0)), static_cast<T>(1));
        }


        template<typename T>
        GLB_INLINE constexpr T Sign(T val) noexcept
        {
            return (static_cast<T>(0) < val) - (val < static_cast<T>(0));
        }


    
        template<typename T>
        GLB_INLINE constexpr T Abs(T val) noexcept { return std::abs(val); };


        template<typename T>
        GLB_INLINE constexpr T Round(T val) noexcept { return std::round(val); };
        template<typename T>
        GLB_INLINE constexpr T Floor(T val) noexcept { return std::floor(val); };
        template<typename T>
        GLB_INLINE constexpr T Ceil(T val) noexcept { return std::ceil(val); };
        template<typename T>
        GLB_INLINE constexpr T Trunc(T val) noexcept { return std::trunc(val); };
        template<typename T>
        GLB_INLINE constexpr T Fract(T val) noexcept 
        {
            return val - std::floor(val);
        }


        GLB_INLINE constexpr int32_t RoundToInt(float val) noexcept
        {
            return static_cast<int32_t>(std::round(val));
        }
        GLB_INLINE constexpr int32_t FloorToInt(float val) noexcept
        {
            return static_cast<int32_t>(std::floor(val));
        }
        GLB_INLINE constexpr int32_t CeilToInt(float val) noexcept
        {
            return static_cast<int32_t>(std::ceil(val));
        }
        GLB_INLINE constexpr int32_t TruncToInt(float val) noexcept
        {
            return static_cast<int32_t>(std::trunc(val));
        }


        template<typename T>
        GLB_INLINE constexpr T Mod(T val, T modulus) noexcept { return std::fmod(val, modulus); };


        template<typename T>
        GLB_INLINE constexpr T Repeat(T val, T max) noexcept
        {
            return Math::Clamp(val - std::floor(val / max) * max, static_cast<T>(0), max);
        }
        template<typename T>
        GLB_INLINE constexpr T PingPong(T val, T max) noexcept
        {
            val = Math::Repeat(val, max * static_cast<T>(2));
            return max - std::abs(val - max);
        }


        template<typename T>
        GLB_INLINE constexpr bool ApproxEqual(T a, T b) noexcept
        {
            return glbIntern::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a, b);
        }

        template<typename T>
        GLB_INLINE constexpr bool ApproxZero(T val) noexcept
        {
            return val == 0;
        }
        template<>
        GLB_INLINE constexpr bool ApproxZero(float val) noexcept
        {
            return std::abs(val) < 8.0e-05f;
        }
        template<>
        GLB_INLINE constexpr bool ApproxZero(double val) noexcept
        {
            return std::abs(val) < 8.0e-13f;
        }
        template<>
        GLB_INLINE constexpr bool ApproxZero(long double val) noexcept
        {
            return std::abs(val) < 8.0e-16f;
        }


        template<typename T>
        GLB_INLINE constexpr bool IsNan(T val) noexcept
        {
            return false;
        }
        template<>
        GLB_INLINE constexpr bool IsNan(float val) noexcept
        {
            return std::isnan(val);
        }
        template<>
        GLB_INLINE constexpr bool IsNan(double val) noexcept
        {
            return std::isnan(val);
        }
        template<>
        GLB_INLINE constexpr bool IsNan(long double val) noexcept
        {
            return std::isnan(val);
        }


        template<typename T>
        GLB_INLINE constexpr bool IsInf(T val) noexcept
        {
            return false;
        }
        template<>
        GLB_INLINE constexpr bool IsInf(float val) noexcept
        {
            return std::isinf(val);
        }
        template<>
        GLB_INLINE constexpr bool IsInf(double val) noexcept
        {
            return std::isinf(val);
        }
        template<>
        GLB_INLINE constexpr bool IsInf(long double val) noexcept
        {
            return std::isinf(val);
        }
        

    } // namespace Math
} // namespace glb

