// getPeaks.c 
// Written by Ashesh Mahidadia, August 2017

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "DLList.h"

/* 
    You will submit only this one file.

    Implement the function "getPeaks" below. Read the exam paper for 
    detailed specification and description of your task.  

    - DO NOT modify code in the file DLList.h . 
    - You can add helper functions in this file.  
    - DO NOT add "main" function in this file. 
    
*/

static void DLListAppend(DLList L, int value);

DLList getPeaks(DLList L) {
    DLList peaksL = newDLList();
	
    if (L->nitems < 3) {
        return peaksL;
    }
	
    for (DLListNode *curr = L->first->next; curr->next != NULL; curr = curr->next) {
        if (curr->value > curr->prev->value && curr->value < curr->next->value) {
            DLListAppend(peaksL, curr->value);
        }
    }
	
    peaksL->curr = peaksL->first;
    return peaksL;
}

static void DLListAppend(DLList L, int value) {
    DLListNode *new = malloc(sizeof(*new));
    
    if (L->first == NULL) {
        L->first = new;
        L->last = new;
        L->curr = new;
		
    } else {
		L->last->next = new;
        new->prev = L->last;
        L->last = new;
    }
}

