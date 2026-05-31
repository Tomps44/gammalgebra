#include "tmx/internal/compute/compute_vec.hpp"
#include "type_vec2.hpp"

namespace tmx
{
    template<typename T>
    TMX_INLINE constexpr vec<2, T>::vec(T vx, T vy) noexcept
    : x(vx), y(vy)
    {}

    template<typename T>
    TMX_INLINE constexpr vec<2, T>::vec(T scalar) noexcept
    : x(scalar), y(scalar)
    {}

    template<typename T>
    TMX_INLINE constexpr vec<2, T>::vec(const vec<2, T>& v) noexcept
    : x(v.x), y(v.y)
    {}
    template<typename T>
    TMX_INLINE constexpr vec<2, T>::vec(const vec<3, T>& v) noexcept
    : x(v.x), y(v.y)
    {}
    template<typename T>
    TMX_INLINE constexpr vec<2, T>::vec(const vec<4, T>& v) noexcept
    : x(v.x), y(v.y)
    {}


    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator=(T scalar) noexcept
    {
        *this = vec<2, T>(scalar);
        return *this;
    }



    template<typename T>
    TMX_INLINE constexpr T& vec<2, T>::operator[](int i)
    {
        return values[i];
    }
    template<typename T>
    TMX_INLINE constexpr const T& vec<2, T>::operator[](int i) const
    {
        return values[i];
    }




    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator+=(const vec<2, T>& v) noexcept
    {
        *this = *this + v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator+=(T scalar) noexcept
    {
        *this = *this + vec<2, T>(scalar);

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator-=(const vec<2, T>& v) noexcept
    {
        *this = *this - v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator-=(T scalar) noexcept
    {
        *this = *this - vec<2, T>(scalar);

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator*=(const vec<2, T>& v) noexcept
    {
        *this = *this * v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator*=(T scalar) noexcept
    {
        *this = *this * vec<2, T>(scalar);

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator/=(const vec<2, T>& v) noexcept
    {
        *this = *this / v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator/=(T scalar) noexcept
    {
        *this = *this / vec<2, T>(scalar);

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator%=(const vec<2, T>& v) noexcept
    {
        *this = *this % v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator%=(T scalar) noexcept
    {
        *this = *this % vec<2, T>(scalar);

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator&=(const vec<2, T>& v) noexcept
    {
        *this = *this & v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator&=(T scalar) noexcept
    {
        *this = *this & vec<2, T>(scalar);

        return *this;
    }

    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator|=(const vec<2, T>& v) noexcept
    {
        *this = *this | v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator|=(T scalar) noexcept
    {
        *this = *this | vec<2, T>(scalar);

        return *this;
    }

    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator^=(const vec<2, T>& v) noexcept
    {
        *this = *this ^ v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator^=(T scalar) noexcept
    {
        *this = *this ^ vec<2, T>(scalar);

        return *this;
    }

    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator<<=(const vec<2, T>& v) noexcept
    {
        *this = *this << v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator<<=(T scalar) noexcept
    {
        *this = *this << vec<2, T>(scalar);

        return *this;
    }

    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator>>=(const vec<2, T>& v) noexcept
    {
        *this = *this >> v;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr vec<2, T>& vec<2, T>::operator>>=(T scalar) noexcept
    {
        *this = *this >> vec<2, T>(scalar);

        return *this;
    }
}