#pragma once

#include "../internal/vec/type_vec2.h"

namespace glb
{
#if !defined(GLB_FORCE_NO_ALIAS)
    // A 2D Vector of `float`
    using Vec2 = glbVec_T<2, float>;
    
    // A 2D Vector of `int32_t`
    using Vec2i = glbVec_T<2, int32_t>; 
    // A 2D Vector of `uint32_t`
    using Vec2u = glbVec_T<2, uint32_t>; 

    // A 2D Vector of `bool`
    using Vec2b = glbVec_T<2, bool>;

#endif
}