#include <cmath>

namespace glb
{
    namespace glbIntern
    {
        template<typename T, bool useSimd>
        struct quatDot
        {
            GLB_INLINE static constexpr T call(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept
            {
                return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
            }
        };


        template<typename T, bool useSimd>
        struct quatLength
        {
            GLB_INLINE static constexpr T call(const glbQuat_T<T>& q) noexcept
            {
                return std::sqrt(glbIntern::quatDot<T, glbIntern::useSimd<4, T>::value>::call(q, q));
            }
        };


        template<typename T, bool useSimd>
        struct quatNormalize
        {
            GLB_INLINE static constexpr glbQuat_T<T> call(const glbQuat_T<T>& q) noexcept
            {
                return q / std::sqrt(glbIntern::quatDot<T, glbIntern::useSimd<4, T>::value>::call(q, q));
            }
        };


        template<typename T, bool useSimd>
        struct quatInverse
        {
            GLB_INLINE static constexpr glbQuat_T<T> call(const glbQuat_T<T>& q) noexcept
            {
                // Conjugué x inverse de la longueur au carré 

                return Qua::Conjugate(q) * (1 / glbIntern::quatDot<T, glbIntern::useSimd<4, T>::value>::call(q, q));
            }
        };

        
        
    } // namespace glbIntern
    
    namespace Qua
    {
        template<typename T>
        GLB_INLINE constexpr T Dot(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept
        {
            return glbIntern::quatDot<T, glbIntern::useSimd<4, T>::value>::call(a, b);
        }

        template<typename T>
        GLB_INLINE constexpr T Length(const glbQuat_T<T>& q) noexcept
        {
            return glbIntern::quatLength<T, glbIntern::useSimd<4, T>::value>::call(q);
        }
        template<typename T>
        GLB_INLINE constexpr T LengthSquared(const glbQuat_T<T>& q) noexcept
        {
            return glbIntern::quatDot<T, glbIntern::useSimd<4, T>::value>::call(q, q);
        }

        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Normalize(const glbQuat_T<T>& q) noexcept
        {
            return glbIntern::quatNormalize<T, glbIntern::useSimd<4, T>::value>::call(q);
        }

        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Conjugate(const glbQuat_T<T>& q) noexcept
        {
            return glbQuat_T<T>(
                q.w, 
                q.x * static_cast<T>(-1),
                q.y * static_cast<T>(-1),
                q.z * static_cast<T>(-1)
            );
        }

        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> Inverse(const glbQuat_T<T>& q) noexcept
        {
            return glbIntern::quatInverse<T, glbIntern::useSimd<4, T>::value>::call(q);
        }

    } // namespace Vec
} // namespace glb