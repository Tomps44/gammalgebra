#include <cmath>

namespace glb
{
    namespace glbIntern
    {
        template<int S, typename T, bool useSimd>
        struct vecDot
        {};
        template<int S, typename T, bool useSimd>
        struct vecCross
        {};

        // Defined below :

        // template<int S, typename T, bool useSimd>
        // struct vecLength
        // {};
        // template<int S, typename T, bool useSimd>
        // struct vecDistance
        // {};
        // template<int S, typename T, bool useSimd>
        // struct vecNormalize
        // {};



        template<typename T, bool useSimd>
        struct vecDot<2, T, useSimd>
        {
            GLB_INLINE static constexpr T call(const glbVec_T<2, T>& a, const glbVec_T<2, T>& b) noexcept
            {
                return a.x * b.x + a.y * b.y;
            }
        };
        template<typename T, bool useSimd>
        struct vecDot<3, T, useSimd>
        {
            GLB_INLINE static constexpr T call(const glbVec_T<3, T>& a, const glbVec_T<3, T>& b) noexcept
            {
                return a.x * b.x + a.y * b.y + a.z * b.z;
            }
        };
        template<typename T, bool useSimd>
        struct vecDot<4, T, useSimd>
        {
            GLB_INLINE static constexpr T call(const glbVec_T<4, T>& a, const glbVec_T<4, T>& b) noexcept
            {
                return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
            }
        };


        template<typename T, bool useSimd>
        struct vecCross<3, T, useSimd>
        {
            GLB_INLINE static constexpr glbVec_T<3, T> call(const glbVec_T<3, T>& a, const glbVec_T<3, T>& b) noexcept
            {
                return glbVec_T<3, T>(
                    a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x
                );
            }
        };
        template<typename T, bool useSimd>
        struct vecCross<4, T, useSimd>
        {
            GLB_INLINE static constexpr glbVec_T<4, T> call(const glbVec_T<4, T>& a, const glbVec_T<4, T>& b) noexcept
            {
                return glbVec_T<4, T>(
                    a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x,
                    static_cast<T>(0)
                );
            }
        };


        template<int S, typename T, bool useSimd>
        struct vecLength
        {
            GLB_INLINE static constexpr T call(const glbVec_T<S, T>& v) noexcept
            {
                return std::sqrt(Vec::Dot(v, v));
            }
        };


        template<int S, typename T, bool useSimd>
        struct vecDistance
        {
            GLB_INLINE static constexpr T call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
            {
                return Vec::Length(b - a);
            }
        };


        template<int S, typename T, bool useSimd>
        struct vecNormalize
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& v) noexcept
            {
                const T invLen = static_cast<T>(1) / Vec::Length(v);

                return glbVec_T<S, T>(
                    v * invLen
                );
            }
        };
        
    } // namespace glbIntern
    
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr T Dot(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            return glbIntern::vecDot<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
        }

        template<int S, typename T>
        GLB_INLINE constexpr T Length(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::vecLength<S, T, glbIntern::useSimd<S, T>::value>::call(v);
        }

        template<int S, typename T>
        GLB_INLINE constexpr T LengthSquared(const glbVec_T<S, T>& v) noexcept
        {
            return Vec::Dot(v, v);
        }

        template<int S, typename T>
        GLB_INLINE constexpr T Distance(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            return glbIntern::vecDistance<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
        }

        template<int S, typename T>
        GLB_INLINE constexpr T DistanceSquared(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            const glbVec_T<S, T> v = b - a;

            return Vec::Dot(v, v);
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Normalize(const glbVec_T<S, T>& v) noexcept
        {
            return glbIntern::vecNormalize<S, T, glbIntern::useSimd<S, T>::value>::call(v);
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Cross(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            return glbIntern::vecCross<S, T, glbIntern::useSimd<S, T>::value>::call(a, b);
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> FaceForward(const glbVec_T<S, T>& N, const glbVec_T<S, T>& I, const glbVec_T<S, T>& Nref) noexcept
        {
            return Vec::Dot(Nref, I) < static_cast<T>(0) ? N : -N;
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Reflect(const glbVec_T<S, T>& I, const glbVec_T<S, T>& N) noexcept
        {
            return I - N * Vec::Dot(N, I) * static_cast<T>(2);
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Refract(const glbVec_T<S, T>& I, const glbVec_T<S, T>& N, T eta) noexcept
        {
            T dotVal = Vec::Dot(N, I);
            T k = static_cast<T>(1) - eta * eta * (static_cast<T>(1) - dotVal * dotVal);

            glbVec_T<S, T> res = (k >= static_cast<T>(0)) ? (eta * I - (eta * dotVal + std::sqrt(k) * N)) : glbVec_T<S, T>(static_cast<T>(0));
            
            return res;
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> Project(const glbVec_T<S, T>& proj, const glbVec_T<S, T>& base) noexcept
        {
            // base * ( proj • base / ||base||² )
            //                       base • base

            return base * (Vec::Dot(proj, base) / Vec::Dot(base, base));
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, T> ClampMagnitude(const glbVec_T<S, T>& v, T maxLength) noexcept
        {
            T sqMag = Vec::LengthSquared(v);

            if (sqMag > maxLength * maxLength)
            {
                const T invLen = static_cast<T>(1) / (std::sqrt(sqMag));
                return (v * invLen) * maxLength;
            }

            return v;
        }
        

    } // namespace Vec
}

#if !defined(GLB_SIMD_NONE)
#    include "../simd/vec_compute_geometric.inl"

#endif