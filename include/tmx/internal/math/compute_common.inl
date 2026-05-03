#include <cmath>
#include <concepts>

namespace tmx
{
    namespace Math
    {
        template<typename T>
        TMX_INLINE constexpr T Min(T a, T b) noexcept
        {
            return a < b ? a : b;
        }
        template<typename T>
        TMX_INLINE constexpr T Max(T a, T b) noexcept
        {
            return a > b ? a : b;
        }


        template<typename T>
        TMX_INLINE constexpr T Clamp(T val, T minVal, T maxVal) noexcept
        {
            return Math::Min(Math::Max(val, minVal), maxVal);
        }
        template<typename T>
        TMX_INLINE constexpr T Clamp01(T val) noexcept
        {
            return Math::Min(Math::Max(val, static_cast<T>(0)), static_cast<T>(1));
        }
        template<typename T>
        TMX_INLINE constexpr T Saturate(T val) noexcept
        {
            return Math::Min(Math::Max(val, static_cast<T>(0)), static_cast<T>(1));
        }


        template<typename T>
        TMX_INLINE constexpr T Sign(T val) noexcept
        {
            return (static_cast<T>(0) < val) - (val < static_cast<T>(0));
        }


    
        template<typename T>
        TMX_INLINE constexpr T Abs(T val) noexcept { return std::abs(val); };


        template<typename T>
        TMX_INLINE constexpr T Round(T val) noexcept { return std::round(val); };
        template<typename T>
        TMX_INLINE constexpr T Floor(T val) noexcept { return std::floor(val); };
        template<typename T>
        TMX_INLINE constexpr T Ceil(T val) noexcept { return std::ceil(val); };
        template<typename T>
        TMX_INLINE constexpr T Trunc(T val) noexcept { return std::trunc(val); };
        template<typename T>
        TMX_INLINE constexpr T Fract(T val) noexcept 
        {
            return val - std::floor(val);
        }


        template<typename T>
        TMX_INLINE constexpr T Mod(T val, T modulus) noexcept { return std::fmod(val, modulus); };


        

    } // namespace Math
} // namespace tmx

