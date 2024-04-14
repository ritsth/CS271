//===============================
// Graph.h
// Name: Ritika, Max, Uyen
// Date: 23 Feb 2024
// This file contains declaration of Graph class.
//===============================
#include <iostream>
#include <vector>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

#define DEFAULT_VERTICES_NUM  10

class Graph
{
protected:
    int     V;      // Number of vertices
    int     E;      // Number of edges

    // Helper structure for BFS
    struct Vertex {
        int pred;
        int dist;
        char color;

        Vertex() : pred(-1),  dist(-1), color('W'){}
    };

    // Helper structure for DFS
    struct VertexInfo {
        char    color;          
        int     pred;
        int     discoveryTime;
        int     finishingTime;

        VertexInfo() : color('W'), pred(-1), discoveryTime(-1), finishingTime(-1) {}
    };

    vector<Vertex>      adjVertex;
    vector<VertexInfo>  info;

public:
    // Primary methods
                        Graph       ( void );
                        Graph       ( int vertices, int edges );
                        Graph       ( const Graph& other );
    virtual             ~Graph      ( void );        
    virtual     Graph&  operator=   ( const Graph& other );

    // Virtual method to be override by derived classes           
    virtual     void    insertEdge  ( int v1, int v2, int w ) = 0;
    virtual     bool    isEdge      ( int v1, int v2 ) const  = 0;
    virtual     int     getWeight   ( int v1, int v2 ) const  = 0;     
    virtual     int     size        ( void ) const;     

    // BFS based algorithms
    virtual    void     BFS              ( int source ) = 0;
    virtual    void     printBFSTable    ( int source ) = 0;
    virtual    void     printBFSPath     ( int s, int d ) = 0;
    virtual    void     printMostDistant ( int s ) =0;
    virtual    bool     isConnected      ( void ) =0;

    // DFS based algorithms
    virtual    void     DFS                      ( void ) = 0; 
    virtual    void     DFS_Visit                ( int v, int &clock ) = 0;
    virtual    void     printDFSTable            ( void ) = 0;
    virtual    void     printTopologicalSort     ( void ) = 0;
    virtual    void     printDFSParenthesization ( void ) = 0;
    virtual    void     classifyDFSEdges         ( void ) = 0;
    // virtual    void     indexSort                ( int a[] ) = 0;

    // Friend functions for input and output operations
    friend istream & operator>>(istream& is, Graph& graph) {
        int v1, v2, weight;
        while (is >> v1 >> v2 >> weight) {
            graph.insertEdge(v1, v2, weight);
        }
        return is;
    }
    
    friend ostream & operator<<(ostream& os, const Graph& graph) {
        os << "G = (" << graph.V << ", " << graph.E << ")" << endl;
        for (int v1 = 0; v1 < graph.V; v1++) {
            for (int v2 = 0; v2 < graph.V; v2++) {
                if (graph.isEdge(v1, v2)) {
                    cout << v1 << " " << v2 << " " << graph.getWeight(v1, v2) << endl;
                }
            }
        }
        return os;
    }
};

#endif  // GRAPH_H
