#pragma once

#include "tmx/internal/type_mat.hpp"
#include "tmx/internal/type_quat.hpp"

namespace tmx
{
    namespace Mat
    {
        
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> FromQuat_3x3(const quat<T>& rot) noexcept;
        
        template<typename T>
        TMX_INLINE constexpr mat<4, 4, T> FromQuat_4x4(const quat<T>& rot) noexcept;


        /**
         * Generates a 3x3 rotation Matrix of a rotation by `angle` around a certain axis
         * 
         * @param axis A unit vector, representing the axis to rotate about `(1, 0, 0)` for `X`, 
         * `(0, 1, 0)` for `Y`, `(0, 0, 1)` for `Z`,
         * @param angle The angle of the rotation, IN RADIANS
         */
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> FromAxisAngle(const vec<3, T>& axis, T angle) noexcept;



        template<typename T>
        TMX_INLINE constexpr mat<2, 2, T> RotateZ_2x2(T angle) noexcept;
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateZ(T angle) noexcept;

       
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateX(T angle) noexcept;

        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateY(T angle) noexcept;

    }    


    namespace tmxDetail
    {
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> FromQuat_3x3_LH(const quat<T>& rot) noexcept;
        template<typename T>
        TMX_INLINE constexpr mat<4, 4, T> FromQuat_4x4_LH(const quat<T>& rot) noexcept;

        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> FromQuat_3x3_RH(const quat<T>& rot) noexcept;
        template<typename T>
        TMX_INLINE constexpr mat<4, 4, T> FromQuat_4x4_RH(const quat<T>& rot) noexcept;


        template<typename T>
        TMX_INLINE constexpr mat<2, 2, T> RotateZ_2x2_LH(T angle) noexcept;
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateZ_LH(T angle) noexcept;
        
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateX_LH(T angle) noexcept;

        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateY_LH(T angle) noexcept;
        


        template<typename T>
        TMX_INLINE constexpr mat<2, 2, T> RotateZ_2x2_RH(T angle) noexcept;
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateZ_RH(T angle) noexcept;
        
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateX_RH(T angle) noexcept;

        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateY_RH(T angle) noexcept;
        
    } // namespace tmxDetail

} // namespace tmx

#include "tmx/internal/mat/compute_rotation.inl"