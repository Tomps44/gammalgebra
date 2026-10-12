namespace glb
{
    namespace glbIntern
    {
    
#       if defined(GLB_SIMD_SSE)

        template<>
        struct matAdd<4, 4, float, true> 
        {
            GLB_INLINE static glbMat_T<4, 4, float> call(const glbMat_T<4, 4, float>& a, const glbMat_T<4, 4, float>& b)
            {
                glbMat_T<4, 4, float> res;

                res[0].reg = _mm_add_ps(a[0].reg, b[0].reg);
                res[1].reg = _mm_add_ps(a[1].reg, b[1].reg);
                res[2].reg = _mm_add_ps(a[2].reg, b[2].reg);
                res[3].reg = _mm_add_ps(a[3].reg, b[3].reg);

                return res;
            }
        
            GLB_INLINE static glbMat_T<4, 4, float> call(const glbMat_T<4, 4, float>& m, float scalar)
            {
                glbMat_T<4, 4, float> res;
                const __m128 scalarReg = _mm_set1_ps(scalar);

                res[0].reg = _mm_add_ps(m[0].reg, scalarReg);
                res[1].reg = _mm_add_ps(m[1].reg, scalarReg);
                res[2].reg = _mm_add_ps(m[2].reg, scalarReg);
                res[3].reg = _mm_add_ps(m[3].reg, scalarReg);

                return res;
            }
        };

        template<>
        struct matSub<4, 4, float, true> 
        {
            GLB_INLINE static glbMat_T<4, 4, float> call(const glbMat_T<4, 4, float>& a, const glbMat_T<4, 4, float>& b)
            {
                glbMat_T<4, 4, float> res;

                res[0].reg = _mm_sub_ps(a[0].reg, b[0].reg);
                res[1].reg = _mm_sub_ps(a[1].reg, b[1].reg);
                res[2].reg = _mm_sub_ps(a[2].reg, b[2].reg);
                res[3].reg = _mm_sub_ps(a[3].reg, b[3].reg);

                return res;
            }
        
            GLB_INLINE static glbMat_T<4, 4, float> call(const glbMat_T<4, 4, float>& m, float scalar)
            {
                glbMat_T<4, 4, float> res;
                const __m128 scalarReg = _mm_set1_ps(scalar);

                res[0].reg = _mm_sub_ps(m[0].reg, scalarReg);
                res[1].reg = _mm_sub_ps(m[1].reg, scalarReg);
                res[2].reg = _mm_sub_ps(m[2].reg, scalarReg);
                res[3].reg = _mm_sub_ps(m[3].reg, scalarReg);

                return res;
            }
        };

        template<>
        struct matMul<4, 4, float, true> 
        {
            GLB_INLINE static glbMat_T<4, 4, float> call(const glbMat_T<4, 4, float>& a, const glbMat_T<4, 4, float>& b)
            {
                glbMat_T<4, 4, float> res;

                res[0].reg = _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(a[0].reg, _mm_set1_ps(b[0][0])), _mm_mul_ps(a[1].reg, _mm_set1_ps(b[0][1]))),
                    _mm_add_ps(_mm_mul_ps(a[2].reg, _mm_set1_ps(b[0][2])), _mm_mul_ps(a[3].reg, _mm_set1_ps(b[0][3])))
                );

                res[1].reg = _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(a[0].reg, _mm_set1_ps(b[1][0])), _mm_mul_ps(a[1].reg, _mm_set1_ps(b[1][1]))),
                    _mm_add_ps(_mm_mul_ps(a[2].reg, _mm_set1_ps(b[1][2])), _mm_mul_ps(a[3].reg, _mm_set1_ps(b[1][3])))
                );

                res[2].reg = _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(a[0].reg, _mm_set1_ps(b[2][0])), _mm_mul_ps(a[1].reg, _mm_set1_ps(b[2][1]))),
                    _mm_add_ps(_mm_mul_ps(a[2].reg, _mm_set1_ps(b[2][2])), _mm_mul_ps(a[3].reg, _mm_set1_ps(b[2][3])))
                );

                res[3].reg = _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(a[0].reg, _mm_set1_ps(b[3][0])), _mm_mul_ps(a[1].reg, _mm_set1_ps(b[3][1]))),
                    _mm_add_ps(_mm_mul_ps(a[2].reg, _mm_set1_ps(b[3][2])), _mm_mul_ps(a[3].reg, _mm_set1_ps(b[3][3])))
                );

                return res;
            }
        
            GLB_INLINE static glbMat_T<4, 4, float> call(const glbMat_T<4, 4, float>& m, float scalar)
            {
                glbMat_T<4, 4, float> res;
                const __m128 scalarReg = _mm_set1_ps(scalar);

                res[0].reg = _mm_mul_ps(m[0].reg, scalarReg);
                res[1].reg = _mm_mul_ps(m[1].reg, scalarReg);
                res[2].reg = _mm_mul_ps(m[2].reg, scalarReg);
                res[3].reg = _mm_mul_ps(m[3].reg, scalarReg);

                return res;
            }

            GLB_INLINE static glbVec_T<4, float> call(const glbMat_T<4, 4, float>& m, const glbVec_T<4, float>& v)
            {
                glbVec_T<4, float> res;

                res.reg = _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(m[0].reg, _mm_set1_ps(v.x)), _mm_mul_ps(m[1].reg, _mm_set1_ps(v.y))),
                    _mm_add_ps(_mm_mul_ps(m[2].reg, _mm_set1_ps(v.z)), _mm_mul_ps(m[3].reg, _mm_set1_ps(v.w)))
                );

                return res;
            }
        };

        template<>
        struct matDiv<4, 4, float, true> 
        {        
            GLB_INLINE static glbMat_T<4, 4, float> call(const glbMat_T<4, 4, float>& m, float scalar)
            {
                glbMat_T<4, 4, float> res;
                const __m128 scalarReg = _mm_set1_ps(scalar);

                res[0].reg = _mm_div_ps(m[0].reg, scalarReg);
                res[1].reg = _mm_div_ps(m[1].reg, scalarReg);
                res[2].reg = _mm_div_ps(m[2].reg, scalarReg);
                res[3].reg = _mm_div_ps(m[3].reg, scalarReg);

                return res;
            }
        };
        

        template<>
        struct matNeg<4, 4, float, true> 
        {
            GLB_INLINE static glbMat_T<4, 4, float> call(const glbMat_T<4, 4, float>& m)
            {
                glbMat_T<4, 4, float> res;
                const __m128 m1Reg = _mm_set1_ps(-1.0f);

                res[0].reg = _mm_mul_ps(m[0].reg, m1Reg);
                res[1].reg = _mm_mul_ps(m[1].reg, m1Reg);
                res[2].reg = _mm_mul_ps(m[2].reg, m1Reg);
                res[3].reg = _mm_mul_ps(m[3].reg, m1Reg);

                return res;
            }
        };

#       endif



#       if defined(GLB_SIMD_AVX)

        template<>
        struct matAdd<4, 4, double, true> 
        {
            GLB_INLINE static glbMat_T<4, 4, double> call(const glbMat_T<4, 4, double>& a, const glbMat_T<4, 4, double>& b)
            {
                glbMat_T<4, 4, double> res;

                res[0].reg = _mm256_add_pd(a[0].reg, b[0].reg);
                res[1].reg = _mm256_add_pd(a[1].reg, b[1].reg);
                res[2].reg = _mm256_add_pd(a[2].reg, b[2].reg);
                res[3].reg = _mm256_add_pd(a[3].reg, b[3].reg);

                return res;
            }
        
            GLB_INLINE static glbMat_T<4, 4, double> call(const glbMat_T<4, 4, double>& m, double scalar)
            {
                glbMat_T<4, 4, double> res;
                const __m256d scalarReg = _mm256_set1_pd(scalar);

                res[0].reg = _mm256_add_pd(m[0].reg, scalarReg);
                res[1].reg = _mm256_add_pd(m[1].reg, scalarReg);
                res[2].reg = _mm256_add_pd(m[2].reg, scalarReg);
                res[3].reg = _mm256_add_pd(m[3].reg, scalarReg);

                return res;
            }
        };

        template<>
        struct matSub<4, 4, double, true> 
        {
            GLB_INLINE static glbMat_T<4, 4, double> call(const glbMat_T<4, 4, double>& a, const glbMat_T<4, 4, double>& b)
            {
                glbMat_T<4, 4, double> res;

                res[0].reg = _mm256_sub_pd(a[0].reg, b[0].reg);
                res[1].reg = _mm256_sub_pd(a[1].reg, b[1].reg);
                res[2].reg = _mm256_sub_pd(a[2].reg, b[2].reg);
                res[3].reg = _mm256_sub_pd(a[3].reg, b[3].reg);

                return res;
            }
        
            GLB_INLINE static glbMat_T<4, 4, double> call(const glbMat_T<4, 4, double>& m, double scalar)
            {
                glbMat_T<4, 4, double> res;
                const __m256d scalarReg = _mm256_set1_pd(scalar);

                res[0].reg = _mm256_sub_pd(m[0].reg, scalarReg);
                res[1].reg = _mm256_sub_pd(m[1].reg, scalarReg);
                res[2].reg = _mm256_sub_pd(m[2].reg, scalarReg);
                res[3].reg = _mm256_sub_pd(m[3].reg, scalarReg);

                return res;
            }
        };

        template<>
        struct matMul<4, 4, double, true> 
        {
            GLB_INLINE static glbMat_T<4, 4, double> call(const glbMat_T<4, 4, double>& a, const glbMat_T<4, 4, double>& b)
            {
                glbMat_T<4, 4, double> res;

                res[0].reg = _mm256_add_pd(
                    _mm256_add_pd(_mm256_mul_pd(a[0].reg, _mm256_set1_pd(b[0][0])), _mm256_mul_pd(a[1].reg, _mm256_set1_pd(b[0][1]))),
                    _mm256_add_pd(_mm256_mul_pd(a[2].reg, _mm256_set1_pd(b[0][2])), _mm256_mul_pd(a[3].reg, _mm256_set1_pd(b[0][3])))
                );

                res[1].reg = _mm256_add_pd(
                    _mm256_add_pd(_mm256_mul_pd(a[0].reg, _mm256_set1_pd(b[1][0])), _mm256_mul_pd(a[1].reg, _mm256_set1_pd(b[1][1]))),
                    _mm256_add_pd(_mm256_mul_pd(a[2].reg, _mm256_set1_pd(b[1][2])), _mm256_mul_pd(a[3].reg, _mm256_set1_pd(b[1][3])))
                );

                res[2].reg = _mm256_add_pd(
                    _mm256_add_pd(_mm256_mul_pd(a[0].reg, _mm256_set1_pd(b[2][0])), _mm256_mul_pd(a[1].reg, _mm256_set1_pd(b[2][1]))),
                    _mm256_add_pd(_mm256_mul_pd(a[2].reg, _mm256_set1_pd(b[2][2])), _mm256_mul_pd(a[3].reg, _mm256_set1_pd(b[2][3])))
                );

                res[3].reg = _mm256_add_pd(
                    _mm256_add_pd(_mm256_mul_pd(a[0].reg, _mm256_set1_pd(b[3][0])), _mm256_mul_pd(a[1].reg, _mm256_set1_pd(b[3][1]))),
                    _mm256_add_pd(_mm256_mul_pd(a[2].reg, _mm256_set1_pd(b[3][2])), _mm256_mul_pd(a[3].reg, _mm256_set1_pd(b[3][3])))
                );

                return res;
            }
        
            GLB_INLINE static glbMat_T<4, 4, double> call(const glbMat_T<4, 4, double>& m, double scalar)
            {
                glbMat_T<4, 4, double> res;
                const __m256d scalarReg = _mm256_set1_pd(scalar);

                res[0].reg = _mm256_mul_pd(m[0].reg, scalarReg);
                res[1].reg = _mm256_mul_pd(m[1].reg, scalarReg);
                res[2].reg = _mm256_mul_pd(m[2].reg, scalarReg);
                res[3].reg = _mm256_mul_pd(m[3].reg, scalarReg);

                return res;
            }

            GLB_INLINE static glbVec_T<4, double> call(const glbMat_T<4, 4, double>& m, const glbVec_T<4, double>& v)
            {
                glbVec_T<4, double> res;

                res.reg = _mm256_add_pd(
                    _mm256_add_pd(_mm256_mul_pd(m[0].reg, _mm256_set1_pd(v.x)), _mm256_mul_pd(m[1].reg, _mm256_set1_pd(v.y))),
                    _mm256_add_pd(_mm256_mul_pd(m[2].reg, _mm256_set1_pd(v.z)), _mm256_mul_pd(m[3].reg, _mm256_set1_pd(v.w)))
                );

                return res;
            }
        };

        template<>
        struct matDiv<4, 4, double, true> 
        {        
            GLB_INLINE static glbMat_T<4, 4, double> call(const glbMat_T<4, 4, double>& m, double scalar)
            {
                glbMat_T<4, 4, double> res;
                const __m256d scalarReg = _mm256_set1_pd(scalar);

                res[0].reg = _mm256_div_pd(m[0].reg, scalarReg);
                res[1].reg = _mm256_div_pd(m[1].reg, scalarReg);
                res[2].reg = _mm256_div_pd(m[2].reg, scalarReg);
                res[3].reg = _mm256_div_pd(m[3].reg, scalarReg);

                return res;
            }
        };
        

        template<>
        struct matNeg<4, 4, double, true> 
        {
            GLB_INLINE static glbMat_T<4, 4, double> call(const glbMat_T<4, 4, double>& m)
            {
                glbMat_T<4, 4, double> res;
                const __m256d m1Reg = _mm256_set1_pd(-1.0f);

                res[0].reg = _mm256_mul_pd(m[0].reg, m1Reg);
                res[1].reg = _mm256_mul_pd(m[1].reg, m1Reg);
                res[2].reg = _mm256_mul_pd(m[2].reg, m1Reg);
                res[3].reg = _mm256_mul_pd(m[3].reg, m1Reg);

                return res;
            }
        };

#       endif



    }
}