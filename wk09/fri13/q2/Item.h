
#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>

typedef struct {
	int a;
	int b;
} Item;

bool itemsEqual(Item i1, Item i2);

bool itemGreaterThan(Item i1, Item i2);

bool itemLessThan(Item i1, Item i2);

void itemShow(Item i);

#endif
