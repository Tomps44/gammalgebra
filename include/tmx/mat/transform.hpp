#pragma once

#include "tmx/mat/rotation.hpp"
#include "tmx/mat/translate.hpp"
#include "tmx/mat/scale.hpp"

#include "tmx/internal/type_quat.hpp"
#include "tmx/internal/type_vec.hpp"

namespace tmx
{
    namespace Mat
    {
        template<typename T>
        TMX_INLINE constexpr mat<4, 4, T> TRS(const vec<3, T>& trsl, const quat<T>& rot, const vec<3, T>& scale) noexcept;

        template<typename T>
        TMX_INLINE constexpr mat<4, 4, T> TRS(const vec<3, T>& trsl, const vec<3, T>& rot, const vec<3, T>& scale) noexcept;
    }

}

#include "tmx/internal/mat/compute_transform.inl"