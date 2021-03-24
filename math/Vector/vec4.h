#ifndef __VEC4__
#define __VEC4__

#include "vecGeneric.h"
#include <assert.h>

namespace hyl
{
    template<typename T>
    struct vec<4, T>
    {
        typedef T value_type;

        union
        {
            std::array<value_type, 4> data;

            struct
            {
                value_type x;
                value_type y;
                value_type z;
                value_type w;
            };

            struct
            {
                vec<3, value_type> xyz;
                value_type _xyz_ignored_w;
            };

            struct
            {
                value_type _yzw_ignored_x;
                vec<3, value_type> yzw;
            };

            struct
            {
                vec<2, value_type> xy;
                vec<2, value_type> zw;
            };

            struct
            {
                value_type _yz_ignored_x;
                vec<2, value_type> yz;
                value_type _yz_ignored_w;
            };


        };

        vec()
        {
            this->x = 0;
            this->y = 0;
            this->z = 0;
            this->w = 0;
        }

        vec(const value_type& val)
        {
            this->x = val;
            this->y = val;
            this->z = val;
            this->w = val;
        }

        vec(const std::initializer_list<value_type> args)
        {
            assert(args.size() <= 4);
            data = args;
        }

        vec(const value_type& x, const value_type& y, const value_type& z, const value_type& w)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        vec(const vec<2, value_type>& xy, const vec<2, value_type>& zw)
        {
            this->x = xy.x;
            this->y = xy.y;
            this->z = zw.z;
            this->w = zw.w;
        }

        vec(const vec<3, value_type>& xyz, const value_type& w)
        {
            this->x = xyz.x;
            this->y = xyz.y;
            this->z = xyz.z;
            this->w = w;
        }

        value_type& operator() (const size_t idx)
        {
            assert(idx >= 0 && idx < 4);
            return data[idx];
        }

        vec<4, T> operator-();
    };
}

#endif /* __VEC4 __ */