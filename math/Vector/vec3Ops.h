#ifndef __VEC3_OPS__
#define __VEC3_OPS__

#include "vec3.h"

namespace hyl
{

// ----------------------------------------------------------------------- //
// ------------------------- NEGATION FUNCTION --------------------------- //
// ----------------------------------------------------------------------- //

    template <typename T>
    inline vec<3, T> vec<3, T>::operator-()
    {
        return vec<3, T>(-x, -y, -z);
    }

// ********************** END NEGATION FUNCTION ************************** //


// ----------------------------------------------------------------------- //
// -------------------------- DOT & CROSS PRODUCT ------------------------ //
// ----------------------------------------------------------------------- //


    template <typename T>
    inline T dot(vec<3, T>& lhs, vec<3, T>& rhs)
    {
        return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
    }

    template <typename T>
    inline vec<3, T> cross(vec<3, T>& lhs, vec<3, T>& rhs)
    {
        return vec<3, T>(lhs.y*rhs.z - rhs.y*lhs.z,
                         lhs.z*rhs.x - rhs.z*lhs.x,
                         lhs.x*rhs.y - rhs.x*lhs.y);
    }

// ********************* END DOT & CROSS PRODUCT ************************* //

// ----------------------------------------------------------------------- //
// ------------------------- LENGTH FUNCTIONS ---------------------------- //
// ----------------------------------------------------------------------- //

    template <typename T>
    inline T length(vec<3, T>& v)
    {
        return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    }

    template <typename T>
    inline T lengthSquared(vec<3, T>& v)
    {
        return (v.x*v.x + v.y*v.y + v.z*v.z);
    }

    template <typename T>
    inline void normalize(vec<3, T>& v)
    {
        T l = length(v);

        v.x /= l;
        v.y /= l;
        v.z /= l;
    }

// *********************** END LENGTH FUNCTIONS ************************** //


// ----------------------------------------------------------------------- //
// ---------------- PROJECTION AND REFLECTION FUNCTIONS ------------------ //
// ----------------------------------------------------------------------- //

    template <typename T>
    inline vec<3, T> projection(vec<3, T>& v, vec<3, T>& normal)
    {
        return (dot(v, normal) * normal);
    }


    // TODO: TRY TO SOLVE WITHOUT TEMP VARIABLES
    template <typename T>
    inline vec<3, T> surfaceProjection(vec<3, T>& v, vec<3, T>& normal)
    {
        vec<3, T> temp = (dot(v, normal) * normal);
        return (v - temp);
    }

    template <typename T>
    inline vec<3, T> reflection(vec<3, T>& v, vec<3, T>& normal)
    {
        vec<3, T> temp = 2 * dot(v, normal) * normal;
        return (v - temp);
    }


// **************** PROJECTION AND REFLECTION FUNCTIONS ****************** //

}

#endif /* __VEC3_OPS__ */