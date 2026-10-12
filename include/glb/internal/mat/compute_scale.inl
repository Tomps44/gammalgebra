namespace glb
{
    namespace Mat
    {

        template<typename T>
        GLB_INLINE constexpr glbMat_T<3, 3, T> Scale_3x3(const glbVec_T<3, T>& scale) noexcept
        {
            return glbMat_T<3, 3, T>(
                scale
            );
        }
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Scale_4x4(const glbVec_T<3, T>& scale) noexcept
        {
            return glbMat_T<4, 4, T>(
                glbVec_T<4, T>(
                    scale, static_cast<T>(1)
                )
            );
        }

    } // namespace Mat


} // namespace glb
