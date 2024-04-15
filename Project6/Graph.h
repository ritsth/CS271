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

    // Table for BFS Algorithm 
    vector<Vertex>      adjVertex;

    // Table for DFS Algorithm
    vector<VertexInfo>  info;

public:
    // Primary methods
                        Graph                    ( void );
                        Graph                    ( int vertices, int edges );
                        Graph                    ( const Graph& other );
    virtual             ~Graph                   ( void );        
    virtual     Graph&  operator=                ( const Graph& other );

    // Virtual method to be override by derived classes           
    virtual     void    insertEdge               ( int v1, int v2, int w ) = 0;
    virtual     bool    isEdge                   ( int v1, int v2 ) const  = 0;
    virtual     int     getWeight                ( int v1, int v2 ) const  = 0;     
                int     size                     ( void ) const;     

    // BFS based algorithms
               void     BFS                      ( int source );
               void     printBFSTable            ( int source );
               void     printBFSPath             ( int s, int d );
               void     printMostDistant         ( int s );
               bool     isConnected              ( void );

    // DFS based algorithms
               void     DFS                      ( void ); 
               void     DFS_Visit                ( int v, int &clock );
               void     printDFSTable            ( void );
               void     printTopologicalSort     ( void );
               void     printDFSParenthesization ( void );
               void     classifyDFSEdges         ( void );

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
