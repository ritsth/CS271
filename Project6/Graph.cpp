//===============================
// Graph.cpp
// Name: Ritika, Max, Uyen
// Date: 23 Feb 2024
// This file contains implementation of Graph class.
//===============================
#include "Graph.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>

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

//==============================================
// BFS(int source)
// This function performs a Breadth First Search
// on a graph, starting at a source node and 
// moving outwards in all directions from there
// INPUT: 
// int source: a source node to start the search at
// RETURN: void
//==============================================
void Graph::BFS(int source) {
    // Check for valid in source index
    if (source < 0 || source >= V) {
        cout << "Invalid source index." << endl;
        return;     // Exit if the source index is out of bounds
    }

    // Initialize a queue to manage BFS exploration order
    queue<int> pq;

    // Resize the table to include all vertices
    adjVertex.resize(V);

    // Initialize all vertices to default values
    for (int i = 0; i < V; i++) {
        adjVertex[i].color = 'W';
        adjVertex[i].pred  = -1;
        adjVertex[i].dist  = -1;
    }

    // Initialize the source node
    adjVertex[source].color = 'G';
    adjVertex[source].pred  = -1;
    adjVertex[source].dist  = 0;

    // Enqueue the source vertex
    pq.push(source);

    // Initalize a variable to hold the current vertex being explored
    int u;

    // Process the queue until it is empty
    while (!pq.empty()) {
        u = pq.front();     // Get the front vertex
        pq.pop();           // Remove the front vertex from the queue

        // Explore each vertex 'v' adjacent to 'u'
        for (int v = 0; v < V; v++) {
            // Check if there is an edge from 'u' to 'v'
            if (isEdge(u, v)) {
                // If 'v' is not yet visited
                if (adjVertex[v].color == 'W') {
                    adjVertex[v].color = 'G';                   // Mark 'v' as being explored
                    adjVertex[v].pred = u;                      // Set 'u' as the predecessor of 'v'
                    adjVertex[v].dist = adjVertex[u].dist + 1;  // Set the distance from the source
                    pq.push(v);                                 // Enqueue 'v' for exploration
                }
            }
        }   
        adjVertex[u].color = 'B';   // Mark 'u' as fully explored
    }
}

//==============================================
// printBFStable(int source)
// This function prints a BFS table with the 
// predecessor, distance from the source and
// color for each vertex
// INPUT: 
// int source: a source node to start the search at
// RETURN: void
//==============================================
void Graph::printBFSTable(int source) {
    // Check for valid in source index
    if (source < 0 || source >= V) {
        cout << "Invalid source index." << endl;
        return;     // Exit if the source index is out of bounds
    }

    // Print vertex numbers as a row
    cout << left << setw(15) << "Vertex";
    for (int i = source; i < V; i++) {
        cout << setw(10) << ("v" + to_string(i));
    }
    cout << endl;


    // Print color as a row
    cout << setw(15) << "Color";
    for (int i = source; i < V; i++) {
        string color = (adjVertex[i].color == 'W' ? "WHITE" :
                        adjVertex[i].color == 'G' ? "GRAY" : "BLACK");
        cout << setw(10) << color;
    }
    cout << endl;

    // Print predecessor as a row
    cout << setw(15) << "Predecessor";
    for (int i = source; i < V; i++) {
        if (adjVertex[i].pred != -1) {
            cout << setw(10) << ("v" + to_string(adjVertex[i].pred));  
        } else {
            cout << setw(10) << "NIL";
        }
    }
    cout << endl;

    // Print distance as a row
    cout << setw(15) << "Distance";
    for (int i = source; i < V; i++) {
        cout << setw(10) << adjVertex[i].dist;
    }
    cout << endl;
}

//==============================================
// printBFSPath(int s, int d)
// This function prints the path from the source
// vertex to a specified destination vertex. If 
// there is no path between the two vertices,
// it prints "No path from s to d exists"
// INPUT: 
// int s: the source node used in BFS
// int d: a destination node that we want a valid path to
// RETURN: void
//==============================================
void Graph::printBFSPath(int s, int d) {
    // Validate input vertices
    if (s < 0 || s >= V || d < 0 || d >= V) {
        cout << "Invalid source or destination vertex." << endl;
        return;
    }

    // Different cases of s and d
    if (s == d) {
        cout << "v" << s << " ";    // Print the single vertex
    } else if (adjVertex[d].pred == -1) {
        cout << "No path from " << s << " to " << d << " exists." << endl;
    } else {
        printBFSPath(s, adjVertex[d].pred);
        cout << "v" << d << " ";
    }
}

//==============================================
// PrintMostDistant(int s)
// This function priints a list of all vertices
// that are the furthest from the source vertex
// that started our BFS at.
// INPUT: 
// int s: a source node
// RETURN: void
//==============================================
void Graph::printMostDistant(int s) {
    // Valid input vertice
    if (s < 0 || s >= V) {
        cout << "Invalid source index." << endl;
        return;
    }

    // Intialize a variable to store the maximum distance found
    int max_dist = 0;

    // Loop to find the maximum distance from the source to any vertex
    for (int i = 0; i < V; i++) {
        // Check if the current vertex's distance is greater than the current maximum
        if(adjVertex[i].dist > max_dist) {
            max_dist = adjVertex[i].dist;  // Update max_dist with the greater distance
        }
    }    
    
    // After finding the maximum distance, find all vertices that are at this maximum distance
    cout << "Most distant vertices from v" << s << ": ";
    for (int i = 0; i < V; i++) {
        // Check if the current vertex's distance is equal to the maximum distance found
        if (adjVertex[i].dist == max_dist) {
            cout << "v" << i << " ";  // Print the vertex number if it is one of the furthest
        }
    }      
    // Print the maximum distance found
    cout << "\nMax distance: " << max_dist << endl;  
}

//==============================================
// isConnected(void)
// This function returns true if the graph is
// connected and false otherwise
// INPUT: none
// RETURN: a boolean value
//==============================================
bool Graph::isConnected(void) {
    // Loop through all vertices in the graph
    for (int i = 0; i < V; i++) {
        // Check each vertex to see if it has been reached from the source
        if (adjVertex[i].dist != 0 && adjVertex[i].pred == -1)
            return false;   // Return false if an unreachable vertex is found
    }
    // If no such vertex is found, the graph is connected
    return true;            
}   

//==============================================
// DFS(void)
// This function performs a depth first search on 
// a graph. Most of the actual work is done by the
// DFS_Visit() function (see next function)
// INPUT: none
// RETURN: void
//==============================================
void Graph::DFS(void) {
    // Ensure the info vector is properly sized for all vertices
    info.resize(V);  

    // Initialize all vertices as unvisited and with no predecessor
    for (int i = 0; i < V; i++) {
        info[i].color = 'W';
        info[i].pred  = -1;
    }

    // Initialize the time counter to 0 at the start of DFS
    int time = 0;

    // Iterate over all vertices to start DFS from each unvisited vertex
    for (int i = 0; i < V; i++) {
        // If the vertex is unvisited, perform a DFS visit from it
        if (info[i].color == 'W') {
            DFS_Visit(i, time);
        }
    }
}

//==============================================
// DFS_Visit(int v, int &clock)
// This function visits each vertex, and assigns
// it a discovery time.
// It recursively calls itself to visit every 
// vertex adjacent to the current one. Once All
// adjacent vertices have been finished, we can set
// the current vertex's finish time, and change 
// its color to black
// INPUT: 
// int v: Index for the current vertex being visited
// int &clock: reference parameter to the current time
// RETURN: void
//==============================================
void Graph::DFS_Visit(int v, int &clock) {
    // Increment the time and set the discovery time for the vertex
    clock++;
    info[v].discoveryTime = clock;

    // Change the vertex color to Gray, indicating it is being explored
    info[v].color = 'G';

    // Explore each vertex adjacent to 'v'
    for (int u = 0; u < V; u++) {
        // Check if 'u' is an adjacent vertex and if it is unvisited
        if (isEdge(v, u) && info[u].color == 'W') {
            info[u].pred = v;       // Set 'v' as the predecessor of 'u'
            DFS_Visit(u, clock);    // Recursively visit 'u'
        }
    }
    // After fully explore, increment the time and set the finishing time for 'v'
    clock++;
    info[v].finishingTime = clock;
    info[v].color = 'B';            // Change color to Black, indicating fully explored
}

//==============================================
// printDFSTable(void)
// This function prints a DFS table with the 
// predecessor, color, discover time and 
// finish time for each vertex
// INPUT: non
// RETURN: void
//==============================================
void Graph::printDFSTable(void) {
    // Print vertex numbers as a row
    cout << left << setw(15) << "Vertex";
    for (int i = 0; i < info.size(); i++) {
        cout << setw(10) << ("v" + to_string(i));
    }
    cout << endl;

    // Print colors as a row
    cout << setw(15) << "Color";
    for (int i = 0; i < info.size(); i++) {
        string color = (info[i].color == 'W' ? "WHITE" :
                        info[i].color == 'G' ? "GRAY" : "BLACK");
        cout << setw(10) << color;
    }
    cout << endl;

    // Print predecessor as a row
    cout << setw(15) << "Predecessor";
    for (int i = 0; i < info.size(); i++) {
        if (info[i].pred != -1) {
            cout << setw(10) << ("v" + to_string(info[i].pred));  
        } else {
            cout << setw(10) << "NIL";  
        }
    }
    cout << endl;

    // Print discovery times as a row
    cout << setw(15) << "Discover time";
    for (int i = 0; i < info.size(); i++) {
        cout << setw(10) << info[i].discoveryTime;
    }
    cout << endl;

    // Print finish times as a row
    cout << setw(15) << "Finish time";
    for (int i = 0; i < info.size(); i++) {
        cout << setw(10) << info[i].finishingTime;
    }
    cout << endl;
}

//==============================================
// printTopologicalSort(void)
// This function prints a topological sort of the vertices
// in the graph based on their finishing times as recorded
// in the DFS process. The vertices are printed in decreasing
// order of their finishing times.
// INPUT: none
// RETURN: void
//==============================================
void Graph::printTopologicalSort(void) {
    // Create a vector to store pairs of finishing time and vertex index
    vector<pair<int, int>> topSort;

    // Populate the vector with finishing times and corresponding vertex indices from the DFS info table
    for (int i = 0; i < info.size(); i++) {
        topSort.push_back(make_pair(info[i].finishingTime, i));
    }
    
    // Sort the vector in reverse order based on the finishing time 
    sort(topSort.rbegin(), topSort.rend());  

    // Iterate through the sorted vector and print each vertex in order
    for (int i = 0; i < topSort.size(); i++) {
        const pair<int, int>& vertex = topSort[i];
        cout << "v" << vertex.second;
        if (i < topSort.size() - 1)
            cout << " > ";
    }
    cout << endl;
}

//==============================================
// printDFSParenthesization(void)
// This function uses the DFS table information to 
// print out a parenthesization of the search
// INPUT: none
// RETURN: void
//==============================================
void Graph::printDFSParenthesization(void) {
    // Initialize a vector to store events, where each pair consist of time and vertex index
    vector<pair<int, int>> events;

    // Iterate through the each vertex to populate events
    for (int i = 0; i < V; i++) {
        events.push_back(make_pair(info[i].discoveryTime, -i-1));  // Negative index for opening parenthesis, adjusted for 1-based index
        events.push_back(make_pair(info[i].finishingTime, i+1));   // Positive index for closing parenthesis, adjusted for 1-based index
    }

    // Sort events based on time
    sort(events.begin(), events.end());  

    // Initialize variables to keep track of progress
    stack<int> s;       // Stack to track open vertices
    string result;      // Result string to accumulate the output

    // Process through each event in the sorted order
    for (size_t i = 0; i < events.size(); i++) {
        // First, get the adjusted and original index of current pair in events
        int index = events[i].second;       // Index to consider order to print parentheses
        int vertex = abs(index) - 1;        // Original vertex index

        // Negative index: discovery time -> opening parenthesis
        if (index < 0) { 
            // If not the first element, append with leading space and open parenthesis
            if (!result.empty()) {
                result += " (v" + to_string(vertex);
            } else {    // First element, start without leading space
                result = "(v" + to_string(vertex);
            }
            // Push vertex to stack indicating start of new DFS exploration
            s.push(vertex);
        } else {  // Positive index: finishing time -> closing parenthesis
            // Append vertex number and close parenthesis
            result += " v" + to_string(vertex) + ")";
            s.pop();
        }
    }
    // Output the fully formatted DFS traversal
    cout << result << endl;
}

//==============================================
// classifyDFSEdges(void)
// This function puts each edge into one of three 
// categories:
// 1. tree/forward edge
// 2. back edge
// 3. cross edge
// INPUT: none
// RETURN: void
//==============================================
void Graph::classifyDFSEdges(void) {
    // Iterate through each vertex 'u'
    for (int u = 0; u < V; u++) {
        // Check for edges from 'u' to every other vertex 'v'
        for (int v = 0; v < V; v++) { 
            if (isEdge(u, v)) {     
                // First, check if it is a forward/tree edge
                if (info[u].discoveryTime < info[v].discoveryTime && info[v].finishingTime < info[u].finishingTime) {
                    cout << "Edge (v" << u << ", v" << v << ") is a forward/tree edge" << endl;
                } else if (u == v || (info[v].discoveryTime < info[u].discoveryTime && info[u].finishingTime < info[v].finishingTime)) {
                    cout << "Edge (v" << u << ", v" << v << ") is a back edge" << endl;
                } else {
                    cout << "Edge (v" << u << ", v" << v << ") is a cross edge" << endl;
                }
            }
        }
    }
}
