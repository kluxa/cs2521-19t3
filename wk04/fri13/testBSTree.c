
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

#define LF(value)              newBSTLink(value, NULL,  NULL) // leaf
#define LC(value, left)        newBSTLink(value, left,  NULL) // left child only
#define RC(value, right)       newBSTLink(value, NULL, right) // right child only
#define LR(value, left, right) newBSTLink(value, left, right) // two children

static void initTrees(void);

static void testPrintHeightDiff(void);
static void testIsHeightBalanced(void);
static void testBSTWidth(void);

static BSTree newBSTLink(int value, BSTree left, BSTree right);

static BSTree t00, t01, t02, t03, t04, t05, t06, t07, t08, t09,
              t10, t11, t12, t13;


int main(void) {
    initTrees();
    
    testPrintHeightDiff();
    testIsHeightBalanced();
    testBSTWidth();
    
    printf("All tests passed!\n");
}

static void initTrees(void) {
    /*
        X
     */
    t00 =
        NULL;
    
    /*
        3
     */
    t01 =
        LF(3);
    
    /*
          6
         /
        3
     */
    t02 =
        LC(6,
            LF(3)
        );
    
    /*
        3
         \
          8
     */
    t03 =
        RC(3,
            LF(8)
        );
    
    /*
          6
         / \
        3   8
     */
    t04 =
        LR(6,
            LF(3),
            LF(8)
        );
    
    /*
            6
           /
          5
         /
        2
     */
    t05 =
        LC(6,
            LC(5,
                LF(2)
            )
        );
    
    /*
        3
         \
          4
           \
            7
     */
    t06 =
        RC(3,
            RC(4,
                LF(7)
            )
        );
    
    /*
          5
         / \
        2   6
             \
              8
     */
    t07 =
        LR(5,
            LF(2),
            RC(6,
                LF(8)
            )
        );

    /*
             5
            / \
           /   \
          3     7
         / \   / \
        2   4 6   8
     */
    t08 =
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
    t09 =
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
    t10 =
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
    t11 =
        RC(1,
            LC(8,
                RC(3,
                    LF(6)
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
    t12 =
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
    
    /*
                6
               / \
              /   \
             /     \
            4       8
           / \     /
          3   5   7
         /
        1
     */
    t13 =
        LR(6,
            LR(4,
                LC(3,
                    LF(1)
                ),
                LF(5)
            ),
            LC(8,
                LF(7)
            )
        );
}

static void testPrintHeightDiff(void) {
    printf("\n"
           "-----------------------\n"
           " printHeightDiff tests \n"
           "-----------------------\n");

    printf("\nt12:\n");
    assert(printHeightDiff(t12) == 5);

    printf("\nt13:\n");
    assert(printHeightDiff(t13) == 3);

    printf("\n");
}

static void testIsHeightBalanced(void) {
    assert(isHeightBalanced(t00) == -1);
    assert(isHeightBalanced(t01) ==  0);
    assert(isHeightBalanced(t02) ==  1);
    assert(isHeightBalanced(t03) ==  1);
    assert(isHeightBalanced(t04) ==  1);
    assert(isHeightBalanced(t05) ==  NOT_HEIGHT_BALANCED);
    assert(isHeightBalanced(t06) ==  NOT_HEIGHT_BALANCED);
    assert(isHeightBalanced(t07) ==  2);
    assert(isHeightBalanced(t08) ==  2);
    assert(isHeightBalanced(t09) ==  NOT_HEIGHT_BALANCED);
    assert(isHeightBalanced(t10) ==  2);
    assert(isHeightBalanced(t11) ==  NOT_HEIGHT_BALANCED);
    assert(isHeightBalanced(t12) ==  NOT_HEIGHT_BALANCED);
    assert(isHeightBalanced(t13) ==  3);

    printf("isHeightBalanced tests passed!\n");
}

static void testBSTWidth(void) {
    assert(BSTWidth(t00) ==  0);
    assert(BSTWidth(t01) ==  3);
    assert(BSTWidth(t02) ==  6);
    assert(BSTWidth(t03) ==  6);
    assert(BSTWidth(t04) ==  9);
    assert(BSTWidth(t05) ==  9);
    assert(BSTWidth(t06) ==  9);
    assert(BSTWidth(t07) == 12);
    assert(BSTWidth(t08) == 21);
    assert(BSTWidth(t09) == 12);
    assert(BSTWidth(t10) == 15);
    assert(BSTWidth(t11) == 12);
    assert(BSTWidth(t12) == 27);
    assert(BSTWidth(t13) == 21);

    printf("BSTWidth tests passed!\n");
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
