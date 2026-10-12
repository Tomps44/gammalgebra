namespace glb
{
    namespace glbIntern
    {
        template<int R, int C, typename T, bool useSimd>
        struct matInverse {};

        template<int R, int C, typename T, bool useSimd>
        struct matAffineInverse {};

        template<int R, int C, typename T, bool useSimd>
        struct matInverseTranspose {};


        template<typename T, bool useSimd>
        struct matInverse<2, 2, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<2, 2, T> call(const glbMat_T<2, 2, T>& m) noexcept
            {
                const T invDet = 
                    static_cast<T>(1) / (m[0][0] * m[1][1] - m[0][1] * m[1][0]);

                return glbMat_T<2, 2, T>(
                    m[1][1], -m[0][1],
                    -m[1][0], m[0][0]
                ) * invDet;
            }
        };

        template<typename T, bool useSimd>
        struct matInverse<3, 3, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(const glbMat_T<3, 3, T>& m) noexcept
            {
                const T invDet = 
                    static_cast<T>(1) / (m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
                       					 m[1][0] * (m[0][1] * m[2][2] - m[0][2] * m[2][1]) +
                       					 m[2][0] * (m[0][1] * m[1][2] - m[0][2] * m[1][1]));

				glbMat_T<3, 3, T> res;

				res[0][0] =  (m[1][1] * m[2][2] - m[1][2] * m[2][1]);
        		res[1][0] = -(m[0][1] * m[2][2] - m[0][2] * m[2][1]);
        		res[2][0] =  (m[0][1] * m[1][2] - m[0][2] * m[1][1]);
				
        		res[0][1] = -(m[1][0] * m[2][2] - m[1][2] * m[2][0]);
        		res[1][1] =  (m[0][0] * m[2][2] - m[0][2] * m[2][0]);
        		res[2][1] = -(m[0][0] * m[1][2] - m[0][2] * m[1][0]);
				
        		res[0][2] =  (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
        		res[1][2] = -(m[0][0] * m[2][1] - m[0][1] * m[2][0]);
        		res[2][2] =  (m[0][0] * m[1][1] - m[0][1] * m[1][0]);

                return res * invDet;
            }
        };

        template<typename T, bool useSimd>
        struct matInverse<4, 4, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(const glbMat_T<4, 4, T>& m) noexcept
            {
                const T coef00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
			    const T coef02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
			    const T coef03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];
			    const T coef04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
			    const T coef06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
			    const T coef07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];
			    const T coef08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
			    const T coef10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
			    const T coef11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
			    const T coef12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
			    const T coef14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
			    const T coef15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];
			    const T coef16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
			    const T coef18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
			    const T coef19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];
			    const T coef20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
			    const T coef22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
			    const T coef23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

			    const glbVec_T<4, T> fac0(coef00, coef00, coef02, coef03);
			    const glbVec_T<4, T> fac1(coef04, coef04, coef06, coef07);
			    const glbVec_T<4, T> fac2(coef08, coef08, coef10, coef11);
			    const glbVec_T<4, T> fac3(coef12, coef12, coef14, coef15);
			    const glbVec_T<4, T> fac4(coef16, coef16, coef18, coef19);
			    const glbVec_T<4, T> fac5(coef20, coef20, coef22, coef23);

			    const glbVec_T<4, T> vec0(m[1][0], m[0][0], m[0][0], m[0][0]);
			    const glbVec_T<4, T> vec1(m[1][1], m[0][1], m[0][1], m[0][1]);
			    const glbVec_T<4, T> vec2(m[1][2], m[0][2], m[0][2], m[0][2]);
			    const glbVec_T<4, T> vec3(m[1][3], m[0][3], m[0][3], m[0][3]);

			    const glbVec_T<4, T> inv0 = vec1 * fac0 - vec2 * fac1 + vec3 * fac2;
			    const glbVec_T<4, T> inv1 = vec0 * fac0 - vec2 * fac3 + vec3 * fac4;
			    const glbVec_T<4, T> inv2 = vec0 * fac1 - vec1 * fac3 + vec3 * fac5;
			    const glbVec_T<4, T> inv3 = vec0 * fac2 - vec1 * fac4 + vec2 * fac5;

			    const glbVec_T<4, T> signA( 1, -1,  1, -1);
			    const glbVec_T<4, T> signB(-1,  1, -1,  1);

			    const glbMat_T<4, 4, T> res(inv0 * signA, inv1 * signB, inv2 * signA, inv3 * signB);



			    const T detCof0 =  (m[1][1] * coef00 - m[1][2] * coef04 + m[1][3] * coef08);
			    const T detCof1 = -(m[1][0] * coef00 - m[1][2] * coef12 + m[1][3] * coef16);
			    const T detCof2 =  (m[1][0] * coef04 - m[1][1] * coef12 + m[1][3] * coef20);
			    const T detCof3 = -(m[1][0] * coef08 - m[1][1] * coef16 + m[1][2] * coef20);

			    const T invDet = static_cast<T>(1) / (
					m[0][0] * detCof0 + m[0][1] * detCof1 +
			    	m[0][2] * detCof2 + m[0][3] * detCof3
				);

			    return res * invDet;
			}
        };


        
        

        template<typename T, bool useSimd>
        struct matAffineInverse<2, 2, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<2, 2, T> call(const glbMat_T<2, 2, T>& m) noexcept
            {
                return glbMat_T<2, 2, T>(
                    m[0][0], m[0][1],
                    m[1][0], m[1][1]
                );
            }
        };

        template<typename T, bool useSimd>
        struct matAffineInverse<3, 3, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(const glbMat_T<3, 3, T>& m) noexcept
            {
                const glbMat_T<2, 2, T> invTopLeft2x2 = Mat::Inverse(glbMat_T<2, 2, T>(m));
                const glbVec_T<2, T> rightCol2(m[2]);

                glbMat_T<3, 3, T> res(invTopLeft2x2);

                res[2] = glbVec_T<3, T>(-(invTopLeft2x2 * rightCol2), static_cast<T>(1));

                return res;
            }
        };

        template<typename T, bool useSimd>
        struct matAffineInverse<4, 4, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(const glbMat_T<4, 4, T>& m) noexcept
            {
                const glbMat_T<3, 3, T> invTopLeft3x3 = Mat::Inverse(glbMat_T<3, 3, T>(m));
                const glbVec_T<3, T> rightCol3(m[3]);

                glbMat_T<4, 4, T> res(invTopLeft3x3);

                res[3] = glbVec_T<4, T>(-(invTopLeft3x3 * rightCol3), static_cast<T>(1));

                return res;
            }
        };



        template<typename T, bool useSimd>
        struct matInverseTranspose<2, 2, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<2, 2, T> call(const glbMat_T<2, 2, T>& m) noexcept
            {
                const T invDet = 
                    static_cast<T>(1) / (m[0][0] * m[1][1] - m[0][1] * m[1][0]);

                return glbMat_T<2, 2, T>(
                    m[1][1], -m[1][0],
                    -m[0][1], m[0][0]
                ) * invDet;
            }
        };

        template<typename T, bool useSimd>
        struct matInverseTranspose<3, 3, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(const glbMat_T<3, 3, T>& m) noexcept
            {
                const T invDet = 
                    static_cast<T>(1) / (m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
                       					 m[1][0] * (m[0][1] * m[2][2] - m[0][2] * m[2][1]) +
                       					 m[2][0] * (m[0][1] * m[1][2] - m[0][2] * m[1][1]));

				glbMat_T<3, 3, T> res;

				res[0][0] =  (m[1][1] * m[2][2] - m[1][2] * m[2][1]);
        		res[0][1] = -(m[0][1] * m[2][2] - m[0][2] * m[2][1]);
        		res[0][2] =  (m[0][1] * m[1][2] - m[0][2] * m[1][1]);
				
        		res[1][0] = -(m[1][0] * m[2][2] - m[1][2] * m[2][0]);
        		res[1][1] =  (m[0][0] * m[2][2] - m[0][2] * m[2][0]);
        		res[1][2] = -(m[0][0] * m[1][2] - m[0][2] * m[1][0]);
				
        		res[2][0] =  (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
        		res[2][1] = -(m[0][0] * m[2][1] - m[0][1] * m[2][0]);
        		res[2][2] =  (m[0][0] * m[1][1] - m[0][1] * m[1][0]);

                return res * invDet;
            }
        };

        template<typename T, bool useSimd>
        struct matInverseTranspose<4, 4, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(const glbMat_T<4, 4, T>& m) noexcept
            {
                const T sub00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
		        const T sub01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
		        const T sub02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
		        const T sub03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
		        const T sub04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
		        const T sub05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
		        const T sub06 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
		        const T sub07 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
		        const T sub08 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
		        const T sub09 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
		        const T sub10 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
		        const T sub11 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
		        const T sub12 = m[1][2] * m[2][3] - m[2][2] * m[1][3];
		        const T sub13 = m[1][1] * m[2][3] - m[2][1] * m[1][3];
		        const T sub14 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
		        const T sub15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];
		        const T sub16 = m[1][0] * m[2][2] - m[2][0] * m[1][2];
		        const T sub17 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

		        glbMat_T<4, 4, T> res;

		        res[0][0] = + (m[1][1] * sub00 - m[1][2] * sub01 + m[1][3] * sub02);
		        res[1][0] = - (m[1][0] * sub00 - m[1][2] * sub03 + m[1][3] * sub04);
		        res[2][0] = + (m[1][0] * sub01 - m[1][1] * sub03 + m[1][3] * sub05);
		        res[3][0] = - (m[1][0] * sub02 - m[1][1] * sub04 + m[1][2] * sub05);

		        res[0][1] = - (m[0][1] * sub00 - m[0][2] * sub01 + m[0][3] * sub02);
		        res[1][1] = + (m[0][0] * sub00 - m[0][2] * sub03 + m[0][3] * sub04);
		        res[2][1] = - (m[0][0] * sub01 - m[0][1] * sub03 + m[0][3] * sub05);
		        res[3][1] = + (m[0][0] * sub02 - m[0][1] * sub04 + m[0][2] * sub05);

		        res[0][2] = + (m[0][1] * sub06 - m[0][2] * sub07 + m[0][3] * sub08);
		        res[1][2] = - (m[0][0] * sub06 - m[0][2] * sub09 + m[0][3] * sub10);
		        res[2][2] = + (m[0][0] * sub07 - m[0][1] * sub09 + m[0][3] * sub11);
		        res[3][2] = - (m[0][0] * sub08 - m[0][1] * sub10 + m[0][2] * sub11);

		        res[0][3] = - (m[0][1] * sub12 - m[0][2] * sub13 + m[0][3] * sub14);
		        res[1][3] = + (m[0][0] * sub12 - m[0][2] * sub15 + m[0][3] * sub16);
		        res[2][3] = - (m[0][0] * sub13 - m[0][1] * sub15 + m[0][3] * sub17);
		        res[3][3] = + (m[0][0] * sub14 - m[0][1] * sub16 + m[0][2] * sub17);


                const T detCof0 =  (m[1][1] * sub00 - m[1][2] * sub01 + m[1][3] * sub02);
			    const T detCof1 = -(m[1][0] * sub00 - m[1][2] * sub03 + m[1][3] * sub04);
			    const T detCof2 =  (m[1][0] * sub01 - m[1][1] * sub03 + m[1][3] * sub05);
			    const T detCof3 = -(m[1][0] * sub02 - m[1][1] * sub04 + m[1][2] * sub05);

			    const T invDet = static_cast<T>(1) / (
					m[0][0] * detCof0 + m[0][1] * detCof1 +
			    	m[0][2] * detCof2 + m[0][3] * detCof3
				);

		        return res * invDet;
            }
        };

        

        

    } // namespace glbIntern
    
    namespace Mat
    {
        template<int R, int C, typename T>
        GLB_INLINE constexpr glbMat_T<R, C, T> Inverse(const glbMat_T<R, C, T>& m) noexcept
        {
            return glbIntern::matInverse<R, C, T, glbIntern::useSimd<R, T>::value>::call(m);
        }

        template<int R, int C, typename T>
        GLB_INLINE constexpr glbMat_T<R, C, T> AffineInverse(const glbMat_T<R, C, T>& m) noexcept
        {
            return glbIntern::matAffineInverse<R, C, T, glbIntern::useSimd<R, T>::value>::call(m);
        }

        template<int R, int C, typename T>
        GLB_INLINE constexpr glbMat_T<R, C, T> InverseTranspose(const glbMat_T<R, C, T>& m) noexcept
        {
            return glbIntern::matInverseTranspose<R, C, T, glbIntern::useSimd<R, T>::value>::call(m);
        }

    } // namespace Mat
    
} // namespace glb


#if !defined(GLB_SIMD_NONE)
#    include "../simd/mat_inverse.inl"

#endif