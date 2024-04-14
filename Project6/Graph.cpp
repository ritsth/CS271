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
#include<algorithm>

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



void Graph::printDFSTable(void) {
    if (V <= 10) {
        cout << left << setw(15) << "Vertex:";
        for (int i = 0; i < info.size(); i++) {
            cout << setw(10) << i;
        }
        cout << endl;

        // Print colors as a row
        cout << setw(15) << "Color:";
        for (int i = 0; i < info.size(); i++) {
            string color = (info[i].color == 'W' ? "WHITE" :
                            info[i].color == 'G' ? "GRAY" : "BLACK");
            cout << setw(10) << color;
        }
        cout << endl;

        // Print predecessor as a row
        cout << setw(15) << "Predecessor:";
        for (int i = 0; i < info.size(); i++) {
            if (info[i].pred != -1) {
                cout << setw(10) << ("v" + to_string(info[i].pred));  
            } else {
                cout << setw(10) << "NIL";  
            }
        }
        cout << endl;

        // Print discovery times as a row
        cout << setw(15) << "Discover time:";
        for (int i = 0; i < info.size(); i++) {
            cout << setw(10) << info[i].discoveryTime;
        }
        cout << endl;

        // Print finish times as a row
        cout << setw(15) << "Finish time:";
        for (int i = 0; i < info.size(); i++) {
            cout << setw(10) << info[i].finishingTime;
        }
        cout << endl;
    } else {
        cout << "No DFS Table printed" << endl;
    }
}



void Graph::indexSort(int a[]) {
    vector<pair<int, int>> topSort;

    for (int i = 0; i < V; i++) {
        topSort.push_back(make_pair(info[a[i]].finishingTime, a[i]));
    }

    sort(topSort.rbegin(), topSort.rend());  

    for (int i = 0; i < V; i++) {
        a[i] = topSort[i].second;
    }
}


void Graph::printTopologicalSort(void) {
    int* sortedIndices = new int[V];  
    for (int i = 0; i < V; i++) {
        sortedIndices[i] = i; 
    }

    indexSort(sortedIndices);  

    for (int i = 0; i < V; i++) {
        cout << "v" << sortedIndices[i];
        if (i < V - 1)
            cout << " > ";
    }
    cout << endl;

    delete[] sortedIndices;  
}
