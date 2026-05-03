/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */




 

#include "tmx/quat/dual_geometric.hpp"
#include "tmx/quat/dual_exponential.hpp"
#include "tmx/quat/geometric.hpp"

namespace tmx
{
    
    namespace DQua
    {    
        template<typename T>
        TMX_INLINE constexpr dQuat<T> lerp(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return DQua::lerpUnclamped(start, end, t);
        }
        template<typename T>
        TMX_INLINE constexpr dQuat<T> lerpUnclamped(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept
        {
            dQuat<T> e = end;

            if (Qua::dot(start.real, e.real) < static_cast<T>(0))
            {
                e = -e;
            }

            return DQua::normalize( (static_cast<T>(1) - t) * start + e * t );
        }

        template<typename T>
        TMX_INLINE constexpr dQuat<T> slerp(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            // return Qua::slerpUnclamped(start, end, t);
            return DQua::slerpUnclamped(start, end, t);
        }
        template<typename T>
        TMX_INLINE constexpr dQuat<T> slerpUnclamped(const dQuat<T>& start, const dQuat<T>& end, T t) noexcept
        {
            return DQua::normalize( start * DQua::pow(DQua::inverse(start) * end, t) );

            // return internal::quatSlerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
        }

    } // namespace Qua

} // namespace tmx