#ifndef __ELLYZ__GRAPH_MANIPULATOR__GRAPH__
#define __ELLYZ__GRAPH_MANIPULATOR__GRAPH__

#include "GraphL.h"

typedef struct {
    int type;                   // indica o tipo de grafo a ser usado
    short weighted;
    union {
        struct graphL *graphL;  // 0 para grafo com lista de adjacencia
    };
} Graph;

Graph* allocGraph(const int type, const short weighted, const int vNum);
void insertVertice(Graph *G, const int num, const int weight);
void insertAdjacency(Graph *G, const int in, const int out);
void removeVertice(Graph *G, const int num);
void removeAdjacency(Graph *G, const int in, const int out);

#endif