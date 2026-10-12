#define GLB_SET_COORDINATE_SYSTEM_LH
#define GLB_SET_Z_RANGE_N1_1
#define GLB_SET_Y_AXIS_DOWNWARDS
#define GLB_SET_ROTATION_ORDER_YXZ
#define GLB_SET_ROTATION_TYPE_INTRINSIC
#include "glb/glb.h"

#include <iostream>


int main()
{
    printf("Hello World!\n");

    using namespace glb;

    Quat q = Qua::FromEuler(Vec3{0.5f, -30.0f, 60.0f});
    q = Qua::Log(Qua::Exp(q));

    for (int i = 0; i < 4; i++)
    {
        std::cout << q[i] << '\n';
    }

    return 0;
}