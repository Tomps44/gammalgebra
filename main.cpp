#include <iostream>
#include <iomanip>

#define TMX_FORCE_SIMD_NONE

#include "tmx/vec/vec_type.hpp"
#include "tmx/vec/functions.hpp"

#include "tmx/internal/mat/type_mat2x2.hpp"
#include "tmx/internal/mat/type_mat3x3.hpp"
#include "tmx/internal/mat/type_mat4x4.hpp"

#include "tmx/quat/quat_type.hpp"

#include "tmx/quat/interpolation.hpp"
#include "tmx/quat/geometric.hpp"
#include "tmx/quat/angle.hpp"
#include "tmx/quat/exponential.hpp"


#include "tmx/math/constants.hpp"
#include "tmx/math/common.hpp"
#include "tmx/math/exponential.hpp"
#include "tmx/math/interpolation.hpp"


namespace tmx
{ 
typedef tmx::mat<2, 2, float> Mat2x2;
typedef tmx::mat<3, 3, float> Mat3x3;
typedef tmx::mat<4, 4, float> Mat4x4;

namespace Mat {}
}

namespace std
{
    typedef int32_t i32;
    typedef uint32_t u32;
}



template<size_t S, typename T>
void logVec(const tmx::vec<S, T>& vec)
{
    std::cout << "(";
    for (size_t i = 0; i < S - 1; i++)
    {
        std::cout << vec.values[i] << ", ";
    }
    std::cout << vec.values[S - 1];
    std::cout << ")" << '\n';
}

template<size_t R, size_t C, typename T>
void logMat(const tmx::mat<R, C, T>& mat)
{
    for (size_t r = 0; r < R; r++)
    {
        for (size_t c = 0; c < C; c++)
        {
            std::cout << mat[c][r] << " ";
        }
        std::cout << '\n';
    }
}

template<typename T>
void logQuat(const tmx::quat<T>& qua)
{
    std::cout << "(";
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << qua.values[i] << ", ";
    }
    std::cout << qua.values[3];
    std::cout << ")" << '\n';
}







int main()
{
    std::cout << std::setprecision(5);

    using namespace tmx;
    using namespace Math;



    std::cout << Math::InvLerp(-Math::PI, Math::PI, -HalfPI) << '\n';
    std::cout << Math::SmoothStep(-Math::PI, Math::PI, -HalfPI) << '\n';
    std::cout << Math::SmootherStep(-Math::PI, Math::PI, -HalfPI) << '\n';


    std::cout << Map(3.0f, 0.0f, 6.0f, 5.0f, 10.0f) << '\n';

    

    
    


    // For vectors, need to implement : 
    // - Step 
    // - Smooth Step 
    // - Smoother Step 
    // - Inverse Lerp 

    // - Change every lerp formula back to a + (b - a) * t,
    //   instead of (1 - t) * a + b * t.
    //   It gives the EXACT same results
    
    
    return 0;
}


