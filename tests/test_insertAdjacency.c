#include "../src/Graph.h"
#include "../src/GraphL.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    Graph *graph = allocTestGraph(0, 0);
    struct graphL *adjL = graph->graphL;

    insertVertice(graph, 1);
    insertVertice(graph, 3);
    insertVertice(graph, 10);
    insertVertice(graph, 4);
    insertAdjacency(graph, 1, 3, 14);
    insertAdjacency(graph, 1, 4, 6);
    insertAdjacency(graph, 1, 4, 11);
    insertAdjacency(graph, 1, 2, 7);
    insertAdjacency(graph, 5, 10, 20);
    insertAdjacency(graph, 5, 2, 19);
    insertAdjacency(graph, 4, 1, 10);

    test(adjL->vertices[2] == 0);
    test(adjL->vertices[5] == 0);
    test(adjL->adj[1].info == 3);
    test(adjL->adj[1].weight == 14);
    test(adjL->adj[1].next->info == 4);
    test(adjL->adj[1].next->weight == 6);
    test(adjL->adj[1].next->next->info == 4);
    test(adjL->adj[1].next->next->weight == 11);
    test(adjL->adj[1].next->next->next->next == NULL);
    test(adjL->adj[4].info == 1);
    test(adjL->adj[5].info == 0);
    test(adjL->adj[5].next->next == NULL);

    return 0;
}