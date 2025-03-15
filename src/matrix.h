#ifndef MATRIX_H
#define MATRIX_H

#include "node.h"

typedef struct __matrix Matrix;

/*
 *   @brief Aloca dinamicamente uma matriz
 *   @return Matriz alocada
 */
Matrix *matrixCreate();

/*
 *  @brief Adiciona o nome de um vértice à matriz
 *  @param matrix Matriz
 *  @param nomeBuffer Nome do vértice
 *  @param id Id do vértice
 */
void matrixAddName(Matrix *matrix, char *nomeBuffer, int id);

/*
 *  @brief Define o tamanho da matriz
 *  @param matrix Matriz
 *  @param nVertices Número de vértices
 */
void matrixSetSize(Matrix *matrix, int nVertices);

/*
 *  @brief Define o vértice fonte da matriz
 *  @param matrix Matriz
 *  @param id Id do vértice fonte
 */
void matrixSetSource(Matrix *matrix, int id);

/*
 *  @brief Define o valor de uma aresta na matriz
 *  @param matrix Matriz
 *  @param i Índice do vértice de origem
 *  @param j Índice do vértice de destino
 *  @param wgh Peso da aresta
 */
void matrixSetValue(Matrix *matrix, int i, int j, float wgh);

/*
 *   @brief Retorna o tamanho da matriz
 *   @param matrix Matriz
 *   @return Número de vértices
 */
int matrixGetSize(Matrix *matrix);

/*
 *   @brief Retorna o vértice fonte da matriz
 *   @param matrix Matriz
 *   @return Id do vértice fonte
 */
int matrixGetSource(Matrix *matrix);

/*
 *   @brief Retorna o nome de um vértice na matriz
 *   @param matrix Matriz
 *   @param id Id do vértice
 *   @return Nome do vértice
 */
char *matrixGetNomeVertice(Matrix *matrix, int id);

/*
 *   @brief Retorna as adjacências de um vértice na matriz
 *   @param matrix Matriz
 *   @param id Id do vértice
 *   @return Ponteiro para os pesos das arestas adjacentes
 */
float *matrixGetAdjacenciasId(Matrix *matrix, int id);

/*
 *  @brief Desaloca a matriz
 *  @param matrix Matriz
 */
void matrixDestroy(Matrix *matrix);

/*
 *   @brief Imprime a matriz
 *   @param matrix Matriz
 */
void matrixPrint(Matrix *matrix);

#endif
