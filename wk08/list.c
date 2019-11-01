
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define empty(L) (L == NULL)
#define head(L)  (L->value)
#define tail(L)  (L->next)

static List newNode(int value);

/**
 * Replaces  the  value  in each node of the given
 * list  by f(x), where x is the original value in
 * the node.
 */
void map(List L, int (*f)(int))
{
	if (!empty(L)) {
		head(L) = f(head(L));
		map(tail(L), f);
	}
}

/**
 * Compresses  the given list to a single value by
 * applying  the  function f all the way along the
 * list.
 */
int fold(List L, int (*f)(int, int), int z)
{
	if (empty(L)) {
		return z;
	} else {
		return f(head(L), fold(tail(L), f, z));
	}
}

/**
 * Applies f to each element of the given list and
 * returns  a  new  list containing all the values
 * for which f returned true.
 */
List filter(List L, bool (*f)(int))
{
	if (empty(L)) {
		return NULL;
	}
	
	if (f(head(L))) {
		List res  = newNode(head(L));
		res->next = filter(tail(L), f);
		return res;
	} else {
		List res  = filter(tail(L), f);
		return res;
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
 * You  don't have to know how to do this, but it's
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
