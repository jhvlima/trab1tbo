#include "ioHandler.h"
#include "matrix.h"
/*
    @brief Le arquivo de entrada para contar o numero de vertices
    @param entrada Arquivo de entrada
    @return Numero de vertices
*/
int contarVertices(FILE* entrada){
    int count = 0;
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

void lerArquivoEntradaGraph(FILE* entrada, Graph* graph)
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

void lerArquivoEntradaGraphToken(FILE* entrada, Graph* graph) {
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

void lerArquivoEntradaMatrixToken(FILE* entrada, Matrix* matrix)
{
    //printf("Lendo arquivo de Entrada\n");
    if(!matrix || !entrada){
        printf("Erro: lerArquivoEntrada\n");
        exit(EXIT_FAILURE);
    }

    char *linha = NULL;
    size_t tamanho = 0;
    char nomeBuffer[1001], sourceName[1001];

    int nVertices = contarVertices(entrada);
    matrixSetSize(matrix, nVertices);

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
        if (!token){
            printf("\n!token\n");
            continue;
        } 

        while (*token == ' ') token++;
        strncpy(nomeBuffer, token, 1000);
        nomeBuffer[1000] = '\0'; 

        matrixAddName(matrix, nomeBuffer, i);

        if (strcmp(nomeBuffer, sourceName) == 0) {
            matrixSetSource(matrix, i);
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
                matrixSetValue(matrix, i, j, 0);
                j++;
            }

            if (wgh > 0) {  
                matrixSetValue(matrix, i, j, wgh);
            }

            else if (wgh == 0){
                matrixSetValue(matrix, i, j, -1);
            }
            j++;
        }
    }

    free(linha);
    //printf("Leitura finalizada!\n");
}

// Estrutura para armazenar caminho e distância
typedef struct {
    double distancia;
    int idVertice;
} Caminho;

// Função de comparação para qsort (ordena da menor para a maior distância)
int compararCaminhos(const void* a, const void* b) {
    Caminho* caminhoA = (Caminho*)a;
    Caminho* caminhoB = (Caminho*)b;
    if (caminhoA->distancia < caminhoB->distancia) return -1;
    if (caminhoA->distancia > caminhoB->distancia) return 1;
    return 0;
}

void escreverArquivoSaidaGraph(FILE* saida, Node** arvoreMinima, Graph* graph)
{
    int nVertices = graphGetNVertices(graph);

    // Cria um array para armazenar os caminhos e distâncias
    Caminho* caminhos = (Caminho*) malloc(nVertices * sizeof(Caminho));
    if (!caminhos) {
        fprintf(stderr, "Erro ao alocar memória para caminhos.\n");
        return;
    }

    // Preenche o array com as distâncias e IDs dos vértices
    for (int i = 0; i < nVertices; i++) {
        caminhos[i].distancia = nodeGetDistancia(arvoreMinima[i]);
        caminhos[i].idVertice = i;
    }

    // Ordena o array por distância (da menor para a maior)
    qsort(caminhos, nVertices, sizeof(Caminho), compararCaminhos);

    // Imprime os caminhos ordenados
    for (int i = 0; i < nVertices; i++) {
        int idVertice = caminhos[i].idVertice;
        Vertice* vertice = graphGetVertice(graph, idVertice);
        fprintf(saida, "SHORTEST PATH TO %s: ", verticeGetName(vertice));

        if (idVertice == graphGetSource(graph)) {
            fprintf(saida, "%s <- %s (Distance: 0.00)\n", verticeGetName(vertice), verticeGetName(vertice));
            continue;
        }

        int leitor = idVertice;
        while (leitor != graphGetSource(graph)) {
            fprintf(saida, "%s <- ", verticeGetName(graphGetVertice(graph, leitor)));
            leitor = nodeGetPai(arvoreMinima[leitor]);
        }
        fprintf(saida, "%s (Distance: %.2f)\n", verticeGetName(graphGetVertice(graph, leitor)), caminhos[i].distancia);
    }

    // Libera a memória alocada para o array de caminhos
    free(caminhos);
}

void escreverSaidaTerminalGraph(Node** arvoreMinima, Graph* graph)
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

void escreverArquivoSaidaMatrix(FILE* saida, Node** arvoreMinima, Matrix* matrix)
{
    int size = matrixGetSize(matrix);

    // Cria um array para armazenar os caminhos e distâncias
    Caminho* caminhos = (Caminho*) malloc(size * sizeof(Caminho));
    if (!caminhos) {
        fprintf(stderr, "Erro ao alocar memória para caminhos.\n");
        return;
    }

    // Preenche o array com as distâncias e IDs dos vértices
    for (int i = 0; i < size; i++) {
        caminhos[i].distancia = nodeGetDistancia(arvoreMinima[i]);
        caminhos[i].idVertice = i;
    }

    // Ordena o array por distância (da menor para a maior)
    qsort(caminhos, size, sizeof(Caminho), compararCaminhos);

    // Imprime os caminhos ordenados
    for (int i = 0; i < size; i++) {
        int idVertice = caminhos[i].idVertice;
        fprintf(saida, "SHORTEST PATH TO %s: ", matrixGetNomeVertice(matrix, idVertice));

        if (idVertice == matrixGetSource(matrix)) {
            fprintf(saida, "%s <- %s (Distance: 0.00)\n", matrixGetNomeVertice(matrix, idVertice), matrixGetNomeVertice(matrix, idVertice));
            continue;
        }

        int leitor = idVertice;
        while (leitor != matrixGetSource(matrix)) {
            fprintf(saida, "%s <- ", matrixGetNomeVertice(matrix, leitor));
            leitor = nodeGetPai(arvoreMinima[leitor]);
        }
        fprintf(saida, "%s (Distance: %.2f)\n", matrixGetNomeVertice(matrix, leitor), caminhos[i].distancia);
    }

    // Libera a memória alocada para o array de caminhos
    free(caminhos);
}

void escreverSaidaTerminalMatrix(Node** arvoreMinima, Matrix* matrix)
{
    for(int i = 0; i < matrixGetSize(matrix); i++){
        printf("SHORTEST PATH TO %s: ", matrixGetNomeVertice(matrix, i));

        if(i == matrixGetSource(matrix)){
            printf("%s <- %s (Distance: 0.00)\n", matrixGetNomeVertice(matrix, i), matrixGetNomeVertice(matrix, i));
            continue;
        }

        int leitor = i;
        while(leitor != matrixGetSource(matrix)){
            printf("%s <- ", matrixGetNomeVertice(matrix, leitor));
            leitor = nodeGetPai(arvoreMinima[leitor]);
        }
        printf("%s (Distance: %.2f)\n", matrixGetNomeVertice(matrix, leitor), nodeGetDistancia(arvoreMinima[i]));
    }
}