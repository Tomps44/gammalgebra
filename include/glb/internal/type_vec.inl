
#include "compute/compute_vec.h"
#include <limits>

namespace glb
{
    // --- Unary operators ---

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator+(const glbVec_T<S, T>& v) noexcept
    {
        return v;
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator-(const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecNeg<S, T, glbIntern::useSimd<S, T>::value>::call(v);
    }



    // --- Arithmetic (binary) operators

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator+(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecAdd<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator+(const glbVec_T<S, T>& v, T scalar) noexcept
    {
        return glbIntern::vecAdd<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator+(T scalar, const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecAdd<S, T, glbIntern::useSimd<S, T>::value>::call(glbVec_T<S, T>(scalar), v);
    }


    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator-(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecSub<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator-(const glbVec_T<S, T>& v, T scalar) noexcept
    {
        return glbIntern::vecSub<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator-(T scalar, const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecSub<S, T, glbIntern::useSimd<S, T>::value>::call(glbVec_T<S, T>(scalar), v);
    }


    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator*(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecMul<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator*(const glbVec_T<S, T>& v, T scalar) noexcept
    {
        return glbIntern::vecMul<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator*(T scalar, const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecMul<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }


    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator/(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecDiv<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator/(const glbVec_T<S, T>& v, T scalar) noexcept
    {
        return glbIntern::vecDiv<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator/(T scalar, const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecDiv<S, T, glbIntern::useSimd<S, T>::value>::call(glbVec_T<S, T>(scalar), v);
    }


    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator%(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecMod<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator%(const glbVec_T<S, T>& v, T scalar) noexcept
    {
        return glbIntern::vecMod<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }




    // --- Bitwise operators

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator&(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecAnd<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator&(const glbVec_T<S, T>& v, T scalar) noexcept
    {
        return glbIntern::vecAnd<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator&(T scalar, const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecAnd<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator|(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecOr<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator|(const glbVec_T<S, T>& v, T scalar) noexcept
    {
        return glbIntern::vecOr<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator|(T scalar, const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecOr<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator^(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecXor<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator^(const glbVec_T<S, T>& v, T scalar) noexcept
    {
        return glbIntern::vecXor<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator^(T scalar, const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecXor<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator<<(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecShiftLeft<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator<<(const glbVec_T<S, T>& v, T scalar) noexcept
    {
        return glbIntern::vecShiftLeft<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator<<(T scalar, const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecShiftLeft<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator>>(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecShiftRight<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator>>(const glbVec_T<S, T>& v, T scalar) noexcept
    {
        return glbIntern::vecShiftRight<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }
    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator>>(T scalar, const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecShiftRight<S, T, glbIntern::useSimd<S, T>::value>::call(v, glbVec_T<S, T>(scalar));
    }




    template<int S, typename T>
    GLB_INLINE constexpr bool operator==(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecEqual<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr bool operator!=(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return !(a == b);
    }

    template<int S, typename T>
    GLB_INLINE constexpr bool operator<(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecLess<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr bool operator<=(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecLessOrEqual<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr bool operator>(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecGreater<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    GLB_INLINE constexpr bool operator>=(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
    {
        return glbIntern::vecGreaterOrEqual<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }




    // --- Unary Bitwise operators

    template<int S, typename T>
    GLB_INLINE constexpr glbVec_T<S, T> operator~(const glbVec_T<S, T>& v) noexcept
    {
        return glbIntern::vecNot<S, T, glbIntern::useSimd<S, T>::value>::call(v);
    }
}