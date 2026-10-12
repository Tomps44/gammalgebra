
#include "compute/compute_mat.h"
#include <limits>

namespace glb
{
    // --- Unary operators ---

    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator+(const glbMat_T<R, C, T>& m) noexcept
    {
        return m;
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator-(const glbMat_T<R, C, T>& m) noexcept
    {
        return glbIntern::matNeg<R, C, T, glbIntern::useSimd<R, T>::value>::call(m);
    }



    // --- Arithmetic operators

    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator+(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b) noexcept
    {
        return glbIntern::matAdd<R, C, T, glbIntern::useSimd<R, T>::value>::call(a, b);
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator+(const glbMat_T<R, C, T>& m, T scalar) noexcept
    {
        return glbIntern::matAdd<R, C, T, glbIntern::useSimd<R, T>::value>::call(m, scalar);
    }
    


    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator-(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b) noexcept
    {
        return glbIntern::matSub<R, C, T, glbIntern::useSimd<R, T>::value>::call(a, b);
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator-(const glbMat_T<R, C, T>& m, T scalar) noexcept
    {
        return glbIntern::matSub<R, C, T, glbIntern::useSimd<R, T>::value>::call(m, scalar);
    }


    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator*(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b) noexcept
    {
        return glbIntern::matMul<R, C, T, glbIntern::useSimd<R, T>::value>::call(a, b);
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator*(const glbMat_T<R, C, T>& m, T scalar) noexcept
    {
        return glbIntern::matMul<R, C, T, glbIntern::useSimd<R, T>::value>::call(m, scalar);
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator*(T scalar, const glbMat_T<R, C, T>& m) noexcept
    {
        return glbIntern::matMul<R, C, T, glbIntern::useSimd<R, T>::value>::call(m, scalar);
    }

    template<int R, int C, typename T>
    GLB_INLINE constexpr typename glbMat_T<R, C, T>::colType operator*(const glbMat_T<R, C, T>& m, const typename glbMat_T<R, C, T>::colType& v) noexcept
    {
        return glbIntern::matMul<R, C, T, glbIntern::useSimd<R, T>::value>::call(m, v);
    }


    template<int R, int C, typename T>
    GLB_INLINE constexpr glbMat_T<R, C, T> operator/(const glbMat_T<R, C, T>& m, T scalar) noexcept
    {
        return glbIntern::matDiv<R, C, T, glbIntern::useSimd<R, T>::value>::call(m, scalar);
    }




    template<int R, int C, typename T>
    GLB_INLINE constexpr bool operator==(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b) noexcept
    {
        return glbIntern::matEqual<R, C, T>::call(a, b);
    }
    template<int R, int C, typename T>
    GLB_INLINE constexpr bool operator!=(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b) noexcept
    {
        return !(a == b);
    }
}