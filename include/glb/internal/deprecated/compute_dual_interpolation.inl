/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */




 

#include "dual_geometric.h"
#include "dual_exponential.h"
#include "../../quat/geometric.h"

namespace glb
{
    
    namespace DQua
    {    
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Lerp(const glbDQuat_T<T>& start, const glbDQuat_T<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return DQua::LerpUnclamped(start, end, t);
        }
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> LerpUnclamped(const glbDQuat_T<T>& start, const glbDQuat_T<T>& end, T t) noexcept
        {
            glbDQuat_T<T> e = end;

            if (Qua::Dot(start.real, e.real) < static_cast<T>(0))
            {
                e = -e;
            }

            return DQua::Normalize( (static_cast<T>(1) - t) * start + e * t );
        }

        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Slerp(const glbDQuat_T<T>& start, const glbDQuat_T<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            // return Qua::slerpUnclamped(start, end, t);
            return DQua::SlerpUnclamped(start, end, t);
        }
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> SlerpUnclamped(const glbDQuat_T<T>& start, const glbDQuat_T<T>& end, T t) noexcept
        {
            return DQua::Normalize( start * DQua::Pow(DQua::Inverse(start) * end, t) );

            // return glbIntern::quatSlerpUnclamped<T, glbIntern::useSimd<4, T>::value>::call(start, end, t);
        }

    } // namespace Qua

} // namespace glb