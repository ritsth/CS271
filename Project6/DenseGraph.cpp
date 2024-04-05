#include "DenseGraph.h"
#include <vector>
#include <stdexcept>

using namespace std;

//==============================================
// DenseGraph(void)
// Default Contructor for DenseGraph class
// INPUT: none
// RETURN: none
//==============================================
DenseGraph::DenseGraph(void) {
    V = 0;
    E = 0;
    vector<vector<int>>   adjMatrix;
} 

//==============================================
// DenseGraph(const DenseGraph &myDenseGraph)
// Copy Contructor for DenseGraph class
// Create a new DenseGraph from an existing one.
// INPUT: const DenseGraph &myDenseGraph
// RETURN: none
//==============================================
DenseGraph::DenseGraph  ( const DenseGraph& mygraph ){

}

//==============================================
// DenseGraph(void)
// Parameterized Contructor for DenseGraph class
// INPUT: none
// RETURN: none
//==============================================
// Constructor with specifies V and E
DenseGraph::DenseGraph  ( int V, int E ){
    this->V = V;
    this->E = E;
    vector<vector<int>>  adjMatrix;
}

//==============================================
// ~DenseGraph(void)
// Destructor for DenseGraph class
// Cleans up the memory of the DenseGraph.
// INPUT: none
// RETURN: none
//==============================================
DenseGraph::~DenseGraph ( void ){
    //Clear()

}


//==============================================
// operator= ( const DenseGraph &myDenseGraph )
// Assignment operator.
// Assign DenseGraph to the class
// INPUT: const DenseGraph &myDenseGraph 
// RETURN: DenseGraph
//==============================================
DenseGraph& DenseGraph::operator=	    ( const DenseGraph &myDenseGraph ){

}



//==============================================
// isEdge ( int v1, int v2 )
// Returns true if there is a edge from the given vertices.
// INPUT: int v,  int v2 
// RETURN: bool
//==============================================
bool DenseGraph::isEdge(int v1, int v2) const {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 > V) 
        throw std::invalid_argument("Invalid vertex number.");
    return adjMatrix[v1][v2] != -1;
}

//==============================================
// getWeight(int v1, int v2)
// Returns the weight of the edge from the given vertices.
// INPUT: int v,  int v2 
// RETURN: int
//==============================================
int DenseGraph::getWeight(int v1, int v2) const {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 > V)
        throw std::invalid_argument("Invalid vertex number.");
    if (adjMatrix[v1][v2] == -1) 
        throw std::runtime_error("Edge does not exist.");
    return adjMatrix[v1][v2];
}

#ifdef UNDIRECTED_GRAPH
//==============================================
// insertEdge(int v1, int v2, int w = 1)
// Inserts a edge between given vertices for a undirected graph
// INPUT: int v1, int v2, int w = 1
// RETURN: void
//==============================================
void DenseGraph::insertEdge(int v1, int v2, int w = 1) {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0)
        throw std::invalid_argument("Invalid edge parameters.");
    if (adjMatrix[v1][v2] == -1) 
        E++;
    adjMatrix[v1][v2] = w;
}
#endif 

#ifndef DIRECTED_GRAPH
//==============================================
// insertEdge(int v1, int v2, int w = 1)
// Inserts a edge between given vertices for a directed graph
// INPUT: int v1, int v2, int w = 1
// RETURN: void
//==============================================
void DenseGraph::insertEdge(int v1, int v2, int w = 1) {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0) 
        throw std::invalid_argument("Invalid edge parameters.");
    if (adjMatrix[v1][v2] == -1) 
        E++;
    adjMatrix[v1][v2] = adjMatrix[v2][v1] = w;
}
#endif