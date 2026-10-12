#include <limits>
#include "compute/compute_quat.h"

namespace glb
{
    // --- Constructors ---

    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T>::glbQuat_T(T qw, T qx, T qy, T qz) noexcept
    : w(qw), x(qx), y(qy), z(qz)
    {}

    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T>::glbQuat_T(T qw, const glbVec_T<3, T>& xyz) noexcept
    : w(qw), x(xyz.x), y(xyz.y), z(xyz.z)
    {}

    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T>::glbQuat_T(const glbQuat_T<T>& q) noexcept
    : w(q.w), x(q.x), y(q.y), z(q.z)
    {}

    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T>::glbQuat_T() noexcept
    : w(static_cast<T>(1)), x(static_cast<T>(0)), y(static_cast<T>(0)), z(static_cast<T>(0))
    {}

    // --- Accessors ---

    template<typename T>
    GLB_INLINE constexpr T& glbQuat_T<T>::operator[](int i) 
    {
        return (&w)[i];
    }
    template<typename T>
    GLB_INLINE constexpr const T glbQuat_T<T>::operator[](int i) const
    {
        return (&w)[i];
    }

    // --- Reference operators ---

    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T>& glbQuat_T<T>::operator+=(const glbQuat_T<T>& q) noexcept
    {
        *this = *this + q;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T>& glbQuat_T<T>::operator-=(const glbQuat_T<T>& q) noexcept
    {
        *this = *this - q;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T>& glbQuat_T<T>::operator*=(const glbQuat_T<T>& q) noexcept
    {
        *this = *this * q;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T>& glbQuat_T<T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T>& glbQuat_T<T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }

    // --- Unary operators ---

    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T> operator+(const glbQuat_T<T>& q) noexcept
    {
        return q;
    }
    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T> operator-(const glbQuat_T<T>& q) noexcept
    {
        return glbQuat_T<T>(-q.w, -q.x, -q.y, -q.z);
    }


    // --- Operators ---

    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T> operator+(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept
    {
        return glbIntern::quatAdd<T, glbIntern::useSimd<4, T>::value>::call(a, b);
    }
    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T> operator-(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept
    {
        return glbIntern::quatSub<T, glbIntern::useSimd<4, T>::value>::call(a, b);
    }

    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T> operator*(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept
    {
        
        return glbIntern::quatMul<T, glbIntern::useSimd<4, T>::value>::call(a, b);
    }
    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T> operator*(const glbQuat_T<T>& q, T scalar) noexcept
    {
        return glbIntern::quatMul<T, glbIntern::useSimd<4, T>::value>::call(q, scalar);
    }
    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T> operator*(T scalar, const glbQuat_T<T>& q) noexcept
    {
        return glbIntern::quatMul<T, glbIntern::useSimd<4, T>::value>::call(q, scalar);
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T> operator*(const glbQuat_T<T>& rot, const glbVec_T<3, T>& point) noexcept
    {
        const glbVec_T<3, T> u(rot.x, rot.y, rot.z);

        const glbVec_T<3, T> t = Vec::Cross(u, point) * static_cast<T>(2);


        return point + (t * rot.w) + Vec::Cross(u, t);
    }


    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T> operator/(const glbQuat_T<T>& q, T scalar) noexcept
    {
        return glbIntern::quatDiv<T, glbIntern::useSimd<4, T>::value>::call(q, scalar);
    }
    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T> operator/(T scalar, const glbQuat_T<T>& q) noexcept
    {
        return glbIntern::quatDiv<T, glbIntern::useSimd<4, T>::value>::call(scalar, q);
    }



    template<typename T>
    GLB_INLINE constexpr bool operator==(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept
    {
        return 
            glbIntern::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.x, b.x) &&
            glbIntern::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.y, b.y) &&
            glbIntern::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.z, b.z) &&
            glbIntern::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a.w, b.w);
    }
    template<typename T>
    GLB_INLINE constexpr bool operator!=(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept
    {
        return !(a == b); 
    }


}