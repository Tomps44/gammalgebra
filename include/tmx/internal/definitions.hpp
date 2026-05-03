#pragma once

#include "tmx/internal/setup.hpp"

namespace tmx
{
    template<size_t S, typename T> struct vec;
    template<size_t R, size_t C, typename T> struct mat;
    template<typename T> struct quat;
    template<typename T> struct dQuat;



    // Default type for Math:: functions, can be changed
    typedef float Real;



    namespace internal
    {
        template<typename T>
        struct isInt 
        {
            static const bool value = false;
        };


        template<>
        struct isInt<int> 
        {
            static const bool value = true;
        };

        template<>
        struct isInt<unsigned int> 
        {
            static const bool value = true;
        };




        template<size_t S, typename T>
        struct useSimd 
        {
            static const bool value = false;
        };
        template<size_t S, typename T>
        struct simdReg
        {
            typedef struct type
            {
                T reg[S];
            } type;
            
        };


#if     defined(TMX_SIMD_SSE)
        template<>
        struct useSimd<4, float>
        {
            static const bool value = true;
        };

        template<>
        struct simdReg<4, float>
        {
            typedef __m128 type;
            
        };
#endif

#if     defined(TMX_SIMD_AVX)
        template<>
        struct useSimd<4, double>
        {
            static const bool value = true;
        };

        template<>
        struct simdReg<4, double>
        {
            typedef __m256d type;
            
        };
#endif

#if     defined(TMX_SIMD_SSE2)
        template<>
        struct useSimd<4, int>
        {
            static
             const bool value = true;
        };
        template<>
        struct simdReg<4, int>
        {
            typedef __m128i type;
        };
#endif


        


        

    } // namespace internal
} // namespace tmx