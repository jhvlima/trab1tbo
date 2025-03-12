#ifndef HEAP_H
#define HEAP_H

typedef struct __node Node;
typedef struct __heap Heap;

//NODE --------------------------------------------
/*
    @brief Aloca dinamicamente um node
    @param idVert Id do vertice no grafo
    @param distancia (0 para fonte, -1 para demais)
    @return Node alocado
*/
Node* nodeCreate(int idVert, float distancia);

/*
    @brief Retorna distancia do vertice fonte ao vertice desse node
    @param node Node
    @return Distancia
*/
float nodeGetDistancia(Node* node);

/*
    @brief Retorna id do vertice pai do vertice desse node no grafo
    @param node Node
    @return Id do vertice pai
*/
int nodeGetPai(Node* node);

/*
    @brief Retorna id do vertice desse node no grafo
    @param node Node
    @return Id do vertice pai
*/
int nodeGetId(Node* node);

//HEAP ----------------------------------------------------------
/*
    @brief Aloca dinamicamente uma heap, incluindo seus nos e vetor de posicoes
    @param nVertices numero de vertices do grafo
    @param source Id do vertice fonte
    @return Heap alocada
*/
Heap* heapCreate(int nVertices, int source);

/*
    @brief Adiciona node a Heap
    @param heap Heap
    @param node Node
    @return
*/
void heapAddNode(Heap* heap, Node* node);

/*
    @brief Remove e retorna o nome com valor minimo da heap
    @param heap Heap
    @return Node com valor minimo
*/
Node* heapPopMin(Heap* heap);

/*
    @brief Altera valor da distancia do node, atualizando pai
    @param heap Heap
    @param pos Posicao do node com o vertice na heap
    @param distancia Nova distancia do node
    @param pai Id do pai do vertice no grafo
    @return
*/
void heapAtualizaDistancia(Heap* heap, int pos, float distancia, int pai);

/*
    @brief Retorna posicao do node do vertice na Heap
    @param heap Heap
    @param id Id do vertice no grafo
    @return posicao do node na Heap
*/
int heapSearchId(Heap* heap, int id);

/*
    @brief Verifica se a heap esta vazia
    @param heap Heap
    @return (1 se estiver vazia, 0 caso contrario)
*/
int heapIsEmpty(Heap* heap);

/*
    @brief Retorna distancia do vertice fonte a este vertice
    @param heap Heap
    @param id Id do vertice do node no grafo
    @return Distancia
*/
float heapGetDistancia(Heap* heap, int id);

/*
    @brief Desaloca heap, incluindo o vetor de posicoes e nodes
    @param heap Heap
    @return
*/
void heapDestroy(Heap* heap);

/*
    @brief Imprime heap no terminal
    @param heap Heap
    @return
*/
void heapPrint(Heap* heap);

#endif