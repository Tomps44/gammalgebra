#pragma once

#include "../internal/mat/type_mat3x3.h"

namespace glb
{
#if !defined(GLB_FORCE_NO_ALIAS)
    // A 3x3 Matrix of `float`
    using Mat3x3 = glb::glbMat_T<3, 3, float>;

#endif
}