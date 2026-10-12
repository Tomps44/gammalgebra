#pragma once


#if defined(_MSC_VER)
#   define GLB_COMPILER_MSVC

#elif defined(__clang__)
#   define GLB_COMPILER_CLANG

#elif defined(__GNUC__) 
#   define GLB_COMPILER_GCC

#endif


#if !defined(GLB_FORCE_SIMD_NONE)
#   if defined(GLB_FORCE_AVX2)
#       define GLB_SIMD_AVX2
#       define GLB_SIMD_AVX
#       define GLB_SIMD_SSE4
#       define GLB_SIMD_SSSE3
#       define GLB_SIMD_SSE3
#       define GLB_SIMD_SSE2
#       define GLB_SIMD_SSE

#   elif defined(GLB_FORCE_AVX)
#       define GLB_SIMD_AVX
#       define GLB_SIMD_SSE4
#       define GLB_SIMD_SSSE3
#       define GLB_SIMD_SSE3
#       define GLB_SIMD_SSE2
#       define GLB_SIMD_SSE

#   elif defined(GLB_FORCE_SSE4)
#       define GLB_SIMD_SSE4
#       define GLB_SIMD_SSSE3
#       define GLB_SIMD_SSE3
#       define GLB_SIMD_SSE2
#       define GLB_SIMD_SSE

#   elif defined(GLB_FORCE_SSSE3)
#       define GLB_SIMD_SSSE3
#       define GLB_SIMD_SSE3
#       define GLB_SIMD_SSE2
#       define GLB_SIMD_SSE

#   elif defined(GLB_FORCE_SSE3)
#       define GLB_SIMD_SSE3
#       define GLB_SIMD_SSE2
#       define GLB_SIMD_SSE

#   elif defined(GLB_FORCE_SSE2)
#       define GLB_SIMD_SSE2
#       define GLB_SIMD_SSE

#   elif defined(GLB_FORCE_SSE)
#       define GLB_SIMD_SSE

#   else 
#       if defined(__AVX2__)  
#           define GLB_SIMD_AVX2
#           define GLB_SIMD_AVX
#           define GLB_SIMD_SSE4
#           define GLB_SIMD_SSSE3
#           define GLB_SIMD_SSE3
#           define GLB_SIMD_SSE2
#           define GLB_SIMD_SSE

#       elif defined(__AVX__)
#           define GLB_SIMD_AVX
#           define GLB_SIMD_SSE4
#           define GLB_SIMD_SSSE3
#           define GLB_SIMD_SSE3
#           define GLB_SIMD_SSE2
#           define GLB_SIMD_SSE

#       elif defined(__SSE4_2__) || defined(__SSE4_1__)
#           define GLB_SIMD_SSE4
#           define GLB_SIMD_SSSE3
#           define GLB_SIMD_SSE3
#           define GLB_SIMD_SSE2
#           define GLB_SIMD_SSE

#       elif defined(__SSSE3__) 
#           define GLB_SIMD_SSSE3
#           define GLB_SIMD_SSE3
#           define GLB_SIMD_SSE2
#           define GLB_SIMD_SSE

#       elif defined(__SSE3__) 
#           define GLB_SIMD_SSE3
#           define GLB_SIMD_SSE2
#           define GLB_SIMD_SSE


#       elif defined(__SSE2__)
#           define GLB_SIMD_SSE2 
#           define GLB_SIMD_SSE 

#       elif defined(__SSE__)
#           define GLB_SIMD_SSE

#       else 
#           define GLB_SIMD_NONE

#       endif

#   endif

#else 
#   define GLB_SIMD_NONE

#endif




#if !defined(GLB_SET_COORDINATE_SYSTEM_LH) && !defined(GLB_SET_COORDINATE_SYSTEM_RH)
 
#   error Coordinate system (Left-Handed or Right-Handed) not specified ! Use GLB_SET_COORDINATE_SYSTEM_LH or GLB_SET_COORDINATE_SYSTEM_RH.
#endif


#if !defined(GLB_SET_Z_RANGE_0_1) && !defined(GLB_SET_Z_RANGE_N1_1)
 
#   error Z-range ([0; 1] or [-1; 1]) not specified ! Use GLB_SET_Z_RANGE_0_1 or GLB_SET_Z_RANGE_N1_1.
#endif


#if !defined(GLB_SET_Y_AXIS_UPWARDS) && !defined(GLB_SET_Y_AXIS_DOWNWARDS)
 
#   error Y axis direction (upwards or downwards) not specified ! Use GLB_SET_Y_AXIS_UPWARDS or GLB_SET_Y_AXIS_DOWNWARDS.
#endif


#if !defined(GLB_SET_ROTATION_ORDER_XYZ) && !defined(GLB_SET_ROTATION_ORDER_XZY) && !defined(GLB_SET_ROTATION_ORDER_YXZ) && \
    !defined(GLB_SET_ROTATION_ORDER_YZX) && !defined(GLB_SET_ROTATION_ORDER_ZXY) && !defined(GLB_SET_ROTATION_ORDER_ZYX) 

#   error Rotation order (XYZ, XZY, YXZ, YZX, ZXY or ZYX) not specified ! Use GLB_SET_ROTATION_ORDER_... XYZ, XZY, YXZ, YZX, ZXY or ZYX.
#endif


#if !defined(GLB_SET_ROTATION_TYPE_INTRINSIC) && !defined(GLB_SET_ROTATION_TYPE_EXTRINSIC) 

#   error State of the rotation axis (rotating or static) not specified ! Use GLB_SET_ROTATION_TYPE_INSTRINSIC or GLB_SET_ROTATION_TYPE_EXTRINSIC.
#endif





#if defined(GLB_SIMD_AVX)
#	include <immintrin.h>

#elif defined(GLB_SIMD_SSE4)
#	include <smmintrin.h>

#elif defined(GLB_SIMD_SSSE3)
#	include <tmmintrin.h>

#elif defined(GLB_SIMD_SSE3)
#	include <pmmintrin.h>

#elif defined(GLB_SIMD_SSE2)
#	include <emmintrin.h>

#elif defined(GLB_SIMD_SSE)
#	include <xmmintrin.h>

#endif



#if defined(GLB_FORCE_ALWAYS_INLINE)
#   if defined(GLB_COMPILER_MSVC)
#       define GLB_INLINE __forceinline

#   else
#       define GLB_INLINE __attribute__((always_inline))

#   endif

#else
#   define GLB_INLINE inline

#endif 


/** Gammalgebra version :
 * 
 * `Major * 1'000'000 + Minor * 1'000 + Patch` 
 * 
 * Ex: Version 1.4.28 = 1004028
 */
#define GLB_VERSION 1005000


