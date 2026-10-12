#include <cmath>
#include <concepts>
#include <bit>

namespace glb
{
    namespace Math
    {
        template<std::integral Int>
        GLB_INLINE constexpr Int Pow(Int val, Int exponent) noexcept
        {
            Int sum = 1;

            for (Int i = 0; i < exponent; i++)
            {
                sum *= val;
            }

            return sum;
        }
        template<std::floating_point F>
        GLB_INLINE constexpr F Pow(F val, F exponent) noexcept
        {
            return std::pow(val, exponent);
        }
        
        
        template<typename T>
        GLB_INLINE constexpr T Sqrt(T val) noexcept
        {
            return std::sqrt(val);
        }
        GLB_INLINE float FastInvSqrt(float val) noexcept
        {
            float tmp = val;
            float half = tmp * 0.5f;

            int32_t* p = reinterpret_cast<int32_t*>(const_cast<float*>(&val));
            int32_t i = 0x5f375a86 - (*p >> 1);
			float* ptmp = reinterpret_cast<float*>(&i);
			tmp = *ptmp;
			tmp = tmp * (1.5f - half * tmp * tmp);
			return tmp;
        }
        template<typename T>
        GLB_INLINE constexpr T InvSqrt(T val) noexcept
        {
            return static_cast<T>(1) / std::sqrt(val);
        }


        template<typename T>
        GLB_INLINE constexpr T Cbrt(T val) noexcept
        {
            return std::pow(val, static_cast<T>(0.33333333333333333333333333333L));
        }



        template<typename T>
        GLB_INLINE constexpr T Exp(T exponent) noexcept
        {
            return std::exp(exponent);
        }
        template<typename T>
        GLB_INLINE constexpr T Exp2(T exponent) noexcept
        {
            return std::exp2(exponent);
        }
        template<typename T>
        GLB_INLINE constexpr T Log(T val) noexcept
        {
            return std::log(val);
        }
        template<typename T>
        GLB_INLINE constexpr T Log2(T val) noexcept
        {
            return std::log2(val);
        }
        template<typename T>
        GLB_INLINE constexpr T Log10(T val) noexcept
        {
            return std::log10(val);
        }




        GLB_INLINE constexpr bool IsPowerOfTwo(int8_t val) noexcept 
        { 
            return val > 0 && !(val & (val - 1)); 
        } 
        GLB_INLINE constexpr bool IsPowerOfTwo(int16_t val) noexcept 
        { 
            return val > 0 && !(val & (val - 1)); 
        } 
        GLB_INLINE constexpr bool IsPowerOfTwo(int32_t val) noexcept 
        { 
            return val > 0 && !(val & (val - 1)); 
        } 
        GLB_INLINE constexpr bool IsPowerOfTwo(int64_t val) noexcept 
        { 
            return val > 0 && !(val & (val - 1)); 
        } 


        GLB_INLINE constexpr uint8_t NextPowerOfTwo(uint8_t val) noexcept 
        { 
            return std::bit_ceil(val);
        } 
        GLB_INLINE constexpr uint16_t NextPowerOfTwo(uint16_t val) noexcept 
        { 
            return std::bit_ceil(val);
        } 
        GLB_INLINE constexpr uint32_t NextPowerOfTwo(uint32_t val) noexcept 
        { 
            return std::bit_ceil(val);
        } 
        GLB_INLINE constexpr uint64_t NextPowerOfTwo(uint64_t val) noexcept 
        { 
            return std::bit_ceil(val);
        } 
        
    } // namespace Math
} // namespace glb

