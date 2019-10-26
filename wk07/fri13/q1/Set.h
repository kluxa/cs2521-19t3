// Interface for a Set of integers

#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct set *Set;

/**
 * Creates an empty set.
 */
Set SetNew(void);

/**
 * Adds  a given item to the set. Simply does nothing if the set already
 * has the given item.
 */
void SetAdd(Set s, int i);

/**
 * Returns true if the set contains the given item, and false otherwise.
 */
bool SetContains(Set s, int i);

/**
 * Prints the set using set notation to the given file. Assumes the file
 * is open for writing.
 */
void SetDump(Set s, FILE *fp);

/**
 * Frees all the memory associated with the given set.
 */
void SetFree(Set s);

#endif

