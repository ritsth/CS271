#include "DisjointSet.h"
#include <iostream>
#include <stdexcept>
#include <unordered_map>
using namespace std;

template <class T>
void DisjointSet<T>::makeSet(const T& element) {
    // First, check that the element is not already in some disjoint set
    if (elements.find(element) != elements.end()) {
        throw std::invalid_argument("Element already exists in the disjoint set.");
    }
    // Then
    elements[element] = {element, 0};
}

template <class T>
T DisjointSet<T>::findSet(const T& element) {
    if (elements.find(element) == element.end()) {
        throw std::invalid_argument("Element not found in the disjoint set");
    }
    if (elements[element].parent != element) {
        elements[element].parent = findSet(elements[element].parent); // Path compression.
    }
    return elements[element].parent;
}

template <class T>
void DisjointSet<T>::unionSets(const T& a, const T& b) {
    if (elements.find(a) == elements.end() || elements.find(b) == elements.end()) {
        throw std::invalid_argument("One or both elements not found in the disjoint set.");
    }
    T rootA = findSet(a);
    T rootB = findSet(b);

    if (rootA != rootB) {
        if (elements[rootA].rank < elements[rootB].rank) {
            elements[rootA].parent = rootB;
        } else if (elements[rootA].rank > elements[rootB].rank) {
            elements[rootB].parent = rootA;
        } else {
            elements[rootB].parent = rootA;
            elements[rootA].rank++;
        }
    }
}
}
