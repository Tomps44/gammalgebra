#include "vec_geometric.inl"

namespace glb
{
    namespace glbIntern
    {

#       if defined(GLB_SIMD_SSE)

        template<>
        struct vecDot<4, float, true>
        {
            GLB_INLINE static float call(const glbVec_T<4, float>& a, const glbVec_T<4, float>& b) noexcept
            {
                return _mm_cvtss_f32(glbIntern::vecDot__m128(a.reg, b.reg));
            }
        };
        template<>
        struct vecDot<3, float, true>
        {
            GLB_INLINE static float call(const glbVec_T<3, float>& a, const glbVec_T<3, float>& b) noexcept
            {
                glbVec_T<4, float> a0(a);
                glbVec_T<4, float> b0(b);

                return _mm_cvtss_f32(glbIntern::vecDot__m128(a0.reg, b0.reg));
            }
        };



        template<>
        struct vecLength<4, float, true>
        {
            GLB_INLINE static float call(const glbVec_T<4, float>& v) noexcept
            {
                return _mm_cvtss_f32(glbIntern::vecLength__m128(v.reg));
            }
        };
        template<>
        struct vecDistance<4, float, true>
        {
            GLB_INLINE static float call(const glbVec_T<4, float>& a, const glbVec_T<4, float>& b) noexcept
            {
                return _mm_cvtss_f32(glbIntern::vecDistance__m128(a.reg, b.reg));
            }
        };


        template<>
        struct vecCross<3, float, true>
        {
            GLB_INLINE static glbVec_T<3, float> call(const glbVec_T<3, float>& a, const glbVec_T<3, float>& b) noexcept
            {
                const glbVec_T<4, float> azz(a); 
                const glbVec_T<4, float> bzz(b); 

                const __m128 vec4Cross = glbIntern::vecCross__m128(azz.reg, bzz.reg);
                glbVec_T<4, float> res4; res4.reg = vec4Cross;

                return glbVec_T<3, float>(res4);
            }
        };
        template<>
        struct vecCross<4, float, true>
        {
            GLB_INLINE static glbVec_T<4, float> call(const glbVec_T<4, float>& a, const glbVec_T<4, float>& b) noexcept
            {
                const __m128 vec4Cross = glbIntern::vecCross__m128(a.reg, b.reg);
                glbVec_T<4, float> res; res.reg = vec4Cross;

                return res;
            }
        };


#       endif

    }
}