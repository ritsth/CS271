//================================================================
// Ritika, Max, Uyen
// April 2024
// DisjointSet.cpp
// This file contains the implementation for the DisjointSet class
// which we need to perform Kruskal's algorithm.
//================================================================

#include "DisjointSet.h"
#include <iostream>
#include <stdexcept>
#include <unordered_map>


//==============================================
// makeSet(const T& element)
// creates a new set with a specified elt
// INPUT: 
// const T& element: a reference parameter to 
// the element we want in the set
// RETURN: none
//==============================================
template <class T>
void DisjointSet<T>::makeSet(const T& element) {
    // Check if the element already exists in the disjoint set
    if (elements.find(element) != elements.end()) {
        throw std::invalid_argument("Element already exists in the disjoint set.");
    }
    // Create a new set with the element as its own parent and rank 0
    elements[element] = {element, 0};
}

//==============================================
// findSet(const T& element)
// this functions identifies the representative
// elt (root) for the set that our specified elt is stored in
// INPUT: 
// const T& element: a reference parameter to 
// the element we want to find the set 
// representative of
// RETURN: the representative elt (the root) of the set
//==============================================
template <class T>
T DisjointSet<T>::findSet(const T& element) {
    // Check if the element exists in the map, throw exception if it does not
    if (elements.find(element) == elements.end()) {
        throw std::invalid_argument("Element not found in the disjoint set");
    }
    // Path compression: make each node on the path point to the root
    if (elements[element].parent != element) {
        elements[element].parent = findSet(elements[element].parent);
    }
    return elements[element].parent;
}

//==============================================
// unionSets(const T& a, const T& b)
// creates the union of two sets
// INPUT: 
// const T& a, b: reference parameters to a
// elements in two different sets that we want 
// to take the union of
// RETURN: none
//==============================================
template <class T>
void DisjointSet<T>::unionSets(const T& a, const T& b) {
    // Check if either element is not found in the set, throw exception if true
    if (elements.find(a) == elements.end() || elements.find(b) == elements.end()) {
        throw std::invalid_argument("One or both elements not found in the disjoint set.");
    }

    // Find the roots of the sets containing a and b
    T rootA = findSet(a);
    T rootB = findSet(b);

    // If both elements have the same root, they are already in the same set
    if (rootA == rootB) return;

    // Union by rank
    if (elements[rootA].rank < elements[rootB].rank) {
        // Make the smaller ranked root point to the higher ranked root
        elements[rootA].parent = rootB;
    } else if (elements[rootA].rank > elements[rootB].rank) {
        // Make the smaller ranked root point to the higher ranked root
        elements[rootB].parent = rootA;
    } else {
        // If ranks are the same, arbitrarily choose one as new root and increment its rank
        elements[rootB].parent = rootA;
        elements[rootA].rank++;
    }
}

// Explicit instantiation for int
template class DisjointSet<int>;
