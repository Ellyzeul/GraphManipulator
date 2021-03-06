#include "GraphL.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

struct graphL* allocGraphL(const short weighted, const int vNum) {
    struct graphL *G = calloc(1, sizeof(struct graphL));
    int num = (vNum != -1 ? vNum : 0);

    G->adj = calloc(num, sizeof(LNode));
    G->aNum = 0;
    G->vertices = calloc(num, sizeof(int));
    G->vNum = num;
    G->weighted = weighted;

    return G;
}
void insertVerticeL(struct graphL *G, const int num, const int weight) {
    if(G->vNum < num) {
        G->vertices = extendVector(G->vertices, &(G->vNum), num);
        return;
    }
    if(G->vertices[num] == 0)
        G->vNum++;
    G->vertices[num] = 1;
}
void insertAdjacencyL(struct graphL *G, const int in, const int out) {

}
void removeVerticeL(struct graphL *G, const int num) {
    if(G->vertices[num] == 1)
        G->vNum--;
    G->vertices[num] = 0;
}
void removeAdjacencyL(struct graphL *G, const int in, const int out) {

}