#include "tmx/internal/compute/vec_functors.hpp"
#include <cmath>

namespace tmx
{
    namespace internal
    {
        // template<size_t S, typename T, bool useSimd>
        // struct vecSqrt {};
        // template<size_t S, typename T, bool useSimd>
        // struct vecInvSqrt {};


        template<size_t S, typename T, bool useSimd>
        struct vecSqrt
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& v) noexcept
            {
                return internal::computeVec_oneElem<S, T>::call(std::sqrt, v);
            }
        };

        template<size_t S, typename T, bool useSimd>
        struct vecInvSqrt 
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& v) noexcept
            {
                return static_cast<T>(1) / Vec::Sqrt(v);
            }
        };

        template<size_t S, bool useSimd>
        struct vecInvSqrt<S, float, useSimd>
        {
            TMX_INLINE static constexpr vec<S, float> call(const vec<S, float>& v) noexcept
            {
                vec<S, float> tmp = v;
                vec<S, float> half = tmp * 0.5f;

                vec<S, unsigned int>* p = reinterpret_cast<vec<S, unsigned int>*>(const_cast<vec<S, float>*>(&v));
                vec<S, unsigned int> i = vec<S, unsigned int>(0x5f375a86) - (*p >> vec<S, unsigned int>(1));
			    vec<S, float>* ptmp = reinterpret_cast<vec<S, float>*>(&i);
			    tmp = *ptmp;
			    tmp = tmp * (1.5f - half * tmp * tmp);
			    return tmp;
            }
        };
    }

    namespace Vec
    {
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Pow(const vec<S, T>& v, const vec<S, T>& exp) noexcept
        {
            return internal::computeVec_twoElem<S, T>::call(std::pow, v, exp);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Pow(const vec<S, T>& v, T exp) noexcept
        {
            return internal::computeVec_twoElem<S, T>::call(std::pow, v, vec<S, T>(exp));
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Sqrt(const vec<S, T>& v) noexcept
        {
            return internal::vecSqrt<S, T, internal::useSimd<S, T>::value>::call(v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> InvSqrt(const vec<S, T>& v) noexcept
        {
            return internal::vecInvSqrt<S, T, internal::useSimd<S, T>::value>::call(v);
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Exp(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::exp, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Exp2(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::exp2, v);
        }


        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Log(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::log, v);
        }
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Log2(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::log2, v);
        }       
        template<size_t S, typename T>
        TMX_INLINE constexpr vec<S, T> Log10(const vec<S, T>& v) noexcept
        {
            return internal::computeVec_oneElem<S, T>::call(std::log10, v);
        }       
        

    } // namespace Vec
} // namespace tmx