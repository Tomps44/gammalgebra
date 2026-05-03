/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */





 

#include "tmx/internal/type_quat.hpp"
#include "tmx/quat/geometric.hpp"

namespace tmx
{
    namespace DQua
    {
        template<typename T>
        TMX_INLINE constexpr dQuat<T> normalize(const dQuat<T>& dq) noexcept
        {
            const T realL = Qua::length(dq.real);

            const quat<T> normReal = dq.real / realL;
            const quat<T> normDual = dq.dual / realL; 

            return dQuat<T>(
                normReal,
                normDual - normReal * (Qua::dot(normReal, normDual))
            );
        }

        template<typename T>
        TMX_INLINE constexpr dQuat<T> conjugate(const dQuat<T>& dq) noexcept
        {
            return dQuat<T>(
                Qua::conjugate(dq.real),
                Qua::conjugate(dq.dual)
            );
        }

        template<typename T>
        TMX_INLINE constexpr dQuat<T> inverse(const dQuat<T>& dq) noexcept
        {
            // const quat<T> invReal = Qua::inverse(dq.real);

            // return dQuat<T>(
            //     invReal,
            //     invReal * dq.dual * invReal
            // );

            const T l2 = Qua::lengthSquared(dq.real);
            const T l4 = l2 * l2;

            const quat<T> conjReal = Qua::conjugate(dq.real);

            return dQuat<T>(
                conjReal / l2,
                -((conjReal * dq.dual * conjReal) / l4)
            );
        }



        template<typename T>
        TMX_INLINE constexpr quat<T> getRotation(const dQuat<T>& dq) noexcept
        {
            return dq.real;
        }
        
        template<typename T>
        TMX_INLINE constexpr vec<3, T> getTranslation(const dQuat<T>& dq) noexcept
        {
            quat<T> trsl = static_cast<T>(2) * (dq.dual * Qua::conjugate(dq.real));
            return vec<3, T>(trsl.x, trsl.y, trsl.z);
        }

    } // namespace DQua
    
} // namespace tmx
