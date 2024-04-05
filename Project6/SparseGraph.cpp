#include "SparseGraph.h"
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

//==============================================
// SparseGraph(void)
// Default Contructor for SparseGraph class
// INPUT: none
// RETURN: none
//==============================================
SparseGraph::SparseGraph(void) {
    V = 0;
    E = 0;
   map<int, vector<int>> adjList;
} 

//==============================================
// SparseGraph(const SparseGraph &mySparseGraph)
// Copy Contructor for SparseGraph class
// Create a new SparseGraph from an existing one.
// INPUT: const SparseGraph &mySparseGraph
// RETURN: none
//==============================================
SparseGraph::SparseGraph  ( const SparseGraph& mygraph ){

}

//==============================================
// SparseGraph(void)
// Parameterized Contructor for SparseGraph class
// INPUT: none
// RETURN: none
//==============================================
// Constructor with specifies V and E
SparseGraph::SparseGraph  ( int V, int E ){
    this->V = V;
    this->E = E;
    map<int, vector<int>> adjList;
}

//==============================================
// ~SparseGraph(void)
// Destructor for SparseGraph class
// Cleans up the memory of the SparseGraph.
// INPUT: none
// RETURN: none
//==============================================
SparseGraph::~SparseGraph ( void ){
    //Clear()
    
}


//==============================================
// operator= ( const SparseGraph &mySparseGraph )
// Assignment operator.
// Assign SparseGraph to the class
// INPUT: const SparseGraph &mySparseGraph 
// RETURN: SparseGraph
//==============================================
SparseGraph& SparseGraph::operator=	    ( const SparseGraph &mySparseGraph ){

}



//==============================================
// isEdge ( int v1, int v2 )
// Returns true if there is a edge from the given vertices.
// INPUT: int v,  int v2 
// RETURN: bool
//==============================================
bool SparseGraph::isEdge(int v1, int v2) const {
    // if (v1 < 0 || v1 >= V || v2 < 0 || v2 > V) 
    //     throw std::invalid_argument("Invalid vertex number.");
    // return adjMatrix[v1][v2] != -1;
}

//==============================================
// getWeight(int v1, int v2)
// Returns the weight of the edge from the given vertices.
// INPUT: int v,  int v2 
// RETURN: int
//==============================================
int SparseGraph::getWeight(int v1, int v2) const {
    // if (v1 < 0 || v1 >= V || v2 < 0 || v2 > V)
    //     throw std::invalid_argument("Invalid vertex number.");
    // if (adjMatrix[v1][v2] == -1) 
    //     throw std::runtime_error("Edge does not exist.");
    // return adjMatrix[v1][v2];
}

#ifdef DIRECTED_GRAPH
//==============================================
// insertEdge(int v1, int v2, int w = 1)
// Inserts a edge between given vertices for a directed graph
// INPUT: int v1, int v2, int w = 1
// RETURN: void
//==============================================
void SparseGraph::insertEdge(int v1, int v2, int w = 1) {
    // if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0)
    //     throw std::invalid_argument("Invalid edge parameters.");
    // if (adjMatrix[v1][v2] == -1) 
    //     E++;
    // adjMatrix[v1][v2] = w;
}
#endif 

#ifndef DIRECTED_GRAPH
//==============================================
// insertEdge(int v1, int v2, int w = 1)
// Inserts a edge between given vertices for a !()directed graph
// INPUT: int v1, int v2, int w = 1
// RETURN: void
//==============================================
void SparseGraph::insertEdge(int v1, int v2, int w = 1) {
    // if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0) 
    //     throw std::invalid_argument("Invalid edge parameters.");
    // if (adjMatrix[v1][v2] == -1) 
    //     E++;
    // adjMatrix[v1][v2] = adjMatrix[v2][v1] = w;
}
#endif