#ifndef transformations_h__
#define transformations_h__

#include "vector.hpp"
#include <cassert>
#include <cmath>
#include <vector>
#include <math.h>

namespace aks
{
    namespace AMR
    {
        enum Axis { AXIS_X = 0, AXIS_Y = 1, AXIS_Z = 2 };

        void Translate( Vertex& v, double x, double y, double z )
        {
            v.x() += x;
            v.y() += y;
            v.z() += z;
        }

        void Scale( Vertex& v, double s )
        {
            v.x() *= s;
            v.y() *= s;
            v.z() *= s;
        }

        void Rotate( Vertex& v, const double angle, const Axis axis )
        {
            const double x = v.x();
            const double y = v.y();
            const double z = v.z();
            const double sine = sin(angle);
            const double cosine = cos(angle);
            switch(axis)
            {
            case AXIS_X:
                v.z() = (z * cosine) - (y * sine);
                v.y() = (z * sine) + (y * cosine);
                break;
            case AXIS_Y:
                v.x() = (x * cosine) - (z * sine);
                v.z() = (x * sine) + (z * cosine);
                break;
            case AXIS_Z:
                v.x() = (x * cosine) - (y * sine);
                v.y() = (x * sine) + (y * cosine);
                break;
            default:
                assert(0);
            }
        }

        const Vertex FindMidPoint( const Vertex& u, const Vertex& v )
        {
            Vertex toReturn;
            toReturn.x() = ( (u.x()+v.x())/2.0 );
            toReturn.y() = ( (u.y()+v.y())/2.0 );
            toReturn.z() = ( (u.z()+v.z())/2.0 );
            return toReturn;
        }

        const double Displacement( const Vertex& u, const Vertex& v )
        {
            double x2 = (u[0] - v[0])*(u[0] - v[0]);
            double y2 = (u[1] - v[1])*(u[1] - v[1]);
            double z2 = (u[2] - v[2])*(u[2] - v[2]);

            return sqrt( x2 + y2 + z2 );
        }
    }
}


#endif // transformations_h__
