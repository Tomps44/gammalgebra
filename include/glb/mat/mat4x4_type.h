#pragma once

#include "../internal/mat/type_mat4x4.h"

namespace glb
{
#if !defined(GLB_FORCE_NO_ALIAS)
    // A 4x4 Matrix of `float`
    using Mat4x4 = glb::glbMat_T<4, 4, float>;

#endif
}