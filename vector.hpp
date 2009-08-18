#ifndef vector_h__
#define vector_h__

#include <iostream>
#include <cassert>

namespace aks
{
    namespace AMR
    {
        template<typename T, unsigned int N>
        class Vector
        {
        public:
            Vector( const T& a = T() )
            {
                for (unsigned int i = 0; i<N; ++i)
                    component[i] = a;
            } //Ctor

            Vector(const Vector<T,N>& v)
            {
                for(unsigned int i = 0; i<N; ++i)
                    component[i] = v.component[i];
            } // copy constructor

            const Vector<T,N>& operator=( const Vector<T,N>& v )
            {
                if(this != &v)
                    for(unsigned int i=0;i<N; ++i)
                        component[i] = v.component[i];
                return *this;
            } // assignment operator

            const Vector<T,N>& operator=( const T& a )
            {
                for(unsigned int i=0; i<N; ++i)
                    component[i] = a;
                return *this;
            } // assignment operator with a scalar argument

            const Vector<T,N>& operator+=(const Vector<T,N>&v)
            {
                for(unsigned int i=0;i<N; ++i)
                    component[i] += v[i];
                return *this;
            } // adding a vector to the current vector

            const Vector<T,N>& operator-=(const Vector<T,N>&v)
            {
                for(unsigned int i=0;i<N; ++i)
                    component[i] -= v[i];
                return *this;
            } // subract a vector from the current vector

            const Vector<T,N>& operator*=(const T&v)
            {
                for(unsigned int i=0;i<N; ++i)
                    component[i] *= v;
                return *this;
            } // vector into scalar

            const Vector<T,N>& operator/=(const T&v)
            {
                for(unsigned int i=0;i<N; ++i)
                    component[i] /= v;
                return *this;
            } // vector into scalar

            bool operator==(const Vector<T,N>& v) const 
            {
                for( unsigned int i = 0; i < N; ++i )
                   if( component[i] != v[i] )
                       return false;
                return true;
            }

            bool operator!=(const Vector<T,N>& v) const 
            {
                return !(*this == v);
            }


            virtual ~Vector(){ } //Dtor

            virtual const T& operator[](unsigned int i) const
            {
                assert(N>i);
                return component[i];
            } //read ith component

            T& get( unsigned int i )
            {
                return (*this)(i);
            }

            void set(unsigned int i,const T& a)
            {
                assert(N>i);
                component[i] = a;
            } // change ith component

            T& operator()(unsigned int i)
            {
                assert(N>i);
                return component[i];
            } // change ith component

            T& x() { assert(N>0); return component[0]; }
            T& y() { assert(N>1); return component[1]; }
            T& z() { assert(N>2); return component[2]; }
            T& t() { assert(N>3); return component[3]; }

            const T& x() const { assert(N>0); return component[0]; }
            const T& y() const { assert(N>1); return component[1]; }
            const T& z() const { assert(N>2); return component[2]; }
            const T& t() const { assert(N>3); return component[3]; }

            T& r() { assert(N>0); return component[0]; }
            T& g() { assert(N>1); return component[1]; }
            T& b() { assert(N>2); return component[2]; }
            T& a() { assert(N>3); return component[3]; }

            const T& r() const { assert(N>0); return component[0]; }
            const T& g() const { assert(N>1); return component[1]; }
            const T& b() const { assert(N>2); return component[2]; }
            const T& a() const { assert(N>3); return component[3]; }

            const Vector<T,2> xy()
            {
                Vector<T,2> temp;
                temp.x() = x();
                temp.y() = y();
                return temp;
            }

            const Vector<T,2> xz()
            {
                Vector<T,2> temp;
                temp.x() = x();
                temp.y() = z();
                return temp;
            }

            const Vector<T,2> xt()
            {
                Vector<T,2> temp;
                temp.x() = x();
                temp.y() = t();
                return temp;
            }

            const Vector<T,2> yz()
            {
                Vector<T,2> temp;
                temp.x() = y();
                temp.y() = z();
                return temp;
            }

            const Vector<T,2> yt()
            {
                Vector<T,2> temp;
                temp.x() = y();
                temp.y() = t();
                return temp;
            }

            const Vector<T,2> zt()
            {
                Vector<T,2> temp;
                temp.x() = z();
                temp.y() = t();
                return temp;
            }

            const Vector<T,2> rg()
            {
                Vector<T,2> temp;
                temp.r() = r();
                temp.g() = g();
                return temp;
            }

            const Vector<T,2> rb()
            {
                Vector<T,2> temp;
                temp.r() = r();
                temp.g() = b();
                return temp;
            }

            const Vector<T,2> ra()
            {
                Vector<T,2> temp;
                temp.r() = r();
                temp.g() = a();
                return temp;
            }

            const Vector<T,2> gb()
            {
                Vector<T,2> temp;
                temp.r() = g();
                temp.g() = b();
                return temp;
            }

            const Vector<T,2> ga()
            {
                Vector<T,2> temp;
                temp.r() = g();
                temp.g() = a();
                return temp;
            }

            const Vector<T,2> ba()
            {
                Vector<T,2> temp;
                temp.r() = b();
                temp.g() = a();
                return temp;
            }

            const Vector<T,3> xyz()
            {
                Vector<T,3> temp;
                temp.x() = x();
                temp.y() = y();
                temp.z() = z();
                return temp;
            }

            const Vector<T,3> xzt()
            {
                Vector<T,3> temp;
                temp.x() = x();
                temp.y() = z();
                temp.z() = t();
                return temp;
            }

            const Vector<T,3> yzt()
            {
                Vector<T,3> temp;
                temp.x() = y();
                temp.y() = z();
                temp.z() = t();
                return temp;
            }

            const Vector<T,3> rgb()
            {
                Vector<T,3> temp;
                temp.r() = r();
                temp.g() = g();
                temp.b() = b();
                return temp;
            }

            const Vector<T,3> gba()
            {
                Vector<T,3> temp;
                temp.g() = g();
                temp.b() = b();
                temp.a() = a();
                return temp;
            }

            const Vector<T,3> rba()
            {
                Vector<T,3> temp;
                temp.r() = r();
                temp.b() = b();
                temp.a() = a();
                return temp;
            }

            const Vector<T,4> xyzt()
            {
                Vector<T,3> temp;
                temp.x() = x();
                temp.y() = y();
                temp.z() = z();
                temp.t() = t();
                return temp;
            }

            const Vector<T,4> rgba()
            {
                Vector<T,3> temp;
                temp.r() = r();
                temp.g() = g();
                temp.b() = b();
                temp.a() = a();
                return temp;
            }



        protected:

        private:
            T component[N];
        };

        template<typename T, unsigned int N>
        const Vector<T,N> operator+(const Vector<T,N>&u, const Vector<T,N>&v)
        {
            return Vector<T,N>(u) += v;
        } // vector plus vector

        template<typename T, unsigned int N>
        const Vector<T,N> operator-(const Vector<T,N>&u, const Vector<T,N>&v)
        {
            return Vector<T,N>(u) -= v;
        } // vector plus vector


        template<typename T, unsigned int N>
        const Vector<T,N> operator*(const Vector<T,N>&u, const T&v)
        {
            return Vector<T,N>(u) *= v;
        } // vector * scalar

        template<typename T, unsigned int N>
        const Vector<T,N> operator*(const T&v, const Vector<T,N>&u )
        {
            return Vector<T,N>(u) *= v;
        } // scalar * vector

        template<typename T, unsigned int N>
        const Vector<T,N> operator/(const Vector<T,N>&u, const T&v)
        {
            return Vector<T,N>(u) /= v;
        } // vector / scalar

        template<typename T, unsigned int N>
        const Vector<T,N>& operator+(const Vector<T,N>&u)
        {
            return u;
        } // positive of a vector

        template<typename T, unsigned int N>
        const Vector<T,N> operator-(const Vector<T,N>&u)
        {
            return Vector<T,N>(u) *= -1;
        } // negative of a vector

        template<typename T, unsigned int N>
        const T operator*(const Vector<T,N>&u, const Vector<T,N>&v)
        {
            T sum = 0;
            for(unsigned int i = 0; i<N; ++i)
                sum += u[i] * +v[i];
            return sum;
        } // vector times vector (inner product)

        template<typename T, unsigned int N>
        const T dot( const Vector<T,N>&u, const Vector<T,N>&v )
        {
            return u*v;
        } //Dot product

        template<typename T, unsigned int N>
        const T squaredNorm( const Vector<T,N>&u )
        {
            return u*u;
        } // sum of squares

        template<typename T, unsigned int N>
        void print(const Vector<T,N>&v)
        {
            std::cout << "( ";
            for(unsigned int i = 0; i < N; ++i)
            {
                std::cout << "v[" << i << "] = " << v[i] << " " ;
            }
            std::cout << ")\n";
        } // printing a vector

        typedef Vector<double,2> Point;
        typedef Vector<double,3> Point3D;
        typedef Vector<double,3> Vertex;
        typedef Vector<double,4> Vector4D;
    }
}


#endif // vector_h__
