#ifndef __ELLYZ__GRAPH_MANIPULATOR__GRAPHL__
#define __ELLYZ__GRAPH_MANIPULATOR__GRAPHL__

struct listNode {
    int info;                   // numeracao do vertice para onde aponta
    int weight;                 // possivel peso do vertice
    struct listNode *next;      // proximo da lista
};
typedef struct listNode LNode;

struct graphL {
    int *vertices;              // vetor booleano de vertices
    LNode *adj;                 // lista de adjacencia
    int vNum;                   // quantidade de vertices
    int aNum;                   // quantidade de arestas/arcos
    int vLen;                   // variavel de controle do tamanho do vetor de vertices
    int aLen;                   // variavel de controle do tamanho do vetor de adjacencia
    short weighted;             // booleano para indicar se tem ou nao peso
};

struct graphL* allocGraphL(const short weighted);
void insertVerticeL(struct graphL *G, const int num);
void insertAdjacencyL(struct graphL *G, const int in, const int out, const int weight);
void removeVerticeL(struct graphL *G, const int num);
void removeAdjacencyL(struct graphL *G, const int in, const int out);

#endif