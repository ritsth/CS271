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
SparseGraph::SparseGraph(void) : Graph(DEFAULT_VERTICES_NUM, 0){
    adjList.resize(V);
} 

//==============================================
// SparseGraph(const SparseGraph &mySparseGraph)
// Copy Contructor for SparseGraph class
// Create a new SparseGraph from an existing one.
// INPUT: const SparseGraph &mySparseGraph
// RETURN: none
//==============================================
SparseGraph::SparseGraph  ( const SparseGraph& mygraph ): Graph(mygraph){
    adjList = mygraph.adjList;
}

//==============================================
// SparseGraph(void)
// Parameterized Contructor for SparseGraph class
// INPUT: none
// RETURN: none
//==============================================
SparseGraph::SparseGraph  ( int V, int E ) : Graph(V, 0){
    adjList.resize(V);
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
    V = E = 0;
    adjList.clear();
}


//==============================================
// operator= ( const SparseGraph &mySparseGraph )
// Assignment operator.
// Assign SparseGraph to the class
// INPUT: const SparseGraph &mySparseGraph 
// RETURN: SparseGraph
//==============================================
SparseGraph& SparseGraph::operator=	    ( const SparseGraph &mySparseGraph ){
    if (this != &mySparseGraph) {
        //Clearing
        V=0;
        E=0;
        adjList.clear();
        Graph::operator=(mySparseGraph);        // Call base class assignment operator to copy V and E
        adjList = mySparseGraph.adjList;    // Deep copy the adjacent matrix
    }
    return *this;
}



//==============================================
// isEdge ( int v1, int v2 )
// Returns true if there is a edge from the given vertices.
// INPUT: int v,  int v2 
// RETURN: bool
//==============================================
bool SparseGraph::isEdge(int v1, int v2) const {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 > V) 
        throw std::invalid_argument("Invalid vertex number.");
    return adjList[v1].find(v2) != adjList[v1].end();
} 

//==============================================
// getWeight(int v1, int v2)
// Returns the weight of the edge from the given vertices.
// INPUT: int v,  int v2 
// RETURN: int
//==============================================
int SparseGraph::getWeight(int v1, int v2) const {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 > V)
        throw std::invalid_argument("Invalid vertex number.");
    // Check is there a edge first
    if (isEdge( v1, v2)){
        return adjList[v1].find(v2)->second; 
    }
    return -1;
}

#ifdef DIRECTED_GRAPH
//==============================================
// insertEdge(int v1, int v2, int w = 1)
// Inserts a edge between given vertices for a directed graph
// INPUT: int v1, int v2, int w = 1
// RETURN: void
//==============================================
void SparseGraph::insertEdge(int v1, int v2, int w = 1) {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0)
        throw std::invalid_argument("Invalid edge parameters.");
    if (isEdge( v1, v2)){
      adjList[v1].find(v2)->second = w;  
    } else{
        adjList[v1][{v2}] = w;
        E++;
    }
}
#endif 

#ifndef DIRECTED_GRAPH
//==============================================
// insertEdge(int v1, int v2, int w = 1)
// Inserts a edge between given vertices for a undirected graph
// INPUT: int v1, int v2, int w = 1
// RETURN: void
//==============================================
void SparseGraph::insertEdge(int v1, int v2, int w = 1) {
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0) 
        throw std::invalid_argument("Invalid edge parameters.");
        
    if (isEdge( v1, v2)){
      adjList[v1].find(v2)->second = w;  
      adjList[v2].find(v1)->second = w; 
    }else{
        adjList[v1][{v2}] = w;
        adjList[v2][{v1}]= w;
        E++;
    }
    
}
#endif
