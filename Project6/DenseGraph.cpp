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
// Default constructor
DenseGraph::DenseGraph(void) : Graph(DEFAULT_VERTICES_NUM, 0) {
    adjMatrix.resize(V, vector<int>(V, -1));        // Initialize adjacency matrix with -1
} 

// Copy constructor
DenseGraph::DenseGraph(const DenseGraph& other) : Graph(other) {
    adjMatrix = other.adjMatrix;
}

// Constructor with specifies V and E
DenseGraph::DenseGraph(int vertices, int edges) : Graph(vertices, 0) {
    adjMatrix.resize(V, vector<int>(V, -1));        // Initialize adjacency matrix with -1
}

// Destructor
DenseGraph::~DenseGraph(void) {
    V = E = 0;
}

// Assignment operator
DenseGraph& DenseGraph::operator=(const DenseGraph& other) {
    if (this != &other) {
        Graph::operator=(other);        // Call base class assignment operator to copy V and E
        adjMatrix = other.adjMatrix;    // Deep copy the adjacent matrix
    }
    return *this;
}

bool DenseGraph::isEdge(int v1, int v2) const {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V) 
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
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V)
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

void DenseGraph::print(ostream& os) const {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adjMatrix[i][j] != -1) {
                os << i << " " << j << " " << adjMatrix[i][j] << endl;
            }
        }
    }
}