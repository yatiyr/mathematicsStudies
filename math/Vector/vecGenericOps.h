#ifndef __VEC_GENERIC_OPS__
#define __VEC_GENERIC_OPS__

#include "vecGeneric.h"
#include <cstdlib>
#include <iostream>
#include <types.h>
#include <math.h>

namespace hyl
{

/**
 *      FUNCTIONS COMMON FOR ALL VECTOR TYPES ARE IMPLEMENTED HERE
 **/

// ------------------------------------------------------------------------//
// ------------------------ PRINTING FUNCTIONS ----------------------------//
// ------------------------------------------------------------------------//

    template <size_t n, typename T>
    inline std::ostream& operator<<(std::ostream& os, vec<n, T>& v) {
        os << "< ";
        for(size_t i = 0; i<n-1; i++)
        {
            os << v(i) << ", ";
        }
        os << v(n-1) << " ";

        os << ">";

        return os;
    }

    // for printing 8 bit unsigned integer values
    template <size_t n>
    inline std::ostream& operator<<(std::ostream& os, vec<n, ui8>& v) {
        os << "< ";
        for(size_t i = 0; i<n-1; i++)
        {
            os << unsigned(v(i)) << ", ";
        }
        os << unsigned(v(n-1)) << " ";

        os << ">";

        return os;
    }

    // for printing 8 bit integer values
    template <size_t n>
    inline std::ostream& operator<<(std::ostream& os, vec<n, i8>& v) {
        os << "< ";
        for(size_t i = 0; i<n-1; i++)
        {
            os << int(v(i)) << ", ";
        }
        os << int(v(n-1)) << " ";

        os << ">";

        return os;
    }

// *********************** END PRINT FUNCTIONS *************************** //

// ----------------------------------------------------------------------- //
// ------------------------- NEGATION FUNCTION --------------------------- //
// ----------------------------------------------------------------------- //

    template <size_t n, typename T>
    inline vec<n, T> vec<n,T>::operator-()
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = -data[i];
        }
        return ans;
    }

// ********************** END NEGATION FUNCTION ************************** //


// ----------------------------------------------------------------------- //
// ------------------------- ADDITION FUNCTIONS -------------------------- //
// ----------------------------------------------------------------------- //

    template <size_t n, typename T>
    inline vec<n, T> operator+(vec<n, T>& lhs, T scalar)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) + scalar;
        }
    }

    template <size_t n, typename T>
    inline vec<n, T> operator+(T scalar, vec<n, T>& rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = rhs(i) + scalar;
        }
        return ans;
    }

    template <size_t n, typename T>
    inline vec<n, T> operator+(vec<n, T>& lhs, vec<n, T>& rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) + rhs(i);
        }
        return ans;
    }

// ********************** END ADDITION FUNCTIONS ************************* //

// ----------------------------------------------------------------------- //
// ----------------------- SUBSTRACTION FUNCTIONS ------------------------ //
// ----------------------------------------------------------------------- //

    template <size_t n, typename T>
    inline vec<n, T> operator-(vec<n, T>& lhs, T scalar)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) - scalar;
        }
    }

    template <size_t n, typename T>
    inline vec<n, T> operator-(T scalar, vec<n, T>& rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = scalar - rhs(i);
        }
        return ans;
    }

    template <size_t n, typename T>
    inline vec<n, T> operator-(vec<n, T>& lhs, vec<n, T>& rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) - rhs(i);
        }
        return ans;
    }

// ******************** END SUBSTRACTION FUNCTIONS *********************** //

// ----------------------------------------------------------------------- //
// ---------------------- MULTIPLICATION FUNCTIONS ----------------------- //
// ----------------------------------------------------------------------- //

    template<size_t n, typename T>
    inline vec<n, T> operator*(vec<n, T>& lhs, T scalar)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) * scalar;
        }
        return ans;
    }

    template<size_t n, typename T>
    inline vec<n, T> operator*(T scalar, vec<n, T> rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = scalar * rhs(i);
        }
        return ans;
    }

    template<size_t n, typename T>
    inline vec<n, T>& operator*=(vec<n, T>& lhs, T scalar)
    {
        for(size_t i=0; i<n; i++)
        {
            lhs(i) *= scalar;       
        }

        return lhs;
    }

    template<size_t n, typename T>
    inline vec<n, T> operator*(vec<n, T>& lhs, vec<n, T>& rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) * rhs(i);
        }
        return ans;
    }

// ******************** END MULTIPLICATION FUNCTIONS ********************** //

// ----------------------------------------------------------------------- //
// -------------------------- DIVISION FUNCTIONS ------------------------- //
// ----------------------------------------------------------------------- //

    template <size_t n, typename T>
    inline vec<n, T> operator/(vec<n, T>& lhs, T scalar)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) / scalar;
        }
        return ans;
    }

    template <size_t n, typename T>
    inline vec<n, T> operator/(T scalar, vec<n, T>& rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = scalar / rhs(i);
        }
        return ans;
    }

    template <size_t n, typename T>
    inline vec<n, T> operator/(vec<n, T>& lhs, vec<n, T>& rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) / rhs(i);
        }
        return ans;
    }

    template<size_t n, typename T>
    inline vec<n, T>& operator/=(vec<n, T>& lhs, T scalar)
    {
        for(size_t i=0; i<n; i++)
        {
            lhs(i) /= scalar;       
        }

        return lhs;
    }    

// *********************** END DIVISION FUNCTIONS ************************ //

// ----------------------------------------------------------------------- //
// -------------------------- DOT PRODUCT -------------------------------- //
// ----------------------------------------------------------------------- //

    template <size_t n, typename T>
    inline T dot(vec<n, T>& lhs, vec<n, T>& rhs)
    {
        T ans = 0;

        for(size_t i=0; i<n; i++)
        {
            ans += lhs(i) * rhs(i);
        }

        return ans;
    }


// ************************** END DOT PRODUCT **************************** //

// ----------------------------------------------------------------------- //
// ------------------------- LENGTH FUNCTIONS ---------------------------- //
// ----------------------------------------------------------------------- //

    template <size_t n, typename T>
    inline T length(vec<n, T>& v)
    {
        T squareSum = 0;

        for(size_t i=0; i<n; i++)
        {
            squareSum += v(i) * v(i);
        }

        return std::sqrt(squareSum);
    }

    template <size_t n, typename T>
    inline T lengthSquared(vec<n, T>& v)
    {
        T squareSum = 0;

        for(size_t i=0; i<n; i++)
        {
            squareSum += v(i) * v(i);
        }

        return squareSum;
    }

    template <size_t n, typename T>
    inline void normalize(vec<n, T>& v)
    {
        T l = length(v);

        v /= l;
    }

    template <size_t n, typename T>
    inline vec<n, T> normalized(vec<n, T>& v)
    {
        T l = length(v);

        return (v / l);

    }


// *********************** END LENGTH FUNCTIONS ************************** //

}


#endif /* __VEC_GENERIC_OPS__ */