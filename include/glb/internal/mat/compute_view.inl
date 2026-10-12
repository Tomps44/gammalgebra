#include "../../vec/geometric.h"

namespace glb
{
    namespace glbDetail
    {
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> LookAt_LH(const glbVec_T<3, T>& eye, const glbVec_T<3, T>& target, const glbVec_T<3, T>& worldUp) noexcept
        {
            const glbVec_T<3, T>& forward = Vec::Normalize(target - eye);
            const glbVec_T<3, T>& right = Vec::Normalize(Vec::Cross(worldUp, forward));
            const glbVec_T<3, T>& up = Vec::Normalize(Vec::Cross(forward, right));

            glbMat_T<4, 4, T> res;

            res[0][0] = right.x;
            res[1][0] = right.y;
            res[2][0] = right.z;
            res[3][0] = -Vec::Dot(right, eye);

            res[0][1] = up.x;
            res[1][1] = up.y;
            res[2][1] = up.z;
            res[3][1] = -Vec::Dot(up, eye);

            res[0][2] = forward.x;
            res[1][2] = forward.y;
            res[2][2] = forward.z;
            res[3][2] = -Vec::Dot(forward, eye);
            
            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> LookAt_RH(const glbVec_T<3, T>& eye, const glbVec_T<3, T>& target, const glbVec_T<3, T>& worldUp) noexcept
        {
            const glbVec_T<3, T>& forward = Vec::Normalize(eye - target);
            const glbVec_T<3, T>& right = Vec::Normalize(Vec::Cross(worldUp, forward));
            const glbVec_T<3, T>& up = Vec::Normalize(Vec::Cross(forward, right));

            glbMat_T<4, 4, T> res;

            res[0][0] = right.x;
            res[1][0] = right.y;
            res[2][0] = right.z;
            res[3][0] = Vec::Dot(right, eye);

            res[0][1] = up.x;
            res[1][1] = up.y;
            res[2][1] = up.z;
            res[3][1] = Vec::Dot(up, eye);

            res[0][2] = forward.x;
            res[1][2] = forward.y;
            res[2][2] = forward.z;
            res[3][2] = Vec::Dot(forward, eye);
            
            return res;
        }
        
    } // namespace glbDetail

    namespace Mat
    {
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> LookAt(const glbVec_T<3, T>& eye, const glbVec_T<3, T>& target, const glbVec_T<3, T>& worldUp) noexcept
        {
#           if defined(GLB_SET_COORDINATE_SYSTEM_LH)
                return glbDetail::LookAt_LH(eye, target, worldUp);

#           else
                return glbDetail::LookAt_RH(eye, target, worldUp);
                
#           endif
        }

    } // namespace Mat
    
} // namespace glb
