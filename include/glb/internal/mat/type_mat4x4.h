#pragma once

#include "../definitions.h"
#include "../type_mat.h"

namespace glb
{
    template<typename T>
    struct alignas(sizeof(T) * 4) glbMat_T<4, 4, T>
    {
        typedef glbVec_T<4, T> colType;
        typedef glbVec_T<4, T> rowType;
        typedef glbMat_T<4, 4, T> transposeType;

    public:
        
        union 
        {
            colType columns[4];
            T indices[16];
        };


        GLB_INLINE explicit constexpr glbMat_T(T x0, T y0, T z0, T w0,
                                 T x1, T y1, T z1, T w1,
                                 T x2, T y2, T z2, T w2,
                                 T x3, T y3, T z3, T w3) noexcept;
        GLB_INLINE explicit constexpr glbMat_T(T scalar = static_cast<T>(1.0)) noexcept;
        GLB_INLINE explicit constexpr glbMat_T(const colType& diag) noexcept;
        GLB_INLINE explicit constexpr glbMat_T(const colType& col0, const colType& col1, const colType& col2, const colType& col3) noexcept;
        GLB_INLINE explicit constexpr glbMat_T(const glbMat_T<2, 2, T>& m) noexcept;
        GLB_INLINE explicit constexpr glbMat_T(const glbMat_T<3, 3, T>& m) noexcept;
        GLB_INLINE constexpr glbMat_T(const glbMat_T<4, 4, T>& m) noexcept;


        GLB_INLINE constexpr const T* data() const noexcept { return &(columns[0].x); };


        GLB_INLINE constexpr const glbVec_T<4, T> GetRow(int index) { return glbVec_T<4, T>(columns[0][index], columns[1][index], columns[2][index], columns[3][index]); }; 
        GLB_INLINE constexpr void SetRow(int index, const glbVec_T<4, T>& v) { columns[0][index] = v.x; columns[1][index] = v.y; columns[2][index] = v.z; columns[3][index] = v.w; }; 


        GLB_INLINE constexpr explicit operator glbMat_T<2, 2, T>() const noexcept { return glbMat_T<2, 2, T>(*this); };
        GLB_INLINE constexpr explicit operator glbMat_T<3, 3, T>() const noexcept { return glbMat_T<3, 3, T>(*this); };


        GLB_INLINE constexpr colType& operator[](int i);
        GLB_INLINE constexpr const colType& operator[](int i) const;


        GLB_INLINE constexpr glbMat_T<4, 4, T>& operator=(const glbMat_T<4, 4, T>& m) noexcept = default;

        
        GLB_INLINE constexpr glbMat_T<4, 4, T>& operator+=(const glbMat_T<4, 4, T>& m) noexcept;
        GLB_INLINE constexpr glbMat_T<4, 4, T>& operator+=(T scalar) noexcept;

        GLB_INLINE constexpr glbMat_T<4, 4, T>& operator-=(const glbMat_T<4, 4, T>& m) noexcept;
        GLB_INLINE constexpr glbMat_T<4, 4, T>& operator-=(T scalar) noexcept;

        GLB_INLINE constexpr glbMat_T<4, 4, T>& operator*=(const glbMat_T<4, 4, T>& m) noexcept;
        GLB_INLINE constexpr glbMat_T<4, 4, T>& operator*=(T scalar) noexcept;

        GLB_INLINE constexpr glbMat_T<4, 4, T>& operator/=(T scalar) noexcept;
    };
}

#include "type_mat4x4.inl"