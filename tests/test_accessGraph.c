#include "../src/Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
    Graph *graph = allocGraph(0, 0, -1);

    assert(graph->type == 0);
    assert(graph->graphL->vNum == 0);
}