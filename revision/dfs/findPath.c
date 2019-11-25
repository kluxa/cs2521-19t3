
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

bool findPathRec(Graph g, Vertex v, Vertex w, int *visited);

// We can use a DFS to find whether there is a path between two vertices
// (if we don't care about how long the path is)

bool findPath(Graph g, Vertex v, Vertex w) {
	int *visited = calloc(GraphNumVertices(g), sizeof(int));
	bool result = findPathRec(g, v, w, visited);
	free(visited);
	return result;
}

// Is there a path from v to w?
bool findPathRec(Graph g, Vertex v, Vertex w, int *visited) {
	if (v == w) {
		return true;
	}
	visited[v] = 1;
	for (int i = 0; i < GraphNumVertices(g); i++) {
		if (GraphIsAdjacent(g, v, i) && visited[i] == 0) {
			if (findPathRec(g, i, w, visited)) {
				return true;
			}
		}
	}
	return false;
}

////////////////////////////////////////////////////////////////////////

int main(void) {
	// Play around with findPath - create a graph using the functions in
	// Graph.h and then call findPath
	
}
