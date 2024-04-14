//===============================
// SparseGraph.cpp
// Name: Ritika, Max, Uyen
// Date: 23 Feb 2024
// This file contains implementation of derived SparseGraph class.
//===============================
#include "SparseGraph.h"
#include <map>
#include <vector>
#include <stdexcept>
#include <queue>
using namespace std;

//==============================================
// SparseGraph(void)
// Default Contructor for SparseGraph class
// INPUT: none
// RETURN: none
//==============================================
SparseGraph::SparseGraph(void) : Graph(DEFAULT_VERTICES_NUM, 0) {
    adjList.resize(V);              // Resize the size of the adjList to V
} 

//==============================================
// SparseGraph(const SparseGraph &mySparseGraph)
// Copy Contructor for SparseGraph class
// Create a new SparseGraph from an existing one.
// INPUT: const SparseGraph &mySparseGraph
// RETURN: none
//==============================================
SparseGraph::SparseGraph(const SparseGraph& mygraph) : Graph(mygraph) {
    adjList = mygraph.adjList;      // Deep copy the adjMatrix of given SpareGraph object
}

//==============================================
// SparseGraph(void)
// Parameterized Contructor for SparseGraph class
// INPUT: none
// RETURN: none
//==============================================
SparseGraph::SparseGraph(int V, int E) : Graph(V, 0) {
    adjList.resize(V);              // Resize the size of the adjList to V
}

//==============================================
// ~SparseGraph(void)
// Destructor for SparseGraph class
// Cleans up the memory of the SparseGraph.
// INPUT: none
// RETURN: none
//==============================================
SparseGraph::~SparseGraph(void) {
    V = E = 0;                     // Reset V and E
    adjList.clear();               // Clear the adjList
}


//==============================================
// operator= ( const SparseGraph &mySparseGraph )
// Assignment operator.
// Assign SparseGraph to the class
// INPUT: const SparseGraph &mySparseGraph 
// RETURN: SparseGraph
//==============================================
SparseGraph& SparseGraph::operator=(const SparseGraph &mySparseGraph) {
    // Check for self-assignment
    if (this != &mySparseGraph) {
        // If not, first clear the current SparseGraph
        V = E = 0;
        adjList.clear();
        // Then, deep copy the variables of the given SparseGraph to the current graph
        Graph::operator=(mySparseGraph);    // Call base class assignment operator to copy V and E
        adjList = mySparseGraph.adjList;    // Deep copy the adjacent matrix
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
bool SparseGraph::isEdge(int v1, int v2) const {
    // First, check for valid parameters (0 <= v1, v2 < V)
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V) 
        throw std::invalid_argument("Invalid vertex number.");
    // Return true if an edge from v1 to v2 exists, else return false
    return adjList[v1].find(v2) != adjList[v1].end();
} 

//==============================================
// getWeight(int v1, int v2)
// Returns the weight of the edge from the given vertices.
// INPUT: int v,  int v2 
// RETURN: int
//==============================================
int SparseGraph::getWeight(int v1, int v2) const {
    // First, check for valid parameters (0 <= v1, v2 < V)
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V)
        throw std::invalid_argument("Invalid vertex number.");
    // Check if there is actually an edge from v1 to v2
    if (isEdge(v1, v2)){
        // If yes, return the weight
        return adjList[v1].find(v2)->second; 
    }
    // Else, throw an error to show that there is indeed no edge from v1 to v2
    throw std::runtime_error("Edge does not exists.");
}

#ifdef DIRECTED_GRAPH
//==============================================
// insertEdge(int v1, int v2, int w = 1)
// Inserts a edge between given vertices for a directed graph
// INPUT: int v1, int v2, int w = 1
// RETURN: void
//==============================================
void SparseGraph::insertEdge(int v1, int v2, int w = 1) {
    // First, check for valid parameters (0 <= v1, v2 < V && weight >= 0)
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0)
        throw std::invalid_argument("Invalid edge parameters.");
    // First, chech if there is an edge from v1 to v2 already
    if (isEdge(v1, v2)){
        // If yes, overwrite the current weight with the new weight
       adjList[v1].find(v2)->second = w;  
    } else {
        // If not yet, create a new edge from v1 to v2 with weight w and increase the number of edges
        adjList[v1][v2] = w;
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
    // First, check for valid parameters (0 <= v1, v2 < V && weight >= 0)
    if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V || w < 0) 
        throw std::invalid_argument("Invalid edge parameters.");
    // First, chech if there is an edge from v1 to v2 already
    if (isEdge(v1, v2)) {
        // If yes, overwrite the current weight with the new weight (v1 -> v2 and v2 -> v1)
        adjList[v1].find(v2)->second = w;  
        adjList[v2].find(v1)->second = w; 
    } else {
        // If not yet, create a new edge from v1->v2 and from v2->v1 and increase the number of edges
        adjList[v1][v2] = adjList[v2][v1] = w;
        E++;
    }
}
#endif

void SparseGraph::BFS ( int source ){
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

void SparseGraph::printBFSTable ( int source ){
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

void SparseGraph::printBFSPath ( int s, int d ){
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

void SparseGraph::printMostDistant ( int s ){
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
    
bool SparseGraph::isConnected ( void ){
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
void SparseGraph::DFS(void) {
    info.resize(V);  
    int time = 0;
    for (int i = 0; i < V; i++) {
        if (info[i].color == 'W') {
            DFS_Visit(i, time);
        }
    }
}


void SparseGraph::DFS_Visit(int v, int &clock) {
    clock++;
    info[v].discoveryTime = clock;
    info[v].color = 'G';
    for (map<int, int>::const_iterator pair = adjList[v].begin(); pair != adjList[v].end(); ++pair) {
        int i = pair->first;
        if (info[i].color == 'W') {
            info[i].pred = v;
            DFS_Visit(i, clock);
        }
    }
    clock++;
    info[v].finishingTime = clock;
    info[v].color = 'B';
}


void SparseGraph::printDFSParenthesization(void) {
    vector<bool> visited(V, false);

    function<void(int, bool)> dfsParenthesize = [&](int v, bool isFirst) {
        visited[v] = true;
        if (isFirst) {
            cout << "(v" << v; 
        } else {
            cout << " (v" << v;  
        }

        bool first = true;
        for (map<int, int>::const_iterator it = adjList[v].begin(); it != adjList[v].end(); ++it) {
            int u = it->first;  
            if (!visited[u]) {
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



void SparseGraph::classifyDFSEdges(void) {
    for (int u = 0; u < V; u++) {
        for (map<int, int>::const_iterator it = adjList[u].begin(); it != adjList[u].end(); ++it) {
            int v = it->first;
            if (info[u].discoveryTime < info[v].discoveryTime)
                cout << "Edge (v" << u << ", v" << v << ") is a forward/tree edge" << endl;
            else if (info[u].discoveryTime > info[v].discoveryTime && info[u].finishingTime > info[v].finishingTime)
                cout << "Edge (v" << u << ", v" << v << ") is a cross edge" << endl;
            else
                cout << "Edge (v" << u << ", v" << v << ") is a back edge" << endl;
        }
    }
}
