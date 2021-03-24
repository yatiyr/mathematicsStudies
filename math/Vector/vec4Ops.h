#ifndef __VEC4_OPS__
#define __VEC4_OPS__

#include "vec4.h"

namespace hyl
{

// ----------------------------------------------------------------------- //
// ------------------------- NEGATION FUNCTION --------------------------- //
// ----------------------------------------------------------------------- //

    template <typename T>
    inline vec<4, T> vec<4, T>::operator-()
    {
        return vec<4, T>(-x, -y, -z, -w);
    }

// ********************** END NEGATION FUNCTION ************************** //    
}

#endif /* __VEC4_OPS__ */