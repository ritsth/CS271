#include "Graph.h"
#include <iostream>
#include <stdexcept>

// Default constructor
Graph::Graph(void) : V(10), E(0), adjMatrix(10, std::vector<int>(10, -1)) {}

// Graph with the specified number of vertices and edges
Graph::Graph(int vertices, int edges) {
    if (vertices < 0 || edges < 0)
        throw std::invalid_argument("Number of vertices and edges must be nonnegative.");
    this->V = vertices;
    this->E = edges;        // this part trips me a bit (?), since how do we know which edge is which 
                            // and how to represent it in the matrix    
    // adjMatrix = std::vector<std::vector<int>>(V, std::vector<int>(V, -1));
}




// Destructor





bool Graph::isEdge(int v1, int v2) {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 > V) 
        throw std::invalid_argument("Invalid vertex number.");
    return adjMatrix[v1][v2] != -1;
}

int Graph::getWeight(int v1, int v2) {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 > V)
        throw std::invalid_argument("Invalid vertex number.");
    if (adjMatrix[v1][v2] == -1) 
        throw std::runtime_error("Edge does not exist.");
    return adjMatrix[v1][v2];
}

void Graph::insertEdge(int v1, int v2, int w) {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0)
        throw std::invalid_argument("Invalid edge parameters.");
    if (adjMatrix[v1][v2] == -1)
        E++;
    adjMatrix[v1][v2] = w;
}


