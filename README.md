## Gammalgebra

GLB is a C++ header-only math library made for graphics rendering. <br> It supports `Vectors`, with 2, 3 and 4 components,
`Matrices`, of size 2x2, 3x3 and 4x4, and `Quaternions`. <br>
SIMD instructions are also implemented, for devices supporting SSE, SSE2, or AVX.


```cpp
#include "glb/vec/vec_type.h"
#include "glb/vec/functions.h"

using namespace glb;

int main()
{
    Vec3 a{1.1f, 2.2f, 3.3f};
    Vec3 b{-1.1f, -2.2f, -3.3f};

    Vec3 c = Vec::Cross(a, b);

    return 0;
}
```

### - Using the library

#### Before including the library, you need to define multiple macros :

- `GLB_SET_COORDINATE_SYSTEM_...` with `LH` if you want to use a Left-Handed coordinate system, or `RH` if you want to use a Right-Handed one.

- `GLB_SET_Z_RANGE_...`           with `N1_1` if you want the Z range to be [-1; 1], or `0_1` if you want it to be [0; 1].

- `GLB_SET_Y_AXIS_...`            with `UPWARDS` if you want the Y axis to go from bottom to top, or `DOWNWARDS` if you want it to go from tom to bottom.

- `GLB_SET_ROTATION_ORDER_...`    with `XYZ, XZY, YXZ, YZX, ZXY or ZYX`, depending on the desired rotation order of quaternions and rotation matrices.

- `GLB_SET_ROTATION_TYPE_...`     with `INTRINSIC` if you want the rotation axis of quaternions to be rotating, or `EXTRINSIC` if you want it to be static.

#### You can also define optional macros : 

- `GLB_FORCE_SIMD_...`            with `SSE/SSE2/SSE3/SSSE3/SSE4/AVX or AVX2`, depending on the desired level of SIMD instructions. If you don't specify it explicitely, it defaults to the highest supported level by the machine using the library.

- `GLB_FORCE_NO_ALIAS`            if  you don't want the library to define any alias of template types, so that you can define the ones you need to use (see : ...) 



The readme if far from complete.

