//===============================
// DenseGraph.cpp
// Name: Ritika, Max, Uyen
// Date: 23 Feb 2024
// This file contains implementation of derived DenseGraph class.
//===============================
#include "DenseGraph.h"
#include <iomanip>
#include <queue>
#include <functional>
#include <vector>
#include <stdexcept>
using namespace std;

//==============================================
// DenseGraph(void)
// Default Contructor for DenseGraph class
// INPUT: none
// RETURN: none
//==============================================
DenseGraph::DenseGraph(void) : Graph(DEFAULT_VERTICES_NUM, 0) {
    adjMatrix.resize(V, vector<int>(V, -1));        // Initialize adjacency matrix of size (V x V) with -1
} 

//==============================================
// DenseGraph(const DenseGraph &myDenseGraph)
// Copy Contructor for DenseGraph class
// Create a new DenseGraph from an existing one.
// INPUT: const DenseGraph &myDenseGraph
// RETURN: none
//==============================================
DenseGraph::DenseGraph(const DenseGraph& other) : Graph(other) {
    adjMatrix = other.adjMatrix;                     // Deep copy the adjMatrix of the given DenseGraph
}

//==============================================
// DenseGraph(int vertices, int edges)
// Parameterized Contructor for DenseGraph class
// INPUT: int vertices, int edges
// RETURN: none
//==============================================
DenseGraph::DenseGraph(int vertices, int edges) : Graph(vertices,0) {
    adjMatrix.resize(V, vector<int>(V, -1));        // Initialize adjacency matrix of size (vertices x vertices) with -1
}

//==============================================
// ~DenseGraph(void)
// Destructor for DenseGraph class
// Cleans up the memory of the DenseGraph.
// INPUT: none
// RETURN: none
//==============================================
DenseGraph::~DenseGraph(void) {
    V = E = 0;                          // Reset the V and E
    adjMatrix.clear();                  // Clear the matrix
}

//==============================================
// operator= ( const DenseGraph &myDenseGraph )
// Assignment operator.
// Assign DenseGraph to the class
// INPUT: const DenseGraph &myDenseGraph 
// RETURN: DenseGraph
//==============================================
DenseGraph& DenseGraph::operator=(const DenseGraph& other) {
    // Check for self-assignment
    if (this != &other) {
        // If not, first clear the given DenseGraph object
        V = E = 0;
        adjMatrix.clear();
        // Then, deep copy the variables from the given DenseGraph object
        Graph::operator=(other);        // Call base class assignment operator to copy V and E
        adjMatrix = other.adjMatrix;    // Deep copy the adjacent matrix
    }
    // Return a reference to the current object
    return *this;
}

//==============================================
// isEdge ( int v1, int v2 )
// Returns true if there is a edge from the given vertices.
// INPUT: int v,  int v2 
// RETURN: bool
//==============================================
bool DenseGraph::isEdge(int v1, int v2) const {
    // First, check for valid parameter (0 <= v1, v2 < V)
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V) 
        throw std::invalid_argument("Invalid vertex number.");
    // Return the 1 if the weight at given indexes of the adjMatrix is not -1, else return 0
    return adjMatrix[v1][v2] != -1;
}

//==============================================
// getWeight(int v1, int v2)
// Returns the weight of the edge from the given vertices.
// INPUT: int v,  int v2 
// RETURN: int
//==============================================
int DenseGraph::getWeight(int v1, int v2) const {
    // First, check for valid parameter (0 <= v1, v2 < V)
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V)
        throw std::invalid_argument("Invalid vertex number.");
    // Then, check if there is an edge from v1 to v2
    if (adjMatrix[v1][v2] == -1) 
        throw std::runtime_error("Edge does not exist.");
    // If yes, return the weight of that edge
    return adjMatrix[v1][v2];
}

#ifdef DIRECTED_GRAPH
//==============================================
// insertEdge(int v1, int v2, int w = 1)
// Inserts a edge between given vertices for a directed graph
// INPUT: int v1, int v2, int w = 1
// RETURN: void
//==============================================
void DenseGraph::insertEdge(int v1, int v2, int w = 1) {
    // First, check for valid parameter (0 <= v1, v2 < V && w >= 0)
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0)
        throw std::invalid_argument("Invalid edge parameters.");
    // If there is not yet an edge from v1 to v2, increase the number of edges by 1
    if (adjMatrix[v1][v2] == -1) 
        E++;
    // Set the weight of the new edge to w, if there is already an edge there, overwrite the value
    adjMatrix[v1][v2] = w;
}
#endif 

#ifndef DIRECTED_GRAPH
//==============================================
// insertEdge(int v1, int v2, int w = 1)
// Inserts a edge between given vertices for a undirected graph
// INPUT: int v1, int v2, int w = 1
// RETURN: void
//==============================================
void DenseGraph::insertEdge(int v1, int v2, int w = 1) {
    // First, check for valid parameter (0 <= v1, v2 < V && w >= 0)
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0) 
        throw std::invalid_argument("Invalid edge parameters.");
    // If there is not yet an edge from v1 to v2, increase the number of edges by 1
    if (adjMatrix[v1][v2] == -1) 
        E++;
    // Set the weight of the new edge to w, if there is already an edge there, overwrite the value
    adjMatrix[v1][v2] = adjMatrix[v2][v1] = w;
}
#endif
