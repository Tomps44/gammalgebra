#include <cmath>

namespace glb
{
    namespace glbDetail
    {        
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> FromQuat_3x3_RH(const glbQuat_T<T>& rot) noexcept
        {
            const T xx = rot.x * rot.x;
            const T yy = rot.y * rot.y;
            const T zz = rot.z * rot.z;
            const T xy = rot.x * rot.y;
            const T xz = rot.x * rot.z;
            const T xw = rot.x * rot.w;
            const T zw = rot.z * rot.w;
            const T yw = rot.y * rot.w;
            const T yz = rot.y * rot.z;

            return glbMat_T<3, 3, T>(
                static_cast<T>(1) - static_cast<T>(2) * (yy + zz), static_cast<T>(2) * (xy - zw), static_cast<T>(2) * (xz + yw),
                static_cast<T>(2) * (xy + zw), static_cast<T>(1) - static_cast<T>(2) * (xx + zz), static_cast<T>(2) * (yz - xw),
                static_cast<T>(2) * (xz - yw), static_cast<T>(2) * (yz + xw), static_cast<T>(1) - static_cast<T>(2) * (xx + yy)
            );
        }
        
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> FromQuat_4x4_RH(const glbQuat_T<T>& rot) noexcept
        {
            const T xx = rot.x * rot.x;
            const T yy = rot.y * rot.y;
            const T zz = rot.z * rot.z;
            const T xy = rot.x * rot.y;
            const T xz = rot.x * rot.z;
            const T xw = rot.x * rot.w;
            const T zw = rot.z * rot.w;
            const T yw = rot.y * rot.w;
            const T yz = rot.y * rot.z;

            glbMat_T<4, 4, T> res;

            res[0][0] = static_cast<T>(1) - static_cast<T>(2) * (yy + zz);
            res[1][0] = static_cast<T>(2) * (xy - zw);
            res[2][0] = static_cast<T>(2) * (xz + yw);

            res[0][1] = static_cast<T>(2) * (xy + zw);
            res[1][1] = static_cast<T>(1) - static_cast<T>(2) * (xx + zz);
            res[2][1] = static_cast<T>(2) * (yz - xw);

            res[0][2] = static_cast<T>(2) * (xz - yw);
            res[1][2] = static_cast<T>(2) * (yz + xw);
            res[2][2] = static_cast<T>(1) - static_cast<T>(2) * (xx + yy);
            
            return res;
        }



        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> FromQuat_3x3_LH(const glbQuat_T<T>& rot) noexcept
        {
            const T xx = rot.x * rot.x;
            const T yy = rot.y * rot.y;
            const T zz = rot.z * rot.z;
            const T xy = rot.x * rot.y;
            const T xz = rot.x * rot.z;
            const T xw = rot.x * rot.w;
            const T zw = rot.z * rot.w;
            const T yw = rot.y * rot.w;
            const T yz = rot.y * rot.z;

            return glbMat_T<3, 3, T>(
                static_cast<T>(1) - static_cast<T>(2) * (yy + zz), static_cast<T>(2) * (xy + zw), static_cast<T>(2) * (xz - yw),
                static_cast<T>(2) * (xy - zw), static_cast<T>(1) - static_cast<T>(2) * (xx + zz), static_cast<T>(2) * (yz + xw),
                static_cast<T>(2) * (xz + yw), static_cast<T>(2) * (yz - xw), static_cast<T>(1) - static_cast<T>(2) * (xx + yy)
            );
        }
        
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> FromQuat_4x4_LH(const glbQuat_T<T>& rot) noexcept
        {
            const T xx = rot.x * rot.x;
            const T yy = rot.y * rot.y;
            const T zz = rot.z * rot.z;
            const T xy = rot.x * rot.y;
            const T xz = rot.x * rot.z;
            const T xw = rot.x * rot.w;
            const T zw = rot.z * rot.w;
            const T yw = rot.y * rot.w;
            const T yz = rot.y * rot.z;

            glbMat_T<4, 4, T> res;

            res[0][0] = static_cast<T>(1) - static_cast<T>(2) * (yy + zz);
            res[1][0] = static_cast<T>(2) * (xy + zw);
            res[2][0] = static_cast<T>(2) * (xz - yw);

            res[0][1] = static_cast<T>(2) * (xy - zw);
            res[1][1] = static_cast<T>(1) - static_cast<T>(2) * (xx + zz);
            res[2][1] = static_cast<T>(2) * (yz + xw);

            res[0][2] = static_cast<T>(2) * (xz + yw);
            res[1][2] = static_cast<T>(2) * (yz - xw);
            res[2][2] = static_cast<T>(1) - static_cast<T>(2) * (xx + yy);
            
            return res;
        }





        template<typename T>
        GLB_INLINE constexpr glbMat_T<2, 2, T> RotateZ_2x2_LH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            return glbMat_T<2, 2, T>(
                c, -s,
                s, c
            );
        }
        template<typename T>
        GLB_INLINE constexpr glbMat_T<2, 2, T> RotateZ_2x2_RH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            return glbMat_T<2, 2, T>(
                c, s,
                -s, c
            );
        }


        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateZ_LH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            glbMat_T<3, 3, T> res;

            res[0][0] = c;
            res[1][0] = s;
            res[0][1] = -s;
            res[1][1] = c;

            return res;
        }
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateZ_RH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            glbMat_T<3, 3, T> res;

            res[0][0] = c;
            res[1][0] = -s;
            res[0][1] = s;
            res[1][1] = c;

            return res;
        }



        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateX_LH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            glbMat_T<3, 3, T> res;

            res[1][1] = c;
            res[2][1] = s;
            res[1][2] = -s;
            res[2][2] = c;

            return res;
        }
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateX_RH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            glbMat_T<3, 3, T> res;

            res[1][1] = c;
            res[2][1] = -s;
            res[1][2] = s;
            res[2][2] = c;

            return res;
        }



        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateY_LH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            glbMat_T<3, 3, T> res;

            res[0][0] = c;
            res[2][0] = -s;
            res[0][2] = s;
            res[2][2] = c;

            return res;
        }
        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateY_RH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            glbMat_T<3, 3, T> res;

            res[0][0] = c;
            res[2][0] = s;
            res[0][2] = -s;
            res[2][2] = c;

            return res;
        }

    } // namespace glbDetail



    namespace Mat
    {

        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> FromQuat_3x3(const glbQuat_T<T>& rot) noexcept
        {
#           if defined(GLB_SET_COORDINATE_SYSTEM_LH)
                return glbDetail::FromQuat_3x3_LH(rot);

#           else // GLB_SET_COORDINATE_SYSTEM_RH
                return glbDetail::FromQuat_3x3_RH(rot);

#           endif
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> FromQuat_4x4(const glbQuat_T<T>& rot) noexcept
        {
#           if defined(GLB_SET_COORDINATE_SYSTEM_LH)
                return glbDetail::FromQuat_4x4_LH(rot);

#           else // GLB_SET_COORDINATE_SYSTEM_RH
                return glbDetail::FromQuat_4x4_RH(rot);

#           endif
        }




        template<typename T>
        GLB_INLINE constexpr glbMat_T<2, 2, T> RotateZ_2x2(T angle) noexcept
        {
#           if defined(GLB_SET_COORDINATE_SYSTEM_LH)
                return glbDetail::RotateZ_2x2_LH(angle);

#           else // GLB_SET_COORDINATE_SYSTEM_RH
                return glbDetail::RotateZ_2x2_RH(angle);

#           endif
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateZ(T angle) noexcept
        {
#           if defined(GLB_SET_COORDINATE_SYSTEM_LH)
                return glbDetail::RotateZ_LH(angle);

#           else // GLB_SET_COORDINATE_SYSTEM_RH
                return glbDetail::RotateZ_RH(angle);

#           endif
        }



        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateX(T angle) noexcept
        {
#           if defined(GLB_SET_COORDINATE_SYSTEM_LH)
                return glbDetail::RotateX_LH(angle);

#           else // GLB_SET_COORDINATE_SYSTEM_RH
                return glbDetail::RotateX_RH(angle);

#           endif
        }



        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> RotateY(T angle) noexcept
        {
#           if defined(GLB_SET_COORDINATE_SYSTEM_LH)
                return glbDetail::RotateY_LH(angle);

#           else // GLB_SET_COORDINATE_SYSTEM_RH
                return glbDetail::RotateY_RH(angle);

#           endif
        }



        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> FromAxisAngle(const glbVec_T<3, T>& axis, T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            const T oneMinusC = static_cast<T>(1) - c;

            const T xy = axis.x * axis.y;
            const T xz = axis.x * axis.z;
            const T yz = axis.y * axis.z;

            return glbMat_T<3, 3, T>(
                axis.x * axis.x * oneMinusC + c, (xy * oneMinusC) - (axis.z * s), (xz * oneMinusC) + (axis.y * s),
                (xy * oneMinusC) + (axis.z * s), axis.y * axis.y * oneMinusC + c, (yz * oneMinusC) - (axis.x * s),
                (xz * oneMinusC) - (axis.y * s), (yz * oneMinusC) + (axis.x * s), axis.z * axis.z * oneMinusC + c
            );
        }

    } // namespace Mat


} // namespace glb
