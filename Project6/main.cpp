//============================================================
// Matt Kretchmar
// April 2024
// main_a_level.cpp
// This file tests various graph operations
// It assumes students are completing the b_level option
//============================================================
#include "Graph.h"
#include <iostream>
using namespace std;

int main ( void )
{
   Graph *gp;

   int nv, ne;
   cin >> nv >> ne;
   //gp = new DenseGraph(nv,ne);
   gp = new Graph(nv,ne);
   cin >> (*gp);
   cout << (*gp);

   printf("Edge Testing\n");

   int v1, v2, w;
   v1 = 0;
   v2 = 2;
   printf("Is there an edge from %d to %d: %d\n",v1,v2,gp->isEdge(v1,v2));
   printf("Edge value from %d to %d: %d\n",v1,v2,gp->getWeight(v1,v2));

   v1 = 2;
   v2 = 0;
   // for undirected, this should give the same reults
   // for directed, the second line should generate an exception.
   printf("Is there an edge from %d to %d: %d\n",v1,v2,gp->isEdge(v1,v2));
   printf("Edge value from %d to %d: %d\n",v1,v2,gp->getWeight(v1,v2));

   v1 = 0;
   v2 = 3;
   printf("Is there an edge from %d to %d: %d\n",v1,v2,gp->isEdge(v1,v2));

   Graph *gp2 = new Graph(*gp);
   cout << (*gp2);                   // print out the graph


   delete gp;
   delete gp2;
   
   return 0;
}
