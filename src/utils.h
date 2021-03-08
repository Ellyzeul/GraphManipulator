#ifndef __ELLYZ__GRAPH_MANIPULATION__UTILS__
#define __ELLYZ__GRAPH_MANIPULATION__UTILS__

#include "GraphL.h"

int* extendIntVector(const int *oldVec, int *oldLen, const int newLen);
LNode* extendLNodeVector(const LNode *oldVec, int *oldLen, const int newLen);

#endif