#include "../src/Graph.h"
#include "../src/GraphL.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Graph *graph = allocTestGraph(0, 0);
    struct graphL *adjL = graph->graphL;

    insertVertice(graph, 1);
    test(adjL->vertices[0] == 0);
    test(adjL->vertices[1] == 1);

    insertVertice(graph, 3);
    test(adjL->vertices[0] == 0);
    test(adjL->vertices[1] == 1);
    test(adjL->vertices[2] == 0);
    test(adjL->vertices[3] == 1);

    insertVertice(graph, 10);
    insertVertice(graph, 4);
    test(adjL->vertices[1] == 1);
    test(adjL->vertices[3] == 1);
    test(adjL->vertices[4] == 1);
    test(adjL->vertices[6] == 0);
    test(adjL->vertices[10] == 1);

    return 0;
}