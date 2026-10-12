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
#if !defined(GLB_FORCE_NO_ALIAS)
    // A Dual Quaternion of `float`
    using DQuat = glbDQuat_T<float>;

#endif
}