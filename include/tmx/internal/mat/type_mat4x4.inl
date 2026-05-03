namespace tmx
{
    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>::mat(T x0, T y0, T z0, T w0,
                                           T x1, T y1, T z1, T w1,
                                           T x2, T y2, T z2, T w2,
                                           T x3, T y3, T z3, T w3) noexcept
    // : columns{colType(x0, y0, z0, w0), colType(x1, y1, z1, w1), colType(x2, y2, z2, w2), colType(x3, y3, z3, w3)}
    : columns{colType(x0, x1, x2, x3), colType(y0, y1, y2, y3), colType(z0, z1, z2, z3), colType(w0, w1, w2, w3)}
    {}

    // template<typename T>
    // TMX_INLINE constexpr mat<4, 4, T>::mat() noexcept
    // : columns{colType(1, 0, 0, 0), colType(0, 1, 0, 0), colType(0, 0, 1, 0), colType(0, 0, 0, 1)}
    // {}

    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>::mat(T scalar) noexcept
    : columns{colType(scalar, 0, 0, 0), colType(0, scalar, 0, 0), colType(0, 0, scalar, 0), colType(0, 0, 0, scalar)}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>::mat(const colType& v1, const colType& v2, const colType& v3, const colType& v4) noexcept
    // : columns{v1, v2, v3, v4}
    : columns{colType(v1.x, v2.x, v3.x, v4.x), colType(v1.y, v2.y, v3.y, v4.y), colType(v1.z, v2.z, v3.z, v4.z), colType(v1.w, v2.w, v3.w, v4.w)}
    {}

    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>::mat(const mat<4, 4, T>& m) noexcept
    : columns{colType(m[0]), colType(m[1]), colType(m[2]), colType(m[3])}
    {}





    template<typename T>
    TMX_INLINE constexpr typename mat<4, 4, T>::colType& mat<4, 4, T>::operator[](size_t i) 
    {
        return columns[i];
    }
    template<typename T>
    TMX_INLINE constexpr const typename mat<4, 4, T>::colType& mat<4, 4, T>::operator[](size_t i) const
    {
        return columns[i];
    }




    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>& mat<4, 4, T>::operator+=(const mat<4, 4, T>& m) noexcept
    {
        *this = *this + m;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>& mat<4, 4, T>::operator+=(T scalar) noexcept
    {
        *this = *this + scalar;

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>& mat<4, 4, T>::operator-=(const mat<4, 4, T>& m) noexcept
    {
        *this = *this - m;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>& mat<4, 4, T>::operator-=(T scalar) noexcept
    {
        *this = *this - scalar;

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>& mat<4, 4, T>::operator*=(const mat<4, 4, T>& m) noexcept
    {
        *this = *this * m;

        return *this;
    }
    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>& mat<4, 4, T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }


    template<typename T>
    TMX_INLINE constexpr mat<4, 4, T>& mat<4, 4, T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }
}