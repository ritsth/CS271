#include "Graph.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Graph::Graph(void) {
    V = DEFAULT_VERTICES_NUM;
    E = 0;
}

Graph::Graph(int vertices, int edges) {
    if (vertices < 0 || edges < 0) 
        throw std::invalid_argument("The number of vertices and edges cannot be negative.");
    V = vertices;
    E = edges;        
}

Graph::Graph(const Graph& other) {
    V = other.V;
    E = other.E;
}

Graph::~Graph(void) {
    V = 0;
    E = 0;    
}

Graph& Graph::operator=(const Graph& other) {
    V = other.V;
    E = other.E;
    return *this;
}



