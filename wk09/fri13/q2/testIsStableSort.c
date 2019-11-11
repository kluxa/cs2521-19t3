
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayUtil.h"
#include "isStableSort.h"

static void test(Item A[], int size);
static void stableSort(Item A[], int size);
static void unstableSort(Item A[], int size);
static void insertionSort(Item A[], int size);
static void selectionSort(Item A[], int size);
static void swap(Item A[], int i, int j);

int main(void) {
	Item array1[] = {{1, 9}, {1, 4}, {2, 7}, {2, 3}};
	test(array1, 4);
	Item array2[] = {{2, 7}, {2, 3}, {1, 1}, {1, 9}};
	test(array2, 4);
	Item array3[] = {{2, 3}, {1, 6}, {2, 2}, {1, 7}};
	test(array3, 4);
}

static void test(Item A[], int size) {
	printf("***************\n");
	Item copy1[size]; arrayCopy(copy1, A, size);
	Item copy2[size]; arrayCopy(copy2, A, size);
	
	printf("Original array:      ");
	arrayShow(A, size);
	
	stableSort(copy1, size);
	printf("\nAfter stable sort:   ");
	arrayShow(copy1, size);
	printf("Checking the stable sort..... %s\n",
	       isStableSort(A, copy1, 0, size - 1) ?
		   "stable" : "unstable");
	
	unstableSort(copy2, size);
	printf("\nAfter unstable sort: ");
	arrayShow(copy2, size);
	printf("Checking the unstable sort... %s\n",
	       isStableSort(A, copy2, 0, size - 1) ?
		   "stable" : "unstable");
}

////////////////////////////////////////////////////////////

static void stableSort(Item A[], int size) {
	insertionSort(A, size);
}

static void unstableSort(Item A[], int size) {
	selectionSort(A, size);
}

static void insertionSort(Item A[], int size) {
	for (int i = 1; i < size; i++) {
		int j = i;
		Item temp = A[j];
		while (j > 0 && itemGreaterThan(A[j - 1], temp)) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = temp;
	}
}

static void selectionSort(Item A[], int size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i; j < size; j++) {
			if (itemLessThan(A[j], A[min])) {
				min = j;
			}
		}
		swap(A, i, min);
	}
}

static void swap(Item A[], int i, int j) {
	Item temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
