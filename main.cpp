#include <iostream>
#include <iomanip>
#include <chrono>


// #define TMX_FORCE_SIMD_NONE
// #define TMX_FORCE_SSE2
// #define TMX_FORCE_AVX
#define TMX_SET_COORDINATE_SYSTEM_RH
#define TMX_SET_ROTATION_ORDER_ZXY
#define TMX_SET_ROTATION_TYPE_EXTRINSIC
#define TMX_SET_Z_RANGE_N1_1
#define TMX_SET_Y_AXIS_UPWARDS


#include "tmx/vec/vec_type.hpp"
#include "tmx/vec/functions.hpp"

#include "tmx/mat/mat_type.hpp"
#include "tmx/mat/functions.hpp"

#include "tmx/quat/quat_type.hpp"
#include "tmx/quat/functions.hpp"

#include "tmx/math/functions.hpp"

#include "tmx/internal/hash.hpp"


template<typename T>
void logVal(T val) 
{
    std::cout << ((std::abs(val) < static_cast<T>(5.0e-05)) ? static_cast<T>(0) : val);
}

template<int S, typename T>
void logVec(const tmx::vec<S, T>& vec)
{
    std::cout << "(";
    for (int i = 0; i < S - 1; i++)
    {
        std::cout << vec.values[i] << ", ";
    }
    std::cout << vec.values[S - 1];
    std::cout << ")" << '\n';
}

template<int R, int C, typename T>
void logMat(const tmx::mat<R, C, T>& mat)
{
    for (int r = 0; r < R; r++)
    {
        std::cout << "(";
        for (int c = 0; c < C - 1; c++)
        {
            logVal(mat[c][r]);
            std::cout << " ";
        }
        logVal(mat[C - 1][r]);
        std::cout << ")" << '\n';
    }
}

template<typename T>
void logQuat(const tmx::quat<T>& qua)
{
    std::cout << "(";
    for (int i = 0; i < 3; i++)
    {
        std::cout << qua.values[i] << ", ";
    }
    std::cout << qua.values[3];
    std::cout << ")" << '\n';
}








int main()
{
    // std::cout << std::setprecision(10);

    using namespace tmx;
    using namespace Math;



/***********************************************************************************/
/*                   This file is part of the TMathX library                       */
/***********************************************************************************/
/*                                                                                 */
/*  Copyright (c) 2026 Tomps44                                                     */
/*                                                                                 */
/*  Permission is hereby granted, free of charge, to any person obtaining a copy   */
/*  of this software and associated documentation files (the "Software"), to deal  */
/*  in the Software without restriction, including without limitation the rights   */
/*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      */
/*  copies of the Software, and to permit persons to whom the Software is          */
/*  furnished to do so, subject to the following conditions:                       */
/*                                                                                 */
/*  The above copyright notice and this permission notice shall be                 */
/*  included in all copies or substantial portions of the Software.                */
/*                                                                                 */
/*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     */
/*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       */
/*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    */
/*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         */
/*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  */
/*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  */
/*  SOFTWARE.                                                                      */
/*                                                                                 */
/***********************************************************************************/
    

    /** Need to add in the Math namespace :
     * Floor/Ceil/Truc...ToInt
     * WrapAngle (keeps it between 0 and 2PI)
     * LerpAngle (lerp with shortest path)
     * IsPOwerOfTwo and NextPowerOfTwo
     * IsNaN and IsInf
     * Equal(with epsilon) and IsZero
     * BitCast ??
     * Clz (Count Leading Zeros) and Popcount (amount of bits set to 1)
     */

    // And also think of a new name, which would sound good in its abbreviated form (in the namespace), and goes well with other libraries




    return 0;
}




