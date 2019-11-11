
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static List newNode(int value);

static List copyList(List ls);
static List listMax(List ls);
static List listUnlinkNode(List ls, List node);

// We copy the original list. Then we repeatedly remove
// the  node containing the largest value from the copy
// list and add it to the beginning of a new list until
// the  copy  list  is  empty.  We should end up with a
// sorted list, which we just return.
List selectSort(List ls) {
	List copy = copyList(ls);
	List head = NULL;
	while (copy != NULL) {
		List max = listMax(copy);
		copy = listUnlinkNode(copy, max);
		max->next = head;
		head = max;
	}
	return head;
}

// Produces a copy of the given list
static List copyList(List ls) {
	if (ls == NULL) {
		return NULL;
	} else {
		List new = newNode(ls->value);
		new->next = copyList(ls->next);
		return new;
	}
}

// Returns a pointer to the node containing the largest
// element of the given list.
static List listMax(List ls) {
	List max = ls;
	for (List curr = ls; curr != NULL; curr = curr->next) {
		if (curr->value > max->value) {
			max = curr;
		}
	}
	return max;
}

// Removes a given node from a list without freeing it.
static List listUnlinkNode(List ls, List node) {
	// node  SHOULD  be in the list, so if we reach the
	// end of the list, something is wrong
	assert(ls != NULL);

	if (ls == node) {
		return ls->next;
	} else {
		ls->next = listUnlinkNode(ls->next, node);
		return ls;
	}
}

//////////////////////////////////////////////////
// Basic list functions

void printList(List l) {
	for (List curr = l; curr != NULL; curr = curr->next) {
		printf("[%d] -> ", curr->value);
	}
	printf("X\n");
}

/*
 * Creates a list from an arbitrary list of numbers
 * You don't have to know how to do this,  but it's
 * interesting!
 */
List newList(int size, ...) {
	List head = NULL;
	List curr = NULL;

	va_list args;
	va_start(args, size);

	for (int i = 0; i < size; i++) {
		int num = va_arg(args, int);

		List node = newNode(num);
		if (head == NULL) {
			head = node;
		} else {
			curr->next = node;
		}
		curr = node;
	}

	va_end(args);
	return head;
}

static List newNode(int value) {
	List n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	n->value = value;
	n->next = NULL;
	return n;
}
