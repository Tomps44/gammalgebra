#pragma once

#include "vec_functors.h"
#include "compute_equal.h"

namespace glb
{
    namespace glbIntern
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
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b)
            {
                return glbIntern::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a + b; }, 
                    a, b
                );
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecSub
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b)
            {
                return glbIntern::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a - b; }, 
                    a, b
                );
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecMul
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b)
            {
                return glbIntern::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a * b; }, 
                    a, b
                );
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecDiv
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b)
            {
                return glbIntern::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a / b; }, 
                    a, b
                );
            }
        };


        template<int S, typename T, bool useSimd>
        struct vecMod
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b)
            {
                return glbIntern::computeVec_twoElem<S, T>::call(
                    [](T a, T b) -> T
                    { return a % b; }, 
                    a, b
                );
            }
        };

        template<int S, typename T, bool useSimd>
        struct vecNeg
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& v)
            {
                return glbIntern::computeVec_oneElem<S, T>::call(
                    [](T a) -> T
                    { return -a; }, 
                    v
                );
            }
        };



        template<int S, typename T, bool useSimd>
        struct vecAnd
        {
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b)
            {
                glbVec_T<S, T> v = a;
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
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b)
            {
                glbVec_T<S, T> v = a;
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
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b)
            {
                glbVec_T<S, T> v = a;
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
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a)
            {
                glbVec_T<S, T> v = a;
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
            GLB_INLINE static constexpr glbVec_T<S, bool> call(const glbVec_T<S, bool>& a)
            {
                glbVec_T<S, bool> v = a;
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
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b)
            {
                glbVec_T<S, T> v = a;
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
            GLB_INLINE static constexpr glbVec_T<S, T> call(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b)
            {
                glbVec_T<S, T> v = a;
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
            GLB_INLINE static constexpr bool call(const glbVec_T<2, T>& a, const glbVec_T<2, T>& b)
            {
                return 
                    glbIntern::computeEqual<T, isFloating>::call(a.x, b.x) &&
                    glbIntern::computeEqual<T, isFloating>::call(a.y, b.y);

            }
        };
        template<typename T, bool isFloating>
        struct vecEqual<3, T, isFloating>
        {
            GLB_INLINE static constexpr bool call(const glbVec_T<3, T>& a, const glbVec_T<3, T>& b)
            {
                return 
                    glbIntern::computeEqual<T, isFloating>::call(a.x, b.x) &&
                    glbIntern::computeEqual<T, isFloating>::call(a.y, b.y) &&
                    glbIntern::computeEqual<T, isFloating>::call(a.z, b.z);

            }
        };
        template<typename T, bool isFloating>
        struct vecEqual<4, T, isFloating>
        {
            GLB_INLINE static constexpr bool call(const glbVec_T<4, T>& a, const glbVec_T<4, T>& b)
            {
                return 
                    glbIntern::computeEqual<T, isFloating>::call(a.x, b.x) &&
                    glbIntern::computeEqual<T, isFloating>::call(a.y, b.y) &&
                    glbIntern::computeEqual<T, isFloating>::call(a.z, b.z) &&
                    glbIntern::computeEqual<T, isFloating>::call(a.w, b.w);

            }
        };



        template<typename T, bool isFloating>
        struct vecLess<2, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<2, T>& a, const glbVec_T<2, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x < b.x;
                return a.y < b.y;
            }
        };
        template<typename T, bool isFloating>
        struct vecLess<3, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<3, T>& a, const glbVec_T<3, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x < b.x;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y < b.y;
                return a.z < b.z;
            }
        };
        template<typename T, bool isFloating>
        struct vecLess<4, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<4, T>& a, const glbVec_T<4, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x < b.x;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y < b.y;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.z, b.z)) return a.z < b.z;
                return a.w < b.w;
            }
        };


        template<typename T, bool isFloating>
        struct vecLessOrEqual<2, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<2, T>& a, const glbVec_T<2, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x <= b.x;
                return a.y <= b.y;
            }
        };
        template<typename T, bool isFloating>
        struct vecLessOrEqual<3, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<3, T>& a, const glbVec_T<3, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x <= b.x;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y <= b.y;
                return a.z <= b.z;
            }
        };
        template<typename T, bool isFloating>
        struct vecLessOrEqual<4, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<4, T>& a, const glbVec_T<4, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x <= b.x;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y <= b.y;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.z, b.z)) return a.z <= b.z;
                return a.w <= b.w;
            }
        };


        template<typename T, bool isFloating>
        struct vecGreater<2, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<2, T>& a, const glbVec_T<2, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x > b.x;
                return a.y > b.y;
            }
        };
        template<typename T, bool isFloating>
        struct vecGreater<3, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<3, T>& a, const glbVec_T<3, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x > b.x;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y > b.y;
                return a.z > b.z;
            }
        };
        template<typename T, bool isFloating>
        struct vecGreater<4, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<4, T>& a, const glbVec_T<4, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x > b.x;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y > b.y;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.z, b.z)) return a.z > b.z;
                return a.w > b.w;
            }
        };


        template<typename T, bool isFloating>
        struct vecGreaterOrEqual<2, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<2, T>& a, const glbVec_T<2, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x >= b.x;
                return a.y >= b.y;
            }
        };
        template<typename T, bool isFloating>
        struct vecGreaterOrEqual<3, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<3, T>& a, const glbVec_T<3, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x >= b.x;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y >= b.y;
                return a.z >= b.z;
            }
        };
        template<typename T, bool isFloating>
        struct vecGreaterOrEqual<4, T, isFloating>
        {
            GLB_INLINE constexpr static bool call(const glbVec_T<4, T>& a, const glbVec_T<4, T>& b) noexcept
            {
                if (!glbIntern::computeEqual<T, isFloating>::call(a.x, b.x)) return a.x >= b.x;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.y, b.y)) return a.y >= b.y;
                else if (!glbIntern::computeEqual<T, isFloating>::call(a.z, b.z)) return a.z >= b.z;
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
