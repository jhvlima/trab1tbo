#include "dijkstraMatrix.h"
#include <stdbool.h>

bool less(float x, float y) {
    if (y == -1) return true;  // y é infinito, logo x é menor
    if (x == -1) return false; // x é infinito, logo y é menor
    return x < y;
}

Node* extraiMin(float* distancias, Node** arvoreMin, int size)
{
    int idMin = -1;
    float value = -1;
    for(int i = 0; i < size; i++){
        if (!arvoreMin[i] && (distancias[i] != -1 && less(distancias[i], value))) {
            idMin = i;
            value = distancias[i];
        }
    }
    if(idMin < 0){
        return NULL;
    }
    Node* node = nodeCreate(idMin, value);

    return node;
}

void relaxarArestas(Matrix* matrix, float* distancias, int idPai, int* pais, Node** arvoreMin)
{
    float* adjacencias = matrixGetAdjacenciasId(matrix, idPai);
    for(int i = 0; i < matrixGetSize(matrix); i++){
        if(arvoreMin[i] || adjacencias[i] == -1){
            continue;
        }
        float distPai = distancias[idPai];
        float novaDist = distPai + adjacencias[i];
        //printf("%d -[%.2f]-> %d || %.2f < %.2f?\n", idPai, adjacencias[i], i, novaDist, distancias[i]);
        if (distancias[i] == -1 || distancias[i] > novaDist) {
            //printf("TROCA\n");
            distancias[i] = novaDist;
            pais[i] = idPai;
        }
    }
}

Node** dijkstraMatrix(Matrix* matrix)
{
    int size = matrixGetSize(matrix);
    int source = matrixGetSource(matrix);

    Node** arvoreMin = (Node**) calloc (size, sizeof(Node*));

    int* pais = (int*) malloc (size * sizeof(int));
    float* distancias = (float*) malloc (size * sizeof(float));

    for(int i = 0; i < size; i++){
        pais[i] = -1;
        distancias[i] = -1;
    }

    distancias[source] = 0;
    pais[source] = source;

    for (int i = 0; i < size; i++){
        Node* min = extraiMin(distancias, arvoreMin, size);
        if(!min){
            break;
        }
        int idMin = nodeGetId(min);
        nodeSetPai(min, pais[idMin]);
        //printf("\nmin: %d(%d)\n", idMin, nodeGetPai(min));
        
        arvoreMin[idMin] = min;

        relaxarArestas(matrix, distancias, idMin, pais, arvoreMin);

    }
    free(pais);
    free(distancias);

    return arvoreMin;
}

int resolveComDijkstraMatrix(char* entradaPath, char* saidaPath)
{
    FILE *entrada = fopen(entradaPath, "r");
    if (entrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada: %s\n", entradaPath);
        return 1;
    }

    FILE *saida = fopen(saidaPath, "w");
    if (saida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída\n");
        return 1;
    }

    Matrix* matrix = matrixCreate();
    lerArquivoEntradaMatrixToken(entrada, matrix);
    //matrixPrint(matrix);

    Node** arvoreMinima = dijkstraMatrix(matrix);

    escreverArquivoSaidaMatrix(saida, arvoreMinima, matrix);
    //escreverSaidaTerminalMatrix(arvoreMinima, matrix);

    nodeDestroyArvoreMinima(arvoreMinima, matrixGetSize(matrix));

    matrixDestroy(matrix);

    fclose(entrada);
    fclose(saida);
    return 0;
}