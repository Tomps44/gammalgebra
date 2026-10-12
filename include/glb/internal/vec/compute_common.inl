#include "../type_vec.h"
#include <cmath>

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Min(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            // return glbIntern::computeVec_twoElem<S, T>::call(std::min, a, b));

            // For some unknown reason, the line above throws an <unresolved overloaded function type>, 
            // so I define the min function myself

            // The same thing apply for the max function 
            
            return glbIntern::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a < b ? a : b; }, 
                a, b);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Min(const glbVec_T<S, T>& v, T scalar) noexcept
        {
            // return glbIntern::computeVec_twoElem<S, T>::call(std::min, v, glbVec_T<S, T>(scalar));
            return glbIntern::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a < b ? a : b; }, 
                v, glbVec_T<S, T>(scalar));
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Max(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            // return glbIntern::computeVec_twoElem<S, T>::call(std::max, a, b));
            return glbIntern::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a > b ? a : b; }, 
                a, b);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Max(const glbVec_T<S, T>& v, T scalar) noexcept
        {
            // return glbIntern::computeVec_twoElem<S, T>::call(std::max, v, glbVec_T<S, T>(scalar));
            return glbIntern::computeVec_twoElem<S, T>::call(
                [](T a, T b) -> T
                { return a > b ? a : b; }, 
                v, glbVec_T<S, T>(scalar));
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Abs(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::abs, v);
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Clamp(const glbVec_T<S, T>& v, const glbVec_T<S, T>& minVal, const glbVec_T<S, T>& maxVal) noexcept
        {
            return Vec::Min(Vec::Max(v, minVal), maxVal);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Clamp(const glbVec_T<S, T>& v, T minVal, T maxVal) noexcept
        {
            return Vec::Min(Vec::Max(v, glbVec_T<S, T>(minVal)), glbVec_T<S, T>(maxVal));
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Clamp01(const glbVec_T<S, T>& v) noexcept
        {
            return Vec::Min(Vec::Max(v, static_cast<T>(0)), static_cast<T>(1));
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Saturate(const glbVec_T<S, T>& v) noexcept
        {
            return Vec::Clamp01(v);
        }



        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Floor(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::floor, v);
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Ceil(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::ceil, v);
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Round(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::round, v);
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Trunc(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::computeVec_oneElem<S, T>::call(std::trunc, v);
        }



        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Mod(const glbVec_T<S, T>& v, const glbVec_T<S, T>& modulus) noexcept
        {
            return glbIntern::computeVec_twoElem<S, T>::call(std::fmod, v, modulus);
        }
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Mod(const glbVec_T<S, T>& v, T modulus) noexcept
        {
            return glbIntern::computeVec_twoElem<S, T>::call(std::fmod, v, glbVec_T<S, T>(modulus));
        }


        

        

    } // namespace Vec
}