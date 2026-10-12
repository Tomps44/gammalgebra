#pragma once 
#include "mat_functors.h"

namespace glb
{
    namespace glbIntern
    {
        // template<int R, int C, typename T, bool useSimd>
        // struct matAdd {};
        // template<int R, int C, typename T, bool useSimd>
        // struct matSub {};
        template<int R, int C, typename T, bool useSimd>
        struct matMul {};
        // template<int R, int C, typename T, bool useSimd>
        // struct matDiv {};
        // template<int R, int C, typename T, bool useSimd>
        // struct matNeg {};

        template<int R, int C, typename T>
        struct matEqual {};



        template<int R, int C, typename T, bool useSimd>
        struct matAdd
        {
            GLB_INLINE static constexpr glbMat_T<R, C, T> call(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b)
            {
                return glbIntern::computeMat_twoElem<R, C, T>::call(
                    [](T a, T b) -> T
                    { return a + b; },
                    a, b
                );
            }

            GLB_INLINE static constexpr glbMat_T<2, 2, T> call(const glbMat_T<2, 2, T>& m, T scalar)
            {
                return glbMat_T<2, 2, T>(
                    m[0] + scalar,
                    m[1] + scalar
                );
            }
            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(const glbMat_T<3, 3, T>& m, T scalar)
            {
                return glbMat_T<3, 3, T>(
                    m[0] + scalar,
                    m[1] + scalar,
                    m[2] + scalar
                );
            }
            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(const glbMat_T<4, 4, T>& m, T scalar)
            {
                return glbMat_T<4, 4, T>(
                    m[0] + scalar,
                    m[1] + scalar,
                    m[2] + scalar,
                    m[3] + scalar
                );
            }
        };

        template<int R, int C, typename T, bool useSimd>
        struct matSub
        {
            GLB_INLINE static constexpr glbMat_T<R, C, T> call(const glbMat_T<R, C, T>& a, const glbMat_T<R, C, T>& b)
            {
                return glbIntern::computeMat_twoElem<R, C, T>::call(
                    [](T a, T b) -> T
                    { return a - b; },
                    a, b
                );
            }

            GLB_INLINE static constexpr glbMat_T<2, 2, T> call(const glbMat_T<2, 2, T>& m, T scalar)
            {
                return glbMat_T<2, 2, T>(
                    m[0] - scalar,
                    m[1] - scalar
                );
            }
            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(const glbMat_T<3, 3, T>& m, T scalar)
            {
                return glbMat_T<3, 3, T>(
                    m[0] - scalar,
                    m[1] - scalar,
                    m[2] - scalar
                );
            }
            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(const glbMat_T<4, 4, T>& m, T scalar)
            {
                return glbMat_T<4, 4, T>(
                    m[0] - scalar,
                    m[1] - scalar,
                    m[2] - scalar,
                    m[3] - scalar
                );
            }
        };

        template<typename T, bool useSimd>
        struct matMul<2, 2, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<2, 2, T> call(const glbMat_T<2, 2, T>& a, const glbMat_T<2, 2, T>& b)
            {
                return glbMat_T<2, 2, T>(
                    a[0][0] * b[0][0] + a[1][0] * b[0][1], 
                    a[0][0] * b[1][0] + a[1][0] * b[1][1],
                    a[0][1] * b[0][0] + a[1][1] * b[0][1],
                    a[0][1] * b[1][0] + a[1][1] * b[1][1]
                );
            }
            

            GLB_INLINE static constexpr glbMat_T<2, 2, T> call(const glbMat_T<2, 2, T>& m, T scalar)
            {
                return glbMat_T<2, 2, T>(
                    m[0] * scalar,
                    m[1] * scalar
                );
            }

            GLB_INLINE static constexpr typename glbMat_T<2, 2, T>::colType call(const glbMat_T<2, 2, T>& m, const typename glbMat_T<2, 2, T>::colType& v)
            {
                return m[0] * v.x + m[1] * v.y;
            }
        };
        template<typename T, bool useSimd>
        struct matMul<3, 3, T, useSimd>
        { 
            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(const glbMat_T<3, 3, T>& m, T scalar)
            {
                return glbMat_T<3, 3, T>(
                    m[0] * scalar,
                    m[1] * scalar,
                    m[2] * scalar
                );
            }

            GLB_INLINE static constexpr typename glbMat_T<3, 3, T>::colType call(const glbMat_T<3, 3, T>& m, const typename glbMat_T<3, 3, T>::colType& v)
            {
                return m[0] * v.x + m[1] * v.y + m[2] * v.z;
            }

            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(const glbMat_T<3, 3, T>& a, const glbMat_T<3, 3, T>& b)
            {
                glbMat_T<3, 3, T> res;

                typename glbMat_T<3, 3, T>::colType vec;

                vec = a[0] * b[0][0];
                vec += a[1] * b[0][1];
                vec += a[2] * b[0][2];

                res[0] = vec;

                vec = a[0] * b[1][0];
                vec += a[1] * b[1][1];
                vec += a[2] * b[1][2];

                res[1] = vec;

                vec = a[0] * b[2][0];
                vec += a[1] * b[2][1];
                vec += a[2] * b[2][2];

                res[2] = vec;

                
                return res;
                
            }
        };
        
        template<typename T, bool useSimd>
        struct matMul<4, 4, T, useSimd>
        { 
            GLB_INLINE static constexpr typename glbMat_T<4, 4, T>::colType call(const glbMat_T<4, 4, T>& m, const typename glbMat_T<4, 4, T>::colType& v)
            {
                return m[0] * v.x + m[1] * v.y + m[2] * v.z + m[3] * v.w;
            }

            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(const glbMat_T<4, 4, T>& m, T scalar)
            {
                return glbMat_T<4, 4, T>(
                    m[0] * scalar,
                    m[1] * scalar,
                    m[2] * scalar,
                    m[3] * scalar
                );
            }

            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(const glbMat_T<4, 4, T>& a, const glbMat_T<4, 4, T>& b)
            {
                 glbMat_T<4, 4, T> res;

                typename glbMat_T<4, 4, T>::colType vec;

                vec = a[0] * b[0][0];
                vec += a[1] * b[0][1];
                vec += a[2] * b[0][2];
                vec += a[3] * b[0][3];

                res[0] = vec;

                vec = a[0] * b[1][0];
                vec += a[1] * b[1][1];
                vec += a[2] * b[1][2];
                vec += a[3] * b[1][3];

                res[1] = vec;

                vec = a[0] * b[2][0];
                vec += a[1] * b[2][1];
                vec += a[2] * b[2][2];
                vec += a[3] * b[2][3];

                res[2] = vec;

                vec = a[0] * b[3][0];
                vec += a[1] * b[3][1];
                vec += a[2] * b[3][2];
                vec += a[3] * b[3][3];

                res[3] = vec;

                
                return res;
            }
        };
        

        template<int R, int C, typename T, bool useSimd>
        struct matDiv
        {
            GLB_INLINE static constexpr glbMat_T<2, 2, T> call(const glbMat_T<2, 2, T>& m, T scalar)
            {
                return glbMat_T<2, 2, T>(
                    m[0] / scalar,
                    m[1] / scalar
                );
            }
            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(const glbMat_T<3, 3, T>& m, T scalar)
            {
                return glbMat_T<3, 3, T>(
                    m[0] / scalar,
                    m[1] / scalar,
                    m[2] / scalar
                );
            }
            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(const glbMat_T<4, 4, T>& m, T scalar)
            {
                return glbMat_T<4, 4, T>(
                    m[0] / scalar,
                    m[1] / scalar,
                    m[2] / scalar,
                    m[3] / scalar
                );
            }
        };
    



        template<int R, int C, typename T, bool useSimd>
        struct matNeg
        {
            GLB_INLINE static constexpr glbMat_T<R, C, T> call(const glbMat_T<R, C, T>& m)
            {
                return glbIntern::computeMat_oneElem<R, C, T>::call(
                    [](T a) -> T
                    { return -a; },
                    m
                );
            }
        };




        template<typename T>
        struct matEqual<2, 2, T>
        {
            GLB_INLINE static constexpr bool call(const glbMat_T<2, 2, T>& a, const glbMat_T<2, 2, T>& b)
            {
                return a[0] == b[0] && a[1] == b[1]; 
            }
        };
        template<typename T>
        struct matEqual<3, 3, T>
        {
            GLB_INLINE static constexpr bool call(const glbMat_T<3, 3, T>& a, const glbMat_T<3, 3, T>& b)
            {
                return a[0] == b[0] && a[1] == b[1] && a[2] == b[2]; 
            }
        };
        template<typename T>
        struct matEqual<4, 4, T>
        {
            GLB_INLINE static constexpr bool call(const glbMat_T<4, 4, T>& a, const glbMat_T<4, 4, T>& b)
            {
                return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]; 
            }
        };
    }
}