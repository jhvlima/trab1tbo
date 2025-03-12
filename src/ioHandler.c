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
    while(1){
        if(fscanf(entrada, "%f%*c", &wgh) != 1){
            char c;
            fscanf(entrada,"%c", &c);
            if (c == 'b'){
                fscanf(entrada, "%*[^\n ]%*c");
                wgh = 0;
            }
            else{
                break;
            }
        }
        if(wgh){
            Aresta* aresta = arestaCreate(id, dst, wgh);
            graphAddAresta(graph, aresta);
        }
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
            if(fscanf(entrada, "%f%*c", &wgh) != 1){
                fscanf(entrada, "%*[^\n ]%*c");
                wgh = 0;
            }        
            if(wgh){
                Aresta* aresta = arestaCreate(id, j, wgh);
                graphAddAresta(graph, aresta);
            }
        }
    }
    return;
}

void escreverArquivoSaida(FILE* saida, Node** arvoreMinima, Graph* graph)
{
    for(int i = 0; i < graphGetNVertices(graph); i++){
        fprintf(saida, "SHORTEST PATH TO node_%d: ", i);

        if(i == graphGetSource(graph)){
            fprintf(saida, "node_%d <- node_%d (Distance: 0.00)\n", i, i);
            continue;
        }

        int leitor = i;
        while(leitor != graphGetSource(graph)){
            fprintf(saida, "node_%d <- ", nodeGetId(arvoreMinima[leitor]));
            leitor = nodeGetPai(arvoreMinima[leitor]);
        }
        fprintf(saida, "node_%d (Distance: %.2f)\n", nodeGetId(arvoreMinima[leitor]), nodeGetDistancia(arvoreMinima[i]));
    }
}

void escreverSaidaTerminal(FILE* saida, Node** arvoreMinima, Graph* graph)
{
    for(int i = 0; i < graphGetNVertices(graph); i++){
        printf("SHORTEST PATH TO node_%d: ", i);

        if(i == graphGetSource(graph)){
            printf("node_%d <- node_%d (Distance: 0.00)\n", i, i);
            continue;
        }

        int leitor = i;
        while(leitor != graphGetSource(graph)){
            printf("node_%d <- ", nodeGetId(arvoreMinima[leitor]));
            leitor = nodeGetPai(arvoreMinima[leitor]);
        }
        printf("node_%d (Distance: %.2f)\n", nodeGetId(arvoreMinima[leitor]), nodeGetDistancia(arvoreMinima[i]));
    }
}
