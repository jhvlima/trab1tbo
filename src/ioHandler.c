#include "ioHandler.h"

void lerArquivoEntrada(FILE* entrada, Graph* graph)
{
    if(!graph || !entrada) exit(EXIT_FAILURE);

    int id = 0;
    fscanf(entrada, "node_%d\n", &id);
    graphSetSource(graph, id);

    int dst = 0, size = 0;
    float wgh = 0;
    fscanf(entrada, "node_%d,", &id);
    while(fscanf(entrada, "%f%*c", &wgh) == 1){
        Aresta* aresta = arestaCreate(id, dst, wgh);
        graphAddAresta(graph, aresta);
        dst++;
    }
    size = dst + 1;

    for(int i = 1; i < size; i++){
        fscanf(entrada, "node_%d,", &id);
        for(int j = 0; j < size; j++){
            fscanf(entrada, "%f%*c", &wgh);
            Aresta* aresta = arestaCreate(id, j, wgh);
            graphAddAresta(graph, aresta);
        }
    }
    return;
}
