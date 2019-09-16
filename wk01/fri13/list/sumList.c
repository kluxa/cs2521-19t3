
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
	
}

// sum a list using a for loop
int sumList2(List head) {
	
}

// sum a list using recursion
int sumList3(List head) {
	
}
