
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void dfsRec(Graph g, Vertex v, int *visited);

// In  this  version,  the visited array marks whether a vertex has been
// visited (1 if it has, 0 if it hasn't).  This can be extended in a lot
// of useful ways.

void dfs(Graph g, Vertex v) {
	int *visited = calloc(GraphNumVertices(g), sizeof(int));
	dfsRec(g, v, visited);

	// Do something with the predecessor array. Here are some ideas:
	// - You can use it to count how many vertices are reachable from v
	// - You  can  use  it to check whether a vertex is reachable from v
	//   (i.e., whether there is a path from v to a given vertex)

	free(visited);
}

// Perform DFS on vertices that haven't been visited
void dfsRec(Graph g, Vertex v, int *visited) {
	printf("%d ", v);
	visited[v] = 1;
	for (int i = 0; i < GraphNumVertices(g); i++) {
		if (GraphIsAdjacent(g, v, i) && visited[i] == 0) {
			dfsRec(g, i, visited);
		}
	}
}

////////////////////////////////////////////////////////////////////////

int main(void) {
	// Play  around with dfs here. Create a graph using the functions in
	// Graph.h and then call dfs

}
