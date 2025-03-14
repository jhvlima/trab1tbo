#ifndef NODE_H
#define NODE_H

typedef struct __node Node;

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

/*
    @brief Define distancia do node
    @param node Node
    @param distancia Distancia
    @return 
*/
void nodeSetDistancia(Node* node, int distancia);

/*
    @brief Define vertice pai do node
    @param node Node
    @param pai Id do vertice pai no grafo
    @return 
*/
void nodeSetPai(Node* node, int pai);

/*
    @brief Desaloca arvore minima (vetor de nodes)
    @param arvoreMinima Arvores Minimas;
    @param nVertices Numero de vertices
    @return
*/
void nodeDestroyArvoreMinima(Node** arvoreMinima, int nVertices);

#endif
