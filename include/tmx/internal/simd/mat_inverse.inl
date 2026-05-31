#include "tmx/internal/simd/vec_geometric.inl"
#include "tmx/vec/geometric.hpp"

namespace tmx
{
    namespace internal
    {

#       if defined(TMX_SIMD_SSE)

        template<>
        struct matInverse<3, 3, float, true>
        {
            TMX_INLINE static mat<3, 3, float> call(const mat<3, 3, float>& m) noexcept
            {
                mat<3, 3, float> res;

                const vec<3, float> a = m[0];
                const vec<3, float> b = m[1];
                const vec<3, float> c = m[2];

                res[0] = Vec::Cross(b, c);
                res[1] = Vec::Cross(c, a);
                res[2] = Vec::Cross(a, b);

                const float invDet = 1.0f / (
                    Vec::Dot(a, Vec::Cross(b, c))
                );

                return res * invDet;
            }
        };

        template<>
        struct matInverseTranspose<3, 3, float, true>
        {
            TMX_INLINE static mat<3, 3, float> call(const mat<3, 3, float>& m) noexcept
            {
                mat<3, 3, float> res;

                const vec<3, float> a = m[0];
                const vec<3, float> b = m[1];
                const vec<3, float> c = m[2];

                res[0] = Vec::Cross(b, c);
                res[1] = Vec::Cross(c, a);
                res[2] = Vec::Cross(a, b);

				res = Mat::Transpose(res);

                const float invDet = 1.0f / (
                    Vec::Dot(a, Vec::Cross(b, c))
                );

                return res * invDet;
            }
        };

        template<>
        struct matInverse<4, 4, float, true>
        {
            TMX_INLINE static mat<4, 4, float> call(const mat<4, 4, float>& m) noexcept
            {
                // source : https://github.com/icaven/glm/blob/master/glm/simd/matrix.h

                mat<4, 4, float> res;

                __m128 fac0;
	            {
	            	//	valType SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
	            	//	valType SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
	            	//	valType SubFactor06 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
	            	//	valType SubFactor13 = m[1][2] * m[2][3] - m[2][2] * m[1][3];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(3, 3, 3, 3));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(2, 2, 2, 2));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(2, 2, 2, 2));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(3, 3, 3, 3));
                
	            	const __m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	const __m128 mul01 = _mm_mul_ps(swap02, swap03);

	            	fac0 = _mm_sub_ps(mul00, mul01);
	            }
            
	            __m128 fac1;
	            {
	            	//	valType SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
	            	//	valType SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
	            	//	valType SubFactor07 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
	            	//	valType SubFactor14 = m[1][1] * m[2][3] - m[2][1] * m[1][3];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(3, 3, 3, 3));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(1, 1, 1, 1));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(1, 1, 1, 1));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(3, 3, 3, 3));
                
	            	__m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	__m128 mul01 = _mm_mul_ps(swap02, swap03);

	            	fac1 = _mm_sub_ps(mul00, mul01);
	            }
            
            
	            __m128 fac2;
	            {
	            	//	valType SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
	            	//	valType SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
	            	//	valType SubFactor08 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
	            	//	valType SubFactor15 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(2, 2, 2, 2));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(1, 1, 1, 1));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(1, 1, 1, 1));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(2, 2, 2, 2));
                
	            	const __m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	const __m128 mul01 = _mm_mul_ps(swap02, swap03);
	            	
                    fac2 = _mm_sub_ps(mul00, mul01);
	            }
            
	            __m128 fac3;
	            {
	            	//	valType SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
	            	//	valType SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
	            	//	valType SubFactor09 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
	            	//	valType SubFactor16 = m[1][0] * m[2][3] - m[2][0] * m[1][3];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(3, 3, 3, 3));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(0, 0, 0, 0));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(0, 0, 0, 0));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(3, 3, 3, 3));
                
	            	const __m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	const __m128 mul01 = _mm_mul_ps(swap02, swap03);
	            	
                    fac3 = _mm_sub_ps(mul00, mul01);
	            }
            
	            __m128 fac4;
	            {
	            	//	valType SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
	            	//	valType SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
	            	//	valType SubFactor10 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
	            	//	valType SubFactor17 = m[1][0] * m[2][2] - m[2][0] * m[1][2];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(2, 2, 2, 2));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(0, 0, 0, 0));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(0, 0, 0, 0));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(2, 2, 2, 2));
                
	            	const __m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	const __m128 mul01 = _mm_mul_ps(swap02, swap03);
	            	
                    fac4 = _mm_sub_ps(mul00, mul01);
	            }
            
	            __m128 fac5;
	            {
	            	//	valType SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
	            	//	valType SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
	            	//	valType SubFactor12 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
	            	//	valType SubFactor18 = m[1][0] * m[2][1] - m[2][0] * m[1][1];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(1, 1, 1, 1));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(0, 0, 0, 0));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(0, 0, 0, 0));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(1, 1, 1, 1));
                
	            	const __m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	const __m128 mul01 = _mm_mul_ps(swap02, swap03);
	            	
                    fac5 = _mm_sub_ps(mul00, mul01);
	            }
            
	            const __m128 signA = _mm_set_ps(1.0f, -1.0f, 1.0f, -1.0f);
	            const __m128 signB = _mm_set_ps(-1.0f, 1.0f, -1.0f, 1.0f);
            
	            // m[1][0]
	            // m[0][0]
	            // m[0][0]
	            // m[0][0]
	            const __m128 temp0 = _mm_shuffle_ps(m[1].reg, m[0].reg, _MM_SHUFFLE(0, 0, 0, 0));
	            const __m128 vec0 = _mm_shuffle_ps(temp0, temp0, _MM_SHUFFLE(2, 2, 2, 0));
            
	            // m[1][1]
	            // m[0][1]
	            // m[0][1]
	            // m[0][1]
	            const __m128 temp1 = _mm_shuffle_ps(m[1].reg, m[0].reg, _MM_SHUFFLE(1, 1, 1, 1));
	            const __m128 vec1 = _mm_shuffle_ps(temp1, temp1, _MM_SHUFFLE(2, 2, 2, 0));
            
	            // m[1][2]
	            // m[0][2]
	            // m[0][2]
	            // m[0][2]
	            const __m128 temp2 = _mm_shuffle_ps(m[1].reg, m[0].reg, _MM_SHUFFLE(2, 2, 2, 2));
	            const __m128 vec2 = _mm_shuffle_ps(temp2, temp2, _MM_SHUFFLE(2, 2, 2, 0));
            
	            // m[1][3]
	            // m[0][3]
	            // m[0][3]
	            // m[0][3]
	            const __m128 temp3 = _mm_shuffle_ps(m[1].reg, m[0].reg, _MM_SHUFFLE(3, 3, 3, 3));
	            const __m128 vec3 = _mm_shuffle_ps(temp3, temp3, _MM_SHUFFLE(2, 2, 2, 0));
            
	            // col0
	            // + (Vec1[0] * Fac0[0] - Vec2[0] * Fac1[0] + Vec3[0] * Fac2[0]),
	            // - (Vec1[1] * Fac0[1] - Vec2[1] * Fac1[1] + Vec3[1] * Fac2[1]),
	            // + (Vec1[2] * Fac0[2] - Vec2[2] * Fac1[2] + Vec3[2] * Fac2[2]),
	            // - (Vec1[3] * Fac0[3] - Vec2[3] * Fac1[3] + Vec3[3] * Fac2[3]),
	            const __m128 mul00 = _mm_mul_ps(vec1, fac0);
	            const __m128 mul01 = _mm_mul_ps(vec2, fac1);
	            const __m128 mul02 = _mm_mul_ps(vec3, fac2);
	            const __m128 sub00 = _mm_sub_ps(mul00, mul01);
	            const __m128 add00 = _mm_add_ps(sub00, mul02);
	            const __m128 inv0 = _mm_mul_ps(signB, add00);
            
	            // col1
	            // - (Vec0[0] * Fac0[0] - Vec2[0] * Fac3[0] + Vec3[0] * Fac4[0]),
	            // + (Vec0[0] * Fac0[1] - Vec2[1] * Fac3[1] + Vec3[1] * Fac4[1]),
	            // - (Vec0[0] * Fac0[2] - Vec2[2] * Fac3[2] + Vec3[2] * Fac4[2]),
	            // + (Vec0[0] * Fac0[3] - Vec2[3] * Fac3[3] + Vec3[3] * Fac4[3]),
	            const __m128 mul03 = _mm_mul_ps(vec0, fac0);
	            const __m128 mul04 = _mm_mul_ps(vec2, fac3);
	            const __m128 mul05 = _mm_mul_ps(vec3, fac4);
	            const __m128 sub01 = _mm_sub_ps(mul03, mul04);
	            const __m128 add01 = _mm_add_ps(sub01, mul05);
	            const __m128 inv1 = _mm_mul_ps(signA, add01);
            
	            // col2
	            // + (Vec0[0] * Fac1[0] - Vec1[0] * Fac3[0] + Vec3[0] * Fac5[0]),
	            // - (Vec0[0] * Fac1[1] - Vec1[1] * Fac3[1] + Vec3[1] * Fac5[1]),
	            // + (Vec0[0] * Fac1[2] - Vec1[2] * Fac3[2] + Vec3[2] * Fac5[2]),
	            // - (Vec0[0] * Fac1[3] - Vec1[3] * Fac3[3] + Vec3[3] * Fac5[3]),
	            const __m128 mul06 = _mm_mul_ps(vec0, fac1);
	            const __m128 mul07 = _mm_mul_ps(vec1, fac3);
	            const __m128 mul08 = _mm_mul_ps(vec3, fac5);
	            const __m128 sub02 = _mm_sub_ps(mul06, mul07);
	            const __m128 add02 = _mm_add_ps(sub02, mul08);
	            const __m128 inv2 = _mm_mul_ps(signB, add02);
            
	            // col3
	            // - (Vec1[0] * Fac2[0] - Vec1[0] * Fac4[0] + Vec2[0] * Fac5[0]),
	            // + (Vec1[0] * Fac2[1] - Vec1[1] * Fac4[1] + Vec2[1] * Fac5[1]),
	            // - (Vec1[0] * Fac2[2] - Vec1[2] * Fac4[2] + Vec2[2] * Fac5[2]),
	            // + (Vec1[0] * Fac2[3] - Vec1[3] * Fac4[3] + Vec2[3] * Fac5[3]));
	            const __m128 mul09 = _mm_mul_ps(vec0, fac2);
	            const __m128 mul10 = _mm_mul_ps(vec1, fac4);
	            const __m128 mul11 = _mm_mul_ps(vec2, fac5);
	            const __m128 sub03 = _mm_sub_ps(mul09, mul10);
	            const __m128 add03 = _mm_add_ps(sub03, mul11);
	            const __m128 inv3 = _mm_mul_ps(signA, add03);
            
	            const __m128 row0 = _mm_shuffle_ps(inv0, inv1, _MM_SHUFFLE(0, 0, 0, 0));
	            const __m128 row1 = _mm_shuffle_ps(inv2, inv3, _MM_SHUFFLE(0, 0, 0, 0));
	            const __m128 row2 = _mm_shuffle_ps(row0, row1, _MM_SHUFFLE(2, 0, 2, 0));
            
	            //	valType Determinant = m[0][0] * Inverse[0][0]
	            //						+ m[0][1] * Inverse[1][0]
	            //						+ m[0][2] * Inverse[2][0]
	            //						+ m[0][3] * Inverse[3][0];
	            const __m128 invDet = _mm_div_ps(_mm_set1_ps(1.0f), internal::vecDot__m128(m[0].reg, row2));
            
	            //	Inverse /= Determinant;
	            res[0].reg = _mm_mul_ps(inv0, invDet);
	            res[1].reg = _mm_mul_ps(inv1, invDet);
	            res[2].reg = _mm_mul_ps(inv2, invDet);
	            res[3].reg = _mm_mul_ps(inv3, invDet);

				_MM_TRANSPOSE4_PS(res[0].reg, res[1].reg, res[2].reg, res[3].reg);

				return res;
            }
        };



        template<>
        struct matInverseTranspose<4, 4, float, true>
        {
            TMX_INLINE static mat<4, 4, float> call(const mat<4, 4, float>& m) noexcept
            {
                // source : https://github.com/icaven/glm/blob/master/glm/simd/matrix.h

                mat<4, 4, float> res;

                __m128 fac0;
	            {
	            	//	valType SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
	            	//	valType SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
	            	//	valType SubFactor06 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
	            	//	valType SubFactor13 = m[1][2] * m[2][3] - m[2][2] * m[1][3];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(3, 3, 3, 3));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(2, 2, 2, 2));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(2, 2, 2, 2));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(3, 3, 3, 3));
                
	            	const __m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	const __m128 mul01 = _mm_mul_ps(swap02, swap03);

	            	fac0 = _mm_sub_ps(mul00, mul01);
	            }
            
	            __m128 fac1;
	            {
	            	//	valType SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
	            	//	valType SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
	            	//	valType SubFactor07 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
	            	//	valType SubFactor14 = m[1][1] * m[2][3] - m[2][1] * m[1][3];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(3, 3, 3, 3));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(1, 1, 1, 1));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(1, 1, 1, 1));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(3, 3, 3, 3));
                
	            	__m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	__m128 mul01 = _mm_mul_ps(swap02, swap03);

	            	fac1 = _mm_sub_ps(mul00, mul01);
	            }
            
            
	            __m128 fac2;
	            {
	            	//	valType SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
	            	//	valType SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
	            	//	valType SubFactor08 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
	            	//	valType SubFactor15 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(2, 2, 2, 2));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(1, 1, 1, 1));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(1, 1, 1, 1));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(2, 2, 2, 2));
                
	            	const __m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	const __m128 mul01 = _mm_mul_ps(swap02, swap03);
	            	
                    fac2 = _mm_sub_ps(mul00, mul01);
	            }
            
	            __m128 fac3;
	            {
	            	//	valType SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
	            	//	valType SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
	            	//	valType SubFactor09 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
	            	//	valType SubFactor16 = m[1][0] * m[2][3] - m[2][0] * m[1][3];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(3, 3, 3, 3));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(0, 0, 0, 0));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(0, 0, 0, 0));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(3, 3, 3, 3));
                
	            	const __m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	const __m128 mul01 = _mm_mul_ps(swap02, swap03);
	            	
                    fac3 = _mm_sub_ps(mul00, mul01);
	            }
            
	            __m128 fac4;
	            {
	            	//	valType SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
	            	//	valType SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
	            	//	valType SubFactor10 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
	            	//	valType SubFactor17 = m[1][0] * m[2][2] - m[2][0] * m[1][2];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(2, 2, 2, 2));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(0, 0, 0, 0));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(0, 0, 0, 0));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(2, 2, 2, 2));
                
	            	const __m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	const __m128 mul01 = _mm_mul_ps(swap02, swap03);
	            	
                    fac4 = _mm_sub_ps(mul00, mul01);
	            }
            
	            __m128 fac5;
	            {
	            	//	valType SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
	            	//	valType SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
	            	//	valType SubFactor12 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
	            	//	valType SubFactor18 = m[1][0] * m[2][1] - m[2][0] * m[1][1];
                
	            	const __m128 swap0a = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(1, 1, 1, 1));
	            	const __m128 swap0b = _mm_shuffle_ps(m[3].reg, m[2].reg, _MM_SHUFFLE(0, 0, 0, 0));
                
	            	const __m128 swap00 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(0, 0, 0, 0));
	            	const __m128 swap01 = _mm_shuffle_ps(swap0a, swap0a, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap02 = _mm_shuffle_ps(swap0b, swap0b, _MM_SHUFFLE(2, 0, 0, 0));
	            	const __m128 swap03 = _mm_shuffle_ps(m[2].reg, m[1].reg, _MM_SHUFFLE(1, 1, 1, 1));
                
	            	const __m128 mul00 = _mm_mul_ps(swap00, swap01);
	            	const __m128 mul01 = _mm_mul_ps(swap02, swap03);
	            	
                    fac5 = _mm_sub_ps(mul00, mul01);
	            }
            
	            const __m128 signA = _mm_set_ps(1.0f, -1.0f, 1.0f, -1.0f);
	            const __m128 signB = _mm_set_ps(-1.0f, 1.0f, -1.0f, 1.0f);
            
	            // m[1][0]
	            // m[0][0]
	            // m[0][0]
	            // m[0][0]
	            const __m128 temp0 = _mm_shuffle_ps(m[1].reg, m[0].reg, _MM_SHUFFLE(0, 0, 0, 0));
	            const __m128 vec0 = _mm_shuffle_ps(temp0, temp0, _MM_SHUFFLE(2, 2, 2, 0));
            
	            // m[1][1]
	            // m[0][1]
	            // m[0][1]
	            // m[0][1]
	            const __m128 temp1 = _mm_shuffle_ps(m[1].reg, m[0].reg, _MM_SHUFFLE(1, 1, 1, 1));
	            const __m128 vec1 = _mm_shuffle_ps(temp1, temp1, _MM_SHUFFLE(2, 2, 2, 0));
            
	            // m[1][2]
	            // m[0][2]
	            // m[0][2]
	            // m[0][2]
	            const __m128 temp2 = _mm_shuffle_ps(m[1].reg, m[0].reg, _MM_SHUFFLE(2, 2, 2, 2));
	            const __m128 vec2 = _mm_shuffle_ps(temp2, temp2, _MM_SHUFFLE(2, 2, 2, 0));
            
	            // m[1][3]
	            // m[0][3]
	            // m[0][3]
	            // m[0][3]
	            const __m128 temp3 = _mm_shuffle_ps(m[1].reg, m[0].reg, _MM_SHUFFLE(3, 3, 3, 3));
	            const __m128 vec3 = _mm_shuffle_ps(temp3, temp3, _MM_SHUFFLE(2, 2, 2, 0));
            
	            // col0
	            // + (Vec1[0] * Fac0[0] - Vec2[0] * Fac1[0] + Vec3[0] * Fac2[0]),
	            // - (Vec1[1] * Fac0[1] - Vec2[1] * Fac1[1] + Vec3[1] * Fac2[1]),
	            // + (Vec1[2] * Fac0[2] - Vec2[2] * Fac1[2] + Vec3[2] * Fac2[2]),
	            // - (Vec1[3] * Fac0[3] - Vec2[3] * Fac1[3] + Vec3[3] * Fac2[3]),
	            const __m128 mul00 = _mm_mul_ps(vec1, fac0);
	            const __m128 mul01 = _mm_mul_ps(vec2, fac1);
	            const __m128 mul02 = _mm_mul_ps(vec3, fac2);
	            const __m128 sub00 = _mm_sub_ps(mul00, mul01);
	            const __m128 add00 = _mm_add_ps(sub00, mul02);
	            const __m128 inv0 = _mm_mul_ps(signB, add00);
            
	            // col1
	            // - (Vec0[0] * Fac0[0] - Vec2[0] * Fac3[0] + Vec3[0] * Fac4[0]),
	            // + (Vec0[0] * Fac0[1] - Vec2[1] * Fac3[1] + Vec3[1] * Fac4[1]),
	            // - (Vec0[0] * Fac0[2] - Vec2[2] * Fac3[2] + Vec3[2] * Fac4[2]),
	            // + (Vec0[0] * Fac0[3] - Vec2[3] * Fac3[3] + Vec3[3] * Fac4[3]),
	            const __m128 mul03 = _mm_mul_ps(vec0, fac0);
	            const __m128 mul04 = _mm_mul_ps(vec2, fac3);
	            const __m128 mul05 = _mm_mul_ps(vec3, fac4);
	            const __m128 sub01 = _mm_sub_ps(mul03, mul04);
	            const __m128 add01 = _mm_add_ps(sub01, mul05);
	            const __m128 inv1 = _mm_mul_ps(signA, add01);
            
	            // col2
	            // + (Vec0[0] * Fac1[0] - Vec1[0] * Fac3[0] + Vec3[0] * Fac5[0]),
	            // - (Vec0[0] * Fac1[1] - Vec1[1] * Fac3[1] + Vec3[1] * Fac5[1]),
	            // + (Vec0[0] * Fac1[2] - Vec1[2] * Fac3[2] + Vec3[2] * Fac5[2]),
	            // - (Vec0[0] * Fac1[3] - Vec1[3] * Fac3[3] + Vec3[3] * Fac5[3]),
	            const __m128 mul06 = _mm_mul_ps(vec0, fac1);
	            const __m128 mul07 = _mm_mul_ps(vec1, fac3);
	            const __m128 mul08 = _mm_mul_ps(vec3, fac5);
	            const __m128 sub02 = _mm_sub_ps(mul06, mul07);
	            const __m128 add02 = _mm_add_ps(sub02, mul08);
	            const __m128 inv2 = _mm_mul_ps(signB, add02);
            
	            // col3
	            // - (Vec1[0] * Fac2[0] - Vec1[0] * Fac4[0] + Vec2[0] * Fac5[0]),
	            // + (Vec1[0] * Fac2[1] - Vec1[1] * Fac4[1] + Vec2[1] * Fac5[1]),
	            // - (Vec1[0] * Fac2[2] - Vec1[2] * Fac4[2] + Vec2[2] * Fac5[2]),
	            // + (Vec1[0] * Fac2[3] - Vec1[3] * Fac4[3] + Vec2[3] * Fac5[3]));
	            const __m128 mul09 = _mm_mul_ps(vec0, fac2);
	            const __m128 mul10 = _mm_mul_ps(vec1, fac4);
	            const __m128 mul11 = _mm_mul_ps(vec2, fac5);
	            const __m128 sub03 = _mm_sub_ps(mul09, mul10);
	            const __m128 add03 = _mm_add_ps(sub03, mul11);
	            const __m128 inv3 = _mm_mul_ps(signA, add03);
            
	            const __m128 row0 = _mm_shuffle_ps(inv0, inv1, _MM_SHUFFLE(0, 0, 0, 0));
	            const __m128 row1 = _mm_shuffle_ps(inv2, inv3, _MM_SHUFFLE(0, 0, 0, 0));
	            const __m128 row2 = _mm_shuffle_ps(row0, row1, _MM_SHUFFLE(2, 0, 2, 0));
            
	            //	valType Determinant = m[0][0] * Inverse[0][0]
	            //						+ m[0][1] * Inverse[1][0]
	            //						+ m[0][2] * Inverse[2][0]
	            //						+ m[0][3] * Inverse[3][0];
	            const __m128 invDet = _mm_div_ps(_mm_set1_ps(1.0f), internal::vecDot__m128(m[0].reg, row2));
            
	            //	Inverse /= Determinant;
	            res[0].reg = _mm_mul_ps(inv0, invDet);
	            res[1].reg = _mm_mul_ps(inv1, invDet);
	            res[2].reg = _mm_mul_ps(inv2, invDet);
	            res[3].reg = _mm_mul_ps(inv3, invDet);

				return res;
            }
        };

#       endif

    }
}