#pragma once

#include "tmx/internal/simd/vec_geometric.inl"

namespace tmx
{
    namespace internal
    {

#       if defined(TMX_SIMD_SSE)

        template<>
        struct matTranspose<4, 4, float, true>
        {
            TMX_INLINE static mat<4, 4, float> call(const mat<4, 4, float>& m) noexcept
            {
                mat<4, 4, float> res = m;

				_MM_TRANSPOSE4_PS(res[0].reg, res[1].reg, res[2].reg, res[3].reg);

				return res;
            }
        };

        template<>
        struct matDeterminant<4, 4, float, true>
        {
            TMX_INLINE static float call(const mat<4, 4, float>& m) noexcept
            {
				// source : https://github.com/icaven/glm/blob/master/glm/simd/matrix.h


				//T SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
				//T SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
				//T SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
				//T SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
				//T SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
				//T SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];

                // First 2 columns
                const __m128 swap2A = _mm_shuffle_ps(m[2].reg, m[2].reg, _MM_SHUFFLE(0, 1, 1, 2));
 	            const __m128 swap3A = _mm_shuffle_ps(m[3].reg, m[3].reg, _MM_SHUFFLE(3, 2, 3, 3));
	            const __m128 mulA = _mm_mul_ps(swap2A, swap3A);

	            // Second 2 columns
	            const __m128 swap2B = _mm_shuffle_ps(m[2].reg, m[2].reg, _MM_SHUFFLE(3, 2, 3, 3));
	            const __m128 swap3B = _mm_shuffle_ps(m[3].reg, m[3].reg, _MM_SHUFFLE(0, 1, 1, 2));
	            const __m128 mulB = _mm_mul_ps(swap2B, swap3B);

	            // Columns subtraction
	            const __m128 subE = _mm_sub_ps(mulA, mulB);

	            // Last 2 rows
	            const __m128 swap2C = _mm_shuffle_ps(m[2].reg, m[2].reg, _MM_SHUFFLE(0, 0, 1, 2));
	            const __m128 swap3C = _mm_shuffle_ps(m[3].reg, m[3].reg, _MM_SHUFFLE(1, 2, 0, 0));
	            const __m128 mulC = _mm_mul_ps(swap2C, swap3C);
	            const __m128 subF = _mm_sub_ps(_mm_movehl_ps(mulC, mulC), mulC);

	            //vec<4, T, Q> DetCof(
	            //	+ (m[1][1] * SubFactor00 - m[1][2] * SubFactor01 + m[1][3] * SubFactor02),
	            //	- (m[1][0] * SubFactor00 - m[1][2] * SubFactor03 + m[1][3] * SubFactor04),
	            //	+ (m[1][0] * SubFactor01 - m[1][1] * SubFactor03 + m[1][3] * SubFactor05),
	            //	- (m[1][0] * SubFactor02 - m[1][1] * SubFactor04 + m[1][2] * SubFactor05));

	            const __m128 subFacA = _mm_shuffle_ps(subE, subE, _MM_SHUFFLE(2, 1, 0, 0));
	            const __m128 swapFacA = _mm_shuffle_ps(m[1].reg, m[1].reg, _MM_SHUFFLE(0, 0, 0, 1));
	            const __m128 mulFacA = _mm_mul_ps(swapFacA, subFacA);

	            const __m128 subTmpB = _mm_shuffle_ps(subE, subF, _MM_SHUFFLE(0, 0, 3, 1));
	            const __m128 subFacB = _mm_shuffle_ps(subTmpB, subTmpB, _MM_SHUFFLE(3, 1, 1, 0));//SubF[0], SubE[3], SubE[3], SubE[1];
	            const __m128 swapFacB = _mm_shuffle_ps(m[1].reg, m[1].reg, _MM_SHUFFLE(1, 1, 2, 2));
	            const __m128 mulFacB = _mm_mul_ps(swapFacB, subFacB);

	            const __m128 subRes = _mm_sub_ps(mulFacA, mulFacB);

	            const __m128 subTmpC = _mm_shuffle_ps(subE, subF, _MM_SHUFFLE(1, 0, 2, 2));
	            const __m128 subFacC = _mm_shuffle_ps(subTmpC, subTmpC, _MM_SHUFFLE(3, 3, 2, 0));
	            const __m128 swapFacC = _mm_shuffle_ps(m[1].reg, m[1].reg, _MM_SHUFFLE(2, 3, 3, 3));
	            const __m128 mulFacC = _mm_mul_ps(swapFacC, subFacC);

	            const __m128 addRes = _mm_add_ps(subRes, mulFacC);
	            const __m128 detCof = _mm_mul_ps(addRes, _mm_setr_ps(1.0f, -1.0f, 1.0f, -1.0f));

	            //return m[0][0] * DetCof[0]
	            //	 + m[0][1] * DetCof[1]
	            //	 + m[0][2] * DetCof[2]
	            //	 + m[0][3] * DetCof[3];

	            return _mm_cvtss_f32(internal::vecDot__m128(m[0].reg, detCof));
            }
        };

#       endif

    }
}