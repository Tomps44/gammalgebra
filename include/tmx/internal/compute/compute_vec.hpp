#pragma once

#include "tmx/internal/compute/vec_functors.hpp"
#include "tmx/internal/compute/compute_equal.hpp"

namespace tmx
{
    namespace internal
    {
        // template<int S, typename T, bool useSimd>
        // struct vecAdd {};
        // template<int S, typename T, bool useSimd>
        // struct vecSub {};
        // template<int S, typename T, bool useSimd>
        // struct vecMul {};
        // template<int S, typename T, bool useSimd>
        // struct vecDiv {};
        // template<int S, typename T, bool useSimd>
        // struct vecMod {};
        // template<int S, typename T, bool useSimd>
        // struct vecNeg {};
        // template<int S, typename T, bool useSimd>
        // struct vecAnd {};
        // template<int S, typename T, bool useSimd>
        // struct vecOr {};
        // template<int S, typename T, bool useSimd>
        // struct vecXor {};
        // template<int S, typename T, bool useSimd>
        // struct vecNot {};
        // template<int S, typename T, bool useSimd>
        // struct vecShiftLeft {};
        // template<int S, typename T, bool useSimd>
        // struct vecShiftRight {};

        template<int S, typename T, bool isFloating>
        struct vecEqual {};

        template<int S, typename T, bool isFloating>
        struct vecLess {};
        template<int S, typename T, bool isFloating>
        struct vecLessOrEqual {};
        template<int S, typename T, bool isFloating>
        struct vecGreater {};
        template<int S, typename T, bool isFloating>
        struct vecGreaterOrEqual {};
    


        template<int S, typename T, bool useSimd>
        struct vecAdd
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a + b; }, 
                    a, b
                );
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecSub
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a - b; }, 
                    a, b
                );
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecMul
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a * b; }, 
                    a, b
                );
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecDiv
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a / b; }, 
                    a, b
                );
            }
        };


        template<int S, typename T, bool useSimd>
        struct vecMod
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                return internal::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a % b; }, 
                    a, b
                );
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecNeg
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& v)
            {
                return internal::computeVec_oneElem<S, T>::call(
                    [](T a) -> T
                    { return -a; }, 
                    v
                );
            }
        };



        template<int S, typename T, bool useSimd>
        struct vecAnd
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                vec<S, T> v = a;
                for (int s = 0; s < S; s++)
                {
                    v[s] &= b[s];
                }
                return v;
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecOr
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                vec<S, T> v = a;
                for (int s = 0; s < S; s++)
                {
                    v[s] |= b[s];
                }
                return v;
            }
        };
        template<int S, typename T, bool useSimd>
        struct vecXor
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                vec<S, T> v = a;
                for (int s = 0; s < S; s++)
                {
                    v[s] ^= b[s];
                }
                return v;
            }
        }; 
        template<int S, typename T, bool useSimd>
        struct vecNot
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a)
            {
                vec<S, T> v = a;
                for (int s = 0; s < S; s++)
                {
                    v[s] = ~v[s];
                }
                return v;
            }
        };

        template<int S, bool useSimd>
        struct vecNot<S, bool, useSimd>
        {
            TMX_INLINE static constexpr vec<S, bool> call(const vec<S, bool>& a)
            {
                vec<S, bool> v = a;
                for (int s = 0; s < S; s++)
                {
                    v[s] = !v[s];
                }
                return v;
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecShiftLeft
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                vec<S, T> v = a;
                for (int s = 0; s < S; s++)
                {
                    v[s] <<= b[s];
                }
                return v;
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecShiftRight
        {
            TMX_INLINE static constexpr vec<S, T> call(const vec<S, T>& a, const vec<S, T>& b)
            {
                vec<S, T> v = a;
                for (int s = 0; s < S; s++)
                {
                    v[s] >>= b[s];
                }
                return v;
            }
        };


        template<typename T, bool isFloating>
        struct vecEqual<2, T, isFloating>
        {
            TMX_INLINE static constexpr bool call(const vec<2, T>& a, const vec<2, T>& b)
            {
                return 
                    internal::computeEqual<T, isFloating>::call(a.x, b.x) &&
                    internal::computeEqual<T, isFloating>::call(a.y, b.y);

            }
        };
        template<typename T, bool isFloating>
        struct vecEqual<3, T, isFloating>
        {
            TMX_INLINE static constexpr bool call(const vec<3, T>& a, const vec<3, T>& b)
            {
                return 
                    internal::computeEqual<T, isFloating>::call(a.x, b.x) &&
                    internal::computeEqual<T, isFloating>::call(a.y, b.y) &&
                    internal::computeEqual<T, isFloating>::call(a.z, b.z);

            }
        };
        template<typename T, bool isFloating>
        struct vecEqual<4, T, isFloating>
        {
            TMX_INLINE static constexpr bool call(const vec<4, T>& a, const vec<4, T>& b)
            {
                return 
                    internal::computeEqual<T, isFloating>::call(a.x, b.x) &&
                    internal::computeEqual<T, isFloating>::call(a.y, b.y) &&
                    internal::computeEqual<T, isFloating>::call(a.z, b.z) &&
                    internal::computeEqual<T, isFloating>::call(a.w, b.w);

            }
        };



        template<typename T, bool isFloating>
        struct vecLess<2, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<2, T>& a, const vec<2, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x < b.x;
                return a.y < b.y;
            }
        };
        template<typename T, bool isFloating>
        struct vecLess<3, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<3, T>& a, const vec<3, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x < b.x;
                else if (!internal::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y < b.y;
                return a.z < b.z;
            }
        };
        template<typename T, bool isFloating>
        struct vecLess<4, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<4, T>& a, const vec<4, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x < b.x;
                else if (!internal::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y < b.y;
                else if (!internal::computeEqual<T, isFloating>::call(a.z, b.z)) return a.z < b.z;
                return a.w < b.w;
            }
        };


        template<typename T, bool isFloating>
        struct vecLessOrEqual<2, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<2, T>& a, const vec<2, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x <= b.x;
                return a.y <= b.y;
            }
        };
        template<typename T, bool isFloating>
        struct vecLessOrEqual<3, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<3, T>& a, const vec<3, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x <= b.x;
                else if (!internal::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y <= b.y;
                return a.z <= b.z;
            }
        };
        template<typename T, bool isFloating>
        struct vecLessOrEqual<4, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<4, T>& a, const vec<4, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x <= b.x;
                else if (!internal::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y <= b.y;
                else if (!internal::computeEqual<T, isFloating>::call(a.z, b.z)) return a.z <= b.z;
                return a.w <= b.w;
            }
        };


        template<typename T, bool isFloating>
        struct vecGreater<2, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<2, T>& a, const vec<2, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x > b.x;
                return a.y > b.y;
            }
        };
        template<typename T, bool isFloating>
        struct vecGreater<3, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<3, T>& a, const vec<3, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x > b.x;
                else if (!internal::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y > b.y;
                return a.z > b.z;
            }
        };
        template<typename T, bool isFloating>
        struct vecGreater<4, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<4, T>& a, const vec<4, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x > b.x;
                else if (!internal::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y > b.y;
                else if (!internal::computeEqual<T, isFloating>::call(a.z, b.z)) return a.z > b.z;
                return a.w > b.w;
            }
        };


        template<typename T, bool isFloating>
        struct vecGreaterOrEqual<2, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<2, T>& a, const vec<2, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x >= b.x;
                return a.y >= b.y;
            }
        };
        template<typename T, bool isFloating>
        struct vecGreaterOrEqual<3, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<3, T>& a, const vec<3, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x >= b.x;
                else if (!internal::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y >= b.y;
                return a.z >= b.z;
            }
        };
        template<typename T, bool isFloating>
        struct vecGreaterOrEqual<4, T, isFloating>
        {
            TMX_INLINE constexpr static bool call(const vec<4, T>& a, const vec<4, T>& b) noexcept
            {
                if (!internal::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x >= b.x;
                else if (!internal::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y >= b.y;
                else if (!internal::computeEqual<T, isFloating>::call(a.z, b.z)) return a.z >= b.z;
                return a.w >= b.w;
            }
        };

        // template<int S, typename T, bool isFloating>
        // struct vecLessOrEqual {};
        // template<int S, typename T, bool isFloating>
        // struct vecGreater {};
        // template<int S, typename T, bool isFloating>
        // struct vecGreaterOrEqual {};
        
    }
}
