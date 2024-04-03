#include "DenseGraph.h"
#include <stdexcept>
using namespace std;

// Default constructor
DenseGraph::DenseGraph(void) {

} 

// Copy constructor


// Constructor with specifies V and E

// Destructor

// Assignment operator





bool DenseGraph::isEdge(int v1, int v2) const {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 > V) 
        throw std::invalid_argument("Invalid vertex number.");
    return adjMatrix[v1][v2] != -1;
}

int DenseGraph::getWeight(int v1, int v2) const {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 > V)
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