#ifndef SPARSEGRAPH_H
#define SPARSEGRAPH_H

#include "Graph.h"

// Derived class for sparse graph representation
class SparseGraph : public Graph
{
private:

public:


    void        insertEdge  ( int v1, int v2, int w);
    bool        isEdge      ( int v1, int v2 ) const;
    int         getWeight   ( int v1, int v2 ) const; 
};

#endif  // SPARSEGRAPH_H
