/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */





 

#include "../type_quat.h"
#include "../../quat/geometric.h"

namespace glb
{
    namespace DQua
    {
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Normalize(const glbDQuat_T<T>& dq) noexcept
        {
            const T realL = Qtr::Length(dq.real);

            const glbQuat_T<T> normReal = dq.real / realL;
            const glbQuat_T<T> normDual = dq.dual / realL; 

            return glbDQuat_T<T>(
                normReal,
                normDual - normReal * (Qtr::Dot(normReal, normDual))
            );
        }

        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Conjugate(const glbDQuat_T<T>& dq) noexcept
        {
            return glbDQuat_T<T>(
                Qtr::Conjugate(dq.real),
                Qtr::Conjugate(dq.dual)
            );
        }

        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Inverse(const glbDQuat_T<T>& dq) noexcept
        {
            // const glbQuat_T<T> invReal = Qtr::inverse(dq.real);

            // return glbDQuat_T<T>(
            //     invReal,
            //     invReal * dq.dual * invReal
            // );

            const T l2 = Qtr::LengthSquared(dq.real);
            const T l4 = l2 * l2;

            const glbQuat_T<T> conjReal = Qtr::Conjugate(dq.real);

            return glbDQuat_T<T>(
                conjReal / l2,
                -((conjReal * dq.dual * conjReal) / l4)
            );
        }



        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> GetRotation(const glbDQuat_T<T>& dq) noexcept
        {
            return dq.real;
        }
        
        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> GetTranslation(const glbDQuat_T<T>& dq) noexcept
        {
            glbQuat_T<T> trsl = static_cast<T>(2) * (dq.dual * Qtr::Conjugate(dq.real));
            return glbVec_T<3, T>(trsl.x, trsl.y, trsl.z);
        }

    } // namespace DQua
    
} // namespace glb
