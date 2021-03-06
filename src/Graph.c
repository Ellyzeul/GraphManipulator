#include "Graph.h"
#include "GraphL.h"
#include <stdio.h>
#include <stdlib.h>

Graph* allocGraph(const int type, const short weighted) {
    Graph *G = calloc(1, sizeof(Graph));
    if(type == 0)
        G->graphL = allocGraphL(weighted);
    G->type = type;
    G->weighted = weighted;

    return G;
}
void insertVertice(Graph *G, const int num) {
    G->type == 0
        ? insertVerticeL(G->graphL, num)
        : NULL;
}
void insertAdjacency(Graph *G, const int in, const int out, const int weight) {
    G->type == 0
        ? insertAdjacencyL(G->graphL, in, out, weight)
        : NULL;
}
void removeVertice(Graph *G, const int num) {
    G->type == 0
        ? removeVerticeL(G->graphL, num)
        : NULL;
}
void removeAdjacency(Graph *G, const int in, const int out) {
    G->type == 0
        ? removeAdjacencyL(G->graphL, in, out)
        : NULL;
}