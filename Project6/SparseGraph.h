#ifndef SPARSEGRAPH_H
#define SPARSEGRAPH_H

#include "Graph.h"
#include <map>
#include <vector>

// Derived class for sparse graph representation
class SparseGraph : public Graph
{
private:
    vector<map<int,int>> adjList;

public:
    // Primary Methods
                SparseGraph  ( void );                       // Default constructor         
                SparseGraph  ( const SparseGraph& mygraph );  // Copy constructor
                SparseGraph  ( int V, int E );               // Constructor that specifies V and E
                ~SparseGraph ( void );                       // Destructor
    
    // Functional Methods
    SparseGraph&   operator=	( const SparseGraph &mySparseGraph );

    void        insertEdge  ( int v1, int v2, int w);
    bool        isEdge      ( int v1, int v2 ) const;
    int         getWeight   ( int v1, int v2 ) const; 

    // Supporting function for operator<<
    void        print       ( ostream& os ) const; 
};

#endif  // SPARSEGRAPH_H
