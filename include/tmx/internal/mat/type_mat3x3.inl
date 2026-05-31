namespace tmx
{
    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>::mat(T x0, T y0, T z0,
                                           T x1, T y1, T z1,
                                           T x2, T y2, T z2) noexcept
    // : columns{colType(x0, y0, z0), colType(x1, y1, z1), colType(x2, y2, z2)}
    : columns{colType(x0, x1, x2), colType(y0, y1, y2), colType(z0, z1, z2)}
    {}

    // template<typename T>
    // TMX_INLINE constexpr mat<3, 3, T>::mat() noexcept
    // : columns{colType(1, 0, 0), colType(0, 1, 0), colType(0, 0, 1)}
    // {}

    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>::mat(T scalar) noexcept
    : columns{colType(scalar, 0, 0), colType(0, scalar, 0), colType(0, 0, scalar)}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>::mat(const colType& v1, const colType& v2, const colType& v3) noexcept
    // : columns{v1, v2, v3}
    : columns{colType(v1.x, v2.x, v3.x), colType(v1.y, v2.y, v3.y), colType(v1.z, v2.z, v3.z)}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>::mat(const colType& diag) noexcept
    : columns{colType(diag.x, 0, 0), colType(0, diag.y, 0), colType(0, 0, diag.z)}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>::mat(const mat<3, 3, T>& m) noexcept
    : columns{colType(m[0]), colType(m[1]), colType(m[2])}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>::mat(const mat<2, 2, T>& m) noexcept
    : columns{colType(m[0][0], m[0][1], 0), colType(m[1][0], m[1][1], 0), colType(0, 0, 1)}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>::mat(const mat<4, 4, T>& m) noexcept
    : columns{colType(m[0][0], m[0][1], m[0][2]), colType(m[1][0], m[1][1], m[1][2]), colType(m[2][0], m[2][1], m[2][2])}
    {}





    template<typename T>
    TMX_INLINE constexpr typename mat<3, 3, T>::colType& mat<3, 3, T>::operator[](int i) 
    {
        return columns[i];
    }
    template<typename T>
    TMX_INLINE constexpr const typename mat<3, 3, T>::colType& mat<3, 3, T>::operator[](int i) const
    {
        return columns[i];
    }




    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>& mat<3, 3, T>::operator+=(const mat<3, 3, T>& m) noexcept
    {
        *this = *this + m;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>& mat<3, 3, T>::operator+=(T scalar) noexcept
    {
        *this = *this + scalar;

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>& mat<3, 3, T>::operator-=(const mat<3, 3, T>& m) noexcept
    {
        *this = *this - m;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>& mat<3, 3, T>::operator-=(T scalar) noexcept
    {
        *this = *this - scalar;

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>& mat<3, 3, T>::operator*=(const mat<3, 3, T>& m) noexcept
    {
        *this = *this * m;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>& mat<3, 3, T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr mat<3, 3, T>& mat<3, 3, T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }
}