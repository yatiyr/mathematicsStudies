#ifndef __VEC_TYPE_ALIASES__
#define __VEC_TYPE_ALIASES__

#include "Vector/vecGeneric.h"
#include <types.h>

namespace hyl
{
    using fvec2 = vec<2, f32>;
    using fvec3 = vec<3, f32>;
    using fvec4 = vec<4, f32>;

    using dvec2 = vec<2, f64>;
    using dvec3 = vec<3, f64>;
    using dvec4 = vec<4, f64>;

    using i8vec2 = vec<2, i8>;
    using i8vec3 = vec<3, i8>;
    using i8vec4 = vec<4, i8>;

    using i16vec2 = vec<2, i16>;
    using i16vec3 = vec<3, i16>;
    using i16vec4 = vec<4, i16>;

    using ivec2 = vec<2, i32>;
    using ivec3 = vec<3, i32>;
    using ivec4 = vec<4, i32>;

    using i64vec2 = vec<2, i64>;
    using i64vec3 = vec<3, i64>;
    using i64vec4 = vec<4, i64>;

    using ui16vec2 = vec<2, ui16>;
    using ui16vec3 = vec<3, ui16>;
    using ui16vec4 = vec<4, ui16>;

    using uivec2 = vec<2, ui32>;
    using uivec3 = vec<3, ui32>;
    using uivec4 = vec<4, ui32>;

    using ui64vec2 = vec<2, ui64>;
    using ui64vec3 = vec<3, ui64>;
    using ui64vec4 = vec<4, ui64>;
}

#endif /* __VEC_TYPE_ALIASES__ */