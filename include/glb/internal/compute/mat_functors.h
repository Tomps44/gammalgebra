#pragma once

#include "../definitions.h"

namespace glb
{
    namespace glbIntern
    {
        template<int R, int C, typename T>
        struct computeMat_oneElem {} ;

        template<int R, int C, typename T>
        struct computeMat_twoElem {};


        template<typename T>
        struct computeMat_oneElem<2, 2, T>
        {
            GLB_INLINE static constexpr glbMat_T<2, 2, T> call(T (*Func) (T val), const glbMat_T<2, 2, T>& m)
            {
                return glbMat_T<2, 2, T>(
                    Func(m[0][0]), Func(m[0][1]),
                    Func(m[1][0]), Func(m[1][1])
                );
            }
        };

        template<typename T>
        struct computeMat_oneElem<3, 3, T>
        {
            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(T (*Func) (T val), const glbMat_T<3, 3, T>& m)
            {
                return glbMat_T<3, 3, T>(
                    Func(m[0][0]), Func(m[0][1]), Func(m[0][2]),
                    Func(m[1][0]), Func(m[1][1]), Func(m[1][2]),
                    Func(m[2][0]), Func(m[2][1]), Func(m[2][2])
                );
            }
        };

        template<typename T>
        struct computeMat_oneElem<4, 4, T>
        {
            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(T (*Func) (T val), const glbMat_T<4, 4, T>& m)
            {
                return glbMat_T<4, 4, T>(
                    Func(m[0][0]), Func(m[0][1]), Func(m[0][2]), Func(m[0][3]),
                    Func(m[1][0]), Func(m[1][1]), Func(m[1][2]), Func(m[1][3]),
                    Func(m[2][0]), Func(m[2][1]), Func(m[2][2]), Func(m[2][3]),
                    Func(m[3][0]), Func(m[3][1]), Func(m[3][2]), Func(m[3][3])
                );
            }
        };

        template<typename T>
        struct computeMat_twoElem<2, 2, T>
        {
            GLB_INLINE static constexpr glbMat_T<2, 2, T> call(T (*Func) (T valA, T valB), const glbMat_T<2, 2, T>& ma, const glbMat_T<2, 2, T>& mb)
            {
                return glbMat_T<2, 2, T>(
                    Func(ma[0][0], mb[0][0]), Func(ma[0][1], mb[0][1]),
                    Func(ma[1][0], mb[1][0]), Func(ma[1][1], mb[1][1])
                );
            }
        };
    
       template<typename T>
        struct computeMat_twoElem<3, 3, T>
        {
            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(T (*Func) (T valA, T valB), const glbMat_T<3, 3, T>& ma, const glbMat_T<3, 3, T>& mb)
            {
                return glbMat_T<3, 3, T>(
                    Func(ma[0][0], mb[0][0]), Func(ma[0][1], mb[0][1]), Func(ma[0][2], mb[0][2]),
                    Func(ma[1][0], mb[1][0]), Func(ma[1][1], mb[1][1]), Func(ma[1][2], mb[1][2]),
                    Func(ma[2][0], mb[2][0]), Func(ma[2][1], mb[2][1]), Func(ma[2][2], mb[2][2])
                );
            }
        };

       template<typename T>
        struct computeMat_twoElem<4, 4, T>
        {
            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(T (*Func) (T valA, T valB), const glbMat_T<4, 4, T>& ma, const glbMat_T<4, 4, T>& mb)
            {
                return glbMat_T<4, 4, T>(
                    Func(ma[0][0], mb[0][0]), Func(ma[0][1], mb[0][1]), Func(ma[0][2], mb[0][2]), Func(ma[0][3], mb[0][3]),
                    Func(ma[1][0], mb[1][0]), Func(ma[1][1], mb[1][1]), Func(ma[1][2], mb[1][2]), Func(ma[1][3], mb[1][3]),
                    Func(ma[2][0], mb[2][0]), Func(ma[2][1], mb[2][1]), Func(ma[2][2], mb[2][2]), Func(ma[2][3], mb[2][3]),
                    Func(ma[3][0], mb[3][0]), Func(ma[3][1], mb[3][1]), Func(ma[3][2], mb[3][2]), Func(ma[3][3], mb[3][3])
                );
            }
        };

    } // namespace glbIntern
    
} // namespace glb
