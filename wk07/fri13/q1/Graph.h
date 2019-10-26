// Interface for an Undirected Graph ADT where vertices are identified
// by integers between 0 and N - 1, where N is the number of vertices.

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef int Vertex;

typedef struct Edge {
	Vertex v;
	Vertex w;
} Edge;

typedef struct graph *Graph;

////////////////////////////////////////////////////////////////////////
// Constructors

/**
 * Creates a new Graph with the given number of vertices and no edges.
 * @param nV - the number of vertices
 */
Graph GraphNew(int nV);

/**
 * Creates a new Graph with edges as given in the boolean matrix.
 * @param nV - the number of vertices
 * @param edges - a matrix of booleans indicating which edges the graph
 *                should contain (true = edge, false = no edge)
 * @pre - for all v, edges[v][v] is false
 *
 * Example Usage:
 *  bool edges[4][4] = {
 *  	{0, 1, 0, 1},
 *  	{1, 0, 1, 0},
 *  	{0, 1, 0, 1},
 *  	{1, 0, 1, 0}
 *  };
 *  Graph g = GraphNewFromMatrix(4, edges);
 */
Graph GraphNewFromMatrix(int nV, bool edges[nV][nV]);

/**
 * Creates a new Graph with edges as given in the array of edges.
 * @param nV - the number of vertices
 * @param nE - the number of edges
 * @param edges - an array of edges, where each edge is an array of two
 *                vertices
 * @pre - for all edges {v, w}, v != w
 *
 * Example Usage:
 *  Edge edges[] = {
 *  	{0, 1}, {1, 2}, {2, 3}, {3, 0}
 *  };
 *  Graph g = GraphNewFromEdgeArray(4, 4, edges);
 */
Graph GraphNewFromEdgeArray(int nV, int nE, Edge edges[nE]);

////////////////////////////////////////////////////////////////////////
// Destructors

/**
 * Frees all the memory allocated for the given Graph.
 * @param g - the graph to be freed
 */
void GraphFree(Graph g);

////////////////////////////////////////////////////////////////////////
// General Graph Functions

/**
 * Returns the number of edges in the given Graph.
 */
int GraphNumVertices(Graph g);

/**
 * Adds an undirected edge between two vertices to the given Graph. If
 * the edge already exists, this function does nothing.
 * @pre - v != w
 */
void GraphAddEdge(Graph g, Vertex v, Vertex w);

/**
 * Removes an undirected edge between two vertices from the given Graph.
 * If the edge does not exist, this function does nothing.
 * @pre - v != w
 */
void GraphRemoveEdge(Graph g, Vertex v, Vertex w);

/**
 * Checks whether two vertices are adjacent in the given Graph. Returns
 * true or false as appropriate.
 */
bool GraphIsAdjacent(Graph g, Vertex v, Vertex w);

/**
 * Returns the number of neighbours of a given vertex. A vertex is not
 * considered to be a neighbour of itself.
 */
int GraphNumNeighbours(Graph g, Vertex v);

////////////////////////////////////////////////////////////////////////
// Displaying the Graph

void GraphDump(Graph g, FILE *fp);

////////////////////////////////////////////////////////////////////////
// Graph Search Algorithms

/**
 * Performs a breadth-first search on the graph starting at the given
 * vertex.
 * @returns - a dynamically allocated array of predecessor vertices. The
 *            predecessor of the starting vertex is set to be itself. If
 *            a vertex is unreachable, its predecessor is set to -1.
 */
Vertex *GraphBfs(Graph g, Vertex src);

/**
 * Performs a depth-first search on the graph starting at the given
 * vertex.
 * @returns - a dynamically allocated array of predecessor vertices. The
 *            predecessor of the starting vertex is set to be itself. If
 *            a vertex is unreachable, its predecessor is set to -1.
 */
Vertex *GraphDfs(Graph g, Vertex src);

#endif

