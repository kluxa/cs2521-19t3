
#include <stdbool.h>
#include <stdio.h>

#include "arrayUtil.h"
#include "Item.h"

void arrayCopy(Item dst[], Item src[], int size) {
	for (int i = 0; i < size; i++) {
		dst[i] = src[i];
	}
}

bool arraysEqual(Item a1[], Item a2[], int size) {
	for (int i = 0; i < size; i++) {
		if (!itemsEqual(a1[i], a2[i])) {
			return false;
		}
	}
	return true;
}

void arrayShow(Item A[], int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		itemShow(A[i]);
		if (i != size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}
