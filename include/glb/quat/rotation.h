#pragma once

#include "../internal/type_quat.h"
#include "../internal/type_vec.h"
#include "../internal/type_mat.h"

namespace glb
{
    namespace Qua
    {
        /**
         * Rotates `point` counter-clockwise by the rotation `rot`
         * 
         * @param rot The unit Quaternion representing the rotation
         * @param point The point to rotate
         */
        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> RotatePoint(const glbQuat_T<T>& rot, const glbVec_T<3, T>& point) noexcept;
        /**
         * Rotates `point` clockwise around `pivot`, by the rotation `rot`
         * 
         * @param rot The unit Quaternion representing the rotation
         * @param point The point to rotate around `pivot`
         * @param pivot The pivot of the rotation
         */
        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> RotatePointAroundPivot(const glbQuat_T<T>& rot, const glbVec_T<3, T>& point, const glbVec_T<3, T>& pivot) noexcept;


        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> ToMat3x3(const glbQuat_T<T>& rot) noexcept;
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> ToMat4x4(const glbQuat_T<T>& rot) noexcept;

        template<int R, int C, typename T>
        GLB_INLINE constexpr glbQuat_T<T> FromMat(const glbMat_T<R, C, T>& m) noexcept;
        
        
    } // namespace Qua

    
} // namespace glb

#include "../internal/quat/compute_rotation.inl"