#pragma once

#include "../definitions.h"

namespace glb
{
    namespace glbIntern
    {
        template<int S, typename T>
        struct computeVec_oneElem {};

        template<int S, typename T>
        struct computeVec_twoElem {};


        template<typename T>
        struct computeVec_oneElem<2, T>
        {
            GLB_INLINE static constexpr glbVec_T<3, T> call(T (*Func)(T val), const glbVec_T<2, T>& v)
            {
                return glbVec_T<2, T>(Func(v.x), Func(v.y));
            }
        };

        template<typename T>
        struct computeVec_oneElem<3, T>
        {
            GLB_INLINE static constexpr glbVec_T<3, T> call(T (*Func)(T val), const glbVec_T<3, T>& v)
            {
                return glbVec_T<3, T>(Func(v.x), Func(v.y), Func(v.z));
            }
        };

        template<typename T>
        struct computeVec_oneElem<4, T>
        {
            GLB_INLINE static constexpr glbVec_T<4, T> call(T (*Func)(T val), const glbVec_T<4, T>& v)
            {
                return glbVec_T<4, T>(Func(v.x), Func(v.y), Func(v.z), Func(v.w));
            }
        };

        


        template<typename T>
        struct computeVec_twoElem<2, T>
        {
            GLB_INLINE static constexpr glbVec_T<2, T> call(T (*Func)(T valA, T valB), const glbVec_T<2, T>& va, const glbVec_T<2, T>& vb)
            {
                return glbVec_T<2, T>(Func(va.x, vb.x), Func(va.y, vb.y));
            }
        };

        template<typename T>
        struct computeVec_twoElem<3, T>
        {
            GLB_INLINE static constexpr glbVec_T<3, T> call(T (*Func)(T valA, T valB), const glbVec_T<3, T>& va, const glbVec_T<3, T>& vb)
            {
                return glbVec_T<3, T>(Func(va.x, vb.x), Func(va.y, vb.y), Func(va.z, vb.z));
            }
        };

        template<typename T>
        struct computeVec_twoElem<4, T>
        {
            GLB_INLINE static constexpr glbVec_T<4, T> call(T (*Func)(T valA, T valB), const glbVec_T<4, T>& va, const glbVec_T<4, T>& vb)
            {
                return glbVec_T<4, T>(Func(va.x, vb.x), Func(va.y, vb.y), Func(va.z, vb.z), Func(va.w, vb.w));
            }
        };
    } 
    
}