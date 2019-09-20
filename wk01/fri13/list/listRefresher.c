
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

typedef Node *List; // pointer to first Node
*/

List createNode(int val);

/**
 * Insert a value at the end of the list
 */
List listAppend(List head, int val) {
	// We didn't have time to do this in the tute

	// empty list
	if (head == NULL) {
		return createNode(val);
	}

	// not empty list
	List curr = head;
	// loop until the last node
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = createNode(val);
	return head;
}

/**
 * Creates a node with the given val.
 * Also sets the next field of the node
 * to NULL so we don't have to do it later
 */
List createNode(int val) {
	// IMPORTANT
	// Note that we are allocating sizeof(Node) here,
	// not sizeof(List). This is important! List is a
	// pointer, so if we allocated sizeof(List), we
	// would only be allocating a pointer, which
	// is not enough space for an entire node
	List n = malloc(sizeof(Node));
	if (n == NULL) {
		fprintf(stderr, "couldn't allocate node");
		exit(EXIT_FAILURE);
	}
	n->value = val;
	n->next = NULL;
	return n;
}

/**
 * Delete first instance of a value from
 * the list, if it exists
 */
// inputs: head of the list, value we want to delete
// outputs: head of the updated list
List listDelete(List head, int val) {
	// empty list
	if (head == NULL) {
		return NULL;
	}

	// val is the first value in the list
	if (head->value == val) {
		List newHead = head->next;
		// newHead could be NULL, but that's fine
		// because  we don't need to access it in
		// this function.
		free(head);
		return newHead;
	}

	// val is not the first value in the list
	List prev = NULL;
	List curr = head;
	while (curr != NULL && curr->value != val) {
		prev = curr;
		curr = curr->next;
	}
	if (curr != NULL) {
		prev->next = curr->next;
		free(curr);
	}
	return head;
}

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
	l1 = listDelete(l1, 2);
	printList(l1);

	// try a value not in the list
	l1 = listDelete(l1, 9);
	printList(l1);

	// try a value that occurs more
	// than once in the list
	l1 = listDelete(l1, 1);
	printList(l1);

	// try a value that appears at
	// the beginning of the list
	l1 = listDelete(l1, 0);
	printList(l1);
}
