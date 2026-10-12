namespace glb
{
    namespace Mat
    {
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Translate(const glbVec_T<3, T>& trsl) noexcept
        {
            glbMat_T<4, 4, T> res;

            res[3] = glbVec_T<4, T>(trsl, static_cast<T>(1));

            return res;
        }

    } // namespace Mat
    
} // namespace glb
