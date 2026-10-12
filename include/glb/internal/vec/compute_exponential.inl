#include "../compute/vec_functors.h"
#include <cmath>

namespace glb
{
    namespace glbIntern
    {
        // template<int S, typename T, bool useSimd>
        // struct vecSqrt {};
        // template<int S, typename T, bool useSimd>
        // struct vecInvSqrt {};


        template<int S, typename T, bool useSimd>
        struct vecSqrt
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& v) noexcept
            {
                return glbIntern::computeVec_oneElem<S, T>::call(std::sqrt, v);
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecInvSqrt 
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& v) noexcept
            {
                return static_cast<T>(1) / Vec::Sqrt(v);
            }
        };

        template<int S, bool useSimd>
        struct vecInvSqrt<S, float, useSimd>
        {
            GLB_INLINE static constexpr glbVec_T<S, float> call(const glbVec_T<S, float>& v) noexcept
            {
                glbVec_T<S, float> tmp = v;
                glbVec_T<S, float> half = tmp * 0.5f;

                glbVec_T<S, unsigned int>* p = reinterpret_cast<glbVec_T<S, unsigned int>*>(const_cast<glbVec_T<S, float>*>(&v));
                glbVec_T<S, unsigned int> i = glbVec_T<S, unsigned int>(0x5f375a86) - (*p >> glbVec_T<S, unsigned int>(1));
			    glbVec_T<S, float>* ptmp = reinterpret_cast<glbVec_T<S, float>*>(&i);
			    tmp = *ptmp;
			    tmp = tmp * (1.5f - half * tmp * tmp);
			    return tmp;
            }
        };
    }

    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Pow(const glbVec_T<S, T>& v, const glbVec_T<S, T>& exp) noexcept
        {
            return glbIntern::computeVec_twoElem<S, T>::call(std::pow, v, exp);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Pow(const glbVec_T<S, T>& v, T exp) noexcept
        {
            return glbIntern::computeVec_twoElem<S, T>::call(std::pow, v, glbVec_T<S, T>(exp));
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Sqrt(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::vecSqrt<S, T, glbIntern::useSimd<S, T>::value>::call(v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> InvSqrt(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::vecInvSqrt<S, T, glbIntern::useSimd<S, T>::value>::call(v);
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Exp(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::exp, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Exp2(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::exp2, v);
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Log(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::log, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Log2(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::log2, v);
        }       
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Log10(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::log10, v);
        }       
        

    } // namespace Vec
} // namespace glb