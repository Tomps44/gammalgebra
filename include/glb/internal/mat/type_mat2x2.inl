namespace glb
{
    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>::glbMat_T(T x0, T y0,
                                           T x1, T y1) noexcept
    // : columns{colType(x0, y0), colType(x1, y1)}
    : columns{colType(x0, x1), colType(y0, y1)}
    {}

    // template<typename T>
    // GLB_INLINE constexpr glbMat_T<2, 2, T>::glbMat_T() noexcept
    // : columns{colType(1, 0), colType(0, 1)}
    // {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>::glbMat_T(T scalar) noexcept
    : columns{colType(scalar, 0), colType(0, scalar)}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>::glbMat_T(const colType& diag) noexcept
    : columns{colType(diag.x, 0), colType(0, diag.y)}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>::glbMat_T(const colType& col0, const colType& col1) noexcept
    : columns{col0, col1}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>::glbMat_T(const glbMat_T<2, 2, T>& m) noexcept
    : columns{colType(m[0]), colType(m[1])}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>::glbMat_T(const glbMat_T<3, 3, T>& m) noexcept
    : columns{colType(m[0][0], m[0][1]), colType(m[1][0], m[1][1])}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>::glbMat_T(const glbMat_T<4, 4, T>& m) noexcept
    : columns{colType(m[0][0], m[0][1]), colType(m[1][0], m[1][1])}
    {}





    template<typename T>
    GLB_INLINE constexpr typename glbMat_T<2, 2, T>::colType& glbMat_T<2, 2, T>::operator[](int i) 
    {
        return columns[i];
    }
    template<typename T>
    GLB_INLINE constexpr const typename glbMat_T<2, 2, T>::colType& glbMat_T<2, 2, T>::operator[](int i) const
    {
        return columns[i];
    }




    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>& glbMat_T<2, 2, T>::operator+=(const glbMat_T<2, 2, T>& m) noexcept
    {
        *this = *this + m;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>& glbMat_T<2, 2, T>::operator+=(T scalar) noexcept
    {
        *this = *this + scalar;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>& glbMat_T<2, 2, T>::operator-=(const glbMat_T<2, 2, T>& m) noexcept
    {
        *this = *this - m;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>& glbMat_T<2, 2, T>::operator-=(T scalar) noexcept
    {
        *this = *this - scalar;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>& glbMat_T<2, 2, T>::operator*=(const glbMat_T<2, 2, T>& m) noexcept
    {
        *this = *this * m;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>& glbMat_T<2, 2, T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbMat_T<2, 2, T>& glbMat_T<2, 2, T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }
}