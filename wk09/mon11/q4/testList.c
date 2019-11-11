
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#include "list.h"

static void testSelectSort(List l);

int main(void) {
	List l1 = newList(5, 4, 8, 2, 6, 1);
	testSelectSort(l1);

	List l2 = newList(5, 5, 4, 3, 2, 1);
	testSelectSort(l2);

	List l3 = newList(5, 1, 2, 3, 4, 5);
	testSelectSort(l3);
}

static void testSelectSort(List l) {
	List sorted = selectSort(l);
	printf("Original list:\n");
	printList(l);
	printf("Sorted list:\n");
	printList(sorted);
	printf("\n");
}
