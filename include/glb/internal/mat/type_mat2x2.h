#pragma once

#include "../definitions.h"
#include "../type_mat.h"

namespace glb
{
    template<typename T>
    struct alignas(sizeof(T) * 4) glbMat_T<2, 2, T>
    {
        typedef glbVec_T<2, T> colType;
        typedef glbVec_T<2, T> rowType;
        typedef glbMat_T<2, 2, T> transposeType;

    public:
        
        union 
        {
            colType columns[2];
            T indices[4];
        };


        /**
         * @brief The first row of parameters (x0, y0) is the first column, same thing for the second row.
         */
        GLB_INLINE explicit constexpr glbMat_T(T x0, T y0, 
                                 T x1, T y1) noexcept;
        /**
         * @brief Sets the 2 values in the column to `scalar`, and the rest to 0.
         */
        GLB_INLINE explicit constexpr glbMat_T(T scalar = static_cast<T>(1.0)) noexcept;
        /**
         * @brief Sets the values in the column to `diag`.
         */
        GLB_INLINE explicit constexpr glbMat_T(const colType& diag) noexcept;
        /**
         * @brief Sets the first column to `col0`, and the second column to `col1`.
         */
        GLB_INLINE explicit constexpr glbMat_T(const colType& col0, const colType& col1) noexcept;
        /**
         * @brief Copy constructor.
         */
        GLB_INLINE constexpr glbMat_T(const glbMat_T<2, 2, T>& m) noexcept;
        /**
         * @brief Sets the matrix values to the top 2x2 matrix of `m`.
         */
        GLB_INLINE explicit constexpr glbMat_T(const glbMat_T<3, 3, T>& m) noexcept;
        /**
         * @brief Sets the matrix values to the top 2x2 matrix of `m`.
         */
        GLB_INLINE explicit constexpr glbMat_T(const glbMat_T<4, 4, T>& m) noexcept;


        /**
         * Returns a const pointer to the first element (mat[0][0]) of the matrix.
         */
        GLB_INLINE constexpr const T* data() const noexcept { return &(columns[0].x); };

        GLB_INLINE constexpr const glbVec_T<2, T> GetRow(int index) { return glbVec_T<2, T>(columns[0][index], columns[1][index]); }; 
        GLB_INLINE constexpr void SetRow(int index, const glbVec_T<2, T>& v) { columns[0][index] = v.x; columns[1][index] = v.y; }; 

        GLB_INLINE constexpr explicit operator glbMat_T<3, 3, T>() const noexcept { return glbMat_T<3, 3, T>(*this); };
        GLB_INLINE constexpr explicit operator glbMat_T<4, 4, T>() const noexcept { return glbMat_T<4, 4, T>(*this); };


        GLB_INLINE constexpr colType& operator[](int i);
        GLB_INLINE constexpr const colType& operator[](int i) const;


        GLB_INLINE constexpr glbMat_T<2, 2, T>& operator=(const glbMat_T<2, 2, T>& m) noexcept = default;

        GLB_INLINE constexpr glbMat_T<2, 2, T>& operator+=(const glbMat_T<2, 2, T>& m) noexcept;
        GLB_INLINE constexpr glbMat_T<2, 2, T>& operator+=(T scalar) noexcept;

        GLB_INLINE constexpr glbMat_T<2, 2, T>& operator-=(const glbMat_T<2, 2, T>& m) noexcept;
        GLB_INLINE constexpr glbMat_T<2, 2, T>& operator-=(T scalar) noexcept;

        GLB_INLINE constexpr glbMat_T<2, 2, T>& operator*=(const glbMat_T<2, 2, T>& m) noexcept;
        GLB_INLINE constexpr glbMat_T<2, 2, T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr glbMat_T<2, 2, T>& operator/=(T scalar) noexcept;
    };
}

#include "type_mat2x2.inl"