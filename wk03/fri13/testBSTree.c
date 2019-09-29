
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

#define LF(value)              newBSTLink(value, NULL,  NULL) // leaf
#define LC(value, left)        newBSTLink(value, left,  NULL) // left child only
#define RC(value, right)       newBSTLink(value, NULL, right) // right child only
#define LR(value, left, right) newBSTLink(value, left, right) // two children

static void initTrees(void);

static void testTreeNumNodes(void);
static void testTreeHeight(void);
static void testCountInternal(void);
static void testNodeDepth(void);
static void testBSTreeMaxBranchLen(void);

static BSTree newBSTLink(int value, BSTree left, BSTree right);

static BSTree t01, t02, t03, t04, t05, t06, t07, t08, t09, t10, t11;


int main(void) {
    initTrees();

    testTreeNumNodes();
    testTreeHeight();
    testCountInternal();
    testNodeDepth();
    testBSTreeMaxBranchLen();

    printf("All tests passed!\n");
}

static void initTrees(void) {
    /*
     */
    t01 =
        NULL;
    
    /*
        3
     */
    t02 =
        LF(3);
    
    /*
          6
         /
        3
     */
    t03 =
        LC(6,
            LF(3)
        );
    
    /*
        3
         \
          8
     */
    t04 =
        RC(3,
            LF(8)
        );
    
    /*
          6
         / \
        3   8
     */
    t05 =
        LR(6,
            LF(3),
            LF(8)
        );
    
    /*
             5
            / \
           /   \
          3     7
         / \   / \
        2   4 6   8
     */
    t06 =
        LR(5,
            LR(3,
                LF(2),
                LF(4)
            ),
            LR(7,
                LF(6),
                LF(8)
            )
        );
    
    /*
            8
           /
          2
         / \
        1   7
     */
    t07 =
        LC(8,
            LR(2,
                LF(1),
                LF(7)
            )
        );
    
    /*
          2
         / \
        0   6
           / \
          4   8
     */
    t08 =
        LR(2,
            LF(0),
            LR(6,
                LF(4),
                LF(8)
            )
        );
    
    /*
        1
         \
          8
         /
        3
         \
          6
     */
    t09 =
        RC(1,
            LC(8,
                RC(3,
                    LF(6)
                )
            )
        );
    
    /*
              5
             / \
            4   6
           /     \
          3       7
         /         \
        2           8
     */
    t10 =
        LR(5,
            LC(4,
                LC(3,
                    LF(2)
                )
            ),
            RC(6,
                RC(7,
                    LF(8)
                )
            )
        );
    
    /*
        1
         \
          3
         / \
        2   5
           / \
          4   7
             / \
            6   9
               /
              8
     */
    t11 =
        RC(1,
            LR(3,
                LF(2),
                LR(5,
                    LF(4),
                    LR(7,
                        LF(6),
                        LC(9,
                            LF(8)
                        )
                    )
                )
            )
        );
}

static void testTreeNumNodes(void) {
    assert(TreeNumNodes(t01) == 0);
    assert(TreeNumNodes(t02) == 1);
    assert(TreeNumNodes(t03) == 2);
    assert(TreeNumNodes(t04) == 2);
    assert(TreeNumNodes(t05) == 3);
    assert(TreeNumNodes(t06) == 7);
    assert(TreeNumNodes(t07) == 4);
    assert(TreeNumNodes(t08) == 5);
    assert(TreeNumNodes(t09) == 4);
    assert(TreeNumNodes(t10) == 7);
    assert(TreeNumNodes(t11) == 9);

    printf("TreeNumNodes tests passed!\n");
}

static void testTreeHeight(void) {
    assert(TreeHeight(t01) == -1);
    assert(TreeHeight(t02) ==  0);
    assert(TreeHeight(t03) ==  1);
    assert(TreeHeight(t04) ==  1);
    assert(TreeHeight(t05) ==  1);
    assert(TreeHeight(t06) ==  2);
    assert(TreeHeight(t07) ==  2);
    assert(TreeHeight(t08) ==  2);
    assert(TreeHeight(t09) ==  3);
    assert(TreeHeight(t10) ==  3);
    assert(TreeHeight(t11) ==  5);

    printf("TreeHeight tests passed!\n");
}

static void testCountInternal(void) {
    assert(countInternal(t01) == 0);
    assert(countInternal(t02) == 0);
    assert(countInternal(t03) == 1);
    assert(countInternal(t04) == 1);
    assert(countInternal(t05) == 1);
    assert(countInternal(t06) == 3);
    assert(countInternal(t07) == 2);
    assert(countInternal(t08) == 2);
    assert(countInternal(t09) == 3);
    assert(countInternal(t10) == 5);
    assert(countInternal(t11) == 5);

    printf("countInternal tests passed!\n");
}

static void testNodeDepth(void) {
    assert(nodeDepth(t01, 1) == -1);

    assert(nodeDepth(t02, 3) ==  0);
    assert(nodeDepth(t02, 0) == -1);
    assert(nodeDepth(t02, 6) == -1);
    
    assert(nodeDepth(t03, 6) ==  0);
    assert(nodeDepth(t03, 3) ==  1);
    assert(nodeDepth(t03, 2) == -1);
    assert(nodeDepth(t03, 5) == -1);
    assert(nodeDepth(t03, 9) == -1);
    
    assert(nodeDepth(t04, 3) ==  0);
    assert(nodeDepth(t04, 8) ==  1);
    assert(nodeDepth(t04, 0) == -1);
    assert(nodeDepth(t04, 7) == -1);
    assert(nodeDepth(t04, 4) == -1);
    
    assert(nodeDepth(t05, 6) ==  0);
    assert(nodeDepth(t05, 3) ==  1);
    assert(nodeDepth(t05, 8) ==  1);
    assert(nodeDepth(t05, 1) == -1);
    assert(nodeDepth(t05, 4) == -1);
    assert(nodeDepth(t05, 7) == -1);
    assert(nodeDepth(t05, 9) == -1);
    
    assert(nodeDepth(t06, 5) ==  0);
    assert(nodeDepth(t06, 3) ==  1);
    assert(nodeDepth(t06, 7) ==  1);
    assert(nodeDepth(t06, 2) ==  2);
    assert(nodeDepth(t06, 4) ==  2);
    assert(nodeDepth(t06, 6) ==  2);
    assert(nodeDepth(t06, 8) ==  2);
    assert(nodeDepth(t06, 0) == -1);
    assert(nodeDepth(t06, 9) == -1);
    
    assert(nodeDepth(t07, 8) ==  0);
    assert(nodeDepth(t07, 2) ==  1);
    assert(nodeDepth(t07, 1) ==  2);
    assert(nodeDepth(t07, 7) ==  2);
    assert(nodeDepth(t07, 0) == -1);
    assert(nodeDepth(t07, 5) == -1);
    assert(nodeDepth(t07, 9) == -1);

    assert(nodeDepth(t08, 2) ==  0);
    assert(nodeDepth(t08, 0) ==  1);
    assert(nodeDepth(t08, 6) ==  1);
    assert(nodeDepth(t08, 4) ==  2);
    assert(nodeDepth(t08, 8) ==  2);
    assert(nodeDepth(t08, 1) == -1);
    assert(nodeDepth(t08, 3) == -1);
    assert(nodeDepth(t08, 5) == -1);
    assert(nodeDepth(t08, 7) == -1);
    assert(nodeDepth(t08, 9) == -1);

    assert(nodeDepth(t09, 1) ==  0);
    assert(nodeDepth(t09, 8) ==  1);
    assert(nodeDepth(t09, 3) ==  2);
    assert(nodeDepth(t09, 6) ==  3);
    assert(nodeDepth(t09, 0) == -1);
    assert(nodeDepth(t09, 2) == -1);
    assert(nodeDepth(t09, 5) == -1);
    assert(nodeDepth(t09, 7) == -1);
    assert(nodeDepth(t09, 9) == -1);

    assert(nodeDepth(t10, 5) ==  0);
    assert(nodeDepth(t10, 4) ==  1);
    assert(nodeDepth(t10, 6) ==  1);
    assert(nodeDepth(t10, 3) ==  2);
    assert(nodeDepth(t10, 7) ==  2);
    assert(nodeDepth(t10, 2) ==  3);
    assert(nodeDepth(t10, 8) ==  3);
    assert(nodeDepth(t10, 1) == -1);
    assert(nodeDepth(t10, 9) == -1);

    assert(nodeDepth(t11,  1) ==  0);
    assert(nodeDepth(t11,  3) ==  1);
    assert(nodeDepth(t11,  2) ==  2);
    assert(nodeDepth(t11,  5) ==  2);
    assert(nodeDepth(t11,  4) ==  3);
    assert(nodeDepth(t11,  7) ==  3);
    assert(nodeDepth(t11,  6) ==  4);
    assert(nodeDepth(t11,  9) ==  4);
    assert(nodeDepth(t11,  8) ==  5);
    assert(nodeDepth(t11,  0) == -1);
    assert(nodeDepth(t11, 10) == -1);

    printf("nodeDepth tests passed!\n");
}

static void testBSTreeMaxBranchLen(void) {
    assert(BSTreeMaxBranchLen(t01) == 0);
    assert(BSTreeMaxBranchLen(t02) == 0);
    assert(BSTreeMaxBranchLen(t03) == 1);
    assert(BSTreeMaxBranchLen(t04) == 1);
    assert(BSTreeMaxBranchLen(t05) == 1);
    assert(BSTreeMaxBranchLen(t06) == 2);
    assert(BSTreeMaxBranchLen(t07) == 2);
    assert(BSTreeMaxBranchLen(t08) == 2);
    assert(BSTreeMaxBranchLen(t09) == 3);
    assert(BSTreeMaxBranchLen(t10) == 3);
    assert(BSTreeMaxBranchLen(t11) == 5);

    printf("BSTreeMaxBranchLen tests passed!\n");
}

// ----------------------------------------

static BSTree newBSTLink(int value, BSTree left, BSTree right) {
    BSTree t = malloc(sizeof(*t));
    if (t == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }

    t->value = value;
    t->right = right;
    t->left = left;
    return t;
}
