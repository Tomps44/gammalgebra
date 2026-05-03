#pragma once

#include "tmx/internal/definitions.hpp"
#include "tmx/internal/type_mat.hpp"

namespace tmx
{
    template<typename T>
    struct mat<4, 4, T>
    {
        typedef vec<4, T> colType;
        typedef vec<4, T> rowType;
        typedef mat<4, 4, T> transposeType;

    public:
        
        union 
        {
            colType columns[4];
            // T indices[16];
        };


        TMX_INLINE constexpr mat(T x0, T y0, T z0, T w0,
                                 T x1, T y1, T z1, T w1,
                                 T x2, T y2, T z2, T w2,
                                 T x3, T y3, T z3, T w3) noexcept;
        // TMX_INLINE constexpr mat() noexcept;
        TMX_INLINE constexpr mat(T scalar = static_cast<T>(1.0)) noexcept;
        TMX_INLINE constexpr mat(const colType& v1, const colType& v2, const colType& v3, const colType& v4) noexcept;
        TMX_INLINE constexpr mat(const mat<4, 4, T>& m) noexcept;


        TMX_INLINE constexpr colType& operator[](size_t i);
        TMX_INLINE constexpr const colType& operator[](size_t i) const;


        TMX_INLINE constexpr mat<4, 4, T>& operator=(const mat<4, 4, T>& m) noexcept = default;

        TMX_INLINE constexpr mat<4, 4, T>& operator+=(const mat<4, 4, T>& m) noexcept;
        TMX_INLINE constexpr mat<4, 4, T>& operator+=(T scalar) noexcept;

        TMX_INLINE constexpr mat<4, 4, T>& operator-=(const mat<4, 4, T>& m) noexcept;
        TMX_INLINE constexpr mat<4, 4, T>& operator-=(T scalar) noexcept;

        TMX_INLINE constexpr mat<4, 4, T>& operator*=(const mat<4, 4, T>& m) noexcept;
        TMX_INLINE constexpr mat<4, 4, T>& operator*=(T scalar) noexcept;

        TMX_INLINE constexpr mat<4, 4, T>& operator/=(T scalar) noexcept;
    };
}

#include "tmx/internal/mat/type_mat4x4.inl"