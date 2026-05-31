#include <cmath>

namespace tmx
{
    namespace Qua
    {
        template<typename T>
        TMX_INLINE constexpr quat<T> FromAxisAngle(const vec<3, T>& u, T angle) noexcept
        {
            const T halfAng = angle * static_cast<T>(0.5); 
            const T sinHalfAng = std::sin(halfAng); 

            return quat<T>(
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
        TMX_INLINE constexpr quat<T> FromEuler(T x, T y, T z) noexcept
        {
#           if defined(TMX_SET_ROTATION_TYPE_INTRINSIC)
#               if defined(TMX_SET_ROTATION_ORDER_XYZ)
                    return tmxDetail::FromEuler_XYZ(x, y, z);

#               elif defined(TMX_SET_ROTATION_ORDER_XZY)
                    return tmxDetail::FromEuler_XZY(x, y, z);

#               elif defined(TMX_SET_ROTATION_ORDER_YXZ)
                    return tmxDetail::FromEuler_YXZ(x, y, z);

#               elif defined(TMX_SET_ROTATION_ORDER_YZX)
                    return tmxDetail::FromEuler_YZX(x, y, z);

#               elif defined(TMX_SET_ROTATION_ORDER_ZXY)
                    return tmxDetail::FromEuler_ZXY(x, y, z);

#               else // TMX_SET_ROTATION_ORDER_ZYX
                    return tmxDetail::FromEuler_ZYX(x, y, z);

                #endif
#           else // TMX_SET_ROTATION_TYPE_EXTRINSIC
#               if defined(TMX_SET_ROTATION_ORDER_XYZ)
                    return tmxDetail::FromEuler_ZYX(x, y, z);

#               elif defined(TMX_SET_ROTATION_ORDER_XZY)
                    return tmxDetail::FromEuler_YZX(x, y, z);

#               elif defined(TMX_SET_ROTATION_ORDER_YXZ)
                    return tmxDetail::FromEuler_ZXY(x, y, z);

#               elif defined(TMX_SET_ROTATION_ORDER_YZX)
                    return tmxDetail::FromEuler_XZY(x, y, z);

#               elif defined(TMX_SET_ROTATION_ORDER_ZXY)
                    return tmxDetail::FromEuler_YXZ(x, y, z);

#               else // TMX_SET_ROTATION_ORDER_ZYX
                    return tmxDetail::FromEuler_XYZ(x, y, z);

                #endif

#           endif
        }


        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler(const vec<3, T>& angles) noexcept
        {
            return FromEuler(angles.x, angles.y, angles.z);
        }



        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler(const quat<T>& q) noexcept
        {
#           if defined(TMX_SET_ROTATION_TYPE_INTRINSIC)
#               if defined(TMX_SET_ROTATION_ORDER_XYZ)
                    return tmxDetail::ToEuler_XYZ(q);

#               elif defined(TMX_SET_ROTATION_ORDER_XZY)
                    return tmxDetail::ToEuler_XZY(q);

#               elif defined(TMX_SET_ROTATION_ORDER_YXZ)
                    return tmxDetail::ToEuler_YXZ(q);

#               elif defined(TMX_SET_ROTATION_ORDER_YZX)
                    return tmxDetail::ToEuler_YZX(q);

#               elif defined(TMX_SET_ROTATION_ORDER_ZXY)
                    return tmxDetail::ToEuler_ZXY(q);

#               else // TMX_SET_ROTATION_ORDER_ZYX
                    return tmxDetail::ToEuler_ZYX(q);

                #endif
                
#           else // TMX_SET_ROTATION_TYPE_EXTRINSIC
#               if defined(TMX_SET_ROTATION_ORDER_XYZ)
                    return tmxDetail::ToEuler_ZYX(q);

#               elif defined(TMX_SET_ROTATION_ORDER_XZY)
                    return tmxDetail::ToEuler_YZX(q);

#               elif defined(TMX_SET_ROTATION_ORDER_YXZ)
                    return tmxDetail::ToEuler_ZXY(q);

#               elif defined(TMX_SET_ROTATION_ORDER_YZX)
                    return tmxDetail::ToEuler_XZY(q);

#               elif defined(TMX_SET_ROTATION_ORDER_ZXY)
                    return tmxDetail::ToEuler_YXZ(q);

#               else // TMX_SET_ROTATION_ORDER_ZYX
                    return tmxDetail::ToEuler_XYZ(q);

                #endif

#           endif
        }
    
    } // namespace Qua

        


    
    
    namespace tmxDetail
    {
        
        // ------------------------------------------------------
        //                  FromEuler functions
        // ------------------------------------------------------

        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_XYZ(T x, T y, T z) noexcept
        {
            const T halfX = x * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfY = y * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfZ = z * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);


            return quat<T>(
                cx * cy * cz - sx * sy * sz,
                sx * cy * cz + cx * sy * sz,
                cx * sy * cz - sx * cy * sz,
                cx * cy * sz + sx * sy * cz
            );
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_XZY(T x, T y, T z) noexcept
        {
            const T halfX = x * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfY = y * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfZ = z * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);


            return quat<T>(
                cx * cy * cz + sx * sy * sz,
                sx * cy * cz - cx * sy * sz,
                cx * sy * cz - sx * cy * sz,
                cx * cy * sz + sx * sy * cz
            );
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_YXZ(T x, T y, T z) noexcept
        {
            const T halfX = x * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfY = y * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfZ = z * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);
            

            return quat<T>(
                cx * cy * cz + sx * sy * sz,
                sx * cy * cz + cx * sy * sz,
                cx * sy * cz - sx * cy * sz,
                cx * cy * sz - sx * sy * cz
            );
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_YZX(T x, T y, T z) noexcept
        {
            const T halfX = x * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfY = y * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfZ = z * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);


            return quat<T>(
                cx * cy * cz - sx * sy * sz,
                sx * cy * cz + cx * sy * sz,
                cx * sy * cz + sx * cy * sz,
                cx * cy * sz - sx * sy * cz
            );
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_ZXY(T x, T y, T z) noexcept
        {
            const T halfX = x * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfY = y * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfZ = z * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);


            return quat<T>(
                cx * cy * cz - sx * sy * sz,
                sx * cy * cz - cx * sy * sz,
                cx * sy * cz + sx * cy * sz,
                cx * cy * sz + sx * sy * cz
            );
        }
        template<typename T>
        TMX_INLINE constexpr quat<T> FromEuler_ZYX(T x, T y, T z) noexcept
        {
            const T halfX = x * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfY = y * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);
            const T halfZ = z * static_cast<T>(0.5) * static_cast<T>(0.0174532925199432957691391462423657899L);

            const T cx = std::cos(halfX);
            const T sx = std::sin(halfX);
            const T cy = std::cos(halfY); 
            const T sy = std::sin(halfY);
            const T cz = std::cos(halfZ); 
            const T sz = std::sin(halfZ);


            return quat<T>(
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
        TMX_INLINE constexpr vec<3, T> ToEuler_XYZ(const quat<T>& q) noexcept
        {
            const T sy = static_cast<T>(2) * (q.x * q.z + q.w * q.y);
            const T sySq = sy * sy;
            vec<3, T> res;

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

            return res * static_cast<T>(57.2957795130823208766546184023127353);
        }

        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_XZY(const quat<T>& q) noexcept
        {
            const T sz = -(static_cast<T>(2) * (q.x * q.y - q.w * q.z));
            const T szSq = sz * sz;
            vec<3, T> res;

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
            
            return res * static_cast<T>(57.2957795130823208766546184023127353);
        }

        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_YXZ(const quat<T>& q) noexcept
        {
            const T sx = -(static_cast<T>(2) * (q.y * q.z - q.w * q.x));
            const T sxSq = sx * sx;
            vec<3, T> res;

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

            return res * static_cast<T>(57.2957795130823208766546184023127353);
        }

        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_YZX(const quat<T>& q) noexcept
        {
            const T sz = static_cast<T>(2) * (q.x * q.y + q.w * q.z);
            const T szSq = sz * sz;
            vec<3, T> res;

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
            return res * static_cast<T>(57.2957795130823208766546184023127353);
        }

        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_ZXY(const quat<T>& q) noexcept
        {
            const T sx = static_cast<T>(2) * (q.y * q.z + q.w * q.x);
            const T sxSq = sx * sx;
            vec<3, T> res;

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

            return res * static_cast<T>(57.2957795130823208766546184023127353);
        }

        template<typename T>
        TMX_INLINE constexpr vec<3, T> ToEuler_ZYX(const quat<T>& q) noexcept
        {
            const T sy = -(static_cast<T>(2) * (q.x * q.z - q.w * q.y));
            const T sySq = sy * sy;
            vec<3, T> res;

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
            return res * static_cast<T>(57.2957795130823208766546184023127353);
        }

    } // namespace tmxDetail
    
} // namespace tmx
