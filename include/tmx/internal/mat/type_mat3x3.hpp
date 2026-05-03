#pragma once

#include "tmx/internal/definitions.hpp"
#include "tmx/internal/type_mat.hpp"

namespace tmx
{
    template<typename T>
    struct mat<3, 3, T>
    {
        typedef vec<3, T> colType;
        typedef vec<3, T> rowType;
        typedef mat<3, 3, T> transposeType;

    public:
        
        union 
        {
            colType columns[3];
            T indices[9];
        };


        TMX_INLINE constexpr mat(T x0, T y0, T z0,
                                 T x1, T y1, T z1,
                                 T x2, T y2, T z2) noexcept;
        // TMX_INLINE constexpr mat() noexcept;
        TMX_INLINE constexpr mat(T scalar = static_cast<T>(1.0)) noexcept;
        TMX_INLINE constexpr mat(const colType& v1, const colType& v2, const colType& v3) noexcept;
        TMX_INLINE constexpr mat(const mat<3, 3, T>& m) noexcept;


        TMX_INLINE constexpr colType& operator[](size_t i);
        TMX_INLINE constexpr const colType& operator[](size_t i) const;


        TMX_INLINE constexpr mat<3, 3, T>& operator=(const mat<3, 3, T>& m) noexcept = default;

        TMX_INLINE constexpr mat<3, 3, T>& operator+=(const mat<3, 3, T>& m) noexcept;
        TMX_INLINE constexpr mat<3, 3, T>& operator+=(T scalar) noexcept;

        TMX_INLINE constexpr mat<3, 3, T>& operator-=(const mat<3, 3, T>& m) noexcept;
        TMX_INLINE constexpr mat<3, 3, T>& operator-=(T scalar) noexcept;

        TMX_INLINE constexpr mat<3, 3, T>& operator*=(const mat<3, 3, T>& m) noexcept;
        TMX_INLINE constexpr mat<3, 3, T>& operator*=(T scalar) noexcept;

        TMX_INLINE constexpr mat<3, 3, T>& operator/=(T scalar) noexcept;
    };
}

#include "tmx/internal/mat/type_mat3x3.inl"