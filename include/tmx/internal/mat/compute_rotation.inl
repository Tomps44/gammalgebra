#include <cmath>

namespace tmx
{
    namespace tmxDetail
    {        
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> FromQuat_3x3_RH(const quat<T>& rot) noexcept
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

            return mat<3, 3, T>(
                static_cast<T>(1) - static_cast<T>(2) * (yy + zz), static_cast<T>(2) * (xy - zw), static_cast<T>(2) * (xz + yw),
                static_cast<T>(2) * (xy + zw), static_cast<T>(1) - static_cast<T>(2) * (xx + zz), static_cast<T>(2) * (yz - xw),
                static_cast<T>(2) * (xz - yw), static_cast<T>(2) * (yz + xw), static_cast<T>(1) - static_cast<T>(2) * (xx + yy)
            );
        }
        
        template<typename T>
        TMX_INLINE constexpr mat<4, 4, T> FromQuat_4x4_RH(const quat<T>& rot) noexcept
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

            mat<4, 4, T> res;

            res[0][0] =  static_cast<T>(1) - static_cast<T>(2) * (yy + zz);
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
        TMX_INLINE constexpr mat<3, 3, T> FromQuat_3x3_LH(const quat<T>& rot) noexcept
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

            return mat<3, 3, T>(
                static_cast<T>(1) - static_cast<T>(2) * (yy + zz), static_cast<T>(2) * (xy + zw), static_cast<T>(2) * (xz - yw),
                static_cast<T>(2) * (xy - zw), static_cast<T>(1) - static_cast<T>(2) * (xx + zz), static_cast<T>(2) * (yz + xw),
                static_cast<T>(2) * (xz + yw), static_cast<T>(2) * (yz - xw), static_cast<T>(1) - static_cast<T>(2) * (xx + yy)
            );
        }
        
        template<typename T>
        TMX_INLINE constexpr mat<4, 4, T> FromQuat_4x4_LH(const quat<T>& rot) noexcept
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

            mat<4, 4, T> res;

            res[0][0] =  static_cast<T>(1) - static_cast<T>(2) * (yy + zz);
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
        TMX_INLINE constexpr mat<2, 2, T> RotateZ_2x2_LH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            return mat<2, 2, T>(
                c, -s,
                s, c
            );
        }
        template<typename T>
        TMX_INLINE constexpr mat<2, 2, T> RotateZ_2x2_RH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            return mat<2, 2, T>(
                c, s,
                -s, c
            );
        }


        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateZ_LH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            mat<3, 3, T> res;

            res[0][0] = c;
            res[1][0] = s;
            res[0][1] = -s;
            res[1][1] = c;

            return res;
        }
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateZ_RH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            mat<3, 3, T> res;

            res[0][0] = c;
            res[1][0] = -s;
            res[0][1] = s;
            res[1][1] = c;

            return res;
        }



        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateX_LH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            mat<3, 3, T> res;

            res[1][1] = c;
            res[2][1] = s;
            res[1][2] = -s;
            res[2][2] = c;

            return res;
        }
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateX_RH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            mat<3, 3, T> res;

            res[1][1] = c;
            res[2][1] = -s;
            res[1][2] = s;
            res[2][2] = c;

            return res;
        }



        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateY_LH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            mat<3, 3, T> res;

            res[0][0] = c;
            res[2][0] = -s;
            res[0][2] = s;
            res[2][2] = c;

            return res;
        }
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateY_RH(T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            mat<3, 3, T> res;

            res[0][0] = c;
            res[2][0] = s;
            res[0][2] = -s;
            res[2][2] = c;

            return res;
        }

    } // namespace tmxDetail



    namespace Mat
    {

        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> FromQuat_3x3(const quat<T>& rot) noexcept
        {
#           if defined(TMX_SET_COORDINATE_SYSTEM_LH)
                return tmxDetail::FromQuat_3x3_LH(rot);

#           else // TMX_SET_COORDINATE_SYSTEM_RH
                return tmxDetail::FromQuat_3x3_RH(rot);

#           endif
        }

        template<typename T>
        TMX_INLINE constexpr mat<4, 4, T> FromQuat_4x4(const quat<T>& rot) noexcept
        {
#           if defined(TMX_SET_COORDINATE_SYSTEM_LH)
                return tmxDetail::FromQuat_4x4_LH(rot);

#           else // TMX_SET_COORDINATE_SYSTEM_RH
                return tmxDetail::FromQuat_4x4_RH(rot);

#           endif
        }




        template<typename T>
        TMX_INLINE constexpr mat<2, 2, T> RotateZ_2x2(T angle) noexcept
        {
#           if defined(TMX_SET_COORDINATE_SYSTEM_LH)
                return tmxDetail::RotateZ_2x2_LH(angle);

#           else // TMX_SET_COORDINATE_SYSTEM_RH
                return tmxDetail::RotateZ_2x2_RH(angle);

#           endif
        }

        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateZ(T angle) noexcept
        {
#           if defined(TMX_SET_COORDINATE_SYSTEM_LH)
                return tmxDetail::RotateZ_LH(angle);

#           else // TMX_SET_COORDINATE_SYSTEM_RH
                return tmxDetail::RotateZ_RH(angle);

#           endif
        }



        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateX(T angle) noexcept
        {
#           if defined(TMX_SET_COORDINATE_SYSTEM_LH)
                return tmxDetail::RotateX_LH(angle);

#           else // TMX_SET_COORDINATE_SYSTEM_RH
                return tmxDetail::RotateX_RH(angle);

#           endif
        }



        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> RotateY(T angle) noexcept
        {
#           if defined(TMX_SET_COORDINATE_SYSTEM_LH)
                return tmxDetail::RotateY_LH(angle);

#           else // TMX_SET_COORDINATE_SYSTEM_RH
                return tmxDetail::RotateY_RH(angle);

#           endif
        }



        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> FromAxisAngle(const vec<3, T>& axis, T angle) noexcept
        {
            const T c = std::cos(angle);
            const T s = std::sin(angle);

            const T oneMinusC = static_cast<T>(1) - c;

            const T xy = axis.x * axis.y;
            const T xz = axis.x * axis.z;
            const T yz = axis.y * axis.z;

            return mat<3, 3, T>(
                axis.x * axis.x * oneMinusC + c, (xy * oneMinusC) - (axis.z * s), (xz * oneMinusC) + (axis.y * s),
                (xy * oneMinusC) + (axis.z * s), axis.y * axis.y * oneMinusC + c, (yz * oneMinusC) - (axis.x * s),
                (xz * oneMinusC) - (axis.y * s), (yz * oneMinusC) + (axis.x * s), axis.z * axis.z * oneMinusC + c
            );
        }

    } // namespace Mat


} // namespace tmx
