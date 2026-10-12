#include "../../quat/geometric.h"
#include "../../quat/exponential.h"

namespace glb
{
    namespace glbIntern
    {
        template<typename T, bool useSimd>
        struct quatLerpUnclamped
        {
            GLB_INLINE static constexpr glbQuat_T<T> call(const glbQuat_T<T>& start, const glbQuat_T<T>& end, T t) noexcept
            {
                glbQuat_T<T> e = end;

                if (Qua::Dot(start, e) < static_cast<T>(0))
                {
                    e = -e;
                }

                return Qua::Normalize((static_cast<T>(1) - t) * start + e * t);
            }
        };

        template<typename T, bool useSimd>
        struct quatSlerpUnclamped
        {
            GLB_INLINE static constexpr glbQuat_T<T> call(const glbQuat_T<T>& start, const glbQuat_T<T>& end, T t) noexcept
            {
                glbQuat_T<T> e = end;
                T dot = Qua::Dot(start, e);

                if (dot < static_cast<T>(0.0))
                {
                    e = -e;
                    dot = -dot;
                }

                if (dot > static_cast<T>(0.9995))
                {
                    return glbIntern::quatLerpUnclamped<T, glbIntern::useSimd<4, T>::value>::call(start, end, t);
                }

                T omega = std::acos(dot);
                T sinOmega = std::sin(omega);


                T w0 = std::sin((static_cast<T>(1) - t) * omega) / sinOmega;
                T w1 = std::sin(t * omega) / sinOmega;

                return (start * w0) + (e * w1);
            }
        };

    }



    namespace Qua
    {    
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Lerp(const glbQuat_T<T>& start, const glbQuat_T<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return glbIntern::quatLerpUnclamped<T, glbIntern::useSimd<4, T>::value>::call(start, end, t);
        }
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> LerpUnclamped(const glbQuat_T<T>& start, const glbQuat_T<T>& end, T t) noexcept
        {
            return glbIntern::quatLerpUnclamped<T, glbIntern::useSimd<4, T>::value>::call(start, end, t);
        }
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Slerp(const glbQuat_T<T>& start, const glbQuat_T<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            // return Qua::slerpUnclamped(start, end, t);
            return glbIntern::quatSlerpUnclamped<T, glbIntern::useSimd<4, T>::value>::call(start, end, t);
        }
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> SlerpUnclamped(const glbQuat_T<T>& start, const glbQuat_T<T>& end, T t) noexcept
        {
            // return Qua::normalize( start * Qua::pow(Qua::conjugate(start) * end, t) );

            return glbIntern::quatSlerpUnclamped<T, glbIntern::useSimd<4, T>::value>::call(start, end, t);
        }

    } // namespace Qua

} // namespace glb