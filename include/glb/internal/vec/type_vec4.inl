
#include "../compute/compute_vec.h"

namespace glb
{
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>::glbVec_T(T vx, T vy, T vz, T vw) noexcept
    : x(vx), y(vy), z(vz), w(vw)
    {}

    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>::glbVec_T(T scalar) noexcept
    : x(scalar), y(scalar), z(scalar), w(scalar)
    {}

    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>::glbVec_T(const glbVec_T<3, T>& xyz, T vw) noexcept
    : x(xyz.x), y(xyz.y), z(xyz.z), w(vw)
    {}

    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>::glbVec_T(const glbVec_T<2, T>& v) noexcept
    : x(v.x), y(v.y), z(static_cast<T>(0)), w(static_cast<T>(0))
    {}
    
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>::glbVec_T(const glbVec_T<4, T>& v) noexcept
    : x(v.x), y(v.y), z(v.z), w(v.w)
    {}




    template<typename T>
    GLB_INLINE constexpr T& glbVec_T<4, T>::operator[](int i)
    {
        return values[i];
    }
    template<typename T>
    GLB_INLINE constexpr const T& glbVec_T<4, T>::operator[](int i) const
    {
        return values[i];
    }


    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator+=(const glbVec_T<4, T>& v) noexcept
    {
        *this = *this + v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator+=(T scalar) noexcept
    {
        *this = *this + glbVec_T<4, T>(scalar);

        return *this;
    }



    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator-=(const glbVec_T<4, T>& v) noexcept
    {
        *this = *this - v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator-=(T scalar) noexcept
    {
        *this = *this - glbVec_T<4, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator*=(const glbVec_T<4, T>& v) noexcept
    {
        *this = *this * v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator*=(T scalar) noexcept
    {
        *this = *this * glbVec_T<4, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator/=(const glbVec_T<4, T>& v) noexcept
    {
        *this = *this / v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator/=(T scalar) noexcept
    {
        *this = *this / glbVec_T<4, T>(scalar);

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator%=(const glbVec_T<4, T>& v) noexcept
    {
        *this = *this % v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator%=(T scalar) noexcept
    {
        *this = *this % glbVec_T<4, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator&=(const glbVec_T<4, T>& v) noexcept
    {
        *this = *this & v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator&=(T scalar) noexcept
    {
        *this = *this & glbVec_T<4, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator|=(const glbVec_T<4, T>& v) noexcept
    {
        *this = *this | v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator|=(T scalar) noexcept
    {
        *this = *this | glbVec_T<4, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator^=(const glbVec_T<4, T>& v) noexcept
    {
        *this = *this ^ v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator^=(T scalar) noexcept
    {
        *this = *this ^ glbVec_T<4, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator<<=(const glbVec_T<4, T>& v) noexcept
    {
        *this = *this << v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator<<=(T scalar) noexcept
    {
        *this = *this << glbVec_T<4, T>(scalar);

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator>>=(const glbVec_T<4, T>& v) noexcept
    {
        *this = *this >> v;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<4, T>& glbVec_T<4, T>::operator>>=(T scalar) noexcept
    {
        *this = *this >> glbVec_T<4, T>(scalar);

        return *this;
    }
}

#if !defined(GLB_SIMD_NONE)
#    include "../simd/vec_compute_vec.inl"

#endif