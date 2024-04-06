//===============================
// Graph.h
// Name: Ritika, Max, Uyen
// Date: 23 Feb 2024
// This file contains declaration of Grap class.
//===============================
#include <iostream>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

#define DEFAULT_VERTICES_NUM  10

class Graph
{
protected:
    int     V;      // Number of vertices
    int     E;      // Number of edges

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

    // Supporting method for operator<< 
    virtual     void    print       ( ostream& os ) const = 0; 
    
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
        graph.print(os);
        return os;
    }
};

#endif  // GRAPH_H
