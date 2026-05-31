#include "tmx/quat/geometric.hpp"
// #include <cmath>
#include "tmx/quat/exponential.hpp"

namespace tmx
{
    namespace internal
    {
        template<typename T, bool useSimd>
        struct quatLerpUnclamped
        {
            TMX_INLINE static constexpr quat<T> call(const quat<T>& start, const quat<T>& end, T t) noexcept
            {
                quat<T> e = end;

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
            TMX_INLINE static constexpr quat<T> call(const quat<T>& start, const quat<T>& end, T t) noexcept
            {
                quat<T> e = end;
                T dot = Qua::Dot(start, e);

                if (dot < static_cast<T>(0.0))
                {
                    e = -e;
                    dot = -dot;
                }

                if (dot > static_cast<T>(0.9995))
                {
                    return internal::quatLerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
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
        TMX_INLINE constexpr quat<T> Lerp(const quat<T>& start, const quat<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            return internal::quatLerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> LerpUnclamped(const quat<T>& start, const quat<T>& end, T t) noexcept
        {
            return internal::quatLerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> Slerp(const quat<T>& start, const quat<T>& end, T t) noexcept
        {
            // clamps t between 0 and 1
            t = std::min(std::max(t, static_cast<T>(0)), static_cast<T>(1));

            // return Qua::slerpUnclamped(start, end, t);
            return internal::quatSlerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> SlerpUnclamped(const quat<T>& start, const quat<T>& end, T t) noexcept
        {
            // return Qua::normalize( start * Qua::pow(Qua::conjugate(start) * end, t) );

            return internal::quatSlerpUnclamped<T, internal::useSimd<4, T>::value>::call(start, end, t);
        }

    } // namespace Qua

} // namespace tmx