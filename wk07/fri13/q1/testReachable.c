
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

Set reachable(Graph g, Vertex v);

static void testReachable1(void);
static void testReachable2(void);
static void testReachable3(void);

int main(void) {
	setbuf(stdout, NULL);
	
	testReachable1();
	testReachable2();
	testReachable3();
	
	printf("All reachable tests passed!\n");
}

static void testReachable1(void) {
	/*
	   0       5
	   |       |
	   1---3---4
	   |       |
	   2       6
	 */
	Edge edges[] = {
		{0, 1}, {1, 2}, {1, 3}, {3, 4}, {4, 5}, {4, 6}
	};
	Graph g = GraphNewFromEdgeArray(7, 6, edges);
	
	Set s = reachable(g, 3);
	printf("Test 1: reachable(g, 3) => "); SetDump(s, stdout); printf("\n");
	assert(SetContains(s, 0));
	assert(SetContains(s, 1));
	assert(SetContains(s, 2));
	assert(SetContains(s, 3));
	assert(SetContains(s, 4));
	assert(SetContains(s, 5));
	assert(SetContains(s, 6));
	SetFree(s);
	
	GraphFree(g);
}

static void testReachable2(void) {
	/*
	   0     3
	    \   /|
	     \ / |   5---6
	      1  |       |
	     / \ |   8---7---9
	    /   \|
	   2     4
	 */
	Edge edges[] = {
		{0, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 3},
		{5, 6}, {6, 7}, {7, 8}, {7, 9}
	};
	Graph g = GraphNewFromEdgeArray(10, 9, edges);
	
	Set s1 = reachable(g, 2);
	printf("Test 2: reachable(g, 2) => "); SetDump(s1, stdout); printf("\n");
	assert( SetContains(s1, 0));
	assert( SetContains(s1, 1));
	assert( SetContains(s1, 2));
	assert( SetContains(s1, 3));
	assert( SetContains(s1, 4));
	assert(!SetContains(s1, 5));
	assert(!SetContains(s1, 6));
	assert(!SetContains(s1, 7));
	assert(!SetContains(s1, 8));
	assert(!SetContains(s1, 9));
	SetFree(s1);
	
	Set s2 = reachable(g, 9);
	printf("Test 2: reachable(g, 9) => "); SetDump(s2, stdout); printf("\n");
	assert(!SetContains(s2, 0));
	assert(!SetContains(s2, 1));
	assert(!SetContains(s2, 2));
	assert(!SetContains(s2, 3));
	assert(!SetContains(s2, 4));
	assert( SetContains(s2, 5));
	assert( SetContains(s2, 6));
	assert( SetContains(s2, 7));
	assert( SetContains(s2, 8));
	assert( SetContains(s2, 9));
	SetFree(s2);
	
	GraphFree(g);
}

static void testReachable3(void) {
	/*
	   0-----1           5-----6
	   |     |     4     |     |
	   |     |           |     |
	   3-----2           8-----7
	 */
	Edge edges[] = {
		{0, 2}, {2, 5}, {5, 7}, {7, 0},
		{1, 3}, {3, 6}, {6, 8}, {8, 1}
	};
	Graph g = GraphNewFromEdgeArray(9, 8, edges);
	
	Set s1 = reachable(g, 0);
	printf("Test 3: reachable(g, 0) => "); SetDump(s1, stdout); printf("\n");
	bool expected1[] = {true, false, true, false, false,
	                    true, false, true, false};
	for (int i = 0; i < 9; i++) {
		assert(SetContains(s1, i) == expected1[i]);
	}
	SetFree(s1);
	
	Set s2 = reachable(g, 4);
	printf("Test 3: reachable(g, 4) => "); SetDump(s2, stdout); printf("\n");
	bool expected2[] = {false, false, false, false, true,
	                    false, false, false, false};
	for (int i = 0; i < 9; i++) {
		assert(SetContains(s2, i) == expected2[i]);
	}
	SetFree(s2);
	
	Set s3 = reachable(g, 8);
	printf("Test 3: reachable(g, 8) => "); SetDump(s3, stdout); printf("\n");
	bool expected3[] = {false, true, false, true, false,
	                    false, true, false, true};
	for (int i = 0; i < 9; i++) {
		assert(SetContains(s3, i) == expected3[i]);
	}
	SetFree(s3);
	
	GraphFree(g);
}

