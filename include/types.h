#ifndef __TYPES__
#define __TYPES__

#include <cstdint>

namespace hyl
{
    using i8  = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
    using i64 = int64_t;

    using i8f  = int_fast8_t;
    using i16f = int_fast16_t;
    using i32f = int_fast32_t;
    using i64f = int_fast64_t;

    using ui8  = uint8_t;
    using ui16 = uint16_t;
    using ui32 = uint32_t;
    using ui64 = uint64_t;

    using ui8f  = uint_fast8_t;
    using ui16f = uint_fast16_t;
    using ui32f = uint_fast32_t;
    using ui64f = uint_fast64_t;

    using imax = intmax_t;
    using iptr = intptr_t;

    using f32 = float;
    using f64 = double;

    using uchr = unsigned char;
    using chr  = char;

}



#endif