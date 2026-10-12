#include <cmath>

namespace glb
{
    namespace Qua
    {
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> FromAxisAngle(const glbVec_T<3, T>& u, T angle) noexcept
        {
            const T halfAng = angle * static_cast<T>(0.5); 
            const T sinHalfAng = std::sin(halfAng); 

            return glbQuat_T<T>(
                std::cos(halfAng),
                u.x * sinHalfAng,
                u.y * sinHalfAng,
                u.z * sinHalfAng
            );
        }

        // ------------------------------------------------------
        //                 from/to Euler wrapper
        // ------------------------------------------------------

        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> FromEuler(const glbVec_T<3, T>& angles) noexcept
        {
#           if defined(GLB_SET_ROTATION_TYPE_INTRINSIC)
#               if defined(GLB_SET_ROTATION_ORDER_XYZ)
                    return glbDetail::FromEuler_XYZ(angles);

#               elif defined(GLB_SET_ROTATION_ORDER_XZY)
                    return glbDetail::FromEuler_XZY(angles);

#               elif defined(GLB_SET_ROTATION_ORDER_YXZ)
                    return glbDetail::FromEuler_YXZ(angles);

#               elif defined(GLB_SET_ROTATION_ORDER_YZX)
                    return glbDetail::FromEuler_YZX(angles);

#               elif defined(GLB_SET_ROTATION_ORDER_ZXY)
                    return glbDetail::FromEuler_ZXY(angles);

#               else // GLB_SET_ROTATION_ORDER_ZYX
                    return glbDetail::FromEuler_ZYX(angles);

                #endif
#           else // GLB_SET_ROTATION_TYPE_EXTRINSIC
#               if defined(GLB_SET_ROTATION_ORDER_XYZ)
                    return glbDetail::FromEuler_ZYX(angles);

#               elif defined(GLB_SET_ROTATION_ORDER_XZY)
                    return glbDetail::FromEuler_YZX(angles);

#               elif defined(GLB_SET_ROTATION_ORDER_YXZ)
                    return glbDetail::FromEuler_ZXY(angles);

#               elif defined(GLB_SET_ROTATION_ORDER_YZX)
                    return glbDetail::FromEuler_XZY(angles);

#               elif defined(GLB_SET_ROTATION_ORDER_ZXY)
                    return glbDetail::FromEuler_YXZ(angles);

#               else // GLB_SET_ROTATION_ORDER_ZYX
                    return glbDetail::FromEuler_XYZ(angles);

                #endif

#           endif
        }


        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> FromEuler(T x, T y, T z) noexcept
        {
            return FromEuler(glbVec_T<3, T>{x, y, z});
        }



        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> ToEuler(const glbQuat_T<T>& q) noexcept
        {
#           if defined(GLB_SET_ROTATION_TYPE_INTRINSIC)
#               if defined(GLB_SET_ROTATION_ORDER_XYZ)
                    return glbDetail::ToEuler_XYZ(q);

#               elif defined(GLB_SET_ROTATION_ORDER_XZY)
                    return glbDetail::ToEuler_XZY(q);

#               elif defined(GLB_SET_ROTATION_ORDER_YXZ)
                    return glbDetail::ToEuler_YXZ(q);

#               elif defined(GLB_SET_ROTATION_ORDER_YZX)
                    return glbDetail::ToEuler_YZX(q);

#               elif defined(GLB_SET_ROTATION_ORDER_ZXY)
                    return glbDetail::ToEuler_ZXY(q);

#               else // GLB_SET_ROTATION_ORDER_ZYX
                    return glbDetail::ToEuler_ZYX(q);

                #endif
                
#           else // GLB_SET_ROTATION_TYPE_EXTRINSIC
#               if defined(GLB_SET_ROTATION_ORDER_XYZ)
                    return glbDetail::ToEuler_ZYX(q);

#               elif defined(GLB_SET_ROTATION_ORDER_XZY)
                    return glbDetail::ToEuler_YZX(q);

#               elif defined(GLB_SET_ROTATION_ORDER_YXZ)
                    return glbDetail::ToEuler_ZXY(q);

#               elif defined(GLB_SET_ROTATION_ORDER_YZX)
                    return glbDetail::ToEuler_XZY(q);

#               elif defined(GLB_SET_ROTATION_ORDER_ZXY)
                    return glbDetail::ToEuler_YXZ(q);

#               else // GLB_SET_ROTATION_ORDER_ZYX
                    return glbDetail::ToEuler_XYZ(q);

                #endif

#           endif
        }
    
    } // namespace Qua

        


    
    
    namespace glbDetail
    {
        
        // ------------------------------------------------------
        //                  FromEuler functions
        // ------------------------------------------------------

        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> FromEuler_XYZ(const glbVec_T<3, T>& angles) noexcept
        {
            const T halfX = angles.x * static_cast<T>(0.5);
            const T halfY = angles.y * static_cast<T>(0.5);
            const T halfZ = angles.z * static_cast<T>(0.5);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);


            return glbQuat_T<T>(
                cx * cy * cz - sx * sy * sz,
                sx * cy * cz + cx * sy * sz,
                cx * sy * cz - sx * cy * sz,
                cx * cy * sz + sx * sy * cz
            );
        }
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> FromEuler_XZY(const glbVec_T<3, T>& angles) noexcept
        {
            const T halfX = angles.x * static_cast<T>(0.5);
            const T halfY = angles.y * static_cast<T>(0.5);
            const T halfZ = angles.z * static_cast<T>(0.5);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);


            return glbQuat_T<T>(
                cx * cy * cz + sx * sy * sz,
                sx * cy * cz - cx * sy * sz,
                cx * sy * cz - sx * cy * sz,
                cx * cy * sz + sx * sy * cz
            );
        }
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> FromEuler_YXZ(const glbVec_T<3, T>& angles) noexcept
        {
            const T halfX = angles.x * static_cast<T>(0.5);
            const T halfY = angles.y * static_cast<T>(0.5);
            const T halfZ = angles.z * static_cast<T>(0.5);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);
            

            return glbQuat_T<T>(
                cx * cy * cz + sx * sy * sz,
                sx * cy * cz + cx * sy * sz,
                cx * sy * cz - sx * cy * sz,
                cx * cy * sz - sx * sy * cz
            );
        }
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> FromEuler_YZX(const glbVec_T<3, T>& angles) noexcept
        {
            const T halfX = angles.x * static_cast<T>(0.5);
            const T halfY = angles.y * static_cast<T>(0.5);
            const T halfZ = angles.z * static_cast<T>(0.5);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);


            return glbQuat_T<T>(
                cx * cy * cz - sx * sy * sz,
                sx * cy * cz + cx * sy * sz,
                cx * sy * cz + sx * cy * sz,
                cx * cy * sz - sx * sy * cz
            );
        }
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> FromEuler_ZXY(const glbVec_T<3, T>& angles) noexcept
        {
            const T halfX = angles.x * static_cast<T>(0.5);
            const T halfY = angles.y * static_cast<T>(0.5);
            const T halfZ = angles.z * static_cast<T>(0.5);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);


            return glbQuat_T<T>(
                cx * cy * cz - sx * sy * sz,
                sx * cy * cz - cx * sy * sz,
                cx * sy * cz + sx * cy * sz,
                cx * cy * sz + sx * sy * cz
            );
        }
        template<typename T>
        GLB_INLINE constexpr glbQuat_T<T> FromEuler_ZYX(const glbVec_T<3, T>& angles) noexcept
        {
            const T halfX = angles.x * static_cast<T>(0.5);
            const T halfY = angles.y * static_cast<T>(0.5);
            const T halfZ = angles.z * static_cast<T>(0.5);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);


            return glbQuat_T<T>(
                cx * cy * cz + sx * sy * sz,
                sx * cy * cz - cx * sy * sz,
                cx * sy * cz + sx * cy * sz,
                cx * cy * sz - sx * sy * cz
            );
        }


        // ------------------------------------------------------
        //                  ToEuler functions
        // ------------------------------------------------------

        // Here's a Quaternion converted into a 3x3 Matrix


        // Inhomogeneous form : 
        // [                                                                 |                                                                 |                                                                 ]
        // [ static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z) |           static_cast<T>(2) * (q.x * q.y - q.w * q.z)           |           static_cast<T>(2) * (q.x * q.z + q.w * q.y)           ]
        // [        m00                                                      |                                                      m01        |        m02                                                      ]
        // [-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------]
        // [                                                                 |                                                                 |                                                                 ]
        // [           static_cast<T>(2) * (q.x * q.y + q.w * q.z)           | static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.z * q.z) |           static_cast<T>(2) * (q.y * q.z - q.w * q.x)           ]
        // [        m10                                                      |        m11                                                      |        m12                                                      ]
        // [-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------]
        // [                                                                 |                                                                 |                                                                 ]
        // [           static_cast<T>(2) * (q.x * q.z - q.x * q.y)           |           static_cast<T>(2) * (q.y * q.z + q.w * q.x)           | static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.y * q.y) ]
        // [         m20                                                     |        m21                                                      |        m22                                                      ]

        // Homogeneous form :
        // [                                               |                                               |                                               ]
        // [ q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z |  static_cast<T>(2) * (q.x * q.y - q.w * q.z)  |  static_cast<T>(2) * (q.x * q.z + q.w * q.y)  ]
        // [                    m00                        |                    m01                        |                      m02                      ]
        // [-----------------------------------------------------------------------------------------------------------------------------------------------]
        // [                                               |                                               |                                               ]
        // [  static_cast<T>(2) * (q.x * q.y + q.w * q.z)  | q.w * q.w - q.x * q.x + q.y * q.y - q.z * q.z |  static_cast<T>(2) * (q.y * q.z - q.w * q.x)  ]
        // [                       m10                     |                     m11                       |                      m12                      ]
        // [-----------------------------------------------------------------------------------------------------------------------------------------------]
        // [                                               |                                               |                                               ]
        // [  static_cast<T>(2) * (q.x * q.z - q.w * q.y)  |  static_cast<T>(2) * (q.y * q.z + q.w * q.x)  | q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z ]
        // [                       m20                     |                        m21                    |                       m22                     ]
        
        
        


        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> ToEuler_XYZ(const glbQuat_T<T>& q) noexcept
        {
            const T sy = static_cast<T>(2) * (q.x * q.z + q.w * q.y);
            const T sySq = sy * sy;
            glbVec_T<3, T> res;

            // Gimbal Lock
            if (sySq > static_cast<T>(0.9999))
            {
                res.z = static_cast<T>(0);

                if (sy > static_cast<T>(0))
                {
                    res.y = static_cast<T>(1.5707963267948966192564044797030931); // PI/2
                    res.x = std::atan2(static_cast<T>(2) * (q.y * q.z + q.w * q.x), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.z * q.z)); // Other formula
                }
                else
                {
                    res.y = static_cast<T>(-1.5707963267948966192564044797030931);
                    res.x = std::atan2(-(static_cast<T>(2) * (q.y * q.z + q.w * q.x)), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.z * q.z));
                }
            }
            // Normal
            else
            {
                res.x = std::atan2(-(static_cast<T>(2) * (q.y * q.z - q.w * q.x)), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.y * q.y));
                res.y = std::asin(static_cast<T>(2) * (q.x * q.z + q.w * q.y));
                res.z = std::atan2(-(static_cast<T>(2) * (q.x * q.y - q.w * q.z)), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
            }

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> ToEuler_XZY(const glbQuat_T<T>& q) noexcept
        {
            const T sz = -(static_cast<T>(2) * (q.x * q.y - q.w * q.z));
            const T szSq = sz * sz;
            glbVec_T<3, T> res;

            if (szSq > static_cast<T>(0.9999))
            {
                res.y = static_cast<T>(0);

                if (sz > static_cast<T>(0))
                {
                    res.x = std::atan2(-(static_cast<T>(2) * (q.y * q.z - q.w * q.x)), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.y * q.y));
                    res.z = static_cast<T>(1.5707963267948966192564044797030931);
                }
                else
                {
                    res.x = std::atan2(static_cast<T>(2) * (q.y * q.z - q.w * q.x), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.y * q.y));
                    res.z = static_cast<T>(-1.5707963267948966192564044797030931);
                }
            }
            else
            {
                res.x = std::atan2(static_cast<T>(2) * (q.y * q.z + q.w * q.x), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.z * q.z));
                res.y = std::atan2(static_cast<T>(2) * (q.x * q.z + q.w * q.y), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
                res.z = std::asin(-(static_cast<T>(2) * (q.x * q.y - q.w * q.z)));
            }
            
            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> ToEuler_YXZ(const glbQuat_T<T>& q) noexcept
        {
            const T sx = -(static_cast<T>(2) * (q.y * q.z - q.w * q.x));
            const T sxSq = sx * sx;
            glbVec_T<3, T> res;

            if (sxSq > static_cast<T>(0.9999))
            {
                res.z = static_cast<T>(0);

                if (sx > static_cast<T>(0))
                {
                    res.y = std::atan2(static_cast<T>(2) * (q.x * q.z - q.w * q.y), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
                    res.x = static_cast<T>(1.5707963267948966192564044797030931);
                }
                else
                {
                    res.y = std::atan2(-(static_cast<T>(2) * (q.x * q.z - q.w * q.y)), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
                    res.x = static_cast<T>(-1.5707963267948966192564044797030931);
                }
            }
            else
            {
                res.x = std::asin(-(static_cast<T>(2) * (q.y * q.z - q.w * q.x)));
                res.y = std::atan2(static_cast<T>(2) * (q.x * q.z + q.w * q.y), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.y * q.y));
                res.z = std::atan2(static_cast<T>(2) * (q.x * q.y + q.w * q.z), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.z * q.z));
            }

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> ToEuler_YZX(const glbQuat_T<T>& q) noexcept
        {
            const T sz = static_cast<T>(2) * (q.x * q.y + q.w * q.z);
            const T szSq = sz * sz;
            glbVec_T<3, T> res;

            if (szSq > static_cast<T>(0.9999))
            {
                res.x = static_cast<T>(0);

                if (sz > static_cast<T>(0))
                {
                    res.y = std::atan2(-(static_cast<T>(2) * (q.x * q.z - q.w * q.y)), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
                    res.z = static_cast<T>(1.5707963267948966192564044797030931);
                }
                else
                {
                    res.y = std::atan2(static_cast<T>(2) * (q.x * q.z - q.w * q.y), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
                    res.z = static_cast<T>(-1.5707963267948966192564044797030931);
                }
            }
            else
            {
                res.x = std::atan2(-(static_cast<T>(2) * (q.y * q.z - q.w * q.x)), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.z * q.z));
                res.y = std::atan2(-(static_cast<T>(2) * (q.x * q.z - q.w * q.y)), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
                res.z = std::asin(static_cast<T>(2) * (q.x * q.y + q.w * q.z));
            }
            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> ToEuler_ZXY(const glbQuat_T<T>& q) noexcept
        {
            const T sx = static_cast<T>(2) * (q.y * q.z + q.w * q.x);
            const T sxSq = sx * sx;
            glbVec_T<3, T> res;

            if (sxSq > static_cast<T>(0.9999))
            {
                res.y = static_cast<T>(0);

                if (sx > static_cast<T>(0))
                {
                    res.z = std::atan2(static_cast<T>(2) * (q.x * q.y + q.w * q.z), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
                    res.x = static_cast<T>(1.5707963267948966192564044797030931);
                }
                else
                {
                    res.z = std::atan2(-(static_cast<T>(2) * (q.x * q.y + q.w * q.z)), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
                    res.x = static_cast<T>(-1.5707963267948966192564044797030931);
                }
            }
            else
            {
                res.x = std::asin(static_cast<T>(2) * (q.y * q.z + q.w * q.x));
                res.y = std::atan2(-(static_cast<T>(2) * (q.x * q.z - q.w * q.y)), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.y * q.y));
                res.z = std::atan2(-(static_cast<T>(2) * (q.x * q.y - q.w * q.z)), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.z * q.z));
            }

            return res;
        }

        template<typename T>
        GLB_INLINE constexpr glbVec_T<3, T> ToEuler_ZYX(const glbQuat_T<T>& q) noexcept
        {
            const T sy = -(static_cast<T>(2) * (q.x * q.z - q.w * q.y));
            const T sySq = sy * sy;
            glbVec_T<3, T> res;

            if (sySq > static_cast<T>(0.9999))
            {
                res.x = static_cast<T>(0);

                if (sy > static_cast<T>(0))
                {
                    res.z = std::atan2(static_cast<T>(2) * (q.x * q.y + q.w * q.z), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
                    res.y = static_cast<T>(1.5707963267948966192564044797030931);
                }
                else
                {
                    res.z = std::atan2(-(static_cast<T>(2) * (q.x * q.y + q.w * q.z)), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
                    res.y = static_cast<T>(-1.5707963267948966192564044797030931);
                }
            }
            else
            {
                res.x = std::atan2(static_cast<T>(2) * (q.y * q.z + q.w * q.x), static_cast<T>(1) - static_cast<T>(2) * (q.x * q.x + q.y * q.y));
                res.y = std::asin(-(static_cast<T>(2) * (q.x * q.z - q.w * q.y)));
                res.z = std::atan2(static_cast<T>(2) * (q.x * q.y + q.w * q.z), static_cast<T>(1) - static_cast<T>(2) * (q.y * q.y + q.z * q.z));
            }
            return res;
        }

    } // namespace glbDetail
    
} // namespace glb
