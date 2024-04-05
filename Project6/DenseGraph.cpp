#include "DenseGraph.h"
#include <stdexcept>
using namespace std;

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

int DenseGraph::getWeight(int v1, int v2) const {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V)
        throw std::invalid_argument("Invalid vertex number.");
    if (adjMatrix[v1][v2] == -1) 
        throw std::runtime_error("Edge does not exist.");
    return adjMatrix[v1][v2];
}

#ifdef DIRECTED_GRAPH
void DenseGraph::insertEdge(int v1, int v2, int w = 1) {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0)
        throw std::invalid_argument("Invalid edge parameters.");
    if (adjMatrix[v1][v2] == -1) 
        E++;
    adjMatrix[v1][v2] = w;
}
#endif 

#ifndef DIRECTED_GRAPH
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