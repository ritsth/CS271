//===============================
// Graph.h
// Name: Ritika 
// Date: 23 Feb 2024
// This file contains declaration of Grap class.
//===============================

#include <iostream>
#include <string>

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
private:
    int     V;      // Number of vertices
    int     E;      // Number of edges
    // I'm using a 2D list for now I guess...
    std::vector<std::vector<int>> adjMatrix;

public:
	            Graph   ( void );                   // Default constructor
                Graph   ( int vertices, int edges );  // Graph with the specified vertices and edges
                Graph   ( const Graph &myGraph );   // Copy constructor
	            ~Graph  ( void );                   // Destructor

    Graph     operator=	( const Graph &myGraph );

    bool      isEdge    ( int v1, int v2 );
    int       getWeight ( int v1, int v2 );
    void      insertEdge( int v1, int v2, int w );


//Overloading cout operator

    // friend ostream & operator<< ( ostream &os, Graph &myGraph )
    // {
    //     os << "[ ";

    //     for(int i = 0 ; i < myGraph.num_vertice; i ++){

    //         os << "" << myGraph.num_edge << " ";
    //     }

    //     os << "]";
    //     return os;	
    // }

//Overloading cin operator

    // friend istream & operator>> ( istream &in, Graph &myGraph )
    // {
    //     in >> myGraph.num_edge;
    //     return in;	
    // }

};

#endif