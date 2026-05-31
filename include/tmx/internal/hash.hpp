#pragma once

#include "tmx/internal/vec/type_vec2.hpp"
#include "tmx/internal/vec/type_vec3.hpp"
#include "tmx/internal/vec/type_vec4.hpp"

#include "tmx/internal/mat/type_mat2x2.hpp"
#include "tmx/internal/mat/type_mat3x3.hpp"
#include "tmx/internal/mat/type_mat4x4.hpp"

#include "tmx/internal/type_quat.hpp"

#include <functional>

namespace tmx
{
    namespace internal
    {
        TMX_INLINE constexpr void hashCombine(size_t& seed, size_t hash)
        {
            hash += 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= hash;
        }
    }
}


    // template<typename T>
    // TMX_INLINE constexpr size_t hash<tmx::vec<2, T>>::operator()(const tmx::vec<2, T>& v) const

namespace std
{
    template<typename T>
    struct hash<tmx::vec<2, T>>
    {
        size_t operator()(const tmx::vec<2, T>& v) const noexcept
        {
            size_t res = 0;
            hash<T> hasher;

            tmx::internal::hashCombine(res, hasher(v.x));
            tmx::internal::hashCombine(res, hasher(v.y));

            return res;
        }
    };
    template<typename T>
    struct hash<tmx::vec<3, T>>
    {
        size_t operator()(const tmx::vec<3, T>& v) const noexcept
        {
            size_t res = 0;
            hash<T> hasher;

            tmx::internal::hashCombine(res, hasher(v.x));
            tmx::internal::hashCombine(res, hasher(v.y));
            tmx::internal::hashCombine(res, hasher(v.z));

            return res;
        }
    };

    template<typename T>
    struct hash<tmx::vec<4, T>>
    {
        size_t operator()(const tmx::vec<4, T>& v) const noexcept
        {
            size_t res = 0;
            hash<T> hasher;

            tmx::internal::hashCombine(res, hasher(v.x));
            tmx::internal::hashCombine(res, hasher(v.y));
            tmx::internal::hashCombine(res, hasher(v.z));
            tmx::internal::hashCombine(res, hasher(v.w));

            return res;
        }
    };


    template<typename T>
    struct hash<tmx::quat<T>>
    {
        size_t operator()(const tmx::quat<T>& v) const noexcept
        {
            size_t res = 0;
            hash<T> hasher;

            tmx::internal::hashCombine(res, hasher(v.w));
            tmx::internal::hashCombine(res, hasher(v.x));
            tmx::internal::hashCombine(res, hasher(v.y));
            tmx::internal::hashCombine(res, hasher(v.z));

            return res;
        }
    };


    template<typename T>
    struct hash<tmx::mat<2, 2, T>>
    {
        size_t operator()(const tmx::mat<2, 2, T>& v) const noexcept
        {
            size_t res = 0;
            hash<tmx::vec<2, T>> hasher;

            tmx::internal::hashCombine(res, hasher(v[0]));
            tmx::internal::hashCombine(res, hasher(v[1]));

            return res;
        }
    };

    template<typename T>
    struct hash<tmx::mat<3, 3, T>>
    {
        size_t operator()(const tmx::mat<3, 3, T>& v) const noexcept
        {
            size_t res = 0;
            hash<tmx::vec<3, T>> hasher;

            tmx::internal::hashCombine(res, hasher(v[0]));
            tmx::internal::hashCombine(res, hasher(v[1]));
            tmx::internal::hashCombine(res, hasher(v[2]));

            return res;
        }
    };

    template<typename T>
    struct hash<tmx::mat<4, 4, T>>
    {
        size_t operator()(const tmx::mat<3, 3, T>& v) const noexcept
        {
            size_t res = 0;
            hash<tmx::vec<4, T>> hasher;

            tmx::internal::hashCombine(res, hasher(v[0]));
            tmx::internal::hashCombine(res, hasher(v[1]));
            tmx::internal::hashCombine(res, hasher(v[2]));
            tmx::internal::hashCombine(res, hasher(v[3]));

            return res;
        }
    };
    

} // namespace std


