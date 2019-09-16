
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List createNode(int val);

/*
typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

typedef Node *List; // pointer to first Node
*/

/**
 * Insert a value at the end of the list.
 * Returns the head of the updated list.
 */
List listAppend(List l, int val) {
	if (l == NULL) {
		return createNode(val);
	}

	List curr = l;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = createNode(val);
	return l;
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
 * the list, if it exists. Returns the
 * head of the updated list.
 */
List deleteVal(List l, int val) {
	// empty list
	if (l == NULL) {
		return NULL;
	}

	// first node contains val
	if (l->value == val) {
		List newHead = l->next;
		free(l);
		return newHead;
	}

	// first node doesn't contain val
	List curr = l;
	List prev = NULL;
	while (curr != NULL) {
		if (curr->value == val) {
			prev->next = curr->next;
			free(curr);
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	return l;
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
