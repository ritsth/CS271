//===============================
// Graph.cpp
// Name: Ritika, Max, Uyen
// Date: 23 Feb 2024
// This file contains implementation of Graph class.
//===============================
#include "Graph.h"
#include <iostream>
#include <stdexcept>
#include <queue>
using namespace std;

//==============================================
// Graph(void)
// Default Contructor for Graph class
// INPUT: none
// RETURN: none
//==============================================
Graph::Graph(void) {
    V = DEFAULT_VERTICES_NUM;
    E = 0;
}

//==============================================
// Graph(int vertices, int edges)
// Constructor with specficied number of vertices
// and edges
// INPUT: 
// int vertices: The number of vertices in the graph
// int edges: the number of edges in the graph
// RETURN: none
//==============================================
Graph::Graph(int vertices, int edges) {
    if (vertices < 0 || edges < 0) 
        throw std::invalid_argument("The number of vertices and edges cannot be negative.");
    V = vertices;
    E = edges;        
}

//==============================================
// Graph(const Graph& other)
// Copy Contructor for Graph class
// INPUT: 
// Graph& other: A reference parameter to another 
// Graph object
// RETURN: none
//==============================================
Graph::Graph(const Graph& other) {
    V = other.V;
    E = other.E;
}

//==============================================
// ~Graph(void)
// Destructor for Graph class  
// INPUT: none
// RETURN: none
//==============================================
Graph::~Graph(void) {
    V = 0;
    E = 0;    
}

//==============================================
// operator=(const Graph& other)
// assignment operator, basically the same thing 
// as the copy constructor 
// INPUT: 
// const Graph& other: A constant reference parameter 
// to another Graph object
// RETURN: returns a pointer to the Graph we are 
// assigning a value to
//==============================================
Graph& Graph::operator=(const Graph& other) {
    V = other.V;
    E = other.E;
    return *this;
}

int     Graph::size   () const{
    return V;
}

// void Graph::BFS ( int source ){
//     queue<int> pq;
//     for(int i=0; i < V; i++){
//         //Initialization
        
//     }



// }

// void Graph::printBFSTable ( int source ){

// }

// void Graph::printBFSPath ( int s, int d ){

// }