#pragma once

#include "../definitions.h"

namespace glb
{
    namespace glbIntern
    {
        template<typename T, bool useSimd>
        struct quatAdd
        {
            GLB_INLINE static constexpr glbQuat_T<T> call(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept
            {
                return glbQuat_T<T>(a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z);
            }
        };
        template<typename T, bool useSimd>
        struct quatSub
        {
            GLB_INLINE static constexpr glbQuat_T<T> call(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept
            {
                return glbQuat_T<T>(a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z);
            }
        };
        template<typename T, bool useSimd>
        struct quatDiv
        {
            GLB_INLINE static constexpr glbQuat_T<T> call(const glbQuat_T<T>& v, T scalar) noexcept
            {
                return glbQuat_T<T>(v.w / scalar, v.x / scalar, v.y / scalar, v.z / scalar);
            }
            GLB_INLINE static constexpr glbQuat_T<T> call(T scalar, const glbQuat_T<T>& v) noexcept
            {
                return glbQuat_T<T>(scalar / v.w, scalar / v.x, scalar / v.y, scalar / v.z);
            }
        };
        template<typename T, bool useSimd>
        struct quatMul
        {
            GLB_INLINE static constexpr glbQuat_T<T> call(const glbQuat_T<T>& a, const glbQuat_T<T>& b) noexcept
            {
                return glbQuat_T<T>(
                    a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
                    a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
                    a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
                    a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
                );
            }
            GLB_INLINE static constexpr glbQuat_T<T> call(const glbQuat_T<T>& q, T scalar) noexcept
            {
                return glbQuat_T<T>(q.w * scalar, q.x * scalar, q.y * scalar, q.z * scalar);
            }
            
        };
        


    } // namespace glbIntern
    
} // namespace glb
