#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct __matrix{
    int source, size;
    char** nomeVertices;
    float** adjacencias;
}; 

Matrix* matrixCreate() {
    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
    if (!matrix) {
        fprintf(stderr, "Error: Não foi possivel alocar a matriz.\n");
        exit(EXIT_FAILURE);
    }
    matrix->nomeVertices = NULL;
    matrix->adjacencias = NULL;
    matrix->size = 0;
    return matrix;
}

void matrixSetSize(Matrix* matrix, int nVertices) {
    if (!matrix) return;

    // Free existing allocations if any
    if (matrix->nomeVertices) {
        for (int i = 0; i < matrix->size; i++) {
            if (matrix->nomeVertices[i]) free(matrix->nomeVertices[i]);
        }
        free(matrix->nomeVertices);
    }
    if (matrix->adjacencias) {
        for (int i = 0; i < matrix->size; i++) {
            if (matrix->adjacencias[i]) free(matrix->adjacencias[i]);
        }
        free(matrix->adjacencias);
    }

    // Allocate new memory
    matrix->size = nVertices;
    matrix->nomeVertices = (char**) malloc(nVertices * sizeof(char*));
    matrix->adjacencias = (float**) malloc(nVertices * sizeof(float*));
    if (!matrix->nomeVertices || !matrix->adjacencias) {
        fprintf(stderr, "Error: Unable to allocate memory for matrix.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < nVertices; i++) {
        matrix->adjacencias[i] = (float*) calloc(nVertices, sizeof(float));
        if (!matrix->adjacencias[i]) {
            fprintf(stderr, "Error: Unable to allocate memory for matrix.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void matrixSetSource(Matrix* matrix, int id) {
    if (!matrix || id < 0 || id >= matrix->size) {
        fprintf(stderr, "Error: Invalid source vertex ID.\n");
        return;
    }
    matrix->source = id;
}

void matrixAddName(Matrix* matrix, char* nomeBuffer, int id) {
    if (!matrix || !matrix->nomeVertices || id < 0 || id >= matrix->size) {
        fprintf(stderr, "Error: Invalid matrix or vertex ID.\n");
        return;
    }
    matrix->nomeVertices[id] = strdup(nomeBuffer);
    if (!matrix->nomeVertices[id]) {
        fprintf(stderr, "Error: Unable to allocate memory for vertex name.\n");
        exit(EXIT_FAILURE);
    }
}


void matrixSetValue(Matrix* matrix, int i, int j, float wgh) {
    if (!matrix || i < 0 || i >= matrix->size || j < 0 || j >= matrix->size) {
        fprintf(stderr, "Error: Invalid vertex indices.\n");
        return;
    }
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
