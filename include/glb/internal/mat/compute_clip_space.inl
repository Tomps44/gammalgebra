#include <cmath>

namespace glb
{
    namespace glbDetail
    {
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Perspective_LH_Z0_YUP(T fovY, T aspect, T zNear, T zFar) noexcept
        {
            glbMat_T<4, 4, T> res(static_cast<T>(0)); // Sets the matrix to all 0

            const T invTanHalfFov = static_cast<T>(1) / std::tan(fovY * static_cast<T>(0.5)); 
            const T invFarMinusNear = static_cast<T>(1) / (zFar - zNear);

            res[0][0] = invTanHalfFov / aspect;
            res[1][1] = invTanHalfFov;
            res[2][2] = zFar * invFarMinusNear;
            res[2][3] = static_cast<T>(1);
            res[3][2] = -(zFar * zNear) * invFarMinusNear;

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Perspective_LH_ZN1_YUP(T fovY, T aspect, T zNear, T zFar) noexcept
        {
            glbMat_T<4, 4, T> res(static_cast<T>(0)); // Sets the matrix to all 0

            const T invTanHalfFov = static_cast<T>(1) / std::tan(fovY * static_cast<T>(0.5)); 
            const T invFarMinusNear = static_cast<T>(1) / (zFar - zNear);

            res[0][0] = invTanHalfFov / aspect;
            res[1][1] = invTanHalfFov;
            res[2][2] = -(zFar + zNear) * invFarMinusNear;
            res[2][3] = static_cast<T>(1);
            res[3][2] = (static_cast<T>(2) * zFar * zNear) * invFarMinusNear;

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Perspective_LH_Z0_YDOWN(T fovY, T aspect, T zNear, T zFar) noexcept
        {
            glbMat_T<4, 4, T> res(static_cast<T>(0)); // Sets the matrix to all 0

            const T invTanHalfFov = static_cast<T>(1) / std::tan(fovY * static_cast<T>(0.5)); 
            const T invFarMinusNear = static_cast<T>(1) / (zFar - zNear);

            res[0][0] = invTanHalfFov / aspect;
            res[1][1] = -invTanHalfFov;
            res[2][2] = zFar * invFarMinusNear;
            res[2][3] = static_cast<T>(1);
            res[3][2] = -(zFar * zNear) * invFarMinusNear;

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Perspective_LH_ZN1_YDOWN(T fovY, T aspect, T zNear, T zFar) noexcept
        {
            glbMat_T<4, 4, T> res(static_cast<T>(0)); // Sets the matrix to all 0

            const T invTanHalfFov = static_cast<T>(1) / std::tan(fovY * static_cast<T>(0.5)); 
            const T invFarMinusNear = static_cast<T>(1) / (zFar - zNear);

            res[0][0] = invTanHalfFov / aspect;
            res[1][1] = -invTanHalfFov;
            res[2][2] = -(zFar + zNear) * invFarMinusNear;
            res[2][3] = static_cast<T>(1);
            res[3][2] = (static_cast<T>(2) * zFar * zNear) * invFarMinusNear;

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Perspective_RH_Z0_YUP(T fovY, T aspect, T zNear, T zFar) noexcept
        {
            glbMat_T<4, 4, T> res(static_cast<T>(0)); // Sets the matrix to all 0

            const T invTanHalfFov = static_cast<T>(1) / std::tan(fovY * static_cast<T>(0.5)); 
            const T invFarMinusNear = static_cast<T>(1) / (zFar - zNear);

            res[0][0] = invTanHalfFov / aspect;
            res[1][1] = invTanHalfFov;
            res[2][2] = zFar * invFarMinusNear;
            res[2][3] = static_cast<T>(-1);
            res[3][2] = (zFar * zNear) * invFarMinusNear;

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Perspective_RH_ZN1_YUP(T fovY, T aspect, T zNear, T zFar) noexcept
        {
            glbMat_T<4, 4, T> res(static_cast<T>(0)); // Sets the matrix to all 0

            const T invTanHalfFov = static_cast<T>(1) / std::tan(fovY * static_cast<T>(0.5)); 
            const T invFarMinusNear = static_cast<T>(1) / (zFar - zNear);

            res[0][0] = invTanHalfFov / aspect;
            res[1][1] = invTanHalfFov;
            res[2][2] = -(zFar + zNear) * invFarMinusNear;
            res[2][3] = static_cast<T>(-1);
            res[3][2] = -(static_cast<T>(2) * zFar * zNear) * invFarMinusNear;

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Perspective_RH_Z0_YDOWN(T fovY, T aspect, T zNear, T zFar) noexcept
        {
            glbMat_T<4, 4, T> res(static_cast<T>(0)); // Sets the matrix to all 0

            const T invTanHalfFov = static_cast<T>(1) / std::tan(fovY * static_cast<T>(0.5)); 
            const T invFarMinusNear = static_cast<T>(1) / (zFar - zNear);

            res[0][0] = invTanHalfFov / aspect;
            res[1][1] = -invTanHalfFov;
            res[2][2] = zFar * invFarMinusNear;
            res[2][3] = static_cast<T>(-1);
            res[3][2] = (zFar * zNear) * invFarMinusNear;

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Perspective_RH_ZN1_YDOWN(T fovY, T aspect, T zNear, T zFar) noexcept
        {
            glbMat_T<4, 4, T> res(static_cast<T>(0)); // Sets the matrix to all 0

            const T invTanHalfFov = static_cast<T>(1) / std::tan(fovY * static_cast<T>(0.5)); 
            const T invFarMinusNear = static_cast<T>(1) / (zFar - zNear);

            res[0][0] = invTanHalfFov / aspect;
            res[1][1] = -invTanHalfFov;
            res[2][2] = -(zFar + zNear) * invFarMinusNear;
            res[2][3] = static_cast<T>(-1);
            res[3][2] = -(static_cast<T>(2) * zFar * zNear) * invFarMinusNear;

            return res;
        }






        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_LH_Z0(T left, T right, T bottom, T top, T near, T far) noexcept
        // GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_LH_Z0_YUP(T left, T right, T bottom, T top, T near, T far) noexcept
        {
            glbMat_T<4, 4, T> res;

            const T invRightMinusLeft = static_cast<T>(1) / (right - left); 
            const T invTopMinusBottom = static_cast<T>(1) / (top - bottom); 
            const T invFarMinusNear = static_cast<T>(1) / (far - near); 

            res[0][0] = static_cast<T>(2) * invRightMinusLeft;
            res[1][1] = static_cast<T>(2) * invTopMinusBottom;
            res[2][2] = static_cast<T>(1) * invFarMinusNear;
            res[3][0] = -(right + left) * invRightMinusLeft;
            res[3][1] = -(top + bottom) * invTopMinusBottom;
            res[3][2] = -near * invFarMinusNear;

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_RH_Z0(T left, T right, T bottom, T top, T near, T far) noexcept
        // GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_RH_Z0_YUP(T left, T right, T bottom, T top, T near, T far) noexcept
        {
            glbMat_T<4, 4, T> res;

            const T invRightMinusLeft = static_cast<T>(1) / (right - left); 
            const T invTopMinusBottom = static_cast<T>(1) / (top - bottom); 
            const T invFarMinusNear = static_cast<T>(1) / (far - near); 

            res[0][0] = static_cast<T>(2) * invRightMinusLeft;
            res[1][1] = static_cast<T>(2) * invTopMinusBottom;
            res[2][2] = static_cast<T>(-1) * invFarMinusNear;
            res[3][0] = -(right + left) * invRightMinusLeft;
            res[3][1] = -(top + bottom) * invTopMinusBottom;
            res[3][2] = near * invFarMinusNear;

            return res;
        }

        // template<typename T>
        // GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_LH_Z0_YDOWN(T left, T right, T bottom, T top, T near, T far) noexcept
        // {
        //     glbMat_T<4, 4, T> res;

        //     const T invRightMinusLeft = static_cast<T>(1) / (right - left); 
        //     const T invTopMinusBottom = static_cast<T>(1) / (top - bottom); 
        //     const T invFarMinusNear = static_cast<T>(1) / (far - near); 

        //     res[0][0] = static_cast<T>(2) * invRightMinusLeft;
        //     res[1][1] = static_cast<T>(-2) * invTopMinusBottom;
        //     res[2][2] = static_cast<T>(1) * invFarMinusNear;
        //     res[3][0] = -(right + left) * invRightMinusLeft;
        //     res[3][1] = (top + bottom) * invTopMinusBottom;
        //     res[3][2] = -near * invFarMinusNear;

        //     return res;
        // }

        // template<typename T>
        // GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_RH_Z0_YDOWN(T left, T right, T bottom, T top, T near, T far) noexcept
        // {
        //     glbMat_T<4, 4, T> res;

        //     const T invRightMinusLeft = static_cast<T>(1) / (right - left); 
        //     const T invTopMinusBottom = static_cast<T>(1) / (top - bottom); 
        //     const T invFarMinusNear = static_cast<T>(1) / (far - near); 

        //     res[0][0] = static_cast<T>(2) * invRightMinusLeft;
        //     res[1][1] = static_cast<T>(-2) * invTopMinusBottom;
        //     res[2][2] = static_cast<T>(-1) * invFarMinusNear;
        //     res[3][0] = -(right + left) * invRightMinusLeft;
        //     res[3][1] = (top + bottom) * invTopMinusBottom;
        //     res[3][2] = near * invFarMinusNear;

        //     return res;
        // }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_LH_ZN1(T left, T right, T bottom, T top, T near, T far) noexcept
        // GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_LH_ZN1_YUP(T left, T right, T bottom, T top, T near, T far) noexcept
        {
            glbMat_T<4, 4, T> res;

            const T invRightMinusLeft = static_cast<T>(1) / (right - left); 
            const T invTopMinusBottom = static_cast<T>(1) / (top - bottom); 
            const T invFarMinusNear = static_cast<T>(1) / (far - near); 

            res[0][0] = static_cast<T>(2) * invRightMinusLeft;
            res[1][1] = static_cast<T>(2) * invTopMinusBottom;
            res[2][2] = static_cast<T>(2) * invFarMinusNear;
            res[3][0] = -(right + left) * invRightMinusLeft;
            res[3][1] = -(top + bottom) * invTopMinusBottom;
            res[3][2] = (far + near) * invFarMinusNear;

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_RH_ZN1(T left, T right, T bottom, T top, T near, T far) noexcept
        // GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_RH_ZN1_YUP(T left, T right, T bottom, T top, T near, T far) noexcept
        {
            glbMat_T<4, 4, T> res;

            const T invRightMinusLeft = static_cast<T>(1) / (right - left); 
            const T invTopMinusBottom = static_cast<T>(1) / (top - bottom); 
            const T invFarMinusNear = static_cast<T>(1) / (far - near); 

            res[0][0] = static_cast<T>(2) * invRightMinusLeft;
            res[1][1] = static_cast<T>(2) * invTopMinusBottom;
            res[2][2] = static_cast<T>(-2) * invFarMinusNear;
            res[3][0] = -(right + left) * invRightMinusLeft;
            res[3][1] = -(top + bottom) * invTopMinusBottom;
            res[3][2] = -(far + near) * invFarMinusNear;

            return res;
        }

        // template<typename T>
        // GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_LH_ZN1_YDOWN(T left, T right, T bottom, T top, T near, T far) noexcept
        // {
        //     glbMat_T<4, 4, T> res;

        //     const T invRightMinusLeft = static_cast<T>(1) / (right - left); 
        //     const T invTopMinusBottom = static_cast<T>(1) / (top - bottom); 
        //     const T invFarMinusNear = static_cast<T>(1) / (far - near); 

        //     res[0][0] = static_cast<T>(2) * invRightMinusLeft;
        //     res[1][1] = static_cast<T>(-2) * invTopMinusBottom;
        //     res[2][2] = static_cast<T>(2) * invFarMinusNear;
        //     res[3][0] = -(right + left) * invRightMinusLeft;
        //     res[3][1] = (top + bottom) * invTopMinusBottom;
        //     res[3][2] = (far + near) * invFarMinusNear;

        //     return res;
        // }
        // template<typename T>
        // GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic_RH_ZN1_YDOWN(T left, T right, T bottom, T top, T near, T far) noexcept
        // {
        //     glbMat_T<4, 4, T> res;

        //     const T invRightMinusLeft = static_cast<T>(1) / (right - left); 
        //     const T invTopMinusBottom = static_cast<T>(1) / (top - bottom); 
        //     const T invFarMinusNear = static_cast<T>(1) / (far - near); 

        //     res[0][0] = static_cast<T>(2) * invRightMinusLeft;
        //     res[1][1] = static_cast<T>(-2) * invTopMinusBottom;
        //     res[2][2] = static_cast<T>(-2) * invFarMinusNear;
        //     res[3][0] = -(right + left) * invRightMinusLeft;
        //     res[3][1] = (top + bottom) * invTopMinusBottom;
        //     res[3][2] = -(far + near) * invFarMinusNear;

        //     return res;
        // }

    } // namespace glbDetail

    namespace Mat
    {
        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Perspective(T fovY, T aspect, T zNear, T zFar) noexcept
        {
#           if defined(GLB_SET_COORDINATE_SYSTEM_LH)
#               if defined(GLB_SET_Z_RANGE_0_1)
#                   if defined(GLB_SET_Y_AXIS_UPWARDS)
                        return glbDetail::Perspective_LH_Z0_YUP(fovY, aspect, zNear, zFar);

#                   else
                        return glbDetail::Perspective_LH_Z0_YDOWN(fovY, aspect, zNear, zFar);

#                   endif

#               else
#                   if defined(GLB_SET_Y_AXIS_UPWARDS)
                        return glbDetail::Perspective_LH_ZN1_YUP(fovY, aspect, zNear, zFar);

#                   else
                        return glbDetail::Perspective_LH_ZN1_YDOWN(fovY, aspect, zNear, zFar);

#                   endif

#               endif

#           else
#               if defined(GLB_SET_Z_RANGE_0_1)
#                   if defined(GLB_SET_Y_AXIS_UPWARDS)
                        return glbDetail::Perspective_RH_Z0_YUP(fovY, aspect, zNear, zFar);

#                   else
                        return glbDetail::Perspective_RH_Z0_YDOWN(fovY, aspect, zNear, zFar);

#                   endif

#               else
#                   if defined(GLB_SET_Y_AXIS_UPWARDS)
                        return glbDetail::Perspective_RH_ZN1_YUP(fovY, aspect, zNear, zFar);

#                   else
                        return glbDetail::Perspective_RH_ZN1_YDOWN(fovY, aspect, zNear, zFar);

#                   endif

#               endif

#           endif
        }



        template<typename T>
        GLB_INLINE constexpr glbMat_T<4, 4, T> Orthographic(T left, T right, T bottom, T top, T near, T far) noexcept
        {
#           if defined(GLB_SET_COORDINATE_SYSTEM_LH)
#               if defined(GLB_SET_Z_RANGE_0_1)
                    return glbDetail::Orthographic_LH_Z0(left, right, bottom, top, near, far);

#               else
                    return glbDetail::Orthographic_LH_ZN1(left, right, bottom, top, near, far);

#               endif

#           else
#               if defined(GLB_SET_Z_RANGE_0_1)
                    return glbDetail::Orthographic_RH_Z0(left, right, bottom, top, near, far);

#               else
                    return glbDetail::Orthographic_RH_ZN1(left, right, bottom, top, near, far);

#               endif

#           endif
        }

    } // namespace Mat

} // namespace glb
