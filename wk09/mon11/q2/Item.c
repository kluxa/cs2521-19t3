
#include <stdbool.h>
#include <stdio.h>

#include "Item.h"

bool itemsEqual(Item i1, Item i2) {
	return i1.a == i2.a && i1.b == i2.b;
}

bool itemGreaterThan(Item i1, Item i2) {
	return i1.a > i2.a;
}

bool itemLessThan(Item i1, Item i2) {
	return i1.a < i2.a;
}

void itemShow(Item i) {
	printf("{a: %d, b: %d}",
	       i.a, i.b);
}
