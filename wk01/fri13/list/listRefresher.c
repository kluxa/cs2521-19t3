
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

typedef Node *List; // pointer to first Node

/**
 * Insert a value at the end of the list
 */



/**
 * Delete first instance of a value from
 * the list, if it exists
 */


int main(void) {
	List l1 = newList();
	l1 = listAppend(l1, 0);
	l1 = listAppend(l1, 1);
	l1 = listAppend(l1, 1);
	l1 = listAppend(l1, 2);
	l1 = listAppend(l1, 3);
	l1 = listAppend(l1, 5);
	l1 = listAppend(l1, 8);
	
	printList(l1);

	// try a value in the list
	l1 = deleteVal(l1, 2);
	printList(l1);

	// try a value not in the list
	l1 = deleteVal(l1, 9);
	printList(l1);

	// try a value that occurs more
	// than once in the list
	l1 = deleteVal(l1, 1);
	printList(l1);

	// try a value that appears at
	// the beginning of the list
	l1 = deleteVal(l1, 0);
	printList(l1);
}
