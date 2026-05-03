#include <cmath>
#include <concepts>

namespace tmx
{
    namespace Math
    {
        template<std::integral Int>
        TMX_INLINE constexpr Int Pow(Int val, Int exponent) noexcept
        {
            std::cout << "I" << '\n';
            Int sum = 1;

            for (Int i = 0; i < exponent; i++)
            {
                sum *= val;
            }

            return sum;
        }
        template<std::floating_point F>
        TMX_INLINE constexpr F Pow(F val, F exponent) noexcept
        {
            std::cout << "F" << '\n';
            return std::pow(val, exponent);
        }
        
        
        template<typename T>
        TMX_INLINE constexpr T Sqrt(T val) noexcept
        {
            return std::sqrt(val);
        }
        // template<>
        // TMX_INLINE constexpr float invSqrt(float val) noexcept
        // {
        //     float tmp = val;
        //     float half = tmp * 0.5f;

        //     int* p = reinterpret_cast<int*>(const_cast<float*>(&val));
        //     int i = 0x5f375a86 - (*p >> 1);
		// 	float* ptmp = reinterpret_cast<float*>(&i);
		// 	tmp = *ptmp;
		// 	tmp = tmp * (1.5f - half * tmp * tmp);
		// 	return tmp;
        // }
        template<typename T>
        TMX_INLINE constexpr T InvSqrt(T val) noexcept
        {
            return static_cast<T>(1) / std::sqrt(val);
        }


        template<typename T>
        TMX_INLINE constexpr T Cbrt(T val) noexcept
        {
            return std::pow(val, static_cast<T>(0.33333333333333333333333333333L));
        }



        template<typename T>
        TMX_INLINE constexpr T Exp(T exponent) noexcept
        {
            return std::exp(exponent);
        }
        template<typename T>
        TMX_INLINE constexpr T Exp2(T exponent) noexcept
        {
            return std::exp2(exponent);
        }
        template<typename T>
        TMX_INLINE constexpr T Log(T val) noexcept
        {
            return std::log(val);
        }
        template<typename T>
        TMX_INLINE constexpr T Log2(T val) noexcept
        {
            return std::log2(val);
        }
        template<typename T>
        TMX_INLINE constexpr T Log10(T val) noexcept
        {
            return std::log10(val);
        }

        
        

    } // namespace Math
} // namespace tmx

