all: main_bfs_undirected main_bfs_directed main_dfs_directed main_dfs_undirected main

main_bfs_directed: main_bfs.cpp Graph.cpp Graph.h DenseGraph.h DenseGraph.cpp SparseGraph.h SparseGraph.cpp
	g++ -std=c++2a -o main_bfs_directed -DDIRECTED_GRAPH main_bfs.cpp Graph.cpp DenseGraph.cpp SparseGraph.cpp

main_bfs_undirected: main_bfs.cpp Graph.cpp Graph.h DenseGraph.h DenseGraph.cpp SparseGraph.h SparseGraph.cpp
	g++ -std=c++2a -o main_bfs_undirected main_bfs.cpp Graph.cpp DenseGraph.cpp SparseGraph.cpp

main_dfs_directed: main_dfs.cpp Graph.cpp Graph.h DenseGraph.h DenseGraph.cpp SparseGraph.h SparseGraph.cpp
	g++ -std=c++2a -o main_dfs_directed -DDIRECTED_GRAPH main_dfs.cpp Graph.cpp DenseGraph.cpp SparseGraph.cpp

main_dfs_undirected: main_dfs.cpp Graph.cpp Graph.h DenseGraph.h DenseGraph.cpp SparseGraph.h SparseGraph.cpp
	g++ -std=c++2a -o main_dfs_undirected main_dfs.cpp Graph.cpp DenseGraph.cpp SparseGraph.cpp

main: main.cpp Graph.cpp Graph.h DenseGraph.h DenseGraph.cpp SparseGraph.h SparseGraph.cpp DisjointSet.h DisjointSet.cpp
	g++ -std=c++2a -o main main.cpp Graph.cpp DenseGraph.cpp SparseGraph.cpp DisjointSet.cpp 