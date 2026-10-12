#pragma once

#include "../internal/mat/type_mat2x2.h"

namespace glb
{
#if !defined(GLB_FORCE_NO_ALIAS)
    // A 2x2 Matrix of `float`
    using Mat2x2 = glbMat_T<2, 2, float>;

#endif
}