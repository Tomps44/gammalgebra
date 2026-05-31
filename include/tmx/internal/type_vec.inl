
#include "tmx/internal/compute/compute_vec.hpp"
#include <limits>

namespace tmx
{
    // --- Unary operators ---

    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator+(const vec<S, T>& v) noexcept
    {
        return v;
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator-(const vec<S, T>& v) noexcept
    {
        return internal::vecNeg<S, T, internal::useSimd<S, T>::value>::call(v);
    }



    // --- Arithmetic (binary) operators

    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator+(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecAdd<S, T, internal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator+(const vec<S, T>& v, T scalar) noexcept
    {
        return internal::vecAdd<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator+(T scalar, const vec<S, T>& v) noexcept
    {
        return internal::vecAdd<S, T, internal::useSimd<S, T>::value>::call(vec<S, T>(scalar), v);
    }


    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator-(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecSub<S, T, internal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator-(const vec<S, T>& v, T scalar) noexcept
    {
        return internal::vecSub<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator-(T scalar, const vec<S, T>& v) noexcept
    {
        return internal::vecSub<S, T, internal::useSimd<S, T>::value>::call(vec<S, T>(scalar), v);
    }


    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator*(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecMul<S, T, internal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator*(const vec<S, T>& v, T scalar) noexcept
    {
        return internal::vecMul<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator*(T scalar, const vec<S, T>& v) noexcept
    {
        return internal::vecMul<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }


    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator/(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecDiv<S, T, internal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator/(const vec<S, T>& v, T scalar) noexcept
    {
        return internal::vecDiv<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator/(T scalar, const vec<S, T>& v) noexcept
    {
        return internal::vecDiv<S, T, internal::useSimd<S, T>::value>::call(vec<S, T>(scalar), v);
    }


    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator%(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecMod<S, T, internal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator%(const vec<S, T>& v, T scalar) noexcept
    {
        return internal::vecMod<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }




    // --- Bitwise operators

    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator&(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecAnd<S, T, internal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator&(const vec<S, T>& v, T scalar) noexcept
    {
        return internal::vecAnd<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator&(T scalar, const vec<S, T>& v) noexcept
    {
        return internal::vecAnd<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }

    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator|(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecOr<S, T, internal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator|(const vec<S, T>& v, T scalar) noexcept
    {
        return internal::vecOr<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator|(T scalar, const vec<S, T>& v) noexcept
    {
        return internal::vecOr<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }

    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator^(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecXor<S, T, internal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator^(const vec<S, T>& v, T scalar) noexcept
    {
        return internal::vecXor<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator^(T scalar, const vec<S, T>& v) noexcept
    {
        return internal::vecXor<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }

    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator<<(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecShiftLeft<S, T, internal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator<<(const vec<S, T>& v, T scalar) noexcept
    {
        return internal::vecShiftLeft<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator<<(T scalar, const vec<S, T>& v) noexcept
    {
        return internal::vecShiftLeft<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }

    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator>>(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecShiftRight<S, T, internal::useSimd<S, T>::value>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator>>(const vec<S, T>& v, T scalar) noexcept
    {
        return internal::vecShiftRight<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }
    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator>>(T scalar, const vec<S, T>& v) noexcept
    {
        return internal::vecShiftRight<S, T, internal::useSimd<S, T>::value>::call(v, vec<S, T>(scalar));
    }




    template<int S, typename T>
    TMX_INLINE constexpr bool operator==(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecEqual<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr bool operator!=(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return !(a == b);
    }

    template<int S, typename T>
    TMX_INLINE constexpr bool operator<(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecLess<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr bool operator<=(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecLessOrEqual<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr bool operator>(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecGreater<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }
    template<int S, typename T>
    TMX_INLINE constexpr bool operator>=(const vec<S, T>& a, const vec<S, T>& b) noexcept
    {
        return internal::vecGreaterOrEqual<S, T, std::numeric_limits<T>::is_iec559>::call(a, b);
    }




    // --- Unary Bitwise operators

    template<int S, typename T>
    TMX_INLINE constexpr vec<S, T> operator~(const vec<S, T>& v) noexcept
    {
        return internal::vecNot<S, T, internal::useSimd<S, T>::value>::call(v);
    }
}