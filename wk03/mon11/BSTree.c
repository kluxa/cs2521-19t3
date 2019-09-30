
#include <stdlib.h>

#include "BSTree.h"

/**
 * Returns the number of nodes in the tree.
 */
int TreeNumNodes(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + TreeNumNodes(t->left) + TreeNumNodes(t->right);
    }
}

/**
 * Returns  the  height  of  the given tree. The height of a tree is the
 * number  of  edges  on  the  longest path from the root node to a leaf
 * node. The height of an empty tree is -1.
 */
int TreeHeight(BSTree t) {
    if (t == NULL) {
        return -1;
    } else if (t->left == NULL && t->right == NULL) {
        return 0;
    } else {
        int l = TreeHeight(t->left);
        int r = TreeHeight(t->right);
        return 1 + (l > r ? l : r);
    }
}

/**
 * Returns the number of internal nodes in the tree. An internal node is
 * a  node  that  has  one  or more children, i.e., a node that is not a
 * leaf.
 */
int countInternal(BSTree t) {
    if (t == NULL) {
        return 0;
    } else if (t->left == NULL && t->right == NULL) {
        return 0;
    } else {
        return 1 + countInternal(t->left) + countInternal(t->right);
    }
}

/**
 * Returns the depth of the node containing the given key in the tree if
 * it exists, or -1 otherwise.
 */
int nodeDepth(BSTree t, int key) {
    if (t == NULL) {
        return -1; // key doesn't exist in the tree
    } else if (t->value == key) {
        return 0; // root node contains key
    } else {
        // key *could* be in left subtree
        if (key < t->value) {
            int depth = nodeDepth(t->left, key);
            return (depth == -1 ? -1 : 1 + depth);
        // key *could* be in right subtree
        } else {
            int depth = nodeDepth(t->right, key);
            return (depth == -1 ? -1 : 1 + depth);
        }
    }
}

/**
 * Returns  the  maximum  branch  length  of the given tree. The maximum
 * branch  length  is defined as the number of edges on the longest path
 * from  the  root to a leaf. The maximum branch length of an empty tree
 * is considered to be -1.
 */
int BSTreeMaxBranchLen(BSTree t) {
    return TreeHeight(t);
}
