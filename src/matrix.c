#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct __matrix{
    int source, size;
    char** nomeVertices;
    float** adjacencias;
}; 

Matrix* matrixCreate()
{
    Matrix* matrix = (Matrix*) malloc (sizeof(Matrix));
    matrix->nomeVertices = NULL;
    matrix->adjacencias = NULL;
    matrix->size = 0;
    return matrix;
}

void matrixSetSize(Matrix* matrix, int nVertices)
{
    matrix->size = nVertices;
    matrix->nomeVertices = (char**) malloc (nVertices * sizeof(char*));
    matrix->adjacencias = (float**) malloc (nVertices * sizeof(float*));
    for(int i = 0; i < nVertices; i++){
        matrix->adjacencias[i] = (float*) calloc (nVertices , sizeof(float));
    }
}

void matrixSetSource(Matrix* matrix, int id)
{
    matrix->source = id;
}

void matrixAddName(Matrix* matrix, char* nomeBuffer, int id)
{
    if(!matrix || !matrix->nomeVertices){
        return;
    }
    matrix->nomeVertices[id] = strdup(nomeBuffer);
}


void matrixSetValue(Matrix* matrix, int i, int j, float wgh)
{
    matrix->adjacencias[i][j] = wgh;
}

int matrixGetSize(Matrix* matrix)
{
    return matrix->size;
}

int matrixGetSource(Matrix* matrix)
{
    return matrix->source;
}

char* matrixGetNomeVertice(Matrix* matrix, int id)
{
    return matrix->nomeVertices[id];
}

float* matrixGetAdjacenciasId(Matrix* matrix, int id)
{
    return matrix->adjacencias[id];
}

void matrixDestroy(Matrix* matrix)
{
    if(!matrix) return;
    if(matrix->adjacencias && matrix->nomeVertices){
        for(int i = 0; i < matrix->size; i++){
            if(matrix->nomeVertices[i]){
                free(matrix->nomeVertices[i]);
            }
            if(matrix->adjacencias[i]){
                free(matrix->adjacencias[i]);
            }
        }
        free(matrix->nomeVertices);
        free(matrix->adjacencias);
    }
    free(matrix);
}

void matrixPrint(Matrix* matrix){
    printf("IMPRIMINDO MATRIZ DE ADJACENCIAS: (size: %d; source: %d)\n", matrix->size, matrix->source);
    for(int i = 0; i < matrix->size; i++){
        for(int j = 0; j < matrix->size; j++){
            printf("%.2f ", matrix->adjacencias[i][j]);
        }
        printf("\n");
    }
}
