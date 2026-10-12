#include <cmath>
#include "../type_vec.h"
#include "../../vec/geometric.h"
#include "../../quat/geometric.h"

namespace glb
{
    namespace Qua
    {
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Exp(const glbQuat_T<T>& q) noexcept
        {
            const glbVec_T<3, T> imag(q.x, q.y, q.z);
            const T len = Vec::Length(imag);

            if (len < static_cast<T>(8.0e-05))
            {
                return glbQuat_T<T>(static_cast<T>(2.718281828459045235360287471352662498L), glbVec_T<3, T>{});
            }
            else
            {
                return glbQuat_T<T>(std::cos(len), (imag / len) * std::sin(len)) * std::exp(q.w);
            }

        }

        
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Log(const glbQuat_T<T>& q) noexcept
        {
            const T qLen = Qua::Length(q);
            const glbVec_T<3, T> imag(q.x, q.y, q.z);
            const T vLen = Vec::Length(imag);

            if (qLen < static_cast<T>(8.0e-05) || vLen < static_cast<T>(8.0e-05))
            {
                return glbQuat_T<T>(0, 0, 0, 0);
            }
            else
            {
                const T imagCoef = (static_cast<T>(1) / vLen) * std::acos(q.w / qLen);

                return glbQuat_T<T>(std::log(qLen), imagCoef * imag);
            }
        }


        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Pow(const glbQuat_T<T>& q, T exp) noexcept
        {
            return Qua::Exp(exp * Qua::Log(q));
        }
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Sqrt(const glbQuat_T<T>& q) noexcept
        {
            return Qua::Pow(q, static_cast<T>(0.5));
        }


        


    } // namespace Qua
} // namespace glb
