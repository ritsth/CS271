//===============================
// DenseGraph.cpp
// Name: Ritika, Max, Uyen
// Date: 23 Feb 2024
// This file contains implementation of derived DenseGraph class.
//===============================
#include "DenseGraph.h"
#include <iomanip>
#include <queue>
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


void DenseGraph::BFS ( int source ){
    queue<int> pq;
    adjVertex.resize(V);
    for(int i=0; i < V; i++){
        //Initialization
        adjVertex[i].color = 'W';
        adjVertex[i].pred = -1;
        adjVertex[i].dist = -1;
    }

    adjVertex[source].color = 'G';
    adjVertex[source].pred = -1;
    adjVertex[source].dist = 0;

    pq.push(source);
    int u;

    while (!pq.empty()){
        u = pq.front();
        pq.pop();

        //for each vertex connected from u
        for(int v=0;v <V;v++){
            if (isEdge(u,v)){
                if (adjVertex[v].color == 'W'){
                    adjVertex[v].color = 'G';
                    adjVertex[v].pred = u;
                    adjVertex[v].dist = adjVertex[u].dist+1;
                    pq.push(v);
                }                
            }
        }
        adjVertex[u].color = 'B';
    }


}

void DenseGraph::printBFSTable ( int source ){
    cout << "Vertex:         ";
    for (int i=source; i < V;i++){
        cout << "v" << i << "  ";
    }
    cout << "\nPredecessor:    ";
    for (int i=source; i < V;i++){
        if (adjVertex[i].pred != -1){
            cout << "v" << adjVertex[i].pred << "  ";            
        }
        else{
            cout <<adjVertex[i].pred << "  ";  
        }
    }
    cout << "\nDistance:        ";
    for (int i=source; i < V;i++){
        cout << adjVertex[i].dist << "   ";
    }
    cout << "\nColor:           ";
    for (int i=source; i < V;i++){
        cout  << adjVertex[i].color << "   ";
    }
    cout << ""<< endl;
}

void DenseGraph::printBFSPath ( int s, int d ){
    if(s == d){
        cout << "v" << s <<" ";
    }
    else if (adjVertex[d].pred == -1)
    {
        cout<< "No path from " <<  s << " to " << d << " exists." <<endl;
    }
    else{
        printBFSPath (s,adjVertex[d].pred);
        cout << "v" << d << " ";
    }
    
}

void DenseGraph::printMostDistant ( int s ){
    int max_dist = 0;
    //Find the max distance
    for(int i=0;i< V;i++){
        if(adjVertex[i].dist > max_dist){
            max_dist = adjVertex[i].dist ;
        }
    }    
    
    //Find the max distance vertex
    for(int i=0;i< V;i++){
        if(adjVertex[i].dist == max_dist){
            cout << "v" << i << " ";
        }
    }    
    cout << "\nMax distance: " << max_dist << endl;  


}
    
bool DenseGraph::isConnected ( void ){
    for(int i=1;i< V;i++){
        if(adjVertex[i].pred == -1){
            return false;
        }
    }
    return true;
}

//============================================================
// ! DFS-based algorithms
//============================================================
void DenseGraph::DFS(void) {
    info.resize(adjMatrix.size());
    int time = 0;
    for (int i = 0; i < adjMatrix.size(); i++) {
        if (info[i].color == 'W') {
            DFS_Visit(i, time);
        }
    }
}


void DenseGraph::DFS_Visit(int v, int &clock) {
    clock++;
    info[v].discoveryTime = clock;
    info[v].color = 'G';
    for (int i = 0; i < adjMatrix[v].size(); i++) {
        if (adjMatrix[v][i] != -1 && info[i].color == 'W') {
            info[i].pred = v;
            DFS_Visit(i, clock);
        }
    }
    clock++;
    info[v].finishingTime = clock;
    info[v].color = 'B';
}


void DenseGraph::printDFSParenthesization(void) {
    vector<bool> visited(V, false);

    function<void(int, bool)> dfsParenthesize = [&](int v, bool isFirst) {
        visited[v] = true;
        if (isFirst) {
            cout << "(v" << v; 
        } else {
            cout << " (v" << v;  
        }

        bool first = true;
        for (int u = 0; u < V; u++) {
            if (adjMatrix[v][u] != -1 && !visited[u]) {  
                if (first)
                    first = false;
                dfsParenthesize(u, false);  
            }
        }
        cout << " v" << v << ")";  
    };

    bool isFirst = true;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsParenthesize(i, isFirst);  
            if (isFirst)
                isFirst = false;  
            else 
                cout << " ";  
        }
    }
    cout << endl;  
}



void DenseGraph::classifyDFSEdges(void) {
    for (int u = 0; u < adjMatrix.size(); u++) {
            for (int v = 0; v < adjMatrix[u].size(); v++) {
                if (adjMatrix[u][v] != -1) {  
                    if (info[u].discoveryTime < info[v].discoveryTime)
                        cout << "Edge (v" << u << ", v" << v << ") is a forward/tree edge" << endl;
                    else if (info[u].discoveryTime > info[v].discoveryTime && info[u].finishingTime > info[v].finishingTime)
                        cout << "Edge (v" << u << ", v" << v << ") is a cross edge" << endl;
                    else
                        cout << "Edge (v" << u << ", v" << v << ") is a back edge" << endl;
            }
        }
    }
}