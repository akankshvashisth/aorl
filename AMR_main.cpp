#include "vector.hpp"
#include "transformations.hpp"
#include "boxHandler.hpp"

#include <iostream>
#include <fstream>

#define NOMINMAX
#include <Eigen/Core>
#include <Eigen/Array>
#include <Eigen/LU>

using namespace aks;

int main( void )
{
    //using namespace aks::AMR;
    //Vertex v, u;
    ////v.set(0,1);v.set(1,1);v.set(2,1);
    //v = 1;
    //print(v);
    //u = 2;
    //print(u);
    //print( FindMidPoint(v, u) );
    
    AMR::Vertex v[8];
    v[0](0) = -1; v[0](1) = -1; v[0](2) = -1;
    v[1](0) =  1; v[1](1) = -1; v[1](2) = -1;
    v[2](0) = -1; v[2](1) =  1; v[2](2) = -1;
    v[3](0) =  1; v[3](1) =  1; v[3](2) = -1;
    v[4](0) = -1; v[4](1) = -1; v[4](2) =  1;
    v[5](0) =  1; v[5](1) = -1; v[5](2) =  1;
    v[6](0) = -1; v[6](1) =  1; v[6](2) =  1;
    v[7](0) =  1; v[7](1) =  1; v[7](2) =  1;

    for(unsigned i(0); i<8; ++i)
        AMR::Scale( v[i], 20 );

    AMR::Box b;
    for(unsigned i(0); i < 8; ++i)
        b(i) = v[i];

    //AMR::print( AMR::FindMinimumBottomCorner(b) );

    PartitionBox( b );
    PartitionBox( b.GetPartitionAt(0) );
    PartitionBox( b.GetPartitionAt(0).GetPartitionAt(0) );
    PartitionBox( b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0) );
    PartitionBox( b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0) );


    std::ofstream myfile;
    myfile.open ("rossler.txt");

    Eigen::Matrix<double,3,1> m;
    for( unsigned i(0); i<8; ++i )
    {
        m(0) = b.at(i).x();
        m(1) = b.at(i).y();
        m(2) = b.at(i).z();
        myfile << m.transpose();
        myfile << "\n";
    }

    for (unsigned i(0); i<b.GetPartitions().size(); ++i)
    {
        for( unsigned j(0); j<8; ++j )
        {
            m(0) = b.GetPartitionAt(i).at(j).x();
            m(1) = b.GetPartitionAt(i).at(j).y();
            m(2) = b.GetPartitionAt(i).at(j).z();
            myfile << m.transpose();
            myfile << "\n";
        }
    }

    for( unsigned i(0); i<b.GetPartitionAt(0).GetPartitions().size(); ++i )
    {
        for( unsigned j(0); j<8; ++j )
        {
            m(0) = b.GetPartitionAt(0).GetPartitionAt(i).at(j).x();
            m(1) = b.GetPartitionAt(0).GetPartitionAt(i).at(j).y();
            m(2) = b.GetPartitionAt(0).GetPartitionAt(i).at(j).z();
            myfile << m.transpose();
            myfile << "\n";
        }
    }

    for( unsigned i(0); i<b.GetPartitionAt(0).GetPartitionAt(0).GetPartitions().size(); ++i )
    {
        for( unsigned j(0); j<8; ++j )
        {
            m(0) = b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(i).at(j).x();
            m(1) = b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(i).at(j).y();
            m(2) = b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(i).at(j).z();
            myfile << m.transpose();
            myfile << "\n";
        }
    }

    for( unsigned i(0); i<b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitions().size(); ++i )
    {
        for( unsigned j(0); j<8; ++j )
        {
            m(0) = b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(i).at(j).x();
            m(1) = b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(i).at(j).y();
            m(2) = b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(i).at(j).z();
            myfile << m.transpose();
            myfile << "\n";
        }
    }

    for( unsigned i(0); i<b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitions().size(); ++i )
    {
        for( unsigned j(0); j<8; ++j )
        {
            m(0) = b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(i).at(j).x();
            m(1) = b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(i).at(j).y();
            m(2) = b.GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(0).GetPartitionAt(i).at(j).z();
            myfile << m.transpose();
            myfile << "\n";
        }
    }

    myfile.close();
    
    return 0;
}