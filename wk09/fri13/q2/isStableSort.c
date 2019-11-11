
#include <stdbool.h>

#include "arrayUtil.h"
#include "isStableSort.h"
#include "Item.h"

static void bubbleSort(Item A[], int size);
static void swap(Item A[], int i, int j);

bool isStableSort(Item original[], Item sorted[], int lo, int hi) {
	// TODO
	return false;
}

// Known to be stable
static void bubbleSort(Item A[], int size) {
	bool swapped;
	for (int i = size - 1; i > 0; i--) {
		swapped = false;
		for (int j = 0; j < i; j++) {
			if (A[j].a > A[j + 1].a) {
				swap(A, j, j + 1);
				swapped = true;
			}
		}
		if (swapped == false) {
			break;
		}
	}
}

static void swap(Item A[], int i, int j) {
	Item temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
