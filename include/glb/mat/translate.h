#pragma once

#include "../internal/type_mat.h"
#include "../internal/type_vec.h"

namespace glb
{
    namespace Mat
    {
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Translate(const glbVec_T<3, T>& trsl) noexcept;

    } // namespace Mat
    
} // namespace glb

#include "../internal/mat/compute_translate.inl"