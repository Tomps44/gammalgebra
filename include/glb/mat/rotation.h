#pragma once

#include "../internal/type_mat.h"
#include "../internal/type_quat.h"

namespace glb
{
    namespace Mat
    {
        /**
         * @brief Generates a 3x3 rotation matrix, representing the rotation stored in `rot`, a unit Quaternion.
         * 
         * @attention 
         * The coordinate system used to generate that matrix is the one specified by GLB_SET_COORDINATE_SYSTEM_... 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> FromQuat_3x3(const glbQuat_T<T>& rot) noexcept;
        
        /**
         * @brief Generates a 4x4 rotation matrix, representing the rotation stored in `rot`, a unit Quaternion.
         * 
         * @attention 
         * The coordinate system used to generate that matrix is the one specified by GLB_SET_COORDINATE_SYSTEM_... 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> FromQuat_4x4(const glbQuat_T<T>& rot) noexcept;


        /**
         * Generates a 3x3 rotation matrix of a rotation by `angle`, specified in `radians` around the axis specified by `axis`.
         * 
         * @param axis A unit vector, representing the axis to rotate about : `(1, 0, 0)` for `X`, 
         * `(0, 1, 0)` for `Y`, `(0, 0, 1)` for `Z`
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> FromAxisAngle(const glbVec_T<3, T>& axis, T angle) noexcept;



        /**
         * @brief Generates a 2x2 rotation matrix around the Z axis, rotating by `angle`, specified in `radians`.
         * 
         * @attention 
         * The coordinate system used to generate that matrix is the one specified by GLB_SET_COORDINATE_SYSTEM_... 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<2, 2, T> RotateZ_2x2(T angle) noexcept;
        /**
         * @brief Generates a 3x3 rotation matrix around the Z axis, rotating by `angle`, specified in `radians`.
         * 
         * @attention 
         * The coordinate system used to generate that matrix is the one specified by GLB_SET_COORDINATE_SYSTEM_... 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateZ(T angle) noexcept;

       
        /**
         * @brief Generates a 3x3 rotation matrix around the X axis, rotating by `angle`, specified in `radians`.
         * 
         * @attention 
         * The coordinate system used to generate that matrix is the one specified by GLB_SET_COORDINATE_SYSTEM_... 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateX(T angle) noexcept;

        /**
         * @brief Generates a 3x3 rotation matrix around the Y axis, rotating by `angle`, specified in `radians`.
         * 
         * @attention 
         * The coordinate system used to generate that matrix is the one specified by GLB_SET_COORDINATE_SYSTEM_... 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateY(T angle) noexcept;

    }    


    namespace glbDetail
    {
        /**
         * @brief Generates a 3x3 `left-handed` rotation matrix, representing the rotation stored in `rot`, a unit Quaternion.
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> FromQuat_3x3_LH(const glbQuat_T<T>& rot) noexcept;
        /**
         * @brief Generates a 4x4 `left-handed` rotation matrix, representing the rotation stored in `rot`, a unit Quaternion.
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> FromQuat_4x4_LH(const glbQuat_T<T>& rot) noexcept;

        /**
         * @brief Generates a 3x3 `right-handed` rotation matrix, representing the rotation stored in `rot`, a unit Quaternion.
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> FromQuat_3x3_RH(const glbQuat_T<T>& rot) noexcept;
        /**
         * @brief Generates a 4x4 `right-handed` rotation matrix, representing the rotation stored in `rot`, a unit Quaternion.
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> FromQuat_4x4_RH(const glbQuat_T<T>& rot) noexcept;


        /**
         * @brief Generates a 2x2 `left-handed` rotation matrix around the Z axis, rotating by `angle`, specified in `radians`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<2, 2, T> RotateZ_2x2_LH(T angle) noexcept;
        /**
         * @brief Generates a 3x3 `left-handed` rotation matrix around the Z axis, rotating by `angle`, specified in `radians`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateZ_LH(T angle) noexcept;
        
        /**
         * @brief Generates a 3x3 `left-handed` rotation matrix around the X axis, rotating by `angle`, specified in `radians`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateX_LH(T angle) noexcept;

        /**
         * @brief Generates a 3x3 `left-handed` rotation matrix around the Y axis, rotating by `angle`, specified in `radians`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateY_LH(T angle) noexcept;
        


        /**
         * @brief Generates a 2x2 `right-handed` rotation matrix around the Z axis, rotating by `angle`, specified in `radians`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<2, 2, T> RotateZ_2x2_RH(T angle) noexcept;
        /**
         * @brief Generates a 3x3 `right-handed` rotation matrix around the Z axis, rotating by `angle`, specified in `radians`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateZ_RH(T angle) noexcept;
        
        /**
         * @brief Generates a 3x3 `right-handed` rotation matrix around the X axis, rotating by `angle`, specified in `radians`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateX_RH(T angle) noexcept;

        /**
         * @brief Generates a 3x3 `right-handed` rotation matrix around the Y axis, rotating by `angle`, specified in `radians`. 
         */
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateY_RH(T angle) noexcept;
        
    } // namespace glbDetail

} // namespace glb

#include "../internal/mat/compute_rotation.inl"