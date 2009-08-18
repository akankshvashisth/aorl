#ifndef BoxHandler_h__
#define BoxHandler_h__

#include "box.hpp"
#include "transformations.hpp"
#include <vector>
#include <algorithm>

namespace aks
{
    namespace AMR
    {
        //TODO: Needs to be cleaner and better :P Can be MUCH better.
        const Vertex& FindMinimumBottomCorner( const Box& aBox ) 
        {
            Vertex v = aBox(0);
            for( unsigned i(0); i < 8; ++i )
                for( unsigned j(0); j < 3; ++j )
                {
                    if( v(j) > aBox(i)[j] )
                        v(j) = aBox(i)[j];
                }
                for( unsigned i(0); i < 8; ++i )
                {
                    if( v == aBox(i) )
                        return aBox(i);
                }
                return aBox(0);
        }

        class VertexPairDisplacementHelper
        {
        public:
            Vertex v;
            double mDisplacment;
        };

        bool operator< (const VertexPairDisplacementHelper& cC1, const VertexPairDisplacementHelper& cC2)
        {
            return cC1.mDisplacment < cC2.mDisplacment;
        }

        //class VertexDisplacementComparer
        //{
        //public:
        //    Vertex v[2];
        //};

        //bool operator< (const VertexDisplacementComparer& v, const VertexDisplacementComparer& u)
        //{
        //    
        //}



        void PartitionBox( Box& aBox )
        {
            Vertex v = FindMinimumBottomCorner(aBox);

            //Move box so that one vertex is at 0,0,0;
            aBox.Translate(-v[0], -v[1], -v[2]);

            std::vector<Vertex> midPts;
            Vertex temp;
            bool bPresent;

            for( unsigned i(0); i<8; ++i )
            {
                for( unsigned j(0); j<8; ++j )
                {
                    if( i != j)
                    {
                        bPresent = false;
                        temp = FindMidPoint( aBox(i), aBox(j) );
                        for( std::vector<Vertex>::const_iterator i = midPts.begin(); 
                            i != midPts.end(); ++i )
                        {
                            if( (*i) == temp )
                                bPresent = true;
                        }
                        if( !bPresent )
                            midPts.push_back(temp);
                    }
                }
            }

            for( unsigned i(0); i < 8; ++i )
            {
                std::vector<VertexPairDisplacementHelper> s;
                for( unsigned j(0); j < midPts.size(); ++j )
                {
                    VertexPairDisplacementHelper vpdh;
                    vpdh.v = midPts[j];
                    vpdh.mDisplacment = Displacement( aBox(i), midPts[j] );
                    s.push_back( vpdh );
                }

                std::sort( s.begin(), s.end() );
                Box b;
                b(0) = aBox(i);

                for( unsigned j(0); j < 7; ++j )
                    b(j+1) = s[j].v;

                aBox.GetPartitions().push_back(b);
            }

            aBox.Translate( v[0], v[1], v[2] );
            for (unsigned i(0); i < aBox.GetPartitions().size(); ++i)
                aBox.GetPartitions()[i].Translate(v[0], v[1], v[2]);

            
            for(unsigned i(0); i<8; ++i)
            {
                double d = Displacement( aBox(i), aBox(0) );
                for (unsigned j(0); j<8; ++j)
                {
                    if(i != j)
                    {
                        if( Displacement(aBox(i), aBox(j)) < d )
                        {
                            Vertex temp = aBox(i);
                            aBox(i) = aBox(j);
                            aBox(j) = temp;
                        }
                    }
                }
            }

            //for (unsigned i(0); i < aBox.GetPartitions().size(); ++i)
            //{
            //    for( unsigned j(0); j < 8; ++j )
            //    {
            //        print( aBox.GetPartitions().at(i).at(j) );
            //    }
            //    std::cout << "\n\n";
            //}
        }
    }
}


#endif // BoxHandler_h__