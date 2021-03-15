#ifndef __VECTOR_DEF__
#define __VECTOR_DEF__

#include <cstdlib>
#include <assert.h>
#include <array>
#include <types.h>

namespace hyl
{

    // generic vector
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
            this.x = 0;
            this.y = 0;
        }

        vec(const value_type& val)
        {
            this.x = val;
            this.y = val;
        }

        vec(const std::intitializer_list<T> args)
        {
            assert(args.size() <=2);
            this.data = args;
        }

        vec(const value_type& x, const value_type& y)
        {
            this.x = x;
            this.y = y;
        }

        value_type& operator()(const size_t idx)
        {
            assert(idx >= 0 && idx < 2);
            return data[idx];
        }

        vec<2, value_type> operator-();

    };

    // 2d vector
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
                value_type omitted_val;
            };
            
            struct 
            {
                value_type ommitted_val;
                vec<2, value_type> yz;
            };
            
            
        };

        vec()
        {
            this.x = 0;
            this.y = 0;
            this.z = 0;
        }

        vec(const value_type& val)
        {
            this.x = val;
            this.y = val;
            this.z = val;
        }

        vec(const std::initializer_list<value_type> args)
        {
            assert(args.size() <= 3);
            data = args;
        }

        vec(const value_type& x, const value_type& y, const value_type& z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        vec(const vec<2, value_type>& vec, const value_type& z)
        {
            this.x = vec.x;
            this.y = vec.y;
            this.z = z;
        }

        vec(const value_type& x, const vec<2, value_type>& vec)
        {
            this.x = x;
            this.y = vec.x;
            this.z = vec.y;
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
                vec<2,value_type> xy;
                value_type omitted_val;
                value_type omitted_val;
            };

            struct
            {
                value_type omitted_val;
                vec<2, value_type> yz;
                value_type omitted_val;
            };

            struct
            {
                value_type omitted_val;
                value_type omitted_val;
                vec<2, value_type> zw;
            };

            struct
            {
                vec<3, value_type> xyz;
                value_type omitted_val;
            };

            struct
            {
                value_type omitted_val;
                vec<3, value_type> yzw;
            };

        };

        vec()
        {
            this.x = 0;
            this.y = 0;
            this.z = 0;
            this.w = 0;
        }

        vec(const value_type& val)
        {
            this.x = val;
            this.y = val;
            this.z = val;
            this.w = val;
        }

        vec(const std::initializer_list<value_type> args)
        {
            assert(args.size() <= 4);
            data = args;
        }

        vec(const value_type& x, const value_type& y, const value_type& z, const value_type& w)
        {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
        }

        vec(const vec<2, value_type>& xy, const vec<2, value_type>& zw)
        {
            this.x = xy.x;
            this.y = xy.y;
            this.z = zw.z;
            this.w = zw.w;
        }

        vec(const vec<3, value_type>& xyz, const value_type& w)
        {
            this.x = xyz.x;
            this.y = xyz.y;
            this.z = xyz.z;
            this.w = w;
        }

        value_type& operator() (const size_t idx)
        {
            assert(idx >= 0 && idx < 4);
            return data[idx];
        }

        vec<4, T> operator-();
    };

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

    using ivec2 = vec<2, ui32>;
    using ivec3 = vec<3, ui32>;
    using ivec4 = vec<4, ui32>;

    using i64vec2 = vec<2, ui64>;
    using i64vec3 = vec<2, ui64>;
    using i64vec4 = vec<2, ui64>;

    using ui16vec2 = vec<2, ui16>;
    using ui16vec3 = vec<3, ui16>;
    using ui16vec4 = vec<4, ui16>;

    using uivec2 = vec<2, ui32>;
    using uivec3 = vec<3, ui32>;
    using uivec4 = vec<4, ui32>;

    using ui64vec2 = vec<2, ui64>;
    using ui64vec3 = vec<2, ui64>;
    using ui64vec4 = vec<2, ui64>;

// -------------------- NEGATION FUNCTIONS --------------------- //
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

    template <typename T>
    inline vec<2, T> vec<2, T>::operator-()
    {
        return vec<2, T>(-x, -y);
    }

    template <typename T>
    inline vec<3, T> vec<3, T>::operator-()
    {
        return vec<3, T>(-x, -y, -z);
    }

    template <typename T>
    inline vec<4, T> vec<4, T>::operator-()
    {
        return vec<4, T>(-x, -y, -z, -w);
    }

// -------------------------------------------------------------- //


// --------------------- ADITION FUNCTIONS ---------------------- //

    template <size_t n, typename T>
    inline vec<n, T> operator+(vec<n, T> lhs, T scalar)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) + scalar;
        }
    }

    template <size_t n, typename T>
    inline vec<n, T> operator+(T scalar, vec<n, T> rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = rhs(i) + scalar;
        }
        return ans;
    }

    template <size_t n, typename T>
    inline vec<n, T> operator+(vec<n, T> lhs, vec<n, T> rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) + rhs(i);
        }
        return ans;
    }

// --------------------------------------------------------------- //

// --------------------- SUBSTRACTION FUNCTIONS ------------------ //

    template <size_t n, typename T>
    inline vec<n, T> operator-(vec<n, T> lhs, T scalar)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) - scalar;
        }
    }

    template <size_t n, typename T>
    inline vec<n, T> operator-(T scalar, vec<n, T> rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = scalar - rhs(i);
        }
        return ans;
    }

    template <size_t n, typename T>
    inline vec<n, T> operator-(vec<n, T> lhs, vec<n, T> rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) - rhs(i);
        }
        return ans;
    }
    
// --------------------------------------------------------------- //

// --------------------- MULTIPLICATION FUNCTIONS ---------------- //

    template<size_t n, typename T>
    inline vec<n, T> operator*(vec<n, T> lhs, T scalar)
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
    inline vec<n, T> operator*(vec<n, T> lhs, vec<n, T> rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) * rhs(i);
        }
        return ans;
    }

// --------------------------------------------------------------- //

// ---------------------- DIVISION FUNCTIONS --------------------- //

    template <size_t n, typename T>
    inline vec<n, T> operator/(vec<n, T> lhs, T scalar)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) / scalar;
        }
        return ans;
    }

    template <size_t n, typename T>
    inline vec<n, T> operator/(T scalar, vec<n, T> rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = scalar / rhs(i);
        }
        return ans;
    }

    template <size_t n, typename T>
    inline vec<n, T> operator/(vec<n, T> lhs, vec<n, T> rhs)
    {
        vec<n, T> ans;
        for(size_t i=0; i<n; i++)
        {
            ans(i) = lhs(i) / rhs(i);
        }
        return ans;
    }
// --------------------------------------------------------------- //

}


#endif __MATH_VECTOR__