#include "tmx/mat/rotation.hpp"

namespace tmx
{    
    namespace Qua
    {    
        template<typename T>
        TMX_INLINE constexpr vec<3, T> RotatePoint(const quat<T>& rot, const vec<3, T>& point) noexcept
        {
            return rot * point;
        }

        template<typename T>
        TMX_INLINE constexpr vec<3, T> RotatePointAroundPivot(const quat<T>& rot, const vec<3, T>& point, const vec<3, T>& pivot) noexcept
        {
            // We rotate (pivot - point) by rot, then add again pivot 

            return pivot + (rot * (pivot - point));
        }


        
        template<typename T>
        TMX_INLINE constexpr mat<3, 3, T> ToMat3x3(const quat<T>& q) noexcept
        {
            return Mat::FromQuat_3x3(q);
        }

        template<typename T>
        TMX_INLINE constexpr mat<4, 4, T> ToMat4x4(const quat<T>& q) noexcept
        {
            return Mat::FromQuat_4x4(q);
        }


        template<typename T>
        TMX_INLINE constexpr quat<T> FromMat(const mat<3, 3, T>& m) noexcept
        {
            const T trace = m[0][0] + m[1][1] + m[2][2];

            if (trace > static_cast<T>(0))
            {
                const T s = std::sqrt(trace + static_cast<T>(1)) * static_cast<T>(2);
                const T invS = static_cast<T>(1) / s;

                return quat<T>(
                    static_cast<T>(0.25) * s,
                    (m[1][2] - m[2][1]) * invS,
                    (m[2][0] - m[0][2]) * invS,
                    (m[0][1] - m[1][0]) * invS
                );
            }
            else if (m[0][0] > m[1][1] && m[0][0] > m[2][2])
            {
                const T s = std::sqrt(static_cast<T>(1) + m[0][0] - m[1][1] - m[2][2]) * static_cast<T>(2);
                const T invS = static_cast<T>(1) / s;

                return quat<T>(
                    (m[1][2] - m[2][1]) * invS,
                    static_cast<T>(0.25) * s,
                    (m[1][0] - m[0][1]) * invS,
                    (m[2][0] - m[0][2]) * invS
                );
            }
            else if (m[1][1] > m[2][2])
            {
                const T s = std::sqrt(static_cast<T>(1) + m[1][1] - m[0][0] - m[2][2]) * static_cast<T>(2);
                const T invS = static_cast<T>(1) / s;

                return quat<T>(
                    (m[2][0] - m[0][2]) * invS,
                    (m[1][0] - m[0][1]) * invS,
                    static_cast<T>(0.25) * s,
                    (m[2][1] - m[1][2]) * invS
                );
            }
            else 
            {
                const T s = std::sqrt(static_cast<T>(1) + m[2][2] - m[0][0] - m[1][1]) * static_cast<T>(2);
                const T invS = static_cast<T>(1) / s;

                return quat<T>(
                    (m[1][0] - m[0][1]) * invS,
                    (m[2][0] - m[0][2]) * invS,
                    (m[2][1] - m[1][2]) * invS,
                    static_cast<T>(0.25) * s
                );
            }
            
        }

        template<typename T>
        TMX_INLINE constexpr quat<T> FromMat(const mat<4, 4, T>& m) noexcept
        {
            return Qua::FromMat(static_cast<mat<3, 3, T>>(m));
        }




    } // namespace Qua

} // namespace tmx