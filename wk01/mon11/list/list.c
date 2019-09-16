
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static List insertEnd(List l, int value);
static List newNode(int value);

/**
 * Creates an empty list
 */
List newList(void) {
	return NULL;
}

/**
 * Creates a list with the elements in the given array.
 */
List arrayToList(int array[], int size) {
	List l = NULL;
	for (int i = 0; i < size; i++) {
		l = insertEnd(l, array[i]);
	}
	return l;
}

/**
 * Inserts a value at the end of the list and returns
 * the pointer to the first node of the updated list.
 */
static List insertEnd(List l, int value) {
	List n = newNode(value);
	
	// If the list is empty,  the new
	// node becomes the first node
	if (l == NULL) {
		return n;
	
	// Otherwise, insert the new node
	// after the last node
	} else {
		List curr = l;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
		return l;
	}
}

static List newNode(int value) {
	List n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(1);
	}
	n->value = value;
	n->next = NULL;
	return n;
}

/**
 * Prints a list
 */
void printList(List l) {
	List curr = l;
	while (curr != NULL) {
		printf("[%d] -> ", curr->value);
		curr = curr->next;
	}
	printf("X\n");
}
