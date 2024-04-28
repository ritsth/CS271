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
#include <set>
#include <functional>
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



void SparseGraph::delEdge(int v1, int v2){
    adjList[v2].erase(adjList[v2].find(v1));
}



Graph* SparseGraph::MST_Prim(void) {
    // Create a new graph M to hold the MST, initially with no edges
    Graph* M = new SparseGraph(V,0);

    // Start the MST from vertex 0
    int start_vertex=0;

    // Priority queue to store edges based on their weights in increasing order
    priority_queue<Edge,vector<Edge>, CompareWeight> Q;

    // Set of vertices included in the MST
    set <int> Inset = {start_vertex};

    // Set of vertices not yet included in the MST
    set <int> Outset;

    // Initialize the Outset with all other vertices
    for (int i = start_vertex + 1; i < V; i++) {
        Outset.insert(i);
    }

    // Add all edges starting from the start_vertex to the priority queue
    for (int i = 0; i < V; i++) {
        if (isEdge(start_vertex, i)) {
            Edge obj;
            obj.u = start_vertex;
            obj.v = i;
            obj.weight = adjList[start_vertex].find(i)->second;
            Q.push(obj);
        }
    }

    // While there are still vertices to be included in the MST
    while(!Outset.empty() && !Q.empty()) {
        // Get the smallest edge from the priority queue
        Edge obj2 = Q.top();
        Q.pop();

        // Check if this edge connects a vertex in the MST to one outside the MST
        if(Inset.count(obj2.u) && Outset.count(obj2.v) || Inset.count(obj2.v) && Outset.count(obj2.u)) {
            // Add this edge to the MST
            M->insertEdge(obj2.u,obj2.v,obj2.weight);

            // Removes extra edge from v -> u in case it's an undirected graph and duplicate edges were inserted
            M->delEdge(obj2.u,obj2.v);
            
            // Add new edges from the newly added vertex to the queue
            for (int i = 0; i < V; i++) {
                if (isEdge(obj2.v,i)) {
                    Edge temp;
                    temp.u = obj2.v;
                    temp.v = i;
                    temp.weight = adjList[obj2.v].find(i)->second;
                    Q.push(temp);
                } 
            }

            // Move the vertex from the Outset to the Inset
            Inset.insert(obj2.v);
            Outset.erase(obj2.v);
        }

    }
    // Return the MST graph
    return M;
}



Graph* SparseGraph::MST_Kruskal(void) {
    // Create a new DenseGraph to represent the MST
    Graph* mst = new SparseGraph(V, 0);

    // Priority queue to store edges
    priority_queue<Edge,vector<Edge>, CompareWeight> Q;

    // Add each edge to the priority queue
    for (int i = 0; i < adjList.size(); ++i) {
        for (const pair<int, int>& edge : adjList[i]) {
            Q.push(Edge(i, edge.first, edge.second));
        }
    }

    // Disjoint set to track connected components
    DisjointSet<int> S;

    // Counter for number of edges added to MST
    int count = 0;

    // Initialize the disjoint set with individual elements
    for (int i = 0; i < adjList.size(); ++i) {
        S.makeSet(i);
    }

    // Continue until MST has V-1 edges or priority queue is empty
    while (!Q.empty() && count < adjList.size() - 1) {
        // Get the smallest edge from the priority queue
        Edge e = Q.top();
        Q.pop();

        // Check if adding this edge forms a cycle
        if (S.findSet(e.u) != S.findSet(e.v)) {
            // Add edge to MST
            mst->insertEdge(e.u, e.v, e.weight);

            // Removes extra edge from v -> u in case it's an undirected graph and duplicate edges were inserted
            mst->delEdge(e.u, e.v);

            // Merge the sets
            S.unionSets(e.u, e.v);

            // Increment edge count
            count++;
        }
    }
    // Return the MST graph
    return mst;
}
