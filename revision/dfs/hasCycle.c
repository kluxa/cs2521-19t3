
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

// We can use a DFS to find whether there is a cycle in a graph. This is
// one of the practice exercises, but I'll give you a hint.

bool hasCycleRec(Graph g, Vertex v, int *pred);


bool hasCycle(Graph g) {
	int *pred = malloc(GraphNumVertices(g) * sizeof(int));
	for (int i = 0; i < GraphNumVertices(g); i++) {
		pred[i] = -1;
	}
	
	free(pred);
	// return the result here...
	return false;
}

bool hasCycleRec(Graph g, Vertex v, int *pred) {
	// TODO
	return false;
}

////////////////////////////////////////////////////////////////////////

int main(void) {
	// Play around with hasCycle - create a graph using the functions in
	// Graph.h and then call hasCycle
	
}
