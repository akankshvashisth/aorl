#ifndef box_h__
#define box_h__

#include "vector.hpp"
#include <vector>
#include <cassert>

namespace aks
{
    namespace AMR
    {
        class Box
        {
        public:
            Box( void ){}

            Vertex& operator()( unsigned aNum )
            {
                assert( (aNum < 8) && (aNum >= 0) );
                return mVertices[aNum];
            }

            const Vertex& operator()( unsigned aNum ) const
            {
                assert( (aNum < 8) && (aNum >= 0) );
                return mVertices[aNum];
            }

            const Vertex& at( unsigned aNum ) const
            {
                assert( (aNum < 8) && (aNum >= 0) );
                return mVertices[aNum];
            }

            std::vector<Box>& GetPartitions()
            {
                return mPartitions;
            }

            Box& GetPartitionAt( unsigned aNum )
            {
                assert( aNum < mPartitions.size() );
                return mPartitions[aNum];
            }

            void Translate( double x, double y, double z )
            {
                for( unsigned i(0); i < 8; ++i )
                {
                    mVertices[i].x() += x;
                    mVertices[i].y() += y;
                    mVertices[i].z() += z;
                }
            }

            bool IsLeaf() const
            {
                return mPartitions.empty();
            }
        protected:
        private:
            Vertex mVertices[8]; //order top clockwise from ++
            std::vector<Box> mPartitions;
            bool isLeaf;
        };
    }
}


#endif // box_h__
