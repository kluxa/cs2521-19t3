
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

static void doReachable(Graph g, Vertex v, Set s);

Set reachable(Graph g, Vertex v) {
	Set s = SetNew();
	doReachable(g, v, s);
	return s;
}

static void doReachable(Graph g, Vertex v, Set s) {
	SetAdd(s, v);
	for (Vertex w = 0; w < GraphNumVertices(g); w++) {
		if (GraphIsAdjacent(g, v, w) && !SetContains(s, w)) {
			doReachable(g, w, s);
		}
	}
}
