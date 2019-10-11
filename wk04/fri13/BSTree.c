
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

/**
 * Prints  the  height difference between the left subtree and the right
 * subtree  of  every  node  in  the  given binary tree, and returns the
 * height of the binary tree.
 */
int printHeightDiff(BSTree t) {
    if (t == NULL) {
        return -1;
    } else {
        int l = printHeightDiff(t->left);
        int r = printHeightDiff(t->right);
        printf("At node %d, left height - right height = %d\n", t->value, l - r);
        return (l < r ? r : l) + 1;
    }
}

static int max(int n1, int n2) {
    return (n1 > n2 ? n1 : n2);
}

/**
 * Returns the height of the given binary tree if it is height-balanced,
 * and  NOT_HEIGHT_BALANCED otherwise. A tree is height-balanced if, for
 * every  node,  the  absolute difference between the height of the left
 * subtree and right subtree is no greater than 1.
 */
int isHeightBalanced(BSTree t) {
    if (t == NULL) {
        return -1;
    } else {
        int lh = isHeightBalanced(t->left);
        int rh = isHeightBalanced(t->right);
        if (lh == NOT_HEIGHT_BALANCED || rh == NOT_HEIGHT_BALANCED) {
            return NOT_HEIGHT_BALANCED;
        }

        if (abs(lh - rh) > 1) {
            return NOT_HEIGHT_BALANCED;
        } else {
            return 1 + max(lh, rh);
        }
    }
}

/**
 * Returns the width of the given tree. Width is defined as follows:
 * - an empty tree has width zero
 * - a tree with just one node has width three
 * - all  other  trees  have width which is three more than the combined
 *   width of the subtrees
 */
int BSTWidth(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 3 + BSTWidth(t->left) + BSTWidth(t->right);
    }
}

/**
 * Deletes  all  leaves  from the given tree and returns the root of the
 * updated tree. (bonus function)
 */
BSTree deleteLeaves(BSTree t) {
    if (t == NULL) {
        return NULL;
    } else if (t->left == NULL && t->right == NULL) {
        free(t);
        return NULL;
    } else {
        t->left = deleteLeaves(t->left);
        t->right = deleteLeaves(t->right);
        return t;
    }
}
