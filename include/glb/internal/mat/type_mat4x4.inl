namespace glb
{
    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>::glbMat_T(T x0, T y0, T z0, T w0,
                                           T x1, T y1, T z1, T w1,
                                           T x2, T y2, T z2, T w2,
                                           T x3, T y3, T z3, T w3) noexcept
    // : columns{colType(x0, y0, z0, w0), colType(x1, y1, z1, w1), colType(x2, y2, z2, w2), colType(x3, y3, z3, w3)}
    : columns{colType(x0, x1, x2, x3), colType(y0, y1, y2, y3), colType(z0, z1, z2, z3), colType(w0, w1, w2, w3)}
    {}

    // template<typename T>
    // GLB_INLINE constexpr glbMat_T<4, 4, T>::glbMat_T() noexcept
    // : columns{colType(1, 0, 0, 0), colType(0, 1, 0, 0), colType(0, 0, 1, 0), colType(0, 0, 0, 1)}
    // {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>::glbMat_T(T scalar) noexcept
    : columns{colType(scalar, 0, 0, 0), colType(0, scalar, 0, 0), colType(0, 0, scalar, 0), colType(0, 0, 0, scalar)}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>::glbMat_T(const colType& diag) noexcept
    : columns{colType(diag.x, 0, 0, 0), colType(0, diag.y, 0, 0), colType(0, 0, diag.z, 0), colType(0, 0, 0, diag.w)}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>::glbMat_T(const colType& col0, const colType& col1, const colType& col2, const colType& col3) noexcept
    : columns{col0, col1, col2, col3}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>::glbMat_T(const glbMat_T<4, 4, T>& m) noexcept
    : columns{colType(m[0]), colType(m[1]), colType(m[2]), colType(m[3])}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>::glbMat_T(const glbMat_T<2, 2, T>& m) noexcept
    : columns{colType(m[0][0], m[0][1], 0, 0), colType(m[1][0], m[1][1], 0, 0), colType(0), colType(0, 0, 0, 1)}
    {}

    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>::glbMat_T(const glbMat_T<3, 3, T>& m) noexcept
    : columns{colType(m[0][0], m[0][1], m[0][2], 0), colType(m[1][0], m[1][1], m[1][2], 0), colType(m[2][0], m[2][1], m[2][2], 0), colType(0, 0, 0, 1)}
    {}





    template<typename T>
    GLB_INLINE constexpr typename glbMat_T<4, 4, T>::colType& glbMat_T<4, 4, T>::operator[](int i) 
    {
        return columns[i];
    }
    template<typename T>
    GLB_INLINE constexpr const typename glbMat_T<4, 4, T>::colType& glbMat_T<4, 4, T>::operator[](int i) const
    {
        return columns[i];
    }




    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>& glbMat_T<4, 4, T>::operator+=(const glbMat_T<4, 4, T>& m) noexcept
    {
        *this = *this + m;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>& glbMat_T<4, 4, T>::operator+=(T scalar) noexcept
    {
        *this = *this + scalar;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>& glbMat_T<4, 4, T>::operator-=(const glbMat_T<4, 4, T>& m) noexcept
    {
        *this = *this - m;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>& glbMat_T<4, 4, T>::operator-=(T scalar) noexcept
    {
        *this = *this - scalar;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>& glbMat_T<4, 4, T>::operator*=(const glbMat_T<4, 4, T>& m) noexcept
    {
        *this = *this * m;

        return *this;
    }
    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>& glbMat_T<4, 4, T>::operator*=(T scalar) noexcept
    {
        *this = *this * scalar;

        return *this;
    }


    template<typename T>
    GLB_INLINE constexpr glbMat_T<4, 4, T>& glbMat_T<4, 4, T>::operator/=(T scalar) noexcept
    {
        *this = *this / scalar;

        return *this;
    }
}


#if !defined(GLB_SIMD_NONE)
#    include "../simd/mat_compute_mat.inl"

#endif