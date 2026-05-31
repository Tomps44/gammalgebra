namespace tmx
{
    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>::mat(T x0, T y0,
                                           T x1, T y1) noexcept
    // : columns{colType(x0, y0), colType(x1, y1)}
    : columns{colType(x0, x1), colType(y0, y1)}
    {}

    // template<typename T>
    // TMX_INLINE constexpr mat<2, 2, T>::mat() noexcept
    // : columns{colType(1, 0), colType(0, 1)}
    // {}

    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>::mat(T scalar) noexcept
    : columns{colType(scalar, 0), colType(0, scalar)}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>::mat(const colType& v1, const colType& v2) noexcept
    // : columns{v1, v2}
    : columns{colType(v1.x, v2.x), colType(v1.y, v2.y)}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>::mat(const colType& diag) noexcept
    : columns{colType(diag.x, 0), colType(0, diag.y)}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>::mat(const mat<2, 2, T>& m) noexcept
    : columns{colType(m[0]), colType(m[1])}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>::mat(const mat<3, 3, T>& m) noexcept
    : columns{colType(m[0][0], m[0][1]), colType(m[1][0], m[1][1])}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>::mat(const mat<4, 4, T>& m) noexcept
    : columns{colType(m[0][0], m[0][1]), colType(m[1][0], m[1][1])}
    {}





    template<typename T>
    TMX_INLINE constexpr typename mat<2, 2, T>::colType& mat<2, 2, T>::operator[](int i) 
    {
        return columns[i];
    }
    template<typename T>
    TMX_INLINE constexpr const typename mat<2, 2, T>::colType& mat<2, 2, T>::operator[](int i) const
    {
        return columns[i];
    }




    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>& mat<2, 2, T>::operator+=(const mat<2, 2, T>& m) noexcept
    {
        *this = *this + m;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>& mat<2, 2, T>::operator+=(T scalar) noexcept
    {
        *this = *this + scalar;

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>& mat<2, 2, T>::operator-=(const mat<2, 2, T>& m) noexcept
    {
        *this = *this - m;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>& mat<2, 2, T>::operator-=(T scalar) noexcept
    {
        *this = *this - scalar;

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>& mat<2, 2, T>::operator*=(const mat<2, 2, T>& m) noexcept
    {
        *this = *this * m;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>& mat<2, 2, T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr mat<2, 2, T>& mat<2, 2, T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }
}