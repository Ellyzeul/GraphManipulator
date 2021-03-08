#ifndef __ELLYZ__GRAPH_MANIPULATOR__GRAPH__
#define __ELLYZ__GRAPH_MANIPULATOR__GRAPH__

#include "GraphL.h"

typedef struct {
    int type;                   // indica o tipo de grafo a ser usado
    short weighted;             // booleano indicando se e ponderado
    union {
        struct graphL *graphL;  // 0 para grafo com lista de adjacencia
    };
} Graph;

Graph* allocGraph(const int type, const short weighted);                        // aloca novo grafo
void insertVertice(Graph *G, const int num);                                    // insere novo vertice ao grafo
void insertAdjacency(Graph *G, const int in, const int out, const int weight);  // insere arco/aresta ao grafo
void removeVertice(Graph *G, const int num);                                    // remove vertice do grafo
void removeAdjacency(Graph *G, const int in, const int out);                    // remove arco/aresta do grafo  

#endif