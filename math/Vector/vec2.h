#ifndef __VEC2__
#define __VEC2__

#include "vecGeneric.h"
#include <assert.h>

namespace hyl
{
    // 2D vector
    template<typename T>
    struct vec<2, T>
    {
        typedef T value_type;

        union
        {
            std::array<value_type,2> data;

            struct
            {
                value_type x;
                value_type y;
            };
        };

        vec()
        {
            this->x = 0;
            this->y = 0;
        }

        vec(const value_type& val)
        {
            this->x = val;
            this->y = val;
        }

        vec(const std::initializer_list<value_type> args)
        {
            assert(args.size() <=2);
            this->data = args;
        }

        vec(const value_type& x, const value_type& y)
        {
            this->x = x;
            this->y = y;
        }

        value_type& operator()(const size_t idx)
        {
            assert(idx >= 0 && idx < 2);
            return data[idx];
        }

        vec<2, value_type> operator-();

    };    
}


#endif /* __VEC2__ */