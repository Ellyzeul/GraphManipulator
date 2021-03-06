#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int* extendVector(const int *oldVec, int *oldLen, const int newLen){
    int *newVec, i;
    newVec = calloc(newLen+1, sizeof(int));

    for(i = 0; i <= *oldLen; i++)
        newVec[i] = oldVec[i];
    for(int j = i; j <= newLen; j++)
        newVec[j] = (j != newLen ? 0 : 1);
    
    *oldLen = newLen;
    return newVec;
}
