#ifndef MATRIX_H
#define MATRIX_H

#include "node.h"

typedef struct __matrix Matrix;

Matrix* matrixCreate();
void matrixAddName(Matrix* matrix, char* nomeBuffer, int id);
void matrixSetSource(Matrix* matrix, int id);
void matrixSetValue(Matrix* matrix, int i, int j, float wgh);
void matrixDestroy(Matrix* matrix);
void matrixPrint(Matrix* matrix);


#endif