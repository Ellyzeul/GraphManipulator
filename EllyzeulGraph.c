#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int info;                   // numeracao do vertice para onde aponta
    int weight;                 // possivel peso do vertice
    struct listNode *next;      // proximo da lista
};
typedef struct listNode LNode;

struct graphL {
    int *vertices;              // vetor de vertices
    LNode *adj;                 // lista de adjacencia
    int vNum;                   // quantidade de vertices
    int aNum;                   // quantidade de arestas/arcos
    short weighted;             // booleano para indicar se tem ou nao peso
};
typedef struct {
    int type;                   // indica o tipo de grafo a ser usado
    short weighted;             // booleano indicando se e ponderado
    union {
        struct graphL *graphL;  // 0 para grafo com lista de adjacencia
    };
} Graph;

struct graphL* allocGraphL(const short weighted, const int vNum) {
    struct graphL *G = calloc(1, sizeof(struct graphL));
    int num = (vNum != -1 ? vNum : 1);

    G->adj = calloc(num, sizeof(LNode));
    G->aNum = 0;
    G->vertices = calloc(num, sizeof(int));
    G->vNum = num;
    G->weighted = weighted;

    return G;
}
int* extendVector(const int *oldVec, int *oldLen, const int newLen){
    int *newVec, i;
    newVec = calloc(newLen+1, sizeof(int));

    for(i = 0; i <= *oldLen; i++)
        newVec[i] = oldVec[i];
    for(int j = i; j <= newLen; j++)
        newVec[j] = (j != newLen ? 0 : 1);
    
    *oldLen = newLen;
    return newVec;
}
void insertVerticeL(struct graphL *G, const int num) {
    puts("Entrou aqui");
    if(G->vNum < num) {
        puts("O vetor vai ser estendido");
        G->vertices = extendVector(G->vertices, &(G->vNum), num);
        puts("O vetor foi estendido");
        return;
    }
    puts("...");
    if(G->vertices[num] == 0){
        G->vNum++;puts("Incrementando vNum");}
    G->vertices[num] = 1;puts("Vertice adicionado");
}
Graph* allocGraph(const int type, const short weighted, const int vNum) {
    Graph *G = calloc(1, sizeof(Graph));
    if(type == 0)
        allocGraphL(weighted, vNum);
    G->type = type;
    G->weighted = weighted;

    return G;
}
void insertVertice(Graph *G, const int num) {
    G->type == 0
        ? insertVerticeL(G->graphL, num)
        : NULL;
}

int main() {
    int i = 1;
    Graph *graph = allocGraph(0, 0, -1);
    struct graphL *adjL = graph->graphL;

    insertVertice(graph, 1);
    printf("Teste %d: %s\n", i++, adjL->vertices[0] == 0 ? "Passou" : "Falhou");
    return 0;
}
  