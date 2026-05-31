#pragma once

#include "tmx/internal/type_mat.hpp"
#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Mat
    {
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> Scale_3x3(const vec<3, T>& scale) noexcept;
        
        template<typename T>
        TMX_INLINE constexpr mat<4, 4, T> Scale_4x4(const vec<3, T>& scale) noexcept;



    } // namespace Mat
    
} // namespace tmx

#include "tmx/internal/mat/compute_scale.inl"