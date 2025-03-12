#include "ioHandler.h"

/*
    @brief Le arquivo de entrada para contar o numero de vertices
    @param entrada Arquivo de entrada
    @return Numero de vertices
*/
int contarVertices(FILE* entrada){
    int count = 0;
    char c;
    fscanf(entrada, "%*[^\n]\n"); //ignora primeira linha (vertice de origem)

    char *linha = NULL;
    size_t tamanho = 0;
    if (getline(&linha, &tamanho, entrada) == -1){
        free(linha);
        return 0;
    }
    char *token = strtok(linha, ",\n");
    count++;

    while (token = strtok(NULL, ",\n")){
        count++;
    }

    free(linha);
    rewind(entrada);

    //printf("Contagem de vertices finalizada: %d\n", count);

    return count;
}

void lerArquivoEntrada(FILE* entrada, Graph* graph)
{
    //printf("Lendo arquivo de Entrada\n");
    if(!graph || !entrada){
        printf("Erro: lerArquivoEntrada\n");
        exit(EXIT_FAILURE);
    }

    char nomeBuffer[1001], sourceName[1001];

    int nVertices = contarVertices(entrada);
    graphSetSize(graph, nVertices);
    
    //Le nome do vertice fonte
    fscanf(entrada, "%[^\n]\n", sourceName);

    int dst = 0;
    float wgh = 0;

    for(int i = 0; i < nVertices; i++){
        //Le nome do vertice, se for fonte define seu id no grafo
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
            fscanf(entrada, "%*[^,\n]"); //ignora bomba
            fscanf(entrada, "%*c");      //remove ',' ou '\n'
            if(wgh){
                Aresta* aresta = arestaCreate(i, j, wgh);
                graphAddAresta(graph, aresta);
            }
        }
    }
    //printf("Leitura finalizada!");
    return;
}

void lerArquivoEntradaToken(FILE* entrada, Graph* graph) {
    //printf("Lendo arquivo de Entrada\n");
    if(!graph || !entrada){
        printf("Erro: lerArquivoEntrada\n");
        exit(EXIT_FAILURE);
    }

    char *linha = NULL;
    size_t tamanho = 0;
    char nomeBuffer[1001], sourceName[1001];

    int nVertices = contarVertices(entrada);
    graphSetSize(graph, nVertices);

    // Le nome do vertice fonte
    if (getline(&linha, &tamanho, entrada) == -1) {
        free(linha);
        return;
    }
    sscanf(linha, "%1000[^\n]", sourceName);

    //Para cada vertice
    for (int i = 0; i < nVertices; i++) {
        if (getline(&linha, &tamanho, entrada) == -1) break;

        //Le nome do vertice, se for o fonte define seu id no grafo
        char *token = strtok(linha, ",\n");
        if (!token) continue;

        while (*token == ' ') token++;
        strncpy(nomeBuffer, token, 1000);
        nomeBuffer[1000] = '\0'; 

        Vertice* vertice = verticeCreate(nomeBuffer, i);
        graphAddVertice(graph, vertice);

        if (strcmp(nomeBuffer, sourceName) == 0) {
            graphSetSource(graph, i);
        }

        //Para cada adjacencia do vertice
        int j = 0;
        while ((token = strtok(NULL, ",\n")) && j < nVertices) {
            while (*token == ' ') token++; 
            float wgh = 0;

            //ignora se for "bomba" ou qualquer outra palavra, mantendo wgh 0
            if(!isalpha(token[0])) {
                wgh = strtof(token, NULL);
            }

            //aresta do vertice para ele mesmo com distancia 0
            if (i == j) {  
                graphAddAresta(graph, arestaCreate(i, j, 0));
                j++;
            }

            if (wgh > 0) {  
                Aresta* aresta = arestaCreate(i, j, wgh);
                graphAddAresta(graph, aresta);
            }

            j++;
        }
    }

    free(linha);
    //printf("Leitura finalizada!\n");
}

void escreverArquivoSaida(FILE* saida, Node** arvoreMinima, Graph* graph)
{
    //printf("Imprimindo Saidas\n");
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
    //printf("Impressao finalizada\n");
}

void escreverSaidaTerminal(Node** arvoreMinima, Graph* graph)
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
