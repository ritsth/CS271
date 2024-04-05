#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H

#include "Graph.h"
#include <vector>
using namespace std;

// Derived class for dense graph representation
class DenseGraph : public Graph 
{
private:
    std::vector<std::vector<int>>   adjMatrix;

public:
    // Primary Methods
                DenseGraph  ( void );                       // Default constructor         
                DenseGraph  ( const DenseGraph& other );    // Copy constructor
                DenseGraph  ( int vertices, int edges );               // Constructor that specifies V and E
                ~DenseGraph ( void );                       // Destructor
    DenseGraph& operator=   ( const DenseGraph& other );    // Operator= override    

    // Functional Methods
    void        insertEdge  ( int v1, int v2, int w );
    bool        isEdge      ( int v1, int v2 ) const;
    int         getWeight   ( int v1, int v2 ) const; 

    // Supporting function for operator<<
    void        print       ( ostream& os ) const; 
};

#endif  // DENSEGRAPH_H
