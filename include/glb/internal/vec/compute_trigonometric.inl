#include "../compute/vec_functors.h"
#include <cmath>

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> ToRad(const glbVec_T<S, T>& v) noexcept
        {
            return v * static_cast<T>(0.01745329251994329576923690768489);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> ToDeg(const glbVec_T<S, T>& v) noexcept
        {
            return v * static_cast<T>(57.295779513082320876798154814105);
        }



        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Sin(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::sin, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Cos(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::cos, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Tan(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::tan, v);
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Asin(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::asin, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Acos(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::acos, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Atan(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::atan, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Atan2(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            return glbIntern::computeVec_twoElem<S, T>::call(std::atan2, a, b);
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Sinh(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::sinh, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Cosh(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::cosh, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Tanh(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::tanh, v);
        }
        


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Asinh(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::asinh, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Acosh(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::acosh, v);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Atanh(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::atanh, v);
        }
    }
}