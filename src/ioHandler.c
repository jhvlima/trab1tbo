#include "ioHandler.h"

void lerArquivoEntrada(FILE* entrada, Graph* graph)
{
    if(!graph || !entrada) exit(EXIT_FAILURE);

    int id = 0;
    fscanf(entrada, "%*[^0-9]%d\n", &id);
    graphSetSource(graph, id);

    int dst = 0, size = 0;
    float wgh = 0;
    fscanf(entrada, "%*[^0-9]%d%*c", &id);
    if(id == dst){
        graphAddAresta(graph, arestaCreate(id, dst, 0)); //Adiciona aresta 0-> 0
        dst++;
    }
    while(fscanf(entrada, "%f%*c", &wgh) == 1){
        Aresta* aresta = arestaCreate(id, dst, wgh);
        graphAddAresta(graph, aresta);
        dst++;
    }
    size = dst;

    for(int i = 1; i < size; i++){
        fscanf(entrada, "%*[^0-9]%d%*c", &id);
        for(int j = 0; j < size; j++){
            if(id == j){
                graphAddAresta(graph, arestaCreate(id, j, 0));
                continue;
            }
            fscanf(entrada, "%f%*c", &wgh);
            Aresta* aresta = arestaCreate(id, j, wgh);
            graphAddAresta(graph, aresta);
        }
    }
    return;
}
