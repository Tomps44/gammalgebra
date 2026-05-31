#pragma once

#include "tmx/internal/definitions.hpp"
#include "tmx/internal/type_mat.hpp"

namespace tmx
{
    template<typename T>
    struct TMX_ALIGN_(T) mat<2, 2, T>
    {
        typedef vec<2, T> colType;
        typedef vec<2, T> rowType;
        typedef mat<2, 2, T> transposeType;

    public:
        
        union 
        {
            colType columns[2];
            T indices[4];
        };


        TMX_INLINE constexpr mat(T x0, T y0, 
                                 T x1, T y1) noexcept;
        TMX_INLINE constexpr mat(T scalar = static_cast<T>(1.0)) noexcept;
        TMX_INLINE constexpr mat(const colType& v1, const colType& v2) noexcept;
        TMX_INLINE constexpr mat(const colType& diag) noexcept;
        TMX_INLINE constexpr mat(const mat<2, 2, T>& m) noexcept;
        TMX_INLINE constexpr mat(const mat<3, 3, T>& m) noexcept;
        TMX_INLINE constexpr mat(const mat<4, 4, T>& m) noexcept;


        TMX_INLINE constexpr const T* data() const noexcept { return &(columns[0].x); };


        TMX_INLINE constexpr explicit operator mat<3, 3, T>() const noexcept { return mat<3, 3, T>(*this); };
        TMX_INLINE constexpr explicit operator mat<4, 4, T>() const noexcept { return mat<4, 4, T>(*this); };


        TMX_INLINE constexpr colType& operator[](int i);
        TMX_INLINE constexpr const colType& operator[](int i) const;


        TMX_INLINE constexpr mat<2, 2, T>& operator=(const mat<2, 2, T>& m) noexcept = default;

        TMX_INLINE constexpr mat<2, 2, T>& operator+=(const mat<2, 2, T>& m) noexcept;
        TMX_INLINE constexpr mat<2, 2, T>& operator+=(T scalar) noexcept;

        TMX_INLINE constexpr mat<2, 2, T>& operator-=(const mat<2, 2, T>& m) noexcept;
        TMX_INLINE constexpr mat<2, 2, T>& operator-=(T scalar) noexcept;

        TMX_INLINE constexpr mat<2, 2, T>& operator*=(const mat<2, 2, T>& m) noexcept;
        TMX_INLINE constexpr mat<2, 2, T>& operator*=(T scalar) noexcept;

        TMX_INLINE constexpr mat<2, 2, T>& operator/=(T scalar) noexcept;
    };
}

#include "tmx/internal/mat/type_mat2x2.inl"