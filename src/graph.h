//Autoria:
//Daniel Corona de Aguiar (2023101578)
//João Henrique Valbusa Lima (2023100583)

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __aresta Aresta;
typedef struct __vertice Vertice;
typedef struct __graph Graph;

//ARESTA --------------------------------------
/*
    @brief Aloca dinamicamente uma aresta
    @param src Id do vertice de origem da aresta
    @param dst Id do vertice de destino da aresta
    @param wgh Peso da aresta
    @return Aresta alocada
*/
Aresta* arestaCreate(int src, int dst, float wgh);

/*
    @brief Retorna aresta seguinte da lista de adjacencias
    @param aresta Aresta atual
    @return Aresta seguinte
*/
Aresta* arestaGetNext(Aresta* aresta);

/*
    @brief Retorna id do vertice de destino da aresta
    @param aresta Aresta
    @return Id do vertice de destino
*/
int arestaGetDst(Aresta* aresta);

/*
    @brief Retorna peso da aresta
    @param aresta Aresta
    @return Peso da aresta
*/
float arestaGetPeso(Aresta* aresta);

/*
    @brief Desaloca lista de adjacencias a partir da primeira aresta
    @param aresta Primeira aresta da lista de adjacencias
    @return
*/
void arestaNextsDestroy(Aresta* aresta);

//VERTICE -------------------------------------------
/*
    @brief Aloca dinamicamente um vertice
    @param nome Nome do vertice
    @param id Id do vertice
    @return Vertice alocado
*/
Vertice* verticeCreate(char* nome, int id);

/*
    @brief Retorna nome do vertice
    @param vertice Vertice
    @return Nome do vertice
*/
char* verticeGetName(Vertice* vertice);

/*
    @brief Desaloca vertice
    @param vertice Vertice
    @return
*/
void verticeDestroy(Vertice* vertice);

//GRAPH ---------------------------------------------
/*
    @brief Aloca dinamicamente um grafo vazio 
    @param 
    @return Grafo vazio
*/
Graph* graphCreate();

/*
    @brief Adiciona aresta a lista de adjacencias do grafo 
    @param graph Grafo
    @param aresta Aresta a ser adicionada
    @return 
*/
void graphAddAresta(Graph* graph, Aresta* aresta);

/*
    @brief Adiciona vertice ao vetor de vertices do grafo 
    @param graph Grafo
    @param vertice Vertice a ser adicionado
    @return 
*/
void graphAddVertice(Graph* graph, Vertice* vertice);

/*
    @brief Retorna id do vertice fonte do grafo
    @param graph Grafo
    @return Id do vertice fonte do grafo
*/
int graphGetSource(Graph* graph);

/*
    @brief Retorna numero de vertices do grafo
    @param graph Grafo
    @return Numero de vertices do grafo
*/
int graphGetNVertices(Graph* graph);

/*
    @brief Retorna o vertice correspondente ao id no vetor de vertices do grafo
    @param graph Grafo
    @param id Id do vertice no vetor de vertices do grafo
    @return Vertice correspondente ao Id
*/
Vertice* graphGetVertice(Graph* graph, int id);

/*
    @brief Retorna a lista de adjacencias do vertice correspondente ao id no vetor de vertices do grafo
    @param graph Grafo
    @param id Id do vertice no vetor de vertices do grafo
    @return Primeira aresta da lista de adjacencias
*/
Aresta* graphGetAdjacencias(Graph* graph, int id);

/*
    @brief Define id do vertice fonte do grafo
    @param graph Grafo
    @param src Id do vertice fonte
    @return
*/
void graphSetSource(Graph* graph, int src);

/*
    @brief Define numero de vertices do grafo, alocando dinamicamente memoria para as adjacencias e vertices
    @param graph Grafo
    @param size Numero de Vertices
    @return
*/
void graphSetSize(Graph* graph, int size);


/*
    @brief Imprime grafo no terminal
    @param graph Grafo
    @return
*/
void graphPrint(Graph* graph);

/*
    @brief Desaloca grafo, incluindo adjacencias e vertices
    @param graph Grafo
    @return
*/
void graphDestroy(Graph* graph);



#endif
