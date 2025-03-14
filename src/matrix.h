#ifndef MATRIX_H
#define MATRIX_H

#include "node.h"

typedef struct __matrix Matrix;

Matrix* matrixCreate();
void matrixAddName(Matrix* matrix, char* nomeBuffer, int id);
void matrixSetSize(Matrix* matrix, int nVertices);
void matrixSetSource(Matrix* matrix, int id);
void matrixSetValue(Matrix* matrix, int i, int j, float wgh);
int matrixGetSize(Matrix* matrix);
int matrixGetSource(Matrix* matrix);
char* matrixGetNomeVertice(Matrix* matrix, int id);
float* matrixGetAdjacenciasId(Matrix* matrix, int id);
void matrixDestroy(Matrix* matrix);
void matrixPrint(Matrix* matrix);


#endif