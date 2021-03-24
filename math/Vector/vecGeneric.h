#ifndef __VEC_GENERIC__
#define __VEC_GENERIC__

#include <cstdlib>
#include <assert.h>

namespace hyl
{

    // IT'S A GENERAL VECTOR CLASS
    template<size_t n, typename T>
    struct vec
    {
        typedef T value_type;

        std::array<value_type,n> data;

        vec()
        {

        }

        // Like in glm library, all values of vector
        // will be initialized with val
        vec(const value_type& val)
        {
            for(size_t i=0; i<n; i++)
            {
                data[i] = val;
            }
        }

        vec(const std::initializer_list<value_type> args)
        {
            assert(args.size() < n);
            data = args;
        }

        value_type& operator() (const size_t idx)
        {
            assert(idx >= 0 && idx <n);
            return data[idx];
        }

        vec<n, value_type> operator-();

    };
}


#endif /* __VEC_GENERIC__ */