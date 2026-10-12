/** 
 * -------------------------------------------------------------
 * 
 * This file is deprecated !
 * Dual Quaternions will maybe be implemented in a later version.
 * For now, do not include any of that :
 * 
 * --------------------------------------------------------------
 */



 

#pragma once

#include "type_dualquat.h"

namespace glb
{
    namespace DQua
    {
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Exp(const glbDQuat_T<T>& q) noexcept;
        
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Log(const glbDQuat_T<T>& q) noexcept;

        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Pow(const glbDQuat_T<T>& q, T exponent) noexcept;
        template<typename T>
        GLB_INLINE constexpr glbDQuat_T<T> Sqrt(const glbDQuat_T<T>& q) noexcept;

    } // namespace Quaternion
    
} // namespace glb

#include "compute_dual_exponential.inl"
