
#ifndef LIST_H
#define LIST_H

typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

typedef Node *List; // pointer to first Node

/**
 * Creates an empty list
 */
List newList(void);

/**
 * Creates a list with the elements in the given array
 */
List arrayToList(int array[], int size);

/**
 * Prints a list
 */
void printList(List l);

#endif
