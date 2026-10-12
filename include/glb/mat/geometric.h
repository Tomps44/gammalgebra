#pragma once

#include "../internal/type_mat.h"
#include "../internal/type_vec.h"

namespace glb
{
    namespace Mat
    {
        /**
         * @brief Calculates the determinant of the Matrix `m`.
         */
        template<int R, int C, typename T>
        GLB_INLINE constexpr T Determinant(const glbMat_T<R, C, T>& m) noexcept;

        /**
         * @brief Returns the transpose of the Matrix `m`, thus a Matrix of the same size.
         */
        template<int R, int C, typename T>
        GLB_INLINE constexpr glbMat_T<C, R, T> Transpose(const glbMat_T<R, C, T>& m) noexcept;

        /**
         * @brief Generates a Cross-Product Matrix from the Vec3 `v`.
         */
        template<int R, int C, typename T>
        GLB_INLINE constexpr glbMat_T<C, R, T> Cross(const glbVec_T<3, T>& v) noexcept;

    } // namespace Mat
    
} // namespace glb

#include "../internal/mat/compute_geometric.inl"