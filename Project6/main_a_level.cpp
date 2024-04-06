//============================================================
// Matt Kretchmar
// April 2024
// main_a_level.cpp
// This file tests various graph operations
// It assumes students are completing the a_level option
//============================================================

#include "Graph.h"
#include "DenseGraph.h"
#include "SparseGraph.h"
#include <iostream>
using namespace std;

int main ( void )
{
   Graph *gp;

   int nv, ne;
   cin >> nv >> ne;

   // gp = new DenseGraph(nv,ne);   // should work with either choice
   gp = new SparseGraph(nv,ne);

   cin >> (*gp);                    // read in the graph
   cout << (*gp);                   // print out the graph

   printf("Edge Testing1\n");

   int v1, v2, w;
   v1 = 0;
   v2 = 2;
   printf("Is there an edge from %d to %d: %d\n",v1,v2,gp->isEdge(v1,v2));
   printf("Edge value from %d to %d: %d\n",v1,v2,gp->getWeight(v1,v2));

   printf("Edge Testing2\n");
   v1 = 2;
   v2 = 0;
   // for undirected, this should give the same reults
   // for directed, the second line should generate an exception.
   printf("Is there an edge from %d to %d: %d\n",v1,v2,gp->isEdge(v1,v2));
   printf("Edge value from %d to %d: %d\n",v1,v2,gp->getWeight(v1,v2));

   printf("Edge Testing3\n");
   v1 = 0;
   v2 = 3;
   printf("Is there an edge from %d to %d: %d\n",v1,v2,gp->isEdge(v1,v2));

   // Graph *gp2 = new DenseGraph(*(DenseGraph *)gp);
   Graph *gp2 = new SparseGraph(*(SparseGraph *)gp);
   cout << (*gp2);                   // print out the graph
   

   printf("Testing insert Edge\n");
   gp2->insertEdge(3, 0, 4);
   gp2->insertEdge(1, 3, 5);

   cout << (*gp2);  

   printf("Testing Assignment op\n");
   Graph *gp3;
   gp3= gp2;
   
   cout << (*gp3);

   cout<<"here";
   delete gp;
   delete gp2;
   delete gp3;
   return 0;
}
