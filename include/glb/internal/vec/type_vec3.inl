
#include "../compute/compute_vec.h"

namespace glb
{
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>::glbVec_T(T vx, T vy, T vz) noexcept
    : x(vx), y(vy), z(vz)
    {}

    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>::glbVec_T(T scalar) noexcept
    : x(scalar), y(scalar), z(scalar)
    {}

    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>::glbVec_T(const glbVec_T<2, T>& xy, T vz) noexcept
    : x(xy.x), y(xy.y), z(vz)
    {}

    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>::glbVec_T(const glbVec_T<3, T>& v) noexcept
    : x(v.x), y(v.y), z(v.z)
    {}
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>::glbVec_T(const glbVec_T<4, T>& v) noexcept
    : x(v.x), y(v.y), z(v.z)
    {}



    


    template<typename T>
    GLB_INLINE constexpr T& glbVec_T<3, T>::operator[](int i)
    {
        return values[i];
    }
    template<typename T>
    GLB_INLINE constexpr const T& glbVec_T<3, T>::operator[](int i) const
    {
        return values[i];
    }


    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator+=(const glbVec_T<3, T>& v) noexcept
    {
        *this = *this + v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator+=(T scalar) noexcept
    {
        *this = *this + glbVec_T<3, T>(scalar);

        return *this;
    }



    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator-=(const glbVec_T<3, T>& v) noexcept
    {
        *this = *this - v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator-=(T scalar) noexcept
    {
        *this = *this - glbVec_T<3, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator*=(const glbVec_T<3, T>& v) noexcept
    {
        *this = *this * v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator*=(T scalar) noexcept
    {
        *this = *this * glbVec_T<3, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator/=(const glbVec_T<3, T>& v) noexcept
    {
        *this = *this / v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator/=(T scalar) noexcept
    {
        *this = *this / glbVec_T<3, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator%=(const glbVec_T<3, T>& v) noexcept
    {
        *this = *this % v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator%=(T scalar) noexcept
    {
        *this = *this % glbVec_T<3, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator&=(const glbVec_T<3, T>& v) noexcept
    {
        *this = *this & v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator&=(T scalar) noexcept
    {
        *this = *this & glbVec_T<3, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator|=(const glbVec_T<3, T>& v) noexcept
    {
        *this = *this | v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator|=(T scalar) noexcept
    {
        *this = *this | glbVec_T<3, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator^=(const glbVec_T<3, T>& v) noexcept
    {
        *this = *this ^ v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator^=(T scalar) noexcept
    {
        *this = *this ^ glbVec_T<3, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator<<=(const glbVec_T<3, T>& v) noexcept
    {
        *this = *this << v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator<<=(T scalar) noexcept
    {
        *this = *this << glbVec_T<3, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator>>=(const glbVec_T<3, T>& v) noexcept
    {
        *this = *this >> v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T>& glbVec_T<3, T>::operator>>=(T scalar) noexcept
    {
        *this = *this >> glbVec_T<3, T>(scalar);

        return *this;
    }
}