#pragma once

#include "../internal/vec/type_vec4.h"

namespace glb
{
#if !defined(GLB_FORCE_NO_ALIAS)
    // A 4D Vector of `float`
    using Vec4 = glbVec_T<4, float>;

    // A 4D Vector of `int32_t`
    using Vec4i = glbVec_T<4, int32_t>; 
    // A 4D Vector of `uint32_t`
    using Vec4u = glbVec_T<4, uint32_t>; 

    // A 4D Vector of `bool`
    using Vec4b = glbVec_T<4, bool>;

#endif
}