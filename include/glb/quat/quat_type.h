#pragma once

#include "../internal/type_quat.h"

namespace glb
{
#if !defined(GLB_FORCE_NO_ALIAS)
    // A Quaternion of `float`
    using Quat = glbQuat_T<float>;

#endif
}