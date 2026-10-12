#pragma once

#include "../internal/type_mat.h"
#include "../internal/type_vec.h"

namespace glb
{
    namespace glbDetail
    {
        /**
         * Generates a `left-handed` view matrix 
         * 
         * @param eye The position of the eye (camera)
         * @param target The position of the object to look at
         * @param worldUp The normalized vector representing the direction of the up axis in world space
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> LookAt_LH(const glbVec_T<3, T>& eye, const glbVec_T<3, T>& target, const glbVec_T<3, T>& worldUp) noexcept;

        /**
         * Generates a `right-handed` view matrix 
         * 
         * @param eye The position of the eye (camera)
         * @param target The position of the object to look at
         * @param worldUp The normalized vector representing the direction of the up axis in world space
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> LookAt_RH(const glbVec_T<3, T>& eye, const glbVec_T<3, T>& target, const glbVec_T<3, T>& worldUp) noexcept;
        
    } // namespace glbDetail

    namespace Mat
    {
        /**
         * Generates a view matrix from `eye`, the position of the object looking, 
         * `target`, the position of the object eye is looking at, 
         * and `worldUp`, the world up vector.
         * 
         * @attention 
         * The coordinate system used to generate the matrix is the one specified by GLB_SET_COORDINATE_SYSTEM_...
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> LookAt(const glbVec_T<3, T>& eye, const glbVec_T<3, T>& target, const glbVec_T<3, T>& worldUp) noexcept;

    } // namespace Mat
    
} // namespace glb

#include "../internal/mat/compute_view.inl"