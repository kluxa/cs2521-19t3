
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int sumList1(List head);
int sumList2(List head);
int sumList3(List head);
int sumList4(List head);

int main(void) {
	// The more complex the problem
	// is, the more tests you need.
	
	// A 'common' case
	int A1[] = {6, 1, 5};
	List l1 = arrayToList(A1, 3);

	// An 'edge' case
	int A2[] = {};
	List l2 = arrayToList(A2, 0);

	int A3[] = {7};
	List l3 = arrayToList(A3, 1);

	assert(sumList1(l1) == 12);
	assert(sumList1(l2) ==  0);
	assert(sumList1(l3) ==  7);
	
	assert(sumList2(l1) == 12);
	assert(sumList2(l2) ==  0);
	assert(sumList2(l3) ==  7);
	
	assert(sumList3(l1) == 12);
	assert(sumList3(l2) ==  0);
	assert(sumList3(l3) ==  7);
	
	assert(sumList4(l1) == 12);
	assert(sumList4(l2) ==  0);
	assert(sumList4(l3) ==  7);
	
	printf("All tests passed.\n");
	
	return 0;
}

// sum a list using a while loop
int sumList1(List head) {
	int result = 0;
	List curr = head; // initialisation
	while (curr != NULL) { // condition
		result += curr->value;
		curr = curr->next; // increment
	}
	return result;
}

// sum a list using a for loop 1
int sumList2(List head) {
	int result = 0;
	List curr;
	for (curr = head; curr != NULL; curr = curr->next) {
		result += curr->value;
	}
	return result;
}

// sum a list using a for loop 2
int sumList3(List head) {
	int result = 0;
	// If curr is not needed outside the loop, you can declare
	// it inside the initialisation part of the for loop, but
	// you have to use -std=c99 or -std=c11 when compiling.
	for (List curr = head; curr != NULL; curr = curr->next) {
		result += curr->value;
	}
	return result;
}

// sum a list using recursion

// Recursion  is  particularly  suitable for problems where the
// data structure in question is recursive. For example:
// - a  linked list is a recursive structure because all linked
//   lists  (except  for the empty list) contain smaller linked
//   lists within them
// - a  string is recursive because all strings (except for the
//   empty string) contain smaller strings within them.
// - an  array  is recursive because all arrays (except for the
//   empty  array)  contain smaller arrays within them (usually
//   called subarrays).

// Suppose  that  you  are the first node in a linked list. The
// key  insight  is that if you knew the sum of the rest of the
// list, then you can easily find the sum of the entire list by
// just  adding  your value to it. But how can you find the sum
// of the rest of the list?
// (Hint: have a look at the paragraph on recursion above...)

int sumList4(List head) {
	return 0;
}

// the solution is below but pls try it yourself before looking








































































/*

int sumList4(List l) {
	if (l == NULL) {
		return 0;
	}

	return l->value + sumList4(l->next);
}

*/
