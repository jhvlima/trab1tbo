#include "ioHandler.h"

int contarVertices(FILE* entrada){
    int count = 0;
    char c;
    fscanf(entrada, "%*[^\n]\n");
    while(1){
        fscanf(entrada, "%*[^,\n]%c", &c);
        if(c == '\n'){
            count++;
            break;
        }
        else{
            count++;
        }
    }
    rewind(entrada);
    printf("Contagem de vertices finalizada: %d\n", count);
    return count;
}

void lerArquivoEntrada(FILE* entrada, Graph* graph)
{
    printf("Lendo arquivo de Entrada\n");
    if(!graph || !entrada) exit(EXIT_FAILURE);

    char nomeBuffer[1001], sourceName[1001];
    int nVertices = contarVertices(entrada);
    graphSetSize(graph, nVertices);
    
    fscanf(entrada, "%[^\n]\n", sourceName);

    int dst = 0;
    float wgh = 0;

    for(int i = 0; i < nVertices; i++){
        printf("%d\n", i);
        fscanf(entrada, "%[^,]%*c", nomeBuffer);
        Vertice* vertice = verticeCreate(nomeBuffer, i);
        graphAddVertice(graph, vertice);
        if(strcmp(nomeBuffer, sourceName) == 0){
            graphSetSource(graph, i);
        }

        for(int j = 0; j < nVertices; j++){
            wgh = 0;
            if(i == j){
                graphAddAresta(graph, arestaCreate(i, j, wgh));
                continue;
            }
            fscanf(entrada, "%f", &wgh);
            fscanf(entrada, "%*[^,\n]");
            fscanf(entrada, "%*c");        
            if(wgh){
                Aresta* aresta = arestaCreate(i, j, wgh);
                graphAddAresta(graph, aresta);
            }
        }
    }
    printf("Leitura finalizada!");
    return;
}

void escreverArquivoSaida(FILE* saida, Node** arvoreMinima, Graph* graph)
{
    printf("Imprimindo Saidas\n");
    for(int i = 0; i < graphGetNVertices(graph); i++){
        Vertice* vertice = graphGetVertice(graph, i);
        fprintf(saida, "SHORTEST PATH TO %s: ", verticeGetName(vertice));

        if(i == graphGetSource(graph)){
            fprintf(saida, "%s <- %s (Distance: 0.00)\n", verticeGetName(vertice), verticeGetName(vertice));
            continue;
        }

        int leitor = i;
        while(leitor != graphGetSource(graph)){
            fprintf(saida, "%s <- ", verticeGetName(vertice));
            leitor = nodeGetPai(arvoreMinima[leitor]);
            vertice = graphGetVertice(graph, nodeGetId(arvoreMinima[leitor]));
        }
        fprintf(saida, "%s (Distance: %.2f)\n", verticeGetName(vertice), nodeGetDistancia(arvoreMinima[i]));
    }
    printf("Impressao finalizada\n");
}

void escreverSaidaTerminal(FILE* saida, Node** arvoreMinima, Graph* graph)
{
    for(int i = 0; i < graphGetNVertices(graph); i++){
        Vertice* vertice = graphGetVertice(graph, i);
        printf("SHORTEST PATH TO %s: ", verticeGetName(vertice));

        if(i == graphGetSource(graph)){
            printf("%s <- %s (Distance: 0.00)\n", verticeGetName(vertice), verticeGetName(vertice));
            continue;
        }

        int leitor = i;
        while(leitor != graphGetSource(graph)){
            printf("%s <- ", verticeGetName(vertice));
            leitor = nodeGetPai(arvoreMinima[leitor]);
            vertice = graphGetVertice(graph, nodeGetId(arvoreMinima[leitor]));
        }
        printf("%s (Distance: %.2f)\n", verticeGetName(vertice), nodeGetDistancia(arvoreMinima[i]));
    }
}
