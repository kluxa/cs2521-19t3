
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

#define BETTER 1 // Set it to 1 or 0

#if (BETTER)

static void doReachable(Graph g, Vertex v, Set s);

Set reachable(Graph g, Vertex v) {
	Set s = SetNew();
	doReachable(g, v, s);
	return s;
}

static void doReachable(Graph g, Vertex v, Set s) {
	SetAdd(s, v);
	for (int i = 0; i < GraphNumVertices(g); i++) {
		if (GraphIsAdjacent(g, v, i) && !SetContains(s, i)) {
			doReachable(g, i, s);
		}
	}
}

#elif

// This is the version that we wrote in the tutorial.
// The thing I forgot to mention is that Set already keeps track of what
// vertices we have visited, so we don't need a visited array!!!

static void doReachable(Graph g, Vertex v, int *visited, Set s);

Set reachable(Graph g, Vertex v) {
	Set s = SetNew();
	int *visited = calloc(GraphNumVertices(g), sizeof(int));
	doReachable(g, v, visited, s);
	free(visited);
	return s;
}

static void doReachable(Graph g, Vertex v, int *visited, Set s) {
	visited[v] = 1;
	SetAdd(s, v);
	for (int i = 0; i < GraphNumVertices(g); i++) {
		if (GraphIsAdjacent(g, v, i) && visited[i] == 0) {
			doReachable(g, i, visited, s);
		}
	}
}

#endif
