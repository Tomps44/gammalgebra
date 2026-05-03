/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */




namespace tmx
{
    // --- Constructors ---

    template<typename T>
    TMX_INLINE constexpr dQuat<T>::dQuat() noexcept
    : real(quat<T>()), dual(quat<T>(0, 0, 0, 0))
    {}

    template<typename T>
    TMX_INLINE constexpr dQuat<T>::dQuat(const quat<T>& rot, const vec<3, T>& trsl) noexcept
    : real(rot), dual((static_cast<T>(0.5) * (quat<T>(0, trsl))) * rot)
    {}

    template<typename T>
    TMX_INLINE constexpr dQuat<T>::dQuat(const quat<T>& rot, const quat<T>& trsl) noexcept
    : real(rot), dual(trsl)
    {}

    template<typename T>
    TMX_INLINE constexpr dQuat<T>::dQuat(const quat<T>& rot) noexcept
    : real(rot), dual(quat<T>(0, 0, 0, 0))
    {}

    template<typename T>
    TMX_INLINE constexpr dQuat<T>::dQuat(const vec<3, T>& trsl) noexcept
    : real(quat<T>()), dual(quat<T>(0, trsl * static_cast<T>(0.5)))
    {}

    template<typename T>
    TMX_INLINE constexpr dQuat<T>::dQuat(const dQuat<T>& dq) noexcept
    : real(dq.real), dual(dq.dual)
    {}


    // --- Accessors ---

    template<typename T>
    TMX_INLINE constexpr quat<T>& dQuat<T>::operator[](size_t i)
    {
        return (&real)[i];
    }
    template<typename T>
    TMX_INLINE constexpr const quat<T>& dQuat<T>::operator[](size_t i) const
    {
        return (&real)[i];
    }


    // --- Reference operators

    template<typename T>
    TMX_INLINE constexpr dQuat<T>& dQuat<T>::operator+=(const dQuat<T>& dq) noexcept
    {
        *this = *this + dq;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr dQuat<T>& dQuat<T>::operator-=(const dQuat<T>& dq) noexcept
    {
        *this = *this - dq;

        return *this;
    }

    template<typename T>
    TMX_INLINE constexpr dQuat<T>& dQuat<T>::operator*=(const dQuat<T>& dq) noexcept
    {
        *this = *this * dq;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr dQuat<T>& dQuat<T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }

    template<typename T>
    TMX_INLINE constexpr dQuat<T>& dQuat<T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }


    // --- Unary operators

    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator+(const dQuat<T>& dq) noexcept
    {
        return dq;
    }
    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator-(const dQuat<T>& dq) noexcept
    {
        return dQuat<T>(-dq.real, -dq.dual);
    }


    // --- Operators ---


    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator+(const dQuat<T>& a, const dQuat<T>& b) noexcept
    {
        return dQuat<T>(a.real + b.real, a.dual + b.dual);
    }
    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator-(const dQuat<T>& a, const dQuat<T>& b) noexcept
    {
        return dQuat<T>(a.real - b.real, a.dual - b.dual);
    }


    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator*(const dQuat<T>& dq, T scalar) noexcept
    {
        return dQuat<T>(dq.real * scalar, dq.dual * scalar);
    }
    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator*(T scalar, const dQuat<T>& dq) noexcept
    {
        return dQuat<T>(dq.real * scalar, dq.dual * scalar);
    }
    template<typename T>
    TMX_INLINE constexpr dQuat<T> operator*(const dQuat<T>& a, const dQuat<T>& b) noexcept
    {
        return dQuat<T>(
            a.real * b.real,
            a.real * b.dual + a.dual * b.real
        );
    }
    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator*(const dQuat<T>& dq, const vec<3, T>& point) noexcept
    {
        // TODO

        // return dq.real * point + dq.translation();
    }


    template<typename T>
    TMX_INLINE constexpr vec<3, T> operator/(const dQuat<T>& dq, T scalar) noexcept
    {
        return dQuat<T>(dq.real / scalar, dq.dual / scalar);
    }

    

    template<typename T>
    TMX_INLINE constexpr bool operator==(const dQuat<T>& a, const dQuat<T>& b) noexcept
    {
        return a.real == b.real && a.dual == b.dual;
    }
    template<typename T>
    TMX_INLINE constexpr bool operator!=(const dQuat<T>& a, const dQuat<T>& b) noexcept
    {
        return !(a == b);
    }
}