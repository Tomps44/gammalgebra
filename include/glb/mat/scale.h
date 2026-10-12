#pragma once

#include "../internal/type_mat.h"
#include "../internal/type_vec.h"

namespace glb
{
    namespace Mat
    {
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> Scale_3x3(const glbVec_T<3, T>& scale) noexcept;
        
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Scale_4x4(const glbVec_T<3, T>& scale) noexcept;



    } // namespace Mat
    
} // namespace glb

#include "../internal/mat/compute_scale.inl"