//============================================================
// DenseGraph.cpp
// Name: Ritika, Max, Uyen
// Date: 23 Feb 2024
// This file tests various graph operations of DenseGraph and SparseGraph
//============================================================
#include "Graph.h"
#include "DenseGraph.h"
#include "SparseGraph.h"
#include <iostream>
using namespace std;

// Testing Directed Graph
#ifdef DIRECTED_GRAPH
int main (void)
{
   //========================================================
   // Testing Directed DenseGraph with graph1.txt
   cout << "*********************************************************************" << endl;
   cout << "Testing Directed DenseGraph with graph1.txt" << endl;

   // Create a new Graph object that points to a DenseGraph object
   Graph *gp;

   int nv, ne;                         // Read in V and E
   cin >> nv >> ne;
   // gp = new SparseGraph(nv, ne);    // Should work for this also
   gp = new DenseGraph(nv, ne);

   cin >> (*gp);                       // Read in the graph
   cout << (*gp);                      // Print out the graph

   //=========================================
   // a. Edge Testing
   cout << "*********************************************" << endl;
   printf("a. Edge Testing\n");
   
   // i. There is an edge from v1 to v2
   int v1, v2;
   v1 = 0;
   v2 = 2;
   printf("i. Checking an existing edge\n");
   printf("- Is there an edge from %d to %d: %d\n", v1, v2, gp->isEdge(v1, v2));
   printf("- Edge value from %d to %d: %d\n", v1, v2, gp->getWeight(v1, v2));

   // ii. There does not exist an edge from v1 to v2
   printf("ii. Checking a non-existing edge\n");
   v1 = 3;
   v2 = 0;
   printf("- Is there an edge from %d to %d: %d\n", v1, v2, gp->isEdge(v1, v2));
   
   // iii. Passing non-valid argument
   printf("iii. Passing non-valid argument for testing\n");
   v1 = 4;
   v2 = -1;
   try {
      printf("- Is there an edge from %d to %d: %d\n", v1, v2, gp->isEdge(v1, v2));
   } catch (const std::exception& e) {
      cout << "- Exception caught: " << e.what() << endl;
   }

   //=========================================
   // b. Testing copy constructor
   cout << "*********************************************" << endl;
   printf("b. Testing Copy Constructor\n");

   // Graph *gp1 = new SparseGraph(*(SparseGraph *)gp);     // Should work for this also
   Graph *gp1 = new DenseGraph(*(DenseGraph *)gp);
   cout << (*gp1);         // Print out the graph

   //=========================================
   // c. Testing Inserting Edge
   cout << "*********************************************" << endl;
   printf("c. Testing Inserting Edge\n");

   // i. Insert a new edge to the graph
   printf("i. Insert a new edge to current graph\n");
   gp1->insertEdge(3, 1, 6);
   cout << (*gp1);         // Print out the graph

   // ii. Override the weight of an existing edge
   printf("ii. Override the weight of existing edge\n");
   gp1->insertEdge(0, 2, 5);
   cout << (*gp1);         // Print out the graph
   
   // iii. Passing non-valid argument
   printf("iii. Passing non-valid argument for testing\n");
   v1 = -2;
   v2 = 7;
   try {
      printf("- Inserting new edge from %d to %d: ", v1, v2);
      gp1->insertEdge(v1, v2, -2);
   } catch (const std::exception& e) {
      cout << "Exception caught: " << e.what() << endl;
   }

   //=========================================
   // d. Testing Assignment Operator
   cout << "*********************************************" << endl;
   printf("d. Testing Assignment Operator\n");

   // SparseGraph gp2, gp3(3, 4);      // Should work for this also
   DenseGraph gp2, gp3(3, 4);

   gp2.insertEdge(1, 2, 10);
   gp2.insertEdge(2, 5, 6);
   printf("- Current graph of gp2: \n");
   cout << gp2;                  // Print out the graph

   printf("- Current graph of gp3: \n");
   cout << gp3;                  // Print out the graph   
   
   printf("- New graph of gp3 after gp3 = gp2 \n");
   gp3 = gp2;
   cout << gp3;

   // =========================================
   // e. Clear up pointers to prevent memory leaking
   delete gp;
   delete gp1;

   return 0;
}
#endif


// Testing Undirected Graph
#ifndef DIRECTED_GRAPH
int main (void)
{
   //========================================================
   // Testing Undirected SparseGraph with graph3.txt
   cout << "*********************************************************************" << endl;
   cout << "Testing Undirected SparseGraph with graph3.txt" << endl;

   // Create a new Graph object that points to a DenseGraph object
   Graph *gp;

   int nv, ne;                         // Read in V and E
   cin >> nv >> ne;
   // gp = new DenseGraph(nv, ne);    // Should work for this also
   gp = new SparseGraph(nv, ne);

   cin >> (*gp);                       // Read in the graph
   cout << (*gp);                      // Print out the graph

   //=========================================
   // a. Edge Testing
   cout << "*********************************************" << endl;
   printf("a. Edge Testing\n");
   
   // i. There is an edge from v1 to v2
   int v1, v2;
   v1 = 1;
   v2 = 2;
   printf("i. Checking an existing edge\n");
   printf("- Is there an edge from %d to %d: %d\n", v1, v2, gp->isEdge(v1, v2));
   printf("- Is there an edge from %d to %d: %d\n", v2, v1, gp->isEdge(v1, v2));
   printf("- Edge value from %d to %d: %d\n", v1, v2, gp->getWeight(v1, v2));

   // ii. There does not exist an edge from v1 to v2
   printf("ii. Checking a non-existing edge\n");
   v1 = 4;
   v2 = 1;
   printf("- Is there an edge from %d to %d: %d\n", v1, v2, gp->isEdge(v1, v2));
   
   // iii. Passing non-valid argument
   printf("iii. Passing non-valid argument for testing\n");
   v1 = 6;
   v2 = 2;
   try {
      printf("- Is there an edge from %d to %d: %d\n", v1, v2, gp->isEdge(v1, v2));
   } catch (const std::exception& e) {
      cout << "- Exception caught: " << e.what() << endl;
   }

   //=========================================
   // b. Testing copy constructor
   cout << "*********************************************" << endl;
   printf("b. Testing Copy Constructor\n");

   // Graph *gp1 = new DenseGraph(*(DenseGraph *)gp);     // Should work for this also
   Graph *gp1 = new SparseGraph(*(SparseGraph *)gp);
   cout << (*gp1);         // Print out the graph

   //=========================================
   // c. Testing Inserting Edge
   cout << "*********************************************" << endl;
   printf("c. Testing Inserting Edge\n");

   // i. Insert a new edge to the graph
   printf("i. Insert a new edge to current graph\n");
   gp1->insertEdge(4, 1, 2);
   gp1->insertEdge(2, 5, 3);
   gp1->insertEdge(5, 1, 4);
   cout << (*gp1);         // Print out the graph

   // ii. Override the weight of an existing edge
   printf("ii. Override the weight of existing edge\n");
   gp1->insertEdge(3, 2, 6);
   cout << (*gp1);         // Print out the graph
   
   // iii. Passing non-valid argument
   printf("iii. Passing non-valid argument for testing\n");
   v1 = -2;
   v2 = 7;
   try {
      printf("- Inserting new edge from %d to %d: ", v1, v2);
      gp1->insertEdge(v1, v2, -2);
   } catch (const std::exception& e) {
      cout << "Exception caught: " << e.what() << endl;
   }

   //=========================================
   // d. Testing Assignment Operator
   cout << "*********************************************" << endl;
   printf("d. Testing Assignment Operator\n");

   // DenseGraph gp2, gp3(1, 2);      // Should work for this also
   SparseGraph gp2, gp3(1, 2);

   gp2.insertEdge(2, 3, 1);
   gp2.insertEdge(4, 5, 2);
   printf("- Current graph of gp2: \n");
   cout << gp2;                  // Print out the graph

   printf("- Current graph of gp3: \n");
   cout << gp3;                  // Print out the graph   
   
   printf("- New graph of gp3 after gp3 = gp2 \n");
   gp3 = gp2;
   cout << gp3;

   // =========================================
   // e. Clear up pointers to prevent memory leaking
   delete gp;
   delete gp1;

   return 0;
}
#endif