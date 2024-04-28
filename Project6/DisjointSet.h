#include <iostream>
#include <stdexcept>
#include <unordered_map>
using namespace std;

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

template <class T>
class DisjointSet
{
private:
    struct  setElement {
        T       parent;         // Set representative 
        size_t  rank;           // Rank of the tree, used to keep the tree flat during unions
    };
    // Hash table to map each element to its corresponding setElement
    std::unordered_map<T, setElement> elements;
    
public:
    // Primary methods
                DisjointSet     ( void ) {};                // Default constructor
                ~DisjointSet    ( void ) {};                // Destructor

    // Additional methods    
    void        makeSet         ( const T& element )        // Create a set containing only the specified element
    T           findSet         ( const T& element )        // Find the representative of the set containing element
    void        unionSets       ( const T& a, const T& b )  // Union the sets containing a and b
};

#endif  // DISJOINTSET_H
