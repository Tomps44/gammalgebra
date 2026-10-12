/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */




namespace glb
{
    // --- Constructors ---

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>::glbDQuat_T() noexcept
    : real(glbQuat_T<T>()), dual(glbQuat_T<T>(0, 0, 0, 0))
    {}

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>::glbDQuat_T(const glbQuat_T<T>& rot, const glbVec_T<3, T>& trsl) noexcept
    : real(rot), dual((static_cast<T>(0.5) * (glbQuat_T<T>(0, trsl))) * rot)
    {}

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>::glbDQuat_T(const glbQuat_T<T>& rot, const glbQuat_T<T>& trsl) noexcept
    : real(rot), dual(trsl)
    {}

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>::glbDQuat_T(const glbQuat_T<T>& rot) noexcept
    : real(rot), dual(glbQuat_T<T>(0, 0, 0, 0))
    {}

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>::glbDQuat_T(const glbVec_T<3, T>& trsl) noexcept
    : real(glbQuat_T<T>()), dual(glbQuat_T<T>(0, trsl * static_cast<T>(0.5)))
    {}

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>::glbDQuat_T(const glbDQuat_T<T>& dq) noexcept
    : real(dq.real), dual(dq.dual)
    {}


    // --- Accessors ---

    template<typename T>
    GLB_INLINE constexpr glbQuat_T<T>& glbDQuat_T<T>::operator[](int i)
    {
        return (&real)[i];
    }
    template<typename T>
    GLB_INLINE constexpr const glbQuat_T<T>& glbDQuat_T<T>::operator[](int i) const
    {
        return (&real)[i];
    }


    // --- Reference operators

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>& glbDQuat_T<T>::operator+=(const glbDQuat_T<T>& dq) noexcept
    {
        *this = *this + dq;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>& glbDQuat_T<T>::operator-=(const glbDQuat_T<T>& dq) noexcept
    {
        *this = *this - dq;

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>& glbDQuat_T<T>::operator*=(const glbDQuat_T<T>& dq) noexcept
    {
        *this = *this * dq;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>& glbDQuat_T<T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T>& glbDQuat_T<T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }


    // --- Unary operators

    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator+(const glbDQuat_T<T>& dq) noexcept
    {
        return dq;
    }
    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator-(const glbDQuat_T<T>& dq) noexcept
    {
        return glbDQuat_T<T>(-dq.real, -dq.dual);
    }


    // --- Operators ---


    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator+(const glbDQuat_T<T>& a, const glbDQuat_T<T>& b) noexcept
    {
        return glbDQuat_T<T>(a.real + b.real, a.dual + b.dual);
    }
    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator-(const glbDQuat_T<T>& a, const glbDQuat_T<T>& b) noexcept
    {
        return glbDQuat_T<T>(a.real - b.real, a.dual - b.dual);
    }


    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator*(const glbDQuat_T<T>& dq, T scalar) noexcept
    {
        return glbDQuat_T<T>(dq.real * scalar, dq.dual * scalar);
    }
    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator*(T scalar, const glbDQuat_T<T>& dq) noexcept
    {
        return glbDQuat_T<T>(dq.real * scalar, dq.dual * scalar);
    }
    template<typename T>
    GLB_INLINE constexpr glbDQuat_T<T> operator*(const glbDQuat_T<T>& a, const glbDQuat_T<T>& b) noexcept
    {
        return glbDQuat_T<T>(
            a.real * b.real,
            a.real * b.dual + a.dual * b.real
        );
    }
    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T> operator*(const glbDQuat_T<T>& dq, const glbVec_T<3, T>& point) noexcept
    {
        // TODO

        // return dq.real * point + dq.translation();
    }


    template<typename T>
    GLB_INLINE constexpr glbVec_T<3, T> operator/(const glbDQuat_T<T>& dq, T scalar) noexcept
    {
        return glbDQuat_T<T>(dq.real / scalar, dq.dual / scalar);
    }

    

    template<typename T>
    GLB_INLINE constexpr bool operator==(const glbDQuat_T<T>& a, const glbDQuat_T<T>& b) noexcept
    {
        return a.real == b.real && a.dual == b.dual;
    }
    template<typename T>
    GLB_INLINE constexpr bool operator!=(const glbDQuat_T<T>& a, const glbDQuat_T<T>& b) noexcept
    {
        return !(a == b);
    }
}