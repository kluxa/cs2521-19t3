
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct node *List;
struct node {
	int value;
	List next;
};

void map(List L, int (*f)(int));

int fold(List L, int (*f)(int, int), int z);

List filter(List L, bool (*f)(int));

List newList(int size,  ...);

void printList(List l);

#endif
