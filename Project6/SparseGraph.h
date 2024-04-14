//===============================
// SparseGraph.h
// Name: Ritika, Max, Uyen
// Date: 23 Feb 2024
// This file contains declaration of derived SparseGraph class.
//===============================
#ifndef SPARSEGRAPH_H
#define SPARSEGRAPH_H

#include "Graph.h"
#include <map>
#include <vector>
using namespace std;

// Derived class for sparse graph representation
class SparseGraph : public Graph
{
private:
    vector<map<int,int>> adjList;       // Adjacent List for SparseGraph representation

public:
    // Primary Methods
                  SparseGraph  ( void );                              // Default constructor         
                  SparseGraph  ( const SparseGraph& mygraph );        // Copy constructor
                  SparseGraph  ( int V, int E );                      // Constructor that specifies V and E
                  ~SparseGraph ( void );                              // Destructor
    SparseGraph&  operator=	   ( const SparseGraph &mySparseGraph );  // Operator= override

    // Functional Methods
    void        insertEdge  ( int v1, int v2, int w );                // Insert a new edge to a graph, override if already existed
    bool        isEdge      ( int v1, int v2 ) const;                 // Check if there is an edge
    int         getWeight   ( int v1, int v2 ) const;                 // Return the weight of an edge

    // BFS based algorithms
    void        BFS              ( int source );
    void        printBFSTable    ( int source );
    void        printBFSPath     ( int s, int d );
    void        printMostDistant ( int s );
    bool        isConnected      ( void );

    // DFS based algorithm
    void        DFS                      ( void ); 
    void        DFS_Visit                ( int v, int &clock );
    void        printDFSTable            ( void );
    void        printTopologicalSort     ( void );
    void        printDFSParenthesization ( void );
    void        classifyDFSEdges         ( void );
    // void        indexSort                ( int a[] );
};

#endif  // SPARSEGRAPH_H
