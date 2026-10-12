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
#include "../type_vec.h"
#include "../../vec/geometric.h"
#include "../../quat/exponential.h"
#include "../../quat/geometric.h"

namespace glb
{
    namespace DQua
    {
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Log(const glbDQuat_T<T>& dq) noexcept
        {
            glbDQuat_T<T> copy = dq;

            if (copy.real.w < static_cast<T>(0))
            {
                copy = -copy;
            }

            return glbDQuat_T<T>(
                Qtr::Log(copy.real),
                (copy.dual * Qtr::Conjugate(copy.real)) /** static_cast<T>(2.0)*/
            );
        }

        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Exp(const glbDQuat_T<T>& dq) noexcept
        {
            const glbVec_T<3, T> v(dq.real.x, dq.real.y, dq.real.z);
            const glbVec_T<3, T> t(dq.dual.x, dq.dual.y, dq.dual.z);
            const T theta = Vec::Length(v);

            if (theta < static_cast<T>(8.0e-05))
            {
                return glbDQuat_T<T>(
                    glbQuat_T<T>(static_cast<T>(1), v),
                    glbQuat_T<T>(static_cast<T>(0), t)
                );
            }


            const glbQuat_T<T> expReal = Qtr::Exp(dq.real);

            return glbDQuat_T<T>(
                expReal,
                (dq.dual * expReal) /** static_cast<T>(0.5)*/
            );

        }


        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Pow(const glbDQuat_T<T>& dq, T exp) noexcept
        {            
            return DQua::Exp(exp * DQua::Log(dq));
        }
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Sqrt(const glbDQuat_T<T>& dq) noexcept
        {
            // n^s = e^(s * ln(n))

            return DQua::Pow(dq, static_cast<T>(0.5));
        }


    } // namespace Qtr
} // namespace glb
