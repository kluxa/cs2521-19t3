
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
	
	printf("All tests passed.\n");
	
	return 0;
}

// sum a list using a while loop
int sumList1(List head) {
	// loop
	// condition to stop at the end
	// pointer to keep track of where we're up to
	// integer variable to keep track of the sum
	List curr = head;
	int sum = 0;
	while (curr != NULL) {
		sum += curr->value;
		curr = curr->next; 
	}
	return sum;
}

// sum a list using a for loop
int sumList2(List head) {
	int sum = 0;
	for (List curr = head; curr != NULL; curr = curr->next) {
		sum += curr->value;
	}
	return sum;
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
// of the rest of the list? (Recursion!)
int sumList3(List head) {
	if (head == NULL) {
		return 0;
	}

	return head->value + sumList3(head->next);
}
