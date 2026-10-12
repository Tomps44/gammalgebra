namespace glb
{
    namespace glbIntern
    {    

#       if defined(GLB_SIMD_SSE)

        template<>
        struct vecAdd<4, float, true> 
        {
            GLB_INLINE static glbVec_T<4, float> call(const glbVec_T<4, float>& a, const glbVec_T<4, float>& b)
            {
                glbVec_T<4, float> res;

                res.reg = _mm_add_ps(a.reg, b.reg);
                return res;
            }
        };

        template<>
        struct vecSub<4, float, true> 
        {
            GLB_INLINE static glbVec_T<4, float> call(const glbVec_T<4, float>& a, const glbVec_T<4, float>& b)
            {
                glbVec_T<4, float> res;

                res.reg = _mm_sub_ps(a.reg, b.reg);
                return res;
            }
        };

        template<>
        struct vecMul<4, float, true> 
        {
            GLB_INLINE static glbVec_T<4, float> call(const glbVec_T<4, float>& a, const glbVec_T<4, float>& b)
            {
                glbVec_T<4, float> res;

                res.reg = _mm_mul_ps(a.reg, b.reg);
                return res;
            }
        };

        template<>
        struct vecDiv<4, float, true> 
        {
            GLB_INLINE static glbVec_T<4, float> call(const glbVec_T<4, float>& a, const glbVec_T<4, float>& b)
            {
                glbVec_T<4, float> res;

                res.reg = _mm_div_ps(a.reg, b.reg);
                return res;
            }
        };


        template<>
        struct vecNeg<4, float, true> 
        {
            GLB_INLINE static glbVec_T<4, float> call(const glbVec_T<4, float>& v)
            {
                glbVec_T<4, float> res;

                res.reg = _mm_mul_ps(_mm_set1_ps(-1.0f), v.reg);
                return res;
            }
        };

#       endif


#       if defined(GLB_SIMD_AVX)

        template<>
        struct vecAdd<4, double, true> 
        {
            GLB_INLINE static glbVec_T<4, double> call(const glbVec_T<4, double>& a, const glbVec_T<4, double>& b)
            {
                glbVec_T<4, double> res;

                res.reg = _mm256_add_pd(a.reg, b.reg);
                return res;
            }
        };

        template<>
        struct vecSub<4, double, true> 
        {
            GLB_INLINE static glbVec_T<4, double> call(const glbVec_T<4, double>& a, const glbVec_T<4, double>& b)
            {
                glbVec_T<4, double> res;

                res.reg = _mm256_sub_pd(a.reg, b.reg);
                return res;
            }
        };

        template<>
        struct vecMul<4, double, true> 
        {
            GLB_INLINE static glbVec_T<4, double> call(const glbVec_T<4, double>& a, const glbVec_T<4, double>& b)
            {
                glbVec_T<4, double> res;

                res.reg = _mm256_mul_pd(a.reg, b.reg);
                return res;
            }
        };

        template<>
        struct vecDiv<4, double, true> 
        {
            GLB_INLINE static glbVec_T<4, double> call(const glbVec_T<4, double>& a, const glbVec_T<4, double>& b)
            {
                glbVec_T<4, double> res;

                res.reg = _mm256_div_pd(a.reg, b.reg);
                return res;
            }
        };

        template<>
        struct vecNeg<4, double, true> 
        {
            GLB_INLINE static glbVec_T<4, double> call(const glbVec_T<4, double>& v)
            {
                glbVec_T<4, double> res;

                res.reg = _mm256_mul_pd(_mm256_set1_pd(-1.0), v.reg);
                return res;
            }
        };

#       endif



#       if defined(GLB_SIMD_SSE2)

        template<>
        struct vecAdd<4, int32_t, true> 
        {
            GLB_INLINE static glbVec_T<4, int32_t> call(const glbVec_T<4, int32_t>& a, const glbVec_T<4, int32_t>& b)
            {
                glbVec_T<4, int32_t> res;

                res.reg = _mm_add_epi32(a.reg, b.reg);
                return res;
            }
        };

        template<>
        struct vecSub<4, int32_t, true> 
        {
            GLB_INLINE static glbVec_T<4, int32_t> call(const glbVec_T<4, int32_t>& a, const glbVec_T<4, int32_t>& b)
            {
                glbVec_T<4, int32_t> res;

                res.reg = _mm_sub_epi32(a.reg, b.reg);
                return res;
            }
        };

#       if defined(GLB_SIMD_SSE4)
        template<>
        struct vecMul<4, int32_t, true> 
        {
            GLB_INLINE static glbVec_T<4, int32_t> call(const glbVec_T<4, int32_t>& a, const glbVec_T<4, int32_t>& b)
            {
                glbVec_T<4, int32_t> res;

                res.reg = _mm_mul_epi32(a.reg, b.reg);
                return res;
            }
        };
#       endif


        template<>
        struct vecAnd<4, int32_t, true> 
        {
            GLB_INLINE static glbVec_T<4, int32_t> call(const glbVec_T<4, int32_t>& a, const glbVec_T<4, int32_t>& b)
            {
                glbVec_T<4, int32_t> res;

                res.reg = _mm_and_si128(a.reg, b.reg);
                return res;
            }
        };
        template<>
        struct vecOr<4, int32_t, true> 
        {
            GLB_INLINE static glbVec_T<4, int32_t> call(const glbVec_T<4, int32_t>& a, const glbVec_T<4, int32_t>& b)
            {
                glbVec_T<4, int32_t> res;

                res.reg = _mm_or_si128(a.reg, b.reg);
                return res;
            }
        };
        template<>
        struct vecXor<4, int32_t, true> 
        {
            GLB_INLINE static glbVec_T<4, int32_t> call(const glbVec_T<4, int32_t>& a, const glbVec_T<4, int32_t>& b)
            {
                glbVec_T<4, int32_t> res;

                res.reg = _mm_xor_si128(a.reg, b.reg);
                return res;
            }
        };
        


#       endif
    }
}