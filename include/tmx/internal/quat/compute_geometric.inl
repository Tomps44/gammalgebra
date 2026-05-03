#include <cmath>

namespace tmx
{
    namespace internal
    {
        template<typename T, bool useSimd>
        struct quatDot
        {
            TMX_INLINE static constexpr T call(const quat<T>& a, const quat<T>& b) noexcept
            {
                return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
            }
        };


        template<typename T, bool useSimd>
        struct quatLength
        {
            TMX_INLINE static constexpr T call(const quat<T>& q) noexcept
            {
                return std::sqrt(internal::quatDot<T, internal::useSimd<4, T>::value>::call(q, q));
            }
        };


        template<typename T, bool useSimd>
        struct quatNormalize
        {
            TMX_INLINE static constexpr quat<T> call(const quat<T>& q) noexcept
            {
                return q / std::sqrt(internal::quatDot<T, internal::useSimd<4, T>::value>::call(q, q));
            }
        };


        template<typename T, bool useSimd>
        struct quatInverse
        {
            TMX_INLINE static constexpr quat<T> call(const quat<T>& q) noexcept
            {
                // Conjugué x inverse de la longueur au carré 

                return Qua::Conjugate(q) * (1 / internal::quatDot<T, internal::useSimd<4, T>::value>::call(q, q));
            }
        };

        
        
    } // namespace internal
    
    namespace Qua
    {
        template<typename T>
        TMX_INLINE constexpr T Dot(const quat<T>& a, const quat<T>& b) noexcept
        {
            return internal::quatDot<T, internal::useSimd<4, T>::value>::call(a, b);
        }

        template<typename T>
        TMX_INLINE constexpr T Length(const quat<T>& q) noexcept
        {
            return internal::quatLength<T, internal::useSimd<4, T>::value>::call(q);
        }
        template<typename T>
        TMX_INLINE constexpr T LengthSquared(const quat<T>& q) noexcept
        {
            return internal::quatDot<T, internal::useSimd<4, T>::value>::call(q, q);
        }

        template<typename T>
        TMX_INLINE constexpr quat<T> Normalize(const quat<T>& q) noexcept
        {
            return internal::quatNormalize<T, internal::useSimd<4, T>::value>::call(q);
        }

        template<typename T>
        TMX_INLINE constexpr quat<T> Conjugate(const quat<T>& q) noexcept
        {
            return quat<T>(
                q.w, 
                q.x * static_cast<T>(-1),
                q.y * static_cast<T>(-1),
                q.z * static_cast<T>(-1)
            );
        }

        template<typename T>
        TMX_INLINE constexpr quat<T> Inverse(const quat<T>& q) noexcept
        {
            return internal::quatInverse<T, internal::useSimd<4, T>::value>::call(q);
        }

    } // namespace Vec
} // namespace tmx