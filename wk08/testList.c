
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#include "list.h"

void testMap(void);
void testFold(void);
void testFilter(void);

int main(void) {
	testMap();
	testFold();
	testFilter();
}

//////////////////////////////////////////////////

int square(int x) { return x * x; }
int triple(int x) { return 3 * x; }
int increm(int x) { return x + 1; }

void testMap(void) {
	printf("\n***** testMap *****\n");
	List l1 = newList(5, 1, 3, 5, 7, 9);
	printList(l1);
	
	printf("mapping square over the list\n");
	map(l1, square);
	printList(l1);

	printf("mapping triple over the list\n");
	map(l1, triple);
	printList(l1);

	printf("mapping increm over the list\n");
	map(l1, increm);
	printList(l1);
}

//////////////////////////////////////////////////

int mul(int x, int y) { return x * y; }
int sum(int x, int y) { return x + y; }
int min(int x, int y) { return x < y ? x : y; }

void testFold(void) {
	printf("\n***** testFold *****\n");
	List l1 = newList(4, 1, 2, 3, 4);
	printList(l1);

	int product = fold(l1, mul, 1);
	printf("fold(l1, mul, 1) => %d\n", product);

	int listSum = fold(l1, sum, 0);
	printf("fold(l1, sum, 0) => %d\n", listSum);

	int minimum = fold(l1, min, INT_MAX);
	printf("fold(l1, min, %d) => %d\n", INT_MAX, minimum);
}

//////////////////////////////////////////////////
// For your interest

bool  isOdd(int x) { return x % 2 != 0; }
bool isEven(int x) { return x % 2 == 0; }
bool  isPos(int x) { return x > 0; }

void testFilter(void) {
	printf("\n***** testFilter *****\n");
	List l1 = newList(7, -3, -2, -1, 0, 1, 2, 3);
	printList(l1);

	printf("filtering odds\n");
	printList(filter(l1, isOdd));

	printf("filtering evens\n");
	printList(filter(l1, isEven));

	printf("filtering positives\n");
	printList(filter(l1, isPos));
}
