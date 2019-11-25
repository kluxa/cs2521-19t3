
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void dfsRec(Graph g, Vertex v, int *pred);

// In  this  version,  the  visited array is replaced with a pred array,
// which stores the predecessor of each vertex during the DFS (or -1  if
// a  vertex  hasn't been visited). We have to use -1 if a vertex hasn't
// been visited, rather than 0, because 0 is a vertex number, so using 0
// would lead to ambiguities.

void dfs(Graph g, Vertex v) {
	int *pred = malloc(GraphNumVertices(g) * sizeof(int));
	for (int i = 0; i < GraphNumVertices(g); i++) {
		pred[i] = -1;
	}

	// Set the predecessor of v to itself
	pred[v] = v;
	dfsRec(g, v, pred);

	// Do something with the predecessor array. Here are some ideas:
	// - You can use it to count how many vertices are reachable from v
	// - You  can  use  it to check whether a vertex is reachable from v
	//   (i.e., whether there is a path from v to a given vertex)
	// - You can use it to print the path from v to any vertex
	//   > But note that this path is not necessarily the shortest - you
	//     would need to use a BFS if you wanted the shortest path
	//   > Also  note that the path will be in reverse, unless you place
	//     the path in an array and the print it in reverse
	
}

// Perform DFS on vertices that haven't been visited
void dfsRec(Graph g, Vertex v, int *pred) {
	for (int i = 0; i < GraphNumVertices(g); i++) {
		if (GraphIsAdjacent(g, v, i) && pred[i] == -1) {
			pred[i] = v;
			dfsRec(g, i, pred);
		}
	}
}

int main(void) {
	// Play  around with dfs here. Create a graph using the functions in
	// Graph.h and then call dfs
	
}
