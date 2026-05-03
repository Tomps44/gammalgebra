#include <cmath>
#include "tmx/internal/type_vec.hpp"
#include "tmx/vec/geometric.hpp"

namespace tmx
{
    namespace Qua
    {
        template<typename T>
        TMX_INLINE constexpr quat<T> Exp(const quat<T>& q) noexcept
        {
            const vec<3, T> v(q.x, q.y, q.z);
            T w, coeff;

            const T theta = Vec::Length(v);

            if (theta < static_cast<T>(1.0e-06))
            {
                w = 1 - (theta * theta * static_cast<T>(0.5));
                coeff = 1 - (theta * theta * static_cast<T>(0.166666666667));
            }
            else
            {
                w = std::cos(theta);
                coeff = std::sin(theta) / theta;
            }

            return quat<T>(w, v * coeff);
        }

        template<typename T>
        TMX_INLINE constexpr quat<T> Log(const quat<T>& q) noexcept
        {
            const vec<3, T> v(q.x, q.y, q.z);
            T coeff;
            const T vNorm = Vec::Length(v);

            if (vNorm < static_cast<T>(1.0e-06))
            {
                coeff = 1 / q.w;
            }
            else
            {
                coeff = std::atan2(vNorm, q.w) / vNorm;
            }

            return quat<T>(static_cast<T>(0), v * coeff);
        }


        template<typename T>
        TMX_INLINE constexpr quat<T> Pow(const quat<T>& q, T s) noexcept
        {
            const vec<3, T> v(q.x, q.y, q.z);
            const T vNorm = Vec::Length(v);
            T newW, coeff;

            if (vNorm < static_cast<T>(1.0e-06))
            {
                newW = static_cast<T>(1);
                coeff = s;
            }
            else
            {
                const T theta = std::atan2(vNorm, q.w);

                newW = std::cos(s * theta);
                coeff = std::sin(s * theta) / vNorm;
            }

            return quat<T>(newW, v * coeff);
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> Sqrt(const quat<T>& q) noexcept
        {
            return Qua::Pow(q, static_cast<T>(0.5));
        }


        


    } // namespace Qua
} // namespace tmx
