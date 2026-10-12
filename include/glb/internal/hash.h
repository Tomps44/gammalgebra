#pragma once

#include "vec/type_vec2.h"
#include "vec/type_vec3.h"
#include "vec/type_vec4.h"

#include "mat/type_mat2x2.h"
#include "mat/type_mat3x3.h"
#include "mat/type_mat4x4.h"

#include "type_quat.h"

#include <functional>

namespace glb
{
    namespace glbIntern
    {
        GLB_INLINE constexpr void hashCombine(size_t& seed, size_t hash)
        {
            hash += 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= hash;
        }
    }
}



namespace std
{
    template<typename T>
    struct hash<glb::glbVec_T<2, T>>
    {
        size_t operator()(const glb::glbVec_T<2, T>& v) const noexcept
        {
            size_t res = 0;
            hash<T> hasher;

            glb::glbIntern::hashCombine(res, hasher(v.x));
            glb::glbIntern::hashCombine(res, hasher(v.y));

            return res;
        }
    };
    template<typename T>
    struct hash<glb::glbVec_T<3, T>>
    {
        size_t operator()(const glb::glbVec_T<3, T>& v) const noexcept
        {
            size_t res = 0;
            hash<T> hasher;

            glb::glbIntern::hashCombine(res, hasher(v.x));
            glb::glbIntern::hashCombine(res, hasher(v.y));
            glb::glbIntern::hashCombine(res, hasher(v.z));

            return res;
        }
    };

    template<typename T>
    struct hash<glb::glbVec_T<4, T>>
    {
        size_t operator()(const glb::glbVec_T<4, T>& v) const noexcept
        {
            size_t res = 0;
            hash<T> hasher;

            glb::glbIntern::hashCombine(res, hasher(v.x));
            glb::glbIntern::hashCombine(res, hasher(v.y));
            glb::glbIntern::hashCombine(res, hasher(v.z));
            glb::glbIntern::hashCombine(res, hasher(v.w));

            return res;
        }
    };


    template<typename T>
    struct hash<glb::glbQuat_T<T>>
    {
        size_t operator()(const glb::glbQuat_T<T>& v) const noexcept
        {
            size_t res = 0;
            hash<T> hasher;

            glb::glbIntern::hashCombine(res, hasher(v.w));
            glb::glbIntern::hashCombine(res, hasher(v.x));
            glb::glbIntern::hashCombine(res, hasher(v.y));
            glb::glbIntern::hashCombine(res, hasher(v.z));

            return res;
        }
    };


    template<typename T>
    struct hash<glb::glbMat_T<2, 2, T>>
    {
        size_t operator()(const glb::glbMat_T<2, 2, T>& v) const noexcept
        {
            size_t res = 0;
            hash<glb::glbVec_T<2, T>> hasher;

            glb::glbIntern::hashCombine(res, hasher(v[0]));
            glb::glbIntern::hashCombine(res, hasher(v[1]));

            return res;
        }
    };

    template<typename T>
    struct hash<glb::glbMat_T<3, 3, T>>
    {
        size_t operator()(const glb::glbMat_T<3, 3, T>& v) const noexcept
        {
            size_t res = 0;
            hash<glb::glbVec_T<3, T>> hasher;

            glb::glbIntern::hashCombine(res, hasher(v[0]));
            glb::glbIntern::hashCombine(res, hasher(v[1]));
            glb::glbIntern::hashCombine(res, hasher(v[2]));

            return res;
        }
    };

    template<typename T>
    struct hash<glb::glbMat_T<4, 4, T>>
    {
        size_t operator()(const glb::glbMat_T<3, 3, T>& v) const noexcept
        {
            size_t res = 0;
            hash<glb::glbVec_T<4, T>> hasher;

            glb::glbIntern::hashCombine(res, hasher(v[0]));
            glb::glbIntern::hashCombine(res, hasher(v[1]));
            glb::glbIntern::hashCombine(res, hasher(v[2]));
            glb::glbIntern::hashCombine(res, hasher(v[3]));

            return res;
        }
    };
    

} // namespace std


