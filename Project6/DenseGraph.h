#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H

#include "Graph.h"
#include <vector>

// Derived class for dense graph representation
class DenseGraph : public Graph 
{
private:
    std::vector<std::vector<int>>   adjMatrix;

public:
    // Primary Methods
                DenseGraph  ( void );                       // Default constructor         
                DenseGraph  ( const DenseGraph& mygraph );  // Copy constructor
                DenseGraph  ( int V, int E );               // Constructor that specifies V and E
                ~DenseGraph ( void );                       // Destructor
    
    // Functional Methods
    void        insertEdge  ( int v1, int v2, int w );
    bool        isEdge      ( int v1, int v2 ) const;
    int         getWeight   ( int v1, int v2 ) const; 
};

#endif  // DENSEGRAPH_H
