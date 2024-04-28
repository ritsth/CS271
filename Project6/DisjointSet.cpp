#include "DisjointSet.h"
#include <iostream>
#include <stdexcept>
#include <unordered_map>

template <class T>
void DisjointSet<T>::makeSet(const T& element) {
    // Check if the element already exists in the disjoint set
    if (elements.find(element) != elements.end()) {
        throw std::invalid_argument("Element already exists in the disjoint set.");
    }
    // Create a new set with the element as its own parent and rank 0
    elements[element] = {element, 0};
}

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
