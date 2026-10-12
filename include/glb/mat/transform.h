#pragma once

#include "rotation.h"
#include "translate.h"
#include "scale.h"

#include "../internal/type_quat.h"
#include "../internal/type_vec.h"

namespace glb
{
    namespace Mat
    {
        /**
         * Generates a 4x4 matrix that is the result of multiplicating the three matrices constructed from `trsl`, `rot` and `scale`,
         * in the order : `translation * rotation * scale`.
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> TRS(const glbVec_T<3, T>& trsl, const glbQuat_T<T>& rot, const glbVec_T<3, T>& scale) noexcept;

        /**
         * Generates a 4x4 matrix that is the result of multiplicating the three matrices constructed from `trsl`, `rot` and `scale`,
         * in the order : `translation * rotation * scale`.
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> TRS(const glbVec_T<3, T>& trsl, const glbVec_T<3, T>& rot, const glbVec_T<3, T>& scale) noexcept;
    }

}

#include "../internal/mat/compute_transform.inl"