// Implementation of a Set of integers

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

typedef struct node *Tree;
struct node {
	int value;
	Tree left;
	Tree right;
};

struct set {
	Tree root;
};

static Tree treeInsert(Tree t, int item);
static Tree newTreeNode(int item);
static bool treeSearch(Tree t, int item);
static void treePrintInOrder(Tree t, FILE *fp);
static void treeFree(Tree t);

/**
 * Creates an empty set.
 */
Set SetNew(void) {
	Set s = malloc(sizeof(*s));
	if (s == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	
	s->root = NULL;
	return s;
}

/**
 * Adds  a given item to the set. Simply does nothing if the set already
 * has the given item.
 */
void SetAdd(Set s, int item) {
	assert(s != NULL);
	
	s->root = treeInsert(s->root, item);
}

static Tree treeInsert(Tree t, int item) {
	if (t == NULL) {
		return newTreeNode(item);
	} else if (item < t->value) {
		t->left = treeInsert(t->left, item);
	} else if (item > t->value) {
		t->right = treeInsert(t->right, item);
	}
	return t;
}

static Tree newTreeNode(int item) {
	Tree n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	
	n->value = item;
	n->left = NULL;
	n->right = NULL;
	return n;
}

/**
 * Returns true if the set contains the given item, and false otherwise.
 */
bool SetContains(Set s, int item) {
	assert(s != NULL);
	
	return treeSearch(s->root, item);
}

static bool treeSearch(Tree t, int item) {
	if (t == NULL) {
		return false;
	} else if (item < t->value) {
		return treeSearch(t->left, item);
	} else if (item > t->value) {
		return treeSearch(t->right, item);
	} else {
		return true;
	}
}

/**
 * Prints the set using set notation to the given file. Assumes the file
 * is open for writing.
 */
void SetDump(Set s, FILE *fp) {
	assert(s != NULL);
	if (s->root == NULL) {
		fprintf(fp, "{}");
	} else {
		fprintf(fp, "{");
		treePrintInOrder(s->root, fp);
		fprintf(fp, "\b\b  \b\b}");
	}
}

static void treePrintInOrder(Tree t, FILE *fp) {
	if (t == NULL) return;
	treePrintInOrder(t->left, fp);
	fprintf(fp, "%d, ",  t->value);
	treePrintInOrder(t->right, fp);
}

/**
 * Frees all the memory associated with the given set.
 */
void SetFree(Set s) {
	treeFree(s->root);
	free(s);
}

static void treeFree(Tree t) {
	if (t == NULL) return;
	treeFree(t->left);
	free(t);
	treeFree(t->right);
}

