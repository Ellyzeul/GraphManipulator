#include "utils.h"
#include "GraphL.h"
#include <stdio.h>
#include <stdlib.h>

int* extendIntVector(const int *oldVec, int *oldLen, const int newLen){
    int *newVec, i;
    newVec = calloc(newLen+1, sizeof(int));

    for(i = 0; i <= *oldLen; i++)
        newVec[i] = oldVec[i];
    for(int j = i; j <= newLen; j++)
        newVec[j] = 0;
    
    *oldLen = newLen;
    return newVec;
}
LNode* extendLNodeVector(const LNode *oldVec, int *oldLen, const int newLen){
    LNode *newVec = calloc(newLen+1, sizeof(LNode));
    int i;

    for(i = 0; i <= *oldLen; i++)
        newVec[i] = oldVec[i];
    for(int j = i; j <= newLen; j++) {
        newVec[j].next = NULL;
        newVec[j].info = 0;
        newVec[j].weight = 0;
    }
    
    *oldLen = newLen;
    return newVec;
}