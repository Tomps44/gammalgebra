/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */




 
#include <cmath>
#include "tmx/internal/type_vec.hpp"
#include "tmx/vec/geometric.hpp"
#include "tmx/quat/exponential.hpp"
#include "tmx/quat/geometric.hpp"

namespace tmx
{
    namespace DQua
    {
        template<typename T>
        TMX_INLINE constexpr dQuat<T> log(const dQuat<T>& dq) noexcept
        {
            dQuat<T> copy = dq;

            if (copy.real.w < static_cast<T>(0))
            {
                copy = -copy;
            }

            return dQuat<T>(
                Qua::log(copy.real),
                (copy.dual * Qua::conjugate(copy.real)) /** static_cast<T>(2.0)*/
            );
        }

        template<typename T>
        TMX_INLINE constexpr dQuat<T> exp(const dQuat<T>& dq) noexcept
        {
            const vec<3, T> v(dq.real.x, dq.real.y, dq.real.z);
            const vec<3, T> t(dq.dual.x, dq.dual.y, dq.dual.z);
            const T theta = Vec::length(v);

            if (theta < static_cast<T>(1.0e-06))
            {
                return dQuat<T>(
                    quat<T>(static_cast<T>(1), v),
                    quat<T>(static_cast<T>(0), t)
                );
            }


            const quat<T> expReal = Qua::exp(dq.real);

            return dQuat<T>(
                expReal,
                (dq.dual * expReal) /** static_cast<T>(0.5)*/
            );
        }


        template<typename T>
        TMX_INLINE constexpr dQuat<T> pow(const dQuat<T>& dq, T s) noexcept
        {
            // n^s = e^(s * ln(n))

            // return dQuat<T>(
            //     DQua::exp(DQua::log(dq) * s)
            // );

            dQuat<T> L = DQua::log(dq);
            L *= s;
            
            return DQua::exp(L);
        }
        template<typename T>
        TMX_INLINE constexpr dQuat<T> sqrt(const dQuat<T>& dq) noexcept
        {
            // n^s = e^(s * ln(n))

            return DQua::pow(dq, static_cast<T>(0.5));
        }


    } // namespace Qua
} // namespace tmx
