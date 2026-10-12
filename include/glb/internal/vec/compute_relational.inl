#include "../compute/compute_equal.h"
#include <limits>

namespace glb
{
    namespace Vec
    {
        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> GreaterThan(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            glbVec_T<S, bool> res = glbVec_T<S, bool>{true};

            for (int s = 0; s < S; s++)
                res[s] = a[s] > b[s];
            
            return res;
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> GreaterThanOrEqual(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            glbVec_T<S, bool> res = glbVec_T<S, bool>{true};

            for (int s = 0; s < S; s++)
                res[s] = a[s] >= b[s];
            
            return res;
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> LessThan(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            glbVec_T<S, bool> res = glbVec_T<S, bool>{true};

            for (int s = 0; s < S; s++)
                res[s] = a[s] < b[s];
            
            return res;
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> LessThanOrEqual(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            glbVec_T<S, bool> res = glbVec_T<S, bool>{true};

            for (int s = 0; s < S; s++)
                res[s] = a[s] <= b[s];
            
            return res;
        }


        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> Equal(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            glbVec_T<S, bool> res = glbVec_T<S, bool>{true};

            for (int s = 0; s < S; s++)
                res[s] = glbIntern::computeEqual<T, std::numeric_limits<T>::is_iec559>::call(a[s], b[s]);

            return res;
        }

        template<int S, typename T>
        GLB_INLINE constexpr glbVec_T<S, bool> NotEqual(const glbVec_T<S, T>& a, const glbVec_T<S, T>& b) noexcept
        {
            return ~equal(a, b);
        }



        template<int S>
        GLB_INLINE constexpr bool Any(const glbVec_T<S, bool>& v) noexcept
        {
            bool res = false;

            for (int s = 0; s < 0; s++)
                res = res || v[s];

            return res;
        }

        template<int S>
        GLB_INLINE constexpr bool All(const glbVec_T<S, bool>& v) noexcept
        {
            bool res = true;

            for (int s = 0; s < 0; s++)
                res = res && v[s];

            return res;
        }

    

    } // namespace Vec
    
} // namespace glb
