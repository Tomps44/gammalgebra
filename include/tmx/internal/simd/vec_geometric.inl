#pragma once

namespace tmx
{
    namespace internal
    {

#       if defined(TMX_SIMD_SSE)


        TMX_INLINE static __m128 vecDot__m128(__m128 a, __m128 b) noexcept
        {
#           if defined(TMX_SIMD_AVX)
                return _mm_dp_ps(a, b, 0xFF);

#           elif defined(TMX_SIMD_SSE3)
                const __m128 mul = _mm_mul_ps(a, b);
                const __m128 hadd0 = _mm_hadd_ps(mul, mul);
                const __m128 hadd1 = _mm_hadd_ps(hadd0, hadd0);

                return hadd1;

#           else
                const __m128 mul = _mm_mul_ps(a, b);
		        const __m128 swap0 = _mm_shuffle_ps(mul, mul, _MM_SHUFFLE(2, 3, 0, 1));
		        const __m128 add0 = _mm_add_ps(mul, swap0);
		        const __m128 swap1 = _mm_shuffle_ps(add0, add0, _MM_SHUFFLE(0, 1, 2, 3));
		        const __m128 add1 = _mm_add_ps(add0, swap1);

		        return add1;

#           endif
            
        }

        TMX_INLINE static __m128 vecLength__m128(__m128 v) noexcept
        {
            const __m128 dot = internal::vecDot__m128(v, v);

            return _mm_sqrt_ps(dot);
        }


        TMX_INLINE static __m128 vecDistance__m128(__m128 a, __m128 b) noexcept
        {
            const __m128 vec = _mm_sub_ps(b, a);

            return internal::vecLength__m128(vec);
        }



        TMX_INLINE static __m128 vecCross__m128(__m128 a, __m128 b) noexcept
        {
            const __m128 swap0 = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1));
	        const __m128 swap1 = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2));
	        const __m128 swap2 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1));
	        const __m128 swap3 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2));

	        const __m128 mul0 = _mm_mul_ps(swap0, swap3);
	        const __m128 mul1 = _mm_mul_ps(swap1, swap2);

	        const __m128 sub = _mm_sub_ps(mul0, mul1);

	        return sub;
        }
        


        TMX_INLINE static __m128 vecNormalize__m128(__m128 v) noexcept
        {
            const __m128 dot = internal::vecDot__m128(v, v);
            const __m128 invSqrt = _mm_rsqrt_ps(dot);
            const __m128 mul = _mm_mul_ps(dot, invSqrt);

	        return mul;
        }



        TMX_INLINE static __m128 vecReflect__m128(__m128 I, __m128 N)
        {
        	const __m128 dot = internal::vecDot__m128(N, I);

        	const __m128 mul0 = _mm_mul_ps(N, dot);
        	const __m128 mul1 = _mm_mul_ps(mul0, _mm_set1_ps(2.0f));

        	const __m128 sub = _mm_sub_ps(I, mul1);

        	return sub;
        }

#       endif


        // I don't think it is useful to implement it for HighP vectors (__m256d), 
        // since every single function relies on the dot product, 
        // and the dp for __m256d is not implemented by default, 
        // and the alternative is less precise and slower

        // HighP vectors will be more precise but will sacrifice performance  

    }
}