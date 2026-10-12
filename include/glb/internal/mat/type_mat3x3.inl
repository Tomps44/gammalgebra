namespace glb
{
    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>::glbMat_T(T x0, T y0, T z0,
                                           T x1, T y1, T z1,
                                           T x2, T y2, T z2) noexcept
    // : columns{colType(x0, y0, z0), colType(x1, y1, z1), colType(x2, y2, z2)}
    : columns{colType(x0, x1, x2), colType(y0, y1, y2), colType(z0, z1, z2)}
    {}

    // template<typename T>
    // GLB_INLINE constexpr glbMat_T<3, 3, T>::glbMat_T() noexcept
    // : columns{colType(1, 0, 0), colType(0, 1, 0), colType(0, 0, 1)}
    // {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>::glbMat_T(T scalar) noexcept
    : columns{colType(scalar, 0, 0), colType(0, scalar, 0), colType(0, 0, scalar)}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>::glbMat_T(const colType& diag) noexcept
    : columns{colType(diag.x, 0, 0), colType(0, diag.y, 0), colType(0, 0, diag.z)}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>::glbMat_T(const colType& col0, const colType& col1, const colType& col2) noexcept
    : columns{col0, col1, col2}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>::glbMat_T(const glbMat_T<3, 3, T>& m) noexcept
    : columns{colType(m[0]), colType(m[1]), colType(m[2])}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>::glbMat_T(const glbMat_T<2, 2, T>& m) noexcept
    : columns{colType(m[0][0], m[0][1], 0), colType(m[1][0], m[1][1], 0), colType(0, 0, 1)}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>::glbMat_T(const glbMat_T<4, 4, T>& m) noexcept
    : columns{colType(m[0][0], m[0][1], m[0][2]), colType(m[1][0], m[1][1], m[1][2]), colType(m[2][0], m[2][1], m[2][2])}
    {}





    template<typename T>
    GLB_INLINE constexpr typename glbMat_T<3, 3, T>::colType& glbMat_T<3, 3, T>::operator[](int i) 
    {
        return columns[i];
    }
    template<typename T>
    GLB_INLINE constexpr const typename glbMat_T<3, 3, T>::colType& glbMat_T<3, 3, T>::operator[](int i) const
    {
        return columns[i];
    }




    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>& glbMat_T<3, 3, T>::operator+=(const glbMat_T<3, 3, T>& m) noexcept
    {
        *this = *this + m;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>& glbMat_T<3, 3, T>::operator+=(T scalar) noexcept
    {
        *this = *this + scalar;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>& glbMat_T<3, 3, T>::operator-=(const glbMat_T<3, 3, T>& m) noexcept
    {
        *this = *this - m;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>& glbMat_T<3, 3, T>::operator-=(T scalar) noexcept
    {
        *this = *this - scalar;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>& glbMat_T<3, 3, T>::operator*=(const glbMat_T<3, 3, T>& m) noexcept
    {
        *this = *this * m;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>& glbMat_T<3, 3, T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbMat_T<3, 3, T>& glbMat_T<3, 3, T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }
}