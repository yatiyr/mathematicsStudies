#ifndef __VEC3__
#define __VEC3__

#include "vecGeneric.h"
#include <assert.h>

namespace hyl
{
    template<typename T>
    struct vec<3, T>
    {
        typedef T value_type;

        static vec<3, value_type> UP;
        static vec<3, value_type> DOWN;
        static vec<3, value_type> LEFT;
        static vec<3, value_type> RIGHT;
        static vec<3, value_type> FORWARD;
        static vec<3, value_type> BACKWARD;

        union
        {
            std::array<value_type, 3> data;

            struct
            {
                value_type x;
                value_type y;
                value_type z;
            };

            struct
            {
                vec<2, value_type> xy;
                value_type _xy_ignored_z;
            };

            struct
            {
                value_type _yz_ignored_x;
                vec<2, value_type> yz;
            };
            
        };

        vec()
        {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }

        vec(const value_type& val)
        {
            this->x = val;
            this->y = val;
            this->z = val;
        }

        vec(const std::initializer_list<value_type> args)
        {
            assert(args.size() <= 3);
            data = args;
        }

        vec(const value_type& x, const value_type& y, const value_type& z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        vec(const vec<2, value_type>& vec, const value_type& z)
        {
            this->x = vec.x;
            this->y = vec.y;
            this->z = z;
        }

        vec(const value_type& x, const vec<2, value_type>& vec)
        {
            this->x = x;
            this->y = vec.x;
            this->z = vec.y;
        }

        value_type& operator() (const size_t idx)
        {
            assert(idx >= 0 && idx < 3);
            return data[idx];
        }

        vec<3, value_type> operator-();
        
    };

    // We are talking about right handed coordinate system here where middle finger
    // points us
    template<typename T> vec<3, T> vec<3, T>::UP       = vec<3, T>( 0.0,  1.0,  0.0);
    template<typename T> vec<3, T> vec<3, T>::DOWN     = vec<3, T>( 0.0, -1.0,  0.0);
    template<typename T> vec<3, T> vec<3, T>::LEFT     = vec<3, T>(-1.0,  0.0,  0.0);
    template<typename T> vec<3, T> vec<3, T>::RIGHT    = vec<3, T>( 1.0,  0.0,  0.0);
    template<typename T> vec<3, T> vec<3, T>::FORWARD  = vec<3, T>( 0.0,  0.0, -1.0);
    template<typename T> vec<3, T> vec<3, T>::BACKWARD = vec<3, T>( 0.0,  0.0,  1.0);    
}

#endif /* __VEC3__ */