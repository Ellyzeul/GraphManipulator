#include "../src/Graph.h"
#include "../src/GraphL.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    Graph *graph = allocTestGraph(0, 0);
    struct graphL *adjL = graph->graphL;
    LNode* adj = adjL->adj;

    test(graph->type == 0);
    test(adjL->vNum == 0);
    test(adjL->aNum == 0);
    test(adjL->vertices[0] == 0);
    test(adj[0].info == 0);

    return 0;
}