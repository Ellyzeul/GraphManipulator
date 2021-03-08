#include "GraphL.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

struct graphL* allocGraphL(const short weighted) {
    struct graphL *G = calloc(1, sizeof(struct graphL));

    G->vertices = calloc(1, sizeof(int));
    G->adj = calloc(1, sizeof(LNode));
    G->adj[0].next = NULL;
    G->vNum = 0;
    G->aNum = 0;
    G->vLen = 0;
    G->aLen = 0;
    G->weighted = weighted;

    return G;
}
void insertVerticeL(struct graphL *G, const int num) {
    if(G->vNum < num) 
        G->vertices = extendIntVector(G->vertices, &(G->vLen), num);
    if(G->vertices[num] == 0)
        G->vNum++;
    G->vertices[num] = 1;
}
void insertAdjacencyL(struct graphL *G, const int in, const int out, const int weight) {
    LNode *node;
    if(G->vertices[in] == 0 || G->vertices[out] == 0)
        return;
    if(G->aNum < in)
        G->adj = extendLNodeVector(G->adj, &(G->aLen), in);
    for(node = &(G->adj[in]); node->next != NULL; node = node->next)
        continue;
    node->info = out;
    node->weight = (weight != -1 ? weight : 0);
    node->next = calloc(1, sizeof(LNode));
    node->next->next = NULL;
    G->aNum++;
}
void removeVerticeL(struct graphL *G, const int num) {
    if(G->vertices[num] == 1)
        G->vNum--;
    G->vertices[num] = 0;
}
void removeAdjacencyL(struct graphL *G, const int in, const int out) {
    LNode *node, *prev;
    prev = NULL;
    for(node = &(G->adj[in]); node->next != NULL; node = node->next) {
        if(node->info == out) {
            G->aNum--;
            if(prev == NULL) {
                G->adj[in].info = G->adj[in].weight = 0;
                return;
            }
            prev->next = node->next;
            free(node);
            return;
        }
        prev = node;
    }
}