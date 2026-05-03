#pragma once

#include "tmx/internal/definitions.hpp"
#include "tmx/internal/type_mat.hpp"

namespace tmx
{
    template<typename T>
    struct mat<2, 2, T>
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
        // TMX_INLINE constexpr mat() noexcept;
        TMX_INLINE constexpr mat(T scalar = static_cast<T>(1.0)) noexcept;
        TMX_INLINE constexpr mat(const colType& v1, const colType& v2) noexcept;
        TMX_INLINE constexpr mat(const mat<2, 2, T>& m) noexcept;


        TMX_INLINE constexpr colType& operator[](size_t i);
        TMX_INLINE constexpr const colType& operator[](size_t i) const;


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