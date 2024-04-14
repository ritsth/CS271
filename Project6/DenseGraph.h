//===============================
// DenseGraph.h
// Name: Ritika, Max, Uyen
// Date: 23 Feb 2024
// This file contains declaration of derived DenseGraph class.
//===============================
#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H

#include "Graph.h"
#include <vector>
using namespace std;

// Derived class for dense graph representation
class DenseGraph : public Graph 
{
private:
    vector<vector<int>>   adjMatrix;        // Adjacent Matrix for DenseGraph representation

public:
    // Primary Methods
                DenseGraph  ( void );                       // Default constructor         
                DenseGraph  ( const DenseGraph& other );    // Copy constructor
                DenseGraph  ( int vertices, int edges );    // Constructor that specifies V and E
                ~DenseGraph ( void );                       // Destructor
    DenseGraph& operator=   ( const DenseGraph& other );    // Operator= override    

    // Functional Methods
    void        insertEdge  ( int v1, int v2, int w );      // Insert a new edge to a graph, override if already existed
    bool        isEdge      ( int v1, int v2 ) const;       // Check if there is an edge
    int         getWeight   ( int v1, int v2 ) const;       // Return the weight of an edge

    // BFS based algorithms
    void        BFS              ( int source );
    void        printBFSTable    ( int source );
    void        printBFSPath     ( int s, int d );
    void        printMostDistant ( int s );
    bool        isConnected      ( void );

    // DFS based algorithm
    void        DFS                      ( void ); 
    void        DFS_Visit                ( int v, int &clock );
    // void        printDFSTable            ( void );
    // void        printTopologicalSort     ( void );
    void        printDFSParenthesization ( void );
    void        classifyDFSEdges         ( void );
    
};

#endif  // DENSEGRAPH_H
