namespace glb
{
    namespace glbIntern
    {
        template<int R, int C, typename T, bool useSimd>
        struct matDeterminant {};

        template<int R, int C, typename T, bool useSimd>
        struct matTranspose {};


        template<typename T, bool useSimd>
        struct matDeterminant<2, 2, T, useSimd>
        {
            GLB_INLINE static constexpr T call(const glbMat_T<2, 2, T>& m) noexcept
            {
                return m[0][0] * m[1][1] - m[0][1] * m[1][0];
            }
        };

        template<typename T, bool useSimd>
        struct matDeterminant<3, 3, T, useSimd>
        {
            GLB_INLINE static constexpr T call(const glbMat_T<3, 3, T>& m) noexcept
            {
                return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
                       m[1][0] * (m[0][1] * m[2][2] - m[0][2] * m[2][1]) +
                       m[2][0] * (m[0][1] * m[1][2] - m[0][2] * m[1][1]);
            }
        };

        template<typename T, bool useSimd>
        struct matDeterminant<4, 4, T, useSimd>
        {
            GLB_INLINE static constexpr T call(const glbMat_T<4, 4, T>& m) noexcept
            {
                

                const T sub0 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
			    const T sub1 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
			    const T sub2 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
			    const T sub3 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
			    const T sub4 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
			    const T sub5 = m[2][0] * m[3][1] - m[3][0] * m[2][1];

			    const T detCof0 =  (m[1][1] * sub0 - m[1][2] * sub1 + m[1][3] * sub2);
			    const T detCof1 = -(m[1][0] * sub0 - m[1][2] * sub3 + m[1][3] * sub4);
			    const T detCof2 =  (m[1][0] * sub1 - m[1][1] * sub3 + m[1][3] * sub5);
			    const T detCof3 = -(m[1][0] * sub2 - m[1][1] * sub4 + m[1][2] * sub5);

			    return
			    	m[0][0] * detCof0 + m[0][1] * detCof1 +
			    	m[0][2] * detCof2 + m[0][3] * detCof3;               
            }
        };

        template<typename T, bool useSimd>
        struct matTranspose<2, 2, T, useSimd>
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
        struct matTranspose<3, 3, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<3, 3, T> call(const glbMat_T<3, 3, T>& m) noexcept
            {
                return glbMat_T<3, 3, T>(
                    m[0][0], m[0][1], m[0][2],
                    m[1][0], m[1][1], m[1][2],
                    m[2][0], m[2][1], m[2][2]
                );
            }
        };

        template<typename T, bool useSimd>
        struct matTranspose<4, 4, T, useSimd>
        {
            GLB_INLINE static constexpr glbMat_T<4, 4, T> call(const glbMat_T<4, 4, T>& m) noexcept
            {
                return glbMat_T<4, 4, T>(
                    m[0][0], m[0][1], m[0][2], m[0][3],
                    m[1][0], m[1][1], m[1][2], m[1][3],
                    m[2][0], m[2][1], m[2][2], m[2][3],
                    m[3][0], m[3][1], m[3][2], m[3][3]
                );
            }
        };
        
    } // namespace glbIntern
    
    namespace Mat
    {
        template<int R, int C, typename T>
        GLB_INLINE constexpr T Determinant(const glbMat_T<R, C, T>& m) noexcept
        {
            return glbIntern::matDeterminant<R, C, T, glbIntern::useSimd<R, T>::value>::call(m);
        }

        template<int R, int C, typename T>
        GLB_INLINE constexpr glbMat_T<C, R, T> Transpose(const glbMat_T<R, C, T>& m) noexcept
        {
            return glbIntern::matTranspose<R, C, T, glbIntern::useSimd<R, T>::value>::call(m);
        }



        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> Cross(const glbVec_T<3, T>& v) noexcept
        {
            glbMat_T<3, 3, T> res(static_cast<T>(0));

            res[0][1] = v.z;
            res[1][0] = -v.z;
            res[0][2] = -v.y;
            res[2][0] = v.y;
            res[1][2] = v.x;
            res[2][1] = -v.x;

            return res;
        }
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Cross(const glbVec_T<3, T>& v) noexcept
        {
            glbMat_T<4, 4, T> res(static_cast<T>(0));

            res[0][1] = v.z;
            res[1][0] = -v.z;
            res[0][2] = -v.y;
            res[2][0] = v.y;
            res[1][2] = v.x;
            res[2][1] = -v.x;

            return res;
        }

    } // namespace Mat
    
} // namespace glb

#if !defined(GLB_SIMD_NONE)
#    include "../simd/mat_geometric.inl"

#endif