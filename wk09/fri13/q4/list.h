
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct node *List;
struct node {
	int value;
	List next;
};

List selectSort(List ls);

List newList(int size,  ...);

void printList(List l);

#endif
