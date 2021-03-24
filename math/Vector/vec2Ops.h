#ifndef __VEC2_OPS__
#define __VEC2_OPS__

#include "vec2.h"

namespace hyl
{

// ----------------------------------------------------------------------- //
// ------------------------- NEGATION FUNCTION --------------------------- //
// ----------------------------------------------------------------------- //

    template <typename T>
    inline vec<2, T> vec<2, T>::operator-()
    {
        return vec<2, T>(-x, -y);
    } 

// ********************** END NEGATION FUNCTION ************************** //


// ----------------------------------------------------------------------- //
// ----------------------- DOT & CROSS PRODUCT --------------------------- //
// ----------------------------------------------------------------------- //


    template <typename T>
    inline T dot(vec<2, T>& lhs, vec<2, T>& rhs)
    {
        return lhs.x*rhs.x + lhs.y*rhs.y;
    }

    // cross product of 2D vector will give a scalar value
    template <typename T>
    inline T cross(vec<2, T>& lhs, vec<2, T>& rhs)
    {
        return lhs.x*rhs.y - rhs.x*lhs.y;
    }

// ******************** END DOT & CROSS PRODUCT ************************* //

// ----------------------------------------------------------------------- //
// ------------------------- LENGTH FUNCTIONS ---------------------------- //
// ----------------------------------------------------------------------- //

    template <typename T>
    inline T length(vec<2, T>& v)
    {
        return sqrt(v.x * v.x + v.y * v.y);
    }

    template <typename T>
    inline T lengthSquared(vec<2, T>& v)
    {
        return (v.x * v.x + v.y * v.y);
    }

    template <typename T>
    inline void normalize(vec<2, T>& v)
    {
        T l = length(v);

        v.x /= l;
        v.y /= l;
    }

// *********************** END LENGTH FUNCTIONS ************************** //


// ----------------------------------------------------------------------- //
// ---------------- PROJECTION AND REFLECTION FUNCTIONS ------------------ //
// ----------------------------------------------------------------------- //

    template <typename T>
    inline vec<2, T> projection(vec<2, T>& v, vec<2, T>& normal)
    {
        return (dot(v, normal) * normal);
    }

    // TODO: TRY TO SOLVE WITHOUT TEMP VARIABLES
    template <typename T>
    inline vec<2, T> surfaceProjection(vec<2, T>& v, vec<2, T>& normal)
    {
        vec<2, T> temp = (dot(v, normal) * normal);
        return (v - temp);
    }

    template <typename T>
    inline vec<2, T> reflection(vec<2, T>& v, vec<2, T>& normal)
    {
        vec<2, T> temp = 2 * dot(v, normal) * normal;
        return (v - temp);
    }


// **************** PROJECTION AND REFLECTION FUNCTIONS ****************** //

}

#endif /* __VEC2_OPS__ */