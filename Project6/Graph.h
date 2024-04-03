//===============================
// Graph.h
// Name: Ritika 
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
    virtual       ~Graph      ( void );                   
    virtual void  insertEdge  ( int v1, int v2, int w);
    virtual bool  isEdge      ( int v1, int v2 ) const;
    virtual int   getWeight   ( int v1, int v2) const;     
};

#include "Graph.cpp"

#endif  // GRAPH_H



    


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
