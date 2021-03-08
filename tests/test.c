#include "../src/Graph.h"
#include "../src/GraphL.h"
#include "../src/ANSI-color-codes.h"
#include "test.h"
#include <stdio.h>

void test(const short expr) {
    static int i = 1;
    printf("Teste %d: ", i++);
    if(expr) {
        printf(BGRN "Passou\n" reset);
        return;
    }
    printf(BRED "Falhou\n" reset);
}

Graph* allocTestGraph(const int type, const short weighted) {
    return allocGraph(type, weighted);
}