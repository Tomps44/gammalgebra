#pragma once

#include <cstdint>




#if defined(_MSC_VER)
#   define TMX_COMPILER_MSVC

#elif defined(__clang__)
#   define TMX_COMPILER_CLANG

#elif defined(__GNUC__) 
#   define TMX_COMPILER_GCC

#endif

// #if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64)
// #   define TMX_PLATFORM_AMD64

// #elif defined(__arm__) || defined(_M_ARM)
// #   define TMX_PLATFORM_ARM

// #elif defined(__aarch64__) || defined(_M_ARM64)
// #   define TMX_PLATFORM_ARM64

// #endif

#if defined(__ANDROID__)
#   define TMX_PLATFORM_ANDROID

#elif defined(__linux__)
#   define TMX_PLATFORM_LINUX

#elif defined(__WIN32) || defined(__WIN64) || defined(__WIN16)
#   define TMX_PLATFORM_WINDOWS

#elif defined(__unix__) || defined(__unix)
#   define TMX_PLATFORM_UNIX

#elif defined(__APPLE__)
#   define TMX_PLATFORM_APPLE

#endif



#if !defined(TMX_FORCE_SIMD_NONE)
#   if defined(TMX_FORCE_SIMD_AVX) || defined(__AVX2__) || defined(__AVX__)
#       define TMX_SIMD_AVX
#       define TMX_SIMD_SSE4
#       define TMX_SIMD_SSSE3
#       define TMX_SIMD_SSE3
#       define TMX_SIMD_SSE2
#       define TMX_SIMD_SSE

#   elif defined(TMX_FORCE_SIMD_SSE4) || defined(__SSE4_2__) || defined(__SSE4_1__)
#       define TMX_SIMD_SSE4
#       define TMX_SIMD_SSSE3
#       define TMX_SIMD_SSE3
#       define TMX_SIMD_SSE2
#       define TMX_SIMD_SSE

#   elif defined(TMX_FORCE_SIMD_SSSE3) || defined(__SSSE3__) 
#       define TMX_SIMD_SSSE3
#       define TMX_SIMD_SSE3
#       define TMX_SIMD_SSE2
#       define TMX_SIMD_SSE

#   elif defined(TMX_FORCE_SIMD_SSE3) || defined(__SSE3__) 
#       define TMX_SIMD_SSE3
#       define TMX_SIMD_SSE2
#       define TMX_SIMD_SSE


#   elif defined(TMX_FORCE_SIMD_SSE2) || defined(__SSE2__)
#       define TMX_SIMD_SSE2 
#       define TMX_SIMD_SSE 

#   elif defined(TMX_FORCE_SIMD_SSE) || defined(__SSE__)
#       define TMX_SIMD_SSE

#   else 
#       define TMX_SIMD_NONE

#   endif

#else 
#   define TMX_SIMD_NONE

#endif


#if defined(TMX_SIMD_AVX)
#	include <immintrin.h>

#elif defined(TMX_SIMD_SSE4)
#	include <smmintrin.h>

#elif defined(TMX_SIMD_SSSE3)
#	include <tmmintrin.h>

#elif defined(TMX_SIMD_SSE3)
#	include <pmmintrin.h>

#elif defined(TMX_SIMD_SSE2)
#	include <emmintrin.h>

#elif defined(TMX_SIMD_SSE)
#	include <xmmintrin.h>

#endif


/* #define TMX_ALIGN_AS(type) \
       #if defined(TMX_COMPILER_MSVC) 
           alignas(sizeof(type) * 4)
       #endif */


#define TMX_INLINE inline // or change to forceinline


#define TMX_STATIC_ASSERT(cond, mes) static_assert(cond, mes) 
#define TMX_ASSERT_INDEX(i, max) static_assert(i < max, "The specified index is too large !")

