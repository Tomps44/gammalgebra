#pragma once

#include "../internal/vec/type_vec3.h"

namespace glb
{
#if !defined(GLB_FORCE_NO_ALIAS)
    // A 3D Vector of `float`
    using Vec3 = glbVec_T<3, float>;

    // A 3D Vector of `int32_t`
    using Vec3i = glbVec_T<3, int32_t>; 
    // A 3D Vector of `uint32_t`
    using Vec3u = glbVec_T<3, uint32_t>;
     
    // A 3D Vector of `bool`
    using Vec3b = glbVec_T<3, bool>;

#endif
}