all: main maind

maind: main_a_level.cpp Graph.cpp Graph.h DenseGraph.cpp DenseGraph.h SparseGraph.cpp SparseGraph.h
	g++ -std=c++20 -o maind -DDIRECTED_GRAPH main_a_level.cpp Graph.cpp DenseGraph.cpp SparseGraph.cpp

main: main_a_level.o Graph.o DenseGraph.o SparseGraph.o
	g++ -std=c++20 -o main main_a_level.o Graph.o DenseGraph.o SparseGraph.o

main_a_level.o: main_a_level.cpp Graph.h DenseGraph.h SparseGraph.h
	g++ -std=c++20 -c main_a_level.cpp

Graph.o: Graph.h Graph.cpp
	g++ -std=c++20 -c Graph.cpp

DenseGraph.o: DenseGraph.h DenseGraph.cpp Graph.h
	g++ -std=c++20 -c DenseGraph.cpp

SparseGraph.o: SparseGraph.h SparseGraph.cpp Graph.h
	g++ -std=c++20 -c SparseGraph.cpp
