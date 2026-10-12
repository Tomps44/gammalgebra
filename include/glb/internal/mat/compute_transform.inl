#include "../../quat/euler.h"

namespace glb
{
    namespace Mat
    {
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> TRS(const glbVec_T<3, T>& trsl, const glbQuat_T<T>& rot, const glbVec_T<3, T>& scale) noexcept
        {
            glbMat_T<4, 4, T> res = Mat::FromQuat_4x4(rot);

            res[0] *= scale.x; 
            res[1] *= scale.y; 
            res[2] *= scale.z; 

            res[3] = glbVec_T<4, T>(trsl, static_cast<T>(1));

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> TRS(const glbVec_T<3, T>& trsl, const glbVec_T<3, T>& rot, const glbVec_T<3, T>& scale) noexcept
        {
            return Mat::TRS(trsl, Qua::FromEuler(rot), scale);
        }



    }

}